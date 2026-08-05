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

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

from .....execute.encryption.encryptor_aes import EncryptorAES

NONCE_SIZE = 12
logger = logging.getLogger(__name__)


class EncryptorMXS40Sv2:
    def __init__(self, key):
        if isinstance(key, bytes):
            self.key = key
        else:
            with open(key, 'rb') as f:
                self.key = f.read()
        cipher = Cipher(algorithms.AES(self.key), modes.ECB())
        self.encryptor = cipher.encryptor()

    @staticmethod
    def _load(image_path):
        with open(image_path, 'rb') as f:
            image = f.read()
        return image

    @staticmethod
    def _save(data, output_path):
        with open(output_path, 'wb') as f:
            f.write(data)

    def encrypt(self, image, initial_counter, nonce=None):
        """
        Encrypts a byte array using a customized AES-CTR mode
        where a counter is incremented by 16 per block.
        A nonce format is (128 bit):
            bits 0...31 - counter + initial values
            bits 32...127 - random nonce
        """
        if nonce is None:
            nonce = os.urandom(NONCE_SIZE)
        ciphertext = EncryptorAES.encrypt_ecb(
            image, self.key, initial_counter, nonce
        )
        return ciphertext, nonce

    def encrypt_image(self, input_file, initial_counter=None, output=None,
                      nonce=None, nonce_output=None):
        """Encrypts an image and saves the encrypted data and nonce
        into files. If the output locations are not specified the output
        files are saved in the same location as the input with the
        prefix _encrypted and _nonce.
        @param input_file: Binary file to encrypt
        @param initial_counter: A value matching application address
        @param output: Encrypted image output path
        @param nonce: A hex string representing nonce used for encryption. If
                      not provided, a random value will be generated
        @param nonce_output: The path to a file where to save the nonce
        """
        image = self._load(input_file)

        try:
            nonce_val = self.nonce_value(nonce)
        except ValueError:
            logger.error('Non-hexadecimal number specified')
            return False, None, None

        if nonce_val and len(nonce_val) > 12:
            logger.error('Nonce length must be 12 bytes')
            return False, None, None

        try:
            iv = int(str(initial_counter), 0) if initial_counter else 0
        except ValueError:
            logger.info('Initialization vector must be equal to '
                        'the application base address')
            logger.error("Invalid initialization vector value '%s'",
                         initial_counter)
            return False, None, None

        ciphertext, nonce_val = self.encrypt(image, iv, nonce=nonce_val)

        if output is None:
            output = '{0}_encrypted{1}'.format(*os.path.splitext(input_file))

        if nonce_output is None:
            nonce_output = '{0}_nonce{1}'.format(*os.path.splitext(input_file))

        self._save(ciphertext, output)
        self._save(nonce_val, nonce_output)

        return True, output, nonce_output

    @staticmethod
    def nonce_value(nonce):
        """Gets nonce bytes from hex string or file"""
        nonce_val = None
        if nonce:
            if os.path.isfile(nonce):
                with open(nonce, 'rb') as f:
                    nonce_val = f.read()
            else:
                nonce_val = bytes.fromhex(nonce.zfill(24))
        return nonce_val
