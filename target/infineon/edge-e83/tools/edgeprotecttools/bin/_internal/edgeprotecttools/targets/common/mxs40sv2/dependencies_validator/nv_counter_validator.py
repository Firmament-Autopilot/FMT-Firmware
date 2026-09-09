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
from .....core.dependecy_validator import DependencyValidator


class NvCounterValidator(DependencyValidator):
    """Validator for NV counter(s) specified in the policy"""

    def validate(self, **_kwargs):
        """Runs all nv_counter validators"""
        nv_counter = self.parser.get_nv_counter()
        bits_per_cnt = self.parser.get_bits_per_cnt()

        if not self._validate_nv_counter_type(nv_counter):
            return
        if not self._validate_arrays_len(nv_counter, bits_per_cnt):
            return
        if not self._validate_bits_per_cnt_sum(bits_per_cnt):
            return
        self._validate_nv_counters(nv_counter, bits_per_cnt)

    def _validate_nv_counter_type(self, value):
        """Validates nv_counter type. It can be either integer or
        a list of integers. Do it in dependency validator because JSON
        schema draft-03 does not support this feature
        """
        if not isinstance(value, int):
            if not all(isinstance(item, int) for item in value):
                self.add_msg('Invalid nv_counter type, it can be either '
                             'integer or a list of integers')
                return False
        return True

    def _validate_arrays_len(self, nv_counter, bits_per_cnt):
        """Validates whether nv_counter and bits_per_cnt arrays
        are of the same length
        """
        if isinstance(nv_counter, int):
            if len(bits_per_cnt) > 1:
                self.add_msg('Number of items in the nv_counter and '
                             'bits_per_cnt must be equal')
                return False
        elif isinstance(nv_counter, list):
            if len(nv_counter) != len(bits_per_cnt):
                self.add_msg('Number of items in the nv_counter and '
                             'bits_per_cnt must be equal')
                return False
        return True

    def _validate_bits_per_cnt_sum(self, bits_per_cnt, total=32):
        """Checks whether sum of bits_per_cnt array equals to the total
        number of nv counter bits
        """
        if sum(bits_per_cnt) != total:
            self.add_msg(f'Sum of bits_per_cnt must be equal to {total}')
            return False
        return True

    def _validate_nv_counters(self, nv_counter, bits_per_cnt):
        """Checks each element of the nv_counter array to not exceed the
        size of defined bits
        """
        if isinstance(nv_counter, list):
            for (value, bits) in zip(nv_counter, bits_per_cnt):
                if not 0 <= value <= bits:
                    self.add_msg(
                        'nv_counter value must be a positive number and less '
                        'or equal to the corresponding bits_per_cnt value')
                    return False
        return True
