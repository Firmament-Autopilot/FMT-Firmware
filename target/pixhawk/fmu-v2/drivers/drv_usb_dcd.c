/******************************************************************************
 * Copyright 2020-2025 The Firmament Authors. All Rights Reserved.
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
#include "usbd_core.h"
#include "board.h"
#include "stm32f4xx.h"
#include "module/system/systime.h"

#ifdef USBD_USING_IRQ_THREAD

#ifndef USB_IRQ_THREAD_PRIO
#define USB_IRQ_THREAD_PRIO 13
#endif
rt_sem_t sem_usb_irq;
rt_thread_t usb_irq_thread;
#ifndef USB_IRQ_THREAD_STACK_SZ
#define USB_IRQ_THREAD_STACK_SZ 2048
#endif

/**
* @brief This function handles USB On The Go FS global interrupt.
*/
void OTG_FS_IRQHandler(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    rt_interrupt_enter();
    // Mask interrupt, and signal processing of interrupt by usb_cmd_thread
    // The thread will re-enable the interrupt when all pending irqs are clear.
    NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
    NVIC_Init(&NVIC_InitStructure);
    rt_sem_release(sem_usb_irq);
    rt_interrupt_leave();
}
void usb_deferred_interrupt_thread(void * ctx) {
    (void) ctx; // unused parameter
    NVIC_InitTypeDef NVIC_InitStructure;

    for (;;) {
        // Wait for signalling from USB interrupt (OTG_FS_IRQHandler)
        if (RT_EOK == rt_sem_take(sem_usb_irq, RT_WAITING_FOREVER)) {
            // We have a new incoming USB transmission: handle it
            USBD_IRQHandler(0);
            // Let the irq (OTG_FS_IRQHandler) fire again.
            NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
            NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
            NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
            NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
            NVIC_Init(&NVIC_InitStructure);
        }
    }
}

void init_deferred_interrupts(void) {
    // Init usb irq binary semaphore, and start with no tokens by removing the starting one.
    sem_usb_irq = rt_sem_create("usb_irq", 0, RT_IPC_FLAG_FIFO);
    // Start USB interrupt handler thread
    usb_irq_thread = rt_thread_create("usb_irq", usb_deferred_interrupt_thread, RT_NULL, USB_IRQ_THREAD_STACK_SZ, USB_IRQ_THREAD_PRIO, 10);
    rt_thread_startup(usb_irq_thread);
}
#else
void OTG_FS_IRQHandler(void)
{
    rt_interrupt_enter();
    USBD_IRQHandler(0);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif

void EXTI9_5_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line9) != RESET) {
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == SET) {
            // USB connect
            usbd_event_connect_handler(0);
        } else {
            // USB disconnect
            usbd_event_disconnect_handler(0);
        }
        EXTI_ClearITPendingBit(EXTI_Line9);
    }
}

void usb_dc_low_level_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;

#ifdef USBD_USING_IRQ_THREAD
    init_deferred_interrupts();
#endif

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    /**USB_OTG_FS GPIO Configuration
    PA11     ------> USB_OTG_FS_DM
    PA12     ------> USB_OTG_FS_DP
    */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_OTG1_FS);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_OTG1_FS);

    /* Configure  VBUS Pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_OTG_FS, ENABLE);

    /* USB_OTG_FS interrupt Init */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* VBUS Detect Pin 
     * Configure EXTI line9 (connected to PA9) in interrupt mode 9_5 */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource9);

    EXTI_InitStructure.EXTI_Line = EXTI_Line9;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void usb_dc_low_level_deinit(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
    NVIC_Init(&NVIC_InitStructure);
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_OTG_FS, DISABLE);

    /**USB_OTG_FS GPIO Configuration
    PA11     ------> USB_OTG_FS_DM
    PA12     ------> USB_OTG_FS_DP
    */

}

uint32_t usbd_get_dwc2_gccfg_conf(uint32_t reg_base)
{
#if __has_include("stm32h7xx.h") || __has_include("stm32f7xx.h") || __has_include("stm32l4xx.h")
#define USB_OTG_GLB ((USB_OTG_GlobalTypeDef *)(reg_base))
    /* B-peripheral session valid override enable */
    USB_OTG_GLB->GOTGCTL |= USB_OTG_GOTGCTL_BVALOEN;
    USB_OTG_GLB->GOTGCTL |= USB_OTG_GOTGCTL_BVALOVAL;
#endif

#ifdef CONFIG_USB_HS
#if defined(STM32F722xx) || defined(STM32F723xx) || defined(STM32F730xx) || defined(STM32F732xx) || defined(STM32F733xx)
    USB_OTG_GLB->GCCFG = (1 << 23);
    usb_hsphy_init(25000000U);
    return (1 << 23); /* Enable USB HS PHY USBx->GCCFG |= USB_OTG_GCCFG_PHYHSEN;*/
#elif __has_include("stm32h7rsxx.h")
    return (1 << 21);
#else
    return 0;
#endif
#else
#if __has_include("stm32h7xx.h") || __has_include("stm32f7xx.h") || __has_include("stm32l4xx.h")
    return (1 << 16);
#else
    return ((1 << 16) | (1 << 21));
#endif
#endif
}

void usbd_dwc2_delay_ms(uint8_t ms)
{
    systime_mdelay(ms);
}
