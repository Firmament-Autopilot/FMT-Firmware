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
from typing import Union

from cryptography.hazmat.primitives.asymmetric.rsa import (
    RSAPublicKey, RSAPrivateKey)
from cryptography.hazmat.primitives.asymmetric.ec import (
    EllipticCurvePublicKey, EllipticCurvePrivateKey
)
from cryptography.hazmat.primitives import serialization

from .psa_constants import PsaKeyTypes, PsaKeyLifetime
from .asset_enums import KeyUsage, KeyAlgorithm
from ....core.key_handlers import load_public_key, load_private_key
from ....core.bitops import number_size
from ....core.key_handlers.ec_handler import ECHandler

KeyTypes = Union[
    EllipticCurvePrivateKey,
    EllipticCurvePublicKey,
    RSAPrivateKey,
    RSAPublicKey,
    bytes
]

KID_ID = 0x30010001
KTY_ID = 0x30010002
ALG_ID = 0x30010003
USE_ID = 0x30010004
KEY_DATA_ID = 0x30010005
KEY_OWNER_ID = 0x30010006
KEY_BITS_ID = 0x30010007


class CustomKeysPacket:
    """OEM custom key packet creator"""

    @staticmethod
    def create(key_data_list) -> list:
        """Creates a CBOR packet containing an array with OEM custom key
        data needed for the PSA key import function
        @param key_data_list: A list of key data from the policy
        oem_custom_keys section
        @return: CBOR packet
        """
        cbor_data = []
        for data in key_data_list:
            key = CustomKeysPacket.load_key(data['key']['value'])
            kid = CustomKeysPacket.key_id(data['kid']['value'])
            alg = CustomKeysPacket.key_algorithm(data['alg']['value'])
            use = CustomKeysPacket.key_usage(data['use']['value'])
            if data.get('kty') and data['kty'].get('value'):
                kty = CustomKeysPacket.key_type(key, data['kty']['value'])
            else:
                kty = CustomKeysPacket.key_type_auto(key, data['alg']['value'])
            kda = CustomKeysPacket.key_data(key)
            kbt = CustomKeysPacket.key_bits(key)
            user_key = {
                KID_ID: kid,
                KTY_ID: kty,
                ALG_ID: alg,
                USE_ID: use,
                KEY_DATA_ID: kda,
                KEY_BITS_ID: kbt
            }

            if data.get('owner') and data['owner'].get('value') is not None:
                kwn = CustomKeysPacket.key_owner(data['owner']['value'])
                user_key.update({KEY_OWNER_ID: kwn})
            cbor_data.append(user_key)
        return cbor_data

    @staticmethod
    def key_lifetime(lifetime: str) -> int:
        """Gets key lifetime value for PSA import"""
        lifetime = lifetime.upper().strip()
        try:
            return PsaKeyLifetime[lifetime].value
        except KeyError as e:
            raise ValueError(f"Unknown key lifetime '{lifetime}'") from e

    @staticmethod
    def key_id(kid: Union[int, str]) -> int:
        """Sanitizes and validates key ID value"""
        try:
            return int(str(kid), 0)
        except ValueError as e:
            raise ValueError(f"Non-numeric key ID value '{str(kid)}'") from e

    @staticmethod
    def key_algorithm(alg: str) -> int:
        """Gets key algorithm value for PSA import"""
        alg = alg.upper().strip()
        try:
            return KeyAlgorithm[alg].value
        except KeyError as e:
            raise ValueError(f"Unknown key algorithm '{alg}'") from e

    @staticmethod
    def key_usage(use: str) -> int:
        """Gets key usage value for PSA import"""
        usages = use.split('|')
        psa_value = 0
        for usage in usages:
            usage = usage.upper().strip()
            try:
                psa_value |= KeyUsage[usage].value
            except KeyError as e:
                raise ValueError(f"Unknown key usage '{usage}'") from e
        return psa_value

    @staticmethod
    def key_type(key: KeyTypes, kty: str = None) -> int:
        """Gets key type value for PSA import"""
        kty_map = {
            'DERIVE': PsaKeyTypes.DERIVE,
            'NONE': PsaKeyTypes.RAW_DATA,
            'ECC_KEY_PAIR': PsaKeyTypes.ECC_KEY_PAIR,
            'ECC_PUBLIC_KEY': PsaKeyTypes.ECC_PUBLIC_KEY,
            'RSA_KEY_PAIR': PsaKeyTypes.RSA_KEY_PAIR,
            'RSA_PUBLIC_KEY': PsaKeyTypes.RSA_PUBLIC_KEY,
            'AES': PsaKeyTypes.AES,
            'AES-CTR': PsaKeyTypes.AES,
            'AES-CBC': PsaKeyTypes.AES,
            'AES-ECB': PsaKeyTypes.AES
        }

        if kty not in kty_map:
            raise ValueError(f'Invalid key type: "{kty}"')

        if key and kty in ('ECC_KEY_PAIR', 'ECC_PUBLIC_KEY',
                           'RSA_KEY_PAIR', 'RSA_PUBLIC_KEY'):
            CustomKeysPacket._verify_asymmetric_key_size(key)

        return kty_map[kty]

    @staticmethod
    def key_type_auto(key: KeyTypes, alg: str = None) -> int:
        """Gets key type value for PSA import"""
        if key:
            CustomKeysPacket._verify_asymmetric_key_size(key)
            if isinstance(key, EllipticCurvePrivateKey):
                return PsaKeyTypes.ECC_KEY_PAIR
            if isinstance(key, EllipticCurvePublicKey):
                return PsaKeyTypes.ECC_PUBLIC_KEY
            if isinstance(key, RSAPrivateKey):
                return PsaKeyTypes.RSA_KEY_PAIR
            if isinstance(key, RSAPublicKey):
                return PsaKeyTypes.RSA_PUBLIC_KEY

        if not alg:
            raise ValueError('Algorithm is required for the selected key')
        if alg in ('AES-CTR', 'AES-CBC', 'AES-ECB'):
            return PsaKeyTypes.AES
        if alg == 'NONE':
            return PsaKeyTypes.RAW_DATA
        raise ValueError('Invalid key type')

    @staticmethod
    def key_type_field(psa_key_type: str) -> int:
        """Gets type value for PSA key attribute"""
        if psa_key_type in ('AES', 'ECC_PUBLIC_KEY'):
            return PsaKeyTypes[psa_key_type].value
        raise ValueError('Invalid key type')

    @staticmethod
    def key_data(key: KeyTypes) -> bytes:
        """Gets key data in the format supported by PSA import"""
        if isinstance(key, EllipticCurvePrivateKey):
            priv_nums = key.private_numbers()
            return priv_nums.private_value.to_bytes(
                length=number_size(priv_nums.private_value), byteorder='big')
        if isinstance(key, EllipticCurvePublicKey):
            return ECHandler.raw_format(key)
        if isinstance(key, RSAPrivateKey):
            return key.private_bytes(
                serialization.Encoding.DER,
                serialization.PrivateFormat.TraditionalOpenSSL,
                serialization.NoEncryption()
            )
        if isinstance(key, RSAPublicKey):
            return key.public_bytes(
                serialization.Encoding.DER,
                serialization.PublicFormat.PKCS1
            )
        return key

    @staticmethod
    def key_bits(key: KeyTypes) -> int:
        """Gets key data in the format supported by PSA import"""
        if isinstance(key, (EllipticCurvePrivateKey, EllipticCurvePublicKey)):
            return key.curve.key_size
        if isinstance(key, (RSAPrivateKey, RSAPublicKey)):
            return key.key_size
        if isinstance(key, bytes):
            return len(key) * 8
        raise ValueError(f'Unsupported key type "{type(key)}"')

    @staticmethod
    def key_owner(owner: Union[int, str]):
        """Gets key owner identifier data"""
        return int(str(owner), 0)

    @staticmethod
    def load_key(key_path: str) -> KeyTypes:
        """Loads a key from file"""
        try:
            key = load_private_key(key_path)
        except ValueError:
            try:
                key = load_public_key(key_path)
            except ValueError:
                with open(key_path, 'rb') as f:
                    key = f.read()
        return key

    @staticmethod
    def _verify_asymmetric_key_size(key: KeyTypes) -> None:
        if isinstance(key, (EllipticCurvePrivateKey, EllipticCurvePublicKey)):
            if key.key_size not in (256, 384, 521):
                raise ValueError(f'Unsupported key size {key.key_size}')
        if isinstance(key, (RSAPrivateKey, RSAPublicKey)):
            if key.key_size not in (1024, 2048, 3072, 4096):
                raise ValueError(f'Unsupported key size {key.key_size}')
