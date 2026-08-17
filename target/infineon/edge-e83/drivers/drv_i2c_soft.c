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
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/pin/pin.h"

#ifndef BSP_SOFT_I2C1_SCL_PIN
    #define BSP_SOFT_I2C1_SCL_PIN 24
#endif

#ifndef BSP_SOFT_I2C1_SDA_PIN
    #define BSP_SOFT_I2C1_SDA_PIN 25
#endif

#define I2C_DELAY_US      10
#define I2C_TIMEOUT_TICKS TICKS_FROM_MS(1)

static struct rt_i2c_bus soft_i2c1_bus;
static rt_device_t pin_dev;

static void soft_i2c_pin_mode(rt_uint16_t pin, rt_uint16_t mode)
{
    struct device_pin_mode pin_mode = {
        .pin = pin,
        .mode = mode,
        .otype = PIN_OUT_TYPE_OD,
    };

    rt_device_control(pin_dev, RT_DEVICE_CTRL_CONFIG, &pin_mode);
}

static void soft_i2c_pin_write(rt_uint16_t pin, rt_uint16_t value)
{
    struct device_pin_status pin_status = {
        .pin = pin,
        .status = value,
    };

    rt_device_write(pin_dev, 0, &pin_status, sizeof(pin_status));
}

static rt_int32_t soft_i2c_pin_read(rt_uint16_t pin)
{
    struct device_pin_status pin_status = {
        .pin = pin,
        .status = PIN_LOW,
    };

    if (rt_device_read(pin_dev, 0, &pin_status, sizeof(pin_status)) != sizeof(pin_status)) {
        return 0;
    }

    return pin_status.status;
}

static void soft_i2c_set_sda(void* data, rt_int32_t state)
{
    soft_i2c_pin_write(BSP_SOFT_I2C1_SDA_PIN, state ? PIN_HIGH : PIN_LOW);
}

static void soft_i2c_set_scl(void* data, rt_int32_t state)
{
    soft_i2c_pin_write(BSP_SOFT_I2C1_SCL_PIN, state ? PIN_HIGH : PIN_LOW);
}

static rt_int32_t soft_i2c_get_sda(void* data)
{
    return soft_i2c_pin_read(BSP_SOFT_I2C1_SDA_PIN);
}

static rt_int32_t soft_i2c_get_scl(void* data)
{
    return soft_i2c_pin_read(BSP_SOFT_I2C1_SCL_PIN);
}

static void soft_i2c_udelay(rt_uint32_t us)
{
    systime_udelay(us);
}

static rt_err_t soft_i2c_pin_init(void)
{
    pin_dev = rt_device_find("pin");
    if (pin_dev == RT_NULL) {
        return -RT_ENOSYS;
    }

    soft_i2c_pin_mode(BSP_SOFT_I2C1_SCL_PIN, PIN_MODE_OUTPUT_OD);
    soft_i2c_pin_mode(BSP_SOFT_I2C1_SDA_PIN, PIN_MODE_OUTPUT_OD);
    soft_i2c_pin_write(BSP_SOFT_I2C1_SCL_PIN, PIN_HIGH);
    soft_i2c_pin_write(BSP_SOFT_I2C1_SDA_PIN, PIN_HIGH);

    return RT_EOK;
}

static struct rt_i2c_bit_ops soft_i2c1_bit_ops = {
    .data = &soft_i2c1_bus,
    .set_sda = soft_i2c_set_sda,
    .set_scl = soft_i2c_set_scl,
    .get_sda = soft_i2c_get_sda,
    .get_scl = soft_i2c_get_scl,
    .udelay = soft_i2c_udelay,
    .delay_us = I2C_DELAY_US,
    .timeout = I2C_TIMEOUT_TICKS,
};

static struct rt_i2c_device i2c1_dev0 = { .slave_addr = 0x45, .flags = 0 }; // INA228

rt_err_t drv_i2c_soft_init(void)
{
    RT_TRY(soft_i2c_pin_init());

    soft_i2c1_bus.priv = &soft_i2c1_bit_ops;
    soft_i2c1_bus.retries = 3;

    RT_TRY(rt_i2c_soft_bus_register(&soft_i2c1_bus, "i2c1"));

    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c1_dev0, "i2c1_dev0", "i2c1", RT_NULL));

    return RT_EOK;
}
