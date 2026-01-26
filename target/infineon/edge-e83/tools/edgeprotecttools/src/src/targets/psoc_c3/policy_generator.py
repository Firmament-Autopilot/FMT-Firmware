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
from .maps.asset_map import AssetMapPsocC3
from .maps.reverse_asset_map import ReverseAssetMap
from ...core.json_helper import replace
from ...core.jsonpath import set_node_value


class PolicyGenerator:
    def __init__(self, policy_parser):
        self.policy_parser = policy_parser
        self.asset_map_cls = AssetMapPsocC3
        self.reverse_asset_map_cls = ReverseAssetMap

    def populate(self, packets, assets):
        """
        Populates policy dictionary with the data from binary file
        @param packets: List of the binary packets paths. One packet
               only is supported for the PSOC C3 device
        @param assets: List of the assets in the packet
        @return: Dictionary populated with the data from the binary file
        """
        unpacked = self._unpack_binary(packets, assets)
        datadict = replace(self.policy_parser.json, 'value', None)

        reverse_map = self.reverse_asset_map_cls(self.policy_parser)
        for asset_name, asset_value in unpacked.items():
            items = reverse_map.reverse_asset(asset_name, asset_value)
            for path, value in items:
                if not path:
                    continue
                try:
                    datadict = set_node_value(datadict, path, value)
                except KeyError:
                    pass
        return datadict

    def _unpack_binary(self, binary, asset_list):
        """ Unpacks binary data into assets """
        fmt = self._struct_format(asset_list)

        unpacked = []

        for size in fmt:
            unpacked.append(binary[:size])
            binary = binary[size:]

        return dict(zip(asset_list, unpacked))

    def _struct_format(self, asset_list):
        """ Gets format string based on asset map items size """
        assets = self.asset_map_cls.get(self.policy_parser)
        fmt = [assets[asset]['size'] for asset in asset_list]
        return fmt
