"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import hashlib
import logging

from .key_handlers.rsa_handler import RSAHandler
from .key_handlers.pem_key import PemKey

logger = logging.getLogger(__name__)

TRUNCATED_SHA256_SIZE = 16
PUB_KEY_SIZE = 516
AES_KEY_SIZE = 16


def jwk_to_pem(jwk_file, private_key=True):
    """Converts JWK file content to PEM format string"""
    pem = PemKey(jwk_file)
    pem_str = pem.to_str(private_key=private_key)
    return pem_str


def get_key_bytearray(key_path):
    """Gets key bytes"""
    if key_path and os.path.isfile(key_path):
        if verify_key_format(key_path, 'binary'):
            with open(key_path, 'rb') as key:
                key_bytes = key.read()
        elif verify_key_format(key_path, 'rsa'):
            key_str = RSAHandler.convert_to_mbedtls(key_path)
            key_bytes = bytearray.fromhex(key_str)
        else:
            raise ValueError(f'Invalid key format ({key_path})')
        return key_bytes

    zero_bytes = bytes(b'\x00' * PUB_KEY_SIZE)
    return zero_bytes


def calc_key_hash(key_path):
    """Calculates key hash"""
    empty_bytes = bytes(PUB_KEY_SIZE)
    key_bytes = get_key_bytearray(key_path)
    if key_bytes != empty_bytes:
        hash_object = hashlib.sha256(key_bytes[4:])
        hex_dig = hash_object.digest()
        key_hash = hex_dig[:TRUNCATED_SHA256_SIZE]
        return key_hash

    zero_bytes = bytes(b'\x00' * TRUNCATED_SHA256_SIZE)
    return zero_bytes


def verify_key_format(key_path, key_type):
    """Verifies whether key format matches the specified"""
    if key_type == 'rsa':
        try:
            RSAHandler.public_numbers(key_path)
        except ValueError:
            return False
        return True
    if key_type == 'binary':
        return os.path.getsize(key_path) == AES_KEY_SIZE
    raise ValueError(f'Invalid key type ({key_type})')
