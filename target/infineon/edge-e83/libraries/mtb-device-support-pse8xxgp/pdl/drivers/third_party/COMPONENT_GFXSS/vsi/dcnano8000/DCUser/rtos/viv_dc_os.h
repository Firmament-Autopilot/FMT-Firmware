/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 - 2023 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/


#ifndef _VIV_DC_OS_H_
#define _VIV_DC_OS_H_

#include "viv_dc_type.h"
#if !_BAREMETAL
#include "FreeRTOS.h"
#include "task.h"
#endif
typedef struct _viv_dc_os {
    gctUINT irq;
    gctSIZE_T reg_phys_addr;
} viv_dc_os;

/***********************************/
/*  Platform specific DC Function  */
/***********************************/
gctINT viv_dc_device_init(
    gctVOID
    );

gctVOID viv_dc_device_deinit(
    gctVOID
    );

gctINT viv_dc_device_call(
    gctPOINTER args
    );

gctINT viv_dc_platform_init(
    gctPOINTER args
    );

gctVOID viv_dc_platform_deinit(
    gctPOINTER args
    );

vivSTATUS viv_os_devmem_open(
    gctVOID
    );

vivSTATUS viv_os_devmem_close(
    gctVOID
    );

vivSTATUS viv_os_get_dev_mem(
    gctUINT32 size,
    gctUINT32 *physical,
    gctPOINTER *logical
    );

vivSTATUS viv_os_free_dev_mem(
    gctVOID
    );

gctPOINTER viv_os_mem_alloc(
    gctSIZE_T size
    );

gctVOID viv_os_mem_free(
    gctPOINTER addr
    );

gctPOINTER viv_os_memset(
    viv_dc_os *os,
    gctPOINTER addr,
    gctINT value,
    gctSIZE_T num
    );

gctPOINTER viv_os_memcpy(
    gctPOINTER dst,
    gctPOINTER src,
    gctSIZE_T num
    );

gctINT viv_os_memcmp(
    gctCHAR *s1,
    gctCHAR *s2,
    gctSIZE_T n
    );

gctPOINTER dc_os_memcpy(
    gctPOINTER dst,
    gctPOINTER src,
    gctSIZE_T num
    );

gctPOINTER viv_os_file_open(
    gctCHAR* path,
    gctINT type
    );

gctINT viv_os_file_close(
    gctPOINTER p
    );

gctSIZE_T viv_os_file_read(
    gctPOINTER ptr,
    gctSIZE_T size,
    gctPOINTER p
    );

gctUINT16 viv_os_file_read_word(
    gctPOINTER p
    );

gctUINT8 viv_os_file_read_byte(
    gctPOINTER p
    );

gctUINT32 viv_os_file_read_dword(
    gctPOINTER p
    );

gctINT viv_os_file_read_long(
    gctPOINTER p
    );

gctINT viv_os_file_write(
    gctPOINTER ptr,
    gctSIZE_T size,
    gctPOINTER p
    );

gctINT dc_os_file_write_word(
    gctPOINTER p,
    gctUINT16 w
    );

gctINT dc_os_file_write_dword(
    gctPOINTER p,
    gctUINT32 dw
    );

gctINT dc_os_file_write_long(
    gctPOINTER p,
    gctINT l)
    ;

gctINT viv_os_file_seek(
    gctPOINTER p,
    gctSIZE_T offset,
    gctBOOL end
    );

gctUINT dc_os_file_tell(
    gctPOINTER p
    );

gctUINT8_PTR viv_os_fgets(
    gctPOINTER Buffer,
    gctUINT32 BufferLen,
    gctPOINTER File
    );

gctINT viv_os_fputs(
    gctPOINTER line,
    gctPOINTER file
    );

gctINT viv_os_feof(
    gctPOINTER file
    );

gctVOID viv_os_print(
    gctCHAR *message,
    ...
    );

gctVOID viv_os_sprint(
    gctCHAR *str,
    gctCHAR *message,
    ...
    );
gctVOID viv_os_fprint(
    gctPOINTER fp,
    gctCHAR *message,
    ...
    );
gctVOID viv_os_sleep(
    gctUINT32 Delay
    );

gctPOINTER
viv_os_create_window(
    gctUINT32 X,
    gctUINT32 Y,
    gctUINT32 Width,
    gctUINT32 Height,
    gctPOINTER * Window
    );

vivSTATUS
viv_os_window_draw_image(
    gctPOINTER Window,
    gctINT Left,
    gctINT Top,
    gctINT Right,
    gctINT Bottom,
    gctINT Width,
    gctINT Height,
    gctINT BitsPerPixel,
    gctPOINTER Bits
    );

gctUINT viv_os_read_reg(
    viv_dc_os *os,
    gctUINT addr
    );

gctVOID viv_os_write_reg(
    viv_dc_os *os,
    gctUINT addr,
    gctUINT data
    );

gctUINT viv_os_get_page_count(
    gctUINT size,
    gctUINT offset
    );

vivSTATUS viv_os_alloc_memory(
    viv_dc_os *os,
    gctUINT bytes,
    gctPOINTER *memory
    );

vivSTATUS viv_os_free_memory(
    viv_dc_os *os,
    gctPOINTER memory
    );

vivSTATUS viv_os_alloc_buffer(
    viv_dc_os *os,
    gctUINT32 Size,
    gctPOINTER *Handle,
    gctPOINTER *Logical,
    gctADDRESS *Physical,
    viv_pool_type *Pool
    );

vivSTATUS viv_os_free_buffer(
    viv_dc_os *os,
    gctPOINTER Handle
    );

#endif
