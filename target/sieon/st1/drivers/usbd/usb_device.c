/**
 * @brief usb_device 驱动代码
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file usb_device.c
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_cdc.h"
#include "usbd_msc.h"
#include "usbd_storage_if.h"
#include "usbd_cdc_if.h"
#include "usbd_desc.h"

USBD_HandleTypeDef hUsbDevice;

uint8_t epnums_CDC[] = {CDC_IN_EP, CDC_OUT_EP, CDC_CMD_EP};
uint8_t epnums_MSC[] = {MSC_EPIN_ADDR, MSC_EPOUT_ADDR};

void MX_USB_DEVICE_Init(void)
{
  if (USBD_Init(&hUsbDevice, &USBD_Desc, DEVICE_FS) != USBD_OK)
  {
    while(1);
  }

  if (USBD_CDC_RegisterInterface(&hUsbDevice, &USBD_Interface_fops) != USBD_OK)
  {
    while(1);
  }

  if (USBD_RegisterClassComposite(&hUsbDevice, &USBD_CDC, CLASS_TYPE_CDC, &epnums_CDC[0]) != USBD_OK)
  {
    while(1);
  }

  if (USBD_MSC_RegisterStorage(&hUsbDevice, &USBD_Storage_Interface_fops) != USBD_OK)
  {
    while(1);
  }

  if (USBD_RegisterClassComposite(&hUsbDevice, &USBD_MSC, CLASS_TYPE_MSC, &epnums_MSC[0]) != USBD_OK)
  {
    while(1);
  }
  
	// 开启USB
  if (USBD_Start(&hUsbDevice) != USBD_OK)
  {
    while(1);
  }

  HAL_PWREx_EnableUSBVoltageDetector();
}
