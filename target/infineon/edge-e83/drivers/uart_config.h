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

#ifdef BSP_USING_UART1
cy_stc_sysint_t UART1_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_1_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif

#ifdef BSP_USING_UART2
cy_stc_sysint_t UART2_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_2_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif

#ifdef BSP_USING_UART5
cy_stc_sysint_t UART5_SCB_IRQ_cfg = {
    .intrSrc = (IRQn_Type)scb_5_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif

/* UART1 */
#if defined(BSP_USING_UART1)
    #ifndef UART1_CONFIG
        #define UART1_CONFIG                                      \
            {                                                     \
                .name = "uart1",                                  \
                .usart_x = SCB1,                                  \
                .intrSrc = scb_1_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART1_config,               \
                .hal_uart_configurator = &CYBSP_UART1_hal_config, \
                .userIsr = uart_isr_callback(uart1),              \
                .UART_SCB_IRQ_cfg = &UART1_SCB_IRQ_cfg,           \
            }
    #endif
void uart1_isr_callback(void);
#endif /* BSP_USING_UART1 */

/* UART2 */
#if defined(BSP_USING_UART2)
    #ifndef UART2_CONFIG
        #define UART2_CONFIG                                           \
            {                                                          \
                .name = "serial2",                                     \
                .usart_x = SCB2,                                       \
                .intrSrc = scb_2_interrupt_IRQn,                       \
                .uart_config = &CYBSP_DEBUG_UART_config,               \
                .hal_uart_configurator = &CYBSP_DEBUG_UART_hal_config, \
                .userIsr = uart_isr_callback(uart2),                   \
                .UART_SCB_IRQ_cfg = &UART2_SCB_IRQ_cfg,                \
            }
    #endif
void uart2_isr_callback(void);
#endif /* BSP_USING_UART2 */

/* UART5 */
#if defined(BSP_USING_UART5)
    #ifndef UART5_CONFIG
        #define UART5_CONFIG                                      \
            {                                                     \
                .name = "serial5",                                \
                .usart_x = SCB5,                                  \
                .intrSrc = scb_5_interrupt_IRQn,                  \
                .uart_config = &CYBSP_UART5_config,               \
                .hal_uart_configurator = &CYBSP_UART5_hal_config, \
                .userIsr = uart_isr_callback(uart5),              \
                .UART_SCB_IRQ_cfg = &UART5_SCB_IRQ_cfg,           \
            }
    #endif
void uart5_isr_callback(void);
#endif /* BSP_USING_UART5 */

#ifdef __cplusplus
}
#endif

#endif
