"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .command import Command
from ....execute.encryption import EncryptorAES, XipEncryptor


logger = logging.getLogger(__name__)


class CommandEncryptAes(Command):
    """Encrypt-aes command implementation"""

    args_map = {
        'cmd_name': 'command',
        'input': 'file',
        'key': 'key',
        'output': 'file',
        'iv': 'iv',
        'nonce': 'nonce',
        'add_iv': 'add-iv',
        'iv_output': 'iv-output',
        'cipher_mode': 'cipher-mode',
        'description': 'description'
    }

    schema = 'encrypt_aes_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._input = self.get_arg(self._inputs, 'input')
        self._key = self.get_arg(self._inputs, 'key')
        self._iv = self.get_arg(self._inputs, 'iv')
        self._nonce = self.get_arg(self._inputs, 'nonce')
        self._add_iv = self.get_arg(self._inputs, 'add_iv')
        self._cipher_mode = self.get_arg(self._inputs, 'cipher_mode')

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')
        self._iv_output = self.get_arg(outputs, 'iv_output')

    @property
    def input(self):
        return self._input

    @property
    def output(self):
        return self._output

    @property
    def key(self):
        return self._key

    @property
    def iv(self):
        return self._iv

    @iv.setter
    def iv(self, value):
        self._iv = value

    @property
    def nonce(self):
        return self._nonce

    @property
    def add_iv(self):
        return self._add_iv

    @property
    def iv_output(self):
        return self._iv_output

    @property
    def cipher_mode(self):
        return self._cipher_mode

    def validate_args(self) -> bool:
        """Validation of encrypt-aes command arguments"""

        if not self._is_file(self.input):
            return False

        if not self._is_file(self.key):
            return False

        if not self._validate_nonce():
            return False

        if not self._validate_iv():
            return False

        return True

    def execute(self) -> bool:
        """Executes the encrypt-aes command"""
        iv = self._parse_iv()
        payload = self._parse_payload()
        key = self._parse_key()

        if self.cipher_mode == 'ECB':
            encryptor = XipEncryptor(
                initial_counter=iv, nonce=self.nonce, plainkey=key
            )
            encrypted = encryptor.encrypt(payload)
        else:
            encrypted = EncryptorAES.encrypt(payload, key, iv, self.cipher_mode)
        del key

        with open(self.output, 'wb') as f:
            f.write(iv + encrypted if self.add_iv else encrypted)

        logger.info("Saved encrypted file to '%s'",
                    os.path.abspath(self.output))

        if self.iv_output:
            with open(self.iv_output, 'wb') as f:
                f.write(iv)
            logger.info("Saved IV to '%s'", os.path.abspath(self.iv_output))
        return True

    def _parse_iv(self) -> bytes:
        """Parse initialization vector"""
        if self.iv.lower() == 'auto':
            iv = os.urandom(16)
        elif self._is_hex_string(self.iv):
            iv = bytes.fromhex(self.iv)
        elif self._is_hex_number(self.iv):
            if self.cipher_mode == 'ECB':
                iv = int(str(self.iv), 0)
            else:
                iv = bytes.fromhex(self.iv[2:])
        else:
            with open(self.iv, 'rb') as f:
                iv = f.read()
        return iv

    def _parse_payload(self) -> bytes:
        """Parse payload"""
        with open(self.input, 'rb') as f:
            return f.read()

    def _parse_key(self) -> bytes:
        """Parse key"""
        with open(self.key, 'rb') as f:
            return f.read()

    def _validate_nonce(self):
        """Validate nonce"""
        if self.nonce:
            if self.cipher_mode != 'ECB':
                logger.error('Nonce is only supported for ECB mode')
                return False

            if not (self._is_file(self.nonce, log=False, length=12)
                    or self._is_hex_string(self.nonce, length=12)):
                logger.error(
                    'Invalid nonce value. '
                    'Expected: path to a binary file or hexadecimal string '
                    'of 12 bytes'
                )
                return False
        return True

    def _validate_iv(self):
        """Validate IV"""
        if not self.iv:
            logger.error('Specifying of IV is required')
            return False

        if self.cipher_mode == 'ECB' and self.iv.lower() == 'auto':
            logger.error('Auto IV generation is not supported for ECB mode')
            return False

        if self.iv.lower() != 'auto':
            if self.cipher_mode == 'ECB':
                if not self._is_hex_number(self.iv):
                    logger.error(
                        'Invalid IV for ECB mode. Expected: hexadecimal number'
                    )
                    return False
            elif not (self._is_file(self.iv, log=False, length=16)
                      or self._is_hex_string(self.iv, length=16)
                      or self._is_hex_number(self.iv, length=16)):
                logger.error(
                    'Invalid IV value. '
                    'Expected: path to a binary file, hexadecimal number '
                    'or hexadecimal string of 16 bytes'
                )
                return False
        return True

    @staticmethod
    def _is_file(file_path, log=True, length=None) -> bool:
        """Validate file"""
        if not os.path.isfile(file_path):
            if log:
                logger.error("File not found: '%s'", os.path.abspath(file_path))
            return False
        if length is not None:
            with open(file_path, 'rb') as f:
                return len(f.read()) == length
        return True

    @staticmethod
    def _is_hex_string(value, length=None) -> bool:
        """Validate hex string"""
        if not (all(c.lower() in '0123456789abcdef' for c in value)
                and len(value) % 2 == 0):
            return False
        if length is not None and len(value) != length * 2:
            return False
        return True

    def _is_hex_number(self, value, length=None) -> bool:
        """Validate hex number"""
        return self._is_hex_string(value[2:], length=length)
