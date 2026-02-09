/***************************************************************************//**
* \file cy_ipc_sema.c
* \version 1.140
*
*  Description:
*   IPC Semaphore Driver - This source file contains the source code for the
*   semaphore level APIs for the IPC interface.
*
********************************************************************************
* Copyright 2016-2025 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"

#if defined (CY_IP_M4CPUSS) || defined (CY_IP_M7CPUSS) || defined (CY_IP_MXIPC)

#include "cy_ipc_drv.h"
#include "cy_ipc_sema.h"
#include "cy_syslib.h"
#include <string.h> /* The memset() definition */

/* Defines a mask to Check if semaphore count is a multiple of 32 */
#define CY_IPC_SEMA_PER_WORD_MASK    (CY_IPC_SEMA_PER_WORD - 1UL)

/* Pointer to IPC channel structure used for semaphores. */
static IPC_STRUCT_Type* cy_semaIpcStruct;
#if defined(CY_PDL_TZ_ENABLED)
/* In the secure world, we can't safely indirect through a pointer read from an
 * IPC channel. So we store an entire copy of the semaphore data struct, and
 * only use the IPC channel struct pointer for lock/release/notify operations */
#if (CY_IPC_DRV_CACHE_PRESENT)
static cy_stc_ipc_sema_t       cy_semaStruct CY_ALIGN(__SCB_DCACHE_LINE_SIZE);
#else
static cy_stc_ipc_sema_t       cy_semaStruct;
#endif
#endif


/*******************************************************************************
* Function Name: Cy_IPC_Sema_Init
****************************************************************************//**
*
* This function initializes the semaphores subsystem. The user must create an
* array of unsigned 32-bit words to hold the semaphore bits. The number
* of semaphores will be the size of the array * 32. The total semaphores count
* will always be a multiple of 32.
*
* Either this function or \ref Cy_IPC_Sema_InitExt must be called from each core
* that will use IPC semaphores.
*
* \note In a multi-CPU system this init function should be called with all
* initialized parameters on one CPU only to provide a pointer to SRAM that can
* be shared between all the CPUs in the system that will use semaphores.
* On other CPUs user must specify the IPC semaphores channel and pass 0 / NULL
* to count and memPtr parameters correspondingly.
*
* If semaphores will be used from within a secure processing environment, the secure
* processing environment must call either this function or \ref Cy_IPC_Sema_InitExt
* with non-0 / NULL arguments, and it must do so before launching any other processing
* environment.
*
* On cores that support DCache, user needs to make sure that the memPtr pointer passed
* to the Cy_IPC_Sema_Init function points to 32 byte aligned array of words that contain
* the semaphore data. User can use CY_ALIGN(32) macro for 32 byte alignment.
*
* If semaphores will be used from within a secure processing environment, the
* secure processing environment must \ref Cy_IPC_Sema_InitExt with non-0 / NULL arguments.
* This must be done even if this function or \ref Cy_IPC_Sema_InitExt was previously
* called from another (non-secure) processing environment.
*
* \param ipcChannel
* The IPC channel number used for semaphores
*
* \param count
*  The maximum number of semaphores to be supported (multiple of 32).
*
* \param memPtr
*  This points to the array of (count/32) words that contain the semaphore data. This must be located
*  in memory which is accessible to all processing environments which will interact with semaphores
*
* \return Status of the operation
*    \retval CY_IPC_SEMA_SUCCESS: Successfully initialized
*    \retval CY_IPC_SEMA_BAD_PARAM:     Memory pointer is NULL and count is not zero,
*                             or count not multiple of 32
*    \retval CY_IPC_SEMA_ERROR_LOCKED:  Could not acquire semaphores IPC channel
*
* \funcusage
* \snippet ipc/snippet/main.c snippet_Cy_IPC_Sema_Init
*
*******************************************************************************/
cy_en_ipcsema_status_t Cy_IPC_Sema_Init(uint32_t ipcChannel,
                                        uint32_t count, uint32_t memPtr[])
{
    /* Structure containing semaphores control data */
    CY_SECTION_SHAREDMEM
#if (CY_IPC_DRV_CACHE_PRESENT)
    static cy_stc_ipc_sema_t       cy_semaData CY_ALIGN(__SCB_DCACHE_LINE_SIZE);
#else
    static cy_stc_ipc_sema_t       cy_semaData;
#endif
    cy_en_ipcsema_status_t retStatus = CY_IPC_SEMA_BAD_PARAM;

    /* Secure device cannot trust a pointer from the NS world. It must always use its own */
    #if !defined(CY_PDL_TZ_ENABLED)
    if( (NULL == memPtr) && (0u == count))
    {
        cy_semaIpcStruct = Cy_IPC_Drv_GetIpcBaseAddress(ipcChannel);

        retStatus = CY_IPC_SEMA_SUCCESS;
    }
    else
    #endif
    /* Check for non Null pointers and count value */
    if ((NULL != memPtr) && (0u != count))
    {
        cy_semaData.maxSema  = count;
        cy_semaData.arrayPtr = memPtr;

        retStatus = Cy_IPC_Sema_InitExt(ipcChannel, &cy_semaData);
    }
    else
    {
        retStatus = CY_IPC_SEMA_BAD_PARAM;
    }

    return(retStatus);
}


/*******************************************************************************
* Function Name: Cy_IPC_Sema_InitExt
****************************************************************************//**
* This function initializes the semaphores subsystem. The user must create an
* array of unsigned 32-bit words to hold the semaphore bits. The number
* of semaphores will be the size of the array * 32. The total semaphores count
* will always be a multiple of 32.
*
* Either this function or \ref Cy_IPC_Sema_Init must be called from each core
* that will use IPC semaphores.
*
* \note In a multi-CPU system this init function should be called with all
* initialized parameters on one CPU only to provide a pointer to SRAM that can
* be shared between all the CPUs in the system that will use semaphores.
* On other CPUs user must specify the IPC semaphores channel and pass 0 / NULL
* to count and memPtr parameters correspondingly.
*
* If semaphores will be used from within a secure processing environment, the
* secure processing environment must this function with non-0 / NULL arguments.
* This must be done even if this function or \ref Cy_IPC_Sema_Init was previously
* called from another (non-secure) processing environment.
*
* \param ipcChannel
* The IPC channel number used for semaphores
*
* \param ipcSema
*  This is configuration structure of the IPC semaphore. This struct must be located in memory
*  which is accessible to all processing environments which will interact with semaphores.
*  See \ref cy_stc_ipc_sema_t.
*
* \return Status of the operation
*    \retval CY_IPC_SEMA_SUCCESS: Successfully initialized
*    \retval CY_IPC_SEMA_BAD_PARAM:     Memory pointer is NULL and count is not zero,
*                             or count not multiple of 32
*    \retval CY_IPC_SEMA_ERROR_LOCKED:  Could not acquire semaphores IPC channel
*
*******************************************************************************/
cy_en_ipcsema_status_t Cy_IPC_Sema_InitExt(uint32_t ipcChannel, cy_stc_ipc_sema_t *ipcSema)
{
    cy_en_ipcsema_status_t retStatus = CY_IPC_SEMA_BAD_PARAM;
    if (ipcChannel >= CY_IPC_CHANNELS)
    {
        retStatus = CY_IPC_SEMA_BAD_PARAM;
    }
    else
    {
        if(NULL != ipcSema)
        {
#if (CY_IPC_DRV_CACHE_PRESENT)
            SCB_CleanDCache_by_Addr((uint32_t*)&ipcSema->maxSema, (int32_t)sizeof(ipcSema->maxSema));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */
            /* Check if semaphore count is a multiple of 32 */
            if( 0UL == (ipcSema->maxSema & CY_IPC_SEMA_PER_WORD_MASK))
            {
                cy_semaIpcStruct = Cy_IPC_Drv_GetIpcBaseAddress(ipcChannel);

                /* Initialize all semaphores to released */
                for (uint32_t index=0; index<(uint32_t)(ipcSema->maxSema / CY_IPC_SEMA_PER_WORD); index++)
                {
                    ipcSema->arrayPtr[index] = 0UL;
                }

#if (CY_IPC_DRV_CACHE_PRESENT)
                SCB_CleanDCache_by_Addr((uint32_t*)ipcSema->arrayPtr, (int32_t)sizeof(*ipcSema->arrayPtr));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

                /* Make sure semaphores start out released.  */
                /* Ignore the return value since it is OK if it was already released. */
                (void) Cy_IPC_Drv_LockRelease (cy_semaIpcStruct, CY_IPC_NO_NOTIFICATION);

                 /* Set the IPC Data with the pointer to the array. */
                if( CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_SendMsgPtr (cy_semaIpcStruct, CY_IPC_NO_NOTIFICATION, ipcSema))
                {
                    if(CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockRelease (cy_semaIpcStruct, CY_IPC_NO_NOTIFICATION))
                    {
                        retStatus = CY_IPC_SEMA_SUCCESS;
                    }
                    else
                    {
                        /* IPC channel not released, still semaphored */
                        retStatus = CY_IPC_SEMA_ERROR_LOCKED;
                    }
                }
                else
                {
                    /* Could not acquire semaphore channel */
                    retStatus = CY_IPC_SEMA_ERROR_LOCKED;
                }
            }
            else
            {
                retStatus = CY_IPC_SEMA_BAD_PARAM;
            }
        }
        else
        {
            retStatus = CY_IPC_SEMA_BAD_PARAM;
        }
    }

    #if defined(CY_PDL_TZ_ENABLED)
    /* Cache the trustworthy values for usage in subsequent function calls. */
    if (CY_IPC_SEMA_SUCCESS == retStatus)
    {
        memcpy(&cy_semaStruct, ipcSema, sizeof(cy_semaStruct));
    }
    else
    {
        memset(&cy_semaStruct, 0u, sizeof(cy_semaStruct));
    }
    #endif

    return(retStatus);
}

/** \cond INTERNAL
  * Internal helper: gets the raw number and array pointer to use for a given semaphore
  */
static inline cy_en_ipcsema_status_t _Cy_IPC_Sema_GetChannelAndStruct(uint32_t userSemaNum, uint32_t *rawSemaNum, cy_stc_ipc_sema_t** semaStruct)
{
    /* check cy_semaIpcStruct != NULL */
    if (cy_semaIpcStruct == NULL)
    {
        return CY_IPC_SEMA_NOT_ACQUIRED;
    }

    if (NULL != rawSemaNum)
    {
        /* Get pointer to structure */
        #if defined(CY_IPC_SECURE_SEMA_DEVICE)
            *rawSemaNum = CY_IPC_SEMA_GET_NUM(userSemaNum);
        #else
            *rawSemaNum = userSemaNum;
        #endif
    }

    #if defined(CY_PDL_TZ_ENABLED) /* We need to use the trustworthy pointers we cached locally */
        *semaStruct = &cy_semaStruct;
    #else
        *semaStruct = (cy_stc_ipc_sema_t *)(GET_NSALIAS_ADDRESS(Cy_IPC_Drv_ReadDataValue(cy_semaIpcStruct)));
    #endif

    if (NULL == *semaStruct)
    {
        return CY_IPC_SEMA_NOT_ACQUIRED;
    }

    return CY_IPC_SEMA_SUCCESS;
}
/** \endcond */


/*******************************************************************************
* Function Name: Cy_IPC_Sema_Set
****************************************************************************//**
*
* This function tries to acquire a semaphore. If the
* semaphore is not available, this function returns immediately with
* CY_IPC_SEMA_LOCKED.
*
* It first acquires the IPC channel that is used for all the semaphores, sets
* the semaphore if it is cleared, then releases the IPC channel used for the
* semaphore.
*
* \param semaNumber
*  The semaphore number to acquire.
* \note There are two shared memories. One is a secure memory area which is accessible from
*  secure domains only. Another memory area which is accessible from both secure and non-secure
*  domains. To use secure area for semaphore, user has to use \ref CY_IPC_SEMA_SEC macro to create
*  a secure semaphore.
*
* \param preemptable
*  When this parameter is enabled the function can be preempted by another
*  task or other forms of context switching in an RTOS environment.
*
* \note
*  If <b>preemptable</b> is enabled (true), the user must ensure that there are
*  no deadlocks in the system, which can be caused by an interrupt that occurs
*  after the IPC channel is locked. Unless the user is ready to handle IPC
*  channel locks correctly at the application level, set <b>preemptable</b> to
*  false.
*
* \return Status of the operation
*    \retval CY_IPC_SEMA_SUCCESS:      The semaphore was set successfully
*    \retval CY_IPC_SEMA_LOCKED:       The semaphore channel is busy or locked
*                              by another process
*    \retval CY_IPC_SEMA_NOT_ACQUIRED: Semaphore was already set
*    \retval CY_IPC_SEMA_OUT_OF_RANGE: The semaphore number is not valid
*
* \funcusage
* \snippet ipc/snippet/main.c snippet_Cy_IPC_Sema_Set
*
*******************************************************************************/
cy_en_ipcsema_status_t Cy_IPC_Sema_Set(uint32_t semaNumber, bool preemptable)
{
    uint32_t semaIndex;
    uint32_t semaMask;
    uint32_t interruptState = 0UL;

    cy_stc_ipc_sema_t *semaStruct = NULL;
    uint32_t *ptrArray;
    uint32_t semaNum = 0u;

    cy_en_ipcsema_status_t retStatus = _Cy_IPC_Sema_GetChannelAndStruct(semaNumber, &semaNum, &semaStruct);
    if (CY_IPC_SEMA_SUCCESS != retStatus)
    {
        return retStatus;
    }

    retStatus = CY_IPC_SEMA_LOCKED; /* Assume locked until we determine otherwise */

#if (CY_IPC_DRV_CACHE_PRESENT)
    SCB_InvalidateDCache_by_Addr((uint32_t*)&semaStruct->maxSema, (int32_t)sizeof(semaStruct->maxSema));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

    if (semaNum < semaStruct->maxSema)
    {
        semaIndex = semaNum / CY_IPC_SEMA_PER_WORD;
        semaMask = (uint32_t)(1UL << (semaNum - (semaIndex * CY_IPC_SEMA_PER_WORD) ));
    #if defined(CY_IPC_SECURE_SEMA_DEVICE)
        ptrArray = CY_IPC_SEMA_IS_SEC(semaNumber) ? semaStruct->arrayPtr_sec : (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #elif defined(__SAUREGION_PRESENT) && (__SAUREGION_PRESENT==1)
        ptrArray = (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #else
        ptrArray = semaStruct->arrayPtr;
    #endif
        if (NULL == ptrArray)
        {
            return CY_IPC_SEMA_BAD_PARAM;
        }
        if (!preemptable)
        {
            interruptState = Cy_SysLib_EnterCriticalSection();
        }

        /* Check to make sure the IPC channel is released
           If so, check if specific channel can be locked. */
        if(CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire (cy_semaIpcStruct))
        {
#if (CY_IPC_DRV_CACHE_PRESENT)
            SCB_InvalidateDCache_by_Addr((uint32_t*)ptrArray, (int32_t)sizeof(*ptrArray));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

            if((ptrArray[semaIndex] & semaMask) == 0UL)
            {
                ptrArray[semaIndex] |= semaMask;
#if (CY_IPC_DRV_CACHE_PRESENT)
                SCB_CleanDCache_by_Addr((uint32_t*)ptrArray, (int32_t)sizeof(*ptrArray));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */
                retStatus = CY_IPC_SEMA_SUCCESS;
            }
            else
            {
                retStatus = CY_IPC_SEMA_NOT_ACQUIRED;
            }

            /* Release, but do not trigger a release event */
            (void) Cy_IPC_Drv_LockRelease (cy_semaIpcStruct, CY_IPC_NO_NOTIFICATION);
        }

        if (!preemptable)
        {
            Cy_SysLib_ExitCriticalSection(interruptState);
        }
    }
    else
    {
        retStatus = CY_IPC_SEMA_OUT_OF_RANGE;
    }

    return(retStatus);
}


/*******************************************************************************
* Function Name: Cy_IPC_Sema_Clear
****************************************************************************//**
*
* This functions tries to releases a semaphore.
*
* It first acquires the IPC channel that is used for all the semaphores, clears
* the semaphore if it is set, then releases the IPC channel used for the
* semaphores.
*
* \param semaNumber
*  The index of the semaphore to release.
* \note There are two shared memories. One is a secure memory area which is accessible from
*  secure domains only. Another memory area which is accessible from both secure and non-secure
*  domains. To use secure area for semaphore, user has to use \ref CY_IPC_SEMA_SEC macro to create
*  a secure semaphore.
*
* \param preemptable
*  When this parameter is enabled the function can be preempted by another
*  task or other forms of context switching in an RTOS environment.
*
* \note
*  If <b>preemptable</b> is enabled (true), the user must ensure that there are
*  no deadlocks in the system, which can be caused by an interrupt that occurs
*  after the IPC channel is locked. Unless the user is ready to handle IPC
*  channel locks correctly at the application level, set <b>preemptable</b> to
*  false.
*
* \return Status of the operation
*    \retval CY_IPC_SEMA_SUCCESS:         The semaphore was cleared successfully
*    \retval CY_IPC_SEMA_NOT_ACQUIRED:    The semaphore was already cleared
*    \retval CY_IPC_SEMA_LOCKED:          The semaphore channel was semaphored or busy
*    \retval CY_IPC_SEMA_OUT_OF_RANGE:    The semaphore number is not valid
*
* \funcusage
* \snippet ipc/snippet/main.c snippet_Cy_IPC_Sema_Clear
*
*******************************************************************************/
cy_en_ipcsema_status_t Cy_IPC_Sema_Clear(uint32_t semaNumber, bool preemptable)
{
    uint32_t semaIndex;
    uint32_t semaMask;
    uint32_t interruptState = 0UL;

    cy_stc_ipc_sema_t *semaStruct = NULL;
    uint32_t *ptrArray;
    uint32_t semaNum = 0u;

    cy_en_ipcsema_status_t retStatus = _Cy_IPC_Sema_GetChannelAndStruct(semaNumber, &semaNum, &semaStruct);
    if (CY_IPC_SEMA_SUCCESS != retStatus)
    {
        return retStatus;
    }

    retStatus = CY_IPC_SEMA_LOCKED; /* Assume locked until we determine otherwise */

#if (CY_IPC_DRV_CACHE_PRESENT)
    SCB_InvalidateDCache_by_Addr((uint32_t*)&semaStruct->maxSema, (int32_t)sizeof(semaStruct->maxSema));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

    if (semaNum < semaStruct->maxSema)
    {
        semaIndex = semaNum / CY_IPC_SEMA_PER_WORD;
        semaMask = (uint32_t)(1UL << (semaNum - (semaIndex * CY_IPC_SEMA_PER_WORD) ));

    #if defined(CY_IPC_SECURE_SEMA_DEVICE)
        ptrArray = CY_IPC_SEMA_IS_SEC(semaNumber) ? semaStruct->arrayPtr_sec : (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #elif defined(__SAUREGION_PRESENT) && (__SAUREGION_PRESENT==1)
        ptrArray = (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #else
        ptrArray = semaStruct->arrayPtr;
    #endif

        if (NULL == ptrArray)
        {
            return CY_IPC_SEMA_BAD_PARAM;
        }
        if (!preemptable)
        {
            interruptState = Cy_SysLib_EnterCriticalSection();
        }

        /* Check to make sure the IPC channel is released
           If so, check if specific channel can be locked. */
        if(CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire (cy_semaIpcStruct))
        {
#if (CY_IPC_DRV_CACHE_PRESENT)
            SCB_InvalidateDCache_by_Addr((uint32_t*)ptrArray, (int32_t)sizeof(*ptrArray));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */
            if((ptrArray[semaIndex] & semaMask) != 0UL)
            {
                ptrArray[semaIndex] &= ~semaMask;
#if (CY_IPC_DRV_CACHE_PRESENT)
                SCB_CleanDCache_by_Addr((uint32_t*)ptrArray, (int32_t)sizeof(*ptrArray));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */
                retStatus = CY_IPC_SEMA_SUCCESS;
            }
            else
            {
                retStatus = CY_IPC_SEMA_NOT_ACQUIRED;
            }

            /* Release, but do not trigger a release event */
            (void) Cy_IPC_Drv_LockRelease (cy_semaIpcStruct, CY_IPC_NO_NOTIFICATION);
        }

        if (!preemptable)
        {
            Cy_SysLib_ExitCriticalSection(interruptState);
        }
    }
    else
    {
        retStatus = CY_IPC_SEMA_OUT_OF_RANGE;
    }
    return(retStatus);
}


/*******************************************************************************
* Function Name: Cy_IPC_Sema_Status
****************************************************************************//**
*
* This function returns the status of the semaphore.
*
* \param semaNumber
*  The index of the semaphore to return status.
* \note There are two shared memories. One is a secure memory area which is accessible from
*  secure domains only. Another memory area which is accessible from both secure and non-secure
*  domains. To use secure area for semaphore, user has to use \ref CY_IPC_SEMA_SEC macro to create
*  a secure semaphore.
*
* \return Status of the operation
*     \retval CY_IPC_SEMA_STATUS_LOCKED:    The semaphore is in the set state.
*     \retval CY_IPC_SEMA_STATUS_UNLOCKED:  The semaphore is in the cleared state.
*     \retval CY_IPC_SEMA_OUT_OF_RANGE:     The semaphore number is not valid
*
* \funcusage
* \snippet ipc/snippet/main.c snippet_Cy_IPC_Sema_Status
*
*******************************************************************************/
cy_en_ipcsema_status_t Cy_IPC_Sema_Status(uint32_t semaNumber)
{
    uint32_t semaIndex;
    uint32_t semaMask;
    cy_stc_ipc_sema_t *semaStruct = NULL;
    uint32_t *ptrArray;
    uint32_t semaNum = 0u;

    cy_en_ipcsema_status_t retStatus = _Cy_IPC_Sema_GetChannelAndStruct(semaNumber, &semaNum, &semaStruct);
    if (CY_IPC_SEMA_SUCCESS != retStatus)
    {
        return retStatus;
    }

    retStatus = CY_IPC_SEMA_LOCKED; /* Assume locked until we determine otherwise */

#if (CY_IPC_DRV_CACHE_PRESENT)
    SCB_InvalidateDCache_by_Addr((uint32_t*)&semaStruct->maxSema, (int32_t)sizeof(semaStruct->maxSema));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

    if (semaNum < semaStruct->maxSema)
    {
        /* Get the index into the semaphore array and calculate the mask */
        semaIndex = semaNum / CY_IPC_SEMA_PER_WORD;
        semaMask = (uint32_t)(1UL << (semaNum - (semaIndex * CY_IPC_SEMA_PER_WORD) ));
    #if defined(CY_IPC_SECURE_SEMA_DEVICE)
        ptrArray = CY_IPC_SEMA_IS_SEC(semaNumber) ? semaStruct->arrayPtr_sec : (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #elif defined(__SAUREGION_PRESENT) && (__SAUREGION_PRESENT==1)
        ptrArray = (uint32_t*)GET_NSALIAS_ADDRESS(semaStruct->arrayPtr);
    #else
        ptrArray = semaStruct->arrayPtr;
    #endif
        if (NULL == ptrArray)
        {
            return CY_IPC_SEMA_BAD_PARAM;
        }

#if (CY_IPC_DRV_CACHE_PRESENT)
        SCB_InvalidateDCache_by_Addr((uint32_t*)ptrArray, (int32_t)sizeof(*ptrArray));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */

        if((ptrArray[semaIndex] & semaMask) != 0UL)
        {
            retStatus =  CY_IPC_SEMA_STATUS_LOCKED;
        }
        else
        {
            retStatus =  CY_IPC_SEMA_STATUS_UNLOCKED;
        }
    }
    else
    {
        retStatus = CY_IPC_SEMA_OUT_OF_RANGE;
    }
    return(retStatus);
}


/*******************************************************************************
* Function Name: Cy_IPC_Sema_GetMaxSems
****************************************************************************//**
*
* This function returns the number of semaphores in the semaphores subsystem.
*
* \return
*     Returns the semaphores quantity.
*
* \funcusage
* \snippet ipc/snippet/main.c snippet_Cy_IPC_Sema_GetMaxSems
*
*******************************************************************************/
uint32_t Cy_IPC_Sema_GetMaxSems(void)
{
    cy_stc_ipc_sema_t      *semaStruct = NULL;
    cy_en_ipcsema_status_t  retStatus  = _Cy_IPC_Sema_GetChannelAndStruct(0u, NULL, &semaStruct);
    if (CY_IPC_SEMA_SUCCESS != retStatus)
    {
        CY_ASSERT(false);
        return 0u;
    }

#if (CY_IPC_DRV_CACHE_PRESENT)
    SCB_InvalidateDCache_by_Addr((uint32_t*)&semaStruct->maxSema, (int32_t)sizeof(semaStruct->maxSema));
#endif /* (CY_IPC_DRV_CACHE_PRESENT) */
    return (semaStruct->maxSema);
}

#endif

/* [] END OF FILE */
