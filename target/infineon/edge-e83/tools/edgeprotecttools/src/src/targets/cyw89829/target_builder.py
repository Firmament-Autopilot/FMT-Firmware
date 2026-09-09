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
from ..cyw20829 import CYW20829B1Builder


class CYW89829B1Builder(CYW20829B1Builder):
    """ CYW89829 B1 target builder """

    def get_test_packages(self):
        return {
            'testapps': {
                'package': 'testapps_cyw89829_b1', 'flow_name': 'testapps'
            },
            'testapps_si': {
                'package': 'testapps_cyw89829_b1', 'flow_name': 'testapps_si'
            }
        }

    def get_silicon_id(self):
        """Gets the target silicon ID"""
        return {
            'id': [0xEB4E, 0xEB51],
            'rev': [0x21],
            'family': 0x110
        }
