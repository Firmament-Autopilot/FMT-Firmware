/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/usb_app_conf.h
 * @brief low level driver configuration
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
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
#ifndef __USB_APP_CONF_H__
#define __USB_APP_CONF_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/

/* USB MODE CONFIGURATION */
/*
USB_FS_MODE, USB_HS_MODE, USB_HS_EXTERNAL_PHY defined comment
(1) If only defined USB_FS_MODE:
    MCU USBFS core work in full speed using internal PHY.
(2) If only defined USB_HS_MODE:
    MCU USBHS core work in full speed using internal PHY.
(3) If both defined USB_HS_MODE && USB_HS_EXTERNAL_PHY
    MCU USBHS core work in high speed using external PHY.
(4) Other combination:
    Not support, forbid!!
*/

//#define USB_HS_MODE
#define USB_FS_MODE

#define USE_DEVICE_MODE

#ifdef USB_HS_MODE
#define USB_HS_EXTERNAL_PHY
#endif

#ifndef USB_HS_MODE
#ifndef USB_FS_MODE
#error  "USB_HS_MODE or USB_FS_MODE should be defined"
#endif
#endif

#ifndef USE_DEVICE_MODE
#ifndef USE_HOST_MODE
#error  "USE_DEVICE_MODE or USE_HOST_MODE should be defined"
#endif
#endif

/* USB DEVICE ENDPOINT CONFIGURATION */
#define CDC_IN_EP               (0x82U)
#define CDC_OUT_EP              (0x01U)
#define CDC_CMD_EP              (0x85U)

/* USB FIFO CONFIGURATION */
#ifdef USB_FS_MODE
#define RX_FIFO_FS_SIZE         (128U)
#define TX0_FIFO_FS_SIZE        (64U)
#define TX1_FIFO_FS_SIZE        (0U)
#define TX2_FIFO_FS_SIZE        (32U)
#define TX3_FIFO_FS_SIZE        (0U)
#define TX4_FIFO_FS_SIZE        (0U)
#define TX5_FIFO_FS_SIZE        (32U)
#define TX6_FIFO_FS_SIZE        (0U)
#define TX7_FIFO_FS_SIZE        (0U)
#define TX8_FIFO_FS_SIZE        (0U)
#define TX9_FIFO_FS_SIZE        (0U)
#define TX10_FIFO_FS_SIZE       (0U)
#define TX11_FIFO_FS_SIZE       (0U)
#define TX12_FIFO_FS_SIZE       (0U)
#define TX13_FIFO_FS_SIZE       (0U)
#define TX14_FIFO_FS_SIZE       (0U)
#define TX15_FIFO_FS_SIZE       (0U)

#if ((RX_FIFO_FS_SIZE + \
      TX0_FIFO_FS_SIZE + TX1_FIFO_FS_SIZE + TX2_FIFO_FS_SIZE + TX3_FIFO_FS_SIZE + TX4_FIFO_FS_SIZE + \
      TX5_FIFO_FS_SIZE + TX6_FIFO_FS_SIZE + TX7_FIFO_FS_SIZE + TX8_FIFO_FS_SIZE + TX9_FIFO_FS_SIZE + \
      TX10_FIFO_FS_SIZE + TX11_FIFO_FS_SIZE + TX12_FIFO_FS_SIZE + TX13_FIFO_FS_SIZE + TX14_FIFO_FS_SIZE + \
      TX15_FIFO_FS_SIZE) > 640U)
#error  "The USB max FIFO size is 640 x 4 Bytes!"
#endif
#endif

#ifdef USB_HS_MODE
#define RX_FIFO_HS_SIZE         (128U)
#define TX0_FIFO_HS_SIZE        (64U)
#define TX1_FIFO_HS_SIZE        (0U)
#define TX2_FIFO_HS_SIZE        (64U)
#define TX3_FIFO_HS_SIZE        (0U)
#define TX4_FIFO_HS_SIZE        (0U)
#define TX5_FIFO_HS_SIZE        (64U)
#define TX6_FIFO_HS_SIZE        (0U)
#define TX7_FIFO_HS_SIZE        (0U)
#define TX8_FIFO_HS_SIZE        (0U)
#define TX9_FIFO_HS_SIZE        (0U)
#define TX10_FIFO_HS_SIZE       (0U)
#define TX11_FIFO_HS_SIZE       (0U)
#define TX12_FIFO_HS_SIZE       (0U)
#define TX13_FIFO_HS_SIZE       (0U)
#define TX14_FIFO_HS_SIZE       (0U)
#define TX15_FIFO_HS_SIZE       (0U)

#if ((RX_FIFO_HS_SIZE + \
      TX0_FIFO_HS_SIZE + TX1_FIFO_HS_SIZE + TX2_FIFO_HS_SIZE + TX3_FIFO_HS_SIZE + TX4_FIFO_HS_SIZE + \
      TX5_FIFO_HS_SIZE + TX6_FIFO_HS_SIZE + TX7_FIFO_HS_SIZE + TX8_FIFO_HS_SIZE + TX9_FIFO_HS_SIZE + \
      TX10_FIFO_HS_SIZE + TX11_FIFO_HS_SIZE + TX12_FIFO_HS_SIZE + TX13_FIFO_HS_SIZE + TX14_FIFO_HS_SIZE + \
      TX15_FIFO_HS_SIZE) > 2048U)
#error  "The USB max FIFO size is 2048 x 4 Bytes!"
#endif
#endif

/* FUNCTION CONFIGURATION */
#define DEV_MAX_CFG_NUM         (1U)
#define USBD_ITF_MAX_NUM        (1U)
#define USB_MAX_STR_DESC_SIZ    (128U)

#define VBUS_SENSING_ENABLED
//#define SELF_POWER

/* CONFIGURATION FOR CDC */
#define MAX_CDC_PACKET_SIZE     (64U)      /* IN & OUT Endpoint Packet size */
#define CDC_CMD_PACKET_SIZE     (8U)       /* Control Endpoint Packet size */

#define CDC_IN_FRAME_INTERVAL   (1U)       /* Number of frames between IN transfers */
#define APP_TX_DATA_SIZE        (2048U)    /* Total size of IN buffer*/

#ifdef __cplusplus
}
#endif

#endif /* __USB_APP_CONF_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
