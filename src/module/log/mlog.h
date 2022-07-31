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

#ifndef MLOG_H__
#define MLOG_H__

#include <firmament.h>

#include "module/param/param.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to define packed structures */
#ifdef __GNUC__
    #define LOGPACKED(__Declaration__) __Declaration__ __attribute__((packed))
#else
    #define LOGPACKED(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#endif

#define MLOG_VERSION 1

#define MLOG_BEGIN_MSG1 0x92
#define MLOG_BEGIN_MSG2 0x05
#define MLOG_END_MSG    0x26

#define MLOG_MAX_NAME_LEN     20
#define MLOG_DESCRIPTION_SIZE 128
#define MLOG_MODEL_INFO_SIZE  256

typedef enum {
    MLOG_CB_START,
    MLOG_CB_STOP,
    MLOG_CB_UPDATE,
} mlog_cb_type;

enum {
    MLOG_INT8 = 0,
    MLOG_UINT8,
    MLOG_INT16,
    MLOG_UINT16,
    MLOG_INT32,
    MLOG_UINT32,
    MLOG_FLOAT,
    MLOG_DOUBLE,
    MLOG_BOOLEAN,
};

enum {
    MLOG_STATUS_IDLE = 0,
    MLOG_STATUS_WRITE_HEAD,
    MLOG_STATUS_LOGGING,
    MLOG_STATUS_STOPPING,
};

typedef struct {
    char name[MLOG_MAX_NAME_LEN];
    uint16_t type;
    uint16_t number;
} mlog_elem_t;

typedef struct {
    char name[MLOG_MAX_NAME_LEN];
    uint8_t num_elem;
    mlog_elem_t* elem_list;
} mlog_bus_t;

typedef struct {
    /* log info */
    uint16_t version;
    uint32_t timestamp;
    uint16_t max_name_len;
    uint16_t max_desc_len;
    uint16_t max_model_info_len;
    char description[MLOG_DESCRIPTION_SIZE];
    char model_info[MLOG_MODEL_INFO_SIZE];
    /* bus info */
    uint8_t num_bus;
    mlog_bus_t* bus_list;
    /* parameter info */
    uint8_t num_param_group;
    param_group_t* param_group_list;
} mlog_header_t;

typedef struct {
    uint8_t* data;
    uint32_t head; // head point for sector
    uint32_t tail; // tail point for sector
    uint32_t num_sector;
    uint32_t index; // index in sector
} mlog_buffer_t;

#define MLOG_ELEMENT(_name, _type) \
    {                              \
        .name = #_name,            \
        .type = _type,             \
        .number = 1                \
    }

#define MLOG_ELEMENT_VEC(_name, _type, _num) \
    {                                        \
        .name = #_name,                      \
        .type = _type,                       \
        .number = _num                       \
    }

#define MLOG_BUS_EXPORT                    RT_USED static const mlog_bus_t SECTION("MlogTab")
#define MLOG_BUS_DEFINE(_name, _elem_list) MLOG_BUS_EXPORT __mlog_bus_##_name = { \
    .name = #_name,                                                               \
    .num_elem = sizeof(_elem_list) / sizeof(mlog_elem_t),                         \
    .elem_list = _elem_list                                                       \
}

int mlog_get_bus_id(const char* bus_name);
fmt_err_t mlog_add_desc(char* desc);
fmt_err_t mlog_start(char* file_name);
void mlog_stop(void);
fmt_err_t mlog_push_msg(const uint8_t* payload, uint8_t msg_id, uint16_t len);
uint8_t mlog_get_status(void);
char* mlog_get_file_name(void);
void mlog_show_statistic(void);
fmt_err_t mlog_register_callback(mlog_cb_type type, void (*cb_func)(void));
fmt_err_t mlog_deregister_callback(mlog_cb_type type, void (*cb_func)(void));
fmt_err_t mlog_init(void);
void mlog_async_output(void);

#ifdef __cplusplus
}
#endif

#endif