# FMT Pixhawk4移植

Pixhawk4采用Pixhawk FMUv5的硬件，[资料地址](https://github.com/pixhawk/Hardware/tree/master/FMUv5)

FMT移植到Pixhawk4上大体分为两步。第一步先将FMT的最小系统（仅包含RTOS，systick系统时钟和串口等）在Pixhawk4上跑起来。第二步在添加Pixhawk4的驱动程序。

## FMT最小系统移植
最小系统仅仅包含最基础的功能，能够让RTOS给运行起来，并且包含Systick系统时钟和串口的驱动，可以通过串口连接到系统控制台。移植最小系统主要包含以下步骤。

### 1. 移植STM32F7固件库
首先需要下载[STM32F7的固件库](https://github.com/STMicroelectronics/STM32CubeF7)(最新版本为v1.16.0)，放到`fmt_fmu/src/lib/STM32_Lib`目录下。目前的`STM_Lib`中只包含了STM32F4xx的固件库。
目前FMT的启动文件为`fmt_fmu/src/lib/STM_Lib/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f427x.s`，对于Pixhawk4需要替换为对应固件库中f7的文件。

### 2. 修改RTOS
创建`target/pixhawk4`目录，并将`tartget/pixhawk`中的内容复制过来。然后对该目录中的文件进行修改。

- **bsp.c**: 只保留systick, serial的驱动初始化，将其它驱动的初始化函数先删除或者注释掉。
- **rtconfig.py**: 修改该文件，使其适配`cortex-m7`，可以参考RTT stm32f767的bsp
- **stm32_rom.ld**: 修改该文件，使其适配stm32f765，主要是ROM/RAM的起始地址和大小等

### 3. 修改驱动

- systick驱动：修改`fmt_fmu/src/driver/systick/systick_drv.c`以支持pixhawk4的系统时钟
- serial驱动：修改`fmt_fmu/src/driver/usart/usart.c`以支持pixhawk4的串口功能

## 添加Pixhawk4的其它驱动

TBD

