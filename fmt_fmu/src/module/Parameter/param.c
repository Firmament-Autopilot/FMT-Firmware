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

#include "yxml.h"
#include <firmament.h>
#include <string.h>

#include "module/fs_manager/fs_manager.h"

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
    /* Determines when to start and stop logging (Blog).
	0: disabled
	1: when armed until disarm
	2: from boot until disarm
	3: from boot until shutdown  */
    PARAM_DEFINE_INT32(BLOG_MODE, 0),
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
};

PARAM_GROUP(INS)
PARAM_DECLARE_GROUP(INS) = {
    /* User external filter for IMU*/
    PARAM_DEFINE_INT8(USE_EXTERN_FILTER, 0),
};

PARAM_GROUP(CONTROL)
PARAM_DECLARE_GROUP(CONTROL) = {
    PARAM_DEFINE_FLOAT(VEL_XY_P, 0.9),
    PARAM_DEFINE_FLOAT(VEL_XY_I, 0.09),
    PARAM_DEFINE_FLOAT(VEL_XY_D, 0.1),
    PARAM_DEFINE_FLOAT(VEL_Z_P, 0.5),
    PARAM_DEFINE_FLOAT(VEL_Z_I, 0.2),
    PARAM_DEFINE_FLOAT(VEL_Z_D, 0.01),
    PARAM_DEFINE_FLOAT(VEL_XY_I_MIN, -1),
    PARAM_DEFINE_FLOAT(VEL_XY_I_MAX, 1),
    PARAM_DEFINE_FLOAT(VEL_XY_D_MIN, -1),
    PARAM_DEFINE_FLOAT(VEL_XY_D_MAX, 1),
    PARAM_DEFINE_FLOAT(VEL_Z_I_MIN, -0.15),
    PARAM_DEFINE_FLOAT(VEL_Z_I_MAX, 0.15),
    PARAM_DEFINE_FLOAT(VEL_Z_D_MIN, -0.1),
    PARAM_DEFINE_FLOAT(VEL_Z_D_MAX, 0.1),

    PARAM_DEFINE_FLOAT(ROLL_P, 4.5),
    PARAM_DEFINE_FLOAT(PITCH_P, 4.5),
    PARAM_DEFINE_FLOAT(ROLL_PITCH_CMD_LIM, PI / 6),

    PARAM_DEFINE_FLOAT(ROLL_RATE_P, 0.075),
    PARAM_DEFINE_FLOAT(PITCH_RATE_P, 0.075),
    PARAM_DEFINE_FLOAT(YAW_RATE_P, 0.2),
    PARAM_DEFINE_FLOAT(ROLL_RATE_I, 0.1),
    PARAM_DEFINE_FLOAT(PITCH_RATE_I, 0.1),
    PARAM_DEFINE_FLOAT(YAW_RATE_I, 0.1),
    PARAM_DEFINE_FLOAT(ROLL_RATE_D, 0.001),
    PARAM_DEFINE_FLOAT(PITCH_RATE_D, 0.001),
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
    PARAM_DEFINE_GROUP(CONTROL),
};

static fmt_err _parse_xml(yxml_t* x, yxml_ret_t r, PARAM_PARSE_STATE* status)
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

int param_get_index(const param_t* param)
{
    int index = 0;
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

param_t* param_get(char* group_name, char* param_name)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < sizeof(param_list) / sizeof(param_group_t); j++) {
        if (strcmp(group_name, gp->name) == 0) {
            p = gp->content;

            for (int i = 0; i < gp->param_num; i++) {
                if (strcmp(param_name, p->name) == 0)
                    return p;

                p++;
            }
        }

        gp++;
    }

    return NULL;
}

param_t* param_get_by_name(const char* param_name)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
        p = gp->content;

        for (int i = 0; i < gp->param_num; i++) {
            if (strcmp(param_name, p->name) == 0)
                return p;

            p++;
        }

        gp++;
    }

    return NULL;
}

param_t* param_get_by_full_name(const char* group_name, const char* param_name)
{
    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < PARAM_GROUP_COUNT; j++) {
        p = gp->content;

        if (strcmp(group_name, gp->name) == 0) {
            for (int i = 0; i < gp->param_num; i++) {
                if (strcmp(param_name, p->name) == 0)
                    return p;

                p++;
            }
        }

        gp++;
    }

    return NULL;
}

fmt_err param_set_string_val(param_t* param, char* val)
{
    if (param == NULL) {
        return FMT_ERROR;
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

fmt_err param_set_string_val_by_name(char* param_name, char* val)
{
    param_t* p = param_get_by_name(param_name);

    return param_set_string_val(p, val);
}

fmt_err param_set_string_val_by_full_name(char* group_name, char* param_name, char* val)
{
    param_t* p = param_get(group_name, param_name);

    return param_set_string_val(p, val);
}

fmt_err param_set_val(param_t* param, void* val)
{
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

fmt_err param_set_val_by_name(char* param_name, void* val)
{
    param_t* p = param_get_by_name(param_name);

    return param_set_val(p, val);
}

fmt_err param_set_val_by_full_name(char* group_name, char* param_name, void* val)
{
    param_t* p = param_get(group_name, param_name);

    return param_set_val(p, val);
}

fmt_err param_save(char* path)
{
    int fd;
    fmt_err res = FMT_EOK;

    fd = open(path ? path : PARAM_FILE_NAME, O_CREAT | O_WRONLY);

    if (fd < 0) {
        ulog_e(TAG, "parameter file open fail!\n");
        return FMT_ERROR;
    }

    /* add title */
    fs_fprintf(fd, "<?xml version=\"1.0\"?>\n");
    /* add param_list element */
    fs_fprintf(fd, "<param_list>\n");

    param_t* p;
    param_group_t* gp = (param_group_t*)&param_list;

    for (int j = 0; j < sizeof(param_list) / sizeof(param_group_t); j++) {
        /* add group element */
        fs_fprintf(fd, "\x20\x20<group name=\"%s\">\n", gp->name);
        p = gp->content;

        for (int i = 0; i < gp->param_num; i++) {
            /* add param element */
            fs_fprintf(fd, "\x20\x20\x20\x20<param name=\"%s\">\n", p->name);

            /* add value element */
            if (p->type == PARAM_TYPE_INT8) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.i8);
            }

            if (p->type == PARAM_TYPE_UINT8) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.u8);
            }

            if (p->type == PARAM_TYPE_INT16) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.i16);
            }

            if (p->type == PARAM_TYPE_UINT16) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.u16);
            }

            if (p->type == PARAM_TYPE_INT32) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.i32);
            }

            if (p->type == PARAM_TYPE_UINT32) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%d</value>\n", p->val.u32);
            }

            if (p->type == PARAM_TYPE_FLOAT) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%f</value>\n", p->val.f);
            }

            if (p->type == PARAM_TYPE_DOUBLE) {
                fs_fprintf(fd, "\x20\x20\x20\x20\x20\x20<value>%lf</value>\n", p->val.lf);
            }

            p++;
            fs_fprintf(fd, "\x20\x20\x20\x20</param>\n");
        }

        gp++;
        fs_fprintf(fd, "\x20\x20</group>\n");
    }

    fs_fprintf(fd, "</param_list>\n");
    close(fd);

    return res;
}

fmt_err param_load(char* path)
{
    int fd;
    yxml_ret_t yxml_r;
    char c;
    fmt_err res = FMT_EOK;

    fd = open(path ? path : PARAM_FILE_NAME, O_RDONLY);

    if (fd < 0) {
        ulog_i(TAG, "%s load fail, use default configuration.\n", PARAM_FILE_NAME);
        return FMT_EOK;
    }

    PARAM_PARSE_STATE status = PARAM_PARSE_START;

    char* yxml_stack = (char*)rt_malloc(YXML_STACK_SIZE);

    if (yxml_stack != NULL) {
        yxml_t yxml_handle;
        yxml_init(&yxml_handle, yxml_stack, YXML_STACK_SIZE);

        while (read(fd, &c, 1)) {
            yxml_r = yxml_parse(&yxml_handle, c);
            _parse_xml(&yxml_handle, yxml_r, &status);
        }

        if (yxml_eof(&yxml_handle) != YXML_OK) {
            ulog_e(TAG, "xml parse err\n");
            res = FMT_ERROR;
        }
    } else {
        ulog_e(TAG, "param malloc fail\n");
        res = FMT_ERROR;
    }

    rt_free(yxml_stack);
    close(fd);

    return res;
}

fmt_err param_init(void)
{
    param_load(PARAM_FILE_NAME);

    return FMT_EOK;
}
