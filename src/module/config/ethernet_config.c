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

#ifdef RT_USING_LWIP

#include <stdio.h>

#include "hal/eth/eth_dev.h"
#include "module/config/ethernet_config.h"

#define TOML_DBG_E(...) toml_debug("Ethernet", "E", __VA_ARGS__)
#define TOML_DBG_W(...) toml_debug("Ethernet", "W", __VA_ARGS__)

#define MATCH(a, b)     (strcmp(a, b) == 0)

static fmt_err_t ethernet_parse_device(const toml_table_t* curtab)
{
    fmt_err_t res = FMT_EOK;
    char* name;
    char* ip_addr;
    int64_t port;
    int ip[4];
    eth_dev_t eth_dev = (eth_dev_t)rt_malloc(sizeof(struct eth_dev));

    if (eth_dev == NULL) {
        TOML_DBG_E("fail to alloc mem for eth_dev\n");
        res = FMT_ENOMEM;
        goto out;
    } else {
        /* set default value */
        init_eth_dev(eth_dev);
    }

    if (toml_string_in(curtab, "name", &name) != 0) {
        TOML_DBG_E("fail to parse name value\n");
        res = FMT_ERROR;
        goto out;
    }

    if (toml_string_in(curtab, "local_addr", &ip_addr) == 0) {
        sscanf(ip_addr, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        IP4_ADDR(&eth_dev->local_addr, ip[0], ip[1], ip[2], ip[3]);
    }

    if (toml_int_in(curtab, "local_port", &port) == 0) {
        eth_dev->local_port = port;
    }

    if (toml_string_in(curtab, "remote_addr", &ip_addr) == 0) {
        sscanf(ip_addr, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        IP4_ADDR(&eth_dev->remote_addr, ip[0], ip[1], ip[2], ip[3]);
    } else {
        TOML_DBG_E("eth dev need set remote addr\n");
        res = FMT_EINVAL;
        goto out;
    }

    if (toml_int_in(curtab, "remote_port", &port) == 0) {
        eth_dev->remote_port = port;
    } else {
        TOML_DBG_E("eth dev need set remote port\n");
        res = FMT_EINVAL;
        goto out;
    }

    if (hal_eth_dev_register(eth_dev, name, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE, NULL) != RT_EOK) {
        TOML_DBG_E("fail to register eth dev\n");
        res = FMT_ERROR;
        goto out;
    }

out:
    if (res != FMT_EOK) {
        rt_free(eth_dev);
    }

    return res;
}

static fmt_err_t ethernet_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = ethernet_parse_device(curtab);

        if (err != FMT_EOK) {
            TOML_DBG_E("device parse fail: %d\n", err);
            return err;
        }
    }

    return err;
}

/* config ethernet via toml system configuration file */
fmt_err_t ethernet_toml_config(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    fmt_err_t err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            if (toml_array_table_in(table, key, &arr) == 0) {
                err = ethernet_parse_devices(arr);
                if (err != FMT_EOK) {
                    TOML_DBG_E("fail to parse devices\n");
                    return err;
                }
            } else {
                TOML_DBG_E("fail to get devices table\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown config key: %s\n", key);
            err = FMT_ERROR;
        }
    }

    return err;
}

#endif
