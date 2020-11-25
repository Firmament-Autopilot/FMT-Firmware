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

#include "hal/fmtio_dev.h"
#include "module/fmtio/fmtio.h"

#define FMT_IO_PKG_BUFFER_SIZE 10
#define FMT_IO_PKG_DATA_SIZE   256

#define EVENT_FMTIO_RX (1) // 1 << 0
#define EVENT_FMTIO_TX (2) // 1 << 1

static struct rt_event _fmtio_event;
/* suspend io package transfer */
static uint8_t _io_comm_suspend = 0;
/* io send package buffer */
static PackageStruct _io_pkg_buff[FMT_IO_PKG_BUFFER_SIZE];
static uint16_t _pkg_buff_head = 0;
static uint16_t _pkg_buff_tail = 0;
/* send package data buffer */
static uint8_t _pkg_data[FMT_IO_PKG_DATA_SIZE];
/* io rx pkg */
static uint8_t _rx_pkg_buff[MAX_PACKAGE_SIZE];
static PackageStruct _rx_pkg = {
    .content = _rx_pkg_buff
};
static rt_device_t _fmtio_dev;
static fmtio_rx_handler_t _rx_handler = NULL;

static rt_err_t _io_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* wakeup thread to handle received data */
    return rt_event_send(&_fmtio_event, EVENT_FMTIO_RX);
}

static fmt_err _dump_pkg_buffer(void)
{
    SendPkgStruct send_pkg;

    if (_io_comm_suspend) {
        return FMT_EBUSY;
    }

    /* use static buffer to store pkg data which is going be sent */
    send_pkg.send_buff = _pkg_data;

    while (_pkg_buff_tail != _pkg_buff_head) {
        /* read pkg from buffer and make send pkg */
        //package2sendpack_static(_io_pkg_buff[_pkg_buff_tail], &send_pkg);
        make_send_package(_io_pkg_buff[_pkg_buff_tail], &send_pkg);

        /* send out pkg data */
        if (rt_device_write(_fmtio_dev, RT_WAITING_FOREVER, send_pkg.send_buff, send_pkg.buff_size) == send_pkg.buff_size) {
            /* send success, free pkg and remove it from buffer */
            free_io_package(&_io_pkg_buff[_pkg_buff_tail]);
            OS_ENTER_CRITICAL;
            _pkg_buff_tail = (_pkg_buff_tail + 1) % FMT_IO_PKG_BUFFER_SIZE;
            OS_EXIT_CRITICAL;
        }
    }

    return FMT_EOK;
}

static fmt_err _handle_rx(void)
{
    uint8_t c;

    if (_io_comm_suspend) {
        return FMT_EBUSY;
    }

    while (rt_device_read(_fmtio_dev, 0, &c, 1)) {
        if (proto_parse_package(c, &_rx_pkg) == FMT_EOK) {
            if (_rx_handler) {
                _rx_handler(&_rx_pkg);
            }
        }
    }

    return FMT_EOK;
}

rt_device_t fmtio_get_device(void)
{
    return _fmtio_dev;
}

void fmtio_suspend_comm(uint8_t suspend)
{
    _io_comm_suspend = suspend;

    if (suspend == 0) {
        /* wakeup thread to handle TX/RX event */
        rt_event_send(&_fmtio_event, EVENT_FMTIO_RX);
        rt_event_send(&_fmtio_event, EVENT_FMTIO_TX);
    }
}

fmt_err fmtio_send_package(const void* data, uint16_t len, PackageStruct* pkg)
{
    if (_io_comm_suspend) {
        return FMT_EBUSY;
    }

    if ((_pkg_buff_head + 1) % FMT_IO_PKG_BUFFER_SIZE == _pkg_buff_tail) {
        console_printf("io package overflow\n");
        return FMT_EFULL;
    } else {
        /* write pkg content */
        if (fill_io_package(data, len, pkg) != FMT_EOK) {
            console_printf("write pkg fail\n");
            return FMT_ERROR;
        }

        /* push pkg into send buffer */
        OS_ENTER_CRITICAL;
        _io_pkg_buff[_pkg_buff_head] = *pkg;
        _pkg_buff_head = (_pkg_buff_head + 1) % FMT_IO_PKG_BUFFER_SIZE;
        OS_EXIT_CRITICAL;

        /* wakeup thread to send out pkg */
        rt_event_send(&_fmtio_event, EVENT_FMTIO_TX);
    }

    return FMT_EOK;
}

fmt_err fmtio_send_message(uint16_t cmd, const void* data, uint16_t len)
{
    fmt_err err;
    PackageStruct pkg;

    err = create_io_package(cmd, len, &pkg);

    if (err == FMT_EOK) {
        err = fmtio_send_package(data, len, &pkg);
    }

    return err;
}

fmt_err fmtio_register_rx_handler(fmtio_rx_handler_t rx_handler)
{
    if (rx_handler == NULL) {
        return FMT_ERROR;
    }

    _rx_handler = rx_handler;
    return FMT_EOK;
}

void fmtio_loop(void)
{
    rt_err_t rt_err;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_FMTIO_RX | EVENT_FMTIO_TX;

    while (1) {
        /* wait event happen or timeout */
        rt_err = rt_event_recv(&_fmtio_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            10, &recv_set);

        if (rt_err == RT_EOK || rt_err == -RT_ETIMEOUT) {
            if (recv_set & EVENT_FMTIO_RX) {
                _handle_rx();
            }

            if (recv_set & EVENT_FMTIO_TX) {
                _dump_pkg_buffer();
            }
        } else {
            //some err happen
            console_printf("fmtio event err:%d\n", rt_err);
        }
    }
}

fmt_err fmtio_init(void)
{
    /* register fmtio hal device */
    if (hal_fmtio_dev_register(FMTIO_DEVICE_NAME, "fmtio_dev", RT_DEVICE_FLAG_RDWR, RT_NULL) != RT_EOK) {
        return FMT_ERROR;
    }

    /* create event */
    if (rt_event_init(&_fmtio_event, "fmtio", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }

    _fmtio_dev = rt_device_find("fmtio_dev");

    if (_fmtio_dev == NULL) {
        console_printf("can not find fmtio device\n");
        return FMT_ERROR;
    }

    if (rt_device_open(_fmtio_dev, RT_DEVICE_FLAG_RDWR) != RT_EOK) {
        console_printf("fmtio device open fail\n");
        return FMT_ERROR;
    }

    /* set rx indicator */
    rt_device_set_rx_indicate(_fmtio_dev, _io_rx_ind);

    return FMT_EOK;
}