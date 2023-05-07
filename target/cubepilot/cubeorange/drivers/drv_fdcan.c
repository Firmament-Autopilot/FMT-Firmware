#include "drv_fdcan.h"
#include "board.h"
#include "hal/can/can.h"

#include "canard_stm32H7.h"

FDCAN_HandleTypeDef hfdcan1;

/* stm32 can device */
struct stm32_fdcan {
    FDCanID canid;
};

static can_device fdcan_dev1;
struct stm32_fdcan stm32_fdcan1 = {
    .canid = can1
};

////////////////////////////////////////////////////////////////////////////////////
static uint32_t HAL_RCC_FDCAN_CLK_ENABLED = 0;

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (fdcanHandle->Instance == FDCAN1) {
        /* USER CODE BEGIN FDCAN1_MspInit 0 */

        /* USER CODE END FDCAN1_MspInit 0 */
        /* FDCAN1 clock enable */
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
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* FDCAN1 interrupt Init */
        // HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 0);
        // HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
        /* USER CODE BEGIN FDCAN1_MspInit 1 */

        /* USER CODE END FDCAN1_MspInit 1 */
    } else if (fdcanHandle->Instance == FDCAN2) {
        /* USER CODE BEGIN FDCAN2_MspInit 0 */

        /* USER CODE END FDCAN2_MspInit 0 */
        /* FDCAN2 clock enable */
        HAL_RCC_FDCAN_CLK_ENABLED++;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 1) {
            __HAL_RCC_FDCAN_CLK_ENABLE();
        }

        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**FDCAN2 GPIO Configuration
        PB12     ------> FDCAN2_RX
        PB6     ------> FDCAN2_TX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* FDCAN2 interrupt Init */
        // HAL_NVIC_SetPriority(FDCAN2_IT0_IRQn, 0, 0);
        // HAL_NVIC_EnableIRQ(FDCAN2_IT0_IRQn);
        /* USER CODE BEGIN FDCAN2_MspInit 1 */

        /* USER CODE END FDCAN2_MspInit 1 */
    }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

    if (fdcanHandle->Instance == FDCAN1) {
        /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

        /* USER CODE END FDCAN1_MspDeInit 0 */
        /* Peripheral clock disable */
        HAL_RCC_FDCAN_CLK_ENABLED--;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 0) {
            __HAL_RCC_FDCAN_CLK_DISABLE();
        }

        /**FDCAN1 GPIO Configuration
        PD0     ------> FDCAN1_RX
        PD1     ------> FDCAN1_TX
        */
        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0 | GPIO_PIN_1);

        /* FDCAN1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
        /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

        /* USER CODE END FDCAN1_MspDeInit 1 */
    } else if (fdcanHandle->Instance == FDCAN2) {
        /* USER CODE BEGIN FDCAN2_MspDeInit 0 */

        /* USER CODE END FDCAN2_MspDeInit 0 */
        /* Peripheral clock disable */
        HAL_RCC_FDCAN_CLK_ENABLED--;
        if (HAL_RCC_FDCAN_CLK_ENABLED == 0) {
            __HAL_RCC_FDCAN_CLK_DISABLE();
        }

        /**FDCAN2 GPIO Configuration
        PB12     ------> FDCAN2_RX
        PB6     ------> FDCAN2_TX
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_6);

        /* FDCAN2 interrupt Deinit */
        HAL_NVIC_DisableIRQ(FDCAN2_IT0_IRQn);
        /* USER CODE BEGIN FDCAN2_MspDeInit 1 */

        /* USER CODE END FDCAN2_MspDeInit 1 */
    }
}

static rt_err_t fdcan_baud_rate_configure(FDCAN_HandleTypeDef* fdcanHandle, rt_int32_t baud)
{

    return RT_EOK;
}

static int fdcan_sendmsg(can_dev_t fdcan_dev, const void* buf)
{
    struct stm32_fdcan* stm32_fdcan_x = (struct stm32_fdcan*)fdcan_dev->parent.user_data;
    RT_ASSERT(stm32_fdcan_x != RT_NULL);

    can_msg_t msg_t = (can_msg_t)buf;

    return msg_t->len;
}

static int fdcan_recvmsg(can_dev_t fdcan_dev, void* buf)
{
    struct stm32_fdcan* stm32_fdcan_x = (struct stm32_fdcan*)fdcan_dev->parent.user_data;
    RT_ASSERT(stm32_fdcan_x != RT_NULL);

    CanardCANFrame* out_frame = (CanardCANFrame*)buf;

    // printf("data_len1 =%d\n", out_frame->data_len);

    int16_t ret = fdCANReceive(stm32_fdcan_x->canid, out_frame);

    // printf("ret=%d,data_len2 =%d\n", ret, out_frame->data_len);

    return out_frame->data_len;
}

static rt_err_t fdcan_configure(can_dev_t fdcan_dev, struct can_configure* cfg)
{
    struct stm32_fdcan* stm32_fdcan_x = (struct stm32_fdcan*)fdcan_dev->parent.user_data;

    RT_ASSERT(stm32_fdcan_x != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    // fdcan_baud_rate_configure(stm32_fdcan_x->fdcan_handler, cfg->baud_rate);

    // #endif
    return RT_EOK;
}

static const struct can_ops _fdcan_ops = {
    .configure = fdcan_configure,
    .sendmsg = fdcan_sendmsg,
    .recvmsg = fdcan_recvmsg,
};

static rt_err_t fdcan_init(void)
{
#if FDCAN_NUM_IFACES == 1

    HAL_FDCAN_DeInit(&hfdcan1); // 先清除以前的设置

    hfdcan1.Instance = FDCAN1;
    hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan1.Init.AutoRetransmission = DISABLE;
    hfdcan1.Init.TransmitPause = DISABLE;
    hfdcan1.Init.ProtocolException = DISABLE;
    hfdcan1.Init.NominalPrescaler = 4;
    hfdcan1.Init.NominalSyncJumpWidth = 8;
    hfdcan1.Init.NominalTimeSeg1 = 8;
    hfdcan1.Init.NominalTimeSeg2 = 3;
    hfdcan1.Init.DataPrescaler = 4;
    hfdcan1.Init.DataSyncJumpWidth = 8;
    hfdcan1.Init.DataTimeSeg1 = 8;
    hfdcan1.Init.DataTimeSeg2 = 3;
    hfdcan1.Init.MessageRAMOffset = 0;
    hfdcan1.Init.StdFiltersNbr = 10;
    hfdcan1.Init.ExtFiltersNbr = 1;
    hfdcan1.Init.RxFifo0ElmtsNbr = 64;
    hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxFifo1ElmtsNbr = 0;
    hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxBuffersNbr = 0;
    hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.TxEventsNbr = 0;
    hfdcan1.Init.TxBuffersNbr = 0;
    hfdcan1.Init.TxFifoQueueElmtsNbr = 16;
    hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
    if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK) {
        Error_Handler();
        // return RT_ERROR;
    }

    // systime_mdelay(1000);

    FdCANTimings can1_timing;
    fdCANComputeTimings(FDCAN_CLOCK, FDCAN_TARGET_CLOCK, &can1_timing);
    fdCANInit(can1_timing, can1);

#elif FDCAN_NUM_IFACES == 2
    FdCANTimings can2_timing;
    fdCANComputeTimings(FDCAN_CLOCK, FDCAN_TARGET_CLOCK, &can2_timing);
    fdCANInit(can2_timing, can2);
#endif
    return RT_EOK;
}

rt_err_t drv_fdcan_init(void)
{
    RT_CHECK(fdcan_init());

    struct can_configure config = CAN_DEFAULT_CONFIG;

    fdcan_dev1.ops = &_fdcan_ops;
    fdcan_dev1.config = config;

    hw_can_register(&fdcan_dev1, "fdcan1", 0, &stm32_fdcan1);

#if FDCAN_NUM_IFACES == 2
    fdcan_dev2.ops = &_fdcan_ops;
    fdcan_dev2.config = config;

    hw_can_register(&fdcan_dev2, "fdcan2", 0, &stm32_fdcan2);
#endif

    return RT_EOK;
}
