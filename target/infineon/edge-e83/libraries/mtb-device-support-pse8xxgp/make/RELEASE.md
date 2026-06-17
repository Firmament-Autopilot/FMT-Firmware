# PSOC™ Edge GNU make Build System Release Notes
This repo provides the build recipe make files and scripts for building and programming PSOC™ Edge applications. Builds can be run either through a command-line interface (CLI) or through a supported IDE such as Eclipse or VS Code.

### What's Included?
This release of the PSOC™ Edge GNU make build recipe includes complete support for building, programming, and debugging PSOC™ Edge application projects. It is expected that a code example contains a top level make file for itself and references a Board Support Package (BSP) that defines specific items, like the PSOC™ Edge part, for the target board. Supported functionality includes the following:

* Supported operations:
    * Build
    * Program
    * Debug
    * IDE Integration (Eclipse, VS Code, IAR, uVision)
* Supported toolchains:
    * GCC
    * IAR
    * ARM Compiler 6
    * LLVM Embedded Toolchain for Arm

### What Changed?
#### v2.3.2
* Removed obsolete interface_version_3 support.
* Added support for the memory report tool.

#### v2.3.1
* Improved missing toolchains handling.
* Improved FreeRTOS component flag handling for IAR toolchain.

#### v2.3.0
* Initial release.

### Product/Asset Specific Instructions
Builds require that the ModusToolbox™ tools be installed on your machine. This comes with the ModusToolbox™ install. On Windows machines, it is recommended that CLI builds be executed using the Cygwin.bat located in ModusToolBox/tools\_x.y/modus-shell install directory. This guarantees a consistent shell environment for your builds.

To list the build options, run the "help" target by typing "make help" in CLI. For a verbose documentation on a specific subject type "make help CY\_HELP={variable/target}", where "variable" or "target" is one of the listed make variables or targets.

### Supported Software and Tools
This version of the PSOC™ Edge build system was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.6     |
| GCC Compiler                              | 14.2.1  |
| LLVM Compiler                             | 19.1.5  |
| IAR Compiler                              | 9.50.2  |
| ARM Compiler                              | 6.22    |

Minimum required ModusToolbox™ Software Environment: v3.6

### More information
* [Infineon GitHub](https://github.com/Infineon)
* [ModusToolbox™](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software)
---
(c) 2020-2025, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
