/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2022-07-1      Rbb666            first version
 */

#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

#include <rthw.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "mtb_hal_irq_impl.h"
#include "mtb_hal_gpio.h"

#define GPIO_INTERRUPT_PRIORITY (7u)

#define GET_PIN(PORTx,PIN)      ((((uint8_t)(PORTx)) << 3U) + ((uint8_t)(PIN)))
#define CYHAL_GET_PIN(pin)          ((uint8_t)(((uint8_t)pin) & 0x07U))
/** Macro that, given a gpio, will extract the port number */
#define CYHAL_GET_PORT(pin)         ((uint8_t)(((uint8_t)pin) >> 3U))

struct pin_irq_map
{
    rt_uint16_t port;
#if defined(SOC_SERIES_IFX_XMC)
    rt_uint32_t irqno;
#else
    IRQn_Type irqno;
#endif
};

int rt_hw_pin_init(void);

typedef enum
{
    CYHAL_PORT_0  = 0x00,
    CYHAL_PORT_1  = 0x01,
    CYHAL_PORT_2  = 0x02,
    CYHAL_PORT_3  = 0x03,
    CYHAL_PORT_4  = 0x04,
    CYHAL_PORT_5  = 0x05,
    CYHAL_PORT_6  = 0x06,
    CYHAL_PORT_7  = 0x07,
    CYHAL_PORT_8  = 0x08,
    CYHAL_PORT_9  = 0x09,
    CYHAL_PORT_10 = 0x0A,
    CYHAL_PORT_11 = 0x0B,
    CYHAL_PORT_12 = 0x0C,
    CYHAL_PORT_13 = 0x0D,
    CYHAL_PORT_14 = 0x0E,
    CYHAL_PORT_15 = 0x0F,
    CYHAL_PORT_16 = 0x10,
    CYHAL_PORT_17 = 0x11,
    CYHAL_PORT_18 = 0x12,
    CYHAL_PORT_19 = 0x13,
    CYHAL_PORT_20 = 0x14,
    CYHAL_PORT_21 = 0x15,
    CYHAL_PORT_22 = 0x16,
    CYHAL_PORT_23 = 0x17,
    CYHAL_PORT_24 = 0x18,
    CYHAL_PORT_25 = 0x19,
    CYHAL_PORT_26 = 0x1A,
    CYHAL_PORT_27 = 0x1B,
    CYHAL_PORT_28 = 0x1C,
    CYHAL_PORT_29 = 0x1D,
    CYHAL_PORT_30 = 0x1E,
    CYHAL_PORT_31 = 0x1F,
    CYHAL_PORT_32 = 0x20,
    CYHAL_PORT_33 = 0x21,
    CYHAL_PORT_34 = 0x22,
} cyhal_port_t;

#endif /* __DRV_GPIO_H__ */
