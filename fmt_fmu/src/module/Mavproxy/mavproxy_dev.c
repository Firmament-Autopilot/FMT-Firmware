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

#include "shell.h"
#include <firmament.h>
#include <string.h>

#include "hal/cdcacm.h"
#include "hal/serial.h"
#include "module/mavproxy/mavcmd.h"
#include "task/task_comm.h"

#define MAVPROXY_SERIAL_BAUDRATE    57600
#define MAVPROXY_MAX_DEVICE_NUM     5
#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_TYPE_IS(_idx, _name) MATCH(_mavproxy_device_list[_idx].type, #_name)

typedef struct {
    uint32_t baudrate;
} mavproxy_serial_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} mavproxy_device_info;

static rt_device_t _mavproxy_dev = RT_NULL;
static rt_sem_t _mavproxy_dev_rx_sem, _mavproxy_dev_tx_sem;
static uint8_t _dev_chan = 0xFF;

static mavproxy_device_info _mavproxy_device_list[MAVPROXY_MAX_DEVICE_NUM] = { 0 };
static uint8_t _mavproxy_device_num = 0;

fmt_err (*_mav_rx_indicate)(uint32_t size);

static void _init_device_list(void)
{
    for (int i = 0; i < MAVPROXY_MAX_DEVICE_NUM; i++) {
        if (_mavproxy_device_list[i].type) {
            rt_free(_mavproxy_device_list[i].type);
        }
        if (_mavproxy_device_list[i].name) {
            rt_free(_mavproxy_device_list[i].name);
        }
        if (_mavproxy_device_list[i].config) {
            rt_free(_mavproxy_device_list[i].config);
        }
        _mavproxy_device_list[i].type = NULL;
        _mavproxy_device_list[i].name = NULL;
        _mavproxy_device_list[i].config = NULL;
    }
    _mavproxy_device_num = 0;
}

static fmt_err _mavproxy_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err err = FMT_EOK;
    int i;
    const char* key;
    const char* raw;

    /* get device type */
    if ((raw = toml_raw_in(curtab, "type")) != 0) {
        if (toml_rtos(raw, &_mavproxy_device_list[idx].type) != 0) {
            console_printf("Error: fail to parse type value\n");
            err = FMT_ERROR;
        }

        if (DEVICE_TYPE_IS(idx, serial)) {
            mavproxy_serial_dev_config serial_default_config = {
                .baudrate = MAVPROXY_SERIAL_BAUDRATE
            };
            _mavproxy_device_list[idx].config = rt_malloc(sizeof(mavproxy_serial_dev_config));

            /* set default value */
            if (_mavproxy_device_list[idx].config)
                *(mavproxy_serial_dev_config*)_mavproxy_device_list[idx].config = serial_default_config;

        } else if (DEVICE_TYPE_IS(idx, usb)) {
            /* no configuration for usb device */
        } else {
            console_printf("Error: unknown device type: %s\n", _mavproxy_device_list[idx].type);
            err = FMT_ERROR;
        }

        if (_mavproxy_device_list[idx].config == NULL && !DEVICE_TYPE_IS(idx, usb)) {
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
                mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)_mavproxy_device_list[idx].config;

                if (MATCH(key, "name")) {
                    if (toml_rtos(raw, &_mavproxy_device_list[idx].name) != 0) {
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
                } else {
                    console_printf("Error: unknown config key: %s\n", key);
                    continue;
                }
            }

            /* parse mavlink device */
            if (DEVICE_TYPE_IS(idx, usb)) {
                if (MATCH(key, "name")) {
                    if (toml_rtos(raw, &_mavproxy_device_list[idx].name) != 0) {
                        console_printf("Error: fail to parse name value\n");
                        return FMT_ERROR;
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

static fmt_err _mavproxy_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = _mavproxy_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            console_printf("mavproxy device parse fail: %d\n", err);
            continue;
        }

        if (++idx >= MAVPROXY_MAX_DEVICE_NUM) {
            break;
        }
    }

    _mavproxy_device_num = idx;

    return err;
}

int mavproxy_get_dev_chan(const char* name)
{
    for (int idx = 0; idx < _mavproxy_device_num; idx++) {
        if (MATCH(_mavproxy_device_list[idx].name, name)) {
            return idx;
        }
    }

    return -1;
}

rt_err_t mavproxy_dev_tx_done(rt_device_t dev, void* buffer)
{
    return rt_sem_release(_mavproxy_dev_tx_sem);
}

rt_err_t mavproxy_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_err_t rt_err;
    rt_err = rt_sem_release(_mavproxy_dev_rx_sem);

    if (_mav_rx_indicate) {
        _mav_rx_indicate(size);
    }

    return rt_err;
}

static int device_switch(char* dev_name)
{
    rt_device_t new_dev;
    rt_device_t old_dev = _mavproxy_dev;

    new_dev = rt_device_find(dev_name);

    if (new_dev == RT_NULL) {
        console_printf("cant not find device\n");
        return 1;
    }

    if (new_dev == _mavproxy_dev) {
        console_printf("device is already used\n");
        return 0;
    }

    if (rt_device_open(new_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX) != RT_EOK) {
        console_printf("mavproxy device open fail\n");
        return 1;
    }

    /* config devices if needed */
    int idx = mavproxy_get_dev_chan(dev_name);
    if (idx >= 0 && DEVICE_TYPE_IS(idx, serial)) {
        serial_dev_t serial_dev = (serial_dev_t)new_dev;
        mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)_mavproxy_device_list[idx].config;

        if (serial_dev->config.baud_rate != config->baudrate) {
            struct serial_configure pconfig = serial_dev->config;
            pconfig.baud_rate = config->baudrate;
            if (rt_device_control(new_dev, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
                console_printf("Error: fail to configure serial\n");
            }
        }
    }

    _mavproxy_dev = new_dev;

    if (old_dev) {
        rt_device_close(old_dev);
    }

    /* set callback functions */
    rt_device_set_tx_complete(new_dev, mavproxy_dev_tx_done);
    rt_device_set_rx_indicate(new_dev, mavproxy_dev_rx_ind);

    return 0;
}

static int switch_chan_if_needed(uint8_t new_chan)
{
    if (new_chan != _dev_chan && new_chan < _mavproxy_device_num) {
        if (device_switch(_mavproxy_device_list[new_chan].name) == 0) {
            _dev_chan = new_chan;
            return 1;
        }
    }

    return 0;
}

uint8_t mavproxy_dev_used_channel(void)
{
    return _dev_chan;
}

rt_size_t mavproxy_dev_sync_write(uint8_t chan, const void* buffer, uint32_t len)
{
    rt_size_t size;

    switch_chan_if_needed(chan);

    /* write data to device */
    OS_ENTER_CRITICAL;
    size = rt_device_write(_mavproxy_dev, 0, buffer, len);
    OS_EXIT_CRITICAL;

    /* wait write complete (synchronized write) */
    rt_sem_take(_mavproxy_dev_tx_sem, RT_WAITING_FOREVER);

    return size;
}

rt_size_t mavproxy_dev_sync_read(uint8_t chan, void* buffer, uint32_t len)
{
    rt_size_t cnt = 0;

    switch_chan_if_needed(chan);

    /* try to read data */
    OS_ENTER_CRITICAL;
    cnt = rt_device_read(_mavproxy_dev, 0, buffer, len);
    OS_EXIT_CRITICAL;

    /* if not enough data reveived, wait it */
    while (cnt < len) {
        /* wait until something reveived (synchronized read) */
        rt_sem_take(_mavproxy_dev_rx_sem, RT_WAITING_FOREVER);
        /* read rest data */
        OS_ENTER_CRITICAL;
        cnt += rt_device_read(_mavproxy_dev, 0, (void*)((uint32_t)buffer + cnt), len - cnt);
        OS_EXIT_CRITICAL;
    }

    return len;
}

rt_size_t mavproxy_dev_write(uint8_t chan, const void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t size;

    switch_chan_if_needed(chan);

    /* write data to device */
    size = rt_device_write(_mavproxy_dev, 0, buffer, len);

    /* wait write complete (synchronized write) */
    rt_sem_take(_mavproxy_dev_tx_sem, timeout);

    return size;
}

rt_size_t mavproxy_dev_read(uint8_t chan, void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t cnt = 0;

    switch_chan_if_needed(chan);

    /* try to read data */
    cnt = rt_device_read(_mavproxy_dev, 0, buffer, len);

    /* sync mode */
    if (timeout != 0) {
        /* if not enough data reveived, wait it */
        while (cnt < len) {
            rt_err_t rt_err;
            /* wait until something reveived (synchronized read) */
            rt_err = rt_sem_take(_mavproxy_dev_rx_sem, timeout);

            if (rt_err != RT_EOK)
                break;

            /* read rest data */
            cnt += rt_device_read(_mavproxy_dev, 0, (void*)((uint32_t)buffer + cnt), len - cnt);
        }
    }

    return cnt;
}

void mavproxy_dev_set_rx_indicate(fmt_err (*rx_ind)(uint32_t size))
{
    _mav_rx_indicate = rx_ind;
}

/* config mavproxy via toml system configuration file */
fmt_err mavproxy_dev_toml_init(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    toml_table_t* tab;
    fmt_err err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            /* we get new device configuration, override original one */
            _init_device_list();

            if ((arr = toml_array_in(table, key)) != 0) {
                if (toml_array_kind(arr) == 't') {
                    err = _mavproxy_parse_devices(arr);
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
            /* we get new device configuration, override original one */
            _init_device_list();

            if ((tab = toml_table_in(table, key)) != 0) {
                err = _mavproxy_parse_device(tab, 0);
                if (err == FMT_EOK) {
                    _mavproxy_device_num = 1;
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

    return err;
}

fmt_err mavproxy_dev_init(void)
{
    _mavproxy_dev_rx_sem = rt_sem_create("mavdev_rx_sem", 0, RT_IPC_FLAG_FIFO);
    _mavproxy_dev_tx_sem = rt_sem_create("mavdev_tx_sem", 0, RT_IPC_FLAG_FIFO);

    if (_mavproxy_dev_rx_sem == RT_NULL || _mavproxy_dev_tx_sem == RT_NULL) {
        console_printf("mavproxy rx/tx sem create fail\n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}