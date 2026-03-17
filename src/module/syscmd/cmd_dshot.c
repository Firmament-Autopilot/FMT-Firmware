/* DShot shell command. */

#include <firmament.h>
#include <stdlib.h>
#include <string.h>

#include "FMS.h"
#include "hal/actuator/actuator.h"
#include "model/fms/fms_interface.h"
#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

MCN_DECLARE(fms_output);
MCN_DECLARE(control_output);

static void show_usage(void)
{
    COMMAND_USAGE("dshot", "<command> [options]");
    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("reverse", "Set spin direction reversed");
    SHELL_COMMAND("normal", "Set spin direction normal");
    SHELL_COMMAND("save", "Save settings to ESC");
    SHELL_COMMAND("beep1...5", "Make ESC beep");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
    SHELL_OPTION("-a, --all", "Select all channels of the device.");
    SHELL_OPTION("-d, --device", "Actuator device, default: main_out.");
    SHELL_OPTION("-c, --channel", "Channel mask in hex, e.g. f selects channels 1-4.");
}

int cmd_dshot(int argc, char** argv)
{
    (void)argc;
    char* arg;
    struct optparse options;
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "all", 'a', OPTPARSE_NONE },
        { "device", 'd', OPTPARSE_REQUIRED },
        { "channel", 'c', OPTPARSE_REQUIRED },
        { NULL } /* Don't remove this line */
    };

    if (argc > 1 && (STRING_COMPARE(argv[1], "-h") || STRING_COMPARE(argv[1], "--help"))) {
        show_usage();
        return EXIT_SUCCESS;
    }

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg == NULL) {
        show_usage();
        return EXIT_SUCCESS;
    }

    const char* cmd = arg;

    uint16_t chan_sel = 0;
    const char* dev_name = "main_out";

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_usage();
            return EXIT_SUCCESS;
        case 'a':
            chan_sel = 0xFFFF;
            break;
        case 'd':
            dev_name = options.optarg;
            break;
        case 'c':
            chan_sel = math_hex2dec(options.optarg);
            break;
        case '?':
            console_printf("%s: %s\n", "dshot", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if (chan_sel == 0) {
        console_printf("Please specify channels with -c or use -a\n");
        return EXIT_FAILURE;
    }

    FMS_Out_Bus fms_out;
    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) == FMT_EOK) {
        if (fms_out.status != VehicleStatus_Disarm) {
            console_printf("dshot commands are only allowed when disarmed\n");
            return EXIT_FAILURE;
        }
    } else {
        console_printf("failed to get vehicle status\n");
        return EXIT_FAILURE;
    }

    rt_device_t dev = rt_device_find(dev_name);
    if (!dev) {
        console_printf("device %s not found\n", dev_name);
        return EXIT_FAILURE;
    }

    actuator_dev_t act = (actuator_dev_t)dev;
    if (act->config.protocol != ACT_PROTOCOL_DSHOT) {
        console_printf("device %s protocol is not dshot\n", dev_name);
        return EXIT_FAILURE;
    }

    chan_sel &= act->chan_mask;
    if (chan_sel == 0) {
        console_printf("no valid channels selected on %s\n", dev_name);
        return EXIT_FAILURE;
    }

    struct dshot_command c = { 0 };
    uint16_t cmd_val = 0;
    c.chan_mask = chan_sel;
    c.size = 0;

    if (STRING_COMPARE(cmd, "reverse")) {
        cmd_val = DSHOT_CMD_SPIN_DIRECTION_2;
        c.repeat = 10;
        c.wait_ms = 0;
    } else if (STRING_COMPARE(cmd, "normal")) {
        cmd_val = DSHOT_CMD_SPIN_DIRECTION_1;
        c.repeat = 10;
        c.wait_ms = 0;
    } else if (STRING_COMPARE(cmd, "save")) {
        cmd_val = DSHOT_CMD_SAVE_SETTINGS;
        c.repeat = 10;
        c.wait_ms = 35;
    } else if (STRING_COMPARE(cmd, "beep1")) {
        cmd_val = DSHOT_CMD_BEEP1;
        c.repeat = 1;
        c.wait_ms = 400;
    } else if (STRING_COMPARE(cmd, "beep2")) {
        cmd_val = DSHOT_CMD_BEEP2;
        c.repeat = 1;
        c.wait_ms = 400;
    } else if (STRING_COMPARE(cmd, "beep3")) {
        cmd_val = DSHOT_CMD_BEEP3;
        c.repeat = 1;
        c.wait_ms = 400;
    } else if (STRING_COMPARE(cmd, "beep4")) {
        cmd_val = DSHOT_CMD_BEEP4;
        c.repeat = 1;
        c.wait_ms = 400;
    } else if (STRING_COMPARE(cmd, "beep5")) {
        cmd_val = DSHOT_CMD_BEEP5;
        c.repeat = 1;
        c.wait_ms = 400;
    } else {
        console_printf("unknown command: %s\n", cmd);
        return EXIT_FAILURE;
    }

    for (uint16_t i = 0; i < 16; i++) {
        if (c.chan_mask & (1 << i)) {
            c.value[i] = cmd_val;
            c.size++;
        } else {
            c.value[i] = 0;
        }
    }

    /* Suspend controller output */
    mcn_suspend(MCN_HUB(control_output));

    for (uint16_t i = 0; i < c.repeat; i++) {
        if (rt_device_control(dev, ACT_CMD_DSHOT_SEND, &c) != RT_EOK) {
            console_printf("failed to send dshot command\n");
            /* Resume controller output */
            mcn_resume(MCN_HUB(control_output));
            return EXIT_FAILURE;
        }
        systime_msleep(5);
    }
    systime_msleep(c.wait_ms);

    /* Resume controller output */
    mcn_resume(MCN_HUB(control_output));

    console_printf("dshot %s sent to %s channel mask 0x%X\n", cmd, dev_name, c.chan_mask);

    return EXIT_SUCCESS;
}

FINSH_FUNCTION_EXPORT_ALIAS(cmd_dshot, __cmd_dshot, DShot ESC commands);
