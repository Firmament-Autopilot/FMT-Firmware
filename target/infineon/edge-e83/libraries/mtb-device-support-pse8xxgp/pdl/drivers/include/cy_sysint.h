/***************************************************************************//**
* \file cy_sysint.h
* \version 1.130
*
* \brief
* Provides an API declaration of the SysInt driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2016-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
*
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


/**
* \addtogroup group_sysint
* \{
* The SysInt driver provides an API to configure the device peripheral interrupts.
* It provides a lightweight interface to complement
* the <a href="https://www.keil.com/pack/doc/CMSIS/Core/html/group__NVIC__gr.html">CMSIS core NVIC API</a>.
* The provided functions are applicable for all cores in a device and they can
* be used to configure and connect device peripheral interrupts to one or more
* cores.
*
* The functions and other declarations used in this driver are in cy_sysint.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* \section group_sysint_vector_table Vector Table
*
 * \subsection group_sysint_CM33 CM33
* CM33 with Security extension supports two vector tables, one for secure world and another
* for non-secure world. Secure interrupt vector table is placed in the secure ROM/FLASH, where as
* non-secure interrupt vector table is placed in the non-secure ROM/FLASH. In both scenarios,
* vector tables are copied by the startup code to secure and non-secure RAM respectively.
* The symbol code __s_vector_table is the address of the secure vector table and
* __ns_vector_table is for the non-secure world in the startup code. The register SCB->VTOR
* holds the start address of the vector table. See \ref group_system_config_device_vector_table
* section for the implementation details.
*
* \note Because the IAR compiler expects the vector table to be defined as __vector_table, when
* compiling with IAR, both the __ns_vector_table and __s_vector_table symbols are aliased to instead
* be defined as __vector_table. The generated .map files per project will contain no references to
* __ns_vector_table or __s_vector_table, but will instead contain references to __vector_table. The
* project containing the .map file will still indicate which vector table (secure or non-secure) is
* being used in that project. i.e. proj_cm33_s.map's __vector_table would refer to the secure vector table.
*
* CM33 without Security extension will support only non-secure interrupts.
*
* The default interrupt handler functions are defined to a dummy handler in the startup file.
* The naming convention is \<interrupt_name\>_IRQHandler.
*
* \subsection group_sysint_CM55 CM55
* CM55 is without Security extension and will support only non-secure interrupts. It is similar to CM33 non-secure part.
* Additionally CM55 core has support to block EWIC (External Wakeup Interrupt Controller). EWIC is a peripheral to the processor
* and it can be a source of wakeup in the system. EWIC block is disabled by default and needs to be enabled in order for the DS
* wakeup source to work.
*
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_Init
*
* \section group_sysint_driver_usage Driver Usage
*
* \subsection group_sysint_initialization Initialization
*
* Interrupt numbers are defined in a device-specific header file, such as
* cy_device_headers.h, and are consistent with interrupt handlers defined in the
* vector table.
*
* To configure an interrupt, call Cy_SysInt_Init(). Populate
* the configuration structure (cy_stc_sysint_t) and pass it as a parameter
* along with the ISR address. This initializes the interrupt and
* instructs the CPU to jump to the specified ISR vector upon a valid trigger.
*
* For CM33/CM55 core, system interrupt source 'n' is connected to the
* corresponding IRQn. Deep-sleep capable interrupts are allocated to Deep Sleep
* capable IRQn channels.
*
*
* \subsection group_sysint_enable Enable
*
* After initializing an interrupt, use the CMSIS Core
* <a href="https://www.keil.com/pack/doc/CMSIS/Core/html/group__NVIC__gr.html#ga530ad9fda2ed1c8b70e439ecfe80591f">NVIC_EnableIRQ()</a> function
* to enable it. Given an initialization structure named config,
* the function should be called as follows:
* \code
* NVIC_EnableIRQ(config.intrSrc)
* \endcode
*
* \subsection group_sysint_service Writing an interrupt service routine
*
* Servicing interrupts in the Peripheral Drivers should follow a prescribed
* recipe to ensure all interrupts are serviced and duplicate interrupts are not
* received. Any peripheral-specific register that must be written to clear the
* source of the interrupt should be written as soon as possible in the interrupt
* service routine. However, note that due to buffering on the output bus to the
* peripherals, the write clearing of the interrupt may be delayed. After performing
* the normal interrupt service that should respond to the interrupting
* condition, the interrupt register that was initially written to clear the
* register should be read before returning from the interrupt service routine.
* This read ensures that the initial write has been flushed out to the hardware.
* Note, no additional processing should be performed based on the result of this
* read, as this read is intended only to ensure the write operation is flushed.
*
* This final read may indicate a pending interrupt. What this means is that in
* the interval between when the write actually happened at the peripheral and
* when the read actually happened at the peripheral, an interrupting condition
* occurred. This is ok and a return from the interrupt is still the correct
* action. As soon as conditions warrant, meaning interrupts are enabled and
* there are no higher priority interrupts pending, the interrupt will be
* triggered again to service the additional condition.
*
*
* \section group_sysint_more_information More Information
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_sysint_macros Macros
* \defgroup group_sysint_functions Functions
* \defgroup group_sysint_data_structures Data Structures
* \defgroup group_sysint_enums Enumerated Types
*/


#if !defined (CY_SYSINT_H)
#define CY_SYSINT_H

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS) || defined (CY_IP_M4CPUSS) || defined (CY_IP_M7CPUSS) || defined(CY_IP_M55APPCPUSS)

#include <stddef.h>
#include "cy_syslib.h"
 #include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*       Global Variable
***************************************/



/***************************************
*       Global Interrupt
***************************************/

/**
* \addtogroup group_sysint_macros
* \{
*/

/** Driver major version */
#define CY_SYSINT_DRV_VERSION_MAJOR    1

/** Driver minor version */
#define CY_SYSINT_DRV_VERSION_MINOR    130

/** SysInt driver ID */
#define CY_SYSINT_ID CY_PDL_DRV_ID     (0x15U)

#if !defined(CY_IP_M7CPUSS)  /* Applicable for Mux'ed IRQ CM4 interrupts */
#define CY_SYSINT_INTRSRC_MASK           (0x0FFFUL)  /**< Bit 0-11 indicate system interrupt and bit 12-15 will indicate the CPU IRQ */
#define CY_SYSINT_INTRSRC_MUXIRQ_SHIFT   (12UL)      /**< Bit 0-11 indicate system interrupt and bit 12-15 will indicate the CPU IRQ */
#endif /* defined (CY_IP_M7CPUSS) */

/** \} group_sysint_macros */


/***************************************
*       Enumeration
***************************************/

/**
* \addtogroup group_sysint_enums
* \{
*/

/**
* SysInt Driver error codes
*/
typedef enum
{
    CY_SYSINT_SUCCESS   = 0x0UL,                                      /**< Returned successful */
    CY_SYSINT_BAD_PARAM = CY_SYSINT_ID | CY_PDL_STATUS_ERROR | 0x1UL, /**< Bad parameter was passed */
} cy_en_sysint_status_t;

/** NMI connection input */
typedef enum
{
    CY_SYSINT_NMI1       = 1UL, /**< NMI source input 1 */
    CY_SYSINT_NMI2       = 2UL, /**< NMI source input 2 */
    CY_SYSINT_NMI3       = 3UL, /**< NMI source input 3 */
    CY_SYSINT_NMI4       = 4UL, /**< NMI source input 4 */
} cy_en_sysint_nmi_t;

/** \} group_sysint_enums */


/***************************************
*       Configuration Structure
***************************************/

/**
* \addtogroup group_sysint_data_structures
* \{
*/

/**
* Initialization configuration structure for a single interrupt channel
*/
typedef struct {
#if !defined(CY_IP_M7CPUSS)
    IRQn_Type       intrSrc;        /**< Interrupt source */
#endif
      uint32_t        intrPriority;   /**< Interrupt priority number (Refer to __NVIC_PRIO_BITS) */
} cy_stc_sysint_t;

/** \} group_sysint_data_structures */


/***************************************
*              Constants
***************************************/

/** \cond INTERNAL */

    #define CY_INT_IRQ_BASE            (16U)    /**< Start location of interrupts in the vector table */
    #define CY_SYSINT_STATE_MASK       (1UL)    /**< Mask for interrupt state */
    #define CY_SYSINT_STIR_MASK        (0xFFUL) /**< Mask for software trigger interrupt register */
    #define CY_SYSINT_DISABLE          (0UL)    /**< Disable interrupt */
    #define CY_SYSINT_ENABLE           (1UL)    /**< Enable interrupt */
    #define CY_SYSINT_INT_STATUS_MSK   (0x7UL)


    /* Parameter validation macros */
    #define CY_SYSINT_IS_PRIORITY_VALID(intrPriority)     ((uint32_t)(1UL << __NVIC_PRIO_BITS) > (intrPriority))
    #define CY_SYSINT_IS_VECTOR_VALID(userIsr)            (NULL != (userIsr))
    #define CY_SYSINT_IS_NMI_NUM_VALID(nmiNum)            (((nmiNum) == CY_SYSINT_NMI1) || \
                                                           ((nmiNum) == CY_SYSINT_NMI2) || \
                                                           ((nmiNum) == CY_SYSINT_NMI3) || \
                                                           ((nmiNum) == CY_SYSINT_NMI4))
 /** \endcond */


/***************************************
*       Function Prototypes
***************************************/

/**
* \addtogroup group_sysint_functions
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysInt_Init
****************************************************************************//**
*
* \brief Initializes the referenced interrupt by setting the priority and the
* interrupt vector.
* In case of CM33 with Security Extension enabled, if this function is called
* from secure world then, the parameters are used to configure secure interrupt.
* If it is called form non-secure world then the parameters are used to configure
* non-secure interrupt. In case of CM33 without Security Extension, this function
* always configures the non-secure interrupt.
* In case of CM55, this function always configures the non-secure interrupt.
*
* Use the CMSIS core function NVIC_EnableIRQ(config.intrSrc) to enable the interrupt.
*
* \param config
* Interrupt configuration structure
*
* \param userIsr
* Address of the ISR
*
* \return
* Initialization status
*
*
 * \note CM33<br/>
* The interrupt vector will be relocated only if the vector table was
* moved to __s_vector_table_rw and __ns_vector_table_rw for secure and
* non-secure world respectively.
*
* \note CM55<br/>
* The interrupt vector will be relocated only if the vector table was
* moved to __ns_vector_table_rw non-secure world.
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_Init
*
*******************************************************************************/
cy_en_sysint_status_t Cy_SysInt_Init(const cy_stc_sysint_t* config, cy_israddress userIsr);


/*******************************************************************************
* Function Name: Cy_SysInt_SetVector
****************************************************************************//**
*
* \brief Changes the ISR vector for the interrupt.
*
 * CM33:<br/>
* When called from secure world. this function relies on the assumption that the
* vector table is relocated to __s_vector_table_rw[] in secure SRAM. Otherwise it will
* return the address of the default ISR location in the secure flash/ROM vector table.
*
* When called from non-secure world. this function relies on the assumption that
* the vector table is relocated to __ns_vector_table_rw[] in non-secure SRAM.
* Otherwise it will return the address of the default ISR location in the non-secure
* flash/ROM vector table.
*
* CM55:<br/>
* This function relies on the assumption that
* the vector table is relocated to __ns_vector_table_rw[] in non-secure SRAM.
* Otherwise it will return the address of the default ISR location in the non-secure
* flash/ROM vector table.
*
* Use the CMSIS core function NVIC_EnableIRQ(config.intrSrc) to enable the interrupt.
* \param IRQn
* Interrupt source
*
* \param userIsr
* Address of the ISR to set in the interrupt vector table
*
* \return
 * Previous address of the ISR in the interrupt vector table
*
*
 * \note In case of CM33 with Security Extension enabled, if this function is called
* from secure world then, it sets the interrupt vector for the secure world.
* If it is called form non-secure world then it sets the interrupt vector for the
* non-secure world.
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_SetVector
*
*******************************************************************************/
cy_israddress Cy_SysInt_SetVector(IRQn_Type IRQn, cy_israddress userIsr);


/*******************************************************************************
* Function Name: Cy_SysInt_GetVector
****************************************************************************//**
*
* \brief Gets the address of the current ISR vector for the interrupt.
*
*
*
 * CM33:<br/>
* When called from the secure world, this function relies on the assumption that
* the vector table is relocated to __ns_vector_table_rw[] in non-secure SRAM.
* Otherwise it will return the address of the default ISR location in the
* flash/ROM vector table.
*
* CM55:<br/>
* This function relies on the assumption that
* the vector table is relocated to __ns_vector_table_rw[] in non-secure SRAM.
* Otherwise it will return the address of the default ISR location in the
* flash/ROM vector table.
*
* \param IRQn
* Interrupt source
*
* \return
* Address of the ISR in the interrupt vector table
*
*
 * \note In case of CM33 with Security Extension enabled, if this function is called
* from secure world then, it sets the interrupt vector for the secure world.
* If it is called form non-secure world then it sets the interrupt vector for the
* non-secure world.
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_SetVector
*
*******************************************************************************/
cy_israddress Cy_SysInt_GetVector(IRQn_Type IRQn);





/***************************************
*           Functions
***************************************/

/*******************************************************************************
* Function Name: Cy_SysInt_SetNmiSource
****************************************************************************//**
*
* \brief Sets the interrupt source of the CPU core NMI.
*
* The interrupt source must be a positive number. Setting the value to
* "unconnected_IRQn" or "disconnected_IRQn" disconnects the interrupt source
* from the NMI. Depending on the device, the number of interrupt sources that
* can provide the NMI trigger signal to the core can vary.
*
* \param nmiNum
* NMI source number.
* CPUSS_ver2 allows up to 4 sources to trigger the core NMI.
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_SetNmiSource
*
*******************************************************************************/

void Cy_SysInt_SetNmiSource(cy_en_sysint_nmi_t nmiNum, IRQn_Type intrSrc);

/*******************************************************************************
* Function Name: Cy_SysInt_GetIntSourceNMI
****************************************************************************//**
*
* \brief Gets the interrupt source of the CPU core NMI for the given NMI source
* number.
*
* \param nmiNum
* NMI source number.
* CPUSS_ver2 allows up to 4 sources to trigger the core NMI (i.e. #1, 2, 3, 4).
*
* \return
* Interrupt Source.
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_SetNmiSource
*
*******************************************************************************/
IRQn_Type Cy_SysInt_GetNmiSource(cy_en_sysint_nmi_t nmiNum);

/*******************************************************************************
* Function Name: Cy_SysInt_SoftwareTrig
****************************************************************************//**
*
* \brief Triggers an interrupt using software (Not applicable for CM0+).
*
* \param IRQn
* Interrupt source
*
* \funcusage
* \snippet sysint/snippet/main.c snippet_Cy_SysInt_SoftwareTrig
*
* \note Only privileged software can enable unprivileged access to the
* Software Trigger Interrupt Register (STIR). This function is not available for devices with an M7 CPU.
*
*******************************************************************************/
void Cy_SysInt_SoftwareTrig(IRQn_Type IRQn);


/** \} group_sysint_functions */

/** \cond INTERNAL */

/***************************************
*       Deprecated functions
***************************************/

/*******************************************************************************
* Function Name: Cy_SysInt_GetState
****************************************************************************//**
*
* This function is deprecated. It invokes the NVIC_GetEnableIRQ() function.
*
*******************************************************************************/
#define Cy_SysInt_GetState NVIC_GetEnableIRQ


/*******************************************************************************
* Function Name: Cy_SysInt_SetIntSource
****************************************************************************//**
*
* This function is deprecated. It invokes the Cy_SysInt_SetInterruptSource() function.
*
*******************************************************************************/
#define Cy_SysInt_SetIntSource(intrSrc, devIntrSrc) Cy_SysInt_SetInterruptSource(intrSrc, devIntrSrc)


/*******************************************************************************
* Function Name: Cy_SysInt_GetIntSource
****************************************************************************//**
*
* This function is deprecated. It invokes the Cy_SysInt_GetInterruptSource() function.
*
*******************************************************************************/
#define Cy_SysInt_GetIntSource(intrSrc) Cy_SysInt_GetInterruptSource(intrSrc)


/*******************************************************************************
* Function Name: Cy_SysInt_SetIntSourceNMI
****************************************************************************//**
*
* This function is deprecated. It invokes the Cy_SysInt_SetNmiSource() function.
*
*******************************************************************************/
#define Cy_SysInt_SetIntSourceNMI(srcParam) Cy_SysInt_SetNmiSource(CY_SYSINT_NMI1, srcParam)


/*******************************************************************************
* Function Name: Cy_SysInt_GetIntSourceNMI
****************************************************************************//**
*
* This function is deprecated. It invokes the Cy_SysInt_GetNmiSource() function.
*
*******************************************************************************/
#define Cy_SysInt_GetIntSourceNMI() Cy_SysInt_GetNmiSource(CY_SYSINT_NMI1)

/** \endcond */

#if defined(__cplusplus)
}
#endif

#endif /* defined (CY_IP_M33SYSCPUSS) || defined (CY_IP_M4CPUSS) || defined (CY_IP_M7CPUSS) || defined(CY_IP_M55APPCPUSS) */

#endif /* CY_SYSINT_H */

/** \} group_sysint */

/* [] END OF FILE */
