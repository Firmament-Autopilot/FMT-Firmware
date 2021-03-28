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

#include "module/syscmd/syscmd.h"

static int _name_maxlen(const char* title)
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

static void _list_topics(void)
{
    char* title_1 = "Topic";
    char* title_2 = "#SUB";
    char* title_3 = "Freq(Hz)";
    char* title_4 = "Echo";
    char* title_5 = "Suspend";
    uint32_t title1_len = _name_maxlen(title_1) + 2;
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

static void _suspend_topic(const char* topic_name, bool suspend)
{
    McnList_t ite = mcn_get_list();
    McnHub_t target_hub = NULL;
    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        if (strcmp(hub->obj_name, topic_name) == 0) {
            target_hub = hub;
            break;
        }
    }

    if (target_hub == NULL) {
        console_printf("can not find topic %s\n", topic_name);
        return;
    }

    if (suspend == true) {
        mcn_suspend(target_hub);
    } else {
        mcn_resume(target_hub);
    }
}

static void _echo_topic(const char* topic_name, int optc, optv_t* optv)
{
    uint32_t cnt = 0xFFFFFFFF;
    uint32_t period = 500;

    /* handle operation */
    for (uint16_t i = 0; i < optc; i++) {
        if (STRING_COMPARE(optv[i].opt, "-c") || STRING_COMPARE(optv[i].opt, "--cnt")) {
            if (!syscmd_is_num(optv[i].val))
                continue;

            cnt = atoi(optv[i].val);
        }

        if (STRING_COMPARE(optv[i].opt, "-p") || STRING_COMPARE(optv[i].opt, "--period")) {
            if (!syscmd_is_num(optv[i].val))
                continue;

            period = atoi(optv[i].val);
        }
    }

    McnList_t ite = mcn_get_list();
    McnHub_t target_hub = NULL;
    while (1) {
        McnHub_t hub = mcn_iterate(&ite);
        if (hub == NULL) {
            break;
        }
        if (strcmp(hub->obj_name, topic_name) == 0) {
            target_hub = hub;
            break;
        }
    }

    if (target_hub == NULL) {
        console_printf("can not find topic %s\n", topic_name);
        return;
    }

    if (target_hub->echo == NULL) {
        console_printf("there is no topic echo function defined!\n");
        return;
    }

    McnNode_t node = mcn_subscribe(target_hub, NULL, NULL);

    if (node == NULL) {
        console_printf("mcn subscribe fail\n");
        return;
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
    }
}

static void show_usage(void)
{
    PRINT_USAGE(mcn, [OPTION] ACTION[ARGS]);

    PRINT_STRING("\nAction:\n");
    PRINT_ACTION("list", 4, "List all uMCN topics.");
    PRINT_ACTION("echo", 4, "Echo a uMCN topic.");
    PRINT_ACTION("suspend", 7, "Suspend a uMCN topic.");
    PRINT_ACTION("resume", 6, "Resume a uMCN topic.");

    PRINT_STRING("\nOption:\n");
    PRINT_ACTION("-c, --cnt", 12, "Set topic echo count, e.g, -c=10 will echo 10 times.");
    PRINT_ACTION("-p, --period", 12, "Set topic echo period(ms), -p=0 inherits topic period. The default period is 500ms.");
}

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    /* handle operation */
    for (uint16_t i = 0; i < optc; i++) {
        if (STRING_COMPARE(optv[i].opt, "-h") || STRING_COMPARE(optv[i].opt, "--help")) {
            show_usage();
            return 0;
        }
    }

    if (argc < 2) {
        show_usage();
        return -1;
    }

    if (STRING_COMPARE(argv[1], "list")) {
        _list_topics();
    } else if (STRING_COMPARE(argv[1], "echo")) {
        if (argc < 3) {
            console_printf("usage: mcn echo <topic>\n");
            return -1;
        }

        _echo_topic(argv[2], optc, optv);
    } else if (STRING_COMPARE(argv[1], "suspend")) {
        if (argc < 3) {
            console_printf("usage: mcn suspend <topic>\n");
            return -1;
        }
        _suspend_topic(argv[2], true);
    } else if (STRING_COMPARE(argv[1], "resume")) {
        if (argc < 3) {
            console_printf("usage: mcn resume <topic>\n");
            return -1;
        }
        _suspend_topic(argv[2], false);
    } else {
        show_usage();
    }

    return 0;
}

int cmd_mcn(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_mcn, __cmd_mcn, uMCN topics operations);