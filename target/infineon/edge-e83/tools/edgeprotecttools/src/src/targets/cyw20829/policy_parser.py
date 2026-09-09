"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import os

from ..common.mxs40sv2 import asset_enums as enums
from ..cyw20829_a0.policy_parser import PolicyParser


class PolicyParserCYW20829B1(PolicyParser):
    """
    Provides functionality for searching data in the package policy.
    """

    def get_oem_secure_key(self, ret_value=True):
        try:
            value = self.json['pre_build']['keys']['oem_secure_key']['value']
        except KeyError:
            value = None
        if not ret_value:
            return value
        if value:
            if value.endswith('.bin'):
                if not os.path.isabs(value):
                    value = os.path.abspath(
                        os.path.join(self.policy_dir, value)
                    )
                try:
                    with open(value, 'rb') as f:
                        return f.read()
                except FileNotFoundError as e:
                    raise ValueError('Failed to parse OEM secure key') from e
            else:
                try:
                    parsed_value = bytes.fromhex(value)
                    return parsed_value
                except ValueError as e:
                    raise ValueError('Failed to parse OEM secure key') from e
        return value

    def get_control_word(self):
        value = super().get_control_word()
        if self.get_oem_secure_key(ret_value=False):
            value |= enums.ControlWord.PROGRAM_OEM_SECURE_KEY_MSK
        return value
