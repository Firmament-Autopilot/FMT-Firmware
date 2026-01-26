/**
  ******************************************************************************
  * @file    py32e407_ll_lcdc.h
  * @author  MCU Application Team
  * @brief   Header file of LCDC LL module.
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
#ifndef PY32E407_LL_LCDC_H
#define PY32E407_LL_LCDC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined(LCDC0) || defined(LCDC1) || defined(LCDC2) || defined(LCDC3)

/** @defgroup LCDC_LL LCDC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup LCDC_LL_Exported_Constants LCDC Exported Constants
  * @{
  */

/** @defgroup LCDC_LL_EC_MODE LCDC Mode Defines
  * @{
  */
#define LL_LCDC_MODE_8080                    0x00000000   /*!< LCDC Mode 8080                                   */
#define LL_LCDC_MODE_6800                    0x00000001   /*!< LCDC Mode 6800                                   */
/**
  * @}
  */

/**
  * @}
  */

/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/** @defgroup LCDC_LL_Exported_Macros LCDC Exported Macros
  * @{
  */

/** @defgroup LCDC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in LCDC register
  * @param  __INSTANCE__ LCDC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_LCDC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in LCDC register
  * @param  __INSTANCE__ LCDC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_LCDC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup LCDC_LL_ES_INIT LCDC Exported Init structure
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

} LL_LCDC_TimingTypeDef;

/**
  * @brief  Structure definition of some features of LCDC
  */
typedef struct
{
  uint32_t Mode;                /*!< Specifies the LCDC interface mode.
                                     This parameter can be a value of @ref LCDC_LL_EC_MODE */

  LL_LCDC_TimingTypeDef Write;     /*!< Specifies the LCDC write access timing.*/

  LL_LCDC_TimingTypeDef Read;      /*!< Specifies the LCDC read access timing.*/

} LL_LCDC_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */


/* Exported functions --------------------------------------------------------*/

/** @defgroup LCDC_LL_Exported_Functions LCDC Exported Functions
  * @{
  */

/** @defgroup LCDC_LL_EF_Enable LCDC Enable
  * @{
  */

/**
  * @brief  Enable LCDC.
  * @rmtoll CSR        EN         LL_LCDC_Enable
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_Enable(LCDC_TypeDef *LCDCx)
{
  uint32_t lcdcindex=0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0);
  SET_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN0 << lcdcindex);
}

/**
  * @brief  Disable LCDC.
  * @rmtoll CSR        EN         LL_LCDC_Disable
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_Disable(LCDC_TypeDef *LCDCx)
{
  uint32_t lcdcindex = 0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0); 
  CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN0 << lcdcindex);
}

/**
  * @brief  Check the state of LCDC.
  * @rmtoll CSR        EN         LL_LCDC_IsEnabled
  * @param  LCDCx LCDC instance
  * @retval uint32_t State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCDC_IsEnabled(const LCDC_TypeDef *LCDCx)
{
  uint32_t lcdcindex = 0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0);
  return ((READ_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN0 << lcdcindex) == (LCDC_CSR_EN0 << lcdcindex)) ? 1UL : 0UL);
}

/**
  * @}
  */
/** @defgroup LCDC_LL_EF_FLAG_Management Flag_Management
  * @{
  */

/**
  * @brief  Check if LCDC Busy
  * @rmtoll CSR          BUSY         LL_LCDC_IsActiveFlag_BUSY
  * @param  LCDCx LCDC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t LL_LCDC_IsActiveFlag_BUSY(LCDC_TypeDef *LCDCx)
{
  return ((READ_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_BUSY) == LCDC_CSR_BUSY) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup LCDC_LL_EF_WRITEREAD LCDC Write Read
  * @{
  */

/**
  * @brief  Write 8bit Data.
  * @rmtoll DR        D          LL_LCDC_WriteData_8b
  * @param  LCDCx LCDC instance
  * @param  Data 8-bit value to be provided as input data for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteData_8b(LCDC_TypeDef *LCDCx, uint8_t Data)
{
  *((__IO uint8_t *)&LCDCx->DR) = (Data & 0xFFU);
}

/**
  * @brief  Read 8bit Data.
  * @rmtoll DR        D          LL_LCDC_ReadData_8b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint8_t LL_LCDC_ReadData_8b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint8_t *)&LCDCx->DR) & 0xFF);
}


/**
  * @brief  Write 8bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_WriteCommand_8b
  * @param  LCDCx LCDC instance
  * @param  Command 8-bit value to be provided as input Command for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteCommand_8b(LCDC_TypeDef *LCDCx, uint8_t Command)
{
  *((__IO uint8_t *)&LCDCx->CMDR) = (Command & 0xFFU);
}

/**
  * @brief  Read 8bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_ReadCommand_8b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint8_t LL_LCDC_ReadCommand_8b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint8_t *)&LCDCx->CMDR) & 0xFF);
}

/**
  * @brief  Write 9bit Data.
  * @rmtoll DR        D          LL_LCDC_WriteData_9b
  * @param  LCDCx LCDC instance
  * @param  Data 9-bit value to be provided as input data for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteData_9b(LCDC_TypeDef *LCDCx, uint16_t Data)
{
  *((__IO uint16_t *)&LCDCx->DR) = (Data & 0x1FFU);
}

/**
  * @brief  Read 9bit Data.
  * @rmtoll DR        D          LL_LCDC_ReadData_9b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint16_t LL_LCDC_ReadData_9b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint16_t *)&LCDCx->DR) & 0x1FF);
}

/**
  * @brief  Write 9bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_WriteCommand_9b
  * @param  LCDCx LCDC instance
  * @param  Command 9-bit value to be provided as input Command for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteCommand_9b(LCDC_TypeDef *LCDCx, uint16_t Command)
{
  *((__IO uint16_t *)&LCDCx->CMDR) = (Command & 0x1FFU);
}

/**
  * @brief  Read 9bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_ReadCommand_9b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint16_t LL_LCDC_ReadCommand_9b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint16_t *)&LCDCx->CMDR) & 0x1FF);
}

/**
  * @brief  Write 16bit Data.
  * @rmtoll DR        D          LL_LCDC_WriteData_16b
  * @param  LCDCx LCDC instance
  * @param  Data 16-bit value to be provided as input data for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteData_16b(LCDC_TypeDef *LCDCx, uint16_t Data)
{
  *((__IO uint16_t *)&LCDCx->DR) = (Data & 0xFFFFU);
}

/**
  * @brief  Read 16bit Data.
  * @rmtoll DR        D          LL_LCDC_ReadData_16b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint16_t LL_LCDC_ReadData_16b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint16_t *)&LCDCx->DR) & 0xFFFFF);
}

/**
  * @brief  Write 16bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_WriteCommand_16b
  * @param  LCDCx LCDC instance
  * @param  Command 16-bit value to be provided as input Command for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteCommand_16b(LCDC_TypeDef *LCDCx, uint16_t Command)
{
  *((__IO uint16_t *)&LCDCx->CMDR) = (Command & 0xFFFFU);
}

/**
  * @brief  Read 16bit Command.
  * @rmtoll CMDR        Cmd          LL_LCDC_ReadCommand_16b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint16_t LL_LCDC_ReadCommand_16b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint16_t *)&LCDCx->CMDR) & 0xFFFFF);
}

/**
  * @brief  Write 18bit Data.
  * @rmtoll DR        D          LL_LCDC_WriteData_18b
  * @param  LCDCx LCDC instance
  * @param  Data 18-bit value to be provided as input data for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteData_18b(LCDC_TypeDef *LCDCx, uint32_t Data)
{
  *((__IO uint32_t *)&LCDCx->DR) = (Data & 0x3FFFFU);
}

/**
  * @brief  Read 18bit Data.
  * @rmtoll DR        D          LL_LCDC_ReadData_18b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint32_t LL_LCDC_ReadData_18b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint32_t *)&LCDCx->DR) & 0x3FFFF);
}

/**
  * @brief  Write 18bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_WriteCommand_18b
  * @param  LCDCx LCDC instance
  * @param  Command 18-bit value to be provided as input command for LCDC processing.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_WriteCommand_18b(LCDC_TypeDef *LCDCx, uint32_t Command)
{
  *((__IO uint32_t *)&LCDCx->CMDR) = (Command & 0x3FFFFU);
}

/**
  * @brief  Read 18bit Command.
  * @rmtoll CMDR        CMD          LL_LCDC_ReadCommand_18b
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE uint32_t LL_LCDC_ReadCommand_18b(LCDC_TypeDef *LCDCx)
{
  return  (*((__IO uint32_t *)&LCDCx->CMDR) & 0x3FFFFU);
}
/**
  * @}
  */

/** @defgroup LCDC_LL_EF_Mode_Management LCDC Mode
  * @{
  */
/**
  * @brief  Configure Mode.
  * @rmtoll CSR        Mode          LL_LCDC_SetMode
  * @param  LCDCx LCDC instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_LCDC_MODE_8080
  *         @arg @ref LL_LCDC_MODE_6800
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetMode(LCDC_TypeDef *LCDCx, uint32_t Mode)
{
  uint32_t lcdcindex=0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0);
 
  MODIFY_REG(LCDC0123_COMMON->CSR,LCDC_CSR_MODE0 << lcdcindex,Mode << (LCDC_CSR_MODE0_Pos+lcdcindex));
}
  
/**
  * @brief  Return Mode.
  * @rmtoll CSR        Mode          LL_LCDC_GetMode
  * @param  LCDCx LCDC instance
  * @retval uint32_t Returned value can be one of the following values:
  *         @arg @ref LL_LCDC_MODE_8080
  *         @arg @ref LL_LCDC_MODE_6800
  */
__STATIC_INLINE uint32_t LL_LCDC_GetMode(const LCDC_TypeDef *LCDCx)
{
  uint32_t lcdcindex=0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0);
  return (READ_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_MODE0 << lcdcindex) >> (LCDC_CSR_MODE0_Pos + lcdcindex)) ;
}
/**
  * @}
  */

/** @defgroup LCDC_LL_EF_WriteTime_Management Write Time Management
  * @{
  */

/**
  * @brief  Configure Write Address Set Time.
  * @rmtoll WCFGR        ADDSET          LL_LCDC_SetWriteAddressSetTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0x0F.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetWriteAddressSetTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WCFGR,LCDC_WCFGR_ADDSET,Time);
}
  
/**
  * @brief  Return Write Address Set Time.
  * @rmtoll CSR        Mode          LL_LCDC_GetWriteAddressSetTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0x0F).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetWriteAddressSetTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WCFGR, LCDC_WCFGR_ADDSET));
}

/**
  * @brief  Configure Write Data Set Time.
  * @rmtoll WCFGR        DATAST          LL_LCDC_SetWriteDataSetTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0xFF.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetWriteDataSetTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WCFGR,LCDC_WCFGR_DATAST,Time<<LCDC_WCFGR_DATAST_Pos);
}
  
/**
  * @brief  Return Write Data Set Time.
  * @rmtoll WCFGR        DATAST          LL_LCDC_GetWriteDataSetTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0x0F).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetWriteDataSetTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WCFGR, LCDC_WCFGR_DATAST)>>LCDC_WCFGR_DATAST_Pos);
}

/**
  * @brief  Configure Write Data Hold Time.
  * @rmtoll WCFGR        DATAHLD          LL_LCDC_SetWriteDataHoldTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0x04.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetWriteDataHoldTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WCFGR,LCDC_WCFGR_DATAHLD,Time<<LCDC_WCFGR_DATAHLD_Pos);
}
  
/**
  * @brief  Return Write Data Hold Time.
  * @rmtoll WCFGR        DATAHLD          LL_LCDC_GetWriteDataHoldTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0x0F).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetWriteDataHoldTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WCFGR, LCDC_WCFGR_DATAHLD)>>LCDC_WCFGR_DATAHLD_Pos);
}
/**
  * @}
  */


/** @defgroup LCDC_LL_EF_ReadTime_Management Read Time Management
  * @{
  */

/**
  * @brief  Configure Read Address Set Time.
  * @rmtoll RCFGR        ADDSET          LL_LCDC_SetReadAddressSetTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0x0F.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetReadAddressSetTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->RCFGR,LCDC_RCFGR_ADDSET,Time);
}
  
/**
  * @brief  Return Read Address Set Time.
  * @rmtoll RCFGR        ADDSET          LL_LCDC_GetReadAddressSetTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0x0F).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetReadAddressSetTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->RCFGR, LCDC_RCFGR_ADDSET));
}

/**
  * @brief  Configure Read Data Set Time.
  * @rmtoll RCFGR        DATAST          LL_LCDC_SetReadDataSetTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0xFF.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetReadDataSetTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->RCFGR,LCDC_RCFGR_DATAST,Time<<LCDC_RCFGR_DATAST_Pos);
}
  
/**
  * @brief  Return Read Data Set Time.
  * @rmtoll RCFGR        DATAST          LL_LCDC_GetReadDataSetTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0xFF).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetReadDataSetTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->RCFGR, LCDC_RCFGR_DATAST)>>LCDC_RCFGR_DATAST_Pos);
}

/**
  * @brief  Configure Read Data Hold Time.
  * @rmtoll RCFGR        DATAHLD          LL_LCDC_SetReadDataHoldTime
  * @param  LCDCx LCDC instance
  * @param  Time Parameter .
  *               This parameter must be a value between Min_Data=0x00 and Max_Data=0x4.
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_SetReadDataHoldTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->RCFGR,LCDC_RCFGR_DATAHLD,Time<<LCDC_RCFGR_DATAHLD_Pos);
}
  
/**
  * @brief  Return Read Data Hold Time.
  * @rmtoll RCFGR        DATAHLD          LL_LCDC_GetReadDataHoldTime
  * @param  LCDCx LCDC instance
  * @retval (value between Min_Data=0x00 and Max_Data=0x0F).
  */
__STATIC_INLINE uint32_t LL_LCDC_GetReadDataHoldTime(const LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->RCFGR, LCDC_RCFGR_DATAHLD)>>LCDC_RCFGR_DATAHLD_Pos);
}
/**
  * @}
  */


/** @defgroup LCDC_LL_EF_DMA_Management DMA_Management
  * @{
  */

/**
  * @brief  Enable LCDCC DMA request.
  * @rmtoll CSR           DMAEN        LL_LCDC_EnableDMAReq
  * @param  LCDCx LCDCC instance
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_EnableDMAReq(LCDC_TypeDef *LCDCx)
{
  SET_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);
}

/**
  * @brief  Disable LCDC DMA request.
  * @rmtoll CSR           DMAEN        LL_LCDC_DisableDMAReq
  * @param  LCDCx LCDC instance
  * @retval None
  */
__STATIC_INLINE void LL_LCDC_DisableDMAReq(LCDC_TypeDef *LCDCx)
{
  CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);
}

/**
  * @brief  Check LCDC DMA request state.
  * @rmtoll CSR           DMAEN        LL_LCDC_IsEnabledDMAReq
  * @param  LCDCx LCDC instance
  * @retval uint32_t State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCDC_IsEnabledDMAReq(const LCDC_TypeDef *LCDCx)
{
  return ((READ_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN) == (LCDC_CSR_DMAEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup LCDC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_LCDC_Init(LCDC_TypeDef *LCDCx,LL_LCDC_InitTypeDef *LCDC_InitStruct);
ErrorStatus LL_LCDC_DeInit(LCDC_TypeDef *LCDCx);


/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(LCDC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_LL_LCDC_H */
