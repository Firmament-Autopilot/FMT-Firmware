# FRAM Parameter Backup Implementation Guide

## Implementation Summary

✅ **COMPLETED**: FRAM parameter backup has been fully implemented for FMU-v6C

### What Was Implemented

1. **param_fram.c / param_fram.h** - FRAM parameter storage module
   - Binary parameter packing/unpacking
   - CRC32 verification for data integrity
   - Direct MTD device access (no filesystem)
   - Supports all parameter types

2. **param.c modifications** - Integrated automatic backup
   - `param_save()` - Automatically backs up to FRAM after SD card save
   - `param_load()` - Automatically falls back to FRAM if SD card fails
   - `param_get_group_count()` - Helper function added

3. **cmd_param.c** - Added FRAM test commands
   - `param fram_save` - Manually save to FRAM
   - `param fram_load` - Manually load from FRAM
   - `param fram_check` - Check FRAM validity
   - `param fram_erase` - Erase FRAM backup

### Storage Architecture

```
SD Card (Primary Storage):
  /sys/param.xml - XML format (human-readable, ~50KB)

FRAM (Backup Storage - 32KB):
  Sector 0:     Header (512 bytes)
                - Magic: 0x464D5450 ("FMTP")
                - Version, CRC, data size
  Sectors 1-63: Binary parameter data (31KB max)
                - Packed format: [type][name_len][name][value]
```

## Usage

### Normal Operation (Automatic Backup)

```bash
# Save parameters (automatically saves to both SD and FRAM)
msh> param save
parameter saved to /sys/param.xml
Parameters backed up to FRAM
Parameters saved to FRAM (1234 bytes)

# Load parameters (tries SD first, falls back to FRAM)
msh> param load
parameter loaded from /sys/param.xml

# If SD card fails:
msh> param load
SD card parameter file not found, trying FRAM backup...
Parameters loaded from FRAM (1234 bytes)
```

### Manual FRAM Testing

```bash
# Check if FRAM has valid parameters
msh> param fram_check
FRAM has valid parameters

# Manually save to FRAM (for testing)
msh> param fram_save
Parameters saved to FRAM (1234 bytes)
Parameters saved to FRAM successfully

# Manually load from FRAM (for testing)
msh> param fram_load
Parameters loaded from FRAM (1234 bytes)
Parameters loaded from FRAM successfully

# Erase FRAM backup
msh> param fram_erase
FRAM parameters erased
FRAM parameters erased successfully
```

### Testing Scenarios

#### Test 1: Verify Automatic Backup
```bash
msh> param set TEST_PARAM 12.34
msh> param save              # Should backup to FRAM automatically
msh> param fram_check        # Should show valid parameters
```

#### Test 2: Verify Fallback to FRAM
```bash
# 1. Save parameters normally
msh> param save

# 2. Remove SD card or corrupt param.xml file

# 3. Reboot and load parameters
msh> param load
# Should automatically load from FRAM backup

# 4. Verify parameter values
msh> param get TEST_PARAM
# Should show correct value from FRAM
```

#### Test 3: Verify FRAM Integrity
```bash
# Reboot multiple times and verify FRAM still works
msh> param fram_check        # Should remain valid after reboot
```

## Technical Details

### FRAM Storage Format

**Header Structure (20 bytes):**
```c
typedef struct {
    uint32_t magic;         // 0x464D5450 ("FMTP")
    uint16_t version;       // Current: 1
    uint16_t param_count;   // Total parameters
    uint32_t data_size;     // Data size in bytes
    uint32_t data_crc;      // CRC32 of data
    uint32_t header_crc;    // CRC32 of header
} fram_param_header_t;
```

**Parameter Data Format:**
```
[type:1][name_len:1][name:n][value:1/2/4/8]
[type:1][name_len:1][name:n][value:1/2/4/8]
...
```

### Implementation Logic

**param_save() flow:**
```
1. Save parameters to SD card XML file
2. Pack all parameters to binary format
3. Calculate CRC for data
4. Write header to FRAM sector 0
5. Write data to FRAM sectors 1+
6. Verify write success
```

**param_load() flow:**
```
1. Try to open SD card param.xml
2. If SD card fails:
   a. Read FRAM header
   b. Verify magic and CRC
   c. Read parameter data
   d. Verify data CRC
   e. Unpack parameters
3. Return success/error
```

## Benefits

1. **Reliability**: Parameters survive SD card failures
2. **Fast Boot**: FRAM access faster than SD card
3. **Wear Leveling**: FRAM has 10^14 write cycles
4. **Zero Latency**: Direct MTD access, no filesystem overhead
5. **Automatic**: Transparent backup/restore

## Troubleshooting

### FRAM Not Found
```bash
msh> param fram_check
FRAM device mtdblk0 not found
```
**Solution**: Check if `drv_ramtron_init("spi2_dev1")` is called in board.c

### CRC Mismatch
```bash
msh> param fram_load
FRAM header CRC mismatch
```
**Solution**: FRAM corrupted, use `param fram_erase` then `param save`

### Buffer Overflow
```bash
msh> param fram_save
FRAM buffer overflow!
```
**Solution**: Too many parameters (>30KB), reduce parameter count

## Files Modified/Created

**New Files:**
- `src/module/param/param_fram.h` - FRAM parameter interface
- `src/module/param/param_fram.c` - FRAM parameter implementation

**Modified Files:**
- `src/module/param/param.c` - Added FRAM backup/restore
- `src/module/param/param.h` - Added param_get_group_count()
- `src/module/syscmd/cmd_param.c` - Added FRAM test commands
- `target/pixhawk/fmu-v6c/board/board.c` - Updated comments

**Build System:**
- No changes needed (param/*.c wildcard already includes param_fram.c)

## Comparison with PX4

| Feature | PX4 | FMT (This Implementation) |
|---------|-----|---------------------------|
| Primary Storage | Binary blocks | XML files (SD card) |
| Backup Storage | FRAM direct MTD | FRAM direct MTD ✅ |
| Storage Size | ~30KB | ~30KB ✅ |
| CRC Verification | Yes | Yes ✅ |
| Automatic Backup | Yes | Yes ✅ |
| Fallback on Error | Yes | Yes ✅ |
| User Commands | Limited | Full test suite ✅ |

## Next Steps

1. **Test on Hardware**: Verify FRAM read/write works on FMU-v6C
2. **SD Card Removal Test**: Verify fallback to FRAM works
3. **Power Cycle Test**: Verify FRAM survives reboots
4. **Performance Test**: Measure FRAM vs SD card load time
5. **Stress Test**: Write/read FRAM 1000+ times

## References

- PX4 FRAM Usage: https://github.com/PX4/PX4-Autopilot/blob/main/boards/px4/fmu-v6c/src/mtd.cpp
- FM25V02A Datasheet: 256Kbit (32KB) FRAM
- FMT Parameter System: src/module/param/param.c

