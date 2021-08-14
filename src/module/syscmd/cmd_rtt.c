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

#include "module/shell_cmd/optparse.h"
#include "module/shell_cmd/syscmd.h"

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

static void show_usage(void)
{
    COMMAND_USAGE("rtt", "<command>");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("list_device", "List device in system.");
    SHELL_COMMAND("list_timer", "List timer in system.");
    SHELL_COMMAND("list_mempool", "List memory pool in system.");
    SHELL_COMMAND("list_msgqueue", "List message queue in system.");
    SHELL_COMMAND("list_mailbox", "List mail box in system.");
    SHELL_COMMAND("list_mutex", "List mutex in system.");
    SHELL_COMMAND("list_event", "List event in system.");
    SHELL_COMMAND("list_sem", "List semaphore in system.");
    SHELL_COMMAND("list_thread", "List thread.");
}

int cmd_rtt(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "list_device")) {
            list_device();
        } else if (STRING_COMPARE(arg, "list_timer")) {
            list_timer();
        } else if (STRING_COMPARE(arg, "list_mempool")) {
            list_mempool();
        } else if (STRING_COMPARE(arg, "list_msgqueue")) {
            list_msgqueue();
        } else if (STRING_COMPARE(arg, "list_mailbox")) {
            list_mailbox();
        } else if (STRING_COMPARE(arg, "list_mutex")) {
            list_mutex();
        } else if (STRING_COMPARE(arg, "list_event")) {
            list_event();
        } else if (STRING_COMPARE(arg, "list_sem")) {
            list_sem();
        } else if (STRING_COMPARE(arg, "list_thread")) {
            list_thread();
        } else {
            show_usage();
        }
    } else {
        show_usage();
    }

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_rtt, __cmd_rtt, rt-thread commands);