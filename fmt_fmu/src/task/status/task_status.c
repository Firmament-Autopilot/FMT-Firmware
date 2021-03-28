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

#include "driver/tca62724.h"
#include "hal/pin.h"
#include "module/buzzer/buzzer_tune.h"
#include "module/fms/fms_model.h"
#include "module/ins/ins_model.h"
#include "module/sysio/pilot_cmd.h"
#include "module/utils/devmq.h"
#include "task/task_logger.h"
#include "task/task_status.h"

#define TAG "Status"

#define FMU_LED_PIN 43

MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(pilot_cmd);

static rt_device_t _pin_device;
static rt_device_t _rgb_led_dev;

static McnNode_t _fms_out_nod;
static McnNode_t _ins_out_nod;
static McnNode_t _pilot_cmd_nod;

static void _led_on(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 0 };

    if (_pin_device != RT_NULL) {
        _pin_device->write(_pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

static void _led_off(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 1 };
    ;

    if (_pin_device != RT_NULL) {
        _pin_device->write(_pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

static void _rgb_led_control(void)
{
    static int bright = 0;
    static int inc = 0;
    DEFINE_TIMETAG(rgb_led, 0);

    if (bright <= 0) {
        TIMETAG(rgb_led)->period = 100;
        // delay_time = 100;
    } else {
        if (bright >= TCA62724_MAX_BRIGHT) {
            // delay_time = 300;
            TIMETAG(rgb_led)->period = 300;
        } else {
            // delay_time = 50;
            TIMETAG(rgb_led)->period = 50;
        }
    }

    if (check_timetag(TIMETAG(rgb_led))) {
        /* breath light control */
        if (bright <= 0)
            inc = 1;

        if (bright >= TCA62724_MAX_BRIGHT)
            inc = -1;

        bright += inc;
        rt_device_control(_rgb_led_dev, TCA62724_CMD_SET_BRIGHT, (void*)bright);
    }
}

static void _update_fms_status(void)
{
    static FMS_Out_Bus old_fms_out;
    FMS_Out_Bus fms_out;

    if (_fms_out_nod == NULL)
        return;

    if (mcn_poll(_fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), _fms_out_nod, &fms_out);

        if (fms_out.mode != old_fms_out.mode) {
            switch (fms_out.mode) {
            case 1:
                ulog_i(TAG, "[Mode]] Mission");
                break;

            case 2:
                ulog_i(TAG, "[Mode] Position");
                break;

            case 3:
                ulog_i(TAG, "[Mode] Altitude Hold");
                break;

            case 4:
                ulog_i(TAG, "[Mode] Manual");
                break;

            case 5:
                ulog_i(TAG, "[Mode] Acro");
                break;

            default:
                ulog_w(TAG, "[Mode] Unknown");
                rt_device_write(_rgb_led_dev, TCA62724_LED_RED, NULL, 0);
                break;
            }
        }

        if (fms_out.state != old_fms_out.state) {
            switch (fms_out.state) {
            case 0:
                ulog_i(TAG, "[Status] Disarm");
                rt_device_write(_rgb_led_dev, TCA62724_LED_BLUE, NULL, 0);

                /* stop blog when disarm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 || PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 2) {
                    blog_stop();
                }
                break;

            case 1:
                ulog_i(TAG, "[Status] Standby");
                rt_device_write(_rgb_led_dev, TCA62724_LED_GREEN, NULL, 0);
                break;

            case 2:
                ulog_i(TAG, "[Status] Arm");
                rt_device_write(_rgb_led_dev, TCA62724_LED_GREEN, NULL, 0);

                /* start blog from arm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 && blog_get_status() == BLOG_STATUS_IDLE) {
                    logger_start_blog(NULL);
                }
                break;

            default:
                ulog_w(TAG, "[Status] Unknown");
                rt_device_write(_rgb_led_dev, TCA62724_LED_RED, NULL, 0);
                break;
            }
        }

        old_fms_out = fms_out;
    }
}

static void _update_ins_status(void)
{
    //TODO
}

static void _update_pilot_cmd_status(void)
{
    static Pilot_Cmd_Bus old_pilot_cmd;
    Pilot_Cmd_Bus pilot_cmd;

    if (mcn_poll(_pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), _pilot_cmd_nod, &pilot_cmd);

        if (pilot_cmd.cmd_1 != old_pilot_cmd.cmd_1) {
            switch (pilot_cmd.cmd_1) {
            case FMS_CMD_FORCE_DISARM:
                ulog_i(TAG, "[Pilot Cmd] Force Disarm");
                break;
            default:
                break;
            }
        }

        old_pilot_cmd = pilot_cmd;
    }
}

fmt_err task_status_init(void)
{
    struct device_pin_mode mode = { FMU_LED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    _pin_device = rt_device_find("pin");

    if (_pin_device == RT_NULL) {
        return FMT_ERROR;
    }

    /* configure led pin device */
    if (rt_device_open(_pin_device, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }

    _pin_device->control(_pin_device, 0, &mode);

    /* get 3 channel led device */
    _rgb_led_dev = rt_device_find("tca62724");

    if (_rgb_led_dev == RT_NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(_rgb_led_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void task_status_entry(void* parameter)
{
    // static int _inc;
    // static int bright = 0;
    // uint32_t delay_time;

    _fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    _ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    _pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);

    _led_on();

    rt_device_write(_rgb_led_dev, TCA62724_LED_BLUE, NULL, 0);
    buzzer_tune_init();
    buzzer_tune_play(TUNE_STARTUP);

#ifdef FMT_USING_HIL
#ifdef FMT_USING_SIH
    ulog_i(TAG, "SIH Simulation");
#else
    ulog_i(TAG, "HIL Simulation");
#endif
#endif

#ifdef FMT_HIL_WITH_ACTUATOR
    ulog_w(TAG, "Actuator enabled for HIL, make sure you have removed all propellers!");
#endif

    while (1) {
        // update pilot command status
        _update_pilot_cmd_status();

        // update FMS output status
        _update_fms_status();

        // update INS output status
        _update_ins_status();

        _rgb_led_control();

        sys_msleep(10);
    }
}