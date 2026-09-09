"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import errno
import logging

from ..common.mxs40sv2.asset_builder import AssetBuilder
from ..common.mxs40sv2.enums import PolicyType
from ..common.flow_parser import FlowParser
from ...core.json_helper import read_json, dump_json
from ...core.key_handlers.rsa_handler import RSAHandler
from ...core.strategy_context import ProvisioningPacketStrategy

logger = logging.getLogger(__name__)


class ProvisioningPacketCYW20829(ProvisioningPacketStrategy):
    """ Provisioning packet generator for MXS40Sv2 targets """

    ASSETS_DIR = os.path.abspath(
        os.path.join(os.path.dirname(__file__), 'flows')
    )

    def __init__(self, policy_parser, asset_map):
        self.policy_parser = policy_parser
        self.asset_map = asset_map

    def create(self, target, **kwargs):
        """
        Creates RAM applications input parameters binary packets
        :return: True if packet created successfully, otherwise False.
        """
        policy_type = self.policy_parser.policy_type()
        apps_dir = target.project_initializer.apps_dir
        flow_parser = FlowParser(target, kwargs.get('testapps'))
        apps_data = flow_parser.apps_by_flow(policy_type)

        for app, config_path in apps_data.items():

            if not os.path.isfile(config_path):
                raise FileNotFoundError(
                    f'Cannot find application config file \'{config_path}\'')

            config_data = read_json(config_path)
            in_params_data = config_data.get('in_params')

            if in_params_data is not None:

                if os.path.isabs(in_params_data['path']):
                    in_params_path = in_params_data['path']
                else:
                    in_params_path = os.path.join(
                        apps_dir, app, in_params_data['path'])

                if in_params_data.get('use_existing', False):
                    continue

                if PolicyType.REPROVISIONING_SECURE == policy_type:
                    input_data = self.reprovisioning_data(
                        target.key_source, in_params_path=in_params_path,
                        **kwargs)
                else:
                    input_data = self.provisioning_data()

                os.makedirs(os.path.dirname(in_params_path), exist_ok=True)
                with open(in_params_path, 'wb') as f:
                    f.write(input_data)

                logger.info("Provisioning packet for '%s' application "
                            "successfully created (%s)", app, in_params_path)
        return True

    def verify(self, target, **kwargs):
        """N/A for the MXS40Sv2 platform"""
        raise NotImplementedError

    def create_package(self, target, **kwargs):
        """N/A for MXS40Sv2 platform"""
        raise NotImplementedError

    def reverse_conversion(self, target, packets, output):
        """ Does conversion of provisioning packet to policy """
        policy_type = self.policy_parser.policy_type()
        if PolicyType.REPROVISIONING_SECURE == policy_type:
            assets = self._reprovisioning_assets()
        else:
            assets = self._provisioning_assets()
        data = target.policy_generator.populate(packets, assets)
        dump_json(data, output)
        logger.info("Created policy in '%s'", os.path.abspath(output))
        return True

    def provisioning_data(self):
        """ Gets provisioning packet data """
        assets_list = self._provisioning_assets()
        asset_builder = AssetBuilder(
            self.policy_parser, assets_list, self.asset_map)
        input_data = asset_builder.get_assets()
        return input_data

    def reprovisioning_data(self, key_source, **kwargs):
        """ Gets reprovisioning packet data """
        key_id = kwargs.get('key_id')
        key_path = kwargs.get('key_path')
        signature = kwargs.get('signature')
        pubkey = kwargs.get('pubkey')
        non_signed = kwargs.get('non_signed')
        in_params_path = kwargs.get('in_params_path')

        if non_signed and signature:
            raise ValueError("Arguments 'non_signed' and 'signature' are "
                             "mutually exclusive")

        if not non_signed and all(
                v is None for v in [key_id, key_path, signature]):
            raise KeyError(
                'To sign the reprovisioning packet one of the following '
                'parameters must be specified: a key ID, a key path, '
                'an existing signature file')

        if pubkey is None:
            if key_path is not None:
                pubkey = key_path
            elif key_id is not None:
                pubkey = key_source.get_key(key_id, 'public')
            elif not signature:
                raise ValueError('Public key source not specified')

        if not signature:
            if not os.path.isfile(pubkey):
                raise FileNotFoundError(
                    errno.ENOENT, os.strerror(errno.ENOENT), pubkey)

            assets_list = self._reprovisioning_assets()
            asset_builder = AssetBuilder(
                self.policy_parser, assets_list, self.asset_map, pubkey=pubkey,
                image_id=kwargs.get('image_id'))
            input_data = asset_builder.get_assets()
        else:
            if not in_params_path:
                raise ValueError('Input parameters file not specified')
            with open(in_params_path, 'rb') as f:
                input_data = f.read()

        if not non_signed:
            if signature:
                with open(signature, 'rb') as f:
                    packet_signature = f.read()
            else:
                if key_path is None:
                    key = key_source.get_key(key_id, 'private')
                else:
                    key = key_path
                packet_signature = RSAHandler.sign(key, input_data)

            input_data += packet_signature

        return input_data

    def _provisioning_assets(self):
        assets_list_path = os.path.join(self.ASSETS_DIR, 'oem_assets.json')
        assets_list = read_json(assets_list_path)['Assets']
        return assets_list

    def _reprovisioning_assets(self):
        assets_list_path = os.path.join(
            self.ASSETS_DIR, 'reprovisioning_assets.json')
        assets_list = read_json(assets_list_path)['Assets']
        return assets_list
