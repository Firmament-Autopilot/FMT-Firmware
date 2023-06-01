Pixhawk2.4.6 Flight Controller
============================

The *3DR Pixhawk® 1* autopilot is a popular general purpose flight controller based on the [Pixhawk-project (opens new window)](https://pixhawk.org/)**FMUv2** open hardware design (it combines the functionality of the PX4FMU + PX4IO).

<div align=center><img src="https://docs.px4.io/main/assets/img/hardware-pixhawk.06e032bf.png" width="60%"></div>

## Feature

- Main System-on-Chip: STM32F427

  - CPU: 180 MHz ARM® Cortex® M4 with single-precision FPU
  - RAM: 256 KB SRAM (L1)

- Failsafe System-on-Chip: STM32F100

  - CPU: 24 MHz ARM Cortex M3
  - RAM: 8 KB SRAM

- Wifi: ESP8266 external

- GPS: u-blox® 7/8 (Hobbyking®) / u-blox 6 (3D Robotics)

- Redundant power supply inputs and automatic failover

- External safety switch

- Multicolor LED main visual indicator

- High-power, multi-tone piezo audio indicator

- microSD card for high-rate logging over extended periods of time

Connectivity

- 1x I2C
- 1x CAN (2x optional)
- 1x ADC
- 4x UART (2x with flow control)
- 1x Console
- 8x PWM with manual override
- 6x PWM / GPIO / PWM input
- S.BUS / PPM / Spektrum input
- S.BUS output

## Wiki

[3DR Pixhawk 1 Flight Controller (Discontinued) | PX4 User Guide](https://docs.px4.io/main/en/flight_controller/pixhawk.html)

## Where to Buy

Discontinued in 2016.

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/pixhawk/fmu-v2
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

Pixhawk2.4.6 has an io (co-processor) processor onboard. Use the following command to build io firmware.

```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
```

## Download


### Download FMU Firmware

Currently there are 3 ways to download fmu firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the Pixhawk4 directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\pixhawk\fmu-v2> python .\uploader.py
waiting for the bootloader...
Error: no serial connection found
wait for connect fmt-fmu...

Found board id: 9,0 bootloader version: 4 on COM11
sn: 0038001f3432470d31323533
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 11.865
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
RAM.................................192 KB
Target.......................Pixhawk FMUv2
Vehicle.........................Multicopter
INS Model..................Base INS v0.3.1
FMS Model..................Base FMS v0.4.0
Control Model.......Base Controller v0.2.4
Task Initialize:
  vehicle...............................OK
  comm..................................OK
  logger................................OK
  fmtio.................................OK
  status................................OK
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

> For the first time to download the io firmware, you need click the io reset button on the side after entering fmtio command to let io processor reboot and enter bootloader.

## Port Mapping

| UART   | Device  | Port     |
| ------ | ------- | -------- |
| USART3 | serial0 | TELEM2   |
| USART2 | serial1 | TELEM1   |
| UART4  | serial2 | GPS      |
| UART8  | serial3 | SERIAL 4 |
| UART8  | serial4 | SERIAL 5 |

## Maintainer
Josh Zou
zoujiachi666@163.com
