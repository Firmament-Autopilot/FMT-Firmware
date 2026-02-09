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
from .advanced_validator.policy_advanced_validator import (
    AdvancedValidatorCYW559xx
)
from .maps.asset_map import AssetMapCYW559xx
from .maps.memory_map import MemoryMapCYW559xx
from .policy_validator import PolicyValidatorCYW559xx
from .provisioning import ProvisioningCYW559xx, RamAppLoaderCYW559xx
from .provisioning_packet import ProvisioningPacketCYW559xx
from .project_init_cyw559xx import ProjectInitializerCYW559xx
from ...core import TargetBuilder
from .policy_parser.policy_parser import PolicyParser


class CYW559xxBuilder(TargetBuilder):
    """ CYW559xx target builder """

    def get_default_policy(self):
        return None

    def get_ocds(self):
        return ['chipload']

    def get_ocd_config(self):
        return None

    def get_memory_map(self):
        return MemoryMapCYW559xx()

    def get_register_map(self):
        return None

    def get_policy_parser(self, policy):
        return PolicyParser(policy)

    def get_policy_validator(self, policy_parser, memory_map):
        dependency_validator = AdvancedValidatorCYW559xx(policy_parser)
        return PolicyValidatorCYW559xx(policy_parser, dependency_validator)

    def get_policy_filter(self, policy_parser):
        """N/A for CYW559xx"""

    def get_provisioning_strategy(self):
        return ProvisioningCYW559xx()

    def get_provisioning_packet_strategy(self, policy_parser):
        return ProvisioningPacketCYW559xx(policy_parser, AssetMapCYW559xx())

    def get_entrance_exam(self):
        return None

    def get_voltage_tool(self):
        return None

    def get_key_reader(self):
        return None

    def get_project_initializer(self):
        return ProjectInitializerCYW559xx

    def get_silicon_data_reader(self):
        return None

    def get_key_algorithms(self):
        return None

    def get_sign_tool(self):
        return None

    def get_key_source(self, **kwargs):
        return None

    def get_bootloader_provider(self):
        return None

    def get_version_provider(self):
        return None

    def get_debug_certificate(self):
        return None

    def get_policy_generator(self, policy_parser):
        return None

    def get_test_packages(self):
        return None

    def get_certificate_strategy(self):
        return None

    def get_app_loader(self):
        return RamAppLoaderCYW559xx()

    def get_silicon_id(self):
        return None
