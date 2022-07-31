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

static uint8_t tx_buffer[] = "Test DMA Usart!\r\n";

int cmd_test(int argc, char** argv)
{
    rt_device_t dev = rt_device_find("serial1");

    rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX);

    for (int i = 0; i < 20; i++) {
        rt_device_write(dev, 0, tx_buffer, sizeof(tx_buffer));
    }

    rt_device_close(dev);

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);