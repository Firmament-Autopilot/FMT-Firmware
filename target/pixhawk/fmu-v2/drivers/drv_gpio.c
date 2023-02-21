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

#include "hal/pin/pin.h"
#include <firmament.h>

/* STM32F427 GPIO driver */
struct pin_index {
    int index;
    uint32_t rcc;
    GPIO_TypeDef* gpio;
    uint32_t pin;
};

/* pin map, refer to chip datasheet */
static const struct pin_index pins[] = {
    { 23, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_0 },
    { 24, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_1 },
    { 25, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_2 },
    { 26, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_3 },
    { 29, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_4 },
    { 30, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_5 },
    { 31, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_6 },
    { 32, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_7 },

    { 67, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_8 },
    { 68, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_9 },
    { 69, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_10 },
    { 70, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_11 },
    { 71, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_12 },
    { 72, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_13 },
    { 76, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_14 },
    { 77, RCC_AHB1Periph_GPIOA, GPIOA, GPIO_Pin_15 },

    { 35, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_0 },
    { 36, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_1 },
    { 37, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_2 },
    { 89, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_3 },
    { 90, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_4 },
    { 91, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_5 },
    { 92, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_6 },
    { 93, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_7 },

    { 95, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_8 },
    { 96, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_9 },
    { 47, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_10 },
    { 48, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_11 },
    { 51, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_12 },
    { 52, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_13 },
    { 53, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_14 },
    { 54, RCC_AHB1Periph_GPIOB, GPIOB, GPIO_Pin_15 },

    { 15, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_0 },
    { 16, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_1 },
    { 17, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_2 },
    { 18, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_3 },
    { 33, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_4 },
    { 34, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_5 },
    { 63, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_6 },
    { 64, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_7 },

    { 65, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_8 },
    { 66, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_9 },
    { 78, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_10 },
    { 79, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_11 },
    { 80, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_12 },
    { 7, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_13 },
    { 8, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_14 },
    { 9, RCC_AHB1Periph_GPIOC, GPIOC, GPIO_Pin_15 },

    { 81, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_0 },
    { 82, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_1 },
    { 83, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_2 },
    { 84, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_3 },
    { 85, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_4 },
    { 86, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_5 },
    { 87, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_6 },
    { 88, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_7 },

    { 55, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_8 },
    { 56, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_9 },
    { 57, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_10 },
    { 58, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_11 },
    { 59, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_12 },
    { 60, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_13 },
    { 61, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_14 },
    { 62, RCC_AHB1Periph_GPIOD, GPIOD, GPIO_Pin_15 },

    { 97, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_0 },
    { 98, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_1 },
    { 1, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_2 },
    { 2, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_3 },
    { 3, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_4 },
    { 4, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_5 },
    { 5, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_6 },
    { 38, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_7 },

    { 39, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_8 },
    { 40, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_9 },
    { 41, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_10 },
    { 42, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_11 },
    { 43, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_12 },
    { 44, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_13 },
    { 45, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_14 },
    { 46, RCC_AHB1Periph_GPIOE, GPIOE, GPIO_Pin_15 },
};

#define ITEM_NUM(items) sizeof(items) / sizeof(items[0])

static struct pin_device pin_device;

// TODO, optimize get_pin speed
static const struct pin_index* _get_pin(uint8_t pin)
{
    for (int i = 0; i < ITEM_NUM(pins); i++) {
        if (pin == pins[i].index) {
            return &pins[i];
        }
    }

    return RT_NULL;
};

static void gpio_pin_write(pin_dev_t dev, rt_base_t pin, rt_base_t value)
{
    const struct pin_index* index;

    index = _get_pin(pin);

    if (index == RT_NULL) {
        return;
    }

    if (value == PIN_LOW) {
        GPIO_ResetBits(index->gpio, index->pin);
    } else {
        GPIO_SetBits(index->gpio, index->pin);
    }
}

static int gpio_pin_read(pin_dev_t dev, rt_base_t pin)
{
    int value;
    const struct pin_index* index;

    value = PIN_LOW;

    index = _get_pin(pin);

    if (index == RT_NULL) {
        return value;
    }

    if (GPIO_ReadInputDataBit(index->gpio, index->pin) == Bit_RESET) {
        value = PIN_LOW;
    } else {
        value = PIN_HIGH;
    }

    return value;
}

static void gpio_pin_mode(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype)
{
    const struct pin_index* index;
    GPIO_InitTypeDef GPIO_InitStructure;

    index = _get_pin(pin);

    if (index == RT_NULL) {
        return;
    }

    /* GPIO Periph clock enable */
    RCC_AHB1PeriphClockCmd(index->rcc, ENABLE);

    /* Configure GPIO_InitStructure */
    GPIO_InitStructure.GPIO_Pin = index->pin;

    if (otype == PIN_OUT_TYPE_PP) {
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    } else if (otype == PIN_OUT_TYPE_OD) {
        GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    }

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

    if (mode == PIN_MODE_OUTPUT) {
        /* output setting */
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    } else if (mode == PIN_MODE_INPUT) {
        /* input setting: not pull. */
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    } else if (mode == PIN_MODE_INPUT_PULLUP) {
        /* input setting: pull up. */
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    } else {
        /* input setting:default. */
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    }

    GPIO_Init(index->gpio, &GPIO_InitStructure);
}

const static struct pin_ops _gpio_pin_ops = {
    gpio_pin_mode,
    gpio_pin_write,
    gpio_pin_read,
};

rt_err_t drv_gpio_init(void)
{
    pin_device.ops = &_gpio_pin_ops;

    /* Enable PE3 */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    /* Set PE3 for VDD_3V3_SENSOR_EN */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE, GPIO_Pin_3);

    return hal_pin_register(&pin_device, "pin", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
