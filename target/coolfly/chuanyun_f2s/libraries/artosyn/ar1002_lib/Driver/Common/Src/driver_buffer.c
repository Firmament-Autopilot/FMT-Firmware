#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "driver_buffer.h"
#include "debuglog.h"
#include "memory.h"

int8_t COMMON_getNewBuffer(uint8_t **ppu8_drvBuf, uint8_t *pu8_usrBuf, uint32_t *pu32_txLenLast, uint32_t u32_size)
{
    if (NULL == *ppu8_drvBuf)
    {
        *ppu8_drvBuf = rt_malloc(u32_size);
        if (NULL == *ppu8_drvBuf)
        {
            *pu32_txLenLast = 0;
            DLOG_Error("malloc error");
            return -1;
        }
        else
        {
            *pu32_txLenLast = u32_size;
        }
    }
    else
    {
        if (0 != *pu32_txLenLast)
        {
            //DLOG_Info("line = %d, u32_size = %d, *txLenLast = %d", __LINE__, u32_size, *txLenLast);
            if ((u32_size > *pu32_txLenLast) || (u32_size < (*pu32_txLenLast/4) && *pu32_txLenLast >= 256))
            {
                *ppu8_drvBuf = rt_realloc(*ppu8_drvBuf, u32_size);
                if (NULL == *ppu8_drvBuf)
                {
                    *pu32_txLenLast = 0;
                    DLOG_Error("realloc error, size = %ld", u32_size);
                    return -1;
                }
                else
                {
                    *pu32_txLenLast = u32_size;
                    //DLOG_Info("line = %d", __LINE__);
                }
            }
            else
            {
                //DLOG_Warning("keep current length");
            }
        }        
    }

    memcpy(*ppu8_drvBuf, pu8_usrBuf, u32_size);

    return 0;
}
