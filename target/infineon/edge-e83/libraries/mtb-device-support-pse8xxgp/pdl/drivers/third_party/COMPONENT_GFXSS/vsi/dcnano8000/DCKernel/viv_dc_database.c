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


#include "viv_dc_database.h"

static gcsDC_FEATURES gDCFeatureInfos[] = {
    /* For cmodel verify */
    {
        0x0, /* ChipID */
        0x5550, /* ChipRevision */
        0x12000000, /* ProductID */
        0x0, /* EcoID */
        0x300, /* CustomerID */
        0x0, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x1, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005720, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x0000030a, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x1, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005720, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x0000030e, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x0, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005720, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x0000030b, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x4, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005721, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x0000030b, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x4, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005721, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x00000310, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x0, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x0, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005720, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x00000311, /* CustomerID */
        0x00000008, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x0, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005721, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x00000311, /* CustomerID */
        0x00000004, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x0, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008000, /* ChipID */
        0x00005543, /* ChipRevision */
        0x02080001, /* ProductID */
        0x0, /* EcoID */
        0x0000030F, /* CustomerID */
        0x3, /* PatchVersion */
        0x1, /* FormalRelease */
        0x1, /* DC_DISPLAY_COUNT */
        0x3, /* DC_LAYER_COUNT */
        0x1, /* DC_CURSOR_COUNT */
        0x8, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x0, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x0, /* DC_CSC_MODULE */
        0x0, /* DC_3D_LUT */
        0x0, /* DC_DE_GAMMA */
        0x0, /* DC_DP */
        0x0, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x1, /* DC_DBI */
        0x0, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x0, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x1, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
    {
        0x00008100, /* ChipID */
        0x00005730, /* ChipRevision */
        0x02081000, /* ProductID */
        0x0, /* EcoID */
        0x00000312, /* CustomerID */
        0x0, /* PatchVersion */
        0x1, /* FormalRelease */
        0x1, /* DC_DISPLAY_COUNT */
        0x5, /* DC_LAYER_COUNT */
        0x0, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x0, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x1, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x1, /* DC_COLOR_BAR */
        0x1, /* DC_CRC */
        0x1, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x1, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x1, /* DC_DUAL_OS */
    },
    {
        0x00008200, /* ChipID */
        0x00005721, /* ChipRevision */
        0x02082000, /* ProductID */
        0x00000000, /* EcoID */
        0x00000313, /* CustomerID */
        0x00000004, /* PatchVersion */
        0x1, /* FormalRelease */
        0x2, /* DC_DISPLAY_COUNT */
        0x6, /* DC_LAYER_COUNT */
        0x2, /* DC_CURSOR_COUNT */
        0xc, /* DC_GAMMA_PIPE_BITS */
        0x0, /* DC_SECURITY */
        0x1, /* DC_MMU */
        0x1, /* DC_CURSOR_VERSION */
        0x1, /* DC_CSC_MODULE */
        0x1, /* DC_3D_LUT */
        0x1, /* DC_DE_GAMMA */
        0x1, /* DC_DP */
        0x1, /* DC_DP_YUV */
        0x0, /* DC_DPI */
        0x0, /* DC_DBI */
        0x1, /* DC_NEW_GAMMA */
        0x0, /* DC_COLOR_BAR */
        0x0, /* DC_CRC */
        0x0, /* DC_40BIT_ADDRESS */
        0x1, /* DC_WRITEBACK */
        0x0, /* DC_PROGRAM_WB */
        0x0, /* DC_CUSTOMER_TILE4X4 */
        0x0, /* DC_DUAL_OS */
    },
};

gcsDC_FEATURES*
_DCQueryFeatures(
    gctUINT32 ChipID,
    gctUINT32 ChipVersion,
    gctUINT32 ProductID,
    gctUINT32 EcoID,
    gctUINT32 CustomerID
    )
{
    gctINT size = sizeof(gDCFeatureInfos) / sizeof(gDCFeatureInfos[0]);
    gctINT i = 0;
    /* check formal release entries */
    for (i = 0; i < size; ++i)
    {
        if ((gDCFeatureInfos[i].chipID == ChipID)
            && (gDCFeatureInfos[i].chipVersion == ChipVersion)
            && (gDCFeatureInfos[i].productID == ProductID)
            && (gDCFeatureInfos[i].ecoID == EcoID)
            && (gDCFeatureInfos[i].customerID == CustomerID)
            /*&& (gDCFeatureInfos[i].formalRelease)*/
           )
        {
            return &gDCFeatureInfos[i];
        }
    }
    return &gDCFeatureInfos[8]; //IFXEXP-176 Awaiting for new delivery from VSI
}
