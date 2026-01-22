/***************************************************************************//**
* \file cy_rram.h
* \version 1.10
*
* \brief
* Provides an API declaration of the RRAM driver.
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


/**
* \defgroup group_rram               RRAM         (Resistive Random Access Memory)
* \{
*
* Resistive Random Access Memory (RRAM) is a type of non-volatile memory which is going
* to replace FLASH and OTP memory in MXS22 platform. RRAM is configured as NVM(512KB) + Extra(16KB) region.
* NVM memory region is further divided into MAIN (code), Em_EEPROM, SupMEM (Supervisory), and PROTECTED sub regions.
* The 16KB is RRAM extra area and is partitioned into lower 14KB as OTP region and the highest
* 2KB as configuration space region.
* OTP region is further divided into PROTECTED_OTP (including BootRow and UDS), General OTP data and
* BISR SRAM repair OTP regions.
*
* RRAM driver provides API's to Read/Write from/to RRAM memory,
* Enable/Disable RRAM sleep mode, Write protection.
* The functions and other declarations used in this driver are in cy_rram.h
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.h
*
* \section group_rram_configuration Configuration Considerations
*
* The RRAM driver provides the API to read and write to RRAM memory.
* No configuration is needed.
*
* \section group_rram_more_information More Information
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_rram_macros Macros
* \defgroup group_rram_enums Enums
* \defgroup group_rram_functions Functions
*
* \note In order to acquire PC_LOCK from CM33 the bootrow(0x50100000) value should be updated with
*  0xdb, 0x00, 0x00, 0x00, 0x70, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
*  where 0xdb should be written at 0th offset. Bootrow can be updated using \ref Cy_RRAM_OtpReadByteArray() API.
*/

#if !defined(CY_RRAM_H)
#define CY_RRAM_H

#include "cy_device.h"

#if defined (CY_IP_MXS22RRAMC)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 6, \
'Value extracted from _VAL2FLD macro will not exceed enum range.')

/*******************************************************************************
*       Function Constants
*******************************************************************************/

/**
* \addtogroup group_rram_macros
* \{
*/

/** Driver major version */
#define CY_RRAM_DRV_VERSION_MAJOR    1

/** Driver minor version */
#define CY_RRAM_DRV_VERSION_MINOR    0

/** Driver ID */
#define CY_RRAM_ID CY_PDL_DRV_ID     (0x4DU)

/** \cond INTERNAL */

/* The base address and size related macros will be generated during header generation process.*/
#ifdef CY_DEVICE_IFX_SECURITY_EPC2
#define CY_RRAM_RECLAIM_PROTECTED_NVM (0x15UL)
#else
#define CY_RRAM_RECLAIM_PROTECTED_NVM (0x0UL)
#endif /* CY_DEVICE_IFX_SECURITY_EPC2 */
#define CY_RRAM_REGION_SIZE_UNIT                (8192UL)
#define CY_RRAM_RECLAIM_SIZE                    (CY_RRAM_RECLAIM_PROTECTED_NVM * CY_RRAM_REGION_SIZE_UNIT)
#define CY_RRAM_MAIN_N                          ((CPUSS_RRAMC_MAIN_N) + CY_RRAM_RECLAIM_PROTECTED_NVM)
#define CY_RRAM_PROTECTED_X                     ((CPUSS_RRAMC_PROTECTED_X) - CY_RRAM_RECLAIM_PROTECTED_NVM)
#define CY_RRAM_WORK_Z                          (0x0UL)
#define CY_RRAM_FLASH_Y                         (0x0UL)
#define CY_RRAM_PC_LOCK_ACQUIRE                 (0x0FUL)
#define CY_RRAM_BLOCK_SIZE_BYTES                (0x10UL)
#define CY_RRAM_BLOCK_SIZE_WORDS                (0x04UL)
#define CY_RRAM_S_OFFSET_MASK                   (0x10000000UL)
#define CY_RRAM_MAIN_REGION_SIZE                (CY_RRAM_MAIN_N * CY_RRAM_REGION_SIZE_UNIT)
#define CY_RRAM_WORK_REGION_SIZE                (CY_RRAM_WORK_Z * CY_RRAM_REGION_SIZE_UNIT)
#define CY_RRAM_SFLASH_REGION_SIZE              (CY_RRAM_FLASH_Y * CY_RRAM_REGION_SIZE_UNIT)
#define CY_RRAM_PROTECTED_REGION_SIZE           (CY_RRAM_PROTECTED_X * CY_RRAM_REGION_SIZE_UNIT)
#define CY_RRAM_PROTECTED_OTP_SIZE              (0x00002000UL)
#define CY_RRAM_GENERAL_OTP_SIZE                (0x00001600UL)
#define CY_RRAM_INVALID_ACCESS                  (0x0UL)
#define CY_RRAM_NVM_SIZE_KB                     (0x00000200UL)
#define CY_RRAM_SECTOR_SIZE_KB                  (0X04UL)
#define CY_RRAM_PROTECTED_LOCK_REGION_LIMIT     (0x00000100UL)

/* Base address of NVM region */
#if (CY_CPU_CORTEX_M0P)
#define CY_RRAM_MAIN_HOST_NS_START_ADDRESS            (0x02000000UL)
#define CY_RRAM_MAIN_HOST_S_START_ADDRESS             (0x12000000UL)
#define CY_RRAM_WORK_HOST_NS_START_ADDRESS            (0x03000000UL)
#define CY_RRAM_WORK_HOST_S_START_ADDRESS             (0x13000000UL)
#define CY_RRAM_SFLASH_HOST_NS_START_ADDRESS          (0x03600000UL)
#define CY_RRAM_SFLASH_HOST_S_START_ADDRESS           (0x13600000UL)
#define CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS       (0x03C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_HOST_S_START_ADDRESS        (0x13C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS  (0x03800000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_PROTECTED_S_START_ADDRESS   (0x13800000UL + CY_RRAM_RECLAIM_SIZE)
/* Remove once CDT_005546-83 is fixed */
#define CY_RRAM_CONFIG_SPACE_SIZE                      (0x2048UL)
#define CY_RRAM_CONFIG_PROTECTED_NS_START_ADDRESS      (0x40108800UL)
#define CY_RRAM_CONFIG_PROTECTED_S_START_ADDRESS       (0x50108800UL)
#define CY_RRAM_CONFIG_PROTECTED_NS_END_ADDRESS        (CY_RRAM_CONFIG_PROTECTED_NS_START_ADDRESS + CY_RRAM_CONFIG_SPACE_SIZE - 1UL)
#define CY_RRAM_CONFIG_PROTECTED_S_END_ADDRESS         (CY_RRAM_CONFIG_PROTECTED_S_START_ADDRESS  + CY_RRAM_CONFIG_SPACE_SIZE - 1UL)
#define CY_RRAM_PHYSICAL_CONFIG_SPACE_BASE_ADDR        (0x00008380UL)
//
#elif (CY_CPU_CORTEX_M55)
#define CY_RRAM_MAIN_HOST_NS_START_ADDRESS            (0x02000000UL)
#define CY_RRAM_WORK_HOST_NS_START_ADDRESS            (0x03000000UL)
#define CY_RRAM_SFLASH_HOST_NS_START_ADDRESS          (0x03600000UL)
#define CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS       (0x03C00000UL + CY_RRAM_RECLAIM_SIZE)
#else
#define CY_RRAM_MAIN_HOST_NS_START_ADDRESS            (0x22000000UL)
#define CY_RRAM_MAIN_HOST_S_START_ADDRESS             (0x32000000UL)
#define CY_RRAM_MAIN_HOST_CBUS_NS_START_ADDRESS       (0x02000000UL)
#define CY_RRAM_MAIN_HOST_CBUS_S_START_ADDRESS        (0x12000000UL)
#define CY_RRAM_WORK_HOST_NS_START_ADDRESS            (0x03000000UL)
#define CY_RRAM_WORK_HOST_S_START_ADDRESS             (0x13000000UL)
#define CY_RRAM_SFLASH_HOST_NS_START_ADDRESS          (0x03600000UL)
#define CY_RRAM_SFLASH_HOST_S_START_ADDRESS           (0x13600000UL)
#define CY_RRAM_PROTECTED_HOST_CBUS_NS_START_ADDRESS  (0x03C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_HOST_CBUS_S_START_ADDRESS   (0x13C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS       (0x23C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_HOST_S_START_ADDRESS        (0x33C00000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS  (0x03800000UL + CY_RRAM_RECLAIM_SIZE)
#define CY_RRAM_PROTECTED_PROTECTED_S_START_ADDRESS   (0x13800000UL + CY_RRAM_RECLAIM_SIZE)
#endif

/* Base address for OTP region */
#define CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS         (0x42204000UL)
#define CY_RRAM_GENERAL_OTP_MMIO_S_START_ADDRESS          (0x52204000UL)
#define CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS  (0x40100000UL)
#define CY_RRAM_PROTECTED_OTP_PROTECTED_S_START_ADDRESS   (0x50100000UL)

/* End address of NVM region */
#define CY_RRAM_MAIN_HOST_NS_END_ADDRESS               (CY_RRAM_MAIN_REGION_SIZE != 0UL ? (CY_RRAM_MAIN_HOST_NS_START_ADDRESS + CY_RRAM_MAIN_REGION_SIZE - 1UL) : CY_RRAM_MAIN_HOST_NS_START_ADDRESS)
#define CY_RRAM_MAIN_HOST_S_END_ADDRESS                (CY_RRAM_MAIN_REGION_SIZE != 0UL ? (CY_RRAM_MAIN_HOST_S_START_ADDRESS + CY_RRAM_MAIN_REGION_SIZE - 1UL) : CY_RRAM_MAIN_HOST_S_START_ADDRESS)
#define CY_RRAM_MAIN_HOST_CBUS_NS_END_ADDRESS          (CY_RRAM_MAIN_REGION_SIZE != 0UL ? (CY_RRAM_MAIN_HOST_CBUS_NS_START_ADDRESS + CY_RRAM_MAIN_REGION_SIZE - 1UL) : CY_RRAM_MAIN_HOST_CBUS_NS_START_ADDRESS)
#define CY_RRAM_MAIN_HOST_CBUS_S_END_ADDRESS           (CY_RRAM_MAIN_REGION_SIZE != 0UL ? (CY_RRAM_MAIN_HOST_CBUS_S_START_ADDRESS + CY_RRAM_MAIN_REGION_SIZE - 1UL) : CY_RRAM_MAIN_HOST_CBUS_S_START_ADDRESS)
#define CY_RRAM_WORK_HOST_NS_END_ADDRESS               (CY_RRAM_WORK_REGION_SIZE != 0UL ? (CY_RRAM_WORK_HOST_NS_START_ADDRESS + CY_RRAM_WORK_REGION_SIZE - 1UL) : CY_RRAM_WORK_HOST_NS_START_ADDRESS)
#define CY_RRAM_WORK_HOST_S_END_ADDRESS                (CY_RRAM_WORK_REGION_SIZE != 0UL ? (CY_RRAM_WORK_HOST_S_START_ADDRESS + CY_RRAM_WORK_REGION_SIZE - 1UL) : CY_RRAM_WORK_HOST_S_START_ADDRESS)
#define CY_RRAM_SFLASH_HOST_NS_END_ADDRESS             (CY_RRAM_SFLASH_REGION_SIZE != 0UL ? (CY_RRAM_SFLASH_HOST_NS_START_ADDRESS + CY_RRAM_SFLASH_REGION_SIZE - 1UL) : CY_RRAM_SFLASH_HOST_NS_START_ADDRESS)
#define CY_RRAM_SFLASH_HOST_S_END_ADDRESS              (CY_RRAM_SFLASH_REGION_SIZE != 0UL ? (CY_RRAM_SFLASH_HOST_S_START_ADDRESS + CY_RRAM_SFLASH_REGION_SIZE - 1UL) : CY_RRAM_SFLASH_HOST_NS_START_ADDRESS)
#define CY_RRAM_PROTECTED_HOST_NS_END_ADDRESS          (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS)
#define CY_RRAM_PROTECTED_HOST_S_END_ADDRESS           (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_HOST_S_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_HOST_S_START_ADDRESS)
#define CY_RRAM_PROTECTED_PROTECTED_NS_END_ADDRESS     (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS)
#define CY_RRAM_PROTECTED_PROTECTED_S_END_ADDRESS      (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_PROTECTED_S_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_PROTECTED_S_START_ADDRESS)
#define CY_RRAM_PROTECTED_HOST_CBUS_S_END_ADDRESS      (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_HOST_CBUS_S_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_HOST_CBUS_S_START_ADDRESS)
#define CY_RRAM_PROTECTED_HOST_CBUS_NS_END_ADDRESS     (CY_RRAM_PROTECTED_REGION_SIZE != 0UL ? (CY_RRAM_PROTECTED_HOST_CBUS_NS_START_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE - 1UL) : CY_RRAM_PROTECTED_HOST_CBUS_NS_START_ADDRESS)

/* End address for OTP region */
#define CY_RRAM_GENERAL_OTP_MMIO_NS_END_ADDRESS        (CY_RRAM_GENERAL_OTP_SIZE != 0UL ? (CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS + CY_RRAM_GENERAL_OTP_SIZE - 1UL) :CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS)
#define CY_RRAM_GENERAL_OTP_MMIO_S_END_ADDRESS         (CY_RRAM_GENERAL_OTP_SIZE != 0UL ? (CY_RRAM_GENERAL_OTP_MMIO_S_START_ADDRESS + CY_RRAM_GENERAL_OTP_SIZE - 1UL) : CY_RRAM_GENERAL_OTP_MMIO_S_START_ADDRESS)
#define CY_RRAM_PROTECTED_OTP_MMIO_NS_END_ADDRESS      (CY_RRAM_PROTECTED_OTP_SIZE != 0UL ? (CY_RRAM_PROTECTED_OTP_MMIO_NS_START_ADDRESS + CY_RRAM_PROTECTED_OTP_SIZE - 1UL) : CY_RRAM_PROTECTED_OTP_MMIO_NS_START_ADDRESS)
#define CY_RRAM_PROTECTED_OTP_MMIO_S_END_ADDRESS       (CY_RRAM_PROTECTED_OTP_SIZE != 0UL ? (CY_RRAM_PROTECTED_OTP_MMIO_S_START_ADDRESS + CY_RRAM_PROTECTED_OTP_SIZE - 1UL) : CY_RRAM_PROTECTED_OTP_MMIO_S_START_ADDRESS)
#define CY_RRAM_PROTECTED_OTP_PROTECTED_NS_END_ADDRESS (CY_RRAM_PROTECTED_OTP_SIZE != 0UL ? (CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS + CY_RRAM_PROTECTED_OTP_SIZE - 1UL) : CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS)
#define CY_RRAM_PROTECTED_OTP_PROTECTED_S_END_ADDRESS  (CY_RRAM_PROTECTED_OTP_SIZE != 0UL ? (CY_RRAM_PROTECTED_OTP_PROTECTED_S_START_ADDRESS + CY_RRAM_PROTECTED_OTP_SIZE - 1UL) : CY_RRAM_PROTECTED_OTP_PROTECTED_S_START_ADDRESS)

/* Physical address */
#define CY_RRAM_PHYSICAL_MAIN_BASE_ADDR                 (0x00000000UL)
#define CY_RRAM_PHYSICAL_WORK_BASE_ADDR                 (CY_RRAM_PHYSICAL_MAIN_BASE_ADDR + (CY_RRAM_MAIN_REGION_SIZE / CY_RRAM_BLOCK_SIZE_BYTES))               /* 0x00004000UL */
#define CY_RRAM_PHYSICAL_SFLASH_BASE_ADDR               (CY_RRAM_PHYSICAL_WORK_BASE_ADDR + (CY_RRAM_WORK_REGION_SIZE / CY_RRAM_BLOCK_SIZE_BYTES))               /* 0x00004000UL */
#define CY_RRAM_PHYSICAL_PROTECTED_BASE_ADDR            (CY_RRAM_PHYSICAL_SFLASH_BASE_ADDR + (CY_RRAM_SFLASH_REGION_SIZE / CY_RRAM_BLOCK_SIZE_BYTES))           /* 0x00004000UL */
#define CY_RRAM_PHYSICAL_PROTECTED_OTP_BASE_ADDR        (CY_RRAM_PHYSICAL_PROTECTED_BASE_ADDR + (CY_RRAM_PROTECTED_REGION_SIZE  / CY_RRAM_BLOCK_SIZE_BYTES))    /* 0x00008000UL */
#define CY_RRAM_PHYSICAL_GENERAL_OTP_BASE_ADDR          (CY_RRAM_PHYSICAL_PROTECTED_OTP_BASE_ADDR + (CY_RRAM_PROTECTED_OTP_SIZE / CY_RRAM_BLOCK_SIZE_BYTES))    /* 0x00008200UL */

#define CY_RRAM_SECTOR_COUNT_VALID(numSectors)     ((numSectors) <= (CY_RRAM_NVM_SIZE_KB / CY_RRAM_SECTOR_SIZE_KB))

#define CY_RRAM_BLOCK_COUNT_VALID(numBlocks)      ((numBlocks > 0UL) && (numBlocks < ((CY_RRAM_NVM_SIZE_KB * 1024U) / CY_RRAM_BLOCK_SIZE_BYTES)))

/*
 * By default ECC Check is Enabled. This API is not meant for user. This API is used only during very early stage of
 * pre-silicon bring-up activity. During bring-up, RRAM test application can override this and disable ECC checking when tag
 * bits are being reset. Once the tag bits are reset, the test app can enable it so that ECC can be checked for normal
 * functionality of the driver.
 */

bool cy_rram_should_check_ecc(void);

/** \endcond */

/** \} group_rram_macros */

/**
* \addtogroup group_rram_enums
* \{
*/

/**
* RRAM driver error codes
*/
typedef enum
{
    CY_RRAM_SUCCESS                          = 0x0UL,                                     /**< Returned successful */
    CY_RRAM_BAD_PARAM                        = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x01UL, /**< Bad parameter was passed */
    CY_RRAM_ACQUIRE_PC_LOCK_FAIL             = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0X02UL, /**< Fail to acquire PC lock during indirect operation */
    CY_RRAM_OPERATION_TIME_OUT_ERROR         = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0X03UL, /**< Time out error during RRAM operation */
    CY_RRAM_WRITE_OPERATION_ERROR            = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x04UL, /**< Write operation failed */
    CY_RRAM_WPLOCK_ENABLED                   = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x05UL, /**< Write protection lock enabled */
    CY_RRAM_ECC_FAIL                         = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x06UL, /**< Read operation failed with uncorrectable ECC error */
    CY_RRAM_HARDEN_ALLMEM_FAIL               = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x07UL, /**< Hardening of complete memory failed */
    CY_RRAM_UPDATE_LOCKABLE_REGION_FAILED    = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x08UL, /**< The Lock bit state is Locked. Failed to update the lockable region. */
    CY_RRAM_VERR_BLOCK_FAIL_BITS             = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x09UL, /**< Information on number of fail bits for a block after verify operations in indirect
                                                                                               write, verify-only, and forming operations */
    CY_RRAM_ADDRESS_UPDATE_FAIL              = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x0AUL,   /**< Failed to write NVM_ADDR register for write operation */
    CY_RRAM_INIT_FAIL                        = CY_RRAM_ID | CY_PDL_STATUS_ERROR | 0x0BUL   /**< Failed to retrieve configuration from configuration space in extra area. */
} cy_en_rram_status_t;

/**
* RRAM protected lock for NVM region
*/
typedef enum
{
    CY_RRAM_PROTECTED_UNLOCK    = 0x00UL,      /**< Not locked, PARTITION_SIZE_0/1 in PROTECTED_NVM region */
    CY_RRAM_PROTECTED_LOCK      = 0x0FUL       /**< Locked, PARTITION_SIZE_0/1 in PROTECTED_NVM region */
} cy_en_rram_protected_lock_t;

/**
* RRAM UDS lock for NVM region
*/
typedef enum
{
    CY_RRAM_UDS_UNLOCK    = 0x00UL,      /**< Not locked, Access to UDS_KEY */
    CY_RRAM_UDS_LOCK      = 0x0FUL       /**< Locked, No access to UDS_KEY */
} cy_en_rram_uds_lock_t;

/**
* RRAM write protection lock for NVM region
*/
typedef enum
{
    CY_RRAM_WP_UNLOCK    = 0x00UL,      /**< Not locked, Sectors for write protection can be configured. */
    CY_RRAM_WP_LOCK      = 0x01UL       /**< Locked, Sectors for write protection cannot be configured. */
} cy_en_rram_wp_lock_t;


/**
* RRAM sleep mode status
*/
typedef enum
{
    CY_RRAM_NOT_IN_SLEEP    = 0x00UL,      /**< Not in sleep mode, and no sleep or wake up procedure in progress.*/
    CY_RRAM_IN_SLEEP        = 0x01UL       /**< In sleep mode, or busy due to a sleep or wake up procedure.*/
} cy_en_rram_sleep_t;

/**
* RRAM operations
*/
typedef enum
{
    CY_RRAM_IDLE                = 0x00UL,  /**< Idle state */
    CY_RRAM_INDIRECT_WRITE      = 0x01UL,  /**< Indirect write operation */
    CY_RRAM_VERIFY_ONLY         = 0x02UL,  /**< Verify only operation */
    CY_RRAM_HARDENING           = 0x04UL,  /**< Hardening operation */
    CY_RRAM_LOOPED_FORMING      = 0x07UL,  /**< Looped forming operation */
    CY_RRAM_FORMING             = 0x08UL,  /**< Forming operation */
    CY_RRAM_RETRIEVE_CONFIG     = 0x0BUL,  /**< Retrieve configuration */
    CY_RRAM_LOOPED_WRITE        = 0x0EUL   /**< Looped write*/
} cy_en_rram_operation_t;

/**
* RRAM error codes
*/
typedef enum
{
    CY_RRAM_NO_ERROR                     = 0x00UL,  /**< No Error */
    CY_RRAM_SINGLE_BIT_ERROR             = 0x01UL,  /**< Single Bit fail */
    CY_RRAM_DOUBLE_BIT_ERROR             = 0x02UL,  /**< Double Bit fail */
    CY_RRAM_TRIPLE_BIT_ERROR             = 0x03UL,  /**< Triple Bit fail */
    CY_RRAM_ECC_UNCORRECTABLE_BIT_ERROR  = 0x04UL,  /**< ECC uncorrectable fail bit error */
    CY_RRAM_ECC_ADDR_MISMATCH_ERROR      = 0x05UL,  /**< ECC address mismatch error */
    CY_RRAM_CONFIG_ERROR                 = 0x06UL,  /**< Config error */
    CY_RRAM_ALGORITHM_ERROR              = 0x07UL  /**< Algorithm error */
} cy_en_rram_verr_status_t;

/**
* RRAM AHB error codes
*/
typedef enum
{
    CY_RRAM_AHB_NO_ERROR                        = 0x00UL,  /**< No Error */
    CY_RRAM_OTP_TAGBIT_VIOLATION                = 0x01UL,  /**< OTP Tag bit violation during write */
    CY_RRAM_POSTREAD_CHK_TAGBIT_VIOLATION       = 0x02UL,  /**< Post-read check Tag bit violation during read */
    CY_RRAM_POSTREAD_CHK_ADDR_FAULT_ALRM        = 0x03UL,  /**< Post-read check address fault alarm */
    CY_RRAM_AHB_ERROR                           = 0x04UL,  /**< RRAM IP AHB bus error */
    CY_RRAM_M0SEC_WRITE_ERROR                   = 0x05UL,  /**< Incomplete write or 8/16 write on the protected interface */
    CY_RRAM_WRITE_ADDR_MISMATCH                 = 0x06UL,  /**< Indirect sequence where AHB write address mismatch with SFR NVM_ADDR */
    CY_RRAM_PROTECTED_PRGM_ERROR                = 0x07UL,  /**< Programming PROTECTED_NVM lockable subsection */
    CY_RRAM_READ_UDS_WHILE_LOCKED               = 0x09UL,  /**< Detecting UDS read access while UDS is locked */
    CY_RRAM_UNLOCK_UDS_WHILE_LOCKED             = 0x0AUL,  /**< Detecting unlock UDS when it is locked */
    CY_RRAM_TAGBIT_GATING_CTL_ERROR             = 0x0BUL,  /**< Detecting Tag bit gating control error */
    CY_RRAM_OPRTN_ERR_WITHOUT_PC_ACQUISITION    = 0x0CUL,  /**< Executing indirect operation without a PC acquired */
    CY_RRAM_PC_MISMATCH_ERROR                   = 0x0DUL,  /**< Transaction PC is different than the acquired PC */
    CY_RRAM_EXECUTE_FORMING                     = 0x0EUL,  /**< Executing forming or looped forming in SORT LCS */
    CY_RRAM_PROTECTED_INTERFACE_MPC_VIOLATION   = 0x0FUL   /**< Protected interface MPC violation */
} cy_en_rram_hresp_t;


/**
* RRAM voltage/frequency mode for operations
*/
typedef enum
{
    CY_RRAM_VMODE_UNDEFINED  = 0x0UL,     /**<Undefined voltage/frequency mode for operations.*/
    CY_RRAM_VMODE_ULP        = 0x1UL,     /**<ULP voltage/frequency mode for operations.*/
    CY_RRAM_VMODE_LP         = 0x2UL,     /**<LP voltage/frequency mode for operations.*/
    CY_RRAM_VMODE_HP         = 0x3UL      /**<HP voltage/frequency mode for operations.*/
} cy_en_rram_vmode_t;

/**
* RRAM Junction Temperature
*/
typedef enum
{
    CY_RRAM_TEMP_INVALID               = 0x0UL,     /**< Invalid/Unknown junction temperature value.*/
    CY_RRAM_TEMP_LESS_THAN_EQ_50C      = 0x1UL,     /**< Tj <= 50C.*/
    CY_RRAM_TEMP_ABOVE_50C_BELOW_85C   = 0x2UL,     /**< 50C < Tj <= 85C.*/
    CY_RRAM_TEMP_ABOVE_85C_BELOW_100C  = 0x4UL,     /**< 85C < Tj <= 100C.*/
    CY_RRAM_TEMP_ABOVE_100C_BELOW_110C = 0x8UL,     /**< 100C < Tj <= 110C.*/
    CY_RRAM_TEMP_ABOVE_110C_BELOW_120C = 0xAUL,     /**< 110C < Tj <=120C.*/
    CY_RRAM_TEMP_ABOVE_120C            = 0xCUL,     /**< Tj > 120C.*/
} cy_en_rram_temperature_t;


/** \} group_rram_enums */

/***************************************
*      Function Prototypes
***************************************/

/**
* \addtogroup group_rram_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteByteArray
****************************************************************************//**
*
* \brief
* Writes array of byte data to the specified address.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the OTP subsection. The address should fall in General OTP or Protected OTP subsection.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \param numBytes
* Number of bytes to be written.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_OtpWriteByteArray
*
* \note
* OTP region is One Time Programmable. API does read-modify(OR)-write operation.
* Once the data bit has been programmed into the OTP region it can't be erased by writing a 0 to it.
* Any zero bit in the data indicates that write to this bit in OTP regions will be ignored.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_OtpReadByteArray
****************************************************************************//**
*
* \brief
* Reads array of byte data from the specified address.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the OTP subsection. The address should fall in General OTP or Protected OTP subsection.
*
* \param data
* Pointer to the destination where the read data is stored.
*
* \param numBytes
* Number of bytes to be read.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_OtpReadByteArray
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteWord
****************************************************************************//**
*
* \brief
* Writes a 32-bit word data to the specified address.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the OTP subsection. The address should fall in General OTP or Protected OTP subsection.
*
* \param data
* Data to be written to the specified address.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_OtpWriteWord
*
* \note
* OTP region is One Time Programmable. API does read-modify(OR)-write operation.
* Once the data bit has been programmed into the OTP region it can't be erased by writing a 0 to it.
* Any zero bit in the data indicates that write to this bit in OTP regions will be ignored.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteWord(RRAMC_Type * base, uint32_t addr, uint32_t data);


/*******************************************************************************
* Function Name: Cy_RRAM_OtpReadWord
****************************************************************************//**
*
* \brief
* Reads a 32bit word data from the specified address.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the OTP subsection. The address should fall in General OTP or Protected OTP subsection.
*
* \param data
* Pointer to the destination where the read word is stored.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_OtpReadWord
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpReadWord(RRAMC_Type * base, uint32_t addr, uint32_t * data);


/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteBlock
****************************************************************************//**
*
* \brief
* Writes a block(16B) data to the specified address.
* Assumption is that the provided address is block aligned.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the OTP subsection. The address should fall in General OTP or Protected OTP subsection.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_OtpWriteBlock
*
* \note OTP region is One Time Programmable. API does read-modify(OR)-write operation.
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteBlock(RRAMC_Type * base, uint32_t addr, uint8_t *data);


/*******************************************************************************
* Function Name: Cy_RRAM_NvmWriteByteArray
****************************************************************************//**
*
* \brief
* Writes array of byte data to the specified address in blocking mode.
* API will wait for the write operation to be completed. It returns error or success status.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the NVM subsection. The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \param numBytes
* Number of bytes to be written.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NvmWriteByteArray
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_NvmReadByteArray
****************************************************************************//**
*
* \brief
* Reads array of byte data from the specified address.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the NVM subsection. The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
* \param data
* Pointer to the destination where the read data is stored.
*
* \param numBytes
* Number of bytes to be read.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NvmReadByteArray
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_NonBlockingNvmWriteByteArray
****************************************************************************//**
*
* \brief
* Writes array of byte data to the specified address in Non Blocking mode.
* API will only validate parameter and performs write operation. User needs to call \ref Cy_RRAM_GetStatus() to
* check the status of write operation.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the NVM subsection. The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \param numBytes
* Number of bytes to be written.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NonBlockingNvmWriteByteArray
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NonBlockingNvmWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_NvmWriteBlock
****************************************************************************//**
*
* \brief
* Writes a block(16B) data to the specified address.
* Assumption is that the provided address is Block aligned.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of the NVM subsection. The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NvmWriteBlock
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmWriteBlock(RRAMC_Type * base, uint32_t addr, uint8_t *data);


/*******************************************************************************
* Function Name: Cy_RRAM_WriteByteArray
****************************************************************************//**
*
* \brief
* Writes array of byte data to the specified address in blocking mode.
* API will wait for the write operation to be completed. It returns error or success status.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of RRAM memory. The provided address should fall under one of the NVM or OTP sub
* sections otherwise bad parameter error will be returned.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \param numBytes
* Number of bytes to be written.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_WriteByteArray
*
* \note OTP region is One Time Programmable. API does read-modify(OR)-write operation.
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_WriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_TSWriteByteArray
****************************************************************************//**
*
* \brief
* Writes an array of byte data to the specified address in blocking mode without considering
* uncorrectable ECC fail error.
* API will wait for the write operation to be completed. It returns error or success status.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of RRAM memory. The provided address should fall under one of the NVM or OTP sub
* sections otherwise bad parameter error will be returned.
*
* \param data
* Pointer to the data to be written to the specified address.
*
* \param numBytes
* Number of bytes to be written.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_TSWriteByteArray
*
* \note
* This API should be used only for tearing safe use cases.
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_TSWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_ReadByteArray
****************************************************************************//**
*
* \brief
* Reads an array of byte data from the specified address.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of RRAM memory. The provided address should fall under one of the NVM or OTP sub
* sections otherwise bad parameter error will be returned.
*
* \param data
* Pointer to the destination where the read data is stored.
*
* \param numBytes
* Number of bytes to be read.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_ReadByteArray
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_ReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes);


/*******************************************************************************
* Function Name: Cy_RRAM_TSReadByteArray
****************************************************************************//**
*
* \brief
* Reads an array of byte data from the specified address after validating the
* uncorrectable ECC fail bits.
* Returns ECC fail error if uncorrectable ECC fail error exist.
* This function tries to acquire the lock. If the
* lock is not available, then it returns immediately with
* CY_RRAM_ACQUIRE_PC_LOCK_FAIL error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param addr
* Address of RRAM memory. The provided address should fall under one of the NVM or OTP sub
* sections otherwise bad parameter error will be returned.
*
* \param data
* Pointer to the destination where the read data is stored.
*
* \param numBytes
* Number of bytes to be read.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_ReadByteArray
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_TSReadByteArray
*
* \note
* This API should be used only for tearing safe use cases.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_TSReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes);


#if (CY_CPU_CORTEX_M0P)
/*******************************************************************************
* Function Name : Cy_RRAM_Init
****************************************************************************//**
*
* \brief
* Retrieves configuration settings from configuration space in extra area.
*
* Sequence followed:
* Set voltage/frequency mode \ref cy_en_rram_vmode_t
* Start "Retrieve configuration settings" sequence and waits until
* the sequence finishes.
* Validate for read errors and return status.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param vmode
* voltage/frequency mode for operations.
*
* \param retrvAlgoInfo
* Set the parameter to true in order to retrieve the write algorithm information along
* with the SYSCONF information and configuration settings.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \note
* This API is available only for CM0P
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_Init(RRAMC_Type * base, cy_en_rram_vmode_t vmode, bool retrvAlgoInfo);
#endif


/*******************************************************************************
* Function Name: Cy_RRAM_GetStatus
****************************************************************************//**
*
* \brief
* Get the status of RRAM. It includes information about busy status, sleep status,
* status on ECC during read operation, write protection error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* RRAM status.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NonBlockingNvmWriteByteArray
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_RRAM_GetStatus(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return RRAM_NVM_STATUS(base);
}


/*******************************************************************************
* Function Name: Cy_RRAM_IsBusy
****************************************************************************//**
*
* Indicates the status of NVM Busy flag.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* RRAM status:  true - Busy, false - Not busy.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_RRAM_IsBusy(RRAMC_Type * base)
{
    return (bool)_FLD2VAL(RRAMC_RRAM_SFR_NVM_STATUS_BUSY, RRAM_NVM_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetAHBError
****************************************************************************//**
*
* \brief
* Gets AHB bus error occurred during transactions.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Status. Refer \ref cy_en_rram_hresp_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_NonBlockingNvmWriteByteArray
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_hresp_t Cy_RRAM_GetAHBError(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return (cy_en_rram_hresp_t)_FLD2VAL(RRAMC_RRAMC_AHB_HRESP_HRESP, RRAM_AHB_HRESP(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_EnableSleepMode
****************************************************************************//**
*
* \brief
* Puts RRAM in Sleep mode. No memory access is possible in NVM sleep mode.
* During sleep, the SFR NVM_CONF1 can be read and written, all other SFRs are read-only.
*
* \param base
* The pointer to the RRAMC instance.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_Sleep
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_EnableSleepMode(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    RRAM_NVM_CONF1(base) &= ~RRAMC_RRAM_SFR_NVM_CONF1_NVM_ON_Msk;
}


/*******************************************************************************
* Function Name: Cy_RRAM_DisableSleepMode
****************************************************************************//**
*
* \brief
* Puts RRAM in Normal mode.
*
* \param base
* The pointer to the RRAMC instance.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_Sleep
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_DisableSleepMode(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    RRAM_NVM_CONF1(base) |= RRAMC_RRAM_SFR_NVM_CONF1_NVM_ON_Msk;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetSleepStatus
****************************************************************************//**
*
* \brief
* Gets the sleep status of RRAM.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Status. Refer \ref cy_en_rram_sleep_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_Sleep
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_sleep_t Cy_RRAM_GetSleepStatus(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return (cy_en_rram_sleep_t)_FLD2VAL(RRAMC_RRAM_SFR_NVM_STATUS_SLEEP, RRAM_NVM_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_EnableWP
****************************************************************************//**
*
* \brief
* Enables write protection for number of sectors starting with sector 0 in RRAM NVM region.
* Before calling this API, user need to call Cy_RRAM_GetWPLockState() API and
* make sure the write protection lock is not locked. Otherwise this API will return
* CY_RRAM_WPLOCK_ENABLED error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param numSectors
* Number of sectors.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_WriteProtection
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_EnableWP(RRAMC_Type * base, uint32_t numSectors);


/*******************************************************************************
* Function Name: Cy_RRAM_DisableWP
****************************************************************************//**
*
* \brief
* Disables write protection for all sectors in RRAM NVM region.
* Before calling this API, user need to call Cy_RRAM_GetWPLockState() API and
* make sure the write protection lock is not locked. Otherwise this API will return
* CY_RRAM_WPLOCK_ENABLED error.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_WriteProtection
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_DisableWP(RRAMC_Type * base);


/*******************************************************************************
* Function Name: Cy_RRAM_SetWPLock
****************************************************************************//**
*
* \brief
* Enables the write protection lock by setting WPLCK to 1.
* Once locked, the lock state cannot be changed till next reset.
*
* \param base
* The pointer to the RRAMC instance.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_WriteProtection
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetWPLock(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    /* Enable write protection lock by setting WPLCK to 1 */
    RRAM_NVM_CONF1(base) |= RRAMC_RRAM_SFR_NVM_CONF1_WPLCK_Msk;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetWPLockState
****************************************************************************//**
*
* \brief
* Gets the state of write protection lock.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Status. Refer \ref cy_en_rram_wp_lock_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_WriteProtection
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_wp_lock_t Cy_RRAM_GetWPLockState(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return (cy_en_rram_wp_lock_t)_FLD2VAL(RRAMC_RRAM_SFR_NVM_CONF1_WPLCK, RRAM_NVM_CONF1(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetVoltageMode
****************************************************************************//**
*
* \brief
* Set voltage/frequency mode.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param vmode
* Voltage mode. Refer \ref cy_en_rram_vmode_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_UpdateVoltageMode
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetVoltageMode(RRAMC_Type * base, cy_en_rram_vmode_t vmode)
{
    CY_ASSERT_L1(NULL != base);

    /* Sets voltage/frequency mode */
    uint32_t temp = RRAM_NVM_VMODE(base) & ~ RRAMC_RRAM_SFR_NVM_VMODE_VMODE_Msk;
    RRAM_NVM_VMODE(base) = temp | _VAL2FLD(RRAMC_RRAM_SFR_NVM_VMODE_VMODE, vmode);
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetVoltageMode
****************************************************************************//**
*
* \brief
* Get voltage/frequency mode.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Voltage mode. Refer \ref cy_en_rram_vmode_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_UpdateVoltageMode
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_vmode_t Cy_RRAM_GetVoltageMode(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    /* Get voltage/frequency mode */
    return (cy_en_rram_vmode_t)_FLD2VAL(RRAMC_RRAM_SFR_NVM_VMODE_VMODE, RRAM_NVM_VMODE(base));
}

/*******************************************************************************
* Function Name: Cy_RRAM_SetTemperature
****************************************************************************//**
*
* \brief
* Set junction temperature.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param temperature
* Temperature. Refer \ref cy_en_rram_temperature_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetTemperature
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetTemperature(RRAMC_Type * base, cy_en_rram_temperature_t temperature)
{
    CY_ASSERT_L1(NULL != base);

    /* Sets junction temperature */
    uint32_t temp = RRAM_NVM_PROG(base) & ~ RRAMC_RRAM_SFR_NVM_PROG_TEMP_Msk;
    RRAM_NVM_PROG(base) = temp | _VAL2FLD(RRAMC_RRAM_SFR_NVM_PROG_TEMP, temperature);
}

/*******************************************************************************
* Function Name: Cy_RRAM_GetTemperature
****************************************************************************//**
*
* \brief
* Get junction temperature.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Temperature. Refer \ref cy_en_rram_temperature_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetTemperature
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_temperature_t Cy_RRAM_GetTemperature(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    /* Get junction temperature */
    return (cy_en_rram_temperature_t)_FLD2VAL(RRAMC_RRAM_SFR_NVM_PROG_TEMP, RRAM_NVM_PROG(base));
}

/*******************************************************************************
* Function Name: Cy_RRAM_SetProtLockableRegion
****************************************************************************//**
*
* \brief
* Sets the size of lockable region in PROTECTED_NVM region. If size is larger than
* PROTECTED_NVM, the entire PROTECTED_NVM is lockable. The lockable region can be configured
* only if the protected nvm lock state is unlocked. The configured region is protected only when the
* protected nvm lock state is locked
*
* \param base
* The pointer to the RRAMC instance.
*
* \param regionSize
* Size of lockable region in KB. The valid range is 1-256.
*
* \return
* Status. Refer \ref cy_en_rram_status_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetProtLockableRegion
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_SetProtLockableRegion(RRAMC_Type * base, uint32_t regionSize);


/*******************************************************************************
* Function Name: Cy_RRAM_GetProtLockableRegion
****************************************************************************//**
*
* \brief
* Gets the size of configured lockable region in PROTECTED_NVM region.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* Size of lockable region in KB.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetProtLockableRegion
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_RRAM_GetProtLockableRegion(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return _FLD2VAL(RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_0, RRAM_PROTECTED_LOCKABLE_LOCK(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetProtLock
****************************************************************************//**
*
* \brief
* Enables the lock for the configured PROTECTED_NVM region \ref Cy_RRAM_SetProtLockableRegion().
* Updating the configured region and lockable programming are NOT allowed. The topmost
* 1KB of lockable region which is always writable regardless of lock status.
* Once locked, the lock state cannot be changed till next reset.
*
* \param base
* The pointer to the RRAMC instance.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetProtLockableRegion
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetProtLock(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    RRAM_PROTECTED_LOCKABLE_LOCK(base) |= RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_LOCK_Msk;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetProtLockState
****************************************************************************//**
*
* \brief
* Get the lock state of the PROTECTED_NVM Lockable region.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return
* State. \ref cy_en_rram_protected_lock_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetProtLockableRegion
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_protected_lock_t Cy_RRAM_GetProtLockState(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return (cy_en_rram_protected_lock_t)_FLD2VAL(RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_LOCK, RRAM_PROTECTED_LOCKABLE_LOCK(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetUDSLock
****************************************************************************//**
*
* \brief
* Enables the lock to avoid access to UDS key.
* Once locked, the lock state cannot be changed till next reset.
*
* \param base
* The pointer to the RRAMC instance.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetUDSLock
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetUDSLock(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    RRAM_UDS_CTL(base) |= RRAMC_RRAMC_UDS_CTL_LOCK_Msk;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetUDSLockState
****************************************************************************//**
*
* \brief
* Get the status of UDS lock. If it is locked then there will be no access to UDS key.
* Until the lock is unlocked. The lock state cannot be changed till next reset.
*
* \param base
* The pointer to the RRAMC instance.
*
* \return lockState
* State of the lock. Refer \ref cy_en_rram_uds_lock_t
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetUDSLock
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_uds_lock_t Cy_RRAM_GetUDSLockState(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    return (cy_en_rram_uds_lock_t)_FLD2VAL(RRAMC_RRAMC_UDS_CTL_LOCK, RRAM_UDS_CTL(base));
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetUDSConfig
****************************************************************************//**
*
* \brief
* Configure UDS to trigger a AHB error or read as zero without error when there is a read
* access to UDS. It is effective only when UDS is locked.
*
* \param base
* The pointer to the RRAMC instance.
*
* \param config
* Set to true to trigger AHB error when there is a read access to UDS.
* Set to false to return read as zero for the read access without any AHB error.
*
* \funcusage
* \snippet rram/snippet/main.c snippet_Cy_RRAM_SetUDSLock
*
* \note
* This API is available for only CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetUDSConfig(RRAMC_Type * base, bool config)
{
    CY_ASSERT_L1(NULL != base);

    if(config)
    {
        RRAM_UDS_CTL(base) |= RRAMC_RRAMC_UDS_CTL_CONFIG_Msk;
    }
    else
    {
        RRAM_UDS_CTL(base) &= ~RRAMC_RRAMC_UDS_CTL_CONFIG_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_RRAM_ForceRelPCLock
****************************************************************************//**
*
* Release PC lock forcefully. In order to avoid deadlock situation during indirect
* write operation, CM0 has the capability to release or break the acquired lock.
* Should be called only when a pc lock acquired by CM33/CM55 during indirect write
* operation needs be released forcefully.
* This API can be called before the start of write operation from CM0.
* This API is only available for CM0 secure enclave.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_ForceRelPCLock(RRAMC_Type * base)
{
    CY_ASSERT_L1(NULL != base);

    RRAM_PC_MASK(base) &= ~RRAMC_RRAMC_PC_MASK_PC_LOCK_Msk;
}


/** \} group_rram_functions */

    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8')

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22RRAMC */

#endif /* CY_rram_H */

/** \} group_rram */

/* [] END OF FILE */
