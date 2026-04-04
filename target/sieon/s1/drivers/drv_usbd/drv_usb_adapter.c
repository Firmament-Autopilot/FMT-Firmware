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
#include "stm32h7xx_hal.h"
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
    rt_interrupt_enter();
    /* Mask interrupt, and signal processing by deferred thread. */
    HAL_NVIC_DisableIRQ(OTG_FS_IRQn);
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
            /* Re-enable IRQ using HAL. */
            HAL_NVIC_SetPriority(OTG_FS_IRQn, 1, 3);
            HAL_NVIC_EnableIRQ(OTG_FS_IRQn);
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
// void OTG_FS_IRQHandler(void)
// {
//     rt_interrupt_enter();
//     USBD_IRQHandler(0);
//     /* leave interrupt */
//     rt_interrupt_leave();
// }
#endif

void EXTI9_5_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_9) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_9);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_SET) {
            /* USB connect */
            usbd_event_connect_handler(0);
        } else {
            /* USB disconnect */
            usbd_event_disconnect_handler(0);
        }
    }
}

void HAL_PCD_MspInit(PCD_HandleTypeDef* pcdHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (pcdHandle->Instance == USB_OTG_FS) {
        /* USER CODE BEGIN USB_OTG_FS_MspInit 0 */

        /* USER CODE END USB_OTG_FS_MspInit 0 */
        LL_RCC_SetUSBClockSource(LL_RCC_USB_CLKSOURCE_PLL1Q);
        LL_PWR_EnableUSBVoltageDetector();

        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**USB_OTG_FS GPIO Configuration
        PA9     ------> USB_OTG_FS_VBUS
        PA12     ------> USB_OTG_FS_DP
        PA11     ------> USB_OTG_FS_DM
        */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_11;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG1_FS;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* USB_OTG_FS clock enable */
        __HAL_RCC_USB_OTG_FS_CLK_ENABLE();

        /* USB_OTG_FS interrupt Init */
        HAL_NVIC_SetPriority(OTG_FS_IRQn, 1, 0);
        HAL_NVIC_EnableIRQ(OTG_FS_IRQn);
        /* USER CODE BEGIN USB_OTG_FS_MspInit 1 */

        /* USER CODE END USB_OTG_FS_MspInit 1 */

        /* Configure VBUS Pin (PA9) as input with EXTI */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = 0;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        /* Configure EXTI for PA9 (EXTI line 9) */
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 2);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    }
}

void HAL_PCD_MspDeInit(PCD_HandleTypeDef* pcdHandle)
{
    if (pcdHandle->Instance == USB_OTG_FS) {
        /* USER CODE BEGIN USB_OTG_FS_MspDeInit 0 */

        /* USER CODE END USB_OTG_FS_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_USB_OTG_FS_CLK_DISABLE();

        /**USB_OTG_FS GPIO Configuration
        PA9     ------> USB_OTG_FS_VBUS
        PA12     ------> USB_OTG_FS_DP
        PA11     ------> USB_OTG_FS_DM
        */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_12 | GPIO_PIN_11);

        /* USB_OTG_FS interrupt Deinit */
        HAL_NVIC_DisableIRQ(OTG_FS_IRQn);
        /* USER CODE BEGIN USB_OTG_FS_MspDeInit 1 */

        /* USER CODE END USB_OTG_FS_MspDeInit 1 */
    }
}
