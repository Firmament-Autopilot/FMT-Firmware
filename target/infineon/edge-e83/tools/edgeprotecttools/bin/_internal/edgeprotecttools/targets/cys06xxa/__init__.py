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
from .target_builder import CYS06xxA_Builder

target_map = {
    'cy8ckit-064s0s2-4343w': {
        'class': CYS06xxA_Builder,
        'family': 'PSoC64 Kit targets',
        'display_name': 'PSoC64 2M',
        'type': 'kit',
        'platform': 'psoc64'
    },
    'cys06xxa': {
        'class': CYS06xxA_Builder,
        'family': 'PSoC64 Standard Secure Family',
        'display_name': 'PSoC64 2M',
        'type': 'family',
        'platform': 'psoc64'
    }
}
