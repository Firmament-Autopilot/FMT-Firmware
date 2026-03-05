/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/usb_dev_desc.c
 * @brief USB descriptor define and function for example
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2022-10-31       CDT             Modify DEV_MANUFACTURER_STRING
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2023, wlhc Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by WLHC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "usb_dev_desc.h"
#include "usb_dev_stdreq.h"

/**
 * @addtogroup WL32F436_DDL_Applications
 * @{
 */

/**
 * @addtogroup USB_Dev_Cdc
 * @{
 */

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define DEV_VID                        (0x2E88)
#define DEV_PID                        (0x4603)

#define DEV_LANGID_STRING              (0x409)
#define DEV_MANUFACTURER_STRING        ("WLHC")
#define DEV_PRODUCT_FS_STRING          ("Device of CDC")
#define DEV_SERIALNUMBER_FS_STRING     ("00000000050C")
#define DEV_CONFIGURATION_FS_STRING    ("CDC Config")
#define DEV_INTERFACE_FS_STRING        ("CDC Interface")

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
uint8_t *usb_dev_desc(uint16_t *length);
uint8_t *usb_dev_langiddesc(uint16_t *length);
uint8_t *usb_dev_manufacturerstr(uint16_t *length);
uint8_t *usb_dev_productdesc(uint16_t *length);
uint8_t *usb_dev_serialstr(uint16_t *length);
uint8_t *usb_dev_configstrdesc(uint16_t *length);
uint8_t *usb_dev_intfstrdesc(uint16_t *length);

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/
usb_dev_desc_func user_desc = {
    &usb_dev_desc,
    &usb_dev_langiddesc,
    &usb_dev_manufacturerstr,
    &usb_dev_productdesc,
    &usb_dev_serialstr,
    &usb_dev_configstrdesc,
    &usb_dev_intfstrdesc,
};

/* USB Standard Device Descriptor */
__USB_ALIGN_BEGIN static uint8_t usb_dev_devicedesc[USB_SIZ_DEVICE_DESC] = {
    0x12,                       /* bLength */
    USB_DEVICE_DESCRIPTOR_TYPE, /* bDescriptorType */
    0x00,                       /* bcdUSB */
    0x02,
    0x00,                       /* bDeviceClass */
    0x00,                       /* bDeviceSubClass */
    0x00,                       /* bDeviceProtocol */
    USB_MAX_EP0_SIZE,           /* bMaxPacketSize */
    LOBYTE(DEV_VID),            /* idVendor */
    HIBYTE(DEV_VID),            /* idVendor */
    LOBYTE(DEV_PID),            /* idVendor */
    HIBYTE(DEV_PID),            /* idVendor */
    0x00,                       /* bcdDevice rel. 2.00 */
    0x02,
    MFC_STR_IDX,                /* Index of manufacturer string */
    PRODUCT_STR_IDX,            /* Index of product string */
    SERIAL_STR_IDX,             /* Index of serial number string */
    DEV_MAX_CFG_NUM             /* bNumConfigurations */
} ;

/* USB Standard Device Descriptor */
__USB_ALIGN_BEGIN static uint8_t USB_DEV_LangIDDesc[USB_SIZ_STRING_LANGID] = {
    USB_SIZ_STRING_LANGID,
    USB_DESC_TYPE_STRING,
    LOBYTE(DEV_LANGID_STRING),
    HIBYTE(DEV_LANGID_STRING),
};

__USB_ALIGN_BEGIN static uint8_t usb_dev_strdesc[USB_MAX_STR_DESC_SIZ];

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  return the device descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_desc(uint16_t *length)
{
    *length = (uint16_t)sizeof(usb_dev_devicedesc);
    return usb_dev_devicedesc;
}

/**
 * @brief  return the LangID string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_langiddesc(uint16_t *length)
{
    *length = (uint16_t)sizeof(USB_DEV_LangIDDesc);
    return USB_DEV_LangIDDesc;
}

/**
 * @brief  return the product string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_productdesc(uint16_t *length)
{
    usb_getstring((uint8_t *)DEV_PRODUCT_FS_STRING, usb_dev_strdesc, length);
    return usb_dev_strdesc;
}

/**
 * @brief  return the manufacturer string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_manufacturerstr(uint16_t *length)
{
    usb_getstring((uint8_t *)DEV_MANUFACTURER_STRING, usb_dev_strdesc, length);
    return usb_dev_strdesc;
}

/**
 * @brief  return the serial number string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_serialstr(uint16_t *length)
{
    usb_getstring((uint8_t *)DEV_SERIALNUMBER_FS_STRING, usb_dev_strdesc, length);
    return usb_dev_strdesc;
}

/**
 * @brief  return the configuration string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_configstrdesc(uint16_t *length)
{
    usb_getstring((uint8_t *)DEV_CONFIGURATION_FS_STRING, usb_dev_strdesc, length);
    return usb_dev_strdesc;
}

/**
 * @brief  return the interface string descriptor
 * @param  [in] length      pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t *usb_dev_intfstrdesc(uint16_t *length)
{
    usb_getstring((uint8_t *)DEV_INTERFACE_FS_STRING, usb_dev_strdesc, length);
    return usb_dev_strdesc;
}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
