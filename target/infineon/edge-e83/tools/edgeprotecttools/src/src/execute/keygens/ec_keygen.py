"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import json
import logging
from typing import Union

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import serialization

from ...core.enums import KeyFormat
from ...core.json_helper import read_json
from ...core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)

CurveTypes = Union[ec.SECP256R1, ec.SECP384R1, ec.SECP521R1]


def generate_key(curve: CurveTypes, template=None, byteorder="big"):
    """Creates either private or public key using ECDSA algorithm
    @param curve: Elliptic curve
    @param template: Path to JSON file containing key public numbers
    @param byteorder: Byte order of the private key value
    @return: Private key, public key
    """
    if template:
        try:
            data = read_json(template)
            public_key = ECHandler.populate_public_key(
                bytes.fromhex(data['pub']), curve=curve)
            private_key = None

        except UnicodeDecodeError as e:
            with open(template, 'rb') as f:
                data = f.read()

            if (isinstance(curve, ec.SECP256R1) and len(data) == 65) \
                or (isinstance(curve, ec.SECP384R1) and len(data) == 97) \
                    or (isinstance(curve, ec.SECP521R1) and len(data) == 133):
                public_key = ECHandler.populate_public_key(data, curve=curve)
                private_key = None
            elif (isinstance(curve, ec.SECP256R1) and len(data) == 32) \
                or (isinstance(curve, ec.SECP384R1) and len(data) == 48)\
                    or (isinstance(curve, ec.SECP521R1) and len(data) == 66):
                value = int.from_bytes(data, byteorder=byteorder)
                public_key = None
                private_key = ECHandler.populate_private_key(value, curve=curve)
            else:
                raise ValueError(f"Invalid file format '{template}'") from e

        except ValueError as e:
            raise ValueError(
                f'The template contains invalid data ({template})') from e

        except KeyError as e:
            raise KeyError(
                f'The template structure is invalid ({template})') from e

    else:
        if not isinstance(curve, (ec.SECP256R1, ec.SECP384R1, ec.SECP521R1)):
            raise TypeError(f"Unsupported curve '{type(curve)}'")

        private_key = ec.generate_private_key(curve, default_backend())
        public_key = private_key.public_key()

    return private_key, public_key


def save_key(key, output, encoding, fmt=None, kid=None, password=None):
    """Saves the key to the file
    @param key: Private or public key object
    @param output: Key output path
    @param encoding: Defines key format PEM, DER, or JWK
    @param fmt: Defines key format
    @param kid: Customer key ID
    @param password: Password for the private key encryption
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
        _save_jwk(key, output, kid=kid)
    else:
        raise ValueError(f"Invalid key encoding '{encoding}'")


def _save_jwk(key, output, kid=None):
    if isinstance(key, ec.EllipticCurvePrivateKey):
        jwk = ECHandler.private_jwk(key, kid)
    elif isinstance(key, ec.EllipticCurvePublicKey):
        jwk = ECHandler.public_jwk(key, kid)
    else:
        raise TypeError(f"Invalid key type '{type(key)}'")

    with open(output, 'w', encoding='utf-8') as fp:
        fp.write(json.dumps(jwk, indent=4))


def _save_encoded(key, output, encoding, fmt, password=None):
    if isinstance(key, ec.EllipticCurvePrivateKey):
        if password:
            enc_alg = serialization.BestAvailableEncryption(password.encode())
        else:
            enc_alg = serialization.NoEncryption()
        if fmt:
            fmt = KeyFormat[fmt]
        else:
            fmt = serialization.PrivateFormat.TraditionalOpenSSL

        if not isinstance(fmt, serialization.PrivateFormat):
            raise ValueError(f"Invalid format for private key '{fmt}'")

        serialized = key.private_bytes(encoding=encoding, format=fmt,
                                       encryption_algorithm=enc_alg)
    elif isinstance(key, ec.EllipticCurvePublicKey):
        if fmt:
            fmt = KeyFormat[fmt]
        else:
            fmt = serialization.PublicFormat.SubjectPublicKeyInfo

        if not isinstance(fmt, serialization.PublicFormat):
            raise ValueError(f"Invalid format for public key '{fmt}'")

        serialized = key.public_bytes(encoding=encoding, format=fmt)
    else:
        if fmt:
            fmt = KeyFormat[fmt]
        else:
            fmt = serialization.PublicFormat.SubjectPublicKeyInfo

        if not isinstance(fmt, serialization.PublicFormat):
            raise ValueError(f"Invalid format for public key '{fmt}'")

        pubkey = key.public_key()
        serialized = pubkey.public_bytes(encoding=encoding, format=fmt)

    with open(output, 'wb') as fp:
        fp.write(serialized)
