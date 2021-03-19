/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2017-12-12     ZYH               the first version
 * 2019-12-19     tyustli           port to stm32 series
 */
#ifndef __DRV_USBD_CDC_H__
#define __DRV_USBD_CDC_H__
#include <rtthread.h>

#include "finsh.h"
#include "shell.h"
#include "module/utils/ringbuffer.h"

#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "usbd_desc.h"
#include "usbd_core.h"
#include "usbd_ctlreq.h"
#include "usbd_def.h"
#include "usbd_ioreq.h"
#include "usbd_cdc_dev.h"
#include "usbd_conf.h"

rt_err_t drv_usb_cdc_init(void);

#endif

/************* end of file ************/
