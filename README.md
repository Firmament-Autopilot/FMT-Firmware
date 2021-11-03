<p align="center"><img width="160" src="figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
</p>

[中文页](README_cn.md) |

Overview
============================
Firmament (FMT) is an advanced autopilot system which is developed for Model-Based Design (MBD), which can be used to quickly build control systems for autonomous vehicle, such as uav, car, ship, robot, etc.

The system is mainly composed of two parts.

- [FMT-Firmware](https://github.com/Firmament-Autopilot/FMT-Firmware): A stable and high performance embedded system designed with C/C++.
- [FMT-Model](https://github.com/Firmament-Autopilot/FMT-Model): A simulation framework with algorithm libraries designed with MATLAB/Simulink.

## Feature
- High development efficency achieved with model-based deisign and debug easier.
- A stable and high performance embedded system designed with C/C++.
- A powerful simulation framework with various algorithm library designed with MATLAB/Simulink.
- Auto code generation from Simulink model adapted to different hardware platforms (ARM, AMD, Intel, etc).
- Excellent real-time performance based on [RT-Thread](https://www.rt-thread.io/) RTOS with active community and large number of third-party components.
- Support with most widely used open-source hardware Pixhawk (Both FMUv2 and FMUv5 are supported).
- Cross-platform toolchain support with Windows/Linux/Mac.
- Support with Mavlink v1.0/v2.0.

## Architecture
FMT Firmware's architecture is shown in the figure below.

<img src="figures/fmt_struct.png" width="80%">

## Hardware
The current supported hardware platforms are [Pixhawk(FMUv2)](https://docs.px4.io/master/en/flight_controller/pixhawk.html) and [Pixhawk 4(FMUv5)](https://docs.px4.io/master/en/flight_controller/pixhawk4.html). Please visit the [websit](https://pixhawk.org/) to get more information about the hardware.

## Documentation
[User Guide](https://firmament-autopilot.github.io/FMT-DOCS/)

## License
[Apache-2.0](./LICENSE)
