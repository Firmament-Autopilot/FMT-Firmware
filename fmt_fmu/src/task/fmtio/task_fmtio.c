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

#include "hal/motor.h"
#include "hal/rc.h"
#include "hal/serial.h"
#include "module/fmtio/fmtio.h"
#include "task/task_fmtio.h"

#define FMTIO_MOTOR_CHANNEL_NUM 8
#define FMTIO_RC_CHANNEL_NUM    16

/* default config for motor device */
#define MOTOR_CONFIG_DEFAULT           \
    {                                  \
        50, /* 50Hz */                 \
            8,                         \
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

typedef struct {
    uint32_t baud_rate; // serial baudrate
} fmtio_config_t;

typedef struct {
    uint16_t pwm_freq; // pwm output frequency
} fmtio_motor_config_t;

typedef struct {
    uint16_t protocol; // 1:sbus 2:ppm
    float sample_time; // rc sample time in seconds (-1 for inherits)
} fmtio_rc_config_t;

typedef struct {
    uint32_t timestamp_ms;
    uint16_t rc_chan_val[FMTIO_RC_CHANNEL_NUM];
} rc_data_t;

typedef struct {
    fmtio_config_t io_config;
    fmtio_rc_config_t rc_config;
    fmtio_motor_config_t motor_config;
} fmtio_full_config_t;

/* rc channel value */
static rc_data_t _rc_data;
static uint8_t _rc_updated = 0;
static rc_dev_t _rc_dev_t;
static motor_dev_t _motor_dev_t;
static fmtio_full_config_t _io_default_config = {
    .io_config = { 230400 },
    .rc_config = { 1, 0.05 },
    .motor_config = { 50 }
};

static uint16_t _motor_cmd[FMTIO_MOTOR_CHANNEL_NUM];
static PackageStruct _motor_cmd_pkg;

static uint8_t _sync_finish = 0;

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

static fmt_err _fmtio_set_default_config(const fmtio_full_config_t default_config)
{
    if (fmtio_send_message(PROTO_CMD_RC_CONFIG, &default_config.rc_config, sizeof(fmtio_rc_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    if (fmtio_send_message(PROTO_CMD_MOTOR_CONFIG, &default_config.motor_config, sizeof(fmtio_motor_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    //TODO: Need update fmtio serial device baudrate
    if (fmtio_send_message(PROTO_CMD_CONFIG, &default_config.io_config, sizeof(fmtio_config_t)) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

static fmt_err _handle_rx_package(const PackageStruct* pkg)
{
    switch (pkg->cmd) {
    case PROTO_CMD_SYNC: {
        /* reply sync ack */
        _fmtio_set_default_config(_io_default_config);
    } break;

    case PROTO_DBG_TEXT: {
        console_printf("[IO]:", systime_now_ms());
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

    default:
        break;
    }

    _sync_finish = 1;

    return FMT_EOK;
}

static rt_err_t _motor_configure(motor_dev_t motor, struct motor_configure* cfg)
{
    fmt_err err;
    fmtio_motor_config_t config = {
        .pwm_freq = cfg->pwm_frequency
    };

    /* update default configuration */
    _io_default_config.motor_config = config;

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
        _io_default_config.motor_config = config;

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

static rt_err_t _rc_configure(rc_dev_t rc, struct rc_configure* cfg)
{
    fmt_err err;
    fmtio_rc_config_t rc_config = {
        .protocol = cfg->protocol,
        .sample_time = cfg->sample_time
    };

    /* update default configuration */
    _io_default_config.rc_config = rc_config;

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

/**************************** Public Function ********************************/
fmt_err task_fmtio_init(void)
{
    static struct motor_device motor_dev = {
        .config = MOTOR_CONFIG_DEFAULT,
        .ops = &_motor_ops
    };
    static struct rc_device rc_dev = {
        .config = RC_CONFIG_DEFAULT,
        .ops = &_rc_ops
    };

    _motor_dev_t = &motor_dev;
    _rc_dev_t = &rc_dev;

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

    if (fmtio_init() != FMT_EOK) {
        return FMT_ERROR;
    }

    if (fmtio_register_rx_handler(_handle_rx_package) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void task_fmtio_entry(void* parameter)
{
    /* send sync cmd */
    _fmtio_set_default_config(_io_default_config);
    /* execute fmtio main loop */
    fmtio_loop();
}