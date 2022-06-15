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

#include "module/math/conversion.h"

void Msb2Lsb(uint8_t* data, uint8_t bytes)
{
    uint8_t temp;

    if (!bytes)
        return;

    for (uint8_t i = 0; i < bytes / 2; i++) {
        temp = data[i];
        data[i] = data[bytes - 1 - i];
        data[bytes - 1 - i] = temp;
    }
}

int16_t int16_t_from_bytes(uint8_t bytes[])
{
    union {
        uint8_t b[2];
        int16_t w;
    } u;

    u.b[1] = bytes[0];
    u.b[0] = bytes[1];

    return u.w;
}
