/******************************************************************************
 * Copyright 2020-2024 The Firmament Authors. All Rights Reserved.
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
#include "drv_fdcan.h"
#include "board.h"
#include "hal/can/can.h"

static FDCAN_HandleTypeDef hfdcan1;
static FDCAN_HandleTypeDef hfdcan2;
static uint32_t HAL_RCC_FDCAN_CLK_ENABLED = 0;

static rt_err_t can_configure(can_dev_t can, struct can_configure* cfg);
static rt_err_t can_control(can_dev_t can, int cmd, void* arg);
static int send_canmsg(can_dev_t can, const can_msg_t msg);
static int recv_canmsg(can_dev_t can, can_msg_t msg);

const static struct can_ops can_dev_ops = {
    .configure = can_configure,
    .control = can_control,
    .sendmsg = send_canmsg,
    .recvmsg = recv_canmsg
};

static can_device can1_dev = {
    .ops = &can_dev_ops,
    .config = CAN_DEFAULT_CONFIG,
};

static can_device can2_dev = {
    .ops = &can_dev_ops,
    .config = CAN_DEFAULT_CONFIG,
};

void FDCAN1_IT0_IRQHandler(void)
{
    HAL_FDCAN_IRQHandler(&hfdcan1);
}

void FDCAN1_IT1_IRQHandler(void)
{
    HAL_FDCAN_IRQHandler(&hfdcan1);
}

void FDCAN2_IT0_IRQHandler(void)
{
    HAL_FDCAN_IRQHandler(&hfdcan2);
}

void FDCAN2_IT1_IRQHandler(void)
{
    HAL_FDCAN_IRQHandler(&hfdcan2);
}

/**
 * @brief FDCAN MSP Initialization
 * This function configures the hardware resources used in this example
 * @param hfdcan: FDCAN handle pointer
 * @retval None
 */
void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* hfdcan)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (hfdcan->Instance == FDCAN1) {
        LL_RCC_SetFDCANClockSource(LL_RCC_FDCAN_CLKSOURCE_PLL1Q);

        /* Peripheral clock enable */
        HAL_RCC_FDCAN_CLK_ENABLED++;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 1) {
            __HAL_RCC_FDCAN_CLK_ENABLE();
        }

        __HAL_RCC_GPIOD_CLK_ENABLE();
        /**FDCAN1 GPIO Configuration
        PD0     ------> FDCAN1_RX
        PD1     ------> FDCAN1_TX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    } else if (hfdcan->Instance == FDCAN2) {
        LL_RCC_SetFDCANClockSource(LL_RCC_FDCAN_CLKSOURCE_PLL1Q);

        /* Peripheral clock enable */
        HAL_RCC_FDCAN_CLK_ENABLED++;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 1) {
            __HAL_RCC_FDCAN_CLK_ENABLE();
        }

        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**FDCAN2 GPIO Configuration
        PB12     ------> FDCAN2_RX
        PB13     ------> FDCAN2_TX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    }
}

/**
 * @brief FDCAN MSP De-Initialization
 * This function freeze the hardware resources used in this example
 * @param hfdcan: FDCAN handle pointer
 * @retval None
 */
void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* hfdcan)
{
    if (hfdcan->Instance == FDCAN1) {
        HAL_RCC_FDCAN_CLK_ENABLED--;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 0) {
            __HAL_RCC_FDCAN_CLK_DISABLE();
        }

        /**FDCAN1 GPIO Configuration
        PD0     ------> FDCAN1_RX
        PD1     ------> FDCAN1_TX
        */
        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0 | GPIO_PIN_1);
    } else if (hfdcan->Instance == FDCAN2) {
        HAL_RCC_FDCAN_CLK_ENABLED--;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 0) {
            __HAL_RCC_FDCAN_CLK_DISABLE();
        }

        /**FDCAN2 GPIO Configuration
        PB12     ------> FDCAN2_RX
        PB13     ------> FDCAN2_TX
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_13);
    }
}

/**
 * @brief  Rx FIFO 0 callback.
 * @param  hfdcan: pointer to an FDCAN_HandleTypeDef structure that contains
 *         the configuration information for the specified FDCAN.
 * @param  RxFifo0ITs: indicates which Rx FIFO 0 interrupts are signalled.
 *                     This parameter can be any combination of @arg FDCAN_Rx_Fifo0_Interrupts.
 * @retval None
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef* hfdcan, uint32_t RxFifo0ITs)
{
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[16];

    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
        /* Retrieve Rx messages from RX FIFO0 */
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK) {
            can_msg msg;

            msg.std_id = RxHeader.Identifier;
            msg.ext_id = RxHeader.Identifier;
            msg.id_type = RxHeader.IdType == FDCAN_EXTENDED_ID ? CAN_ID_EXTENDED : CAN_ID_STANDARD;
            msg.frame_type = RxHeader.RxFrameType == FDCAN_REMOTE_FRAME ? CAN_FRAME_REMOTE : CAN_FRAME_DATA;
            msg.data_len = RxHeader.DataLength;
            memcpy(msg.data, RxData, msg.data_len);

            if (hfdcan == &hfdcan1)
                hal_can_notify(&can1_dev, CAN_EVENT_RX_IND, &msg);
            else if ((hfdcan == &hfdcan2))
                hal_can_notify(&can2_dev, CAN_EVENT_RX_IND, &msg);
        }

        /* Enable FDCAN_IT_RX_FIFO0_NEW_MESSAGE interrupt */
        if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
            /* Notification Error */
        }
    }
}

void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef* hfdcan)
{
    /* notify tx complete */
    if (hfdcan == &hfdcan1)
        hal_can_notify(&can1_dev, CAN_EVENT_TX_DONE, RT_NULL);
    else if (hfdcan == &hfdcan2)
        hal_can_notify(&can2_dev, CAN_EVENT_TX_DONE, RT_NULL);
}

void HAL_FDCAN_ErrorStatusCallback(FDCAN_HandleTypeDef* hfdcan, uint32_t ErrorStatusITs)
{
    if ((ErrorStatusITs & FDCAN_IT_BUS_OFF) != RESET) {
        /* recover from bus-off */
        CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_INIT);
    }
}

static rt_err_t can_configure(can_dev_t can, struct can_configure* cfg)
{
    FDCAN_HandleTypeDef* hfdcan = (FDCAN_HandleTypeDef*)can->parent.user_data;
    /* The basic can baudrate is 1000K bps */
    uint32_t scaler = CAN_BAUD_RATE_1000K / (cfg->baud_rate > CAN_BAUD_RATE_1000K ? CAN_BAUD_RATE_1000K : cfg->baud_rate);

    hfdcan->Instance = can == &can1_dev ? FDCAN1 : FDCAN2;
    hfdcan->Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan->Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan->Init.AutoRetransmission = DISABLE;
    hfdcan->Init.TransmitPause = DISABLE;
    hfdcan->Init.ProtocolException = DISABLE;
    hfdcan->Init.NominalPrescaler = 6 * scaler;
    hfdcan->Init.NominalSyncJumpWidth = 1;
    hfdcan->Init.NominalTimeSeg1 = 5;
    hfdcan->Init.NominalTimeSeg2 = 2;
    hfdcan->Init.DataPrescaler = 1;
    hfdcan->Init.DataSyncJumpWidth = 1;
    hfdcan->Init.DataTimeSeg1 = 1;
    hfdcan->Init.DataTimeSeg2 = 1;
    hfdcan->Init.MessageRAMOffset = 0;
    hfdcan->Init.StdFiltersNbr = 1;
    hfdcan->Init.ExtFiltersNbr = 0;
    hfdcan->Init.RxFifo0ElmtsNbr = 32;
    hfdcan->Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan->Init.RxFifo1ElmtsNbr = 0;
    hfdcan->Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan->Init.RxBuffersNbr = 0;
    hfdcan->Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan->Init.TxEventsNbr = 0;
    hfdcan->Init.TxBuffersNbr = 0;
    hfdcan->Init.TxFifoQueueElmtsNbr = 10;
    hfdcan->Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan->Init.TxElmtSize = FDCAN_DATA_BYTES_8;
    if (HAL_FDCAN_Init(hfdcan) != HAL_OK) {
        return RT_ERROR;
    }

    /* Configure Rx filter */
    FDCAN_FilterTypeDef sFilterConfig;
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    /* Accept all id */
    sFilterConfig.FilterID1 = 0x000;
    sFilterConfig.FilterID2 = 0x000;
    if (HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig) != HAL_OK) {
        /* Filter configuration Error */
        return RT_ERROR;
    }

    /* Configure global filter to reject all non-matching frames */
    HAL_FDCAN_ConfigGlobalFilter(hfdcan, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);
    // HAL_FDCAN_ConfigGlobalFilter(hfdcan, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);

    /* Start the FDCAN module */
    if (HAL_FDCAN_Start(hfdcan) != HAL_OK) {
        /* Start Error */
        return RT_ERROR;
    }

    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
        /* Notification Error */
        return RT_ERROR;
    }

    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_BUS_OFF, 0) != HAL_OK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t can_control(can_dev_t can, int cmd, void* arg)
{
    switch (cmd) {
    case CAN_OPEN_DEVICE:
        if (can->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
            if (can == &can1_dev) {
                HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 1, 1);
                HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
            } else if (can == &can2_dev) {
                HAL_NVIC_SetPriority(FDCAN2_IT0_IRQn, 1, 1);
                HAL_NVIC_EnableIRQ(FDCAN2_IT0_IRQn);
            }
        }
        break;

    case CAN_CLOSE_DEVICE:
        if (can->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
            if (can == &can1_dev) {
                HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
            } else if (can == &can2_dev) {
                HAL_NVIC_DisableIRQ(FDCAN2_IT0_IRQn);
            }
        }
        break;

    case CAN_SET_RX_FILTER: {
        FDCAN_FilterTypeDef sFilterConfig;
        struct can_filter* filter = (struct can_filter*)arg;
        FDCAN_HandleTypeDef* hfdcan = (FDCAN_HandleTypeDef*)can->parent.user_data;

        if (filter->filter_type == CAN_FILTER_TYPE_MASK) {
            sFilterConfig.FilterType = FDCAN_FILTER_MASK;
        } else if (filter->filter_type == CAN_FILTER_TYPE_RANGE) {
            sFilterConfig.FilterType = FDCAN_FILTER_RANGE;
        } else {
            return RT_EINVAL;
        }

        /* Configure Rx filter */
        sFilterConfig.IdType = FDCAN_STANDARD_ID;
        sFilterConfig.FilterIndex = 0;
        sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
        sFilterConfig.FilterID1 = filter->filter_id1;
        sFilterConfig.FilterID2 = filter->filter_id2;
        if (HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig) != HAL_OK) {
            /* Filter configuration Error */
            return RT_ERROR;
        }
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static int send_canmsg(can_dev_t can, const can_msg_t msg)
{
    FDCAN_HandleTypeDef* hfdcan = (FDCAN_HandleTypeDef*)can->parent.user_data;
    FDCAN_TxHeaderTypeDef TxHeader;

    /* Prepare Tx Header */
    TxHeader.Identifier = msg->std_id;
    TxHeader.IdType = msg->id_type == CAN_ID_EXTENDED ? FDCAN_EXTENDED_ID : FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = msg->frame_type == CAN_FRAME_REMOTE ? FDCAN_REMOTE_FRAME : FDCAN_DATA_FRAME;
    TxHeader.DataLength = msg->data_len;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = DISABLE;
    TxHeader.FDFormat = DISABLE;

    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    if (HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &TxHeader, msg->data) == HAL_OK) {
        /* Enable FDCAN_IT_TX_FIFO_EMPTY interrupt */
        if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_TX_FIFO_EMPTY, 0) == HAL_OK) {
            return 1;
        }
    }

    return 0;
}

static int recv_canmsg(can_dev_t can, can_msg_t msg)
{
    FDCAN_HandleTypeDef* hfdcan = (FDCAN_HandleTypeDef*)can->parent.user_data;
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[16];

    /* Retrieve Rx messages from RX FIFO0 */
    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK) {
        msg->std_id = RxHeader.Identifier;
        msg->ext_id = RxHeader.Identifier;
        msg->id_type = RxHeader.IdType == FDCAN_EXTENDED_ID ? CAN_ID_EXTENDED : CAN_ID_STANDARD;
        msg->frame_type = RxHeader.RxFrameType == FDCAN_REMOTE_FRAME ? CAN_FRAME_REMOTE : CAN_FRAME_DATA;
        msg->data_len = RxHeader.DataLength;
        memcpy(msg->data, RxData, msg->data_len);

        return 1;
    }
    return 0;
}

rt_err_t drv_fdcan_init(void)
{
    RT_TRY(hal_can_register(&can1_dev, "can1", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX, &hfdcan1));
    RT_TRY(hal_can_register(&can2_dev, "can2", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX, &hfdcan2));

    return RT_EOK;
}
