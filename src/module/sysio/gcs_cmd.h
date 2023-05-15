/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#ifndef GCS_CMD_H__
#define GCS_CMD_H__

#include <FMS.h>

#ifdef __cplusplus
extern "C" {
#endif

fmt_err_t gcs_cmd_init(void);
GCS_Cmd_Bus gcs_cmd_get(void);
fmt_err_t gcs_cmd_collect(void);
void gcs_cmd_heartbeat(void);
fmt_err_t gcs_set_cmd(FMS_Cmd cmd, float param[5]);
fmt_err_t gcs_set_mode(PilotMode mode);

#ifdef __cplusplus
}
#endif

#endif
