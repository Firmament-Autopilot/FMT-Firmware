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
#include <firmament.h>

#include "ar1002_hal.h"
#include "hal/actuator/actuator.h"

// #define DRV_DBG(...) console_println(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ         (50)
#define PWM_FREQ_125HZ        (125)
#define PWM_FREQ_250HZ        (250)
#define PWM_FREQ_400HZ        (400)

// #define MAX_PWM_OUT_CHAN      10            // AUX Out has 10 pwm channel
#define MAX_PWM_OUT_CHAN      8              // AUX Out has 10 pwm channel
#define PWM_DEFAULT_FREQUENCY PWM_FREQ_400HZ // pwm default frequqncy

uint32_t g_pwm_high_level[MAX_PWM_OUT_CHAN]; // high level of the pwm wave
uint32_t g_pwm_freq[MAX_PWM_OUT_CHAN];       // high level of the pwm wave
// ENUM_HAL_PWM_NUM g_pwm_map[MAX_PWM_OUT_CHAN] = {    HAL_PWM_NUM0, HAL_PWM_NUM1, HAL_PWM_NUM2, HAL_PWM_NUM3, HAL_PWM_NUM4,
//                                                     HAL_PWM_NUM5, HAL_PWM_NUM6, HAL_PWM_NUM7, HAL_PWM_NUM8, HAL_PWM_NUM9 };
ENUM_HAL_PWM_NUM g_pwm_map[MAX_PWM_OUT_CHAN] = { HAL_PWM_NUM0, HAL_PWM_NUM1, HAL_PWM_NUM2, HAL_PWM_NUM3, HAL_PWM_NUM4, HAL_PWM_NUM5, HAL_PWM_NUM6, HAL_PWM_NUM7 };

void pwm_gpio_init(void)
{
}

void pwm_timer_init(void)
{
}

rt_err_t __set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    for (rt_int32_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        g_pwm_freq[i] = freq;
    }

    rt_uint32_t pwm_period_us = 1 * 1000000 / freq;

    for (rt_int32_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        HAL_PWM_DynamicModifyPwmDutyCycleByIntr(g_pwm_map[i], pwm_period_us - g_pwm_high_level[i], g_pwm_high_level[i]);
    }

    return RT_EOK;
}

rt_err_t pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

rt_err_t pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:

        /* set to lowest pwm before open */
        for (rt_uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            HAL_PWM_Start(g_pwm_map[i]);
        }

        DRV_DBG("aux out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:

        for (rt_uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            HAL_PWM_Stop(g_pwm_map[i]);
        }

        DRV_DBG("aux out disabled\n");
        break;
    case ACT_CMD_SET_PROTOCOL:
        /* TODO: Support dshot */
        ret = RT_EINVAL;
        break;

    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;

    for (rt_uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            *index = g_pwm_high_level[i];
            index++;
        }
    }

    return size;
}

rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;

    for (rt_uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            g_pwm_high_level[i] = *index;

            rt_uint32_t pwm_period_us = 1 * 1000000 / g_pwm_freq[i];

            /* update pwm signal */
            HAL_PWM_DynamicModifyPwmDutyCycleByIntr(g_pwm_map[i], pwm_period_us - g_pwm_high_level[i], g_pwm_high_level[i]);

            index++;
        }
    }

    return size;
}

const static struct actuator_ops __act_ops = {
    .act_config  = pwm_config,
    .act_control = pwm_control,
    .act_read    = pwm_read,
    .act_write   = pwm_write
};

// TODO modify channel mask
static struct actuator_device act_dev = {
    .chan_mask = 0x03FF,
    .range     = { 1000, 2000 },
    .config    = {
           .protocol     = ACT_PROTOCOL_PWM,
           .chan_num     = MAX_PWM_OUT_CHAN,
           .pwm_config   = { .pwm_freq = PWM_FREQ_400HZ },
           .dshot_config = { 0 } },
    .ops = &__act_ops
};

rt_err_t drv_pwm_init(void)
{
    rt_err_t ret = RT_EOK;

    /* init pwm setting */
    for (rt_int32_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        g_pwm_high_level[i] = 1000;
        g_pwm_freq[i]       = PWM_DEFAULT_FREQUENCY;
    }

    /* init pwm gpio pin */
    pwm_gpio_init();

    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    for (rt_uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        rt_uint32_t pwm_period_us = 1 * 1000000 / g_pwm_freq[i];
        HAL_PWM_RegisterPwmWithIntr(g_pwm_map[i], pwm_period_us - g_pwm_high_level[i], g_pwm_high_level[i]);
        // HAL_PWM_Start(g_pwm_map[i]);
    }

    /* register actuator hal device */
    ret = hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);

    return ret;
}