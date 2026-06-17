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
import tempfile
import hashlib
from typing import Union

from cryptography.hazmat.primitives.asymmetric import ec

from ...core.key_handlers import load_enckey
from ..encryption import XipEncryptor
from ...core.signtool_base import SignToolBase
from ...core.key_handlers.ec_handler import ECHandler
from ...execute.imgtool.image import TLV_VALUES, TLV_INFO_SIZE
from ...execute.image_signing.image import Image, TLV
from ...execute.image_signing.image_config_parser import ImageConfigParser
from ...pkg_globals import PkgData

logger = logging.getLogger(__name__)


class SignTool(SignToolBase):
    """Image signing and manipulations with its data"""

    DEFAULT_HEADER_SIZE = 0x400
    DEFAULT_SLOT_SIZE = 0x20000
    DEFAULT_MIN_ERASE_SIZE = 0x8000
    DEFAULT_MAX_SECTORS = 128

    def __init__(self):
        self.output = None
        self.key_path = None
        self.erased_val = 0
        self.header_size = self.DEFAULT_HEADER_SIZE
        self.slot_size = self.DEFAULT_SLOT_SIZE
        self.image_version = '0.0.0'
        self.security_counter = None
        self.align = 8
        self.public_key_format = None
        self.pubkey_encoding = None
        self.signature_encoding = None
        self.pad = False
        self.confirm = False
        self.overwrite_only = False
        self.boot_record = None
        self.min_erase_size = self.DEFAULT_MIN_ERASE_SIZE
        self.hex_addr = None
        self.load_addr = None
        self.rom_fixed = None
        self.max_sectors = self.DEFAULT_MAX_SECTORS
        self.save_enctlv = False
        self.dependencies = None
        self.encrypt = None
        self.decrypted = None
        self.endian = 'little'
        self.tlv = []
        self.prot_tlv = []
        self.remove_tlv = []
        self.enckey = None
        self.enckey_role = 'xip'
        self.encrypt_addr = None
        self.nonce = None
        self.nonce_output = None
        self.kdf = None

    def initialize(self, kwargs):
        """Initializes class attributes with the keyword arguments"""
        if kwargs.get('output'):
            self.output = os.path.abspath(kwargs.get('output'))

        if kwargs.get('key_path'):
            self.key_path = os.path.abspath(kwargs.get('key_path'))
        else:
            if kwargs.get('pubkey'):
                self.key_path = os.path.abspath(kwargs.get('pubkey'))

        if kwargs.get('erased_val') is not None:
            self.erased_val = int(str(kwargs.get('erased_val')), 0)
        if kwargs.get('slot_size') is not None:
            self.slot_size = int(str(kwargs.get('slot_size')), 0)
        if kwargs.get('header_size') is not None:
            self.header_size = int(str(kwargs.get('header_size')), 0)
        if kwargs.get('align'):
            self.align = int(str(kwargs.get('align')), 0)

        self.public_key_format = str(
            kwargs.get('public_key_format', 'hash')
        ).lower()
        if self.public_key_format not in ['hash', 'full']:
            raise ValueError('Unexpected value for public-key-format: %s')

        self.pubkey_encoding = str(
            kwargs.get('pubkey_encoding', 'der').lower()
        )
        if self.pubkey_encoding not in ['der', 'raw']:
            raise ValueError('Unexpected value for pubkey-encoding: %s')

        self.signature_encoding = str(
            kwargs.get('signature_encoding', 'asn1').lower()
        )
        if self.signature_encoding not in ['asn1', 'raw']:
            raise ValueError('Unexpected value for signature-encoding: %s')

        self.pad = kwargs.get('pad', self.pad)
        self.confirm = kwargs.get('confirm', self.confirm)
        self.overwrite_only = kwargs.get('overwrite_only', self.overwrite_only)
        self.boot_record = kwargs.get('boot_record', self.boot_record)
        if kwargs.get('min_erase_size'):
            self.min_erase_size = int(str(kwargs.get('min_erase_size')), 0)
        if kwargs.get('hex_addr') is not None:
            self.hex_addr = int(str(kwargs.get('hex_addr')), 0)
        if kwargs.get('load_addr') is not None:
            self.load_addr = int(str(kwargs.get('load_addr')), 0)
        if kwargs.get('rom_fixed') is not None:
            self.rom_fixed = int(str(kwargs.get('rom_fixed')), 0)
        self.max_sectors = kwargs.get('max_sectors', self.max_sectors)
        self.save_enctlv = kwargs.get('save_enctlv', self.save_enctlv)
        self.image_version = kwargs.get('image_version', self.image_version)
        if kwargs.get('security_counter') is not None:
            self.security_counter = int(str(kwargs.get('security_counter')), 0)
        self.dependencies = kwargs.get('dependencies')
        self.encrypt = kwargs.get('encrypt')
        self.decrypted = kwargs.get('decrypted')
        self.endian = kwargs.get('endian', self.endian)
        if kwargs.get('tlv'):
            self.tlv.extend(kwargs.get('tlv'))
        self.prot_tlv.extend(self._get_config_tlvs(kwargs))
        if kwargs.get('prot_tlv'):
            self.prot_tlv.extend(kwargs.get('prot_tlv'))
        if kwargs.get('remove_tlv'):
            self.remove_tlv.extend(kwargs.get('remove_tlv'))
        self.enckey = kwargs.get('enckey')
        if kwargs.get('enckey_role'):
            self.enckey_role = kwargs.get('enckey_role').lower()
        if kwargs.get('encrypt_addr') is not None:
            self.encrypt_addr = int(str(kwargs.get('encrypt_addr')), 0)
        if kwargs.get('nonce_output'):
            self.nonce_output = kwargs.get('nonce_output')
        self.kdf = kwargs.get('kdf')

    def sign_image(self, image: str, **kwargs) -> Union[str, Image]:
        """Signs image. Optionally encrypts the image
        @param image: The path to the image to sign
        @param kwargs:
            :output: The path where to save signed image
            :key_path: The key used to sign the image
            :image_config: The path to the image configuration file
            :erased_val: The value, which is read back from erased flash
            :header_size: Header size of the MCUboot format image
            :slot_size: Maximum slot size
            :min_erase_size: Minimum erase size
            :image_version: Sets image version in the image header
            :security_counter: Specify the value of security counter. Use the
                               'auto' keyword to automatically generate it from
                               the image version
            :align: Flash alignment
            :public_key_format: Public key format
            :pubkey_encoding: Public key encoding
            :signature_encoding: Signature encoding
            :pad: Add padding to the image trailer
            :confirm: Add image OK status to trailer
            :overwrite_only: Use overwrite mode instead of swap
            :boot_record: Create CBOR encoded boot record TLV
            :hex_addr: Adjust the address in the hex output file
            :dependencies: Add dependence on another image.
                           Format: "(<image_ID>,<image_version>), ... "
            :encrypt: Encrypt image using the provided public key
            :endian: Byte order
            :prot_tlv: Protected TLVs
            :tlv: Non-Protected TLVs
            :remove_tlv: TLV ID list to remove
            :allow_signed: Allows signing already signed image
            :enckey: Encryption key
            :enckey_role: Encryption key role, either 'xip' or 'aes-kw'
            :encrypt_addr: Starting address for data encryption
            :nonce_output: The path where to save the nonce
            :kdf: Key derivation function name
        @return: Either path to the signed file if 'output' argument is
        specified, otherwise the image object
        """
        if not kwargs.get('allow_signed'):
            img = Image(image)
            if img.is_signed:
                raise ValueError(
                    'Signature not added. The image has been already signed')

        self.initialize(kwargs)

        if not self.is_private_key(self.key_path):
            raise ValueError(f"Signing image with public key '{self.key_path}'")

        img = self._sign(image, self.key_path)

        if isinstance(img, str):
            if self.encrypt or self.enckey:
                logger.info('Image signed and encrypted successfully (%s)', img)
            else:
                logger.info('Image signed successfully (%s)', img)

        return img

    def add_metadata(self, image, **kwargs):
        """Adds MCUboot metadata to the image. Optionally encrypts
        the image
        @param image: The path to the image to add the metadata
        @param kwargs:
            :output: The path where to save unsigned image with metadata
            :decrypted: The path where to save decrypted image payload
            :image_config: The path to the image configuration file
            :erase_val: The value, which is read back from erased flash
            :header_size: Header size of the MCUboot format image
            :slot_size: Maximum slot size
            :min_erase_size: Minimum erase size
            :image_version: Sets image version in the image header
            :security_counter: Specify the value of security counter. Use the
                               'auto' keyword to automatically generate it from
                               the image version
            :align: Flash alignment
            :pubkey: Public key
            :public_key_format: Public key format
            :pubkey_encoding: Public key encoding
            :pad: Add padding to the image trailer
            :confirm: Add image OK status to trailer
            :overwrite_only: Use overwrite mode instead of swap
            :boot_record: Create CBOR encoded boot record TLV
            :hex_addr: Adjust the address in the hex output file
            :dependencies: Add dependence on another image.
                           Format: "(<image_ID>,<image_version>), ... "
            :encrypt: Encrypt image using the provided public key
            :endian: Byte order
            :prot_tlv: Protected TLVs
            :tlv: Non-Protected TLVs
            :remove_tlv: TLV ID list to remove
            :enckey: Encryption key
            :enckey_role: Encryption key role, either 'xip' or 'aes-kw'
            :encrypt_addr: Starting address for data encryption
            :nonce_output: The path where to save the nonce
        @return: Different results based on input parameters:
                  - (output, None) - if the 'output' argument is provided
                  - (output, decrypted) - if the 'output' argument is provided
                    and encryption is used
                  - (Image, None) - if the 'output' argument is not provided
                  - (Image, Image) - if the 'output' argument is not
                    provided and encryption is used
        """
        self.initialize(kwargs)

        if self.encrypt and not isinstance(self.output, type(self.decrypted)):
            raise ValueError("Arguments 'output' and 'decrypted' must be "
                             "initialized together")

        img = self._sign(image, self.key_path)

        if isinstance(img, str):
            logger.info("Image saved to '%s'", img)

        decrypted = None
        if self.encrypt:
            if isinstance(img, Image):
                with open(image, 'rb') as rf:
                    repl = rf.read()
                decrypted = self.replace_image_body(img.data, repl,
                                                    self.header_size,
                                                    erased_val=self.erased_val)
                decrypted = Image(decrypted)
            else:
                if image.endswith('.hex'):
                    with tempfile.NamedTemporaryFile(dir=os.path.dirname(image),
                                                     suffix='.bin',
                                                     delete=False) as tf:
                        temp_bin = tf.name
                    self.hex2bin(image, temp_bin)
                    self.replace_image_body(img, temp_bin, self.header_size,
                                            erased_val=self.erased_val,
                                            output=self.decrypted)
                    os.unlink(temp_bin)
                else:
                    self.replace_image_body(
                        img, image, self.header_size,
                        erased_val=self.erased_val,
                        output=self.decrypted)
                decrypted = self.decrypted
                logger.info(
                    "Saved decrypted image to '%s'", os.path.abspath(decrypted))
                logger.info(
                    'Image signature is calculated based on decrypted data. '
                    'Ensure the decrypted image is used for signing with HSM')

        return img, decrypted

    @staticmethod
    def extract_payload(image, output=None) -> Union[str, bytes]:
        """Extracts a part to be signed from MCUboot image
        @param image: Path to the image with MCUboot metadata or the image bytes
        @param output: The path where to save the payload
        @return: Payload bytes
        """
        img = Image(image)
        if not img.has_metadata:
            raise ValueError('The image does not have metadata')
        if output:
            with open(output, 'wb') as f:
                f.write(img.payload)
            logger.info("Saved image payload to '%s'", os.path.abspath(output))
        return img.payload

    @staticmethod
    def add_signature(image, signature, alg, output=None):
        """Adds ECDSA signature into MCUboot image
        @param image: Path to the image with MCUboot metadata or the image bytes
        @param signature: Path to the binary containing signature or
        the signature bytes
        @param alg: Signature algorithm
        @param output: The path where to save the payload
        @return: Signed image bytes
        """
        img = Image(image)
        if not img.has_metadata:
            raise ValueError('The image does not have metadata')
        if isinstance(signature, bytes):
            sig_bytes = signature
        else:
            with open(signature, 'rb') as f:
                sig_bytes = f.read()

        if alg in ('ECDSA-P256', 'ECDSA-P384', 'ECDSA-P521'):
            tag = TLV_VALUES['ECDSASIG']
        elif alg == 'RSA2048':
            tag = TLV_VALUES['RSA2048']
        elif alg == 'RSA4096':
            tag = TLV_VALUES['RSA4096']
        else:
            raise ValueError('Unsupported signature algorithm')

        img.remove_tlv(tag)
        tlv_signature = TLV(tag, sig_bytes)
        img.add_tlv(tlv_signature)

        if img.is_upgrade():
            img.trailer = img.trailer[TLV_INFO_SIZE + tlv_signature.length:]

        if output:
            with open(output, 'wb') as f:
                f.write(img.data)
            logger.info("Saved image to '%s'", os.path.abspath(output))
        return img.data

    @staticmethod
    def verify_image(image, key):
        """Verifies the image with a key
        @param image: The file to verify
        @param key: Verification key
        @return: True if success, otherwise False
        """
        img = image if isinstance(image, Image) else Image(image)

        if not img.is_signed:
            if isinstance(image, Image):
                raise ValueError('Image is not signed')
            raise ValueError(f"Image is not signed '{os.path.abspath(image)}'")

        pubkey = SignTool.load_public_key(key)
        result = img.verify(pubkey)

        if result:
            logger.info('Image verified successfully')
        else:
            logger.error('Invalid image signature')

        return result

    def _sign(self, image, key):
        temp_out = None
        if not self.output:
            temp_out = tempfile.NamedTemporaryFile(suffix='.bin', delete=False)
            temp_out.close()
            self.output = temp_out.name
            logger.debug("Created temporary file '%s'", self.output)

        encryptor = None
        if self.enckey_role == 'xip' and self.encrypt_addr:
            encryptor = XipEncryptor(
                initial_counter=self.encrypt_addr + self.header_size,
                nonce=None,
                plainkey=self.enckey,
                nonce_output=self.nonce_output
            )
            encrypt_arg = self.load_key(self.encrypt) if self.encrypt else None
        elif self.enckey_role == 'aes-kw':
            if isinstance(self.enckey, bytes):
                encrypt_arg = self.enckey
            else:
                encrypt_arg = load_enckey(self.enckey)
        else:
            encrypt_arg = self.load_key(self.encrypt) if self.encrypt else None

        args = {
            'key': self.load_key(key) if key else None,
            'public_key_format': self.public_key_format,
            'align': self.align,
            'version': self.image_version,
            'pad_sig': False,
            'header_size': self.header_size,
            'pad_header': True,
            'slot_size': self.slot_size,
            'pad': self.pad,
            'confirm': self.confirm,
            'max_sectors': self.max_sectors,
            'overwrite_only': self.overwrite_only,
            'endian': self.endian,
            'infile': image,
            'outfile': self.output,
            'dependencies': self.dependencies,
            'load_addr': self.load_addr,
            'hex_addr': self.hex_addr,
            'erased_val': str(self.erased_val),
            'save_enctlv': self.save_enctlv,
            'security_counter': self.security_counter,
            'boot_record': self.boot_record,
            'custom_tlv': self.prot_tlv,
            'custom_tlv_unprotected': self.tlv,
            'rom_fixed': self.rom_fixed,
            'use_random_iv': self.encrypt is not None or encryptor is not None,
            'encrypt': encrypt_arg,
            'image_addr': self.encrypt_addr or 0,
            'encryptor': encryptor,
            'kdf': self.kdf
        }

        try:
            self._call_imgtool_sign(args)
        except Exception:
            logger.error('Signature not added')
            logger.error('imgtool finished execution with errors')
            logger.info('Ref. %s/blob/master/docs/README_ERRORS.md',
                        PkgData.pkg_github_url())
            raise

        self._postprocess_tlvs(self.output, key)

        if not self.validate_trailer(self.output):
            os.unlink(self.output)
            logger.warning(
                'To prevent the image validation failure by MCUboot, '
                'ensure that header + body + protected TLVs + TLVs of the '
                'resulting image do not overlap with the last sector of '
                'memory, where the trailer is located.')
            raise ValueError('The header + body + protected TLVs + TLVs '
                             'overlap with the trailer sector')

        img = None
        if temp_out:
            img = Image(self.output)
            os.unlink(self.output)
            logger.debug("Deleted temporary file '%s'", self.output)
            self.output = None

        return self.output if self.output else img

    @staticmethod
    def _get_config_tlvs(kwargs) -> list:
        image_config = kwargs.get('image_config')
        tlvs = {}
        if image_config:
            if os.path.isfile(image_config):
                tlvs = ImageConfigParser.get_image_tlvs(image_config)
            else:
                raise FileNotFoundError(
                    f"Image configuration file '{image_config}' not found")
        return list(tlvs.items())

    def validate_trailer(self, bin_file):
        """
        Checks whether there is only trailer data in the last sector
        of the image. Only trailer should be present in the last sector
        of the slot, otherwise the image will not be validated by MCUboot.
        @param bin_file: Input file to validate
        @return: True if there is only trailer data in the last sector
        of the image, False if not
        """
        if self.overwrite_only:
            return True
        img = Image(bin_file, endian=self.endian)

        if self.slot_size % self.min_erase_size:
            sectors = self.slot_size / self.min_erase_size + 1
            max_image_size = self.min_erase_size * sectors
        else:
            max_image_size = self.slot_size

        return img.header_size + img.body_size + img.protected_tlv_length + \
            img.tlv_length <= max_image_size - self.min_erase_size

    def _postprocess_tlvs(self, bin_file, key):
        """Updates TLVs added by imgtool according to specified options"""
        img = None
        if key:
            if (self.pubkey_encoding != 'raw' and
                    self.signature_encoding != 'raw' and
                    hasattr(key, 'public_key')):
                return

            img = Image(bin_file)
            key = self.load_key(key)

            self._postprocess_key_tlv(img, key)
            self._postprocess_signature_tlv(img, key)

        if self.remove_tlv:
            if not img:
                img = Image(bin_file)
            for tag in self.remove_tlv:
                img.remove_tlv(int(str(tag), 0))

        if img and self.pad:
            img.trailer = bytes(
                [self.erased_val] * (self.slot_size - img.size)) + img.trailer

        if img:
            self._save(img)

    def _postprocess_key_tlv(self, img, key):
        """Replaces public key or its hash to raw data if the raw
        encoding is specified
        """
        if self.pubkey_encoding == 'raw':
            if not isinstance(key, (
                    ec.EllipticCurvePrivateKey, ec.EllipticCurvePublicKey)):
                raise ValueError("The 'raw' encoding of the public key "
                                 "is supported for EC key only")

            pub = ECHandler.raw_format(key)

            if self.public_key_format == 'hash':
                if key.key_size == 256:
                    sha = hashlib.sha256()
                elif key.key_size == 384:
                    sha = hashlib.sha384()
                elif key.key_size == 521:
                    sha = hashlib.sha512()
                else:
                    raise ValueError(f'Unsupported key length {key.key_size}')
                sha.update(pub)
                digest = sha.digest()
                img.remove_tlv(TLV_VALUES['KEYHASH'])
                img.add_tlv(TLV(TLV_VALUES['KEYHASH'], digest))
            else:
                img.remove_tlv(TLV_VALUES['PUBKEY'])
                img.add_tlv(TLV(TLV_VALUES['PUBKEY'], pub))

    def _postprocess_signature_tlv(self, img, key):
        """Replaces signature to raw data if the raw encoding is
        specified.
        Removes signature TLV placeholder if a public key is specified.
        imgtool adds signature TLV placeholder, which is necessary for
        the correct padding size calculation for PSoC 64 upgrade image.
        This placeholder is not needed for the general sign tool
        """
        try:
            key.public_key()
        except AttributeError:
            img.remove_tlv(TLV_VALUES['ECDSASIG'])
            img.remove_tlv(TLV_VALUES['RSA2048'])
            img.remove_tlv(TLV_VALUES['RSA3072'])
            img.remove_tlv(TLV_VALUES['RSA4096'])
            img.remove_tlv(TLV_VALUES['ED25519'])

        if self.signature_encoding == 'raw':
            sig_tlv = img.tlv_by_tag(TLV_VALUES['ECDSASIG'])
            if sig_tlv:
                r, s = ECHandler.asn1_to_rs(sig_tlv.value, key.key_size)
                img.remove_tlv(sig_tlv.tag)
                img.add_tlv(TLV(sig_tlv.tag, r + s))

    def _save(self, img):
        """Saves image object into a file"""
        if self.output.endswith('.hex'):
            with tempfile.NamedTemporaryFile(dir=os.path.dirname(self.output),
                                             suffix='.bin',
                                             delete=False) as tf:
                temp_bin = tf.name
            with open(temp_bin, 'wb') as f:
                f.write(img.data)
            self.bin2hex(temp_bin, self.output,
                         offset=self.hex_addr or img.base_addr)
            os.unlink(temp_bin)
        else:
            with open(self.output, 'wb') as f:
                f.write(img.data)
