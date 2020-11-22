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
#include "hal/systick.h"
#include "module/console/console.h"
#include "module/sensor/sensor_manager.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/toml/toml.h"
#include "task/task_fmtio.h"

#define DEFAULT_TOML_SYS_CONFIG "\
target = \"Pixhawk FMUv2\"\n\
[console]\n\
	[[console.devices]]\n\
	type = \"serial\"\n\
	name = \"serial0\"\n\
	baudrate = 57600\n\
	auto-switch = true\n\
	[[console.devices]]\n\
	type = \"mavlink\"\n\
	name = \"mav_console\"\n\
	auto-switch = true"

rt_device_t _systick_dev;

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    console_printf("%s\n", DEFAULT_TOML_SYS_CONFIG);
    toml_table_t* tab = toml_parse_config_string(DEFAULT_TOML_SYS_CONFIG);
    toml_print_table(tab);
    toml_free(tab);

    return 0;
}

int cmd_test(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);