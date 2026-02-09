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


#ifndef _VIV_DC_LAYER_FEATURE_H_
#define _VIV_DC_LAYER_FEATURE_H_
#include "viv_dc_type.h"

#define DC_LAYER_NUM 3
#define DC_DISPLAY_NUM 1
#define DC_CURSOR_NUM 1

typedef struct {
    gctUINT32 LAYER_COMPRESSION:1;
    gctUINT32 LAYER_SCALE:1;
    gctUINT32 LAYER_TILED:1;
    gctUINT32 LAYER_ROTATION:1;
    gctUINT32 LAYER_ROI:1;
} gcsDC_LAYERCAP;

gctUINT _DCQueryLayerCount(
    gctVOID
    );

gctUINT _DCQueryLayerHWId(
    gctUINT sw_id
    );

vivSTATUS _DCQueryLayerFeature(
    gctUINT layer_id,
    viv_dc_layer_cap cap,
    gctUINT *value
    );
#endif
