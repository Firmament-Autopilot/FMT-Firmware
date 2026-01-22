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
from enum import IntEnum


class LifecycleStage(IntEnum):
    """ Device lifecycle stages """
    VIRGIN = 0
    SORT = 0x29
    PROVISIONED = 0xE9
    NORMAL = 0xC029
    NORMAL_NO_SECURE = 0xCC29
    NORMAL_PROVISIONED = 0xC0E9
    SECURE = 0xC3E9
    RMA_NORMAL = 0xF029
    RMA_NORMAL_NO_SECURE = 0xFC29
    RMA_SECURE = 0xF3E9
    CORRUPTED = 0xFFFF


class PolicyType:
    SECURE = 'secure'
    NO_SECURE = 'no_secure'
    REPROVISIONING = 'reprovisioning'
    REPROVISIONING_SECURE = 'reprovisioning_secure'
    REPROVISIONING_NO_SECURE = 'reprovisioning_no_secure'
    HCI_SECURE = 'hci_secure'


class CoseSign1Packet(IntEnum):
    """Key ID for COSE_Sign1 CBOR packet"""
    COSE_PACKET_ID = 0x1F000000

