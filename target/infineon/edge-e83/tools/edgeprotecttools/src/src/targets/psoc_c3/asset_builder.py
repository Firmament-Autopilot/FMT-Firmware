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
from .asset import AssetPsocC3
from ..common.mxs40sv2.asset_builder import AssetBuilder


class AssetBuilderPsocC3(AssetBuilder):

    def get_assets(self):
        """
        Creates a list of assets and sort it by order
        :return: Return a byte-array value representing a value of single Asset
        """
        assets = [AssetPsocC3(k, v) for k, v in self.assets_dict.items()]
        value = bytes()
        for item in assets:
            value += item.value
        return value
