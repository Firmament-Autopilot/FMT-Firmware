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
#include "driver/dshot/dshot.h"
#include "hal/actuator/actuator.h"
#include "model/fms/fms_interface.h"
#include "stm32h7xx_ll_dma.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_tim.h"
#include <firmament.h>

MCN_DECLARE(fms_output);

// #define DRV_DBG(...)          console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define MAIN_PWM_CHAN          12
#define AUX_PWM_CHAN           4
#define PWM_FREQ_50HZ          (50)
#define PWM_FREQ_125HZ         (125)
#define PWM_FREQ_250HZ         (250)
#define PWM_FREQ_400HZ         (400)

#define TIMER_FREQUENCY        3000000       // Timer frequency: 3M
#define DSHOT_TIMER_FREQUENCY  120000000     // Timer frequency for DShot: 120M
#define PWM_DEFAULT_FREQUENCY  PWM_FREQ_50HZ // pwm default frequqncy
#define VAL_TO_DC(_val, _freq) ((float)(_val * _freq) / 1000000.0f)
#define DC_TO_VAL(_dc, _freq)  (1000000.0f / _freq * _dc)

#define PWM_ARR(freq)          (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = 3M/60K = 50 Hz
#define PWM_TIMER(id)          (id < 4 ? TIM1 : TIM4)

static uint32_t main_pwm_freq = PWM_DEFAULT_FREQUENCY;
static uint32_t aux_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float main_pwm_dc[MAIN_PWM_CHAN];
static float aux_pwm_dc[AUX_PWM_CHAN];

/* Track current protocol */
static uint8_t main_protocol = ACT_PROTOCOL_PWM;
static uint8_t aux_protocol = ACT_PROTOCOL_PWM;
/* DShot command state array: keeps track of ongoing sequence correctly synced to cyclic update */
typedef struct {
    uint16_t cmd;
    uint16_t repeat;
    uint32_t wait_start_ms;
    uint16_t wait_ms;
    bool active;
} dshot_cmd_state_t;
static volatile dshot_cmd_state_t dshot_cmds[MAIN_PWM_CHAN + AUX_PWM_CHAN] = { 0 };

/* Channels serviced by the periodic actuator loop. */
static volatile uint16_t main_polled_mask = 0;
static volatile uint16_t aux_polled_mask = 0;

/* One DMA stream is used per timer, with 4 CCR values updated on each event. */

#define DSHOT_BITS           16U
#define DSHOT_TIMER_COUNT    4U
#define DSHOT_TIMER_CHANNELS 4U
#define DSHOT_FRAME_ROWS     17U
#define DSHOT_DMA_ROWS       18U
#define DSHOT_DMA_WORDS      ((DSHOT_FRAME_ROWS - 1U) * DSHOT_TIMER_CHANNELS)

/* DMA1/DMA2 on STM32H7 can access this buffer only from D2 SRAM. */
static __attribute__((section(".dshot_dma_buf"), aligned(32))) uint32_t dshot_dma_frame[DSHOT_TIMER_COUNT][DSHOT_DMA_ROWS][DSHOT_TIMER_CHANNELS];

struct dshot_dma_map {
    DMA_TypeDef* dma;
    uint32_t stream;
    uint32_t request;
    TIM_TypeDef* tim;
};

static const struct dshot_dma_map dshot_dma_map[DSHOT_TIMER_COUNT] = {
    { DMA2, LL_DMA_STREAM_2, LL_DMAMUX1_REQ_TIM1_UP, TIM1 },
    { DMA2, LL_DMA_STREAM_3, LL_DMAMUX1_REQ_TIM4_UP, TIM4 },
    { DMA2, LL_DMA_STREAM_4, LL_DMAMUX1_REQ_TIM5_UP, TIM5 },
    { DMA2, LL_DMA_STREAM_5, LL_DMAMUX1_REQ_TIM8_UP, TIM8 },
};

static void _dshot_clear_dma_flags(DMA_TypeDef* dma, uint32_t stream)
{
    uint32_t shift = 0;
    uint32_t mask = 0x3DU;
    __IO uint32_t* ifcr;

    if (stream == LL_DMA_STREAM_0 || stream == LL_DMA_STREAM_4)
        shift = 0;
    else if (stream == LL_DMA_STREAM_1 || stream == LL_DMA_STREAM_5)
        shift = 6;
    else if (stream == LL_DMA_STREAM_2 || stream == LL_DMA_STREAM_6)
        shift = 16;
    else
        shift = 22;

    ifcr = (stream < LL_DMA_STREAM_4) ? &dma->LIFCR : &dma->HIFCR;
    *ifcr = (mask << shift);
}

static void _setup_dshot_dma(void)
{
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
    /* Enable D2 SRAM clock for the DMA buffer. */
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_D2SRAM1EN | RCC_AHB2ENR_D2SRAM2EN);
    (void)RCC->AHB2ENR; /* dummy read to ensure clock is enabled before use */

    for (uint8_t i = 0; i < DSHOT_TIMER_COUNT; i++) {
        LL_DMA_InitTypeDef dma_init = { 0 };

        LL_DMA_DisableStream(dshot_dma_map[i].dma, dshot_dma_map[i].stream);
        while (LL_DMA_IsEnabledStream(dshot_dma_map[i].dma, dshot_dma_map[i].stream))
            ;
        CLEAR_BIT(dshot_dma_map[i].tim->DIER, TIM_DIER_UDE);
        _dshot_clear_dma_flags(dshot_dma_map[i].dma, dshot_dma_map[i].stream);

        dma_init.PeriphOrM2MSrcAddress = (uint32_t)&dshot_dma_map[i].tim->DMAR;
        dma_init.MemoryOrM2MDstAddress = (uint32_t)&dshot_dma_frame[i][1][0];
        dma_init.Direction = LL_DMA_DIRECTION_MEMORY_TO_PERIPH;
        dma_init.Mode = LL_DMA_MODE_NORMAL;
        dma_init.PeriphOrM2MSrcIncMode = LL_DMA_PERIPH_NOINCREMENT;
        dma_init.MemoryOrM2MDstIncMode = LL_DMA_MEMORY_INCREMENT;
        dma_init.PeriphOrM2MSrcDataSize = LL_DMA_PDATAALIGN_WORD;
        dma_init.MemoryOrM2MDstDataSize = LL_DMA_MDATAALIGN_WORD;
        dma_init.NbData = DSHOT_DMA_WORDS;
        dma_init.Priority = LL_DMA_PRIORITY_HIGH;
        /* Timer DMAR burst still issues single DMA requests on STM32H7. */
        dma_init.FIFOMode = LL_DMA_FIFOMODE_DISABLE;
        dma_init.PeriphRequest = dshot_dma_map[i].request;

        LL_DMA_Init(dshot_dma_map[i].dma, dshot_dma_map[i].stream, &dma_init);
        LL_DMA_DisableIT_HT(dshot_dma_map[i].dma, dshot_dma_map[i].stream);
        LL_DMA_DisableIT_TC(dshot_dma_map[i].dma, dshot_dma_map[i].stream);
        LL_DMA_DisableIT_TE(dshot_dma_map[i].dma, dshot_dma_map[i].stream);

        dshot_dma_map[i].tim->DCR = LL_TIM_DMABURST_BASEADDR_CCR1 | LL_TIM_DMABURST_LENGTH_4TRANSFERS;
    }
}

static void _dshot_pack(uint8_t chan, uint16_t frame, uint32_t arr)
{
    uint8_t tim_idx = chan / 4U;
    uint8_t ch_in_tim = chan % 4U;
    uint32_t period = arr + 1U;

    /* +3U rounds to nearest: (x + divisor/2) / divisor */
    uint32_t duty_0 = (period * 2U + 3U) / 6U; /* T0H: ~33.3% */
    uint32_t duty_1 = (period * 4U + 3U) / 6U; /* T1H: ~66.7% */

    for (uint8_t i = 0; i < DSHOT_BITS; i++) {
        dshot_dma_frame[tim_idx][i][ch_in_tim] = (frame & (0x8000U >> i)) ? duty_1 : duty_0;
    }

    dshot_dma_frame[tim_idx][DSHOT_BITS][ch_in_tim] = 0;
}

static void _dshot_fire_tim(uint8_t tim_idx)
{
    const struct dshot_dma_map* map = &dshot_dma_map[tim_idx];

    LL_DMA_DisableStream(map->dma, map->stream);
    while (LL_DMA_IsEnabledStream(map->dma, map->stream))
        ;
    CLEAR_BIT(map->tim->DIER, TIM_DIER_UDE);
    _dshot_clear_dma_flags(map->dma, map->stream);

    /* Reset timer state in case a previous burst did not finish cleanly. */
    CLEAR_BIT(map->tim->CR1, TIM_CR1_CEN);

    /* Force outputs low before loading the next frame. */
    map->tim->CCR1 = 0;
    map->tim->CCR2 = 0;
    map->tim->CCR3 = 0;
    map->tim->CCR4 = 0;
    SET_BIT(map->tim->CR1, TIM_CR1_URS);
    map->tim->EGR = TIM_EGR_UG;
    CLEAR_BIT(map->tim->SR, TIM_SR_UIF);

    /* Preload the first bit; the next update event latches it. */
    map->tim->CCR1 = dshot_dma_frame[tim_idx][0][0];
    map->tim->CCR2 = dshot_dma_frame[tim_idx][0][1];
    map->tim->CCR3 = dshot_dma_frame[tim_idx][0][2];
    map->tim->CCR4 = dshot_dma_frame[tim_idx][0][3];

    map->tim->CNT = LL_TIM_GetAutoReload(map->tim);

    LL_DMA_SetMemoryAddress(map->dma, map->stream, (uint32_t)&dshot_dma_frame[tim_idx][1][0]);
    LL_DMA_SetDataLength(map->dma, map->stream, DSHOT_DMA_WORDS);
    LL_DMA_EnableStream(map->dma, map->stream);

    SET_BIT(map->tim->DIER, TIM_DIER_UDE);
    SET_BIT(map->tim->CR1, TIM_CR1_CEN);
}

static void _dshot_clean_cache(uint8_t tim_idx)
{
    SCB_CleanDCache_by_Addr((uint32_t*)dshot_dma_frame[tim_idx], sizeof(dshot_dma_frame[tim_idx]));
}

static rt_err_t _dshot_send_command(rt_uint16_t chan_mask, uint16_t dshot_val, uint8_t repeat, uint16_t wait_ms,
                                    bool aux)
{
    rt_ubase_t level;
    uint8_t base = aux ? MAIN_PWM_CHAN : 0;
    uint8_t count = aux ? AUX_PWM_CHAN : MAIN_PWM_CHAN;

    chan_mask &= (aux ? aux_polled_mask : main_polled_mask);

    if (chan_mask == 0) {
        return RT_EINVAL;
    }

    level = rt_hw_interrupt_disable();
    for (uint8_t i = 0; i < count; i++) {
        if (chan_mask & (1u << i)) {
            dshot_cmds[base + i].cmd = dshot_val;
            dshot_cmds[base + i].repeat = repeat;
            dshot_cmds[base + i].wait_ms = wait_ms;
            dshot_cmds[base + i].wait_start_ms = 0;
            dshot_cmds[base + i].active = true;
        }
    }
    rt_hw_interrupt_enable(level);

    uint32_t start_time = systime_now_ms();
    uint32_t timeout = repeat * 20 + wait_ms + 1000;

    while (1) {
        bool done = true;
        level = rt_hw_interrupt_disable();
        for (uint8_t i = 0; i < count; i++) {
            if ((chan_mask & (1u << i)) && dshot_cmds[base + i].active) {
                done = false;
                break;
            }
        }
        rt_hw_interrupt_enable(level);

        if (done) {
            break;
        }

        if (systime_now_ms() - start_time > timeout) {
            console_printf("dshot timeout, chan_mask: %x\n", chan_mask);
            return RT_ETIMEOUT;
        }

        if (rt_thread_self()) {
            rt_thread_delay(1);
        } else {
            systime_mdelay(1);
        }
    }

    return RT_EOK;
}

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

    /* Timer 5 gpio init */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOH);
    /**TIM5 GPIO Configuration
    PI0   ------> TIM5_CH4
    PH12   ------> TIM5_CH3
    PH11   ------> TIM5_CH2
    PH10   ------> TIM5_CH1
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_12 | LL_GPIO_PIN_11 | LL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    /****************** AUX OUT ******************/

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);
    /**TIM8 GPIO Configuration
    PI6   ------> TIM8_CH2
    PI5   ------> TIM8_CH1
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_5;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_3;
    LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOH);
    /**TIM12 GPIO Configuration
    PH6   ------> TIM12_CH1
    PH9   ------> TIM12_CH2
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOH, &GPIO_InitStruct);
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

    /* Timer 5 initialization */

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM5);

    TIM_InitStruct.Prescaler = APB1_PrescalerValue;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = PWM_ARR(main_pwm_freq) - 1;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    LL_TIM_Init(TIM5, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM5);
    LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH1);
    TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.CompareValue = 0;
    TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
    LL_TIM_OC_Init(TIM5, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM5, LL_TIM_CHANNEL_CH1);
    LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_Init(TIM5, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM5, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH3);
    LL_TIM_OC_Init(TIM5, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM5, LL_TIM_CHANNEL_CH3);
    LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH4);
    LL_TIM_OC_Init(TIM5, LL_TIM_CHANNEL_CH4, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM5, LL_TIM_CHANNEL_CH4);
    LL_TIM_SetTriggerOutput(TIM5, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM5);

    /****************** AUX OUT ******************/

    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM8);
    TIM_InitStruct.Prescaler = APB2_PrescalerValue;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = PWM_ARR(main_pwm_freq) - 1;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    TIM_InitStruct.RepetitionCounter = 0;
    LL_TIM_Init(TIM8, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM8);

    LL_TIM_OC_EnablePreload(TIM8, LL_TIM_CHANNEL_CH1);
    TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.CompareValue = 0;
    TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
    TIM_OC_InitStruct.OCNPolarity = LL_TIM_OCPOLARITY_HIGH;
    TIM_OC_InitStruct.OCIdleState = LL_TIM_OCIDLESTATE_LOW;
    TIM_OC_InitStruct.OCNIdleState = LL_TIM_OCIDLESTATE_LOW;
    LL_TIM_OC_Init(TIM8, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM8, LL_TIM_CHANNEL_CH1);
    LL_TIM_OC_EnablePreload(TIM8, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_Init(TIM8, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM8, LL_TIM_CHANNEL_CH2);
    LL_TIM_SetTriggerOutput(TIM8, LL_TIM_TRGO_RESET);
    LL_TIM_SetTriggerOutput2(TIM8, LL_TIM_TRGO2_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM8);
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
    LL_TIM_BDTR_Init(TIM8, &TIM_BDTRInitStruct);

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM12);
    TIM_InitStruct.Prescaler = APB1_PrescalerValue;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = PWM_ARR(main_pwm_freq) - 1;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    LL_TIM_Init(TIM12, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM12);
    LL_TIM_OC_EnablePreload(TIM12, LL_TIM_CHANNEL_CH1);
    TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
    TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
    TIM_OC_InitStruct.CompareValue = 0;
    TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
    LL_TIM_OC_Init(TIM12, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM12, LL_TIM_CHANNEL_CH1);
    LL_TIM_OC_EnablePreload(TIM12, LL_TIM_CHANNEL_CH2);
    LL_TIM_OC_Init(TIM12, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
    LL_TIM_OC_DisableFast(TIM12, LL_TIM_CHANNEL_CH2);
    LL_TIM_SetTriggerOutput(TIM12, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM12);
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
    case 4:
        LL_TIM_OC_SetCompareCH1(TIM4, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 5:
        LL_TIM_OC_SetCompareCH2(TIM4, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 6:
        LL_TIM_OC_SetCompareCH3(TIM4, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 7:
        LL_TIM_OC_SetCompareCH4(TIM4, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 8:
        LL_TIM_OC_SetCompareCH1(TIM5, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 9:
        LL_TIM_OC_SetCompareCH2(TIM5, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 10:
        LL_TIM_OC_SetCompareCH3(TIM5, PWM_ARR(main_pwm_freq) * dc);
        break;
    case 11:
        LL_TIM_OC_SetCompareCH4(TIM5, PWM_ARR(main_pwm_freq) * dc);
        break;
    default:
        break;
    }

    main_pwm_dc[chan_id] = dc;
}

rt_inline void __aux_write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        LL_TIM_OC_SetCompareCH1(TIM8, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 1:
        LL_TIM_OC_SetCompareCH2(TIM8, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 2:
        LL_TIM_OC_SetCompareCH1(TIM12, PWM_ARR(aux_pwm_freq) * dc);
        break;
    case 3:
        LL_TIM_OC_SetCompareCH2(TIM12, PWM_ARR(aux_pwm_freq) * dc);
        break;
    default:
        break;
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
    LL_TIM_SetAutoReload(TIM4, PWM_ARR(main_pwm_freq) - 1);
    LL_TIM_SetAutoReload(TIM5, PWM_ARR(main_pwm_freq) - 1);

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

    LL_TIM_SetAutoReload(TIM8, PWM_ARR(aux_pwm_freq) - 1);
    LL_TIM_SetAutoReload(TIM12, PWM_ARR(aux_pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        __aux_write_pwm(i, aux_pwm_dc[i]);
    }

    return RT_EOK;
}

static rt_err_t main_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    if (cfg->protocol == ACT_PROTOCOL_PWM) {
        DRV_DBG("main out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

        LL_RCC_ClocksTypeDef rcc_clocks;
        LL_RCC_GetSystemClocksFreq(&rcc_clocks);
        uint32_t psc_apb1 = (rcc_clocks.PCLK1_Frequency * 2) / TIMER_FREQUENCY - 1;
        uint32_t psc_apb2 = (rcc_clocks.PCLK2_Frequency * 2) / TIMER_FREQUENCY - 1;
        LL_TIM_SetPrescaler(TIM1, psc_apb2);
        LL_TIM_SetPrescaler(TIM4, psc_apb1);
        LL_TIM_SetPrescaler(TIM5, psc_apb1);

        if (__main_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
            return RT_ERROR;
        }
    } else if (cfg->protocol == ACT_PROTOCOL_DSHOT) {
        DRV_DBG("main out configured: dshot speed:%d\n", cfg->dshot_config.speed);
        uint16_t speed = cfg->dshot_config.speed;
        if (speed > 0) {
            LL_RCC_ClocksTypeDef rcc_clocks;
            LL_RCC_GetSystemClocksFreq(&rcc_clocks);
            uint32_t psc_apb1 = (rcc_clocks.PCLK1_Frequency * 2) / DSHOT_TIMER_FREQUENCY - 1;
            uint32_t psc_apb2 = (rcc_clocks.PCLK2_Frequency * 2) / DSHOT_TIMER_FREQUENCY - 1;
            LL_TIM_SetPrescaler(TIM1, psc_apb2);
            LL_TIM_SetPrescaler(TIM4, psc_apb1);
            LL_TIM_SetPrescaler(TIM5, psc_apb1);

            uint32_t new_arr = DSHOT_TIMER_FREQUENCY / ((uint32_t)speed * 1000U);
            LL_TIM_SetAutoReload(TIM1, new_arr - 1);
            LL_TIM_SetAutoReload(TIM4, new_arr - 1);
            LL_TIM_SetAutoReload(TIM5, new_arr - 1);
            /* DShot updates CCR through DMA burst, so preload must stay enabled. */
            LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH1);
            LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH2);
            LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH3);
            LL_TIM_OC_EnablePreload(TIM1, LL_TIM_CHANNEL_CH4);
            LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH1);
            LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH2);
            LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH3);
            LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH4);
            LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH1);
            LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH2);
            LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH3);
            LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH4);
            TIM1->CCR1 = 0;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = 0;
            TIM1->CCR4 = 0;
            TIM4->CCR1 = 0;
            TIM4->CCR2 = 0;
            TIM4->CCR3 = 0;
            TIM4->CCR4 = 0;
            TIM5->CCR1 = 0;
            TIM5->CCR2 = 0;
            TIM5->CCR3 = 0;
            TIM5->CCR4 = 0;
            _setup_dshot_dma();
        }
    }
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    if (cfg->protocol == ACT_PROTOCOL_PWM) {
        DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

        LL_RCC_ClocksTypeDef rcc_clocks;
        LL_RCC_GetSystemClocksFreq(&rcc_clocks);
        uint32_t psc_apb2 = (rcc_clocks.PCLK2_Frequency * 2) / TIMER_FREQUENCY - 1;
        LL_TIM_SetPrescaler(TIM8, psc_apb2);

        if (__aux_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
            return RT_ERROR;
        }
    } else if (cfg->protocol == ACT_PROTOCOL_DSHOT) {
        DRV_DBG("aux out configured: dshot speed:%d\n", cfg->dshot_config.speed);
        uint16_t speed = cfg->dshot_config.speed;
        if (speed > 0) {
            LL_RCC_ClocksTypeDef rcc_clocks;
            LL_RCC_GetSystemClocksFreq(&rcc_clocks);
            uint32_t psc_apb2 = (rcc_clocks.PCLK2_Frequency * 2) / DSHOT_TIMER_FREQUENCY - 1;
            LL_TIM_SetPrescaler(TIM8, psc_apb2);

            uint32_t new_arr = DSHOT_TIMER_FREQUENCY / ((uint32_t)speed * 1000U);
            LL_TIM_SetAutoReload(TIM8, new_arr - 1);
            LL_TIM_OC_EnablePreload(TIM8, LL_TIM_CHANNEL_CH1);
            LL_TIM_OC_EnablePreload(TIM8, LL_TIM_CHANNEL_CH2);
            TIM8->CCR1 = 0;
            TIM8->CCR2 = 0;
            _setup_dshot_dma();
        }
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
        if (main_protocol == ACT_PROTOCOL_PWM) {
            /* set to lowest pwm before open */
            for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
                __main_write_pwm(i, VAL_TO_DC(1000, main_pwm_freq));
            }
        } else {
            TIM1->CCR1 = 0;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = 0;
            TIM1->CCR4 = 0;
            TIM4->CCR1 = 0;
            TIM4->CCR2 = 0;
            TIM4->CCR3 = 0;
            TIM4->CCR4 = 0;
            TIM5->CCR1 = 0;
            TIM5->CCR2 = 0;
            TIM5->CCR3 = 0;
            TIM5->CCR4 = 0;
        }

        LL_TIM_EnableCounter(TIM1);
        LL_TIM_EnableCounter(TIM4);
        LL_TIM_EnableCounter(TIM5);
        LL_TIM_EnableAllOutputs(TIM1);

        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH4);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH4);
        LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH4);

        DRV_DBG("main out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        LL_TIM_DisableCounter(TIM1);
        LL_TIM_DisableCounter(TIM4);
        LL_TIM_DisableCounter(TIM5);
        LL_TIM_DisableAllOutputs(TIM1);

        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH4);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH4);
        LL_TIM_CC_DisableChannel(TIM5, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM5, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM5, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM5, LL_TIM_CHANNEL_CH4);

        DRV_DBG("main out disabled\n");
        break;
    case ACT_CMD_SET_PROTOCOL: {
        uint8_t protocol = *(uint8_t*)arg;
        if (protocol == ACT_PROTOCOL_DSHOT || protocol == ACT_PROTOCOL_PWM) {
            main_protocol = protocol;
            dev->config.protocol = protocol;
            ret = RT_EOK;
        } else {
            ret = RT_EINVAL;
        }
        break;
    }
    case ACT_CMD_DSHOT_SEND: {
        struct dshot_command* c = (struct dshot_command*)arg;
        if (c == RT_NULL) {
            ret = RT_EINVAL;
            break;
        }
        if (dev->config.protocol != ACT_PROTOCOL_DSHOT) {
            ret = RT_EINVAL;
            break;
        }
        ret = _dshot_send_command(c->chan_mask, c->value, c->repeat ? c->repeat : 1, c->wait_ms, false);
        break;
    }
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

        LL_TIM_EnableCounter(TIM8);
        LL_TIM_EnableAllOutputs(TIM8);
        LL_TIM_EnableCounter(TIM12);

        LL_TIM_CC_EnableChannel(TIM8, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM8, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_EnableChannel(TIM12, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_EnableChannel(TIM12, LL_TIM_CHANNEL_CH2);

        DRV_DBG("aux out enabled\n");
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        LL_TIM_DisableCounter(TIM8);
        LL_TIM_DisableAllOutputs(TIM8);
        LL_TIM_DisableCounter(TIM12);

        LL_TIM_CC_DisableChannel(TIM8, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM8, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM12, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM12, LL_TIM_CHANNEL_CH2);

        DRV_DBG("aux out disabled\n");
        break;
    case ACT_CMD_SET_PROTOCOL: {
        uint8_t protocol = *(uint8_t*)arg;
        if (protocol == ACT_PROTOCOL_DSHOT || protocol == ACT_PROTOCOL_PWM) {
            aux_protocol = protocol;
            dev->config.protocol = protocol;
            ret = RT_EOK;
        } else {
            ret = RT_EINVAL;
        }
        break;
    }
    case ACT_CMD_DSHOT_SEND: {
        struct dshot_command* c = (struct dshot_command*)arg;
        if (c == RT_NULL) {
            ret = RT_EINVAL;
            break;
        }
        if (dev->config.protocol != ACT_PROTOCOL_DSHOT) {
            ret = RT_EINVAL;
            break;
        }
        ret = _dshot_send_command(c->chan_mask, c->value, c->repeat ? c->repeat : 1, c->wait_ms, true);
        break;
    }
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

    main_polled_mask |= chan_sel;

    if (main_protocol == ACT_PROTOCOL_DSHOT) {
        uint32_t current_arr = LL_TIM_GetAutoReload(TIM1);
        uint16_t packed_sel = 0;

        for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
            if (chan_sel & (1 << i)) {
                uint16_t dshot_val;
                val = *index;

                if (dshot_cmds[i].active) {
                    if (dshot_cmds[i].repeat > 0) {
                        dshot_val = dshot_cmds[i].cmd;
                        dshot_cmds[i].repeat--;
                        if (dshot_cmds[i].repeat == 0) {
                            dshot_cmds[i].wait_start_ms = systime_now_ms();
                            if (dshot_cmds[i].wait_ms == 0) {
                                dshot_cmds[i].active = false;
                            }
                        }
                    } else {
                        dshot_val = DSHOT_CMD_MOTOR_STOP;
                        if ((systime_now_ms() - dshot_cmds[i].wait_start_ms) >= dshot_cmds[i].wait_ms) {
                            dshot_cmds[i].active = false;
                        }
                    }
                } else {
                    float norm_throttle = (val > 1000) ? ((float)(val - 1000) / 1000.0f) : 0.0f;
                    FMS_Out_Bus fms_out;
                    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) == FMT_EOK && fms_out.status == VehicleStatus_Disarm) {
                        dshot_val = DSHOT_CMD_MOTOR_STOP;
                    } else {
                        dshot_val = dshot_throttle_to_value(norm_throttle);
                    }
                }

                uint16_t frame = dshot_pack_frame(dshot_val, dev->config.dshot_config.telem_req);
                _dshot_pack(i, frame, current_arr);
                packed_sel |= (1u << i);
                index++;
            }
        }
        if (packed_sel & 0x000F) {
            _dshot_clean_cache(0);
            _dshot_fire_tim(0);
        }
        if (packed_sel & 0x00F0) {
            _dshot_clean_cache(1);
            _dshot_fire_tim(1);
        }
        if (packed_sel & 0x0F00) {
            _dshot_clean_cache(2);
            _dshot_fire_tim(2);
        }
        return size;
    }

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

    aux_polled_mask |= chan_sel;

    if (aux_protocol == ACT_PROTOCOL_DSHOT) {
        uint32_t current_arr = LL_TIM_GetAutoReload(TIM8);
        uint16_t packed_sel_aux = 0;

        for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
            if (chan_sel & (1 << i)) {
                uint16_t dshot_val;
                val = *index;
                uint8_t global_idx = MAIN_PWM_CHAN + i;

                if (dshot_cmds[global_idx].active) {
                    if (dshot_cmds[global_idx].repeat > 0) {
                        dshot_val = dshot_cmds[global_idx].cmd;
                        dshot_cmds[global_idx].repeat--;
                        if (dshot_cmds[global_idx].repeat == 0) {
                            dshot_cmds[global_idx].wait_start_ms = systime_now_ms();
                            if (dshot_cmds[global_idx].wait_ms == 0) {
                                dshot_cmds[global_idx].active = false;
                            }
                        }
                    } else {
                        dshot_val = DSHOT_CMD_MOTOR_STOP;
                        if ((systime_now_ms() - dshot_cmds[global_idx].wait_start_ms) >= dshot_cmds[global_idx].wait_ms) {
                            dshot_cmds[global_idx].active = false;
                        }
                    }
                } else {
                    float norm_throttle = (val > 1000) ? ((float)(val - 1000) / 1000.0f) : 0.0f;
                    FMS_Out_Bus fms_out;
                    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) == FMT_EOK && fms_out.status == VehicleStatus_Disarm) {
                        dshot_val = DSHOT_CMD_MOTOR_STOP;
                    } else {
                        dshot_val = dshot_throttle_to_value(norm_throttle);
                    }
                }

                uint16_t frame = dshot_pack_frame(dshot_val, dev->config.dshot_config.telem_req);
                _dshot_pack(global_idx, frame, current_arr);
                packed_sel_aux |= (1u << i);
                index++;
            }
        }
        if (packed_sel_aux & 0x0003) {
            _dshot_clean_cache(3);
            _dshot_fire_tim(3);
        }
        return size;
    }

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

static struct actuator_device main_act_dev = { .chan_mask = 0xFFF,
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

rt_err_t drv_actuator_init(void)
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
