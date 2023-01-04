/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_spi.h
Description: The external HAL APIs to use the SPI controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_spi.h
*****************************************************************************/

#ifndef __HAL_SPI_H__
#define __HAL_SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
#include "hal_ret_type.h"
#include "spi.h"


typedef enum {
    HAL_SPI_COMPONENT_0 = 0,
    HAL_SPI_COMPONENT_1,
    HAL_SPI_COMPONENT_2,
    HAL_SPI_COMPONENT_3,
    HAL_SPI_COMPONENT_4,
    HAL_SPI_COMPONENT_5,
    HAL_SPI_COMPONENT_6,
    HAL_SPI_COMPONENT_7,
} ENUM_HAL_SPI_COMPONENT;

// Serial Clock Polarity
typedef enum {
    HAL_SPI_POLARITY_LOW = 0, // Inactive state of serial clock is low
    HAL_SPI_POLARITY_HIGH     // Inactive state of serial clock is high
} ENUM_HAL_SPI_POLARITY;

// Serial Clock Phase
typedef enum {
    // data are captured on the first edge of the serial clock
    HAL_SPI_PHASE_1EDGE = 0,

    // data are captured on the second edge of the serial clock
    HAL_SPI_PHASE_2EDGE
} ENUM_HAL_SPI_PHASE;

// spi init info
typedef struct
{
    uint32_t u32_halSpiBaudr_Hz; // range 1~50 Mhz
    ENUM_HAL_SPI_POLARITY e_halSpiPolarity;
    ENUM_HAL_SPI_PHASE e_halSpiPhase;
} STRU_HAL_SPI_INIT;

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
                             STRU_HAL_SPI_INIT* pst_spiInitInfo);

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
                                  uint32_t u32_timeOut);

#ifdef __cplusplus
}
#endif

#endif
