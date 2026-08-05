/***************************************************************************//**
*
* \file ifx_se_psacrypto.c
* \version 1.2.0
*
* \brief
*  This is the source code file for Secure Services psa crypto syscalls.
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ifx_se_psacrypto.h"
#include "ifx_se_syscall.h"
#include "ifx_se_memory.h"

#include "cy_device.h"
#include "cy_utils.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 38, \
    'The "operation" context changes inside SE RT Services.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 59, \
    'Intentional typecast of "ipc_packet[]" to "ifx_se_fih_uint *" type.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 103, \
    'Intentional typecast of "ipc_packet" to an integer type.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 221, \
    'Use function-like macro as simple inline functions.')

ifx_se_status_t ifx_se_sign_hash(
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    const ifx_se_fih_ptr_t hash,
                                    ifx_se_fih_t hash_length,
                                    const ifx_se_fih_ptr_t signature,
                                    ifx_se_fih_t signature_size,
                                    ifx_se_fih_ptr_t signature_length,
                                    void *ctx)
 {
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 8 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(8u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_SIGN_HASH;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[5] = hash_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(signature);
    ipc_params[7] = signature_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(signature_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
 }

ifx_se_status_t ifx_se_verify_hash(
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    const ifx_se_fih_ptr_t hash,
                                    ifx_se_fih_t hash_length,
                                    const ifx_se_fih_ptr_t signature,
                                    ifx_se_fih_t signature_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 7 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(7u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_VERIFY_HASH;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[5] = hash_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(signature);
    ipc_params[7] = signature_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_sign_message(ifx_se_key_id_fih_t key,
                               ifx_se_alg_fih_t alg,
                               const ifx_se_fih_ptr_t input,
                               ifx_se_fih_t input_length,
                               ifx_se_fih_ptr_t signature,
                               ifx_se_fih_t signature_size,
                               ifx_se_fih_ptr_t signature_length,
                               void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 8 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(8u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_SIGN_MESSAGE;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[5] = input_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(signature);
    ipc_params[7] = signature_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(signature_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_verify_message(ifx_se_key_id_fih_t key,
                                 ifx_se_alg_fih_t alg,
                                 const ifx_se_fih_ptr_t input,
                                 ifx_se_fih_t input_length,
                                 const ifx_se_fih_ptr_t signature,
                                 ifx_se_fih_t signature_length,
                                 void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 7 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(7u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_VERIFY_MESSAGE;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[5] = input_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(signature);
    ipc_params[7] = signature_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

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
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 12 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(12u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_ENCRYPT;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(nonce);
    ipc_params[5] = nonce_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(additional_data);
    ipc_params[7] = additional_data_length;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(plaintext);
    ipc_params[9] = plaintext_length;
    ipc_params[10] = ifx_se_fih_ptr_to_uint(ciphertext);
    ipc_params[11] = ciphertext_size;
    ipc_params[12] = ifx_se_fih_ptr_to_uint(ciphertext_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

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
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 12 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(12u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_DECRYPT;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(nonce);
    ipc_params[5] = nonce_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(additional_data);
    ipc_params[7] = additional_data_length;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(ciphertext);
    ipc_params[9] = ciphertext_length;
    ipc_params[10] = ifx_se_fih_ptr_to_uint(plaintext);
    ipc_params[11] = plaintext_size;
    ipc_params[12] = ifx_se_fih_ptr_to_uint(plaintext_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_encrypt_setup(ifx_se_aead_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_ENCRYPT_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_decrypt_setup(ifx_se_aead_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_DECRYPT_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_generate_nonce(ifx_se_aead_operation_t *operation,
                                     ifx_se_fih_ptr_t nonce,
                                     ifx_se_fih_t nonce_size,
                                     ifx_se_fih_ptr_t nonce_length,
                                     void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_GENERATE_NONCE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(nonce);
    ipc_params[3] = nonce_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(nonce_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_set_nonce(ifx_se_aead_operation_t *operation,
                                const ifx_se_fih_ptr_t nonce,
                                ifx_se_fih_t nonce_length,
                                void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_SET_NONCE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(nonce);
    ipc_params[3] = nonce_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_set_lengths(ifx_se_aead_operation_t *operation,
                                  ifx_se_fih_t ad_length,
                                  ifx_se_fih_t plaintext_length,
                                  void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_SET_LENGTHS;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ad_length;
    ipc_params[3] = plaintext_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_update_ad(ifx_se_aead_operation_t *operation,
                                const ifx_se_fih_ptr_t input,
                                ifx_se_fih_t input_length,
                                void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_UPDATE_AD;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_update(ifx_se_aead_operation_t *operation,
                             const ifx_se_fih_ptr_t input,
                             ifx_se_fih_t input_length,
                             ifx_se_fih_ptr_t output,
                             ifx_se_fih_t output_size,
                             ifx_se_fih_ptr_t output_length,
                             void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 6 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(6u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_UPDATE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[5] = output_size;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_finish(ifx_se_aead_operation_t *operation,
                             ifx_se_fih_ptr_t ciphertext,
                             ifx_se_fih_t ciphertext_size,
                             ifx_se_fih_ptr_t ciphertext_length,
                             ifx_se_fih_ptr_t tag,
                             ifx_se_fih_t tag_size,
                             ifx_se_fih_ptr_t tag_length,
                             void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 7 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(7u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_FINISH;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(ciphertext);
    ipc_params[3] = ciphertext_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(ciphertext_length);
    ipc_params[5] = ifx_se_fih_ptr_to_uint(tag);
    ipc_params[6] = tag_size;
    ipc_params[7] = ifx_se_fih_ptr_to_uint(tag_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_verify(ifx_se_aead_operation_t *operation,
                             ifx_se_fih_ptr_t plaintext,
                             ifx_se_fih_t plaintext_size,
                             ifx_se_fih_ptr_t plaintext_length,
                             const ifx_se_fih_ptr_t tag,
                             ifx_se_fih_t tag_length,
                             void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 6 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(6u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_VERIFY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(plaintext);
    ipc_params[3] = plaintext_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(plaintext_length);
    ipc_params[5] = ifx_se_fih_ptr_to_uint(tag);
    ipc_params[6] = tag_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_aead_abort(ifx_se_aead_operation_t *operation, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_AEAD_ABORT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

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
                                void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 10 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(10u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_ENCRYPT;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(iv);
    ipc_params[5] = iv_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[7] = input_length;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[9] = output_size;
    ipc_params[10] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_decrypt(ifx_se_key_id_fih_t key,
                                ifx_se_alg_fih_t alg,
                                const ifx_se_fih_ptr_t input,
                                ifx_se_fih_t input_length,
                                ifx_se_fih_ptr_t output,
                                ifx_se_fih_t output_size,
                                ifx_se_fih_ptr_t output_length,
                                void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 8 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(8u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_DECRYPT;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[5] = input_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[7] = output_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_encrypt_setup(
                                    ifx_se_cipher_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_ENCRYPT_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_decrypt_setup(
                                    ifx_se_cipher_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_DECRYPT_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_finish(
                                    ifx_se_cipher_operation_t *operation,
                                    ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_size,
                                    ifx_se_fih_ptr_t output_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_FINISH;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[3] = output_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_generate_iv(
                                    ifx_se_cipher_operation_t *operation,
                                    ifx_se_fih_ptr_t iv,
                                    ifx_se_fih_t iv_size,
                                    ifx_se_fih_ptr_t iv_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_GENERATE_IV;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(iv);
    ipc_params[3] = iv_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(iv_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_set_iv(
                                    ifx_se_cipher_operation_t *operation,
                                    const ifx_se_fih_ptr_t iv,
                                    ifx_se_fih_t iv_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_SET_IV;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(iv);
    ipc_params[3] = iv_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_update(
                                    ifx_se_cipher_operation_t *operation,
                                    const ifx_se_fih_ptr_t input,
                                    ifx_se_fih_t input_length,
                                    ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_size,
                                    ifx_se_fih_ptr_t output_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 6 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(6u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_UPDATE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[5] = output_size;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_cipher_abort(ifx_se_cipher_operation_t *operation, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_CIPHER_ABORT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_destroy_key(ifx_se_key_id_fih_t key, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_DESTROY_KEY;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}


ifx_se_status_t ifx_se_purge_key(ifx_se_key_id_fih_t key, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameter */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_PURGE_KEY;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_generate_key(const ifx_se_key_attributes_t *attributes,
                                    ifx_se_fih_ptr_t key,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_GENERATE_KEY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(attributes));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(key);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_generate_random(ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_size,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_GET_RANDOM;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[2] = output_size;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_abort(
                                    ifx_se_key_derivation_operation_t *operation,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_ABORT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_setup(
                                    ifx_se_hash_operation_t *operation,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_update(
                                    ifx_se_hash_operation_t *operation,
                                    const ifx_se_fih_ptr_t input,
                                    ifx_se_fih_t input_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_UPDATE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_finish(
                                    ifx_se_hash_operation_t *operation,
                                    ifx_se_fih_ptr_t hash,
                                    ifx_se_fih_t hash_size,
                                    ifx_se_fih_ptr_t hash_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_FINISH;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[3] = hash_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(hash_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_verify(
                                    ifx_se_hash_operation_t *operation,
                                    const ifx_se_fih_ptr_t hash,
                                    ifx_se_fih_t hash_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (3 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_VERIFY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[3] = hash_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_abort(ifx_se_hash_operation_t *operation, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_ABORT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_compute(ifx_se_alg_fih_t alg,
                              const ifx_se_fih_ptr_t input,
                              ifx_se_fih_t input_length,
                              ifx_se_fih_ptr_t hash,
                              ifx_se_fih_t hash_size,
                              ifx_se_fih_ptr_t hash_length,
                              void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 6 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(6u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_COMPUTE;
    ipc_params[1] = alg;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[5] = hash_size;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(hash_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_hash_clone(const ifx_se_hash_operation_t *source_operation,
                            ifx_se_hash_operation_t *target_operation,
                            void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_HASH_CLONE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(source_operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(target_operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_import_key(
                                    const ifx_se_key_attributes_t *attributes,
                                    const ifx_se_fih_ptr_t data,
                                    ifx_se_fih_t data_length,
                                    ifx_se_fih_ptr_t key,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_IMPORT_KEY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(attributes));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(data);
    ipc_params[3] = data_length;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(key);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_export_key(
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_fih_ptr_t data,
                                    ifx_se_fih_t data_size,
                                    ifx_se_fih_ptr_t data_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 5 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(5u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_EXPORT_KEY;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = ifx_se_fih_ptr_to_uint(data);
    ipc_params[4] = data_size;
    ipc_params[5] = ifx_se_fih_ptr_to_uint(data_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_export_public_key(
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_fih_ptr_t data,
                                    ifx_se_fih_t data_size,
                                    ifx_se_fih_ptr_t data_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 5 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(5u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_EXPORT_PUBLIC_KEY;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = ifx_se_fih_ptr_to_uint(data);
    ipc_params[4] = data_size;
    ipc_params[5] = ifx_se_fih_ptr_to_uint(data_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_copy_key(ifx_se_key_id_fih_t source_key,
                          const ifx_se_key_attributes_t *attributes,
                          ifx_se_fih_ptr_t target_key,
                          void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_COPY_KEY;
    ipc_params[1] = source_key.key_id;
    ipc_params[2] = source_key.owner;
    ipc_params[3] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(attributes));
    ipc_params[4] = ifx_se_fih_ptr_to_uint(target_key);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_output_key(
                                    const ifx_se_key_attributes_t *attributes,
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_fih_ptr_t key,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_OUTPUT_KEY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(attributes));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[3] = ifx_se_fih_ptr_to_uint(key);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_input_key(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_key_derivation_step_t step,
                                    ifx_se_key_id_fih_t key,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_INPUT_KEY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_uint_encode(step);
    ipc_params[3] = key.key_id;
    ipc_params[4] = key.owner;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_input_bytes(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_key_derivation_step_t step,
                                    const ifx_se_fih_ptr_t data,
                                    ifx_se_fih_t data_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_INPUT_BYTES;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_uint_encode(step);
    ipc_params[3] = ifx_se_fih_ptr_to_uint(data);
    ipc_params[4] = data_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_output_bytes(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_OUTPUT_BYTES;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[3] = output_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}


ifx_se_status_t ifx_se_key_derivation_setup(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_get_capacity(
                                    const ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_fih_ptr_t capacity,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_GET_CAPACITY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(capacity);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_set_capacity(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_fih_t capacity,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_SET_CAPACITY;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = capacity;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_key_derivation_key_agreement(
                                    ifx_se_key_derivation_operation_t *operation,
                                    ifx_se_key_derivation_step_t step,
                                    ifx_se_key_id_fih_t private_key,
                                    const ifx_se_fih_ptr_t peer_key,
                                    ifx_se_fih_t peer_key_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 6 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(6u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_KEY_DERIVATION_AGREEMENT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_uint_encode(step);
    ipc_params[3] = private_key.key_id;
    ipc_params[4] = private_key.owner;
    ipc_params[5] = ifx_se_fih_ptr_to_uint(peer_key);
    ipc_params[6] = peer_key_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_raw_key_agreement(ifx_se_alg_fih_t alg,
                                    ifx_se_key_id_fih_t private_key,
                                    const ifx_se_fih_ptr_t peer_key,
                                    ifx_se_fih_t peer_key_length,
                                    ifx_se_fih_ptr_t output,
                                    ifx_se_fih_t output_size,
                                    ifx_se_fih_ptr_t output_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 8 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(8u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_RAW_KEY_AGREEMENT;
    ipc_params[1] = alg;
    ipc_params[2] = private_key.key_id;
    ipc_params[3] = private_key.owner;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(peer_key);
    ipc_params[5] = peer_key_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(output);
    ipc_params[7] = output_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(output_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_compute(ifx_se_key_id_fih_t key,
                             ifx_se_alg_fih_t alg,
                             const ifx_se_fih_ptr_t input,
                             ifx_se_fih_t input_length,
                             ifx_se_fih_ptr_t mac,
                             ifx_se_fih_t mac_size,
                             ifx_se_fih_ptr_t mac_length,
                             void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 8 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(8u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_COMPUTE;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[5] = input_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(mac);
    ipc_params[7] = mac_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(mac_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_verify(ifx_se_key_id_fih_t key,
                            ifx_se_alg_fih_t alg,
                            const ifx_se_fih_ptr_t input,
                            ifx_se_fih_t input_length,
                            const ifx_se_fih_ptr_t mac,
                            ifx_se_fih_t mac_length,
                            void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 7 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(7u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_VERIFY;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = alg;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[5] = input_length;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(mac);
    ipc_params[7] = mac_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_sign_setup(
                                    ifx_se_mac_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_SIGN_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_verify_setup(
                                    ifx_se_mac_operation_t *operation,
                                    ifx_se_key_id_fih_t key,
                                    ifx_se_alg_fih_t alg,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_VERIFY_SETUP;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = key.key_id;
    ipc_params[3] = key.owner;
    ipc_params[4] = alg;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_update(
                                    ifx_se_mac_operation_t *operation,
                                    const ifx_se_fih_ptr_t input,
                                    ifx_se_fih_t input_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_UPDATE;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(input);
    ipc_params[3] = input_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_sign_finish(
                                    ifx_se_mac_operation_t *operation,
                                    ifx_se_fih_ptr_t mac,
                                    ifx_se_fih_t mac_size,
                                    ifx_se_fih_ptr_t mac_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_SIGN_FINISH;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(mac);
    ipc_params[3] = mac_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(mac_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_verify_finish(
                                    ifx_se_mac_operation_t *operation,
                                    const ifx_se_fih_ptr_t mac,
                                    ifx_se_fih_t mac_length,
                                    void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_VERIFY_FINISH;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));
    ipc_params[2] = ifx_se_fih_ptr_to_uint(mac);
    ipc_params[3] = mac_length;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mac_abort(ifx_se_mac_operation_t *operation, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_MAC_ABORT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(operation));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

void ifx_se_reset_key_attributes( ifx_se_key_attributes_t *attributes )
{
    (void)memset( attributes, 0, sizeof( *attributes ) );
}

ifx_se_status_t ifx_se_get_key_attributes(ifx_se_key_id_fih_t key,
                                          ifx_se_key_attributes_t *attributes,
                                          void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PSA_GET_KEY_ATTRIBUTES;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(attributes));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4')
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')
