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
from ....core.dependecy_validator import DependencyValidator


class OemReqsValidatorPse8x(DependencyValidator):
    """Validator for the required policy fields when the
    IFX OEM certificate is specified"""

    def validate(self, **_kwargs):
        """Runs debug section validator"""
        mandatory = (
            self.parser.debug_cm33_cpu,
            self.parser.debug_cm33_allowed,
            self.parser.debug_cm33_dbgen,
            self.parser.debug_cm33_niden,
            self.parser.debug_cm33_spiden,
            self.parser.debug_cm33_spniden,
            self.parser.debug_cm33_secure,
            self.parser.debug_system_ap,
            self.parser.debug_system_allowed,
            self.parser.debug_system_mpc_ppc_enable,
            self.parser.debug_system_rram_otp_enable,
            self.parser.debug_system_rram_nvm_enable,
            self.parser.debug_system_ram_enable,
            self.parser.debug_system_mmio_enable,
            self.parser.debug_rma_permission,
            self.parser.reprovisioning_debug_cm33,
            self.parser.reprovisioning_debug_system,
            self.parser.reprovisioning_debug_rma,
            self.parser.reprovisioning_user_keys,
            self.parser.reprovisioning_user_certificate,
            self.parser.extended_boot_policy_secure_boot,
            self.parser.extended_boot_policy_clock,
            self.parser.extended_boot_policy_listen_window,
            self.parser.extended_boot_policy_enable_alt_serial,
            self.parser.extended_boot_policy_cm33_ram_app_enable,
            self.parser.extended_boot_policy_cm33_ram_app_address,
            self.parser.extended_boot_policy_oem_app_address,
            self.parser.extended_boot_policy_oem_alt_boot,
            self.parser.extended_boot_policy_oem_alt_app_address,
            self.parser.extended_boot_policy_external_flash_smif_chip_select,
            self.parser.extended_boot_policy_external_flash_smif_data_width,
            self.parser.extended_boot_policy_external_flash_smif_data_select,
            self.parser.boundary_scan,
            self.parser.oem_key_revocation
        )

        for method in mandatory:
            value = method()
            if value is None:
                self.add_msg(f"Incomplete policy. Missing '{method.__name__}'")
