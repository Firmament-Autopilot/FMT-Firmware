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
#include "module/task_manager/task_manager.h"

static void show_usage(void)
{
    COMMAND_USAGE("task", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("list", "List all tasks.");
    SHELL_COMMAND("start", "start a task.");
    SHELL_COMMAND("suspend", "suspend a task.");
    SHELL_COMMAND("resume", "resume a task.");
    SHELL_COMMAND("kill", "kill a task.");
}

static void show_start_usage(void)
{
    COMMAND_USAGE("task start", "<task_name>");
}

static void show_suspend_usage(void)
{
    COMMAND_USAGE("task suspend", "<task_name>");
}

static void show_resume_usage(void)
{
    COMMAND_USAGE("task resume", "<task_name>");
}

static void show_kill_usage(void)
{
    COMMAND_USAGE("task kill", "<task_name>");
}

static int name_maxlen(const char* title)
{
    int max_len = strlen(title);
    uint32_t task_num = get_task_num();
    fmt_task_desc_t task_table = get_task_table();

    for (uint32_t i = 0; i < task_num; i++) {
        int len = strlen(task_table[i].name);

        if (len > max_len) {
            max_len = len;
        }
    }

    return max_len;
}

static int _list(struct optparse options)
{
    uint32_t max_len = name_maxlen("Task") + 2;
    uint32_t task_num = get_task_num();
    fmt_task_desc_t task_table = get_task_table();
    char* status_str[] = {
        "IDLE", "FAIL", "READY", "RUNNING", "SUSPEND", "ZOMBIE"
    };
    uint8_t status;

    rt_kprintf("%-*.s    Status\n", max_len - 2, "Topic");
    syscmd_putc('-', max_len);
    printf(" ---------\n");

    for (uint32_t i = 0; i < task_num; i++) {
        status = get_task_status(task_table[i].name);

        syscmd_printf(' ', max_len, SYSCMD_ALIGN_LEFT, task_table[i].name);
        printf(" ");
        syscmd_printf(' ', strlen(status_str[status]) + 2, SYSCMD_ALIGN_MIDDLE, "%s", status_str[status]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}

static int _start(struct optparse options)
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
            show_start_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "task start", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_start_usage();
        return EXIT_FAILURE;
    }

    uint32_t task_id = get_task_id(arg);
    if (task_id == -1) {
        printf("wrong task name:%s\n", arg);
        return EXIT_FAILURE;
    }

    if (start_task(task_id) != FMT_EOK) {
        printf("fail to start task!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int _suspend(struct optparse options)
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
            printf("%s: %s\n", "task suspend", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_suspend_usage();
        return EXIT_FAILURE;
    }

    uint32_t task_id = get_task_id(arg);
    if (task_id == -1) {
        printf("wrong task name:%s\n", arg);
        return EXIT_FAILURE;
    }

    if (suspend_task(task_id, 1000) != FMT_EOK) {
        printf("fail to suspend task!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int _resume(struct optparse options)
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
            printf("%s: %s\n", "task resume", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_resume_usage();
        return EXIT_FAILURE;
    }

    uint32_t task_id = get_task_id(arg);
    if (task_id == -1) {
        printf("wrong task name:%s\n", arg);
        return EXIT_FAILURE;
    }

    if (resume_task(task_id) != FMT_EOK) {
        printf("fail to resume task!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int _kill(struct optparse options)
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
            show_kill_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "task kill", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if ((arg = optparse_arg(&options)) == NULL) {
        show_kill_usage();
        return EXIT_FAILURE;
    }

    uint32_t task_id = get_task_id(arg);
    if (task_id == -1) {
        printf("wrong task name:%s\n", arg);
        return EXIT_FAILURE;
    }

    if (kill_task(task_id) != FMT_EOK) {
        printf("fail to kill task!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int cmd_task(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "list")) {
            res = _list(options);
        } else if (STRING_COMPARE(arg, "start")) {
            res = _start(options);
        } else if (STRING_COMPARE(arg, "suspend")) {
            res = _suspend(options);
        } else if (STRING_COMPARE(arg, "resume")) {
            res = _resume(options);
        } else if (STRING_COMPARE(arg, "kill")) {
            res = _kill(options);
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
FINSH_FUNCTION_EXPORT_ALIAS(cmd_task, __cmd_task, task manager operations);