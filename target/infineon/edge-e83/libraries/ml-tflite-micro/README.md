# ModusToolbox™ Tensorflow tflite-micro library

## Overview

The ml-tflite-micro library is a pre-compiled TensorFlow tflite-micro runtime library for Infineon PSOC™ 6 and PSOC™ Edge microcontrollers.

### What is Provided

Infineon provides the following methods for running the TFLiteU inference engine on deployed machine learning models:

1. TFliteU runtime interpreter: Uses an interpreter to process a machine learning model deployed as binary data. This allows easy updates to the deployed model or the ability to perform inference on multiple models.

2. TfliteU interpreter-less: Uses pre-generated model specific code to perform the inference without an interpreter. This allows for smaller binaries as well as less overhead on inference execution.

In both cases, this version of the library provides three types of quantization - `floating point`, `16-bit integer` and `8-bit integer`.

### Quick Start

The ml-tflite-micro library is available as a ModusToolbox™ asset. Use the following GitHub link: https://github.com/infineon/ml-tflite-micro.
You can add a dependency file (mtb format) under the `deps` folder or use the `Library Manager` to add it to your application. It is available under Library -> Machine Learning -> ml-tflite-micro.

To use this library, the following `COMPONENTS` and `DEFINES` are required:

TFLiteU runtime interpreter:
- DEFINES+=TF_LITE_STATIC_MEMORY
- COMPONENTS+=ML_TFLM

TFLiteU interpreter less:
- DEFINES+=TF_LITE_STATIC_MEMORY TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA
- COMPONENTS+=ML_TFLM_LESS

TFLiteU floating point quantization:
- COMPONENTS+=ML_FLOAT32

TFLiteU 8-bit integer quantization:
- COMPONENTS+=ML_INT8x8

TFLiteU 16-bit integer quantization:
- COMPONENTS+=ML_INT16x8

Why these `DEFINES` are required:

`TF_LITE_STATIC_MEMORY`:
This is a google defined setting. This must be defined for all TFLiteU builds because tlite micro shares C API's with tflite. This supports a full dynamic/static memory tensor. This ensures there will be no dynamic branching in a given decision tree.

`TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA`:
Infineon defined setting. This is required when selecting TFliteU interpreter less. When defined, the prepared phase kernel variant selection code is dropped and TFLitU kernal convolution evaluation functions are used instead. This turns on the use of per-instance pre-computed parameters in TFLM interpreter less. Furthermore, uses pre-compiled data previously captured from a model Init/Prepare call.
Advantages: Smaller binaries, since only the required kernels are compiled. Smaller runtime, because many intermediate values are stored

`TF_LITE_STRIP_ERROR_STRINGS`:
This is a google defined setting. A release-variant of TFLM library is built, so need this one to strip MicroPrintf() routine calls.

Why these `COMPONENTS` are required:

`ML_TFLM/ML_TFLM_LESS`:
Determine whether you would like to use the runtime interpreter or TFliteU interpreter less variant. Either `ML_TFLM` or `ML_TFLM_LESS` must always be defined.

`ML_FLOAT32/ML_INT16x8/ML_INT8x8`:
Sets the quantization to be float, 16 bit or 8 bit integer. One of these must always be defined.

See [tensorflow-lite documentation](https://www.tensorflow.org/lite) for general information on on how to prepare and optimize AI/ML applications for execution using tensorflow-lite(micro). Information specific to the tensorflow-lite(micro) runtime environment for Microcontrollers is found [here](https://www.tensorflow.org/lite/microcontrollers).

### More information

* [TFLiteU Release Notes](./RELEASE.md)
* [ModusToolbox™ Machine Learning Design Support](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/modustoolbox-machine-learning/)
* [ModusToolbox™ Tensorflow-lite(micro) library Release Notes](./RELEASE.md)
* [ModusToolbox™ Software Environment, Quick Start Guide, Documentation, and Videos](https://www.cypress.com/products/modustoolbox-software-environment)
* [Cypress Semiconductor](http://www.cypress.com)

---
© 2022-2025, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.

