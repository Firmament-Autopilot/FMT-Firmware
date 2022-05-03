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

#include "hal/serial/serial.h"

static rt_device_t mavproxy_dev = RT_NULL;
static struct rt_completion tx_cplt, rx_cplt;

static fmt_err_t (*mav_rx_indicate)(uint32_t size) = NULL;

static rt_err_t mavproxy_dev_tx_done(rt_device_t dev, void* buffer)
{
    rt_completion_done(&tx_cplt);
    return RT_EOK;
}

static rt_err_t mavproxy_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_completion_done(&rx_cplt);

    if (mav_rx_indicate) {
        mav_rx_indicate(size);
    }

    return RT_EOK;
}

rt_size_t mavproxy_dev_write(const void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t size;

    if (mavproxy_dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }
    /* write data to device */
    size = rt_device_write(mavproxy_dev, 0, buffer, len);
    if (size > 0) {
        /* wait write complete (synchronized write) */
        if (rt_completion_wait(&tx_cplt, timeout) != RT_EOK) {
            return 0;
        }
    }

    return size;
}

rt_size_t mavproxy_dev_read(void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t cnt = 0;

    if (mavproxy_dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

    /* try to read data */
    cnt = rt_device_read(mavproxy_dev, 0, buffer, len);

    /* sync mode */
    if (timeout != 0) {
        uint32_t time_start, elapse_time;
        /* if not enough data reveived, wait it */
        while (cnt < len) {
            time_start = systime_now_ms();
            /* wait until something reveived (synchronized read) */
            if (rt_completion_wait(&rx_cplt, timeout) != RT_EOK) {
                break;
            }
            if (timeout != RT_WAITING_FOREVER) {
                elapse_time = systime_now_ms() - time_start;
                timeout -= elapse_time;
                if (timeout <= 0) {
                    /* timeout */
                    break;
                }
            }
            /* read rest data */
            cnt += rt_device_read(mavproxy_dev, 0, (void*)((uint32_t)buffer + cnt), len - cnt);
        }
    }

    return cnt;
}

void mavproxy_dev_set_rx_indicate(fmt_err_t (*rx_ind)(uint32_t size))
{
    mav_rx_indicate = rx_ind;
}

fmt_err_t mavproxy_set_device(const char* dev_name)
{
    rt_device_t new_dev;

    new_dev = rt_device_find(dev_name);

    if (new_dev == RT_NULL) {
        return FMT_EEMPTY;
    }

    if (new_dev != mavproxy_dev) {
        rt_uint16_t flag = RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX;
        if (new_dev->flag & (RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX)) {
            /* if device support DMA, then use it */
            flag = RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX;
        }
        rt_err_t err = rt_device_open(new_dev, flag);
        if (err != RT_EOK) {
            return FMT_ERROR;
        }
        mavproxy_dev = new_dev;
    }

    /* set callback functions */
    rt_device_set_tx_complete(new_dev, mavproxy_dev_tx_done);
    rt_device_set_rx_indicate(new_dev, mavproxy_dev_rx_ind);

    return FMT_EOK;
}

rt_device_t mavproxy_get_device(void)
{
    return mavproxy_dev;
}

fmt_err_t mavproxy_dev_init(void)
{
    rt_completion_init(&tx_cplt);
    rt_completion_init(&rx_cplt);

    return FMT_EOK;
}