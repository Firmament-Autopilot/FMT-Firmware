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
import os

from ....core import PolicyParserBase
from .policy_parser_ifx_provisioning import PolicyParserIfxProvisioning
from .policy_parser_oem_provisioning import PolicyParserOemProvisioning


class PolicyParser(
    PolicyParserBase,
    PolicyParserIfxProvisioning,
    PolicyParserOemProvisioning
):
    """Provides functionality for searching data in the policy file"""

    def __init__(self, policy_file):
        PolicyParserBase.__init__(self, policy_file)
        PolicyParserIfxProvisioning.__init__(self, self.json, self.policy_dir)
        PolicyParserOemProvisioning.__init__(self, self.json, self.policy_dir)

    def rt_services_image(self):
        """Gets Run-Time Services image bytes"""
        try:
            filename = self.json['rt_services_image']['value']
        except KeyError:
            value = b''
        else:
            if not os.path.isabs(filename):
                filename = os.path.join(self.policy_dir, filename)
            with open(filename, 'rb') as f:
                value = f.read()
        return value
