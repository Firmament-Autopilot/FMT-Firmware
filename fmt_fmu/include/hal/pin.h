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

#ifndef __PIN_H__
#define __PIN_H__

#include <firmament.h>

#define PIN_LOW 0x00
#define PIN_HIGH 0x01

#define PIN_MODE_OUTPUT 0x00
#define PIN_MODE_INPUT 0x01
#define PIN_MODE_INPUT_PULLUP 0x02

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

/* gpio driver opeations */
struct pin_ops {
    void (*pin_mode)(struct rt_device* device, rt_base_t pin, rt_base_t mode, rt_base_t otype);
    void (*pin_write)(struct rt_device* device, rt_base_t pin, rt_base_t value);
    int (*pin_read)(struct rt_device* device, rt_base_t pin);

    /* TODO: add GPIO interrupt */
};

rt_err_t hal_pin_register(pin_dev_t pin, const char* name, rt_uint32_t flag, void* data);

#endif
