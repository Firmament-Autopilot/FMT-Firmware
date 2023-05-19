/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "hal/droencan_dev/droencan_dev.h"

static struct rt_device droencan_dev;
static rt_device_t droencan_dev_t = &droencan_dev;
static rt_device_t can_dev_t;

static rt_err_t fmtio_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_err_t ret;

    rt_completion_done(&rx_cplt);

    /* invoke rx indicator if set */
    if (fmtio_dev_t->rx_indicate) {
        fmtio_dev_t->rx_indicate(fmtio_dev_t, size);
    }

    return ret;
}

static rt_err_t fmtio_dev_open(rt_device_t dev, rt_uint16_t oflag)
{
    return rt_device_open(io_dev_t, oflag);
}

static rt_err_t fmtio_dev_close(rt_device_t dev)
{
    return rt_device_close(io_dev_t);
}

static rt_size_t fmtio_dev_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rt_size_t cnt = 0;
    rt_int32_t timeout = (rt_int32_t)pos;

    /* try to read data */
    cnt = rt_device_read(io_dev_t, 0, buffer, size);

    /* if not enough data received, wait it */
    while (cnt < size) {
        /* wait receive some data */
        if (rt_completion_wait(&rx_cplt, timeout) != RT_EOK) {
            return cnt;
        }
        /* read left data */
        cnt += rt_device_read(io_dev_t, 0, (void*)((uint32_t)buffer + cnt), size - cnt);
    }

    return cnt;
}

static rt_size_t fmtio_dev_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    rt_size_t wb;
    rt_int32_t timeout = (rt_int32_t)pos;

    /* take tx lock */
    if (rt_sem_take(tx_lock, timeout) != RT_EOK) {
        return 0;
    }
    /* write data to device */
    wb = rt_device_write(io_dev_t, 0, buffer, size);
    /* wait write complete */
    rt_completion_wait(&tx_cplt, timeout);
    /* release tx lock */
    rt_sem_release(tx_lock);

    return wb;
}

/**
 * @brief Register fmtio device
 *
 * @param io_dev The io device which is used by fmtio
 * @param name The name of fmtio device
 * @param flag Open flag, should be equal to io device flag
 * @param data User data
 * @return rt_err_t
 */
rt_err_t hal_dronecan_dev_register(rt_device_t can_dev, const char* name, rt_uint32_t flag, void* data)
{
    can_dev_t = can_dev;

    RT_ASSERT(can_dev_t != NULL);

    /* init fmtio device */
    fmtio_dev_t->type = RT_Device_Class_Char;
    fmtio_dev_t->rx_indicate = RT_NULL;
    fmtio_dev_t->tx_complete = RT_NULL;

    fmtio_dev_t->init = RT_NULL;
    fmtio_dev_t->open = fmtio_dev_open;
    fmtio_dev_t->close = fmtio_dev_close;
    fmtio_dev_t->read = fmtio_dev_read;
    fmtio_dev_t->write = fmtio_dev_write;
    fmtio_dev_t->control = RT_NULL;

    fmtio_dev_t->user_data = data;

    return rt_device_register(fmtio_dev_t, name, flag);
}