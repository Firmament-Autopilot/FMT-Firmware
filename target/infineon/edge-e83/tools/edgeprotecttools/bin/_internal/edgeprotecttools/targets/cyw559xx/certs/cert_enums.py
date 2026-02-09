"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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

CertificateType = Enum(
    value='Certificate Type',
    names=[
        ('KEY_CERT', 0x53426b63),
        ('CONTENT_CERT', 0x53426363)
    ]
)

class AesCeId(IntEnum):
    """ID of the key that is used for encryption"""
    NONE = 0
    """No encryption for SW image"""
    KCE_ICV = 1
    """Use ICV key. Not supported"""
    KCE = 2
    """Use OEM key"""

LoadVerifyScheme = Enum(
    value='Load Verify Scheme',
    names=[
        ('RAM_LOAD_VERIFY', 0),
        ('FLASH_VERIFY', 1),
        ('RAM_VERIFY', 2),
        ('RAM_LOAD', 3)
    ]
)

CryptoType = Enum(
    value='Crypto Type',
    names=[
        ('PLAIN_IMAGE_HASH', 0),
        ('ENC_IMAGE_HASH', 1)
    ]
)
