# stdlib Stubs Release Notes
The stdlib Stubs asset provides necessary WEAK stub implementations of all of the functions that nosys provides implementations for, but without the attached warnings that the GCC_ARM toolchain will throw when compiling the nosys versions of the stubs.

### What's Included?
* Stub implementations of functions
_chown,
_close,
_execve,
_fork,
_fstat,
_getentropy,
_getpid,
_gettimeofday,
_isatty,
_kill,
_link,
_lseek,
_open,
_isatty,
_read,
_readlink,
_stat,
_symlink,
_times,
_unlink,
_wait,
_write,
that GCC_ARM will throw warnings for by default when using their provided nosys lib implementations.

### What Changed?
#### v1.0.0
* Initial release

### Supported Software and Tools
This version of the stlib Stubs Library was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.6.0   |
| GCC Compiler                              | 14.2.1  |
| IAR Compiler                              | 9.50.4  |
| ARM Compiler                              | 6.22    |
| LLVM ARM Compiler                         | 19.1.5  |

Minimum required ModusToolbox™ Software Environment: v3.0

### More information
Use the following links for more information, as needed:
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2020-2025.