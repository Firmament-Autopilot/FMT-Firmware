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
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding


class AESCipher(object):
    def __init__(self, key, iv):
        self.backend = default_backend()
        self.key = AESCipher.get_bytes(key)
        self.iv = AESCipher.get_bytes(iv)
        self.block_size = 128

    @staticmethod
    def get_bytes(data):
        if type(data) is str:
            return str.encode(data, 'utf-8')
        elif type(data) is bytes:
            return data
        else:
            raise ValueError('Unknown input data type.')


class AESCipherCBC(AESCipher):
    def __init__(self, key, iv):
        super().__init__(key, iv)
        self.cipher = Cipher(algorithms.AES(self.key), modes.CBC(self.iv), backend=self.backend)

    def encrypt(self, raw):
        encryptor = self.cipher.encryptor()
        padder = padding.PKCS7(self.block_size).padder()		
        return encryptor.update(padder.update(raw) + padder.finalize()) + encryptor.finalize()

    def decrypt(self, enc):
        decryptor = self.cipher.decryptor()
        unpadder = padding.PKCS7(self.block_size).unpadder()
        return unpadder.update(decryptor.update(enc) + decryptor.finalize()) + unpadder.finalize()


def read_key_from_file(key):
    content = key.splitlines()
    if len(content) < 2:
        raise ValueError('Not enough AES input data: in the file should be two lines: key, iv.')

    key = bytes.fromhex(content[0])
    iv = bytes.fromhex(content[1])

    if 8 * len(key) not in [128, 192, 256]:
        raise ValueError('Invalid AES Key length: should be 128, 192 or 256 bits.')
    check_iv_length(iv)

    return key, iv


def check_iv_length(iv):
    if 8 * len(iv) != 128:
        raise ValueError('Invalid AES IV length: should be 128 bits.')
    return True
