/**
 * \file ifx_se_psacrypto_types.h
 * \version 1.2.0
 *
 * \brief PSA cryptography module: type aliases.
 *
 * \note This file may not be included directly. Applications must
 * include ifx_se_psacrypto.h.
 *
 * This file contains portable definitions of integral types for properties
 * of cryptographic keys, designations of cryptographic algorithms, and
 * error codes returned by the library.
 *
 * This header file does not declare any function.
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

#ifndef IFX_SE_PSACRYPTO_TYPES_H
#define IFX_SE_PSACRYPTO_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \addtogroup cipher_operations
 * \{
 */

/** The type of the state data structure for multipart cipher operations.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation. */
typedef struct ifx_se_cipher_operation_s ifx_se_cipher_operation_t;

/** \} */

/** \addtogroup hash_operations
 * \{
 */

/** The type of the state data structure for multipart hash operations.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation. */
typedef struct ifx_se_hash_operation_s ifx_se_hash_operation_t;

/** \} */

/** \addtogroup mac_operations
 * \{
 */

/** The type of the state data structure for multipart MAC operations.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation. */
typedef struct ifx_se_mac_operation_s ifx_se_mac_operation_t;

/** \} */

/** \addtogroup key_derivation
 * \{
 */

/** The type of the state data structure for key derivation operations.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation.
 */
typedef struct ifx_se_key_derivation_s ifx_se_key_derivation_operation_t;

/** \} */

/** \addtogroup aead_operations
 * \{
 */

/** The type of the state data structure for multipart AEAD operations.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation.
 */
typedef struct ifx_se_aead_operation_s ifx_se_aead_operation_t;

/** \} */

/** \addtogroup fih
 * @{
 */

/** Special algorithm FIH type definition for SE RT Services transport */
typedef ifx_se_fih_uint ifx_se_alg_fih_t;

/** \} */

/** \addtogroup crypto_types
 * @{
 */

/** \brief Encoding of a key type.
 */
typedef uint16_t ifx_se_key_type_t;

/** The type of PSA elliptic curve family identifiers.
 *
 * The curve identifier is required to create an ECC key using the
 * IFX_SE_KEY_TYPE_ECC_KEY_PAIR() or IFX_SE_KEY_TYPE_ECC_PUBLIC_KEY()
 * macros.
 *
 * Values defined by this standard will never be in the range 0x80-0xff.
 * Vendors who define additional families must use an encoding in this range.
 */
typedef uint8_t ifx_se_ecc_family_t;

/** The type of PSA Diffie-Hellman group family identifiers.
 *
 * The group identifier is required to create an Diffie-Hellman key using the
 * IFX_SE_KEY_TYPE_DH_KEY_PAIR() or IFX_SE_KEY_TYPE_DH_PUBLIC_KEY()
 * macros.
 *
 * Values defined by this standard will never be in the range 0x80-0xff.
 * Vendors who define additional families must use an encoding in this range.
 */
typedef uint8_t ifx_se_dh_family_t;

/**@}*/

/** \addtogroup crypto_algs
 * @{
 */

/** \brief Encoding of a cryptographic algorithm.
 *
 * For algorithms that can be applied to multiple key types, this type
 * does not encode the key type. For example, for symmetric ciphers
 * based on a block cipher, #ifx_se_algorithm_t encodes the block cipher
 * mode and the padding mode while the block cipher itself is encoded
 * via #ifx_se_key_type_t.
 */
typedef uint32_t ifx_se_algorithm_t;

/**@}*/

/** \addtogroup key_lifetimes Key lifetimes
 * @{
 */

/** Encoding of key lifetimes.
 *
 * The lifetime of a key indicates where it is stored and what system actions
 * may create and destroy it.
 *
 * Lifetime values have the following structure:
 * - Bits 0-7 (#IFX_SE_KEY_LIFETIME_GET_PERSISTENCE(\c lifetime)):
 *   persistence level. This value indicates what device management
 *   actions can cause it to be destroyed. In particular, it indicates
 *   whether the key is _volatile_ or _persistent_.
 *   See ::ifx_se_key_persistence_t for more information.
 * - Bits 8-31 (#IFX_SE_KEY_LIFETIME_GET_LOCATION(\c lifetime)):
 *   location indicator. This value indicates which part of the system
 *   has access to the key material and can perform operations using the key.
 *   See ::ifx_se_key_location_t for more information.
 *
 * Volatile keys are automatically destroyed when the application instance
 * terminates or on a power reset of the device. Persistent keys are
 * preserved until the application explicitly destroys them or until an
 * integration-specific device management event occurs (for example,
 * a factory reset).
 *
 * Persistent keys have a key identifier of type #ifx_se_svc_key_id_t.
 * This identifier remains valid throughout the lifetime of the key,
 * even if the application instance that created the key terminates.
 * The application can call ifx_se_open_key() to open a persistent key that
 * it created previously.
 *
 * The default lifetime of a key is #IFX_SE_KEY_LIFETIME_VOLATILE. The lifetime
 * #IFX_SE_KEY_LIFETIME_PERSISTENT is supported if persistent storage is
 * available. Other lifetime values may be supported depending on the
 * library configuration.
 */
typedef uint32_t ifx_se_key_lifetime_t;

/** Encoding of key persistence levels.
 *
 * What distinguishes different persistence levels is what device management
 * events may cause keys to be destroyed. _Volatile_ keys are destroyed
 * by a power reset. Persistent keys may be destroyed by events such as
 * a transfer of ownership or a factory reset. What management events
 * actually affect persistent keys at different levels is outside the
 * scope of the PSA Cryptography specification.
 *
 * The PSA Cryptography specification defines the following values of
 * persistence levels:
 * - \c 0 = #IFX_SE_KEY_PERSISTENCE_VOLATILE: volatile key.
 *   A volatile key is automatically destroyed by the implementation when
 *   the application instance terminates. In particular, a volatile key
 *   is automatically destroyed on a power reset of the device.
 * - \c 1 = #IFX_SE_KEY_PERSISTENCE_DEFAULT:
 *   persistent key with a default lifetime.
 * - \c 2-254: currently not supported by Mbed TLS.
 * - \c 255 = #IFX_SE_KEY_PERSISTENCE_READ_ONLY:
 *   read-only or write-once key.
 *   A key with this persistence level cannot be destroyed.
 *   Mbed TLS does not currently offer a way to create such keys, but
 *   integrations of Mbed TLS can use it for built-in keys that the
 *   application cannot modify (for example, a hardware unique key (HUK)).
 *
 * \note Key persistence levels are 8-bit values. Key management
 *       interfaces operate on lifetimes (type ::ifx_se_key_lifetime_t) which
 *       encode the persistence as the lower 8 bits of a 32-bit value.
 */
typedef uint8_t ifx_se_key_persistence_t;

/** Encoding of key location indicators.
 *
 * If an integration of Mbed TLS can make calls to external
 * cryptoprocessors such as secure elements, the location of a key
 * indicates which secure element performs the operations on the key.
 * Depending on the design of the secure element, the key
 * material may be stored either in the secure element, or
 * in wrapped (encrypted) form alongside the key metadata in the
 * primary local storage.
 *
 * The PSA Cryptography API specification defines the following values of
 * location indicators:
 * - \c 0: primary local storage.
 *   This location is always available.
 *   The primary local storage is typically the same storage area that
 *   contains the key metadata.
 * - \c 1: primary secure element.
 *   Integrations of Mbed TLS should support this value if there is a secure
 *   element attached to the operating environment.
 *   As a guideline, secure elements may provide higher resistance against
 *   side channel and physical attacks than the primary local storage, but may
 *   have restrictions on supported key types, sizes, policies and operations
 *   and may have different performance characteristics.
 * - \c 2-0x7fffff: other locations defined by a PSA specification.
 *   The PSA Cryptography API does not currently assign any meaning to these
 *   locations, but future versions of that specification or other PSA
 *   specifications may do so.
 * - \c 0x800000-0xffffff: vendor-defined locations.
 *   No PSA specification will assign a meaning to locations in this range.
 *
 * \note Key location indicators are 24-bit values. Key management
 *       interfaces operate on lifetimes (type ::ifx_se_key_lifetime_t) which
 *       encode the location as the upper 24 bits of a 32-bit value.
 */
typedef uint32_t ifx_se_key_location_t;

/**@}*/

/** \addtogroup key_attributes
 * @{
 */

/** Encoding of identifiers of persistent keys.
 *
 * - Applications may freely choose key identifiers in the range
 *   #IFX_SE_KEY_ID_USER_MIN to #IFX_SE_KEY_ID_USER_MAX.
 * - The implementation may define additional key identifiers in the range
 *   #IFX_SE_KEY_ID_VENDOR_MIN to #IFX_SE_KEY_ID_VENDOR_MAX.
 * - 0 is reserved as an invalid key identifier.
 * - Key identifiers outside these ranges are reserved for future use.
 */
typedef uint32_t ifx_se_key_id_t;

/** Building for the PSA Crypto service on a PSA platform, a key owner is a PSA
 * partition identifier.
 */
typedef int32_t ifx_se_key_owner_id_t;

/** Encoding of key identifiers as seen inside the PSA Crypto implementation.
 *
 * When PSA Crypto is built as a library inside an application, this type
 * is identical to #ifx_se_key_id_t. When PSA Crypto is built as a service
 * that can store keys on behalf of multiple clients, this type
 * encodes the #ifx_se_key_id_t value seen by each client application as
 * well as extra information that identifies the client that owns
 * the key.
 *
 * \note Values of this type are encoded in the persistent key store.
 *       Any changes to existing values will require bumping the storage
 *       format version and providing a translation when reading the old
 *       format.
 */

/* Implementation-specific: The Mbed TLS library can be built as
 * part of a multi-client service that exposes the PSA Cryptography API in each
 * client and encodes the client identity in the key identifier argument of
 * functions such as ifx_se_open_key().
 */

/** Encoding of identifiers of persistent keys. */
typedef struct {
    ifx_se_key_id_t key_id; /*!< Key ID in persistent key storage */
    ifx_se_key_owner_id_t owner; /*!< Encoded owner of a key with this ID */
} ifx_se_svc_key_id_t;

/** The type of the of keys identifier transfer data.
 *
 * This is an implementation-defined \c struct. Applications should not
 * make any assumptions about the content of this structure except
 * as directed by the documentation of a specific implementation.
 *
 * Members:
 * - ifx_se_fih_uint **key_id** - ID of a key
 * - ifx_se_fih_uint **owner** - Key owner
 */
typedef struct ifx_se_key_id_fih_s ifx_se_key_id_fih_t;

/**@}*/

/** \addtogroup key_policy
 * @{
 */

/** \brief Encoding of permitted usage on a key. */
typedef uint32_t ifx_se_key_usage_t;

/**@}*/

/** \addtogroup key_attributes
 * @{
 */

/** The type of a structure containing key attributes.
 *
 * Members:
 *
 * - #ifx_se_key_type_t **type** - Defines key type
 * - #ifx_se_key_bits_t **bits** - Defines size of a key in bits
 * - #ifx_se_key_lifetime_t **lifetime** - Defines type of storage (persistent or volatile storage)
 * - #ifx_se_key_policy_t **policy** - Defines usage policy (algorithms, etc)
 * - #ifx_se_svc_key_id_t **id** - Defined ID for persistent keys
 *
 * This is an opaque structure that can represent the metadata of a key
 * object. Metadata that can be stored in attributes includes:
 * - The location of the key in storage, indicated by its key identifier
 *   and its lifetime.
 * - The key's policy, comprising usage flags and a specification of
 *   the permitted algorithm(s).
 * - Information about the key itself: the key type and its size.
 * - Additional implementation-defined attributes.
 *
 * The actual key material is not considered an attribute of a key.
 * Key attributes do not contain information that is generally considered
 * highly confidential.
 *
 * An attribute structure works like a simple data structure where each function
 * `ifx_se_set_key_xxx` sets a field and the corresponding function
 * `ifx_se_get_key_xxx` retrieves the value of the corresponding field.
 * However, a future version of the library  may report values that are
 * equivalent to the original one, but have a different encoding. Invalid
 * values may be mapped to different, also invalid values.
 *
 * An attribute structure may contain references to auxiliary resources,
 * for example pointers to allocated memory or indirect references to
 * pre-calculated values. In order to free such resources, the application
 * must call ifx_se_reset_key_attributes(). As an exception, calling
 * ifx_se_reset_key_attributes() on an attribute structure is optional if
 * the structure has only been modified by the following functions
 * since it was initialized or last reset with ifx_se_reset_key_attributes():
 * - ifx_se_set_key_id()
 * - ifx_se_set_key_lifetime()
 * - ifx_se_set_key_type()
 * - ifx_se_set_key_bits()
 * - ifx_se_set_key_usage_flags()
 * - ifx_se_set_key_algorithm()
 *
 * Before calling any function on a key attribute structure, the application
 * must initialize it by any of the following means:
 * - Set the structure to all-bits-zero, for example:
 *   \code
 *   ifx_se_key_attributes_t attributes;
 *   memset(&attributes, 0, sizeof(attributes));
 *   \endcode
 * - Initialize the structure to logical zero values, for example:
 *   \code
 *   ifx_se_key_attributes_t attributes = {0};
 *   \endcode
 * - Initialize the structure to the initializer #IFX_SE_KEY_ATTRIBUTES_INIT,
 *   for example:
 *   \code
 *   ifx_se_key_attributes_t attributes = IFX_SE_KEY_ATTRIBUTES_INIT;
 *   \endcode
 * - Assign the result of the function ifx_se_key_attributes_init()
 *   to the structure, for example:
 *   \code
 *   ifx_se_key_attributes_t attributes;
 *   attributes = ifx_se_key_attributes_init();
 *   \endcode
 *
 * A freshly initialized attribute structure contains the following
 * values:
 *
 * - lifetime: #IFX_SE_KEY_LIFETIME_VOLATILE.
 * - key identifier: 0 (which is not a valid key identifier).
 * - type: \c 0 (meaning that the type is unspecified).
 * - key size: \c 0 (meaning that the size is unspecified).
 * - usage flags: \c 0 (which allows no usage except exporting a public key).
 * - algorithm: \c 0 (which allows no cryptographic usage, but allows
 *   exporting).
 *
 * A typical sequence to create a key is as follows:
 * -# Create and initialize an attribute structure.
 * -# If the key is persistent, call ifx_se_set_key_id().
 *    Also call ifx_se_set_key_lifetime() to place the key in a non-default
 *    location.
 * -# Set the key policy with ifx_se_set_key_usage_flags() and
 *    ifx_se_set_key_algorithm().
 * -# Set the key type with ifx_se_set_key_type().
 *    Skip this step if copying an existing key with ifx_se_copy_key().
 * -# When generating a random key with ifx_se_generate_key() or deriving a key
 *    with ifx_se_key_derivation_output_key(), set the desired key size with
 *    ifx_se_set_key_bits().
 * -# Call a key creation function: ifx_se_import_key(), ifx_se_generate_key(),
 *    ifx_se_key_derivation_output_key() or ifx_se_copy_key(). This function reads
 *    the attribute structure, creates a key with these attributes, and
 *    outputs a key identifier to the newly created key.
 * -# The attribute structure is now no longer necessary.
 *    You may call ifx_se_reset_key_attributes(), although this is optional
 *    with the workflow presented here because the attributes currently
 *    defined in this specification do not require any additional resources
 *    beyond the structure itself.
 *
 * A typical sequence to query a key's attributes is as follows:
 * -# Call ifx_se_get_key_attributes().
 * -# Call `ifx_se_get_key_xxx` functions to retrieve the attribute(s) that
 *    you are interested in.
 * -# Call ifx_se_reset_key_attributes() to free any resources that may be
 *    used by the attribute structure.
 *
 * Once a key has been created, it is impossible to change its attributes.
 */
typedef struct ifx_se_key_attributes_s ifx_se_key_attributes_t;


/**@}*/

/** \addtogroup key_derivation Key derivation
 * @{
 */

/** \brief Encoding of the step of a key derivation. */
typedef uint16_t ifx_se_key_derivation_step_t;

/**@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_PSACRYPTO_TYPES_H */
