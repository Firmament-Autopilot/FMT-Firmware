### CMSIS Repo

### Overview

### What changed from previous releases?
CMSIS Core updated to CMSIS_6

###  What exactly was changed compared to upstream version
Source files which includes implemtation files e.g. https://github.com/ARM-software/CMSIS-DSP/blob/main/Source/FilteringFunctions/FilteringFunctions.c which includes other ".c" causes duplicate definition in MTB build environment, are skipped from main line. 


### What's Included?
* [CMSIS Core]
 Standardized API for the Cortex-M processor core and peripherals.
 Includes intrinsic functions for Cortex-M4/M7/M33/M35P SIMD instructions.
  CMSIS Core is based on CMSIS_6 tag https://github.com/ARM-software/CMSIS_6/releases/tag/v6.1.0

* [COMPONENT_CMSIS_NN]
 CMSIS NN, collection of efficient neural network kernels developed to maximize the
  performance and minimize the memory footprint on Cortex-M processor cores.
 CMSIS NN is sourced from https://github.com/ARM-software/CMSIS_5/tree/5.9.0/CMSIS/NN
* [COMPONENT_CMSIS_DSP]
 CMSIS DSP is an optimized compute library for embedded systems. Different variants are
  available according to the core and most of the functions are using a vectorized version
  when the Helium or Neon extension is available.
  CMSIS DSP is based on https://github.com/ARM-software/CMSIS-DSP/releases/tag/v1.16.2

### Known Issues
GCC has  limitated support of Helium instructions, due to which some specific instructions like vstrb  may trigger assembler errors due to unsupported or misinterpreted syntax. Issue is seen in CMSIS DSP component when compiled with optimization other than Debug mode (Optimzation level -Og) for Cortex-M55.

### More information

* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [Infineon](http://www.infineon.com)

---
© Cypress Semiconductor Corporation (an Infineon company), 2022.