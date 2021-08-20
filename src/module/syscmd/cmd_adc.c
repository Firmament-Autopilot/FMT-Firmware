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
    COMMAND_USAGE("adc", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("read", "Read adc channel value.");
}

static void show_read_usage(void)
{
    COMMAND_USAGE("adc read", "-d <device> -c <channel>");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-d, --device", "ADC device.");
    SHELL_OPTION("-c, --channel", "ADC channel to read.");
}

static int read_channel(struct optparse options)
{
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "device", 'd', OPTPARSE_REQUIRED },
        { "channel", 'c', OPTPARSE_REQUIRED },
        { NULL } /* Don't remove this line */
    };
    char dev_name[RT_NAME_MAX] = "";
    uint32_t channel = 0xFF;

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'd':
            strcpy(dev_name, options.optarg);
            break;
        case 'c':
            channel = atoi(options.optarg);
            break;
        case 'h':
            show_read_usage();
            return EXIT_SUCCESS;
        case '?':
            console_printf("%s: %s\n", "adc read", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if (strlen(dev_name) == 0 || channel == 0xFF) {
        show_read_usage();
        return EXIT_FAILURE;
    }

    rt_device_t adc_dev = rt_device_find(dev_name);
    uint32_t mVolt;

    if (adc_dev == NULL) {
        printf("Can not find adc device %s\n", dev_name);
        return EXIT_FAILURE;
    }

    if (rt_device_open(adc_dev, RT_DEVICE_FLAG_RDONLY) != RT_EOK) {
        printf("Fail to open adc device %s\n", dev_name);
        return EXIT_FAILURE;
    }

    if (rt_device_read(adc_dev, channel, &mVolt, sizeof(mVolt)) != sizeof(mVolt)) {
        printf("Fail to read %s channel %u\n", dev_name, channel);
        return EXIT_FAILURE;
    }

    if (rt_device_close(adc_dev) != RT_EOK) {
        printf("Fail to close adc device %s\n", dev_name);
        return EXIT_FAILURE;
    }

    printf("%s CH%u: %.3f V\n", dev_name, channel, mVolt * 1e-3);

    return EXIT_SUCCESS;
}

int cmd_adc(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "read")) {
            res = read_channel(options);
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
FINSH_FUNCTION_EXPORT_ALIAS(cmd_adc, __cmd_adc, adc device operations);