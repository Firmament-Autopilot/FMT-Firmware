/**
 * @brief usbd_conf 驱动代码
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file usbd_conf.c
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"
#include "usbd_def.h"
#include "usbd_core.h"
#include "usbd_msc.h"
#include "drv_usbd_cdc.h"

// PCD_USB_OTG 定义
PCD_HandleTypeDef hpcd_USB_OTG_FS;
PCD_HandleTypeDef hpcd_USB_OTG_HS;

// USB连接状态 0,没有连接; 1,已经连接;
volatile uint8_t usb_connectflag = 0;   

void drv_usbd_cdc_connect_cb(PCD_HandleTypeDef* hpcd);
void drv_usbd_cdc_disconnect_cb(PCD_HandleTypeDef* hpcd);

/* USBD LL PCD驱动回调函数(PCD->USB Device Library) */
  /**
   * @author WeiXuan
   * @brief 返回USB的状态
   * @param hal_status
   * @returns 
   */
  USBD_StatusTypeDef USBD_Get_USB_Status(HAL_StatusTypeDef hal_status);

  /** 
  * @author WeiXuan
  * @brief USBD 配置阶段回调函数 
  * @param *hpcd PCD结构体指针
  * @returns 
  */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    USBD_LL_SetupStage((USBD_HandleTypeDef*)hpcd->pData, (uint8_t *)hpcd->Setup);
  }

  /**
   * @author WeiXuan
   * @brief USBD OUT 阶段回调函数 
   * @param *hpcd PCD结构体指针
   * @param epnum 端点号
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #else
  void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #endif 
  {
    USBD_LL_DataOutStage((USBD_HandleTypeDef*)hpcd->pData, epnum, hpcd->OUT_ep[epnum].xfer_buff);
  }

  /**
   * @author WeiXuan
   * @brief USBD IN 阶段回调函数
   * @param *hpcd PCD结构体指针
   * @param epnum 端点号
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #else
  void HAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #endif 
  {
    USBD_LL_DataInStage((USBD_HandleTypeDef*)hpcd->pData, epnum, hpcd->IN_ep[epnum].xfer_buff);
  }

  /**
   * @author WeiXuan
   * @brief USBD SOF回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_SOFCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_SOFCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    USBD_LL_SOF((USBD_HandleTypeDef*)hpcd->pData);
  }

  /**
   * @author WeiXuan
   * @brief USBD 复位回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_ResetCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_ResetCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    USBD_SpeedTypeDef speed = USBD_SPEED_FULL;

    if ( hpcd->Init.speed == PCD_SPEED_HIGH)
    {
      speed = USBD_SPEED_HIGH;
    }
    else if ( hpcd->Init.speed == PCD_SPEED_FULL)
    {
      speed = USBD_SPEED_FULL;
    }
    else
    {
      while(1);
    }
    USBD_LL_SetSpeed((USBD_HandleTypeDef*)hpcd->pData, speed);
    USBD_LL_Reset((USBD_HandleTypeDef*)hpcd->pData);
  }

  /**
   * @author WeiXuan
   * @brief USBD 挂起回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_SuspendCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_SuspendCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    usb_connectflag = 0;
    USBD_LL_Suspend((USBD_HandleTypeDef*)hpcd->pData);
    __HAL_PCD_GATE_PHYCLOCK(hpcd);
    if (hpcd->Init.low_power_enable)
    {
      SCB->SCR |= (uint32_t)((uint32_t)(SCB_SCR_SLEEPDEEP_Msk | SCB_SCR_SLEEPONEXIT_Msk));
    }
  }

  /**
   * @author WeiXuan
   * @brief USBD 恢复回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_ResumeCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_ResumeCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    USBD_LL_Resume((USBD_HandleTypeDef*)hpcd->pData);
  }

  /**
   * @author WeiXuan
   * @brief USBD ISO OUT事务完成回调函数
   * @param *hpcd PCD结构体指针
   * @param epnum 端点号
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #else
  void HAL_PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #endif
  {
    USBD_LL_IsoOUTIncomplete((USBD_HandleTypeDef*)hpcd->pData, epnum);
  }

  /**
   * @author WeiXuan
   * @brief USBD ISO IN事务完成回调函数
   * @param *hpcd PCD结构体指针
   * @param epnum 端点号
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #else
  void HAL_PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
  #endif
  {
    USBD_LL_IsoINIncomplete((USBD_HandleTypeDef*)hpcd->pData, epnum);
  }

  /**
   * @author WeiXuan
   * @brief USBD 连接成功回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_ConnectCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_ConnectCallback(PCD_HandleTypeDef *hpcd)
  #endif
  {
    usb_connectflag = 1;
    USBD_LL_DevConnected((USBD_HandleTypeDef*)hpcd->pData);
    drv_usbd_cdc_connect_cb(hpcd);
  }

  /**
   * @author WeiXuan
   * @brief USBD 断开连接回调函数
   * @param *hpcd PCD结构体指针
   * @returns 
   */
  #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
  static void PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd)
  #else
  void HAL_PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd)
  #endif 
  {
    usb_connectflag = 0;
    USBD_LL_DevDisconnected((USBD_HandleTypeDef*)hpcd->pData);
    drv_usbd_cdc_disconnect_cb(hpcd);
  }
/* USBD LL PCD驱动回调函数(PCD->USB Device Library) */

/* USBD LL 驱动接口函数(USB Device Library --> PCD) */
  /**
   * @author WeiXuan
   * @brief 初始化PCD MSP 
   * @param pcdHandle PCD 结构体指针
   * @returns 
   */
  void HAL_PCD_MspInit(PCD_HandleTypeDef* pcdHandle)
  {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    // USB2 低速配置
    if(pcdHandle->Instance==USB_OTG_FS)
    {
      // USB_OTG_FS GPIO Configuration    
      // PA11     ------> USB_OTG_FS_DM
      // PA12     ------> USB_OTG_FS_DP
      
      // 使能GPIO时钟
      __HAL_RCC_GPIOA_CLK_ENABLE();
      // 复用
      GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF10_OTG1_FS;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

      // 使能OTG FS时钟
      __HAL_RCC_USB_OTG_FS_CLK_ENABLE();
      // 使能 OTG FS 中断
			NVIC_SetPriority(OTG_FS_IRQn, 14);
			NVIC_EnableIRQ(OTG_FS_IRQn);
    }
  }

  /**
   * @author WeiXuan
   * @brief 取消初始化PCD MSP 
   * @param pcdHandle PCD 结构体指针
   * @returns 
   */
  void HAL_PCD_MspDeInit(PCD_HandleTypeDef* pcdHandle)
  {
    // USB2 低速配置
    if(pcdHandle->Instance==USB_OTG_FS)
    {
      __HAL_RCC_USB_OTG_FS_CLK_DISABLE();
      HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);
      HAL_NVIC_DisableIRQ(OTG_FS_IRQn);
    }
  }

  /**
   * @author WeiXuan
   * @brief USBD底层初始化函数
   * @param *pdev USBD句柄指针
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_Init(USBD_HandleTypeDef *pdev)
  {
    // 低速
    if (pdev->id == DEVICE_FS) 
    {
      // hpcd_USB_OTG_FS的pData指向pdev
      hpcd_USB_OTG_FS.pData = pdev;
      // pdev的pData指向hpcd_USB_OTG_FS
      pdev->pData = &hpcd_USB_OTG_FS;
      // 使用USB2 OTG
      hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
      // 端点数为9
      hpcd_USB_OTG_FS.Init.dev_endpoints = 9;			
      // 不使能DMA
      hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
      // 不使能电源充电
      hpcd_USB_OTG_FS.Init.battery_charging_enable = DISABLE;
      // USB全速(12Mbps)	
      hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
      // 使用内部PHY
      hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
      // 不使能SOF中断
      hpcd_USB_OTG_FS.Init.Sof_enable = DISABLE;
      // 不使能低功耗模式
      hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
      // 不使能连接电源管理
      hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
      // 不使能VBUS检测
      hpcd_USB_OTG_FS.Init.vbus_sensing_enable = DISABLE;
      // 禁止EP1 dedicated中断
      hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
      // 初始化LL驱动
      if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
      {
        while(1);
      }

    #if (USE_HAL_PCD_REGISTER_CALLBACKS == 1U)
      /* Register USB PCD CallBacks */
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_SOF_CB_ID, PCD_SOFCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_SETUPSTAGE_CB_ID, PCD_SetupStageCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_RESET_CB_ID, PCD_ResetCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_SUSPEND_CB_ID, PCD_SuspendCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_RESUME_CB_ID, PCD_ResumeCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_CONNECT_CB_ID, PCD_ConnectCallback);
      HAL_PCD_RegisterCallback(&hpcd_USB_OTG_FS, HAL_PCD_DISCONNECT_CB_ID, PCD_DisconnectCallback);

      HAL_PCD_RegisterDataOutStageCallback(&hpcd_USB_OTG_FS, PCD_DataOutStageCallback);
      HAL_PCD_RegisterDataInStageCallback(&hpcd_USB_OTG_FS, PCD_DataInStageCallback);
      HAL_PCD_RegisterIsoOutIncpltCallback(&hpcd_USB_OTG_FS, PCD_ISOOUTIncompleteCallback);
      HAL_PCD_RegisterIsoInIncpltCallback(&hpcd_USB_OTG_FS, PCD_ISOINIncompleteCallback);
    #endif
      // 设置接收FIFO大小为0x200
      HAL_PCDEx_SetRxFiFo(&hpcd_USB_OTG_FS, 0x200);
      // 设置发送FIFO 0的大小为(128字节)
      HAL_PCDEx_SetTxFiFo(&hpcd_USB_OTG_FS, 0, 128);
      // 设置发送FIFO 1的大小为(256字节)
      HAL_PCDEx_SetTxFiFo(&hpcd_USB_OTG_FS, 1, 256);
      // 设置发送FIFO 2的大小为(128字节)
      HAL_PCDEx_SetTxFiFo(&hpcd_USB_OTG_FS, 2, 128);
      // 设置发送FIFO 3的大小为(64字节)
      HAL_PCDEx_SetTxFiFo(&hpcd_USB_OTG_FS, 3, 64);
    }
    
    return USBD_OK;
  }

  /**
   * @author WeiXuan
   * @brief USBD底层取消初始化(回复默认复位状态)函数 
   * @param *pdev USBD句柄指针
   * @returns 0,正常 1,忙 2,失败
   */  
  USBD_StatusTypeDef USBD_LL_DeInit(USBD_HandleTypeDef *pdev)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;
    hal_status = HAL_PCD_DeInit(pdev->pData);
    usb_status =  USBD_Get_USB_Status(hal_status);
    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD底层驱动开始工作
   * @param *pdev USBD句柄指针
   * @returns 0,正常 1,忙 2,失败
   */ 
  USBD_StatusTypeDef USBD_LL_Start(USBD_HandleTypeDef *pdev)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_Start(pdev->pData);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD底层驱动停止工作
   * @param *pdev USBD句柄指针
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_Stop(USBD_HandleTypeDef *pdev)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_Stop(pdev->pData);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD初始化(打开)某个端点
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @param ep_type 端点类型
   * @param ep_mps 端点最大包容量(字节)
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_OpenEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr, uint8_t ep_type, uint16_t ep_mps)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_Open(pdev->pData, ep_addr, ep_mps, ep_type);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD取消初始化(关闭)某个端点
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_CloseEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_Close(pdev->pData, ep_addr);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD清空某个端点的数据
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_FlushEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_Flush(pdev->pData, ep_addr);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD给某个端点设置一个暂停状态
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_StallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_SetStall(pdev->pData, ep_addr);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD取消某个端点的暂停状态
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_ClearStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_ClrStall(pdev->pData, ep_addr);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD返回是否处于暂停状态
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 0,非暂停; 1,暂停.
   */ 
  uint8_t USBD_LL_IsStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    PCD_HandleTypeDef *hpcd = (PCD_HandleTypeDef*) pdev->pData;

    if((ep_addr & 0x80) == 0x80)
    {
      return hpcd->IN_ep[ep_addr & 0x7F].is_stall;
    }
    else
    {
      return hpcd->OUT_ep[ep_addr & 0x7F].is_stall;
    }
  }

  /**
   * @author WeiXuan
   * @brief USBD为设备指定新的USB地址
   * @param *pdev USBD句柄指针
   * @param dev_addr 新的设备地址,USB1_OTG_HS/USB2_OTG_HS
   * @returns 0,正常 1,忙 2,失败
   */ 
  USBD_StatusTypeDef USBD_LL_SetUSBAddress(USBD_HandleTypeDef *pdev, uint8_t dev_addr)
  {
    usb_connectflag = 1;
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_SetAddress(pdev->pData, dev_addr);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD通过端点发送数据
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @param *pbuf 数据缓冲区首地址
   * @param size 要发送的数据大小
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_Transmit(USBD_HandleTypeDef *pdev, uint8_t ep_addr, uint8_t *pbuf, uint32_t size)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_Transmit(pdev->pData, ep_addr, pbuf, size);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD准备一个端点接收数据
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @param *pbuf 数据缓冲区首地址
   * @param size 要接收的数据大小
   * @returns 0,正常 1,忙 2,失败
   */   
  USBD_StatusTypeDef USBD_LL_PrepareReceive(USBD_HandleTypeDef *pdev, uint8_t ep_addr, uint8_t *pbuf, uint32_t size)
  {
    HAL_StatusTypeDef hal_status = HAL_OK;
    USBD_StatusTypeDef usb_status = USBD_OK;

    hal_status = HAL_PCD_EP_Receive(pdev->pData, ep_addr, pbuf, size);

    usb_status =  USBD_Get_USB_Status(hal_status);

    return usb_status;
  }

  /**
   * @author WeiXuan
   * @brief USBD获取最后一个传输包的大小
   * @param *pdev USBD句柄指针
   * @param ep_addr 端点号
   * @returns 包大小
   */ 
  uint32_t USBD_LL_GetRxDataSize(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
  {
    return HAL_PCD_EP_GetRxCount((PCD_HandleTypeDef*) pdev->pData, ep_addr);
  }

  /**
   * @author WeiXuan
   * @brief USBD设置为测试模式
   * @returns USBD状态
   */ 
  #ifdef USBD_HS_TESTMODE_ENABLE
  USBD_StatusTypeDef USBD_LL_SetTestMode(USBD_HandleTypeDef *pdev, uint8_t testmode)
  {
    UNUSED(pdev);
    UNUSED(testmode);

    return USBD_OK;
  }
  #endif

  /**
   * @author WeiXuan
   * @brief USBD 延时函数(以ms为单位) 
   * @param Delay 延时的ms数.
   * @returns 
   */   
  void USBD_LL_Delay(uint32_t Delay)
  {
    HAL_Delay(Delay);
  }

  /**
   * @author WeiXuan
   * @brief 返回USB的状态
   * @param hal_status
   * @returns 
   */   
  USBD_StatusTypeDef USBD_Get_USB_Status(HAL_StatusTypeDef hal_status)
  {
    USBD_StatusTypeDef usb_status = USBD_OK;

    switch (hal_status)
    {
      case HAL_OK :
        usb_status = USBD_OK;
      break;
      case HAL_ERROR :
        usb_status = USBD_FAIL;
      break;
      case HAL_BUSY :
        usb_status = USBD_BUSY;
      break;
      case HAL_TIMEOUT :
        usb_status = USBD_FAIL;
      break;
      default :
        usb_status = USBD_FAIL;
      break;
    }
    return usb_status;
  }
/* USBD LL 驱动接口函数(USB Device Library --> PCD) */