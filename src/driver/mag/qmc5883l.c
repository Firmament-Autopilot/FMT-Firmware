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

#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "hal/mag/mag.h"

#define DRV_DBG(...) printf(__VA_ARGS__)

static rt_device_t i2c_dev;

static rt_err_t probe(void)
{
    uint8_t chip_id = 0;

    RT_TRY(i2c_read_reg(i2c_dev, 0x0D, &chip_id));

    printf("qmc5883l id:0x%x\n", chip_id);

    // if (device_id != IST8310_DEVICE_ID) {
    //     DRV_DBG("ist8310 unmatched id: 0x%x\n", device_id);
    //     return RT_ERROR;
    // }

    return RT_EOK;
}

rt_err_t drv_qmc5883l_init(const char* i2c_device_name, const char* mag_device_name)
{
    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    probe();

    return RT_EOK;
}
