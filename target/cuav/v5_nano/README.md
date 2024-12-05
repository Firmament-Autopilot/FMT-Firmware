CUAV V5+ Flight Controller
============================

V5 nano is an autopilot for space-constrained applications manufactured by CUAV®. It is based on the Pixhawk FMUv5 design standard and is compatible with PX4 firmware and ArduPilot firmware. The autopilot combines small size with powerful features, and can be used not only in ordinary drones, but also 220mm racing drones and other space limited vehicles. The Carrier Board design reference is [here](https://github.com/cuav/hardware/tree/master/V5_Autopilot/V5_NANO)

<div align=center><img src="https://www.cuav.net/wp-content/uploads/2019/09/nono05.png" width="50%"></div>



## Feature

Main FMU Processor: STM32F765◦32 Bit Arm® Cortex®-M7, 216MHz, 2MB memory, 512KB RAM

- **On-board sensors:**
  - Accel/Gyro: ICM-20689
  - Accel/Gyro: ICM-20602
  - Accel/Gyro: BMI055
  - Magnetometer: IST8310
  - Barometer: MS5611
- **Interfaces:**
  - Up to 11 PWM outputs(8 standard pwm output +3 Optional pwm output )*
  - 3 dedicated PWM/Capture inputs on FMU*
  - 1 nARMED
  - Dedicated R/C input for CPPM
  - Dedicated R/C input for Spektrum / DSM and S.Bus
  - analog / PWM RSSI input
  - 4 general purpose serial ports
  - 4 I2C ports
  - 4 SPI buses
  - 2 CANBuses
  - Analog inputs for voltage / current of battery
  - 2 additional analog input
- **Power System:**
  - Power Brick Input: 4.75~5.5V
  - USB Power Input: 4.75~5.25V
  - Servo Rail Input: 0~36V
- **Weight and Dimensions:**
  - Dimensions: 60*40*14mm
- **Other Characteristics:**
  - Operating temperature: -20 ~ 85°c（Measured value）

## Wiki

[V5 nano · cuav-v5](https://doc.cuav.net/controller/v5-autopilot/en/v5-nano.html)

## Where to Buy

[CUAV Store](https://store.cuav.net/shop/v5-nano/)

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/cuav/v5_nano
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

1. **Donwload Script**: Enter `python3 uploader.py` in the V5+ directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\cuav\v5_nano> python.exe .\uploader.py
waiting for the bootloader...
Attempting reboot on COM31 with baudrate=57600...
If the board does not respond, unplug and re-plug the USB connector.

Found board id: 50,0 bootloader version: 5 on COM6
sn: 0023003f3033511236323635
chip: 10016451
family: b'STM32F7[6|7]x'
revision: b'Z'
flash: 2064384 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 11.949
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
Target........................CUAV V5-Nano
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
| UART7  | serial0 | DSU7 (DEBUG&UART7) |
| USART2 | serial1 | TELEM1       |
| USART3 | serial2 | TELEM2       |
| USART1 | serial3 | GPS          |
| UART4 | serial4 | UART       |

| SPI   | Device  | Port         |
| ------ | ------- | ------------ |
| SPI1  | spi1 | Internal |
| SPI2 | spi2 | Internal       |

| I2C   | Device  | Port         |
| ------ | ------- | ------------ |
| I2C1  | i2c1 | GPS |
| I2C2  | i2c2 | I2C2 |
| I2C3  | i2c3 | I2C3 |
| I2C4  | i2c4 | I2C4 |

| CAN   | Device  | Port         |
| ------ | ------- | ------------ |
| CAN1  | can1 | CAN1 |
| CAN2  | can2 | CAN2 |

## Maintainer
Josh Zou zoujiachi666@163.com
