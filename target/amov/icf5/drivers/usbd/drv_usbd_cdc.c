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

#include "drv_usbd_cdc.h"
#include "hal/usb/usbd_cdc.h"
#include "module/utils/ringbuffer.h"

#include "cdc_acm_core.h"
#include "drv_usbd_int.h"

static struct usbd_cdc_dev usbd_dev;
usb_core_driver cdc_acm;

/*!
    \brief      this function handles USBFS wakeup interrupt handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USBFS_WKUP_IRQHandler(void)
{
}

/*!
    \brief      this function handles USBFS IRQ Handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USBFS_IRQHandler(void)
{
    rt_interrupt_enter();
    usbd_isr(&cdc_acm);
    rt_interrupt_leave();
}

/*!
    \brief      delay in micro seconds
    \param[in]  usec: value of delay required in micro seconds
    \param[out] none
    \retval     none
*/
void usb_udelay(const uint32_t usec)
{
    systime_udelay(usec);
}

/*!
    \brief      delay in milliseconds
    \param[in]  msec: value of delay required in milliseconds
    \param[out] none
    \retval     none
*/
void usb_mdelay(const uint32_t msec)
{
    systime_mdelay(msec);
}

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);

    return rb;
}

static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    usb_cdc_handler* cdc = (usb_cdc_handler*)(&cdc_acm)->dev.class_data[CDC_COM_INTERFACE];
    uint32_t tx_size = size > USB_TX_DATA_SIZE ? USB_TX_DATA_SIZE : size;

    rt_memcpy(cdc->tx_buffer, buf, tx_size);
    cdc->tx_length = tx_size;

    cdc_acm_data_send(&cdc_acm);

    return tx_size;
}

void drv_usbd_cdc_connect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);

    /* endpoint prepare to receive data */
    cdc_acm_data_receive(&cdc_acm);

    // printf("usb connect\n");
}

void drv_usbd_cdc_disconnect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);

    // printf("usb disconnect\n");
}

void drv_usbd_cdc_receive(uint8_t* buffer, uint32_t size)
{
    if (usbd_dev.rx_rb == NULL) {
        /* usbd is not initialized */
        return;
    }

    (void)ringbuffer_put(usbd_dev.rx_rb, buffer, size);

    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);
}

void drv_usbd_cdc_transmist_complete(uint8_t* buffer, uint32_t size)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);
}

static void usb_gpio_config(void)
{
    rcu_periph_clock_enable(RCU_SYSCFG);

    rcu_periph_clock_enable(RCU_GPIOA);

    /* USBFS_DM(PA11) and USBFS_DP(PA12) GPIO pin configuration */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11 | GPIO_PIN_12);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11 | GPIO_PIN_12);

    gpio_af_set(GPIOA, GPIO_AF_10, GPIO_PIN_11 | GPIO_PIN_12);
}

static void usb_rcu_config(void)
{
#ifndef USE_IRC48M
    rcu_pll48m_clock_config(RCU_PLL48MSRC_PLLQ);

    rcu_ck48m_clock_config(RCU_CK48MSRC_PLL48M);
#else
    /* enable IRC48M clock */
    rcu_osci_on(RCU_IRC48M);

    /* wait till IRC48M is ready */
    while (SUCCESS != rcu_osci_stab_wait(RCU_IRC48M)) {
    }

    rcu_ck48m_clock_config(RCU_CK48MSRC_IRC48M);
#endif /* USE_IRC48M */

    rcu_periph_clock_enable(RCU_USBFS);
}

static void usb_intr_config(void)
{
    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    nvic_irq_enable((uint8_t)USBFS_IRQn, 2U, 0U);
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

    usb_gpio_config();
    usb_rcu_config();

    usbd_init(&cdc_acm,
              USB_CORE_ENUM_FS,
              &cdc_desc,
              &cdc_class);

    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }

    usb_intr_config();

    return RT_EOK;
}
