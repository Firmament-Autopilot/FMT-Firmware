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
File        : usbd_os_abs_rtos.c
Purpose     : OS Layer for the emUSB-Device. RTOS_AWARE component must be defined
              additionally to enable OS functionality since the same file is
              used in both RTOS and non-RTOS scenarios.
---------------------------END-OF-HEADER------------------------------
*/

#include "USB.h"

/*********************************************************************
*
*       Set the default value for the compile time options
*
*********************************************************************/
#if !defined (USBD_USE_PDL)
#define USBD_USE_PDL                       (0U)
#endif /* #if !defined (USBD_USE_PDL) */

#if !defined (USBD_NORTOS_TICKCNT_ENABLE)
#if defined (COMPONENT_RTOS_AWARE)
#define USBD_NORTOS_TICKCNT_ENABLE              (0U)
#else
#define USBD_NORTOS_TICKCNT_ENABLE              (1U)
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
#endif /* #if !defined USBD_NORTOS_TICKCNT_ENABLE */


/*********************************************************************
*
*       Check if the combinations of the compile time options are valid
*
*********************************************************************/
#if defined (COMPONENT_RTOS_AWARE) && (USBD_NORTOS_TICKCNT_ENABLE == 1U)
#error "USBD_NORTOS_TICKCNT_ENABLE option must be always set to 0 for non-RTOS environment"
#endif /* #if defined (COMPONENT_RTOS_AWARE) && (USBD_USE_PDL == 1U) */

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U) && (USBD_USE_PDL == 1U) && !defined (COMPONENT_RTOS_AWARE)
#error "When USBD_USE_PDL is enabled in non-RTOS environment, the custom implementation \
        of USB_OS_GetTickCnt() must be provided and USBD_NORTOS_TICKCNT_ENABLE is set to 0"
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) && (USBD_USE_PDL == 1U) */

#if !(defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84)) && (USBD_USE_PDL == 1U)
#error "USBD_USE_PDL option is applicable only for CAT1A and PSE84 device families"
#endif /* #if defined (COMPONENT_RTOS_AWARE) && (USBD_USE_PDL == 1U) */


/*********************************************************************
*
*       Include Device-specific libraries
*
*********************************************************************/
#if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84)
#include "cy_pdl.h"
#if (USBD_USE_PDL == 0U)
#include "mtb_hal.h"
#endif /* #if (USBD_USE_PDL == 0U) */
#elif defined (COMPONENT_CAT3)
#include "cybsp.h"
#include "cy_utils.h"
#else
#error "Unsupported Device Family"
#endif /* #if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84) */

#if defined (COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"
#endif /* #if defined (COMPONENT_RTOS_AWARE) */


/*********************************************************************
*
*       Global variables
*
*********************************************************************/
#define USBD_NUM_ALL_EVENTS                      (USB_NUM_EPS + USB_EXTRA_EVENTS)

static uint32_t critical_section_count;
static volatile unsigned usbd_event_transact_cnt[USBD_NUM_ALL_EVENTS];

#if defined (COMPONENT_RTOS_AWARE)

#define TRANSACT_CNT_EVENT_BITS_MASK            (0x1U)

static cy_mutex_t critical_section_mutex;
static cy_event_t usbd_event[USBD_NUM_ALL_EVENTS];

#if USB_NUM_MUTEXES > 0
static cy_mutex_t mutex_list[USB_NUM_MUTEXES];
static uint32_t mutex_num = 0U;
#endif

#else /* Non-RTOS environment */

static volatile bool usbd_event_transact_flag[USBD_NUM_ALL_EVENTS];

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
#if defined (COMPONENT_CAT3) || defined (COMPONENT_PSE84)
void usbd_timer_config(void);
void usbd_timer_config_deinit(void);
#endif /* defined (COMPONENT_CAT3) || defined (COMPONENT_PSE84) */
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */


/*********************************************************************
*
*       USB_OS_Init
*
*  Function description
*    This function initializes all OS objects that are necessary.
*/
void USB_OS_Init(void)
{
    critical_section_count = 0U;
#if defined (COMPONENT_RTOS_AWARE)
    cy_rslt_t result;

    for (uint32_t i = 0U; i < USBD_NUM_ALL_EVENTS; i++)
    {
        result = cy_rtos_event_init(&usbd_event[i]);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
    }

    result = cy_rtos_init_mutex2(&critical_section_mutex, true);
    CY_ASSERT(CY_RSLT_SUCCESS == result);

    (void)result;  /* To avoid the compiler warning in Release mode */
#else /* Non-RTOS environment */
    for (uint32_t i = 0U; i < USBD_NUM_ALL_EVENTS; i++)
    {
        usbd_event_transact_flag[i] = false;
    }
#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
    usbd_timer_config();
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*       USB_OS_DeInit
*
*  Function description
*    Frees all resources used by the OS layer.
*
*/
void USB_OS_DeInit(void)
{
#if defined (COMPONENT_RTOS_AWARE)
    cy_rslt_t result;

    for (uint32_t i = 0U; i < USBD_NUM_ALL_EVENTS; i++)
    {
        result = cy_rtos_event_deinit(&usbd_event[i]);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
    }

    result = cy_rtos_deinit_mutex(&critical_section_mutex);
    CY_ASSERT(CY_RSLT_SUCCESS == result);

    (void)result;  /* To avoid the compiler warning in Release mode */
#else /* Non-RTOS environment */
#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)

#if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84)
/* cyhal_timer_free(&timer_obj); was removed because of porting to HAL Next in
  MIDDLEWARE-15649 */
  usbd_timer_config_deinit();
#elif defined (COMPONENT_CAT3)
    /* Stops the counter for CAT3 Device */
    XMC_CCU4_SLICE_StopClearTimer(emUSB_OS_Timer_HW);
    NVIC_DisableIRQ(emUSB_OS_Timer_IRQN);
#endif /* #if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84) */
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*       USB_OS_Delay
*
*  Function description
*    Delays for a given number of ms.
*
*  Parameters
*    ms:     Number of ms.
*/
void USB_OS_Delay(int ms)
{
#if defined (COMPONENT_RTOS_AWARE)
    cy_rslt_t result = cy_rtos_delay_milliseconds((cy_time_t) ms);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */
#else /* Non-RTOS environment */
#if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84)
#if (USBD_USE_PDL == 0U)
    cy_rslt_t result = mtb_hal_system_delay_ms((uint32_t)ms);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */
#else
    Cy_SysLib_Delay((uint32_t)ms);
#endif /* #if (USBD_USE_PDL == 0U) */
#elif defined (COMPONENT_CAT3)
    XMC_Delay((uint32_t)ms);
#endif /* #if defined (COMPONENT_CAT1A) || defined (COMPONENT_PSE84) */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*       USB_OS_DecRI
*
*  Function description
*    Leave a critical region for the USB stack: Decrements interrupt disable count and
*    enable interrupts if counter reaches 0.
*
*  Additional information
*    The USB stack will perform nested calls to USB_OS_IncDI() and USB_OS_DecRI().
*    This function may be called from a task context or from within an interrupt. If called
*    from an interrupt, it need not do anything.
*
*    An alternate implementation would be to
*      * enable the USB interrupts,
*      * unlock the mutex or semaphore locked in  USB_OS_IncDI()
*    if the disable count reaches 0.
*
*    This may be more efficient, because interrupts of other peripherals can be serviced
*    while inside a critical section of the USB stack.
*/
void USB_OS_DecRI(void)
{

    /* Alternate implementation has two variants: the RTOS is not used - the function
    * only disables the interrupt and increments the critical_section_count variable;
    * the RTOS is used - additionally, the function uses Mutex to check the lock state
    * of the critical_section_count variable.
    */

    /* If called from an interrupt, it need not do anything. */
    if (0U == __get_IPSR())
    {
    /* Use mutex to allow/block critical_section_count variable incrementing
    * for other tasks
    */
#if defined (COMPONENT_RTOS_AWARE)
        cy_rslt_t result = cy_rtos_get_mutex(&critical_section_mutex, CY_RTOS_NEVER_TIMEOUT);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
#endif /* #if defined (COMPONENT_RTOS_AWARE) */

        /* Check if interrupt is already disabled */
        CY_ASSERT(0U != critical_section_count);

        /* Enable the interrupt even if the RTOS is not used. */
        critical_section_count--;
        if (0U == critical_section_count)
        {
            USBD_X_EnableInterrupt();
        }

    /* Use mutex to allow/block critical_section_count variable incrementing
    * for other tasks
    */
#if defined (COMPONENT_RTOS_AWARE)
        result = cy_rtos_set_mutex(&critical_section_mutex);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        (void)result;  /* To avoid the compiler warning in Release mode */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
    }
}

/*********************************************************************
*
*        USB_OS_IncDI
*
*  Function description
*    Enter a critical region for the USB stack: Increments interrupt disable count and
*    disables interrupts.
*
*  Additional information
*    The USB stack will perform nested calls to USB_OS_IncDI() and USB_OS_DecRI().
*    This function may be called from a task context or from within an interrupt. If called
*    from an interrupt, it need not do anything.
*
*    An alternate implementation would be to
*      * perform a lock using a mutex or semaphore and
*      * disable the USB interrupts.
*
*    This may be more efficient, because interrupts of other peripherals can be serviced
*    while inside a critical section of the USB stack.
*/
void USB_OS_IncDI(void)
{

    /* Alternate implementation has two variants: the RTOS is not used - the function
    * only disables the interrupt and increments the critical_section_count variable;
    * the RTOS is used - additionally, the function uses Mutex to check the lock state
    * of the critical_section_count variable.
    */

    /* If called from an interrupt, it need not do anything. */
    if (0U == __get_IPSR())
    {
    /* Use mutex to allow/block critical_section_count variable decrementing
    * for other tasks
    */
#if defined (COMPONENT_RTOS_AWARE)
        cy_rslt_t result = cy_rtos_get_mutex(&critical_section_mutex, CY_RTOS_NEVER_TIMEOUT);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
#endif /* #if defined (COMPONENT_RTOS_AWARE) */

        /* Disable the interrupt even if the RTOS is not used. */
        if (0U == critical_section_count)
        {
            USBD_X_DisableInterrupt();
        }
        critical_section_count++;

    /* Use mutex to allow/block critical_section_count variable decrementing
    * for other tasks
    */
#if defined (COMPONENT_RTOS_AWARE)
        result = cy_rtos_set_mutex(&critical_section_mutex);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        (void)result;  /* To avoid the compiler warning in Release mode */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
    }
}

/*********************************************************************
*
*       USB_OS_Signal
*
*  Function description
*    Wakes the task waiting for signal.
*
*  Parameters
*    EPIndex:     Endpoint index. Signaling must be independent for all endpoints.
*    TransactCnt: Transaction counter. Specifies which transaction has been finished.
*
*  Additional information
*    This routine is typically called from within an interrupt
*    service routine.
*/
void USB_OS_Signal(unsigned EPIndex, unsigned TransactCnt)
{
#if defined (COMPONENT_RTOS_AWARE)
    uint32_t bit = TRANSACT_CNT_EVENT_BITS_MASK;
    cy_rslt_t result;
    /* Update usbd_event_transact_cnt before setting of bits */
    usbd_event_transact_cnt[EPIndex] = TransactCnt;
    /* For Free-RTOS, the RTOS daemon task must have higher priority
     * than other USB task, otherwise USB_OS_Signal() won't work
     * correctly. Refer to xEventGroupSetBitsFromISR description of
     * Free-RTOS API Reference.
     */
    result = cy_rtos_event_setbits(&usbd_event[EPIndex], bit);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */

#if defined(COMPONENT_FREERTOS)
    /* Always trigger context switching even if no tasks with higher
     * priority which are preparing for execution
     */
    portYIELD_FROM_ISR(pdTRUE);
#endif /* #if defined(COMPONENT_FREERTOS) */
#else /* Non-RTOS environment */
    usbd_event_transact_cnt[EPIndex] = TransactCnt;
    usbd_event_transact_flag[EPIndex] = true;
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_Wait
*
*  Function description
*    Blocks the task until USB_OS_Signal() is called for a given transaction.
*
*  Parameters
*    EPIndex:     Endpoint index. Signaling must be independent for all endpoints.
*    TransactCnt: Transaction counter.  Specifies the transaction to wait for.
*
*  Additional information
*    The function must ignore signaling transactions other than given in TransactCnt. If
*    this transaction was signaled before this function was called, it must return immediately.
*
*    This routine is called from a task.
*/
void USB_OS_Wait(unsigned EPIndex, unsigned TransactCnt)
{
#if defined (COMPONENT_RTOS_AWARE)

    while (true)
    {
        uint32_t bits = TRANSACT_CNT_EVENT_BITS_MASK;
        cy_rslt_t result = cy_rtos_event_waitbits(&usbd_event[EPIndex], &bits,
                                                  true, false, CY_RTOS_NEVER_TIMEOUT);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        (void)result;  /* To avoid the compiler warning in Release mode */

        /* Exit from USB_OS_Wait() only if signaling transaction is
         * the same as TransactCnt, otherwise continue to wait.
         */
        if(usbd_event_transact_cnt[EPIndex] == TransactCnt)
        {
            break;
        }
    }
#else /* Non-RTOS environment */
    while (true)
    {
        if (usbd_event_transact_flag[EPIndex])
        {
            usbd_event_transact_flag[EPIndex] = false;

            /* Exit from USB_OS_Wait() only if signaling transaction is
             * the same as TransactCnt, otherwise continue to wait.
             */
            if(usbd_event_transact_cnt[EPIndex] == TransactCnt)
            {
                break;
            }
        }
    }
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_WaitTimed
*
*  Function description
*    Blocks the task until USB_OS_Signal() is called for a given transaction or a timeout
*    occurs.
*
*  Parameters
*    EPIndex:     Endpoint index. Signaling must be independent for all endpoints.
*    ms:          Timeout time given in ms.
*    TransactCnt: Transaction counter.  Specifies the transaction to wait for.
*
*  Return value
*    == 0:        Task was signaled within the given timeout.
*    == 1:        Timeout occurred.
*
*  Additional information
*    The function must ignore signaling transactions other than given in TransactCnt. If
*    this transaction was signaled before this function was called, it must return immediately.
*
*    USB_OS_WaitTimed() is called from a task. This function is used by all available timed
*    routines.
*
*    Alternatively this function may take the given timeout in units of system ticks of the
*    underlying operating system instead of milliseconds. In this case all API functions
*    that support a timeout parameter should also use system ticks for the timeout.
*/
int USB_OS_WaitTimed(unsigned EPIndex, unsigned ms, unsigned TransactCnt)
{
#if defined (COMPONENT_RTOS_AWARE)
    int status = 1;
    cy_rslt_t result;

    /* It is expected that USB_OS_WaitTimed() waits longer than given timeout
     * if cy_rtos_event_waitbits() return bits before timeout and returned
     * transaction count will be different from TransactCnt
     */
    while (true)
    {
        uint32_t bits = TRANSACT_CNT_EVENT_BITS_MASK;

        result = cy_rtos_event_waitbits(&usbd_event[EPIndex], &bits,
                                        true, false, (cy_time_t) ms);
        /* CY_RSLT_SUCCESS and CY_RTOS_TIMEOUT are possible valid statuses.
        * Other statuses are not expected and report about unexpected behavior
        */
        CY_ASSERT((CY_RSLT_SUCCESS == result) || (CY_RTOS_TIMEOUT == result));

        /* Other statuses than CY_RSLT_SUCCESS mean Timeout or Error. In
         * case of error the function must return timeout status
         */
        if (result == CY_RSLT_SUCCESS)
        {
            if(usbd_event_transact_cnt[EPIndex] == TransactCnt)
            {
                status = 0;
                break;
            }
        }
        else
        {
            /* Status already equal 1 (Timeout occurred) */
            break;
        }
    }
    return status;

#else /* Non-RTOS environment */
    U32 current_tick = USB_OS_GetTickCnt();
    U32 tick_count_to_wait = current_tick + (U32) ms;
    while (tick_count_to_wait >= current_tick)
    {
        if (usbd_event_transact_flag[EPIndex])
        {
            usbd_event_transact_flag[EPIndex] = false;

            /* Exit from USB_OS_WaitTimed() if signaling transaction is
            * the same as TransactCnt.
            */
            if (usbd_event_transact_cnt[EPIndex] == TransactCnt)
            {
                break;
            }
        }

        /* If signal transaction is not the same as TransactCnt when timeout
         * equal zero, then exit at first cycle and assign to current_tick
         * tick_count_to_wait value to return 1.
         */
        if (ms == 0U)
        {
            current_tick = tick_count_to_wait + 1U;
            break;
        }

        current_tick = USB_OS_GetTickCnt();
    }
    return ((tick_count_to_wait < current_tick) ? 1 : 0);
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_GetTickCnt
*
*  Function description
*    Returns the current system time in milliseconds or system ticks.
*
*  Return value
*    Current system time.
*/
#if defined (COMPONENT_RTOS_AWARE)
U32 USB_OS_GetTickCnt(void)
{
    cy_time_t time;
    cy_rslt_t result = cy_rtos_get_time(&time);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */
    return (U32)time;
}
#endif /* #if defined (COMPONENT_RTOS_AWARE) */

#if (USBD_NORTOS_TICKCNT_ENABLE == 1U)
#if defined (COMPONENT_CAT3)
/*********************************************************************
*
*        usbd_timer_config
*
*  Function description
*    Configure the timer to generate an interrupt every 1 ms.
*/
static void usbd_timer_config()
{
    NVIC_SetPriority(emUSB_OS_Timer_IRQN,
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), emUSB_OS_Timer_INTERRUPT_PRIORITY, 0UL));

    XMC_CCU4_SLICE_ClearEvent(emUSB_OS_Timer_HW, emUSB_OS_Timer_EVENT);

    NVIC_ClearPendingIRQ(emUSB_OS_Timer_IRQN);
    
    NVIC_EnableIRQ(emUSB_OS_Timer_IRQN);

    XMC_CCU4_SLICE_StartTimer(emUSB_OS_Timer_HW);
}

/*******************************************************************************
*        emUSB_OS_Timer_INTERRUPT_HANDLER
*
*  Function description
*    This is the interrupt handler function for the emUSB OS timer period match
*    interrupt.
*
*  Note
*    The name of the handler is declared with the emusb_os_timer personality.
*
*******************************************************************************/
void emUSB_OS_Timer_INTERRUPT_HANDLER(void)
{
    timer_tick_count++;
}
#endif /* #if defined (COMPONENT_CAT3) */
#endif /* #if (USBD_NORTOS_TICKCNT_ENABLE == 1U) */

#if USB_NUM_MUTEXES > 0

/*********************************************************************
*
*        USB_OS_MutexAlloc
*
*  Function description
*    Allocates a new mutex to be used by USB_OS_MutexLock() / USB_OS_MutexUnlock() calls.
*
*  Return value
*    >= 0:        Valid index to be used for USB_OS_MutexLock() / USB_OS_MutexUnlock().
*    <  0:        Error: No mutex available.
*/
int USB_OS_MutexAlloc(void)
{
#if defined (COMPONENT_RTOS_AWARE)
    int status;

    if (mutex_num < USB_NUM_MUTEXES)
    {
        cy_rslt_t result = cy_rtos_init_mutex2(&mutex_list[mutex_num], true);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        (void)result;  /* To avoid the compiler warning in Release mode */
        status = (int)mutex_num;
        mutex_num++;
    }
    else
    {
        status = -1;
    }
    return status;
#else /* Non-RTOS environment */
    return -1;
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_MutexFree
*
*  Function description
*    Releases all mutexes allocated by USB_OS_MutexAlloc()
*/
void USB_OS_MutexFree(void)
{
#if defined (COMPONENT_RTOS_AWARE)
    for (uint32_t i = 0U; i < USB_NUM_MUTEXES; i++)
    {
        cy_rslt_t result = cy_rtos_deinit_mutex(&mutex_list[i]);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        (void)result;  /* To avoid the compiler warning in Release mode */
    }
    mutex_num = 0U;
#else /* Non-RTOS environment */
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_MutexLock
*
*  Function description
*    This function locks a mutex object that was allocated by USB_OS_MutexAlloc().
*
*  Parameters
*    Idx:     Index of the mutex to be locked (from USB_OS_MutexAlloc()).
*/
void USB_OS_MutexLock(int Idx)
{
#if defined (COMPONENT_RTOS_AWARE)
    cy_rslt_t result = cy_rtos_get_mutex(&mutex_list[Idx], CY_RTOS_NEVER_TIMEOUT);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */
#else /* Non-RTOS environment */
    (void)Idx;
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

/*********************************************************************
*
*        USB_OS_MutexUnlock
*
*  Function description
*    This function unlocks a mutex object that was allocated by USB_OS_MutexAlloc().
*
*  Parameters
*    Idx:     Index of the mutex to be unlocked (from USB_OS_MutexAlloc()).
*/
void USB_OS_MutexUnlock(int Idx)
{
#if defined (COMPONENT_RTOS_AWARE)
    cy_rslt_t result = cy_rtos_set_mutex(&mutex_list[Idx]);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    (void)result;  /* To avoid the compiler warning in Release mode */
#else /* Non-RTOS environment */
    (void)Idx;
#endif /* #if defined (COMPONENT_RTOS_AWARE) */
}

#endif /* USB_NUM_MUTEXES > 0 */

/*************************** End of file ****************************/
