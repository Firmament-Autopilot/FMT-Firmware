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
import os.path

from ..asset_enums import BootCfgId
from ....core.dependecy_validator import DependencyValidator


class OemKeysValidator(DependencyValidator):
    """OEM keys policy validation"""

    def validate(self, **_kwargs):
        """Validates policy OEM keys section"""
        _pp = self.parser

        key0 = _pp.oem_rot_public_key_0()
        key1 = _pp.oem_rot_public_key_1()
        boot_cfg_id = _pp.boot_cfg_id()

        if boot_cfg_id == BootCfgId.BOOT_SIMPLE_APP:
            self._validate_simple_app(key0, key1)
        else:
            self._validate_not_simple_app(key0, key1)

    def _validate_simple_app(self, key0, key1):
        """Validates BOOT_SIMPLE_APP case"""
        if not os.path.isfile(key0):
            self.add_msg("Skip 'oem_rot_public_key_0' validation, "
                         "not used with simple app", severity='info')
        if not os.path.isfile(key1):
            self.add_msg("Skip 'oem_rot_public_key_1' validation, "
                         "not used with simple app", severity='info')

    def _validate_not_simple_app(self, key0, key1):
        """Validates NOT BOOT_SIMPLE_APP case"""
        if key0:
            if not os.path.isfile(key0):
                self.add_msg(f"'oem_rot_public_key_0': file not found '{key0}'")
        else:
            self.add_msg("'oem_rot_public_key_0': key is not specified")

        if key1:
            if not os.path.isfile(key1):
                self.add_msg(f"'oem_rot_public_key_1': file not found '{key1}'")
        else:
            self.add_msg("'oem_rot_public_key_1': key is not specified")
