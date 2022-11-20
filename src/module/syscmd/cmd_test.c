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

#include <stdlib.h>
#include <string.h>

#include "hal/rc/rc.h"
#include "hal/serial/serial.h"
#include "hal/systick/systick.h"
#include "module/console/console.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_hub.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/toml/toml.h"
#include "module/workqueue/work_queue.h"
#include "module/workqueue/workqueue_manager.h"

#include "module/fmtio/protocol.h"

#include "module/syscmd/optparse.h"

#include "hal/i2c/i2c.h"
#include "hal/spi/spi.h"

#include <string.h>

// static uint8_t tx_buffer[] = "Test DMA Usart!\r\n";
// static rt_device_t test_dev;

int cmd_test(int argc, char** argv)
{
    // printf("cos:%f sin:%f\n", arm_cos_f32(PI/6), arm_sin_f32(PI/6));

    // test_dev = rt_device_find("spi1_dev1");
    // RT_ASSERT(test_dev != NULL);
    // /* config spi */
    // {
    //     struct rt_spi_configuration cfg;
    //     cfg.data_width = 8;
    //     cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
    //     cfg.max_hz = 7000000;

    //     struct rt_spi_device* spi_device_t = (struct rt_spi_device*)test_dev;
    //     spi_device_t->config.data_width = cfg.data_width;
    //     spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
    //     spi_device_t->config.max_hz = cfg.max_hz;

    //     RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    // }

    // uint8_t id;

    // /* init spi bus */
    // RT_TRY(rt_device_open(test_dev, RT_DEVICE_OFLAG_RDWR));

    // RT_TRY(spi_read_reg8(test_dev, 0x0A, &id));

    // printf("id:%x\n", id);

    // uint8_t id;
    // test_dev = rt_device_find("i2c0_dev0");

    // RT_CHECK(rt_device_open(test_dev, RT_DEVICE_OFLAG_RDWR));

    // RT_CHECK(i2c_read_reg(test_dev, 0x0A, &id));

    // printf("id:%x\n", id);

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);