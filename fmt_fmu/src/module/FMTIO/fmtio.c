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
#include "hal/motor.h"
#include "hal/rc.h"
#include "hal/serial.h"
#include "module/fmtio/fmtio.h"

#define FMT_IO_PKG_BUFFER_SIZE  50
#define FMT_IO_PKG_DATA_SIZE    256
#define FMTIO_MOTOR_CHANNEL_NUM 8
#define FMTIO_RC_CHANNEL_NUM    16

#define EVENT_FMTIO_RX (1) // 1 << 0
#define EVENT_FMTIO_TX (2) // 1 << 1

/* default config for motor device */
#define MOTOR_CONFIG_DEFAULT           \
    {                                  \
        50,       /* 50Hz */           \
            8,    /* 8 channel */      \
            1000, /* minimal 1000us */ \
            2000, /* maximal 2000us */ \
    }

/* default config for rc device */
#define RC_CONFIG_DEFAULT               \
    {                                   \
        1,         /* sbus */           \
            6,     /* 6 channel */      \
            0.05f, /* sample time */    \
            1000,  /* minimal 1000us */ \
            2000,  /* maximal 2000us */ \
    }

/* fmtio device configuration */
typedef struct {
    uint32_t baud_rate; // serial baudrate
} fmtio_dev_config_t;

/* fmtio motor configuration */
typedef struct {
    uint16_t pwm_freq; // pwm output frequency
} fmtio_motor_config_t;

/* fmtio rc configuration */
typedef struct {
    uint16_t protocol; // 1:sbus 2:ppm
    float sample_time; // rc sample time in seconds (-1 for inherits)
} fmtio_rc_config_t;

/* fmtio full configuration */
typedef struct {
    fmtio_dev_config_t dev_config;
    fmtio_rc_config_t rc_config;
    fmtio_motor_config_t motor_config;
} fmtio_config_t;

typedef struct {
    uint32_t timestamp_ms;
    uint16_t rc_chan_val[FMTIO_RC_CHANNEL_NUM];
} rc_data_t;

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
static rc_dev_t _rc_dev_t = NULL;
static motor_dev_t _motor_dev_t = NULL;
static rc_data_t _rc_data;
static uint8_t _rc_updated = 0;
static uint16_t _motor_cmd[FMTIO_MOTOR_CHANNEL_NUM];
static PackageStruct _motor_cmd_pkg;
static fmtio_config_t _fmtio_default_config = {
    .dev_config = { 230400 },
    .rc_config = { 1, 0.05 },
    .motor_config = { 50 }
};
static uint8_t _sync_finish = 0;

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

static fmt_err _set_default_config(const fmtio_config_t default_config)
{
    if (fmtio_send_message(PROTO_CMD_RC_CONFIG, &default_config.rc_config, sizeof(fmtio_rc_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    if (fmtio_send_message(PROTO_CMD_MOTOR_CONFIG, &default_config.motor_config, sizeof(fmtio_motor_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    //TODO: Need update fmtio_dev baudrate
    if (fmtio_send_message(PROTO_CMD_DEV_CONFIG, &default_config.dev_config, sizeof(fmtio_dev_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

static fmt_err _local_rx_handler(const PackageStruct* pkg)
{
    switch (pkg->cmd) {
    case PROTO_CMD_SYNC: {
        /* we get sync message, try configure fmtio */
        _set_default_config(_fmtio_default_config);
    } break;

    case PROTO_DATA_RC: {
        uint16_t* index = (uint16_t*)pkg->content;

        for (uint8_t i = 0; i < pkg->len / 2; i++) {
            _rc_data.rc_chan_val[i] = *(index++);
        }

        _rc_data.timestamp_ms = systime_now_ms();
        _rc_updated = 1;

        hal_rc_rx_ind(_rc_dev_t, pkg->len);
    } break;

    default:
        break;
    }

    _sync_finish = 1;

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
            /* handle rx pkg locally */
            _local_rx_handler(&_rx_pkg);
            /* call user defined rx handler */
            if (_rx_handler) {
                _rx_handler(&_rx_pkg);
            }
        }
    }

    return FMT_EOK;
}

static rt_err_t _rc_configure(rc_dev_t rc, struct rc_configure* cfg)
{
    fmt_err err;
    fmtio_rc_config_t rc_config = {
        .protocol = cfg->protocol,
        .sample_time = cfg->sample_time
    };

    /* update default configuration */
    _fmtio_default_config.rc_config = rc_config;

    err = fmtio_send_message(PROTO_CMD_RC_CONFIG, &rc_config, sizeof(fmtio_rc_config_t));

    if (err == FMT_EOK) {
        rc->config = *cfg;
    }

    return err;
}

static rt_err_t _rc_control(rc_dev_t rc, int cmd, void* arg)
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

static rt_uint16_t _rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
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

    return chan_mask;
}

const static struct rc_ops _rc_ops = {
    _rc_configure,
    _rc_control,
    _rc_read,
};

static rt_err_t _motor_configure(motor_dev_t motor, struct motor_configure* cfg)
{
    fmt_err err;
    fmtio_motor_config_t config = {
        .pwm_freq = cfg->pwm_frequency
    };

    /* update default configuration */
    _fmtio_default_config.motor_config = config;

    err = fmtio_send_message(PROTO_CMD_MOTOR_CONFIG, &config, sizeof(config));
    if (err == FMT_EOK) {
        motor->config = *cfg;
    }

    return err;
}

static rt_err_t _motor_control(motor_dev_t motor, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case MOTOR_CMD_CHANNEL_ENABLE: {
        uint8_t enable = 1;

        ret = fmtio_send_message(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_CHANNEL_DISABLE: {
        uint8_t enable = 0;

        ret = fmtio_send_message(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_SET_FREQUENCY: {
        fmtio_motor_config_t config;

        config.pwm_freq = *(uint16_t*)arg;
        /* update default configuration */
        _fmtio_default_config.motor_config = config;

        ret = fmtio_send_message(PROTO_CMD_MOTOR_CONFIG, &config, sizeof(fmtio_motor_config_t));
    } break;

    default:
        break;
    }

    return ret;
}

static rt_size_t _motor_read(motor_dev_t motor, rt_uint16_t chan_mask, rt_uint16_t* chan_val, rt_size_t size)
{
    fmt_err err;
    PackageStruct pkg;

    create_io_package(PROTO_GET_MOTOR_VAL, sizeof(chan_mask), &pkg);

    err = fmtio_send_package(&chan_mask, sizeof(chan_mask), &pkg);

    return err == FMT_EOK ? size : 0;
}

static rt_size_t _motor_write(motor_dev_t motor, rt_uint16_t chan_mask, const rt_uint16_t* chan_val, rt_size_t size)
{
    uint16_t data[FMTIO_MOTOR_CHANNEL_NUM + 1];
    uint16_t max_size = FMTIO_MOTOR_CHANNEL_NUM * sizeof(uint16_t);
    uint16_t w_size = size <= max_size ? size : max_size;

    data[0] = chan_mask;
    memcpy(&data[1], chan_val, w_size);

    // 2 bytes for channel mask
    fmt_err err = fmtio_send_package(data, w_size + 2, &_motor_cmd_pkg);

    return err == FMT_EOK ? w_size : 0;
}

const static struct motor_ops _motor_ops = {
    _motor_configure,
    _motor_control,
    _motor_read,
    _motor_write
};

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
    }

    /* wakeup thread to send out pkg */
    rt_event_send(&_fmtio_event, EVENT_FMTIO_TX);

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

    /* try to configure fmtio at the beginning */
    _set_default_config(_fmtio_default_config);

    while (1) {
        /* wait event happen or timeout */
        rt_err = rt_event_recv(&_fmtio_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            10, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_FMTIO_RX) {
                _handle_rx();
            }
            if (recv_set & EVENT_FMTIO_TX) {
                _dump_pkg_buffer();
            }
        } else if (rt_err == -RT_ETIMEOUT) {
            _handle_rx();
            _dump_pkg_buffer();
        } else {
            //some err happen
            console_printf("fmtio event err:%d\n", rt_err);
        }
    }
}

fmt_err fmtio_init(void)
{
    static struct rc_device rc_dev = {
        .config = RC_CONFIG_DEFAULT,
        .ops = &_rc_ops
    };
    static struct motor_device motor_dev = {
        .config = MOTOR_CONFIG_DEFAULT,
        .ops = &_motor_ops
    };

    /* setup fmtio_dev device */
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

    rt_device_set_rx_indicate(_fmtio_dev, _io_rx_ind);

    /* setup fmtio virtual device */
    _rc_dev_t = &rc_dev;
    _motor_dev_t = &motor_dev;

    /* create static io pkg for motor cmd */
    if (init_io_package(PROTO_CMD_MOTOR, (uint8_t*)_motor_cmd, &_motor_cmd_pkg) != FMT_EOK) {
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

    return FMT_EOK;
}