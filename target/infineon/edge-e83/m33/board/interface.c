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
#include <string.h>

static struct IOPacket rx_pkt, tx_pkt;
static uint8_t _recv_sync = 0;
static rt_device_t ipc_dev;

// IO_RCConfig rc_config = {
//     .protocol = 1,
//     .sample_time = 0.05
// };
// IO_ActuatorConfig motor_config = {
//     .pwm_freq = 50
// };

// extern ppm_encoder_t ppm_param;

// uint8_t rc_signal_ready(void)
// {
//     static uint32_t prev_time = 0;
//     uint32_t time = time_nowMs();

//     if (rc_config.sample_time <= 0) {
//         // inherit sample time
//         return 1;
//     }

//     if (time - prev_time >= (uint32_t)(rc_config.sample_time * 1e3 + 0.5)) {
//         prev_time = time;
//         return 1;
//     }

//     return 0;
// }

fmt_err_t send_io_cmd(uint8_t code, void* data, uint16_t len)
{
    fmt_err_t ret = FMT_ERROR;

    if (set_io_pkt(&tx_pkt, code, data, len) == FMT_EOK) {
        // uint32_t w_size = PKT_SIZE(&tx_pkt);
        // if (send((uint8_t*)&tx_pkt, w_size) == w_size) {
        //     ret = FMT_EOK;
        // }

        if (rt_device_write(ipc_dev, RT_WAITING_FOREVER, (void*)&tx_pkt, PKT_SIZE(&tx_pkt))) {
            ret = FMT_EOK;
        }
    }

    return ret;
}

uint8_t sync_finish(void)
{
    return _recv_sync;
}

fmt_err_t handle_rx_packet(struct IOPacket* pkt)
{
    fmt_err_t ret = FMT_EOK;
    uint8_t crc = pkt->crc;

    pkt->crc = 0;
    if (crc != crc_packet(pkt)) {
        return FMT_EINVAL;
    }

    switch (pkt->code) {
    case IO_CODE_SYNC: {
        printf("get sync.\n");
        _recv_sync = 1;
    } break;

    case IO_CODE_REBOOT: {
        uint16_t* magic = (uint16_t*)pkt->data;
        if (*magic == IO_REBOOT_MAGIC) {
            /* reboot the system */
            rt_hw_cpu_reset();
        } else {
            ret = FMT_EINVAL;
        }
    } break;

    case IO_CODE_W_ACTUATOR: {
        // uint16_t chan_mask = *(uint16_t*)pkt->data;
        // uint16_t* value = (uint16_t*)&pkt->data[2];

        // handle_motor_pkt(chan_mask, value);
    } break;

    case IO_CODE_CTRL_ACTUATOR: {
        // int enable = pkt->data[0];

        // pwm_configure(PWM_CMD_ENABLE, &enable);
    } break;

    case IO_CODE_CONFIG_ACTUATOR: {
        // IO_ActuatorConfig new_config = *((IO_ActuatorConfig*)pkt->data);

        // if (new_config.pwm_freq >= 50 && new_config.pwm_freq <= 400) {
        //     motor_config = new_config;
        //     pwm_configure(PWM_CMD_SET_FREQ, &motor_config.pwm_freq);
        // } else {
        //     ret = FMT_EINVAL;
        // }
    } break;

    case IO_CODE_CONFIG_RC: {
        // IO_RCConfig new_config = *((IO_RCConfig*)pkt->data);

        // /* check if we need switch protocol */
        // if (new_config.protocol && new_config.protocol != rc_config.protocol) {
        //     if (new_config.protocol == 1) {
        //         ppm_decoder_deinit();
        //         sbus_init();
        //     } else if (new_config.protocol == 2) {
        //         sbus_deinit();
        //         ppm_decoder_init();
        //     } else {
        //         debug("invalid rc protocol:%d\n", new_config.protocol);
        //         return FMT_EINVAL;
        //     }
        // }
        // rc_config = new_config;
    } break;

    case IO_CODE_DBG_TEXT: {
        char recv_str[IO_BUFFER_SIZE];

        strncpy(recv_str, (char*)pkt->data, pkt->len);
        recv_str[pkt->len] = '\0';

        if (strcmp("hello", recv_str) == 0) {
            /* say hello to FMU */
            debug("Hello, this is FMT IO!\n");
        }
    } break;

    default:
        ret = FMT_EINVAL;
        break;
    }

    return ret;
}

void interface_listen(void)
{
    uint8_t c;
    if (rt_device_read(ipc_dev, RT_WAITING_NO, &c, 1)) {
        if (io_parse_char(&rx_pkt, c) == FMT_EOK) {
            handle_rx_packet(&rx_pkt);
        }
    }
}

fmt_err_t interface_init(void)
{
    init_io_pkt(&rx_pkt);
    init_io_pkt(&tx_pkt);

    ipc_dev = rt_device_find("ipc0_dev");

    if (rt_device_open(ipc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("[M33][IPC_DEV] open device failed\r\n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}