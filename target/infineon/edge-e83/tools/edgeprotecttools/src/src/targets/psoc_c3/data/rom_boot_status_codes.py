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
from ....core.status_codes_base import StatusCodesBase


class RomBootStatusPsocC3(StatusCodesBase):
    """ROM BOOT status codes for PSoC C3"""

    def status_codes(self):
        """Gets a dictionary containing ROM BOOT status codes for PSoC C3"""

        return {
            0x0D50B002: {
                "status": "CYBOOT_SUCCESS",
                "desc": "Success"
            },
            0xBAF00001: {
                "status": "CYBOOT_BAD_PARAM",
                "desc": "One or more invalid parameters"
            },
            0xBAF00002: {
                "status": "CYBOOT_LOCKED",
                "desc": "Resource lock failure"
            },
            0xBAF00003: {
                "status": "CYBOOT_STARTED",
                "desc": "Operation started but not necessarily completed yet"
            },
            0xBAF00004: {
                "status": "CYBOOT_FINISHED",
                "desc": "Operation completed"
            },
            0xBAF00005: {
                "status": "CYBOOT_CANCELED",
                "desc": "Operation canceled"
            },
            0xBAF00006: {
                "status": "CYBOOT_TIMEOUT",
                "desc": "Operation timed out"
            },
            0xBAF00007: {
                "status": "CYBOOT_NOT_IMPLEMENTED",
                "desc": "Invalid SMIF configuration"
            },
            0xBAF00008: {
                "status": "CYBOOT_FAILED",
                "desc": "A generic failure"
            },
            0xBAF00011: {
                "status": "CYBOOT_L1_APP_DESCR_INVALID",
                "desc": "Invalid L1 application descriptor. The boostrap size (inside L1 application descriptor) is greater than the image"
            },
            0xBAF00013: {
                "status": "CYBOOT_SERV_APP_DESCR_INVALID",
                "desc": "Invalid verification application descriptor content"
            },
            0xBAF00020: {
                "status": "CYBOOT_BOOTROW_READ_FAILED",
                "desc": "Read the bootrow value from the OTP failed"
            },
            0xBAF00021: {
                "status": "CYBOOT_BOOTROW_CORRUPTED",
                "desc": "BOOTROW corrupted"
            },
            0xBAF00022: {
                "status": "CYBOOT_OTP_INIT_FAILED",
                "desc": "OTP initialisation failed"
            },
            0xBAF00023: {
                "status": "CYBOOT_OTP_READ_FAILED",
                "desc": "OTP read operation failed"
            },
            0xBAF00024: {
                "status": "CYBOOT_OTP_WRITE_FAILED",
                "desc": "OTP write operation failed"
            },
            0xBAF00025: {
                "status": "CYBOOT_OTP_SMIF_CFG_INVALID",
                "desc": "Invalid SMIF configuration from OTP data structure"
            },
            0xBAF00026: {
                "status": "CYBOOT_ASSET_FACTORY_HASH_INVALID",
                "desc": "ASSET/FACTORY hash validation failed"
            },
            0xBAF00030: {
                "status": "CYBOOT_PUBKEY_REQUEST_FAILED",
                "desc": "Public key hash request failed"
            },
            0xBAF00031: {
                "status": "CYBOOT_PUBKEY_FORMAT_INVALID",
                "desc": "Incorrect the input key data"
            },
            0xBAF00032: {
                "status": "CYBOOT_PUBKEY_VALIDATION_FAILED",
                "desc": "Calculated hash does not match"
            },
            0xBAF00033: {
                "status": "CYBOOT_PUBKEY_HASH_PTE_INVALID",
                "desc": "Invalid PTE public key hash"
            },
            0xBAF00034: {
                "status": "CYBOOT_PUBKEY_HASH_ICV_INVALID",
                "desc": "Invalid ICV public key hash"
            },
            0xBAF00035: {
                "status": "CYBOOT_PUBKEY_HASH_OEM_INVALID",
                "desc": "Invalid OEM public key hash"
            },
            0xBAF00036: {
                "status": "CYBOOT_APP_VALIDATION_FAILED",
                "desc": "RAM application validation failed"
            },
            0xBAF00037: {
                "status": "CYBOOT_APP_LAUNCH_ADDR_INVALID",
                "desc": "Vector Table address is zero (IDLE loop)"
            },
            0xBAF00038: {
                "status": "CYBOOT_SIGNATURE_INVALID",
                "desc": "Verification of the digital signature with the RSASSA-PKCS1-v2.1 algorithm failed"
            },
            0xBAF00039: {
                "status": "CYBOOT_MCUBOOT_INTERNAL_ASSERT",
                "desc": "MCUBOOT internal assert"
            },
            0xBAF0003A: {
                "status": "CYBOOT_RAM_APP_FORMAT_INVALID",
                "desc": "Invalid RAM application format"
            },
            0xBAF0004A: {
                "status": "CYBOOT_FLASH_TRIM_INVALID",
                "desc": "Error in Flash trims"
            },
            0xBAF0004B: {
                "status": "CYBOOT_FLASH_INIT_FAILED",
                "desc": "Flash init error"
            },
            0xBAF0004C: {
                "status": "CYBOOT_FLASH_ADDR_INVALID",
                "desc": "Flash address is invalid"
            },
            0xBAF0004D: {
                "status": "CYBOOT_FLASH_PARAM_INVALID",
                "desc": "A parameter value for Flash API is invalid"
            },
            0xBAF0004E: {
                "status": "CYBOOT_FAULT_UNEXPECTED",
                "desc": "A parameter value for Flash ECC NC fault is unexpected"
            },
            0xBAF00050: {
                "status": "CYBOOT_NUM_ZEROS_0_INVALID",
                "desc": "Invalid status of OTP zeros check 0"
            },
            0xBAF00051: {
                "status": "CYBOOT_NUM_ZEROS_1_INVALID",
                "desc": "Invalid status of OTP zeros check 1"
            },
            0xBAF00052: {
                "status": "CYBOOT_NUM_ZEROS_2_INVALID",
                "desc": "Invalid status of OTP zeros check 2"
            },
            0xBAF00053: {
                "status": "CYBOOT_NUM_ZEROS_3_INVALID",
                "desc": "Invalid status of OTP zeros check 3"
            },
            0xBAF00054: {
                "status": "CYBOOT_NUM_ZEROS_KEY_0_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_key_0_hash assets"
            },
            0xBAF00055: {
                "status": "CYBOOT_NUM_ZEROS_KEY_1_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_key_1_hash assets"
            },
            0xBAF00056: {
                "status": "CYBOOT_NUM_ZEROS_ASSET_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_asset_hash assets"
            },
            0xBAF00057: {
                "status": "CYBOOT_NUM_ZEROS_FACTORY_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_factory_hash assets"
            },
            0xBAF00058: {
                "status": "CYBOOT_NUM_ZEROS_SECURE_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_secure_hash assets"
            },
            0xBAF00059: {
                "status": "CYBOOT_NUM_ZEROS_PROT_FW_HASH_INVALID",
                "desc": "Invalid calculation number of zeros for num_zeros_prot_fw_hash assets"
            },
            0x0D500067: {
                "status": "CYBOOT_NEXT_APP_LAUNCHED",
                "desc": "Next application launched"
            },
            0x0D500068: {
                "status": "CYBOOT_IDLE_BRANCH_REACHED",
                "desc": "Idle branch reached"
            },
            0x0D500080: {
                "status": "CYBOOT_WFA_POLLING",
                "desc": "Report status WFA polling"
            },
            0x0D500081: {
                "status": "CYBOOT_SERVICE_APP_LAUNCHED",
                "desc": "Service aplication launched"
            },
            0x0D500082: {
                "status": "CYBOOT_SERVICE_APP_NOT_LAUNCHED",
                "desc": "Indicate application launch failed"
            },
            0x0D500083: {
                "status": "CYBOOT_WFA_REQUEST_INVALID",
                "desc": "Invalid WFA reqest"
            },
            0x0D500084: {
                "status": "CYBOOT_DEBUG_TOKEN_PASSED",
                "desc": "Debug certificate passed"
            },
            0x0D500085: {
                "status": "CYBOOT_DEBUG_TOKEN_FAILED",
                "desc": "Debug certificate failed"
            },
            0xBAF000A0: {
                "status": "CYBOOT_IMG_INVALID",
                "desc": "The image validation failed"
            },
            0xBAF000AD: {
                "status": "CYBOOT_FLASH_AREA_INVALID",
                "desc": "The access to flash area failed"
            },
            0xBAF000AE: {
                "status": "CYBOOT_TLV_INVALID",
                "desc": "Invalid TLV iterator"
            },
            0xBAF000AF: {
                "status": "CYBOOT_TLV_NO_MORE_FOUND",
                "desc": "No more TLVs with the matching type are available"
            },
            0xBAF000A1: {
                "status": "CYBOOT_NO_BOOT_IMAGE_FOUND",
                "desc": "No boot image found"
            }
        }
