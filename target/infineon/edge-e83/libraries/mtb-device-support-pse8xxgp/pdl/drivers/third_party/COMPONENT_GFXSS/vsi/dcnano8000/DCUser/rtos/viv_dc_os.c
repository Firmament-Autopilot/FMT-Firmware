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


#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "viv_dc_type.h"
#include "viv_dc_os.h"
#if _BAREMETAL
#include "cy_syslib.h"
#endif

#define MAX_SIZE 0x1FA400

#define _4K_PAGE_SHIFT 12
#define _4K_PAGE_SIZE (1UL << _4K_PAGE_SHIFT)
#define _4K_PAGE_MASK (~(_4K_PAGE_SIZE -1))

#define GET_PAGE_COUNT(size, offset) \
    ((((size) + ((offset) & ~ _4K_PAGE_MASK)) + _4K_PAGE_SIZE - 1) >> _4K_PAGE_SHIFT)

gctPOINTER viv_os_file_open(
    gctCHAR* path,
    gctINT type
    )
{
    return vivNULL;
}

gctINT viv_os_file_close(
    gctPOINTER p
    )
{
    return 0;
}

gctSIZE_T viv_os_file_read(
    gctPOINTER ptr,
    gctSIZE_T size,
    gctPOINTER p
    )
{
    return 0;
}

gctINT viv_os_file_seek(
    gctPOINTER p,
    gctSIZE_T offset,
    gctBOOL end
    )
{
    return 0;
}

gctINT viv_os_file_write(
    gctPOINTER ptr,
    gctSIZE_T size,
    gctPOINTER p
    )
{
    return 0;
}

gctINT dc_os_file_write_word(gctPOINTER p, gctUINT16 w)
{
    return 0;
}

gctUINT8 viv_os_file_read_byte(
    gctPOINTER p
    )
{
    return 0;
}

gctUINT16 viv_os_file_read_word(
    gctPOINTER p
    )
{
    return 0;
}

gctUINT32 viv_os_file_read_dword(
    gctPOINTER p
    )
{
    return 0;
}

gctINT viv_os_file_read_long(
    gctPOINTER p
    )
{
    return 0;
}

gctINT dc_os_file_write_dword(
    gctPOINTER p,
    gctUINT32 dw
    )
{
    return 0;
}

gctINT dc_os_file_write_long(
    gctPOINTER p,
    gctINT l)
{
    return 0;
}

gctUINT dc_os_file_tell(
    gctPOINTER p
    )
{
    return 0;
}

gctUINT8_PTR viv_os_fgets(
    gctPOINTER Buffer,
    gctUINT32 BufferLen,
    gctPOINTER File
    )
{
    return vivNULL;
}

gctINT viv_os_fputs(
    gctPOINTER line,
    gctPOINTER file
    )
{
    return 0;
}

gctINT viv_os_feof(
    gctPOINTER file
    )
{
    return 0;
}

gctVOID viv_os_print(
    gctCHAR *message,
    ...
    )
{
#if vivENABLE_DC_DEBUG
    va_list arguments;

    va_start(arguments, message);
    vprintf(message, arguments);
    va_end(arguments);
#endif
}

gctVOID viv_os_sprint(
    gctCHAR *str,
    gctCHAR *message,
    ...
    )
{
    va_list arguments;

    va_start(arguments, message);
    vsprintf(str, message, arguments);
    va_end(arguments);
}
gctVOID viv_os_fprint(
    gctPOINTER fp,
    gctCHAR *message,
    ...
    )
{}
gctPOINTER viv_os_mem_alloc(
    gctSIZE_T size
    )
{
    if (size > MAX_SIZE)
    {
        viv_os_print("%s try to allocate oversize memory.\n", __FUNCTION__);
        return vivNULL;
    }
    else
    {
#if !_BAREMETAL
        return (gctPOINTER)pvPortMalloc(size);
#else
        return (gctPOINTER)malloc(size);
#endif
    }
}

gctVOID viv_os_mem_free(
    gctPOINTER addr
    )
{
    if(!addr)
    {
        viv_os_print("%s try to free an invalid memory.\n", __FUNCTION__);
    }
    else
    {
#if _BAREMETAL
        free((void*)addr);
#else
        vPortFree((void*)addr);
#endif
    }
}

gctPOINTER viv_os_memcpy(
    gctPOINTER dst,
    gctPOINTER src,
    gctSIZE_T num
    )
{
    gctUINT i = 0;
    gctUINT8* tsrc = (gctUINT8*) src;
    gctUINT8* tdst = (gctUINT8*) dst;

    for (i = 0; i < num; i++)
    {
        tdst[i] = tsrc[i];
    }

    return dst;
}

gctINT viv_os_memcmp(
    gctCHAR *s1,
    gctCHAR *s2,
    gctSIZE_T n
    )
{
    if (n)
        return strncmp(s1, s2, n);
    else
        return strcmp(s1, s2);
}

gctPOINTER viv_os_memset(
    viv_dc_os *os,
    gctPOINTER addr,
    gctINT value,
    gctSIZE_T num
    )
{
    gctUINT i = 0;
    gctUINT8* dst = (gctUINT8*) addr;

    for (i = 0; i < num; i++)
    {
        dst[i] = (gctUINT8)value;
    }

    return dst;
}

gctPOINTER dc_os_memcpy(
    gctPOINTER dst,
    gctPOINTER src,
    gctSIZE_T num
    )
{
    gctUINT i = 0;
    gctUINT8* tsrc = (gctUINT8*) src;
    gctUINT8* tdst = (gctUINT8*) dst;

    for (i = 0; i < num; i++)
    {
        tdst[i] = tsrc[i];
    }

    return dst;
}

vivSTATUS viv_os_devmem_open(
    gctVOID
    )
{
    return vivSTATUS_NOT_SUPPORT;
}

vivSTATUS viv_os_devmem_close(
    gctVOID
    )
{
    return vivSTATUS_NOT_SUPPORT;
}

vivSTATUS viv_os_get_dev_mem(
    gctUINT32 size,
    gctUINT32 *physical,
    gctPOINTER *logical
    )
{
    return vivSTATUS_NOT_SUPPORT;
}

vivSTATUS viv_os_free_dev_mem(
    gctVOID
    )
{
    return vivSTATUS_NOT_SUPPORT;
}

gctVOID
viv_os_sleep(
    gctUINT32 Delay
    )
{
    Cy_SysLib_Delay(Delay);
}

gctPOINTER
viv_os_create_window(
    gctUINT32 X,
    gctUINT32 Y,
    gctUINT32 Width,
    gctUINT32 Height,
    gctPOINTER * Window
)
{
    return vivNULL;
}

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
)
{
    return vivSTATUS_NOT_SUPPORT;
}

gctUINT viv_os_read_reg(
    viv_dc_os *os,
    gctUINT addr
    )
{
    gctUINT read = 0;

    read = *((gctUINT*)(os->reg_phys_addr + addr));

#if vivENABLE_DC_DEBUG
    viv_os_print(" Read [0x%08X] 0x%08X\n", addr, read);
#endif

    return read;
}

gctVOID viv_os_write_reg(
    viv_dc_os *os,
    gctUINT addr,
    gctUINT data
    )
{
    *((gctUINT*)(os->reg_phys_addr + addr)) = data;

#if vivENABLE_DC_DEBUG
    viv_os_print("Write [0x%08X] 0x%08X\n", addr, data);
#endif
}

gctUINT viv_os_get_page_count(
    gctUINT size,
    gctUINT offset
    )
{
    return GET_PAGE_COUNT(size, offset);
}

vivSTATUS viv_os_alloc_memory(
    viv_dc_os *os,
    gctUINT bytes,
    gctPOINTER *memory
    )
{
    gctPOINTER mem = vivNULL;

    /* Verify the arguments. */
    if (bytes == 0 || memory == vivNULL)
    {
        viv_os_print("%s out of memory.\n", __FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

#if !_BAREMETAL
    mem = (gctPOINTER)pvPortMalloc(bytes);
#else
    mem = (gctPOINTER)malloc(bytes);
#endif

    if (mem == vivNULL)
    {
        viv_os_print("%s out of memory.\n", __FUNCTION__);
        /* Out of memory. */
        return vivSTATUS_OOM;
    }

    viv_os_memset(vivNULL, (gctUINT8 *)mem, 0, bytes);

    /* Return pointer to the memory allocation. */
    *memory = mem;

    return vivSTATUS_OK;
}

vivSTATUS viv_os_free_memory(
    viv_dc_os *os,
    gctPOINTER memory
    )
{
    if (memory == vivNULL)
    {
        viv_os_print("%s invalid arguments.\n", __FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

#if !_BAREMETAL
    vPortFree((void*)memory);
#else
    free((void*)memory);
#endif

    memory = vivNULL;

    return vivSTATUS_OK;
}

vivSTATUS viv_os_alloc_buffer(
    viv_dc_os *os,
    gctUINT32 Size,
    gctPOINTER *Handle,
    gctPOINTER *Logical,
    gctADDRESS *Physical,
    viv_pool_type *Pool
    )
{
    gctPOINTER pointer = vivNULL;
    if(!Size || !Handle || !Logical || !Physical)
    {
        viv_os_print("%s invalid arguments.\n", __FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

#if !_BAREMETAL
    pointer = (gctPOINTER)pvPortMalloc(Size);
#else
    pointer = (gctPOINTER)malloc(Size);
#endif
    if(!pointer)
    {
        viv_os_print("%s invalid arguments.\n", __FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    *Logical = pointer;
    *Physical = (intptr_t)pointer;
    *Handle = pointer;

    return vivSTATUS_OK;
}

vivSTATUS viv_os_free_buffer(
    viv_dc_os *os,
    gctPOINTER Handle
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    if(!Handle)
    {
        viv_os_print("%s invalid arguments.\n", __FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }
#if !_BAREMETAL
    vPortFree((void*)Handle);
#else
    free((void*)Handle);
#endif
    Handle = vivNULL;

    return ret;
}
