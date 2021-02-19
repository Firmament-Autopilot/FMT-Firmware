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

#include <firmament.h>

#include "hal/pin.h"

#define FMU_LED_PIN 17
static rt_device_t pin_device;

static void _led_on(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 0 };

    if (pin_device != RT_NULL) {
        pin_device->write(pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

static void _led_off(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 1 };

    if (pin_device != RT_NULL) {
        pin_device->write(pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

fmt_err task_simple_init(void)
{
    return FMT_EOK;
}

void task_simple_entry(void* parameter)
{
    struct device_pin_mode mode = { FMU_LED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    pin_device = rt_device_find("pin");
    pin_device->control(pin_device, 0, &mode);

    while (1) {
        _led_on();
        rt_thread_delay(1000);
        _led_off();
        rt_thread_delay(1000);
    }
}