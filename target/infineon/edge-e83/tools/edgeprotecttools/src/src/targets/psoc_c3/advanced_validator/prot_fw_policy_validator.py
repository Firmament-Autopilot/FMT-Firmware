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

from ....core.dependecy_validator import DependencyValidator
from ....core.key_handlers import load_key


class ProtFwPolicyValidator(DependencyValidator):
    """Protected FW policy validation"""

    def validate(self, **_kwargs):
        """Validates Protected FW policy"""
        for _validate in (self._validate_prot_fw_key_exists,
                          self._validate_prot_fw_key_size,
                          self._validate_encrypt,
                          self._validate_prot_fw_rot_keys):
            _validate()
            if not self.is_valid:
                break

    def _validate_prot_fw_key_exists(self):
        key = self.parser.prot_fw_key(ret_value=False)

        if not os.path.isabs(key):
            key = os.path.abspath(
                os.path.join(self.parser.policy_dir, key)
            )
        if not os.path.isfile(key):
            self.add_msg(f"PROT_FW_KEY not found: '{key}'")

    def _validate_prot_fw_key_size(self):
        key = self.parser.prot_fw_key()

        if len(key) != 16:
            self.add_msg(f'Unexpected PROT_FW_KEY size ({len(key)}). '
                         f'Expected size: 16 bytes')

    def _validate_encrypt(self):
        encrypt = self.parser.prot_fw_encrypt_enable()
        if encrypt:
            iv = self.parser.prot_fw_encrypt_iv(ret_value=False)
            if not iv:
                self.add_msg(
                    '"encrypt.iv" must be specified '
                    'if "encrypt.enable" is enabled'
                )
            elif not all(x.lower() in '01234567890abcdef' for x in iv):
                if iv != 'random':
                    self.add_msg(
                        '"encrypt.iv" must be a hex string '
                        'or "random" for random iv generation'
                    )
            elif len(iv) != 32:
                self.add_msg(
                    f'Unexpected "encrypt.iv" size ({len(iv)})'
                )
        else:
            if self.parser.prot_fw_encrypt_iv():
                self.add_msg(
                    '"encrypt.iv" must be empty '
                    'if "encrypt.enable" is disabled'
                )

    def _validate_prot_fw_rot_keys(self):
        key_path = self.parser.prot_fw_rot_public_key_0(ret_hash=False)
        try:
            load_key(key_path)
        except Exception as e: # pylint: disable=broad-except
            self.add_msg(f'Error prot_fw_rot_public_key_0: {e}')
            return

        key_path = self.parser.prot_fw_rot_public_key_1(ret_hash=False)
        try:
            load_key(key_path)
        except Exception as e:  # pylint: disable=broad-except
            self.add_msg(f'Error prot_fw_rot_public_key_0: {e}')
            return


