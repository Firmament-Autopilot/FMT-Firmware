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

#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_tim.h"
#include "stm32h7xx_ll_usart.h"

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

void TIM3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_TIM_IsActiveFlag_CC1(TIM3)) {
        uint32_t ic_val = LL_TIM_IC_GetCaptureCH1(TIM3) + 1;
        LL_TIM_ClearFlag_CC1(TIM3);

        ppm_update(&ppm_decoder, ic_val);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void UART8_IRQHandler(void)
{
    uint8_t ch;
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_USART_IsActiveFlag_RXNE(UART8)) {
        do {
            ch = LL_USART_ReceiveData8(UART8);
            sbus_input(&sbus_decoder, &ch, 1);
        } while (LL_USART_IsActiveFlag_RXNE(UART8));

        /* if it's reading sbus data, we just parse it later */
        if (!sbus_islock(&sbus_decoder)) {
            sbus_update(&sbus_decoder);
        }
        /* the RXNE flag is cleared by reading the USART_RDR register */
    }

    if (LL_USART_IsActiveFlag_IDLE(UART8)) {
        LL_USART_ClearFlag_IDLE(UART8);
    }

    if (LL_USART_IsActiveFlag_FE(UART8)) {
        LL_USART_ClearFlag_FE(UART8);
    }

    if (LL_USART_IsActiveFlag_PE(UART8)) {
        LL_USART_ClearFlag_PE(UART8);
    }

    if (LL_USART_IsActiveFlag_ORE(UART8)) {
        LL_USART_ClearFlag_ORE(UART8);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t ppm_lowlevel_init(void)
{
    LL_TIM_InitTypeDef TIM_InitStruct = { 0 };
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    LL_RCC_ClocksTypeDef RCC_Clock;
    uint32_t TIM3_Clk;

    LL_RCC_GetSystemClocksFreq(&RCC_Clock);
    /* APB1 Timer Clock = PCLK1 * 2 */
    TIM3_Clk = RCC_Clock.PCLK1_Frequency * 2;

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
    /**TIM3 GPIO Configuration
    PB4 (NJTRST)   ------> TIM3_CH1
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP; /* Need internal pull-up, otherwise an unexpected interupt generated */
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* TIM3 interrupt Init */
    NVIC_SetPriority(TIM3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(TIM3_IRQn);

    /* USER CODE BEGIN TIM3_Init 1 */

    /* USER CODE END TIM3_Init 1 */
    TIM_InitStruct.Prescaler = TIM3_Clk / PPM_DECODER_FREQUENCY - 1;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = 65535;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    LL_TIM_DeInit(TIM3);
    LL_TIM_Init(TIM3, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM3);
    LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM3);
    LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);

    return RT_EOK;
}

static rt_err_t sbus_lowlevel_init(void)
{
    LL_USART_InitTypeDef UART_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_RCC_SetUSARTClockSource(LL_RCC_USART234578_CLKSOURCE_PCLK1);

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_UART8);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
    /**UART8 GPIO Configuration
    PE1   ------> UART8_TX
    PE0   ------> UART8_RX
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_1 | LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* USER CODE BEGIN UART8_Init 1 */

    /* UART8 interrupt Init */
    NVIC_SetPriority(UART8_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(UART8_IRQn);

    /* USER CODE END UART8_Init 1 */
    UART_InitStruct.PrescalerValue = LL_USART_PRESCALER_DIV1;
    UART_InitStruct.BaudRate = 100000;
    UART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    UART_InitStruct.StopBits = LL_USART_STOPBITS_2;
    UART_InitStruct.Parity = LL_USART_PARITY_EVEN;
    UART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    UART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    UART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
    LL_USART_Init(UART8, &UART_InitStruct);
    LL_USART_DisableFIFO(UART8);
    LL_USART_SetTXFIFOThreshold(UART8, LL_USART_FIFOTHRESHOLD_1_8);
    LL_USART_SetRXFIFOThreshold(UART8, LL_USART_FIFOTHRESHOLD_1_8);
    LL_USART_SetRXPinLevel(UART8, LL_USART_RXPIN_LEVEL_INVERTED);
    LL_USART_ConfigAsyncMode(UART8);

    /* USER CODE BEGIN WKUPType UART8 */

    /* USER CODE END WKUPType UART8 */

    LL_USART_Enable(UART8);

    /* Polling UART8 initialisation */
    while ((!(LL_USART_IsActiveFlag_TEACK(UART8))) || (!(LL_USART_IsActiveFlag_REACK(UART8)))) {
    }

    return RT_EOK;
}

rt_err_t rc_init(rc_dev_t dev)
{
    /* open interrupt */
    LL_TIM_EnableCounter(TIM3);
    LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
    LL_TIM_EnableIT_CC1(TIM3);

    LL_USART_EnableIT_RXNE(UART8);

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
    .rc_init = rc_init,
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
    /* init ppm decoder */
    RT_TRY(ppm_decoder_init(&ppm_decoder, PPM_DECODER_FREQUENCY));
    /* init ppm driver */
    RT_TRY(ppm_lowlevel_init());

    RT_TRY(sbus_decoder_init(&sbus_decoder));
    RT_TRY(sbus_lowlevel_init());

    RT_CHECK(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}