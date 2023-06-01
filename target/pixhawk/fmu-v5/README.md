Pixhawk4 Flight Controller
============================

*Pixhawk 4*® is an advanced autopilot designed and made in collaboration with Holybro® and the PX4 team. It is suitable for academic and commercial developers.

<div align=center><img src="https://tse4-mm.cn.bing.net/th/id/OIP-C.TdVj2xYg1mjgMnlnN-01GgHaEK?pid=ImgDet&rs=1" width="50%"></div>

## Feature

- Main FMU Processor: STM32F765
  - 32 Bit Arm® Cortex®-M7, 216MHz, 2MB memory, 512KB RAM
- IO Processor: STM32F100
  - 32 Bit Arm® Cortex®-M3, 24MHz, 8KB SRAM
- On-board sensors:
  - Accel/Gyro: ICM-20689
  - Accel/Gyro: BMI055 or ICM20602
  - Magnetometer: IST8310
  - Barometer: MS5611
- GPS: u-blox Neo-M8N GPS/GLONASS receiver; integrated magnetometer IST8310
- Interfaces:
  - 8-16 PWM outputs (8 from IO, 8 from FMU)
  - 3 dedicated PWM/Capture inputs on FMU
  - Dedicated R/C input for CPPM
  - Dedicated R/C input for Spektrum / DSM and S.Bus with analog / PWM RSSI input
  - Dedicated S.Bus servo output
  - 5 general purpose serial ports
  - 3 I2C ports
  - 4 SPI buses
  - Up to 2 CANBuses for dual CAN with serial ESC
  - Analog inputs for voltage / current of 2 batteries
- Power System:
  - Power module output: 4.9~5.5V
  - USB Power Input: 4.75~5.25V
  - Servo Rail Input: 0~36V
- Weight and Dimensions:
  - Weight: 15.8g
  - Dimensions: 44x84x12mm
- Other Characteristics:
  - Operating temperature: -40 ~ 85°c

Additional information can be found in the [Pixhawk 4 Technical Data Sheet](https://github.com/PX4/PX4-user_guide/raw/main/assets/flight_controller/pixhawk4/pixhawk4_technical_data_sheet.pdf)

## Wiki

[Pixhawk 4 | PX4 User Guide](https://docs.px4.io/main/en/flight_controller/pixhawk4.html)

## Where to Buy

Order from [Holybro](https://shop.holybro.com/pixhawk-4beta-launch_p1089.html)

## Build

Build fmu firmware for quadcopter

```
cd FMT-Firmware/taget/pixhawk/fmu-v5
scons -j4
```

> -jN allows N jobs at once which makes your build process quicker.

For other vehicle, such as fixwing, using

```
scons -j4 --vehicle=Fixwing
```

Pixhawk4 has an io (co-processor) processor onboard. Use the following command to build io firmware.

```
cd FMT-Firmware/target/pixhawk/fmt-io/project
scons -j4
```

## Download


### Download FMU Firmware

Currently there are 3 ways to download fmu firmware to hardware.

1. **Donwload Script**: Enter `python3 uploader.py` in the Pixhawk4 directory. Then connect your hardware via usb.

```
PS D:\ws\FMT\FMT-Firmware\target\pixhawk\fmu-v5> python .\uploader.py
waiting for the bootloader...
Error: no serial connection found
wait for connect fmt-fmu...
Error: no serial connection found
wait for connect fmt-fmu...
Error: no serial connection found
wait for connect fmt-fmu...

Found board id: 50,0 bootloader version: 5 on COM3
sn: 0021001c3438510636363539
chip: 10016451
family: b'STM32F7[6|7]x'
revision: b'Z'
flash: 2064384 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 8.850
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
Target......................Pixhawk4 FMUv5
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

> For the first time to download the io firmware, you need click the io reset button on the side after entering fmtio command to let io processor reboot and enter bootloader.

## Port Mapping

| UART   | Device  | Port      |
| ------ | ------- | --------- |
| UART7  | serial0 | FMU Debug |
| USART2 | serial1 | TELEM1    |
| USART3 | serial2 | TELEM2    |
| USART1 | serial3 | GPS       |
| UART4 | serial4 | UART       |

## Maintainer
Josh Zou
zoujiachi666@163.com
