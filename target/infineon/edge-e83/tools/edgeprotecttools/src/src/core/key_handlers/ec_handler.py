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
import hashlib

from jose.utils import long_to_base64
from cryptography.hazmat.primitives.asymmetric.utils import decode_dss_signature
from cryptography.hazmat.primitives.asymmetric import ec, utils
from cryptography.hazmat.primitives.asymmetric.ec import (
    EllipticCurvePublicKey, EllipticCurvePrivateKey
)
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.backends import default_backend

from .pem_key import PemKey
from . import load_private_key, load_public_key


class ECHandler:
    """Handles EC signature and parse key data operations"""

    @staticmethod
    def populate_public_key(
        pub: bytes,
        curve=ec.SECP256R1()
    ) -> EllipticCurvePublicKey:
        """ Generates an EC public key from the public numbers """
        if not isinstance(curve, (ec.SECP256R1, ec.SECP384R1, ec.SECP521R1)):
            raise TypeError(f"Unsupported curve '{type(curve)}'")
        pubkey = EllipticCurvePublicKey.from_encoded_point(curve, pub)
        return pubkey

    @staticmethod
    def populate_private_key(
        value: int,
        curve=ec.SECP256R1()
    ) -> EllipticCurvePrivateKey:
        """ Generates an EC private key from the private value """
        if not isinstance(curve, (ec.SECP256R1, ec.SECP384R1, ec.SECP521R1)):
            raise TypeError(f"Unsupported curve '{type(curve)}'")
        key = ec.derive_private_key(value, curve, default_backend())
        return key

    @staticmethod
    def public_jwk(pubkey, kid=None):
        """ Gets EC public key is JSON format """
        alg, crv, lth = ECHandler._jwk_alg(pubkey)
        key_json = {
            'alg': alg,
            'kty': 'EC',
            'crv': crv,
            'use': 'sig',
            'x': long_to_base64(pubkey.public_numbers().x, lth).decode('utf-8'),
            'y': long_to_base64(pubkey.public_numbers().y, lth).decode('utf-8')
        }
        if kid is not None:
            key_json['kid'] = str(kid)
        return key_json

    @staticmethod
    def public_pem(pub_key: EllipticCurvePublicKey):
        """Converts public key to PEM format"""
        return pub_key.public_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PublicFormat.SubjectPublicKeyInfo
        )

    @staticmethod
    def private_jwk(privkey, kid=None):
        """ Gets EC private key is JSON format """
        alg, crv, lth = ECHandler._jwk_alg(privkey)
        pubkey = privkey.public_key()
        key_json = {
            'alg': alg,
            'kty': 'EC',
            'crv': crv,
            'use': 'sig',
            'x': long_to_base64(pubkey.public_numbers().x, lth).decode('utf-8'),
            'y': long_to_base64(pubkey.public_numbers().y, lth).decode('utf-8'),
            'd': long_to_base64(
                privkey.private_numbers().private_value, lth).decode('utf-8'),
        }
        if kid:
            key_json['kid'] = str(kid)
        return key_json

    @staticmethod
    def private_pem(priv_key: EllipticCurvePrivateKey):
        """Converts private key to PEM format"""
        return priv_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.TraditionalOpenSSL,
            encryption_algorithm=serialization.NoEncryption()
        )

    @staticmethod
    def _jwk_alg(privkey):
        if isinstance(privkey.curve, ec.SECP256R1):
            alg = 'ES256'
            crv = 'P-256'
            lth = 32
        elif isinstance(privkey.curve, ec.SECP384R1):
            alg = 'ES384'
            crv = 'P-384'
            lth = 48
        elif isinstance(privkey.curve, ec.SECP521R1):
            alg = 'ES512'
            crv = 'P-521'
            lth = 66
        else:
            raise ValueError('Unsupported elliptic curve')
        return alg, crv, lth

    @staticmethod
    def alg(privkey):
        if isinstance(privkey.curve, ec.SECP256R1):
            alg = 'ES256'
        elif isinstance(privkey.curve, ec.SECP384R1):
            alg = 'ES384'
        elif isinstance(privkey.curve, ec.SECP521R1):
            alg = 'ES512'
        else:
            raise ValueError('Unsupported elliptic curve')
        return alg

    @staticmethod
    def public_bytes(pubkey: EllipticCurvePublicKey) -> bytes:
        """Encoding public key in DER format and return as byte sequence"""
        return pubkey.public_bytes(
            encoding=serialization.Encoding.DER,
            format=serialization.PublicFormat.SubjectPublicKeyInfo
        )

    @staticmethod
    def raw_format(key):
        """Returns public key in raw format"""
        try:
            pubkey = key.public_key()
        except AttributeError:
            pubkey = key

        raw = pubkey.public_bytes(
            encoding=serialization.Encoding.X962,
            format=serialization.PublicFormat.UncompressedPoint
        )
        return raw

    @staticmethod
    def is_private_key(key):
        """ Gets a value indicating whether the key is a private key """
        if isinstance(key, str):
            try:
                p_key = load_private_key(key)
            except ValueError:
                p_key = load_public_key(key)
        else:
            p_key = key

        if not isinstance(p_key, (EllipticCurvePrivateKey,
                                  EllipticCurvePublicKey)):
            raise ValueError("Using EC with unsupported key")

        return isinstance(p_key, EllipticCurvePrivateKey)

    @staticmethod
    def sign(key, message):
        """Signs a message with a key
        @param key: The key object or key path
        @param message: The message to sign
        @return: Signature
        """
        if not isinstance(key, EllipticCurvePrivateKey):
            key = load_private_key(key)

        if key.key_size == 256:
            hash_algorithm = hashes.SHA256()
        elif key.key_size == 384:
            hash_algorithm = hashes.SHA384()
        elif key.key_size == 521:
            hash_algorithm = hashes.SHA512()
        else:
            raise ValueError(f'Unsupported key length {key.key_size}')

        sig = key.sign(message, ec.ECDSA(hash_algorithm))
        return ECHandler.asn1_to_rs(sig, key.key_size)

    @staticmethod
    def sign_hash(key, message):
        """Signs a message hash"""
        if isinstance(key, EllipticCurvePrivateKey):
            private_key = key
        else:
            private_key = load_private_key(key)

        if key.key_size == 256:
            hashlib_algorithm = hashlib.sha256
            hash_algorithm = hashes.SHA256
        elif key.key_size == 384:
            hashlib_algorithm = hashlib.sha384
            hash_algorithm = hashes.SHA384
        elif key.key_size == 521:
            hashlib_algorithm = hashlib.sha512
            hash_algorithm = hashes.SHA512
        else:
            raise ValueError(f'Unsupported key length {key.key_size}')

        digest = hashlib_algorithm(message).digest()
        sig = private_key.sign(
            digest,
            signature_algorithm=ec.ECDSA(utils.Prehashed(hash_algorithm()))
        )
        return sig

    @staticmethod
    def jwk_to_pem(jwk_file, private_key=True):
        """Converts JWK file content to PEM format string"""
        pem = PemKey(jwk_file)
        pem_str = pem.to_str(private_key=private_key)
        return pem_str

    @staticmethod
    def asn1_to_rs(signature, key_size):
        """Converts ECDSA signature in ASN.1 format to R and S values"""
        r, s = decode_dss_signature(signature)
        values_size = key_size // 8 + (key_size % 8 > 0)
        return (r.to_bytes(values_size, byteorder='big'),
                s.to_bytes(values_size, byteorder='big'))
