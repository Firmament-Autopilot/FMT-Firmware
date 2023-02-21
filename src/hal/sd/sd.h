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

#ifndef SD_H__
#define SD_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sd_device {
    struct rt_device parent;
    const struct sd_ops* ops;
    struct rt_event event;
};
typedef struct sd_device* sd_dev_t;

/* sd driver opeations */
struct sd_ops {
    /**
     * @brief initialize sd card
     * @param dev sd device
     */
    rt_err_t (*sd_init)(sd_dev_t dev);
    /**
     * @brief write data to sd
     * @param dev sd device
     * @param buffer write buffer
     * @param sector sector to write
     * @param count sector count to write
     */
    rt_err_t (*sd_write)(sd_dev_t dev, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count);
    /**
     * @brief read data from sd
     * @param dev sd device
     * @param buffer read buffer
     * @param sector sector to read
     * @param count sector count to read
     */
    rt_err_t (*sd_read)(sd_dev_t dev, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count);
    /**
     * @brief sd control function (optional)
     * @param dev sd device
     * @param cmd operation command
     * @param arg command argument (optional)
    */
    rt_err_t (*sd_control)(sd_dev_t dev, int cmd, void* arg);
};

rt_err_t hal_sd_register(sd_dev_t sd, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
