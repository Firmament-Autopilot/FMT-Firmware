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
import os.path

from .policy_parser_debug import PolicyParserDebug
from .policy_parser_reprovisioning import PolicyParserReprovisioning
from .policy_parser_cm33_l1_boot_policy import PolicyParserCm33L1BootPolicy
from ...common.mxs22.custom_keys_packet import CustomKeysPacket


class PolicyParserOemProvisioning(
    PolicyParserDebug,
    PolicyParserReprovisioning,
    PolicyParserCm33L1BootPolicy
):
    """Provides functionality for searching data in the policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir

        PolicyParserDebug.__init__(self, self.json, self.policy_dir)
        PolicyParserReprovisioning.__init__(self, self.json, self.policy_dir)
        PolicyParserCm33L1BootPolicy.__init__(self, self.json, self.policy_dir)

    def extended_boot_image(self):
        """Gets a value of extended_boot_image property"""
        return self.bin_file_field('extended_boot_image', 'value')

    def ifx_oem_cert(self):
        """Gets a value of ifx_oem_cert property"""
        return self.bin_file_field('ifx_oem_cert', 'value')

    def user_certificate(self):
        """Gets a list of file contents in the user_certificate property"""
        return self.bin_file_list_field('user_certificate', 'value')

    def user_keys(self, ret_value=False):
        """Gets a list of file contents in the user_keys property
        @param ret_value: Returns actual value as a dictionary if True,
        otherwise CBOR packet
        @return: CBOR packet or dictionary
        """
        keys = self.field('user_keys', 'value')
        filled_in = []
        if keys:
            for key in keys:
                if not all(v['value'] is None for v in key.values()):
                    if not os.path.isabs(key['key']['value']):
                        key['key']['value'] = os.path.abspath(
                            os.path.join(self.policy_dir, key['key']['value']))
                    filled_in.append(key)
        if filled_in:
            if ret_value:
                return filled_in
            return CustomKeysPacket.create(filled_in)
        return None

    def oem_key_revocation(self):
        """Gets a value of oem_key_revocation.value property"""
        return self.field('oem_key_revocation', 'value')

    def boundary_scan(self):
        """Gets a value of boundary_scan.value property"""
        return self.field('boundary_scan', 'value')
