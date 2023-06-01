CUAV V5+ Minimum System
============================

This is a FMT minimum system for CUAV V5+, which only contains the drivers which is required to make the FMT up and running with the minimum functionality. This minimum system is good reference for other hardware's BSP development.

<div align=center><img src="https://ardupilot.org/copter/_images/v5plus_01.png" width="50%"></div>

## Feature

- **Processor**
  - 32-bit ARM Cortex M7 core with DPFPU
  - 216 Mhz/512 KB RAM/2 MB Flash
  - 32 bit IOMCU co-processor
- **Sensors**
  - InvenSense ICM20689 accelerometer / gyroscope
  - InvenSense ICM20602 : accelerometer / gyroscope
  - Bosch BMI055 accelerometer / gyroscope
  - MS5611 barometer
  - IST8310 magnetometer
- **Power**
  - Operating power: 4.3~5.4V
  - USB Input: 4.75~5.25V
  - High-power servo rail, up to 36V (servo rail does not power the autopilot)
  - Dual voltage and current monitor inputs
  - CUAV v5 Plus can be triple redundant if power is provided to both battery monitor inputs and the USB port
- **Interfaces**
  - 8 - 14 PWM servo outputs (6 IOMCU, 8 FMU)
  - 3 dedicated PWM/Capture inputs on FMU
  - S.Bus servo output
  - PPM connector supports only PPM
  - SBUS/DSM/RSSI connector supports all RC protocols (including SBUS, DSM, ST24, SRXL and PPM)
  - Analog / PWM RSSI input
  - 5x general purpose serial ports
  - 4x I2C ports
  - 4x SPI bus
  - 2x CAN Bus ports
  - 2x analog battery monitor ports
- **Other**
  - Weight: 90g
  - Dimensions: 85.5mm x 42mm x 33mm
  - Operating temperature: -20 ~ 80°c（Measured value）

## Wiki

[CUAV V5 Plus Overview — Copter documentation (ardupilot.org)](https://ardupilot.org/copter/docs/common-cuav-v5plus-overview.html)

## Where to Buy

Order from [here](https://store.cuav.net/index.php). Official retailers are listed [here](https://www.cuav.net/en/resellers/).

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/cuav/v5_plus
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

CUAV V5+ has an io (co-processor) processor onboard. Use the following command to build io firmware.

```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
```

## Download


### Download FMU Firmware
Currently there are 3 ways to download fmu firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the V5+ directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\cuav\v5_plus> python .\uploader.py
waiting for the bootloader...
Error: no serial connection found
wait for connect fmt-fmu...
Error: no serial connection found
wait for connect fmt-fmu...

Found board id: 50,0 bootloader version: 5 on COM3
sn: 0027003a5931500620333539
chip: 10016451
family: b'STM32F7[6|7]x'
revision: b'Z'
flash: 2064384 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 11.289
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
Firmware.....................FMT FW v0.3.0
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target............................CUAV V5+
Vehicle.........................Multicopter
INS Model..................Base INS v0.3.1
FMS Model..................Base FMS v0.4.0
Control Model.......Base Controller v0.2.4
Task Initialize:
  comm..................................OK
  logger................................OK
  fmtio.................................OK
  status................................OK
  vehicle...............................OK
```

### Download IO Firmware

The next step is to upload the io firmware which is downloaded through the fmu. First copy the io firmware `target/pixhawk/fmt-io/project/build/fmt_io.bin` to the on board sd card. You can do that via QGC onboard files page (QGC version 3.5.6 only) or a sd card reader. 

![qgc_download](https://qiniu.md.amovlab.com/img/m/202303/20230305/1820266235233805846609920.png)


Then enter the following command in FMT console to upload the firmware to io processor.

```
msh /usr>fmtio upload /usr/fmt_io.bin
[312785] I/Uploader: sync success
[312793] I/Uploader: found bootloader revision: 5
[312803] I/Uploader: io firmaware:/usr/fmt_io.bin
[312818] I/Uploader: erase...
[314151] I/Uploader: program...
[316275] I/Uploader: CRC check ok, received: 8a27ed4f, expected: 8a27ed4f
```

> For the first time to download the io firmware, you need connect GPS module and hold the safety button to power up, which would lead io processor to stay in bootloader.

## Port Mapping

| UART   | Device  | Port         |
| ------ | ------- | ------------ |
| UART7  | serial0 | DSU7 (DEBUG) |
| USART2 | serial1 | TELEM1       |
| USART3 | serial2 | TELEM2       |
| USART1 | serial3 | GPS          |
| UART4 | serial4 | UART       |

## Maintainer
Josh Zou
zoujiachi666@163.com
