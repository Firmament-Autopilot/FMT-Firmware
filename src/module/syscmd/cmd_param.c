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
#include <string.h>

#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

static void show_usage(void)
{
    COMMAND_USAGE("param", "<command> [options]");

    PRINT_STRING("\ncommand:\n");
    SHELL_COMMAND("list", "List groups and parameters.");
    SHELL_COMMAND("set", "Set parameter.");
    SHELL_COMMAND("get", "Get parameter.");
    SHELL_COMMAND("save", "Save parameters to file.");
    SHELL_COMMAND("load", "Load parameters from file.");
}

static void show_list_usage(void)
{
    COMMAND_USAGE("param list", "[options] [group1][group2]...");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
    SHELL_OPTION("-a, --all", "List all parameters");
}

static void show_set_usage(void)
{
    COMMAND_USAGE("param set", "[options] [group] <parameter> <value>");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
}

static void show_get_usage(void)
{
    COMMAND_USAGE("param get", "[options] [group] <parameter>");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
}

static void show_save_usage(void)
{
    COMMAND_USAGE("param save", "[options] [file]");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
}

static void show_load_usage(void)
{
    COMMAND_USAGE("param load", "[options] [file]");

    PRINT_STRING("\noptions:\n");
    SHELL_OPTION("-h, --help", "Show help.");
}

static void disp_param(param_t* p)
{
    if (p == NULL)
        return;

    console_printf("%25s: ", p->name);

    switch (p->type) {
    case PARAM_TYPE_INT8:
        console_printf("%d\n", p->val.i8);
        break;
    case PARAM_TYPE_UINT8:
        console_printf("%u\n", p->val.u8);
        break;
    case PARAM_TYPE_INT16:
        console_printf("%d\n", p->val.i16);
        break;
    case PARAM_TYPE_UINT16:
        console_printf("%u\n", p->val.u16);
        break;
    case PARAM_TYPE_INT32:
        console_printf("%d\n", p->val.i32);
        break;
    case PARAM_TYPE_UINT32:
        console_printf("%u\n", p->val.u32);
        break;
    case PARAM_TYPE_FLOAT:
        console_printf("%f\n", p->val.f);
        break;
    case PARAM_TYPE_DOUBLE:
        console_printf("%lf\n", p->val.lf);
        break;
    default:
        console_printf("unknow param type:%d\n", p->type);
        break;
    }
}

static void list_group(param_group_t* gp)
{
    param_t* p;

    if (gp == NULL)
        return;

    printf("%s:\n", gp->name);
    p = gp->param_list;

    for (int i = 0; i < gp->param_num; i++) {
        disp_param(p++);
    }
}

static void list_groups(void)
{
    param_group_t* gp = param_get_table();

    printf(" parameter groups \n");
    printf("------------------\n");

    for (int i = 0; i < param_get_group_count(); i++) {
        printf("%s\n", gp->name);
        gp++;
    }
}

static void list_all(void)
{
    param_group_t* gp = param_get_table();

    for (int i = 0; i < param_get_group_count(); i++) {
        list_group(gp++);
    }
}

static int list(int argc, struct optparse options)
{
    char* arg;
    int option;
    int all = 0;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { "all", 'a', OPTPARSE_NONE },
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_list_usage();
            return EXIT_SUCCESS;
        case 'a':
            all = 1;
            break;
        case '?':
            printf("%s: %s\n", "param list", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    if (all) {
        /* list all parameters */
        list_all();
    } else {
        if (argc - options.optind > 0) {
            while ((arg = optparse_arg(&options))) {
                /* list group parameters */
                list_group(param_find_group(arg));
            }
        } else {
            /* list all groups */
            list_groups();
        }
    }

    return EXIT_SUCCESS;
}

static int set(int argc, struct optparse options)
{
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_set_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "param set", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    int arg_c = argc - options.optind;

    if (arg_c == 2) {
        char* param_name = optparse_arg(&options);
        char* value = optparse_arg(&options);

        if (param_set_str_val_by_name(param_name, value) != FMT_EOK) {
            printf("fail to set parameter: %s=%s\n", param_name, value);
            return EXIT_FAILURE;
        }
    } else if (arg_c == 3) {
        char* group_name = optparse_arg(&options);
        char* param_name = optparse_arg(&options);
        char* value = optparse_arg(&options);

        if (param_set_str_val_by_full_name(group_name, param_name, value) != FMT_EOK) {
            printf("fail to set parameter: %s.%s=%s\n", group_name, param_name, value);
            return EXIT_FAILURE;
        }
    } else {
        show_set_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int get(int argc, struct optparse options)
{
    int option;
    struct optparse_long longopts[] = {
        { "help", 'h', OPTPARSE_NONE },
        { NULL } /* Don't remove this line */
    };

    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'h':
            show_get_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "param get", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    int arg_c = argc - options.optind;

    if (arg_c == 1) {
        char* param_name = optparse_arg(&options);

        param_t* param = param_get_by_name(param_name);
        if (param != NULL) {
            disp_param(param);
        } else {
            printf("fail to find parameter: %s\n", param_name);
            return EXIT_FAILURE;
        }
    } else if (arg_c == 2) {
        char* group_name = optparse_arg(&options);
        char* param_name = optparse_arg(&options);

        param_t* param = param_get_by_full_name(group_name, param_name);
        if (param != NULL) {
            disp_param(param);
        } else {
            printf("fail to find parameter: %s.%s\n", group_name, param_name);
            return EXIT_FAILURE;
        }
    } else {
        show_get_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int save(struct optparse options)
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
            show_save_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "param save", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    arg = optparse_arg(&options);
    if (param_save(arg) == FMT_EOK) {
        printf("parameter save to %s\n", (arg != NULL) ? arg : PARAM_FILE_NAME);
    } else {
        printf("parameter save fail\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int load(struct optparse options)
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
            show_load_usage();
            return EXIT_SUCCESS;
        case '?':
            printf("%s: %s\n", "param load", options.errmsg);
            return EXIT_FAILURE;
        }
    }

    arg = optparse_arg(&options);
    if (param_load(arg) == FMT_EOK) {
        printf("parameter load from %s\n", (arg != NULL) ? arg : PARAM_FILE_NAME);
    } else {
        printf("parameter load fail\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int cmd_param(int argc, char** argv)
{
    char* arg;
    struct optparse options;
    int res = EXIT_SUCCESS;

    optparse_init(&options, argv);

    arg = optparse_arg(&options);
    if (arg) {
        if (STRING_COMPARE(arg, "list")) {
            res = list(argc, options);
        } else if (STRING_COMPARE(arg, "set")) {
            res = set(argc, options);
        } else if (STRING_COMPARE(arg, "get")) {
            res = get(argc, options);
        } else if (STRING_COMPARE(arg, "save")) {
            res = save(options);
        } else if (STRING_COMPARE(arg, "load")) {
            res = load(options);
        } else {
            show_usage();
        }
    } else {
        show_usage();
    }

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_param, __cmd_param, configure system parameter);