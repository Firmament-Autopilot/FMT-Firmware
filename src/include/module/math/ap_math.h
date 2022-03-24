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

#ifndef AP_MATH_H__
#define AP_MATH_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float x;
    float y;
} Vector2f_t;

typedef struct {
    float x;
    float y;
    float z;
} Vector3f_t;

float math_rsqrt(float number);
float math_vector_length(const float v[3]);
float math_vector_dot(const float left[3], const float right[3]);
void math_vector_cross(float result[3], const float left[3], const float right[3]);
uint16_t math_crc16(uint16_t crc, const void* data, uint16_t len);
void math_itoa(int32_t val, char* str);
uint32_t math_hex2dec(const char* hex);
const char* math_afromi(int32_t val);

void Vector3_Set(float vector[3], float x, float y, float z);
void Vector3_Normalize(float result[3], const float vector[3]);
void Vector3_CrossProduct(float result[3], const float vector1[3], const float vector2[3]);
float Vector3_DotProduct(const float vector1[3], const float vector2[3]);
float Vector3_Length(const float vector[3]);
void Vector2_Normalize(float result[2], float vector[2]);
float Vector2_DotProduct(const float vector1[2], const float vector2[2]);

uint8_t constrain(float* val, float min_val, float max_val);
float constrain_float(float amt, float low, float high);
uint16_t constrain_uint16(uint16_t amt, uint16_t low, uint16_t high);
uint32_t constrain_uint32(uint32_t amt, uint32_t low, uint32_t high);

#ifdef __cplusplus
}
#endif

#endif
