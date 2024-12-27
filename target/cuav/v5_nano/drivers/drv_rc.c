/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "hal/rc/ppm.h"
#include "hal/rc/rc.h"
#include "hal/rc/sbus.h"

#include "stm32f7xx_ll_rcc.h"
#include "stm32f7xx_ll_tim.h"
#include "stm32f7xx_ll_usart.h"

#ifndef min // mod by prife
    #define min(x, y) (x < y ? x : y)
#endif

/* capture accuracy is 0.001ms */
#define PPM_DECODER_FREQUENCY 1000000

/* default config for rc device */
#define RC_CONFIG_DEFAULT                      \
    {                                          \
        RC_PROTOCOL_AUTO, /* auto */           \
            6,            /* 6 channel */      \
            0.05f,        /* sample time */    \
            1000,         /* minimal 1000us */ \
            2000,         /* maximal 2000us */ \
    }

static ppm_decoder_t ppm_decoder;
static sbus_decoder_t sbus_decoder;

void TIM8_CC_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_TIM_IsActiveFlag_CC1(TIM8)) {
        uint32_t ic_val = LL_TIM_IC_GetCaptureCH1(TIM8) + 1;
        LL_TIM_ClearFlag_CC1(TIM8);

        ppm_update(&ppm_decoder, ic_val);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void USART6_IRQHandler(void)
{
    uint8_t ch;
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_USART_IsActiveFlag_RXNE(USART6)) {
        do {
            ch = LL_USART_ReceiveData8(USART6);
            sbus_input(&sbus_decoder, &ch, 1);
        } while (LL_USART_IsActiveFlag_RXNE(USART6));

        /* if it's reading sbus data, we just parse it later */
        if (!sbus_islock(&sbus_decoder)) {
            sbus_update(&sbus_decoder);
        }
        /* the RXNE flag is cleared by reading the USART_RDR register */
    }

    if (LL_USART_IsActiveFlag_IDLE(USART6)) {
        LL_USART_ClearFlag_IDLE(USART6);
    }

    if (LL_USART_IsActiveFlag_FE(USART6)) {
        LL_USART_ClearFlag_FE(USART6);
    }

    if (LL_USART_IsActiveFlag_PE(USART6)) {
        LL_USART_ClearFlag_PE(USART6);
    }

    if (LL_USART_IsActiveFlag_ORE(USART6)) {
        LL_USART_ClearFlag_ORE(USART6);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t ppm_lowlevel_init(void)
{
    LL_TIM_InitTypeDef TIM_InitStruct = { 0 };
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    LL_RCC_ClocksTypeDef RCC_Clock;
    uint32_t TIM8_Clk;

    LL_RCC_GetSystemClocksFreq(&RCC_Clock);
    /* APB2 Timer Clock = PCLK1 * 2 */
    TIM8_Clk = RCC_Clock.PCLK2_Frequency * 2;

    /* Peripheral clock enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM8);

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
    /**TIM8 GPIO Configuration
    PI5   ------> TIM8_CH1
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_3;
    LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    /* TIM8 interrupt Init */
    NVIC_SetPriority(TIM8_CC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(TIM8_CC_IRQn);

    /* USER CODE BEGIN TIM3_Init 1 */

    /* USER CODE END TIM3_Init 1 */
    TIM_InitStruct.Prescaler = TIM8_Clk / PPM_DECODER_FREQUENCY - 1;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = 65535;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    TIM_InitStruct.RepetitionCounter = 0;
    LL_TIM_Init(TIM8, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM8);
    LL_TIM_SetTriggerOutput(TIM8, LL_TIM_TRGO_RESET);
    LL_TIM_SetTriggerOutput2(TIM8, LL_TIM_TRGO2_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM8);
    LL_TIM_IC_SetActiveInput(TIM8, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM8, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM8, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM8, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);

    LL_TIM_EnableCounter(TIM8);
    LL_TIM_CC_EnableChannel(TIM8, LL_TIM_CHANNEL_CH1);
    LL_TIM_EnableIT_CC1(TIM8);

    return RT_EOK;
}

static rt_err_t sbus_lowlevel_init(void)
{
    LL_USART_InitTypeDef USART_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_RCC_SetUSARTClockSource(LL_RCC_USART6_CLKSOURCE_PCLK2);

    /* Peripheral clock enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART6);

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
    /**USART6 GPIO Configuration
    PG14   ------> USART6_TX
    PG9   ------> USART6_RX
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    /* USART6 interrupt Init */
    NVIC_SetPriority(USART6_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(USART6_IRQn);

    /* USER CODE BEGIN USART6_Init 1 */

    /* USER CODE END USART6_Init 1 */
    USART_InitStruct.BaudRate = 100000;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_2;
    USART_InitStruct.Parity = LL_USART_PARITY_EVEN;
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
    LL_USART_Init(USART6, &USART_InitStruct);
    LL_USART_SetRXPinLevel(USART6, LL_USART_RXPIN_LEVEL_INVERTED);
    LL_USART_SetTXRXSwap(USART6, LL_USART_TXRX_SWAPPED);
    LL_USART_ConfigAsyncMode(USART6);
    LL_USART_Enable(USART6);

    LL_USART_EnableIT_RXNE(USART6);

    return RT_EOK;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void* arg)
{
    switch (cmd) {
    case RC_CMD_CHECK_UPDATE: {
        uint8_t updated = 0;

        if (rc->config.protocol == RC_PROTOCOL_SBUS) {
            updated = sbus_data_ready(&sbus_decoder);
        } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
            updated = ppm_data_ready(&ppm_decoder);
        }

        *(uint8_t*)arg = updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_uint16_t rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
{
    uint16_t* index = chan_val;
    rt_uint16_t rb = 0;

    if (rc->config.protocol == RC_PROTOCOL_SBUS) {
        if (sbus_data_ready(&sbus_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        sbus_lock(&sbus_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, sbus_decoder.rc_count); i++) {
            *(index++) = sbus_decoder.sbus_val[i];
            rb += 2;
        }
        sbus_data_clear(&sbus_decoder);

        sbus_unlock(&sbus_decoder);
    } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
        if (ppm_data_ready(&ppm_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        ppm_lock(&ppm_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, ppm_decoder.total_chan); i++) {
            if (chan_mask & (1 << i)) {
                *(index++) = ppm_decoder.ppm_val[i];
                rb += 2;
            }
        }
        ppm_data_clear(&ppm_decoder);

        ppm_unlock(&ppm_decoder);
    }

    return rb;
}

const static struct rc_ops rc_ops = {
    .rc_config = NULL,
    .rc_control = rc_control,
    .rc_read = rc_read,
};

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops = &rc_ops,
};

rt_err_t drv_rc_init(void)
{
    /* init ppm driver */
    RT_TRY(ppm_lowlevel_init());
    /* init ppm decoder */
    RT_TRY(ppm_decoder_init(&ppm_decoder, PPM_DECODER_FREQUENCY));

    RT_TRY(sbus_lowlevel_init());
    RT_TRY(sbus_decoder_init(&sbus_decoder));

    RT_CHECK(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}