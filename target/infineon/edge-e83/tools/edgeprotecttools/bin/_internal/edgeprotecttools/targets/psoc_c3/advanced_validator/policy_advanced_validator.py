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
from . import MpcValidator, OemKeysValidator, ProtFwPolicyValidator
from ...common.dependencies_validation import DependenciesValidatorRunner


class AdvancedValidatorPsocC3(DependenciesValidatorRunner):
    """Does advanced validation on PSoC C3 policy"""

    validators = {}

    def __init__(self, parser):
        super().__init__(parser, self.validators)

    def validate(self, skip_list=None, **kwargs):
        if self.parser.policy_type() == 'oem_provisioning':
            self.validators = {
                'pre_build': [
                    OemKeysValidator,
                    MpcValidator
                ]
            }
        elif self.parser.policy_type() == 'prot_fw_policy':
            self.validators = {
                'pre_build': [
                    ProtFwPolicyValidator
                ]
            }
        return super().validate(skip_list=skip_list, **kwargs)
