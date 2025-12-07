#!/usr/bin/env python3
"""
War Thunder WRPL Replay Extractor (Structured Version)

This script extracts comprehensive information from War Thunder replay files (.wrpl)
using a structured approach that mirrors the C++ implementation.
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
from dataclasses import dataclass, field, asdict
from typing import Dict, List, Optional, Any, Tuple, BinaryIO
import logging
from enum import IntEnum


# ============================================================================
# Enums and Constants (from constants.h)
# ============================================================================

class Difficulty(IntEnum):
    """Game difficulty levels (from constants.h)"""
    ARCADE = 0
    REALISTIC = 5
    SIMULATOR = 10


# ============================================================================
# Data Classes (from C++ structs/classes)
# ============================================================================

@dataclass
class Position:
    """Represents a map position (from position.h)"""
    x: float = -1.0
    y: float = -1.0
    color: str = "#FFFFFF"
    type: str = "unknown"
    icon: str = "unknown"
    timestamp: int = 0
    
    @property
    def is_capture_zone(self) -> bool:
        return self.type.lower() == "capture_zone"
    
    @property
    def is_respawn_base_tank(self) -> bool:
        return self.type.lower() == "respawn_base_tank"
    
    @property
    def is_player(self) -> bool:
        return self.icon.lower() == "player"
    
    @property
    def is_airfield(self) -> bool:
        return self.type.lower() == "airfield"
    
    @property
    def is_aircraft(self) -> bool:
        return self.type.lower() == "aircraft"
    
    @property
    def is_respawn_base_fighter(self) -> bool:
        return self.type.lower() == "respawn_base_fighter"
    
    @property
    def is_valid(self) -> bool:
        return 0.0 <= self.x <= 1.0 and 0.0 <= self.y <= 1.0


@dataclass
class CraftInfo:
    """Aircraft/vehicle information (from craftinfo.h)"""
    name: str = ""
    type: str = ""
    rank_unused: bool = False
    mrank: int = 0
    rank: int = 0
    
    @classmethod
    def from_json(cls, json_data: Dict[str, Any]) -> 'CraftInfo':
        return cls(
            name=json_data.get("name", ""),
            type=json_data.get("type", ""),
            rank_unused=json_data.get("rankUnused", False),
            mrank=json_data.get("mrank", 0),
            rank=json_data.get("rank", 0)
        )


@dataclass
class Player:
    """Player information (from player.h)"""
    user_id: str = ""
    username: str = ""
    squadron_id: str = ""
    squadron_tag: str = ""
    platform: str = ""
    
    @classmethod
    def from_json(cls, json_data: Dict[str, Any]) -> 'Player':
        def get_string(key: str, default: str = "") -> str:
            return json_data.get(key, default) if json_data.get(key) is not None else default
        
        def get_int_as_string(key: str, default: str = "") -> str:
            value = json_data.get(key)
            if isinstance(value, (int, float)):
                return str(int(value))
            return default
        
        user_id = get_int_as_string("id", "")
        squadron_id = get_int_as_string("clanId", "")
        
        # Convert "-1" squadron_id to empty string (like C++ code)
        if squadron_id == "-1":
            squadron_id = ""
        
        return cls(
            user_id=user_id,
            username=get_string("name", ""),
            squadron_id=squadron_id,
            squadron_tag=get_string("clanTag", ""),
            platform=get_string("platform", "")
        )


@dataclass
class PlayerReplayData:
    """Player statistics from replay (from playerreplaydata.h)"""
    user_id: str = ""
    squad: int = 0
    auto_squad: bool = False
    team: int = 0
    wait_time: float = 0.0
    kills: int = 0
    ground_kills: int = 0
    naval_kills: int = 0
    team_kills: int = 0
    ai_kills: int = 0
    ai_ground_kills: int = 0
    ai_naval_kills: int = 0
    assists: int = 0
    deaths: int = 0
    capture_zone: int = 0
    damage_zone: int = 0
    score: int = 0
    award_damage: int = 0
    missile_evades: int = 0
    lineup: List[str] = field(default_factory=list)
    
    @classmethod
    def from_json(cls, json_data: Dict[str, Any]) -> 'PlayerReplayData':
        def get_int(key: str, default: int = 0) -> int:
            value = json_data.get(key)
            if isinstance(value, (int, float)):
                return int(value)
            return default
        
        def get_bool(key: str, default: bool = False) -> bool:
            value = json_data.get(key)
            if isinstance(value, bool):
                return value
            return default
        
        def get_string(key: str, default: str = "") -> str:
            return str(json_data.get(key, default))
        
        return cls(
            user_id=get_string("userId", ""),
            squad=get_int("squadId", 0),
            auto_squad=get_bool("autoSquad", False),
            team=get_int("team", 0),
            kills=get_int("kills", 0),
            ground_kills=get_int("groundKills", 0),
            naval_kills=get_int("navalKills", 0),
            team_kills=get_int("teamKills", 0),
            ai_kills=get_int("aiKills", 0),
            ai_ground_kills=get_int("aiGroundKills", 0),
            ai_naval_kills=get_int("aiNavalKills", 0),
            assists=get_int("assists", 0),
            deaths=get_int("deaths", 0),
            capture_zone=get_int("captureZone", 0),
            damage_zone=get_int("damageZone", 0),
            score=get_int("score", 0),
            award_damage=get_int("awardDamage", 0),
            missile_evades=get_int("missileEvades", 0)
        )


# ============================================================================
# Replay Header Structure (from replay.h and 010 Editor template)
# ============================================================================

@dataclass
class ReplayHeader:
    """WRPL file header structure (matches C++ and 010 Editor template)"""
    # Magic number (0x10AC00E5 in little endian)
    magic: bytes = b'\xe5\xac\x00\x10'
    
    # Fields in order of appearance in the file
    version: int = 0
    level: str = ""               # 128 bytes
    level_settings: str = ""      # 260 bytes
    battle_type: str = ""         # 128 bytes
    environment: str = ""         # 128 bytes
    visibility: str = ""          # 32 bytes
    rez_offset: int = 0           # 4 bytes
    
    # Difficulty bitfield (1 byte)
    difficulty_raw: int = 0       # Raw byte value
    difficulty: Difficulty = Difficulty.ARCADE
    
    # Padding and session info
    session_type: int = 0         # 4 bytes
    session_id: str = ""          # 8 bytes as hex string
    session_id_int: int = 0       # 8 bytes as integer
    
    # More fields
    m_set_size: int = 0           # 4 bytes
    loc_name: str = ""            # 128 bytes
    start_time: int = 0           # 4 bytes (Unix timestamp)
    time_limit: int = 0           # 4 bytes
    score_limit: int = 0          # 4 bytes
    battle_class: str = ""        # 128 bytes
    battle_kill_streak: str = ""  # 128 bytes
    
    # Computed/derived fields
    file_size: int = 0
    file_name: str = ""
    start_time_readable: str = ""
    
    def __post_init__(self):
        if self.start_time:
            try:
                dt = datetime.fromtimestamp(self.start_time)
                self.start_time_readable = dt.strftime('%Y-%m-%d %H:%M:%S')
            except (ValueError, OSError):
                self.start_time_readable = f"Invalid timestamp: {self.start_time}"


# ============================================================================
# Replay Data (Main container class)
# ============================================================================

@dataclass
class ReplayData:
    """Complete replay data container (from replay.h)"""
    # Header information
    header: ReplayHeader
    
    # Results/BLK data
    status: str = "left"
    time_played: float = 0.0
    author_user_id: str = ""
    author: str = ""
    
    # Players data
    players: List[Tuple[Player, PlayerReplayData]] = field(default_factory=list)
    
    # Additional data (if needed)
    positions: List[Position] = field(default_factory=list)
    blk_data: Dict[str, Any] = field(default_factory=dict)


# ============================================================================
# Parser Classes
# ============================================================================

class ReplayParser:
    """Parses WRPL files following the C++ structure"""
    
    # Constants from replay.h
    MAGIC = b'\xe5\xac\x00\x10'
    
    # String field sizes (in bytes)
    STRING_SIZES = {
        'level': 128,
        'level_settings': 260,
        'battle_type': 128,
        'environment': 128,
        'visibility': 32,
        'loc_name': 128,
        'battle_class': 128,
        'battle_kill_streak': 128
    }
    
    def __init__(self, file_path: Path, wt_ext_cli_path: Path):
        self.file_path = file_path
        self.wt_ext_cli_path = wt_ext_cli_path
        self.logger = logging.getLogger(__name__)
        self._buffer = b''
        
    def parse(self) -> Optional[ReplayData]:
        """Parse the WRPL file and return ReplayData"""
        try:
            # Read file content
            self._read_file()
            
            # Parse header
            header = self._parse_header()
            
            # Parse BLK data (results section)
            blk_data = self._parse_blk_data(header.rez_offset)
            
            # Create replay data
            replay_data = self._create_replay_data(header, blk_data)
            
            return replay_data
            
        except Exception as e:
            self.logger.error(f"Failed to parse {self.file_path.name}: {e}")
            self.logger.debug(f"Traceback:\n{traceback.format_exc()}")
            return None
    
    def _read_file(self) -> None:
        """Read entire file into buffer"""
        with open(self.file_path, 'rb') as f:
            self._buffer = f.read()
    
    def _parse_header(self) -> ReplayHeader:
        """Parse the structured header from binary content"""
        buffer = self._buffer
        offset = 0
        
        # Check magic
        magic = buffer[offset:offset+4]
        if magic != self.MAGIC:
            raise ValueError(f"Invalid magic number: {magic.hex()}")
        offset += 4
        
        # Parse fixed-size fields
        version = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        # Parse string fields
        level = self._read_string(buffer, offset, self.STRING_SIZES['level'])
        offset += self.STRING_SIZES['level']
        
        level_settings = self._read_string(buffer, offset, self.STRING_SIZES['level_settings'])
        offset += self.STRING_SIZES['level_settings']
        
        battle_type = self._read_string(buffer, offset, self.STRING_SIZES['battle_type'])
        offset += self.STRING_SIZES['battle_type']
        
        environment = self._read_string(buffer, offset, self.STRING_SIZES['environment'])
        offset += self.STRING_SIZES['environment']
        
        visibility = self._read_string(buffer, offset, self.STRING_SIZES['visibility'])
        offset += self.STRING_SIZES['visibility']
        
        # Parse rez_offset
        rez_offset = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        # Parse difficulty (bitfield)
        difficulty_raw = buffer[offset]
        difficulty_value = difficulty_raw & 0x0F
        difficulty = self._parse_difficulty(difficulty_value)
        offset += 1
        
        # Skip padding (35 bytes as per C++ code)
        offset += 35
        
        # Parse session type
        session_type = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        # Skip padding (7 bytes as per C++ code)
        offset += 7
        
        # Parse session ID
        session_id_int = struct.unpack_from('<Q', buffer, offset)[0]
        session_id = hex(session_id_int)
        offset += 8
        
        # Skip padding (4 bytes as per C++ code)
        offset += 4
        
        # Parse m_set_size
        m_set_size = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        # Skip padding (32 bytes as per C++ code)
        offset += 32
        
        # Parse loc_name
        loc_name = self._read_string(buffer, offset, self.STRING_SIZES['loc_name'])
        offset += self.STRING_SIZES['loc_name']
        
        # Parse timestamps and limits
        start_time = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        time_limit = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        score_limit = struct.unpack_from('<I', buffer, offset)[0]
        offset += 4
        
        # Skip padding (48 bytes as per C++ code)
        offset += 48
        
        # Parse final string fields
        battle_class = self._read_string(buffer, offset, self.STRING_SIZES['battle_class'])
        offset += self.STRING_SIZES['battle_class']
        
        battle_kill_streak = self._read_string(buffer, offset, self.STRING_SIZES['battle_kill_streak'])
        offset += self.STRING_SIZES['battle_kill_streak']
        
        # Clean up level string (remove paths and extensions like C++ code)
        level = level.replace("levels/", "").replace(".bin", "")
        
        # Create header object
        return ReplayHeader(
            magic=magic,
            version=version,
            level=level,
            level_settings=level_settings,
            battle_type=battle_type,
            environment=environment,
            visibility=visibility,
            rez_offset=rez_offset,
            difficulty_raw=difficulty_raw,
            difficulty=difficulty,
            session_type=session_type,
            session_id=session_id,
            session_id_int=session_id_int,
            m_set_size=m_set_size,
            loc_name=loc_name,
            start_time=start_time,
            time_limit=time_limit,
            score_limit=score_limit,
            battle_class=battle_class,
            battle_kill_streak=battle_kill_streak,
            file_size=len(self._buffer),
            file_name=self.file_path.name
        )
    
    def _parse_blk_data(self, rez_offset: int) -> Dict[str, Any]:
        """Parse BLK data using wt_ext_cli tool"""
        if rez_offset <= 0 or rez_offset >= len(self._buffer):
            self.logger.warning(f"Invalid rez_offset: {rez_offset}")
            return {}
        
        # Extract BLK data from buffer
        blk_data = self._buffer[rez_offset:]
        
        if not self.wt_ext_cli_path.exists():
            raise FileNotFoundError(
                f"wt_ext_cli not found at {self.wt_ext_cli_path}\n"
                f"Download from: https://github.com/Warthunder-Open-Source-Foundation/wt_ext_cli"
            )
        
        try:
            # Prepare command (similar to C++ code)
            cmd = [
                str(self.wt_ext_cli_path),
                '--unpack_raw_blk',
                '--stdout',
                '--stdin',
                '--format', 'Json'
            ]
            
            self.logger.debug(f"Running command: {' '.join(cmd)}")
            
            process = subprocess.Popen(
                cmd,
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=False
            )
            
            stdout, stderr = process.communicate(input=blk_data, timeout=30)
            
            if process.returncode != 0:
                self.logger.warning(f"wt_ext_cli returned exit code {process.returncode}")
                if stderr:
                    stderr_text = stderr.decode('utf-8', errors='ignore')
                    self.logger.debug(f"stderr: {stderr_text}")
                return {}
            
            # Parse JSON output
            json_data = json.loads(stdout.decode('utf-8'))
            return json_data
            
        except subprocess.TimeoutExpired:
            self.logger.warning("BLK parsing timed out")
            return {}
        except json.JSONDecodeError as e:
            self.logger.warning(f"Failed to parse JSON: {e}")
            return {}
    
    def _create_replay_data(self, header: ReplayHeader, blk_data: Dict[str, Any]) -> ReplayData:
        """Create ReplayData from header and BLK data (like C++ parseResults)"""
        # Extract basic info from BLK data
        status = blk_data.get("status", "left")
        time_played = blk_data.get("timePlayed", 0.0)
        author_user_id = blk_data.get("authorUserId", "")
        author = blk_data.get("author", "")
        
        # Handle missing author info (like C++ code)
        if not author_user_id or not author:
            author_user_id = "-1"
            author = "server"
        
        # Parse players data
        players = []
        players_array = blk_data.get("player", [])
        ui_scripts_data = blk_data.get("uiScriptsData", {})
        players_info_object = ui_scripts_data.get("playersInfo", {})
        
        # Convert players_info_object to list for easier iteration
        players_info_list = players_info_object.values() if isinstance(players_info_object, dict) else []
        
        for player_obj in players_array:
            player_user_id = str(player_obj.get("userId", ""))
            
            # Find matching player info
            player_info = None
            for info in players_info_list:
                if str(info.get("id", "")) == player_user_id:
                    player_info = info
                    break
            
            if player_info:
                # Create Player object
                player = Player.from_json(player_info)
                
                # Create PlayerReplayData object
                player_replay_data = PlayerReplayData.from_json(player_obj)
                
                # Set additional fields (like C++ code)
                player_replay_data.wait_time = player_info.get("wait_time", 0.0)
                
                # Parse crafts/lineup
                crafts = player_info.get("crafts", {})
                lineup = []
                for craft_key in crafts:
                    craft_value = crafts[craft_key]
                    if isinstance(craft_value, str):
                        lineup.append(craft_value)
                    elif isinstance(craft_value, dict) and "name" in craft_value:
                        lineup.append(craft_value["name"])
                
                player_replay_data.lineup = lineup
                
                # Add to players list
                players.append((player, player_replay_data))
        
        # Create ReplayData object
        return ReplayData(
            header=header,
            status=status,
            time_played=time_played,
            author_user_id=author_user_id,
            author=author,
            players=players,
            blk_data=blk_data
        )
    
    @staticmethod
    def _read_string(buffer: bytes, offset: int, length: int) -> str:
        """Read a null-terminated string from buffer (like C++ readString)"""
        if offset + length > len(buffer):
            return ""
        
        data = buffer[offset:offset+length]
        null_index = data.find(b'\x00')
        if null_index != -1:
            data = data[:null_index]
        
        try:
            return data.decode('utf-8')
        except UnicodeDecodeError:
            # Try other encodings if UTF-8 fails
            try:
                return data.decode('latin-1')
            except UnicodeDecodeError:
                return data.decode('utf-8', errors='ignore')
    
    @staticmethod
    def _parse_difficulty(value: int) -> Difficulty:
        """Parse difficulty value (bitfield handling like C++)"""
        # Map difficulty values (from constants.h)
        difficulty_map = {
            0: Difficulty.ARCADE,
            5: Difficulty.REALISTIC,
            10: Difficulty.SIMULATOR
        }
        
        # Try to find exact match first
        if value in difficulty_map:
            return difficulty_map[value]
        
        # Fallback: find closest match
        for diff_value, diff_enum in difficulty_map.items():
            if value == diff_value:
                return diff_enum
        
        # Default to ARCADE if unknown
        return Difficulty.ARCADE


# ============================================================================
# Utility Functions (from utils.h)
# ============================================================================

class Utils:
    """Utility functions similar to utils.h"""
    
    @staticmethod
    def difficulty_to_string(difficulty: Difficulty) -> str:
        """Convert Difficulty enum to string (like difficultyToString)"""
        mapping = {
            Difficulty.ARCADE: "ARCADE",
            Difficulty.REALISTIC: "REALISTIC",
            Difficulty.SIMULATOR: "SIMULATOR"
        }
        return mapping.get(difficulty, "UNKNOWN")
    
    @staticmethod
    def replay_length_to_string(seconds: int) -> str:
        """Format replay length as HH:MM:SS (like replayLengthToString)"""
        hours = seconds // 3600
        minutes = (seconds % 3600) // 60
        seconds = seconds % 60
        return f"{hours:02d}:{minutes:02d}:{seconds:02d}"
    
    @staticmethod
    def epoch_to_formatted_time(timestamp: int) -> str:
        """Format Unix timestamp to time string (like epochSToFormattedTime)"""
        dt = datetime.fromtimestamp(timestamp)
        return dt.strftime("%H:%M:%S")


# ============================================================================
# Export Functions
# ============================================================================

class ReplayExporter:
    """Handles exporting replay data in various formats"""
    
    def __init__(self, output_format: str = 'json'):
        self.output_format = output_format
        self.logger = logging.getLogger(__name__)
    
    def export(self, replay_data: ReplayData, output_file: Path) -> bool:
        """Export replay data to file"""
        try:
            if self.output_format == 'json':
                return self._export_json(replay_data, output_file)
            elif self.output_format == 'txt':
                return self._export_text(replay_data, output_file)
            elif self.output_format == 'debug':
                return self._export_debug(replay_data, output_file)
            else:
                raise ValueError(f"Unsupported format: {self.output_format}")
        except Exception as e:
            self.logger.error(f"Export failed: {e}")
            return False
    
    def _export_json(self, replay_data: ReplayData, output_file: Path) -> bool:
        """Export as JSON"""
        # Convert to dict
        data_dict = {
            'header': asdict(replay_data.header),
            'status': replay_data.status,
            'time_played': replay_data.time_played,
            'author_user_id': replay_data.author_user_id,
            'author': replay_data.author,
            'players': self._players_to_dict(replay_data.players),
            'blk_data': replay_data.blk_data
        }
        
        with open(output_file, 'w', encoding='utf-8') as f:
            json.dump(data_dict, f, indent=2, ensure_ascii=False, default=str)
        
        return True
    
    def _export_text(self, replay_data: ReplayData, output_file: Path) -> bool:
        """Export as human-readable text"""
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write("=" * 80 + "\n")
            f.write(f"War Thunder Replay Analysis\n")
            f.write("=" * 80 + "\n\n")
            
            # Header info
            f.write("[ HEADER INFORMATION ]\n")
            f.write("-" * 80 + "\n")
            header = replay_data.header
            f.write(f"File: {header.file_name} ({header.file_size:,} bytes)\n")
            f.write(f"Version: {header.version}\n")
            f.write(f"Map: {header.level}\n")
            f.write(f"Battle Type: {header.battle_type}\n")
            f.write(f"Difficulty: {Utils.difficulty_to_string(header.difficulty)} ({header.difficulty_raw})\n")
            f.write(f"Session ID: {header.session_id}\n")
            f.write(f"Start Time: {header.start_time_readable} ({header.start_time})\n")
            f.write(f"Time Limit: {Utils.replay_length_to_string(header.time_limit)}\n")
            f.write(f"Score Limit: {header.score_limit}\n")
            f.write(f"Location: {header.loc_name}\n")
            f.write(f"Battle Class: {header.battle_class}\n")
            
            # Replay info
            f.write(f"\n[ REPLAY INFORMATION ]\n")
            f.write("-" * 80 + "\n")
            f.write(f"Status: {replay_data.status}\n")
            f.write(f"Time Played: {replay_data.time_played:.1f}s\n")
            f.write(f"Author: {replay_data.author} (ID: {replay_data.author_user_id})\n")
            
            # Players
            f.write(f"\n[ PLAYERS ({len(replay_data.players)}) ]\n")
            f.write("-" * 80 + "\n")
            
            for idx, (player, player_data) in enumerate(replay_data.players, 1):
                f.write(f"\nPlayer {idx}: {player.username} (ID: {player.user_id})\n")
                f.write(f"  Squadron: {player.squadron_tag} (ID: {player.squadron_id})\n")
                f.write(f"  Platform: {player.platform}\n")
                f.write(f"  Team: {player_data.team}, Squad: {player_data.squad}\n")
                f.write(f"  Kills: {player_data.kills} (Air: {player_data.kills}, Ground: {player_data.ground_kills}, Naval: {player_data.naval_kills})\n")
                f.write(f"  AI Kills: Air={player_data.ai_kills}, Ground={player_data.ai_ground_kills}, Naval={player_data.ai_naval_kills}\n")
                f.write(f"  Deaths: {player_data.deaths}, Assists: {player_data.assists}, Team Kills: {player_data.team_kills}\n")
                f.write(f"  Score: {player_data.score}, Capture Zones: {player_data.capture_zone}\n")
                f.write(f"  Lineup: {', '.join(player_data.lineup[:3])}" + 
                       (f" (+{len(player_data.lineup)-3} more)" if len(player_data.lineup) > 3 else "") + "\n")
        
        return True
    
    def _export_debug(self, replay_data: ReplayData, output_file: Path) -> bool:
        """Export debug information including raw BLK data"""
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write("=" * 80 + "\n")
            f.write("WRPL File Debug Information\n")
            f.write("=" * 80 + "\n\n")
            
            # Full header dump
            f.write("[ FULL HEADER DUMP ]\n")
            f.write("-" * 80 + "\n")
            f.write(json.dumps(asdict(replay_data.header), indent=2, default=str))
            
            # BLK data structure
            f.write("\n\n[ BLK DATA STRUCTURE ]\n")
            f.write("-" * 80 + "\n")
            self._write_json_structure(replay_data.blk_data, f, depth=0)
    
    def _players_to_dict(self, players: List[Tuple[Player, PlayerReplayData]]) -> List[Dict]:
        """Convert players list to serializable dict"""
        result = []
        for player, player_data in players:
            result.append({
                'player': asdict(player),
                'player_data': asdict(player_data)
            })
        return result
    
    def _write_json_structure(self, data: Any, f, depth: int = 0, max_depth: int = 3):
        """Write JSON structure with limited depth"""
        indent = "  " * depth
        
        if depth >= max_depth:
            f.write(f"{indent}... (truncated at depth {max_depth})\n")
            return
        
        if isinstance(data, dict):
            for key, value in data.items():
                if isinstance(value, (dict, list)):
                    f.write(f"{indent}{key}: {type(value).__name__}\n")
                    self._write_json_structure(value, f, depth + 1, max_depth)
                else:
                    f.write(f"{indent}{key}: {type(value).__name__} = {repr(value)[:100]}\n")
        elif isinstance(data, list):
            f.write(f"{indent}List[{len(data)} items]:\n")
            for i, item in enumerate(data[:5]):  # Limit to 5 items
                f.write(f"{indent}[{i}]: {type(item).__name__}\n")
                self._write_json_structure(item, f, depth + 1, max_depth)
            if len(data) > 5:
                f.write(f"{indent}... (+{len(data) - 5} more items)\n")
        else:
            f.write(f"{indent}{type(data).__name__}: {repr(data)[:200]}\n")


# ============================================================================
# Main Processing
# ============================================================================

def setup_logging(verbose: bool = False) -> None:
    """Configure logging"""
    level = logging.DEBUG if verbose else logging.INFO
    
    # Basic configuration
    logging.basicConfig(
        level=level,
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
        datefmt='%H:%M:%S'
    )


def process_single_file(file_path: Path, wt_ext_cli_path: Path, 
                       output_format: str) -> bool:
    """Process a single WRPL file"""
    logger = logging.getLogger(__name__)
    
    logger.info(f"Processing: {file_path.name}")
    
    # Parse file
    parser = ReplayParser(file_path, wt_ext_cli_path)
    replay_data = parser.parse()
    
    if not replay_data:
        logger.error(f"Failed to parse {file_path.name}")
        return False
    
    # Export results
    exporter = ReplayExporter(output_format)
    output_file = file_path.with_suffix(f'.{output_format}')
    
    if exporter.export(replay_data, output_file):
        logger.info(f"Successfully exported to: {output_file}")
        return True
    else:
        logger.error(f"Failed to export {file_path.name}")
        return False


def process_directory(directory_path: Path, wt_ext_cli_path: Path,
                     output_format: str) -> None:
    """Process all WRPL files in a directory"""
    logger = logging.getLogger(__name__)
    
    wrpl_files = list(directory_path.glob("*.wrpl"))
    
    if not wrpl_files:
        logger.warning(f"No .wrpl files found in {directory_path}")
        return
    
    logger.info(f"Found {len(wrpl_files)} replay files in {directory_path}")
    
    success_count = 0
    for idx, wrpl_file in enumerate(wrpl_files, 1):
        logger.info(f"[{idx}/{len(wrpl_files)}] Processing {wrpl_file.name}")
        
        if process_single_file(wrpl_file, wt_ext_cli_path, output_format):
            success_count += 1
    
    logger.info(f"Processing complete. Successful: {success_count}/{len(wrpl_files)}")


def main() -> None:
    """Main entry point"""
    parser = argparse.ArgumentParser(
        description="Extract structured information from War Thunder replay files (.wrpl)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s replay.wrpl
  %(prog)s replays/ --wt_ext_cli ./wt_ext_cli --format txt
  %(prog)s replays/ --verbose --format debug

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
        choices=['json', 'txt', 'debug'],
        default='json',
        help='Output format (default: json)'
    )
    
    parser.add_argument(
        '--verbose', '-v',
        action='store_true',
        help='Enable verbose output with debug information'
    )
    
    args = parser.parse_args()
    setup_logging(args.verbose)
    
    # Validate inputs
    if not args.path.exists():
        logging.error(f"Path does not exist: {args.path}")
        sys.exit(1)
    
    wt_ext_cli_path = args.wt_ext_cli.resolve()
    if not wt_ext_cli_path.exists():
        logging.error(f"wt_ext_cli not found at {wt_ext_cli_path}")
        sys.exit(1)
    
    # Process files
    try:
        if args.path.is_file():
            if args.path.suffix.lower() != '.wrpl':
                logging.error(f"File must have .wrpl extension: {args.path}")
                sys.exit(1)
            success = process_single_file(args.path, wt_ext_cli_path, args.format)
            sys.exit(0 if success else 1)
        else:
            process_directory(args.path, wt_ext_cli_path, args.format)
            
    except KeyboardInterrupt:
        logging.info("Processing interrupted by user")
        sys.exit(130)
    except Exception as e:
        logging.error(f"Fatal error: {e}")
        logging.debug(f"Traceback:\n{traceback.format_exc()}")
        sys.exit(1)


if __name__ == "__main__":
    main()
