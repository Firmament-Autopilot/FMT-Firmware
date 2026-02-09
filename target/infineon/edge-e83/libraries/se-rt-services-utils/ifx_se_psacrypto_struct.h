/**
 * \file ifx_se_psacrypto_struct.h
 * \version 1.2.0
 *
 * \brief PSA cryptography module: Mbed TLS structured type implementations
 *
 * \note This file may not be included directly. Applications must
 * include ifx_se_psacrypto.h.
 *
 * This file contains the definitions of some data structures with
 * implementation-specific definitions.
 *
 * In implementations with isolation between the application and the
 * cryptography module, it is expected that the front-end and the back-end
 * would have different versions of this file.
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

#ifndef IFX_SE_PSACRYPTO_STRUCT_H
#define IFX_SE_PSACRYPTO_STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \cond INTERNAL */
struct ifx_se_hash_operation_s {
    uint32_t operation_handle;   /*!< Frontend context handle associated to a multipart operation */
};
/** \endcond */

/** \addtogroup hash_operations
 * \{
 */

/** the initial value of the Hash operation context */
#define IFX_SE_HASH_OPERATION_INIT {0}

/** Initialize the Hash operation context 
 * \return ifx_se_hash_operation_s structure
 */
static inline struct ifx_se_hash_operation_s ifx_se_hash_operation_init( void )
{
    const struct ifx_se_hash_operation_s v = IFX_SE_HASH_OPERATION_INIT;
    return( v );
}
/** \} */

/** \cond INTERNAL */
struct ifx_se_cipher_operation_s {
     uint32_t operation_handle;   /*!< Frontend context handle associated to a multipart operation */
};
/** \endcond */

/** \addtogroup cipher_operations
 * \{
 */

/** The initial value of the Cipher operation context */
#define IFX_SE_CIPHER_OPERATION_INIT {0}

/** Initialize the Cipher operation context 
 * \return ifx_se_cipher_operation_s structure
 */
static inline struct ifx_se_cipher_operation_s ifx_se_cipher_operation_init( void )
{
    const struct ifx_se_cipher_operation_s v = IFX_SE_CIPHER_OPERATION_INIT;
    return( v );
}
/** \} */

/** \cond INTERNAL */
struct ifx_se_mac_operation_s {
    uint32_t operation_handle;   /*!< Frontend context handle associated to a multipart operation */
};
/** \endcond */

/** \addtogroup mac_operations
 * \{
 */

/** The initial value of the MAC operation context */
#define IFX_SE_MAC_OPERATION_INIT {0}

/** Initialize the MAC operation context
 * \return ifx_se_mac_operation_s structure
 */
static inline struct ifx_se_mac_operation_s ifx_se_mac_operation_init( void )
{
    const struct ifx_se_mac_operation_s v = IFX_SE_MAC_OPERATION_INIT;
    return( v );
}
/** \} */

/** \cond INTERNAL */
struct ifx_se_aead_operation_s {
    uint32_t operation_handle;   /*!< Frontend context handle associated to a multipart operation */
};
/** \endcond */

/** \addtogroup aead_operations
 * \{
 */

/** This only zeroes out the first byte in the union, the rest is unspecified. */
#define IFX_SE_AEAD_OPERATION_INIT {0}

/** 
 * Initialize the AEAD operation context
 * \return ifx_se_aead_operation_s structure
 */
static inline struct ifx_se_aead_operation_s ifx_se_aead_operation_init( void )
{
    const struct ifx_se_aead_operation_s v = IFX_SE_AEAD_OPERATION_INIT;
    return( v );
}
/** \} */

/** \cond INTERNAL */
struct ifx_se_key_derivation_s {
    uint32_t operation_handle;   /*!< Frontend context handle associated to a multipart operation */
};
/** \endcond */

/** \addtogroup key_derivation
 * \{
 */

/** This only zeroes out the first byte in the union, the rest is unspecified. */
#define IFX_SE_KEY_DERIVATION_OPERATION_INIT {0}

/** Initialize the key derivation context 
 * \return ifx_se_key_derivation_s structure
 */
static inline struct ifx_se_key_derivation_s ifx_se_key_derivation_operation_init( void )
{
    const struct ifx_se_key_derivation_s v = IFX_SE_KEY_DERIVATION_OPERATION_INIT;
    return( v );
}
/** \} */

/** \addtogroup key_policy
* \{
*/
/** \cond INTERNAL */
struct ifx_se_key_policy_s {
    ifx_se_key_usage_t usage; /*!< Encoded permitted usage of a key */
    ifx_se_algorithm_t alg; /*! Allowed main algorithm */
    ifx_se_algorithm_t alg2; /*! Allowed secondary algorithm */
};
/** \endcond */

/** Holds key usage allowance and specific algorithms
 * 
 * Members:
 * - #ifx_se_key_usage_t **usage** - Encoded permitted usage of a key
 * - #ifx_se_algorithm_t **alg** - Allowed main algorithm
 * - #ifx_se_algorithm_t **alg2** - Allowed secondary algorithm
 */
typedef struct ifx_se_key_policy_s ifx_se_key_policy_t;

/** The initial value of the key policy */
#define IFX_SE_KEY_POLICY_INIT { 0, 0, 0 }
/**
* \brief Sets key policy structure with initial value.
* \return ifx_se_key_policy_s structure
*/
static inline struct ifx_se_key_policy_s ifx_se_key_policy_init( void )
{
    const struct ifx_se_key_policy_s v = IFX_SE_KEY_POLICY_INIT;
    return( v );
}

/** \} */

/** \addtogroup crypto_types
 * \{
 */

/**
 * The type used internally for key sizes.
 * Public interfaces use size_t, but internally we use a smaller type. */
typedef uint16_t ifx_se_key_bits_t;

/**
 * The maximum value of the type used to represent bit-sizes.
 * This is used to mark an invalid key size. */
#define IFX_SE_KEY_BITS_TOO_LARGE          ( ( ifx_se_key_bits_t ) -1 )

/**
 * \brief The maximum size of a key in bits.
 * Currently defined as the maximum that can be represented, rounded down
 * to a whole number of bytes.
 * This is an uncast value so that it can be used in preprocessor
 * conditionals. */
#define IFX_SE_MAX_KEY_BITS 0xfff8

/**@}*/

/** \addtogroup key_attributes
 * @{
 */
/** \cond INTERNAL */
struct ifx_se_key_attributes_s {
    ifx_se_key_type_t type; /*!< Defines key type */
    ifx_se_key_bits_t bits; /*!< Defines size of a key in bits */
    ifx_se_key_lifetime_t lifetime; /*!<  Defines type of storage (persistent or volatile storage) */
    ifx_se_key_policy_t policy; /*!< Defines usage policy (algorithms, etc) */
    ifx_se_svc_key_id_t id; /*!< Defined ID for persistent keys */
};
/** \endcond */

/** The initial value of the key attributes */
#define IFX_SE_KEY_ATTRIBUTES_INIT { IFX_SE_KEY_TYPE_NONE, 0,        \
                                     IFX_SE_KEY_LIFETIME_VOLATILE,   \
                                     IFX_SE_KEY_POLICY_INIT,         \
                                     IFX_SE_SVC_KEY_ID_INIT }

/**
* \brief Sets key attributes structure with initial value.
* \return ifx_se_key_attributes_s structure
*/
static inline struct ifx_se_key_attributes_s ifx_se_key_attributes_init( void )
{
    const struct ifx_se_key_attributes_s v = IFX_SE_KEY_ATTRIBUTES_INIT;
    return( v );
}

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 2, \
    'Use function-like macro as simple inline functions.')
/**
* \brief Sets key ID in key attributes structure.
* \param[in] attributes     Key attributes structure
* \param[in] key            Key ID
*/
static inline void ifx_se_set_key_id( ifx_se_key_attributes_t *attributes,
                                   ifx_se_svc_key_id_t key )
{
    ifx_se_key_lifetime_t lifetime = attributes->lifetime;

    attributes->id = key;

    if ( IFX_SE_KEY_LIFETIME_IS_VOLATILE( lifetime ) )
    {
        attributes->lifetime =
            IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                IFX_SE_KEY_LIFETIME_PERSISTENT,
                IFX_SE_KEY_LIFETIME_GET_LOCATION( lifetime ) );
    }
}
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')

/**
* \brief Gets key ID from key attributes structure.
* \param[in] attributes     Key attributes structure
* \return                   Key ID
*/
static inline ifx_se_svc_key_id_t ifx_se_get_key_id(
    const ifx_se_key_attributes_t *attributes )
{
    return attributes->id;
}

/**@}*/

/** \addtogroup key_lifetimes
 * @{
 */

/**
* \brief Sets key lifetime in key attributes structure.
* \param[in] attributes     Key attributes structure
* \param[in] lifetime       Key lifetime
*/
static inline void ifx_se_set_key_lifetime( ifx_se_key_attributes_t *attributes,
                                        ifx_se_key_lifetime_t lifetime )
{
    attributes->lifetime = lifetime;
    if ( IFX_SE_KEY_LIFETIME_IS_VOLATILE( lifetime ) )
    {
        attributes->id.key_id = 0;
    }
}

/**
* \brief Gets key lifetime from key attributes structure.
* \param[in] attributes     Key attributes structure
* \return                   Key lifetime
*/
static inline ifx_se_key_lifetime_t ifx_se_get_key_lifetime(
    const ifx_se_key_attributes_t *attributes )
{
    return( attributes->lifetime );
}

/**@}*/

/** \addtogroup key_policy
 * @{
 */

/** \cond INTERNAL */
/*
* \brief Extends key usage flags in key attributes structure
* to support message mode.
* \param[in] attributes     Key attributes structure
* \param[in] usage_flags    Key usage flags
*/
static inline void ifx_se_extend_key_usage_flags( ifx_se_key_usage_t *usage_flags )
{
    if ((*usage_flags & IFX_SE_KEY_USAGE_SIGN_HASH) != 0u)
    {
         *usage_flags |= IFX_SE_KEY_USAGE_SIGN_MESSAGE;
    }

    if ((*usage_flags & IFX_SE_KEY_USAGE_VERIFY_HASH) != 0u)
    {
         *usage_flags |= IFX_SE_KEY_USAGE_VERIFY_MESSAGE;
    }
}
/** \endcond */

/**
* \brief Sets key usage flags in key attributes structure.
* \param[in] attributes     Key attributes structure
* \param[in] usage_flags    Key usage flags
*/
static inline void ifx_se_set_key_usage_flags(ifx_se_key_attributes_t *attributes,
                                           ifx_se_key_usage_t usage_flags)
{
    ifx_se_extend_key_usage_flags( &usage_flags );
    attributes->policy.usage = usage_flags;
}

/**
* \brief Gets key usage flags from key attributes structure.
* \param[in] attributes     Key attributes structure
* \return                   Key usage flags
*/
static inline ifx_se_key_usage_t ifx_se_get_key_usage_flags(
    const ifx_se_key_attributes_t *attributes )
{
    return( attributes->policy.usage );
}

/**@}*/

/** \addtogroup crypto_algs
 * @{
 */

/**
* \brief Sets key algorithm in key attributes structure.
* \param[in] attributes     Key attributes structure
* \param[in] alg            Key algorithm
*/
static inline void ifx_se_set_key_algorithm( ifx_se_key_attributes_t *attributes,
                                         ifx_se_algorithm_t alg )
{
    attributes->policy.alg = alg;
}

/**
* \brief Gets key algorithm from key attributes structure.
* \param[in] attributes     Key attributes structure
* \return                   Key algorithm
*/
static inline ifx_se_algorithm_t ifx_se_get_key_algorithm(
    const ifx_se_key_attributes_t *attributes )
{
    return attributes->policy.alg;
}

/**
* \brief Sets enrollment key algorithm in key attributes structure.
* \param[in] attributes    Key attributes structure
* \param[in] alg2          A second algorithm that the key may be used
*                          for, in addition to the algorithm set with
*                          ifx_se_set_key_algorithm().
*
* \warning Setting an enrollment algorithm is not recommended, because
*          using the same key with different algorithms can allow some
*          attacks based on arithmetic relations between different
*          computations made with the same key, or can escalate harmless
*          side channels into exploitable ones. Use this function only
*          if it is necessary to support a protocol for which it has been
*          verified that the usage of the key with multiple algorithms
*          is safe.
*/
static inline void ifx_se_set_key_enrollment_algorithm( ifx_se_key_attributes_t *attributes,
                                                    ifx_se_algorithm_t alg2)
{
    attributes->policy.alg2 = alg2;
}

/**
* \brief Gets enrollment key algorithm from key attributes structure.
* \param[in] attributes     Key attributes structure
* \return                   The enrollment algorithm stored in the attribute structure
*/
static inline ifx_se_algorithm_t ifx_se_get_key_enrollment_algorithm(
                                                    const ifx_se_key_attributes_t *attributes)
{
    return attributes->policy.alg2;
}

/**@}*/

/** \addtogroup crypto_types
 * @{
 */

 /**
 * \brief Sets key type in key attributes structure.
 * \param[in] attributes     Key attributes structure
 * \param[in] type           Key type
 */
static inline void ifx_se_set_key_type( ifx_se_key_attributes_t *attributes,
                                    ifx_se_key_type_t type )
{
        attributes->type = type;
}

/**
* \brief Gets key type from key attributes structure
* \param[in] attributes     Key attributes structure
* \return                   Key type
*/
static inline ifx_se_key_type_t ifx_se_get_key_type(
    const ifx_se_key_attributes_t *attributes )
{
    return attributes->type;
}

/**
* \brief Sets key length in bits in key attributes structure
* \param[in] attributes     Key attributes structure
* \param[in] bits           Key length in bits
*/
static inline void ifx_se_set_key_bits( ifx_se_key_attributes_t *attributes,
                                    size_t bits )
{
    if ( bits > (size_t) IFX_SE_MAX_KEY_BITS )
    {
        attributes->bits = IFX_SE_KEY_BITS_TOO_LARGE;
    }
    else
    {
        attributes->bits = (ifx_se_key_bits_t) bits;
    }
}

/**
* \brief Gets key length in bits from key attributes structure
* \param[in] attributes     Key attributes structure
* \return                   Key length in bits
*/
static inline size_t ifx_se_get_key_bits(
    const ifx_se_key_attributes_t *attributes )
{
    return( attributes->bits );
}

/** \cond INTERNAL */
struct ifx_se_key_id_fih_s {
    ifx_se_fih_uint key_id; /*!< ID of a key */
    ifx_se_fih_uint owner;  /*!< Key owner */
};
/** \endcond */

/** The initial value of the keys identifier transfer data with specified key id and owner */
#define IFX_SE_KEY_ID_FIH_INIT_VALUE(owner, id) \
    { { (id), IFX_SE_FIH_VAL_MASK(id) }, { (owner), IFX_SE_FIH_VAL_MASK(owner) } }

/** The initial value of the keys identifier transfer data */
#define IFX_SE_KEY_ID_FIH_INIT IFX_SE_KEY_ID_FIH_INIT_VALUE(0, 0)

/**
* \brief Sets key  FIH transfer data with initial value.
* \return ifx_se_key_id_fih_s structure
*/
static inline ifx_se_key_id_fih_t ifx_se_key_id_fih_init( void )
{
    const struct ifx_se_key_id_fih_s v = IFX_SE_KEY_ID_FIH_INIT;
    return( v );
}

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 1, \
    'Use function-like macro as simple inline functions.')
/**
* \brief Utility to initialize a key identifier FIH transfer data at runtime.
* \param owner_id Identifier of the key owner.
* \param key_id   Identifier of the key.
* \return ifx_se_key_id_fih_s structure
*/
static inline ifx_se_key_id_fih_t ifx_se_key_id_fih_make( int32_t owner_id, ifx_se_key_id_t key_id )
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Intentional typecast owner_id to uint32_t.');
    const struct ifx_se_key_id_fih_s v = IFX_SE_KEY_ID_FIH_INIT_VALUE((uint32_t)owner_id, key_id);
    return( v );
}
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')

/**
* \brief Utility to initialize a key identifier FIH transfer data from FIH values at runtime.
* \param owner_id Identifier of the key owner.
* \param key_id   Identifier of the key.
* \return ifx_se_key_id_fih_s structure
*/
static inline ifx_se_key_id_fih_t ifx_se_key_id_make( ifx_se_fih_uint owner_id, ifx_se_fih_uint key_id )
{
    const struct ifx_se_key_id_fih_s v = { .key_id = key_id, .owner = owner_id };
    return( v );
}

/** \} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_PSACRYPTO_STRUCT_H */
