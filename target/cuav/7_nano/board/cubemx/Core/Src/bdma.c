/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    bdma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "bdma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_BDMA_Init(void)
{

  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_BDMA);

  /* DMA interrupt init */
  /* BDMA_Channel0_IRQn interrupt configuration */
  NVIC_SetPriority(BDMA_Channel0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(BDMA_Channel0_IRQn);
  /* BDMA_Channel1_IRQn interrupt configuration */
  NVIC_SetPriority(BDMA_Channel1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(BDMA_Channel1_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

