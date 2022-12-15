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

#define TIMER_FREQUENCY       2500000                  // Timer frequency: 2.5M
#define PWM_DEFAULT_FREQUENCY 50                       // pwm default frequqncy
#define PWM_ARR(freq)         (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;

static void pwm_gpio_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);

    /* Configure PA0 (TIMER4 CH0) as alternate function */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0);

    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_0);
}

static void pwm_timer_init(void)
{
    /* Configured by system_clock_240m_8m_hxtal(), AHB = SYSCLK, APB1 = AHB/4, APB2 = AHB/2 */
    timer_oc_parameter_struct timer_ocintpara;
    uint16_t timer_psc;
    timer_parameter_struct timer_initpara;

    /* TIMER clock configuration */
    rcu_periph_clock_enable(RCU_TIMER4);

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
    timer_deinit(TIMER4);
    /* Timer init */
    timer_init(TIMER4, &timer_initpara);

    /* Timer channel configuration in PWM mode */
    timer_ocintpara.ocpolarity = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    /* Timer4 channel configure */
    timer_channel_output_config(TIMER4, TIMER_CH_0, &timer_ocintpara);
    timer_channel_output_mode_config(TIMER4, TIMER_CH_0, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);


    timer_channel_output_pulse_value_config(TIMER4, TIMER_CH_0, PWM_ARR(__pwm_freq) * 0.7 - 1);
    timer_enable(TIMER4);
}

rt_err_t drv_buzzer_init(void)
{
    pwm_gpio_init();
    pwm_timer_init();

    return RT_EOK;
}
