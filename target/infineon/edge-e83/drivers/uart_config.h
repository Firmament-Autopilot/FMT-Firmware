/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__

#include "board.h"
#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BSP_USING_UART1) || defined(BSP_USING_UART1_DMA_TX)
static cy_stc_sysint_t UART1_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_1_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART1_DMA_TX
static cy_stc_sysint_t UART1_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)cpuss_interrupts_dw0_x_IRQn,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART2) || defined(BSP_USING_UART2_DMA_TX)
static cy_stc_sysint_t UART2_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_2_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART2_DMA_TX
static cy_stc_sysint_t UART2_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)cpuss_interrupts_dw0_1_IRQn,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART5) || defined(BSP_USING_UART5_DMA_TX)
static cy_stc_sysint_t UART5_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_5_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART5_DMA_TX
static cy_stc_sysint_t UART5_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)cpuss_interrupts_dw0_2_IRQn,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART1)

    #ifdef BSP_USING_UART1_DMA_TX
        #define UART1_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART1_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART1_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART1_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart1_dma_tx_isr_callback,                             \
            .tx_dma_irq = cpuss_interrupts_dw0_x_IRQn,                           \
            .tx_dma_channel = CYBSP_UART1_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART1_TX_DMA_HW,
    #else
        #define UART1_DMA_TX_CONFIG
    #endif

    #ifndef UART1_CONFIG
        #define UART1_CONFIG                                      \
            {                                                     \
                .name = "serial1",                                \
                .usart_x = SCB1,                                  \
                .intrSrc = scb_1_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART1_config,               \
                .hal_uart_configurator = &CYBSP_UART1_hal_config, \
                .userIsr = uart1_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART1_SCB_IRQ_cfg,           \
                UART1_DMA_TX_CONFIG                               \
            }
    #endif

void uart1_isr_callback(void);
    #ifdef BSP_USING_UART1_DMA_TX
void uart1_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART1 */

/* ----------------------------------------------------------------
 * UART2
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART2)

    #ifdef BSP_USING_UART2_DMA_TX
        #define UART2_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART2_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART2_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART2_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart2_dma_tx_isr_callback,                             \
            .tx_dma_irq = cpuss_interrupts_dw0_1_IRQn,                           \
            .tx_dma_channel = CYBSP_UART2_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART2_TX_DMA_HW,
    #else
        #define UART2_DMA_TX_CONFIG
    #endif

    #ifndef UART2_CONFIG
        #define UART2_CONFIG                                           \
            {                                                          \
                .name = "serial2",                                     \
                .usart_x = SCB2,                                       \
                .intrSrc = scb_2_interrupt_IRQn,                       \
                .uart_config = &CYBSP_DEBUG_UART_config,               \
                .hal_uart_configurator = &CYBSP_DEBUG_UART_hal_config, \
                .userIsr = uart2_isr_callback,                         \
                .UART_SCB_IRQ_cfg = &UART2_SCB_IRQ_cfg,                \
                UART2_DMA_TX_CONFIG                                    \
            }
    #endif

void uart2_isr_callback(void);
    #ifdef BSP_USING_UART2_DMA_TX
void uart2_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART2 */

/* ----------------------------------------------------------------
 * UART5
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART5)

    #ifdef BSP_USING_UART5_DMA_TX
        #define UART5_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART5_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART5_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART5_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart5_dma_tx_isr_callback,                             \
            .tx_dma_irq = cpuss_interrupts_dw0_2_IRQn,                           \
            .tx_dma_channel = CYBSP_UART5_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART5_TX_DMA_HW,
    #else
        #define UART5_DMA_TX_CONFIG
    #endif

    #ifndef UART5_CONFIG
        #define UART5_CONFIG                                      \
            {                                                     \
                .name = "serial5",                                \
                .usart_x = SCB5,                                  \
                .intrSrc = scb_5_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART5_config,               \
                .hal_uart_configurator = &CYBSP_UART5_hal_config, \
                .userIsr = uart5_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART5_SCB_IRQ_cfg,           \
                UART5_DMA_TX_CONFIG                               \
            }
    #endif

void uart5_isr_callback(void);
    #ifdef BSP_USING_UART5_DMA_TX
void uart5_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART5 */

#ifdef __cplusplus
}
#endif

#endif /* __UART_CONFIG_H__ */