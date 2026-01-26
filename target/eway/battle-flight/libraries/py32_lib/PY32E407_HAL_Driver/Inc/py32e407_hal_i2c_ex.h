/**
  ******************************************************************************
  * @file    py32e407_hal_i2c_ex.h
  * @author  MCU Application Team
  * @brief   Header file of I2C HAL Extended module.
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
#ifndef __PY32E407_HAL_I2C_EX_H
#define __PY32E407_HAL_I2C_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup I2CEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup I2CEx_Exported_Constants I2C Extended Exported Constants
  * @{
  */

/** @defgroup I2CEx_FastModePlus I2C Extended Fast Mode Plus
  * @{
  */
#define I2C_FMP_NOT_SUPPORTED           0xAAAA0000U                                     /*!< Fast Mode Plus not supported       */
#define I2C_FASTMODEPLUS_I2C1           SYSCFG_CFGR1_I2C1_FMP                           /*!< Enable Fast Mode Plus on I2C1 pins */
#define I2C_FASTMODEPLUS_I2C2           SYSCFG_CFGR1_I2C2_FMP                           /*!< Enable Fast Mode Plus on I2C2 pins */
#define I2C_FASTMODEPLUS_I2C3           SYSCFG_CFGR1_I2C3_FMP                           /*!< Enable Fast Mode Plus on I2C3 pins */
#define I2C_FASTMODEPLUS_I2C4           SYSCFG_CFGR1_I2C4_FMP                           /*!< Enable Fast Mode Plus on I2C4 pins */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2CEx_Exported_Macros I2C Extended Exported Macros
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup I2CEx_Exported_Functions I2C Extended Exported Functions
  * @{
  */

/** @addtogroup I2CEx_Exported_Functions_Group2 I2C Extended WakeUp Mode Functions
  * @{
  */
HAL_StatusTypeDef HAL_I2CEx_EnableWakeUp(I2C_HandleTypeDef *hi2c,uint32_t ToutDiv,uint32_t ToutCnt);
HAL_StatusTypeDef HAL_I2CEx_DisableWakeUp(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/** @addtogroup I2CEx_Exported_Functions_Group3 I2C Extended FastModePlus Functions
  * @{
  */
void HAL_I2CEx_EnableFastModePlus(uint32_t ConfigFastModePlus);
void HAL_I2CEx_DisableFastModePlus(uint32_t ConfigFastModePlus);
/**
  * @}
  */


/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2CEx_Private_Constants I2C Extended Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup I2CEx_Private_Macro I2C Extended Private Macros
  * @{
  */
#define IS_I2C_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & I2C_FMP_NOT_SUPPORTED) != I2C_FMP_NOT_SUPPORTED) && \
                                          (((__CONFIG__) & (I2C_FASTMODEPLUS_I2C1)) == I2C_FASTMODEPLUS_I2C1)    || \
                                          (((__CONFIG__) & (I2C_FASTMODEPLUS_I2C2)) == I2C_FASTMODEPLUS_I2C2)    || \
                                          (((__CONFIG__) & (I2C_FASTMODEPLUS_I2C3)) == I2C_FASTMODEPLUS_I2C3)    || \
                                          (((__CONFIG__) & (I2C_FASTMODEPLUS_I2C4)) == I2C_FASTMODEPLUS_I2C4))
/**
  * @}
  */

/* Private Functions ---------------------------------------------------------*/
/** @defgroup I2CEx_Private_Functions I2C Extended Private Functions
  * @{
  */
/* Private functions are defined in py32e407_hal_i2c_ex.c file */
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

#endif /* PY32E407_HAL_I2C_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
