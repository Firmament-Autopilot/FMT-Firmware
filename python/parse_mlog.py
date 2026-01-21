#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import sys
import csv
import struct
from pathlib import Path
from typing import Dict, List, Tuple, Optional


# --------- Constants mirrored from mlog.h (fallbacks). We will try to read actual values from mlog.h. ---------
MLOG_BEGIN_MSG1 = 0x92
MLOG_BEGIN_MSG2 = 0x05
MLOG_END_MSG = 0x26

# Default values in case header parsing of mlog.h fails; will be overridden by header
MLOG_MAX_NAME_LEN_DEFAULT = 25

# Feature flags default to 1, will try to auto-detect from header file
MLOG_ENABLE_DESCRIPTION = 1
MLOG_ENABLE_MODEL_INFO = 1
MLOG_ENABLE_PARAM = 1


TypeSizeLE: Dict[int, Tuple[str, int]] = {
    # enum in mlog.h
    0: ("b", 1),   # MLOG_INT8
    1: ("B", 1),   # MLOG_UINT8
    2: ("h", 2),   # MLOG_INT16
    3: ("H", 2),   # MLOG_UINT16
    4: ("i", 4),   # MLOG_INT32
    5: ("I", 4),   # MLOG_UINT32
    6: ("f", 4),   # MLOG_FLOAT
    7: ("d", 8),   # MLOG_DOUBLE
    8: ("B", 1),   # MLOG_BOOLEAN (store as 0/1)
}

# Human readable type names corresponding to enum in mlog.h
TypeName: Dict[int, str] = {
    0: "INT8",
    1: "UINT8",
    2: "INT16",
    3: "UINT16",
    4: "INT32",
    5: "UINT32",
    6: "FLOAT",
    7: "DOUBLE",
    8: "BOOLEAN",
}

# Parameter type mapping from param.h
ParamTypeSizeLE: Dict[int, Tuple[str, int]] = {
    0: ("b", 1),   # PARAM_TYPE_INT8
    1: ("B", 1),   # PARAM_TYPE_UINT8
    2: ("h", 2),   # PARAM_TYPE_INT16
    3: ("H", 2),   # PARAM_TYPE_UINT16
    4: ("i", 4),   # PARAM_TYPE_INT32
    5: ("I", 4),   # PARAM_TYPE_UINT32
    6: ("f", 4),   # PARAM_TYPE_FLOAT
    7: ("d", 8),   # PARAM_TYPE_DOUBLE
}

ParamTypeName: Dict[int, str] = {
    0: "INT8",
    1: "UINT8", 
    2: "INT16",
    3: "UINT16",
    4: "INT32",
    5: "UINT32",
    6: "FLOAT",
    7: "DOUBLE",
}


def find_project_root(start: Path) -> Path:
    cur = start.resolve()
    for _ in range(6):
        if (cur / "driverframework").is_dir() and (cur / "python").is_dir():
            return cur
        if cur.parent == cur:
            break
        cur = cur.parent
    return start.resolve()


def read_mlog_header_macros(project_root: Path) -> None:
    """Attempt to read mlog.h to set feature flags and constants."""
    global MLOG_ENABLE_DESCRIPTION, MLOG_ENABLE_MODEL_INFO, MLOG_ENABLE_PARAM
    global MLOG_MAX_NAME_LEN_DEFAULT

    header_path = project_root / "driverframework" / "L0_task" / "02_tools" / "TASK_02_SD_MLOG" / "mlog.h"
    if not header_path.is_file():
        return

    text = header_path.read_text(encoding="utf-8", errors="ignore")

    def get_macro_int(name: str, default: Optional[int] = None) -> Optional[int]:
        # Match lines like: #define NAME 0
        m = re.search(rf"^[\t ]*#define[\t ]+{re.escape(name)}[\t ]+([0-9]+)", text, flags=re.MULTILINE)
        if m:
            try:
                return int(m.group(1))
            except Exception:
                return default
        return default

    val = get_macro_int("MLOG_ENABLE_DESCRIPTION", None)
    if val is not None:
        MLOG_ENABLE_DESCRIPTION = val

    val = get_macro_int("MLOG_ENABLE_MODEL_INFO", None)
    if val is not None:
        MLOG_ENABLE_MODEL_INFO = val

    val = get_macro_int("MLOG_ENABLE_PARAM", None)
    if val is not None:
        MLOG_ENABLE_PARAM = val

    val = get_macro_int("MLOG_MAX_NAME_LEN", None)
    if val is not None:
        MLOG_MAX_NAME_LEN_DEFAULT = val


def find_mlog_bin(search_root: Path, target_name: str = "mlog1.bin") -> Optional[Path]:
    for root, _dirs, files in os.walk(search_root):
        if target_name in files:
            return Path(root) / target_name
    return None


def read_exact(data: bytes, offset: int, size: int) -> Tuple[bytes, int]:
    end = offset + size
    if end > len(data):
        raise EOFError("Unexpected EOF while reading")
    return data[offset:end], end


def read_cstr_fixed(raw: bytes) -> str:
    # bytes with possible embedded zeros; strip trailing zeros and spaces
    s = raw.split(b"\x00", 1)[0]
    return s.decode("utf-8", errors="ignore").rstrip("\x00 ")


class ElemDef:
    def __init__(self, name: str, elem_type: int, number: int):
        self.name = name
        self.elem_type = elem_type
        self.number = number

    def field_names(self) -> List[str]:
        if self.number <= 1:
            return [self.name]
        return [f"{self.name}[{i}]" for i in range(self.number)]

    def total_size(self) -> int:
        fmt, size = TypeSizeLE.get(self.elem_type, (None, 0))
        return size * self.number

    def unpack(self, payload: bytes, offset: int) -> Tuple[List[object], int]:
        fmt, size = TypeSizeLE.get(self.elem_type, (None, 0))
        if fmt is None or size == 0:
            raise ValueError(f"Unsupported elem_type {self.elem_type}")
        values: List[object] = []
        for _ in range(self.number):
            chunk, offset = read_exact(payload, offset, size)
            val = struct.unpack("<" + fmt, chunk)[0]
            values.append(val)
        return values, offset


class ParamDef:
    def __init__(self, name: str, param_type: int, value: object):
        self.name = name
        self.param_type = param_type
        self.value = value

    def type_name(self) -> str:
        return ParamTypeName.get(self.param_type, f"TYPE_{self.param_type}")

    def value_str(self) -> str:
        if self.param_type == 0:  # INT8
            return str(self.value)
        elif self.param_type == 1:  # UINT8
            return str(self.value)
        elif self.param_type == 2:  # INT16
            return str(self.value)
        elif self.param_type == 3:  # UINT16
            return str(self.value)
        elif self.param_type == 4:  # INT32
            return str(self.value)
        elif self.param_type == 5:  # UINT32
            return str(self.value)
        elif self.param_type == 6:  # FLOAT
            return f"{self.value:.6f}"
        elif self.param_type == 7:  # DOUBLE
            return f"{self.value:.6f}"
        else:
            return str(self.value)


class ParamGroupDef:
    def __init__(self, name: str, params: List[ParamDef]):
        self.name = name
        self.params = params


class BusDef:
    def __init__(self, bus_id: int, name: str, elems: List[ElemDef]):
        self.bus_id = bus_id
        self.name = name
        self.elems = elems
        # Precompute element byte offsets within payload
        self._elem_offsets: List[int] = []
        off = 0
        for e in elems:
            self._elem_offsets.append(off)
            off += e.total_size()

    def header(self) -> List[str]:
        cols: List[str] = []
        for e in self.elems:
            cols.extend(e.field_names())
        # Append delta_ts column
        cols.append("delta_ts")
        return cols

    def payload_size(self) -> int:
        return sum(e.total_size() for e in self.elems)

    def find_timestamp_field(self) -> Optional[Tuple[int, int]]:
        """Return (elem_index, byte_offset) of a field named 'timestamp' if present and scalar."""
        for idx, e in enumerate(self.elems):
            if e.name == "timestamp" and e.number == 1:
                return idx, self._elem_offsets[idx]
        return None

    def element_descriptions(self) -> List[Tuple[str, str, int]]:
        desc: List[Tuple[str, str, int]] = []
        for e in self.elems:
            _fmt, unit_size = TypeSizeLE.get(e.elem_type, (None, 0))
            total = unit_size * max(1, e.number)
            tname = TypeName.get(e.elem_type, f"TYPE_{e.elem_type}")
            # If vector, we still report the element as a whole total bytes
            desc.append((e.name, tname if e.number == 1 else f"{tname}[{e.number}]", total))
        return desc


def parse_header(data: bytes) -> Tuple[int, int, int, int, int, int, Dict[int, BusDef], List[ParamGroupDef], str, str, int]:
    # Returns: (version, timestamp, max_name_len, max_desc_len, max_model_info_len, num_bus, bus_map, param_groups, description, model_info, offset_after_header)
    offset = 0
    # uint16 version, uint32 ts, uint16 max_name_len, uint16 max_desc_len, uint16 max_model_info_len
    hdr_basic_fmt = "<H I H H H"
    basic_size = struct.calcsize(hdr_basic_fmt)
    chunk, offset = read_exact(data, offset, basic_size)
    version, timestamp, max_name_len, max_desc_len, max_model_info_len = struct.unpack(hdr_basic_fmt, chunk)

    description = ""
    model_info = ""
    
    if MLOG_ENABLE_DESCRIPTION:
        desc_bytes, offset = read_exact(data, offset, max_desc_len)
        description = read_cstr_fixed(desc_bytes)
    if MLOG_ENABLE_MODEL_INFO:
        model_bytes, offset = read_exact(data, offset, max_model_info_len)
        model_info = read_cstr_fixed(model_bytes)

    # num_bus (uint8)
    num_bus = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
    offset += 1

    bus_map: Dict[int, BusDef] = {}
    name_len = max_name_len if max_name_len > 0 else MLOG_MAX_NAME_LEN_DEFAULT
    for _ in range(num_bus):
        # name[name_len]
        raw_name, offset = read_exact(data, offset, name_len)
        bus_name = read_cstr_fixed(raw_name)
        # msg_id (uint8)
        msg_id = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
        offset += 1
        # num_elem (uint8)
        num_elem = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
        offset += 1

        elems: List[ElemDef] = []
        for _k in range(num_elem):
            raw_en, offset = read_exact(data, offset, name_len)
            elem_name = read_cstr_fixed(raw_en)
            # uint16 type, uint16 number
            etype, number = struct.unpack("<H H", read_exact(data, offset, 4)[0])
            offset += 4
            elems.append(ElemDef(elem_name, etype, number))

        bus_map[msg_id] = BusDef(msg_id, bus_name, elems)

    # Parse parameter information
    param_groups: List[ParamGroupDef] = []
    if MLOG_ENABLE_PARAM:
        # num_param_group (uint8)
        num_param_group = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
        offset += 1
        
        for _ in range(num_param_group):
            # group name[name_len]
            raw_group_name, offset = read_exact(data, offset, name_len)
            group_name = read_cstr_fixed(raw_group_name)
            # param_num (uint8)
            param_num = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
            offset += 1
            
            params: List[ParamDef] = []
            for _k in range(param_num):
                # param name[name_len]
                raw_param_name, offset = read_exact(data, offset, name_len)
                param_name = read_cstr_fixed(raw_param_name)
                # param type (uint8)
                param_type = struct.unpack("<B", read_exact(data, offset, 1)[0])[0]
                offset += 1
                
                # Read parameter value based on type
                fmt, size = ParamTypeSizeLE.get(param_type, (None, 0))
                if fmt is not None and size > 0:
                    value_bytes, offset = read_exact(data, offset, size)
                    value = struct.unpack("<" + fmt, value_bytes)[0]
                else:
                    value = 0
                
                params.append(ParamDef(param_name, param_type, value))
            
            param_groups.append(ParamGroupDef(group_name, params))

    return (
        version,
        timestamp,
        max_name_len,
        max_desc_len,
        max_model_info_len,
        num_bus,
        bus_map,
        param_groups,
        description,
        model_info,
        offset,
    )


def ensure_csv_writer(out_dir: Path, bus: BusDef, writers: Dict[int, Tuple[csv.writer, object]]) -> Tuple[csv.writer, object]:
    if bus.bus_id in writers:
        return writers[bus.bus_id]
    out_dir.mkdir(parents=True, exist_ok=True)
    safe_name = bus.name if bus.name else f"bus_{bus.bus_id}"
    filename = f"mlog_msg_{bus.bus_id}_{safe_name}.csv"
    f = open(out_dir / filename, "w", newline="", encoding="utf-8")
    w = csv.writer(f)
    w.writerow(bus.header())
    writers[bus.bus_id] = (w, f)
    return w, f


def parse_frames(data: bytes, start_offset: int, bus_map: Dict[int, BusDef], out_dir: Path) -> None:
    writers: Dict[int, Tuple[csv.writer, object]] = {}
    prev_ts_map: Dict[int, int] = {}
    frame_count: Dict[int, int] = {}
    i = start_offset
    n = len(data)
    while i + 4 <= n:  # minimal frame size
        if data[i] == MLOG_BEGIN_MSG1 and i + 1 < n and data[i + 1] == MLOG_BEGIN_MSG2:
            if i + 2 >= n:
                break
            msg_id = data[i + 2]
            bus = bus_map.get(msg_id)
            if bus is None:
                # Unknown id; resync by advancing one byte
                i += 1
                continue
            payload_len = bus.payload_size()
            frame_end_pos = i + 3 + payload_len  # index where end marker expected
            if frame_end_pos >= n:
                break
            if data[frame_end_pos] != MLOG_END_MSG:
                # Desync; advance by 1 to re-scan
                i += 1
                continue

            # Extract payload
            payload = data[i + 3: i + 3 + payload_len]
            # Decode row
            row: List[object] = []
            off = 0
            try:
                for e in bus.elems:
                    vals, off = e.unpack(payload, off)
                    row.extend(vals)
            except Exception:
                # On decoding error, resync and continue
                i += 1
                continue

            # Compute delta_ts based on a field named 'timestamp' if available
            delta_ts = 0
            ts_info = bus.find_timestamp_field()
            if ts_info is not None:
                ts_idx, ts_byte_off = ts_info
                # Extract 4-byte little-endian chunk for timestamp (expect uint32)
                try:
                    ts_raw = payload[ts_byte_off:ts_byte_off + 4]
                    ts_val = struct.unpack('<I', ts_raw)[0]
                except Exception:
                    ts_val = 0
                prev = prev_ts_map.get(msg_id)
                if prev is not None:
                    delta_ts = (ts_val - prev) & 0xFFFFFFFF
                prev_ts_map[msg_id] = ts_val

            row.append(delta_ts)

            w, _f = ensure_csv_writer(out_dir, bus, writers)
            w.writerow(row)

            # Count frames per message
            frame_count[msg_id] = frame_count.get(msg_id, 0) + 1

            # Advance to next possible frame after this one
            i = frame_end_pos + 1
        else:
            i += 1

    # Close all files
    for _id, (_w, f) in writers.items():
        try:
            f.close()
        except Exception:
            pass

    # Summary report
    total_msgs = len(bus_map)
    print(f"总消息种类: {total_msgs}")
    for bid in sorted(bus_map.keys()):
        print(f"msg_id={bid} '{bus_map[bid].name}': 帧数={frame_count.get(bid, 0)}")
    # Detailed element layout per message
    print("元素布局详情：")
    for bid in sorted(bus_map.keys()):
        b = bus_map[bid]
        print(f"msg_id={bid} '{b.name}':")
        for name, tname, total_bytes in b.element_descriptions():
            print(f"  - {name}: {tname}, bytes={total_bytes}")


def main() -> int:
    script_dir = Path(__file__).resolve().parent
    project_root = find_project_root(script_dir)
    read_mlog_header_macros(project_root)

    # Search for mlog1.bin starting from project root, then fallback to current working directory
    bin_path = find_mlog_bin(project_root, "mlog1.bin")
    if bin_path is None:
        bin_path = find_mlog_bin(Path.cwd(), "mlog1.bin")
    if bin_path is None:
        print("未找到 mlog1.bin 文件，请将其放在工程目录或当前目录下。")
        return 1

    data = Path(bin_path).read_bytes()

    try:
        version, ts, max_name_len, max_desc_len, max_model_info_len, num_bus, bus_map, param_groups, description, model_info, off = parse_header(data)
    except EOFError:
        print("文件过短，无法解析头部。")
        return 2
    except Exception as e:
        print(f"解析头部失败: {e}")
        return 3

    print(f"解析头部成功: version={version}, timestamp={ts}, num_bus={num_bus}")
    print(f"名称长度={max_name_len}, 描述长度={max_desc_len}, 模型信息长度={max_model_info_len}")
    
    if description:
        print(f"描述信息: {description}")
    if model_info:
        print(f"模型信息: {model_info}")
    
    print(f"参数组数量: {len(param_groups)}")
    for pg in param_groups:
        print(f"  参数组: {pg.name}, 参数数量: {len(pg.params)}")
        for p in pg.params:
            print(f"    {p.name}: {p.type_name()} = {p.value_str()}")
    
    for bid, b in bus_map.items():
        print(f"  msg_id={bid}, bus='{b.name}', 元素数={len(b.elems)}, payload大小={b.payload_size()} 字节")

    out_dir = script_dir / "out"
    parse_frames(data, off, bus_map, out_dir)
    print(f"解析完成。CSV 输出目录: {out_dir}")
    return 0


if __name__ == "__main__":
    sys.exit(main())


