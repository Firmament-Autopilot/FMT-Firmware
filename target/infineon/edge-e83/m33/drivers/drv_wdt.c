/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2022-07-21     Rbb666            first version
 */

#include "drv_wdt.h"

#ifdef RT_USING_WDT

/* PILO frequency in Hz */
#define PILO_FREQ_HZ (32768u)

/* Number if bits used for comparison */
#define NUM_MATCH_BITS (14u)

// #define DRV_DEBUG
#define LOG_TAG "drv.wdt"
#include <drv_log.h>

static struct ifx_wdt_cfg wdt_cfg =
{
    .name = "wdt"
};

static struct ifx_wdt wdt_drv;

static rt_err_t wdt_init(rt_watchdog_t *wdt)
{
    Cy_WDT_Init();
    return RT_EOK;
}

static rt_err_t wdt_control(rt_watchdog_t *wdt_device, int cmd, void *arg)
{
    RT_ASSERT(wdt_device != RT_NULL);

    rt_uint32_t timeout_ms = 0;

    switch (cmd)
    {
    /* feed the watchdog */
    case RT_DEVICE_CTRL_WDT_KEEPALIVE:
        Cy_WDT_Unlock();
        Cy_WDT_ClearWatchdog();
        Cy_WDT_Lock();
        break;

    /* set watchdog timeout */
    case RT_DEVICE_CTRL_WDT_SET_TIMEOUT:

        timeout_ms = *((rt_uint32_t *)arg) * 1000;

        /* Step 1- Unlock WDT */
        Cy_WDT_Unlock();

        /* Step 2- Write the number of bit used for compare -
        (operate with only 14 bits) */
        Cy_WDT_SetMatchBits(NUM_MATCH_BITS);

        /* Step 3- Write match value */
        Cy_WDT_SetMatch(((timeout_ms / 1000) * PILO_FREQ_HZ));

        /* Step 4- Clear match event interrupt, if any */
        Cy_WDT_ClearInterrupt();

        /* Step 5- Enable WDT */
        Cy_WDT_Enable();

        /* Step 6- Lock WDT configuration */
        Cy_WDT_Lock();
        break;

    case RT_DEVICE_CTRL_WDT_GET_TIMEOUT:
        break;

    case RT_DEVICE_CTRL_WDT_START:
        Cy_WDT_Unlock();
        Cy_WDT_Enable();
        Cy_WDT_Lock();
        break;

    case RT_DEVICE_CTRL_WDT_STOP:
        Cy_WDT_Unlock();
        Cy_WDT_Disable();
        break;

    default:
        LOG_W("This command is not supported.");
        return -RT_ERROR;
    }

    return RT_EOK;
}

const static struct rt_watchdog_ops ifx_wdt_ops =
{
    wdt_init,
    wdt_control
};

int rt_hw_wdt_init(void)
{
    wdt_drv.cfg = &wdt_cfg;
    wdt_drv.wdt_device.ops = &ifx_wdt_ops;

    if (rt_hw_watchdog_register(&wdt_drv.wdt_device, wdt_drv.cfg->name, RT_DEVICE_FLAG_RDWR, wdt_drv.cfg) != RT_EOK)
    {
        LOG_E("wdt device register failed.");
        return -RT_ERROR;
    }

    LOG_D("wdt device register success.");
    return RT_EOK;
}
INIT_BOARD_EXPORT(rt_hw_wdt_init);

#endif /* RT_USING_WDT */
