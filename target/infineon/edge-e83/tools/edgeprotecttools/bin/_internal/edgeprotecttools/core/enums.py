"""
Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from collections import namedtuple

from cryptography.hazmat.primitives import serialization


class EntranceExamStatus(IntEnum):
    OK = 0
    FAIL = 1
    FLASH_NOT_EMPTY = 2


class RegionHashStatus(IntEnum):
    OK = 0
    FAIL = 1
    FLASH_NOT_EMPTY = 2


class ProvisioningStatus(IntEnum):
    OK = 0
    FAIL = 1
    TERMINATED = 2
    SKIPPED = 3
    STOP = 4


class ValidationStatus(IntEnum):
    OK = 0,
    ERROR = 1,
    WARNING = 2,
    TERMINATED = 3


class KeyType(Enum):
    """
    Available key types.
    """
    user, encryption, device_public, group_public = range(4)


class KeyAlgorithm:
    """
    Supported key algorithms.
    """
    ECDSA_P256 = 'ECDSA-P256'
    ECDSA_P384 = 'ECDSA-P384'
    ECDSA_P521 = 'ECDSA-P521'
    X25519 = 'X25519'
    RSA2048 = 'RSA2048'
    RSA3072 = 'RSA3072'
    RSA4096 = 'RSA4096'
    AES128 = 'AES128'
    AES256 = 'AES256'
    EC = ECDSA_P256
    RSA = RSA2048
    AES = AES128


KeyFormat = {
    'SUBJPUBKEYINFO': serialization.PublicFormat.SubjectPublicKeyInfo,
    'PKCS1': serialization.PublicFormat.PKCS1,
    'OPENSSL': serialization.PrivateFormat.TraditionalOpenSSL,
    'PKCS8': serialization.PrivateFormat.PKCS8
}

KeyEncoding = {
    'PEM': serialization.Encoding.PEM,
    'DER': serialization.Encoding.DER,
    'JWK': None,
    'C_ARRAY': serialization.Encoding.DER,
    'SECURE_BOOT': None,
    'X962': serialization.Encoding.X962
}


class ImageType(Enum):
    """
    Available image types.
    """
    BOOT = 'BOOT'
    UPGRADE = 'UPGRADE'
    BOOTLOADER = 'BOOTLOADER'


KeyPair = namedtuple('KeyPair', 'private public')


class Protocol:
    """
    Supported DFU protocols.
    """
    UART = 'uart'
    I2C = 'i2c'
    SPI = 'spi'
    CAN_FD = 'can_fd'
