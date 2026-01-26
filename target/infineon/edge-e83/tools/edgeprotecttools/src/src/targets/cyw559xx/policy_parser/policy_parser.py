"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from ....core import PolicyParserBase
from .policy_parser_oem_provisioning import PolicyParserOemProvisioning


class PolicyParser(
    PolicyParserBase,
    PolicyParserOemProvisioning
):
    """Provides functionality for searching data in the policy file"""

    def __init__(self, policy_file):
        PolicyParserBase.__init__(self, policy_file)
        PolicyParserOemProvisioning.__init__(self, self.json, self.policy_dir)
