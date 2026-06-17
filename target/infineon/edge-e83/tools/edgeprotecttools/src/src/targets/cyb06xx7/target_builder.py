"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .maps.memory_map import MemoryMap_cyb06xx7
from .maps.register_map import RegisterMap_cyb06xx7
from ..common.mxs40v1 import (
    PolicyFilter, PolicyParser, PolicyValidator, X509CertificateStrategyMXS40v1,
    ProvisioningPacketMXS40v1, EntranceExamCyb06xx7, SignToolMXS40v1,
    KeySourceMXS40v1, ProjectInitializerMXS40V1, ProvisioningMXS40v1,
    SiliconDataReaderMXS40v1, VersionProviderMXS40v1, VoltageToolMXS40v1,
    BootloaderProviderMXS40v1, KeyReaderMXS40V1
)
from ...core import TargetBuilder
from ...core.enums import KeyAlgorithm


class CYB06xx7_Builder(TargetBuilder):
    """ CYB06xx7 target builder """

    def get_default_policy(self):
        return os.path.join(
            self.target_dir, 'policy', 'policy_single_CM0_CM4.json')

    def get_ocds(self):
        return ['openocd']

    def get_ocd_config(self):
        return {
            'openocd': {
                'before_init': '',
                'after_init': 'targets'
            }
        }

    def get_memory_map(self):
        memory_map = MemoryMap_cyb06xx7()
        return memory_map

    def get_register_map(self):
        register_map = RegisterMap_cyb06xx7()
        return register_map

    def get_policy_parser(self, policy):
        policy_parser = PolicyParser(policy)
        return policy_parser

    def get_policy_validator(self, policy_parser, memory_map):
        policy_validator = PolicyValidator(policy_parser, memory_map)
        return policy_validator

    def get_policy_filter(self, policy_parser):
        policy_filter = PolicyFilter(policy_parser)
        return policy_filter

    def get_provisioning_strategy(self):
        return ProvisioningMXS40v1()

    def get_provisioning_packet_strategy(self, policy_parser):
        return ProvisioningPacketMXS40v1(policy_parser)

    def get_entrance_exam(self):
        return EntranceExamCyb06xx7

    def get_voltage_tool(self):
        return VoltageToolMXS40v1

    def get_key_reader(self):
        return KeyReaderMXS40V1

    def get_project_initializer(self):
        return ProjectInitializerMXS40V1

    def get_silicon_data_reader(self):
        return SiliconDataReaderMXS40v1

    def get_key_algorithms(self):
        return [KeyAlgorithm.EC]

    def get_sign_tool(self):
        return SignToolMXS40v1

    def get_key_source(self, **kwargs):
        return KeySourceMXS40v1(kwargs['policy_parser'])

    def get_bootloader_provider(self):
        return BootloaderProviderMXS40v1

    def get_version_provider(self):
        return VersionProviderMXS40v1

    def get_debug_certificate(self):
        """ N/A for MXS40v1 platform """
        return None

    def get_policy_generator(self, policy_parser):
        """ N/A for MXS40v1 platform """
        return None

    def get_test_packages(self):
        """ N/A for MXS40v1 platform """
        return None

    def get_certificate_strategy(self):
        return X509CertificateStrategyMXS40v1()

    def get_app_loader(self):
        """ N/A for MXS40v1 platform """

    def get_silicon_id(self):
        """Gets the target silicon ID"""
        return None
