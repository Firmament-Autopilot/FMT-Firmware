<p align="center"><img width="200" src="https://github.com/FirmamentPilot/fmt_user_guide_cn/blob/master/figures/logo.png" alt=FMT logo"></p>
  
<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
</p>

## 概述
Firmament Autopilot (简称FMT) 是首个基于模型设计 (Model-Based Design， 简称MBD) 的开源自驾仪。FMT项目从 [Starry Pilot](https://github.com/JcZou/StarryPilot) 开源飞控发展而来，
包括一个主要用C语言实现的嵌入式飞控系统 [FMT Firmware](https://github.com/FirmamentPilot/FMT_Firmware) 以及基于 Matlab/Simulink 开发的算法模型库和仿真框架 
[FMT Model](https://github.com/FirmamentPilot/FMT_Model)。

基于FMT平台可以更快速的开发和验证的飞控算法，无需手动编写嵌入式代码，只需要在Simulink中通过图形化的方式设计算法模型然后一键生成C/C++代码。生成的代码可以直接并合入飞控，而无需修改和编
写任何嵌入式代码。

**项目地址**：https://github.com/FirmamentPilot

## FMT Firmware架构
FMT Firmware 为飞控的嵌入式部分，采用**分层设计模式**，层与层，模块与模块之间松耦合，易于单独添加/删除模各个模块。 FMT Firmware 架构如下图所示。

![fmt_structure](figures/fmt_struct.png)

它具体包括以下部分：

- 内核层 (RTOS): 内核层采用实时操作系统 RT-Thread,提供了例如多线程及其调度、信号量、邮箱、消息队列、内存管理、定时器等；DFS 是 RT-Thread 提供的虚拟文件系统组件，全称为 Device File System, 提供标准POSIX接口。MSH为RT-Thread提供的命令行系统组件，FMT基于MSH进一步封装，提供了丰富的指令。Library则包含一些三方库，如Mavlink, STIM32 Standard Library等。
- 驱动层 (Driver): 驱动层提供了Pixhawk板载和外扩的外设驱动支持，如IMU, GPS, 磁力计，气压计，SD卡，USB以及通信总线，如I2C，SPI，DMA等。
- 硬件抽象层 (HAL)： 在Driver层之上的HAL为上层提供统一的设备接口 (rt_read, rt_write, rt_control)，这样当替换不同的驱动设备或者移植到不同硬件上时，上层将不需要或者只需做很少的改动即可。一些与硬件无关的驱动逻辑也可以都放在HAL层中实现，这样就简化了驱动的开发难度。
- 模块层 (Module)：模块层提供FMT系统的基础功能模块，系统的大部分功能在这层实现，并提供给Task层进行组合，调用。比如跨进程通信模块uMCN提供基于发布/订阅模式的安全跨进程通信机制。log模块提供了二进制日志 (blog)和文字日志 (ulog)的功能。blog提供功能强大的数据记录功能，在不影响高优先级任务的前提下实时记录算法模块的输入/输入数据，供Simulink模型进行开环仿真。param参数模块提供方便的参数功能，支持命令行/地面站在线调参，并且参数将被记录到blog日志中，供仿真模块读取。算法模块INS, FMS, Controller为FMT Model生成的C/C++源文件，只要模块符合FMT Model Interface的标准，则可以直接嵌入到FMT飞控中，而无需做任何修改。Plant模块为无人机的物理模型 (也可以是其它对象模型)，同样为FMT Model生成。它主要是为了支持HIL Internal仿真模式，即无人机模型 (包括传感器模型)跑在飞控上而非外部的实时PC。
- 任务层 (Task)： 每个Task为一个单独的线程 (内部可以创建子线程) 实现独立的功能。比如最重要的`vehicle`任务，将选择适合被控对象的INS，FMS和Controller组件，负责周期性运行模型并采集和发布模型的输入/输出数据，因此vehicle任务具有最高优先级，以保证被控对象的稳定。fmtio任务负责跟IO协处理器进行通信，IO将提供RC和Motor等相关的功能。logger任务负责将采集blog和ulog的日志数据并存储到对应的存储设备，如SD卡。comm任务使用mavproxy模块的接口提供mavlink通信相关的功能。status任务的主要功能是显示当前系统的状态，可以通过LED，蜂鸣器和控制台等进行显示。
- 应用层 (App)  **(TODO)**: 应用层采用动态加载的模式，使用FMT提供的SDK实现一些复杂的任务功能，比如视觉避障，路径规划等。

## 为什么使用 FMT
基于模型设计是一种数学及可视化的设计方法，通过图形化的方式设计复杂的飞控或者其它控制系统。目前大部分开源飞控系统的研发手段还是采用传统的手动编码的开发模式。这种方式固然有其优势，
但是其劣势也越来越明显。特别当系统变得越来越庞大，功能越来越复杂，使用手写的算法模块变得越来越难以维护，也不可避免的造成代码的安全性和可移植性越来越差。

FMT 的核心算法使用 Simulink 搭建，继承了 MBD 开发模式的诸多优点。基于 FMT 可以更快地开发出高性能、高可靠的自驾仪系统。总结起来，MBD 具有以下优势：

1. 极大提升算法开发效率，节省时间和人力成本。
2. 减少手动编写代码过程中产生的错误，提升系统稳定性。
3. 极大提升算法的优化和 Debug 效率，简化系统测试和验证流程。
4. 提高算法的可维护性和可移植性。

FMT Firmware 是一个轻量级，高实时性和高性能的嵌入式飞控系统 FMT_Firmware，支持当前最流行的开源飞控硬件 Pixhawk (2.4.6/2.4.8)。

- C 语言编写的轻量级飞控系统，高度模块化设计，更加易于使用和二次开发。
- 基于硬实时操作系统 RT-Thread，时间误差 < 1us。
- 高度优化的系统结构和算法，可以用更高频率运行复杂的算法模块。比如以 500Hz 运行基础导航和控制器，250Hz 运行飞行管理状态机的 CPU 使用率 < 30%。更大的空间用以提高算法的复杂度和运行频率。
- 支持 Mavlink V1.0/V2.0，支持主流地面站 QGC，Mission Planner等。
- 支持半物理硬件在环仿真 (Hardware-in-the-loop Simulation, HIL) 和无人机模型运行在飞控上的硬件仿真 (Simulator-in-hardware, SIH)。

## Contributor
A big thanks to these contributor:
- weety, luohui2320@gmail.com
- yangjiong, 275011821@qq.com


