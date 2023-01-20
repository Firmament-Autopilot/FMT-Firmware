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

#include "hal/spi/spi.h"

static void test_unit_1(void)
{
    rt_device_t spi_device;
    uint8_t chip_id;

    /* Test SPI1 CS1 */
    spi_device = rt_device_find("spi1_dev3");
    uassert_not_null(spi_device);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        uassert_int_equal(rt_spi_configure(spi_device_t, &cfg), RT_EOK);
    }

    uassert_int_equal(rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR), RT_EOK);

    uassert_int_equal(spi_read_reg8(spi_device, 0x75, &chip_id), RT_EOK);

    uassert_int_equal(chip_id, 0x68);

    rt_device_close(spi_device);
}

static void test_unit_2(void)
{
    rt_device_t spi_device;
    uint8_t chip_id;

    /* Test SPI1 CS2 */
    spi_device = rt_device_find("spi1_dev4");
    uassert_not_null(spi_device);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        uassert_int_equal(rt_spi_configure(spi_device_t, &cfg), RT_EOK);
    }

    uassert_int_equal(rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR), RT_EOK);

    uassert_int_equal(spi_read_reg8(spi_device, 0x75, &chip_id), RT_EOK);

    uassert_int_equal(chip_id, 0x68);

    rt_device_close(spi_device);
}

static rt_err_t testcase_init(void)
{
    return RT_EOK;
}

static rt_err_t testcase_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_unit_1);
    UTEST_UNIT_RUN(test_unit_2);
}
UTEST_TC_EXPORT(testcase, "utest.interface.spi", testcase_init, testcase_cleanup, 50000);