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

from ..common.mxs40sv2 import ProjectInitializerMXS40Sv2

logger = logging.getLogger(__name__)


class ProjectInitializerPsocC3(ProjectInitializerMXS40Sv2):
    """A class that implements project creation logic for PSoC C3"""

    @property
    def misc_files(self):
        """
        Gets miscellaneous project files
        Must follow the project folder structure for MXS40Sv2 platform
        """
        return {
            self.packets_dirname: [
                'debug_token.json',
                'device_integrity_cert.json'
            ],
            self.keys_dirname: [
                'ec_key_tmpl.json'
            ]
        }
