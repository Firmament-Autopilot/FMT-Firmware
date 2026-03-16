/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#include "driver/usb/mtp/usbd_mtp.h"
#include "driver/usb/mtp/usbd_mtp_support.h"
#include "driver/usb/mtp/usbd_mtp_device_info.h"
#include "usb_osal.h"
#include "driver/usb/mtp/usbd_mtp_file.h"
#include "driver/usb/mtp/usbd_mtp_object.h"

#include <time.h>
#if defined(KERNEL_RTTHREAD)
#include <rtthread.h>
#include <rthw.h>
#include <rtthread.h>
#include <rtservice.h>
#include <rtdevice.h>
#endif
/* Max USB packet size */
#ifndef CONFIG_USB_HS
#define MTP_BULK_EP_MPS 64
#else
#define MTP_BULK_EP_MPS 512
#endif
#define DATA_BUFFER_SIZE CONFIG_USBDEV_MTP_MAX_BUFSIZE
#define MAX_WITTE_FILE_SIZE CONFIG_USBDEV_MTP_MAX_BUFSIZE
#define MTP_OUT_EP_IDX 0
#define MTP_IN_EP_IDX  1
#define MTP_INT_EP_IDX 2

#define MTP_THREAD_EVENT_SEND 0x100
#define MTP_EVENT_Q_SIZE 8

/* MTP Stage */
enum Stage {
    MTP_READ_COMMAND = 0,
    MTP_DATA_OUT = 1,
    MTP_DATA_IN = 2,
    MTP_SEND_RESPONSE = 3,
    MTP_WAIT_RESPONSE = 4,
};

/* Compatibility structure wrappers for unified mtp_header */
struct mtp_container_command {
    uint32_t conlen;
    uint16_t contype;
    uint16_t code;
    uint32_t trans_id;
    uint32_t param1;
    uint32_t param2;
    uint32_t param3;
    uint32_t param4;
    uint32_t param5;
};

struct mtp_container_data {
    uint32_t conlen;
    uint16_t contype;
    uint16_t code;
    uint32_t trans_id;
    uint8_t data[CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE];
};

struct mtp_container_response {
    uint32_t conlen;
    uint16_t contype;
    uint16_t code;
    uint32_t trans_id;
    uint32_t param1;
    uint32_t param2;
    uint32_t param3;
    uint32_t param4;
    uint32_t param5;
};

/* Macro wrappers for backward compatibility
    Use pointer-style macros to avoid accidental expansion inside
    expressions like "g_usbd_mtp.con_command" which the preprocessor
    would replace. Code should use the following macros as pointers,
    e.g. USBD_MTP_CON_COMMAND->param1, (uint8_t *)USBD_MTP_CON_DATA, etc.
*/
#define USBD_MTP_CON_COMMAND  ((struct mtp_container_command *)&g_usbd_mtp.header)
#define USBD_MTP_CON_RESPONSE ((struct mtp_container_response *)&g_usbd_mtp.header)
#define USBD_MTP_CON_DATA     ((struct mtp_container_data *)&g_usbd_mtp.header)

USB_NOCACHE_RAM_SECTION struct usbd_mtp_priv {
    USB_MEM_ALIGNX struct mtp_header header;
    USB_MEM_ALIGNX uint8_t payload[CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE];
    enum Stage stage;
    uint8_t session_state;
    uint32_t response_code;
    /*-----priv-----*/
    char path[CONFIG_USBDEV_MTP_MAX_PATHNAME];
    mtp_object_manager_t obj_manager; // object manager
    USB_MEM_ALIGNX uint8_t usbd_mtp_data_in[CONFIG_USBDEV_MTP_MAX_BUFSIZE];
    USB_MEM_ALIGNX uint8_t usbd_mtp_data_out[CONFIG_USBDEV_MTP_MAX_BUFSIZE];
    uint32_t usbd_mtp_rcnt;
    uint32_t usbd_mtp_wcnt;
    struct mtp_file mtp_file_in; // file data
    struct mtp_file mtp_file_out;
#if defined(CONFIG_USBDEV_MTP_THREAD)
    usb_osal_mq_t usbd_mtp_mq;
    usb_osal_thread_t usbd_mtp_thread;
    uint32_t nbytes;
#endif
    uint8_t busid;
    /* async event queue */
    struct {
        uint16_t code;
        uint32_t p1;
        uint32_t p2;
        uint32_t p3;
    } event_q[MTP_EVENT_Q_SIZE];
    uint8_t ev_q_head;
    uint8_t ev_q_tail;
    usb_osal_mutex_t ev_mutex;
    uint8_t int_busy; /* INT transfer in progress */
    USB_MEM_ALIGNX uint8_t event_buf[MTP_CONTAINER_HEADER_SIZE + 12]; /* 3 params */
} g_usbd_mtp;


/* Describe EndPoints configuration */
static struct usbd_endpoint mtp_ep_data[3];

static int mtp_class_interface_request_handler(uint8_t busid, struct usb_setup_packet *setup, uint8_t **data, uint32_t *len)
{
    USB_LOG_DBG("MTP Class request: "
                "bRequest 0x%02x\r\n",
                setup->bRequest);

    switch (setup->bRequest) {
        case MTP_REQUEST_CANCEL:
            break;
        case MTP_REQUEST_GET_EXT_EVENT_DATA:
            break;
        case MTP_REQUEST_RESET:
            break;
        case MTP_REQUEST_GET_DEVICE_STATUS:
            *(uint16_t *)(*data) = 0x08; //len
            *(uint16_t *)(*data + 2) = MTP_RESPONSE_OK; // resepone
            *len = 8;
            break;

        default:
            USB_LOG_WRN("Unhandled MTP Class bRequest 0x%02x\r\n", setup->bRequest);
            return -1;
    }

    return 0;
}


/* Rebuild full path from handle */
static inline int usbd_mtp_rebuild_path(uint32_t handle, char *full_path, size_t max_len)
{
    return mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, handle, full_path, max_len);
}


/* Delete object by handle. If it's a directory, all children will be deleted too. */
static int usbd_mtp_unlink_object_by_handle(uint32_t handle)
{
    if (handle == 0) {
        return -1;
    }

    return mtp_free_handle_recursive(&g_usbd_mtp.obj_manager, handle,
                                     usbd_mtp_unlink, usbd_mtp_rmdir_recursive); //usbd_mtp_rmdir
}

static void usbd_mtp_send_response_param(uint32_t code, uint32_t param1,
                                    uint32_t param2, uint32_t param3,
                                    uint32_t param4, uint32_t param5)
{
    USB_LOG_DBG("Send response\r\n");
    USB_LOG_DBG("Response params: code=0x%08lx p1=0x%08lx p2=0x%08lx p3=0x%08lx\r\n",
                code, param1, param2, param3);
    g_usbd_mtp.stage = MTP_WAIT_RESPONSE;

    USBD_MTP_CON_RESPONSE->conlen = 32;
    USBD_MTP_CON_RESPONSE->contype = MTP_CONTAINER_TYPE_RESPONSE;
    USBD_MTP_CON_RESPONSE->code = code;
    USBD_MTP_CON_RESPONSE->trans_id = USBD_MTP_CON_COMMAND->trans_id;
    USBD_MTP_CON_RESPONSE->param1 = (uint32_t)param1;
    USBD_MTP_CON_RESPONSE->param2 = (uint32_t)param2;
    USBD_MTP_CON_RESPONSE->param3 = (uint32_t)param3;
    USBD_MTP_CON_RESPONSE->param4 = (uint32_t)param4;
    USBD_MTP_CON_RESPONSE->param5 = (uint32_t)param5;

    usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_IN_EP_IDX].ep_addr, (uint8_t *)USBD_MTP_CON_RESPONSE, 32);

    USB_LOG_DBG("Started IN write of response, len=32\r\n");
}

static void usbd_mtp_send_response(uint32_t code)
{
    USB_LOG_DBG("Send response\r\n");

    g_usbd_mtp.stage = MTP_WAIT_RESPONSE;

    USBD_MTP_CON_RESPONSE->conlen = MTP_CONTAINER_HEADER_SIZE;
    USBD_MTP_CON_RESPONSE->contype = MTP_CONTAINER_TYPE_RESPONSE;
    USBD_MTP_CON_RESPONSE->code = code;
    USBD_MTP_CON_RESPONSE->trans_id = USBD_MTP_CON_COMMAND->trans_id;

    usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_IN_EP_IDX].ep_addr,
                        (uint8_t *)USBD_MTP_CON_RESPONSE,
                        MTP_CONTAINER_HEADER_SIZE);
}

static void usbd_mtp_send_info(uint8_t *data, uint32_t len)
{
    USB_LOG_DBG("Send info\r\n");

    g_usbd_mtp.stage = MTP_SEND_RESPONSE;

    USBD_MTP_CON_DATA->conlen = MTP_CONTAINER_HEADER_SIZE + len;
    USBD_MTP_CON_DATA->contype = MTP_CONTAINER_TYPE_DATA;
    USBD_MTP_CON_DATA->code = MTP_RESPONSE_OK;
    USBD_MTP_CON_DATA->trans_id = USBD_MTP_CON_COMMAND->trans_id;

    memcpy(USBD_MTP_CON_DATA->data, data, len);
    usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_IN_EP_IDX].ep_addr,
                        (uint8_t *)USBD_MTP_CON_DATA,
                        MTP_CONTAINER_HEADER_SIZE + len);
}

/* Dequeue and start sending next event. Caller MUST hold ev_mutex. */
static void usbd_mtp_event_send_queued_locked(void)
{
    if (!g_usbd_mtp.int_busy && g_usbd_mtp.ev_q_head != g_usbd_mtp.ev_q_tail) {
        uint8_t *p = g_usbd_mtp.event_buf;
        uint16_t code = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].code;
        uint32_t p1 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p1;
        uint32_t p2 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p2;
        uint32_t p3 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p3;
        g_usbd_mtp.ev_q_tail = (uint8_t)((g_usbd_mtp.ev_q_tail + 1) % MTP_EVENT_Q_SIZE);

        PUT_U32_AT(p, (uint32_t)(MTP_CONTAINER_HEADER_SIZE + 12));  // container length
        PUT_U16_AT(p, MTP_CONTAINER_TYPE_EVENT);                    // container type
        PUT_U16_AT(p, code);                                       // event code
        PUT_U32_AT(p, 0U);                                          // transaction ID = 0 for events
        PUT_U32_AT(p, p1);                                         // parameter 1
        PUT_U32_AT(p, p2);                                         // parameter 2
        PUT_U32_AT(p, p3);                                         // parameter 3

        g_usbd_mtp.int_busy = 1;
        usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_INT_EP_IDX].ep_addr, g_usbd_mtp.event_buf, MTP_CONTAINER_HEADER_SIZE + 12);
    }
}

/* Enqueue an event (thread-safe). If a worker thread exists it will be notified,
   otherwise attempt to send immediately while holding the mutex. */
static void usbd_mtp_event_enqueue(uint16_t code, uint32_t p1, uint32_t p2, uint32_t p3)
{
    if (g_usbd_mtp.ev_mutex) {
        usb_osal_mutex_take(g_usbd_mtp.ev_mutex);
        g_usbd_mtp.event_q[g_usbd_mtp.ev_q_head].code = code;
        g_usbd_mtp.event_q[g_usbd_mtp.ev_q_head].p1 = p1;
        g_usbd_mtp.event_q[g_usbd_mtp.ev_q_head].p2 = p2;
        g_usbd_mtp.event_q[g_usbd_mtp.ev_q_head].p3 = p3;
        g_usbd_mtp.ev_q_head = (uint8_t)((g_usbd_mtp.ev_q_head + 1) % MTP_EVENT_Q_SIZE);

        if (g_usbd_mtp.usbd_mtp_mq) {
            /* notify worker to process queued events */
            usb_osal_mq_send(g_usbd_mtp.usbd_mtp_mq, (uintptr_t)MTP_THREAD_EVENT_SEND);
        } else {
            /* no worker: try to send right away while holding mutex */
            usbd_mtp_event_send_queued_locked();
        }
        usb_osal_mutex_give(g_usbd_mtp.ev_mutex);
    }
}


static void usbd_mtp_get_device_info(void)
{
    /*
     * Optimized DeviceInfo payload builder for minimal RAM usage.
     * Writes directly into USBD_MTP_CON_DATA->data to avoid large
     * temporary buffer allocation on stack.
     */
    uint8_t *p = USBD_MTP_CON_DATA->data;
    uint32_t i, j, cnt;

    /* StandardVersion (uint16) */
    PUT_U16_AT(p, MTP_STANDARD_VERSION);

    /* VendorExtensionID (uint32) */
    PUT_U32_AT(p, 0x06);

    /* VendorExtensionVersion (uint16) */
    PUT_U16_AT(p, 100);

    /* VendorExtensionDesc: mtp_string format (uint8 len, then uint16 chars) */
    i = (uint16_t)(sizeof(VendExtDesc) / sizeof(uint16_t));
    PUT_U8_AT(p, i);
    for (j = 0; j < i; j++) {
        PUT_U16_AT(p, VendExtDesc[j]);
    }

    /* FunctionalMode (uint16) */
    PUT_U16_AT(p, 0x0000);

    /* OperationsSupported: write uint32 length then uint16 elements */
    i = (uint32_t)(sizeof(supported_op) / sizeof(uint16_t));
    PUT_U32_AT(p, i);
    for (j = 0; j < i; j++) {
        PUT_U16_AT(p, supported_op[j]);
    }

    /* EventsSupported */
    i = (uint32_t)(sizeof(supported_event) / sizeof(uint16_t));
    PUT_U32_AT(p, i);
    for (j = 0; j < i; j++) {
        PUT_U16_AT(p, supported_event[j]);
    }

    /* DevicePropertiesSupported: iterate until prop_code == 0xFFFF */
    cnt = 0;
    for (j = 0; j < 255; j++) {
        if (support_device_properties[j].prop_code == 0xFFFFU)
            break;
        cnt++;
    }
    PUT_U32_AT(p, cnt);
    for (j = 0; j < cnt; j++) {
        PUT_U16_AT(p, support_device_properties[j].prop_code);
    }

    /* CaptureFormats: iterate until format_code == 0xFFFF */
    cnt = 0;
    for (j = 0; j < 255; j++) {
        if (support_format_properties[j].format_code == 0xFFFFU)
            break;
        cnt++;
    }
    PUT_U32_AT(p, cnt);
    for (j = 0; j < cnt; j++) {
        PUT_U16_AT(p, support_format_properties[j].format_code);
    }

    /* PlaybackFormats: fixed length defined by config */
    cnt = 0;
    for (j = 0; j < 255; j++) {
        if (support_format_properties[j].format_code == 0xFFFFU)
            break;
        cnt++;
    }
    PUT_U32_AT(p, cnt);
    for (j = 0; j < cnt; j++) {
        PUT_U16_AT(p, support_format_properties[j].format_code);
    }

    /* Manufacturer (mtp_string) */
    PUT_STRING_AT(p, Manuf, sizeof(Manuf)/sizeof(uint16_t));
    /* Model */
    PUT_STRING_AT(p, Model, sizeof(Model)/sizeof(uint16_t));
    /* DeviceVersion */
    PUT_STRING_AT(p, DeviceVers, sizeof(DeviceVers)/sizeof(uint16_t));
    /* SerialNumber */
    PUT_STRING_AT(p, SerialNbr, sizeof(SerialNbr)/sizeof(uint16_t));

    /* Send info with calculated payload length */
    usbd_mtp_send_info(USBD_MTP_CON_DATA->data, (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

static void usbd_mtp_open_session(void)
{
    g_usbd_mtp.session_state = 1;
    usbd_mtp_send_response(MTP_RESPONSE_OK);
}

static void usbd_mtp_get_storage_ids(void)
{
    /* FIXME: Build storage ID list */
    uint8_t *p = USBD_MTP_CON_DATA->data;

    PUT_U32_AT(p, MTP_STORAGE_IDS);
    PUT_U32_AT(p, MTP_STORAGE_ID);

    usbd_mtp_send_info(USBD_MTP_CON_DATA->data, (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

static void usbd_mtp_get_storage_info(void)
{
    uint8_t *p = USBD_MTP_CON_DATA->data;
    const char *storage_desc = "SD Card";
    const char *volume_identifier = "SD Card1";

    struct mtp_statfs stfs;

    if (usbd_mtp_statfs(usbd_mtp_fs_root_path(), &stfs))
        USB_LOG_ERR("Failed to get storage info \r\n");

    PUT_U16_AT(p, MTP_STORAGE_REMOVABLE_RAM);
    PUT_U16_AT(p, MTP_STORAGE_FILESYSTEM_FLAT);
    PUT_U16_AT(p, MTP_STORAGE_READ_WRITE);
    PUT_U64_AT(p, (uint64_t)stfs.f_blocks * (uint64_t)stfs.f_bsize);
    PUT_U64_AT(p, (uint64_t)stfs.f_bfree * (uint64_t)stfs.f_bsize);
    PUT_U32_AT(p, 0xFFFFFFFFU);
    /* StorageDescription - MTP string format (uint8 len, then uint16 chars) */
    PUT_STRING_AT(p, storage_desc, strlen(storage_desc)+1);
    /* VolumeLabel - MTP string format (uint8 len, then uint16 chars) */
    PUT_STRING_AT(p, volume_identifier, strlen(volume_identifier)+1);

    usbd_mtp_send_info(USBD_MTP_CON_DATA->data, (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

uint16_t _get_format_by_name(char *file_name)
{
    uint32_t objformat;
    char file_ext[5];

    memset(file_ext, 0, sizeof(file_ext));

    char* ext = strrchr(file_name, '.');

    /* Get file type */
    if (ext != 0U && (strlen(ext + 1) <= 5)) {
        strcpy(file_ext, (ext + 1));
    } else {
        objformat = MTP_FORMAT_UNDEFINED;
        return objformat;
    }

    if ((strcmp(file_ext, "TXT") == 0) || (strcmp(file_ext, "txt") == 0)) {
        objformat = MTP_FORMAT_TEXT;
    } else if ((strcmp(file_ext, "JPG") == 0) || (strcmp(file_ext, "jpg") == 0)) {
        objformat = MTP_FORMAT_EXIF_JPEG;
    } else if ((strcmp(file_ext, "BMP") == 0) || (strcmp(file_ext, "bmp") == 0)) {
        objformat = MTP_FORMAT_BMP;
    } else if ((strcmp(file_ext, "PNG") == 0) || (strcmp(file_ext, "png") == 0)) {
        objformat = MTP_FORMAT_PNG;
    } else if ((strcmp(file_ext, "MP4") == 0) || (strcmp(file_ext, "mp4") == 0)) {
        objformat = MTP_FORMAT_MP4_CONTAINER;
    } else if ((strcmp(file_ext, "WAV") == 0) || (strcmp(file_ext, "wav") == 0)) {
        objformat = MTP_FORMAT_WAV;
    } else if ((strcmp(file_ext, "PDF") == 0) || (strcmp(file_ext, "pdf") == 0)) {
        objformat = MTP_FORMAT_UNDEFINED;
    } else {
        objformat = MTP_FORMAT_UNDEFINED;
    }

    /* Return object format */
    return objformat;
}

void _string_to_unicode(void *dest, void *src, int len)
{
    uint16_t *dest_str = (uint16_t *)dest;
    uint8_t *src_str = (uint8_t *)src;

    for (int i = 0; i < len; i++) {
        *dest_str = (uint16_t)*src_str;
        dest_str++;
        src_str++;
    }
}

/* Convert UTF-8 string to UTF-16LE
 * src: UTF-8 string
 * dest: UTF-16LE output buffer (uint16_t array)
 * dest_max_words: output buffer size (UTF-16 words)
 * Return: number of UTF-16 characters (excluding null terminator)
 */
static int utf8_to_utf16le(const char *src, uint16_t *dest, int dest_max_words)
{
    if (!src || !dest || dest_max_words <= 0) return 0;

    int dest_idx = 0;
    int src_idx = 0;

    while (src[src_idx] != '\0' && dest_idx < dest_max_words - 1) {
        uint32_t ch = 0;
        int bytes_read = 0;

        uint8_t c = (uint8_t)src[src_idx];

        if (c < 0x80) {
            /* ASCII: 1 byte */
            ch = c;
            bytes_read = 1;
        } else if ((c & 0xE0) == 0xC0) {
            /* 2 byte UTF-8: 110xxxxx 10xxxxxx */
            if (src[src_idx + 1] == '\0') break;
            ch = ((c & 0x1F) << 6) | (src[src_idx + 1] & 0x3F);
            bytes_read = 2;
        } else if ((c & 0xF0) == 0xE0) {
            /* 3 byte UTF-8: 1110xxxx 10xxxxxx 10xxxxxx */
            if (src[src_idx + 1] == '\0' || src[src_idx + 2] == '\0') break;
            ch = ((c & 0x0F) << 12) | ((src[src_idx + 1] & 0x3F) << 6) | (src[src_idx + 2] & 0x3F);
            bytes_read = 3;
        } else {
            /* skip invalid byte */
            src_idx++;
            continue;
        }

        /* Write UTF-16LE character to destination */
        dest[dest_idx++] = (uint16_t)ch;
        src_idx += bytes_read;
    }

    dest[dest_idx] = 0;  /* null terminator */
    return dest_idx;
}

/* Convert UTF-16LE to UTF-8
 * src: UTF-16LE string (uint16_t array)
 * len: UTF-16 character count (not byte count)
 * dest: UTF-8 output buffer
 * dest_size: output buffer size (bytes)
 * return: length of converted UTF-8 string (excluding null terminator)
 */
static int utf16le_to_utf8(char *dest, const uint16_t *src, int len, int dest_size)
{
    if (!dest || !src || dest_size <= 0) return -1;

    int dest_idx = 0;
    int src_idx = 0;

    while (src_idx < len && dest_idx < dest_size - 1) {
        uint16_t ch = src[src_idx++];

        if (ch < 0x80) {
            /* ASCII: 1 byte UTF-8 */
            if (dest_idx + 1 >= dest_size) break;
            dest[dest_idx++] = (char)ch;
        } else if (ch < 0x800) {
            /* 2 byte UTF-8: 110xxxxx 10xxxxxx */
            if (dest_idx + 2 >= dest_size) break;
            dest[dest_idx++] = (char)(0xC0 | (ch >> 6));
            dest[dest_idx++] = (char)(0x80 | (ch & 0x3F));
        } else {
            /* 3 byte UTF-8: 1110xxxx 10xxxxxx 10xxxxxx */
            /* Note: This simplifies the processing, not handling the proxy pair (U+D800~U+DFFF) */
            if (dest_idx + 3 >= dest_size) break;
            dest[dest_idx++] = (char)(0xE0 | (ch >> 12));
            dest[dest_idx++] = (char)(0x80 | ((ch >> 6) & 0x3F));
            dest[dest_idx++] = (char)(0x80 | (ch & 0x3F));
        }
    }

    dest[dest_idx] = '\0';
    return dest_idx;
}

void _unicode_to_string(void *dest, void *src, int len)
{
    uint16_t *src_str = (uint16_t *)src;
    utf16le_to_utf8((char *)dest, src_str, len, CONFIG_USBDEV_MTP_MAX_PATHNAME);
}

/* Convert UTF-8 string to UTF-16LE and write to MTP buffer
 * buf_ptr: pointer to buffer pointer (will be updated)
 * utf8_str: UTF-8 source string
 */
static void put_utf8_as_utf16(uint8_t **buf_ptr, const char *utf8_str,
                               uint8_t *buf_start, size_t buf_size)
{
    /* calculate UTF-16LE length */
    int utf16_len = 0;
    const char *src = utf8_str;
    while (*src != '\0') {
        int bytes_read = 0;
        uint8_t c = (uint8_t)*src;

        if (c < 0x80) {
            bytes_read = 1;
        } else if ((c & 0xE0) == 0xC0) {
            if (src[1] == '\0') break;
            bytes_read = 2;
        } else if ((c & 0xF0) == 0xE0) {
            if (src[1] == '\0' || src[2] == '\0') break;
            bytes_read = 3;
        } else {
            src++;
            continue;
        }
        src += bytes_read;
        utf16_len++;
    }

    /* calculate used size */
    size_t used_size = (*buf_ptr) - buf_start;

    /* check if there is enough space to write length field (1 byte) */
    if (used_size + 1 > buf_size) {
        USB_LOG_ERR("Buffer overflow at length field in put_utf8_as_utf16\n");
        return;
    }

    PUT_U8_AT((*buf_ptr), utf16_len + 1);  /* length (including null terminator) */
    used_size += 1;

    /* re-traverse, convert and write */
    src = utf8_str;
    while (*src != '\0') {
        uint32_t ch;
        int bytes_read = 0;
        uint8_t c = (uint8_t)*src;

        if (c < 0x80) {
            ch = c;
            bytes_read = 1;
        } else if ((c & 0xE0) == 0xC0) {
            if (src[1] == '\0') break;
            ch = ((c & 0x1F) << 6) | (src[1] & 0x3F);
            bytes_read = 2;
        } else if ((c & 0xF0) == 0xE0) {
            if (src[1] == '\0' || src[2] == '\0') break;
            ch = ((c & 0x0F) << 12) | ((src[1] & 0x3F) << 6) | (src[2] & 0x3F);
            bytes_read = 3;
        } else {
            src++;
            continue;
        }

        /* check if there is enough space to write uint16_t (2 bytes) */
        if (used_size + 2 > buf_size) {
            USB_LOG_ERR("Buffer overflow at data field in put_utf8_as_utf16\n");
            return;
        }

        PUT_U16_AT((*buf_ptr), (uint16_t)ch);
        used_size += 2;
        src += bytes_read;
    }

    /* check if there is enough space to write null terminator (2 bytes) */
    if (used_size + 2 > buf_size) {
        USB_LOG_ERR("Buffer overflow at null terminator in put_utf8_as_utf16\n");
        return;
    }

    PUT_U16_AT((*buf_ptr), 0);  /* null terminator */
}

static int mtp_object_handles_list(struct mtp_object_handle *object_handle,
                                uint32_t parent_handle, const char *pathname)
{
    uint32_t i = 0, size = 0, protection_status;
    char *path = (char*)pathname;
    char fullpath[CONFIG_USBDEV_MTP_MAX_PATHNAME];
    void *dir = NULL;
    MTP_DIRENT *dirent = NULL;
    uint8_t file_name_len;
    struct stat statbuf;
    int ret = 0;

    dir = usbd_mtp_opendir(pathname);
    if (dir == NULL) {
        USB_LOG_DBG("Failed to open %s\r\n", pathname);
        return -1;
    }

    USB_LOG_DBG("[MTP_ENUM] opendir success for %s, starting enumeration\r\n", pathname);

    int idx = 0;
    int empty_dir = 1;
    while ((dirent = usbd_mtp_readdir_raw(dir)) != NULL) {
        empty_dir = 0;
        /* Get file information */
        memset(fullpath, 0, sizeof(fullpath));
        strcpy(fullpath, path);
        usbd_mtp_make_fullpath(fullpath, dirent);
        USB_LOG_DBG("[%d] fullpath:%s\r\n", idx, fullpath);
        const char *file_name = strrchr(fullpath, '/');
        if (file_name) {
            file_name++; /* skip '/' */
        } else {
            file_name = path;
        }

        size = usbd_mtp_get_file_size(fullpath);
        if (size < 0)
            break;

        ret = usbd_mtp_stat(fullpath, &statbuf);
        if (ret < 0)
            continue;

        /* alloc handle - alloc full path for file operation and persistence
         * persistence mechanism: if path exists, reuse same handle */
        uint32_t handle = mtp_alloc_handle(&g_usbd_mtp.obj_manager, MTP_STORAGE_ID,
                                          parent_handle, fullpath, 
                                          statbuf.st_mode & S_IFDIR ? MTP_FORMAT_ASSOCIATION : (uint16_t)_get_format_by_name(file_name),
                                          size, statbuf.st_mode & S_IFDIR ? true : false);
        if (handle == 0) {
            USB_LOG_ERR("Failed to allocate handle for %s\n", fullpath);
            continue;
        }

        /* Add to handle list */
        object_handle->ObjectHandle[i] = handle;

        USB_LOG_DBG("file:%s(%lu-%lu-%lu-%lu)\r\n", fullpath,
                        handle, object_handle->ObjectHandle[i], g_usbd_mtp.obj_manager.total_objects, i);


        if (i >= CONFIG_USBDEV_MTP_MAX_OBJECTS)
            break;
        i++;
        idx++;
    }

    USB_LOG_DBG("[MTP_RESP] Final handle array: ");
    for (uint32_t k = 0; k < i; k++) {
        USB_LOG_DBG("0x%lx ", object_handle->ObjectHandle[k]);
    }
    USB_LOG_DBG("\r\n");

    if (empty_dir) {
        USB_LOG_DBG("[MTP_WARN] Directory %s appears to be empty or readdir failed!\r\n", pathname);
    }

    object_handle->ObjectHandle_len = i;
    usbd_mtp_closedir(dir);

    return 0;
}

static void usbd_mtp_get_object_handles(struct mtp_container_command *cmd)
{
    struct mtp_object_handle *p_object_handle = (struct mtp_object_handle *)USBD_MTP_CON_DATA->data;
    int ret;
    char full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME];

    USB_LOG_DBG("GetObjHandles, StorageID:0x%lx, FormatCode:0x%lx, ParentHandle:0x%lx\r\n",
                cmd->param1,
                cmd->param2,
                cmd->param3);

    if (cmd->param3 != 0x00000000 && 
        cmd->param3 != 0xffffffff) {
        mtp_object_t *parent_obj;
        if (mtp_get_object_by_handle(&g_usbd_mtp.obj_manager, cmd->param3, &parent_obj) == 0) {
            if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, cmd->param3, 
                                        full_path, sizeof(full_path)) == 0) {
                USB_LOG_DBG("ParentHandle 0x%lx -> path: %s (format=0x%x)\r\n", 
                            cmd->param3, 
                            full_path,
                            parent_obj->format);
            }
        } else {
            USB_LOG_ERR("ParentHandle 0x%lx not found!\r\n", cmd->param3);
        }
    }

    memset(p_object_handle, 0U, sizeof(struct mtp_object_handle));

    if (cmd->param1 != MTP_STORAGE_ID &&
        cmd->param1 != 0xffffffff) {
        usbd_mtp_send_response(MTP_RESPONSE_STORE_NOT_AVAILABLE);
        return;
    }

    if (cmd->param2 != 0x00000000) {
        usbd_mtp_send_response(MTP_RESPONSE_SPECIFICATION_BY_FORMAT_UNSUPPORTED);
        return;
    }

    if (cmd->param3 == 0x00000000 ||
        cmd->param3 == 0xffffffff) {
        /* Use 0xFFFFFFFF as the canonical "no parent / root" value per MTP */
        ret = mtp_object_handles_list(p_object_handle, 0xFFFFFFFFU, usbd_mtp_fs_root_path());
        if (ret < 0) {
            usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
            return;
        }
    } else {
        mtp_object_t *parent_obj;
        ret = mtp_get_object_by_handle(&g_usbd_mtp.obj_manager, cmd->param3, &parent_obj);
        if (ret < 0) {
            USB_LOG_ERR("Invalid handle: 0x%lx\n", cmd->param3);
            usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
            return;
        }

        if (parent_obj->format != MTP_FORMAT_ASSOCIATION) {
            USB_LOG_ERR("Handle 0x%lx is not a directory (format=0x%x)\n",
                        cmd->param3, parent_obj->format);
            usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
            return;
        }

        /* Rebuild parent object's full path */
        if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, cmd->param3,
                                        full_path, sizeof(full_path)) != 0) {
            USB_LOG_ERR("Failed to rebuild path for parent handle 0x%lx\n",
                       cmd->param3);
            usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
            return;
        }

        ret = mtp_object_handles_list(p_object_handle, cmd->param3,
                                        full_path);
        if (ret < 0) {
            USB_LOG_ERR("Failed to list handles for directory: %s\n", full_path);
            usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
            return;
        }
    }

    USB_LOG_DBG("[MTP_RESP] Returning %lu handles for Parent 0x%lx: ",
                (unsigned long)p_object_handle->ObjectHandle_len,
                (unsigned long)cmd->param3);
    for (uint32_t i = 0; i < p_object_handle->ObjectHandle_len && i < 8; i++) {
        USB_LOG_DBG("0x%lx ", (unsigned long)p_object_handle->ObjectHandle[i]);
    }
    if (p_object_handle->ObjectHandle_len > 8) {
        USB_LOG_DBG("...");
    }
    USB_LOG_DBG("\r\n");

    usbd_mtp_send_info((uint8_t *)p_object_handle, sizeof(uint32_t) * (p_object_handle->ObjectHandle_len + 1U));
}

static void usbd_mtp_get_object_info(struct mtp_container_command *cmd)
{
    mtp_object_t *obj;
    int ret;
    uint8_t *p = (uint8_t *)USBD_MTP_CON_DATA->data;
    uint8_t *buf_start = p;
    size_t buf_size = CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE;
    char full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME];

    USB_LOG_DBG("GetObjInfo, ObjectHandle:0x%lx\r\n",
                cmd->param1);

    ret = mtp_get_object_by_handle(&g_usbd_mtp.obj_manager,
                                    cmd->param1, &obj);
    if (ret < 0) {
        USB_LOG_ERR("Invalid object by handle:0x%lx\r\n", cmd->param1);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    /* Rebuild full path */
    if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, obj->handle, 
                             full_path, sizeof(full_path)) != 0) {
        USB_LOG_ERR("Failed to rebuild full path for handle 0x%lx\n", 
                   (unsigned long)obj->handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    USB_LOG_DBG("format:0x%04x, size:%ld, name:%s, path:%s\r\n",
                obj->format,
                obj->size,
                obj->name,
                full_path);
    USB_LOG_DBG("[MTP_INFO] parent_handle=0x%lx will be sent to PC\r\n",
                (unsigned long)obj->parent_handle);

    PUT_U32_AT(p, MTP_STORAGE_ID); /* storage id */
    PUT_U16_AT(p, obj->format); /* object format */
    PUT_U16_AT(p, 0U); /* protection status */
    PUT_U32_AT(p, obj->size); /* object compressed size */
    PUT_U16_AT(p, MTP_FORMAT_UNDEFINED); /* thumb format */
    PUT_U32_AT(p, 0U); /* thumb compressed size */
    PUT_U32_AT(p, 0U); /* thumb pix width */
    PUT_U32_AT(p, 0U); /* thumb pix height */
    PUT_U32_AT(p, 0U); /* pix width */
    PUT_U32_AT(p, 0U); /* pix height */
    PUT_U32_AT(p, 0U); /* pix depth */
    PUT_U32_AT(p, obj->parent_handle); /* parent object */
    if (obj->format == MTP_FORMAT_ASSOCIATION) /* Association Type */
        PUT_U16_AT(p, 0x0001U); /* generic folder */
    else
        PUT_U16_AT(p, 0x0000U); /* Undefined/Not Association */
    PUT_U32_AT(p, 0U); /* association desc */
    PUT_U32_AT(p, 0U); /* sequence number */
    /* Filename in MTP: convert UTF-8 to UTF-16LE and write to buffer */
    put_utf8_as_utf16(&p, obj->name, buf_start, buf_size);
    {
        struct stat st;
        char time_str[32];
        struct tm tmval;
        /* Fill CaptureDate and ModificationDate in MTP format: year(uint16 LE), month(uint8), day(uint8), hour(uint8), minute(uint8) -> 6 bytes */
        if (usbd_mtp_stat(full_path, &st) == 0) {
            /* Creation/Change time: use st_mtime */
            localtime_r(&st.st_mtime, &tmval);
            snprintf(time_str, sizeof(time_str), "%04d%02d%02dT%02d%02d%02d", 
                    tmval.tm_year + 1900, 
                    tmval.tm_mon + 1, 
                    tmval.tm_mday, 
                    tmval.tm_hour, 
                    tmval.tm_min, 
                    tmval.tm_sec);
            PUT_STRING_AT(p, time_str, strlen(time_str) + 1);

            /* Modification time, reuse the same code as above for creation time */
            PUT_STRING_AT(p, time_str, strlen(time_str) + 1);
        } else {
            strncpy(time_str, "19800101T000000", sizeof(time_str));

            PUT_STRING_AT(p, time_str, strlen(time_str) + 1);
            PUT_STRING_AT(p, time_str, strlen(time_str) + 1);
        }

        /* Keywords: empty string (one byte length 0) */
        PUT_U8_AT(p, 0U);
    }

    usbd_mtp_send_info(USBD_MTP_CON_DATA->data, (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

static void usbd_mtp_get_object(struct mtp_container_command *cmd)
{
    int fd;
    int32_t ret;
    mtp_object_t *obj;
    char full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME];

    ret = mtp_get_object_by_handle(&g_usbd_mtp.obj_manager,
                                  cmd->param1, &obj);
    if (ret < 0) {
        USB_LOG_ERR("Failed to get object handle: 0x%lx\n", 
                   (unsigned long)cmd->param1);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }
    if (obj->format == MTP_FORMAT_ASSOCIATION) {
        USB_LOG_ERR("The object is a folder\r\n");
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    /* Rebuild full path */
    if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, obj->handle,
                             full_path, sizeof(full_path)) != 0) {
        USB_LOG_ERR("Failed to rebuild full path for handle 0x%lx\n", 
                   (unsigned long)obj->handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    /* Read */
    fd = usbd_mtp_open(full_path, O_RDONLY, 0);
    if (fd < 0) {
        USB_LOG_ERR("Failed to open file(%s)\r\n", full_path);
        usbd_mtp_send_response(MTP_RESPONSE_INCOMPLETE_TRANSFER);
        return;
    }

    int32_t data_length = obj->size;

    /* first packet */
    ret = usbd_mtp_read(fd, USBD_MTP_CON_DATA->data,
                            MIN(data_length, CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE));
    USBD_MTP_CON_DATA->conlen = MTP_CONTAINER_HEADER_SIZE + data_length;
    USBD_MTP_CON_DATA->contype = MTP_CONTAINER_TYPE_DATA;
    USBD_MTP_CON_DATA->code = MTP_RESPONSE_OK;
    USBD_MTP_CON_DATA->trans_id = cmd->trans_id;

    data_length = ((data_length - ret) < 0) ? data_length : (data_length - ret);

    if (data_length == 0) {
        g_usbd_mtp.stage = MTP_SEND_RESPONSE;
        if (usbd_mtp_close(fd) < 0) {
            USB_LOG_ERR("Failed to close file(%s)\r\n", full_path);
            usbd_mtp_send_response(MTP_RESPONSE_INCOMPLETE_TRANSFER);
            return;
        }
    } else {
        g_usbd_mtp.stage = MTP_DATA_IN;
        g_usbd_mtp.mtp_file_in.handle = cmd->param1;
        g_usbd_mtp.mtp_file_in.fd = fd;
        g_usbd_mtp.mtp_file_in.data_length = data_length;
    }
    usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_IN_EP_IDX].ep_addr,
                        (uint8_t *)USBD_MTP_CON_DATA,
                        MIN(USBD_MTP_CON_DATA->conlen, CONFIG_USBDEV_MTP_MAX_BUFSIZE));

    return;
}

void usbd_mtp_data_in(void)
{
    int32_t ret;
    int32_t data_length = g_usbd_mtp.mtp_file_in.data_length;

    if (data_length <= 0)
        return;

    ret = usbd_mtp_read(g_usbd_mtp.mtp_file_in.fd,
                                g_usbd_mtp.usbd_mtp_data_in,
                                MIN(data_length, CONFIG_USBDEV_MTP_MAX_BUFSIZE));
    if (ret < 0) {
        USB_LOG_ERR("Failed to read file\r\n");
        if (usbd_mtp_close(g_usbd_mtp.mtp_file_in.fd) < 0) {
            USB_LOG_ERR("Falie to close file\r\n");
        }
        usbd_mtp_send_response(MTP_RESPONSE_INCOMPLETE_TRANSFER);
        return;
    }

    data_length = ((data_length - ret) < 0) ? data_length : (data_length - ret);

    g_usbd_mtp.mtp_file_in.data_length = data_length;

    if (g_usbd_mtp.mtp_file_in.data_length == 0) {
        if (usbd_mtp_close(g_usbd_mtp.mtp_file_in.fd) < 0) {
            USB_LOG_ERR("Falie to close file\r\n");
            return;
        }
        g_usbd_mtp.stage = MTP_SEND_RESPONSE;
    }

    usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_IN_EP_IDX].ep_addr,
                        g_usbd_mtp.usbd_mtp_data_in, ret);

    return;
}

static void usbd_mtp_get_object_prop_desc(struct mtp_container_command *cmd)
{
    uint8_t *p = USBD_MTP_CON_DATA->data;
    uint16_t undef_format = MTP_FORMAT_UNDEFINED;
    uint32_t storageid = MTP_STORAGE_ID;
    USB_LOG_DBG("param:%#lx(1)-%#lx(2)\r\n", cmd->param1, cmd->param2);

    uint16_t prop_code = (uint16_t)(cmd->param2);
    PUT_U16_AT(p, prop_code); //obj prop code

    switch (prop_code) /* switch obj prop code */
    {
        case MTP_PROPERTY_STORAGE_ID:
            PUT_U16_AT(p, MTP_TYPE_UINT32); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET);     /* get/set */
            PUT_U32_AT(p, storageid);       /* default value */
            PUT_U32_AT(p, 0U);               /* group code */
            PUT_U8_AT(p, 0U);                /* form flag */
            break;

        case MTP_PROPERTY_OBJECT_FORMAT:
            PUT_U16_AT(p, MTP_TYPE_UINT16); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET);     /* get/set */
            PUT_U16_AT(p, undef_format);    /* default value */
            PUT_U32_AT(p, 0U);               /* group code */
            PUT_U8_AT(p, 0U);                /* form flag */
            break;

        case MTP_PROPERTY_PROTECTION_STATUS:
            PUT_U16_AT(p, MTP_TYPE_UINT16); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET_SET); /* get/set */
            PUT_U16_AT(p, 0U);              /* default value */
            PUT_U32_AT(p, 0U);              /* group code */
            PUT_U8_AT(p, 0U);               /* form flag */
            break;

        case MTP_PROPERTY_OBJECT_FILE_NAME:
            PUT_U16_AT(p, MTP_TYPE_STR);   /* data type */
            PUT_U8_AT(p, MTP_PROP_GET_SET); /* get/set */
            PUT_U8_AT(p, sizeof(DefaultFileName)/sizeof(uint16_t)); /* default value length */
            for (uint32_t i = 0; i < sizeof(DefaultFileName)/sizeof(uint16_t); i++) {
                PUT_U16_AT(p, DefaultFileName[i]); /* default value string */
            }
            PUT_U32_AT(p, 0U);                /* group code */
            PUT_U8_AT(p, 0U);                 /* form flag */
            break;

        case MTP_PROPERTY_PARENT_OBJECT:
            PUT_U16_AT(p, MTP_TYPE_UINT32); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET);     /* get/set */
            PUT_U32_AT(p, 0U);              /* default value */
            PUT_U32_AT(p, 0U);              /* group code */
            PUT_U8_AT(p, 0U);               /* form flag */
            break;

        case MTP_PROPERTY_OBJECT_SIZE:
            PUT_U16_AT(p, MTP_TYPE_UINT64); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET);     /* get/set */
            PUT_U64_AT(p, 0U);              /* default value */
            PUT_U32_AT(p, 0U);              /* group code */
            PUT_U8_AT(p, 0U);               /* form flag */
            break;

        case MTP_PROPERTY_NAME:
            PUT_U16_AT(p, MTP_TYPE_STR);   /* data type */
            PUT_U8_AT(p, MTP_PROP_GET_SET); /* get/set */
            PUT_U8_AT(p, sizeof(DefaultFileName)/sizeof(uint16_t)); /* default value length */
            for (uint32_t i = 0; i < sizeof(DefaultFileName)/sizeof(uint16_t); i++) {
                PUT_U16_AT(p, DefaultFileName[i]);
            }
            PUT_U32_AT(p, 0U);                /* group code */
            PUT_U8_AT(p, 0U);                 /* form flag */
            break;

        case MTP_PROPERTY_PERSISTENT_UID:
            PUT_U16_AT(p, MTP_TYPE_UINT128); /* data type */
            PUT_U8_AT(p, MTP_PROP_GET);     /* get/set */
            for (uint32_t i = 0; i < 16; i++) {
                PUT_U8_AT(p, 0U);
            }
            PUT_U32_AT(p, 0U);              /* group code */
            PUT_U8_AT(p, 0U);               /* form flag */
            break;
        default:
            usbd_mtp_send_response(MTP_RESPONSE_OBJECT_PROP_NOT_SUPPORTED);
            return;
    }

    usbd_mtp_send_info(USBD_MTP_CON_DATA->data, (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

static void usbd_mtp_get_object_props_supported(void)
{
    struct mtp_object_props_support object_props_support;
    const formats_property *format_property;
    uint32_t i;
    int found = 0;

    for (i = 0; i < sizeof(support_format_properties) / sizeof(formats_property); i++) {
        format_property = &support_format_properties[i];
        if (format_property->format_code == MTP_FORMAT_UNDEFINED) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        for (i = 0; i < 255; i++) {
            if (format_property->properties[i] != 0xFFFF) {
                object_props_support.ObjectPropCode[i] = format_property->properties[i];
            } else {
                break;
            }
        }
        object_props_support.ObjectPropCode_len = i;
        usbd_mtp_send_info((uint8_t *)&object_props_support, sizeof(struct mtp_object_props_support));
    }
}


void usbd_mtp_send_object_info(struct mtp_container_command *cmd)
{
    static uint32_t last_trans_id = 0x0;
    static uint32_t last_parent_handle = 0x0; // FIXME
    uint32_t parent_handle;
    struct mtp_statfs stfs;
    int fd = -1;
    char filename_tmp[CONFIG_USBDEV_MTP_MAX_PATHNAME];
    struct mtp_object_info *object_info;
    int ret;

    if (cmd->trans_id != last_trans_id) {
        last_trans_id = cmd->trans_id;
        last_parent_handle = cmd->param2;
         /* place object in root by default; actual parent will be taken from dataset */
        memset(g_usbd_mtp.path, 0, sizeof(g_usbd_mtp.path));
        strncpy(g_usbd_mtp.path, usbd_mtp_fs_root_path(), sizeof(g_usbd_mtp.path) - 1);

        /* No response, prepare to receive object info dataset */
        USB_LOG_DBG("Prepare to read ObjectInfo dataset on OUT ep (len=%d)\r\n", CONFIG_USBDEV_MTP_MAX_BUFSIZE);
        usbd_ep_start_read(g_usbd_mtp.busid, mtp_ep_data[MTP_OUT_EP_IDX].ep_addr, 
                           (uint8_t *)USBD_MTP_CON_DATA, CONFIG_USBDEV_MTP_MAX_BUFSIZE); // CONFIG_USBDEV_MSC_MAX_BUFSIZE
        return;
    }

    if ((g_usbd_mtp.obj_manager.total_objects + 1U) >= MTP_HANDLE_POOL_SIZE) {
        USB_LOG_ERR("Object limit reached\r\n");
        goto __error_access;
    }

    /* Get ObjectInfo Dataset */
    object_info = (struct mtp_object_info *)&USBD_MTP_CON_DATA->data[0];

    /* UTF-16LE -> UTF-8 */
    memset(filename_tmp, 0, sizeof(filename_tmp));
    _unicode_to_string(filename_tmp,
                        object_info->Filename,
                        object_info->Filename_len);

    USB_LOG_DBG("ObjInfo: StorageId=0x%08lx, Fmt=0x%04x, parent=0x%08lx, fname=%s\r\n",
        object_info->StorageId, object_info->ObjectFormat, object_info->ParentObject, filename_tmp);

    /* Check Storage Space */
    if (usbd_mtp_statfs(usbd_mtp_fs_root_path(), &stfs)) {
        USB_LOG_ERR("Failed to get storage info\r\n");
        goto __error_store_full;
    }

    uint64_t required_size = (uint64_t)object_info->ObjectCompressedSize;
    uint64_t free_space = (uint64_t)stfs.f_bfree * (uint64_t)stfs.f_bsize;
    
    if (required_size > free_space) {
        USB_LOG_ERR("Store full! Req:%lld, Free:%lld\r\n", required_size, free_space);
        goto __error_store_full;
    }

    /* Determine parent from dataset */
    parent_handle = last_parent_handle;
    if (parent_handle != 0xFFFFFFFFU && 
        parent_handle != 0x00000000U) {
        mtp_object_t *parent_obj;
        ret = mtp_get_object_by_handle(&g_usbd_mtp.obj_manager, parent_handle, &parent_obj);
        if (ret != 0) {
            USB_LOG_ERR("Invalid parent handle in dataset: 0x%08lx\r\n", (unsigned long)parent_handle);
            goto __error_access;
        }
        memset(g_usbd_mtp.path, 0, sizeof(g_usbd_mtp.path));
        if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, parent_handle,
                                   g_usbd_mtp.path, sizeof(g_usbd_mtp.path)) != 0) {
            USB_LOG_ERR("Failed to rebuild parent path for handle 0x%lx\n", (unsigned long)parent_handle);
            goto __error_access;
        }
    }

    /* Construct Full Path safely */
    size_t path_len = strlen(g_usbd_mtp.path);
    size_t name_len = strlen(filename_tmp);

    if (path_len + 1 + name_len >= sizeof(g_usbd_mtp.path)) {
        USB_LOG_ERR("Path too long\r\n");
        goto __error_access;
    }

    strcat(g_usbd_mtp.path, "/");
    strcat(g_usbd_mtp.path, filename_tmp);

    USB_LOG_DBG("Target: %s, Size: %lu\n", g_usbd_mtp.path, object_info->ObjectCompressedSize);

    USB_LOG_DBG("Creating object: format=0x%04x protection=%u\r\n", object_info->ObjectFormat, object_info->ProtectionStatus);
    uint8_t *ptr = (uint8_t*)object_info + sizeof(struct mtp_object_info) + object_info->Filename_len * 2;
    GET_STRING_AT(ptr, filename_tmp); /* CreateData */
    USB_LOG_DBG("CreatData: %s\r\n", filename_tmp);
    GET_STRING_AT(ptr, filename_tmp); /* ModifyData */
    USB_LOG_DBG("ModifyData: %s\r\n", filename_tmp);

    /* Create file or directory */
    if (object_info->ObjectFormat != MTP_FORMAT_ASSOCIATION) {
        fd = usbd_mtp_open(g_usbd_mtp.path, O_CREAT | O_TRUNC | O_RDWR, 0644);
    } else {
        ret = usbd_mtp_mkdir(g_usbd_mtp.path);
        fd = (ret == 0) ? 0 : -1;
    }

    if (fd < 0) {
        USB_LOG_ERR("Failed to create file/dir (fd=%d)\r\n", fd);
        goto __error_access;
    }

    /* Allocate Object Handle */
    uint32_t new_handle = mtp_alloc_handle(&g_usbd_mtp.obj_manager, MTP_STORAGE_ID,
                                          parent_handle, g_usbd_mtp.path,
                                          object_info->ObjectFormat,
                                          object_info->ObjectCompressedSize,
                                          object_info->ObjectFormat == MTP_FORMAT_ASSOCIATION ? true : false);
    if (new_handle == 0) {
        USB_LOG_ERR("Failed to allocate object handle\r\n");
        if (object_info->ObjectFormat != MTP_FORMAT_ASSOCIATION) {
            usbd_mtp_close(fd);
            usbd_mtp_unlink(g_usbd_mtp.path); /* Clean up created file */
        }
        goto __error_access;
    }

    if (object_info->ObjectFormat != MTP_FORMAT_ASSOCIATION) {
        usbd_mtp_close(fd);
    }
    g_usbd_mtp.mtp_file_out.handle = new_handle;

    /* Send OK response with StorageID, ParentObject, ObjectHandle (3 params)
     * Response packet size must be 32 bytes, otherwise the host will fail */
    usbd_mtp_send_response_param(MTP_RESPONSE_OK, MTP_STORAGE_ID,
                                    parent_handle,
                                    new_handle, 0, 0);
    USB_LOG_DBG("Response params: code=0x%08lx p1=0x%08lx p2=0x%08lx p3=0x%08lx\r\n",
                (unsigned long)MTP_RESPONSE_OK, (unsigned long)MTP_STORAGE_ID, (unsigned long)parent_handle, (unsigned long)new_handle);
    /* enqueue OBJECT_ADDED event (handle,0,0) */
    usbd_mtp_event_enqueue(MTP_EVENT_OBJECT_ADDED, new_handle, 0U, 0U);
    return;

__error_store_full:
    usbd_mtp_send_response(MTP_RESPONSE_STORAGE_FULL);
    return;

__error_access:
    /* Covers: Access Denied, Path Too Long, Invalid Parent, Creation Fail */
    usbd_mtp_send_response(MTP_RESPONSE_ACCESS_DENIED);
    return;
}

void usbd_mtp_data_out(void)
{
    int32_t ret;
    int32_t data_length = g_usbd_mtp.usbd_mtp_wcnt;
    if (data_length <= 0) {
        usbd_mtp_send_response(MTP_RESPONSE_OK);
        return;
    }

    ret = usbd_mtp_write(g_usbd_mtp.mtp_file_out.fd,
                                g_usbd_mtp.usbd_mtp_data_out,
                                g_usbd_mtp.mtp_file_out.data_length);
    if (ret <= 0) {
        usbd_mtp_send_response(MTP_RESPONSE_INCOMPLETE_TRANSFER);
        if (usbd_mtp_close(g_usbd_mtp.mtp_file_out.fd) < 0) {
            USB_LOG_ERR("Falie to close file\r\n");
        }
        return;
    }

    data_length = ((data_length - ret) < 0) ? data_length : (data_length - ret);

    g_usbd_mtp.mtp_file_out.data_length = MIN(data_length, CONFIG_USBDEV_MTP_MAX_BUFSIZE);

    g_usbd_mtp.usbd_mtp_wcnt = data_length;
    if (g_usbd_mtp.usbd_mtp_wcnt == 0) {
        if (usbd_mtp_close(g_usbd_mtp.mtp_file_out.fd) < 0) {
            USB_LOG_ERR("Falie to close file\r\n");
            return;
        }
        usbd_mtp_send_response(MTP_RESPONSE_OK);
        /* enqueue OBJECT_INFO_CHANGED for the object that was written */
        usbd_mtp_event_enqueue(MTP_EVENT_OBJECT_INFO_CHANGED, g_usbd_mtp.mtp_file_out.handle, 0U, 0U);
        return;
    }
    usbd_ep_start_read(g_usbd_mtp.busid, mtp_ep_data[MTP_OUT_EP_IDX].ep_addr,
                        g_usbd_mtp.usbd_mtp_data_out, CONFIG_USBDEV_MTP_MAX_BUFSIZE);
}

void usbd_mtp_send_object(struct mtp_container_command *cmd)
{
    static uint32_t last_trans_id = 0x0;
    int fd;
    int32_t ret;
    mtp_object_t *obj;
    char full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME];
    
    if (cmd->trans_id != last_trans_id) {
        last_trans_id = cmd->trans_id;
        usbd_ep_start_read(g_usbd_mtp.busid, mtp_ep_data[MTP_OUT_EP_IDX].ep_addr, (uint8_t *)USBD_MTP_CON_DATA, CONFIG_USBDEV_MTP_MAX_BUFSIZE);
        return;
    }

    ret = mtp_get_object_by_handle(&g_usbd_mtp.obj_manager, g_usbd_mtp.mtp_file_out.handle, &obj);

    if (ret < 0) {
        USB_LOG_ERR("Failed to get file handle: 0x%lx\n", (unsigned long)g_usbd_mtp.mtp_file_out.handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    /* Rebuild full path */
    if (mtp_rebuild_full_path(&g_usbd_mtp.obj_manager, obj->handle,
                             full_path, sizeof(full_path)) != 0) {
        USB_LOG_ERR("Failed to rebuild full path for handle 0x%lx\n", (unsigned long)obj->handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    /* Write file */
    fd = usbd_mtp_open(full_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        USB_LOG_ERR("Failed to open file(%s)\r\n", full_path);
        usbd_mtp_send_response(MTP_RESPONSE_INCOMPLETE_TRANSFER);
        return;
    }

    uint32_t data_length = USBD_MTP_CON_DATA->conlen - MTP_CONTAINER_HEADER_SIZE;
    if (data_length > CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE)
        g_usbd_mtp.stage = MTP_DATA_OUT;

    g_usbd_mtp.usbd_mtp_wcnt = data_length;
    g_usbd_mtp.mtp_file_out.fd = fd;
    g_usbd_mtp.mtp_file_out.data_length = MIN(data_length,
                                                CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE);
    memcpy(g_usbd_mtp.usbd_mtp_data_out, USBD_MTP_CON_DATA->data,
            MIN(data_length, CONFIG_USBDEV_MTP_MAX_BUFSIZE - MTP_CONTAINER_HEADER_SIZE));

    usbd_mtp_data_out();

    return;
}

void usbd_mtp_delete_object(struct mtp_container_command *cmd)
{
    int ret = 0;
    uint32_t handle = cmd->param1;
    uint32_t parent_handle = 0;
    
    /* Don't support delete the root object! */
    if (handle == 0xffffffff) {
        USB_LOG_ERR("Don't support delete the root object!\r\n");
        usbd_mtp_send_response(MTP_RESPONSE_OPERATION_NOT_SUPPORTED);
        return;
    }

    ret = mtp_get_parent_by_handle(&g_usbd_mtp.obj_manager, handle, &parent_handle);
    if (ret < 0) {
        USB_LOG_ERR("Failed to get parent handle for object handle 0x%lx\n", (unsigned long)handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    ret = usbd_mtp_unlink_object_by_handle(handle);

    if (ret < 0) {
        USB_LOG_ERR("Failed to delete object handle 0x%lx\n", (unsigned long)handle);
        usbd_mtp_send_response(MTP_RESPONSE_INVALID_OBJECT_HANDLE);
        return;
    }

    usbd_mtp_send_response(MTP_RESPONSE_OK);
    /* enqueue OBJECT_REMOVED event */
    usbd_mtp_event_enqueue(MTP_EVENT_OBJECT_REMOVED, handle, 0U, 0U);
}

static void usbd_mtp_get_device_prop_desc(void)
{
    int i = 0;
    uint8_t *p = USBD_MTP_CON_DATA->data;

    PUT_U16_AT(p, MTP_DEVICE_PROPERTY_DEVICE_FRIENDLY_NAME); /* DevicePropertyCode */
    PUT_U16_AT(p, MTP_TYPE_STR);                             /* DataType */
    PUT_U8_AT(p, MTP_PROP_GET_SET);                          /* GetSet */
    /* DefaultValue_len/CurrentValue_len are measured in UTF-16 code units */
    PUT_U8_AT(p, (uint32_t)(sizeof(DevicePropDefVal) / sizeof(uint16_t))); /* DefaultValue_len */
    for (i = 0; i < (sizeof(DevicePropDefVal) / sizeof(uint16_t)); i++) {
        PUT_U16_AT(p, DevicePropDefVal[i]);
    }
    PUT_U8_AT(p, (uint32_t)(sizeof(DevicePropCurDefVal) / sizeof(uint16_t))); /* CurrentValue_len */
    for (i = 0; i < (sizeof(DevicePropCurDefVal) / sizeof(uint16_t)); i++) {
        PUT_U16_AT(p, DevicePropCurDefVal[i]);
    }
    PUT_U8_AT(p, 0U);                                        /* FormFlag */
    usbd_mtp_send_info(USBD_MTP_CON_DATA->data,
                        (uint32_t)(p - USBD_MTP_CON_DATA->data));
}

static int usbd_mtp_decode(struct mtp_container_command *cmd)
{
    USB_LOG_DBG("Decode MTP command: code=0x%04x, contype=%u, conlen=%lu, trans_id=%lu, param1=0x%08lx, param2=0x%08lx, param3=0x%08lx\r\n",
                cmd->code, cmd->contype, (unsigned long)cmd->conlen, (unsigned long)cmd->trans_id,
                (unsigned long)cmd->param1, (unsigned long)cmd->param2, (unsigned long)cmd->param3);
    switch (cmd->code) {
        case MTP_OPERATION_GET_DEVICE_INFO:
            usbd_mtp_get_device_info();
            break;
        case MTP_OPERATION_OPEN_SESSION:
            usbd_mtp_open_session();
            break;
        case MTP_OPERATION_CLOSE_SESSION:
            g_usbd_mtp.session_state = 0;  /* Close session */
            usbd_mtp_send_response(MTP_RESPONSE_OK);
            break;
        case MTP_OPERATION_GET_STORAGE_IDS:
            usbd_mtp_get_storage_ids();
            break;
        case MTP_OPERATION_GET_STORAGE_INFO:
            usbd_mtp_get_storage_info();
            break;
        case MTP_OPERATION_GET_OBJECT_HANDLES:
            usbd_mtp_get_object_handles(cmd);
            break;
        case MTP_OPERATION_GET_OBJECT_INFO:
            usbd_mtp_get_object_info(cmd);
            break;
        case MTP_OPERATION_GET_OBJECT_REFERENCES:
            usbd_mtp_send_response(MTP_RESPONSE_OPERATION_NOT_SUPPORTED);
            break;
        case MTP_OPERATION_GET_OBJECT_PROPS_SUPPORTED:
            usbd_mtp_get_object_props_supported();
            break;
        case MTP_OPERATION_GET_OBJECT_PROP_DESC:
            usbd_mtp_get_object_prop_desc(cmd);
            break;
        case MTP_OPERATION_GET_OBJECT_PROP_LIST:
            usbd_mtp_send_response(MTP_RESPONSE_OPERATION_NOT_SUPPORTED);
            break;
        case MTP_OPERATION_SET_OBJECT_PROP_VALUE:
            /* usbd_mtp_set_object_prop_value(); */
            usbd_mtp_send_response(MTP_RESPONSE_OPERATION_NOT_SUPPORTED);
            break;
        case MTP_OPERATION_GET_OBJECT_PROP_VALUE:
            /* usbd_mtp_get_object_prop_value(); */
            usbd_mtp_send_response(MTP_RESPONSE_OPERATION_NOT_SUPPORTED);
            break;
        case MTP_OPERATION_GET_DEVICE_PROP_DESC:
            usbd_mtp_get_device_prop_desc();
            break;
        case MTP_OPERATION_GET_OBJECT:
            usbd_mtp_get_object(cmd);
            break;
        case MTP_OPERATION_SEND_OBJECT_INFO:
            usbd_mtp_send_object_info(cmd);
            break;
        case MTP_OPERATION_SEND_OBJECT:
            usbd_mtp_send_object(cmd);
            break;
        case MTP_OPERATION_DELETE_OBJECT:
            usbd_mtp_delete_object(cmd);
            break;

        default:
            USB_LOG_WRN("code:%04x\r\n", cmd->code);
            break;
    }
    return 0;
}

static void usbd_mtp_bulk_out(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    USB_LOG_DBG("bulk_out callback: ep=0x%02x nbytes=%lu stage=%d\r\n", ep, nbytes, g_usbd_mtp.stage);
    switch (g_usbd_mtp.stage) {
        case MTP_READ_COMMAND:
            #ifdef CONFIG_USBDEV_MTP_THREAD
            usb_osal_mq_send(g_usbd_mtp.usbd_mtp_mq, MTP_READ_COMMAND);
            #else
            usbd_mtp_decode((struct mtp_header *)&g_usbd_mtp.header);
            #endif
            break;
        case MTP_DATA_OUT:
            #ifdef CONFIG_USBDEV_MTP_THREAD
            usb_osal_mq_send(g_usbd_mtp.usbd_mtp_mq, MTP_DATA_OUT);
            #else
            usbd_mtp_data_out();
            #endif
            break;
        default:
            break;
    }
}

static void usbd_mtp_bulk_in(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    switch (g_usbd_mtp.stage) {
        case MTP_DATA_IN:
            #ifdef CONFIG_USBDEV_MTP_THREAD
            usb_osal_mq_send(g_usbd_mtp.usbd_mtp_mq, MTP_DATA_IN);
            #else
            usbd_mtp_data_in();
            #endif
            break;
        case MTP_SEND_RESPONSE:
            usbd_mtp_send_response(MTP_RESPONSE_OK);
            break;
        case MTP_WAIT_RESPONSE:
            g_usbd_mtp.stage = MTP_READ_COMMAND;
            usbd_ep_start_read(g_usbd_mtp.busid, mtp_ep_data[MTP_OUT_EP_IDX].ep_addr, (uint8_t *)&g_usbd_mtp.header, CONFIG_USBDEV_MTP_MAX_BUFSIZE);
            break;
        default:
            break;
    }
}

static void usbd_mtp_event_int(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    /* INT IN transfer completed (interrupt context): avoid blocking calls.
     * Clear busy flag and notify worker thread to send next event, or
     * directly try to start next event when no thread is configured.
     */
    (void)busid; (void)ep; (void)nbytes;
    g_usbd_mtp.int_busy = 0;
#ifdef CONFIG_USBDEV_MTP_THREAD
    if (g_usbd_mtp.usbd_mtp_mq) {
        /* notify worker to process queued events (non-blocking) */
        usb_osal_mq_send(g_usbd_mtp.usbd_mtp_mq, (uintptr_t)MTP_THREAD_EVENT_SEND);
    }
#else
    /* No thread: try to send next event directly (non-blocking, no mutex)
     * We implement a nolock sender to avoid mutex in interrupt.
     */
    {
        if (g_usbd_mtp.ev_q_head != g_usbd_mtp.ev_q_tail && !g_usbd_mtp.int_busy) {
            uint8_t *p = g_usbd_mtp.event_buf;
            uint16_t code = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].code;
            uint32_t p1 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p1;
            uint32_t p2 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p2;
            uint32_t p3 = g_usbd_mtp.event_q[g_usbd_mtp.ev_q_tail].p3;
            g_usbd_mtp.ev_q_tail = (uint8_t)((g_usbd_mtp.ev_q_tail + 1) % MTP_EVENT_Q_SIZE);

            PUT_U32_AT(p, (uint32_t)(MTP_CONTAINER_HEADER_SIZE + 12));  // container length
            PUT_U16_AT(p, MTP_CONTAINER_TYPE_EVENT);                    // container type
            PUT_U16_AT(p, code);                                       // event code
            PUT_U32_AT(p, 0U);                                          // transaction ID = 0 for events
            PUT_U32_AT(p, p1);                                         // parameter 1
            PUT_U32_AT(p, p2);                                         // parameter 2
            PUT_U32_AT(p, p3);                                         // parameter 3

            g_usbd_mtp.int_busy = 1;
            usbd_ep_start_write(g_usbd_mtp.busid, mtp_ep_data[MTP_INT_EP_IDX].ep_addr, g_usbd_mtp.event_buf, MTP_CONTAINER_HEADER_SIZE + 12);
        }
    }
#endif
}

static void mtp_notify_handler(uint8_t busid, uint8_t event, void *arg)
{
    switch (event) {
        case USBD_EVENT_RESET:
            break;
        case USBD_EVENT_CONFIGURED:
            USB_LOG_DBG("Start reading command\r\n");
            g_usbd_mtp.stage = MTP_READ_COMMAND;
            usbd_ep_start_read(busid, mtp_ep_data[MTP_OUT_EP_IDX].ep_addr, (uint8_t *)&g_usbd_mtp.header, CONFIG_USBDEV_MTP_MAX_BUFSIZE);
            break;

        default:
            break;
    }
}

#ifdef CONFIG_USBDEV_MTP_THREAD
static void usbdev_mtp_thread(void *argument)
{
    uintptr_t event;
    int ret;

    while (1) {
        ret = usb_osal_mq_recv(g_usbd_mtp.usbd_mtp_mq, (uintptr_t *)&event, USB_OSAL_WAITING_FOREVER);
        if (ret < 0) {
            continue;
        }
        USB_LOG_DBG("%d\r\n", event);
        if (event == MTP_DATA_OUT) {
            usbd_mtp_data_out();
        } else if (event == MTP_DATA_IN) {
            usbd_mtp_data_in();
        } else if (event == MTP_READ_COMMAND) {
            struct mtp_container_command cmd = *(struct mtp_container_command *)&g_usbd_mtp.header;
            usbd_mtp_decode(&cmd);
        } else if (event == MTP_THREAD_EVENT_SEND) {
            /* send next pending event (worker context) */
            if (g_usbd_mtp.ev_mutex) {
                usb_osal_mutex_take(g_usbd_mtp.ev_mutex);
                usbd_mtp_event_send_queued_locked();
                usb_osal_mutex_give(g_usbd_mtp.ev_mutex);
            }
        } else {
        }
    }
}
#endif

struct usbd_interface *usbd_mtp_init_intf(uint8_t busid,
                                          struct usbd_interface *intf,
                                          const uint8_t out_ep,
                                          const uint8_t in_ep,
                                          const uint8_t int_ep)
{
    USB_LOG_DBG("usbd_mtp_init_intf called: busid=%d out_ep=0x%02x in_ep=0x%02x int_ep=0x%02x\r\n", busid, out_ep, in_ep, int_ep);
    g_usbd_mtp.busid = busid;

    /* Initialize object manager */
    if (mtp_object_manager_init(&g_usbd_mtp.obj_manager) != 0) {
        USB_LOG_ERR("Failed to initialize MTP object manager\r\n");
        return NULL;
    }

    intf->class_interface_handler = mtp_class_interface_request_handler;
    intf->class_endpoint_handler = NULL;
    intf->vendor_handler = NULL;
    intf->notify_handler = mtp_notify_handler;

    mtp_ep_data[MTP_OUT_EP_IDX].ep_addr = out_ep;
    mtp_ep_data[MTP_OUT_EP_IDX].ep_cb = usbd_mtp_bulk_out;
    mtp_ep_data[MTP_IN_EP_IDX].ep_addr = in_ep;
    mtp_ep_data[MTP_IN_EP_IDX].ep_cb = usbd_mtp_bulk_in;
    mtp_ep_data[MTP_INT_EP_IDX].ep_addr = int_ep;
    mtp_ep_data[MTP_INT_EP_IDX].ep_cb = usbd_mtp_event_int;

    usbd_add_endpoint(busid, &mtp_ep_data[MTP_OUT_EP_IDX]);
    usbd_add_endpoint(busid, &mtp_ep_data[MTP_IN_EP_IDX]);
    usbd_add_endpoint(busid, &mtp_ep_data[MTP_INT_EP_IDX]); //event

#ifdef CONFIG_USBDEV_MTP_THREAD
    g_usbd_mtp.usbd_mtp_mq = usb_osal_mq_create(DATA_BUFFER_SIZE / MAX_WITTE_FILE_SIZE);
    if (g_usbd_mtp.usbd_mtp_mq == NULL) {
        mtp_object_manager_deinit(&g_usbd_mtp.obj_manager);
        return NULL;
    }
    g_usbd_mtp.usbd_mtp_thread = usb_osal_thread_create("usbd_mtp", CONFIG_USBDEV_MTP_STACKSIZE, CONFIG_USBDEV_MTP_PRIO, usbdev_mtp_thread, NULL);
    if (g_usbd_mtp.usbd_mtp_thread == NULL) {
        usb_osal_mq_delete(g_usbd_mtp.usbd_mtp_mq);
        mtp_object_manager_deinit(&g_usbd_mtp.obj_manager);
        return NULL;
    }
#endif
    /* init event queue and mutex */
    g_usbd_mtp.ev_q_head = 0;
    g_usbd_mtp.ev_q_tail = 0;
    g_usbd_mtp.int_busy = 0;
    g_usbd_mtp.ev_mutex = usb_osal_mutex_create();

    return intf;
}

/* Get MTP object manager instance */
mtp_object_manager_t *usbd_mtp_get_obj_manager(void)
{
    return &g_usbd_mtp.obj_manager;
}
