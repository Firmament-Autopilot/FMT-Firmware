#ifndef _DRIVER_BUFFER_H
#define _DRIVER_BUFFER_H

#include <stdint.h>

int8_t COMMON_getNewBuffer(uint8_t **ppu8_drvBuf, 
                                 uint8_t *pu8_usrBuf, 
                                 uint32_t *pu32_txLenLast, 
                                 uint32_t u32_size);

#endif
