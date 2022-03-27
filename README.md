<p align="center"><img width="160" src="figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/actions/workflows/main.yml"><img src="https://img.shields.io/github/workflow/status/Firmament-Autopilot/FMT-Firmware/FMT-Firmware%20CI/master" alt="build status"></a>
  <a href="https://github.com/Firmament-Autopilot/FMT-Firmware/releases"><img src="https://img.shields.io/github/v/release/Firmament-Autopilot/FMT-Firmware" alt="release version" /></a>
</p>

[中文页](README_cn.md) |

Overview
============================
Firmament (FMT) is an advanced autopilot system which is designed with Model-based design (MBD). It can be used to quickly and easily build the control system for autonomous vehicle, such as uav, car, ship, robot, etc.

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
- Support with Mavlink and [QGroundcontrol](https://cn.bing.com/search?form=MOZLBR&pc=MOZI&q=QGroundControl).

## Architecture
FMT Firmware's architecture is shown in the figure below.

<img src="figures/fmt_struct.png" width="70%">

## Hardware
Current supported hardware:
- [Pixhawk (FMUv2)](https://docs.px4.io/master/en/flight_controller/pixhawk.html)
- [Pixhawk4 (FMUv5)](https://docs.px4.io/master/en/flight_controller/pixhawk4.html)
- [CUAV V5+](https://store.cuav.net/shop/v5-autopilot/)
- QEMU vexpress-a9

## Documentation
[User Guide](https://firmament-autopilot.github.io/FMT-DOCS/)

## Quick Start
1. Clone the project
```
git clone https://github.com/Firmament-Autopilot/FMT-Firmware.git --recursive --shallow-submodules
```
2. Install the toolchian
- Compiler: [arm-none-eabi- toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads): Version:*7-2018-q2-update*， other version are not well tested. When the compiler is installed, add a new environment variable RTT_EXEC_PATH with the value set to compiler's path. E.g, in the linux system:
```
export RTT_EXEC_PATH=$arm-none-eabi-7-2018-q2-update/bin
```
- Construction Tool: [Scons](https://scons.org/): You can use `pip3 install SCons` to install scons. The scons path should be added into *Path* environment variable after installation.
- IDE: [Visual Studio Code](https://code.visualstudio.com/): Visual Studio Code is the recommend IDE. However you can use any other IDE that you are familar with.
- USB Driver: [STM32 USB Driver](https://www.st.com/en/development-tools/stsw-stm32102.html): Only required for Windows platform.

3. Build the firmware

To build the firmware, change to a specific target directory and type command `scons` to start build process. The generated fmu firmware is located in the *build* folder, such as `FMT-Firmware/target/pixhawk/fmu-v5/build`. 
```
cd FMT-Firmware/target/pixhawk/fmu-v5/
scons -j4
```
For some target, such as pixhawk and cuav v5+, there is a co-processor (AKA io processor) on board, so you need build io firmware as well.
```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
```

4. Download the firmware

The download process relys on the on-board  bootloader ([PX4-Bootloader](https://github.com/PX4/PX4-Bootloader)). If not, please flash the bootloader first.

Currently there are three methods to download the fmu firmware,:

- **Upload Script**: Change directory to a specific target and type `python uploader.py`. Then connect your hardware to PC via a usb cable, the download shuold start automatically.

```
~/FMT-Firmware/target/pixhawk/fmu-v5$ python3 uploader.py 
```

> If download is not started, unplug your usb cable then try it again.

- **QGoundControl**: Go to **Firmware Setup** page，then connect your hardware to PC with a usb cable. In pop-up diaglog，select **Advanced Settings**->**Custom firmware file** with `fmt_fmu.bin` firmware.
- **JLink**: Please refer to [Debug](https://firmament-autopilot.github.io/FMT-DOCS/#/introduction/debug) section.

If download success, power on the board and the system banner should be printed on `serial0` (serial0 is the default serial used by console). If you don't have a serial cable, you can also connect to console via QGroundControl **Mavlink Console**

```
   _____                               __ 
  / __(_)_____ _  ___ ___ _  ___ ___  / /_
 / _// / __/  ' \/ _ `/  ' \/ -_) _ \/ __/
/_/ /_/_/ /_/_/_/\_,_/_/_/_/\__/_//_/\__/ 
Firmware..................FMT FW v0.3.0-rc
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target............................CUAV V5+
Vehicle.........................Quadcopter
INS Model..................Base INS v0.2.1
FMS Model..................Base FMS v0.3.1
Control Model.......Base Controller v0.2.1
Task Initialize:
  comm..................................OK
  logger................................OK
  fmtio.................................OK
  status................................OK
  vehicle...............................OK

msh />
```

The next step is to upload the `io firmware` which is downloaded through the fmu. First copy the io firmware `target/pixhawk/fmt-io/project/build/fmt_io.bin` to the on board sd card. You can do that via QGroundControl ftp  (version 3.5.6, the FTP function is removed on higher version) or a sd  card reader. Then type the following command in fmt console to upload  the firmware to io processor.

```
msh /usr>fmtio upload /usr/fmt_io.bin
[312785] I/Uploader: sync success
[312793] I/Uploader: found bootloader revision: 5
[312803] I/Uploader: io firmaware:/usr/fmt_io.bin
[312818] I/Uploader: erase...
[314151] I/Uploader: program...
[316275] I/Uploader: CRC check ok, received: 8a27ed4f, expected: 8a27ed4f
```

> At the first time to download the io firmware, you should click the io reset button after typing `fmtio upload` to let io processor enter bootloader.

After the download is completed, type `fmtio hello` command. You should see the following message which sent from the io processor.

```
msh />fmtio hello
msh />[IO]:Hello, this is FMT IO!
```

Congratulation! Now you have FMT up and running. :)

## License
[Apache-2.0](./LICENSE)
