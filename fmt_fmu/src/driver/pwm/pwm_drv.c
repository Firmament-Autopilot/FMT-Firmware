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
#include "driver/pwm_drv.h"
#include "hal/motor.h"
#include <firmament.h>

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define MAX_PWM_OUT_CHAN      6        // AUX Out has 6 pwm channel
#define TIMER_FREQUENCY       3000000  // Timer frequency: 3M
#define PWM_DEFAULT_FREQUENCY 50       // pwm default frequqncy: 50Hz
#define PWM_DC_SCALE          0.00005f // convert motor value to pwm duty cycle

#define PWM_ARR(freq) (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = 3M/60K = 50 Hz
#define PWM_TIMER(id) (id < 4 ? TIM1 : TIM4)

static int _pwm_freq = PWM_DEFAULT_FREQUENCY;
static float _pwm_fmu_duty_cyc[MAX_PWM_OUT_CHAN] = { 0.00, 0.00, 0.00, 0.00, 0.00, 0.00 };

typedef void (*timer_func)(TIM_TypeDef*, uint32_t);
timer_func _timer_set_compare[MAX_PWM_OUT_CHAN] = {
    TIM_SetCompare4,
    TIM_SetCompare3,
    TIM_SetCompare2,
    TIM_SetCompare1,
    TIM_SetCompare2,
    TIM_SetCompare3
};

static void _pwm_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* TIM1 clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    /* GPIOE clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    /* TIM1 CH1 (PE9,FMU_CH4), TIM1 CH2 (PE11,FMU_CH3), TIM1 CH3 (PE13,FMU_CH2) and TIM1 CH4 (PE14,FMU_CH1) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Connect TIM1 pins to AF */
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);

    /* TIM4 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    /* GPIOE clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* TIM4 CH2 (PD13,FMU_CH5), TIM4 CH3 (PD14,FMU_CH6) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* Connect TIM4 pins to AF */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
}

static void _pwm_timer_init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    uint16_t PrescalerValue;
    RCC_ClocksTypeDef rcc_clocks;

    /* TIM1CLK = 2 * PCLK2 */
    /* PCLK2 = HCLK / 2 */
    RCC_GetClocksFreq(&rcc_clocks);

    /* Compute the prescaler value, TIM1 frequency = 3M Hz */
    PrescalerValue = (uint16_t)((rcc_clocks.PCLK2_Frequency * 2 / TIMER_FREQUENCY) - 1);

    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = PWM_ARR(_pwm_freq) - 1; //PWM Frequency = 3M/60K = 50 Hz
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM1, ENABLE);
    //TIM_Cmd(TIM1, ENABLE);

    /* TIM4CLK = 2 * PCLK1 */
    /* PCLK1 = HCLK / 4 */
    PrescalerValue = (uint16_t)((rcc_clocks.PCLK1_Frequency * 2 / TIMER_FREQUENCY) - 1);
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;

    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    TIM_OC2Init(TIM4, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

    TIM_OC3Init(TIM4, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM4, ENABLE);
    //TIM_Cmd(TIM4, ENABLE);
}

rt_inline void _pwm_write(uint8_t chan_id, float duty_cyc)
{
    _timer_set_compare[chan_id](PWM_TIMER(chan_id), PWM_ARR(_pwm_freq) * duty_cyc);

    _pwm_fmu_duty_cyc[chan_id] = duty_cyc;
}

rt_inline void _pwm_read(uint8_t chan_id, float* duty_cyc)
{
    *duty_cyc = _pwm_fmu_duty_cyc[chan_id];
}

static rt_err_t motor_configure(motor_dev_t motor, struct motor_configure* cfg)
{
    motor->config = *cfg;

    DRV_DBG("aux motor configured: min:%d max:%d\n", motor->config.motor_min_value, motor->config.motor_max_value);

    return RT_EOK;
}

static rt_err_t motor_control(motor_dev_t motor, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case MOTOR_CMD_CHANNEL_ENABLE: {
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            _pwm_write(i, 0.05);
        }

        TIM_Cmd(TIM1, ENABLE);
        TIM_CtrlPWMOutputs(TIM1, ENABLE);
        TIM_Cmd(TIM4, ENABLE);

        DRV_DBG("aux motor enabled\n");
    } break;

    case MOTOR_CMD_CHANNEL_DISABLE: {
        TIM_Cmd(TIM1, DISABLE);
        TIM_CtrlPWMOutputs(TIM1, DISABLE);
        TIM_Cmd(TIM4, DISABLE);

        DRV_DBG("aux motor disabled\n");
    } break;

    case MOTOR_CMD_SET_FREQUENCY: {
        _pwm_freq = (int)arg;

        _pwm_timer_init();

        /* the timer compare value should be re-configured */
        for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            _pwm_write(i, _pwm_fmu_duty_cyc[i]);
        }

        DRV_DBG("aux motor set frequency to %d Hz\n", _pwm_freq);
    } break;

    default:
        break;
    }

    return ret;
}

static rt_size_t motor_read(motor_dev_t motor, rt_uint16_t chan_mask, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_mask & (1 << i)) {
            _pwm_read(i, &dc);
            *index = dc / PWM_DC_SCALE;
            index++;
        }
    }

    return size;
}

static rt_size_t motor_write(motor_dev_t motor, rt_uint16_t chan_mask, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    DRV_DBG("aux motor write: ");
    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_mask & (1 << i)) {
            /* constrain motor value */
            val = constrain_uint16(*index, motor->config.motor_min_value, motor->config.motor_max_value);
            /* calculate pwm duty cycle */
            dc = PWM_DC_SCALE * val;
            /* update pwm signal */
            _pwm_write(i, dc);

            DRV_DBG("chan[%d]=%d %.2f ", i + 1, *index, dc);
            index++;
        }
    }
    DRV_DBG("\n");

    return size;
}

/* default config for motor device */
#define MOTOR_CONFIG_DEFAULT           \
    {                                  \
        1000,     /* minimal 1000us */ \
            2000, /* maximal 2000us */ \
    }

const static struct motor_ops _motor_ops = {
    motor_configure,
    motor_control,
    motor_read,
    motor_write
};

rt_err_t pwm_drv_init(void)
{
    rt_err_t ret;
    static struct motor_device motor;
    struct motor_configure motor_config = MOTOR_CONFIG_DEFAULT;

    _pwm_gpio_init();
    _pwm_timer_init();

    /* Disable output by default, need ne enabled by uper layer */
    TIM_Cmd(TIM1, DISABLE);
    TIM_CtrlPWMOutputs(TIM1, DISABLE);
    TIM_Cmd(TIM4, DISABLE);

    /* register motor hal device */
    motor.channel_num = MAX_PWM_OUT_CHAN;
    motor.config = motor_config;
    motor.ops = &_motor_ops;
    ret = hal_motor_register(&motor, "motor_aux", RT_DEVICE_FLAG_RDWR, NULL);

    return ret;
}
