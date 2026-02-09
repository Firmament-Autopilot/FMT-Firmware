/**
 * \file ifx_se_fih.c
 * \version 1.2.0
 *
 * \brief Fault injection hardening module implementation.
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

#include "ifx_se_fih.h"

/* Inherit the compilers setting & behaviour from SysLib */
#include "cy_syslib.h"

/* Default implementation, should be replaced in user project */
__WEAK bool ifx_se_fih_delay(void)
{
    return true;
}

/* Global failure loop for bootloader code. Uses attribute used to prevent
 * compiler removing due to non-standard calling procedure. Multiple loop jumps
 * used to make unlooping difficult.
 */
__attribute__((used))
__attribute__((noinline))
void ifx_se_fih_panic_loop(void)
{
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
    __asm volatile ("b ifx_se_fih_panic_loop");
}

IFX_SE_NOINLINE bool ifx_se_fih_check_eq_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return ((a->msk) == (b->msk));
}

IFX_SE_NOINLINE bool ifx_se_fih_check_not_eq_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return ((a->msk) != (b->msk));
}

IFX_SE_NOINLINE bool ifx_se_fih_check_gt_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return (IFX_SE_FIH_VAL_MASK(a->msk) > IFX_SE_FIH_VAL_MASK(b->msk));
}

IFX_SE_NOINLINE bool ifx_se_fih_check_ge_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return (IFX_SE_FIH_VAL_MASK(a->msk) >= IFX_SE_FIH_VAL_MASK(b->msk));
}

IFX_SE_NOINLINE bool ifx_se_fih_check_lt_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return (IFX_SE_FIH_VAL_MASK(a->msk) < IFX_SE_FIH_VAL_MASK(b->msk));
}

IFX_SE_NOINLINE bool ifx_se_fih_check_le_mask(ifx_se_fih_uint *a, ifx_se_fih_uint *b)
{
    return (IFX_SE_FIH_VAL_MASK(a->msk) <= IFX_SE_FIH_VAL_MASK(b->msk));
}

