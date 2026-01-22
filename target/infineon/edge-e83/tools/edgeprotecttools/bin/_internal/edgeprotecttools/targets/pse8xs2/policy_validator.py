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
import os

from ..common.mxs22 import PolicyValidatorMXS22


class PolicyValidatorPSE8xB0(PolicyValidatorMXS22):
    """Policy validator for PSE8x B0 platform"""

    schema_dir = os.path.join(os.path.dirname(__file__), 'schemas')

    _schemas = {
        'prov_oem': os.path.join(
            schema_dir, 'policy_prov_oem_schema.json_schema'),
        'prov_oem_L2': os.path.join(
            schema_dir, 'policy_prov_oem_schema.json_schema'),
        'prov_oem_L4': os.path.join(
            schema_dir, 'policy_prov_oem_schema.json_schema'),
        'device_identity': None,
        'device_identity_item': None,
        'device_identity_images': None,
        'prov_icv_sort': None,
        'prov_icv_provisioned': None,
        'prov_icv_normal_provisioned': None,
        'device_integrity_exam': None
    }
