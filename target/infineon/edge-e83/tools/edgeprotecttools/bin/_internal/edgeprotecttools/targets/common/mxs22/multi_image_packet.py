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
import hashlib
import json
import logging
import os

from cbor import cbor
from intelhex import IntelHex

from ....execute.image_signing import SplitTool, MultiImage
from .key_validator_mxs22 import KeyValidatorMXS22

logger = logging.getLogger(__name__)


class MultiImageMXS22(MultiImage):
    """
    Creates a multiple images COSE packet
    """

    def __init__(self, input_path, output, **kwargs):
        super().__init__(input_path, output, **kwargs)
        self._template = kwargs.get('template')

    @property
    def template(self):
        """Additional image data template path"""
        return self._template

    def collect_data(self):
        """Collects data from input file"""
        try:
            segments = SplitTool.split(self.input_path)
        except UnicodeDecodeError:
            logger.error(
                'Unsupported image format %s', os.path.abspath(self.input_path))
            return False

        if self.template:
            data = self.image_template(segments)
        else:
            data = self.image_no_template(segments)

        return data

    def image_template(self, segments):
        """Creates image package according to the template data
        @param segments: List of IntelHex objects containing hex segments
        """
        with open(self.template, 'r', encoding='utf-8') as f:
            meta_data = json.load(f)
        meta = meta_data.get('meta')
        addresses = self.meta_addresses(meta)
        if len(segments) < len(addresses):
            logger.debug('A .hex image without gap is used')
            segments = self.process_no_gap_img(segments, addresses)
        if len(segments) != len(addresses):
            raise ValueError('The number of images does not correspond '
                             'to the meta address fields')
        image_info = []
        for item in meta:
            image_info.extend(self.process_meta_item(item, segments))

        packet = [cbor.dumps(image_info)]
        for addr_itm in addresses:
            image = self.select_segment_bytes(segments, addr_itm)
            packet.append(image)

        return packet

    @staticmethod
    def process_no_gap_img(ihex_img, addr_list):
        """Creates a list of IntelHex objects based on a list of
        template addresses
        """
        addr_list.sort()
        segments = []
        for itm in ihex_img:
            hex_max_addr = itm.maxaddr()
            hex_addresses = itm.addresses()
            for i in addr_list:
                if i in hex_addresses:
                    if i == addr_list[-1] or addr_list[addr_list.index(i) + 1] \
                            > hex_max_addr:
                        img = itm.gets(i, hex_max_addr - i + 1)
                    else:
                        img = itm.gets(i, addr_list[addr_list.index(i) + 1] - i)
                    ih = IntelHex()
                    ih.frombytes(bytearray(img), i)
                    segments.append(ih)

        return segments

    @staticmethod
    def image_no_template(segments):
        """Creates image package without template
        @param segments: List of IntelHex objects containing hex segments
        """
        packet = []
        for seg in segments:
            packet.append({
                'addr': seg.minaddr(),
                'img': seg.tobinarray().tobytes()
            })
        return packet

    def process_meta_item(self, item, segments):
        """Processes item of the template 'meta' array
        @param item: Item of the 'meta' array in the template
        @param segments: List of IntelHex objects containing hex segments
        """
        meta = {}
        edc = {}
        for field in item:
            if field in ('addr', 'nv_counter', 'nv_counter_addr_nvm',
                         'nv_counter_addr_otp', 'hash_addr', 'l1_ver_img_idx',
                         'img_info_offset'):
                meta.update(self.process_field(item, field))
            elif field == 'hash':
                meta.update(
                    self.process_hash(item.get('hash'), meta.get('addr'),
                                      segments))
            elif field == 'edc_addr':
                edc.update(self.process_field(item, field))
            elif field == 'iv':
                meta.update(self.process_iv(item, field))
            else:
                meta.update({field: item.get(field)})
        image_info = [meta]
        if edc:
            image_info.append(edc)
        return image_info

    def process_hash(self, img_hash, img_addr, segments):
        """Computes image hash if hash field is 'auto' or algorithm specified,
        or converts to bytes array
        @param img_hash: Image hash value
        @param img_addr: Image address
        @param segments: List of IntelHex objects containing hex segments
        """
        if img_hash in ('auto', 'sha256'):
            img = self.select_segment_bytes(segments, img_addr)
            img_hash = hashlib.sha256(img)
            return {'hash': img_hash.digest()}
        if img_hash == 'sha384':
            img = self.select_segment_bytes(segments, img_addr)
            img_hash = hashlib.sha384(img)
            return {'hash': img_hash.digest()}
        if img_hash == 'sha512':
            img = self.select_segment_bytes(segments, img_addr)
            img_hash = hashlib.sha512(img)
            return {'hash': img_hash.digest()}
        return {'hash': bytes.fromhex(img_hash)}

    @staticmethod
    def process_field(meta_item, field):
        """Converts field name and value to the CBOR packet format"""
        data = meta_item.get(field)
        if data is not None:
            if field == 'nv_counter':
                field = 'cnt'
            elif field == 'edc_addr':
                field = 'addr'
            return {field: int(str(data), 0)}
        raise ValueError(f"The '{field}' field is empty")

    def process_iv(self, item, field):
        """Processes IV field from the template item"""
        iv = item.get(field)
        if iv is not None:
            try:
                with open(os.path.join(os.path.dirname(self.input_path), iv),
                          'rb') as f:
                    data = f.read()
            except (FileNotFoundError, OSError, ValueError):
                try:
                    data = bytes.fromhex(iv)
                except ValueError as e:
                    raise ValueError(
                        f"Error parsing data: '{field}'"
                    ) from e
            return {'iv': data}
        raise ValueError(f"The '{field}' field is empty")

    @staticmethod
    def meta_addresses(metadata):
        """Creates address list based on template"""
        addresses = []
        for item in metadata:
            for field in item:
                if field in ('addr', 'edc_addr'):
                    addr = item.get(field)
                    if addr:
                        addresses.append(int(str(addr), 0))
        return addresses

    @staticmethod
    def select_segment_bytes(segments, addr):
        """Selects image from list if IntelHex objects by the address
        @param segments: List of IntelHex objects containing hex segments
        @param addr: Segment address to select
        @return Segment bytes
        """
        for seg in segments:
            if seg.minaddr() == addr:
                return seg.tobinarray().tobytes()
        raise ValueError(f"No image with min address '{hex(addr)}' found")

    def validate_args(self):
        """Validates arguments"""
        if self.key:
            KeyValidatorMXS22().validate_private_key(self.key)
