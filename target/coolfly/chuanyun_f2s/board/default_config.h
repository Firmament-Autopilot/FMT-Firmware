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

/* This is the default toml config for the target, which is loaded when there is
 * no sysconfig.toml finded. Please do not format this file. */
static char* default_conf = STRING(
target = "CHUANYUN_F2S"\n
[console]\n
	[[console.devices]]\n
	type = "serial"\n
	name = "serial0"\n
	baudrate = 460800\n
	auto-switch = true\n
	[[console.devices]]\n
	type = "mavlink"\n
	name = "mav_console"\n
	auto-switch = true\n
[pilot-cmd]\n
    stick-channel = [4,3,2,1]\n
	[pilot-cmd.device]\n
	type = "rc"\n
	name = "rc"\n
	protocol = "sbus"\n
	channel-num = 16\n
	sample-time = 0.05\n
	range = [1000,2000]\n
	[[pilot-cmd.mode]]\n
	mode = 5\n
	channel = 6\n
	range = [1000,1200]\n
	[[pilot-cmd.mode]]\n
	mode = 4\n
	channel = 6\n
	range = [1400,1600]\n
	[[pilot-cmd.mode]]\n
	mode = 3\n
	channel = 6\n
	range = [1800,2000]\n
	[[pilot-cmd.command]]\n
	type = 1\n
	cmd = 1002\n
	channel = 12\n
	range = [1800,2000]\n
	[[pilot-cmd.command]]\n
	type = 1\n
	cmd = 1003\n
	channel = 8\n
	range = [1800,2000]\n	
	[[pilot-cmd.command]]\n
	type = 1\n
	cmd = 1005\n
	channel = 11\n
	range = [1800,2000]\n
[mavproxy]\n
	[[mavproxy.devices]]\n
	chan = 1\n
	type = "serial"\n
	name = "serial7"\n
	baudrate = 460800\n
	[[mavproxy.devices]]\n
	chan = 0\n
	type = "bb_com"\n
	name = "bb_com3"\n
	auto-switch = true\n
[actuator]\n
    [[actuator.devices]]\n
    protocol = "pwm"\n
    name = "main_out"\n
    freq = 400\n
    [[actuator.mappings]]\n
    from = "control_out"\n
    to = "main_out"\n
    chan-map = [[1,2,3,4],[1,2,3,4]]\n
    [[actuator.mappings]]\n
    from = "rc_channels"\n
    to = "main_out"\n
    chan-map = [[5,7,8,9],[5,6,7,8]]\n
);