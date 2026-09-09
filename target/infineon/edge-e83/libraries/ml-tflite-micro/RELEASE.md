# ModusToolbox™ Machine Learning TFLiteU Asset

## What's Included?

Refer to the [README.md](./README.md) for a complete description of the ModusToolbox™ Machine Learning TFLiteU asset.

## What Changed?

### v3.1.0

* Implemented support for PSOC Edge™ capabilities:
    * Cortex-M33 (CPU-based inference)
    * NNLite™ NPU integration (Cortex-M33 core only)
    * EthosU U55 NPU integration (Cortex-M55 core only)
* Updated TensorFlow up to 2.14.1 and set ethos-u-vela up to 3.11
* Added LSTM models support
* Removed dependency to the Y data as they were not used
* Update configuration JSON schema
* Fixed issue when calibration data were limited to the 200 samples

### v2.0.0

* Initial release of TensorFlow Lite Micro inference
* PSOC6™ as a target platform (Cortex-M4)

## Supported Software and Tools

This version of the ModusToolbox™ Machine Learning TFLiteU asset was validated for the compatibility with the following Software and Tools:

| Software and Tools                                      | Version      |
| :---                                                    | :----:       |
| ModusToolbox™ Software Environment                      | 3.4.0        |
| GCC Compiler                                            | 11.3         |
| ARM Compiler 6                                          | 6.22         |
| LLVM**                                                  | 19.1.1       |

**LLVM supported for CM4- and CM33-only, CM33 with NNLite, softFP only.

## More information

For more information, refer to the following documents:

* [ModusToolbox™ Machine Learning Design Support](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/modustoolbox-machine-learning/)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.cypress.com/products/modustoolbox-software-environment)
* [Infineon Technologies AG](https://www.infineon.com)

---
© 2022-2025, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.
