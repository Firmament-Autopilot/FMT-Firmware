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
from .....core.status_codes_base import StatusCodesBase


class RamAppStatusMXS22(StatusCodesBase):
    """RAM applications status codes for the MXS22 platform"""

    def status_codes(self):
        """Gets a dictionary containing RAM applications status codes
        for the MXS22 platform
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
            0x45000008: {
                "status": "CYAPP_FAILED",
                "desc": "RAM Application failed"
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
                "status": "CYAPP_LCS_UPDATE_FAILED",
                "desc": "Fail to update LCS"
            },
            0x45000022: {
                "status": "CYAPP_LCS_READ_FAILED",
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
                "desc": "Current device LCS is illegal to perform provisioning or re-provisioning"
            },
            0x45000031: {
                "status": "CYAPP_CBOR_INVALID",
                "desc": "Object in CBOR has illegal value"
            },
            0x45000032: {
                "status": "CYAPP_RESPONSE_PACKET_FAILED",
                "desc": "Response packet creation failed"
            },
            0x45000033: {
                "status": "CYAPP_DEVICE_ID_CSR_FAILED",
                "desc": "DICE_DeviceID CSR"
            },
            0x45000034: {
                "status": "CYAPP_DEVICE_ID_KEYPAIR_FAILED",
                "desc": "Fail to retrieve DeviceID keypair"
            },
            0x45000035: {
                "status": "CYAPP_ALIAS_CERT_GEN_FAILED",
                "desc": "Alias certificate generation failed"
            },
            0x45000036: {
                "status": "CYAPP_DEVICE_ID_GENERATION_FAILED",
                "desc": "Fail to generate device identity"
            },
            0x45000037: {
                "status": "CYAPP_CDI_COMPUTE_FAILED",
                "desc": "Fail to compute CDI hash"
            },
            0x45000038: {
                "status": "CYAPP_HL0_COMPUTE_FAILED",
                "desc": "Fail to compute HL0 hash"
            },
            0x45000039: {
                "status": "CYAPP_DEVICE_ID_PROGRAM_FAILED",
                "desc": "Fail to program device identity data, not recoverable error"
            },
            0x4500003A: {
                "status": "CYAPP_PACKET_SIGN_VERIFY_FAILED",
                "desc": "Packet signature validation failed"
            },
            0x4500003B: {
                "status": "CYAPP_ASSET_VERIFY_FAILED",
                "desc": "RRAM asset validation failed"
            },
            0x4500003C: {
                "status": "CYAPP_NVM_WRITE_FAILED",
                "desc": "Fail to program object into NVM"
            },
            0x4500003D: {
                "status": "CYAPP_NVM_READ_FAILED",
                "desc": "Fail to read object from NVM"
            },
            0x4500003E: {
                "status": "CYAPP_HASH_CALCULATION_FAILED",
                "desc": "Fail to calculate hash"
            },
            0x4500003F: {
                "status": "CYAPP_PROVISIONING_LIMITS_FAILED",
                "desc": "Exceed provisioning limits"
            },
            0x45000040: {
                "status": "CYAPP_ALIAS_KEY_PAIR_GEN_FAILED",
                "desc": "Fail to generate Alias keypair"
            },
            0x45000041: {
                "status": "CYAPP_HASH_VALIDATION_FAILED",
                "desc": "Fail to validate hash"
            },
            0x45000042: {
                "status": "CYAPP_SE_RT_SERVICES_FAILED",
                "desc": "Call of SE RT Services API failed"
            },
            0x45000043: {
                "status": "CYAPP_RMA_TOKEN_INVALID",
                "desc": "RMA token validation failed"
            },
            0x45000044: {
                "status": "CYAPP_PUB_KEY_ACCESS_FAILED",
                "desc": "Public key access failed"
            },
            0x45000045: {
                "status": "CYAPP_RMA_TRIAL_COUNTER_PROCESS_FAILED",
                "desc": "Fail to process RMA trial counter"
            },
            0x45000046: {
                "status": "CYAPP_RMA_ASSET_INVALIDATION_FAILED",
                "desc": "Fail to invalidate RMA asset"
            },
            0x45000047: {
                "status": "CYAPP_REPROV_DEBUG_CM33_NOT_ALLOWED",
                "desc": "Re-provisioning of CM33 debug policy is protected"
            },
            0x45000048: {
                "status": "CYAPP_REPROV_DEBUG_CM55_NOT_ALLOWED",
                "desc": "Re-provisioning of CM55 debug policy is protected"
            },
            0x45000049: {
                "status": "CYAPP_REPROV_DEBUG_SYSTEM_NOT_ALLOWED",
                "desc": "Re-provisioning of system debug policy is protected"
            },
            0x4500004A: {
                "status": "CYAPP_REPROV_DEBUG_RMA_NOT_ALLOWED",
                "desc": "Re-provisioning of permission transition to RMA is protected"
            },
            0x4500004B: {
                "status": "CYAPP_REPROV_DEBUG_KEY_NOT_ALLOWED",
                "desc": "Re-provisioning of debug key is protected"
            },
            0x4500004C: {
                "status": "CYAPP_REPROV_CM33_L1_BOOT_POLICY_NOT_ALLOWED",
                "desc": "Re-provisioning of L1 BOOT policy is protected"
            },
            0x4500004D: {
                "status": "CYAPP_REPROV_USER_KEYS_NOT_ALLOWED",
                "desc": "Re-provisioning of OEM keys is protected"
            },
            0x4500004E: {
                "status": "CYAPP_REPROV_USER_CERTIFICATE_NOT_ALLOWED",
                "desc": "Re-provisioning of chain-of-trust certificates is protected"
            },
            0x4500004F: {
                "status": "CYAPP_REPROV_CM33_L1_BOOT_NOT_ALLOWED",
                "desc": "Re-provisioning of CM33 L1 BOOT image can not be updated in SECURE LCS"
            },
            0x45000050: {
                "status": "CYAPP_PROV_IFX_OEM_CERT_NOT_ALLOWED",
                "desc": "Injection of IFX_OEM_CERT is not allowed in SECURE LCS"
            },
            0x45000051: {
                "status": "CYAPP_REPROV_POLICY_INVALID",
                "desc": "Re-provisioning policy invalid"
            },
            0x45000052: {
                "status": "CYAPP_CMD_INVALID",
                "desc": "Invalid command code"
            },
            0x45000053: {
                "status": "CYAPP_OBJ_NUM_INVALID",
                "desc": "The number of data objects exceeds the maximum allowed value"
            },
            0x45000054: {
                "status": "CYAPP_KEY_IMPORT_FAILED",
                "desc": "Key import failed"
            },
            0x45000055: {
                "status": "CYAPP_TRANSITION_TO_RMA_NOT_ALLOWED",
                "desc": "Transition to RMA not allowed by policy"
            },
            0x45000056: {
                "status": "CYAPP_PACKET_SIGN_FAILED",
                "desc": "Packet sign failed"
            },
            0x45000057: {
                "status": "CYAPP_UDS_ACCESS_FAILED",
                "desc": "Access to UDS failed"
            },
            0x45000058: {
                "status": "CYAPP_SE_RT_SERVICES_INSUFFICIENT_STORAGE",
                "desc": "There is not enough persistent storage"
            },
            0x45000059: {
                "status": "CYAPP_RRAM_TEMP_COMP_FAILED",
                "desc": "RRAM IP temperature compensation failed"
            },
            0x4500005A: {
                "status": "CYAPP_MANUFACTURING_CERT_INVALID",
                "desc": "Fail to validate Manufacturing certificate"
            },
            0x4500005B: {
                "status": "CYAPP_IFX_DEVICE_CERT_INVALID",
                "desc": "Fail to validate IFX_DEVICE certificate"
            },
            0x4500005C: {
                "status": "CYAPP_RT_SERVICES_INVALID",
                "desc": "Fail to validate RT_SERVICES"
            },
            0x4500005D: {
                "status": "CYAPP_RT_SERVICES_BASE_INVALID",
                "desc": "Fail to validate RT_SERVICES_BASE"
            },
            0x4500005E: {
                "status": "CYAPP_RRAM_SE_BOOT_INVALID",
                "desc": "Fail to validate RRAM SE BOOT"
            },
            0x4500005F: {
                "status": "CYAPP_CM33_L1_BOOT_INVALID",
                "desc": "Fail to validate Extended BOOT"
            },
            0x45000060: {
                "status": "CYAPP_INTEGRITY_CERT_INVALID",
                "desc": "No description provided"
            }
        }
