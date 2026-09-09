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
    .intrSrc = (IRQn_Type)CYBSP_UART1_TX_DMA_IRQ,
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
    .intrSrc = (IRQn_Type)CYBSP_UART2_TX_DMA_IRQ,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART4) || defined(BSP_USING_UART4_DMA_TX)
static cy_stc_sysint_t UART4_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_4_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART4_DMA_TX
static cy_stc_sysint_t UART4_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)CYBSP_UART4_TX_DMA_IRQ,
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
    .intrSrc = (IRQn_Type)CYBSP_UART5_TX_DMA_IRQ,
    .intrPriority = (6u),
};
#endif
#if defined(BSP_USING_UART6) || defined(BSP_USING_UART6_DMA_TX)
static cy_stc_sysint_t UART6_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_6_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART6_DMA_TX
static cy_stc_sysint_t UART6_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)CYBSP_UART6_TX_DMA_IRQ,
    .intrPriority = (6u),
};
#endif
#if defined(BSP_USING_UART9)
static cy_stc_sysint_t UART9_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_9_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART9_DMA_TX
static cy_stc_sysint_t UART9_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)CYBSP_UART9_TX_DMA_IRQ,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART10)
static cy_stc_sysint_t UART10_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_10_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART10_DMA_TX
static cy_stc_sysint_t UART10_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)CYBSP_UART10_TX_DMA_IRQ,
    .intrPriority = (6u),
};
#endif

#if defined(BSP_USING_UART11)
static cy_stc_sysint_t UART11_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_11_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif
#ifdef BSP_USING_UART11_DMA_TX
static cy_stc_sysint_t UART11_TX_DMA_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)CYBSP_UART11_TX_DMA_IRQ,
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
            .tx_dma_irq = CYBSP_UART1_TX_DMA_IRQ,                                \
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
            .tx_dma_irq = CYBSP_UART2_TX_DMA_IRQ,                                \
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
                .uart_config = &CYBSP_UART2_config,                    \
                .hal_uart_configurator = &CYBSP_UART2_hal_config,      \
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
 * UART4
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART4)

    #ifdef BSP_USING_UART4_DMA_TX
        #define UART4_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART4_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART4_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART4_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart4_dma_tx_isr_callback,                             \
            .tx_dma_irq = CYBSP_UART4_TX_DMA_IRQ,                                \
            .tx_dma_channel = CYBSP_UART4_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART4_TX_DMA_HW,
    #else
        #define UART4_DMA_TX_CONFIG
    #endif

    #ifndef UART4_CONFIG
        #define UART4_CONFIG                                           \
            {                                                          \
                .name = "serial0",                                     \
                .usart_x = SCB4,                                       \
                .intrSrc = scb_4_interrupt_IRQn,                       \
                .uart_config = &CYBSP_DEBUG_UART_config,               \
                .hal_uart_configurator = &CYBSP_DEBUG_UART_hal_config, \
                .userIsr = uart4_isr_callback,                         \
                .UART_SCB_IRQ_cfg = &UART4_SCB_IRQ_cfg,                \
                UART4_DMA_TX_CONFIG                                    \
            }
    #endif

void uart4_isr_callback(void);
    #ifdef BSP_USING_UART4_DMA_TX
void uart4_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART4 */

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
            .tx_dma_irq = CYBSP_UART5_TX_DMA_IRQ,                                \
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

#if defined(BSP_USING_UART6)

    #ifdef BSP_USING_UART6_DMA_TX
        #define UART6_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART6_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART6_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART6_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart6_dma_tx_isr_callback,                             \
            .tx_dma_irq = CYBSP_UART6_TX_DMA_IRQ,                                \
            .tx_dma_channel = CYBSP_UART6_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART6_TX_DMA_HW,
    #else
        #define UART6_DMA_TX_CONFIG
    #endif

    #ifndef UART6_CONFIG
        #define UART6_CONFIG                                      \
            {                                                     \
                .name = "serial6",                                \
                .usart_x = SCB6,                                  \
                .intrSrc = scb_6_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART6_config,               \
                .hal_uart_configurator = &CYBSP_UART6_hal_config, \
                .userIsr = uart6_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART6_SCB_IRQ_cfg,           \
                UART6_DMA_TX_CONFIG                               \
            }
    #endif

void uart6_isr_callback(void);
    #ifdef BSP_USING_UART6_DMA_TX
void uart6_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART6 */

/* ----------------------------------------------------------------
 * UART9
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART9)

    #ifdef BSP_USING_UART9_DMA_TX
        #define UART9_DMA_TX_CONFIG                                              \
            .tx_dma_descriptor_config = &CYBSP_UART9_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART9_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART9_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart9_dma_tx_isr_callback,                             \
            .tx_dma_irq = CYBSP_UART9_TX_DMA_IRQ,                                \
            .tx_dma_channel = CYBSP_UART9_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART9_TX_DMA_HW,
    #else
        #define UART9_DMA_TX_CONFIG
    #endif

    #ifndef UART9_CONFIG
        #define UART9_CONFIG                                      \
            {                                                     \
                .name = "serial3",                               \
                .usart_x = SCB9,                                  \
                .intrSrc = scb_9_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART9_config,               \
                .hal_uart_configurator = &CYBSP_UART9_hal_config, \
                .userIsr = uart9_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART9_SCB_IRQ_cfg,           \
                UART9_DMA_TX_CONFIG                               \
            }
    #endif

void uart9_isr_callback(void);
    #ifdef BSP_USING_UART9_DMA_TX
void uart9_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART9 */

/* ----------------------------------------------------------------
 * UART10
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART10)

    #ifdef BSP_USING_UART10_DMA_TX
        #define UART10_DMA_TX_CONFIG                                                \
            .tx_dma_descriptor_config = &CYBSP_UART10_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART10_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART10_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart10_dma_tx_isr_callback,                             \
            .tx_dma_irq = CYBSP_UART10_TX_DMA_IRQ,                                \
            .tx_dma_channel = CYBSP_UART10_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART10_TX_DMA_HW,
    #else
        #define UART10_DMA_TX_CONFIG
    #endif

    #ifndef UART10_CONFIG
        #define UART10_CONFIG                                      \
            {                                                      \
                .name = "serial4",                               \
                .usart_x = SCB10,                                  \
                .intrSrc = scb_10_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART10_config,               \
                .hal_uart_configurator = &CYBSP_UART10_hal_config, \
                .userIsr = uart10_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART10_SCB_IRQ_cfg,           \
                UART10_DMA_TX_CONFIG                               \
            }
    #endif

void uart10_isr_callback(void);
    #ifdef BSP_USING_UART10_DMA_TX
void uart10_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART10 */

/* ----------------------------------------------------------------
 * UART11
 * ---------------------------------------------------------------- */
#if defined(BSP_USING_UART11)

    #ifdef BSP_USING_UART11_DMA_TX
        #define UART11_DMA_TX_CONFIG                                                \
            .tx_dma_descriptor_config = &CYBSP_UART11_TX_DMA_Descriptor_0_config, \
            .tx_dma_channel_config = &CYBSP_UART11_TX_DMA_channelConfig,          \
            .tx_dma_int_cfg = &UART11_TX_DMA_SCB_IRQ_cfg,                         \
            .tx_dma_isr = uart11_dma_tx_isr_callback,                             \
            .tx_dma_irq = CYBSP_UART11_TX_DMA_IRQ,                                \
            .tx_dma_channel = CYBSP_UART11_TX_DMA_CHANNEL,                        \
            .tx_dma_hw = CYBSP_UART11_TX_DMA_HW,
    #else
        #define UART11_DMA_TX_CONFIG
    #endif

    #ifndef UART11_CONFIG
        #define UART11_CONFIG                                      \
            {                                                      \
                .name = "serial11",                               \
                .usart_x = SCB11,                                  \
                .intrSrc = scb_11_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART11_config,               \
                .hal_uart_configurator = &CYBSP_UART11_hal_config, \
                .userIsr = uart11_isr_callback,                    \
                .UART_SCB_IRQ_cfg = &UART11_SCB_IRQ_cfg,           \
                UART11_DMA_TX_CONFIG                               \
            }
    #endif

void uart11_isr_callback(void);
    #ifdef BSP_USING_UART11_DMA_TX
void uart11_dma_tx_isr_callback(void);
    #endif

#endif /* BSP_USING_UART11 */

#ifdef __cplusplus
}
#endif

#endif /* __UART_CONFIG_H__ */