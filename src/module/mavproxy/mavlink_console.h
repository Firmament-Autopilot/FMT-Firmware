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

#ifndef MAVLINK_CONSOLE_H__
#define MAVLINK_CONSOLE_H__

#include <firmament.h>
#include <mavlink.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t mavlink_console_init(void);
void mavlink_console_process_rx_msg(const mavlink_serial_control_t* serial_control);
void mavlink_console_handle_timeout(void);

#ifdef __cplusplus
}
#endif

#endif
