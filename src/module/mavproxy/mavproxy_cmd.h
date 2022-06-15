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

#ifndef MAVPROXY_CMD_H__
#define MAVPROXY_CMD_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MAVCMD_CALIBRATION_GYR = 0,
    MAVCMD_CALIBRATION_ACC,
    MAVCMD_CALIBRATION_MAG,
    MAVCMD_CALIBRATION_LEVEL,
    MAVCMD_STREAM_SESSION,
    MAVCMD_ITEM_NUM // do not remove it
} MavCmd_ID;

void mavproxy_cmd_exec(void);
void mavproxy_cmd_set(MavCmd_ID cmd, void* data);
void mavproxy_cmd_reset(MavCmd_ID cmd);

#ifdef __cplusplus
}
#endif

#endif
