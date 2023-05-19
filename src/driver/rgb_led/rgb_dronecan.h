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
#ifndef RGB_DRONECAN_H__
#define RGB_DRONECAN_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DRONECAN_CMD_SET_COLOR  0x01
#define DRONECAN_CMD_SET_BRIGHT 0x02

enum {
    DRONECAN_LED_RED = 0,
    DRONECAN_LED_GREEN,
    DRONECAN_LED_BLUE,
    DRONECAN_LED_YELLOW,
    DRONECAN_LED_PURPLE,
    DRONECAN_LED_CYAN,
    DRONECAN_LED_WHITE,
};

rt_err_t drv_rgb_dronecan_init(const char* can_dev_name);

#ifdef __cplusplus
}
#endif

#endif