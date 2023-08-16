/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_spi.c
Description: The external HAL APIs to use the SPI controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_spi.c
*****************************************************************************/

#include "hal_spi.h"
#include "debuglog.h"
#include "hal_nvic.h"
#include "interrupt.h"
#include "drv_systick.h"
#include "hal.h"
#include "driver_mutex.h"
#include "driver_module_init.h"
#include "drv_systick.h"
/**
* @brief  The SPI initialization function which must be called 
*         before using the SPI controller.
* @param  e_spiComponent    The SPI controller number, the right number 
*                           should be 0-7 and totally 8 SPI controllers 
*                           can be used by application.
*         pst_spiInitInfo   spi init info,the member's value should use 
*                           the enum value.
* @retval HAL_OK            means the initializtion is well done.
*         HAL_SPI_ERR_INIT  means some error happens in the initializtion.
* @note   None.
*       
*/
HAL_RET_T HAL_SPI_MasterInit(ENUM_HAL_SPI_COMPONENT e_spiComponent,
                             STRU_HAL_SPI_INIT* pst_spiInitInfo)
{
    // uint16_t u16_spiDivision;
    uint8_t u8_spiVecNum;
    // init default value.
    STRU_SPI_InitTypes st_spiInit = {
        .ctrl0 = SPI_CTRL0_DEF_VALUE, //EEPROM Read
        .clk_hz = (9 * 1000000),
        .Tx_Fthr = SPI_TXFTLR_DEF_VALUE,
        .Rx_Ftlr = SPI_RXFTLR_DEF_VALUE,
        .SER = SPI_SSIENR_DEF_VALUE
    };

    if (e_spiComponent > HAL_SPI_COMPONENT_7) {
        return HAL_SPI_ERR_INIT;
    }

    if (NULL == pst_spiInitInfo) {
        return HAL_SPI_ERR_INIT;
    }

    if (-1 == COMMON_driverMutexGet(MUTEX_SPI, e_spiComponent)) {
        DLOG_Error("fail, e_spiComponent = %d", e_spiComponent);
        return HAL_OCCUPIED;
    }
    COMMON_driverMutexSet(MUTEX_SPI, (uint32_t)e_spiComponent);
    COMMON_driverInitSet(INITED_SPI, (uint32_t)e_spiComponent);
    // BAUDR
    st_spiInit.clk_hz = pst_spiInitInfo->u32_halSpiBaudr_Hz;

    // SCPOL
    st_spiInit.ctrl0 &= (~0x80);
    st_spiInit.ctrl0 |= (((uint16_t)(pst_spiInitInfo->e_halSpiPolarity)) << 7) & 0x80;

    // SCPH
    st_spiInit.ctrl0 &= (~0x40);
    st_spiInit.ctrl0 |= (((uint16_t)(pst_spiInitInfo->e_halSpiPhase)) << 6) & 0x40;

    //connect spi interrupt service function
    if (HAL_SPI_COMPONENT_7 == e_spiComponent) {
        u8_spiVecNum = VIDEO_SPI_INTR_BB_VECTOR_NUM;
    } else {
        u8_spiVecNum = e_spiComponent + HAL_NVIC_SSI_INTR_N0_VECTOR_NUM;
    }
    HAL_NVIC_SetPriority(u8_spiVecNum, INTR_NVIC_PRIORITY_SPI_DEFAULT, 0);
    //HAL_NVIC_RegisterHandler(u8_spiVecNum, SPI_IntrSrvc, NULL);
    HAL_NVIC_RegisterHandler(u8_spiVecNum, SPI_IntrSrvc_dbg, NULL); // ---- dbg for badfile, chenbang
    SPI_master_init((ENUM_SPI_COMPONENT)(e_spiComponent), &st_spiInit);
    HAL_NVIC_EnableIrq(u8_spiVecNum);

    return HAL_OK;
}

/**
* @brief  The SPI data write function which can be used to send out SPI data 
*         by the SPI controller.
* @param  e_spiComponent          The SPI controller number, the right number 
*                                 should be 0-7 and totally 8 SPI controllers 
*                                 can be used by application.
*         pu8_wrData              The transmit buffer pointer to be sent out 
*                                 by SPI bus. 
*         u32_wrSize              The transmit buffer size in byte. 
*         pu8_rdData              The receive buffer pointer to hold the data 
*                                 in read operation.
*         u32_rdSize              The receive buffer size in byte.
*         u32_timeOut             timeout threshold, unit:ms
* @retval HAL_OK                  means the SPI data write is well done.
*         HAL_SPI_ERR_WRITE_DATA  means some error happens in the SPI data write.
*         HAL_SPI_ERR_READ_DATA   means some error happens in the data read.
*         HAL_SPI_ERR_COMPONENT   means component error.
* @note   the SPI controller must work in master mode.
*
*/
HAL_RET_T HAL_SPI_MasterWriteRead(ENUM_HAL_SPI_COMPONENT e_spiComponent,
                                  uint8_t* pu8_wrData,
                                  uint32_t u32_wrSize,
                                  uint8_t* pu8_rdData,
                                  uint32_t u32_rdSize,
                                  uint32_t u32_timeOut)

{
    uint32_t start;

    if (e_spiComponent > HAL_SPI_COMPONENT_7) {
        return HAL_SPI_ERR_COMPONENT;
    }
    if ((u32_wrSize > 0) && (NULL == pu8_wrData)) {
        return HAL_SPI_ERR_WRITE_DATA;
    }
    if ((u32_rdSize > 0) && (NULL == pu8_rdData)) {
        return HAL_SPI_ERR_READ_DATA;
    }

    if (-1 == COMMON_driverInitGet(INITED_SPI, e_spiComponent)) {
        DLOG_Error("fail, e_spiComponent = %d", e_spiComponent);
        return HAL_NOT_INITED;
    }

    if (SPI_GetBusyStatus(e_spiComponent)) {
        return HAL_BUSY;
    }

/*    SPI_write_read((ENUM_SPI_COMPONENT)(e_spiComponent),
                   pu8_wrData,
                   u32_wrSize,
                   pu8_rdData,
                   u32_rdSize);
	*/	
    SPI_write_read_dbg((ENUM_SPI_COMPONENT)(e_spiComponent),
                   pu8_wrData,
                   u32_wrSize,
                   pu8_rdData,
                   u32_rdSize);


    if (0 != u32_timeOut) {
        start = SysTicks_GetTickCount();
        while (SPI_GetBusyStatus(e_spiComponent)) {
            if ((SysTicks_GetDiff(start, SysTicks_GetTickCount())) >= u32_timeOut) {
                SPI_DisEnableInt(e_spiComponent, SPI_IMR_MASK);
                return HAL_TIME_OUT;
            }

            //SysTicks_DelayUS(5);
        }
    }

//--------chenbang add, for debugging
#if 0
	if(e_spiComponent == HAL_SPI_COMPONENT_1)
	{
		if((pu8_wrData != NULL) && (u32_wrSize != 0))
		{
			console_printf("wr=%d ",u32_wrSize);
			for(int i=0; i<u32_wrSize; i++)
			{
				console_printf("%02X", pu8_wrData[i]);
			}
		}
		if((pu8_rdData != NULL) && (u32_rdSize != 0))
		{
			console_printf("rd=%d ",u32_rdSize);
			for(int i=0; i<u32_rdSize; i++)
			{
				console_printf("%02X", pu8_rdData[i]);
			}
		}
		console_printf("\r\n");
	}
#endif

    return HAL_OK;
}
