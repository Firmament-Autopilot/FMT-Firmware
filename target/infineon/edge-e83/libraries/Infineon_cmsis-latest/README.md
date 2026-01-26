# CMSIS Repository

### Overview
This repository has CMSIS Core headers, CMSIS DSP and CMSIS NN source. It can be used by application or middleware to link CMSIS Core headers. It can also be used to build CMSIS DSP or NN based applications.

CMSIS Core is sourced from https://github.com/ARM-software/CMSIS_6

CMSIS DSP is sourced from https://github.com/ARM-software/CMSIS-DSP/releases/tag/v1.16.2

CMSIS NN is sourced from https://github.com/ARM-software/CMSIS_5/tree/5.9.0/CMSIS/NN

### Enabling CMSIS NN and DSP
CMSIS NN and DSP source are not enabled by default. The applications which require CMSIS NN or CMSIS DSP need to update Makefile to add these in the components list:

COMPONENTS += CMSIS_NN CMSIS_DSP
