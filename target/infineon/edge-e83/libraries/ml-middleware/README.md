# ModusToolbox™ Machine Learning Middleware Library

## Overview
The ModusToolbox™ ML Middleware Library is a set of helper functions to handle the Machine Learning models and capability to receive stream validation data.

## Features
* mtb_ml        - functions for module initialization
* mtb_ml_utils  - functions to help handling the inputs/outputs of a ML model
* mtb_ml_model  - functions to initialize and inference a ML model
* mtb_ml_stream - functions to stream validation data

## Requirements

* [ModusToolbox™ software](https://www.cypress.com/products/modustoolbox-software-environment) v3.6 or greater
* Programming Language: C
* Associated Parts: See "Supported Kits" section below.

## Supported Device Family

* [PSOC™ 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [PSOC™ Edge](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/32-bit-psoc-edge-arm/)

## Supported Toolchains (make variable 'TOOLCHAIN')

* GNU Arm® Embedded Compiler 14.2 (`GCC_ARM`)
* ARM Compiler v6.22 (`ARM`)
* LLVM Embedded Toolchain for ARM v19.1.5 (`LLVM_ARM`)

The ModusToolbox™ ML Middleware library supports the following operating systems:
- Windows 7 and greater
- Ubuntu 18.04 and greater
- macOS Catalina and greater

## Quick Start Guide

This quick start guide assumes that the environment is configured for ModusToolbox™ applications development. If  PSOC™ 64 device is being used for development, it is provisioned as documented in [PSOC™ 64 Secure MCU Secure Boot SDK User Guide](www.cypress.com/documentation/software-and-drivers/psoc-64-secure-mcu-secure-boot-sdk-user-guide).

### Adding the library

Middleware library is provided in the form of the source code. There are two ways to add library to our project:

* add a dependency file (MTB format) into the 'deps' folder;
* use the Library Manager. It is available under Libraries Tab >  Machine Learning > ml-middleware.

### Using the library - ML inference engines

This library supports ml-tflite-micro inference library only. ml-inference is deprecated.

The ml-tflite-micro library is available as a ModusToolbox™ asset. Use the following GitHub link: [https://github.com/infineon/ml-tflite-micro](https://github.com/infineon/ml-tflite-micro). You can add a dependency file (mtb format) under the `deps` folder or use the `Library Manager` to add it to your application. It is available under Library -> Machine Learning -> ml-tflite-micro.

Refer to the ml-tflite-micro README.md files for further information on the `COMPONENTS` and `DEFINES` that must be added in order to select the preferred inference engine.

### Using the library - ML models types

User can define model's quantization explicitly, defining following symbols (only one out of list):
- `COMPONENT_ML_INT16x8`
- `COMPONENT_ML_INT8x8`
- `COMPONENT_ML_FLOAT32`

This could be done through Makefile:

```
COMPONENTS+=ML_FLOAT32
```

Defining these symbols makes following macroses working for user's convenience:

- `ML_INCLUDE_MODEL_FILE_IMPL`
- `ML_INCLUDE_MODEL_X_DATA_FILE_IMPL`
- `ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL`
- `MTB_ML_MODEL_BIN_DATA`

This makes model and regression data files inclusion account file names suffices, defining its type: `TEST_MODEL_tflm_less_model_int8x8.h`

If none of listed is defined, type-less variant of middleware API will be used, identifying quantization runtime.

In type-less variant an application author have to take care about including appropriate model's and data files. For example:

```
#include "WakeWord_model.h"
#include "speech_data_x.h"
#include "speech_data_y.h"
```

Model's and data initialization need to be done manually in this case too:

```
mtb_ml_model_bin_t model_bin = WakeWord_model_bin;

mtb_ml_x_file_header_t *x_file_header = (mtb_ml_x_file_header_t *)speech_data_x_bin;
/* Point to regression data */
input_ref = (MTB_ML_DATA_T *)(((uint32_t) x_file_header) + sizeof(*x_file_header));
output_ref = (MTB_ML_DATA_T *)speech_data_y_bin;
```

### Using the library - ML stream

1. Make sure the application includes module header file and selected model:
```c
#include "mtb_ml.h"
#include MTB_ML_INCLUDE_MODEL_FILE(MODEL_NAME)
```

2. Initialize the model:
```c
mtb_ml_model_t *model_object;
mtb_ml_model_bin_t model_bin = {MTB_ML_MODEL_BIN_DATA(MODEL_NAME)};
if (mtb_ml_model_init(&model_bin, NULL, &model_object) != MTB_ML_RESULT_SUCCESS)
{
    // Error handling
}
```

3. Initialize the streaming interface:
```c
mtb_ml_stream_interface_t iface;
mtb_data_streaming_interface_t *iface_obj = (mtb_data_streaming_interface_t *) malloc(sizeof(mtb_data_streaming_interface_t));
if(!iface_obj)
{
    // Error handling
}

iface.interface_obj = iface_obj;
```

4. Initialize the stream. On the desktop side, start the streaming application ml-coretools-middleware-streaming. Note that mtb_ml_stream_init does not allocate any memory resources, but is used to initialize communication with the desktop. Therefore, if you wish to run re-run your device application without re-programming it between runs, you must call mtb_ml_stream_init for each run.
```c
/* Initialize stream */
status = mtb_ml_stream_init(&iface, model_object);
if(status != MTB_ML_RESULT_SUCCESS)
{
    // Error handling
}
```
5. Your application then needs to receive input data, and transmit the resulting output data back to the desktop continuosly. Here is a typical use case as an example:
```c
cy_rslt_t stream_task(mtb_ml_stream_interface_t *iface, mtb_ml_model_t *model_object)
{
    cy_rslt_t result;

    /* Alloc RX buf */
    MTB_ML_DATA_T *rx_buf = (MTB_ML_DATA_T *)malloc(iface->input_size * sizeof(MTB_ML_DATA_T));
    if(!rx_buf)
    {
        // Error handling
    }

    for (int i = 0; i < iface->x_data_info.num_of_samples; i++)
    {
        // Streaming input data
        result = mtb_ml_stream_input_data(iface, rx_buf, USER_TIMEOUT_VAL);
        if(result != MTB_ML_RESULT_SUCCESS)
        {
            // Error handling
        }

        // Inferencing
        result = mtb_ml_model_run(model_object, (MTB_ML_DATA_T *) rx_buf);
        if (result != MTB_ML_RESULT_SUCCESS)
        {
            // Error handling
        }

        // Streaming output data
        result = mtb_ml_stream_output_data(iface, model_object->output, tx_timeout_ms);
        if(result != MTB_ML_RESULT_SUCCESS)
        {
            printf("ERROR: Failed to send output data to host\r\n");
            goto ret_err;
        }
    }
}
```
6. Finally, inform the host that your application is complete:
```c
status = mtb_ml_inform_host_done(iface, DEFAULT_TIMEOUT_MS);
if(status != MTB_ML_RESULT_SUCCESS)
{
    // Error handling
}
```

Note: The UART port is shared with the debug port for any messages that are printed by the application.

### Using the library - U55

To enable U55 support for Vela optimized models, simply add ```U55``` to the ```COMPONENTS``` make variable, or define the component explicitly in your Makefile:
```Make
DEFINES+=COMPONENT_U55
```
You also have the option to enable/disable the U55 security and privilege options as well:
```Make
DEFINES+=MTB_ML_ETHOSU_SECURITY_ENABLE=0
DEFINES+=MTB_ML_ETHOSU_PRIVILEGE_ENABLE=1
```
These options are defined as ```MTB_ML_ETHOSU_SECURITY_ENABLE=0``` and ```MTB_ML_ETHOSU_PRIVILEGE_ENABLE=1``` by default. For more information on these options, see [https://developer.arm.com/documentation/102420/0200/Functional-description/Security-and-boot-flow](https://developer.arm.com/documentation/102420/0200/Functional-description/Security-and-boot-flow).

Cache management settings are drive by ```MTB_ML_ETHOSU_CACHE_MGMT_TYPE``` parameter, with possible values:

```MTB_ML_ETHOSU_CACHE_MGMT_CONDITIONAL``` : this mode clears or invalidates the entire cache based on an internal state.
It can reduce the total number of CPU cycles, but it might cause some undesired behavior in the application affecting other cache/memory users.
```MTB_ML_ETHOSU_CACHE_MGMT_ALL_LAYERS``` : this mode clears and invalidates the cache by address for each layer using cache-API calls within the driver.
```MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS``` : this mode clears the input layer before executing the inference and invalidates the output layer after executing inference. Should be only used if all operators are supported by Ethos-U55.


By default, original cache management is performed on every single TFLM operation (for each model's layer).
This setting could be changed to optional variant when cache management is performed only on the input and output layers with defining following constant:

You can set MTB_ML_ETHOSU_CACHE_MGMT_TYPE in the DEFINES list in the Makefile or call mtb_ml_set_cache_mgmt_type() function to change the cache management type to one of the above options.

```Make
DEFINES+=MTB_ML_ETHOSU_CACHE_MGMT_TYPE=1 # ALL_LAYERS
```

### Using the library - NNLite NPU (PSOC Edge)

To enable NNLITE NPU support (works on Cortex-M33 only), add `NNLITE2` to the `COMPONENTS` make variable, or define the component explicitly in your Makefile:

```Make
DEFINES+=COMPONENT_NNLITE2
```
###  Using the library - SRAM banks sharing (PSOC Edge, Cortex-M33)

For CM33 application only SRAM1 bank is used from BSP by default.

There might be a need to use more SRAM memory for two major reasons:

* Overcome SRAM1 available space constraints;
* Avoid single-bank contention for NNLite NPU operation (high perfomance impact);

It is possible to use SRAM0 bank to resolve issues above.

#### SRAM Sharing - Model Data relocation

Pass parameter during make command `MEM_MODEL=".cy_sram0_data_ns"`

Or, which would be an equivalent, create DEFINE-name `CY_ML_MODEL_MEM=".cy_sram0_data_ns"`

This will instruct linker script to place model data into SRAM0 memory bank, so SRAM1 space will be released for another usage.

#### SRAM Sharing - Tensor Arena relocation

It is also possible to relocate TFLiteMicro tensor arena buffer from default SRAM1 to SRAM0.

To achieve this an interface of `mtb_ml_model_init()` needs to be used, where `mtb_ml_model_buffer_t *buffer` should be allocated and referenced by user.

A following code snippet demonstrates minimum changes needed from application side:

```C
CY_SECTION_SRAM0_DATANS_BEGIN
uint8_t mtb_ml_sram0_arena[MODEL_ARENA_SIZE];
CY_SECTION_SRAM0_DATANS_END
...

mtb_ml_model_buffer_t tensor_buffer = {0};
tensor_buffer.tensor_arena = mtb_ml_sram0_arena;

cy_rslt_t result = mtb_ml_model_init(&model_bin, &tensor_buffer, &model_object);
...
```

Make sure arena buffer size is not smaller that TFLiteMicro interpreter needs for a given model.

__NOTE:__  tensor arena and model data relocations are possible for interpreter-only mode.
For interpreter-less mode all buffers and arrays are definced statically in pre-generated file.

### Using the library - RTOS Aware Environment

The ```semaphore_take()``` and ```mutex_take()``` functions for both U55 and NNLite drivers are implemented as non-blocking in an ISR and with a default ```ML_NPU_SEMAPHORE_TIMEOUT``` and ```ML_NPU_MUTEX_TIMEOUT``` blocking time outside of an ISR. This timeout can be configured by defining ```ML_NPU_SEMAPHORE_TIMEOUT``` and/or ```ML_NPU_MUTEX_TIMEOUT``` in the user code. For example:
```Make
DEFINES+=ML_NPU_SEMAPHORE_TIMEOUT=CY_RTOS_NEVER_TIMEOUT
DEFINES+=ML_NPU_MUTEX_TIMEOUT=CY_RTOS_NEVER_TIMEOUT
```

Both ```ML_NPU_SEMAPHORE_TIMEOUT``` and ```ML_NPU_MUTEX_TIMEOUT``` shall be represented in ms, and must be of type ```uint32_t```.

Also if using FreeRTOSConfig.h from ml-middleware it is needed to define CY_DEVICE_CAT1D in Makefile:
```Make
DEFINES+=CY_DEVICE_CAT1D
```

### Using the library - miscellaneous settings

In case of using stateful RNN models, there is a need to define resource variables count through ```TFLM_RESVAR_COUNT``` parameter. It is set to 0 by default, excluding relevant TFLiteMicro initialization code.
To enable feature define this value to be a value between 1 and 64 (max count of resource variable supported). For example:

```Make
DEFINES +=TFLM_RESVAR_COUNT=5
```

### More information
The following resources contain more information:
* [ModusToolbox™ Machine Learning Design Support](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/modustoolbox-machine-learning/)
* [ModusToolbox™ Machine Learning Middleware Library RELEASE.md](./RELEASE.md)
* [MTB ML Middleware API Reference Guide](https://infineon.github.io/ml-middleware/html/index.html)
* [PSOC™ 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [PSOC™ Edge](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/32-bit-psoc-edge-arm/)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Cypress Semiconductor GitHub](https://github.com/Infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox)

---
© 2021-2026, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.
