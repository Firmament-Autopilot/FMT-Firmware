#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>


/* Private define ------------------------------------------------------------*/

#define UART0_BASE                      (0x40500000)
#define UART1_BASE                      (0x40510000)
#define UART2_BASE                      (0x40520000)
#define UART3_BASE                      (0x40530000)
#define UART4_BASE                      (0x40540000)
#define UART5_BASE                      (0x40550000)
#define UART6_BASE                      (0x40560000)
#define UART7_BASE                      (0x40570000)
#define UART8_BASE                      (0x40580000)
#define UART9_BASE                      (0xA0000000)
#define UART10_BASE                     (0xA0060000) 


#define UART_FCR_ENABLE_FIFO            (0x01)
#define UART_FCR_CLEAR_RCVR             (0x02)
#define UART_FCR_CLEAR_XMIT             (0x04)
#define UART_FCR_TRIGGER_14             (0xc0)
#define UART_LCR_WLEN8                  (0x03)
#define UART_LCR_STOP                   (0x04)
#define UART_LCR_PARITY                 (0x08)
#define UART_LCR_DLAB                   (0x80)
#define UART_LSR_THRE                   (0x20)
#define UART_LSR_TEMT                   (0x40)
#define UART_LSR_DATAREADY              (0x01)
#define UART_IIR_RECEIVEDATA            (0x04)
#define UART_IIR_DATATIMEOUT            (0x0C)
#define UART_IIR_THR_EMPTY              (0x02)
#define UART_IIR_INTID_BUSY             (0x07)
#define UART_LSR_DR                     (0x01)
#define UART_DLH_IER_TX_INT             (0x02)
#define UART_DLH_IER_RX_INT             (0x01)

#define UART_TOTAL_CHANNEL              (11)
#define UART_TFL_MAX                    (16)
#define UART_RX_FIFOLEN                 (14)
#define UART_DEFAULT_TIMEOUTMS          (20)

//user CallBack for uart data receive.
typedef uint32_t (*UART_RxHandler)(uint8_t *pu8_rxBuf, uint8_t u8_len);



typedef struct 
{  
  uint16_t u16_uartSendBuffLen;  
  uint16_t u16_uartSendBuffLentmp;
  const char *ps8_uartSendBuff;
  uint32_t txLenLast;
}uart_tx;

typedef struct 
{
  uint32_t u32_buffCurrentPosition;
  uint16_t u16_uartSendBuffLen;  
  uint16_t u16_uartSendBuffLentmp;
}uart_tx_ringbuff;

typedef struct 
{
  unsigned int RBR_THR_DLL;
  unsigned int DLH_IER;
  unsigned int IIR_FCR;
  unsigned int LCR;
  unsigned int MCR;
  unsigned int LSR;
  unsigned int MSR;
  unsigned int SCR;
  unsigned int LPDLL;
  unsigned int LPDLH;
  unsigned int reserv[2];
  unsigned int SRBR_STHR[16];
  unsigned int FAR;
  unsigned int TFR;
  unsigned int RFW;
  unsigned int USR;
  unsigned int TFL;
  unsigned int RFL;
  unsigned int SRR;
  unsigned int SRTS;
  unsigned int SBCR;
  unsigned int SDMAM;
  unsigned int SFE;
  unsigned int SRT;
  unsigned int STET;
  unsigned int HTX;
  unsigned int DMASA;
  unsigned int reserv1[14];
  unsigned int CPR;
  unsigned int UCV;
  unsigned int CTR;
} uart_type;


void uart_init(unsigned char index, unsigned int baud_rate);
void uart_set_baudrate(unsigned char index, unsigned int baud_rate);
void sbus_init(unsigned char index, unsigned int baud_rate);
void uart_putc(unsigned char index, char c);
void uart_putFifo(unsigned char index);
void uart_puts(unsigned char index, const char *s);
char uart_getc(unsigned char index);
void uart_putdata(unsigned char index,  const char *s, unsigned short dataLen);
void uart_aes_off(void);
void uart_aes_off_len(uint8_t len);
uint8_t uart_dummy_cnt(void);

uint8_t uart_checkoutFifoStatus(unsigned char index);
//int32_t Uart10_WaitTillIdle(unsigned char index, uint16_t datalen);
/**
* @brief  WaitTillIdle.  
* @param  index           uart channel, 0 ~ 10.
* @retval None.
* @note   None.
*/
int32_t Uart_WaitTillIdle(unsigned char index, uint32_t timeOut);

/**
* @brief  uart interrupt servive function.just handled data reception.  
* @param  u32_vectorNum           Interrupt number.
* @retval None.
* @note   None.
*/
void UART_IntrSrvc(uint32_t u32_vectorNum);

/**
* @brief  register user function for uart recevie data.called in interrupt
*         service function.
* @param  u8_uartCh           uart channel, 0 ~ 10.
* @param  userHandle          user function for uart recevie data.
* @retval 
*         -1                  register user function failed.
*         0                   register user function sucessed.
* @note   None.
*/
int32_t UART_RegisterUserRxHandler(uint8_t u8_uartCh, UART_RxHandler userHandle);

/**
* @brief  unregister user function for uart recevie data.
* @param  u8_uartCh           uart channel, 0 ~ 10.
* @retval 
*         -1                  unregister user function failed.
*         0                   unregister user function sucessed.
* @note   None.
*/
int32_t UART_UnRegisterUserRxHandler(uint8_t u8_uartCh);


#endif
