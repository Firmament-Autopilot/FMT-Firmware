Cubepilot Cubeorange Flight Controller
============================

The Cubepilot Cubeorange is an advanced STM32H743 autopilot designed and made by Cubepilot. It is a variant of the Cubeorange, updated to use Pixhawk standard pinouts. The Cubeorange reference document is [here](https://docs.cubepilot.org/user-guides/autopilot/the-cube-module-overview)

<div align=center><img src="https://ardupilot.org/copter/_images/Cube_orange_adsb.jpg" width="50%"></div>

## Feature

- **Processor**
  - 32-bit ARM Cortex M7 core with DPFPU
  - 480 Mhz/1 MB RAM/2 MB Flash
  - 32 bit IOMCU co-processor
- **Sensors**
  - InvenSense 20948 accelerometer / gyroscope / magnetometer
  - MS5611 barometer
- **Power**
  - Operating power: 4.3~5.4V
  - USB Input: 4.75~5.25V
  - High-power servo rail, up to 36V (servo rail does not power the autopilot)
  - Dual voltage and current monitor inputs
  - CUAV v5 Plus can be triple redundant if power is provided to both battery monitor inputs and the USB port
- **Interfaces**
  - 6 - 12 PWM servo outputs (6 IOMCU, 6 FMU)
  - S.Bus servo output
  - PPM connector supports only PPM
  - SBUS/DSM/RSSI connector supports all RC protocols (including SBUS, DSM, ST24, SRXL and PPM)
  - Analog / PWM RSSI input
  - 4x general purpose serial ports
  - 1x I2C ports
  - 2x CAN Bus ports
  - 2x analog battery monitor ports

## Wiki

[Cubepilot Cubeorange Overview — Copter documentation (ardupilot.org)](https://docs.cubepilot.org/user-guides/autopilot/the-cube-module-overview)

## Where to Buy


## Enivronment
Cubepilot used dronecan, so you should install the python packages:  

```
pip install empy
pip install pexpect
pip install dronecan
```

## Build
Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/cubepilot/cubeorange
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

Cubepilot Cubeorange has an io (co-processor) processor onboard. Use the following command to build io firmware.

```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
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
Firmware.....................FMT FW v0.5.2
Kernel....................RT-Thread v4.0.3
RAM.................................512 KB
Target................Cubepilot Cubeorange
Vehicle........................Multicopter
Airframe.................................1
INS Model..................Base INS v0.3.2
FMS Model..................Base FMS v0.4.0
Control Model.......Base Controller v0.2.4
Task Initialize:
  mavobc................................OK
  mavgcs................................OK
  logger................................OK
  fmtio.................................OK
  status................................OK
  vehicle...............................OK
  dronecan..............................OK
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

| UART   | Device  | Port          |
| ------ | ------- | ------------  |
| UART2  | Serial0 | TELEM1(DEBUG) |
| UART3  | Serial1 | TELEM2        |
| UART4  | Serial2 | GPS1          |
| UART8  | serial3 | GPS2          |
| UART7  | serial4 | HAL           |
| UART6  | serial5 | FMTIO         |
