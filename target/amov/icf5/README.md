AMOV ICF5 Flight Controller
============================

ICF5 is a professional open-source autopilot hardware created by FMT teams and AMOVLAB. ICF5 is equipped with the latest FMT stable firmware and can be applied to various robotics application scenarios.

FMT is a next-generation open source autopilot system which supports Model-based-design (MBD). Use MATLAB/Simulink to quickly build algorithm models graphically, and one-click to generate C/C++ code which can be easily deployed to ICF5. Using FMT can greatly improves the development  efficiency and make R&D much easier. ICF is an ideal platform for algorithm and prototype verification.

<div align=center><img src="https://qiniu.md.amovlab.com/img/m/202303/20230304/0949205159518958801485824.jpg" width="30%"></div>

## Feature

- FMU Processor: 
  - 32 Bit Arm® Cortex®-M4, 240MHz, 1MB memory, 512KB RAM
- On-board sensors:
  - IMU: BMI088/ICM-42688-P/ICM-20948
  - Magnetometer: BMM150/ICM-20948
  - Barometer: SPL06-001/MS5611
- Interfaces:
  - 10 PWM outputs
  - Dedicated R/C input for PPM and SBUS
  - 1 GPS integrated with safety switch and buzzer interface
  - 5 general purpose serial ports
  - 3 I2C ports
  - 1 SPI buses
  - 1 CAN Buses
  - 1 ETH
  - 1 Type-C USB
- Power System:
  - Power module output: 4.9~5.5V
  - USB Power Input: 4.75~5.25V
  - Servo Rail Input: 0~36V
- Weight and Dimensions:
  - Weight: 39.3g
  - Dimensions: 70x36x18.5mm
- Other Characteristics:
  - Operating temperature: -20 ~ 85°c

## Wiki

https://wiki.amovlab.com/public/icf5-wiki/

## Where to Buy
https://item.taobao.com/item.htm?spm=a230r.1.14.60.284211f8srcCoe&id=705459383848&ns=1&abbucket=12#detail

## Build

Build firmware for quadcopter

```
cd FMT-Firmware/taget/amov/icf5
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

## Download

Currently there are 2 ways to download firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the icf5 directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\amov\icf5> python .\uploader.py
waiting for the bootloader...
Error: no serial connection found
wait for connect fmt-fmu...
Error: no serial connection found
wait for connect fmt-fmu...

Found board id: 50,0 bootloader version: 5 on COM7
sn: 000000000000000000000000
chip: 22020419
family: b'GD32F4[5|7]x'
revision: b'?'
flash: 1015808 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 9.687
```

> If the `"ModuleNotFoundError: No module named 'serial'"` error occurs, indicating that the **pyserial** component is missing, enter `pip3 install pyserial` to install.

2. **J-Link**: If you have a JLink, you can connect it to board debug port download the firmware. For more information, please check the [Debug](https://firmament-autopilot.github.io/FMT-DOCS/#/introduction/debug) section.

> Be careful do not override the bootloader!

When system is up and running, the system banner is output via serial0 or you can view it by entering `boot_log` in QGC Mavlink Console.

```
-----------FMT Bootloader v1.x-----------
Board Type:         50
Board Revision:     0
Board Flash Size:   1015808
App Load Address:   0x8010000

   _____                               __
  / __(_)_____ _  ___ ___ _  ___ ___  / /_
 / _// / __/  ' \/ _ `/  ' \/ -_) _ \/ __/
/_/ /_/_/ /_/_/_/\_,_/_/_/_/\__/_//_/\__/
Firmware.....................FMT FW v0.3.0
Kernel....................RT-Thread v4.0.3
RAM.................................448 KB
Target...........................Amov-ICF5
Vehicle.........................Multicopter
INS Model..................Base INS v0.3.1
FMS Model..................Base FMS v0.4.0
Control Model.......Base Controller v0.2.4
Task Initialize:
  local.................................OK
  offboard..............................OK
  comm..................................OK
  logger................................OK
  status................................OK
  vehicle...............................OK
```



## Port Mapping

|  UART   | Device  | Port |
|  ----   | ------  | ---- |
|  UART6 | serial0 | DEBUG |
|  USART1 | serial1 | TELEM1 |
|  USART2 | serial2 | TELEM2 |
|  USART0  | serial3 | UART |
|  UART7 | serial4 | GPS |

|  SPI   | Device  | Port |
|  ----   | ------  | ---- |
|  SPI1 | spi1_dev3 | SPI CS1 |
|  SPI1 | spi1_dev4 | SPI CS2 |

|  I2C   | Device  | Port |
|  ----   | ------  | ---- |
|  I2C0 | / | I2C |

## Maintainer
Josh Zou
zoujiachi666@163.com
