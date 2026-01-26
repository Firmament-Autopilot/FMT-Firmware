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
import logging

from .enums import LifecycleStage
from ....core.version_provider import VersionProvider

logger = logging.getLogger(__name__)


class VersionProviderMXS40Sv2(VersionProvider):
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
        """ Prints a BootROM version from the device """
        bootrom_ver = self.bootrom_version(tool)
        print('\tDevice:')
        print(f'\t\tBootROM: {bootrom_ver}')

    def bootrom_version(self, tool):
        """ Reads a BootROM version from the device """
        version = tool.read32(self.target.register_map.BOOTROM_VERSION)
        build = tool.read32(self.target.register_map.BOOTROM_BUILD)
        return f'{self.convert_version(version)}.{build}'

    @staticmethod
    def convert_version(version):
        """ Converts BootRom version from int to string """
        patch = 0xff & version
        minor = 0xff & (version >> 8)
        major = 0xff & (version >> 16)
        return f'{major}.{minor}.{patch}'

    def log_version(self, tool):
        """Creates logger message(s) with components version"""
        self.log_lifecycle_stage(tool)

    def log_lifecycle_stage(self, tool):
        """
        Reads device lifecycle stage and creates a
        logger info message
        """
        stage = self.get_lifecycle_stage(tool)
        logger.info('Chip lifecycle stage: %s', stage.upper())

    def get_lifecycle_stage(self, tool, **_):
        """ Gets a lifecycle stage name """
        value = self.target.silicon_data_reader.read_lifecycle_stage(tool)
        try:
            stage = LifecycleStage(value & 0xFFFF).name.upper()
        except ValueError:
            stage = f'UNKNOWN ({value})'
        return stage

    def check_compatibility(self, tool, **_):
        """
        Verifies HW compatibility.
        N/A for MXS40Sv2 platform
        """
        return True
