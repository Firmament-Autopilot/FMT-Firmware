CUAV 7-Nano Flight Controller
============================

7-Nano is a micro autopilot developed for miniaturized unmanned system equipment. It is independently developed and produced by CUAV. It innovatively adopts a stacked design and integrates a high-performance STM32H7 processor, dual redundant industrial-grade IMU and rich and complete expansion interfaces in a very small space; it supports Ethernet communication The interface can realize the low-latency and large-bandwidth real-time communication requirements of various components of the autopilot and unmanned system equipment. 

<div align=center><img src="https://github.com/user-attachments/assets/cb447db7-3fd3-4d75-9059-fdacf84785fd" width="50%"></div>

## Feature

**7-Nano**
- STM32H753 microcontroller
- 2 IMUs: IIM42652 and BMI088
- builtin IST8310 magnetometer
- 2 barometers: BMP581 and ICP20100
- microSD card slot
- USB-TypeC port
- 1 ETH network interface
- 5 UARTs plus USB
- 14 PWM outputs
- 3 I2C ports
- 2 CAN ports (two of which share a CAN bus and one is an independent CAN bus)
- Analog RSSI input
- 3.3V/5V configurable PWM ouput voltage
- Power System:
  - Power: 4.5~5.4V
  - USB Input: 4.75~5.25V
  - Servo Rail Input: 0~10V
  - 4.5 ~ 5.5V Operating Voltage
- Weight and Dimensions:
  - Weight: 33.8g
- Operating temperature
  - -20 ~ 85°c
  
**7-Nano PDB**

- Operating Voltage：12-70V
- Detection current(MAX):79.2A
- Bec out:5.3V/4A
- Voltage and current accuracy:±0.2V/0.5A
- Splitter:Divided into six
- Sport:XT60/GH1.25 6Pin
- Weight：17g

## Wiki

[7-nano](https://doc.cuav.net/controller/7-nano/en/#Optional-hardware)


## Where to Buy

[CUAV Store](https://store.cuav.net/)

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/cuav/7_nano
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

## Download


### Download FMU Firmware
Currently there are 3 ways to download fmu firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the BSP directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\cuav\7_nano> python.exe .\uploader.py
waiting for the bootloader...
Attempting reboot on COM72 with baudrate=57600...
If the board does not respond, unplug and re-plug the USB connector.

Found board id: 7000,0 bootloader version: 5 on COM72
sn: 6828e780d4f5008030184823
chip: 00000000
family: b'STM32H??????'
revision: b'?'
flash: 1966080 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 12.291
```

> If the `"ModuleNotFoundError: No module named 'serial'"` error occurs, indicating that the **pyserial** component is missing, enter `pip3 install pyserial` to install.

2. **QGC**: Go to *Firmware Setup* page，then connect your hardware to PC with a usb cable. In pop-up diaglog，select *Advanced Settings->Custom firmware file* with FMT firmware to download.

   ![qgc_download](https://firmament-autopilot.github.io/FMT-DOCS/figures/qgc_download.png)

3. **J-Link**: If you have a JLink, you can connect it to board debug port download the firmware. For more information, please check the [Debug](https://firmament-autopilot.github.io/FMT-DOCS/#/introduction/debug) section.

> Be careful do not override the bootloader!

When system is up and running, the system banner is output via serial0 or you can view it by entering `boot_log` in QGC Mavlink Console.

```
   _____                               __
  / __(_)_____ _  ___ ___ _  ___ ___  / /_
 / _// / __/  ' \/ _ `/  ' \/ -_) _ \/ __/
/_/ /_/_/ /_/_/_/\_,_/_/_/_/\__/_//_/\__/
Firmware.....................FMT FW v1.0.0
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target.........................CUAV 7-Nano
Vehicle........................Multicopter
Airframe.................................1
INS Model....................CF INS v1.0.0
FMS Model....................MC FMS v1.0.0
Control Model.........MC Controller v1.0.0
Task Initialize:
  mavobc................................OK
  mavgcs................................OK
  logger................................OK
  status................................OK
  vehicle...............................OK

```

## Port Mapping

| UART   | Device  | Port         |
| ------ | ------- | ------------ |
| UART3  | serial0 | DEBUG |
| UART7 | serial1 | TELEM1       |
| UART5 | serial2 | TELEM2       |
| UART1 | serial3 | GPS          |
| UART8 | serial4 | GPS2       |

| CAN   | Device  | Port         |
| ------ | ------- | ------------ |
| CAN1  | can1 | CAN1 |
| CAN2  | can2 | CAN2 |

| PWM   | Device  | Port         |
| ------ | ------- | ------------ |
| MAIN OUT  | main_out | M1-M14 |

## Maintainer
Josh Zou zoujiachi666@163.com
