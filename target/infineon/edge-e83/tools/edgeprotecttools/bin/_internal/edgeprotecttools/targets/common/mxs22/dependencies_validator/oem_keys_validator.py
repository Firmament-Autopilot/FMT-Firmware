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
import os.path

from ....common.mxs22.asset_enums import KeyAlgorithm, KeyUsage
from .....core.dependecy_validator import DependencyValidator


class UserKeysValidator(DependencyValidator):
    """Validator for OEM keys specified in the policy"""

    section = "Policy section 'user_keys'"

    def validate(self, **_kwargs):
        """Runs all OEM keys validators"""
        try:
            user_keys = self.parser.user_keys(ret_value=True)
        except KeyError as e:
            self.add_msg(f"{self.section}: invalid structure, missing {e} field")
        except TypeError:
            self.add_msg(f"{self.section}: invalid 'key' value")
        else:
            if user_keys:
                for key in user_keys:
                    if self._validate_fields_existence(key):
                        if self._validate_kid_type(key):
                            self._validate_kid_range(key)
                        self._validate_alg(key)
                        self._validate_use(key)
                        self._validate_key(key)
                        owner = key.get('owner')
                        if owner and owner.get('value'):
                            if self._validate_owner_type(owner.get('value')):
                                self._validate_owner_range(key)
                    if not self.is_valid:
                        break

    def _validate_fields_existence(self, key):
        for field in ('kid', 'alg', 'use'):
            if field not in key:
                self.add_msg(f"{self.section}: invalid structure, missing "
                             f"'{field}' field")
                return False
            if 'value' not in key[field]:
                self.add_msg(
                    f"{self.section}: invalid structure, missing 'value' field")
                return False
        return True

    def _validate_kid_type(self, key):
        try:
            int(str(key['kid']['value']), 0)
        except ValueError:
            self.add_msg(
                f"{self.section}: invalid 'kid' value '{key['kid']['value']}'")
            return False
        return True

    def _validate_kid_range(self, key):
        uint32_min = 0x40000000
        uint32_max = 0x7FFEFFFF
        kid = int(str(key['kid']['value']), 0)
        if kid < uint32_min or kid > uint32_max:
            self.add_msg(f"{self.section}: 'kid' value out of range "
                         f"{uint32_min:#010x} - {uint32_max:#010x}")

    def _validate_alg(self, key):
        alg = key['alg']['value'].upper().strip()
        valid = [x.name for x in KeyAlgorithm]
        if alg not in valid:
            self.add_msg(f"{self.section}: invalid 'alg' value '{alg}'. "
                         f"Valid values: {', '.join(valid)}'")

    def _validate_use(self, key):
        valid = [x.name for x in KeyUsage]
        for use in key['use']['value'].split('|'):
            use = use.upper().strip()
            if use not in valid:
                self.add_msg(f"{self.section}: invalid 'use' value '{use}'. "
                             f"Valid values: {', '.join(valid)}'")

    def _validate_key(self, key):
        key_path = key['key']['value']
        if not os.path.isfile(key_path):
            self.add_msg(f"{self.section}: cannot find file '{key_path}'",
                         severity='warning')

    def _validate_owner_type(self, owner):
        try:
            int(str(owner), 0)
        except ValueError:
            self.add_msg(
                f"{self.section}: invalid 'owner'"
                f" value '{owner}'")
            return False
        return True

    def _validate_owner_range(self, key):
        int32_min = -2147483648
        int32_max = 2147483647
        owner = int(str(key['owner']['value']), 0)
        if owner < int32_min or owner > int32_max:
            self.add_msg(f"{self.section}: 'owner' value out of range "
                         f"{int32_min} - {int32_max}")
