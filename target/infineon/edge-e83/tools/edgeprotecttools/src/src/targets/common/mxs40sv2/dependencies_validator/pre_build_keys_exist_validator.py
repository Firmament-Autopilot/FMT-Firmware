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


class PreBuildKeysExistValidator(DependencyValidator):
    def validate(self, **_kwargs):
        _pp = self.parser

        pub_key_0 = _pp.get_program_oem_key_0_hash()
        pub_key_1 = _pp.get_program_oem_key_1_hash()
        smif_encryption = _pp.get_encryption()

        if pub_key_0:
            key = _pp.get_pub_key_0_path()
            if key is None or not os.path.isfile(key):
                self.add_msg(f'OEM public key 0 not found ({key})')

        if pub_key_1:
            key = _pp.get_pub_key_1_path()
            if key is None or not os.path.isfile(key):
                self.add_msg(f'OEM public key 1 not found ({key})')

        if smif_encryption:
            key = _pp.get_encrypt_key_path()
            if key is None or not os.path.isfile(key):
                self.add_msg(f'Encryption key not found ({key})')
