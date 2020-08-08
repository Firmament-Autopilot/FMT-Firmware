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

#include "module/syscmd/syscmd.h"
#include "module/system/statistic.h"

extern long list_device(void);
extern long list_timer(void);
extern long list_mempool(void);
extern long list_msgqueue(void);
extern long list_mailbox(void);
extern long list_mutex(void);
extern long list_event(void);
extern long list_sem(void);
extern long list_thread(void);
extern void list_mem(void);
extern int df(const char* path);

static void show_usage(void)
{
    PRINT_USAGE(sys, ACTION);

    PRINT_STRING("\nAction:\n");
    PRINT_ACTION("status", 13, "Show system status.");
    PRINT_ACTION("list_device", 13, "List device in system.");
    PRINT_ACTION("list_timer", 13, "List timer in system.");
    PRINT_ACTION("list_mempool", 13, "List memory pool in system.");
    PRINT_ACTION("list_msgqueue", 13, "List message queue in system.");
    PRINT_ACTION("list_mailbox", 13, "List mail box in system.");
    PRINT_ACTION("list_mutex", 13, "List mutex in system.");
    PRINT_ACTION("list_event", 13, "List event in system.");
    PRINT_ACTION("list_sem", 13, "List semaphore in system.");
    PRINT_ACTION("list_thread", 13, "List thread.");
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
        return 0;
    }

    if (STRING_COMPARE(argv[1], "status")) {
        console_println("cpu usage: %.2f%%\n", sysstat_get_cpu_usage());
        list_mem();
        console_printf("\n");
        df("/");
    } else if (STRING_COMPARE(argv[1], "list_device")) {
        list_device();
    } else if (STRING_COMPARE(argv[1], "list_timer")) {
        list_timer();
    } else if (STRING_COMPARE(argv[1], "list_mempool")) {
        list_mempool();
    } else if (STRING_COMPARE(argv[1], "list_msgqueue")) {
        list_msgqueue();
    } else if (STRING_COMPARE(argv[1], "list_mailbox")) {
        list_mailbox();
    } else if (STRING_COMPARE(argv[1], "list_mutex")) {
        list_mutex();
    } else if (STRING_COMPARE(argv[1], "list_event")) {
        list_event();
    } else if (STRING_COMPARE(argv[1], "list_sem")) {
        list_sem();
    } else if (STRING_COMPARE(argv[1], "list_thread")) {
        list_thread();
    } else {
        show_usage();
    }

    return 0;
}

int cmd_sys(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_sys, __cmd_sys, display system information);