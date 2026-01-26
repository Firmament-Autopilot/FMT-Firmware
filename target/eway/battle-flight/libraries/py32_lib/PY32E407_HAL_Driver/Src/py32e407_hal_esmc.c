/**
  ******************************************************************************
  * @file    py32e407_hal_esmc.c
  * @author  MCU Application Team
  * @brief   ESMC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the ESMC interface.
  *           + Initialization and de-initialization functions
  *           + Indirect functional mode management
  *           + Memory-mapped functional mode management
  *           + Memory-write functional mode management
  *           + Interrupts and flags management
  *           + DMA channel configuration for indirect functional mode
  *           + Errors management and abort functionality
  *
  *
  @verbatim
 ===============================================================================
  @endverbatim
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

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup ESMC ESMC
  * @brief HAL ESMC module driver
  * @{
  */
#ifdef HAL_ESMC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup ESMC_Private_Constants
  * @{
  */
#define ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE       0x00000000U   /*!<Indirect write or read mode*/
#define ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT         0x00000001U   /*!<Indirect only send instruction mode*/
#define ESMC_FUNCTIONAL_MODE_MEMORY_MAPPED             0x00000002U   /*!<Memory-mapped mode*/
#define ESMC_FUNCTIONAL_MODE_MEMORY_WRITE              0x00000003U   /*!<Memory-write mode*/
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @addtogroup ESMC_Private_Macros ESMC Private Macros
  * @{
  */
#define IS_ESMC_FUNCTIONAL_MODE(MODE) (((MODE) == ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE)    || \
                                       ((MODE) == ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT) || \
                                       ((MODE) == ESMC_FUNCTIONAL_MODE_MEMORY_MAPPED) || \
                                       ((MODE) == ESMC_FUNCTIONAL_MODE_MEMORY_WRITE))
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup ESMC_Private_Functions ESMC Private Functions
  * @{
  */
static void ESMC_DMARxCplt(DMA_HandleTypeDef *hdma);
static void ESMC_DMATxCplt(DMA_HandleTypeDef *hdma);
static void ESMC_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void ESMC_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void ESMC_DMAError(DMA_HandleTypeDef *hdma);
static void ESMC_DMAAbortCplt(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef ESMC_WaitFlagStateUntilTimeout(ESMC_HandleTypeDef *hesmc, uint32_t Flag, FlagStatus State, uint32_t tickstart, uint32_t Timeout);
static void ESMC_Config(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd, uint32_t FunctionalMode);
static void ESMC_WriteBuff(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint8_t dataLen);
void ESMC_ReadBuff(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint8_t dataLen);


/* Exported functions ---------------------------------------------------------*/

/** @defgroup ESMC_Exported_Functions ESMC Exported Functions
  * @{
  */

/** @defgroup ESMC_Exported_Functions_Group1 Initialization/de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
===============================================================================
            ##### Initialization and Configuration functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to :
      (+) Initialize the ESMC.
      (+) De-initialize the ESMC.

@endverbatim
  * @{
  */

/**
  * @brief Initializes the ESMC mode according to the specified parameters
  *        in the ESMC_InitTypeDef and creates the associated handle.
  * @param hesmc esmc handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Init(ESMC_HandleTypeDef *hesmc)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Check the ESMC handle allocation */
  if(hesmc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_ESMC_ALL_INSTANCE(hesmc->Instance));
  assert_param(IS_ESMC_CLOCK_PRESCALER(hesmc->Init.ClockPrescaler));
  assert_param(IS_ESMC_CLOCK_MODE(hesmc->Init.ClockMode));
  assert_param(IS_ESMC_DUAL_FLASH_MODE(hesmc->Init.DualFlash));
  assert_param(IS_ESMC_CS_HIGH_TIME(hesmc->Init.ChipSelectHighTime));
  assert_param(IS_ESMC_CS_HOLD_TIME(hesmc->Init.ChipSelectHoldTime));

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hesmc->Lock = HAL_UNLOCKED;

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
    /* Reset Callback pointers in HAL_ESMC_STATE_RESET only */
    hesmc->ErrorCallback         = HAL_ESMC_ErrorCallback;
    hesmc->AbortCpltCallback     = HAL_ESMC_AbortCpltCallback;
    hesmc->CmdCpltCallback       = HAL_ESMC_CmdCpltCallback;
    hesmc->RxCpltCallback        = HAL_ESMC_RxCpltCallback;
    hesmc->TxCpltCallback        = HAL_ESMC_TxCpltCallback;
    hesmc->RxHalfBlockCpltCallback    = HAL_ESMC_RxHalfBlockCpltCallback;
    hesmc->TxHalfBlockCpltCallback    = HAL_ESMC_TxHalfBlockCpltCallback;

    if(hesmc->MspInitCallback == NULL)
    {
      hesmc->MspInitCallback = HAL_ESMC_MspInit;
    }

    /* Init the low level hardware */
    hesmc->MspInitCallback(hesmc);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_ESMC_MspInit(hesmc);
#endif

    /* Configure the default timeout for the ESMC memory access */
    HAL_ESMC_SetTimeout(hesmc, HAL_ESMC_TIMEOUT_DEFAULT_VALUE);
  }

  /* Wait till IDLE flag set */
  status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);
  
  if(status == HAL_OK)
  {
    /* Set Clock Prescaler */
    MODIFY_REG(hesmc->Instance->BAUD, ESMC_BAUD_BAUD, hesmc->Init.ClockPrescaler);
    
    MODIFY_REG(hesmc->Instance->CR2, ESMC_CR2_CPOL | ESMC_CR2_CPHA, hesmc->Init.ClockMode);
       
    MODIFY_REG(hesmc->Instance->TCR, ESMC_TCR_HOLD | ESMC_TCR_HIGH ,hesmc->Init.ChipSelectHighTime | hesmc->Init.ChipSelectHoldTime);
    
    /* CLEAR ALL CS */
    CLEAR_BIT(hesmc->Instance->ADDR32, ESMC_ADDR32_SSXO);

    /* CLEAR ALL CS */
    CLEAR_BIT(hesmc->Instance->XSSOCR, ESMC_XSSOCR_SSXO);

    /* CLEAR ALL CS */
    CLEAR_BIT(hesmc->Instance->XSSOCR_WE, ESMC_XSSOCR_WE_SSXO);    

    /* Config Dual Flash, Enable ESMC, And reset other bits */
    hesmc->Instance->CR = ESMC_CR_SPIEN | hesmc->Init.DualFlash;

    /* Clear FIFO */
    __HAL_ESMC_CLEAR_FIFO(hesmc);

    /* Initialize the ESMC operation */
    hesmc->Contex = ESMC_CONTEXT_NONE;

    /* Set ESMC error code to none */
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    /* Initialize the ESMC state */
    hesmc->State = HAL_ESMC_STATE_READY;
  }

  /* Release Lock */
  __HAL_UNLOCK(hesmc);

  /* Return function status */
  return status;
}

/**
  * @brief DeInitializes the ESMC peripheral
  * @param hesmc esmc handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_DeInit(ESMC_HandleTypeDef *hesmc)
{
  /* Check the ESMC handle allocation */
  if(hesmc == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hesmc);

  /* Disable the slave select */
  __HAL_ESMC_DISABLE_SLAVE(hesmc);

  /* Soft reset ESMC */
  __HAL_ESMC_SOFT_RESET(hesmc);

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
  if(hesmc->MspDeInitCallback == NULL)
  {
    hesmc->MspDeInitCallback = HAL_ESMC_MspDeInit;
  }

  /* DeInit the low level hardware */
  hesmc->MspDeInitCallback(hesmc);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC... */
  HAL_ESMC_MspDeInit(hesmc);
#endif

  /* Set ESMC error code to none */
  hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

  /* Initialize the ESMC state */
  hesmc->State = HAL_ESMC_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hesmc);

  return HAL_OK;
}

/**
  * @brief ESMC MSP Init
  * @param hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_MspInit(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_ESMC_MspInit can be implemented in the user file
   */
}

/**
  * @brief ESMC MSP DeInit
  * @param hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_MspDeInit(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_ESMC_MspDeInit can be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup ESMC_Exported_Functions_Group2 IO operation functions
  *  @brief ESMC Transmit/Receive functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
       [..]
    This subsection provides a set of functions allowing to :
      (+) Handle the interrupts.
      (+) Handle the command sequence.
      (+) Transmit data in blocking, interrupt or DMA mode.
      (+) Receive data in blocking, interrupt or DMA mode.
      (+) Manage the auto-polling functional mode.
      (+) Manage the memory-mapped functional mode.

@endverbatim
  * @{
  */

/**
  * @brief This function handles ESMC interrupt request.
  * @param hesmc ESMC handle
  * @retval None.
  */
void HAL_ESMC_IRQHandler(ESMC_HandleTypeDef *hesmc)
{
  uint32_t flag = *(__IO uint32_t *)(&hesmc->Instance->IFR1);
  uint32_t itsource = *(__IO uint32_t *)(&hesmc->Instance->IER1);
  uint32_t len;

  /* ESMC data wait interrupt occurred ----------------------------------*/
  if(((flag & ESMC_FLAG_DATAWAITIF) != 0U) && ((itsource & ESMC_IT_DATAWAIT) != 0U))
  {
    if(hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_TX)
    {
      if (hesmc->TxXferCount == 0U)
      {
        if ((hesmc->Instance->CR & ESMC_CR_DMAEN) != 0U)
        {
          /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
          CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);
        }
        /* No more data available for the transfer */
        /* Disable the ESMC datawait Interrupt */
        __HAL_ESMC_DISABLE_IT(hesmc, ESMC_IT_DATAWAIT);
        if (hesmc->Contex == ESMC_CONTEXT_WRITE_VARIABLE_LENGTH)
        {
          /* Disable the slave select */
          __HAL_ESMC_DISABLE_SLAVE(hesmc);

          /* Change state of ESMC */
          hesmc->State = HAL_ESMC_STATE_READY;

          /* Restore default values */
          hesmc->Contex = ESMC_CONTEXT_NONE;

          /* Command Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
          hesmc->TxCpltCallback(hesmc);
#else
          HAL_ESMC_TxCpltCallback(hesmc);
#endif
        }
      } 
      else
      {
        /* Transmission process */
        if ((hesmc->TxXferCount/HAL_ESMC_FIFO_SIZE) > 0)
        {
          /* The amount of data to be sent is greater than the maximum depth of the FIFO */
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, HAL_ESMC_FIFO_SIZE);
          hesmc->pTxBuffPtr += HAL_ESMC_FIFO_SIZE;
          hesmc->TxXferCount -= HAL_ESMC_FIFO_SIZE;
        } 
        else
        {
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, hesmc->TxXferCount);
          hesmc->pTxBuffPtr += hesmc->TxXferCount;
          hesmc->TxXferCount = 0;
        }
      }
    } 
    else if(hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_RX)
    {
      /* Transmission process */
      len = (hesmc->RxXferCount > HAL_ESMC_FIFO_SIZE) ? HAL_ESMC_FIFO_SIZE : hesmc->RxXferCount;
      ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, len);
      hesmc->pRxBuffPtr += len;
      hesmc->RxXferCount -= len;

      if (hesmc->RxXferCount == 0U)
      {
        /* No more data available for the transfer */
        /* Disable the ESMC datawait Interrupt */
        __HAL_ESMC_DISABLE_IT(hesmc, ESMC_IT_DATAWAIT);
        if (hesmc->Contex == ESMC_CONTEXT_READ_VARIABLE_LENGTH)
        {
          /* Disable the slave select */
          __HAL_ESMC_DISABLE_SLAVE(hesmc);

          /* Change state of ESMC */
          hesmc->State = HAL_ESMC_STATE_READY;

          /* Restore default values */
          hesmc->Contex = ESMC_CONTEXT_NONE;

          /* Command Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
          hesmc->RxCpltCallback(hesmc);
#else
          HAL_ESMC_RxCpltCallback(hesmc);
#endif
        }
      }
    }
    else if(hesmc->State == HAL_ESMC_STATE_BUSY)
    {
      /* Disable the ESMC datawait Interrupt */
      __HAL_ESMC_DISABLE_IT(hesmc, ESMC_IT_DATAWAIT);

      /* Disable the slave select */
      __HAL_ESMC_DISABLE_SLAVE(hesmc);

      /* Change state of ESMC */
      hesmc->State = HAL_ESMC_STATE_READY;

      /* Restore default values */
      hesmc->Contex = ESMC_CONTEXT_NONE;

      /* Command Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
      hesmc->CmdCpltCallback(hesmc);
#else
      HAL_ESMC_CmdCpltCallback(hesmc);
#endif
    }
  }
  else if(((flag & ESMC_FLAG_IDLEDONEIF) != 0U) && ((itsource & ESMC_IT_IDLEDONE) != 0U))
  {
    /* Clear interrupt */
    __HAL_ESMC_CLEAR_FLAG(hesmc, ESMC_FLAG_IDLEDONEIF);

    /* Disable the ESMC idle interrupts and datawait interrupts */
    __HAL_ESMC_DISABLE_IT(hesmc, (ESMC_IT_IDLEDONE | ESMC_IT_DATAWAIT));

    /* Transfer complete callback */
    if(hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_TX)
    {
      if ((hesmc->Instance->CR & ESMC_CR_DMAEN) != 0U)
      {
        /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
        CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);
      }

      /* Change state of ESMC */
      hesmc->State = HAL_ESMC_STATE_READY;

      /* Restore default values */
      hesmc->Contex = ESMC_CONTEXT_NONE;

      /* TX Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
      hesmc->TxCpltCallback(hesmc);
#else
      HAL_ESMC_TxCpltCallback(hesmc);
#endif
    }
    else if(hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_RX)
    {
      /* Transmission process */
      ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, hesmc->RxXferCount);
      hesmc->pRxBuffPtr += hesmc->RxXferCount;
      hesmc->RxXferCount = 0;

      /* Change state of ESMC */
      hesmc->State = HAL_ESMC_STATE_READY;

      /* Restore default values */
      hesmc->Contex = ESMC_CONTEXT_NONE;

      /* RX Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
      hesmc->RxCpltCallback(hesmc);
#else
      HAL_ESMC_RxCpltCallback(hesmc);
#endif
    }
    else if(hesmc->State == HAL_ESMC_STATE_BUSY)
    {
      /* Change state of ESMC */
      hesmc->State = HAL_ESMC_STATE_READY;

      /* Restore default values */
      hesmc->Contex = ESMC_CONTEXT_NONE;

      /* Command Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
      hesmc->CmdCpltCallback(hesmc);
#else
      HAL_ESMC_CmdCpltCallback(hesmc);
#endif
    }
    else
    {
      /* Nothing to do */
    }
  }
}

/**
  * @brief Sets the command configuration.
  * @param hesmc ESMC handle
  * @param cmd  structure that contains the command configuration information
  * @param Timeout  Time out duration
  * @note   This function is used only in Indirect Read or Write Modes
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Command(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd, uint32_t Timeout)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  assert_param(IS_ESMC_INSTRUCTION_MODE(cmd->InstructionMode));

  if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
  {
    assert_param(IS_ESMC_INSTRUCTION(cmd->Instruction));
    assert_param(IS_ESMC_INSTRUCTION_LENGTH(cmd->InstrcutionLen));
  }

  assert_param(IS_ESMC_ADDRESS_MODE(cmd->AddressMode));

  if (cmd->AddressMode != ESMC_ADDRESS_NONE)
  {
    assert_param(IS_ESMC_ADDRESS_SIZE(cmd->AddressSize));
  }
  assert_param(IS_ESMC_ALTERNATE_BYTES_MODE(cmd->AlternateByteMode));
  assert_param(IS_ESMC_ALTERNATE_BYTE(cmd->AlternateByte));
  assert_param(IS_ESMC_DUMMY_CYCLES(cmd->DummyCycles));
  assert_param(IS_ESMC_DATA_MODE(cmd->DataMode));
  assert_param(IS_ESMC_DQS_MODE(cmd->DQSMode));
  assert_param(IS_ESMC_SAMPLESHIFTING(cmd->SampleShifting));
  assert_param(IS_ESMC_XSPI_DUALLATENCY(cmd->XspiDualLatency));  

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    /* Update ESMC state */
    hesmc->State = HAL_ESMC_STATE_BUSY;

    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, Timeout);
    
    if (status == HAL_OK)
    {
      if ((cmd->InstructionMode != ESMC_INSTRUCTION_NONE) && \
          (cmd->AddressMode == ESMC_ADDRESS_NONE) && \
          (cmd->AlternateByteMode == ESMC_ALTERNATE_BYTES_DISABLE)&& \
          (cmd->DataMode == ESMC_DATA_NONE))
      {
        /* Call the configuration function  */
        ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT);
        status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);
        if (status == HAL_OK)
        {
          /* Update ESMC state */
          hesmc->State = HAL_ESMC_STATE_READY;
        }          
      }
      else
      {
        /* Call the configuration function  */
        ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE);

        if (cmd->DataMode == ESMC_DATA_NONE)
        {
          status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);

          if (status == HAL_OK)
          {
            /* Update ESMC state */
            hesmc->State = HAL_ESMC_STATE_READY;
          }          
        }
        else
        {
          hesmc->State = HAL_ESMC_STATE_READY;            
        }
      }
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  /* Return function status */
  return status;
}

/**
  * @brief Set the command configuration in interrupt mode.
  * @param hesmc : ESMC handle
  * @param cmd : structure that contains the command configuration information
  * @note   This function is used only in Indirect Read or Write Modes
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Command_IT(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd)
{
  HAL_StatusTypeDef status;
  uint32_t tickstart = HAL_GetTick();

  assert_param(IS_ESMC_INSTRUCTION_MODE(cmd->InstructionMode));

  if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
  {
    assert_param(IS_ESMC_INSTRUCTION(cmd->Instruction));
    assert_param(IS_ESMC_INSTRUCTION_LENGTH(cmd->InstrcutionLen));
  }

  assert_param(IS_ESMC_ADDRESS_MODE(cmd->AddressMode));

  if (cmd->AddressMode != ESMC_ADDRESS_NONE)
  {
    assert_param(IS_ESMC_ADDRESS_SIZE(cmd->AddressSize));
  }
  assert_param(IS_ESMC_ALTERNATE_BYTES_MODE(cmd->AlternateByteMode));
  assert_param(IS_ESMC_ALTERNATE_BYTE(cmd->AlternateByte));
  assert_param(IS_ESMC_DUMMY_CYCLES(cmd->DummyCycles));
  assert_param(IS_ESMC_DATA_MODE(cmd->DataMode));
  assert_param(IS_ESMC_DQS_MODE(cmd->DQSMode));
  assert_param(IS_ESMC_SAMPLESHIFTING(cmd->SampleShifting));
  assert_param(IS_ESMC_XSPI_DUALLATENCY(cmd->XspiDualLatency));  

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    /* Update ESMC state */
    hesmc->State = HAL_ESMC_STATE_BUSY;

    /* Wait till idle state set */
    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);

    if (status == HAL_OK)
    {
      if ((cmd->InstructionMode != ESMC_INSTRUCTION_NONE) && \
          (cmd->AddressMode == ESMC_ADDRESS_NONE) && \
          (cmd->AlternateByte == ESMC_ALTERNATE_BYTES_DISABLE)&& \
          (cmd->DataMode == ESMC_DATA_NONE))
      {
        /* Clear idle interrupt */
        __HAL_ESMC_CLEAR_FLAG(hesmc, ESMC_FLAG_IDLEDONEIF);

        /* Call the configuration function  */
        ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT);

        /* Process unlocked */
        __HAL_UNLOCK(hesmc);

        /* Enable the ESMC idle Interrupt */
        __HAL_ESMC_ENABLE_GLOBAL_IT(hesmc);
        __HAL_ESMC_ENABLE_IT(hesmc, ESMC_FLAG_IDLEDONEIF);
      }
      else
      {
        /* Call the configuration function  */
        ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE);

        if (cmd->DataMode == ESMC_DATA_NONE)
        {       
          /* Process unlocked */
          __HAL_UNLOCK(hesmc);

          /* Enable the ESMC datawait Interrupt */
          __HAL_ESMC_ENABLE_GLOBAL_IT(hesmc);
          __HAL_ESMC_ENABLE_IT(hesmc, ESMC_FLAG_IDLEDONEIF);
        } 
        else
        {
          /* Update ESMC state */
          hesmc->State = HAL_ESMC_STATE_READY;

          /* Process unlocked */
          __HAL_UNLOCK(hesmc);
        }
      }
    }
  }
  else
  {
    status = HAL_BUSY;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }

  /* Return function status */
  return status;
}

/**
  * @brief  Configure the Memory Mapped mode.
  * @param  hesmc : ESMC handle
  * @param  cmd : structure that contains the command configuration information.
  * @note   This function is used only in Memory mapped Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_MemoryMapped(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd)
{
  HAL_StatusTypeDef status;
  uint32_t tickstart = HAL_GetTick();

  assert_param(IS_ESMC_INSTRUCTION_MODE(cmd->InstructionMode));

  if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
  {
    assert_param(IS_ESMC_INSTRUCTION(cmd->Instruction));
    assert_param(IS_ESMC_INSTRUCTION_LENGTH(cmd->InstrcutionLen));
  }

  assert_param(IS_ESMC_ADDRESS_MODE(cmd->AddressMode));

  if (cmd->AddressMode != ESMC_ADDRESS_NONE)
  {
    assert_param(IS_ESMC_ADDRESS_SIZE(cmd->AddressSize));
  }
  assert_param(IS_ESMC_ALTERNATE_BYTES_MODE(cmd->AlternateByteMode));
  assert_param(IS_ESMC_ALTERNATE_BYTE(cmd->AlternateByte));
  assert_param(IS_ESMC_DUMMY_CYCLES(cmd->DummyCycles));
  assert_param(IS_ESMC_DATA_MODE(cmd->DataMode));
  assert_param(IS_ESMC_DQS_MODE(cmd->DQSMode));
  assert_param(IS_ESMC_SAMPLESHIFTING(cmd->SampleShifting));
  assert_param(IS_ESMC_XSPI_DUALLATENCY(cmd->XspiDualLatency));  

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY  || hesmc->State == HAL_ESMC_STATE_BUSY_MEM_WRITE )
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;
    
    if(hesmc->State == HAL_ESMC_STATE_READY)
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_MEM_MAPPED;
    }
    else
    {
       /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED;    
    }

    /* Wait till IDLE flag set */
    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);

    if (status == HAL_OK)
    {
      /* Disable XIP mode, DMA, global interrupt */
      CLEAR_BIT(hesmc->Instance->CR, (ESMC_CR_XIPEN | ESMC_CR_DMAEN | ESMC_CR_GIE));

      /* Call the configuration function */
      ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_MEMORY_MAPPED);

      /* Enable XIP mode */
      SET_BIT(hesmc->Instance->CR, ESMC_CR_XIPEN);

      /* Enable the slave select */
      __HAL_ESMC_ENABLE_SLAVE(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  /* Return function status */
  return status;
}


/**
  * @brief  Configure the Memory Mapped mode.
  * @param  hesmc : ESMC handle
  * @param  cmd : structure that contains the command configuration information.
  * @note   This function is used only in Memory mapped Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_MemoryWrite(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd)
{
  HAL_StatusTypeDef status;
  uint32_t tickstart = HAL_GetTick();

  assert_param(IS_ESMC_INSTRUCTION_MODE(cmd->InstructionMode));

  if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
  {
    assert_param(IS_ESMC_INSTRUCTION(cmd->Instruction));
    assert_param(IS_ESMC_INSTRUCTION_LENGTH(cmd->InstrcutionLen));
  }

  assert_param(IS_ESMC_ADDRESS_MODE(cmd->AddressMode));

  if (cmd->AddressMode != ESMC_ADDRESS_NONE)
  {
    assert_param(IS_ESMC_ADDRESS_SIZE(cmd->AddressSize));
  }
  assert_param(IS_ESMC_ALTERNATE_BYTES_MODE(cmd->AlternateByteMode));
  assert_param(IS_ESMC_ALTERNATE_BYTE(cmd->AlternateByte));
  assert_param(IS_ESMC_DUMMY_CYCLES(cmd->DummyCycles));
  assert_param(IS_ESMC_DATA_MODE(cmd->DataMode));
  assert_param(IS_ESMC_DQS_MODE(cmd->DQSMode));
  assert_param(IS_ESMC_SAMPLESHIFTING(cmd->SampleShifting));
  assert_param(IS_ESMC_XSPI_DUALLATENCY(cmd->XspiDualLatency));  

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY || hesmc->State == HAL_ESMC_STATE_BUSY_MEM_MAPPED)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if(hesmc->State == HAL_ESMC_STATE_READY)
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_MEM_WRITE;
    }
    else
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED;    
    }

    /* Wait till IDLE flag set */
    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);

    if (status == HAL_OK)
    {
      /* Disable XIP mode, DMA, global interrupt */
      CLEAR_BIT(hesmc->Instance->CR, (ESMC_CR_XIPEN | ESMC_CR_DMAEN | ESMC_CR_GIE));

      /* Call the configuration function */
      ESMC_Config(hesmc, cmd, ESMC_FUNCTIONAL_MODE_MEMORY_WRITE);

      /* Enable XIP mode */
      SET_BIT(hesmc->Instance->CR, ESMC_CR_XIPEN);

      /* Enable the slave select */
      __HAL_ESMC_ENABLE_SLAVE(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  /* Return function status */
  return status;
}

/**
  * @brief Transmit an amount of data in blocking mode.
  * @param hesmc ESMC handle
  * @param pData pointer to data buffer
  * @param Timeout  Time out duration
  * @note   This function is used only in Indirect Write Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Transmit(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->TxXferCount != 0) && (hesmc->TxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_TX;

      hesmc->pTxBuffPtr = pData;
           
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;
      
      status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);  

      while(hesmc->TxXferCount != 0U)
      {
        if (hesmc->TxXferCount > HAL_ESMC_FIFO_SIZE)
        {
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, HAL_ESMC_FIFO_SIZE);
        
          hesmc->pTxBuffPtr += HAL_ESMC_FIFO_SIZE;
          hesmc->TxXferCount -= HAL_ESMC_FIFO_SIZE;
          status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);          
        } 
        else
        {
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, hesmc->TxXferCount);
          hesmc->pTxBuffPtr += hesmc->TxXferCount;
          hesmc->TxXferCount = 0;
          if(hesmc->Contex == ESMC_CONTEXT_WRITE_FIXED_LENGTH)
          {
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);
          }
          else
          {
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);
          }
        }
        if (status != HAL_OK)
        {
          break;
        }
      }

       /* Disable the slave select */
      __HAL_ESMC_DISABLE_SLAVE(hesmc);

      /* Update ESMC state */
      hesmc->State = HAL_ESMC_STATE_READY;
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  return status;
}

/**
  * @brief Transmit an amount of data in blocking mode with FIFO Half Empty.
  * @param hesmc ESMC handle
  * @param pData pointer to data buffer
  * @param Timeout  Time out duration
  * @note   This function is used only in Indirect Write Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_TransmitFIFO(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->TxXferCount != 0) && (hesmc->TxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_TX;

      hesmc->pTxBuffPtr = pData;
           
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;

      status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_TXFIFOHEIF, SET, tickstart, Timeout);
      
      while(hesmc->TxXferCount != 0U)
      {
        if (hesmc->TxXferCount>(HAL_ESMC_FIFO_SIZE/2))
        {
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, (HAL_ESMC_FIFO_SIZE/2));
        
          hesmc->pTxBuffPtr += (HAL_ESMC_FIFO_SIZE/2);
          hesmc->TxXferCount -= (HAL_ESMC_FIFO_SIZE/2); 
          status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_TXFIFOHEIF, SET, tickstart, Timeout);
        } 
        else
        {
          ESMC_WriteBuff(hesmc, hesmc->pTxBuffPtr, hesmc->TxXferCount);
          hesmc->pTxBuffPtr += hesmc->TxXferCount;
          hesmc->TxXferCount = 0;
          if(hesmc->Contex == ESMC_CONTEXT_WRITE_FIXED_LENGTH)
          {
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);
          }
          else
          {
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);
          }
        }
        if (status != HAL_OK)
        {
          break;
        }
      }

      __HAL_ESMC_DISABLE_SLAVE(hesmc);

      /* Update ESMC state */
      hesmc->State = HAL_ESMC_STATE_READY;
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  return status;
}


/**
  * @brief Receive an amount of data in blocking mode
  * @param hesmc ESMC handle
  * @param pData pointer to data buffer
  * @param Timeout  Time out duration
  * @note   This function is used only in Indirect Read Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Receive(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->RxXferCount != 0) && (hesmc->RxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_RX;

      hesmc->pRxBuffPtr = pData;

      /* send command */
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;
      
      while (hesmc->RxXferCount > HAL_ESMC_FIFO_SIZE)
      {     
        /* Wait until datawait flag is set */
        status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);

        if(status != HAL_OK)
        {
          break;
        }
        
        ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, HAL_ESMC_FIFO_SIZE);
        hesmc->pRxBuffPtr += HAL_ESMC_FIFO_SIZE;
        hesmc->RxXferCount -= HAL_ESMC_FIFO_SIZE;
      }
      if(status == HAL_OK)
      {      
        while (hesmc->RxXferCount != 0)
        {
          if (hesmc->Contex == ESMC_CONTEXT_READ_FIXED_LENGTH)
          {
            /* Wait until idle flag is set */
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);
            if(status != HAL_OK)
            {
              break;
            }
          } 
          else if (hesmc->Contex == ESMC_CONTEXT_READ_VARIABLE_LENGTH)
          {
            /* Wait until datawait flag is set */
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_DATAWAITIF, SET, tickstart, Timeout);
            if(status != HAL_OK)
            {
              break;
            }
          }
          ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, hesmc->RxXferCount);
          hesmc->pRxBuffPtr += hesmc->RxXferCount;
          hesmc->RxXferCount = 0;
        }
      }

      /* Disable the slave select */
      __HAL_ESMC_DISABLE_SLAVE(hesmc);
      
      if(status == HAL_OK)
      {
        /* Update ESMC state */
        hesmc->State = HAL_ESMC_STATE_READY;
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  return status;
}

/**
  * @brief Receive an amount of data in blocking mode with FIFO Half Full
  * @param hesmc ESMC handle
  * @param pData pointer to data buffer
  * @param Timeout  Time out duration
  * @note   This function is used only in Indirect Read Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_ReceiveFIFO(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->RxXferCount != 0) && (hesmc->RxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_RX;

      hesmc->pRxBuffPtr = pData;

      /* send command */
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;
      
      while ((hesmc->RxXferCount/(HAL_ESMC_FIFO_SIZE/2)) > 0U)
      {   
        /* Wait until fifo half full flag is set */
        status= ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_RXFIFOHIF, SET, tickstart, Timeout);
        if(status != HAL_OK)
        {
          break;
        }
        ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, HAL_ESMC_FIFO_SIZE/2);
        hesmc->pRxBuffPtr += (HAL_ESMC_FIFO_SIZE/2);
        hesmc->RxXferCount -= (HAL_ESMC_FIFO_SIZE/2);
      }
      if(status == HAL_OK)
      {
        while (hesmc->RxXferCount != 0)
        {
          if (hesmc->Contex == ESMC_CONTEXT_READ_FIXED_LENGTH)
          {
            /* Wait until idle flag is set */
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLEDONEIF, SET, tickstart, Timeout);
            if(status != HAL_OK)
            {
              break;
            }
          } 
          else if (hesmc->Contex == ESMC_CONTEXT_READ_VARIABLE_LENGTH)
          {
            /* Wait until fifo full flag is set */
            status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_RXFIFOFIF, SET, tickstart, Timeout);
            if(status != HAL_OK)
            {
              break;
            }
          }
          ESMC_ReadBuff(hesmc, hesmc->pRxBuffPtr, hesmc->RxXferCount);
          hesmc->pRxBuffPtr += hesmc->RxXferCount;
          hesmc->RxXferCount = 0;
        }
      }

      /* Disable the slave select */
      __HAL_ESMC_DISABLE_SLAVE(hesmc);
      
      if(status == HAL_OK)
      {
        /* Update ESMC state */
        hesmc->State = HAL_ESMC_STATE_READY;
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;
    }
  }
  else
  {
    status = HAL_BUSY;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hesmc);

  return status;
}


/**
  * @brief  Send an amount of data in interrupt mode
  * @param  hesmc ESMC handle
  * @param  pData pointer to data buffer
  * @note   This function is used only in Indirect Write Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Transmit_IT(ESMC_HandleTypeDef *hesmc, uint8_t *pData)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->TxXferCount != 0) && (hesmc->TxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_TX;

      hesmc->pTxBuffPtr = pData;
      
      /* send command */
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);

      /* Enable the ESMC Interrupt */
      __HAL_ESMC_ENABLE_GLOBAL_IT(hesmc);

      if (hesmc->Contex == ESMC_CONTEXT_WRITE_FIXED_LENGTH)
      {
        __HAL_ESMC_ENABLE_IT(hesmc, (ESMC_IT_DATAWAIT | ESMC_IT_IDLEDONE));
      } 
      else
      {
        __HAL_ESMC_ENABLE_IT(hesmc, ESMC_IT_DATAWAIT);
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }

  return status;
}

/**
  * @brief  Receive an amount of data in no-blocking mode with Interrupt
  * @param  hesmc ESMC handle
  * @param  pData pointer to data buffer
  * @note   This function is used only in Indirect Read Mode
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Receive_IT(ESMC_HandleTypeDef *hesmc, uint8_t *pData)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->RxXferCount != 0) && (hesmc->RxXferSize != 0))
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_RX;

      hesmc->pRxBuffPtr = pData;

      /* send command */
      hesmc->Instance->ADDR24 = hesmc->ContexAddr24;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);

      /* Enable the ESMC Interrupt */
      __HAL_ESMC_ENABLE_GLOBAL_IT(hesmc);

      if (hesmc->Contex == ESMC_CONTEXT_READ_FIXED_LENGTH)
      {
        __HAL_ESMC_ENABLE_IT(hesmc, (ESMC_IT_DATAWAIT | ESMC_IT_IDLEDONE));
      } 
      else
      {
        __HAL_ESMC_ENABLE_IT(hesmc, ESMC_IT_DATAWAIT);
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }

  return status;
}

/**
  * @brief  Sends an amount of data in non blocking mode with DMA.
  * @param  hesmc ESMC handle
  * @param  pData pointer to data buffer
  * @note   This function is used only in Indirect Write Mode
  * @note   If DMA peripheral access is configured as halfword, the number
  *         of data and the fifo threshold should be aligned on halfword
  * @note   If DMA peripheral access is configured as word, the number
  *         of data and the fifo threshold should be aligned on word
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Transmit_DMA(ESMC_HandleTypeDef *hesmc, uint8_t *pData)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t *pData32 = (uint32_t *)pData;

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    /* Clear the error code */
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->TxXferCount != 0) && (hesmc->TxXferSize != 0))
    {
      /* Configure counters of the handle */
      if ((hesmc->hdmatx->Init.DstWidth == DMA_DST_WIDTH_WORD) && ((hesmc->TxXferSize % 4U) == 0U))
      {
        hesmc->TxXferCount = (hesmc->TxXferSize >> 2U);
      }
      else if((hesmc->hdmatx->Init.DstWidth == DMA_DST_WIDTH_HALFWORD)&&((hesmc->TxXferSize % 2U) == 0U) )
      {
        hesmc->TxXferCount = (hesmc->TxXferSize >> 1U );     
      }    
      else if(hesmc->hdmatx->Init.DstWidth == DMA_DST_WIDTH_BYTE)
      {
        hesmc->TxXferCount = (hesmc->TxXferSize);
      }      
      else
      {
        /* The number of data is not aligned on word
        => no transfer possible with DMA peripheral access configured as word */
        hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
        status = HAL_ERROR;

        /* Process unlocked */
        __HAL_UNLOCK(hesmc);
      }

      if (status == HAL_OK)
      {
        /* Update state */
        hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_TX;

        /* Configure size and pointer of the handle */
        hesmc->TxXferSize = hesmc->TxXferCount;
        hesmc->pTxBuffPtr = pData;

        /* Set the ESMC DMA transfer complete callback */
        hesmc->hdmatx->XferCpltCallback = ESMC_DMATxCplt;

        /* Set the ESMC DMA Half Block transfer complete callback */
        hesmc->hdmatx->XferHalfBlockCpltCallback = ESMC_DMATxHalfBlockCplt;

        /* Set the DMA error callback */
        hesmc->hdmatx->XferErrorCallback = ESMC_DMAError;

        /* Clear the DMA abort callback */
        hesmc->hdmatx->XferAbortCallback = NULL;

        /* Configure the direction of the DMA */
        hesmc->hdmatx->Init.Direction = DMA_MEMORY_TO_PERIPH;
      
        hesmc->Instance->ADDR24 = hesmc->ContexAddr24;
       
        SET_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);
        
        /* Enable the ESMC transmit DMA Channel */
        if (HAL_DMA_Start_IT(hesmc->hdmatx, (uint32_t)pData32, (uint32_t)&hesmc->Instance->DATA, hesmc->TxXferSize) == HAL_OK)
        {
          /* Process unlocked */
          __HAL_UNLOCK(hesmc);

        }
        else
        {
          status = HAL_ERROR;
          hesmc->ErrorCode |= HAL_ESMC_ERROR_DMA;
          hesmc->State = HAL_ESMC_STATE_READY;

          /* Process unlocked */
          __HAL_UNLOCK(hesmc);
        }
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }

  return status;
}




/**
  * @brief  Receives an amount of data in non blocking mode with DMA.
  * @param  hesmc ESMC handle
  * @param  pData pointer to data buffer.
  * @note   This function is used only in Indirect Read Mode
  * @note   If DMA peripheral access is configured as halfword, the number
  *         of data and the fifo threshold should be aligned on halfword
  * @note   If DMA peripheral access is configured as word, the number
  *         of data and the fifo threshold should be aligned on word
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Receive_DMA(ESMC_HandleTypeDef *hesmc, uint8_t *pData)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    /* Clear the error code */
    hesmc->ErrorCode = HAL_ESMC_ERROR_NONE;

    if((pData != NULL) && (hesmc->RxXferCount != 0) && (hesmc->RxXferSize != 0))
    {
      /* Configure counters of the handle */
      if ((hesmc->hdmarx->Init.SrcWidth == DMA_SRC_WIDTH_WORD) && ((hesmc->RxXferSize % 4U) == 0U))
      {
        hesmc->RxXferCount = (hesmc->RxXferSize >> 2U);
      }
      else
      {
        /* The number of data is not aligned on word
             => no transfer possible with DMA peripheral access configured as word */
        hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
        status = HAL_ERROR;

        /* Process unlocked */
        __HAL_UNLOCK(hesmc);
      }

      if (status == HAL_OK)
      {
        /* Update state */
        hesmc->State = HAL_ESMC_STATE_BUSY_INDIRECT_RX;

        /* Configure size and pointer of the handle */
        hesmc->RxXferSize = hesmc->RxXferCount;
        hesmc->pRxBuffPtr = pData;
                   
        /* Set the ESMC DMA transfer complete callback */
        hesmc->hdmarx->XferCpltCallback = ESMC_DMARxCplt;

        /* Set the ESMC DMA Half block transfer complete callback */
        hesmc->hdmarx->XferHalfBlockCpltCallback = ESMC_DMARxHalfBlockCplt;

        /* Set the DMA error callback */
        hesmc->hdmarx->XferErrorCallback = ESMC_DMAError;

        /* Clear the DMA abort callback */
        hesmc->hdmarx->XferAbortCallback = NULL;

        /* Configure the direction of the DMA */
        hesmc->hdmarx->Init.Direction = DMA_PERIPH_TO_MEMORY;

        /* Enable the DMA Channel */
        if (HAL_DMA_Start_IT(hesmc->hdmarx, (uint32_t)&hesmc->Instance->DATA, (uint32_t)pData, hesmc->RxXferSize) == HAL_OK)
        {
         /* Process unlocked */
          __HAL_UNLOCK(hesmc);
          
         /* Enable the DMA transfer by setting the DMAEN bit in the ESMC CR register */
         SET_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);
         /* send command */
         hesmc->Instance->ADDR24 = hesmc->ContexAddr24;         
        }
        else
        {
          status = HAL_ERROR;
          hesmc->ErrorCode |= HAL_ESMC_ERROR_DMA;
          hesmc->State = HAL_ESMC_STATE_READY;

          /* Process unlocked */
          __HAL_UNLOCK(hesmc);
        }
      }
    }
    else
    {
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_PARAM;
      status = HAL_ERROR;

      /* Process unlocked */
      __HAL_UNLOCK(hesmc);
    }
  }
  else
  {
    status = HAL_BUSY;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }

  return status;
}

/**
  * @brief  Writes 32-bit buffer to  memory.
  * @param  hesmc pointer to a ESMC_HandleTypeDef structure that contains
  *                the configuration information for ESMC module.
  * @param  pAddress Pointer to write start address
  * @param  pSrcBuffer Pointer to source buffer to write
  * @param  BufferSize Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Write_32b(ESMC_HandleTypeDef *hesmc, uint32_t *pAddress, uint32_t *pSrcBuffer,
                                     uint32_t BufferSize)
{
  uint32_t size;
  __IO uint32_t *psramaddress = pAddress;
  uint32_t *psrcbuff = pSrcBuffer;
  HAL_ESMC_StateTypeDef CurrentState = hesmc->State;

  if((CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITE) || (CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED))
  {
    /* Process Locked */
    __HAL_LOCK(hesmc);

    /* Update the controller state */
    hesmc->State = HAL_ESMC_STATE_BUSY;

    /* Write data to memory */
    for (size=0; size<BufferSize; size++)
    {
      *psramaddress = *psrcbuff;
      psrcbuff++;
      psramaddress++;
    }
    SET_BIT(ESMC->XSSOCR_WE,ESMC_XSSOCR_WE_SS_CLR_RQ);

    /* Update the controller state */
    hesmc->State = CurrentState;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

/**
  * @brief  Writes 16-bit buffer to memory.
  * @param  hesmc pointer to a EMSC_HandleTypeDef structure that contains
  *                the configuration information for ESMC module.
  * @param  pAddress Pointer to write start address
  * @param  pSrcBuffer Pointer to source buffer to write
  * @param  BufferSize Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Write_16b(ESMC_HandleTypeDef *hesmc, uint16_t *pAddress, uint16_t *pSrcBuffer,
                                     uint32_t BufferSize)
{
  uint32_t size;
  __IO uint16_t *psramaddress = pAddress;
  uint16_t *psrcbuff = pSrcBuffer;
  HAL_ESMC_StateTypeDef CurrentState = hesmc->State;

  /* Check the controller state */
  if((CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITE) || (CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED))
  {
    /* Process Locked */
    __HAL_LOCK(hesmc);

    /* Update the controller state */
    hesmc->State = HAL_ESMC_STATE_BUSY;
   
    /* Write data to memory */
    for (size=0; size<BufferSize; size=size+1)
    {
      *(uint16_t*)psramaddress = (uint16_t)(*psrcbuff);
      psramaddress++;
      psrcbuff++;
    }

    SET_BIT(ESMC->XSSOCR_WE,ESMC_XSSOCR_WE_SS_CLR_RQ);

    /* Update the controller state */
    hesmc->State = CurrentState;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

/**
  * @brief  Writes 8-bit buffer to memory.
  * @param  hesmc pointer to a ESMC_HandleTypeDef structure that contains
  *                the configuration information for ESMC module.
  * @param  pAddress Pointer to write start address
  * @param  pSrcBuffer Pointer to source buffer to write
  * @param  BufferSize Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ESMC_Write_8b(ESMC_HandleTypeDef *hesmc, uint8_t *pAddress, uint8_t *pSrcBuffer,
                                     uint32_t BufferSize)
{
  uint32_t size;
  __IO uint8_t *psramaddress = pAddress;
  uint8_t *psrcbuff = pSrcBuffer;
  HAL_ESMC_StateTypeDef CurrentState = hesmc->State;

  /* Check the controller state */
  if((CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITE) || (CurrentState == HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED))
  {
    /* Process Locked */
    __HAL_LOCK(hesmc);

    /* Update the controller state */
    hesmc->State = HAL_ESMC_STATE_BUSY;
   
    /* Write data to memory */
    for (size=0; size<BufferSize; size=size+1)
    {
      *(uint8_t*)psramaddress = (uint8_t)(*psrcbuff);
      psramaddress++;
      psrcbuff++;
    }

    SET_BIT(ESMC->XSSOCR_WE,ESMC_XSSOCR_WE_SS_CLR_RQ);

    /* Update the controller state */
    hesmc->State = CurrentState;

    /* Process unlocked */
    __HAL_UNLOCK(hesmc);
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

/**
  * @brief  Transfer Error callbacks
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_ErrorCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_ESMC_ErrorCallback could be implemented in the user file
   */
}

/**
  * @brief  Abort completed callback.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_AbortCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_ESMC_AbortCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Command completed callback.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_CmdCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_ESMC_CmdCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Rx Transfer completed callbacks.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_RxCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_ESMC_RxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Tx Transfer completed callbacks.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_TxCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_ESMC_TxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Rx Half Block Transfer completed callbacks.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_RxHalfBlockCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_ESMC_RxHalfCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Tx Half Block Transfer completed callbacks.
  * @param  hesmc ESMC handle
  * @retval None
  */
__weak void HAL_ESMC_TxHalfBlockCpltCallback(ESMC_HandleTypeDef *hesmc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hesmc);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_ESMC_TxHalfCpltCallback could be implemented in the user file
   */
}

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User ESMC Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param hesmc : ESMC handle
  * @param CallbackId : ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_ESMC_ERROR_CB_ID          ESMC Error Callback ID
  *          @arg @ref HAL_ESMC_ABORT_CB_ID          ESMC Abort Callback ID
  *          @arg @ref HAL_ESMC_CMD_CPLT_CB_ID       ESMC Command Complete Callback ID
  *          @arg @ref HAL_ESMC_RX_CPLT_CB_ID        ESMC Rx Complete Callback ID
  *          @arg @ref HAL_ESMC_TX_CPLT_CB_ID        ESMC Tx Complete Callback ID
  *          @arg @ref HAL_ESMC_RX_HALFBLOCK_CPLT_CB_ID   ESMC Rx Half Block Complete Callback ID
  *          @arg @ref HAL_ESMC_TX_HALFBLOCK_CPLT_CB_ID   ESMC Tx Half Block Complete Callback ID
  *          @arg @ref HAL_ESMC_MSP_INIT_CB_ID       ESMC MspInit callback ID
  *          @arg @ref HAL_ESMC_MSP_DEINIT_CB_ID     ESMC MspDeInit callback ID
  * @param pCallback : pointer to the Callback function
  * @retval status
  */
HAL_StatusTypeDef HAL_ESMC_RegisterCallback (ESMC_HandleTypeDef *hesmc, HAL_ESMC_CallbackIDTypeDef CallbackId, pESMC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(pCallback == NULL)
  {
    /* Update the error code */
    hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    switch (CallbackId)
    {
    case  HAL_ESMC_ERROR_CB_ID :
      hesmc->ErrorCallback = pCallback;
      break;
    case HAL_ESMC_ABORT_CB_ID :
      hesmc->AbortCpltCallback = pCallback;
      break;
    case HAL_ESMC_CMD_CPLT_CB_ID :
      hesmc->CmdCpltCallback = pCallback;
      break;
    case HAL_ESMC_RX_CPLT_CB_ID :
      hesmc->RxCpltCallback = pCallback;
      break;
    case HAL_ESMC_TX_CPLT_CB_ID :
      hesmc->TxCpltCallback = pCallback;
      break;
    case HAL_ESMC_RX_HALFBLOCK_CPLT_CB_ID :
      hesmc->RxHalfBlockCallback = pCallback;
      break;
    case HAL_ESMC_TX_HALFBLOCK_CPLT_CB_ID :
      hesmc->TxHalfBlockCallback = pCallback;
      break;
    case HAL_ESMC_MSP_INIT_CB_ID :
      hesmc->MspInitCallback = pCallback;
      break;
    case HAL_ESMC_MSP_DEINIT_CB_ID :
      hesmc->MspDeInitCallback = pCallback;
      break;
    default :
      /* Update the error code */
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (hesmc->State == HAL_ESMC_STATE_RESET)
  {
    switch (CallbackId)
    {
    case HAL_ESMC_MSP_INIT_CB_ID :
      hesmc->MspInitCallback = pCallback;
      break;
    case HAL_ESMC_MSP_DEINIT_CB_ID :
      hesmc->MspDeInitCallback = pCallback;
      break;
    default :
      /* Update the error code */
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hesmc);
  return status;
}

/**
  * @brief  Unregister a User ESMC Callback
  *         ESMC Callback is redirected to the weak (surcharged) predefined callback
  * @param hesmc : ESMC handle
  * @param CallbackId : ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_ESMC_ERROR_CB_ID          ESMC Error Callback ID
  *          @arg @ref HAL_ESMC_ABORT_CB_ID          ESMC Abort Callback ID
  *          @arg @ref HAL_ESMC_CMD_CPLT_CB_ID       ESMC Command Complete Callback ID
  *          @arg @ref HAL_ESMC_RX_CPLT_CB_ID        ESMC Rx Complete Callback ID
  *          @arg @ref HAL_ESMC_TX_CPLT_CB_ID        ESMC Tx Complete Callback ID
  *          @arg @ref HAL_ESMC_RX_HALFBLOCK_CPLT_CB_ID   ESMC Rx Half Block Callback ID
  *          @arg @ref HAL_ESMC_TX_HALFBLOCK_CPLT_CB_ID   ESMC Tx Half Block Callback ID
  *          @arg @ref HAL_ESMC_MSP_INIT_CB_ID       ESMC MspInit callback ID
  *          @arg @ref HAL_ESMC_MSP_DEINIT_CB_ID     ESMC MspDeInit callback ID
  * @retval status
  */
HAL_StatusTypeDef HAL_ESMC_UnRegisterCallback (ESMC_HandleTypeDef *hesmc, HAL_ESMC_CallbackIDTypeDef CallbackId)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hesmc);

  if(hesmc->State == HAL_ESMC_STATE_READY)
  {
    switch (CallbackId)
    {
    case  HAL_ESMC_ERROR_CB_ID :
      hesmc->ErrorCallback = HAL_ESMC_ErrorCallback;
      break;
    case HAL_ESMC_ABORT_CB_ID :
      hesmc->AbortCpltCallback = HAL_ESMC_AbortCpltCallback;
      break;
    case HAL_ESMC_CMD_CPLT_CB_ID :
      hesmc->CmdCpltCallback = HAL_ESMC_CmdCpltCallback;
      break;
    case HAL_ESMC_RX_CPLT_CB_ID :
      hesmc->RxCpltCallback = HAL_ESMC_RxCpltCallback;
      break;
    case HAL_ESMC_TX_CPLT_CB_ID :
      hesmc->TxCpltCallback = HAL_ESMC_TxCpltCallback;
      break;
    case HAL_ESMC_RX_HALFBLOCK_CPLT_CB_ID :
      hesmc->RxHalfBlockCallback = HAL_ESMC_RxHalfBlockCallback;
      break;
    case HAL_ESMC_TX_HALFBLOCK_CPLT_CB_ID :
      hesmc->TxHalfBlockCallback = HAL_ESMC_TxHalfBlockCallback;
      break;
    case HAL_ESMC_MSP_INIT_CB_ID :
      hesmc->MspInitCallback = HAL_ESMC_MspInit;
      break;
    case HAL_ESMC_MSP_DEINIT_CB_ID :
      hesmc->MspDeInitCallback = HAL_ESMC_MspDeInit;
      break;
    default :
      /* Update the error code */
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (hesmc->State == HAL_ESMC_STATE_RESET)
  {
    switch (CallbackId)
    {
    case HAL_ESMC_MSP_INIT_CB_ID :
      hesmc->MspInitCallback = HAL_ESMC_MspInit;
      break;
    case HAL_ESMC_MSP_DEINIT_CB_ID :
      hesmc->MspDeInitCallback = HAL_ESMC_MspDeInit;
      break;
    default :
      /* Update the error code */
      hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    hesmc->ErrorCode |= HAL_ESMC_ERROR_INVALID_CALLBACK;
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hesmc);
  return status;
}
#endif

/**
  * @}
  */

/** @defgroup ESMC_Exported_Functions_Group3 Peripheral Control and State functions
  *  @brief   ESMC control and State functions
  *
@verbatim
 ===============================================================================
                  ##### Peripheral Control and State functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to :
      (+) Check in run-time the state of the driver.
      (+) Check the error code set during last operation.
      (+) Abort any operation.
.....
@endverbatim
  * @{
  */

/**
  * @brief  Return the ESMC handle state.
  * @param  hesmc ESMC handle
  * @retval HAL state
  */
HAL_ESMC_StateTypeDef HAL_ESMC_GetState(ESMC_HandleTypeDef *hesmc)
{
  /* Return ESMC handle state */
  return hesmc->State;
}

/**
* @brief  Return the ESMC error code
* @param  hesmc ESMC handle
* @retval ESMC Error Code
*/
uint32_t HAL_ESMC_GetError(ESMC_HandleTypeDef *hesmc)
{
  return hesmc->ErrorCode;
}

/**
* @brief  Abort the current transmission
* @param  hesmc ESMC handle
* @retval HAL status
*/
HAL_StatusTypeDef HAL_ESMC_Abort(ESMC_HandleTypeDef *hesmc)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Check if the state is in one of the busy states */
  if ((hesmc->State & 0x2) != 0)
  {
    /* Process unlocked */
    __HAL_UNLOCK(hesmc);

    if ((hesmc->Instance->CR & ESMC_CR_DMAEN)!= RESET)
    {
      /* Abort DMA channel */
      if (hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_RX)
      {
        status = HAL_DMA_Abort(hesmc->hdmarx);
      }
      else if (hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_TX)
      {
        status = HAL_DMA_Abort(hesmc->hdmatx);
      }
      /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
      CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);

      if(status != HAL_OK)
      {
        hesmc->ErrorCode |= HAL_ESMC_ERROR_DMA;
      }
    }

    /* Disable the slave select, Abort communication */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);

    /* Wait until IDLE flag is set to go back in idle state */
    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);

    if(status == HAL_OK)
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_READY;
    }
  }

  return status;
}

/**
* @brief  Abort the current transmission (non-blocking function)
* @param  hesmc ESMC handle
* @retval HAL status
*/
HAL_StatusTypeDef HAL_ESMC_Abort_IT(ESMC_HandleTypeDef *hesmc)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Check if the state is in one of the busy states */
  if ((hesmc->State & 0x2) != 0)
  {
    /* Process unlocked */
    __HAL_UNLOCK(hesmc);

    /* Disable global interrupts */
    __HAL_ESMC_DISABLE_GLOBAL_IT(hesmc);
    /* Disable all interrupts */
    __HAL_ESMC_DISABLE_IT(hesmc, ESMC_IT_ALL);

    if ((hesmc->Instance->CR & ESMC_CR_DMAEN)!= RESET)
    {
      /* Abort DMA channel */
      hesmc->hdmarx->XferAbortCallback = ESMC_DMAAbortCplt;
      if (hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_RX)
      {
        status = HAL_DMA_Abort_IT(hesmc->hdmarx);
      }
      else if (hesmc->State == HAL_ESMC_STATE_BUSY_INDIRECT_TX)
      {
        status = HAL_DMA_Abort_IT(hesmc->hdmarx);
      }
      /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
      CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);
      if (status != HAL_OK)
      {
        /* Change state of ESMC */
        hesmc->State = HAL_ESMC_STATE_READY;

        /* Abort Complete callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
        hesmc->AbortCpltCallback(hesmc);
#else
        HAL_ESMC_AbortCpltCallback(hesmc);
#endif
      }
    }

    /* Disable the slave select, Abort communication */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);

    /* Wait until IDLE flag is set to go back in idle state */
    status = ESMC_WaitFlagStateUntilTimeout(hesmc, ESMC_FLAG_IDLE, SET, tickstart, hesmc->Timeout);

    if(status == HAL_OK)
    {
      /* Update state */
      hesmc->State = HAL_ESMC_STATE_READY;
    }
  }

  return status;
}

/** @brief Set ESMC timeout
  * @param  hesmc ESMC handle.
  * @param  Timeout Timeout for the ESMC memory access.
  * @retval None
  */
void HAL_ESMC_SetTimeout(ESMC_HandleTypeDef *hesmc, uint32_t Timeout)
{
  hesmc->Timeout = Timeout;
}


/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  DMA ESMC receive process complete callback.
  * @param  hdma DMA handle
  * @retval None
  */
static void ESMC_DMARxCplt(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = ( ESMC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  hesmc->RxXferCount = 0;

  /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
  CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);

  if (hesmc->Contex == ESMC_CONTEXT_READ_VARIABLE_LENGTH)
  {
    /* Disable the slave select */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);
  }

  /* Change state of ESMC */
  hesmc->State = HAL_ESMC_STATE_READY;

  /* Restore default values */
  hesmc->Contex = ESMC_CONTEXT_NONE;
}

/**
  * @brief  DMA ESMC transmit process complete callback.
  * @param  hdma DMA handle
  * @retval None
  */
static void ESMC_DMATxCplt(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = ( ESMC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  hesmc->TxXferCount = 0;

  /* Enable the ESMC Interrupt */
  __HAL_ESMC_ENABLE_GLOBAL_IT(hesmc);
  if (hesmc->Contex == ESMC_CONTEXT_WRITE_FIXED_LENGTH)
  {
    __HAL_ESMC_ENABLE_IT(hesmc, ESMC_IT_IDLEDONE);
  } 
  else
  {
    __HAL_ESMC_ENABLE_IT(hesmc, ESMC_IT_DATAWAIT);
  }
}

/**
  * @brief  DMA ESMC receive process half block complete callback
  * @param  hdma  DMA handle
  * @retval None
  */
static void ESMC_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = (ESMC_HandleTypeDef*)((DMA_HandleTypeDef*)hdma)->Parent;

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
  hesmc->RxHalfCpltCallback(hesmc);
#else
  HAL_ESMC_RxHalfBlockCpltCallback(hesmc);
#endif
}

/**
  * @brief  DMA ESMC transmit process half block complete callback
  * @param  hdma  DMA handle
  * @retval None
  */
static void ESMC_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = (ESMC_HandleTypeDef*)((DMA_HandleTypeDef*)hdma)->Parent;

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
  hesmc->TxHalfCpltCallback(hesmc);
#else
  HAL_ESMC_TxHalfBlockCpltCallback(hesmc);
#endif
}

/**
  * @brief  DMA ESMC communication error callback.
  * @param  hdma DMA handle
  * @retval None
  */
static void ESMC_DMAError(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = ( ESMC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;

  hesmc->RxXferCount = 0;
  hesmc->TxXferCount = 0;
  hesmc->ErrorCode   |= HAL_ESMC_ERROR_DMA;

  /* Disable the DMA transfer by clearing the DMAEN bit in the ESMC CR register */
  CLEAR_BIT(hesmc->Instance->CR, ESMC_CR_DMAEN);

  /* Abort the ESMC */
  HAL_ESMC_Abort_IT(hesmc);

}

/**
  * @brief  DMA ESMC abort complete callback.
  * @param  hdma DMA handle
  * @retval None
  */
static void ESMC_DMAAbortCplt(DMA_HandleTypeDef *hdma)
{
  ESMC_HandleTypeDef* hesmc = ( ESMC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;

  hesmc->RxXferCount = 0;
  hesmc->TxXferCount = 0;

  if(hesmc->State == HAL_ESMC_STATE_ABORT)
  {

  }
  else
  {
    /* DMA Abort called due to a transfer error interrupt */
    /* Change state of ESMC */
    hesmc->State = HAL_ESMC_STATE_READY;

    /* Error callback */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
    hesmc->ErrorCallback(hesmc);
#else
    HAL_ESMC_ErrorCallback(hesmc);
#endif
  }
}

/**
  * @brief  Wait for a flag state until timeout.
  * @param  hesmc ESMC handle
  * @param  Flag Flag checked
  * @param  State Value of the flag expected
  * @param  tickstart Start tick value
  * @param  Timeout Duration of the time out
  * @retval HAL status
  */
HAL_StatusTypeDef ESMC_WaitFlagStateUntilTimeout(ESMC_HandleTypeDef *hesmc, uint32_t Flag,
    FlagStatus State, uint32_t tickstart, uint32_t Timeout)
{
  /* Wait until flag is in expected state */
  while((__HAL_ESMC_GET_FLAG(hesmc, Flag)) != State)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0) || ((HAL_GetTick() - tickstart) > Timeout))
      {
        hesmc->State     = HAL_ESMC_STATE_ERROR;
        hesmc->ErrorCode |= HAL_ESMC_ERROR_TIMEOUT;

        return HAL_ERROR;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Configure the communication registers.
  * @param  hesmc ESMC handle
  * @param  cmd structure that contains the command configuration information
  * @param  FunctionalMode functional mode to configured
  *           This parameter can be one of the following values:
  *            @arg ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT: Instruct mode
  *            @arg ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE: write/read mode
  *            @arg ESMC_FUNCTIONAL_MODE_MEMORY_MAPPED: Memory Read
  *            @arg ESMC_FUNCTIONAL_MODE_MEMORY_WRITE: Memory Write
  * @retval None
  */
static void ESMC_Config(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd, uint32_t FunctionalMode)
{
  uint32_t TmpCR3 =0;
  uint32_t TmpSOCR = 0;
  uint32_t TmpDCR = 0;
  uint32_t TmpADDR24 = 0;
  uint32_t TmpADDR32 = 0;
  uint32_t TmpSFCR = 0;
  uint32_t TmpSTRR = 0;

  uint32_t TmpXSFCR =0;
  uint32_t TmpXSOCR = 0;
  uint32_t TmpXSSOCR = 0;
  uint32_t TmpXDCR = 0;
  uint32_t TmpXCR3 = 0;
  uint32_t TmpXMODE = 0;
  uint32_t TmpXSTRR = 0;

  uint32_t TmpXSFCR_WE = 0;
  uint32_t TmpXSOCR_WE = 0;
  uint32_t TmpXSSOCR_WE = 0;
  uint32_t TmpXDCR_WE = 0;
  uint32_t TmpXMODE_WE = 0;
  uint32_t TmpXCR3_WE = 0;

  assert_param(IS_ESMC_FUNCTIONAL_MODE(FunctionalMode));

  if(cmd->XspiDualLatency == ESMC_XSPI_DUALLATENCY_DISABLE)
  {
    SET_BIT(hesmc->Instance->CR2,ESMC_CR2_XSPI_DUAL_LAT_OFF);
  }
  else
  {
    CLEAR_BIT(hesmc->Instance->CR2,ESMC_CR2_XSPI_DUAL_LAT_OFF);
  }
  if (FunctionalMode == ESMC_FUNCTIONAL_MODE_INDIRECT_INSTRUCT)
  {
    /* Disable the slave select by default */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);

    /* clear fifo */
    __HAL_ESMC_CLEAR_FIFO(hesmc);

    TmpCR3 = hesmc->Instance->CR3;
    TmpSOCR = hesmc->Instance->SOCR;
    TmpDCR = hesmc->Instance->DCR;
    TmpADDR24 = hesmc->Instance->ADDR24;
    TmpADDR32 = hesmc->Instance->ADDR32;

    /* configure spi transfer format, instruction operation mode and DDR mode */
    MODIFY_REG(TmpSOCR, (ESMC_SOCR_SPIMODE | ESMC_SOCR_DDRADDR | ESMC_SOCR_DDRCMD | ESMC_SOCR_DDRDATA), \
               (cmd->TransferFormat | cmd->DdrMode));

    /* Set Instruction Mode */
    if (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES)
    {
      SET_BIT(TmpSOCR, ESMC_SOCR_MULTICMD);
    } 
    else
    {
      CLEAR_BIT(TmpSOCR, ESMC_SOCR_MULTICMD);
    }
 
    /* Set Instruction Length */
    if(cmd->InstrcutionLen == ESMC_INSTRCUTION_LEN_2_BYTE)
    {
      /* Set the Second Command */
      SET_BIT(TmpCR3,ESMC_CR3_CMD_EXT);
      MODIFY_REG(TmpADDR32,ESMC_ADDR32_MREG,(cmd->Instruction & ESMC_ADDR32_MREG));
    }
    else
    {
      /* Clear the Second Commnad */ 
      CLEAR_BIT(TmpCR3,ESMC_CR3_CMD_EXT);
      CLEAR_BIT(TmpADDR32,ESMC_ADDR32_MREG);
    }

    /* Set Command */
    CLEAR_BIT(TmpDCR, ESMC_DCR_NO_CMD); 

    /* Set NO ADDR/DATA */
    SET_BIT(TmpCR3, ESMC_CR3_NO_ADDR | ESMC_CR3_NO_DATA);

    /* configure slave select output */
    MODIFY_REG(TmpADDR32, ESMC_ADDR32_SSXO, (cmd->CSPinSel) << ESMC_ADDR32_SSXO_Pos);

    /* Modify DQS */
    MODIFY_REG(TmpCR3,ESMC_CR3_XSPI_RWDS,cmd->DQSMode); 

    /* Set Instruction */
    WRITE_REG(TmpSFCR,(cmd->Instruction)&ESMC_SFCR_SFCR0);

    /* write config values to register */
    WRITE_REG(hesmc->Instance->CR3, TmpCR3);
    WRITE_REG(hesmc->Instance->SOCR, TmpSOCR);
    WRITE_REG(hesmc->Instance->DCR, TmpDCR);
    WRITE_REG(hesmc->Instance->ADDR32, TmpADDR32);
    WRITE_REG(hesmc->Instance->SFCR, TmpSFCR);
  }
  else if (FunctionalMode == ESMC_FUNCTIONAL_MODE_INDIRECT_READ_WRITE)
  {
    /* Disable the slave select by default */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);

    /* clear fifo */
    __HAL_ESMC_CLEAR_FIFO(hesmc);

    TmpCR3 = hesmc->Instance->CR3;
    TmpSOCR = hesmc->Instance->SOCR;
    TmpDCR = hesmc->Instance->DCR;

    TmpADDR24 = hesmc->Instance->ADDR24;
    TmpADDR32 = hesmc->Instance->ADDR32;
      
    /* configure spi transfer format, instruction operation mode and DDR mode */
    MODIFY_REG(TmpSOCR, (ESMC_SOCR_SPIMODE | ESMC_SOCR_DDRADDR | ESMC_SOCR_DDRCMD | ESMC_SOCR_DDRDATA), \
               (cmd->TransferFormat | cmd->DdrMode));

    /* config command region */
    if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
    {
      CLEAR_BIT(TmpDCR, ESMC_DCR_NO_CMD);
      if (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES)
      {
        SET_BIT(TmpSOCR, ESMC_SOCR_MULTICMD);
      } 
      else
      {
        CLEAR_BIT(TmpSOCR, ESMC_SOCR_MULTICMD);
      }
      /* set command value */
      MODIFY_REG(TmpADDR24, ESMC_ADDR24_INS1, (uint8_t)((cmd->Instruction)&ESMC_ADDR24_INS1));
    } 
    else
    {
      /* No instruction and begin with Address */
      SET_BIT(TmpDCR, ESMC_DCR_NO_CMD);
    }
 
    if(cmd->InstrcutionLen == ESMC_INSTRCUTION_LEN_2_BYTE)
    {
      SET_BIT(TmpCR3,ESMC_CR3_CMD_EXT);
      MODIFY_REG(TmpADDR32,ESMC_ADDR32_MREG,(cmd->Instruction & ESMC_ADDR32_MREG));
    }
    else
    {
      CLEAR_BIT(TmpCR3,ESMC_CR3_CMD_EXT);
    }
     
    /* config address region */
    if (cmd->AddressMode != ESMC_ADDRESS_NONE)
    {
      CLEAR_BIT(TmpCR3,ESMC_CR3_NO_ADDR);

      if ((cmd->AddressMode == ESMC_ADDRESS_MULTI_LINES) || \
          (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES))
      {
        SET_BIT(TmpSOCR, ESMC_SOCR_MULTIADDR);
      } 
      else
      {
        CLEAR_BIT(TmpSOCR, ESMC_SOCR_MULTIADDR);
      }
       
      /* Modify Address Size */
      MODIFY_REG(TmpCR3, (ESMC_CR3_ADDR8BIT | ESMC_CR3_ADDR16BIT | ESMC_CR3_ADDR32BIT), cmd->AddressSize);

      /* Set Address Value */
      if (cmd->AddressSize == ESMC_ADDRESS_32_BITS)
      {
        MODIFY_REG(TmpADDR32, ESMC_ADDR32_ADDR3, ((cmd->Address >> 24) & ESMC_ADDR32_ADDR3));
      }
      /* Set Address Value */
      MODIFY_REG(TmpADDR24, (ESMC_ADDR24_ADDR0 | ESMC_ADDR24_ADDR1 | ESMC_ADDR24_ADDR2), \
                 ((cmd->Address & 0x00FFFFFF) << ESMC_ADDR24_ADDR0_Pos));
    } 
    else
    {
      SET_BIT(TmpCR3, ESMC_CR3_NO_ADDR);     
    }

    /* Config Alternate region */
    if (cmd->AlternateByteMode == ESMC_ALTERNATE_BYTES_ENABLE)
    {
      /* Set Alternate byte */
      MODIFY_REG(TmpADDR32, ESMC_ADDR32_MREG, cmd->AlternateByte<<ESMC_ADDR32_MREG_Pos);
      SET_BIT(TmpSOCR, ESMC_SOCR_SENM);
    } 
    else
    {
      /* Clear Alternate byte */
      CLEAR_BIT(TmpSOCR, ESMC_SOCR_SENM);
    }

    /* config dummy region */
    MODIFY_REG(TmpDCR, ESMC_DCR_DUMMY, cmd->DummyCycles);

    /* configure slave select output */
    MODIFY_REG(TmpADDR32, ESMC_ADDR32_SSXO, (cmd->CSPinSel) << ESMC_ADDR32_SSXO_Pos);

    MODIFY_REG(TmpCR3,ESMC_CR3_XSPI_RWDS,cmd->DQSMode);

    /* config data region */
    if ((cmd->DataMode == ESMC_DATA_WRITE) && (cmd->NbData != 0))
    {
      /* set write mode */
      CLEAR_BIT(TmpDCR, ESMC_DCR_REC);
      if (cmd->NbData >= HAL_ESMC_TCR_MAX_LENGTH)
      {
        /* Read/write of undefined number of data bytes from/to FLASH */
        WRITE_REG(hesmc->Instance->BCR, 0);
        hesmc->Contex = ESMC_CONTEXT_WRITE_VARIABLE_LENGTH;
      } 
      else
      {
        /* Read/write specified number of data bytes from/to FLASH */
        WRITE_REG(hesmc->Instance->BCR, cmd->NbData);
        hesmc->Contex = ESMC_CONTEXT_WRITE_FIXED_LENGTH;
      }

      /* Configure counters and size of the handle */
      hesmc->TxXferCount = cmd->NbData;
      hesmc->TxXferSize  = cmd->NbData;
    }
    else if ((cmd->DataMode == ESMC_DATA_READ) && (cmd->NbData != 0))
    {
      /* set read mode */
      SET_BIT(TmpDCR, ESMC_DCR_REC);
      if (cmd->NbData >= HAL_ESMC_TCR_MAX_LENGTH)
      {
        /* Read/write of undefined number of data bytes from/to FLASH */
        WRITE_REG(hesmc->Instance->BCR, 0);
        hesmc->Contex = ESMC_CONTEXT_READ_VARIABLE_LENGTH;
      } 
      else
      {
        /* Read/write specified number of data bytes from/to FLASH */
        WRITE_REG(hesmc->Instance->BCR, cmd->NbData);
        hesmc->Contex = ESMC_CONTEXT_READ_FIXED_LENGTH;
      }

      /* Configure counters and size of the handle */
      hesmc->RxXferCount = cmd->NbData;
      hesmc->RxXferSize  = cmd->NbData;
    } 
    else
    {
      CLEAR_BIT(TmpDCR, ESMC_DCR_REC);

      WRITE_REG(hesmc->Instance->BCR, 0);

      /* Restore default values */
      hesmc->Contex = ESMC_CONTEXT_NONE;
    }

    /* Set Sample Shifting */
    WRITE_REG(TmpSTRR,cmd->SampleShifting);

    WRITE_REG(hesmc->Instance->ADDR32, TmpADDR32);
    WRITE_REG(hesmc->Instance->SOCR, TmpSOCR);
    WRITE_REG(hesmc->Instance->DCR, TmpDCR);
    WRITE_REG(hesmc->Instance->STRR,TmpSTRR);

    if (cmd->DataMode != ESMC_DATA_NONE)
    {
      CLEAR_BIT(TmpCR3,ESMC_CR3_NO_DATA);
      WRITE_REG(hesmc->Instance->CR3, TmpCR3);
      hesmc->ContexAddr24 = TmpADDR24;
    } 
    else
    {
      SET_BIT(TmpCR3,ESMC_CR3_NO_DATA);
      WRITE_REG(hesmc->Instance->CR3, TmpCR3);
      WRITE_REG(hesmc->Instance->ADDR24, TmpADDR24);
    }
  } 
  else if (FunctionalMode == ESMC_FUNCTIONAL_MODE_MEMORY_MAPPED)
  {
    __HAL_ESMC_DISABLE_SLAVE(hesmc);
    __HAL_ESMC_CLEAR_FIFO(hesmc);

    TmpXSFCR = hesmc->Instance->XSFCR;
    TmpXSOCR = hesmc->Instance->XSOCR;
    TmpXDCR  = hesmc->Instance->XDCR;
    TmpXCR3 = hesmc->Instance->XCR3;
    TmpXMODE = hesmc->Instance->XMODE;
    TmpXSSOCR = hesmc->Instance->XSSOCR;

    /* configure spi transfer format, instruction operation mode and DDR mode */
    MODIFY_REG(TmpXSOCR, (ESMC_SOCR_SPIMODE | ESMC_XSOCR_DDRCMD | ESMC_XSOCR_DDRADDR | ESMC_XSOCR_DDRDATA), \
               (cmd->TransferFormat | cmd->DdrMode));

    /* Config Instruction Mode */
    if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
    {
      CLEAR_BIT(TmpXDCR, ESMC_XDCR_NO_CMD);
      if (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES)
      {
        SET_BIT(TmpXSOCR, ESMC_XSOCR_MULTICMD);
      } 
      else
      {
        CLEAR_BIT(TmpXSOCR, ESMC_XSOCR_MULTICMD);
      }
    }
    else
    {
      SET_BIT(TmpXDCR, ESMC_XDCR_NO_CMD);
      CLEAR_BIT(TmpXSOCR, ESMC_XSOCR_MULTICMD);
    }

    /* Config Instruction Length */
    if(cmd->InstrcutionLen == ESMC_INSTRCUTION_LEN_2_BYTE)
    {
      SET_BIT(TmpXCR3, ESMC_XCR3_CMD_EXT);
      MODIFY_REG(TmpXMODE,ESMC_XMODE_XMODE,(uint8_t)((cmd->Instruction>>8)&ESMC_XMODE_XMODE));
    }
    else
    {
      CLEAR_BIT(TmpXCR3,ESMC_XCR3_CMD_EXT);
      CLEAR_BIT(TmpXMODE,ESMC_XMODE_XMODE);
    }

    /* config address region */
    CLEAR_BIT(TmpXDCR, ESMC_XCR3_NO_ADDR);

    if ((cmd->AddressMode == ESMC_ADDRESS_MULTI_LINES) || \
        (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES))
    {
      SET_BIT(TmpXSOCR, ESMC_XSOCR_MULTIADDR);
    } 
    else
    {
      CLEAR_BIT(TmpXSOCR, ESMC_XSOCR_MULTIADDR);
    }

    /* Config Address Size */
    MODIFY_REG(TmpXCR3, (ESMC_XCR3_ADDR8BIT | ESMC_XCR3_ADDR16BIT | ESMC_XCR3_ADDR32BIT), cmd->AddressSize);

    /* Config Alternate region */
    if (cmd->AlternateByteMode == ESMC_ALTERNATE_BYTES_ENABLE)
    {
      /* Config alternate byte */
      MODIFY_REG(TmpXMODE, ESMC_XMODE_XMODE, cmd->AlternateByte);
      SET_BIT(TmpXSOCR, ESMC_XSOCR_SEND_M);
    } 
    else
    {
      CLEAR_BIT(TmpXSOCR, ESMC_XSOCR_SEND_M);
    }
      
    /* Config Dummy Cycles */
    MODIFY_REG(TmpXDCR, ESMC_XDCR_XDUMMY, cmd->DummyCycles);

    /* Config CS */
    MODIFY_REG(TmpXSSOCR, ESMC_XSSOCR_SSXO, cmd->CSPinSel);

    /* Config DQS Mode */
    MODIFY_REG(TmpXCR3,ESMC_XCR3_XSPI_RWDS,cmd->DQSMode); 

    /* Config Instrction */
    WRITE_REG(TmpXSFCR,(uint8_t)(cmd->Instruction & ESMC_XSFCR_XINS));

    /* Config Sample Shifting */
    WRITE_REG(TmpXSTRR,cmd->SampleShifting);

    WRITE_REG(hesmc->Instance->XCR3, TmpXCR3);   
    WRITE_REG(hesmc->Instance->XSSOCR, TmpXSSOCR);
    WRITE_REG(hesmc->Instance->XSOCR, TmpXSOCR);
    WRITE_REG(hesmc->Instance->XDCR, TmpXDCR);
    WRITE_REG(hesmc->Instance->XMODE, TmpXMODE);
    WRITE_REG(hesmc->Instance->XSTRR,TmpXSTRR);

    if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
    {
      WRITE_REG(hesmc->Instance->XSFCR, TmpXSFCR);
    }  
  }
  else if (FunctionalMode == ESMC_FUNCTIONAL_MODE_MEMORY_WRITE)
  { 
    /* Disable the slave select by default */
    __HAL_ESMC_DISABLE_SLAVE(hesmc);

    /* clear fifo */
    __HAL_ESMC_CLEAR_FIFO(hesmc);

    TmpXMODE_WE = hesmc->Instance->XMODE_WE;
    TmpXSSOCR_WE = hesmc->Instance->XSSOCR_WE;
    TmpXSFCR_WE = hesmc->Instance->XSFCR_WE;
    TmpXSOCR_WE = hesmc->Instance->XSOCR_WE;
    TmpXDCR_WE  = hesmc->Instance->XDCR_WE;
    TmpXCR3_WE = hesmc->Instance->XCR3_WE;
 
    /* configure spi transfer format, instruction operation mode and DDR mode */
    MODIFY_REG(TmpXSOCR_WE, (ESMC_XSOCR_WE_SPI_MODE | ESMC_XSOCR_WE_DDRADDR | ESMC_XSOCR_WE_DDRCMD | ESMC_XSOCR_WE_DDRDATA), \
               (cmd->TransferFormat | cmd->DdrMode));

    /* config command region */
    if (cmd->InstructionMode != ESMC_INSTRUCTION_NONE)
    {
      WRITE_REG(TmpXSFCR_WE, cmd->Instruction);

      CLEAR_BIT(TmpXDCR_WE, ESMC_XDCR_WE_NO_CMD);

      if (cmd->InstructionMode  == ESMC_INSTRUCTION_MULTI_LINES)
      {
        SET_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_MULTICMD);
      } 
      else
      {
        CLEAR_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_MULTICMD);
      }
    }
    else
    {
      /* no instruction and begin with Address */
      SET_BIT(TmpXDCR_WE, ESMC_XDCR_WE_NO_CMD);
    }
    
    if(cmd->InstrcutionLen == ESMC_INSTRCUTION_LEN_2_BYTE)
    {
      SET_BIT(TmpXCR3_WE,ESMC_XCR3_WE_CMD_EXT);
      MODIFY_REG(TmpXMODE_WE,ESMC_XMODE_WE_XMODE_WE,(cmd->Instruction>>8)&ESMC_XMODE_WE_XMODE_WE);
    }
    else
    {
       CLEAR_BIT(TmpXCR3_WE,ESMC_XCR3_WE_CMD_EXT);
       CLEAR_BIT(TmpXMODE_WE,ESMC_XMODE_WE_XMODE_WE);
    }

    /* config address region */
    CLEAR_BIT(TmpXDCR_WE, ESMC_XCR3_WE_NO_ADDR);

    if (cmd->AddressMode == ESMC_ADDRESS_MULTI_LINES)
    {
      SET_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_MULTIADDR);
    } 
    else
    {
      CLEAR_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_MULTIADDR);
    }

    /* Condig Address Size */
    MODIFY_REG(TmpXCR3_WE, (ESMC_XCR3_WE_ADDR8BIT | ESMC_XCR3_WE_ADDR16BIT | ESMC_XCR3_WE_ADDR32BIT), cmd->AddressSize);

    /* Config Alternate Region */
    if (cmd->AlternateByteMode == ESMC_ALTERNATE_BYTES_ENABLE)
    {
      /* configure alternate byte */
      MODIFY_REG(TmpXMODE_WE, ESMC_XMODE_WE_XMODE_WE, cmd->AlternateByte);
      SET_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_SEND_M);
    } 
    else
    {
      CLEAR_BIT(TmpXSOCR_WE, ESMC_XSOCR_WE_SEND_M);
    }

    /* Config Dummy Cycles */
    MODIFY_REG(TmpXDCR_WE, ESMC_XDCR_XDUMMY, cmd->DummyCycles);
   
    /* Config CS */
    MODIFY_REG(TmpXSSOCR_WE, ESMC_XSSOCR_WE_SSXO, (cmd->CSPinSel) << ESMC_XSSOCR_WE_SSXO_Pos);

    /* Config DQS */
    MODIFY_REG(TmpXCR3_WE,ESMC_XCR3_XSPI_RWDS,cmd->DQSMode); 

    /* write register */
    WRITE_REG(hesmc->Instance->XSOCR_WE, TmpXSOCR_WE);
    WRITE_REG(hesmc->Instance->XDCR_WE, TmpXDCR_WE);
    WRITE_REG(hesmc->Instance->XMODE_WE, TmpXMODE_WE);
    WRITE_REG(hesmc->Instance->XCR3_WE, TmpXCR3_WE);
    WRITE_REG(hesmc->Instance->XSSOCR_WE, TmpXSSOCR_WE);
    WRITE_REG(hesmc->Instance->XSFCR_WE, TmpXSFCR_WE);
  }
}

/**
  * @brief  Write data to FIFO.
  * @param  hesmc ESMC handle
  * @param  pData Data buffer pointer
  * @param  dataLen Number of bytes to be written
  * @retval None
  */
void ESMC_WriteBuff(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint8_t dataLen)
{
  uint8_t len32 = (dataLen & 0xFC) >> 2;
  uint8_t len8 = dataLen & 0x03;
  uint8_t i = 0 ;
  uint32_t data = 0;
  __IO uint8_t *data_reg8 = (uint8_t *)(&hesmc->Instance->DATA);

  for(i=0; i<len32; i++)
  {
    data = (uint32_t)(*pData++);
    data |= ((uint32_t)(*pData++) << 8);
    data |= ((uint32_t)(*pData++) << 16);
    data |= ((uint32_t)(*pData++) << 24);
    hesmc->Instance->DATA = data;
  }

  for(i=0; i<len8; i++)
  {
    *data_reg8 = *pData++;
  }
}

/**
  * @brief  Write data to FIFO.
  * @param  hesmc ESMC handle
  * @param  pData Data buffer pointer
  * @param  dataLen Number of bytes to be written
  * @retval None
  */
void ESMC_ReadBuff(ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint8_t dataLen)
{
  uint8_t len32 = (dataLen & 0xFC) >> 2;
  uint8_t len8 = dataLen & 0x03;
  uint8_t i;
  uint32_t data;
  
  for(i=0; i<len32; i++)
  {
    data = hesmc->Instance->DATA;
    *pData++ = (uint8_t)(data & 0xFFU);
    *pData++ = (uint8_t)((data >> 8U) & 0xFFU);
    *pData++ = (uint8_t)((data >> 16U) & 0xFFU);
    *pData++ = (uint8_t)((data >> 24U) & 0xFFU);
  }

  if (len8 != 0)
  {
    data = hesmc->Instance->DATA;
    while (len8--)
    {
      *pData++ = (uint8_t)(data & 0xFFU);
      data >>= 8;
    }
  }
}

/**
  * @}
  */

#endif /* HAL_ESMC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
