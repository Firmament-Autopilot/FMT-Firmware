/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author             Notes
 * 2022-07-29     rtthread qiu      first version
 */

#ifndef __DRV_HWTIMER_H__
#define __DRV_HWTIMER_H__

#include <rtthread.h>

#ifndef TIM_DEV_INFO_CONFIG
#define TIM_DEV_INFO_CONFIG            \
    {                                  \
        .maxfreq = 1000000,            \
        .minfreq = 2000,               \
        .maxcnt = 0xFFFF,              \
        .cntmode = HWTIMER_CNTMODE_UP, \
    }
#endif /* TIM_DEV_INFO_CONFIG */
#ifdef BSP_USING_TIM0
cy_stc_sysint_t TIMER_COINTER0_IRQ_cfg =
{
    .intrSrc = (IRQn_Type)CYBSP_TCPWM_0_GRP_0_COUNTER_0_IRQ,
    .intrPriority = (7u),
};
void timer0_isr_callback(void);
#endif

#ifdef BSP_USING_TIM0
#ifndef TIM0_CONFIG
#define TIM0_CONFIG                                                     \
    {                                                                   \
        .cy_stc_tcpwm_counter_config = &CYBSP_TCPWM_0_GRP_0_COUNTER_0_config,    \
        .base = CYBSP_TCPWM_0_GRP_0_COUNTER_0_HW,                                \
        .intr_cfg = &TIMER_COINTER0_IRQ_cfg,                            \
        .tim_irqn = CYBSP_TCPWM_0_GRP_0_COUNTER_0_IRQ,                           \
        .name = "timer0",                                                \
        .cntNum = CYBSP_TCPWM_0_GRP_0_COUNTER_0_NUM,                             \
        .userIsr = &timer0_isr_callback,                                \
        .source_clock_freq = 100000000,                                \
        .ipBlock = PCLK_TCPWM0_CLOCK_COUNTER_EN2,                                \
        .dividerType = CY_SYSCLK_DIV_16_BIT,                                \
    }
#endif /*TIM0_CONFIG*/
#endif /* BSP_USING_TIM0 */

#ifdef BSP_USING_TIM1
#ifndef TIM1_CONFIG
#define TIM1_CONFIG                            \
    {                                          \
        .tim_irqn = tcpwm_0_interrupts_0_IRQn, \
        .name = "timer1",                       \
    }
#endif /*TIM1_CONFIG*/
#endif /* BSP_USING_TIM1 */



#endif /* __DRV_HWTIMER_H__ */
