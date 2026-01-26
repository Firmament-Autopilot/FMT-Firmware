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
import hashlib
import os
from typing import Union

from cryptography.hazmat.primitives.asymmetric import rsa

from ....core.key_handlers.rsa_handler import RSAHandler
from ....core.key_handlers import load_public_key
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ..asset_enums import AssetType, HbkType


class PolicyParserOemProvisioning(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    @staticmethod
    def oem_mandatory_field_type(ret_value=False) -> Union[AssetType, int]:
        """Gets a value of the oem_mandatory_field.type property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return HbkType.DMPU_HBK_TYPE_HBK1.value if ret_value \
            else HbkType.DMPU_HBK_TYPE_HBK1

    def oem_public_key(self):
        """Gets a value of the oem_public_key property
        @return: The enum object or its value
        """
        pubkey = self.rsa_key_field('oem_public_key', 'value')

        if not pubkey:
            raise ValueError("No RSA key found in the policy")

        n = RSAHandler.public_numbers(pubkey).modulus.to_bytes(
            pubkey.key_size // 8, 'big'
        )
        np = RSAHandler.rsa_np(pubkey).to_bytes(20, 'big')
        sha256_hash = hashlib.sha256()
        sha256_hash.update(n + np)
        value = sha256_hash.digest()[:16] + b'\x00' * 16
        return value

    def provisioning_key_type(self, ret_value=False) -> Union[AssetType, int]:
        """Gets a value of the provisioning_key.type property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(AssetType, ret_value,
                               'provisioning_key', 'type', 'value')

    def provisioning_key_data(self) -> bytes:
        """Gets a value of the provisioning_key.data property
        @return: The enum object or its value
        """
        data = self.bin_file_or_hex_string_field(
            'provisioning_key', 'data', 'value'
        )

        if data:
            if len(data) != 16:
                raise ValueError(
                    "Provisioning key data must be 16 bytes long"
                )
        else:
            data = bytes(64)

        return data + b'\x00' * (64 - len(data))

    def code_encryption_key_type(self, ret_value=False) \
            -> Union[AssetType, int]:
        """Gets a value of the code_encryption_key.type property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(AssetType, ret_value,
                               'code_encryption_key', 'type', 'value')

    def code_encryption_key_data(self) -> bytes:
        """Gets a value of the code_encryption_key.data property
        @return: The enum object or its value
        """
        data = self.bin_file_or_hex_string_field(
            'code_encryption_key', 'data', 'value'
        )

        if data:
            if len(data) != 16:
                raise ValueError(
                    "Code encryption key data must be 16 bytes long"
                )
        else:
            data = bytes(64)

        return data + b'\x00' * (64 - len(data))

    def nv_counter(self):
        """Gets a value of the nv_counter property
        @return: The enum object or its value
        """
        data = self.field('nv_counter', 'value')
        return int(str(data), 0) if data else 0

    def rsa_key_field(self, *keys):
        """Gets a field containing path to RSA key file"""
        path = self.field(*keys)
        if path:
            if not os.path.isabs(path):
                path = os.path.abspath(str(os.path.join(self.policy_dir, path)))

            try:
                key = load_public_key(path)
                if not (isinstance(key,
                                   rsa.RSAPublicKey) and key.key_size == 3072):
                    raise TypeError
            except (ValueError, TypeError) as e:
                raise ValueError(f"Unexpected key type: '{path}'. Expected: "
                                 f"RSA public key of the 3072-bit size") from e
        else:
            key = None
        return key
