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

#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

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
    rt_device_t dev = NULL;

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
        show_set_usage();
        return EXIT_FAILURE;
    }

    int arg_c = argc - options.optind;
    int chan_num = 0;

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
        uint16_t val;
        arg = optparse_arg(&options);
        if (arg == NULL) {
            show_set_usage();
            return EXIT_FAILURE;
        }
        val = atoi(arg);

        for (int i = 0; i < 16; i++) {
            chan_val[i] = val;
        }

        rt_device_write(dev, chan_sel, chan_val, 16);
    } else {
        uint8_t index = 0;
        for (int i = 0; i < 16; i++) {
            if (chan_sel & (1 << i)) {
                if ((arg = optparse_arg(&options)) == NULL) {
                    show_set_usage();
                    return EXIT_FAILURE;
                }
                chan_val[index++] = atoi(arg);
            }
        }

        rt_device_write(dev, chan_sel, chan_val, index);
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