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
#include <stdio.h>
#include <string.h>

#include "debug.h"
#include "interface.h"
#include "ppm_decoder.h"
#include "protocol.h"
#include "time.h"
#include "usart.h"

#define GET_GAP(x, y) x > y ? (x - y) : (0xFFFF - y + x)

//capture accuracy is 0.001ms
#define ENCODER_FREQ 1000000
static float Scale_US = 1000000.0f / ENCODER_FREQ;
static uint8_t _ppm_send_freq = 20; /* default is 20Hz */
static uint8_t _ppm_recv = 0;
static uint8_t _ppm_sending = 0;

ppm_encoder_t ppm_param;

void ppm_status_machine(uint16_t IC_Val)
{
    static uint16_t temp_val[MAX_PPM_CHANNEL];
    uint16_t gap;

    gap = GET_GAP(IC_Val, ppm_param.last_ic);

    if (gap > ENCODER_FREQ / 1000 * 0.9f && gap < ENCODER_FREQ / 1000 * 2.1f) {
        /* valid ppm signal should between 1ms(100) to 2ms(200) */
        if (ppm_param.chan_id < MAX_PPM_CHANNEL) {
            temp_val[ppm_param.chan_id] = gap;
            ppm_param.chan_id++;
        }
    } else {
        /* sync signal */
        if (ppm_param.chan_id >= 1 && ppm_param.chan_id <= MAX_PPM_CHANNEL) {
            /* get total channel count */
            ppm_param.total_chan = ppm_param.chan_id;
        }

        if (ppm_param.total_chan && ppm_param.chan_id == ppm_param.total_chan && !_ppm_sending) {
            uint8_t i;

            /* reveived all channel data */
            for (i = 0; i < ppm_param.total_chan; i++) {
                ppm_param.ppm_val[i] = Scale_US * temp_val[i];

                if (ppm_param.ppm_val[i] < 1000) {
                    ppm_param.ppm_val[i] = 1000;
                } else if (ppm_param.ppm_val[i] > 2000) {
                    ppm_param.ppm_val[i] = 2000;
                }
            }

            _ppm_recv = 1;
        }

        ppm_param.chan_id = 0;
    }

    /* update last capture value */
    ppm_param.last_ic = IC_Val;
}

void TIM1_irq_event_handler(void)
{
    volatile uint16_t IC1ReadValue = 0;

    if (TIM_GetITStatus(TIM1, TIM_IT_CC1) == SET) {
        /* Clear TIM1 Capture compare interrupt pending bit */
        TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);

        IC1ReadValue = TIM_GetCapture1(TIM1);
        ppm_status_machine(IC1ReadValue);
    }
}

void get_ppm_value(uint16_t* val)
{
    uint8_t i;

    for (i = 0; i < MAX_PPM_CHANNEL; i++) {
        val[i] = ppm_param.ppm_val[i];
    }
}

uint8_t config_ppm_send_freq(uint8_t freq)
{
    if (freq >= 0 && freq <= 50) {
        _ppm_send_freq = freq;
        return 1;
    } else
        return 0;
}

uint8_t send_ppm_value(void)
{
    if (!_ppm_recv) {
        return 0;
    }

    if (rc_signal_ready()) {
        _ppm_sending = 1;
        send_io_cmd(IO_CODE_RC_DATA, ppm_param.ppm_val, 32);
        _ppm_recv = 0;
        _ppm_sending = 0;
    }

    return 1;
}

uint8_t ppm_decoder_init(void)
{
    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Clock Enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* Enable global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* TIM1 channel 1 pin (PA.08) configuration */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Time Base configuration */
    TIM_TimeBaseStructure.TIM_Prescaler = SystemCoreClock / ENCODER_FREQ;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;

    TIM_ICInit(TIM1, &TIM_ICInitStructure);

    /* TIM enable counter */
    TIM_Cmd(TIM1, ENABLE);
    /* Enable the CC1 Interrupt Request */
    TIM_ITConfig(TIM1, TIM_IT_CC1, ENABLE);

    ppm_param.chan_id = 0;
    ppm_param.total_chan = 0;
    ppm_param.last_ic = 0;

    memset(ppm_param.ppm_val, 0, sizeof(ppm_param.ppm_val));

    return 1;
}

void ppm_decoder_deinit(void)
{
    TIM_ITConfig(TIM1, TIM_IT_CC1, DISABLE);
    TIM_Cmd(TIM1, DISABLE);
}
