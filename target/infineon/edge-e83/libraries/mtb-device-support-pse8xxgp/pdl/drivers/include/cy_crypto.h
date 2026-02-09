/***************************************************************************//**
* \file cy_crypto.h
* \version 2.150
*
* \brief
*  This file provides the public interface for the Crypto driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/**
* \addtogroup group_crypto
* \{
* \note IP Supported: CRYPTO
*
* The Crypto driver provides a public API to perform cryptographic and hash
* operations, as well as generate both true and pseudo random numbers.
*
* It uses a hardware IP block to accelerate operations.
*
* The functions and other declarations used in this driver are in cy_crypto.h,
* cy_crypto_core.h. You can also include cy_pdl.h
* to get access to all functions and declarations in the PDL.
*
* The Crypto driver supports these standards: DES, TDES, AES (128, 192, 256 bits), CMAC-AES, SHA,
* HMAC, PRNG, TRNG, CRC, RSA, ECP, and ECDSA.
*
* \section group_crypto_configuration_considerations Configuration Considerations
*
* User can enable/disable cryptographic functionality based on the project
* requirements. To do so, create a configuration header file to configure cryptographic
* functionalities and define a macro CY_CRYPTO_USER_CONFIG_FILE with configuration
* header file name and add to project environment. If CY_CRYPTO_USER_CONFIG_FILE macro
* is not defined in project environment, firmware will enable all available
* cryptographic functionalities.
*
* Firmware sets up a cryptographic operation by passing in the required data as
* parameters in the function calls.
*
* All Crypto functions require a context. A context is a data
* structure that the driver uses for its operations. Firmware declares a
* context (allocates memory) but does not write or read the values in that
* context. In effect, the context is a scratch pad you provide to the driver.
* The driver uses the context to store and manipulate data during cryptographic
* operations.
*
* Several methods require an additional context unique to the particular
* cryptographic technique.
* The Crypto driver header files declare all the required structures for both
* configuration and context.
*
* Some encryption techniques require additional initialization specific to the
* technique. If there is an Init function, you must call it before using any
* other function for that technique, and re-initialize after you use a different
* encryption technique.
*
* For example, use \ref Cy_Crypto_Core_Aes_Init to configure an AES encryption
* operation with the encryption key, and key length.
* Provide pointers to two context structures. You can then call the AES Run functions.
* If you use DES after that, you must re-initialize the AES encryption before using
* it again.
*
* \section group_crypto_definitions Definitions
*
* <table class="doxtable">
*   <tr>
*     <th>Term</th>
*     <th>Definition</th>
*   </tr>
*
*   <tr>
*     <td>Plaintext</td>
*     <td>An unencrypted message</td>
*   </tr>
*
*   <tr>
*     <td>Ciphertext</td>
*     <td>An encrypted message</td>
*   </tr>
*
*   <tr>
*     <td>Block Cipher</td>
*     <td>An encryption function for fixed-size blocks of data.
*     This function takes a fixed-size key and a block of plaintext data from
*     the message and encrypts it to generate ciphertext. Block ciphers are
*     reversible. The function performed on a block of encrypted data will
*     decrypt that data.</td>
*   </tr>
*
*   <tr>
*     <td>Block Cipher Mode</td>
*     <td>A mode of encrypting a message using block ciphers for messages of an
*     arbitrary length. The message is padded so that its length is an integer
*     multiple of the block size. ECB (Electronic Code Book), CBC (Cipher Block
*     Chaining), and CFB (Cipher Feedback) are all modes of using block ciphers
*     to create an encrypted message of an arbitrary length.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Data Encryption Standard (DES)</td>
*     <td>The [DES standard]
*     (https://csrc.nist.gov/csrc/media/publications/fips/46/3/archive/1999-10-25/documents/fips46-3.pdf)
*     specifies a symmetric-key algorithm for encryption of electronic data.
*     It uses a 56-bit key. The block size is 64-bits.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Triple DES (3DES or TDES)</td>
*     <td>The [TDES standard]
*     (https://csrc.nist.gov/csrc/media/publications/fips/46/3/archive/1999-10-25/documents/fips46-3.pdf)
*     specifies a symmetric-key block cipher that applies the Data Encryption
*     Standard (DES) cipher algorithm three times to each data block.
*     It uses three 56-bit keys. The block size is 64-bits.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Advanced Encryption Standard (AES)</td>
*     <td>The [AES standard] (https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf)
*     specifies the Rijndael algorithm, a symmetric block
*     cipher that can process 128-bit data blocks, using cipher keys with
*     128-, 192-, and 256-bit lengths. Rijndael was designed to handle
*     additional block sizes and key lengths. However, they are not adopted in
*     this standard. AES is also used for message authentication.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Secure Hash Algorithm (SHA)</td>
*     <td>A cryptographic hash function.
*     This function takes a message of an arbitrary length and reduces it to a
*     fixed-length residue or message digest after performing a series of
*     mathematically defined operations that practically guarantee that any
*     change in the message will change the hash value. It is used for message
*     authentication by transmitting a message with a hash value appended to it
*     and recalculating the message hash value using the same algorithm at the
*     recipient's end. If the hashes differ, then the message is corrupted.
*     For more information see [Secure Hash standard description]
*     (https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf).
*     </td>
*   </tr>
*
*   <tr>
*     <td>Message Authentication Code (MAC)</td>
*     <td>MACs are used to verify that a received message has not been altered.
*     This is done by first computing a MAC value at the sender's end and
*     appending it to the transmitted message. When the message is received,
*     the MAC is computed again and checked against the MAC value transmitted
*     with the message. If they do not match, the message has been altered.
*     Either a Hash algorithm (such as SHA) or a block cipher (such as AES) can
*     be used to produce the MAC value. Keyed MAC schemes use a Secret Key
*     along with the message, thus the Key value must be known to be able to
*     compute the MAC value.</td>
*   </tr>
*
*   <tr>
*     <td>Cipher-based Message Authentication Code (CMAC)</td>
*     <td>A block cipher-based message authentication code algorithm.
*     It computes the MAC value using the AES block cipher algorithm.</td>
*     For more information see [Recommendation for Block Cipher Modes of Operation]
*     (https://nvlpubs.nist.gov/nistpubs/specialpublications/nist.sp.800-38b.pdf).
*   </tr>
*
*   <tr>
*     <td>Hash Message Authentication Code (HMAC)</td>
*     <td>A specific type of message authentication code (MAC) that involves a
*     cryptographic hash function and a secret cryptographic key.
*     It computes the MAC value using a Hash algorithm.
*     For more information see [The Keyed-Hash Message Authentication Code standard]
*     (https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf)
*     </td>
*   </tr>
*
*   <tr>
*     <td>Pseudo Random Number Generator (PRNG)</td>
*     <td>A Linear Feedback Shift Registers-based algorithm for generating a
*     sequence of numbers starting from a non-zero seed.</td>
*   </tr>
*
*   <tr>
*     <td>True Random Number Generator (TRNG)</td>
*     <td>A block that generates a number that is statistically random and based
*     on some physical random variation. The number cannot be duplicated by
*     running the process again.</td>
*   </tr>
*
*   <tr>
*     <td>Symmetric Key Cryptography</td>
*     <td>Uses a common, known key to encrypt and decrypt messages (a shared
*     secret between sender and receiver). An efficient method used for
*     encrypting and decrypting messages after the authenticity of the other
*     party has been established. DES (now obsolete), 3DES, and AES (currently
*     used) are well-known symmetric cryptography methods.</td>
*   </tr>
*
*   <tr>
*     <td>Asymmetric Key Cryptography</td>
*     <td>Also referred to as Public Key encryption. To receive a message,
*     you publish a very large public key (up to 4096 bits currently). The
*     public key is described by the pair (n, e) where n is a product of
*     two randomly chosen primes p and q. The exponent e is a random integer
*     1 < e < Q where Q = (p-1) (q-1). The private key d is uniquely defined
*     by the integer 1 < d < Q so that ed congruent with 1 (mod Q ). To send
*     a message to the publisher of the public key, you encrypt the message
*     with the public key. This message can now be decrypted only with the
*     private key. The message is now sent over any channel to the recipient
*     who can decrypt it with the private (secret) key. The same process is
*     used to send messages to the sender of the original message. The
*     asymmetric cryptography relies on the mathematical impracticality
*     (usually related to the processing power available at any given time)
*     of factoring the keys.
*     </td>
*   </tr>
* </table>
*
* \section group_crypto_more_information More Information
*
* RSASSA-PKCS1-v1_5 described here, page 31:
* https://www.rfc-editor.org/rfc/pdfrfc/rfc8017.txt.pdf
*
* See the "Cryptographic Function Block" chapter of the Technical Reference Manual.
*
* \defgroup group_crypto_lld_api Direct Crypto Core Access
* \defgroup group_crypto_data_structures Common Data Structures
* \defgroup group_crypto_enums Common Enumerated Types
* \defgroup group_crypto_macros Common macro defines
*/

#if !defined (CY_CRYPTO_H)
#define CY_CRYPTO_H

#include "cy_device.h"

#if defined (CY_IP_MXCRYPTO)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

/** \cond INTERNAL */

cy_en_crypto_status_t Cy_Crypto_GetLibraryInfo(cy_en_crypto_lib_info_t *cryptoInfo);

/** \endcond */

/** \cond INTERNAL */
/*******************************************************************************
* Function Name: Cy_Crypto_Init
****************************************************************************//**
*
* This function initializes the Crypto context buffer and
* configures the Crypto driver. Must be called at first.
*
* To start working with Crypto methods after Crypto_Init(),
* call Crypto_Enable() to turn-on the Crypto Hardware.
*
* \param config
* The pointer to the Crypto configuration structure.
*
* \param context
* The pointer to the \ref cy_stc_crypto_context_t instance of structure
* that stores the Crypto driver common context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoInit
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Init(cy_stc_crypto_config_t const *config, cy_stc_crypto_context_t *context);

/*******************************************************************************
* Function Name: Cy_Crypto_DeInit
****************************************************************************//**
*
* This function de-initializes the Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_DeInit(void);

/*******************************************************************************
* Function Name: Cy_Crypto_Enable
****************************************************************************//**
*
* This function enables (turns on) the Crypto hardware.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Enable(void);

/*******************************************************************************
* Function Name: Cy_Crypto_Disable
****************************************************************************//**
*
* This function disables (turns off) the Crypto hardware.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Disable(void);

/*******************************************************************************
* Function Name: Cy_Crypto_Sync
****************************************************************************//**
*
* This function waits or just checks (depending on the parameter)
* for the Crypto operation to complete.
*
* \param isBlocking
* Set whether Crypto_Sync is blocking:
* True - is blocking.
* False - is not blocking.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sync(bool isBlocking);

/*******************************************************************************
* Function Name: Cy_Crypto_GetErrorStatus
****************************************************************************//**
*
* This function returns a cause of a Crypto hardware error.
* It is independent of the Crypto previous state.
*
* \param hwErrorCause
* \ref cy_stc_crypto_hw_error_t.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_GetErrorStatus(cy_stc_crypto_hw_error_t *hwErrorCause);

#if (CPUSS_CRYPTO_PR == 1) && defined(CY_CRYPTO_CFG_PRNG_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Prng_Init
****************************************************************************//**
*
* This function initializes parameters of the PRNG.
*
* Call to initialize this encryption technique before using any associated
* functions. You must initialize this technique again after using any other
* encryption technique.
* Invoking this function resets the pseudo random sequence.
*
* \param lfsr32InitState
* A non-zero seed value for the first LFSR. User selected.

* \param lfsr31InitState
* A non-zero seed value for the second LFSR. User selected.

* \param lfsr29InitState
* A non-zero seed value for the third LFSR. User selected.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_prng_t structure that stores
* the Crypto function context.
* __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoPrngUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Prng_Init(uint32_t lfsr32InitState,
                                          uint32_t lfsr31InitState,
                                          uint32_t lfsr29InitState,
                                          cy_stc_crypto_context_prng_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Prng_Generate
****************************************************************************//**
*
* This function generates 32-bit the Pseudo Random Number.
* It depends on \ref Cy_Crypto_Prng_Init that should be called before.
*
* \param max
* The maximum value of a generated random number.
*
* \param randomNum
* The pointer to a variable to store the generated pseudo random number.
* __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_prng_t structure that stores
* the Crypto function context.
* __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoPrngUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Prng_Generate(uint32_t max,
                                              uint32_t *randomNum,
                                              cy_stc_crypto_context_prng_t *cfContext);
#endif /* (CPUSS_CRYPTO_PR == 1) && defined(CY_CRYPTO_CFG_PRNG_C) */

#if (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_AES_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Init
****************************************************************************//**
*
* This function initializes the AES operation by setting key and key length.
*
* Call to initialize this encryption technique before using any associated
* functions. You must initialize this technique again after using any other
* encryption technique.
*
* \param key
* The pointer to the encryption/decryption key. __Must be 4-byte aligned.__
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t structure that stores all
* internal variables the Crypto driver requires. __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoAesEcbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Init(uint32_t *key,
                                         cy_en_crypto_aes_key_length_t keyLength,
                                         cy_stc_crypto_context_aes_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ecb_Run
****************************************************************************//**
*
* This function performs AES operation on one 16-byte block
* (see \ref CY_CRYPTO_AES_BLOCK_SIZE).
* The AES key must be set before by invoking Cy_Crypto_Aes_Init().
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
* \param srcBlock
* The pointer to a 16-byte source block. __Must be 4-byte aligned.__
*
* \param dstBlock
* The pointer to a 16-byte destination cipher block. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t instance of structure
* that stores all AES internal variables. __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoAesEcbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ecb_Run(cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t *dstBlock,
                                            uint32_t *srcBlock,
                                            cy_stc_crypto_context_aes_t *cfContext);

#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC)
/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cbc_Run
****************************************************************************//**
*
* This function performs AES operation on a plain text with Cipher Block Chaining (CBC).
* The key must be set before by invoking Cy_Crypto_Aes_Init().
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector. __Must be 4-byte aligned.__
*
* \param dst
* The pointer to a destination cipher text. __Must be 4-byte aligned.__
*
* \param src
* The pointer to a source plain text. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t structure that stores all
* internal variables the Crypto driver requires.  __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cbc_Run(cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t srcSize,
                                            uint32_t *ivPtr,
                                            uint32_t *dst,
                                            uint32_t *src,
                                            cy_stc_crypto_context_aes_t *cfContext);
#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC) */

#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CFB)
/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cfb_Run
****************************************************************************//**
*
* This function performs AES operation on a plain text with Cipher Feedback mode
* (CFB). The key must be set before by invoking Cy_Crypto_Aes_Init().
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector. __Must be 4-byte aligned.__
*
* \param dst
* The pointer to the destination cipher text. __Must be 4-byte aligned.__
*
* \param src
* The pointer to the source plain text. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t structure that stores all
* internal variables the Crypto driver requires. __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cfb_Run(cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t srcSize,
                                            uint32_t *ivPtr,
                                            uint32_t *dst,
                                            uint32_t *src,
                                            cy_stc_crypto_context_aes_t *cfContext);
#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CFB) */

#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CTR)
/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ctr_Run
****************************************************************************//**
*
* This function performs AES operation on a plain text with Cipher Block Counter
* mode (CTR).
* NOTE: preparation of the unique nonceCounter for each block is
* the user's responsibility. This function is dependent on
* the key being set before invoking \ref Cy_Crypto_Aes_Init().
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of a source plain text.
*
* \param srcOffset
* The size of an offset within the current block stream for resuming within the
* current cipher stream.
*
* \param nonceCounter
* The 128-bit nonce and counter. __Must be 4-byte aligned.__
*
* \param streamBlock
* The saved stream-block for resuming. Is over-written by the function.
* __Must be 4-byte aligned.__
*
* \param dst
* The pointer to the destination cipher text. __Must be 4-byte aligned.__
*
* \param src
* The pointer to the source plain text. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t structure that stores all
* internal variables the Crypto driver requires. __Must be 4-byte aligned.__
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ctr_Run(cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t srcSize,
                                            uint32_t *srcOffset,
                                            uint32_t nonceCounter[CY_CRYPTO_AES_BLOCK_SIZE / 8u],
                                            uint32_t streamBlock[CY_CRYPTO_AES_BLOCK_SIZE / 8u],
                                            uint32_t *dst,
                                            uint32_t *src,
                                            cy_stc_crypto_context_aes_t *cfContext);
#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CTR) */
#endif /* (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_AES_C) */

#if (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_CMAC_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cmac_Run
****************************************************************************//**
*
* This function performs the cipher-block chaining-message authentication-code.
*
* There is no Init function. Provide the required parameters and the pointer to
* the context structure when making this function call.
*
* \param src
* The pointer to the source plain text. __Must be 4-byte aligned.__
*
* \param srcSize
* The size of a source plain text.
*
* \param key
* The pointer to the encryption key. __Must be 4-byte aligned.__
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param cmacPtr
* The pointer to the calculated CMAC. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_aes_t structure that stores all
* internal variables the Crypto driver requires.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoCmacUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cmac_Run(uint32_t *src,
                                             uint32_t srcSize,
                                             uint32_t *key,
                                             cy_en_crypto_aes_key_length_t keyLength,
                                             uint32_t *cmacPtr,
                                             cy_stc_crypto_context_aes_t *cfContext);
#endif /* (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_CMAC_C) */

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Run
****************************************************************************//**
*
* This function performs the SHA Hash function.
* There is no Init function. Provide the required parameters and the pointer
* to the context structure when making this function call.
* It is independent of the previous Crypto state because it already contains
* preparation, calculation, and finalization steps.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param message
* The pointer to a message whose hash value is being computed.
* __Must be 4-byte aligned.__
*
* \param messageSize
* The size of a message.
*
* \param digest
* The pointer to the hash digest. The hash size depends on the selected SHA mode
* (from 20 to 64 bytes).
* __Must be 4-byte aligned.__
*
* \param cfContext
* the pointer to the \ref cy_stc_crypto_context_sha_t structure that stores all
* internal variables for Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoSha256Use
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Run(uint32_t *message,
                                        uint32_t  messageSize,
                                        uint32_t *digest,
                                        cy_en_crypto_sha_mode_t mode,
                                        cy_stc_crypto_context_sha_t *cfContext);
#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C) */

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HMAC_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Hmac_Run
****************************************************************************//**
*
* This function performs HMAC calculation.
* There is no Init function. Provide the required parameters and the pointer
* to the context structure when making this function call.
* It is independent of the previous Crypto state because it already contains
* preparation, calculation, and finalization steps.
*
* \param hmac
* The pointer to the calculated HMAC. __Must be 4-byte aligned.__
*
* \param message
* The pointer to a message whose hash value is being computed.
* __Must be 4-byte aligned.__
*
* \param messageSize
* The size of a message.
*
* \param key
* The pointer to the key. __Must be 4-byte aligned.__
*
* \param keyLength
* The length of the key.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param cfContext
* the pointer to the \ref cy_stc_crypto_context_sha_t structure that stores all
* internal variables for the Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoHmacUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Hmac_Run(uint32_t *hmac,
                                         uint32_t *message,
                                         uint32_t  messageSize,
                                         uint32_t *key,
                                         uint32_t keyLength,
                                         cy_en_crypto_sha_mode_t mode,
                                         cy_stc_crypto_context_sha_t *cfContext);
#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HMAC_C) */

#if (CPUSS_CRYPTO_STR == 1)
/*******************************************************************************
* Function Name: Cy_Crypto_Str_MemCpy
****************************************************************************//**
*
* This function copies a memory block. It operates on data in the user SRAM and
* doesn't use Crypto internal SRAM.
*
* \note Memory blocks should not overlap.
*
* There is no alignment restriction.
* This function is independent of the previous Crypto state.
*
* \param dst
* The pointer to the destination of MemCpy.
*
* \param src
* The pointer to the source of MemCpy.
*
* \param size
* The size in bytes of the copy operation. Maximum size is 65535 Bytes.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_str_t structure that stores all
* internal variables for the Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Str_MemCpy(void *dst,
                                           void const *src,
                                           uint16_t size,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Str_MemSet
****************************************************************************//**
*
* This function sets the memory block. It operates on data in the user SRAM and
* doesn't use Crypto internal SRAM.
*
* There is no alignment restriction.
* This function is independent from the previous Crypto state.
*
* \param dst
* The pointer to the destination of MemSet.
*
* \param data
* The value to be set.
*
* \param size
* The size in bytes of the set operation. Maximum size is 65535 Bytes.
*
* \param cfContext
* the pointer to the \ref cy_stc_crypto_context_str_t structure that stores all
* internal variables for the Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Str_MemSet(void *dst,
                                           uint8_t data,
                                           uint16_t size,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Str_MemCmp
****************************************************************************//**
*
* This function compares memory blocks. It operates on data in the user SRAM and
* doesn't use Crypto internal SRAM.
*
* There is no alignment restriction.
* This function is independent from the previous Crypto state.
*
* \param src0
* The pointer to the first source of MemCmp.(__must be 4-byte aligned__)
*
* \param src1
* The pointer to the second source of MemCmp.
*
* \param size
* The size in bytes of the compare operation. Maximum size is 65535 Bytes.
*
* \param resultPtr
* The pointer to the result of compare (__must be 4-byte aligned__):
*     - 0 - if Source 1 equal Source 2
*     - 1 - if Source 1 not equal Source 2
*
* \param cfContext
* the pointer to the \ref cy_stc_crypto_context_str_t structure that stores all
* internal variables for the Crypto driver. __must be 4-byte aligned__
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Str_MemCmp(void const *src0,
                                           void const *src1,
                                           uint16_t size,
                                           uint32_t *resultPtr,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Crypto_Str_MemXor
****************************************************************************//**
*
* This function calculates the XOR of two memory blocks. It operates on data in
* the user SRAM and doesn't use Crypto internal SRAM.
*
* \note Memory structures should not overlap.
*
* There is no alignment restriction.
* This function is independent from the previous Crypto state.
*
* \param src0
* The pointer to the first source of MemXor.

* \param src1
* The pointer to the second source of MemXor.

* \param dst
* The pointer to the destination of MemXor.
*
* \param size
* The size in bytes of the compare operation. Maximum size is 65535 Bytes.
*
* \param cfContext
* the pointer to the \ref cy_stc_crypto_context_str_t structure that stores all
* internal variables for the Crypto driver.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Str_MemXor(void const *src0,
                                           void const *src1,
                                           void *dst,
                                           uint16_t size,
                                           cy_stc_crypto_context_str_t *cfContext);
#endif /* #if (CPUSS_CRYPTO_STR == 1) */

#if (CPUSS_CRYPTO_CRC == 1) && defined(CY_CRYPTO_CFG_CRC_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Crc_Init
****************************************************************************//**
*
* This function performs CRC initialization.
*
* Call to initialize this encryption technique before using any associated
* functions. You must initialize this technique again after using any other
* encryption technique.
*
* Below is the table with known polynomials with different parameters and their
* calculated CRCs from the string <b>"123456789"</b>:
* | Name               | Width | Poly       | Init       | Data Rev | Data XOR | Rem Rev | Rem XOR    | Expected CRC |
* |:-------------------|:-----:|:----------:|:----------:|:--------:|:--------:|:-------:|:----------:|:------------:|
* | CRC-3 / ROHC       |     3 |        0x3 |        0x7 |        1 |        0 |       1 |        0x0 |          0x6 |
* | CRC-4 / ITU        |     4 |        0x3 |        0x0 |        1 |        0 |       1 |        0x0 |          0x7 |
* | CRC-5 / EPC        |     5 |        0x9 |        0x9 |        0 |        0 |       0 |        0x0 |          0x0 |
* | CRC-5 / ITU        |     5 |       0x15 |        0x0 |        1 |        0 |       1 |        0x0 |          0x7 |
* | CRC-5 / USB        |     5 |        0x5 |       0x1F |        1 |        0 |       1 |       0x1F |         0x19 |
* | CRC-6 / CDMA2000-A |     6 |       0x27 |       0x3F |        0 |        0 |       0 |        0x0 |          0xD |
* | CRC-6 / CDMA2000-B |     6 |        0x7 |       0x3F |        0 |        0 |       0 |        0x0 |         0x3B |
* | CRC-6 / DARC       |     6 |       0x19 |        0x0 |        1 |        0 |       1 |        0x0 |         0x26 |
* | CRC-6 / ITU        |     6 |        0x3 |        0x0 |        1 |        0 |       1 |        0x0 |          0x6 |
* | CRC-7              |     7 |        0x9 |        0x0 |        0 |        0 |       0 |        0x0 |         0x75 |
* | CRC-7 / ROHC       |     7 |       0x4F |       0x7F |        1 |        0 |       1 |        0x0 |         0x53 |
* | CRC-8              |     8 |        0x7 |        0x0 |        0 |        0 |       0 |        0x0 |         0xF4 |
* | CRC-8 / CDMA2000   |     8 |       0x9B |       0xFF |        0 |        0 |       0 |        0x0 |         0xDA |
* | CRC-8 / DARC       |     8 |       0x39 |        0x0 |        1 |        0 |       1 |        0x0 |         0x15 |
* | CRC-8 / DVB-S2     |     8 |       0xD5 |        0x0 |        0 |        0 |       0 |        0x0 |         0xBC |
* | CRC-8 / EBU        |     8 |       0x1D |       0xFF |        1 |        0 |       1 |        0x0 |         0x97 |
* | CRC-8 / I-CODE     |     8 |       0x1D |       0xFD |        0 |        0 |       0 |        0x0 |         0x7E |
* | CRC-8 / ITU        |     8 |        0x7 |        0x0 |        0 |        0 |       0 |       0x55 |         0xA1 |
* | CRC-8 / MAXIM      |     8 |       0x31 |        0x0 |        1 |        0 |       1 |        0x0 |         0xA1 |
* | CRC-8 / ROHC       |     8 |        0x7 |       0xFF |        1 |        0 |       1 |        0x0 |         0xD0 |
* | CRC-8 / WCDMA      |     8 |       0x9B |        0x0 |        1 |        0 |       1 |        0x0 |         0x25 |
* | CRC-10             |    10 |      0x233 |        0x0 |        0 |        0 |       0 |        0x0 |        0x199 |
* | CRC-10 / CDMA2000  |    10 |      0x3D9 |      0x3FF |        0 |        0 |       0 |        0x0 |        0x233 |
* | CRC-11             |    11 |      0x385 |       0x1A |        0 |        0 |       0 |        0x0 |        0x5A3 |
* | CRC-12 / 3GPP      |    12 |      0x80F |        0x0 |        0 |        0 |       1 |        0x0 |        0xDAF |
* | CRC-12 / CDMA2000  |    12 |      0xF13 |      0xFFF |        0 |        0 |       0 |        0x0 |        0xD4D |
* | CRC-12 / DECT      |    12 |      0x80F |        0x0 |        0 |        0 |       0 |        0x0 |        0xF5B |
* | CRC-13 / BBC       |    13 |     0x1CF5 |        0x0 |        0 |        0 |       0 |        0x0 |        0x4FA |
* | CRC-14 / DARC      |    14 |      0x805 |        0x0 |        1 |        0 |       1 |        0x0 |        0x82D |
* | CRC-15             |    15 |     0x4599 |        0x0 |        0 |        0 |       0 |        0x0 |        0x59E |
* | CRC-15 / MPT1327   |    15 |     0x6815 |        0x0 |        0 |        0 |       0 |        0x1 |       0x2566 |
* | CRC-24             |    24 |  0x0864CFB | 0x00B704CE |        0 |        0 |       0 |        0x0 |     0x21CF02 |
* | CRC-24 / FLEXRAY-A |    24 |  0x05D6DCB | 0x00FEDCBA |        0 |        0 |       0 |        0x0 |     0x7979BD |
* | CRC-24 / FLEXRAY-B |    24 |  0x05D6DCB | 0x00ABCDEF |        0 |        0 |       0 |        0x0 |     0x1F23B8 |
* | CRC-31 / PHILIPS   |    31 |  0x4C11DB7 | 0x7FFFFFFF |        0 |        0 |       0 | 0x7FFFFFFF |    0xCE9E46C |
* | CRC-16 / ARC       |    16 |     0x8005 |     0x0000 |        1 |        0 |       1 |     0x0000 |       0xBB3D |
* | CRC-16 / AUG-CCITT |    16 |     0x1021 |     0x1D0F |        0 |        0 |       0 |     0x0000 |       0xE5CC |
* | CRC-16 / BUYPASS   |    16 |     0x8005 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0xFEE8 |
* | CRC-16 / CCITT-0   |    16 |     0x1021 |     0xFFFF |        0 |        0 |       0 |     0x0000 |       0x29B1 |
* | CRC-16 / CDMA2000  |    16 |     0xC867 |     0xFFFF |        0 |        0 |       0 |     0x0000 |       0x4C06 |
* | CRC-16 / DDS-110   |    16 |     0x8005 |     0x800D |        0 |        0 |       0 |     0x0000 |       0x9ECF |
* | CRC-16 / DECT-R    |    16 |     0x0589 |     0x0000 |        0 |        0 |       0 |     0x0001 |       0x007E |
* | CRC-16 / DECT-X    |    16 |     0x0589 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x007F |
* | CRC-16 / DNP       |    16 |     0x3D65 |     0x0000 |        1 |        0 |       1 |     0xFFFF |       0xEA82 |
* | CRC-16 / EN-13757  |    16 |     0x3D65 |     0x0000 |        0 |        0 |       0 |     0xFFFF |       0xC2B7 |
* | CRC-16 / GENIBUS   |    16 |     0x1021 |     0xFFFF |        0 |        0 |       0 |     0xFFFF |       0xD64E |
* | CRC-16 / MAXIM     |    16 |     0x8005 |     0x0000 |        1 |        0 |       1 |     0xFFFF |       0x44C2 |
* | CRC-16 / MCRF4XX   |    16 |     0x1021 |     0xFFFF |        1 |        0 |       1 |     0x0000 |       0x6F91 |
* | CRC-16 / RIELLO    |    16 |     0x1021 |     0xB2AA |        1 |        0 |       1 |     0x0000 |       0x63D0 |
* | CRC-16 / T10-DIF   |    16 |     0x8BB7 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0xD0DB |
* | CRC-16 / TELEDISK  |    16 |     0xA097 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x0FB3 |
* | CRC-16 / TMS37157  |    16 |     0x1021 |     0x89EC |        1 |        0 |       1 |     0x0000 |       0x26B1 |
* | CRC-16 / USB       |    16 |     0x8005 |     0xFFFF |        1 |        0 |       1 |     0xFFFF |       0xB4C8 |
* | CRC-A              |    16 |     0x1021 |     0xC6C6 |        1 |        0 |       1 |     0x0000 |       0xBF05 |
* | CRC-16 / KERMIT    |    16 |     0x1021 |     0x0000 |        1 |        0 |       1 |     0x0000 |       0x2189 |
* | CRC-16 / MODBUS    |    16 |     0x8005 |     0xFFFF |        1 |        0 |       1 |     0x0000 |       0x4B37 |
* | CRC-16 / X-25      |    16 |     0x1021 |     0xFFFF |        1 |        0 |       1 |     0xFFFF |       0x906E |
* | CRC-16 / XMODEM    |    16 |     0x1021 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x31C3 |
* | CRC-32             |    32 | 0x04C11DB7 | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0xCBF43926 |
* | CRC-32 / BZIP2     |    32 | 0x04C11DB7 | 0xFFFFFFFF |        0 |        0 |       0 | 0xFFFFFFFF |   0xFC891918 |
* | CRC-32C            |    32 | 0x1EDC6F41 | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0xE3069283 |
* | CRC-32D            |    32 | 0xA833982B | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0x87315576 |
* | CRC-32 / MPEG-2    |    32 | 0x04C11DB7 | 0xFFFFFFFF |        0 |        0 |       0 | 0x00000000 |   0x0376E6E7 |
* | CRC-32 / POSIX     |    32 | 0x04C11DB7 | 0x00000000 |        0 |        0 |       0 | 0xFFFFFFFF |   0x765E7680 |
* | CRC-32Q            |    32 | 0x814141AB | 0x00000000 |        0 |        0 |       0 | 0x00000000 |   0x3010BF7F |
* | CRC-32 / JAMCRC    |    32 | 0x04C11DB7 | 0xFFFFFFFF |        1 |        0 |       1 | 0x00000000 |   0x340BC6D9 |
* | CRC-32 / XFER      |    32 | 0x000000AF | 0x00000000 |        0 |        0 |       0 | 0x00000000 |   0xBD0BE338 |
*
* \param polynomial
* The polynomial (specified using 32 bits) used in the computing CRC.
*
* \param dataReverse
* The order in which data bytes are processed. 0 - MSB first; 1- LSB first.
*
* \param dataXor
* The byte mask for XORing data
*
* \param remReverse
* A remainder reverse: 0 means the remainder is not reversed. 1 means reversed.
*
* \param remXor
* Specifies a mask with which the LFSR32 register is XORed to produce a remainder.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_crc_t structure that stores
* the Crypto driver context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \note
* The polynomial, initial seed and remainder XOR values are <b>always</b>
* provided as MSB aligned (so actual higher bit should be located in 31s bit of
* the parameter value).<br>
* Calculated CRC value is MSB aligned <b>only when dataReverse is zero</b>.
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoCrcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_Init(uint32_t polynomial,
                                         uint8_t  dataReverse,
                                         uint8_t  dataXor,
                                         uint8_t  remReverse,
                                         uint32_t remXor,
                                         cy_stc_crypto_context_crc_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_Run
****************************************************************************//**
*
* This function performs CRC calculation on a message.
* It depends on \ref Cy_Crypto_Crc_Init(), which should be called before.
*
* \param data
* The pointer to the message whose CRC is being computed.
*
* \param dataSize
* The size of a message in bytes.
*
* \param crc
* The pointer to a computed CRC value. __Must be 4-byte aligned.__
*
* \param lfsrInitState
* The initial state of the LFSR.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_crc_t structure that stores
* the Crypto driver context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \note
* The polynomial, initial seed and remainder XOR values are <b>always</b>
* provided as MSB aligned (so actual higher bit should be located in 31s bit of
* the parameter value).<br>
* Calculated CRC value is MSB aligned <b>only when dataReverse is zero</b>.
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoCrcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_Run(void     *data,
                                        uint16_t dataSize,
                                        uint32_t *crc,
                                        uint32_t  lfsrInitState,
                                        cy_stc_crypto_context_crc_t *cfContext);
#endif /* (CPUSS_CRYPTO_CRC == 1) && defined(CY_CRYPTO_CFG_CRC_C) */

#if (CPUSS_CRYPTO_TR == 1) && defined(CY_CRYPTO_CFG_TRNG_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Trng_Generate
****************************************************************************//**
*
* This function generates a 32-bit True Random Number.
*
* \param GAROPol
* The polynomial for the programmable Galois ring oscillator.
*
* \param FIROPol
* The polynomial for the programmable Fibonacci ring oscillator.
*
* \param max
* The maximum length of a random number, in the range [0, 32] bits.
*
* \param randomNum
* The pointer to a generated true random number. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_trng_t structure that stores
* the Crypto driver context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoTrngUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Trng_Generate(uint32_t  GAROPol,
                                              uint32_t  FIROPol,
                                              uint32_t  max,
                                              uint32_t *randomNum,
                                              cy_stc_crypto_context_trng_t *cfContext);
#endif /* (CPUSS_CRYPTO_TR == 1) && defined(CY_CRYPTO_CFG_TRNG_C) */

#if (CPUSS_CRYPTO_DES == 1) && defined(CY_CRYPTO_CFG_DES_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Des_Run
****************************************************************************//**
*
* This function performs DES operation on a Single Block. All addresses must be
* 4-Byte aligned.
* Ciphertext (dstBlock) may overlap with plaintext (srcBlock)
* There is no Init function. Provide the required parameters and the pointer
* to the context structure when making this function call.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param key
* The pointer to the encryption/decryption key. __Must be 4-byte aligned.__
*
* \param srcBlock
* The pointer to a source block. __Must be 4-byte aligned.__
*
* \param dstBlock
* The pointer to a destination cipher block. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the cy_stc_crypto_context_des_t structure that stores
* the Crypto driver context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Des_Run(cy_en_crypto_dir_mode_t dirMode,
                                        uint32_t *key,
                                        uint32_t *dstBlock,
                                        uint32_t *srcBlock,
                                        cy_stc_crypto_context_des_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Tdes_Run
****************************************************************************//**
*
* This function performs the TDES operation on a single block. All addresses
* __Must be 4-byte aligned.__
* Ciphertext (dstBlock) may overlap with plaintext (srcBlock).
* There is no Init function. Provide the required parameters and the pointer
* to the context structure when making this function call.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param key
* The pointer to the encryption/decryption key. __Must be 4-byte aligned.__
*
* \param srcBlock
* The pointer to a source block. __Must be 4-byte aligned.__
*
* \param dstBlock
* The pointer to a destination cipher block. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the cy_stc_crypto_context_des_t structure that stores
* the Crypto driver context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto/snippet/main.c snippet_myCryptoTdesUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Tdes_Run(cy_en_crypto_dir_mode_t dirMode,
                                         uint32_t *key,
                                         uint32_t *dstBlock,
                                         uint32_t *srcBlock,
                                         cy_stc_crypto_context_des_t *cfContext);
#endif /* (CPUSS_CRYPTO_DES == 1) && defined(CY_CRYPTO_CFG_DES_C) */

#if (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_RSA_C)
/*******************************************************************************
* Function Name: Cy_Crypto_GetMemBufAddress
****************************************************************************//**
*
* This function gets an operation memory buffer location.
*
* \param membufAddress
* The pointer of the operation memory buffer.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_str_t structure that stores
* the data context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_GetMemBufAddress(uint32_t **membufAddress,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_GetMemBufSize
****************************************************************************//**
*
* This function gets an operation memory buffer size.
*
* \param membufSize
* The size of the memory buffer (in bytes)
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_str_t structure that stores
* the data context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_GetMemBufSize(uint32_t *membufSize,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_SetMemBufAddress
****************************************************************************//**
*
* This function sets a new operation memory buffer.
*
* \param newMembufAddress
* The pointer to the new operation memory buffer.
* __Must be 4-byte aligned.__
*
* \param newMembufSize
* The size of the new memory buffer (in bytes)
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_str_t structure that stores
* the data context.
*
* \return
* \ref cy_en_crypto_status_t
*
* \note This function sets the default device specific values
*       when vuMemoryAddr parameter is NULL and vuMemorySize parameter is zero.
*
* \note New memory buffer should be allocated in a memory region that is not
*       protected by a protection scheme for use by Crypto hardware.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_SetMemBufAddress(uint32_t const *newMembufAddress,
                                           uint32_t newMembufSize,
                                           cy_stc_crypto_context_str_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Rsa_Proc
****************************************************************************//**
*
* This function calculates (m^e mod modulo) where m is Message (Signature), e -
* public exponent using a public key in the next representation, it contains:
* modulo,
* public exponent,
* coefficient for Barrett reduction,
* binary inverse of the modulo, and
* result of (2^moduloLength mod modulo).
*
* Not all fields in a key must be given. Modulo and public exponents are mandatory;
* Barrett coefficient, inverse modulo, and r-bar are optional.
* If they don't exist, their according pointers should be NULL. These coefficients
* could be calculated by \ref Cy_Crypto_Rsa_CalcCoefs.
* Their presence accelerates performance by five times.
* Approximate performance for 1024-bit modulo is 41.6 ms; for 2048-bit modulo is
* 142 ms when using a 25 MHz clock for Crypto HW. These numbers just for reference.
* They depend on many factors (compiler, optimization level, etc.).
*
* Returns the processed value and a success value.
*
* \note <b>Incoming message</b> and <b>result processed message</b> must be in
* little-endian order.<br>
* The <b>modulus</b> and <b>exponent</b> values in the \ref cy_stc_crypto_rsa_pub_key_t
* must also be in little-endian order.<br>
* Use \ref Cy_Crypto_InvertEndianness function to convert to or from
* little-endian order.
*
* \param pubKey
* The pointer to the \ref cy_stc_crypto_rsa_pub_key_t structure that stores
* public key.
*
* \param message
* The pointer to the message to be processed. __Must be 4-byte aligned.__
*
* \param messageSize
* The length of the message to be processed.
*
* \param processedMessage
* The pointer to processed message. __Must be 4-byte aligned.__
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_rsa_t structure that stores
* the RSA context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Rsa_Proc(cy_stc_crypto_rsa_pub_key_t const *pubKey,
                                         uint32_t const *message,
                                         uint32_t messageSize,
                                         uint32_t *processedMessage,
                                         cy_stc_crypto_context_rsa_t *cfContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Rsa_CalcCoefs
****************************************************************************//**
*
* This function calculates constant coefficients (which is dependent only on modulo
* and independent on message). With this pre-calculated coefficients calculations
* speed-up by five times.
*
* These coefficients are:
*                         coefficient for Barrett reduction,
*                         binary inverse of the modulo,
*                         result of (2^moduloLength mod modulo)
*
* Calculated coefficients will be placed by addresses provided in the
* pubKey structure for according coefficients.
* Function overwrites previous values.
* Approximate performance for 1024-bit modulo is 33.2 ms; for 2048-bit modulo is
* 113 ms when using a 25 MHz clock for Crypto HW. These numbers are just for
* reference.
* They depend on many factors (compiler, optimization level, etc.).
*
* \param pubKey
* The pointer to the \ref cy_stc_crypto_rsa_pub_key_t structure that stores a
* public key.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_rsa_t structure that stores
* the RSA context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Rsa_CalcCoefs(cy_stc_crypto_rsa_pub_key_t const *pubKey,
                                         cy_stc_crypto_context_rsa_t *cfContext);

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C) && defined(CY_CRYPTO_CFG_RSA_VERIFY_ENABLED)
/*******************************************************************************
* Function Name: Cy_Crypto_Rsa_Verify
****************************************************************************//**
*
* This function does an RSA verification with checks for content, paddings, and
* signature format.
* The SHA digest of the message and decrypted message should be calculated first.
* Supports only PKCS1-v1_5 format. Inside of this format supported padding
* using only SHA. Cases with MD2 and MD5 are not supported.
*
* PKCS1-v1_5 described here, page 31:
* http://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
*
* Returns the verification result \ref cy_en_crypto_rsa_ver_result_t.
*
* \param verResult
* The pointer to the verification result \ref cy_en_crypto_rsa_ver_result_t.
*
* \param digestType
* SHA mode used for hash calculation \ref cy_en_crypto_sha_mode_t.
*
* \param digest
* The pointer to the hash of the message whose signature is to be verified.
* __Must be 4-byte aligned.__
*
* \param decryptedSignature
* The pointer to the decrypted signature to be verified.
* __Must be 4-byte aligned.__
*
* \param decryptedSignatureLength
* The length of the decrypted signature to be verified (in bytes)
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_rsa_ver_t structure that stores
* the RSA context.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Rsa_Verify(cy_en_crypto_rsa_ver_result_t *verResult,
                                           cy_en_crypto_sha_mode_t digestType,
                                           uint32_t const *digest,
                                           uint32_t const *decryptedSignature,
                                           uint32_t decryptedSignatureLength,
                                           cy_stc_crypto_context_rsa_ver_t *cfContext);
#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C) && defined(CY_CRYPTO_CFG_RSA_VERIFY_ENABLED) */
#endif /* (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_RSA_C) */

#if (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_ECDSA_C)
#if defined(CY_CRYPTO_CFG_ECDSA_SIGN_C)
/*******************************************************************************
* Function Name: Cy_Crypto_ECDSA_SignHash
****************************************************************************//**
*
* Sign a message digest.
*
* \param hash
* The message digest to sign. Provided as is in data buffer.
*
* \param hashlen
* The length of the digest in bytes.
*
* \param sig
* [out] The destination for the signature, 'R' followed by 'S'.
*
* \param key
* Key used for signature generation. See \ref cy_stc_crypto_ecc_key.
*
* \param messageKey
* Message key.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_ecc_t structure that stores
* the ECC operation context.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_ECDSA_SignHash(const uint8_t *hash,
                                        uint32_t hashlen,
                                        uint8_t *sig,
                                        const cy_stc_crypto_ecc_key *key,
                                        const uint8_t *messageKey,
                                        cy_stc_crypto_context_ecc_t *cfContext);
#endif /* defined(CY_CRYPTO_CFG_ECDSA_SIGN_C) */

#if defined(CY_CRYPTO_CFG_ECDSA_VERIFY_C)
/*******************************************************************************
* Function Name: Cy_Crypto_ECDSA_VerifyHash
****************************************************************************//**
*
* Verify an ECC signature.
*
* \param sig
* The signature to verify, 'R' followed by 'S'.
*
* \param hash
* The message digest that was signed. Provided as is in data buffer.
*
* \param hashlen
* The length of the digest in bytes.
*
* \param stat
* Result of signature, 1==valid, 0==invalid.
*
* \param key
* The corresponding public ECC key. See \ref cy_stc_crypto_ecc_key.
*
* \param cfContext
* The pointer to the \ref cy_stc_crypto_context_ecc_t structure that stores
* the ECC operation context.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_ECDSA_VerifyHash(const uint8_t *sig,
                                        const uint8_t *hash,
                                        uint32_t hashlen,
                                        uint8_t *stat,
                                        const cy_stc_crypto_ecc_key *key,
                                        cy_stc_crypto_context_ecc_t *cfContext);

#endif /* defined(CY_CRYPTO_CFG_ECDSA_VERIFY_C) */
#endif /* (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_ECDSA_C) */
/** \endcond */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

#endif /* (CY_CRYPTO_H) */

/** \} group_crypto */


/* [] END OF FILE */
