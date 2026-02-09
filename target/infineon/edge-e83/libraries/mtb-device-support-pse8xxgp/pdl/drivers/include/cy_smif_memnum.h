/***************************************************************************//**
* \file cy_smif_memnum.h
* \version 1.0
*
* \brief
* This file provides the constants and parameter values for the memory-level APIs of the SMIF driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2025 Infineon Technologies AG or an affiliate of
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
* \addtogroup group_smif_memnum
* \{
* \section group_smif_section_secure_aware Secure Aware SMIF
* Some SMIF APIs are marked as Secure Aware.  This means that if the SMIF is marked
* as a secure resource in the Peripheral Protection Controller (PPC) and these
* APIs are called from a non-secure CPU state, the PDL will submit a request to the
* Secure Request Framework (SRF) middleware to transition to a secure CPU state to
* perform the operation.  From the application's perspective, the API will behave
* the same whether it is called from a secure or non-secure CPU state albeit slower.
*
* This functionality is automatically enabled on devices with ARM TrustZone processors.
* To disable, set the DEFINE+=CY_PDL_ENABLE_SECURE_AWARE_SMIF=0 in the application
* Makefile.
*
* For more information on Secure Aware PDL behavior, see \ref group_pdl_srf_general.
*
*/

#if !defined (CY_SMIF_MEMORYNUM_H)
#define CY_SMIF_MEMORYNUM_H

#include "cy_device.h"

#include "cy_pdl_srf.h"
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
#include "cy_pdl_srf_common.h"
#endif /* defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */

#if defined (CY_IP_MXSMIF)

#include <stdint.h>
#include <stdbool.h>
#include "cy_syslib.h"
#include "cy_smif.h"
#include "cy_smif_memslot.h"

#if defined(__cplusplus)
extern "C" {
#endif


#if !defined(CY_SMIF_MAX_HYBRID_REGION)
/** Maximum number of hybrid regions in the supported external memories*/
#define CY_SMIF_MAX_HYBRID_REGION      (5U)
#endif
/** SMIF sub-block 0 */
#define CY_SMIF_SUB_BLOCK_0             (0UL)
/** SMIF sub-block 1 */
#define CY_SMIF_SUB_BLOCK_1             (1UL)
/** SMIF flag to identify regular SPI devices */
#define CY_SMIF_FLAG_SPI_DEVICE          (1UL)
/** SMIF flag to identify HyperBus devices */
#define CY_SMIF_FLAG_HYPERBUS_DEVICE     (2UL)


/** The SMIF Device internal context data. The user must not modify it.
*  The contents of this struct are internal to the PDL and are subject to change.
*  The user allocates this struct but should not directly access its contents.
*  base, block_config, and smif_context are all initialized when Cy_SMIF_MemNumInit is called.
*  Only base is initialized when Cy_SMIF_MemNumSetupNonSecure is called.
*  The items below are only applicable if the memory in question can be
*  directly accessed (either because it is not secure, or because the
*  calling code is secure). They are included in the struct unconditionally
*  because there are two SMIFs and they could have different security attributes
*  Includes a pointer to an array of cy_stc_smif_mem_config_t* */
typedef struct
{
    SMIF_Type*                         base;                  /**< This stores the pointer to the base address of the SMIF instance*/
    cy_stc_smif_block_config_t const * block_config;          /**< This stores the pointer to the block config where applicable */
    cy_stc_smif_context_t              smif_context;          /**< This stores the info on the smif driver context */
    bool                               requires_secure_call;  /**< This specifies whether secure calls are needed */
} cy_stc_smif_mem_context_t;

/** This structure specifies data relevant to the non-secure side relative to hybrid sectors */
typedef struct
{
    uint32_t regionStartAddress;                 /**< This specifies the address where a region starts */
    uint32_t regionEndAddress;                   /**< This specifies the address where a region ends  */
    uint32_t eraseSize;                          /**< This specifies the erase size of one sector */
} cy_stc_smif_hyb_sectors_info_t;

/**
* This SMIF memory info structure is used to store the memory information that are useful to the
* non-secure side in Secure-Aware environments.
* The data structure is initialized by the secure side when the non secure side calls
* \ref Cy_SMIF_MemGetInfo. */
typedef struct
{
    uint32_t flags;                                           /**< Determines if the device is SPI/HyperBus */
    uint32_t memSize;                                         /**< The memory size: For densities of 2 gigabits or less - the size in bytes;
                                                              * For densities 4 gigabits and above - bit-31 is set to 1b to define that
                                                              * this memory is 4 gigabits and above; and other 30:0 bits define N where
                                                              * the density is computed as 2^N bytes.
                                                              * For example, 0x80000021 corresponds to 2^30 = 1 gigabyte.
                                                              */
    uint32_t eraseSize;                                      /**< This specifies the sector size of each Erase */
    uint32_t programSize;                                    /**< This specifies the page size for programming */
    uint32_t hybridRegionCount;                              /**< This specifies the number of regions for memory with hybrid sectors */
    cy_stc_smif_hyb_sectors_info_t hybridRegionInfo[CY_SMIF_MAX_HYBRID_REGION];  /**< This stores the information for the hybrid regions */

} cy_stc_smif_mem_info_t;

/** \cond INTERNAL */
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
/** This is only used by secure-aware. The structure contains SMIF status parameters */
typedef struct {
    cy_en_smif_status_t op_res;
} cy_pdl_smif_srf_status_out_t;

/** This is only used by secure-aware. The structure contains clean SMIF cache configuration parameters */
typedef struct {
    uint32_t address;
    uint32_t size;
} cy_pdl_smif_srf_clean_cache_in_t;

/** This is only used by secure-aware. The structure contains invalidate SMIF cache configuration parameters */
typedef struct {
    uint32_t address;
    uint32_t size;
} cy_pdl_smif_srf_invalidate_cache_in_t;

/** This is only used by secure-aware. The structure contains clean/invalidate SMIF cache configuration parameters */
typedef struct {
    uint32_t address;
    uint32_t size;
} cy_pdl_smif_srf_cl_inv_cache_in_t;
#endif
/** \endcond */

/*******************************************************************************
* Function Name: Cy_SMIF_MemNumInit
****************************************************************************//**
*
* This function initializes the slots of the memory device in the SMIF
* configuration. It's security aware and is a thin wrapper around
* \ref Cy_SMIF_MemInit. It can either be called in a secure partition or in
* the non-secure partition if the peripheral itself is not secured.
* \param base
* The address of the slave-slot device register to initialize.
*
* \param blockConfig
* The configuration structure array that configures the SMIF memory device to be
* mapped into the device's memory map. \ref cy_stc_smif_mem_config_t
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return The memory slot initialization status.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*       - \ref CY_SMIF_SFDP_SS0_FAILED
*       - \ref CY_SMIF_SFDP_SS1_FAILED
*       - \ref CY_SMIF_SFDP_SS2_FAILED
*       - \ref CY_SMIF_SFDP_SS3_FAILED
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumInit(SMIF_Type *base,
                            cy_stc_smif_block_config_t const * blockConfig,
                            cy_stc_smif_mem_context_t *context);

#if !defined(COMPONENT_SECURE_DEVICE)
/*******************************************************************************
* Function Name: Cy_SMIF_MemNumSetupNonSecure
****************************************************************************//**
*
* This function is to be called from the non secure world to set up the context
* to be correctly used in subsequent MemNum calls.
* It's security aware.
*
* \param base
* The address of the slave-slot device register to initialize.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return The memory slot initialization status.
*       - \ref CY_SMIF_SUCCESS
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumSetupNonSecure(SMIF_Type *base,
                            cy_stc_smif_mem_context_t *context);
#endif

/*******************************************************************************
* Function Name: Cy_SMIF_MemNumGetInfo
****************************************************************************//**
*
* This function is to be called from the non secure partition in trustzone
* devices to gather all information about the memory size, erase and program size
* to be used in subsequent MemNum calls instead of polling the secure partition
* repeatedly for the information.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to get information for.
* \param memNumInfo
* This is the pointer to the info structure ot type \ref cy_stc_smif_mem_info_t
* to populate.
*
* \return The memory slot initialization status.
*       - \ref CY_SMIF_SUCCESS
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context and memNumInfo arguments are DCache aligned when calling
* from a non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumGetInfo(const cy_stc_smif_mem_context_t *context,
                            uint8_t memNum,
                            cy_stc_smif_mem_info_t *memNumInfo);

/*******************************************************************************
* Function Name: Cy_SMIF_MemRead
****************************************************************************//**
*
* Reads data from the external memory and blocks until the read
* transfer is complete or a timeout occurs.
* This is a blocking function, it will block the execution flow until
* the command transmission is completed.
* It is security aware.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform read operation on.
*
* \param address
* The address to read data from. In case of Octal DDR, address must be an even address.
*
* \param rxBuffer
* The buffer for storing the read data.
*
* \param length
* The size of data to read.
*
* \return The status of the operation. See \ref cy_en_smif_status_t.
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context and rxBuffer arguments are DCache aligned when calling
* from a non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumRead(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                    uint32_t address, uint8_t rxBuffer[],
                                    uint32_t length);

/*******************************************************************************
* Function Name: Cy_SMIF_MemWrite
****************************************************************************//**
*
* This function writes data to the external memory.
* This is a blocking function, it will block the execution flow until
* the command transmission is completed.
* It is security aware.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform write operation on.
*
* \param address
* The address to write data at. In case of Octal DDR, address must be an even address.
*
* \param txBuffer
* The buffer holding the data to write in the external memory.
*
* \param length
* The size of data to write.
*
* \return The status of the operation. See \ref cy_en_smif_status_t.
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context and txBuffer arguments are DCache aligned when calling
* from a non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumWrite(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                     uint32_t address, uint8_t const txBuffer[],
                                     uint32_t length);

/*******************************************************************************
* Function Name: Cy_SMIF_MemEraseSector
****************************************************************************//**
*
* Erases a block/sector of the external memory.
* This is a blocking function, it will block the execution flow until
* the command transmission is completed.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform erase sector operation on.
*
* \param address
* The address of the block to be erased. The address will be aligned to
* the start address of the sector in which address is located.
*
* \param length
* The length of data to erase. The length will be aligned to the sector
* boundary where end address is located. If length exceeds memory size
* API returns \ref CY_SMIF_BAD_PARAM without performing erase operation.
*
* \return The status of the operation. See \ref cy_en_smif_status_t.
*
* \note Memories like hybrid have sectors of different sizes. \n
* Check the address and length parameters before calling this function.
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context argument is DCache aligned when calling from a
* non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumEraseSector(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                           uint32_t address, uint32_t length);

/*******************************************************************************
* Function Name: Cy_SMIF_MemEraseChip
****************************************************************************//**
*
* Erases the entire chip of the external memory.
* This is a blocking function, it will block the execution flow until
* the command transmission is completed.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform erase sector operation on.
*
* \return The status of the operation. See \ref cy_en_smif_status_t.
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured and therefore the
* EraseChip function will not be run.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context argument is DCache aligned when calling from a
* non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumEraseChip(cy_stc_smif_mem_context_t *context, uint8_t memNum);

/*******************************************************************************
* Function Name: Cy_SMIF_MemNumHyperBusRead
****************************************************************************//**
*
* This function reads data from hyper bus memory in MMIO mode.
* It's security aware and is a thin wrapper around \ref Cy_SMIF_HyperBus_Read.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform read operation on.
*
* \param address
* The address to read data from. In case of Octal DDR, address must be an even address.
*
* \param rxBuffer
* The buffer for storing the read data.
*
* \param length
* The size of data to read.
*
* \return \ref cy_en_smif_status_t
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context and rxBuffer arguments are DCache aligned when calling
* from a non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumHyperBusRead(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                    uint32_t address, uint8_t rxBuffer[],
                                    uint32_t length);

/*******************************************************************************
* Function Name: Cy_SMIF_MemNumHyperBusWrite
****************************************************************************//**
*
* This function writes data into hyper bus memory in MMIO mode.
* It's security aware and is a thin wrapper around \ref Cy_SMIF_HyperBus_Write.
*
* \param context
* This is the pointer to the context structure \ref cy_stc_smif_mem_context_t
* allocated by the user. The structure is used during the SMIF
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \param memNum
* The Slave Slot number associated to the memory in qspi-configurator
* to perform write operation on.
*
* \param address
* The address to write data at. In case of Octal DDR, address must be an even address.
*
* \param txBuffer
* The buffer holding the data to write in the external memory.
*
* \param length
* The size of data to write.
*
* \return \ref cy_en_smif_status_t
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.  See
* \ref group_smif_section_secure_aware for further details. When determining
* whether an address range is accessible or not, there is a limitation that only
* XIP mapped addresses are considered. So if only a portion of the external memory
* is memory mapped, the remaining portion will be considered secured.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that context and txBuffer arguments are DCache aligned when calling
* from a non-secured Core onto a secured hardware resource.  This is only relevent for
* cross-core calls, not calls between security contexts on the same core.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MemNumHyperBusWrite(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                     uint32_t address, uint8_t const txBuffer[],
                                     uint32_t length);

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSMIF */

#endif /* (CY_SMIF_MEMORYSLOT_H) */

/** \} group_smif_memnum */

/* [] END OF FILE */
