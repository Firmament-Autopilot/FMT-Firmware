/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#include "drv_gpio.h"
#include "hal/pin/pin.h"
#include "ar1002_hal.h"

static struct pin_device pin_device;

static void ar1002_pin_write(pin_dev_t dev, rt_base_t pin, rt_base_t value)
{
    if (value == PIN_LOW) {
        HAL_GPIO_SetPin(pin, HAL_GPIO_PIN_RESET);
    } else {
        HAL_GPIO_SetPin(pin, HAL_GPIO_PIN_SET);
    }
}

static int ar1002_pin_read(pin_dev_t dev, rt_base_t pin)
{
    int value = PIN_LOW;

    HAL_GPIO_GetPin(pin, (uint32_t *)&value);

    return value;
}

static void ar1002_pin_mode(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype)
{
    if (mode == PIN_MODE_OUTPUT) {
        HAL_GPIO_OutPut(pin); 
    } else if (mode == PIN_MODE_INPUT) {
        HAL_GPIO_InPut(pin);
    } else if (mode == PIN_MODE_INPUT_PULLUP) {
        HAL_GPIO_InPut(pin);
    } else if (mode == PIN_MODE_INPUT_PULLDOWN) {
        HAL_GPIO_InPut(pin);
    } else {
        /* unsurpoted mode */
        return;
    }
}

const static struct pin_ops _ar1002_pin_ops = {
    ar1002_pin_mode,
    ar1002_pin_write,
    ar1002_pin_read,
};

rt_err_t drv_gpio_init(void)
{
    pin_device.ops = &_ar1002_pin_ops;

    return hal_pin_register(&pin_device, "pin", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
