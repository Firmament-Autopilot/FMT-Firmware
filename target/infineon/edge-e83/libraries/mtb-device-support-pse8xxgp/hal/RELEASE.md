# Hardware Abstraction Layer (HAL) Release Notes
The Hardware Abstraction Layer (HAL) provides an implementation of the Hardware Abstraction Layer for the PSE8XXGP family of chips. This API provides convenience methods for initializing and manipulating different hardware peripherals. Depending on the specific chip being used, not all features may be supported.

On devices which contain multiple cores, this library is supported on all cores. If HAL is used on multiple cores at the same time, the application is responsible for ensuring that each peripheral is only used on one core at a given time.

### What's Included?
This release of the HAL includes support for the following drivers:
* ADC
* Clock
* Comp
* DMA
* GPIO
* I2C
* LPTimer
* MemorySPI
* NVM
* PWM
* RTC
* SDHC
* SDIO
* SPI
* SysPm
* System
* TRNG
* Timer
* UART

### What Changed?
#### v1.0.0
* Initial release for PSE8xxGP support.


### Supported Software and Tools
This version of the Hardware Abstraction Layer was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.6.0   |
| GCC Compiler                              | 14.2.1  |
| IAR Compiler                              | 9.50.2  |
| ARM Compiler                              | 6.22    |
| LLVM ARM Compiler                         | 19.1.5  |

Minimum required ModusToolbox™ Software Environment: v3.6

### More information
Use the following links for more information, as needed:
* [API Reference Guide](https://infineon.github.io/mtb-hal-pse8xxgp/html/modules.html)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2025.
