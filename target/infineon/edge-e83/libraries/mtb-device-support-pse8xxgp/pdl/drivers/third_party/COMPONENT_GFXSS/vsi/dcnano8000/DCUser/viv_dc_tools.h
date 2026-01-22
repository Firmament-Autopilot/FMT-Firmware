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


#ifndef _VIV_DC_TOOLS_H_
#define _VIV_DC_TOOLS_H_

#if vivENABLE_LAYER_SCALE

#include "viv_dc_util.h"
gctUINT32 get_stretch_factor(
    gctUINT32 src_size,
    gctUINT32 dest_size
    );

gctFLOAT sinc_filter(
    gctFLOAT x,
    gctINT32 radius
    );

viv_status_type calculate_sync_table(
    gctUINT8 kernel_size,
    gctUINT32 src_size,
    gctUINT32 dst_size,
    gcsFILTER_BLIT_ARRAY_PTR kernel_info
    );

gctINT viv_generate_factor(
    gctUINT32* scale_factorx,
    gctUINT32* scale_factory,
    gctUINT32  src_width,
    gctUINT32  src_height,
    gctUINT32  dst_width,
    gctUINT32  dst_height
    );
#endif

#endif