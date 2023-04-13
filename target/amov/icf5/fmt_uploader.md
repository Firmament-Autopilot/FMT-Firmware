FMT_Uploader.exe使用方法
============================



## 使用方法

- 在控制台下直接运行FMT_Uploader.exe即可自动更新程序，注意目录下需要有固件 build/fmt_amov-icf5.bin
- 快捷键CTL+C 退出脚本



```
PS E:\vshare\FirmamentPilot\yangjian\FMT-Firmware\target\amov\icf5> .\FMT_Uploader.exe

============================================================================
FMT Uploader
Email: yangjian1631@163.com
Help: Copy fmt_amov-icf5.bin to FMT_Uploader floader/build,the firmware will auto be upload
============================================================================

Start check usb connect...

Press Enter continue

Found board id: 50,0 bootloader version: 5 on COM8
WARNING: Firmware not suitable for this board (Firmware board_type=50 board_id=9)
FORCED WRITE, FLASHING ANYWAY!
sn: 000000000000000000000000
chip: 22020419
family: b'GD32F4[5|7]x'
revision: b'?'
flash: 1015808 bytes
Windowed mode: False

Erase  : [====================] 100.0%
Program: [====================] 100.0%
Verify : [====================] 100.0%
Rebooting. Elapsed Time 7.246


 Upload aborted by user.
PS E:\vshare\FirmamentPilot\yangjian\FMT-Firmware\target\amov\icf5>
```
