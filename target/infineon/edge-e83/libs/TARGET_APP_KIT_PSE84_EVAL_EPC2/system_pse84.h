/***************************************************************************//**
* \file system_pse84.h
* \version 1.0
*
* \brief Device system header file.
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


#ifndef _SYSTEM_PSE84_H_
#define _SYSTEM_PSE84_H_

/**
* \addtogroup group_system_config_psoc_edge Startup/System
* \{
* Provides device startup, system configuration, and linker script files.
* The system startup provides the followings features:
* - \ref group_system_config_device_memory_definition_edge
* - \ref group_system_config_device_initialization_edge
* - \ref group_system_config_heap_stack_config_edge
* - \ref group_system_config_default_handlers_edge
* - \ref group_system_config_device_vector_table_edge
*
* \section group_system_config_configuration_edge Configuration Considerations
*
* \subsection group_system_config_device_memory_definition_edge Device Memory Definition
* Allocation of different types of memory such as the RRAM and RAM etc. for the CPU is defined
* by the linker scripts.
*
* \note The linker files provided with the templates are generic and handle all common
* use cases. Your project may not use every section defined in the linker files.
* In that case you may see warnings during the build process. To eliminate build
* warnings in your project, you can simply comment out or remove the relevant
* section in the linker file.
*
* \note If the start of the Cortex-M33 non-secure application image is changed, the value
* of the \ref CY_CORTEX_M33_NS_APPL_ADDR should also be changed. The
* \ref CY_CORTEX_M33_NS_APPL_ADDR macro should be used as the parameter fo the __TZ_set_MSP_NS
* function call.
*
* \note If the start of the Cortex-M55 application image is changed, the value
* of the \ref CY_CORTEX_M55_APPL_ADDR should also be changed. The
* \ref CY_CORTEX_M55_APPL_ADDR macro should be used as the parameter for the
* Cy_SysCM55Enable() function call.
*
*
* \subsection group_system_config_device_initialization_edge Device Initialization
* After a power-on-reset (POR), the boot process is handled by the boot code
* from the on-chip ROM that is always executed by the Cortex-M0+ core. The boot
* code passes the control to the Cortex-M33 startup code and Cortex-M33 boots the Cortex-M55 core.
*
* <b>CM33 Boot</b><br/>
* CM33 always boots in secure mode after reset. Then, the secure code switches
* execution to non-secure mode. Each execution environment has its own application image.
* Each application image contains its startup code. So, there are two separate startup codes.
* One is for secure execution environment, part of secure application image and
* other one is for non-secure execution environment, part of non-secure application image.
* Execution of startup code is triggered by the secure code after it completes the
* initialization during boot process. It switches control to non-secure startup code
* by switching processor execution state to non-secure state.\n
* The secure code is programmed in RRAM NVM MAIN region. This code executes in place (XIP) from RRAM.
* First secure code to execute on CM33 is CM33_L1_BOOTLOADER. The CM33_L1_BOOTLOADER, SE_RRAM_BOOT
* code is launched by the code executing on CM0P core in secure enclave by setting the address of
* the image entry point in the CM33_S_VECTOR_TABLE_BASE (S_VTOR) register and setting the CM33_CTL.CPUWAIT
* to LOW to allow execution of reset handler of secure image. Address of CM33_L1_BOOTLOADER image entry point
* is obtained from the TOC2 table entry CM33_L1_BOOTLOADER_ADDR.
*
* <b>CM55 Boot</b><br/>
* The CM55 CPUSS is OFF by default upon POR. CM55 application is launched from CM33 non-secure application
* depending on the use case requirements. CM55 Application is programmed executed in place from the external flash.
* The C runtime code will copy necessary code to SOCMEM and other memory areas depending on the choice made for the
* execution region in the linker script.
* CM55 execution is held by its CM55_CTL.CPU_WAIT (which will be HIGH) till released (made LOW) by CM33 app
* to launch the CM55 code after programming the CM55 VTOR with the image entry point in the targeted memory.
*
* Below sequence diagram captures the initialization process in the startup code.
* ![](cm33_bootup_sequence.png)
*
* \subsection group_system_config_heap_stack_config_edge Heap and Stack Configuration
* By default, the stack size is set to 0x00001000 for non-secure applications and 0x00000800 for the CM33 secure
* application. The remaining ram is used for the heap
*
* \subsubsection group_system_config_heap_stack_config_gcc_edge ARM GCC
* The stack and heap sizes are defined in the linker script file: 'pse84_s_cm33.ld', 'pse84_ns_cm33.ld' and 'pse84_ns_cm55.ld'
* To set stack size in application add makefile ldflags: -Wl,--defsym=APP_MSP_STACK_SIZE=< CUSTOM_VALUE >
* Remaining free RAM is used as heap.
*
* \note Correct operation of malloc and related functions depends on the working
* implementation of the 'sbrk' function. Newlib-nano (default C runtime library
* used by the GNU Arm Embedded toolchain) provides weak 'sbrk' implementation that
* doesn't check for heap and stack collisions during excessive memory allocations.
* To ensure the heap always remains within the range defined by __HeapBase and
* __HeapLimit linker symbols, provide a strong override for the 'sbrk' function:
* ```C
* void * _sbrk(uint32_t incr)
* {
*     extern uint8_t __HeapBase, __HeapLimit;
*     static uint8_t *heapBrk = &__HeapBase;
*     uint8_t *prevBrk = heapBrk;
*     if (incr > (uint32_t)(&__HeapLimit - heapBrk))
*     {
*         errno = ENOMEM;
*         CY_HALT();
*     }
*     heapBrk += incr;
*     return prevBrk;
* }
* ```
* For FreeRTOS-enabled multi-threaded applications, it is sufficient to include
* clib-support library that provides newlib-compatible implementations of
* 'sbrk', '__malloc_lock' and '__malloc_unlock':
* <br>
* https://github.com/Infineon/clib-support.
*
* \subsubsection group_system_config_heap_stack_config_arm_edge ARM Compiler
* The stack and heap sizes are defined in the linker script file: 'pse84_s_cm33.sct', 'pse84_ns_cm33.sct' and 'pse84_ns_cm55.sct'
* To set stack size in application add makefile ldflags: --predefine="-DAPP_MSP_STACK_SIZE=< CUSTOM_VALUE >"
* Remaining free RAM is used as heap.
*
* \subsubsection group_system_config_heap_stack_config_iar_edge IAR
* The stack and heap sizes are defined in the linker script file: 'pse84_s_cm33.icf', 'pse84_ns_cm33.icf' and 'pse84_ns_cm55.icf'
* To set stack size in application add makefile ldflags: --config_def APP_MSP_STACK_SIZE=< CUSTOM_VALUE >
* Remaining free RAM is used as heap.
*
* \subsubsection group_system_config_heap_stack_config_llvm_edge LLVM ARM
* The stack and heap sizes are defined in the linker script file: 'pse84_s_cm33.ld', 'pse84_ns_cm33.ld' and 'pse84_ns_cm55.ld'
* To set stack size in application add makefile ldflags: -Wl,--defsym=APP_MSP_STACK_SIZE=< CUSTOM_VALUE >
* Remaining free RAM is used as heap.
*
* \subsection group_system_config_default_handlers_edge Default Interrupt Handlers Definition
* The default interrupt handler functions are dummy handler in the startup file.\n
* Below is the default handler for the non-secure interrupts:\n
* \code interrupt_type void InterruptHandler(void) {
*    while(1);
* } \endcode
*
* \subsection group_system_config_device_vector_table_edge Vectors Table Copy from Flash to RAM
* This process uses memory sections defined in the linker script. The startup code copies the
* default vector table contents to the non-secure SRAM region specified by the linker script.
* APIs are provided in the sysint driver to hook user implemented handler replacing the default
* handler for the corresponding interrupt.
*
* Following tables provide the address of the default and non-secure SRAM interrupt vector
* table for different supported compilers.
* The linker script file is 'pse84_ns_cm33.ld'.
* For non-secure world, it uses the following variable.\n
*       Copy interrupt vectors from ROM/flash to RAM: \n
*       From: \code __ns_vector_table \endcode
*       To:   \code __ns_vector_table_rw \endcode
* The vector table address (and the vector table itself) are defined in the
* ns_start_<device>.c startup file corresponding to non-secure world.
* The code in these files copies the vector table from Flash to RAM.
*
* \defgroup group_system_config_macro_edge Macros
* \{
*   \defgroup group_system_config_system_macro_edge System Macros
*   \defgroup group_system_config_core_status_macro_edge Core Status Macros
*   \defgroup group_system_config_user_settings_macro_edge User Settings Macros
* \}
* \defgroup group_system_config_enum_edge Enumerated Types
* \{
*   \defgroup group_system_enums APPCPU Debug mode Enumerated Types
* \}
* \defgroup group_system_config_functions_edge Functions
* \{
*   \defgroup group_system_config_cm33_functions_edge Cortex-M33 Control Functions
*   \defgroup group_system_config_cm55_functions_edge Cortex-M55 Control Functions
* \}
* \defgroup group_system_config_globals_edge Global Variables
*/

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
* Include files
*******************************************************************************/
#include <stdint.h>


/*******************************************************************************
* Global preprocessor symbols/macros ('define')
*******************************************************************************/
/**
* \addtogroup group_system_config_system_macro_edge
* \{
*/

/** The Cortex-M33 startup driver identifier */
#define CY_STARTUP_M33_ID               ((uint32_t)((uint32_t)((0x10U) & 0x3FFFU) << 18U))

/** The Cortex-M55 startup driver identifier */
#define CY_STARTUP_M55_ID               ((uint32_t)((uint32_t)((0x11U) & 0x3FFFU) << 18U))

/** \} group_system_config_system_macro_edge */

/**
* \addtogroup group_system_config_functions_edge
* \{
*/

/** Initializes the system.
  *
  * Custom steps can be added to this process by overrding the weak Cy_SystemInit() function.
  */
extern void SystemInit(void);

/** Update information about system clocks.
 *
 * Gets core clock frequency and updates \ref SystemCoreClock,
 * and \ref cy_AhbFreqHz.
 *
 * Updates global variables used by the Cy_SysLib_Delay(),
 * Cy_SysLib_DelayUs(), and Cy_SysLib_DelayCycles().
 */
extern void SystemCoreClockUpdate(void);

/** Populates system clock frequency variables with the provided values.
 * Sets the startup clock frequencies of \ref SystemCoreClock,
 * and \ref cy_AhbFreqHz variables.
 *
 * \param systemCoreClk_freq_hz
 * Frequency in Hz for the System Core Clock (e.g. Cortex-M33)
 *
 * \param ahb_freq_hz
 * Frequency in Hz of the AHB source
 *
 * \note This API does not take into account any run-time clock frequency updates.
 * Should any updates occur, \ref SystemCoreClockUpdate must be called afterwards
 * on the CM33_NS and CM55.
 */
extern void SystemCoreClockSetup (uint32_t systemCoreClk_freq_hz, uint32_t ahb_freq_hz);

/** Performs custom system initialization.
  *
  * The function is called during device startup. This is a weak function that
  * by default does nothing. It can be overridden to add custom steps to SystemInit
  */
extern void Cy_SystemInit(void);

/** \} group_system_config_functions_edge */

/** \cond INTERNAL */
extern uint32_t cy_delayFreqHz;
extern uint32_t cy_delayFreqKhz;
extern uint32_t cy_delayFreqMhz;
/** \endcond */


/** \addtogroup group_system_config_globals_edge
* \{
*/
/**
* Holds the system core clock, which is the system clock frequency supplied
* to the SysTick timer and the processor core clock.
* This variable implements the CMSIS Core global variable.
* Refer to the [CMSIS documentation]
* (http://www.keil.com/pack/doc/CMSIS/Core/html/group__system__init__gr.html "System and Clock Configuration")
* for more details.
* This variable can be used by debuggers to query the frequency
* of the debug timer or to configure the trace clock speed.
*
* \attention Compilers must be configured to avoid removing this variable in case
* the application program is not using it. Debugging systems require the variable
* to be physically present in memory so that it can be examined to configure the debugger. */
extern uint32_t SystemCoreClock;

/** Holds the AHB frequency. Updated by \ref SystemCoreClockUpdate(). */
extern uint32_t cy_AhbFreqHz;

/** Holds the flag to indicate if the System woke up from Warm Boot or not */
extern bool cy_WakeupFromWarmBootStatus;

/** \} group_system_config_globals_edge */

/** \} group_system_config_psoc_edge */

#ifdef __cplusplus
}
#endif

#endif /* _SYSTEM_PSE84_H_ */


/* [] END OF FILE */
