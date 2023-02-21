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

#ifndef SYSTICK_H__
#define SYSTICK_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SYSTICK_RD_TIME_US 0

#define SYSTICK_CMD_SET_FREQUENCY 0x20

/* default config for systick device */
#define SYSTICK_CONFIG_DEFAULT \
    {                          \
        RT_TICK_PER_SECOND,    \
    }

struct systick_configure {
    rt_uint16_t tick_freq;
};

struct systick_device {
    struct rt_device parent;
    const struct systick_ops* ops;
    struct systick_configure config;
    rt_uint32_t ticks_per_us;
    rt_uint32_t ticks_per_isr;
    void (*systick_isr_cb)(void);
};
typedef struct systick_device* systick_dev_t;

struct systick_ops {
    /**
     * @brief systick configuration
     * @param dev systick device
     * @param config systick configuration
     */
    rt_err_t (*systick_configure)(systick_dev_t dev, struct systick_configure* config);
    /**
     * @brief read systick value in us
     * @param dev systick device
     */
    rt_uint32_t (*systick_read)(systick_dev_t dev);
};

rt_err_t hal_systick_register(systick_dev_t systick, const char* name, rt_uint32_t flag, void* data);
void hal_systick_isr(systick_dev_t systick);

#ifdef __cplusplus
}
#endif

#endif
