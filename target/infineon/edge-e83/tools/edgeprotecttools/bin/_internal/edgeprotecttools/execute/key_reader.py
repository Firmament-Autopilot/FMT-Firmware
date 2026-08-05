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
import json
import logging

from jose import jwk, exceptions
from jose.constants import ALGORITHMS
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization

logger = logging.getLogger(__name__)


def load_key(key):
    """
    Load JWK for certificate signing.
    :param key: File that contains the key.
    :return: Tuple - private key, public key
    """
    priv_key = None
    pub_key = None

    with open(key, 'r', encoding='utf-8') as f:
        key_str = f.read()

    key_json = json.loads(key_str)
    combined = False
    for item in key_json:
        if 'priv_key' in item or 'pub_key' in item:
            combined = True
            break

    if not combined:
        try:
            is_private = 'd' in key_json
            if is_private:
                if 'alg' in key_json:
                    priv_key_obj = jwk.construct(key_json)
                else:
                    priv_key_obj = jwk.construct(key_json, ALGORITHMS.ES256)
                pub_key_obj = priv_key_obj.public_key()
                priv_key = key_json
                pub_key = pub_key_obj.to_dict()
                # Jose ignores 'kid' and 'use' fields in JWK, so
                # copy them from private key
                if 'kid' not in pub_key and 'kid' in priv_key:
                    pub_key['kid'] = priv_key['kid']
                if 'use' not in pub_key and 'use' in priv_key:
                    pub_key['use'] = priv_key['use']
                # Jose represents key tokens as bytes, so convert bytes to str
                for k, v in pub_key.items():
                    if isinstance(v, bytes):
                        pub_key[k] = v.decode('utf-8')
            else:
                priv_key = None
                pub_key = key_json
        except exceptions.JWKError:
            logger.error('Failed to load key %s', key)
            priv_key = None
            pub_key = None
    else:
        # Input file may be JSON combined from private and public key
        for item in key_json:
            if 'priv_key' in item:
                priv_key = key_json[item]
                break
        for item in key_json:
            if 'pub_key' in item:
                pub_key = key_json[item]
                break

        # Input file does not contain JWK
        if not priv_key:
            raise ValueError(f'Private key not found in {key}')
        if not pub_key:
            if priv_key:
                pub_key = priv_key
                del pub_key["d"]
            else:
                raise ValueError(f'Public key not found in {key}')

    return priv_key, pub_key


def is_private_key(path):
    with open(path, 'rb') as f:
        raw_pem = f.read()
    try:
        serialization.load_pem_private_key(
            raw_pem, password=None, backend=default_backend())
        return True
    except ValueError:
        serialization.load_pem_public_key(raw_pem, backend=default_backend())
        return False
