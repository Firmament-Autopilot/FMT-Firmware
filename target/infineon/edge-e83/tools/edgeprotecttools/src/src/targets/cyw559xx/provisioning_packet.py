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
import os
import logging
import tempfile

import cbor

from .asset_builder import AssetBuilder
from ..common.flow_parser import FlowParser
from ...core.json_helper import read_json
from ...core.provisioning_flows.application import Application
from ...core.strategy_context import ProvisioningPacketStrategy
from ...execute.image_signing import MergeTool, SignTool

logger = logging.getLogger(__name__)


class ProvisioningPacketCYW559xx(ProvisioningPacketStrategy):
    """ Provisioning packet generator for CYW559xx family """

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
        flow_name = kwargs.get('flow_name')

        if kwargs.get('output'):
            output = os.path.abspath(kwargs.get('output'))
        else:
            app = self._get_app_data(target, None)
            output = app.in_params_path

        if not output:
            raise ValueError("Output path must be specified")

        self.policy_type = flow_name or self.policy_parser.policy_type()

        packet = self.provisioning_data()

        os.makedirs(os.path.dirname(output), exist_ok=True)
        with open(output, 'wb') as f:
            f.write(packet)
        logger.info("Provisioning packet created in '%s'", output)

        return True

    def verify(self, target, **kwargs):
        """N/A for the CYW559xx family"""
        raise NotImplementedError

    def create_package(self, target, **kwargs):
        """Builds RAM application package"""
        flow_name = kwargs.get('flow_name')
        output = kwargs.get('output')
        input_params = kwargs.get('input_params')
        app_path = kwargs.get('app')
        input_params_address = None
        if not app_path:
            app = self._get_app_data(target, kwargs.get('testapps'), flow_name)
            if app.dlm_path:
                app_path = app.image_path
                output = app.dlm_path
            else:
                return True
            if not input_params:
                input_params = app.in_params_path
            input_params_address = app.in_params_address
        if not input_params_address:
            input_params_address = target.memory_map.IN_PARAMS_BASE_ADDR
        output = os.path.abspath(output) if output else None
        with tempfile.TemporaryDirectory() as temp_dir:
            input_params_hex_path = os.path.join(temp_dir, 'in_params.hex')
            SignTool.bin2hex(
                input_params, input_params_hex_path,
                offset=input_params_address
            )
            MergeTool.merge_hex((app_path, input_params_hex_path), output)
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
        """N/A for CYW559xx"""
        raise NotImplementedError

    def provisioning_data(self):
        """Gets provisioning packet data"""
        assets_file = {
            'oem_provisioning': 'oem_assets.json',
        }
        assets_list_path = os.path.join(self.ASSETS_DIR,
                                        assets_file[self.policy_type])
        assets_list = read_json(assets_list_path)['Assets']
        asset_builder = AssetBuilder(self.policy_parser, assets_list,
                                     self.asset_map,
                                     policy_type=self.policy_type)
        input_data = asset_builder.get_assets()
        return input_data

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
