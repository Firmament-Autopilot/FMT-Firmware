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
from ..asset_enums import AssetType
from ....core.dependecy_validator import DependencyValidator


class OemKeysValidator(DependencyValidator):
    """OEM keys policy validation"""

    def validate(self, **_kwargs):
        """Validates policy keys """
        _pp = self.parser

        provisioning_key_type = _pp.provisioning_key_type()
        provisioning_key_data = _pp.provisioning_key_data()

        code_encryption_key_data = _pp.code_encryption_key_data()
        code_encryption_key_type = _pp.code_encryption_key_type()

        if provisioning_key_type == AssetType.ASSET_NO_KEY:
            self._validate_empty_key(provisioning_key_data,
                                     'provisioning_key')
        else:
            self._validate_plain_key(provisioning_key_data,
                                     'provisioning_key')

        if code_encryption_key_type == AssetType.ASSET_NO_KEY:
            self._validate_empty_key(code_encryption_key_data,
                                     'code_encryption_key')
        else:
            self._validate_plain_key(code_encryption_key_data,
                                     'code_encryption_key')

    def _validate_empty_key(self, key, key_name):
        """Validates ASSET_NO_KEY case"""
        if key and key != b'\00' * 64:
            self.add_msg(f"'{key_name}': key must not be specified")

    def _validate_plain_key(self, key, key_name):
        """Validates ASSET_PLAIN_KEY case"""
        if not key or len(key) != 64:
            self.add_msg(f"'{key_name}': wrong key size")
