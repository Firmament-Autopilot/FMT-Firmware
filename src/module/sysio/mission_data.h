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

#ifndef MISSION_DATA_H__
#define MISSION_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MISSION_FILE "/sys/mission.txt"

struct mission_item {
    uint16_t seq;         /*<  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).*/
    uint16_t command;     /*<  The scheduled action for the waypoint.*/
    uint8_t frame;        /*<  The coordinate system of the waypoint.*/
    uint8_t current;      /*<  false:0, true:1*/
    uint8_t autocontinue; /*<  Autocontinue to next waypoint*/
    uint8_t mission_type; /*<  Mission type.*/
    float param1;         /*<  PARAM1, see MAV_CMD enum*/
    float param2;         /*<  PARAM2, see MAV_CMD enum*/
    float param3;         /*<  PARAM3, see MAV_CMD enum*/
    float param4;         /*<  PARAM4, see MAV_CMD enum*/
    int32_t x;            /*<  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7*/
    int32_t y;            /*<  PARAM6 / y position: local: y position in meters * 1e4, global: longitude in degrees *10^7*/
    float z;              /*<  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.*/
};

fmt_err_t mission_data_init(void);
fmt_err_t mission_reset(void);
fmt_err_t mission_data_collect(void);
fmt_err_t load_mission_data(const char* path);
uint16_t get_mission_count(void);
struct mission_item* get_mission_item(uint16_t seq);
fmt_err_t clear_mission_data(const char* path);
void dump_mission_data(void);

#ifdef __cplusplus
}
#endif

#endif
