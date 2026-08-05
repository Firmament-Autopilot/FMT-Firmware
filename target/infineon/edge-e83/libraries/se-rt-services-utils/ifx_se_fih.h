/**
 * \file ifx_se_fih.h
 * \version 1.2.0
 *
 * \brief Fault injection hardening module definitions.
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

/*******************************************************************************
* IFX SE FIH library API definitions
****************************************************************************//**
*
* \defgroup fih     IFX SE FIH library API
* \brief
*  IFX SE FIH library functions
*
*******************************************************************************/

#ifndef IFX_SE_FIH_H
#define IFX_SE_FIH_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "cy_syslib.h"
#include "cy_utils.h"

/*
 * Fault injection mitigation library simplified for the needs of SE RT Services.
 *
 * NOTE: It is not guaranteed that these constructs against fault injection
 *       attacks can be preserved in all compilers.
 *
 * Makes critical variables into a tuple (x, x ^ msk).
 * Then the correctness of x can be checked by XORing the two tuple values
 * together. This also means that comparisons between ifx_se_fih_uints can be
 * verified by doing x == y && x_msk == y_msk.
 *
 * Makes all while(1) failure loops redirect to a global failure loop. 
 * This loop has mitigations against loop escapes / unlooping.
 * This also means that any unlooping won't immediately continue executing the
 * function that was executing before the failure.
 *
 * If a fault injection is detected, call IFX_SE_FIH_PANIC to trap the execution.
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 4, \
    'Use function-like macro as simple inline functions.')

/** \addtogroup fih
 * \{
 */

/** \cond INTERNAL */
#define IFX_SE_FIH_TRUE             (0xC35AUL)
#define IFX_SE_FIH_FALSE            (0x0U)

#define IFX_SE_FIH_POSITIVE_VALUE   (uint32_t)(0x5555AAAAU)
#define IFX_SE_FIH_NEGATIVE_VALUE   (uint32_t)(0xAAAA5555U)

#ifdef __DOXYGEN__
    #define IFX_SE_NOINLINE
#else
    #define IFX_SE_NOINLINE                  __attribute__((noinline))
#endif /* __DOXYGEN__ */

/*
 * A volatile mask is used to prevent compiler optimization - the mask is XORed
 * with the variable to create the backup and the integrity can be checked with
 * another xor. The mask value doesn't _really_ matter that much, as long as
 * it has reasonably high Hamming weight.
 */
#define IFX_SE_FIH_MASK_VALUE       (uint32_t)(0xA5C35A3CU)

#define IFX_SE_FIH_VAL_MASK(val)    (((uint32_t)(val)) ^ IFX_SE_FIH_MASK_VALUE)
/** \endcond */

/**
 * All ints are replaced with two int - the normal one and a backup which is
 * XORed with the mask.
 */
typedef struct {
    volatile uint32_t val;
    volatile uint32_t msk;
} ifx_se_fih_uint;

/** \cond INTERNAL */
#define IFX_SE_FIH_UINT_INIT(x)     ((ifx_se_fih_uint){(x), IFX_SE_FIH_VAL_MASK(x)})

#define IFX_SE_FIH_SUCCESS          (IFX_SE_FIH_UINT_INIT(IFX_SE_FIH_POSITIVE_VALUE))
#define IFX_SE_FIH_FAILURE          (IFX_SE_FIH_UINT_INIT(IFX_SE_FIH_NEGATIVE_VALUE))
#define IFX_SE_FIH_UINT_ZERO        (IFX_SE_FIH_UINT_INIT(0UL))
#define IFX_SE_FIH_UINT_MAX         (IFX_SE_FIH_UINT_INIT(UINT32_MAX))

/**
 * Global failure handler - more resistant to unlooping. noinline and used are
 * used to prevent optimization.
 *
 * NOTE
 * This failure handler shall be used as FIH specific error handling to capture
 * FI attacks. Error handling in SPM and SP should be enhanced respectively.
 */
__attribute__((noinline)) __attribute__((used)) void ifx_se_fih_panic_loop(void);
#define IFX_SE_FIH_PANIC ifx_se_fih_panic_loop()
/** \endcond */

/*******************************************************************************
 * Function Name: ifx_se_fih_delay
 ***************************************************************************//**
 * \brief Perform delay between FIH operations
 *
 * \return TRUE after delay
 *
 * \note This function is marked as WEAK so user should implement it
 * in own project according to the platform environment
 *
 ******************************************************************************/
bool ifx_se_fih_delay(void);

/*******************************************************************************
 * Function Name: ifx_se_fih_uint_validate
 ***************************************************************************//**
 * \brief Validate ifx_se_fih_uint for tampering.
 *
 * \param x  ifx_se_fih_uint value to be validated.
 *
 * \return   TRUE if data is valid and not tampered
 *           otherwise raise panic loop.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
bool ifx_se_fih_uint_validate(ifx_se_fih_uint x)
{
    uint32_t x_msk = IFX_SE_FIH_VAL_MASK(x.msk);
    if (x.val != x_msk)
    {
        IFX_SE_FIH_PANIC;
    }
    return true;
}

/*******************************************************************************
 * Function Name: ifx_se_fih_uint_decode
 ***************************************************************************//**
 * \brief Convert a ifx_se_fih_uint to an unsigned int.
 *
 * \param x  ifx_se_fih_uint value to be converted.
 *
 * \return   Value converted to unsigned int.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
uint32_t ifx_se_fih_uint_decode(ifx_se_fih_uint x)
{
    (void)ifx_se_fih_uint_validate(x);
    return x.val;
}


/*******************************************************************************
 * Function Name: ifx_se_fih_uint_encode
 ***************************************************************************//**
 * \brief Convert an unsigned int to a ifx_se_fih_uint.
 *
 * \param x  Unsigned integer value to be converted.
 *
 * \return   Value converted to ifx_se_fih_uint.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
ifx_se_fih_uint ifx_se_fih_uint_encode(uint32_t x)
{
    ifx_se_fih_uint ret = IFX_SE_FIH_UINT_INIT(x);
    return ret;
}


/*******************************************************************************
 * Function Name: ifx_se_fih_check_eq_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are equal in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_eq_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: ifx_se_fih_uint_eq
 ***************************************************************************//**
 * \brief Standard equality for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x == y, FALSE other otherwise.
 *
 * \note
 * This implementation of ifx_se_fih_uint_eq() macro causes two
 * "MISRA C-2012 Rule 13.5" - "persistent side effects" violations in "if" per
 * each ifx_se_fih_uint_eq() in the calling code. The violations should be
 * suppressed in the MISRA checker configuration and marked as non-critical.
 * This explanation is also applicable for other  FIH macros like
 * ifx_se_fih_uint_not_eq(), ifx_se_fih_uint_gt(), etc.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_eq(x, y) \
        ( ((x).val == (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val == IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x) && \
          ifx_se_fih_check_eq_mask(&(x), &(y)) \
          )


/*******************************************************************************
 * Function Name: ifx_se_fih_check_not_eq_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are not equal in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_not_eq_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: ifx_se_fih_uint_not_eq
 ***************************************************************************//**
 * \brief Standard non-equality for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x != y, FALSE otherwise.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_not_eq(x, y) \
        ( ((x).val != (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val != IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x) && \
          ifx_se_fih_check_not_eq_mask(&(x), &(y)) \
        )


/*******************************************************************************
 * Function Name: ifx_se_fih_check_gt_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are greater than in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_gt_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: fih_uint_gt
 ***************************************************************************//**
 * \brief Standard greater than comparison for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x > y, FALSE otherwise.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_gt(x, y) \
        ( ((x).val > (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val < IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x)  && \
          ifx_se_fih_check_gt_mask(&(x), &(y)) \
        )


/*******************************************************************************
 * Function Name: ifx_se_fih_check_ge_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are greater than or equal in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_ge_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: ifx_se_fih_uint_ge
 ***************************************************************************//**
 * \brief Standard greater than or equal comparison for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x >= y, FALSE otherwise.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_ge(x, y) \
        ( ((x).val >= (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val <= IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x)  && \
          ifx_se_fih_check_ge_mask(&(x), &(y)) \
        )


/*******************************************************************************
 * Function Name: ifx_se_fih_check_lt_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are less than in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_lt_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: ifx_se_fih_uint_lt
 ***************************************************************************//**
 * \brief Standard less than comparison for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x < y, FALSE otherwise.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_lt(x, y) \
        ( ((x).val < (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val > IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x)  && \
          ifx_se_fih_check_lt_mask(&(x), &(y)) \
        )


/*******************************************************************************
 * Function Name: ifx_se_fih_check_le_mask
 ***************************************************************************//**
 * \brief Compares masks for two FIH variables.
 *
 * \param a  pointer to the 1st ifx_se_fih_uint value.
 * \param b  pointer to the 2nd ifx_se_fih_uint value.
 *
 * \return   TRUE if masks are less than or equal in two variables
 *           otherwise FALSE.
 *
 ******************************************************************************/
IFX_SE_NOINLINE
bool ifx_se_fih_check_le_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b);


/*******************************************************************************
 * Macro Name: ifx_se_fih_uint_le
 ***************************************************************************//**
 * Standard less than or equal comparison for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be compared.
 * \param y  2nd ifx_se_fih_uint value to be compared.
 *
 * \return   TRUE if x <= y, FALSE otherwise.
 *
 ******************************************************************************/
#define ifx_se_fih_uint_le(x, y) \
        ( ((x).val <= (y).val) && \
          ifx_se_fih_delay() && \
          ((y).val >= IFX_SE_FIH_VAL_MASK((x).msk)) && \
          ifx_se_fih_delay() && \
          ifx_se_fih_uint_validate(x)  && \
          ifx_se_fih_check_le_mask(&(x), &(y)) \
        )

/*******************************************************************************
 * Function Name: ifx_se_fih_uint_or
 ***************************************************************************//**
 * \brief Standard logical OR for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be ORed.
 * \param y  2nd ifx_se_fih_uint value to be ORed.
 *
 * \return  ORed value
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
ifx_se_fih_uint ifx_se_fih_uint_or(ifx_se_fih_uint x, ifx_se_fih_uint y)
{
    uint32_t y_val, y_msk;
    ifx_se_fih_uint rc;

    y_val = y.val;
    rc.val = x.val | y_val;

    y_msk = y.msk;
    rc.msk = IFX_SE_FIH_VAL_MASK(IFX_SE_FIH_VAL_MASK(x.msk) | IFX_SE_FIH_VAL_MASK(y_msk));

    return rc;
}

/*******************************************************************************
 * Function Name: ifx_se_fih_uint_and
 ***************************************************************************//**
 * \brief Standard logical AND for ifx_se_fih_uint values.
 *
 * \param x  1st ifx_se_fih_uint value to be ANDed.
 * \param y  2nd ifx_se_fih_uint value to be ANDed.
 *
 * \return  ANDed value
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
ifx_se_fih_uint ifx_se_fih_uint_and(ifx_se_fih_uint x, ifx_se_fih_uint y)
{
    uint32_t y_val, y_msk;
    ifx_se_fih_uint rc;

    y_val = y.val;
    rc.val = x.val & y_val;

    y_msk = y.msk;
    rc.msk = IFX_SE_FIH_VAL_MASK(IFX_SE_FIH_VAL_MASK(x.msk) & IFX_SE_FIH_VAL_MASK(y_msk));

    return rc;
}

/** Special generic FIH type definition for SE RT Services transport */
typedef ifx_se_fih_uint ifx_se_fih_t;

/** Special pointer FIH type definition for SE RT Services transport */
typedef struct {
    volatile uint32_t val;
    volatile uint32_t msk;
} ifx_se_fih_ptr_t;

/** \cond INTERNAL */
#define IFX_SE_FIH_PTR_INIT(x)     ((ifx_se_fih_ptr_t){(x), IFX_SE_FIH_VAL_MASK(x)})

/*******************************************************************************
 * Function Name: ifx_se_fih_ptr_to_uint
 ***************************************************************************//**
 * \brief Convert ifx_se_fih_ptr_t value to ifx_se_fih_uint
 *
 * \param x  ifx_se_fih_ptr_t value to be converted.
 *
 * \return   Value converted to ifx_se_fih_uint.
 *
 * \note This function is internal and shouldn't be used in the application code
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
ifx_se_fih_uint ifx_se_fih_ptr_to_uint(const ifx_se_fih_ptr_t x)
{
    ifx_se_fih_uint ret = { x.val, x.msk };
    return ret;
}
/** \endcond */

/*******************************************************************************
 * Function Name: ifx_se_fih_ptr_validate
 ***************************************************************************//**
 * \brief Validate ifx_se_fih_ptr_t for tampering.
 *
 * \param x  ifx_se_fih_ptr_t value to be validated.
 *
 * \return   TRUE if data is valid and not tampered
 *           otherwise raise panic loop.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
bool ifx_se_fih_ptr_validate(ifx_se_fih_ptr_t x)
{
    uint32_t x_msk = IFX_SE_FIH_VAL_MASK(x.msk);
    if (x.val != x_msk)
    {
        IFX_SE_FIH_PANIC;
    }
    return true;
}

CY_MISRA_DEVIATE_BLOCK_START('CERT INT36-C', 2, \
    'Intentional typecast between "void *" and "ifx_se_fih_ptr_t" types.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.6', 2, \
    'Intentional typecast between "void *" and "ifx_se_fih_ptr_t" types.')

/*******************************************************************************
 * Function Name: ifx_se_fih_ptr_encode
 ***************************************************************************//**
 * \brief Convert pointer address to a ifx_se_fih_ptr_t.
 *
 * \param x  Pointer address to be converted.
 *
 * \return   Value converted to ifx_se_fih_ptr_t.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
ifx_se_fih_ptr_t ifx_se_fih_ptr_encode(const void *x)
{
    return IFX_SE_FIH_PTR_INIT((uint32_t)x);
}

/*******************************************************************************
 * Function Name: ifx_se_fih_ptr_decode
 ***************************************************************************//**
 * \brief Convert a ifx_se_fih_ptr_t to pointer address.
 *
 * \param x  ifx_se_fih_ptr_t value to be converted.
 *
 * \return   Value converted to pointer address.
 *
 ******************************************************************************/
__STATIC_FORCEINLINE
void * ifx_se_fih_ptr_decode(ifx_se_fih_ptr_t x)
{
    (void)ifx_se_fih_ptr_validate(x);
    return (void *)(x.val);
}

CY_MISRA_BLOCK_END('CERT INT36-C')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.6')

/** \} */

CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_FIH_H */
