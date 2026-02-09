"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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


class MemoryMapCYW20829:

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
