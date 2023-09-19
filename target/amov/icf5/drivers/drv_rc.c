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

static ppm_decoder_t  ppm_decoder;
static sbus_decoder_t sbus_decoder;

void TIMER0_BRK_TIMER8_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (SET == timer_interrupt_flag_get(TIMER8, TIMER_INT_CH1)) {
        /* clear channel 0 interrupt bit */
        timer_interrupt_flag_clear(TIMER8, TIMER_INT_CH1);

        uint32_t ic_val = timer_channel_capture_value_register_read(TIMER8, TIMER_CH_1) + 1;
        ppm_update(&ppm_decoder, ic_val);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void USART5_IRQHandler(void)
{
    uint8_t ch;
    /* enter interrupt */
    rt_interrupt_enter();

    if ((usart_interrupt_flag_get(USART5, USART_INT_FLAG_RBNE) != RESET)) {
        while (usart_flag_get(USART5, USART_FLAG_RBNE) != RESET) {
            ch = (uint8_t)usart_data_receive(USART5);
            sbus_input(&sbus_decoder, &ch, 1);
        }

        /* if it's reading sbus data, we just parse it later */
        if (!sbus_islock(&sbus_decoder)) {
            sbus_update(&sbus_decoder);
        }

        /* Clear RXNE interrupt flag */
        usart_flag_clear(USART5, USART_FLAG_RBNE);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t ppm_lowlevel_init(void)
{
    /* initialize gpio */

    rcu_periph_clock_enable(RCU_GPIOE);

    /*configure PE6 (TIMER8 CH1) as alternate function*/
    gpio_mode_set(GPIOE, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_6);
    gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);

    gpio_af_set(GPIOE, GPIO_AF_3, GPIO_PIN_6);

    /* initialize isr */
    nvic_irq_enable(TIMER0_BRK_TIMER8_IRQn, 1, 1);

    /* timer configuration for input capture */

    timer_ic_parameter_struct timer_icinitpara;
    timer_parameter_struct    timer_initpara;
    uint32_t                  APB1_2_PrescalerValue;

    rcu_periph_clock_enable(RCU_TIMER8);

    /* When TIMERSEL is set, the TIMER clock is equal to CK_AHB(CK_TIMERx = CK_AHB). */
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);

    /* APB1_2_PrescalerValue = SystemCoreClock / TARGET_TIMER_CLK */
    APB1_2_PrescalerValue = SystemCoreClock / PPM_DECODER_FREQUENCY - 1;

    timer_deinit(TIMER8);
    /* TIMER2 configuration */
    timer_initpara.prescaler         = APB1_2_PrescalerValue;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER8, &timer_initpara);

    /* TIMER8  configuration */
    /* TIMER8 CH1 input capture configuration */
    timer_icinitpara.icpolarity  = TIMER_IC_POLARITY_RISING;
    timer_icinitpara.icselection = TIMER_IC_SELECTION_DIRECTTI;
    timer_icinitpara.icprescaler = TIMER_IC_PSC_DIV1;
    timer_icinitpara.icfilter    = 0x0;
    timer_input_capture_config(TIMER8, TIMER_CH_1, &timer_icinitpara);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER8);
    /* clear channel 0 interrupt bit */
    timer_interrupt_flag_clear(TIMER8, TIMER_INT_CH1);
    /* channel 0 interrupt enable */
    timer_interrupt_enable(TIMER8, TIMER_INT_CH1);

    /* TIMER8 counter enable */
    timer_enable(TIMER8);

    return RT_EOK;
}

static rt_err_t sbus_lowlevel_init(void)
{
    /* initialize gpio */

    /* enable gpio clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_USART5);

    /* connect port to USARTx_Rx */
    gpio_af_set(GPIOC, GPIO_AF_8, GPIO_PIN_7);
    /* configure USART Rx as alternate function push-pull */
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_7);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);

    /* config usart */

    /* 100000bps, even parity, two stop bits */
    usart_baudrate_set(USART5, 100000);
    usart_word_length_set(USART5, USART_WL_8BIT);
    usart_stop_bit_set(USART5, USART_STB_2BIT);
    usart_parity_config(USART5, USART_PM_EVEN);
    usart_receive_config(USART5, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART5, USART_TRANSMIT_ENABLE); // TODO, need sbus output?
    usart_enable(USART5);

    /* initialize isr */
    nvic_irq_enable(USART5_IRQn, 1, 1);
    /* enable interrupt */
    usart_interrupt_enable(USART5, USART_INT_RBNE);

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
    uint16_t*   index = chan_val;
    rt_uint16_t rb    = 0;

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
    .rc_config  = NULL,
    .rc_control = rc_control,
    .rc_read    = rc_read,
};

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops    = &rc_ops,
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