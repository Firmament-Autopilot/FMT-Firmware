/** 
 * @brief usb cdc接口配置
 * @author WeiXuan <2020302121154@whu.edu.cn
 * @file usbd_cdc_interface.c
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */
 
#include "usbd_cdc_if.h"
#include "string.h"	
#include "stdbool.h"	
#include "stdarg.h"		 
#include "stdio.h"	
#include <stdint.h>
#include <firmament.h>

// USB接收数据缓冲区
uint8_t UserRxBuffer[APP_RX_DATA_SIZE];

// USB发送数据缓冲区
uint8_t UserTxBuffer[APP_TX_DATA_SIZE];

void drv_usbd_cdc_receive(uint8_t* buffer, uint32_t size);
void drv_usbd_cdc_transmist_complete(uint8_t* buffer, uint32_t size);

extern USBD_HandleTypeDef hUsbDevice;

static int8_t CDC_Init(void);
static int8_t CDC_DeInit(void);
static int8_t CDC_Control(uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t CDC_Receive(uint8_t* pbuf, uint32_t *Len);
static int8_t CDC_TransmitCplt(uint8_t *pbuf, uint32_t *Len, uint8_t epnum);

USBD_CDC_ItfTypeDef USBD_Interface_fops =
{
  CDC_Init,
  CDC_DeInit,
  CDC_Control,
  CDC_Receive,
  CDC_TransmitCplt
};

/**
 * @author WeiXuan
 * @brief 初始化CDC串口
 * @returns USBD_OK
 */
static int8_t CDC_Init(void)
{
  USBD_HandleTypeDef *pdev = &hUsbDevice;
  uint8_t idx = USBD_CoreFindEP(pdev, CDC_IN_EP);
  USBD_CDC_SetTxBuffer(&hUsbDevice, UserTxBuffer, 0, idx);
  USBD_CDC_SetRxBuffer(&hUsbDevice, UserRxBuffer);
  return (USBD_OK);
}

/**
 * @author WeiXuan
 * @brief 复位CDC串口
 * @returns USBD_OK
 */
static int8_t CDC_DeInit(void)
{
  return (USBD_OK);
}

/**
 * @author WeiXuan
 * @brief 控制CDC串口的设置
 * @param cmd 
 * @param pbuf 命令数据缓冲区/参数保存缓冲区
 * @param length 数据长度
 * @returns USBD_OK
 */
static int8_t CDC_Control(uint8_t cmd, uint8_t* pbuf, uint16_t length)
{
  switch(cmd)
  {
    case CDC_SEND_ENCAPSULATED_COMMAND:break;
    case CDC_GET_ENCAPSULATED_RESPONSE:break;
    case CDC_SET_COMM_FEATURE:break;
    case CDC_GET_COMM_FEATURE:break;
    case CDC_CLEAR_COMM_FEATURE:break;
    case CDC_SET_LINE_CODING:break;
    case CDC_GET_LINE_CODING:break;
    case CDC_SET_CONTROL_LINE_STATE:break;
    case CDC_SEND_BREAK:break;
    default:break;
  }
  return (USBD_OK);
}

/**
 * @author WeiXuan
 * @brief 处理从USB虚拟串口接收到的数据 
 * @param Buf 数据缓存区
 * @param Len 接收到的字节数
 * @returns USBD_OK
 */
static int8_t CDC_Receive(uint8_t* Buf, uint32_t *Len)
{
  drv_usbd_cdc_receive(Buf, *Len);
  USBD_CDC_SetRxBuffer(&hUsbDevice, &Buf[0]);
  USBD_CDC_ReceivePacket(&hUsbDevice);
  return (USBD_OK);
}

/**
 * @author WeiXuan
 * @brief 通过USB发送数据
 * @param *Buf 要发送的数据
 * @param Len 数据长度
 * @returns 
 */
uint8_t CDC_Transmit(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  USBD_HandleTypeDef *pdev = &hUsbDevice;
  uint8_t idx = USBD_CoreFindEP(pdev, CDC_IN_EP);
  if (((uint8_t)idx != 0xFFU) && (idx < USBD_MAX_SUPPORTED_CLASS))
  {
    pdev->classId = idx;

    USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDevice.pClassDataCmsit[pdev->classId];
    if (hcdc->TxState != 0)
    {
      return USBD_BUSY;
    }
    USBD_CDC_SetTxBuffer(pdev, Buf, Len, idx);
    result = USBD_CDC_TransmitPacket(pdev,idx);

    return result;
  }
  return USBD_FAIL;
}

/**
 * @author WeiXuan
 * @brief USB发送完成回调函数
 * @param *Buf 要发送的数据
 * @param Len 数据长度
 * @returns 
 */
static int8_t CDC_TransmitCplt(uint8_t *Buf, uint32_t *Len, uint8_t epnum)
{
  uint8_t result = USBD_OK;
  UNUSED(Buf);
  UNUSED(Len);
  UNUSED(epnum);
  drv_usbd_cdc_transmist_complete(Buf, *Len);
  return result;
}
