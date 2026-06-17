"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .encryptor_aes import EncryptorAES
from ...execute.imgtool.custom_encryptor import CustomEncryptor

logger = logging.getLogger(__name__)


class XipEncryptor(CustomEncryptor):
    """Custom encryption for XIP"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._initial_counter = None
        self._nonce = None
        self._plainkey = None
        self._nonce_output = None

        if kwargs.get('initial_counter'):
            self.initial_counter = kwargs.get('initial_counter')

        if kwargs.get('nonce'):
            self.nonce = kwargs.get('nonce')

        if kwargs.get('plainkey'):
            self.plainkey = kwargs.get('plainkey')

        if kwargs.get('nonce_output'):
            self.nonce_output = kwargs.get('nonce_output')

    @property
    def initial_counter(self):
        if not self._initial_counter:
            raise ValueError("Initialization vector not specified")
        return self._initial_counter

    @initial_counter.setter
    def initial_counter(self, value):
        try:
            self._initial_counter = int(str(value), 0)
        except ValueError as exc:
            logger.info('Initialization vector must be equal to '
                        'the application base address')
            logger.error("Invalid initialization vector value '%s'", value)
            raise exc

    @property
    def nonce(self):
        if not self._nonce:
            raise ValueError("Nonce value not specified")
        return self._nonce

    @nonce.setter
    def nonce(self, value):
        try:
            self._nonce = self._nonce_value(value)
        except ValueError as exc:
            logger.error('Non-hexadecimal number specified')
            raise exc

    @property
    def plainkey(self):
        if not self._plainkey:
            raise ValueError("Encryption key not specified")
        return self._plainkey

    @plainkey.setter
    def plainkey(self, value):
        if not value:
            raise ValueError("Encryption key not specified")

        if isinstance(value, str):
            with open(value, 'rb') as f:
                self._plainkey = f.read()
        elif isinstance(value, bytes):
            self._plainkey = value
        else:
            raise ValueError(f"Invalid encryption key value '{value}'")

    @property
    def nonce_output(self):
        return self._nonce_output

    @nonce_output.setter
    def nonce_output(self, value):
        self._nonce_output = value

    @staticmethod
    def _nonce_value(nonce):
        """Gets nonce bytes from hex string or file"""
        if not nonce:
            raise ValueError('Nonce value is empty')
        if isinstance(nonce, bytes):
            nonce_val = nonce
        elif os.path.isfile(nonce):
            with open(nonce, 'rb') as f:
                nonce_val = f.read()
        else:
            nonce_val = bytes.fromhex(
                nonce.zfill(EncryptorAES.xip_nonce_size * 2)
            )
        return nonce_val

    def save_nonce(self):
        """Saves nonce to file"""

        path = os.path.abspath(self.nonce_output)

        with open(path, 'wb') as f:
            f.write(self.nonce[:12])

        logger.debug(
            'Nonce generated while encrypting this image '
            'for SMIF XIP on-the-fly decryption mode '
            'is saved to "%s".', path
        )

        logger.debug(
            'This nonce should be used with '
            '--nonce %s flag of '
            'encrypt-aes command for encryption of all other images '
            'placed along with this one.', path
        )

        logger.info(
            "The generated nonce saved to '%s'", path
        )

        logger.info(
            'ATTENTION! Make sure this nonce '
            'is used to encrypt all other images'
        )

    def encrypt(self, image, **kwargs) -> bytes:
        ciphertext = EncryptorAES.encrypt_ecb(
            image,
            self.plainkey,
            self.initial_counter,
            self.nonce
        )

        if self.nonce_output:
            self.save_nonce()

        return ciphertext
