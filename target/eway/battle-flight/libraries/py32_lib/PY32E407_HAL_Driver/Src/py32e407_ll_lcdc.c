/**
  ******************************************************************************
  * @file    py32e407_ll_lcdc.c
  * @author  MCU Application Team
  * @brief   Header for py32e407_ll_lcdc.c module
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
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_lcdc.h"
#include "py32e407_ll_bus.h"
#ifdef USE_FULL_ASSERT
#include "py32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined(LCDC0) || defined(LCDC1) || defined(LCDC2) || defined(LCDC3)  
 
/** @addtogroup LCDC_LL
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Functions Definition ------------------------------------------------------*/
/** @addtogroup LCDC_LL_Exported_Functions
  * @{
  */

/** @addtogroup LCDC_LL_EF_Init
  * @{
  */

/**
  * @brief  Initialize LCDC peripheral registers to their default reset values.
  * @param  LCDCx LCDC Instance
  * @param  LCDC_InitStruct to a @ref LL_LCDC_InitTypeDef structure  
  * @retval ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are initialized
  *          - ERROR: LCDC registers are not initialized
  */
ErrorStatus LL_LCDC_Init(LCDC_TypeDef *LCDCx,LL_LCDC_InitTypeDef *LCDC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_LCDC_ALL_INSTANCE(LCDCx));

  uint32_t lcdcindex=0;
  lcdcindex = (LCDCx-LCDC0)/(LCDC1-LCDC0);
 
  MODIFY_REG(LCDC0123_COMMON->CSR,LCDC_CSR_MODE0_Pos<<lcdcindex,LCDC_InitStruct->Mode << (LCDC_CSR_MODE0_Pos+lcdcindex));

  /*----------------------- LCDCx WCFGR & RCFGR Configuration ---------------------*/
  /* Configure : address setup time , data-phase duration and data hold time for write
     access */
  WRITE_REG(LCDCx->WCFGR, ((LCDC_InitStruct->Write.AddSet & LCDC_WCFGR_ADDSET) |
                                     ((LCDC_InitStruct->Write.DataSt << LCDC_WCFGR_DATAST_Pos) & LCDC_WCFGR_DATAST) |
                                     ((LCDC_InitStruct->Write.DataHold << LCDC_WCFGR_DATAHLD_Pos) & LCDC_WCFGR_DATAHLD)));
  
  /* Configure : address setup time , data-phase duration and data hold time for read
     access */
  WRITE_REG(LCDCx->RCFGR, ((LCDC_InitStruct->Read.AddSet & LCDC_RCFGR_ADDSET) |
                                     ((LCDC_InitStruct->Read.DataSt << LCDC_RCFGR_DATAST_Pos) & LCDC_RCFGR_DATAST) |
                                     ((LCDC_InitStruct->Read.DataHold << LCDC_RCFGR_DATAHLD_Pos) & LCDC_RCFGR_DATAHLD)));


  return (status);
}

/**
  * @brief  De-Initialize LCDC peripheral registers to their default reset values.
  * @param  LCDCx LCDC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are de-initialized
  *          - ERROR: LCDC registers are not de-initialized
  */
ErrorStatus LL_LCDC_DeInit(LCDC_TypeDef *LCDCx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_LCDC_ALL_INSTANCE(LCDCx));

  if ((LCDCx == LCDC0) || (LCDCx == LCDC1) || (LCDCx == LCDC2) || (LCDCx == LCDC3))
  {
    LL_LCDC_Disable(LCDCx);
  }
  else
  {
    status = ERROR;
  }

  return (status);
}


/**
  * @}
  */

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

#endif /* USE_FULL_LL_DRIVER */
