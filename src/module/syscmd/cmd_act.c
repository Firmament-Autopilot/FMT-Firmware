/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include "hal/actuator/actuator.h"
#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

MCN_DECLARE(control_output);
MCN_DECLARE(fms_output);

static void show_usage(void)
{
    COMMAND_USAGE("act", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("get", "Get actuator channel value.");
    SHELL_COMMAND("set", "Set actuator channel value.");
}

static void show_set_usage(void)
{
    COMMAND_USAGE("act set", "[options] <channel value>");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
    SHELL_OPTION("-a, --all", "Set all actuator channels to the same value.");
    SHELL_OPTION("-d, --device", "Actuator device.");
    SHELL_OPTION("-c, --channel", "Selected channel in hex, e.g, f means channel 1 to channel 4.");
}

static void show_get_usage(void)
{
    COMMAND_USAGE("act get", "[options]");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
    SHELL_OPTION("-d, --device", "Actuator device.");
    SHELL_OPTION("-c, --channel", "Selected channel in hex, e.g, f means channel 1 to channel 4.");
}

static rt_size_t act_device_write(actuator_dev_t act_dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    rt_size_t ret = size;

    /* Suspend controller output */
    mcn_suspend(MCN_HUB(control_output));

    if (act_dev->config.protocol == ACT_PROTOCOL_PWM) {
        ret = rt_device_write(&act_dev->parent, chan_sel, chan_val, size);
    } else if (act_dev->config.protocol == ACT_PROTOCOL_DSHOT) {
        printf("Press any key to stop...\n");
        while (1) {
            /* type any key to exit */
            if (syscmd_has_input()) {
                syscmd_flush();
                break;
            }

            if (rt_device_write(&act_dev->parent, chan_sel, chan_val, size) != size) {
                printf("dshot write failed!\n");
                ret = 0;
                break;
                ;
            }

            systime_msleep(10);
        }
    } else {
        /* Unknown protocol */
        ret = 0;
    }

    /* Resume controller output */
    mcn_resume(MCN_HUB(control_output));

    return ret;
}

static int set(int argc, struct optparse options)
{
    char* arg;
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "all", 'a', OPTPARSE_NONE },
        { "device", 'd', OPTPARSE_REQUIRED },
        { "channel", 'c', OPTPARSE_REQUIRED },
        { NULL } /* Don't remove this line */
    };

    uint8_t all = 0;
    uint16_t chan_sel = 0;
    uint16_t chan_val[16] = { 0 };
    actuator_dev_t dev = NULL;

    FMS_Out_Bus fms_out;
    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) == FMT_EOK) {
        if (fms_out.status != VehicleStatus_Disarm) {
            printf("act set command only allowed when disarmed\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("failed to get vehicle status\n");
        return EXIT_FAILURE;
    }

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_set_usage();
            return EXIT_SUCCESS;
        case 'a':
            all = 1;
            chan_sel = 0xFFFF;
            break;
        case 'd':
            dev = (actuator_dev_t)rt_device_find(options.optarg);
            if (dev == NULL) {
                printf("Can not find device:%s\n", options.optarg);
                return EXIT_FAILURE;
            }
            break;
        case 'c':
            chan_sel = math_hex2dec(options.optarg);
            break;
        case '?':
            console_printf("%s: %s\n", "act write", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if (dev == NULL || chan_sel == 0) {
        show_set_usage();
        return EXIT_FAILURE;
    }

    int arg_c = argc - options.optind;
    int chan_num = 0;
    uint16_t val;

    for (int i = 0; i < 16; i++) {
        if (chan_sel & (1 << i)) {
            chan_num++;
        }
    }

    if ((all && arg_c != 1) || (all == 0 && arg_c != chan_num)) {
        show_set_usage();
        return EXIT_FAILURE;
    }

    if (all) {
        arg = optparse_arg(&options);
        if (arg == NULL) {
            show_set_usage();
            return EXIT_FAILURE;
        }
        val = atoi(arg);

        for (int i = 0; i < 16; i++) {
            if (val < dev->range[0] || val > dev->range[1]) {
                printf("Invalid value! The allowed range is [%d, %d]\n", dev->range[0], dev->range[1]);
                return EXIT_FAILURE;
            }
            chan_val[i] = val;
        }

        act_device_write(dev, chan_sel, chan_val, 16);
    } else {
        uint8_t index = 0;
        for (int i = 0; i < 16; i++) {
            if (chan_sel & (1 << i)) {
                if ((arg = optparse_arg(&options)) == NULL) {
                    show_set_usage();
                    return EXIT_FAILURE;
                }

                val = atoi(arg);
                if (val < dev->range[0] || val > dev->range[1]) {
                    printf("the allowed range is [%d, %d]\n", dev->range[0], dev->range[1]);
                    return EXIT_FAILURE;
                }
                chan_val[index++] = val;
            }
        }

        act_device_write(dev, chan_sel, chan_val, index);
    }

    return EXIT_SUCCESS;
}

static int get(struct optparse options)
{
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "device", 'd', OPTPARSE_REQUIRED },
        { "channel", 'c', OPTPARSE_REQUIRED },
        { NULL } /* Don't remove this line */
    };

    uint16_t chan_sel = 0;
    uint16_t chan_val[16] = { 0 };
    rt_device_t dev = NULL;

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_get_usage();
            return EXIT_SUCCESS;
        case 'd':
            dev = rt_device_find(options.optarg);
            if (dev == NULL) {
                printf("Can not find device:%s\n", options.optarg);
                return EXIT_FAILURE;
            }
            break;
        case 'c':
            chan_sel = math_hex2dec(options.optarg);
            break;
        case '?':
            console_printf("%s: %s\n", "act write", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if (dev == NULL || chan_sel == 0) {
        show_get_usage();
        return EXIT_FAILURE;
    }

    uint8_t index = 0;
    rt_size_t size;
    for (int i = 0; i < 16; i++) {
        if (chan_sel & (1 << i)) {
            index++;
        }
    }
    size = index;

    if (rt_device_read(dev, chan_sel, chan_val, size) != size) {
        printf("Actuator channel read fail\n");
        return EXIT_FAILURE;
    }

    index = 0;
    for (int i = 0; i < 16; i++) {
        if (chan_sel & (1 << i)) {
            printf("channel[%d]=%d ", i, chan_val[index++]);
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}

int cmd_act(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "get")) {
            res = get(options);
        } else if (STRING_COMPARE(arg, "set")) {
            res = set(argc, options);
        } else {
            show_usage();
        }
    } else {
        show_usage();
    }

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_act, __cmd_act, Actuator operations);