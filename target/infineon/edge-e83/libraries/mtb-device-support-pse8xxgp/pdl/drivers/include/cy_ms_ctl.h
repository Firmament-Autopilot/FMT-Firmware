/***************************************************************************//**
* \file cy_ms_ctl.h
* \version 1.2
*
* \brief
* The header file of the MSC driver.
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
* \addtogroup group_ms_ctl
* \{
* MSC is the Master Security Controller which helps to protect the transactions
* initiated on the bus.
*
* MSC is instantiated on non-CPU paths to provide security extension attributes
* and to add TrustZone-M capability. MSC Driver provides APIs to configure
* access rights to the given master (a core, DMA, etc) for each Protection Context
* (provides a more precise way of applying memory restrictions).
* Maximum of 32 masters are supported. It also provides API to set the active PC.
*
* The functions and other declarations used in this driver are in cy_ms_ctl.h.
* You can include cy_pdl.h (ModusToolbox only) to get access to all functions
* and declarations in the PDL.
*
* You can use this driver to protect the transactions initiated on the bus.
*
* Devices support multiple CPU subsystems, viz. SYSCPUSS (Power Domain 0 powered by a
* low-power 32-bit Arm® Cortex-M33 (CM33) CPU, which handles security, control, communication)
* and APPCPUSS (Power Domain 1 powered by an Arm Cortex-M55 (CM55) processor,
* which supports M-profile vector extension (MVE), Digital Signal Processing (DSP),
* and Machine Learning (ML) capabilities).
*
* The default MSC configuration is pre-defined and can be found in the architecture TRM.
* Each subsystem has its own MSC APIs to be used within it.
*
* Following APIs are used for MSC IP in SYSCPUSS <br>
* Cy_Ms_Ctl_ConfigBusMaster <br>
* Cy_Ms_Ctl_ConfigMscAcgResp <br>
* Cy_Ms_Ctl_SetActivePC <br>
* Cy_Ms_Ctl_GetActivePC <br>
* Cy_Ms_Ctl_SetPcHandler <br>
* Cy_Ms_Ctl_GetPcHandler <br>
*
* Following APIs are used for MSC IP in APPCPUSS <br>
* Cy_Ms_Ctl_ConfigBusMasterV1 <br>
* Cy_Ms_Ctl_ConfigMscAcgRespV1 <br>
* Cy_Ms_Ctl_SetActivePCV1 <br>
* Cy_Ms_Ctl_GetActivePCV1 <br>
*
* \section group_ms_ctl_more_information More Information
*
* For more information on the MSC , refer to
* the technical reference manual (TRM).
*
* \section group_ms_ctl_MISRA MISRA-C Compliance
* The MSC driver does not have any specific deviations.
*
* \defgroup group_ms_ctl_macros Macros
* \defgroup group_ms_ctl_functions Functions
* \defgroup group_ms_ctl_enums Enumerated Types
*/

#if !defined (CY_MS_CTL_H)
#define CY_MS_CTL_H

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS) || defined(CY_DOXYGEN)

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ms_ctl_macros
* \{
*/
/** The MSC driver identifier */
/** MSC driver ID */
#define CY_MS_CTL_ID                      (CY_PDL_DRV_ID(0x62U))

/** Driver major version */
#define CY_MS_CTL_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_MS_CTL_DRV_VERSION_MINOR       2

/** \} group_ms_ctl_macros */

/**
* \addtogroup group_ms_ctl_enums
* \{
*/
/** MSC API return status */
typedef enum
{
    CY_MS_CTL_SUCCESS       = 0x00U,                                      /**< Returned successful */
    CY_MS_CTL_BAD_PARAM     = CY_MS_CTL_ID | CY_PDL_STATUS_ERROR | 0x01U, /**< Bad parameter was passed */
    CY_MS_CTL_INVALID_STATE = CY_MS_CTL_ID | CY_PDL_STATUS_ERROR | 0x02U, /**< The operation is not setup */
    CY_MS_CTL_FAILURE       = CY_MS_CTL_ID | CY_PDL_STATUS_ERROR | 0x03U, /**< The resource is locked */
    CY_MS_CTL_UNAVAILABLE   = CY_MS_CTL_ID | CY_PDL_STATUS_ERROR | 0x04U  /**< The resource is unavailable */
} cy_en_ms_ctl_status_t;

/** Bus masters */
typedef enum
{
    CY_MS_CTL_ID_CM33_0            = 0,  /**< Cortex M33 CPU-0 */
    CY_MS_CTL_ID_CM33_1            = 1,  /**< Cortex M33 CPU-1 */
    CY_MS_CTL_ID_DMAC0_MS          = 2,  /**< AHBDMA 0 controller */
    CY_MS_CTL_ID_DMAC1_MS          = 3,  /**< AHBDMA 1 controller */
    CY_MS_CTL_ID_DW0_MS            = 4,  /**< DataWire 0 */
    CY_MS_CTL_ID_DW1_MS            = 5,  /**< DataWire 1 */
    CY_MS_CTL_ID_CODE_MS_0         = 6,  /**< External 128-bit AHB5 CODE master-0 */
    CY_MS_CTL_ID_SYS_MS_0          = 7,  /**< External 32-bit AHB5 SYS interconnect master-0 */
    CY_MS_CTL_ID_SYS_MS_1          = 8,  /**< External 32-bit AHB5 SYS interconnect master-1 */
    CY_MS_CTL_ID_EXP_SYSCPUSS_MS_0 = 9,  /**< External 32-bit AHB5 EXP interconnect master-0 */
    CY_MS_CTL_ID_EXP_SYSCPUSS_MS_1 = 10, /**< External 32-bit AHB5 EXP interconnect master-1 */
    CY_MS_CTL_ID_EXP_SYSCPUSS_MS_2 = 11, /**< External 32-bit AHB5 EXP interconnect master-2 */
    CY_MS_CTL_ID_EXP_SYSCPUSS_MS_3 = 12, /**< External 32-bit AHB5 EXP interconnect master-3 */
    CY_MS_CTL_ID_EXP_APPCPUSS_MS_0 = 13, /**< External 32-bit AHB5 EXP interconnect master-4 */
    CY_MS_CTL_ID_EXP_APPCPUSS_MS_1 = 14, /**< External 32-bit AHB5 EXP interconnect master-5 */
    CY_MS_CTL_ID_EXP_APPCPUSS_MS_2 = 15, /**< External 32-bit AHB5 EXP interconnect master-6 */
    CY_MS_CTL_ID_EXP_APPCPUSS_MS_3 = 16, /**< External 32-bit AHB5 EXP interconnect master-7 */
    CY_MS_CTL_ID_SYS_MS_0_NVM      = 17, /**< External 32-bit AHB5 SYS NVM interconnect master-0 */
    CY_MS_CTL_ID_SYS_MS_1_NVM      = 18, /**< External 32-bit AHB5 SYS NVM interconnect master-1 */
    CY_MS_CTL_ID_CM55_MS_0         = 19, /**< Cortex M55 CPU-0 */
    CY_MS_CTL_ID_CM55_MS_1         = 20, /**< Cortex M55 CPU-1 */
    CY_MS_CTL_ID_CM55_MS_2         = 21, /**< Cortex M55 CPU-2 */
    CY_MS_CTL_ID_CM55_MS_3         = 22, /**< Cortex M55 CPU-3 */
    CY_MS_CTL_ID_AXIDMAC0_MS       = 23, /**< AXIDMA 0 controller */
    CY_MS_CTL_ID_AXIDMAC1_MS       = 24, /**< AXIDMA 1 controller */
    CY_MS_CTL_ID_U55AXI0_MS        = 25, /**< AXI_SYS_MS_0 */
    CY_MS_CTL_ID_U55AXI1_MS        = 26, /**< AXI_SYS_MS_1 */
    CY_MS_CTL_ID_AXI_SYS_MS2       = 27, /**< AXI_SYS_MS_2 */
    CY_MS_CTL_ID_AXI_SYS_MS3       = 28, /**< AXI_SYS_MS_3 */
    CY_MS_CTL_ID_BISR_MS           = 29, /**< BISR_MS */
    CY_MS_CTL_ID_RESERVED          = 30, /**< Reserved */
    CY_MS_CTL_ID_TC_MS             = 31  /**< Test Controller */
} en_ms_ctl_master_t;

/** Bus masters security controller and Access Control Group (ACG) config */
typedef enum
{
    CODE_MS0_MSC = 0,
    SYS_MS0_MSC  = 1,
    SYS_MS1_MSC  = 2,
    EXP_MS_MSC   = 3,
    DMAC0_MSC    = 4,
    DMAC1_MSC    = 5
} en_ms_ctl_master_sc_acg_t;

#if defined (CY_IP_M55APPCPUSS)

/** Bus masters security controller and Access Control Group (ACG) config */
typedef enum
{
    APP_SYS_MS0_MSC  = 0,
    APP_SYS_MS1_MSC  = 1,
    APP_AXIDMAC0_MSC = 2,
    APP_AXIDMAC1_MSC = 3,
    APP_AXI_MS0_MSC  = 4,
    APP_AXI_MS1_MSC  = 5,
    APP_AXI_MS2_MSC  = 6,
    APP_AXI_MS3_MSC  = 7,
    APP_EXP_MS0_MSC  = 8,
    APP_EXP_MS1_MSC  = 9,
    APP_EXP_MS2_MSC  = 10,
    APP_EXP_MS3_MSC  = 11,
} en_ms_ctl_master_sc_acg_v1_t;
#endif

/** Response type when ACG blocks incoming transfers */
typedef enum
{
    CY_MS_CTL_GATE_RESP_WAITED_TRFR = 0, /**< Waited transfer */
    CY_MS_CTL_GATE_RESP_ERR         = 1  /**< Error response */
} cy_en_ms_ctl_cfg_gate_resp_t;

/** Response type when MSC blocks transfers */
typedef enum
{
    CY_MS_CTL_SEC_RESP_RAZ_WI = 0, /**< Read as zero and write ignored */
    CY_MS_CTL_SEC_RESP_ERR    = 1  /**< Error response */
} cy_en_ms_ctl_sec_resp_t;

/** Protection context mask (PC_MASK) */
typedef enum
{
    CY_MS_CTL_PCMASK0  = 0x0001U,  /**< Mask to allow PC = 0 */
    CY_MS_CTL_PCMASK1  = 0x0002U,  /**< Mask to allow PC = 1 */
    CY_MS_CTL_PCMASK2  = 0x0004U,  /**< Mask to allow PC = 2 */
    CY_MS_CTL_PCMASK3  = 0x0008U,  /**< Mask to allow PC = 3 */
    CY_MS_CTL_PCMASK4  = 0x0010U,  /**< Mask to allow PC = 4 */
    CY_MS_CTL_PCMASK5  = 0x0020U,  /**< Mask to allow PC = 5 */
    CY_MS_CTL_PCMASK6  = 0x0040U,  /**< Mask to allow PC = 6 */
    CY_MS_CTL_PCMASK7  = 0x0080U,  /**< Mask to allow PC = 7 */
    CY_MS_CTL_PCMASK8  = 0x0100U,  /**< Mask to allow PC = 8 */
    CY_MS_CTL_PCMASK9  = 0x0200U,  /**< Mask to allow PC = 9 */
    CY_MS_CTL_PCMASK10 = 0x0400U,  /**< Mask to allow PC = 10 */
    CY_MS_CTL_PCMASK11 = 0x0800U,  /**< Mask to allow PC = 11 */
    CY_MS_CTL_PCMASK12 = 0x1000U,  /**< Mask to allow PC = 12 */
    CY_MS_CTL_PCMASK13 = 0x2000U,  /**< Mask to allow PC = 13 */
    CY_MS_CTL_PCMASK14 = 0x4000U,  /**< Mask to allow PC = 14 */
    CY_MS_CTL_PCMASK15 = 0x8000U   /**< Mask to allow PC = 15 */
} cy_en_ms_ctl_pcmask_t;

/** \} group_ms_ctl_enums */

/**
* \addtogroup group_ms_ctl_functions
* \{
*/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMaster(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask);
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgResp(en_ms_ctl_master_sc_acg_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp);
cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetPcHandler(uint32_t pc, cy_israddress handler);


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_SetActivePC
****************************************************************************//**
*
* \brief Set active protection context (PC) for the referenced bus master
*
* \param busMaster
* Bus master being initialized
*
* \param pc
* Protection Context value
*
* \return
* Requested operation status
*
*******************************************************************************/
__STATIC_INLINE cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetActivePC(en_ms_ctl_master_t busMaster, uint32_t pc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(busMaster), MS_PC_PC_PC , pc);
    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_GetActivePC
****************************************************************************//**
*
* \brief Reads the active protection context (PC) for the referenced bus master
*
* \param busMaster
* Bus master for which the PC value is being read
*
* \return
* Protection Context value
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Ms_Ctl_GetActivePC(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_PC_PC_READ_MIR_PC, MS_CTL_PC_READ_MIRROR_VX(busMaster)));
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_SetSavedPC
****************************************************************************//**
*
* \brief Set saved protection context (PC) for the referenced bus master
*
* \param busMaster
* Bus master being initialized
*
* \param savedPc
* Protection Context value
*
* \return
* Requested operation status
*
*******************************************************************************/
__STATIC_INLINE cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetSavedPC(en_ms_ctl_master_t busMaster, uint32_t savedPc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(busMaster), MS_PC_PC_PC_SAVED , savedPc);
    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_GetSavedPC
****************************************************************************//**
*
* \brief Reads the saved protection context (PC) for the referenced bus master
*
* \param busMaster
* Bus master for which the saved PC value is being read
*
* \return
* Protection Context value
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Ms_Ctl_GetSavedPC(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_PC_PC_READ_MIR_PC_SAVED, MS_CTL_PC_READ_MIRROR_VX(busMaster)));
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_GetPcHandler
****************************************************************************//**
*
* \brief Reads the handler address for the given PC
*
* \param pc
* Protection context for which the handler is being read
*
* \return
* Address of the protection context  handler
*
*******************************************************************************/

cy_israddress Cy_Ms_Ctl_GetPcHandler(uint32_t pc);

#if defined (CY_IP_M55APPCPUSS)
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMasterV1(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask);
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgRespV1(en_ms_ctl_master_sc_acg_v1_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp);

/*******************************************************************************
* Function Name: Cy_Ms_Ctl_SetActivePCV1
****************************************************************************//**
*
* \brief Set active protection context (PCTX) for the referenced bus master in APPCPUSS
*
* \param busMaster
* Bus master being initialized
*
* \param p_ctx
* Protection Context value
*
* \return
* Requested operation status
*
*******************************************************************************/
__STATIC_INLINE cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetActivePCV1(en_ms_ctl_master_t busMaster, uint32_t pc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_V1(busMaster), MS_CTL_MS_PC_PC_PC , pc);
    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_AppCpuSsGetActivePC
****************************************************************************//**
*
* \brief Reads the active protection context (PCTX) for the referenced bus master in APPCPUSS
*
* \param busMaster
* Bus master for which the PC value is being read
*
* \return
* Protection Context value
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_Ms_Ctl_GetActivePCV1(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_CTL_MS_PC_PC_READ_MIR_PC, MS_CTL_PC_READ_MIRROR_V1(busMaster)));
}

#endif
/** \} group_ms_ctl_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined (CY_IP_M55APPCPUSS) */

#endif /* #if defined (CY_IP_M33SYSCPUSS) */

/** \} group_ms_ctl */

/* [] END OF FILE */
