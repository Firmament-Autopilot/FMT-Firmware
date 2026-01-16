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

static rt_device_t i2c_dev;

static rt_err_t probe(void)
{
    uint8_t chip_id = 0;

    i2c_read_reg(i2c_dev, 0x00, &chip_id);

    printf("chip id:%x\n", chip_id);

    // if (chip_id != CHIP_ID) {
    //     DRV_DBG("qmc5883l id unmatched: 0x%x\n", chip_id);
    //     return RT_ERROR;
    // }

    return RT_EOK;
}

// static void test(void)
// {
//     rt_size_t ret;
//     uint8_t reg;
//     struct rt_i2c_msg msgs[1];
//     struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

//     msgs[0].flags = RT_I2C_RD | i2c_device->flags;
//     msgs[0].buf = &reg;
//     msgs[0].len = 1;

//     ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 1);

//     printf("status:%x\n", reg);
// }

rt_err_t drv_qmc5883p_init(const char* i2c_device_name, const char* mag_device_name, uint32_t dev_flags)
{
    // static struct mag_device mag_dev = {
    //     .ops = &__mag_ops,
    //     .config = QMC5883L_CONFIG_DEFAULT,
    //     .bus_type = MAG_I2C_BUS_TYPE
    // };

    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    probe();

    // test();

    return RT_EOK;
}
