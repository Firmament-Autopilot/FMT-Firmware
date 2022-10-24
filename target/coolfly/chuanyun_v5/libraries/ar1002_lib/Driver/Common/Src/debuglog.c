#include <stdio.h>
#include <string.h>
#include "memory_config.h"
#include "debuglog.h"
#include "sys_event.h"
#include "serial.h"
#include "ar8020.h"
#include "cpu_info.h"
#include "interrupt.h"
#include "hal_uart.h"


volatile uint8_t sd_mountStatus = 0;
static uint8_t g_log_level = LOG_LEVEL_INFO;

static uint8_t s_u8_dlogServerCpuId = 0xFF;

#define DEBUG_LOG_OUTPUT_BUF_HEAD_0      ((char*)(((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_0)->buf))
#define DEBUG_LOG_OUTPUT_BUF_TAIL_0      ((char*)(SRAM_DEBUG_LOG_OUTPUT_BUFFER_END_ADDR_0))
#define DEBUG_LOG_OUTPUT_BUF_HEAD_1      ((char*)(((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_1)->buf))
#define DEBUG_LOG_OUTPUT_BUF_TAIL_1      ((char*)(SRAM_DEBUG_LOG_OUTPUT_BUFFER_END_ADDR_1))
#define DEBUG_LOG_OUTPUT_BUF_HEAD_2      ((char*)(((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_2)->buf))
#define DEBUG_LOG_OUTPUT_BUF_TAIL_2      ((char*)(SRAM_DEBUG_LOG_OUTPUT_BUFFER_END_ADDR_2))

#define DEBUG_LOG_OUTPUT_BUF_WR_POS_0    (((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_0)->header.output_buf_wr_pos)
#define DEBUG_LOG_OUTPUT_BUF_RD_POS_0    (s_debug_log_output_buf_rd_pos_0)
#define DEBUG_LOG_OUTPUT_BUF_WR_POS_1    (((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_1)->header.output_buf_wr_pos)
#define DEBUG_LOG_OUTPUT_BUF_RD_POS_1    (s_debug_log_output_buf_rd_pos_1)
#define DEBUG_LOG_OUTPUT_BUF_WR_POS_2    (((STRU_DebugLogOutputBuffer*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_2)->header.output_buf_wr_pos)
#define DEBUG_LOG_OUTPUT_BUF_RD_POS_2    (s_debug_log_output_buf_rd_pos_2)

#define DEBUG_LOG_INPUT_BUF_HEAD         ((char*)(((STRU_DebugLogInputBuffer*)SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR)->buf))
#define DEBUG_LOG_INPUT_BUF_TAIL         ((char*)(SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR + SRAM_DEBUG_LOG_INPUT_BUFFER_SIZE - 1))

#define DEBUG_LOG_INPUT_BUF_WR_POS       (((STRU_DebugLogInputBuffer*)SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR)->header.input_buf_wr_pos)
#define DEBUG_LOG_INPUT_BUF_RD_POS_0     (s_debug_log_input_buf_rd_pos_0)
#define DEBUG_LOG_INPUT_BUF_RD_POS_1     (s_debug_log_input_buf_rd_pos_1)
#define DEBUG_LOG_INPUT_BUF_RD_POS_2     (s_debug_log_input_buf_rd_pos_2)

#define CHECK_DEBUG_BUF_INIT_STATUS()    do { if (DLOG_CheckDebugBufInitStatus() == 0 ) return 0; } while(0)

#define SRAM_DEBUG_BUF_INIT_FLAG         0x30A5A503


#define DLOG_INPUT_MAX_CMD_PAR           (10)

typedef struct
{
    volatile uint32_t input_buf_wr_pos;
    volatile uint32_t input_buf_init_flag;
} STRU_DebugLogInputBufferHeader;

typedef struct
{
    volatile STRU_DebugLogInputBufferHeader header  __attribute__ ((aligned (4)));
    volatile char buf[1]                            __attribute__ ((aligned (4)));
} STRU_DebugLogInputBuffer;

typedef struct
{
    volatile uint32_t output_buf_wr_pos;
    volatile uint32_t output_buf_init_flag;
} STRU_DebugLogOutputBufferHeader;

typedef struct
{
    volatile STRU_DebugLogOutputBufferHeader header __attribute__ ((aligned (4)));
    volatile char buf[1]                            __attribute__ ((aligned (4)));
} STRU_DebugLogOutputBuffer;

static char *s_debug_log_output_buf_rd_pos_0 = DEBUG_LOG_OUTPUT_BUF_HEAD_0;
static char *s_debug_log_output_buf_rd_pos_1 = DEBUG_LOG_OUTPUT_BUF_HEAD_1;
static char *s_debug_log_output_buf_rd_pos_2 = DEBUG_LOG_OUTPUT_BUF_HEAD_2;

static char *s_debug_log_input_buf_rd_pos_0 = DEBUG_LOG_INPUT_BUF_HEAD;
static char *s_debug_log_input_buf_rd_pos_1 = DEBUG_LOG_INPUT_BUF_HEAD;
static char *s_debug_log_input_buf_rd_pos_2 = DEBUG_LOG_INPUT_BUF_HEAD;

// static unsigned char s_u8_commandPos;
// static unsigned char s_u8_commandLine[128];

static FUNC_CommandRun s_func_commandRun = NULL;
static FUNC_LogSave s_sd_log_func_commandRun = NULL;

// ENUM_CPU_ID CPUINFO_GetLocalCpuId(void) 
// {
//     return *((volatile ENUM_CPU_ID*)CPU_ID_INFO_ADDRESS);
// }


static unsigned char DLOG_CheckDebugBufInitStatus(void)
{
    // Check input SRAM buffer init flag 
    
    if (((volatile STRU_DebugLogInputBufferHeader*)SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR)->input_buf_init_flag != SRAM_DEBUG_BUF_INIT_FLAG) 
    {
        return 0; 
    }

    // Check output SRAM buffer init flag 
    
    unsigned int out_buf_addr;
    switch(CPUINFO_GetLocalCpuId())
    {
    case ENUM_CPU0_ID:
        out_buf_addr = SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_0;
        break;
    case ENUM_CPU1_ID:
        out_buf_addr = SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_1;
        break;
    case ENUM_CPU2_ID:
        out_buf_addr = SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_2;
        break;
    }
    
    if (((STRU_DebugLogOutputBufferHeader*)out_buf_addr)->output_buf_init_flag != SRAM_DEBUG_BUF_INIT_FLAG) 
    {
        return 0; 
    }

    return 1;
}



void DLOG_Process(void* p)
{
    while(DLOG_Output(4096))
    {
    }
}



void DLOG_Init(FUNC_CommandRun func_command, 
                  FUNC_LogSave func_log_sd,
                  ENUM_DLOG_PROCESSOR e_dlogProcessor)
{
    s_func_commandRun = func_command;
    s_sd_log_func_commandRun = func_log_sd;

    if (e_dlogProcessor == DLOG_SERVER_PROCESSOR)
    {
        s_u8_dlogServerCpuId = CPUINFO_GetLocalCpuId();
        
        ((STRU_DebugLogInputBufferHeader*)SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR)->input_buf_wr_pos = (uint32_t)DEBUG_LOG_INPUT_BUF_HEAD;
        ((STRU_DebugLogInputBufferHeader*)SRAM_DEBUG_LOG_INPUT_BUFFER_ST_ADDR)->input_buf_init_flag = SRAM_DEBUG_BUF_INIT_FLAG;

        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_0)->output_buf_wr_pos = (uint32_t)DEBUG_LOG_OUTPUT_BUF_HEAD_0;
        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_0)->output_buf_init_flag = SRAM_DEBUG_BUF_INIT_FLAG;
        
        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_1)->output_buf_wr_pos = (uint32_t)DEBUG_LOG_OUTPUT_BUF_HEAD_1;
        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_1)->output_buf_init_flag = SRAM_DEBUG_BUF_INIT_FLAG;
        
        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_2)->output_buf_wr_pos = (uint32_t)DEBUG_LOG_OUTPUT_BUF_HEAD_2;
        ((STRU_DebugLogOutputBufferHeader*)SRAM_DEBUG_LOG_OUTPUT_BUFFER_ST_ADDR_2)->output_buf_init_flag = SRAM_DEBUG_BUF_INIT_FLAG;

        // DLOG_InputCommandInit();
    }
    else
    {
        while (DLOG_CheckDebugBufInitStatus() == 0 );

        //invalidate d-cache: the ITCM2_EXT copy from the cpu0.
        SCB_InvalidateDCache_by_Addr((uint32_t *)0x2000A000, 0x6000);
    }

}

#ifdef DEBUG_LOG_USE_SRAM_OUTPUT_BUFFER

unsigned int DLOG_StrCpyToDebugOutputLogBuf(const char *src, unsigned int length)
{
    char* dst;
    char* head;
    char* tail;

    CHECK_DEBUG_BUF_INIT_STATUS();

    switch(CPUINFO_GetLocalCpuId())
    {
    case ENUM_CPU0_ID:
        dst = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_0;
        head = DEBUG_LOG_OUTPUT_BUF_HEAD_0;
        tail = DEBUG_LOG_OUTPUT_BUF_TAIL_0;
        break;
    case ENUM_CPU1_ID:
        dst = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_1;
        head = DEBUG_LOG_OUTPUT_BUF_HEAD_1;
        tail = DEBUG_LOG_OUTPUT_BUF_TAIL_1;
        break;
    case ENUM_CPU2_ID:
        dst = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_2;
        head = DEBUG_LOG_OUTPUT_BUF_HEAD_2;
        tail = DEBUG_LOG_OUTPUT_BUF_TAIL_2;
        break;
    default:
        return 0;
    }

    while ((*src) && (length--))
    {
        *dst = *src;
        if (dst >= tail)
        {
            dst = head;
        }
        else
        {
            dst++;
        }
        src++;
    }

    switch(CPUINFO_GetLocalCpuId())
    {
    case ENUM_CPU0_ID:
        DEBUG_LOG_OUTPUT_BUF_WR_POS_0 = (uint32_t)dst;
        break;
    case ENUM_CPU1_ID:
        DEBUG_LOG_OUTPUT_BUF_WR_POS_1 = (uint32_t)dst;
        break;
    case ENUM_CPU2_ID:
        DEBUG_LOG_OUTPUT_BUF_WR_POS_2 = (uint32_t)dst;
        break;
    default:
        return 0;
    }

    return 1;
}

unsigned int DLOG_Output(unsigned int byte_num)
{
    unsigned int iByte = 0;

    char **p_src;
    char* src;
    char* tmpsrc;
    char* write_pos;
    char* head;
    char* tail;
    
    unsigned char output_index;
    unsigned char enter_detected;

    char tmp_buf[256];
    unsigned int tmp_buf_index;


    CHECK_DEBUG_BUF_INIT_STATUS();

    if (CPUINFO_GetLocalCpuId() != s_u8_dlogServerCpuId)
    {
        return 0;
    }

    // Print output buffer 0,1,2 to serial 
    output_index = 0;
    while (output_index <= 2) 
    {
        switch (output_index)
        {
        case 0:
            p_src  = &DEBUG_LOG_OUTPUT_BUF_RD_POS_0;
            write_pos = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_0;
            head = DEBUG_LOG_OUTPUT_BUF_HEAD_0;
            tail = DEBUG_LOG_OUTPUT_BUF_TAIL_0;
            break;
        case 1:
            p_src  = &DEBUG_LOG_OUTPUT_BUF_RD_POS_1;
            write_pos = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_1;
            head = DEBUG_LOG_OUTPUT_BUF_HEAD_1;
            tail = DEBUG_LOG_OUTPUT_BUF_TAIL_1;
            break;
        case 2:
            p_src  = &DEBUG_LOG_OUTPUT_BUF_RD_POS_2;
            write_pos = (char*)DEBUG_LOG_OUTPUT_BUF_WR_POS_2;
            head = DEBUG_LOG_OUTPUT_BUF_HEAD_2;
            tail = DEBUG_LOG_OUTPUT_BUF_TAIL_2;
            break;
        default:
            return 0;
        }

        src = *p_src;
        tmp_buf_index = 0;
        memset(tmp_buf, 0, sizeof(tmp_buf));
        enter_detected = 0;

        while (src != write_pos)
        {
            if (tmp_buf_index < sizeof(tmp_buf))
            {
                tmp_buf[tmp_buf_index++] = *src;
            }

            if ((*src == '\n') || (*src == DEBUG_LOG_END) )
            {
                enter_detected = 1;
                *tmpsrc = *src;
            }

            if (src >= tail)
            {
                src = head;
            }
            else
            {
                src++;
            }

            if (enter_detected == 1)
            {
                
                if ((*tmpsrc != DEBUG_LOG_END))
                {
                    console_write(tmp_buf, strlen(tmp_buf));
             
                    uint8_t c_test[1] = {'\r'};
                    console_write(c_test, 1);
                    iByte += tmp_buf_index;
                }
                else
                {   
                    tmp_buf[tmp_buf_index-1]='\0';
                    console_write(tmp_buf, strlen(tmp_buf));
                    iByte += (tmp_buf_index-1);
                }
                               
                *p_src = src;

#ifdef DEBUG_LOG_OUTPUT_CPU_AFTER_CPU
                // Output cpu0, cpu1, cpu2.
                tmp_buf_index = 0;
                memset(tmp_buf, 0, sizeof(tmp_buf));
                enter_detected = 0;
#else
                // Output line by line
                break;
#endif
            }
        }

        if (iByte >= byte_num)
        {
            break;
        }

        output_index++;
    }

    return iByte;
}

// Output string when use libsimplec.a 
int puts(const char * s)
{
    unsigned int len = 0;

    while (('\n' != s[len]) && (DEBUG_LOG_END != s[len]) && (0 != s[len]))
    {
        len++;
    }
    
    // Print to buffer
    DLOG_StrCpyToDebugOutputLogBuf(s, len+1);

    return 0;
}


#else

int puts(const char * s)
{
    // Print to serial
    char c;

    CHECK_DEBUG_BUF_INIT_STATUS();

    if (CPUINFO_GetLocalCpuId() == s_u8_dlogServerCpuId)
    {
        while (*s)
        {
            c = *s++;

            if (c == '\n')
            {
                uart_putc(DEBUG_LOG_UART_PORT, '\r');
                Uart_WaitTillIdle(DEBUG_LOG_UART_PORT, UART_DEFAULT_TIMEOUTMS);
            }
            
            uart_putc(DEBUG_LOG_UART_PORT, c);
            Uart_WaitTillIdle(DEBUG_LOG_UART_PORT, UART_DEFAULT_TIMEOUTMS);
        }
    }
    
    return 0;
}

unsigned int DLOG_Output(unsigned int byte_num)
{
    return 0;
}

#endif

int dlog_set_output_level(unsigned char level)
{
    if (level <= LOG_LEVEL_INFO)
    {
        g_log_level = level;
        return 0;
    }

    return -1;
}

unsigned int dlog_get_output_level(void)
{
    return g_log_level;
}
