# Retarget IO

### Overview

A utility library to retarget the standard input/output (STDIO) messages to a UART port. With this library, you can directly print messages on a UART terminal using `printf()`. You can specify the TX pin, RX pin, and the baud rate when configuring the UART. When using MTB-HAL, the library also provides functionality to dynamically change the UART baud rate at runtime.

**NOTE:** The standard library is not standard in how it treats an I/O stream. Some implement a data buffer by default. The buffer is not flushed until it is full. In that case it may appear that your I/O is not working. You should be aware of how the library buffers data, and you should identify a buffering strategy and buffer size for a specified stream. If you supply a buffer, it must exist until the stream is closed.

**Buffer Configuration:** The default buffer size is typically defined by the `BUFSIZ` constant in `<stdio.h>`, which varies by compiler (usually 512-1024 bytes for embedded systems). This buffer is managed by the C standard library implementation that comes with your compiler (GCC_ARM/LLVM, ARM, IAR etc.). The retarget-io library works independently of these buffers by implementing low-level I/O redirection, but standard library buffering still applies unless explicitly disabled with `setvbuf()`.

### Buffer Flushing Behavior by Compiler

**GCC_ARM, LLVM and ARM Compilers:**
These compilers support automatic buffer flushing control. You can disable buffering entirely:
```c
#include <stdio.h>
setvbuf(stdin, NULL, _IONBF, 0);   // Disable input buffering
setvbuf(stdout, NULL, _IONBF, 0);  // Disable output buffering
```

**IAR Compiler:**
IAR has limited standard library support in embedded projects. Buffer flushing must be handled manually:
- **Automatic flush:** End printf strings with `\n` (newline character)
- **Manual flush:** Call `fflush(stdout)` if available, or use newline characters

### Manual Buffer Flushing Methods

If automatic buffer disabling is not available, use these approaches:

1. **Always use newline characters (most portable):**
   ```c
   printf("Hello World\n");  // Flushes immediately on most systems
   ```

2. **Manual flush with fflush() (if supported):**
   ```c
   printf("Hello World");
   fflush(stdout);  // Force immediate output
   ```

### Important Notes

**Floating Point Support:** If the application is built using newlib-nano, by default, floating point format strings (%f) are not supported. To enable this support, you must add `-u _printf_float` to the linker command line.

**ISR Context:** In general, console prints such as printf() should not be performed in ISR context. It must definitely not be called in ISR context when `CY_RTOS_AWARE` is defined, as the thread safety implementation disallows such calls.

**PDL-Only Mode:** If the application is built without HAL support (i.e., neither `COMPONENT_MTB_HAL` nor `CY_USING_HAL` is defined), then the UART must be initialized using PDL function calls prior to being passed into the `cy_retarget_io_init()` function. See *Quick Start (PDL Only)* section below.

### RTOS Integration
To avoid concurrent access to the UART peripheral in a RTOS environment, the ARM and IAR libraries use mutexes to control access to stdio streams. For Newlib (GCC_ARM), the mutex must be implemented in _write() and can be enabled by adding `DEFINES+=CY_RTOS_AWARE` to the Makefile. For all libraries, the program must start the RTOS kernel before calling any stdio functions.

HAL support is required for retarget-io in an RTOS environment.  If your project does not include HAL support, you must manually manage concurrency in your application.

## Initialization Function Reference {#init_function_reference}

The retarget-io library provides different initialization functions based on your project configuration:

| Configuration | Function | Parameters | Notes |
|---------------|----------|------------|-------|
| **MTB-HAL** (`COMPONENT_MTB_HAL`) | cy_retarget_io_init() | 1 arg: MTB-HAL UART object pointer | Requires pre-configured UART |
| | cy_retarget_io_change_baud_rate() | 2 args: baud rate, actual baud pointer | Changes UART baud rate dynamically on retarget-io UART |
| **CY-HAL** (`CY_USING_HAL`) | cy_retarget_io_init() | 3 args: TX pin, RX pin, baud rate | Macro calling cy_retarget_io_init_fc() |
| | cy_retarget_io_init_fc() | 5 args: pins + flow control | Full control with CTS/RTS |
| | cy_retarget_io_init_hal() | 0 args | Assumes `cy_retarget_io_uart_obj` pre-initialized |
| **PDL-Only** (no HAL) | cy_retarget_io_init() | 1 arg: SCB UART peripheral pointer | Not thread-safe |

### Quick Start (with MTB-HAL(COMPONENT_MTB_HAL) Support)
1. Configure the UART using the device configurator generated structures or through manually written config structures. Configuration includes the UART TX and RX pins, CTS/RTS pins if flow control is desired, Baud Rate and other UART config parameters
2. Set up the clock source to the UART peripheral. This could be done using the device configurator or manually. Set up the clock divider value depending on the desired baud rate.
3. Initialize the UART Hardware using PDL function calls. For example, if using a device where UART is provided by an SCB:
```
    result = Cy_SCB_UART_Init(DEBUG_UART_HW, &DEBUG_UART_config, &DEBUG_UART_context);
    // Check for correct result
```
4. Set up the HAL UART object.
```
    result = mtb_hal_uart_setup(&DEBUG_UART_hal_obj,
                                &CYBSP_DEBUG_UART_hal_config,
                                &DEBUG_UART_context, NULL);
    // Check for correct result
```
5. Enable the UART peripheral
```
    Cy_SCB_UART_Enable(DEBUG_UART_HW);
```
6. Add `#include "cy_retarget_io.h"`.
7. Call `cy_retarget_io_init(&DEBUG_UART_hal_obj);`.
8. Start printing using `printf()`.
9. **Optional:** Change UART baud rate dynamically using `cy_retarget_io_change_baud_rate()`:
   ```c
   uint32_t actual_baud = 0;
   cy_rslt_t result = cy_retarget_io_change_baud_rate(9600, &actual_baud);
   if (result == CY_RSLT_SUCCESS) {
       printf("Baud rate changed to %lu\n", actual_baud);
   }
   ```
   **Note:** This function uses the MTB-HAL baud rate setting capability to automatically configure optimal peripheral clock divider and oversample values for accurate baud rates.
10. If needed, register a callback to handle the transitions to deepsleep (it's automatically registered in CY-HAL case). This can be done by registering with `Cy_SysPm_RegisterCallback` either the predefined mtb_syspm_scb_uart_deepsleep_callback from the syspm-callbacks asset or a new callback function specific to the needs of the user. For more info refer to `Cy_SysPm_RegisterCallback` in PDL documentation.

### Quick Start (with CY-HAL(CY_USING_HAL) Support)
1. Add `#include "cy_retarget_io.h"`
2. Choose one of the initialization options:

   **Basic initialization (3 parameters):**
   ```c
   cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
   ```

   **With flow control (5 parameters):**
   ```c
   cy_retarget_io_init_fc(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 
                         CYBSP_DEBUG_UART_CTS, CYBSP_DEBUG_UART_RTS, 
                         CY_RETARGET_IO_BAUDRATE);
   ```

   **Pre-initialized UART object (0 parameters):**
   ```c
   // First initialize cy_retarget_io_uart_obj separately, then:
   cy_retarget_io_init_hal();
   ```

   `CYBSP_DEBUG_UART_TX` and `CYBSP_DEBUG_UART_RX` pins are defined in the BSP and `CY_RETARGET_IO_BAUDRATE` is set to 115200. You can use a different baud rate if you prefer.

3. Start printing using `printf()`

### Quick Start (PDL Only)
These instructions apply when the UART interface is provided by the SCB peripheral directly using a PDL configured and initialized SCB object.  Only relevant when HAL is unavailable.  UART interfaces other than SCB are not supported at this time.

1. Add `#include "cy_retarget_io.h"`
2. Initialize and enable your UART hardware using PDL function calls.  The DEBUG_UART must be defined and configured in the Device Configurator tool.
```
    Cy_SCB_UART_Init(DEBUG_UART_HW, &DEBUG_UART_config, NULL);
    Cy_SCB_UART_Enable(DEBUG_UART_HW);
```
3. Call `cy_retarget_io_init(DEBUG_UART_HW);`
4. Start printing using `printf()`

### Dynamic Baud Rate Change (MTB-HAL Only)

The retarget-io library provides a function to dynamically change the UART baud rate at runtime when using MTB-HAL configuration:

```c
cy_rslt_t cy_retarget_io_change_baud_rate(uint32_t baud_rate, uint32_t* actual_baud);
```

This function operates on the UART object that was initialized with `cy_retarget_io_init()`, so no UART object parameter is needed.

#### Parameters:
- `baud_rate`: Desired baud rate (e.g., 9600, 115200, 230400)
- `actual_baud`: Pointer to store the actual baud rate achieved

#### Prerequisites:
- The retarget-io library must be initialized with `cy_retarget_io_init()` before calling this function

#### Features:
- **MTB-HAL Integration**: Uses `mtb_hal_uart_set_baud()` to leverage HAL's built-in baud rate configuration expertise
- **Automatic Configuration**: HAL automatically determines optimal peripheral clock divider and oversample values
- **Cross-Platform Compatibility**: Works consistently across different MTB-HAL supported hardware platforms
- **Communication Safety**: Includes proper UART buffer flushing before baud rate changes
- **Error Handling**: Returns appropriate error codes if baud rate cannot be achieved

#### Example Usage:
```c
#include "cy_retarget_io.h"

// Initialize retarget-io first
cy_retarget_io_init(&DEBUG_UART_hal_obj);

// Change to different baud rates as needed
uint32_t actual_baud = 0;

// Change to 9600 baud
cy_rslt_t result = cy_retarget_io_change_baud_rate(9600, &actual_baud);
if (result == CY_RSLT_SUCCESS) {
    printf("Successfully changed to %lu baud\n", actual_baud);
} else {
    printf("Failed to change baud rate\n");
}

// Change back to 115200 baud
result = cy_retarget_io_change_baud_rate(115200, &actual_baud);
```

#### Important Notes:
- This function is **only available when `COMPONENT_MTB_HAL` is defined**
- Changing the baud rate will cause temporary communication disruption
- The terminal/host must also be set to the new baud rate to maintain communication
- For production use, consider using a separate debug UART that maintains a fixed baud rate
- The function uses MTB-HAL's `mtb_hal_uart_set_baud()` for reliable cross-platform baud rate configuration

### Enabling Conversion of '\\n' into "\r\n"

#### Line Ending Conventions
The difference between `\n` and `\r\n` relates to different line ending conventions:

- **`\n` (Line Feed, LF)**: Used by Unix/Linux/macOS systems
- **`\r\n` (Carriage Return + Line Feed, CRLF)**: Used by Windows systems  
- **`\r` (Carriage Return, CR)**: Used by old Mac systems (pre-macOS)

#### In UART Terminal Context
When sending text over UART to a terminal:

1. **`\n` only**: Moves cursor to the next line but **may not** return to the beginning of the line on some terminals
2. **`\r\n`**: Properly moves cursor to the beginning of the next line on **all terminals**

#### Automatic Conversion Feature
If you want to use only `\n` instead of `\r\n` for printing a new line using printf(), define the macro `CY_RETARGET_IO_CONVERT_LF_TO_CRLF` using the *DEFINES* variable in the application Makefile. The library will then automatically append `\r` before each `\n` character on the output (STDOUT). No conversion occurs if `\r\n` is already present in the string.

**Example without conversion:**
```c
printf("Line 1\n");
printf("Line 2\n");
printf("Line 3\n");
```
May display as:
```
Line 1
      Line 2
            Line 3
```

**Example with conversion (CY_RETARGET_IO_CONVERT_LF_TO_CRLF defined):**
```c
printf("Line 1\n");  // Automatically becomes "Line 1\r\n"
printf("Line 2\n");  // Automatically becomes "Line 2\r\n"
printf("Line 3\n");  // Automatically becomes "Line 3\r\n"
```
Displays correctly as:
```
Line 1
Line 2
Line 3
```

**Recommendation:** For embedded UART terminals, it's generally safer to either define `CY_RETARGET_IO_CONVERT_LF_TO_CRLF` in your Makefile or manually use `\r\n` in your printf strings to ensure proper line formatting across all terminal applications.

### Floating Point Support
By default, floating point support is enabled in printf. If floating point values will not be used in printed strings, this functionality can be disabled to reduce flash consumption. To disable floating support, add the following to the application makefile: `DEFINES += CY_RETARGET_IO_NO_FLOAT`.

### More information

* [API Reference Guide](https://infineon.github.io/retarget-io/html/index.html)
* [Infineon](http://www.infineon.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [PSoC™ 6 Code Examples using ModusToolbox™ IDE](https://github.com/infineon/Code-Examples-for-ModusToolbox-Software)
* [ModusToolbox™ Software](https://github.com/Infineon/modustoolbox-software)

---
© Copyright 2018-2025 Infineon Technologies Apache2
