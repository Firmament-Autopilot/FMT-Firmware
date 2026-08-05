"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import serialization


class EcdhKdf(object):
    def __init__(self, private_key, public_key, key_length, salt, info): 
        
        salt_length = 16

        self.backend = default_backend()
        self.host_key_pair = serialization.load_pem_private_key(
            private_key, password=None, backend=self.backend)
        
        # Deserialize public key: extract from private
        # or directly from pem file
        try:
            self.device_public_key = serialization.load_pem_private_key(
                public_key, password=None, backend=self.backend).public_key()
        except ValueError:
            self.device_public_key = serialization.load_pem_public_key(
                public_key, backend=self.backend)

        self.key_length = key_length
        self.iv_length = 16

        if salt is not None:
            self.salt = EcdhKdf.get_bytes(salt)
        else:
            self.salt = os.urandom(salt_length)
        self.info = EcdhKdf.get_bytes(info)
        
        self.derived_key = self.derive_key()
        self.aes_key = self.derived_key[:self.key_length]
        self.iv = self.derived_key[self.key_length:]

    @staticmethod
    def get_bytes(data):
        if type(data) is str:
            return str.encode(data, 'utf-8')
        elif type(data) is bytes:
            return data
        else:
            raise ValueError('Unknown input data type.')
        
    @staticmethod
    def read_key_bytes(key_file):
        with open(key_file, 'rb') as key_file:
            return key_file.read()

    def derive_key(self):
        shared_key = self.host_key_pair.exchange(ec.ECDH(),
                                                 self.device_public_key)
        derived_key = HKDF(algorithm=hashes.SHA256(),
                           length=self.key_length + self.iv_length,
                           salt=self.salt,
                           info=self.info,
                           backend=self.backend).derive(shared_key)
        return derived_key
