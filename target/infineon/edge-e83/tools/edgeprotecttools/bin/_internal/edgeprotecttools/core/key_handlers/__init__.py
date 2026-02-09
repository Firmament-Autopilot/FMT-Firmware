"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import ec, rsa, x25519
from cryptography.hazmat.primitives.serialization import (
    load_der_private_key,
    load_pem_private_key,
    load_der_public_key,
    load_pem_public_key
)

from .pem_key import PemKey
from ..enums import KeyFormat, KeyEncoding


def load_private_key(key_path, password=None):
    """Loads private key any of the following formats: JWK, PEM, DER"""
    password = password.encode() if password else None
    try:
        with open(key_path, 'r', encoding='utf-8') as f:
            data = f.read()
    except UnicodeDecodeError:
        with open(key_path, 'rb') as f:
            der_data = f.read()
        key = load_der_private_key(der_data, password=password)
    else:
        try:
            json.loads(data)
        except json.decoder.JSONDecodeError:
            key = load_pem_private_key(data.encode(), password=password)
        else:
            pem_data = jwk_to_pem(key_path, private_key=True)
            key = load_pem_private_key(pem_data, password=password)
    return key


def load_public_key(key_path):
    """Loads public key any of the following formats: JWK, PEM, DER"""
    try:
        with open(key_path, 'r', encoding='utf-8') as f:
            data = f.read()
    except UnicodeDecodeError:
        with open(key_path, 'rb') as f:
            der_data = f.read()
        key = load_der_public_key(der_data)
    else:
        try:
            json.loads(data)
        except json.decoder.JSONDecodeError:
            key = load_pem_public_key(data.encode())
        else:
            pem_data = jwk_to_pem(key_path, private_key=False)
            key = load_pem_public_key(pem_data)
    return key


def load_key(key_path, password=None):
    """Loads either private or public key of the one of
    the following formats: JWK, PEM, DER
    """
    try:
        key = load_private_key(key_path, password=password)
    except ValueError:
        try:
            key = load_public_key(key_path)
        except ValueError as e:
            raise ValueError(f"Failed to open the key '{key_path}'. "
                             f"The data may be in an incorrect format") from e
    return key


def load_enckey(key) -> bytes:
    """Loads encryption key from a file or a hex string"""
    def _is_hex_string(value, lengths=None) -> bool:
        """Validate hex string"""
        if not (all(c.lower() in '0123456789abcdef' for c in value)
                and len(value) % 2 == 0):
            return False
        if lengths is not None and len(value) // 2 not in lengths:
            raise ValueError(
                f"Invalid key length. Expected: {', '.join(lengths)}")
        return True

    if _is_hex_string(key, lengths=[16, 32]):
        return bytes.fromhex(key)
    else:
        with open(key, 'rb') as f:
            return f.read()


def jwk_to_pem(jwk_file, private_key=True):
    """Converts JWK file content to PEM format string"""
    pem = PemKey(jwk_file)
    pem_str = pem.to_str(private_key=private_key)
    return pem_str


def emit_c(key, key_format, password=None, var_name=None):
    """Saves private or public key in C-array format
    @param key: Key object
    @param key_format: Key format
    @param password: Password for the private key encryption
    @param var_name: C array variable name
    """
    var_names = {
        ec.EllipticCurvePrivateKey: 'ecdsa_priv_key',
        ec.EllipticCurvePublicKey: 'ecdsa_pub_key',
        rsa.RSAPrivateKey: 'rsa_priv_key',
        rsa.RSAPublicKey: 'rsa_pub_key',
        x25519.X25519PrivateKey: 'x25519_priv_key',
        x25519.X25519PublicKey: 'x25519_pub_key'
    }

    try:
        default_var_name = [
            n for t, n in var_names.items() if isinstance(key, t)][0]
    except IndexError as e:
        raise TypeError(f"Unsupported key type '{type(key)}'") from e

    if isinstance(key, (ec.EllipticCurvePrivateKey,
                        rsa.RSAPrivateKey,
                        x25519.X25519PrivateKey)):
        if password:
            enc_alg = serialization.BestAvailableEncryption(password.encode())
        else:
            enc_alg = serialization.NoEncryption()
        if key_format:
            key_format = KeyFormat[key_format]
        else:
            key_format = serialization.PrivateFormat.PKCS8
        if not isinstance(key_format, serialization.PrivateFormat):
            raise ValueError(f"Invalid format for private key '{key_format}'")

        encoded_bytes = key.private_bytes(
            encoding=serialization.Encoding.DER,
            format=key_format,
            encryption_algorithm=enc_alg
        )
    elif isinstance(key, (ec.EllipticCurvePublicKey, x25519.X25519PublicKey)):
        if key_format:
            key_format = KeyFormat[key_format]
        else:
            key_format = serialization.PublicFormat.SubjectPublicKeyInfo
        if not isinstance(key_format, serialization.PublicFormat):
            raise ValueError(f"Invalid format for public key '{key_format}'")
        encoded_bytes = key.public_bytes(encoding=serialization.Encoding.DER,
                                         format=key_format)
    elif isinstance(key, rsa.RSAPublicKey):
        if key_format:
            key_format = KeyFormat[key_format]
        else:
            key_format = serialization.PublicFormat.PKCS1
        if not isinstance(key_format, serialization.PublicFormat):
            raise ValueError(f"Invalid format for public key '{key_format}'")
        encoded_bytes = key.public_bytes(encoding=serialization.Encoding.DER,
                                         format=key_format)
    else:
        raise ValueError('Serialization of unsupported key')

    result = c_array_str(
        encoded_bytes, var_name if var_name else default_var_name)
    return result


def c_array_str(encoded_bytes, array_name):
    autogen_message = "/* Autogenerated by imgtool.py, do not edit. */"
    header = f"const unsigned char {array_name}[] = {{"
    trailer = "};"
    indent = "    "
    len_format = f"const unsigned int {array_name}_len" \
                 f" = {len(encoded_bytes)};"
    result = ""
    result += autogen_message + "\n"
    result += header
    for count, encoded_byte in enumerate(encoded_bytes):
        if count % 8 == 0:
            result += "\n" + indent
        else:
            result += " "
        result += f"{encoded_byte:#04x}" \
                  f"{'' if count + 1 == len(encoded_bytes) else ','}"
    result += "\n" + trailer + "\n"
    result += len_format + "\n"
    return result


def key_encoding_and_format(fmt):
    """Parses key encoding and format from the given string
    @param fmt: Key encoding and format separated by a dash
    @return: Tuple of key encoding and key format
    """
    if '-' in fmt:
        key_encoding, key_format = fmt.upper().split('-')
    else:
        key_encoding = fmt.upper()
        key_format = None

    try:
        KeyEncoding[key_encoding]
    except KeyError as e:
        raise ValueError(f"Invalid key encoding '{key_encoding}'") from e

    if key_format is not None:
        try:
            KeyFormat[key_format]
        except KeyError as e:
            raise ValueError(f"Invalid key format '{key_format}'") from e

    return key_encoding, key_format
