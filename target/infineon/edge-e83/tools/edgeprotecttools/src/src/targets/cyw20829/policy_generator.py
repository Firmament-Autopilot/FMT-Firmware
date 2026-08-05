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
from .maps.asset_map import AssetMapCYW20829B1
from .maps.reverse_asset_map import ReverseAssetMapCYW20829B1
from ..cyw20829_a0.policy_generator import PolicyGenerator


class PolicyGeneratorCYW20829B1(PolicyGenerator):

    def __init__(self, policy_parser):
        super().__init__(policy_parser)
        self.asset_map = AssetMapCYW20829B1
        self.reverse_asset_map = ReverseAssetMapCYW20829B1
