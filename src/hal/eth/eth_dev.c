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

#include "lwip/err.h"
#include "lwip/udp.h"

#include "hal/eth/eth_dev.h"

#define ETH_DEV_RX_BUFFER_SIZE (4096)

static void udp_recv_callback(void* arg, struct udp_pcb* pcb, struct pbuf* p, const ip_addr_t* addr, u16_t port)
{
    eth_dev_t eth = (eth_dev_t)arg;

    if (p == NULL || eth == NULL) {
        return;
    }

    struct pbuf* sbuf = p;
    while (sbuf != NULL) {
        if (ringbuffer_put(eth->rx_rb, sbuf->payload, sbuf->len) != sbuf->len) {
            /* maybe ringbuffer is full */
            break;
        }
        sbuf = sbuf->next; /* move to next */
    }

    pbuf_free(p);

    rt_completion_done(&eth->rx_ind);

    if (eth->parent.rx_indicate) {
        eth->parent.rx_indicate(&eth->parent, ringbuffer_getlen(eth->rx_rb));
    }
}

static rt_err_t hal_eth_dev_open(rt_device_t dev, rt_uint16_t oflag)
{
    eth_dev_t eth = (eth_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    if (eth->udp_pcb == NULL) {
        eth->udp_pcb = udp_new_ip_type(IPADDR_TYPE_ANY);
        if (eth->udp_pcb != NULL) {
            /* create rx ringbuffer */
            eth->rx_rb = ringbuffer_create(ETH_DEV_RX_BUFFER_SIZE);
            if (eth->rx_rb == NULL) {
                udp_remove(eth->udp_pcb);
                return RT_ENOMEM;
            }
            /* create rx complete handler */
            rt_completion_init(&eth->rx_ind);

            if (udp_bind(eth->udp_pcb, &eth->local_addr, eth->local_port) != ERR_OK) {
                udp_remove(eth->udp_pcb);
                return RT_ERROR;
            }
            /* start to receive data */
            udp_recv(eth->udp_pcb, udp_recv_callback, eth);
        } else {
            return RT_ERROR;
        }
    }

    return RT_EOK;
}

rt_err_t hal_eth_dev_close(rt_device_t dev)
{
    eth_dev_t eth = (eth_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    udp_disconnect(eth->udp_pcb);
    udp_remove(eth->udp_pcb);

    return RT_EOK;
}

static rt_size_t hal_eth_dev_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    eth_dev_t eth = (eth_dev_t)dev;
    rt_size_t rx_cnt = 0;
    rt_int32_t timeout = pos;

    if (size == 0 || dev == RT_NULL || buffer == RT_NULL) {
        return 0;
    }

    /* try to read data */
    rx_cnt = ringbuffer_get(eth->rx_rb, buffer, size);

    /* if timeout is not 0, then check if required length data read */
    if (timeout != 0) {
        uint32_t time_start, elapse_time;
        /* if not enough data reveived, wait it */
        while (rx_cnt < size) {
            time_start = systime_now_ms();
            /* wait until something reveived (synchronized read) */
            if (rt_completion_wait(&eth->rx_ind, timeout) != RT_EOK) {
                break;
            }
            if (timeout > 0) {
                elapse_time = systime_now_ms() - time_start;
                timeout -= elapse_time;
                if (timeout <= 0) {
                    /* timeout */
                    break;
                }
            }
            /* read rest data */
            rx_cnt += ringbuffer_get(eth->rx_rb, (void*)((uint32_t)buffer + rx_cnt), size - rx_cnt);
        }
    }

    return rx_cnt;
}

static rt_size_t hal_eth_dev_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    eth_dev_t eth = (eth_dev_t)dev;
    struct pbuf* p;
    rt_size_t w_size;

    if (size == 0 || dev == RT_NULL || buffer == RT_NULL) {
        return 0;
    }

    p = pbuf_alloc(PBUF_TRANSPORT, size, PBUF_RAM);
    if (p == NULL) {
        return 0;
    }

    memcpy(p->payload, buffer, size);

    if (udp_sendto(eth->udp_pcb, p, &eth->remote_addr, eth->remote_port) != ERR_OK) {
        w_size = 0;
    } else {
        w_size = size;
    }

    pbuf_free(p);

    if (eth->parent.tx_complete) {
        eth->parent.tx_complete(&eth->parent, NULL);
    }

    return w_size;
}

void init_eth_dev(eth_dev_t eth)
{
    memset(eth, 0, sizeof(struct eth_dev));
    IP4_ADDR(&eth->local_addr, 0, 0, 0, 0); /* receive from any ip */
    IP4_ADDR(&eth->remote_addr, 0, 0, 0, 0);
    eth->local_port = 0;                    /* alloc a local port */
    eth->remote_port = 0;
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

    dev->user_data = data;

    if (rt_device_register(dev, name, flag) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}