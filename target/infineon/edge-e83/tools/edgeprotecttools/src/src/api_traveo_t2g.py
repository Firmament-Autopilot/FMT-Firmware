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
import logging
import os

from cryptography.hazmat.primitives.asymmetric import ec

from .api_common import CommonAPI
from .core.enums import KeyAlgorithm, KeyPair
from .execute.keygens import rsa_keygen, ec_keygen

logger = logging.getLogger(__name__)


class TraveoT2GAPI(CommonAPI):
    """A class containing API for Traveo T2G platform"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def create_keys(self, output, alg, fmt, overwrite=None): # pylint: disable=arguments-differ, arguments-renamed
        """Creates RSA and EC keys
        @param output: Output paths the generated keys
        @param alg: User key type
        @param fmt: Output key format (PEM, DER, JWK)
        @param overwrite: Indicates whether overwrite keys in the
               specified paths if they already exist. If the value
               is None, a prompt will ask whether to overwrite
               existing keys
        @return: True if key(s) created successfully, otherwise False.
        """
        if alg not in self.target.key_algorithms:
            valid_types = ",".join(self.target.key_algorithms)
            raise ValueError(
                f"Invalid key type '{alg}'. Supported key types for "
                f"the selected target: '{valid_types}'")

        key_param = self.__key_param(alg)

        if not overwrite:
            keys_exist = False
            for key_path in output:
                if os.path.isfile(key_path):
                    keys_exist = True
                    break

            if keys_exist:
                if overwrite is None:
                    if self.skip_prompts:
                        logger.info('Keys already exist. Skip creating keys')
                        return True

                    answer = input('Key paths are not empty. '
                                   'Overwrite? (y/n): ')
                    while answer.lower() != 'y' and answer.lower() != 'n':
                        answer = input("Please use 'y' or 'n'")
                    if answer.lower() != 'y':
                        logger.info('Terminated by user')
                        return True

                elif overwrite is False:
                    logger.info('Keys already exist. Skip creating keys')
                    return True

        # Generate keys
        keys = KeyPair(output[0], output[1])

        if alg in (KeyAlgorithm.RSA2048,
                   KeyAlgorithm.RSA3072,
                   KeyAlgorithm.RSA4096):
            private_key, public_key = rsa_keygen.generate_key(key_param)
            rsa_keygen.save_key(private_key, keys.private, fmt)
            logger.info("Created a key '%s'", os.path.abspath(keys.private))
            rsa_keygen.save_key(public_key, keys.public, fmt)
            logger.info("Created a key '%s'", os.path.abspath(keys.public))
        elif alg == KeyAlgorithm.ECDSA_P256:
            private_key, public_key = ec_keygen.generate_key(key_param)
            ec_keygen.save_key(private_key, keys.private, fmt)
            logger.info("Created a key '%s'", os.path.abspath(keys.private))
            ec_keygen.save_key(public_key, keys.public, fmt)
            logger.info("Created a key '%s'", os.path.abspath(keys.public))

        return True

    def sign_cysaf(self, image, **kwargs):
        """Signs application image in CySAF format
        @param image: Path to image in hex or bin format
        @param kwargs:
            :key_path: Path to RSA private key of length 2048, 3072 or 4096
            :output: Output path for signed image
        """
        self.target.sign_tool.sign_cysaf(image, **kwargs)

    @staticmethod
    def __key_param(key_type):
        if key_type == 'RSA2048':
            param = 2048
        elif key_type == 'RSA3072':
            param = 3072
        elif key_type == 'RSA4096':
            param = 4096
        elif key_type == 'ECDSA-P256':
            param = ec.SECP256R1()
        else:
            raise ValueError(f"Invalid key type '{key_type}'")
        return param
