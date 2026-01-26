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

from ......core.dependecy_validator import DependencyValidator


class DeviceIdValidator(DependencyValidator):
    """Validator for device_id field specified in the debug token"""

    def validate(self, **_kwargs):
        """Validates debug token device_id property"""
        silicon_id = self.parser.get_silicon_id()
        family_id = self.parser.get_family_id()
        revision_id = self.parser.get_revision_id()

        try:
            struct.pack('<H', int(silicon_id, 16))
        except (ValueError, struct.error):
            self.add_msg("Invalid 'silicon_id' value. Unsigned short "
                         'format requires 0 <= number <= 0xFFFF')

        try:
            struct.pack('<H', int(family_id, 16))
        except (ValueError, struct.error):
            self.add_msg("Invalid 'family_id' value. Unsigned short "
                         'format requires 0 <= number <= 0xFFFF')

        try:
            struct.pack('<B', int(revision_id, 16))
        except (ValueError, struct.error):
            self.add_msg("Invalid 'revision_id' value. Unsigned byte "
                         'format requires 0 <= number <= 0xFF')
