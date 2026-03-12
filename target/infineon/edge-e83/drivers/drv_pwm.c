/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include "cy_sysclk.h"
#include "cy_tcpwm.h"
#include "cycfg_peripheral_clocks.h"
#include "cycfg_peripherals.h"
#include "hal/actuator/actuator.h"

// #define DRV_DBG(...)          console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ          (50)
#define PWM_FREQ_125HZ         (125)
#define PWM_FREQ_250HZ         (250)
#define PWM_FREQ_400HZ         (400)

#define MAIN_PWM_CHAN          1
#define AUX_PWM_CHAN           1
#define PWM_DEFAULT_FREQUENCY  PWM_FREQ_400HZ

#define TIMER_FREQUENCY        10000000
#define VAL_TO_DC(_val, _freq) ((float)(_val) / (1000000.0f / _freq))
#define DC_TO_VAL(_dc, _freq)  (1000000.0f / _freq * _dc)

#define PWM_ARR(freq)          (TIMER_FREQUENCY / freq)

static uint32_t main_pwm_freq = PWM_DEFAULT_FREQUENCY;
static uint32_t aux_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float main_pwm_dc[MAIN_PWM_CHAN];
static float aux_pwm_dc[AUX_PWM_CHAN];

struct pwm_channel {
    TCPWM_Type* base;
    uint32_t cntNum;
    const cy_stc_tcpwm_pwm_config_t* pwm_config;
};

static const struct pwm_channel main_pwm_channels[MAIN_PWM_CHAN] = {
#ifdef BSP_USING_PWM5
    {
        .base = TCPWM0,
        .cntNum = 5,
        .pwm_config = &tcpwm_0_group_0_cnt_5_config,
    },
#endif
    // Add more main PWM channels here if needed
};

static const struct pwm_channel aux_pwm_channels[AUX_PWM_CHAN] = {
    // Add aux PWM channels here if needed
};

rt_inline void __main_read_pwm(uint8_t chan_id, float* dc)
{
    *dc = main_pwm_dc[chan_id];
}

rt_inline void __aux_read_pwm(uint8_t chan_id, float* dc)
{
    *dc = aux_pwm_dc[chan_id];
}

rt_inline void __main_write_pwm(uint8_t chan_id, float dc)
{
    if (chan_id >= MAIN_PWM_CHAN) {
        return;
    }

    const struct pwm_channel* pwm = &main_pwm_channels[chan_id];
    uint32_t arr = TIMER_FREQUENCY / main_pwm_freq;
    uint32_t compare = (uint32_t)(arr * dc);

    Cy_TCPWM_PWM_SetPeriod0(pwm->base, pwm->cntNum, arr);
    Cy_TCPWM_PWM_SetCompare0Val(pwm->base, pwm->cntNum, compare);

    main_pwm_dc[chan_id] = dc;
}

rt_inline void __aux_write_pwm(uint8_t chan_id, float dc)
{
    if (chan_id >= AUX_PWM_CHAN) {
        return;
    }

    const struct pwm_channel* pwm = &aux_pwm_channels[chan_id];
    uint32_t arr = TIMER_FREQUENCY / aux_pwm_freq;
    uint32_t compare = (uint32_t)(arr * dc);

    Cy_TCPWM_PWM_SetPeriod0(pwm->base, pwm->cntNum, arr);
    Cy_TCPWM_PWM_SetCompare0Val(pwm->base, pwm->cntNum, compare);

    aux_pwm_dc[chan_id] = dc;
}

rt_inline rt_err_t __main_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        return RT_EINVAL;
    }

    main_pwm_freq = freq;

    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        __main_write_pwm(i, main_pwm_dc[i]);
    }

    return RT_EOK;
}

rt_inline rt_err_t __aux_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        return RT_EINVAL;
    }

    aux_pwm_freq = freq;

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        __aux_write_pwm(i, aux_pwm_dc[i]);
    }

    return RT_EOK;
}

static rt_err_t main_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("main out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__main_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__aux_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t main_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
            __main_write_pwm(i, VAL_TO_DC(1000, main_pwm_freq));
        }

        for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
            const struct pwm_channel* pwm = &main_pwm_channels[i];
            Cy_TCPWM_PWM_Enable(pwm->base, pwm->cntNum);
            Cy_TCPWM_TriggerStart_Single(pwm->base, pwm->cntNum);
        }

        DRV_DBG("main out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
            const struct pwm_channel* pwm = &main_pwm_channels[i];
            Cy_TCPWM_PWM_Disable(pwm->base, pwm->cntNum);
        }

        DRV_DBG("main out disabled\n");
        break;
    case ACT_CMD_SET_PROTOCOL:
        ret = RT_EINVAL;
        break;
    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

static rt_err_t aux_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
            __aux_write_pwm(i, VAL_TO_DC(1000, aux_pwm_freq));
        }

        for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
            const struct pwm_channel* pwm = &aux_pwm_channels[i];
            Cy_TCPWM_PWM_Enable(pwm->base, pwm->cntNum);
            Cy_TCPWM_TriggerStart_Single(pwm->base, pwm->cntNum);
        }

        DRV_DBG("aux out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
            const struct pwm_channel* pwm = &aux_pwm_channels[i];
            Cy_TCPWM_PWM_Disable(pwm->base, pwm->cntNum);
        }

        DRV_DBG("aux out disabled\n");
        break;
    case ACT_CMD_SET_PROTOCOL:
        ret = RT_EINVAL;
        break;
    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

rt_size_t main_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            __main_read_pwm(i, &dc);
            *index = DC_TO_VAL(dc, main_pwm_freq);
            index++;
        }
    }

    return size;
}

static rt_size_t aux_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            __aux_read_pwm(i, &dc);
            *index = DC_TO_VAL(dc, aux_pwm_freq);
            index++;
        }
    }

    return size;
}

rt_size_t main_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            dc = VAL_TO_DC(val, main_pwm_freq);
            __main_write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

static rt_size_t aux_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            dc = VAL_TO_DC(val, aux_pwm_freq);
            __aux_write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

const static struct actuator_ops main_act_ops = {
    .act_config = main_pwm_config,
    .act_control = main_pwm_control,
    .act_read = main_pwm_read,
    .act_write = main_pwm_write
};

const static struct actuator_ops aux_act_ops = {
    .act_config = aux_pwm_config,
    .act_control = aux_pwm_control,
    .act_read = aux_pwm_read,
    .act_write = aux_pwm_write
};

static struct actuator_device main_act_dev = {
    .chan_mask = (MAIN_PWM_CHAN == 4) ? 0x0F : 0x0FFF,
    .range = { 1000, 2000 },
    .config = { .protocol = ACT_PROTOCOL_PWM,
                .chan_num = MAIN_PWM_CHAN,
                .pwm_config = { .pwm_freq = PWM_DEFAULT_FREQUENCY },
                .dshot_config = { 0 } },
    .ops = &main_act_ops
};

static struct actuator_device aux_act_dev = {
    .chan_mask = (AUX_PWM_CHAN == 4) ? 0x0F : 0x0FFF,
    .range = { 1000, 2000 },
    .config = { .protocol = ACT_PROTOCOL_PWM,
                .chan_num = AUX_PWM_CHAN,
                .pwm_config = { .pwm_freq = PWM_DEFAULT_FREQUENCY },
                .dshot_config = { 0 } },
    .ops = &aux_act_ops
};

rt_err_t drv_pwm_init(void)
{
    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        const struct pwm_channel* pwm = &main_pwm_channels[i];
        if (pwm->base && pwm->pwm_config) {
            cy_en_tcpwm_status_t status = Cy_TCPWM_PWM_Init(pwm->base, pwm->cntNum, pwm->pwm_config);
            if (status != CY_RSLT_SUCCESS) {
                DRV_DBG("Initialize TCPWM PWM channel %d failed\n", i);
                return RT_ERROR;
            }
        }
    }

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        const struct pwm_channel* pwm = &aux_pwm_channels[i];
        if (pwm->base && pwm->pwm_config) {
            cy_en_tcpwm_status_t status = Cy_TCPWM_PWM_Init(pwm->base, pwm->cntNum, pwm->pwm_config);
            if (status != CY_RSLT_SUCCESS) {
                DRV_DBG("Initialize TCPWM PWM channel %d failed\n", i);
                return RT_ERROR;
            }
        }
    }

    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        main_pwm_dc[i] = 0.0f;
    }

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        aux_pwm_dc[i] = 0.0f;
    }

    RT_TRY(hal_actuator_register(&main_act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL));
    RT_TRY(hal_actuator_register(&aux_act_dev, "aux_out", RT_DEVICE_FLAG_RDWR, NULL));

    DRV_DBG("E83 M55 PWM driver initialized\n");
    return RT_EOK;
}