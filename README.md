<p align="center"><img width="160" src="figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/actions/workflows/build.yml"><img src="https://img.shields.io/github/actions/workflow/status/Firmament-Autopilot/FMT-Firmware/build.yml" alt="build status"></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/releases"><img src="https://img.shields.io/github/v/release/Firmament-Autopilot/FMT-Firmware" alt="release version" /></a>
</p>

<p align="center">
  <strong><a href="https://docs.sieon.net/fmt/#">Guides</a> · <a href="https://docs.sieon.net/product/#/">Products</a> · <a href="https://www.sieon.net/">Website</a></strong>
</p>

Overview
============================
Firmament (FMT) is an advanced autopilot system which is designed with Model-based design (MBD). It can be used to quickly and easily build the control system for autonomous vehicle, such as uav, car, ship, robot, etc.

The system is mainly composed of two parts.

- [FMT-Firmware](https://github.com/Firmament-Autopilot/FMT-Firmware): A stable and high performance embedded system designed with C/C++.
- [FMT-Model](https://github.com/Firmament-Autopilot/FMT-Model): A simulation framework with algorithm libraries designed with MATLAB/Simulink.

## Documentation
[User Guide](https://docs.sieon.net/fmt)

[S1 Flight Controller](https://docs.sieon.net/product)

## Download

```
git clone https://github.com/Firmament-Autopilot/FMT-Firmware.git --recursive --shallow-submodules
```

> Note that FMT-Firmware contains submodules, use *--recursive* to download submodule as well.

## Feature

- High development efficency achieved with model-based deisign and debug easier.
- A stable and high performance embedded system designed with C/C++.
- A powerful simulation framework with various algorithm library designed with MATLAB/Simulink.
- Auto code generation from Simulink model adapted to different hardware platforms (ARM, AMD, Intel, etc).
- Excellent real-time performance based on [RT-Thread](https://www.rt-thread.io/) RTOS with active community and large number of third-party components.
- Support with most widely used open-source hardware Pixhawk (Both FMUv2 and FMUv5 are supported).
- Cross-platform toolchain support with Windows/Linux/Mac.
- Support with Mavlink and [QGroundcontrol](https://cn.bing.com/search?form=MOZLBR&pc=MOZI&q=QGroundControl).

## Architecture
FMT Firmware's architecture is shown in the figure below.

<img src="figures/fmt_struct.png" width="70%">

## Hardware
Current supported hardware:
- [SIEON S1](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/sieon/s1)
- [EDGI-X](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/infineon)
- [AMOV ICF5](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/amov/icf5)(Archived)
- [CUAV V5-Nano](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/cuav/v5_nano)
- [CUAV V5+](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/cuav/v5_plus)
- [CUAV 7Nano](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/cuav/7_nano)
- [CUAV X7+/X7+ Pro](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/cuav/x7_plus)
- [Pixhawk V6C](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/pixhawk/fmu-v6c)
- [Pixhawk4 (FMUv5)](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/pixhawk/fmu-v5)
- [Pixhawk (FMUv2)](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/pixhawk/fmu-v2)(Archived)
- [QEMU vexpress-a9](https://github.com/Firmament-Autopilot/FMT-Firmware/tree/master/target/qemu/qemu-vexpress-a9)

## License
[Apache-2.0](./LICENSE)
