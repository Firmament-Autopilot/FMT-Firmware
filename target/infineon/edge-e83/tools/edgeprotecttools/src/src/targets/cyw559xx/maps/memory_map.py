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


class MemoryMapCYW559xx:
    """Memory map used by CYW559xx target"""

    @property
    def DLM_BASE_ADDR(self):
        """DLM base address"""
        return 0x00000000

    @property
    def DLM_SLOT_SIZE(self):
        """DLM maximum slot size"""
        return 0xA000

    @property
    def IN_PARAMS_BASE_ADDR(self):
        """Input parameters base address"""
        return 0x80430000
