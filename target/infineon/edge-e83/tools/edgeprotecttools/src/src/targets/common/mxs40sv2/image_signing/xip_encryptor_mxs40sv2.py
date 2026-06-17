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
from .encrypt_mxv40sv2 import EncryptorMXS40Sv2
from .....execute.imgtool.custom_encryptor import CustomEncryptor


class XipEncryptor(CustomEncryptor):
    """Custom encryption for XIP"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.initial_counter = kwargs.get('initial_counter')
        self.nonce = kwargs.get('nonce')
        self.plainkey = kwargs.get('plainkey')
        self.nonce_output = None

    def encrypt(self, image, **kwargs) -> bytes:
        encryptor = EncryptorMXS40Sv2(self.plainkey)
        ciphertext, _ = encryptor.encrypt(
            image, self.initial_counter, nonce=self.nonce
        )
        return ciphertext
