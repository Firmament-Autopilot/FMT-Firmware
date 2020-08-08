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

#ifndef __PILOT_CMD_H__
#define __PILOT_CMD_H__

#include <firmament.h>

// Pilot Command
#define FMS_CMD_KILL_MOTOR   0x10
#define FMS_CMD_RESUME_MOTOR 0x11

fmt_err pilot_cmd_init(void);
uint8_t pilot_cmd_collect(void);

#endif