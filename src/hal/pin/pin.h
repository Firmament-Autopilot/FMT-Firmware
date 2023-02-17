/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#ifndef PIN_H__
#define PIN_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PIN_LOW  0x00
#define PIN_HIGH 0x01

#define PIN_MODE_OUTPUT         0x00
#define PIN_MODE_INPUT          0x01
#define PIN_MODE_INPUT_PULLUP   0x02
#define PIN_MODE_INPUT_PULLDOWN 0x03
#define PIN_MODE_OUTPUT_OD      0x04

#define PIN_IRQ_MODE_RISING         0x00
#define PIN_IRQ_MODE_FALLING        0x01
#define PIN_IRQ_MODE_RISING_FALLING 0x02
#define PIN_IRQ_MODE_HIGH_LEVEL     0x03
#define PIN_IRQ_MODE_LOW_LEVEL      0x04

#define PIN_IRQ_DISABLE 0x00
#define PIN_IRQ_ENABLE  0x01

#define PIN_OUT_TYPE_PP 0x00
#define PIN_OUT_TYPE_OD 0x01

/* pin device and operations */
struct pin_device {
    struct rt_device parent;
    const struct pin_ops* ops;
};
typedef struct pin_device* pin_dev_t;

struct device_pin_mode {
    uint16_t pin;
    uint16_t mode;
    uint16_t otype;
};
struct device_pin_status {
    uint16_t pin;
    uint16_t status;
};

struct rt_pin_irq_hdr {
    rt_int16_t pin;
    rt_uint16_t mode;
    void (*hdr)(void* args);
    void* args;
};

/* gpio driver opeations */
struct pin_ops {
    void (*pin_mode)(pin_dev_t dev, rt_base_t pin, rt_base_t mode, rt_base_t otype);
    void (*pin_write)(pin_dev_t dev, rt_base_t pin, rt_base_t value);
    int (*pin_read)(pin_dev_t dev, rt_base_t pin);
    /* TODO: add GPIO interrupt */
};

rt_err_t hal_pin_register(pin_dev_t pin, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
