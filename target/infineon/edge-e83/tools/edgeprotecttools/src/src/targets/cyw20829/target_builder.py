"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from .provisioning_packet import ProvisioningPacketCYW20829B1
from .maps.asset_map import AssetMapCYW20829B1
from ..cyw20829_b0 import CYW20829B0Builder
from .policy_parser import PolicyParserCYW20829B1
from .policy_generator import PolicyGeneratorCYW20829B1
from .dependency_validator import DependencyValidator
from ..common.mxs40sv2 import PolicyValidatorMXS40Sv2


class CYW20829B1Builder(CYW20829B0Builder):
    """ CYW20829 target builder """

    def get_policy_parser(self, policy):
        policy_parser = PolicyParserCYW20829B1(policy)
        return policy_parser

    def get_policy_validator(self, policy_parser, memory_map):
        dependency_validator = DependencyValidator(policy_parser)
        return PolicyValidatorMXS40Sv2(policy_parser, dependency_validator)

    def get_policy_generator(self, policy_parser):
        return PolicyGeneratorCYW20829B1(policy_parser)

    def get_provisioning_packet_strategy(self, policy_parser):
        return ProvisioningPacketCYW20829B1(policy_parser, AssetMapCYW20829B1())

    def get_test_packages(self):
        return {
            'testapps': {
                'package': 'testapps_cyw20829_b1', 'flow_name': 'testapps'
            },
            'testapps_si': {
                'package': 'testapps_cyw20829_b1', 'flow_name': 'testapps_si'
            }
        }

    def get_silicon_id(self):
        """Gets the target silicon ID"""
        return {
            'id': [0xEB4B, 0xEB4C, 0xEB4F, 0xEB50],
            'rev': [0x22],
            'family': 0x110
        }
