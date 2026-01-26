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
from cryptography.hazmat.primitives.asymmetric import ec, rsa

from ..core.enums import KeyAlgorithm
from ..core.key_handlers import load_private_key, load_public_key, load_key


class KeyValidator:
    """Key validator base class"""

    key_algorithms = (
            KeyAlgorithm.ECDSA_P256,
            KeyAlgorithm.ECDSA_P384,
            KeyAlgorithm.ECDSA_P521,
            KeyAlgorithm.RSA2048, KeyAlgorithm.RSA3072, KeyAlgorithm.RSA4096,
            KeyAlgorithm.AES128, KeyAlgorithm.AES256
        )

    def validate(self, key, **kwargs):
        """Checks whether the key has a valid format and
        matches one of the supported keys for the target
        @param key: Path to the key
        @raise ValueError: If the key has an invalid format or does not
        match any of the supported key types
        """
        return self._validate_alg(key, **kwargs)

    def validate_private_key(self, key_path, **kwargs):
        """Checks whether the private key has a valid format and
        matches one of the supported keys for the target
        @param key_path: Path to the private key
        @raise ValueError: If the key has an invalid format or does not
        match any of the supported key types
        """
        try:
            key = load_private_key(key_path)
        except ValueError as e:
            raise ValueError(
                'A key may be in an incorrect format '
                'or it may be an unsupported key type' +
                self._supported_key_types_msg()) from e

        if not isinstance(key, (ec.EllipticCurvePrivateKey, rsa.RSAPrivateKey))\
                or not self.validate(key, **kwargs):
            raise ValueError(
                'A key may be in an incorrect format '
                'or it may be an unsupported key type')

    def validate_public_key(self, key_path, **kwargs):
        """Checks whether the private key has a valid format and
        matches one of the supported keys for the target
        @param key_path: Path to the private key
        @raise ValueError: If the key has an invalid format or does not
        match any of the supported key types
        """
        try:
            key = load_public_key(key_path)
        except ValueError as e:
            raise ValueError(
                'A key may be in an incorrect format '
                'or it may be an unsupported key type' +
                self._supported_key_types_msg()) from e

        if not isinstance(key, (ec.EllipticCurvePublicKey, rsa.RSAPublicKey))\
                or not self.validate(key, **kwargs):
            raise ValueError(
                'A key may be in an incorrect format '
                'or it may be an unsupported key type')

    @staticmethod
    def algorithm_by_key(key):
        """Returns key algorithm
        @param key: Key or path to the key
        @raise ValueError: If the key has an invalid format or does not
        match any of the supported key types
        @return: Key algorithm
        """
        if isinstance(key, str):
            try:
                key = load_key(key)
            except ValueError:
                with open(key, 'rb') as f:
                    key = f.read()

        getters = [
            KeyValidator._ec_algorithm_by_key,
            KeyValidator._rsa_algorithm_by_key,
            KeyValidator._aes_algorithm_by_key
        ]

        for getter in getters:
            alg = getter(key)
            if alg:
                return alg

        raise ValueError('Unsupported key type')

    def _validate_alg(self, key_path, **_kwargs):
        try:
            alg = KeyValidator.algorithm_by_key(key_path)
        except ValueError as e:
            raise ValueError(str(e) + self._supported_key_types_msg()) from e
        if alg not in self.key_algorithms:
            return False

        return True

    @staticmethod
    def _ec_algorithm_by_key(key):
        algorithms = {
            ec.SECP256R1.name: KeyAlgorithm.ECDSA_P256,
            ec.SECP384R1.name: KeyAlgorithm.ECDSA_P384,
            ec.SECP521R1.name: KeyAlgorithm.ECDSA_P521
        }
        if isinstance(
                key, (ec.EllipticCurvePrivateKey, ec.EllipticCurvePublicKey)
        ):
            return algorithms.get(key.curve.name)
        return None

    @staticmethod
    def _rsa_algorithm_by_key(key):
        algorithms = {
            2048: KeyAlgorithm.RSA2048,
            3072: KeyAlgorithm.RSA3072,
            4096: KeyAlgorithm.RSA4096
        }
        if isinstance(
                key, (rsa.RSAPrivateKey, rsa.RSAPublicKey)
        ):
            return algorithms.get(key.key_size)
        return None

    @staticmethod
    def _aes_algorithm_by_key(key):
        algorithms = {
            16: KeyAlgorithm.AES128,
            32: KeyAlgorithm.AES256
        }
        if isinstance(
                key, bytes
        ):
            return algorithms.get(len(key))
        return None

    def _supported_key_types_msg(self):
        supported = list(self.key_algorithms)
        return f'. Supported types: {", ".join(supported)}'
