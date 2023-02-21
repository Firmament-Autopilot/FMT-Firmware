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

#define MAX_PWM_OUT_CHAN      10            // Main Out has 10 pwm channel
#define TIMER_FREQUENCY       2500000       // Timer frequency: 2.5M
#define PWM_DEFAULT_FREQUENCY PWM_FREQ_50HZ // pwm default frequqncy
#define VAL_TO_DC(_val)       ((float)(_val * __pwm_freq) / 1000000.0f)
#define DC_TO_VAL(_dc)        (1000000.0f / __pwm_freq * _dc)

#define PWM_ARR(freq) (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static rt_err_t pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg);
static rt_err_t pwm_control(actuator_dev_t dev, int cmd, void* arg);
static rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
static rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);

const static struct actuator_ops __act_ops = {
    .act_config = pwm_config,
    .act_control = pwm_control,
    .act_read = pwm_read,
    .act_write = pwm_write
};

static struct actuator_device act_dev = {
    .chan_mask = 0x3FF,
    .range = { 1000, 2000 },
    .config = {
        .protocol = ACT_PROTOCOL_PWM,
        .chan_num = MAX_PWM_OUT_CHAN,
        .pwm_config = { .pwm_freq = 50 },
        .dshot_config = { 0 } },
    .ops = &__act_ops
};

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;
static float __pwm_dc[MAX_PWM_OUT_CHAN];

static void pwm_gpio_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);

    /* Configure PE9 PE11 PE13 PE14 (TIMER0 CH0 CH1 CH2 CH3) as alternate function */
    gpio_mode_set(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14);
    gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14);

    gpio_af_set(GPIOE, GPIO_AF_1, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14);

    /* Configure PA15 PB3 PA3 (TIMER1 CH0 CH1 CH3) as alternate function */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_3 | GPIO_PIN_15);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3 | GPIO_PIN_15);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_3);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3);

    gpio_af_set(GPIOA, GPIO_AF_1, GPIO_PIN_3 | GPIO_PIN_15);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_3);

    /* Configure PD13 PD14 PD15 (TIMER3 CH1 CH2 CH3) as alternate function */
    gpio_mode_set(GPIOD, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
    gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

    gpio_af_set(GPIOD, GPIO_AF_2, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
}

static void pwm_timer_init(void)
{
    /* Configured by system_clock_240m_8m_hxtal(), AHB = SYSCLK, APB1 = AHB/4, APB2 = AHB/2 */
    timer_oc_parameter_struct timer_ocintpara;
    uint16_t timer_psc;
    timer_parameter_struct timer_initpara;

    /* TIMER clock configuration */
    rcu_periph_clock_enable(RCU_TIMER0);
    rcu_periph_clock_enable(RCU_TIMER1);
    rcu_periph_clock_enable(RCU_TIMER3);

    /* When TIMERSEL is set, the TIMER clock is equal to CK_AHB(CK_TIMERx = CK_AHB) if APB1 = AHB/4, APB2 = AHB/2s. */
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);

    /* Timer_PSC = CK_AHB / TARGET_TIMER_CK */
    timer_psc = rcu_clock_freq_get(CK_AHB) / TIMER_FREQUENCY - 1;
    /* Timer init parameter */
    timer_initpara.prescaler = timer_psc;
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = PWM_ARR(__pwm_freq) - 1;
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;

    /* Timer deinit */
    timer_deinit(TIMER0);
    timer_deinit(TIMER1);
    timer_deinit(TIMER3);
    /* Timer0 must enable primary output to enable pwm output */
    timer_primary_output_config(TIMER0, ENABLE);
    /* Timer init */
    timer_init(TIMER0, &timer_initpara);
    timer_init(TIMER1, &timer_initpara);
    timer_init(TIMER3, &timer_initpara);

    /* Timer channel configuration in PWM mode */
    timer_ocintpara.ocpolarity = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    /* Timer0 channel configure */
    timer_channel_output_config(TIMER0, TIMER_CH_0, &timer_ocintpara);
    timer_channel_output_config(TIMER0, TIMER_CH_1, &timer_ocintpara);
    timer_channel_output_config(TIMER0, TIMER_CH_2, &timer_ocintpara);
    timer_channel_output_config(TIMER0, TIMER_CH_3, &timer_ocintpara);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_0, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_1, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_2, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_2, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_3, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);

    /* Timer1 channel configure */
    timer_channel_output_config(TIMER1, TIMER_CH_0, &timer_ocintpara);
    timer_channel_output_config(TIMER1, TIMER_CH_1, &timer_ocintpara);
    timer_channel_output_config(TIMER1, TIMER_CH_3, &timer_ocintpara);
    timer_channel_output_mode_config(TIMER1, TIMER_CH_0, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER1, TIMER_CH_1, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER1, TIMER_CH_3, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);

    /* Timer3 channel configure */
    timer_channel_output_config(TIMER3, TIMER_CH_1, &timer_ocintpara);
    timer_channel_output_config(TIMER3, TIMER_CH_2, &timer_ocintpara);
    timer_channel_output_config(TIMER3, TIMER_CH_3, &timer_ocintpara);
    timer_channel_output_mode_config(TIMER3, TIMER_CH_1, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER3, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER3, TIMER_CH_2, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER3, TIMER_CH_2, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_mode_config(TIMER3, TIMER_CH_3, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER3, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER0);
    timer_auto_reload_shadow_enable(TIMER1);
    timer_auto_reload_shadow_enable(TIMER3);
}

rt_inline void __read_pwm(uint8_t chan_id, float* dc)
{
    *dc = __pwm_dc[chan_id];
}

rt_inline void __write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_3, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 1:
        timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_2, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 2:
        timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_1, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 3:
        timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_0, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 4:
        timer_channel_output_pulse_value_config(TIMER3, TIMER_CH_1, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 5:
        timer_channel_output_pulse_value_config(TIMER3, TIMER_CH_2, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 6:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_3, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 7:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_0, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 8:
        timer_channel_output_pulse_value_config(TIMER3, TIMER_CH_3, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 9:
        timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_1, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    default:
        return;
    }

    __pwm_dc[chan_id] = dc;
}

static rt_err_t __set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    __pwm_freq = freq;

    timer_autoreload_value_config(TIMER0, PWM_ARR(__pwm_freq) - 1);
    timer_autoreload_value_config(TIMER1, PWM_ARR(__pwm_freq) - 1);
    timer_autoreload_value_config(TIMER3, PWM_ARR(__pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        __write_pwm(i, __pwm_dc[i]);
    }

    return RT_EOK;
}

static rt_err_t pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            __write_pwm(i, VAL_TO_DC(act_dev.range[0]));
        }

        /* auto-reload preload enable */
        timer_enable(TIMER0);
        timer_enable(TIMER1);
        timer_enable(TIMER3);
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        /* auto-reload preload disable */
        timer_disable(TIMER0);
        timer_disable(TIMER1);
        timer_disable(TIMER3);
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

static rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
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

static rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
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

rt_err_t drv_pwm_init(void)
{
    /* init pwm gpio pin */
    pwm_gpio_init();
    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    /* register actuator hal device */
    return hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);
}