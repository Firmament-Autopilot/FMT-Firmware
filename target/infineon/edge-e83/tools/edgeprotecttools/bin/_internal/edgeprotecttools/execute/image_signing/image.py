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
import pathlib
import struct
import logging
from typing import List

from cryptography.exceptions import InvalidSignature
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import ec, rsa, padding, utils
from intelhex import IntelHex

from ..imgtool.image import (
    Image as ImgtoolImage,
    STRUCT_ENDIAN_DICT,
    IMAGE_MAGIC,
    TLV_VALUES,
    TLV_PROT_INFO_MAGIC,
    TLV_INFO_MAGIC,
    TLV_SIZE,
    TLV_INFO_SIZE
)
from ..imgtool.version import SemiSemVersion

logger = logging.getLogger(__name__)


class TLV:
    """A representation of TLV object"""

    def __init__(self, tag, value):
        self.tag = tag
        self.length = len(value)
        self.value = value

    def tlv_bytes(self, endian='little'):
        """Gets TLV bytes"""
        tlv_bytes = b''
        tlv_bytes += self.tag.to_bytes(2, byteorder=endian)
        tlv_bytes += self.length.to_bytes(2, byteorder=endian)
        tlv_bytes += self.value
        return tlv_bytes


class Header:
    """A representation of MCUboot image header"""

    def __init__(self, endian='little'):
        self.endian = endian
        self.magic = 0
        self.load_addr = 0
        self.header_size = 0
        self.ptlv_size = 0
        self.img_size = 0
        self.flags = 0
        self.pad1 = 0
        self.img_version = None
        self.padding = b''
        self._fmt = ImgtoolImage.header_format(STRUCT_ENDIAN_DICT[endian])

    def header_bytes(self):
        """Gets header bytes"""
        hdr = b''
        hdr += self.magic.to_bytes(4, byteorder=self.endian)
        hdr += self.load_addr.to_bytes(4, byteorder=self.endian)
        hdr += self.header_size.to_bytes(2, byteorder=self.endian)
        hdr += self.ptlv_size.to_bytes(2, byteorder=self.endian)
        hdr += self.img_size.to_bytes(4, byteorder=self.endian)
        hdr += self.flags.to_bytes(4, byteorder=self.endian)
        hdr += int(self.img_version.major).to_bytes(1, byteorder=self.endian)
        hdr += int(self.img_version.minor).to_bytes(1, byteorder=self.endian)
        hdr += int(self.img_version.revision).to_bytes(2, byteorder=self.endian)
        hdr += int(self.img_version.build).to_bytes(4, byteorder=self.endian)
        hdr += self.pad1.to_bytes(4, byteorder=self.endian)
        hdr += self.padding
        return hdr

    def decompose(self, header):
        """Decomposes header into attributes"""
        header_data_size = struct.calcsize(self._fmt)
        (
            self.magic,
            self.load_addr,
            self.header_size,
            self.ptlv_size,
            self.img_size,
            self.flags,
            ver_maj,
            ver_min,
            ver_rev,
            ver_build,
            self.pad1,
        ) = struct.unpack(self._fmt, header[:header_data_size])
        self.img_version = SemiSemVersion(ver_maj, ver_min, ver_rev, ver_build)
        self.padding = header[header_data_size:]


class Image:
    """A representation of the MCUboot image"""
    def __init__(self, image_path, endian='little'):
        self.image_path = image_path
        self._data = b''
        self._header = b''
        self.body = b''
        self._protected_tlv = []
        self._tlv = []
        self.trailer = b''
        self.protected_tlv_length = 0
        self.tlv_length = 0
        self.endian = endian
        self.header_size = 0
        self.body_size = 0
        self.magic = 0
        self.base_addr = 0
        self.header = Header()
        self._load()

    @property
    def has_metadata(self):
        """Indicates whether this is MCUboot format image"""
        return self.magic == IMAGE_MAGIC

    @property
    def is_signed(self):
        """Indicates whether the image has been already signed"""
        for tlv in self._tlv:
            if tlv.tag in [TLV_VALUES['RSA2048'],
                           TLV_VALUES['RSA3072'],
                           TLV_VALUES['RSA4096'],
                           TLV_VALUES['ECDSASIG']]:
                return True
        return False

    @property
    def tlv(self) -> List[TLV]:
        """Gets list of unprotected TLVs"""
        return self._tlv

    @property
    def protected_tlv(self) -> List[TLV]:
        """Gets list of protected TLVs"""
        return self._protected_tlv

    @property
    def tlv_bytes(self):
        """Gets unprotected TLVs bytes"""
        tlv_bytes = b''
        if self.tlv_length > 0:
            tlv_bytes += TLV_INFO_MAGIC.to_bytes(2, byteorder=self.endian)
            tlv_bytes += self.tlv_length.to_bytes(2, byteorder=self.endian)
            for tlv in self._tlv:
                tlv_bytes += tlv.tlv_bytes(endian=self.endian)
        return tlv_bytes

    @property
    def protected_tlv_bytes(self):
        """Gets protected TLVs bytes"""
        tlv_bytes = b''
        if self.protected_tlv_length > 0:
            tlv_bytes += TLV_PROT_INFO_MAGIC.to_bytes(2, byteorder=self.endian)
            tlv_bytes += self.protected_tlv_length.to_bytes(
                2, byteorder=self.endian)
            for tlv in self._protected_tlv:
                tlv_bytes += tlv.tlv_bytes(endian=self.endian)
        return tlv_bytes

    def add_tlv(self, tlv: TLV):
        """Adds unprotected TLV to image"""
        self._tlv.append(tlv)
        if self.tlv_length == 0:
            self.tlv_length = TLV_INFO_SIZE
        self.tlv_length += TLV_INFO_SIZE + tlv.length

    def remove_tlv(self, tag):
        """Removes unprotected TLV"""
        for tlv in self._tlv:
            if tlv.tag == tag:
                self._tlv.remove(tlv)
                self.tlv_length -= TLV_INFO_SIZE + tlv.length
                if not self._tlv:
                    self.tlv_length = 0
                break

    def tlv_by_tag(self, tag):
        """Gets unprotected TLV by tag"""
        for tlv in self._tlv:
            if tlv.tag == tag:
                return tlv
        return None

    def add_protected_tlv(self, tlv: TLV):
        """Adds protected TLV to image"""
        self._protected_tlv.append(tlv)
        self.protected_tlv_length += TLV_INFO_SIZE + tlv.length
        self.header.ptlv_size = self.protected_tlv_length

    def protected_tlv_by_tag(self, tag):
        """Gets protected TLV by tag"""
        for tlv in self._protected_tlv:
            if tlv.tag == tag:
                return tlv
        return None

    @property
    def payload(self):
        """Gets a part of the image that has to be signed"""
        return self.header.header_bytes() + self.body + self.protected_tlv_bytes

    @property
    def data(self):
        """Gets image bytes"""
        return self.payload + self.tlv_bytes + self.trailer

    @property
    def size(self):
        """Gets the entire image size"""
        return len(self.data)

    def is_upgrade(self):
        """Checks whether the image is for the upgrade slot"""
        upgrade_img_magic = bytes(
            [0x77, 0xC2, 0x95, 0xF3, 0x60, 0xD2, 0xEF, 0x7F,
             0x35, 0x52, 0x50, 0x0F, 0x2C, 0xB6, 0x79, 0x80])
        return self.data[-len(upgrade_img_magic):] == upgrade_img_magic

    def _load(self):
        if isinstance(self.image_path, (bytearray, bytes)):
            self._data = self.image_path
        else:
            ext = pathlib.Path(self.image_path).suffix
            if ext == ".hex":
                ih = IntelHex(self.image_path)
                self.base_addr = ih.minaddr()
                self._data = bytes(ih.tobinarray())
            else:
                with open(self.image_path, 'rb') as f:
                    self._data = f.read()
        self._decompose()

    def _decompose(self):
        """Decomposes image into header, body, protected, and
        unprotected TLVs
        """
        self.magic, _, self.header_size, _, self.body_size = struct.unpack(
            STRUCT_ENDIAN_DICT[self.endian] + 'IIHHI', self._data[:16])

        if self.has_metadata:
            self._header = self._data[:self.header_size]
            self.header.decompose(self._header)
            self.body = self._data[
                        self.header_size:self.body_size + self.header_size]

            tlv_offset = self.header_size + self.body_size

            if len(self._data[tlv_offset:]) > TLV_INFO_SIZE:
                self._protected_tlv, self.protected_tlv_length = \
                    self._parse_tlv_block(tlv_offset, TLV_PROT_INFO_MAGIC)
                tlv_offset += self.protected_tlv_length

            if len(self._data[tlv_offset:]) > TLV_INFO_SIZE:
                self._tlv, self.tlv_length = self._parse_tlv_block(
                    tlv_offset, TLV_INFO_MAGIC)
                tlv_offset += self.tlv_length

            self.trailer = self._data[tlv_offset:]

    def _parse_tlv_block(self, tlv_offset, magic):
        """Parses TLV block"""
        tlv = []
        tlv_length = 0
        endian = STRUCT_ENDIAN_DICT[self.endian]
        beg = tlv_offset
        end = tlv_offset + 2
        tlv_magic = struct.unpack(endian + 'H', self._data[beg:end])[0]
        if tlv_magic == magic:
            beg = end
            end += 2
            tlv_length = struct.unpack(endian + 'H', self._data[beg:end])[0]
            tlv = self._get_tlv(end, tlv_length - TLV_INFO_SIZE)
        return tlv, tlv_length

    def _get_tlv(self, start_addr, length) -> List[TLV]:
        """Gets array of TLV objects"""
        tlv_info = []
        tlv_end = start_addr + length
        while start_addr < tlv_end:
            tlv = self._data[start_addr:start_addr + TLV_SIZE]
            tlv_tag, tlv_length = struct.unpack(
                STRUCT_ENDIAN_DICT[self.endian] + 'HH', tlv)
            start_addr += TLV_INFO_SIZE
            tlv_value = self._data[start_addr:start_addr + tlv_length]
            tlv_obj = TLV(tlv_tag, tlv_value)
            tlv_info.append(tlv_obj)
            start_addr += tlv_length
        return tlv_info

    def verify(self, key):
        """Verifies image with the key"""

        try:
            if isinstance(key, ec.EllipticCurvePublicKey):
                logger.debug('Using public key of type ECDSA')
                self._verify_ec_signature(key)
            elif isinstance(key, rsa.RSAPublicKey):
                logger.debug('Using public key of type RSA')
                self._verify_rsa_signature(key)
            else:
                raise ValueError('Unsupported key algorithm')
        except InvalidSignature:
            return False
        else:
            return True

    def _verify_ec_signature(self, key):
        """Verifies image with the ECDSA key"""
        try:
            sig = [x for x in self.tlv if x.tag == TLV_VALUES['ECDSASIG']][0]
        except IndexError as e:
            raise LookupError(
                f"Cannot find ECDSA signature in '{self.image_path}'") from e
        sig = bytes(sig.value)
        if len(sig) in (64, 96, 132):
            sig_len = len(sig) // 2
            r = int.from_bytes(sig[:sig_len], 'big')
            s = int.from_bytes(sig[sig_len:], 'big')
            sig = utils.encode_dss_signature(r, s)

        if key.key_size == 256:
            hash_algorithm = hashes.SHA256()
        elif key.key_size == 384:
            hash_algorithm = hashes.SHA384()
        elif key.key_size == 521:
            hash_algorithm = hashes.SHA512()
        else:
            raise ValueError(f'Unsupported key length {key.key_size}')
        key.verify(sig, self.payload, ec.ECDSA(hash_algorithm))

    def _verify_rsa_signature(self, key):
        """Verifies image with the RSA key"""
        try:
            sig = [x for x in self.tlv if x.tag == TLV_VALUES['RSA2048']][0]
        except IndexError as e:
            raise LookupError(
                f"Cannot find RSA signature in '{self.image_path}'") from e
        sig = bytes(sig.value)
        key.verify(sig, self.payload,
                   padding.PSS(
                       mgf=padding.MGF1(hashes.SHA256()),
                       salt_length=32
                   ),
                   hashes.SHA256())
