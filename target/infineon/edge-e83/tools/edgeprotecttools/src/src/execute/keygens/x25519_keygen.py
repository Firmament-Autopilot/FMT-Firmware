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

from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import x25519

from ...core.enums import KeyFormat


def generate_key():
    """Generates an X25519 private and public key pair
    @return: A tuple containing the private key and public key
    """
    private = x25519.X25519PrivateKey.generate()
    public = private.public_key()
    return private, public


def save_key(key, output, encoding, fmt=None, password=None):
    """Saves the key to a file
    @param key: Private or public key object
    @param output: Key output file
    @param encoding: Defines key format PEM, DER, or JWK
    @param fmt: Key format
    @param password: Password to encrypt the key
    """
    dir_name = os.path.dirname(output)
    if dir_name:
        os.makedirs(dir_name, exist_ok=True)

    if encoding.upper() == 'PEM':
        _save_encoded(key, output, serialization.Encoding.PEM, fmt,
                      password=password)
    elif encoding.upper() == 'DER':
        _save_encoded(key, output, serialization.Encoding.DER, fmt,
                      password=password)
    elif encoding.upper() == 'JWK':
        raise ValueError(f"Incorrect encoding '{encoding}' with this key")
    else:
        raise ValueError(f"Invalid key encoding '{encoding}'")


def _save_encoded(key, output, encoding, fmt, password=None):
    if isinstance(key, x25519.X25519PrivateKey):
        if password:
            enc_alg = serialization.BestAvailableEncryption(password.encode())
        else:
            enc_alg = serialization.NoEncryption()
        if fmt:
            fmt = KeyFormat[fmt]
        else:
            fmt = serialization.PrivateFormat.PKCS8

        if not isinstance(fmt, serialization.PrivateFormat):
            raise ValueError(f"Invalid format for private key '{fmt}'")

        serialized = key.private_bytes(encoding=encoding, format=fmt,
                                       encryption_algorithm=enc_alg)
    elif isinstance(key, x25519.X25519PublicKey):
        if fmt:
            fmt = KeyFormat[fmt]
        else:
            fmt = serialization.PublicFormat.SubjectPublicKeyInfo

        if not isinstance(fmt, serialization.PublicFormat):
            raise ValueError(f"Invalid format for public key '{fmt}'")

        serialized = key.public_bytes(encoding=encoding, format=fmt)
    else:
        raise TypeError(f"Invalid key type '{type(key)}'")

    with open(output, 'wb') as fp:
        fp.write(serialized)
