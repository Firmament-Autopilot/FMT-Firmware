/**
  ******************************************************************************
  * @file    py32e407_hal_esmc.h
  * @author  MCU Application Team
  * @brief   Header file of ESMC HAL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PY32E407_HAL_ESMC_H
#define __PY32E407_HAL_ESMC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup ESMC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup ESMC_Exported_Types ESMC Exported Types
  * @{
  */

/**
  * @brief  ESMC Init structure definition
  */

typedef struct
{
  uint32_t ClockPrescaler;       /* Specifies the prescaler factor for generating clock based on the AHB clock.
                                    This parameter can be a number between 2 and 255 */

  uint32_t ClockMode;            /* Specifies the Clock Mode. It indicates the level that clock takes between commands.
                                    This parameter can be a value of @ref ESMC_ClockMode */

  uint32_t DualFlash;            /* Specifies the Dual Flash Mode State
                                    This parameter can be a value of @ref ESMC_DualFlash_Mode */
  
  uint32_t ChipSelectHighTime;   /* Specifies the Chip Select High Time. ChipSelectHighTime+1 defines the minimum number
                                    of clock cycles which the chip select must remain high between commands.
                                    This parameter can be a value of @ref QSPI_ChipSelectHighTime */

  uint32_t ChipSelectHoldTime;   /* Specifies the Chip Select High Time. ChipSelectHoldTime+1 defines the minimum number
                                    of clock cycles which the chip select must remain low between commands.
                                    This parameter can be a value of @ref QSPI_ChipSelectHoldTime */


} ESMC_InitTypeDef;

/**
  * @brief HAL ESMC State structures definition
  */
typedef enum
{
  HAL_ESMC_STATE_RESET             = 0x00U,    /*!< Peripheral not initialized                            */
  HAL_ESMC_STATE_READY             = 0x01U,    /*!< Peripheral initialized and ready for use              */
  HAL_ESMC_STATE_BUSY              = 0x02U,    /*!< Peripheral in indirect mode and busy                  */
  HAL_ESMC_STATE_BUSY_INDIRECT_TX  = 0x12U,    /*!< Peripheral in indirect mode with transmission ongoing */
  HAL_ESMC_STATE_BUSY_INDIRECT_RX  = 0x22U,    /*!< Peripheral in indirect mode with reception ongoing    */
  HAL_ESMC_STATE_BUSY_AUTO_POLLING = 0x42U,    /*!< Peripheral in auto polling mode ongoing               */
  HAL_ESMC_STATE_BUSY_MEM_MAPPED   = 0x40U,    /*!< Peripheral in memory mapped mode ongoing              */
  HAL_ESMC_STATE_BUSY_MEM_WRITE    = 0x80U,    /*!< Peripheral in memory write mode ongoing              */
  HAL_ESMC_STATE_BUSY_MEM_WRITEANDMAPPED   = 0xC0U,    /*!< Peripheral in memory mapped mode and write ongoing              */
  HAL_ESMC_STATE_ABORT             = 0x08U,    /*!< Peripheral with abort request ongoing                 */
  HAL_ESMC_STATE_ERROR             = 0x04U     /*!< Peripheral in error                                   */
} HAL_ESMC_StateTypeDef;

/**
  * @brief  ESMC Handle Structure definition
  */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
typedef struct __ESMC_HandleTypeDef
#else
typedef struct
#endif
{
  ESMC_TypeDef               *Instance;        /* ESMC registers base address        */
  ESMC_InitTypeDef           Init;             /* ESMC communication parameters      */
  uint8_t                    *pTxBuffPtr;      /* Pointer to ESMC Tx transfer Buffer */
  __IO uint32_t              TxXferSize;       /* ESMC Tx Transfer size              */
  __IO uint32_t              TxXferCount;      /* ESMC Tx Transfer Counter           */
  uint8_t                    *pRxBuffPtr;      /* Pointer to ESMC Rx transfer Buffer */
  __IO uint32_t              RxXferSize;       /* ESMC Rx Transfer size              */
  __IO uint32_t              RxXferCount;      /* ESMC Rx Transfer Counter           */
  DMA_HandleTypeDef          *hdmarx;          /* ESMC Rx DMA Handle parameters      */
  DMA_HandleTypeDef          *hdmatx;          /* ESMC Tx DMA Handle parameters      */
  __IO HAL_LockTypeDef       Lock;             /* Locking object                     */
  __IO HAL_ESMC_StateTypeDef State;            /* ESMC communication state           */
  __IO uint32_t              ErrorCode;        /* ESMC Error code                    */
  uint32_t                   Timeout;          /* Timeout for the ESMC memory access */
  uint32_t                   Contex;           /* ESMC transfer context */
  uint32_t                   ContexAddr24;     /* Temporarily store the value of register ADDR24 */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
  void (* ErrorCallback)        (struct __ESMC_HandleTypeDef *hesmc);
  void (* AbortCpltCallback)    (struct __ESMC_HandleTypeDef *hesmc);
  void (* CmdCpltCallback)      (struct __ESMC_HandleTypeDef *hesmc);
  void (* RxCpltCallback)       (struct __ESMC_HandleTypeDef *hesmc);
  void (* TxCpltCallback)       (struct __ESMC_HandleTypeDef *hesmc);
  void (* RxHalfBlockCpltCallback)   (struct __ESMC_HandleTypeDef *hesmc);
  void (* TxHalfBlockCpltCallback)   (struct __ESMC_HandleTypeDef *hesmc);
  void (* MspInitCallback)      (struct __ESMC_HandleTypeDef *hesmc);
  void (* MspDeInitCallback)    (struct __ESMC_HandleTypeDef *hesmc);
#endif
} ESMC_HandleTypeDef;

/**
  * @brief  ESMC Command structure definition
  */
typedef struct
{
  uint32_t TransferFormat;     /* Specifies the Transfer Format
                                  This parameter can be a value of @ref ESMC_TransferFormat */
  uint32_t InstructionMode;    /* Specifies the Instruction Mode
                                  This parameter can be a value of @ref ESMC_InstructionMode */
  uint32_t InstrcutionLen;     /* Specifies the Instruction Length
                                  This parameter can be a value of @ref ESMC_InstructionLen */ 

  uint32_t Instruction;        /* Specifies the Instruction to be sent
                                  This parameter can be a value (8-bit) between 0x00 and 0xFF or (16-bit) between 0x0 and 0xFFFF */  
  uint32_t AddressMode;        /* Specifies the Address Mode
                                  This parameter can be a value of @ref ESMC_AddressMode */
  uint32_t AddressSize;        /* Specifies the Address Size
                                  This parameter can be a value of @ref ESMC_AddressSize */
  uint32_t Address;            /* Specifies the Address to be sent (Size from 1 to 4 bytes according AddressSize)
                                  This parameter can be a value (32-bits) between 0x0 and 0xFFFFFFFF */
  uint32_t AlternateByteMode;  /* Specifies the Alternate Bytes Mode
                                  This parameter can be a value of @ref ESMC_AlternateBytesMode */
  uint32_t AlternateByte;      /* Specifies the Alternate Byte to be sent
                                  This parameter can be a value (8-bits) between 0x0 and 0xFF */
  uint32_t DataMode;           /* Specifies the Data Mode (used for dummy cycles and data phases)
                                  This parameter can be a value of @ref ESMC_DataMode */
  uint32_t NbData;             /* Specifies the number of data to transfer.
                                  This parameter can be any value between 1 and 0xFFFFFFFF */
  uint32_t DdrMode;            /* Specifies the double data rate mode for address, and data phase
                                  This parameter can be a value of @ref ESMC_DdrMode */
  uint32_t DummyCycles;        /* Specifies the Number of Dummy Cycles.
                                  This parameter can be a number between 0 and 31 */
  uint32_t CSPinSel;           /* Specifies the activated SSxO pin
                                  This parameter can be a value of @ref ESMC_CS_PIN_SEL */                                
  uint32_t DQSMode;            /* Specifies the activated DQSMode
                                  This parameter can be a value of @ref ESMC_DQSMode */    
  uint32_t SampleShifting;     /* Specifies the activated SampleShifting
                                  This parameter can be a value of @ref ESMC_SampleShifting */    
  uint32_t XspiDualLatency;    /* Specifies the activated DualLatency 
                                  This parameter can be a value of @ref ESMC_XSPI_DualLatency */    

} ESMC_CommandTypeDef;


#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL ESMC Callback ID enumeration definition
  */
typedef enum
{
  HAL_ESMC_ERROR_CB_ID          = 0x00U,  /*!< ESMC Error Callback ID            */
  HAL_ESMC_ABORT_CB_ID          = 0x01U,  /*!< ESMC Abort Callback ID            */
  HAL_ESMC_CMD_CPLT_CB_ID       = 0x02U,  /*!< ESMC Command Complete Callback ID */
  HAL_ESMC_RX_CPLT_CB_ID        = 0x03U,  /*!< ESMC Rx Complete Callback ID      */
  HAL_ESMC_TX_CPLT_CB_ID        = 0x04U,  /*!< ESMC Tx Complete Callback ID      */
  HAL_ESMC_RX_HALFBLOCK_CPLT_CB_ID   = 0x05U,  /*!< ESMC Rx Half Block Complete Callback ID */
  HAL_ESMC_TX_HALFBLOCK_CPLT_CB_ID   = 0x06U,  /*!< ESMC Tx Half Block Complete Callback ID */
  HAL_ESMC_MSP_INIT_CB_ID       = 0x07U,  /*!< ESMC MspInit Callback ID          */
  HAL_ESMC_MSP_DEINIT_CB_ID     = 0x08U   /*!< ESMC MspDeInit Callback ID        */
} HAL_ESMC_CallbackIDTypeDef;

/**
  * @brief  HAL ESMC Callback pointer definition
  */
typedef void (*pESMC_CallbackTypeDef)(ESMC_HandleTypeDef *hesmc);
#endif
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ESMC_Exported_Constants ESMC Exported Constants
  * @{
  */

/** @defgroup ESMC_FIFO_SIZE ESMC FIFO SIZE
  * @{
  */
#define HAL_ESMC_TCR_MAX_LENGTH       0xFFFFFFFF
#define HAL_ESMC_FIFO_SIZE            0x10
/**
  * @}
  */
  
/** @defgroup ESMC_ErrorCode ESMC Error Code
  * @{
  */
#define HAL_ESMC_ERROR_NONE            ((uint32_t)0x00000000U) /*!< No error           */
#define HAL_ESMC_ERROR_TIMEOUT         ((uint32_t)0x00000001U) /*!< Timeout error      */
#define HAL_ESMC_ERROR_TRANSFER        ((uint32_t)0x00000002U) /*!< Transfer error     */
#define HAL_ESMC_ERROR_DMA             ((uint32_t)0x00000004U) /*!< DMA transfer error */
#define HAL_ESMC_ERROR_INVALID_PARAM   ((uint32_t)0x00000008U) /*!< Invalid parameters error */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
#define HAL_ESMC_ERROR_INVALID_CALLBACK 0x00000010U /*!< Invalid callback error   */
#endif
/**
  * @}
  */

/** @defgroup ESMC_CONTEXT ESMC CONTEXT
  * @{
  */
#define ESMC_CONTEXT_NONE                   ((uint32_t)0x00000000U)  /*!< None                             */
#define ESMC_CONTEXT_READ_FIXED_LENGTH      ((uint32_t)0x00000001U)  /*!< Read single block operation      */
#define ESMC_CONTEXT_READ_VARIABLE_LENGTH   ((uint32_t)0x00000002U)  /*!< Read multiple blocks operation   */
#define ESMC_CONTEXT_WRITE_FIXED_LENGTH     ((uint32_t)0x00000010U)  /*!< Write single block operation     */
#define ESMC_CONTEXT_WRITE_VARIABLE_LENGTH  ((uint32_t)0x00000020U)  /*!< Write multiple blocks operation  */
/**
  * @}
  */
  
/** @defgroup ESMC_DQSMode  ESMC DQS Mode
  * @{
  */
#define ESMC_DQS_DISABLE                    ((uint32_t)0x00000000U)         /*!< Disable DQS */
#define ESMC_DQS_ENABLE                     ((uint32_t)ESMC_CR3_XSPI_RWDS)  /*!< Enable DQS */
/**
  * @}
  */

/** @defgroup ESMC_ClockMode ESMC Clock Mode
  * @{
  */
#define ESMC_CLOCK_MODE_0                   ((uint32_t)0x00000000U)                     /*!<Clk stays low while nCS is released, the first data sampling is the first clock edge*/
#define ESMC_CLOCK_MODE_3                   ((uint32_t)(ESMC_CR2_CPOL | ESMC_CR2_CPHA)) /*!<Clk goes high while nCS is released, the first data sampling is the second clock edge*/
/**
  * @}
  */
  
/** @defgroup ESMC_ChipSelectHighTime ESMC ChipSelect High Time
  * @{
  */
#define ESMC_CS_HIGH_TIME_1_CYCLE    ((uint32_t)                                                       ESMC_TCR_HIGH_0)  /*!<nCS stay high for at least 1 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_2_CYCLE    ((uint32_t)                                     ESMC_TCR_HIGH_1                   ) /*!<nCS stay high for at least 2 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_3_CYCLE    ((uint32_t)(                                    ESMC_TCR_HIGH_1 | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 3 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_4_CYCLE    ((uint32_t)(                  ESMC_TCR_HIGH_2                                    )) /*!<nCS stay high for at least 4 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_5_CYCLE    ((uint32_t)(                  ESMC_TCR_HIGH_2                   | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 5 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_6_CYCLE    ((uint32_t)(                  ESMC_TCR_HIGH_2 | ESMC_TCR_HIGH_1                  )) /*!<nCS stay high for at least 6 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_7_CYCLE    ((uint32_t)(                  ESMC_TCR_HIGH_2 | ESMC_TCR_HIGH_1 | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 7 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_8_CYCLE    ((uint32_t)(ESMC_TCR_HIGH_3                                                      )) /*!<nCS stay high for at least 8 clock cycle between commands*/
#define ESMC_CS_HIGH_TIME_9_CYCLE    ((uint32_t)(ESMC_TCR_HIGH_3                                     | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 9 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_10_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3                   | ESMC_TCR_HIGH_1                  )) /*!<nCS stay high for at least 10 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_11_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3                   | ESMC_TCR_HIGH_1 | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 11 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_12_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3 | ESMC_TCR_HIGH_2                                    )) /*!<nCS stay high for at least 12 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_13_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3 | ESMC_TCR_HIGH_2                   | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 13 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_14_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3 | ESMC_TCR_HIGH_2 | ESMC_TCR_HIGH_1                  )) /*!<nCS stay high for at least 14 clock cycles between commands*/
#define ESMC_CS_HIGH_TIME_15_CYCLE   ((uint32_t)(ESMC_TCR_HIGH_3 | ESMC_TCR_HIGH_2 | ESMC_TCR_HIGH_1 | ESMC_TCR_HIGH_0)) /*!<nCS stay high for at least 15 clock cycles between commands*/
/**
  * @}
  */
  
/** @defgroup ESMC_ChipSelectHoldTime ESMC ChipSelect Hold Time
  * @{
  */
#define ESMC_CS_HOLD_TIME_2_CYCLE    ((uint32_t)                                                       ESMC_TCR_HOLD_0)  /*!<nCS stay hold for at least 2 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_3_CYCLE    ((uint32_t)                                     ESMC_TCR_HOLD_1                   ) /*!<nCS stay hold for at least 3 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_4_CYCLE    ((uint32_t)(                                    ESMC_TCR_HOLD_1 | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 4 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_5_CYCLE    ((uint32_t)(                  ESMC_TCR_HOLD_2                                    )) /*!<nCS stay hold for at least 5 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_6_CYCLE    ((uint32_t)(                  ESMC_TCR_HOLD_2                   | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 6 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_7_CYCLE    ((uint32_t)(                  ESMC_TCR_HOLD_2 | ESMC_TCR_HOLD_1                  )) /*!<nCS stay hold for at least 7 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_8_CYCLE    ((uint32_t)(                  ESMC_TCR_HOLD_2 | ESMC_TCR_HOLD_1 | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 8 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_9_CYCLE    ((uint32_t)(ESMC_TCR_HOLD_3                                                      )) /*!<nCS stay hold for at least 9 clock cycle between commands*/
#define ESMC_CS_HOLD_TIME_10_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3                                     | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 10 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_11_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3                   | ESMC_TCR_HOLD_1                  )) /*!<nCS stay hold for at least 11 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_12_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3                   | ESMC_TCR_HOLD_1 | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 12 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_13_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3 | ESMC_TCR_HOLD_2                                    )) /*!<nCS stay hold for at least 13 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_14_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3 | ESMC_TCR_HOLD_2                   | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 14 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_15_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3 | ESMC_TCR_HOLD_2 | ESMC_TCR_HOLD_1                  )) /*!<nCS stay hold for at least 15 clock cycles between commands*/
#define ESMC_CS_HOLD_TIME_16_CYCLE   ((uint32_t)(ESMC_TCR_HOLD_3 | ESMC_TCR_HOLD_2 | ESMC_TCR_HOLD_1 | ESMC_TCR_HOLD_0)) /*!<nCS stay hold for at least 16 clock cycles between commands*/
/**
  * @}
  */

/** @defgroup ESMC_SampleShifting ESMC Sample Shifting
  * @{
  */
#define ESMC_SAMPLE_SHIFTING_NONE         (0x00000000U)                                                                                                           /*!<Sample Shifting none */
#define ESMC_SAMPLE_SHIFTING_1_CYCLE      ((uint32_t)(                                                                                          ESMC_STRR_SMP_0)) /*!<Sample Shifting 1 cycle*/
#define ESMC_SAMPLE_SHIFTING_2_CYCLE      ((uint32_t)(                                                                        ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 2 cycle*/
#define ESMC_SAMPLE_SHIFTING_3_CYCLE      ((uint32_t)(                                                                        ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 3 cycle*/
#define ESMC_SAMPLE_SHIFTING_4_CYCLE      ((uint32_t)(                                                      ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 4 cycle*/
#define ESMC_SAMPLE_SHIFTING_5_CYCLE      ((uint32_t)(                                                      ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 5 cycle*/
#define ESMC_SAMPLE_SHIFTING_6_CYCLE      ((uint32_t)(                                                      ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 6 cycle*/
#define ESMC_SAMPLE_SHIFTING_7_CYCLE      ((uint32_t)(                                                      ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 7 cycle*/
#define ESMC_SAMPLE_SHIFTING_8_CYCLE      ((uint32_t)(                                    ESMC_STRR_SMP_3                                                      )) /*!<Sample Shifting 8 cycle*/
#define ESMC_SAMPLE_SHIFTING_9_CYCLE      ((uint32_t)(                                    ESMC_STRR_SMP_3                                     | ESMC_STRR_SMP_0)) /*!<Sample Shifting 9 cycle*/
#define ESMC_SAMPLE_SHIFTING_10_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 10 cycle*/
#define ESMC_SAMPLE_SHIFTING_11_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 11 cycle*/
#define ESMC_SAMPLE_SHIFTING_12_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 12 cycle*/
#define ESMC_SAMPLE_SHIFTING_13_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 13 cycle*/
#define ESMC_SAMPLE_SHIFTING_14_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 14 cycle*/
#define ESMC_SAMPLE_SHIFTING_15_CYCLE     ((uint32_t)(                                    ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 15 cycle*/
#define ESMC_SAMPLE_SHIFTING_16_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                                                                        )) /*!<Sample Shifting 16 cycle*/
#define ESMC_SAMPLE_SHIFTING_17_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                                                       | ESMC_STRR_SMP_0)) /*!<Sample Shifting 17 cycle*/
#define ESMC_SAMPLE_SHIFTING_18_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                                     | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 18 cycle*/
#define ESMC_SAMPLE_SHIFTING_19_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                                     | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 19 cycle*/
#define ESMC_SAMPLE_SHIFTING_20_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 20 cycle*/
#define ESMC_SAMPLE_SHIFTING_21_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 21 cycle*/
#define ESMC_SAMPLE_SHIFTING_22_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 22 cycle*/
#define ESMC_SAMPLE_SHIFTING_23_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 23 cycle*/
#define ESMC_SAMPLE_SHIFTING_24_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                                                      )) /*!<Sample Shifting 24 cycle*/
#define ESMC_SAMPLE_SHIFTING_25_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                                     | ESMC_STRR_SMP_0)) /*!<Sample Shifting 25 cycle*/
#define ESMC_SAMPLE_SHIFTING_26_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 26 cycle*/
#define ESMC_SAMPLE_SHIFTING_27_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 27 cycle*/
#define ESMC_SAMPLE_SHIFTING_28_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 28 cycle*/
#define ESMC_SAMPLE_SHIFTING_29_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 29 cycle*/
#define ESMC_SAMPLE_SHIFTING_30_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 30 cycle*/
#define ESMC_SAMPLE_SHIFTING_31_CYCLE     ((uint32_t)(                  ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 31 cycle*/
#define ESMC_SAMPLE_SHIFTING_32_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                                                                          )) /*!<Sample Shifting 32 cycle*/
#define ESMC_SAMPLE_SHIFTING_33_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                                                         | ESMC_STRR_SMP_0)) /*!<Sample Shifting 33 cycle*/
#define ESMC_SAMPLE_SHIFTING_34_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                                       | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 34 cycle*/
#define ESMC_SAMPLE_SHIFTING_35_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                                       | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 35 cycle*/
#define ESMC_SAMPLE_SHIFTING_36_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                     | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 36 cycle*/
#define ESMC_SAMPLE_SHIFTING_37_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                     | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 37 cycle*/
#define ESMC_SAMPLE_SHIFTING_38_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                     | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 38 cycle*/
#define ESMC_SAMPLE_SHIFTING_39_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                                     | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 39 cycle*/
#define ESMC_SAMPLE_SHIFTING_40_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3                                                      )) /*!<Sample Shifting 40 cycle*/
#define ESMC_SAMPLE_SHIFTING_41_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3                                     | ESMC_STRR_SMP_0)) /*!<Sample Shifting 41 cycle*/
#define ESMC_SAMPLE_SHIFTING_42_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 42 cycle*/
#define ESMC_SAMPLE_SHIFTING_43_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 43 cycle*/
#define ESMC_SAMPLE_SHIFTING_44_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 44 cycle*/
#define ESMC_SAMPLE_SHIFTING_45_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 45 cycle*/
#define ESMC_SAMPLE_SHIFTING_46_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 46 cycle*/
#define ESMC_SAMPLE_SHIFTING_47_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5                   | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 47 cycle*/
#define ESMC_SAMPLE_SHIFTING_48_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                                                                        )) /*!<Sample Shifting 48 cycle*/
#define ESMC_SAMPLE_SHIFTING_49_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                                                       | ESMC_STRR_SMP_0)) /*!<Sample Shifting 49 cycle*/
#define ESMC_SAMPLE_SHIFTING_50_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                                     | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 50 cycle*/
#define ESMC_SAMPLE_SHIFTING_51_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                                     | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 51 cycle*/
#define ESMC_SAMPLE_SHIFTING_52_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 52 cycle*/
#define ESMC_SAMPLE_SHIFTING_53_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 53 cycle*/
#define ESMC_SAMPLE_SHIFTING_54_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 54 cycle*/
#define ESMC_SAMPLE_SHIFTING_55_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4                   | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 55 cycle*/
#define ESMC_SAMPLE_SHIFTING_56_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                                                      )) /*!<Sample Shifting 56 cycle*/
#define ESMC_SAMPLE_SHIFTING_57_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                                     | ESMC_STRR_SMP_0)) /*!<Sample Shifting 57 cycle*/
#define ESMC_SAMPLE_SHIFTING_58_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 58 cycle*/
#define ESMC_SAMPLE_SHIFTING_59_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3                   | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 59 cycle*/
#define ESMC_SAMPLE_SHIFTING_60_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                                    )) /*!<Sample Shifting 60 cycle*/
#define ESMC_SAMPLE_SHIFTING_61_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2                   | ESMC_STRR_SMP_0)) /*!<Sample Shifting 61 cycle*/
#define ESMC_SAMPLE_SHIFTING_62_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1                  )) /*!<Sample Shifting 62 cycle*/
#define ESMC_SAMPLE_SHIFTING_63_CYCLE     ((uint32_t)(ESMC_STRR_SMP_5 | ESMC_STRR_SMP_4 | ESMC_STRR_SMP_3 | ESMC_STRR_SMP_2 | ESMC_STRR_SMP_1 | ESMC_STRR_SMP_0)) /*!<Sample Shifting 63 cycle*/
/**
  * @}
  */
  
/** @defgroup ESMC_TransferFormat ESMC Transfer Format
  * @{
  */
#define ESMC_TRANSFER_FORMAT_SINGLE         ((uint32_t)0x00000000U)                                    /*!<Transfer on a single line*/
#define ESMC_TRANSFER_FORMAT_DUAL           ((uint32_t)(ESMC_SOCR_SPIMODE_0))                          /*!<Transfer on two lines*/
#define ESMC_TRANSFER_FORMAT_QUAD           ((uint32_t)(ESMC_SOCR_SPIMODE_1))                          /*!<Transfer on four lines*/
#define ESMC_TRANSFER_FORMAT_OCTAL          ((uint32_t)(ESMC_SOCR_SPIMODE_0 | ESMC_SOCR_SPIMODE_1))    /*!<Transfer on eight lines*/
/**
  * @}
  */

/** @defgroup ESMC_InstructionMode ESMC Instruction Mode
* @{
*/
#define ESMC_INSTRUCTION_NONE          ((uint32_t)0x00U)    /*!<No instruction*/
#define ESMC_INSTRUCTION_SINGLE_LINE   ((uint32_t)0x01U)    /*!<Instruction on a single line*/
#define ESMC_INSTRUCTION_MULTI_LINES   ((uint32_t)0x02U)    /*!<Instruction on multi lines*/
/**
  * @}
  */

/** @defgroup ESMC_InstructionLength ESMC Instruction Length
* @{
*/
#define ESMC_INSTRCUTION_LEN_1_BYTE    ((uint32_t)0x00U)    /*!<Instruction 1 byte*/
#define ESMC_INSTRCUTION_LEN_2_BYTE    ((uint32_t)0x01U)    /*!<Instruction 2 bytes*/
/**
  * @}
  */

/** @defgroup ESMC_AddressMode ESMC Address Mode
* @{
*/
#define ESMC_ADDRESS_NONE              ((uint32_t)0x00U)    /*!<No address*/
#define ESMC_ADDRESS_SINGLE_LINE       ((uint32_t)0x01U)    /*!<Address on a single line*/
#define ESMC_ADDRESS_MULTI_LINES       ((uint32_t)0x02U)    /*!<Address on multi lines*/
/**
  * @}
  */

/** @defgroup ESMC_AddressSize ESMC Address Size
  * @{
  */
#define ESMC_ADDRESS_8_BITS            ((uint32_t)ESMC_CR3_ADDR8BIT)    /*!<8-bit address*/
#define ESMC_ADDRESS_16_BITS           ((uint32_t)ESMC_CR3_ADDR16BIT)   /*!<16-bit address*/
#define ESMC_ADDRESS_24_BITS           ((uint32_t)0x00)                 /*!<24-bit address*/
#define ESMC_ADDRESS_32_BITS           ((uint32_t)ESMC_CR3_ADDR32BIT)   /*!<32-bit address*/
/**
  * @}
  */

/** @defgroup ESMC_DataMode ESMC data mode
  * @{
  */
#define ESMC_DATA_NONE                 ((uint32_t)0x00U)   /*!<No data*/
#define ESMC_DATA_WRITE                ((uint32_t)0x01U)   /*!<data write mode*/
#define ESMC_DATA_READ                 ((uint32_t)0x02U)   /*!<data read mode*/
/**
  * @}
  */

/** @defgroup ESMC_AlternateBytesMode ESMC Alternate Bytes Mode
* @{
*/
#define ESMC_ALTERNATE_BYTES_DISABLE   0x00000000U                      /*!<No send alternate bytes*/
#define ESMC_ALTERNATE_BYTES_ENABLE    ((uint32_t)ESMC_SOCR_SENM)       /*!<Send alternate bytes after ADDR*/
/**
  * @}
  */

/** @defgroup ESMC_DualFlash_Mode  ESMC Dual Flash Mode
* @{
*/
#define ESMC_DUALFLASH_ENABLE         ((uint32_t)ESMC_CR_2QSPI)
#define ESMC_DUALFLASH_DISABLE        ((uint32_t)0x00000000U)
/**
  * @}
  */

/** @defgroup ESMC_XSPI_DualLatency  ESMC XSPI DualLatency
* @{
*/
#define ESMC_XSPI_DUALLATENCY_DISABLE       ((uint32_t)0x00000000)
#define ESMC_XSPI_DUALLATENCY_ENABLE        ((uint32_t)0x00000001)
/**
  * @}
  */

/** @defgroup ESMC_CS_PIN_SEL  ESMC CS pin select
* @{
*/
#define ESMC_SELECT_PIN_CS0         ((uint32_t)0x00000001U)      /*!<CS0 select*/
#define ESMC_SELECT_PIN_CS1         ((uint32_t)0x00000002U)      /*!<CS1 select*/
#define ESMC_SELECT_PIN_CS2         ((uint32_t)0x00000004U)      /*!<CS2 select*/
#define ESMC_SELECT_PIN_CS3         ((uint32_t)0x00000008U)      /*!<CS3 select*/
#define ESMC_SELECT_PIN_CS4         ((uint32_t)0x00000010U)      /*!<CS4 select*/
#define ESMC_SELECT_PIN_CS5         ((uint32_t)0x00000020U)      /*!<CS5 select*/
/**
  * @}
  */

/** @defgroup ESMC_DdrMode ESMC Ddr Mode
  * @{
  */
#define ESMC_DDR_DISABLE              ((uint32_t)0x00000000U)                                      /*!<Double data rate mode disabled */
#define ESMC_DDR_DATA                 ((uint32_t)(ESMC_SOCR_DDRDATA))                                          /*!<Double data rate mode enabled on data*/
#define ESMC_DDR_ADDR_DATA            ((uint32_t)(ESMC_SOCR_DDRADDR | ESMC_SOCR_DDRDATA))                      /*!<Double data rate mode enabled on address and data */
#define ESMC_DDR_CMD_ADDR_DATA        ((uint32_t)(ESMC_SOCR_DDRCMD  | ESMC_SOCR_DDRADDR | ESMC_SOCR_DDRDATA))  /*!<Double data rate mode enabled on command and address and data */
/**
  * @}
  */

/** @defgroup ESMC_Flags ESMC Flags
  * @{
  */
#define ESMC_FLAG_SSACTIVE             (0xf0000000 | ESMC_SR_SSACTIVE)     /*!<SS outputs Active flag: any of the SS outputs is active (low)*/
#define ESMC_FLAG_RXBUSY               (0xf0000000 | ESMC_SR_RXBUSY)       /*!<RX In progress flag: ESMC is busy with the data reception from Flash*/
#define ESMC_FLAG_TXBUSY               (0xf0000000 | ESMC_SR_TXBUSY)       /*!<TX In progress flag: ESMC is busy with memory write operations*/
#define ESMC_FLAG_XIPBUSY              (0xf0000000 | ESMC_SR_XIPBUSY)      /*!<ESMC is busy in XIP state*/
#define ESMC_FLAG_IDLE                 (0xf0000000 | ESMC_SR_IDLE_STATE)   /*!<FIFO is in idle state*/
#define ESMC_FLAG_TXFIFOOV             (0xf0000000 | ESMC_SR_TXFIFOV)      /*!<TX Fifo overflow flag*/
#define ESMC_FLAG_DATAWAIT             (0xf0000000 | ESMC_SR_DATAWAIT)     /*!<ESMC is in wait state*/
#define ESMC_FLAG_SPIF                 (0xf0000000 | ESMC_SR_SPIF)         /*!<Interrupt request flag: There is at least one interrupt request pending*/

#define ESMC_FLAG_CMDIF                (ESMC_IFR1_CMDIF)                   /*!<CMD flag: COMMAND Done*/
#define ESMC_FLAG_RXFIFONEIF           (ESMC_IFR1_RXFIFOEIF )              /*!<FIFO Not Empty flag: FIFO is not Empty*/
#define ESMC_FLAG_RXFIFOHIF            (ESMC_IFR1_RXFIFOHFIF)              /*!<FIFO HALF Full flag: FIFO memory is half filled*/
#define ESMC_FLAG_RXFIFOFIF            (ESMC_IFR1_RXFIFOFIF)               /*!<FIFO Full flag: There is no free space in the FIFO Memory*/
#define ESMC_FLAG_IDLEDONEIF           (ESMC_IFR1_IDLEDONEIF)              /*!<IDLE flag: ESMC completed operation and went to IDLE state*/
#define ESMC_FLAG_DATAWAITIF           (ESMC_IFR1_DATAWAITIF)              /*!<DATA WAIT flag: In write operations FIFO is empty, or In read operations FIFO is full*/
#define ESMC_FLAG_RXFIFOWIF            (ESMC_IFR1_RXFIFOWIF)               /*!<FIFO OVER WORD Flag: Fifo is more than one word*/
#define ESMC_FLAG_ADDRDONEIF           (ESMC_IFR1_ADDRDONEIF)              /*!<ADDRESS Done flag: the Address field has been sent out*/

#define ESMC_FLAG_XIPRDINSTRSETIF      (ESMC_IFR2_XIPRDInstrSetIF << 16)   /*!< XIP Busy in read*/
#define ESMC_FLAG_TXFIFOEIF            (ESMC_IFR2_TXFIFOEIF << 16)         /*!< TX FIFO EMPTY*/
#define ESMC_FLAG_TXFIFOHEIF           (ESMC_IFR2_TXFIFOHEIF << 16)        /*!< TX FIFO HALF EMPTY FLAG*/
#define ESMC_FLAG_TXFIFOFIF            (ESMC_IFR2_TXIFOFIF << 16)          /*!< TX FIFO FULL FLAG*/
#define ESMC_FLAG_TXFIFOOVIF           (ESMC_IFR2_TXFIFOOVIF << 16)        /*!< TX FIFO OVERFLOW FLAG*/
#define ESMC_FLAG_TXWORDOVIF           (ESMC_IFR2_TXWORDOVIF << 16)        /*!< TX not Word Alignt*/
#define ESMC_FLAG_XIPWEINSTRSETIF      (ESMC_IFR2_XIPWEINSTRSETIF << 16)   /*!< XIP Busy in write*/
#define ESMC_FLAG_RXTIMEOUTOF          (ESMC_IFR2_RXTOUTIF << 16)          /*!< RX Timeout*/


#define ESMC_FLAG_XSPI_DUALLATENCY     (ESMC_SR1_XSPI_DUAL_LATENCY)        /*!<Xspi Dual Latency*/
#define ESMC_FLAG_RWDSI_ND             (ESMC_SR1_RWDSI_ND)                 /*!<No RWDSI Clock*/

/**
  * @}
  */

/** @defgroup ESMC_Interrupts EMSC Interrupts
  * @{
  */
#define ESMC_IT_CMD                    (ESMC_IER1_CMDIE)         /*!<Interrupt on the command done*/
#define ESMC_IT_RXFIFONE               (ESMC_IER1_RXFIFONEIE)    /*!<Interrupt on the rx fifo not empty*/
#define ESMC_IT_RXFIFOHF               (ESMC_IER1_RXFIFOHFIE)    /*!<Interrupt on the rx fifo half full flag*/
#define ESMC_IT_RXFIFOF                (ESMC_IER1_RXFIFOFIE)     /*!<Interrupt on the rx fifo full flag*/
#define ESMC_IT_IDLEDONE               (ESMC_IER1_IDLEDONEIE)    /*!<Interrupt on the idle flag*/
#define ESMC_IT_DATAWAIT               (ESMC_IER1_DATAWAITIE)    /*!<Interrupt on the data wait flag*/
#define ESMC_IT_RXFIFOW                (ESMC_IER1_RXFIFOWIE)     /*!<Interrupt on the rx fifo overflow flag*/
#define ESMC_IT_ADDRDONE               (ESMC_IER1_ADDRDONEIE)    /*!<Interrupt on the address done flag*/

#define ESMC_IT_TXFIFOE                (ESMC_IER2_TXFIFOEIE<<16)    /*!<Interrupt on the tx fifo empty flag*/
#define ESMC_IT_TXFIFOHE               (ESMC_IER2_TXFIFOHEIE<<16)   /*!<Interrupt on the tx fifo half empty flag*/
#define ESMC_IT_TXFIFOF                (ESMC_IER2_TXFIFOFIE<<16)    /*!<Interrupt on the tx fifo full flag*/
#define ESMC_IT_TXFIFOOVE              (ESMC_IER2_TXFIFOOVIE<<16)   /*!<Interrupt on the tx fifo overflow flag*/
#define ESMC_IT_TXWORDOVE              (ESMC_IER2_TXWORDOVIE<<16)   /*!<Interrupt on the tx fifo word overflow flag*/

#define ESMC_IT_ALL                    (ESMC_IT_CMD  | ESMC_IT_RXFIFONE | ESMC_IT_RXFIFOHF | ESMC_IT_RXFIFOF | \
                                        ESMC_IT_IDLEDONE | ESMC_IT_DATAWAIT | ESMC_IT_RXFIFOW | ESMC_IT_ADDRDONE | \
                                        ESMC_IT_TXFIFOE | ESMC_IT_TXFIFOHE | ESMC_IT_TXFIFOF | ESMC_IT_TXFIFOOVE | ESMC_IT_TXWORDOVE)
/**
  * @}
  */

/** @defgroup ESMC_Timeout_definition ESMC Timeout definition
  * @{
  */
#define HAL_ESMC_TIMEOUT_DEFAULT_VALUE ((uint32_t)5000)/* 5 s */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup ESMC_Exported_Macros ESMC Exported Macros
  * @{
  */

/** @brief Reset ESMC handle state
  * @param  __HANDLE__ ESMC handle.
  * @retval None
  */
#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
#define __HAL_ESMC_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                                  (__HANDLE__)->State = HAL_ESMC_STATE_RESET; \
                                                                  (__HANDLE__)->MspInitCallback = NULL;       \
                                                                  (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                               } while(0)
#else
#define __HAL_ESMC_RESET_HANDLE_STATE(__HANDLE__)           ((__HANDLE__)->State = HAL_ESMC_STATE_RESET)
#endif

/** @brief  Enable ESMC
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_ENABLE(__HANDLE__)                       SET_BIT((__HANDLE__)->Instance->CR, ESMC_CR_SPIEN)

/** @brief  Disable ESMC
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_DISABLE(__HANDLE__)                      CLEAR_BIT((__HANDLE__)->Instance->CR, ESMC_CR_SPIEN)

/** @brief  Enable ESMC Global interrupt
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_ENABLE_GLOBAL_IT(__HANDLE__)             SET_BIT((__HANDLE__)->Instance->CR, ESMC_CR_GIE)

/** @brief  Disable ESMC Global interrupt
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_DISABLE_GLOBAL_IT(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->CR, ESMC_CR_GIE)

/** @brief  Soft reset ESMC
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_SOFT_RESET(__HANDLE__)                   SET_BIT((__HANDLE__)->Instance->CR, ESMC_CR_SOFTRST)

/** @brief  Enables the specified ESMC interrupt.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __INTERRUPT__ specifies the ESMC interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg ESMC_IT_CMD        : ESMC Command Done interrupt
  *            @arg ESMC_IT_RXFIFONE   : ESMC FIFO not empty interrupt
  *            @arg ESMC_IT_RXFIFOHF   : ESMC FIFO half full interrupt
  *            @arg ESMC_IT_RXFIFOF    : ESMC FIFO full interrupt
  *            @arg ESMC_IT_IDLEDONE   : ESMC Idle interrupt
  *            @arg ESMC_IT_DATAWAIT   : ESMC Datawait interrupt
  *            @arg ESMC_IT_RXFIFOW    : ESMC FIFO OverFlow interrupt
  *            @arg ESMC_IT_ADDRDONE   : ESMC Address Done interrupt
  *            @arg ESMC_IT_TXFIFOE    : ESMC TX FIFO empty interrupt
  *            @arg ESMC_IT_TXFIFOHE   : ESMC TX FIFO half empty interrupt
  *            @arg ESMC_IT_TXFIFOF    : ESMC TX FIFO full  interrupt
  *            @arg ESMC_IT_TXFIFOOVE  : ESMC TX FIFO OverFlow interrupt
  *            @arg ESMC_IT_TXWORDOVE  : ESMC TX FIFO unaligned data
  * @retval None
  */
#define __HAL_ESMC_ENABLE_IT(__HANDLE__, __INTERRUPT__)    SET_BIT(*(__IO uint32_t *)(&((__HANDLE__)->Instance->IER1)), (__INTERRUPT__))

/** @brief  Disables the specified ESMC interrupt.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __INTERRUPT__ specifies the ESMC interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg ESMC_IT_CMD        : ESMC Command Done interrupt
  *            @arg ESMC_IT_RXFIFONE   : ESMC FIFO not empty interrupt
  *            @arg ESMC_IT_RXFIFOHF   : ESMC FIFO half full interrupt
  *            @arg ESMC_IT_RXFIFOF    : ESMC FIFO full interrupt
  *            @arg ESMC_IT_IDLEDONE   : ESMC Idle interrupt
  *            @arg ESMC_IT_DATAWAIT   : ESMC Datawait interrupt
  *            @arg ESMC_IT_RXFIFOW    : ESMC FIFO OverFlow interrupt
  *            @arg ESMC_IT_ADDRDONE   : ESMC Address Done interrupt
  *            @arg ESMC_IT_TXFIFOE    : ESMC TX FIFO empty interrupt
  *            @arg ESMC_IT_TXFIFOHE   : ESMC TX FIFO half empty interrupt
  *            @arg ESMC_IT_TXFIFOF    : ESMC TX FIFO full  interrupt
  *            @arg ESMC_IT_TXFIFOOVE  : ESMC TX FIFO OverFlow interrupt
  *            @arg ESMC_IT_TXWORDOVE  : ESMC TX FIFO unaligned data
  * @retval None
  */
#define __HAL_ESMC_DISABLE_IT(__HANDLE__, __INTERRUPT__)     CLEAR_BIT(*(__IO uint32_t *)(&((__HANDLE__)->Instance->IER1)), (__INTERRUPT__))

/** @brief  Checks whether the specified ESMC interrupt source is enabled.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __INTERRUPT__ specifies the ESMC interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg ESMC_IT_CMD        : ESMC Command Done interrupt
  *            @arg ESMC_IT_RXFIFONE   : ESMC FIFO not empty interrupt
  *            @arg ESMC_IT_RXFIFOHF   : ESMC FIFO half full interrupt
  *            @arg ESMC_IT_RXFIFOF    : ESMC FIFO full interrupt
  *            @arg ESMC_IT_IDLEDONE   : ESMC Idle interrupt
  *            @arg ESMC_IT_DATAWAIT   : ESMC Datawait interrupt
  *            @arg ESMC_IT_RXFIFOW    : ESMC FIFO OverFlow interrupt
  *            @arg ESMC_IT_ADDRDONE   : ESMC Address Done interrupt
  *            @arg ESMC_IT_TXFIFOE    : ESMC TX FIFO Empty interrupt
  *            @arg ESMC_IT_TXFIFOHE   : ESMC TX FIFO Half Empty interrupt
  *            @arg ESMC_IT_TXFIFOF    : ESMC TX FIFO Full interrupt
  *            @arg ESMC_IT_TXFIFOOVE  : ESMC TX FIFO OverFlow interrupt
  *            @arg ESMC_IT_TXWORDOVE  : ESMC TX WORD Over interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_ESMC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (READ_BIT(*(__IO uint32_t *)(&((__HANDLE__)->Instance->IER1)), (__INTERRUPT__)) == (__INTERRUPT__))

/**
  * @brief  Get the selected ESMC's flag status.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __FLAG__ specifies the ESMC flag to check.
  *          This parameter can be one of the following values:
  *            @arg ESMC_FLAG_SSACTIVE         : SS output acive flag
  *            @arg ESMC_FLAG_RXBUSY           : RX in progeess flag
  *            @arg ESMC_FLAG_TXBUSY           : TX in progress flag
  *            @arg ESMC_FLAG_XIPBUSY          : ESMC is busy in XIP state
  *            @arg ESMC_FLAG_IDLE             : FIFO is in idle state
  *            @arg ESMC_FLAG_TXFIFOOV         : TX Fifo overflow flag
  *            @arg ESMC_FLAG_DATAWAIT         : ESMC is in wait state
  *            @arg ESMC_FLAG_SPIF             : Interrupt request flag
  *            @arg ESMC_FLAG_CMDIF            : CMD done flag
  *            @arg ESMC_FLAG_RXFIFONEIF       : RX FIFO Not Empty flag
  *            @arg ESMC_FLAG_RXFIFOHIF        : RX FIFO HALF Full flag
  *            @arg ESMC_FLAG_RXFIFOFIF        : RX FIFO Full flag
  *            @arg ESMC_FLAG_IDLEDONEIF       : ESMC is in IDLE state
  *            @arg ESMC_FLAG_DATAWAITIF       : DATA WAIT flag
  *            @arg ESMC_FLAG_RXFIFOWIF        : FIFO OVER WORD Flag
  *            @arg ESMC_FLAG_ADDRDONEIF       : ADDRESS Done flag
  *            @arg ESMC_FLAG_XIPRDINSTRSETIF  : XIP Busy
  *            @arg ESMC_FLAG_TXFIFOEIF        : TX FIFO EMPTY
  *            @arg ESMC_FLAG_TXFIFOHEIF       : TX FIFO HALF EMPTY FLAG
  *            @arg ESMC_FLAG_TXFIFOFIF        : TX FIFO FULL FLAG
  *            @arg ESMC_FLAG_TXFIFOOVIF       : TX FIFO OVERFLOW FLAG
  *            @arg ESMC_FLAG_TXWORDOVIF       : TX not Word Alignt
  *            @arg ESMC_FLAG_XIPWEINSTRSETIF  : XIP Busy in write
  *            @arg ESMC_FLAG_RXTIMEOUTOF      : RX Timeout flag
  * @retval None
  */
#define __HAL_ESMC_GET_FLAG(__HANDLE__, __FLAG__) (((__FLAG__&0xF0000000U) == 0xF0000000U) ? \
                  ((((__HANDLE__)->Instance->SR & (__FLAG__&0x0FFFFFFF)) == ((__FLAG__)&0x0FFFFFFF )) ? SET : RESET) : \
                  ((((*(__IO uint32_t *)(&(__HANDLE__)->Instance->IFR1)) & __FLAG__) == __FLAG__ ) ? SET : RESET))

/** @brief  Clears the specified ESMC's flag status.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __FLAG__ specifies the ESMC clear register flag that needs to be set
  *          This parameter can be one of the following values:
  *            @arg ESMC_FLAG_CMDIF         : COMMAND Done flag
  *            @arg ESMC_FLAG_ADDRDONEIF    : ADDRESS Done flag
  * @retval None
  */
#define __HAL_ESMC_CLEAR_FLAG(__HANDLE__, __FLAG__)    (__HANDLE__)->Instance->IFR1 = (__FLAG__)

/** @brief  configure which slave select output should be driven during no xip mode.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @param  __SSX__ specifies the CS pin
  *          The parameter can take the following values:
  *            @arg ESMC_SELECT_PIN_CS0
  *            @arg ESMC_SELECT_PIN_CS1
  *            @arg ESMC_SELECT_PIN_CS2
  *            @arg ESMC_SELECT_PIN_CS3
  *            @arg ESMC_SELECT_PIN_CS4
  *            @arg ESMC_SELECT_PIN_CS5
  * @retval None
  */
#define __HAL_ESMC_SET_SSXO(__HANDLE__, __SSX__)             SET_BIT((__HANDLE__)->Instance->ADDR32, (__SSX__)<<ESMC_ADDR32_SSXO_Pos)


/** @brief  Clear TX and RX Fifo
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_CLEAR_FIFO(__HANDLE__)                    SET_BIT((__HANDLE__)->Instance->CR2, ESMC_CR2_TXFIFO_CLR | ESMC_CR2_RXFIFO_CLR)

/** @brief  Enable the slave select.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_ENABLE_SLAVE(__HANDLE__)                  SET_BIT((__HANDLE__)->Instance->ADDR32, ESMC_ADDR32_SS_SET)

/** @brief  Disable the slave select.
  * @param  __HANDLE__ specifies the ESMC Handle.
  * @retval None
  */
#define __HAL_ESMC_DISABLE_SLAVE(__HANDLE__)                 SET_BIT((__HANDLE__)->Instance->ADDR32, ESMC_ADDR32_SS_CLR)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ESMC_Exported_Functions
  * @{
  */

/** @addtogroup ESMC_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  ********************************/
HAL_StatusTypeDef     HAL_ESMC_Init     (ESMC_HandleTypeDef *hesmc);
HAL_StatusTypeDef     HAL_ESMC_DeInit   (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_MspInit  (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_MspDeInit(ESMC_HandleTypeDef *hesmc);
/**
  * @}
  */

/** @addtogroup ESMC_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
/* ESMC IRQ handler method */
void                  HAL_ESMC_IRQHandler(ESMC_HandleTypeDef *hesmc);

/* ESMC indirect mode */
HAL_StatusTypeDef     HAL_ESMC_Command      (ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd, uint32_t Timeout);
HAL_StatusTypeDef     HAL_ESMC_Transmit     (ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_ESMC_TransmitFIFO (ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_ESMC_Receive      (ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_ESMC_ReceiveFIFO  (ESMC_HandleTypeDef *hesmc, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_ESMC_Command_IT   (ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd);
HAL_StatusTypeDef     HAL_ESMC_Transmit_IT  (ESMC_HandleTypeDef *hesmc, uint8_t *pData);
HAL_StatusTypeDef     HAL_ESMC_Receive_IT   (ESMC_HandleTypeDef *hesmc, uint8_t *pData);
HAL_StatusTypeDef     HAL_ESMC_Transmit_DMA (ESMC_HandleTypeDef *hesmc, uint8_t *pData);
HAL_StatusTypeDef     HAL_ESMC_Receive_DMA  (ESMC_HandleTypeDef *hesmc, uint8_t *pData);
HAL_StatusTypeDef     HAL_ESMC_Write_32b    (ESMC_HandleTypeDef *hesmc, uint32_t *pAddress, uint32_t *pSrcBuffer,uint32_t BufferSize);
HAL_StatusTypeDef     HAL_ESMC_Write_16b    (ESMC_HandleTypeDef *hesmc, uint16_t *pAddress, uint16_t *pSrcBuffer,uint32_t BufferSize);
HAL_StatusTypeDef     HAL_ESMC_Write_8b     (ESMC_HandleTypeDef *hesmc, uint8_t *pAddress,  uint8_t *pSrcBuffer ,uint32_t BufferSize);
/* QSPI memory-mapped mode */
HAL_StatusTypeDef HAL_ESMC_MemoryMapped(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd);
HAL_StatusTypeDef HAL_ESMC_MemoryWrite(ESMC_HandleTypeDef *hesmc, ESMC_CommandTypeDef *cmd);

/* Callback functions in non-blocking modes ***********************************/
void                  HAL_ESMC_ErrorCallback        (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_AbortCpltCallback    (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_SetSSxO(ESMC_HandleTypeDef *hesmc, uint32_t SSxO);

/* ESMC indirect mode */
void                  HAL_ESMC_CmdCpltCallback      (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_RxCpltCallback       (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_TxCpltCallback       (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_RxHalfBlockCpltCallback   (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_TxHalfBlockCpltCallback   (ESMC_HandleTypeDef *hesmc);

#if (USE_HAL_ESMC_REGISTER_CALLBACKS == 1)
/* ESMC callback registering/unregistering */
HAL_StatusTypeDef     HAL_ESMC_RegisterCallback     (ESMC_HandleTypeDef *hesmc, HAL_ESMC_CallbackIDTypeDef CallbackId, pESMC_CallbackTypeDef pCallback);
HAL_StatusTypeDef     HAL_ESMC_UnRegisterCallback   (ESMC_HandleTypeDef *hesmc, HAL_ESMC_CallbackIDTypeDef CallbackId);
#endif
/**
  * @}
  */

/** @addtogroup ESMC_Exported_Functions_Group3
  * @{
  */
/* Peripheral Control and State functions  ************************************/
HAL_ESMC_StateTypeDef HAL_ESMC_GetState        (ESMC_HandleTypeDef *hesmc);
uint32_t              HAL_ESMC_GetError        (ESMC_HandleTypeDef *hesmc);
HAL_StatusTypeDef     HAL_ESMC_Abort           (ESMC_HandleTypeDef *hesmc);
HAL_StatusTypeDef     HAL_ESMC_Abort_IT        (ESMC_HandleTypeDef *hesmc);
void                  HAL_ESMC_SetTimeout      (ESMC_HandleTypeDef *hesmc, uint32_t Timeout);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ESMC_Private_Macros ESMC Private Macros
  * @{
  */

#define IS_ESMC_CLOCK_PRESCALER(PRESCALER)  ((PRESCALER) <= 0xFF && (PRESCALER) >= 0x2)


#define IS_ESMC_CLOCK_MODE(CLKMODE)         (((CLKMODE) == ESMC_CLOCK_MODE_0) || \
                                             ((CLKMODE) == ESMC_CLOCK_MODE_3))


#define IS_ESMC_DUAL_FLASH_MODE(MODE)    (((MODE) == ESMC_DUALFLASH_ENABLE) || \
                                          ((MODE) == ESMC_DUALFLASH_DISABLE))

#define IS_ESMC_CS_HIGH_TIME(TIME)          (((TIME) == ESMC_CS_HIGH_TIME_1_CYCLE) || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_2_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_3_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_4_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_5_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_6_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_7_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_8_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_9_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_10_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_11_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_12_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_13_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_14_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HIGH_TIME_15_CYCLE))


#define IS_ESMC_CS_HOLD_TIME(TIME)          (((TIME) == ESMC_CS_HOLD_TIME_2_CYCLE) || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_3_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_4_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_5_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_6_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_7_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_8_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_9_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_10_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_11_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_12_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_13_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_14_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_15_CYCLE)  || \
                                             ((TIME) == ESMC_CS_HOLD_TIME_16_CYCLE))


#define IS_ESMC_INSTRUCTION(INSTRUCTION)    ((INSTRUCTION) <= 0xFFFF)

#define IS_ESMC_INSTRUCTION_LENGTH(LENGTH)   (((LENGTH) == ESMC_INSTRCUTION_LEN_1_BYTE)|| \
                                             ((LENGTH) == ESMC_INSTRCUTION_LEN_2_BYTE))

#define IS_ESMC_ADDRESS_SIZE(ADDR_SIZE)     (((ADDR_SIZE) == ESMC_ADDRESS_8_BITS)  || \
                                             ((ADDR_SIZE) == ESMC_ADDRESS_16_BITS) || \
                                             ((ADDR_SIZE) == ESMC_ADDRESS_24_BITS) || \
                                             ((ADDR_SIZE) == ESMC_ADDRESS_32_BITS))

#define IS_ESMC_DUMMY_CYCLES(DCY)           ((DCY) <= 63)

#define IS_ESMC_INSTRUCTION_MODE(MODE)      (((MODE) == ESMC_INSTRUCTION_NONE)         || \
                                             ((MODE) == ESMC_INSTRUCTION_SINGLE_LINE)  || \
                                             ((MODE) == ESMC_INSTRUCTION_MULTI_LINES))

#define IS_ESMC_ADDRESS_MODE(MODE)          (((MODE) == ESMC_ADDRESS_NONE)         || \
                                             ((MODE) == ESMC_ADDRESS_SINGLE_LINE)  || \
                                             ((MODE) == ESMC_ADDRESS_MULTI_LINES))

#define IS_ESMC_ALTERNATE_BYTES_MODE(MODE)  (((MODE) == ESMC_ALTERNATE_BYTES_DISABLE) || \
                                             ((MODE) == ESMC_ALTERNATE_BYTES_ENABLE))

#define IS_ESMC_ALTERNATE_BYTE(ALT)         ((ALT) <= 0xFF)

#define IS_ESMC_DATA_MODE(MODE)             (((MODE) == ESMC_DATA_NONE)    || \
                                             ((MODE) == ESMC_DATA_WRITE)   || \
                                             ((MODE) == ESMC_DATA_READ))

#define IS_ESMC_DDR_MODE(DDR_MODE)          (((DDR_MODE) == ESMC_DDR_DISABLE)    || \
                                             ((DDR_MODE) == ESMC_DDR_DATA)       || \
                                             ((DDR_MODE) == ESMC_DDR_ADDR_DATA)  || \
                                             ((DDR_MODE) == ESMC_DDR_CMD_ADDR_DATA))

#define IS_ESMC_DQS_MODE(MODE)              (((MODE) == ESMC_DQS_ENABLE) || \
                                             ((MODE) == ESMC_DQS_DISABLE))

#define IS_ESMC_SAMPLESHIFTING(SAMPLESHIFTING)    ((SAMPLESHIFTING) <= ESMC_SAMPLE_SHIFTING_63_CYCLE)

#define IS_ESMC_XSPI_DUALLATENCY(DUALLATENCY)    (((DUALLATENCY) == ESMC_XSPI_DUALLATENCY_ENABLE) || \
                                                  ((DUALLATENCY) == ESMC_XSPI_DUALLATENCY_DISABLE))
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup ESMC_Private_Functions ESMC Private Functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */
  
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_HAL_ESMC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
