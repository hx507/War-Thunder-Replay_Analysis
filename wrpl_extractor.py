#!/usr/bin/env python3
"""
War Thunder WRPL Replay Extractor

This script extracts comprehensive information from War Thunder replay files (.wrpl)
using the wt_ext_cli tool from the Warthunder-Open-Source-Foundation.
"""

import argparse
import json
import struct
import subprocess
import sys
import traceback
import os
from pathlib import Path
from datetime import datetime
from typing import Dict, Optional, List, Any
from dataclasses import dataclass, field
import logging


@dataclass
class WRPLHeader:
    """Structured representation of WRPL file header data."""
    file_name: str = ""
    file_size: int = 0
    version: int = 0
    level: str = ""
    level_settings: str = ""
    battle_type: str = ""
    environment: str = ""
    visibility: str = ""
    difficulty: str = ""
    difficulty_value: int = 0
    session_type: int = 0
    session_id: str = ""
    session_id_int: int = 0
    m_set_size: int = 0
    loc_name: str = ""
    start_time: int = 0
    start_time_readable: str = ""
    time_limit: int = 0
    score_limit: int = 0
    battle_class: str = ""
    battle_kill_streak: str = ""
    rez_offset: int = 0
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert header to dictionary for serialization."""
        return {k: v for k, v in self.__dict__.items() if not k.startswith('_')}


class WRPLParser:
    """Parser for War Thunder WRPL replay files."""
    
    MAGIC = b'\xe5\xac\x00\x10'
    DIFFICULTY_MAP = {0: "Arcade", 5: "Realistic", 10: "Simulator"}
    
    def __init__(self, file_path: Path, wt_ext_cli_path: str = "wt_ext_cli"):
        self.file_path = file_path
        self.wt_ext_cli_path = Path(wt_ext_cli_path)
        self.header = WRPLHeader()
        self.blk_data: Dict[str, Any] = {}
        self.logger = logging.getLogger(__name__)
        
    def parse(self) -> bool:
        """
        Parse the WRPL file.
        
        Returns:
            bool: True if parsing was successful, False otherwise.
        """
        try:
            file_content = self._read_file_content()
            if not self._validate_magic(file_content):
                return False
            
            self._parse_header(file_content)
            self._parse_blk_data(file_content)
            return True
            
        except Exception as e:
            self.logger.error(f"Failed to parse {self.file_path.name}: {e}")
            self.logger.debug(f"Full traceback:\n{traceback.format_exc()}")
            return False
    
    def _read_file_content(self) -> bytes:
        """Read and return the entire file content."""
        with open(self.file_path, 'rb') as f:
            return f.read()
    
    def _validate_magic(self, content: bytes) -> bool:
        """Validate the file magic bytes."""
        magic = content[0:4]
        if magic != self.MAGIC:
            self.logger.error(f"Invalid magic bytes in {self.file_path.name}")
            return False
        return True
    
    def _parse_header(self, content: bytes) -> None:
        """Parse the structured header from binary content."""
        self.header.file_name = self.file_path.name
        self.header.file_size = len(content)
        
        # Parse individual header fields
        self.header.version = struct.unpack('<I', content[0x04:0x08])[0]
        self.header.level = self._read_null_terminated_string(content[0x08:0x08+128])
        self.header.level_settings = self._read_null_terminated_string(content[0x08+128:0x08+128+260])
        self.header.battle_type = self._read_null_terminated_string(content[0x18C:0x18C+128])
        self.header.environment = self._read_null_terminated_string(content[0x18C+128:0x18C+128+128])
        self.header.visibility = self._read_null_terminated_string(content[0x18C+256:0x18C+256+32])
        
        self.header.rez_offset = struct.unpack('<I', content[0x2AC:0x2AC+4])[0]
        difficulty_value = content[0x2B0] & 0x0F
        self.header.difficulty_value = difficulty_value
        self.header.difficulty = self.DIFFICULTY_MAP.get(difficulty_value, f"Unknown({difficulty_value})")
        
        self.header.session_type = struct.unpack('<I', content[0x2D4:0x2D8])[0]
        session_id_int = struct.unpack('<Q', content[0x2DF:0x2E7])[0]
        self.header.session_id_int = session_id_int
        self.header.session_id = hex(session_id_int)
        
        self.header.m_set_size = struct.unpack('<I', content[0x2EB:0x2EF])[0]
        self.header.loc_name = self._read_null_terminated_string(content[0x30F:0x30F+128])
        
        start_time = struct.unpack('<I', content[0x38F:0x393])[0]
        self.header.start_time = start_time
        self.header.start_time_readable = datetime.fromtimestamp(start_time).strftime('%Y-%m-%d %H:%M:%S')
        
        self.header.time_limit = struct.unpack('<I', content[0x393:0x397])[0]
        self.header.score_limit = struct.unpack('<I', content[0x397:0x39B])[0]
        self.header.battle_class = self._read_null_terminated_string(content[0x3CB:0x3CB+128])
        self.header.battle_kill_streak = self._read_null_terminated_string(content[0x44B:0x44B+128])
    
    def _parse_blk_data(self, content: bytes) -> None:
        """Parse BLK data using wt_ext_cli."""
        blk_start = self._find_blk_start(content)
        if blk_start < 0:
            self.logger.warning(f"Could not find BLK data start in {self.file_path.name}")
            return
        
        blk_data = content[blk_start:]
        self.blk_data = self._unpack_blk_with_tool(blk_data)
    
    def _find_blk_start(self, content: bytes) -> int:
        """Find the starting position of BLK data."""
        # Use rez_offset if valid
        if 0 < self.header.rez_offset < len(content):
            return self.header.rez_offset
        
        # Search for 'status' keyword
        status_pos = content.find(b'status\x00', 0x400)
        if status_pos > 0:
            blk_start = max(0x400, status_pos - 100)
            return (blk_start // 4) * 4  # Align to 4-byte boundary
        
        # Use default offset (header size)
        return 0x4CB
    
    def _unpack_blk_with_tool(self, blk_data: bytes) -> Dict[str, Any]:
        """
        Unpack BLK data using the wt_ext_cli binary.
        
        Returns:
            Dict containing parsed BLK data, or empty dict on failure.
        """
        # Resolve the path to absolute to avoid issues with working directory
        wt_ext_cli_path = self.wt_ext_cli_path
        
        # If path is relative, resolve it relative to the current working directory
        if not wt_ext_cli_path.is_absolute():
            wt_ext_cli_path = wt_ext_cli_path.resolve()
        
        if not wt_ext_cli_path.exists():
            raise FileNotFoundError(
                f"wt_ext_cli not found at {wt_ext_cli_path}. "
                f"Download from: https://github.com/Warthunder-Open-Source-Foundation/wt_ext_cli"
            )
        
        if not wt_ext_cli_path.is_file():
            raise FileNotFoundError(f"wt_ext_cli path is not a file: {wt_ext_cli_path}")
        
        try:
            cli_path = str(wt_ext_cli_path)
            self.logger.debug(f"Using wt_ext_cli at: {cli_path}")
            
            process = subprocess.Popen(
                [cli_path, 'unpack_raw_blk', '--stdin', '--stdout', '--format', 'Json'],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=False
            )
            
            stdout, stderr = process.communicate(input=blk_data, timeout=30)
            
            if process.returncode != 0:
                self.logger.warning(f"wt_ext_cli returned non-zero exit code: {process.returncode}")
                if stderr:
                    stderr_text = stderr.decode('utf-8', errors='ignore').strip()
                    if stderr_text:
                        self.logger.debug(f"stderr: {stderr_text}")
                return {}
            
            return json.loads(stdout.decode('utf-8'))
            
        except subprocess.TimeoutExpired:
            self.logger.warning(f"BLK unpacking timed out for {self.file_path.name}")
            return {}
        except json.JSONDecodeError as e:
            self.logger.warning(f"Failed to parse JSON output from wt_ext_cli: {e}")
            self.logger.debug(f"JSON decode error. stderr: {stderr.decode('utf-8', errors='ignore') if stderr else 'No stderr'}")
            return {}
        except Exception as e:
            self.logger.warning(f"Unexpected error during BLK unpacking: {e}")
            self.logger.debug(f"BLK unpacking traceback:\n{traceback.format_exc()}")
            return {}
    
    @staticmethod
    def _read_null_terminated_string(data: bytes) -> str:
        """Extract null-terminated string from bytes."""
        null_pos = data.find(b'\x00')
        if null_pos != -1:
            data = data[:null_pos]
        return data.decode('utf-8', errors='ignore').strip()
    
    def export_data(self) -> Dict[str, Any]:
        """Export complete parsed data as a dictionary."""
        return {
            'header': self.header.to_dict(),
            'blk_data': self.blk_data
        }


class ReplayProcessor:
    """Handles processing of replay files and directories."""
    
    def __init__(self, wt_ext_cli_path: str, output_format: str = 'json'):
        self.wt_ext_cli_path = Path(wt_ext_cli_path)
        self.output_format = output_format
        self.logger = logging.getLogger(__name__)
        
    def process_file(self, file_path: Path) -> bool:
        """
        Process a single WRPL file.
        
        Returns:
            bool: True if processing was successful, False otherwise.
        """
        self.logger.info(f"Processing: {file_path.name}")
        
        try:
            parser = WRPLParser(file_path, str(self.wt_ext_cli_path))
            
            if not parser.parse():
                self.logger.error(f"Failed to parse {file_path.name}")
                return False
            
            return self._export_data(parser, file_path)
            
        except Exception as e:
            self.logger.error(f"Unexpected error processing {file_path.name}: {e}")
            self.logger.debug(f"Full traceback:\n{traceback.format_exc()}")
            return False
    
    def process_directory(self, directory_path: Path) -> None:
        """Process all WRPL files in a directory."""
        wrpl_files = list(directory_path.glob("*.wrpl"))
        
        if not wrpl_files:
            self.logger.warning(f"No .wrpl files found in {directory_path}")
            return
        
        self.logger.info(f"Found {len(wrpl_files)} replay files in {directory_path}")
        
        success_count = 0
        for idx, wrpl_file in enumerate(wrpl_files, 1):
            self.logger.info(f"[{idx}/{len(wrpl_files)}] Processing {wrpl_file.name}")
            if self.process_file(wrpl_file):
                success_count += 1
        
        self.logger.info(f"Processing complete. Successful: {success_count}/{len(wrpl_files)}")
    
    def _export_data(self, parser: WRPLParser, file_path: Path) -> bool:
        """Export parsed data to file."""
        data = parser.export_data()
        output_file = file_path.with_suffix(f'.{self.output_format}')
        
        try:
            if self.output_format == 'json':
                with open(output_file, 'w', encoding='utf-8') as f:
                    json.dump(data, f, indent=2, ensure_ascii=False, default=str)
            elif self.output_format == 'txt':
                self._export_text(data, output_file)
            else:
                raise ValueError(f"Unsupported output format: {self.output_format}")
            
            self.logger.info(f"Exported to: {output_file}")
            return True
            
        except Exception as e:
            self.logger.error(f"Failed to export {file_path.name}: {e}")
            self.logger.debug(f"Export traceback:\n{traceback.format_exc()}")
            return False
    
    @staticmethod
    def _export_text(data: Dict[str, Any], output_file: Path) -> None:
        """Export data in human-readable text format."""
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write("=" * 80 + "\n")
            f.write(f"War Thunder Replay: {data['header'].get('file_name', 'Unknown')}\n")
            f.write("=" * 80 + "\n\n")
            
            f.write("[ HEADER INFORMATION ]\n")
            f.write("-" * 80 + "\n")
            for key, value in data['header'].items():
                f.write(f"{key:25s}: {value}\n")
            
            f.write("\n\n[ BATTLE DATA (BLK) ]\n")
            f.write("-" * 80 + "\n")
            if data['blk_data']:
                f.write(json.dumps(data['blk_data'], indent=2, ensure_ascii=False, default=str))
            else:
                f.write("(No BLK data available)")


def setup_logging(verbose: bool = False) -> None:
    """Configure logging based on verbosity level."""
    level = logging.DEBUG if verbose else logging.INFO
    
    # Configure root logger
    root_logger = logging.getLogger()
    root_logger.setLevel(level)
    
    # Remove existing handlers to avoid duplicates
    for handler in root_logger.handlers[:]:
        root_logger.removeHandler(handler)
    
    # Create console handler
    console_handler = logging.StreamHandler()
    console_handler.setLevel(level)
    
    # Create formatter
    formatter = logging.Formatter(
        '%(asctime)s - %(name)s - %(levelname)s - %(message)s',
        datefmt='%H:%M:%S'
    )
    console_handler.setFormatter(formatter)
    
    # Add handler to root logger
    root_logger.addHandler(console_handler)


def main() -> None:
    """Main entry point for the script."""
    parser = argparse.ArgumentParser(
        description="Extract comprehensive information from War Thunder replay files (.wrpl)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s replay.wrpl
  %(prog)s replays/ --wt_ext_cli ./wt_ext_cli --format txt
  %(prog)s replays/ --verbose

The wt_ext_cli tool is required and can be downloaded from:
https://github.com/Warthunder-Open-Source-Foundation/wt_ext_cli
        """
    )
    
    parser.add_argument(
        'path',
        type=Path,
        help='Path to a .wrpl file or directory containing .wrpl files'
    )
    
    parser.add_argument(
        '--wt_ext_cli',
        type=Path,
        default='./wt_ext_cli',
        help='Path to wt_ext_cli binary (default: ./wt_ext_cli)'
    )
    
    parser.add_argument(
        '--format',
        choices=['json', 'txt'],
        default='json',
        help='Output format (default: json)'
    )
    
    parser.add_argument(
        '--verbose', '-v',
        action='store_true',
        help='Enable verbose output with debug information and full tracebacks'
    )
    
    args = parser.parse_args()
    setup_logging(args.verbose)
    logger = logging.getLogger(__name__)
    
    # Validate input path
    if not args.path.exists():
        logger.error(f"Path does not exist: {args.path}")
        sys.exit(1)
    
    # Resolve wt_ext_cli path to absolute
    wt_ext_cli_path = args.wt_ext_cli
    if not wt_ext_cli_path.is_absolute():
        wt_ext_cli_path = wt_ext_cli_path.resolve()
    
    logger.debug(f"Resolved wt_ext_cli path: {wt_ext_cli_path}")
    
    # Validate wt_ext_cli binary exists
    if not wt_ext_cli_path.exists():
        logger.error(
            f"wt_ext_cli not found at {wt_ext_cli_path}\n"
            f"Download from: https://github.com/Warthunder-Open-Source-Foundation/wt_ext_cli"
        )
        sys.exit(1)
    
    if not wt_ext_cli_path.is_file():
        logger.error(f"wt_ext_cli path is not a file: {wt_ext_cli_path}")
        sys.exit(1)
    
    # Check if wt_ext_cli is executable (Unix-like systems only)
    if hasattr(os, 'access') and hasattr(os, 'X_OK'):
        if not os.access(wt_ext_cli_path, os.X_OK):
            logger.warning(f"wt_ext_cli may not be executable: {wt_ext_cli_path}")
            logger.info(f"Try: chmod +x {wt_ext_cli_path}")
    
    # Create processor and execute
    try:
        processor = ReplayProcessor(str(wt_ext_cli_path), args.format)
        
        if args.path.is_file():
            if args.path.suffix.lower() != '.wrpl':
                logger.error(f"File must have .wrpl extension: {args.path}")
                sys.exit(1)
            success = processor.process_file(args.path)
            sys.exit(0 if success else 1)
        elif args.path.is_dir():
            processor.process_directory(args.path)
        else:
            logger.error(f"Invalid path type: {args.path}")
            sys.exit(1)
            
    except KeyboardInterrupt:
        logger.info("Processing interrupted by user")
        sys.exit(130)
    except Exception as e:
        logger.error(f"Fatal error: {e}")
        logger.debug(f"Full traceback:\n{traceback.format_exc()}")
        sys.exit(1)


if __name__ == "__main__":
    main()
