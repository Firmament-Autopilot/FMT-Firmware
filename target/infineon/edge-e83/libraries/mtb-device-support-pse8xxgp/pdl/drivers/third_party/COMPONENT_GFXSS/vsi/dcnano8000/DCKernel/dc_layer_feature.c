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


#include "dc_layer_feature.h"

static gctUINT32 layerIdMapTable[DC_LAYER_NUM][2] = {
    {0, 0},
    {1, 1},
    {2, 2},
};

static gcsDC_LAYERCAP gDCLayercapInfos[]= {
    {/* video layer */
        0x0,/* gcLAYERCAP_BIT_LAYER_COMPRESSION */
        0x0,/* gcLAYERCAP_BIT_LAYER_SCALE */
        0x1,/* gcLAYERCAP_BIT_LAYER_TILED */
        0x0,/* gcLAYERCAP_BIT_LAYER_ROTATION */
        0x0 /* gcLAYERCAP_BIT_LAYER_ROI */
    },
    {/* overlay layer */
        0x0,/* gcLAYERCAP_BIT_LAYER_COMPRESSION */
        0x0,/* gcLAYERCAP_BIT_LAYER_SCALE */
        0x1,/* gcLAYERCAP_BIT_LAYER_TILED */
        0x0,/* gcLAYERCAP_BIT_LAYER_ROTATION */
        0x0 /* gcLAYERCAP_BIT_LAYER_ROI */
    },
    {/* overlay layer */
        0x0,/* gcLAYERCAP_BIT_LAYER_COMPRESSION */
        0x0,/* gcLAYERCAP_BIT_LAYER_SCALE */
        0x1,/* gcLAYERCAP_BIT_LAYER_TILED */
        0x0,/* gcLAYERCAP_BIT_LAYER_ROTATION */
        0x0 /* gcLAYERCAP_BIT_LAYER_ROI */
    }
};

gctUINT _DCQueryLayerCount(
    gctVOID
    )
{
    gctUINT layer_count = 0;

    layer_count = sizeof(gDCLayercapInfos) / sizeof(gDCLayercapInfos[0]);

    return layer_count;
}

gctUINT _DCQueryLayerHWId(
    gctUINT sw_id
    )
{
    gctUINT layer_count = sizeof(gDCLayercapInfos) / sizeof(gDCLayercapInfos[0]);
    if (sw_id >= layer_count)
    {
        return 0;
    }
    return layerIdMapTable[sw_id][1];
}

vivSTATUS _DCQueryLayerFeature(
    gctUINT layer_id,
    viv_dc_layer_cap cap,
    gctUINT *value
    )
{
    switch (cap){
      case vivLAYER_CAP_DEC400_COMPRESSION:
        *value = gDCLayercapInfos[layer_id].LAYER_COMPRESSION;
        break;
      case vivLAYER_CAP_SCALE:
        *value = gDCLayercapInfos[layer_id].LAYER_SCALE;
        break;
      case vivLAYER_CAP_TILED:
        *value = gDCLayercapInfos[layer_id].LAYER_TILED;
        break;
      case vivLAYER_CAP_ROTATION:
        *value = gDCLayercapInfos[layer_id].LAYER_ROTATION;
        break;
      case vivLAYER_CAP_ROI:
        *value =  gDCLayercapInfos[layer_id].LAYER_ROI;
        break;
      default:
        break;
    }
    return vivSTATUS_OK;
}
/* [] END OF FILE */
