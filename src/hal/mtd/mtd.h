/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#ifndef MTD_H__
#define MTD_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

struct mtd_device {
    struct rt_device parent;
    const struct mtd_ops* ops;
    struct rt_device_blk_geometry blk_geometry;
};
typedef struct mtd_device* mtd_dev_t;

/* mtd (media technology device) driver opeations */
struct mtd_ops {
    /**
     * @brief mtd init function
     * @param dev mtd device
     */
    rt_err_t (*init)(mtd_dev_t dev);
    /**
     * @brief mtd read function
     * @param dev mtd device
     * @param buffer read buffer
     * @param sector sector to read
     * @param count sector count to read
     */
    rt_err_t (*read)(mtd_dev_t dev, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count);
    /**
     * @brief mtd write function
     * @param dev mtd device
     * @param buffer write buffer
     * @param sector sector to write
     * @param count sector count to write
     */
    rt_err_t (*write)(mtd_dev_t dev, const rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count);
    /**
     * @brief mtd erase function (optional)
     * @param dev mtd device
     * @param sector sector to erase
     * @param count sector count to erase
     */
    rt_err_t (*erase)(mtd_dev_t dev, rt_uint32_t sector, rt_uint32_t count);
    /**
     * @brief mtd control function (optional)
     * @param dev mtd device
     * @param cmd operation command
     * @param arg command argument (optional)
    */
    rt_err_t (*control)(mtd_dev_t dev, int cmd, void* arg);
};

rt_err_t hal_mtd_register(mtd_dev_t mtd, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
