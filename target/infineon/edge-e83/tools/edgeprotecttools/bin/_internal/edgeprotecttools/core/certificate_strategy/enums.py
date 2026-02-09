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
from enum import IntEnum


class DeviceIntegrity(IntEnum):
    """Device Integrity CBOR map key ID"""
    ENTR_EXAM_CMD = 0x13000000
    NONCE = 0x13010002
    REGIONS = 0x13010001


class DeviceResponse(IntEnum):
    """Device response CBOR map key ID"""
    DEV_RSP = 0x12000000
    APP_STATUS = 0x12010001
    ALIAS_PUB_KEY = 0x12010002
    DICE_DEV_ID_PUB_KEY = 0x12010003
    CURRENT_LCS = 0x12010004
    NONCE = 0x12010005
    DEV_ID_CERT = 0x12010006
    IFX_CHAIN_OF_TRUST = 0x12010007
    IFX_DEVICE_CERT = 0x12010008
    ALIAS_CERT = 0x12010009
    REGION_HASH = 0x1201000A
