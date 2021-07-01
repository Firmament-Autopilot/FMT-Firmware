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
#include "interface.h"
#include "debug.h"
#include "ppm_decoder.h"
#include "pwm.h"
#include "sbus.h"
#include "usart.h"
#include <stdlib.h>
#include <string.h>

static struct IOPacket rx_pkt, tx_pkt;
static uint8_t _recv_sync = 0;
IO_RCConfig rc_config = {
    .protocol = 1,
    .sample_time = 0.05
};
IO_ActuatorConfig motor_config = {
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

FMT_Error send_io_cmd(uint8_t code, void* data, uint16_t len)
{
    FMT_Error ret = SYS_ERROR;

    if (set_io_pkt(&tx_pkt, code, data, len) == SYS_EOK) {
        uint32_t w_size = PKT_SIZE(&tx_pkt);
        if (send((uint8_t*)&tx_pkt, w_size) == w_size) {
            ret = SYS_EOK;
        }
    }

    return ret;
}

uint8_t sync_finish(void)
{
    return _recv_sync;
}

FMT_Error handle_rx_packet(struct IOPacket* pkt)
{
    FMT_Error ret = SYS_EOK;
    uint8_t crc = pkt->crc;

    pkt->crc = 0;
    if (crc != crc_packet(pkt)) {
        return SYS_EINVAL;
    }

    switch (pkt->code) {
    case IO_CODE_SYNC: {
        _recv_sync = 1;
    } break;

    case IO_CODE_REBOOT: {
        uint16_t* magic = (uint16_t*)pkt->data;
        if (*magic == IO_REBOOT_MAGIC) {
            /* reboot the system */
            NVIC_SystemReset();
        } else {
            ret = SYS_EINVAL;
        }
    } break;

    case IO_CODE_W_ACTUATOR: {
        uint16_t chan_mask = *(uint16_t*)pkt->data;
        uint16_t* value = (uint16_t*)&pkt->data[2];

        handle_motor_pkt(chan_mask, value);
    } break;

    case IO_CODE_CTRL_ACTUATOR: {
        int enable = pkt->data[0];

        pwm_configure(PWM_CMD_ENABLE, &enable);
    } break;

    case IO_CODE_CONFIG_ACTUATOR: {
        IO_ActuatorConfig new_config = *((IO_ActuatorConfig*)pkt->data);

        if (new_config.pwm_freq >= 50 && new_config.pwm_freq <= 400) {
            motor_config = new_config;
            pwm_configure(PWM_CMD_SET_FREQ, &motor_config.pwm_freq);
        } else {
            ret = SYS_EINVAL;
        }
    } break;

    case IO_CODE_CONFIG_RC: {
        IO_RCConfig new_config = *((IO_RCConfig*)pkt->data);

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

    case IO_CODE_DBG_TEXT: {
        char recv_str[IO_BUFFER_SIZE];

        strncpy(recv_str, pkt->data, pkt->len);
        recv_str[pkt->len] = '\0';

        if (strcmp("hello", recv_str) == 0) {
            /* say hello to FMU */
            debug("Hello, this is FMT IO!\n");
        }
    } break;

    default:
        ret = SYS_EINVAL;
        break;
    }

    return ret;
}

void interface_listen(void)
{
    uint8_t c;
    if (read_ch(&c)) {
        if (io_parse_char(&rx_pkt, c) == SYS_EOK) {
            handle_rx_packet(&rx_pkt);
        }
    }
}

FMT_Error interface_init(void)
{
    init_io_pkt(&rx_pkt);
    init_io_pkt(&tx_pkt);
}