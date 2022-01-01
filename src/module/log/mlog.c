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

#include "module/control/control_interface.h"
#include "module/file_manager/file_manager.h"
#include "module/fms/fms_interface.h"
#include "module/ins/ins_interface.h"
#ifdef FMT_USING_SIH
#include "module/plant/plant_interface.h"
#endif

#define TAG                   "MLog"
#define MLOG_MAX_CALLBACK_NUM 10

#define WRITE_PAYLOAD(_payload, _len) write(mlog_handle.fid, _payload, _len);

/* MLog element define */
mlog_elem_t IMU_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("gyr_x", MLOG_FLOAT),
    MLOG_ELEMENT("gyr_y", MLOG_FLOAT),
    MLOG_ELEMENT("gyr_z", MLOG_FLOAT),
    MLOG_ELEMENT("acc_x", MLOG_FLOAT),
    MLOG_ELEMENT("acc_y", MLOG_FLOAT),
    MLOG_ELEMENT("acc_z", MLOG_FLOAT),
};

mlog_elem_t MAG_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("mag_x", MLOG_FLOAT),
    MLOG_ELEMENT("mag_y", MLOG_FLOAT),
    MLOG_ELEMENT("mag_z", MLOG_FLOAT),
};

mlog_elem_t Barometer_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("pressure", MLOG_FLOAT),
    MLOG_ELEMENT("temperature", MLOG_FLOAT),
};

mlog_elem_t GPS_uBlox_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("iTOW", MLOG_UINT32),
    MLOG_ELEMENT("year", MLOG_UINT16),
    MLOG_ELEMENT("month", MLOG_UINT8),
    MLOG_ELEMENT("day", MLOG_UINT8),
    MLOG_ELEMENT("hour", MLOG_UINT8),
    MLOG_ELEMENT("min", MLOG_UINT8),
    MLOG_ELEMENT("sec", MLOG_UINT8),
    MLOG_ELEMENT("valid", MLOG_UINT8),
    MLOG_ELEMENT("tAcc", MLOG_UINT32),
    MLOG_ELEMENT("nano", MLOG_INT32),
    MLOG_ELEMENT("fixType", MLOG_UINT8),
    MLOG_ELEMENT("flags", MLOG_UINT8),
    MLOG_ELEMENT("reserved1", MLOG_UINT8),
    MLOG_ELEMENT("numSV", MLOG_UINT8),
    MLOG_ELEMENT("lon", MLOG_INT32),
    MLOG_ELEMENT("lat", MLOG_INT32),
    MLOG_ELEMENT("height", MLOG_INT32),
    MLOG_ELEMENT("hMSL", MLOG_INT32),
    MLOG_ELEMENT("hAcc", MLOG_UINT32),
    MLOG_ELEMENT("vAcc", MLOG_UINT32),
    MLOG_ELEMENT("velN", MLOG_INT32),
    MLOG_ELEMENT("velE", MLOG_INT32),
    MLOG_ELEMENT("velD", MLOG_INT32),
    MLOG_ELEMENT("gSpeed", MLOG_INT32),
    MLOG_ELEMENT("heading", MLOG_INT32),
    MLOG_ELEMENT("sAcc", MLOG_UINT32),
    MLOG_ELEMENT("headingAcc", MLOG_UINT32),
    MLOG_ELEMENT("pDOP", MLOG_UINT16),
    MLOG_ELEMENT("reserved2", MLOG_UINT16),
};

mlog_elem_t Rangefinder_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("distance_m", MLOG_FLOAT),
};

mlog_elem_t Optflow_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("vx", MLOG_FLOAT),
    MLOG_ELEMENT("vy", MLOG_FLOAT),
    MLOG_ELEMENT("valid", MLOG_UINT32),
};

mlog_elem_t Pilot_Cmd_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("stick_yaw", MLOG_FLOAT),
    MLOG_ELEMENT("stick_throttle", MLOG_FLOAT),
    MLOG_ELEMENT("stick_roll", MLOG_FLOAT),
    MLOG_ELEMENT("stick_pitch", MLOG_FLOAT),
    MLOG_ELEMENT("mode", MLOG_UINT32),
    MLOG_ELEMENT("cmd_1", MLOG_UINT32),
    MLOG_ELEMENT("cmd_2", MLOG_UINT32),
};

mlog_elem_t GCS_Cmd_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("mode", MLOG_UINT32),
    MLOG_ELEMENT("cmd_1", MLOG_UINT32),
    MLOG_ELEMENT("cmd_2", MLOG_UINT32),
};

mlog_elem_t INS_Out_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("phi", MLOG_FLOAT),
    MLOG_ELEMENT("theta", MLOG_FLOAT),
    MLOG_ELEMENT("psi", MLOG_FLOAT),
    MLOG_ELEMENT_VEC("quat", MLOG_FLOAT, 4),
    MLOG_ELEMENT("p", MLOG_FLOAT),
    MLOG_ELEMENT("q", MLOG_FLOAT),
    MLOG_ELEMENT("r", MLOG_FLOAT),
    MLOG_ELEMENT("ax", MLOG_FLOAT),
    MLOG_ELEMENT("ay", MLOG_FLOAT),
    MLOG_ELEMENT("az", MLOG_FLOAT),
    MLOG_ELEMENT("vn", MLOG_FLOAT),
    MLOG_ELEMENT("ve", MLOG_FLOAT),
    MLOG_ELEMENT("vd", MLOG_FLOAT),
    MLOG_ELEMENT("reserved", MLOG_FLOAT),
    MLOG_ELEMENT("lon", MLOG_DOUBLE),
    MLOG_ELEMENT("lat", MLOG_DOUBLE),
    MLOG_ELEMENT("alt", MLOG_DOUBLE),
    MLOG_ELEMENT("x_R", MLOG_FLOAT),
    MLOG_ELEMENT("y_R", MLOG_FLOAT),
    MLOG_ELEMENT("h_R", MLOG_FLOAT),
    MLOG_ELEMENT("h_AGL", MLOG_FLOAT),
    MLOG_ELEMENT("flag", MLOG_UINT32),
    MLOG_ELEMENT("status", MLOG_UINT32),
};

mlog_elem_t FMS_Out_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("p_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("q_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("r_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("phi_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("theta_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("psi_rate_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("u_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("v_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("w_cmd", MLOG_FLOAT),
    MLOG_ELEMENT("throttle_cmd", MLOG_UINT32),
    MLOG_ELEMENT_VEC("actuator_cmd", MLOG_UINT16, 16),
    MLOG_ELEMENT("status", MLOG_UINT8),
    MLOG_ELEMENT("state", MLOG_UINT8),
    MLOG_ELEMENT("ctrl_mode", MLOG_UINT8),
    MLOG_ELEMENT("reset", MLOG_UINT8),
    MLOG_ELEMENT("mode", MLOG_UINT8),
    MLOG_ELEMENT("reserved1", MLOG_UINT8),
    MLOG_ELEMENT("reserved2", MLOG_UINT16),
};

mlog_elem_t Control_Out_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT_VEC("actuator_cmd", MLOG_UINT16, 16),
};

#if defined(FMT_USING_SIH)
mlog_elem_t Plant_States_Elems[] = {
    MLOG_ELEMENT("timestamp", MLOG_UINT32),
    MLOG_ELEMENT("phi", MLOG_FLOAT),
    MLOG_ELEMENT("theta", MLOG_FLOAT),
    MLOG_ELEMENT("psi", MLOG_FLOAT),
    MLOG_ELEMENT("rot_x_B", MLOG_FLOAT),
    MLOG_ELEMENT("rot_y_B", MLOG_FLOAT),
    MLOG_ELEMENT("rot_z_B", MLOG_FLOAT),
    MLOG_ELEMENT("acc_x_O", MLOG_FLOAT),
    MLOG_ELEMENT("acc_y_O", MLOG_FLOAT),
    MLOG_ELEMENT("acc_z_O", MLOG_FLOAT),
    MLOG_ELEMENT("vel_x_O", MLOG_FLOAT),
    MLOG_ELEMENT("vel_y_O", MLOG_FLOAT),
    MLOG_ELEMENT("vel_z_O", MLOG_FLOAT),
    MLOG_ELEMENT("x_R", MLOG_FLOAT),
    MLOG_ELEMENT("y_R", MLOG_FLOAT),
    MLOG_ELEMENT("h_R", MLOG_FLOAT),
    MLOG_ELEMENT("lon", MLOG_DOUBLE),
    MLOG_ELEMENT("lat", MLOG_DOUBLE),
    MLOG_ELEMENT("alt", MLOG_DOUBLE),
    MLOG_ELEMENT("lon_ref", MLOG_DOUBLE),
    MLOG_ELEMENT("lat_ref", MLOG_DOUBLE),
    MLOG_ELEMENT("alt_ref", MLOG_DOUBLE),
};
#endif

/* MLog bus define */
mlog_bus_t _mlog_bus[] = {
    MLOG_BUS("IMU", MLOG_IMU_ID, IMU_Elems),
    MLOG_BUS("MAG", MLOG_MAG_ID, MAG_Elems),
    MLOG_BUS("Barometer", MLOG_BARO_ID, Barometer_Elems),
    MLOG_BUS("GPS_uBlox", MLOG_GPS_ID, GPS_uBlox_Elems),
    MLOG_BUS("Rangefinder", MLOG_RANGEFINDER_ID, Rangefinder_Elems),
    MLOG_BUS("Optical_Flow", MLOG_OPTICAL_FLOW_ID, Optflow_Elems),
    MLOG_BUS("Pilot_Cmd", MLOG_PILOT_CMD_ID, Pilot_Cmd_Elems),
    MLOG_BUS("GCS_Cmd", MLOG_GCS_CMD_ID, GCS_Cmd_Elems),
    MLOG_BUS("INS_Out", MLOG_INS_OUT_ID, INS_Out_Elems),
    MLOG_BUS("FMS_Out", MLOG_FMS_OUT_ID, FMS_Out_Elems),
    MLOG_BUS("Control_Out", MLOG_CONTROL_OUT_ID, Control_Out_Elems),
#if defined(FMT_USING_SIH)
    MLOG_BUS("Plant_States", MLOG_PLANT_STATE_ID, Plant_States_Elems),
#endif
};

typedef struct {
    uint32_t total_msg;
    uint32_t lost_msg;
} mlog_stat_t;

struct fmt_mlog {
    int fid;
    uint8_t is_open;
    char file_name[50];
    uint8_t log_status;
    mlog_header_t header;
    mlog_buffer_t buffer;
    struct rt_mutex lock;
    mlog_stat_t monitor[sizeof(_mlog_bus) / sizeof(mlog_bus_t)];
};

static struct fmt_mlog mlog_handle = { 0 };
static void (*mlog_start_cbs[MLOG_MAX_CALLBACK_NUM])(void);
static void (*mlog_stop_cbs[MLOG_MAX_CALLBACK_NUM])(void);
static void (*mlog_update_cbs[MLOG_MAX_CALLBACK_NUM])(void);

static void __invoke_callback_func(uint8_t cb_type)
{
    uint32_t i;

    if (cb_type == MLOG_CB_START) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_start_cbs[i]) {
                mlog_start_cbs[i]();
            }
        }
    }

    if (cb_type == MLOG_CB_STOP) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_stop_cbs[i]) {
                mlog_stop_cbs[i]();
            }
        }
    }

    if (cb_type == MLOG_CB_UPDATE) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_update_cbs[i]) {
                mlog_update_cbs[i]();
            }
        }
    }
}

static void __buffer_putc(uint8_t ch)
{
    uint32_t free_space_in_sector = MLOG_SECTOR_SIZE - mlog_handle.buffer.index;

    if (free_space_in_sector < 1) {
        // move head point to next sector
        mlog_handle.buffer.head = (mlog_handle.buffer.head + 1) % mlog_handle.buffer.num_sector;
        mlog_handle.buffer.index = 0;

        /* we have a new sector data, inform callback functions */
        __invoke_callback_func(MLOG_CB_UPDATE);
    }

    mlog_handle.buffer.data[mlog_handle.buffer.head * MLOG_SECTOR_SIZE + mlog_handle.buffer.index] = ch;
    mlog_handle.buffer.index += 1;
}

static void __buffer_write(const uint8_t* data, uint16_t len)
{
    uint32_t free_space_in_sector = MLOG_SECTOR_SIZE - mlog_handle.buffer.index;

    // TODO: add support with len larger than MLOG_SECTOR_SIZE

    if (free_space_in_sector < len) {
        memcpy(&mlog_handle.buffer.data[mlog_handle.buffer.head * MLOG_SECTOR_SIZE + mlog_handle.buffer.index], data, free_space_in_sector);

        // move head point to next sector
        mlog_handle.buffer.head = (mlog_handle.buffer.head + 1) % mlog_handle.buffer.num_sector;
        mlog_handle.buffer.index = 0;

        memcpy(&mlog_handle.buffer.data[mlog_handle.buffer.head * MLOG_SECTOR_SIZE + mlog_handle.buffer.index], &data[free_space_in_sector], len - free_space_in_sector);
        mlog_handle.buffer.index += len - free_space_in_sector;

        /* we have a new sector data, inform callback functions */
        __invoke_callback_func(MLOG_CB_UPDATE);
    } else {
        memcpy(&mlog_handle.buffer.data[mlog_handle.buffer.head * MLOG_SECTOR_SIZE + mlog_handle.buffer.index], data, len);
        mlog_handle.buffer.index += len;
    }
}

static int32_t get_bus_index(uint8_t msg_id)
{
    for (int i = 0; i < sizeof(_mlog_bus) / sizeof(mlog_bus_t); i++) {
        if (_mlog_bus[i].msg_id == msg_id) {
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

    sector_to_end = mlog_handle.buffer.num_sector - tail_p;

    if (head_p >= tail_p) {
        sector_in_buffer = head_p - tail_p;
    } else {
        sector_in_buffer = sector_to_end + head_p;
    }

    sector_to_write = sector_in_buffer < sector_to_end ? sector_in_buffer : sector_to_end;

    return sector_to_write <= MLOG_MAX_SECTOR_TO_WRITE ? sector_to_write : MLOG_MAX_SECTOR_TO_WRITE;
}

static bool buffer_is_full(uint32_t len_to_write)
{
    uint32_t free_space_in_sector = MLOG_SECTOR_SIZE - mlog_handle.buffer.index;

    // TODO: check if write multiple sectors at once

    /* check if buffer is full */
    if (free_space_in_sector < len_to_write) {
        if ((mlog_handle.buffer.head + 1) % mlog_handle.buffer.num_sector == mlog_handle.buffer.tail) {
            return true;
        }
    }

    return false;
}

/**
 * Get current logging status
 *
 * @return mlog status: MLOG_STATUS_IDLE | MLOG_STATUS_WRITE_HEAD | MLOG_STATUS_LOGGING | MLOG_STATUS_STOPPING
 */
uint8_t mlog_get_status(void)
{
    return mlog_handle.log_status;
}

/**
 * Get current logging file name
 *
 * @return mlog logging file name
 */
char* mlog_get_file_name(void)
{
    return mlog_handle.file_name;
}

/**
 * Show the mlog logging statistics
 *
 */
void mlog_statistic(void)
{
    for (int i = 0; i < sizeof(_mlog_bus) / sizeof(mlog_bus_t); i++) {
        console_printf("%-20s id:%-3d record:%-8ld lost:%-5ld\n", _mlog_bus[i].name, _mlog_bus[i].msg_id,
            mlog_handle.monitor[i].total_msg, mlog_handle.monitor[i].lost_msg);
    }
}

/**
 * Register mlog callback function
 *
 * @param cb_type MLOG_CB_START | MLOG_CB_STOP | MLOG_CB_UPDATE
 * @param cb callback function
 * 
 * @return FMT Error
 */
fmt_err_t mlog_register_callback(uint8_t cb_type, void (*cb)(void))
{
    uint32_t i;

    if (cb == NULL) {
        return FMT_ERROR;
    }

    if (cb_type == MLOG_CB_START) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_start_cbs[i] == NULL) {
                mlog_start_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else if (cb_type == MLOG_CB_STOP) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_stop_cbs[i] == NULL) {
                mlog_stop_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else if (cb_type == MLOG_CB_UPDATE) {
        for (i = 0; i < MLOG_MAX_CALLBACK_NUM; i++) {
            if (mlog_update_cbs[i] == NULL) {
                mlog_update_cbs[i] = cb;
                return FMT_EOK;
            }
        }
    } else {
        return FMT_EINVAL;
    }

    return FMT_ERROR;
}

/**
 * Add log description into mlog header
 *
 * @param desc description text, should not longer than MLOG_DESCRIPTION_SIZE
 * @return FMT Error
 */
fmt_err_t mlog_add_desc(char* desc)
{
    if (strlen(desc) > MLOG_DESCRIPTION_SIZE - 1) {
        ulog_w(TAG, "description too long.");
        return FMT_ENOMEM;
    }

    strcpy(mlog_handle.header.description, desc);

    return FMT_EOK;
}

/**
 * Push a mlog message into buffer
 *
 * @param payload msg payload
 * @param msg_id msg id
 * @param len msg length
 * 
 * @return FMT Error
 */
fmt_err_t mlog_push_msg(const uint8_t* payload, uint8_t msg_id, uint16_t len)
{
    /*                           MLOG MSG Format                                 */
    /*   ======================================================================= */
    /*   | MLOG_BEGIN_MSG1 | MLOG_BEGIN_MSG2 | MSG_ID | PAYLOAD | MLOG_END_MSG | */
    /*   ======================================================================= */
    int32_t bus_index;

    /* check log status */
    if (mlog_handle.log_status != MLOG_STATUS_LOGGING) {
        return FMT_EEMPTY;
    }

    /* check if buffer has enough space to store msg */
    if (buffer_is_full(len + 4)) {
        /* do not let it print too fast */
        PERIOD_EXECUTE(mlog_buff_full, 1000, ulog_w(TAG, "buffer is full!"););

        bus_index = get_bus_index(msg_id);
        mlog_handle.monitor[bus_index].lost_msg += 1;

        return FMT_EFULL;
    }

    rt_mutex_take(&mlog_handle.lock, RT_WAITING_FOREVER);

    /* write msg begin flag */
    __buffer_putc(MLOG_BEGIN_MSG1);
    __buffer_putc(MLOG_BEGIN_MSG2);
    /* write msg id */
    __buffer_putc(msg_id);
    /* write payload */
    __buffer_write(payload, len);
    /* write msg end flag */
    __buffer_putc(MLOG_END_MSG);

    rt_mutex_release(&mlog_handle.lock);

    bus_index = get_bus_index(msg_id);
    if (bus_index >= 0) {
        mlog_handle.monitor[bus_index].total_msg += 1;
    }

    return FMT_EOK;
}

/**
 * Call this function to start the binary log
 *
 * @param file_name mlog_handle file name with full path
 * @return FMT Error
 */
fmt_err_t mlog_start(char* file_name)
{
    if (mlog_handle.log_status != MLOG_STATUS_IDLE) {
        ulog_w(TAG, "%s is logging, stop it first", mlog_handle.file_name);
        return FMT_EBUSY;
    }

    /*********************** create log file ***********************/
    mlog_handle.fid = open(file_name, O_CREAT | O_WRONLY);

    if (mlog_handle.fid < 0) {
        ulog_e(TAG, "%s open fail", file_name);
        return FMT_ERROR;
    }
    /* set log file open flag */
    mlog_handle.is_open = 1;
    /* get current time stamp */
    mlog_handle.header.timestamp = systime_now_ms();

    /*********************** init log buffer ***********************/
    mlog_handle.buffer.head = mlog_handle.buffer.tail = 0;
    mlog_handle.buffer.index = 0;

    /*********************** write log header ***********************/
    mlog_handle.log_status = MLOG_STATUS_WRITE_HEAD;

    /* write log info */
    WRITE_PAYLOAD(&mlog_handle.header.version, sizeof(mlog_handle.header.version));
    WRITE_PAYLOAD(&mlog_handle.header.timestamp, sizeof(mlog_handle.header.timestamp));
    WRITE_PAYLOAD(&mlog_handle.header.max_name_len, sizeof(mlog_handle.header.max_name_len));
    WRITE_PAYLOAD(&mlog_handle.header.max_desc_len, sizeof(mlog_handle.header.max_desc_len));
    WRITE_PAYLOAD(&mlog_handle.header.max_model_info_len, sizeof(mlog_handle.header.max_model_info_len));
    WRITE_PAYLOAD(mlog_handle.header.description, MLOG_DESCRIPTION_SIZE);
    /* clear the description after it has been written */
    memset(mlog_handle.header.description, 0, MLOG_DESCRIPTION_SIZE);

    /* write model information */
#ifdef FMT_USING_SIH
    sprintf(mlog_handle.header.model_info, "%s\n%s\n%s\n%s", ins_model_info.info, fms_model_info.info,
        control_model_info.info, plant_model_info.info);
#else
    sprintf(mlog_handle.header.model_info, "%s\n%s\n%s", ins_model_info.info, fms_model_info.info,
        control_model_info.info);
#endif
    WRITE_PAYLOAD(mlog_handle.header.model_info, MLOG_MODEL_INFO_SIZE);

    /* write bus information */
    WRITE_PAYLOAD(&mlog_handle.header.num_bus, sizeof(mlog_handle.header.num_bus));
    for (int n = 0; n < mlog_handle.header.num_bus; n++) {
        /* write bus list */
        WRITE_PAYLOAD(mlog_handle.header.bus_list[n].name, MLOG_MAX_NAME_LEN);
        WRITE_PAYLOAD(&mlog_handle.header.bus_list[n].msg_id, sizeof(mlog_handle.header.bus_list[n].msg_id));
        WRITE_PAYLOAD(&mlog_handle.header.bus_list[n].num_elem, sizeof(mlog_handle.header.bus_list[n].num_elem));
        /* write bus element */
        for (int k = 0; k < mlog_handle.header.bus_list[n].num_elem; k++) {
            WRITE_PAYLOAD(mlog_handle.header.bus_list[n].elem_list[k].name, MLOG_MAX_NAME_LEN);
            WRITE_PAYLOAD(&mlog_handle.header.bus_list[n].elem_list[k].type, sizeof(mlog_handle.header.bus_list[n].elem_list[k].type));
            WRITE_PAYLOAD(&mlog_handle.header.bus_list[n].elem_list[k].number, sizeof(mlog_handle.header.bus_list[n].elem_list[k].number));
        }
    }

    /*********************** write parameter information ***********************/
    char name_buffer[MLOG_MAX_NAME_LEN + 1];

    WRITE_PAYLOAD(&mlog_handle.header.num_param_group, sizeof(mlog_handle.header.num_param_group));
    for (int n = 0; n < mlog_handle.header.num_param_group; n++) {
        memset(name_buffer, 0, MLOG_MAX_NAME_LEN);
        strncpy(name_buffer, mlog_handle.header.param_group_list[n].name, MLOG_MAX_NAME_LEN);

        WRITE_PAYLOAD(name_buffer, MLOG_MAX_NAME_LEN);
        WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].param_num, sizeof(mlog_handle.header.param_group_list[n].param_num));

        for (int k = 0; k < mlog_handle.header.param_group_list[n].param_num; k++) {
            memset(name_buffer, 0, MLOG_MAX_NAME_LEN);
            strncpy(name_buffer, mlog_handle.header.param_group_list[n].content[k].name, MLOG_MAX_NAME_LEN);

            WRITE_PAYLOAD(name_buffer, MLOG_MAX_NAME_LEN);
            WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].type, sizeof(mlog_handle.header.param_group_list[n].content[k].type));

            int type = mlog_handle.header.param_group_list[n].content[k].type;

            if (type == PARAM_TYPE_INT8) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.i8, sizeof(int8_t));
            } else if (type == PARAM_TYPE_UINT8) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.u8, sizeof(uint8_t));
            } else if (type == PARAM_TYPE_INT16) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.i16, sizeof(int16_t));
            } else if (type == PARAM_TYPE_UINT16) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.u16, sizeof(uint16_t));
            } else if (type == PARAM_TYPE_INT32) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.i32, sizeof(int32_t));
            } else if (type == PARAM_TYPE_UINT32) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.u32, sizeof(uint32_t));
            } else if (type == PARAM_TYPE_FLOAT) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.f, sizeof(float));
            } else if (type == PARAM_TYPE_DOUBLE) {
                WRITE_PAYLOAD(&mlog_handle.header.param_group_list[n].content[k].val.lf, sizeof(double));
            } else {
                ulog_w(TAG, "unknown parameter type:%d", type);
            }
        }
    }

    /*********************** set log status ***********************/
    strncpy(mlog_handle.file_name, file_name, sizeof(mlog_handle.file_name) - 1);

    for (int i = 0; i < sizeof(_mlog_bus) / sizeof(mlog_bus_t); i++) {
        mlog_handle.monitor[i].total_msg = 0;
        mlog_handle.monitor[i].lost_msg = 0;
    }

    /* start logging, set flag */
    mlog_handle.log_status = MLOG_STATUS_LOGGING;

    /* invoke callback function */
    __invoke_callback_func(MLOG_CB_START);

    ulog_i(TAG, "start logging:%s", file_name);

    return FMT_EOK;
}

/**
 * Call this function to stop the binary log
 *
 */
void mlog_stop(void)
{
    /* here we just set log status to stopping, it actually stops
       when the mlog_async_output() is called later */
    if (mlog_handle.log_status == MLOG_STATUS_LOGGING) {
        mlog_handle.log_status = MLOG_STATUS_STOPPING;
    }
}

/**
 * Asynchronous binary logs to storage device
 *
 * @note you must call this function periodically
 */
void mlog_async_output(void)
{
    uint32_t head_p, tail_p;
    uint8_t need_sync = 0;

    if (!mlog_handle.is_open) {
        /* no log file is opened */
        return;
    }

    OS_ENTER_CRITICAL;
    head_p = mlog_handle.buffer.head;
    tail_p = mlog_handle.buffer.tail;
    OS_EXIT_CRITICAL;

    /* check if we need synchronous the output */
    need_sync = (head_p != tail_p);
    /* write log buffer sector into storage device */
    while (head_p != tail_p) {
        /* check how many sectors that we can write at once */
        uint16_t sector_to_write = get_max_write_sector(head_p, tail_p);
        /* write data to the storage device */
        write(mlog_handle.fid, &mlog_handle.buffer.data[tail_p * MLOG_SECTOR_SIZE], sector_to_write * MLOG_SECTOR_SIZE);
        /* update buffer pointer */
        tail_p = (tail_p + sector_to_write) % mlog_handle.buffer.num_sector;
        OS_ENTER_CRITICAL;
        mlog_handle.buffer.tail = tail_p;
        OS_EXIT_CRITICAL;
    }

    /* synchronous the disk to make sure data have been written */
    if (need_sync) {
        fsync(mlog_handle.fid);
    }

    /* if logging is off, clean up the buffer. */
    if (mlog_handle.log_status == MLOG_STATUS_STOPPING) {
        /* dump rest data in buffer */
        if (mlog_handle.buffer.index) {
            write(mlog_handle.fid, &mlog_handle.buffer.data[tail_p * MLOG_SECTOR_SIZE], mlog_handle.buffer.index);
            fsync(mlog_handle.fid);
        }
        /* close the file if needed */
        if (mlog_handle.is_open) {
            close(mlog_handle.fid);
            mlog_handle.fid = -1;
            mlog_handle.is_open = 0;
        }

        /* set log status to idle */
        mlog_handle.log_status = MLOG_STATUS_IDLE;

        /* invoke callback function */
        __invoke_callback_func(MLOG_CB_STOP);

        ulog_i(TAG, "stop logging:%s", mlog_handle.file_name);
        for (int i = 0; i < sizeof(_mlog_bus) / sizeof(mlog_bus_t); i++) {
            ulog_i(TAG, "%-20s id:%-3d record:%-8d lost:%-5d", _mlog_bus[i].name, _mlog_bus[i].msg_id,
                mlog_handle.monitor[i].total_msg, mlog_handle.monitor[i].lost_msg);
        }
    }
}

/**
 * Initialize mat log module.
 * 
 * @return FMT Errors.
 */
fmt_err_t mlog_init(void)
{
    int i;

    /* initialize mlog_handle status */
    mlog_handle.is_open = 0;
    mlog_handle.log_status = MLOG_STATUS_IDLE;
    /* initialize log header */
    mlog_handle.header.version = MLOG_VERSION;
    mlog_handle.header.timestamp = 0;
    mlog_handle.header.max_name_len = MLOG_MAX_NAME_LEN;
    mlog_handle.header.max_desc_len = MLOG_DESCRIPTION_SIZE;
    mlog_handle.header.max_model_info_len = MLOG_MODEL_INFO_SIZE;
    mlog_handle.header.num_bus = sizeof(_mlog_bus) / sizeof(mlog_bus_t);
    mlog_handle.header.bus_list = _mlog_bus;
    mlog_handle.header.num_param_group = sizeof(param_list) / sizeof(param_group_t);
    mlog_handle.header.param_group_list = (param_group_t*)&param_list;
    memset(mlog_handle.header.description, 0, MLOG_DESCRIPTION_SIZE);

    /* initialize mlog_handle buffer */
    mlog_handle.buffer.data = (uint8_t*)rt_malloc(MLOG_BUFFER_SIZE);
    if (mlog_handle.buffer.data == NULL) {
        console_printf("mlog_handle buffer malloc fail!\n");
        return FMT_ENOMEM;
    } else {
        /* initialize buffer */
        mlog_handle.buffer.num_sector = MLOG_BUFFER_SIZE / MLOG_SECTOR_SIZE;
        mlog_handle.buffer.head = 0;
        mlog_handle.buffer.tail = 0;
        mlog_handle.buffer.index = 0;
    }

    /* create write lock */
    if (rt_mutex_init(&mlog_handle.lock, "mlog_lock", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("fail to create mlog lock!\n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}