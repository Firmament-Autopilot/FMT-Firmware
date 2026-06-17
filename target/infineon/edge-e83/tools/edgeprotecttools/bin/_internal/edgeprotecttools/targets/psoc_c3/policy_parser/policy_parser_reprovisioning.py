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
import os
from typing import Union

from ..asset_enums import KeyRevocation
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ....core.key_handlers import load_key
from ....core.key_handlers.ec_handler import ECHandler


class PolicyParserReprovisioning(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def revoke(self, ret_value=False) -> Union[KeyRevocation, int]:
        """Gets a value of the 'revoke' property"""
        return self.enum_field(KeyRevocation, ret_value, 'revoke', 'value')

    def public_key(self, ret_value=False):
        """Gets a value of the pre_build.keys.public_key property
        @param ret_value: Returns the key raw value (65 bytes) if True,
        otherwise the key path
        """
        key_path = self.field('public_key', 'value')
        if key_path:
            if not os.path.isabs(key_path):
                key_path = os.path.abspath(
                    os.path.join(self.policy_dir, key_path))
            if ret_value:
                key = load_key(key_path)
                return ECHandler.raw_format(key)
        return key_path
