"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from enum import Enum, IntEnum


ApPermission = Enum(
    value='Permissions',
    names=[
        ('Enable', 0),
        ('Disable', 1),
        ('Permanently Disable', 2),
        ('None', 0),
    ]
)

MpcPpcPermission = Enum(
    value='Permissions',
    names=[
        ('Enable', 1),
        ('Disable', 0),
        ('None', 0),
    ]
)

SRAMPart = Enum(
    value='Region',
    names=[
        ('Entire region', 0),
        ('7/8', 1),
        ('3/4', 2),
        ('1/2', 3),
        ('1/4', 4),
        ('1/8', 5),
        ('1/16', 6),
        ('Nothing', 7),
        ('None', 0),
    ]
)

MMIOPart = Enum(
    value='Region',
    names=[
        ('All', 0),
        ('Only IPC', 1),
        ('No access', 2),
        ('None', 0),
    ]
)

SMIFConfiguation = Enum(
    value='Configuration',
    names=[
        ('SFDP 1.5 and above', 1),
        ('QER_1', 2),
        ('QER_2', 3),
        ('QER_3', 4),
        ('QER_4', 5),
        ('QER_5', 6),
        ('QER_6', 7),
        ('HCI mode', 15),
        ('None', 0),
    ]
)

ChipSelect = Enum(
    value='Selector',
    names=[
        ('CS0', 0),
        ('CS1', 1),
        ('None', 0),
    ]
)

DataWidth = Enum(
    value='Width',
    names=[
        ('1X', 0),
        ('2X', 1),
        ('4X', 2),
        ('None', 0),
    ]
)

DataSelect = Enum(
    value='Selector',
    names=[
        ('SEL0', 0),
        ('SEL1', 1),
        ('None', 0),
    ]
)

AddressingMode = Enum(
    value='Mode',
    names=[
        ('3-byte', 0),
        ('4-byte', 1),
        ('None', 0),
    ]
)

ListenWindow = Enum(
    value='Time',
    names=[
        ('100 ms', 0),
        ('20 ms', 1),
        ('2 ms', 2),
        ('0 ms', 3),
        ('None', 0),
    ]
)

LifecycleStage = Enum(
    value='LCS',
    names=[
        ('VIRGIN', 0xD16B4C22),
        ('SORT', 0x720EE85E),
        ('PROVISIONED', 0xF8143E33),
        ('NORMAL', 0xB041109C),
        ('NORMAL_NO_SECURE', 0x10C65B65),
        ('NORMAL_PROVISIONED', 0xC646D68B),
        ('SECURE', 0x9CE5E053),
        ('RMA', 0x882A957F),
        ('CORRUPTED', 0x74378505),
        ('None', 0),
    ]
)


class ControlWord(IntEnum):
    """ Control word used for Secure LCS """
    PROGRAM_OEM_ASSETS_MSK = 0x01
    PROGRAM_OEM_KEY_0_HASH_MSK = 0x02

    # ENCRYPT_KEY uses the same memory slot as OEM_KEY_1_HASH
    PROGRAM_OEM_KEY_1_HASH_MSK = 0x04
    PROGRAM_ENCRYPT_KEY_MSK = 0x04

    REVOKE_ICV_PUBKEY_MSK = 0x08
    REVOKE_OEM_PUBKEY_MSK = 0x10
    RESET_DEVICE_MSK = 0x20

    PROGRAM_OEM_SECURE_KEY_MSK = 0x40


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
    INTEGRITY_EXAM_CMD = 0x13000000
    NONCE = 0x13010002
    REGIONS = 0x13010001
