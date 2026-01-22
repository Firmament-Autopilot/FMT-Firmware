"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .enums import PolicyType
from ...common.policy_validator import PolicyValidator


class PolicyValidatorMXS40Sv2(PolicyValidator):
    """Policy validator for MXS40v2 platform"""

    schema_dir = os.path.join(os.path.dirname(__file__), 'schemas')

    schemas = {
        PolicyType.SECURE: os.path.join(
            schema_dir, 'cyw20829_secure.json_schema'),
        PolicyType.NO_SECURE: os.path.join(
            schema_dir, 'cyw20829_no_secure.json_schema'),
        PolicyType.REPROVISIONING_SECURE: os.path.join(
            schema_dir, 'cyw20829_reprovisioning_secure.json_schema'),
        PolicyType.REPROVISIONING_NO_SECURE: os.path.join(
            schema_dir, 'cyw20829_reprovisioning_no_secure.json_schema'),
        PolicyType.HCI_SECURE:
            os.path.join(schema_dir, 'cyw20829_secure.json_schema'),
        'normal': None
    }

    def __init__(self, policy_parser, dependency_validator):
        super().__init__(policy_parser, None,
                         self.schemas, dependency_validator)
