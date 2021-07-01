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

#include "hal/motor.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/actuator_cmd.h"

static void show_usage(void)
{
}

static int _motor_set(int argc, char** argv, rt_device_t motor_dev, uint16_t mask)
{
    uint16_t chan_val[16] = { 0 };
    uint8_t i;
    uint8_t chan_cnt = 0;

    if (motor_dev == NULL) {
        return -1;
    }

    if (!(motor_dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
        console_printf("motor is not open!\n");
        return -1;
    }

    for (i = 0; i < 16; i++) {
        if (mask & (1 << i)) {
            if (argc > 2 + chan_cnt) {
                chan_val[i] = atoi(argv[chan_cnt++]);
                if (chan_val[i] < 1000 || chan_val[i] > 2000) {
                    // invalid value
                    return -1;
                }
            } else {
                // not enough arguments
                return -1;
            }
        }
    }

    rt_device_write(motor_dev, mask, chan_val, sizeof(uint16_t) * chan_cnt);

    return 0;
}

static int _motor_setall(int argc, char** argv, rt_device_t motor_dev)
{
    uint16_t val;
    uint16_t chan_val[16];

    if (argc < 3 || motor_dev == NULL) {
        return -1;
    }

    if (!(motor_dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
        console_printf("motor is not open!\n");
        return -1;
    }

    val = atoi(argv[2]);

    if (val < 1000 || val > 2000) {
        return -1;
    }

    for (int i = 0; i < 16; i++) {
        chan_val[i] = val;
    }

    rt_device_write(motor_dev, MOTOR_MASK_ALL, chan_val, sizeof(uint16_t) * 16);

    return 0;
}

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    uint8_t aux = 0;
    uint16_t mask = 0;
    rt_device_t motor_dev = NULL;

    if (argc < 2) {
        show_usage();
        return 0;
    }

    for (uint16_t i = 0; i < optc; i++) {
        if (STRING_COMPARE(optv[i].opt, "-h") || STRING_COMPARE(optv[i].opt, "--help")) {
            show_usage();
            return 0;
        } else if (STRING_COMPARE(optv[i].opt, "--aux")) {
            aux = 1;
        } else if (STRING_COMPARE(optv[i].opt, "--mask")) {
            if (syscmd_is_hex(optv[i].val)) {
                mask = math_hex2dec(optv[i].val) && 0xFFFF;
            }
        }
    }

    if (aux) {
        motor_dev = rt_device_find("motor_aux");
    } else {
        motor_dev = rt_device_find("motor_main");
    }

    if (STRING_COMPARE(argv[1], "request")) {
        // request motor control
        // if (actuator_suspend_output() != FMT_EOK) {
        //     console_printf("Fail to get control!\n");
        // }
    } else if (STRING_COMPARE(argv[1], "release")) {
        // release motor control
        // if (actuator_resume_output() != FMT_EOK) {
        //     console_printf("Fail to release control!\n");
        // }
    } else if (strcmp(argv[1], "open") == 0) {
        if (motor_dev) {
            if (rt_device_open(motor_dev, RT_DEVICE_OFLAG_RDWR) == RT_EOK) {
                console_printf("%s open success\n", aux ? "motor aux" : "motor main");
            } else {
                console_printf("%s open fail\n", aux ? "motor aux" : "motor main");
            }
        }
    } else if (strcmp(argv[1], "close") == 0) {
        if (motor_dev) {
            if (rt_device_close(motor_dev) == RT_EOK) {
                console_printf("%s close success\n", aux ? "motor aux" : "motor main");
            } else {
                console_printf("%s close fail\n", aux ? "motor aux" : "motor main");
            }
        }
    } else if (strcmp(argv[1], "set") == 0) {
        if (_motor_set(argc, argv, motor_dev, mask) != 0) {
            console_printf("Fail to set motor!\n");
        }
    } else if (strcmp(argv[1], "setall") == 0) {
        if (_motor_setall(argc, argv, motor_dev) != 0) {
            console_printf("Fail to set motor!\n");
        }
    } else {
        show_usage();
    }

    return 0;
}

int cmd_motor(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_motor, __cmd_motor, Control motor);