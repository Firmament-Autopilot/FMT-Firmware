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

#include <firmament.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "drv_usbd_cdc_rb.h"
#include "hal/usb/usbd_cdc.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "USB.h"
#include "USB_CDC.h"
#include "usb_config.h"

#define VENDOR_ID              0xFFFF
#define PRODUCT_ID             0xFFFF
#define USB_ENABLE_FLAG        0u
#define USB_BULK_IN_INTERVAL   0u
#define USB_BULK_OUT_INTERVAL  0u
#define USB_INT_INTERVAL       16u
#define USB_THREAD_STACK       6144u
#define USB_THREAD_PRIO        8u
#define USB_THREAD_TICK        10u
#define USB_START_DELAY_MS     50u
#define USB_RX_POLL_MS         2u
#define USB_TX_READY_TIMEOUT   50u
#define USB_TX_DONE_TIMEOUT    200u
#define USB_DCACHE_ALIGN       __SCB_DCACHE_LINE_SIZE
#define USB_TX_BUFFER_SIZE     1024u
#define USB_RX_BUFFER_SIZE     8192u
#define USB_MAVFTP_FAST_CHAN   MAVLINK_COMM_3
#define USB_FTP_WRITE_QUEUE_SIZE 512u
#define USB_FTP_WRITE_QUEUE_WAIT_MS 500u
#define USB_FTP_WRITE_QUEUE_HIGH_WATERMARK ((USB_FTP_WRITE_QUEUE_SIZE * 3u) / 4u)
#define USB_FTP_WRITE_QUEUE_LOW_WATERMARK  (USB_FTP_WRITE_QUEUE_SIZE / 2u)
#define USB_FTP_WRITE_BACKPRESSURE_WAIT_MS 300u
#define USB_FTP_WRITE_THREAD_STACK 4096u
#define USB_FTP_WRITE_THREAD_PRIO  9u
#define USB_FTP_WRITE_THREAD_TICK  10u
#define USB_DIRECT_TX_SEM_TIMEOUT_MS 200u
#define USB_FTP_UPLOAD_CACHE_SIZE 4096u
#define USB_FTP_UPLOAD_MAX_PATH_LEN 268u

typedef struct {
    uint8_t payload[MAVLINK_MSG_FILE_TRANSFER_PROTOCOL_FIELD_PAYLOAD_LEN];
    uint8_t target_system;
    uint8_t target_component;
    uint16_t req_seq;
    uint8_t req_opcode;
    uint8_t size;
    uint32_t offset;
} usb_ftp_write_job_t;

static const USB_DEVICE_INFO usb_device_info = {
    VENDOR_ID,
    PRODUCT_ID,
    "Firmament",
    "Firmament CDC Device",
    "2024010001"
};

static struct usbd_cdc_dev cdc_device;
static USB_CDC_HANDLE usb_cdc_handle;
static volatile bool usb_configured = false;
static volatile bool usb_stack_started = false;
static rt_thread_t usb_thread = RT_NULL;
static volatile bool usb_tx_pending = false;
static volatile bool usb_tx_abort_pending = false;
static volatile bool usb_tx_slot_busy = false;
static rt_size_t usb_tx_size = 0u;
static rt_sem_t usb_tx_sem = RT_NULL;
static drv_usbd_cdc_rb_t usb_rx_rb;
static uint8_t usb_mavlink_frame[MAVLINK_MAX_PACKET_LEN];
static mavlink_message_t usb_mavlink_rx_msg;
static mavlink_message_t usb_mavlink_tx_msg;
static mavlink_file_transfer_protocol_t usb_ftp_protocol;
static uint8_t usb_mavlink_tx_buffer[MAVLINK_MAX_PACKET_LEN];
static rt_sem_t usb_ftp_write_free_sem = RT_NULL;
static rt_sem_t usb_ftp_write_queued_sem = RT_NULL;
static rt_thread_t usb_ftp_write_thread = RT_NULL;
static volatile uint16_t usb_ftp_write_head = 0u;
static volatile uint16_t usb_ftp_write_tail = 0u;
static volatile uint16_t usb_ftp_write_depth = 0u;
static volatile bool usb_ftp_write_inflight = false;
static uint16_t usb_mavlink_frame_len = 0u;
static volatile uint32_t usb_rx_packet_count = 0u;
static volatile uint32_t usb_rx_byte_count = 0u;
static volatile uint32_t usb_rx_forward_count = 0u;
static volatile uint32_t usb_rx_drop_count = 0u;
static volatile uint32_t usb_mavlink_frame_ok_count = 0u;
static volatile uint32_t usb_mavlink_frame_bad_count = 0u;
static volatile uint32_t usb_ftp_seen_count = 0u;
static volatile uint32_t usb_ftp_target_mismatch_count = 0u;
static volatile uint32_t usb_ftp_fast_handled_count = 0u;
static volatile uint32_t usb_ftp_no_ack_count = 0u;
static volatile uint32_t usb_ftp_fast_ack_count = 0u;
static volatile uint32_t usb_ftp_fast_ack_fail_count = 0u;
static volatile uint32_t usb_ftp_duplicate_req_count = 0u;
static volatile uint32_t usb_ftp_proc_total_ms = 0u;
static volatile uint32_t usb_ftp_proc_max_ms = 0u;
static volatile uint32_t usb_ftp_tx_total_ms = 0u;
static volatile uint32_t usb_ftp_tx_max_ms = 0u;
static volatile uint32_t usb_ftp_total_max_ms = 0u;
static volatile uint32_t usb_ftp_total_over_50ms_count = 0u;
static volatile uint32_t usb_ftp_total_over_100ms_count = 0u;
static volatile uint32_t usb_ftp_total_over_500ms_count = 0u;
static volatile uint32_t usb_ftp_total_over_1000ms_count = 0u;
static volatile uint16_t usb_ftp_last_req_seq = 0u;
static volatile uint16_t usb_ftp_last_rsp_seq = 0u;
static volatile uint8_t usb_ftp_last_req_opcode = 0u;
static volatile uint8_t usb_ftp_last_rsp_opcode = 0u;
static volatile uint8_t usb_ftp_last_rsp_req_opcode = 0u;
static volatile uint8_t usb_ftp_last_session = 0u;
static volatile uint8_t usb_ftp_last_size = 0u;
static volatile uint32_t usb_ftp_last_offset = 0u;
static volatile uint32_t usb_ftp_last_proc_ms = 0u;
static volatile uint32_t usb_ftp_last_tx_ms = 0u;
static volatile uint32_t usb_ftp_last_total_ms = 0u;
static volatile uint16_t usb_ftp_slowest_req_seq = 0u;
static volatile uint8_t usb_ftp_slowest_req_opcode = 0u;
static volatile uint8_t usb_ftp_slowest_session = 0u;
static volatile uint8_t usb_ftp_slowest_size = 0u;
static volatile uint32_t usb_ftp_slowest_offset = 0u;
static volatile uint32_t usb_ftp_write_queued_count = 0u;
static volatile uint32_t usb_ftp_write_worker_ok_count = 0u;
static volatile uint32_t usb_ftp_write_worker_fail_count = 0u;
static volatile uint32_t usb_ftp_write_queue_full_count = 0u;
static volatile uint32_t usb_ftp_write_sync_fallback_count = 0u;
static volatile uint16_t usb_ftp_write_max_depth = 0u;
static volatile uint32_t usb_ftp_write_worker_max_ms = 0u;
static volatile uint32_t usb_ftp_write_drain_max_ms = 0u;
static volatile uint32_t usb_ftp_write_backpressure_count = 0u;
static volatile uint32_t usb_ftp_write_backpressure_max_ms = 0u;
static volatile uint32_t usb_ftp_upload_flush_count = 0u;
static volatile uint32_t usb_ftp_upload_flush_fail_count = 0u;
static volatile uint32_t usb_tx_direct_sem_busy_count = 0u;
static volatile uint32_t usb_tx_direct_sem_timeout_count = 0u;
static volatile uint32_t usb_tx_direct_ready_fail_count = 0u;
static volatile uint32_t usb_tx_direct_write_fail_count = 0u;
static volatile uint32_t usb_tx_direct_wait_fail_count = 0u;

static void usb_cdc_process_tx(void);

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t read_buffer[USB_HS_BULK_MAX_PACKET_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t write_buffer[USB_TX_BUFFER_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t usb_rx_buffer[USB_RX_BUFFER_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static U8 out_ep_buffer[USB_HS_BULK_MAX_PACKET_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static usb_ftp_write_job_t usb_ftp_write_queue[USB_FTP_WRITE_QUEUE_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t usb_ftp_upload_cache[USB_FTP_UPLOAD_CACHE_SIZE];

static int usb_ftp_upload_fd = -1;
static uint32_t usb_ftp_upload_cache_offset = 0u;
static uint32_t usb_ftp_upload_cache_len = 0u;

static void usb_dcache_clean(const void* addr, rt_size_t size)
{
    (void)addr;
    (void)size;
}

static void usb_dcache_invalidate(const void* addr, rt_size_t size)
{
    (void)addr;
    (void)size;
}

static void usb_add_cdc(void)
{
    USB_CDC_INIT_DATA init_data;
    USB_ADD_EP_INFO ep_bulk_in;
    USB_ADD_EP_INFO ep_bulk_out;
    USB_ADD_EP_INFO ep_int_in;

    memset(&init_data, 0, sizeof(init_data));
    memset(&ep_bulk_in, 0, sizeof(ep_bulk_in));
    memset(&ep_bulk_out, 0, sizeof(ep_bulk_out));
    memset(&ep_int_in, 0, sizeof(ep_int_in));

    ep_bulk_in.Flags = USB_ENABLE_FLAG;
    ep_bulk_in.InDir = USB_DIR_IN;
    ep_bulk_in.Interval = USB_BULK_IN_INTERVAL;
    ep_bulk_in.MaxPacketSize = USB_HS_BULK_MAX_PACKET_SIZE;
    ep_bulk_in.TransferType = USB_TRANSFER_TYPE_BULK;
    init_data.EPIn = USBD_AddEPEx(&ep_bulk_in, NULL, 0);

    ep_bulk_out.Flags = USB_ENABLE_FLAG;
    ep_bulk_out.InDir = USB_DIR_OUT;
    ep_bulk_out.Interval = USB_BULK_OUT_INTERVAL;
    ep_bulk_out.MaxPacketSize = USB_HS_BULK_MAX_PACKET_SIZE;
    ep_bulk_out.TransferType = USB_TRANSFER_TYPE_BULK;
    init_data.EPOut = USBD_AddEPEx(&ep_bulk_out, out_ep_buffer, sizeof(out_ep_buffer));

    ep_int_in.Flags = USB_ENABLE_FLAG;
    ep_int_in.InDir = USB_DIR_IN;
    ep_int_in.Interval = USB_INT_INTERVAL;
    ep_int_in.MaxPacketSize = USB_HS_INT_MAX_PACKET_SIZE;
    ep_int_in.TransferType = USB_TRANSFER_TYPE_INT;
    init_data.EPInt = USBD_AddEPEx(&ep_int_in, NULL, 0);

    usb_cdc_handle = USBD_CDC_Add(&init_data);
}

static void usb_notify_rx_ready(void)
{
    if (cdc_device.parent.rx_indicate) {
        cdc_device.parent.rx_indicate(&cdc_device.parent, drv_usbd_cdc_rb_len(&usb_rx_rb));
    }
}

static uint32_t usb_push_rx_data(const uint8_t* data, uint32_t len)
{
    uint32_t pushed_len;

    pushed_len = drv_usbd_cdc_rb_put(&usb_rx_rb, data, len);
    usb_rx_forward_count += pushed_len;
    if (pushed_len < len) {
        usb_rx_drop_count += len - pushed_len;
    }

    return pushed_len;
}

static void usb_mavlink_fastpath_reset(void)
{
    usb_mavlink_frame_len = 0u;
    mavlink_reset_channel_status(USB_MAVFTP_FAST_CHAN);
}

static bool usb_ftp_write_queue_idle(void)
{
    return usb_ftp_write_depth == 0u && !usb_ftp_write_inflight;
}

static bool usb_ftp_wait_write_queue_idle(uint32_t timeout_ms)
{
    uint32_t start_ms = systime_now_ms();

    while (!usb_ftp_write_queue_idle()) {
        if ((systime_now_ms() - start_ms) >= timeout_ms) {
            return false;
        }
        rt_thread_mdelay(1);
    }

    return true;
}

static void usb_ftp_finish_ack(FTP_Msg_Payload* ftp_payload)
{
    ftp_payload->seq_number++;
    ftp_payload->req_opcode = ftp_payload->opcode;
    ftp_payload->opcode = kRspAck;
}

static void usb_ftp_finish_nak(FTP_Msg_Payload* ftp_payload, uint8_t err_code, uint8_t err_no)
{
    ftp_payload->seq_number++;
    ftp_payload->req_opcode = ftp_payload->opcode;
    ftp_payload->opcode = kRspNak;
    ftp_payload->size = 1u;
    ftp_payload->data[0] = err_code;
    if (err_code == kErrFailErrno) {
        ftp_payload->size = 2u;
        ftp_payload->data[1] = err_no;
    }
}

static void usb_ftp_upload_cache_reset(void)
{
    usb_ftp_upload_cache_offset = 0u;
    usb_ftp_upload_cache_len = 0u;
}

static uint8_t usb_ftp_upload_cache_flush(void)
{
    uint32_t written = 0u;

    if (usb_ftp_upload_cache_len == 0u) {
        return kErrNone;
    }

    if (usb_ftp_upload_fd < 0) {
        usb_ftp_upload_cache_reset();
        return kErrInvalidSession;
    }

    off_t off = lseek(usb_ftp_upload_fd, usb_ftp_upload_cache_offset, SEEK_SET);
    if (off != (off_t)usb_ftp_upload_cache_offset) {
        usb_ftp_upload_flush_fail_count++;
        return kErrFailErrno;
    }

    while (written < usb_ftp_upload_cache_len) {
        int bw = write(usb_ftp_upload_fd,
                       &usb_ftp_upload_cache[written],
                       usb_ftp_upload_cache_len - written);
        if (bw <= 0) {
            usb_ftp_upload_flush_fail_count++;
            return kErrFailErrno;
        }
        written += (uint32_t)bw;
    }

    usb_ftp_upload_flush_count++;
    usb_ftp_upload_cache_reset();
    return kErrNone;
}

static uint8_t usb_ftp_upload_close(void)
{
    uint8_t err_code = usb_ftp_upload_cache_flush();

    if (usb_ftp_upload_fd >= 0) {
        if (close(usb_ftp_upload_fd) < 0 && err_code == kErrNone) {
            err_code = kErrFailErrno;
        }
        usb_ftp_upload_fd = -1;
    }
    usb_ftp_upload_cache_reset();

    return err_code;
}

static uint8_t usb_ftp_upload_write(const FTP_Msg_Payload* ftp_payload)
{
    uint32_t write_size = ftp_payload->size;
    uint8_t err_code;

    if (ftp_payload->session != 0u || usb_ftp_upload_fd < 0) {
        return kErrInvalidSession;
    }

    if (write_size > sizeof(usb_ftp_upload_cache)) {
        return kErrFail;
    }

    if (usb_ftp_upload_cache_len > 0u &&
        ftp_payload->offset != (usb_ftp_upload_cache_offset + usb_ftp_upload_cache_len)) {
        err_code = usb_ftp_upload_cache_flush();
        if (err_code != kErrNone) {
            return err_code;
        }
    }

    if (usb_ftp_upload_cache_len == 0u) {
        usb_ftp_upload_cache_offset = ftp_payload->offset;
    }

    if ((usb_ftp_upload_cache_len + write_size) > sizeof(usb_ftp_upload_cache)) {
        err_code = usb_ftp_upload_cache_flush();
        if (err_code != kErrNone) {
            return err_code;
        }
        usb_ftp_upload_cache_offset = ftp_payload->offset;
    }

    memcpy(&usb_ftp_upload_cache[usb_ftp_upload_cache_len], ftp_payload->data, write_size);
    usb_ftp_upload_cache_len += write_size;

    if (write_size < MAX_FTP_DATA_LEN) {
        err_code = usb_ftp_upload_cache_flush();
        if (err_code != kErrNone) {
            return err_code;
        }
    }

    return kErrNone;
}

static bool usb_ftp_upload_can_ack_write(const FTP_Msg_Payload* ftp_payload)
{
    return ftp_payload->session == 0u &&
           usb_ftp_upload_fd >= 0 &&
           ftp_payload->size <= MAX_FTP_DATA_LEN;
}

static bool usb_ftp_handle_upload_open(FTP_Msg_Payload* ftp_payload, int oflag)
{
    char file_name[USB_FTP_UPLOAD_MAX_PATH_LEN + 1u];
    struct stat fno;
    uint32_t file_size = 0u;

    if (ftp_payload->size > USB_FTP_UPLOAD_MAX_PATH_LEN) {
        usb_ftp_finish_nak(ftp_payload, kErrEOF, 0u);
        return true;
    }

    (void)usb_ftp_upload_close();

    memcpy(file_name, ftp_payload->data, ftp_payload->size);
    file_name[ftp_payload->size] = '\0';

    if (stat(file_name, &fno) == 0) {
        file_size = (uint32_t)fno.st_size;
    } else if ((oflag & O_CREAT) == 0) {
        usb_ftp_finish_nak(ftp_payload, kErrFailErrno, (uint8_t)rt_get_errno());
        return true;
    }

    usb_ftp_upload_fd = open(file_name, oflag);
    if (usb_ftp_upload_fd < 0) {
        usb_ftp_finish_nak(ftp_payload, kErrFailErrno, (uint8_t)rt_get_errno());
        return true;
    }

    usb_ftp_upload_cache_reset();
    ftp_payload->session = 0u;
    ftp_payload->size = sizeof(uint32_t);
    memcpy(ftp_payload->data, &file_size, ftp_payload->size);
    usb_ftp_finish_ack(ftp_payload);

    return true;
}

static bool usb_ftp_handle_upload_control(FTP_Msg_Payload* ftp_payload)
{
    uint8_t err_code;

    switch (ftp_payload->opcode) {
    case kCmdCreateFile:
        return usb_ftp_handle_upload_open(ftp_payload, O_CREAT | O_TRUNC | O_WRONLY);

    case kCmdOpenFileWO:
        return usb_ftp_handle_upload_open(ftp_payload, O_WRONLY);

    case kCmdTerminateSession:
        if (usb_ftp_upload_fd < 0) {
            return false;
        }
        err_code = usb_ftp_upload_close();
        if (err_code == kErrNone) {
            ftp_payload->size = 0u;
            usb_ftp_finish_ack(ftp_payload);
        } else {
            usb_ftp_finish_nak(ftp_payload, err_code, (uint8_t)rt_get_errno());
        }
        return true;

    default:
        return false;
    }
}

static void usb_ftp_backpressure_if_needed(void)
{
    uint32_t start_ms;
    uint32_t elapsed_ms;

    if (usb_ftp_write_depth < USB_FTP_WRITE_QUEUE_HIGH_WATERMARK) {
        return;
    }

    usb_ftp_write_backpressure_count++;
    start_ms = systime_now_ms();
    while (usb_ftp_write_depth > USB_FTP_WRITE_QUEUE_LOW_WATERMARK) {
        if ((systime_now_ms() - start_ms) >= USB_FTP_WRITE_BACKPRESSURE_WAIT_MS) {
            break;
        }
        rt_thread_mdelay(1);
    }

    elapsed_ms = systime_now_ms() - start_ms;
    if (elapsed_ms > usb_ftp_write_backpressure_max_ms) {
        usb_ftp_write_backpressure_max_ms = elapsed_ms;
    }
}

static bool usb_ftp_enqueue_write(const uint8_t* payload, uint8_t target_system, uint8_t target_component)
{
    FTP_Msg_Payload* ftp_payload;
    uint16_t slot;

    if (usb_ftp_write_free_sem == RT_NULL || usb_ftp_write_queued_sem == RT_NULL) {
        return false;
    }

    if (rt_sem_take(usb_ftp_write_free_sem, TICKS_FROM_MS(USB_FTP_WRITE_QUEUE_WAIT_MS)) != RT_EOK) {
        usb_ftp_write_queue_full_count++;
        return false;
    }

    OS_ENTER_CRITICAL;
    slot = usb_ftp_write_head;
    usb_ftp_write_head = (usb_ftp_write_head + 1u) % USB_FTP_WRITE_QUEUE_SIZE;
    usb_ftp_write_depth++;
    if (usb_ftp_write_depth > usb_ftp_write_max_depth) {
        usb_ftp_write_max_depth = usb_ftp_write_depth;
    }
    OS_EXIT_CRITICAL;

    rt_memcpy(usb_ftp_write_queue[slot].payload,
              payload,
              MAVLINK_MSG_FILE_TRANSFER_PROTOCOL_FIELD_PAYLOAD_LEN);
    usb_ftp_write_queue[slot].target_system = target_system;
    usb_ftp_write_queue[slot].target_component = target_component;

    ftp_payload = (FTP_Msg_Payload*)usb_ftp_write_queue[slot].payload;
    usb_ftp_write_queue[slot].req_seq = ftp_payload->seq_number;
    usb_ftp_write_queue[slot].req_opcode = ftp_payload->opcode;
    usb_ftp_write_queue[slot].size = ftp_payload->size;
    usb_ftp_write_queue[slot].offset = ftp_payload->offset;

    usb_ftp_write_queued_count++;
    rt_sem_release(usb_ftp_write_queued_sem);

    return true;
}

static void usb_ftp_ack_write_request(FTP_Msg_Payload* ftp_payload)
{
    uint32_t written_size = ftp_payload->size;

    ftp_payload->seq_number++;
    ftp_payload->req_opcode = ftp_payload->opcode;
    ftp_payload->opcode = kRspAck;
    ftp_payload->size = sizeof(uint32_t);
    rt_memcpy(ftp_payload->data, &written_size, ftp_payload->size);
}

static void usb_ftp_nak_write_request(FTP_Msg_Payload* ftp_payload, uint8_t err_code)
{
    ftp_payload->seq_number++;
    ftp_payload->req_opcode = ftp_payload->opcode;
    ftp_payload->opcode = kRspNak;
    ftp_payload->size = 1u;
    ftp_payload->data[0] = err_code;
}

static void usb_ftp_force_reset_session(uint8_t target_system, uint8_t target_component)
{
    uint8_t reset_payload[MAVLINK_MSG_FILE_TRANSFER_PROTOCOL_FIELD_PAYLOAD_LEN] = { 0 };
    FTP_Msg_Payload* reset_msg = (FTP_Msg_Payload*)reset_payload;

    usb_ftp_wait_write_queue_idle(30000u);

    reset_msg->opcode = kCmdResetSessions;
    reset_msg->session = 0u;
    reset_msg->size = 0u;
    reset_msg->seq_number = 0u;

    (void)ftp_process_request(reset_payload, target_system, target_component);
}

static fmt_err_t usb_ftp_process_write_job(usb_ftp_write_job_t* job)
{
    FTP_Msg_Payload* ftp_payload = (FTP_Msg_Payload*)job->payload;
    uint8_t err_code = usb_ftp_upload_write(ftp_payload);

    (void)job;

    return err_code == kErrNone ? FMT_EOK : FMT_ERROR;
}

static void usb_ftp_write_thread_entry(void* parameter)
{
    usb_ftp_write_job_t job;
    uint16_t slot;

    (void)parameter;

    while (1) {
        if (rt_sem_take(usb_ftp_write_queued_sem, RT_WAITING_FOREVER) != RT_EOK) {
            continue;
        }

        OS_ENTER_CRITICAL;
        slot = usb_ftp_write_tail;
        usb_ftp_write_tail = (usb_ftp_write_tail + 1u) % USB_FTP_WRITE_QUEUE_SIZE;
        usb_ftp_write_depth--;
        usb_ftp_write_inflight = true;
        OS_EXIT_CRITICAL;

        rt_memcpy(&job, &usb_ftp_write_queue[slot], sizeof(job));
        rt_sem_release(usb_ftp_write_free_sem);

        uint32_t start_ms = systime_now_ms();
        fmt_err_t ret = usb_ftp_process_write_job(&job);
        uint32_t elapsed_ms = systime_now_ms() - start_ms;

        if (elapsed_ms > usb_ftp_write_worker_max_ms) {
            usb_ftp_write_worker_max_ms = elapsed_ms;
        }

        if (ret == FMT_EOK) {
            usb_ftp_write_worker_ok_count++;
        } else {
            usb_ftp_write_worker_fail_count++;
        }

        OS_ENTER_CRITICAL;
        usb_ftp_write_inflight = false;
        OS_EXIT_CRITICAL;
    }
}

static void usb_update_connection_state(void)
{
    uint32_t state;

    state = USBD_GetState();

    if (!usb_configured) {
        if ((state & (USB_STAT_CONFIGURED | USB_STAT_SUSPENDED)) == USB_STAT_CONFIGURED) {
            usb_configured = true;
            hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_CONNECT);
        }
    } else if ((state & USB_STAT_CONFIGURED) == 0u) {
        bool need_release = usb_tx_slot_busy;

        usb_configured = false;
        usb_tx_pending = false;
        usb_tx_size = 0u;
        usb_tx_abort_pending = true;
        usb_tx_slot_busy = false;
        if (need_release && usb_tx_sem) {
            rt_sem_release(usb_tx_sem);
        }
        hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_DISCONNECT);
        drv_usbd_cdc_rb_flush(&usb_rx_rb);
        usb_mavlink_fastpath_reset();
        (void)usb_ftp_wait_write_queue_idle(30000u);
        (void)usb_ftp_upload_close();
    }
}

static void usb_cdc_process_tx(void)
{
    int ret;
    int wait_ret;

    if (usb_tx_abort_pending) {
        usb_tx_abort_pending = false;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
    }

    if (!usb_tx_pending) {
        return;
    }

    if (!usb_stack_started || !usb_configured || usb_tx_size == 0u) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    usb_dcache_clean(write_buffer, usb_tx_size);

    ret = USBD_CDC_WaitForTXReady(usb_cdc_handle, USB_TX_READY_TIMEOUT);
    if (ret < 0) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    ret = USBD_CDC_Write(usb_cdc_handle, write_buffer, (unsigned)usb_tx_size, 0);
    if (ret < 0) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    wait_ret = USBD_CDC_WaitForTX(usb_cdc_handle, USB_TX_DONE_TIMEOUT);
    if (wait_ret < 0) {
        USBD_CDC_CancelWrite(usb_cdc_handle);
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    usb_tx_pending = false;
    usb_tx_size = 0u;
    if (usb_tx_slot_busy) {
        usb_tx_slot_busy = false;
        if (usb_tx_sem) {
            rt_sem_release(usb_tx_sem);
        }
    }
    hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_TX_COMPLETE);
}

static rt_size_t usb_cdc_write_direct(const void* buf, rt_size_t size)
{
    int ret;
    int wait_ret;
    uint32_t wait_start_ms;

    if (!usb_stack_started || !usb_configured || buf == RT_NULL || size == 0u) {
        return 0u;
    }

    if (size > sizeof(write_buffer) || usb_tx_sem == RT_NULL) {
        return 0u;
    }

    if (rt_sem_take(usb_tx_sem, 0) != RT_EOK) {
        usb_tx_direct_sem_busy_count++;
        wait_start_ms = systime_now_ms();
        while (rt_sem_take(usb_tx_sem, 0) != RT_EOK) {
            usb_cdc_process_tx();
            if ((systime_now_ms() - wait_start_ms) >= USB_DIRECT_TX_SEM_TIMEOUT_MS) {
                usb_tx_direct_sem_timeout_count++;
                return 0u;
            }
            rt_thread_mdelay(1);
        }
    }

    if (!usb_stack_started || !usb_configured) {
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    memcpy(write_buffer, buf, size);
    usb_dcache_clean(write_buffer, size);

    ret = USBD_CDC_WaitForTXReady(usb_cdc_handle, USB_TX_READY_TIMEOUT);
    if (ret < 0) {
        usb_tx_direct_ready_fail_count++;
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    ret = USBD_CDC_Write(usb_cdc_handle, write_buffer, (unsigned)size, 0);
    if (ret < 0) {
        usb_tx_direct_write_fail_count++;
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    wait_ret = USBD_CDC_WaitForTX(usb_cdc_handle, USB_TX_DONE_TIMEOUT);
    if (wait_ret < 0) {
        usb_tx_direct_wait_fail_count++;
        USBD_CDC_CancelWrite(usb_cdc_handle);
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    rt_sem_release(usb_tx_sem);
    hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_TX_COMPLETE);

    return size;
}

static bool usb_try_handle_mavlink_ftp(mavlink_message_t* msg)
{
    mavlink_system_t this_system;
    FTP_Msg_Payload* ftp_payload;
    uint16_t tx_len;
    uint16_t req_seq;
    uint8_t req_opcode;
    uint32_t start_ms;
    uint32_t proc_done_ms;
    uint32_t tx_done_ms;
    uint32_t proc_ms;
    uint32_t tx_ms;
    uint32_t total_ms;
    uint32_t drain_start_ms;
    uint32_t drain_ms;
    bool async_write_ack = false;
    rt_size_t sent_len;

    if (msg->msgid != MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL) {
        return false;
    }

    usb_ftp_seen_count++;
    this_system = mavproxy_get_system();
    if (this_system.sysid != mavlink_msg_file_transfer_protocol_get_target_system(msg)) {
        usb_ftp_target_mismatch_count++;
        return false;
    }

    usb_ftp_fast_handled_count++;
    mavlink_msg_file_transfer_protocol_decode(msg, &usb_ftp_protocol);
    ftp_payload = (FTP_Msg_Payload*)usb_ftp_protocol.payload;
    req_seq = ftp_payload->seq_number;
    req_opcode = ftp_payload->opcode;

    if (req_seq == usb_ftp_last_req_seq && req_opcode == usb_ftp_last_req_opcode) {
        usb_ftp_duplicate_req_count++;
    }

    usb_ftp_last_req_seq = req_seq;
    usb_ftp_last_req_opcode = req_opcode;
    usb_ftp_last_session = ftp_payload->session;
    usb_ftp_last_size = ftp_payload->size;
    usb_ftp_last_offset = ftp_payload->offset;

    start_ms = systime_now_ms();
    if (req_opcode == kCmdWriteFile) {
        usb_ftp_backpressure_if_needed();
        if (!usb_ftp_upload_can_ack_write(ftp_payload)) {
            usb_ftp_nak_write_request(ftp_payload, kErrInvalidSession);
            async_write_ack = true;
        } else if (usb_ftp_enqueue_write(usb_ftp_protocol.payload, msg->sysid, msg->compid)) {
            usb_ftp_ack_write_request(ftp_payload);
            async_write_ack = true;
        } else {
            usb_ftp_nak_write_request(ftp_payload, kErrFail);
            async_write_ack = true;
        }
    } else {
        drain_start_ms = systime_now_ms();
        usb_ftp_wait_write_queue_idle(30000u);
        drain_ms = systime_now_ms() - drain_start_ms;
        if (drain_ms > usb_ftp_write_drain_max_ms) {
            usb_ftp_write_drain_max_ms = drain_ms;
        }

        if (req_opcode == kCmdResetSessions) {
            (void)usb_ftp_upload_close();
        } else if (req_opcode == kCmdCreateFile || req_opcode == kCmdOpenFileWO) {
            usb_ftp_force_reset_session(msg->sysid, msg->compid);
        }

        if (req_opcode == kCmdCreateFile || req_opcode == kCmdOpenFileWO || req_opcode == kCmdTerminateSession) {
            if (usb_ftp_handle_upload_control(ftp_payload)) {
                async_write_ack = true;
            }
        }
    }

    if (!async_write_ack && ftp_process_request(usb_ftp_protocol.payload, msg->sysid, msg->compid) != FMT_EOK) {
        proc_done_ms = systime_now_ms();
        proc_ms = proc_done_ms - start_ms;
        usb_ftp_last_proc_ms = proc_ms;
        usb_ftp_proc_total_ms += proc_ms;
        if (proc_ms > usb_ftp_proc_max_ms) {
            usb_ftp_proc_max_ms = proc_ms;
        }
        usb_ftp_no_ack_count++;
        return true;
    }
    proc_done_ms = systime_now_ms();
    proc_ms = proc_done_ms - start_ms;

    usb_ftp_protocol.target_system = msg->sysid;
    usb_ftp_protocol.target_component = msg->compid;
    usb_ftp_protocol.target_network = 0;

    mavlink_msg_file_transfer_protocol_encode(this_system.sysid, this_system.compid, &usb_mavlink_tx_msg, &usb_ftp_protocol);
    tx_len = mavlink_msg_to_send_buffer(usb_mavlink_tx_buffer, &usb_mavlink_tx_msg);

    sent_len = usb_cdc_write_direct(usb_mavlink_tx_buffer, tx_len);
    tx_done_ms = systime_now_ms();
    tx_ms = tx_done_ms - proc_done_ms;
    total_ms = tx_done_ms - start_ms;

    usb_ftp_last_rsp_seq = ftp_payload->seq_number;
    usb_ftp_last_rsp_opcode = ftp_payload->opcode;
    usb_ftp_last_rsp_req_opcode = ftp_payload->req_opcode;
    usb_ftp_last_proc_ms = proc_ms;
    usb_ftp_last_tx_ms = tx_ms;
    usb_ftp_last_total_ms = total_ms;
    usb_ftp_proc_total_ms += proc_ms;
    usb_ftp_tx_total_ms += tx_ms;

    if (proc_ms > usb_ftp_proc_max_ms) {
        usb_ftp_proc_max_ms = proc_ms;
    }
    if (tx_ms > usb_ftp_tx_max_ms) {
        usb_ftp_tx_max_ms = tx_ms;
    }
    if (total_ms > usb_ftp_total_max_ms) {
        usb_ftp_total_max_ms = total_ms;
        usb_ftp_slowest_req_seq = req_seq;
        usb_ftp_slowest_req_opcode = req_opcode;
        usb_ftp_slowest_session = usb_ftp_last_session;
        usb_ftp_slowest_size = usb_ftp_last_size;
        usb_ftp_slowest_offset = usb_ftp_last_offset;
    }
    if (total_ms > 50u) {
        usb_ftp_total_over_50ms_count++;
    }
    if (total_ms > 100u) {
        usb_ftp_total_over_100ms_count++;
    }
    if (total_ms > 500u) {
        usb_ftp_total_over_500ms_count++;
    }
    if (total_ms > 1000u) {
        usb_ftp_total_over_1000ms_count++;
    }

    if (sent_len == tx_len) {
        usb_ftp_fast_ack_count++;
    } else {
        usb_ftp_fast_ack_fail_count++;
    }

    return true;
}

static uint32_t usb_process_rx_byte(uint8_t byte)
{
    mavlink_status_t status;
    uint8_t parse_ret;
    uint32_t pushed_len = 0u;

    if (usb_mavlink_frame_len == 0u) {
        if (byte != MAVLINK_STX && byte != MAVLINK_STX_MAVLINK1) {
            return usb_push_rx_data(&byte, 1u);
        }
        usb_mavlink_frame[usb_mavlink_frame_len++] = byte;
    } else {
        if (usb_mavlink_frame_len >= sizeof(usb_mavlink_frame)) {
            pushed_len += usb_push_rx_data(usb_mavlink_frame, usb_mavlink_frame_len);
            usb_mavlink_frame_len = 0u;
            usb_mavlink_fastpath_reset();
            return pushed_len + usb_push_rx_data(&byte, 1u);
        }
        usb_mavlink_frame[usb_mavlink_frame_len++] = byte;
    }

    parse_ret = mavlink_parse_char(USB_MAVFTP_FAST_CHAN, byte, &usb_mavlink_rx_msg, &status);
    if (parse_ret == MAVLINK_FRAMING_OK) {
        usb_mavlink_frame_ok_count++;
        if (!usb_try_handle_mavlink_ftp(&usb_mavlink_rx_msg)) {
            pushed_len += usb_push_rx_data(usb_mavlink_frame, usb_mavlink_frame_len);
        }
        usb_mavlink_frame_len = 0u;
    } else if (parse_ret == MAVLINK_FRAMING_BAD_CRC || parse_ret == MAVLINK_FRAMING_BAD_SIGNATURE) {
        usb_mavlink_frame_bad_count++;
        pushed_len += usb_push_rx_data(usb_mavlink_frame, usb_mavlink_frame_len);
        usb_mavlink_frame_len = 0u;
    }

    return pushed_len;
}

static uint32_t usb_process_rx_data(const uint8_t* data, uint32_t len)
{
    uint32_t pushed_len = 0u;

    for (uint32_t i = 0u; i < len; i++) {
        pushed_len += usb_process_rx_byte(data[i]);
    }

    return pushed_len;
}

static void usb_cdc_thread_entry(void* parameter)
{
    int recv_len;
    uint32_t pushed_len;

    (void)parameter;

    rt_thread_mdelay(USB_START_DELAY_MS);

    USBD_Init();
    usb_add_cdc();
    USBD_SetDeviceInfo(&usb_device_info);
    USBD_Start();
    usb_stack_started = true;

    while (1) {
        usb_update_connection_state();

        if (!usb_configured) {
            continue;
        }

        recv_len = USBD_CDC_Receive(usb_cdc_handle, read_buffer, sizeof(read_buffer), USB_RX_POLL_MS);
        if (recv_len > 0) {
            usb_dcache_invalidate(read_buffer, (rt_size_t)recv_len);
            usb_rx_packet_count++;
            usb_rx_byte_count += (uint32_t)recv_len;

            pushed_len = usb_process_rx_data(read_buffer, (uint32_t)recv_len);
            if (pushed_len > 0u) {
                usb_notify_rx_ready();
            }
        }

        usb_cdc_process_tx();
    }
}

static rt_err_t cdc_dev_init(usbd_cdc_dev_t dev)
{
    (void)dev;

    if (usb_thread != RT_NULL) {
        return RT_EOK;
    }

    if (drv_usbd_cdc_rb_init(&usb_rx_rb, usb_rx_buffer, sizeof(usb_rx_buffer)) != RT_EOK) {
        return RT_ERROR;
    }
    usb_mavlink_fastpath_reset();

    usb_tx_sem = rt_sem_create("usb_txq", 1, RT_IPC_FLAG_FIFO);
    if (usb_tx_sem == RT_NULL) {
        return RT_ENOMEM;
    }

    usb_ftp_write_free_sem = rt_sem_create("ufwfree", USB_FTP_WRITE_QUEUE_SIZE, RT_IPC_FLAG_FIFO);
    if (usb_ftp_write_free_sem == RT_NULL) {
        return RT_ENOMEM;
    }

    usb_ftp_write_queued_sem = rt_sem_create("ufwq", 0, RT_IPC_FLAG_FIFO);
    if (usb_ftp_write_queued_sem == RT_NULL) {
        return RT_ENOMEM;
    }

    usb_ftp_write_thread = rt_thread_create("usb_ftpw",
                                            usb_ftp_write_thread_entry,
                                            RT_NULL,
                                            USB_FTP_WRITE_THREAD_STACK,
                                            USB_FTP_WRITE_THREAD_PRIO,
                                            USB_FTP_WRITE_THREAD_TICK);
    if (usb_ftp_write_thread == RT_NULL) {
        return RT_ENOMEM;
    }
    rt_thread_startup(usb_ftp_write_thread);

    usb_thread = rt_thread_create("usb_cdc",
                                  usb_cdc_thread_entry,
                                  RT_NULL,
                                  USB_THREAD_STACK,
                                  USB_THREAD_PRIO,
                                  USB_THREAD_TICK);
    if (usb_thread == RT_NULL) {
        return RT_ENOMEM;
    }

    rt_thread_startup(usb_thread);
    return RT_EOK;
}

static rt_size_t cdc_dev_read(usbd_cdc_dev_t dev, rt_off_t pos, void* buf, rt_size_t size)
{
    (void)dev;
    (void)pos;

    return drv_usbd_cdc_rb_get(&usb_rx_rb, buf, (uint32_t)size);
}

static rt_size_t cdc_dev_write(usbd_cdc_dev_t dev, rt_off_t pos, const void* buf, rt_size_t size)
{
    (void)dev;
    (void)pos;

    if (!usb_stack_started || !usb_configured || buf == RT_NULL || size == 0u) {
        return 0u;
    }

    if (size > sizeof(write_buffer) || usb_tx_sem == RT_NULL) {
        return 0u;
    }

    if (rt_sem_take(usb_tx_sem, TICKS_FROM_MS(USB_TX_DONE_TIMEOUT)) != RT_EOK) {
        return 0u;
    }

    if (!usb_stack_started || !usb_configured) {
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    memcpy(write_buffer, buf, size);
    usb_tx_slot_busy = true;
    usb_tx_size = size;
    usb_tx_pending = true;

    return size;
}

static rt_err_t cdc_dev_control(usbd_cdc_dev_t dev, int cmd, void* arg)
{
    (void)dev;
    (void)cmd;
    (void)arg;
    return RT_EOK;
}

static struct usbd_cdc_ops cdc_ops = {
    .dev_init = NULL,
    .dev_read = cdc_dev_read,
    .dev_write = cdc_dev_write,
    .dev_control = cdc_dev_control
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t ret;

    memset(&cdc_device, 0, sizeof(cdc_device));
    cdc_device.ops = &cdc_ops;
    cdc_device.status = USBD_STATUS_DISCONNECT;

    ret = hal_usbd_cdc_register(&cdc_device,
                                "usbd_cdc",
                                RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
                                NULL);
    if (ret != RT_EOK) {
        return ret;
    }

    ret = cdc_dev_init(&cdc_device);
    if (ret != RT_EOK) {
        return ret;
    }

    return RT_EOK;
}

#if defined(RT_USING_FINSH)
    #include <finsh.h>

static void usb_cdc_stat_clear(void)
{
    OS_ENTER_CRITICAL;
    usb_rx_packet_count = 0u;
    usb_rx_byte_count = 0u;
    usb_rx_forward_count = 0u;
    usb_rx_drop_count = 0u;
    usb_mavlink_frame_ok_count = 0u;
    usb_mavlink_frame_bad_count = 0u;
    usb_ftp_seen_count = 0u;
    usb_ftp_target_mismatch_count = 0u;
    usb_ftp_fast_handled_count = 0u;
    usb_ftp_no_ack_count = 0u;
    usb_ftp_fast_ack_count = 0u;
    usb_ftp_fast_ack_fail_count = 0u;
    usb_ftp_duplicate_req_count = 0u;
    usb_ftp_proc_total_ms = 0u;
    usb_ftp_proc_max_ms = 0u;
    usb_ftp_tx_total_ms = 0u;
    usb_ftp_tx_max_ms = 0u;
    usb_ftp_total_max_ms = 0u;
    usb_ftp_total_over_50ms_count = 0u;
    usb_ftp_total_over_100ms_count = 0u;
    usb_ftp_total_over_500ms_count = 0u;
    usb_ftp_total_over_1000ms_count = 0u;
    usb_ftp_last_req_seq = 0u;
    usb_ftp_last_rsp_seq = 0u;
    usb_ftp_last_req_opcode = 0u;
    usb_ftp_last_rsp_opcode = 0u;
    usb_ftp_last_rsp_req_opcode = 0u;
    usb_ftp_last_session = 0u;
    usb_ftp_last_size = 0u;
    usb_ftp_last_offset = 0u;
    usb_ftp_last_proc_ms = 0u;
    usb_ftp_last_tx_ms = 0u;
    usb_ftp_last_total_ms = 0u;
    usb_ftp_slowest_req_seq = 0u;
    usb_ftp_slowest_req_opcode = 0u;
    usb_ftp_slowest_session = 0u;
    usb_ftp_slowest_size = 0u;
    usb_ftp_slowest_offset = 0u;
    usb_ftp_write_queued_count = 0u;
    usb_ftp_write_worker_ok_count = 0u;
    usb_ftp_write_worker_fail_count = 0u;
    usb_ftp_write_queue_full_count = 0u;
    usb_ftp_write_sync_fallback_count = 0u;
    usb_ftp_write_max_depth = usb_ftp_write_depth;
    usb_ftp_write_worker_max_ms = 0u;
    usb_ftp_write_drain_max_ms = 0u;
    usb_ftp_write_backpressure_count = 0u;
    usb_ftp_write_backpressure_max_ms = 0u;
    usb_ftp_upload_flush_count = 0u;
    usb_ftp_upload_flush_fail_count = 0u;
    usb_tx_direct_sem_busy_count = 0u;
    usb_tx_direct_sem_timeout_count = 0u;
    usb_tx_direct_ready_fail_count = 0u;
    usb_tx_direct_write_fail_count = 0u;
    usb_tx_direct_wait_fail_count = 0u;
    OS_EXIT_CRITICAL;
}

static int usb_cdc_stat(int argc, char** argv)
{
    if (argc > 1) {
        if (rt_strcmp(argv[1], "clear") == 0 || rt_strcmp(argv[1], "reset") == 0) {
            usb_cdc_stat_clear();
            rt_kprintf("usb_cdc_stat cleared\n");
            return 0;
        }

        rt_kprintf("usage: usb_cdc_stat [clear]\n");
        return 0;
    }

    rt_kprintf("usb configured=%u stack_started=%u rx_rb_len=%lu frame_len=%u tx_pending=%u tx_size=%lu\n",
               usb_configured ? 1u : 0u,
               usb_stack_started ? 1u : 0u,
               (unsigned long)drv_usbd_cdc_rb_len(&usb_rx_rb),
               (unsigned int)usb_mavlink_frame_len,
               usb_tx_pending ? 1u : 0u,
               (unsigned long)usb_tx_size);
    rt_kprintf("rx packet=%lu byte=%lu forward=%lu drop=%lu\n",
               (unsigned long)usb_rx_packet_count,
               (unsigned long)usb_rx_byte_count,
               (unsigned long)usb_rx_forward_count,
               (unsigned long)usb_rx_drop_count);
    rt_kprintf("mav frame_ok=%lu frame_bad=%lu\n",
               (unsigned long)usb_mavlink_frame_ok_count,
               (unsigned long)usb_mavlink_frame_bad_count);
    rt_kprintf("ftp seen=%lu target_mismatch=%lu handled=%lu no_ack=%lu ack_ok=%lu ack_fail=%lu\n",
               (unsigned long)usb_ftp_seen_count,
               (unsigned long)usb_ftp_target_mismatch_count,
               (unsigned long)usb_ftp_fast_handled_count,
               (unsigned long)usb_ftp_no_ack_count,
               (unsigned long)usb_ftp_fast_ack_count,
               (unsigned long)usb_ftp_fast_ack_fail_count);
    rt_kprintf("ftp duplicate_req=%lu last req_seq=%u req_op=%u rsp_seq=%u rsp_op=%u rsp_req_op=%u session=%u size=%u offset=%lu\n",
               (unsigned long)usb_ftp_duplicate_req_count,
               (unsigned int)usb_ftp_last_req_seq,
               (unsigned int)usb_ftp_last_req_opcode,
               (unsigned int)usb_ftp_last_rsp_seq,
               (unsigned int)usb_ftp_last_rsp_opcode,
               (unsigned int)usb_ftp_last_rsp_req_opcode,
               (unsigned int)usb_ftp_last_session,
               (unsigned int)usb_ftp_last_size,
               (unsigned long)usb_ftp_last_offset);
    rt_kprintf("ftp timing last proc=%lums tx=%lums total=%lums max proc=%lums tx=%lums total=%lums\n",
               (unsigned long)usb_ftp_last_proc_ms,
               (unsigned long)usb_ftp_last_tx_ms,
               (unsigned long)usb_ftp_last_total_ms,
               (unsigned long)usb_ftp_proc_max_ms,
               (unsigned long)usb_ftp_tx_max_ms,
               (unsigned long)usb_ftp_total_max_ms);
    rt_kprintf("ftp slowest req_seq=%u req_op=%u session=%u size=%u offset=%lu\n",
               (unsigned int)usb_ftp_slowest_req_seq,
               (unsigned int)usb_ftp_slowest_req_opcode,
               (unsigned int)usb_ftp_slowest_session,
               (unsigned int)usb_ftp_slowest_size,
               (unsigned long)usb_ftp_slowest_offset);
    rt_kprintf("ftp timing avg proc=%lums tx=%lums over50=%lu over100=%lu over500=%lu over1000=%lu\n",
               usb_ftp_fast_handled_count ? (unsigned long)(usb_ftp_proc_total_ms / usb_ftp_fast_handled_count) : 0u,
               usb_ftp_fast_ack_count ? (unsigned long)(usb_ftp_tx_total_ms / usb_ftp_fast_ack_count) : 0u,
               (unsigned long)usb_ftp_total_over_50ms_count,
               (unsigned long)usb_ftp_total_over_100ms_count,
               (unsigned long)usb_ftp_total_over_500ms_count,
               (unsigned long)usb_ftp_total_over_1000ms_count);
    rt_kprintf("ftp writeq depth=%u max_depth=%u queued=%lu worker_ok=%lu worker_fail=%lu full=%lu sync_fallback=%lu worker_max=%lums drain_max=%lums backpressure=%lu bp_max=%lums inflight=%u\n",
               (unsigned int)usb_ftp_write_depth,
               (unsigned int)usb_ftp_write_max_depth,
               (unsigned long)usb_ftp_write_queued_count,
               (unsigned long)usb_ftp_write_worker_ok_count,
               (unsigned long)usb_ftp_write_worker_fail_count,
               (unsigned long)usb_ftp_write_queue_full_count,
               (unsigned long)usb_ftp_write_sync_fallback_count,
               (unsigned long)usb_ftp_write_worker_max_ms,
               (unsigned long)usb_ftp_write_drain_max_ms,
               (unsigned long)usb_ftp_write_backpressure_count,
               (unsigned long)usb_ftp_write_backpressure_max_ms,
               usb_ftp_write_inflight ? 1u : 0u);
    rt_kprintf("ftp upload fd=%d cache_len=%lu cache_offset=%lu flush=%lu flush_fail=%lu\n",
               usb_ftp_upload_fd,
               (unsigned long)usb_ftp_upload_cache_len,
               (unsigned long)usb_ftp_upload_cache_offset,
               (unsigned long)usb_ftp_upload_flush_count,
               (unsigned long)usb_ftp_upload_flush_fail_count);
    rt_kprintf("tx direct_sem_busy=%lu sem_timeout=%lu ready_fail=%lu write_fail=%lu wait_fail=%lu\n",
               (unsigned long)usb_tx_direct_sem_busy_count,
               (unsigned long)usb_tx_direct_sem_timeout_count,
               (unsigned long)usb_tx_direct_ready_fail_count,
               (unsigned long)usb_tx_direct_write_fail_count,
               (unsigned long)usb_tx_direct_wait_fail_count);

    return 0;
}
MSH_CMD_EXPORT(usb_cdc_stat, show USB CDC MAVLink FTP fast-path counters);
#endif
