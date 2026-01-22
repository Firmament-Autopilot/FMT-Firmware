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
from enum import IntEnum


class ProtectionState(IntEnum):
    """ Device protection states """
    unknown = 0
    virgin = 1
    normal = 2
    secure = 3
    dead = 4


class KeyId(IntEnum):
    HSM = 4
    OEM = 5
    DEVICE = 1
    GROUP = 12
