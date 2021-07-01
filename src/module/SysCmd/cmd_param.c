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

static void _disp_param(param_t* p)
{
    if (p == NULL)
        return;

    console_printf("%20s: ", p->name);

    if (p->type == PARAM_TYPE_INT8) {
        console_printf("%d\n", p->val.i8);
    }

    if (p->type == PARAM_TYPE_UINT8) {
        console_printf("%d\n", p->val.u8);
    }

    if (p->type == PARAM_TYPE_INT16) {
        console_printf("%d\n", p->val.i16);
    }

    if (p->type == PARAM_TYPE_UINT16) {
        console_printf("%d\n", p->val.u16);
    }

    if (p->type == PARAM_TYPE_INT32) {
        console_printf("%d\n", p->val.i32);
    }

    if (p->type == PARAM_TYPE_UINT32) {
        console_printf("%d\n", p->val.u32);
    }

    if (p->type == PARAM_TYPE_FLOAT) {
        console_printf("%f\n", p->val.f);
    }

    if (p->type == PARAM_TYPE_DOUBLE) {
        console_printf("%lf\n", p->val.lf);
    }
}

static void _list_groups(void)
{
    param_group_t* gp = (param_group_t*)&param_list;

    syscmd_printf(' ', 20, SYSCMD_ALIGN_MIDDLE, "Parameter Groups");
    console_printf("\n");
    syscmd_putc('-', 20);
    console_printf("\n");

    for (int j = 0; j < sizeof(param_list) / sizeof(param_group_t); j++) {
        console_printf("%s\n", gp->name);
        gp++;
    }
}

static void _list_group(char* group_name)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < sizeof(param_list_t) / sizeof(param_group_t); j++) {
        if (STRING_COMPARE(group_name, gp->name)) {
            console_printf("%s:\n", gp->name);
            p = gp->content;

            for (int i = 0; i < gp->param_num; i++) {
                _disp_param(p);
                p++;
            }

            return;
        }

        gp++;
    }
}

static void _list_all(void)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < sizeof(param_list) / sizeof(param_group_t); j++) {
        console_printf("%s:\n", gp->name);
        p = gp->content;

        for (int i = 0; i < gp->param_num; i++) {
            _disp_param(p);
            p++;
        }

        gp++;
    }
}

static void _set_param(int argc, char** argv, int optc, optv_t* optv)
{
    uint8_t save_param = 0;

    if (argc < 4) {
        console_printf("usage: param set [group] <parameter> <value>\n");
        return;
    }

    /* handle operation */
    for (uint16_t i = 0; i < optc; i++) {
        if (STRING_COMPARE(optv[i].opt, "-s") || STRING_COMPARE(optv[i].opt, "--save")) {
            save_param = 1;
        }
    }

    if (argc <= 4) {
        /* do not explicitly define group name, just search parameter in all groups */
        if (syscmd_is_num(argv[3])) {
            if (param_set_string_val_by_name(argv[2], argv[3]) == FMT_EOK) {
                console_printf("%s set to %s\n", argv[2], argv[3]);

                if (save_param) {
                    param_save(NULL);
                }
            } else {
                console_printf("param set fail\n");
            }
        }
    } else {
        if (syscmd_is_num(argv[4])) {
            if (param_set_string_val_by_full_name(argv[2], argv[3], argv[4]) == FMT_EOK) {
                console_printf("%s set to %s\n", argv[3], argv[4]);

                if (save_param) {
                    param_save(NULL);
                }
            } else {
                console_printf("param set fail\n");
            }
        }
    }
}

static void _get_param(int argc, char** argv, int optc, optv_t* optv)
{
    if (argc < 3) {
        console_printf("usage: param get [group] <parameter>\n");
        return;
    }

    if (argc <= 3) {
        param_t* param = param_get_by_name(argv[2]);

        if (param) {
            _disp_param(param);
        } else {
            console_printf("can not find parameter\n");
        }
    } else {
        param_t* param = param_get_by_full_name(argv[2], argv[3]);

        if (param) {
            _disp_param(param);
        } else {
            console_printf("can not find parameter\n");
        }
    }
}

static void show_usage(void)
{
    PRINT_USAGE(param, [OPTION] ACTION[ARGS]);

    PRINT_STRING("\nAction:\n");
    PRINT_ACTION("list", 5, "List group(s) parameters.");
    PRINT_ACTION("group", 5, "List all parameter groups.");
    PRINT_ACTION("set", 5, "Set parameter.");
    PRINT_ACTION("get", 5, "Get parameter.");
    PRINT_ACTION("save", 5, "Save parameters to file.");
    PRINT_ACTION("load", 5, "Load parameters from file.");

    PRINT_STRING("\nOption:\n");
    PRINT_ACTION("-s, --save", 10, "Save parameter value.");
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
        if (argc >= 3) {
            _list_group(argv[2]);
        } else {
            _list_all();
        }
    } else if (STRING_COMPARE(argv[1], "group")) {
        _list_groups();
    } else if (STRING_COMPARE(argv[1], "set")) {
        _set_param(argc, argv, optc, optv);
    } else if (STRING_COMPARE(argv[1], "get")) {
        _get_param(argc, argv, optc, optv);
    } else if (STRING_COMPARE(argv[1], "save")) {
        char* path = argc > 2 ? argv[2] : NULL;

        if (param_save(path) == 0) {
            console_printf("parameter save to %s\n", path ? path : PARAM_FILE_NAME);
        }
    } else if (STRING_COMPARE(argv[1], "load")) {
        char* path = argc > 2 ? argv[2] : NULL;

        if (param_load(path) == FMT_EOK) {
            console_printf("parameter load from %s\n", path ? path : PARAM_FILE_NAME);
        }else{
            console_printf("can not load %s\n", path ? path : PARAM_FILE_NAME);
        }
    } else {
        show_usage();
    }

    return 0;
}

int cmd_param(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_param, __cmd_param, configure system parameter);