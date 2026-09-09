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

import cbor
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

from .ram_app_package import RamAppPackagePsocC3
from .asset_builder import AssetBuilderPsocC3
from ..common.mxs40sv2.asset_enums import DeviceIntegrity
from ..common.flow_parser import FlowParser
from ...core.exceptions import CryptoKeyError
from ...core.json_helper import read_json
from ...core.key_handlers.ec_handler import ECHandler
from ...core.provisioning_flows.application import Application
from ...core.strategy_context import ProvisioningPacketStrategy

logger = logging.getLogger(__name__)


class ProvisioningPacketPsocC3(ProvisioningPacketStrategy):
    """ Provisioning packet generator for PSoC C3 family """

    ASSETS_DIR = os.path.abspath(
        os.path.join(os.path.dirname(__file__), 'flows'))

    def __init__(self, policy_parser, asset_map):
        self.policy_parser = policy_parser
        self.asset_map = asset_map
        self.policy_type = None

    def create(self, target, **kwargs):
        """Creates RAM applications input parameters binary packets
        :return: True if packet created successfully, otherwise False.
        """
        if kwargs.get('integrity_cert'):
            kwargs['flow_name'] = 'device_integrity_exam'
        flow_name = kwargs.get('flow_name')

        if kwargs.get('output'):
            output = os.path.abspath(kwargs.get('output'))
        else:
            test_pkg_type = kwargs.get('testapps')
            app = self._get_app_data(target, test_pkg_type, flow_name)
            output = app.in_params_path

        if not output:
            return True

        self.policy_type = flow_name or self.policy_parser.policy_type()

        packet, info = self._get_packet_data(**kwargs)

        os.makedirs(os.path.dirname(output), exist_ok=True)
        with open(output, 'wb') as f:
            f.write(packet)
        logger.info("%s in '%s'", info, output)

        return True

    def verify(self, target, **kwargs):
        """N/A for the MXS40Sv2 platform"""
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
            app = self._get_app_data(target, kwargs.get('testapps'), flow_name)
            if app.dlm_path:
                app_path = app.image_path
                output = app.dlm_path
            else:
                return True
            if not input_params:
                input_params = app.in_params_path
            hex_addr = app.image_address
        output = os.path.abspath(output) if output else None
        package = self._get_ram_app_package(app_path, input_params=input_params)
        if kwargs.get('slot_size'):
            package.slot_size = kwargs.get('slot_size')
        if not self.sign_save_dlm(package, output, key, hex_addr):
            return False
        logger.info("RAM application package created in '%s'", output)
        return True

    @staticmethod
    def sign_save_dlm(package, output, key, hex_addr):
        """Signs and saves the RAM application package"""
        if os.path.splitext(output)[1] == '.hex':
            if not hex_addr:
                logger.error("Hex address must be specified for hex output")
                return False
            package.sign_hex(hex_addr, key=key, output=output)
        else:
            signed = package.sign_bin(key=key)
            with open(output, 'wb') as f:
                f.write(signed)
        return True

    def reverse_conversion(self, target, packets, output):
        """Parses provisioning packet"""
        if not self.policy_type:
            self.policy_type = self.policy_parser.policy_type()
        if self.policy_type == 'oem_provisioning':
            assets_list = self._provisioning_assets()
        else:
            return None
        data = target.policy_generator.populate(packets, assets_list)
        return data

    def provisioning_data(self):
        """Gets provisioning packet data"""
        assets_list = self._provisioning_assets()
        asset_builder = AssetBuilderPsocC3(self.policy_parser, assets_list,
                                           self.asset_map,
                                           policy_type=self.policy_type)
        input_data = asset_builder.get_assets()
        return input_data

    def prot_fw_policy_data(self):
        """Gets Protected FW policy packet data"""
        assets_list = self._provisioning_assets()
        asset_builder = AssetBuilderPsocC3(self.policy_parser, assets_list,
                                           self.asset_map,
                                           policy_type=self.policy_type)
        input_data = asset_builder.get_assets()

        if self.policy_parser.prot_fw_encrypt_enable():
            iv = self.policy_parser.prot_fw_encrypt_iv(ret_value=True)
            key = self.policy_parser.prot_fw_key()
            cipher = Cipher(algorithms.AES(key), modes.CBC(iv))
            encryptor = cipher.encryptor()
            ct = encryptor.update(input_data) + encryptor.finalize()
            data = iv + ct
        else:
            iv = bytes(16)
            data = iv + input_data

        return data

    def reprovisioning_data(self, key):
        """Gets reprovisioning packet data.
        Signs the packet if a key is specified
        """
        assets_list = self._provisioning_assets()
        asset_builder = AssetBuilderPsocC3(self.policy_parser, assets_list,
                                           self.asset_map,
                                           policy_type=self.policy_type)
        input_data = asset_builder.get_assets()
        sig = b''
        if key:
            try:
                r, s = ECHandler.sign(key, input_data)
            except TypeError as e:
                raise CryptoKeyError('Invalid key type') from e
            sig = r + s

        input_data += sig
        return input_data

    def device_integrity_data(self, cert):
        """Gets device_integrity packet data"""
        if not cert:
            raise ValueError('Integrity cert must be specified')

        assets = self.asset_map.get(self.policy_parser,
                                    policy_type=self.policy_type,
                                    integrity_cert=cert)

        unprotected = self._unprotected_data(assets)
        packet = self._build_unsigned_packet(DeviceIntegrity.INTEGRITY_EXAM_CMD,
                                             unprotected)
        packet = len(packet).to_bytes(4, byteorder='little') + packet

        return packet

    @staticmethod
    def _build_unsigned_packet(map_id, unprotected):
        """Builds a CBOR provisioning packet
        @return: CBOR packet
        """
        packet = {map_id: unprotected}
        packet = cbor.dumps(packet)
        return packet

    @staticmethod
    def _unprotected_data(assets):
        """Gets an unprotected part of the provisioning packet"""
        top_level = {}
        for val in assets.values():
            if val['value'] is None:
                continue
            top_level[val['id']] = val['value']
        return top_level

    def _get_app_data(self, target, test_pkg_type, flow_name=None):
        """Gets app data by the policy type or provisioning flow"""
        if not flow_name:
            flow_name = self.policy_parser.policy_type()
        flow = FlowParser(target, test_pkg_type=test_pkg_type)
        try:
            app_data = flow.apps_by_flow(flow_name)
        except KeyError as e:
            raise KeyError(f"Unknown flow name {e}") from e
        return Application(list(app_data)[-1], app_dir=flow.apps_dir)

    @staticmethod
    def _get_ram_app_package(app_path, input_params=None):
        return RamAppPackagePsocC3(app_path, input_params=input_params)

    def _get_packet_data(self, **kwargs):
        key = kwargs.get('key')
        integrity_cert = kwargs.get('integrity_cert')

        if self.policy_type == 'reprovisioning':
            try:
                packet = self.reprovisioning_data(key)
            except (CryptoKeyError, ValueError):
                logger.error("Invalid key type '%s'. ECDSA is expected", key)
                return False
            if not key:
                logger.warning('No key was specified. The data is unsigned')
        elif self.policy_type == 'device_integrity_exam':
            packet = self.device_integrity_data(integrity_cert)
        elif self.policy_type == 'prot_fw_policy':
            packet = self.prot_fw_policy_data()
        else:
            packet = self.provisioning_data()

        info = 'Provisioning packet created'

        return packet, info

    def _provisioning_assets(self):
        """Gets assets list"""
        assets_file = {
            'provisioned': 'device_identity_assets.json',
            'normal_provisioned': 'prov_icv_assets.json',
            'oem_provisioning': 'oem_assets.json',
            'prot_fw_policy': 'prot_fw_assets.json',
            'prot_fw_dfu': 'prot_fw_dfu_assets.json',
            'reprovisioning': 'reprovisioning_assets.json'
        }
        assets_list_path = os.path.join(self.ASSETS_DIR,
                                        assets_file[self.policy_type])
        assets_list = read_json(assets_list_path)['Assets']
        return assets_list
