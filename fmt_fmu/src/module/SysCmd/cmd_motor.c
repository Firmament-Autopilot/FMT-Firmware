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

static void show_usage(void)
{
}

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    uint8_t aux = 0;
    uint8_t id = 0;
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
        } else if (STRING_COMPARE(optv[i].opt, "--id")) {
            if (syscmd_is_num(optv[i].val)) {
                id = atoi(optv[i].val);
            }
        }
    }

    if (aux) {
        motor_dev = rt_device_find("motor_aux");
    } else {
        motor_dev = rt_device_find("motor_main");
    }

    if (strcmp(argv[1], "open") == 0) {
        if (motor_dev) {

            if (rt_device_open(motor_dev, RT_DEVICE_OFLAG_RDWR) == RT_EOK) {
                console_printf("%s open success\n", aux ? "motor_aux" : "motor");
            } else {
                console_printf("%s open fail\n", aux ? "motor_aux" : "motor");
            }
        }
    } else if (strcmp(argv[1], "close") == 0) {
        if (motor_dev) {
            if (rt_device_close(motor_dev) == RT_EOK) {
                console_printf("%s close success\n", aux ? "motor_aux" : "motor");
            } else {
                console_printf("%s close fail\n", aux ? "motor_aux" : "motor");
            }
        }
    } else if (strcmp(argv[1], "set") == 0) {
        uint16_t val = atoi(argv[2]);
        if (motor_dev && argc >= 3) {
            if (!(motor_dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
                console_printf("open it first\n");
                return -1;
            }

            if (id) {
                if (rt_device_write(motor_dev, 1 << (id - 1), &val, 2) == 2) {
                    console_printf("%s[%d] = %d\n", aux ? "motor_aux" : "motor", id, val);
                } else {
                    console_printf("%s[%d] set fail\n", aux ? "motor_aux" : "motor", id);
                }
            } else {
                console_printf("need specify motor id\n");
            }
        }
    } else if (strcmp(argv[1], "setall") == 0) {
        uint16_t val = atoi(argv[2]);
        uint16_t motor_val[4];

        motor_val[0] = val;
        motor_val[1] = val;
        motor_val[2] = val;
        motor_val[3] = val;

        if (motor_dev && argc >= 3) {
            if (!(motor_dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
                console_printf("open it first\n");
                return -1;
            }

            if (rt_device_write(motor_dev, MOTOR_MASK_1_4, motor_val, 8) == 8) {
                console_printf("%s[1-4] = %d\n", aux ? "motor_aux" : "motor", val);
            } else {
                console_printf("%s[1-4] set fail\n", aux ? "motor_aux" : "motor", id);
            }
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