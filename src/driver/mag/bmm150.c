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

#include "driver/mag/bmm150.h"
#include "hal/mag/mag.h"
#include "hal/spi/spi.h"

static rt_device_t mag_spi_dev;

static rt_err_t magnetometer_init(void)
{
    uint8_t mag_id;

    /* init spi bus */
    RT_TRY(rt_device_open(mag_spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(spi_write_reg8(mag_spi_dev, 0x4b, 0x01));

    RT_TRY(spi_read_reg8(mag_spi_dev, 0x40, &mag_id));

    printf("mag chip id:%x\n", mag_id);

    return RT_EOK;
}

rt_err_t drv_bmm150_init(const char* spi_device_name, const char* mag_device_name)
{
    rt_err_t res = RT_EOK;

    mag_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(mag_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)mag_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    magnetometer_init();

    return res;
}
