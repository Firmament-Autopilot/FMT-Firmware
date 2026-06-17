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
import struct

from .maps.asset_map import AssetMapCYW20829
from .maps.reverse_asset_map import ReverseAssetMap
from ...core.json_helper import replace
from ...core.jsonpath import set_node_value


class PolicyGenerator:
    def __init__(self, policy_parser):
        self.policy_parser = policy_parser
        self.asset_map = AssetMapCYW20829
        self.reverse_asset_map = ReverseAssetMap

    def populate(self, packets, assets):
        """
        Populates policy dictionary with the data from binary file
        @param packets: List of the binary packets paths. One packet
               only is supported for the CYW20829 device
        @param assets: List of the assets in the packet
        @return: Dictionary populated with the data from the binary file
        """
        if not packets:
            raise ValueError('Input parameters packet not specified')
        with open(packets[0], 'rb') as f:
            binary = f.read()
        unpacked = self._unpack_binary(binary, assets)
        datadict = replace(self.policy_parser.json, 'value', None)

        reverse_map = self.reverse_asset_map(self.policy_parser)
        for asset_name, asset_value in unpacked.items():
            items = reverse_map.reverse_asset(asset_name, asset_value)
            for path, value in items:
                try:
                    datadict = set_node_value(datadict, path, value)
                except KeyError:
                    pass
        return datadict

    def _unpack_binary(self, binary, asset_list):
        """ Unpacks binary data into assets """
        fmt, assets_size = self._struct_format(asset_list)
        unpacked = struct.unpack(fmt, binary[:assets_size])
        data = dict()
        for i, asset in enumerate(asset_list):
            data[asset] = unpacked[i]
        return data

    def _struct_format(self, asset_list):
        """ Gets format string based on asset map items size """
        fmt = '<'
        assets_size = 0
        assets = self.asset_map.get(self.policy_parser)
        for asset in asset_list:
            size = assets[asset]['size']
            if size == 4:
                fmt += 'I'
                assets_size += size
            elif size > 4:
                fmt += f'{size}s'
                assets_size += size
            else:
                assert False

        return fmt, assets_size
