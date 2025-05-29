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
#include <firmament.h>

#include "FMS.h"
#include "led.h"
#include "module/workqueue/workqueue_manager.h"

MCN_DECLARE(fms_output);

static rt_device_t pin_dev;
static uint8_t _r;
static uint8_t _g;
static uint8_t _b;

static void run_rgb_led(void* parameter)
{
    if (_r) {
        LED_TOGGLE(FMU_RGB_LED_RED_PIN);
    }

    if (_g) {
        LED_TOGGLE(FMU_RGB_LED_GREEN_PIN);
    }

    if (_b) {
        LED_TOGGLE(FMU_RGB_LED_BLUE_PIN);
    }
}

void vehicle_status_change_cb(uint8_t status)
{
    switch (status) {
    case VehicleStatus_Disarm:
        rgb_led_set_color(RGB_LED_BLUE);
        break;
    case VehicleStatus_Standby:
        rgb_led_set_color(RGB_LED_YELLOW);
        break;
    case VehicleStatus_Arm:
        rgb_led_set_color(RGB_LED_GREEN);
        break;
    default:
        rgb_led_set_color(RGB_LED_RED);
        break;
    }
}

void vehicle_state_change_cb(uint8_t mode)
{
    if (mode == VehicleState_None) {
        /* unknown mode */
        rgb_led_set_color(RGB_LED_RED);
    }
}

void fms_error_change_cb(uint32_t error)
{
    if (error > 0) {
        rgb_led_set_color(RGB_LED_RED);
    } else {
        FMS_Out_Bus fms_out;
        mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out);
        /* change led to current status color */
        vehicle_status_change_cb(fms_out.status);
    }
}

fmt_err_t led_set(struct device_pin_status pin_sta)
{
    if (pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(&pin_sta)) != sizeof(&pin_sta)) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t led_toggle(uint32_t pin)
{
    struct device_pin_status pin_sta = { .pin = pin };

    if (pin_dev->read(pin_dev, 0, (void*)&pin_sta, sizeof(&pin_sta)) != sizeof(&pin_sta)) {
        return FMT_ERROR;
    }

    pin_sta.status = !pin_sta.status;
    if (pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(&pin_sta)) != sizeof(&pin_sta)) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t led_init(struct device_pin_mode pin_mode)
{
    if (pin_dev->control(pin_dev, 0, &pin_mode) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t rgb_led_set_color(uint32_t color)
{
    /* First off all leds */
    LED_OFF(FMU_RGB_LED_RED_PIN);
    LED_OFF(FMU_RGB_LED_GREEN_PIN);
    LED_OFF(FMU_RGB_LED_BLUE_PIN);

    switch (color) {
    case RGB_LED_RED:
        _r = 1;
        _g = 0;
        _b = 0;
        break;
    case RGB_LED_GREEN:
        _r = 0;
        _g = 1;
        _b = 0;
        break;
    case RGB_LED_BLUE:
        _r = 0;
        _g = 0;
        _b = 1;
        break;
    case RGB_LED_YELLOW:
        _r = 1;
        _g = 1;
        _b = 0;
        break;
    case RGB_LED_PURPLE:
        _r = 1;
        _g = 0;
        _b = 1;
        break;
    case RGB_LED_CYAN:
        _r = 0;
        _g = 1;
        _b = 1;
        break;
    case RGB_LED_WHITE:
        _r = 1;
        _g = 1;
        _b = 1;
        break;
    default:
        _r = 0;
        _g = 0;
        _b = 0;
    }

    return FMT_EOK;
}

static struct WorkItem rgb_led_item = {
    .name = "rgb_led",
    .period = 1000,
    .schedule_time = 0,
    .run = run_rgb_led
};

fmt_err_t led_control_init(void)
{
    struct device_pin_mode rgbled_r_mode = { FMU_RGB_LED_RED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    struct device_pin_mode rgbled_g_mode = { FMU_RGB_LED_GREEN_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    struct device_pin_mode rgbled_b_mode = { FMU_RGB_LED_BLUE_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    /* configure led pin */
    pin_dev = rt_device_find("pin");
    RT_ASSERT(pin_dev != NULL);

    RT_CHECK(rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR));

    LED_OFF(FMU_RGB_LED_RED_PIN);
    LED_OFF(FMU_RGB_LED_GREEN_PIN);
    LED_OFF(FMU_RGB_LED_BLUE_PIN);

    led_init(rgbled_r_mode);
    led_init(rgbled_g_mode);
    led_init(rgbled_b_mode);

    /* set rgb led initial color */
    rgb_led_set_color(RGB_LED_BLUE);

    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &rgb_led_item));

    return FMT_EOK;
}
