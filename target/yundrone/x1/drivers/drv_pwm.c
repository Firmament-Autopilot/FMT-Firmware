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
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_tim.h"

// #define DRV_DBG(...)          console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ          (50)
#define PWM_FREQ_125HZ         (125)
#define PWM_FREQ_250HZ         (250)
#define PWM_FREQ_400HZ         (400)

#define MAIN_PWM_CHAN          4
#define AUX_PWM_CHAN           4
#define TIMER_FREQUENCY        3000000       // Timer frequency: 3M
#define PWM_DEFAULT_FREQUENCY  PWM_FREQ_50HZ // pwm default frequqncy
#define VAL_TO_DC(_val, _freq) ((float)(_val * _freq) / 1000000.0f)
#define DC_TO_VAL(_dc, _freq)  (1000000.0f / _freq * _dc)

#define PWM_ARR(freq)          (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = 3M/60K = 50 Hz
#define PWM_TIMER(id)          (id < 4 ? TIM1 : TIM4)

static uint32_t main_pwm_freq = PWM_DEFAULT_FREQUENCY;
static uint32_t aux_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float main_pwm_dc[MAIN_PWM_CHAN];
static float aux_pwm_dc[AUX_PWM_CHAN];

void pwm_gpio_init(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* Timer 1 gpio init */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
    /**TIM1 GPIO Configuration
    PE13   ------> TIM1_CH3
    PE9   ------> TIM1_CH1
    PE11   ------> TIM1_CH2
    PE14   ------> TIM1_CH4
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_13 | LL_GPIO_PIN_9 | LL_GPIO_PIN_11 | LL_GPIO_PIN_14;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
    LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* Timer 4 gpio init */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
    /**TIM4 GPIO Configuration
    PD15   ------> TIM4_CH4
    PD14   ------> TIM4_CH3
    PD13   ------> TIM4_CH2
    PD12   ------> TIM4_CH1
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_15 | LL_GPIO_PIN_14 | LL_GPIO_PIN_13 | LL_GPIO_PIN_12;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void pwm_timer_init(void)
{
    LL_TIM_InitTypeDef TIM_InitStruct = { 0 };
    LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = { 0 };
    LL_TIM_BDTR_InitTypeDef TIM_BDTRInitStruct = { 0 };
    LL_RCC_ClocksTypeDef rcc_clocks;
    uint32_t APB1_PrescalerValue;
    uint32_t APB2_PrescalerValue;

    LL_RCC_GetSystemClocksFreq(&rcc_clocks);
    /* APB1 Timer Clock = PCLK1 * 2 */
    APB1_PrescalerValue = (rcc_clocks.PCLK1_Frequency * 2) / TIMER_FREQUENCY - 1;
    /* APB2 Timer Clock = PCLK2 * 2 */
    APB2_PrescalerValue = (rcc_clocks.PCLK2_Frequency * 2) / TIMER_FREQUENCY - 1;

    /* Timer 1 initialization */

    /* Peripheral clock enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);

    TIM_InitStruct.Prescaler = APB2_PrescalerValue;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = PWM_ARR(main_pwm_freq) - 1;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    TIM_InitStruct.RepetitionCounter = 0;
    LL_TIM_Init(TIM1, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM1);

    LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH1);
    TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.CompareValue = 0;
    TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
    TIM_OC_InitStruct.OCNPolarity = LL_TIM_OCPOLARITY_HIGH;
    TIM_OC_InitStruct.OCIdleState = LL_TIM_OCIDLESTATE_LOW;
    TIM_OC_InitStruct.OCNIdleState = LL_TIM_OCIDLESTATE_LOW;
    LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH1);
    LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH2);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH3);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH3);
    LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH4);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH4, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM1, LL_TIM_CHANNEL_CH4);
    LL_TIM_SetTriggerOutput(TIM1, LL_TIM_TRGO_RESET);
    LL_TIM_SetTriggerOutput2(TIM1, LL_TIM_TRGO2_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM1);
    TIM_BDTRInitStruct.OSSRState = LL_TIM_OSSR_DISABLE;
    TIM_BDTRInitStruct.OSSIState = LL_TIM_OSSI_DISABLE;
    TIM_BDTRInitStruct.LockLevel = LL_TIM_LOCKLEVEL_OFF;
    TIM_BDTRInitStruct.DeadTime = 0;
    TIM_BDTRInitStruct.BreakState = LL_TIM_BREAK_DISABLE;
    TIM_BDTRInitStruct.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH;
    TIM_BDTRInitStruct.BreakFilter = LL_TIM_BREAK_FILTER_FDIV1;
    TIM_BDTRInitStruct.Break2State = LL_TIM_BREAK2_DISABLE;
    TIM_BDTRInitStruct.Break2Polarity = LL_TIM_BREAK2_POLARITY_HIGH;
    TIM_BDTRInitStruct.Break2Filter = LL_TIM_BREAK2_FILTER_FDIV1;
    TIM_BDTRInitStruct.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE;
    LL_TIM_BDTR_Init(TIM1, &TIM_BDTRInitStruct);

    /* Timer 4 initialization */

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);

    TIM_InitStruct.Prescaler = APB1_PrescalerValue;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = PWM_ARR(main_pwm_freq) - 1;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    LL_TIM_Init(TIM4, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM4);
    LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH1);
    TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.CompareValue = 0;
    TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
    LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH1);
    LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH2);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH3);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH3);
    LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH4);
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH4, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH4);
    LL_TIM_SetTriggerOutput(TIM4, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM4);
}

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
    switch (chan_id) {
    case 0:
        LL_TIM_OC_SetCompareCH1(TIM1, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 1:
        LL_TIM_OC_SetCompareCH2(TIM1, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 2:
        LL_TIM_OC_SetCompareCH3(TIM1, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 3:
        LL_TIM_OC_SetCompareCH4(TIM1, PWM_ARR(main_pwm_freq) * dc);
        break;
    default:
        return;
    }

    main_pwm_dc[chan_id] = dc;
}

rt_inline void __aux_write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        LL_TIM_OC_SetCompareCH1(TIM4, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 1:
        LL_TIM_OC_SetCompareCH2(TIM4, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 2:
        LL_TIM_OC_SetCompareCH3(TIM4, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 3:
        LL_TIM_OC_SetCompareCH4(TIM4, PWM_ARR(aux_pwm_freq) * dc);
        break;
    default:
        return;
    }

    aux_pwm_dc[chan_id] = dc;
}

rt_inline rt_err_t __main_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    main_pwm_freq = freq;

    LL_TIM_SetAutoReload(TIM1, PWM_ARR(main_pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        __main_write_pwm(i, main_pwm_dc[i]);
    }

    return RT_EOK;
}

rt_inline rt_err_t __aux_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    aux_pwm_freq = freq;

    LL_TIM_SetAutoReload(TIM4, PWM_ARR(aux_pwm_freq) - 1);

    /* the timer compare value should be re-configured */
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
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__aux_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t main_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
            __main_write_pwm(i, VAL_TO_DC(1000, main_pwm_freq));
        }

        LL_TIM_EnableCounter(TIM1);
        LL_TIM_EnableAllOutputs(TIM1);

        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH4);

        DRV_DBG("main out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        LL_TIM_DisableCounter(TIM1);
        LL_TIM_DisableAllOutputs(TIM1);

        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH4);

        DRV_DBG("main out disabled\n");
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

static rt_err_t aux_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
            __aux_write_pwm(i, VAL_TO_DC(1000, aux_pwm_freq));
        }

        LL_TIM_EnableCounter(TIM4);

        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH4);

        DRV_DBG("aux out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        LL_TIM_DisableCounter(TIM4);

        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH4);

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
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val, main_pwm_freq);
            /* update pwm signal */
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
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val, aux_pwm_freq);
            /* update pwm signal */
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

static struct actuator_device main_act_dev = { .chan_mask = 0x0F,
                                               .range = { 1000, 2000 },
                                               .config = { .protocol = ACT_PROTOCOL_PWM,
                                                           .chan_num = MAIN_PWM_CHAN,
                                                           .pwm_config = { .pwm_freq = 50 },
                                                           .dshot_config = { 0 } },
                                               .ops = &main_act_ops };

static struct actuator_device aux_act_dev = { .chan_mask = 0x0F,
                                              .range = { 1000, 2000 },
                                              .config = { .protocol = ACT_PROTOCOL_PWM,
                                                          .chan_num = AUX_PWM_CHAN,
                                                          .pwm_config = { .pwm_freq = 50 },
                                                          .dshot_config = { 0 } },
                                              .ops = &aux_act_ops };

rt_err_t drv_pwm_init(void)
{
    /* init pwm gpio pin */
    pwm_gpio_init();
    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    /* register actuator hal device */
    RT_TRY(hal_actuator_register(&main_act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL));
    RT_TRY(hal_actuator_register(&aux_act_dev, "aux_out", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}
