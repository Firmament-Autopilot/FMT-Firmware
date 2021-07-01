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

#include "pwm.h"
#include "debug.h"

// #define DBG(...) debug(__VA_ARGS__)
#define DBG(...)

#define PWM_ARR(freq)  (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = 3M/60K = 50 Hz
#define VAL_TO_DC(val) ((float)(val * _pwm_freq) / 1000000.0f)

uint16_t _pwm_freq = PWM_DEFAULT_FREQUENCY;
static float _tim_duty_cycle[MAX_PWM_CHAN] = { 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00 };
static int _enable = 0;

void pwm_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    /* TIM3 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    /* TIM4 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    /* GPIO clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

    /* GPIOA Configuration:TIM2 Channel 1, 2 as alternate function push-pull, for IO_CH1, IO_CH2 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* GPIOA Configuration:TIM4 Channel 3, 4 as alternate function push-pull, for IO_CH3, IO_CH4 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* GPIOA Configuration:TIM3 Channel 1, 2, 3 and 4 as alternate function push-pull, for IO_C51, IO_CH6, IO_CH7 and IO_CH8 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void pwm_timer_init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    uint16_t PrescalerValue = 0;
    RCC_ClocksTypeDef rcc_clocks;

    // Timer 2,3,4 are all base timer
    RCC_GetClocksFreq(&rcc_clocks);
    uint8_t APB1_Prescaler = rcc_clocks.HCLK_Frequency / rcc_clocks.PCLK1_Frequency;
    uint32_t TimClk = APB1_Prescaler == 1 ? rcc_clocks.PCLK1_Frequency : rcc_clocks.PCLK1_Frequency * 2;
    /* Compute the prescaler value */
    PrescalerValue = (uint16_t)(TimClk / TIMER_FREQUENCY) - 1;
    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = PWM_ARR(_pwm_freq) - 1;
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

    /* -----------------------------------------------------------------------
	TIM2 Configuration:
	----------------------------------------------------------------------- */
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM2, ENABLE);

    /* -----------------------------------------------------------------------
	TIM3 Configuration:
	----------------------------------------------------------------------- */
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OC1Init(TIM3, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM3, ENABLE);

    /* -----------------------------------------------------------------------
	TIM4 Configuration:
	----------------------------------------------------------------------- */
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    TIM_OC3Init(TIM4, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
    TIM_OC4Init(TIM4, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM4, ENABLE);
}

uint8_t pwm_write(float* duty_cyc, uint8_t chan_id)
{
    if (chan_id & PWM_CHAN_1) {
        TIM_SetCompare1(TIM2, PWM_ARR(_pwm_freq) * duty_cyc[0]);
        _tim_duty_cycle[0] = duty_cyc[0];
    }

    if (chan_id & PWM_CHAN_2) {
        TIM_SetCompare2(TIM2, PWM_ARR(_pwm_freq) * duty_cyc[1]);
        _tim_duty_cycle[1] = duty_cyc[1];
    }

    if (chan_id & PWM_CHAN_3) {
        TIM_SetCompare3(TIM4, PWM_ARR(_pwm_freq) * duty_cyc[2]);
        _tim_duty_cycle[2] = duty_cyc[2];
    }

    if (chan_id & PWM_CHAN_4) {
        TIM_SetCompare4(TIM4, PWM_ARR(_pwm_freq) * duty_cyc[3]);
        _tim_duty_cycle[3] = duty_cyc[3];
    }

    if (chan_id & PWM_CHAN_5) {
        TIM_SetCompare1(TIM3, PWM_ARR(_pwm_freq) * duty_cyc[4]);
        _tim_duty_cycle[4] = duty_cyc[4];
    }

    if (chan_id & PWM_CHAN_6) {
        TIM_SetCompare2(TIM3, PWM_ARR(_pwm_freq) * duty_cyc[5]);
        _tim_duty_cycle[5] = duty_cyc[5];
    }

    if (chan_id & PWM_CHAN_7) {
        TIM_SetCompare3(TIM3, PWM_ARR(_pwm_freq) * duty_cyc[6]);
        _tim_duty_cycle[6] = duty_cyc[6];
    }

    if (chan_id & PWM_CHAN_8) {
        TIM_SetCompare4(TIM3, PWM_ARR(_pwm_freq) * duty_cyc[7]);
        _tim_duty_cycle[7] = duty_cyc[7];
    }

    return 0;
}

uint8_t pwm_read(float* buffer, uint8_t chan_id)
{
    for (uint8_t i = 0; i < MAX_PWM_CHAN; i++) {
        if (chan_id & (1 << i)) {
            buffer[i] = _tim_duty_cycle[i];
        }
    }

    return 0;
}

uint8_t pwm_configure(uint8_t cmd, void* args)
{
    if (cmd == PWM_CMD_SET_FREQ) {
        uint16_t freq_to_set = *((uint16_t*)args);

        if (freq_to_set < 50 || freq_to_set > 400) {
            /* invalid frequency */
            DBG("invalid pwm freq:%d\n", freq_to_set);
            return 1;
        }
        DBG("pwm freq %d => %d\n", _pwm_freq, freq_to_set);
        _pwm_freq = freq_to_set;

        // configure timer
        pwm_timer_init();
        // after frequency changing, the timer compare value should be re-configured also
        pwm_write(_tim_duty_cycle, PWM_CHAN_ALL);

        return 0;
    } else if (cmd == PWM_CMD_ENABLE) {
        int new_state = *((int*)args);

        DBG("pwm enable %d => %d\n", _enable, new_state);

        if (new_state) {
            /* set to min value when motor is opened */
            float min_dc[MAX_PWM_CHAN];

            for (uint8_t i = 0; i < MAX_PWM_CHAN; i++) {
                min_dc[i] = VAL_TO_DC(1000);
            }
            pwm_write(min_dc, PWM_CHAN_ALL);

            TIM_Cmd(TIM2, ENABLE);
            TIM_Cmd(TIM4, ENABLE);
            TIM_Cmd(TIM3, ENABLE);
            _enable = 1;
        } else {
            // float pwm[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
            // pwm_write(pwm, PWM_CHAN_ALL);
            TIM_Cmd(TIM2, DISABLE);
            TIM_Cmd(TIM4, DISABLE);
            TIM_Cmd(TIM3, DISABLE);
            _enable = 0;
        }

        return 0;
    } else {
        // unknown command
        return 1;
    }
}

void handle_motor_pkt(uint16_t mask, uint16_t* value)
{
    uint16_t val;
    float duty_cyc[MAX_PWM_CHAN] = { 0.0 };
    uint16_t* val_ptr = value;

    for (uint8_t i = 0; i < MAX_PWM_CHAN; i++) {
        if (mask & 1 << i) {
            val = *val_ptr;
            if (val > 2000) {
                val = 2000;
            } else if (val < 1000) {
                val = 1000;
            }
            val_ptr++;
            duty_cyc[i] = VAL_TO_DC(val);
        }
    }

    pwm_write(duty_cyc, (uint8_t)mask);
}

uint8_t pwm_init(void)
{
    pwm_gpio_init();
    pwm_timer_init();

    // disable by default
    TIM_Cmd(TIM2, DISABLE);
    TIM_Cmd(TIM4, DISABLE);
    TIM_Cmd(TIM3, DISABLE);
    _enable = 0;

    return 0;
}
