mavlink_shell.py使用方法
============================



## 环境要求

- python3.8及以上版本
- pymavlink pyserial

## 使用方法

```
PS E:\vshare\FirmamentPilot\yangjian\FMT-Firmware\target\amov\icf5> python.exe .\mavlink_shell.py COM8
msvcrt
Connecting to MAVLINK...

msh />
msh />
msh />ls
sys/  usr/  log/  mnt/
msh />ps
thread      pri  status      sp     stack size max used left tick  error cpu
----------- ---  ------- ---------- ----------  ------  ---------- ---   -----
mav_rx       11  suspend 0x000004c0 0x00001000    29%   0x00000003 000   0.01%
logger       10  suspend 0x00000118 0x00000800    13%   0x00000001 000   0.06%
vehicle       3  suspend 0x00000138 0x00001400    18%   0x00000001 000   16.44%
status       13  suspend 0x000003b8 0x00001000    25%   0x00000001 000   0.14%
comm         12  suspend 0x00000124 0x00002000    13%   0x00000001 000   2.49%
offboard     25  init    0x00000048 0x00000400    07%   0x00000001 000   0.00%
local        25  init    0x00000044 0x00000400    06%   0x00000001 000   0.00%
tshell       20  running 0x000005b4 0x00001000    39%   0x00000009 000   0.06%
mtf-01        7  suspend 0x00000134 0x00002000    03%   0x00000001 000   0.09%
wq:hp_work    6  suspend 0x000000e0 0x00001400    04%   0x0000000a 000   0.00%
wq:lp_work   19  suspend 0x000000f4 0x00001400    05%   0x0000000a 000   0.05%
tidle0       31  ready   0x00000054 0x00000400    09%   0x0000000e 000   80.67%
timer         5  suspend 0x000000f4 0x00000400    23%   0x0000000a 000   0.00%
msh />
msh />
```
