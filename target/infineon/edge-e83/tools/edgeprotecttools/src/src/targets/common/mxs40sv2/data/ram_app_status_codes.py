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
from .....core.status_codes_base import StatusCodesBase


class RamAppStatusMXS40Sv2(StatusCodesBase):
    """RAM applications status codes for the MXS40Sv2 platform"""

    def status_codes(self):
        """Gets a dictionary containing RAM applications status codes
        for the MXS40Sv2 platform
        """
        return {
            0xF2A00001: {
                "status": "CYAPP_SUCCESS",
                "desc": "The provisioning application completed successfully"
            },
            0x45000002: {
                "status": "CYAPP_BAD_PARAM",
                "desc": "One or more invalid parameters"
            },
            0x45000003: {
                "status": "CYAPP_LOCKED",
                "desc": "Resource lock failure"
            },
            0x45000004: {
                "status": "CYAPP_STARTED",
                "desc": "Operation started but not necessarily completed yet"
            },
            0x45000005: {
                "status": "CYAPP_FINISHED",
                "desc": "Operation finished"
            },
            0x45000006: {
                "status": "CYAPP_CANCELED",
                "desc": "Operation canceled"
            },
            0x45000007: {
                "status": "CYAPP_TIMEOUT",
                "desc": "Operation timed out"
            },
            0xF2A00010: {
                "status": "CYAPP_APP_RUNNING",
                "desc": "The provisioning application is in-progress"
            },
            0x45000020: {
                "status": "CYAPP_OTP_INIT_FAILED",
                "desc": "Fail to initialize OTP"
            },
            0x45000021: {
                "status": "CYAPP_OTP_BOOTROW_WRITE_FAILED",
                "desc": "Fail to update LCS"
            },
            0x45000022: {
                "status": "CYAPP_OTP_BOOTROW_READ_FAILED",
                "desc": "Fail to read LCS"
            },
            0x45000023: {
                "status": "CYAPP_OTP_WRITE_FAILED",
                "desc": "Fail to program object into OTP"
            },
            0x45000024: {
                "status": "CYAPP_OTP_READ_FAILED",
                "desc": "Fail to read object from OTP"
            },
            0x45000030: {
                "status": "CYAPP_LCS_INVALID",
                "desc": "Current device LCS is illegal "
                        "to perform provisioning or re-provisioning"
            },
            0x45000031: {
                "status": "CYAPP_OEM_KEY_ALREADY_REVOKED",
                "desc": "The OEM key 0 was revoked. "
                        "This is operation can be done only once"
            },
            0x45000032: {
                "status": "CYAPP_ICV_KEY_ALREADY_REVOKED",
                "desc": "The ICV key 0 was revoked. "
                        "This is operation can be done only once"
            },
            0x45000033: {
                "status": "CYAPP_SIGNATURE_VERIF_FAILED",
                "desc": "Fail to verify input parameters digital signature"
            },
            0x45000034: {
                "status": "CYAPP_KEY_0_ALREADY_PROGRAMMED",
                "desc": "The OEM key 0 was programmed. "
                        "This is operation can be done only once"
            },
            0x45000035: {
                "status": "CYAPP_KEY_1_ALREADY_PROGRAMMED",
                "desc": "The OEM key 1 was programmed. "
                        "This is operation can be done only once"
            },
            0x45000036: {
                "status": "CYAPP_OEM_ASSETS_ALREADY_PROGRAMMED",
                "desc": "The OEM assets were programmed. "
                        "This is operation can be done only once"
            },
            0x45000037: {
                "status": "CYAPP_OEM_SECURE_KEY_ALREADY_PROGRAMMED",
                "desc": "The OEM_SECURE_KEY assets is already programmed. "
                        "This operation can be done only once"
            },
            0x45000100: {
                "status": "CYAPP_PARAM_NV_CNT_INVALID",
                "desc": "The input parameter NV counter is not valid"
            },
            0x45000101: {
                "status": "CYAPP_PARAM_OEM_KEY_0_HASH_INVALID",
                "desc": "The input parameter OEM key 0 hash is not valid"
            },
            0x45000102: {
                "status": "CYAPP_PARAM_OEM_KEY_1_HASH_INVALID",
                "desc": "The input parameter OEM key 1 hash is not valid"
            },
            0x45000103: {
                "status": "CYAPP_PARAM_PUBKEY_INVALID",
                "desc": "The OEM public key for the digital signature "
                        "verification does not correspond to OEM public key "
                        "hash provisioned in the OTP"
            },
            0x45000104: {
                "status": "CYAPP_PARAM_CONTROL_WORD_INVALID",
                "desc": "The input parameter control word is not valid"
            },
            0x45000105: {
                "status": "CYAPP_PARAM_TARGET_LCS_INVALID",
                "desc": "The input parameter target LCS is not valid."
                        " The range of valid values is NORMAL,"
                        " NORMAL_NO_SECURE and SECURE"
            },
            0x45000106: {
                "status": "CYAPP_RMA_CERT_VERIF_FAILED",
                "desc": "Fail to verify certificate for RMA LCS transition"
            },
            0x45000107: {
                "status": "CYAPP_PARAM_ACCESS_RESTRICT_INVALID",
                "desc": "The input parameter ACCESS_RESTRICT has invalid "
                        "configuration"
            },
            0x45000108: {
                "status": "CYAPP_PARAM_OEM_SECURE_KEY_INVALID",
                "desc": "The input parameter OEM_SECURE_KEY is not valid"
            }
        }
