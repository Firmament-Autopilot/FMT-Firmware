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

#include "drv_i2c.h"
#include "cy_scb_i2c.h"
#include "hal/i2c/i2c.h"
#include "mtb_hal_i2c.h"

/*******************************************************************************
 * I2C peripheral configuration (from cycfg_peripherals)
 ******************************************************************************/
#ifdef BSP_USING_HW_I2C0
extern const cy_stc_scb_i2c_config_t CYBSP_I2C_CONTROLLER_config;
extern const mtb_hal_i2c_configurator_t CYBSP_I2C_CONTROLLER_hal_config;
#endif

#ifdef BSP_USING_HW_I2C8
extern const cy_stc_scb_i2c_config_t scb_8_config;
extern const mtb_hal_i2c_configurator_t scb_8_hal_config;
#endif

/*******************************************************************************
 * I2C bus object definition
 ******************************************************************************/
struct ifx_i2c {
    const char*                          name;
    CySCB_Type*                          base;
    const cy_stc_scb_i2c_config_t*       scb_config;
    const mtb_hal_i2c_configurator_t*    hal_configurator;
    mtb_hal_i2c_t                        hal_obj;
    cy_stc_scb_i2c_context_t             context;
    struct rt_i2c_bus                     i2c_bus;
};

/*******************************************************************************
 * I2C bus instances (statically allocated)
 ******************************************************************************/
static struct ifx_i2c i2c_objs[] = {
#ifdef BSP_USING_HW_I2C0
    {
        .name             = "i2c0",
        .base             = SCB0,
        .scb_config       = &CYBSP_I2C_CONTROLLER_config,
        .hal_configurator = &CYBSP_I2C_CONTROLLER_hal_config,
    },
#endif
#ifdef BSP_USING_HW_I2C3
    {
        .name             = "i2c3",
        .base             = SCB3,
        .scb_config       = NULL,       /* TODO: add I2C3 peripheral config */
        .hal_configurator = NULL,
    },
#endif
#ifdef BSP_USING_HW_I2C4
    {
        .name             = "i2c4",
        .base             = SCB4,
        .scb_config       = NULL,       /* TODO: add I2C4 peripheral config */
        .hal_configurator = NULL,
    },
#endif
#ifdef BSP_USING_HW_I2C6
    {
        .name             = "i2c6",
        .base             = SCB6,
        .scb_config       = NULL,       /* TODO: add I2C6 peripheral config */
        .hal_configurator = NULL,
    },
#endif
#ifdef BSP_USING_HW_I2C8
    {
        .name             = "i2c8",
        .base             = SCB8,
        .scb_config       = &scb_8_config,
        .hal_configurator = &scb_8_hal_config,
    },
#endif
};

#define I2C_BUS_NUM (sizeof(i2c_objs) / sizeof(i2c_objs[0]))

/*******************************************************************************
 * I2C bus operations
 ******************************************************************************/
static int ifx_i2c_read(struct ifx_i2c* hi2c, rt_uint16_t slave_address,
                         rt_uint8_t* p_buffer, rt_uint16_t data_byte)
{
    if (mtb_hal_i2c_controller_read(&hi2c->hal_obj, slave_address,
                                     p_buffer, data_byte, 10, true) != RT_EOK) {
        return -RT_ERROR;
    }
    return 0;
}

static int ifx_i2c_write(struct ifx_i2c* hi2c, uint16_t slave_address,
                          uint8_t* p_buffer, uint16_t data_byte)
{
    if (mtb_hal_i2c_controller_write(&hi2c->hal_obj, slave_address,
                                      p_buffer, data_byte, 10, true) != RT_EOK) {
        return -RT_ERROR;
    }
    return 0;
}

static rt_size_t _i2c_xfer(struct rt_i2c_bus* bus,
                            rt_uint16_t slave_addr,
                            struct rt_i2c_msg msgs[],
                            rt_uint32_t num)
{
    struct rt_i2c_msg* msg;
    rt_uint32_t i;
    struct ifx_i2c* i2c_obj;
    rt_uint16_t addr7;

    RT_ASSERT(bus != RT_NULL);
    RT_ASSERT(msgs != RT_NULL);

    i2c_obj = rt_container_of(bus, struct ifx_i2c, i2c_bus);

    addr7 = slave_addr >> 1;
    RT_ASSERT(addr7 <= 0x7F);

    for (i = 0; i < num; i++) {
        msg = &msgs[i];

        if (msg->flags & RT_I2C_RD) {
            if (ifx_i2c_read(i2c_obj, addr7, msg->buf, msg->len) != 0) {
                break;
            }
        } else {
            if (ifx_i2c_write(i2c_obj, addr7, msg->buf, msg->len) != 0) {
                break;
            }
        }
    }

    return i;
}

static const struct rt_i2c_bus_device_ops i2c_ops = {
    _i2c_xfer,
    RT_NULL,
    RT_NULL
};

/*******************************************************************************
 * I2C hardware initialization
 ******************************************************************************/
static void ifx_i2c_hw_init(struct ifx_i2c* obj)
{
    cy_rslt_t rslt;
    cy_en_scb_i2c_status_t status;

    RT_ASSERT(obj != RT_NULL);
    RT_ASSERT(obj->hal_configurator != RT_NULL);
    RT_ASSERT(obj->scb_config != RT_NULL);

    /* Initialize SCB block as I2C */
    status = Cy_SCB_I2C_Init(obj->base, obj->scb_config, &obj->context);
    if (status != CY_SCB_I2C_SUCCESS) {
        rt_kprintf("Cy_SCB_I2C_Init failed for %s, code: 0x%08x\n", obj->name, status);
        return;
    }

    Cy_SCB_I2C_Enable(obj->base);

    /* Setup HAL layer */
    rslt = mtb_hal_i2c_setup(&obj->hal_obj, obj->hal_configurator, &obj->context, NULL);
    if (rslt != CY_RSLT_SUCCESS) {
        rt_kprintf("I2C setup failed for %s, code: 0x%08x\n", obj->name, rslt);
        return;
    }

    /* Configure as controller at 100 kHz */
    mtb_hal_i2c_cfg_t cfg = {
        .is_target               = MTB_HAL_I2C_MODE_CONTROLLER,
        .address                 = 0,
        .frequency_hz            = 100000,
        .address_mask            = MTB_HAL_I2C_DEFAULT_ADDR_MASK,
        .enable_address_callback = false,
    };

    rslt = mtb_hal_i2c_configure(&obj->hal_obj, &cfg);
    if (rslt != CY_RSLT_SUCCESS) {
        rt_kprintf("I2C configure failed for %s, code: 0x%08x\n", obj->name, rslt);
        return;
    }
}

/*******************************************************************************
 * I2C slave device instances
 ******************************************************************************/
#ifdef BSP_USING_HW_I2C0
 static struct rt_i2c_device i2c0_dev1 = { .slave_addr = 0x77, .flags = 0 };
#endif
#ifdef BSP_USING_HW_I2C8
static struct rt_i2c_device i2c8_dev1 = { .slave_addr = 0x77, .flags = 0 };
#endif
/*******************************************************************************
 * Driver entry
 ******************************************************************************/
rt_err_t drv_i2c_init(void)
{
    for (size_t i = 0; i < I2C_BUS_NUM; i++) {
        i2c_objs[i].i2c_bus.ops = &i2c_ops;

        ifx_i2c_hw_init(&i2c_objs[i]);

        rt_err_t ret = rt_i2c_bus_device_register(&i2c_objs[i].i2c_bus, i2c_objs[i].name);
        RT_ASSERT(ret == RT_EOK);
    }
#ifdef BSP_USING_HW_I2C0
    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c0_dev1, "i2c0_dev1", "i2c0", RT_NULL));
#endif
#ifdef BSP_USING_HW_I2C8
    RT_TRY(rt_i2c_bus_attach_device(&i2c8_dev1, "i2c8_dev1", "i2c8", RT_NULL));
#endif
    return RT_EOK;
}
