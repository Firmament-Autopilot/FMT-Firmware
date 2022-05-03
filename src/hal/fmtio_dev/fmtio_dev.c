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

#include "hal/fmtio_dev/fmtio_dev.h"
#include "hal/serial/serial.h"

static struct rt_device fmtio_dev;
static rt_device_t fmtio_dev_t = &fmtio_dev;
static rt_device_t io_dev_t;
static struct rt_completion tx_cplt, rx_cplt;
static rt_sem_t tx_lock;

static rt_err_t fmtio_dev_tx_done(rt_device_t dev, void* buffer)
{
    rt_err_t ret;

    rt_completion_done(&tx_cplt);

    /* invoke tx indicator if set */
    if (fmtio_dev_t->tx_complete) {
        fmtio_dev_t->tx_complete(fmtio_dev_t, buffer);
    }

    return ret;
}

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

rt_err_t fmtio_dev_control(rt_device_t dev, int cmd, void* args)
{
    rt_err_t ret = RT_EOK;
    serial_dev_t serial = (serial_dev_t)io_dev_t;

    switch (cmd) {
    case FMTIO_SET_BAUDRATE: {
        struct serial_configure config = serial->config;
        config.baud_rate = (uint32_t)args;
        ret = serial->ops->configure(serial, &config);
        if (ret == RT_EOK) {
            serial->config.baud_rate = config.baud_rate;
        }
    } break;

    case FMTIO_GET_BAUDRATE:
        if (args == NULL) {
            return RT_EINVAL;
        }
        *(uint32_t*)args = serial->config.baud_rate;
        break;

    default:
        break;
    }

    return ret;
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
rt_err_t hal_fmtio_dev_register(rt_device_t io_dev, const char* name, rt_uint32_t flag, void* data)
{
    io_dev_t = io_dev;

    RT_ASSERT(io_dev_t != NULL);
    RT_ASSERT(io_dev_t->flag == flag);

    rt_completion_init(&tx_cplt);
    rt_completion_init(&rx_cplt);

    /* write lock */
    tx_lock = rt_sem_create("io_tx_lock", 1, RT_IPC_FLAG_FIFO);
    RT_ASSERT(tx_lock != NULL);

    /* set tx/rx callback functions */
    RT_CHECK(rt_device_set_tx_complete(io_dev_t, fmtio_dev_tx_done));
    RT_CHECK(rt_device_set_rx_indicate(io_dev_t, fmtio_dev_rx_ind));

    /* init fmtio device */
    fmtio_dev_t->type = RT_Device_Class_Char;
    fmtio_dev_t->rx_indicate = RT_NULL;
    fmtio_dev_t->tx_complete = RT_NULL;

    fmtio_dev_t->init = RT_NULL;
    fmtio_dev_t->open = fmtio_dev_open;
    fmtio_dev_t->close = fmtio_dev_close;
    fmtio_dev_t->read = fmtio_dev_read;
    fmtio_dev_t->write = fmtio_dev_write;
    fmtio_dev_t->control = fmtio_dev_control;

    fmtio_dev_t->user_data = data;

    return rt_device_register(fmtio_dev_t, name, flag);
}