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

#include "board_device.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)

static rt_device_t spi_dev;

static rt_err_t low_level_init(void)
{
    uint8_t dev_id;

    /* init spi bus */
    RT_TRY(rt_device_open(spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(spi_read_reg8(spi_dev, 0x75, &dev_id));

    printf("icm42688 chip id:%x\n", dev_id);

    return RT_EOK;
}

rt_err_t drv_icm42688_init(const char* spi_dev_name, const char* gyro_dev_name, const char* accel_dev_name)
{
    /* Initialize gyroscope */

    spi_dev = rt_device_find(spi_dev_name);
    RT_ASSERT(spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 4000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }
    /* device low-level init */
    RT_TRY(low_level_init());

    // /* register accel hal device */
    // RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}
