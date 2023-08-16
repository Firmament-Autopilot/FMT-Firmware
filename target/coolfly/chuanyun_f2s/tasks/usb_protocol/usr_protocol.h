#ifndef __USR_PROTOCOL__
#define __USR_PROTOCOL__

#ifdef __cplusplus
extern "C"
{
#endif

extern uint8_t usb_send_packet_start;


#define CMD_VIDEO_BUF_DEEP 0x81
#define CMD_GRD_MOD_STATUS 0x82
#define CMD_SKY_MOD_STATUS 0x83
#define CMD_WRITE_USB_BYPASS 0x84
#define CMD_READ_USB_BYPASS 0x85
#define CMD_WRITE_UART5_BYPASS 0x86
#define CMD_READ_UART5_BYPASS 0x87
#define CMD_DBUG_INFO 0x88
#define CMD_GET_AUTOTEST_STATUS  0x89
#define CMD_MTP_VIDEO_STREAM     0x90

#define CMD_CTRL_HI3518_STATUS   0x91
#define CMD_READ_CF_PROTOCOL   0x93
#define CMD_WRITE_CF_PROTOCOL  0x94

#define CMD_CF_CTRL_READ        0x95
#define CMD_CF_CTRL_WRITE       0x96

#define CMD_MANUL_RC_PATTEN		0x97
#define CMD_MANUL_SET_BW		0x98

uint8_t cmd_ack_handle(void *msg, uint8_t port_id);

void usb_send_packet(void const *argument);

uint8_t cmd_usb_bypass_read_handle(void *msg, uint8_t port_id);

uint8_t cmd_usb_bypass_write_handle(void *msg, uint8_t port_id);

uint8_t cmd_usb_bypass_read_uart5_handle(void *msg, uint8_t port_id);

uint8_t cmd_usb_bypass_write_uart5_handle(void *msg, uint8_t port_id);

unsigned int data_check(char *buffer,int len);

void print_msg(void *msg);

uint8_t mtp_rev_stream_video(void *msg, uint8_t port_id);

uint8_t cmd_usb_cf_protocol_read_handle(void *msg, uint8_t port_id);
uint8_t cmd_usb_cf_protocol_write_handle(void *msg, uint8_t port_id);

uint8_t cmd_usb_cf_ctrl_write_handle(void *msg, uint8_t port_id);


uint8_t get_grd_status_info(unsigned char *buf, int *len);

uint8_t get_sky_status_info(unsigned char *buf, int *len);

// uint8_t set_rc_patten_by_manul(void *msg, uint8_t port_id);

// uint8_t set_bw_by_manul(void *msg, uint8_t port_id);

	


#ifdef __cplusplus
}
#endif

#endif

