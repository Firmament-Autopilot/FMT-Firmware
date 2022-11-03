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
#include <string.h>

static McnList __mcn_list = { .hub = NULL, .next = NULL };
static struct rt_timer timer_mcn_freq_est;

/**
 * @brief Topic publish frequency estimator entry
 * 
 * @param parameter Unused
 */
static void mcn_freq_est_entry(void* parameter)
{
    for (McnList_t cp = &__mcn_list; cp != NULL; cp = cp->next) {
        McnHub_t hub = cp->hub;
        if (hub == NULL) {
            break;
        }

        /* calculate publish frequency */
        uint32_t cnt = 0;
        for (int i = 0; i < MCN_FREQ_EST_WINDOW_LEN; i++) {
            cnt += hub->freq_est_window[i];
            hub->freq = (float)cnt / MCN_FREQ_EST_WINDOW_LEN;
        }
        /* move window */
        hub->window_index = (hub->window_index + 1) % MCN_FREQ_EST_WINDOW_LEN;
        hub->freq_est_window[hub->window_index] = 0;
    }
}

/**
 * @brief Clear uMCN node renewal flag
 * 
 * @param node_t uMCN node
 */
void mcn_node_clear(McnNode_t node_t)
{
    MCN_ASSERT(node_t != NULL);

    if (node_t == NULL) {
        return;
    }

    MCN_ENTER_CRITICAL;
    node_t->renewal = 0;
    MCN_EXIT_CRITICAL;
}

/**
 * @brief Suspend a uMCN topic
 * 
 * @param hub uMCN hub
 */
void mcn_suspend(McnHub_t hub)
{
    hub->suspend = 1;
}

/**
 * @brief Resume a uMCN topic
 * 
 * @param hub uMCN hub
 */
void mcn_resume(McnHub_t hub)
{
    hub->suspend = 0;
}

/**
 * @brief Get uMCN list
 * 
 * @return McnList_t uMCN list pointer
 */
McnList_t mcn_get_list(void)
{
    return &__mcn_list;
}

/**
 * @brief Iterate all uMCN hubs in list
 * 
 * @param ite uMCN list pointer
 * @return McnHub_t uMCN hub
 */
McnHub_t mcn_iterate(McnList_t* ite)
{
    McnHub_t hub;
    McnList_t node = *ite;

    if (node == NULL) {
        return NULL;
    }
    hub = node->hub;
    *ite = node->next;

    return hub;
}

/**
 * @brief Poll for topic status
 * @note This function would return immediately
 * 
 * @param node_t uMCN node
 * @return true Topic updated
 * @return false Topic not updated
 */
bool mcn_poll(McnNode_t node_t)
{
    bool renewal;

    MCN_ASSERT(node_t != NULL);

    MCN_ENTER_CRITICAL;
    renewal = node_t->renewal;
    MCN_EXIT_CRITICAL;

    return renewal;
}

/**
 * @brief Wait for topic update
 * @note event must has been provided when subscribe the topic
 * 
 * @param node_t uMCN node
 * @param timeout Wait timeout
 * @return true Topic updated
 * @return false Topic not updated
 */
bool mcn_wait(McnNode_t node_t, int32_t timeout)
{
    MCN_ASSERT(node_t != NULL);
    MCN_ASSERT(node_t->event != NULL);

    return MCN_WAIT_EVENT(node_t->event, timeout) == 0 ? true : false;
}

/**
 * @brief Copy uMCN topic data from hub
 * @note This function will clear the renewal flag
 * 
 * @param hub uMCN hub
 * @param node_t uMCN node
 * @param buffer buffer to received the data
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t mcn_copy(McnHub_t hub, McnNode_t node_t, void* buffer)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(node_t != NULL);
    MCN_ASSERT(buffer != NULL);

    if (hub->pdata == NULL) {
        /* copy from non-advertised hub */
        return FMT_ERROR;
    }

    if (!hub->published) {
        /* copy before published */
        return FMT_ENOTHANDLE;
    }

    MCN_ENTER_CRITICAL;
    memcpy(buffer, hub->pdata, hub->obj_size);
    node_t->renewal = 0;
    MCN_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * @brief Copy uMCN topic data from hub
 * @note This function will directly copy topic data from hub no matter it has been 
 * updated or not and won't clear the renewal flag
 * 
 * @param hub 
 * @param buffer 
 * @return fmt_err_t 
 */
fmt_err_t mcn_copy_from_hub(McnHub_t hub, void* buffer)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(buffer != NULL);

    if (hub->pdata == NULL) {
        /* copy from non-advertised hub */
        return FMT_ERROR;
    }

    if (!hub->published) {
        /* copy before published */
        return FMT_ENOTHANDLE;
    }

    MCN_ENTER_CRITICAL;
    memcpy(buffer, hub->pdata, hub->obj_size);
    MCN_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * @brief Advertise a uMCN topic
 * 
 * @param hub uMCN hub
 * @param echo Echo function to print topic contents
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t mcn_advertise(McnHub_t hub, int (*echo)(void* parameter))
{
    void* pdata;
    void* next;

    MCN_ASSERT(hub != NULL);

    if (hub->pdata != NULL) {
        /* already advertised */
        return FMT_ENOTHANDLE;
    }

    pdata = MCN_MALLOC(hub->obj_size);
    if (pdata == NULL) {
        return FMT_ENOMEM;
    }
    memset(pdata, 0, hub->obj_size);

    next = MCN_MALLOC(sizeof(McnList));
    if (next == NULL) {
        MCN_FREE(pdata);
        return FMT_ENOMEM;
    }

    MCN_ENTER_CRITICAL;
    hub->pdata = pdata;
    hub->echo = echo;

    /* update Mcn List */
    McnList_t cp = &__mcn_list;

    while (cp->next != NULL) {
        /* find last node */
        cp = cp->next;
    }

    if (cp->hub != NULL) {
        cp->next = (McnList_t)next;
        cp = cp->next;
    }

    cp->hub = hub;
    cp->next = NULL;

    /* init publish freq estimator window */
    memset(hub->freq_est_window, 0, 2 * MCN_FREQ_EST_WINDOW_LEN);
    hub->window_index = 0;

    MCN_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * @brief Subscribe a uMCN topic
 * 
 * @param hub uMCN hub
 * @param event Event handler to provide synchronize poll
 * @param pub_cb Topic published callback function
 * @return McnNode_t Subscribe node, return NULL if fail
 */
McnNode_t mcn_subscribe(McnHub_t hub, MCN_EVENT_HANDLE event, void (*pub_cb)(void* parameter))
{
    MCN_ASSERT(hub != NULL);

    if (hub->link_num >= MCN_MAX_LINK_NUM) {
        printf("mcn link num is already full!\n");
        return NULL;
    }

    McnNode_t node = (McnNode_t)MCN_MALLOC(sizeof(McnNode));

    if (node == NULL) {
        printf("mcn create node fail!\n");
        return NULL;
    }

    node->renewal = 0;
    node->event = event;
    node->pub_cb = pub_cb;
    node->next = NULL;

    MCN_ENTER_CRITICAL;

    /* no node link yet */
    if (hub->link_tail == NULL) {
        hub->link_head = hub->link_tail = node;
    } else {
        hub->link_tail->next = node;
        hub->link_tail = node;
    }

    hub->link_num++;
    MCN_EXIT_CRITICAL;

    if (hub->published) {
        /* update renewal flag as it's already published */
        node->renewal = 1;

        if (node->pub_cb) {
            /* if data published before subscribe, then call callback immediately */
            node->pub_cb(hub->pdata);
        }
    }

    return node;
}

/**
 * @brief Unsubscribe a uMCN topic
 * 
 * @param hub uMCN hub
 * @param node Subscribe node
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t mcn_unsubscribe(McnHub_t hub, McnNode_t node)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(node != NULL);

    /* traverse each node */
    McnNode_t cur_node = hub->link_head;
    McnNode_t pre_node = NULL;

    while (cur_node != NULL) {
        if (cur_node == node) {
            /* find node */
            break;
        }

        pre_node = cur_node;
        cur_node = cur_node->next;
    }

    if (cur_node == NULL) {
        /* can not find */
        return FMT_EEMPTY;
    }

    /* update list */
    MCN_ENTER_CRITICAL;

    if (hub->link_num == 1) {
        hub->link_head = hub->link_tail = NULL;
    } else {
        if (cur_node == hub->link_head) {
            hub->link_head = cur_node->next;
        } else if (cur_node == hub->link_tail) {
            if (pre_node) {
                pre_node->next = NULL;
            }
            hub->link_tail = pre_node;
        } else {
            pre_node->next = cur_node->next;
        }
    }

    hub->link_num--;
    MCN_EXIT_CRITICAL;

    /* free current node */
    MCN_FREE(cur_node);
    // cur_node = NULL;

    return FMT_EOK;
}

/**
 * @brief Publish uMCN topic
 * 
 * @param hub uMCN hub, which can be obtained by MCN_HUB() macro
 * @param data Data of topic to publish
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t mcn_publish(McnHub_t hub, const void* data)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(data != NULL);

    if (hub->pdata == NULL) {
        /* hub is not advertised yet */
        return FMT_ERROR;
    }

    if (hub->suspend) {
        return FMT_ENOTHANDLE;
    }

    /* update freq estimator window */
    hub->freq_est_window[hub->window_index]++;

    MCN_ENTER_CRITICAL;
    /* copy data to hub */
    memcpy(hub->pdata, data, hub->obj_size);
    /* traverse each node */
    McnNode_t node = hub->link_head;

    while (node != NULL) {
        /* update each node's renewal flag */
        node->renewal = 1;

        /* send out event to wakeup waiting task */
        if (node->event) {
            /* stimulate as mutex */
            if (node->event->value == 0)
                MCN_SEND_EVENT(node->event);
        }

        node = node->next;
    }

    hub->published = 1;
    MCN_EXIT_CRITICAL;

    /* invoke callback func */
    node = hub->link_head;

    while (node != NULL) {
        if (node->pub_cb != NULL) {
            node->pub_cb(hub->pdata);
        }

        node = node->next;
    }

    return FMT_EOK;
}

/**
 * @brief Initialize uMCN module
 * 
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t mcn_init(void)
{
    rt_timer_init(&timer_mcn_freq_est, "mcn_freq_est", mcn_freq_est_entry, NULL, 1000, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);

    if (rt_timer_start(&timer_mcn_freq_est) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}