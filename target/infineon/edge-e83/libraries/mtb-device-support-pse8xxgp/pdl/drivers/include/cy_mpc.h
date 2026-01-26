/***************************************************************************//**
* \file cy_mpc.h
* \version 1.1
*
* \brief
* The header file of the MPC driver.
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
* \addtogroup group_mpc
* \{
* The Memory Protection Controller (MPC) driver allows to configure memory
* regions as secure or non-secure, helping to protect sensitive data and code in the application.
*
* Key features of the MPC driver:
*
* 1. Memory Protection Controller (MPC) offers a more granular and flexible approach
* to memory configuration compared to traditional Security Attribution Unit (SAU) and
* Implementation Defined Attribution Unit (IDAU) solutions.
*
* 2. Supports ARMv8-M TrustZone-M technology, allows defining secure and non-secure
* memory regions. Secure regions are accessible only by trusted code,
* while non-secure regions are available to less trusted code.
*
* 3. Utilizes Protection Contexts (PCs) as a key component, which define the rules
* that govern access to specific memory regions.
* By configuring PCs, you can control who can read, write, or execute code in designated memory areas.
*
* 4. MPCs enables flexible memory separation and sharing, depending on your system's requirements.
* Memory separation ensures that different system components have isolated memory spaces,
* while sharing allows multiple components to access the same memory space.
*
* 5. Divides memory into fixed-size blocks. Security and access permissions for each block
* can be configured, providing fine-grained control over memory protection.
*
* The functions and other declarations used in this driver are in cy_mpc.h.
* You can include cy_pdl.h (ModusToolbox only) to get access to all functions
* and declarations in the PDL.
*
* You can use this driver to configure memory regions as secure/non-secure.
*
* \section group_mpc_more_information More Information
*
* For more information on the MPC , refer to
* the technical reference manual (TRM).
*
* \section group_mpc_MISRA MISRA-C Compliance
* The mpc driver does not have any specific deviations.
*
* \defgroup group_mpc_macros Macros
* \defgroup group_mpc_functions Functions
* \defgroup group_mpc_data_structures Data Structures
* \defgroup group_mpc_enums Enumerated Types
*/
/** \} group_mpc */


#if !defined (CY_MPC_H)
#define CY_MPC_H

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
* \addtogroup group_mpc_macros
* \{
*/
/** The MPC driver identifier */
/** MPC driver ID */
#define CY_MPC_ID                      (CY_PDL_DRV_ID(0x60U))

/** Driver major version */
#define CY_MPC_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_MPC_DRV_VERSION_MINOR       1

/** \} group_mpc_macros */

/**
* Prot Driver error codes
*/

/**
* \addtogroup group_mpc_enums
* \{
*/
/** MPC API return status */
typedef enum
{
    CY_MPC_SUCCESS       = 0x00U,                                   /**< Returned successful */
    CY_MPC_BAD_PARAM     = CY_MPC_ID | CY_PDL_STATUS_ERROR | 0x01U, /**< Bad parameter was passed */
    CY_MPC_INVALID_STATE = CY_MPC_ID | CY_PDL_STATUS_ERROR | 0x02U, /**< The operation is not setup */
    CY_MPC_FAILURE       = CY_MPC_ID | CY_PDL_STATUS_ERROR | 0x03U, /**< The resource is locked */
    CY_MPC_UNAVAILABLE   = CY_MPC_ID | CY_PDL_STATUS_ERROR | 0x04U  /**< The resource is unavailable */
} cy_en_mpc_status_t;

/** Access permission */
typedef enum
{
    CY_MPC_ACCESS_DISABLED = 0x00U, /**< Read and Write disabled */
    CY_MPC_ACCESS_R        = 0x01U, /**< Read enabled */
    CY_MPC_ACCESS_W        = 0x02U, /**< Write enabled */
    CY_MPC_ACCESS_RW       = 0x03U  /**< Read and Write enabled */
}cy_en_mpc_access_attr_t;

/** Security permission */
typedef enum
{
    CY_MPC_SECURE     = 0x0U, /**< Secure */
    CY_MPC_NON_SECURE = 0x1U  /**< Non-secure */
}cy_en_mpc_sec_attr_t;

/** MPC block size */
typedef enum
{
    CY_MPC_SIZE_32B   = 0U,  /**< 32 bytes */
    CY_MPC_SIZE_64B   = 1U,  /**< 64 bytes */
    CY_MPC_SIZE_128B  = 2U,  /**< 128 bytes */
    CY_MPC_SIZE_256B  = 3U,  /**< 256 bytes */
    CY_MPC_SIZE_512B  = 4U,  /**< 512 bytes */
    CY_MPC_SIZE_1KB   = 5U,  /**< 1 Kilobyte */
    CY_MPC_SIZE_2KB   = 6U,  /**< 2 Kilobytes */
    CY_MPC_SIZE_4KB   = 7U,  /**< 4 Kilobytes */
    CY_MPC_SIZE_8KB   = 8U,  /**< 8 Kilobytes */
    CY_MPC_SIZE_16KB  = 9U,  /**< 16 Kilobytes */
    CY_MPC_SIZE_32KB  = 10U, /**< 32 Kilobytes */
    CY_MPC_SIZE_64KB  = 11U, /**< 64 Kilobytes */
    CY_MPC_SIZE_128KB = 12U, /**< 128 Kilobytes */
    CY_MPC_SIZE_256KB = 13U, /**< 256 Kilobytes */
    CY_MPC_SIZE_512KB = 14U, /**< 512 Kilobytes */
    CY_MPC_SIZE_1MB   = 15U  /**< 1 Megabyte */
}cy_en_mpc_size_t;

/** MPC protection context */
typedef enum
{
    CY_MPC_PC_0  = 0U, /**< PC 0 */
    CY_MPC_PC_1  = 1U, /**< PC 1 */
    CY_MPC_PC_2  = 2U, /**< PC 2 */
    CY_MPC_PC_3  = 3U, /**< PC 3 */
    CY_MPC_PC_4  = 4U, /**< PC 4 */
    CY_MPC_PC_5  = 5U, /**< PC 5 */
    CY_MPC_PC_6  = 6U, /**< PC 6 */
    CY_MPC_PC_7  = 7U  /**< PC 7 */
}cy_en_mpc_prot_context_t;

/** MPC response configuration */
typedef enum
{
    CY_MPC_RZWI     = 0, /**< Read Zero and Write ignore */
    CY_MPC_BUS_ERR  = 1  /**< Generate bus error */
} cy_en_mpc_resp_cfg_t;
/** \} group_mpc_enums */

/**
* \addtogroup group_mpc_data_structures
* \{
*/
/** The OTP Control configuration structure.*/
/**
 Configuration structure for ROT (Root of Trust) MPC Struct initialization,
 used for defining a memory region that configured with this structure are
 inherently trusted and therefore secure by design.
 This structure is to used to configure protection context (PC) and specific access
 permissions for the memory region, in addition to security permission.
 Typically is used to store sensitive data, such as encryption keys,
 secure boot code, etc.
*/
typedef struct
{
    cy_en_mpc_prot_context_t pc;            /**< Protection Context */
    cy_en_mpc_sec_attr_t     secure;        /**< Security permissions for the region */
    cy_en_mpc_access_attr_t  access;        /**< Access permissions for the Protection Context */
} cy_stc_mpc_rot_cfg_t;

/**
 Configuration structure for MPC Struct initialization,
 used for memory region definition that configured with this structure are
 not inherently trusted.
 This structure is to used to configure only the security permission for the
 memory region.
 Typically used to store non-sensitive data, such as application code, data.
 */
typedef struct
{
    cy_en_mpc_sec_attr_t     secure;        /**< Security permissions for the region */
} cy_stc_mpc_cfg_t;

/** ROT MPC block attribute settings */
typedef struct {
    cy_en_mpc_sec_attr_t    secure;         /**< Security permissions for the block */
    cy_en_mpc_access_attr_t access;         /**< Access permissions for the block */
} cy_stc_mpc_rot_block_attr_t;


/** MPC block attribute settings */
typedef struct {
    cy_en_mpc_sec_attr_t    secure;         /**< Security permissions for the block */
} cy_stc_mpc_block_attr_t;

/** MPC response configuration structure */
typedef struct {
    MPC_Type*             base;          /**< Address of the MPC controller */
    cy_en_mpc_resp_cfg_t  response;      /**< Response configuration */
} cy_stc_mpc_resp_cfg_t;


/** MPC region configuration structure */
typedef struct {
    MPC_Type*          base;          /**< Address of the MPC controller */
    uint32_t           offset;        /**< Region offset within block */
    uint32_t           size;          /**< Region size */
} cy_stc_mpc_regions_t;


/** Full MPC settings structure */
typedef struct {
    const cy_stc_mpc_regions_t* regions;         /**< Pointer to the regions array */
    uint8_t                     region_count;    /**< Regions array size */
    const cy_stc_mpc_rot_cfg_t* cfg;             /**< Pointer to the settings array */
    uint8_t                     cfg_count;       /**< Settings array size  */
} cy_stc_mpc_unified_t;

/** \} group_mpc_data_structures */


/**
* \addtogroup group_mpc_functions
* \{
*/


cy_en_mpc_status_t Cy_Mpc_ConfigRotMpcStruct(MPC_Type* base, const uint32_t addOffset, const uint32_t size, const cy_stc_mpc_rot_cfg_t* rotConfig);
cy_en_mpc_status_t Cy_Mpc_ConfigMpcStruct(MPC_Type* base, const uint32_t addOffset, const uint32_t size, const cy_stc_mpc_cfg_t* config);
cy_en_mpc_status_t Cy_Mpc_GetRotBlockAttr(MPC_Type* base, const cy_en_mpc_prot_context_t pc, const uint32_t addOffset, cy_stc_mpc_rot_block_attr_t* p_block_settings);
cy_en_mpc_status_t Cy_Mpc_GetBlockAttr(MPC_Type* base, const uint32_t addOffset, cy_stc_mpc_block_attr_t* p_block_settings);

__STATIC_INLINE void Cy_Mpc_Lock(MPC_Type* base);
__STATIC_INLINE void Cy_Mpc_RotLock(MPC_Type* base);
__STATIC_INLINE void Cy_Mpc_RotAutoInc(MPC_Type* base, uint8_t control);
__STATIC_INLINE void Cy_Mpc_AutoInc(MPC_Type* base, uint8_t control);
__STATIC_INLINE cy_en_mpc_status_t Cy_Mpc_SetViolationResponse(MPC_Type* base, const cy_en_mpc_resp_cfg_t mpcResponse);

/** \} group_mpc_functions */

/*******************************************************************************
* Function Name: Cy_Mpc_Lock
****************************************************************************//**
*
* \brief Locks the MPC configuration
*
* \note To release lock system reset should be performed
*
* \param base
* Base address of MPC being configured
*
*******************************************************************************/
__STATIC_INLINE void Cy_Mpc_Lock(MPC_Type* base)
{
    base->CTRL |= _VAL2FLD(RAMC_MPC_CTRL_LOCK, 1);
}


/*******************************************************************************
* Function Name: Cy_Mpc_RotLock
****************************************************************************//**
*
* \brief Locks the MPC configuration for ROT (Root of Trust), this action cannot be undone
*
* \note To release lock system reset should be performed
*
* \param base
* Base address of mpc being configured
*
*******************************************************************************/
__STATIC_INLINE void Cy_Mpc_RotLock(MPC_Type* base)
{
    base->ROT_CTRL |= _VAL2FLD(RAMC_MPC_ROT_CTRL_LOCK, 1);
}


/*******************************************************************************
* Function Name: Cy_Mpc_RotAutoInc
****************************************************************************//**
*
* \brief Auto increment of BLK ID for ROT  (Root of Trust)
*
*
* \param base
* Base address of mpc being configured
*
* \param control
* Auto increment control
*
*******************************************************************************/
__STATIC_INLINE void Cy_Mpc_RotAutoInc(MPC_Type* base, uint8_t control)
{
    if (control == 0u)
    {
        /* reset auto_inc bit */
        base->ROT_CTRL &= ~(_VAL2FLD(RAMC_MPC_ROT_CTRL_AUTO_INC, 1u));
    }
    else
    {
        /* set auto_inc bit */
        base->ROT_CTRL |= RAMC_MPC_ROT_CTRL_AUTO_INC_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_Mpc_AutoInc
****************************************************************************//**
*
* \brief Auto increment of BLK ID
*
*
* \param base
* Base address of mpc being configured
*
* \param control
* Auto increment control
*
*******************************************************************************/
__STATIC_INLINE void Cy_Mpc_AutoInc(MPC_Type* base, uint8_t control)
{
    if (control == 0u)
    {
        /* reset auto_inc bit */
        base->CTRL &= ~(_VAL2FLD(RAMC_MPC_CTRL_AUTO_INC, 1u));
    }
    else
    {
        /* set auto_inc bit */
        base->CTRL |= RAMC_MPC_CTRL_AUTO_INC_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_Mpc_SetViolationResponse
****************************************************************************//**
*
* \brief Set MPC Violation Response
*
* \param base
* Base address of MPC being configured
*
* \param mpcResponse
* Enable/Disable MPC Response on violation
*
* \return
* API status
*
* \note Not expected to be called by user application code
*
*******************************************************************************/
__STATIC_INLINE cy_en_mpc_status_t Cy_Mpc_SetViolationResponse(MPC_Type* base, const cy_en_mpc_resp_cfg_t mpcResponse)
{
    CY_ASSERT(base != NULL);
    if (mpcResponse == CY_MPC_BUS_ERR)
    {
        /* Enable response for MPC violation */
        base->CFG |= RAMC_MPC_CFG_RESPONSE_Msk;
    }
    else
    {
        /* Disable response for MPC violation */
        base->CFG &= (~RAMC_MPC_CFG_RESPONSE_Msk);
    }

    return CY_MPC_SUCCESS;
}

#if defined(__cplusplus)
}
#endif

#endif

#endif /* #if !defined (CY_MPC_H) */

/* [] END OF FILE */
