/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-08     Rbb666       first version
 */

#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__

#include <rtthread.h>
#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BSP_USING_UART1
cy_stc_sysint_t UART1_SCB_IRQ_cfg =
{
    .intrSrc = (IRQn_Type)scb_1_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif

#ifdef BSP_USING_UART2
cy_stc_sysint_t UART2_SCB_IRQ_cfg =
{
    .intrSrc = (IRQn_Type)scb_2_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif

#ifdef BSP_USING_UART5
cy_stc_sysint_t UART5_SCB_IRQ_cfg =
{
    .intrSrc = (IRQn_Type)scb_5_interrupt_IRQn,
    .intrPriority = (7u),
};
#endif


/* UART1 */
#if defined(BSP_USING_UART1)
#ifndef UART1_CONFIG
#define UART1_CONFIG                            \
    {                                           \
        .name = "uart1",                        \
        .usart_x = SCB1,                        \
        .intrSrc = scb_1_interrupt_IRQn,        \
        .uart_config = &CYBSP_UART1_config,     \
        .hal_uart_configurator = &CYBSP_UART1_hal_config, \
        .userIsr = uart_isr_callback(uart1),    \
        .UART_SCB_IRQ_cfg = &UART1_SCB_IRQ_cfg, \
    }
#endif
void uart1_isr_callback(void);
#endif /* BSP_USING_UART1 */


/* UART2 */
#if defined(BSP_USING_UART2)
#ifndef UART2_CONFIG
#define UART2_CONFIG                                \
    {                                               \
        .name = "uart2",                            \
        .usart_x = SCB2,                            \
        .intrSrc = scb_2_interrupt_IRQn,            \
        .uart_config = &CYBSP_DEBUG_UART_config,    \
        .hal_uart_configurator = &CYBSP_DEBUG_UART_hal_config, \
        .userIsr = uart_isr_callback(uart2),        \
        .UART_SCB_IRQ_cfg = &UART2_SCB_IRQ_cfg,     \
    }
#endif
void uart2_isr_callback(void);
#endif /* BSP_USING_UART2 */


/* UART5 */
#if defined(BSP_USING_UART5)
#ifndef UART5_CONFIG
#define UART5_CONFIG                            \
    {                                           \
        .name = "uart5",                        \
        .usart_x = SCB5,                        \
        .intrSrc = scb_5_interrupt_IRQn,        \
        .uart_config = &CYBSP_UART5_config,     \
        .hal_uart_configurator = &CYBSP_UART5_hal_config, \
        .userIsr = uart_isr_callback(uart5),    \
        .UART_SCB_IRQ_cfg = &UART5_SCB_IRQ_cfg, \
    }
#endif
void uart5_isr_callback(void);
#endif /* BSP_USING_UART5 */


#ifdef __cplusplus
}
#endif

#endif
