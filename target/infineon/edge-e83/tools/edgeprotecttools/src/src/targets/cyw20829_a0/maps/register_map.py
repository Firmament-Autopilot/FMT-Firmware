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
from ....core import RegisterMapBaseMXS40Sv2


class RegisterMap_cyw20829(RegisterMapBaseMXS40Sv2):

    @property
    def BOOTROM_VERSION(self):
        return 0x20000004

    @property
    def BOOTROM_BUILD(self):
        return 0x20000008

    @property
    def CPUSS_PROTECTION(self):
        return 0x401C2004

    @property
    def BOOTROW(self):
        return 0x40810180

    @property
    def TST_DEBUG_CTL(self):
        return 0x40200404

    @property
    def TST_DEBUG_STATUS(self):
        return 0x40200408

    @property
    def RES_SOFT_CTL(self):
        return 0x40200410

    @property
    def EFUSE_DIE_ID_0(self):
        return 0x40810874

    @property
    def EFUSE_DIE_ID_1(self):
        return 0x40810878

    @property
    def EFUSE_DIE_ID_2(self):
        return 0x4081087C

    @property
    def EFUSE_DEVICE_ID(self):
        return 0x40810870

    @property
    def EFUSE_CTRL_ADDR(self):
        return 0x40810000
    #
    # LVD registers
    #

    @property
    def PWR_LVD_CTL(self):
        return 0x40201020

    @property
    def PWR_LVD_STATUS(self):
        return 0x40200040
