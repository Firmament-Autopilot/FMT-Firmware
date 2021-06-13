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

#include "driver/ncp5623c.h"
#include "hal/pin.h"
#include "module/fms/fms_model.h"
#include "module/ins/ins_model.h"
#include "module/sysio/pilot_cmd.h"
#include "module/task_manager/task_manager.h"
#include "task/task_logger.h"

#define TAG "Status"

#define FMU_LED_RED_PIN   17
#define FMU_LED_GREEN_PIN 38
#define FMU_LED_BLUE_PIN  39

#define LED_ON(_pin)  led_set((struct device_pin_status) { .pin = _pin, .status = 0 })
#define LED_OFF(_pin) led_set((struct device_pin_status) { .pin = _pin, .status = 1 })

MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(pilot_cmd);

static rt_device_t pin_dev;
static rt_device_t rgb_led_dev;

static McnNode_t fms_out_nod;
static McnNode_t ins_out_nod;
static McnNode_t pilot_cmd_nod;

static void led_set(struct device_pin_status pin_sta)
{
    RT_ASSERT(pin_dev != NULL);

    pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(&pin_sta));
}

static void led_init(struct device_pin_mode pin_mode)
{
    RT_CHECK(pin_dev->control(pin_dev, 0, &pin_mode));
}

static void rgb_led_control(void)
{
    static int bright = 0;
    static int inc = 0;
    static int max_bright = 16;
    static int min_bright = 0;
    DEFINE_TIMETAG(rgb_led, 0);

    if (bright <= min_bright) {
        TIMETAG(rgb_led)->period = 150;
    } else {
        if (bright >= max_bright) {
            TIMETAG(rgb_led)->period = 250;
        } else {
            TIMETAG(rgb_led)->period = 50;
        }
    }

    if (check_timetag(TIMETAG(rgb_led))) {
        /* breath light control */
        if (bright <= min_bright)
            inc = 1;

        if (bright >= max_bright)
            inc = -1;

        bright += inc;
        rt_device_control(rgb_led_dev, NCP5623_CMD_SET_BRIGHT, (void*)bright);
    }
}

static void update_fms_status(void)
{
    static FMS_Out_Bus old_fms_out;
    FMS_Out_Bus fms_out;

    if (fms_out_nod == NULL)
        return;

    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);

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
                // rt_device_write(_rgb_led_dev, TCA62724_LED_RED, NULL, 0);
                RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_RED));
                break;
            }
        }

        if (fms_out.state != old_fms_out.state) {
            switch (fms_out.state) {
            case 0:
                ulog_i(TAG, "[Status] Disarm");
                // rt_device_write(_rgb_led_dev, TCA62724_LED_BLUE, NULL, 0);
                RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_BLUE));

                /* stop blog when disarm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 || PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 2) {
                    blog_stop();
                }
                break;

            case 1:
                ulog_i(TAG, "[Status] Standby");
                // rt_device_write(_rgb_led_dev, TCA62724_LED_GREEN, NULL, 0);
                RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_GREEN));
                break;

            case 2:
                ulog_i(TAG, "[Status] Arm");
                // rt_device_write(_rgb_led_dev, TCA62724_LED_GREEN, NULL, 0);
                RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_GREEN));

                /* start blog from arm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 && blog_get_status() == BLOG_STATUS_IDLE) {
                    logger_start_blog(NULL);
                }
                break;

            default:
                ulog_w(TAG, "[Status] Unknown");
                // rt_device_write(_rgb_led_dev, TCA62724_LED_RED, NULL, 0);
                RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_RED));
                break;
            }
        }

        old_fms_out = fms_out;
    }
}

static void update_ins_status(void)
{
    //TODO
}

static void update_pilot_cmd_status(void)
{
    static Pilot_Cmd_Bus old_pilot_cmd;
    Pilot_Cmd_Bus pilot_cmd;

    if (mcn_poll(pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), pilot_cmd_nod, &pilot_cmd);

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

fmt_err_t task_status_init(void)
{
    struct device_pin_mode r_pin_mode = { FMU_LED_RED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    struct device_pin_mode g_pin_mode = { FMU_LED_GREEN_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    struct device_pin_mode b_pin_mode = { FMU_LED_BLUE_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    RT_ASSERT(fms_out_nod != NULL);

    ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    RT_ASSERT(ins_out_nod != NULL);

    pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    RT_ASSERT(pilot_cmd_nod != NULL);

    /* configure led pin */
    pin_dev = rt_device_find("pin");
    RT_ASSERT(pin_dev != NULL);

    RT_CHECK(rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR));
    led_init(r_pin_mode);
    led_init(g_pin_mode);
    led_init(b_pin_mode);

    /* configure rgd led */
    rgb_led_dev = rt_device_find("ncp5623c");
    RT_ASSERT(rgb_led_dev != NULL);

    RT_CHECK(rt_device_open(rgb_led_dev, RT_DEVICE_OFLAG_RDWR));

    return FMT_EOK;
}

void task_status_entry(void* parameter)
{
    LED_ON(FMU_LED_RED_PIN);
    LED_ON(FMU_LED_GREEN_PIN);
    LED_ON(FMU_LED_BLUE_PIN);

    RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_BLUE));
    sys_msleep(10); /* give some time for rgb led to setup */

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
        update_pilot_cmd_status();

        // update FMS output status
        update_fms_status();

        // update INS output status
        update_ins_status();

        rgb_led_control();

        sys_msleep(10);
    }
}

FMT_TASK_EXPORT(
    status,                 /* name */
    task_status_init,       /* init */
    task_status_entry,      /* entry */
    STATUS_THREAD_PRIORITY, /* priority */
    2048,                   /* stack size */
    NULL,                   /* param */
    NULL                    /* dependency */
);
