# Retarget IO

A utility library to retarget the standard input/output (STDIO) messages to a UART port. With this library, you can directly print messages on a UART terminal using `printf()`.

### What's Included?
* printf() support over a UART terminal
* Support for GCC, IAR, and ARM toolchains
* Thread safe write for NewLib
* Optional PDL-only support

### What Changed?
#### v1.9.0
* Added `cy_retarget_io_change_baud_rate` function.
* Refactored duplicate code in `fputc` and `_fputc$unlocked` to use a common helper function.
#### v1.8.1
* Documentation update
#### v1.8.0
* Updated `_read` and `_write` function attributes to support GCC 14.
#### v1.7.0
* Added support for MTB HAL API version 3.
* UART peripheral to be set up and initilalized as a prerquisite for using the retarget-io library.
* cy_retarget_io_init function signature change. Init function needs a pre-initialized HAL UART object as input parameter.
* cy_retarget_io_init_fc function removed.
* Stopped exposing the HAL UART object.
#### v1.6.0
* Added support for PDL-only.  When COMPONENT_MTB_HAL or CY_USING_HAL is not defined, only the PDL will be used to support printf() functionality.
* Changed declaration of putc override for ARM compiler to align with latest ARM guidance.
#### v1.5.0
* Add a new macro `CY_RETARGET_IO_NO_FLOAT`. When defined, floating point string formatting support will be disabled,
  allowing for flash savings in applications which do not need this functionality.
#### v1.4.0
* Add cy_retarget_io_init_fc function to initialize with flow control pins
* Mark mutex as no longer initialized after 'cy_retarget_io_deinit'
#### v1.3.0
* Added support for checking whether data is being transmitted and waiting until done before finishing the deinit process
* Added support for using with HAL v1 or v2
#### v1.2.0
* Improve error handling
* Add de-initialization of the mutex to `cy_retarget_io_deinit`
* Update documentation for integration of the library in a RTOS environment.
#### v1.1.1
* Minor update for documentation & branding
#### v1.1.0
* Implemented system I/O retarget functions specific to ARM Compiler 6.
* Made _write implementation thread-safe for Newlib.
#### v1.0.0
* Initial release

### Supported Software and Tools
This version of the Retarget IO was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.6.0   |
| GCC Compiler                              | 14.2.1  |
| IAR Compiler                              | 9.50.2  |
| ARM Compiler 6                            | 6.22    |

Minimum required ModusToolbox™ Software Environment: v3.5.0

### More information

* [API Reference Guide](https://infineon.github.io/retarget-io/html/index.html)
* [Infineon](http://www.infineon.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [PSoC™ 6 Code Examples using ModusToolbox™ IDE](https://github.com/infineon/Code-Examples-for-ModusToolbox-Software)
* [ModusToolbox™ Software](https://github.com/Infineon/modustoolbox-software)

---
© Copyright 2018-2025 Infineon Technologies Apache2
