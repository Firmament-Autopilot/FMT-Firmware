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

#include <firmament.h>
#include <math.h>
#include <string.h>

#include "module/math/ap_math.h"

#define IS_ALPHA(c) ((c >= 'a' && c < 'z') || (c >= 'A' && c <= 'Z'))

// 快速算“平方根的倒数”。
// http://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E6%A0%B9%E5%80%92%E6%95%B0%E9%80%9F%E7%AE%97%E6%B3%95
float math_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;            // evil floating point bit level hacking（对浮点数的邪恶位级hack）
    i = 0x5f3759df - (i >> 1); // what the fuck?（这他妈的是怎么回事？）
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration （第一次牛顿迭代）
    y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, this can be removed（第二次迭代，可以删除）

    return y;
}

void math_vector_cross(float result[3], const float left[3], const float right[3])
{
    result[0] = left[1] * right[2] - left[2] * right[1];
    result[1] = left[2] * right[0] - left[0] * right[2];
    result[2] = left[0] * right[1] - left[1] * right[0];
}

float math_vector_dot(const float left[3], const float right[3])
{
    return left[0] * right[0] + left[1] * right[1] + left[2] * right[2];
}

float math_vector_length(const float v[3])
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

// 计算CRC-16-CCITT。
// http://www.dzjs.net/html/qianrushixitong/2007/0530/2162.html
// crc为上次的结果，开始时设为0。用于分段计算。
uint16_t math_crc16(uint16_t crc, const void* data, uint16_t len)
{
    const static uint16_t crc_tab[16] = {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF
    };
    uint8_t h_crc;
    const uint8_t* ptr = (const uint8_t*)data;

    //
    while (len--) {
        h_crc = (uint8_t)(crc >> 12);
        crc <<= 4;
        crc ^= crc_tab[h_crc ^ ((*ptr) >> 4)];
        //
        h_crc = crc >> 12;
        crc <<= 4;
        crc ^= crc_tab[h_crc ^ ((*ptr) & 0x0F)];
        //
        ptr++;
    }

    //
    return crc;
}

uint32_t math_hex2dec(const char* hex)
{
    uint32_t i;
    uint32_t len = strlen(hex);
    uint32_t dec = 0;

    for (i = 0; i < len; i++) {
        char c = *(hex + i);
        uint32_t temp;
        if (IS_ALPHA(c)) {
            if (c >= 'A' && c <= 'F') {
                temp = (c - 'A') + 10;
            } else {
                temp = (c - 'a') + 10;
            }
        } else {
            temp = c - '0';
        }
        dec += temp << ((len - 1 - i) * 4);
    }

    return dec;
}

// 整数转字符串。
void math_itoa(int32_t val, char* str)
{
    char buf[16];
    buf[15] = '\0';
    uint8_t index = 16;
    int nagative = 0;

    //
    if (val == 0) {
        // 先考虑val=0的情况。
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    //
    // 考虑val<0的情况。
    if (val < 0) {
        val = -val;
        nagative = 1;
    }

    //
    while (val > 0 && index != 0) {
        index--;
        buf[index] = val % 10 + '0';
        val /= 10;
    }

    //
    // 复制结果。
    int i_str = 0;

    if (nagative)
        str[i_str++] = '-';

    for (int i_buf = index; i_buf < 16; i_buf++)
        str[i_str++] = buf[i_buf];

    str[i_str++] = '\0';
    //
    return;
}

// 整数转字符串。
// 不可重入，内存空间由函数管理。
const char* math_afromi(int32_t val)
{
    // int32_t最多只有10位，16字节足够。
    static char buffer[16];
    //
    math_itoa(val, buffer);
    //
    return buffer;
}

void Vector3_Set(float vector[3], float x, float y, float z)
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}

void Vector3_Normalize(float result[3], const float vector[3])
{
    float rsqrt = math_rsqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
    result[0] = vector[0] * rsqrt;
    result[1] = vector[1] * rsqrt;
    result[2] = vector[2] * rsqrt;
}

void Vector3_CrossProduct(float result[3], const float vector1[3], const float vector2[3])
{
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}

float Vector3_DotProduct(const float vector1[3], const float vector2[3])
{
    return vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2];
}

float Vector3_Length(const float vector[3])
{
    return sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
}

void Vector2_Normalize(float result[2], float vector[2])
{
    float rsqrt = math_rsqrt(vector[0] * vector[0] + vector[1] * vector[1]);
    result[0] = vector[0] * rsqrt;
    result[1] = vector[1] * rsqrt;
}

float Vector2_DotProduct(const float vector1[2], const float vector2[2])
{
    return vector1[0] * vector2[0] + vector1[1] * vector2[1];
}

uint8_t constrain(float* val, float min_val, float max_val)
{
    if (*val > max_val) {
        *val = max_val;
        return 1;
    }

    if (*val < min_val) {
        *val = min_val;
        return 2;
    }

    return 0;
}

float constrain_float(float amt, float low, float high)
{
    // the check for NaN as a float prevents propogation of
    // floating point errors through any function that uses
    // constrain_float(). The normal float semantics already handle -Inf
    // and +Inf
    if (isnan(amt)) {
        return (low + high) * 0.5f;
    }

    return ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)));
}

uint16_t constrain_uint16(uint16_t amt, uint16_t low, uint16_t high)
{
    return ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)));
}

uint32_t constrain_uint32(uint32_t amt, uint32_t low, uint32_t high)
{
    return ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)));
}
