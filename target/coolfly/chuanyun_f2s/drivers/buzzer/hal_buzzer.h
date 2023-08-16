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

#ifndef HAL_BUZZER_H__
#define HAL_BUZZER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BUZZER_CMD_CHANNEL_ENABLE  0x30
#define BUZZER_CMD_CHANNEL_DISABLE 0x31

struct buzzer_pwm_drv_configure {
    rt_uint16_t pwm_freq; /* pwm frequency in hz */
};

struct buzzer_configure {
    rt_uint16_t                     channel;
    struct buzzer_pwm_drv_configure pwm_config;
};

struct buzzer_device {
    struct rt_device         parent;
    const struct buzzer_ops* ops;
    struct buzzer_configure  config;
    rt_uint16_t              chan_mask;
    rt_uint16_t              range[2]; /* [min, max] value */
};
typedef struct buzzer_device* buzzer_dev_t;

struct buzzer_ops {
    rt_err_t (*dev_config)(buzzer_dev_t dev, const struct buzzer_configure* cfg);
    rt_err_t (*dev_control)(buzzer_dev_t dev, int cmd, void* arg);
    rt_size_t (*dev_read)(buzzer_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
    rt_size_t (*dev_write)(buzzer_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);
};

rt_err_t hal_buzzer_register(buzzer_dev_t dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
