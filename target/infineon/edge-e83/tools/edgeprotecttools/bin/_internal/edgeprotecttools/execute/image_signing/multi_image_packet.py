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

from cbor import cbor
from intelhex import IntelHex

from ...core.cose import Cose
from ...core.key_validator import KeyValidator


logger = logging.getLogger(__name__)


class MultiImage:
    """
    Creates a multiple images COSE packet
    """

    def __init__(self, input_path, output, **kwargs):
        self._input_path = input_path
        self._output = output
        self._algorithm = kwargs.get('algorithm')
        self._key = kwargs.get('key')
        self._kid = kwargs.get('kid')
        self._signature = kwargs.get('signature')
        self._segments = kwargs.get('segments')
        self._padding = kwargs.get('erased_val', 0)
        self._add_size = kwargs.get('add_size', True)
        if self._padding:
            self._padding = int(str(self._padding), 0)
            if not 0 <= self._padding <= 255:
                raise ValueError('Padding must be within range [0, 255]')

    @property
    def input_path(self):
        """Input file"""
        return self._input_path

    @property
    def output(self):
        """Output file"""
        return self._output

    @property
    def algorithm(self):
        """Signature algorithm"""
        return self._algorithm

    @property
    def key(self):
        """Private key path"""
        return self._key

    @property
    def kid(self):
        """Key ID"""
        return self._kid

    @property
    def signature(self):
        """Signature path"""
        return self._signature

    @property
    def segments(self):
        """Pairs of segment start address and size to include"""
        return self._segments

    @property
    def padding(self):
        """Value to pad missing parts in segments"""
        return self._padding

    @property
    def add_size(self):
        """Whether to add size to the beginning of the packet"""
        return self._add_size

    def create(self):
        """Creates a multi-image COSE packet
        @return: COSE multi-image packet
        """

        if self.signature:
            packet = self.add_signature(self.input_path,
                                        self.algorithm,
                                        self.signature)
        else:
            self.validate_args()
            data = self.collect_data()
            cbor_data = cbor.dumps(data)
            packet = self.create_packet(cbor_data)

        if self.output:
            self.save_packet(packet, self.output)

        return packet

    def collect_data(self):
        """Collects data from input file"""

        ih = IntelHex(self.input_path)
        ih.padding = self.padding

        ih_segments = []

        for segment in self.segments:
            start, size = list(map(lambda x: int(str(x), 0), segment))

            ih_segment = IntelHex()
            ih_segment.frombytes(ih.tobinstr(start=start, size=size), start)
            ih_segment.start_addr = start
            ih_segments.append(ih_segment)

        data = [
            {
                "addr": seg.start_addr,
                "img": seg.tobinarray().tobytes()
            } for seg in ih_segments
        ]

        return data

    def add_signature(self, input_path, algorithm, signature) -> bytes:
        """
        Adds signature to the unsigned packet
        @param input_path: Path to the unsigned packet
        @param algorithm: Signature algorithm used for signing on HSM
        @param signature: Signature to add
        @return: Signed COSE multi-image packet
        """
        if not algorithm:
            raise ValueError('Algorithm must be specified '
                             'when adding signature')
        with open(input_path, 'rb') as f:
            cbor_data = f.read()
        with open(signature, 'rb') as f:
            sig = f.read()
        signed = Cose.add_signature1(cbor_data, sig, algorithm, kid=self.kid)
        packet = signed
        if self.add_size:
            length = len(signed).to_bytes(4, byteorder='little')
            packet = length + packet
            logger.info('4-byte packet size header added: %s (%s bytes)',
                        length.hex(), len(signed))

        return packet

    def create_packet(self, cbor_data):
        """
        Creates COSE packet
        @param cbor_data: Binary payload
        @return: COSE packet
        """
        if self.key:
            packet = self.create_signed(cbor_data, self.key)
        elif self.algorithm:
            packet = self.create_unsigned(cbor_data, self.algorithm)
        else:
            raise ValueError('Either key or algorithm must be specified')

        return packet

    @staticmethod
    def create_unsigned(cbor_data: bytes, algorithm) -> bytes:
        """
        Creates packet for signing on HSM
        @param cbor_data: Binary payload
        @param algorithm: Signature algorithm used for signing on HSM
        @return: Unsigned COSE multi-image packet
        """
        return Cose.prepare_hsm_sign1(cbor_data, algorithm)

    def create_signed(self, cbor_data: bytes, key) -> bytes:
        """
        Creates signed packet
        @param cbor_data: Binary payload
        @param key: Private key
        @return: Signed COSE multi-image packet
        """
        cose_signed = Cose.cose_sign1(cbor_data, key, kid=self.kid)
        packet = cose_signed
        if self.add_size:
            length = len(cose_signed).to_bytes(4, byteorder='little')
            packet = length + packet
            logger.info('4-byte packet size header added: %s (%s bytes)',
                        length.hex(), len(cose_signed))
        return packet

    @staticmethod
    def save_packet(packet: bytes, output):
        """
        Saves packet
        @param packet: COSE packet to save
        @param output: Output path
        """
        Cose.dump(packet, output)
        logger.info("Multi-image COSE packet created '%s'",
                    os.path.abspath(output))

    def validate_args(self):
        """Validates arguments"""
        if self.key:
            KeyValidator().validate_private_key(self.key)

        if not self.segments or len(self.segments) < 2:
            raise ValueError('At least 2 segments must be specified')

        for segment in self.segments:
            if len(segment) != 2:
                raise ValueError('Invalid segment format')

            for itm in segment:
                try:
                    int(str(itm), 0)
                except ValueError as e:
                    raise ValueError('Invalid segment format') from e
