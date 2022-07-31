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

#ifndef BUTTER_H__
#define BUTTER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float A[4];
    float B[4];
    float X[4];
    float Y[4];
} Butter3;

/* butter lpf filter */
Butter3* butter3_filter_create(float b[4], float a[4]);
float butter3_filter_process(float in, Butter3* butter);

#ifdef __cplusplus
}
#endif

#endif
