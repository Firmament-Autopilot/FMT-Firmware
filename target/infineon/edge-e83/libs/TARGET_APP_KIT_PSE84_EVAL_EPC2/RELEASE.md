# KIT_PSE84_EVAL_EPC2 BSP Release Notes
The PSOC™ Edge E84 Evaluation Kit (KIT\_PSE84\_EVAL) is based on the PSOC™ Edge family of devices. It enables the evaluation and development of applications for the PSOC™ Edge E84 EPC2 MCU.


NOTE: BSPs are versioned by family. This means that version 1.2.0 of any BSP in a family (eg: XMC™ ) will have the same software maturity level. However, not all updates are necessarily applicable for each BSP in the family so not all version numbers will exist for each board. Additionally, new BSPs may not start at version 1.0.0. In the event of adding a common feature across all BSPs, the libraries are assigned the same version number. For example if BSP_A is at v1.3.0 and BSP_B is at v1.2.0, the event will trigger a version update to v1.4.0 for both BSP_A and BSP_B. This allows the common feature to be tracked in a consistent way.

### What's Included?
The KIT_PSE84_EVAL_EPC2 library includes the following:
* BSP specific makefile to configure the build process for the board
* cybsp.c/h files to initialize the board and any system peripherals
* cybsp_types.h file describing basic board setup
* CM33 Linker script & startup code for GCC and ARM toolchains
* CM55 Linker script & startup code for GCC and ARM toolchains
* Configurator design files (and generated code) to setup board specific peripherals
* .lib file references for all dependent libraries
* API documentation

### What Changed?
#### v1.2.0
* Documentation improvements
#### v1.1.0
* Removing out of date defines and improving error handling
#### v1.0.0
* Initial production release

### Supported Software and Tools
This version of the KIT_PSE84_EVAL_EPC2 BSP was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.6.0   |
| GCC Compiler                              | 14.2.1  |
| ARM Compiler&reg;                         | 6.16    |
| IAR Compiler                              | 9.50.1  |
| LLVM ARM Compiler                         | 19.1.1  |

Minimum required ModusToolbox™ Software Environment: v3.6.0

### More information
* [KIT_PSE84_EVAL_EPC2 BSP API Reference Manual][api]
* [KIT_PSE84_EVAL_EPC2 Documentation](https://www.infineon.com/product-information/kit_pse84_eval)
* [Infineon Technologies AG](https://www.infineon.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.infineon.com/modustoolbox)

[api]: https://infineon.github.io/TARGET_KIT_PSE84_EVAL_EPC2/html/modules.html

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2023.