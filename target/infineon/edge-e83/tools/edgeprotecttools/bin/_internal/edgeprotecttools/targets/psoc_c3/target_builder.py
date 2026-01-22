"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from .advanced_validator.policy_advanced_validator import \
    AdvancedValidatorPsocC3
from .cert import CertificateStrategyPsocC3
from .data import StatusPsocC3
from .debug_token import DebugTokenPsocC3
from .debug_token.token_template_validator import TokenTemplateValidatorPsocC3
from .maps.asset_map import AssetMapPsocC3
from .maps.memory_map import MemoryMapPsocC3
from .maps.register_map import RegisterMapPsocC3
from .policy_generator import PolicyGenerator
from .policy_parser.policy_parser import PolicyParser
from .policy_validator import PolicyValidatorPsocC3
from .project_init import ProjectInitializerPsocC3
from .provisioning import ProvisioningPsoc3, RamAppLoaderPsocC3
from .provisioning_packet import ProvisioningPacketPsocC3
from .silicon_data_reader import SiliconDataReaderPsocC3
from .version_provider import VersionProviderPsocC3
from ..common.mxs40sv2 import IntegrityExamMXS40Sv2
from ..common.mxs40sv2.debug_cert import TokenVersionVerifierMXS40Sv2
from ...core import TargetBuilder
from ...core.enums import KeyAlgorithm


class PsocC3Builder(TargetBuilder):
    """ PSoC C3 target builder """

    def get_default_policy(self):
        return None

    def get_ocds(self):
        return ['openocd', 'serial']

    def get_ocd_config(self):
        return {
            'openocd': {
                'variables': 'set ENABLE_CM33 0',
                'before_init': '',
                'after_init': 'targets psc3.sys'
            }
        }

    def get_memory_map(self):
        return MemoryMapPsocC3()

    def get_register_map(self):
        return RegisterMapPsocC3()

    def get_policy_parser(self, policy):
        return PolicyParser(policy)

    def get_policy_validator(self, policy_parser, memory_map):
        dependency_validator = AdvancedValidatorPsocC3(policy_parser)
        return PolicyValidatorPsocC3(policy_parser, dependency_validator)

    def get_policy_filter(self, policy_parser):
        return None

    def get_provisioning_strategy(self):
        return ProvisioningPsoc3()

    def get_provisioning_packet_strategy(self, policy_parser):
        return ProvisioningPacketPsocC3(policy_parser, AssetMapPsocC3())

    def get_entrance_exam(self):
        return IntegrityExamMXS40Sv2

    def get_voltage_tool(self):
        return None

    def get_key_reader(self):
        return None

    def get_project_initializer(self):
        return ProjectInitializerPsocC3

    def get_silicon_data_reader(self):
        return SiliconDataReaderPsocC3

    def get_key_algorithms(self):
        return [
            KeyAlgorithm.ECDSA_P256,
            KeyAlgorithm.AES128
        ]

    def get_sign_tool(self):
        return None

    def get_key_source(self, **kwargs):
        return None

    def get_bootloader_provider(self):
        return None

    def get_version_provider(self):
        return VersionProviderPsocC3

    def get_debug_certificate(self):
        template_validator = TokenTemplateValidatorPsocC3(
            version_verifier=TokenVersionVerifierMXS40Sv2,
            advanced_validator=None)
        return DebugTokenPsocC3(template_validator=template_validator)

    def get_policy_generator(self, policy_parser):
        return PolicyGenerator(policy_parser)

    def get_test_packages(self):
        return {
            'testapps': {
                'package': 'testapps_psoc_c3', 'flow_name': 'testapps'
            },
            'testapps_si': {
                'package': 'testapps_psoc_c3', 'flow_name': 'testapps_si'
            }
        }

    def get_certificate_strategy(self):
        return CertificateStrategyPsocC3()

    def get_app_loader(self):
        return RamAppLoaderPsocC3(StatusPsocC3())

    def get_silicon_id(self):
        return None
