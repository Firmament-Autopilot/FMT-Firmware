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

from ...common.policy_validator import PolicyValidator


class PolicyValidatorMXS22(PolicyValidator):
    """Policy validator for MXS22 platform"""

    schema_dir = os.path.join(os.path.dirname(__file__), 'schemas')

    _schemas = {
        'prov_oem': None,
        'prov_oem_L2': None,
        'prov_oem_L4': None,
        'device_identity': None,
        'device_identity_item': None,
        'device_identity_images': None,
        'prov_icv_sort': None,
        'prov_icv_provisioned': None,
        'prov_icv_normal_provisioned': None,
        'device_integrity_exam': None
    }

    def __init__(self, policy_parser, version_validator,
                 schemas, dependency_validator):
        super().__init__(policy_parser, version_validator,
                         schemas if schemas else self._schemas,
                         dependency_validator)

    def validate(self, skip=None, skip_prompts=False, **kwargs):
        """
        Policy JSON file validation
        :param skip:
            Validator names to be skipped
        :param skip_prompts:
            Indicates whether to skip interactive prompts
        :return
            Validation status
        """
        if self.policy_parser.json is None:
            self.skip_validation = True
        return super().validate(skip, skip_prompts, **kwargs)
