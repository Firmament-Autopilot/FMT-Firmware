#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#ifdef  __cplusplus
extern "C"
{
#endif


#include <stdio.h>
// #include "module/console/console.h"
#include "module/console/console.h"

#define LOG_LEVEL_CRITICAL 1
#define LOG_LEVEL_ERROR 2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_INFO 4

int dlog_set_output_level(unsigned char level);
unsigned int dlog_get_output_level(void);

#define DLOG_Critical(fmt, arg...) \
do \
{ \
    {if (dlog_get_output_level() >= LOG_LEVEL_CRITICAL) \
    console_printf("CPU%d: %s\t" fmt "\n", *((int*)0x0000018C), __FUNCTION__, ##arg);} \
}while(0)

#define DLOG_Error(fmt, arg...) \
do \
{ \
    {if (dlog_get_output_level() >= LOG_LEVEL_ERROR) \
    console_printf("CPU%d: %s\t" fmt "\n", *((int*)0x0000018C), __FUNCTION__, ##arg);} \
}while(0)

#define DLOG_Warning(fmt, arg...) \
do \
{ \
    {if (dlog_get_output_level() >= LOG_LEVEL_WARNING)  \
    console_printf("CPU%d: %s\t" fmt "\n", *((int*)0x0000018C), __FUNCTION__, ##arg);} \
}while(0)

#define DLOG_Info(fmt, arg...) \
do \
{ \
    {if (dlog_get_output_level() >= LOG_LEVEL_INFO) \
    console_printf("CPU%d: %s\t" fmt "\n", *((int*)0x0000018C), __FUNCTION__, ##arg);} \
}while(0)

#define DEBUG_LOG_USE_SRAM_OUTPUT_BUFFER
#define DEBUG_LOG_OUTPUT_CPU_AFTER_CPU

#define DEBUG_LOG_UART_PORT               0
#define DEBUG_LOG_END                    (0x1f)

typedef enum
{
    DLOG_SERVER_PROCESSOR = 0,
    DLOG_CLIENT_PROCESSOR,
} ENUM_DLOG_PROCESSOR;

typedef int (*FUNC_CommandRun)(char *cmdArray[], uint32_t cmdNum);
typedef void (*FUNC_LogSave)(char *buf, uint32_t bytes);

void DLOG_Init(FUNC_CommandRun func_command, 
                  FUNC_LogSave func_log_sd,
                  ENUM_DLOG_PROCESSOR e_dlogProcessor);

unsigned int DLOG_Output(unsigned int byte_num);
void DLOG_Process(void* p);

extern volatile uint8_t sd_mountStatus;


#ifdef  __cplusplus
}
#endif


#endif
