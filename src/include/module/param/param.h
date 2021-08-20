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

#ifndef PARAM_H__
#define PARAM_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef FMT_USING_HIL
#define PARAM_FILE_NAME "/sys/hil_param.xml"
#else
#define PARAM_FILE_NAME "/sys/param.xml"
#endif

/********************** Parameter Data Structure **********************/
enum param_type_t {
    PARAM_TYPE_INT8 = 0,
    PARAM_TYPE_UINT8,
    PARAM_TYPE_INT16,
    PARAM_TYPE_UINT16,
    PARAM_TYPE_INT32,
    PARAM_TYPE_UINT32,
    PARAM_TYPE_FLOAT,
    PARAM_TYPE_DOUBLE,
    PARAM_TYPE_UNKNOWN = 0xFF
};

typedef enum {
    PARAM_PARSE_START = 0,
    PARAM_PARSE_LIST,
    PARAM_PARSE_GROUP_INFO,
    PARAM_PARSE_GROUP_NAME,
    PARAM_PARSE_GROUP,
    PARAM_PARSE_PARAM,
    PARAM_PARSE_PARAM_NAME,
    PARAM_PARSE_PARAM_VAL,
    PARAM_PARSE_PARAM_VAL_CONTENT,
} PARAM_PARSE_STATE;

typedef union {
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    float f;
    double lf;
} param_value_t;

typedef struct {
    const char* name;
    const uint8_t type;
    param_value_t val;
} param_t;

typedef struct {
    const char* name;
    const uint32_t param_num;
    param_t* content;
} param_group_t;

/********************** Function Macro **********************/
#define PARAM_DECLARE(_name) param_t _name

#define PARAM_DEFINE_INT8(_name, _default) \
    {                                      \
        .name = #_name,                    \
        .type = PARAM_TYPE_INT8,           \
        .val.i8 = _default                 \
    }

#define PARAM_DEFINE_UINT8(_name, _default) \
    {                                       \
        .name = #_name,                     \
        .type = PARAM_TYPE_UINT8,           \
        .val.u8 = _default                  \
    }

#define PARAM_DEFINE_INT16(_name, _default) \
    {                                       \
        .name = #_name,                     \
        .type = PARAM_TYPE_INT16,           \
        .val.i16 = _default                 \
    }

#define PARAM_DEFINE_UINT16(_name, _default) \
    {                                        \
        .name = #_name,                      \
        .type = PARAM_TYPE_UINT16,           \
        .val.u16 = _default                  \
    }

#define PARAM_DEFINE_INT32(_name, _default) \
    {                                       \
        .name = #_name,                     \
        .type = PARAM_TYPE_INT32,           \
        .val.i32 = _default                 \
    }

#define PARAM_DEFINE_UINT32(_name, _default) \
    {                                        \
        .name = #_name,                      \
        .type = PARAM_TYPE_UINT32,           \
        .val.u32 = _default                  \
    }

#define PARAM_DEFINE_FLOAT(_name, _default) \
    {                                       \
        .name = #_name,                     \
        .type = PARAM_TYPE_FLOAT,           \
        .val.f = _default                   \
    }

#define PARAM_DEFINE_DOUBLE(_name, _default) \
    {                                        \
        .name = #_name,                      \
        .type = PARAM_TYPE_DOUBLE,           \
        .val.lf = _default                   \
    }

#define PARAM_GROUP(_group)         _param_##_group
#define PARAM_DECLARE_GROUP(_group) _param_##_group##_t
#define PARAM_DEFINE_GROUP(_group)                                  \
    {                                                               \
        .name = #_group,                                            \
        .param_num = sizeof(_param_##_group##_t) / sizeof(param_t), \
        .content = (param_t*)&_param_##_group##_t                   \
    }

/******************** Step 3: Declare Parameters In Group ********************/
typedef struct {
    PARAM_DECLARE(BLOG_MODE);
} PARAM_GROUP(SYSTEM);

typedef struct {
    PARAM_DECLARE(GYRO0_XOFF);
    PARAM_DECLARE(GYRO0_YOFF);
    PARAM_DECLARE(GYRO0_ZOFF);
    PARAM_DECLARE(ACC0_XOFF);
    PARAM_DECLARE(ACC0_YOFF);
    PARAM_DECLARE(ACC0_ZOFF);
    PARAM_DECLARE(ACC0_XXSCALE);
    PARAM_DECLARE(ACC0_YYSCALE);
    PARAM_DECLARE(ACC0_ZZSCALE);
    PARAM_DECLARE(ACC0_XYSCALE);
    PARAM_DECLARE(ACC0_XZSCALE);
    PARAM_DECLARE(ACC0_YZSCALE);
    PARAM_DECLARE(MAG0_XOFF);
    PARAM_DECLARE(MAG0_YOFF);
    PARAM_DECLARE(MAG0_ZOFF);
    PARAM_DECLARE(MAG0_XXSCALE);
    PARAM_DECLARE(MAG0_YYSCALE);
    PARAM_DECLARE(MAG0_ZZSCALE);
    PARAM_DECLARE(MAG0_XYSCALE);
    PARAM_DECLARE(MAG0_XZSCALE);
    PARAM_DECLARE(MAG0_YZSCALE);
    PARAM_DECLARE(GYRO1_XOFF);
    PARAM_DECLARE(GYRO1_YOFF);
    PARAM_DECLARE(GYRO1_ZOFF);
    PARAM_DECLARE(ACC1_XOFF);
    PARAM_DECLARE(ACC1_YOFF);
    PARAM_DECLARE(ACC1_ZOFF);
    PARAM_DECLARE(ACC1_XXSCALE);
    PARAM_DECLARE(ACC1_YYSCALE);
    PARAM_DECLARE(ACC1_ZZSCALE);
    PARAM_DECLARE(ACC1_XYSCALE);
    PARAM_DECLARE(ACC1_XZSCALE);
    PARAM_DECLARE(ACC1_YZSCALE);
    PARAM_DECLARE(MAG1_XOFF);
    PARAM_DECLARE(MAG1_YOFF);
    PARAM_DECLARE(MAG1_ZOFF);
    PARAM_DECLARE(MAG1_XXSCALE);
    PARAM_DECLARE(MAG1_YYSCALE);
    PARAM_DECLARE(MAG1_ZZSCALE);
    PARAM_DECLARE(MAG1_XYSCALE);
    PARAM_DECLARE(MAG1_XZSCALE);
    PARAM_DECLARE(MAG1_YZSCALE);
    PARAM_DECLARE(LEVEL_XOFF);
    PARAM_DECLARE(LEVEL_YOFF);
    PARAM_DECLARE(LEVEL_ZOFF);
} PARAM_GROUP(CALIB);

typedef struct {
    PARAM_DECLARE(USE_EXTERN_FILTER);
} PARAM_GROUP(INS);

typedef struct {
    PARAM_DECLARE(THROTTLE_DZ);
    PARAM_DECLARE(YAW_DZ);
    PARAM_DECLARE(ROLL_DZ);
    PARAM_DECLARE(PITCH_DZ);
    PARAM_DECLARE(XY_P);
    PARAM_DECLARE(Z_P);
    PARAM_DECLARE(VEL_XY_LIM);
    PARAM_DECLARE(VEL_Z_LIM);
    PARAM_DECLARE(YAW_P);
    PARAM_DECLARE(YAW_RATE_LIM);
    PARAM_DECLARE(ROLL_PITCH_LIM);
} PARAM_GROUP(FMS);

typedef struct {
    PARAM_DECLARE(VEL_XY_P);
    PARAM_DECLARE(VEL_XY_I);
    PARAM_DECLARE(VEL_XY_D);
    PARAM_DECLARE(VEL_Z_P);
    PARAM_DECLARE(VEL_Z_I);
    PARAM_DECLARE(VEL_Z_D);
    PARAM_DECLARE(VEL_XY_I_MIN);
    PARAM_DECLARE(VEL_XY_I_MAX);
    PARAM_DECLARE(VEL_XY_D_MIN);
    PARAM_DECLARE(VEL_XY_D_MAX);
    PARAM_DECLARE(VEL_Z_I_MIN);
    PARAM_DECLARE(VEL_Z_I_MAX);
    PARAM_DECLARE(VEL_Z_D_MIN);
    PARAM_DECLARE(VEL_Z_D_MAX);

    PARAM_DECLARE(ROLL_P);
    PARAM_DECLARE(PITCH_P);
    PARAM_DECLARE(ROLL_PITCH_CMD_LIM);

    PARAM_DECLARE(ROLL_RATE_P);
    PARAM_DECLARE(PITCH_RATE_P);
    PARAM_DECLARE(YAW_RATE_P);
    PARAM_DECLARE(ROLL_RATE_I);
    PARAM_DECLARE(PITCH_RATE_I);
    PARAM_DECLARE(YAW_RATE_I);
    PARAM_DECLARE(ROLL_RATE_D);
    PARAM_DECLARE(PITCH_RATE_D);
    PARAM_DECLARE(YAW_RATE_D);
    PARAM_DECLARE(RATE_I_MIN);
    PARAM_DECLARE(RATE_I_MAX);
    PARAM_DECLARE(RATE_D_MIN);
    PARAM_DECLARE(RATE_D_MAX);
    PARAM_DECLARE(P_Q_CMD_LIM);
    PARAM_DECLARE(R_CMD_LIM);
} PARAM_GROUP(CONTROL);

/******************** Step 1: Declare Group ********************/
typedef struct {
    param_group_t PARAM_GROUP(SYSTEM);
    param_group_t PARAM_GROUP(CALIB);
    param_group_t PARAM_GROUP(INS);
    param_group_t PARAM_GROUP(FMS);
    param_group_t PARAM_GROUP(CONTROL);
} param_list_t;

/********************** Helper Macro **********************/
#define PARAM_GET(_group, _name) ((_param_##_group*)(param_list._param_##_group.content))->_name

#define PARAM_GET_INT8(_group, _name)   ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i8
#define PARAM_GET_UINT8(_group, _name)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u8
#define PARAM_GET_INT16(_group, _name)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i16
#define PARAM_GET_UINT16(_group, _name) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u16
#define PARAM_GET_INT32(_group, _name)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i32
#define PARAM_GET_UINT32(_group, _name) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u32
#define PARAM_GET_FLOAT(_group, _name)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.f
#define PARAM_GET_DOUBLE(_group, _name) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.lf

#define PARAM_SET_INT8(_group, _name, _val)   ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i8 = _val
#define PARAM_SET_UINT8(_group, _name, _val)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u8 = _val
#define PARAM_SET_INT16(_group, _name, _val)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i16 = _val
#define PARAM_SET_UINT16(_group, _name, _val) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u16 = _val
#define PARAM_SET_INT32(_group, _name, _val)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.i32 = _val
#define PARAM_SET_UINT32(_group, _name, _val) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.u32 = _val
#define PARAM_SET_FLOAT(_group, _name, _val)  ((_param_##_group*)(param_list._param_##_group.content))->_name.val.f = _val
#define PARAM_SET_DOUBLE(_group, _name, _val) ((_param_##_group*)(param_list._param_##_group.content))->_name.val.lf = _val
/************************************************************/

extern param_list_t param_list;

fmt_err_t param_init(void);
fmt_err_t param_save(char* path);
fmt_err_t param_load(char* path);

fmt_err_t param_set_val(param_t* param, void* val);
fmt_err_t param_set_val_by_name(char* param_name, void* val);
fmt_err_t param_set_val_by_full_name(char* group_name, char* param_name, void* val);
fmt_err_t param_set_string_val(param_t* param, char* val);
fmt_err_t param_set_string_val_by_name(char* param_name, char* val);
fmt_err_t param_set_string_val_by_full_name(char* group_name, char* param_name, char* val);

uint32_t param_get_count(void);
int16_t param_get_index(const param_t* param);
param_t* param_get_by_name(const char* param_name);
param_t* param_get_by_full_name(const char* group_name, const char* param_name);
param_t* param_get_by_index(int16_t index);

param_group_t* param_find_group(const char* group_name);

#ifdef __cplusplus
}
#endif

#endif
