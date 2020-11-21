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

#ifndef __BINARY_LOG_H__
#define __BINARY_LOG_H__

#include <firmament.h>

/* Macro to define packed structures */
#ifdef __GNUC__
#define LOGPACKED(__Declaration__) __Declaration__ __attribute__((packed))
#else
#define LOGPACKED(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#endif

#define BLOG_VERSION 1

#define BLOG_BEGIN_MSG1 0x92
#define BLOG_BEGIN_MSG2 0x05
#define BLOG_END_MSG    0x26

#define BLOG_MAX_NAME_LEN     20
#define BLOG_DESCRIPTION_SIZE 128
#define BLOG_MODEL_INFO_SIZE  256

// #define BLOG_BUFFER_SIZE            16384*3
// #define BLOG_SECTOR_SIZE             16384    /* larger block can increase wrte bandwidth */

#define BLOG_BUFFER_SIZE         24 * 1024
#define BLOG_SECTOR_SIZE         4096 /* larger block can increase wrte bandwidth */
#define BLOG_MAX_SECTOR_TO_WRITE 3

/* BLog Msg ID */
enum {
    /* must start from 1 */
    BLOG_IMU_ID = 1,
    BLOG_MAG_ID,
    BLOG_BARO_ID,
    BLOG_GPS_ID,
    BLOG_RANGEFINDER_ID,
    BLOG_OPTICAL_FLOW_ID,
    BLOG_PILOT_CMD_ID,
    BLOG_INS_OUT_ID,
    BLOG_FMS_OUT_ID,
    BLOG_CONTROL_OUT_ID,
#if defined(FMT_USING_SIH)
    BLOG_PLANT_STATE_ID,
#endif
};

enum {
    BLOG_CB_START,
    BLOG_CB_STOP,
};

enum {
    BLOG_INT8 = 0,
    BLOG_UINT8,
    BLOG_INT16,
    BLOG_UINT16,
    BLOG_INT32,
    BLOG_UINT32,
    BLOG_FLOAT,
    BLOG_DOUBLE,
    BLOG_BOOLEAN,
};

enum {
    BLOG_STATUS_IDLE = 0,
    BLOG_STATUS_WRITE_HEAD,
    BLOG_STATUS_LOGGING,
    BLOG_STATUS_STOPPING,
};

LOGPACKED(
    typedef struct {
        char name[BLOG_MAX_NAME_LEN];
        uint16_t type;
        uint16_t number;
    })
blog_elem_t;

LOGPACKED(
    typedef struct {
        char name[BLOG_MAX_NAME_LEN];
        uint8_t msg_id;
        uint8_t num_elem;
        blog_elem_t* elem_list;
    })
blog_bus_t;

LOGPACKED(
    typedef struct {
        /* log info */
        uint16_t version;
        uint32_t timestamp;
        uint16_t max_name_len;
        uint16_t max_desc_len;
        uint16_t max_model_info_len;
        char description[BLOG_DESCRIPTION_SIZE];
        char model_info[BLOG_MODEL_INFO_SIZE];
        /* bus info */
        uint8_t num_bus;
        blog_bus_t* bus_list;
        /* parameter info */
        uint8_t num_param_group;
        param_group_t* param_group_list;
    })
blog_header_t;

typedef struct {
    uint8_t* data;
    uint32_t head; // head point for sector
    uint32_t tail; // tail point for sector
    uint32_t num_sector;
    uint32_t index; // index in sector
} blog_buffer_t;

#define BLOG_ELEMENT(_name, _type) \
    {                              \
#_name,                    \
            _type,                 \
            1                      \
    }

#define BLOG_ELEMENT_VEC(_name, _type, _num) \
    {                                        \
#_name,                              \
            _type,                           \
            _num                             \
    }

#define BLOG_BUS(_name, _id, _elem_list)              \
    {                                                 \
#_name,                                       \
            _id,                                      \
            sizeof(_elem_list) / sizeof(blog_elem_t), \
            _elem_list                                \
    }

fmt_err blog_add_desc(char* desc);
fmt_err blog_start(char* file_name);
void blog_stop(void);
fmt_err blog_push_msg(const uint8_t* payload, uint8_t msg_id, uint16_t len);

uint8_t blog_get_status(void);
char* blog_get_logging_file_name(void);
void blog_show_status(void);

fmt_err blog_register_callback(uint8_t cb_type, void (*cb)(void));

void blog_init(void);
void blog_async_output(void);

#endif