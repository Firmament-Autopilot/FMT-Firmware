/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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
#include <wl32_ll.h>
#include <wl32f436.h>


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

#define USART3_RX_ERR_IRQn         (INT006_IRQn)
#define USART3_RX_FULL_IRQn        (INT007_IRQn)
#define USART3_TX_CPLT_IRQn        (INT008_IRQn)
#define USART3_TX_DMA_TC_IRQn      (INT009_IRQn)
#define USART3_TX_DMA_UNIT         (CM_DMA1)
#define USART3_TX_DMA_CH           (DMA_CH1)
#define USART3_TX_DMA_TC_INT_SRC   (INT_SRC_DMA1_TC1)
#define USART3_TX_DMA_TC_FLAG      (DMA_FLAG_TC_CH1)
#define USART3_TX_DMA_TRIG_SEL     (AOS_DMA1_1)
#define USART3_TX_DMA_TRIG_EVT_SRC (EVT_SRC_USART3_TI)
#define USART3_TX_DMA_TC_INT       (DMA_INT_TC_CH1)

#define USART2_RX_ERR_IRQn         (INT010_IRQn)
#define USART2_RX_FULL_IRQn        (INT011_IRQn)
#define USART2_TX_CPLT_IRQn        (INT012_IRQn)
#define USART2_TX_DMA_TC_IRQn      (INT013_IRQn)
#define USART2_TX_DMA_UNIT         (CM_DMA1)
#define USART2_TX_DMA_CH           (DMA_CH2)
#define USART2_TX_DMA_TC_INT_SRC   (INT_SRC_DMA1_TC2)
#define USART2_TX_DMA_TC_FLAG      (DMA_FLAG_TC_CH2)
#define USART2_TX_DMA_TRIG_SEL     (AOS_DMA1_2)
#define USART2_TX_DMA_TRIG_EVT_SRC (EVT_SRC_USART2_TI)
#define USART2_TX_DMA_TC_INT       (DMA_INT_TC_CH2)

#define USART7_RX_ERR_IRQn         (INT014_IRQn)
#define USART7_RX_FULL_IRQn        (INT015_IRQn)

#define TIMA_2_CMP_IRQn            (INT080_IRQn)