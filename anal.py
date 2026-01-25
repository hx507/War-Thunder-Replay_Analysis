#!/usr/bin/env python3
"""
War Thunder WRPL 文件信息提取工具
完整提取并导出replay文件中的所有可用信息
"""

import struct
import json
import subprocess
import sys
from pathlib import Path
from datetime import datetime
from typing import Dict, Optional


class WRPLParser:
    """War Thunder WRPL文件解析器"""
    
    MAGIC = b'\xe5\xac\x00\x10'
    
    def __init__(self, file_path: Path, wt_ext_cli_path: str = "wt_ext_cli"):
        self.file_path = file_path
        self.wt_ext_cli_path = wt_ext_cli_path
        self.header = {}
        self.results = {}
        
    def parse(self) -> bool:
        """解析WRPL文件"""
        try:
            with open(self.file_path, 'rb') as f:
                file_content = f.read()
            
            # 验证魔数
            magic = file_content[0:4]
            if magic != self.MAGIC:
                print(f"❌ 无效的魔数: {self.file_path.name}")
                return False
            
            # 解析头部信息
            version = struct.unpack('<I', file_content[0x04:0x08])[0]
            level = self._read_string_from_bytes(file_content[0x08:0x08+128])
            level_settings = self._read_string_from_bytes(file_content[0x08+128:0x08+128+260])
            battle_type = self._read_string_from_bytes(file_content[0x18C:0x18C+128])
            environment = self._read_string_from_bytes(file_content[0x18C+128:0x18C+128+128])
            visibility = self._read_string_from_bytes(file_content[0x18C+256:0x18C+256+32])
            rez_offset = struct.unpack('<I', file_content[0x2AC:0x2AC+4])[0]
            difficulty = file_content[0x2B0] & 0x0F
            session_type = struct.unpack('<I', file_content[0x2D4:0x2D8])[0]
            session_id = struct.unpack('<Q', file_content[0x2DF:0x2E7])[0]
            m_set_size = struct.unpack('<I', file_content[0x2EB:0x2EF])[0]
            loc_name = self._read_string_from_bytes(file_content[0x30F:0x30F+128])
            start_time = struct.unpack('<I', file_content[0x38F:0x393])[0]
            time_limit = struct.unpack('<I', file_content[0x393:0x397])[0]
            score_limit = struct.unpack('<I', file_content[0x397:0x39B])[0]
            battle_class = self._read_string_from_bytes(file_content[0x3CB:0x3CB+128])
            battle_kill_streak = self._read_string_from_bytes(file_content[0x44B:0x44B+128])
            
            self.header = {
                'file_name': self.file_path.name,
                'file_size': len(file_content),
                'version': version,
                'level': level,
                'level_settings': level_settings,
                'battle_type': battle_type,
                'environment': environment,
                'visibility': visibility,
                'difficulty': self._difficulty_name(difficulty),
                'difficulty_value': difficulty,
                'session_type': session_type,
                'session_id': hex(session_id),
                'session_id_int': session_id,
                'm_set_size': m_set_size,
                'loc_name': loc_name,
                'start_time': start_time,
                'start_time_readable': datetime.fromtimestamp(start_time).strftime('%Y-%m-%d %H:%M:%S'),
                'time_limit': time_limit,
                'score_limit': score_limit,
                'battle_class': battle_class,
                'battle_kill_streak': battle_kill_streak,
                'rez_offset': rez_offset
            }
            
            # 确定BLK数据位置
            blk_start = self._find_blk_start(file_content, rez_offset)
            if blk_start < 0:
                print(f"⚠️  无法找到BLK数据起始位置: {self.file_path.name}")
                return False
            
            # 解包BLK数据
            blk_data = file_content[blk_start:]
            self.results = self._unpack_blk(blk_data)
            
            return bool(self.results)
            
        except Exception as e:
            print(f"❌ 解析失败 {self.file_path.name}: {e}")
            return False
    
    def _find_blk_start(self, file_content: bytes, rez_offset: int) -> int:
        """查找BLK数据起始位置"""
        # 如果rezOffset有效，直接使用
        if 0 < rez_offset < len(file_content):
            return rez_offset
        
        # 搜索"status"关键字
        status_pos = file_content.find(b'status\x00', 0x400)
        if status_pos > 0:
            blk_start = max(0x400, status_pos - 100)
            return (blk_start // 4) * 4  # 4字节对齐
        
        # 使用固定偏移（头部大小）
        return 0x4CB
    
    def _unpack_blk(self, blk_data: bytes) -> dict:
        """使用wt_ext_cli解包BLK数据"""
        try:
            process = subprocess.Popen(
                [self.wt_ext_cli_path, 'unpack_raw_blk', '--stdin', '--stdout', '--format', 'Json'],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )
            
            stdout, stderr = process.communicate(input=blk_data, timeout=30)
            
            if process.returncode == 0:
                return json.loads(stdout.decode('utf-8'))
            
            return {}
            
        except FileNotFoundError:
            print(f"❌ 找不到 {self.wt_ext_cli_path}！")
            print(f"   下载地址: https://github.com/kotiq/wt-tools")
            sys.exit(1)
        except subprocess.TimeoutExpired:
            print(f"⚠️  解包超时: {self.file_path.name}")
            return {}
        except Exception as e:
            print(f"⚠️  解包错误: {e}")
            return {}
    
    def _read_string_from_bytes(self, data: bytes) -> str:
        """从字节数组读取以NULL结尾的字符串"""
        null_pos = data.find(b'\x00')
        if null_pos != -1:
            data = data[:null_pos]
        return data.decode('utf-8', errors='ignore').strip()
    
    def _difficulty_name(self, value: int) -> str:
        """难度值转换为名称"""
        difficulty_map = {0: "Arcade", 5: "Realistic", 10: "Simulator"}
        return difficulty_map.get(value, f"Unknown({value})")
    
    def export_full_data(self) -> Dict:
        """导出完整的结构化数据"""
        return {
            'header': self.header,
            'results': self.results
        }


def process_single_file(file_path: Path, wt_ext_cli_path: str, output_format: str = 'json'):
    """处理单个WRPL文件"""
    print(f"📄 处理: {file_path.name}")
    
    parser = WRPLParser(file_path, wt_ext_cli_path)
    
    if not parser.parse():
        print(f"  ❌ 解析失败\n")
        return False
    
    # 导出完整数据
    full_data = parser.export_full_data()
    
    # 生成输出文件名
    output_file = file_path.with_suffix(f'.{output_format}')
    
    try:
        with open(output_file, 'w', encoding='utf-8') as f:
            if output_format == 'json':
                json.dump(full_data, f, indent=2, ensure_ascii=False)
            elif output_format == 'txt':
                # 文本格式输出
                f.write("=" * 80 + "\n")
                f.write(f"War Thunder Replay: {file_path.name}\n")
                f.write("=" * 80 + "\n\n")
                
                f.write("[ 文件头部信息 ]\n")
                f.write("-" * 80 + "\n")
                for key, value in full_data['header'].items():
                    f.write(f"{key:25s}: {value}\n")
                
                f.write("\n\n[ 对局结果数据 ]\n")
                f.write("-" * 80 + "\n")
                f.write(json.dumps(full_data['results'], indent=2, ensure_ascii=False))
        
        print(f"  ✅ 已导出到: {output_file}\n")
        return True
        
    except Exception as e:
        print(f"  ❌ 导出失败: {e}\n")
        return False


def process_folder(folder_path: Path, wt_ext_cli_path: str, output_format: str = 'json'):
    """处理文件夹中的所有WRPL文件"""
    wrpl_files = list(folder_path.glob("*.wrpl"))
    total = len(wrpl_files)
    
    if total == 0:
        print(f"❌ 在 {folder_path} 中未找到 .wrpl 文件")
        return
    
    print(f"📂 找到 {total} 个replay文件")
    print("=" * 80 + "\n")
    
    success_count = 0
    
    for idx, wrpl_file in enumerate(wrpl_files, 1):
        print(f"[{idx}/{total}] ", end="")
        if process_single_file(wrpl_file, wt_ext_cli_path, output_format):
            success_count += 1
    
    print("=" * 80)
    print(f"✅ 完成! 成功: {success_count}/{total}")


def main():
    """主函数"""
    print("=" * 80)
    print("War Thunder WRPL 完整信息提取工具")
    print("=" * 80)
    print()
    
    # 解析命令行参数
    if len(sys.argv) < 2:
        print("用法:")
        print(f"  {sys.argv[0]} <文件或文件夹路径> [wt_ext_cli路径] [输出格式]")
        print()
        print("输出格式: json (默认) 或 txt")
        print()
        print("示例:")
        print(f"  {sys.argv[0]} ./replay.wrpl")
        print(f"  {sys.argv[0]} ./replays/ ./wt_ext_cli json")
        print(f"  {sys.argv[0]} ./replays/ ./wt_ext_cli txt")
        sys.exit(1)
    
    target_path = Path(sys.argv[1])
    
    if not target_path.exists():
        print(f"❌ 路径不存在: {target_path}")
        sys.exit(1)
    
    # wt_ext_cli路径
    wt_ext_cli_path = sys.argv[2] if len(sys.argv) > 2 else "wt_ext_cli"
    if sys.platform == "win32" and not wt_ext_cli_path.endswith('.exe'):
        wt_ext_cli_path += ".exe"
    
    # 输出格式
    output_format = sys.argv[3] if len(sys.argv) > 3 else "json"
    if output_format not in ['json', 'txt']:
        print(f"❌ 不支持的输出格式: {output_format}")
        print("   支持的格式: json, txt")
        sys.exit(1)
    
    print(f"📌 wt_ext_cli: {wt_ext_cli_path}")
    print(f"📌 输出格式: {output_format}")
    print()
    
    # 处理文件或文件夹
    if target_path.is_file():
        process_single_file(target_path, wt_ext_cli_path, output_format)
    elif target_path.is_dir():
        process_folder(target_path, wt_ext_cli_path, output_format)
    else:
        print(f"❌ 无效的路径类型: {target_path}")
        sys.exit(1)
    
    print("\n✅ 全部完成!")


if __name__ == "__main__":
    main()
