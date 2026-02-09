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

from .....core.dependecy_validator import DependencyValidator


class OemSecureKeyValidator(DependencyValidator):
    def validate(self, **_kwargs):
        _pp = self.parser

        key = _pp.get_oem_secure_key(ret_value=False)

        if key is not None:
            if not isinstance(key, str):
                self.add_msg(
                    f'Unexpected OEM secure key type ({type(key)})'
                )
            elif key.endswith('.bin'):
                if not os.path.isabs(key):
                    key = os.path.abspath(
                        os.path.join(_pp.policy_dir, key)
                    )
                if not os.path.isfile(key):
                    self.add_msg(f'OEM secure key not found ({key})')
            else:
                if not all(x.lower() in '0123456789abcdef' for x in key):
                    self.add_msg(
                        'OEM secure key must be a hex string or '
                        'a path to a binary (.bin) file'
                    )
                elif len(key) % 2:
                    self.add_msg(
                        'OEM secure key provided as hex string '
                        'must have an even number of digits'
                    )
                elif len(key) == 0:
                    self.add_msg('OEM secure key cannot be empty')

        if not self.is_valid:
            return

        oem_secure_key = _pp.get_oem_secure_key()

        if oem_secure_key:
            if not (
                isinstance(oem_secure_key, bytes) and len(oem_secure_key) == 16
            ):
                self.add_msg('OEM secure key shall have the length of 16 bytes')
