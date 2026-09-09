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
import os
import logging
from pathlib import Path

from cryptography.hazmat.primitives.hashes import Hash, SHA256
from cryptography.hazmat.primitives.asymmetric.padding import PKCS1v15
from cryptography.hazmat.primitives.asymmetric.utils import Prehashed
from cryptography.hazmat.primitives.asymmetric import rsa
from elftools.elf.elffile import ELFFile

from ....execute.image_signing import Image
from ....core.signtool_base import SignToolBase
from ....core.key_handlers.rsa_handler import RSAHandler
from ....core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)


class SignToolXMC7xxx(SignToolBase):
    """Image signing and manipulations with its data"""

    IMAGE_ALIGNMENT = 8
    WARN_SLOT_SIZE = 0x400000
    IMAGE_VERSION = '0.1'

    DEFAULT_HEADER_SIZE = 0x400
    DEFAULT_SLOT_SIZE = 0x20000
    DEFAULT_MIN_ERASE_SIZE = 0x8000

    def __init__(self, target):
        self.target = target
        self.key_path = None
        self.erased_val = None
        self.header_size = None
        self.slot_size = None
        self.hex_addr = None
        self.pad = None
        self.overwrite_only = None
        self.align = None
        self.dependencies = None
        self.image_version = '0.0.0'
        self.output = None
        self.min_erase_size = None
        self.tlv = {}
        self.prot_tlv = {}

    def _initialize(self, kwargs):
        self.key_path = self._get_key_path(kwargs)
        self.erased_val = self._get_erased_val(kwargs)
        self.header_size = self._get_header_size(kwargs)
        self.slot_size = self._get_slot_size(kwargs)
        self.hex_addr = self._get_hex_addr(kwargs)
        self.pad = self._get_pad(kwargs)
        self.overwrite_only = self._get_overwrite_only(kwargs)
        self.align = self._get_align(kwargs)
        self.dependencies = self._get_dependencies(kwargs)
        self.image_version = self._get_image_version(kwargs)
        self.min_erase_size = self._get_min_erase_size(kwargs)

        if kwargs.get('tlv'):
            self.tlv.update(kwargs.get('tlv'))
        if kwargs.get('prot_tlv'):
            self.prot_tlv.update(kwargs.get('prot_tlv'))

    def add_metadata(self, image, **kwargs):
        """Adds MCUboot metadata to the image. Optionally
        encrypts the image
        """
        raise NotImplementedError

    @staticmethod
    def extract_payload(image, output):
        """Extracts a part to be signed from MCUboot image"""
        raise NotImplementedError

    @staticmethod
    def add_signature(image, signature, alg, output=None):
        """Adds ECDSA signature into MCUboot image"""
        raise NotImplementedError

    def sign_image(self, image, **kwargs):
        """
        Signs image with the key specified in the policy file.
        Creates copy of unsigned hex file.
        :param image: The file to sign.
        :param kwargs:
            :key_path: The key used to sign the image
            :header_size: Header size of the image in MCUboot format
            :slot_size: Maximum slot size
            :erased_val: The value that is read back from erased flash
            :output: Signed image output file
            :hex_addr: Adjust address in hex output file
            :image_version: Sets image version in the image header
            :pad: Add padding to the image trailer
            :overwrite_only: Use Overwrite mode instead of Swap
            :align: Flash alignment
            :dependencies: Add dependence on another image
        :return: Path to the signed file
        """
        img = Image(image)
        if img.is_signed:
            raise ValueError(
                'Signature not added. The image has been already signed')

        self._initialize(kwargs)

        self.output = self._get_output(image, kwargs)

        if kwargs.get('tlv'):
            self.tlv.update(kwargs.get('tlv'))

        if kwargs.get('prot_tlv'):
            self.prot_tlv.update(kwargs.get('prot_tlv'))

        self._time_warning(self.pad, self.slot_size)

        pk = self.load_key(self.key_path)

        if not self._is_private_key(pk):
            raise ValueError(f'Signing image with public key "{self.key_path}"')

        args = {
            'key': pk,
            'public_key_format': 'hash',
            'align': self.align,
            'version': self.image_version,
            'pad_sig': False,
            'header_size': self.header_size,
            'pad_header': True,
            'slot_size': self.slot_size,
            'pad': self.pad,
            'confirm': False,
            'max_sectors': 512,
            'overwrite_only': self.overwrite_only,
            'endian': 'little',
            'encrypt': None,
            'infile': image,
            'outfile': self.output,
            'dependencies': self.dependencies,
            'load_addr': None,
            'hex_addr': self.hex_addr,
            'erased_val': self.erased_val,
            'save_enctlv': False,
            'security_counter': None,
            'boot_record': None,
            'custom_tlv': [],
            'custom_tlv_unprotected': [],
            'rom_fixed': None,
            'use_random_iv': False,
            'image_addr': 0,
        }

        for t, v in self.tlv.items():
            args['custom_tlv_unprotected'].append((t, v))
        for t, v in self.prot_tlv.items():
            args['custom_tlv'].append((t, v))

        try:
            self._call_imgtool_sign(args)
        except Exception:
            logger.error('Signature not added')
            logger.error('imgtool finished execution with errors')
            raise

        if not self.validate_trailer(
                self.output, self.slot_size, self.min_erase_size
        ):
            self._cleanup(self.output)
            logger.warning(
                'To prevent the image validation failure by MCUboot, '
                'ensure that header + body + protected TLVs + TLVs of the '
                'resulting image do not overlap with the last sector of '
                'memory, where the trailer is located.')
            raise ValueError('The header + body + protected TLVs + TLVs '
                             'overlap with the trailer sector')

        logger.info('Image signed successfully (%s)', self.output)
        return self.output

    def sign_cysaf(self, image_path, **kwargs):
        """Signs application image in CySAF format
        @param image_path: Path to image in hex or bin format
        @param kwargs:
            :key_path: Path to RSA private key of length 2048, 3072 or 4096
            :output: Output path for signed image
        """

        SYM_APP_VERIFY_START = "__cy_app_verify_start"
        SYM_APP_VERIFY_LEN = "__cy_app_verify_length"
        SECTION_APP_SIGNATURE = ".cy_app_signature"
        SECTION_SYM_TAB = ".symtab"

        self._initialize(kwargs)

        key = SignToolXMC7xxx.load_key(self.key_path)
        if not isinstance(key, rsa.RSAPrivateKey):
            raise ValueError('Expected key type: RSA private')

        output = kwargs.get('output')

        with open(image_path, 'rb') as f:
            elf_payload = f.read()

        with open(image_path, 'rb') as f:
            elf = ELFFile(f)

            if elf is None:
                raise ValueError(
                    f'Failed to parse image "{os.path.abspath(image_path)}"'
                )

            for section_name in (SECTION_APP_SIGNATURE, SECTION_SYM_TAB):
                if elf.get_section_by_name(section_name) is None:
                    raise ValueError(
                        f'Unable to sign without section "{section_name}"'
                    )

            signature_section = elf.get_section_by_name(SECTION_APP_SIGNATURE)
            symtab = elf.get_section_by_name('.symtab')

            for symbol_name in (SYM_APP_VERIFY_START, SYM_APP_VERIFY_LEN):
                if symtab.get_symbol_by_name(symbol_name) is None:
                    raise ValueError(
                        f'Unable to sign without symbol "{symbol_name}"'
                    )

            app_start = symtab.get_symbol_by_name(SYM_APP_VERIFY_START)[0]
            app_length = symtab.get_symbol_by_name(SYM_APP_VERIFY_LEN)[0]

            start = app_start.entry.st_value
            length = app_length.entry.st_value
            end = start + length

            payload = [0] * length

            for segment in elf.iter_segments():
                p_type = segment.header.p_type
                p_addr = segment.header.p_paddr
                p_size = segment.header.p_memsz
                if p_type in ('PT_LOAD', 'PT_ARM_EXIDX') and p_size > 0:
                    if start <= p_addr < end:
                        for i, b in enumerate(segment.data()):
                            if p_addr - start + i >= len(payload):
                                break
                            payload[p_addr - start + i] = b
                    elif 0 < start - p_addr < p_size:
                        for i in range(0, min(length, p_addr + p_size - start)):
                            payload[i] = segment.content[i + start - p_addr]

            sha256 = Hash(SHA256())
            sha256.update(bytes(payload))
            digest = sha256.finalize()

            signature = key.sign(
                digest,
                PKCS1v15(),
                Prehashed(SHA256())
            )

            new_payload = self._update_section_content(
                elf_payload,
                signature_section,
                signature
            )

        with open(os.path.abspath(output), 'wb') as f:
            f.write(new_payload)

        logger.info("Image signed successfully '%s'", os.path.abspath(output))

    def _time_warning(self, pad, slot_size):
        if pad:
            if slot_size > self.WARN_SLOT_SIZE:
                logger.warning('The slot size is %s bytes. The padding '
                               'operation may take a while', slot_size)

    @staticmethod
    def _get_output(image_path, kwargs):
        output = kwargs.get('output')
        if not output:
            output = image_path
        output = os.path.abspath(output)
        Path(os.path.dirname(output)).mkdir(parents=True, exist_ok=True)
        return output

    @staticmethod
    def _get_hex_addr(kwargs):
        hex_addr = kwargs.get('hex_addr')
        return None if hex_addr is None else int(str(hex_addr), 0)

    def _get_align(self, kwargs):
        return int(kwargs.get('align', self.IMAGE_ALIGNMENT))

    def _get_slot_size(self, kwargs):
        if 'slot_size' in kwargs and kwargs['slot_size'] is not None:
            slot_size = int(str(kwargs['slot_size']), 0)
        else:
            slot_size = self.DEFAULT_SLOT_SIZE
        return slot_size

    @staticmethod
    def _get_erased_val(kwargs):
        erased_val = kwargs.get('erased_val')
        return '0x00' if erased_val is None else str(erased_val)

    @staticmethod
    def _get_dependencies(kwargs):
        return kwargs.get('dependencies')

    def _get_image_version(self, kwargs):
        version = kwargs.get('version')
        return self.IMAGE_VERSION if version is None else version

    def _get_key_path(self, kwargs):
        key_path = kwargs.get('key_path')
        if key_path is None:
            raise KeyError('Key path must be specified')
        return key_path

    @staticmethod
    def _get_pad(kwargs):
        return kwargs.get('pad', False)

    @staticmethod
    def _get_overwrite_only(kwargs):
        if kwargs.get('overwrite_only') is not None:
            overwrite_only = kwargs['overwrite_only']
        else:
            overwrite_only = True
        return overwrite_only

    def _get_header_size(self, kwargs):
        if 'header_size' in kwargs and kwargs['header_size'] is not None:
            header_size = int(str(kwargs['header_size']), 0)
        else:
            header_size = self.DEFAULT_HEADER_SIZE
        return header_size

    def _get_min_erase_size(self, kwargs):
        if kwargs.get('min_erase_size') is not None:
            min_erase_size = int(str(kwargs['min_erase_size']), 0)
        else:
            min_erase_size = self.DEFAULT_MIN_ERASE_SIZE
        return min_erase_size

    @staticmethod
    def _is_private_key(key):
        """Gets a value indicating whether a key
        is a private key of RSA or EC type"""
        if isinstance(key, str):
            p_key = SignToolXMC7xxx.load_key(key)
        else:
            p_key = key

        try:
            is_private = RSAHandler.is_private_key(p_key)
        except ValueError:
            try:
                is_private = ECHandler.is_private_key(p_key)
            except ValueError as e:
                raise ValueError(
                    f"Invalid or unsupported key '{key}'") from e

        return is_private

    @staticmethod
    def validate_trailer(bin_file, slot_size, min_erase_size):
        """
        Checks whether there is only trailer data in the last sector
        of the image. Only trailer should be present in the last sector
        of the slot, otherwise the image will not be validated by MCUboot.
        @param bin_file: Input file to validate
        @param min_erase_size: Minimum erase size to be used
        @param slot_size: Slot size to be used
        @return: True if there is only trailer data in the last sector
        of the image, False if not
        """
        img = Image(bin_file)
        return img.header_size + img.body_size + img.protected_tlv_length + \
            img.tlv_length <= slot_size - min_erase_size

    @staticmethod
    def _update_section_content(elf_payload, section, data):
        offset = section.header.sh_offset
        size = section.header.sh_size

        l = len(data)
        if l > size:
            raise ValueError('Data exceeds section size')
        new_payload = elf_payload[:offset] + data + elf_payload[offset + l:]
        return new_payload

    @staticmethod
    def _cleanup(file):
        """Removes file"""
        if file is not None:
            try:
                os.remove(file)
            except OSError:
                pass
