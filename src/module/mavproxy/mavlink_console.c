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

#include "module/mavproxy/mavproxy.h"
#include "module/utils/ringbuffer.h"

#define MAV_CONSOLE_DEVICE_NAME    "mav_console"
#define MAV_CONSOLE_RX_BUFFER_SIZE 128
#define MAV_CONSOLE_TX_BUFFER_SIZE 256

static struct rt_device* device;
static struct rt_device mavlink_console_dev;
static ringbuffer* _mav_console_rx_rb = RT_NULL;
static ringbuffer* _mav_console_tx_rb = RT_NULL;
static uint8_t _mav_console_rx_buffer[MAV_CONSOLE_RX_BUFFER_SIZE];
static uint8_t _mav_console_tx_buffer[MAV_CONSOLE_TX_BUFFER_SIZE];
static mavlink_serial_control_t _serial_control;
static struct rt_timer timer_mav_console;

static void mav_console_timeout(void* parameter)
{
    mavproxy_send_event(MAVPROXY_GCS_CHAN, EVENT_MAVCONSOLE_TIMEOUT);
}

static void send_serial_control_msg(mavlink_serial_control_t* serial_control)
{
    bool sync = true;
    mavlink_message_t msg;
    mavlink_system_t mavlink_system = mavproxy_get_system();

    mavlink_msg_serial_control_encode(mavlink_system.sysid, mavlink_system.compid, &msg, serial_control);

    if (rt_interrupt_get_nest() != 0) {
        /* if we are in the interrupt context, we can not send data via usb,
			since usb driver doesn't support that. Therefore, we will push this
			message into immediate msg queue, and let mavproxy send it out.
		*/

        /* we use async send for all msg in interrupt context,
			in order to do not influence the real-time performance */
        sync = false;
    }

    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, sync);
}

void mavlink_console_handle_timeout(void)
{
    mavlink_serial_control_t serial_control;

    serial_control.baudrate = 0;
    serial_control.device = SERIAL_CONTROL_DEV_SHELL;
    serial_control.flags = SERIAL_CONTROL_FLAG_REPLY;

    while (ringbuffer_getlen(_mav_console_tx_rb) >= 70) {

        serial_control.count = 70;
        ringbuffer_get(_mav_console_tx_rb, serial_control.data, serial_control.count);

        send_serial_control_msg(&serial_control);
    }

    uint32_t len = ringbuffer_getlen(_mav_console_tx_rb);

    if (len) {
        serial_control.count = len;

        ringbuffer_get(_mav_console_tx_rb, serial_control.data, serial_control.count);

        send_serial_control_msg(&serial_control);
    }
}

/* RT-Thread Device Interface */
/*
 * This function initializes mavlink_console device.
 */
static rt_err_t _init(struct rt_device* dev)
{
    rt_err_t result = RT_EOK;
    RT_ASSERT(dev != RT_NULL);

    return result;
}

static rt_err_t _open(struct rt_device* dev, rt_uint16_t oflag)
{
    RT_ASSERT(dev != RT_NULL);

    /* do not check oflag, since mav_console based on mavproxy device, which should be opened properly */

    /* get open flags */
    dev->open_flag = oflag & 0xFFFF;

    /* initialize the Rx/Tx structure according to open flag */
    if (oflag & RT_DEVICE_FLAG_DMA_RX) {
        dev->open_flag |= RT_DEVICE_FLAG_DMA_RX;
    } else if (oflag & RT_DEVICE_FLAG_INT_RX) {
        dev->open_flag |= RT_DEVICE_FLAG_INT_RX;
    }

    if (oflag & RT_DEVICE_FLAG_DMA_TX) {
        dev->open_flag |= RT_DEVICE_FLAG_DMA_TX;
    } else if (oflag & RT_DEVICE_FLAG_INT_TX) {
        dev->open_flag |= RT_DEVICE_FLAG_INT_TX;
    }

    /* init serial control object */
    _serial_control.baudrate = 0;
    _serial_control.count = 0;
    _serial_control.device = SERIAL_CONTROL_DEV_SHELL;
    _serial_control.flags = SERIAL_CONTROL_FLAG_REPLY;

    return RT_EOK;
}

static rt_err_t _close(struct rt_device* dev)
{
    RT_ASSERT(dev != RT_NULL);

    /* this device has more reference count */
    if (dev->ref_count > 1)
        return RT_EBUSY;

    dev->rx_indicate = RT_NULL;
    dev->tx_complete = RT_NULL;

    return RT_EOK;
}

static rt_size_t _read(struct rt_device* dev,
                       rt_off_t pos,
                       void* buffer,
                       rt_size_t size)
{
    uint16_t len;

    RT_ASSERT(dev != RT_NULL);

    if (size == 0)
        return 0;

    len = ringbuffer_getlen(_mav_console_rx_rb);

    if (!len)
        return 0;

    size = size > len ? len : size;
    return ringbuffer_get(_mav_console_rx_rb, buffer, size);
}

static rt_size_t _write(struct rt_device* dev,
                        rt_off_t pos,
                        const void* buffer,
                        rt_size_t size)
{
    rt_size_t len;
    rt_size_t left;
    rt_size_t free_space;
    rt_size_t data_in_buffer;
    rt_size_t sent_cnt;

    RT_ASSERT(dev != RT_NULL);

    if (size == 0)
        return 0;

    /* left data to be sent */
    left = size;

    while (left) {
        /* get data length in buffer */
        data_in_buffer = ringbuffer_getlen(_mav_console_tx_rb);
        /* get buffer free space */
        free_space = MAV_CONSOLE_TX_BUFFER_SIZE - data_in_buffer;
        /* data that already be sent */
        sent_cnt = size - left;
        /* fill buffer up to it's size */
        len = left <= free_space ? left : free_space;
        ringbuffer_put(_mav_console_tx_rb, buffer + sent_cnt, len);

        /* if buffer has enough data, send it now */
        while (ringbuffer_getlen(_mav_console_tx_rb) >= 70) {

            mavlink_serial_control_t serial_control;

            serial_control.baudrate = 0;
            serial_control.count = 70;
            serial_control.device = SERIAL_CONTROL_DEV_SHELL;
            serial_control.flags = SERIAL_CONTROL_FLAG_REPLY;

            /* read data from buffer */
            ringbuffer_get(_mav_console_tx_rb, serial_control.data, serial_control.count);

            send_serial_control_msg(&serial_control);
        }

        /* update left data to be sent */
        left -= len;
    }

    /* if there are some data in buffer but buffer is not full,
		setup a timer. If no more data coming before timer expired,
		send data out. otherwise, reset timer */
    if (ringbuffer_getlen(_mav_console_tx_rb)) {
        rt_timer_start(&timer_mav_console);
    }

    if (dev->tx_complete) {
        dev->tx_complete(dev, RT_NULL);
    }

    return size;
}

static rt_err_t _control(struct rt_device* dev,
                         int cmd,
                         void* args)
{
    RT_ASSERT(dev != RT_NULL);

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
        /* configure device */
        break;

    case RT_DEVICE_CTRL_GET_INT:
        break;

    default:
        break;
    }

    return RT_EOK;
}

void mavlink_console_process_rx_msg(const mavlink_serial_control_t* serial_control)
{
    /* push data to ring buffer */
    for (uint8_t i = 0; i < serial_control->count; i++) {
        if (!ringbuffer_putc(_mav_console_rx_rb, serial_control->data[i]))
            break;
    }

    /* call indicator if exist */
    if (device->rx_indicate) {
        device->rx_indicate(device, serial_control->count);
    }
}

/*
 * mavlink console register
 */
rt_err_t mavlink_console_init()
{
    device = &mavlink_console_dev;

    device->type = RT_Device_Class_Char;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = _init;
    device->open = _open;
    device->close = _close;
    device->read = _read;
    device->write = _write;
    device->control = _control;
    device->user_data = RT_NULL;

    if (_mav_console_rx_rb == RT_NULL) {
        _mav_console_rx_rb = ringbuffer_static_create(MAV_CONSOLE_RX_BUFFER_SIZE, _mav_console_rx_buffer);

        if (_mav_console_rx_rb == RT_NULL) {
            console_printf("mav console ringbuffer create fail\n");
            return RT_ERROR;
        }
    }

    if (_mav_console_tx_rb == RT_NULL) {
        _mav_console_tx_rb = ringbuffer_static_create(MAV_CONSOLE_TX_BUFFER_SIZE, _mav_console_tx_buffer);

        if (_mav_console_tx_rb == RT_NULL) {
            console_printf("mav console ringbuffer create fail\n");
            return RT_ERROR;
        }
    }

    /* register timer event */
    rt_timer_init(&timer_mav_console, "mav_console", mav_console_timeout, RT_NULL, 50, RT_TIMER_FLAG_ONE_SHOT | RT_TIMER_FLAG_HARD_TIMER);

    /* open flag doesn't matter, since open function will not check open flag */
    return rt_device_register(device, MAV_CONSOLE_DEVICE_NAME, RT_DEVICE_FLAG_RDWR);
}
