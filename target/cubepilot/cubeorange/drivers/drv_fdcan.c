#include "drv_fdcan.h"
#include "board.h"
#include "hal/can/can.h"
#include "stm32h7xx_hal_fdcan.h"

#define DRV_USE_FDCAN1
#define DRV_USE_FDCAN2

#define FDCAN_TIMEOUT        5000
#define EVENT_FDCAN1_RX_CPLT 0x00000001
#define EVENT_FDCAN2_RX_CPLT 0x00000010

#ifdef DRV_USE_FDCAN1

FDCAN_HandleTypeDef hfdcan1;

FDCAN_FilterTypeDef FDCAN1_RXFilter;

FDCAN_RxHeaderTypeDef FDCAN1_RxHeader;

FDCAN_TxHeaderTypeDef FDCAN1_TxHeader;

#endif

#ifdef DRV_USE_FDCAN2
FDCAN_HandleTypeDef hfdcan2;
FDCAN_FilterTypeDef FDCAN2_RXFilter;
FDCAN_RxHeaderTypeDef FDCAN2_RxHeader;
FDCAN_TxHeaderTypeDef FDCAN2_TxHeader;
#endif

/* stm32 can device */
struct stm32_fdcan {
    FDCAN_HandleTypeDef* fdcan_handler;
    FDCAN_FilterTypeDef* fdcan_filter;

    FDCAN_RxHeaderTypeDef* fdcan_rxheader;
    FDCAN_TxHeaderTypeDef* fdcan_txheader;

    IRQn_Type irq;
};

static can_device fdcan_dev1;
struct stm32_fdcan stm32_fdcan1 = {
    .fdcan_handler = &hfdcan1,
    .fdcan_filter = &FDCAN1_RXFilter,

    .fdcan_rxheader = &FDCAN1_RxHeader,
    .fdcan_txheader = &FDCAN1_TxHeader,

    .irq = FDCAN1_IT0_IRQn,
};

#ifdef DRV_USE_FDCAN2
static can_device fdcan_dev2;
struct stm32_fdcan stm32_fdcan2 = {
    .fdcan_handler = &hfdcan2,
    .fdcan_filter = &FDCAN2_RXFilter,

    .fdcan_rxheader = &FDCAN2_RxHeader,
    .fdcan_txheader = &FDCAN2_TxHeader,

    .irq = FDCAN2_IT0_IRQn,
};
#endif

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
        HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
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
        HAL_NVIC_SetPriority(FDCAN2_IT0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(FDCAN2_IT0_IRQn);
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

////////////////////////////////////////////////////////////////////////////////////

static rt_err_t fdacn_wait_complete(can_dev_t fdcan_dev, rt_uint32_t* status)
{
    if (rt_event_recv(&fdcan_dev->event, 0xffffffff, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, TICKS_FROM_MS(FDCAN_TIMEOUT), status) != RT_EOK) {
        /* wait timeout */
        return RT_ETIMEOUT;
    }

    return RT_EOK;
}

static rt_err_t fdcan_baud_rate_configure(FDCAN_HandleTypeDef* fdcanHandle, rt_int32_t baud)
{
    //时钟频率40M / (1 + TSG1 + TSG2) = CAN波特率
    if (baud == CAN_BAUD_RATE_1000K) {
        fdcanHandle->Init.NominalPrescaler = 4;
        fdcanHandle->Init.NominalSyncJumpWidth = 1;
        fdcanHandle->Init.NominalTimeSeg1 = 6;
        fdcanHandle->Init.NominalTimeSeg2 = 4;

        fdcanHandle->Init.DataPrescaler = 4;
        fdcanHandle->Init.DataSyncJumpWidth = 1;
        fdcanHandle->Init.DataTimeSeg1 = 6;
        fdcanHandle->Init.DataTimeSeg2 = 4;
    } else if (baud == CAN_BAUD_RATE_500K) {
        fdcanHandle->Init.NominalPrescaler = 4;
        fdcanHandle->Init.NominalSyncJumpWidth = 1;
        fdcanHandle->Init.NominalTimeSeg1 = 12;
        fdcanHandle->Init.NominalTimeSeg2 = 8;

        fdcanHandle->Init.DataPrescaler = 4;
        fdcanHandle->Init.DataSyncJumpWidth = 1;
        fdcanHandle->Init.DataTimeSeg1 = 12;
        fdcanHandle->Init.DataTimeSeg2 = 8;
    } else {
        return RT_ERROR;
    }

    return RT_EOK;
}

static int fdcan_sendmsg(can_dev_t fdcan_dev, const void* buf)
{
    struct stm32_fdcan* stm32_fdcan_x = (struct stm32_fdcan*)fdcan_dev->parent.user_data;
    RT_ASSERT(stm32_fdcan_x != RT_NULL);

    can_msg_t msg_t = (can_msg_t)buf;

    stm32_fdcan_x->fdcan_txheader->Identifier = msg_t->id;                  // 32位ID
    stm32_fdcan_x->fdcan_txheader->IdType = FDCAN_EXTENDED_ID;              //标准ID
    stm32_fdcan_x->fdcan_txheader->TxFrameType = FDCAN_DATA_FRAME;          //数据帧
    stm32_fdcan_x->fdcan_txheader->DataLength = msg_t->len << 16;           //数据长度
    stm32_fdcan_x->fdcan_txheader->BitRateSwitch = FDCAN_BRS_OFF;           //关闭速率切换
    stm32_fdcan_x->fdcan_txheader->FDFormat = FDCAN_CLASSIC_CAN;            //传统的CAN模式
    stm32_fdcan_x->fdcan_txheader->TxEventFifoControl = FDCAN_NO_TX_EVENTS; //无发送事件
    stm32_fdcan_x->fdcan_txheader->ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    stm32_fdcan_x->fdcan_txheader->MessageMarker = 0;

    if (HAL_FDCAN_AddMessageToTxFifoQ(stm32_fdcan_x->fdcan_handler,
                                      stm32_fdcan_x->fdcan_txheader,
                                      (uint8_t*)msg_t->data)
        != HAL_OK)
        return -1; //发送

    return msg_t->len;
}

static int fdcan_recvmsg(can_dev_t fdcan_dev, void* buf)
{
    rt_uint32_t status;
    rt_err_t err = RT_EOK;
    can_msg_t msg_t = (can_msg_t)buf;

    struct stm32_fdcan* stm32_fdcan_x = (struct stm32_fdcan*)fdcan_dev->parent.user_data;
    RT_ASSERT(stm32_fdcan_x != RT_NULL);

    fdacn_wait_complete(fdcan_dev, &status);

    if ((err == RT_EOK) && (status & EVENT_FDCAN1_RX_CPLT)) {
        uint32_t start = systime_now_ms();
        uint32_t now;

        while (HAL_FDCAN_GetRxMessage(stm32_fdcan_x->fdcan_handler,
                                      FDCAN_RX_FIFO0,
                                      stm32_fdcan_x->fdcan_rxheader,
                                      msg_t->data)
               != HAL_OK) {
            now = systime_now_ms();
            if (now - start > FDCAN_TIMEOUT) {
                err = RT_ETIMEOUT;
                break;
            }
            sys_msleep(1);
        }
    }

    msg_t->id = stm32_fdcan_x->fdcan_rxheader->Identifier;
    msg_t->len = stm32_fdcan_x->fdcan_rxheader->DataLength >> 16;

    return msg_t->len;
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
#ifdef DRV_USE_FDCAN1

    HAL_FDCAN_DeInit(&hfdcan1); //先清除以前的设置

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
    hfdcan1.Init.StdFiltersNbr = 0;
    hfdcan1.Init.ExtFiltersNbr = 1;
    hfdcan1.Init.RxFifo0ElmtsNbr = 16;
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

    FDCAN1_RXFilter.IdType = FDCAN_EXTENDED_ID;                       //标准ID
    FDCAN1_RXFilter.FilterIndex = 0;                                  //滤波器索引
    FDCAN1_RXFilter.FilterType = FDCAN_FILTER_MASK;                   //滤波器类型
    FDCAN1_RXFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;           //过滤器0关联到FIFO0
    FDCAN1_RXFilter.FilterID1 = 0x0000;                               // 32位ID
    FDCAN1_RXFilter.FilterID2 = 0x0000;                               //如果FDCAN配置为传统模式的话，这里是32位掩码
    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &FDCAN1_RXFilter) != HAL_OK) //滤波器初始化
    {
        Error_Handler();
    }

    if (HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK) {
        Error_Handler();
    }

    HAL_FDCAN_Start(&hfdcan1); //开启FDCAN

    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

#endif

#ifdef DRV_USE_FDCAN2
    hfdcan2.Instance = FDCAN2;
    hfdcan2.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan2.Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan2.Init.AutoRetransmission = DISABLE;
    hfdcan2.Init.TransmitPause = DISABLE;
    hfdcan2.Init.ProtocolException = DISABLE;
    hfdcan2.Init.NominalPrescaler = 4;
    hfdcan2.Init.NominalSyncJumpWidth = 8;
    hfdcan2.Init.NominalTimeSeg1 = 8;
    hfdcan2.Init.NominalTimeSeg2 = 3;
    hfdcan2.Init.DataPrescaler = 4;
    hfdcan2.Init.DataSyncJumpWidth = 8;
    hfdcan2.Init.DataTimeSeg1 = 8;
    hfdcan2.Init.DataTimeSeg2 = 3;
    hfdcan2.Init.MessageRAMOffset = hfdcan1.msgRam.EndAddress - SRAMCAN_BASE;
    hfdcan2.Init.StdFiltersNbr = 1;
    hfdcan2.Init.ExtFiltersNbr = 0;
    hfdcan2.Init.RxFifo0ElmtsNbr = 16;
    hfdcan2.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.RxFifo1ElmtsNbr = 0;
    hfdcan2.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.RxBuffersNbr = 0;
    hfdcan2.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.TxEventsNbr = 0;
    hfdcan2.Init.TxBuffersNbr = 0;
    hfdcan2.Init.TxFifoQueueElmtsNbr = 16;
    hfdcan2.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan2.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
    if (HAL_FDCAN_Init(&hfdcan2) != HAL_OK) {
        Error_Handler();
    }

    FDCAN2_RXFilter.IdType = FDCAN_STANDARD_ID;                       //标准ID
    FDCAN2_RXFilter.FilterIndex = 0;                                  //滤波器索引
    FDCAN2_RXFilter.FilterType = FDCAN_FILTER_MASK;                   //滤波器类型
    FDCAN2_RXFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;           //过滤器0关联到FIFO0
    FDCAN2_RXFilter.FilterID1 = 0x0000;                               // 32位ID
    FDCAN2_RXFilter.FilterID2 = 0x0000;                               //如果FDCAN配置为传统模式的话，这里是32位掩码
    if (HAL_FDCAN_ConfigFilter(&hfdcan2, &FDCAN2_RXFilter) != HAL_OK) //滤波器初始化
    {
        Error_Handler();
    }

    if (HAL_FDCAN_ConfigGlobalFilter(&hfdcan2, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK) {
        Error_Handler();
    }

    HAL_FDCAN_Start(&hfdcan2); //开启FDCAN

    HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
#endif

    return RT_EOK;
}

rt_err_t drv_fdcan_init(void)
{
    RT_CHECK(fdcan_init());

    struct can_configure config = CAN_DEFAULT_CONFIG;

#ifdef DRV_USE_FDCAN1
    fdcan_dev1.ops = &_fdcan_ops;
    fdcan_dev1.config = config;

    if (rt_event_init(&fdcan_dev1.event, "fdcan1", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("fail to init fdcan1 event\n");
        return RT_ERROR;
    }

    hw_can_register(&fdcan_dev1, "fdcan1", 0, &stm32_fdcan1);

#endif

#ifdef DRV_USE_FDCAN2
    fdcan_dev2.ops = &_fdcan_ops;
    fdcan_dev2.config = config;

    hw_can_register(&fdcan_dev2, "fdcan2", 0, &stm32_fdcan2);
#endif

    return RT_EOK;
}

uint8_t buffer[12];
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef* hfdcan, uint32_t RxFifo0ITs)
{
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
        if (hfdcan == &hfdcan1) {
            rt_event_send(&fdcan_dev1.event, EVENT_FDCAN1_RX_CPLT);
        }

        // /* Retrieve Rx messages from RX FIFO0 */
        // if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &FDCAN1_RxHeader, buffer) != HAL_OK) {
        //     Error_Handler();
        // }
        // if (hfdcan == &hfdcan1) {
        //     printf("buffer %d :\n", FDCAN1_RxHeader.DataLength >> 16);
        //     for (uint8_t i = 0; i < 8; i++)
        //         printf("buffer[%d] = 0x%x\n", i, buffer[i]);
        // }
    }
}

/**
 * @brief This function handles FDCAN1 interrupt 0.
 */
void FDCAN1_IT0_IRQHandler(void)
{
    /* USER CODE BEGIN FDCAN1_IT0_IRQn 0 */

    /* USER CODE END FDCAN1_IT0_IRQn 0 */
    HAL_FDCAN_IRQHandler(&hfdcan1);
    /* USER CODE BEGIN FDCAN1_IT0_IRQn 1 */

    /* USER CODE END FDCAN1_IT0_IRQn 1 */
}

/**
 * @brief This function handles FDCAN2 interrupt 0.
 */
void FDCAN2_IT0_IRQHandler(void)
{
    /* USER CODE BEGIN FDCAN2_IT0_IRQn 0 */

    /* USER CODE END FDCAN2_IT0_IRQn 0 */
    HAL_FDCAN_IRQHandler(&hfdcan2);
    /* USER CODE BEGIN FDCAN2_IT0_IRQn 1 */

    /* USER CODE END FDCAN2_IT0_IRQn 1 */
}