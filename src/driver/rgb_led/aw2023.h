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
#ifndef AW2023_H__
#define AW2023_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AW2023_CMD_SET_COLOR       0x01
#define AW2023_CMD_SET_BRIGHT      0x02
#define AW2023_CMD_SET_MANUAL_MODE 0x03
#define AW2023_CMD_SET_PATERN_MODE 0x04

enum {
    AW2023_LED_RED = 0,
    AW2023_LED_GREEN,
    AW2023_LED_BLUE,
    AW2023_LED_YELLOW,
    AW2023_LED_PURPLE,
    AW2023_LED_CYAN,
    AW2023_LED_WHITE,
};

rt_err_t drv_aw2023_init(const char* i2c_dev_name);

#ifdef __cplusplus
}
#endif

#endif