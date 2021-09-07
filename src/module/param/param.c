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

#define TAG "Param"

#define YXML_STACK_SIZE 1024

#define PARAM_GROUP_COUNT (sizeof(param_list_t) / sizeof(param_group_t))

/* Define Parameters/Group include 4 steps
	* Step 1:	Declare Group
    * Step 2:	Define Groups
	* Step 3:	Declare Parameters In Group
	* Step 4:	Define Parameters In Group
	 */

/******************** Step 4: Define Parameters In Group ********************/
PARAM_GROUP(SYSTEM)
PARAM_DECLARE_GROUP(SYSTEM) = {
    /* Determines when to start and stop logging.
	0: disabled
	1: when armed until disarm
	2: from boot until disarm
	3: from boot until shutdown  */
    PARAM_DEFINE_INT32(MLOG_MODE, 0),
};

PARAM_GROUP(CALIB)
PARAM_DECLARE_GROUP(CALIB) = {
    /* GYRO_CAL = GYRO - OFFSET */
    PARAM_DEFINE_FLOAT(GYRO0_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(GYRO0_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(GYRO0_ZOFF, 0.0),
    /* ACC_CAL = ROT_M * (ACC-OFFSET)
	           |  XX  XY  XZ |
	   ROT_M = |  XY  YY  YZ |
	           |  XZ  YZ  ZZ |   */
    PARAM_DEFINE_FLOAT(ACC0_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC0_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC0_ZOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC0_XXSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC0_YYSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC0_ZZSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC0_XYSCALE, 0.0),
    PARAM_DEFINE_FLOAT(ACC0_XZSCALE, 0.0),
    PARAM_DEFINE_FLOAT(ACC0_YZSCALE, 0.0),
    /* MAG_CAL = ROT_M * (MAG-OFFSET)
	           |  XX  XY  XZ |
	   ROT_M = |  XY  YY  YZ |
	           |  XZ  YZ  ZZ |   */
    PARAM_DEFINE_FLOAT(MAG0_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG0_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG0_ZOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG0_XXSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG0_YYSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG0_ZZSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG0_XYSCALE, 0.0),
    PARAM_DEFINE_FLOAT(MAG0_XZSCALE, 0.0),
    PARAM_DEFINE_FLOAT(MAG0_YZSCALE, 0.0),

    PARAM_DEFINE_FLOAT(GYRO1_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(GYRO1_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(GYRO1_ZOFF, 0.0),

    PARAM_DEFINE_FLOAT(ACC1_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC1_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC1_ZOFF, 0.0),
    PARAM_DEFINE_FLOAT(ACC1_XXSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC1_YYSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC1_ZZSCALE, 1.0),
    PARAM_DEFINE_FLOAT(ACC1_XYSCALE, 0.0),
    PARAM_DEFINE_FLOAT(ACC1_XZSCALE, 0.0),
    PARAM_DEFINE_FLOAT(ACC1_YZSCALE, 0.0),

    PARAM_DEFINE_FLOAT(MAG1_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG1_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG1_ZOFF, 0.0),
    PARAM_DEFINE_FLOAT(MAG1_XXSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG1_YYSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG1_ZZSCALE, 1.0),
    PARAM_DEFINE_FLOAT(MAG1_XYSCALE, 0.0),
    PARAM_DEFINE_FLOAT(MAG1_XZSCALE, 0.0),
    PARAM_DEFINE_FLOAT(MAG1_YZSCALE, 0.0),
    /* Level Calibration. Roll,Pitch,Yaw offset in rad */
    PARAM_DEFINE_FLOAT(LEVEL_XOFF, 0.0),
    PARAM_DEFINE_FLOAT(LEVEL_YOFF, 0.0),
    PARAM_DEFINE_FLOAT(LEVEL_ZOFF, 0.0),
};

PARAM_GROUP(INS)
PARAM_DECLARE_GROUP(INS) = {
    /* User external filter for IMU*/
    PARAM_DEFINE_INT8(USE_EXTERN_FILTER, 1),
};

PARAM_GROUP(FMS)
PARAM_DECLARE_GROUP(FMS) = {
    /* Stick Dead Zone */
    PARAM_DEFINE_FLOAT(THROTTLE_DZ, 0.15),
    PARAM_DEFINE_FLOAT(YAW_DZ, 0.15),
    PARAM_DEFINE_FLOAT(ROLL_DZ, 0.1),
    PARAM_DEFINE_FLOAT(PITCH_DZ, 0.1),
    PARAM_DEFINE_FLOAT(XY_P, 0.95),
    PARAM_DEFINE_FLOAT(Z_P, 1),
    PARAM_DEFINE_FLOAT(VEL_XY_LIM, 5.0),
    PARAM_DEFINE_FLOAT(VEL_Z_LIM, 2.5),
    PARAM_DEFINE_FLOAT(YAW_P, 2.5),
    PARAM_DEFINE_FLOAT(YAW_RATE_LIM, PI / 3),
    PARAM_DEFINE_FLOAT(ROLL_PITCH_LIM, PI / 6),
};

PARAM_GROUP(CONTROL)
PARAM_DECLARE_GROUP(CONTROL) = {
    PARAM_DEFINE_FLOAT(VEL_XY_P, 1.4),
    PARAM_DEFINE_FLOAT(VEL_XY_I, 0.2),
    PARAM_DEFINE_FLOAT(VEL_XY_D, 0.2),
    PARAM_DEFINE_FLOAT(VEL_Z_P, 0.6),
    PARAM_DEFINE_FLOAT(VEL_Z_I, 0.1),
    PARAM_DEFINE_FLOAT(VEL_Z_D, 0.0),
    PARAM_DEFINE_FLOAT(VEL_XY_I_MIN, -1),
    PARAM_DEFINE_FLOAT(VEL_XY_I_MAX, 1),
    PARAM_DEFINE_FLOAT(VEL_XY_D_MIN, -1),
    PARAM_DEFINE_FLOAT(VEL_XY_D_MAX, 1),
    PARAM_DEFINE_FLOAT(VEL_Z_I_MIN, -0.15),
    PARAM_DEFINE_FLOAT(VEL_Z_I_MAX, 0.15),
    PARAM_DEFINE_FLOAT(VEL_Z_D_MIN, -0.1),
    PARAM_DEFINE_FLOAT(VEL_Z_D_MAX, 0.1),

    PARAM_DEFINE_FLOAT(ROLL_P, 5),
    PARAM_DEFINE_FLOAT(PITCH_P, 5),
    PARAM_DEFINE_FLOAT(ROLL_PITCH_CMD_LIM, PI / 6),

    PARAM_DEFINE_FLOAT(ROLL_RATE_P, 0.1),
    PARAM_DEFINE_FLOAT(PITCH_RATE_P, 0.1),
    PARAM_DEFINE_FLOAT(YAW_RATE_P, 0.15),
    PARAM_DEFINE_FLOAT(ROLL_RATE_I, 0.1),
    PARAM_DEFINE_FLOAT(PITCH_RATE_I, 0.1),
    PARAM_DEFINE_FLOAT(YAW_RATE_I, 0.2),
    PARAM_DEFINE_FLOAT(ROLL_RATE_D, 0.003),
    PARAM_DEFINE_FLOAT(PITCH_RATE_D, 0.003),
    PARAM_DEFINE_FLOAT(YAW_RATE_D, 0.001),
    PARAM_DEFINE_FLOAT(RATE_I_MIN, -0.1),
    PARAM_DEFINE_FLOAT(RATE_I_MAX, 0.1),
    PARAM_DEFINE_FLOAT(RATE_D_MIN, -0.1),
    PARAM_DEFINE_FLOAT(RATE_D_MAX, 0.1),
    PARAM_DEFINE_FLOAT(P_Q_CMD_LIM, PI / 2),
    PARAM_DEFINE_FLOAT(R_CMD_LIM, PI),
};

/******************** Step 2: Define Group ********************/
param_list_t param_list = {
    PARAM_DEFINE_GROUP(SYSTEM),
    PARAM_DEFINE_GROUP(CALIB),
    PARAM_DEFINE_GROUP(INS),
    PARAM_DEFINE_GROUP(FMS),
    PARAM_DEFINE_GROUP(CONTROL),
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

            param_set_string_val_by_full_name(group_name, param_name, content);
        }
    } break;
    }

    return FMT_ERROR;
}

/**
 * Get total parameter count.
 * 
 * @return parameter count.
 */
uint32_t param_get_count(void)
{
    uint32_t count = 0;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
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
int16_t param_get_index(const param_t* param)
{
    int16_t index = 0;
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int i = 0; i < PARAM_GROUP_COUNT; i++) {
        p = gp->content;

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
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
        p = gp->content;

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
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
        p = gp->content;

        if (strcmp(group_name, gp->name) == 0) {
            for (int i = 0; i < gp->param_num; i++) {
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
param_t* param_get_by_index(int16_t index)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;
    int16_t cur_idx = 0;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
        p = gp->content;

        for (int i = 0; i < gp->param_num; i++) {
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
fmt_err_t param_set_string_val(param_t* param, char* val)
{
    if (param == NULL) {
        return FMT_EINVAL;
    }

#ifdef FMT_ONLINE_PARAM_TUNING
    OS_ENTER_CRITICAL;
#endif

    if (param->type == PARAM_TYPE_INT8) {
        param->val.i8 = atoi(val);
    }

    if (param->type == PARAM_TYPE_UINT8) {
        param->val.u8 = atoi(val);
    }

    if (param->type == PARAM_TYPE_INT16) {
        param->val.i16 = atoi(val);
    }

    if (param->type == PARAM_TYPE_UINT16) {
        param->val.u16 = atoi(val);
    }

    if (param->type == PARAM_TYPE_INT32) {
        param->val.i32 = atoi(val);
    }

    if (param->type == PARAM_TYPE_UINT32) {
        param->val.u32 = atoi(val);
    }

    if (param->type == PARAM_TYPE_FLOAT) {
        param->val.f = atof(val);
    }

    if (param->type == PARAM_TYPE_DOUBLE) {
        param->val.lf = atof(val);
    }

#ifdef FMT_ONLINE_PARAM_TUNING
    OS_EXIT_CRITICAL;
#endif

    return FMT_EOK;
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
fmt_err_t param_set_string_val_by_name(char* param_name, char* val)
{
    param_t* p = param_get_by_name(param_name);

    if (p == NULL) {
        return FMT_EINVAL;
    }

    return param_set_string_val(p, val);
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
fmt_err_t param_set_string_val_by_full_name(char* group_name, char* param_name, char* val)
{
    param_t* p = param_get_by_full_name(group_name, param_name);

    if (p == NULL) {
        return FMT_EINVAL;
    }

    return param_set_string_val(p, val);
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
    if (param == NULL) {
        return FMT_EINVAL;
    }

    switch (param->type) {
    case PARAM_TYPE_INT8:
        memcpy(&(param->val.i8), val, sizeof(param->val.i8));
        break;

    case PARAM_TYPE_UINT8:
        memcpy(&(param->val.u8), val, sizeof(param->val.u8));
        break;

    case PARAM_TYPE_INT16:
        memcpy(&(param->val.i16), val, sizeof(param->val.i16));
        break;

    case PARAM_TYPE_UINT16:
        memcpy(&(param->val.u16), val, sizeof(param->val.u16));
        break;

    case PARAM_TYPE_INT32:
        memcpy(&(param->val.i32), val, sizeof(param->val.i32));
        break;

    case PARAM_TYPE_UINT32:
        memcpy(&(param->val.u32), val, sizeof(param->val.u32));
        break;

    case PARAM_TYPE_FLOAT:
        memcpy(&(param->val.f), val, sizeof(param->val.f));
        break;

    case PARAM_TYPE_DOUBLE:
        memcpy(&(param->val.lf), val, sizeof(param->val.lf));
        break;

    default:
        return FMT_ENOTHANDLE;
    }

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

    if (p == NULL) {
        return FMT_EINVAL;
    }

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

    if (p == NULL) {
        return FMT_EINVAL;
    }

    return param_set_val(p, val);
}

/**
 * @brief Find specific group
 * 
 * @param group_name Group name
 * @return param_group_t* Pointer of group instance, NULL means not found
 */
param_group_t* param_find_group(const char* group_name)
{
    param_group_t* gp = (param_group_t*)&param_list;

    for (uint32_t i = 0; i < sizeof(param_list_t) / sizeof(param_group_t); i++) {
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
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < sizeof(param_list) / sizeof(param_group_t); j++) {
        /* add group element */
        fm_fprintf(fd, "\x20\x20<group name=\"%s\">\n", gp->name);
        p = gp->content;

        for (int i = 0; i < gp->param_num; i++) {
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
 * Initialize parameter module.
 * 
 * @return FMT Errors.
 */
fmt_err_t param_init(void)
{
    /* load parameter from file */
    if (param_load(PARAM_FILE_NAME) != FMT_EOK) {
        console_printf("can not load %s, use default parameter value.\n", PARAM_FILE_NAME);
    }

    return FMT_EOK;
}
