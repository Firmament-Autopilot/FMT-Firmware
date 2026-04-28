/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#ifndef MAVLINK_LOG_H__
#define MAVLINK_LOG_H__

#include <firmament.h>
#include <mavlink.h>

#ifdef __cplusplus
extern "C" {
#endif

void handle_log_request_list(mavlink_message_t* msg, mavlink_system_t this_system, uint8_t chan);
void handle_log_request_data(mavlink_message_t* msg, mavlink_system_t this_system, uint8_t chan);
void handle_log_erase(mavlink_message_t* msg, mavlink_system_t this_system);
void handle_log_request_end(mavlink_message_t* msg, mavlink_system_t this_system);

#ifdef __cplusplus
}
#endif

#endif
