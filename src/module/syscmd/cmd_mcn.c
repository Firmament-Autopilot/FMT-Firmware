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
#include <string.h>

#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

static void show_usage(void)
{
    COMMAND_USAGE("mcn", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("list", "List all uMCN topics.");
    SHELL_COMMAND("echo", "Echo a uMCN topic.");
    SHELL_COMMAND("suspend", "Suspend a uMCN topic.");
    SHELL_COMMAND("resume", "Resume a uMCN topic.");
}

static void show_echo_usage(void)
{
    COMMAND_USAGE("mcn echo", "<topic> [options]");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-n, --number", "Set topic echo number, e.g, -n 10 will echo 10 times.");
    SHELL_OPTION("-p, --period", "Set topic echo period (ms), -p 0 inherits topic period");
}

static void show_suspend_usage(void)
{
    COMMAND_USAGE("mcn suspend", "<topic>");
}

static void show_resume_usage(void)
{
    COMMAND_USAGE("mcn resume", "<topic>");
}

static int name_maxlen(const char* title)
{
    int max_len = strlen(title);

    McnList_t ite = mcn_get_list();
    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        int len = strlen(hub->obj_name);

        if (len > max_len) {
            max_len = len;
        }
    }

    return max_len;
}

static void list_topic(void)
{
    char* title_1 = "Topic";
    char* title_2 = "#SUB";
    char* title_3 = "Freq(Hz)";
    char* title_4 = "Echo";
    char* title_5 = "Suspend";
    uint32_t title1_len = name_maxlen(title_1) + 2;
    uint32_t title2_len = strlen(title_2) + 2;
    uint32_t title3_len = strlen(title_3) + 2;
    uint32_t title4_len = strlen(title_4) + 2;
    uint32_t title5_len = strlen(title_5) + 2;

    syscmd_printf(' ', title1_len, SYSCMD_ALIGN_MIDDLE, title_1);
    syscmd_putc(' ', 1);
    syscmd_printf(' ', title2_len, SYSCMD_ALIGN_MIDDLE, title_2);
    syscmd_putc(' ', 1);
    syscmd_printf(' ', title3_len, SYSCMD_ALIGN_MIDDLE, title_3);
    syscmd_putc(' ', 1);
    syscmd_printf(' ', title4_len, SYSCMD_ALIGN_MIDDLE, title_4);
    syscmd_putc(' ', 1);
    syscmd_printf(' ', title5_len, SYSCMD_ALIGN_MIDDLE, title_5);
    console_printf("\n");

    syscmd_putc('-', title1_len);
    syscmd_putc(' ', 1);
    syscmd_putc('-', title2_len);
    syscmd_putc(' ', 1);
    syscmd_putc('-', title3_len);
    syscmd_putc(' ', 1);
    syscmd_putc('-', title4_len);
    syscmd_putc(' ', 1);
    syscmd_putc('-', title5_len);
    console_printf("\n");

    McnList_t ite = mcn_get_list();
    for (McnHub_t hub = mcn_iterate(&ite); hub != NULL; hub = mcn_iterate(&ite)) {
        syscmd_printf(' ', title1_len, SYSCMD_ALIGN_LEFT, hub->obj_name);
        syscmd_putc(' ', 1);
        syscmd_printf(' ', title2_len, SYSCMD_ALIGN_MIDDLE, "%d", (int)hub->link_num);
        syscmd_putc(' ', 1);
        syscmd_printf(' ', title3_len, SYSCMD_ALIGN_MIDDLE, "%.1f", hub->freq);
        syscmd_putc(' ', 1);
        syscmd_printf(' ', title4_len, SYSCMD_ALIGN_MIDDLE, "%s", hub->echo ? "true" : "false");
        syscmd_putc(' ', 1);
        syscmd_printf(' ', title5_len, SYSCMD_ALIGN_MIDDLE, "%s", hub->suspend ? "true" : "false");
        console_printf("\n");
    }
}

static int suspend_topic(struct optparse options)
{
    char* arg;
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_suspend_usage();
            return EXIT_SUCCESS;
        case '?':
            console_printf("%s: %s\n", "mcn echo", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_suspend_usage();
        return EXIT_FAILURE;
    }

    McnList_t ite = mcn_get_list();
    McnHub_t target_hub = NULL;

    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        if (strcmp(hub->obj_name, arg) == 0) {
            target_hub = hub;
            break;
        }
    }

    if (target_hub == NULL) {
        console_printf("can not find topic %s\n", arg);
        return EXIT_FAILURE;
    }

    mcn_suspend(target_hub);

    return EXIT_SUCCESS;
}

static int resume_topic(struct optparse options)
{
    char* arg;
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_resume_usage();
            return EXIT_SUCCESS;
        case '?':
            console_printf("%s: %s\n", "mcn echo", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_resume_usage();
        return EXIT_FAILURE;
    }

    McnList_t ite = mcn_get_list();
    McnHub_t target_hub = NULL;

    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        if (strcmp(hub->obj_name, arg) == 0) {
            target_hub = hub;
            break;
        }
    }

    if (target_hub == NULL) {
        console_printf("can not find topic %s\n", arg);
        return EXIT_FAILURE;
    }

    mcn_resume(target_hub);

    return EXIT_SUCCESS;
}

static int echo_topic(struct optparse options)
{
    char* arg;
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "number", 'n', OPTPARSE_REQUIRED },
        { "period", 'p', OPTPARSE_REQUIRED },
        { NULL } /* Don't remove this line */
    };

    uint32_t cnt = 0xFFFFFFFF;
    uint32_t period = 500;

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_echo_usage();
            return EXIT_SUCCESS;
        case 'n':
            cnt = atoi(options.optarg);
            break;
        case 'p':
            period = atoi(options.optarg);
            break;
        case '?':
            console_printf("%s: %s\n", "mcn echo", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_echo_usage();
        return EXIT_FAILURE;
    }

    McnList_t ite = mcn_get_list();
    McnHub_t target_hub = NULL;
    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        if (strcmp(hub->obj_name, arg) == 0) {
            target_hub = hub;
            break;
        }
    }

    if (target_hub == NULL) {
        console_printf("can not find topic %s\n", arg);
        return EXIT_FAILURE;
    }

    if (target_hub->echo == NULL) {
        console_printf("there is no topic echo function defined!\n");
        return EXIT_FAILURE;
    }

    McnNode_t node = mcn_subscribe(target_hub, NULL, NULL);

    if (node == NULL) {
        console_printf("mcn subscribe fail\n");
        return EXIT_FAILURE;
    }

    while (cnt) {
        /* type any key to exit */
        if (syscmd_has_input()) {
            syscmd_flush();
            break;
        }

        if (mcn_poll(node)) {
            /* call custom echo function */
            target_hub->echo(target_hub);
            mcn_node_clear(node);
            cnt--;
        }

        if (period) {
            sys_msleep(period);
        }
    }

    if (mcn_unsubscribe(target_hub, node) != FMT_EOK) {
        console_printf("mcn unsubscribe fail\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int cmd_mcn(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "list")) {
            list_topic();
        } else if (STRING_COMPARE(arg, "echo")) {
            res = echo_topic(options);
        } else if (STRING_COMPARE(arg, "suspend")) {
            res = suspend_topic(options);
        } else if (STRING_COMPARE(arg, "resume")) {
            res = resume_topic(options);
        } else {
            show_usage();
        }
    } else {
        show_usage();
    }

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_mcn, __cmd_mcn, uMCN topics operations);