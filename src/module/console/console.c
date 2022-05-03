/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <finsh.h>
#include <firmament.h>
#include <string.h>

#include "hal/serial/serial.h"

#define CONSOLE_BUFF_SIZE 1024

/* console write hook function, can be reimplemented by other modules. */
RT_WEAK void console_write_hook(const char* content, uint32_t len);

static rt_device_t console_dev;
static char console_buffer[CONSOLE_BUFF_SIZE];

/**
 * Write raw data to console device.
 *
 * @param content data to be written
 * @param len length of data
 *
 * @return length has been written.
 */
int console_write(const char* content, uint32_t len)
{
    if (console_dev == NULL) {
        return 0;
    }

    /* write content into console device */
    uint32_t size = rt_device_write(console_dev, 0, (void*)content, len);

    /* call write hook */
    if (console_write_hook)
        console_write_hook(content, len);

    return size;
}

/**
 * Console print arguments.
 *
 * @param fmt string format
 * @param args arguments list
 *
 * @return length of output.
 */
int console_print_args(const char* fmt, va_list args)
{
    int length;

    length = vsnprintf(console_buffer, CONSOLE_BUFF_SIZE, fmt, args);

    return console_write(console_buffer, length);
}

/**
 * Console printf.
 *
 * @param fmt string format
 *
 * @return length of output.
 */
int console_printf(const char* fmt, ...)
{
    va_list args;
    int length;

    va_start(args, fmt);
    length = vsnprintf(console_buffer, CONSOLE_BUFF_SIZE, fmt, args);
    va_end(args);

    return console_write(console_buffer, length);
}

/**
 * Console print line.
 *
 * @param fmt string format
 * @return length of output.
 */
int console_println(const char* fmt, ...)
{
    va_list args;
    int length;

    va_start(args, fmt);
    length = vsnprintf(console_buffer, CONSOLE_BUFF_SIZE - 1, fmt, args);
    va_end(args);

    console_buffer[length++] = '\n';

    return console_write(console_buffer, length);
}

/**
 * Format string into the buffer.
 */
void console_format(char* buffer, const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);
}

/**
 * Get current console device.
 *
 * @return current console device. NULL indicates no device.
 */
rt_device_t console_get_device(void)
{
    return console_dev;
}

/**
 * Set console to a specific device.
 * @note console input/output will be enabled as well
 *
 * @return FMT Errors.
 */
fmt_err_t console_set_device(const char* device_name)
{
    rt_device_t new;
    fmt_err_t err;

    new = rt_device_find(device_name);
    if (new == RT_NULL) {
        /* can not find console device */
        return FMT_EINVAL;
    }

    /* switch console to new device */
    console_dev = new;
    /* enable console */
    err = console_enable_input();

    return err;
}

/**
 * Enable console input and output.
 * @note console_dev should be set already
 *
 * @return FMT Errors.
 */
fmt_err_t console_enable_input(void)
{
    uint16_t oflag = RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_STREAM;

    if (console_dev == RT_NULL) {
        return FMT_EINVAL;
    }

    if ((console_dev->open_flag & RT_DEVICE_OFLAG_OPEN)
        && (console_dev->open_flag != oflag)) {
        /* reopen console device */
        rt_device_close(console_dev);
    }
    /* open console device */
    if (rt_device_open(console_dev, oflag) != RT_EOK) {
        /* fail to open */
        return FMT_ERROR;
    }

    /* set rt console device to enable kernel printf, e.g, rt_kprintf */
    rt_set_console_device(console_dev);
    /* mount finsh to current console device */
    finsh_set_device_without_open(console_dev->parent.name);

    return FMT_EOK;
}

/**
 * Initialize the console device.
 * @note only console output is enabled
 *
 * @return FMT Errors.
 */
fmt_err_t console_init(void)
{
    /* console use serial0 by default */
    console_dev = rt_device_find("serial0");
    if (console_dev == RT_NULL) {
        /* can not find console device */
        return FMT_EEMPTY;
    }

    /* here we only enable console output, the console input should be enabled specifically */
    if (rt_device_open(console_dev, RT_DEVICE_OFLAG_WRONLY | RT_DEVICE_FLAG_STREAM) != RT_EOK) {
        return FMT_ERROR;
    }

    /* set rt console device to enable kernel printf, e.g, rt_kprintf */
    rt_set_console_device(console_dev);

    return FMT_EOK;
}
