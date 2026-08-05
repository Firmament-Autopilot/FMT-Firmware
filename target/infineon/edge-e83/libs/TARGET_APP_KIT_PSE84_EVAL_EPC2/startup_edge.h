/***************************************************************************//**
* \file startup_edge.h
* \version 1.0
*
* \brief Common startup header file for PSOC Edge devices.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#ifndef STARTUP_EDGE_H_
#define STARTUP_EDGE_H_
#include "cy_device_headers.h"

#if defined (CY_DOXYGEN) || defined (CY_DEVICE_PSE84_A0) || defined (CY_DEVICE_PSE84) /* Declarations for PSE84 */

#define ARMV8M_FIXED_EXP_NR     (15u)
#if defined (COMPONENT_CM55)
#define VECTORTABLE_SIZE        (MXCM55_SYSTEM_INT_NR + ARMV8M_FIXED_EXP_NR + 1u) /* +1 is for Stack pointer */
#else
#define VECTORTABLE_SIZE        (MXCM33_SYSTEM_INT_NR + ARMV8M_FIXED_EXP_NR + 1u) /* +1 is for Stack pointer */
#endif /* COMPONENT_CM55 */

#define VECTORTABLE_ALIGN       (1024) /* CM33 alignment for 195 entries (195x4=780) is 1024 bytes */

#if defined(__llvm__) && !defined(__ARMCC_VERSION)
    __STATIC_FORCEINLINE void __llvm_init_data(void)
    {
        typedef struct __copy_table {
            uint32_t const* src;
            uint32_t* dest;
            uint32_t  wlen;
        } __copy_table_t;

        typedef struct __zero_table {
            uint32_t* dest;
            uint32_t  wlen;
        } __zero_table_t;

        extern const __copy_table_t __copy_table_start__;
        extern const __copy_table_t __copy_table_end__;
        extern const __zero_table_t __zero_table_start__;
        extern const __zero_table_t __zero_table_end__;

        for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
            for(uint32_t i=0u; i<pTable->wlen; ++i) {
                pTable->dest[i] = pTable->src[i];
            }
        }

        for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
            for(uint32_t i=0u; i<pTable->wlen; ++i) {
                pTable->dest[i] = 0u;
            }
        }
    }

    typedef void(* ExecFuncPtr)(void) ;           /* typedef for the function pointers in the vector table */
    typedef void(* ExecFuncPtrRw)(void);
    extern ExecFuncPtrRw __s_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
    extern ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
#elif defined(__ARMCC_VERSION)
    typedef void(* const ExecFuncPtr)(void); /* typedef for the function pointers in the vector table */
    typedef void(* ExecFuncPtrRw)(void);
    extern ExecFuncPtrRw __s_vector_table_rw[VECTORTABLE_SIZE]    __attribute__( ( section( ".bss.noinit.RESET_RAM"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
    extern ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]    __attribute__( ( section( ".bss.noinit.RESET_RAM"))) __attribute__((aligned(VECTORTABLE_ALIGN)));
#elif defined (__GNUC__)
    typedef void(* ExecFuncPtr)(void) ;           /* typedef for the function pointers in the vector table */
    typedef void(* ExecFuncPtrRw)(void);
    extern ExecFuncPtrRw __s_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
    extern ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
#elif defined (__ICCARM__)
    typedef void(* const ExecFuncPtr)(void) ; /* typedef for the function pointers in the vector table */
    typedef void(* ExecFuncPtrRw)(void) ;
    extern ExecFuncPtrRw __s_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".intvec_ram"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
    extern ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".intvec_ram"))) __attribute__((aligned(VECTORTABLE_ALIGN))); /**< Secure vector table in flash/ROM */
#endif
extern ExecFuncPtr __s_vector_table[] ; /**< secure vector table in secure SRAM */

#endif /* defined (CY_DOXYGEN) || defined (CY_DEVICE_PSE84_A0) || defined (CY_DEVICE_PSE84)  */

#endif /* STARTUP_EDGE_H_ */
