/******************************************************************************
 * Copyright 2016-2021 The Firmament Authors. All Rights Reserved.
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

#ifndef ACTUATOR_H__
#define ACTUATOR_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ACT_CMD_CHANNEL_ENABLE  0x20
#define ACT_CMD_CHANNEL_DISABLE 0x21
#define ACT_CMD_SET_PROTOCOL    0x22

enum {
    ACT_PROTOCOL_PWM = 1,
    ACT_PROTOCOL_DSHOT = 2
};

struct pwm_drv_configure {
    rt_uint16_t pwm_freq; /* pwm frequency in hz */
};

struct dshot_drv_configure {
    rt_uint16_t speed;   /* 600, 300, 150 */
    rt_bool_t telem_req; /* telemetry request */
};

struct actuator_configure {
    rt_uint8_t protocol;
    rt_uint16_t chan_num;
    struct pwm_drv_configure pwm_config;
    struct dshot_drv_configure dshot_config;
};

struct actuator_device {
    struct rt_device parent;
    const struct actuator_ops* ops;
    struct actuator_configure config;
    rt_uint16_t chan_mask;
    rt_uint16_t range[2]; /* [min, max] value */
};
typedef struct actuator_device* actuator_dev_t;

struct actuator_ops {
    rt_err_t (*dev_config)(actuator_dev_t dev, const struct actuator_configure* cfg);
    rt_err_t (*dev_control)(actuator_dev_t dev, int cmd, void* arg);
    rt_size_t (*dev_read)(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
    rt_size_t (*dev_write)(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);
};

rt_err_t hal_actuator_register(actuator_dev_t dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif /* ACTUATOR_H__ */