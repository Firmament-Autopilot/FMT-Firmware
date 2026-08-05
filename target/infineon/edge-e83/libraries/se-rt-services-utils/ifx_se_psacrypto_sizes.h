/**
 * \file ifx_se_psacrypto_sizes.h
 * \version 1.2.0
 *
 * \brief PSA cryptography module: Mbed TLS buffer size macros
 *
 * \note This file may not be included directly. Applications must
 * include ifx_se_psacrypto.h.
 *
 * This file contains the definitions of macros that are useful to
 * compute buffer sizes. The signatures and semantics of these macros
 * are standardized, but the definitions are not, because they depend on
 * the available algorithms and, in some cases, on permitted tolerances
 * on buffer sizes.
 *
 * In implementations with isolation between the application and the
 * cryptography module, implementers should take care to ensure that
 * the definitions that are exposed to applications match what the
 * module implements.
 *
 * Macros that compute sizes whose values do not depend on the
 * implementation are in ifx_se_psacrypto.h.
 *
 *******************************************************************************
 * \copyright
 * Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
 * All rights reserved.
 * You may use this file only in accordance with the license, terms, conditions,
 * disclaimers, and limitations in the end user license agreement accompanying
 * the software package with which this file was provided.
 *******************************************************************************
*/

/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  (http)www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef IFX_SE_CRYPTO_SIZES_H
#define IFX_SE_CRYPTO_SIZES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define IFX_SE_BITS_TO_BYTES(bits) (((bits) + 7u) / 8u)
#define IFX_SE_BYTES_TO_BITS(bytes) ((bytes) * 8u)
#define IFX_SE_MAX_OF_THREE(a, b, c) ((a) <= (b) ? (b) <= (c) ? \
                                   (c) : (b) : (a) <= (c) ? (c) : (a))

#define IFX_SE_ROUND_UP_TO_MULTIPLE(block_size, length) \
    (((length) + (block_size) - 1) / (block_size) * (block_size))

/** \addtogroup constants_sizes
 * \{
 */

/** The size of the output of ifx_se_hash_finish(), in bytes.
 *
 * This is also the hash size that ifx_se_hash_verify() expects.
 *
 * \param alg   A hash algorithm (\c IFX_SE_ALG_XXX value such that
 *              #IFX_SE_ALG_IS_HASH(\p alg) is true), or an HMAC algorithm
 *              (#IFX_SE_ALG_HMAC(\c hash_alg) where \c hash_alg is a
 *              hash algorithm).
 *
 * \return The hash size for the specified hash algorithm.
 *         If the hash algorithm is not recognized, return 0.
 */
#define IFX_SE_HASH_LENGTH(alg)                                        \
    (                                                               \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_256 ? 32u :        \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_384 ? 48u :        \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512 ? 64u :        \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512_224 ? 28u :    \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512_256 ? 32u :    \
        0u)

/** The input block size of a hash algorithm, in bytes.
 *
 * Hash algorithms process their input data in blocks. Hash operations will
 * retain any partial blocks until they have enough input to fill the block or
 * until the operation is finished.
 * This affects the output from ifx_se_hash_suspend().
 *
 * \param alg   A hash algorithm (\c IFX_SE_ALG_XXX value such that
 *              IFX_SE_ALG_IS_HASH(\p alg) is true).
 *
 * \return      The block size in bytes for the specified hash algorithm.
 *              If the hash algorithm is not recognized, return 0.
 *              An implementation can return either 0 or the correct size for a
 *              hash algorithm that it recognizes, but does not support.
 */
#define IFX_SE_HASH_BLOCK_LENGTH(alg)                                  \
    (                                                               \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_256 ? 64u :        \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_384 ? 128u :       \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512 ? 128u :       \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512_224 ? 128u :   \
        IFX_SE_ALG_HMAC_GET_HASH(alg) == IFX_SE_ALG_SHA_512_256 ? 128u :   \
        0)

/** \def IFX_SE_HASH_MAX_SIZE
 *
 * Maximum size of a hash.
 *
 * This macro expands to a compile-time constant integer. This value
 * is the maximum size of a hash in bytes.
 */
/* Note: for HMAC-SHA-3, the block size is 144 bytes for HMAC-SHA3-226,
 * 136 bytes for HMAC-SHA3-256, 104 bytes for SHA3-384, 72 bytes for
 * HMAC-SHA3-512. */
#if defined(IFX_SE_WANT_ALG_SHA_512) || defined(IFX_SE_WANT_ALG_SHA_384)
#define IFX_SE_HASH_MAX_SIZE 64u
/** \cond INTERNAL */
#define IFX_SE_HMAC_MAX_HASH_BLOCK_SIZE 128u
/** \endcond */
#else
#define IFX_SE_HASH_MAX_SIZE 32u
/** \cond INTERNAL */
#define IFX_SE_HMAC_MAX_HASH_BLOCK_SIZE 64u
/** \endcond */
#endif

/** \def IFX_SE_MAC_MAX_SIZE
 *
 * Maximum size of a MAC.
 *
 * This macro expands to a compile-time constant integer. This value
 * is the maximum size of a MAC in bytes.
 */
/* All non-HMAC MACs have a maximum size that's smaller than the
 * minimum possible value of IFX_SE_HASH_MAX_SIZE in this implementation. */
/* Note that the encoding of truncated MAC algorithms limits this value
 * to 64 bytes.
 */
#define IFX_SE_MAC_MAX_SIZE IFX_SE_HASH_MAX_SIZE

/** The length of a tag for an AEAD algorithm, in bytes.
 *
 * This macro can be used to allocate a buffer of sufficient size to store the
 * tag output from ifx_se_aead_finish().
 *
 * See also #IFX_SE_AEAD_TAG_MAX_SIZE.
 *
 * \param key_type            The type of the AEAD key.
 * \param key_bits            The size of the AEAD key in bits.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 *
 * \return                    The tag length for the specified algorithm and key.
 *                            If the AEAD algorithm does not have an identified
 *                            tag that can be distinguished from the rest of
 *                            the ciphertext, return 0.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
#define IFX_SE_AEAD_TAG_LENGTH(key_type, key_bits, alg)                        \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 ?                            \
     IFX_SE_ALG_AEAD_GET_TAG_LENGTH(alg) :                                     \
     ((void) (key_bits), 0u))

/** The maximum tag size for all supported AEAD algorithms, in bytes.
 *
 * See also #IFX_SE_AEAD_TAG_LENGTH(\p key_type, \p key_bits, \p alg).
 */
#define IFX_SE_AEAD_TAG_MAX_SIZE       16u

/** The maximum size of an RSA key on this implementation, in bits.
 * This is a vendor-specific macro.
 *
 * Mbed TLS does not set a hard limit on the size of RSA keys: any key
 * whose parameters fit in a bignum is accepted. However large keys can
 * induce a large memory usage and long computation times. Unlike other
 * auxiliary macros in this file and in crypto.h, which reflect how the
 * library is configured, this macro defines how the library is
 * configured. This implementation refuses to import or generate an
 * RSA key whose size is larger than the value defined here.
 *
 * Note that an implementation may set different size limits for different
 * operations, and does not need to accept all key sizes up to the limit. */
#define IFX_SE_VENDOR_RSA_MAX_KEY_BITS 4096u

/** The maximum size of an ECC key on this implementation, in bits.
 * This is a vendor-specific macro. */
#define IFX_SE_VENDOR_ECC_MAX_CURVE_BITS 384u

/** This macro returns the maximum supported length of the PSK for the
 * TLS-1.2 PSK-to-MS key derivation
 * (#IFX_SE_ALG_TLS12_PSK_TO_MS(\c hash_alg)).
 *
 * The maximum supported length does not depend on the chosen hash algorithm.
 *
 * Quoting RFC 4279, Sect 5.3:
 * TLS implementations supporting these ciphersuites MUST support
 * arbitrary PSK identities up to 128 octets in length, and arbitrary
 * PSKs up to 64 octets in length.  Supporting longer identities and
 * keys is RECOMMENDED.
 *
 * Therefore, no implementation should define a value smaller than 64
 * for #IFX_SE_TLS12_PSK_TO_MS_PSK_MAX_SIZE.
 */
#define IFX_SE_TLS12_PSK_TO_MS_PSK_MAX_SIZE 128u

/** The maximum size of a block cipher. */
#define IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE 16u

/** The size of the output of ifx_se_mac_sign_finish(), in bytes.
 *
 * This is also the MAC size that ifx_se_mac_verify_finish() expects.
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type      The type of the MAC key.
 * \param key_bits      The size of the MAC key in bits.
 * \param alg           A MAC algorithm (\c IFX_SE_ALG_XXX value such that
 *                      #IFX_SE_ALG_IS_MAC(\p alg) is true).
 *
 * \return              The MAC size for the specified algorithm with
 *                      the specified key parameters.
 * \return              0 if the MAC algorithm is not recognized.
 * \return              Either 0 or the correct size for a MAC algorithm that
 *                      the implementation recognizes, but does not support.
 * \return              Unspecified if the key parameters are not consistent
 *                      with the algorithm.
 */
#define IFX_SE_MAC_LENGTH(key_type, key_bits, alg)                                   \
    ((alg) & IFX_SE_ALG_MAC_TRUNCATION_MASK ? IFX_SE_MAC_TRUNCATED_LENGTH(alg) :        \
     IFX_SE_ALG_IS_HMAC(alg) ? IFX_SE_HASH_LENGTH(IFX_SE_ALG_HMAC_GET_HASH(alg)) :         \
     IFX_SE_ALG_IS_BLOCK_CIPHER_MAC(alg) ? IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) : \
     ((void)(key_type), (void)(key_bits), 0u))

/** The maximum size of the output of ifx_se_aead_encrypt(), in bytes.
 *
 * If the size of the ciphertext buffer is at least this large, it is
 * guaranteed that ifx_se_aead_encrypt() will not fail due to an
 * insufficient buffer size. Depending on the algorithm, the actual size of
 * the ciphertext may be smaller.
 *
 * See also #IFX_SE_AEAD_ENCRYPT_OUTPUT_MAX_SIZE(\p plaintext_length).
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type            A symmetric key type that is
 *                            compatible with algorithm \p alg.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param plaintext_length    Size of the plaintext in bytes.
 *
 * \return                    The AEAD ciphertext size for the specified
 *                            algorithm.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
#define IFX_SE_AEAD_ENCRYPT_OUTPUT_SIZE(key_type, alg, plaintext_length) \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 ?                      \
     (plaintext_length) + IFX_SE_ALG_AEAD_GET_TAG_LENGTH(alg) :          \
     0u)

/** A sufficient output buffer size for ifx_se_aead_encrypt(), for any of the
 *  supported key types and AEAD algorithms.
 *
 * If the size of the ciphertext buffer is at least this large, it is guaranteed
 * that ifx_se_aead_encrypt() will not fail due to an insufficient buffer size.
 *
 * \note This macro returns a compile-time constant if its arguments are
 *       compile-time constants.
 *
 * See also #IFX_SE_AEAD_ENCRYPT_OUTPUT_SIZE(\p key_type, \p alg,
 * \p plaintext_length).
 *
 * \param plaintext_length    Size of the plaintext in bytes.
 *
 * \return                    A sufficient output buffer size for any of the
 *                            supported key types and AEAD algorithms.
 *
 */
#define IFX_SE_AEAD_ENCRYPT_OUTPUT_MAX_SIZE(plaintext_length)          \
    ((plaintext_length) + IFX_SE_AEAD_TAG_MAX_SIZE)


/** The maximum size of the output of ifx_se_aead_decrypt(), in bytes.
 *
 * If the size of the plaintext buffer is at least this large, it is
 * guaranteed that ifx_se_aead_decrypt() will not fail due to an
 * insufficient buffer size. Depending on the algorithm, the actual size of
 * the plaintext may be smaller.
 *
 * See also #IFX_SE_AEAD_DECRYPT_OUTPUT_MAX_SIZE(\p ciphertext_length).
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type            A symmetric key type that is
 *                            compatible with algorithm \p alg.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param ciphertext_length   Size of the plaintext in bytes.
 *
 * \return                    The AEAD ciphertext size for the specified
 *                            algorithm.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
#define IFX_SE_AEAD_DECRYPT_OUTPUT_SIZE(key_type, alg, ciphertext_length) \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 &&                      \
     (ciphertext_length) > IFX_SE_ALG_AEAD_GET_TAG_LENGTH(alg) ?      \
     (ciphertext_length) - IFX_SE_ALG_AEAD_GET_TAG_LENGTH(alg) :      \
     0u)

/** A sufficient output buffer size for ifx_se_aead_decrypt(), for any of the
 *  supported key types and AEAD algorithms.
 *
 * If the size of the plaintext buffer is at least this large, it is guaranteed
 * that ifx_se_aead_decrypt() will not fail due to an insufficient buffer size.
 *
 * \note This macro returns a compile-time constant if its arguments are
 *       compile-time constants.
 *
 * See also #IFX_SE_AEAD_DECRYPT_OUTPUT_SIZE(\p key_type, \p alg,
 * \p ciphertext_length).
 *
 * \param ciphertext_length   Size of the ciphertext in bytes.
 *
 * \return                    A sufficient output buffer size for any of the
 *                            supported key types and AEAD algorithms.
 *
 */
#define IFX_SE_AEAD_DECRYPT_OUTPUT_MAX_SIZE(ciphertext_length)     \
     (ciphertext_length)

/** The default nonce size for an AEAD algorithm, in bytes.
 *
 * This macro can be used to allocate a buffer of sufficient size to
 * store the nonce output from #ifx_se_aead_generate_nonce().
 *
 * See also #IFX_SE_AEAD_NONCE_MAX_SIZE.
 *
 * \note This is not the maximum size of nonce supported as input to
 *       #ifx_se_aead_set_nonce(), #ifx_se_aead_encrypt() or #ifx_se_aead_decrypt(),
 *       just the default size that is generated by #ifx_se_aead_generate_nonce().
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type  A symmetric key type that is compatible with
 *                  algorithm \p alg.
 *
 * \param alg       An AEAD algorithm (\c IFX_SE_ALG_XXX value such that
 *                  #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 *
 * \return The default nonce size for the specified key type and algorithm.
 *         If the key type or AEAD algorithm is not recognized,
 *         or the parameters are incompatible, return 0.
 */
#define IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) \
    (IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) == 16 ? \
     IFX_SE_ALG_AEAD_EQUAL(alg, IFX_SE_ALG_CCM) ? 13u : \
     IFX_SE_ALG_AEAD_EQUAL(alg, IFX_SE_ALG_GCM) ? 12u : \
     0u : \
     (key_type) == IFX_SE_KEY_TYPE_CHACHA20 && \
     IFX_SE_ALG_AEAD_EQUAL(alg, IFX_SE_ALG_CHACHA20_POLY1305) ? 12u : \
     0u)

/** The maximum default nonce size among all supported pairs of key types and
 *  AEAD algorithms, in bytes.
 *
 * This is equal to or greater than any value that #IFX_SE_AEAD_NONCE_LENGTH()
 * may return.
 *
 * \note This is not the maximum size of nonce supported as input to
 *       #ifx_se_aead_set_nonce(), #ifx_se_aead_encrypt() or #ifx_se_aead_decrypt(),
 *       just the largest size that may be generated by
 *       #ifx_se_aead_generate_nonce().
 */
#define IFX_SE_AEAD_NONCE_MAX_SIZE 13u

/** A sufficient output buffer size for ifx_se_aead_update().
 *
 * If the size of the output buffer is at least this large, it is
 * guaranteed that ifx_se_aead_update() will not fail due to an
 * insufficient buffer size. The actual size of the output may be smaller
 * in any given call.
 *
 * See also #IFX_SE_AEAD_UPDATE_OUTPUT_MAX_SIZE(\p input_length).
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type            A symmetric key type that is
 *                            compatible with algorithm \p alg.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 * \param input_length        Size of the input in bytes.
 *
 * \return                    A sufficient output buffer size for the specified
 *                            algorithm.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
/* For all the AEAD modes defined in this specification, it is possible
 * to emit output without delay. However, hardware may not always be
 * capable of this. So for modes based on a block cipher, allow the
 * implementation to delay the output until it has a full block. */
#define IFX_SE_AEAD_UPDATE_OUTPUT_SIZE(key_type, alg, input_length)                            \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 ?                                            \
     IFX_SE_ALG_IS_AEAD_ON_BLOCK_CIPHER(alg) ?                                                 \
     IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type), (input_length)) : \
     (input_length) : \
     0u)

/** A sufficient output buffer size for ifx_se_aead_update(), for any of the
 *  supported key types and AEAD algorithms.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_aead_update() will not fail due to an insufficient buffer size.
 *
 * See also #IFX_SE_AEAD_UPDATE_OUTPUT_SIZE(\p key_type, \p alg, \p input_length).
 *
 * \param input_length      Size of the input in bytes.
 */
#define IFX_SE_AEAD_UPDATE_OUTPUT_MAX_SIZE(input_length)                           \
    (IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE, (input_length)))

/** A sufficient ciphertext buffer size for ifx_se_aead_finish().
 *
 * If the size of the ciphertext buffer is at least this large, it is
 * guaranteed that ifx_se_aead_finish() will not fail due to an
 * insufficient ciphertext buffer size. The actual size of the output may
 * be smaller in any given call.
 *
 * See also #IFX_SE_AEAD_FINISH_OUTPUT_MAX_SIZE.
 *
 * \param key_type            A symmetric key type that is
                              compatible with algorithm \p alg.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 *
 * \return                    A sufficient ciphertext buffer size for the
 *                            specified algorithm.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
#define IFX_SE_AEAD_FINISH_OUTPUT_SIZE(key_type, alg) \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 &&  \
     IFX_SE_ALG_IS_AEAD_ON_BLOCK_CIPHER(alg) ?    \
     IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) : \
     0u)

/** A sufficient ciphertext buffer size for ifx_se_aead_finish(), for any of the
 *  supported key types and AEAD algorithms.
 *
 * See also #IFX_SE_AEAD_FINISH_OUTPUT_SIZE(\p key_type, \p alg).
 */
#define IFX_SE_AEAD_FINISH_OUTPUT_MAX_SIZE     (IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE)

/** A sufficient plaintext buffer size for ifx_se_aead_verify().
 *
 * If the size of the plaintext buffer is at least this large, it is
 * guaranteed that ifx_se_aead_verify() will not fail due to an
 * insufficient plaintext buffer size. The actual size of the output may
 * be smaller in any given call.
 *
 * See also #IFX_SE_AEAD_VERIFY_OUTPUT_MAX_SIZE.
 *
 * \param key_type            A symmetric key type that is
 *                            compatible with algorithm \p alg.
 * \param alg                 An AEAD algorithm
 *                            (\c IFX_SE_ALG_XXX value such that
 *                            #IFX_SE_ALG_IS_AEAD(\p alg) is true).
 *
 * \return                    A sufficient plaintext buffer size for the
 *                            specified algorithm.
 *                            If the key type or AEAD algorithm is not
 *                            recognized, or the parameters are incompatible,
 *                            return 0.
 */
#define IFX_SE_AEAD_VERIFY_OUTPUT_SIZE(key_type, alg) \
    (IFX_SE_AEAD_NONCE_LENGTH(key_type, alg) != 0 &&  \
     IFX_SE_ALG_IS_AEAD_ON_BLOCK_CIPHER(alg) ?    \
     IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) : \
     0u)

/** A sufficient plaintext buffer size for ifx_se_aead_verify(), for any of the
 *  supported key types and AEAD algorithms.
 *
 * See also #IFX_SE_AEAD_VERIFY_OUTPUT_SIZE(\p key_type, \p alg).
 */
#define IFX_SE_AEAD_VERIFY_OUTPUT_MAX_SIZE     (IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE)

/**
 * \brief ECDSA signature size for a given curve bit size
 *
 * \param curve_bits    Curve size in bits.
 * \return              Signature size in bytes.
 *
 * \note This macro returns a compile-time constant if its argument is one.
 */
#define IFX_SE_ECDSA_SIGNATURE_SIZE(curve_bits)    \
    (IFX_SE_BITS_TO_BYTES(curve_bits) * 2u)

/** Sufficient signature buffer size for ifx_se_sign_hash().
 *
 * This macro returns a sufficient buffer size for a signature using a key
 * of the specified type and size, with the specified algorithm.
 * Note that the actual size of the signature may be smaller
 * (some algorithms produce a variable-size signature).
 *
 * \warning This function may call its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type  An asymmetric key type (this may indifferently be a
 *                  key pair type or a public key type).
 * \param key_bits  The size of the key in bits.
 * \param alg       The signature algorithm.
 *
 * \return If the parameters are valid and supported, return
 *         a buffer size in bytes that guarantees that
 *         ifx_se_sign_hash() will not fail with
 *         #IFX_SE_ERROR_BUFFER_TOO_SMALL.
 *         If the parameters are a valid combination that is not supported,
 *         return either a sensible size or 0.
 *         If the parameters are not valid, the
 *         return value is unspecified.
 */
#define IFX_SE_SIGN_OUTPUT_SIZE(key_type, key_bits, alg)        \
     (IFX_SE_KEY_TYPE_IS_ECC(key_type) ? IFX_SE_ECDSA_SIGNATURE_SIZE(key_bits) : \
     ((void)alg, 0u))

/** \cond INTERNAL */
#define IFX_SE_VENDOR_ECDSA_SIGNATURE_MAX_SIZE     \
    IFX_SE_ECDSA_SIGNATURE_SIZE(IFX_SE_VENDOR_ECC_MAX_CURVE_BITS)
/** \endcond */

/** \def IFX_SE_SIGNATURE_MAX_SIZE
 *
 * Maximum size of an asymmetric signature.
 *
 * This macro expands to a compile-time constant integer. This value
 * is the maximum size of a signature in bytes.
 */
#define IFX_SE_SIGNATURE_MAX_SIZE      1

#if (IFX_SE_VENDOR_ECDSA_SIGNATURE_MAX_SIZE > IFX_SE_SIGNATURE_MAX_SIZE)
#undef IFX_SE_SIGNATURE_MAX_SIZE
#define IFX_SE_SIGNATURE_MAX_SIZE      IFX_SE_VENDOR_ECDSA_SIGNATURE_MAX_SIZE
#endif
#if (IFX_SE_BITS_TO_BYTES(IFX_SE_VENDOR_RSA_MAX_KEY_BITS) > IFX_SE_SIGNATURE_MAX_SIZE)
#undef IFX_SE_SIGNATURE_MAX_SIZE
#define IFX_SE_SIGNATURE_MAX_SIZE      IFX_SE_BITS_TO_BYTES(IFX_SE_VENDOR_RSA_MAX_KEY_BITS)
#endif

/** Maximum size of the export encoding of an ECC public key.
 *
 * The representation of an ECC public key is:
 *      - The byte 0x04;
 *      - `x_P` as a `ceiling(m/8)`-byte string, big-endian;
 *      - `y_P` as a `ceiling(m/8)`-byte string, big-endian;
 *      - where m is the bit size associated with the curve.
 *
 * -> 1 byte + 2 * point size.
 */
#define IFX_SE_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(key_bits)        \
    (2u * IFX_SE_BITS_TO_BYTES(key_bits) + 1u)

/** Maximum size of the export encoding of an ECC key pair.
 *
 * An ECC key pair is represented by the secret value.
 */
#define IFX_SE_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(key_bits)   \
    (IFX_SE_BITS_TO_BYTES(key_bits))

/** Sufficient output buffer size for ifx_se_export_key() or
 * ifx_se_export_public_key().
 *
 * This macro returns a compile-time constant if its arguments are
 * compile-time constants.
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * The following code illustrates how to allocate enough memory to export
 * a key by querying the key type and size at runtime.
 * \code{c}
 * ifx_se_key_attributes_t attributes = IFX_SE_KEY_ATTRIBUTES_INIT;
 * ifx_se_status_t status;
 * status = ifx_se_get_key_attributes(key, &attributes);
 * if (status != IFX_SE_SUCCESS) handle_error(...);
 * ifx_se_key_type_t key_type = ifx_se_get_key_type(&attributes);
 * size_t key_bits = ifx_se_get_key_bits(&attributes);
 * size_t buffer_size = IFX_SE_EXPORT_KEY_OUTPUT_SIZE(key_type, key_bits);
 * ifx_se_reset_key_attributes(&attributes);
 * uint8_t *buffer = malloc(buffer_size);
 * if (buffer == NULL) handle_error(...);
 * size_t buffer_length;
 * status = ifx_se_export_key(key, buffer, buffer_size, &buffer_length);
 * if (status != IFX_SE_SUCCESS) handle_error(...);
 * \endcode
 *
 * \param key_type  A supported key type.
 * \param key_bits  The size of the key in bits.
 *
 * \return If the parameters are valid and supported, return
 *         a buffer size in bytes that guarantees that
 *         ifx_se_export_key() or ifx_se_export_public_key() will not fail with
 *         #IFX_SE_ERROR_BUFFER_TOO_SMALL.
 *         If the parameters are a valid combination that is not supported,
 *         return either a sensible size or 0.
 *         If the parameters are not valid, the return value is unspecified.
 */
#define IFX_SE_EXPORT_KEY_OUTPUT_SIZE(key_type, key_bits)                                              \
    (IFX_SE_KEY_TYPE_IS_UNSTRUCTURED(key_type) ? IFX_SE_BITS_TO_BYTES(key_bits) :                         \
     IFX_SE_KEY_TYPE_IS_ECC_KEY_PAIR(key_type) ? IFX_SE_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(key_bits) :      \
     IFX_SE_KEY_TYPE_IS_ECC_PUBLIC_KEY(key_type) ? IFX_SE_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(key_bits) :  \
     0u)

/** Sufficient output buffer size for ifx_se_export_public_key().
 *
 * This macro returns a compile-time constant if its arguments are
 * compile-time constants.
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * The following code illustrates how to allocate enough memory to export
 * a public key by querying the key type and size at runtime.
 * \code{c}
 * ifx_se_key_attributes_t attributes = IFX_SE_KEY_ATTRIBUTES_INIT;
 * ifx_se_status_t status;
 * status = ifx_se_get_key_attributes(key, &attributes);
 * if (status != IFX_SE_SUCCESS) handle_error(...);
 * ifx_se_key_type_t key_type = ifx_se_get_key_type(&attributes);
 * size_t key_bits = ifx_se_get_key_bits(&attributes);
 * size_t buffer_size = IFX_SE_EXPORT_PUBLIC_KEY_OUTPUT_SIZE(key_type, key_bits);
 * ifx_se_reset_key_attributes(&attributes);
 * uint8_t *buffer = malloc(buffer_size);
 * if (buffer == NULL) handle_error(...);
 * size_t buffer_length;
 * status = ifx_se_export_public_key(key, buffer, buffer_size, &buffer_length);
 * if (status != IFX_SE_SUCCESS) handle_error(...);
 * \endcode
 *
 * \param key_type      A public key or key pair key type.
 * \param key_bits      The size of the key in bits.
 *
 * \return              If the parameters are valid and supported, return
 *                      a buffer size in bytes that guarantees that
 *                      ifx_se_export_public_key() will not fail with
 *                      #IFX_SE_ERROR_BUFFER_TOO_SMALL.
 *                      If the parameters are a valid combination that is not
 *                      supported, return either a sensible size or 0.
 *                      If the parameters are not valid,
 *                      the return value is unspecified.
 *
 *                      If the parameters are valid and supported,
 *                      return the same result as
 *                      #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(
 *                          \p #IFX_SE_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR(\p key_type),
 *                          \p key_bits).
 */
#define IFX_SE_EXPORT_PUBLIC_KEY_OUTPUT_SIZE(key_type, key_bits)                           \
     (IFX_SE_KEY_TYPE_IS_ECC(key_type) ? IFX_SE_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(key_bits) : \
     0u)

/** Sufficient buffer size for exporting any asymmetric key pair.
 *
 * This macro expands to a compile-time constant integer. This value is
 * a sufficient buffer size when calling ifx_se_export_key() to export any
 * asymmetric key pair, regardless of the exact key type and key size.
 *
 * See also #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(\p key_type, \p key_bits).
 */
#define IFX_SE_EXPORT_KEY_PAIR_MAX_SIZE                                            \
     IFX_SE_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(IFX_SE_VENDOR_ECC_MAX_CURVE_BITS)

/** Sufficient buffer size for exporting any asymmetric public key.
 *
 * This macro expands to a compile-time constant integer. This value is
 * a sufficient buffer size when calling ifx_se_export_key() or
 * ifx_se_export_public_key() to export any asymmetric public key,
 * regardless of the exact key type and key size.
 *
 * See also #IFX_SE_EXPORT_PUBLIC_KEY_OUTPUT_SIZE(\p key_type, \p key_bits).
 */
#define IFX_SE_EXPORT_PUBLIC_KEY_MAX_SIZE                                          \
     IFX_SE_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(IFX_SE_VENDOR_ECC_MAX_CURVE_BITS)

/** Sufficient output buffer size for ifx_se_raw_key_agreement().
 *
 * This macro returns a compile-time constant if its arguments are
 * compile-time constants.
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * See also #IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_MAX_SIZE.
 *
 * \param key_type      A supported key type.
 * \param key_bits      The size of the key in bits.
 *
 * \return              If the parameters are valid and supported, return
 *                      a buffer size in bytes that guarantees that
 *                      ifx_se_raw_key_agreement() will not fail with
 *                      #IFX_SE_ERROR_BUFFER_TOO_SMALL.
 *                      If the parameters are a valid combination that
 *                      is not supported, return either a sensible size or 0.
 *                      If the parameters are not valid,
 *                      the return value is unspecified.
 */
/* FFDH is not yet supported in PSA. */
#define IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_SIZE(key_type, key_bits)   \
    (IFX_SE_KEY_TYPE_IS_ECC_KEY_PAIR(key_type) ?                   \
     IFX_SE_BITS_TO_BYTES(key_bits) :                              \
     0u)

/** Maximum size of the output from ifx_se_raw_key_agreement().
 *
 * This macro expands to a compile-time constant integer. This value is the
 * maximum size of the output any raw key agreement algorithm, in bytes.
 *
 * See also #IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_SIZE(\p key_type, \p key_bits).
 */
#define IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_MAX_SIZE       1

#if (IFX_SE_BITS_TO_BYTES(IFX_SE_VENDOR_ECC_MAX_CURVE_BITS) > IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_MAX_SIZE)
#undef IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_MAX_SIZE
#define IFX_SE_RAW_KEY_AGREEMENT_OUTPUT_MAX_SIZE    IFX_SE_BITS_TO_BYTES(IFX_SE_VENDOR_ECC_MAX_CURVE_BITS)
#endif

/** The default IV size for a cipher algorithm, in bytes.
 *
 * The IV that is generated as part of a call to #ifx_se_cipher_encrypt() is always
 * the default IV length for the algorithm.
 *
 * This macro can be used to allocate a buffer of sufficient size to
 * store the IV output from #ifx_se_cipher_generate_iv() when using
 * a multi-part cipher operation.
 *
 * See also #IFX_SE_CIPHER_IV_MAX_SIZE.
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type  A symmetric key type that is compatible with algorithm \p alg.
 *
 * \param alg       A cipher algorithm (\c IFX_SE_ALG_XXX value such that #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 *
 * \return The default IV size for the specified key type and algorithm.
 *         If the algorithm does not use an IV, return 0.
 *         If the key type or cipher algorithm is not recognized,
 *         or the parameters are incompatible, return 0.
 */
#define IFX_SE_CIPHER_IV_LENGTH(key_type, alg) \
    (IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) > 1 && \
        ((alg) == IFX_SE_ALG_CTR || \
         (alg) == IFX_SE_ALG_CBC_NO_PADDING || \
         (alg) == IFX_SE_ALG_CBC_PKCS7) ? IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) : \
         0u)

/** The maximum IV size for all supported cipher algorithms, in bytes.
 *
 * See also #IFX_SE_CIPHER_IV_LENGTH().
 */
#define IFX_SE_CIPHER_IV_MAX_SIZE 16u

/** The maximum size of the output of ifx_se_cipher_encrypt(), in bytes.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_encrypt() will not fail due to an insufficient buffer size.
 * Depending on the algorithm, the actual size of the output might be smaller.
 *
 * See also #IFX_SE_CIPHER_ENCRYPT_OUTPUT_MAX_SIZE(\p input_length).
 *
 * \warning This macro may evaluate its arguments multiple times or
 *          zero times, so you should not pass arguments that contain
 *          side effects.
 *
 * \param key_type      A symmetric key type that is compatible with algorithm
 *                      alg.
 * \param alg           A cipher algorithm (\c IFX_SE_ALG_XXX value such that
 *                      #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param input_length  Size of the input in bytes.
 *
 * \return              A sufficient output size for the specified key type and
 *                      algorithm. If the key type or cipher algorithm is not
 *                      recognized, or the parameters are incompatible,
 *                      return 0.
 */
#define IFX_SE_CIPHER_ENCRYPT_OUTPUT_SIZE(key_type, alg, input_length)             \
    (alg == IFX_SE_ALG_CBC_PKCS7 ?                                                 \
     (IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) != 0 ?                            \
     IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type),          \
                              (input_length) + 1u) +                             \
     IFX_SE_CIPHER_IV_LENGTH((key_type), (alg)) : 0u) :                             \
     (IFX_SE_ALG_IS_CIPHER(alg) ?                                                  \
      (input_length) + IFX_SE_CIPHER_IV_LENGTH((key_type), (alg)) :                \
     0u))

/** A sufficient output buffer size for ifx_se_cipher_encrypt(), for any of the
 *  supported key types and cipher algorithms.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_encrypt() will not fail due to an insufficient buffer size.
 *
 * See also #IFX_SE_CIPHER_ENCRYPT_OUTPUT_SIZE(\p key_type, \p alg, \p input_length).
 *
 * \param input_length  Size of the input in bytes.
 *
 */
#define IFX_SE_CIPHER_ENCRYPT_OUTPUT_MAX_SIZE(input_length)                        \
    (IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE,                  \
                              (input_length) + 1u) +                             \
     IFX_SE_CIPHER_IV_MAX_SIZE)

/** The maximum size of the output of ifx_se_cipher_decrypt(), in bytes.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_decrypt() will not fail due to an insufficient buffer size.
 * Depending on the algorithm, the actual size of the output might be smaller.
 *
 * See also #IFX_SE_CIPHER_DECRYPT_OUTPUT_MAX_SIZE(\p input_length).
 *
 * \param key_type      A symmetric key type that is compatible with algorithm
 *                      alg.
 * \param alg           A cipher algorithm (\c IFX_SE_ALG_XXX value such that
 *                      #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param input_length  Size of the input in bytes.
 *
 * \return              A sufficient output size for the specified key type and
 *                      algorithm. If the key type or cipher algorithm is not
 *                      recognized, or the parameters are incompatible,
 *                      return 0.
 */
#define IFX_SE_CIPHER_DECRYPT_OUTPUT_SIZE(key_type, alg, input_length)                 \
    (IFX_SE_ALG_IS_CIPHER(alg) &&                                                      \
     ((key_type) & IFX_SE_KEY_TYPE_CATEGORY_MASK) == IFX_SE_KEY_TYPE_CATEGORY_SYMMETRIC ? \
     (input_length) :                                                               \
     0u)

/** A sufficient output buffer size for ifx_se_cipher_decrypt(), for any of the
 *  supported key types and cipher algorithms.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_decrypt() will not fail due to an insufficient buffer size.
 *
 * See also #IFX_SE_CIPHER_DECRYPT_OUTPUT_SIZE(\p key_type, \p alg, \p input_length).
 *
 * \param input_length  Size of the input in bytes.
 */
#define IFX_SE_CIPHER_DECRYPT_OUTPUT_MAX_SIZE(input_length)    \
    (input_length)

/** A sufficient output buffer size for ifx_se_cipher_update().
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_update() will not fail due to an insufficient buffer size.
 * The actual size of the output might be smaller in any given call.
 *
 * See also #IFX_SE_CIPHER_UPDATE_OUTPUT_MAX_SIZE(\p input_length).
 *
 * \param key_type      A symmetric key type that is compatible with algorithm
 *                      alg.
 * \param alg           A cipher algorithm (IFX_SE_ALG_XXX value such that
 *                      #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \param input_length  Size of the input in bytes.
 *
 * \return              A sufficient output size for the specified key type and
 *                      algorithm. If the key type or cipher algorithm is not
 *                      recognized, or the parameters are incompatible, return 0.
 */
#define IFX_SE_CIPHER_UPDATE_OUTPUT_SIZE(key_type, alg, input_length)              \
    (IFX_SE_ALG_IS_CIPHER(alg) ?                                                   \
    (IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) != 0 ?                             \
     (((alg) == IFX_SE_ALG_CBC_PKCS7      ||                                       \
       (alg) == IFX_SE_ALG_CBC_NO_PADDING ||                                       \
       (alg) == IFX_SE_ALG_ECB_NO_PADDING) ?                                       \
      IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type),         \
                                input_length) :                                 \
      (input_length)) : 0u) :                                                    \
     0u)

/** A sufficient output buffer size for ifx_se_cipher_update(), for any of the
 *  supported key types and cipher algorithms.
 *
 * If the size of the output buffer is at least this large, it is guaranteed
 * that ifx_se_cipher_update() will not fail due to an insufficient buffer size.
 *
 * See also #IFX_SE_CIPHER_UPDATE_OUTPUT_SIZE(\p key_type, \p alg, \p input_length).
 *
 * \param input_length  Size of the input in bytes.
 */
#define IFX_SE_CIPHER_UPDATE_OUTPUT_MAX_SIZE(input_length)     \
    (IFX_SE_ROUND_UP_TO_MULTIPLE(IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE, input_length))

/** A sufficient ciphertext buffer size for ifx_se_cipher_finish().
 *
 * If the size of the ciphertext buffer is at least this large, it is
 * guaranteed that ifx_se_cipher_finish() will not fail due to an insufficient
 * ciphertext buffer size. The actual size of the output might be smaller in
 * any given call.
 *
 * See also #IFX_SE_CIPHER_FINISH_OUTPUT_MAX_SIZE().
 *
 * \param key_type      A symmetric key type that is compatible with algorithm
 *                      alg.
 * \param alg           A cipher algorithm (IFX_SE_ALG_XXX value such that
 *                      #IFX_SE_ALG_IS_CIPHER(\p alg) is true).
 * \return              A sufficient output size for the specified key type and
 *                      algorithm. If the key type or cipher algorithm is not
 *                      recognized, or the parameters are incompatible, return 0.
 */
#define IFX_SE_CIPHER_FINISH_OUTPUT_SIZE(key_type, alg)    \
    (IFX_SE_ALG_IS_CIPHER(alg) ?                           \
     (alg == IFX_SE_ALG_CBC_PKCS7 ?                        \
      IFX_SE_BLOCK_CIPHER_BLOCK_LENGTH(key_type) :         \
      0u) :                                              \
     0u)

/** A sufficient ciphertext buffer size for ifx_se_cipher_finish(), for any of the
 *  supported key types and cipher algorithms.
 *
 * See also #IFX_SE_CIPHER_FINISH_OUTPUT_SIZE(\p key_type, \p alg).
 */
#define IFX_SE_CIPHER_FINISH_OUTPUT_MAX_SIZE           \
    (IFX_SE_BLOCK_CIPHER_BLOCK_MAX_SIZE)

/** \} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_CRYPTO_SIZES_H */
