/***************************************************************************//**
* \file cy_rram.c
* \version 1.10
*
* \brief
* Provides an API implementation of the RRAM driver.
*
********************************************************************************
* \copyright
* Copyright (c) 2022-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_rram.h"
#ifdef WA__PM_0159902_6
#include "cy_ipc_drv.h"
#endif
#if defined (CY_IP_MXS22RRAMC)
#include "cy_ms_ctl.h"

/*******************************************************************************
*       Internal Defines
*******************************************************************************/
/* Time out value is calculated considering worst case cycles required for 10ms with max core freq of 400MHz */
/* Make sure this delay is multiple of CY_RRAM_STATUS_CHECK_DELAY */
#define CY_RRAM_OPERATION_TIMEOUT                  (4000000UL)
/* Delay in cpu cycles before repeating the status check */
#define CY_RRAM_STATUS_CHECK_DELAY                 (50UL)
/* Maximum number of write trials */
#define CY_RRAM_MAX_WRITE_TRIALS                   (3UL)

/* RRAM read operation ECC fail status */
#define CY_RRAM_ECC_READ_NO_FAIL                   (0x00000000UL)                         /**< Read is success without any ECC fail */
#define CY_RRAM_ECC_READ_SINGLE_BIT_FAIL           RRAMC_RRAM_SFR_NVM_STATUS_ECC1READ_Msk /**< At least one ECC single-bit failure was detected and corrected during the last memory read operation */
#define CY_RRAM_ECC_READ_DOUBLE_BIT_FAIL           RRAMC_RRAM_SFR_NVM_STATUS_ECC2READ_Msk /**< At least one ECC double-bit failure was detected and corrected during the last memory read operation */
#define CY_RRAM_ECC_READ_TRIPLE_BIT_FAIL           RRAMC_RRAM_SFR_NVM_STATUS_ECC3READ_Msk /**< At least one ECC triple-bit failure was detected and corrected during the last memory read operation */
#define CY_RRAM_ECC_READ_MULTIPLE_BIT_FAIL         RRAMC_RRAM_SFR_NVM_STATUS_ECC4READ_Msk /**< At least one ECC-uncorrectable multi-bit failure was detected during the last memory read operation */
#define CY_RRAM_ECC_READ_ADDRESS_MISMATCH          RRAMC_RRAM_SFR_NVM_STATUS_ECCAREAD_Msk /**< At least one address mismatch ECC failure was detected during the last memory read operation */
#define CY_RRAM_ECC_READ_BLOCK_SINGLE_BIT_FAIL     RRAMC_RRAM_SFR_NVM_STATUS_ECC1MRD_Msk  /**< An ECC single-bit failure was detected and corrected during the most recent memory read operation to a new block */
#define CY_RRAM_ECC_READ_BLOCK_DOUBLE_BIT_FAIL     RRAMC_RRAM_SFR_NVM_STATUS_ECC2MRD_Msk  /**< An ECC double-bit failure was detected and corrected during the most recent memory read operation to a new block */
#define CY_RRAM_ECC_READ_BLOCK_TRIPLE_BIT_FAIL     RRAMC_RRAM_SFR_NVM_STATUS_ECC3MRD_Msk  /**< An ECC triple-bit failure was detected and corrected during the most recent memory read operation to a new block */
#define CY_RRAM_ECC_READ_BLOCK_MULTIPLE_BIT_FAIL   RRAMC_RRAM_SFR_NVM_STATUS_ECC4MRD_Msk  /**< An ECC-uncorrectable multi-bit failure was detected during the most recent memory read operation to a new block */
#define CY_RRAM_ECC_READ_BLOCK_ADDRESS_MISMATCH    RRAMC_RRAM_SFR_NVM_STATUS_ECCAMRD_Msk  /**< An address mismatch ECC failure was detected during the most recent memory read operation to a new block */

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 2, \
'Value extracted from _VAL2FLD macro will not exceed enum range.')

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 14.3', 12, \
'Because the size of work, flash subsection is zero but will be true if devices have valid size.')


/* RRAM config structure */
typedef struct
{
    RRAMC_Type * base;         /*!< The pointer to the RRAMC instance.*/
    uint32_t addr;             /*!< Address of the RRAM subregion.*/
    uint32_t subRegionBase;    /*!< Base address of subregion.*/
    uint32_t subRegionSize;    /*!< Size of subregion.*/
    bool blockingWrite;        /*!< To define blocking write for indirect write operation.*/
    bool tearingSafe;          /*!< Boolean to check if API is called from tearing safe library.*/
} cy_stc_rram_config_t;

typedef struct
{
    uint32_t base;    /*!< Base address of subregion.*/
    uint32_t size;    /*!< Size of subregion.*/
}  cy_stc_rram_rgn_info_t;

typedef union
{
    uint32_t w[4];    /*!< Store word data.*/
    uint8_t b[16];    /*!< Store byte data.*/
} cy_rram_blk_buf_t;


/*******************************************************************************
* Function Name: Cy_RRAM_AcquirePCLock
****************************************************************************//**
*
* Acquire a PC lock for RRAM to perform indirect operations.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_RRAM_AcquirePCLock(RRAMC_Type * base)
{
    bool status = false;
    uint32_t activePC;
    uint32_t savedIntrStatus;

    /* Enter Critical section */
    savedIntrStatus = Cy_SysLib_EnterCriticalSection();

#ifdef WA__PM_0159902_6
    if (CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_LockAcquire (Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_RRAM_LOCK)))
    {
        /* Exit Critical section */
        Cy_SysLib_ExitCriticalSection(savedIntrStatus);
        return false;
    }
#endif

    RRAM_PC_MASK(base) |= _VAL2FLD(RRAMC_RRAMC_PC_MASK_PC_LOCK, CY_RRAM_PC_LOCK_ACQUIRE);

    /* Get the value of active PC */
    #if (CY_CPU_CORTEX_M0P)
    activePC = ((uint32_t)_FLD2VAL(M0SECCPUSS_CM0_MS_PC_PC, M0SECCPUSS_CM0_MS_PC));
    #elif (CY_CPU_CORTEX_M33)
    activePC = Cy_Ms_Ctl_GetActivePC(CY_MS_CTL_ID_CM33_0);
    #else // CY_CPU_CORTEX_M55
    activePC = Cy_Ms_Ctl_GetActivePCV1(CY_MS_CTL_ID_CM55_MS_0);
    #endif

    if((_FLD2VAL(RRAMC_RRAMC_PC_MASK_PC, RRAM_PC_MASK(base)) == activePC) && \
                   (_FLD2VAL(RRAMC_RRAMC_PC_MASK_PC_LOCK, RRAM_PC_MASK(base)) == CY_RRAM_PC_LOCK_ACQUIRE))
    {
        status = true;
    }

    /* Exit Critical section */
    Cy_SysLib_ExitCriticalSection(savedIntrStatus);

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_ReleasePCLock
****************************************************************************//**
*
* Release PC lock.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_ReleasePCLock(RRAMC_Type * base)
{
    RRAM_PC_MASK(base) &= ~RRAMC_RRAMC_PC_MASK_PC_LOCK_Msk;
#ifdef WA__PM_0159902_6
    (void)Cy_IPC_Drv_LockRelease (Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_RRAM_LOCK), CY_IPC_NO_NOTIFICATION);
#endif
}


/*******************************************************************************
* Function Name: Cy_RRAM_IsPCLockAcquired
****************************************************************************//**
*
* Indicates whether PC lock is acquired or not.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_RRAM_IsPCLockAcquired(RRAMC_Type * base)
{
#ifdef WA__PM_0159902_6
    (void) base;
    return (Cy_IPC_Drv_IsLockAcquired (Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_RRAM_LOCK)));
#else
    return (_FLD2VAL(RRAMC_RRAMC_PC_MASK_PC_LOCK, RRAM_PC_MASK(base)) == CY_RRAM_PC_LOCK_ACQUIRE);
#endif
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetOperationMode
****************************************************************************//**
*
* Sets operation mode refer cy_en_rram_operation_t for supported operations.
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_SetOperationMode(RRAMC_Type * base, cy_en_rram_operation_t operation)
{
    uint32_t temp = RRAM_NVM_PROG(base) & ~ RRAMC_RRAM_SFR_NVM_PROG_ACTION_Msk;
    RRAM_NVM_PROG(base) = temp | _VAL2FLD(RRAMC_RRAM_SFR_NVM_PROG_ACTION, operation);
}


/*******************************************************************************
* Function Name: Cy_RRAM_StartOperation
****************************************************************************//**
*
* Start the RRAM operation that is set by Cy_RRAM_SetOperationMode().
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_StartOperation(RRAMC_Type * base)
{
    RRAM_NVM_PROG(base) |= RRAMC_RRAM_SFR_NVM_PROG_STARTOP_Msk;
}

#if (CY_CPU_CORTEX_M0P)
/*******************************************************************************
* Function Name: Cy_RRAM_StopOperation
****************************************************************************//**
*
* Stop the RRAM operation that is set by Cy_RRAM_SetOperationMode().
*
*******************************************************************************/
__STATIC_INLINE void Cy_RRAM_StopOperation(RRAMC_Type * base)
{
    RRAM_NVM_PROG(base) &= ~RRAMC_RRAM_SFR_NVM_PROG_STARTOP_Msk;
}
#endif


/*******************************************************************************
* Function Name: CY_RRAM_GetFailBitInfo
****************************************************************************//**
*
* Information on number of fail bits for a block after verify in indirect
* write operation.
*
*******************************************************************************/
__STATIC_INLINE cy_en_rram_verr_status_t CY_RRAM_GetFailBitInfo(RRAMC_Type * base)
{
    return (cy_en_rram_verr_status_t)_FLD2VAL(RRAMC_RRAM_SFR_NVM_STATUS_VERR, RRAM_NVM_STATUS(base));
}


/*******************************************************************************
* Function Name: CY_RRAM_ReadOperationECCStatus
****************************************************************************//**
*
* Indicates ECC-status. ECC single, double and triple bit failures in read operation
* are treated as only warnings.
*
*******************************************************************************/
__STATIC_INLINE bool CY_RRAM_ReadOperationECCStatus(RRAMC_Type * base, uint32_t ecc_error)
{
    return (0U != (RRAM_NVM_STATUS(base) & ecc_error));
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetOTPSubRegionInfo
****************************************************************************//**
*
* Get base address, size of the OTP sub region for the provided address.
*
*******************************************************************************/
static cy_stc_rram_rgn_info_t Cy_RRAM_GetOTPSubRegionInfo(uint32_t addr)
{
    uint32_t secureBitState = addr & CY_RRAM_S_OFFSET_MASK;
    cy_stc_rram_rgn_info_t rgnInfo= {CY_RRAM_INVALID_ACCESS, 0UL};

    addr &= ~CY_RRAM_S_OFFSET_MASK;

    if((addr >= CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS) && (addr <= CY_RRAM_GENERAL_OTP_MMIO_NS_END_ADDRESS))
    {
        addr = CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_GENERAL_OTP_SIZE;
    }
    else if((addr >= CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS) && (addr <= CY_RRAM_PROTECTED_OTP_PROTECTED_NS_END_ADDRESS))
    {
        addr = CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_PROTECTED_OTP_SIZE;
    }
    else
    {
        secureBitState = 0UL;
    }

    addr |= secureBitState;
    rgnInfo.base = addr;

    return rgnInfo;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetNVMSubRegionInfo
****************************************************************************//**
*
* Get base address, size of the NVM sub region for the provided address.
*
*******************************************************************************/
static cy_stc_rram_rgn_info_t Cy_RRAM_GetNVMSubRegionInfo(uint32_t addr)
{
    uint32_t secureBitState = addr & CY_RRAM_S_OFFSET_MASK;
    cy_stc_rram_rgn_info_t rgnInfo = {CY_RRAM_INVALID_ACCESS, 0UL};

    addr &= ~CY_RRAM_S_OFFSET_MASK;

    if((addr >= CY_RRAM_MAIN_HOST_NS_START_ADDRESS) && (addr <= CY_RRAM_MAIN_HOST_NS_END_ADDRESS + CY_RRAM_PROTECTED_REGION_SIZE))
    {
        addr = CY_RRAM_MAIN_HOST_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_MAIN_REGION_SIZE + CY_RRAM_PROTECTED_REGION_SIZE;
    }
    else if((addr >= CY_RRAM_WORK_HOST_NS_START_ADDRESS) && (addr <= CY_RRAM_WORK_HOST_NS_END_ADDRESS))
    {
        addr = CY_RRAM_WORK_HOST_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_WORK_REGION_SIZE;
    }
    else if((addr >= CY_RRAM_SFLASH_HOST_NS_START_ADDRESS) && (addr <= CY_RRAM_SFLASH_HOST_NS_END_ADDRESS))
    {
        addr = CY_RRAM_SFLASH_HOST_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_SFLASH_REGION_SIZE;
    }
    else if((addr >= CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS) && (addr <= CY_RRAM_PROTECTED_HOST_NS_END_ADDRESS))
    {
        addr = CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_PROTECTED_REGION_SIZE;
    }
#if (CY_CPU_CORTEX_M0P)
    else if((addr >= CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS) && (addr <= CY_RRAM_PROTECTED_PROTECTED_NS_END_ADDRESS))
    {
        addr = CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_PROTECTED_REGION_SIZE;
    }
#endif
#if (CY_CPU_CORTEX_M33)
    else if((addr >= CY_RRAM_MAIN_HOST_CBUS_NS_START_ADDRESS) && (addr <= CY_RRAM_MAIN_HOST_CBUS_NS_END_ADDRESS))
    {
        addr = CY_RRAM_MAIN_HOST_CBUS_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_MAIN_REGION_SIZE;
    }
    else if((addr >= CY_RRAM_PROTECTED_HOST_CBUS_NS_START_ADDRESS) && (addr <= CY_RRAM_PROTECTED_HOST_CBUS_NS_END_ADDRESS))
    {
        addr = CY_RRAM_PROTECTED_HOST_CBUS_NS_START_ADDRESS;
        rgnInfo.size = CY_RRAM_PROTECTED_REGION_SIZE;
    }
#endif
    else
    {
        secureBitState = 0UL;
    }
    addr |= secureBitState;
    rgnInfo.base = addr;

    return rgnInfo;
}


/*******************************************************************************
* Function Name: Cy_RRAM_GetPhyBase
****************************************************************************//**
*
* Get the physical base address for the provided logical base address.
*
*******************************************************************************/
static uint32_t Cy_RRAM_GetPhyBase(uint32_t addr)
{
    uint32_t physicalAddr = 0;
    addr &= ~CY_RRAM_S_OFFSET_MASK;

    if(addr == CY_RRAM_MAIN_HOST_NS_START_ADDRESS)
    {
       physicalAddr= CY_RRAM_PHYSICAL_MAIN_BASE_ADDR;
    }
    else if(addr == CY_RRAM_WORK_HOST_NS_START_ADDRESS)
    {
        physicalAddr= CY_RRAM_PHYSICAL_WORK_BASE_ADDR;
    }
    else if(addr == CY_RRAM_SFLASH_HOST_NS_START_ADDRESS)
    {
        physicalAddr= CY_RRAM_PHYSICAL_SFLASH_BASE_ADDR;
    }
    else if(addr == CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS)
    {
        physicalAddr= CY_RRAM_PHYSICAL_PROTECTED_BASE_ADDR;
    }
#if (CY_CPU_CORTEX_M0P)
    else if(addr == CY_RRAM_PROTECTED_PROTECTED_NS_START_ADDRESS)
    {
        physicalAddr= CY_RRAM_PHYSICAL_PROTECTED_BASE_ADDR;
    }
#endif
    else if(addr == CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS)
    {
       physicalAddr= CY_RRAM_PHYSICAL_GENERAL_OTP_BASE_ADDR;
    }
    else
    {
        physicalAddr = CY_RRAM_PHYSICAL_PROTECTED_OTP_BASE_ADDR;
    }
    return physicalAddr;
}


/*******************************************************************************
* Function Name: Cy_RRAM_ReadBlock
****************************************************************************//**
*
* Read one of block data from the specified address.
*
*******************************************************************************/
static cy_en_rram_status_t Cy_RRAM_ReadBlock(cy_stc_rram_config_t * config, uint8_t * data, uint32_t pos, uint32_t numBytes)
{
    cy_rram_blk_buf_t blk;
    volatile uint32_t *readAddr = (uint32_t *) config->addr;
    cy_en_rram_status_t status = CY_RRAM_ECC_FAIL;
    uint32_t timeout;

    if(config->tearingSafe)
    {
        uint32_t phy_addr = Cy_RRAM_GetPhyBase(config->subRegionBase) +
                                ((config->addr - config->subRegionBase) / CY_RRAM_BLOCK_SIZE_BYTES);

        /* Set mode to idle to meet initialization condition. */
        Cy_RRAM_SetOperationMode(config->base, CY_RRAM_IDLE);

        /* Set operation mode to indirect write. */
        Cy_RRAM_SetOperationMode(config->base, CY_RRAM_INDIRECT_WRITE);

        /* Set the module-internal target address (physical address) */
        RRAM_NVM_ADDR(config->base) = phy_addr;

        timeout = CY_RRAM_OPERATION_TIMEOUT / CY_RRAM_STATUS_CHECK_DELAY;

        /* Wait until internal read operation is completed. As per RRAM IP team,
        * there is no need for timeout as the state machine will definitely
        * return to non-busy state. As a safety measure this timeout is added */
        while(Cy_RRAM_IsBusy(config->base) && (0UL != timeout))
        {
            timeout--;
            Cy_SysLib_DelayCycles(CY_RRAM_STATUS_CHECK_DELAY);
        }

        if(timeout == 0UL)
        {
            return CY_RRAM_OPERATION_TIME_OUT_ERROR;
        }

        /* Validate ECC status */
        if(!CY_RRAM_ReadOperationECCStatus(config->base, CY_RRAM_ECC_READ_BLOCK_MULTIPLE_BIT_FAIL))
        {
            /* Continue and read block, there is no uncorrectable ECC errors */
            status = CY_RRAM_SUCCESS;
        }

        /* Set mode to idle */
        Cy_RRAM_SetOperationMode(config->base, CY_RRAM_IDLE);
    }
    else
    {
        /* Set status to success if read operation is not called from TS library. */
        status = CY_RRAM_SUCCESS;
    }

    if(status == CY_RRAM_SUCCESS)
    {
        for (uint32_t wordCount = 0UL; wordCount < CY_RRAM_BLOCK_SIZE_WORDS; wordCount++)
        {
            blk.w[wordCount] = *readAddr++;
        }

        for (; numBytes != 0UL; --numBytes)
        {
            *data++ = blk.b[pos++];
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_SubRegionReadData
****************************************************************************//**
*
* Reads a number of bytes to a array from the provided address.
*
*******************************************************************************/
static cy_en_rram_status_t Cy_RRAM_SubRegionReadData(cy_stc_rram_config_t * config, uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    /* Validate the parameters */
    if((config->subRegionSize - (config->addr - config->subRegionBase)) < numBytes)
    {
        return status;
    }
    else
    {
        /* The status is being set to SUCCESS in order to make one of the
           entry check for read aligned blocks case as true.
           While reading from an non-aligned block address the status will be overwritten
           based on result from Cy_RRAM_ReadBlock.*/
        status = CY_RRAM_SUCCESS;
    }

    /* Offset in bytes from block boundary */
    uint32_t offsetStart = config->addr & 0x0FUL;

    /* If the address is not aligned to the block boundary or the number of bytes to
    * read is less than one block
    */
    if (0UL != offsetStart)
    {
        uint32_t blkAlignedAddr = config->addr & ~0x0FUL;
        uint32_t bytesInFirstBlk = CY_RRAM_BLOCK_SIZE_BYTES - offsetStart;

        /* If there is more room in this block than the number of bytes to read */
        if (bytesInFirstBlk > numBytes)
        {
            bytesInFirstBlk = numBytes;
        }
        config->addr = blkAlignedAddr;
        status = Cy_RRAM_ReadBlock(config, data, offsetStart, bytesInFirstBlk);

        config->addr += CY_RRAM_BLOCK_SIZE_BYTES;
        numBytes  -= bytesInFirstBlk;
        data += bytesInFirstBlk;
    }

    /* Read complete 16-byte aligned blocks */
    uint32_t blockCount = numBytes / CY_RRAM_BLOCK_SIZE_BYTES;
    while (blockCount > 0UL)
    {
        if(CY_RRAM_SUCCESS != status)
        {
            break;
        }
        status = Cy_RRAM_ReadBlock(config, data, 0UL, CY_RRAM_BLOCK_SIZE_BYTES);
        config->addr += CY_RRAM_BLOCK_SIZE_BYTES;
        numBytes    -= CY_RRAM_BLOCK_SIZE_BYTES;
        data += CY_RRAM_BLOCK_SIZE_BYTES;
        blockCount --;
    }

    /* Read remaining bytes from the beginning of the last block */
    if ((0UL != numBytes) && (CY_RRAM_SUCCESS == status))
    {
        status = Cy_RRAM_ReadBlock(config, data, 0UL, numBytes);
    }

    return status;
}

/*
 * By default ECC Check is Enabled. This API is not meant for user. This API is used only during very early stage of
 * pre-silicon bring-up activity. During bring-up, RRAM test application can override this and disable ECC checking when tag
 * bits are being reset. Once the tag bits are reset, the test app can enable it so that ECC can be checked for normal
 * functionality of the driver.
 */

__WEAK bool cy_rram_should_check_ecc(void)
{
    return true;
}

/*******************************************************************************
* Function Name: Cy_RRAM_UpdateBlock
****************************************************************************//**
*
* Update one 16-byte RRAM block.
*
*******************************************************************************/
static cy_en_rram_status_t Cy_RRAM_UpdateBlock(cy_stc_rram_config_t * config, const uint8_t * data, uint32_t pos, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_ECC_FAIL;
    cy_rram_blk_buf_t blk;
    uint32_t timeout;
    volatile uint32_t *nvm_addr = (uint32_t *) config->addr;
    uint32_t phy_addr = Cy_RRAM_GetPhyBase(config->subRegionBase) + ((config->addr - config->subRegionBase) / CY_RRAM_BLOCK_SIZE_BYTES);

    bool is_otp = (((config->addr >= CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS) && (config->addr <= CY_RRAM_GENERAL_OTP_MMIO_NS_END_ADDRESS)) ||
                   ((config->addr >= CY_RRAM_GENERAL_OTP_MMIO_S_START_ADDRESS) && (config->addr <= CY_RRAM_GENERAL_OTP_MMIO_S_END_ADDRESS)) ||
                   ((config->addr >= CY_RRAM_PROTECTED_OTP_PROTECTED_S_START_ADDRESS) && (config->addr <= CY_RRAM_PROTECTED_OTP_PROTECTED_S_END_ADDRESS)) ||
                   ((config->addr >= CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS) && (config->addr <= CY_RRAM_PROTECTED_OTP_PROTECTED_NS_END_ADDRESS)));

    /* Set the module-internal target address (physical address) */
    RRAM_NVM_ADDR(config->base) = phy_addr;

    timeout = CY_RRAM_OPERATION_TIMEOUT / CY_RRAM_STATUS_CHECK_DELAY;

    /* Wait until internal read operation is completed. As per RRAM IP team,
    * there is no need for timeout as the state machine will definitely
    * return to non-busy state. As a safety measure this timeout is added */
    while(Cy_RRAM_IsBusy(config->base) && (0UL != timeout))
    {
        timeout--;
        Cy_SysLib_DelayCycles(CY_RRAM_STATUS_CHECK_DELAY);
    }

    if(timeout == 0UL)
    {
        return CY_RRAM_OPERATION_TIME_OUT_ERROR;
    }

    /* Validate ECC status */
    if (CY_RRAM_ReadOperationECCStatus(config->base, CY_RRAM_ECC_READ_BLOCK_MULTIPLE_BIT_FAIL))
    {
        if ((!config->tearingSafe) && cy_rram_should_check_ecc())
        {
            return CY_RRAM_ECC_FAIL;
        }

        /* If the block is partially modified, fill block with zero. The block
        * content can't be read due to ECC error.
        */
        for (uint32_t wordCount = 0UL; wordCount < CY_RRAM_BLOCK_SIZE_WORDS; wordCount++)
        {
            blk.w[wordCount] = 0UL;
        }
    }
    else
    {
        /* If the block is partially modified or is located in OTP */
        if ((0UL != pos) || (numBytes < CY_RRAM_BLOCK_SIZE_BYTES) || is_otp)
        {
            for (uint32_t wordCount = 0UL; wordCount < CY_RRAM_BLOCK_SIZE_WORDS; wordCount++)
            {
                blk.w[wordCount] = nvm_addr[wordCount];
            }
        }
    }

    /* Update the block buffer with the data to be written */
    if (is_otp)
    {
        for (; numBytes != 0UL; --numBytes)
        {
            blk.b[pos++] |= *data++;
        }
    }
    else
    {
        for (; numBytes != 0UL; --numBytes)
        {
            blk.b[pos++] = *data++;
        }
    }

    /* Compare the NVM_ADDR register against the correct address before starting the write operation */
    if (RRAM_NVM_ADDR(config->base) != phy_addr)
    {
        return CY_RRAM_WRITE_OPERATION_ERROR;
    }

    if(config->blockingWrite)
    {
        for (uint32_t trials = 0; trials < CY_RRAM_MAX_WRITE_TRIALS; trials++)
        {
            /* Initiate AHB write transactions */
            for (uint32_t wordCount = 0UL; wordCount < CY_RRAM_BLOCK_SIZE_WORDS; wordCount++)
            {
                nvm_addr[wordCount] = blk.w[wordCount];
            }

            Cy_RRAM_StartOperation(config->base);

            timeout = CY_RRAM_OPERATION_TIMEOUT / CY_RRAM_STATUS_CHECK_DELAY;

            /* Check for the actual write completion. As per RRAM IP team,
            * there is no need for timeout as the state machine will definitely
            * return to non-busy state. As a safety measure this timeout is added */
            while(Cy_RRAM_IsBusy(config->base) && (0UL != timeout))
            {
                timeout--;
                Cy_SysLib_DelayCycles(CY_RRAM_STATUS_CHECK_DELAY);
            }

            if(timeout == 0UL)
            {
                status = CY_RRAM_OPERATION_TIME_OUT_ERROR;
                break;
            }

            cy_en_rram_verr_status_t verrStatus= CY_RRAM_GetFailBitInfo(config->base);

            /* if no error or single bit error then return success. After final trial if there is a two bit error then also return success */
            if((verrStatus == CY_RRAM_NO_ERROR) ||
               (verrStatus == CY_RRAM_SINGLE_BIT_ERROR) ||
               ((verrStatus == CY_RRAM_DOUBLE_BIT_ERROR) && (trials == (CY_RRAM_MAX_WRITE_TRIALS - 1UL))))
            {
                status = CY_RRAM_SUCCESS;
                break;
            }
            /* For any error other than two or three bit and ECC uncorrectable bit error, return failure */
            else if((verrStatus == CY_RRAM_ECC_ADDR_MISMATCH_ERROR) ||
                    (verrStatus == CY_RRAM_CONFIG_ERROR) ||
                    (verrStatus == CY_RRAM_ALGORITHM_ERROR))
            {
                status = CY_RRAM_VERR_BLOCK_FAIL_BITS;
                break;
            }
            /* Control will reach here when there is two bit or three bit or ECC Uncorrectable bit error. But it will reach here in the
               final trial only when there is three bit or ECC uncorrectable bit error */
            else
            {
                status = CY_RRAM_VERR_BLOCK_FAIL_BITS;
            }
        }
    }
    else
    {
        /* Initiate AHB write transactions */
        for (uint32_t wordCount = 0UL; wordCount < CY_RRAM_BLOCK_SIZE_WORDS; wordCount++)
        {
            nvm_addr[wordCount] = blk.w[wordCount];
        }
        Cy_RRAM_StartOperation(config->base);
        status = CY_RRAM_SUCCESS;
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_SubRegionWriteData
****************************************************************************//**
*
* Writes a number of bytes starting from the provided target address.
*
*******************************************************************************/
static cy_en_rram_status_t Cy_RRAM_SubRegionWriteData(cy_stc_rram_config_t * config, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if((config->subRegionSize - (config->addr - config->subRegionBase)) < numBytes)
    {
        return status;
    }
    else
    {
        /* The status is being set to SUCCESS in order to make one of the
           entry check for only Write complete 16-byte aligned blocks case as true.
           While writing to a non-aligned block address the status will be overwritten
           based on result from Cy_RRAM_UpdateBlock.*/
        status = CY_RRAM_SUCCESS;
    }

    /* Set mode to idle to meet initialization condition */
    Cy_RRAM_SetOperationMode(config->base, CY_RRAM_IDLE);

    /* Set operation mode.to indirect write.*/
    Cy_RRAM_SetOperationMode(config->base, CY_RRAM_INDIRECT_WRITE);

    /* Offset in bytes from block boundary */
    uint32_t offsetStart = config->addr & 0x0FUL;

    /* If the address is not aligned to the block boundary or the number of bytes to
    * write is less than one block
    */
    if (0UL != offsetStart)
    {
        uint32_t blkAlignedAddr = config->addr & ~0x0FUL;
        uint32_t bytesInFirstBlk = CY_RRAM_BLOCK_SIZE_BYTES - offsetStart;

        /* If there is more room in this block than the number of bytes to write */
        if (bytesInFirstBlk > numBytes)
        {
            bytesInFirstBlk = numBytes;
        }

        config->addr = blkAlignedAddr;
        status = Cy_RRAM_UpdateBlock(config, data, offsetStart, bytesInFirstBlk);

        numBytes -= bytesInFirstBlk;
        data += bytesInFirstBlk;
        config->addr += CY_RRAM_BLOCK_SIZE_BYTES;
    }

    /* Write complete 16-byte aligned blocks */
    uint32_t blockCount = numBytes / CY_RRAM_BLOCK_SIZE_BYTES;
    for (uint32_t i = 0UL; i < blockCount; ++i)
    {
        if(CY_RRAM_SUCCESS != status)
        {
            break;
        }
        status = Cy_RRAM_UpdateBlock(config, data, 0UL, CY_RRAM_BLOCK_SIZE_BYTES);
        config->addr += CY_RRAM_BLOCK_SIZE_BYTES;
        numBytes    -= CY_RRAM_BLOCK_SIZE_BYTES;
        data += CY_RRAM_BLOCK_SIZE_BYTES;
    }

    /* Write remaining bytes at the beginning of the last block */
    if ((0UL != numBytes) && (CY_RRAM_SUCCESS == status))
    {
        status = Cy_RRAM_UpdateBlock(config, data, 0UL, numBytes);
    }

    /* Set mode to idle */
    Cy_RRAM_SetOperationMode(config->base, CY_RRAM_IDLE);

    return status;
}

/*******************************************************************************
* Function Name: Cy_RRAM_IsParamValid
****************************************************************************//**
*
* Validate the Parameters.
* Return true if the parameters are valid else return false
*
*******************************************************************************/
static bool Cy_RRAM_IsParamValid(RRAMC_Type *base, cy_stc_rram_rgn_info_t rgnInfo, uint32_t numBytes)
{
    if((NULL != base) &&
       (rgnInfo.base != CY_RRAM_INVALID_ACCESS) &&
       (rgnInfo.size != CY_RRAM_INVALID_ACCESS) &&
       (numBytes > 0UL) && (numBytes <= rgnInfo.size))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteByteArray
****************************************************************************//**
*
* Writes array of byte data to the specified address.
* The address should fall in General OTP or Protected OTP subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;
    cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetOTPSubRegionInfo(addr);

    if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
    {
        cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, true, false};

        if(!Cy_RRAM_IsPCLockAcquired(base))
        {
            /* Acquire a PC to confirm the transaction is effective. */
            if(Cy_RRAM_AcquirePCLock(base))
            {
                status = Cy_RRAM_SubRegionWriteData(&config, data, numBytes);
                Cy_RRAM_ReleasePCLock(base);
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
        else
        {
            status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_OtpReadByteArray
****************************************************************************//**
*
* Reads array of byte data from the specified address.
* The address should fall in General OTP or Protected OTP subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;
    cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetOTPSubRegionInfo(addr);

    if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
    {
        cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.base, false, false};
        status = Cy_RRAM_SubRegionReadData(&config, data, numBytes);
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteWord
****************************************************************************//**
*
* Writes a 32-bit word data to the specified address.
* The address should fall in General OTP or Protected OTP subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteWord(RRAMC_Type * base, uint32_t addr, uint32_t data)
{
    return Cy_RRAM_OtpWriteByteArray(base, addr, (uint8_t *)(&data), 4UL);
}


/*******************************************************************************
* Function Name: Cy_RRAM_OtpReadWord
****************************************************************************//**
*
* Reads a 32bit word data from the specified address.
* The address should fall in General OTP or Protected OTP subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpReadWord(RRAMC_Type * base, uint32_t addr, uint32_t * data)
{
    return Cy_RRAM_OtpReadByteArray(base, addr, (uint8_t *)(data), 4UL);
}


/*******************************************************************************
* Function Name: Cy_RRAM_OtpWriteBlock
****************************************************************************//**
*
* Writes a block(16B) data to the specified address.
* The address should be block aligned.
* The address should fall in General OTP or Protected OTP subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_OtpWriteBlock(RRAMC_Type * base, uint32_t addr, uint8_t *data)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if((addr % CY_RRAM_BLOCK_SIZE_BYTES == 0UL))
    {
         status =  Cy_RRAM_OtpWriteByteArray(base, addr, data, CY_RRAM_BLOCK_SIZE_BYTES);
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_NvmWriteByteArray
****************************************************************************//**
*
* Writes array of byte data to the specified address in blocking mode.
* The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;
    cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetNVMSubRegionInfo(addr);

    if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
    {
        cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, true, false};

        if(!Cy_RRAM_IsPCLockAcquired(base))
        {
            /* Acquire a PC to confirm the transaction is effective. */
            if(Cy_RRAM_AcquirePCLock(base))
            {
                status = Cy_RRAM_SubRegionWriteData(&config, data, numBytes);
                Cy_RRAM_ReleasePCLock(base);
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
        else
        {
            status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_NvmReadByteArray
****************************************************************************//**
*
* Reads array of byte data from the specified address.
* The address should fall in Main, Work, Sflash, Protected NVM subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;
    cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetNVMSubRegionInfo(addr);

    if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
    {
        cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, false, false};
        status = Cy_RRAM_SubRegionReadData(&config, data, numBytes);
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_NonBlockingNvmWriteByteArray
****************************************************************************//**
*
* Writes array of byte data to the specified address in Non Blocking mode.
* The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NonBlockingNvmWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;
    cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetNVMSubRegionInfo(addr);

    if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
    {
        cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, false, false};

        if(!Cy_RRAM_IsPCLockAcquired(base))
        {
            /* Acquire a PC to confirm the transaction is effective. */
            if(Cy_RRAM_AcquirePCLock(base))
            {
                status = Cy_RRAM_SubRegionWriteData(&config, data, numBytes);
                Cy_RRAM_ReleasePCLock(base);
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
        else
        {
            status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_NvmWriteBlock
****************************************************************************//**
*
* Writes a block(16B) data to the specified address in Blocking mode.
* The address should fall in Main or Work or Sflash or Protected NVM subsection.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_NvmWriteBlock(RRAMC_Type * base, uint32_t addr, uint8_t * data)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if((addr % CY_RRAM_BLOCK_SIZE_BYTES == 0UL))
    {
         status =  Cy_RRAM_NvmWriteByteArray(base, addr, data, CY_RRAM_BLOCK_SIZE_BYTES);
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_WriteByteArray
****************************************************************************//**
*
* Writes array of byte data to the provided RRAM address in blocking mode.
* API will wait for the write operation to be completed. It returns error or success status.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_WriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if(Cy_RRAM_GetNVMSubRegionInfo(addr).size != 0UL)
    {
        status = Cy_RRAM_NvmWriteByteArray(base, addr, data, numBytes);
    }
    else if(Cy_RRAM_GetOTPSubRegionInfo(addr).size != 0UL)
    {
        status = Cy_RRAM_OtpWriteByteArray(base, addr, data, numBytes);
    }
    else
    {
        status = CY_RRAM_BAD_PARAM;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_RRAM_TSWriteByteArray
****************************************************************************//**
*
* Writes an array of byte data to the specified address in blocking mode without considering
* uncorrectable ECC fail error.
* This API should be used only for tearing safe use cases.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_TSWriteByteArray(RRAMC_Type * base, uint32_t addr, const uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if(Cy_RRAM_GetNVMSubRegionInfo(addr).size != 0UL)
    {
        cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetNVMSubRegionInfo(addr);

        if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
        {
            cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, true, true};

            if(!Cy_RRAM_IsPCLockAcquired(base))
            {
                /* Acquire a PC to confirm the transaction is effective. */
                if(Cy_RRAM_AcquirePCLock(base))
                {
                    status = Cy_RRAM_SubRegionWriteData(&config, data, numBytes);
                    Cy_RRAM_ReleasePCLock(base);
                }
                else
                {
                    status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
                }
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
    }
    else if(Cy_RRAM_GetOTPSubRegionInfo(addr).size != 0UL)
    {
        cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetOTPSubRegionInfo(addr);

        if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
        {
            cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, true, true};

            if(!Cy_RRAM_IsPCLockAcquired(base))
            {
                /* Acquire a PC to confirm the transaction is effective. */
                if(Cy_RRAM_AcquirePCLock(base))
                {
                    status = Cy_RRAM_SubRegionWriteData(&config, data, numBytes);
                    Cy_RRAM_ReleasePCLock(base);
                }
                else
                {
                    status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
                }
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
    }
    else
    {
        status = CY_RRAM_BAD_PARAM;
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_ReadByteArray
****************************************************************************//**
*
* Reads a array of byte data from the provided RRAM address.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_ReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if(Cy_RRAM_GetNVMSubRegionInfo(addr).size != 0UL)
    {
        status = Cy_RRAM_NvmReadByteArray(base, addr, data, numBytes);
    }
    else if(Cy_RRAM_GetOTPSubRegionInfo(addr).size != 0UL)
    {
        status = Cy_RRAM_OtpReadByteArray(base, addr, data, numBytes);
    }
    else
    {
        status = CY_RRAM_BAD_PARAM;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_RRAM_TSReadByteArray
****************************************************************************//**
*
* Reads an array of byte data from the specified address after validating the
* uncorrectable ECC fail bits.
* Returns ECC fail error if uncorrectable ECC fail error exist.
* This API should be used only for tearing safe use cases.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_TSReadByteArray(RRAMC_Type * base, uint32_t addr, uint8_t * data, uint32_t numBytes)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if(Cy_RRAM_GetNVMSubRegionInfo(addr).size != 0UL)
    {
        cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetNVMSubRegionInfo(addr);
        if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
        {
            cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.size, false, true};
            if(!Cy_RRAM_IsPCLockAcquired(base))
            {
                /* Acquire a PC to confirm the transaction is effective. */
                if(Cy_RRAM_AcquirePCLock(base))
                {
                    status = Cy_RRAM_SubRegionReadData(&config, data, numBytes);
                    Cy_RRAM_ReleasePCLock(base);
                }
                else
                {
                    status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
                }
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
    }
    else if(Cy_RRAM_GetOTPSubRegionInfo(addr).size != 0UL)
    {
        cy_stc_rram_rgn_info_t rgnInfo = Cy_RRAM_GetOTPSubRegionInfo(addr);

        if(Cy_RRAM_IsParamValid(base, rgnInfo, numBytes) && NULL != data)
        {
            cy_stc_rram_config_t config = {base, addr, rgnInfo.base, rgnInfo.base, false, true};
            if(!Cy_RRAM_IsPCLockAcquired(base))
            {
                /* Acquire a PC to confirm the transaction is effective. */
                if(Cy_RRAM_AcquirePCLock(base))
                {
                    status = Cy_RRAM_SubRegionReadData(&config, data, numBytes);
                    Cy_RRAM_ReleasePCLock(base);
                }
                else
                {
                    status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
                }
            }
            else
            {
                status = CY_RRAM_ACQUIRE_PC_LOCK_FAIL;
            }
        }
    }
    else
    {
        status = CY_RRAM_BAD_PARAM;
    }

    return status;
}


#if (CY_CPU_CORTEX_M0P)
/*******************************************************************************
* Function Name : Cy_RRAM_Init
****************************************************************************//**
*
* Retrieves configuration settings from configuration space in Extra area.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_Init(RRAMC_Type * base, cy_en_rram_vmode_t vmode, bool retrvAlgoInfo)
{
    cy_en_rram_status_t status = CY_RRAM_SUCCESS;
    uint32_t timeout;

    if(NULL == base)
    {
        return CY_RRAM_BAD_PARAM;
    }

    /* Mask for Uncorrectable failure or no configuration retrieved errors. */
    uint32_t errorMask = _VAL2FLD(RRAMC_RRAM_SFR_NVM_STATUS_VERR, 0x04UL);

    /* Sets voltage/frequency mode */
    Cy_RRAM_SetVoltageMode(base, vmode);

    /* Starts "Retrieve configuration settings" sequence and waits until the sequence finishes. */
    Cy_RRAM_SetOperationMode(base, CY_RRAM_IDLE);
    Cy_RRAM_SetOperationMode(base, CY_RRAM_RETRIEVE_CONFIG);

    /* Retrieve the write algorithm information */
    RRAM_NVM_PROG(base) |= _VAL2FLD(RRAMC_RRAM_SFR_NVM_PROG_SELRCS, retrvAlgoInfo);

    /* Start operation with unchanged NVM_PROG.ACTION */
    Cy_RRAM_StartOperation(base);

    timeout = CY_RRAM_OPERATION_TIMEOUT / CY_RRAM_STATUS_CHECK_DELAY;

    /* Wait for the retrieve operation to finish. As per RRAM IP team,
    * there is no need for timeout as the state machine will definitely
    * return to non-busy state. As a safety measure this timeout is added */
    while(Cy_RRAM_IsBusy(base) && (0UL != timeout))
    {
        timeout--;
        Cy_SysLib_DelayCycles(CY_RRAM_STATUS_CHECK_DELAY);
    }

    if(timeout == 0UL)
    {
        return CY_RRAM_OPERATION_TIME_OUT_ERROR;
    }
    Cy_RRAM_StopOperation(base);

    /* Up to triple-bit fails are corrected by HW
       below check is for uncorrectable failure or no configuration retrieved errors*/
    if((((uint32_t)CY_RRAM_GetFailBitInfo(base)) & errorMask) != ((uint32_t)CY_RRAM_NO_ERROR))
    {
        status =  CY_RRAM_INIT_FAIL;
    }

    return status;
}
#endif


/*******************************************************************************
* Function Name: Cy_RRAM_EnableWP
****************************************************************************//**
*
* Enables write protection for number of sectors starting with sector 0 in RRAM NVM region.
* Before calling this API, user need to call Cy_RRAM_GetWPLockState() API and
* make sure the write protection lock is not locked. Otherwise this API will return
* CY_RRAM_WPLOCK_ENABLED error.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_EnableWP(RRAMC_Type * base, uint32_t numSectors)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    CY_ASSERT_L2(CY_RRAM_SECTOR_COUNT_VALID(numSectors));

    if(NULL != base && numSectors > 0UL && numSectors <= (CY_RRAM_NVM_SIZE_KB / CY_RRAM_SECTOR_SIZE_KB))
    {
        /* Check the status of write protection lock */
        if(Cy_RRAM_GetWPLockState(base) == CY_RRAM_WP_UNLOCK)
        {

            uint32_t temp = RRAM_NVM_CONF1(base) & ~RRAMC_RRAM_SFR_NVM_CONF1_SECPROT_Msk;
            /* Erase and Update the number of sectors to be write protected */
            RRAM_NVM_CONF1(base) = temp | _VAL2FLD(RRAMC_RRAM_SFR_NVM_CONF1_SECPROT, numSectors);
            status = CY_RRAM_SUCCESS;
        }
        else
        {
            status = CY_RRAM_WPLOCK_ENABLED;
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_DisableWP
****************************************************************************//**
*
* Disables write protection for all sectors in RRAM NVM region.
* Before calling this API, user need to call Cy_RRAM_GetWPLockState() API and
* make sure the write protection lock is not locked. Otherwise this API will return
* CY_RRAM_WPLOCK_ENABLED error.
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_DisableWP(RRAMC_Type * base)
{
    cy_en_rram_status_t status = CY_RRAM_WPLOCK_ENABLED;

    if(NULL == base)
    {
        return CY_RRAM_BAD_PARAM;
    }

    /* Check the status of write protection lock */
    if(Cy_RRAM_GetWPLockState(base) == CY_RRAM_WP_UNLOCK)
    {
        /* Disable write protection on all sectors by writing SECPROT to 0 */
        RRAM_NVM_CONF1(base) &= ~RRAMC_RRAM_SFR_NVM_CONF1_SECPROT_Msk;
        status = CY_RRAM_SUCCESS;
    }

    return status;
}


/*******************************************************************************
* Function Name: Cy_RRAM_SetProtLockableRegion
****************************************************************************//**
*
* Sets the size of lockable region in PROTECTED_NVM region. If size is larger than
* PROTECTED_NVM, the entire PROTECTED_NVM is lockable. The lockable region can be configured
* only if the protected nvm lock state is unlocked. The configured region is protected only when the
* protected nvm lock state is locked
*
*******************************************************************************/
cy_en_rram_status_t Cy_RRAM_SetProtLockableRegion(RRAMC_Type * base, uint32_t regionSize)
{
    cy_en_rram_status_t status = CY_RRAM_BAD_PARAM;

    if(NULL != base && regionSize > 0UL && regionSize <= CY_RRAM_PROTECTED_LOCK_REGION_LIMIT)
    {
        if(Cy_RRAM_GetProtLockState(base) == CY_RRAM_PROTECTED_UNLOCK)
        {
            /* Align regionSize to update valid data to register */
            RRAM_PROTECTED_LOCKABLE_LOCK(base) |=
              (((regionSize - 1UL) << RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_1_Pos) | (regionSize - 1UL));
            status = CY_RRAM_SUCCESS;
        }
        else
        {
            status = CY_RRAM_UPDATE_LOCKABLE_REGION_FAILED;
        }
    }

    return status;
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3')

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8')

#endif /* CY_IP_MXS22RRAMC */

/* [] END OF FILE */
