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


class PolicyParserReprovisioning(PolicyParserPrimitives):
    """Provides functionality for searching data in the
    policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir
        PolicyParserPrimitives.__init__(self, self.json, self.policy_dir)

    def reprovisioning_debug_cm33(self):
        """Gets a value of reprovisioning.debug.cm33 property"""
        return self.field('reprovisioning', 'debug', 'cm33')

    def reprovisioning_debug_system(self):
        """Gets a value of reprovisioning.debug.system property"""
        return self.field('reprovisioning', 'debug', 'system')

    def reprovisioning_debug_rma(self):
        """Gets a value of reprovisioning.debug.rma property"""
        return self.field('reprovisioning', 'debug', 'rma')

    def reprovisioning_debug_debug_key(self):
        """Gets a value of reprovisioning.debug.debug_key property"""
        return self.field('reprovisioning', 'debug', 'debug_key')

    def reprovisioning_extended_boot_policy(self):
        """Gets a value of reprovisioning.extended_boot_policy property"""
        return self.field('reprovisioning', 'extended_boot_policy')

    def reprovisioning_user_keys(self):
        """Gets a value of reprovisioning.user_keys property"""
        return self.field('reprovisioning', 'user_keys')

    def reprovisioning_user_certificate(self):
        """Gets a value of reprovisioning.user_certificate property"""
        return self.field('reprovisioning', 'user_certificate')
