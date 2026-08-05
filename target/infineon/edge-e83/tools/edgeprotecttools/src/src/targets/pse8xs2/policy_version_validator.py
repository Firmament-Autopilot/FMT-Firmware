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


class PolicyVersionValidator:
    """Validator for version specified in the policy"""

    def __init__(self, policy_parser):
        self.policy_parser = policy_parser

    def validate(self):
        """Runs policy version validation"""

        version_min = 1.0
        version_max = 2.0
        section = "Policy section 'version'"

        try:
            version = self.policy_parser.policy_version()
        except KeyError as e:
            return False, f"{section}: invalid structure, missing {e} field"
        else:
            try:
                if version < version_min or version >= version_max:
                    return False, f"Policy version is incompatible. " \
                                  f"Use version {version_min:.1f} " \
                                  f"or below {version_max:.1f}"
            except TypeError:
                return False, f"{section}: invalid 'version' value"
        return True, None
