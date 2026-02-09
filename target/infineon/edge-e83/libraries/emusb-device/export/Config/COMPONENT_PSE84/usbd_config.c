/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2003 - 2025     SEGGER Microcontroller GmbH              *
*                                                                    *
*       www.segger.com     Support: www.segger.com/ticket            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device * USB Device stack for embedded applications    *
*                                                                    *
*       Please note: Knowledge of this file may under no             *
*       circumstances be used to write a similar product.            *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device version: V3.66.5                                *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
All Intellectual Property rights in the software belongs to SEGGER.
emUSB Device is protected by international copyright laws. This file
may only be used in accordance with the following terms:

The source code of the emUSB Device software has been licensed to Cypress
Semiconductor Corporation, whose registered office is 198 Champion
Court, San Jose, CA 95134, USA including the 
right to create and distribute the object code version of 
the emUSB Device software for its Cortex M0, M0+, M4, M33 and M55 based devices.
The object code version can be used by Cypress customers under the 
terms and conditions of the associated End User License Agreement.
Support for the object code version is provided by Cypress, 
full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              Cypress Semiconductor Corp, 198 Champion Ct., San Jose, CA 95134, USA
Licensed SEGGER software: emUSB-Device
License number:           USBD-00500
License model:            Cypress Services and License Agreement, signed November 17th/18th, 2010
                          and Amendment Number One, signed December 28th, 2020 and February 10th, 2021
                          and Amendment Number Three, signed May 2nd, 2022 and May 5th, 2022 and Amendment Number Four, signed August 28th, 2023
Licensed platform:        Cypress devices containing ARM Cortex M cores: M0, M0+, M4, M33 and M55
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2022-05-12 - 2026-05-19
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
File        : usbd_config.c
Purpose     : emUSB-Device configuration file for PSE84 device
--------  END-OF-HEADER  ---------------------------------------------
*/

#include "USB.h"
#include "USB_HW_Infineon_PSOCE84.h"
#include "cy_pdl.h"
#include "cybsp.h"

/* Define interrupt priority */
#define USBD_ISR_PRIO                           (3U)

/* Use driver with DMA support. Can be defined in Makefile */
#if !defined (USBD_ENABLE_DMA)
#define USBD_ENABLE_DMA                         (false)
#endif /* #if !defined (USBD_ENABLE_DMA) */

#if !defined (USBD_NORTOS_TICKCNT_ENABLE)
#if defined (COMPONENT_RTOS_AWARE)
#define USBD_NORTOS_TICKCNT_ENABLE              (0U)
#else
#define USBD_NORTOS_TICKCNT_ENABLE              (1U)
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
#endif /* #if !defined USBD_NORTOS_TICKCNT_ENABLE */

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
#include "mtb_hal_timer.h"
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */

#if defined(emUSB_OS_Timer_HW) && defined(COMPONENT_RTOS_AWARE)
#warning "The 1 ms timer in the emUSB personality should not be selected when using RTOS environment."
#endif

/* Define the size of memory dedicated for driver in bytes.
 * The memory is used for the endpoints buffers and transfer
 * descriptors. Update this value with the optimal memory pool
 * size (strongly recommended) for the application. For details
 * on selecting the optimal memory pool size, refer to the
 * USBD_AssignMemory() description in emUSB-Device User Guide &
 * Reference Manual.
 */
#define EP_BUFFER_SIZE                          (4096U)

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
#define TIMER_IRQ_PRIORITY  (7U)

static mtb_hal_timer_t timer_obj;
static volatile uint32_t timer_tick_count; /* The value in milliseconds */

void usbd_timer_config(void);
void usbd_timer_config_deinit(void);
void isr_timer(void* arg, mtb_hal_timer_event_t event);
void timer_irq(void);
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/* Memory pool for driver with DMA support */
#if defined (COMPONENT_CM55)
/* For CM55, the default linker scripts do not locate the USB memory pool
 * to the area with DMA access. So, specify manually the memory area with
 * DMA access for the USB memory pool. */
CY_SECTION(".cy_socmem_data") static uint32_t memory_pool[EP_BUFFER_SIZE / 4U];
#else /* COMPONENT_CM33 */
static uint32_t memory_pool[EP_BUFFER_SIZE / 4U];
#endif /* #if defined (COMPONENT_CM55) */

#if (USBD_ENABLE_DMA == true)
/* These macros define the lower and upper limits of SRAM regions for
 * the verification that memory assigned for the DMA driver is allocated
 * in the region with DMA access. These macros are device-specific.
 * Update them for a specific device.
 */
#define DMA_VALID_ADDR_START                    (0x24000000U)
#define DMA_VALID_ADDR_END                      (0x40000000U)


/*********************************************************************
*
*       check_valid_dma_address
*  Function description
*    Checks if the memory location can be used for DMA transfers.
*
*/
static int check_valid_dma_address(const void * mem_addr)
{
    int status = 1;
    if (((uint32_t)mem_addr >= DMA_VALID_ADDR_START) && ((uint32_t)mem_addr < DMA_VALID_ADDR_END))
    {
        status = 0;
    }
    return status;
}

/*********************************************************************
*
*       clean_dcache
*
*  Function description
*    Flush all dirty cache lines to memory, that cover memory range 'ptr' to 'ptr + num_bytes - 1'.
*    (num_bytes may need to be rounded up to a multiple of the cache line size).
*/
static void clean_dcache(void * ptr, unsigned long num_bytes)
{
#if defined (COMPONENT_CM55)
    SCB_CleanDCache_by_Addr(ptr, num_bytes);
#else
    /* Do nothing */
    (void) ptr;
    (void) num_bytes;
#endif /* #if defined (COMPONENT_CM55) */
}

/*********************************************************************
*
*       invalidate_dcache
*
*  Function description
*    Invalidate all cache lines  (discard contents) that cover memory range 'ptr' to 'ptr + num_bytes - 1'.
*    (num_bytes may need to be rounded up to a multiple of the cache line size).
*/
static void invalidate_dcache(void * ptr, unsigned long num_bytes)
{
#if defined (COMPONENT_CM55)
    SCB_InvalidateDCache_by_Addr(ptr, num_bytes);
#else
    /* Do nothing */
    (void) ptr;
    (void) num_bytes;
#endif /* #if defined (COMPONENT_CM55) */
}

static const SEGGER_CACHE_CONFIG cache_config =
{
    /* CacheLineSize of CPU */
    32,
    /* Data Memory Barrier is not present */
    NULL,
    clean_dcache,
    invalidate_dcache
};

#endif /* #if (USBD_ENABLE_DMA == true) */

/*********************************************************************
*
*       enable_isr
*  Function description
*    Configure and enable interrupts.
*/
static void enable_isr(USB_ISR_HANDLER * pfISRHandler)
{
    cy_stc_sysint_t usb_int_cfg =
    {
        .intrSrc = usbhs_interrupt_usbhsctrl_IRQn,
        .intrPriority = USBD_ISR_PRIO
    };

    cy_en_sysint_status_t status;

    /* Install the interrupt service routine */
    status = Cy_SysInt_Init(&usb_int_cfg, pfISRHandler);
    CY_ASSERT(CY_RSLT_SUCCESS == status);
    (void) status; /* To avoid the compiler warning in Release mode */

    NVIC_EnableIRQ(usbhs_interrupt_usbhsctrl_IRQn);
}

/*********************************************************************
*
*       USBD_X_Config
*
*  Function description
*    Configure the USB stack. This function is always called from
*    USBD_Init().
*
*/
void USBD_X_Config(void)
{
#if (USBD_ENABLE_DMA == true)
    USBD_AddDriver(&USB_Driver_Infineon_PSOCE84_DMA);
    USBD_SetCacheConfig(&cache_config, sizeof(cache_config));
    USBD_SetCheckAddress(check_valid_dma_address);
#else
    USBD_AddDriver(&USB_Driver_Infineon_PSOCE84);
#endif /* #if (USBD_ENABLE_DMA == true) */
    USBD_AssignMemory(memory_pool, sizeof(memory_pool));
    /* Configure interrupt */
    USBD_SetISREnableFunc(enable_isr);
}

/*********************************************************************
*
*       USBD_X_EnableInterrupt
*
*  Function description
*    This function is called by the stack to enable USB interrupt(s)
*    after they have been disabled by USBD_X_DisableInterrupt().
*
*/
void USBD_X_EnableInterrupt(void)
{
    NVIC_EnableIRQ(usbhs_interrupt_usbhsctrl_IRQn);
}

/*********************************************************************
*
*       USBD_X_DisableInterrupt
*
*  Function description
*    This function is called by the stack in cases where the stack
*    must perform a critical operation which can not be interrupted
*    by a new incoming USB interrupt event.
*
*/
void USBD_X_DisableInterrupt(void)
{
    NVIC_DisableIRQ(usbhs_interrupt_usbhsctrl_IRQn);
}

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
/*********************************************************************
*
*        usbd_timer_config
*
*  Function description
*    Configure the timer to generate an interrupt every 1 ms.
*    Called in usbd_os_abs_rtos.c file.
*/

void usbd_timer_config()
{
    cy_rslt_t rslt = CY_RSLT_SUCCESS;
    cy_en_tcpwm_status_t res;

    /* Use the device-configurator output for the alias "timer" */
    res = Cy_TCPWM_Counter_Init(emUSB_OS_Timer_HW, emUSB_OS_Timer_NUM, &emUSB_OS_Timer_config);
    if (res == CY_TCPWM_SUCCESS)
    {
        rslt = mtb_hal_timer_setup(&timer_obj, &emUSB_OS_Timer_hal_config, NULL);
        if (rslt == CY_RSLT_SUCCESS)
        {
            Cy_TCPWM_Counter_Enable(emUSB_OS_Timer_HW, emUSB_OS_Timer_NUM);
        }

        /* Enable System IRQ */
        if (rslt == CY_RSLT_SUCCESS)
        {
            uint32_t saved_intr_status = mtb_hal_system_critical_section_enter();

            /* Enable IRQ */
            cy_stc_sysint_t intr_cfg;
            intr_cfg.intrSrc = (IRQn_Type)emUSB_OS_Timer_IRQ;
            intr_cfg.intrPriority = TIMER_IRQ_PRIORITY;

            /* Register system callback */
            Cy_SysInt_Init(&intr_cfg, timer_irq);
            NVIC_EnableIRQ((IRQn_Type)emUSB_OS_Timer_IRQ);

            mtb_hal_system_critical_section_exit(saved_intr_status);
        }

        /* Register the Callback and enable the events */
        if (CY_RSLT_SUCCESS == rslt)
        {
            /* Assign the ISR to execute on timer interrupt */
            mtb_hal_timer_register_callback(&timer_obj, isr_timer, NULL);

            /* Set the event on which timer interrupt occurs and enable it */
            mtb_hal_timer_enable_event(&timer_obj, MTB_HAL_TIMER_EVENT_TERMINAL_COUNT, true);
        }

        /* Start the timer */
        if (rslt == CY_RSLT_SUCCESS)
        {
            rslt = mtb_hal_timer_start(&timer_obj);
        }

        CY_ASSERT(rslt == CY_RSLT_SUCCESS);
    }
}

/*********************************************************************
*
*        usbd_timer_config_deinit
*
*  Function description
*    Deinitialization the timer.
*    Called in usbd_os_abs_rtos.c file.
*/
void usbd_timer_config_deinit(void)
{
    cy_rslt_t rslt = mtb_hal_timer_stop(&timer_obj);
    CY_ASSERT(rslt == CY_RSLT_SUCCESS);

    if (CY_RSLT_SUCCESS == rslt)
    {
        rslt = mtb_hal_timer_reset(&timer_obj, 0);
        CY_ASSERT(rslt == CY_RSLT_SUCCESS);

        memset((void*)&timer_obj, 0, sizeof(mtb_hal_timer_t));

        Cy_TCPWM_Counter_Disable(emUSB_OS_Timer_HW, emUSB_OS_Timer_NUM);
        Cy_TCPWM_Counter_DeInit(emUSB_OS_Timer_HW, emUSB_OS_Timer_NUM, &emUSB_OS_Timer_config);

        NVIC_DisableIRQ((IRQn_Type)emUSB_OS_Timer_IRQ);
        timer_tick_count = 0;
    }
}

/*********************************************************************
*
*        isr_timer
*
*  Function description
*     Callback function for HAL driver. Increments value every ms.
*/
void isr_timer(void* arg, mtb_hal_timer_event_t event)
{
    (void)arg;
    (void)event;

    timer_tick_count++;
}

/*********************************************************************
*
*        timer_irq
*
*  Function description
*    System Timer interrupt.
*/
void timer_irq(void)
{
    mtb_hal_timer_process_interrupt(&timer_obj);
}

/*********************************************************************
*
*        USB_OS_GetTickCnt
*
*  Function description
*    Get ms from the start of timer which increments in interrupt each ms.
*/
U32 USB_OS_GetTickCnt(void)
{
    return (U32) timer_tick_count;;
}
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */
