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
#include <board_device.h>

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

static struct rt_event fmtio_event;
/* suspend io package transfer */
static uint8_t io_comm_suspend = 0;
/* io send package buffer */
static PackageStruct _io_pkg_buff[FMT_IO_PKG_BUFFER_SIZE];
static uint16_t _pkg_buff_head = 0;
static uint16_t _pkg_buff_tail = 0;
/* send package data buffer */
static uint8_t _pkg_data[FMT_IO_PKG_DATA_SIZE];
/* io rx pkg */
static uint8_t _rx_pkg_buff[MAX_PACKAGE_SIZE];
static PackageStruct rx_pkg = {
    .content = _rx_pkg_buff
};
static rt_device_t fmtio_dev;
static fmtio_rx_handler_t _rx_handler = NULL;
static rc_dev_t _rc_dev_t = NULL;
static motor_dev_t _motor_dev_t = NULL;
static rc_data_t rc_data;
static uint8_t rc_updated = 0;
static uint16_t _motor_cmd[FMTIO_MOTOR_CHANNEL_NUM];
static PackageStruct _motor_cmd_pkg;
static fmtio_config_t fmtio_default_config = {
    .dev_config = { 230400 },
    .rc_config = { 1, 0.05 },
    .motor_config = { 50 }
};
static uint8_t sync_finish = 0;

static rt_err_t io_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* wakeup thread to handle received data */
    return rt_event_send(&fmtio_event, EVENT_FMTIO_RX);
}

static fmt_err_t dump_pkg_buffer(void)
{
    SendPkgStruct send_pkg;

    if (io_comm_suspend) {
        return FMT_EBUSY;
    }

    /* use static buffer to store pkg data which is going be sent */
    send_pkg.send_buff = _pkg_data;

    while (_pkg_buff_tail != _pkg_buff_head) {
        /* read pkg from buffer and make send pkg */
        FMT_CHECK_RETURN(make_send_package(_io_pkg_buff[_pkg_buff_tail], &send_pkg));

        /* send out pkg data */
        if (rt_device_write(fmtio_dev, RT_WAITING_FOREVER, send_pkg.send_buff, send_pkg.buff_size) == send_pkg.buff_size) {
            /* send success, free pkg and remove it from buffer */
            free_io_package(&_io_pkg_buff[_pkg_buff_tail]);
            OS_ENTER_CRITICAL;
            _pkg_buff_tail = (_pkg_buff_tail + 1) % FMT_IO_PKG_BUFFER_SIZE;
            OS_EXIT_CRITICAL;
        }
    }

    return FMT_EOK;
}

static fmt_err_t configure_default(const fmtio_config_t default_config)
{
    FMT_CHECK_RETURN(fmtio_send_cmd(PROTO_CMD_RC_CONFIG, &default_config.rc_config, sizeof(fmtio_rc_config_t)));
    FMT_CHECK_RETURN(fmtio_send_cmd(PROTO_CMD_MOTOR_CONFIG, &default_config.motor_config, sizeof(fmtio_motor_config_t)));
    //TODO: Need update fmtio_dev baudrate
    FMT_CHECK_RETURN(fmtio_send_cmd(PROTO_CMD_DEV_CONFIG, &default_config.dev_config, sizeof(fmtio_dev_config_t)));

    return FMT_EOK;
}

static fmt_err_t local_rx_handler(const PackageStruct* pkg)
{
    switch (pkg->cmd) {
    case PROTO_CMD_SYNC: {
        /* we get sync message, try configure fmtio */
        configure_default(fmtio_default_config);
    } break;

    case PROTO_DATA_RC: {
        uint16_t* index = (uint16_t*)pkg->content;

        for (uint8_t i = 0; i < pkg->len / 2; i++) {
            rc_data.rc_chan_val[i] = *(index++);
        }

        rc_data.timestamp_ms = systime_now_ms();
        rc_updated = 1;

        hal_rc_rx_ind(_rc_dev_t, pkg->len);
    } break;

    default:
        break;
    }

    /* if any package received, synchronize finish */
    sync_finish = 1;
    return FMT_EOK;
}

static fmt_err_t handle_rx(void)
{
    uint8_t c;

    if (io_comm_suspend) {
        return FMT_EBUSY;
    }

    while (rt_device_read(fmtio_dev, 0, &c, 1)) {
        if (proto_parse_package(c, &rx_pkg) == FMT_EOK) {
            /* handle rx pkg locally */
            local_rx_handler(&rx_pkg);
            /* call user defined rx handler */
            if (_rx_handler) {
                _rx_handler(&rx_pkg);
            }
        }
    }

    return FMT_EOK;
}

static rt_err_t rc_configure(rc_dev_t rc, struct rc_configure* cfg)
{
    fmt_err_t err;
    fmtio_rc_config_t rc_config = {
        .protocol = cfg->protocol,
        .sample_time = cfg->sample_time
    };

    /* update default configuration */
    fmtio_default_config.rc_config = rc_config;

    err = fmtio_send_cmd(PROTO_CMD_RC_CONFIG, &rc_config, sizeof(fmtio_rc_config_t));

    if (err == FMT_EOK) {
        rc->config = *cfg;
    }

    return err;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void* arg)
{
    switch (cmd) {
    case RC_CMD_CHECK_UPDATE: {
        *(uint8_t*)arg = rc_updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_uint16_t rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
{
    uint16_t* index = chan_val;

    if (!rc_updated)
        return 0;

    for (uint8_t i = 0; i < FMTIO_RC_CHANNEL_NUM; i++) {
        if (chan_mask & (1 << i)) {
            *(index++) = rc_data.rc_chan_val[i];
        }
    }

    rc_updated = 0;

    return chan_mask;
}

const static struct rc_ops _rc_ops = {
    rc_configure,
    rc_control,
    rc_read,
};

static rt_err_t motor_configure(motor_dev_t motor, struct motor_configure* cfg)
{
    fmt_err_t err;
    fmtio_motor_config_t config = {
        .pwm_freq = cfg->pwm_frequency
    };

    /* update default configuration */
    fmtio_default_config.motor_config = config;

    err = fmtio_send_cmd(PROTO_CMD_MOTOR_CONFIG, &config, sizeof(config));
    if (err == FMT_EOK) {
        motor->config = *cfg;
    }

    return err;
}

static rt_err_t motor_control(motor_dev_t motor, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case MOTOR_CMD_CHANNEL_ENABLE: {
        uint8_t enable = 1;

        ret = fmtio_send_cmd(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_CHANNEL_DISABLE: {
        uint8_t enable = 0;

        ret = fmtio_send_cmd(PROTO_CMD_PWM_SWITCH, &enable, 1);
    } break;

    case MOTOR_CMD_SET_FREQUENCY: {
        fmtio_motor_config_t config;

        config.pwm_freq = *(uint16_t*)arg;
        /* update default configuration */
        fmtio_default_config.motor_config = config;

        ret = fmtio_send_cmd(PROTO_CMD_MOTOR_CONFIG, &config, sizeof(fmtio_motor_config_t));
    } break;

    default:
        break;
    }

    return ret;
}

static rt_size_t motor_read(motor_dev_t motor, rt_uint16_t chan_mask, rt_uint16_t* chan_val, rt_size_t size)
{
    fmt_err_t err;
    PackageStruct pkg;

    if (create_io_package(PROTO_GET_MOTOR_VAL, sizeof(chan_mask), &pkg) != FMT_EOK) {
        return 0;
    }

    err = fmtio_send_package(&chan_mask, sizeof(chan_mask), &pkg);

    return err == FMT_EOK ? size : 0;
}

static rt_size_t motor_write(motor_dev_t motor, rt_uint16_t chan_mask, const rt_uint16_t* chan_val, rt_size_t size)
{
    uint16_t data[FMTIO_MOTOR_CHANNEL_NUM + 1];
    uint16_t max_size = FMTIO_MOTOR_CHANNEL_NUM * sizeof(uint16_t);
    uint16_t w_size = size <= max_size ? size : max_size;

    data[0] = chan_mask;
    memcpy(&data[1], chan_val, w_size);

    /* 2 bytes for channel mask */
    fmt_err_t err = fmtio_send_package(data, w_size + 2, &_motor_cmd_pkg);

    return err == FMT_EOK ? w_size : 0;
}

const static struct motor_ops _motor_ops = {
    motor_configure,
    motor_control,
    motor_read,
    motor_write
};

/**
 * @brief Register fmtio receive hander
 * 
 * @param rx_handler 
 * @return fmt_err_t 
 */
fmt_err_t fmtio_register_rx_handler(fmtio_rx_handler_t rx_handler)
{
    if (rx_handler == NULL) {
        return FMT_EINVAL;
    }

    _rx_handler = rx_handler;
    return FMT_EOK;
}

/**
 * @brief Get fmtio device
 * 
 * @return rt_device_t fmtio handler
 */
rt_device_t fmtio_get_device(void)
{
    return fmtio_dev;
}

/**
 * @brief Suspend fmtio communication
 * 
 * @param suspend 1: suspend 0: resume
 */
void fmtio_suspend_comm(uint8_t suspend)
{
    io_comm_suspend = suspend;

    if (suspend == 0) {
        /* wakeup thread to handle TX/RX event */
        rt_event_send(&fmtio_event, EVENT_FMTIO_RX);
        rt_event_send(&fmtio_event, EVENT_FMTIO_TX);
    }
}

/**
 * @brief Send a package to fmtio
 * 
 * @param data Package data
 * @param len Data length
 * @param pkg Package pointer
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t fmtio_send_package(const void* data, uint16_t len, PackageStruct* pkg)
{
    if (io_comm_suspend) {
        return FMT_EBUSY;
    }

    if ((_pkg_buff_head + 1) % FMT_IO_PKG_BUFFER_SIZE == _pkg_buff_tail) {
        console_printf("io package overflow\n");
        return FMT_EFULL;
    } else {
        /* write pkg content */
        FMT_CHECK_RETURN(fill_io_package(data, len, pkg));
        /* push pkg into send buffer */
        OS_ENTER_CRITICAL;
        _io_pkg_buff[_pkg_buff_head] = *pkg;
        _pkg_buff_head = (_pkg_buff_head + 1) % FMT_IO_PKG_BUFFER_SIZE;
        OS_EXIT_CRITICAL;
    }

    /* wakeup thread to send out pkg */
    rt_event_send(&fmtio_event, EVENT_FMTIO_TX);

    return FMT_EOK;
}

/**
 * @brief Send a command to fmtio
 * 
 * @param cmd Message command
 * @param data Message data
 * @param len Data length
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t fmtio_send_cmd(uint16_t cmd, const void* data, uint16_t len)
{
    PackageStruct pkg;

    /* Create an io package. Note that will dynamically malloc a memory space,
     * the memory will be freed when package is sent */
    FMT_CHECK_RETURN(create_io_package(cmd, len, &pkg));
    /* Send io package */
    FMT_CHECK_RETURN(fmtio_send_package(data, len, &pkg));

    return FMT_EOK;
}

/**
 * @brief FMTIO main loop
 * 
 */
void fmtio_loop(void)
{
    rt_err_t rt_err;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_FMTIO_RX | EVENT_FMTIO_TX;

    /* try to configure fmtio at the beginning */
    if (configure_default(fmtio_default_config) != FMT_EOK) {
        console_printf("Fail to configure fmtio\n");
    }

    while (1) {
        /* wait event happen or timeout */
        rt_err = rt_event_recv(&fmtio_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            10, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_FMTIO_RX) {
                handle_rx();
            }
            if (recv_set & EVENT_FMTIO_TX) {
                dump_pkg_buffer();
            }
        } else if (rt_err == -RT_ETIMEOUT) {
            handle_rx();
            dump_pkg_buffer();
        } else {
            console_printf("fmtio event err:%d\n", rt_err);
        }
    }
}

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops = &_rc_ops
};
static struct motor_device motor_dev = {
    .config = MOTOR_CONFIG_DEFAULT,
    .ops = &_motor_ops
};

/**
 * @brief Initialize fmtio module
 * 
 * @param dev_name io device name
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t fmtio_init(const char* dev_name)
{
    rt_device_t io_dev = rt_device_find(dev_name);

    /* setup fmtio device */
    RT_CHECK(hal_fmtio_dev_register(io_dev, "fmtio_dev", io_dev->flag, RT_NULL));

    fmtio_dev = rt_device_find("fmtio_dev");
    RT_ASSERT(fmtio_dev != NULL);

    /* create event */
    RT_CHECK(rt_event_init(&fmtio_event, "fmtio", RT_IPC_FLAG_FIFO));

    /* Find best capacity for fmtio device */
    rt_uint16_t oflag = RT_DEVICE_OFLAG_RDWR;
    if (io_dev->flag & RT_DEVICE_FLAG_DMA_TX) {
        oflag |= RT_DEVICE_FLAG_DMA_TX;
    }
    if (io_dev->flag & RT_DEVICE_FLAG_DMA_RX) {
        oflag |= RT_DEVICE_FLAG_DMA_RX;
    } else {
        oflag |= RT_DEVICE_FLAG_INT_RX;
    }
    RT_CHECK(rt_device_open(fmtio_dev, oflag));

    RT_CHECK(rt_device_set_rx_indicate(fmtio_dev, io_rx_ind));

    /* setup fmtio virtual device */
    _rc_dev_t = &rc_dev;
    _motor_dev_t = &motor_dev;

    /* create static io pkg for motor cmd */
    FMT_CHECK(init_io_package(PROTO_CMD_MOTOR, (uint8_t*)_motor_cmd, &_motor_cmd_pkg));

    /* register motor hal device */
    RT_CHECK(hal_motor_register(_motor_dev_t, "motor_main", RT_DEVICE_FLAG_RDWR, NULL));

    /* register rc hal device */
    RT_CHECK(hal_rc_register(_rc_dev_t, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return FMT_EOK;
}