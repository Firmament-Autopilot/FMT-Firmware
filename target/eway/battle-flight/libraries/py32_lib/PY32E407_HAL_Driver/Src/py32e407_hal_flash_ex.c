/**
  ******************************************************************************
  * @file    py32e407_hal_flash_ex.c
  * @author  MCU Application Team
  * @brief   UART HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (FLASH).
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State and Errors functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx_hal.h"
#include "py32e407_hal_flash_ex.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup FLASHEx FLASHEx
  * @brief FLASH Extended HAL module driver
  * @{
  */

#ifdef HAL_FLASH_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup FLASHEx_Private_Functions FLASHEx Private Functions
  * @{
  */
static HAL_StatusTypeDef FLASH_OB_WRPConfig(uint32_t WRPArea);
static HAL_StatusTypeDef FLASH_OB_PCROPConfig(uint32_t PCROPConfig, uint32_t PCROPStartAddr, uint32_t PCROPEndAddr);
static uint32_t          FLASH_OB_GetWRP(void);
static uint32_t          FLASH_OB_GetRDP(void);
static uint32_t          FLASH_OB_GetUser(void);
static void              FLASH_OB_GetPCROP(uint32_t *PCROPConfig, uint32_t *PCROPStartAddr, uint32_t *PCROPEndAddr);
static void              FLASH_OB_OptrConfig(uint32_t UserType, uint32_t UserConfig, uint32_t RDPLevel);

/**
  * @}
  */

/* Exported functions -------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Functions FLASHEx Exported Functions
  * @{
  */

/** @defgroup FLASHEx_Exported_Functions_Group1 Extended IO operation functions
  * @brief   Extended IO operation functions
  *
@verbatim
 ===============================================================================
                ##### Extended programming operation functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to manage the Extended FLASH
    programming operations Operations.

@endverbatim
  * @{
  */
/**
  * @brief  Perform a mass erase or erase the specified FLASH memory pages.
  * @param[in]  pEraseInit pointer to an FLASH_EraseInitTypeDef structure that
  *         contains the configuration information for the erasing.
  * @param[out]  PageError pointer to variable that contains the configuration
  *         information on faulty page in case of error (0xFFFFFFFF means that all
  *         the pages have been correctly erased).
  * @retval HAL_Status
  */
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError)
{
  HAL_StatusTypeDef status;
  uint32_t address_index;

  /* Check the parameters */
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  /* Process Locked */
  __HAL_LOCK(&pFlash);

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    if ((pEraseInit->TypeErase & FLASH_TYPEERASE_MASSERASE) != 0)
    {
      /* Mass erase to be done */
      FLASH_MassErase(pEraseInit->Banks);

      /* Wait for last operation to be completed */
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

      /* If the erase operation is completed, disable the MER Bit */
      CLEAR_BIT(FLASH->CR, (FLASH_CR_MER0 | FLASH_CR_MER1));
    }
    else if(pEraseInit->TypeErase == FLASH_TYPEERASE_PAGEERASE)
    {
      /* Page Erase is requested */
      /* Check the parameters */
      assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->PageAddress));
      assert_param(IS_FLASH_NB_PAGES(pEraseInit->PageAddress, pEraseInit->NbPages));

      /*Initialization of PageSectorError variable*/
      *PageError = 0xFFFFFFFFU;

      /* Erase page by page to be done*/
      for(address_index = pEraseInit->PageAddress;
          address_index < ((pEraseInit->NbPages * FLASH_PAGE_SIZE) + pEraseInit->PageAddress);
          address_index += FLASH_PAGE_SIZE)
      {
        FLASH_PageErase(address_index);

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
        /* If the erase operation is completed, disable the PER Bit */
        CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
        if (status != HAL_OK)
        {
          /* In case of error, stop erase procedure and return the faulty address */
          *PageError = address_index;
          break;
        }
      }
      
    }
    else if(pEraseInit->TypeErase == FLASH_TYPEERASE_SECTORERASE)
    {
      /* Sector Erase is requested */
      /* Check the parameters */
      assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->SectorAddress));
      assert_param(IS_FLASH_NB_SECTORS(pEraseInit->SectorAddress, pEraseInit->NbSectors));


      /*Initialization of PageSectorError variable*/
      *PageError = 0xFFFFFFFFU;

      /* Erase sector by sector to be done*/
      for(address_index = pEraseInit->SectorAddress;
          address_index < ((pEraseInit->NbSectors * FLASH_SECTOR_SIZE) + pEraseInit->SectorAddress);
          address_index += FLASH_SECTOR_SIZE)
      {
        FLASH_SectorErase(address_index);

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
        /* If the erase operation is completed, disable the SER Bit */
        CLEAR_BIT(FLASH->CR, FLASH_CR_SER);
        if (status != HAL_OK)
        {
          /* In case of error, stop erase procedure and return the faulty address */
          *PageError = address_index;
          break;
        }
      }  
      
    }
    else if(pEraseInit->TypeErase == FLASH_TYPEERASE_BLOCKERASE)
    {
      /* Block Erase is requested */
      /* Check the parameters */
      assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->BlockAddress));
      assert_param(IS_FLASH_NB_BLOCKS(pEraseInit->BlockAddress, pEraseInit->NbBlocks));

      /* Wait for last operation to be completed */
      if (FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {
        /*Initialization of PageSectorError variable*/
        *PageError = 0xFFFFFFFFU;

        /* Erase block by block to be done*/
        for(address_index = pEraseInit->BlockAddress;
            address_index < ((pEraseInit->NbBlocks * FLASH_BLOCK_SIZE) + pEraseInit->BlockAddress);
            address_index += FLASH_BLOCK_SIZE)
        {
          FLASH_BlockErase(address_index);
          /* Wait for last operation to be completed */
          status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
          /* If the erase operation is completed, disable the BER Bit */
          CLEAR_BIT(FLASH->CR, FLASH_CR_BER);
          if (status != HAL_OK)
          {
            /* In case of error, stop erase procedure and return the faulty address */
            *PageError = address_index;
            break;
          }
        }  
      }
    }
  }

  /* Process Unlocked */
  __HAL_UNLOCK(&pFlash);

  return status;
}

/**
  * @brief  Perform a mass erase or erase the specified FLASH memory pages with interrupt enabled.
  * @param  pEraseInit pointer to an FLASH_EraseInitTypeDef structure that
  *         contains the configuration information for the erasing.
  * @retval HAL_Status
  */
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process Locked */
  __HAL_LOCK(&pFlash);

  /* Check the parameters */
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

  /* save procedure for interrupt treatment */
  pFlash.ProcedureOnGoing = pEraseInit->TypeErase;

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);

  if (status != HAL_OK)
  {
    /* Process Unlocked */
    __HAL_UNLOCK(&pFlash);
  }
  else  
  {
    /* Enable End of Operation and Error interrupts */
    __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_OPERR);
  
    if(pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
    {
      /* Set Bank to Bank for Interrupt callback management */
      pFlash.Bank = pEraseInit->Banks;

      /* Mass erase to be done */
      FLASH_MassErase(pEraseInit->Banks);
    }
    else if(pEraseInit->TypeErase == FLASH_TYPEERASE_PAGEERASE)
    {
      /* Erase by page to be done */
      pFlash.NbPagesSectorsBlocksToErase = pEraseInit->NbPages;
      pFlash.PageOrSectorOrBlock = pEraseInit->PageAddress;

      /*Erase 1st page and wait for IT */
      FLASH_PageErase(pEraseInit->PageAddress);
    }
    else if(pEraseInit->TypeErase == FLASH_TYPEERASE_SECTORERASE)
    {
      /* Erase by sector to be done */
      pFlash.NbPagesSectorsBlocksToErase = pEraseInit->NbSectors;
      pFlash.PageOrSectorOrBlock = pEraseInit->SectorAddress;
        
      FLASH_SectorErase(pEraseInit->SectorAddress);
    }
    else if (pEraseInit->TypeErase == FLASH_TYPEERASE_BLOCKERASE) 
    {
      /* Erase by block to be done */
      pFlash.NbPagesSectorsBlocksToErase = pEraseInit->NbBlocks;
      pFlash.PageOrSectorOrBlock = pEraseInit->BlockAddress;
        
      FLASH_BlockErase(pEraseInit->BlockAddress);
    }
    else
    {
      /* nothing to do */
    }
  }
  return status;
}

/**
  * @brief  Program Option bytes.
  * @param  pOBInit pointer to an FLASH_OBInitStruct structure that
  *         contains the configuration information for the programming.
  * @retval HAL_Status
  */
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit)
{
  uint32_t optr;
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_OPTIONBYTE(pOBInit->OptionType));

  /* Process Locked */
  __HAL_LOCK(&pFlash);

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

  /* Write protection configuration */
  if ((pOBInit->OptionType & OPTIONBYTE_WRP) != 0U)
  {
    /* Configure of Write protection on the selected area */
    if (FLASH_OB_WRPConfig(pOBInit->WRPBlock) != HAL_OK)
    {
      status = HAL_ERROR;
    }
  }

  if((pOBInit->OptionType & (OPTIONBYTE_RDP | OPTIONBYTE_USER)) == (OPTIONBYTE_RDP | OPTIONBYTE_USER))
  {
    /* Configure the user option bytes */
    FLASH_OB_OptrConfig(pOBInit->USERType, pOBInit->USERConfig, pOBInit->RDPLevel);
  }
  else if ((pOBInit->OptionType & OPTIONBYTE_RDP) != 0U)
  {
    /* Only modify RDP so get current user data */
    optr = FLASH_OB_GetUser();
    /* Configure the Read protection level */
    FLASH_OB_OptrConfig(optr, optr, pOBInit->RDPLevel);
  }
  else if ((pOBInit->OptionType & OPTIONBYTE_USER) != 0U)
  {
    /* Only modify user so get current RDP level */
    optr = FLASH_OB_GetRDP();
    /* Configure the user option bytes */
    FLASH_OB_OptrConfig(pOBInit->USERType, pOBInit->USERConfig, optr);
  }
  else
  {
    /* nothing to do */
  }
  /* PCROP Configuration */
  if ((pOBInit->OptionType & OPTIONBYTE_PCROP) != 0U)
  {
    if (pOBInit->PCROPStartAddr != pOBInit->PCROPEndAddr)
    {
      /* Configure the Proprietary code readout protection */
      if (FLASH_OB_PCROPConfig(pOBInit->PCROPConfig, pOBInit->PCROPStartAddr, pOBInit->PCROPEndAddr) != HAL_OK)
      {
        status = HAL_ERROR;
      }
    }
  }

  /* starts to modify Flash Option bytes */
  FLASH->CR|=FLASH_CR_OPTSTRT;

  /* set bit EOPIE */
  FLASH->CR|=FLASH_CR_EOPIE;
 
  /* trigger program */
  *((__IO uint32_t *)(0x1FFF7400))=0xffffffff;

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  /* Process Unlocked */
  __HAL_UNLOCK(&pFlash);

  return status;
}

/**
  * @brief  Get the Option bytes configuration.
  * @param  pOBInit pointer to an FLASH_OBInitStruct structure that contains the
  *         configuration information.
  * @note   The fields pOBInit->WRPBlock and pOBInit->PCROPConfig should indicate
  *         which area is requested for the WRP and PCROP, else no information will be returned.
  * @retval None
  */
void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit)
{
  pOBInit->OptionType = (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER);

  /* Get Read protection level */
  pOBInit->WRPBlock = FLASH_OB_GetWRP();

  /* Get Read protection level */
  pOBInit->RDPLevel = FLASH_OB_GetRDP();

  /* Get the user option bytes */
  pOBInit->USERConfig = FLASH_OB_GetUser();

  if ((pOBInit->PCROPConfig == FLASH_BANK_0) || (pOBInit->PCROPConfig == FLASH_BANK_1))
  {
    pOBInit->OptionType |= OPTIONBYTE_PCROP;
    /* Get the Proprietary code readout protection */
    FLASH_OB_GetPCROP(&(pOBInit->PCROPConfig), &(pOBInit->PCROPStartAddr), &(pOBInit->PCROPEndAddr));
  }
  else
  {
    /* Nothing to do */
  }
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/** @addtogroup FLASHEx_Private_Functions
  * @{
  */
/**
  * @brief  Mass erase of FLASH memory.
  * @param  Banks Banks to be erased.
  *         This parameter can be one of the following values:
  *            @arg FLASH_BANK_0: Bank0 to be erased
  *            @arg FLASH_BANK_1: Bank1 to be erased
  * @note   (*) availability depends on devices
  * @retval None
  */
void FLASH_MassErase(uint32_t Banks)
{
  /* Check the parameters */
  assert_param(IS_FLASH_BANK(Banks));

  if(Banks == FLASH_BANK_0)
  {
    SET_BIT(FLASH->CR, FLASH_CR_MER0);
  }
  else
  {
    SET_BIT(FLASH->CR, FLASH_CR_MER1);
  }
  
  /* Set the Mass Erase Bit for the bank if requested */
  if(READ_BIT(FLASH->OPTR1, FLASH_OPTR1_BFB) == 0)
  {
    if(Banks == FLASH_BANK_0)
    {
      *(__IO uint32_t *)(FLASH_BASE) = 0x12344321;
    }
    else
    {
      *(__IO uint32_t *)(FLASH_BASE + (FLASH_SIZE >> 1)) = 0x12344321;
    }
  }
  else
  {
    if(Banks == FLASH_BANK_0)
    {
      *(__IO uint32_t *)(FLASH_BASE + (FLASH_SIZE >> 1)) = 0x12344321;
    }
    else
    {
      *(__IO uint32_t *)(FLASH_BASE) = 0x12344321;
    }
  }
}

/**
  * @brief  Erase the specified FLASH memory page.
  * @param  PageAddress FLASH page to erase.
  *         This parameter must be a value between 0 and (max number of pages in the bank - 1).
  * @retval None
  */
void FLASH_PageErase(uint32_t PageAddress)
{
  /* Proceed to erase the page */
  SET_BIT(FLASH->CR, FLASH_CR_PER);
  *(__IO uint32_t *)(PageAddress) = 0x12344321;
}

/**
  * @brief  Sector erase of FLASH memory
  * @param  SectorAddress sector erase address
  * @retval None
  */
void FLASH_SectorErase(uint32_t SectorAddress)
{
  SET_BIT(FLASH->CR, FLASH_CR_SER);
  *(__IO uint32_t *)(SectorAddress) = 0xFFFFFFFF;
}

/**
  * @brief  Block erase of FLASH memory
  * @param  BlockAddress block erase address
  * @retval None
  */
void FLASH_BlockErase(uint32_t BlockAddress)
{
  SET_BIT(FLASH->CR, FLASH_CR_BER);
  *(__IO uint32_t *)(BlockAddress) = 0xFFFFFFFF;
}

/**
  * @brief  Page program of FLASH memory
  * @param  Address  Specifies the address to be programmed.
  * @param  DataAddress  Specifies the data to be programmed
  * @retval None
  */
void FLASH_Program_Page(uint32_t Address, uint32_t * DataAddress)
{
  uint8_t index=0;
  uint32_t dest = Address;
  uint32_t * src = DataAddress;
  uint32_t primask_bit;

  SET_BIT(FLASH->CR, FLASH_CR_PG);
  /* Enter critical section */
  primask_bit = __get_PRIMASK();
  __disable_irq();
  /* 128 words*/
  while(index<128U) 
  {
    *(uint32_t *)dest = *src;
    src += 1U;
    dest += 4U;
    index++;
    if(index==127)
    {
      SET_BIT(FLASH->CR, FLASH_CR_PGSTRT);
    }
  }

  /* Exit critical section: restore previous priority mask */
  __set_PRIMASK(primask_bit);
}

/**
  * @brief  Configure the write protection area into Option Bytes.
  * @param  WRPArea specifies the area to be configured.
  *         This parameter can be one of the following values:
  *            @arg OB_WRP_BLOCK_0: Flash Bank 1 Block 0
  *            @arg OB_WRP_BLOCK_1: Flash Bank 1 Block 1
  *            @arg OB_WRP_BLOCK_2: Flash Bank 1 Block 2
  *            @arg OB_WRP_BLOCK_3: Flash Bank 1 Block 3
  *            @arg OB_WRP_BLOCK_4: Flash Bank 2 Block 4
  *            @arg OB_WRP_BLOCK_5: Flash Bank 2 Block 5
  *            @arg OB_WRP_BLOCK_6: Flash Bank 2 Block 6
  *            @arg OB_WRP_BLOCK_7: Flash Bank 2 Block 7
  * @retval HAL_Status
  */
static HAL_StatusTypeDef FLASH_OB_WRPConfig(uint32_t WRPArea)
{
  HAL_StatusTypeDef status;

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
    FLASH->WRPR = (uint32_t)(~WRPArea);
  }

  return status;
}

/**
  * @brief  Set the read protection level into Option Bytes.
  * @param  RDPLevel specifies the read protection level.
  *         This parameter can be one of the following values:
  *            @arg OB_RDP_LEVEL_0: No protection
  *            @arg OB_RDP_LEVEL_1: Memory Read protection
  *
  * @retval HAL_Status
  */
HAL_StatusTypeDef HAL_FLASH_OB_RDPConfig(uint32_t RDPLevel)
{
  HAL_StatusTypeDef status;

  /* Check the parameters */
  assert_param(IS_OB_RDP_LEVEL(RDPLevel));

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
    /* Process Locked */
    __HAL_LOCK(&pFlash);

    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* Configure the RDP level in the option bytes register */
    MODIFY_REG(FLASH->OPTR1, FLASH_OPTR1_RDP, RDPLevel);

    /* Set OPTSTRT Bit */
    SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);

    /* set bit EOPIE */
    FLASH->CR|=FLASH_CR_EOPIE;

    /* trigger program */
    *((__IO uint32_t *)(0x1FFF7400))=0xffffffff;

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* Process Unlocked */
    __HAL_UNLOCK(&pFlash);
  }

  return status;
}

/**
  * @brief  Program the FLASH User Option Bytes.
  * @param  UserType The FLASH User Option Bytes to be modified.
  *         This parameter can be a combination of @ref FLASH_OB_USER_Type.
  * @param  UserConfig The selected User Option Bytes values:
  *         This parameter can be a combination of the following values:
  *         @ref FLASH_OB_USER_IWDG_STOP
  *         @ref FLASH_OB_USER_IWDG_STANDBY
  *         @ref FLASH_OB_USER_BFB
  *         @ref FLASH_OB_USER_IWDG_SW
  *         @ref FLASH_OB_USER_nRST_STOP
  *         @ref FLASH_OB_USER_nRST_STANDBY
  *         @ref FLASH_OB_USER_WWDG_SW
  *         @ref FLASH_OB_USER_nBOOT1
  *         @ref FLASH_OB_USER_NRST_MODE
  *         @ref FLASH_OB_USER_SRAM_PE
  *         @ref FLASH_OB_USER_CCMSRAM_RST
  *         @ref FLASH_OB_USER_nSWBOOT0
  *         @ref FLASH_OB_USER_nBOOT0
  *         @ref FLASH_OB_USER_BOOT_LOCK
  * @param  RDPLevel The selected User RDP Level values:
  *         @arg OB_RDP_LEVEL_0: No protection
  *         @arg OB_RDP_LEVEL_1: Memory Read protection
  * @retval HAL_Status
  */
static void FLASH_OB_OptrConfig(uint32_t UserType, uint32_t UserConfig, uint32_t RDPLevel)
{
  uint32_t optr1;
  uint32_t optr2;

  /* Check the parameters */
  assert_param(IS_OB_USER_TYPE(UserType));
  assert_param(IS_OB_USER_CONFIG(UserType, UserConfig));
  assert_param(IS_OB_RDP_LEVEL(RDPLevel));

  /* Configure the RDP level in the option bytes register */
  optr1 = FLASH->OPTR1;
  optr2 = FLASH->OPTR2;
  optr1 &= ~((UserType & 0xFFFF) | FLASH_OPTR1_RDP);
  optr2 &= ~((UserType >> 16) & 0xFFFF);
  FLASH->OPTR1 = (optr1 | UserConfig | RDPLevel);
  FLASH->OPTR2 = (optr2 | (UserConfig >> 16));
}

/**
  * @brief  Configure the Proprietary code readout protection area into Option Bytes.
  * @param  PCROPConfig specifies the configuration .
  *         This parameter must be a combination of FLASH_BANK_0 or FLASH_BANK_1 .
  * @param  PCROPStartAddr specifies the start address of the Proprietary code readout protection.
  *         This parameter can be an address between begin and end of the bank.
  * @param  PCROPEndAddr specifies the end address of the Proprietary code readout protection.
  *         This parameter can be an address between PCROPStartAddr and end of the bank.
  * @retval HAL_Status
  */
static HAL_StatusTypeDef FLASH_OB_PCROPConfig(uint32_t PCROPConfig, uint32_t PCROPStartAddr, uint32_t PCROPEndAddr)
{
  HAL_StatusTypeDef status;
  uint32_t reg_value;
  uint32_t bank0_addr;
  uint32_t bank1_addr;

  /* Check the parameters */
  assert_param(IS_FLASH_BANK_EXCLUSIVE(PCROPConfig & FLASH_BANK_MSK));
  assert_param(IS_FLASH_MAIN_MEM_ADDRESS(PCROPStartAddr));
  assert_param(IS_FLASH_MAIN_MEM_ADDRESS(PCROPEndAddr));

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
    /* Get the information about the bank swapping */
    if (READ_BIT(FLASH->OPTR1, FLASH_OPTR1_BFB) == 0U)
    {
      bank0_addr = FLASH_BASE;
      bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
    }
    else
    {
      bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
      bank1_addr = FLASH_BASE;
    }

    /* Configure the Proprietary code readout protection */
    if ((PCROPConfig & FLASH_BANK_MSK) == FLASH_BANK_0)
    {
      /* Calculate the location of the PCROPStartAddr in FLASH */
      reg_value = ((PCROPStartAddr - bank0_addr) >> 9);
      MODIFY_REG(FLASH->PCROP0SR, FLASH_PCROP0SR_PCROP0SR, reg_value);

      reg_value = ((PCROPEndAddr - bank0_addr) >> 9);
      MODIFY_REG(FLASH->PCROP0ER, FLASH_PCROP0ER_PCROP0ER, reg_value);
    }
    else if ((PCROPConfig & FLASH_BANK_MSK) == FLASH_BANK_1)
    {
      reg_value = ((PCROPStartAddr - bank1_addr) >> 9);
      MODIFY_REG(FLASH->PCROP1SR, FLASH_PCROP1SR_PCROP1SR, reg_value);

      reg_value = ((PCROPEndAddr - bank1_addr) >> 9);
      MODIFY_REG(FLASH->PCROP1ER, FLASH_PCROP1ER_PCROP1ER, reg_value);
    }
    else
    {
      /* Nothing to do */
    }
      
  }

  return status;
}

/**
  * @brief  Return the Write Protection configuration into Option Bytes.
  * @retval None
  */
static uint32_t FLASH_OB_GetWRP(void)
{
  return (uint32_t)(~FLASH->WRPR);
}

/**
  * @brief  Return the FLASH Read Protection level into Option Bytes.
  * @retval RDP_Level
  *         This return value can be one of the following values:
  *            @arg OB_RDP_LEVEL_0: No protection
  *            @arg OB_RDP_LEVEL_1: Read protection of the memory
  */
static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t rdp_level = READ_BIT(FLASH->OPTR1, FLASH_OPTR1_RDP);

  if (rdp_level != OB_RDP_LEVEL_0)
  {
    return (OB_RDP_LEVEL_1);
  }
  else
  {
    return rdp_level;
  }
}

/**
  * @brief  Return the FLASH User Option Byte value.
  * @retval OB_user_config
  *         This parameter can be a combination of the following values:
  *         @ref FLASH_OB_USER_IWDG_STOP
  *         @ref FLASH_OB_USER_IWDG_STANDBY
  *         @ref FLASH_OB_USER_BFB
  *         @ref FLASH_OB_USER_IWDG_SW
  *         @ref FLASH_OB_USER_nRST_STOP
  *         @ref FLASH_OB_USER_nRST_STANDBY
  *         @ref FLASH_OB_USER_WWDG_SW
  *         @ref FLASH_OB_USER_nBOOT1
  *         @ref FLASH_OB_USER_NRST_MODE
  *         @ref FLASH_OB_USER_SRAM_PE
  *         @ref FLASH_OB_USER_CCMSRAM_RST
  *         @ref FLASH_OB_USER_nSWBOOT0
  *         @ref FLASH_OB_USER_nBOOT0
  *         @ref FLASH_OB_USER_BOOT_LOCK
  */
static uint32_t FLASH_OB_GetUser(void)
{
  uint32_t user_config = 0;
  user_config  = READ_REG(FLASH->OPTR1) & 0xFFFFU;
  user_config |=  (READ_REG(FLASH->OPTR2) << 16);
  CLEAR_BIT(user_config, FLASH_OPTR1_RDP);

  return user_config;
}

/**
  * @brief  Return the FLASH PCROP configuration into Option Bytes.
  * @param[in,out] PCROPConfig specifies the configuration (Bank to be configured).
  *        This parameter must be a one of FLASH_BANK_0 or FLASH_BANK_1.
  * @param[out] PCROPStartAddr specifies the address where to copied the start address
  *        of the Proprietary code readout protection.
  * @param[out] PCROPEndAddr specifies the address where to copied the end address of
  *        the Proprietary code readout protection.
  * @retval None
  */
static void FLASH_OB_GetPCROP(uint32_t *PCROPConfig, uint32_t *PCROPStartAddr, uint32_t *PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank0_addr;
  uint32_t bank1_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASH->OPTR1, FLASH_OPTR1_BFB) == 0U)
  {
    bank0_addr = FLASH_BASE;
    bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  else
  {
    bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
    bank1_addr = FLASH_BASE;
  }

  if (((*PCROPConfig) & FLASH_BANK_MSK) == FLASH_BANK_0)
  {
    /* Calculate PCROPStartAddr by FLASH->PCROP0SR */
    reg_value       = ((READ_REG(FLASH->PCROP0SR) & FLASH_PCROP0SR_PCROP0SR) << 9);
    *PCROPStartAddr = (reg_value) + bank0_addr;

    /* Calculate PCROPEndAddr by FLASH->PCROP0ER */
    reg_value     = ((READ_REG(FLASH->PCROP0ER) & FLASH_PCROP0ER_PCROP0ER) << 9);
    *PCROPEndAddr = (reg_value) + bank0_addr;
  }
  else if (((*PCROPConfig) & FLASH_BANK_MSK) == FLASH_BANK_1)
  {
    /* Calculate PCROPStartAddr by FLASH->PCROP1SR */
    reg_value       = ((READ_REG(FLASH->PCROP1SR) & FLASH_PCROP1SR_PCROP1SR) << 9);
    *PCROPStartAddr = (reg_value) + bank1_addr;

    /* Calculate PCROPEndAddr by FLASH->PCROP1ER */
    reg_value     = ((READ_REG(FLASH->PCROP1ER) & FLASH_PCROP1ER_PCROP1ER) << 9);
    *PCROPEndAddr = (reg_value) + bank1_addr;
  }
  else
  {
    /* Nothing to do */
  }
}

/**
  * @}
  */

#endif /* HAL_FLASH_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
