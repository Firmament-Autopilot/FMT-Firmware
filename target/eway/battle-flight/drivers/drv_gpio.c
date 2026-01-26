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

#define PIN_NUM(port, no) (((((port)&0xFu) << 4) | ((no)&0xFu)))
#define PIN_PORT(pin)     ((uint8_t)(((pin) >> 4) & 0xFu))
#define PIN_NO(pin)       ((uint8_t)((pin)&0xFu))

#define PIN_STPORT(pin) ((GPIO_TypeDef*)(GPIOA_BASE + (0x400u * PIN_PORT(pin))))
#define PIN_STPIN(pin)  ((uint16_t)(1u << PIN_NO(pin)))

#if defined(GPIOZ)
    #define __STM32_PORT_MAX 12u
#elif defined(GPIOK)
    #define __STM32_PORT_MAX 11u
#elif defined(GPIOJ)
    #define __STM32_PORT_MAX 10u
#elif defined(GPIOI)
    #define __STM32_PORT_MAX 9u
#elif defined(GPIOH)
    #define __STM32_PORT_MAX 8u
#elif defined(GPIOG)
    #define __STM32_PORT_MAX 7u
#elif defined(GPIOF)
    #define __STM32_PORT_MAX 6u
#elif defined(GPIOE)
    #define __STM32_PORT_MAX 5u
#elif defined(GPIOD)
    #define __STM32_PORT_MAX 4u
#elif defined(GPIOC)
    #define __STM32_PORT_MAX 3u
#elif defined(GPIOB)
    #define __STM32_PORT_MAX 2u
#elif defined(GPIOA)
    #define __STM32_PORT_MAX 1u
#else
    #define __STM32_PORT_MAX 0u
    #error Unsupported STM32 GPIO peripheral.
#endif

#define PIN_STPORT_MAX __STM32_PORT_MAX

static struct pin_device pin_device;

static rt_base_t stm32_pin_get(const char* name)
{
    rt_base_t pin = 0;
    int hw_port_num, hw_pin_num = 0;
    int i, name_len;

    name_len = rt_strlen(name);

    if ((name_len < 4) || (name_len >= 6)) {
        return -RT_EINVAL;
    }
    if ((name[0] != 'P') || (name[2] != '.')) {
        return -RT_EINVAL;
    }

    if ((name[1] >= 'A') && (name[1] <= 'Z')) {
        hw_port_num = (int)(name[1] - 'A');
    } else {
        return -RT_EINVAL;
    }

    for (i = 3; i < name_len; i++) {
        hw_pin_num *= 10;
        hw_pin_num += name[i] - '0';
    }

    pin = PIN_NUM(hw_port_num, hw_pin_num);

    return pin;
}

static void stm32_pin_write(pin_dev_t dev, rt_base_t pin, rt_base_t value)
{
    GPIO_TypeDef* gpio_port;
    uint16_t gpio_pin;

    if (PIN_PORT(pin) < PIN_STPORT_MAX) {
        gpio_port = PIN_STPORT(pin);
        gpio_pin = PIN_STPIN(pin);

        if (value == GPIO_PIN_RESET) {
            LL_GPIO_ResetOutputPin(gpio_port, gpio_pin);
        } else {
            LL_GPIO_SetOutputPin(gpio_port, gpio_pin);
        }
    }
}

static int stm32_pin_read(pin_dev_t dev, rt_base_t pin)
{
    GPIO_TypeDef* gpio_port;
    uint16_t gpio_pin;
    int value = PIN_LOW;

    if (PIN_PORT(pin) < PIN_STPORT_MAX) {
        gpio_port = PIN_STPORT(pin);
        gpio_pin = PIN_STPIN(pin);

        value = LL_GPIO_IsInputPinSet(gpio_port, gpio_pin);
    }

    return value;
}

static void stm32_pin_mode(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    if (PIN_PORT(pin) >= PIN_STPORT_MAX) {
        return;
    }

    GPIO_InitStruct.Pin = PIN_STPIN(pin);
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    if (otype == PIN_OUT_TYPE_PP) {
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    } else if (otype == PIN_OUT_TYPE_OD) {
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    }

    if (mode == PIN_MODE_OUTPUT) {
        /* output setting */
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    } else if (mode == PIN_MODE_INPUT) {
        /* input setting: not pull. */
        GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    } else if (mode == PIN_MODE_INPUT_PULLUP) {
        /* input setting: pull up. */
        GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    } else if (mode == PIN_MODE_INPUT_PULLDOWN) {
        /* input setting: pull down. */
        GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;
    } else {
        /* unsurpoted mode */
        return;
    }

    LL_GPIO_Init(PIN_STPORT(pin), &GPIO_InitStruct);
}

const static struct pin_ops _stm32_pin_ops = {
    stm32_pin_mode,
    stm32_pin_write,
    stm32_pin_read,
};

rt_err_t drv_gpio_init(void)
{
    /* GPIO Ports Clock Enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);

    // return rt_device_pin_register("pin", &_stm32_pin_ops, RT_NULL);
    pin_device.ops = &_stm32_pin_ops;

    return hal_pin_register(&pin_device, "pin", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
