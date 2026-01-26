/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-13     Rbb666       first version
 */
#include "drv_pwm.h"

#ifdef RT_USING_PWM
#include <rtdevice.h>
#include "drv_gpio.h"
#include "cy_sysclk.h"
#include "cy_tcpwm.h"
//#define DRV_DEBUG
#define LOG_TAG "drv.pwm"
#include <drv_log.h>

struct ifx_pwm
{
    struct rt_device_pwm pwm_device;
    const cy_stc_tcpwm_pwm_config_t *tcpwm_pwm_config;
    TCPWM_Type *base;
    uint32_t cntNum;
    rt_uint8_t channel;
    const char *name;
    uint32_t clk_dst;
    cy_en_divider_types_t clk_divType;
    uint32_t clk_divNum;
};

static struct ifx_pwm ifx_pwm_obj[] =
{
#ifdef BSP_USING_PWM18
    #ifdef TCPWM_0_GRP_1_PWM_9_CONFIG
        TCPWM_0_GRP_1_PWM_9_CONFIG,
    #endif
#endif
};


#ifndef IFX_PWM_MAX_TICKS
#define IFX_PWM_MAX_TICKS 65535U
#endif

static inline uint32_t ifx_pwm_get_clock(struct ifx_pwm *pwm)
{
    return Cy_SysClk_PeriPclkGetFrequency((en_clk_dst_t)pwm->clk_dst,
                                          pwm->clk_divType,
                                          pwm->clk_divNum);
}

static inline int ifx_pwm_check_clk(struct ifx_pwm *pwm, uint32_t *clk)
{
    *clk = ifx_pwm_get_clock(pwm);
    if (*clk == 0U)
    {
        LOG_E("%s: invalid clk (0 Hz)", pwm->name ? pwm->name : "ifx_pwm");
        return -RT_ERROR;
    }
    return RT_EOK;
}

static inline uint64_t ns_to_ticks(uint64_t ns, uint32_t clk)
{
    if (clk == 0U)
        return 0ULL;

    uint64_t ticks = (ns * (uint64_t)clk) / 1000000000ULL;

    if (ticks > IFX_PWM_MAX_TICKS)
        ticks = IFX_PWM_MAX_TICKS;

    return ticks;
}

static rt_err_t drv_pwm_enable(struct rt_device_pwm *device, struct rt_pwm_configuration *configuration, rt_bool_t enable)
{
    struct ifx_pwm *pwm = (struct ifx_pwm *)device->parent.user_data;

    (void)configuration;

    if (!pwm || pwm->base == RT_NULL)
        return -RT_ERROR;

    if (!enable)
    {
        Cy_TCPWM_PWM_Disable(pwm->base, pwm->cntNum);
    }
    else
    {
        Cy_TCPWM_PWM_Enable(pwm->base, pwm->cntNum);
        Cy_TCPWM_TriggerStart_Single(pwm->base, pwm->cntNum);
    }

    return RT_EOK;
}

static rt_err_t drv_pwm_set_period(struct ifx_pwm *pwm, struct rt_pwm_configuration *configuration)
{
    uint32_t clk;

    if (ifx_pwm_check_clk(pwm, &clk) != RT_EOK)
        return -RT_ERROR;

    uint64_t period_ns = configuration->period;
    uint64_t ticks = ns_to_ticks(period_ns, clk);

    if (period_ns > 0 && ticks == 0)
        ticks = 1;

    if (ticks == 0)
    {
        LOG_E("%s: requested period is 0 ns", pwm->name ? pwm->name : "ifx_pwm");
        return -RT_EINVAL;
    }

    if (ticks > IFX_PWM_MAX_TICKS)
        ticks = IFX_PWM_MAX_TICKS;

    Cy_TCPWM_PWM_SetPeriod0(pwm->base, pwm->cntNum, (uint32_t)ticks);

    return RT_EOK;
}

static rt_err_t drv_pwm_set_pulse(struct ifx_pwm *pwm, struct rt_pwm_configuration *configuration)
{
    uint32_t clk;

    if (ifx_pwm_check_clk(pwm, &clk) != RT_EOK)
        return -RT_ERROR;

    uint64_t pulse_ns = configuration->pulse;
    uint64_t ticks = ns_to_ticks(pulse_ns, clk);

    uint32_t period_ticks = Cy_TCPWM_PWM_GetPeriod0(pwm->base, pwm->cntNum);

    if (period_ticks == 0)
    {
        LOG_W("%s: period not configured, setting pulse to 0", pwm->name ? pwm->name : "ifx_pwm");
        ticks = 0;
    }
    else
    {
        if (ticks > period_ticks)
            ticks = period_ticks;
    }

    Cy_TCPWM_PWM_SetCompare0Val(pwm->base, pwm->cntNum, (uint32_t)ticks);

    return RT_EOK;
}

static rt_err_t drv_pwm_set(struct rt_device_pwm *device, struct rt_pwm_configuration *configuration)
{
    struct ifx_pwm *pwm = (struct ifx_pwm *)device->parent.user_data;
    uint32_t clk;

    if (ifx_pwm_check_clk(pwm, &clk) != RT_EOK)
        return -RT_ERROR;

    uint64_t period_ticks = ns_to_ticks(configuration->period, clk);
    uint64_t pulse_ticks  = ns_to_ticks(configuration->pulse, clk);

    if (configuration->period > 0 && period_ticks == 0)
        period_ticks = 1;

    if (period_ticks == 0)
    {
        LOG_E("%s: requested period is 0 ns", pwm->name ? pwm->name : "ifx_pwm");
        return -RT_EINVAL;
    }

    if (pulse_ticks > period_ticks)
        pulse_ticks = period_ticks;

    if (period_ticks > IFX_PWM_MAX_TICKS)
        period_ticks = IFX_PWM_MAX_TICKS;

    Cy_TCPWM_PWM_SetPeriod0(pwm->base, pwm->cntNum, (uint32_t)period_ticks);
    Cy_TCPWM_PWM_SetCompare0Val(pwm->base, pwm->cntNum, (uint32_t)pulse_ticks);

    return RT_EOK;
}

static rt_err_t drv_pwm_get(struct rt_device_pwm *device, struct rt_pwm_configuration *configuration)
{
    struct ifx_pwm *pwm = (struct ifx_pwm *)device->parent.user_data;
    uint32_t clk;

    if (ifx_pwm_check_clk(pwm, &clk) != RT_EOK)
        return -RT_ERROR;

    uint32_t period_ticks = Cy_TCPWM_PWM_GetPeriod0(pwm->base, pwm->cntNum);
    uint32_t cmp_ticks    = Cy_TCPWM_PWM_GetCompare0Val(pwm->base, pwm->cntNum);

    configuration->period = (uint64_t)period_ticks * 1000000000ULL / (uint64_t)clk;
    configuration->pulse  = (uint64_t)cmp_ticks * 1000000000ULL / (uint64_t)clk;

    return RT_EOK;
}

static rt_err_t drv_pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    struct rt_pwm_configuration *configuration = (struct rt_pwm_configuration *)arg;

    switch (cmd)
    {
    case PWM_CMD_ENABLE:
        return drv_pwm_enable(device, configuration, RT_TRUE);

    case PWM_CMD_DISABLE:
        return drv_pwm_enable(device, configuration, RT_FALSE);

    case PWM_CMD_SET:
        return drv_pwm_set(device, configuration);

    case PWM_CMD_GET:
        return drv_pwm_get(device, configuration);

    case PWM_CMD_SET_PERIOD:
        return drv_pwm_set_period((struct ifx_pwm *)device->parent.user_data, configuration);

    case PWM_CMD_SET_PULSE:
        return drv_pwm_set_pulse((struct ifx_pwm *)device->parent.user_data, configuration);

    default:
        return -RT_EINVAL;
    }
}

static struct rt_pwm_ops drv_ops = { drv_pwm_control };

static rt_err_t ifx_hw_pwm_init(struct ifx_pwm *device)
{
    cy_en_tcpwm_status_t tcpwm_status;
    RT_ASSERT(device != RT_NULL);

    if (!device->tcpwm_pwm_config || !device->base)
    {
        LOG_W("%s: tcpwm config or base missing", device->name ? device->name : "ifx_pwm");
        return -RT_ERROR;
    }

    tcpwm_status = Cy_TCPWM_PWM_Init(device->base, device->cntNum, device->tcpwm_pwm_config);
    if (CY_RSLT_SUCCESS != tcpwm_status)
    {
        LOG_E("%s: Initialize the TCPWM block failed", device->name ? device->name : "ifx_pwm");
        return -RT_ERROR;
    }

    return RT_EOK;
}

static int rt_hw_pwm_init(void)
{
    int i;
    int result = RT_EOK;
    int count = sizeof(ifx_pwm_obj) / sizeof(ifx_pwm_obj[0]);

    if (count == 0)
    {
        LOG_W("No PWM instances configured");
        return RT_EOK;
    }

    for (i = 0; i < count; i++)
    {
        struct ifx_pwm *obj = &ifx_pwm_obj[i];

        if (obj->tcpwm_pwm_config == RT_NULL || obj->base == RT_NULL)
        {
            LOG_W("pwm obj %d not configured (skipped)", i);
            continue;
        }

        if (ifx_hw_pwm_init(obj) != RT_EOK)
        {
            LOG_E("%s init failed", obj->name ? obj->name : "ifx_pwm");
            result = -RT_ERROR;
            goto __exit;
        }

        obj->pwm_device.parent.user_data = obj;

        if (rt_device_pwm_register(&obj->pwm_device, obj->name, &drv_ops, obj) == RT_EOK)
        {
            LOG_D("%s register success", obj->name ? obj->name : "ifx_pwm");
        }
        else
        {
            LOG_E("%s register failed", obj->name ? obj->name : "ifx_pwm");
            result = -RT_ERROR;
        }
    }

__exit:
    return result;
}
INIT_BOARD_EXPORT(rt_hw_pwm_init);

#endif /* RT_USING_PWM */
