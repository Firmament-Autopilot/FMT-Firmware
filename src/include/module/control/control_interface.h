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

#ifndef CONTROL_INTERFACE_H__
#define CONTROL_INTERFACE_H__

#include <Controller.h>

#ifdef __cplusplus
extern "C" {
#endif

extern fmt_model_info_t control_model_info;

void control_interface_init(void);
void control_interface_step(uint32_t timestamp);

#ifdef __cplusplus
}
#endif

#endif