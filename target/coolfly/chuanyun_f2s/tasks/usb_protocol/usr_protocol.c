#include <stdio.h>
#include <string.h>

#include "debuglog.h"
#include "hal.h"
#include "hal_bb.h"
#include "hal_usb_device.h"
#include "usr_wir_core.h"

// #include "usr_upgrade.h"
// #include "test_bb_sigQuality.h"
// #include "test_bb_led_ctrl_2.h"
#include "usr_protocol.h"
#include "usr_usb_task.h"
// #include "c201d_pt.h"
// #include "usr_uart3_task.h"
// #include "hal_sram_ground.h"

// #include "cf_protocol.h"
// #include "cf_parse_cmd.h"

#define DATA_RDY                    0
#define DATA_NORDY                  1
#define DATA_ERR                    2

#define USB_FIFO_SIEZ               512
#define USB_BYPASS_MAX_PLAYLOAD_LEN (USB_FIFO_SIEZ - 10 - 4) // 10 byte head ,4 byte to 4times euqal

// parse usr data
/*
image trans error rate
 all pack num = (Npacket *((BW)/10)*768*96*log(qam))/2304
 cur default Npacket = 1
 qam = 2 (bpsk) qam = 4(qpsk) qam=16(16qam) qam=64(64qam)

10Mhz
 bpsk 32
 qpsk 64
 16qam 128
 64qam 192
20Mhz
 10Mhz * 2
*/
const uint8_t  pack_total[4] = { 32, 64, 128, 192 };
static uint8_t bypass_buf[512];
static uint8_t bypass_uart_buf[512];
static uint8_t bypass_cf_protocol_buf[512];

#define TO4TIMES(value) ((((value) + 3) / 4) * 4)

uint8_t get_grd_status_info(unsigned char* buf, int* len)
{
    unsigned char *             pstart, *p;
    HAL_RET_T                   ret;
    STRU_WIRELESS_INFO_DISPLAY* pst_bbInfoAddr = (STRU_WIRELESS_INFO_DISPLAY*)&p;
    ;
    uint8_t gnd_sig, sky_sig;
    uint8_t ref_total_pack = 1;
    uint8_t bw             = 1;

    ret = HAL_BB_GetInfo(&pst_bbInfoAddr);
    if ((pst_bbInfoAddr == NULL)) {
        *len = 0;
        DLOG_Warning("failed %x", ret);
        return DATA_NORDY;
    }

    pstart    = buf;
    *pstart++ = 0;
    *pstart++ = 0;

    // get_sigQuality(&gnd_sig,&sky_sig);
    gnd_sig = GndSigQuality(pst_bbInfoAddr->errcnt1, pst_bbInfoAddr->snr_vlaue[1]);
    sky_sig = SkySigQuality(pst_bbInfoAddr->u8_rclock, pst_bbInfoAddr->sky_snr);

    *pstart++ = gnd_sig;
    *pstart++ = sky_sig;
    *pstart++ = pst_bbInfoAddr->agc_value[0];                                             // rssia
    *pstart++ = pst_bbInfoAddr->agc_value[1];                                             // rssib
    *pstart++ = pst_bbInfoAddr->sky_agc[0];                                               // sky rssia
    *pstart++ = pst_bbInfoAddr->sky_agc[1];                                               // sky rssib
    *pstart++ = 100 >= pst_bbInfoAddr->u8_rclock ? 100 - pst_bbInfoAddr->u8_rclock : 100; // sky error rate percent

    if (pst_bbInfoAddr->e_bandwidth == BW_20M) {
        bw = 2;
    }

    if (pst_bbInfoAddr->modulation_mode < 4) {
        ref_total_pack = pack_total[pst_bbInfoAddr->modulation_mode];
    } else {
        DLOG_Error("qam mode error");
    }

    *pstart++ = (pst_bbInfoAddr->ldpc_error * 100) / (bw * ref_total_pack); // grd error rate percent

    *len = pstart - buf;

    return DATA_RDY;
}

uint8_t get_sky_status_info(unsigned char* buf, int* len)
{
    unsigned char *             pstart, *p;
    HAL_RET_T                   ret;
    STRU_WIRELESS_INFO_DISPLAY* pst_bbInfoAddr = (STRU_WIRELESS_INFO_DISPLAY*)&p;
    uint8_t                     val;

    // DLOG_Warning("-->%x",pst_bbInfoAddr);
    ret = HAL_BB_GetInfo(&pst_bbInfoAddr);
    // DLOG_Warning("-->%x",pst_bbInfoAddr);
    if ((pst_bbInfoAddr == NULL)) {
        *len = 0;
        DLOG_Warning("failed %x,%x", ret, pst_bbInfoAddr);
        return DATA_NORDY;
    }

    pstart    = buf;
    *pstart++ = 0;
    *pstart++ = 0;

    val       = SkySigQuality(pst_bbInfoAddr->u8_rclock, pst_bbInfoAddr->snr_vlaue[1]); // get_sky_sigQuality();
    *pstart++ = val;

    *pstart++ = pst_bbInfoAddr->agc_value[0];                                             // rssia
    *pstart++ = pst_bbInfoAddr->agc_value[1];                                             // rssib
    *pstart++ = 100 >= pst_bbInfoAddr->u8_rclock ? 100 - pst_bbInfoAddr->u8_rclock : 100; // sky error rate
    *len      = pstart - buf;

    return DATA_RDY;
}

unsigned int data_check(char* buffer, int len)
{
    int          i;
    unsigned int sum = 0;
    for (i = 0; i < len; i++) {
        sum += (unsigned char)buffer[i];
        sum = sum & 0x0000FFFF;
    }

    return sum;
}

void print_msg(void* msg)
{
    uint8_t* pmsg = (uint8_t*)msg;
    uint16_t msg_len, i;

    msg_len = pmsg[7] << 8 | pmsg[6];
    for (i = 0; i < msg_len + 10; i++)
        DLOG_Warning("%02x", pmsg[i]);
}

uint8_t cmd_ack_handle(void* msg, uint8_t port_id)
{
    int      ret, len;
    int      i;
    char     buf[512];
    uint8_t  sky_v, grd_v;
    uint8_t* pmsg = (uint8_t*)msg;
    uint8_t  msg_id;

    uint32_t test_len = 336;

    msg_id = pmsg[2];
    buf[0] = 0xff;
    buf[1] = 0x5a;
    buf[2] = msg_id;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0x00;

    switch (msg_id) {
    // case CMD_VIDEO_BUF_DEEP:

    //     len = 11;
    //     len += 1;//data is ready len

    //     buf[6] = len;
    //     buf[7] = len >> 8;

    //     ret = get_vedio_deep((int *)(&buf[11]));
    //     get_vedio_deep1((int *)(&buf[16]));
    //     if(ret < 0)
    //         buf[10] = DATA_NORDY;
    //     else
    //         buf[10] = DATA_RDY;

    //     buf[15] = get_mcs();
    // 	buf[20] = get_bw();
    // 	buf[21] = get_taget_pwr();
    //     ret = data_check(&buf[10],len+1);

    //     buf[8] = (char)ret;
    //     buf[9] = (char)(ret >> 8);

    //     break;
    case CMD_VIDEO_BUF_DEEP:

        len = 9;

        len += 1; // data is ready len

        buf[6] = len;
        buf[7] = len >> 8;

        ret = get_vedio_deep((int*)(&buf[11]));
        get_vedio_deep1((int*)(&buf[16]));
        if (ret < 0)
            buf[10] = DATA_NORDY;
        else
            buf[10] = DATA_RDY;

        buf[15] = get_mcs();

        ret = data_check(&buf[10], 10);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        break;

    case CMD_GRD_MOD_STATUS:

        buf[10] = get_grd_status_info(buf + 11, &len);

        len += 1; // data is ready len

        buf[6] = len;
        buf[7] = len >> 8;

        ret = data_check(&buf[10], len);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        // send_to_host(buf,len + 10);
        break;

    case CMD_SKY_MOD_STATUS:

        buf[10] = get_sky_status_info(buf + 11, &len);

        len += 1; // data is ready len

        buf[6] = len;
        buf[7] = len >> 8;

        ret = data_check(&buf[10], len);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        break;

    case CMD_DBUG_INFO:

        len = 16; // data is ready len
        len += 1; // data is ready len

        buf[6] = len;
        buf[7] = len >> 8;

        buf[10] = DATA_RDY;

        ret = get_usb_recv_size0();

        buf[11] = (char)(ret >> 24);
        buf[12] = (char)(ret >> 16);
        buf[13] = (char)(ret >> 8);
        buf[14] = (char)ret;

        ret = get_usb_recv_size1();

        buf[15] = (char)(ret >> 24);
        buf[16] = (char)(ret >> 16);
        buf[17] = (char)(ret >> 8);
        buf[18] = (char)ret;

        // HAL_SRAM_GetReceivedDataSize((uint32_t *)(&buf[19]), (uint32_t *)(&buf[23]));

        ret = data_check(&buf[10], len);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        break;
    case CMD_GET_AUTOTEST_STATUS:

        len    = 1;
        buf[6] = len;
        buf[7] = 0;

        buf[10] = 0;
        ret     = data_check(&buf[10], len);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        break;
    case CMD_CTRL_HI3518_STATUS:

        len = 9;

        len += 1; // data is ready len

        buf[6] = len;
        buf[7] = len >> 8;

        ret = get_vedio_deep((int*)(&buf[11]));

        if (ret < 0)
            buf[10] = DATA_NORDY;
        else
            buf[10] = DATA_RDY;

        buf[15] = get_mcs();

        ret = data_check(&buf[10], 10);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        break;
    case CMD_CF_CTRL_READ:

        buf[6] = test_len;
        buf[7] = test_len >> 8;

        memset(&buf[10], 1, test_len);

        ret = data_check(&buf[10], test_len);

        buf[8] = (char)ret;
        buf[9] = (char)(ret >> 8);

        len = test_len;
        break;

    default:
        DLOG_Warning("undef cmd %d", msg_id);
        return 0;
    }

    len += 10;
    ret = HAL_USB_SendCtrl(buf, len, port_id);
    if (ret != HAL_OK) {
        DLOG_Error("failed %x", ret);
    }

    return 0;
}

uint8_t        usb_send_packet_start = 0;
static uint8_t port_id_save          = 0;
static int     last_state            = 0;
static int     g_len                 = 0;

uint8_t        uart2usb_send_start = 0;
static uint8_t uart2usb_port_id    = 0;
static int     uart2usb_state      = 0;
static int     uart2usb_len        = 0;
static int     usb_retry_cnt       = 0;
static int     uart_retry_cnt      = 0;

uint8_t        cf_protocol2usb_send_start = 0;
static uint8_t cf_protocol2usb_port_id    = 0;
static int     cf_protocol2usb_state      = 0;
static int     cf_protocol2usb_len        = 0;
static int     cf_protocol2usb_retry_cnt  = 0;

void usb_send_packet(void const* argument)
{

    uint16_t  sum_check, len;
    HAL_RET_T ret     = HAL_OK;
    uint8_t   port_id = 0;
    while (1) {
        if (usb_send_packet_start == 1) {
            port_id = port_id_save;
            if (last_state == 1) {
                ret = HAL_USB_SendCtrl(bypass_buf, g_len, port_id);
                usb_retry_cnt++;
                if (usb_retry_cnt == 10) {
                    last_state    = 0;
                    usb_retry_cnt = 0;
                }
                DLOG_Critical("Now it is Retry HAL_USB_SendCtrl %d", g_len);
            } else {

                len       = usb_bypass_read(bypass_buf + 10, USB_BYPASS_MAX_PLAYLOAD_LEN);
                sum_check = data_check(bypass_buf + 10, len);

                bypass_buf[0] = 0xff;
                bypass_buf[1] = 0x5a;
                bypass_buf[2] = CMD_READ_USB_BYPASS;
                bypass_buf[3] = 0x00;
                bypass_buf[4] = 0x00;
                bypass_buf[5] = 0x00;
                bypass_buf[6] = len;
                bypass_buf[7] = len >> 8;
                bypass_buf[8] = (char)sum_check;
                bypass_buf[9] = (char)(sum_check >> 8);
                if (len > 0) {
                    len += 10;
                    ret = HAL_USB_SendCtrl(bypass_buf, len, port_id);
                }
            }

            if (ret == HAL_OK) {
                last_state = 0;
            } else {

                if (!last_state) {
                    last_state = 1;
                    g_len      = len;
                }
                DLOG_Error("failed %x, last_state %d", ret, last_state);
            }
        }

        if (uart2usb_send_start == 1) {
            if (uart2usb_state == 1) {
                ret = HAL_USB_SendCtrl(bypass_uart_buf, uart2usb_len, uart2usb_port_id);
                DLOG_Critical("HAL_USB_SendCtrl Retry %d", uart2usb_len);
                uart_retry_cnt++;
                if (uart_retry_cnt == 4) {
                    uart2usb_state = 0;
                    uart_retry_cnt = 0;
                }
            } else {

                len       = bypass_read_uart2usb(bypass_uart_buf + 10, USB_BYPASS_MAX_PLAYLOAD_LEN);
                sum_check = data_check(bypass_uart_buf + 10, len);

                bypass_uart_buf[0] = 0xff;
                bypass_uart_buf[1] = 0x5a;
                bypass_uart_buf[2] = CMD_READ_UART5_BYPASS;
                bypass_uart_buf[3] = 0x00;
                bypass_uart_buf[4] = 0x00;
                bypass_uart_buf[5] = 0x00;
                bypass_uart_buf[6] = len;
                bypass_uart_buf[7] = len >> 8;
                bypass_uart_buf[8] = (char)sum_check;
                bypass_uart_buf[9] = (char)(sum_check >> 8);
                if (len > 0) {
                    len += 10;
                    ret = HAL_USB_SendCtrl(bypass_uart_buf, len, uart2usb_port_id);
                }
            }

            if (ret == HAL_OK) {
                uart2usb_state = 0;
            } else {
                if (!uart2usb_state) {
                    uart2usb_state = 1;
                    uart2usb_len   = len;
                }
                DLOG_Error("failed %x, uart2usb_len %d", ret, uart2usb_len);
            }
        }

        if (cf_protocol2usb_send_start == 1) {
            if (cf_protocol2usb_state == 1) {
                ret = HAL_USB_SendCtrl(bypass_cf_protocol_buf, cf_protocol2usb_len, cf_protocol2usb_port_id);
                DLOG_Critical("HAL_USB_SendCtrl Retry %d", cf_protocol2usb_len);
                cf_protocol2usb_retry_cnt++;
                if (cf_protocol2usb_retry_cnt == 4) {
                    cf_protocol2usb_state     = 0;
                    cf_protocol2usb_retry_cnt = 0;
                }
            } else {

                len       = gnd_cf_protocol_read2bbrx(bypass_cf_protocol_buf + 10, USB_BYPASS_MAX_PLAYLOAD_LEN);
                sum_check = data_check(bypass_cf_protocol_buf + 10, len);

                bypass_cf_protocol_buf[0] = 0xff;
                bypass_cf_protocol_buf[1] = 0x5a;
                bypass_cf_protocol_buf[2] = CMD_READ_CF_PROTOCOL;
                bypass_cf_protocol_buf[3] = 0x00;
                bypass_cf_protocol_buf[4] = 0x00;
                bypass_cf_protocol_buf[5] = 0x00;
                bypass_cf_protocol_buf[6] = len;
                bypass_cf_protocol_buf[7] = len >> 8;
                bypass_cf_protocol_buf[8] = (char)sum_check;
                bypass_cf_protocol_buf[9] = (char)(sum_check >> 8);
                if (len > 0) {
                    len += 10;
                    ret = HAL_USB_SendCtrl(bypass_cf_protocol_buf, len, cf_protocol2usb_port_id);
                }
            }

            if (ret == HAL_OK) {
                cf_protocol2usb_state = 0;
            } else {
                if (!cf_protocol2usb_state) {
                    cf_protocol2usb_state = 1;
                    cf_protocol2usb_len   = len;
                }
                DLOG_Error("failed %x, cf_protocol2usb_len %d", ret, cf_protocol2usb_len);
            }
        }

        HAL_Delay(11);
    }
}

uint8_t cmd_usb_bypass_read_handle(void* msg, uint8_t port_id)
{
    uint8_t* pmsg = (uint8_t*)msg;
    uint16_t msg_len, sum_check;
    uint8_t  msg_id;
    uint8_t  payload = 0;

    msg_id = pmsg[2];

    msg_len   = pmsg[7] << 8 | pmsg[6];
    sum_check = pmsg[9] << 8 | pmsg[8];

    if (msg_len)
        payload = pmsg[10];

    if (data_check(pmsg + 10, msg_len) != sum_check) {
        DLOG_Warning("check sum error");
        return 0;
    }

    if (!usb_send_packet_start && !msg_len && msg_id == CMD_READ_USB_BYPASS) {
        port_id_save          = port_id;
        usb_send_packet_start = 1;
        DLOG_Warning("usb send start...");
    } else if (usb_send_packet_start == 1 && msg_id == CMD_READ_USB_BYPASS && payload == 0x90) {
        usb_send_packet_start = 0;
        DLOG_Warning("usb send stop...");
    }
}

static int is_pluged = 0;
uint8_t    mtp_rev_stream_video(void* msg, uint8_t port_id)
{
    uint16_t len       = 0;
    uint16_t sum_check = 0;
    uint16_t cal_check = 0;
    uint8_t* pmsg      = (uint8_t*)msg;
    uint8_t  payload[512];
    uint16_t payload_len = 0;

    payload_len = ((pmsg[7] & 0x0FF) << 8) | (pmsg[6] & 0x0FF);
    if (payload_len <= 10 || payload_len > 512)
        return 0;
    sum_check = ((pmsg[9] & 0x0FF) << 8) | (pmsg[8] & 0x0FF);
    cal_check = (uint16_t)data_check(pmsg + 10, payload_len);

    if (cal_check != sum_check) {
        DLOG_Critical("check sum error %08x, calc %08x !", sum_check, cal_check);

        return 0;
    }

    if (is_pluged == 0) {
        is_pluged = 1;
        HAL_SRAM_EnableSkyBypassVideo(1);
    }

    HAL_SRAM_TransferBypassVideoStream(HAL_SRAM_VIDEO_CHANNEL_1, pmsg + 10, payload_len);

    return payload_len;
}

uint8_t cmd_usb_bypass_write_handle(void* msg, uint8_t port_id)
{
    uint8_t* pmsg = (uint8_t*)msg;
    uint16_t msg_len;
    uint8_t  msg_id;

    // print_msg(msg);
    msg_id = pmsg[2];
    if (msg_id != CMD_WRITE_USB_BYPASS) {
        DLOG_Warning("msg id error %d", msg_id);
        return 0;
    }

    msg_len = pmsg[7] << 8 | pmsg[6];
    /*sum_check = pmsg[9] << 8 | pmsg[8];
    if(data_check(pmsg+10,msg_len) != sum_check)
    {
        DLOG_Warning("check sum error");
        return 0;
    }*/

    usb_bypass_write(pmsg + 10, msg_len);

    return msg_len;
}
