#include <string.h>
#include <stdlib.h>

#include "cmd_line.h"
#include "debuglog.h"

extern STRU_CMD_ENTRY_T g_cmdArray[];


typedef void (*fn0)(void);
typedef void (*fn1)(char *);
typedef void (*fn2)(char *, char *);
typedef void (*fn3)(char *, char *, char *);
typedef void (*fn4)(char *, char *, char *, char *);
typedef void (*fn5)(char *, char *, char *, char *, char *);
typedef void (*fn6)(char *, char *, char *, char *, char *, char *);
typedef void (*fn7)(char *, char *, char *, char *, char *, char *, char *);
typedef void (*fn8)(char *, char *, char *, char *, char *, char *, char *, char *);


static int cmd_help(void)
{
    uint32_t i=0;

    // DLOG_Critical("Please use the commands like:");
    while(NULL != g_cmdArray[i].func)
    {
        DLOG_Critical("%s %s", g_cmdArray[i].fname, g_cmdArray[i].help);
        i ++;
    }

    return 0;
}


int CMD_exec_cmd(char *cmdArray[], uint32_t cmdNum)
{
    uint32_t i =0;
    int ret;
    // char buf[64];
    if (cmdNum >= 10)
    {
        return 1;
    }

    if (0==memcmp(cmdArray[0], "help", strlen("help")))
    {
        return cmd_help();
    }

    while(NULL!= g_cmdArray[i].func)
    {
        uint8_t name_match = (0 == memcmp(cmdArray[0], g_cmdArray[i].fname, strlen((char *)g_cmdArray[i].fname)));
        uint8_t argc_match = (cmdNum >= (g_cmdArray[i].argc+1));

        if (name_match && argc_match)
        {
            switch (cmdNum-1)
            {
                case 0:
                    ((fn0)(g_cmdArray[i].func))();
                    break;

                case 1:
                    ((fn1)(g_cmdArray[i].func))(cmdArray[1]);
                    break;

                case 2:
                    ((fn2)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2]);
                    break;

                case 3:
                    ((fn3)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3]);
                    break;

                case 4:
                    ((fn4)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3], cmdArray[4]);
                    break;

                case 5:
                    ((fn5)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3], 
                                                cmdArray[4], cmdArray[5]);
                    break;

                case 6:
                    ((fn6)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3], 
                                                cmdArray[4], cmdArray[5], cmdArray[6]);
                    break;

                case 7:
                    ((fn7)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3], cmdArray[4], 
                                                cmdArray[5], cmdArray[6], cmdArray[7]);
                    break;

                case 8:
                    ((fn8)(g_cmdArray[i].func))(cmdArray[1], cmdArray[2], cmdArray[3], cmdArray[4], 
                                                cmdArray[5], cmdArray[6], cmdArray[7], cmdArray[8]);
                    break;

                default :
                    break;
           }
           break;
        }

        i++;
    }
    return ret;
}
