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

import cbor

from .enums import CoseSign1Packet
from ....core.cose import Cose


class PacketBuilder:
    """A class for generating CBOR provisioning packet"""

    def __init__(self, policy_parser, asset_map):
        self.cbor_fields = {}
        self.policy_parser = policy_parser
        self.asset_map = asset_map

    def build_signed(self, key_path, **kwargs):
        """Builds a signed provisioning packet based on policy type
        @param key_path: A path to the private key
        @param kwargs:
            :kid: Key ID
        @return: CBOR packet with unprotected and protected parts
        """
        map_id, unprotected, b_payload = self._cose_headers(**kwargs)
        protected = Cose.cose_sign1(b_payload, key_path, kid=kwargs.get('kid'))
        packet = {map_id: unprotected}
        cose_packet_id = kwargs.get(
            'cose_packet_id',
            CoseSign1Packet.COSE_PACKET_ID
        )
        packet[map_id][cose_packet_id] = protected
        packet = cbor.dumps(packet)
        return packet

    def build_cose_sign1(self, key_path, **kwargs):
        """Builds a signed cose_sign1 packet based on policy type
        @param key_path: A path to the private key
        @param kwargs:
            :kid: Key ID
        @return: CBOR packet with unprotected and protected parts
        """
        _, _, b_payload = self._cose_headers(**kwargs)
        packet = Cose.cose_sign1(b_payload, key_path, kid=kwargs.get('kid'))
        return packet

    def build_unsigned(self, **kwargs):
        """Builds a packet to be signed manually
        @param kwargs:
            :kid: Key ID
        @return: Data to be signed manually
        """
        _, _, b_payload = self._cose_headers(**kwargs)
        b_protected = cbor.dumps({1: -7})
        kid = kwargs.get('kid')
        b_kid = str(kid).encode(encoding='utf-8') if kid else b''
        sig_structure = ['Signature1', b_protected, b_kid, b_payload]
        return cbor.dumps(sig_structure)

    def build_add_signature(self, signature, **kwargs):
        """Builds a provisioning packet based on policy type and adds
        a signature to its COSE_Sign1 structure
        @param signature: Path to file or hex string containing signature
        @param kwargs:
            :kid: Key ID
        @return: CBOR packet with unprotected and protected parts
        """
        map_id, unprotected, b_payload = self._cose_headers(**kwargs)
        b_protected = cbor.dumps({1: -7})
        kid = kwargs.get('kid')
        b_kid = str(kid).encode(encoding='utf-8') if kid else {}
        b_signature = self._signature_bytes(signature)
        tag = cbor.Tag(18, [b_protected, b_kid, b_payload, b_signature])
        packet = {map_id: unprotected}
        cose_packet_id = kwargs.get(
            'cose_packet_id',
            CoseSign1Packet.COSE_PACKET_ID
        )
        packet[map_id][cose_packet_id] = cbor.dumps(tag)
        packet = cbor.dumps(packet)
        return packet

    def build_cose_sign1_add_signature(self, signature, **kwargs):
        """Builds a provisioning packet based on policy type and adds
        a signature to its COSE_Sign1 structure
        @param signature: Path to file or hex string containing signature
        @param kwargs:
            :kid: Key ID
        @return: CBOR packet with unprotected and protected parts
        """
        _, _, b_payload = self._cose_headers(**kwargs)
        b_protected = cbor.dumps({1: -7})
        kid = kwargs.get('kid')
        b_kid = str(kid).encode(encoding='utf-8') if kid else {}
        b_signature = self._signature_bytes(signature)
        tag = cbor.Tag(18, [b_protected, b_kid, b_payload, b_signature])
        packet = cbor.dumps(tag)
        return packet

    def build_unsigned_packet(self, **kwargs):
        """Builds a CBOR provisioning packet
        @return: CBOR packet
        """
        map_id, unprotected, _ = self._cose_headers(**kwargs)
        packet = {map_id: unprotected}
        packet = cbor.dumps(packet)
        return packet

    def verify_map(self, data, key_path, kid=None):
        """Verifies CBOR map COSE_Sign1 signature
        @param data: COSE_Sign1 data
        @param key_path: Verification ke path
        @param kid: Key ID
        @return: True if verified, otherwise False
        """
        data = cbor.loads(data)
        cbor_packet_id = next(iter(data))
        cose_sign1 = data[cbor_packet_id][CoseSign1Packet.COSE_PACKET_ID]
        return Cose.verify(cose_sign1, key_path, kid=kid)

    def _cose_headers(self, **kwargs):
        """Gets COSE_Sign1 parts common for all ways of the
        packet building - unprotected and payload. The protected part is
        created differently for the signed and unsigned packets"""
        map_id, unprotected_map, protected_map, cbor_blobs = self.asset_map.get(
            self.policy_parser, **kwargs)
        payload = self._cose_payload(protected_map, cbor_blobs=cbor_blobs)
        for section in self.policy_parser.custom_data_sections():
            payload.update(section)
        b_payload = cbor.dumps(payload)
        unprotected = self._unprotected_data(unprotected_map)
        return map_id, unprotected, b_payload

    @staticmethod
    def _unprotected_data(assets):
        """Gets an unprotected part of the provisioning packet"""
        top_level = {}
        for val in assets.values():
            if val.get('value') is None:
                continue
            if val.get('id') is None:
                top_level = val['value']
                break
            top_level[val['id']] = val['value']
        return top_level

    def _cose_payload(self, assets, cbor_blobs=None):
        """Gets a dictionary containing payload for COSE_Sign1 data object
        @param assets: Dictionary which is a result of the asset map
        @param cbor_blobs: List of asset IDs, which has to be represented
               as a CBOR blob
        @return: The COSE_Sign1 payload
        """
        payload = {}
        for val in assets.values():
            if val['value'] is None:
                continue

            if 'parent' in val:
                if val['parent'] in payload:
                    payload[val['parent']].update({val['id']: val['value']})
                else:
                    payload[val['parent']] = {val['id']: val['value']}
            else:
                payload[val['id']] = val['value']

        if cbor_blobs:
            for key in payload.copy():
                if key in cbor_blobs:
                    payload[key] = cbor.dumps(payload[key])
        return payload

    @staticmethod
    def _signature_bytes(signature):
        """Gets signature bytes from either a file or a hex string"""
        if os.path.isfile(signature):
            with open(signature, 'rb') as f:
                sig = f.read()
        else:
            sig = bytes.fromhex(signature)
        return sig
