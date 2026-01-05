/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>

#include "usb_dev_user.h"
#include "usb_dev_desc.h"
#include "usb_dev_cdc_class.h"

#include "hal/usb/usbd_cdc.h"
#include "module/utils/ringbuffer.h"

// #include "cdc_acm_core.h"
// #include "drv_usbd_int.h"

usb_core_instance  usb_dev;
static struct usbd_cdc_dev usbd_dev;
#define USB_TX_BUF_SIZE 2048
uint8_t usb_tx_buf[USB_TX_BUF_SIZE + 5];
//usb_core_driver cdc_acm;

/*!
    \brief      this function handles USBFS wakeup interrupt handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
// void USBFS_WKUP_IRQHandler(void)
// {
// }
/**
 * @brief  usb_dev_user_init
 * @param  None
 * @retval None
 */
#if 0

/*!
    \brief      this function handles USBFS IRQ Handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
// void USBFS_IRQHandler(void)
// {
//     rt_interrupt_enter();
//     usbd_isr(&cdc_acm);
//     rt_interrupt_leave();
// }

/*!
    \brief      delay in micro seconds
    \param[in]  usec: value of delay required in micro seconds
    \param[out] none
    \retval     none
*/
// void usb_udelay(const uint32_t usec)
// {
//     systime_udelay(usec);
// }

/*!
    \brief      delay in milliseconds
    \param[in]  msec: value of delay required in milliseconds
    \param[out] none
    \retval     none
*/
// void usb_mdelay(const uint32_t msec)
// {
//     systime_mdelay(msec);
// }


/**
 * @brief  usb_dev_user_conn
 * @param  None
 * @retval None
 */
void usb_dev_user_conn(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
#if (LL_PRINT_ENABLE == DDL_ON)
    DDL_Printf(">>USB device connects.\r\n");
#endif
}

/**
 * @brief  USBD_USR_DeviceDisonnected
 * @param  None
 * @retval None
 */
void usb_dev_user_disconn(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);
#if (LL_PRINT_ENABLE == DDL_ON)
    DDL_Printf(">>USB device disconnected.\r\n");
#endif
}


// static void usb_gpio_config(void)
// {
//     rcu_periph_clock_enable(RCU_SYSCFG);

//     rcu_periph_clock_enable(RCU_GPIOA);

//     /* USBFS_DM(PA11) and USBFS_DP(PA12) GPIO pin configuration */
//     gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11 | GPIO_PIN_12);
//     gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11 | GPIO_PIN_12);

//     gpio_af_set(GPIOA, GPIO_AF_10, GPIO_PIN_11 | GPIO_PIN_12);
// }


// static void usb_intr_config(void)
// {
//     nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
//     nvic_irq_enable((uint8_t)USBFS_IRQn, 2U, 0U);
// }
#endif

void drv_usbd_cdc_transmist_complete(uint8_t* buffer, uint32_t size)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);
}

void usb_dev_user_init(void)
{ 
    usbd_cdc_dev_t usbd = &usbd_dev;
    rt_err_t err = RT_EOK;

    //RT_ASSERT(dev != RT_NULL);

    usbd->rx_rb = ringbuffer_create(USB_TX_BUF_SIZE);
    if (usbd->rx_rb == NULL) {
        return FMT_ENOMEM;
    }

    usbd->tx_lock = rt_mutex_create("usbd_tx", RT_IPC_FLAG_FIFO);
    if (usbd->tx_lock == NULL) {
        return FMT_ENOMEM;
    }

    if (usbd->ops->dev_init) {
        err = usbd->ops->dev_init(usbd);
    }
    return err;
    /* Add initial code here */
}
void drv_mbtls_ota_mode_config(void);
uint8_t ota_cmd_start[] = "ew_nowstart_otakey";
uint8_t ota_cmd_key[] = {0xf5,0x50,0x73,0x15,0xa0,0x02,0x57,0x05,0x37,0x51,0x0a,0x20};
uint8_t ota_sta = 0;
void drv_usbd_cdc_receive(uint8_t* buffer, uint32_t size)
{
    if (usbd_dev.rx_rb == NULL) {
        /* usbd is not initialized */
        return;
    }

    if(ota_sta)
    {
        if(memcmp(buffer, ota_cmd_key, sizeof(ota_cmd_key - 1)) == 0)
        {
            //ota
            drv_mbtls_ota_mode_config();
        }
        else
            ota_sta = 0;
    }
    else
    {
        if(memcmp(buffer,ota_cmd_start,sizeof(ota_cmd_start - 1)) == 0)
            ota_sta = 1;
    }

    (void)ringbuffer_put(usbd_dev.rx_rb, buffer, size);

    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);
}

void drv_usbd_cdc_connect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);

    /* endpoint prepare to receive data */
    //cdc_acm_data_receive(&cdc_acm);

    // printf("usb connect\n");
}

void drv_usbd_cdc_disconnect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);

    //printf("usb disconnect\n");
}

/**
 * @brief  usb_dev_user_conn
 * @param  None
 * @retval None
 */
void usb_dev_user_conn(void)
{
    drv_usbd_cdc_connect_cb();
#if (LL_PRINT_ENABLE == DDL_ON)
    //DDL_Printf(">>USB device connects.\r\n");
#endif
}

/**
 * @brief  USBD_USR_DeviceDisonnected
 * @param  None
 * @retval None
 */
void usb_dev_user_disconn(void)
{
    drv_usbd_cdc_disconnect_cb();
#if (LL_PRINT_ENABLE == DDL_ON)
    //DDL_Printf(">>USB device disconnected.\r\n");
#endif
}
static void usb_rcu_config(void)
{
    
    stc_usb_port_identify stcPortIdentify;
#if defined (USB_FS_MODE)
    stcPortIdentify.u8CoreID = USBFS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EMBED;
#elif defined (USB_HS_MODE) && (!defined (USB_HS_EXTERNAL_PHY))
    stcPortIdentify.u8CoreID = USBHS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EMBED;
#elif defined (USB_HS_MODE) && (defined (USB_HS_EXTERNAL_PHY))
    stcPortIdentify.u8CoreID = USBHS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EXT;
#endif
    usb_dev_init(&usb_dev, &stcPortIdentify, &user_desc, &class_cdc_cbk, &user_cb);
    //DDL_DelayMS(3000);
}
uint8_t tmp_buf_usb[64];

void tmp_test_usb(void)
{
    return;
    memset(&tmp_buf_usb,0xf5,63);
    usb_deveptx(&usb_dev,
                CDC_IN_EP,
                tmp_buf_usb,
                (uint32_t)63);
}
uint16_t usb_write_busy = 0;
void usb_send_relady(void)
{
    if(usb_write_busy>0)
        usb_write_busy--;
}

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);

    return rb;
}
extern uint32_t APP_Rx_length;
extern void process_asynchdata_usb2usb(void *pdev);
uint8_t u8cdcinterfacestart = 0;
static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    uint32_t tx_size = size > MAX_CDC_OUT_PACKET_SIZE?MAX_CDC_OUT_PACKET_SIZE:size;
    usb_data_send(buf,size);
#if 0
    rt_memcpy(usb_tx_buf,buf,tx_size);
    //usb_readytorx(&usb_dev, CDC_OUT_EP, (uint8_t *)(usb_tx_buf), MAX_CDC_OUT_PACKET_SIZE);

    APP_Rx_length = size;
    memcpy(uart_rx_buffer,buf,APP_Rx_length);
    // for(uint16_t u16count = 0;u16count< APP_Rx_length;u16count++)
    // {
    //     uart_rx_buffer[u16count] = buf[u16count];
    // }
    if(u8cdcinterfacestart)
    process_asynchdata_usb2usb(&usb_dev);
#endif
    // if(usb_write_busy)
    //     return 0;
    // usb_write_busy = 210;
    // //memset(&tmp_buf_usb,0xf5,63);
    // usb_deveptx(&usb_dev,
    //             CDC_IN_EP,
    //             buf,
    //             (uint32_t)MAX_CDC_OUT_PACKET_SIZE+5);

    // usb_deveptx(&usb_dev,
    //             CDC_IN_EP,
    //             usb_tx_buf,
    //             (uint32_t)tx_size);
    //usb_cdc_handler* cdc = (usb_cdc_handler*)(&cdc_acm)->dev.class_data[CDC_COM_INTERFACE];
    // uint32_t tx_size = size > USB_TX_DATA_SIZE ? USB_TX_DATA_SIZE : size;

    // rt_memcpy(cdc->tx_buffer, buf, tx_size);
    // cdc->tx_length = tx_size;

    // cdc_acm_data_send(&cdc_acm);

    return tx_size;
}

struct usbd_cdc_ops usbd_ops = {
    .dev_init = NULL,
    .dev_read = usbd_cdc_read,
    .dev_write = usbd_cdc_write,
    .dev_control = NULL
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t err;
    usbd_dev.ops = &usbd_ops;

    //usb_gpio_config();
    usb_rcu_config();

    // usbd_init(&cdc_acm,
    //           USB_CORE_ENUM_FS,
    //           &cdc_desc,
    //           &cdc_class);

    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }

    //usb_intr_config();

    return RT_EOK;
}
