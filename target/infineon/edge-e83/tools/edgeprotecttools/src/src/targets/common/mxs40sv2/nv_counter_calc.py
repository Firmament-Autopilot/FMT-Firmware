"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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


class NvCounterCalculator:
    """Convert an integer or list of integers to Non-Volatile (NV)
    counter format used by CYW20829 platform
    """

    @staticmethod
    def calculate(value, bits_per_cnt=None, image_id=None):
        """Builds NV counter value based on input data type
        Example:
        >>> NvCounterCalculator.calculate(4)
        15 (bin: 1111)
        >>> NvCounterCalculator.calculate(
        ...[3, 2, 1, 2, 3, 7], bits_per_cnt=[4, 3, 3, 3, 3, 16])
        8383671 (bin: 111 1111 1110 1100 1011 0111)
        """
        if isinstance(value, int):
            return NvCounterCalculator.single_value_counter(value)
        if all(isinstance(item, int) for item in value):
            return NvCounterCalculator.multi_value_counter(
                value, bits_per_cnt, image_id)
        raise TypeError(f"Invalid NV counter type '{type(value).__name__}'")

    @staticmethod
    def single_value_counter(value):
        """Creates NV counter value based on a single integer"""
        if not 0 <= value <= 32:
            raise ValueError('NV counter out of range 0-32')
        return NvCounterCalculator._calc_counter(value)

    @staticmethod
    def multi_value_counter(values, bits_per_cnt, image_id=None):
        """Creates NV counter value based on an array of integers.
        Optionally returns the counter for the specific image only
        """
        if len(values) != len(bits_per_cnt):
            raise ValueError('Different lengths of bits_per_cnt and nv_counter')
        nv_counter = 0
        shift = 0
        if image_id is None:
            for value, bits in zip(values, bits_per_cnt):
                nv_counter |= NvCounterCalculator._calc_counter(value, shift)
                shift += bits
        else:
            if not 0 <= image_id <= len(values) - 1:
                raise ValueError('Image ID is out of range')
            index = 0
            for value, bits in zip(values, bits_per_cnt):
                cnt = value if index == image_id else 0
                nv_counter |= NvCounterCalculator._calc_counter(cnt, shift)
                shift += bits
                index += 1

        return nv_counter

    @staticmethod
    def _calc_counter(value, bits_per_cnt=0):
        """
        Gets an integer that in a binary form has ones count equal
        to the specified value
        Example:
        >>> NvCounterCalculator._calc_counter(4)
        15 (bin: 1111)
        >>> NvCounterCalculator._calc_counter(7)
        127 (bin: 111 1111)
        >>> NvCounterCalculator._calc_counter(7, bits_per_cnt=16)
        8323072 (bin: 111 1111 0000 0000 0000 0000)
        """
        return pow(2, value) - 1 << bits_per_cnt
