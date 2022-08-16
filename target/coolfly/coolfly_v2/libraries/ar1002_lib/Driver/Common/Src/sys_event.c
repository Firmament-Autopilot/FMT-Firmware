#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sys_event.h"
#include "debuglog.h"
#include "memory.h"
#include "cpu_info.h"
#include "drv_systick.h"
#include "memory.h"
#include "hal.h"

#include "inter_core.h"

#define TRUE (1)
#define FALSE (0)

#define IDLE_EVENT_PROCESS_INTERVAL     95

static STRU_RegisteredSysEvent_List  g_registeredSysEventList      = NULL;
static STRU_RegisteredSysEvent_Node* g_registeredSysEventList_tail = NULL;
static STRU_NotifiedSysEvent_List    g_notifiedSysEventList        = NULL;
static STRU_NotifiedSysEvent_Node*   g_notifiedSysEventList_tail   = NULL;

// static unsigned long s_ul_primask = 0;

static unsigned long msg_malloc_cnt  = 0, msg_free_cnt = 0;
static unsigned long node_malloc_cnt = 0, node_free_cnt = 0;
static unsigned long handler_malloc_cnt = 0, handler_free_cnt = 0;



/**
 * Internal functions about event node
 **/

static STRU_RegisteredSysEvent_Node* findExistedSysEventNode(STRU_RegisteredSysEvent_Node* pFirstEventNode, uint32_t event_id)  
{
    STRU_RegisteredSysEvent_Node* pNode = pFirstEventNode;  
    if(NULL == pNode)
    {
        return NULL;  
    }
    
    while(NULL != pNode)
    {  
        if(event_id == pNode->event_id)
        {
            return pNode;
        }
        
        pNode = pNode ->next;  
    }  
      
    return NULL;
}

static STRU_RegisteredSysEvent_Node* retrieveRegisteredEventNode(uint32_t event_id, uint8_t create_if_no)
{
    STRU_RegisteredSysEvent_Node** ppFirstNode = &g_registeredSysEventList;
    STRU_RegisteredSysEvent_Node** ppLastNode = &g_registeredSysEventList_tail;
    STRU_RegisteredSysEvent_Node* get_node = findExistedSysEventNode(*ppFirstNode, event_id);  

    if ((get_node == NULL) && (create_if_no == TRUE))
    {
        // Can not find the event ID in the list, then to create a new node for the event ID.
        STRU_RegisteredSysEvent_Node* pEventNode = (STRU_RegisteredSysEvent_Node*)malloc_safe(sizeof(STRU_RegisteredSysEvent_Node));

        if (pEventNode != NULL)
        {
            node_malloc_cnt ++;

            pEventNode->event_id = event_id;
            pEventNode->handler_list = NULL;
            pEventNode->handler_list_tail = NULL;
            pEventNode->prev = *ppLastNode;
            pEventNode->next = NULL;
            if (pEventNode->prev != NULL)
            {
                // Not the first node to be created
                pEventNode->prev->next = pEventNode;
            }
            else
            {
                // The first node to be created
                *ppFirstNode = pEventNode;
            }
            *ppLastNode = pEventNode;
            get_node = pEventNode;
        }
        else
        {
            DLOG_Error("Error: create new STRU_RegisteredSysEvent_Node failed.");
        }
    }

    return get_node;
}

static uint8_t removeRegisteredSysEventNode(STRU_RegisteredSysEvent_Node* pNode)  
{

    rt_base_t level;

    STRU_RegisteredSysEvent_Node** ppFirstNode = &g_registeredSysEventList;
    STRU_RegisteredSysEvent_Node** ppLastNode = &g_registeredSysEventList_tail;
 
    if((NULL == pNode) || (NULL == *ppFirstNode))
    {
        return FALSE;
    }

    level = rt_hw_interrupt_disable();
    
    if(pNode == *ppFirstNode)
    {
        // The first event node to be removed
        if(NULL == (*ppFirstNode)->next)
        {
            // The only event node to be removed
            *ppFirstNode = NULL;
            *ppLastNode = NULL;
        }else
        {
            // The first node, not the last node, to be removed.
            *ppFirstNode = pNode->next;  
            (*ppFirstNode)->prev = NULL;  
        }  
  
    }
    else
    {
        // The event node to be removed is not the first node
        if(pNode->next)
        {
            // The event node to be removed is not the last node
            pNode->next->prev = pNode->prev;
        }
        else
        {
            // The last event node to be removed
            *ppLastNode = pNode->prev;
        }
        pNode->prev->next = pNode->next;  
    }

    rt_hw_interrupt_enable(level);
  
    free_safe(pNode);
    node_free_cnt ++;
    return TRUE; 
}

/**
 * Internal functions about event handler node
 **/

static STRU_RegisteredSysEventHandler_Node* findExistedSysEventHandlerNode(const STRU_RegisteredSysEvent_Node* pEventNode, SYS_Event_Handler handler)  
{
    STRU_RegisteredSysEventHandler_Node* pNode;

    if(NULL == pEventNode)
    {
        return NULL;  
    }

    // Get the first node in the handler list of the current event node
    pNode = pEventNode->handler_list; 

    // Check whether this handler can be found
    while(NULL != pNode)
    {  
        if(handler == pNode->handler)
        {
            return pNode;
        }
        
        pNode = pNode ->next;  
    }  
      
    return NULL;
}

static uint8_t addSysEventHandlerNode(STRU_RegisteredSysEvent_Node* pEventNode, SYS_Event_Handler handler)
{
    if ((pEventNode != NULL) && (handler != NULL))
    {
        STRU_RegisteredSysEventHandler_Node** ppFirstNode = &(pEventNode->handler_list);
        STRU_RegisteredSysEventHandler_Node** ppLastNode = &(pEventNode->handler_list_tail);
        STRU_RegisteredSysEventHandler_Node* pNewNode = (STRU_RegisteredSysEventHandler_Node*)malloc_safe(sizeof(STRU_RegisteredSysEventHandler_Node));

        if (pNewNode != NULL)
        {
            // Just put in the tail of the handler list
            pNewNode->handler= handler;
            pNewNode->prev = *ppLastNode;
            pNewNode->next = NULL;
            if (pNewNode->prev != NULL)
            {
                // Not the first node to be created
                pNewNode->prev->next = pNewNode;
            }
            else
            {
                // The first node to be created
                *ppFirstNode = pNewNode;
            }
            *ppLastNode = pNewNode;

            handler_malloc_cnt ++;
            return TRUE;
        }
        else
        {
            printf("Error: create new STRU_RegisteredSysEventHandler_Node failed.");
        }
    }

    return FALSE;
}

static uint8_t removeExistedSysEventHandlerNode(STRU_RegisteredSysEvent_Node* pEventNode, SYS_Event_Handler handler)  
{
    STRU_RegisteredSysEventHandler_Node** ppFirstNode;
    STRU_RegisteredSysEventHandler_Node** ppLastNode;
    STRU_RegisteredSysEventHandler_Node* pNode;

    if (NULL == pEventNode)
    {
        return FALSE;
    }

    ppFirstNode = &(pEventNode->handler_list);
    ppLastNode = &(pEventNode->handler_list_tail);
 
    if(NULL == *ppFirstNode)
    {
        return FALSE;
    }
  
    pNode = findExistedSysEventHandlerNode(pEventNode, handler);

    if(NULL == pNode)
    {
        return FALSE;  
    }
    
    if(pNode == *ppFirstNode)
    {
        // The first node in the handler list will be removed
        if(NULL == (*ppFirstNode)->next)
        {
            // The only node to be removed
            *ppFirstNode = NULL;
            *ppLastNode = NULL;
        }else
        {
            // The fisrt node, not the last node, is removed and the header is changed
            *ppFirstNode = pNode->next;  
            (*ppFirstNode)->prev = NULL;  
        }  
  
    }
    else
    {
        // Not the first node to be removed
        if(pNode->next)
        {
            // Not the last node to be removed
            pNode->next->prev = pNode->prev;
        }
        else
        {
            // The last node to be removed
            *ppLastNode = pNode->prev;
        }
        pNode->prev->next = pNode->next;  
    }  

    handler_free_cnt ++;
    free_safe(pNode);  
    return TRUE;
}

/**
 * Internal functions about notified event node
 **/

static STRU_NotifiedSysEvent_Node* findNotifiedSysEventNodeByPriority(void)
{
    STRU_NotifiedSysEvent_Node* pNode = g_notifiedSysEventList;
    STRU_NotifiedSysEvent_Node* pFirstHighNode = NULL;
    STRU_NotifiedSysEvent_Node* pFirstMidiumNode = NULL;
    STRU_NotifiedSysEvent_Node* pFirstLowNode = NULL;
    
    if(NULL == pNode)
    {
        return NULL;  
    }

    while(NULL != pNode)
    {
        if((pNode->event_id & SYS_EVENT_LEVEL_HIGH_MASK) && (NULL == pFirstHighNode))
        {
            pFirstHighNode = pNode;
            // When the fisrt hight priority node is found, stop the list parse.
            return pFirstHighNode;
        }
        else if((pNode->event_id & SYS_EVENT_LEVEL_MIDIUM_MASK) && (NULL == pFirstMidiumNode))
        {
            pFirstMidiumNode = pNode;
        }
        else if((pNode->event_id & SYS_EVENT_LEVEL_LOW_MASK) && (NULL == pFirstLowNode))
        {
            pFirstLowNode = pNode;
        }
        else
        {
            if (((pNode->event_id & SYS_EVENT_LEVEL_HIGH_MASK) || 
                 (pNode->event_id & SYS_EVENT_LEVEL_MIDIUM_MASK) ||
                 (pNode->event_id & SYS_EVENT_LEVEL_LOW_MASK)) == 0)
            {
                DLOG_Error("The system event ID 0x%lx priority level is not right!", pNode->event_id);
            }
        }
        
        pNode = pNode ->next;  
    }

    if(NULL != pFirstMidiumNode)
    {
        // No high priority node is found, choose the first midium priority node.
        return pFirstMidiumNode;
    }

    if(NULL != pFirstLowNode)
    {
        // No high priority and midium priority node is found, choose the first low priority node.
        return pFirstLowNode;
    }
    
    return NULL;
}

static uint8_t removeNotifiedSysEventNode(STRU_NotifiedSysEvent_Node* pNode)  
{

    rt_base_t level;

    STRU_NotifiedSysEvent_Node** ppFirstNode;
    STRU_NotifiedSysEvent_Node** ppLastNode;

    ppFirstNode = &g_notifiedSysEventList;
    ppLastNode  = &g_notifiedSysEventList_tail;
 
    if(NULL == pNode)
    {
        return FALSE;  
    }
    
    // Avoid event notification in ISR functions to change the notified event list at the same time
    level = rt_hw_interrupt_disable();

    if(pNode == *ppFirstNode)
    {
        // The head node to be removed
        if(NULL == (*ppFirstNode)->next)
        {
            // The only node to be removed
            *ppFirstNode = NULL;
            *ppLastNode = NULL;
        }else
        {  
            *ppFirstNode = pNode->next;  
            (*ppFirstNode)->prev = NULL;  
        }  
  
    }
    else
    {
        // The normal node to be removed
        if(pNode->next)
        {
            // Not the last node
            pNode->next->prev = pNode->prev;
        }
        else
        {
            // The last node to be removed
            *ppLastNode = pNode->prev;
        }
        pNode->prev->next = pNode->next;  
    }

    rt_hw_interrupt_enable(level);

    free_safe(pNode);  

    msg_free_cnt ++;

    return TRUE; 
}

/**
 * External APIs --------------------------------------------------------------------
 **/

/** 
 * @brief       API for different modules to register an envent handler.  
 * @param[in]   event_id, the event ID the module wants to observe and handle.
 * @param[in]   event_handler, the event handler the module wants to use to process the observed event.
 * @retval      TURE, this means event and handler are registered sucessfully. 
 * @retval      FALSE, this means error happens in event and handler registeration
 */
uint8_t SYS_EVENT_RegisterHandler(uint32_t event_id, SYS_Event_Handler event_handler)
{
    uint8_t retval = FALSE;
    STRU_RegisteredSysEvent_Node* sysEventNode;

    event_id &= ~SYS_EVENT_INTER_CORE_MASK;

    sysEventNode = retrieveRegisteredEventNode(event_id, TRUE);

    if (sysEventNode != NULL)
    {
        // Check whether this handler has already been registered before, overlapped handlers are not permitted.
        if (findExistedSysEventHandlerNode(sysEventNode, event_handler) == NULL)
        {
            retval = addSysEventHandlerNode(sysEventNode, event_handler);           
        }
    }
    
    return retval;
}

/** 
 * @brief       API for different modules to unregister an envent handler.
 * @param[in]   event_id, the event ID the module wants to remove in the observation list.
 * @param[in]   event_handler, the event handler the module wants to remove in the handler list.
 * @retval      TURE, this means event and handler are unregistered sucessfully. 
 * @retval      FALSE, this means error happens in event and handler unregisteration
 */
uint8_t SYS_EVENT_UnRegisterHandler(uint32_t event_id, SYS_Event_Handler event_handler)
{
    uint8_t retval = FALSE;
    STRU_RegisteredSysEvent_Node* sysEventNode;   

    sysEventNode = retrieveRegisteredEventNode(event_id, FALSE);

    if (sysEventNode != NULL)
    {  
        if (removeExistedSysEventHandlerNode(sysEventNode, event_handler) == TRUE)
        {
            if (sysEventNode->handler_list == NULL)
            {
                // No hanlder in this event node, then this event node can be removed.
                retval = removeRegisteredSysEventNode(sysEventNode);
            }
            else
            {
                retval = TRUE;
            }
        }
    }
    
    return retval;
}

static uint8_t notifySysEvent(uint32_t event_id, void* parameter)
{
    uint8_t retval = FALSE;

    // Local CPU core process
    if (retrieveRegisteredEventNode((event_id & ~SYS_EVENT_INTER_CORE_MASK), FALSE) != NULL)
    {
        STRU_NotifiedSysEvent_Node** ppFirstNode = &g_notifiedSysEventList;
        STRU_NotifiedSysEvent_Node** ppLastNode  = &g_notifiedSysEventList_tail;

        STRU_NotifiedSysEvent_Node* pNewNode = (STRU_NotifiedSysEvent_Node*)malloc_safe(sizeof(STRU_NotifiedSysEvent_Node));
  
        if (pNewNode != NULL)
        {
            // Add the new node to the tail, unmask the inter core bit.
            pNewNode->event_id = (event_id & ~SYS_EVENT_INTER_CORE_MASK);
            memcpy((void*)(pNewNode->parameter), parameter, sizeof(pNewNode->parameter));
            pNewNode->prev = *ppLastNode;
            pNewNode->next = NULL;

            if (*ppLastNode == NULL)
            {
                // The first node to be created
                *ppFirstNode = pNewNode;
            }
            else
            {
                (*ppLastNode)->next = pNewNode;
            }

            *ppLastNode = pNewNode;

            retval = TRUE;
            
            msg_malloc_cnt ++;
        }
        else
        {
            DLOG_Info("Malloc Fail g_notifiedSysEventList = %p ", g_notifiedSysEventList);
            retval = FALSE;
        }
    }
    else
    {
        //not register the Event node handler, not need to notify
        retval = TRUE;
    }

    // Inter-Core event nofitication
    if (event_id & SYS_EVENT_INTER_CORE_MASK)
    {
        INTER_CORE_CPU_ID dst = 0;
        dst |= ((INTER_CORE_CPU0_ID | INTER_CORE_CPU1_ID | INTER_CORE_CPU2_ID) & (~(1 << CPUINFO_GetLocalCpuId())));
        // Inter-Core message send
        retval = InterCore_SendMsg(dst, event_id & ~SYS_EVENT_INTER_CORE_MASK, parameter, SYS_EVENT_HANDLER_PARAMETER_LENGTH);
     }

    return retval;
}


/** 
 * @brief       API for different modules to notify an envent in ISR functions.
 * @param[in]   event_id, the event ID the module wants to notify.
 * @param[in]   parameter, the parameter the module wants to transfer in this notification.
 * @retval      TURE, this means notification operation is sucessful. 
 * @retval      FALSE, this means error happens in this notification operation.
 */
void SYS_EVENT_Notify_From_ISR(uint32_t event_id, void* parameter)
{
    rt_base_t level = rt_hw_interrupt_disable();
    notifySysEvent(event_id, parameter);
    rt_hw_interrupt_enable(level);
}


/** 
 * @brief       API for different modules to notify an envent.
 * @param[in]   event_id, the event ID the module wants to notify.
 * @param[in]   parameter, the parameter the module wants to transfer in this notification.
 * @retval      TURE, this means notification operation is sucessful. 
 * @retval      FALSE, this means error happens in this notification operation.
 */
uint8_t SYS_EVENT_Notify(uint32_t event_id, void* parameter)
{
    uint8_t retval = FALSE;

    retval = notifySysEvent(event_id, parameter);
    
    return retval;
}

uint8_t SYS_EVENT_NotifyRemote(uint32_t event_id, void* parameter)
{
    uint8_t data[SYS_EVENT_HANDLER_PARAMETER_LENGTH];

    event_id |= SYS_EVENT_INTER_CORE_MASK;
    memcpy(data, (uint8_t *)(&event_id), 4);
    memcpy(&data[4], (uint8_t *)parameter, SYS_EVENT_HANDLER_PARAMETER_LENGTH - 4);

    return SYS_EVENT_Notify(SYS_EVENT_ID_REMOTE_EVENT, (void *)data);
}

uint8_t SYS_EVENT_NotifyLocal(uint32_t event_id, void* parameter)
{
    return SYS_EVENT_Notify(event_id & (~SYS_EVENT_INTER_CORE_MASK), parameter);
}

uint8_t SYS_EVENT_NotifyInterCore(uint32_t event_id, void* parameter)
{
    return SYS_EVENT_Notify(event_id | SYS_EVENT_INTER_CORE_MASK, parameter);
}


/** 
 * @brief       API for main loop to process the notified events.
 * @param[in]   none
 * @retval      TURE, this means the oldest notification with the highest priority is processed sucessfully. 
 * @retval      FALSE, this means error happens in this notification process.
 */
uint8_t SYS_EVENT_Process(void)
{
    uint8_t             retval = FALSE;
    static uint32_t     idle_event_ticks = 0;

    // Get the notification node with the highest priority in the notification list
    STRU_NotifiedSysEvent_Node* processNode = findNotifiedSysEventNodeByPriority();
    
    if (processNode != NULL)
    {
        // Get the event node with same event ID as the nitification node 
        STRU_RegisteredSysEvent_Node* event_node = retrieveRegisteredEventNode(processNode->event_id, FALSE);
        if (event_node != NULL)
        {
            STRU_RegisteredSysEventHandler_Node* handler_node = event_node->handler_list;

            // Process all the handlers in the handler list
            while (handler_node != NULL)
            {
                // Use temp handler to avoid handler node freed by the handler itself  
                SYS_Event_Handler tmp_handler = handler_node->handler;

                // Launch the handler callback
                // From this design, event handler callback can not register or unregister event handler.
                tmp_handler(processNode->parameter);

                // Continue to process the next handler of this event
                handler_node = handler_node->next;
            }
        }

        // Remove such notification node after it is processed
        retval = removeNotifiedSysEventNode(processNode);
    }

    //check IDLE event, avoid idle event starve or too often
    {
        uint32_t now  = SysTicks_GetTickCount();
        uint32_t diff = SysTicks_GetDiff(idle_event_ticks, now);

        if (diff <= IDLE_EVENT_PROCESS_INTERVAL)
        {
		    //idle event happens too often
            return FALSE;
        }
        idle_event_ticks = now;

        // Get the idle event node 
        STRU_RegisteredSysEvent_Node* event_node = retrieveRegisteredEventNode(SYS_EVENT_ID_IDLE, FALSE);
        if (event_node != NULL)
        {
            STRU_RegisteredSysEventHandler_Node* handler_node = event_node->handler_list;

            // Process all the handlers in the handler list
            while (handler_node != NULL)
            {
                // Use temp handler to avoid handler node freed by the handler itself  
                SYS_Event_Handler tmp_handler = handler_node->handler;

                // Launch the handler callback
                // From this design, event handler callback can not register or unregister event handler.
                tmp_handler((void*)NULL);

                // Continue to process the next handler of this event
                handler_node = handler_node->next;
            }
        }        
    }

    return retval;
}

/**
 * Debug APIs --------------------------------------------------------------------
 **/
void SYS_EVENT_DumpAllListNodes(void)
{
    // STRU_RegisteredSysEvent_Node* rEventNode = g_registeredSysEventList;
    // while(rEventNode != NULL)
    // {
    //     printf("Registered EventNode: event_id 0x%lx\n", rEventNode->event_id);
    //     STRU_RegisteredSysEventHandler_Node* hNode = rEventNode->handler_list;
    //     while(hNode != NULL)
    //     {
    //         printf("                      handler %p\n", hNode->handler);
    //         hNode = hNode->next;
    //     }
    //     rEventNode = rEventNode->next;
    // }

    STRU_NotifiedSysEvent_Node* nEventNode = g_notifiedSysEventList;
    while(nEventNode != NULL)
    {
        printf("Notified EventNode: event_id 0x%lx\n", nEventNode->event_id);
        nEventNode = nEventNode->next;
    }
}


void SYS_EVENT_MallocFreeCntCheck(void)
{
    printf("--------%ld %ld %ld %ld %ld %ld \r\n\n", msg_malloc_cnt, msg_free_cnt, 
                                       handler_malloc_cnt, handler_free_cnt, 
                                       node_malloc_cnt, node_free_cnt);
}