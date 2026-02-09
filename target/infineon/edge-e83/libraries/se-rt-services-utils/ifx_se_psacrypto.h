/*******************************************************************************
*
* \file ifx_se_psacrypto.h
* \version 1.2.0
*
* \brief
*  This is the header file for the SE RT Services PSA crypto syscalls.
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/*******************************************************************************
* PSA crypto prototypes
****************************************************************************//**
*
* \defgroup psacrypto     IFX SE PSA crypto API
* \brief
*  This is the adopted version of PSA crypto API based on Mbed TLS
* \{
*   \defgroup hash_operations Hash operations
*       Hash operations definitions
*   \defgroup async_operations Signature and verification operations
*       Signature and verification operations definitions
*   \defgroup cipher_operations Cipher operations
*       Cipher operations definitions
*   \defgroup aead_operations AEAD operations
*       AEAD operations definitions
*   \defgroup mac_operations MAC operations
*       MAC operations definitions
*   \defgroup import_export Key import and export
*       Key import and export definitions
*   \defgroup key_derivation Key derivation
*       Key derivation definitions
*   \defgroup random Random generation
*       Random generation definitions
*   \defgroup crc32_calc CRC32 operations
*       CRC32 operations definitions
*   \defgroup key_attributes Key attributes operations
*       Key attributes operations definitions
*   \{
*       \defgroup crypto_types Key types
*           Key types operations definitions
*       \defgroup crypto_algs Key algorithms
*           Key algorithms operations definitions
*       \defgroup key_policy Key policies
*           Key policies operations definitions
*       \defgroup key_lifetimes Key lifetimes
*           Key lifetimes operations definitions
*       \defgroup builtin_keys Built-In keys
*           Built-In keys definitions
*   \}
*   \defgroup constants_sizes Data size definitions
*       Data size definitions
*   \defgroup psacrypto_error Error codes definitions
*       Error codes definitions
* \}
*
*******************************************************************************/

#ifndef IFX_SE_PSACRYPTO_H
#define IFX_SE_PSACRYPTO_H

#include <stddef.h>
#include <stdint.h>

#include "ifx_se_fih.h"

/** This type represents open handles to keys.
 * 0 is not a valid key handle. How other handle values are assigned is
 * implementation-dependent.
 * */
typedef uint32_t ifx_se_key_handle_t;

#ifdef __cplusplus
extern "C" {
#endif

/* The file "crypto_types.h" declares types that encode errors,
 * algorithms, key types, policies, etc. */
#include "ifx_se_psacrypto_types.h"

/* The file "crypto_values.h" declares macros to build and analyze values
 * of integral types defined in "crypto_types.h". */
#include "ifx_se_psacrypto_values.h"

/* The file "crypto_struct.h" contains definitions for
 * implementation-specific structs that are declared above. */
#include "ifx_se_psacrypto_struct.h"

/* The file "crypto_sizes.h" contains definitions for size calculation
 * macros whose definitions are implementation-specific. */
#include "ifx_se_psacrypto_sizes.h"

#include "ifx_se_syscall.h"

/** \addtogroup async_operations
 * \{
 */

/**
 * \brief Sign a hash or short message with a private key.
 *
 * Note that to perform a hash-and-sign signature algorithm, you must
 * first calculate the hash by calling ifx_se_hash_setup(), ifx_se_hash_update()
 * and ifx_se_hash_finish(), or alternatively by calling ifx_se_hash_compute().
 * Then pass the resulting hash as the \p hash
 * parameter to this function. You can use #IFX_SE_ALG_SIGN_GET_HASH(\p alg)
 * to determine the hash algorithm to use.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must be an asymmetric key pair. The key must
 *                              allow the usage #IFX_SE_KEY_USAGE_SIGN_HASH.
 * \param[in] alg               A signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_HASH(\p alg)
 *                              is true), that is compatible with
 *                              the type of \p key.
 * \param[in] hash              The hash or message to sign
 *                              (encoded pointer to input data).
 * \param[in] hash_length       Size of the \p hash buffer in bytes (size_t).
 * \param[out] signature        Buffer where the signature is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] signature_size    Size of the \p signature buffer in bytes (size_t).
 * \param[out] signature_length On success, the number of bytes
 *                              that make up the returned signature value
 *                              (encoded pointer to size_t variable).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p signature buffer is too small. You can
 *         determine a sufficient buffer size by calling
 *         #IFX_SE_SIGN_OUTPUT_SIZE(\c key_type, \c key_bits, \p alg)
 *         where \c key_type and \c key_bits are the type and bit-size
 *         respectively of \p key.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 */
ifx_se_status_t ifx_se_sign_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_size,
    ifx_se_fih_ptr_t signature_length,
    void *ctx);

/**
 * \brief Verify the signature of a hash or short message using a public key.
 *
 * Note that to perform a hash-and-sign signature algorithm, you must
 * first calculate the hash by calling ifx_se_hash_setup(), ifx_se_hash_update()
 * and ifx_se_hash_finish(), or alternatively by calling ifx_se_hash_compute().
 * Then pass the resulting hash as the \p hash
 * parameter to this function. You can use #IFX_SE_ALG_SIGN_GET_HASH(\p alg)
 * to determine the hash algorithm to use.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must be a public key or an asymmetric key
 *                              pair. The key must allow the usage
 *                              #IFX_SE_KEY_USAGE_VERIFY_HASH.
 * \param[in] alg               A signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_HASH(\p alg)
 *                              is true), that is compatible with
 *                              the type of \p key.
 * \param[in] hash              The hash or message whose signature is to be
 *                              verified
 *                              (encoded pointer to input data).
 * \param[in] hash_length       Size of the \p hash buffer in bytes (size_t).
 * \param[in] signature         Buffer containing the signature to verify
 *                              (encoded pointer to input data).
 * \param[in] signature_length  Size of the \p signature buffer in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         The signature is valid.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The calculation was performed successfully, but the passed
 *         signature is not a valid signature.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_verify_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_length,
    void *ctx);

/**
 * \brief Sign a message with a private key. For hash-and-sign algorithms,
 *        this includes the hashing step.
 *
 * \note To perform a multi-part hash-and-sign signature algorithm, first use
 *       a multi-part hash operation and then pass the resulting hash to
 *       ifx_se_sign_hash(). IFX_SE_ALG_GET_HASH(\p alg) can be used to determine the
 *       hash algorithm to use.
 *
 * \param[in]  key              Identifier of the key to use for the operation.
 *                              It must be an asymmetric key pair. The key must
 *                              allow the usage #IFX_SE_KEY_USAGE_SIGN_MESSAGE.
 * \param[in]  alg              An asymmetric signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_MESSAGE(\p alg)
 *                              is true), that is compatible with the type of
 *                              \p key.
 * \param[in]  input            The input message to sign
 *                              (encoded pointer to input data).
 * \param[in]  input_length     Size of the \p input buffer in bytes (size_t).
 * \param[out] signature        Buffer where the signature is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  signature_size   Size of the \p signature buffer in bytes (size_t).
 *                              This must be appropriate for the selected
 *                              algorithm and key:
 *                              - The required signature size is
 *                                #IFX_SE_SIGN_OUTPUT_SIZE(\c key_type, \c key_bits, \p alg)
 *                                where \c key_type and \c key_bits are the type and
 *                                bit-size respectively of key.
 *                              - #IFX_SE_SIGNATURE_MAX_SIZE evaluates to the
 *                                maximum signature size of any supported
 *                                signature algorithm.
 * \param[out] signature_length On success, the number of bytes that make up
 *                              the returned signature value
 *                              (encoded pointer to size_t variable).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key does not have the #IFX_SE_KEY_USAGE_SIGN_MESSAGE flag,
 *         or it does not permit the requested algorithm.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p signature buffer is too small. You can
 *         determine a sufficient buffer size by calling
 *         #IFX_SE_SIGN_OUTPUT_SIZE(\c key_type, \c key_bits, \p alg)
 *         where \c key_type and \c key_bits are the type and bit-size
 *         respectively of \p key.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 */
ifx_se_status_t ifx_se_sign_message(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_size,
    ifx_se_fih_ptr_t signature_length,
    void *ctx);

/** \brief Verify the signature of a message with a public key, using
 *         a hash-and-sign verification algorithm.
 *
 * \note To perform a multi-part hash-and-sign signature verification
 *       algorithm, first use a multi-part hash operation to hash the message
 *       and then pass the resulting hash to ifx_se_verify_hash().
 *       IFX_SE_ALG_GET_HASH(\p alg) can be used to determine the hash algorithm
 *       to use.
 *
 * \param[in]  key              Identifier of the key to use for the operation.
 *                              It must be a public key or an asymmetric key
 *                              pair. The key must allow the usage
 *                              #IFX_SE_KEY_USAGE_VERIFY_MESSAGE.
 * \param[in]  alg              An asymmetric signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_MESSAGE(\p alg)
 *                              is true), that is compatible with the type of
 *                              \p key.
 * \param[in]  input            The message whose signature is to be verified
 *                              (encoded pointer to input data).
 * \param[in]  input_length     Size of the \p input buffer in bytes (size_t).
 * \param[in]  signature        Buffer containing the signature to verify
 *                              (encoded pointer to input data).
 * \param[in]  signature_length Size of the \p signature buffer in bytes (size_t).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key does not have the #IFX_SE_KEY_USAGE_SIGN_MESSAGE flag,
 *         or it does not permit the requested algorithm.
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The calculation was performed successfully, but the passed signature
 *         is not a valid signature.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_DATA_INVALID
 */
ifx_se_status_t ifx_se_verify_message(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_length,
    void *ctx);

/** \} */


/** \addtogroup aead_operations
 * \{
 */

/** Process an authenticated encryption operation.
 *
 * \param[in] key                 Identifier of the key to use for the
 *                                operation. It must allow the usage
 *                                #IFX_SE_KEY_USAGE_ENCRYPT.
 * \param[in] alg                 The AEAD algorithm to compute
 *                                (\c IFX_SE_ALG_XXX value such that
 *                                #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param[in] nonce               Nonce or IV to use
 *                                (encoded pointer to input data).
 * \param[in] nonce_length        Size of the \p nonce buffer in bytes (size_t).
 * \param[in] additional_data     Additional data that will be authenticated
 *                                but not encrypted
 *                                (encoded pointer to input data).
 * \param[in] additional_data_length  Size of \p additional_data in bytes (size_t).
 * \param[in] plaintext           Data that will be authenticated and
 *                                encrypted
 *                                (encoded pointer to input data).
 * \param[in] plaintext_length    Size of \p plaintext in bytes (size_t).
 * \param[out] ciphertext         Output buffer for the authenticated and
 *                                encrypted data
 *                                (encoded pointer to output buffer).
 *                                The additional data is not
 *                                part of this output. For algorithms where the
 *                                encrypted data and the authentication tag
 *                                are defined as separate outputs, the
 *                                authentication tag is appended to the
 *                                encrypted data.
 * \param[in] ciphertext_size     Size of the \p ciphertext buffer in bytes (size_t).
 *                                This must be appropriate for the selected
 *                                algorithm and key:
 *                                - A sufficient output size is
 *                                  #IFX_SE_AEAD_ENCRYPT_OUTPUT_SIZE(\c key_type,
 *                                  \p alg, \p plaintext_length) where
 *                                  \c key_type is the type of \p key.
 *                                - #IFX_SE_AEAD_ENCRYPT_OUTPUT_MAX_SIZE(\p
 *                                  plaintext_length) evaluates to the maximum
 *                                  ciphertext size of any supported AEAD
 *                                  encryption.
 * \param[out] ciphertext_length  On success, the size of the output
 *                                in the \p ciphertext buffer
 *                                (encoded pointer to size_t variable).
 * \param[in]  ctx                The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not an AEAD algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         \p ciphertext_size is too small.
 *         #IFX_SE_AEAD_ENCRYPT_OUTPUT_SIZE(\c key_type, \p alg,
 *         \p plaintext_length) or
 *         #IFX_SE_AEAD_ENCRYPT_OUTPUT_MAX_SIZE(\p plaintext_length) can be used to
 *         determine the required buffer size.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_aead_encrypt(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t nonce,
    ifx_se_fih_t nonce_length,
    const ifx_se_fih_ptr_t additional_data,
    ifx_se_fih_t additional_data_length,
    const ifx_se_fih_ptr_t plaintext,
    ifx_se_fih_t plaintext_length,
    const ifx_se_fih_ptr_t ciphertext,
    ifx_se_fih_t ciphertext_size,
    ifx_se_fih_ptr_t ciphertext_length,
    void *ctx);

/** Process an authenticated decryption operation.
 *
 * \param[in] key                 Identifier of the key to use for the
 *                                operation. It must allow the usage
 *                                #IFX_SE_KEY_USAGE_DECRYPT.
 * \param[in] alg                 The AEAD algorithm to compute
 *                                (\c IFX_SE_ALG_XXX value such that
 *                                #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param[in] nonce               Nonce or IV to use
 *                                (encoded pointer to input data).
 * \param[in] nonce_length        Size of the \p nonce buffer in bytes (size_t).
 * \param[in] additional_data     Additional data that has been authenticated
 *                                but not encrypted
 *                                (encoded pointer to input data).
 * \param[in] additional_data_length  Size of \p additional_data in bytes (size_t).
 * \param[in] ciphertext          Data that has been authenticated and
 *                                encrypted
 *                                (encoded pointer to input data).
 *                                For algorithms where the
 *                                encrypted data and the authentication tag
 *                                are defined as separate inputs, the buffer
 *                                must contain the encrypted data followed
 *                                by the authentication tag.
 * \param[in] ciphertext_length   Size of \p ciphertext in bytes
 *                                (encoded pointer to input data).
 * \param[out] plaintext          Output buffer for the decrypted data
 *                                (encoded pointer to output buffer).
 * \param[in] plaintext_size      Size of the \p plaintext buffer in bytes (size_t).
 *                                This must be appropriate for the selected
 *                                algorithm and key:
 *                                - A sufficient output size is
 *                                  #IFX_SE_AEAD_DECRYPT_OUTPUT_SIZE(\c key_type,
 *                                  \p alg, \p ciphertext_length) where
 *                                  \c key_type is the type of \p key.
 *                                - #IFX_SE_AEAD_DECRYPT_OUTPUT_MAX_SIZE(\p
 *                                  ciphertext_length) evaluates to the maximum
 *                                  plaintext size of any supported AEAD
 *                                  decryption.
 * \param[out] plaintext_length   On success, the size of the output
 *                                in the \p plaintext buffer
 *                                (encoded pointer to size_t variable).
 * \param[in] ctx                 The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The ciphertext is not authentic.
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not an AEAD algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         \p plaintext_size is too small.
 *         #IFX_SE_AEAD_DECRYPT_OUTPUT_SIZE(\c key_type, \p alg,
 *         \p ciphertext_length) or
 *         #IFX_SE_AEAD_DECRYPT_OUTPUT_MAX_SIZE(\p ciphertext_length) can be used
 *         to determine the required buffer size.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_aead_decrypt(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t nonce,
    ifx_se_fih_t nonce_length,
    const ifx_se_fih_ptr_t additional_data,
    ifx_se_fih_t additional_data_length,
    const ifx_se_fih_ptr_t ciphertext,
    ifx_se_fih_t ciphertext_length,
    const ifx_se_fih_ptr_t plaintext,
    ifx_se_fih_t plaintext_size,
    ifx_se_fih_ptr_t plaintext_length,
    void *ctx);

/** Set the key for a multipart authenticated encryption operation.
 *
 * The sequence of operations to encrypt a message with authentication
 * is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_aead_operation_t, e.g.
 *    #IFX_SE_AEAD_OPERATION_INIT.
 * -# Call ifx_se_aead_encrypt_setup() to specify the algorithm and key.
 * -# If needed, call ifx_se_aead_set_lengths() to specify the length of the
 *    inputs to the subsequent calls to ifx_se_aead_update_ad() and
 *    ifx_se_aead_update(). See the documentation of ifx_se_aead_set_lengths()
 *    for details.
 * -# Call either ifx_se_aead_generate_nonce() or ifx_se_aead_set_nonce() to
 *    generate or set the nonce. You should use
 *    ifx_se_aead_generate_nonce() unless the protocol you are implementing
 *    requires a specific nonce value.
 * -# Call ifx_se_aead_update_ad() zero, one or more times, passing a fragment
 *    of the non-encrypted additional authenticated data each time.
 * -# Call ifx_se_aead_update() zero, one or more times, passing a fragment
 *    of the message to encrypt each time.
 * -# Call ifx_se_aead_finish().
 *
 * If an error occurs at any step after a call to ifx_se_aead_encrypt_setup(),
 * the operation will need to be reset by a call to ifx_se_aead_abort(). The
 * application may call ifx_se_aead_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_aead_encrypt_setup(), the application must
 * eventually terminate the operation. The following events terminate an
 * operation:
 * - A successful call to ifx_se_aead_finish().
 * - A call to ifx_se_aead_abort().
 *
 * \param[in,out] operation     The operation object to set up. It must have
 *                              been initialized as per the documentation for
 *                              #ifx_se_aead_operation_t and not yet in use.
 * \param[in] key            Identifier of the key to use for the operation.
 *                              It must remain valid until the operation
 *                              terminates. It must allow the usage
 *                              #IFX_SE_KEY_USAGE_ENCRYPT.
 * \param[in] alg               The AEAD algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive), or
 *         the library has not been previously initialized by ifx_se_crypto_init().
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not an AEAD algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_aead_encrypt_setup(
    ifx_se_aead_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Set the key for a multipart authenticated decryption operation.
 *
 * The sequence of operations to decrypt a message with authentication
 * is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_aead_operation_t, e.g.
 *    #IFX_SE_AEAD_OPERATION_INIT.
 * -# Call ifx_se_aead_decrypt_setup() to specify the algorithm and key.
 * -# If needed, call ifx_se_aead_set_lengths() to specify the length of the
 *    inputs to the subsequent calls to ifx_se_aead_update_ad() and
 *    ifx_se_aead_update(). See the documentation of ifx_se_aead_set_lengths()
 *    for details.
 * -# Call ifx_se_aead_set_nonce() with the nonce for the decryption.
 * -# Call ifx_se_aead_update_ad() zero, one or more times, passing a fragment
 *    of the non-encrypted additional authenticated data each time.
 * -# Call ifx_se_aead_update() zero, one or more times, passing a fragment
 *    of the ciphertext to decrypt each time.
 * -# Call ifx_se_aead_verify().
 *
 * If an error occurs at any step after a call to ifx_se_aead_decrypt_setup(),
 * the operation will need to be reset by a call to ifx_se_aead_abort(). The
 * application may call ifx_se_aead_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_aead_decrypt_setup(), the application must
 * eventually terminate the operation. The following events terminate an
 * operation:
 * - A successful call to ifx_se_aead_verify().
 * - A call to ifx_se_aead_abort().
 *
 * \param[in,out] operation     The operation object to set up. It must have
 *                              been initialized as per the documentation for
 *                              #ifx_se_aead_operation_t and not yet in use.
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must remain valid until the operation
 *                              terminates. It must allow the usage
 *                              #IFX_SE_KEY_USAGE_DECRYPT.
 * \param[in] alg               The AEAD algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not an AEAD algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_aead_decrypt_setup(
    ifx_se_aead_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Generate a random nonce for an authenticated encryption operation.
 *
 * This function generates a random nonce for the authenticated encryption
 * operation with an appropriate size for the chosen algorithm, key type
 * and key size.
 *
 * The application must call ifx_se_aead_encrypt_setup() before
 * calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[out] nonce            Buffer where the generated nonce is to be
 *                              written
 *                              (encoded pointer to output buffer).
 * \param[in] nonce_size        Size of the \p nonce buffer in bytes (size_t).
 * \param[out] nonce_length     On success, the number of bytes of the
 *                              generated nonce
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p nonce buffer is too small.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active AEAD encrypt
 *         operation, with no nonce set).
 */
ifx_se_status_t ifx_se_aead_generate_nonce(
    ifx_se_aead_operation_t *operation,
    ifx_se_fih_ptr_t nonce,
    ifx_se_fih_t nonce_size,
    ifx_se_fih_ptr_t nonce_length,
    void *ctx);

/** Set the nonce for an authenticated encryption or decryption operation.
 *
 * This function sets the nonce for the authenticated
 * encryption or decryption operation.
 *
 * The application must call ifx_se_aead_encrypt_setup() or
 * ifx_se_aead_decrypt_setup() before calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \note When encrypting, applications should use ifx_se_aead_generate_nonce()
 * instead of this function, unless implementing a protocol that requires
 * a non-random IV.
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[in] nonce             Buffer containing the nonce to use
 *                              (encoded pointer to input data).
 * \param[in] nonce_length      Size of the nonce in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The size of \p nonce is not acceptable for the chosen algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, with no nonce
 *         set).
 */
ifx_se_status_t ifx_se_aead_set_nonce(
    ifx_se_aead_operation_t *operation,
    const ifx_se_fih_ptr_t nonce,
    ifx_se_fih_t nonce_length,
    void *ctx);

/** Declare the lengths of the message and additional data for AEAD.
 *
 * The application must call this function before calling
 * ifx_se_aead_update_ad() or ifx_se_aead_update() if the algorithm for
 * the operation requires it. If the algorithm does not require it,
 * calling this function is optional, but if this function is called
 * then the implementation must enforce the lengths.
 *
 * You may call this function before or after setting the nonce with
 * ifx_se_aead_set_nonce() or ifx_se_aead_generate_nonce().
 *
 * - For #IFX_SE_ALG_CCM, calling this function is required.
 * - For the other AEAD algorithms defined in this specification, calling
 *   this function is not required.
 * - For vendor-defined algorithm, refer to the vendor documentation.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[in] ad_length         Size of the non-encrypted additional
 *                              authenticated data in bytes (size_t).
 * \param[in] plaintext_length  Size of the plaintext to encrypt in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         At least one of the lengths is not acceptable for the chosen
 *         algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, and
 *         ifx_se_aead_update_ad() and ifx_se_aead_update() must not have been
 *         called yet).
 */
ifx_se_status_t ifx_se_aead_set_lengths(
    ifx_se_aead_operation_t *operation,
    ifx_se_fih_t ad_length,
    ifx_se_fih_t plaintext_length,
    void *ctx);

/** Pass additional data to an active AEAD operation.
 *
 * Additional data is authenticated, but not encrypted.
 *
 * You may call this function multiple times to pass successive fragments
 * of the additional data. You may not call this function after passing
 * data to encrypt or decrypt with ifx_se_aead_update().
 *
 * Before calling this function, you must:
 * 1. Call either ifx_se_aead_encrypt_setup() or ifx_se_aead_decrypt_setup().
 * 2. Set the nonce with ifx_se_aead_generate_nonce() or ifx_se_aead_set_nonce().
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \warning When decrypting, until ifx_se_aead_verify() has returned #IFX_SE_SUCCESS,
 *          there is no guarantee that the input is valid. Therefore, until
 *          you have called ifx_se_aead_verify() and it has returned #IFX_SE_SUCCESS,
 *          treat the input as untrusted and prepare to undo any action that
 *          depends on the input if ifx_se_aead_verify() returns an error status.
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[in] input             Buffer containing the fragment of
 *                              additional data
 *                              (encoded pointer to input data).
 * \param[in] input_length      Size of the \p input buffer in bytes (size_t).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The total input length overflows the additional data length that
 *         was previously specified with ifx_se_aead_set_lengths().
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, have a nonce
 *         set, have lengths set if required by the algorithm, and
 *         ifx_se_aead_update() must not have been called yet).
 */
ifx_se_status_t ifx_se_aead_update_ad(
    ifx_se_aead_operation_t *operation,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    void *ctx);

/** Encrypt or decrypt a message fragment in an active AEAD operation.
 *
 * Before calling this function, you must:
 * 1. Call either ifx_se_aead_encrypt_setup() or ifx_se_aead_decrypt_setup().
 *    The choice of setup function determines whether this function
 *    encrypts or decrypts its input.
 * 2. Set the nonce with ifx_se_aead_generate_nonce() or ifx_se_aead_set_nonce().
 * 3. Call ifx_se_aead_update_ad() to pass all the additional data.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \warning When decrypting, until ifx_se_aead_verify() has returned #IFX_SE_SUCCESS,
 *          there is no guarantee that the input is valid. Therefore, until
 *          you have called ifx_se_aead_verify() and it has returned #IFX_SE_SUCCESS:
 *          - Do not use the output in any way other than storing it in a
 *            confidential location. If you take any action that depends
 *            on the tentative decrypted data, this action will need to be
 *            undone if the input turns out not to be valid. Furthermore,
 *            if an adversary can observe that this action took place
 *            (for example through timing), they may be able to use this
 *            fact as an oracle to decrypt any message encrypted with the
 *            same key.
 *          - In particular, do not copy the output anywhere but to a
 *            memory or storage space that you have exclusive access to.
 *
 * This function does not require the input to be aligned to any
 * particular block boundary. If the implementation can only process
 * a whole block at a time, it must consume all the input provided, but
 * it may delay the end of the corresponding output until a subsequent
 * call to ifx_se_aead_update(), ifx_se_aead_finish() or ifx_se_aead_verify()
 * provides sufficient input. The amount of data that can be delayed
 * in this way is bounded by #IFX_SE_AEAD_UPDATE_OUTPUT_SIZE.
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[in] input             Buffer containing the message fragment to
 *                              encrypt or decrypt
 *                              (encoded pointer to input data).
 * \param[in] input_length      Size of the \p input buffer in bytes (size_t).
 * \param[out] output           Buffer where the output is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] output_size       Size of the \p output buffer in bytes (size_t).
 *                              This must be appropriate for the selected
 *                                algorithm and key:
 *                                - A sufficient output size is
 *                                  #IFX_SE_AEAD_UPDATE_OUTPUT_SIZE(\c key_type,
 *                                  \c alg, \p input_length) where
 *                                  \c key_type is the type of key and \c alg is
 *                                  the algorithm that were used to set up the
 *                                  operation.
 *                                - #IFX_SE_AEAD_UPDATE_OUTPUT_MAX_SIZE(\p
 *                                  input_length) evaluates to the maximum
 *                                  output size of any supported AEAD
 *                                  algorithm.
 * \param[out] output_length    On success, the number of bytes
 *                              that make up the returned output
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p output buffer is too small.
 *         #IFX_SE_AEAD_UPDATE_OUTPUT_SIZE(\c key_type, \c alg, \p input_length) or
 *         #IFX_SE_AEAD_UPDATE_OUTPUT_MAX_SIZE(\p input_length) can be used to
 *         determine the required buffer size.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The total length of input to ifx_se_aead_update_ad() so far is
 *         less than the additional data length that was previously
 *         specified with ifx_se_aead_set_lengths(), or
 *         the total input length overflows the plaintext length that
 *         was previously specified with ifx_se_aead_set_lengths().
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, have a nonce
 *         set, and have lengths set if required by the algorithm).
 */
ifx_se_status_t ifx_se_aead_update(
    ifx_se_aead_operation_t *operation,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    ifx_se_fih_ptr_t output_length,
    void *ctx);

/** Finish encrypting a message in an AEAD operation.
 *
 * The operation must have been set up with ifx_se_aead_encrypt_setup().
 *
 * This function finishes the authentication of the additional data
 * formed by concatenating the inputs passed to preceding calls to
 * ifx_se_aead_update_ad() with the plaintext formed by concatenating the
 * inputs passed to preceding calls to ifx_se_aead_update().
 *
 * This function has two output buffers:
 * - \p ciphertext contains trailing ciphertext that was buffered from
 *   preceding calls to ifx_se_aead_update().
 * - \p tag contains the authentication tag.
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[out] ciphertext       Buffer where the last part of the ciphertext
 *                              is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] ciphertext_size   Size of the \p ciphertext buffer in bytes (size_t).
 *                              This must be appropriate for the selected
 *                              algorithm and key:
 *                              - A sufficient output size is
 *                                #IFX_SE_AEAD_FINISH_OUTPUT_SIZE(\c key_type,
 *                                \c alg) where \c key_type is the type of key
 *                                and \c alg is the algorithm that were used to
 *                                set up the operation.
 *                              - #IFX_SE_AEAD_FINISH_OUTPUT_MAX_SIZE evaluates to
 *                                the maximum output size of any supported AEAD
 *                                algorithm.
 * \param[out] ciphertext_length On success, the number of bytes of
 *                              returned ciphertext
 *                              (encoded pointer to size_t variable).
 * \param[out] tag              Buffer where the authentication tag is
 *                              to be written
 *                              (encoded pointer to output buffer).
 * \param[in] tag_size          Size of the \p tag buffer in bytes (size_t).
 *                              This must be appropriate for the selected
 *                              algorithm and key:
 *                              - The exact tag size is #IFX_SE_AEAD_TAG_LENGTH(\c
 *                                key_type, \c key_bits, \c alg) where
 *                                \c key_type and \c key_bits are the type and
 *                                bit-size of the key, and \c alg is the
 *                                algorithm that were used in the call to
 *                                ifx_se_aead_encrypt_setup().
 *                              - #IFX_SE_AEAD_TAG_MAX_SIZE evaluates to the
 *                                maximum tag size of any supported AEAD
 *                                algorithm.
 * \param[out] tag_length       On success, the number of bytes
 *                              that make up the returned tag
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p ciphertext or \p tag buffer is too small.
 *         #IFX_SE_AEAD_FINISH_OUTPUT_SIZE(\c key_type, \c alg) or
 *         #IFX_SE_AEAD_FINISH_OUTPUT_MAX_SIZE can be used to determine the
 *         required \p ciphertext buffer size. #IFX_SE_AEAD_TAG_LENGTH(\c key_type,
 *         \c key_bits, \c alg) or #IFX_SE_AEAD_TAG_MAX_SIZE can be used to
 *         determine the required \p tag buffer size.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The total length of input to ifx_se_aead_update_ad() so far is
 *         less than the additional data length that was previously
 *         specified with ifx_se_aead_set_lengths(), or
 *         the total length of input to ifx_se_aead_update() so far is
 *         less than the plaintext length that was previously
 *         specified with ifx_se_aead_set_lengths().
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active encryption
 *         operation with a nonce set).
 */
ifx_se_status_t ifx_se_aead_finish(
    ifx_se_aead_operation_t *operation,
    ifx_se_fih_ptr_t ciphertext,
    ifx_se_fih_t ciphertext_size,
    ifx_se_fih_ptr_t ciphertext_length,
    ifx_se_fih_ptr_t tag,
    ifx_se_fih_t tag_size,
    ifx_se_fih_ptr_t tag_length,
    void *ctx);

/** Finish authenticating and decrypting a message in an AEAD operation.
 *
 * The operation must have been set up with ifx_se_aead_decrypt_setup().
 *
 * This function finishes the authenticated decryption of the message
 * components:
 *
 * -  The additional data consisting of the concatenation of the inputs
 *    passed to preceding calls to ifx_se_aead_update_ad().
 * -  The ciphertext consisting of the concatenation of the inputs passed to
 *    preceding calls to ifx_se_aead_update().
 * -  The tag passed to this function call.
 *
 * If the authentication tag is correct, this function outputs any remaining
 * plaintext and reports success. If the authentication tag is not correct,
 * this function returns #IFX_SE_ERROR_INVALID_SIGNATURE.
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_aead_abort().
 *
 * \note Implementations shall make the best effort to ensure that the
 * comparison between the actual tag and the expected tag is performed
 * in constant time.
 *
 * \param[in,out] operation     Active AEAD operation.
 * \param[out] plaintext        Buffer where the last part of the plaintext
 *                              is to be written
 *                              (encoded pointer to output buffer).
 *                              This is the remaining data
 *                              from previous calls to ifx_se_aead_update()
 *                              that could not be processed until the end
 *                              of the input.
 * \param[in] plaintext_size    Size of the \p plaintext buffer in bytes (size_t).
 *                              This must be appropriate for the selected algorithm and key:
 *                              - A sufficient output size is
 *                                #IFX_SE_AEAD_VERIFY_OUTPUT_SIZE(\c key_type,
 *                                \c alg) where \c key_type is the type of key
 *                                and \c alg is the algorithm that were used to
 *                                set up the operation.
 *                              - #IFX_SE_AEAD_VERIFY_OUTPUT_MAX_SIZE evaluates to
 *                                the maximum output size of any supported AEAD
 *                                algorithm.
 * \param[out] plaintext_length On success, the number of bytes of
 *                              returned plaintext
 *                              (encoded pointer to size_t variable).
 * \param[in] tag               Buffer containing the authentication tag
 *                              (encoded pointer to input data).
 * \param[in] tag_length        Size of the \p tag buffer in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The calculations were successful, but the authentication tag is
 *         not correct.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p plaintext buffer is too small.
 *         #IFX_SE_AEAD_VERIFY_OUTPUT_SIZE(\c key_type, \c alg) or
 *         #IFX_SE_AEAD_VERIFY_OUTPUT_MAX_SIZE can be used to determine the
 *         required buffer size.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The total length of input to ifx_se_aead_update_ad() so far is
 *         less than the additional data length that was previously
 *         specified with ifx_se_aead_set_lengths(), or
 *         the total length of input to ifx_se_aead_update() so far is
 *         less than the plaintext length that was previously
 *         specified with ifx_se_aead_set_lengths().
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active decryption
 *         operation with a nonce set).
 */
ifx_se_status_t ifx_se_aead_verify(
    ifx_se_aead_operation_t *operation,
    ifx_se_fih_ptr_t plaintext,
    ifx_se_fih_t plaintext_size,
    ifx_se_fih_ptr_t plaintext_length,
    const ifx_se_fih_ptr_t tag,
    ifx_se_fih_t tag_length,
    void *ctx);

/** Abort an AEAD operation.
 *
 * Aborting an operation frees all associated resources except for the
 * \p operation structure itself. Once aborted, the operation object
 * can be reused for another operation by calling
 * ifx_se_aead_encrypt_setup() or ifx_se_aead_decrypt_setup() again.
 *
 * You may call this function any time after the operation object has
 * been initialized as described in #ifx_se_aead_operation_t.
 *
 * In particular, calling ifx_se_aead_abort() after the operation has been
 * terminated by a call to ifx_se_aead_abort(), ifx_se_aead_finish() or
 * ifx_se_aead_verify() is safe and has no effect.
 *
 * \param[in,out] operation     Initialized AEAD operation.
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_aead_abort(
    ifx_se_aead_operation_t *operation,
    void *ctx);

/** \} */

/** \addtogroup cipher_operations
 * \{
 */

/** Encrypt a message using a symmetric cipher with provided IV.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must allow the usage #IFX_SE_KEY_USAGE_ENCRYPT.
 * \param[in] alg               The cipher algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param[in] iv                Buffer containing the IV to use
 *                              (encoded pointer to input data).
 * \param[in] iv_length         Size of the IV in bytes (size_t).
 * \param[in] input             Buffer containing the message to encrypt
 *                              (encoded pointer to input data).
 * \param[in] input_length      Size of the \p input buffer in bytes (size_t).
 * \param[out] output           Buffer where the output is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] output_size       Size of the \p output buffer in bytes (size_t).
 * \param[out] output_length    On success, the number of bytes
 *                              that make up the output
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a cipher algorithm.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_cipher_encrypt(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t iv,
    ifx_se_fih_t iv_length,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    ifx_se_fih_ptr_t output_length,
    void *ctx);

/** Decrypt a message using a symmetric cipher.
 *
 * This function decrypts a message encrypted with a symmetric cipher.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must remain valid until the operation
 *                              terminates. It must allow the usage
 *                              #IFX_SE_KEY_USAGE_DECRYPT.
 * \param[in] alg               The cipher algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param[in] input             Buffer containing the message to decrypt
 *                              (encoded pointer to input data).
 *                              This consists of the IV followed by the
 *                              ciphertext proper.
 * \param[in] input_length      Size of the \p input buffer in bytes (size_t).
 * \param[out] output           Buffer where the plaintext is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] output_size       Size of the \p output buffer in bytes (size_t).
 * \param[out] output_length    On success, the number of bytes
 *                              that make up the output
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a cipher algorithm.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_cipher_decrypt(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    ifx_se_fih_ptr_t output_length,
    void *ctx);

/** Set the key for a multipart symmetric encryption operation.
 *
 * The sequence of operations to encrypt a message with a symmetric cipher
 * is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_cipher_operation_t, e.g.
 *    #IFX_SE_CIPHER_OPERATION_INIT.
 * -# Call ifx_se_cipher_encrypt_setup() to specify the algorithm and key.
 * -# Call either ifx_se_cipher_generate_iv() or ifx_se_cipher_set_iv() to
 *    generate or set the IV (initialization vector). You should use
 *    ifx_se_cipher_generate_iv() unless the protocol you are implementing
 *    requires a specific IV value.
 * -# Call ifx_se_cipher_update() zero, one or more times, passing a fragment
 *    of the message each time.
 * -# Call ifx_se_cipher_finish().
 *
 * If an error occurs at any step after a call to ifx_se_cipher_encrypt_setup(),
 * the operation will need to be reset by a call to ifx_se_cipher_abort(). The
 * application may call ifx_se_cipher_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_cipher_encrypt_setup(), the application must
 * eventually terminate the operation. The following events terminate an
 * operation:
 * - A successful call to ifx_se_cipher_finish().
 * - A call to ifx_se_cipher_abort().
 *
 * \param[in,out] operation     The operation object to set up. It must have
 *                              been initialized as per the documentation for
 *                              #ifx_se_cipher_operation_t and not yet in use.
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must remain valid until the operation
 *                              terminates. It must allow the usage
 *                              #IFX_SE_KEY_USAGE_ENCRYPT.
 * \param[in] alg               The cipher algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a cipher algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_cipher_encrypt_setup(
    ifx_se_cipher_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Set the key for a multipart symmetric decryption operation.
 *
 * The sequence of operations to decrypt a message with a symmetric cipher
 * is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_cipher_operation_t, e.g.
 *    #IFX_SE_CIPHER_OPERATION_INIT.
 * -# Call ifx_se_cipher_decrypt_setup() to specify the algorithm and key.
 * -# Call ifx_se_cipher_set_iv() with the IV (initialization vector) for the
 *    decryption. If the IV is prepended to the ciphertext, you can call
 *    ifx_se_cipher_update() on a buffer containing the IV followed by the
 *    beginning of the message.
 * -# Call ifx_se_cipher_update() zero, one or more times, passing a fragment
 *    of the message each time.
 * -# Call ifx_se_cipher_finish().
 *
 * If an error occurs at any step after a call to ifx_se_cipher_decrypt_setup(),
 * the operation will need to be reset by a call to ifx_se_cipher_abort(). The
 * application may call ifx_se_cipher_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_cipher_decrypt_setup(), the application must
 * eventually terminate the operation. The following events terminate an
 * operation:
 * - A successful call to ifx_se_cipher_finish().
 * - A call to ifx_se_cipher_abort().
 *
 * \param[in,out] operation     The operation object to set up. It must have
 *                              been initialized as per the documentation for
 *                              #ifx_se_cipher_operation_t and not yet in use.
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must remain valid until the operation
 *                              terminates. It must allow the usage
 *                              #IFX_SE_KEY_USAGE_DECRYPT.
 * \param[in] alg               The cipher algorithm to compute
 *                              (\c IFX_SE_ALG_XXX value such that
 *                              #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a cipher algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_cipher_decrypt_setup(
    ifx_se_cipher_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Generate an IV for a symmetric encryption operation.
 *
 * This function generates a random IV (initialization vector), nonce
 * or initial counter value for the encryption operation as appropriate
 * for the chosen algorithm, key type and key size.
 *
 * The application must call ifx_se_cipher_encrypt_setup() before
 * calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_cipher_abort().
 *
 * \param[in,out] operation     Active cipher operation.
 * \param[out] iv               Buffer where the generated IV is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  iv_size          Size of the \p iv buffer in bytes (size_t).
 * \param[out] iv_length        On success, the number of bytes of the
 *                              generated IV
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p iv buffer is too small.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, with no IV set).
 */
ifx_se_status_t ifx_se_cipher_generate_iv(
    ifx_se_cipher_operation_t *operation,
    ifx_se_fih_ptr_t iv,
    ifx_se_fih_t iv_size,
    ifx_se_fih_ptr_t iv_length,
    void *ctx);

/** Set the IV for a symmetric encryption or decryption operation.
 *
 * This function sets the IV (initialization vector), nonce
 * or initial counter value for the encryption or decryption operation.
 *
 * The application must call ifx_se_cipher_encrypt_setup() before
 * calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_cipher_abort().
 *
 * \note When encrypting, applications should use ifx_se_cipher_generate_iv()
 * instead of this function, unless implementing a protocol that requires
 * a non-random IV.
 *
 * \param[in,out] operation     Active cipher operation.
 * \param[in] iv                Buffer containing the IV to use
 *                              (encoded pointer to input data).
 * \param[in] iv_length         Size of the IV in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The size of \p iv is not acceptable for the chosen algorithm,
 *         or the chosen algorithm does not use an IV.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active cipher
 *         encrypt operation, with no IV set).
 */
ifx_se_status_t ifx_se_cipher_set_iv(
    ifx_se_cipher_operation_t *operation,
    const ifx_se_fih_ptr_t iv,
    ifx_se_fih_t iv_length,
    void *ctx);

/** Encrypt or decrypt a message fragment in an active cipher operation.
 *
 * Before calling this function, you must:
 * 1. Call either ifx_se_cipher_encrypt_setup() or ifx_se_cipher_decrypt_setup().
 *    The choice of setup function determines whether this function
 *    encrypts or decrypts its input.
 * 2. If the algorithm requires an IV, call ifx_se_cipher_generate_iv()
 *    (recommended when encrypting) or ifx_se_cipher_set_iv().
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_cipher_abort().
 *
 * \param[in,out] operation     Active cipher operation.
 * \param[in] input             Buffer containing the message fragment to
 *                              encrypt or decrypt
 *                              (encoded pointer to input data).
 * \param[in]  input_length     Size of the \p input buffer in bytes (size_t).
 * \param[out] output           Buffer where the output is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  output_size      Size of the \p output buffer in bytes (size_t).
 * \param[out] output_length    On success, the number of bytes
 *                              that make up the returned output
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p output buffer is too small.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, with an IV set
 *         if required for the algorithm).
 */
ifx_se_status_t ifx_se_cipher_update(
    ifx_se_cipher_operation_t *operation,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    ifx_se_fih_ptr_t output_length,
    void *ctx);

/** Finish encrypting or decrypting a message in a cipher operation.
 *
 * The application must call ifx_se_cipher_encrypt_setup() or
 * ifx_se_cipher_decrypt_setup() before calling this function. The choice
 * of setup function determines whether this function encrypts or
 * decrypts its input.
 *
 * This function finishes the encryption or decryption of the message
 * formed by concatenating the inputs passed to preceding calls to
 * ifx_se_cipher_update().
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_cipher_abort().
 *
 * \param[in,out] operation     Active cipher operation.
 * \param[out] output           Buffer where the output is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  output_size      Size of the \p output buffer in bytes (size_t).
 * \param[out] output_length    On success, the number of bytes
 *                              that make up the returned output
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The total input size passed to this operation is not valid for
 *         this particular algorithm. For example, the algorithm is a based
 *         on block cipher and requires a whole number of blocks, but the
 *         total input size is not a multiple of the block size.
 * \retval #IFX_SE_ERROR_INVALID_PADDING
 *         This is a decryption operation for an algorithm that includes
 *         padding, and the ciphertext does not contain valid padding.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p output buffer is too small.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active, with an IV set
 *         if required for the algorithm).
 */
ifx_se_status_t ifx_se_cipher_finish(
    ifx_se_cipher_operation_t *operation,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    ifx_se_fih_ptr_t output_length,
    void *ctx);

/** Abort a cipher operation.
 *
 * Aborting an operation frees all associated resources except for the
 * \p operation structure itself. Once aborted, the operation object
 * can be reused for another operation by calling
 * ifx_se_cipher_encrypt_setup() or ifx_se_cipher_decrypt_setup() again.
 *
 * You may call this function any time after the operation object has
 * been initialized as described in #ifx_se_cipher_operation_t.
 *
 * In particular, calling ifx_se_cipher_abort() after the operation has been
 * terminated by a call to ifx_se_cipher_abort() or ifx_se_cipher_finish()
 * is safe and has no effect.
 *
 * \param[in,out] operation     Initialized cipher operation.
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_cipher_abort(
    ifx_se_cipher_operation_t *operation,
    void *ctx);

/** \} */


/** \addtogroup import_export
 * \{
 */

/**
 * \brief Destroy a key.
 *
 * This function destroys a key from both volatile
 * memory and, if applicable, non-volatile storage. Implementations shall
 * make a best effort to ensure that that the key material cannot be recovered.
 *
 * This function also erases any metadata such as policies and frees
 * resources associated with the key.
 *
 * If a key is currently in use in a multipart operation, then destroying the
 * key will cause the multipart operation to fail.
 *
 * \param[in] key     Identifier of the key to erase. If this is \c 0,
 *                    do nothing and return #IFX_SE_SUCCESS.
 * \param[in]  ctx    The pointer to the SE syscall context that
 *                    contain a special syscall data
 *                    (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         \p key was a valid identifier and the key material that it
 *         referred to has been erased. Alternatively, \p key is \c 0.
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key cannot be erased because it is
 *         read-only, either due to a policy or due to physical restrictions.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 *         \p key is not a valid identifier nor \c 0.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 *         There was an failure in communication with the cryptoprocessor.
 *         The key material may still be present in the cryptoprocessor.
 * \retval #IFX_SE_ERROR_DATA_INVALID
 *         This error is typically a result of either storage corruption on a
 *         cleartext storage backend, or an attempt to read data that was
 *         written by an incompatible version of the library.
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The storage is corrupted. Implementations shall make a best effort
 *         to erase key material even in this stage, however applications
 *         should be aware that it may be impossible to guarantee that the
 *         key material is not recoverable in such cases.
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 *         An unexpected condition which is not a storage corruption or
 *         a communication failure occurred. The cryptoprocessor may have
 *         been compromised.
 */
ifx_se_status_t ifx_se_destroy_key(ifx_se_key_id_fih_t key, void *ctx);


/** Remove non-essential copies of key material from memory.
 *
 * If the key identifier designates a volatile key, this functions does not do
 * anything and returns successfully.
 *
 * If the key identifier designates a persistent key, then this function will
 * free all resources associated with the key in volatile memory. The key
 * data in persistent storage is not affected and the key can still be used.
 *
 * \param[in]  key    Identifier of the key to purge.
 * \param[in]  ctx    The pointer to the SE syscall context that
 *                    contain a special syscall data
 *                    (IPC release callback etc).
 *                              
 * \retval #IFX_SE_SUCCESS
 *         The key material will have been removed from memory if it is not
 *         currently required.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not a valid key identifier.
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_purge_key(ifx_se_key_id_fih_t key, void *ctx);

/**
 * \brief Generate a key or key pair.
 *
 * The key is generated randomly.
 * Its location, usage policy, type and size are taken from \p attributes.
 *
 * Implementations must reject an attempt to generate a key of size 0.
 *
 * \param[in] attributes    The attributes for the new key.
 * \param[out] key          On success, a pointer to identifier
 *                          of newly created key
 *                          (encoded pointer to #ifx_se_key_id_fih_t variable).
 *                          For persistent keys, this is the key
 *                          identifier defined in \p attributes.
 *                          \c 0 on failure. 
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 *         If the key is persistent, the key material and the key's metadata
 *         have been saved to persistent storage.
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 *         This is an attempt to create a persistent key, and there is
 *         already a persistent key with the given identifier.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 */
ifx_se_status_t ifx_se_generate_key(
    const ifx_se_key_attributes_t *attributes,
    ifx_se_fih_ptr_t key,
    void *ctx);

/** \} */


/** \addtogroup random
 * \{
 */

/**
 * \brief Generate random bytes.
 *
 * \warning This function **can** fail! Callers MUST check the return status
 *          and MUST NOT use the content of the output buffer if the return
 *          status is not #IFX_SE_SUCCESS.
 *
 * \note    To generate a key, use ifx_se_generate_key() instead.
 *
 * \param[out] output           Output buffer for the generated data.
 * \param[in]  output_size      Number of bytes to generate and output.
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \warning The output buffer MUST be larger than output_size by at least
 *          IFX_CRC32_CRC_SIZE (4 bytes) to save the CRC32 value at the end
 *          of the data block
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 *
 * \funcusage
 * \snippet main.c snippet_ifx_se_generate_random
 */
ifx_se_status_t ifx_se_generate_random(
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size, /* with CRC included */
    void *ctx);

/** \} */


/** \addtogroup hash_operations
 * \{
 */

/** Set up a multipart hash operation.
 *
 * The sequence of operations to calculate a hash (message digest)
 * is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_hash_operation_t, e.g. #IFX_SE_HASH_OPERATION_INIT.
 * -# Call ifx_se_hash_setup() to specify the algorithm.
 * -# Call ifx_se_hash_update() zero, one or more times, passing a fragment
 *    of the message each time. The hash that is calculated is the hash
 *    of the concatenation of these messages in order.
 * -# To calculate the hash, call ifx_se_hash_finish().
 *    To compare the hash with an expected value, call ifx_se_hash_verify().
 *
 * If an error occurs at any step after a call to ifx_se_hash_setup(), the
 * operation will need to be reset by a call to ifx_se_hash_abort(). The
 * application may call ifx_se_hash_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_hash_setup(), the application must
 * eventually terminate the operation. The following events terminate an
 * operation:
 * - A successful call to ifx_se_hash_finish() or ifx_se_hash_verify().
 * - A call to ifx_se_hash_abort().
 *
 * \param[in,out] operation The operation object to set up. It must have
 *                          been initialized as per the documentation for
 *                          #ifx_se_hash_operation_t and not yet in use.
 * \param[in] alg           The hash algorithm to compute (\c IFX_SE_ALG_XXX value
 *                          such that #IFX_SE_ALG_IS_HASH(\p alg) is true).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not a supported hash algorithm.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p alg is not a hash algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_hash_setup(
    ifx_se_hash_operation_t *operation,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Add a message fragment to a multipart hash operation.
 *
 * The application must call ifx_se_hash_setup() before calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_hash_abort().
 *
 * \param[in,out] operation   Active hash operation.
 * \param[in] input           Buffer containing the message fragment to hash
 *                            (encoded pointer to input data).
 * \param[in] input_length    Size of the \p input buffer in bytes (size_t).
 * \param[in] ctx             The pointer to the SE syscall context that
 *                            contain a special syscall data
 *                            (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_hash_update(
    ifx_se_hash_operation_t *operation,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    void *ctx);

/** Finish the calculation of the hash of a message.
 *
 * The application must call ifx_se_hash_setup() before calling this function.
 * This function calculates the hash of the message formed by concatenating
 * the inputs passed to preceding calls to ifx_se_hash_update().
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_hash_abort().
 *
 * \warning Applications should not call this function if they expect
 *          a specific value for the hash. Call ifx_se_hash_verify() instead.
 *          Beware that comparing integrity or authenticity data such as
 *          hash values with a function such as \c memcmp is risky
 *          because the time taken by the comparison may leak information
 *          about the hashed data which could allow an attacker to guess
 *          a valid hash and thereby bypass security controls.
 *
 * \param[in,out] operation     Active hash operation.
 * \param[out] hash             Buffer where the hash is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  hash_size        Size of the \p hash buffer in bytes (size_t).
 * \param[out] hash_length      On success, the number of bytes
 *                              that make up the hash value
 *                              (encoded pointer to size_t variable).
 *                              This is always #IFX_SE_HASH_LENGTH(\c alg)
 *                              where \c alg is the hash algorithm
 *                              that is calculated.
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p hash buffer is too small. You can determine a
 *         sufficient buffer size by calling #IFX_SE_HASH_LENGTH(\c alg)
 *         where \c alg is the hash algorithm that is calculated.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_hash_finish(
    ifx_se_hash_operation_t *operation,
    ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_size,
    ifx_se_fih_ptr_t hash_length,
    void *ctx);


/** Finish the calculation of the hash of a message and compare it with
 * an expected value.
 *
 * The application must call ifx_se_hash_setup() before calling this function.
 * This function calculates the hash of the message formed by concatenating
 * the inputs passed to preceding calls to ifx_se_hash_update(). It then
 * compares the calculated hash with the expected hash passed as a
 * parameter to this function.
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_hash_abort().
 *
 * \note Implementations shall make the best effort to ensure that the
 * comparison between the actual hash and the expected hash is performed
 * in constant time.
 *
 * \param[in,out] operation     Active hash operation.
 * \param[in] hash              Buffer containing the expected hash value
 *                              (encoded pointer to input data).
 * \param[in] hash_length       Size of the \p hash buffer in bytes (size_t).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         The expected hash is identical to the actual hash of the message.
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The hash of the message was calculated successfully, but it
 *         differs from the expected hash.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_hash_verify(
    ifx_se_hash_operation_t *operation,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    void *ctx);

/** Abort a hash operation.
 *
 * Aborting an operation frees all associated resources except for the
 * \p operation structure itself. Once aborted, the operation object
 * can be reused for another operation by calling
 * ifx_se_hash_setup() again.
 *
 * You may call this function any time after the operation object has
 * been initialized by one of the methods described in #ifx_se_hash_operation_t.
 *
 * In particular, calling ifx_se_hash_abort() after the operation has been
 * terminated by a call to ifx_se_hash_abort(), ifx_se_hash_finish() or
 * ifx_se_hash_verify() is safe and has no effect.
 *
 * \param[in,out] operation     Initialized hash operation.
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_hash_abort(
    ifx_se_hash_operation_t *operation,
    void *ctx);

/** Calculate the hash (digest) of a message.
 *
 * \note To verify the hash of a message against an
 *       expected value, use ifx_se_hash_compare() instead.
 *
 * \param[in] alg           The hash algorithm to compute (\c IFX_SE_ALG_XXX value
 *                          such that #IFX_SE_ALG_IS_HASH(\p alg) is true).
 * \param[in] input         Buffer containing the message to hash
 *                          (encoded pointer to input data).
 * \param[in] input_length  Size of the \p input buffer in bytes (size_t).
 * \param[out] hash         Buffer where the hash is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  hash_size    Size of the \p hash buffer in bytes (size_t).
 * \param[out] hash_length  On success, the number of bytes
 *                          that make up the hash value
 *                          (encoded pointer to size_t variable).
 *                          This is always #IFX_SE_HASH_LENGTH(\p alg).
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a hash algorithm.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         \p hash_size is too small
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_hash_compute(
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_size,
    ifx_se_fih_ptr_t hash_length,
    void *ctx);

/** Clone a hash operation.
 *
 * This function copies the state of an ongoing hash operation to
 * a new operation object. In other words, this function is equivalent
 * to calling ifx_se_hash_setup() on \p target_operation with the same
 * algorithm that \p source_operation was set up for, then
 * ifx_se_hash_update() on \p target_operation with the same input that
 * that was passed to \p source_operation. After this function returns, the
 * two objects are independent, i.e. subsequent calls involving one of
 * the objects do not affect the other object.
 *
 * \param[in] source_operation      The active hash operation to clone.
 * \param[in,out] target_operation  The operation object to set up.
 *                                  It must be initialized but not active.
 * \param[in] ctx                   The pointer to the SE syscall context that
 *                                  contain a special syscall data
 *                                  (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The \p source_operation state is not valid (it must be active), or
 *         the \p target_operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_hash_clone(
    const ifx_se_hash_operation_t *source_operation,
    ifx_se_hash_operation_t *target_operation,
    void *ctx);

/** \} */


/** \addtogroup import_export
 * \{
 */

/**
 * \brief Import a key in binary format.
 *
 * This function supports any output from ifx_se_export_key(). Refer to the
 * documentation of ifx_se_export_public_key() for the format of public keys
 * and to the documentation of ifx_se_export_key() for the format for
 * other key types.
 *
 * The key data determines the key size. The attributes may optionally
 * specify a key size; in this case it must match the size determined
 * from the key data. A key size of 0 in \p attributes indicates that
 * the key size is solely determined by the key data.
 *
 * Implementations must reject an attempt to import a key of size 0.
 *
 * This specification supports a single format for each key type.
 * Implementations may support other formats as long as the standard
 * format is supported. Implementations that support other formats
 * should ensure that the formats are clearly unambiguous so as to
 * minimize the risk that an invalid input is accidentally interpreted
 * according to a different format.
 *
 * \param[in] attributes    The attributes for the new key.
 *                          The key size is always determined from the
 *                          \p data buffer.
 *                          If the key size in \p attributes is nonzero,
 *                          it must be equal to the size from \p data.
 * \param[out] key          On success, an identifier to the newly created key
 *                          (encoded pointer to #ifx_se_key_id_fih_t variable).
 *                          For persistent keys, this is the key identifier
 *                          defined in \p attributes.
 *                          \c 0 on failure.
 * \param[in] data          Buffer containing the key data
 *                          (encoded pointer to input data). The content of this
 *                          buffer is interpreted according to the type declared
 *                          in \p attributes.
 *                          All implementations must support at least the format
 *                          described in the documentation
 *                          of ifx_se_export_key() or ifx_se_export_public_key()
 *                          for the chosen type. Implementations may allow other
 *                          formats, but should be conservative: implementations
 *                          should err on the side of rejecting content if it
 *                          may be erroneous (e.g. wrong type or truncated data).
 * \param[in] data_length   Size of the \p data buffer with CRC included
 *                          in bytes (size_t).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 *         If the key is persistent, the key material and the key's metadata
 *         have been saved to persistent storage.
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 *         This is an attempt to create a persistent key, and there is
 *         already a persistent key with the given identifier.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         The key type or key size is not supported, either by the
 *         implementation in general or in this particular persistent location.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The key attributes, as a whole, are invalid, or
 *         the key data is not correctly formatted, or
 *         the size in \p attributes is nonzero and does not match the size
 *         of the key data.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_import_key(
    const ifx_se_key_attributes_t *attributes,
    const ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_length, /* with CRC included */
    ifx_se_fih_ptr_t key,
    void *ctx);

/**
 * \brief Export a key in binary format.
 *
 * The output of this function can be passed to ifx_se_import_key() to
 * create an equivalent object.
 *
 * If the implementation of ifx_se_import_key() supports other formats
 * beyond the format specified here, the output from ifx_se_export_key()
 * must use the representation specified here, not the original
 * representation.
 *
 * For standard key types, the output format is as follows:
 *
 * - For symmetric keys (including MAC keys), the format is the
 *   raw bytes of the key.
 * - For DES, the key data consists of 8 bytes. The parity bits must be
 *   correct.
 * - For Triple-DES, the format is the concatenation of the
 *   two or three DES keys.
 * - For RSA key pairs (#IFX_SE_KEY_TYPE_RSA_KEY_PAIR), the format
 *   is the non-encrypted DER encoding of the representation defined by
 *   PKCS\#1 (RFC 8017) as `RSAPrivateKey`, version 0.
 *   ```
 *   RSAPrivateKey ::= SEQUENCE {
 *       version             INTEGER,  -- must be 0
 *       modulus             INTEGER,  -- n
 *       publicExponent      INTEGER,  -- e
 *       privateExponent     INTEGER,  -- d
 *       prime1              INTEGER,  -- p
 *       prime2              INTEGER,  -- q
 *       exponent1           INTEGER,  -- d mod (p-1)
 *       exponent2           INTEGER,  -- d mod (q-1)
 *       coefficient         INTEGER,  -- (inverse of q) mod p
 *   }
 *   ```
 * - For elliptic curve key pairs (key types for which
 *   #IFX_SE_KEY_TYPE_IS_ECC_KEY_PAIR is true), the format is
 *   a representation of the private value as a `ceiling(m/8)`-byte string
 *   where `m` is the bit size associated with the curve, i.e. the bit size
 *   of the order of the curve's coordinate field. This byte string is
 *   in little-endian order for Montgomery curves (curve types
 *   `IFX_SE_ECC_FAMILY_CURVEXXX`), and in big-endian order for Weierstrass
 *   curves (curve types `IFX_SE_ECC_FAMILY_SECTXXX`, `IFX_SE_ECC_FAMILY_SECPXXX`
 *   and `IFX_SE_ECC_FAMILY_BRAINPOOL_PXXX`).
 *   For Weierstrass curves, this is the content of the `privateKey` field of
 *   the `ECPrivateKey` format defined by RFC 5915.  For Montgomery curves,
 *   the format is defined by RFC 7748, and output is masked according to p.5.
 *   For twisted Edwards curves, the private key is as defined by RFC 8032
 *   (a 32-byte string for Edwards25519, a 57-byte string for Edwards448).
 * - For Diffie-Hellman key exchange key pairs (key types for which
 *   #IFX_SE_KEY_TYPE_IS_DH_KEY_PAIR is true), the
 *   format is the representation of the private key `x` as a big-endian byte
 *   string. The length of the byte string is the private key size in bytes
 *   (leading zeroes are not stripped).
 * - For public keys (key types for which #IFX_SE_KEY_TYPE_IS_PUBLIC_KEY is
 *   true), the format is the same as for ifx_se_export_public_key().
 *
 * The policy on the key must have the usage flag #IFX_SE_KEY_USAGE_EXPORT set.
 *
 * \param[in] key           Identifier of the key to export. It must allow the
 *                          usage #IFX_SE_KEY_USAGE_EXPORT, unless it is
 *                          a public key.
 * \param[out] data         Buffer where the key data is to be written
 *                          (encoded pointer to output buffer).
 * \param[in]  data_size    Size of the \p data buffer with CRC included
 *                          in bytes (size_t).
 * \param[out] data_length  On success, the number of bytes
 *                          that make up the key data
 *                          (encoded pointer to size_t variable).
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key does not have the #IFX_SE_KEY_USAGE_EXPORT flag.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p data buffer is too small. You can determine a
 *         sufficient buffer size by calling
 *         #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(\c type, \c bits)
 *         where \c type is the key type
 *         and \c bits is the key size in bits.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 */
ifx_se_status_t ifx_se_export_key(ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size, /* with CRC included */
    ifx_se_fih_ptr_t data_length,
    void *ctx);

/**
 * \brief Export a public key or the public part of a key pair in binary format.
 *
 * The output of this function can be passed to ifx_se_import_key() to
 * create an object that is equivalent to the public key.
 *
 * This specification supports a single format for each key type.
 * Implementations may support other formats as long as the standard
 * format is supported. Implementations that support other formats
 * should ensure that the formats are clearly unambiguous so as to
 * minimize the risk that an invalid input is accidentally interpreted
 * according to a different format.
 *
 * For standard key types, the output format is as follows:
 * - For RSA public keys (#IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY), the DER encoding of
 *   the representation defined by RFC 3279 &sect;2.3.1 as `RSAPublicKey`.
 *   ```
 *   RSAPublicKey ::= SEQUENCE {
 *      modulus            INTEGER,    -- n
 *      publicExponent     INTEGER  }  -- e
 *   ```
 * - For elliptic curve keys on a twisted Edwards curve (key types for which
 *   #IFX_SE_KEY_TYPE_IS_ECC_PUBLIC_KEY is true and #IFX_SE_KEY_TYPE_ECC_GET_FAMILY
 *   returns #IFX_SE_ECC_FAMILY_TWISTED_EDWARDS), the public key is as defined
 *   by RFC 8032
 *   (a 32-byte string for Edwards25519, a 57-byte string for Edwards448).
 * - For other elliptic curve public keys (key types for which
 *   #IFX_SE_KEY_TYPE_IS_ECC_PUBLIC_KEY is true), the format is the uncompressed
 *   representation defined by SEC1 &sect;2.3.3 as the content of an ECPoint.
 *   Let `m` be the bit size associated with the curve, i.e. the bit size of
 *   `q` for a curve over `F_q`. The representation consists of:
 *      - The byte 0x04;
 *      - `x_P` as a `ceiling(m/8)`-byte string, big-endian;
 *      - `y_P` as a `ceiling(m/8)`-byte string, big-endian.
 * - For Diffie-Hellman key exchange public keys (key types for which
 *   #IFX_SE_KEY_TYPE_IS_DH_PUBLIC_KEY is true),
 *   the format is the representation of the public key `y = g^x mod p` as a
 *   big-endian byte string. The length of the byte string is the length of the
 *   base prime `p` in bytes (size_t).
 *
 * Exporting a public key object or the public part of a key pair is
 * always permitted, regardless of the key's usage flags.
 *
 * \param[in] key               Identifier of the key to export.
 * \param[out] data             Buffer where the key data is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  data_size        Size of the \p data buffer with CRC included
 *                              in bytes (size_t).
 * \param[out] data_length      On success, the number of bytes
 *                              that make up the key data
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The key is neither a public key nor a key pair.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p data buffer is too small. You can determine a
 *         sufficient buffer size by calling
 *         #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(#IFX_SE_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR(\c type), \c bits)
 *         where \c type is the key type
 *         and \c bits is the key size in bits.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 */
ifx_se_status_t ifx_se_export_public_key(ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size, /* with CRC included */
    ifx_se_fih_ptr_t data_length,
    void *ctx);

/** Make a copy of a key.
 *
 * Copy key material from one location to another.
 *
 * This function is primarily useful to copy a key from one location
 * to another, since it populates a key using the material from
 * another key which may have a different lifetime.
 *
 * This function may be used to share a key with a different party,
 * subject to implementation-defined restrictions on key sharing.
 *
 * The policy on the source key must have the usage flag
 * #IFX_SE_KEY_USAGE_COPY set.
 * This flag is sufficient to permit the copy if the key has the lifetime
 * #IFX_SE_KEY_LIFETIME_VOLATILE or #IFX_SE_KEY_LIFETIME_PERSISTENT.
 * Some secure elements do not provide a way to copy a key without
 * making it extractable from the secure element. If a key is located
 * in such a secure element, then the key must have both usage flags
 * #IFX_SE_KEY_USAGE_COPY and #IFX_SE_KEY_USAGE_EXPORT in order to make
 * a copy of the key outside the secure element.
 *
 * The resulting key may only be used in a way that conforms to
 * both the policy of the original key and the policy specified in
 * the \p attributes parameter:
 * - The usage flags on the resulting key are the bitwise-and of the
 *   usage flags on the source policy and the usage flags in \p attributes.
 * - If both allow the same algorithm or wildcard-based
 *   algorithm policy, the resulting key has the same algorithm policy.
 * - If either of the policies allows an algorithm and the other policy
 *   allows a wildcard-based algorithm policy that includes this algorithm,
 *   the resulting key allows the same algorithm.
 * - If the policies do not allow any algorithm in common, this function
 *   fails with the status #IFX_SE_ERROR_INVALID_ARGUMENT.
 *
 * The effect of this function on implementation-defined attributes is
 * implementation-defined.
 *
 * \param[in] source_key    The key to copy. It must allow the usage
 *                          #IFX_SE_KEY_USAGE_COPY. If a private or secret key is
 *                          being copied outside of a secure element it must
 *                          also allow #IFX_SE_KEY_USAGE_EXPORT.
 * \param[in] attributes    The attributes for the new key.
 *                          They are used as follows:
 *                          - The key type and size may be 0. If either is
 *                            nonzero, it must match the corresponding
 *                            attribute of the source key.
 *                          - The key location (the lifetime and, for
 *                            persistent keys, the key identifier) is
 *                            used directly.
 *                          - The policy constraints (usage flags and
 *                            algorithm policy) are combined from
 *                            the source key and \p attributes so that
 *                            both sets of restrictions apply, as
 *                            described in the documentation of this function.
 * \param[out] target_key   On success, an identifier for the newly created key
 *                          (encoded pointer to
 *                          #ifx_se_key_id_fih_t variable).
 *                          For persistent keys, this is the key
 *                          identifier defined in \p attributes.
 *                          \c 0 on failure.
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 *         \p source_key is invalid.
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 *         This is an attempt to create a persistent key, and there is
 *         already a persistent key with the given identifier.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The lifetime or identifier in \p attributes are invalid, or
 *         the policy constraints on the source and specified in
 *         \p attributes are incompatible, or
 *         \p attributes specifies a key type or key size
 *         which does not match the attributes of the source key.
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The source key does not have the #IFX_SE_KEY_USAGE_COPY usage flag, or
 *         the source key is not exportable and its lifetime does not
 *         allow copying it to the target's lifetime.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_copy_key(
    ifx_se_key_id_fih_t source_key,
    const ifx_se_key_attributes_t *attributes,
    ifx_se_fih_ptr_t target_key,
    void *ctx);

/** \} */


/** \addtogroup key_derivation
 * \{
 */

/** Abort a key derivation operation.
 *
 * Aborting an operation frees all associated resources except for the \c
 * operation structure itself. Once aborted, the operation object can be reused
 * for another operation by calling ifx_se_key_derivation_setup() again.
 *
 * This function may be called at any time after the operation
 * object has been initialized as described in
 * #ifx_se_key_derivation_operation_t.
 *
 * In particular, it is valid to call ifx_se_key_derivation_abort() twice, or to
 * call ifx_se_key_derivation_abort() on an operation that has not been set up.
 *
 * \param[in,out] operation    The operation to abort.
 * \param[in] ctx              The pointer to the SE syscall context that
 *                             contain a special syscall data
 *                             (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_key_derivation_abort(
    ifx_se_key_derivation_operation_t *operation,
    void *ctx);

/** Set up a key derivation operation.
 *
 * A key derivation algorithm takes some inputs and uses them to generate
 * a byte stream in a deterministic way.
 * This byte stream can be used to produce keys and other
 * cryptographic material.
 *
 * To derive a key:
 * -# Start with an initialized object of type #ifx_se_key_derivation_operation_t.
 * -# Call ifx_se_key_derivation_setup() to select the algorithm.
 * -# Provide the inputs for the key derivation by calling
 *    ifx_se_key_derivation_input_bytes() or ifx_se_key_derivation_input_key()
 *    as appropriate. Which inputs are needed, in what order, and whether
 *    they may be keys and if so of what type depends on the algorithm.
 * -# Optionally set the operation's maximum capacity with
 *    ifx_se_key_derivation_set_capacity(). You may do this before, in the middle
 *    of or after providing inputs. For some algorithms, this step is mandatory
 *    because the output depends on the maximum capacity.
 * -# To derive a key, call ifx_se_key_derivation_output_key().
 *    To derive a byte string for a different purpose, call
 *    ifx_se_key_derivation_output_bytes().
 *    Successive calls to these functions use successive output bytes
 *    calculated by the key derivation algorithm.
 * -# Clean up the key derivation operation object with
 *    ifx_se_key_derivation_abort().
 *
 * If this function returns an error, the key derivation operation object is
 * not changed.
 *
 * If an error occurs at any step after a call to ifx_se_key_derivation_setup(),
 * the operation will need to be reset by a call to ifx_se_key_derivation_abort().
 *
 * Implementations must reject an attempt to derive a key of size 0.
 *
 * \param[in,out] operation       The key derivation operation object
 *                                to set up. It must
 *                                have been initialized but not set up yet.
 * \param[in] alg                 The key derivation algorithm to compute
 *                                (\c IFX_SE_ALG_XXX value such that
 *                                #IFX_SE_ALG_IS_KEY_DERIVATION(\p alg) is true).
 * \param[in] ctx                 The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \c alg is not a key derivation algorithm.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \c alg is not supported or is not a key derivation algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_key_derivation_setup(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Retrieve the current capacity of a key derivation operation.
 *
 * The capacity of a key derivation is the maximum number of bytes that it can
 * return. When you get *N* bytes of output from a key derivation operation,
 * this reduces its capacity by *N*.
 *
 * \param[in]  operation     The operation to query.
 * \param[out] capacity      On success, the capacity of the operation
 *                           (encoded pointer to size_t variable).
 * \param[in]  ctx           The pointer to the SE syscall context that
 *                           contain a special syscall data
 *                           (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_key_derivation_get_capacity(
    const ifx_se_key_derivation_operation_t *operation,
    ifx_se_fih_ptr_t capacity,
    void *ctx);

/** Set the maximum capacity of a key derivation operation.
 *
 * The capacity of a key derivation operation is the maximum number of bytes
 * that the key derivation operation can return from this point onwards.
 *
 * \param[in,out] operation  The key derivation operation object to modify.
 * \param[in] capacity       The new capacity of the operation.
 *                           It must be less or equal to the operation's
 *                           current capacity.
 * \param[in] ctx            The pointer to the SE syscall context that
 *                           contain a special syscall data
 *                           (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p capacity is larger than the operation's current capacity.
 *         In this case, the operation object remains valid and its capacity
 *         remains unchanged.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_key_derivation_set_capacity(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_fih_t capacity,
    void *ctx);

/** Provide an input for key derivation in the form of a key.
 *
 * Which inputs are required and in what order depends on the algorithm.
 * Refer to the documentation of each key derivation or key agreement
 * algorithm for information.
 *
 * This function obtains input from a key object, which is usually correct for
 * secret inputs or for non-secret personalization strings kept in the key
 * store. To pass a non-secret parameter which is not in the key store,
 * call ifx_se_key_derivation_input_bytes() instead of this function.
 * Refer to the documentation of individual step types
 * (`IFX_SE_KEY_DERIVATION_INPUT_xxx` values of type ::ifx_se_key_derivation_step_t)
 * for more information.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_key_derivation_abort().
 *
 * \param[in,out] operation       The key derivation operation object to use.
 *                                It must have been set up with
 *                                ifx_se_key_derivation_setup() and must not
 *                                have produced any output yet.
 * \param[in] step                Which step the input data is for.
 * \param[in] key                 Identifier of the key. It must have an
 *                                appropriate type for step and must allow the
 *                                usage #IFX_SE_KEY_USAGE_DERIVE or
 *                                #IFX_SE_KEY_USAGE_VERIFY_DERIVATION (see note)
 *                                and the algorithm used by the operation.
 * \param[in]  ctx                The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *
 * \note Once all inputs steps are completed, the operations will allow:
 * - ifx_se_key_derivation_output_bytes() if each input was either a direct input
 *   or  a key with #IFX_SE_KEY_USAGE_DERIVE set;
 * - ifx_se_key_derivation_output_key() if the input for step
 *   #IFX_SE_KEY_DERIVATION_INPUT_SECRET or #IFX_SE_KEY_DERIVATION_INPUT_PASSWORD
 *   was from a key slot with #IFX_SE_KEY_USAGE_DERIVE and each other input was
 *   either a direct input or a key with #IFX_SE_KEY_USAGE_DERIVE set;
 * - ifx_se_key_derivation_verify_bytes() if each input was either a direct input
 *   or  a key with #IFX_SE_KEY_USAGE_VERIFY_DERIVATION set;
 * - ifx_se_key_derivation_verify_key() under the same conditions as
 *   ifx_se_key_derivation_verify_bytes().
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key allows neither #IFX_SE_KEY_USAGE_DERIVE nor
 *         #IFX_SE_KEY_USAGE_VERIFY_DERIVATION, or it doesn't allow this
 *         algorithm.
 *         Also operation rejected with this response when HUK key is selected
 *         in SECURE life cycle and debug port is opened or enabled by policy.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \c step is not compatible with the operation's algorithm, or
 *         \c step does not allow key inputs of the given type
 *         or does not allow key inputs at all.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid for this input \p step.
 */
ifx_se_status_t ifx_se_key_derivation_input_key(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_key_derivation_step_t step,
    ifx_se_key_id_fih_t key,
    void *ctx);

/** Provide an input for key derivation or key agreement.
 *
 * Which inputs are required and in what order depends on the algorithm.
 * Refer to the documentation of each key derivation or key agreement
 * algorithm for information.
 *
 * This function passes direct inputs, which is usually correct for
 * non-secret inputs. To pass a secret input, which should be in a key
 * object, call ifx_se_key_derivation_input_key() instead of this function.
 * Refer to the documentation of individual step types
 * (`IFX_SE_KEY_DERIVATION_INPUT_xxx` values of type ::ifx_se_key_derivation_step_t)
 * for more information.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_key_derivation_abort().
 *
 * \param[in,out] operation       The key derivation operation object to use.
 *                                It must have been set up with
 *                                ifx_se_key_derivation_setup() and must not
 *                                have produced any output yet.
 * \param[in] step                Which step the input data is for.
 * \param[in] data                Input data to use
 *                                (encoded pointer to input data).
 * \param[in] data_length         Size of the \p data buffer in bytes (size_t).
 * \param[in] ctx                 The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \c step is not compatible with the operation's algorithm, or
 *         \c step does not allow direct inputs.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid for this input \p step.
 */
ifx_se_status_t ifx_se_key_derivation_input_bytes(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_key_derivation_step_t step,
    const ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_length,
    void *ctx);



/** Read some data from a key derivation operation.
 *
 * This function calculates output bytes from a key derivation algorithm and
 * return those bytes.
 * If you view the key derivation's output as a stream of bytes, this
 * function destructively reads the requested number of bytes from the
 * stream.
 * The operation's capacity decreases by the number of bytes read.
 *
 * If this function returns an error status other than
 * #IFX_SE_ERROR_INSUFFICIENT_DATA, the operation enters an error
 * state and must be aborted by calling ifx_se_key_derivation_abort().
 *
 * \param[in,out] operation    The key derivation operation object to read from.
 * \param[out] output          Buffer where the output will be written
 *                             (encoded pointer to output buffer).
 * \param[in]  output_length   Number of bytes to output.
 * \param[in]  ctx             The pointer to the SE syscall context that
 *                             contain a special syscall data
 *                             (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         One of the inputs was a key whose policy didn't allow
 *         #IFX_SE_KEY_USAGE_DERIVE.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_DATA
 *                          The operation's capacity was less than
 *                          \p output_length bytes. Note that in this case,
 *                          no output is written to the output buffer.
 *                          The operation's capacity is set to 0, thus
 *                          subsequent calls to this function will not
 *                          succeed, even with a smaller output buffer.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active and completed
 *         all required input steps).
 */
ifx_se_status_t ifx_se_key_derivation_output_bytes(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_length,
    void *ctx);

/** Derive a key from an ongoing key derivation operation.
 *
 * This function calculates output bytes from a key derivation algorithm
 * and uses those bytes to generate a key deterministically.
 * The key's location, usage policy, type and size are taken from
 * \p attributes.
 *
 * If you view the key derivation's output as a stream of bytes, this
 * function destructively reads as many bytes as required from the
 * stream.
 * The operation's capacity decreases by the number of bytes read.
 *
 * If this function returns an error status other than
 * #IFX_SE_ERROR_INSUFFICIENT_DATA, the operation enters an error
 * state and must be aborted by calling ifx_se_key_derivation_abort().
 *
 * How much output is produced and consumed from the operation, and how
 * the key is derived, depends on the key type and on the key size
 * (denoted \c bits below):
 *
 * - For key types for which the key is an arbitrary sequence of bytes
 *   of a given size, this function is functionally equivalent to
 *   calling #ifx_se_key_derivation_output_bytes
 *   and passing the resulting output to #ifx_se_import_key.
 *   However, this function has a security benefit:
 *   if the implementation provides an isolation boundary then
 *   the key material is not exposed outside the isolation boundary.
 *   As a consequence, for these key types, this function always consumes
 *   exactly (\c bits / 8) bytes from the operation.
 *   The following key types defined in this specification follow this scheme:
 *
 *     - #IFX_SE_KEY_TYPE_AES;
 *     - #IFX_SE_KEY_TYPE_ARIA;
 *     - #IFX_SE_KEY_TYPE_CAMELLIA;
 *     - #IFX_SE_KEY_TYPE_DERIVE;
 *     - #IFX_SE_KEY_TYPE_HMAC;
 *     - #IFX_SE_KEY_TYPE_PASSWORD_HASH.
 *
 * - For ECC keys on a Montgomery elliptic curve
 *   (#IFX_SE_KEY_TYPE_ECC_KEY_PAIR(\c curve) where \c curve designates a
 *   Montgomery curve), this function always draws a byte string whose
 *   length is determined by the curve, and sets the mandatory bits
 *   accordingly. That is:
 *
 *     - Curve25519 (#IFX_SE_ECC_FAMILY_MONTGOMERY, 255 bits): draw a 32-byte
 *       string and process it as specified in RFC 7748 &sect;5.
 *     - Curve448 (#IFX_SE_ECC_FAMILY_MONTGOMERY, 448 bits): draw a 56-byte
 *       string and process it as specified in RFC 7748 &sect;5.
 *
 * - For key types for which the key is represented by a single sequence of
 *   \c bits bits with constraints as to which bit sequences are acceptable,
 *   this function draws a byte string of length (\c bits / 8) bytes rounded
 *   up to the nearest whole number of bytes. If the resulting byte string
 *   is acceptable, it becomes the key, otherwise the drawn bytes are discarded.
 *   This process is repeated until an acceptable byte string is drawn.
 *   The byte string drawn from the operation is interpreted as specified
 *   for the output produced by ifx_se_export_key().
 *   The following key types defined in this specification follow this scheme:
 *
 *     - #IFX_SE_KEY_TYPE_DES.
 *       Force-set the parity bits, but discard forbidden weak keys.
 *       For 2-key and 3-key triple-DES, the three keys are generated
 *       successively (for example, for 3-key triple-DES,
 *       if the first 8 bytes specify a weak key and the next 8 bytes do not,
 *       discard the first 8 bytes, use the next 8 bytes as the first key,
 *       and continue reading output from the operation to derive the other
 *       two keys).
 *     - Finite-field Diffie-Hellman keys (#IFX_SE_KEY_TYPE_DH_KEY_PAIR(\c group)
 *       where \c group designates any Diffie-Hellman group) and
 *       ECC keys on a Weierstrass elliptic curve
 *       (#IFX_SE_KEY_TYPE_ECC_KEY_PAIR(\c curve) where \c curve designates a
 *       Weierstrass curve).
 *       For these key types, interpret the byte string as integer
 *       in big-endian order. Discard it if it is not in the range
 *       [0, *N* - 2] where *N* is the boundary of the private key domain
 *       (the prime *p* for Diffie-Hellman, the subprime *q* for DSA,
 *       or the order of the curve's base point for ECC).
 *       Add 1 to the resulting integer and use this as the private key *x*.
 *       This method allows compliance to NIST standards, specifically
 *       the methods titled "key-pair generation by testing candidates"
 *       in NIST SP 800-56A &sect;5.6.1.1.4 for Diffie-Hellman,
 *       in FIPS 186-4 &sect;B.1.2 for DSA, and
 *       in NIST SP 800-56A &sect;5.6.1.2.2 or
 *       FIPS 186-4 &sect;B.4.2 for elliptic curve keys.
 *
 * - For other key types, including #IFX_SE_KEY_TYPE_RSA_KEY_PAIR,
 *   the way in which the operation output is consumed is
 *   implementation-defined.
 *
 * In all cases, the data that is read is discarded from the operation.
 * The operation's capacity is decreased by the number of bytes read.
 *
 * For algorithms that take an input step #IFX_SE_KEY_DERIVATION_INPUT_SECRET,
 * the input to that step must be provided with ifx_se_key_derivation_input_key().
 * Future versions of this specification may include additional restrictions
 * on the derived key based on the attributes and strength of the secret key.
 *
 * \param[in] attributes    The attributes for the new key.
 *                          If the key type to be created is
 *                          #IFX_SE_KEY_TYPE_PASSWORD_HASH then the algorithm in
 *                          the policy must be the same as in the current
 *                          operation.
 * \param[in,out] operation The key derivation operation object to read from.
 * \param[out] key          On success, an identifier for the newly created key
 *                          (encoded pointer to #ifx_se_key_id_fih_t variable).
 *                          For persistent keys, this is the key
 *                          identifier defined in \p attributes.
 *                          \c 0 on failure.
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 *         If the key is persistent, the key material and the key's metadata
 *         have been saved to persistent storage.
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 *         This is an attempt to create a persistent key, and there is
 *         already a persistent key with the given identifier.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_DATA
 *         There was not enough data to create the desired key.
 *         Note that in this case, no output is written to the output buffer.
 *         The operation's capacity is set to 0, thus subsequent calls to
 *         this function will not succeed, even with a smaller output buffer.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         The key type or key size is not supported, either by the
 *         implementation in general or in this particular location.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The provided key attributes are not valid for the operation.
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The #IFX_SE_KEY_DERIVATION_INPUT_SECRET or
 *         #IFX_SE_KEY_DERIVATION_INPUT_PASSWORD input was not provided through a
 *         key; or one of the inputs was a key whose policy didn't allow
 *         #IFX_SE_KEY_USAGE_DERIVE.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active and completed
 *         all required input steps).
 */
ifx_se_status_t ifx_se_key_derivation_output_key(
    const ifx_se_key_attributes_t *attributes,
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_fih_ptr_t key,
    void *ctx);

/** Perform a key agreement and use the shared secret as input to a key
 * derivation.
 *
 * A key agreement algorithm takes two inputs: a private key \p private_key
 * a public key \p peer_key.
 * The result of this function is passed as input to a key derivation.
 * The output of this key derivation can be extracted by reading from the
 * resulting operation to produce keys and other cryptographic material.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_key_derivation_abort().
 *
 * \param[in,out] operation The key derivation operation object to use.
 *                          It must have been set up with
 *                          ifx_se_key_derivation_setup() with a
 *                          key agreement and derivation algorithm
 *                          \c alg (\c IFX_SE_ALG_XXX value such that
 *                          #IFX_SE_ALG_IS_KEY_AGREEMENT(\c alg) is true
 *                          and #IFX_SE_ALG_IS_RAW_KEY_AGREEMENT(\c alg)
 *                          is false).
 *                          The operation must be ready for an input
 *                          of the type given by \p step.
 * \param[in] step          Which step the input data is for.
 * \param[in] private_key   Identifier of the private key to use. It must
 *                          allow the usage #IFX_SE_KEY_USAGE_DERIVE.
 * \param[in] peer_key      Public key of the peer
 *                          (encoded pointer to input data).
 *                          The peer key must be in the
 *                          same format that ifx_se_import_key() accepts for the
 *                          public key type corresponding to the type of
 *                          private_key. That is, this function performs the
 *                          equivalent of
 *                          #ifx_se_import_key(...,
 *                          `peer_key`, `peer_key_length`) where
 *                          with key attributes indicating the public key
 *                          type corresponding to the type of `private_key`.
 *                          For example, for EC keys, this means that peer_key
 *                          is interpreted as a point on the curve that the
 *                          private key is on. The standard formats for public
 *                          keys are documented in the documentation of
 *                          ifx_se_export_public_key().
 * \param[in] peer_key_length Size of \p peer_key in bytes (size_t).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *                              
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \c private_key is not compatible with \c alg,
 *         or \p peer_key is not valid for \c alg or not compatible with
 *         \c private_key, or \c step does not allow an input resulting
 *         from a key agreement.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \c alg is not supported or is not a key derivation algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid for this key agreement \p step,
 *         or the library has not been previously initialized by ifx_se_crypto_init().
 *         It is implementation-dependent whether a failure to initialize
 *         results in this error code.
 */
ifx_se_status_t ifx_se_key_derivation_key_agreement(
    ifx_se_key_derivation_operation_t *operation,
    ifx_se_key_derivation_step_t step,
    ifx_se_key_id_fih_t private_key,
    const ifx_se_fih_ptr_t peer_key,
    ifx_se_fih_t peer_key_length,
    void *ctx);

/** Perform a key agreement and return the raw shared secret.
 *
 * \warning The raw result of a key agreement algorithm such as finite-field
 * Diffie-Hellman or elliptic curve Diffie-Hellman has biases and should
 * not be used directly as key material. It should instead be passed as
 * input to a key derivation algorithm. To chain a key agreement with
 * a key derivation, use ifx_se_key_derivation_key_agreement() and other
 * functions from the key derivation interface.
 *
 * \param alg                     The key agreement algorithm to compute
 *                                (\c IFX_SE_ALG_XXX value such that
 *                                #IFX_SE_ALG_IS_RAW_KEY_AGREEMENT(\p alg)
 *                                is true).
 * \param[in] private_key         Identifier of the private key to use. It must
 *                                allow the usage #IFX_SE_KEY_USAGE_DERIVE.
 * \param[in] peer_key            Public key of the peer
 *                                (encoded pointer to input data). It must be
 *                                in the same format that ifx_se_import_key()
 *                                accepts. The standard formats for public
 *                                keys are documented in the documentation
 *                                of ifx_se_export_public_key().
 * \param[in] peer_key_length     Size of \p peer_key in bytes (size_t).
 * \param[out] output             Buffer where the raw shared secret is to
 *                                be written (encoded pointer to output buffer).
 * \param[in] output_size         Size of the \c output buffer in bytes (size_t).
 * \param[out] output_length      On success, the number of bytes
 *                                that make up the returned output
 *                                (encoded pointer to size_t variable).
  * \param[in] ctx                The pointer to the SE syscall context that
 *                                contain a special syscall data
 *                                (IPC release callback etc).
 *                              
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p alg is not a key agreement algorithm, or
 *         \p private_key is not compatible with \p alg,
 *         or \p peer_key is not valid for \p alg or not compatible with
 *         \p private_key.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         \p output_size is too small
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not a supported key agreement algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The library has not been previously initialized by ifx_se_crypto_init().
 *         It is implementation-dependent whether a failure to initialize
 *         results in this error code.
 */
ifx_se_status_t ifx_se_raw_key_agreement(ifx_se_alg_fih_t alg,
                                    ifx_se_key_id_fih_t private_key,
                                    const ifx_se_fih_ptr_t peer_key,
                                    ifx_se_fih_t peer_key_length,
                                    ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_size,
                                    ifx_se_fih_ptr_t output_length,
                                    void *ctx);

/** \} */


/** \addtogroup mac_operations
 * \{
 */

/** Set up a multipart MAC calculation operation.
 *
 * This function sets up the calculation of the MAC
 * (message authentication code) of a byte string.
 * To verify the MAC of a message against an
 * expected value, use ifx_se_mac_verify_setup() instead.
 *
 * The sequence of operations to calculate a MAC is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_mac_operation_t, e.g. #IFX_SE_MAC_OPERATION_INIT.
 * -# Call ifx_se_mac_sign_setup() to specify the algorithm and key.
 * -# Call ifx_se_mac_update() zero, one or more times, passing a fragment
 *    of the message each time. The MAC that is calculated is the MAC
 *    of the concatenation of these messages in order.
 * -# At the end of the message, call ifx_se_mac_sign_finish() to finish
 *    calculating the MAC value and retrieve it.
 *
 * If an error occurs at any step after a call to ifx_se_mac_sign_setup(), the
 * operation will need to be reset by a call to ifx_se_mac_abort(). The
 * application may call ifx_se_mac_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_mac_sign_setup(), the application must
 * eventually terminate the operation through one of the following methods:
 * - A successful call to ifx_se_mac_sign_finish().
 * - A call to ifx_se_mac_abort().
 *
 * \param[in,out] operation The operation object to set up. It must have
 *                          been initialized as per the documentation for
 *                          #ifx_se_mac_operation_t and not yet in use.
 * \param[in] key           Identifier of the key to use for the operation. It
 *                          must remain valid until the operation terminates.
 *                          It must allow the usage IFX_SE_KEY_USAGE_SIGN_MESSAGE.
 * \param[in] alg           The MAC algorithm to compute (\c IFX_SE_ALG_XXX value
 *                          such that #IFX_SE_ALG_IS_MAC(\p alg) is true).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a MAC algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The key could not be retrieved from storage.
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_mac_sign_setup(
    ifx_se_mac_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Set up a multipart MAC verification operation.
 *
 * This function sets up the verification of the MAC
 * (message authentication code) of a byte string against an expected value.
 *
 * The sequence of operations to verify a MAC is as follows:
 * -# Allocate an operation object which will be passed to all the functions
 *    listed here.
 * -# Initialize the operation object with one of the methods described in the
 *    documentation for #ifx_se_mac_operation_t, e.g. #IFX_SE_MAC_OPERATION_INIT.
 * -# Call ifx_se_mac_verify_setup() to specify the algorithm and key.
 * -# Call ifx_se_mac_update() zero, one or more times, passing a fragment
 *    of the message each time. The MAC that is calculated is the MAC
 *    of the concatenation of these messages in order.
 * -# At the end of the message, call ifx_se_mac_verify_finish() to finish
 *    calculating the actual MAC of the message and verify it against
 *    the expected value.
 *
 * If an error occurs at any step after a call to ifx_se_mac_verify_setup(), the
 * operation will need to be reset by a call to ifx_se_mac_abort(). The
 * application may call ifx_se_mac_abort() at any time after the operation
 * has been initialized.
 *
 * After a successful call to ifx_se_mac_verify_setup(), the application must
 * eventually terminate the operation through one of the following methods:
 * - A successful call to ifx_se_mac_verify_finish().
 * - A call to ifx_se_mac_abort().
 *
 * \param[in,out] operation The operation object to set up. It must have
 *                          been initialized as per the documentation for
 *                          #ifx_se_mac_operation_t and not yet in use.
 * \param[in] key           Identifier of the key to use for the operation. It
 *                          must remain valid until the operation terminates.
 *                          It must allow the usage
 *                          IFX_SE_KEY_USAGE_VERIFY_MESSAGE.
 * \param[in] alg           The MAC algorithm to compute (\c IFX_SE_ALG_XXX value
 *                          such that #IFX_SE_ALG_IS_MAC(\p alg) is true).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \c key is not compatible with \c alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \c alg is not supported or is not a MAC algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The key could not be retrieved from storage.
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be inactive).
 */
ifx_se_status_t ifx_se_mac_verify_setup(
    ifx_se_mac_operation_t *operation,
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    void *ctx);

/** Add a message fragment to a multipart MAC operation.
 *
 * The application must call ifx_se_mac_sign_setup() or ifx_se_mac_verify_setup()
 * before calling this function.
 *
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_mac_abort().
 *
 * \param[in,out] operation   Active MAC operation.
 * \param[in] input           Buffer containing the message fragment to add to
 *                            the MAC calculation
 *                            (encoded pointer to input data).
 * \param[in] input_length    Size of the \p input buffer in bytes (size_t).
 * \param[in] ctx             The pointer to the SE syscall context that
 *                            contain a special syscall data
 *                            (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be active).
 */
ifx_se_status_t ifx_se_mac_update(
    ifx_se_mac_operation_t *operation,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    void *ctx);

/** Finish the calculation of the MAC of a message.
 *
 * The application must call ifx_se_mac_sign_setup() before calling this function.
 * This function calculates the MAC of the message formed by concatenating
 * the inputs passed to preceding calls to ifx_se_mac_update().
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_mac_abort().
 *
 * \warning Applications should not call this function if they expect
 *          a specific value for the MAC. Call ifx_se_mac_verify_finish() instead.
 *          Beware that comparing integrity or authenticity data such as
 *          MAC values with a function such as \c memcmp is risky
 *          because the time taken by the comparison may leak information
 *          about the MAC value which could allow an attacker to guess
 *          a valid MAC and thereby bypass security controls.
 *
 * \param[in,out] operation Active MAC operation.
 * \param[out] mac          Buffer where the MAC value is to be written
 *                          (encoded pointer to output buffer).
 * \param[in]  mac_size     Size of the \p mac buffer in bytes (size_t).
 * \param[out] mac_length   On success, the number of bytes
 *                          that make up the MAC value
 *                          (encoded pointer to size_t variable). This is always
 *                          #IFX_SE_MAC_LENGTH(\c key_type, \c key_bits, \c alg)
 *                          where \c key_type and \c key_bits are the type and
 *                          bit-size respectively of the key and \c alg is the
 *                          MAC algorithm that is calculated.
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p mac buffer is too small. You can determine a
 *         sufficient buffer size by calling IFX_SE_MAC_LENGTH().
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active mac sign
 *         operation).
 */
ifx_se_status_t ifx_se_mac_sign_finish(
    ifx_se_mac_operation_t *operation,
    ifx_se_fih_ptr_t mac,
    ifx_se_fih_t mac_size,
    ifx_se_fih_ptr_t mac_length,
    void *ctx);

/** Finish the calculation of the MAC of a message and compare it with
 * an expected value.
 *
 * The application must call ifx_se_mac_verify_setup() before calling this function.
 * This function calculates the MAC of the message formed by concatenating
 * the inputs passed to preceding calls to ifx_se_mac_update(). It then
 * compares the calculated MAC with the expected MAC passed as a
 * parameter to this function.
 *
 * When this function returns successfully, the operation becomes inactive.
 * If this function returns an error status, the operation enters an error
 * state and must be aborted by calling ifx_se_mac_abort().
 *
 * \note Implementations shall make the best effort to ensure that the
 * comparison between the actual MAC and the expected MAC is performed
 * in constant time.
 *
 * \param[in,out] operation    Active MAC operation.
 * \param[in] mac              Buffer containing the expected MAC value
 *                             (encoded pointer to input data).
 * \param[in] mac_length       Size of the \p mac buffer in bytes (size_t).
 * \param[in] ctx              The pointer to the SE syscall context that
 *                             contain a special syscall data
 *                             (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         The expected MAC is identical to the actual MAC of the message.
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The MAC of the message was calculated successfully, but it
 *         differs from the expected MAC.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The operation state is not valid (it must be an active mac verify
 *         operation).
 */
ifx_se_status_t ifx_se_mac_verify_finish(
    ifx_se_mac_operation_t *operation,
    const ifx_se_fih_ptr_t mac,
    ifx_se_fih_t mac_length,
    void *ctx);

/** Abort a MAC operation.
 *
 * Aborting an operation frees all associated resources except for the
 * \p operation structure itself. Once aborted, the operation object
 * can be reused for another operation by calling
 * ifx_se_mac_sign_setup() or ifx_se_mac_verify_setup() again.
 *
 * You may call this function any time after the operation object has
 * been initialized by one of the methods described in #ifx_se_mac_operation_t.
 *
 * In particular, calling ifx_se_mac_abort() after the operation has been
 * terminated by a call to ifx_se_mac_abort(), ifx_se_mac_sign_finish() or
 * ifx_se_mac_verify_finish() is safe and has no effect.
 *
 * \param[in,out] operation     Initialized MAC operation.
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 */
ifx_se_status_t ifx_se_mac_abort(
    ifx_se_mac_operation_t *operation,
    void *ctx);

/** Calculate the MAC (message authentication code) of a message.
 *
 * \note To verify the MAC of a message against an
 *       expected value, use ifx_se_mac_verify() instead.
 *       Beware that comparing integrity or authenticity data such as
 *       MAC values with a function such as \c memcmp is risky
 *       because the time taken by the comparison may leak information
 *       about the MAC value which could allow an attacker to guess
 *       a valid MAC and thereby bypass security controls.
 *
 * \param[in] key           Identifier of the key to use for the operation. It
 *                          must allow the usage IFX_SE_KEY_USAGE_SIGN_MESSAGE.
 * \param[in] alg           The MAC algorithm to compute (\c IFX_SE_ALG_XXX
 *                          value such that #IFX_SE_ALG_IS_MAC(\p alg) is true).
 * \param[in] input         Buffer containing the input message
 *                          (encoded pointer to input data).
 * \param[in] input_length  Size of the \p input buffer in bytes (size_t).
 * \param[out] mac          Buffer where the MAC value is to be written
 *                          (encoded pointer to output buffer).
 * \param[in]  mac_size     Size of the \p mac buffer in bytes (size_t).
 * \param[out] mac_length   On success, the number of bytes
 *                          that make up the MAC value
 *                          (encoded pointer to size_t variable).
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a MAC algorithm.
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         \p mac_size is too small
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The key could not be retrieved from storage.
 */
ifx_se_status_t ifx_se_mac_compute(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    ifx_se_fih_ptr_t mac,
    ifx_se_fih_t mac_size,
    ifx_se_fih_ptr_t mac_length,
    void *ctx);

/** Calculate the MAC of a message and compare it with a reference value.
 *
 * \param[in] key           Identifier of the key to use for the operation. It
 *                          must allow the usage IFX_SE_KEY_USAGE_VERIFY_MESSAGE.
 * \param[in] alg           The MAC algorithm to compute (\c IFX_SE_ALG_XXX
 *                          value such that #IFX_SE_ALG_IS_MAC(\p alg) is true).
 * \param[in] input         Buffer containing the input message
 *                          (encoded pointer to input data).
 * \param[in] input_length  Size of the \p input buffer in bytes (size_t).
 * \param[in] mac           Buffer containing the expected MAC value
 *                          (encoded pointer to input data).
 * \param[in] mac_length    Size of the \p mac buffer in bytes (size_t).
 * \param[in] ctx           The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 *         The expected MAC is identical to the actual MAC of the input.
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The MAC of the message was calculated successfully, but it
 *         differs from the expected value.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         \p key is not compatible with \p alg.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         \p alg is not supported or is not a MAC algorithm.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The key could not be retrieved from storage.
 */
ifx_se_status_t ifx_se_mac_verify(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t input,
    ifx_se_fih_t input_length,
    const ifx_se_fih_ptr_t mac,
    ifx_se_fih_t mac_length,
    void *ctx);

/** \} */

/** \addtogroup key_attributes
 * \{
 */

/** Reset a key attribute structure to a freshly initialized state.
 *
 * You must initialize the attribute structure as described in the
 * documentation of the type #ifx_se_key_attributes_t before calling this
 * function. Once the structure has been initialized, you may call this
 * function at any time.
 *
 * This function frees any auxiliary resources that the structure
 * may contain.
 *
 * \param[in,out] attributes    The attribute structure to reset.
 */
void ifx_se_reset_key_attributes( ifx_se_key_attributes_t *attributes );

/** Retrieve the attributes of a key.
 *
 * This function first resets the attribute structure as with
 * ifx_se_reset_key_attributes(). It then copies the attributes of
 * the given key into the given attribute structure.
 *
 * \note This function may allocate memory or other resources.
 *       Once you have called this function on an attribute structure,
 *       you must call ifx_se_reset_key_attributes() to free these resources.
 *
 * \param[in] key               Identifier of the key to query.
 * \param[in,out] attributes    On success, the attributes of the key.
 *                              On failure, equivalent to a
 *                              freshly-initialized structure.
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_BAD_STATE
 *         The library has not been previously initialized by ifx_se_crypto_init().
 *         It is implementation-dependent whether a failure to initialize
 *         results in this error code.
 */
ifx_se_status_t ifx_se_get_key_attributes(ifx_se_key_id_fih_t key,
                                          ifx_se_key_attributes_t *attributes,
                                          void *ctx);

/** \} */

/* BWC macros for obsoleted API, don't use it in the applications */
#define ifx_se_key_derivation_inp_key       ifx_se_key_derivation_input_key
#define ifx_se_key_derivation_inp_bytes     ifx_se_key_derivation_input_bytes
#define ifx_se_key_derivation_out_key       ifx_se_key_derivation_output_key
#define ifx_se_key_derivation_out_bytes     ifx_se_key_derivation_output_bytes

#ifdef __cplusplus
}
#endif

#endif /* IFX_SE_PSACRYPTO_H */
