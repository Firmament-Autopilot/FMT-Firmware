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


#ifndef _VIV_DC_DATABASE_H_
#define _VIV_DC_DATABASE_H_
#include "viv_dc_type.h"

/*dc feature*/
typedef struct {
    gctUINT32 chipID;
    gctUINT32 chipVersion;
    gctUINT32 productID;
    gctUINT32 ecoID;
    gctUINT32 customerID;
    gctUINT32 patchVersion;
    gctUINT32 formalRelease;
    gctUINT32 DC_DISPLAY_COUNT:8;
    gctUINT32 DC_LAYER_COUNT:8;
    gctUINT32 DC_CURSOR_COUNT:8;
    gctUINT32 DC_GAMMA_BIT_OUT:8;
    gctUINT32 DC_SECURITY:1;
    gctUINT32 DC_MMU:1;
    gctUINT32 DC_CURSOR_VERSION:1;
    gctUINT32 DC_CSC_MODULE:1;
    gctUINT32 DC_3D_LUT:1;
    gctUINT32 DC_DE_GAMMA:1;
    gctUINT32 DC_DP:1;
    gctUINT32 DC_DP_YUV:1;
    gctUINT32 DC_DPI:1;
    gctUINT32 DC_DBI:1;
    gctUINT32 DC_NEW_GAMMA:1;
    gctUINT32 DC_COLOR_BAR:1;
    gctUINT32 DC_CRC:1;
    gctUINT32 DC_40BIT_ADDRESS:1;
    gctUINT32 DC_WRITEBACK:1;
    gctUINT32 DC_PROGRAM_WB:1;
    gctUINT32 DC_CUSTOMER_TILE4X4:1;
    gctUINT32 DC_DUAL_OS;
} gcsDC_FEATURES;

gcsDC_FEATURES* _DCQueryFeatures(
    gctUINT32 ChipID,
    gctUINT32 ChipVersion,
    gctUINT32 ProductID,
    gctUINT32 EcoID,
    gctUINT32 CustomerID
    );
#endif
