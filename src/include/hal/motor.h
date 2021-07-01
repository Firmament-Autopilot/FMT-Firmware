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

#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <firmament.h>

#define MAX_MOTOR_CHANNEL_NUM 16

#define MOTOR_MASK_1  0x0001
#define MOTOR_MASK_2  0x0002
#define MOTOR_MASK_3  0x0004
#define MOTOR_MASK_4  0x0008
#define MOTOR_MASK_5  0x0010
#define MOTOR_MASK_6  0x0020
#define MOTOR_MASK_7  0x0040
#define MOTOR_MASK_8  0x0080
#define MOTOR_MASK_9  0x0100
#define MOTOR_MASK_10 0x0200
#define MOTOR_MASK_11 0x0400
#define MOTOR_MASK_12 0x0800
#define MOTOR_MASK_13 0x1000
#define MOTOR_MASK_14 0x2000
#define MOTOR_MASK_15 0x4000
#define MOTOR_MASK_16 0x8000

#define MOTOR_MASK_1_2  0x0003
#define MOTOR_MASK_1_4  0x000F
#define MOTOR_MASK_1_6  0x003F
#define MOTOR_MASK_1_8  0x00FF
#define MOTOR_MASK_1_10 0x03FF
#define MOTOR_MASK_1_12 0x0FFF
#define MOTOR_MASK_1_14 0x3FFF
#define MOTOR_MASK_ALL  0xFFFF

#define MOTOR_CMD_GET_CHANNEL_NUM 0x20
#define MOTOR_CMD_CHANNEL_ENABLE  0x21
#define MOTOR_CMD_CHANNEL_DISABLE 0x22
#define MOTOR_CMD_SET_FREQUENCY   0x23
#define MOTOR_CMD_SET_DIRECTION   0x24

struct motor_configure {
    rt_uint16_t pwm_frequency;
    rt_uint16_t channel_num;
    rt_uint16_t motor_min_value;
    rt_uint16_t motor_max_value;
};

struct motor_device {
    struct rt_device parent;
    const struct motor_ops* ops;
    struct motor_configure config;
    rt_uint8_t channel_num;
};
typedef struct motor_device* motor_dev_t;

struct motor_ops {
    rt_err_t (*motor_configure)(motor_dev_t motor, struct motor_configure* cfg);
    rt_err_t (*motor_control)(motor_dev_t motor, int cmd, void* arg);
    rt_size_t (*motor_read)(motor_dev_t motor, rt_uint16_t chan_mask, rt_uint16_t* chan_val, rt_size_t size);
    rt_size_t (*motor_write)(motor_dev_t motor, rt_uint16_t chan_mask, const rt_uint16_t* chan_val, rt_size_t size);
};

rt_err_t hal_motor_register(motor_dev_t motor, const char* name, rt_uint32_t flag, void* data);

#endif
