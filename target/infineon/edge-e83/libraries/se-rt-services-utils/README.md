# SE RT Services Utilities Library

## Overview
The SE RT Services Utilities Library is a set of utility code for the PSOC Edge E84 device to provide
an interface to SE RT Services SysCalls including PSA cryptographic functions, rollback management and
generic syscall functions.

## Features

### PSA Cryptographic functions
Wrapper functions to call PSA Crypto API v1.1 are implemented in SE RT Services.
All cryptographic functions are implemented according to the MbedTLS library version 3.6.0 interface.
This version corresponds to the version which used in SE RT Services.
Refer to the PSA Crypto API Reference Guide for the specific PSA Crypto functions:
- https://armmbed.github.io/mbed-crypto/html/index.html
- https://github.com/Mbed-TLS/mbedtls/tree/v3.2.1#psa-cryptography-api

#### Supported algorithms
SE RT Services Utilities Library follows all Mbed TLS PSA definitions and functions but
SE RT Services has limited support of key types and algorithms:

| Operation      | Algorithm                 | Key type         |
|:---------------|:--------------------------|:-----------------|
| Hash           | SHA-256                   |                  |
| Symmetric      | AES-ECB, AES-CBC, AES-CTR | AES-128, AES-256 |
| ^              | AEAD AES-CCM              | AES-128          |
| MAC            | AES-CMAC                  | AES-128, AES-256 |
| Asymmetric     | ECDSA sign / verify       | SECP-256R1       |
| ^              | ECDSA verify              | SECP-384R1       |
| ^              | RSA verify                | Up to 4096 bits  |
| Key derivation | CMAC-KDF                  | AES-128, AES-256 |
| Key agreement  | ECDH                      | SECP-256R1       |

### Generic Syscall functions
Wrapper functions to call several syscalls which are implemented in SE RT Services:
- \ref platform_power
- \ref platform_rollbacks
- \ref platform_attestation
- \ref platform_mpc

### Adding the library
There are two ways to add library to our project:
- add a dependency file (MTB format) into the 'deps' folder;
- use the Library Manager. It is available under Libraries section > Middleware > se-rt-services-utils.

#### Code snippet: Calculate the hash from the input data
```c
#include "ifx_se_psacrypto.h"
#include "ifx_se_platform.h"

int main(void)
{
        /* All data arrays should be 4-byte aligned for a better performance */

        /* Input data */
    	CY_ALIGN(4) const uint8_t text[10] = "1234";

    	/* Calculated SHA-256 hash */
        CY_ALIGN(4) uint8_t hash[IFX_SE_HASH_LENGTH(IFX_SE_ALG_SHA_256)] = {0};
    	size_t hash_lenght;
    	ifx_se_hash_operation_t psaOp = IFX_SE_HASH_OPERATION_INIT;
    	ifx_se_status_t status;

        __enable_irq();

        /* Hash the message by SHA256 */
        status = ifx_se_hash_setup (&psaOp, ifx_se_fih_uint_encode(IFX_SE_ALG_SHA_256), IFX_SE_NULL_CTX);

    	/* ... check for errors... */
        /* Use CY_REMAP_ADDRESS_CBUS_TO_SAHB macro to remap address if the input data are located in external flash */
        status = ifx_se_hash_update (&psaOp,
    								 ifx_se_fih_ptr_encode(CY_REMAP_ADDRESS_CBUS_TO_SAHB(text)),
    								 ifx_se_fih_uint_encode(sizeof(text)),
    								 IFX_SE_NULL_CTX);

        /* ... check for errors... */
        status = ifx_se_hash_finish (&psaOp,
    								 ifx_se_fih_ptr_encode(hash),
    								 ifx_se_fih_uint_encode(sizeof(hash)),
    								 ifx_se_fih_ptr_encode(&hash_lenght),
    								 IFX_SE_NULL_CTX);

        /* ... check for errors... */

    for (;;)
    {
    }
}
```

#### Code snippet: Verify signature based on NIST test vector
```c
    {
        /* SigVer.rsp [P-384,SHA-256] csrc.nist.gov/CSRC/media/Projects/Cryptographic-Algorithm-Validation-Program/documents/dss/186-4ecdsatestvectors.zip */
        /* Input message from the NIST test vector */
        CY_ALIGN(4) uint8_t message[] =
        {
            0x86,0x2c,0xf1,0x4c,0x65,0xff,0x85,0xf4,0xfd,0xd8,0xa3,0x93,0x02,0x05,0x63,0x55,
            0xc8,0x9c,0x6e,0xa1,0x78,0x9c,0x05,0x62,0x62,0xb0,0x77,0xda,0xb3,0x3a,0xbb,0xfd,
            0xa0,0x07,0x0f,0xce,0x18,0x8c,0x63,0x30,0xde,0x84,0xdf,0xc5,0x12,0x74,0x4e,0x9f,
            0xa0,0xf7,0xb0,0x3c,0xe0,0xc1,0x48,0x58,0xdb,0x19,0x52,0x75,0x0d,0x7b,0xbe,0x6b,
            0xd9,0xc8,0x72,0x6c,0x0e,0xae,0x61,0xe6,0xcf,0x28,0x77,0xc6,0x55,0xb1,0xf0,0xe0,
            0xce,0x82,0x54,0x30,0xa9,0x79,0x6e,0x74,0x20,0xe5,0xc1,0x74,0xea,0xb7,0xa5,0x04,
            0x59,0xe2,0x91,0x51,0x0b,0xc5,0x15,0x14,0x17,0x38,0x90,0x0d,0x39,0x02,0x17,0xc5,
            0xa5,0x22,0xe4,0xbd,0xe5,0x47,0xe5,0x72,0x87,0xd8,0x13,0x9d,0xc9,0x16,0x50,0x4e
        };
        /* Signature from the NIST test vector */
        CY_ALIGN(4) uint8_t signature[] =
        {
            0x79,0x80,0x65,0xf1,0xd1,0xcb,0xd3,0xa1,0x89,0x77,0x94,0xf4,0xa0,0x25,0xed,0x47,
            0x56,0x5d,0xf7,0x73,0x84,0x3f,0x4f,0xa7,0x4c,0x85,0xfe,0x4d,0x30,0xe3,0xa3,0x94,
            0x78,0x3e,0xc5,0x72,0x3b,0x53,0x0f,0xc5,0xf5,0x79,0x06,0xf9,0x46,0xce,0x15,0xe8,
            0xb5,0x71,0x66,0x04,0x4c,0x57,0xc7,0xd9,0x58,0x20,0x66,0x80,0x5b,0x58,0x85,0xab,
            0xc0,0x6e,0x0b,0xfc,0x02,0x43,0x38,0x50,0xc2,0xb7,0x49,0x73,0x20,0x5c,0xa3,0x57,
            0xa2,0xda,0x94,0xa6,0x51,0x72,0x08,0x6f,0x5a,0x15,0x80,0xba,0xa6,0x97,0x40,0x0b
        };
        /* The public key from the NIST test vector is embedded in to SE_RT_SERVICES
           Qx = 86ac12dd0a7fe5b81fdae86b12435d316ef9392a3f50b307ab65d9c6079dd0d2d819dc09e22861459c2ed99fbab66fae
           Qy = ac8444077aaed6d6ccacbe67a4caacee0b5a094a3575ca12ea4b4774c030fe1c870c9249023f5dc4d9ad6e333668cc38
           S = b57166044c57c7d9582066805b5885abc06e0bfc02433850c2b74973205ca357a2da94a65172086f5a1580baa697400b
		*/
        ifx_se_key_id_fih_t oem_custom_key = IFX_SE_KEY_ID_FIH_INIT_VALUE(0, IFX_SE_KEY_ID_BUILTIN_TEST_ECC384);

        status = ifx_se_verify_message(oem_custom_key,
                                       ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
                                       ifx_se_fih_ptr_encode(message),
                                       ifx_se_fih_uint_encode(sizeof(message)),
                                       ifx_se_fih_ptr_encode(signature),
                                       ifx_se_fih_uint_encode(sizeof(signature)),
                                       IFX_SE_NULL_CTX);
        /* ... check for errors... */
    }
 ```

#### Code snippet: Generate random AES key and use it for data encryption and decryption
```c
    {
        #define AES_KEY_SIZE        (16)
        ifx_se_key_attributes_t aesAttributes = IFX_SE_KEY_ATTRIBUTES_INIT;
        ifx_se_key_id_fih_t aesKeyId;

        /* Set AES key attributes */
        ifx_se_set_key_usage_flags(&aesAttributes, IFX_SE_KEY_USAGE_DECRYPT | IFX_SE_KEY_USAGE_ENCRYPT);
        ifx_se_set_key_algorithm(&aesAttributes, IFX_SE_ALG_CBC_NO_PADDING);
        ifx_se_set_key_type(&aesAttributes, IFX_SE_KEY_TYPE_AES);
        ifx_se_set_key_bits(&aesAttributes, IFX_SE_BYTES_TO_BITS(AES_KEY_SIZE));
        ifx_se_set_key_lifetime(&aesAttributes, IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                                IFX_SE_KEY_PERSISTENCE_VOLATILE, IFX_SE_KEY_LOCATION_SE));
        /* Generate AES key */
        status = ifx_se_generate_key(&aesAttributes,
                                     ifx_se_fih_ptr_encode(&aesKeyId),
                                     IFX_SE_NULL_CTX);
        /* ... check for errors after each API call ... */
    {
        #define DATA_LEN	          (16)
        /* Input data */
    	CY_ALIGN(4) const uint8_t inData[DATA_LEN] = "1234567890";
        /* Encrypted data buffer contains Initialization vector followed by the cipher text */
        uint8_t iv_and_encryptedData[IFX_SE_CIPHER_ENCRYPT_OUTPUT_SIZE(IFX_SE_KEY_TYPE_AES, IFX_SE_ALG_CBC_NO_PADDING, DATA_LEN)] = {0};

        /* Decrypted data */
    	uint8_t decryptedData[IFX_SE_CIPHER_DECRYPT_OUTPUT_SIZE(IFX_SE_KEY_TYPE_AES, IFX_SE_ALG_CBC_NO_PADDING, DATA_LEN)] = {0};
    	size_t outSize = 0;

        /* Generate random IV */
        status = ifx_se_generate_random(ifx_se_fih_ptr_encode(iv_and_encryptedData),
        		                        ifx_se_fih_uint_encode(IFX_SE_CIPHER_IV_MAX_SIZE),
										IFX_SE_NULL_CTX);

        /* Encrypt Data */
        status = ifx_se_cipher_encrypt(aesKeyId,
				                       ifx_se_fih_uint_encode(IFX_SE_ALG_CBC_NO_PADDING),
									   ifx_se_fih_ptr_encode(iv_and_encryptedData),
									   ifx_se_fih_uint_encode(IFX_SE_CIPHER_IV_MAX_SIZE),
	                                   ifx_se_fih_ptr_encode(inData),
									   ifx_se_fih_uint_encode(sizeof(inData)),
	                                   ifx_se_fih_ptr_encode(iv_and_encryptedData + IFX_SE_CIPHER_IV_MAX_SIZE),
									   ifx_se_fih_uint_encode(sizeof(iv_and_encryptedData) - IFX_SE_CIPHER_IV_MAX_SIZE),
									   ifx_se_fih_ptr_encode(&outSize),
									   IFX_SE_NULL_CTX);

        /* Decrypt Data */
        status = ifx_se_cipher_decrypt(aesKeyId,
				                       ifx_se_fih_uint_encode(IFX_SE_ALG_CBC_NO_PADDING),
	                                   ifx_se_fih_ptr_encode(iv_and_encryptedData),
									   ifx_se_fih_uint_encode(sizeof(iv_and_encryptedData)),
	                                   ifx_se_fih_ptr_encode(decryptedData),
									   ifx_se_fih_uint_encode(sizeof(decryptedData)),
									   ifx_se_fih_ptr_encode(&outSize),
									   IFX_SE_NULL_CTX);


        /* Destroy old AES key */
        status = ifx_se_destroy_key(aesKeyId, IFX_SE_NULL_CTX);
    }}
```

#### Code snippet: Generate random ECC P256 key and use it for hash sign and verify operations
```c
    {
        #define ECP_CURVE_BITS                (256u)
    	ifx_se_key_id_fih_t eccKeyId;
    	ifx_se_key_attributes_t eccAttributes = IFX_SE_KEY_ATTRIBUTES_INIT;
    	/* Pre-calculated SHA-256 hash */
        CY_ALIGN(4) uint8_t hash[IFX_SE_HASH_LENGTH(IFX_SE_ALG_SHA_256)] = {0, 1, 2, 3, 4, 5};
        CY_ALIGN(4) uint8_t signature[IFX_SE_ECDSA_SIGNATURE_SIZE(ECP_CURVE_BITS)] = {0};
        uint32_t signature_length;

    	/* Set ECC key attributes */
        ifx_se_set_key_usage_flags(&eccAttributes, IFX_SE_KEY_USAGE_SIGN_HASH | IFX_SE_KEY_USAGE_VERIFY_HASH);
        ifx_se_set_key_algorithm(&eccAttributes, IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256));
        ifx_se_set_key_type(&eccAttributes, IFX_SE_KEY_TYPE_ECC_KEY_PAIR(IFX_SE_ECC_FAMILY_SECP_R1));
        ifx_se_set_key_bits(&eccAttributes, ECP_CURVE_BITS);
        ifx_se_set_key_lifetime(&eccAttributes, IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                                                IFX_SE_KEY_PERSISTENCE_VOLATILE, IFX_SE_KEY_LOCATION_SE));

        /* Generate ECC key */
        status = ifx_se_generate_key(&eccAttributes,
                                     ifx_se_fih_ptr_encode(&eccKeyId),
                                     IFX_SE_NULL_CTX);
        /* Sign existing hash */
        status = ifx_se_sign_hash(eccKeyId,
                                  ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
                                  ifx_se_fih_ptr_encode(hash),
                                  ifx_se_fih_uint_encode(sizeof(hash)),
                                  ifx_se_fih_ptr_encode(signature),
                                  ifx_se_fih_uint_encode(sizeof(signature)),
								  ifx_se_fih_ptr_encode(&signature_length),
                                  IFX_SE_NULL_CTX);
        /* Verify signature */
        status = ifx_se_verify_hash(eccKeyId,
								    ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
								    ifx_se_fih_ptr_encode(hash),
								    ifx_se_fih_uint_encode(sizeof(hash)),
								    ifx_se_fih_ptr_encode(signature),
								    ifx_se_fih_uint_encode(sizeof(signature)),
								    IFX_SE_NULL_CTX);
        /* ... check for errors ... */
    }
```

## Supported memory regions
SE RT Services can process data from different memory regions.

Memory regions that can have input data for processing:

| Region     | Address            | Size               |
|:-----------|:-------------------|:-------------------|
| SRAM0      | SRAM0_S_SAHB_START | SRAM0_SIZE         |
| SRAM1      | SRAM1_S_SAHB_START | SRAM1_SIZE         |
| SOCMEM_RAM | CY_SOCMEM_RAM_BASE | CY_SOCMEM_RAM_SIZE |
| XIP0       | CY_XIP_PORT0_BASE  | CY_XIP_PORT0_SIZE  |
| XIP1       | CY_XIP_PORT1_BASE  | CY_XIP_PORT1_SIZE  |
| NVM        | CY_RRAM_CBUS_BASE  | RRAM_SIZE          |

Memory regions that can be used for output data:

| Region     | Address            | Size               |
|:-----------|:-------------------|:-------------------|
| SRAM0      | SRAM0_S_SAHB_START | SRAM0_SIZE         |
| SRAM1      | SRAM1_S_SAHB_START | SRAM1_SIZE         |
| SOCMEM_RAM | CY_SOCMEM_RAM_BASE | CY_SOCMEM_RAM_SIZE |

## Key storage capacity

SE RT Services have special internal storage to store persistent keys
(with \ref IFX_SE_KEY_PERSISTENCE_DEFAULT in the lifetime key attribute).

Keys can be imported in two different phases according to key ID number range:
 - User keys with Key ID in range [\ref IFX_SE_KEY_ID_USER_MIN -
 \ref IFX_SE_KEY_ID_USER_MAX] on runtime using \ref ifx_se_import_key
 - Vendor keys with key ID in range [\ref IFX_SE_KEY_ID_VENDOR_MIN -
 \ref IFX_SE_KEY_ID_VENDOR_MAX] during provisioning procedure

User key storage allows to import and store up to 12 keys according to it size
and type:

| Data/Key type                                    | count |
|:-------------------------------------------------|------:|
| \ref IFX_SE_KEY_TYPE_AES (AES-128)               |    12 |
| \ref IFX_SE_KEY_TYPE_AES (AES-256)               |     9 |
| \ref IFX_SE_KEY_TYPE_DERIVE (AES-128)            |    12 |
| \ref IFX_SE_KEY_TYPE_DERIVE (AES-256)            |     9 |
| \ref IFX_SE_KEY_TYPE_ECC_KEY_PAIR (SECP-256R1)   |     9 |
| \ref IFX_SE_KEY_TYPE_ECC_PUBLIC_KEY (SECP-256R1) |    12 |
| \ref IFX_SE_KEY_TYPE_ECC_PUBLIC_KEY (SECP-384R1) |     9 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (1024 bits)  |     6 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (2048 bits)  |     3 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (3072 bits)  |     2 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (4096 bits)  |     2 |
| \ref IFX_SE_KEY_TYPE_RAW_DATA (1 - 65 bytes)     |    12 |

Maximal size of the single \ref IFX_SE_KEY_TYPE_RAW_DATA object is 564 bytes.

Vendor keys storage allows to provision up to 16 keys.

Persistent AES keys have usage limitation up to 100k times per key implemented
using internal rollback counters. These counters can be red by
\ref ifx_se_get_usage_limit_counter.
After using limit key should be destroyed by \ref ifx_se_destroy_key.

\note
SE RT Services have only 16 usage limit counters for ALL AES keys.
\note
E.g. if device provisioned with 8 AES Vendor keys, only 8 limit counters
left to use for imported AES User keys.
\note
AES crypto limits the usage of non-volatile keys to 100k blocks of operation. 
For side channel protection reasons user applications should limit the usage of 
volatile keys also to 100k, or use other protective measures.

## Performance
PSA Crypto API benchmark for the PSOC Edge E84 device with the SE core frequency
set to 100 Mhz:

| Algorithm       | Execution time       |
|:----------------|:---------------------|
| SHA-256         | 8   ms/100kB payload |
| AES-CBC-128     | 202 ms/10kB payload  |
| AES-CBC-256     | 277 ms/10kB payload  |
| AES-CTR-128     | 200 ms/10kB payload  |
| AES-CTR-256     | 275 ms/10kB payload  |
| ECDSA-secp256r1 | 220 ms/sign          |
| ECDSA-secp256r1 | 170 ms/verify        |
| ECDSA-secp384r1 | 340 ms/verify        |
| ECDSA-secp521r1 | 700 ms/verify        |

## More information
The following resources contain more information:
* [SE RT Services Utilities Library RELEASE.md](RELEASE.md)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [Infineon Technologies AG](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2023-2025.
