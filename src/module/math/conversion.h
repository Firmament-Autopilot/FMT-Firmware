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

#ifndef CONVERSION_H__
#define CONVERSION_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RAD2DEG(u) ((u)*180.0f / PI)
#define DEG2RAD(u) ((u)*PI / 180.0f)

void Msb2Lsb(uint8_t* data, uint8_t bytes);
int16_t int16_t_from_bytes(uint8_t bytes[]);

#ifdef __cplusplus
}
#endif

#endif
