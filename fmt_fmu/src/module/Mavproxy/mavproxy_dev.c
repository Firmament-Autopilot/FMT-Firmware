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

#include "hal/cdcacm.h"
#include "hal/serial.h"

static rt_device_t _mavproxy_dev = RT_NULL;
static rt_sem_t _mavproxy_dev_rx_sem, _mavproxy_dev_tx_sem;

fmt_err (*_mav_rx_indicate)(uint32_t size);

static rt_err_t mavproxy_dev_tx_done(rt_device_t dev, void* buffer)
{
    return rt_sem_release(_mavproxy_dev_tx_sem);
}

static rt_err_t mavproxy_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_err_t rt_err;
    rt_err = rt_sem_release(_mavproxy_dev_rx_sem);

    if (_mav_rx_indicate) {
        _mav_rx_indicate(size);
    }

    return rt_err;
}

rt_size_t mavproxy_dev_write(const void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t size;

    if (_mavproxy_dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

    /* write data to device */
    size = rt_device_write(_mavproxy_dev, 0, buffer, len);

    /* wait write complete (synchronized write) */
    rt_sem_take(_mavproxy_dev_tx_sem, timeout);

    return size;
}

rt_size_t mavproxy_dev_read(void* buffer, uint32_t len, int32_t timeout)
{
    rt_size_t cnt = 0;

    if (_mavproxy_dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

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

fmt_err mavproxy_set_device(const char* dev_name)
{
    rt_device_t new_dev;

    new_dev = rt_device_find(dev_name);

    if (new_dev == RT_NULL) {
        return FMT_EEMPTY;
    }

    if (new_dev != _mavproxy_dev) {
        rt_uint16_t flag = RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX;
        if (new_dev->flag & (RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX) ){
            /* if device support DMA, then use it */
            flag = RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX;
        }
        rt_err_t err = rt_device_open(new_dev, flag);
        if (err != RT_EOK) {
            return FMT_ERROR;
        }
        _mavproxy_dev = new_dev;
    }

    /* set callback functions */
    rt_device_set_tx_complete(new_dev, mavproxy_dev_tx_done);
    rt_device_set_rx_indicate(new_dev, mavproxy_dev_rx_ind);

    return FMT_EOK;
}

rt_device_t mavproxy_get_device(void)
{
    return _mavproxy_dev;
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