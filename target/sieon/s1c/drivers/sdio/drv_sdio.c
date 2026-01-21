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

#include "hal/sd/sd.h"
#include "sd.h"
#if 1
#if defined   (__CC_ARM)        /*!< ARM compiler */
    #pragma O0
#elif defined (__GNUC__)        /*!< GNU compiler */
    #pragma GCC optimize ("O0")
#elif defined  (__TASKING__)    /*!< TASKING compiler */
    #pragma optimize=0
#endif /* __CC_ARM */
#endif
#define SD_WAIT_TIMEOUT 10

static struct sd_device sd0_dev;
//static sd_card_info_struct sd_cardinfo; /* information of SD card */
static struct rt_mutex sd_lock;

/* unlock/lock peripheral */
#define EXAMPLE_PERIPH_WE               (LL_PERIPH_GPIO | LL_PERIPH_EFM | LL_PERIPH_FCG | \
    LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_SRAM)
#define EXAMPLE_PERIPH_WP               (LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_SRAM)

/* SD transfer mode */
#define SD_TRANS_MD_POLLING             (0U)
#define SD_TRANS_MD_INT                 (1U)
#define SD_TRANS_MD_DMA                 (2U)
/* Populate the following macro with an value, reference "SD transfer mode" */
#define SD_TRANS_MD                     (SD_TRANS_MD_POLLING)
/* SDIOC DMA configuration define */
#define SDIOC_DMA_UNIT                  (CM_DMA1)
#define SDIOC_DMA_CLK                   (FCG0_PERIPH_DMA1 | FCG0_PERIPH_AOS)
#define SDIOC_DMA_TX_CH                 (DMA_CH0)
#define SDIOC_DMA_RX_CH                 (DMA_CH1)
#define SDIOC_DMA_TX_TRIG_CH            (AOS_DMA1_0)
#define SDIOC_DMA_RX_TRIG_CH            (AOS_DMA1_1)
#define SDIOC_DMA_TX_TRIG_SRC           (EVT_SRC_SDIOC1_DMAW)
#define SDIOC_DMA_RX_TRIG_SRC           (EVT_SRC_SDIOC1_DMAR)

/* SDIOC configuration define */
#define SDIOC_SD_UINT                   (CM_SDIOC2)
#define SDIOC_SD_CLK                    (FCG1_PERIPH_SDIOC2)
#define SIDOC_SD_INT_SRC                (INT_SRC_SDIOC2_SD)
#define SIDOC_SD_IRQ                    (INT006_IRQn)
/* CD = PC11 */
// #define SDIOC_CD_PORT                   (GPIO_PORT_C)
// #define SDIOC_CD_PIN                    (GPIO_PIN_11)
/* CK = PC12 */
#define SDIOC_CK_PORT                   (GPIO_PORT_C)
#define SDIOC_CK_PIN                    (GPIO_PIN_13)
/* CMD = PD02 */
#define SDIOC_CMD_PORT                  (GPIO_PORT_B)
#define SDIOC_CMD_PIN                   (GPIO_PIN_00)
/* D0 = PB07 */
#define SDIOC_D0_PORT                   (GPIO_PORT_B)
#define SDIOC_D0_PIN                    (GPIO_PIN_03)
/* D1 = PA08 */
#define SDIOC_D1_PORT                   (GPIO_PORT_A)
#define SDIOC_D1_PIN                    (GPIO_PIN_15)
/* D2 = PC10 */
#define SDIOC_D2_PORT                   (GPIO_PORT_B)
#define SDIOC_D2_PIN                    (GPIO_PIN_02)
/* D3 = PB05 */
#define SDIOC_D3_PORT                   (GPIO_PORT_B)
#define SDIOC_D3_PIN                    (GPIO_PIN_01)

/* SD card read/write/erase */
//#define SD_CARD_BLK_MAX_LUM             (0x20000)
#define SD_CARD_BLK_MAX_LUM             (0x100)
#define SD_CARD_BLK_SIZE                (512UL)
//#define SD_CARD_BLK_SIZE                (4096UL)
#define SD_CARD_BLK_NUM                 (10U)
static stc_sd_handle_t SdHandle;

#if 0
/*!
    \brief      this function handles SDIO interrupt request
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SDIO_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    sd_error_enum sd_err = sd_interrupts_process();
    if (sd_err != SD_OK) {
        printf("sd isr error:%d\n", sd_err);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif

static en_flag_status_t SdCard_GetInsertState(void)
{
    en_flag_status_t enFlagSta = SET;

    /* Check SD card detect pin */
    // if (0U != GPIO_ReadInputPins(SDIOC_CD_PORT, SDIOC_CD_PIN)) {
    //     enFlagSta = RESET;
    // }

    return enFlagSta;
}

void BSP_CLK_Init(void)
{
    return;
    stc_clock_xtal_init_t stcXtalInit;
    stc_clock_pll_init_t stcPLLHInit;

    CLK_SetClockDiv(CLK_BUS_CLK_ALL,
                    (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | CLK_PCLK2_DIV4 |
                     CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 |
                     CLK_HCLK_DIV1));
    (void)CLK_XtalStructInit(&stcXtalInit);
    /* Config Xtal and enable Xtal */
    stcXtalInit.u8Mode   = CLK_XTAL_MD_OSC;
    stcXtalInit.u8Drv    = CLK_XTAL_DRV_ULOW;
    stcXtalInit.u8State  = CLK_XTAL_ON;
    stcXtalInit.u8StableTime = CLK_XTAL_STB_2MS;

    //GPIO_AnalogCmd(BSP_XTAL_PORT, BSP_XTAL_PIN, ENABLE);
    (void)CLK_XtalInit(&stcXtalInit);

    (void)CLK_PLLStructInit(&stcPLLHInit);
    /* VCO = (8/1)*100 = 800MHz*/
    stcPLLHInit.u8PLLState      = CLK_PLL_ON;
    stcPLLHInit.PLLCFGR         = 0UL;
    stcPLLHInit.PLLCFGR_f.PLLM  = 1UL - 1UL;
    stcPLLHInit.PLLCFGR_f.PLLN  = 100UL - 1UL;
    stcPLLHInit.PLLCFGR_f.PLLP  = 4UL - 1UL;
    stcPLLHInit.PLLCFGR_f.PLLQ  = 4UL - 1UL;
    stcPLLHInit.PLLCFGR_f.PLLR  = 4UL - 1UL;
    stcPLLHInit.PLLCFGR_f.PLLSRC = CLK_PLL_SRC_XTAL;
    (void)CLK_PLLInit(&stcPLLHInit);

    /* SRAM Read/Write wait cycle setting */
    SRAM_SetWaitCycle(SRAM_SRAMH, SRAM_WAIT_CYCLE0, SRAM_WAIT_CYCLE0);
    SRAM_SetWaitCycle((SRAM_SRAM123 | SRAM_SRAM4 | SRAM_SRAMB), SRAM_WAIT_CYCLE1, SRAM_WAIT_CYCLE1);
    /* 0-wait @ 40MHz */
    EFM_SetWaitCycle(EFM_WAIT_CYCLE5);
    /* 4 cycles for 200 ~ 250MHz */
    GPIO_SetReadWaitCycle(GPIO_RD_WAIT4);
    CLK_SetSysClockSrc(CLK_SYSCLK_SRC_PLL);
}

static rt_err_t init(sd_dev_t sd)
{
    LL_PERIPH_WE(EXAMPLE_PERIPH_WE);
    BSP_CLK_Init();
#if 0
    uint32_t cardstate = 0;

    nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    nvic_irq_enable(SDIO_IRQn, 0, 1);

    if (sd_init() != SD_OK) {
        goto error;
    }

    if (sd_card_information_get(&sd_cardinfo) != SD_OK) {
        goto error;
    }

    if (sd_card_select_deselect(sd_cardinfo.card_rca) != SD_OK) {
        goto error;
    }

    if (sd_cardstatus_get(&cardstate) != SD_OK) {
        goto error;
    }

    if (cardstate & 0x02000000) {
        printf("the card is locked!\n");
        goto error;
    }

    if (sd_bus_mode_config(SDIO_BUSMODE_4BIT) != SD_OK) {
        goto error;
    }

    if (sd_transfer_mode_config(SD_POLLING_MODE) != SD_OK) {
        goto error;
    }

    /* enable sdio hardware clock control to avoid SD_RX_OVERRUN_ERROR */
    sdio_hardware_clock_enable();
#endif

    /* Enable SDIOC clock */
    FCG_Fcg1PeriphClockCmd(SDIOC_SD_CLK, ENABLE);
    
	// delay_dnn(0xfffff0);
	GPIO_SetDebugPort(GPIO_PIN_TDI,DISABLE);
    GPIO_SetDebugPort(GPIO_PIN_TDO,DISABLE);

    /* SDIOC pins configuration */
//    BSP_IO_ConfigPortPin(EIO_PORT0, EIO_SDIO1_CD, EIO_DIR_IN);
    stc_gpio_init_t stcGpioInit;
    (void)GPIO_StructInit(&stcGpioInit);
    GPIO_REG_Unlock();
    stcGpioInit.u16ExtInt = PIN_EXTINT_OFF;
    stcGpioInit.u16PullUp = PIN_PU_ON;
    (void)GPIO_Init(SDIOC_D0_PORT,SDIOC_D0_PIN, &stcGpioInit);
    (void)GPIO_Init(SDIOC_D1_PORT,SDIOC_D1_PIN, &stcGpioInit);
    (void)GPIO_Init(SDIOC_D2_PORT,SDIOC_D2_PIN, &stcGpioInit);
    (void)GPIO_Init(SDIOC_D3_PORT,SDIOC_D3_PIN, &stcGpioInit);
    (void)GPIO_Init(SDIOC_CMD_PORT,SDIOC_CMD_PIN, &stcGpioInit);
    stcGpioInit.u16PullUp = PIN_PU_OFF;
    // (void)GPIO_Init(SDIOC_CD_PORT,SDIOC_CD_PIN, &stcGpioInit);
    GPIO_SetFunc(SDIOC_CK_PORT,  SDIOC_CK_PIN,  GPIO_FUNC_9);
    GPIO_SetFunc(SDIOC_CMD_PORT, SDIOC_CMD_PIN, GPIO_FUNC_9);
    GPIO_SetFunc(SDIOC_D0_PORT,  SDIOC_D0_PIN,  GPIO_FUNC_9);
    GPIO_SetFunc(SDIOC_D1_PORT,  SDIOC_D1_PIN,  GPIO_FUNC_9);
    GPIO_SetFunc(SDIOC_D2_PORT,  SDIOC_D2_PIN,  GPIO_FUNC_9);
    GPIO_SetFunc(SDIOC_D3_PORT,  SDIOC_D3_PIN,  GPIO_FUNC_9);

    /* Configure structure initialization */
    SdHandle.SDIOCx                     = SDIOC_SD_UINT;
    SdHandle.stcSdiocInit.u32Mode       = SDIOC_MD_SD;
    SdHandle.stcSdiocInit.u8CardDetect  = SDIOC_CARD_DETECT_CD_PIN_LVL;
    SdHandle.stcSdiocInit.u8SpeedMode   = SDIOC_SPEED_MD_HIGH;
    SdHandle.stcSdiocInit.u8BusWidth    = SDIOC_BUS_WIDTH_4BIT;
    SdHandle.stcSdiocInit.u16ClockDiv   = SDIOC_CLK_DIV4;//SDIOC_CLK_DIV2;
#if SD_TRANS_MD == SD_TRANS_MD_DMA
    SdCard_DMAInit();
    SdHandle.DMAx      = SDIOC_DMA_UNIT;
    SdHandle.u8DmaTxCh = SDIOC_DMA_TX_CH;
    SdHandle.u8DmaRxCh = SDIOC_DMA_RX_CH;
#else
    SdHandle.DMAx    = NULL;
#endif

    /* Reset and init SDIOC */
    if (LL_OK != SDIOC_SWReset(SdHandle.SDIOCx, SDIOC_SW_RST_ALL)) {
        DDL_Printf("Reset SDIOC failed!\r\n");
        goto error;
    } else if (SET != SdCard_GetInsertState()) {
        DDL_Printf("No SD card insertion!\r\n");
        goto error;
    } else if (LL_OK != SD_Init(&SdHandle)) {
        DDL_Printf("SD card initialize failed!\r\n");
        goto error;
    } else {
        DDL_Printf("SD card initialize ok!\r\n");
    }


    return RT_EOK;

error:
    return RT_ERROR;
}

static rt_err_t sd_write(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;
    if (count == 0) {
        return RT_EOK;
    }

    RT_TRY(rt_mutex_take(&sd_lock, TICKS_FROM_MS(SD_WAIT_TIMEOUT)));

    // if (count > 1) { 
    //     err = RT_ERROR;
    // } else {
    if(1){
        // if (sd_block_write((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
        //     err = RT_ERROR;
        // }
        //if (LL_OK != SD_WriteBlocks(&SdHandle, sector * SdHandle.stcSdCardInfo.u32BlockSize, 1, (uint8_t *)buffer, 2000U))
        if (LL_OK != SD_WriteBlocks(&SdHandle, sector, count, (uint8_t *)buffer, 2000U))
        {
            //i32Ret = LL_ERR;
            err = RT_ERROR;
        }
    }
    if(err != RT_EOK)
    {
        console_printf("write error\n");
    }


    RT_TRY(rt_mutex_release(&sd_lock));

    return err;
}

static rt_err_t sd_read(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    if (count == 0) {
        return RT_EOK;
    }

    RT_TRY(rt_mutex_take(&sd_lock, TICKS_FROM_MS(SD_WAIT_TIMEOUT)));

    // if (count > 1) {
    //     //if (sd_multiblocks_read((uint32_t*)buffer, sector * SD_CARD_BLK_SIZE, 1, count) != SD_OK) {
    //         err = RT_ERROR;
    //    // }
    // } else 
    if(1)
    {
        // if (sd_block_read((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
        //     err = RT_ERROR;
        // }
        //if (LL_OK != SD_ReadBlocks(&SdHandle, sector * SdHandle.stcSdCardInfo.u32BlockSize, 1, (uint8_t *)buffer, 2000UL))
        // if (LL_OK != SD_ReadBlocks(&SdHandle, sector, 1, (uint8_t *)buffer, 2000UL))
        if (LL_OK != SD_ReadBlocks(&SdHandle, sector, count, (uint8_t *)buffer, 2000UL))
        {
            //i32Ret = LL_ERR;
            err = RT_ERROR;
        }
    }

    RT_TRY(rt_mutex_release(&sd_lock));
    if(err != RT_EOK)
    {
        console_printf("Read error\n");
    }

    return err;
}

static rt_err_t sd_control(sd_dev_t sd, int cmd, void* arg)
{
    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        struct rt_device_blk_geometry geometry;

        geometry.bytes_per_sector = SdHandle.stcSdCardInfo.u32BlockSize;//sd_cardinfo.card_blocksize;
        geometry.block_size = SdHandle.stcSdCardInfo.u32BlockSize;//SD_CARD_BLK_SIZE;//sd_cardinfo.card_blocksize;
        geometry.sector_count = SdHandle.stcSdCardInfo.u32BlockNum;//sd_cardinfo.card_capacity / sd_cardinfo.card_blocksize;
        *(struct rt_device_blk_geometry*)arg = geometry;
    } break;
    case RT_DEVICE_CTRL_BLK_SYNC: {
        //TODO
    } break;
    case RT_DEVICE_CTRL_BLK_ERASE: {
        /* sd card is not needed to erase */
        return RT_ERROR;
    } break;
    default: {
        console_printf("unknown sd control cmd:%d\n", cmd);
    } break;
    }

    return RT_EOK;
}

const static struct sd_ops dev_ops = {
    .sd_init = init,
    .sd_write = sd_write,
    .sd_read = sd_read,
    .sd_control = sd_control
};

rt_err_t drv_sdio_init(void)
{
    sd0_dev.ops = &dev_ops;

    RT_TRY(rt_mutex_init(&sd_lock, "sd_lock", RT_IPC_FLAG_PRIO));

    //return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &sd_cardinfo);
    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, NULL);
}

static int init_flag = 1;
static uint8_t write_buf[20] = {0,1,2,3,4,5,6,7,8,9,10};
static uint8_t read_buf[20];
void test_rw(void)
{
    rt_memset(read_buf,0,15);
    if(init_flag)
    {
        init_flag = 0;
        sd0_dev.ops->sd_init(0);
        return;
    }
    if(sd0_dev.ops->sd_write(NULL,write_buf,10,1) != RT_EOK)
    {
        console_printf("write err");
    }
    if(sd0_dev.ops->sd_read(NULL,read_buf,10,1) != RT_EOK)
    {
        console_printf("read err");
    }
    if(rt_memcmp(read_buf, write_buf,15) != 0 )
    {
        console_printf("cmp error");
    }
    else
    {
        console_printf("cmp okk");
    }
    return;
}

