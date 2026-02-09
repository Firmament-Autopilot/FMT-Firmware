/***************************************************************************//**
* \file cy_ppc.h
* \version 1.10
*
* \brief
* The header file of the PPC driver.
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
* \addtogroup group_ppc
* \{
* The Peripheral Protection Controller (PPC) is a hardware block designed to enforce security policies
* for peripheral access, utilizing Protection Contexts (PC) and ARM TrustZone-M technology.
*
* The PPC monitors transactions initiated by bus masters to peripheral regions, checking the security attributes
* of each transaction against the configured access policies. If a transaction violates the security configuration
* (for example, a non-secure master attempts to access a secure peripheral), the PPC blocks the transaction,
* preventing unauthorized access and helping to maintain system integrity. The response on transaction can be configured
* to be either Read Zero/Write Ignore or Bus Error.
*
* Security attributes for bus masters are configured by the Master Security Control (MSC). The PPC complements
* this by allowing fine-grained control over peripheral regions, supporting both secure and non-secure access,
* as well as privilege levels. Protection Contexts provide additional flexibility, enabling multiple levels of
* access control beyond the basic secure/non-secure distinction.
*
* Up to 1024 regions can be protected by the PPC. However, the configuration of the response on an access violation
* is only available at the PPC instance level. Therefore, every region associated with a given PPC instance will have
* the same response type for access violations.
*
* The PPC driver provides APIs to configure the security attributes, privilege levels, and protection context masks
* for peripheral regions. These APIs allows:
* - Set a peripheral region as secure or non-secure
* - Configure privilege access for secure and non-secure regions
* - Set protection context masks to restrict access based on the current context
* - Lock configuration to prevent further changes until a system reset
*
* All functions and declarations for PPC configuration are provided in cy_ppc.h.
* For ModusToolbox users, including cy_pdl.h will provide access to all Peripheral Driver Library (PDL) functions.
*
* This driver is typically used in applications that require robust security, such as IoT devices, secure boot,
* and systems with multiple privilege levels or secure/non-secure partitions.
*
* \section group_ppc_more_information More Information
*
* For detailed information on the PPC hardware and its configuration, refer to the device's
* Technical Reference Manual (TRM) and ARM TrustZone-M documentation.
*
* \section group_ppc_MISRA MISRA-C Compliance
* The PPC driver does not have any specific MISRA-C deviations.
*
* \defgroup group_ppc_macros Macros
* \defgroup group_ppc_functions Functions
* \defgroup group_ppc_data_structures Data Structures
* \defgroup group_ppc_enums Enumerated Types
*/

#if !defined (CY_PPC_H)
#define CY_PPC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_device_headers.h"
#include "cy_device.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined (CY_IP_M33SYSCPUSS)

/**
* \addtogroup group_ppc_macros
* \{
*/
/** The PPC driver identifier */
/** PPC driver ID */
#define CY_PPC_ID                      (CY_PDL_DRV_ID(0x61U))
/** Driver major version */
#define CY_PPC_DRV_VERSION_MAJOR       1
/** Driver minor version */
#define CY_PPC_DRV_VERSION_MINOR       0
/** PPC region mask */
#define CY_PPC_DRV_REGION_MASK         (0x00FFFFFFU)
/** PPC region mask */
#define CY_PPC_DRV_BLOCK_MASK          (0xF0000000U)
/** PPC region mask */
#define CY_PPC_DRV_BLOCK_SHIFT         (28U)
/** PPC region number extraction */
#define CY_PPC_DRV_REGION_EXTRACT(a)   (((uint32_t)a) & CY_PPC_DRV_REGION_MASK)
/** PPC region number extraction */
#define CY_PPC_DRV_BLOCK_EXTRACT(a)    ((((uint32_t)a) & CY_PPC_DRV_BLOCK_MASK) >> CY_PPC_DRV_BLOCK_SHIFT)
/** \} group_ppc_macros */

/**
* PPC Driver error codes
*/
/**
* \addtogroup group_ppc_enums
* \{
*/
/** PPC API return status */
typedef enum
{
    CY_PPC_SUCCESS       = 0x00U,                                   /**< Returned successful */
    CY_PPC_BAD_PARAM     = CY_PPC_ID | CY_PDL_STATUS_ERROR | 0x01U, /**< Bad parameter was passed */
} cy_en_ppc_status_t;

/** PPC response configuration */
typedef enum
{
    CY_PPC_RZWI     = 0, /**< Read Zero and Write ignore */
    CY_PPC_BUS_ERR  = 1  /**< Generate bus error  */
} cy_en_ppc_resp_cfg_t;


/** PPC security attributes */
typedef enum
{
    CY_PPC_SECURE     = 0, /**< PPC region is Secure */
    CY_PPC_NON_SECURE = 1  /**< PPC region is Non-secure */
} cy_en_ppc_sec_attribute_t;


/** PPC Secure privilege attributes */
typedef enum
{
    CY_PPC_PRIV       = 0,    /**< Privilege access to secure/non-secure region */
    CY_PPC_NONPRIV    = 1,    /**< Privilege/non-privilege access to secure/non-secure region  */
} cy_en_ppc_priv_attribute_t;

/** \} group_ppc_enums */

/**
* \addtogroup group_ppc_data_structures
* \{
*/


/** PPC attribute initialization structure */
typedef struct
{
    uint32_t pcMask;                                /**< Protection Context mask */
    cy_en_ppc_sec_attribute_t secAttribute;         /**< Security attribute */
    cy_en_ppc_priv_attribute_t privAttribute;       /**< Privilege attribute */
} cy_stc_ppc_attribute_t;

/** PPC domains configuration structure */
typedef struct {
    const cy_en_prot_region_t* regions;        /**< Pointer to the array of regions for the domain */
    uint32_t region_count;                     /**< Number of regions in the regions array */
    const cy_stc_ppc_attribute_t* cfg;         /**< Pointer to the PPC attribute configuration for the domain */
} cy_stc_ppc_cfg_t;

/** \} group_ppc_data_structures */

/**
* \addtogroup group_ppc_functions
* \{
*/
cy_en_ppc_status_t Cy_Ppc_InitPpc(PPC_Type* base, const cy_en_ppc_resp_cfg_t ppcResponse);
cy_en_ppc_status_t Cy_Ppc_ConfigAttrib(PPC_Type* base, const cy_en_prot_region_t region, const cy_stc_ppc_attribute_t* attribute);
cy_en_ppc_status_t Cy_Ppc_SetPcMask(PPC_Type* base, const cy_en_prot_region_t region, uint32_t pcMask);

/*******************************************************************************
* Function Name: Cy_Ppc_GetLockMask
****************************************************************************//**
*
* \brief Reads the lock mask value for the referenced PPC
*
*
* \param base
* Base address of PPC being configured
*
* \return
* Mask value read
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Ppc_GetLockMask(const PPC_Type* base)
{
    return base->LOCK_MASK;
}

/*******************************************************************************
* Function Name: Cy_Ppc_Lock
****************************************************************************//**
*
* \brief Sets the lock for the referenced PPC
*
*
* \param base
* Base address of ppc being configured
*
* \return
* Initialization status
*
*******************************************************************************/
__STATIC_INLINE cy_en_ppc_status_t Cy_Ppc_Lock(PPC_Type* base)
{
    base->LOCK_MASK = 0xFFFFFFFFU;
    return CY_PPC_SUCCESS;
}

/** \} group_ppc_functions */


#if defined(__cplusplus)
}
#endif

#endif

#endif /* #if !defined (CY_PPC_H) */

/** \} group_flash */


/* [] END OF FILE */
