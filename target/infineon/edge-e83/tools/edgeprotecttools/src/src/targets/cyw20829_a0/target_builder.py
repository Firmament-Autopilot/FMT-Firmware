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
from .policy_parser import PolicyParser
from .policy_generator import PolicyGenerator
from .maps.asset_map import AssetMapCYW20829
from .maps.memory_map import MemoryMapCYW20829
from .maps.register_map import RegisterMap_cyw20829
from .provisioning_packet import ProvisioningPacketCYW20829
from ..common.mxs40sv2 import (
    DependencyValidatorMXS40Sv2, PolicyValidatorMXS40Sv2,
    DebugCertificateMXS40Sv2, SignToolMXS40Sv2, KeySourceMXS40Sv2,
    ProjectInitializerMXS40Sv2, ProvisioningMXS40Sv2, RamAppLoaderMXS40Sv2,
    VersionProviderMXS40Sv2, SiliconDataReaderMXS40Sv2
)
from ..common.mxs40sv2.data import RamAppStatusMXS40Sv2
from ..common.mxs40sv2.debug_cert import (
    TokenTemplateValidatorMXS40Sv2, TokenAdvancedValidatorMXS40v2,
    TokenVersionVerifierMXS40Sv2
)
from ...core import TargetBuilder
from ...core.enums import KeyAlgorithm


class CYW20829A0Builder(TargetBuilder):
    """ CYW20829 A0 target builder """

    def get_default_policy(self):
        return None

    def get_ocds(self):
        return ['openocd']

    def get_ocd_config(self):
        return {
            'openocd': {
                'before_init': 'cyw20829.cm33 configure -defer-examine',
                'after_init': 'targets cyw20829.sysap'
            }
        }

    def get_memory_map(self):
        memory_map = MemoryMapCYW20829()
        return memory_map

    def get_register_map(self):
        register_map = RegisterMap_cyw20829()
        return register_map

    def get_policy_parser(self, policy):
        policy_parser = PolicyParser(policy)
        return policy_parser

    def get_policy_validator(self, policy_parser, memory_map):
        dependency_validator = DependencyValidatorMXS40Sv2(policy_parser)
        return PolicyValidatorMXS40Sv2(policy_parser, dependency_validator)

    def get_policy_filter(self, policy_parser):
        pass

    def get_provisioning_strategy(self):
        return ProvisioningMXS40Sv2()

    def get_provisioning_packet_strategy(self, policy_parser):
        return ProvisioningPacketCYW20829(policy_parser, AssetMapCYW20829())

    def get_entrance_exam(self):
        return None

    def get_voltage_tool(self):
        return None

    def get_key_reader(self):
        return None

    def get_project_initializer(self):
        return ProjectInitializerMXS40Sv2

    def get_silicon_data_reader(self):
        return SiliconDataReaderMXS40Sv2

    def get_key_algorithms(self):
        return [KeyAlgorithm.RSA, KeyAlgorithm.AES]

    def get_sign_tool(self):
        return SignToolMXS40Sv2

    def get_key_source(self, **kwargs):
        return KeySourceMXS40Sv2(kwargs['policy_parser'])

    def get_bootloader_provider(self):
        return None

    def get_version_provider(self):
        return VersionProviderMXS40Sv2

    def get_debug_certificate(self):
        template_validator = TokenTemplateValidatorMXS40Sv2(
            version_verifier=TokenVersionVerifierMXS40Sv2,
            advanced_validator=TokenAdvancedValidatorMXS40v2)
        return DebugCertificateMXS40Sv2(template_validator=template_validator)

    def get_policy_generator(self, policy_parser):
        return PolicyGenerator(policy_parser)

    def get_certificate_strategy(self):
        return None

    def get_app_loader(self):
        return RamAppLoaderMXS40Sv2(RamAppStatusMXS40Sv2())

    def get_test_packages(self):
        return {
            'testapps': {
                'package': 'testapps_cyw20829_a0', 'flow_name': 'testapps'
            },
            'testapps_si': {
                'package': 'testapps_cyw20829_a0', 'flow_name': 'testapps_si'
            }
        }

    def get_silicon_id(self):
        """Gets the target silicon ID"""
        return {
            'id': [0xEB40],
            'rev': [0x11],
            'family': 0x110
        }
