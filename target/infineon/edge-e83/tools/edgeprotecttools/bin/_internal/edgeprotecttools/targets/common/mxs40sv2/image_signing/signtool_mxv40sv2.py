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
import os
import logging
import binascii
from shutil import copy2
from pathlib import Path

from .encrypt_mxv40sv2 import EncryptorMXS40Sv2
from .xip_encryptor_mxs40sv2 import XipEncryptor
from ..enums import PolicyType
from ..nv_counter_calc import NvCounterCalculator
from .....execute.image_signing.image import Image
from .....execute.image_signing.image_config_parser import ImageConfigParser
from .....execute.imgtool.keys import ecdsa
from .....execute.imgtool import main as imgtool
from .....core.signtool_base import SignToolBase
from .....core.key_handlers.rsa_handler import RSAHandler
from .....core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)


class SignToolMXS40Sv2(SignToolBase):
    """Image signing and manipulations with its data"""

    IMAGE_ALIGNMENT = 8
    WARN_SLOT_SIZE = 0x400000
    IMAGE_VERSION = '0.1'

    def __init__(self, target):
        self.target = target
        self.mem_map = self.target.memory_map
        self.policy_parser = target.policy_parser
        self.key_source = target.key_source
        self.min_erase_size = self.mem_map.MIN_EXT_ERASE_SIZE

    def extend_image(self, image_path, **kwargs):
        """ Extends the image with TLVs. Optionally encrypts the image """
        pubkey_data = self._get_pubkey(kwargs)
        erased_val = self._get_erased_val(kwargs)
        output = self._get_output(image_path, 'orig', kwargs)
        image_format = self._get_image_format(kwargs)
        header_size = self._get_header_size(image_format, kwargs)
        slot_size = self._get_slot_size(kwargs)
        tlv = kwargs.get('tlv')
        protected_tlv = kwargs.get('protected_tlv')
        skip_tlv_info = kwargs.get('skip_tlv_info', False)
        hex_addr = self._get_hex_addr(kwargs)
        pad = self._get_pad(kwargs)
        confirm = self._get_confirm(image_format, kwargs)
        overwrite_only = self._get_overwrite_only(image_format, kwargs)
        align = self._get_align(kwargs)
        image_version = self._get_image_version(kwargs)
        image_id = kwargs.get('image_id', 0)
        update_key_id = kwargs.get('update_key_id')
        update_key_path = kwargs.get('update_key_path')

        if 'bootrom_next_app' == image_format:
            if pubkey_data is None:
                raise ValueError('Public key not specified')

        self._time_warning(pad, slot_size)

        if pubkey_data is not None:
            protected_tlv.append(('0xf0', f'0x{pubkey_data}'))

        tlvs = self._get_config_tlvs(kwargs.get('image_config'))
        for t, v in tlvs.items():
            protected_tlv.append((t, v))

        nv_counter = None
        if self.policy_parser.json:
            policy_type = self.policy_parser.policy_type()
            if policy_type == PolicyType.REPROVISIONING_SECURE:
                nv_counter, update_packet = self._get_update_packet_data(
                   update_key_id, update_key_path, image_id)
                protected_tlv.append(update_packet)
            else:
                if update_key_id is not None or update_key_path:
                    logger.warning(
                        "The update key is specified, but the policy is not of "
                        "the 'reprovisioning_secure' type. Update packet will "
                        "not be added to the image")
        else:
            if update_key_id is not None or update_key_path:
                raise RuntimeError("The 'reprovisioning_secure' policy is "
                                   "required to create an update packet")

        try:
            imgtool.extend(align, image_version,
                           header_size, slot_size, image_path, output,
                           protected_tlv, tlv, pad_header=True, pad=pad,
                           confirm=confirm, overwrite_only=overwrite_only,
                           hex_addr=hex_addr, erased_val=erased_val,
                           skip_tlv_info=skip_tlv_info,
                           security_counter=nv_counter)
            logger.info('Image processed successfully (%s)', output)
        except Exception as e:
            logger.error('Failed to add data to the image')
            logger.error('imgtool finished execution with errors')
            raise e
        return output

    def sign_image(self, image, **kwargs):
        """
        Signs image with the key specified in the policy file.
        Creates copy of unsigned hex file.
        :param image: The file to sign.
        :return: Path to the signed file
        """
        img = Image(image)
        if img.is_signed:
            raise ValueError(
                'Signature not added. The image has been already signed')

        key_path = self._get_key_path(kwargs)
        erased_val = self._get_erased_val(kwargs)
        image_format = self._get_image_format(kwargs)
        header_size = self._get_header_size(image_format, kwargs)
        slot_size = self._get_slot_size(kwargs)
        app_addr = self._get_app_addr(kwargs)
        hex_addr = self._get_hex_addr(kwargs)
        output = self._get_output(image, 'unsigned', kwargs)
        enckey = self._get_enckey(kwargs)
        pad = self._get_pad(kwargs)
        confirm = self._get_confirm(image_format, kwargs)
        overwrite_only = self._get_overwrite_only(image_format, kwargs)
        min_erase_size = self._get_min_erase_size(kwargs)
        align = self._get_align(kwargs)
        dependencies = self._get_dependencies(kwargs)
        image_version = self._get_image_version(kwargs)
        image_id = self._get_image_id(kwargs)

        if not self._is_private_key(key_path):
            raise ValueError(f'Signing image with public key \'{key_path}\'')

        self._time_warning(pad, slot_size)

        tlvs = self._get_config_tlvs(kwargs.get('image_config'))

        if 'mcuboot_user_app' == image_format and enckey:
            enckey_obj = imgtool.load_key(enckey) if enckey else None
            if not isinstance(enckey_obj, ecdsa.ECDSA256P1Public):
                raise ValueError('ECDSA key must be specified')
            encryptor = XipEncryptor(
                initial_counter=app_addr + header_size,
                nonce=None
            )
        else:
            encryptor = None

        args = {
            'key': key_path,
            'public_key_format': 'hash',
            'align': align,
            'version': image_version,
            'pad_sig': False,
            'header_size': header_size,
            'pad_header': True,
            'slot_size': slot_size,
            'pad': pad,
            'confirm': confirm,
            'max_sectors': 512,
            'overwrite_only': overwrite_only,
            'endian': 'little',
            'encrypt': enckey if 'mcuboot_user_app' == image_format else None,
            'infile': image,
            'outfile': output,
            'dependencies': dependencies,
            'load_addr': None,
            'hex_addr': hex_addr,
            'erased_val': erased_val,
            'save_enctlv': False,
            'security_counter': None,
            'boot_record': None,
            'custom_tlv': [],
            'custom_tlv_unprotected': [],
            'rom_fixed': None,
            'use_random_iv': encryptor is not None,
            'image_addr': app_addr,
            'encryptor': encryptor,
        }

        for t, v in tlvs.items():
            args['custom_tlv'].append((t, v))

        if image_format in ['bootrom_next_app', 'bootrom_ram_app']:
            pubkey_data = RSAHandler.convert_to_mbedtls(key_path)
            args['custom_tlv'].append(('0xf0', f'0x{pubkey_data}'))

        policy_type = self.policy_parser.policy_type()
        if policy_type == PolicyType.REPROVISIONING_SECURE:
            nv_counter, update_packet = self._get_update_packet_data(
                kwargs.get('update_key_id'), kwargs.get('update_key_path'),
                image_id)
            args['security_counter'] = nv_counter
            args['custom_tlv'].append(update_packet)

        try:
            self._call_imgtool_sign(args)
        except Exception:
            logger.error('Signature not added')
            logger.error('imgtool finished execution with errors')
            raise

        if image_format == 'mcuboot_user_app':
            if not self.validate_trailer(output, slot_size, min_erase_size):
                self._cleanup(output)
                logger.warning('To prevent the image validation failure by MCUboot, '
                               'ensure that the last sector of the slot contains '
                               'only the trailer')
                raise ValueError('The last sector contains part of the image body')

        if enckey:
            if 'bootrom_next_app' == image_format:
                encryptor = EncryptorMXS40Sv2(enckey)
                is_enc_success, output, nonce = encryptor.encrypt_image(
                    output,
                    initial_counter=app_addr,
                    output=kwargs.get('encr_path'),
                    nonce=kwargs.get('nonce'),
                    nonce_output=kwargs.get('nonce_output'))

                if is_enc_success:
                    logger.info(
                        'Image signed and encrypted successfully (%s, %s)',
                        output, nonce)
                else:
                    logger.error('Encryption failed')
            elif 'bootrom_ram_app' == image_format:
                logger.warning('Encryption is not supported for image format '
                               '%s', image_format)
                logger.info('Image signed successfully (%s)', output)
            else:
                logger.info(
                    'Image signed and encrypted successfully (%s)', output)
        else:
            logger.info('Image signed successfully (%s)', output)
        return output

    def add_metadata(self, image, **kwargs):
        """N/A for MXS40Sv2 platform"""
        raise NotImplementedError

    @staticmethod
    def extract_payload(image, output, **kwargs):
        """N/A for MXS40Sv2 platform"""
        raise NotImplementedError

    @staticmethod
    def add_signature(image, signature, alg, output=None):
        """N/A for MXS40Sv2 platform"""
        raise NotImplementedError

    def _get_update_packet_data(self, update_key_id, update_key_path, image_id):
        if update_key_id is None and update_key_path is None:
            raise KeyError('Either update data packet key ID or key path '
                           'must be specified')
        if update_key_path is None:
            update_key_path = self.key_source.get_key(update_key_id, 'private')

        nv_counter = NvCounterCalculator.calculate(
            self.policy_parser.get_nv_counter(),
            self.policy_parser.get_bits_per_cnt(),
            image_id=image_id)

        reprov_data = binascii.hexlify(self._reprovisioning_packet(
            key_id=update_key_id, key_path=update_key_path,
            image_id=image_id)).decode()
        return nv_counter, ('0x51', f'0x{reprov_data}')

    def _reprovisioning_packet(self, **kwargs):
        return self.target.provisioning_packet_strategy.reprovisioning_data(
            self.target.key_source, **kwargs)

    def _time_warning(self, pad, slot_size):
        if pad:
            if slot_size > self.mem_map.MAX_SLOT_SIZE:
                logger.warning('The slot size is %s bytes. The padding '
                               'operation may take a long time', slot_size)
            elif slot_size > self.WARN_SLOT_SIZE:
                logger.warning('The slot size is %s bytes. The padding '
                               'operation may take a while', slot_size)

    @staticmethod
    def _get_pubkey(kwargs):
        pubkey = kwargs.get('pubkey')
        if pubkey is not None:
            pubkey_data = RSAHandler.convert_to_mbedtls(pubkey)
        else:
            pubkey_data = None
        return pubkey_data

    def _get_enckey(self, kwargs):
        if kwargs.get('encrypt', False):
            enckey = kwargs.get('enckey')
            if enckey is None:
                enckey = self.key_source.get_aes_key()
        else:
            enckey = None
        return enckey

    def _get_output(self, image_path, suffix, kwargs):
        output = kwargs.get('output')
        if not output:
            self._copy_input_image(image_path, suffix)
            output = image_path
        output = os.path.abspath(output)
        Path(os.path.dirname(output)).mkdir(parents=True, exist_ok=True)
        return output

    @staticmethod
    def _get_app_addr(kwargs):
        app_addr = kwargs.get('app_addr')
        return 0 if app_addr is None else int(str(app_addr), 0)

    @staticmethod
    def _get_hex_addr(kwargs):
        hex_addr = kwargs.get('hex_addr')
        return 0 if hex_addr is None else int(str(hex_addr), 0)

    def _get_align(self, kwargs):
        return int(kwargs.get('align', self.IMAGE_ALIGNMENT))

    def _get_slot_size(self, kwargs):
        if 'slot_size' in kwargs and kwargs['slot_size'] is not None:
            slot_size = int(str(kwargs['slot_size']), 0)
        else:
            slot_size = self.mem_map.MAX_SLOT_SIZE
        return slot_size

    @staticmethod
    def _get_erased_val(kwargs):
        erased_val = kwargs.get('erased_val')
        return '0xff' if erased_val is None else str(erased_val)

    @staticmethod
    def _get_dependencies(kwargs):
        return kwargs.get('dependencies')

    def _get_image_version(self, kwargs):
        version = kwargs.get('version')
        return self.IMAGE_VERSION if version is None else version

    def _get_min_erase_size(self, kwargs):
        min_erase_size = kwargs.get('min_erase_size')
        return self.mem_map.MIN_EXT_ERASE_SIZE if min_erase_size is None \
            else int(str(min_erase_size), 0)

    def _get_key_path(self, kwargs):
        key_id = kwargs.get('key_id')
        key_path = kwargs.get('key_path')
        if key_id is None and key_path is None:
            raise KeyError('Either key ID or key path must be specified')
        if key_path is None:
            key_path = self.key_source.get_key(key_id, 'private')
        return key_path

    @staticmethod
    def _get_image_format(kwargs):
        return kwargs.get('image_format', 'mcuboot_user_app')

    @staticmethod
    def _get_pad(kwargs):
        return kwargs.get('pad', False)

    @staticmethod
    def _get_confirm(image_format, kwargs):
        if image_format == 'mcuboot_user_app':
            return kwargs.get('confirm', False)
        return False

    @staticmethod
    def _get_image_id(kwargs):
        image_id = kwargs.get('image_id')
        return 0 if image_id is None else image_id

    @staticmethod
    def validate_trailer(bin_file, slot_size, min_erase_size):
        """
        Checks whether there is only trailer data in the last sector of the image.
        Only trailer should be present in the last sector of the slot, otherwise
        the image will not be validated by MCUboot.
        @param bin_file: Input file to validate
        @param min_erase_size: Minimum erase size to be used
        @param slot_size: Slot size to be used
        @return: True is there is only trailer data in the last sector of the image,
        False if not
        """
        img = Image(bin_file)
        return img.body_size + img.header_size + img.tlv_length <= slot_size - min_erase_size

    @staticmethod
    def _get_overwrite_only(image_format, kwargs):
        if kwargs.get('overwrite_only') is not None:
            overwrite_only = kwargs['overwrite_only']
        elif 'mcuboot_user_app' == image_format:
            overwrite_only = False
        else:
            overwrite_only = True
        return overwrite_only

    def _get_header_size(self, image_format, kwargs):
        if 'header_size' in kwargs and kwargs['header_size'] is not None:
            header_size = int(str(kwargs['header_size']), 0)
        elif 'mcuboot_user_app' == image_format:
            header_size = self.mem_map.MCUBOOT_USER_APP_HEADER_SIZE
        elif 'bootrom_ram_app' == image_format:
            header_size = self.mem_map.BOOTROM_RAM_APP_HEADER_SIZE
        else:
            header_size = self.mem_map.BOOTROM_NEXT_APP_HEADER_SIZE
        return header_size

    @staticmethod
    def _copy_input_image(image_path, suffix):
        unsigned = '{0}_{2}{1}'.format(*os.path.splitext(image_path) + (
            suffix,))
        copy2(image_path, unsigned)

    @staticmethod
    def _get_config_tlvs(image_config):
        tlvs = {}
        if image_config is not None:
            if os.path.isfile(image_config):
                tlvs = ImageConfigParser.get_image_tlvs(image_config)
            else:
                raise FileNotFoundError(
                    f'Image configuration file \'{image_config}\' not found')
        return tlvs

    @staticmethod
    def _is_private_key(key_path):
        """Gets a value indicating whether a key
        is a private key of RSA or EC type"""
        k = SignToolMXS40Sv2.load_key(key_path)

        try:
            is_private = RSAHandler.is_private_key(k)
        except ValueError:
            try:
                is_private = ECHandler.is_private_key(k)
            except ValueError as e:
                raise ValueError(
                    f"Invalid or unsupported key '{key_path}'") from e

        return is_private

    @staticmethod
    def _cleanup(file):
        """Removes file"""
        if file is not None:
            try:
                os.remove(file)
            except OSError:
                pass
