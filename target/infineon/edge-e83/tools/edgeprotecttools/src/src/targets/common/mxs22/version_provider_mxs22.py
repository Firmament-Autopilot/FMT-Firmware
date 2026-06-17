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
import logging

from .enums import LifecycleStage
from ....core.version_provider import VersionProvider

logger = logging.getLogger(__name__)


class VersionProviderMXS22(VersionProvider):
    """
    This class encapsulates the routine for getting a version
    of different parts of the package
    """
    def print_version(self, **kwargs):
        """Prints the package version and versions of the RAM applications
        bundled with the package
        """
        self.print_package_version()
        self.print_ram_apps_version(**kwargs)
        self.print_package_installation_source()

    def print_fw_version(self, tool):
        """Prints version of ROM_BOOT, RRAM_SE_BOOT, BASE_SE_RT_SERVICES,
        SE_RT_SERVICES and EXTENDED_BOOT
        """
        fw_version = self.target.silicon_data_reader.read_fw_version(tool)
        if fw_version:
            rom_boot = self.convert_fw_version(fw_version.rom_boot)
            rram_se_boot = self.convert_fw_version(fw_version.rram_boot)
            base_se_rt_services = self.convert_fw_version(
                fw_version.base_se_rt_services)
            se_rt_services = self.convert_fw_version(fw_version.se_rt_services)
            extended_boot = self.convert_fw_version(fw_version.extended_boot)

            self._print_fw_info(
                ROM_BOOT=rom_boot,
                RRAM_SE_BOOT=rram_se_boot,
                SE_RT_SERVICES=se_rt_services,
                BASE_SE_RT_SERVICES=base_se_rt_services,
                EXTENDED_BOOT=extended_boot
            )

        else:
            logger.error('Failed to read firmware version')

    @staticmethod
    def _print_fw_info(**kwargs):
        """Prints the firmware info"""
        if kwargs:
            print('\tFirmware:')
            for key, value in kwargs.items():
                print(f'\t - {key}: {value}')
            logger.debug(
                'FW versions: %s',
                ", ".join([f'{k} {v}' for k, v in kwargs.items()])
            )

    @staticmethod
    def convert_fw_version(version):
        """Represents 8-bytes value of version to a string like
        major.minor.patch.build"""
        if version:
            major = int.from_bytes(version[:1], byteorder='little')
            minor = int.from_bytes(version[1:2], byteorder='little')
            patch = int.from_bytes(version[2:4], byteorder='little')
            build = int.from_bytes(version[4:8], byteorder='little')
            return f'{major}.{minor}.{patch}.{build}'
        return 'unknown'

    def log_version(self, tool):
        """Creates logger message(s) with components version"""
        self.log_lifecycle_stage(tool)

    def log_lifecycle_stage(self, tool):
        """Reads device lifecycle stage and creates a
        logger info message"""
        stage = self.get_lifecycle_stage(tool, alt_name=True)
        logger.info('Chip lifecycle stage: %s',
                    stage.upper() if stage else 'unknown')

    def get_lifecycle_stage(self, tool, alt_name=False):
        """Gets a lifecycle stage name
        @param tool: OCD tool
        @param alt_name: Indicates whether to use LCS alternative name
        @return: LCS name
        """
        alt_names = {
            LifecycleStage.NORMAL_PROVISIONED.name: 'DEVELOPMENT',
            LifecycleStage.SECURE.name: 'PRODUCTION'
        }
        lcs = self.target.silicon_data_reader.read_lifecycle_stage(tool)
        if lcs:
            return alt_names.get(lcs.name, lcs.name) if alt_name else lcs.name
        return None

    def check_compatibility(self, tool, **_):
        """Verifies HW compatibility. N/A for MXS22 platform"""
        return True
