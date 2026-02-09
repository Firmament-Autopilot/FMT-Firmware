"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from .target_builder import CYB06xx5A1Builder

target_map = {
    'cy8cproto-064b0s3': {
        'default': {
            'class': CYB06xx5A1Builder,
            'family': 'PSoC64 Kit targets',
            'display_name': 'PSoC64 512K',
            'type': 'kit',
            'platform': 'psoc64'
        },
        'a1': {
            'class': CYB06xx5A1Builder,
            'family': 'PSoC64 Kit targets',
            'display_name': 'PSoC64 512K',
            'type': 'kit',
            'platform': 'psoc64'
        }
    },
    'cyb06xx5': {
        'default': {
            'class': CYB06xx5A1Builder,
            'family': 'PSoC64 Secure Boot Family',
            'display_name': 'PSoC64 512K',
            'type': 'family',
            'platform': 'psoc64'
        },
        'a1': {
            'class': CYB06xx5A1Builder,
            'family': 'PSoC64 Secure Boot Family',
            'display_name': 'PSoC64 512K',
            'type': 'family',
            'platform': 'psoc64'
        }
    }
}
