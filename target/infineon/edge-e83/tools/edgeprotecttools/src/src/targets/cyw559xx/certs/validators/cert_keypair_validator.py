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

from cryptography.hazmat.primitives.asymmetric.rsa import RSAPrivateKey

from .....core.dependecy_validator import DependencyValidator
from .....core.key_handlers import load_private_key


class CertKeyPairValidator(DependencyValidator):
    """Validates the certificate keypair property"""

    def validate(self, **_kwargs):
        """Validates the certificate keypair property"""
        config_parser = self.parser

        key_path = config_parser.cert_keypair()
        password = config_parser.cert_keypair_pwd()

        if key_path is None:
            self.add_msg("'cert_keypair' property must be specified")
            return

        if not os.path.isfile(key_path):
            self.add_msg(f"File not found: '{key_path}'")
            return

        try:
            key = load_private_key(key_path, password=password)
        except (TypeError, ValueError) as e:
            self.add_msg(f"Failed to load key '{key_path}'")
            if 'could not deserialize' in str(e).lower():
                self.add_msg('Invalid key type. Make sure the key is RSA '
                             'private key of 3072 bits length')
            else:
                self.add_msg(str(e))
            return

        if not isinstance(key, RSAPrivateKey) or key.key_size != 3072:
            self.add_msg(f"Failed to load key '{key_path}'")
            self.add_msg('Invalid key type. Make sure the key is RSA '
                         'private key of 3072 bits length')
            return
