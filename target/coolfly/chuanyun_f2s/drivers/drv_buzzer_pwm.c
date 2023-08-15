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
#include "hal_buzzer.h"

// #define DRV_DBG(...) console_println(__VA_ARGS__)
#define DRV_DBG(...)

// static const uint16_t g_notes_freq[84] = {
// 	0x0041, 0x0045, 0x0049, 0x004d, 0x0052, 0x0057, 0x005c,
// 	0x0061, 0x0067, 0x006e, 0x0074, 0x007b, 0x0082, 0x008a,
// 	0x0092, 0x009b, 0x00a4, 0x00ae, 0x00b8, 0x00c3, 0x00cf,
// 	0x00dc, 0x00e9, 0x00f6, 0x0105, 0x0115, 0x0125, 0x0137,
// 	0x0149, 0x015d, 0x0171, 0x0187, 0x019f, 0x01b8, 0x01d2,
// 	0x01ed, 0x020b, 0x022a, 0x024b, 0x026e, 0x0293, 0x02ba,
// 	0x02e3, 0x030f, 0x033e, 0x0370, 0x03a4, 0x03db, 0x0416,
// 	0x0454, 0x0496, 0x04dc, 0x0526, 0x0574, 0x05c7, 0x061f,
// 	0x067d, 0x06e0, 0x0748, 0x07b7, 0x082d, 0x08a9, 0x092d,
// 	0x09b9, 0x0a4d, 0x0ae9, 0x0b8f, 0x0c3f, 0x0cfa, 0x0dc0,
// 	0x0e91, 0x0f6f, 0x105a, 0x1152, 0x125a, 0x1372, 0x149a,
// 	0x15d3, 0x171f, 0x187f, 0x19f4, 0x1b80, 0x1d22, 0x1ede
// };

#define PWM_FREQ_0HZ                 (0)

#define PWM_FREQ_40HZ                (40)
#define PWM_FREQ_8000HZ              (8000)

#define BUZZER_PWM_DEFAULT_FREQUENCY PWM_FREQ_8000HZ // pwm default frequqncy
#define BUZZER_PWM_FREQUENCY_MIN     PWM_FREQ_40HZ
#define BUZZER_PWM_FREQUENCY_MAX     PWM_FREQ_8000HZ

#define BUZZER_PWM_CHAN_NUM          HAL_PWM_NUM9

// static uint32_t g_pwm_high_level;  // high level of the pwm wave
static uint32_t g_buzzer_pwm_freq; // high level of the pwm wave

void buzzer_pwm_gpio_init(void)
{
}

void buzzer_pwm_timer_init(void)
{
}

rt_err_t buzzer_pwm_config(buzzer_dev_t dev, const struct buzzer_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);
    if (cfg->pwm_config.pwm_freq < BUZZER_PWM_FREQUENCY_MIN || cfg->pwm_config.pwm_freq > BUZZER_PWM_FREQUENCY_MAX) {
        /* invalid frequency */
        DRV_DBG("Invalid buzzer pwm frequence");
        return RT_ERROR;
    }

    rt_uint32_t buzzer_pwm_period_us = 1 * 1000000 / cfg->pwm_config.pwm_freq;
    HAL_PWM_DynamicModifyPwmDutyCycleByIntr(BUZZER_PWM_CHAN_NUM, buzzer_pwm_period_us / 2, buzzer_pwm_period_us / 2);
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

rt_err_t buzzer_pwm_control(buzzer_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case BUZZER_CMD_CHANNEL_ENABLE:

        /* set to lowest pwm before open */
        HAL_PWM_Start(BUZZER_PWM_CHAN_NUM);

        DRV_DBG("buzzer pwm enabled\n");
        break;
    case BUZZER_CMD_CHANNEL_DISABLE:
        HAL_PWM_Stop(BUZZER_PWM_CHAN_NUM);

        DRV_DBG("buzzer pwm disabled\n");
        break;

    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

rt_size_t buzzer_pwm_read(buzzer_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    // TODO
    return size;
}

rt_size_t buzzer_pwm_write(buzzer_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    // const rt_uint16_t* index = chan_val;

    if (*chan_val == 0) {
        size = 0;
    } else {
        g_buzzer_pwm_freq         = *chan_val;
        rt_uint32_t pwm_period_us = 1 * 1000000 / g_buzzer_pwm_freq;

        /* update pwm signal */
        HAL_PWM_DynamicModifyPwmDutyCycleByIntr(BUZZER_PWM_CHAN_NUM, pwm_period_us / 2, pwm_period_us / 2);
        size = 2;
    }

    return size;
}

const static struct buzzer_ops __buzzer_ops = {
    .dev_config  = buzzer_pwm_config,
    .dev_control = buzzer_pwm_control,
    .dev_read    = buzzer_pwm_read,
    .dev_write   = buzzer_pwm_write
};

// TODO modify channel mask
static struct buzzer_device buzzer_dev = {
    .chan_mask = 0x0200,
    .range     = { 0, 8000 },
    .config    = {
           .channel    = BUZZER_PWM_CHAN_NUM,
           .pwm_config = { .pwm_freq = BUZZER_PWM_DEFAULT_FREQUENCY },
    },
    .ops = &__buzzer_ops
};

rt_err_t drv_buzzer_pwm_init(void)
{
    rt_err_t ret = RT_EOK;

    /* init pwm setting */
    g_buzzer_pwm_freq = BUZZER_PWM_DEFAULT_FREQUENCY;

    /* init pwm gpio pin */
    buzzer_pwm_gpio_init();

    /* init pwm timer, pwm output mode */
    buzzer_pwm_timer_init();

    rt_uint32_t pwm_period_us = 1 * 1000000 / g_buzzer_pwm_freq;

    // HAL_PWM_Stop(BUZZER_PWM_CHAN_NUM);

    HAL_PWM_RegisterPwmWithIntr(BUZZER_PWM_CHAN_NUM, pwm_period_us / 2, pwm_period_us / 2);
    // HAL_PWM_Start(g_pwm_map[i]);

    /* register actuator hal device */
    ret = hal_buzzer_register(&buzzer_dev, "buzzer_pwm", RT_DEVICE_FLAG_RDWR, NULL);
    DRV_DBG("hal buzzer_pwm dev registered");
    return ret;
}
