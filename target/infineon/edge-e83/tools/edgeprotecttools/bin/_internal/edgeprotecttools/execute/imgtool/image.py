# Copyright 2018 Nordic Semiconductor ASA
# Copyright 2017-2020 Linaro Limited
# Copyright 2019-2020 Arm Limited
# Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
#     Changes made to the original file:
#     [Oct 6 2021]
#         - Added image encryption scheme with random salt and AES
#           initial vectors from HKDF tag
#         - Added custom non-protected TLV support
#         - Added option to skip adding non-protected TLV to
#           the image
#         - Added custom encryptor support
#         - Added image_addr argument necessary for XIP encryption.
#           Consider image_addr value in HKDF salt calculation
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
Image signing and management.
"""

from . import version as versmod
from .boot_record import create_sw_component_data
import click
from enum import Enum
from intelhex import IntelHex
import hashlib
import os.path
import struct
from cryptography.exceptions import InvalidSignature
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, hmac, cmac
from cryptography.hazmat.primitives.asymmetric import ec, padding
from cryptography.hazmat.primitives.asymmetric.x25519 import X25519PrivateKey
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.kdf.kbkdf import (
    KBKDFCMAC, Mode, CounterLocation
)
from cryptography.hazmat.primitives.serialization import Encoding, PublicFormat
from cryptography.hazmat.primitives import keywrap

from . import keys
from .keys import rsa, ecdsa, x25519

IMAGE_MAGIC = 0x96f3b83d
IMAGE_HEADER_SIZE = 32
BIN_EXT = "bin"
INTEL_HEX_EXT = "hex"
DEFAULT_MAX_SECTORS = 128
MAX_ALIGN = 8
DEP_IMAGES_KEY = "images"
DEP_VERSIONS_KEY = "versions"
MAX_SW_TYPE_LENGTH = 12  # Bytes

# Image header flags.
IMAGE_F = {
        'PIC':                   0x0000001,
        'ENCRYPTED':             0x0000004,
        'NON_BOOTABLE':          0x0000010,
        'RAM_LOAD':              0x0000020,
        'ROM_FIXED':             0x0000100,
}

TLV_VALUES = {
        'KEYHASH': 0x01,
        'PUBKEY': 0x02,
        'SHA256': 0x10,
        'SHA384': 0x11,
        'SHA512': 0x12,
        'RSA2048': 0x20,
        'ECDSASIG': 0x22,
        'RSA3072': 0x23,
        'ED25519': 0x24,
        'RSA4096': 0x25,
        'ENCRSA2048': 0x30,
        'ENCKW128': 0x31,
        'ENCEC256': 0x32,
        'ENCX25519': 0x33,
        'DEPENDENCY': 0x40,
        'SEC_CNT': 0x50,
        'BOOT_RECORD': 0x60,
}

TLV_SIZE = 4
TLV_INFO_SIZE = 4
TLV_INFO_MAGIC = 0x6907
TLV_PROT_INFO_MAGIC = 0x6908

boot_magic = bytes([
    0x77, 0xc2, 0x95, 0xf3,
    0x60, 0xd2, 0xef, 0x7f,
    0x35, 0x52, 0x50, 0x0f,
    0x2c, 0xb6, 0x79, 0x80, ])

STRUCT_ENDIAN_DICT = {
        'little': '<',
        'big':    '>'
}

VerifyResult = Enum('VerifyResult',
                    """
                    OK INVALID_MAGIC INVALID_TLV_INFO_MAGIC INVALID_HASH
                    INVALID_SIGNATURE
                    """)


class TLV():
    def __init__(self, endian, magic=TLV_INFO_MAGIC):
        self.magic = magic
        self.buf = bytearray()
        self.endian = endian

    def __len__(self):
        return TLV_INFO_SIZE + len(self.buf)

    def add(self, kind, payload):
        """
        Add a TLV record.  Kind should be a string found in TLV_VALUES above.
        """
        e = STRUCT_ENDIAN_DICT[self.endian]
        if isinstance(kind, int):
            buf = struct.pack(e + 'BBH', kind, 0, len(payload))
        else:
            buf = struct.pack(e + 'BBH', TLV_VALUES[kind], 0, len(payload))
        self.buf += buf
        self.buf += payload

    def get(self):
        if len(self.buf) == 0:
            return bytes()
        e = STRUCT_ENDIAN_DICT[self.endian]
        header = struct.pack(e + 'HH', self.magic, len(self))
        return header + bytes(self.buf)


USER_SHA_TO_ALG_AND_TLV = {
    'auto'   : (hashlib.sha256, 'SHA256'),
    '256'    : (hashlib.sha256, 'SHA256'),
    '384'    : (hashlib.sha384, 'SHA384'),
    '512'    : (hashlib.sha512, 'SHA512')
}


# Auto selecting hash algorithm for type(key)
ALLOWED_KEY_SHA = {
    keys.ECDSA521P1         : ['512'],
    keys.ECDSA521P1Public   : ['512'],
    keys.ECDSA384P1         : ['384'],
    keys.ECDSA384P1Public   : ['384'],
    keys.ECDSA256P1         : ['256'],
    keys.ECDSA256P1Public   : ['256'],
    keys.RSA                : ['256'],
    keys.RSAPublic          : ['256'],
    # This two are set to 256 for compatibility, the right would be 512
    keys.Ed25519            : ['256', '512'],
    keys.X25519             : ['256', '512']
}


def key_and_user_sha_to_alg_and_tlv(key, user_sha, is_pure=False):
    """Matches key and user requested sha to sha algorithm and TLV name.

       The returned tuple will contain hash functions and TVL name.
       The function is designed to succeed or completely fail execution,
       as providing incorrect pair here basically prevents doing
       any more work.
    """
    if key is None:
        # If key is none, we allow whatever user has selected for sha
        return USER_SHA_TO_ALG_AND_TLV[user_sha]

    # If key is not None, then we have to filter hash to only allowed
    allowed = None
    allowed_key_ssh = ALLOWED_KEY_SHA
    try:
        allowed = allowed_key_ssh[type(key)]

    except KeyError:
        raise click.UsageError("Colud not find allowed hash algorithms for {}"
                               .format(type(key)))

    # Pure enforces auto, and user selection is ignored
    if user_sha == 'auto' or is_pure:
        return USER_SHA_TO_ALG_AND_TLV[allowed[0]]

    if user_sha in allowed:
        return USER_SHA_TO_ALG_AND_TLV[user_sha]

    raise click.UsageError("Key {} can not be used with --sha {}; allowed sha are one of {}"
                           .format(key.sig_type(), user_sha, allowed))


class Image():

    def __init__(self, version=None, header_size=IMAGE_HEADER_SIZE,
                 pad_header=False, pad=False, confirm=False, align=1,
                 slot_size=0, max_sectors=DEFAULT_MAX_SECTORS,
                 overwrite_only=False, endian="little", load_addr=0,
                 rom_fixed=None, erased_val=None, save_enctlv=False,
                 security_counter=None, image_addr=0, kdf=None):

        if load_addr and rom_fixed:
            raise click.UsageError("Can not set rom_fixed and load_addr at the same time")

        self.version = version or versmod.decode_version("0")
        self.header_size = header_size
        self.pad_header = pad_header
        self.pad = pad
        self.confirm = confirm
        self.align = align
        self.slot_size = slot_size
        self.max_sectors = max_sectors
        self.overwrite_only = overwrite_only
        self.endian = endian
        self.base_addr = None
        self.load_addr = 0 if load_addr is None else load_addr
        self.rom_fixed = rom_fixed
        self.erased_val = 0xff if erased_val is None else int(erased_val, 0)
        self.payload = []
        self.enckey = None
        self.save_enctlv = save_enctlv
        self.enctlv_len = 0
        self.kdf_salt = None
        self.kdf_len = 48
        self.enc_nonce = bytes([0] * 16)
        self.image_addr = image_addr
        self.kdf = kdf.upper() if kdf else 'HKDF'

        if security_counter == 'auto':
            # Security counter has not been explicitly provided,
            # generate it from the version number
            self.security_counter = ((self.version.major << 24)
                                     + (self.version.minor << 16)
                                     + self.version.revision)
        else:
            self.security_counter = security_counter

    def __repr__(self):
        return "<Image version={}, header_size={}, security_counter={}, \
                base_addr={}, load_addr={}, align={}, slot_size={}, \
                max_sectors={}, overwrite_only={}, endian={} format={}, \
                payloadlen=0x{:x}>".format(
                    self.version,
                    self.header_size,
                    self.security_counter,
                    self.base_addr if self.base_addr is not None else "N/A",
                    self.load_addr,
                    self.align,
                    self.slot_size,
                    self.max_sectors,
                    self.overwrite_only,
                    self.endian,
                    self.__class__.__name__,
                    len(self.payload))

    @staticmethod
    def header_format(endian):
        return (endian +
                # type ImageHdr struct {
                'I' +     # Magic    uint32
                'I' +     # LoadAddr uint32
                'H' +     # HdrSz    uint16
                'H' +     # PTLVSz   uint16
                'I' +     # ImgSz    uint32
                'I' +     # Flags    uint32
                'BBHI' +  # Vers     ImageVersion
                'I'       # Pad1     uint32
                )  # }

    def load(self, path):
        """Load an image from a given file"""
        ext = os.path.splitext(path)[1][1:].lower()
        try:
            if ext == INTEL_HEX_EXT:
                ih = IntelHex(path)
                self.payload = ih.tobinarray()
                self.base_addr = ih.minaddr()
            else:
                with open(path, 'rb') as f:
                    self.payload = f.read()
        except FileNotFoundError:
            raise click.UsageError("Input file not found")

        # Add the image header if needed.
        if self.pad_header and self.header_size > 0:
            if self.base_addr:
                # Adjust base_addr for new header
                self.base_addr -= self.header_size
            self.payload = bytes([self.erased_val] * self.header_size) + \
                self.payload

        self.check_header()

    def save(self, path, hex_addr=None):
        """Save an image from a given file"""
        ext = os.path.splitext(path)[1][1:].lower()
        if ext == INTEL_HEX_EXT:
            # input was in binary format, but HEX needs to know the base addr
            if self.base_addr is None and hex_addr is None:
                raise click.UsageError("No address exists in input file "
                                       "neither was it provided by user")
            h = IntelHex()
            if hex_addr is not None:
                self.base_addr = hex_addr
            h.frombytes(bytes=self.payload, offset=self.base_addr)
            if self.pad:
                trailer_size = self._trailer_size(self.align, self.max_sectors,
                                                  self.overwrite_only,
                                                  self.enckey,
                                                  self.save_enctlv,
                                                  self.enctlv_len)
                trailer_addr = (self.base_addr + self.slot_size) - trailer_size
                padding_size = self.slot_size - (len(self.payload) + trailer_size)
                padding = bytearray([self.erased_val] * (padding_size + trailer_size - len(boot_magic)))
                if self.confirm and not self.overwrite_only:
                    padding[-MAX_ALIGN] = 0x01  # image_ok = 0x01
                padding += boot_magic
                h.puts(trailer_addr - padding_size, bytes(padding))
            h.tofile(path, 'hex')
        else:
            if self.pad:
                self.pad_to(self.slot_size)
            with open(path, 'wb') as f:
                f.write(self.payload)

    def check_header(self):
        if self.header_size > 0 and not self.pad_header:
            if any(v != 0 for v in self.payload[0:self.header_size]):
                raise click.UsageError("Header padding was not requested and "
                                       "image does not start with zeros")

    def check_trailer(self):
        if self.slot_size > 0:
            tsize = self._trailer_size(self.align, self.max_sectors,
                                       self.overwrite_only, self.enckey,
                                       self.save_enctlv, self.enctlv_len)
            padding = self.slot_size - (len(self.payload) + tsize)
            if padding < 0:
                msg = "Image size (0x{:x}) + trailer (0x{:x}) exceeds " \
                      "requested size 0x{:x}".format(
                          len(self.payload), tsize, self.slot_size)
                raise click.UsageError(msg)

    def key_derivation(self, name):
        """Return a KDF object depends on the key derivation function name"""
        if name == 'HKDF':
            return HKDF(
                algorithm=hashes.SHA256(), length=self.kdf_len,
                salt=self.kdf_salt, info=b'MCUBoot_ECIES_v1',
                backend=default_backend()
            )
        elif name == 'KBKDFCMAC':
            return KBKDFCMAC(
                algorithm=algorithms.AES,
                mode=Mode.CounterMode,
                length=self.kdf_len,
                rlen=4,
                llen=4,
                location=CounterLocation.BeforeFixed,
                label=b'MCUBoot_ECIES_v1',
                context=self.kdf_salt,
                fixed=None
            )
        else:
            raise ValueError(f"Invalid KDF type: {name}")

    def mac(self, key, name):
        """Return a MAC object depends on the key derivation function name"""
        if name == 'HKDF':
            return hmac.HMAC(
                key=key,
                algorithm=hashes.SHA256(),
                backend=default_backend()
            )
        elif name == 'KBKDFCMAC':
            return cmac.CMAC(algorithms.AES(key))
        else:
            raise ValueError(f"Invalid MAC type: {name}")

    def ecies_hkdf(self, enckey, plainkey):
        if isinstance(enckey, ecdsa.ECDSA256P1Public):
            newpk = ec.generate_private_key(ec.SECP256R1(), default_backend())
            shared = newpk.exchange(ec.ECDH(), enckey._get_public())
        else:
            newpk = X25519PrivateKey.generate()
            shared = newpk.exchange(enckey._get_public())

        if (self.kdf_salt is not None) and (self.image_addr > 0):
            self.kdf_salt = self.kdf_salt[:28] + self.image_addr.to_bytes(
                4, 'little')

        derived_key = self.key_derivation(self.kdf).derive(shared)

        if self.kdf_salt is not None:
            key_nonce = derived_key[48:64]
            self.enc_nonce = derived_key[64:76] + bytes([0] * 4)
        else:
            key_nonce = bytes([0] * 16)

        encryptor = Cipher(algorithms.AES(derived_key[:16]),
                           modes.CTR(key_nonce),
                           backend=default_backend()).encryptor()
        cipherkey = encryptor.update(plainkey) + encryptor.finalize()

        mac = self.mac(derived_key[16:48], self.kdf)
        mac.update(cipherkey)
        ciphermac = mac.finalize()

        if isinstance(enckey, ecdsa.ECDSA256P1Public):
            pubk = newpk.public_key().public_bytes(
                encoding=Encoding.X962,
                format=PublicFormat.UncompressedPoint)
        else:
            pubk = newpk.public_key().public_bytes(
                encoding=Encoding.Raw,
                format=PublicFormat.Raw)

        return cipherkey, ciphermac, pubk

    def create(self, key, public_key_format, enckey, dependencies=None,
               sw_type=None, custom_tlvs=None, use_random_iv=False,
               skip_tlv_info=False, encryptor=None):
        self.enckey = enckey

        # Check what hashing algorithm should be used
        if key is not None:
            hash_algorithm, hash_tlv = key_and_user_sha_to_alg_and_tlv(key, 'auto', is_pure=False)
        else:
            hash_algorithm = hashlib.sha256
            hash_tlv = "SHA256"

        if use_random_iv:
            self.kdf_salt = os.urandom(32)
            self.kdf_len += 16 * 2  # 48 for basic scheme + 16 * 2 for random IVs

        # Calculate the hash of the public key
        if key is not None:
            pub = key.get_public_bytes()
            sha = hash_algorithm()
            sha.update(pub)
            pubbytes = sha.digest()
        else:
            pubbytes = bytes(hash_algorithm().digest_size)

        protected_tlv_size = 0

        if self.security_counter is not None:
            # Size of the security counter TLV: header ('HH') + payload ('I')
            #                                   = 4 + 4 = 8 Bytes
            protected_tlv_size += TLV_SIZE + 4

        if sw_type is not None:
            if len(sw_type) > MAX_SW_TYPE_LENGTH:
                msg = "'{}' is too long ({} characters) for sw_type. Its " \
                      "maximum allowed length is 12 characters.".format(
                       sw_type, len(sw_type))
                raise click.UsageError(msg)

            image_version = (str(self.version.major) + '.'
                             + str(self.version.minor) + '.'
                             + str(self.version.revision))

            # The image hash is computed over the image header, the image
            # itself and the protected TLV area. However, the boot record TLV
            # (which is part of the protected area) should contain this hash
            # before it is even calculated. For this reason the script fills
            # this field with zeros and the bootloader will insert the right
            # value later.
            digest = bytes(hash_algorithm().digest_size)

            # Create CBOR encoded boot record
            boot_record = create_sw_component_data(sw_type, image_version,
                                                   hash_tlv, digest,
                                                   pubbytes)

            protected_tlv_size += TLV_SIZE + len(boot_record)

        if dependencies is not None:
            # Size of a Dependency TLV = Header ('HH') + Payload('IBBHI')
            # = 4 + 12 = 16 Bytes
            dependencies_num = len(dependencies[DEP_IMAGES_KEY])
            protected_tlv_size += (dependencies_num * 16)

        if custom_tlvs is not None and custom_tlvs.get('protected'):
            for value in custom_tlvs['protected'].values():
                protected_tlv_size += TLV_SIZE + len(value)

        if protected_tlv_size != 0:
            # Add the size of the TLV info header
            protected_tlv_size += TLV_INFO_SIZE

        # At this point the image is already on the payload
        #
        # This adds the padding if image is not aligned to the 16 Bytes
        # in encrypted mode
        if self.enckey is not None:
            pad_len = len(self.payload) % 16
            if pad_len > 0:
                pad_len = 16 - pad_len
                pad = self.erased_val.to_bytes(1, byteorder='big') * pad_len
                if isinstance(self.payload, bytes):
                    self.payload += pad
                else:
                    self.payload.extend(pad)

        # This adds the header to the payload as well
        self.add_header(enckey, protected_tlv_size)

        prot_tlv = TLV(self.endian, TLV_PROT_INFO_MAGIC)

        # Protected TLVs must be added first, because they are also included
        # in the hash calculation
        protected_tlv_off = None
        if protected_tlv_size != 0:

            e = STRUCT_ENDIAN_DICT[self.endian]

            if self.security_counter is not None:
                payload = struct.pack(e + 'I', self.security_counter)
                prot_tlv.add('SEC_CNT', payload)

            if sw_type is not None:
                prot_tlv.add('BOOT_RECORD', boot_record)

            if dependencies is not None:
                for i in range(dependencies_num):
                    payload = struct.pack(
                        e + 'B3x'+'BBHI',
                        int(dependencies[DEP_IMAGES_KEY][i]),
                        dependencies[DEP_VERSIONS_KEY][i].major,
                        dependencies[DEP_VERSIONS_KEY][i].minor,
                        dependencies[DEP_VERSIONS_KEY][i].revision,
                        dependencies[DEP_VERSIONS_KEY][i].build
                    )
                    prot_tlv.add('DEPENDENCY', payload)

            if custom_tlvs is not None and custom_tlvs['protected']:
                for tag, value in custom_tlvs['protected'].items():
                    prot_tlv.add(tag, value)

            protected_tlv_off = len(self.payload)
            self.payload += prot_tlv.get()

        tlv = TLV(self.endian)

        # Note that ecdsa wants to do the hashing itself, which means
        # we get to hash it twice.
        sha = hash_algorithm()
        sha.update(self.payload)
        digest = sha.digest()
        tlv.add(hash_tlv, digest)

        if key is not None:
            if public_key_format == 'hash':
                tlv.add('KEYHASH', pubbytes)
            else:
                tlv.add('PUBKEY', pub)

            # `sign` expects the full image payload (hashing done internally),
            # while `sign_digest` expects only the digest of the payload.
            # If the specified key is a public key, add empty signature TLV.
            if hasattr(key, 'sign'):
                sig = key.sign(bytes(self.payload))
                tlv.add(key.sig_tlv(), sig)
            elif hasattr(key, 'sign_digest'):
                sig = key.sign_digest(digest)
                tlv.add(key.sig_tlv(), sig)
            else:
                tlv.add(key.sig_tlv(), bytes(key.sig_len()))

        # At this point the image was hashed + signed, we can remove the
        # protected TLVs from the payload (will be re-added later)
        if protected_tlv_off is not None:
            self.payload = self.payload[:protected_tlv_off]

        if enckey is not None or encryptor:
            if encryptor:
                if not encryptor.plainkey:
                    encryptor.plainkey = os.urandom(16)
                plainkey = encryptor.plainkey
            else:
                plainkey = os.urandom(16)

            if isinstance(enckey, rsa.RSAPublic):
                cipherkey = enckey._get_public().encrypt(
                    plainkey, padding.OAEP(
                        mgf=padding.MGF1(algorithm=hashes.SHA256()),
                        algorithm=hashes.SHA256(),
                        label=None))
                self.enctlv_len = len(cipherkey)
                tlv.add('ENCRSA2048', cipherkey)
            elif isinstance(enckey, (ecdsa.ECDSA256P1Public,
                                     x25519.X25519Public)):
                cipherkey, mac, pubk = self.ecies_hkdf(enckey, plainkey)
                enctlv = pubk + mac + cipherkey
                if self.kdf_salt is not None:
                    enctlv += self.kdf_salt
                self.enctlv_len = len(enctlv)
                if isinstance(enckey, ecdsa.ECDSA256P1Public):
                    tlv.add('ENCEC256', enctlv)
                else:
                    tlv.add('ENCX25519', enctlv)
            elif isinstance(enckey, bytes):
                wrapped = keywrap.aes_key_wrap(enckey, plainkey)
                self.enctlv_len = len(wrapped)
                tlv.add('ENCKW128', wrapped)

            nonce = self.enc_nonce
            img = bytes(self.payload[self.header_size:])
            if encryptor is None:
                cipher = Cipher(algorithms.AES(plainkey), modes.CTR(nonce),
                                backend=default_backend())
                encryptor = cipher.encryptor()
                encdata = encryptor.update(img) + encryptor.finalize()
            else:
                encryptor.nonce = nonce
                encdata = encryptor.encrypt(img)
            self.payload[self.header_size:] = encdata

        self.payload += prot_tlv.get()

        if not skip_tlv_info:
            if custom_tlvs is not None and custom_tlvs.get('unprotected'):
                for tag, value in custom_tlvs['unprotected'].items():
                    tlv.add(tag, value)
            self.payload += tlv.get()

        self.check_trailer()

    def add_header(self, enckey, protected_tlv_size):
        """Install the image header."""

        if self.header_size > 0:
            flags = 0
            if enckey is not None:
                flags |= IMAGE_F['ENCRYPTED']
            if self.load_addr != 0:
                # Indicates that this image should be loaded into RAM
                # instead of run directly from flash.
                flags |= IMAGE_F['RAM_LOAD']
            if self.rom_fixed:
                flags |= IMAGE_F['ROM_FIXED']

            fmt = self.header_format(STRUCT_ENDIAN_DICT[self.endian])
            assert struct.calcsize(fmt) == IMAGE_HEADER_SIZE
            header = struct.pack(fmt,
                    IMAGE_MAGIC,
                    self.rom_fixed or self.load_addr,
                    self.header_size,
                    protected_tlv_size,  # TLV Info header + Protected TLVs
                    len(self.payload) - self.header_size,  # ImageSz
                    flags,
                    self.version.major,
                    self.version.minor or 0,
                    self.version.revision or 0,
                    self.version.build or 0,
                    int(format(self.erased_val, 'x') * 4, 16))  # Pad1

            self.payload = bytearray(self.payload)
            self.payload[:len(header)] = header

    def _trailer_size(self, write_size, max_sectors, overwrite_only, enckey,
                      save_enctlv, enctlv_len):
        # NOTE: should already be checked by the argument parser
        magic_size = 16
        if overwrite_only:
            return MAX_ALIGN * 2 + magic_size
        else:
            if write_size not in set([1, 2, 4, 8]):
                raise click.BadParameter("Invalid alignment: {}".format(
                    write_size))
            m = DEFAULT_MAX_SECTORS if max_sectors is None else max_sectors
            trailer = m * 3 * write_size  # status area
            if enckey is not None:
                if save_enctlv:
                    # TLV saved by the bootloader is aligned
                    keylen = (int((enctlv_len - 1) / MAX_ALIGN) + 1) * MAX_ALIGN
                else:
                    keylen = 16
                trailer += keylen * 2  # encryption keys
            trailer += MAX_ALIGN * 4  # image_ok/copy_done/swap_info/swap_size
            trailer += magic_size
            return trailer

    def pad_to(self, size):
        """Pad the image to the given size, with the given flash alignment."""
        tsize = self._trailer_size(self.align, self.max_sectors,
                                   self.overwrite_only, self.enckey,
                                   self.save_enctlv, self.enctlv_len)
        padding = size - (len(self.payload) + tsize)
        pbytes = bytearray([self.erased_val] * padding)
        pbytes += bytearray([self.erased_val] * (tsize - len(boot_magic)))
        if self.confirm and not self.overwrite_only:
            pbytes[-MAX_ALIGN] = 0x01  # image_ok = 0x01
        pbytes += boot_magic
        self.payload += pbytes

    @staticmethod
    def verify(imgfile, key):
        with open(imgfile, "rb") as f:
            b = f.read()

        magic, _, header_size, _, img_size = struct.unpack('IIHHI', b[:16])
        version = struct.unpack('BBHI', b[20:28])

        if magic != IMAGE_MAGIC:
            return VerifyResult.INVALID_MAGIC, None, None

        tlv_off = header_size + img_size
        tlv_info = b[tlv_off:tlv_off+TLV_INFO_SIZE]
        magic, tlv_tot = struct.unpack('HH', tlv_info)
        if magic == TLV_PROT_INFO_MAGIC:
            tlv_off += tlv_tot
            tlv_info = b[tlv_off:tlv_off+TLV_INFO_SIZE]
            magic, tlv_tot = struct.unpack('HH', tlv_info)

        if magic != TLV_INFO_MAGIC:
            return VerifyResult.INVALID_TLV_INFO_MAGIC, None, None

        if isinstance(key, ecdsa.ECDSA521P1Public):
            sha = hashlib.sha512()
            hash_tlv = "SHA512"
        elif isinstance(key, ecdsa.ECDSA384P1Public):
            sha = hashlib.sha384()
            hash_tlv = "SHA384"
        else:
            sha = hashlib.sha256()
            hash_tlv = "SHA256"

        prot_tlv_size = tlv_off
        sha.update(b[:prot_tlv_size])
        digest = sha.digest()

        tlv_end = tlv_off + tlv_tot
        tlv_off += TLV_INFO_SIZE  # skip tlv info
        while tlv_off < tlv_end:
            tlv = b[tlv_off:tlv_off+TLV_SIZE]
            tlv_type, _, tlv_len = struct.unpack('BBH', tlv)
            if tlv_type == TLV_VALUES[hash_tlv]:
                off = tlv_off + TLV_SIZE
                if digest == b[off:off+tlv_len]:
                    if key is None:
                        return VerifyResult.OK, version, digest
                else:
                    return VerifyResult.INVALID_HASH, None, None
            elif key is not None and tlv_type == TLV_VALUES[key.sig_tlv()]:
                off = tlv_off + TLV_SIZE
                tlv_sig = b[off:off+tlv_len]
                payload = b[:prot_tlv_size]
                try:
                    if hasattr(key, 'verify'):
                        key.verify(tlv_sig, payload)
                    else:
                        key.verify_digest(tlv_sig, digest)
                    return VerifyResult.OK, version, digest
                except InvalidSignature:
                    # continue to next TLV
                    pass
            tlv_off += TLV_SIZE + tlv_len
        return VerifyResult.INVALID_SIGNATURE, None, None
