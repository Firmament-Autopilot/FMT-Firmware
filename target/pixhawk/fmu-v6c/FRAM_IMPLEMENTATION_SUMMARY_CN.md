# FMU-v6C FRAM 参数备份实现总结

## 实现概述

✅ 已完成FMU-v6C的FRAM参数备份功能，实现了类似PX4的双存储架构

## 实现细节

### 1. 核心功能

**自动备份机制（参考PX4设计）：**
- SD卡保存参数时 → 自动备份到FRAM
- SD卡加载参数失败 → 自动从FRAM恢复
- 无需用户干预，完全透明

### 2. 存储架构

```
主存储：SD卡
  /sys/param.xml (XML格式，可编辑，~50KB)

备份存储：FRAM (32KB)
  扇区0:      头部 (512字节)
              - 魔数: 0x464D5450 ("FMTP")
              - 版本、CRC、数据大小
  扇区1-63:   二进制参数数据 (31KB)
              - 格式: [类型][名称长度][名称][值]
```

### 3. 使用场景

**场景1：正常操作**
```bash
msh> param save    # 自动保存到SD卡和FRAM
msh> param load    # 从SD卡加载
```

**场景2：SD卡故障**
```bash
# SD卡损坏或移除
msh> param load    # 自动从FRAM加载备份
SD card parameter file not found, trying FRAM backup...
Parameters loaded from FRAM (1234 bytes)
```

**场景3：手动测试**
```bash
msh> param fram_check    # 检查FRAM备份状态
FRAM has valid parameters

msh> param fram_save     # 手动保存到FRAM
msh> param fram_load     # 手动从FRAM加载
msh> param fram_erase    # 清除FRAM备份
```

## 技术优势

1. **可靠性**: 参数在SD卡故障时不会丢失
2. **快速启动**: FRAM访问速度比SD卡快
3. **高寿命**: FRAM支持10^14次写入（SD卡仅10^5次）
4. **零延迟**: 直接MTD访问，无文件系统开销
5. **自动化**: 用户无感知的备份/恢复

## 文件清单

**新增文件：**
- `src/module/param/param_fram.h` - FRAM参数接口
- `src/module/param/param_fram.c` - FRAM参数实现（500+行）

**修改文件：**
- `src/module/param/param.c` - 集成FRAM备份/恢复
- `src/module/param/param.h` - 新增param_get_group_count()
- `src/module/syscmd/cmd_param.c` - 新增FRAM测试命令
- `target/pixhawk/fmu-v6c/board/board.c` - 更新注释

**构建系统：**
- 无需修改（param/*.c已包含）

## 测试步骤

### 1. 验证FRAM设备
```bash
msh> list_device
# 应该看到 mtdblk0 设备
```

### 2. 测试自动备份
```bash
msh> param set SYSTEM TEST_VALUE 123
msh> param save
# 应该显示：
# parameter saved to /sys/param.xml
# Parameters backed up to FRAM
# Parameters saved to FRAM (xxxx bytes)
```

### 3. 测试故障恢复
```bash
# 1. 正常保存参数
msh> param save

# 2. 移除SD卡或重命名param.xml

# 3. 重启并加载参数
msh> param load
# 应该显示：
# SD card parameter file not found, trying FRAM backup...
# Parameters loaded from FRAM (xxxx bytes)

# 4. 验证参数值正确
msh> param get SYSTEM TEST_VALUE
# 应显示正确的值
```

### 4. 测试FRAM命令
```bash
msh> param fram_check    # 检查FRAM状态
msh> param fram_save     # 手动保存
msh> param fram_load     # 手动加载
msh> param fram_erase    # 清除备份
```

## 与PX4对比

| 特性 | PX4 | FMT (本实现) |
|------|-----|-------------|
| 主存储 | 二进制块 | XML文件（SD卡）|
| 备份存储 | FRAM直接MTD | FRAM直接MTD ✅ |
| 存储容量 | ~30KB | ~30KB ✅ |
| CRC校验 | 是 | 是 ✅ |
| 自动备份 | 是 | 是 ✅ |
| 故障恢复 | 是 | 是 ✅ |
| 测试命令 | 有限 | 完整套件 ✅ |

## 故障排除

### FRAM设备未找到
```bash
msh> param fram_check
FRAM device mtdblk0 not found
```
**解决方案**: 检查board.c中`drv_ramtron_init("spi2_dev1")`是否被调用

### CRC校验失败
```bash
msh> param fram_load
FRAM header CRC mismatch
```
**解决方案**: FRAM数据损坏，使用`param fram_erase`清除后重新保存

### 缓冲区溢出
```bash
msh> param fram_save
FRAM buffer overflow!
```
**解决方案**: 参数太多（>30KB），需要减少参数数量

## 技术细节

### FRAM数据格式

**头部结构（20字节）：**
```c
struct {
    uint32_t magic;       // 0x464D5450 ("FMTP")
    uint16_t version;     // 当前版本：1
    uint16_t param_count; // 参数总数
    uint32_t data_size;   // 数据大小
    uint32_t data_crc;    // 数据CRC32
    uint32_t header_crc;  // 头部CRC32
}
```

**参数数据格式：**
```
[类型:1字节][名称长度:1字节][名称:n字节][值:1/2/4/8字节]
[类型:1字节][名称长度:1字节][名称:n字节][值:1/2/4/8字节]
...
```

### 保存流程
1. 保存参数到SD卡XML文件
2. 打包所有参数为二进制格式
3. 计算数据CRC
4. 写入头部到FRAM扇区0
5. 写入数据到FRAM扇区1+
6. 验证写入成功

### 加载流程
1. 尝试打开SD卡param.xml
2. 如果SD卡失败：
   - 读取FRAM头部
   - 验证魔数和CRC
   - 读取参数数据
   - 验证数据CRC
   - 解包参数
3. 返回成功/失败

## 后续工作

1. ✅ 实现FRAM备份功能
2. ⏳ 硬件测试验证
3. ⏳ SD卡故障测试
4. ⏳ 电源循环测试
5. ⏳ 性能基准测试
6. ⏳ 压力测试（1000+次读写）

## 参考资料

- PX4 FRAM实现: https://github.com/PX4/PX4-Autopilot/blob/main/boards/px4/fmu-v6c/src/mtd.cpp
- FM25V02A数据手册: 256Kbit (32KB) FRAM
- RT-Thread MTD驱动: rtos/rt-thread/components/drivers/include/drivers/mtd_nor.h
- FMT参数系统: src/module/param/param.c

## 总结

本实现完全参考PX4的设计思路，实现了：
- ✅ FRAM直接MTD存储（非文件系统）
- ✅ 自动备份到FRAM
- ✅ 自动从FRAM恢复
- ✅ CRC完整性校验
- ✅ 完整的测试命令集

**FRAM不应该被禁用！**它是宝贵的32KB非易失性存储，用于关键参数备份，确保系统在SD卡故障时依然可靠运行。
