#ifndef __HAL_NV_H__
#define __HAL_NV_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"



/**
* @brief      
* @param    
* @retval   
* @note   
*/
HAL_RET_T HAL_NV_Init(void);

/**
* @brief      
* @param    
* @retval   
* @note   
*/
HAL_RET_T HAL_NV_ResetBbRcId(void);

/**
* @brief  write configuration data to flash, maxximun capacity(MAX_CPT) 60KB.
* @param  addr        start address, 0 ~ (MAX_CPT - 1)
*         wdata       data buffer want to write 
*         wlen        data length, 1 ~ MAX_CPT
* @retval HAL_OK      write sucessed
*         HAL_NV_ERR  write failed.
* @note   (addr + wlen) <= MAX_CPT.
*       
*/
HAL_RET_T HAL_NV_UsrDataWrite(uint32_t addr, uint8_t *wdata, uint32_t wlen);

/**
* @brief  read configuration data from flash, maxximun capacity(MAX_CPT) 60KB.
* @param  addr        start address, 0 ~ (MAX_CPT - 1)
*         rdata       data buffer to save data
*         rlen        data length, 1 ~ MAX_CPT
* @retval HAL_OK      read sucessed
*         HAL_NV_ERR  read failed.
* @note   (addr + wlen) <= MAX_CPT.
*       
*/
HAL_RET_T HAL_NV_UsrDataRead(uint32_t addr, uint8_t *rdata, uint32_t rlen);

HAL_RET_T HAL_NV_SaveChipId(void *par);

// int32_t NV_GetInit(void);

#ifdef __cplusplus
}
#endif

#endif

