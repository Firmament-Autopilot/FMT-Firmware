/**
  ******************************************************************************
  * @file    py32e407_hal_lcdc.h
  * @author  MCU Application Team
  * @brief   Header file of LCDC HAL module.
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
#ifndef __PY32E407_HAL_LCDC_H
#define __PY32E407_HAL_LCDC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup LCDC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup LCDC_Exported_Types LCDC Exported Types
  * @{
  */

/**
  * @brief  LCDC Timing Structure definition
  */
typedef struct
{
  uint32_t AddSet;              /*!< Specifies that the duration of the address setup phase is (addset + 1) pclks.
                                     This parameter can be a number between Min_Data = 0 and Max_Data = 15 */
                               
  uint32_t DataSt;              /*!< Specifies that the duration of data-phase is (DataSt + 1) pclks.
                                     This parameter can be a number between Min_Data = 0 and Max_Data = 255 */
                               
  uint32_t DataHold;            /*!< Specifies that the duration of data hold phase is (DataHold + 2) pclks.
                                     This parameter can be a number between Min_Data = 0 and Max_Data = 3 */

} LCDC_TimingTypeDef;

/**
  * @brief  LCDC Configuration Structure definition
  */
typedef struct
{
  uint32_t Mode;                /*!< Specifies the LCDC interface mode.
                                     This parameter can be a value of @ref LCDC_Mode */

  LCDC_TimingTypeDef Write;     /*!< Specifies the LCDC write access timing.*/

  LCDC_TimingTypeDef Read;      /*!< Specifies the LCDC read access timing.*/

  uint32_t DataSize;            /*!< Specifies the LCDC data size.
                                     This parameter can be a value of @ref LCDC_Data_Size */

  uint32_t CmdSize;             /*!< Specifies the LCDC cmd size.
                                     This parameter can be a value of @ref LCDC_Cmd_Size */
} LCDC_InitTypeDef;

/**
  * @brief  HAL LCDC State structure definition
  */
typedef enum
{
  HAL_LCDC_STATE_RESET             = 0x00U,    /*!< Peripheral not Initialized               */
  HAL_LCDC_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use */
  HAL_LCDC_STATE_BUSY              = 0x02U,    /*!< an internal process is ongoing           */
  HAL_LCDC_STATE_BUSY_WRITE_DATA   = 0x03U,    /*!< Data Wirte process is ongoing            */
  HAL_LCDC_STATE_BUSY_READ_DATA    = 0x04U,    /*!< Data Read process is ongoing             */
  HAL_LCDC_STATE_BUSY_WRITE_CMD    = 0x05U,    /*!< Cmd Wirte process is ongoing             */
  HAL_LCDC_STATE_BUSY_READ_CMD     = 0x06U,    /*!< Cmd Read process is ongoing              */
} HAL_LCDC_StateTypeDef;

/**
  * @brief  LCDC handle Structure definition
  */
typedef struct __LCDC_HandleTypeDef
{
  LCDC_TypeDef                *Instance;      /*!< LCDC registers base address              */

  LCDC_InitTypeDef            Init;           /*!< LCDC initialize parameters               */

  uint8_t                     *pBuffPtr;      /*!< Pointer to LCDC Tx transfer Buffer       */

  uint32_t                    XferSize;       /*!< LCDC Transfer size                       */

  __IO uint32_t               XferCount;      /*!< LCDC Transfer Counter                    */

  DMA_HandleTypeDef           *hdmatx;        /*!< LCDC Tx DMA Handle parameters            */

  HAL_LockTypeDef             Lock;           /*!< Locking object                           */

  __IO HAL_LCDC_StateTypeDef  State;          /*!< LCDC state                               */

  __IO uint32_t               ErrorCode;      /*!< LCDC Error code                          */

#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
  void (* WriteCpltCallback)(struct __LCDC_HandleTypeDef *hlcdc);          /*!< LCDC write data Completed callback  */
  void (* ErrorCallback)(struct __LCDC_HandleTypeDef *hlcdc);              /*!< LCDC DMA write data error callback  */

  void (* MspInitCallback)(struct __LCDC_HandleTypeDef *hlcdc);            /*!< LCDC Msp Init callback              */
  void (* MspDeInitCallback)(struct __LCDC_HandleTypeDef *hlcdc);          /*!< LCDC Msp DeInit callback            */
#endif  /* USE_HAL_LCDC_REGISTER_CALLBACKS */
} LCDC_HandleTypeDef;

#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
/**
  * @brief  HAL LCDC Callback ID enumeration definition
  */
typedef enum
{
  HAL_LCDC_WRITECPLT_CB_ID          = 0x00U,    /*!< LCDC write data Completed callback ID */
  HAL_LCDC_ERROR_CB_ID              = 0x01U,    /*!< LCDC DMA write data error callback ID */
  HAL_LCDC_MSPINIT_CB_ID            = 0x02U,    /*!< LCDC Msp Init callback ID             */
  HAL_LCDC_MSPDEINIT_CB_ID          = 0x03U,    /*!< LCDC Msp DeInit callback ID           */
} HAL_LCDC_CallbackIDTypeDef;

/**
  * @brief  HAL LCDC Callback pointer definition
  */
typedef  void (*pLCDC_CallbackTypeDef)(LCDC_HandleTypeDef *hlcdc); /*!< pointer to an LCDC callback function */

#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LCDC_Exported_Constants LCDC Exported Constants
  * @{
  */

/** @defgroup LCDC_Error_Code LCDC Error Code
  * @{
  */
#define HAL_LCDC_ERROR_NONE              (0x00000000U)   /*!< No error                               */
#define HAL_LCDC_ERROR_BUSY              (0x00000001U)   /*!< BUSY error                             */
#define HAL_LCDC_ERROR_TIMEOUT           (0x00000002U)   /*!< Timrout error                          */
#define HAL_LCDC_ERROR_DMA               (0x00000004U)   /*!< DMA transfer error                     */
#define HAL_LCDC_ERROR_ABORT             (0x00000008U)   /*!< Error during LCDC Abort procedure      */
#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
#define HAL_LCDC_ERROR_INVALID_CALLBACK  (0x00000010U)   /*!< Invalid Callback error                 */
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup LCDC_Mode LCDC Mode
  * @{
  */
#define LCDC_MODE_8080                   (0x00000000U)
#define LCDC_MODE_6800                   (0x00000001U)
/**
  * @}
  */

/** @defgroup LCDC_Data_Size LCDC data size
  * @{
  */
#define LCDC_DATASIZE_8BIT               (0x00000000U)
#define LCDC_DATASIZE_9BIT               (0x00000001U)
#define LCDC_DATASIZE_16BIT              (0x00000002U)
#define LCDC_DATASIZE_18BIT              (0x00000003U)
/**
  * @}
  */

/** @defgroup LCDC_Cmd_Size LCDC cmd size
  * @{
  */
#define LCDC_CMDSIZE_8BIT                (0x00000000U)
#define LCDC_CMDSIZE_9BIT                (0x00000001U)
#define LCDC_CMDSIZE_16BIT               (0x00000002U)
#define LCDC_CMDSIZE_18BIT               (0x00000003U)
/**
  * @}
  */

/** @defgroup LCDC_Flags_definition LCDC Flags Definition
  * @{
  */
#define LCDC_FLAG_BUSY                   LCDC_CSR_BUSY   /* LCDC status flag: busy flag       */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup LCDC_Exported_Macros LCDC Exported Macros
  * @{
  */

/** @brief  Reset LCDC handle state.
  * @param  __HANDLE__ specifies the LCDC Handle.
  *         This parameter can be LCDC where x: 0, 1, 2, or 3 to select the LCDC peripheral.
  * @retval None
  */
#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
#define __HAL_LCDC_RESET_HANDLE_STATE(__HANDLE__)                do{                                            \
                                                                    (__HANDLE__)->State = HAL_LCDC_STATE_RESET; \
                                                                    (__HANDLE__)->MspInitCallback = NULL;       \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                                  } while(0)
#else
#define __HAL_LCDC_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_LCDC_STATE_RESET)
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */

/** @brief  Check whether the specified LCDC flag is set or not.
  * @param  __COMMON__ specifies the LCDC common register.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg LCDC_FLAG_BUSY: busy flag
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define __HAL_LCDC_GET_FLAG(__COMMON__, __FLAG__)                (((((__COMMON__)->CSR) & (__FLAG__)) == (__FLAG__)) ? SET : RESET)

/** @brief  Enable the LCDC peripheral.
  * @param  __HANDLE__ specifies the LCDC Handle.
  *         This parameter can be LCDC where x: 0, 1, 2, or 3 to select the LCDC peripheral.
  * @retval None
  */
#define __HAL_LCDC_ENABLE(__HANDLE__)                            do { \
                                                                      LCDC0123_COMMON->CSR |= (1 << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)LCDC0) \
                                                                                                  /  ((uint32_t)LCDC1 - (uint32_t)LCDC0)) \
                                                                                              ); \
                                                                    } while(0U)

/** @brief  Disable the LCDC peripheral.
  * @param  __HANDLE__ specifies the LCDC Handle.
  *         This parameter can be LCDC where x: 0, 1, 2, or 3 to select the LCDC peripheral.
  * @retval None
  */
#define __HAL_LCDC_DISABLE(__HANDLE__)                           do { \
                                                                      LCDC0123_COMMON->CSR &= ~(1 << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)LCDC0) \
                                                                                                   /  ((uint32_t)LCDC1 - (uint32_t)LCDC0)) \
                                                                                               ); \
                                                                    } while(0U)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup LCDC_Private_Macros LCDC Private Macros
  * @{
  */

/** @brief  Checks if LCDC Mode parameter is in allowed range.
  * @param  __MODE__ specifies the LCDC Mode.
  *         This parameter can be a value of @ref LCDC_Mode
  * @retval None
  */
#define IS_LCDC_MODE(__MODE__)      (((__MODE__) == LCDC_MODE_8080)   || \
                                     ((__MODE__) == LCDC_MODE_6800))

/** @brief  Checks if LCDC AddSet parameter is in allowed range.
  * @param  __ADDSET__ specifies the LCDC AddSet.
  * @retval None
  */
#define IS_LCDC_ADDSET(__ADDSET__)  ((__ADDSET__) <= 15U)

/** @brief  Checks if LCDC DataSt parameter is in allowed range.
  * @param  __DATAST__ specifies the LCDC DataSt.
  * @retval None
  */
#define IS_LCDC_DATAST(__DATAST__)  ((__DATAST__) <= 255U)

/** @brief  Checks if LCDC DataHold parameter is in allowed range.
  * @param  __DATAHOLD__ specifies the LCDC DataHold.
  * @retval None
  */
#define IS_LCDC_DATAHOLD(__DATAHOLD__)  ((__DATAHOLD__) <= 3U)

/** @brief  Checks if LCDC Datasize parameter is in allowed range.
  * @param  __SIZE__ specifies the LCDC Datasize.
  *         This parameter can be a value of @ref LCDC_Data_Size
  * @retval None
  */
#define IS_LCDC_DATASIZE(__SIZE__)      (((__SIZE__) == LCDC_DATASIZE_8BIT)   || \
                                         ((__SIZE__) == LCDC_DATASIZE_9BIT)   || \
                                         ((__SIZE__) == LCDC_DATASIZE_16BIT)  || \
                                         ((__SIZE__) == LCDC_DATASIZE_18BIT))

/** @brief  Checks if LCDC Cmdsize parameter is in allowed range.
  * @param  __SIZE__ specifies the LCDC Cmdsize.
  *         This parameter can be a value of @ref LCDC_Cmd_Size
  * @retval None
  */
#define IS_LCDC_CMDSIZE(__SIZE__)       (((__SIZE__) == LCDC_CMDSIZE_8BIT)   || \
                                         ((__SIZE__) == LCDC_CMDSIZE_9BIT)   || \
                                         ((__SIZE__) == LCDC_CMDSIZE_16BIT)  || \
                                         ((__SIZE__) == LCDC_CMDSIZE_18BIT))

/** @brief  Checks if DMA handle is valid.
  * @param  __HANDLE__ specifies a DMA Handle.
  * @retval None
  */
#define IS_LCDC_DMA_HANDLE(__HANDLE__) ((__HANDLE__) != NULL)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup LCDC_Exported_Functions
  * @{
  */

/** @addtogroup LCDC_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  ********************************/
HAL_StatusTypeDef HAL_LCDC_Init(LCDC_HandleTypeDef *hlcdc);
HAL_StatusTypeDef HAL_LCDC_DeInit(LCDC_HandleTypeDef *hlcdc);
void HAL_LCDC_MspInit(LCDC_HandleTypeDef *hlcdc);
void HAL_LCDC_MspDeInit(LCDC_HandleTypeDef *hlcdc);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
HAL_StatusTypeDef HAL_LCDC_RegisterCallback(LCDC_HandleTypeDef *hlcdc, HAL_LCDC_CallbackIDTypeDef CallbackID, pLCDC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_LCDC_UnRegisterCallback(LCDC_HandleTypeDef *hlcdc, HAL_LCDC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup LCDC_Exported_Functions_Group2
  * @{
  */
/* I/O operation functions  ***************************************************/
HAL_StatusTypeDef HAL_LCDC_WriteData(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LCDC_ReadData(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LCDC_WriteData_DMA(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_LCDC_WriteCmd(LCDC_HandleTypeDef *hlcdc, uint8_t *pCmd, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LCDC_ReadCmd(LCDC_HandleTypeDef *hlcdc, uint8_t *pCmd, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LCDC_Abort(LCDC_HandleTypeDef *hlcdc);
void HAL_LCDC_WriteCpltCallback(LCDC_HandleTypeDef *hlcdc);
void HAL_LCDC_ErrorCallback(LCDC_HandleTypeDef *hlcdc);

/**
  * @}
  */

/** @addtogroup LCDC_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_LCDC_StateTypeDef HAL_LCDC_GetState(LCDC_HandleTypeDef *hlcdc);
uint32_t              HAL_LCDC_GetError(LCDC_HandleTypeDef *hlcdc);
/**
  * @}
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

#endif /* PY32f0xx_HAL_LCDC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
