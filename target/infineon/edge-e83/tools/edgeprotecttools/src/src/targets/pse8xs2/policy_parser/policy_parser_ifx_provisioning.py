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


class PolicyParserIfxProvisioning(PolicyParserPrimitives):
    """Provides functionality for searching data in the
    policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir
        PolicyParserPrimitives.__init__(self, self.json, self.policy_dir)

    def ifx_device_cert(self):
        """Gets a value of ifx_device_cert property"""
        return self.bin_file_field('ifx_device_cert', 'value')

    def ifx_se_rt_services_nv_counter(self):
        """Gets a value of ifx_se_rt_services_nv_counter property"""
        return self.field('ifx_se_rt_services_nv_counter', 'value')

    def asset_hash(self):
        """Gets a value of asset_hash property"""
        return self.bytes_field('asset_hash', 'value')

    def basic_trims(self):
        """Gets a value of basic_trims property"""
        return self.bytes_field('basic_trims', 'value')

    def ram_app_nv_counter(self):
        """Gets a value of ram_app_nv_counter property"""
        return self.field('ram_app_nv_counter', 'value')

    def ifx_policy(self):
        """Gets a value of ifx_policy.value property"""
        return self.bytes_field('ifx_policy', 'value')

    def protected_nvm_lockable(self):
        """Gets a value of protected_nvm_lockable property"""
        return self.bytes_field('protected_nvm_lockable', 'value')

    def oem_nv_counter(self):
        """Gets a value of oem_nv_counter property"""
        return self.bytes_field('oem_nv_counter', 'value')

    def ifx_fw_integrity_key_01(self):
        """Gets a value of ifx_fw_integrity_key_01 property"""
        return self.bytes_field('ifx_fw_integrity_key_01', 'value')

    def ifx_oem_rot_master_key(self):
        """Gets a value of ifx_oem_rot_master_key property"""
        return self.bytes_field('ifx_oem_rot_master_key', 'value')

    def ifx_rma_master_key_01(self):
        """Gets a value of ifx_rma_master_key_01 property"""
        return self.bytes_field('ifx_rma_master_key_01', 'value')

    def ifx_revocation_key(self):
        """Gets a value of ifx_revocation_key property"""
        return self.bytes_field('ifx_revocation_key', 'value')

    def die_id(self):
        """Gets a value of die_id property"""
        die_id = self.field('die_id', 'value')
        if die_id:
            lot = int(die_id['lot']).to_bytes(3, byteorder='little')
            wafer = int(die_id['wafer']).to_bytes(1, byteorder='little')
            xpos = int(die_id['xpos']).to_bytes(1, byteorder='little')
            ypos = int(die_id['ypos']).to_bytes(1, byteorder='little')
            sort = int(die_id['sort']).to_bytes(1, byteorder='little')
            day = int(die_id['day']).to_bytes(1, byteorder='little')
            month = int(die_id['month']).to_bytes(1, byteorder='little')
            year = int(die_id['year']).to_bytes(1, byteorder='little')
            return lot + wafer + xpos + ypos + sort + day + month + year
        return None

    def device_id_to(self):
        """Gets a value of device_id_to property"""
        device_id_to = self.field('device_id_to', 'value')
        if device_id_to:
            family_id = int(
                device_id_to['family_id'], 16).to_bytes(2, byteorder='little')
            si_revision_id = int(
                device_id_to['si_revision_id'], 16).to_bytes(1,
                                                             byteorder='little')
            return family_id + si_revision_id
        return None

    def factory_hash(self):
        """Gets a value of factory_hash property"""
        return self.bytes_field('factory_hash', 'value')

    def full_trims(self):
        """Gets a value of full_trims property"""
        return self.bytes_field('full_trims', 'value')

    def ifx_fw_encryption_key_01(self):
        """Gets a value of ifx_fw_encryption_key_01 property"""
        return self.bytes_field('ifx_fw_encryption_key_01', 'value')

    def toc1(self):
        """Gets a value of toc1 property"""
        return self.bytes_field('toc1', 'value')

    def toc2(self):
        """Gets a value of toc2 property"""
        return self.bytes_field('toc2', 'value')

    def rma_trial_counter(self):
        """Gets a value of rma_trial_counter property"""
        return self.field('rma_trial_counter', 'value')

    def target_lcs(self):
        """Gets a value of target_lcs property"""
        lcs = self.hex_field('target_lcs', 'value')
        return lcs.to_bytes(4, byteorder='little') if lcs else lcs

    def device_rt_cfg_public(self):
        """Gets a value of device_rt_cfg property"""
        return self.bytes_field('device_rt_cfg_public', 'value')

    def boot_device_cfg(self):
        """Gets a value of boot_device_cfg property"""
        return self.bytes_field('boot_device_cfg', 'value')

    def ifx_rot_key_rev(self):
        """Gets a value of ifx_rot_key_rev property"""
        return self.field('ifx_rot_key_rev', 'value')

    def ifx_fw_integrity_key_rev(self):
        """Gets a value of ifx_fw_integrity_key_rev property"""
        return self.field('ifx_fw_integrity_key_rev', 'value')

    def ifx_oem_rot_master_key_rev(self):
        """Gets a value of ifx_oem_rot_master_key_rev property"""
        return self.field('ifx_oem_rot_master_key_rev', 'value')

    def ifx_rma_master_key_rev(self):
        """Gets a value of ifx_rma_master_key_rev property"""
        return self.field('ifx_rma_master_key_rev', 'value')

    def ifx_fw_encryption_key_rev(self):
        """Gets a value of ifx_fw_encryption_key_rev property"""
        return self.field('ifx_fw_encryption_key_rev', 'value')

    def base_se_rt_services_hash(self):
        """Gets a value of base_se_rt_services_hash property"""
        return self.bin_file_field('base_se_rt_services_hash', 'value')

    def se_rt_services_hash(self):
        """Gets a value of se_rt_services_hash property"""
        return self.bin_file_field('se_rt_services_hash', 'value')

    def rram_se_boot_hash(self):
        """Gets a value of rram_se_boot_hash property"""
        return self.bin_file_field('rram_se_boot_hash', 'value')

    def device_id_mpn(self):
        """Gets a value of device_id_mpn property"""
        device_id_mpn = self.field('device_id_mpn', 'value')
        if device_id_mpn:
            silicon_id = int(
                device_id_mpn['silicon_id'], 16).to_bytes(2, byteorder='little')
            return silicon_id
        return None

    def ifx_chain_of_trust(self):
        """Gets a list of file contents in the ifx_chain_of_trust property"""
        return self.bin_file_list_field('ifx_chain_of_trust', 'value')

    def disable_cert_validation(self):
        """Gets a value of disable_cert_validation property"""
        return self.field('disable_cert_validation', 'value')
