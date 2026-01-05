/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/usb_bsp.c
 * @brief BSP function for USB example
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

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "usb_bsp.h"
#include "wl32_ll.h"
#include "usb_dev_int.h"

/**
 * @addtogroup WL32F436_DDL_Applications
 * @{
 */

/**
 * @addtogroup USB_Dev_Cdc
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* unlock/lock peripheral */
#define EXAMPLE_PERIPH_WE               (LL_PERIPH_GPIO | LL_PERIPH_EFM | LL_PERIPH_FCG | \
                                         LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_SRAM)
#define EXAMPLE_PERIPH_WP               (LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_SRAM)

/* KEY10 */
#define KEY10_PORT              (GPIO_PORT_A)
#define KEY10_PIN               (GPIO_PIN_00)
#define KEY10_EXTINT_CH         (EXTINT_CH00)
#define KEY10_INT_SRC           (INT_SRC_PORT_EIRQ0)
#define KEY10_IRQn              (INT003_IRQn)

/* USBFS Core*/
#define USBF_DP_PORT            (GPIO_PORT_A)
#define USBF_DP_PIN             (GPIO_PIN_12)
#define USBF_DM_PORT            (GPIO_PORT_A)
#define USBF_DM_PIN             (GPIO_PIN_11)
#define USBF_VBUS_PORT          (GPIO_PORT_A)
#define USBF_VBUS_PIN           (GPIO_PIN_09)
#define USBF_SOF_PORT           (GPIO_PORT_A)
#define USBF_SOF_PIN            (GPIO_PIN_08)

/* USBHS Core, embedded PHY */
#define USBH_DP_PORT            (GPIO_PORT_B)
#define USBH_DP_PIN             (GPIO_PIN_15)
#define USBH_DM_PORT            (GPIO_PORT_B)
#define USBH_DM_PIN             (GPIO_PIN_14)
#define USBH_VBUS_PORT          (GPIO_PORT_B)
#define USBH_VBUS_PIN           (GPIO_PIN_13)
#define USBH_SOF_PORT           (GPIO_PORT_A)
#define USBH_SOF_PIN            (GPIO_PIN_04)

/* USBHS Core, external PHY */
#define USBH_ULPI_CLK_PORT      (GPIO_PORT_E)
#define USBH_ULPI_CLK_PIN       (GPIO_PIN_12)
#define USBH_ULPI_DIR_PORT      (GPIO_PORT_C)
#define USBH_ULPI_DIR_PIN       (GPIO_PIN_02)
#define USBH_ULPI_NXT_PORT      (GPIO_PORT_C)
#define USBH_ULPI_NXT_PIN       (GPIO_PIN_03)
#define USBH_ULPI_STP_PORT      (GPIO_PORT_C)
#define USBH_ULPI_STP_PIN       (GPIO_PIN_00)
#define USBH_ULPI_D0_PORT       (GPIO_PORT_E)
#define USBH_ULPI_D0_PIN        (GPIO_PIN_13)
#define USBH_ULPI_D1_PORT       (GPIO_PORT_E)
#define USBH_ULPI_D1_PIN        (GPIO_PIN_14)
#define USBH_ULPI_D2_PORT       (GPIO_PORT_E)
#define USBH_ULPI_D2_PIN        (GPIO_PIN_15)
#define USBH_ULPI_D3_PORT       (GPIO_PORT_B)
#define USBH_ULPI_D3_PIN        (GPIO_PIN_10)
#define USBH_ULPI_D4_PORT       (GPIO_PORT_B)
#define USBH_ULPI_D4_PIN        (GPIO_PIN_11)
#define USBH_ULPI_D5_PORT       (GPIO_PORT_B)
#define USBH_ULPI_D5_PIN        (GPIO_PIN_12)
#define USBH_ULPI_D6_PORT       (GPIO_PORT_B)
#define USBH_ULPI_D6_PIN        (GPIO_PIN_13)
#define USBH_ULPI_D7_PORT       (GPIO_PORT_E)
#define USBH_ULPI_D7_PIN        (GPIO_PIN_11)
/* 3300 reset */
#define USB_3300_RESET_PORT     (EIO_PORT1)
#define USB_3300_RESET_PIN      (EIO_USB3300_RST)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static void App_UsbClkIni(void);
/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
extern usb_core_instance usb_dev;

/**
 * @brief  handle the USB interrupt
 * @param  None
 * @retval None
 */
static void USB_IRQ_Handler(void)
{
    usb_isr_handler(&usb_dev);
}

/**
 * @brief  initialize configurations for the BSP
 * @param  [in] pdev                device instance
 * @param  [in] pstcPortIdentify    usb core and phy select
 * @retval None
 */
void usb_bsp_init(usb_core_instance *pdev, stc_usb_port_identify *pstcPortIdentify)
{
  stc_gpio_init_t stcGpioCfg;

  /* Unlock peripherals or registers */
  //App_SysClkIni();

#if (LL_PRINT_ENABLE == DDL_ON)
  //DDL_PrintfInit(BSP_PRINTF_DEVICE, BSP_PRINTF_BAUDRATE, BSP_PRINTF_Preinit);
#endif

  /* USB clock source configure */
  // App_UsbClkIni();
  
  // CLK_SetUSBClockSrc(CLK_USBCLK_PLLR);

#if (LL_PRINT_ENABLE == DDL_ON)
  DDL_Printf("USBFS start !!\r\n");
#endif
  (void)GPIO_StructInit(&stcGpioCfg);
  GPIO_REG_Unlock(); 
  if (USBFS_CORE_ID == pstcPortIdentify->u8CoreID) {
#ifdef USB_FS_MODE
    stcGpioCfg.u16PinAttr = PIN_ATTR_ANALOG;
    (void)GPIO_Init(USBF_DM_PORT, USBF_DM_PIN, &stcGpioCfg);
    (void)GPIO_Init(USBF_DP_PORT, USBF_DP_PIN, &stcGpioCfg);
    GPIO_SetFunc(USBF_VBUS_PORT, USBF_VBUS_PIN, GPIO_FUNC_10); /* VBUS */
    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_USBFS, ENABLE);
#endif
  } else {
#ifdef USB_HS_MODE
    if (USBHS_PHY_EMBED == pstcPortIdentify->u8PhyType) {
      /* USBHS work in embedded PHY */
      stcGpioCfg.u16PinAttr = PIN_ATTR_ANALOG;
      (void)GPIO_Init(USBH_DM_PORT, USBH_DM_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_DP_PORT, USBH_DP_PIN, &stcGpioCfg);
      GPIO_SetFunc(USBH_VBUS_PORT, USBH_VBUS_PIN, GPIO_FUNC_12);
    } else {
      /* Reset 3300 */
      BSP_IO_WritePortPin(USB_3300_RESET_PORT, USB_3300_RESET_PIN, EIO_PIN_SET);
      BSP_IO_ConfigPortPin(USB_3300_RESET_PORT, USB_3300_RESET_PIN, EIO_DIR_OUT);

      (void)GPIO_StructInit(&stcGpioCfg);
      /* High drive capability */
      stcGpioCfg.u16PinDrv = PIN_HIGH_DRV;
      (void)GPIO_Init(USBH_ULPI_D0_PORT, USBH_ULPI_D0_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D1_PORT, USBH_ULPI_D1_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D2_PORT, USBH_ULPI_D2_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D3_PORT, USBH_ULPI_D3_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D4_PORT, USBH_ULPI_D4_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D5_PORT, USBH_ULPI_D5_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D6_PORT, USBH_ULPI_D6_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_D7_PORT, USBH_ULPI_D7_PIN, &stcGpioCfg);
      (void)GPIO_Init(USBH_ULPI_STP_PORT, USBH_ULPI_STP_PIN, &stcGpioCfg);

      GPIO_SetFunc(USBH_ULPI_CLK_PORT, USBH_ULPI_CLK_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_DIR_PORT, USBH_ULPI_DIR_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_NXT_PORT, USBH_ULPI_NXT_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_STP_PORT, USBH_ULPI_STP_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D0_PORT, USBH_ULPI_D0_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D1_PORT, USBH_ULPI_D1_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D2_PORT, USBH_ULPI_D2_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D3_PORT, USBH_ULPI_D3_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D4_PORT, USBH_ULPI_D4_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D5_PORT, USBH_ULPI_D5_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D6_PORT, USBH_ULPI_D6_PIN, GPIO_FUNC_10);
      GPIO_SetFunc(USBH_ULPI_D7_PORT, USBH_ULPI_D7_PIN, GPIO_FUNC_10);

      BSP_IO_WritePortPin(USB_3300_RESET_PORT, USB_3300_RESET_PIN, EIO_PIN_RESET);
    }
    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_USBHS, ENABLE);
#endif
  }
}

/**
 * @brief  configure the NVIC of USB
 * @param  [in] pdev                    device instance
 * @retval None
 */
void usb_bsp_nvicconfig(usb_core_instance *pdev)
{
  stc_irq_signin_config_t stcIrqRegiConf;
  /* Register INT_SRC_USBFS_GLB Int to Vect.No.030 */
  stcIrqRegiConf.enIRQn = INT030_IRQn;
  /* Select interrupt function */
#ifdef USB_FS_MODE
  stcIrqRegiConf.enIntSrc = INT_SRC_USBFS_GLB;
#else
  stcIrqRegiConf.enIntSrc = INT_SRC_USBHS_GLB;
#endif
  /* Callback function */
  stcIrqRegiConf.pfnCallback = &USB_IRQ_Handler;
  /* Registration IRQ */
  (void)INTC_IrqSignIn(&stcIrqRegiConf);
  /* Clear Pending */
  NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
  /* Set priority */
  NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIO_15);
  /* Enable NVIC */
  NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);
}

/**
 * @brief  This function provides delay time in micro sec
 * @param  [in] usec        Value of delay required in micro sec
 * @retval None
 */
void usb_udelay(const uint32_t usec)
{
  __IO uint32_t i;
  uint32_t j;
  j = (HCLK_VALUE + 1000000UL - 1UL) / 1000000UL * usec;
  for (i = 0UL; i < j; i++) {
  }
}

/**
 * @brief  This function provides delay time in milli sec
 * @param  [in] msec        Value of delay required in milli sec
 * @retval None
 */
void usb_mdelay(const uint32_t msec)
{
  usb_udelay(msec * 1000UL);
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
