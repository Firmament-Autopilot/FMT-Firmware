#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "pll_ctrl.h"
#include "cpu_info.h"
#include "interrupt.h"
#include "serial.h"
#include "drv_systick.h"
#include "memory_config.h"
#include "hal_uart.h"
#include "debuglog.h"
#include "driver_buffer.h"

//the user CallBack for uart receive data.
static UART_RxHandler s_pfun_uartUserHandlerTbl[UART_TOTAL_CHANNEL] =  
       { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

volatile static uart_tx s_st_uartTxArray[UART_TOTAL_CHANNEL];

#define SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE               0x400
uint8_t u8_uartTxData[SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE];

//patch for bb aes=off
static uint8_t bb_com_rx_buf[256];
static uint8_t bb_com_rx_len;
static uint32_t bb_com_rx_time;
static uint8_t bb_aes_off_flag=0;
static uint8_t bb_aes_off_uart_max_len;
static uint8_t bb_aes_off_uart_dummy_cnt;


volatile static uart_tx_ringbuff *s_pst_uart10 = (uart_tx_ringbuff *)(u8_uartTxData);
/*********************************************************
 * Generic UART APIs
 *********************************************************/

static uart_type* get_uart_type_by_index(unsigned char index)
{
    uart_type *uart_regs;

    switch (index)
    {
    case 0:
        uart_regs = (uart_type *)UART0_BASE;
        break;
    case 1:
        uart_regs = (uart_type *)UART1_BASE;
        break;
    case 2:
        uart_regs = (uart_type *)UART2_BASE;
        break;
    case 3:
        uart_regs = (uart_type *)UART3_BASE;
        break;
    case 4:
        uart_regs = (uart_type *)UART4_BASE;
        break;
    case 5:
        uart_regs = (uart_type *)UART5_BASE;
        break;
    case 6:
        uart_regs = (uart_type *)UART6_BASE;
        break;
    case 7:
        uart_regs = (uart_type *)UART7_BASE;
        break;
    case 8:
        uart_regs = (uart_type *)UART8_BASE;
        break;
    case 9:
        uart_regs = (uart_type *)UART9_BASE;
        break;
    case 10:
        uart_regs = (uart_type *)UART10_BASE;
        break;
    default:
        uart_regs = (uart_type *)NULL;
        break;
    }

    return uart_regs;
}

static uint32_t get_uart_clock_by_index(unsigned char index)
{
    uint16_t u16_pllClk = 64;

    switch (index)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        PLLCTRL_GetCoreClk(&u16_pllClk, ENUM_CPU0_ID);
        u16_pllClk = u16_pllClk >> 1;
        break;
    case 9:
    case 10:
        PLLCTRL_GetCoreClk(&u16_pllClk, ENUM_CPU2_ID);
        break;
    default:
        break;
    }

    return (uint32_t)u16_pllClk;
}

void uart_aes_off(void)
{
    bb_aes_off_flag = 1;
}
void uart_aes_off_len(uint8_t len)
{
    bb_aes_off_uart_max_len = len;
}
uint8_t uart_dummy_cnt(void)
{
    return bb_aes_off_uart_dummy_cnt;
}

void uart_init(unsigned char index, unsigned int baud_rate)
{
    int devisor;
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);

    if (uart_regs != NULL)
    {
        uart_regs->IIR_FCR = UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14 | UART_FCR_ENABLE_FIFO;
        uart_regs->DLH_IER = 0x00000000;
        uart_regs->LCR = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

        devisor = (get_uart_clock_by_index(index) * 1000000) / (16 * baud_rate);
        uart_regs->LCR |= UART_LCR_DLAB;
        uart_regs->DLH_IER = (devisor >> 8) & 0x000000ff;
        uart_regs->RBR_THR_DLL = devisor & 0x000000ff;
        uart_regs->LCR &= ~UART_LCR_DLAB;
        uart_regs->DLH_IER |= UART_DLH_IER_RX_INT;

        if (10 != index)
        {        
            //s_st_uartTxArray[index].ps8_uartSendBuff = NULL;
            s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
            s_st_uartTxArray[index].u16_uartSendBuffLen = 0;
        }
        else
        {
            memset((void *)(u8_uartTxData), 0, SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE);
            s_pst_uart10->u32_buffCurrentPosition = (uint32_t)u8_uartTxData + sizeof(uart_tx_ringbuff);
        }
    }

    return;
}

void uart_set_baudrate(unsigned char index, unsigned int baud_rate)
{
    int devisor;
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);

    if (uart_regs != NULL)
    {
        uart_regs->IIR_FCR = UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14 | UART_FCR_ENABLE_FIFO;
        uart_regs->DLH_IER = 0x00000000;
        uart_regs->LCR = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

        devisor = (get_uart_clock_by_index(index) * 1000000) / (16 * baud_rate);
        uart_regs->LCR |= UART_LCR_DLAB;
        uart_regs->DLH_IER = (devisor >> 8) & 0x000000ff;
        uart_regs->RBR_THR_DLL = devisor & 0x000000ff;
        uart_regs->LCR &= ~UART_LCR_DLAB;
        uart_regs->DLH_IER |= UART_DLH_IER_RX_INT;
    }

    return;
}

void sbus_init(unsigned char index, unsigned int baud_rate)
{
    int devisor;
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);

    if (uart_regs != NULL)
    {
        uart_regs->IIR_FCR = UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14 | UART_FCR_ENABLE_FIFO;
        uart_regs->DLH_IER = 0x00000000;
        uart_regs->LCR = UART_LCR_WLEN8 | UART_LCR_STOP | (1 << 4) | (1 << 3);

        devisor = (get_uart_clock_by_index(index) * 1000000) / (16 * baud_rate);
        uart_regs->LCR |= UART_LCR_DLAB;
        uart_regs->DLH_IER = (devisor >> 8) & 0x000000ff;
        uart_regs->RBR_THR_DLL = devisor & 0x000000ff;
        uart_regs->LCR &= ~UART_LCR_DLAB;
        uart_regs->DLH_IER |= UART_DLH_IER_RX_INT;

        if (10 != index)
        {        
            //s_st_uartTxArray[index].ps8_uartSendBuff = NULL;
            s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
            s_st_uartTxArray[index].u16_uartSendBuffLen = 0;
        }
        else
        {
            memset((void *)(u8_uartTxData), 0, SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE);
            s_pst_uart10->u32_buffCurrentPosition = (uint32_t)u8_uartTxData + sizeof(uart_tx_ringbuff);
        }
    }

    return;
}


uint8_t uart_checkoutFifoStatus(unsigned char index)
{
    if (10 != index)
    {
        if ((0 == s_st_uartTxArray[index].u16_uartSendBuffLen) && (0 == s_st_uartTxArray[index].u16_uartSendBuffLentmp))
        {
            return 0;
        }
        else
        {
            return 1;
        }        
    }
    else
    {
        if ((0 == s_pst_uart10->u16_uartSendBuffLen) && (0 == s_pst_uart10->u16_uartSendBuffLentmp))
        {
            return 0;
        }
        else
        {
            return 1;
        }        
    }
}

#if 0
int32_t Uart10_WaitTillIdle(unsigned char index, uint16_t datalen)
{

    if (s_pst_uart10->u16_uartSendBuffLen + datalen  >= SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE - sizeof(uart_tx_ringbuff))
    {
        DLOG_Error("uart10 data overflow");
        return -1;
    }
    
    return 0;    
}
#endif

int32_t Uart_WaitTillIdle(unsigned char index, uint32_t timeOut)
{
    uint32_t start;
    
    if (0 != timeOut)
    {
        start = SysTicks_GetTickCount();
        while (uart_checkoutFifoStatus(index))
        {
            if ((SysTicks_GetDiff(start, SysTicks_GetTickCount())) >= timeOut)
            {
                return -1;
            }
        }
    }

    return 0;
}

void uart_putFifo(unsigned char index)
{
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);   

    if (uart_regs != NULL)
    {
        uint8_t u8_sendDataLenCunt = 0;

        if (10 != index)
        {
            if (s_st_uartTxArray[index].u16_uartSendBuffLen > UART_TFL_MAX)
            {
                for (u8_sendDataLenCunt=0; u8_sendDataLenCunt < UART_TFL_MAX; u8_sendDataLenCunt++)
                {                      
                    uart_regs->RBR_THR_DLL = *(s_st_uartTxArray[index].ps8_uartSendBuff + s_st_uartTxArray[index].u16_uartSendBuffLentmp + u8_sendDataLenCunt);            
                }

                s_st_uartTxArray[index].u16_uartSendBuffLen -= UART_TFL_MAX;
                s_st_uartTxArray[index].u16_uartSendBuffLentmp += UART_TFL_MAX;

            }
            else if ((s_st_uartTxArray[index].u16_uartSendBuffLen <= UART_TFL_MAX) && (s_st_uartTxArray[index].u16_uartSendBuffLen > 0))
            {
                for (u8_sendDataLenCunt=0; u8_sendDataLenCunt<s_st_uartTxArray[index].u16_uartSendBuffLen; u8_sendDataLenCunt++)
                {                      
                    uart_regs->RBR_THR_DLL = *(s_st_uartTxArray[index].ps8_uartSendBuff + s_st_uartTxArray[index].u16_uartSendBuffLentmp + u8_sendDataLenCunt);            
                }
                s_st_uartTxArray[index].u16_uartSendBuffLentmp += s_st_uartTxArray[index].u16_uartSendBuffLen;
                s_st_uartTxArray[index].u16_uartSendBuffLen = 0;
/*                 s_st_uartTxArray[index].ps8_uartSendBuff = NULL;                   */
            }
            else
            {            
                s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
                uart_regs->DLH_IER &= ~(UART_DLH_IER_TX_INT);
            }        
        }
        else
        {
            if (s_pst_uart10->u16_uartSendBuffLen > UART_TFL_MAX)
            {
                for (u8_sendDataLenCunt=0; u8_sendDataLenCunt < UART_TFL_MAX; u8_sendDataLenCunt++)
                {                      
                    uart_regs->RBR_THR_DLL = *((uint8_t *)(s_pst_uart10->u32_buffCurrentPosition++));
                    
                    if (s_pst_uart10->u32_buffCurrentPosition >=((uint32_t)u8_uartTxData + SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE))            
                    {
                        s_pst_uart10->u32_buffCurrentPosition = (uint32_t)u8_uartTxData + sizeof(uart_tx_ringbuff);
                    }
                }
                
                s_pst_uart10->u16_uartSendBuffLen -= UART_TFL_MAX;
                s_pst_uart10->u16_uartSendBuffLentmp += UART_TFL_MAX;

            }
            else if ((s_pst_uart10->u16_uartSendBuffLen <= UART_TFL_MAX) && (s_pst_uart10->u16_uartSendBuffLen > 0))
            {
                for (u8_sendDataLenCunt=0; u8_sendDataLenCunt < s_pst_uart10->u16_uartSendBuffLen; u8_sendDataLenCunt++)
                {                      
                    
                    uart_regs->RBR_THR_DLL = *((uint8_t *)(s_pst_uart10->u32_buffCurrentPosition++));
                    
                    if (s_pst_uart10->u32_buffCurrentPosition >=( (uint32_t)u8_uartTxData + SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE))            
                    {
                        s_pst_uart10->u32_buffCurrentPosition = (uint32_t)u8_uartTxData + sizeof(uart_tx_ringbuff);
                    }
                }
                
                s_pst_uart10->u16_uartSendBuffLentmp += s_pst_uart10->u16_uartSendBuffLen;
                s_pst_uart10->u16_uartSendBuffLen = 0;                
            }
            else
            {            
                s_pst_uart10->u16_uartSendBuffLentmp = 0;
                uart_regs->DLH_IER &= ~(UART_DLH_IER_TX_INT);
            }            
        }
    }
    else
    {
         DLOG_Error("uart%d_null",index);
    }
}

static char s_s8_uartchartmp = '\0';
void uart_putc(unsigned char index, char c)
{
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);
    
    s_s8_uartchartmp = c;

    if (NULL == uart_regs)
    {
        DLOG_Error("uart%d_null",index);
        return ;        
    }
    
    s_st_uartTxArray[index].u16_uartSendBuffLen = 1;
    s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
    s_st_uartTxArray[index].ps8_uartSendBuff = &s_s8_uartchartmp;

    uart_regs->DLH_IER |= UART_DLH_IER_TX_INT;
}

void uart_puts(unsigned char index, const char *s)
{
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);

    if (NULL == uart_regs || (0 == strlen(s)))
    {
        DLOG_Error("regs=0x%p %d =%d", (void *)uart_regs, index, strlen(s));
        return ;        
    }

    s_st_uartTxArray[index].u16_uartSendBuffLen = strlen(s);
    s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
    s_st_uartTxArray[index].ps8_uartSendBuff = s;

    uart_regs->DLH_IER |= UART_DLH_IER_TX_INT;
}

void uart_putdata(unsigned char index,  const char *s, unsigned short dataLen)
{
    volatile uart_type *uart_regs;
    uart_regs = get_uart_type_by_index(index);

    if (NULL == uart_regs || (0 == dataLen))
    {
        DLOG_Error("%d",index);
        return ;        
    }
    
    if (10 != index)
    {
        s_st_uartTxArray[index].u16_uartSendBuffLen = dataLen;
        s_st_uartTxArray[index].u16_uartSendBuffLentmp = 0;
        if(0 != COMMON_getNewBuffer((uint8_t**)(&s_st_uartTxArray[index].ps8_uartSendBuff),
                               (uint8_t*)s,
                               (uint32_t*)&s_st_uartTxArray[index].txLenLast, 
                               dataLen))
        {
            DLOG_Error("fail");
        }
    }
    else
    {
        if (s_pst_uart10->u16_uartSendBuffLen + dataLen  >= SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE - sizeof(uart_tx_ringbuff))
        {
            return ;
        }
        else
        {

            if ((s_pst_uart10->u32_buffCurrentPosition + s_pst_uart10->u16_uartSendBuffLen + dataLen) >= 
                ((uint32_t)u8_uartTxData + SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE))
            {
                uint16_t tmp = (uint32_t)u8_uartTxData + SRAM_BB_UART_COM_TX_SHARE_MEMORY_SIZE - s_pst_uart10->u32_buffCurrentPosition - s_pst_uart10->u16_uartSendBuffLen;
                
                memcpy((uint8_t *)(s_pst_uart10->u32_buffCurrentPosition + s_pst_uart10->u16_uartSendBuffLen), s, tmp);
                
                memcpy((uint8_t *)((uint32_t)u8_uartTxData + sizeof(uart_tx_ringbuff)), s + tmp, dataLen - tmp);            
            }
            else
            {
                memcpy((uint8_t *)(s_pst_uart10->u32_buffCurrentPosition + s_pst_uart10->u16_uartSendBuffLen), s, dataLen);
            }

            s_pst_uart10->u16_uartSendBuffLen += dataLen;
                    
        }
    }
    uart_regs->DLH_IER |= UART_DLH_IER_TX_INT;
    
}


char uart_getc(unsigned char index)
{
    char tmp = 0;
    volatile uart_type *uart_regs = get_uart_type_by_index(index);

    if (uart_regs != NULL)
    {
        while ((uart_regs->LSR & UART_LSR_DATAREADY) != UART_LSR_DATAREADY); 
        tmp = uart_regs->RBR_THR_DLL;
    }

    return tmp;
}

/**
* @brief  uart interrupt servive function.just handled data reception.  
* @param  u32_vectorNum           Interrupt number.
* @retval None.
* @note   None.
*/

void UART_IntrSrvc(uint32_t u32_vectorNum)
{
    uint8_t u8_uartRxBuf[20];
    uint8_t u8_uartRxLen = 0;
    uint8_t u8_uartCh;
    uint32_t u32_uartIsrType;
    uint32_t t;
    volatile uart_type      *pst_uartRegs;
    volatile uint32_t       ret;

    if (VIDEO_UART9_INTR_VECTOR_NUM == u32_vectorNum)
    {
        u8_uartCh = 9;
    }
    else if (VIDEO_UART10_INTR_VECTOR_NUM == u32_vectorNum)
    {
        u8_uartCh = 10;
    }
    else
    {
        u8_uartCh = u32_vectorNum - UART_INTR0_VECTOR_NUM;
    }
 
    pst_uartRegs = get_uart_type_by_index(u8_uartCh);

    u32_uartIsrType = pst_uartRegs->IIR_FCR;

     /* receive data irq, try to get the data */

    if (UART_IIR_RECEIVEDATA == (u32_uartIsrType & 0xf))
    {
        uint8_t i = UART_RX_FIFOLEN;
        while (i--)
        {
            u8_uartRxBuf[u8_uartRxLen++] = pst_uartRegs->RBR_THR_DLL;
        }
    }

    if (UART_IIR_DATATIMEOUT == (u32_uartIsrType & 0xf))
    {

        u8_uartRxBuf[u8_uartRxLen++] = pst_uartRegs->RBR_THR_DLL;
    }

    if(u8_uartRxLen > 0) // call user function
    {
    	#if 0
			DLOG_Critical("received uart data cnt= %d",u8_uartRxLen);
		#endif
    	if(u8_uartCh == 10 && bb_aes_off_flag)
        {
            #if 1
            t = SysTicks_GetTickCount();
            if(SysTicks_GetDiff(bb_com_rx_time,t) > 10)
			{
                if(bb_com_rx_len > 0){
                    DLOG_Error("time out than 10: -%d %d",bb_com_rx_len,u8_uartRxLen);
                    bb_com_rx_len = 0;
                }
            }
            if(bb_com_rx_len + u8_uartRxLen > 256)
			{
                DLOG_Error("over size: %d %d",bb_com_rx_len,u8_uartRxLen);
                bb_com_rx_len = 0;
            }
			
            memcpy(bb_com_rx_buf+bb_com_rx_len,u8_uartRxBuf,u8_uartRxLen);
            bb_com_rx_len += u8_uartRxLen;
			
            if(bb_com_rx_len == bb_aes_off_uart_max_len)
            {
                //if( bb_com_rx_buf[0] > 0 && (bb_com_rx_buf[0]==32 || bb_com_rx_buf[0]==128 || bb_com_rx_buf[0]==64 || bb_com_rx_buf[0]==208 ))
                if( bb_com_rx_buf[0] > 0)
				{
                    if((NULL != (s_pfun_uartUserHandlerTbl[u8_uartCh])))
                    {
                    	#if 0
                    	DLOG_Critical("valid uart len= %d",bb_com_rx_buf[0]);
						#endif
                        (s_pfun_uartUserHandlerTbl[u8_uartCh])(bb_com_rx_buf+1, bb_com_rx_buf[0]);
                    }
                    bb_aes_off_uart_dummy_cnt = bb_com_rx_buf[bb_com_rx_buf[0]+1];
                    DLOG_Info("%d %d",bb_com_rx_buf[0],bb_aes_off_uart_dummy_cnt);
                }
                else
				{
                    if(bb_aes_off_uart_max_len == 34){//bpsk 1/2
                        bb_aes_off_uart_dummy_cnt = bb_com_rx_buf[33];
                    }
                    else if(bb_aes_off_uart_max_len == 142){//qpsk 1/2
                        bb_aes_off_uart_dummy_cnt = bb_com_rx_buf[129];
                    }
                    else{
                        DLOG_Error("%d",bb_aes_off_uart_max_len);
                    }
                    //if(bb_com_rx_buf[0]>10)
                    DLOG_Info(">%d %d %d",bb_com_rx_buf[0],u8_uartRxLen,bb_aes_off_uart_dummy_cnt);
                }
                bb_com_rx_len = 0;
            }
			else
			{
				//DLOG_Critical("bb_com_rx_len : %d %d",bb_com_rx_len,u8_uartRxLen);
			}
            bb_com_rx_time = t;
            #endif
    	}
        else
		{
            if(NULL != (s_pfun_uartUserHandlerTbl[u8_uartCh]))
            {
                (s_pfun_uartUserHandlerTbl[u8_uartCh])(u8_uartRxBuf, u8_uartRxLen);
            }
        }
    }

    // TX empty interrupt.
    if (UART_IIR_THR_EMPTY == (u32_uartIsrType & 0xf))
    {
        uart_putFifo(u8_uartCh);                
    }

    if (UART_IIR_INTID_BUSY == (u32_uartIsrType & 0xf))
    {
        ret = pst_uartRegs->USR;
    }

}



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
int32_t UART_RegisterUserRxHandler(uint8_t u8_uartCh, UART_RxHandler userHandle)
{
    if(u8_uartCh >= UART_TOTAL_CHANNEL)
    {
        return -1;
    }

    s_pfun_uartUserHandlerTbl[u8_uartCh] = userHandle;

    return 0;
}

/**
* @brief  unregister user function for uart recevie data.
* @param  u8_uartCh           uart channel, 0 ~ 10.
* @retval 
*         -1                  unregister user function failed.
*         0                   unregister user function sucessed.
* @note   None.
*/
int32_t UART_UnRegisterUserRxHandler(uint8_t u8_uartCh)
{
    if(u8_uartCh >= UART_TOTAL_CHANNEL)
    {
        return -1;
    }

    s_pfun_uartUserHandlerTbl[u8_uartCh] = NULL;

    return 0;
}



