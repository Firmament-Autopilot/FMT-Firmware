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

#include "module/file_manager/file_manager.h"
#include "module/file_manager/yxml.h"
#include "module/utils/list.h"

#define TAG "Param"

#define YXML_STACK_SIZE 1024

static param_group_t* __param_table;
static int16_t __param_group_num;
static LIST_HEAD(__cb_list_head);

struct on_modify_cb {
    void (*on_modify)(param_t*);
    struct list_head link;
};

static fmt_err_t parse_xml(yxml_t* x, yxml_ret_t r, PARAM_PARSE_STATE* status)
{
    static int attr_cnt = 0;
    static char group_name[30];
    static char param_name[30];
    static char content[20];

    switch (*status) {
    case PARAM_PARSE_START: {
        if (r == YXML_ELEMSTART) {
            if (strcmp("param_list", x->elem) == 0) {
                *status = PARAM_PARSE_LIST;
            }
        }
    } break;

    case PARAM_PARSE_LIST: {
        if (r == YXML_ELEMSTART) {
            if (strcmp("group", x->elem) == 0) {
                *status = PARAM_PARSE_GROUP_INFO;
            }
        }

        if (r == YXML_ELEMEND) {
            *status = PARAM_PARSE_START;
            return FMT_EOK;
        }
    } break;

    case PARAM_PARSE_GROUP_INFO: {
        if (r == YXML_ATTRSTART) {
            if (strcmp("name", x->attr) == 0) {
                *status = PARAM_PARSE_GROUP_NAME;
                attr_cnt = 0;
            } else {
                //TODO
                console_printf("parse group name err:%s\n", x->attr);
                return FMT_ERROR;
            }
        }
    } break;

    case PARAM_PARSE_GROUP_NAME: {
        if (r == YXML_ATTRVAL) {
            group_name[attr_cnt++] = x->data[0];
        }

        if (r == YXML_ATTREND) {
            group_name[attr_cnt] = '\0';
            //console_printf("group %s\n", group_name);
            attr_cnt = 0;
            *status = PARAM_PARSE_GROUP;
        }
    } break;

    case PARAM_PARSE_GROUP: {
        if (r == YXML_ELEMSTART) {
            if (strcmp("param", x->elem) == 0) {
                *status = PARAM_PARSE_PARAM;
            } else {
                //TODO
                console_printf("parse param ele err:%s\n", x->elem);
                return FMT_ERROR;
            }
        }

        if (r == YXML_ELEMEND) {
            //console_printf("group %s end\n", group_name);
            *status = PARAM_PARSE_LIST;
        }
    } break;

    case PARAM_PARSE_PARAM: {
        if (r == YXML_ATTRSTART) {
            if (strcmp("name", x->attr) == 0) {
                *status = PARAM_PARSE_PARAM_NAME;
                attr_cnt = 0;
            } else {
                //TODO
                console_printf("parse param name err:%s\n", x->attr);
                return FMT_ERROR;
            }
        }

        if (r == YXML_ELEMEND) {
            *status = PARAM_PARSE_GROUP;
            //console_printf("param parse end\n");
        }
    } break;

    case PARAM_PARSE_PARAM_NAME: {
        if (r == YXML_ATTRVAL) {
            param_name[attr_cnt++] = x->data[0];
        }

        if (r == YXML_ATTREND) {
            param_name[attr_cnt] = '\0';
            //console_printf("param %s\n", param_name);
            attr_cnt = 0;
            *status = PARAM_PARSE_PARAM_VAL;
        }
    } break;

    case PARAM_PARSE_PARAM_VAL: {
        if (r == YXML_ELEMSTART) {
            if (strcmp("value", x->elem) == 0) {
                *status = PARAM_PARSE_PARAM_VAL_CONTENT;
                attr_cnt = 0;
            } else {
                //TODO
                console_printf("parse param val err:%s\n", x->elem);
                return FMT_ERROR;
            }
        }
    } break;

    case PARAM_PARSE_PARAM_VAL_CONTENT: {
        if (r == YXML_CONTENT) {
            content[attr_cnt++] = x->data[0];
        }

        if (r == YXML_ELEMEND) {
            content[attr_cnt] = '\0';

            attr_cnt = 0;
            *status = PARAM_PARSE_PARAM;

            param_set_str_val_by_full_name(group_name, param_name, content);
        }
    } break;
    }

    return FMT_ERROR;
}

static void on_parameter_modify(void* parameter)
{
    struct on_modify_cb* pos;

    list_for_each_entry(pos, struct on_modify_cb, &__cb_list_head, link)
    {
        /* invoke registered callback function */
        pos->on_modify((param_t*)parameter);
    }
}

/**
 * Get total parameter count.
 * 
 * @return parameter count.
 */
int32_t param_get_count(void)
{
    int32_t count = 0;
    param_group_t* gp = __param_table;

    for (int i = 0; i < __param_group_num; i++) {
        count += gp->param_num;
        gp++;
    }

    return count;
}

/**
 * Get parameter index in the parameter list.
 * 
 * @param param parameter instance
 *  
 * @return parameter index (start from 0).
 */
int32_t param_get_index(const param_t* param)
{
    int32_t index = 0;
    param_t* p;
    param_group_t* gp = __param_table;

    for (int i = 0; i < __param_group_num; i++) {
        p = gp->param_list;

        for (int j = 0; j < gp->param_num; j++) {
            if (strcmp(param->name, p->name) == 0) {
                return index;
            }
            p++;
            index++;
        }
        gp++;
    }

    return -1;
}

/**
 * Get parameter instance.
 * @note If there are several parameters with the same name but in the different group,
 * this will find the first parameter with the given name. 
 * 
 * @param param_name parameter name
 *  
 * @return pointer of parameter instance.
 */
param_t* param_get_by_name(const char* param_name)
{
    param_t* p;
    param_group_t* gp = __param_table;

    for (int j = 0; j < __param_group_num; j++) {
        p = gp->param_list;

        for (int i = 0; i < gp->param_num; i++) {
            if (strcmp(param_name, p->name) == 0) {
                return p;
            }
            p++;
        }
        gp++;
    }

    return NULL;
}

/**
 * Get parameter instance.
 * 
 * @param group_name group name
 * @param param_name parameter name
 *  
 * @return pointer of parameter instance.
 */
param_t* param_get_by_full_name(const char* group_name, const char* param_name)
{
    param_t* p;
    param_group_t* gp = __param_table;

    for (int i = 0; i < __param_group_num; i++) {
        p = gp->param_list;

        if (strcmp(group_name, gp->name) == 0) {
            for (int j = 0; j < gp->param_num; j++) {
                if (strcmp(param_name, p->name) == 0) {
                    return p;
                }
                p++;
            }
        }
        gp++;
    }

    return NULL;
}

/**
 * @brief Get parameter by index
 * 
 * @param index Parameter index, start from 0
 * @return param_t* The pointer of parameter instance.
 */
param_t* param_get_by_index(int32_t index)
{
    param_t* p;
    param_group_t* gp = __param_table;
    int32_t cur_idx = 0;

    for (int i = 0; i < __param_group_num; i++) {
        p = gp->param_list;

        for (int j = 0; j < gp->param_num; j++) {
            if (cur_idx == index) {
                return p;
            }
            p++;
            cur_idx++;
        }
        gp++;
    }

    return NULL;
}

/**
 * Set parameter value.
 * 
 * @param param parameter instance
 * @param val string value to be set. e.g, "12.5", "6"
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_str_val(param_t* param, char* val)
{
    param_value_t pval;

    if (param == NULL) {
        return FMT_EINVAL;
    }

    if (param->read_only) {
        return FMT_ENOTHANDLE;
    }

    switch (param->type) {
    case PARAM_TYPE_INT8:
        pval.i8 = atoi(val);
        break;

    case PARAM_TYPE_UINT8:
        pval.u8 = atoi(val);
        break;

    case PARAM_TYPE_INT16:
        pval.i16 = atoi(val);
        break;

    case PARAM_TYPE_UINT16:
        pval.u16 = atoi(val);
        break;

    case PARAM_TYPE_INT32:
        pval.i32 = atoi(val);
        break;

    case PARAM_TYPE_UINT32:
        pval.u32 = atoi(val);
        break;

    case PARAM_TYPE_FLOAT:
        pval.f = atof(val);
        break;

    case PARAM_TYPE_DOUBLE:
        pval.lf = atof(val);
        break;

    default:
        return FMT_ENOTHANDLE;
    }

    return param_set_val(param, &pval);
}

/**
 * Set parameter value with parameter name.
 * @note If there are several parameters with the same name but in the different group,
 * this will find the first parameter with the given name. 
 * 
 * @param param_name parameter name
 * @param val string value to be set. e.g, "12.5", "6"
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_str_val_by_name(char* param_name, char* val)
{
    param_t* p = param_get_by_name(param_name);

    return param_set_str_val(p, val);
}

/**
 * Set parameter value with given group and parameter name.
 * 
 * @param group_name group name
 * @param param_name parameter name
 * @param val string value to be set. e.g, "12.5", "6"
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_str_val_by_full_name(char* group_name, char* param_name, char* val)
{
    param_t* p = param_get_by_full_name(group_name, param_name);

    return param_set_str_val(p, val);
}

/**
 * Set parameter value.
 * 
 * @param param parameter instance
 * @param val value to be set
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_val(param_t* param, void* val)
{
    size_t val_size;

    if (param == NULL) {
        return FMT_EINVAL;
    }

    if (param->read_only) {
        return FMT_ENOTHANDLE;
    }

    switch (param->type) {
    case PARAM_TYPE_INT8:
        val_size = sizeof(param->val.i8);
        break;

    case PARAM_TYPE_UINT8:
        val_size = sizeof(param->val.u8);
        break;

    case PARAM_TYPE_INT16:
        val_size = sizeof(param->val.i16);
        break;

    case PARAM_TYPE_UINT16:
        val_size = sizeof(param->val.u16);
        break;

    case PARAM_TYPE_INT32:
        val_size = sizeof(param->val.i32);
        break;

    case PARAM_TYPE_UINT32:
        val_size = sizeof(param->val.u32);
        break;

    case PARAM_TYPE_FLOAT:
        val_size = sizeof(param->val.f);
        break;

    case PARAM_TYPE_DOUBLE:
        val_size = sizeof(param->val.lf);
        break;

    default:
        return FMT_ENOTHANDLE;
    }

    OS_ENTER_CRITICAL;

    memcpy(&(param->val), val, val_size);
    /* also update the linked variable */
    if (param->var != NULL) {
        memcpy(param->var, val, val_size);
    }

    OS_EXIT_CRITICAL;

    /* invoke parameter modify callbacks */
    if (!list_empty(&__cb_list_head))
        on_parameter_modify(param);

    return FMT_EOK;
}

/**
 * Set parameter value with parameter name.
 * @note If there are several parameters with the same name but in the different group,
 * this will find the first parameter with the given name. 
 * 
 * @param param_name parameter name
 * @param val value to be set
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_val_by_name(char* param_name, void* val)
{
    param_t* p = param_get_by_name(param_name);

    return param_set_val(p, val);
}

/**
 * Set parameter value with given group and parameter name.
 * 
 * @param group_name group name
 * @param param_name parameter name
 * @param val value to be set
 *  
 * @return FMT Errors.
 */
fmt_err_t param_set_val_by_full_name(char* group_name, char* param_name, void* val)
{
    param_t* p = param_get_by_full_name(group_name, param_name);

    return param_set_val(p, val);
}

/**
 * @brief get parameter's group
 * 
 * @param param parameter object
 * @return param_group_t* group object
 */
param_group_t* param_get_group(const param_t* param)
{
    param_group_t* gp = __param_table;

    for (uint32_t i = 0; i < __param_group_num; i++) {
        for (uint32_t j = 0; j < gp->param_num; j++) {
            if (&gp->param_list[j] == param) {
                return gp;
            }
        }
        gp++;
    }

    return NULL;
}

/**
 * @brief Find specific group
 * 
 * @param group_name Group name
 * @return param_group_t* Pointer of group instance, NULL means not found
 */
param_group_t* param_find_group(const char* group_name)
{
    param_group_t* gp = __param_table;

    for (uint32_t i = 0; i < __param_group_num; i++) {
        if (strcmp(group_name, gp->name) == 0) {
            return gp;
        }
        gp++;
    }

    return NULL;
}

/**
 * Save current parameters into a file.
 * 
 * @param path full path of parameter file
 *  
 * @return FMT Errors.
 */
fmt_err_t param_save(char* path)
{
    int fd;
    fmt_err_t res = FMT_EOK;

    fd = open(path ? path : PARAM_FILE_NAME, O_CREAT | O_WRONLY);

    if (fd < 0) {
        console_printf("parameter file open fail!\n");
        return FMT_ERROR;
    }

    /* add title */
    fm_fprintf(fd, "<?xml version=\"1.0\"?>\n");
    /* add param_list element */
    fm_fprintf(fd, "<param_list>\n");

    param_t* p;
    param_group_t* gp = __param_table;

    for (int i = 0; i < __param_group_num; i++) {
        /* add group element */
        fm_fprintf(fd, "\x20\x20<group name=\"%s\">\n", gp->name);
        p = gp->param_list;

        for (int j = 0; j < gp->param_num; j++) {
            /* add param element */
            fm_fprintf(fd, "\x20\x20\x20\x20<param name=\"%s\">\n", p->name);

            switch (p->type) {
            case PARAM_TYPE_INT8:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.i8);
                break;
            case PARAM_TYPE_UINT8:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%u</value>\n", p->val.u8);
                break;
            case PARAM_TYPE_INT16:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.i16);
                break;
            case PARAM_TYPE_UINT16:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%u</value>\n", p->val.u16);
                break;
            case PARAM_TYPE_INT32:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%ld</value>\n", p->val.i32);
                break;
            case PARAM_TYPE_UINT32:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%lu</value>\n", p->val.u32);
                break;
            case PARAM_TYPE_FLOAT:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%f</value>\n", p->val.f);
                break;
            case PARAM_TYPE_DOUBLE:
                fm_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%lf</value>\n", p->val.lf);
                break;
            default:
                console_printf("unknow parameter type:%d\n", p->type);
                break;
            }

            p++;
            fm_fprintf(fd, "\x20\x20\x20\x20</param>\n");
        }

        gp++;
        fm_fprintf(fd, "\x20\x20</group>\n");
    }

    fm_fprintf(fd, "</param_list>\n");
    close(fd);

    return res;
}

/**
 * Load parameter from file.
 * 
 * @param path full path of parameter file
 *  
 * @return FMT Errors.
 */
fmt_err_t param_load(char* path)
{
    int fd;
    yxml_ret_t yxml_r;
    char c;
    fmt_err_t res = FMT_EOK;

    fd = open(path ? path : PARAM_FILE_NAME, O_RDONLY);

    if (fd < 0) {
        return FMT_ERROR;
    }

    PARAM_PARSE_STATE status = PARAM_PARSE_START;

    char* yxml_stack = (char*)rt_malloc(YXML_STACK_SIZE);

    if (yxml_stack != NULL) {
        yxml_t yxml_handle;
        yxml_init(&yxml_handle, yxml_stack, YXML_STACK_SIZE);

        while (read(fd, &c, 1)) {
            yxml_r = yxml_parse(&yxml_handle, c);
            parse_xml(&yxml_handle, yxml_r, &status);
        }

        if (yxml_eof(&yxml_handle) != YXML_OK) {
            console_printf("xml parse err\n");
            res = FMT_ERROR;
        }
    } else {
        console_printf("param malloc fail\n");
        res = FMT_ERROR;
    }

    rt_free(yxml_stack);
    close(fd);

    return res;
}

/**
 * @brief Get the param table object
 * 
 * @return param_group_t* 
 */
param_group_t* param_get_table(void)
{
    return __param_table;
}

/**
 * @brief Get the param group num
 * 
 * @return uint16_t 
 */
int16_t param_get_group_count(void)
{
    return __param_group_num;
}

/**
 * @brief Link parameter with a object. When parameter modified, the linked
 *        object will also be modified.
 * 
 * @param param parameter object
 * @param obj 
 * @return fmt_err_t 
 */
fmt_err_t param_link_variable(param_t* param, void* var)
{
    size_t val_size;

    if (param == NULL) {
        return FMT_EINVAL;
    }

    switch (param->type) {
    case PARAM_TYPE_INT8:
        val_size = sizeof(param->val.i8);
        break;

    case PARAM_TYPE_UINT8:
        val_size = sizeof(param->val.u8);
        break;

    case PARAM_TYPE_INT16:
        val_size = sizeof(param->val.i16);
        break;

    case PARAM_TYPE_UINT16:
        val_size = sizeof(param->val.u16);
        break;

    case PARAM_TYPE_INT32:
        val_size = sizeof(param->val.i32);
        break;

    case PARAM_TYPE_UINT32:
        val_size = sizeof(param->val.u32);
        break;

    case PARAM_TYPE_FLOAT:
        val_size = sizeof(param->val.f);
        break;

    case PARAM_TYPE_DOUBLE:
        val_size = sizeof(param->val.lf);
        break;

    default:
        return FMT_ENOTHANDLE;
    }

    OS_ENTER_CRITICAL;
    param->var = var;
    /* update object value immediately */
    memcpy(param->var, &param->val, val_size);
    OS_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * @brief Register parameter modify callback
 * 
 * @param on_modify callback function pointer
 * @return fmt_err_t 
 */
fmt_err_t register_param_modify_callback(void (*on_modify)(param_t* param))
{
    struct on_modify_cb* node = (struct on_modify_cb*)rt_malloc(sizeof(struct on_modify_cb));

    if (node == NULL) {
        return FMT_ENOMEM;
    }

    INIT_LIST_HEAD(&node->link);
    node->on_modify = on_modify;

    list_add_tail(&node->link, &__cb_list_head);

    return FMT_EOK;
}

/**
 * @brief Deregister parameter modify callback
 * 
 * @param on_modify callback function pointer
 * @return fmt_err_t 
 */
fmt_err_t deregister_param_modify_callback(void (*on_modify)(param_t* param))
{
    struct on_modify_cb* pos;

    list_for_each_entry(pos, struct on_modify_cb, &__cb_list_head, link)
    {
        if (pos->on_modify == on_modify) {
            list_del(&pos->link);
            rt_free(pos);

            return FMT_EOK;
        }
    }

    return FMT_ERROR;
}

/**
 * Initialize parameter module.
 * 
 * @return FMT Errors.
 */
fmt_err_t param_init(void)
{
    extern const int __fmt_param_start;
    extern const int __fmt_param_end;

    __param_table = (param_group_t*)&__fmt_param_start;
    __param_group_num = (param_group_t*)&__fmt_param_end - __param_table;

    /* load parameter from file */
    if (param_load(PARAM_FILE_NAME) != FMT_EOK) {
        console_printf("can not load %s, use default parameter value.\n", PARAM_FILE_NAME);
    }

    return FMT_EOK;
}
