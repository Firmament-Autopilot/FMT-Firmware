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
#include "hal/actuator/actuator.h"
#include <stddef.h>
#include <string.h>
#include "drv_rc.h"

#define PWM_MIN_FREQ_HZ      (50U)
#define PWM_MAX_FREQ_HZ      (400U)
#define PWM_GROUP_CHAN_NUM   (8U)

static struct IOPacket rx_pkt, tx_pkt;
static uint8_t _recv_sync = 0;
static rt_device_t ipc_dev;
static rt_device_t pwm_main_dev;
static rt_device_t pwm_aux_dev;
IO_RCConfig rc_config = {
    .protocol = 1,
    .sample_time = 0.05f,
};
static IO_ActuatorConfig motor_config = {
    .pwm_freq = PWM_MIN_FREQ_HZ,
};

static rt_uint8_t pwm_count_bits(rt_uint16_t mask)
{
    rt_uint8_t cnt = 0;

    for (rt_uint8_t i = 0; i < 16U; i++) {
        if ((mask & (rt_uint16_t)(1U << i)) != 0U) {
            cnt++;
        }
    }

    return cnt;
}

static fmt_err_t pwm_open_devices(void)
{
    rt_bool_t has_output = RT_FALSE;

    if (pwm_main_dev == RT_NULL) {
        pwm_main_dev = rt_device_find("main_out");
        if ((pwm_main_dev != RT_NULL) && (rt_device_open(pwm_main_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK)) {
            pwm_main_dev = RT_NULL;
        }
    }

    if (pwm_aux_dev == RT_NULL) {
        pwm_aux_dev = rt_device_find("aux_out");
        if ((pwm_aux_dev != RT_NULL) && (rt_device_open(pwm_aux_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK)) {
            pwm_aux_dev = RT_NULL;
        }
    }

    if (pwm_main_dev != RT_NULL || pwm_aux_dev != RT_NULL) {
        has_output = RT_TRUE;
    }

    return has_output ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t pwm_write_output(rt_uint16_t chan_mask, const rt_uint16_t* value)
{
    rt_size_t wb;

    if (chan_mask == 0U) {
        return FMT_EOK;
    }

    if ((pwm_main_dev == RT_NULL) && (pwm_aux_dev == RT_NULL)) {
        return FMT_ERROR;
    }

    if ((pwm_main_dev == RT_NULL) ^ (pwm_aux_dev == RT_NULL)) {
        rt_device_t dev = (pwm_main_dev != RT_NULL) ? pwm_main_dev : pwm_aux_dev;
        rt_uint8_t chan_num = pwm_count_bits(chan_mask);

        wb = rt_device_write(dev, chan_mask, value, chan_num);
        return (wb == chan_num) ? FMT_EOK : FMT_ERROR;
    } else {
        rt_uint16_t main_mask = 0U;
        rt_uint16_t aux_mask = 0U;
        rt_uint16_t main_val[PWM_GROUP_CHAN_NUM];
        rt_uint16_t aux_val[PWM_GROUP_CHAN_NUM];
        rt_uint8_t main_cnt = 0U;
        rt_uint8_t aux_cnt = 0U;
        const rt_uint16_t* src = value;

        for (rt_uint8_t i = 0; i < 16U; i++) {
            if ((chan_mask & (rt_uint16_t)(1U << i)) == 0U) {
                continue;
            }

            if (i < PWM_GROUP_CHAN_NUM) {
                main_mask |= (rt_uint16_t)(1U << i);
                main_val[main_cnt++] = *src;
            } else {
                aux_mask |= (rt_uint16_t)(1U << (i - PWM_GROUP_CHAN_NUM));
                aux_val[aux_cnt++] = *src;
            }
            src++;
        }

        if (main_cnt > 0U) {
            wb = rt_device_write(pwm_main_dev, main_mask, main_val, main_cnt);
            if (wb != main_cnt) {
                return FMT_ERROR;
            }
        }

        if (aux_cnt > 0U) {
            wb = rt_device_write(pwm_aux_dev, aux_mask, aux_val, aux_cnt);
            if (wb != aux_cnt) {
                return FMT_ERROR;
            }
        }

        return FMT_EOK;
    }
}

static fmt_err_t pwm_control_output(rt_bool_t enable)
{
    int cmd = enable ? ACT_CMD_CHANNEL_ENABLE : ACT_CMD_CHANNEL_DISABLE;

    if ((pwm_main_dev == RT_NULL) && (pwm_aux_dev == RT_NULL)) {
        return FMT_ERROR;
    }

    if ((pwm_main_dev != RT_NULL) && (rt_device_control(pwm_main_dev, cmd, RT_NULL) != RT_EOK)) {
        return FMT_ERROR;
    }

    if ((pwm_aux_dev != RT_NULL) && (rt_device_control(pwm_aux_dev, cmd, RT_NULL) != RT_EOK)) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

static fmt_err_t pwm_config_output(const IO_ActuatorConfig* config)
{
    struct actuator_configure cfg;

    if ((config->pwm_freq < PWM_MIN_FREQ_HZ) || (config->pwm_freq > PWM_MAX_FREQ_HZ)) {
        return FMT_EINVAL;
    }

    if (pwm_main_dev != RT_NULL) {
        actuator_dev_t act = (actuator_dev_t)pwm_main_dev;

        if ((act->ops == RT_NULL) || (act->ops->act_config == RT_NULL)) {
            return FMT_ERROR;
        }

        cfg = act->config;
        cfg.pwm_config.pwm_freq = config->pwm_freq;

        if (act->ops->act_config(act, &cfg) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    if (pwm_aux_dev != RT_NULL) {
        actuator_dev_t act = (actuator_dev_t)pwm_aux_dev;

        if ((act->ops == RT_NULL) || (act->ops->act_config == RT_NULL)) {
            return FMT_ERROR;
        }

        cfg = act->config;
        cfg.pwm_config.pwm_freq = config->pwm_freq;

        if (act->ops->act_config(act, &cfg) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    motor_config = *config;

    return FMT_EOK;
}

uint16_t fmt_get_rc_proto(void)
{
    return rc_config.protocol;
}

uint8_t rc_signal_ready(void)
{
    static uint32_t prev_time = 0;
    uint32_t time = systime_now_ms();

    if (rc_config.sample_time <= 0) {
        /* inherit sample time */
        return 1;
    }

    if (time - prev_time >= (uint32_t)(rc_config.sample_time * 1e3f + 0.5f)) {
        prev_time = time;
        return 1;
    }

    return 0;
}

fmt_err_t send_io_cmd(uint8_t code, void* data, uint16_t len)
{
    fmt_err_t ret = FMT_ERROR;

    if ((ipc_dev != RT_NULL) && (set_io_pkt(&tx_pkt, code, data, len) == FMT_EOK)) {
        rt_size_t pkt_size = PKT_SIZE(&tx_pkt);
        rt_size_t wb = rt_device_write(ipc_dev, RT_WAITING_FOREVER, (void*)&tx_pkt, pkt_size);

        if (wb == pkt_size) {
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
        _recv_sync = 1;
    } break;

    case IO_CODE_REBOOT: {
        if (pkt->len < sizeof(uint16_t)) {
            ret = FMT_EINVAL;
            break;
        }

        uint16_t* magic = (uint16_t*)pkt->data;
        if (*magic == IO_REBOOT_MAGIC) {
            /* reboot the system */
            rt_hw_cpu_reset();
        } else {
            ret = FMT_EINVAL;
        }
    } break;

    case IO_CODE_W_ACTUATOR: {
        if (pkt->len < sizeof(uint16_t)) {
            ret = FMT_EINVAL;
            break;
        }

        rt_uint16_t chan_mask = *(rt_uint16_t*)pkt->data;
        const rt_uint16_t* value = (const rt_uint16_t*)&pkt->data[sizeof(rt_uint16_t)];

        if (pwm_open_devices() != FMT_EOK) {
            ret = FMT_ERROR;
            break;
        }

        ret = pwm_write_output(chan_mask, value);
    } break;

    case IO_CODE_CTRL_ACTUATOR: {
        if (pkt->len < 1U) {
            ret = FMT_EINVAL;
            break;
        }

        if (pwm_open_devices() != FMT_EOK) {
            ret = FMT_ERROR;
            break;
        }

        ret = pwm_control_output(pkt->data[0] != 0U ? RT_TRUE : RT_FALSE);
    } break;

    case IO_CODE_CONFIG_ACTUATOR: {
        if (pkt->len != sizeof(IO_ActuatorConfig)) {
            ret = FMT_EINVAL;
            break;
        }

        IO_ActuatorConfig new_config = *((IO_ActuatorConfig*)pkt->data);

        if (new_config.pwm_freq < PWM_MIN_FREQ_HZ || new_config.pwm_freq > PWM_MAX_FREQ_HZ) {
            ret = FMT_EINVAL;
            break;
        }

        motor_config = new_config;

        if (pwm_open_devices() != FMT_EOK) {
            ret = FMT_ERROR;
            break;
        }

        ret = pwm_config_output(&motor_config);
    } break;

    case IO_CODE_CONFIG_RC: {
        if (pkt->len != sizeof(IO_RCConfig)) {
            ret = FMT_EINVAL;
            break;
        }
        IO_RCConfig new_config = *((IO_RCConfig*)pkt->data);
        if (new_config.protocol && new_config.protocol != rc_config.protocol) {
            if (new_config.protocol == 1) {
                drv_rc_deinit();
                // sbus_init();
            } else if (new_config.protocol == 2) {
                // sbus_deinit();
                rc_init();
                drv_rc_thread_start();
            } else {
                debug("invalid rc protocol:%d\n", new_config.protocol);
                return FMT_EINVAL;
            }
        }

        rc_config = new_config;
    } break;

    case IO_CODE_DBG_TEXT: {
        char recv_str[IO_BUFFER_SIZE];
        size_t copy_len = pkt->len;

        if (copy_len >= IO_BUFFER_SIZE) {
            copy_len = IO_BUFFER_SIZE - 1U;
        }

        strncpy(recv_str, (char*)pkt->data, copy_len);
        recv_str[copy_len] = '\0';

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
    if ((ipc_dev != RT_NULL) && (rt_device_read(ipc_dev, RT_WAITING_NO, &c, 1) == 1)) {
        if (io_parse_char(&rx_pkt, c) == FMT_EOK) {
            handle_rx_packet(&rx_pkt);
        }
    }
}

fmt_err_t interface_init(void)
{
    init_io_pkt(&rx_pkt);
    init_io_pkt(&tx_pkt);

    pwm_main_dev = RT_NULL;
    pwm_aux_dev = RT_NULL;

    ipc_dev = rt_device_find("ipc0_dev");
    if (ipc_dev == RT_NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(ipc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }

    (void)pwm_open_devices();

    return FMT_EOK;
}