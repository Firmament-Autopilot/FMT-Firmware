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
#include <firmament.h>

#include <finsh.h>
#include <string.h>

#include "hal/serial.h"
#include "module/utils/device_mq.h"

#define CONSOLE_BUFF_SIZE      1024
#define CONSOLE_BAUD_RATE      57600
#define CONSOLE_MAX_DEVICE_NUM 5

#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_TYPE_IS(_idx, _name) MATCH(_console_device_list[_idx].type, #_name)

#define CONSOLE_OFLAG (RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_STREAM)

typedef struct {
    uint32_t baudrate;
    bool auto_switch;
} console_serial_dev_config;

typedef struct {
    bool auto_switch;
} console_mavlink_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} console_device_info;

static rt_device_t _console_dev = NULL;
static int _console_dev_idx = -1;
static uint8_t _console_device_num = 0;
static console_device_info _console_device_list[CONSOLE_MAX_DEVICE_NUM] = { 0 };
static char _buffer[CONSOLE_BUFF_SIZE];

static char* _strdup(const char* str1)
{
    char* str = rt_malloc(strlen(str1) + 1); // 1 for '/0'

    if (str) {
        strcpy(str, str1);
    }

    return str;
}

static void _init_device_list(void)
{
    for (int i = 0; i < CONSOLE_MAX_DEVICE_NUM; i++) {
        _console_device_list[i].type = NULL;
        _console_device_list[i].name = NULL;
        _console_device_list[i].config = NULL;
        _console_device_num = 0;
    }
}

static void _handle_device_status_change(void* msg)
{
    int idx;
    device_status status = *((device_status*)msg);

    for (idx = 0; idx < _console_device_num; idx++) {
        if (rt_device_find(_console_device_list[idx].name) == status.device) {
            /* if data received, switch console to this device */
            if (status.status == DEVICE_STATUS_RX) {
                console_switch_device(idx);
                return;
            }
        }
    }
}

static rt_err_t _console_device_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_err_t rt_err = RT_EOK;

    /* if it's not the current working console device, switch to it */
    if (_console_dev != dev) {
        device_mq_notify(dev, DEVICE_STATUS_RX);
    }

    return rt_err;
}

static fmt_err _set_auto_switch_indicator(void)
{
    rt_err_t rt_err;
    int idx;

    for (idx = 0; idx < _console_device_num; idx++) {
        if (idx == console_get_device_id(_console_dev)) {
            /* do not set rx indicator for current console deivce */
            /* because shell is using that */
            continue;
        }

        if (DEVICE_TYPE_IS(idx, serial)) {
            console_serial_dev_config* config = (console_serial_dev_config*)_console_device_list[idx].config;

            if (config->auto_switch) {
                rt_err = rt_device_set_rx_indicate(console_get_device(idx), _console_device_rx_ind);
                if (rt_err != RT_EOK) {
                    return FMT_ERROR;
                }
            }
        } else if (DEVICE_TYPE_IS(idx, mavlink)) {
            console_mavlink_dev_config* config = (console_mavlink_dev_config*)_console_device_list[idx].config;

            if (config->auto_switch) {
                rt_err = rt_device_set_rx_indicate(console_get_device(idx), _console_device_rx_ind);
                if (rt_err != RT_EOK) {
                    return FMT_ERROR;
                }
            }
        } else {
            /* unknown device type */
            return FMT_ERROR;
        }
    }

    return FMT_EOK;
}

static fmt_err _console_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err err = FMT_EOK;
    int i;
    const char* key;
    const char* raw;

    /* get device type */
    if ((raw = toml_raw_in(curtab, "type")) != 0) {
        if (toml_rtos(raw, &_console_device_list[idx].type) != 0) {
            console_printf("Error: fail to parse type value\n");
            err = FMT_ERROR;
        }

        if (DEVICE_TYPE_IS(idx, serial)) {
            console_serial_dev_config serial_default_config = {
                .baudrate = CONSOLE_BAUD_RATE,
                .auto_switch = true
            };
            _console_device_list[idx].config = rt_malloc(sizeof(console_serial_dev_config));

            /* set default value */
            if (_console_device_list[idx].config)
                *(console_serial_dev_config*)_console_device_list[idx].config = serial_default_config;
        } else if (DEVICE_TYPE_IS(idx, mavlink)) {
            console_mavlink_dev_config mavlink_default_config = {
                .auto_switch = true
            };
            _console_device_list[idx].config = rt_malloc(sizeof(console_mavlink_dev_config));

            /* set default value */
            if (_console_device_list[idx].config)
                *(console_mavlink_dev_config*)_console_device_list[idx].config = mavlink_default_config;
        } else {
            console_printf("Error: unknown device type: %s\n", _console_device_list[idx].type);
            err = FMT_ERROR;
        }

        if (_console_device_list[idx].config == NULL) {
            console_printf("Error: fail to malloc memory\n");
            err = FMT_ERROR;
        }
    } else {
        console_printf("Error: fail to parse type value\n");
        err = FMT_ERROR;
    }

    if (err != FMT_EOK) {
        return err;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (0 != (raw = toml_raw_in(curtab, key))) {
            if (MATCH(key, "type")) {
                /* already handled */
                continue;
            }

            /* parse serial device */
            if (DEVICE_TYPE_IS(idx, serial)) {
                console_serial_dev_config* config = (console_serial_dev_config*)_console_device_list[idx].config;

                if (MATCH(key, "name")) {
                    if (toml_rtos(raw, &_console_device_list[idx].name) != 0) {
                        console_printf("Error: fail to parse name value\n");
                        return FMT_ERROR;
                    }
                } else if (MATCH(key, "baudrate")) {
                    int64_t ival;

                    if (toml_rtoi(raw, &ival) != 0) {
                        console_printf("Error: fail to parse baudrate value\n");
                        continue;
                    }
                    config->baudrate = (uint32_t)ival;

                    _console_device_num = idx + 1;
                } else if (MATCH(key, "auto-switch")) {
                    int bval;
                    console_printf("222\n");
                    if (toml_rtob(raw, &bval) != 0) {
                        console_printf("Error: fail to parse auto-switch value\n");
                        continue;
                    }
                    config->auto_switch = bval ? true : false;

                    if (config->auto_switch) {
                        /* monitor device status */
                        if (device_mq_register(_console_device_list[idx].name, _handle_device_status_change) != FMT_EOK) {
                            console_printf("Error: fail to register %s status msg\n", _console_device_list[idx].name);
                        }
                    }
                } else {
                    console_printf("Error: unknown config key: %s\n", key);
                    continue;
                }
            }

            /* parse mavlink device */
            if (DEVICE_TYPE_IS(idx, mavlink)) {
                console_mavlink_dev_config* config = (console_mavlink_dev_config*)_console_device_list[idx].config;

                if (MATCH(key, "name")) {
                    if (toml_rtos(raw, &_console_device_list[idx].name) != 0) {
                        console_printf("Error: fail to parse name value\n");
                        return FMT_ERROR;
                    }
                } else if (MATCH(key, "auto-switch")) {
                    int bval;

                    if (toml_rtob(raw, &bval) != 0) {
                        console_printf("Error: fail to parse auto-switch value\n");
                        continue;
                    }
                    config->auto_switch = bval ? true : false;

                    if (config->auto_switch) {
                        /* monitor device status */
                        if (device_mq_register(_console_device_list[idx].name, _handle_device_status_change) != FMT_EOK) {
                            console_printf("Error: fail to register %s status msg\n", _console_device_list[idx].name);
                        }
                    }
                } else {
                    console_printf("Error: unknown config key: %s\n", key);
                    continue;
                }
            }
        } else {
            console_printf("Error: unknown config key: %s\n", key);
            continue;
        }
    }

    return err;
}

static fmt_err _console_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = _console_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            console_printf("serial device parse fail: %d\n", i);
            continue;
        }

        if (++idx >= CONSOLE_MAX_DEVICE_NUM) {
            break;
        }
    }

    _console_device_num = idx;

    return err;
}

void list_console_devices(void)
{
    for (int i = 0; i < _console_device_num; i++) {
        console_printf("[console d%d]:\n", i);
        console_printf("type:%s\n", _console_device_list[i].type);
        console_printf("name:%s\n", _console_device_list[i].name);
        if (DEVICE_TYPE_IS(i, serial)) {
            console_serial_dev_config* config = (console_serial_dev_config*)_console_device_list[i].config;
            console_printf("baudrate:%d\n", config->baudrate);
            console_printf("auto-switch:%s\n", config->auto_switch ? "true" : "false");
        } else {
            console_mavlink_dev_config* config = (console_mavlink_dev_config*)_console_device_list[i].config;
            console_printf("auto-switch:%s\n", config->auto_switch ? "true" : "false");
        }
        console_printf("\n");
    }
}

rt_device_t console_get_device(int idx)
{
    if (idx == CONSOLE_CURRENT_DEVICE) {
        return _console_dev;
    }

    if (idx >= _console_device_num) {
        return NULL;
    }

    return rt_device_find(_console_device_list[idx].name);
}

int console_get_device_id(rt_device_t device)
{
    int idx;

    for (idx = 0; idx < _console_device_num; idx++) {
        if (rt_device_find(_console_device_list[idx].name) == device) {
            return idx;
        }
    }

    return -1;
}

fmt_err console_switch_device(int idx)
{
    if (idx >= _console_device_num || idx < 0) {
        return FMT_ERROR;
    }

    if (console_set_device(_console_device_list[idx].name) == FMT_EOK) {
        _console_dev_idx = idx;
    } else {
        return FMT_ERROR;
    }

    return _set_auto_switch_indicator();
}

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
    console_enable_shell(new);

    _console_dev = new;

    return FMT_EOK;
}

fmt_err console_enable_shell(rt_device_t dev)
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

/* config console via toml system configuration file */
fmt_err console_toml_init(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    toml_table_t* tab;
    fmt_err err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            /* we get new device configuration, re-init original one */
            _init_device_list();

            if ((arr = toml_array_in(table, key)) != 0) {
                if (toml_array_kind(arr) == 't') {
                    err = _console_parse_devices(arr);
                    if (err != FMT_EOK) {
                        console_printf("parse fail\n");
                    }
                } else {
                    console_printf("Error: wrong element type: %s\n", key);
                    err = FMT_ERROR;
                }
            } else {
                console_printf("Error: wrong element type: %s\n", key);
                err = FMT_ERROR;
            }
        } else if (MATCH(key, "device")) {
            /* we get new device configuration, re-init original one */
            _init_device_list();

            if ((tab = toml_table_in(table, key)) != 0) {
                err = _console_parse_device(tab, 0);
                if (err == FMT_EOK) {
                    _console_device_num = 1;
                }
            } else {
                console_printf("Error: wrong element type: %s\n", key);
                err = FMT_ERROR;
            }
        } else {
            console_printf("Error: unknown config key: %s\n", key);
            err = FMT_ERROR;
        }
    }

    /* open all devices by default */
    for (int i = 0; i < _console_device_num; i++) {
        rt_device_t dev = rt_device_find(_console_device_list[i].name);

        if (dev == NULL) {
            continue;
        }

        if (!(dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
            if (rt_device_open(dev, CONSOLE_OFLAG) != RT_EOK) {
                return FMT_ERROR;
            }
        } else {
            if (dev->open_flag != CONSOLE_OFLAG) {
                /* open flag is different, reopen */
                rt_device_close(dev);

                if (rt_device_open(dev, CONSOLE_OFLAG) != RT_EOK) {
                    return FMT_ERROR;
                }
            }
        }

        if (DEVICE_TYPE_IS(i, serial)) {
            serial_dev_t serial_dev = (serial_dev_t)console_get_device(i);
            console_serial_dev_config* config = (console_serial_dev_config*)_console_device_list[i].config;
            struct serial_configure pconfig = serial_dev->config;

            pconfig.baud_rate = config->baudrate;
            if (rt_device_control(&serial_dev->parent, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
                return FMT_ERROR;
            }
        }
    }

    /* set console device to the first device by default */
    err = console_switch_device(0);

    return err;
}

fmt_err console_init(char* dev_name)
{
    serial_dev_t serial_dev;

    _console_dev = rt_device_find(dev_name);

    if (_console_dev == RT_NULL) {
        /* can not find console device */
        return FMT_ERROR;
    }

    /* here we only enable console output, the input function should be enabled later */
    if (rt_device_open(_console_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_STREAM) != RT_EOK) {
        return FMT_ERROR;
    }

    /* config serial baudrate if needed */
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
