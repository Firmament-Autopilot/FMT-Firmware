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

#include "hal/actuator/actuator.h"

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ  (50)
#define PWM_FREQ_125HZ (125)
#define PWM_FREQ_250HZ (250)
#define PWM_FREQ_400HZ (400)

#define MAX_PWM_OUT_CHAN      4             // AUX Out has 8 pwm channel
#define TIMER_FREQUENCY       5000000       // Timer frequency: 5M
#define PWM_DEFAULT_FREQUENCY PWM_FREQ_50HZ // pwm default frequqncy
#define VAL_TO_DC(_val)       ((float)(_val * __pwm_freq) / 1000000.0f)
#define DC_TO_VAL(_dc)        (1000000.0f / __pwm_freq * _dc)

#define PWM_ARR(freq) (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;
static float __pwm_dc[MAX_PWM_OUT_CHAN];

void pwm_gpio_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOB);

    /* Configure PB3 PB10 PB11(TIMER1 CH1 CH2 CH3) as alternate function */
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_3);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_10);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11);

    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_3);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_10);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_11);
}

void pwm_timer_init(void)
{
    /* Configured by system_clock_200m_8m_hxtal(), AHB = SYSCLK, APB1 = AHB/4, APB2 = AHB/2 */
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    uint32_t APB1_2_PrescalerValue;

    /* TIMER1 configuration */
    rcu_periph_clock_enable(RCU_TIMER1);

    /* When TIMERSEL is set, the TIMER clock is equal to CK_AHB(CK_TIMERx = CK_AHB). */
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);

    /* APB1_2_PrescalerValue = SystemCoreClock / TARGET_TIMER_CLK */
    APB1_2_PrescalerValue = SystemCoreClock / TIMER_FREQUENCY - 1;

    timer_deinit(TIMER1);
    timer_initpara.prescaler = APB1_2_PrescalerValue;
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = PWM_ARR(__pwm_freq) - 1;
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1, &timer_initpara);

    /* CH1,CH2 and CH3 configuration in PWM mode */
    timer_ocintpara.ocpolarity = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    timer_channel_output_config(TIMER1, TIMER_CH_1, &timer_ocintpara);
    timer_channel_output_config(TIMER1, TIMER_CH_2, &timer_ocintpara);
    timer_channel_output_config(TIMER1, TIMER_CH_3, &timer_ocintpara);

    timer_channel_output_mode_config(TIMER1, TIMER_CH_1, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);

    /* CH2 configuration in PWM mode1,duty cycle 50% */
    timer_channel_output_mode_config(TIMER1, TIMER_CH_2, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_2, TIMER_OC_SHADOW_DISABLE);

    /* CH3 configuration in PWM mode1,duty cycle 75% */
    timer_channel_output_mode_config(TIMER1, TIMER_CH_3, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER1);
}

rt_inline void __read_pwm(uint8_t chan_id, float* dc)
{
    *dc = __pwm_dc[chan_id];
}

rt_inline void __write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_0, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 1:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_1, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 2:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_2, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 3:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_3, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    default:
        break;
    }

    __pwm_dc[chan_id] = dc;
}

rt_err_t __set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    __pwm_freq = freq;

    timer_autoreload_value_config(TIMER1, PWM_ARR(__pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        __write_pwm(i, __pwm_dc[i]);
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
        for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            __write_pwm(i, VAL_TO_DC(1000));
        }

        /* auto-reload preload enable */
        timer_enable(TIMER1);
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        /* auto-reload preload disable */
        timer_disable(TIMER1);
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
    float dc;

    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            __read_pwm(i, &dc);
            *index = DC_TO_VAL(dc);
            index++;
        }
    }

    return size;
}

rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val);
            /* update pwm signal */
            __write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

const static struct actuator_ops __act_ops = {
    .dev_config = pwm_config,
    .dev_control = pwm_control,
    .dev_read = pwm_read,
    .dev_write = pwm_write
};

//TODO modify channel mask
static struct actuator_device act_dev = {
    .chan_mask = 0xFF,
    .range = { 1000, 2000 },
    .config = {
        .protocol = ACT_PROTOCOL_PWM,
        .chan_num = MAX_PWM_OUT_CHAN,
        .pwm_config = { .pwm_freq = 50 },
        .dshot_config = { 0 } },
    .ops = &__act_ops
};

rt_err_t drv_pwm_init(void)
{
    rt_err_t ret = RT_EOK;

    /* init pwm gpio pin */
    pwm_gpio_init();
    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    /* register actuator hal device */
    ret = hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);

    return ret;
}