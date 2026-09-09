/***************************************************************************//**
* \file  cy_mpc.c
* \version 1.1
*
* \brief
* Provides an API implementation of the secure MPC driver.
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

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS)

#include "cy_mpc.h"

/** Number of ROT (Root-of-Trust) MPC blocks per index */
#define CY_MPC_ROT_BLOCKS_PER_IDX       (8UL)
/** Number of ROT (Root-of-Trust) bits used to configure attributes of a block */
#define CY_MPC_ROT_BLOCK_BIT_COUNT      (4UL)
/** Mask of ROT (Root-of-Trust) block attribute */
#define CY_MPC_ROT_BLOCK_MASK           (0x00000007UL)
/** Mask of Read bit in ROT (Root-of-Trust) block*/
#define CY_MPC_ROT_READ_MASK            (0x00000002UL)
/** Mask of Write bit in ROT (Root-of-Trust) block*/
#define CY_MPC_ROT_WRITE_MASK           (0x00000004UL)
/** Mask of Security bit */
#define CY_MPC_NS_MASK                  (0x00000001UL)
/** Number of blocks per index */
#define CY_MPC_BLOCKS_PER_IDX           (32UL)
/** Number of bits used to configure attributes of a block */
#define CY_MPC_BLOCK_BIT_COUNT          (1UL)
/** Mask of Security bit */
#define CY_MPC_BLOCK_MASK               (0x00000001UL)
/** Init in progress check attempts value */
#define CY_MPC_INIT_IN_PROG_ATTEMPTS    (10000UL)
/** Get size of block for a particular region size */
#define CY_MPC_GET_BLOCK_SIZE(base) \
    (1UL << \
        ((uint32_t)(_FLD2VAL(RAMC_MPC_ROT_BLK_CFG_BLOCK_SIZE, (base)->ROT_BLK_CFG)) + 5UL))
/** Get index of a block for a particular address offset and region size */
#define CY_MPC_GET_BLOCK_INDEX(offset, base)  ((offset)/CY_MPC_GET_BLOCK_SIZE(base))

/** RAMC0 macro size */
#if defined(CPUSS_CHIP_TOP_RAMC0_SIZE)
#define CY_MPC_RAMC_0_SIZE             (CPUSS_CHIP_TOP_RAMC0_SIZE * 1024UL)
#endif /* defined(CPUSS_CHIP_TOP_RAMC0_SIZE) */

/** RAMC1 macro size */
#if defined(CPUSS_CHIP_TOP_RAMC1_SIZE)
#define CY_MPC_RAMC_1_SIZE             (CPUSS_CHIP_TOP_RAMC1_SIZE * 1024UL)
#endif /* defined(CPUSS_CHIP_TOP_RAMC1_SIZE) */


/*******************************************************************************
* Function Name: _Cy_Mpc_GetMemSize
****************************************************************************//**
*
* \brief Helper function, get memory size of provided base
*
* \param base
* Base address of MPC being configured
*
* \return The size
*
*******************************************************************************/
static uint32_t _Cy_Mpc_GetMemSize(MPC_Type* base) {
    uint32_t maxSize = 0UL;

    #if defined (SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0)
    if (base == (MPC_Type*)SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0)
    {
        maxSize = CY_XIP_PORT0_SIZE;
    }
    #endif /* SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0 */
    #if defined (SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0)
    if (base == (MPC_Type*)SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0)
    {
        maxSize = CY_XIP_PORT1_SIZE;
    }
    #endif /* SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0 */
    #if defined (SMIF0_CORE_AXI_MPC0)
    if (base == (MPC_Type*)SMIF0_CORE_AXI_MPC0)
    {
        maxSize = CY_XIP_PORT0_SIZE;
    }
    #endif /* SMIF0_CORE_AXI_MPC0 */
    #if defined (SMIF1_CORE_AXI_MPC0)
    if (base == (MPC_Type*)SMIF1_CORE_AXI_MPC0)
    {
        maxSize = CY_XIP_PORT1_SIZE;
    }
    #endif /* SMIF1_CORE_AXI_MPC0 */
    #if defined (SOCMEM_SRAM_MPC0)
    if (base == (MPC_Type*)SOCMEM_SRAM_MPC0)
    {
        maxSize = CY_SOCMEM_RAM_SIZE;
    }
    #endif /* SOCMEM_SRAM_MPC0 */
    #if defined (RAMC0_MPC0)
    if (base == RAMC0_MPC0)
    {
        maxSize = CY_MPC_RAMC_0_SIZE;
    }
    #endif /* RAMC0_MPC0 */
    #if defined (RAMC1_MPC0)
    if (base == RAMC1_MPC0)
    {
        maxSize = CY_MPC_RAMC_1_SIZE;
    }
    #endif /* RAMC1_MPC0 */
    #if defined (RRAMC0_MPC0)
    if (base == (MPC_Type*)RRAMC0_MPC0)
    {
        maxSize = CY_RRAM_SIZE;
    }
    #endif /* RRAMC0_MPC0 */
    #if defined (RRAMC0_MPC1)
    if (base == (MPC_Type*)RRAMC0_MPC1)
    {
        maxSize = CY_RRAM_SIZE;
    }
    #endif /* RRAMC0_MPC1 */

    return maxSize;
}


/*******************************************************************************
* Function Name: _Cy_Mpc_WaitForRotInitCompletion
****************************************************************************//**
*
* \brief Polls for the INIT_IN_PROGRESS bit within the ROT_BLK_CFG register
*
*
* \param base
* Base address of mpc being configured
*
* \note The API pools for CY_MPC_INIT_IN_PROG_ATTEMPTS attempts
*
* \return
* Check status
*
*******************************************************************************/
static cy_en_mpc_status_t _Cy_Mpc_WaitForRotInitCompletion(MPC_Type* base)
{
    uint32_t attempts = 0UL;
    while (((base->ROT_BLK_CFG) & (RAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk)) != 0UL)
    {
        if (attempts >= CY_MPC_INIT_IN_PROG_ATTEMPTS)
        {
            return CY_MPC_INVALID_STATE;
        }
        attempts++;
    }
    return CY_MPC_SUCCESS;
}


/*******************************************************************************
* Function Name: _Cy_Mpc_WaitForInitCompletion
****************************************************************************//**
*
* \brief Pools for the INIT_IN_PROGRESS bit within the BLK_CFG register
*
*
* \param base
* Base address of mpc being configured
*
* \note The API pools for CY_MPC_INIT_IN_PROG_ATTEMPTS attempts
*
* \return
* Check status
*
*******************************************************************************/
static cy_en_mpc_status_t _Cy_Mpc_WaitForInitCompletion(MPC_Type* base)
{
    uint32_t attempts = 0UL;
    while (((base->BLK_CFG) & (RAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk)) != 0UL)
    {
        if (attempts >= CY_MPC_INIT_IN_PROG_ATTEMPTS)
        {
            return CY_MPC_INVALID_STATE;
        }
        attempts++;
    }
    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: _Cy_Mpc_ConfigHelper
****************************************************************************//**
*
* \brief Helper function, used during MPC initialization
*
* \param base
* Base address of MPC being configured
*
* \param start
* The first block to be configured for provided blkIdx
*
* \param end
* The last block to be configured for provided blkIdx
*
* \param mask
* Mask to set to, for RoT version:
*   - bit[0] : NS/S
*   - bit[1] : R
*   - bit[2] : W
*   - bit[3] : Reserved
* For non-RoT version:
*   - bit[0] : NS
*
* \param blkIdx
* Block index to configure
*
* \param rot
* Specifies whether ROT or non-ROT version is to be configured
*
* \param isPartial
* Specifies whether not whole IDX is to be configured, if true masks new value of with an old one
* Partial initialization is ignored during non ROT configuration
*
*******************************************************************************/
static void _Cy_Mpc_ConfigHelper(MPC_Type* base, const uint32_t start, const uint32_t end, const uint32_t mask, uint32_t blkIdx, bool rot, bool isPartial)
{
    CY_ASSERT(base != NULL);
    uint32_t fieldMaskVal = 0UL, value = 0UL;
    uint32_t fieldMask = (rot) ? 0xFUL : 0x1UL;
    uint32_t blockBitCount = (rot)
        ? CY_MPC_ROT_BLOCK_BIT_COUNT
        : CY_MPC_BLOCK_BIT_COUNT;

    for (uint32_t i = start; i <= end; i++)
    {
        fieldMaskVal |= (fieldMask << (blockBitCount * i));
        value |= (mask << (blockBitCount * i));
    }

    if (rot) {
        base->ROT_BLK_IDX = blkIdx;
        base->ROT_BLK_LUT = ((isPartial) ? ((base->ROT_BLK_LUT & ~fieldMaskVal) | value) : value);
    } else {
        base->BLK_IDX = blkIdx;
        base->BLK_LUT = (base->BLK_LUT & ~fieldMaskVal) | value;
    }
}


/*******************************************************************************
* Function Name: _Cy_Mpc_ConfigStructHelper
****************************************************************************//**
*
* \brief Helper function, used during MPC initialization
*
* \param base
* Base address of MPC being configured
*
* \param address
* Offset in the memory from the memory start address to set permissions for
*
* \param size
* Size of the memory to set permissions for
*
* \param blockSize
* The size of block
*
* \param mask
* Mask to set to
*
* \param rot
* Specifies whether ROT or non-ROT version is to be configured
*
*******************************************************************************/
static void _Cy_Mpc_ConfigStructHelper(MPC_Type* base, const uint32_t address, const uint32_t size, const uint32_t blockSize, const uint32_t mask, bool rot)
{
    uint32_t blocksPerIdx = (rot) ? CY_MPC_ROT_BLOCKS_PER_IDX : CY_MPC_BLOCKS_PER_IDX;
    uint32_t start = (address/blockSize) % blocksPerIdx;
    uint32_t totalBlocks = size/blockSize;
    uint32_t freeBlocks = blocksPerIdx - start;

    uint32_t end = 0, newAddr = 0, newSize = 0;
    if (totalBlocks <= freeBlocks)
    {
        end = (totalBlocks + start - 1UL) % blocksPerIdx;
    }
    else
    {
        end = blocksPerIdx - 1UL;
        newAddr = ((address/(blocksPerIdx * blockSize)) + 1UL) * blockSize * blocksPerIdx;
        newSize = size - (freeBlocks * blockSize);
    }

    uint32_t blkIdx = address/(blockSize * blocksPerIdx);
    _Cy_Mpc_ConfigHelper(base, start, end, mask, blkIdx, rot, true);

    if (totalBlocks > freeBlocks)
    {
        blkIdx = newAddr/(blockSize * blocksPerIdx);
        totalBlocks = newSize/(blockSize);
        uint32_t loopCnt = newSize/(blockSize * blocksPerIdx);
        for (uint32_t i = 0UL; i < loopCnt; i++)
        {
            _Cy_Mpc_ConfigHelper(base, 0, blocksPerIdx - 1UL, mask, blkIdx, rot, false);
            blkIdx++;
        }

        uint32_t partBlocks = totalBlocks % blocksPerIdx;
        if (partBlocks != 0UL)
        {
            _Cy_Mpc_ConfigHelper(base, 0, partBlocks - 1UL, mask, blkIdx, rot, true);
        }
    }
}


/*******************************************************************************
* Function Name: Cy_Mpc_ConfigRotMpcStruct
****************************************************************************//**
*
* \brief Initializes the referenced mpc by setting the Protection Context (PC),
* NS/S and RW/R/W permissions. This is called by ROT (Root of Trust) module.
*
*
* \param base
* Base address of MPC being configured
*
* \param addOffset
* Offset in the memory from the memory start address to set permissions for
*
* \param size
* Size of the memory to set permissions for
*
* \param rotConfig
* MPC configuration structure to be used by the ROT code
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_ConfigRotMpcStruct(MPC_Type* base, const uint32_t addOffset, const uint32_t size, const cy_stc_mpc_rot_cfg_t* rotConfig)
{
    CY_ASSERT(base != NULL);

    uint32_t maxSize = _Cy_Mpc_GetMemSize(base);

    if (((addOffset + size) > maxSize) ||
        (size == 0UL) ||
        (maxSize == 0UL))
    {
        return CY_MPC_BAD_PARAM;
    }

    uint32_t blockSize = CY_MPC_GET_BLOCK_SIZE(base);

    /* Check address and size boundaries */
    if ((addOffset%(blockSize) != 0UL) ||
        (size%(blockSize))){
        return CY_MPC_BAD_PARAM;
    }

    /* Check if initialization is still in progress */
    if(CY_MPC_SUCCESS != _Cy_Mpc_WaitForRotInitCompletion(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    uint32_t mask;
    /*
    For each nibble:
    - bit[0] : NS (0 indicates secure, 1 indicates non-secure)
    - bit[1] : R (0 indicates read access not allowed. 1 indicates read access allowed)
    - bit[2] : W (0 indicates write access not allowed, 1 indicates write access allowed)
    - bit[3] : Reserved
    */
    if (((uint32_t)rotConfig->secure <= (uint32_t)CY_MPC_NON_SECURE) ||
        ((uint32_t)rotConfig->access <= (uint32_t)CY_MPC_ACCESS_RW))
    {
        mask = ((uint32_t)rotConfig->secure |
                ((uint32_t)rotConfig->access << 1U));
    }
    else
    {
        return CY_MPC_BAD_PARAM;
    }

    /* Set PC value */
    if ((uint32_t)rotConfig->pc < (uint32_t)MPC_PC_NR)
    {
        base->ROT_BLK_PC = (uint32_t)rotConfig->pc;
    }
    else
    {
         return CY_MPC_BAD_PARAM;
    }

    /* Disable auto increment */
    uint8_t autoInc = (uint8_t)_FLD2VAL(RAMC_MPC_ROT_CTRL_AUTO_INC, base->ROT_CTRL);
    Cy_Mpc_RotAutoInc(base, 0u);

    _Cy_Mpc_ConfigStructHelper(base, addOffset, size, blockSize, mask, true);

    /* Restore auto increment */
    Cy_Mpc_RotAutoInc(base, autoInc);

    return CY_MPC_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Mpc_ConfigMpcStruct
****************************************************************************//**
*
* \brief Initializes the referenced MPC by setting the NS/S
* permissions.
*
*
* \param base
* Base address of MPC being configured
*
* \param addOffset
* Offset in the memory from the memory start address to set permissions for
*
* \param size
* Size of the memory to set permissions for
*
* \param config
* MPC configuration structure to be used
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_ConfigMpcStruct(MPC_Type* base, const uint32_t addOffset, const uint32_t size, const cy_stc_mpc_cfg_t* config)
{
    uint32_t maxSize = _Cy_Mpc_GetMemSize(base);

    if (((addOffset + size) > maxSize) ||
        (size == 0UL) ||
        (maxSize == 0UL))
    {
        return CY_MPC_BAD_PARAM;
    }

    uint32_t blockSize = CY_MPC_GET_BLOCK_SIZE(base);

    /* Check address and size boundaries */
    if ((addOffset%(blockSize) != 0UL) ||
        (size%(blockSize))){
        return CY_MPC_BAD_PARAM;
    }

    /* Check if initialization is still in progress */
    if(CY_MPC_SUCCESS != _Cy_Mpc_WaitForInitCompletion(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    /* Disable auto increment */
    uint8_t autoInc = (uint8_t)_FLD2VAL(RAMC_MPC_CTRL_AUTO_INC, base->ROT_CTRL);
    Cy_Mpc_AutoInc(base, 0u);

    _Cy_Mpc_ConfigStructHelper(base, addOffset, size, blockSize, (uint32_t)config->secure, false);

    /* Restore auto increment bit */
    Cy_Mpc_AutoInc(base, autoInc);

    return CY_MPC_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Mpc_GetRotBlockAttr
****************************************************************************//**
*
* \brief Get MPC attributes settings corresponding to block and the Protection Context (PC) for ROT
*        (Root of Trust)
*
* \param base
* Base address of MPC being configured
*
* \param pc
* Protection Context
*
* \param addOffset
* Offset in the memory from the memory start address to get attributes for
*
* \param p_block_settings
* Pointer to return value of block settings
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_GetRotBlockAttr(MPC_Type* base, const cy_en_mpc_prot_context_t pc, const uint32_t addOffset, cy_stc_mpc_rot_block_attr_t* p_block_settings)
{
    CY_ASSERT(base != NULL);

    if (((uint32_t)pc >= (uint32_t)MPC_PC_NR)) {
        return CY_MPC_BAD_PARAM;
    }

    /* Check if initialization is still in progress */
    if(CY_MPC_SUCCESS != _Cy_Mpc_WaitForRotInitCompletion(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    uint32_t block_idx   = CY_MPC_GET_BLOCK_INDEX(addOffset, base);
    /* block_idx is calculated as address divided by block size; its quotient gives
    * the 32-block group index for BLK_IDX, and its remainder is used to shift
    * BLK_LUT to extract block attributes. Used in both index and attribute
    * calculations.
    */
    base->ROT_BLK_PC     = (uint32_t)pc;
    base->ROT_BLK_IDX    = (block_idx / CY_MPC_ROT_BLOCKS_PER_IDX);
    uint32_t blk_settings = (base->ROT_BLK_LUT >> ((block_idx % CY_MPC_ROT_BLOCKS_PER_IDX) * CY_MPC_ROT_BLOCK_BIT_COUNT)) & CY_MPC_ROT_BLOCK_MASK;

    if ((blk_settings & CY_MPC_NS_MASK) != 0UL) {
        p_block_settings->secure = CY_MPC_NON_SECURE;
    } else {
        p_block_settings->secure = CY_MPC_SECURE;
    }

    if (((blk_settings & CY_MPC_ROT_READ_MASK) != 0UL) &&
        ((blk_settings & CY_MPC_ROT_WRITE_MASK) != 0UL)) {
        p_block_settings->access = CY_MPC_ACCESS_RW;
    } else if ((blk_settings & CY_MPC_ROT_READ_MASK) != 0UL){
        p_block_settings->access = CY_MPC_ACCESS_R;
    } else if ((blk_settings & CY_MPC_ROT_WRITE_MASK) != 0UL){
        p_block_settings->access = CY_MPC_ACCESS_W;
    } else {
        p_block_settings->access = CY_MPC_ACCESS_DISABLED;
    }

    return CY_MPC_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Mpc_GetBlockAttr
****************************************************************************//**
*
* \brief Get MPC attributes settings corresponding to a block
*
*
* \param base
* Base address of MPC being configured
*
* \param addOffset
* Offset in the memory from the memory start address to get attributes for
*
* \param p_block_settings
* Pointer to return value of block settings
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_GetBlockAttr(MPC_Type* base, const uint32_t addOffset, cy_stc_mpc_block_attr_t* p_block_settings)
{
    CY_ASSERT(base != NULL);

    /* Check if initialization is still in progress */
    if(CY_MPC_SUCCESS != _Cy_Mpc_WaitForInitCompletion(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    uint32_t block_idx = CY_MPC_GET_BLOCK_INDEX(addOffset, base);
    /* block_idx is calculated as address divided by block size; its quotient gives
    * the 32-block group index for BLK_IDX, and its remainder is used to shift
    * BLK_LUT to extract block attributes. Used in both index and attribute
    * calculations.
    */
    base->BLK_IDX    = (block_idx / CY_MPC_BLOCKS_PER_IDX);
    uint32_t blk_settings = (base->BLK_LUT >> ((block_idx % CY_MPC_BLOCKS_PER_IDX) * CY_MPC_BLOCK_BIT_COUNT)) & CY_MPC_BLOCK_MASK;

    if ((blk_settings & CY_MPC_NS_MASK) != 0UL) {
        p_block_settings->secure = CY_MPC_NON_SECURE;
    } else {
        p_block_settings->secure = CY_MPC_SECURE;
    }

    return CY_MPC_SUCCESS;
}


#endif
/* [] END OF FILE */
