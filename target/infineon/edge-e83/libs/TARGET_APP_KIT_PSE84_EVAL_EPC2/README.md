# KIT_PSE84_EVAL_EPC2 BSP

## Overview

The PSOC™ Edge E84 Evaluation Kit (KIT\_PSE84\_EVAL) is based on the PSOC™ Edge family of devices. It enables the evaluation and development of applications for the PSOC™ Edge E84 EPC2 MCU.




To use code from the BSP, simply include a reference to `cybsp.h`.

## Features
This evaluation kit carries a PSOC™ E84 EPC2 MCU (PSE846GPS2DBZC4A) on a SODIMM based detachable SOM board connected to the base\-board. The MCU SOM also has 128 Mb QSPI flash, 1 Gb Octal flash, 128 Mb Octal RAM, PSOC™ 4000T as CAPSENSE™ co\-processor and on\-board AIROC™ Wi\-Fi and Bluetooth® combo (CYW55513IUBG).

The base\-board has M.2 interface connectors for interfacing external radio modules based on AIROC™ Wi\-Fi and Bluetooth® combos and external memory interfaces. The base\-board features an on\-board programmer/debugger(KitProg3\), ETM/JTAG/SWD debug headers, custom display capacitive touch panel connector, R\-Pi compatible MIPI\-DSI and MIPI\-DSI custom display, Analog and PDM microphones, Headphone connector, Speaker, USB Host Type\-A and USB device Type\-C connectors, RJ45 Ethernet connector, M.2 (B\-key) memory interface and M.2 (E\-key) radio interface, Infineon’s Shield2Go interface, Mikroelektronika's mikroBUS compatible headers, 6\-Axis IMU sensor, 3\-axis Magnetometer, microSD cardholder, CAPSENSE™ buttons and slider, user LEDs and user buttons. The MCU power domain supports following operating voltages \- 2\.7 V, 3\.3 V, 4\.2 V and the peripheral power domain supports operating voltages \- 1\.8 V and 3\.3 V.


## BSP Configuration

The BSP has a few hooks that allow its behavior to be configured. Some of these items are enabled by default while others must be explicitly enabled. Items enabled by default are specified in the KIT_PSE84_EVAL_EPC2.mk file. The items that are enabled can be changed by creating a custom BSP or by editing the application makefile.

Components:

Defines:
* CYBSP_WIFI_CAPABLE - This define, disabled by default, causes the BSP to initialize the interface to an onboard wireless chip if it has one.
* CYBSP_CUSTOM_SYSCLK_PM_CALLBACK - This define, disabled by default, causes the BSP to skip registering its default SysClk Power Management callback, if any, and instead to invoke the application-defined function `cybsp_register_custom_sysclk_pm_callback` to register an application-specific callback.

### Clock Configuration

|  Clock   |   Source  | Output Frequency |
| :------: | :-------: | :--------------: |
| CLK_HF0  | CLK_PATH0 |     200 MHz      |
| CLK_HF1  | CLK_PATH0 |     400 MHz      |
| CLK_HF2  | CLK_PATH2 |     300 MHz      |
| CLK_HF3  | CLK_PATH0 |     200 MHz      |
| CLK_HF4  | CLK_PATH0 |     400 MHz      |
| CLK_HF5  | CLK_PATH0 |     200 MHz      |
| CLK_HF6  | CLK_PATH0 |     200 MHz      |
| CLK_HF7  | CLK_PATH1 |      49 MHz      |
| CLK_HF8  | CLK_PATH0 |      50 MHz      |
| CLK_HF9  | CLK_PATH0 |      80 MHz      |
| CLK_HF10 | CLK_PATH0 |     100 MHz      |
| CLK_HF11 | CLK_PATH0 |     200 MHz      |
| CLK_HF12 | CLK_PATH4 |      24 MHz      |
| CLK_HF13 | CLK_PATH0 |     100 MHz      |

### Power Configuration

* System Active Power Mode: HP
* System Idle Power Mode: Deep Sleep
* VDDA Voltage: 1800 mV
* VDDD Voltage: 1800 mV

See the [BSP Setttings][settings] for additional board specific configuration settings.

## Default linker scripts
The default linker scripts define a lot of different regions so this document is intended to explain their
purposes. The analysis will be done per memory area.

### ITCM
* m55_code: this is the main code region for the cm55 core code

### DTCM
* m55_data: this is the main data region for the cm55 core data

### RRAM
* A reserved region that should never be removed as it is used for boot firmware, and write-protected
* user_programmable, a region for the cm33 secure core to store persistent data
* user_nvm, a region for storage of non-volatile data from non-secure cores
* A reserved region that should not be used or removed, reserved for boot firmware

### SRAM
* m33s_shared, a region for the cm33_s core to place data that need to be shared with the cm33_ns
* m33s_code, the main region for code for the cm33_s core that gets copied over from the from the non-volatile memory (m33s_nvm) at boot
* m33s_data the main data region for the cm33_s core, initialized data gets copied over from the non-volatile memory (m33s_nvm) at boot, non initialized data gets zeroed
* m33_code, the main region for code for the cm33_ns core that gets copied over from the External Flash at boot
* m33_data the main data region set aside for the cm33_ns core, initialized data gets copied over from the non-volatile memory (m33_nvm) at boot, non initialized data gets zeroed
* m33s_allocatable_shared, this region is where the cm33_s core can allocate data that can be accessed by all cores. It has to be uninitialized
* m33_allocatable_shared, this region is where the cm33 core can allocate data that can be accessed by all cores. It has to be uninitialized
* m55_allocatable_shared, this region is where the cm55 core can allocate data that can be accessed by all cores. It has to be uninitialized

### SoCMem
* m55_code_secondary: this is an additional code region for the cm55 core, it’s slightly less performing than the ITCM
* m55_data_secondary: this is an additional data region for the cm55 core, it’s slightly less performing than the DTCM
* m33_m55_shared: this is a data region created to share data between the non secure cores (cm33_ns and cm55)
* gfx_mem: this is a data region for graphics purposes, it is shared between the non secure cores (cm33_ns and cm55)

### External Flash (Serial Memory Interface block 0 memory 1)
* m33s_nvm: this is the region where all code and data gets placed at programming time for the cm33s core and then gets copied over onto the RAM locations for the areas that are specified. It also include the non-secure callable (NSC) region.
* m33s_trailer: cm33_s trailer
* m33_nvm: this is the region where all code and data gets places at programming time for the cm33_ns core and then gets copied over onto the RAM locations for the areas that are specified
* m33_trailer: cm33_ns trailer
* m55_nvm: this is the region where all code and data gets places at programming time for the cm55 core and then gets copied over onto the RAM locations for the areas that are specified
* m55_trailer: cm55 trailer

The memory configurator allows to move, rename, resize, erase regions as needed.

## Memory Configurator Outputs
The output of the memory configurator are files that can be found in `%your_project%/bsps/TARGET_%board_name%/config/GeneratedSource`.
These files are:
* `cymem_CM33_S_0.h`, `cymem_CM33_0.h`, `cymem_CM55_0.h`: these three files generate defines for all defined regions in the memory configurator for start, size and offset for the regions that are applicable to that core.
* `cymem_armlink_CM33_S_0.sct`, `cymem_armlink_CM33_0.sct`, `cymem_armlink_CM55_0.sct`: these three files contain all the defines for the regions in the memory configurator but have the Scatterfile extension to be easily picked up and integrated in the linker scripts for the ARM toolchain
* `cymem_gnu_CM33_S_0.ld`, `cymem_gnu_CM33_0.ld`, `cymem_gnu_CM55_0.ld`: these three files contain all the defines for the regions in the memory configurator but have the ld extension to be easily picked up and integrated in the linker scripts for the GCC_ARM and LLVM_ARM toolchain
* `cymem_gnu_regions_CM33_S_0.ld`, `cymem_gnu_regions_CM33_0.ld`, `cymem_gnu_regions_CM55_0.ld`: these three files contain all the MEMORY regions information as needed by the GCC_ARM and LLVM_ARM linkers to partition the memory correctly.
* `cymem_ilinkarm_CM33_S_0.ld`, `cymem_ilinkarm_CM33_0.ld`, `cymem_ilinkarm_CM55_0.ld`: these three files contain all the defines for the regions in the memory onfigurator but have the icf extension to be easily picked up and integrated in the linker scripts for the IAR toolchain.
* `cymem_ilinkarm_regions_CM33_S_0.ld`, `cymem_ilinkarm_regions_CM33_0.ld`, `cymem_ilinkarm_regions_CM55_0.ld` : these three files contain all the memory regions
information as needed by the IAR linkers to partition the memory correctly.

## Note on memory aliases
It is important to also note that all memory regions can have up to 4 different valid addresses, that differ in access type.  For example, the same external flash (SMIF_Port0) address can be accessed using:
* 0x08000000 if using non secure access over CBUS
* 0x60000000 if using non secure access over SBUS
* 0x18000000 if using secure access over CBUS
* 0x70000000 if using secure access over SBUS

The distinction between secure and non-secure access is relatively simple, but understanding CBUS and SBUS requires more attention. CBUS provides faster, higher-performance access to memory regions, but it supports only read operations. As a result, CBUS is typically used for code execution at runtime. In contrast, SBUS offers both read and write capabilities, though with lower performance. SBUS is necessary when writing data to memory, such as during device programming.

## API Reference Manual

The KIT_PSE84_EVAL_EPC2 Board Support Package provides a set of APIs to configure, initialize and use the board resources.

See the [BSP API Reference Manual][api] for the complete list of the provided interfaces.

## More information
* [KIT_PSE84_EVAL_EPC2 BSP API Reference Manual][api]
* [KIT_PSE84_EVAL_EPC2 Documentation](https://www.infineon.com/product-information/kit_pse84_eval)
* [Infineon Technologies AG](https://www.infineon.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.infineon.com/modustoolbox)

[api]: https://infineon.github.io/TARGET_KIT_PSE84_EVAL_EPC2/html/modules.html
[settings]: https://infineon.github.io/TARGET_KIT_PSE84_EVAL_EPC2/html/md_bsp_settings.html

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2025.