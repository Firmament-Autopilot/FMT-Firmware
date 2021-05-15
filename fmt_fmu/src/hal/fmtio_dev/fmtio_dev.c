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

#include "hal/fmtio_dev.h"
#include "hal/serial.h"
#include <firmament.h>

static struct rt_device _fmtio_dev;

static rt_device_t _fmtio_dev_t;
static rt_device_t _io_dev;
static struct rt_completion tx_cplt, rx_cplt;
static rt_sem_t tx_lock;

static rt_err_t fmtio_dev_tx_done(rt_device_t dev, void* buffer)
{
    rt_err_t ret;

    rt_completion_done(&tx_cplt);

    /* invoke tx indicator if set */
    if (_fmtio_dev_t->tx_complete) {
        _fmtio_dev_t->tx_complete(_fmtio_dev_t, buffer);
    }

    return ret;
}

static rt_err_t fmtio_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_err_t ret;

    rt_completion_done(&rx_cplt);

    /* invoke rx indicator if set */
    if (_fmtio_dev_t->rx_indicate) {
        _fmtio_dev_t->rx_indicate(_fmtio_dev_t, size);
    }

    return ret;
}

static rt_err_t fmtio_dev_open(rt_device_t dev, rt_uint16_t oflag)
{
    return rt_device_open(_io_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX);
}

static rt_err_t fmtio_dev_close(rt_device_t dev)
{
    return rt_device_close(_io_dev);
}

static rt_size_t fmtio_dev_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rt_size_t cnt = 0;
    rt_int32_t timeout = (rt_int32_t)pos;

    /* try to read data */
    cnt = rt_device_read(_io_dev, 0, buffer, size);

    /* if not enough data reveived, wait it */
    while (cnt < size) {
        /* wait receive some data */
        if (rt_completion_wait(&rx_cplt, timeout) != RT_EOK) {
            return cnt;
        }
        /* read left data */
        cnt += rt_device_read(_io_dev, 0, (void*)((uint32_t)buffer + cnt), size - cnt);
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
    wb = rt_device_write(_io_dev, 0, buffer, size);
    /* wait write complete */
    rt_completion_wait(&tx_cplt, timeout);
    /* release tx lock */
    rt_sem_release(tx_lock);

    return wb;
}

rt_err_t fmtio_dev_control(rt_device_t dev, int cmd, void* args)
{
    rt_err_t ret = RT_ERROR;
    serial_dev_t serial;

    if (_io_dev == NULL) {
        return RT_ERROR;
    }

    serial = (serial_dev_t)_io_dev;

    switch (cmd) {
    case FMTIO_DEV_CMD_CONFIG: {
        if (serial->ops->configure) {
            if (args) {
                ret = serial->ops->configure(serial, (struct serial_configure*)args);
            } else {
                /* if args is NULL, use default configuration */
                ret = serial->ops->configure(serial, &serial->config);
            }
        }
    } break;

    default: {

    } break;
    }

    return ret;
}

rt_err_t hal_fmtio_dev_register(const char* serial_name, const char* name, rt_uint32_t flag, void* data)
{
    _fmtio_dev_t = &_fmtio_dev;

    _io_dev = rt_device_find(serial_name);

    if (_io_dev == RT_NULL) {
        return RT_EEMPTY;
    }

    rt_completion_init(&tx_cplt);
    rt_completion_init(&rx_cplt);

    tx_lock = rt_sem_create("io_tx_lock", 1, RT_IPC_FLAG_FIFO);
    RT_ASSERT(tx_lock != NULL);

    /* set callback functions */
    rt_device_set_tx_complete(_io_dev, fmtio_dev_tx_done);
    rt_device_set_rx_indicate(_io_dev, fmtio_dev_rx_ind);

    /* init fmtio device */
    _fmtio_dev_t->type = RT_Device_Class_Char;
    _fmtio_dev_t->ref_count = 0;
    _fmtio_dev_t->rx_indicate = RT_NULL;
    _fmtio_dev_t->tx_complete = RT_NULL;

    _fmtio_dev_t->init = RT_NULL;
    _fmtio_dev_t->open = fmtio_dev_open;
    _fmtio_dev_t->close = fmtio_dev_close;
    _fmtio_dev_t->read = fmtio_dev_read;
    _fmtio_dev_t->write = fmtio_dev_write;
    _fmtio_dev_t->control = fmtio_dev_control;

    _fmtio_dev_t->user_data = data;

    return rt_device_register(_fmtio_dev_t, name, flag);
}