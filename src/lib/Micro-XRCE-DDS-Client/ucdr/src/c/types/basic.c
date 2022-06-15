// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "../common_internal.h"

#include <string.h>

// -------------------------------------------------------------------
//                    SERIALIZE MACROS
// -------------------------------------------------------------------
#define UCDR_SERIALIZE_BYTE_1(TYPE, ENDIAN)        \
    (void)ENDIAN;                                  \
    if (ucdr_check_final_buffer_behavior(ub, 1)) { \
        *ub->iterator = (uint8_t)value;            \
        ub->iterator += 1;                         \
        ub->offset += 1;                           \
        ub->last_data_size = 1;                    \
    }                                              \
    return !ub->error;

#define UCDR_SERIALIZE_BYTE_2_CORE()                 \
    const uint8_t* bytes_pointer = (uint8_t*)&value; \
    *ub->iterator = *(bytes_pointer + 1);            \
    *(ub->iterator + 1) = *bytes_pointer;

#define UCDR_SERIALIZE_BYTE_4_CORE()                 \
    const uint8_t* bytes_pointer = (uint8_t*)&value; \
    *ub->iterator = *(bytes_pointer + 3);            \
    *(ub->iterator + 1) = *(bytes_pointer + 2);      \
    *(ub->iterator + 2) = *(bytes_pointer + 1);      \
    *(ub->iterator + 3) = *bytes_pointer;

#define UCDR_SERIALIZE_BYTE_8_CORE()                 \
    const uint8_t* bytes_pointer = (uint8_t*)&value; \
    *ub->iterator = *(bytes_pointer + 7);            \
    *(ub->iterator + 1) = *(bytes_pointer + 6);      \
    *(ub->iterator + 2) = *(bytes_pointer + 5);      \
    *(ub->iterator + 3) = *(bytes_pointer + 4);      \
    *(ub->iterator + 4) = *(bytes_pointer + 3);      \
    *(ub->iterator + 5) = *(bytes_pointer + 2);      \
    *(ub->iterator + 6) = *(bytes_pointer + 1);      \
    *(ub->iterator + 7) = *bytes_pointer;

#define UCDR_SERIALIZE_BYTE_N(TYPE, SIZE, ENDIAN)       \
    size_t alignment = ucdr_buffer_alignment(ub, SIZE); \
    ub->iterator += alignment;                          \
    ub->offset += alignment;                            \
    if (ucdr_check_final_buffer_behavior(ub, SIZE)) {   \
        if (UCDR_MACHINE_ENDIANNESS == ENDIAN) {        \
            memcpy(ub->iterator, (void*)&value, SIZE);  \
        } else {                                        \
            UCDR_SERIALIZE_BYTE_##SIZE##_CORE()         \
        }                                               \
        ub->iterator += SIZE;                           \
        ub->offset += SIZE;                             \
        ub->last_data_size = SIZE;                      \
    }                                                   \
    return !ub->error;

#define UCDR_SERIALIZE_BYTE_2(TYPE, ENDIAN) UCDR_SERIALIZE_BYTE_N(TYPE, 2, ENDIAN)
#define UCDR_SERIALIZE_BYTE_4(TYPE, ENDIAN) UCDR_SERIALIZE_BYTE_N(TYPE, 4, ENDIAN)
#define UCDR_SERIALIZE_BYTE_8(TYPE, ENDIAN) UCDR_SERIALIZE_BYTE_N(TYPE, 8, ENDIAN)

#define UCDR_BASIC_TYPE_SERIALIZE_DEFINITION(SUFFIX, TYPE, SIZE)                              \
    bool ucdr_serialize##SUFFIX(ucdrBuffer* ub, TYPE value)                                   \
    {                                                                                         \
        UCDR_SERIALIZE_BYTE_##SIZE(TYPE, ub->endianness)                                      \
    }                                                                                         \
    bool ucdr_serialize_endian##SUFFIX(ucdrBuffer* ub, ucdrEndianness endianness, TYPE value) \
    {                                                                                         \
        UCDR_SERIALIZE_BYTE_##SIZE(TYPE, endianness)                                          \
    }

// -------------------------------------------------------------------
//                    DESERIALIZE MACROS
// -------------------------------------------------------------------
#define UCDR_DESERIALIZE_BYTE_1(TYPE, ENDIAN)      \
    (void)ENDIAN;                                  \
    if (ucdr_check_final_buffer_behavior(ub, 1)) { \
        *value = (TYPE)*ub->iterator;              \
        ub->iterator += 1;                         \
        ub->offset += 1;                           \
        ub->last_data_size = 1;                    \
    }                                              \
    return !ub->error;

#define UCDR_DESERIALIZE_BYTE_2_CORE()        \
    uint8_t* bytes_pointer = (uint8_t*)value; \
    *bytes_pointer = *(ub->iterator + 1);     \
    *(bytes_pointer + 1) = *ub->iterator;

#define UCDR_DESERIALIZE_BYTE_4_CORE()          \
    uint8_t* bytes_pointer = (uint8_t*)value;   \
    *bytes_pointer = *(ub->iterator + 3);       \
    *(bytes_pointer + 1) = *(ub->iterator + 2); \
    *(bytes_pointer + 2) = *(ub->iterator + 1); \
    *(bytes_pointer + 3) = *ub->iterator;

#define UCDR_DESERIALIZE_BYTE_8_CORE()          \
    uint8_t* bytes_pointer = (uint8_t*)value;   \
    *bytes_pointer = *(ub->iterator + 7);       \
    *(bytes_pointer + 1) = *(ub->iterator + 6); \
    *(bytes_pointer + 2) = *(ub->iterator + 5); \
    *(bytes_pointer + 3) = *(ub->iterator + 4); \
    *(bytes_pointer + 4) = *(ub->iterator + 3); \
    *(bytes_pointer + 5) = *(ub->iterator + 2); \
    *(bytes_pointer + 6) = *(ub->iterator + 1); \
    *(bytes_pointer + 7) = *ub->iterator;

#define UCDR_DESERIALIZE_BYTE_N(TYPE, SIZE, ENDIAN)     \
    size_t alignment = ucdr_buffer_alignment(ub, SIZE); \
    ub->iterator += alignment;                          \
    ub->offset += alignment;                            \
    if (ucdr_check_final_buffer_behavior(ub, SIZE)) {   \
        if (UCDR_MACHINE_ENDIANNESS == ENDIAN) {        \
            memcpy((void*)value, ub->iterator, SIZE);   \
        } else {                                        \
            UCDR_DESERIALIZE_BYTE_##SIZE##_CORE()       \
        }                                               \
        ub->iterator += SIZE;                           \
        ub->offset += SIZE;                             \
        ub->last_data_size = SIZE;                      \
    }                                                   \
    return !ub->error;

#define UCDR_DESERIALIZE_BYTE_2(TYPE, ENDIAN) UCDR_DESERIALIZE_BYTE_N(TYPE, 2, ENDIAN)
#define UCDR_DESERIALIZE_BYTE_4(TYPE, ENDIAN) UCDR_DESERIALIZE_BYTE_N(TYPE, 4, ENDIAN)
#define UCDR_DESERIALIZE_BYTE_8(TYPE, ENDIAN) UCDR_DESERIALIZE_BYTE_N(TYPE, 8, ENDIAN)

#define UCDR_BASIC_TYPE_DESERIALIZE_DEFINITION(SUFFIX, TYPE, SIZE)                               \
    bool ucdr_deserialize##SUFFIX(ucdrBuffer* ub, TYPE* value)                                   \
    {                                                                                            \
        UCDR_DESERIALIZE_BYTE_##SIZE(TYPE, ub->endianness)                                       \
    }                                                                                            \
    bool ucdr_deserialize_endian##SUFFIX(ucdrBuffer* ub, ucdrEndianness endianness, TYPE* value) \
    {                                                                                            \
        UCDR_DESERIALIZE_BYTE_##SIZE(TYPE, endianness)                                           \
    }

// -------------------------------------------------------------------
//                         DEFINITION MACRO
// -------------------------------------------------------------------
#define UCDR_BASIC_TYPE_DEFINITIONS(SUFFIX, TYPE, SIZE)      \
    UCDR_BASIC_TYPE_SERIALIZE_DEFINITION(SUFFIX, TYPE, SIZE) \
    UCDR_BASIC_TYPE_DESERIALIZE_DEFINITION(SUFFIX, TYPE, SIZE)

// -------------------------------------------------------------------
//              PUBLIC DE-SERIALIZATION IMPLEMENTATIONS
// -------------------------------------------------------------------
UCDR_BASIC_TYPE_DEFINITIONS(_char, char, 1)
UCDR_BASIC_TYPE_DEFINITIONS(_bool, bool, 1)
UCDR_BASIC_TYPE_DEFINITIONS(_uint8_t, uint8_t, 1)
UCDR_BASIC_TYPE_DEFINITIONS(_uint16_t, uint16_t, 2)
UCDR_BASIC_TYPE_DEFINITIONS(_uint32_t, uint32_t, 4)
UCDR_BASIC_TYPE_DEFINITIONS(_uint64_t, uint64_t, 8)
UCDR_BASIC_TYPE_DEFINITIONS(_int8_t, int8_t, 1)
UCDR_BASIC_TYPE_DEFINITIONS(_int16_t, int16_t, 2)
UCDR_BASIC_TYPE_DEFINITIONS(_int32_t, int32_t, 4)
UCDR_BASIC_TYPE_DEFINITIONS(_int64_t, int64_t, 8)
UCDR_BASIC_TYPE_DEFINITIONS(_float, float, 4)
UCDR_BASIC_TYPE_DEFINITIONS(_double, double, 8)
