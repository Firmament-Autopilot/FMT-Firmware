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

#include "hal/serial.h"

#define CONSOLE_BUFF_SIZE 1024
#define CONSOLE_BAUD_RATE 57600

#define CONSOLE_OFLAG (RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_STREAM)

static rt_device_t _console_dev = NULL;
static char _buffer[CONSOLE_BUFF_SIZE];

uint32_t console_write(const char* content, uint32_t len)
{
    if (boot_logging) {
        /* push to boot log buffer if boot_logging flag is set */
        boot_log_push(content, len);
    }

    return rt_device_write(_console_dev, 0, (void*)content, len);
}

uint32_t console_printf(const char* fmt, ...)
{
    va_list args;
    int length;

    va_start(args, fmt);
    length = vsnprintf(_buffer, CONSOLE_BUFF_SIZE, fmt, args);
    va_end(args);

    return console_write(_buffer, length);
}

uint32_t console_println(const char* fmt, ...)
{
    va_list args;
    int length;

    va_start(args, fmt);
    length = vsnprintf(_buffer, CONSOLE_BUFF_SIZE - 1, fmt, args);
    va_end(args);

    _buffer[length++] = '\n';

    return console_write(_buffer, length);
}

void console_format(char* buffer, const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);
}

fmt_err console_mount_shell(rt_device_t dev)
{
    rt_err_t err;

    /* if dev is null, mount to current console device */
    if (dev == RT_NULL && _console_dev) {
        dev = _console_dev;
    }

    if (dev == RT_NULL) {
        return FMT_ERROR;
    }

    if (!(dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
        /* device is not opened */
        return FMT_ERROR;
    }

    if (dev->open_flag != CONSOLE_OFLAG) {
        /* if open flag is different, reopen it */
        rt_device_close(dev);
        err = rt_device_open(dev, CONSOLE_OFLAG);

        if (err != RT_EOK) {
            return FMT_ERROR;
        }
    }

    /* mount finsh to current console device */
    finsh_set_device(dev->parent.name);

    return FMT_EOK;
}

fmt_err console_set_device(char* dev_name)
{
    rt_device_t new;

    new = rt_device_find(dev_name);

    if (new == RT_NULL) {
        /* can not find console device */
        return FMT_ERROR;
    }

    if (!(new->open_flag& RT_DEVICE_OFLAG_OPEN)) {
        if (rt_device_open(new, CONSOLE_OFLAG) != RT_EOK) {
            return FMT_ERROR;
        }
    } else {
        if (new->open_flag != CONSOLE_OFLAG) {
            /* open flag is different, reopen */
            rt_device_close(new);

            if (rt_device_open(new, CONSOLE_OFLAG) != RT_EOK) {
                return FMT_ERROR;
            }
        }
    }

    rt_console_set_device(dev_name);
    console_mount_shell(new);

    /* close old console device */
    if (_console_dev) {
        rt_device_close(_console_dev);
    }

    _console_dev = new;

    return FMT_EOK;
}

fmt_err console_init(char* dev_name)
{
    serial_dev_t serial_dev;

    _console_dev = rt_device_find(dev_name);

    if (_console_dev == RT_NULL) {
        /* can not find console device */
        return FMT_ERROR;
    }

    /* here we only enable console output, the input function will be enabled in shell mount operation */
    if (rt_device_open(_console_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_STREAM) != RT_EOK) {
        return FMT_ERROR;
    }

    /* set serial baudrate if needed */
    serial_dev = (serial_dev_t)_console_dev;
    if (serial_dev->config.baud_rate != CONSOLE_BAUD_RATE) {
        struct serial_configure pconfig = serial_dev->config;
        
        pconfig.baud_rate = CONSOLE_BAUD_RATE;
        if (rt_device_control(_console_dev, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    /* set rt console device to enable kernel printf, e.g, rt_kprintf */
    rt_console_set_device(dev_name);

    return FMT_EOK;
}
