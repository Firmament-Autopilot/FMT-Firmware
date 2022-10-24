#ifndef __EFUSE_H__
#define __EFUSE_H__

/**
* @brief  cpu efuse.
* @param  u32_key0 efuse key0.
* @param  u32_key1 efuse key1.
* @retval 1               means efuse init is well done.
* @retval 0               means efuse init fail.
* @note   None.
*/
int8_t EFUSE_EfuseInit(uint32_t u32_key0, uint32_t u32_key1);

/**
* @brief  cpu efuse statue.
* @param  None.
* @retval 1               means cpu efuse enable.
* @retval 1               means cpu efuse disable.
* @note   None.
*/
int32_t EFUSE_GetEfuseEnable(void);

/**
* @brief  flash encrypt.
* @param  1                    flash encrypt data write.
* @param  0                    flash raw data write.
* @retval None.
* @note   None.
*/
void EFUSE_CtrFlashWriteEfuse(uint8_t u8_state);
#endif