<p align="center"><img width="200" src="https://github.com/FirmamentPilot/FMT_Firmware/blob/master/figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
</p>

## 概述
Firmament Autopilot (简称FMT) 是首个基于模型设计 (Model-Based Design， 简称MBD) 的开源自驾仪。FMT项目从 [Starry Pilot](https://github.com/JcZou/StarryPilot) 开源飞控发展而来，
包括一个主要用C语言实现的嵌入式飞控系统 [FMT Firmware](https://github.com/FirmamentPilot/FMT_Firmware) 以及基于 Matlab/Simulink 开发的算法模型库和仿真框架 
[FMT Model](https://github.com/FirmamentPilot/FMT_Model)。

基于FMT平台可以更快速的开发和验证的飞控算法，无需手动编写嵌入式代码，只需要在Simulink中通过图形化的方式设计算法模型然后一键生成C/C++代码。生成的代码可以直接合入飞控而无需修改和编写任何嵌入式代码，大大提高算法的开发和验证效率。

**项目地址**：https://github.com/FirmamentPilot

## FMT Firmware架构
FMT Firmware 为飞控的嵌入式部分，采用**分层设计模式**，层与层，模块与模块之间松耦合，其架构如下图所示。

![fmt_structure](figures/fmt_struct.png)

它具体包括以下部分：

- 内核层 (RTOS): 内核层采用实时操作系统 RT-Thread,提供了例如多线程及其调度、信号量、邮箱、消息队列、内存管理、定时器等；DFS 是 RT-Thread 提供的虚拟文件系统组件，提供标准POSIX接口。
- 驱动层 (Driver): 驱动层提供硬件驱动支持，如IMU, GPS, 磁力计，气压计，SD卡，USB以及通信总线，如I2C，SPI，DMA等。
- 硬件抽象层 (HAL)： HAL为上层提供统一的read/write/control设备接口。便于添加新的驱动设备或者移植到不同硬件平台上。同时可以将与硬件无关的驱动逻辑放在HAL层实现，简化了驱动的开发难度。
- 模块层 (Module)：模块层提供FMT系统的大部分功能。比如基于发布/订阅模式的跨进程通信机制uMCN。日志模块提供了二进制日志，文字日志和开机日志的功能。参数模块提供强大的参数功能，支持命令行/地面站在线调参。并且参数也将保存到日志中，供仿真模型读取。
- 任务层 (Task)： 每个Task为一个单独的线程 (内部可以创建子线程) 实现独立的功能。比如`vehicle`任务将周期性执行INS，FMS和Controller，以实现被控对象的控制。

## 为什么使用 FMT
基于模型设计是一种数学及可视化的设计方法，通过图形化的方式设计复杂的飞控或者其它控制系统。传统的手动编码的开发模式固然有其优势，但是其劣势也越来越明显。特别当系统变得越来越庞大，功能越来越复杂，使用手写的算法模块变得越来越难以维护，也不可避免的造成代码的安全性和可移植性越来越差。

FMT 的核心算法基于 Matlab/Simulink 平台搭建，继承了 MBD 开发模式的诸多优点，包括：
1. 极大提升算法开发效率，节省时间和人力成本。
2. 减少手动编写代码过程中产生的错误，提升系统稳定性。
3. 极大提升算法的优化和 Debug 效率，简化系统测试和验证流程。
4. 提高算法的可维护性和可移植性。

FMT Firmware 具有轻量级，易于阅读和使用的特点，并且兼具稳定性和实时性。总结起来，FMT Firmware 的特点包括：

- C 语言编写的轻量级飞控系统，更易使用和二次开发。
- 跨平台的开发工具链，支持Windows/Linux/Mac OS。
- 支持MBD设计模式，大大提升开发和测试效率。
- 支持当前最流行的开源飞控硬件 Pixhawk。
- 高实时性，时间误差 < 1us。
- 更高运行效率和更低的CPU使用率。提供更大算力空间用以提高算法复杂度和运行频率。
- 支持 Mavlink V1.0/V2.0和主流地面站 QGC，Mission Planner等。
- 支持硬件在环仿真 (HIl/SIH)。
- 高度模块化，松耦合的软件架构，易于裁剪和移植。

## 硬件平台
- **Pixhawk**: version 2.4.6 or 2.4.8.
-  未来将支持更多硬件. 

## 文档
[用户手册](https://github.com/FirmamentPilot/fmt_user_guide_cn)

## 开发环境
需要如下工具链进行开发：

- 编译器: arm-none-eabi- toolchain (recommend: `7-2018-q2-update`，other version are not well tested). [download](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- 构建工具: Scons
  - Python 2.x (Python 2.7.x is preferable) is needed
  - Scons 2.x (Scons 2.3.6 is prederable) is needed: [download](https://sourceforge.net/projects/scons/files/scons/2.3.6/)
- USB 驱动 (仅针对Windows): [download](https://www.st.com/en/development-tools/stsw-stm32102.html)

## 开发者名单
非常感谢如下开发者的贡献！
- [weety](https://github.com/weety)
- [yangjiong](https://github.com/yangjion)

## 联系
欢迎加入QQ群
<p align="left"><img width="200" src="figures/QR_code.png" alt=QR code"></p>


