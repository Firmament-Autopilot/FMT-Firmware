/***************************************************************************//**
* \file cy_autanalog_common.h
* \version 2.0
*
* \brief
* The header file with common definitions for the Autonomous Analog driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2022-2025 Infineon Technologies AG or an affiliate of
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


#if !defined(CY_AUTANALOG_COMMON_H)
#define CY_AUTANALOG_COMMON_H

#include "cy_device.h"

#ifdef CY_IP_MXS22LPPASS

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_macros
* \{
*/

/** Driver major version */
#define CY_AUTANALOG_DRV_VERSION_MAJOR                      2

/** Driver minor version */
#define CY_AUTANALOG_DRV_VERSION_MINOR                      0

/** The driver identifier for the Autonomous Analog driver */
#define CY_AUTANALOG_ID                                     CY_PDL_DRV_ID(0x76UL)

/** \cond INTERNAL */

/* One instance of the FIFO tied to the SAR ADC is currently supported */
#ifdef SAR_BASE
#define CY_IP_MXS22LPPASS_FIFO                              (1u)
#define PASS_NR_FIFOS                                       (1u)
#endif

/* Number of CTBs */
#define CY_AUTANALOG_CTB_IDX(value)                         ((value) < PASS_NR_CTBLS)

/* Number of PTCs */
#define CY_AUTANALOG_PTCOMP_IDX(value)                      ((value) < PASS_NR_PTCS)

/* Number of DACs */
#define CY_AUTANALOG_DAC_IDX(value)                         ((value) < PASS_NR_DACS)

/* Number of SARs */
#define CY_AUTANALOG_SAR_IDX(value)                         ((value) < PASS_NR_SARS)

/* Number of FIFOs */
#define CY_AUTANALOG_FIFO_IDX(value)                        ((value) < PASS_NR_FIFOS)

/** \endcond */

/** \} group_autanalog_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_enums
* \{
*/

/**
* The sub-systems of the Autonomous Analog driver
*/
typedef enum
{
    CY_AUTANALOG_CTB   = 0UL, /**< The CTB subsystem. */
    CY_AUTANALOG_PTC   = 1UL, /**< The PTComp subsystem. */
    CY_AUTANALOG_DAC   = 2UL, /**< The DAC subsystem. */
    CY_AUTANALOG_SAR   = 3UL, /**< The SAR subsystem. */
    CY_AUTANALOG_FIFO  = 4UL, /**< The FIFO subsystem. */

} cy_en_autanalog_subsystem_id_t;

/** Return the status for functions of the Autonomous Analog driver */
typedef enum
{
    CY_AUTANALOG_SUCCESS         = 0x00UL,                                           /**< Initialization completed successfully */
    CY_AUTANALOG_BAD_PARAM       = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0000UL, /**< The Autonomous Analog driver error:
                                                                                      *   input pointer was NULL and
                                                                                      *   initialization could not be completed
                                                                                      */
    CY_AUTANALOG_PRB_BAD_PARAM    = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0001UL, /**< PRB subsystem error */
    CY_AUTANALOG_AC_BAD_PARAM     = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0002UL, /**< AC subsystem error */
    CY_AUTANALOG_CTB_BAD_PARAM    = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0004UL, /**< CTB subsystem error */
    CY_AUTANALOG_PTCOMP_BAD_PARAM = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0008UL, /**< PTComp subsystem error */
    CY_AUTANALOG_DAC_BAD_PARAM    = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0010UL, /**< DAC subsystem error */
    CY_AUTANALOG_SAR_BAD_PARAM    = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0020UL, /**< SAR subsystem error */
    CY_AUTANALOG_FIFO_BAD_PARAM   = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0040UL, /**< FIFO subsystem error */
    CY_AUTANALOG_ENABLE_ERR       = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0080UL, /**< The infrastructure error when enabling
                                                                                       *   the Autonomous Analog peripheral */
    CY_AUTANALOG_TRIMM_ERR        = CY_AUTANALOG_ID | CY_PDL_STATUS_ERROR | 0x0100UL, /**< The infrastructure error when reading
                                                                                       *   trimming values */
} cy_en_autanalog_status_t;

/** \cond INTERNAL */

/**
 * The group of start-up/settling delays for subsystems of the Autonomous Analog.
 */
typedef enum
{
    CY_AUTANALOG_PRIORITY_GROUP0 = 0UL,
    CY_AUTANALOG_PRIORITY_GROUP1 = 1UL,
    CY_AUTANALOG_PRIORITY_GROUP2 = 2UL,
    CY_AUTANALOG_PRIORITY_GROUP3 = 3UL,

} cy_en_autanalog_priority_group_t;

/** \endcond */

/** \} group_autanalog_enums */


/** \cond INTERNAL */

/*******************************************************************************
* Function Name: Cy_AutAnalog_IdxToBaseAddr
****************************************************************************//**
*
* Converting index of the subsystem into base address for this particular subsystem
* in the MMIO registers.
*
* \param subSystem
* Identifier for addressing subsystem within Low Power Peripheral Analog System,
* \ref cy_en_autanalog_subsystem_id_t.
*
* \param subSystemIdx
* Subsystem block index within Low Power Peripheral Analog System.
*
* \param baseAddr
* Pointer to base address for this subsystem in the MMIO registers.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_autanalog_status_t Cy_AutAnalog_IdxToBaseAddr(cy_en_autanalog_subsystem_id_t subSystem, uint8_t subSystemIdx, uint32_t * baseAddr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_BAD_PARAM;

    if (NULL != baseAddr)
    {
        switch (subSystem)
        {
#ifdef CY_IP_MXS22LPPASS_CTB
            case CY_AUTANALOG_CTB:
                /* Debug mode */
                CY_ASSERT_L1(CY_AUTANALOG_CTB_IDX(subSystemIdx));
                /* Release mode */
                if (CY_AUTANALOG_CTB_IDX(subSystemIdx))
                {
#ifdef CTBL0_BASE
                   if (0U == subSystemIdx)
                   {
                       *baseAddr = CTBL0_BASE;
                       result = CY_AUTANALOG_SUCCESS;
                   }
#endif
#ifdef CTBL1_BASE
                   if (1U == subSystemIdx)
                   {
                       *baseAddr = CTBL1_BASE;
                       result = CY_AUTANALOG_SUCCESS;
                   }
#endif
                }
            break;
#endif

#ifdef CY_IP_MXS22LPPASS_PTC
            case CY_AUTANALOG_PTC:
                /* Debug mode */
                CY_ASSERT_L1(CY_AUTANALOG_PTCOMP_IDX(subSystemIdx));
                /* Release mode */
                if (CY_AUTANALOG_PTCOMP_IDX(subSystemIdx))
                {
#ifdef PTC_BASE
                    *baseAddr = PTC_BASE;
                    result = CY_AUTANALOG_SUCCESS;
#endif
                }
            break;
#endif

#ifdef CY_IP_MXS22LPPASS_DAC
            case CY_AUTANALOG_DAC:
                /* Debug mode */
                CY_ASSERT_L1(CY_AUTANALOG_DAC_IDX(subSystemIdx));
                /* Release mode */
                if (CY_AUTANALOG_DAC_IDX(subSystemIdx))
                {
#ifdef DAC0_BASE
                   if (0U == subSystemIdx)
                   {
                       *baseAddr = DAC0_BASE;
                       result = CY_AUTANALOG_SUCCESS;
                   }
#endif
#ifdef DAC1_BASE
                   if (1U == subSystemIdx)
                   {
                       *baseAddr = DAC1_BASE;
                       result = CY_AUTANALOG_SUCCESS;
                   }
#endif
                }
            break;
#endif

#ifdef CY_IP_MXS22LPPASS_SAR
            case CY_AUTANALOG_SAR:
                /* Debug mode */
                CY_ASSERT_L1(CY_AUTANALOG_SAR_IDX(subSystemIdx));
                /* Release mode */
                if (CY_AUTANALOG_SAR_IDX(subSystemIdx))
                {
#ifdef SAR_BASE
                    *baseAddr = SAR_BASE;
                    result = CY_AUTANALOG_SUCCESS;
#endif
                }
            break;
#endif

#ifdef CY_IP_MXS22LPPASS_FIFO
            case CY_AUTANALOG_FIFO:
                /* Debug mode */
                CY_ASSERT_L1(CY_AUTANALOG_FIFO_IDX(subSystemIdx));
                /* Release mode */
                if (CY_AUTANALOG_FIFO_IDX(subSystemIdx))
                {
#ifdef LPPASS_MMIO_BASE
                    *baseAddr = LPPASS_MMIO_BASE;
                    result = CY_AUTANALOG_SUCCESS;
#endif
                }
            break;
#endif

            default:
                CY_ASSERT_L1(false);
            break;
        }
    }

    return result;
}

/** \endcond */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS */

#endif /** !defined(CY_AUTANALOG_COMMON_H) */

/* [] END OF FILE */
