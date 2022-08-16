#include <stdint.h>
#include <string.h>
#include "ar8020.h"
#include "bb_uart_com.h"
#include "debuglog.h"
#include "serial.h"
#include "interrupt.h"
#include "memory_config.h"
#include "lock.h"
#include "bb_ctrl_internal.h"
#include "cpu_info.h"

extern uint32_t SysTicks_GetTickCount(void);

static uint8_t header[] = {0xFF, 0x5A, 0x0F};
static STRU_BBComSession g_BBComSessionArray[BB_COM_SESSION_MAX] = {0};
static uint8_t g_BBUARTComSession0RxBuffer[512] = {0};
static uint8_t g_BBUARTComSession0TxBuffer[512] = {0};
static STRU_BBComTxQueue *g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_MAX+1]; //one use for session0
static STRU_BBComRxFIFO     g_BBComRxFIFO;
static STRU_BBComTxFIFO     g_BBComTxFIFO;
static BBCallBack BB_JudgeLockStatus = NULL;
static uint32_t session_cnt_rx[BB_COM_SESSION_SPI];
static uint32_t session_cnt_tx[BB_COM_SESSION_SPI];
static uint32_t session_event_cnt[BB_COM_SESSION_SPI];
#define DATA_CHECK_SUM_SIZE (2)

void session_cnt_debug_print(void)
{
    int i;
    //DLOG_Error("event %d",session_event_cnt);
    for(i=0;i<BB_COM_SESSION_SPI;i++)
        DLOG_Error("s%d ecnt %ld tx %ld rx %ld",i,session_event_cnt[i],session_cnt_tx[i],session_cnt_rx[i]);
}
static void BB_ComLockAccquire(void)
{
    lock_type * lock_p = (lock_type*)SRAM_MODULE_LOCK_BB_UART_MUTEX_FLAG;
    Lock(lock_p);
}

static void BB_ComLockRelease(void)
{
    lock_type * lock_p = (lock_type*)SRAM_MODULE_LOCK_BB_UART_MUTEX_FLAG;
    UnLock(lock_p);
}

uint8_t get_session_eventid(uint8_t id, uint32_t *pu32_rcv_event)
{
    uint8_t ret = 0;
    uint32_t u32_rcv_event;

    /*if ( id == 0 )
    {
        u32_rcv_event = SYS_EVENT_ID_UART_DATA_RCV_SESSION0;
        ret = 1;
    }
    else */if ( id == 1 )
    {
        u32_rcv_event = SYS_EVENT_ID_UART_DATA_RCV_SESSION1;
        ret = 1;
    }
    else if ( id == 2)
    {
        u32_rcv_event = SYS_EVENT_ID_UART_DATA_RCV_SESSION2;
        ret = 1;
    }
    else if ( id == 3)
    {
        u32_rcv_event = SYS_EVENT_ID_UART_DATA_RCV_SESSION3;
        ret = 1;
    }
    else if( id == 4)
    {
        u32_rcv_event = SYS_EVENT_ID_UART_DATA_RCV_SESSION4;
        ret = 1;        
    }

    if (ret && pu32_rcv_event )
    {
        *pu32_rcv_event = u32_rcv_event;
    }

    return ret;
}


static void BB_ComWriteSessionRxBuffer(STRU_BBComRxFIFO *pstBBComRxFIFO)
{
    ENUM_BB_COM_SESSION_ID      session_id = pstBBComRxFIFO->rx_fifo_header.session_id;

    if (g_BBComSessionArray[session_id].rx_buf->header.in_use == 1)
    {
        uint32_t wr_pos = g_BBComSessionArray[session_id].rx_buf->header.rx_buf_wr_pos;
        uint32_t rd_pos = g_BBComSessionArray[session_id].rx_buf->header.rx_buf_rd_pos;
        uint32_t tail_pos = g_BBComSessionArray[session_id].data_max_size;

        uint32_t cnt = 0;
        do
        {
            g_BBComSessionArray[session_id].rx_buf->data[wr_pos] = pstBBComRxFIFO->rx_data_buf[cnt];
            wr_pos++;
            cnt++;

            if (wr_pos >= tail_pos)
            {
                wr_pos = 0;
            }
        } while ((wr_pos != rd_pos) && (cnt < (pstBBComRxFIFO->rx_fifo_header.data_buf_index - DATA_CHECK_SUM_SIZE)));

        if (wr_pos == rd_pos)
        {
            DLOG_Warning("FIFO is full!");
        }

        g_BBComSessionArray[session_id].rx_buf->header.rx_buf_wr_pos = wr_pos;

        //notify the session
        uint32_t u32_rcv_event;
        if ( get_session_eventid(session_id, &u32_rcv_event) )
        {
            SYS_EVENT_NotifyInterCore(u32_rcv_event, NULL);
            session_event_cnt[session_id] += 1;
        }
    }
}



uint8_t BB_ComFindHeader(uint8_t u8_data, STRU_BBComRxFIFO *pstBBComRxFIFO)
{
    uint16_t                    check_sum = 0;
    uint8_t                     i;
    STRU_BBComSessionDataInfo   un_session_data_info;
    uint8_t                     ret_value = 0;
    STRU_BBComRxFIFOHeader     *rx_header = &(pstBBComRxFIFO->rx_fifo_header);

    switch (rx_header->rx_state)
    {
    case BB_COM_RX_HEADER:
        if (u8_data == header[0])    // Reset flag
        {
            rx_header->header_buf_index = 0;
            rx_header->header_buf[rx_header->header_buf_index++] = u8_data;
        }
        else if (rx_header->header_buf_index < sizeof(header))    // Get header
        {
            rx_header->header_buf[rx_header->header_buf_index++] = u8_data;

            if ((rx_header->header_buf_index == sizeof(header))&&
                 (header[0] == rx_header->header_buf[0])&&
                 (header[1] == rx_header->header_buf[1])&&
                 (header[2] == (rx_header->header_buf[2]&header[2])))
            {
                rx_header->rx_state = BB_COM_RX_DATALENGTH;

                rx_header->data_length_index = 0;
            }
        }

        break;

    case BB_COM_RX_DATALENGTH:
        rx_header->header_buf[rx_header->header_buf_index++] = u8_data;

        rx_header->data_length_index++;
        if (rx_header->data_length_index >= sizeof(uint16_t))
        {
            rx_header->data_length_index = 0;

            rx_header->rx_state = BB_COM_RX_HEADER_CHECKSUM;
        }

        break;

    case BB_COM_RX_HEADER_CHECKSUM:

        check_sum = 0;
        for (i = 0; i < rx_header->header_buf_index; i++)
        {
            check_sum += rx_header->header_buf[i];
        }
        if ( (check_sum & 0xff)== u8_data)
        {
            un_session_data_info.u8_info   = rx_header->header_buf[2];

            rx_header->session_id = un_session_data_info.b.sessionNum;
            rx_header->session_data_type = un_session_data_info.b.dataType;

            rx_header->data_length = (rx_header->header_buf[4] << 8) + rx_header->header_buf[3];

            if (rx_header->data_length <= BBCOM_RX_BUF_SIZE)
            {
                ret_value = 1;
            }
        }

        rx_header->rx_state = BB_COM_RX_HEADER;
        rx_header->header_buf_index = 0;

        break;

    default:
        rx_header->rx_state = BB_COM_RX_HEADER;
        rx_header->header_buf_index = 0;

        break;

    }

    return ret_value;
}


uint32_t BB_ComPacketDataAnalyze(uint8_t *u8_uartRxBuf, uint8_t u8_uartRxLen, STRU_BBComRxFIFO *pstBBComRxFIFO)
{
    uint16_t                    i = 0;
    uint16_t                    j = 0;
    uint8_t                     chData = '\0';
    uint16_t                    check_sum = 0;
    STRU_BBComRxFIFOHeader     *rx_header = &(pstBBComRxFIFO->rx_fifo_header);

    while (u8_uartRxLen)
    {
        chData = *(u8_uartRxBuf + i);

        i++;
        u8_uartRxLen--;

        rx_header->find_header = BB_ComFindHeader(chData, pstBBComRxFIFO);

        if (1 == rx_header->find_header)
        {
            if (rx_header->data_length > BBCOM_RX_BUF_SIZE)
            {
               // DLOG_Error("len should not exceed: %d", BBCOM_RX_BUF_SIZE);

                continue;
            }

            if (0 == rx_header->receiving_data)
            {
                /* begin to receive data */
                rx_header->receiving_data  = 1;

                rx_header->data_buf_index  = 0;
            }
            else
            {
                /* exception */
                //DLOG_Error("find header while receiving user data");

                pstBBComRxFIFO->rx_data_buf[rx_header->data_buf_index++] = chData;

                if (rx_header->session_data_type == BB_COM_SESSION_DATA_RT)
                {
                    rx_header->data_buf_index -= BBCOM_SESSION_DATA_HEADER_SIZE;

                    /* process data */
                    BB_ComWriteSessionRxBuffer(pstBBComRxFIFO);

                    rx_header->receiving_data = 0;
                }
                else
                {
                    /* abandon data */
                }

                rx_header->data_buf_index  = 0;
            }
        }
        else
        {
            if (1 == rx_header->receiving_data)
            {
                /* go on receiving data */
                pstBBComRxFIFO->rx_data_buf[rx_header->data_buf_index++] = chData;

                /* user data all received */
                if (rx_header->data_buf_index == (rx_header->data_length + DATA_CHECK_SUM_SIZE)) //2: checksum bytes
                {
                    if (rx_header->session_data_type == BB_COM_SESSION_DATA_RT)
                    {
                        /* process data */
                        BB_ComWriteSessionRxBuffer(pstBBComRxFIFO);
                    }
                    else
                    {

                        check_sum = 0;
                        /* check sum */
                        for (j = 0; j < rx_header->data_length; j++)
                        {
                            check_sum += pstBBComRxFIFO->rx_data_buf[j];
                        }


                        if ( ((check_sum & 0xff) == pstBBComRxFIFO->rx_data_buf[rx_header->data_length]) && 
                             (( (check_sum >>8) & 0xff)== pstBBComRxFIFO->rx_data_buf[rx_header->data_length + 1]))
                        {
                            session_cnt_rx[pstBBComRxFIFO->rx_fifo_header.session_id] += rx_header->data_length;
                            BB_ComWriteSessionRxBuffer(pstBBComRxFIFO);
                        }
                        else
                        {
                            DLOG_Info("checksum fail");
                        }
                    }

                    rx_header->data_buf_index = 0;
                    rx_header->receiving_data = 0;
                }
            }
        }
    }

    return 0;
}


void BB_ComSessionInit(ENUM_BB_COM_SESSION_ID session_id,
                     ENUM_CPU_ID cpu_id,
                     uint16_t in_use,
                     ENUM_BB_COM_SESSION_PRIORITY session_priority,
                     ENUM_BB_COM_SESSION_DATA_TYPE session_dataType)
{
    static STRU_BBComSessionRxBuffer *ptr_BBSessionRxBuffer[BB_COM_SESSION_MAX] = {
                                (STRU_BBComSessionRxBuffer *)g_BBUARTComSession0RxBuffer,
                                (STRU_BBComSessionRxBuffer *)SRAM_BB_UART_COM_SESSION_1_SHARE_MEMORY_ST_ADDR,
                                (STRU_BBComSessionRxBuffer *)SRAM_BB_UART_COM_SESSION_2_SHARE_MEMORY_ST_ADDR,
                                (STRU_BBComSessionRxBuffer *)SRAM_BB_UART_COM_SESSION_3_SHARE_MEMORY_ST_ADDR,
                                (STRU_BBComSessionRxBuffer *)SRAM_BB_UART_COM_SESSION_4_SHARE_MEMORY_ST_ADDR
                                };
    static uint32_t session_buff_size[BB_COM_SESSION_MAX] = {
                                sizeof(g_BBUARTComSession0RxBuffer),
                                SRAM_BB_UART_COM_SESSION_1_SHARE_MEMORY_SIZE,
                                SRAM_BB_UART_COM_SESSION_2_SHARE_MEMORY_SIZE,
                                SRAM_BB_UART_COM_SESSION_3_SHARE_MEMORY_SIZE,
                                SRAM_BB_UART_COM_SESSION_4_SHARE_MEMORY_SIZE
                                };

    g_BBComSessionArray[session_id].rx_buf = ptr_BBSessionRxBuffer[session_id];
    g_BBComSessionArray[session_id].rx_buf->header.in_use = in_use;
    g_BBComSessionArray[session_id].rx_buf->header.rx_buf_wr_pos = 0;
    g_BBComSessionArray[session_id].rx_buf->header.rx_buf_rd_pos = 0;
    g_BBComSessionArray[session_id].rx_buf->header.cpu_id = cpu_id;
    g_BBComSessionArray[session_id].data_max_size = session_buff_size[session_id] - sizeof(STRU_BBComSessionRxBufferHeader);
    g_BBComSessionArray[session_id].e_sessionPriority = session_priority;
    g_BBComSessionArray[session_id].e_sessionDataType = session_dataType;
}


/*
 * call by cpu0 when system start
*/
void BB_ComClearResource(void)
{
    *((lock_type*)(SRAM_MODULE_LOCK_BB_UART_MUTEX_FLAG)) = UNLOCK_STATE;
    *((volatile uint32_t*)(SRAM_MODULE_LOCK_BB_UART_INIT_FLAG)) = 0;

    memset((void *)SRAM_BB_UART_COM_SESSION_1_SHARE_MEMORY_ST_ADDR, 0, sizeof(STRU_BBComSessionRxBuffer));
    memset((void *)SRAM_BB_UART_COM_SESSION_2_SHARE_MEMORY_ST_ADDR, 0, sizeof(STRU_BBComSessionRxBuffer));
    memset((void *)SRAM_BB_UART_COM_SESSION_3_SHARE_MEMORY_ST_ADDR, 0, sizeof(STRU_BBComSessionRxBuffer));
    memset((void *)SRAM_BB_UART_COM_SESSION_4_SHARE_MEMORY_ST_ADDR, 0, sizeof(STRU_BBComSessionRxBuffer));
}


void BB_ComInit(BBCallBack func,uint8_t aes_off_flag)
{
    ENUM_BB_COM_SESSION_ID   session_id;
    uart_init(BBCOM_UART_INDEX, BBCOM_UART_BAUDRATE);
    if(aes_off_flag){
        uart_aes_off();
    }
    reg_IrqHandle(VIDEO_UART10_INTR_VECTOR_NUM, UART_IntrSrvc, NULL);
    UART_RegisterUserRxHandler(BBCOM_UART_INDEX, BB_UARTComRecvDataHandler);
    NVIC_SetPriority(VIDEO_UART10_INTR_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_VIDEO_UART10,0));
    NVIC_EnableIRQ(VIDEO_UART10_INTR_VECTOR_NUM);
    BB_JudgeLockStatus = func;

    // Session 0 is registered by default BB_COM_SESSION_PRIORITY_MAX
    BB_ComSessionInit(BB_COM_SESSION_0,
                      ENUM_CPU2_ID,
                      1,
                      
                      BB_COM_SESSION_PRIORITY_MAX,
                      BB_COM_SESSION_DATA_NORMAL);

    // Sessions 1-4 are registered dynamicly
    for (session_id = BB_COM_SESSION_1; session_id < BB_COM_SESSION_MAX; session_id++)
    {
        BB_ComSessionInit(session_id,
                          ENUM_CPU0_ID,
                          0,
                          BB_COM_SESSION_PRIORITY_HIGH,
                          BB_COM_SESSION_DATA_NORMAL);
    }

    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_HIGH]
                = (STRU_BBComTxQueue *)SRAM_BB_COM_TX_HIGH_PRIO_SHARE_MEMORY_ST_ADDR;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_HIGH]->tx_queue_header.tx_buf_rd_pos
                = 0;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_HIGH]->tx_queue_header.tx_buf_wr_pos
                = 0;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_HIGH]->tx_queue_header.tx_buff_max_size
                = SRAM_BB_COM_TX_HIGH_PRIO_SHARE_MEMORY_SIZE - sizeof(STRU_BB_ComTxQueueHeader);

    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_LOW]
                = (STRU_BBComTxQueue *)SRAM_BB_COM_TX_LOW_PRIO_SHARE_MEMORY_ST_ADDR;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_LOW]->tx_queue_header.tx_buf_rd_pos
                = 0;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_LOW]->tx_queue_header.tx_buf_wr_pos
                = 0;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_LOW]->tx_queue_header.tx_buff_max_size
                = SRAM_BB_COM_TX_LOW_PRIO_SHARE_MEMORY_SIZE - sizeof(STRU_BB_ComTxQueueHeader);

    //use BB_COM_SESSION_PRIORITY_MAX for the session0
    
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_MAX] = (STRU_BBComTxQueue *)g_BBUARTComSession0TxBuffer;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_MAX]->tx_queue_header.tx_buf_rd_pos = 0;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_MAX]->tx_queue_header.tx_buf_wr_pos = 0;

    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_MAX]->tx_queue_header.tx_buff_max_size = sizeof(g_BBUARTComSession0TxBuffer) - sizeof(STRU_BB_ComTxQueueHeader);
    g_BBComTxFIFO.tx_fifo_rd_pos       = 0;
    g_BBComTxFIFO.tx_fifo_wr_pos       = 0;

    memset((void *)&g_BBComRxFIFO.rx_fifo_header, 0, sizeof(STRU_BBComRxFIFOHeader) );
    memset((void *)(SRAM_SPI_DATA_TRANS_ST_ADDR), 0, SRAM_SPI_DATA_TRANS_SIZE );

    *((volatile uint32_t*)(SRAM_MODULE_LOCK_BB_UART_INIT_FLAG)) = 0x10A5A501;
}

void BB_ComRemoteSessionInit(void)
{
    // Wait for the init finish
    while (*((volatile uint32_t*)(SRAM_MODULE_LOCK_BB_UART_INIT_FLAG)) != 0x10A5A501) { }

    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_HIGH]
            = (STRU_BBComTxQueue *)SRAM_BB_COM_TX_HIGH_PRIO_SHARE_MEMORY_ST_ADDR;
    g_pstBBComTxQueue[BB_COM_SESSION_PRIORITY_LOW]
            = (STRU_BBComTxQueue *)SRAM_BB_COM_TX_LOW_PRIO_SHARE_MEMORY_ST_ADDR;
}

uint8_t BB_ComRegisterSession(ENUM_BB_COM_SESSION_ID session_id,
                             ENUM_BB_COM_SESSION_PRIORITY session_priority,
                             ENUM_BB_COM_SESSION_DATA_TYPE session_dataType)
{
    if ((session_id != BB_COM_SESSION_0) && (session_id < BB_COM_SESSION_MAX))
    {
        BB_ComRemoteSessionInit();

        if (g_BBComSessionArray[session_id].rx_buf)
        {
            if (g_BBComSessionArray[session_id].rx_buf->header.in_use == 0)
            {
                BB_ComSessionInit(session_id,
                                  CPUINFO_GetLocalCpuId(),
                                  1,
                                  session_priority,
                                  session_dataType);
            
                return 1;
            }
            else
            {
                DLOG_Error("Session %d occupied", session_id);
            
                return 0;
            }
        }
        else
        {
            BB_ComSessionInit(session_id,
                              CPUINFO_GetLocalCpuId(),
                              1,
                              session_priority,
                              session_dataType);

            return 1;
        }
    }

    return 0;
}

void BB_ComUnRegisterSession(ENUM_BB_COM_SESSION_ID session_id)
{
    if ((session_id != BB_COM_SESSION_0) && (session_id < BB_COM_SESSION_MAX))
    {
        g_BBComSessionArray[session_id].rx_buf->header.in_use = 0;
        g_BBComSessionArray[session_id].rx_buf->header.rx_buf_wr_pos = 0;
        g_BBComSessionArray[session_id].rx_buf->header.rx_buf_rd_pos = 0;
    }
}

void BB_ComClearTxbuffer(ENUM_BB_COM_SESSION_ID session_id){
	ENUM_BB_COM_SESSION_PRIORITY    e_sessionPriority;
    // STRU_BBComTxQueue              *pst_txQueue;

    if (CPUINFO_GetLocalCpuId() != g_BBComSessionArray[session_id].rx_buf->header.cpu_id)
    {
        DLOG_Error("cpu id not match");

        return ;
    }

    if ((session_id >= BB_COM_SESSION_MAX)||
        (g_BBComSessionArray[session_id].rx_buf->header.in_use == 0))
    {
        DLOG_Error("not in use: %d", session_id);

        return ;
    }
    e_sessionPriority       = g_BBComSessionArray[session_id].e_sessionPriority;
	BB_ComFlushTXQueue(e_sessionPriority,0);
}

uint32_t BB_ComGetFreeLength(ENUM_BB_COM_SESSION_ID session_id)
{
    ENUM_BB_COM_SESSION_PRIORITY    e_sessionPriority;
    STRU_BBComTxQueue              *pst_txQueue;

    if (CPUINFO_GetLocalCpuId() != g_BBComSessionArray[session_id].rx_buf->header.cpu_id)
    {
        DLOG_Error("cpu id not match");

        return 0;
    }

    if ((session_id >= BB_COM_SESSION_MAX)||
        (g_BBComSessionArray[session_id].rx_buf->header.in_use == 0))
    {
        DLOG_Error("not in use: %d", session_id);

        return 0;
    }

    e_sessionPriority       = g_BBComSessionArray[session_id].e_sessionPriority;

    pst_txQueue = g_pstBBComTxQueue[e_sessionPriority];

    return BB_ComGetTXQueueFreeLength(pst_txQueue);

}


uint8_t BB_ComSendMsg(ENUM_BB_COM_SESSION_ID session_id,
                       uint8_t* data_buf,
                       uint16_t length)
{
    uint16_t                        u16_checkSum;
    ENUM_BB_COM_SESSION_PRIORITY    e_sessionPriority;
    uint8_t                         headerBuff[BBCOM_SESSION_DATA_HEADER_SIZE];
    uint8_t                         headerCount = 0;
    uint32_t                        u32_wrPos;
    uint16_t                        i;
    STRU_BBComSessionDataInfo       st_sessionDataInfo;
    STRU_BBComTxQueue              *pst_txQueue;

    if (data_buf == NULL)
    {
        DLOG_Critical("data_buf == NULL ");
        return 0;
    }

    if (CPUINFO_GetLocalCpuId() != g_BBComSessionArray[session_id].rx_buf->header.cpu_id)
    {
        DLOG_Error("cpu id not match: session id: %d, local cpu: %d, session cpu: %d",
                    session_id,
                    CPUINFO_GetLocalCpuId(),
                    g_BBComSessionArray[session_id].rx_buf->header.cpu_id);

        return 0;
    }

    if ((session_id >= BB_COM_SESSION_MAX)||
        (g_BBComSessionArray[session_id].rx_buf->header.in_use == 0))
    {
        DLOG_Error("not in use: %d", session_id);
        return 0;
    }

    e_sessionPriority       = g_BBComSessionArray[session_id].e_sessionPriority;

    pst_txQueue = g_pstBBComTxQueue[e_sessionPriority];

    if (BB_ComGetTXQueueFreeLength(pst_txQueue) <= ((length + BBCOM_SESSION_DATA_HEADER_SIZE) + DATA_CHECK_SUM_SIZE)) //2: two checksum bytes
    {
        // DLOG_Info("%d buffer not enough length = %d",session_id,length);
        return 0;
    }

    session_cnt_tx[session_id] += length;
    /* header */
    for (i = 0; i < sizeof(header); i++)
    {
        headerBuff[headerCount] = header[i];

        headerCount++;
    }

    st_sessionDataInfo.u8_info = 0;

    /* session data type */
    /* session id */
    st_sessionDataInfo.b.dataType   = g_BBComSessionArray[session_id].e_sessionDataType;
    st_sessionDataInfo.b.sessionNum = session_id;

    headerBuff[headerCount - 1]    |= st_sessionDataInfo.u8_info;

    /* data length */
    headerBuff[headerCount]     = (uint8_t)length;
    headerCount++;
    headerBuff[headerCount]     = (uint8_t)(length >> 8);
    headerCount++;

    u16_checkSum = 0;


    /* header checksum */
    for (i = 0; i < headerCount; i++)
    {
        u16_checkSum += headerBuff[i];
    }


    /* header checksum */
    headerBuff[headerCount] = (u16_checkSum & 0xff);


    headerCount++;

    u32_wrPos       = pst_txQueue->tx_queue_header.tx_buf_wr_pos;

    /* insert header into tx queue */
    for (i = 0; i < headerCount; i++)
    {
        pst_txQueue->tx_data[u32_wrPos] = headerBuff[i];

        u32_wrPos++;

        if (u32_wrPos >= pst_txQueue->tx_queue_header.tx_buff_max_size)
        {
            u32_wrPos = 0;
        }
    }

    u16_checkSum     = 0;

    /* insert user data into tx queue */
    for (i = 0; i < length; i++)
    {
        pst_txQueue->tx_data[u32_wrPos] = data_buf[i];

        u16_checkSum += data_buf[i];

        u32_wrPos++;

        if (u32_wrPos >= pst_txQueue->tx_queue_header.tx_buff_max_size)
        {
            u32_wrPos = 0;
        }
    }

    pst_txQueue->tx_data[u32_wrPos] = (u16_checkSum & 0xff);
    u32_wrPos++;
    if (u32_wrPos >= pst_txQueue->tx_queue_header.tx_buff_max_size)
    {
        u32_wrPos = 0;
    }

    pst_txQueue->tx_data[u32_wrPos] = ((u16_checkSum >> 8)& 0xff);
    u32_wrPos++;

    if (u32_wrPos >= pst_txQueue->tx_queue_header.tx_buff_max_size)
    {
        u32_wrPos = 0;
    }

    /* update write postion */
    pst_txQueue->tx_queue_header.tx_buf_wr_pos = u32_wrPos;

    return 1;
}


uint32_t BB_ComReceiveMsg(ENUM_BB_COM_SESSION_ID session_id, uint8_t* data_buf, uint32_t length_max)
{
    if (g_BBComSessionArray[session_id].rx_buf->header.in_use == 1)
    {
        uint32_t wr_pos = g_BBComSessionArray[session_id].rx_buf->header.rx_buf_wr_pos;
        uint32_t rd_pos = g_BBComSessionArray[session_id].rx_buf->header.rx_buf_rd_pos;
        uint32_t tail_pos = g_BBComSessionArray[session_id].data_max_size;

        uint32_t cnt = 0;
        while (rd_pos != wr_pos)
        {
            data_buf[cnt] = g_BBComSessionArray[session_id].rx_buf->data[rd_pos];
            rd_pos++;
            cnt++;

            if (rd_pos >= tail_pos)
            {
                rd_pos = 0;
            }

            if (cnt == length_max)
            {
                break;
            }
        }

        g_BBComSessionArray[session_id].rx_buf->header.rx_buf_rd_pos = rd_pos;

        return cnt;
    }

    return 0;
}


uint16_t BB_ComGetMsgFromTXQueue(ENUM_BB_COM_SESSION_PRIORITY session_priority)
{
    STRU_BBComTxQueue      *pst_txQueue;
    uint32_t                read_pos;
    uint32_t                write_pos;
    uint32_t                max_size;
    uint32_t                current_length;
    uint16_t                read_size;
    uint32_t                i = 0;
    uint16_t                user_data_length;
    uint16_t                total_length;
    uint16_t                tx_fifo_free_length;
    STRU_BBComTxFIFO       *pst_txFIFO;

    pst_txQueue     = g_pstBBComTxQueue[session_priority];
    pst_txFIFO      = &g_BBComTxFIFO;

    read_pos        = pst_txQueue->tx_queue_header.tx_buf_rd_pos;
    write_pos       = pst_txQueue->tx_queue_header.tx_buf_wr_pos;
    max_size        = pst_txQueue->tx_queue_header.tx_buff_max_size;

    DLOG_Error("write_pos = %ld ", write_pos);

    current_length  = BB_ComGetTxQueueCurrentLength(pst_txQueue);

    if (current_length <= (BBCOM_SESSION_DATA_HEADER_SIZE + 2))
    {
        return 0;
    }

    for (i = 0; i < (current_length- (BBCOM_SESSION_DATA_HEADER_SIZE + 2)); i++)
    {
        if ((pst_txQueue->tx_data[(read_pos+i)%max_size] == header[0])&&
            (pst_txQueue->tx_data[(read_pos+(i+1))%max_size] == header[1])&&
            (((pst_txQueue->tx_data[(read_pos+(i+2))%max_size])&header[2]) == header[2]))
        {
            break;
        }
    }

    if (i >= 1)
    {
        DLOG_Error("have invalid data");
    }

    read_pos += i;

    if (read_pos >= max_size)
    {
        read_pos -= max_size;
    }

    if (i >= (current_length-8))
    {
        read_size = 0;
        DLOG_Error("no header found");
    }
    else
    {
        user_data_length   = (pst_txQueue->tx_data[(read_pos+4)%max_size]);
        user_data_length <<= 8;
        user_data_length  += (pst_txQueue->tx_data[(read_pos+3)%max_size]);

        /* header + userdata + userdataChechSum */
        total_length        = ((user_data_length + BBCOM_SESSION_DATA_HEADER_SIZE) + DATA_CHECK_SUM_SIZE);

        /* get free length of tx fifo */
        if (pst_txFIFO->tx_fifo_rd_pos <= pst_txFIFO->tx_fifo_wr_pos)
        {
            tx_fifo_free_length = (pst_txFIFO->tx_fifo_rd_pos + BBCOM_TX_FIFO_SIZE) - pst_txFIFO->tx_fifo_wr_pos;
        }
        else
        {
            tx_fifo_free_length = pst_txFIFO->tx_fifo_rd_pos - pst_txFIFO->tx_fifo_wr_pos;
        }

        /* get tx fifo free length */
        if (tx_fifo_free_length > total_length)
        {
            /* insert msg into tx fifo */
            for (i = 0; i < total_length; i++)
            {
                pst_txFIFO->tx_fifo_data[pst_txFIFO->tx_fifo_wr_pos] = pst_txQueue->tx_data[read_pos];

                read_pos++;
                if (read_pos >= max_size)
                {
                    read_pos = 0;
                }

                pst_txFIFO->tx_fifo_wr_pos++;
                if (pst_txFIFO->tx_fifo_wr_pos >= BBCOM_TX_FIFO_SIZE)
                {
                    pst_txFIFO->tx_fifo_wr_pos = 0;
                }
            }

            read_size = i;
        }
        else
        {
            read_size = 0;
        }
    }

    pst_txQueue->tx_queue_header.tx_buf_rd_pos = read_pos;

    return read_size;
}


void BB_ComFlushTXQueue(ENUM_BB_COM_SESSION_PRIORITY session_priority, ENUM_BB_COM_TYPE bb_comType)
{
    STRU_BBComTxQueue  *pst_txQueue;

    pst_txQueue     = g_pstBBComTxQueue[session_priority];

    //BB_ComLockAccquire();

    pst_txQueue->tx_queue_header.tx_buf_rd_pos = 0;
    pst_txQueue->tx_queue_header.tx_buf_wr_pos = 0;
	DLOG_Warning("now is to clear the txqueue ");
    //BB_ComLockRelease();
}


uint32_t BB_ComGetTXQueueFreeLength(STRU_BBComTxQueue *pst_txQueue)
{
    uint32_t        max_size;
    uint32_t        wr_pos;
    uint32_t        rd_pos;
    uint32_t        free_length;

    max_size        = pst_txQueue->tx_queue_header.tx_buff_max_size;
    wr_pos          = pst_txQueue->tx_queue_header.tx_buf_wr_pos;
    rd_pos          = pst_txQueue->tx_queue_header.tx_buf_rd_pos;
	
    if (wr_pos >= rd_pos)
    {
        free_length = ((max_size - wr_pos) + rd_pos);
    }
    else
    {
        free_length = rd_pos - wr_pos;
    }
	// DLOG_Info("max_size = %ld,wr_pos=%ld,rd_pos=%ld,free_length=%ld",max_size,wr_pos,rd_pos,free_length);
    return free_length;
}


uint32_t BB_ComGetTxQueueCurrentLength(STRU_BBComTxQueue *pst_txQueue)
{
    uint32_t                max_size;
    uint32_t                wr_pos;
    uint32_t                rd_pos;
    uint32_t                current_length;

    max_size        = pst_txQueue->tx_queue_header.tx_buff_max_size;
    wr_pos          = pst_txQueue->tx_queue_header.tx_buf_wr_pos;
    rd_pos          = pst_txQueue->tx_queue_header.tx_buf_rd_pos;

    if (wr_pos >= rd_pos)
    {
        current_length = wr_pos - rd_pos;
    }
    else
    {
        current_length = (max_size - rd_pos) + wr_pos;
    }
	//DLOG_Info("max_size = %d,wr_pos=%d,rd_pos=%d,current_length=%d",max_size,wr_pos,rd_pos,current_length);
    return current_length;
}


void BB_ComCycleMsgProcess(void)
{
    uint8_t         i;
    uint8_t         j;
    uint8_t         max_msg_count = 20;
    uint16_t        msg_length;

    /* get session0 message first, every 14ms, get 5 messages ultimately */
    for (i = 5; i > 0; i--)
    {
        msg_length = BB_ComGetMsgFromTXQueue(BB_COM_SESSION_PRIORITY_MAX);

        if (0 == msg_length)
        {
            break;
        }
    }
    /* get high priority message first, every 14ms, get 20 messages ultimately */
    for (i = max_msg_count; i > 0; i--)
    {
        msg_length = BB_ComGetMsgFromTXQueue(BB_COM_SESSION_PRIORITY_HIGH);

        if (0 == msg_length)
        {
            break;
        }
    }

    /* then get low priority message */
    for (j = 0; j < i; j++)
    {
        msg_length = BB_ComGetMsgFromTXQueue(BB_COM_SESSION_PRIORITY_LOW);

        if (0 == msg_length)
        {
            break;
        }
    }

    return;
}


void BB_ComCycleSendMsg(ENUM_BB_COM_TYPE e_bbComType,
                        uint8_t spi_info_size,
                        uint8_t *spi_info)
{
    static uint8_t          fill = 0;
    uint16_t                i;
    uint16_t                read_pos;
    uint16_t                write_pos;
    STRU_BBComTxFIFO       *pst_txFIFO;
    
    pst_txFIFO      = &g_BBComTxFIFO;

    if (BB_COM_TYPE_UART == e_bbComType) // uart channel
    {
        uint8_t                 uart_send_buff[BB_UART_TX_FIFO_QPSK_SIZE];
        uint16_t                uart_send_size = 0;
        uint32_t                uart_max_tx_size;
        uint16_t                uart_size_align;
        
        if (0 != uart_checkoutFifoStatus(BBCOM_UART_INDEX))
        {
            // DLOG_Error("bb uart fifo busy");
		
            return;
        }
		
        /* in sky, no need to consider RC rate */
        if (context.en_bbmode == BB_SKY_MODE)
        {
            uart_max_tx_size = BB_UART_TX_FIFO_QPSK_SIZE;
        }
        else
        {
            uart_max_tx_size = BB_UART_GetTxFifoMaxSize(BB_GRD_MODE);
        }


        read_pos        = pst_txFIFO->tx_fifo_rd_pos;
        write_pos       = pst_txFIFO->tx_fifo_wr_pos;

        for (i = 0; i < uart_max_tx_size; i++)
        {
            if (read_pos == write_pos)
            {
                break;
            }

            uart_send_buff[i] = pst_txFIFO->tx_fifo_data[read_pos++];

            if (read_pos >= BBCOM_TX_FIFO_SIZE)
            {
                read_pos = 0;
            }

            uart_send_size++;
        }

        pst_txFIFO->tx_fifo_rd_pos  = read_pos;
        
        /* 16 byte aligned */
        if ((uart_send_size > 0)&&
            ((uart_send_size % 16) != 0))
        {
            //size_align = send_size;
            uart_size_align = 16 - (uart_send_size % 16);
        
            for (i = 0; i < uart_size_align; i++)
            {
                uart_send_buff[uart_send_size++] = 0;
            }
        }
        
        if (uart_send_size != 0)
        {
            uart_putdata(BBCOM_UART_INDEX,  (const char*)uart_send_buff, uart_send_size);
			if(uart_send_size >0)
            DLOG_Info("1 %ld %d %ld",uart_max_tx_size,uart_send_size,SysTicks_GetTickCount());
        }
        
    }
    else // spi channel
    {
        #define USER_DATA_VALID         (0x01)
        #define USER_DATA_MASK          (0x01)

        
        STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);
        // UNION_BBSPIComHeadByte un_bbSPIComHeadByte;
        uint8_t offset = 0;
        uint8_t spi_com_start_addr;
        uint8_t  spi_send_buff[BB_SPI_TX_FIFO_SIZE];
        uint16_t spi_send_size = 0;
        uint32_t spi_max_tx_size  = 0;

        if(BB_SpiChkDataTransChValid())
        {
            offset = pst_spiDSave->max_len+ 1;
        }

        spi_com_start_addr = SPI_DT_END_ADDR - offset;
        spi_max_tx_size  = BB_SPI_TX_FIFO_SIZE - 1 - spi_info_size - offset;

        read_pos        = pst_txFIFO->tx_fifo_rd_pos;
        write_pos       = pst_txFIFO->tx_fifo_wr_pos;

        for (i = 0; i < spi_max_tx_size; i++)
        {
            if ((read_pos == write_pos))
            {
                break;
            }

            spi_send_buff[i] = pst_txFIFO->tx_fifo_data[read_pos++];

            if (read_pos >= BBCOM_TX_FIFO_SIZE)
            {
                read_pos = 0;
            }

            spi_send_size++;
        }

        pst_txFIFO->tx_fifo_rd_pos  = read_pos;
        
        if (spi_send_size > 0)
        {
            BB_SPI_WriteByteMask(PAGE2, SPI_DT_HEAD_REGISTER, USER_DATA_MASK, USER_DATA_VALID); //datavalid

            for (i = 0; i < spi_send_size; i++)
            {
                BB_SPI_WriteByte(PAGE2, spi_com_start_addr, spi_send_buff[i]);
                spi_com_start_addr--;
            }

        }
        else
        {
        }

        //BB_SpiGrdDataTransChProc();
        
        for (i = 0; i < (spi_max_tx_size - spi_send_size); i++)
        {
            BB_SPI_WriteByte(PAGE2, spi_com_start_addr, fill++);
            spi_com_start_addr--;
        }
		if(spi_send_size >0)
        DLOG_Info("2 %ld %d %ld",spi_max_tx_size,spi_send_size,SysTicks_GetTickCount());
    }

    return;
}


/* only for sky */
uint16_t BB_UARTComGetBBFIFOGap(void)
{
    uint8_t         read_fifo_gap_enable;
    uint8_t         fifo_gap_high;
    uint8_t         fifo_gap_low;
    uint16_t        fifo_gap;

    read_fifo_gap_enable    = BB_ReadReg(PAGE0, 0x0C);
    read_fifo_gap_enable   |= 0x40;
    BB_WriteReg(PAGE0, 0x0C, read_fifo_gap_enable);

    fifo_gap_high           = BB_ReadReg(PAGE0, 0xF6);

    fifo_gap_low            = BB_ReadReg(PAGE0, 0xF7);

    fifo_gap                = (fifo_gap_high << 8) + fifo_gap_low;

    fifo_gap                = 2048 - fifo_gap;

    return fifo_gap;
}


uint32_t BB_UART_GetTxFifoMaxSize(ENUM_BB_MODE e_bb_mode)
{
    uint32_t      rc_rate = 0;

    rc_rate = BB_GetRcRate(e_bb_mode);

    if (rc_rate == 1)
    {
        return BB_UART_TX_FIFO_BPSK_SIZE;
    }
    else if (rc_rate == 2)
    {
        return BB_UART_TX_FIFO_QPSK_SIZE;
    }
    else if (rc_rate == 3)
    {
        return BB_UART_TX_FIFO_QPSK1_2_SIZE;
    }
    else if (rc_rate == 4)
    {
        return BB_UART_TX_FIFO_BPSK2_3_SIZE;
    }
    else
    {
        return BB_UART_TX_FIFO_BPSK_SIZE;
    }
}


uint32_t BB_UARTComRecvDataHandler(uint8_t *u8_uartRxBuf, uint8_t u8_uartRxLen)
{
    if (NULL != BB_JudgeLockStatus)
    {
        if (1 == BB_JudgeLockStatus(NULL))
        {
            return BB_ComPacketDataAnalyze(u8_uartRxBuf, u8_uartRxLen, &g_BBComRxFIFO);
        }
    }
    else
    {
        return BB_ComPacketDataAnalyze(u8_uartRxBuf, u8_uartRxLen, &g_BBComRxFIFO);
    }

    return 0;
}

uint32_t BB_SpiDataTransRcv(void)
{
    // uint8_t                 u8_spiRxBuf[BB_SPI_TX_FIFO_SIZE];
    uint8_t                 spi_com_start_addr = SPI_DT_END_ADDR;
    uint8_t                 i;
    uint8_t                 *pHead;
    STRU_SPI_DATA_TRANS_FORMAT trans_data;
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);

    if(BB_SpiChkDataTransChValid())
    {
        pHead = (uint8_t *)(&trans_data);
        pHead[0] = BB_SPI_ReadByte(PAGE2, spi_com_start_addr);
        if((trans_data.valid) && \
            (trans_data.len <= pst_spiDSave->max_len) && \
            (trans_data.len > 0))
        {
            spi_com_start_addr--;
            for (i = 1; i<= trans_data.len; i++)
            {
                pHead[i] = BB_SPI_ReadByte(PAGE2, spi_com_start_addr);
                spi_com_start_addr--;
            }

            if(0 == pst_spiDSave->busy)
            {
                pst_spiDSave->busy = 1;
                pst_spiDSave->real_len = trans_data.len;
                memcpy(pst_spiDSave->data, trans_data.data, pst_spiDSave->real_len);
                pst_spiDSave->valid = 1;
                pst_spiDSave->busy = 0;
                //send notify
                SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_SPI_DATA_TRANS, NULL);
            }
        }
    }

    return 0;
}


uint32_t BB_SPIComRecvData(void)
{
    uint8_t                 u8_spiRxBuf[BB_SPI_TX_FIFO_SIZE];
    uint8_t                 u8_spiUserDataLen;
    UNION_BBSPIComHeadByte  un_bbSPIComHeadByte;
    uint8_t                 spi_com_start_addr = SPI_DT_END_ADDR;
    uint8_t                 offset = 0;
    uint8_t                 i;
    // uint8_t                 *pHead;
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);

    if(BB_SpiChkDataTransChValid())
    {
        offset = pst_spiDSave->max_len+ 1;
    }
    
    un_bbSPIComHeadByte.u8_headByte = BB_SPI_ReadByte(PAGE2, SPI_DT_HEAD_REGISTER);

    if (1 == un_bbSPIComHeadByte.b.user_data_valid)
    {
        u8_spiUserDataLen = (BB_SPI_TX_FIFO_SIZE - 1 - un_bbSPIComHeadByte.b.bb_data_size - offset);

        spi_com_start_addr = SPI_DT_END_ADDR - offset;
        for (i = 0; i< u8_spiUserDataLen; i++)
        {
            u8_spiRxBuf[i] = BB_SPI_ReadByte(PAGE2, spi_com_start_addr);
            spi_com_start_addr--;
        }

        return BB_ComPacketDataAnalyze(u8_spiRxBuf, u8_spiUserDataLen, &g_BBComRxFIFO);
    }

    return 0;
}

int BB_SpiGrdDataTransChProc(void)
{
    uint8_t spi_com_start_addr = SPI_DT_END_ADDR;
    uint8_t i = 0;
    uint8_t *pData = NULL;

    STRU_SPI_DATA_TRANS_FORMAT trans_data;
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);
    
    if(BB_SpiChkDataTransChValid() && \
        (pst_spiDSave->real_len <= pst_spiDSave->max_len) && 
        (pst_spiDSave->real_len > 0))
    {
        BB_WriteReg(PAGE2, SPI_DT_END_ADDR, 0);
        if((0 == pst_spiDSave->busy) && (1 == pst_spiDSave->valid))
        {
            trans_data.valid = 1;
            trans_data.len = pst_spiDSave->real_len;

            pst_spiDSave->busy = 1;
            memcpy(trans_data.data, pst_spiDSave->data, trans_data.len);
            pst_spiDSave->busy = 0;
            pst_spiDSave->valid = 0;

            pData = (uint8_t *)(&trans_data);
            for (i = 0; i < (trans_data.len + 1); i++)
            {
                BB_SPI_WriteByte(PAGE2, spi_com_start_addr, pData[i]);
                spi_com_start_addr--;
            }

            return 0;
        }
    }

    return -1;
}

uint8_t BB_SpiChkDataTransChValid(void)
{
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);
    
    if((1 == pst_spiDSave->init) && \
        (pst_spiDSave->max_len <= SPI_DATA_TRANS_MAX_LEN) && \
        (pst_spiDSave->max_len > 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BB_SetAesOffUartMaxLen(uint8_t max_len)
{
    uart_aes_off_len(max_len);
}

uint8_t BB_GetUartDummyCnt(void)
{
    return uart_dummy_cnt();
}