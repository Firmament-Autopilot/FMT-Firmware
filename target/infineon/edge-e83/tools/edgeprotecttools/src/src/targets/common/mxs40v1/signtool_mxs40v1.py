"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import sys
import logging
import tempfile
import binascii
import pathlib
from shutil import copy2

from intelhex import IntelHex

from ....execute.image_signing.image import Image, TLV
from ....execute import key_reader
from ....execute.imgtool.image import TLV_VALUES
from ....core.enums import ImageType
from ....core.signtool_base import SignToolBase


logger = logging.getLogger(__name__)


class SignToolMXS40v1(SignToolBase):
    """
    Implements image signing functionality for the MXS40v1 platform.
    The class can be used to sign binary and Intel hex images. However,
    it always operates with the binary. If the Intel hex image was
    specified, it is converted to the binary before the signing.
    The self.tmp_bin is a path to the binary to be signed.
    For the Intel hex format, a temporary binary file is created.
    """

    class OutputFilePair:
        """ A class to store signed BOOT and UPGRADE images paths """
        def __init__(self, boot=None, upgrade=None):
            self.boot = boot
            self.upgrade = upgrade

    def __init__(self, target):
        if target is not None:
            self.header_size = target.memory_map.VECTOR_TABLE_ADDR_ALIGNMENT
            self.parser = target.policy_parser
            self.policy_file = target.policy
        else:
            self.header_size = None
            self.parser = None
            self.policy_file = None
        self.erased_val = None
        self.upgrade_mode = 'overwrite'
        self.align = 8
        self.tmp_bin = None
        self.tmp_files = []
        self.boot_record = 'default'
        self.image_id = 1
        self.image_type = 'BOOT'
        self.slot = None
        self.enckey = None
        self.output = None
        self.tlv = []
        self.protected_tlv = []
        self.mem_map = target.memory_map

    def add_metadata(self, image, **kwargs):
        """Adds MCUboot metadata to the image. Optionally
        encrypts the image
        """
        self._initialize(image, kwargs)
        self._validate_output_extension('bin')

        result = self._process_image('sign', image, kwargs.get('erased_val'),
                                     pubkey=kwargs.get('pubkey'))

        decrypted = None
        if self.enckey and self.image_type == 'UPGRADE':
            decrypted = self._get_decrypted(kwargs)
            self.replace_image_body(result[0], self.tmp_bin, self.header_size,
                                    self.erased_val, output=decrypted)
            logger.info(
                "Saved decrypted image to '%s'", os.path.abspath(decrypted))
            logger.info(
                'Image signature is calculated based on decrypted data. Ensure '
                'the decrypted image is used for signing with HSM')

        self._cleanup()
        return tuple([result[0], decrypted]) if len(result) > 0 else None

    @staticmethod
    def extract_payload(image, output):
        """Extracts a part to be signed from MCUboot image"""
        img = Image(image)
        if not img.has_metadata:
            raise ValueError('The image does not have metadata')
        with open(output, 'wb') as f:
            f.write(img.payload)
        logger.info("Saved image payload to '%s'", os.path.abspath(output))

    @staticmethod
    def add_signature(image, signature, alg=None, output=None):
        """Adds ECDSA signature into MCUboot image"""
        img = Image(image)
        with open(signature, 'rb') as f:
            sig_bytes = f.read()

        img.remove_tlv(TLV_VALUES['ECDSASIG'])
        img.add_tlv(TLV(TLV_VALUES['ECDSASIG'], sig_bytes))

        if img.is_upgrade():
            ecdsa_sig_max_len = 72
            pad_value = img.header.header_bytes()[-1]
            pad_length = ecdsa_sig_max_len - len(sig_bytes)
            pad = pad_value.to_bytes(1, byteorder='big') * pad_length
            img.trailer = pad + img.trailer

        data = img.data
        with open(output, 'wb') as f:
            f.write(data)
        logger.info("Saved image to '%s'", os.path.abspath(output))

    def sign_image(self, image, **kwargs):
        """Signs bin or hex image with the key specified
        in the policy. Optionally encrypts the image
        """
        img = Image(image)
        if img.is_signed:
            raise ValueError(
                'Signature not added. The image has been already signed')

        self._initialize(image, kwargs)

        result = self._process_image(
            'sign', image, kwargs.get('erased_val'))

        self._cleanup()
        return tuple(result) if len(result) > 0 else None

    def backup_image(self, image):
        """Creates an image binary backup. All manipulations are going to be
        done with it. The original image stays unchanged"""
        backup = tempfile.NamedTemporaryFile(
            dir=os.path.dirname(image), suffix=pathlib.Path(image).suffix).name
        copy2(image, backup)
        self.tmp_files.append(backup)
        return backup

    def _initialize(self, image_path, kwargs):
        self.image_id = self._get_image_id(kwargs)
        self.slot = self._get_slot(self.image_id)
        self.image_type = self._get_image_type(kwargs)
        self.output = self._get_output(image_path, kwargs)
        self.boot_record = kwargs.get('boot_record', self.boot_record)
        self.upgrade_mode = self._get_upgrade_mode(kwargs)
        self.align = int(kwargs.get('align', self.align))
        self.header_size = self._get_header_size(kwargs)
        self.enckey = self._slot_enckey(kwargs)
        self.tlv = []
        if kwargs.get('tlv') is not None:
            self.tlv.extend(kwargs.get('tlv'))
        self.protected_tlv = [('0x81', self._align_tlv_value(self.slot['id']))]
        if kwargs.get('protected_tlv') is not None:
            self.protected_tlv.extend(kwargs.get('protected_tlv'))

    def _process_image(self, action, image_path, erased_val, **kwargs):
        methods = {
            'sign': self._sign_image
        }
        try:
            method = methods[action]
        except KeyError as e:
            raise NotImplementedError(f"Invalid action name '{action}'") from e

        image_backup = self.backup_image(image_path)
        result = []
        for image in self.slot['resources']:
            current_image_type = image['type'].upper()
            if self.image_type and self.image_type != current_image_type:
                continue
            self.erased_val = self._get_erased_value(
                current_image_type, erased_val=erased_val)

            self._load_image(image_backup)

            if current_image_type == ImageType.BOOT.name:
                processed_bin = method(current_image_type, self.output.boot,
                                       image['address'], **kwargs)

                if self.enckey is not None:
                    self.replace_image_body(
                        processed_bin, self.tmp_bin, self.header_size,
                        self.erased_val, output=processed_bin)
                    if self.output.boot.endswith('.hex'):
                        self.bin2hex(
                            processed_bin, self.output.boot, image['address'])
                result.append(self.output.boot)
            elif current_image_type == ImageType.UPGRADE.name:
                if not self.slot.get('upgrade', False):
                    continue
                method(current_image_type, self.output.upgrade,
                       image['address'], **kwargs)
                result.append(self.output.upgrade)
        return result

    def _load_image(self, image_path):
        """ Loads binary or Intel hex image """
        tmp_bin = tempfile.NamedTemporaryFile(
            dir=os.path.dirname(image_path), suffix='.bin').name

        if image_path.endswith('.hex'):
            ih = IntelHex()
            ih.padding = int(self.erased_val, 0)
            ih.loadfile(image_path, 'hex')
            self.hex2bin(ih, tmp_bin)
            self.tmp_bin = tmp_bin
        else:
            copy2(image_path, tmp_bin)
            self.tmp_bin = tmp_bin
        self.tmp_files.append(self.tmp_bin)

    def _sign_image(self, image_type, output, image_address, **kwargs):
        """Signs single binary file using imgtool
        :return: Signed bin file path
        """
        _, slot_size = self._slot_address_and_size(image_type, self.slot)

        if kwargs.get('pubkey'):
            key = kwargs.get('pubkey')
        else:
            key = self._user_key(self.slot).pem_key

        if output.endswith('.hex'):
            tmp_output = tempfile.NamedTemporaryFile(
                dir=os.path.dirname(output), suffix='.bin').name
        else:
            tmp_output = output

        args = {
            'key': key,
            'public_key_format': 'hash',
            'align': self.align,
            'version': self.slot['version'],
            'pad_sig': False,
            'header_size': self.header_size,
            'pad_header': True,
            'slot_size': slot_size,
            'pad': image_type != ImageType.BOOT.name,
            'confirm': False,
            'max_sectors': None,
            'overwrite_only': self.upgrade_mode != 'swap',
            'endian': 'little',
            'encrypt': self.enckey,
            'infile': self.tmp_bin,
            'outfile': tmp_output,
            'dependencies': None,
            'load_addr': None,
            'hex_addr': None,
            'erased_val': self.erased_val,
            'save_enctlv': False,
            'security_counter': self.slot['rollback_counter'],
            'boot_record': self.boot_record,
            'custom_tlv': self.protected_tlv,
            'custom_tlv_unprotected': self.tlv,
            'rom_fixed': None,
            'use_random_iv': self.enckey is not None,
            'image_addr': 0
        }

        logger.debug('Run imgtool with arguments: %s', args)

        try:
            self._call_imgtool_sign(args)
        except Exception:
            logger.error('imgtool finished execution with errors. '
                         'Signature not added')
            self._cleanup()
            raise

        if output.endswith('.hex'):
            self.bin2hex(tmp_output, output, image_address)
            self.tmp_files.append(tmp_output)

        logger.info(
            'Image for slot %s %s successfully (%s)', image_type,
            'signed' if key_reader.is_private_key(key) else 'processed', output)
        return tmp_output

    def _cleanup(self):
        """ Removes temporary files created during image signing """
        for file in self.tmp_files:
            if file is not None:
                try:
                    os.remove(file)
                except OSError:
                    pass

    def _get_min_erase_size(self, min_erase_size, slot_address):
        if self.mem_map.FLASH_ADDRESS <= slot_address < self.mem_map.FLASH_SIZE + \
                self.mem_map.FLASH_ADDRESS:
            return self.mem_map.MIN_INT_ERASE_SIZE
        if min_erase_size is None:
            return self.mem_map.MIN_EXT_ERASE_SIZE
        return int(str(min_erase_size), 0)

    def _get_slot(self, image_id):
        slot = self.parser.get_slot(image_id)
        if slot is None:
            raise ValueError(
                f"Image with ID {image_id} not found in '{self.policy_file}'")
        return slot

    def _get_erased_value(self, image_type, **kwargs):
        erased_val = kwargs.get('erased_val')
        if erased_val:
            logger.warning(
                'Custom value %s will be used as an erased value for all '
                'regions and memory types. Typical correct values for '
                'internal and external Flash memory are 0x00 and 0xFF '
                'respectively', erased_val)
        else:
            erased_val = self._default_erased_value(image_type)
        return erased_val

    @staticmethod
    def _get_image_id(kwargs):
        image_id = kwargs.get('image_id')
        return 1 if image_id is None else image_id

    @staticmethod
    def _get_image_type(kwargs):
        image_type = kwargs.get('image_type')
        return image_type.upper() if image_type is not None else None

    def _get_upgrade_mode(self, kwargs):
        upgrade_mode = kwargs.get('upgrade_mode', self.upgrade_mode).lower()
        self._validate_upgrade_mode(upgrade_mode)
        return upgrade_mode

    def _get_header_size(self, kwargs):
        if 'header_size' in kwargs and kwargs['header_size'] is not None:
            header_size = int(str(kwargs['header_size']), 0)
        else:
            header_size = self.header_size
        return header_size

    def _get_output(self, image_path, kwargs):
        image_type = self._get_image_type(kwargs)
        output_file = kwargs.get('output')
        if output_file is not None:
            if image_type is None:
                raise ValueError("The argument 'output' should only be used "
                                 "with 'image_type'.")

            output = self.OutputFilePair()
            if image_type == 'BOOT':
                output.boot = os.path.abspath(output_file)
            elif image_type == 'UPGRADE':
                output.upgrade = os.path.abspath(output_file)
            else:
                raise ValueError('Invalid image type')
        else:
            boot_output = os.path.abspath(image_path)
            upgrade_output = '{0}_upgrade{1}'.format(
                *os.path.splitext(image_path))
            output = self.OutputFilePair(boot_output, upgrade_output)
            unsigned = '{0}_unsigned{1}'.format(*os.path.splitext(image_path))
            copy2(image_path, unsigned)
            if image_type == 'UPGRADE':
                self.tmp_files.append(image_path)
        return output

    def _slot_enckey(self, kwargs):
        enckey = kwargs.get('encrypt_key')
        encryption = self.parser.encryption_enabled(self.image_id)
        if encryption:
            if enckey is None:
                enckey = self.parser.encrypt_key(self.image_id)
                if enckey is None:
                    raise ValueError('Encryption key not specified')
                if not os.path.isfile(enckey):
                    raise FileNotFoundError(
                        f"Encryption key '{enckey}' not found")
        else:
            enckey = None
        return enckey

    def _default_erased_value(self, image_type):
        is_smif = image_type == 'UPGRADE' and self.slot['smif_id'] > 0
        return '0xff' if is_smif else '0'

    @staticmethod
    def _align_tlv_value(value):
        hex_val = str("{:02x}".format(value))
        return f'0x0{hex_val}' if len(hex_val) % 2 else f'0x{hex_val}'

    def _user_key(self, slot):
        key = None
        for key_pair in self.parser.get_keys():
            if key_pair.image_type is not None and \
                    key_pair.image_type.name in ('BOOT', 'UPGRADE') and \
                    key_pair.key_id in slot['boot_auth']:
                key = key_pair
                break
        return key

    def _slot_address_and_size(self, image_type, slot):
        data = self.parser.get_image_data(image_type, slot['id'])
        if len(data) > 0:
            address, size = data[0]
        else:
            raise ValueError('Invalid image ID')
        return address, size

    @staticmethod
    def _get_signature_tlv(kwargs):
        signature = kwargs.get('signature')
        if signature is not None:
            with open(signature, 'rb') as f:
                s = binascii.hexlify(f.read()).decode(sys.stdout.encoding)
            return str(TLV_VALUES['ECDSASIG']), f'0x{s}'
        return None

    def _get_decrypted(self, kwargs):
        decrypted = kwargs.get('decrypted')
        if decrypted is None:
            if self.image_type == 'BOOT':
                output = self.output.boot
            else:
                output = self.output.upgrade
            decrypted = '{0}_decrypted.bin'.format(*os.path.splitext(output))
        return decrypted

    @staticmethod
    def _validate_upgrade_mode(upgrade_mode):
        if upgrade_mode not in ['overwrite', 'swap']:
            raise ValueError(f'Invalid value {upgrade_mode}')

    def _validate_output_extension(self, expected_ext):
        for out in [self.output.boot, self.output.upgrade]:
            if out is not None and not out.endswith(f'.{expected_ext}'):
                raise ValueError(
                    f"Invalid output file type '{out}'. Use (.{expected_ext})")
