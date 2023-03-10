## Download ICF5 bootloader

To download ICF5 bootloader `fmt_bl_icf5.bin`, please make sure you have JLink connected to ICF5 debug port. Then execute the download script.

- Windows: `./download.bat`
- Linux, Mac: `./download.sh`

```
PS D:\ws\FMT\FMT-Firmware\target\amov\icf5\bootloader> .\download.bat

D:\ws\FMT\FMT-Firmware\target\amov\icf5\bootloader>D:\ProgramFiles\SEGGER\JLink\JLinkGDBServerCL/../JLink.exe -device GD32F470VG -if swd -speed 4000 -commandfile ./download.jlink
SEGGER J-Link Commander V7.84a (Compiled Dec 22 2022 16:13:07)
DLL version V7.84a, compiled Dec 22 2022 16:11:39


J-Link Command File read successfully.
Processing script file...
J-Link>r
J-Link connection not established yet but required for command.
Connecting to J-Link via USB...O.K.
Firmware: J-Link V11 compiled Dec 14 2022 09:09:01
Hardware version: V11.00
J-Link uptime (since boot): 0d 00h 12m 59s
S/N: 261011947
License(s): FlashBP, GDB
OEM: SEGGER-EDU
USB speed mode: High speed (480 MBit/s)
VTref=4.799V
Target connection not established yet but required for command.
Device "GD32F470VG" selected.


Connecting to target via SWD
Found SW-DP with ID 0x2BA01477
DPIDR: 0x2BA01477
CoreSight SoC-400 or earlier
Scanning AP map to find all available APs
AP[1]: Stopped AP scan as end of AP map has been reached
AP[0]: AHB-AP (IDR: 0x24770011)
Iterating through AP map to find AHB-AP to use
AP[0]: Core found
AP[0]: AHB-AP ROM base: 0xE00FF000
CPUID register: 0x410FC241. Implementer code: 0x41 (ARM)
Found Cortex-M4 r0p1, Little endian.
FPUnit: 6 code (BP) slots and 2 literal slots
CoreSight components:
ROMTbl[0] @ E00FF000
[0][0]: E000E000 CID B105E00D PID 000BB00C SCS-M7
[0][1]: E0001000 CID B105E00D PID 003BB002 DWT
[0][2]: E0002000 CID B105E00D PID 002BB003 FPB
[0][3]: E0000000 CID B105E00D PID 003BB001 ITM
[0][4]: E0040000 CID B105900D PID 000BB9A1 TPIU
[0][5]: E0041000 CID 00000000 PID 00000000 ???
Memory zones:
  Zone: Default Description: Default access mode
Cortex-M4 identified.
Reset delay: 0 ms
Reset type NORMAL: Resets core & peripherals via SYSRESETREQ & VECTRESET bit.
Reset: Halt core after reset via DEMCR.VC_CORERESET.
Reset: Reset device via AIRCR.SYSRESETREQ.
J-Link>h
PC = 0800205C, CycleCnt = 00000000
R0 = D0000000, R1 = 40007004, R2 = A0000000, R3 = 40023808
R4 = 20000614, R5 = 2000066C, R6 = 2000066C, R7 = 00000C3A
R8 = 20022520, R9 = 20022524, R10= 20021DC0, R11= 20022940
R12= 20000598
SP(R13)= 20001188, MSP= 20001188, PSP= 200341F8, R14(LR) = FFFFFFFF
XPSR = 01000000: APSR = nzcvq, EPSR = 01000000, IPSR = 000 (NoException)
CFBP = 00000000, CONTROL = 00, FAULTMASK = 00, BASEPRI = 00, PRIMASK = 00

FPS0 = 3EAB5CE1, FPS1 = C02A0000, FPS2 = 00000000, FPS3 = 41F00000
FPS4 = 3331BB4C, FPS5 = 40000000, FPS6 = 3C23D70A, FPS7 = 00000000
FPS8 = 439D1463, FPS9 = 3EAB5CE1, FPS10= 3D5F3CD2, FPS11= 3E7F8953
FPS12= 00000000, FPS13= 00000000, FPS14= 00000000, FPS15= 3D5F3CD2
FPS16= 00000000, FPS17= 00000000, FPS18= 00000000, FPS19= 00000000
FPS20= 3E82C7AA, FPS21= 00000000, FPS22= 00000000, FPS23= 00000000
FPS24= 00000000, FPS25= 00000000, FPS26= 00000000, FPS27= 3F800000
FPS28= 00000000, FPS29= 3F800000, FPS30= 00000000, FPS31= 00000000
FPSCR= 00000000
J-Link>erase 0x08000000锛?x8000
Error while parsing parameter <EAddr>
Syntax: erase [<SAddr>, <EAddr>] [, <noreset | reset>]
J-Link>loadbin ./fmt_bl_icf5.bin 0x08000000
'loadbin': Performing implicit reset & halt of MCU.
Reset: Halt core after reset via DEMCR.VC_CORERESET.
Reset: Reset device via AIRCR.SYSRESETREQ.
Downloading file [./fmt_bl_icf5.bin]...
J-Link: Flash download: Bank 0 @ 0x08000000: Skipped. Contents already match
O.K.
J-Link>qc

Script processing completed.
```

