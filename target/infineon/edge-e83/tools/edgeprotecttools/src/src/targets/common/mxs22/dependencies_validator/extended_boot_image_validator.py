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
from .....core.dependecy_validator import DependencyValidator


class ExtendedBootImageValidator(DependencyValidator):
    """Validator for extended boot image presence in the policy"""

    def validate(self, **kwargs):
        """Runs extended boot image validator"""
        if kwargs.get('command') == 'provisioning':
            if self.parser.extended_boot_image() and not kwargs.get(
                    'ifx_oem_cert'):
                self.add_msg('The OEM certificate (ifx_oem_cert) must be '
                             'specified to update the extended boot image')

        if kwargs.get('command') == 'reprovisioning':
            if self.parser.extended_boot_image():
                self.add_msg(
                    "The extended boot image updating is not allowed during "
                    "reprovisioning. Remove the 'extended_boot_image' property "
                    "from the policy to be able to reprovision the device")
                return
