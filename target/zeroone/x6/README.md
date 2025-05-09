ZeroOne X6 Flight Controller
============================

The ZeroOne X6 is a flight controller manufactured by ZeroOne, which is based on the open-source FMU v6X architecture and Pixhawk Autopilot Bus open source specifications.

<div align=center><img src="https://ardupilot.org/plane/_images/ZeroOneX6.png" width="30%"></div>

## Features:

- Separate flight control core design.
- MCU
  STM32H753IIK6 32-bit processor running at 480MHz
  2MB Flash
  1MB RAM
- Sensors
- IMU:
  Internal Vibration Isolation for IMUs
  IMU constant temperature heating(1 W heating power).
  With Triple Synced IMUs, BalancedGyro technology, low noise and more shock-resistant:
  IMU1-ICM45686(With vibration isolation)
  IMU2-BMI088(With vibration isolation)
  IMU3- ICM45686(No vibration isolation)
- Baro:
  Two barometers:2 x ICP20100
  Magnetometer: Builtin RM3100 magnetometer

## Wiki

[X6飞控Readme-零一飞行文档中心](https://docs.01aero.cn/docs/X6_readme)

## Where to Buy

[零一X6开源飞控-淘宝网](https://item.taobao.com/item.htm?abbucket=11&detail_redpacket_pop=true&id=790973866451&ltk2=1746782887151tc8x6ek228s4847eip8xj&ns=1&priceTId=undefined&query=零一飞控&skuId=5780533500698&spm=a21n57.1.hoverItem.2&utparam={"aplus_abtest"%3A"4997d1bb11d5dfa1e801f6a4bf97e79d"}&xxc=taobaoSearch)

## Build
Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/zeroone/x6
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

X6 has an io (co-processor) processor onboard. Use the following command to build io firmware.

```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
```

## Download

### Download FMU Firmware
Currently there are 3 ways to download fmu firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the Cubeorange directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\zeroone\x6> python.exe .\uploader.py
Attempting reboot on COM22 with baudrate=57600...
If the board does not respond, unplug and re-plug the USB connector.

Found board id: 7000,0 bootloader version: 5 on COM22
sn: 6828e780d4f5008030184823
chip: 00000000
family: b'STM32H??????'
revision: b'?'
flash: 1966080 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 12.948
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
