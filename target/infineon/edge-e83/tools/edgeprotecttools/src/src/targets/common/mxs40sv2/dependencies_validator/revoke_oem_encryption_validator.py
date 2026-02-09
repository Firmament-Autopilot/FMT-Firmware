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
from .....core.dependecy_validator import DependencyValidator


class RevocationAndEncryptionValidator(DependencyValidator):
    def validate(self, **_kwargs):
        _pp = self.parser

        encryption = _pp.get_encryption()
        revoke = _pp.get_revoke_oem_pubkey_0()

        if revoke and encryption:
            self.add_msg('Either the "revoke_oem_pubkey_0" or the '
                         '"encryption" can be used. '
                         '"revoke_oem_pubkey_0" and "encryption" '
                         'can not be enabled at once. '
                         'Please edit the policy')
