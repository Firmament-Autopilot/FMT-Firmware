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

from ..common.mxs40sv2 import VersionProviderMXS40Sv2

logger = logging.getLogger(__name__)


class VersionProviderPsocC3(VersionProviderMXS40Sv2):
    """
    This class encapsulates the routine for getting a version
    of different parts of the package
    """
    def bootrom_version(self, tool):
        """ Reads a BootROM version from the device """
        try:
            version = tool.read(self.target.register_map.BOOTROM_VERSION, 8)
        except RuntimeError:
            return 'unknown'
        version = int.from_bytes(bytes(version), byteorder='little')
        return self.convert_version(version)

    @staticmethod
    def convert_version(version):
        """ Converts BootRom version from int to string """
        patch = 0xff & version
        minor = 0xff & (version >> 8)
        major = 0xff & (version >> 16)
        config = 0xff & (version >> 24)
        build = 0xffff & (version >> 32)
        return f'{major}.{minor}.{patch}.{build} (config={config})'
