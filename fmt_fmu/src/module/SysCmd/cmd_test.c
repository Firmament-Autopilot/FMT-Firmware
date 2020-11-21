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

#include "hal/motor.h"
#include "hal/rc.h"
#include "hal/serial.h"
#include "module/console/console.h"
#include "module/sensor/sensor_manager.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/toml/toml.h"
#include "task/task_fmtio.h"
#include "hal/systick.h"

rt_device_t _systick_dev;

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    RCC_ClocksTypeDef rcc_clocks;
    systick_dev_t systick_device = (systick_dev_t)_systick_dev;
    rt_uint32_t cnts;

    RCC_GetClocksFreq(&rcc_clocks);

    cnts = (rt_uint32_t)rcc_clocks.HCLK_Frequency / 1000;
	cnts = cnts / 8;

    console_printf("ticks_per_isr:%u ticks_per_us:%u\n", systick_device->ticks_per_isr, systick_device->ticks_per_us);
    console_printf("load:%u tick_freq:%u cnt:%u HCLK_Frequency:%u\n", SysTick->LOAD, systick_device->config.tick_freq, cnts, rcc_clocks.HCLK_Frequency);

    return 0;
}

int cmd_test(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);