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

#include <arm_math.h>
/* wl32 peripheral library */
#include <wl32f436.h>
#include <wl32_ll.h>

#define USART1_RX_ERR_IRQn         (INT000_IRQn)
#define USART1_RX_FULL_IRQn        (INT001_IRQn)

#define USART6_RX_ERR_IRQn         (INT002_IRQn)
#define USART6_RX_FULL_IRQn        (INT003_IRQn)
#define USART6_TX_CPLT_IRQn        (INT004_IRQn)
#define USART6_TX_DMA_TC_IRQn      (INT005_IRQn)
#define USART6_TX_DMA_UNIT         (CM_DMA1)
#define USART6_TX_DMA_CH           (DMA_CH0)
#define USART6_TX_DMA_TC_INT_SRC   (INT_SRC_DMA1_TC0)
#define USART6_TX_DMA_TC_FLAG      (DMA_FLAG_TC_CH0)
#define USART6_TX_DMA_TRIG_SEL     (AOS_DMA1_0)
#define USART6_TX_DMA_TRIG_EVT_SRC (EVT_SRC_USART6_TI)
#define USART6_TX_DMA_TC_INT       (DMA_INT_TC_CH0)

// #define USART6_RX_ERR_IRQn         (INT006_IRQn)
// #define USART6_RX_FULL_IRQn        (INT007_IRQn)

#endif
