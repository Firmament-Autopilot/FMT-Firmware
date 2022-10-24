#ifndef __CMD_LINE_
#define __CMD_LINE_

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*f_cmdline)(void *);

typedef struct _cmd_entry
{
    uint8_t argc;            //count of the command argc>=1
    void (*func)(void *);    //function to exec
    uint8_t *fname;          //function name
    uint8_t *help;           //help info
}STRU_CMD_ENTRY_T;

#define END_OF_CMD_ENTRY {0, (f_cmdline)NULL, NULL, NULL}

int CMD_exec_cmd(char *cmdArray[], uint32_t cmdNum);


#ifdef __cplusplus
}
#endif

#endif