<p align="center"><img width="200" src="https://github.com/FirmamentPilot/fmt_user_guide_cn/blob/master/figures/logo.png" alt=FMT logo"></p>

<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/license-Apache--2.0-brightgreen" alt="GitHub license" /></a>
</p>

[中文页](README_CN.md) |

Overview
============================
Firmament Autopilot (FMT) is the first open source autopilot based on Model-Based Design (MBD). The FMT project is developed from the [Starry Pilot](https://github.com/JcZou/StarryPilot) open source flight control system, including an embedded flight control system [FMT Firmware](https://github.com/FirmamentPilot/FMT_Firmware) mainly implemented in C language and an algorithm model library with simulation framework [FMT Model](https://github.com/FirmamentPilot/FMT_Model) developed based on Matlab/Simulink .

Based on the FMT platform, the algorithm can be developed and verified more quickly. There is no need to manually write embedded codes anymore. You only need to graphically design the algorithm model in Simulink and then generate C/C++ code with one click. The generated code can be directly incorporated into the flight controller without modifying and writing any embedded code, which greatly improves the efficiency of algorithm development and verification.

Project homepage : https://github.com/FirmamentPilot

## Architecture
FMT Firmware is the embedded part of the FMT autopilot. It adopts a hierarchical design mode, with loose coupling between layers and modules. Its architecture is shown in the figure below.

![fmt_structure](figures/fmt_struct.png)

It specifically includes the following parts:

- Kernel layer: The kernel layer uses the real-time operating system RT-Thread, which provides multithread scheduling, semaphore, mailbox, message queue, memory management, timer, etc. DFS is the virtual file system provided by RT-Thread supporting with standard POSIX interface.
- Driver layer: The driver layer provides hardware driver support, such as IMU, GPS, SD card, USB, etc and communication buses such as I2C, SPI, DMA, etc.
- Hardware Abstraction Layer: HAL provides the unified read/write/control  interfaces for the upper layer. It is convenient to add new device driver or port to different hardware platforms. At the same time, the hardware-independent driver logic can be implemented on the HAL layer, which simplifies the difficulty of driver development.
- Module layer: The module layer provides most of the functions of the system. For example, the uMCN provides IPC functions based on the publish/subscribe model. The log module provides the functions of binary log, text log and boot log. The parameter module provides powerful parameter functions and supports command line/ground station online parameter tuning. And the parameters will also be saved in the log for the simulation model to read.
- Task layer: Each Task is a separate thread (sub-threads can be created internally) to achieve independent functions. For example, the vehicle task will periodically execute **INS**, **FMS** and **Controller** to manipulate the vehicle. 

## Why FMT
Model-based design is a mathematical and visual  method to design complex algprothms or other application in a graphical manner. The manual coding process has its advantages, but its disadvantages are becoming more and more obvious. Especially when the system becomes larger and larger, the function becomes more and more complicated, the algorithm module using handwriting becomes more and more difficult to maintain, and the security and portability of the code will inevitably become worse.

The core algorithm of FMT is developped on the Matlab/Simulink platform and inherits many advantages of the MBD development method, including:

1. Greatly improve the efficiency of algorithm development, saving time and  costs.
2. Reduce errors in the manual coding process and improve system robustness.
3. Greatly improve algorithm optimization and debug efficiency, simplify the system testing and verification procedures.
4. Improve the maintainability and portability of the algorithm.

FMT Firmware is lightweight, easy to read and use, as well as excellent stability and real-time performance. In summary, the features of FMT Firmware include:

- A lightweight flight control system written in C language, easier to use and  secondary development.
- Cross-platform development tool chain, supporting Windows/Linux/Mac OS.
- Support MBD develop method, greatly improving the efficiency of development and testing.
- Support the most popular open source flight control hardware.
- Excellent real-time performance with time error < 1us.
- Higher execution efficiency and lower CPU usage. Provide more space to improve the algorithm complexity and higher execution frequency.
- Support Mavlink V1.0/V2.0 and  ground station QGC, Mission Planner, etc.
- Support hardware-in-the-loop simulation (HIl/SIH).
- Highly modular, loosely coupled software architecture, easy to tailor and port to other hardware.

## Supported Hardware
- **Pixhawk**: version 2.4.6 or 2.4.8.
-  May support more hardwares in future. 

## Documentation
[User Guide (CN)](https://github.com/FirmamentPilot/fmt_user_guide_cn)

## Develop Environment
The following toolchain are needed for development.

- Compiler: arm-none-eabi- toolchain (recommend: `7-2018-q2-update`，other version are not well tested). [download](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- Construction tool: Scons
  - Python 2.x (Python 2.7.x is preferable) is needed
  - Scons 2.x (Scons 2.3.6 is prederable) is needed: [download](https://sourceforge.net/projects/scons/files/scons/2.3.6/)
- USB Driver (only needed for Windows): [download](https://www.st.com/en/development-tools/stsw-stm32102.html)
  
## Build & Doanload Firmware
Please refer to the user guide.

## Contributor
Big thanks to these contributor:
- [weety](https://github.com/weety)
- [yangjiong](https://github.com/yangjion)

