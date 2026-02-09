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
from collections import namedtuple

Register = namedtuple('Register', 'addr size')


class RegisterMapPse8x:
    """Register map used by PSoC Edge E8x target"""
    @property
    def non_secure_mask(self):
        """Non-secure RRAM memory access"""
        return 0x0fffffff

    @property
    def extended_boot_info(self):
        """Extended boot info (4 bytes mode + 4 bytes status)"""
        return Register(0x34000000, 8)

    @property
    def device_id_to(self):
        """Device_ID_TO address and size. Includes checksum"""
        return Register(0x13c2b00e, 7)

    @property
    def device_id_mpn(self):
        """Device_ID_MPN address and size. Includes checksum"""
        return Register(0x13c2b015, 6)

    @property
    def die_id(self):
        """Die ID address and size. Includes checksum"""
        return Register(0x13c2b000, 14)

    @property
    def l0_version(self):
        """Version of ROM_BOOT and RRAM_BOOT
        (8 * 2 + 4-byte checksum that includes the address)"""
        return Register(0x13c2b01b, 20)

    @property
    def l1_version(self):
        """Version of BASE_SE_RT_SERVICES, SE_RT_SERVICES and CM33_L1_BOOT
        (8 * 3 + 4-byte checksum that includes the address)"""
        return Register(0x13c2b02f, 28)

    @property
    def bootrow_0(self):
        """BOOTROW_0 address"""
        return 0x52400420

    @property
    def bootrow_1(self):
        """BOOTROW_1 address"""
        return 0x52400424

    @property
    def bootrow_2(self):
        """BOOTROW_2 address"""
        return 0x52400428

    @property
    def bootrow_3(self):
        """BOOTROW_3 address"""
        return 0x5240042C

    @property
    def boot_dlm_ctl(self):
        """BOOT_DLM_CTL register address"""
        return 0x52400404

    @property
    def boot_dlm_ctl2(self):
        """BOOT_DLM_CTL2 register address"""
        return 0x52400408

    @property
    def boot_dlm_status(self):
        """BOOT_DLM_STATUS register address"""
        return 0x5240040C

    @property
    def res_soft_ctl(self):
        """RES_SOFT_CTL register address"""
        return 0x52400410

    @property
    def boot_status(self):
        """BOOT_STATUS register address"""
        return 0x52400418
