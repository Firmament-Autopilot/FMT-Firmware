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
from ..asset_enums import ApPermission, CpuControlType
from .....core.dependecy_validator import DependencyValidator


class OemDebugValidator(DependencyValidator):
    """Validator for OEM debug section specified in the policy"""

    section = "Policy section 'debug'"

    def validate(self, **_kwargs):
        """Runs debug section validator"""
        self.validate_ap_restrictions()
        self.validate_debug_key()

    def validate_ap_restrictions(self):
        """Checks system and cm33 access port restrictions"""
        cm33_cpu = self.parser.debug_cm33_cpu()
        sys_ap = self.parser.debug_system_ap()

        if cm33_cpu == ApPermission.Allowed and sys_ap == ApPermission.Allowed:
            cm33_allowed = self.parser.debug_cm33_allowed()
            system_allowed = self.parser.debug_system_allowed()
            if cm33_allowed != system_allowed:
                self.add_msg(
                    "Due to common PC settings 'debug.cm33.allowed' and "
                    "'debug.system.allowed' values must be aligned"
                )

    def validate_debug_key(self):
        """Checks if a debug key is required"""
        key = self.parser.debug_debug_key()
        ap_allowed = (self.parser.debug_system_allowed(),
                      self.parser.debug_cm33_allowed())

        if CpuControlType.Certificate in ap_allowed and key == bytes(65):
            self.add_msg('Incomplete policy. The debug key is required when '
                         'the debug certificate is allowed')
