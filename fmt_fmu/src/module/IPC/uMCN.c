/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

static McnList _Mcn_list = { NULL, NULL };

McnList mcn_get_list(void)
{
    return _Mcn_list;
}

fmt_err mcn_advertise(McnHub* hub, int (*echo)(void* parameter))
{
    MCN_ASSERT(hub != NULL);

    if (hub->pdata != NULL) {
        /* already advertised */
        return FMT_ENOTHANDLE;
    }

    MCN_ENTER_CRITICAL;
    hub->pdata = MCN_MALLOC(hub->obj_size);
    hub->echo = echo;

    if (hub->pdata == NULL) {
        return FMT_ENOMEM;
    }

    memset(hub->pdata, 0, hub->obj_size);

    /* update Mcn List */
    McnList_t cp = &_Mcn_list;

    while (cp->next != NULL) {
        /* find last node */
        cp = cp->next;
    }

    if (cp->hub_t != NULL) {
        cp->next = (McnList_t)MCN_MALLOC(sizeof(McnList));

        if (cp->next == NULL)
            return FMT_ENOMEM;

        cp = cp->next;
    }

    cp->hub_t = hub;
    cp->next = NULL;

    MCN_EXIT_CRITICAL;

    return FMT_EOK;
}

McnNode_t mcn_subscribe(McnHub* hub, MCN_EVENT_HANDLE event_t, void (*cb)(void* parameter))
{
    MCN_ASSERT(hub != NULL);

    if (hub->link_num >= MCN_MAX_LINK_NUM) {
        console_printf("mcn link num is already full!\n");
        return NULL;
    }

    McnNode_t node = (McnNode_t)MCN_MALLOC(sizeof(McnNode));

    if (node == NULL) {
        console_printf("mcn create node fail!\n");
        return NULL;
    }

    node->renewal = 0;
    node->event_t = event_t;
    node->cb = cb;
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

    if (hub->published && node->cb) {
        /* if data published before subscribe, then call callback immediately */
        node->cb(hub->pdata);
    }

    return node;
}

fmt_err mcn_unsubscribe(McnHub* hub, McnNode_t node)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(node != NULL);

    /* traverse each node */
    McnNode_t cur_node = hub->link_head;
    McnNode_t pre_node = cur_node;

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

    /* free current node */
    MCN_FREE(cur_node);
    // cur_node = NULL;
    hub->link_num--;
    MCN_EXIT_CRITICAL;

    return FMT_EOK;
}

fmt_err mcn_publish(McnHub* hub, const void* data)
{
    MCN_ASSERT(hub != NULL);
    MCN_ASSERT(data != NULL);

    if (hub->pdata == NULL) {
        // hub is not advertised yet
        return FMT_ERROR;
    }

    // calculate publish frequency
    uint32_t time_now = systime_now_ms();
    hub->freq = 1000.0f / (float)(time_now - hub->last_pub_time);
    hub->last_pub_time = time_now;

    MCN_ENTER_CRITICAL;
    /* copy data to hub */
    memcpy(hub->pdata, data, hub->obj_size);
    /* traverse each node */
    McnNode_t node = hub->link_head;

    while (node != NULL) {
        /* update each node's renewal flag */
        node->renewal = 1;

        /* send out event to wakeup waiting task */
        if (node->event_t) {
            /* stimulate as mutex */
            if (node->event_t->value == 0)
                MCN_SEND_EVENT(node->event_t);
        }

        node = node->next;
    }

    hub->published = 1;
    MCN_EXIT_CRITICAL;

    /* invoke callback func */
    node = hub->link_head;

    while (node != NULL) {
        if (node->cb != NULL) {
            node->cb(hub->pdata);
        }

        node = node->next;
    }

    return FMT_EOK;
}

bool mcn_poll(McnNode_t node_t)
{
    bool renewal;

    MCN_ASSERT(node_t != NULL);

    MCN_ENTER_CRITICAL;
    renewal = node_t->renewal;
    MCN_EXIT_CRITICAL;

    return renewal;
}

bool mcn_poll_sync(McnNode_t node_t, int32_t timeout)
{
    MCN_ASSERT(node_t != NULL);
    MCN_ASSERT(node_t->event_t != NULL);

    return MCN_WAIT_EVENT(node_t->event_t, timeout) == 0 ? 1 : 0;
}

fmt_err mcn_copy(McnHub* hub, McnNode_t node_t, void* buffer)
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

fmt_err mcn_copy_from_hub(McnHub* hub, void* buffer)
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