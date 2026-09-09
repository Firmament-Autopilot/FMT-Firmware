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
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ...common.mxs22.asset_enums import SmifMode


class PolicyParserCm33L1BootPolicy(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir
        PolicyParserPrimitives.__init__(self, self.json, self.policy_dir)

    def extended_boot_policy_secure_boot(self):
        """Gets a value of extended_boot_policy.secure_boot.value property"""
        return self.field('extended_boot_policy', 'secure_boot', 'value')

    def extended_boot_policy_clock(self):
        """Gets a value of extended_boot_policy.clock.value property"""
        return self.field('extended_boot_policy', 'clock', 'value')

    def extended_boot_policy_listen_window(self):
        """Gets a value of extended_boot_policy.listen_window.value property"""
        return self.field('extended_boot_policy', 'listen_window', 'value')

    def extended_boot_policy_enable_alt_serial(self):
        """Gets a value of extended_boot_policy.clock.value property"""
        return self.field('extended_boot_policy', 'enable_alt_serial', 'value')

    def extended_boot_policy_cm33_ram_app_enable(self):
        """Gets a value of extended_boot_policy.cm33_ram_app.enable.value
        property"""
        return self.field('extended_boot_policy', 'cm33_ram_app', 'enable',
                          'value')

    def extended_boot_policy_cm33_ram_app_address(self):
        """Gets a value of extended_boot_policy.cm33_ram_app.address.value
        property"""
        return self.hex_field('extended_boot_policy', 'cm33_ram_app', 'address',
                              'value')

    def extended_boot_policy_cm33_rram_app_address(self):
        """Gets a value of extended_boot_policy.cm33_rram_app.address.value
        property"""
        return self.hex_field('extended_boot_policy', 'cm33_rram_app',
                              'address', 'value')

    def extended_boot_policy_cm33_rram_app_size(self):
        """Gets a value of extended_boot_policy.cm33_rram_app.size.value
        property"""
        return self.hex_field('extended_boot_policy', 'cm33_rram_app', 'size',
                              'value')

    def extended_boot_policy_oem_app_address(self):
        """Gets a value of extended_boot_policy.oem_app_address.value
        property"""
        return self.hex_field(
            'extended_boot_policy', 'oem_app_address', 'value')

    def extended_boot_policy_oem_alt_boot(self):
        """Gets a value of extended_boot_policy.oem_alt_boot.value property"""
        return self.field('extended_boot_policy', 'oem_alt_boot', 'value')

    def extended_boot_policy_oem_alt_app_address(self):
        """Gets a value of extended_boot_policy.oem_app_start.value property"""
        return self.hex_field('extended_boot_policy', 'oem_alt_app_address',
                              'value')

    def extended_boot_policy_external_flash_smif_exflash(self):
        """Gets a value of
        extended_boot_policy.external_flash.smif_exflash.value property"""
        return self.field('extended_boot_policy', 'external_flash',
                          'smif_exflash', 'value')

    def extended_boot_policy_external_flash_smif_chip_select(self):
        """Gets a value of
        extended_boot_policy.external_flash.smif_chip_select.value property"""
        return self.field('extended_boot_policy', 'external_flash',
                          'smif_chip_select', 'value')

    def extended_boot_policy_external_flash_smif_data_width(self):
        """Gets a value of
        extended_boot_policy.external_flash.smif_data_width.value property"""
        return self.field('extended_boot_policy', 'external_flash',
                          'smif_data_width', 'value')

    def extended_boot_policy_external_flash_smif_data_select(self):
        """Gets a value of
        extended_boot_policy.external_flash.smif_data_select.value property"""
        return self.field('extended_boot_policy', 'external_flash',
                          'smif_data_select', 'value')

    def extended_boot_policy_external_flash_smif_mode(self, ret_value=False):
        """Gets a value of
        extended_boot_policy.external_flash.smif_mode.value property"""
        value = self.enum_field(SmifMode, ret_value, 'extended_boot_policy',
                                'external_flash', 'smif_mode', 'value')
        if not value:
            value = SmifMode.AUTO.value if ret_value else SmifMode.AUTO
        return value
