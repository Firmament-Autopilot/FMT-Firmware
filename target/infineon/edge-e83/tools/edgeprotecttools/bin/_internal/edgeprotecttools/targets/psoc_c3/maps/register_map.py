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


class RegisterMapPsocC3:
    """Register map used by PSoC C3 target"""

    @property
    def BOOTROM_VERSION(self):
        return 0x1080FFF8

    @property
    def CPUSS_PROTECTION(self):
        return 0x521C2004

    @property
    def BOOTROW(self):
        return 0x52610180

    @property
    def TST_DEBUG_CTL(self):
        return 0x52200404

    @property
    def TST_DEBUG_STATUS(self):
        return 0x5220040C

    @property
    def BOOT_DLM_CTL_2(self):
        return 0x52200408

    @property
    def RES_SOFT_CTL(self):
        return 0x52200410

    #
    # LVD registers
    #

    @property
    def PWR_LVD_CTL(self):
        return 0x52201020

    @property
    def PWR_LVD_STATUS(self):
        return 0x52200040
