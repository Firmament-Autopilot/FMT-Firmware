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
from .....core.status_codes_base import StatusCodesBase


class ExtendedBootStatus(StatusCodesBase):
    """Extended boot status codes for MXS22 platform"""

    def status_codes(self):
        """Gets a dictionary containing extended boot status codes
        for the MXS22 platform
        """
        return {
            0xEE000000: {
                "status": "SUCCESS",
                "desc": "No errors"
            },
            0xEE000001: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000002: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000003: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000004: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000005: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000006: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000007: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000008: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE000009: {
                "status": "ERROR_DFU_HANDLER",
                "desc": "DFU handler error"
            },
            0xEE00000A: {
                "status": "ERROR_CM33_OVERCLOCKED",
                "desc": "CM33 core is overclocked"
            },
            0xEE00000B: {
                "status": "ERROR_FI_DETECTED",
                "desc": "FI detected"
            },
            0xEE00000C: {
                "status": "ERROR_EXT_MEM_INIT_FAILED",
                "desc": "External memory initialization failed"
            },
            0xEE00000D: {
                "status": "ERROR_DIE_ID_READ",
                "desc": "DIE_ID reading error"
            },
            0xEE00000E: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE00000F: {
                "status": "ERROR_IMAGE_FORMAT",
                "desc": "Image validation. Image format is wrong"
            },
            0xEE000010: {
                "status": "ERROR_IMAGE_HASH_SIG_SCNT",
                "desc": "Image validation. Hash, Signature or Security counter is wrong"
            },
            0xEE000011: {
                "status": "ERROR_IMAGE_VECTOR_TABLE",
                "desc": "Image validation. Vector table is wrong"
            },
            0xEE000012: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE000013: {
                "status": "ERROR_HW_INIT_FAILED",
                "desc": "Hardware initialization failed"
            },
            0xEE000014: {
                "status": "ERROR_SET_CORE_CLOCK_FAILED",
                "desc": "Set core clock failed"
            },
            0xEE000015: {
                "status": "ERROR_CLEAR_STAGING_FLAG_FAILED",
                "desc": "STAGING_SE_RAM_APP_FLAG clearing failed"
            },
            0xEE000016: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE000017: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE000018: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE000019: {
                "status": "ERROR_RESERVED",
                "desc": "For internal use only/Reserved"
            },
            0xEE00001A: {
                "status": "ERROR_RECOVERY_MODE",
                "desc": "Recovery mode error"
            },
            0xEE00001B: {
                "status": "ERROR_RESERVED",
                "desc": "No description provided"
            },
            0xEE00001C: {
                "status": "ERROR_RESERVED",
                "desc": "No description provided"
            },
            0xEE00001D: {
                "status": "ERROR_RESERVED",
                "desc": "No description provided"
            },
            0xEE00001E: {
                "status": "ERROR_RESERVED",
                "desc": "No description provided"
            },
            0xEE00001F: {
                "status": "ERROR_RESERVED",
                "desc": "No description provided"
            },
            0xEE000020: {
                "status": "ERROR_CLEAR_CM33_SRAM_FAILED",
                "desc": "DFU clearing CM33 SRAM failed"
            },
            0xEE000021: {
                "status": "ERROR_SE_RT_SERVICES_NOT_FOUND",
                "desc": "SE RT Services has not been found"
            },
            0xEE000022: {
                "status": "ERROR_NEXT_APP_EXT_MEM_NOT_FOUND",
                "desc": "Boot address of the next application points to External memory but the memory not found."
            },
            0xEE000023: {
                "status": "ERROR_NEXT_IMAGE_VECTOR_STACK",
                "desc": "Image validation. Reset vector or stack pointer of the next image are wrong"
            },
            0xEE000024: {
                "status": "ERROR_NEXT_APP_UNKNOWN_MEM",
                "desc": "Boot address of the next application belongs unknown memory range"
            },
            0xEE000025: {
                "status": "ERROR_AUTO_COPY_SRAM_FAILED",
                "desc": "Auto copy to SRAM failed"
            },
            0xEE000026: {
                "status": "ERROR_STACK_PROTECTION",
                "desc": "Detect Stack protection error"
            },
            0xEE000027: {
                "status": "ERROR_MPU_CONFIG_FAILED",
                "desc": "MPU configuration failed"
            },
            0xEE000028: {
                "status": "ERROR_MPU_ATTR_WRONG",
                "desc": "MPU attribute is wrong"
            },
            0xEE000029: {
                "status": "ERROR_MPU_ENABLE_FAILED",
                "desc": "MPU enabling failed"
            },
            0xEE00002A: {
                "status": "ERROR_MPU_INTERNAL",
                "desc": "MPU internal error"
            },
            0xEE00002B: {
                "status": "ERROR_TRNG_INIT_FAILED",
                "desc": "TRNG initialization failed"
            },
            0xEE00002C: {
                "status": "ERROR_PRNG_INIT_FAILED",
                "desc": "PRNG initialization failed"
            },
            0xEE00002D: {
                "status": "ERROR_STACK_PROT_INIT_FAILED",
                "desc": "Stack protection initialization failed"
            },
            0xEE00002E: {
                "status": "ERROR_GPIO_PINS_FROZEN",
                "desc": "GPIO pins are frozen"
            }
        }
