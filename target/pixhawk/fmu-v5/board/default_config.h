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

// clang-format off
static char* default_conf = STRING(
target = "Pixhawk4 FMUv5"\n
[console]\n
	[[console.devices]]\n
	type = "serial"\n
	name = "serial0"\n
	baudrate = 57600\n
	auto-switch = true\n
	[[console.devices]]\n
	type = "mavlink"\n
	name = "mav_console"\n
	auto-switch = true\n
[mavproxy]\n
	[[mavproxy.devices]]\n
	chan = 0\n
	type = "serial"\n
	name = "serial1"\n
	baudrate = 57600\n
    [[mavproxy.devices]]\n
	chan = 0\n
	type = "usb"\n
	name = "usbd0"\n
    auto-switch = true
);
// clang-format on
