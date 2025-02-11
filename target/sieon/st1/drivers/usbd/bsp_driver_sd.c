/** 
 * @brief SD卡驱动配置
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file bsp_driver_sd.c
 * @addtogroup SD_driver
 * @signature: 热爱漫无边际，生活自有分寸
 */

#include "bsp_driver_sd.h"

// SD卡信息结构体
extern SD_HandleTypeDef hsd1;

/* SD卡操作 */
  /**
   * @author WeiXuan
   * @brief 初始化SD卡设备 
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_Init(void)
  {
    uint8_t sd_state = MSD_OK;
    // 检查SD卡是否被插入
    if (BSP_SD_IsDetected() != SD_PRESENT)
    {
      return MSD_ERROR_SD_NOT_PRESENT;
    }
    // HAL SD 初始化
    sd_state = HAL_SD_Init(&hsd1);
    // 配置SD卡4位总线模式
    if (sd_state == MSD_OK)
    {
      if (HAL_SD_ConfigWideBusOperation(&hsd1, SDMMC_BUS_WIDE_4B) != HAL_OK)
      {
        sd_state = MSD_ERROR;
      }
    }
    return sd_state;
  }

  /**
   * @author WeiXuan
   * @brief 配置SD卡检测引脚的中断模式
   * @returns 成功返回0
   */ 
  uint8_t BSP_SD_ITConfig(void)
  {  
    return (uint8_t)0;
  }

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中读取扇区，普通模式
   * @param *pData 读出数据存储数组
   * @param ReadAddr 读取地址
   * @param NumOfBlocks 读取扇区数量
   * @param Timeout 读操作的超时时间
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout)
  {
    uint8_t sd_state = MSD_OK;

    if (HAL_SD_ReadBlocks(&hsd1, (uint8_t *)pData, ReadAddr, NumOfBlocks, Timeout) != HAL_OK)
    {
      sd_state = MSD_ERROR;
    }

    return sd_state;  
  }

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中写扇区，普通模式
   * @param *pData 写入数据存储数组
   * @param WriteAddr 写地址
   * @param NumOfBlocks 写扇区数量
   * @param Timeout 写操作的超时时间
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout)
  {
    uint8_t sd_state = MSD_OK;

    if (HAL_SD_WriteBlocks(&hsd1, (uint8_t *)pData, WriteAddr, NumOfBlocks, Timeout) != HAL_OK) 
    {
      sd_state = MSD_ERROR;
    }

    return sd_state;  
  }

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中读取扇区，DMA模式
   * @param *pData 读出数据存储数组
   * @param ReadAddr 读取地址
   * @param NumOfBlocks 读取扇区数量
   * @returns SD卡状态
   */
  uint8_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks)
  {
    uint8_t sd_state = MSD_OK;
    
    if (HAL_SD_ReadBlocks_DMA(&hsd1, (uint8_t *)pData, ReadAddr, NumOfBlocks) != HAL_OK)
    {
      sd_state = MSD_ERROR;
    }
    
    return sd_state; 
  }

  /**
   * @author WeiXuan
   * @brief 从SD卡指定地址中写扇区，DMA模式
   * @param *pData 写入数据存储数组
   * @param WriteAddr 写地址
   * @param NumOfBlocks 写扇区数量
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks)
  {
    uint8_t sd_state = MSD_OK;
    
    if (HAL_SD_WriteBlocks_DMA(&hsd1, (uint8_t *)pData, WriteAddr, NumOfBlocks) != HAL_OK)
    {
      sd_state = MSD_ERROR;
    }
    
    return sd_state; 
  }

  /**
   * @author WeiXuan
   * @brief 擦除SD卡扇区 
   * @param StartAddr 开始地址
   * @param EndAddr 结束地址
   * @returns SD卡状态
   */ 
  uint8_t BSP_SD_Erase(uint32_t StartAddr, uint32_t EndAddr)
  {
    uint8_t sd_state = MSD_OK;

    if (HAL_SD_Erase(&hsd1, StartAddr, EndAddr) != HAL_OK)  
    {
      sd_state = MSD_ERROR;
    }

    return sd_state; 
  }

  /**
   * @author WeiXuan
   * @brief 获取SD卡状态 
   * @returns SD_TRANSFER_OK: 无数据传输 SD_TRANSFER_BUSY: 数据正在传输
   */ 
  uint8_t BSP_SD_GetCardState(void)
  {
    return ((HAL_SD_GetCardState(&hsd1) == HAL_SD_CARD_TRANSFER ) ? SD_TRANSFER_OK : SD_TRANSFER_BUSY);
  }

  /**
   * @author WeiXuan
   * @brief 获取SD卡信息 
   * @param *CardInfo
   * @returns 
   */ 
  void BSP_SD_GetCardInfo(HAL_SD_CardInfoTypeDef *CardInfo)
  {
    HAL_SD_GetCardInfo(&hsd1, CardInfo);
  }

  /**
   * @author WeiXuan
   * @brief 判断SD卡是否检测成功 
   * @returns SD卡是否检测
   */
  uint8_t BSP_SD_IsDetected(void)
  {
    __IO uint8_t status = SD_PRESENT;

    if( GPIOB->IDR & (1<<2) )
      status = SD_NOT_PRESENT;

    return status;
  }
/* SD卡操作 */
