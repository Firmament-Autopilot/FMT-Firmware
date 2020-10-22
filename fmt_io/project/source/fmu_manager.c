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
#include "fmu_manager.h"
#include "debug.h"
#include "ppm_decoder.h"
#include "pwm.h"
#include "sbus.h"
#include "usart.h"
#include <stdlib.h>
#include <string.h>

// static uint16_t _rc_proto = 0;  // 0:unset 1:sbus 2:ppm
static uint8_t _recv_sync = 0;
/* send package data buffer */
static uint8_t _pkg_data[256];
fmtio_rc_config_t rc_config = {
    .protocol = 1,
    .sample_time = 0.05
};
fmtio_motor_config_t motor_config = {
    .pwm_freq = 50
};

extern ppm_encoder_t ppm_param;

uint8_t rc_signal_ready(void)
{
    static uint32_t prev_time = 0;
    uint32_t time = time_nowMs();

    if (rc_config.sample_time <= 0) {
        // inherit sample time
        return 1;
    }

    if (time - prev_time >= (uint32_t)(rc_config.sample_time * 1e3 + 0.5)) {
        prev_time = time;
        return 1;
    }

    return 0;
}

FMT_Error fmt_init_pkg(uint16_t cmd, void* buffer, PackageStruct* pkg)
{
    return init_static_package(cmd, (uint8_t*)buffer, pkg);
}

FMT_Error fmt_create_pkg(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg)
{
    return init_package(cmd, buff_len, pkg);
}

FMT_Error fmt_send_pkg(const void* data, uint16_t len, PackageStruct* pkg)
{
    SendPkgStruct send_pkg;

    if (write_package((uint8_t*)data, len, pkg) != SYS_EOK) {
        return SYS_ERROR;
    }

    send_pkg.send_buff = _pkg_data;

    make_send_package(*pkg, &send_pkg);

    /* send via usart */
    send(send_pkg.send_buff, send_pkg.buff_size);

    /* after send, free it */
    free_package(pkg);

    return SYS_EOK;
}

FMT_Error fmt_send_message(uint16_t cmd, const void* data, uint16_t len)
{
    FMT_Error err;
    PackageStruct pkg;

    err = fmt_create_pkg(cmd, len, &pkg);

    if (err == SYS_EOK) {
        err = fmt_send_pkg(data, len, &pkg);
    }

    return err;
}

uint8_t fmt_sync_finish(void)
{
    return _recv_sync;
}

FMT_Error handle_fmu_package(const PackageStruct* pkg)
{
    FMT_Error err = SYS_EOK;
    PackageStruct reply_pkg;

    switch (pkg->cmd) {
    case PROTO_CMD_SYNC: {
        /* send sync ack */
        fmt_send_message(PROTO_ACK_SYNC, NULL, 0);
    } break;

    case PROTO_CMD_REBOOT: {
        /* reboot the system */
        NVIC_SystemReset();
    } break;

    case PROTO_CMD_MOTOR: {
        uint16_t chan_mask = *(uint16_t*)pkg->content;
        uint16_t* value = (uint16_t*)&pkg->content[2];

        handle_motor_pkg(chan_mask, value);
    } break;

    case PROTO_CMD_PWM_SWITCH: {
        int enable = pkg->content[0];
        pwm_configure(PWM_CMD_ENABLE, &enable);
    } break;

    case PROTO_CMD_CONFIG: {
        uint32_t baud_rate;

        baud_rate = *((uint32_t*)&pkg->content[0]);

        if (baud_rate) {
            usart_config_baud_rate(USART2, baud_rate);
        }
    } break;

    case PROTO_CMD_RC_CONFIG: {
        fmtio_rc_config_t new_config;
        new_config = *(fmtio_rc_config_t*)pkg->content;

        /* check if we need switch protocol */
        if (new_config.protocol && new_config.protocol != rc_config.protocol) {
            if (new_config.protocol == 1) {
                ppm_decoder_deinit();
                sbus_init();
            } else if (new_config.protocol == 2) {
                sbus_deinit();
                ppm_decoder_init();
            } else {
                debug("invalid rc protocol:%d\n", new_config.protocol);
                return SYS_EINVAL;
            }
        }
        rc_config = new_config;
    } break;

    case PROTO_CMD_MOTOR_CONFIG: {
        fmtio_motor_config_t new_config = *(fmtio_motor_config_t*)pkg->content;
        if (new_config.pwm_freq >= 50 && new_config.pwm_freq <= 400) {
            motor_config = new_config;
            pwm_configure(PWM_CMD_SET_FREQ, &motor_config.pwm_freq);
        }
    } break;

    case PROTO_DBG_TEXT: {
        char recv_str[256];

        if (pkg->len < 256) {
            strncpy(recv_str, pkg->content, pkg->len);
            recv_str[pkg->len] = '\0';

            if (strcmp("hello", recv_str) == 0) {
                /* say hello to FMU */
                debug("Hello, this is FMT IO!\n");
            }
        }
    } break;

    default: {
    }
    }

    /* set sync flag if we receive a valid pkg */
    _recv_sync = 1;

    return SYS_EOK;
}