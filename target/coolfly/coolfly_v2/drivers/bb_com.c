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

#include "ar1002_hal.h"
#include "bb_com.h"
#include "bb_led.h"
#include "debuglog.h"

static struct bb_com_device bb_com3;

static void bb_com3_irq_handler(void* p)
{

#define BB_READ_MAX_LEN 200

    struct bb_com_device* bb_com = &bb_com3;
    rt_base_t level;
    struct bb_com_rx_fifo* rx_fifo;

    /* interrupt mode receive */
    rx_fifo = (struct bb_com_rx_fifo*)bb_com->bb_com_rx;
    RT_ASSERT(rx_fifo != RT_NULL);

    uint32_t cnt = 0;
    uint8_t buffer[BB_READ_MAX_LEN];
    HAL_RET_T ret;

    ret = HAL_BB_ComReceiveMsg(BB_COM_SESSION_3, buffer, BB_READ_MAX_LEN, &cnt);
    if (ret != HAL_OK) {
        DLOG_Error("failed read bbcom");
        return;
    }

    if (get_link_led_status() != LINK_LOCK && cnt > 0) {
        DLOG_Warning("uart not lock, drop %ld", cnt);
        return;
    }

    if (cnt > 0 && cnt <= BB_READ_MAX_LEN) {
        /* disable interrupt */
        level = rt_hw_interrupt_disable();
        for (uint32_t i = 0; i < cnt; i++) {
            // console_printf("%02x ", buffer[i]);
            rx_fifo->buffer[rx_fifo->put_index] = buffer[i];
            rx_fifo->put_index += 1;

            if (rx_fifo->put_index >= BB_COM_BUFSZ) {
                rx_fifo->put_index = 0;
            }

            /* if the next position is read index, discard this 'read char' */
            if (rx_fifo->put_index == rx_fifo->get_index) {
                rx_fifo->get_index += 1;
                rx_fifo->is_full = RT_TRUE;

                if (rx_fifo->get_index >= BB_COM_BUFSZ)
                    rx_fifo->get_index = 0;
            }
        }
        /* enable interrupt */
        rt_hw_interrupt_enable(level);
    } else {
        // DLOG_Info("bb read %ld",cnt);
    }

    /* invoke callback */
    if (bb_com->parent.rx_indicate != RT_NULL) {
        rt_size_t rx_length;

        /* get rx length */
        level = rt_hw_interrupt_disable();
        rx_length = (rx_fifo->put_index >= rx_fifo->get_index) ? (rx_fifo->put_index - rx_fifo->get_index) : (BB_COM_BUFSZ - (rx_fifo->get_index - rx_fifo->put_index));
        rt_hw_interrupt_enable(level);

        if (rx_length) {
            bb_com->parent.rx_indicate(&bb_com->parent, rx_length);
        }
    }
}

rt_inline int _bb_com_poll_tx(struct bb_com_device* bb_com, const rt_uint8_t* data, int length)
{
#define MAX_BB_DOWNLINK_SEND_SIZE 200

    // int size;
    RT_ASSERT(bb_com != RT_NULL);

    // size = length;

    if (length > MAX_BB_DOWNLINK_SEND_SIZE) {
        length = MAX_BB_DOWNLINK_SEND_SIZE;
    }

    HAL_RET_T ret = HAL_BB_ComSendMsg(BB_COM_SESSION_3, (uint8_t*)data, length);

    /* invoke callback */
    if (bb_com->parent.tx_complete != RT_NULL) {
        bb_com->parent.tx_complete(&bb_com->parent, (void*)RT_NULL);
    }

    if (ret != HAL_OK) {
        // DLOG_Error("failed ret %ld", ret);
        return 0;
    }

    return length;
}

static rt_size_t hal_bb_com_write(struct rt_device* dev,
                                  rt_off_t pos,
                                  const void* buffer,
                                  rt_size_t size)
{
    struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);

    if (size == 0)
        return 0;

    bb_com = (struct bb_com_device*)dev;

    return _bb_com_poll_tx(bb_com, buffer, size);
}

static rt_err_t hal_bb_com_control(struct rt_device* dev,
                                   int cmd,
                                   void* args)
{
    rt_err_t ret = RT_EOK;
    // struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);
    // bb_com = (struct bb_com_device*)dev;

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
        break;

    default:
        break;
    }

    return ret;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/* RT-Thread Device Interface */
/*
 * This function initializes bb_com device.
 */
static rt_err_t hal_bb_com_init(struct rt_device* dev)
{
    rt_err_t result = RT_EOK;
    struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);
    bb_com = (struct bb_com_device*)dev;

    /* initialize rx/tx */
    bb_com->bb_com_rx = RT_NULL;
    bb_com->bb_com_tx = RT_NULL;

    return result;
}

static rt_err_t hal_bb_com_open(struct rt_device* dev, rt_uint16_t oflag)
{
    struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);
    bb_com = (struct bb_com_device*)dev;

    /* check device flag with the open flag */
    if ((oflag & RT_DEVICE_FLAG_INT_RX) && !(dev->flag & RT_DEVICE_FLAG_INT_RX))
        return -RT_EIO;

    /* get open flags */
    dev->open_flag = oflag;

    /* initialize the Rx/Tx structure according to open flag */
    if (oflag & RT_DEVICE_FLAG_INT_RX) {
        if (bb_com->bb_com_rx == RT_NULL) {
            struct bb_com_rx_fifo* rx_fifo;

            /* create dma rx fifo */
            rx_fifo = (struct bb_com_rx_fifo*)rt_malloc(sizeof(struct bb_com_rx_fifo) + BB_COM_BUFSZ);
            RT_ASSERT(rx_fifo != RT_NULL);
            rx_fifo->buffer = (rt_uint8_t*)(rx_fifo + 1);
            rt_memset(rx_fifo->buffer, 0, BB_COM_BUFSZ);
            rx_fifo->put_index = 0;
            rx_fifo->get_index = 0;
            rx_fifo->is_full = RT_FALSE;

            bb_com->bb_com_rx = rx_fifo;
        }
    } else {
        bb_com->bb_com_rx = RT_NULL;
    }

    /* we don't use bb_com_tx */
    bb_com->bb_com_tx = RT_NULL;

    if (oflag & RT_DEVICE_FLAG_INT_RX) {

        HAL_BB_ComRegisterSession(BB_COM_SESSION_3,
                                  BB_COM_SESSION_PRIORITY_HIGH,
                                  BB_COM_SESSION_DATA_NORMAL,
                                  bb_com3_irq_handler); //  LIUWEI : TODO
    }

    return RT_EOK;
}

static rt_err_t hal_bb_com_close(struct rt_device* dev)
{
    struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);
    bb_com = (struct bb_com_device*)dev;

    /* this device has more reference count */
    if (dev->ref_count > 1)
        return RT_EBUSY;

    /* configure low level device, disable ineterrupts and dma*/
    HAL_BB_ComUnRegisterSession(BB_COM_SESSION_3,
                                bb_com3_irq_handler);

    bb_com->parent.rx_indicate = RT_NULL;
    bb_com->parent.tx_complete = RT_NULL;

    if (dev->open_flag & RT_DEVICE_FLAG_INT_RX) {
        struct bb_com_rx_fifo* rx_fifo;

        rx_fifo = (struct bb_com_rx_fifo*)bb_com->bb_com_rx;

        if (rx_fifo)
            rt_free(rx_fifo);

        bb_com->bb_com_rx = RT_NULL;

        dev->open_flag &= ~RT_DEVICE_FLAG_INT_RX;
    }

    return RT_EOK;
}

/*
 * bb_com interrupt routines
 */
rt_inline int _bb_com_int_rx(struct bb_com_device* bb_com, rt_uint8_t* data, int length)
{

    int size;
    int rx_length;

    RT_ASSERT(bb_com != RT_NULL);
    size = length;

    struct bb_com_rx_fifo* rx_fifo = (struct bb_com_rx_fifo*)bb_com->bb_com_rx;

    RT_ASSERT(rx_fifo != RT_NULL);

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

        if (rx_fifo->get_index >= BB_COM_BUFSZ)
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

    rx_length = size - length;

    return rx_length;
}

static rt_size_t hal_bb_com_read(struct rt_device* dev,
                                 rt_off_t pos,
                                 void* buffer,
                                 rt_size_t size)
{
    struct bb_com_device* bb_com;

    RT_ASSERT(dev != RT_NULL);

    if (size == 0)
        return 0;

    bb_com = (struct bb_com_device*)dev;

    return _bb_com_int_rx(bb_com, buffer, size);
}

/*
 * bb_com register
 */
rt_err_t hal_bb_com_register(struct bb_com_device* bb_com,
                             const char* name,
                             rt_uint32_t flag,
                             void* data)
{
    rt_err_t ret;
    struct rt_device* device;
    RT_ASSERT(bb_com != RT_NULL);

    device = &(bb_com->parent);

    device->type = RT_Device_Class_Char;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    device->ops = &bb_com_ops;
#else

    device->init = hal_bb_com_init;
    device->open = hal_bb_com_open;
    device->close = hal_bb_com_close;
    device->read = hal_bb_com_read;
    device->write = hal_bb_com_write;
    device->control = RT_NULL;
#endif
    device->user_data = data;

    /* register a character device */
    ret = rt_device_register(device, name, flag);

    return ret;
}

//////////////////////////////////////////

// static rt_device_t bb_com3_dev;

rt_err_t register_bb_com(void)
{
    /* register rc hal device */
    RT_CHECK(hal_bb_com_register(&bb_com3, "bb_com3", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX, NULL));

    return FMT_EOK;
}
