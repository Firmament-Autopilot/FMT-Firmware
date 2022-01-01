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

#define MLOG_BUFFER_SIZE         40 * 1024
#define MLOG_SECTOR_SIZE         4096 /* larger block can increase write bandwidth */
#define MLOG_MAX_SECTOR_TO_WRITE 5

/* MLog Msg ID */
enum {
    /* must start from 1 */
    MLOG_IMU_ID = 1,
    MLOG_MAG_ID,
    MLOG_BARO_ID,
    MLOG_GPS_ID,
    MLOG_RANGEFINDER_ID,
    MLOG_OPTICAL_FLOW_ID,
    MLOG_PILOT_CMD_ID,
    MLOG_GCS_CMD_ID,
    MLOG_INS_OUT_ID,
    MLOG_FMS_OUT_ID,
    MLOG_CONTROL_OUT_ID,
#if defined(FMT_USING_SIH)
    MLOG_PLANT_STATE_ID,
#endif
};

enum {
    MLOG_CB_START,
    MLOG_CB_STOP,
    MLOG_CB_UPDATE,
};

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

LOGPACKED(
    typedef struct {
        char name[MLOG_MAX_NAME_LEN];
        uint16_t type;
        uint16_t number;
    })
mlog_elem_t;

LOGPACKED(
    typedef struct {
        char name[MLOG_MAX_NAME_LEN];
        uint8_t msg_id;
        uint8_t num_elem;
        mlog_elem_t* elem_list;
    })
mlog_bus_t;

LOGPACKED(
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
    })
mlog_header_t;

typedef struct {
    uint8_t* data;
    uint32_t head; // head point for sector
    uint32_t tail; // tail point for sector
    uint32_t num_sector;
    uint32_t index; // index in sector
} mlog_buffer_t;

#define MLOG_ELEMENT(_name, _type) \
    {                              \
#_name,                    \
            _type,                 \
            1                      \
    }

#define MLOG_ELEMENT_VEC(_name, _type, _num) \
    {                                        \
#_name,                              \
            _type,                           \
            _num                             \
    }

#define MLOG_BUS(_name, _id, _elem_list)              \
    {                                                 \
#_name,                                       \
            _id,                                      \
            sizeof(_elem_list) / sizeof(mlog_elem_t), \
            _elem_list                                \
    }

fmt_err_t mlog_add_desc(char* desc);
fmt_err_t mlog_start(char* file_name);
void mlog_stop(void);
fmt_err_t mlog_push_msg(const uint8_t* payload, uint8_t msg_id, uint16_t len);
uint8_t mlog_get_status(void);
char* mlog_get_file_name(void);
void mlog_statistic(void);
fmt_err_t mlog_register_callback(uint8_t cb_type, void (*cb)(void));
fmt_err_t mlog_init(void);
void mlog_async_output(void);

#ifdef __cplusplus
}
#endif

#endif