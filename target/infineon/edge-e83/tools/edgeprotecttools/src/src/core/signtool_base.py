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
from inspect import getmembers
from abc import ABC, abstractmethod

import click
from intelhex import hex2bin, bin2hex, IntelHex

from ..execute.imgtool import main as imgtool
from .key_handlers import load_private_key, load_public_key


class SignToolBase(ABC):
    """Base class for the classes that implement
    image signing behaviour
    """

    @abstractmethod
    def sign_image(self, image, **kwargs):
        """Signs firmware image"""

    @abstractmethod
    def add_metadata(self, image, **kwargs):
        """Creates a complete MCUboot format image"""

    @staticmethod
    @abstractmethod
    def extract_payload(image, output):
        """Extracts from the image a part that has to be signed"""

    @staticmethod
    @abstractmethod
    def add_signature(image, signature, alg, output=None):
        """Adds a signature to MCUboot format image"""

    @staticmethod
    def bin2hex(fin, fout, offset=0):
        """Converts bin to hex"""
        return bin2hex(fin, fout, offset) == 0

    @staticmethod
    def hex2bin(fin, fout, start=None, end=None, size=None, pad=None):
        """Converts hex to bin"""
        return hex2bin(fin, fout,
                       start=int(str(start), 0) if start else start,
                       end=int(str(end), 0) if end else end,
                       size=int(str(size), 0) if size else size,
                       pad=int(str(pad), 0) if pad else pad) == 0

    @staticmethod
    def load_key(key_path, password=None):
        """Loads key from specified path"""
        try:
            key = load_private_key(key_path, password=password)
        except ValueError:
            try:
                key = load_public_key(key_path)
            except ValueError as e:
                raise ValueError(
                    f"Failed to open the key '{key_path}'. "
                    "The data may be in an incorrect format") from e
        return key

    @staticmethod
    def load_public_key(key_path):
        """Loads public key from a file to an object"""
        try:
            return load_public_key(key_path)
        except ValueError:
            try:
                return load_private_key(key_path).public_key()
            except ValueError:
                return None

    @staticmethod
    def is_private_key(key_path):
        """Gets a value indicating whether the key is a private"""
        key = SignToolBase.load_key(key_path)
        try:
            key.private_numbers()
        except AttributeError:
            return False
        return True

    @staticmethod
    def replace_image_body(orig, repl, header_size, erased_val=0, output=None):
        """Replaces original image with the replacement image
        @param orig: Original binary or hex image
        @param repl: Binary or hex image to replace with
        @param header_size: MCUboot image header size
        @param erased_val: The value that is read back from erased flash
        @param output: Output file
        @return: Modified image bytes
        """
        if isinstance(orig, bytes):
            original = orig
        else:
            if orig.endswith('hex'):
                ih = IntelHex(orig)
                original = ih.tobinarray()
            else:
                with open(orig, 'rb') as of:
                    original = of.read()
        if isinstance(repl, bytes):
            replacement = repl
        else:
            if repl.endswith('hex'):
                ih = IntelHex(repl)
                replacement = ih.tobinarray()
            else:
                with open(repl, 'rb') as rf:
                    replacement = rf.read()

        modified = bytearray(original)
        body_start = header_size
        body_end = header_size + len(replacement)

        j = 0
        for i in range(body_start, body_end):
            modified[i] = replacement[j]
            j += 1

        # This adds padding if the image is not aligned to 16 Bytes
        pad_len = body_end % 16
        pad_value = int(str(erased_val), 0)
        if pad_len > 0:
            pad_len = 16 - pad_len
            for i in range(body_end, body_end + pad_len):
                modified[i] = pad_value

        if output:
            with open(output, 'wb') as of:
                of.write(modified)

        return modified

    @staticmethod
    def _call_imgtool_sign(args):

        def _call_click_command(cmd: click.Command, *args, **kwargs):
            result = cmd.callback(*args, **kwargs)
            return result

        for _, obj in getmembers(imgtool):
            if isinstance(obj, click.Command) and obj.name == 'sign':
                _call_click_command(obj, **args)
                break
