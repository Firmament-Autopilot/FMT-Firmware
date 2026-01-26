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


class MemoryMapPsocC3:
    """Memory map used by PSoC C3 target"""

    @property
    def BOOTROM_NEXT_APP_HEADER_SIZE(self):
        return 0x20

    @property
    def BOOTROM_RAM_APP_HEADER_SIZE(self):
        return 0x200

    @property
    def MCUBOOT_USER_APP_HEADER_SIZE(self):
        return 0x400

    @property
    def MAX_SLOT_SIZE(self):
        return 0x1000000

    @property
    def FLASH_SIZE(self):
        return None

    @property
    def MIN_EXT_ERASE_SIZE(self):
        return 0x1000

    @property
    def SFLASH_DIE_ID_0(self):
        return 0x03400600

    @property
    def SFLASH_DIE_ID_1(self):
        return 0x03400604

    @property
    def SFLASH_DIE_ID_2(self):
        return 0x03400608

    @property
    def SFLASH_DEVICE_ID_0(self):
        return 0x03400000

    @property
    def SFLASH_DEVICE_ID_1(self):
        return 0x03400004

    @property
    def SFLASH_OFFSET_0(self):
        return 0

    @property
    def SFLASH_OFFSET_1(self):
        return 0x10000000

    @property
    def DLM_BASE_ADDR(self):
        """DLM base address"""
        return 0x34003000

    @property
    def DLM_SLOT_SIZE(self):
        """DLM maximum slot size"""
        return 0xB000
