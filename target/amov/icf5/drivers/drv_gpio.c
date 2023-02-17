/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#define PIN_PORT(pin) ((uint8_t)(((pin) >> 4) & 0xFu))
#define PIN_NO(pin)   ((uint8_t)((pin)&0xFu))

#define PIN_STPORT(pin) ((uint32_t)(GPIO_BASE + (0x400u * PIN_PORT(pin))))
#define PIN_STPIN(pin)  ((uint16_t)(1u << PIN_NO(pin)))

#if defined(GPIOZ)
    #define __GD32_PORT_MAX 12u
#elif defined(GPIOK)
    #define __GD32_PORT_MAX 11u
#elif defined(GPIOJ)
    #define __GD32_PORT_MAX 10u
#elif defined(GPIOI)
    #define __GD32_PORT_MAX 9u
#elif defined(GPIOH)
    #define __GD32_PORT_MAX 8u
#elif defined(GPIOG)
    #define __GD32_PORT_MAX 7u
#elif defined(GPIOF)
    #define __GD32_PORT_MAX 6u
#elif defined(GPIOE)
    #define __GD32_PORT_MAX 5u
#elif defined(GPIOD)
    #define __GD32_PORT_MAX 4u
#elif defined(GPIOC)
    #define __GD32_PORT_MAX 3u
#elif defined(GPIOB)
    #define __GD32_PORT_MAX 2u
#elif defined(GPIOA)
    #define __GD32_PORT_MAX 1u
#else
    #define __GD32_PORT_MAX 0u
    #error Unsupported GD32 GPIO peripheral.
#endif

#define PIN_STPORT_MAX __GD32_PORT_MAX

static struct pin_device pin_device;

static void gd32_pin_write(pin_dev_t dev, rt_base_t pin, rt_base_t value)
{
    uint32_t gpio_port;
    uint32_t gpio_pin;

    if (PIN_PORT(pin) < PIN_STPORT_MAX) {
        gpio_port = PIN_STPORT(pin);
        gpio_pin = PIN_STPIN(pin);

        if (value == 0) {
            gpio_bit_reset(gpio_port, gpio_pin);
        } else {
            gpio_bit_set(gpio_port, gpio_pin);
        }
    }
}

static int gd32_pin_read(pin_dev_t dev, rt_base_t pin)
{
    uint32_t gpio_port;
    uint32_t gpio_pin;
    int value = PIN_LOW;

    if (PIN_PORT(pin) < PIN_STPORT_MAX) {
        gpio_port = PIN_STPORT(pin);
        gpio_pin = PIN_STPIN(pin);

        value = gpio_input_bit_get(gpio_port, gpio_pin);
    }

    return value;
}

static void gd32_pin_mode(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype)
{
    uint32_t gpio_port = PIN_STPORT(pin);
    uint32_t gpio_pin = PIN_STPIN(pin);

    if (PIN_PORT(pin) >= PIN_STPORT_MAX) {
        return;
    }

    if (otype == PIN_OUT_TYPE_PP) {
        gpio_output_options_set(gpio_port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
    } else if (otype == PIN_OUT_TYPE_OD) {
        gpio_output_options_set(gpio_port, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
    }

    if (mode == PIN_MODE_OUTPUT) {
        /* output setting: not pull */
        gpio_mode_set(gpio_port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, gpio_pin);
    } else if (mode == PIN_MODE_INPUT) {
        /* input setting: not pull. */
        gpio_mode_set(gpio_port, GPIO_MODE_INPUT, GPIO_PUPD_NONE, gpio_pin);
    } else if (mode == PIN_MODE_INPUT_PULLUP) {
        /* output setting: pull up. */
        gpio_mode_set(gpio_port, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, gpio_pin);
    } else if (mode == PIN_MODE_INPUT_PULLDOWN) {
        /* output setting: pull down. */
        gpio_mode_set(gpio_port, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, gpio_pin);
    } else {
        /* unsurpoted mode */
        return;
    }
}

const static struct pin_ops pin_ops = {
    .pin_mode = gd32_pin_mode,
    .pin_write = gd32_pin_write,
    .pin_read = gd32_pin_read,
};

rt_err_t drv_gpio_init(void)
{
    /* GPIO Ports Clock Enable */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);

    pin_device.ops = &pin_ops;

    return hal_pin_register(&pin_device, "pin", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
