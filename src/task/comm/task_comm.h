/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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
#ifndef TASK_COMM_H__
#define TASK_COMM_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

bool mavlink_msg_heartbeat_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_extended_sys_state_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_sys_status_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_system_time_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_attitude_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_attitude_quaternion_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_local_position_ned_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_global_position_int_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_scaled_imu_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_vfr_hud_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_altitude_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_gps_raw_int_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_rc_channels_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_highres_imu_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_distance_sensor_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_gps_global_origin_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_home_position_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_attitude_target_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_position_target_local_pack_func(mavlink_message_t* msg_t);
bool mavlink_msg_hil_state_pack_func(mavlink_message_t* msg_t);

fmt_err_t mavlink_command_acknowledge(uint8_t chan, uint16_t command, uint8_t result);

#ifdef __cplusplus
}
#endif

#endif