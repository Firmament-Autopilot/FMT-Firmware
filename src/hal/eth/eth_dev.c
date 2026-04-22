/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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
#include <lwip/sockets.h>

#include "hal/eth/eth_dev.h"

// static rt_err_t hal_eth_dev_init(rt_device_t dev)
// {
//     eth_dev_t eth = (eth_dev_t)dev;

//     RT_ASSERT(dev != RT_NULL);

//     return RT_EOK;
// }

static rt_err_t hal_eth_dev_open(rt_device_t dev, rt_uint16_t oflag)
{
    eth_dev_t eth = (eth_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    eth->sock = socket(eth->domain, eth->type, eth->protocol);
    if (eth->sock < 0) {
        /* socket create fail */
        return RT_ENOSYS;
    }

    // memset(&eth->local_addr, 0, sizeof(eth->local_addr));
    // eth->local_addr.sin_family = AF_INET;
    // eth->local_addr.sin_port = htons(5000);
    // eth->local_addr.sin_addr.s_addr = INADDR_ANY;

    /* bind local address/port */
    if (bind(eth->sock, (struct sockaddr*)&eth->local_addr, sizeof(eth->local_addr)) < 0) {
        /* bind fail */
        closesocket(eth->sock);
        eth->sock = -1;
        return RT_ERROR;
    };

    return RT_EOK;
}

rt_err_t hal_eth_dev_close(rt_device_t dev)
{
    eth_dev_t eth = (eth_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    closesocket(eth->sock);
    eth->sock = -1;

    return RT_EOK;
}

static rt_size_t hal_eth_dev_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    eth_dev_t eth = (eth_dev_t)dev;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    uint32_t timeout_ms = pos;
    int ret;

    RT_ASSERT(dev != RT_NULL);

    struct timeval timeout;
    uint32_t mode = 0; /* blocking */
    if (timeout_ms == RT_WAITING_NO) {
        mode = 1;      /* non-blocking */
        ioctlsocket(eth->sock, FIONBIO, &mode);
    } else {
        ioctlsocket(eth->sock, FIONBIO, &mode);

        if (timeout_ms > 0) {
            timeout.tv_sec = timeout_ms / 1000;
            timeout.tv_usec = (timeout_ms % 1000) * 1000;

            if (setsockopt(eth->sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
                return 0;
            }
        }
    }

    ret = recvfrom(eth->sock, buffer, size, 0, (struct sockaddr*)&client_addr, &addr_len);

    if (ret > 0) {
        return ret;
    } else {
        return 0;
    }
}

static rt_size_t hal_eth_dev_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    eth_dev_t eth = (eth_dev_t)dev;
    int ret;

    RT_ASSERT(dev != RT_NULL);

    ret = sendto(eth->sock, buffer, size, 0, (struct sockaddr*)&eth->remote_addr, sizeof(eth->remote_addr));
    if (ret > 0) {
        return ret;
    } else {
        return 0;
    }
}

void hal_eth_dev_init(eth_dev_t eth)
{
    RT_ASSERT(eth != RT_NULL);

    eth->sock = -1;
    eth->domain = AF_INET;
    eth->type = SOCK_DGRAM;
    eth->protocol = IPPROTO_UDP;

    memset(&eth->local_addr, 0, sizeof(eth->local_addr));
    memset(&eth->remote_addr, 0, sizeof(eth->remote_addr));
}

/**
 * @brief register a eth device
 *
 * @param eth eth device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_eth_dev_register(eth_dev_t eth, const char* name, rt_uint16_t flag, void* data)
{
    rt_device_t dev = &eth->parent;

    dev->type = RT_Device_Class_NetIf;
    dev->ref_count = 0;

    dev->rx_indicate = RT_NULL;
    dev->tx_complete = RT_NULL;

    dev->init = RT_NULL;
    dev->open = hal_eth_dev_open;
    dev->close = hal_eth_dev_close;
    dev->read = hal_eth_dev_read;
    dev->write = hal_eth_dev_write;
    dev->control = RT_NULL;

    dev->user_data = RT_NULL;

    if (rt_device_register(dev, name, flag) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}