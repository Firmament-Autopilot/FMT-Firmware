/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 - 2022 Vivante Corporation
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
*****************************************************************************
*
*    The GPL License (GPL)
*
*    Copyright (C) 2014 - 2022 Vivante Corporation
*
*    This program is free software; you can redistribute it and/or
*    modify it under the terms of the GNU General Public License
*    as published by the Free Software Foundation; either version 2
*    of the License, or (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*****************************************************************************
*
*    Note: This software is released under dual MIT and GPL licenses. A
*    recipient may use this file under the terms of either the MIT license or
*    GPL License. If you wish to use only one license not the other, you can
*    indicate your decision by deleting one of the above license notices in your
*    version of this file.
*
*****************************************************************************/

#ifndef _VG_LITE_PLATFORM_H
#define _VG_LITE_PLATFORM_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "stdint.h"
#include "stdlib.h"
#include <stdio.h>
#include "../vg_lite_debug.h"
#include "../vg_lite_type.h"
#include "../vg_lite_option.h"

#ifndef _BAREMETAL
#define _BAREMETAL 1
#endif
#define VG_SYSTEM_RESERVE_COUNT 1

/* Implementation of list. ****************************************/
typedef struct list_head {
    struct list_head *next;
    struct list_head *prev;
}list_head_t;

typedef struct heap_node {
    list_head_t list;
    uint32_t offset;
    unsigned long size;
    int32_t status;
    vg_lite_vidmem_pool_t pool;
}heap_node_t;

typedef struct vg_module_parameters
{

    uint32_t        register_mem_base;
    uint32_t        gpu_mem_base[VG_SYSTEM_RESERVE_COUNT];

    volatile void * contiguous_mem_base[VG_SYSTEM_RESERVE_COUNT];
    uint32_t        contiguous_mem_size[VG_SYSTEM_RESERVE_COUNT];
}
vg_module_parameters_t;

/*!
@brief Initialize the hardware mem setting.
*/
void vg_lite_init_mem(vg_module_parameters_t *param);

/*!
@brief The hardware IRQ handler.
*/
void vg_lite_IRQHandler(void);

#if defined(__cplusplus)
}
#endif

#endif
