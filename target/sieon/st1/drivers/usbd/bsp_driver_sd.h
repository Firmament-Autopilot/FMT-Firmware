/** 
 * @brief SD卡驱动配置
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file bsp_driver_sd.h
 * @addtogroup SD_driver
 * @signature: 热爱漫无边际，生活自有分寸
 */

#ifndef __STM32H7_SD_H
#define __STM32H7_SD_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include "stm32h7xx_hal.h"


// SD卡信息结构体
#define BSP_SD_CardInfo HAL_SD_CardInfoTypeDef

// SD卡状态信息
#define   MSD_OK                        ((uint8_t)0x00)
#define   MSD_ERROR                     ((uint8_t)0x01)
#define   MSD_ERROR_SD_NOT_PRESENT      ((uint8_t)0x02)

// SD卡发送状态定义
#define   SD_TRANSFER_OK                ((uint8_t)0x00)
#define   SD_TRANSFER_BUSY              ((uint8_t)0x01)
#define   SD_PRESENT                    ((uint8_t)0x01)
#define   SD_NOT_PRESENT                ((uint8_t)0x00)
#define   SD_DATATIMEOUT                ((uint32_t)100000000)

// SD卡插入检测函数
#define SD_DetectIRQHandler()            HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7)


/* SD卡操作 */
  /**
   * @author WeiXuan
   * @brief 初始化SD卡设备 
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_Init(void);

  /**
   * @author WeiXuan
   * @brief 配置SD卡检测引脚的中断模式
   * @returns 成功返回0
   */ 
  uint8_t BSP_SD_ITConfig(void);

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中读取扇区，普通模式
   * @param *pData 读出数据存储数组
   * @param ReadAddr 读取地址
   * @param NumOfBlocks 读取扇区数量
   * @param Timeout 读操作的超时时间
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout);

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中写扇区，普通模式
   * @param *pData 写入数据存储数组
   * @param WriteAddr 写地址
   * @param NumOfBlocks 写扇区数量
   * @param Timeout 写操作的超时时间
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout);

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中读取扇区，DMA模式
   * @param *pData 读出数据存储数组
   * @param ReadAddr 读取地址
   * @param NumOfBlocks 读取扇区数量
   * @returns SD卡状态
   */
  uint8_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks);

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中写扇区，DMA模式
   * @param *pData 写入数据存储数组
   * @param WriteAddr 写地址
   * @param NumOfBlocks 写扇区数量
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks);

  /**
   * @author WeiXuan
   * @brief 擦除SD卡扇区 
   * @param StartAddr 开始地址
   * @param EndAddr 结束地址
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_Erase(uint32_t StartAddr, uint32_t EndAddr);

  /**
   * @author WeiXuan
   * @brief 获取SD卡状态 
   * @returns SD_TRANSFER_OK: 无数据传输 SD_TRANSFER_BUSY: 数据正在传输
   */ 
  uint8_t BSP_SD_GetCardState(void);

  /**
   * @author WeiXuan
   * @brief 获取SD卡信息 
   * @param *CardInfo
   * @returns 
   */ 
  void BSP_SD_GetCardInfo(HAL_SD_CardInfoTypeDef *CardInfo);

  /**
   * @author WeiXuan
   * @brief 判断SD卡是否检测成功 
   * @returns SD卡是否检测
   */
  uint8_t BSP_SD_IsDetected(void);

    /**
   * @author WeiXuan
   * @brief SD Abort 回调函数 
   * @returns 
   */ 
  void BSP_SD_AbortCallback(void);

  /**
   * @author WeiXuan
   * @brief SD卡TX完成回调函数
   * @returns 
   */ 
  void BSP_SD_WriteCpltCallback(void);

  /**
   * @author WeiXuan
   * @brief SD卡RX完成回调函数
   * @returns 
   */ 
  void BSP_SD_ReadCpltCallback(void);
/* SD卡操作 */


#ifdef __cplusplus
}
#endif

#endif 