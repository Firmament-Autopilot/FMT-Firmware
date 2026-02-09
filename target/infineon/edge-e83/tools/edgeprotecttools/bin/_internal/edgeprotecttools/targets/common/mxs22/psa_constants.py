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


class PsaKeyTypes(IntEnum):
    """Identifies the type of key"""
    AES = 0x2400
    DERIVE = 0x1200
    RAW_DATA = 0x1001
    RSA_KEY_PAIR = 0x7001
    RSA_PUBLIC_KEY = 0x4001
    ECC_KEY_PAIR_BASE = 0x7100
    ECC_PUBLIC_KEY_BASE = 0x4100
    ECC_FAMILY_SECP_R1 = 0x12
    ECC_KEY_PAIR = ECC_KEY_PAIR_BASE | ECC_FAMILY_SECP_R1
    ECC_PUBLIC_KEY = ECC_PUBLIC_KEY_BASE | ECC_FAMILY_SECP_R1


class PsaKeyAlgorithms(IntEnum):
    """Algorithm identifiers.
    Used to:
      - specify a specific algorithm to use in a cryptographic operation
      - specify the policy for a key, identifying the permitted algorithm
        for use with the key
    """
    NONE = 0
    PSA_ALG_SHA_256 = 0x02000009
    PSA_ALG_ANY_HASH = 0x020000ff
    HASH_MASK = 0x000000ff
    RSA_PKCS1_BASE = 0x06000200
    RSA_PKCS1 = RSA_PKCS1_BASE | (PSA_ALG_SHA_256 & HASH_MASK)
    ECDSA_BASE = 0x06000600
    ECDSA_ANY = ECDSA_BASE
    ECDSA = ECDSA_BASE | (PSA_ALG_ANY_HASH & HASH_MASK)
    CTR = 0x04c01000
    CBF = 0x04C01100
    OFB = 0x04C01200
    CBC_NO_PADDING = 0x04404000
    ECB_NO_PADDING = 0x04404400
    ECDH = 0x09020000
    PSA_ALG_HKDF = 0x08000100
    HKDF_ALG_SHA_256 = PSA_ALG_HKDF | (PSA_ALG_SHA_256 & HASH_MASK)
    IFX_SE_ALG_KDF_AES_CMAC = 0x08000600


class PsaKeyUsage(IntEnum):
    """The key usage flags, encoded in a bitmask"""
    EXPORT = 0x00000001
    COPY = 0x00000002
    CACHE = 0x00000004
    ENCRYPT = 0x00000100
    DECRYPT = 0x00000200
    SIGN_MESSAGE = 0x00000400
    VERIFY_MESSAGE = 0x00000800
    SIGN_HASH = 0x00001000
    VERIFY_HASH = 0x00002000
    DERIVE = 0x00004000
    VERIFY_DERIVATION = 0x00008000


class PsaKeyLifetime(IntEnum):
    """The key lifetime determines how long the key will persist"""
    VOLATILE = 0x00000000
    PERSISTENT = 0x00000001
