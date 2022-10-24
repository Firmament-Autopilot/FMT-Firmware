#ifndef BB_UARTCOM_H
#define BB_UARTCOM_H

#include "sys_event.h"
#include "bb_types.h"

#define BBCOM_UART_INDEX                    10
#define BBCOM_UART_BAUDRATE                 256000
#define BB_UART_TX_FIFO_BPSK_SIZE           32 //bpsk 1/2
#define BB_UART_TX_FIFO_QPSK_SIZE           208 //qpsk 2/3
#define BB_UART_TX_FIFO_QPSK1_2_SIZE        128
#define BB_UART_TX_FIFO_BPSK2_3_SIZE        64

#define BB_SPI_TX_FIFO_SIZE                 64
#define BB_SPI_INFO_SIZE_MAX                8

#define BBCOM_RX_BUF_SIZE                   (2048)
#define BBCOM_TX_FIFO_SIZE                  (2048)

#define BBCOM_SESSION_DATA_HEADER_SIZE      6


typedef enum
{
    BB_COM_RX_HEADER = 0,
    BB_COM_RX_SESSION_INFO,
    BB_COM_RX_DATALENGTH,
    BB_COM_RX_HEADER_CHECKSUM,
    BB_COM_RX_DATABUFFER,
    BB_COM_RX_CHECKSUM,
} ENUM_BBComRxState;


typedef struct
{
    volatile uint8_t    u8_magic[3];
    volatile uint8_t    u8_dataType;
    volatile uint8_t    u8_sessionNum;
    volatile uint16_t   u16_dataLen;
    volatile uint8_t    u8_headerCheckSum;
    volatile uint8_t    u8_userDataCheckSum;
    volatile uint8_t    u8_userData[1];
} STRU_BBComSessionData;


typedef union
{
    volatile uint8_t    u8_info;

    struct
    {
        volatile uint8_t    special:4;
        volatile uint8_t    dataType:1;
        volatile uint8_t    sessionNum:3;
    } b;
} STRU_BBComSessionDataInfo;


typedef struct
{
    volatile uint16_t in_use;
    volatile uint16_t rx_buf_wr_pos;
    volatile uint16_t rx_buf_rd_pos;
    volatile uint16_t cpu_id;
} STRU_BBComSessionRxBufferHeader;

typedef struct
{
    STRU_BBComSessionRxBufferHeader header      __attribute__ ((aligned (4)));
    volatile uint8_t data[1]                    __attribute__ ((aligned (4)));
} STRU_BBComSessionRxBuffer;

typedef struct
{
    STRU_BBComSessionRxBuffer*  rx_buf;
    uint32_t data_max_size;
    ENUM_BB_COM_SESSION_PRIORITY    e_sessionPriority;
    ENUM_BB_COM_SESSION_DATA_TYPE   e_sessionDataType;
} STRU_BBComSession;


typedef struct
{
    volatile uint32_t   tx_buff_max_size;
    volatile uint32_t   tx_buf_wr_pos;
    volatile uint32_t   tx_buf_rd_pos;
    uint32_t            reserved;
} STRU_BB_ComTxQueueHeader;

typedef struct
{
    STRU_BB_ComTxQueueHeader        tx_queue_header __attribute__ ((aligned (4)));
    volatile uint8_t                tx_data[1]      __attribute__ ((aligned (4)));
} STRU_BBComTxQueue;


typedef struct
{
    uint8_t          tx_fifo_data[BBCOM_TX_FIFO_SIZE];
    uint16_t         tx_fifo_rd_pos;
    uint16_t         tx_fifo_wr_pos;
} STRU_BBComTxFIFO;


typedef struct
{
    uint8_t                         find_header;
    uint8_t                         receiving_data;
    uint8_t                         data_length_index;
    uint8_t                         header_buf_index;
    uint8_t                         header_buf[BBCOM_SESSION_DATA_HEADER_SIZE];
    uint8_t                         data_sequence_num[BB_COM_SESSION_PRIORITY_MAX];
    uint8_t                         rx_state;
    uint16_t                        data_buf_index;
    uint16_t                        data_length;
    ENUM_BB_COM_SESSION_ID          session_id;
    ENUM_BB_COM_SESSION_PRIORITY    session_priority;
    ENUM_BB_COM_SESSION_DATA_TYPE   session_data_type;
} STRU_BBComRxFIFOHeader;


typedef struct
{
    STRU_BBComRxFIFOHeader          rx_fifo_header;
    uint8_t                         rx_data_buf[BBCOM_RX_BUF_SIZE + 1];
} STRU_BBComRxFIFO;


typedef union
{
    uint8_t     u8_headByte;

    struct
    {
        uint8_t     user_data_valid:1;          //bit0
        uint8_t     lock_state:1;               //bit1
        uint8_t     bb_data_size:4;             //bit2~6
        uint8_t     vt_match  :1;               //bit7
        uint8_t     flag_searchingSupport:1;    //bit8
    } b;
} UNION_BBSPIComHeadByte;



void BB_ComInit(BBCallBack func,uint8_t aes_off_flag);
void BB_ComRemoteSessionInit(void);
uint8_t BB_ComRegisterSession(ENUM_BB_COM_SESSION_ID session_id,
                             ENUM_BB_COM_SESSION_PRIORITY session_priority,
                             ENUM_BB_COM_SESSION_DATA_TYPE session_dataType);
void BB_ComUnRegisterSession(ENUM_BB_COM_SESSION_ID session_id);
uint8_t BB_ComSendMsg(ENUM_BB_COM_SESSION_ID session_id, uint8_t* data_buf, uint16_t length);
uint32_t BB_ComReceiveMsg(ENUM_BB_COM_SESSION_ID session_id, uint8_t* data_buf, uint32_t length_max);
uint8_t get_session_eventid(uint8_t id, uint32_t *pu32_rcv_event);
uint32_t BB_ComGetTXQueueFreeLength(STRU_BBComTxQueue *pst_txQueue);
uint16_t BB_ComGetMsgFromTXQueue(ENUM_BB_COM_SESSION_PRIORITY session_priority);
void BB_ComFlushTXQueue(ENUM_BB_COM_SESSION_PRIORITY session_priority, ENUM_BB_COM_TYPE bb_comType);
uint32_t BB_ComGetTxQueueCurrentLength(STRU_BBComTxQueue *pst_txQueue);
void BB_ComCycleMsgProcess(void);
void BB_ComCycleSendMsg(ENUM_BB_COM_TYPE e_bbComType,
                        uint8_t spi_info_size,
                        uint8_t *spi_info);
uint32_t BB_ComPacketDataAnalyze(uint8_t *u8_uartRxBuf, uint8_t u8_uartRxLen, STRU_BBComRxFIFO *pstBBComRxFIFO);
uint32_t BB_UARTComRecvDataHandler(uint8_t *u8_uartRxBuf, uint8_t u8_uartRxLen);
uint16_t BB_UARTComGetBBFIFOGap(void);
uint32_t BB_UART_GetTxFifoMaxSize(ENUM_BB_MODE e_bb_mode);
uint32_t BB_UARTComRecvDataHandler(uint8_t *u8_uartRxBuf, uint8_t u8_uartRxLen);
uint32_t BB_SpiDataTransRcv(void);
uint32_t BB_SPIComRecvData(void);
void BB_ComClearResource(void);
uint8_t BB_SpiChkDataTransChValid(void);
int BB_SpiGrdDataTransChProc(void);
uint32_t BB_ComGetFreeLength(ENUM_BB_COM_SESSION_ID session_id);
void BB_ComClearTxbuffer(ENUM_BB_COM_SESSION_ID session_id);
void session_cnt_debug_print(void);
void BB_SetAesOffUartMaxLen(uint8_t max_len);
uint8_t BB_GetUartDummyCnt(void);


#endif
