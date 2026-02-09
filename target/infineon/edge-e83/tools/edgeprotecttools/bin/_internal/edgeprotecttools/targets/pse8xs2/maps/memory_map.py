"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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


class MemoryMapPse8x:
    """Memory map used by PSoC Edge E8x target"""

    @property
    def BOOTROM_RAM_APP_HEADER_SIZE(self):
        """MCUboot header size for RAM application"""
        return 0x20

    @property
    def MAX_SLOT_SIZE(self):
        """Maximum slot size"""
        return 0x100000

    @property
    def SRAM_BASE_ADDR(self):
        """SRAM base address"""
        return 0x34000000

    @property
    def FLASH_SIZE(self):
        """Internal flash size"""
        return None

    @property
    def DLM_BASE_ADDR(self):
        """DLM base address"""
        return 0x34000000

    @property
    def DLM_SLOT_SIZE(self):
        """DLM maximum slot size"""
        return 0xA000
