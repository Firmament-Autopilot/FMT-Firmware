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

#include "task/task_fmtio.h"

#include "module/console/console.h"
#include "module/fmtio/fmtio_protocol.h"
#include "module/ipc/uMCN.h"

#include "hal/fmtio_dev.h"
#include "hal/motor.h"
#include "hal/rc.h"
#include "hal/serial.h"

#define EVENT_FMTIO_RX (1 << 0)
#define EVENT_FMTIO_TX (1 << 1)

typedef struct {
    uint32_t timestamp_ms;
    uint16_t rc_chan_val[MAX_RC_CHANNEL_NUM];
} rc_data_t;

typedef struct {
    uint32_t baud_rate;
    uint16_t rc_chan_num;
    uint16_t pwm_freq;
} fmtio_config_t;

static struct rt_event _fmtio_event;
/* suspend io package send */
static uint8_t _io_comm_suspend = 0;
/* io send package buffer */
static PackageStruct _io_pkg_buff[FMT_IO_BUFFER_SIZE];
static uint16_t _pkg_buff_head = 0;
static uint16_t _pkg_buff_tail = 0;
/* send package data buffer */
static uint8_t _pkg_data[FMT_IO_PKG_DATA_SIZE];
/* io rx pkg */
static uint8_t _rx_pkg_buff[MAX_PACKAGE_SIZE];
static PackageStruct _rx_pkg = {
    .content = _rx_pkg_buff
};
/* rc channel value */
static rc_data_t _rc_data;
static uint8_t _rc_updated = 0;
static rt_device_t _fmtio_dev;
static rc_dev_t _rc_dev_t;
static motor_dev_t _motor_dev_t;

static uint16_t _motor_cmd[FMTIO_MOTOR_CHANNEL_NUM];
static PackageStruct _motor_cmd_pkg;

static uint8_t _sync_finish = 0;

/**************************** Callback Function ********************************/

static rt_err_t fmtio_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* wakeup thread to handle received data */
    return rt_event_send(&_fmtio_event, EVENT_FMTIO_RX);
}

/**************************** Local Function ********************************/

static void _handle_rc_message(const PackageStruct* pkg)
{
    uint16_t* index = (uint16_t*)pkg->content;

    for (uint8_t i = 0; i < pkg->len / 2; i++) {
        _rc_data.rc_chan_val[i] = *(index++);
    }

    _rc_data.timestamp_ms = systime_now_ms();
    _rc_updated = 1;
}

static fmt_err _handle_package(const PackageStruct* pkg)
{
    switch (pkg->cmd) {
    case PROTO_CMD_SYNC: {
        /* reply sync ack */
        fmtio_send_message(PROTO_ACK_SYNC, NULL, 0);
    } break;

    case PROTO_DBG_TEXT: {
        console_printf("[IO]:");
        console_write((char*)pkg->content, pkg->len);
    } break;

    case PROTO_DATA_RC: {
        _handle_rc_message(pkg);
        hal_rc_rx_ind(_rc_dev_t, pkg->len);
    } break;

    case PROTO_ACK_MOTOR_VAL: {
        uint16_t mask = *(uint16_t*)&pkg->content[0];
        console_printf("ack motor, mask:%x ", mask);

        for (int i = 0; i < 8; i++) {
            if (mask & (1 << i)) {
                console_printf("%d ", *(uint16_t*)&pkg->content[2 + i * 2]);
            }
        }

        console_printf("\n");
    } break;

    default: {
    }
    }

    _sync_finish = 1;

    return FMT_EOK;
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
            free_package(&_io_pkg_buff[_pkg_buff_tail]);
            OS_ENTER_CRITICAL;
            _pkg_buff_tail = (_pkg_buff_tail + 1) % FMT_IO_BUFFER_SIZE;
            OS_EXIT_CRITICAL;
        }
    }

    return FMT_EOK;
}

static fmt_err _handle_rx_data(void)
{
    uint8_t c;

    if (_io_comm_suspend) {
        return FMT_EBUSY;
    }

    while (rt_device_read(_fmtio_dev, 0, &c, 1)) {
        if (proto_parse_package(c, &_rx_pkg) == FMT_EOK) {
            _handle_package(&_rx_pkg);
        }
    }

    return FMT_EOK;
}

static rt_err_t motor_configure(motor_dev_t motor, struct motor_configure* cfg)
{
    motor->config = *cfg;

    return RT_EOK;
}

static rt_err_t motor_control(motor_dev_t motor, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case MOTOR_CMD_CHANNEL_ENABLE: {
        uint8_t enable = 1;
        fmtio_send_message(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_CHANNEL_DISABLE: {
        uint8_t enable = 0;
        fmtio_send_message(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_SET_FREQUENCY: {
        uint16_t freq = *(uint16_t*)arg;
        // fmtio_send_message(PROTO_CMD_CONFIG, &freq, 2);
        fmtio_config(0, 0, freq);
    } break;

    default:
        break;
    }

    return ret;
}

static rt_size_t motor_read(motor_dev_t motor, rt_uint16_t chan_mask, rt_uint16_t* chan_val, rt_size_t size)
{
    fmt_err err;
    PackageStruct pkg;

    fmtio_create_pkg(PROTO_GET_MOTOR_VAL, sizeof(chan_mask), &pkg);

    err = fmtio_send_pkg(&chan_mask, sizeof(chan_mask), &pkg);

    return err == FMT_EOK ? size : 0;
}

static rt_size_t motor_write(motor_dev_t motor, rt_uint16_t chan_mask, const rt_uint16_t* chan_val, rt_size_t size)
{
    uint16_t data[FMTIO_MOTOR_CHANNEL_NUM + 1];
    uint16_t max_size = FMTIO_MOTOR_CHANNEL_NUM * sizeof(uint16_t);
    uint16_t w_size = size <= max_size ? size : max_size;

    data[0] = chan_mask;
    memcpy(&data[1], chan_val, w_size);

    // 2 bytes for channel mask
    fmt_err err = fmtio_send_pkg(data, w_size + 2, &_motor_cmd_pkg);

    return err == FMT_EOK ? w_size : 0;
}

const static struct motor_ops _motor_ops = {
    motor_configure,
    motor_control,
    motor_read,
    motor_write
};

static rt_err_t rc_configure(rc_dev_t rc, struct rc_configure* cfg)
{
    // TODO
    return RT_EOK;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void* arg)
{
    switch (cmd) {
    case RC_CMD_CHECK_UPDATE: {
        *(uint8_t*)arg = _rc_updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_uint16_t rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
{
    uint16_t* index = chan_val;

    if (!_rc_updated)
        return 0;

    for (uint8_t i = 0; i < FMTIO_RC_CHANNEL_NUM; i++) {
        if (chan_mask & (1 << i)) {
            *(index++) = _rc_data.rc_chan_val[i];
        }
    }

    _rc_updated = 0;

    return chan_mask & 0xFF; // currently maximal 8 rc channel, could be expended
}

const static struct rc_ops _rc_ops = {
    rc_configure,
    rc_control,
    rc_read,
};

/**************************** Public Function ********************************/
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

fmt_err fmtio_init_pkg(uint16_t cmd, void* buffer, PackageStruct* pkg)
{
    return init_static_package(cmd, (uint8_t*)buffer, pkg);
}

fmt_err fmtio_create_pkg(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg)
{
    return init_package(cmd, buff_len, pkg);
}

fmt_err fmtio_send_pkg(const void* data, uint16_t len, PackageStruct* pkg)
{
    if (_io_comm_suspend) {
        return FMT_EBUSY;
    }

    if ((_pkg_buff_head + 1) % FMT_IO_BUFFER_SIZE == _pkg_buff_tail) {
        console_printf("io package overflow\n");
        return FMT_EFULL;
    } else {
        /* write pkg content */
        if (write_package((uint8_t*)data, len, pkg) != FMT_EOK) {
            console_printf("write pkg fail\n");
            return FMT_ERROR;
        }

        /* push pkg into send buffer */
        OS_ENTER_CRITICAL;
        _io_pkg_buff[_pkg_buff_head] = *pkg;
        _pkg_buff_head = (_pkg_buff_head + 1) % FMT_IO_BUFFER_SIZE;
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

    err = fmtio_create_pkg(cmd, len, &pkg);

    if (err == FMT_EOK) {
        err = fmtio_send_pkg(data, len, &pkg);
    }

    return err;
}

fmt_err fmtio_config(uint32_t baud_rate, uint16_t rc_chan_num, uint16_t pwm_freq)
{
    fmtio_config_t io_config = {
        .baud_rate = baud_rate,
        .rc_chan_num = rc_chan_num,
        .pwm_freq = pwm_freq
    };

    /* check validity */
    if (baud_rate > BAUD_RATE_3000000 || rc_chan_num > FMTIO_RC_CHANNEL_NUM) {
        return FMT_EINVAL;
    }

    return fmtio_send_message(PROTO_CMD_CONFIG, &io_config, sizeof(io_config));
}

fmt_err task_fmtio_init(void)
{
    static struct motor_device motor_dev = {
        .channel_num = FMTIO_MOTOR_CHANNEL_NUM,
        .config = MOTOR_CONFIG_DEFAULT,
        .ops = &_motor_ops
    };
    static struct rc_device rc_dev = {
        .channel_num = FMTIO_RC_CHANNEL_NUM,
        .config = RC_CONFIG_DEFAULT,
        .ops = &_rc_ops
    };

    _motor_dev_t = &motor_dev;
    _rc_dev_t = &rc_dev;

    /* register fmtio hal device */
    if (hal_fmtio_dev_register(FMTIO_DEVICE_NAME, "fmtio_dev", RT_DEVICE_FLAG_RDWR, RT_NULL) != RT_EOK) {
        return FMT_ERROR;
    }

    /* register motor hal device */
    if (hal_motor_register(_motor_dev_t, "motor_main", RT_DEVICE_FLAG_RDWR, NULL) != RT_EOK) {
        return FMT_ERROR;
    }

    /* register rc hal device */
    if (hal_rc_register(_rc_dev_t, "rc", RT_DEVICE_FLAG_RDWR, NULL) != RT_EOK) {
        return FMT_ERROR;
    }

    /* create event */
    if (rt_event_init(&_fmtio_event, "fmtio", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }

    /* create static pkg for motor cmd */
    if (fmtio_init_pkg(PROTO_CMD_MOTOR, _motor_cmd, &_motor_cmd_pkg) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void task_fmtio_entry(void* parameter)
{
    rt_err_t rt_err;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_FMTIO_RX | EVENT_FMTIO_TX;

    _fmtio_dev = rt_device_find("fmtio_dev");

    if (_fmtio_dev == NULL) {
        console_printf("can not find fmtio device\n");
        return;
    }

    if (rt_device_open(_fmtio_dev, RT_DEVICE_FLAG_RDWR) != RT_EOK) {
        console_printf("fmtio device open fail\n");
        return;
    }

    /* set rx indicator */
    rt_device_set_rx_indicate(_fmtio_dev, fmtio_rx_ind);

    /* send sync cmd */
    fmtio_send_message(PROTO_CMD_SYNC, NULL, 0);

    while (1) {
        /* wait event happen or timeout */
        rt_err = rt_event_recv(&_fmtio_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            10, &recv_set);

        if (rt_err == RT_EOK || rt_err == -RT_ETIMEOUT) {
            if (recv_set & EVENT_FMTIO_RX) {
                _handle_rx_data();
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