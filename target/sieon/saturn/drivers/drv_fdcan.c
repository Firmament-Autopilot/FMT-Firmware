#include "drv_fdcan.h"
#include "board.h"
#include "hal/can/can.h"

FDCAN_HandleTypeDef hfdcan1;

static int send_canmsg(can_dev_t can, const can_msg_t msg);
static int recv_canmsg(can_dev_t can, can_msg_t msg);

const static struct can_ops can_dev_ops = {
    .configure = NULL,
    .control = NULL,
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
        /* USER CODE BEGIN FDCAN1_MspInit 0 */

        /* USER CODE END FDCAN1_MspInit 0 */
        LL_RCC_SetFDCANClockSource(LL_RCC_FDCAN_CLKSOURCE_PLL1Q);

        /* Peripheral clock enable */
        __HAL_RCC_FDCAN_CLK_ENABLE();

        __HAL_RCC_GPIOH_CLK_ENABLE();
        /**FDCAN1 GPIO Configuration
        PH13     ------> FDCAN1_TX
        PH14     ------> FDCAN1_RX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_13 | GPIO_PIN_14;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
        HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

        /* FDCAN1 interrupt Init */
        // HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 0);
        // HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
        // HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 0, 0);
        // HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);
        /* USER CODE BEGIN FDCAN1_MspInit 1 */

        /* USER CODE END FDCAN1_MspInit 1 */
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
        /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

        /* USER CODE END FDCAN1_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_FDCAN_CLK_DISABLE();

        /**FDCAN1 GPIO Configuration
        PH13     ------> FDCAN1_TX
        PH14     ------> FDCAN1_RX
        */
        HAL_GPIO_DeInit(GPIOH, GPIO_PIN_13 | GPIO_PIN_14);

        /* FDCAN1 interrupt DeInit */
        /* FDCAN1 interrupt Init */

        // HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 1);
        // HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
        // HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 0, 1);
        // HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);

        /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

        /* USER CODE END FDCAN1_MspDeInit 1 */
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

            hal_can_notify(&can1_dev, CAN_EVENT_RX_IND, &msg);
        }

        /* Enable FDCAN_IT_RX_FIFO0_NEW_MESSAGE interrupt */
        if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
            /* Notification Error */
        }
    }
}

static rt_err_t fdcan_init(void)
{
    hfdcan1.Instance = FDCAN1;
    hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan1.Init.AutoRetransmission = DISABLE;
    hfdcan1.Init.TransmitPause = DISABLE;
    hfdcan1.Init.ProtocolException = DISABLE;
    hfdcan1.Init.NominalPrescaler = 6;
    hfdcan1.Init.NominalSyncJumpWidth = 1;
    hfdcan1.Init.NominalTimeSeg1 = 5;
    hfdcan1.Init.NominalTimeSeg2 = 2;
    hfdcan1.Init.DataPrescaler = 1;
    hfdcan1.Init.DataSyncJumpWidth = 1;
    hfdcan1.Init.DataTimeSeg1 = 1;
    hfdcan1.Init.DataTimeSeg2 = 1;
    hfdcan1.Init.MessageRAMOffset = 0;
    hfdcan1.Init.StdFiltersNbr = 1;
    hfdcan1.Init.ExtFiltersNbr = 0;
    hfdcan1.Init.RxFifo0ElmtsNbr = 10;
    hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxFifo1ElmtsNbr = 0;
    hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxBuffersNbr = 0;
    hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.TxEventsNbr = 0;
    hfdcan1.Init.TxBuffersNbr = 0;
    hfdcan1.Init.TxFifoQueueElmtsNbr = 10;
    hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
    if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK) {
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
    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK) {
        /* Filter configuration Error */
        return RT_ERROR;
    }

    /* Configure global filter to reject all non-matching frames */
    HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);
    // HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);

    /* Start the FDCAN module */
    if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK) {
        /* Start Error */
        return RT_ERROR;
    }

    if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
        /* Notification Error */
        return RT_ERROR;
    }

    return RT_EOK;
}

static int send_canmsg(can_dev_t can, const can_msg_t msg)
{
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

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, msg->data) == HAL_OK) {
        /* can msg has been put to tx fifo, notify tx complete */
        hal_can_notify(&can1_dev, CAN_EVENT_TX_DONE, RT_NULL);
        return 1;
    }

    /* in this case we also notify tx done to release tx cplt wait */
    hal_can_notify(&can1_dev, CAN_EVENT_TX_DONE, RT_NULL);

    return 0;
}

static int recv_canmsg(can_dev_t can, can_msg_t msg)
{
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[16];

    if (can == &can1_dev) {
        /* Retrieve Rx messages from RX FIFO0 */
        if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK) {
            msg->std_id = RxHeader.Identifier;
            msg->ext_id = RxHeader.Identifier;
            msg->id_type = RxHeader.IdType == FDCAN_EXTENDED_ID ? CAN_ID_EXTENDED : CAN_ID_STANDARD;
            msg->frame_type = RxHeader.RxFrameType == FDCAN_REMOTE_FRAME ? CAN_FRAME_REMOTE : CAN_FRAME_DATA;
            msg->data_len = RxHeader.DataLength;
            memcpy(msg->data, RxData, msg->data_len);

            return 1;
        }
    } else if (can == &can2_dev) {
    }

    return 0;
}

rt_err_t drv_fdcan_init(void)
{
    RT_TRY(fdcan_init());

    RT_TRY(hal_can_register(&can1_dev, "can1", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX, NULL));

    return RT_EOK;
}
