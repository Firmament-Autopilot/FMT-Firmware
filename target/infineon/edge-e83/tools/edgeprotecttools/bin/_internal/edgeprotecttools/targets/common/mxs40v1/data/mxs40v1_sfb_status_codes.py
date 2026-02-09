"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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


class SfbStatusMXS40v1(StatusCodesBase):
    """Secure Flash Boot status codes for the MXS40v1 platform"""

    def status_codes(self):
        """Gets a dictionary containing Secure Flash Boot status codes
        for the MXS40v1 platform
        """
        return {
            0xA0000000: {
                "status": "CY_FB_SYSCALL_SUCCESS",
                "desc": "Syscall executed successfully"
            },
            0xF0000004: {
                "status": "CY_FB_INVALID_FLASH_ADDR",
                "desc": "Wrong or out of bound FLASH address"
            },
            0xF0000008: {
                "status": "CY_FB_SYSCALL_ADDR_PROTECTED",
                "desc": "Returned by all APIs when client doesn’t have "
                        "access to region it is using for passing arguments"
            },
            0xF000000B: {
                "status": "CY_FB_SYSCALL_INVALID_OPCODE",
                "desc": "The opcode is not a valid API opcode"
            },
            0xF700DEAD: {
                "status": "CY_FB_INVALID_STATE_DEAD",
                "desc": "Returned when device is in DEAD state"
            },
            0xF7000001: {
                "status": "CY_FB_ALREADY_PROVISIONED",
                "desc": "Device is already provisioned"
            },
            0xF7000002: {
                "status": "CY_FB_INVALID_FLASH_OPERATION",
                "desc": "Returned when write to flash operation fails"
            },
            0xF7000003: {
                "status": "CY_FB_INVALID_CY_JWT_SIGNATURE",
                "desc": "Returned when signature verification of the JWT "
                        "packet, which should be signed by Cypress Private Key "
                        "failed (cy_auth or image_cert)"
            },
            0xF7000004: {
                "status": "CY_FB_INVALID_OEM_JWT_SIGNATURE",
                "desc": "Returned when signature verification of the JWT "
                        "packet, which should be signed by OEM Private Key "
                        "failed (rot_auth or prov_req)"
            },
            0xF7000005: {
                "status": "CY_FB_INVALID_HSM_JWT_SIGNATURE",
                "desc": "Returned when signature verification of the JWT "
                        "packet, which should be signed by HSM Private Key "
                        "failed(prov_cmd)"
            },
            0xF7000006: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1",
                "desc": "Returned when cy_auth token in prov_cmd packet "
                        "doesn’t contain valid hsm_pub_key"
            },
            0xF7000206: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_2",
                "desc": "Returned when cy_auth token in prov_cmd packet "
                        "doesn’t contain valid cy_pub_key"
            },
            0xF7000306: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_3",
                "desc": "Returned when rot_auth token in prov_cmd packet "
                        "doesn’t contain valid oem_pub_key"
            },
            0xF7000406: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_4",
                "desc": "Returned when rot_auth token in prov_cmd packet "
                        "doesn’t contain valid hsm_pub_key"
            },
            0xF7000506: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_5",
                "desc": "Returned when body part of the prov_cmd packet "
                        "is absent"
            },
            0xF7000606: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_6",
                "desc": "Returned when base64_decode of the body part of "
                        "the prov_cmd packet failed"
            },
            0xF7000706: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_7",
                "desc": "Returned when JSON parser failed with the decoded "
                        "body part of the prov_cmd packet"
            },
            0xF7000806: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_8",
                "desc": "Returned when “cy_auth” token is absent in the "
                        "parsed body part of the prov_cmd packet"
            },
            0xF7000906: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_9",
                "desc": "Returned when body part of the cy_auth packet "
                        "is absent"
            },
            0xF7000A06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_A",
                "desc": "Returned when base64_decode of the body part of "
                        "the cy_auth packet failed"
            },
            0xF7000B06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_B",
                "desc": "Returned when JSON parser failed with the decoded "
                        "body part of the cy_auth packet"
            },
            0xF7000C06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_C",
                "desc": "Returned when “exp” token is absent in the parsed "
                        "body part of the cy_auth packet"
            },
            0xF7000D06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_D",
                "desc": "Returned when “image_cert” token is absent in "
                        "the parsed body part of the prov_cmd packet"
            },
            0xF7000E06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_E",
                "desc": "Returned when body part of the image_cert packet "
                        "is absent"
            },
            0xF7000F06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_F",
                "desc": "Returned when base64_decode of the body part of "
                        "the image_cert packet failed"
            },
            0xF7001006: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_10",
                "desc": "Returned when JSON parser failed with the decoded "
                        "body part of the image_cert packet"
            },
            0xF7001106: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_11",
                "desc": "Returned when “image_hash” token is absent in the "
                        "parsed body part of the image_cert packet"
            },
            0xF7001206: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_12",
                "desc": "Returned when “rot_auth” token is absent in the "
                        "parsed body part of the prov_cmd packet"
            },
            0xF7001306: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_13",
                "desc": "Returned when body part of the rot_auth packet "
                        "is absent"
            },
            0xF7001406: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_14",
                "desc": "Returned when base64_decode of the body part of "
                        "the rot_auth packet failed"
            },
            0xF7001506: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_15",
                "desc": "Returned when JSON parser failed with the decoded "
                        "body part of the rot_auth packet"
            },
            0xF7001606: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_16",
                "desc": "Returned when “iat” token is absent in the parsed "
                        "body part of the rot_auth packet"
            },
            0xF7001706: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_17",
                "desc": "Returned when “oem_pub_key” token is absent in the "
                        "parsed body part of the rot_auth packet"
            },
            0xF7001806: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_18",
                "desc": "Returned when “hsm_pub_key” token is absent in the "
                        "parsed body part of the rot_auth packet"
            },
            0xF7001906: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_19",
                "desc": "Returned when “prod_id” token is absent in the "
                        "parsed body part of the rot_auth packet"
            },
            0xF7001A06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1A",
                "desc": "Returned when “prov_req” token is absent in the "
                        "parsed body part of the prov_cmd packet"
            },
            0xF7001B06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1B",
                "desc": "Returned when body part of the prov_req packet "
                        "is absent"
            },
            0xF7001C06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1C",
                "desc": "Returned when base64_decode of the body part of "
                        "the prov_req packet failed"
            },
            0xF7001D06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1D",
                "desc": "Returned when JSON parser failed with the decoded "
                        "body part of the prov_req packet"
            },
            0xF7001E06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1E",
                "desc": "Returned when “prod_id” token is absent in the "
                        "parsed body part of the prov_req packet"
            },
            0xF7001F06: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_1F",
                "desc": "Returned when “boot_upgrade” token is absent in "
                        "the parsed body part of the prov_req packet"
            },
            0xF7002006: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_20",
                "desc": "Returned when JSON parser failed with Boot And "
                        "Upgrade template"
            },
            0xF7002106: {
                "status": "CY_FB_INVALID_JWT_STUCTURE_21",
                "desc": "Returned when JSON parser failed with boot_upgrade "
                        "paket"
            },
            0xF7000007: {
                "status": "CY_FB_INVALID_CYPRESS_KEY",
                "desc": "Returned when import of Cypress Public Key from "
                        "JSON to key storage failed or when validation of "
                        "this key in cy_auth packet failed"
            },
            0xF7000008: {
                "status": "CY_FB_INVALID_JSON_PARSE",
                "desc": "Failed while parsing JSON"
            },
            0xF7000009: {
                "status": "CY_FB_INVALID_DEV_KEY_GEN",
                "desc": "Returned when Device Key generation failed"
            },
            0xF700000A: {
                "status": "CY_FB_INVALID_JWK_GEN",
                "desc": "Returned when JWT response packet generation failed"
            },
            0xF700000B: {
                "status": "CY_FB_INVALID_SEC_HASH_CALC",
                "desc": "Returned when Secure Hash calculation failed"
            },
            0xF700000C: {
                "status": "CY_FB_INVALID_HSM_KEY",
                "desc": "Returned when compare of HSM public key in cy_auth "
                        "and rot_auth packets failed"
            },
            0xF700000D: {
                "status": "CY_FB_INVALID_OEM_KEY",
                "desc": "Invalid OEM key"
            },
            0xF700000E: {
                "status": "CY_FB_INVALID_PROD_ID",
                "desc": "Returned when validation of prod_id in prov_req "
                        "packet failed"
            },
            0xF700000F: {
                "status": "CY_FB_INVALID_EFUSE_BLOW",
                "desc": "Returned when Efuse blow failed"
            },
            0xF7000010: {
                "status": "CY_FB_INVALID_PC_CHANGE",
                "desc": "Returned when Protection Context change of the "
                        "Crypto failed"
            },
            0xF7000011: {
                "status": "CY_FB_INVALID_JWT_POLICY",
                "desc": "Returned when validation of provision policy by "
                        "schema failed"
            },
            0xF7000012: {
                "status": "CY_FB_PD_PERM_NOT_ALLOWED",
                "desc": "Returned by TransitionToRMA or SyscallDPControl when "
                        "requested action (enable DP or RMA) is not permitted "
                        "by the provisioned policy"
            },
            0xF7000013: {
                "status": "CY_FB_INVALID_CRYPTO_OPER",
                "desc": "Returned when cryptographic operation failed"
            },
            0xF7000014: {
                "status": "CY_FB_INVALID_JWT_ID_TOO_LONG",
                "desc": "Returned when “prod_id” string is too long. "
                        "Maximum allowed length is 64 bytes"
            },
            0xF7000015: {
                "status": "CY_FB_INVALID_IMG_HASH",
                "desc": "Returned when calculated secure image hash doesn’t "
                        "match with a hash received in image_cert packet"
            },
            0xF7000016: {
                "status": "CY_FB_INVALID_JWT_TIME",
                "desc": "Returned when “exp” time of cy_auth is not less than "
                        "“iat” of the rot_auth packet"
            },
            0xF70000FF: {
                "status": "CY_FB_INVALID_MEM_ALLOC",
                "desc": "Returned when memory allocation failed"
            },
            0xF7000023: {
                "status": "CY_FB_INVALID_REPROV_CERT",
                "desc": "Invalid re-provisioning certificate"
            },
            0xF7000017: {
                "status": "CY_FB_INVALID_UDS_KEY_GEN",
                "desc": "Error during UDS key generation"
            },
            0xF7000018: {
                "status": "CY_FB_INVALID_GRP_KEY_IMPORT",
                "desc": "Group Private Key validation failed"
            },
            0xF7000019: {
                "status": "CY_FB_INVALID_KEY_ENCRYPTION",
                "desc": "Device Private Key encryption/storage failed"
            },
            0xF700001A: {
                "status": "CY_FB_IDENTITY_CREATED",
                "desc": "Device identity has been already created"
            },
            0xF700001B: {
                "status": "CY_FB_INVALID_CHAIN_LENGTH",
                "desc": "The length of chai_of_trust is greater than "
                        "supported (5k)"
            },
            0xF700001C: {
                "status": "CY_FB_INVALID_POLICY_LENGTH",
                "desc": "Policy length is greater than supported (10k)"
            },
            0xF700001D: {
                "status": "CY_FB_INVALID_IMG_CERT_LENGTH",
                "desc": "Image certificate length is greater than "
                        "supported (1k)"
            },
            0xF700001E: {
                "status": "CY_FB_INVALID_IMG_JWT_SIGNATURE",
                "desc": "Invalid image certificate signature"
            },
            0xF700001F: {
                "status": "CY_FB_INVALID_IMG_JWT_STRUCTURE",
                "desc": "Invalid image certificate structure"
            },
            0xF7000020: {
                "status": "CY_FB_INVALID_DEV_ID",
                "desc": "Invalid device ID"
            },
            0xF7000021: {
                "status": "CY_FB_INVALID_DIE_ID",
                "desc": "Invalid die ID"
            },
            0xF7000022: {
                "status": "CY_FB_INVALID_REPROV_POLICY",
                "desc": "Returned when validation of re-provision policy "
                        "by schema failed"
            },
            0xF7000024: {
                "status": "CY_FB_SYSCALL_INVALID_ARGUMENT",
                "desc": "Returned when invalid arguments are passed to the API"
            },
            0xF0000025: {
                "status": "CY_FB_SYSCALL_KEY_PROTECTED",
                "desc": "Syscall key protected"
            },
            0xF7000026: {
                "status": "CY_FB_ADDRESS_OUT_OF_RANGE",
                "desc": "The address defined by BNU reprogram policy is "
                        "out of range"
            },
        }
