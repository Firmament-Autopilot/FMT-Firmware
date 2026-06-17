"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from ....core import RegisterMapBaseP64


class RegisterMapCYB06xx5(RegisterMapBaseP64):

    #
    #  Entrance exam registers and constants
    #

    @property
    def ENTRANCE_EXAM_FW_STATUS_REG(self):
        return 0x0803e000

    @property
    def ENTRANCE_EXAM_FW_STATUS_VAL(self):
        return 0xF0000000

    @property
    def ENTRANCE_EXAM_FW_STATUS_RE_VAL(self):
        return 0xA0000000

    @property
    def ENTRANCE_EXAM_FW_STATUS_MASK(self):
        return 0xF0800000

    @property
    def ENTRANCE_EXAM_SRAM_ADDR(self):
        return 0x0802c000

    @property
    def ENTRANCE_EXAM_SRAM_SIZE(self):
        return 0x00004000

    @property
    def ENTRANCE_EXAM_REGION_HASH_ADDR(self):
        return 0x10000000

    @property
    def ENTRANCE_EXAM_REGION_HASH_SIZE(self):
        return 0x00070000

    @property
    def ENTRANCE_EXAM_REGION_HASH_MODE(self):
        return 255

    @property
    def ENTRANCE_EXAM_REGION_HASH_EXPECTED_VAL(self):
        return 0x00

    @property
    def FB_FW_STATUS_FIRMWARE_RUNNING_CM4(self):
        return 0xA1000100

    @property
    def FB_FW_STATUS_FIRMWARE_RUNNING_CM0(self):
        return 0xA1000101

    #
    # LVD registers
    #

    @property
    def PWR_LVD_CTL(self):
        return 0x40260008

    @property
    def PWR_LVD_STATUS(self):
        return 0x4026001C

    #
    # PSoC 6 BLE register addresses
    #

    @property
    def CYREG_IPC2_STRUCT_ACQUIRE(self):
        return 0x40220040

    @property
    def CYREG_IPC2_STRUCT_NOTIFY(self):
        return 0x40220048

    @property
    def CYREG_IPC2_STRUCT_DATA(self):
        return 0x4022004C

    @property
    def CYREG_IPC2_STRUCT_LOCK_STATUS(self):
        return 0x4022005C

    @property
    def CYREG_EFUSE_SECURE_HASH(self):
        return 0x402c0814
