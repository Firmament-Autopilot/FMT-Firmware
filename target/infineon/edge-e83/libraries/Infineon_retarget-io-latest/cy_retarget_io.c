/***************************************************************************//**
* \file cy_retarget_io.c
*
* \brief
* Provides APIs for retargeting stdio to UART hardware contained on the Infineon
* kits.
*
********************************************************************************
* \copyright
* (c) 2018-2025, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG. All rights reserved.
* This software, associated documentation and materials ("Software") is
* owned by Infineon Technologies AG or one of its affiliates ("Infineon")
* and is protected by and subject to worldwide patent protection, worldwide
* copyright laws, and international treaty provisions. Therefore, you may use
* this Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software. If no license
* agreement applies, then any use, reproduction, modification, translation, or
* compilation of this Software is prohibited without the express written
* permission of Infineon.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
* IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
* THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
* SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
* Infineon reserves the right to make changes to the Software without notice.
* You are responsible for properly designing, programming, and testing the
* functionality and safety of your intended application of the Software, as
* well as complying with any legal requirements related to its use. Infineon
* does not guarantee that the Software will be free from intrusion, data theft
* or loss, or other breaches ("Security Breaches"), and Infineon shall have
* no liability arising out of any Security Breaches. Unless otherwise
* explicitly approved by Infineon, the Software may not be used in any
* application where a failure of the Product or any consequences of the use
* thereof can reasonably be expected to result in personal injury.
*******************************************************************************/

#include "cy_retarget_io.h"
#include <stdbool.h>
#include <stdlib.h>
#include "cy_utils.h"
#if defined(COMPONENT_MTB_HAL)
#include "mtb_hal_hw_types.h"
#include "mtb_hal_uart.h"
#include "mtb_hal_system.h"
#elif defined (CY_USING_HAL)
#include "cyhal_hw_types.h"
#include "cyhal_uart.h"
#include "cyhal_system.h"
#endif //defined(COMPONENT_MTB_HAL)


#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && defined(__GNUC__) && \
    !defined(__ARMCC_VERSION) && !defined(__clang__)

// The HAL UART driver is not necessarily thread-safe. To avoid concurrent
// access, the ARM and IAR libraries use mutexes to control access to stdio
// streams. For Newlib, the mutex must be implemented in _write(). For all
// libraries, the program must start the RTOS kernel before calling any stdio
// functions.

#include "cyabs_rtos.h"

static cy_mutex_t cy_retarget_io_mutex;
static bool       cy_retarget_io_mutex_initialized = false;
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_init
//--------------------------------------------------------------------------------------------------
static cy_rslt_t cy_retarget_io_mutex_init(void)
{
    cy_rslt_t rslt;
    if (cy_retarget_io_mutex_initialized)
    {
        rslt = CY_RSLT_SUCCESS;
    }
    else if (CY_RSLT_SUCCESS == (rslt = cy_rtos_init_mutex(&cy_retarget_io_mutex)))
    {
        cy_retarget_io_mutex_initialized = true;
    }
    return rslt;
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_acquire
//--------------------------------------------------------------------------------------------------
static void cy_retarget_io_mutex_acquire(void)
{
    CY_ASSERT(cy_retarget_io_mutex_initialized);
    cy_rslt_t rslt = cy_rtos_get_mutex(&cy_retarget_io_mutex, CY_RTOS_NEVER_TIMEOUT);
    if (rslt != CY_RSLT_SUCCESS)
    {
        abort();
    }
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_release
//--------------------------------------------------------------------------------------------------
static void cy_retarget_io_mutex_release(void)
{
    CY_ASSERT(cy_retarget_io_mutex_initialized);
    cy_rslt_t rslt = cy_rtos_set_mutex(&cy_retarget_io_mutex);
    if (rslt != CY_RSLT_SUCCESS)
    {
        abort();
    }
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_deinit
//--------------------------------------------------------------------------------------------------
static void cy_retarget_io_mutex_deinit(void)
{
    CY_ASSERT(cy_retarget_io_mutex_initialized);
    cy_rslt_t rslt = cy_rtos_deinit_mutex(&cy_retarget_io_mutex);
    if (rslt != CY_RSLT_SUCCESS)
    {
        abort();
    }
    cy_retarget_io_mutex_initialized = false;
}


#else // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && defined(__GNUC__) &&
// !defined(__ARMCC_VERSION) && !defined(__clang__)
#ifdef __ICCARM__
// Ignore unused functions
#pragma diag_suppress=Pe177
#endif
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_init
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t cy_retarget_io_mutex_init(void)
{
    return CY_RSLT_SUCCESS;
}


#if defined(__ARMCC_VERSION) || defined(__llvm__) // ARM-MDK or LLVM ARM
__attribute__((unused))
#endif
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_acquire
//--------------------------------------------------------------------------------------------------
static inline void cy_retarget_io_mutex_acquire(void)
{
}


#if defined(__ARMCC_VERSION) || defined(__llvm__) // ARM-MDK or LLVM ARM
__attribute__((unused))
#endif
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_release
//--------------------------------------------------------------------------------------------------
static inline void cy_retarget_io_mutex_release(void)
{
}


#if defined(__ARMCC_VERSION) || defined(__llvm__) // ARM-MDK or LLVM ARM
__attribute__((unused))
#endif
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_mutex_deinit
//--------------------------------------------------------------------------------------------------
static inline void cy_retarget_io_mutex_deinit(void)
{
}


#endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && defined(__GNUC__) &&
// !defined(__ARMCC_VERSION) && !defined(__clang__)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(COMPONENT_MTB_HAL)
// UART HAL object used by BSP for Debug UART port
static mtb_hal_uart_t* cy_retarget_io_uart_obj = NULL;
#elif defined(CY_USING_HAL)
// UART HAL object used by BSP for Debug UART port
cyhal_uart_t cy_retarget_io_uart_obj;
#else
// SCB address that will be used for retarget-io UART
static CySCB_Type* cy_retarget_io_uart = NULL;
#endif


// Tracks the previous character sent to output stream
#ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
static char cy_retarget_io_stdout_prev_char = 0;
#endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

//--------------------------------------------------------------------------------------------------
// cy_retarget_io_getchar
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t cy_retarget_io_getchar(char* c)
{
    #if defined(COMPONENT_MTB_HAL)
    CY_ASSERT(NULL != cy_retarget_io_uart_obj);
    return mtb_hal_uart_get(cy_retarget_io_uart_obj, (uint8_t*)c, 0);
    #elif defined(CY_USING_HAL)
    return cyhal_uart_getc(&cy_retarget_io_uart_obj, (uint8_t*)c, 0);
    #else
    uint32_t read_value = Cy_SCB_UART_Get(cy_retarget_io_uart);
    //Wait until the character is received
    while (CY_SCB_UART_RX_NO_DATA == read_value)
    {
        read_value = Cy_SCB_UART_Get(cy_retarget_io_uart);
    }
    *c = (uint8_t)read_value;
    return CY_RSLT_SUCCESS;
    #endif // if defined(COMPONENT_MTB_HAL)
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_putchar
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t cy_retarget_io_putchar(char c)
{
    #if defined(COMPONENT_MTB_HAL)
    CY_ASSERT(NULL != cy_retarget_io_uart_obj);
    return mtb_hal_uart_put(cy_retarget_io_uart_obj, (uint8_t)c);
    #elif defined(CY_USING_HAL)
    return cyhal_uart_putc(&cy_retarget_io_uart_obj, (uint8_t)c);
    #else
    uint32_t count = 0UL;
    while (count == 0UL)
    {
        count = Cy_SCB_UART_Put(cy_retarget_io_uart, c);
    }
    return CY_RSLT_SUCCESS;
    #endif //defined(COMPONENT_MTB_HAL)
}


#if defined(__ARMCC_VERSION) // ARM-MDK
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_fputc_common
//--------------------------------------------------------------------------------------------------
static inline int cy_retarget_io_fputc_common(int ch, FILE* f)
{
    (void)f;
    cy_rslt_t rslt = CY_RSLT_SUCCESS;
    #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
    if (((char)ch == '\n') && (cy_retarget_io_stdout_prev_char != '\r'))
    {
        rslt = cy_retarget_io_putchar('\r');
    }
    #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

    if (CY_RSLT_SUCCESS == rslt)
    {
        rslt = cy_retarget_io_putchar(ch);
    }

    #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
    if (CY_RSLT_SUCCESS == rslt)
    {
        cy_retarget_io_stdout_prev_char = (char)ch;
    }
    #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

    return (CY_RSLT_SUCCESS == rslt) ? ch : EOF;
}


#if defined (COMPONENT_MTB_HAL)
//--------------------------------------------------------------------------------------------------
// $Sub$$fputc
//--------------------------------------------------------------------------------------------------
int $Sub$$fputc(int ch, FILE* f)
#else
//--------------------------------------------------------------------------------------------------
// fputc
//--------------------------------------------------------------------------------------------------
int fputc(int ch, FILE* f)
#endif /* defined(COMPONENT_MTB_HAL) */
{
    return cy_retarget_io_fputc_common(ch, f);
}


#if defined (COMPONENT_MTB_HAL)
//--------------------------------------------------------------------------------------------------
// $Sub$$fputc unlocked
//--------------------------------------------------------------------------------------------------
int $Sub$$_fputc$unlocked(int ch, FILE* f)
#else
//--------------------------------------------------------------------------------------------------
// _fputc$unlocked
//--------------------------------------------------------------------------------------------------
int _fputc$unlocked(int ch, FILE* f)
#endif /* defined(COMPONENT_MTB_HAL) */
{
    return cy_retarget_io_fputc_common(ch, f);
}


#elif defined(__llvm__)

//--------------------------------------------------------------------------------------------------
// uart_putc
//--------------------------------------------------------------------------------------------------
static int uart_putc(char c, FILE* file)
{
    (void)file;
    cy_rslt_t rslt = CY_RSLT_SUCCESS;
    #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
    if (((c == '\n') && (cy_retarget_io_stdout_prev_char != '\r')))
    {
        rslt = cy_retarget_io_putchar('\r');
    }
    #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF
    if (CY_RSLT_SUCCESS == rslt)
    {
        cy_retarget_io_putchar(c);
    }
    #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
    if (CY_RSLT_SUCCESS == rslt)
    {
        cy_retarget_io_stdout_prev_char = c;
    }
    #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

    return (CY_RSLT_SUCCESS == rslt) ? c : EOF;
}


//--------------------------------------------------------------------------------------------------
// uart_getc
//--------------------------------------------------------------------------------------------------
static int uart_getc(FILE* file)
{
    (void)file;
    char c;
    cy_rslt_t rslt = cy_retarget_io_getchar(&c);
    return (CY_RSLT_SUCCESS == rslt) ? c : EOF;
}


static FILE __stdio = FDEV_SETUP_STREAM(uart_putc,
                                        uart_getc,
                                        NULL,
                                        _FDEV_SETUP_RW);

FILE* const stdin = &__stdio;

__strong_reference(stdin, stdout);

__strong_reference(stdin, stderr);

#elif defined (__ICCARM__) // IAR
    #include <yfuns.h>

//--------------------------------------------------------------------------------------------------
// __write
//--------------------------------------------------------------------------------------------------
size_t __write(int handle, const unsigned char* buffer, size_t size)
{
    size_t nChars = 0;
    // This template only writes to "standard out", for all other file handles it returns failure.
    if (handle != _LLIO_STDOUT)
    {
        return (_LLIO_ERROR);
    }
    if (buffer != NULL)
    {
        cy_rslt_t rslt = CY_RSLT_SUCCESS;
        for (; nChars < size; ++nChars)
        {
            #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            if ((*buffer == '\n') && (cy_retarget_io_stdout_prev_char != '\r'))
            {
                rslt = cy_retarget_io_putchar('\r');
            }
            #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

            if (rslt == CY_RSLT_SUCCESS)
            {
                rslt = cy_retarget_io_putchar(*buffer);
            }

            if (rslt != CY_RSLT_SUCCESS)
            {
                break;
            }

            #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            cy_retarget_io_stdout_prev_char = *buffer;
            #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            ++buffer;
        }
    }
    return (nChars);
}


#else // (__GNUC__)  GCC
#if !defined(CY_RETARGET_IO_NO_FLOAT)
// Add an explicit reference to the floating point printf library to allow the usage of floating
// point conversion specifier.
__asm(".global _printf_float");
#endif
//--------------------------------------------------------------------------------------------------
// _write
//--------------------------------------------------------------------------------------------------
int32_t _write(int32_t fd, const cy_char8_t* ptr, int32_t len)
{
    int32_t nChars = 0;
    (void)fd;
    if (ptr != NULL)
    {
        cy_rslt_t rslt = CY_RSLT_SUCCESS;
        cy_retarget_io_mutex_acquire();
        for (; nChars < len; ++nChars)
        {
            #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            if ((*ptr == '\n') && (cy_retarget_io_stdout_prev_char != '\r'))
            {
                rslt = cy_retarget_io_putchar('\r');
            }
            #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF

            if (CY_RSLT_SUCCESS == rslt)
            {
                rslt = cy_retarget_io_putchar((uint32_t)*ptr);
            }

            if (CY_RSLT_SUCCESS != rslt)
            {
                break;
            }

            #ifdef CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            cy_retarget_io_stdout_prev_char = *ptr;
            #endif // CY_RETARGET_IO_CONVERT_LF_TO_CRLF
            ++ptr;
        }
        cy_retarget_io_mutex_release();
    }
    return (nChars);
}


#endif // if defined(__ARMCC_VERSION)


#if defined(__ARMCC_VERSION) // ARM-MDK
#if defined (COMPONENT_MTB_HAL)
//--------------------------------------------------------------------------------------------------
// $Sub$$fgetc
//--------------------------------------------------------------------------------------------------
int $Sub$$fgetc(FILE* f)
#else
//--------------------------------------------------------------------------------------------------
// fgetc
//--------------------------------------------------------------------------------------------------
int fgetc(FILE* f)
#endif /* defined(COMPONENT_MTB_HAL) */
{
    (void)f;
    char c;
    cy_rslt_t rslt = cy_retarget_io_getchar(&c);
    return (CY_RSLT_SUCCESS == rslt) ? c : EOF;
}


#if defined (COMPONENT_MTB_HAL)
//--------------------------------------------------------------------------------------------------
// $Sub$$_fgetc$unlocked
//--------------------------------------------------------------------------------------------------
int $Sub$$_fgetc$unlocked(FILE* f)
#else
//--------------------------------------------------------------------------------------------------
// _fgetc$unlocked
//--------------------------------------------------------------------------------------------------
int _fgetc$unlocked(FILE* f)
#endif /* defined(COMPONENT_MTB_HAL) */
{
    (void)f;
    char c;
    cy_rslt_t rslt = cy_retarget_io_getchar(&c);
    return (CY_RSLT_SUCCESS == rslt) ? c : EOF;
}


#elif defined (__ICCARM__) // IAR
//--------------------------------------------------------------------------------------------------
// __read
//--------------------------------------------------------------------------------------------------
size_t __read(int handle, unsigned char* buffer, size_t size)
{
    // This template only reads from "standard in", for all other file handles it returns failure.
    if ((handle != _LLIO_STDIN) || (buffer == NULL))
    {
        return (_LLIO_ERROR);
    }
    else
    {
        cy_rslt_t rslt = cy_retarget_io_getchar((char*)buffer);
        return (CY_RSLT_SUCCESS == rslt) ? 1 : 0;
    }
}


#elif defined(__llvm__)
// Nothing to do, putc/getc all defined in the first #if/#else section.

#else // (__GNUC__)  GCC
#if !defined(CY_RETARGET_IO_NO_FLOAT)
// Add an explicit reference to the floating point scanf library to allow the usage of floating
// point conversion specifier.
__asm(".global _scanf_float");
#endif
//--------------------------------------------------------------------------------------------------
// _read
//--------------------------------------------------------------------------------------------------
int32_t _read(int32_t fd, cy_char8_t* ptr, int32_t len)
{
    (void)fd;

    int32_t nChars = 0;
    if (ptr != NULL)
    {
        cy_rslt_t rslt;
        do
        {
            rslt = cy_retarget_io_getchar(ptr);
            if (rslt == CY_RSLT_SUCCESS)
            {
                ++nChars;
                if ((*ptr == '\n') || (*ptr == '\r'))
                {
                    break;
                }
                ptr++;
            }
        } while ((rslt == CY_RSLT_SUCCESS) && (nChars < len));
    }

    return (nChars);
}


#endif // if defined(__ARMCC_VERSION)

#if defined(__ARMCC_VERSION) // ARM-MDK
// Include _sys_* prototypes provided by ARM Compiler runtime library
    #include <rt_sys.h>

// Prevent linkage of library functions that use semihosting calls
__asm(".global __use_no_semihosting\n\t");

// Enable the linker to select an optimized library that does not include code to handle input
// arguments to main()
__asm(".global __ARM_use_no_argv\n\t");

//--------------------------------------------------------------------------------------------------
// _sys_open
//
// Open a file: dummy implementation.
// Everything goes to the same output, no need to translate the file names
// (__stdin_name/__stdout_name/__stderr_name) to descriptor numbers
//--------------------------------------------------------------------------------------------------
FILEHANDLE __attribute__((weak)) _sys_open(const char* name, int openmode)
{
    (void)name;
    (void)openmode;
    return 1;
}


//--------------------------------------------------------------------------------------------------
// _sys_close
//
// Close a file: dummy implementation.
//--------------------------------------------------------------------------------------------------
int __attribute__((weak)) _sys_close(FILEHANDLE fh)
{
    (void)fh;
    return 0;
}


//--------------------------------------------------------------------------------------------------
// _sys_write
//
// Write to a file: dummy implementation.
// The low-level function fputc retargets output to use UART TX
//--------------------------------------------------------------------------------------------------
int __attribute__((weak)) _sys_write(FILEHANDLE fh, const unsigned char* buf, unsigned len,
                                     int mode)
{
    (void)fh;
    (void)buf;
    (void)len;
    (void)mode;
    return 0;
}


//--------------------------------------------------------------------------------------------------
// _sys_read
//
// Read from a file: dummy implementation.
// The low-level function fputc retargets input to use UART RX
//--------------------------------------------------------------------------------------------------
int __attribute__((weak)) _sys_read(FILEHANDLE fh, unsigned char* buf, unsigned len, int mode)
{
    (void)fh;
    (void)buf;
    (void)len;
    (void)mode;
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _ttywrch
//
// Write a character to the output channel: dummy implementation.
//--------------------------------------------------------------------------------------------------
void __attribute__((weak)) _ttywrch(int ch)
{
    (void)ch;
}


//--------------------------------------------------------------------------------------------------
// _sys_istty
//
// Check if the file is connected to a terminal: dummy implementation
//--------------------------------------------------------------------------------------------------
int __attribute__((weak)) _sys_istty(FILEHANDLE fh)
{
    (void)fh;
    return 0;
}


//--------------------------------------------------------------------------------------------------
// _sys_seek
//
// Move the file position to a given offset: dummy implementation
//--------------------------------------------------------------------------------------------------
int __attribute__((weak)) _sys_seek(FILEHANDLE fh, long pos)
{
    (void)fh;
    (void)pos;
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _sys_flen
// Return the current length of a file: dummy implementation
//--------------------------------------------------------------------------------------------------
long __attribute__((weak)) _sys_flen(FILEHANDLE fh)
{
    (void)fh;
    return 0;
}


//--------------------------------------------------------------------------------------------------
// _sys_exit
//
// Terminate the program: dummy implementation
//--------------------------------------------------------------------------------------------------
void __attribute__((weak)) _sys_exit(int returncode)
{
    (void)returncode;
    for (;;)
    {
        // Halt here forever
    }
}


//--------------------------------------------------------------------------------------------------
// _sys_command_string
//
// Return a pointer to the command line: dummy implementation
//--------------------------------------------------------------------------------------------------
char __attribute__((weak)) *_sys_command_string(char* cmd, int len)
{
    (void)cmd;
    (void)len;
    return NULL;
}


#endif // ARM-MDK

#if defined (COMPONENT_MTB_HAL)
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_retarget_io_init(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    cy_retarget_io_uart_obj = obj;
    return cy_retarget_io_mutex_init();
}


#elif (defined(CY_USING_HAL) || defined(DOXYGEN))
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_init_fc
//
// Enables user to provide flow control pins during initialization
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_retarget_io_init_fc(cyhal_gpio_t tx, cyhal_gpio_t rx, cyhal_gpio_t cts,
                                 cyhal_gpio_t rts, uint32_t baudrate)
{
    const cyhal_uart_cfg_t uart_config =
    {
        .data_bits          = 8,
        .stop_bits          = 1,
        .parity             = CYHAL_UART_PARITY_NONE,
        .rx_buffer          = NULL,
        .rx_buffer_size     = 0
    };

    #if (CYHAL_API_VERSION >= 2)
    cy_rslt_t result = cyhal_uart_init(&cy_retarget_io_uart_obj, tx, rx, cts, rts, NULL,
                                       &uart_config);
    #else // HAL API before version 2
    cy_rslt_t result = cyhal_uart_init(&cy_retarget_io_uart_obj, tx, rx, NULL, &uart_config);
    if (result == CY_RSLT_SUCCESS)
    {
        result = cyhal_uart_set_flow_control(&cy_retarget_io_uart_obj, cts, rts);
    }
    #endif

    if (result == CY_RSLT_SUCCESS)
    {
        result = cyhal_uart_set_baud(&cy_retarget_io_uart_obj, baudrate, NULL);
    }

    if (result == CY_RSLT_SUCCESS)
    {
        result = cy_retarget_io_mutex_init();
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_init_hal
//
// Initailize retarget-io mutex for thead-safe during initialization
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_retarget_io_init_hal(void)
{
    return cy_retarget_io_mutex_init();
}


#else // if defined(COMPONENT_MTB_HAL)

//--------------------------------------------------------------------------------------------------
// cy_retarget_io_init
//
// Initializes the UART for retarget-io.  UART must already be initialized and enabled.
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_retarget_io_init(CySCB_Type* uart)
{
    if (uart == NULL)
    {
        return CY_RETARGET_IO_RSLT_NULL_UART_PTR;
    }
    else
    {
        cy_retarget_io_uart = uart;
        return cy_retarget_io_mutex_init();
    }
}


#endif // defined(COMPONENT_MTB_HAL)


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_is_tx_active
//--------------------------------------------------------------------------------------------------
bool cy_retarget_io_is_tx_active(void)
{
    #if defined(COMPONENT_MTB_HAL)
    CY_ASSERT(NULL != cy_retarget_io_uart_obj);
    return mtb_hal_uart_is_tx_active(cy_retarget_io_uart_obj);
    #elif defined (CY_USING_HAL)
    return cyhal_uart_is_tx_active(&cy_retarget_io_uart_obj);
    #else
    return !Cy_SCB_IsTxComplete(cy_retarget_io_uart);
    #endif
}


//--------------------------------------------------------------------------------------------------
// cy_retarget_io_deinit
//--------------------------------------------------------------------------------------------------
void cy_retarget_io_deinit(void)
{
    // Since the largest hardware buffer would be 256 bytes
    // it takes about 500 ms to transmit the 256 bytes at 9600 baud.
    // Thus 1000 ms gives roughly 50% padding to this time.
    int32_t timeout_remaining_ms = 1000;
    while (timeout_remaining_ms > 0)
    {
        if (!cy_retarget_io_is_tx_active())
        {
            break;
        }
        #if defined(COMPONENT_MTB_HAL)
        mtb_hal_system_delay_ms(1);
        #elif defined(CY_USING_HAL)
        cyhal_system_delay_ms(1);
        #else
        Cy_SysLib_Delay(1);
        #endif //defined(COMPONENT_MTB_HAL)
        timeout_remaining_ms--;
    }
    CY_ASSERT(timeout_remaining_ms != 0);
    #if defined(COMPONENT_MTB_HAL)
    cy_retarget_io_uart_obj = NULL;
    #elif defined(CY_USING_HAL)
    cyhal_uart_free(&cy_retarget_io_uart_obj);
    #else
    cy_retarget_io_uart = NULL;
    #endif //defined(COMPONENT_MTB_HAL)
    cy_retarget_io_mutex_deinit();
}


#if defined(COMPONENT_MTB_HAL) || defined(DOXYGEN)
//--------------------------------------------------------------------------------------------------
// cy_retarget_io_change_baud_rate
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_retarget_io_change_baud_rate(uint32_t baud_rate, uint32_t* actual_baud)
{
    if (cy_retarget_io_uart_obj == NULL)
    {
        return CY_RSLT_TYPE_ERROR;
    }

    while (cy_retarget_io_is_tx_active() == true)
    {
        // Wait for transmission to complete
    }

    return (mtb_hal_uart_set_baud(cy_retarget_io_uart_obj, baud_rate, actual_baud));
}


#endif // defined(COMPONENT_MTB_HAL) || defined(DOXYGEN)

#if defined(__cplusplus)
}
#endif
