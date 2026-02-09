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
from ...common.mxs40sv2.data import RamAppStatusMXS40Sv2


class RamAppStatusPsocC3(RamAppStatusMXS40Sv2):
    """RAM applications status codes for PSoC C3"""

    def status_codes(self):
        """Gets a dictionary containing RAM applications status codes
        for PSoC C3
        """
        codes = super().status_codes()
        new_codes = {
            0x45000025: {
                "status": "CYAPP_OTP_BOOTROW_CORRUPTED",
                "desc": "BOOTROW corrupted."
            },
            0x45000026: {
                "status": "CYAPP_NUM_ZEROS_INVALID",
                "desc": "Invalid status of OTP zeros check."
            },
            0x45000037: {
                "status": "CYAPP_HASH_CALCULATION_FAILED",
                "desc": "Hash calculation failed."
            },
            0x45000038: {
                "status": "CYAPP_INVALID_BOOT_CFG_ID",
                "desc": "Invalid BOOT_CFG_ID configuration."
            },
            0x45000039: {
                "status": "CYAPP_HUK_GEN_FAILED",
                "desc": "Fail to generate Wrap Master Key key"
            },
            0x4500003A: {
                "status": "CYAPP_DFU_FAILED",
                "desc": "DFU flow failed"
            },
            0x4500003B: {
                "status": "CYAPP_PROT_FW_POLICY_DISABLED",
                "desc": "Protected FW policy is not configured"
            },
            0x4500003C: {
                "status": "CYAPP_MPC_POLICY_INVALID",
                "desc": "MPC_POLICY invalid"
            },
            0x4500003D: {
                "status": "CYAPP_OTP_NOT_DEFAULT",
                "desc": "OTP assets are not zeros"
            },
            0x4500003E: {
                "status": "CYAPP_BAD_APP_LAYOUT",
                "desc": "Application start addr and/or size invalid"
            },
            0x4500003F: {
                "status": "CYAPP_PROT_FW_KEY_ALREADY_REVOKED",
                "desc": "The PROT_FW key 0 was revoked. "
                        "This operation can be done only once"
            },
            0x45000105: {
                "status": "CYAPP_INVALID_LCS",
                "desc": "The input parameter target LCS is not valid. "
                        "The range of valid values are PROVISIONED, "
                        "NORMAL_PROVISIONED, and SECURE"
            },
            0x45000108: {
                "status": "CYAPP_RMA_ATTEMPT_COUNTER_INVALID",
                "desc": "RMA_ATTEMPT_COUNTER equal to zero"
            },
            0x45000109: {
                "status": "CYAPP_IAK_ALREADY_PROGRAMMED",
                "desc": "IAK already programmed"
            },
            0x4500010A: {
                "status": "CYAPP_BOOTROW_CHECK_FAILED",
                "desc": "BOOTROW check failed"
            },
            0x4500010B: {
                "status": "CYAPP_EFUSE_CHECK_FAILED",
                "desc": "EFUSE data check failed"
            }
        }
        codes.update(new_codes)
        return codes
