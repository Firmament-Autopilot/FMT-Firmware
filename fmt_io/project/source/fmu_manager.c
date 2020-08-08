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
#include "usart.h"
#include <stdlib.h>
#include <string.h>

static uint8_t _recv_sync = 0;
/* send package data buffer */
static uint8_t _pkg_data[256];

extern ppm_encoder_t ppm_param;

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
        uint16_t val;
        float duty_cyc[MAX_PWM_CHAN] = { 0.0 };
        uint16_t* val_ptr = (uint16_t*)&pkg->content[2];

        for (uint8_t i = 0; i < MAX_PWM_CHAN; i++) {
            if (chan_mask & 1 << i) {
                val = *val_ptr;
                if (val > 2000) {
                    val = 2000;
                } else if (val < 1000) {
                    val = 1000;
                }
                val_ptr++;
                duty_cyc[i] = 0.00005f * val;
            }
        }

        pwm_write(duty_cyc, (uint8_t)chan_mask);
    } break;

    case PROTO_CMD_PWM_SWITCH: {
        int enable = pkg->content[0];
        pwm_configure(PWM_CMD_ENABLE, &enable);
    } break;

    case PROTO_CMD_CONFIG: {
        uint32_t baud_rate;
        uint16_t rc_chan_num;
        uint16_t pwm_freq;

        // int freq = *(uint16_t*)pkg->content;

        if (pkg->len != 8) {
            return SYS_ERROR;
        }

        baud_rate = *((uint32_t*)&pkg->content[0]);
        rc_chan_num = *((uint16_t*)&pkg->content[4]);
        pwm_freq = *((uint16_t*)&pkg->content[6]);

        if (baud_rate) {
            usart_config_baud_rate(USART2, baud_rate);
            debug("set baud rate:%d\n", baud_rate);
        }

        if (rc_chan_num) {
            ppm_set_max_rc_chan(rc_chan_num);
            debug("set rc channel num:%d\n", rc_chan_num);
        }

        if (pwm_freq) {
            pwm_configure(PWM_CMD_SET_FREQ, &pwm_freq);
            debug("set pwm frequency:%d\n", pwm_freq);
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