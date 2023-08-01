/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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

#include "module/sensor/sensor_hub.h"
#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/pilot_cmd.h"

MCN_DECLARE(sensor_airspeed);

#define IN_RANGE(_x, _low, _up) ((_x) >= (_low) && (_x) <= (_up))

MCN_DECLARE(rc_channels);

static McnNode_t rc_channels_nod;
static MCN_EVENT_HANDLE event;

static fmt_err_t get_stick_trim_value(float* thro_trim, float* yaw_trim, float* pitch_trim, float* roll_trim)
{
    int16_t rc_val[16];
    int32_t sum_val[4] = { 0 };

    for (int i = 0; i < 5; i++) {
        if (mcn_wait(rc_channels_nod, TICKS_FROM_MS(500))) {
            mcn_copy(MCN_HUB(rc_channels), rc_channels_nod, &rc_val);
            /* get stick trim value */
            sum_val[0] += rc_val[pilot_cmd_get_stick_chan(STICK_THRO)];
            sum_val[1] += rc_val[pilot_cmd_get_stick_chan(STICK_YAW)];
            sum_val[2] += rc_val[pilot_cmd_get_stick_chan(STICK_PITCH)];
            sum_val[3] += rc_val[pilot_cmd_get_stick_chan(STICK_ROLL)];
        } else {
            printf("Wait rc_channels topic timeout!\n");
            return EXIT_FAILURE;
        }
    }

    *thro_trim = sum_val[0] / 5;
    *yaw_trim = sum_val[1] / 5;
    *pitch_trim = sum_val[2] / 5;
    *roll_trim = sum_val[3] / 5;

    return FMT_EOK;
}

static fmt_err_t get_stick_corner_value(stick_enum stick, int16_t low, int16_t up, float* stick_val)
{
    int16_t rc_val[16];
    uint16_t hold_cnt = 0;
    uint16_t wait_cnt = MCN_HUB(rc_channels)->freq > 5.0f ? MCN_HUB(rc_channels)->freq : 5;

    /* first make sure the stick is hold in the expected area */
    while (hold_cnt < wait_cnt) {
        /* type any key to exit */
        if (syscmd_has_input()) {
            syscmd_flush();
            return FMT_ENOTHANDLE;
        }

        if (mcn_wait(rc_channels_nod, TICKS_FROM_MS(500))) {
            mcn_copy(MCN_HUB(rc_channels), rc_channels_nod, &rc_val);

            if (IN_RANGE(rc_val[pilot_cmd_get_stick_chan(stick)], low, up)) {
                hold_cnt++;
            } else {
                hold_cnt = 0;
            }
        } else {
            printf("Wait rc_channels topic timeout!\n");
            return FMT_ETIMEOUT;
        }
    }

    int32_t sum_val = 0;
    for (int i = 0; i < 5; i++) {
        if (mcn_wait(rc_channels_nod, TICKS_FROM_MS(500))) {
            mcn_copy(MCN_HUB(rc_channels), rc_channels_nod, &rc_val);
            /* accumulate the stick value */
            sum_val += rc_val[pilot_cmd_get_stick_chan(stick)];
        } else {
            printf("Wait rc_channels topic timeout!\n");
            return FMT_ETIMEOUT;
        }
    }

    *stick_val = sum_val / 5;

    return FMT_EOK;
}

static void show_usage(void)
{
    COMMAND_USAGE("calib", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("rc", "Calibrate RC.");
    SHELL_COMMAND("airspeed", "Calibrate airspeed.");
}

static int rc_calib(struct optparse options)
{
    int option;
    char ch;
    float rc_thro_max, rc_thro_min, rc_thro_trim;
    float rc_yaw_max, rc_yaw_min, rc_yaw_trim;
    float rc_pitch_max, rc_pitch_min, rc_pitch_trim;
    float rc_roll_max, rc_roll_min, rc_roll_trim;
    struct optparse_long longopts[] = {
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case '?':
            printf("%s: %s\n", "calib rc", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    /* if we did not subscribe the rc_channels topic, subscribe it now  */
    if (rc_channels_nod == NULL) {
        if (event == NULL) {
            event = (MCN_EVENT_HANDLE)rt_sem_create("rc_calib", 0, RT_IPC_FLAG_FIFO);
            if (event == NULL) {
                printf("fail to create rc_calib event!");
                return EXIT_FAILURE;
            }
        }

        rc_channels_nod = mcn_subscribe(MCN_HUB(rc_channels), event, NULL);
        if (rc_channels_nod == NULL) {
            printf("fail to subscribe rc_channels topic!");
            return EXIT_FAILURE;
        }
    }

    printf("Before calibration you should move all your sticks to center.\n");
    printf("And for safety, please make sure you have disabled all motors!\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o      ●      o  o      ●      o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");
    printf("Next step (y/n)\n");

    ch = syscmd_getc();
    if (ch != 'y' && ch != 'Y') {
        return EXIT_SUCCESS;
    }

    if (get_stick_trim_value(&rc_thro_trim, &rc_yaw_trim, &rc_pitch_trim, &rc_roll_trim) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the throttle stick all the way up and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /    ●    \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o             o  o      ●      o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_THRO, 1700, 2200, &rc_thro_max) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the throttle stick all the way down and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o             o  o      ●      o");
    console_println(" \\           /    \\           / ");
    console_println("  \\    ●    /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_THRO, 800, 1300, &rc_thro_min) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the yaw stick all the way right and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o           ● o  o      ●      o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_YAW, 1700, 2200, &rc_yaw_max) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the yaw stick all the way left and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o ●           o  o      ●      o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_YAW, 800, 1300, &rc_yaw_min) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the pitch stick all the way up and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /    ●    \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o      ●      o  o             o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_PITCH, 1700, 2200, &rc_pitch_max) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the pitch stick all the way down and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o      ●      o  o             o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\    ●    /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_PITCH, 800, 1300, &rc_pitch_min) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the roll stick all the way right and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o      ●      o  o           ● o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_ROLL, 1700, 2200, &rc_roll_max) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("Move the roll stick all the way left and hold it there\n");
    console_println("   o-------o        o-------o   ");
    console_println("  /         \\      /         \\  ");
    console_println(" /           \\    /           \\ ");
    console_println("o      ●      o  o ●           o");
    console_println(" \\           /    \\           / ");
    console_println("  \\         /      \\         /  ");
    console_println("   o-------o        o-------o   ");

    if (get_stick_corner_value(STICK_ROLL, 800, 1300, &rc_roll_min) != FMT_EOK) {
        return EXIT_FAILURE;
    }

    printf("RC calibrating finish!\n");
    printf("RC_THRO_MAX:%.1f RC_THRO_MIN:%.1f, RC_THRO_TRIM:%.1f\n", rc_thro_max, rc_thro_min, rc_thro_trim);
    printf("RC_YAW_MAX:%.1f RC_YAW_MIN:%.1f, RC_YAW_TRIM:%.1f\n", rc_yaw_max, rc_yaw_min, rc_yaw_trim);
    printf("RC_PITCH_MAX:%.1f RC_PITCH_MIN:%.1f, RC_PITCH_TRIM:%.1f\n", rc_pitch_max, rc_pitch_min, rc_pitch_trim);
    printf("RC_ROLL_MAX:%.1f RC_ROLL_MIN:%.1f, RC_ROLL_TRIM:%.1f\n", rc_roll_max, rc_roll_min, rc_roll_trim);
    printf("Would you like to update RC parameters? (y/n)\n");
    ch = syscmd_getc();
    if (ch == 'y' || ch == 'Y') {
        int32_t start_idx = param_get_index(PARAM_GET(RC, RC1_MAX));

        /* update rc parameters. note that you need to save it manually */
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_THRO) * 4), &rc_thro_max);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_THRO) * 4 + 1), &rc_thro_min);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_THRO) * 4 + 3), &rc_thro_trim);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_YAW) * 4), &rc_yaw_max);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_YAW) * 4 + 1), &rc_yaw_min);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_YAW) * 4 + 3), &rc_yaw_trim);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_PITCH) * 4), &rc_pitch_max);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_PITCH) * 4 + 1), &rc_pitch_min);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_PITCH) * 4 + 3), &rc_pitch_trim);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_ROLL) * 4), &rc_roll_max);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_ROLL) * 4 + 1), &rc_roll_min);
        param_set_val(param_get_by_index(start_idx + pilot_cmd_get_stick_chan(STICK_ROLL) * 4 + 3), &rc_roll_trim);

        printf("RC parameter updated! Note that you need enter \"param save\" to save parameters.\n");
    }

    return EXIT_SUCCESS;
}

static int airspeed_calib(struct optparse options)
{
    airspeed_data_t airspeed_report;
    McnNode_t airspeed_sub_node;
    rt_sem_t event = rt_sem_create("airspeed", 0, RT_IPC_FLAG_FIFO);
    uint16_t cnt = 0;
    float diff_pressure_pa = 0.0f;
    int res = EXIT_SUCCESS;

    airspeed_sub_node = mcn_subscribe(MCN_HUB(sensor_airspeed), event, NULL);

    if (mcn_wait(airspeed_sub_node, TICKS_FROM_MS(100))) {
        /* If we can read airspeed data, first reset offset */
        PARAM_SET_FLOAT(CALIB, DIFF_PRESS_OFFSET, 0.0f);
    }

    while (mcn_wait(airspeed_sub_node, TICKS_FROM_MS(100))) {
        mcn_copy(MCN_HUB(sensor_airspeed), airspeed_sub_node, &airspeed_report);

        diff_pressure_pa += airspeed_report.diff_pressure_pa;
        cnt++;
        if (cnt >= 100) {
            break;
        }
    }

    if (cnt >= 100) {
        float diff_press_offset = diff_pressure_pa / cnt;
        PARAM_SET_FLOAT(CALIB, DIFF_PRESS_OFFSET, diff_press_offset);
        printf("diff pressure offset:%f\n", diff_press_offset);
        printf("you need enter param save calibration result\n");
    } else {
        printf("airspeed read timeout!\n");
        res = EXIT_FAILURE;
    }

    mcn_unsubscribe(MCN_HUB(sensor_airspeed), airspeed_sub_node);
    rt_sem_delete(event);

    return res;
}

int cmd_calib(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "rc")) {
            res = rc_calib(options);
        } else if (STRING_COMPARE(arg, "airspeed")) {
            res = airspeed_calib(options);
        } else {
            show_usage();
            res = EXIT_FAILURE;
        }
    } else {
        show_usage();
        res = EXIT_FAILURE;
    }

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_calib, __cmd_calib, calibration command);