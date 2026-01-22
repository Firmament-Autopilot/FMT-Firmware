/***************************************************************************//**
* \file ns_start_pse84.c
* \version 1.0
*
* The device system-startup file.
*
********************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * CMSIS Device Startup file modified to adapt for PSOC Edge Device.
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "cy_device_headers.h"
#include "startup_edge.h"
#include "system_edge.h"
#include "cy_sysint.h"
#include "cy_syspm.h"
#include "cy_syslib.h"
#include "cmsis_compiler.h"


CY_MISRA_FP_BLOCK_START('MISRA C-2012 Rule 8.6', 3, \
'Checked manually. The definition is a part of linker script or application.')
CY_MISRA_DEVIATE_BLOCK_START('ARRAY_VS_SINGLETON', 1, \
'Checked manually. Using pointer as an array will not corrupt or misinterpret adjacent memory locations.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.1', 3, \
'Checked manually. Dereferencing a pointer to one beyond the end of an array will not result in undefined behaviour.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.3', 1, \
'Checked manually. Attempting to make comparisons between pointers will not result in undefined behaviour.')

/*
** Copyright (c) 2018 Arm Limited. All rights reserved.
*/

// Initial Setup
//----------------------------------------------------------------

#if defined (__ARMCC_VERSION)
extern uint32_t Region$$Table$$Base;
extern uint32_t Region$$Table$$Limit;
typedef  void(*pGenericFunction)(uint8_t *pSrc, uint8_t* pDst, uint32_t len);     /* typedef for the generic function pointers */
#endif

__WEAK void Reset_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
__WEAK void SVC_Handler(void);
void DebugMon_Handler(void);
__WEAK void PendSV_Handler(void);
__WEAK void SysTick_Handler(void);
void InterruptHandler(void);
void NMIException_Handler(void);
__WEAK void HardFault_Handler(void);
void delay_infinite(void);
void SysLib_FaultHandler(uint32_t const *faultStackAddr);
extern int main(void);

#if defined (__ARMCC_VERSION)
void __attribute__((optnone)) Cy_RuntimeInit(void);
#else
void Cy_RuntimeInit(void);
#endif

#if defined(__llvm__) && !defined(__ARMCC_VERSION)
extern void _start(void);
extern unsigned int __stack;
extern uint32_t __stack_limit;
ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN)));
#elif defined(__ARMCC_VERSION)
extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Limit;
extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Base;
extern void __main(void);
ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE] __attribute__( ( section(".bss.noinit.RESET_RAM"))) __attribute__((aligned(VECTORTABLE_ALIGN)));
#elif defined (__GNUC__)
extern unsigned int __StackTop;
extern uint32_t __StackLimit;
ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".ram_vectors"))) __attribute__((aligned(VECTORTABLE_ALIGN)));
#elif defined (__ICCARM__)
extern unsigned int CSTACK$$Limit;                      /* for (default) One Region model */
extern unsigned int CSTACK$$Base;
extern void  __cmain();
// IAR (and C-SPY debugger) expect that the vector table is defined as __vector_table, so alias the definition upon compilation.
// If the alias is not done, IAR includes its own default __vector_table definition in the compilation.
#define __ns_vector_table __vector_table
ExecFuncPtrRw __ns_vector_table_rw[VECTORTABLE_SIZE]   __attribute__( ( section(".intvec_ram"))) __attribute__((aligned(VECTORTABLE_ALIGN)));
#else
    #error "An unsupported toolchain"
#endif  /* (__ARMCC_VERSION) */

/* Provide empty __WEAK implementation for the low-level initialization
   routine required by the RTOS-enabled applications.
   clib-support library provides FreeRTOS-specific implementation:
   https://github.com/Infineon/clib-support */
__WEAK void cy_toolchain_init(void)
{
}

void Cy_RuntimeInit(void)
{
#if defined(__llvm__) && !defined(__ARMCC_VERSION)
    __llvm_init_data();
    cy_toolchain_init();
#endif

    __PROGRAM_START();
}

__asm(".global SysLib_FaultHandler\n");

void SysLib_FaultHandler(uint32_t const *faultStackAddr)
{
    Cy_SysLib_FaultHandler(faultStackAddr);
}

// Exception Vector Table & Handlers
//----------------------------------------------------------------
void NMIException_Handler(void)
{
    __asm volatile(
        "bkpt #10\n"
        "B .\n"
    );
}

__WEAK void HardFault_Handler(void)
{
    __asm (
        "MRS R0, CONTROL\n"
        "TST R0, #2\n"
        "ITE EQ\n"
        "MRSEQ R0, MSP\n"
        "MRSNE R0, PSP\n"
        "LDR R1, =SysLib_FaultHandler\n"
        "BX R1\n"
    );
}

void MemManage_Handler(void)
{
	__asm (
		"MRS R0, CONTROL\n"
		"TST R0, #2\n"
		"ITE EQ\n"
		"MRSEQ R0, MSP\n"
		"MRSNE R0, PSP\n"
		"B SysLib_FaultHandler\n"
	);
}

void BusFault_Handler(void)
{
	__asm (
		"MRS R0, CONTROL\n"
		"TST R0, #2\n"
		"ITE EQ\n"
		"MRSEQ R0, MSP\n"
		"MRSNE R0, PSP\n"
		"B SysLib_FaultHandler\n"
	);
}
void UsageFault_Handler(void)
{
	__asm (
		"MRS R0, CONTROL\n"
		"TST R0, #2\n"
		"ITE EQ\n"
		"MRSEQ R0, MSP\n"
		"MRSNE R0, PSP\n"
		"B SysLib_FaultHandler\n"
	);
}

__WEAK void SVC_Handler(void)       {Cy_SysLib_ProcessingFault();}
void DebugMon_Handler(void)         {Cy_SysLib_ProcessingFault();}
__WEAK void PendSV_Handler(void)    {Cy_SysLib_ProcessingFault();}
__WEAK void SysTick_Handler(void)   {Cy_SysLib_ProcessingFault();}

void InterruptHandler(void)
{
    __asm volatile(
        "bkpt #1\n"
        "B .\n"
    );
}

ExecFuncPtr __ns_vector_table[] __VECTOR_TABLE_ATTRIBUTE = {
    (ExecFuncPtr)&__INITIAL_SP,           // initial SP
    (ExecFuncPtr)Reset_Handler,           // initial PC/Reset
    (ExecFuncPtr)NMIException_Handler,
    (ExecFuncPtr)HardFault_Handler,
    (ExecFuncPtr)MemManage_Handler,       // Memory Manage Fault
    (ExecFuncPtr)BusFault_Handler,        // Bus Fault
    (ExecFuncPtr)UsageFault_Handler,      // Usage Fault
    0,                                    // Secure Fault
    0,                                    // RESERVED
    0,                                    // RESERVED
    0,                                    // RESERVED
    (ExecFuncPtr)SVC_Handler,             // SVC
    0,                                    // debug
    0,                                    // RESERVED
    (ExecFuncPtr)PendSV_Handler,          // Pend SV
    (ExecFuncPtr)SysTick_Handler,         // Secure systick
    /* External interrupts */
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler,
    (ExecFuncPtr)InterruptHandler
};

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
/* GCC: newlib crt0 _start executes software_init_hook.
   The cy_toolchain_init hook provided by clib-support library must execute
   after static data initialization and before static constructors. */
void software_init_hook();
void software_init_hook()
{
    cy_toolchain_init();
}
#elif defined(__ICCARM__)
/* Initialize data section */
void __iar_data_init3(void);

/* Call the constructors of all global objects */
void __iar_dynamic_initialization(void);

/* Define strong version to return zero for __iar_program_start
   to skip data sections initialization (__iar_data_init3). */
int __low_level_init(void);
int __low_level_init(void)
{
    return 0;
}
#else
/**/
#endif /* defined(__GNUC__) && !defined(__ARMCC_VERSION) */


// Reset Handler
__WEAK void Reset_Handler(void)
{
    __disable_irq();

    for (uint32_t count = 0; count < VECTORTABLE_SIZE; count++)
    {
        __ns_vector_table_rw[count] =__ns_vector_table[count];
    }

    SCB->VTOR = (uint32_t)__ns_vector_table_rw;
    __DMB();

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined(__ICCARM__)
    /* Initialize data section */
    __iar_data_init3();

    /* Initialization hook for RTOS environment  */
    cy_toolchain_init();

    /* Call the constructors of all global objects */
    __iar_dynamic_initialization();
#endif

    SystemInit();

    Cy_RuntimeInit();
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.3')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.1')
CY_MISRA_BLOCK_END('ARRAY_VS_SINGLETON')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.6')
