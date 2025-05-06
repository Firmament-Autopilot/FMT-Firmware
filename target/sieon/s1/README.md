SIEON S1 Flight Controller
============================

The SIEON S1 is an advanced STM32H743 autopilot designed and made by FMT team. 

<div align=center><img src="https://ardupilot.org/copter/_images/Cube_orange_adsb.jpg" width="50%"></div>

## Feature

Main FMU Processor: STM32F743◦32 Bit Arm® Cortex®-M7, 480MHz, 2MB Flash, 512KB RAM

- **On-board sensors:**
  - Accel/Gyro: BMI088
  - Accel/Gyro: ICM-42688
  - Magnetometer: BMM150
  - Barometer: SPL06
- **Interfaces:**
  - Up to 16 PWM outputs(12 standard pwm output + 4 Optional pwm output )
  - R/C input for S.Bus/PPM
  - analog / PWM RSSI input
  - 6 general purpose serial ports
  - 2 GPS ports
  - 3 I2C ports
  - 1 SPI buses (3 chip select pins)
  - 2 CAN Buses
  - 1 ETH port
  - Analog inputs for voltage / current of battery
  - 1 Debug port (Jlink-SWD)
- **Power System:**
  - Power Brick Input: 4.75~5.5V
  - USB Power Input: 4.75~5.25V
  - Servo Rail Input: 0~36V
- **Weight and Dimensions:**
  - Dimensions: 60*40*14mm
- **Other Characteristics:**
  - Operating temperature: -20 ~ 65°c（Measured value）

## Wiki

https://docs.sieon.net/product

## Where to Buy

## Build
Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/sieon/s1
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

1. **Donwload Script**: Enter `python3 uploader.py` in the Cubeorange directory. Then connect your hardware via usb.

```
(fmt) E:\GitRepository\FMT-Firmware\target\cubepilot\cubeorange>python uploader.py
waiting for the bootloader...
Attempting reboot on COM30 with baudrate=57600...
If the board does not respond, unplug and re-plug the USB connector.
Not found fmt_fmu,please connect fmt_fmu!
Not found fmt_fmu,please connect fmt_fmu!
Attempting reboot on COM3 with baudrate=57600...
If the board does not respond, unplug and re-plug the USB connector.
Not found fmt_fmu,please connect fmt_fmu!

Found board id: 140,0 bootloader version: 5 on COM29
sn: 002700493430511030383637
chip: 20036450
family: b'STM32H743/753'
revision: b'V'
flash: 1966080 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 12.231
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
Firmware.....................FMT FW v1.1.0
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target............................SIEON S1
Vehicle........................Multicopter
Airframe.................................1
INS Model..................Base INS v1.0.0
FMS Model..................Base FMS v1.0.0
Control Model.......Base Controller v1.0.0
Task Initialize:
  mavobc................................OK
  mavgcs................................OK
  logger................................OK
  status................................OK
  vehicle...............................OK
```

## Port Mapping

| UART  | Device  | Port     |
| ----- | ------- | -------- |
| UART1 | Serial0 | DEBUG    |
| UART6 | Serial1 | TELEM1   |
| UART2 | Serial2 | TELEM2   |
| UART3 | serial3 | GPS1     |
| UART4 | serial4 | GPS2     |
| UART7 | serial5 | UART/I2C |

| SPI  | Device    | Port    |
| ---- | --------- | ------- |
| SPI2 | spi2_dev1 | SPI CS1 |
| SPI2 | spi2_dev2 | SPI CS2 |
| SPI2 | spi2_dev3 | SPI CS3 |

| I2C  | Device | Port     |
| ---- | ------ | -------- |
| I2C1 | i2c1   | GPS1     |
| I2C2 | i2c2   | GPS2     |
| I2C3 | i2c3   | UART/I2C |

| CAN  | Device | Port |
| ---- | ------ | ---- |
| CAN1 | can1   | CAN1 |
| CAN2 | can2   | CAN2 |

| PWM      | Device   | Port       |
| -------- | -------- | ---------- |
| MAIN OUT | main_out | M1-M12     |
| AUX OUT  | aux_out  | PWM(A1-A4) |

