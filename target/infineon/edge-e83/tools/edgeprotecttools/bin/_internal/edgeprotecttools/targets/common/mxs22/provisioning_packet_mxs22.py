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

from .packet_builder import PacketBuilder
from .key_validator_mxs22 import KeyValidatorMXS22
from .ram_app_pkg_mxs22 import RamAppPackageMXS22
from ..flow_parser import FlowParser
from ....core.provisioning_flows.application import Application
from ....core.strategy_context import ProvisioningPacketStrategy

logger = logging.getLogger(__name__)


class ProvisioningPacketMXS22(ProvisioningPacketStrategy):
    """Provisioning packet generator for MXS22 targets"""

    def __init__(self, policy_parser, asset_map):
        self.policy_parser = policy_parser
        self.packet_builder = PacketBuilder(self.policy_parser, asset_map)

    def create(self, target, **kwargs):
        """Creates RAM applications input parameters binary packets
        @param target: The target packet is intended for
        @param kwargs:
            :kid: Key ID
            :key_path: Path to the key to sign the packet
            :signature: Path to the file containing signature. Can be
                used instead of signing a packet with a key
            :output: A file where to save the packet
            :revoke: Path to the IFX key revocation certificate
        @return: True if packet created successfully, otherwise False.
        """
        if kwargs.get('integrity_cert'):
            kwargs.update({'flow_name': 'device_integrity_exam'})
        flow_name = kwargs.get('flow_name')
        key_path = kwargs.get('key_path')
        signature = kwargs.get('signature')
        output = kwargs.get('output')
        if output:
            output = os.path.abspath(output)
        else:
            test_pkg_type = kwargs.get('testapps')
            app = self._get_app_data(target, test_pkg_type, flow_name)
            output = app.in_params_path

        if key_path and signature:
            raise ValueError(
                "'key_path' and 'signature' are mutually exclusive")
        if not flow_name:
            policy_type = self.policy_parser.policy_type()
        else:
            policy_type = flow_name
        if policy_type in ('device_identity', 'device_identity_images',
                           'device_integrity_exam',
                           'img_update_cpuss'):
            packet = self.packet_builder.build_unsigned_packet(**kwargs)
            info = f'{policy_type} packet created'
            packet = len(packet).to_bytes(4, byteorder='little') + packet
        elif policy_type == 'device_identity_item':
            if 'key_path' in kwargs:
                del kwargs['key_path']
            if 'signature' in kwargs:
                del kwargs['signature']
            packet, info = self.generate_cose_sign1(key_path, signature,
                                                    **kwargs)
        elif policy_type == 'img_update_wifiss_params':
            if 'key_path' in kwargs:
                del kwargs['key_path']
            if 'signature' in kwargs:
                del kwargs['signature']
            packet, info = self.generate_packet(key_path, signature,
                                                **kwargs,
                                                cose_packet_id=0x15010002)
        else:
            if 'key_path' in kwargs:
                del kwargs['key_path']
            if 'signature' in kwargs:
                del kwargs['signature']
            packet, info = self.generate_packet(key_path, signature,
                                                **kwargs)

        with open(output, 'wb') as f:
            f.write(packet)
        logger.info("%s: '%s'", info, output)
        return True

    def generate_packet(self, key_path, signature, **kwargs):
        if key_path:
            KeyValidatorMXS22().validate_private_key(key_path)
            packet = self.packet_builder.build_signed(key_path, **kwargs)
            logger.info(
                "Signed packet with '%s'", os.path.abspath(key_path)
            )
            info = 'Provisioning packet created'
            packet = len(packet).to_bytes(4, byteorder='little') + packet
        elif signature:
            packet = self.packet_builder.build_add_signature(
                signature, **kwargs
            )
            logger.info("Added signature '%s'", os.path.abspath(signature))
            info = 'Provisioning packet created'
            packet = len(packet).to_bytes(4, byteorder='little') + packet
        else:
            packet = self.packet_builder.build_unsigned(**kwargs)
            info = 'Data for signing created'

        return packet, info

    def generate_cose_sign1(self, key_path, signature, **kwargs):
        if key_path:
            KeyValidatorMXS22().validate_private_key(key_path)
            packet = self.packet_builder.build_cose_sign1(key_path,
                                                          **kwargs)
            logger.info(
                "Signed packet with '%s'", os.path.abspath(key_path)
            )
            info = 'Provisioning packet created'
        elif signature:
            packet = self.packet_builder.build_cose_sign1_add_signature(
                signature, **kwargs
            )
            logger.info("Added signature '%s'", os.path.abspath(signature))
            info = 'Provisioning packet created'
        else:
            packet = self.packet_builder.build_unsigned(**kwargs)
            info = 'Data for signing created'

        return packet, info

    def verify(self, target, **kwargs):
        """Verifies packet signature"""
        packet_path = os.path.abspath(kwargs.get('packet'))
        with open(packet_path, 'rb') as f:
            verified = self.packet_builder.verify_map(
                f.read()[4:], kwargs.get('key'), kid=kwargs.get('kid'))
        if verified:
            logger.info("Signature verified for '%s'", packet_path)
        else:
            logger.error("Signature verification failed for '%s'", packet_path)
        return verified

    def reverse_conversion(self, target, packets, output):
        """Converts binary provisioning packet back into policy file"""
        raise NotImplementedError

    def create_package(self, target, **kwargs):
        """Builds RAM application package"""
        flow_name = kwargs.get('flow_name')
        output = kwargs.get('output')
        input_params = kwargs.get('input_params')
        app_path = kwargs.get('app')
        hex_addr = kwargs.get('hex_addr')
        key = kwargs.get('key')
        if not app_path:
            test_pkg_type = kwargs.get('testapps')
            app = self._get_app_data(target, test_pkg_type, flow_name)
            app_path = app.image_path
            output = app.dlm_path
            if not input_params:
                input_params = app.in_params_path
            hex_addr = app.image_address
        output = os.path.abspath(output) if output else None
        package = RamAppPackageMXS22(app_path, input_params=input_params)
        self.sign_save_dlm(package, output, key, hex_addr)
        logger.info("RAM application package created in '%s'", output)
        return True

    def _get_app_data(self, target, test_pkg_type, flow_name):
        """Gets app data by the policy type or provisioning flow"""
        if not flow_name:
            flow_name = self.policy_parser.policy_type()
        flow = FlowParser(target, test_pkg_type=test_pkg_type)
        apps_dir = flow.apps_dir
        try:
            app_name = flow.apps_by_flow(flow_name)
        except KeyError as e:
            raise KeyError(f"It is not one of the flow items {e}") from e
        return Application(list(app_name)[-1], app_dir=apps_dir)

    @staticmethod
    def sign_save_dlm(package, output, key, hex_addr):
        """DLM packet signing"""
        if os.path.splitext(output)[1] == '.hex':
            package.sign_hex(key, hex_addr=hex_addr, output=output)
        else:
            signed = package.sign_bin(key)
            with open(output, 'wb') as f:
                f.write(signed)
