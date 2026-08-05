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

from cryptography.hazmat.primitives.asymmetric.rsa import RSAPublicKey

from .cert_config_parser_base import CertConfigParserBase
from ....core.key_handlers import load_public_key


class KeyCertConfigParser(CertConfigParserBase):
    """Searching data in the key certificate configuration file"""

    @staticmethod
    def hbk_id() -> int:
        """Gets a value of hbk_id. Only one value is supported"""
        return 1

    def next_cert_pubkey(self, ret_value=False) -> Union[str, RSAPublicKey,
                                                         None]:
        """Gets a value of next_cert_pubkey property"""
        key = self.field('next_cert_pubkey', 'value')
        if not key:
            return None
        if isinstance(key, str):
            if not os.path.isabs(key):
                key = os.path.abspath(os.path.join(self.cert_config_dir, key))
            if ret_value:
                key = load_public_key(key)
                if not isinstance(key, RSAPublicKey) or key.key_size != 3072:
                    raise ValueError('The next certificate public key must be '
                                     'an RSA key of size 3072 bits')
        return key
