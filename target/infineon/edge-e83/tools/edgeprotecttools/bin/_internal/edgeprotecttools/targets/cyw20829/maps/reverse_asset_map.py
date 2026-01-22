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
import binascii

from .asset_map import AssetMapCYW20829B1
from ...common.mxs40sv2 import asset_enums as enums
from ...cyw20829_a0.maps.reverse_asset_map import ReverseAssetMap


class ReverseAssetMapCYW20829B1(ReverseAssetMap):

    def __init__(self, policy_parser):
        super().__init__(policy_parser)
        self.asset_map = AssetMapCYW20829B1

    def reverse_asset(self, asset_name, asset_value):
        """
        Gets policy field path and value from the asset bytes
        @param asset_name: The name of the asset
        @param asset_value: The asset bytes
        @return: List of the tuples containing policy field path and value
        """
        pl = super().reverse_asset(asset_name, asset_value)
        if 'oem_secure_key' == asset_name:
            pl.extend(self._oem_secure_key(asset_value))
        return pl

    def _control_word(self, asset_value):
        lst = super()._control_word(asset_value)
        lst.append((
            'device_policy.flow_control.program_oem_secure_key.value',
            bool(asset_value & enums.ControlWord.PROGRAM_OEM_SECURE_KEY_MSK)))
        return lst

    @staticmethod
    def _oem_secure_key(asset_value):
        return [('pre_build.keys.oem_secure_key.value',
                 binascii.hexlify(asset_value).decode())]
