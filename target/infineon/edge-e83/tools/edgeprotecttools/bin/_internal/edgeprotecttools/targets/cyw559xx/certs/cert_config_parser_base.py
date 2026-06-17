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
import json
import os
from typing import Union

from cryptography.hazmat.primitives.asymmetric.rsa import RSAPrivateKey

from .cert_enums import CertificateType
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ....core.key_handlers import load_private_key


class CertConfigParserBase(PolicyParserPrimitives):
    """Base class for the certificate configuration files parser"""

    def __init__(self, cert_config):
        if isinstance(cert_config, str):
            with open(cert_config, encoding='utf-8') as f:
                self.template = json.load(f)
            self.cert_config_file = cert_config
            self.cert_config_dir = os.path.dirname(self.cert_config_file)
        elif isinstance(cert_config, dict):
            self.template = cert_config
            self.cert_config_dir = os.getcwd()
        else:
            raise TypeError(f"Invalid 'cert_config' type '{type(cert_config)}'")
        super().__init__(self.template, self.cert_config_dir)

    def cert_type(self, ret_value=False) -> Union[CertificateType, int]:
        """Gets a value of certificate.type property"""
        return self.enum_field(CertificateType, ret_value, 'certificate',
                               'type')

    def cert_version(self) -> float:
        """Gets a value of certificate.version property"""
        return self.field('certificate', 'version')

    def cert_keypair(self, ret_value=False) -> Union[str, RSAPrivateKey, None]:
        """Gets a value of cert_keypair.value property"""
        key = self.field('cert_keypair', 'value')
        if not key:
            return None
        if isinstance(key, str):
            if not os.path.isabs(key):
                key = os.path.abspath(os.path.join(self.cert_config_dir, key))
            if ret_value:
                pwd = self.cert_keypair_pwd() or None
                key = load_private_key(key, password=pwd)
                if not isinstance(key, RSAPrivateKey) or key.key_size != 3072:
                    raise ValueError('The signing key must be an RSA private '
                                     'key of the 3072-bit size')

        return key

    def cert_keypair_pwd(self) -> str:
        """Gets a value of cert_keypair_pwd.value property"""
        return self.field('cert_keypair_pwd', 'value')

    def nv_counter(self) -> int:
        """Gets a value of nv_counter property"""
        return int(str(self.field('nv_counter', 'value')), 0)
