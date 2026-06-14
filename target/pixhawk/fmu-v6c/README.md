Pixhawk 6C Flight Controller
============================

The Pixhawk 6C is a high-performance STM32H743 autopilot designed and manufactured by Holybro, based on the Pixhawk FMUv6C Open Standard.

## Feature

Main FMU Processor: STM32H743 -- 32 Bit Arm® Cortex®-M7, 480MHz, 2MB Flash, 1MB SRAM

IO Processor: STM32F103 -- 32 Bit Arm® Cortex®-M3, 72MHz, 64KB SRAM

- **On-board sensors:**
  - Accel/Gyro: ICM-42688-P
  - Accel/Gyro: BMI088
  - Magnetometer: IST8310
  - Barometer: MS5611
- **Interfaces:**
  - 16 PWM servo outputs (8 from IO, 8 from FMU) with hardware switchable 3.3V/5V signal mode
  - R/C input for S.Bus/PPM/DSM
  - Dedicated S.BUS output
  - 3 general purpose serial ports (Telem1/2/3)
  - 2 GPS ports
  - 1 I2C port
  - 2 CAN Buses (FDCAN)
  - 2 Debug ports (FMU Debug, I/O Debug)
  - USB port
  - Analog inputs for voltage / current of battery (2 Power input ports)
- **Power System:**
  - Max input voltage: 6V
  - USB Power Input: 4.75~5.25V
  - Servo Rail Input: 0~36V
  - Telem1 Max output current: 1.5A
  - All other ports combined output current: 1.5A
- **Weight and Dimensions:**
  - Dimensions: 84.8mm * 44mm * 12.4mm
  - Weight: 59.3g (Aluminum Case) / 34.6g (Plastic Case)
- **Other Characteristics:**
  - Operating temperature: -40 ~ 85°C

## Wiki

https://docs.holybro.com/autopilot/pixhawk-6c

## Where to Buy

[Holybro Shop](https://holybro.com/products/pixhawk-6c?variant=43018722771133)

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/target/pixhawk/fmu-v6c
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

1. **Download Script**: Enter `python3 uploader.py` in the fmu-v6c directory. Then connect your hardware via usb.

```
(fmt) E:\FMT-Firmware\target\pixhawk\fmu-v6c>python .\uploader.py
waiting for the bootloader...
Auto-detected serial ports are:
Initial ports detected: COM10, COM11, COM3, COM4
Waiting for new device (bootloader)...

New device detected on: COM5

Found board id: 56,0 bootloader version: 5 on COM5
sn: 002f002d3133510e31343630
chip: 20036450
family: b'STM32H7[4|5]x'
revision: b'V'
flash: 1966080 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 18.874
```

> If the `"ModuleNotFoundError: No module named 'serial'"` error occurs, indicating that the **pyserial** component is missing, enter `pip3 install pyserial` to install.

2. **QGC**: Go to *Firmware Setup* page, then connect your hardware to PC with a usb cable. In pop-up dialog, select *Advanced Settings->Custom firmware file* with FMT firmware to download.

   ![qgc_download](https://firmament-autopilot.github.io/FMT-DOCS/figures/qgc_download.png)

3. **J-Link**: If you have a JLink, you can connect it to board debug port download the firmware. For more information, please check the [Debug](https://firmament-autopilot.github.io/FMT-DOCS/#/introduction/debug) section.

> Be careful do not override the bootloader!

When system is up and running, the system banner is output via serial0 or you can view it by entering `boot_log` in QGC Mavlink Console.

```
   _____                               __ 
  / __(_)_____ _  ___ ___ _  ___ ___  / /_
 / _// / __/  ' \/ _ `/  ' \/ -_) _ \/ __/
/_/ /_/_/ /_/_/_/\_,_/_/_/_/\__/_//_/\__/ 
Firmware.....................FMT FW v1.1.3
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target..........................Pixhawk 6C
Vehicle........................Multicopter
Airframe.................................1
Task Initialize:
  mavobc................................OK
  mavgcs................................OK
  logger................................OK
  fmtio.................................OK
  status................................OK
  vehicle...............................OK
```

## Port Mapping

| UART  | Device  | Port     |
| ----- | ------- | -------- |
| UART3 | serial0 | DEBUG    |
| UART7 | serial1 | TELEM1   |
| UART1 | serial2 | GPS1     |
| UART8 | serial3 | GPS2     |
| UART5 | serial4 | TELEM2   |
| UART6 | serial5 | FMU/IO   |
| UART2 | serial6 | TELEM3   |

| SPI  | Device    | Port    |
| ---- | --------- | ------- |
| SPI1 | spi1_dev1 | BMI088 Accel |
| SPI1 | spi1_dev2 | BMI088 Gyro  |
| SPI1 | spi1_dev3 | ICM-42688-P  |
| SPI2 | spi2_dev1 | FRAM         |

| I2C  | Device | Port     |
| ---- | ------ | -------- |
| I2C1 | i2c1   | External |
| I2C2 | i2c2   | External |
| I2C4 | i2c4   | Internal |

| CAN  | Device | Port |
| ---- | ------ | ---- |
| CAN1 | can1   | CAN1 |
| CAN2 | can2   | CAN2 |

| PWM      | Device   | Port       |
| -------- | -------- | ---------- |
| MAIN OUT | main_out | M1-M8      |
| AUX OUT  | aux_out  | A1-A8      |

## Maintainer
Pan Chenliang, panchenliang@nuaa.edu.cn
