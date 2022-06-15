/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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
#ifndef LED_H__
#define LED_H__

#include <firmament.h>

#include "driver/rgb_led/tca62724.h"
#include "hal/pin/pin.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FMU_LED_BLUE_PIN 43

#define LED_ON(_pin)     led_set((struct device_pin_status) { .pin = _pin, .status = 0 })
#define LED_OFF(_pin)    led_set((struct device_pin_status) { .pin = _pin, .status = 1 })
#define LED_TOGGLE(_pin) led_toggle(_pin)

fmt_err_t led_control_init(void);
fmt_err_t led_init(struct device_pin_mode pin_mode);
fmt_err_t led_set(struct device_pin_status pin_sta);
fmt_err_t led_toggle(uint32_t pin);
fmt_err_t rgb_led_set_color(uint32_t color);
fmt_err_t rgb_led_set_bright(uint32_t bright);

#ifdef __cplusplus
}
#endif

#endif