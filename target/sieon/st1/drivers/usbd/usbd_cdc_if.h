/** 
 * @brief usb cdc接口配置
 * @author WeiXuan <2020302121154@whu.edu.cn
 * @file usbd_cdc_interface.h
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */
#ifndef __USBD_CDC_IF_H__
#define __USBD_CDC_IF_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "usbd_cdc.h"

// USB串口缓冲区最大字节数
#define APP_RX_DATA_SIZE  2048
#define APP_TX_DATA_SIZE  2048

extern USBD_CDC_ItfTypeDef USBD_Interface_fops;

/**
 * @author WeiXuan
 * @brief 通过USB发送数据
 * @param *data 要发送的数据
 * @param Len 数据长度
 * @returns 
 */
uint8_t CDC_Transmit(uint8_t* Buf, uint16_t Len);

#ifdef __cplusplus
}
#endif

#endif 

