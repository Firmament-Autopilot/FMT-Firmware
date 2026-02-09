"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from typing import Union

from ...common.policy_parser_primitives import PolicyParserPrimitives


class PolicyParserDeviceIdentity(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def dev_id_incremental_counter(self, ret_value=False) -> Union[int, bytes,
                                                                   None]:
        """Gets a value of the 'incremental_counter' property"""
        value = self.field('incremental_counter', 'value')
        if value:
            int_value = int(str(value), 0)
            return int_value.to_bytes(4, 'big') if ret_value else int_value
        return None

    def dev_id_initial_value(self, ret_value=False) -> Union[int, bytes, None]:
        """Gets a value of the 'initial_value' property"""
        value = self.field('initial_value', 'value')
        if value:
            int_value = int(str(value), 0)
            return int_value.to_bytes(4, 'big') if ret_value else int_value
        return None
