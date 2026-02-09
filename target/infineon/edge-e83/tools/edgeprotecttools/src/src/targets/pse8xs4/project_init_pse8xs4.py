"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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

from ..common.mxs22 import ProjectInitializerMXS22

logger = logging.getLogger(__name__)


class ProjectInitPse8xs4(ProjectInitializerMXS22):
    """
    A class that implements project creation logic for MXS22 platform
    """

    @property
    def misc_files(self):
        """
        Gets miscellaneous project files
        Must follow the project folder structure for MXS22 platform
        """
        return {
            self.keys_dirname: [
                'ec_key_tmpl.json',
                'rsa_key_tmpl.json'
            ],
            self.packets_dirname: [
                'debug_token.json',
                'rma_token.json',
                'open_rma_token.json',
                'ifx_key_revoke_token.json',
                'integrity_exam_custom_regions.json',
                'template_device_cert.json',
                'template_manufacturing_cert.json',
                'template_oem_cert.json',
                'template_oem_csr.json',
                'se_rt_services_meta.json'
            ]
        }
