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
from enum import Enum, IntEnum


class ControlWord(IntEnum):
    """OEM provisioning control word asset values"""
    PROG_SFLASH_ASSETS = 0x01
    PROG_IAK = 0x02
    PROG_HASH_EN = 0x04


class KeyRevocation(IntEnum):
    """Key revocation asset value"""
    IFX_ROT_KEY_0 = 0x01
    OEM_ROT_KEY_0 = 0x02
    PROT_FW_ROT_KEY_0 = 0x03


class SecBool(IntEnum):
    """OEM provisioning boolean asset values"""
    SEC_TRUE = 0xC39D5455
    SEC_FALSE = 0x151DD9BB


ListenWindow = Enum(
    value='Time',
    names=[
        ('100 ms', 0xC39D0001),
        ('20 ms', 0xC39D0002),
        ('2 ms', 0xC39D0003),
        ('0 ms', 0x151DD9BB),
        ('None', 0x151DD9BB),
    ]
)

BootCfgId = Enum(
    value='Behavior',
    names=[
        ('BOOT_SIMPLE_APP', 0x9ADC8D08),
        ('BOOT_ONE_SLOT', 0x4FBEEF63),
        ('BOOT_TWO_SLOTS', 0xECDB4B1F),
        ('BOOT_THREE_SLOTS', 0x39B92974),
        ('BOOT_IDLE', 0xA155E76E),
        ('None', 0),
    ]
)

BootAuthL1 = Enum(
    value='Authentication',
    names=[
        ('Fast', 0x0000_5A3C),
        ('Full', 0x0000_0F96),
        ('None', 0),
    ]
)

BootAuthL2 = Enum(
    value='Authentication',
    names=[
        ('Fast', 0x5A3C_0000),
        ('Full', 0x0F96_0000),
        ('None', 0),
    ]
)

ProtFwAuthMethod = Enum(
    value='Authentication',
    names=[
        ('SHA256', 0x0000_5A3C),
        ('Signature', 0x0000_0F96),
        ('None', 0),
    ]
)

ProtFwAuthNextApp = Enum(
    value='Authentication',
    names=[
        ('Skip', 0x5A3C_0000),
        ('AuthNext', 0x0F96_0000),
        ('None', 0),
    ]
)

MMIORestrictions = Enum(
    value='Restrictions',
    names=[
        ('No restrictions', 0),
        ('SRSS_GENERAL2 only', 1),
        ('No access', 2),
        ('None', 0),
    ]
)

DebugPins = Enum(
    value='Debug Pins',
    names=[
        ('0000', 0b0000),
        ('0011', 0b0011),
        ('0101', 0b0101),
        ('0110', 0b0110),
        ('1001', 0b1001),
        ('1010', 0b1010),
    ]
)

BootOdClk = Enum(
    value='Frequency',
    names=[
        ('48 MHz', 0x00),
        ('100 MHz', 0x55),
        ('180 MHz', 0xAA),
        ('None', 0),
    ]
)

ProvIcvControlWord = Enum(
    value='Control word',
    names=[
        ('EFUSE_DATA', 1),
        ('BOOTROW', 2),
        ('ALL', 3),
        ('None', 0)
    ]
)

FlashWounding = Enum(
    value='Size',
    names=[
        ('256K', 0),
        ('192K', 1),
        ('128K', 2),
        ('64K', 3),
        ('None', 0)
    ]
)

SramWounding = Enum(
    value='Size',
    names=[
        ('64K', 0),
        ('32K', 1),
        ('16K', 2),
        ('None', 0)
    ]
)

TcpwmWounding = Enum(
    value='Wounding',
    names=[
        ('All', 0),
        ('MOTIF disabled', 1),
        ('HRPWM disabled', 2),
        ('None', 0)
    ]
)

SerialInterface = Enum(
    value='Interface',
    names=[
        ('i2c', 1),
        ('uart', 2),
        ('spi', 3),
    ]
)
