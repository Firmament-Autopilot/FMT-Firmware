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
#include <string.h>

#include "module/controller/controller_model.h"
#include "module/file_manager/file_manager.h"
#include "module/fms/fms_model.h"
#include "module/ins/ins_model.h"
#ifdef FMT_USING_SIH
#include "module/plant/plant_model.h"
#endif

#define TAG                   "BLog"
#define BLOG_MAX_CALLBACK_NUM 10

#define WRITE_PAYLOAD(_payload, _len) write(blog_handle.fid, _payload, _len);

/* BLog element define */
blog_elem_t IMU_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("gyr_x", BLOG_FLOAT),
    BLOG_ELEMENT("gyr_y", BLOG_FLOAT),
    BLOG_ELEMENT("gyr_z", BLOG_FLOAT),
    BLOG_ELEMENT("acc_x", BLOG_FLOAT),
    BLOG_ELEMENT("acc_y", BLOG_FLOAT),
    BLOG_ELEMENT("acc_z", BLOG_FLOAT),
};

blog_elem_t MAG_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("mag_x", BLOG_FLOAT),
    BLOG_ELEMENT("mag_y", BLOG_FLOAT),
    BLOG_ELEMENT("mag_z", BLOG_FLOAT),
};

blog_elem_t Barometer_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("pressure", BLOG_FLOAT),
    BLOG_ELEMENT("temperature", BLOG_FLOAT),
};

blog_elem_t GPS_uBlox_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("iTOW", BLOG_UINT32),
    BLOG_ELEMENT("year", BLOG_UINT16),
    BLOG_ELEMENT("month", BLOG_UINT8),
    BLOG_ELEMENT("day", BLOG_UINT8),
    BLOG_ELEMENT("hour", BLOG_UINT8),
    BLOG_ELEMENT("min", BLOG_UINT8),
    BLOG_ELEMENT("sec", BLOG_UINT8),
    BLOG_ELEMENT("valid", BLOG_UINT8),
    BLOG_ELEMENT("tAcc", BLOG_UINT32),
    BLOG_ELEMENT("nano", BLOG_INT32),
    BLOG_ELEMENT("fixType", BLOG_UINT8),
    BLOG_ELEMENT("flags", BLOG_UINT8),
    BLOG_ELEMENT("reserved1", BLOG_UINT8),
    BLOG_ELEMENT("numSV", BLOG_UINT8),
    BLOG_ELEMENT("lon", BLOG_INT32),
    BLOG_ELEMENT("lat", BLOG_INT32),
    BLOG_ELEMENT("height", BLOG_INT32),
    BLOG_ELEMENT("hMSL", BLOG_INT32),
    BLOG_ELEMENT("hAcc", BLOG_UINT32),
    BLOG_ELEMENT("vAcc", BLOG_UINT32),
    BLOG_ELEMENT("velN", BLOG_INT32),
    BLOG_ELEMENT("velE", BLOG_INT32),
    BLOG_ELEMENT("velD", BLOG_INT32),
    BLOG_ELEMENT("gSpeed", BLOG_INT32),
    BLOG_ELEMENT("heading", BLOG_INT32),
    BLOG_ELEMENT("sAcc", BLOG_UINT32),
    BLOG_ELEMENT("headingAcc", BLOG_UINT32),
    BLOG_ELEMENT("pDOP", BLOG_UINT16),
    BLOG_ELEMENT("reserved2", BLOG_UINT16),
};

blog_elem_t Rangefinder_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("distance_m", BLOG_FLOAT),
};

blog_elem_t Optflow_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("vx", BLOG_FLOAT),
    BLOG_ELEMENT("vy", BLOG_FLOAT),
    BLOG_ELEMENT("valid", BLOG_UINT32),
};

blog_elem_t Pilot_Cmd_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("ls_lr", BLOG_FLOAT),
    BLOG_ELEMENT("ls_ud", BLOG_FLOAT),
    BLOG_ELEMENT("rs_lr", BLOG_FLOAT),
    BLOG_ELEMENT("rs_ud", BLOG_FLOAT),
    BLOG_ELEMENT("mode", BLOG_UINT32),
    BLOG_ELEMENT("cmd_1", BLOG_UINT32),
    BLOG_ELEMENT("cmd_2", BLOG_UINT32),
};

blog_elem_t INS_Out_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("phi", BLOG_FLOAT),
    BLOG_ELEMENT("theta", BLOG_FLOAT),
    BLOG_ELEMENT("psi", BLOG_FLOAT),
    BLOG_ELEMENT_VEC("quat", BLOG_FLOAT, 4),
    BLOG_ELEMENT("p", BLOG_FLOAT),
    BLOG_ELEMENT("q", BLOG_FLOAT),
    BLOG_ELEMENT("r", BLOG_FLOAT),
    BLOG_ELEMENT("ax", BLOG_FLOAT),
    BLOG_ELEMENT("ay", BLOG_FLOAT),
    BLOG_ELEMENT("az", BLOG_FLOAT),
    BLOG_ELEMENT("vn", BLOG_FLOAT),
    BLOG_ELEMENT("ve", BLOG_FLOAT),
    BLOG_ELEMENT("vd", BLOG_FLOAT),
    BLOG_ELEMENT("reserved", BLOG_FLOAT),
    BLOG_ELEMENT("lon", BLOG_DOUBLE),
    BLOG_ELEMENT("lat", BLOG_DOUBLE),
    BLOG_ELEMENT("alt", BLOG_DOUBLE),
    BLOG_ELEMENT("x_R", BLOG_FLOAT),
    BLOG_ELEMENT("y_R", BLOG_FLOAT),
    BLOG_ELEMENT("h_R", BLOG_FLOAT),
    BLOG_ELEMENT("h_AGL", BLOG_FLOAT),
    BLOG_ELEMENT("flag", BLOG_UINT32),
    BLOG_ELEMENT("status", BLOG_UINT32),
};

blog_elem_t FMS_Out_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("p_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("q_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("r_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("phi_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("theta_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("psi_rate_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("u_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("v_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("w_cmd", BLOG_FLOAT),
    BLOG_ELEMENT("throttle_cmd", BLOG_UINT32),
    BLOG_ELEMENT_VEC("actuator_cmd", BLOG_UINT16, 16),
    BLOG_ELEMENT("state", BLOG_UINT8),
    BLOG_ELEMENT("mode", BLOG_UINT8),
    BLOG_ELEMENT("reset", BLOG_UINT8),
    BLOG_ELEMENT("reserved", BLOG_UINT8),
};

blog_elem_t Control_Out_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT_VEC("actuator_cmd", BLOG_UINT16, 16),
};

#if defined(FMT_USING_SIH)
blog_elem_t Plant_States_Elems[] = {
    BLOG_ELEMENT("timestamp", BLOG_UINT32),
    BLOG_ELEMENT("phi", BLOG_FLOAT),
    BLOG_ELEMENT("theta", BLOG_FLOAT),
    BLOG_ELEMENT("psi", BLOG_FLOAT),
    BLOG_ELEMENT("rot_x_B", BLOG_FLOAT),
    BLOG_ELEMENT("rot_y_B", BLOG_FLOAT),
    BLOG_ELEMENT("rot_z_B", BLOG_FLOAT),
    BLOG_ELEMENT("acc_x_O", BLOG_FLOAT),
    BLOG_ELEMENT("acc_y_O", BLOG_FLOAT),
    BLOG_ELEMENT("acc_z_O", BLOG_FLOAT),
    BLOG_ELEMENT("vel_x_O", BLOG_FLOAT),
    BLOG_ELEMENT("vel_y_O", BLOG_FLOAT),
    BLOG_ELEMENT("vel_z_O", BLOG_FLOAT),
    BLOG_ELEMENT("x_R", BLOG_FLOAT),
    BLOG_ELEMENT("y_R", BLOG_FLOAT),
    BLOG_ELEMENT("h_R", BLOG_FLOAT),
    BLOG_ELEMENT("lon", BLOG_DOUBLE),
    BLOG_ELEMENT("lat", BLOG_DOUBLE),
    BLOG_ELEMENT("alt", BLOG_DOUBLE),
    BLOG_ELEMENT("lon_ref", BLOG_DOUBLE),
    BLOG_ELEMENT("lat_ref", BLOG_DOUBLE),
    BLOG_ELEMENT("alt_ref", BLOG_DOUBLE),
};
#endif

/* BLog bus define */
blog_bus_t _blog_bus[] = {
    BLOG_BUS("IMU", BLOG_IMU_ID, IMU_Elems),
    BLOG_BUS("MAG", BLOG_MAG_ID, MAG_Elems),
    BLOG_BUS("Barometer", BLOG_BARO_ID, Barometer_Elems),
    BLOG_BUS("GPS_uBlox", BLOG_GPS_ID, GPS_uBlox_Elems),
    BLOG_BUS("Rangefinder", BLOG_RANGEFINDER_ID, Rangefinder_Elems),
    BLOG_BUS("Optical_Flow", BLOG_OPTICAL_FLOW_ID, Optflow_Elems),
    BLOG_BUS("Pilot_Cmd", BLOG_PILOT_CMD_ID, Pilot_Cmd_Elems),
    BLOG_BUS("INS_Out", BLOG_INS_OUT_ID, INS_Out_Elems),
    BLOG_BUS("FMS_Out", BLOG_FMS_OUT_ID, FMS_Out_Elems),
    BLOG_BUS("Control_Out", BLOG_CONTROL_OUT_ID, Control_Out_Elems),
#if defined(FMT_USING_SIH)
    BLOG_BUS("Plant_States", BLOG_PLANT_STATE_ID, Plant_States_Elems),
#endif
};

typedef struct {
    uint32_t total_msg;
    uint32_t lost_msg;
} blog_stat_t;

struct fmt_blog {
    int fid;
    uint8_t is_open;
    char file_name[50];
    uint8_t log_status;
    blog_header_t header;
    blog_buffer_t buffer;
    struct rt_mutex lock;
    blog_stat_t monitor[sizeof(_blog_bus) / sizeof(blog_bus_t)];
};

static struct fmt_blog blog_handle = { 0 };
static void (*blog_start_cbs[BLOG_MAX_CALLBACK_NUM])(void);
static void (*blog_stop_cbs[BLOG_MAX_CALLBACK_NUM])(void);
static void (*blog_update_cbs[BLOG_MAX_CALLBACK_NUM])(void);

static void __invoke_callback_func(uint8_t cb_type)
{
    uint32_t i;

    if (cb_type == BLOG_CB_START) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_start_cbs[i]) {
                blog_start_cbs[i]();
            }
        }
    }

    if (cb_type == BLOG_CB_STOP) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_stop_cbs[i]) {
                blog_stop_cbs[i]();
            }
        }
    }

    if (cb_type == BLOG_CB_UPDATE) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_update_cbs[i]) {
                blog_update_cbs[i]();
            }
        }
    }
}

static void __buffer_putc(uint8_t ch)
{
    uint32_t free_space_in_sector = BLOG_SECTOR_SIZE - blog_handle.buffer.index;

    if (free_space_in_sector < 1) {
        // move head point to next sector
        blog_handle.buffer.head = (blog_handle.buffer.head + 1) % blog_handle.buffer.num_sector;
        blog_handle.buffer.index = 0;

        /* we have a new sector data, inform callback functions */
        __invoke_callback_func(BLOG_CB_UPDATE);
    }

    blog_handle.buffer.data[blog_handle.buffer.head * BLOG_SECTOR_SIZE + blog_handle.buffer.index] = ch;
    blog_handle.buffer.index += 1;
}

static void __buffer_write(const uint8_t* data, uint16_t len)
{
    uint32_t free_space_in_sector = BLOG_SECTOR_SIZE - blog_handle.buffer.index;

    // TODO: add support with len larger than BLOG_SECTOR_SIZE

    if (free_space_in_sector < len) {
        memcpy(&blog_handle.buffer.data[blog_handle.buffer.head * BLOG_SECTOR_SIZE + blog_handle.buffer.index], data, free_space_in_sector);

        // move head point to next sector
        blog_handle.buffer.head = (blog_handle.buffer.head + 1) % blog_handle.buffer.num_sector;
        blog_handle.buffer.index = 0;

        memcpy(&blog_handle.buffer.data[blog_handle.buffer.head * BLOG_SECTOR_SIZE + blog_handle.buffer.index], &data[free_space_in_sector], len - free_space_in_sector);
        blog_handle.buffer.index += len - free_space_in_sector;

        /* we have a new sector data, inform callback functions */
        __invoke_callback_func(BLOG_CB_UPDATE);
    } else {
        memcpy(&blog_handle.buffer.data[blog_handle.buffer.head * BLOG_SECTOR_SIZE + blog_handle.buffer.index], data, len);
        blog_handle.buffer.index += len;
    }
}

static int32_t get_bus_index(uint8_t msg_id)
{
    for (int i = 0; i < sizeof(_blog_bus) / sizeof(blog_bus_t); i++) {
        if (_blog_bus[i].msg_id == msg_id) {
            return i;
        }
    }

    return -1;
}

static uint16_t get_max_write_sector(uint32_t head_p, uint32_t tail_p)
{
    uint16_t sector_to_end;
    uint16_t sector_in_buffer;
    uint16_t sector_to_write;

    sector_to_end = blog_handle.buffer.num_sector - tail_p;

    if (head_p >= tail_p) {
        sector_in_buffer = head_p - tail_p;
    } else {
        sector_in_buffer = sector_to_end + head_p;
    }

    sector_to_write = sector_in_buffer < sector_to_end ? sector_in_buffer : sector_to_end;

    return sector_to_write <= BLOG_MAX_SECTOR_TO_WRITE ? sector_to_write : BLOG_MAX_SECTOR_TO_WRITE;
}

static bool buffer_is_full(uint32_t len_to_write)
{
    uint32_t free_space_in_sector = BLOG_SECTOR_SIZE - blog_handle.buffer.index;

    // TODO: check if write multiple sectors at once

    /* check if buffer is full */
    if (free_space_in_sector < len_to_write) {
        if ((blog_handle.buffer.head + 1) % blog_handle.buffer.num_sector == blog_handle.buffer.tail) {
            return true;
        }
    }

    return false;
}

/**
 * Get current logging status
 *
 * @return blog status: BLOG_STATUS_IDLE | BLOG_STATUS_WRITE_HEAD | BLOG_STATUS_LOGGING | BLOG_STATUS_STOPPING
 */
uint8_t blog_get_status(void)
{
    return blog_handle.log_status;
}

/**
 * Get current logging file name
 *
 * @return blog logging file name
 */
char* blog_get_file_name(void)
{
    return blog_handle.file_name;
}

/**
 * Show the blog logging statistics
 *
 */
void blog_statistic(void)
{
    for (int i = 0; i < sizeof(_blog_bus) / sizeof(blog_bus_t); i++) {
        console_printf("%-20s id:%-3d record:%-8ld lost:%-5ld\n", _blog_bus[i].name, _blog_bus[i].msg_id,
            blog_handle.monitor[i].total_msg, blog_handle.monitor[i].lost_msg);
    }
}

/**
 * Register blog callback function
 *
 * @param cb_type BLOG_CB_START | BLOG_CB_STOP | BLOG_CB_UPDATE
 * @param cb callback function
 * 
 * @return FMT Error
 */
fmt_err_t blog_register_callback(uint8_t cb_type, void (*cb)(void))
{
    uint32_t i;

    if (cb == NULL) {
        return FMT_ERROR;
    }

    if (cb_type == BLOG_CB_START) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_start_cbs[i] == NULL) {
                blog_start_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else if (cb_type == BLOG_CB_STOP) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_stop_cbs[i] == NULL) {
                blog_stop_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else if (cb_type == BLOG_CB_UPDATE) {
        for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
            if (blog_update_cbs[i] == NULL) {
                blog_update_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else {
        return FMT_EINVAL;
    }

    return FMT_ERROR;
}

/**
 * Add log description into blog header
 *
 * @param desc description text, should not longer than BLOG_DESCRIPTION_SIZE
 * @return FMT Error
 */
fmt_err_t blog_add_desc(char* desc)
{
    if (strlen(desc) > BLOG_DESCRIPTION_SIZE - 1) {
        ulog_w(TAG, "description too long.");
        return FMT_ENOMEM;
    }

    strcpy(blog_handle.header.description, desc);

    return FMT_EOK;
}

/**
 * Push a blog message into buffer
 *
 * @param payload msg payload
 * @param msg_id msg id
 * @param len msg length
 * 
 * @return FMT Error
 */
fmt_err_t blog_push_msg(const uint8_t* payload, uint8_t msg_id, uint16_t len)
{
    /*                           BLOG MSG Format                                 */
    /*   ======================================================================= */
    /*   | BLOG_BEGIN_MSG1 | BLOG_BEGIN_MSG2 | MSG_ID | PAYLOAD | BLOG_END_MSG | */
    /*   ======================================================================= */
    int32_t bus_index;

    /* check log status */
    if (blog_handle.log_status != BLOG_STATUS_LOGGING) {
        return FMT_EEMPTY;
    }

    /* check if buffer has enough space to store msg */
    if (buffer_is_full(len + 4)) {
        /* do not let it print too fast */
        TIMETAG_CHECK_EXECUTE(blog_buff_full, 1000, ulog_w(TAG, "buffer is full!"););
        return FMT_EFULL;
    }

    rt_mutex_take(&blog_handle.lock, RT_WAITING_FOREVER);

    /* write msg begin flag */
    __buffer_putc(BLOG_BEGIN_MSG1);
    __buffer_putc(BLOG_BEGIN_MSG2);
    /* write msg id */
    __buffer_putc(msg_id);
    /* write payload */
    __buffer_write(payload, len);
    /* write msg end flag */
    __buffer_putc(BLOG_END_MSG);

    rt_mutex_release(&blog_handle.lock);

    bus_index = get_bus_index(msg_id);
    if (bus_index >= 0) {
        blog_handle.monitor[bus_index].total_msg += 1;
    }

    return FMT_EOK;
}

/**
 * Call this function to start the binary log
 *
 * @param file_name blog_handle file name with full path
 * @return FMT Error
 */
fmt_err_t blog_start(char* file_name)
{
    if (blog_handle.log_status != BLOG_STATUS_IDLE) {
        ulog_w(TAG, "%s is logging, stop it first", blog_handle.file_name);
        return FMT_EBUSY;
    }

    /*********************** create log file ***********************/
    blog_handle.fid = open(file_name, O_CREAT | O_WRONLY);

    if (blog_handle.fid < 0) {
        ulog_e(TAG, "%s open fail", file_name);
        return FMT_ERROR;
    }
    /* set log file open flag */
    blog_handle.is_open = 1;
    /* get current time stamp */
    blog_handle.header.timestamp = systime_now_ms();

    /*********************** init log buffer ***********************/
    blog_handle.buffer.head = blog_handle.buffer.tail = 0;
    blog_handle.buffer.index = 0;

    /*********************** write log header ***********************/
    blog_handle.log_status = BLOG_STATUS_WRITE_HEAD;

    /* write log info */
    WRITE_PAYLOAD(&blog_handle.header.version, sizeof(blog_handle.header.version));
    WRITE_PAYLOAD(&blog_handle.header.timestamp, sizeof(blog_handle.header.timestamp));
    WRITE_PAYLOAD(&blog_handle.header.max_name_len, sizeof(blog_handle.header.max_name_len));
    WRITE_PAYLOAD(&blog_handle.header.max_desc_len, sizeof(blog_handle.header.max_desc_len));
    WRITE_PAYLOAD(&blog_handle.header.max_model_info_len, sizeof(blog_handle.header.max_model_info_len));
    WRITE_PAYLOAD(blog_handle.header.description, BLOG_DESCRIPTION_SIZE);
    /* clear the description after it has been written */
    memset(blog_handle.header.description, 0, BLOG_DESCRIPTION_SIZE);

    /* write model information */
#ifdef FMT_USING_SIH
    sprintf(blog_handle.header.model_info, "%s\n%s\n%s\n%s", (char*)INS_EXPORT.model_info, (char*)FMS_EXPORT.model_info,
        (char*)CONTROL_EXPORT.model_info, (char*)PLANT_EXPORT.model_info);
#else
    sprintf(blog_handle.header.model_info, "%s\n%s\n%s", (char*)INS_EXPORT.model_info, (char*)FMS_EXPORT.model_info,
        (char*)CONTROL_EXPORT.model_info);
#endif
    WRITE_PAYLOAD(blog_handle.header.model_info, BLOG_MODEL_INFO_SIZE);

    /* write bus information */
    WRITE_PAYLOAD(&blog_handle.header.num_bus, sizeof(blog_handle.header.num_bus));
    for (int n = 0; n < blog_handle.header.num_bus; n++) {
        /* write bus list */
        WRITE_PAYLOAD(blog_handle.header.bus_list[n].name, BLOG_MAX_NAME_LEN);
        WRITE_PAYLOAD(&blog_handle.header.bus_list[n].msg_id, sizeof(blog_handle.header.bus_list[n].msg_id));
        WRITE_PAYLOAD(&blog_handle.header.bus_list[n].num_elem, sizeof(blog_handle.header.bus_list[n].num_elem));
        /* write bus element */
        for (int k = 0; k < blog_handle.header.bus_list[n].num_elem; k++) {
            WRITE_PAYLOAD(blog_handle.header.bus_list[n].elem_list[k].name, BLOG_MAX_NAME_LEN);
            WRITE_PAYLOAD(&blog_handle.header.bus_list[n].elem_list[k].type, sizeof(blog_handle.header.bus_list[n].elem_list[k].type));
            WRITE_PAYLOAD(&blog_handle.header.bus_list[n].elem_list[k].number, sizeof(blog_handle.header.bus_list[n].elem_list[k].number));
        }
    }

    /*********************** write parameter information ***********************/
    char name_buffer[BLOG_MAX_NAME_LEN + 1];

    WRITE_PAYLOAD(&blog_handle.header.num_param_group, sizeof(blog_handle.header.num_param_group));
    for (int n = 0; n < blog_handle.header.num_param_group; n++) {
        memset(name_buffer, 0, BLOG_MAX_NAME_LEN);
        strncpy(name_buffer, blog_handle.header.param_group_list[n].name, BLOG_MAX_NAME_LEN);

        WRITE_PAYLOAD(name_buffer, BLOG_MAX_NAME_LEN);
        WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].param_num, sizeof(blog_handle.header.param_group_list[n].param_num));

        for (int k = 0; k < blog_handle.header.param_group_list[n].param_num; k++) {
            memset(name_buffer, 0, BLOG_MAX_NAME_LEN);
            strncpy(name_buffer, blog_handle.header.param_group_list[n].content[k].name, BLOG_MAX_NAME_LEN);

            WRITE_PAYLOAD(name_buffer, BLOG_MAX_NAME_LEN);
            WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].type, sizeof(blog_handle.header.param_group_list[n].content[k].type));

            int type = blog_handle.header.param_group_list[n].content[k].type;

            if (type == PARAM_TYPE_INT8) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.i8, sizeof(int8_t));
            } else if (type == PARAM_TYPE_UINT8) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.u8, sizeof(uint8_t));
            } else if (type == PARAM_TYPE_INT16) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.i16, sizeof(int16_t));
            } else if (type == PARAM_TYPE_UINT16) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.u16, sizeof(uint16_t));
            } else if (type == PARAM_TYPE_INT32) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.i32, sizeof(int32_t));
            } else if (type == PARAM_TYPE_UINT32) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.u32, sizeof(uint32_t));
            } else if (type == PARAM_TYPE_FLOAT) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.f, sizeof(float));
            } else if (type == PARAM_TYPE_DOUBLE) {
                WRITE_PAYLOAD(&blog_handle.header.param_group_list[n].content[k].val.lf, sizeof(double));
            } else {
                ulog_w(TAG, "unknown parameter type:%d", type);
            }
        }
    }

    /*********************** set log status ***********************/
    strncpy(blog_handle.file_name, file_name, sizeof(blog_handle.file_name) - 1);

    for (int i = 0; i < sizeof(_blog_bus) / sizeof(blog_bus_t); i++) {
        blog_handle.monitor[i].total_msg = 0;
        blog_handle.monitor[i].lost_msg = 0;
    }
    /* invoke callback function */
    __invoke_callback_func(BLOG_CB_START);
    /* start logging, set flag */
    blog_handle.log_status = BLOG_STATUS_LOGGING;

    ulog_i(TAG, "start logging:%s", file_name);

    return FMT_EOK;
}

/**
 * Call this function to stop the binary log
 *
 */
void blog_stop(void)
{
    /* here we just set log status to stopping, it actually stops
       when the blog_async_output() is called later */
    if (blog_handle.log_status == BLOG_STATUS_LOGGING) {
        blog_handle.log_status = BLOG_STATUS_STOPPING;
    }
}

/**
 * Asynchronous binary logs to storage device
 *
 * @note you must call this function periodically
 */
void blog_async_output(void)
{
    uint32_t head_p, tail_p;
    uint8_t need_sync = 0;

    if (!blog_handle.is_open) {
        /* no log file is opened */
        return;
    }

    OS_ENTER_CRITICAL;
    head_p = blog_handle.buffer.head;
    tail_p = blog_handle.buffer.tail;
    OS_EXIT_CRITICAL;

    /* check if we need synchronous the output */
    need_sync = (head_p != tail_p);
    /* write log buffer sector into storage device */
    while (head_p != tail_p) {
        /* check how many sectors that we can write at once */
        uint16_t sector_to_write = get_max_write_sector(head_p, tail_p);
        /* write data to the storage device */
        write(blog_handle.fid, &blog_handle.buffer.data[tail_p * BLOG_SECTOR_SIZE], sector_to_write * BLOG_SECTOR_SIZE);
        /* update buffer pointer */
        tail_p = (tail_p + sector_to_write) % blog_handle.buffer.num_sector;
        OS_ENTER_CRITICAL;
        blog_handle.buffer.tail = tail_p;
        OS_EXIT_CRITICAL;
    }

    /* synchronous the disk to make sure data have been written */
    if (need_sync) {
        fsync(blog_handle.fid);
    }

    /* if logging is off, clean up the buffer. */
    if (blog_handle.log_status == BLOG_STATUS_STOPPING) {
        /* dump rest data in buffer */
        if (blog_handle.buffer.index) {
            write(blog_handle.fid, &blog_handle.buffer.data[tail_p * BLOG_SECTOR_SIZE], blog_handle.buffer.index);
            fsync(blog_handle.fid);
        }
        /* close the file if needed */
        if (blog_handle.is_open) {
            close(blog_handle.fid);
            blog_handle.fid = -1;
            blog_handle.is_open = 0;
        }
        /* invoke callback function */
        __invoke_callback_func(BLOG_CB_STOP);
        /* set log status to idle */
        blog_handle.log_status = BLOG_STATUS_IDLE;

        ulog_i(TAG, "stop logging:%s", blog_handle.file_name);
        for (int i = 0; i < sizeof(_blog_bus) / sizeof(blog_bus_t); i++) {
            ulog_i(TAG, "%-20s id:%-3d record:%-8d lost:%-5d", _blog_bus[i].name, _blog_bus[i].msg_id,
                blog_handle.monitor[i].total_msg, blog_handle.monitor[i].lost_msg);
        }
    }
}

/**
 * Initialize binary log module.
 * 
 * @return FMT Errors.
 */
fmt_err_t binary_log_init(void)
{
    int i;

    /* initialize blog_handle status */
    blog_handle.is_open = 0;
    blog_handle.log_status = BLOG_STATUS_IDLE;
    /* initialize log header */
    blog_handle.header.version = BLOG_VERSION;
    blog_handle.header.timestamp = 0;
    blog_handle.header.max_name_len = BLOG_MAX_NAME_LEN;
    blog_handle.header.max_desc_len = BLOG_DESCRIPTION_SIZE;
    blog_handle.header.max_model_info_len = BLOG_MODEL_INFO_SIZE;
    blog_handle.header.num_bus = sizeof(_blog_bus) / sizeof(blog_bus_t);
    blog_handle.header.bus_list = _blog_bus;
    blog_handle.header.num_param_group = sizeof(param_list) / sizeof(param_group_t);
    blog_handle.header.param_group_list = (param_group_t*)&param_list;
    memset(blog_handle.header.description, 0, BLOG_DESCRIPTION_SIZE);

    /* initialize blog_handle buffer */
    blog_handle.buffer.data = (uint8_t*)rt_malloc(BLOG_BUFFER_SIZE);
    if (blog_handle.buffer.data == NULL) {
        console_printf("blog_handle buffer malloc fail!\n");
        return FMT_ENOMEM;
    } else {
        /* initialize buffer */
        blog_handle.buffer.num_sector = BLOG_BUFFER_SIZE / BLOG_SECTOR_SIZE;
        blog_handle.buffer.head = 0;
        blog_handle.buffer.tail = 0;
        blog_handle.buffer.index = 0;
    }

    /* create write lock */
    if (rt_mutex_init(&blog_handle.lock, "blog_lock", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("fail to create blog lock!\n");
        return FMT_ERROR;
    }

    /* clear callback functions */
    for (i = 0; i < BLOG_MAX_CALLBACK_NUM; i++) {
        blog_start_cbs[i] = NULL;
        blog_stop_cbs[i] = NULL;
        blog_update_cbs[i] = NULL;
    }

    return FMT_EOK;
}