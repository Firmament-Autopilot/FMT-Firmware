/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author                   Notes
 * 2022-07-29     rtthread qiu       first version
 */
#include "drv_common.h"
#include "drv_hwtimer.h"
#include <board.h>
#ifdef BSP_USING_TIM

// #define DRV_DEBUG
#define LOG_TAG "drv.hwtimer"
#include <drv_log.h>

#ifdef RT_USING_HWTIMER
enum
{
#ifdef BSP_USING_TIM0
    TIM0_INDEX,
#endif
#ifdef BSP_USING_TIM2
    TIM2_INDEX,
#endif
};

struct cyp_hwtimer
{
    rt_hwtimer_t time_device;
    TCPWM_Type *base;
    uint32_t cntNum;
    const cy_stc_tcpwm_counter_config_t *cy_stc_tcpwm_counter_config;
    cy_israddress userIsr;
    cy_stc_sysint_t *intr_cfg;
    IRQn_Type tim_irqn;
    en_clk_dst_t ipBlock;
    uint32_t source_clock_freq;
    cy_en_divider_types_t dividerType;
    char *name;
};
static struct cyp_hwtimer cyp_hwtimer_obj[] =
{
#ifdef BSP_USING_TIM0
    TIM0_CONFIG,
#endif
#ifdef BSP_USING_TIM1
    TIM1_CONFIG,
#endif
};

#ifdef BSP_USING_TIM0
void timer0_isr_callback(void)
{
    uint32_t interrupts = Cy_TCPWM_GetInterruptStatusMasked(CYBSP_TCPWM_0_GRP_0_COUNTER_0_HW,
                          0);
    Cy_TCPWM_ClearInterrupt(CYBSP_TCPWM_0_GRP_0_COUNTER_0_HW,
                            0, interrupts);
    rt_device_hwtimer_isr(&cyp_hwtimer_obj[TIM0_INDEX].time_device);
}
#endif

int timer_set_frequency(struct cyp_hwtimer *tim, uint32_t freq)
{
    uint32_t dividerValue = (tim->source_clock_freq / freq) - 1;

    Cy_SysClk_PeriPclkDisableDivider(tim->ipBlock, tim->dividerType, tim->cntNum);

    Cy_SysClk_PeriPclkSetDivider(tim->ipBlock, tim->dividerType, tim->cntNum, dividerValue);

    Cy_SysClk_PeriPclkEnableDivider(tim->ipBlock, tim->dividerType, tim->cntNum);

    return 0;
}

static void timer_init(rt_hwtimer_t *timer, rt_uint32_t state)
{
    RT_ASSERT(timer != RT_NULL);

    struct cyp_hwtimer *tim = (struct cyp_hwtimer *)timer->parent.user_data;
    /* Initialze TCPWM block with required timer configuration */
    if (CY_TCPWM_SUCCESS != Cy_TCPWM_Counter_Init(tim->base, tim->cntNum, tim->cy_stc_tcpwm_counter_config))
    {
        CY_ASSERT(0);
    }
    /* Set the interrupt line for COUNTER_HW */
    if (CY_SYSINT_SUCCESS != Cy_SysInt_Init(tim->intr_cfg, tim->userIsr))
    {
        CY_ASSERT(0);
    }
    /* Enable system Interrupt */
    NVIC_EnableIRQ(tim->tim_irqn);
}

static rt_err_t timer_start(rt_hwtimer_t *timer, rt_uint32_t t, rt_hwtimer_mode_t opmode)
{
    RT_ASSERT(timer != RT_NULL);
    struct cyp_hwtimer *tim = (struct cyp_hwtimer *)timer->parent.user_data;

    Cy_TCPWM_Counter_SetCounter(tim->base, tim->cntNum, 0);

    Cy_TCPWM_Counter_SetPeriod(tim->base, tim->cntNum, t - 1);

    Cy_TCPWM_Counter_Enable(tim->base, tim->cntNum);

    Cy_TCPWM_TriggerStart_Single(tim->base, tim->cntNum);

    return RT_EOK;
}

static void timer_stop(rt_hwtimer_t *timer)
{
    RT_ASSERT(timer != RT_NULL);
    struct cyp_hwtimer *tim = (struct cyp_hwtimer *)timer->parent.user_data;
    Cy_TCPWM_TriggerStopOrKill_Single(tim->base, tim->cntNum);
    Cy_TCPWM_Counter_SetCounter(tim->base, tim->cntNum, 0);
}

static rt_uint32_t timer_counter_get(rt_hwtimer_t *timer)
{
    rt_uint32_t count;
    struct cyp_hwtimer *tim = (struct cyp_hwtimer *)timer->parent.user_data;
    count = Cy_TCPWM_Counter_GetCounter(tim->base, tim->cntNum);
    return count;
}

static rt_err_t timer_ctrl(rt_hwtimer_t *timer, rt_uint32_t cmd, void *arg)
{
    RT_ASSERT(timer != RT_NULL);
    RT_ASSERT(arg != RT_NULL);

    struct cyp_hwtimer *tim = (struct cyp_hwtimer *)timer->parent.user_data;

    rt_err_t result = -RT_ERROR;

    switch (cmd)
    {
    case HWTIMER_CTRL_FREQ_SET:
    {
        rt_uint32_t freq;
        freq = *((rt_uint32_t *)arg);
        result = timer_set_frequency(tim, freq);
        result = CY_RSLT_SUCCESS;
        if (result != CY_RSLT_SUCCESS)
        {
            LOG_E("cyhal_timer_set_frequency error\r\n");
            return -RT_ERROR;
        }
    }
    break;
    default:
    {
        result = -RT_EINVAL;
    }
    break;
    }
    return result;
}

static const struct rt_hwtimer_info _info = TIM_DEV_INFO_CONFIG;

static const struct rt_hwtimer_ops _ops =
{
    .init = timer_init,
    .start = timer_start,
    .stop = timer_stop,
    .count_get = timer_counter_get,
    .control = timer_ctrl,
};

int cyp_hwtimer_init(void)
{
    int i = 0;
    int result = RT_EOK;

    for (i = 0; i < sizeof(cyp_hwtimer_obj) / sizeof(struct cyp_hwtimer); i++)
    {
        cyp_hwtimer_obj[i].time_device.info = &_info;
        cyp_hwtimer_obj[i].time_device.ops = &_ops;
        if (rt_device_hwtimer_register(&cyp_hwtimer_obj[i].time_device, cyp_hwtimer_obj[i].name, &cyp_hwtimer_obj[i]) != RT_EOK)
        {
            LOG_E("%s register failed", cyp_hwtimer_obj[i].name);
            result = -RT_ERROR;
        }
    }
    return result;
}
INIT_BOARD_EXPORT(cyp_hwtimer_init);

#endif /*RT_USING_HWTIMER*/
#endif /*BSP_USING_TIM*/
