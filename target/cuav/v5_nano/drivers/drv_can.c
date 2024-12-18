/******************************************************************************
 * Copyright 2024 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>
#include <string.h>

#include "drv_can.h"
#include "hal/can/can.h"
#include "stm32f7xx_hal_can.h"

// #define CAN_DRV_DBG(...) printf(__VA_ARGS__)
#define CAN_DRV_DBG(...)

static rt_err_t can_config(can_dev_t can, struct can_configure* cfg);
static rt_err_t can_control(can_dev_t can, int cmd, void* arg);
static int can_sendmsg(can_dev_t can, const can_msg_t msg);
static int can_recvmsg(can_dev_t can, can_msg_t msg);

static struct can_data {
    CAN_HandleTypeDef hcan;
    CAN_FilterTypeDef filter;
    CAN_TxHeaderTypeDef tx_header;
    CAN_RxHeaderTypeDef rx_header;
    uint8_t tx_data[8];
    uint8_t rx_data[8];
    uint32_t tx_mailbox;
} can1_data, can2_data;

const static struct can_ops can_dev_ops = {
    .configure = can_config,
    .control = can_control,
    .sendmsg = can_sendmsg,
    .recvmsg = can_recvmsg
};

static can_device can1_dev = {
    .ops = &can_dev_ops,
    .config = CAN_DEFAULT_CONFIG,
};

static can_device can2_dev = {
    .ops = &can_dev_ops,
    .config = CAN_DEFAULT_CONFIG,
};

static uint32_t HAL_RCC_CAN1_CLK_ENABLED = 0;

/**
 * @brief This function handles CAN1 TX interrupts.
 */
void CAN1_TX_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_CAN_IRQHandler(&can1_data.hcan);

    /* leave interrupt */
    rt_interrupt_leave();
}

/**
 * @brief This function handles CAN1 RX0 interrupts.
 */
void CAN1_RX0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_CAN_IRQHandler(&can1_data.hcan);

    /* leave interrupt */
    rt_interrupt_leave();
}

/**
 * @brief This function handles CAN2 TX interrupts.
 */
void CAN2_TX_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_CAN_IRQHandler(&can2_data.hcan);

    /* leave interrupt */
    rt_interrupt_leave();
}

/**
 * @brief This function handles CAN2 RX0 interrupts.
 */
void CAN2_RX0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_CAN_IRQHandler(&can2_data.hcan);

    /* leave interrupt */
    rt_interrupt_leave();
}

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef* hcan)
{
    if (hcan->Instance == CAN1) {
        CAN_DRV_DBG("can1 tx cplt\n");
        hal_can_notify(&can1_dev, CAN_EVENT_TX_DONE, RT_NULL);
    } else if (hcan->Instance == CAN2) {
        CAN_DRV_DBG("can2 tx cplt\n");
        hal_can_notify(&can2_dev, CAN_EVENT_TX_DONE, RT_NULL);
    } else {
        /* do nothing */
        CAN_DRV_DBG("unknown can device cplt\n");
    }
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan)
{
    can_msg msg;

    if (hcan->Instance == CAN1) {
        CAN_DRV_DBG("can1 rx fifo pending\n");

        if (HAL_CAN_GetRxMessage(hcan, CAN_FILTER_FIFO0, &can1_data.rx_header, can1_data.rx_data) != HAL_OK)
            return;

        msg.std_id = can1_data.rx_header.StdId;
        msg.ext_id = can1_data.rx_header.ExtId;
        msg.id_type = can1_data.rx_header.IDE == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
        msg.frame_type = can1_data.rx_header.RTR == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
        msg.data_len = can1_data.rx_header.DLC;
        memcpy(msg.data, can1_data.rx_data, sizeof(msg.data));

        hal_can_notify(&can1_dev, CAN_EVENT_RX_IND, &msg);
    } else if (hcan->Instance == CAN2) {
        CAN_DRV_DBG("can2 rx fifo pending\n");

        if (HAL_CAN_GetRxMessage(hcan, CAN_FILTER_FIFO0, &can2_data.rx_header, can2_data.rx_data) != HAL_OK)
            return;

        msg.std_id = can2_data.rx_header.StdId;
        msg.ext_id = can2_data.rx_header.ExtId;
        msg.id_type = can2_data.rx_header.IDE == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
        msg.frame_type = can2_data.rx_header.RTR == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
        msg.data_len = can2_data.rx_header.DLC;
        memcpy(msg.data, can2_data.rx_data, sizeof(msg.data));

        hal_can_notify(&can2_dev, CAN_EVENT_RX_IND, &msg);
    } else {
        CAN_DRV_DBG("unknown can device rx fifo pending\n");
    }
}

void HAL_CAN_ErrorCallback(CAN_HandleTypeDef* hcan)
{
    if (hcan->Instance == CAN1) {
        if (hcan->ErrorCode & HAL_CAN_ERROR_TX_ALST0 || hcan->ErrorCode & HAL_CAN_ERROR_TX_TERR0) {
            CAN_DRV_DBG("can1 tx error!\n");
            hal_can_notify(&can1_dev, CAN_EVENT_TX_DONE, RT_NULL);
        }
    } else if (hcan->Instance == CAN2) {
        if (hcan->ErrorCode & HAL_CAN_ERROR_TX_ALST0 || hcan->ErrorCode & HAL_CAN_ERROR_TX_TERR0) {
            CAN_DRV_DBG("can2 tx error!\n");
            hal_can_notify(&can2_dev, CAN_EVENT_TX_DONE, RT_NULL);
        }
    }
}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    if (canHandle->Instance == CAN1) {
        /* USER CODE BEGIN CAN1_MspInit 0 */

        /* USER CODE END CAN1_MspInit 0 */
        /* CAN1 clock enable */
        HAL_RCC_CAN1_CLK_ENABLED++;
        if (HAL_RCC_CAN1_CLK_ENABLED == 1) {
            __HAL_RCC_CAN1_CLK_ENABLE();
        }

        __HAL_RCC_GPIOI_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        /**CAN1 GPIO Configuration
        PI9     ------> CAN1_RX
        PH13     ------> CAN1_TX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
        HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
        HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

        /* CAN1 interrupt Init */
        HAL_NVIC_SetPriority(CAN1_TX_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN1_TX_IRQn);
        HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
        /* USER CODE BEGIN CAN1_MspInit 1 */

        /* Set silent pin to low to activate can transceiver */
        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_2, GPIO_PIN_RESET);

        /* USER CODE END CAN1_MspInit 1 */
    } else if (canHandle->Instance == CAN2) {
        /* USER CODE BEGIN CAN2_MspInit 0 */

        /* USER CODE END CAN2_MspInit 0 */
        /* CAN2 clock enable */
        HAL_RCC_CAN1_CLK_ENABLED++;
        if (HAL_RCC_CAN1_CLK_ENABLED == 1) {
            __HAL_RCC_CAN1_CLK_ENABLE();
        }
        __HAL_RCC_CAN3_CLK_ENABLE();
        __HAL_RCC_CAN2_CLK_ENABLE();

        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**CAN2 GPIO Configuration
        PB12     ------> CAN2_RX
        PB13     ------> CAN2_TX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* CAN2 interrupt Init */
        HAL_NVIC_SetPriority(CAN2_TX_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN2_TX_IRQn);
        HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
        /* USER CODE BEGIN CAN2_MspInit 1 */

        __HAL_RCC_GPIOH_CLK_ENABLE();
        /* Set silent pin to low to activate can transceiver */
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_3, GPIO_PIN_RESET);

        /* USER CODE END CAN2_MspInit 1 */
    }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{
    if (canHandle->Instance == CAN1) {
        /* USER CODE BEGIN CAN1_MspDeInit 0 */

        /* USER CODE END CAN1_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_CAN1_CLK_DISABLE();

        /**CAN1 GPIO Configuration
        PI9     ------> CAN1_RX
        PH13     ------> CAN1_TX
        */
        HAL_GPIO_DeInit(GPIOI, GPIO_PIN_9);

        HAL_GPIO_DeInit(GPIOH, GPIO_PIN_13);

        /* CAN1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(CAN1_TX_IRQn);
        HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
        /* USER CODE BEGIN CAN1_MspDeInit 1 */

        /* USER CODE END CAN1_MspDeInit 1 */
    } else if (canHandle->Instance == CAN2) {
        /* USER CODE BEGIN CAN2_MspDeInit 0 */

        /* USER CODE END CAN2_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_CAN3_CLK_DISABLE();
        __HAL_RCC_CAN2_CLK_DISABLE();
        HAL_RCC_CAN1_CLK_ENABLED--;
        if (HAL_RCC_CAN1_CLK_ENABLED == 0) {
            __HAL_RCC_CAN1_CLK_DISABLE();
        }

        /**CAN2 GPIO Configuration
        PB12     ------> CAN2_RX
        PB13     ------> CAN2_TX
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_13);

        /* CAN2 interrupt Deinit */
        HAL_NVIC_DisableIRQ(CAN2_TX_IRQn);
        HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
        /* USER CODE BEGIN CAN2_MspDeInit 1 */

        /* USER CODE END CAN2_MspDeInit 1 */
    }
}

static rt_err_t can_config(can_dev_t can, struct can_configure* cfg)
{
    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    if (can == &can1_dev) {
        /* Configure the CAN1 peripheral, 1Mbps */
        can1_data.hcan.Instance = CAN1;
        can1_data.hcan.Init.Prescaler = 6;
        can1_data.hcan.Init.Mode = CAN_MODE_NORMAL;
        can1_data.hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
        can1_data.hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
        can1_data.hcan.Init.TimeSeg2 = CAN_BS2_3TQ;
        can1_data.hcan.Init.TimeTriggeredMode = DISABLE;
        can1_data.hcan.Init.AutoBusOff = ENABLE;
        can1_data.hcan.Init.AutoWakeUp = DISABLE;
        can1_data.hcan.Init.AutoRetransmission = DISABLE;
        can1_data.hcan.Init.ReceiveFifoLocked = DISABLE;
        can1_data.hcan.Init.TransmitFifoPriority = DISABLE;
        if (HAL_CAN_Init(&can1_data.hcan) != HAL_OK)
            return RT_ERROR;

        /* Configure the CAN filter */
        can1_data.filter.FilterBank = 0;
        can1_data.filter.FilterMode = CAN_FILTERMODE_IDMASK;
        can1_data.filter.FilterScale = CAN_FILTERSCALE_32BIT;
        can1_data.filter.FilterIdHigh = 0x0000;
        can1_data.filter.FilterIdLow = 0x0000;
        can1_data.filter.FilterMaskIdHigh = 0x0000;
        can1_data.filter.FilterMaskIdLow = 0x0000;
        can1_data.filter.FilterFIFOAssignment = CAN_RX_FIFO0;
        can1_data.filter.FilterActivation = ENABLE;
        can1_data.filter.SlaveStartFilterBank = 0;
        if (HAL_CAN_ConfigFilter(&can1_data.hcan, &can1_data.filter) != HAL_OK)
            return RT_ERROR;

        /* Acticate TX/RX interrupt */
        if (HAL_CAN_ActivateNotification(&can1_data.hcan, CAN_IT_TX_MAILBOX_EMPTY | CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
            return RT_ERROR;
    } else if (can == &can2_dev) {
        /* Configure the CAN2 peripheral, 1Mbps */
        can2_data.hcan.Instance = CAN2;
        can2_data.hcan.Init.Prescaler = 6;
        can2_data.hcan.Init.Mode = CAN_MODE_NORMAL;
        can2_data.hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
        can2_data.hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
        can2_data.hcan.Init.TimeSeg2 = CAN_BS2_3TQ;
        can2_data.hcan.Init.TimeTriggeredMode = DISABLE;
        can2_data.hcan.Init.AutoBusOff = ENABLE;
        can2_data.hcan.Init.AutoWakeUp = DISABLE;
        can2_data.hcan.Init.AutoRetransmission = DISABLE;
        can2_data.hcan.Init.ReceiveFifoLocked = DISABLE;
        can2_data.hcan.Init.TransmitFifoPriority = DISABLE;
        if (HAL_CAN_Init(&can2_data.hcan) != HAL_OK)
            return RT_ERROR;

        /* Configure the CAN filter */
        can2_data.filter.FilterBank = 14;
        can2_data.filter.FilterMode = CAN_FILTERMODE_IDMASK;
        can2_data.filter.FilterScale = CAN_FILTERSCALE_32BIT;
        can2_data.filter.FilterIdHigh = 0x0000;
        can2_data.filter.FilterIdLow = 0x0000;
        can2_data.filter.FilterMaskIdHigh = 0x0000;
        can2_data.filter.FilterMaskIdLow = 0x0000;
        can2_data.filter.FilterFIFOAssignment = CAN_RX_FIFO0;
        can2_data.filter.FilterActivation = ENABLE;
        can2_data.filter.SlaveStartFilterBank = 14;
        if (HAL_CAN_ConfigFilter(&can2_data.hcan, &can2_data.filter) != HAL_OK)
            return RT_ERROR;

        /* Acticate TX/RX interrupt */
        if (HAL_CAN_ActivateNotification(&can2_data.hcan, CAN_IT_TX_MAILBOX_EMPTY | CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
            return RT_ERROR;
    } else {
        /* unsupported deice */
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t can_control(can_dev_t can, int cmd, void* arg)
{
    RT_ASSERT(can != RT_NULL);

    struct can_data* data = (struct can_data*)can->parent.user_data;

    switch (cmd) {
    case CAN_OPEN_DEVICE:
        if (HAL_CAN_Start(&data->hcan) != HAL_OK)
            return RT_ERROR;
        break;

    case CAN_CLOSE_DEVICE:
        if (HAL_CAN_Stop(&data->hcan) != HAL_OK)
            return RT_ERROR;
        break;

    default:
        break;
    }

    return RT_EOK;
}

static int can_sendmsg(can_dev_t can, const can_msg_t msg)
{
    if (can == &can1_dev) {
        can1_data.tx_header.StdId = msg->std_id;
        can1_data.tx_header.ExtId = msg->ext_id;
        can1_data.tx_header.IDE = msg->id_type == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
        can1_data.tx_header.RTR = msg->frame_type == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
        can1_data.tx_header.DLC = msg->data_len;
        can1_data.tx_header.TransmitGlobalTime = DISABLE;

        memcpy(can1_data.tx_data, msg->data, msg->data_len);

        /* Request transmission */
        if (HAL_CAN_AddTxMessage(&can1_data.hcan, &can1_data.tx_header, can1_data.tx_data, &can1_data.tx_mailbox) == HAL_OK)
            return 1;
    } else if (can == &can2_dev) {
        can2_data.tx_header.StdId = msg->std_id;
        can2_data.tx_header.ExtId = msg->ext_id;
        can2_data.tx_header.IDE = msg->id_type == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
        can2_data.tx_header.RTR = msg->frame_type == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
        can2_data.tx_header.DLC = msg->data_len;
        can2_data.tx_header.TransmitGlobalTime = DISABLE;

        memcpy(can2_data.tx_data, msg->data, msg->data_len);

        /* Request transmission */
        if (HAL_CAN_AddTxMessage(&can2_data.hcan, &can2_data.tx_header, can2_data.tx_data, &can2_data.tx_mailbox) == HAL_OK)
            return 1;
    }

    return 0;
}

static int can_recvmsg(can_dev_t can, can_msg_t msg)
{
    if (can == &can1_dev) {
        if (HAL_CAN_GetRxMessage(&can1_data.hcan, CAN_FILTER_FIFO0, &can1_data.rx_header, can1_data.rx_data) == HAL_OK) {
            msg->std_id = can1_data.rx_header.StdId;
            msg->ext_id = can1_data.rx_header.ExtId;
            msg->id_type = can1_data.rx_header.IDE == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
            msg->frame_type = can1_data.rx_header.RTR == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
            msg->data_len = can1_data.rx_header.DLC;

            memcpy(msg->data, can1_data.rx_data, msg->data_len);

            return 1;
        }
    } else if (can == &can2_dev) {
        if (HAL_CAN_GetRxMessage(&can2_data.hcan, CAN_FILTER_FIFO0, &can2_data.rx_header, can2_data.rx_data) == HAL_OK) {
            msg->std_id = can2_data.rx_header.StdId;
            msg->ext_id = can2_data.rx_header.ExtId;
            msg->id_type = can2_data.rx_header.IDE == CAN_ID_EXTENDED ? CAN_ID_EXT : CAN_ID_STD;
            msg->frame_type = can2_data.rx_header.RTR == CAN_FRAME_REMOTE ? CAN_RTR_REMOTE : CAN_RTR_DATA;
            msg->data_len = can2_data.rx_header.DLC;

            memcpy(msg->data, can2_data.rx_data, msg->data_len);

            return 1;
        }
    }

    return 0;
}

rt_err_t drv_can_init(void)
{
    RT_TRY(hal_can_register(&can1_dev, "can1", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX, &can1_data));
    RT_TRY(hal_can_register(&can2_dev, "can2", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX, &can2_data));

    return RT_EOK;
}
