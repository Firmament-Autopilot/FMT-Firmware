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


#include "viv_dc_setting.h"
#include "viv_dc_interface.h"
#include "viv_dc_tools.h"

#include "viv_dc_core.h"
#include "viv_dc_database.h"
#include "dc_layer_feature.h"
#include <string.h>

#ifdef RTOS
#include "viv_dc_os.h"
#else
#include "viv_dc_platform.h"
#endif

#if vivENABLE_LAYER_SCALE
#define SCALE_DOWN_LIMITATION  3.0
#endif

#if vivENABLE_DISPLAY_CLRBAR
/*color bar range from 0 to 15*/
#define COLOR_BAR_RANGE_MAX 15
#endif

#if vivENABLE_DISPLAY_CRC
#define CRC_RECT_MAX_WIDTH 1920
#define CRC_RECT_MAX_HEIGHT 252
#endif

typedef struct _context{
#if vivENABLE_LAYER_ROI
    viv_dc_rect roiRect[DC_LAYER_NUM];
    gctBOOL roiEnable[DC_LAYER_NUM];
#endif

#if vivENABLE_LAYER_ROT
    viv_rotation_type rot[DC_LAYER_NUM];
#endif

    gctUINT32 layerWidth[DC_LAYER_NUM];
    gctUINT32 layerHeight[DC_LAYER_NUM];
}
Context;

static gctBOOL featureTable[vivFEATURE_COUNT];
static gctUINT currentLayer = 0;
#if vivENABLE_LAYER_SCALE //IFX - Fix Warning. Variable set but never used
static Context context;
#endif
#if vivENABLE_DISPLAY_CRC //IFX - Fix Warning. Variable set but never used
static viv_display_size_type curSizeType[DC_DISPLAY_NUM];
#endif
static gctUINT curCustomWidth = 0;
static gctUINT curCustomHeight = 0;
static gctBOOL Features[vivFEATURE_COUNT];

#if (vivENABLE_DISPLAY_DP && vivENABLE_DISPLAY_R2Y)
gctBOOL viv_is_dp_yuv (
    gctUINT32 output_format
    )
{
    gctBOOL dp_yuv = vivFALSE;

    switch(output_format){
        case vivDPYUV420B8CFG1:
        case vivDPYUV420B8CFG2:
        case vivDPYUV422B8CFG1:
        case vivDPYUV422B8CFG2:
        case vivDPYUV444B8CFG1:
        case vivDPYUV444B8CFG2:
        case vivDPYUV420B10CFG1:
        case vivDPYUV420B10CFG2:
        case vivDPYUV422B10CFG1:
        case vivDPYUV422B10CFG2:
        case vivDPYUV444B10CFG1:
        case vivDPYUV444B10CFG2:
            dp_yuv = vivTRUE;
            break;

        default:
            break;
    }
    return dp_yuv;
}
#endif

vivSTATUS _viv_calculate_resolution(
    viv_display_size_type *display_size,
    gctUINT *width,
    gctUINT *height
    )
{
    gctINT32 m = 0;

    for (m = 0; m < featureTable[vivFEATURE_DISPLAY_COUNT]; m++)
    {
        switch (display_size[m])
        {
            case vivDISPLAY_320_480_60:
                width[m] = 320;
                height[m] = 480;
                break;

            case vivDISPLAY_480_800_60:
                width[m] = 480;
                height[m] = 800;
                break;

            case vivDISPLAY_480_864_60:
                width[m] = 480;
                height[m] = 864;
                break;

            case vivDISPLAY_640_480_60:
                width[m] = 640;
                height[m] = 480;
                break;

            case vivDISPLAY_720_480_60:
                width[m] = 720;
                height[m] = 480;
                break;

            case vivDISPLAY_800_480_60:
                width[m] = 800;
                height[m] = 480;
                break;

            case vivDISPLAY_1024_600_60:
                width[m] = 1024;
                height[m] = 600;
                break;

            case vivDISPLAY_1024_768_60:
                width[m] = 1024;
                height[m] = 768;
                break;

            case vivDISPLAY_1280_720_60:
                width[m] = 1280;
                height[m] = 720;
                break;

            case vivDISPLAY_1920_1080_60:
                width[m] = 1920;
                height[m] = 1080;
                break;

            case vivDISPLAY_3840_2160_30:
                width[m] = 3840;
                height[m] = 2160;
                break;

            case vivDISPLAY_3840_2160_60:
                width[m] = 3840;
                height[m] = 2160;
                break;

            case vivDISPLAY_4096_2160_60:
                width[m] = 4096;
                height[m] = 2160;
                break;

            case vivDISPLAY_5760_756_60:
                width[m] = 5760;
                height[m] = 756;
                break;

            case vivDISPLAY_CUSTOMIZED:
                width[m] = curCustomWidth;
                height[m] = curCustomHeight;
                break;

            default:
                viv_print("current not support display size锛乗n");
                return vivSTATUS_NOT_SUPPORT;
            }
    }

    return vivSTATUS_OK;
}

/* Set dither.
 * iface.u.dither.enable:        Enable dither or not.
 * iface.u.dither.red_channel:   Significant bit width for red channel.
 * iface.u.dither.green_channel: Significant bit width for green channel.
 * iface.u.dither.blue_channel:  Significant bit width for blue channel.
 * iface.u.dither.table_low:     Dither table of refreence value is 64bits.
 *                               These are the lower 32 bits.
 *                               Y0_X0    3:0  Dither reference value at (0, 0)
 *                               Y0_X1    7:4  Dither reference value at (1, 0)
 *                               Y0_X2   11:8  Dither reference value at (2, 0)
 *                               Y0_X3  15:12  Dither reference value at (3, 0)
 *                               Y1_X0  19:16  Dither reference value at (0, 1)
 *                               Y1_X1  23:20  Dither reference value at (1, 1)
 *                               Y1_X2  27:24  Dither reference value at (2, 1)
 *                               Y1_X3  31:28  Dither reference value at (3, 1)
 * iface.u.dither.table_high:    Dither table of refreence value is 64bits.
 *                               These are the high 32 bits.
 *                               Y2_X0    3:0  Dither reference value at (0, 2)
 *                               Y2_X1    7:4  Dither reference value at (1, 2)
 *                               Y2_X2   11:8  Dither reference value at (2, 2)
 *                               Y2_X3  15:12  Dither reference value at (3, 2)
 *                               Y3_X0  19:16  Dither reference value at (0, 3)
 *                               Y3_X1  23:20  Dither reference value at (1, 3)
 *                               Y3_X2  27:24  Dither reference value at (2, 3)
 *                               Y3_X3  31:28  Dither reference value at (3, 3)
 */
gctINT viv_set_dither(
    viv_display display,
    gctBOOL enable
    )
{
    viv_interface iface;

    iface.command = vivIFACE_DITHER;
    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.u.dither.display_id = display;

    iface.u.dither.enable = enable;
    iface.u.dither.table_low = 0x7B48F3C0;
    iface.u.dither.table_high = 0x596AD1E2;

    return viv_dc_device_call(&iface);
}

#if vivENABLE_WRITEBACK
/* Set write back dither.
 * iface.u.wb_dither.enable:        Enable write back dither or not.
 * iface.u.wb_dither.table_low:     Dither table of refreence value is 64bits.
 *                               These are the lower 32 bits.
 *                               Y0_X0    3:0  Dither reference value at (0, 0)
 *                               Y0_X1    7:4  Dither reference value at (1, 0)
 *                               Y0_X2   11:8  Dither reference value at (2, 0)
 *                               Y0_X3  15:12  Dither reference value at (3, 0)
 *                               Y1_X0  19:16  Dither reference value at (0, 1)
 *                               Y1_X1  23:20  Dither reference value at (1, 1)
 *                               Y1_X2  27:24  Dither reference value at (2, 1)
 *                               Y1_X3  31:28  Dither reference value at (3, 1)
 * iface.u.wb_dither.table_high:    Dither table of refreence value is 64bits.
 *                               These are the high 32 bits.
 *                               Y2_X0    3:0  Dither reference value at (0, 2)
 *                               Y2_X1    7:4  Dither reference value at (1, 2)
 *                               Y2_X2   11:8  Dither reference value at (2, 2)
 *                               Y2_X3  15:12  Dither reference value at (3, 2)
 *                               Y3_X0  19:16  Dither reference value at (0, 3)
 *                               Y3_X1  23:20  Dither reference value at (1, 3)
 *                               Y3_X2  27:24  Dither reference value at (2, 3)
 *                               Y3_X3  31:28  Dither reference value at (3, 3)
 */
vivSTATUS viv_set_write_back_dither(
    viv_display display,
    gctBOOL enable
    )
{
    viv_interface iface;

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (!featureTable[vivFEATURE_PROGRAM_WB])
    {
        viv_print("The write back dither is not exist.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_WB_DITHER;
    iface.u.wb_dither.display_id = display;

    if (enable)
    {
        iface.u.wb_dither.enable = SET_ENABLE;
        iface.u.wb_dither.table_low = 0x7B48F3C0;
        iface.u.wb_dither.table_high = 0x596AD1E2;
    }
    else
    {
        iface.u.wb_dither.enable = SET_DISABLE;
    }

    return viv_dc_device_call(&iface);
}
#endif

#if vivENABLE_DISPLAY_3DLUT
/* This function sets 3D LUT table.
* enable: Enable 3D-LUT. When set to 1, 3D-LUT is enabled.
* 3d_lut: Pointer to lookup table for 3D-LUT.
*/
vivSTATUS viv_set_3d_lut(
    viv_display display,
    gctBOOL enable,
    gctUINT32* threed_lut
    )
{
    viv_interface iface;
    gctUINT32 i = 0;
    gctINT32 ret = 0;

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_3D_LUT;
    iface.u.threed_lut.display_id = display;
    iface.u.threed_lut.enable = enable;

    for (i = 0; i < THREED_LUT_SIZE; i++)
    {
        iface.u.threed_lut.index = i;
        iface.u.threed_lut.lut = *(threed_lut + i);

        ret = viv_dc_device_call(&iface);
        if (ret < 0)
        {
            return ret;
        }
    }

    return vivSTATUS_OK;
}

/* This function sets the enlarge value for 3D LUT.
*  value: enlarge value.
*/
vivSTATUS viv_set_3d_lut_enlarge(
    viv_display display,
    viv_lut_enlarge value
    )
{
    viv_interface iface;

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_3D_LUT_ENLARGE;
    iface.u.threed_lut.display_id = display;
    iface.u.threed_lut.enlarge = value;

    return viv_dc_device_call(&iface);
}
#endif

/* Pass value to DC register and get the read value if want.
 * The reset variable is for contigious write/read to clear register state.
 * Instant valid. No need to call commit.
 */
gctINT viv_set_register(
    gctUINT32 offset,
    gctUINT32 write,
    gctUINT32* read,
    gctBOOL reset
    )
{
    gctINT ret;
    viv_interface iface;

    if (reset)
        iface.command = vivIFACE_REGISTER_RESET;
    else
        iface.command = vivIFACE_REGISTER;

    iface.u.registers.offset = offset;
    iface.u.registers.write = write;

    if ((ret = viv_dc_device_call(&iface)) == 0 &&
        read != vivNULL)
    {
        *read = iface.u.registers.read;
    }

    return ret;
}

gctINT viv_read_register(
    gctUINT32 offset,
    gctUINT32* read
    )
{
    gctINT ret;
    viv_interface iface;

    iface.command = vivIFACE_READ_REGISTER;
    iface.u.registers.offset = offset;

    if ((ret = viv_dc_device_call(&iface)) == 0 &&
        read != vivNULL)
    {
        *read = iface.u.registers.read;
    }

    return ret;
}

gctINT viv_alloc_buffer(
    gctSIZE_T Size,
    gctPOINTER * Handle,
    gctADDRESS * HardwareAddress,
    gctPOINTER * Logical,
    gctBOOL   security,
    viv_pool_type Pool
    )
{
    gctINT ret;
    viv_interface iface;

    iface.command = vivIFACE_ALLOC_BUFFER;

    viv_query_chipinfo(Features);
    if((!Features[gcvFEATURE_DC_MMU]) && (Pool == gcvPOOL_DEFAULT))
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        viv_print("Invalid Argument: DC which does not support MMU should set Pool to gcvPOOL_CONTIGUOUS! ");
        return ret;
    }

    iface.u.alloc.size = Size;
    iface.u.alloc.pool = Pool;
    iface.u.alloc.security = security;

    ret = viv_dc_device_call(&iface);

    if (ret == vivSTATUS_OK)
    {
        *Handle = (gctPOINTER)iface.u.alloc.handle;
        *HardwareAddress = iface.u.alloc.hardwareAddress;
        *Logical = (gctPOINTER)iface.u.alloc.logical;
        viv_os_memset(vivNULL, *Logical,0,Size);
    }

    return ret;
}

gctINT viv_free_buffer(
    gctPOINTER Handle
    )
{
    gctINT ret;
    viv_interface iface;
    if(!Handle)
        return vivSTATUS_INVALID_ARGUMENTS;
    iface.command = vivIFACE_FREE_BUFFER;
#if USE_ARCH64
    iface.u.free.handle = (gctUINT64)Handle;
#else
    iface.u.free.handle = (gctUINT32)Handle;
#endif

    ret = viv_dc_device_call(&iface);

    return ret;
}

#if vivENABLE_MMU
gctINT viv_map_buffer(
    gctUINT size,
    gctUINT physicalAddr,
    gctUINT *dcVirtualAddr,
    gctBOOL security,
    viv_pool_type pool
    )
{
    gctINT ret;
    viv_interface iface;
    if(!size || !physicalAddr || !dcVirtualAddr)
        return vivSTATUS_INVALID_ARGUMENTS;
    if(Features[vivFEATURE_MMU] == 0)
    {
        viv_print("MMU is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    iface.command = vivIFACE_MEMORY_MAP;
    iface.u.memory_map.security = security;
    iface.u.memory_map.pool = pool;
    iface.u.memory_map.size = size;
    iface.u.memory_map.physical = physicalAddr;
    ret = viv_dc_device_call(&iface);
    if(vivSTATUS_OK == ret)
    {
        *dcVirtualAddr = iface.u.memory_map.dpu_addrress;
    }
    return ret;
}

gctINT viv_unmap_buffer(
    gctUINT size,
    gctUINT dcVirtualAddr
    )
{
    viv_interface iface;
    if(!size || !dcVirtualAddr)
        return vivSTATUS_INVALID_ARGUMENTS;
    if(Features[vivFEATURE_MMU] == 0)
    {
        viv_print("MMU is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    iface.command = vivIFACE_MEMORY_UNMAP;
    iface.u.memory_unmap.size = size;
    iface.u.memory_unmap.dpu_addrress = dcVirtualAddr;
    return viv_dc_device_call(&iface);
}
#endif

#if vivENABLE_LAYER_ROI
gctINT viv_layer_roi_enable(
    gctBOOL enable
    )
{
    viv_interface iface;
    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_ROI_ENABLE;
    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.u.roi_enable.roi_enable = enable;

    context.roiEnable[currentLayer] = enable;
    return viv_dc_device_call(&iface);
}

vivSTATUS viv_layer_roi_rect(
    viv_dc_rect *rect
    )
{
    viv_interface iface;
    iface.command = vivIFACE_LAYER;
    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_RECT;
    if (!rect)
    {
        viv_print("The input rect is illegal.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    dc_os_memcpy(&iface.u.layer.u.roi_rect.roi_rect,rect,sizeof(viv_dc_rect));

    dc_os_memcpy(&context.roiRect[currentLayer], rect, sizeof(viv_dc_rect));

    return viv_dc_device_call(&iface);
}
#endif

vivSTATUS viv_query_chipinfo(
    gctBOOL *Features
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    gcsDC_FEATURES * feature;
    viv_interface_query_chip_identity identity;
    viv_interface iface;

    if(!Features)
    {
        viv_print("Invalid Argument: Features=%p in %s\n",Features,__FUNCTION__);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_QUERY;
    iface.u.query.cmd = vivQUERY_CHIP_IDENTITY;
    ret = (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.

    dc_os_memcpy(&identity, &iface.u.query.u.queryChipIdentity, sizeof(viv_interface_query_chip_identity));

    feature =
        _DCQueryFeatures(
            identity.chipModel,
            identity.chipRevision,
            identity.productID,
            identity.ecoID,
            identity.customerID
    );

    if (feature == gcvNULL)
    {
        viv_print("Could not find matched hw.\n");
        return vivSTATUS_FAILED;
    }

    Features[vivFEATURE_DISPLAY_COUNT] = feature->DC_DISPLAY_COUNT;
    Features[vivFEATURE_LAYER_COUNT] = feature->DC_LAYER_COUNT;
    Features[vivFEATURE_CURSOR_COUNT] = feature->DC_CURSOR_COUNT;
    Features[vivFEATURE_GAMMA_BIT_OUT] = feature->DC_GAMMA_BIT_OUT;
    Features[vivFEATURE_SECURITY] = feature->DC_SECURITY;
    Features[vivFEATURE_MMU] = feature->DC_MMU;
    Features[vivFEATURE_CURSOR_VERSION] = feature->DC_CURSOR_VERSION;
    Features[vivFEATURE_CSC_MOUDLE] = feature->DC_CSC_MODULE;
    Features[vivFEATURE_3D_LUT] = feature->DC_3D_LUT;
    Features[vivFEATURE_DE_GAMMA] = feature->DC_DE_GAMMA;
    Features[vivFEATURE_DP] = feature->DC_DP;
    Features[vivFEATURE_DP_YUV] = feature->DC_DP_YUV;
    Features[vivFEATURE_DPI] = feature->DC_DPI;
    Features[vivFEATURE_DBI] = feature->DC_DBI;
    Features[vivFEATURE_NEW_GAMMA] = feature->DC_NEW_GAMMA;
    Features[vivFEATURE_COLOR_BAR] = feature->DC_COLOR_BAR;
    Features[vivFEATURE_CRC] = feature->DC_CRC;
    Features[vivFEATURE_40BIT_ADDRESS] = feature->DC_40BIT_ADDRESS;
    Features[vivFEATURE_WRITEBACK] = feature->DC_WRITEBACK;
    Features[vivFEATURE_PROGRAM_WB] = feature->DC_PROGRAM_WB;
    Features[vivFEATURE_CUSTOMER_TILE4X4] = feature->DC_CUSTOMER_TILE4X4;
    Features[vivFEATURE_DUAL_OS] = feature->DC_DUAL_OS;
    return ret;
}

vivSTATUS viv_layer_query_capability(
  gctUINT layer_id,
  viv_dc_layer_cap cap,
  gctUINT *value
  )
{
    gctUINT layer_count = _DCQueryLayerCount();

    if ((layer_id >= layer_count) || (cap >= vivLAYER_CAP_COUNT))
    {
        viv_print("layer id or cap out of boundary!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    _DCQueryLayerFeature(layer_id, cap, value);
    return vivSTATUS_OK;
}

vivSTATUS viv_dc_query_feature(
    viv_dc_features features,
    gctUINT* value
  )
{
  if (features >= vivFEATURE_COUNT)
  {
      viv_print("feature num out of boundary!\n");
      return vivSTATUS_INVALID_ARGUMENTS;
  }
  *value = featureTable[features];
  return vivSTATUS_OK;
}


/* Open DC device and initialize other platform related function.
 * This function should be called at the beginning of DC module.
 */
vivSTATUS viv_dc_init(
  gctVOID
  )
{
  vivSTATUS stat; //IFX - Fix Warning typecast needed.
  stat = (vivSTATUS)viv_dc_device_init();
  if (stat != vivSTATUS_OK)
  {
    viv_print("viv dc device initial failed.\n");
    return stat;
  }
  stat = (vivSTATUS)viv_dc_platform_init(vivNULL);
  if (stat != vivSTATUS_OK)
  {
    viv_print("viv dc platform initial failed.\n");
    return stat;
  }
  stat = viv_query_chipinfo(featureTable);
  if (stat != vivSTATUS_OK)
  {
    viv_print("viv dc query chipinfo failed.\n");
    return stat;
  }
   return stat;
}

/* Close DC platform and device.
 * This function should be called at the end of DC module.
 */
vivSTATUS viv_dc_deinit(
  gctVOID
  )
{
  vivSTATUS ret = vivSTATUS_OK;
  viv_dc_platform_deinit(vivNULL);
  viv_dc_device_deinit();
  return ret;
}

/* This function selects a specified video layer
 */
vivSTATUS viv_dc_select_layer(
  gctUINT layer_id
  )
{
    if (layer_id >= featureTable[vivFEATURE_LAYER_COUNT]) {
        viv_print("The layer id =%d is out of range\n",layer_id);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    currentLayer = layer_id;

    return vivSTATUS_OK;
}

/* This function sets the layer stride, size, and format  for each planar.
 */
vivSTATUS viv_layer_set(
  viv_dc_buffer *buffer
  )
{
    viv_interface iface;

#if vivENABLE_ADDRESS_40BITS
    if(Features[vivFEATURE_40BIT_ADDRESS] == 0)
    {
        buffer->phyAddress[0] &= 0x00FFFFFFFF;
        buffer->phyAddress[1] &= 0x00FFFFFFFF;
        buffer->phyAddress[2] &= 0x00FFFFFFFF;
    }
#endif

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_CMD_BUFFER;

    dc_os_memcpy(&iface.u.layer.u.buffer.buffer, buffer, sizeof(viv_dc_buffer));

#if vivENABLE_LAYER_SCALE //IFX: Fix IAR warning. Variable context set but not used
    context.layerWidth[currentLayer] = buffer->width;
    context.layerHeight[currentLayer] = buffer->height;
#endif
    return (vivSTATUS)viv_dc_device_call(&iface);
}

/* This function sets YUV to RGB with the set csc mode. */
vivSTATUS viv_layer_set_y2r(
  gctBOOL yuvClamp,
  viv_csc_mode mode,
  gctINT *coef,
  gctUINT num
  )
{
    viv_interface iface;

    if(!featureTable[vivFEATURE_CSC_MOUDLE])
    {
        viv_print("Invalid Argument: Not support csc moudle!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_SET_CSC_Y2R;
    iface.u.layer.layer_id = currentLayer;

    if(mode == vivCSC_USER_DEF)
    {
        if(coef == vivNULL)
        {
            viv_print("[viv_dc_setting viv_layer_set_y2r] Invalid Argument: Null Pointer!\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        if(((!!yuvClamp) && (num != YUV2RGB_LR_COEF_NUM)) ||
           ((!yuvClamp) && (num != YUV2RGB_FR_COEF_NUM))
          )
        {
            viv_print("[viv_dc_setting viv_layer_set_y2r] Invalid Argument: The number of user define parameters is not qualified.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        dc_os_memcpy(iface.u.layer.u.y2r.coef, coef, num * sizeof(gctINT));
    }

    iface.u.layer.u.y2r.yuvClamp = yuvClamp;
    iface.u.layer.u.y2r.mode = mode;
    iface.u.layer.u.y2r.num = num;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets RGB to RGB in different csc mode.
 *  @viv_csc_mode
 *              viv_csc_BT709 means RGB2020 to RGB709.
 *              viv_csc_BT2020 means RGB709 to RGB2020.
 */
vivSTATUS viv_layer_set_r2r(
  gctBOOL enable,
  viv_csc_mode mode,
  gctINT *coef,
  gctUINT num
  )
{
    viv_interface iface;

    if(!featureTable[vivFEATURE_CSC_MOUDLE])
    {
        viv_print("Invalid Argument: Not support csc moudle!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_SET_CSC_R2R;
    iface.u.layer.layer_id = currentLayer;

    if(enable)
    {
        if(mode == vivCSC_BT601)
        {
            viv_print("There is no default coeffient form RGB709 to RGB601 or RGB2020 to RGB601.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        if(mode == vivCSC_USER_DEF)
        {
            if(coef == vivNULL)
            {
                viv_print("[viv_dc_setting viv_layer_set_r2r] Invalid Argument: Null Pointer!\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }

            if(num != RGB2RGB_COEF_NUM)
            {
                viv_print("[viv_dc_setting viv_layer_set_r2r] Invalid Argument: The number of user define parameters is not qualified.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }

            dc_os_memcpy(iface.u.layer.u.r2r.coef, coef, num * sizeof(gctINT));
        }

        iface.u.layer.u.r2r.enable = SET_ENABLE;
        iface.u.layer.u.r2r.mode = mode;
        iface.u.layer.u.r2r.num = num;
    }
    else
    {
        iface.u.layer.u.r2r.enable = SET_DISABLE;
    }

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_layer_clear(
    viv_dc_color *clearColor,
    gctBOOL enable
    )
{
    viv_interface iface;
    iface.command = vivIFACE_LAYER;
    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_CLEAR;
    if(!clearColor)
    {
        viv_print("The input clearColor is illegal.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    dc_os_memcpy(&iface.u.layer.u.clear.clear_color,clearColor,sizeof(viv_dc_color));
    if (enable)
        iface.u.layer.u.clear.clear_color_enable = SET_ENABLE;
    else
        iface.u.layer.u.clear.clear_color_enable = SET_DISABLE;
    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_layer_set_position(
    gctUINT x,
    gctUINT y
    )
{
    viv_interface iface;
    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_SET_POSITION;
    iface.u.layer.layer_id =  currentLayer;
    iface.u.layer.u.position.x = x;
    iface.u.layer.u.position.y = y;
    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets colorkey related configuration for layer.
 */
vivSTATUS viv_layer_colorkey(
    viv_dc_color *colorkey,
    viv_dc_color *colorkeyHigh,
    gctBOOL transparency
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_COLORKEY;
    iface.u.layer.u.colorkey.transparency = transparency;
    dc_os_memcpy(&iface.u.layer.u.colorkey.colorkey, colorkey, sizeof(viv_dc_color));
    dc_os_memcpy(&iface.u.layer.u.colorkey.colorkey_high, colorkeyHigh, sizeof(viv_dc_color));

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_DISPLAY_NEWGMMA
vivSTATUS viv_new_gamma_init(
    viv_dc_gamma  *gamma
    )
{
    gctUINT i, table_value;
    gctFLOAT tmpf0, tmpf1;
    gctUINT table0[17] = {0};
    gctUINT table1[257] = {0};

    if(gamma== vivNULL)
    {
        viv_print("[viv_dc_setting viv_new_gamma_init] Invalid Argument: Null Pointer!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    for(i = 0; i <= 16; i++)
    {
        tmpf0 = (gctFLOAT)(i/1024.f * 10000.f);
        tmpf1 = viv_util_dc_to_gamma(tmpf0);
        table0[i] = (gctUINT)(tmpf1*4095.f + 0.95f);
    }

    for(i = 4; i < 256; i++)
    {
        tmpf0 = (gctFLOAT)(i/256.f * 10000.f);
        tmpf1 = viv_util_dc_to_gamma(tmpf0);
        table1[i] = (gctUINT)(tmpf1*4095.f + 0.5f);
    }
    table1[256] = 4095;

    /* final table construct */
    for(i = 0; i < GAMMA_TABLE_SIZE; i++)
    {
        /* When input data is less than 32, directly look up the table
         * Direct look up needs 32 entries
         */
        if(i < 32)
        {
            tmpf0 = (gctFLOAT)(i/1024.f * 10000.f);
            tmpf1 = viv_util_dc_to_gamma(tmpf0);
            table_value = (gctUINT)(tmpf1*(16384 - 1.f));
        }

        /* When input data >=32 and < 256, look up the table and then do interpolation
         * Each interval has 16 data. [32,48),[48,64), ...[240,256).
         * It needs 15 entries
         */
        else if(i < 47)
            table_value = table0[i-30]; /* use table0[2] - [16] */

        /* When input data >=256, look up the  table and then do interpolation
         * Each interval has 64 data. [256,320),[320,384) ...[16320,12384)
         * It needs 252+1 entries.  Extra 1 is for 10384 look up.
         */
        else
            table_value = table1[i-43]; /* use table1[4] - [256] */

        gamma->gammaTable[i][0] = table_value & 0xFFF;
        gamma->gammaTable[i][1] = table_value & 0xFFF;
        gamma->gammaTable[i][2] = table_value & 0xFFF;
    }
    return vivSTATUS_OK;
}
#endif

vivSTATUS viv_gamma_init(
    viv_dc_gamma* gamma,
    gctFLOAT gamma_value
    )
{
    gctINT i;
    gctFLOAT tmpf;
    gctUINT16 temp = 0;

    for (i=0; i < 256; i++)
    {
        tmpf = (i + 0.5f)/256.0f;
        tmpf = (gctFLOAT)(vivPOW((gctDOUBLE)tmpf, (gctDOUBLE)1/gamma_value));
        temp = (gctUINT16)(tmpf*(1<<Features[vivFEATURE_GAMMA_BIT_OUT]) - 0.5f);

        gamma->gammaTable[i][0] = temp & ((1<<Features[vivFEATURE_GAMMA_BIT_OUT])-1);
        gamma->gammaTable[i][1] = temp & ((1<<Features[vivFEATURE_GAMMA_BIT_OUT])-1);
        gamma->gammaTable[i][2] = temp & ((1<<Features[vivFEATURE_GAMMA_BIT_OUT])-1);
    }
    return vivSTATUS_OK;
}

vivSTATUS viv_gamma_enable(
    viv_display  display,
    gctBOOL      enable
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_GAMMA_ENABLE;
    iface.u.gamma.disp_id = display;
    iface.u.gamma.enable = enable;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_set_gamma(
    viv_display  display,
    gctUINT32    index,
    gctUINT16    r,
    gctUINT16    g,
    gctUINT16    b
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if(index >= GAMMA_TABLE_SIZE)
    {
        viv_print("Invalid argument, gamma index is out of range.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_GAMMA;
    iface.u.gamma.disp_id = display;
    iface.u.gamma.index = index;
    iface.u.gamma.item[0] = r;
    iface.u.gamma.item[1] = g;
    iface.u.gamma.item[2] = b;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_LAYER_DEGAMMA
vivSTATUS viv_layer_degamma_init(
    viv_dc_degamma  *degamma
    )
{
    gctUINT i, table_value;
    gctFLOAT tmpf0, tmpf1;
    gctUINT table1[257] = {0};
    gctUINT table2[4] = {0};

    if(degamma == vivNULL)
    {
        viv_print("[viv_dc_setting viv_layer_degamma_init] Invalid Argument: Null Pointer!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    /* This part is used to interpolation and each interval have 4 datas.
     * [0,4),[4,8), ...[1016,1020)
     * There are 255+1 entries for interpolation
     */
    for(i = 0; i < 256; i++)
    {
        tmpf0 = (gctFLOAT)(i/256.f);
        tmpf1 = viv_util_dc_to_degamma(tmpf0) / 10000.f;    /* for 2020 */

        table1[i] = (gctUINT)(tmpf1*(1<<14)*2.f);
    }
    table1[256] = (gctUINT)((1<<14)*2.f - 1.f);

    /* When input data <1020, look up table and do interpolation.
     * When input data >=1020 ([1020,1023]),  directly look up the table.
     * There are 4 entries for direct look up.
     */
    for(i = 1020; i <= 1023; i++)
    {
        tmpf0 = (gctFLOAT)(i/1024.f);
        tmpf1 = viv_util_dc_to_degamma(tmpf0) / 10000.f;    /* for 2020 */

        table2[i-1020] = (gctUINT)(tmpf1*((1<<14) - 1));
    }

    /* final table construct */
    for(i = 0; i < DEGAMMA_TABLE_SIZE; i++)
    {
        if(i < 256)
            table_value = table1[i];
        else
            table_value = table2[i-256];

        degamma->degammaTable[i][0] = table_value & 0x7FFF;
        degamma->degammaTable[i][1] = table_value & 0x7FFF;
        degamma->degammaTable[i][2] = table_value & 0x7FFF;
    }
    return vivSTATUS_OK;
}

vivSTATUS viv_layer_degamma_enable(
    gctBOOL      enable
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_ENABLE_DEGAMMA;
    iface.u.layer.layer_id =  currentLayer;
    iface.u.layer.u.degamma.enable = enable;

    return viv_dc_device_call(&iface);
}

vivSTATUS viv_layer_set_degamma(
    gctUINT32    index,
    gctUINT16    r,
    gctUINT16    g,
    gctUINT16    b
    )
{
    viv_interface iface;

    if(index >= DEGAMMA_TABLE_SIZE)
    {
        viv_print("Invalid argument, degamma index is out of range.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_LAYER;
    iface.u.layer.cmd = vivLAYER_SET_DEGAMMA;
    iface.u.layer.layer_id =  currentLayer;
    iface.u.layer.u.degamma.index = index;
    iface.u.layer.u.degamma.item[0] = r;
    iface.u.layer.u.degamma.item[1] = g;
    iface.u.layer.u.degamma.item[2] = b;

    return viv_dc_device_call(&iface);
}
#endif

/*modified after adding color bar fuction.
*/
vivSTATUS viv_layer_set_background(
    viv_display display,
    viv_dc_color *bgColor
    )
{
    viv_interface iface;

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.command = vivIFACE_BACKGROUND;
    iface.u.background.cmd =vivBACKGROUND_SET_COLOR;
    iface.u.background.display_id = display;

    if (!bgColor)
    {
        viv_print("The input background color is illegal.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    dc_os_memcpy(&iface.u.background.iu.purecolor.color, bgColor, sizeof(viv_dc_color));

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_DISPLAY_CLRBAR
/* this fuction is used to set the color bar.
*/
vivSTATUS viv_set_color_bar(
    viv_display display,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect *range,
    viv_dc_color *color
    )
{
    viv_interface iface;

    if (featureTable[vivFEATURE_COLOR_BAR] == 0)
    {
        viv_print("Color bar feature is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (index > COLOR_BAR_RANGE_MAX)
    {
        viv_print("The input index num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command=vivIFACE_BACKGROUND;
    iface.u.background.cmd=vivBACKGROUND_SET_COLORBAR;
    iface.u.background.display_id=display;

    if (enable)
    {
        if(!range || !color)
        {
            viv_print("The input range or color is illegal.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }
        iface.u.background.iu.colorbar.enable = SET_ENABLE;
        iface.u.background.iu.colorbar.index = index;
        dc_os_memcpy(&iface.u.background.iu.colorbar.range, range, sizeof(viv_dc_rect));
        dc_os_memcpy(&iface.u.background.iu.colorbar.color, color, sizeof(viv_dc_color));
    }
    else
    {
        iface.u.background.iu.colorbar.enable = SET_DISABLE;
        iface.u.background.iu.colorbar.index = index;
    }

    return viv_dc_device_call(&iface);
}
#endif

#if vivENABLE_LAYER_ROT
/* This function sets rotation related configuration for layer.
 */
vivSTATUS viv_layer_rotation(
    viv_rotation_type rotation
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_ROTATION;
    iface.u.layer.u.rotation.rot= rotation;

    context.rot[currentLayer] = rotation;

    return viv_dc_device_call(&iface);
}
#endif

/* This function sets scale related configuration for layer.
 */
vivSTATUS viv_layer_scale(
    viv_dc_rect *displayRect,
    viv_filter_tap_type filter
    )
{
    viv_interface iface;

#if vivENABLE_LAYER_SCALE
    gctUINT32 scaleFactorX, scaleFactorY;
    gcsFILTER_BLIT_ARRAY_PTR kernelInfo = vivNULL;
    gctUINT filterTap, horizontalFilterTap;
    gctUINT32 srcwidth, srcheight;
#endif

    viv_os_memset(vivNULL, &iface, 0x0, sizeof(viv_interface));

#if vivENABLE_LAYER_SCALE
#if vivENABLE_LAYER_ROI
    if (context.roiEnable[currentLayer])
    {
        srcwidth = context.roiRect[currentLayer].w;
        srcheight = context.roiRect[currentLayer].h;
        context.roiEnable[currentLayer] = vivFALSE;
    }
    else
#endif
    {
        srcwidth = context.layerWidth[currentLayer];
        srcheight = context.layerHeight[currentLayer];
    }
#endif

    iface.command = vivIFACE_LAYER;
    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_SCALE;

    dc_os_memcpy(&iface.u.layer.u.scale.display_rect,displayRect,sizeof(viv_dc_rect));

#if vivENABLE_LAYER_SCALE
    kernelInfo = (gcsFILTER_BLIT_ARRAY_PTR)viv_os_mem_alloc(sizeof(gcsFILTER_BLIT_ARRAY));

    if (filter == vivFILTER_H5_V3)
    {
        horizontalFilterTap = 5;
        filterTap = 3;
    }
    else
    {
        horizontalFilterTap = 3;
        filterTap = 3;
    }

    iface.u.layer.u.scale.filter= filter;

    /* kernelInfo->filterType = vivFILTER_SYNC; */
    kernelInfo->kernelStates = vivNULL;

    if ((displayRect->w != srcwidth) || (displayRect->h != srcheight))
    {
        if ((displayRect->w == srcheight) &&
            (displayRect->h == srcwidth) &&
            ((context.rot[currentLayer] == vivROTANGLE_90) || (context.rot[currentLayer] == vivROTANGLE_270)))
        {
            iface.u.layer.u.scale.scale_enable = 0;
        }
        else
        {
            /* Generate factorX and factorY. */
            if ((context.rot[currentLayer] == vivROTANGLE_90) || (context.rot[currentLayer] == vivROTANGLE_270))
            {
                scaleFactorX = get_stretch_factor(srcheight, displayRect->w);
                scaleFactorY = get_stretch_factor(srcwidth, displayRect->h);
                /* rotate 90 or 270, the scale rate in high is srcwidth/displayRect->h */
                if(((gctFLOAT)srcwidth/(gctFLOAT)displayRect->h) > SCALE_DOWN_LIMITATION)
                {
                    return vivSTATUS_NOT_SUPPORT;
                }
                calculate_sync_table(horizontalFilterTap, srcheight, displayRect->w, kernelInfo);
                dc_os_memcpy(iface.u.layer.u.scale.horkernel, (kernelInfo->kernelStates + 1), 312);
                calculate_sync_table(filterTap, srcwidth, displayRect->h, kernelInfo);
                dc_os_memcpy(iface.u.layer.u.scale.verkernel, (kernelInfo->kernelStates + 1), 312);
            }
            else
            {
                scaleFactorX = get_stretch_factor(srcwidth, displayRect->w);
                scaleFactorY = get_stretch_factor(srcheight, displayRect->h);
                 if(((gctFLOAT)srcheight/(gctFLOAT)displayRect->h) > SCALE_DOWN_LIMITATION)
                {
                    return vivSTATUS_NOT_SUPPORT;
                }
                calculate_sync_table(horizontalFilterTap, srcwidth, displayRect->w, kernelInfo);
                dc_os_memcpy(iface.u.layer.u.scale.horkernel, (kernelInfo->kernelStates + 1), 312);
                calculate_sync_table(filterTap, srcheight, displayRect->h, kernelInfo);
                dc_os_memcpy(iface.u.layer.u.scale.verkernel, (kernelInfo->kernelStates + 1), 312);
            }

            if (scaleFactorY > (3 << 16))
            {
                scaleFactorY = (3 << 16);
            }

            iface.u.layer.u.scale.scale_factorx = scaleFactorX;
            iface.u.layer.u.scale.scale_factory = scaleFactorY;
            iface.u.layer.u.scale.scale_enable = 1;

            if(kernelInfo->kernelStates)
            {
                viv_os_mem_free(kernelInfo->kernelStates);
                kernelInfo->kernelStates = vivNULL;
            }
        }
    }

    viv_os_mem_free(kernelInfo);
#endif

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_cursor_move(
    viv_display display,
    gctUINT32 x,
    gctUINT32 y
    )
{
    viv_interface iface;
    iface.command = vivIFACE_CURSOR;
    iface.u.cursor.cmd = vivCURSOR_MOVE;
    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.u.cursor.display_id = display;
    iface.u.cursor.iu.move.x = x;
    iface.u.cursor.iu.move.y = y;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_set_cursor(
    viv_display display,
    viv_dc_buffer *buffer,
    viv_cursor *cursor,
    gctBOOL  enable
    )
{
    viv_interface iface;

    if(featureTable[vivFEATURE_CURSOR_COUNT] == 0)
    {
        viv_print("Not support cursor.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    iface.command = vivIFACE_CURSOR;
    iface.u.cursor.cmd = vivCURSOR_SET;
    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.u.cursor.display_id = display;

    if (enable)
    {
        if(!buffer || !cursor)
        {
            viv_print("The input buffer or cursor is illegal.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }
        iface.u.cursor.iu.set.enable = SET_ENABLE;
        dc_os_memcpy(&iface.u.cursor.iu.set.buffer, buffer, sizeof(viv_dc_buffer));
        dc_os_memcpy(&iface.u.cursor.iu.set.cursor, cursor, sizeof(viv_cursor));
    }
    else
    {
        iface.u.cursor.iu.set.enable = SET_DISABLE;
    }

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_cursor_offset(
    viv_display display,
    gctUINT32 hsx,
    gctUINT32 hsy
    )
{
    viv_interface iface;
    iface.command = vivIFACE_CURSOR;
    iface.u.cursor.cmd = vivCURSOR_HOTSPOT;

    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.u.cursor.display_id = display;
    iface.u.cursor.iu.hotspot.hsx = hsx;
    iface.u.cursor.iu.hotspot.hsy = hsy;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_SEC
vivSTATUS viv_cursor_security(
    viv_display display,
    gctBOOL  enable
    )
{
    viv_interface iface;
    iface.command = vivIFACE_CURSOR;
    iface.u.cursor.cmd = vivCURSOR_SECURITY;
    if (display >= DC_DISPLAY_NUM)
    {
        viv_print("The input display num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    iface.u.cursor.display_id = display;

    if (enable)
    {
        iface.u.cursor.iu.security.enable = SET_ENABLE;
    }
    else
    {
        iface.u.cursor.iu.security.enable = SET_DISABLE;
    }
    return (vivSTATUS)viv_dc_device_call(&iface);
}

/* set security layer */
vivSTATUS viv_layer_security(
    gctBOOL layer_sec
    )
{
    viv_interface iface;
    iface.command = vivIFACE_LAYER;
    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_SECURITY;
    if(layer_sec)
        iface.u.layer.u.security.enable = vivTRUE;
    else
        iface.u.layer.u.security.enable = vivFALSE;
    return (vivSTATUS)viv_dc_device_call(&iface);
}
#endif

vivSTATUS viv_dc_set_qos(
    gctUINT32 low,
    gctUINT32 high
    )
{
    viv_interface iface;
    iface.command = vivIFACE_QOS;
    iface.u.qos.low = low;
    iface.u.qos.high= high;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_LAYER_DECOMPRESS
/* This function sets decompress related configuration for layer.
 */
vivSTATUS viv_layer_decompress(
    viv_tilestatus_buffer *tilebuffer,
    gctBOOL enable
    )
{
    viv_interface iface;
    if(Features[vivFEATURE_40BIT_ADDRESS] == 0)
    {
        tilebuffer->tileStatusHWAddress[0] &= 0x00FFFFFFFF;
        tilebuffer->tileStatusHWAddress[1] &= 0x00FFFFFFFF;
        tilebuffer->tileStatusHWAddress[2] &= 0x00FFFFFFFF;
    }

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_DECOMPRESS;
    iface.u.layer.u.decompress.decompress_enable= enable;
    dc_os_memcpy(&iface.u.layer.u.decompress.tilestatus_buffer, tilebuffer, sizeof(viv_tilestatus_buffer));

    return viv_dc_device_call(&iface);
}

/* This function sets compression size.
 */
vivSTATUS viv_layer_cache_mode(
    viv_cache_mode cache_mode
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_CACHE_MODE;
    iface.u.layer.u.decompress.cache_mode= cache_mode;

    return viv_dc_device_call(&iface);
}
#endif

/* This function set layer watermark value.
 */
vivSTATUS viv_layer_set_watermark(
    gctUINT32 watermark
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_WATERMARK;
    iface.u.layer.u.watermark.watermark_value = watermark;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function set source/dest alpha value and mode.
 */
vivSTATUS viv_set_alpha(
    viv_layer_alpha_mode *Alpha
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_ALPHA;
    dc_os_memcpy(&iface.u.layer.u.alpha.alpha, Alpha, sizeof(viv_layer_alpha_mode));

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets porter duff blending mode.
 */
vivSTATUS viv_layer_poterduff_blend(
    gctBOOL enable,
    viv_porter_duff_mode Mode
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_POTERBUFF_BLEND_MODE;
    iface.u.layer.u.poterduff_blend.enable = enable;
    iface.u.layer.u.poterduff_blend.mode = Mode;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets the layer zorder.
 */
vivSTATUS viv_layer_zorder(
    gctUINT8 zorder
    )
{
    viv_interface iface;

    if(zorder >= featureTable[vivFEATURE_LAYER_COUNT])
    {
        viv_print("Invalid argument, zorder exceeds the count of layer.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_ZORDER;
    iface.u.layer.u.zorder.zorder = zorder;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets which display/output that layer displayed.
 */
vivSTATUS viv_layer_set_display(
    viv_display display
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_SET_DISPLAY;
    iface.u.layer.u.display.display_id= display;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets display settings for the display’s horizontal and vertical dimensions, sync and polarity.
 */
vivSTATUS viv_set_display_size(
    viv_display display,
    viv_display_size_type type
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_DISPLAY;

    iface.u.display.display_id = display;
    iface.u.display.cmd = vivDISPLAY_SET_SIZE;
    iface.u.display.u.size.type = type;
#if vivENABLE_DISPLAY_CRC //IFX - Fix Warning variable set but never used
    curSizeType[display] = type;
#endif
    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function sets custom display settings for the display.
 */
vivSTATUS viv_set_custom_display_size(
    viv_display display,
    gctUINT hactive,
    gctUINT hsync_start,
    gctUINT hsync_end,
    gctUINT htotal,
    gctUINT vactive,
    gctUINT vsync_start,
    gctUINT vsync_end,
    gctUINT vtotal
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_DISPLAY;

    iface.u.display.display_id = display;
    iface.u.display.cmd = vivDISPLAY_SET_CUSTOM_SIZE;
    iface.u.display.u.size.type = vivDISPLAY_CUSTOMIZED;
    iface.u.display.u.size.hactive = hactive;
    iface.u.display.u.size.hsync_start = hsync_start;
    iface.u.display.u.size.hsync_end = hsync_end;
    iface.u.display.u.size.htotal = htotal;
    iface.u.display.u.size.vactive = vactive;
    iface.u.display.u.size.vsync_start = vsync_start;
    iface.u.display.u.size.vsync_end = vsync_end;
    iface.u.display.u.size.vtotal = vtotal;
#if vivENABLE_DISPLAY_CRC //IFX - Fix Warning variable set but never used.
    curSizeType[display] = vivDISPLAY_CUSTOMIZED;
#endif
    curCustomWidth = hactive;
    curCustomHeight = vactive;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/*
 * get the vblank count of specify display
 */
vivSTATUS viv_get_vblank_count(
    viv_display display,
    gctUINT32 *count
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_QUERY;

    iface.u.query.cmd = vivQUERY_VBLANK_COUNT;
    iface.u.query.u.vblank.disp_id = display;

    viv_dc_device_call(&iface);
    *count = iface.u.query.u.vblank.count;
    return vivSTATUS_OK;
}

/* This function enables and sets parameters for output.
 */
vivSTATUS viv_set_output(
    viv_display display,
    viv_output *output,
    gctBOOL enable
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_DISPLAY;
    iface.u.display.cmd = vivDISPLAY_SET_OUTPUT;
    iface.u.display.display_id = display;
    if(enable && output)
    {
        iface.u.display.u.output.enable = vivTRUE;
        dc_os_memcpy(&iface.u.display.u.output.output, output, sizeof(viv_output));
    }
    else
    {
        iface.u.display.u.output.enable = vivFALSE;
        viv_os_memset(vivNULL, &iface.u.display.u.output.output, 0, sizeof(viv_output));
    }
    return (vivSTATUS)viv_dc_device_call(&iface);
}

/* Reset output DBI state.
 */
vivSTATUS viv_reset_dbi()
{
    viv_interface iface;

    iface.command = vivIFACE_DISPLAY;
    iface.u.display.cmd = vivDISPLAY_RESET_DBI;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function set parameters for output DBI.
 */
vivSTATUS viv_set_output_dbi(
    viv_display display,
    viv_dbi_type type
    )
{
    viv_interface iface;

    iface.command = vivIFACE_DISPLAY;
    iface.u.display.cmd = vivDISPLAY_SET_DBI;

    iface.u.display.display_id = display;
    iface.u.display.u.output_dbi.type = type;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_DISPLAY_R2Y
/* This function sets output csc
 */
vivSTATUS viv_set_output_csc(
    viv_display display,
    gctBOOL fullRange,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if(!featureTable[vivFEATURE_CSC_MOUDLE])
    {
        viv_print("Invalid Argument: Not support csc moudle!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_DISPLAY;
    iface.u.display.cmd = vivDISPLAY_SET_CSC;
    iface.u.display.display_id = display;

    if(mode == vivCSC_USER_DEF)
    {
        if(coef == vivNULL)
        {
            viv_print("[viv_dc_setting viv_set_output_csc] Invalid Argument: Null Pointer!\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        if(num != RGB2YUV_COEF_NUM)
        {
            viv_print("[viv_dc_setting viv_set_output_csc] Invalid Argument: The number of user define parameters is not qualified.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        dc_os_memcpy(iface.u.display.u.output_csc.coef, coef, num * sizeof(gctINT));
    }

    iface.u.display.u.output_csc.full_range = fullRange;
    iface.u.display.u.output_csc.mode = mode;
    iface.u.display.u.output_csc.num = num;

    return viv_dc_device_call(&iface);
}
#endif

/* This function commit the commands to DC after the above setting.
 */
vivSTATUS viv_set_commit(
    gctUINT32 display_mask
    )
{
    viv_interface iface;

    if((display_mask != 0x1) && (display_mask != 0x2) && (display_mask != 0x3))
    {
        viv_print("Invalid argument, display mask exceeds the range of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_COMMIT;
    iface.u.commit.display_mask = display_mask;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function enable/disable layer
 */
vivSTATUS viv_layer_enable(
    gctBOOL enable
    )
{
    viv_interface iface;

    iface.command = vivIFACE_LAYER;

    iface.u.layer.layer_id = currentLayer;
    iface.u.layer.cmd = vivLAYER_ENABLE;
    iface.u.layer.u.layer_enable.layer_enable = enable;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

/* This function reset the dc
 */
vivSTATUS viv_dc_reset(
    gctVOID
    )
{
    viv_interface iface;

    iface.command = vivIFACE_RESET;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_WRITEBACK
/* This function sets dest
 */
gctINT viv_set_dest(
    gctBOOL enable,
    viv_display display,
    viv_dc_buffer *buffer,
    viv_write_back_type type,
    viv_display_format_type format
    )
{
    viv_interface iface;

    if(display >= DC_DISPLAY_NUM)
    {
        viv_print("Invalid argument, display id exceeds the number of display.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if(featureTable[vivFEATURE_WRITEBACK] == 0)
    {
        viv_print("Write back feature is not support.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    if((type == vivWB_DEFAULT) && (featureTable[vivFEATURE_PROGRAM_WB] == 1))
    {
        viv_print("It is just support programmable write back.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    if((type != vivWB_DEFAULT) && (featureTable[vivFEATURE_PROGRAM_WB] == 0))
    {
        viv_print("Invalid argument, it is asked program write back.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_DISPLAY;

    iface.u.display.display_id = display;
    iface.u.display.cmd = vivDISPLAY_SET_DEST;

    if(enable)
    {
        if(!buffer)
        {
            viv_print("Invalid argument, *buffer is null pointer.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        if(featureTable[vivFEATURE_PROGRAM_WB] && (type != vivWB_DEFAULT))
        {
            if((buffer->format != vivARGB8888) &&
               (buffer->format != vivXRGB8888) &&
               (buffer->format != vivARGB4444) &&
               (buffer->format != vivXRGB4444) &&
               (buffer->format != vivRGB565) &&
               (buffer->format != vivARGB1555) &&
               (buffer->format != vivXRGB1555) &&
               (buffer->format != vivARGB2101010) &&
               (buffer->format != vivNV12)
              )
            {
                viv_print("This format is not support programmable write back.\n");
                return vivSTATUS_NOT_SUPPORT;
            }

            /* Check whether programmable WB format and display format setting are matched */
            if((type == vivWB_AFTER_BLENDING) && (buffer->format == vivNV12))
            {
                viv_print("Invalid argument, write back format does not match write back type.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }
            else if((type == vivWB_AFTER_DITHER) && (buffer->format == vivNV12) && ((format < vivDPYUV420B8CFG1) || (format > vivDPYUV444B10CFG3)))
            {
                viv_print("Invalid argument, write back format does not match display format.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }
            else if((type == vivWB_AFTER_DITHER) && (buffer->format != vivNV12) && ((format > vivDPRGB101010) && (format < vivD8R3G3B2)))
            {
                viv_print("Invalid argument, write back format does not match display format.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }
          }

        iface.u.display.u.dest.enable = SET_ENABLE;
        dc_os_memcpy(&iface.u.display.u.dest.buffer, buffer, sizeof(viv_dc_buffer));
        iface.u.display.u.dest.type = type;
    }
    else
    {
        iface.u.display.u.dest.enable = SET_DISABLE;
    }

    return viv_dc_device_call(&iface);
}
#endif

vivSTATUS viv_dc_init_lcd(
    gctVOID
    )
{
    viv_interface iface;

    iface.command = vivIFACE_INIT_LCD;

    return (vivSTATUS)viv_dc_device_call(&iface); //IFX - Fix Warning typecast needed.
}

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_set_crc_range(
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect *range
    )
{
    viv_interface iface;
    gctUINT resolution_width[DC_DISPLAY_NUM], resolution_height[DC_DISPLAY_NUM];

    _viv_calculate_resolution(curSizeType, resolution_width, resolution_height);

    if (index >= MAX_CRC_NUM)
    {
        viv_print("The input crc unit num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (!range)
    {
        viv_print("The input range is illegal.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if ((range->w > resolution_width[0]) || (range->h > resolution_height[0]))
    {
        viv_print("The input range is out of resolution.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (index > 0)
    {
        if ((range->w > CRC_RECT_MAX_WIDTH) || (range->h > CRC_RECT_MAX_HEIGHT))
        {
            viv_print("The input range is out of crc max region.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }
    }

    iface.command = vivIFACE_CRC;
    iface.u.crc.cmd = vivCRC_SET_RANGE;

    iface.u.crc.index = index;
    iface.u.crc.u.crc_range.enable = enable;
    dc_os_memcpy(&iface.u.crc.u.crc_range.range, range, sizeof(viv_dc_rect));

    return viv_dc_device_call(&iface);
}

vivSTATUS viv_get_crc_value(
    gctUINT index,
    gctUINT *value
    )
{
    viv_interface iface;
    gctINT ret = 0;

    if (index >= MAX_CRC_NUM)
    {
        viv_print("The input crc unit num is out of boundary.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    iface.command = vivIFACE_CRC;
    iface.u.crc.cmd = vivCRC_GET_VALUE;
    iface.u.crc.index = index;

    ret = viv_dc_device_call(&iface);
    if (ret == vivSTATUS_OK)
    {
        *value = iface.u.crc.u.crc_value.value;
    }

    return ret;
}
#endif

#if vivENABLE_DUALOS
vivSTATUS viv_layer_get_status(
    viv_layer_status *status
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    viv_interface iface;

    if(!featureTable[vivFEATURE_DUAL_OS])
    {
        viv_print("Get the layer status is not support.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    iface.command = vivIFACE_QUERY;
    iface.u.query.cmd = vivQUERY_LAYER_STATUS;
    iface.u.query.u.viv_query_layer_status.layer_id = currentLayer;
    ret = (vivSTATUS)viv_dc_device_call(&iface);
    if(ret != vivSTATUS_OK)
    {
        viv_print("get layer status failed\n");
        return ret;
    }

    dc_os_memcpy(status, &iface.u.query.u.viv_query_layer_status.queryLayerStatus, sizeof(viv_layer_status));

    return ret;
}

vivSTATUS viv_dc_request(
    gctBOOL *success
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    viv_interface iface;

    if(!featureTable[vivFEATURE_DUAL_OS])
    {
        viv_print("DC request is not support.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    iface.command = vivIFACE_OS_REQUEST_CONTROL;
    ret = (vivSTATUS)viv_dc_device_call(&iface);
    if(ret != vivSTATUS_OK)
    {
        viv_print("dc request layer control failed\n");
        return ret;
    }

    dc_os_memcpy(success, &iface.u.request.result, sizeof(gctBOOL));

    return ret;
}

gctVOID viv_dc_interrupt_enable(
    gctBOOL enable
    )
{
    viv_interface iface;
    iface.command = vivIFACE_INTERRUPT_ENABLE;
    iface.u.interrupt.interrupt_enable = enable;
    viv_dc_device_call(&iface);
}
#endif
