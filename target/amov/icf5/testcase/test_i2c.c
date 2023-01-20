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
#include <firmament.h>
#include <utest.h>

#include "hal/i2c/i2c.h"

static struct rt_i2c_device i2c0_dev1 = {
    .slave_addr = 0x30, /* XXX 7 bit address */
    .flags = 0
};

static void test_unit_1(void)
{
    rt_device_t i2c_dev;
    uint8_t chip_id;

    i2c_dev = rt_device_find("i2c0_dev1");
    uassert_not_null(i2c_dev);

    uassert_int_equal(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR), RT_EOK);

    uassert_int_equal(i2c_read_reg(i2c_dev, 0x00, &chip_id), RT_EOK);

    uassert_int_equal(chip_id, 0x0A);

    uassert_int_equal(rt_device_close(i2c_dev), RT_EOK);
}

static rt_err_t testcase_init(void)
{
    return rt_i2c_bus_attach_device(&i2c0_dev1, "i2c0_dev1", "i2c0", RT_NULL);
}

static rt_err_t testcase_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_unit_1);
}
UTEST_TC_EXPORT(testcase, "utest.interface.i2c", testcase_init, testcase_cleanup, 50000);