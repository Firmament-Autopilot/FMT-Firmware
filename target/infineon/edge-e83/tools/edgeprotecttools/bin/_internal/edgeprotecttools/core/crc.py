"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
import struct


def crc32d6a(data, initial_value):
    """Calculates 32-bit CRC code
    @param data: Input data for CRC calculation
    @param initial_value: Initial value for CRC calculation
    @return: Calculated 32-bit CRC (little endian)
    """
    if initial_value == 0:
        raise ValueError(f'Invalid initial value {initial_value}')
    result = initial_value
    for i in data:
        result = _crc32d6a_update(result, i)
    result = int(struct.unpack('<I', struct.pack('>I', result))[0])
    return result


def _crc32d6a_update(crc, data):
    """Updates CRC stage value in the 32-bit CRC calculation
    @param crc: CRC stage value
    @param data: Update value
    @return: Updated CRC value
    """
    crc32d6a_width = 32
    crc32d6a_byte_width = 8
    a = (crc >> (crc32d6a_width - crc32d6a_byte_width)) ^ data
    b = ((a << 18) & 0xFFFFFFFF) ^ ((a << 17) & 0xFFFFFFFF) ^ \
        ((a << 15) & 0xFFFFFFFF) ^ ((a << 14) & 0xFFFFFFFF) ^ a
    crc = b ^ ((crc << crc32d6a_byte_width) & 0xFFFFFFFF)
    return crc
