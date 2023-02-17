/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#ifndef RC_H__
#define RC_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SBUS_RC_CHANNEL_NUM 16
#define MAX_PPM_RC_CHANNEL_NUM  8

#define RC_PROTOCOL_AUTO 0
#define RC_PROTOCOL_SBUS 1
#define RC_PROTOCOL_PPM  2

#define RC_MASK_1  0x0001
#define RC_MASK_2  0x0002
#define RC_MASK_3  0x0004
#define RC_MASK_4  0x0008
#define RC_MASK_5  0x0010
#define RC_MASK_6  0x0020
#define RC_MASK_7  0x0040
#define RC_MASK_8  0x0080
#define RC_MASK_9  0x0100
#define RC_MASK_10 0x0200
#define RC_MASK_11 0x0400
#define RC_MASK_12 0x0800
#define RC_MASK_13 0x1000
#define RC_MASK_14 0x2000
#define RC_MASK_15 0x4000
#define RC_MASK_16 0x8000

#define RC_MASK_1_2  0x0003
#define RC_MASK_1_4  0x000F
#define RC_MASK_1_6  0x003F
#define RC_MASK_1_8  0x00FF
#define RC_MASK_1_10 0x03FF
#define RC_MASK_1_12 0x0FFF
#define RC_MASK_1_14 0x3FFF
#define RC_MASK_ALL  0xFFFF

#define RC_CMD_CHECK_UPDATE 0x20

struct rc_configure {
    rt_uint16_t protocol;    /* rc protocol: auto/sbus/ppm */
    rt_uint16_t channel_num; /* rc channel number */
    float sample_time;       /*rc sample time*/
    rt_int16_t rc_min_value; /*rc channel min value*/
    rt_int16_t rc_max_value; /*rc channel max value*/
};

struct rc_device {
    struct rt_device parent;
    const struct rc_ops* ops;
    struct rc_configure config;
};
typedef struct rc_device* rc_dev_t;

struct rc_ops {
    /**
     * @brief rc configuration function (optional)
     * @param dev rc device
     * @param cfg rc configuration
    */
    rt_err_t (*rc_config)(rc_dev_t dev, struct rc_configure* cfg);
    /**
     * @brief rc control function (optional)
     * @param dev rc device
     * @param cmd operation command
     * @param arg command argument (optional)
    */
    rt_err_t (*rc_control)(rc_dev_t dev, int cmd, void* arg);
    /**
     * @brief rc read function
     * @param dev rc device
     * @param chan_mask selected channel to read with bit mask
     * @param chan_val selected channel read buffer
     */
    rt_uint16_t (*rc_read)(rc_dev_t dev, rt_uint16_t chan_mask, rt_uint16_t* chan_val);
};

rt_err_t hal_rc_register(rc_dev_t rc, const char* name, rt_uint32_t flag, void* data);
rt_err_t hal_rc_rx_ind(rc_dev_t rc, rt_size_t size);

#ifdef __cplusplus
}
#endif

#endif
