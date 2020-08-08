Firmament Firmware
============================
Firmament Firmware (FMT_Firmware) is the embedded flight control system of Firmament Autopilot project. The algorithm modules are availble in Firmament Model ([FMT_Model](https://github.com/FirmamentPilot/FMT_Model)), which are developed in Simulink.

Firmament Autopilot is the first open-source autopilot system designed for MBD (Model-Based Design). It consists of two parts:

- FMT_Firmware: The embedded flight control system written in C. It provides all useful features/functions dedicated to MBD, which means you can easily develop your algorithm model using MATLAB/Simulink and then seamlessly integrate into FMT_Firmware. 

- FMT_Model: The algorithm model developed with Simulink. Generally, it contains the model of INS (Inertial Navigation System), FMS (Flight Management System), Controller and Plant (Dynamic model of unmaned-vehicle including sensor model). Each model can generate C/C++ source files and then integrate into FMT_Firmware. Moreover, FMT_Model provides simulation framework for MIL, SIL, HIL etc.

# Supported Hardware
- The current support hardware is `Pixhawk` (FMUv2). However, it may support more hardwares in future. 

# Features
- Designed for model-based design method, you can develop and simulate your algorithm in Simulink and easily deploy to board.
- Integrate with embedded real-time operating system RT-Thread, which is powerful and easy to use.
- Support internal (Plant model runs on-board) and externel (Plant model runs off-board) Hardware-in-the-loop simulation.
- High performance and real-time log system which makes it easy to record all required data be used for open-loop simulation with FMT_Model framework.
- Safe and powerful interprocess communication module (micro Multi-communication Node, uMCN) based on publisher/subscriober model.
- The parameter system, by which you can easily set/get parameter values via command line or ground control station.
- There are more features waiting for you to explore!

# Develop Environment
The supported develop platform is Windows/Linux/Mac. To build the firmware, the following toolchain are needed.

- Compiler: arm-none-eabi- toolchain (recommend: `7-2018-q2-update`，other version are not well tested). [download](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- Construction tool: Scons
  - Python 2.x (Python 2.7.x is preferable) is needed
  - Scons 2.x (Scons 2.3.6 is prederable) is needed: [download](https://sourceforge.net/projects/scons/files/scons/2.3.6/)
- USB Driver (only needed for Windows): [download](https://www.st.com/en/development-tools/stsw-stm32102.html)
  
# Build/Doanload Firmware
First you need add an environment variable `RTT_EXEC_PATH`, and set its value to the compiler's path, e.g, `$path/gcc-arm-none-eabi-7-2018-q2-update-win32\bin`.

Then you can build the firmware. Pixhawk has two chips, **STM32F427** for flight management unit (FMU) and **STM32F103** for input/output (IO). So the firmament firmware is constructed by two file.

## Build FMU Firmware
1. `cd $FMT_Firmware_PATH/fmt_fmu/target/pixhawk`
2. `scons -j4`
3. The firmware `fmt_fmu.bin` will be generated in `build/` folder.

## Download FMU Firmware
There are several ways to download the firmware. The most used 2 ways are:

- Using QGC

  In `Firmware Setup` tab, choose `Advanced Settings` and `Custom firmware file...`. Then choose `fmt_fmu.bin` to flash.

- Using Script

  `cd $FMT_Firmware_PATH/fmt_fmu/target/pixhawk` and execute `python uploader.py`, then the sciprt should automatically detect the serial port and download the firmware.
  
After downloading the firmware, you could open the console via serial (TELEM 2, 57600 by default) or `Mavlink Console` (In QGC).

## Build IO Firmware
1. `cd $FMT_Firmware_PATH/fmt_io/project`
2. `scons -j4`
3. The firmware `fmt_io.bin` will be generated in `build/` folder.

## Download IO Firmware
1. Copy the firmware `fmt_io.bin` to the sd card, e.g, `/fmt_io.bin`.
2. Type `fmtio upload /fmt_io.bin` command in console.
3. It should start to download if you are not the first time to download the io firmware. Otherwise, after you typing the command, you should 
click the io reset button to let it go to the bootloader.

# Code Style
- We use [**astyle**](http://astyle.sourceforge.net/) code beautifier to maintain the consistency of code style. Use following command to format the source code:

*astyle --style=kr --indent=tab --attach-closing-while --indent-switches --indent-preproc-block --break-blocks --pad-oper --unpad-paren --align-pointer=type -r -n "&lt;dir&gt;\\\*.c,\*.h"*


