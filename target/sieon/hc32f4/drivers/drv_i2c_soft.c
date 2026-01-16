/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>

#include "drv_i2c_soft.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"

#define BSP_I2C0_SCL_PORT GPIO_PORT_B
#define BSP_I2C0_SDA_PORT GPIO_PORT_B

#define BSP_I2C0_SCL_PIN  GPIO_PIN_08
#define BSP_I2C0_SDA_PIN  GPIO_PIN_09

#define I2C_DELAY_US      (10)
#define I2C_TIMEOUT_TICKS TICKS_FROM_MS(1)

static struct rt_i2c_bus i2c0_dev;

void gd32_set_sda(void* data, rt_int32_t state)
{
    struct rt_i2c_bus* i2c_bus = (struct rt_i2c_bus*)data;

    if (i2c_bus == &i2c0_dev) {
        if (state == 1)
            // gpio_bit_set(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);
            GPIO_SetPins(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);
        else if (state == 0)
            // gpio_bit_reset(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);
            GPIO_ResetPins(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);
    }
}

void gd32_set_scl(void* data, rt_int32_t state)
{
    struct rt_i2c_bus* i2c_bus = (struct rt_i2c_bus*)data;

    if (i2c_bus == &i2c0_dev) {
        if (state == 1)
            GPIO_SetPins(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN);
        else if (state == 0)
            GPIO_ResetPins(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN);
    }
}

rt_int32_t gd32_get_sda(void* data)
{
    rt_int32_t val;
    struct rt_i2c_bus* i2c_bus = (struct rt_i2c_bus*)data;

    if (i2c_bus == &i2c0_dev) {
        // gpio_mode_set(BSP_I2C0_SDA_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_I2C0_SDA_PIN);
        // val = (rt_int32_t)gpio_input_bit_get(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);
        // gpio_mode_set(BSP_I2C0_SDA_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_I2C0_SDA_PIN);

        stc_gpio_init_t stcGpioInit;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PullUp = PIN_PU_ON;
        stcGpioInit.u16PinDir = PIN_DIR_IN;
        (void)GPIO_Init(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN, &stcGpioInit);

        val = (rt_int32_t)GPIO_ReadInputPins(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN);

        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        (void)GPIO_Init(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN, &stcGpioInit);
    }

    return val;
}

rt_int32_t gd32_get_scl(void* data)
{
    rt_int32_t val;
    struct rt_i2c_bus* i2c_bus = (struct rt_i2c_bus*)data;

    if (i2c_bus == &i2c0_dev) {
        // gpio_mode_set(BSP_I2C0_SCL_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_I2C0_SCL_PIN);
        // val = (rt_int32_t)gpio_input_bit_get(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN);
        // gpio_mode_set(BSP_I2C0_SCL_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_I2C0_SCL_PIN);

        stc_gpio_init_t stcGpioInit;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PullUp = PIN_PU_ON;
        stcGpioInit.u16PinDir = PIN_DIR_IN;
        (void)GPIO_Init(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN, &stcGpioInit);

        val = (rt_int32_t)GPIO_ReadInputPins(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN);

        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        (void)GPIO_Init(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN, &stcGpioInit);
    }

    return val;
}

rt_inline void gd32_udelay(rt_uint32_t us)
{
    systime_udelay(us);
}

static rt_err_t gd32_i2c_pin_init(struct rt_i2c_bus* i2c_bus)
{
    if (i2c_bus == &i2c0_dev) {
        // gpio_output_options_set(BSP_I2C0_SCL_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, BSP_I2C0_SCL_PIN);
        // gpio_mode_set(BSP_I2C0_SCL_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_I2C0_SCL_PIN);

        // gpio_output_options_set(BSP_I2C0_SDA_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, BSP_I2C0_SDA_PIN);
        // gpio_mode_set(BSP_I2C0_SDA_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_I2C0_SDA_PIN);

        stc_gpio_init_t stcGpioInit;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PullUp = PIN_PU_ON;
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        (void)GPIO_Init(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN, &stcGpioInit);
        (void)GPIO_Init(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN, &stcGpioInit);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

struct rt_i2c_bit_ops gd32_i2c0_bit_ops = {
    (void*)NULL,
    gd32_set_sda,
    gd32_set_scl,
    gd32_get_sda,
    gd32_get_scl,
    gd32_udelay,
    I2C_DELAY_US,
    I2C_TIMEOUT_TICKS
};

/* i2c device instances */
static struct rt_i2c_device i2c0_dev0 = {
    .slave_addr = 0x2C, /* AW2023 7 bit address */
    .flags = 0
};

rt_err_t drv_i2c_soft_init(void)
{
    gd32_i2c0_bit_ops.data = &i2c0_dev;
    i2c0_dev.priv = (void*)&gd32_i2c0_bit_ops;
    i2c0_dev.retries = 3;

    gd32_i2c_pin_init(&i2c0_dev);
    rt_i2c_soft_bus_register(&i2c0_dev, "i2c0");

    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c0_dev0, "i2c0_dev0", "i2c0", RT_NULL));

    return RT_EOK;
}
