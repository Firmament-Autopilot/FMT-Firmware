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
from enum import IntEnum


class LifecycleStage(IntEnum):
    """Device lifecycle stages"""
    VIRGIN = 0xF9A3111A
    SORT = 0x9C7314BD
    PROVISIONED = 0x71D9C97E
    NORMAL = 0xF2D906C8
    NORMAL_NO_SECURE = 0xFD41E812
    NORMAL_PROVISIONED = 0x1F73DB0B
    SECURE = 0xF44B753E
    RMA_NORMAL = 0x0D1F6227
    RMA_NORMAL_PROVISIONED = 0xE0B5BFE4
    RMA_NORMAL_NO_SECURE = 0x02878CFD
    RMA_SECURE = 0x0B8D11D1


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


class DeviceIntegrity(IntEnum):
    """Device Integrity CBOR map key ID"""
    ENTR_EXAM_CMD = 0x13000000
    NONCE = 0x13010002
    REGIONS = 0x13010001


class CoseSign1Packet(IntEnum):
    """Key ID for COSE_Sign1 CBOR packet"""
    IFX_PROV_PACKET = 0x10000000
    OEM_PROV_PACKET = 0x11000000
    REPROVISIONING_ID = 0x11010001
    DEBUG_ID = 0x11010002
    USER_KEYS_ID = 0x11010003
    CM33_L1_BOOT_POLICY_ID = 0x11010004
    IFX_OEM_CERT = 0x11010007
    USER_CERTIFICATE_ID = 0x11010008
    COSE_PACKET_ID = 0x1F000000
    SYS_AP_ID = 0x21020001
    CM33_AP_ID = 0x21000001


class DebugSubSystem(IntEnum):
    """Debug policy items IDs"""
    oem_subsystem = 0x22
    ifx_subsystem = 0x23


class DebugInstance(IntEnum):
    """Debug policy items IDs"""
    cm33_0 = 0x01
    wifiss_epidiag = 0x02
    bless = 0x03
    wifiss_dap = 0x04


class DebugField(IntEnum):
    """Debug policy items IDs"""
    ap = 0x0001
    allowed = 0x0002
    dbgen = 0x0003
    niden = 0x0004
    spiden = 0x0005
    spniden = 0x0006
    secure = 0x0007


class DebugFieldId:
    """Debug policy field ID generator"""

    def __init__(self, subsystem, instance, field):
        self.debug_id = DebugSubSystem[subsystem].value
        self.instance_id = DebugInstance[instance].value
        self.field_id = DebugField[field].value

    @property
    def value(self):
        return (self.debug_id << 24) | (self.instance_id << 16) | self.field_id
