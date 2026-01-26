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
import logging


logger = logging.getLogger(__name__)


class AssetMapCYW559xx:
    """Asset map for CYW559xx"""

    @staticmethod
    def get(p, **kwargs):
        """
        RAM applications asset map
        @params p: Policy parser
        @return: Initialized asset map

        Map fields description:
        size  - asset size in bytes
        shift - represents asset bits number that store a parameter. It says
                about the number of bits the value should be shifted to the left
        mask  - the number of bits used to store the asset item
        value - integer value of the bits.
        """
        policy_type = kwargs.get('policy_type')
        if not policy_type:
            policy_type = p.policy_type()

        if policy_type == 'oem_provisioning':
            return AssetMapCYW559xx.oem_provisioning_assets(p)

        raise ValueError(f"Unknown policy type '{policy_type}'")

    @staticmethod
    def oem_provisioning_assets(p):
        """Gets bytes for OEM provisioning assets"""
        assets = {
            'oem_mandatory_field_type': {
                'size': 4,
                'data': [
                    {
                        'name': 'type',
                        'shift': 0,
                        'value': p.oem_mandatory_field_type(ret_value=True)
                    },
                ],
            },
            'oem_public_key': {
                'size': 32,
                'data': [
                    {
                        'name': 'value',
                        'shift': 0,
                        'value': p.oem_public_key()
                    },
                ],
            },
            'provisioning_key_type': {
                'size': 4,
                'data': [
                    {
                        'name': 'type',
                        'shift': 0,
                        'value': p.provisioning_key_type(ret_value=True)
                    },
                ],
            },
            'provisioning_key_data': {
                'size': 64,
                'data': [
                    {
                        'name': 'value',
                        'shift': 0,
                        'value': p.provisioning_key_data()
                    },
                ],
            },
            'code_encryption_key_type': {
                'size': 4,
                'data': [
                    {
                        'name': 'type',
                        'shift': 0,
                        'value': p.code_encryption_key_type(ret_value=True)
                    },
                ],
            },
            'code_encryption_key_data': {
                'size': 64,
                'data': [
                    {
                        'name': 'value',
                        'shift': 0,
                        'value': p.code_encryption_key_data()
                    },
                ],
            },
            'nv_counter': {
                'size': 4,
                'data': [
                    {
                        'name': 'type',
                        'shift': 0,
                        'value': p.nv_counter()
                    },
                ],
            },
            'padding': {
                'size': 16,
                'data': [
                    {
                        'name': 'padding',
                        'shift': 0,
                        'value': bytes(16)
                    },
                ],
            }
        }
        return assets
