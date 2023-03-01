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

#include "hal/serial/serial.h"

#define HAL_DBG(...) printf(__VA_ARGS__)

/*
 * Serial poll routines
 */
rt_inline int _serial_poll_rx(struct serial_device* serial, rt_uint8_t* data, int length)
{
    int ch;
    int size;
    int rx_length;

    size = length;

    while (length) {
        ch = serial->ops->getc(serial);

        if (ch == -1)
            break;

        *data = ch;
        data++;
        length--;

        if (ch == '\n')
            break;
    }

    rx_length = size - length;

    /* invoke callback */
    if (serial->parent.rx_indicate != RT_NULL && rx_length) {
        serial->parent.rx_indicate(&serial->parent, rx_length);
    }

    return rx_length;
}

rt_inline int _serial_poll_tx(struct serial_device* serial, const rt_uint8_t* data, int length)
{
    int size;

    size = length;

    while (length) {
        /**
         * to be polite with serial console add a line feed
         * to the carriage return character
         */
        if (*data == '\n' && (serial->parent.open_flag & RT_DEVICE_FLAG_STREAM)) {
            serial->ops->putc(serial, '\r');
        }

        serial->ops->putc(serial, *data);

        ++data;
        --length;
    }

    /* invoke callback */
    if (serial->parent.tx_complete != RT_NULL) {
        serial->parent.tx_complete(&serial->parent, (void*)RT_NULL);
    }

    return size - length;
}

/*
 * Serial interrupt routines
 */
rt_inline int _serial_int_rx(struct serial_device* serial, rt_uint8_t* data, int length)
{
    int size = length;
    struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

    if (rx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    /* read from software FIFO */
    while (length) {
        int ch;
        rt_base_t level;

        /* disable interrupt */
        level = rt_hw_interrupt_disable();

        /* there's no data: */
        if ((rx_fifo->get_index == rx_fifo->put_index) && (rx_fifo->is_full == RT_FALSE)) {
            /* no data, enable interrupt and break out */
            rt_hw_interrupt_enable(level);
            break;
        }

        /* otherwise there's the data: */
        ch = rx_fifo->buffer[rx_fifo->get_index];
        rx_fifo->get_index += 1;

        if (rx_fifo->get_index >= serial->config.bufsz)
            rx_fifo->get_index = 0;

        if (rx_fifo->is_full == RT_TRUE) {
            rx_fifo->is_full = RT_FALSE;
        }

        /* enable interrupt */
        rt_hw_interrupt_enable(level);

        *data = ch & 0xff;
        data++;
        length--;
    }

    return size - length;
}

rt_inline int _serial_int_tx(struct serial_device* serial, const rt_uint8_t* data, int length)
{
    int size = length;
    struct serial_tx_fifo* tx_fifo = (struct serial_tx_fifo*)serial->serial_tx;

    if (tx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    while (length) {
        if (serial->ops->putc(serial, *(char*)data) == -1) {
            rt_completion_wait(&(tx_fifo->completion), RT_WAITING_FOREVER);
            continue;
        }

        data++;
        length--;
    }

    return size - length;
}

static rt_size_t _serial_fifo_calc_recved_len(struct serial_device* serial)
{
    struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

    if (rx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    if (rx_fifo->put_index == rx_fifo->get_index) {
        return (rx_fifo->is_full == RT_FALSE ? 0 : serial->config.bufsz);
    } else {
        if (rx_fifo->put_index > rx_fifo->get_index) {
            return rx_fifo->put_index - rx_fifo->get_index;
        } else {
            return serial->config.bufsz - (rx_fifo->get_index - rx_fifo->put_index);
        }
    }
}

/**
 * Calculate DMA received data length.
 *
 * @param serial serial device
 *
 * @return length
 */
static rt_size_t _dma_calc_recved_len(struct serial_device* serial)
{
    return _serial_fifo_calc_recved_len(serial);
}

/**
 * Read data finish by DMA mode then update the get index for receive fifo.
 *
 * @param serial serial device
 * @param len get data length for this operate
 */
static void _dma_recv_update_get_index(struct serial_device* serial, rt_size_t len)
{
    struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

    if (rx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return;
    }

    if (len > _dma_calc_recved_len(serial)) {
        HAL_DBG("length:%d exceeds the maxium received length\n", len);
        return;
    }

    if (rx_fifo->is_full && len != 0)
        rx_fifo->is_full = RT_FALSE;

    rx_fifo->get_index += len;

    if (rx_fifo->get_index >= serial->config.bufsz) {
        rx_fifo->get_index %= serial->config.bufsz;
    }
}

/**
 * DMA received finish then update put index for receive fifo.
 *
 * @param serial serial device
 * @param len received length for this transmit
 */
static void _dma_recv_update_put_index(struct serial_device* serial, rt_size_t len)
{
    struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

    if (rx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return;
    }

    if (rx_fifo->get_index <= rx_fifo->put_index) {
        rx_fifo->put_index += len;

        /* beyond the fifo end */
        if (rx_fifo->put_index >= serial->config.bufsz) {
            rx_fifo->put_index %= serial->config.bufsz;

            /* force overwrite get index */
            if (rx_fifo->put_index >= rx_fifo->get_index) {
                rx_fifo->is_full = RT_TRUE;
            }
        }
    } else {
        rx_fifo->put_index += len;

        if (rx_fifo->put_index >= rx_fifo->get_index) {
            /* beyond the fifo end */
            if (rx_fifo->put_index >= serial->config.bufsz) {
                rx_fifo->put_index %= serial->config.bufsz;
            }

            /* force overwrite get index */
            rx_fifo->is_full = RT_TRUE;
        }
    }

    if (rx_fifo->is_full == RT_TRUE) {
        rx_fifo->get_index = rx_fifo->put_index;
    }

    if (rx_fifo->get_index >= serial->config.bufsz)
        rx_fifo->get_index = 0;
}

/*
 * Serial DMA routines
 */
rt_inline int _serial_dma_rx(struct serial_device* serial, rt_uint8_t* data, int length)
{
    rt_base_t level;
    struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

    if (rx_fifo == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    level = rt_hw_interrupt_disable();

    rt_size_t recv_len = 0, fifo_recved_len = _dma_calc_recved_len(serial);

    RT_ASSERT(rx_fifo != RT_NULL);

    if (length < fifo_recved_len)
        recv_len = length;
    else
        recv_len = fifo_recved_len;

    if (rx_fifo->get_index + recv_len < serial->config.bufsz)
        rt_memcpy(data, rx_fifo->buffer + rx_fifo->get_index, recv_len);
    else {
        rt_memcpy(data, rx_fifo->buffer + rx_fifo->get_index, serial->config.bufsz - rx_fifo->get_index);
        rt_memcpy(data + serial->config.bufsz - rx_fifo->get_index, rx_fifo->buffer, recv_len + rx_fifo->get_index - serial->config.bufsz);
    }

    _dma_recv_update_get_index(serial, recv_len);

    rt_hw_interrupt_enable(level);

    return recv_len;
}

rt_inline int _serial_dma_tx(struct serial_device* serial, const rt_uint8_t* data, int length)
{
    /* make a DMA transfer */
    serial->ops->dma_transmit(serial, (rt_uint8_t*)data, length, SERIAL_DMA_TX);

    return length;
}

/* RT-Thread Device Interface */
/*
 * This function initializes serial device.
 */
static rt_err_t hal_serial_init(struct rt_device* dev)
{
    rt_err_t result = RT_EOK;
    struct serial_device* serial;

    if (dev == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return RT_EINVAL;
    }

    serial = (struct serial_device*)dev;

    /* initialize rx/tx */
    serial->serial_rx = RT_NULL;
    serial->serial_tx = RT_NULL;

    /* apply configuration */
    if (serial->ops->configure)
        result = serial->ops->configure(serial, &serial->config);

    return result;
}

static rt_err_t hal_serial_open(struct rt_device* dev, rt_uint16_t oflag)
{
    struct serial_device* serial;

    if (dev == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return RT_EINVAL;
    }

    serial = (struct serial_device*)dev;

    /*dbg_log(DBG_LOG, "open serial device: 0x%08x with open flag: 0x%04x\n",
            dev, oflag);*/

    /* check device flag with the open flag */
    if ((oflag & RT_DEVICE_FLAG_INT_RX) && !(dev->flag & RT_DEVICE_FLAG_INT_RX))
        return -RT_EIO;

    if ((oflag & RT_DEVICE_FLAG_DMA_RX) && !(dev->flag & RT_DEVICE_FLAG_DMA_RX))
        return -RT_EIO;

    if ((oflag & RT_DEVICE_FLAG_DMA_TX) && !(dev->flag & RT_DEVICE_FLAG_DMA_TX))
        return -RT_EIO;

    /* get open flags */
    dev->open_flag = oflag;

    /* initialize the Rx/Tx structure according to open flag */
    if (oflag & RT_DEVICE_FLAG_INT_RX || oflag & RT_DEVICE_FLAG_DMA_RX) {
        if (serial->serial_rx == RT_NULL) {
            struct serial_rx_fifo* rx_fifo;

            /* create dma rx fifo */
            rx_fifo = (struct serial_rx_fifo*)rt_malloc(sizeof(struct serial_rx_fifo) + serial->config.bufsz);
            RT_ASSERT(rx_fifo != RT_NULL);
            rx_fifo->buffer = (rt_uint8_t*)(rx_fifo + 1);
            rt_memset(rx_fifo->buffer, 0, serial->config.bufsz);
            rx_fifo->put_index = 0;
            rx_fifo->get_index = 0;
            rx_fifo->is_full = RT_FALSE;

            serial->serial_rx = rx_fifo;
        }
    } else {
        serial->serial_rx = RT_NULL;
    }

    /* we don't use serial_tx */
    serial->serial_tx = RT_NULL;

    if (oflag & RT_DEVICE_FLAG_INT_RX) {
        /* configure low level device */
        serial->ops->control(serial, RT_DEVICE_CTRL_SET_INT, (void*)RT_DEVICE_FLAG_INT_RX);
    } else if (oflag & RT_DEVICE_FLAG_DMA_RX) {
        /* configure fifo address and length to low level device */
        serial->ops->control(serial, RT_DEVICE_CTRL_CONFIG, (void*)RT_DEVICE_FLAG_DMA_RX);
    }

    if (oflag & RT_DEVICE_FLAG_DMA_TX) {
        /* configure fifo address and length to low level device */
        serial->ops->control(serial, RT_DEVICE_CTRL_CONFIG, (void*)RT_DEVICE_FLAG_DMA_TX);
    }

    return RT_EOK;
}

static rt_err_t hal_serial_close(struct rt_device* dev)
{
    struct serial_device* serial;

    if (dev == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return RT_EINVAL;
    }

    serial = (struct serial_device*)dev;

    /* this device has more reference count */
    if (dev->ref_count > 1)
        return RT_EBUSY;

    /* configure low level device, disable ineterrupts and dma*/
    serial->ops->control(serial, RT_DEVICE_CTRL_SUSPEND, RT_NULL);

    serial->parent.rx_indicate = RT_NULL;
    serial->parent.tx_complete = RT_NULL;

    if (dev->open_flag & RT_DEVICE_FLAG_INT_RX) {
        struct serial_rx_fifo* rx_fifo;

        rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

        if (rx_fifo)
            rt_free(rx_fifo);

        serial->serial_rx = RT_NULL;

        dev->open_flag &= ~RT_DEVICE_FLAG_INT_RX;
    } else if (dev->open_flag & RT_DEVICE_FLAG_DMA_RX) {
        struct serial_rx_fifo* rx_fifo;

        rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

        if (rx_fifo)
            rt_free(rx_fifo);

        serial->serial_rx = RT_NULL;

        dev->open_flag &= ~RT_DEVICE_FLAG_DMA_RX;
    }

    if (dev->open_flag & RT_DEVICE_FLAG_DMA_TX) {
        if (serial->serial_tx)
            rt_free(serial->serial_tx);

        serial->serial_tx = RT_NULL;

        dev->open_flag &= ~RT_DEVICE_FLAG_DMA_TX;
    }

    return RT_EOK;
}

static rt_size_t hal_serial_read(struct rt_device* dev,
                                 rt_off_t pos,
                                 void* buffer,
                                 rt_size_t size)
{
    struct serial_device* serial;

    if (size == 0) {
        return 0;
    }

    if ((dev == RT_NULL) || (buffer == RT_NULL)) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    if (size == 0)
        return 0;

    serial = (struct serial_device*)dev;

    if (dev->open_flag & RT_DEVICE_FLAG_INT_RX) {
        return _serial_int_rx(serial, buffer, size);
    } else if (dev->open_flag & RT_DEVICE_FLAG_DMA_RX) {
        return _serial_dma_rx(serial, buffer, size);
    } else {
        return _serial_poll_rx(serial, buffer, size);
    }
}

static rt_size_t hal_serial_write(struct rt_device* dev,
                                  rt_off_t pos,
                                  const void* buffer,
                                  rt_size_t size)
{
    struct serial_device* serial;

    if (size == 0) {
        return 0;
    }

    if ((dev == RT_NULL) || (buffer == RT_NULL)) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return 0;
    }

    serial = (struct serial_device*)dev;

    if (dev->open_flag & RT_DEVICE_FLAG_DMA_TX) {
        return _serial_dma_tx(serial, buffer, size);
    } else {
        return _serial_poll_tx(serial, buffer, size);
    }
}

static rt_err_t hal_serial_control(struct rt_device* dev,
                                   int cmd,
                                   void* args)
{
    rt_err_t ret = RT_EOK;
    struct serial_device* serial;

    RT_ASSERT(dev != RT_NULL);
    serial = (struct serial_device*)dev;

    switch (cmd) {
    case RT_DEVICE_CTRL_SUSPEND:
        /* suspend device */
        dev->flag |= RT_DEVICE_FLAG_SUSPENDED;
        break;

    case RT_DEVICE_CTRL_RESUME:
        /* resume device */
        dev->flag &= ~RT_DEVICE_FLAG_SUSPENDED;
        break;

    case RT_DEVICE_CTRL_CONFIG:
        if (args) {
            struct serial_configure* pconfig = (struct serial_configure*)args;

            if (pconfig->bufsz != serial->config.bufsz && serial->parent.ref_count) {
                /*can not change buffer size*/
                return RT_EBUSY;
            }

            /* set serial configure */
            serial->config = *pconfig;

            /* if device is opened before, re-configure it */
            if (serial->parent.flag & RT_DEVICE_FLAG_ACTIVATED && serial->ops->configure) {
                /* serial device has been opened, re-configure it */
                serial->ops->configure(serial, (struct serial_configure*)args);
            }
        }

        break;

    default:
        /* control device */
        if (serial->ops->control) {
            ret = serial->ops->control(serial, cmd, args);
        }
        break;
    }

    return ret;
}

/**
 * @brief serial isr handler
 * 
 * @param serial serial device
 * @param event serial isr event
 */
void hal_serial_isr(struct serial_device* serial, int event)
{
    if (serial == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return;
    }

    switch (event & 0xff) {
    case SERIAL_EVENT_RX_IND: {
        int ch = -1;
        rt_base_t level;
        struct serial_rx_fifo* rx_fifo;

        /* interrupt mode receive */
        rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;
        RT_ASSERT(rx_fifo != RT_NULL);

        while (1) {
            ch = serial->ops->getc(serial);

            if (ch == -1)
                break;

            /* disable interrupt */
            level = rt_hw_interrupt_disable();

            rx_fifo->buffer[rx_fifo->put_index] = ch;
            rx_fifo->put_index += 1;

            if (rx_fifo->put_index >= serial->config.bufsz)
                rx_fifo->put_index = 0;

            /* if the next position is read index, discard this 'read char' */
            if (rx_fifo->put_index == rx_fifo->get_index) {
                rx_fifo->get_index += 1;
                rx_fifo->is_full = RT_TRUE;

                if (rx_fifo->get_index >= serial->config.bufsz)
                    rx_fifo->get_index = 0;
            }

            /* enable interrupt */
            rt_hw_interrupt_enable(level);
        }

        /* invoke callback */
        if (serial->parent.rx_indicate != RT_NULL) {
            rt_size_t rx_length;

            /* get rx length */
            level = rt_hw_interrupt_disable();
            rx_length = (rx_fifo->put_index >= rx_fifo->get_index) ? (rx_fifo->put_index - rx_fifo->get_index) : (serial->config.bufsz - (rx_fifo->get_index - rx_fifo->put_index));
            rt_hw_interrupt_enable(level);

            if (rx_length) {
                serial->parent.rx_indicate(&serial->parent, rx_length);
            }
        }

        break;
    }

    case SERIAL_EVENT_TX_DMADONE: {

        /* invoke callback */
        if (serial->parent.tx_complete != RT_NULL) {
            serial->parent.tx_complete(&serial->parent, (void*)RT_NULL);
        }

        break;
    }

    case SERIAL_EVENT_RX_DMADONE: {
        int length;
        rt_base_t level;

        /* get DMA rx length */
        length = (event & (~0xff)) >> 8;

        /* disable interrupt */
        level = rt_hw_interrupt_disable();
        /* update fifo put index */
        _dma_recv_update_put_index(serial, length);
        /* calculate received total length in fifo */
        length = _dma_calc_recved_len(serial);
        /* enable interrupt */
        rt_hw_interrupt_enable(level);

        /* invoke callback */
        if (serial->parent.rx_indicate != RT_NULL) {
            serial->parent.rx_indicate(&(serial->parent), length);
        }

        break;
    }
    }
}

/**
 * @brief register a serial device
 * 
 * @param serial serial device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_serial_register(struct serial_device* serial,
                             const char* name,
                             rt_uint32_t flag,
                             void* data)
{
    rt_err_t ret;
    struct rt_device* device;
    RT_ASSERT(serial != RT_NULL);

    device = &(serial->parent);

    device->type = RT_Device_Class_Char;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_serial_init;
    device->open = hal_serial_open;
    device->close = hal_serial_close;
    device->read = hal_serial_read;
    device->write = hal_serial_write;
    device->control = hal_serial_control;
    device->user_data = data;

    /* register character to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}
