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

#include "hc32_ll.h"
#include "hc32_ll_fcg.h"
#include "hc32_ll_gpio.h"

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

#define USART5_RX_ERR_IRQn       (INT000_IRQn)
#define USART5_RX_FULL_IRQn      (INT001_IRQn)

#define USART2_RX_ERR_IRQn       (INT002_IRQn)
#define USART2_RX_FULL_IRQn      (INT003_IRQn)
#define USART2_TX_CPLT_IRQn      (INT004_IRQn)
#define USART2_TX_DMA_TC_IRQn    (INT005_IRQn)
#define USART2_TX_DMA_UNIT       (CM_DMA1)
#define USART2_TX_DMA_CH         (DMA_CH0)
#define USART2_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC0)
#define USART2_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH0)
#define USART2_TX_DMA_TRIG_SEL   (AOS_DMA1_0)
#define USART2_TX_DMA_TC_INT     (DMA_INT_TC_CH0)

#define USART6_RX_ERR_IRQn       (INT006_IRQn)
#define USART6_RX_FULL_IRQn      (INT007_IRQn)

#define USART1_RX_ERR_IRQn       (INT008_IRQn)
#define USART1_RX_FULL_IRQn      (INT009_IRQn)
#define USART1_TX_CPLT_IRQn      (INT010_IRQn)
#define USART1_TX_DMA_TC_IRQn    (INT011_IRQn)
#define USART1_TX_DMA_UNIT       (CM_DMA1)
#define USART1_TX_DMA_CH         (DMA_CH1)
#define USART1_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC1)
#define USART1_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH1)
#define USART1_TX_DMA_TRIG_SEL   (AOS_DMA1_1)
#define USART1_TX_DMA_TC_INT     (DMA_INT_TC_CH1)

#define USART7_RX_ERR_IRQn       (INT012_IRQn)
#define USART7_RX_FULL_IRQn      (INT013_IRQn)
#define USART7_TX_CPLT_IRQn      (INT014_IRQn)
#define USART7_TX_DMA_TC_IRQn    (INT015_IRQn)
#define USART7_TX_DMA_UNIT       (CM_DMA1)
#define USART7_TX_DMA_CH         (DMA_CH2)
#define USART7_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC2)
#define USART7_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH2)
#define USART7_TX_DMA_TRIG_SEL   (AOS_DMA1_2)
#define USART7_TX_DMA_TC_INT     (DMA_INT_TC_CH2)

#define USART3_RX_ERR_IRQn       (INT016_IRQn)
#define USART3_RX_FULL_IRQn      (INT017_IRQn)
#define USART3_TX_CPLT_IRQn      (INT018_IRQn)
#define USART3_TX_DMA_TC_IRQn    (INT019_IRQn)
#define USART3_TX_DMA_UNIT       (CM_DMA1)
#define USART3_TX_DMA_CH         (DMA_CH3)
#define USART3_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC3)
#define USART3_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH3)
#define USART3_TX_DMA_TRIG_SEL   (AOS_DMA1_3)
#define USART3_TX_DMA_TC_INT     (DMA_INT_TC_CH3)

#define USART8_RX_ERR_IRQn       (INT020_IRQn)
#define USART8_RX_FULL_IRQn      (INT021_IRQn)
#define USART8_TX_CPLT_IRQn      (INT022_IRQn)
#define USART8_TX_DMA_TC_IRQn    (INT023_IRQn)
#define USART8_TX_DMA_UNIT       (CM_DMA1)
#define USART8_TX_DMA_CH         (DMA_CH4)
#define USART8_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC4)
#define USART8_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH4)
#define USART8_TX_DMA_TRIG_SEL   (AOS_DMA1_4)
#define USART8_TX_DMA_TC_INT     (DMA_INT_TC_CH4)

#define USART4_RX_ERR_IRQn       (INT024_IRQn)
#define USART4_RX_FULL_IRQn      (INT025_IRQn)
#define USART4_TX_CPLT_IRQn      (INT026_IRQn)
#define USART4_TX_DMA_TC_IRQn    (INT027_IRQn)
#define USART4_TX_DMA_UNIT       (CM_DMA1)
#define USART4_TX_DMA_CH         (DMA_CH5)
#define USART4_TX_DMA_TC_INT_SRC (INT_SRC_DMA1_TC5)
#define USART4_TX_DMA_TC_FLAG    (DMA_FLAG_TC_CH5)
#define USART4_TX_DMA_TRIG_SEL   (AOS_DMA1_5)
#define USART4_TX_DMA_TC_INT     (DMA_INT_TC_CH5)

#define TIMA_9_CAPTURE_IRQn      (INT080_IRQn)

#endif
