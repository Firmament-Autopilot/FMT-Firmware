/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "hal/airspeed/airspeed.h"
#include "hal/i2c/i2c.h"
#include "module/sensor/sensor_hub.h"

static rt_device_t i2c_dev;

rt_err_t drv_xgzp6899d_init(const char* i2c_device_name, const char* device_name)
{
    
    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_TRY(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    uint8_t reg;
    i2c_read_reg(i2c_dev, 0x0A, &reg);
    printf("reg:%d\n", reg);

    return RT_EOK;
}