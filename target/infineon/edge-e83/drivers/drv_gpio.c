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
#include "drv_gpio.h"
#include "hal/pin/pin.h"

#define CYHAL_GET_PIN(pin)  ((uint8_t)(((uint8_t)pin) & 0x07U))
#define CYHAL_GET_PORT(pin) ((uint8_t)(((uint8_t)pin) >> 3U))
#define INT_PRIORITY        7u
#define PIN_IFXPORT_MAX     22u

static struct pin_device pin_device;

static void ifx_pin_mode(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) >= PIN_IFXPORT_MAX) {
        return;
    }
    switch (mode) {
    case PIN_MODE_OUTPUT:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_HIGHZ, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT_PULLUP:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_PULLUP, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT_PULLDOWN:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_PULLDOWN, 0U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_OUTPUT_OD:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_OD_DRIVESLOW, 0U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;
    }
}

static void ifx_pin_write(pin_dev_t dev, rt_base_t pin, rt_base_t value)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX) {
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        mtb_hal_gpio_write(&mtb_gpio, value);
    } else {
        return;
    }
}

static int ifx_pin_read(pin_dev_t dev, rt_base_t pin)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX) {
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        return mtb_hal_gpio_read(&mtb_gpio);
    } else {
        return -RT_EINVAL;
    }
}

const static struct pin_ops _ifx_pin_ops = {
    ifx_pin_mode,
    ifx_pin_write,
    ifx_pin_read,
};

rt_err_t drv_gpio_init(void)
{
    pin_device.ops = &_ifx_pin_ops;

    return hal_pin_register(&pin_device, "pin", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
