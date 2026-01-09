/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef FMT_BSP_HEADER_H__
#define FMT_BSP_HEADER_H__

/* hc32 peripheral library */
#include <hc32f4xx.h>
/* FPU Library */
#include <arm_math.h>

// #include "stm32h7xx_hal.h"
// #include "stm32h7xx_hal_fdcan.h"
// #include "stm32h7xx_ll_bus.h"
// #include "stm32h7xx_ll_cortex.h"
// #include "stm32h7xx_ll_dma.h"
// #include "stm32h7xx_ll_exti.h"
// #include "stm32h7xx_ll_gpio.h"
// #include "stm32h7xx_ll_pwr.h"
// #include "stm32h7xx_ll_rcc.h"
// #include "stm32h7xx_ll_system.h"
// #include "stm32h7xx_ll_utils.h"

#define USART5_RX_ERR_IRQn         (INT000_IRQn)
#define USART5_RX_FULL_IRQn        (INT001_IRQn)

#define USART2_RX_ERR_IRQn         (INT002_IRQn)
#define USART2_RX_FULL_IRQn        (INT003_IRQn)
#define USART2_TX_CPLT_IRQn        (INT004_IRQn)
#define USART2_TX_DMA_TC_IRQn      (INT005_IRQn)
#define USART2_TX_DMA_UNIT         (CM_DMA1)
#define USART2_TX_DMA_CH           (DMA_CH0)
#define USART2_TX_DMA_TC_INT_SRC   (INT_SRC_DMA1_TC0)
#define USART2_TX_DMA_TC_FLAG      (DMA_FLAG_TC_CH0)
#define USART2_TX_DMA_TRIG_SEL     (AOS_DMA1_0)
#define USART2_TX_DMA_TRIG_EVT_SRC (EVT_SRC_USART2_TI)
#define USART2_TX_DMA_TC_INT       (DMA_INT_TC_CH0)

#endif
