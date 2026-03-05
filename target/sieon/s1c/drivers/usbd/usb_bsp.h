/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/usb_bsp.h
 * @brief Head file for usb_bsp.c
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2022-10-31       CDT             Add USB core ID select function
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
#ifndef __USB_BSP_H__
#define __USB_BSP_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "usb_lib.h"

/**
 * @addtogroup WL32F436_DDL_Applications
 * @{
 */

/**
 * @addtogroup USB_Dev_Cdc
 * @{
 */

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/


/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
void usb_bsp_init(usb_core_instance *pdev, stc_usb_port_identify *pstcPortIdentify);
void usb_udelay(const uint32_t usec);
void usb_mdelay(const uint32_t msec);
void usb_bsp_nvicconfig(usb_core_instance *pdev);

/**
 * @}
 */

/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __USB_BSP_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
