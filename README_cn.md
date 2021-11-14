<p align="center"><img width="160" src="figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/actions/workflows/main.yml"><img src="https://img.shields.io/github/workflow/status/Firmament-Autopilot/FMT-Firmware/FMT-Firmware%20CI/master" alt="build status"></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/releases"><img src="https://img.shields.io/github/v/release/Firmament-Autopilot/FMT-Firmware" alt="release version" /></a>
</p>

## 概述
Firmament (FMT) 是一款基于模型设计 (Model-Based-Design, MBD) 的开源自驾仪，可被用来快速构建无人机，无人车，无人船，机器人等平台的控制系统。

系统主要由两部分构成.

- [FMT-Firmware](https://github.com/Firmament-Autopilot/FMT-Firmware): 一个基于C/C++开发的稳定、高性能的嵌入式系统.
- [FMT-Model](https://github.com/Firmament-Autopilot/FMT-Model): 一个基于MATLAB/Simulink开发的仿真框架以及算法库.

## 特点
- 基于模型设计提供更高效的开发体验以及更轻松的调试方式 .
- 一个稳定、高性能的基于C/C++设计的嵌入式系统。
- 一个基于MATLAB/Simulink的强大仿真平台，并提供多种算法模块。
- Simulink模型自动代码生成，支持众多硬件架构 (ARM, AMD, Intel, etc).
- 出色的实时性能，基于国产RTOS [RT-Thread](https://www.rt-thread.org/), 拥有活跃的开源社区以及大量第三方组件。
- 支持当前最广泛使用的开源硬件Pixhawk (同时支持 FMUv2 和 FMUv5版本).
- 跨平台的编译工具链，支持Windows/Linux/Mac.
- 支持Mavlink协议v1.0/v2.0.

## 架构
FMT Firmware架构如下图所示。

<img src="figures/fmt_struct.png" width="75%">

## 硬件
当前支持硬件平台 [Pixhawk(FMUv2)](https://docs.px4.io/master/en/flight_controller/pixhawk.html) 和 [Pixhawk 4(FMUv5)](https://docs.px4.io/master/en/flight_controller/pixhawk4.html). 请访问[网站](https://pixhawk.org/)来获得更多硬件信息.

## 文档
[用户手册](https://firmament-autopilot.github.io/FMT-DOCS/#/content_ch/)

## License
[Apache-2.0](./LICENSE)
