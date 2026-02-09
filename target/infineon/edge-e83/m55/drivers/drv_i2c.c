/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-08     Rbb666       first implementation.
 */

#include "drv_i2c.h"
#include "hal/i2c/i2c.h"
#include "cy_scb_i2c.h"
#include "mtb_hal_i2c.h"

#if defined(BSP_USING_HW_I2C0) || defined(BSP_USING_HW_I2C3) || defined(BSP_USING_HW_I2C4) || defined(BSP_USING_HW_I2C6)

extern const cy_stc_scb_i2c_config_t CYBSP_I2C_CONTROLLER_config;
extern const mtb_hal_i2c_configurator_t CYBSP_I2C_CONTROLLER_hal_config;
#define CYBSP_I2C_CONTROLLER_HW SCB0

#ifndef I2C0_CONFIG
#define I2C0_CONFIG                                                     \
    {                                                                   \
        .name = "i2c0",                                                 \
        .base = CYBSP_I2C_CONTROLLER_HW,                              \
        .cy_stc_scb_i2c_config = &CYBSP_I2C_CONTROLLER_config,        \
        .mtb_hal_i2c_configurator = &CYBSP_I2C_CONTROLLER_hal_config, \
    }
#endif 
    
#endif

struct ifx_i2c
{
    mtb_hal_i2c_t *mtb_hal_i2c;
    char *name;
    CySCB_Type *base;
    const cy_stc_scb_i2c_config_t *cy_stc_scb_i2c_config;
    const mtb_hal_i2c_configurator_t *mtb_hal_i2c_configurator;
    cy_stc_scb_i2c_context_t *context;
    struct rt_i2c_bus i2c_bus;
};

static struct ifx_i2c ifx_i2c[] =
{
#ifdef BSP_USING_HW_I2C0
    I2C0_CONFIG,
#endif

#ifdef BSP_USING_HW_I2C3
    I2C3_CONFIG,
#endif

#ifdef BSP_USING_HW_I2C4
    I2C4_CONFIG,
#endif

#ifdef BSP_USING_HW_I2C6
    I2C6_CONFIG,
#endif
};

static struct ifx_i2c i2c_objs[sizeof(ifx_i2c) / sizeof(struct ifx_i2c)] = {0};

static int ifx_i2c_read(struct ifx_i2c *hi2c, rt_uint16_t slave_address, rt_uint8_t *p_buffer, rt_uint16_t data_byte)
{
    if (mtb_hal_i2c_controller_read(hi2c->mtb_hal_i2c, slave_address, p_buffer, data_byte, 10, true) != RT_EOK)
    {
        return -RT_ERROR;
    }

    return 0;
}

static int ifx_i2c_write(struct ifx_i2c *hi2c, uint16_t slave_address, uint8_t *p_buffer, uint16_t data_byte)
{
    if (mtb_hal_i2c_controller_write(hi2c->mtb_hal_i2c, slave_address, p_buffer, data_byte, 10, true) != RT_EOK)
    {
        return -RT_ERROR;
    }

    return 0;
}

static rt_size_t _i2c_xfer(struct rt_i2c_bus *bus,
                           rt_uint16_t slave_addr,
                           struct rt_i2c_msg msgs[],
                           rt_uint32_t num)
{
    struct rt_i2c_msg *msg;
    rt_uint32_t i;
    struct ifx_i2c *i2c_obj;
    rt_uint16_t addr7;

    RT_ASSERT(bus != RT_NULL);
    RT_ASSERT(msgs != RT_NULL);

    i2c_obj = rt_container_of(bus, struct ifx_i2c, i2c_bus);

    addr7 = slave_addr;
    if (addr7 > 0x7F)
    {
        addr7 >>= 1;
    }
    RT_ASSERT(addr7 <= 0x7F);

    for (i = 0; i < num; i++)
    {
        msg = &msgs[i];

        if (msg->flags & RT_I2C_RD)
        {
            if (ifx_i2c_read(i2c_obj, addr7, msg->buf, msg->len) != 0)
            {
                break;
            }
        }
        else
        {
            if (ifx_i2c_write(i2c_obj, addr7, msg->buf, msg->len) != 0)
            {
                break;
            }
        }
    }

    return i;
}


static const struct rt_i2c_bus_device_ops i2c_ops =
{
    _i2c_xfer,
    RT_NULL,
    RT_NULL
};

void HAL_I2C_Init(struct ifx_i2c *obj)
{
    RT_ASSERT(obj != RT_NULL);
    RT_ASSERT(obj->mtb_hal_i2c != RT_NULL);
    RT_ASSERT(obj->mtb_hal_i2c_configurator != RT_NULL);
    RT_ASSERT(obj->context != RT_NULL);

    cy_rslt_t rslt;
    cy_en_scb_i2c_status_t result;

    result = Cy_SCB_I2C_Init(obj->base, obj->cy_stc_scb_i2c_config, obj->context);
    if (result != CY_SCB_I2C_SUCCESS)
    {
        rt_kprintf("Cy_SCB_I2C_Init failed for %s, code: 0x%08x\n", obj->name, result);
        return;
    }

    Cy_SCB_I2C_Enable(obj->base);

    rslt = mtb_hal_i2c_setup(obj->mtb_hal_i2c, obj->mtb_hal_i2c_configurator, obj->context, NULL);
    if (rslt != CY_RSLT_SUCCESS)
    {
        rt_kprintf("I2C setup failed for %s, code: 0x%08x\n", obj->name, rslt);
        return;
    }

    mtb_hal_i2c_cfg_t i2c_controller_config =
    {
        MTB_HAL_I2C_MODE_CONTROLLER,
        0,
        100000,
        MTB_HAL_I2C_DEFAULT_ADDR_MASK,
        false,
    };

    rslt = mtb_hal_i2c_configure(obj->mtb_hal_i2c, &i2c_controller_config);
    if (rslt != CY_RSLT_SUCCESS)
    {
        rt_kprintf("I2C configure failed for %s, code: 0x%08x\n", obj->name, rslt);
        return;
    }
}

rt_err_t drv_i2c_init(void)
{
    rt_err_t result = RT_EOK;
    size_t i2c_num = sizeof(ifx_i2c) / sizeof(struct ifx_i2c);

    for (size_t i = 0; i < i2c_num; i++)
    {
        i2c_objs[i] = ifx_i2c[i];
        i2c_objs[i].i2c_bus.ops = &i2c_ops;
        i2c_objs[i].context = rt_malloc(sizeof(cy_stc_scb_i2c_context_t));
        RT_ASSERT(i2c_objs[i].context != RT_NULL);
        i2c_objs[i].mtb_hal_i2c = rt_malloc(sizeof(mtb_hal_i2c_t));
        RT_ASSERT(i2c_objs[i].mtb_hal_i2c != RT_NULL);
        HAL_I2C_Init(&i2c_objs[i]);
        result = rt_i2c_bus_device_register(&i2c_objs[i].i2c_bus, i2c_objs[i].name);
        RT_ASSERT(result == RT_EOK);
    }

    return RT_EOK;
}

