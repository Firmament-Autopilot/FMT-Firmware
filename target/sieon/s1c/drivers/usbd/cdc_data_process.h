/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/cdc_data_process.h
 * @brief Header file for cdc_data_process.c
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
#ifndef __CDC_DATA_PROCESS_H__
#define __CDC_DATA_PROCESS_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "usb_dev_cdc_class.h"

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
/* all needed parameters to be configured for the ComPort.
 * These parameters can modified on the fly by the host through CDC class
 * command class requests. */
typedef struct {
    uint32_t bitrate;
    uint8_t  format;
    uint8_t  paritytype;
    uint8_t  datatype;
} LINE_CODING;

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define DEFAULT_CONFIG              (0U)
#define OTHER_CONFIG                (1U)

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
extern void vcp_init(void);
extern void vcp_deinit(void);
extern void vcp_ctrlpare(uint32_t Cmd, uint8_t *Buf, uint32_t Len);
extern void vcp_txdata(void);
extern void vcp_rxdata(uint8_t *Buf, uint32_t Len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __CDC_DATA_PROCESS_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
