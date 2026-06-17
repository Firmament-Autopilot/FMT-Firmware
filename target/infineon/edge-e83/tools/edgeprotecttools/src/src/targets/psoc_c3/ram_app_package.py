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
import logging
import os
import tempfile

from ...execute.image_signing.sign_tool import SignTool
from ...execute.imgtool.image import TLV_VALUES

logger = logging.getLogger(__name__)


class RamAppPackagePsocC3:
    """A class representing the RAM application package"""

    def __init__(self, ram_app, input_params=None):
        """
        Creates an instance of RAM application package
        @param ram_app: Path to the RAM application
        @param input_params: Path to the RAM application input
            parameters
        """
        self.__slot_size = 0xB800
        self.ram_app = self.ram_app_bytes(ram_app)
        self.input_params = self.input_params_bytes(input_params)
        self.signer = SignTool()
        self.options = {
            'public_key_format': 'full',
            'pubkey_encoding': 'raw',
            'signature_encoding': 'raw',
            'allow_signed': True,
            'header_size': 0x20,
            'slot_size': self.__slot_size,
            'remove_tlv': [TLV_VALUES['SHA256'],
                           TLV_VALUES['SHA384'],
                           TLV_VALUES['SHA512']]
        }

    @property
    def slot_size(self) -> int:
        """Gets the maximum slot size"""
        return self.__slot_size

    @slot_size.setter
    def slot_size(self, value):
        """Sets the maximum slot size"""
        self.__slot_size = int(str(value), 0)
        self.options['slot_size'] = self.__slot_size

    @property
    def package_bytes(self) -> bytes:
        """Unsigned package bytes"""
        return self.ram_app + self.input_params

    @staticmethod
    def ram_app_bytes(filename) -> bytes:
        """RAM application bytes"""
        with open(filename, 'rb') as f:
            return f.read()

    @staticmethod
    def input_params_bytes(filename) -> bytes:
        """RAM application input parameters bytes"""
        if filename is not None:
            with open(filename, 'rb') as f:
                return f.read()
        return b''

    def sign_bin(self, key=None) -> bytes:
        """Signs RAM application package
        @param key: Path to a private key in pem format. If key not
            provided, the unsigned image is generated
        @return: Signed package bytes
        """
        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as infile:
            infile.write(self.package_bytes)
            infile.flush()
        if key:
            img = self.signer.sign_image(infile.name, key_path=key,
                                         **self.options)
        else:
            img, _ = self.signer.add_metadata(infile.name, **self.options)
        os.unlink(infile.name)
        return img.data

    def sign_hex(self, hex_addr, key=None, output=None) -> str:
        """Signs RAM application package
        @param hex_addr: Hex address where the image will be loaded
        @param key: Path to a private key in pem format. If key not
            provided, the unsigned image is generated
        @param output: Path to save the signed package
        @return: Path to the signed package
        """
        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as infile:
            infile.write(self.package_bytes)
            infile.flush()
            if key:
                img_path = self.signer.sign_image(
                    infile.name, key_path=key, hex_addr=hex_addr, output=output,
                    **self.options)
            else:
                img_path, _ = self.signer.add_metadata(
                    infile.name, hex_addr=hex_addr, output=output,
                    **self.options)
        os.unlink(infile.name)
        return img_path
