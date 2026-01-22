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
from .target_builder import PSE8xS2Builder

target_map = {
    "pse84": {
        'default': {
            'class': PSE8xS2Builder,
            'family': 'PSOC™ Edge Family',
            'display_name': 'PSOC™ Edge E84',
            'type': 'family',
            'platform': 'mxs22'
        },
        'b0': {
            'class': PSE8xS2Builder,
            'family': 'PSOC™ Edge Family',
            'display_name': 'PSOC™ Edge E84',
            'type': 'family',
            'platform': 'mxs22'
        }
    },
    "pse8xs2": {
        'default': {
            'class': PSE8xS2Builder,
            'family': 'PSOC™ Edge Family',
            'display_name': 'PSOC™ Edge E8x',
            'type': 'family',
            'platform': 'mxs22'
        },
        'b0': {
            'class': PSE8xS2Builder,
            'family': 'PSOC™ Edge Family',
            'display_name': 'PSOC™ Edge E8x',
            'type': 'family',
            'platform': 'mxs22'
        }
    }
}
