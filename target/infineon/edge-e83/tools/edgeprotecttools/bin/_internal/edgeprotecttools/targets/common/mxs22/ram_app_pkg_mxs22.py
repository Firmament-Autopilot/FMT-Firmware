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
import tempfile

from ....execute.image_signing import SignTool
from ....execute.imgtool.image import TLV_VALUES

logger = logging.getLogger(__name__)


class RamAppPackageMXS22:
    """A class representing the RAM application package"""

    def __init__(self, ram_app, input_params=None):
        """
        Creates an instance of RAM application package
        @param ram_app: Path to the RAM application
        @param input_params: Path to the RAM application input
            parameters
        """
        self.ram_app = self.ram_app_bytes(ram_app)
        self.input_params = self.input_params_bytes(input_params)

        self.signer = SignTool()
        self.options = {
            'signature_encoding': 'raw',
            'allow_signed': True,
            'header_size': 0x20,
            'slot_size': 0x100000,
            'remove_tlv': [
                TLV_VALUES['SHA256'], TLV_VALUES['SHA384'],
                TLV_VALUES['SHA512'], TLV_VALUES['KEYHASH']]
        }

    @property
    def package_bytes(self):
        """Unsigned package bytes"""
        return self.ram_app + self.input_params

    @staticmethod
    def ram_app_bytes(filename):
        """RAM application bytes"""
        with open(filename, 'rb') as f:
            return f.read()

    @staticmethod
    def input_params_bytes(filename):
        """RAM application input parameters bytes"""
        if filename is not None:
            with open(filename, 'rb') as f:
                return f.read()
        return b''

    def sign_bin(self, key=None):
        """Signs RAM application package
        @param key: Path to a private key in pem format. If key not
            provided, the zero-signature is generated
        @return: Signed package bytes
        """
        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as infile:
            infile.write(self.package_bytes)
            infile.flush()
            with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as outfile:

                if key:
                    self.signer.sign_image(infile.name, key_path=key,
                                           output=outfile.name, **self.options)
                else:
                    self.signer.add_metadata(infile.name, output=outfile.name,
                                             **self.options)
                img = outfile.read()
        os.unlink(infile.name)
        os.unlink(outfile.name)
        return img

    def sign_hex(self, key=None, **kwargs):
        """Signs RAM application package
        @param key: Path to a private key in pem format. If key not
            provided, the zero-signature is generated
        @return: Signed package bytes
        """
        if kwargs.get('hex_addr'):
            hex_addr = int(str(kwargs.get('hex_addr')), 0)
        else:
            raise ValueError('Hex address not specified')

        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as infile:
            infile.write(self.package_bytes)
            infile.flush()
            if key:
                img = self.signer.sign_image(
                    infile.name, key_path=key, output=kwargs.get('output'),
                    hex_addr=hex_addr, **self.options)
            else:
                img, _ = self.signer.add_metadata(
                    infile.name, hex_addr=hex_addr, output=kwargs.get('output'),
                    **self.options)
        os.unlink(infile.name)
        return img
