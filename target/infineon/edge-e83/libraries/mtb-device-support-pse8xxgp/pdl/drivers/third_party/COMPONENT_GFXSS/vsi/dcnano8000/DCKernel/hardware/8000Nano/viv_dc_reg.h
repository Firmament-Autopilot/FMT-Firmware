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


#ifndef __gcregDisplay_h__
#define __gcregDisplay_h__

/*******************************************************************************
**                          ~~~~~~~~~~~~~~~~~~~~~~~~                          **
**                          Module DisplayController                          **
**                          ~~~~~~~~~~~~~~~~~~~~~~~~                          **
*******************************************************************************/

/* Register gcregDcChipRev **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Chip Revision Register.  Shows the revision for the chip in BCD.  This     **
** register has no set reset  value. It varies with the implementation. READ  **
** ONLY.                                                                      */
/* IFXEXP-177 - DCNano offset not matching with PSE84 */
#define gcregDcChipRevRegAddrs                                            0x0800
#define GCREG_DC_CHIP_REV_Address                                        0x00000
#define GCREG_DC_CHIP_REV_MSB                                                 15
#define GCREG_DC_CHIP_REV_LSB                                                  0
#define GCREG_DC_CHIP_REV_BLK                                                  0
#define GCREG_DC_CHIP_REV_Count                                                1
#define GCREG_DC_CHIP_REV_FieldMask                                   0xFFFFFFFF
#define GCREG_DC_CHIP_REV_ReadMask                                    0xFFFFFFFF
#define GCREG_DC_CHIP_REV_WriteMask                                   0x00000000
#define GCREG_DC_CHIP_REV_ResetValue                                  0x00000000

/* Revision. The reset value for this field is subject to change and may be   **
** ignored during test.                                                       */
#define GCREG_DC_CHIP_REV_REV                                               31:0
#define GCREG_DC_CHIP_REV_REV_End                                             31
#define GCREG_DC_CHIP_REV_REV_Start                                            0
#define GCREG_DC_CHIP_REV_REV_Type                                           U32

/* Register gcregDcChipDate **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Chip Date Register.  Shows the release date for the IP in YYYYMMDD (year,  **
** month. day) format.  This register has no set reset value.  It varies with **
** the implementation. READ ONLY.                                             */

#define gcregDcChipDateRegAddrs                                           0x0801
#define GCREG_DC_CHIP_DATE_Address                                       0x00004
#define GCREG_DC_CHIP_DATE_MSB                                                15
#define GCREG_DC_CHIP_DATE_LSB                                                 0
#define GCREG_DC_CHIP_DATE_BLK                                                 0
#define GCREG_DC_CHIP_DATE_Count                                               1
#define GCREG_DC_CHIP_DATE_FieldMask                                  0xFFFFFFFF
#define GCREG_DC_CHIP_DATE_ReadMask                                   0xFFFFFFFF
#define GCREG_DC_CHIP_DATE_WriteMask                                  0x00000000
#define GCREG_DC_CHIP_DATE_ResetValue                                 0x00000000

/* Date. The reset value for this field changes per release and may be        **
** ignored during test. You can read the accurate value from the RTL file     **
** because the actual value may be later than the document release time.      */
#define GCREG_DC_CHIP_DATE_DATE                                             31:0
#define GCREG_DC_CHIP_DATE_DATE_End                                           31
#define GCREG_DC_CHIP_DATE_DATE_Start                                          0
#define GCREG_DC_CHIP_DATE_DATE_Type                                         U32

/* Register gcregDcChipPatchRev **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Patch Revision Register.  Patch revision level for the chip. READ ONLY. */

#define gcregDcChipPatchRevRegAddrs                                       0x0802
#define GCREG_DC_CHIP_PATCH_REV_Address                                  0x00008
#define GCREG_DC_CHIP_PATCH_REV_MSB                                           15
#define GCREG_DC_CHIP_PATCH_REV_LSB                                            0
#define GCREG_DC_CHIP_PATCH_REV_BLK                                            0
#define GCREG_DC_CHIP_PATCH_REV_Count                                          1
#define GCREG_DC_CHIP_PATCH_REV_FieldMask                             0xFFFFFFFF
#define GCREG_DC_CHIP_PATCH_REV_ReadMask                              0xFFFFFFFF
#define GCREG_DC_CHIP_PATCH_REV_WriteMask                             0x00000000
#define GCREG_DC_CHIP_PATCH_REV_ResetValue                            0x00000000

/* Patch revision.  The reset value for this field changes per release and    **
** may be ignored during test. You can read the accurate value from the RTL   **
** file because the actual value may be later than the document release time. */
#define GCREG_DC_CHIP_PATCH_REV_PATCH_REV                                   31:0
#define GCREG_DC_CHIP_PATCH_REV_PATCH_REV_End                                 31
#define GCREG_DC_CHIP_PATCH_REV_PATCH_REV_Start                                0
#define GCREG_DC_CHIP_PATCH_REV_PATCH_REV_Type                               U32

/* Register gcregDcProductId **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Product Identification Register. READ ONLY.  */

#define gcregDcProductIdRegAddrs                                          0x0803
#define GCREG_DC_PRODUCT_ID_Address                                      0x0000C
#define GCREG_DC_PRODUCT_ID_MSB                                               15
#define GCREG_DC_PRODUCT_ID_LSB                                                0
#define GCREG_DC_PRODUCT_ID_BLK                                                0
#define GCREG_DC_PRODUCT_ID_Count                                              1
#define GCREG_DC_PRODUCT_ID_FieldMask                                 0xFFFFFFFF
#define GCREG_DC_PRODUCT_ID_ReadMask                                  0xFFFFFFFF
#define GCREG_DC_PRODUCT_ID_WriteMask                                 0x00000000
#define GCREG_DC_PRODUCT_ID_ResetValue                                0x02000361

/* Product ID.  Bits 3:0 contain Product GRADE_LEVEL. 1 indicates level is    **
** Nano.  Bits 23:4 contain Product NUM, product number. None for DCNano;     **
** 8000 for DC8000 Series.  Bits 27:24 contain Product TYPE. 2 indicates      **
** Display Controller.                                                        */
#define GCREG_DC_PRODUCT_ID_PRODUCT_ID                                      31:0
#define GCREG_DC_PRODUCT_ID_PRODUCT_ID_End                                    31
#define GCREG_DC_PRODUCT_ID_PRODUCT_ID_Start                                   0
#define GCREG_DC_PRODUCT_ID_PRODUCT_ID_Type                                  U32

/* Register gcregDcCustomerId **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Shows the ID for the customer. READ ONLY. */

#define gcregDcCustomerIdRegAddrs                                         0x0804
#define GCREG_DC_CUSTOMER_ID_Address                                     0x00010
#define GCREG_DC_CUSTOMER_ID_MSB                                              15
#define GCREG_DC_CUSTOMER_ID_LSB                                               0
#define GCREG_DC_CUSTOMER_ID_BLK                                               0
#define GCREG_DC_CUSTOMER_ID_Count                                             1
#define GCREG_DC_CUSTOMER_ID_FieldMask                                0xFFFFFFFF
#define GCREG_DC_CUSTOMER_ID_ReadMask                                 0xFFFFFFFF
#define GCREG_DC_CUSTOMER_ID_WriteMask                                0x00000000
#define GCREG_DC_CUSTOMER_ID_ResetValue                               0x00000000

/* Customer Id. */
#define GCREG_DC_CUSTOMER_ID_ID                                             31:0
#define GCREG_DC_CUSTOMER_ID_ID_End                                           31
#define GCREG_DC_CUSTOMER_ID_ID_Start                                          0
#define GCREG_DC_CUSTOMER_ID_ID_Type                                         U32

/* Register gcregDcChipId **
** ~~~~~~~~~~~~~~~~~~~~~~ */

/* Shows the ID for the chip in BCD.  This register has no set reset value.   **
** It varies with the implementation. READ_ONLY.                              */

#define gcregDcChipIdRegAddrs                                             0x0805
#define GCREG_DC_CHIP_ID_Address                                         0x00014
#define GCREG_DC_CHIP_ID_MSB                                                  15
#define GCREG_DC_CHIP_ID_LSB                                                   0
#define GCREG_DC_CHIP_ID_BLK                                                   0
#define GCREG_DC_CHIP_ID_Count                                                 1
#define GCREG_DC_CHIP_ID_FieldMask                                    0xFFFFFFFF
#define GCREG_DC_CHIP_ID_ReadMask                                     0xFFFFFFFF
#define GCREG_DC_CHIP_ID_WriteMask                                    0x00000000
#define GCREG_DC_CHIP_ID_ResetValue                                   0x00000000

/* Id. */
#define GCREG_DC_CHIP_ID_ID                                                 31:0
#define GCREG_DC_CHIP_ID_ID_End                                               31
#define GCREG_DC_CHIP_ID_ID_Start                                              0
#define GCREG_DC_CHIP_ID_ID_Type                                             U32

/* Register gcregDcChipTime **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Shows the release time for the IP in HHMMSS00 (hour,  minutes, second, 00) **
** format.  This register  has no set reset value. It varies with the         **
** implementation.                                                            */

#define gcregDcChipTimeRegAddrs                                           0x0806
#define GCREG_DC_CHIP_TIME_Address                                       0x00018
#define GCREG_DC_CHIP_TIME_MSB                                                15
#define GCREG_DC_CHIP_TIME_LSB                                                 0
#define GCREG_DC_CHIP_TIME_BLK                                                 0
#define GCREG_DC_CHIP_TIME_Count                                               1
#define GCREG_DC_CHIP_TIME_FieldMask                                  0xFFFFFFFF
#define GCREG_DC_CHIP_TIME_ReadMask                                   0xFFFFFFFF
#define GCREG_DC_CHIP_TIME_WriteMask                                  0x00000000
#define GCREG_DC_CHIP_TIME_ResetValue                                 0x00000000

/* Time. */
#define GCREG_DC_CHIP_TIME_TIME                                             31:0
#define GCREG_DC_CHIP_TIME_TIME_End                                           31
#define GCREG_DC_CHIP_TIME_TIME_Start                                          0
#define GCREG_DC_CHIP_TIME_TIME_Type                                         U32

/* Register gcregDcChipInfo **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Chip infomation */

#define gcregDcChipInfoRegAddrs                                           0x0807
#define GCREG_DC_CHIP_INFO_Address                                       0x0001C
#define GCREG_DC_CHIP_INFO_MSB                                                15
#define GCREG_DC_CHIP_INFO_LSB                                                 0
#define GCREG_DC_CHIP_INFO_BLK                                                 0
#define GCREG_DC_CHIP_INFO_Count                                               1
#define GCREG_DC_CHIP_INFO_FieldMask                                  0xFFFFFFFF
#define GCREG_DC_CHIP_INFO_ReadMask                                   0xFFFFFFFF
#define GCREG_DC_CHIP_INFO_WriteMask                                  0x00000000
#define GCREG_DC_CHIP_INFO_ResetValue                                 0x00000000

/* Chip infomation */
#define GCREG_DC_CHIP_INFO_CHIP_INFO                                        31:0
#define GCREG_DC_CHIP_INFO_CHIP_INFO_End                                      31
#define GCREG_DC_CHIP_INFO_CHIP_INFO_Start                                     0
#define GCREG_DC_CHIP_INFO_CHIP_INFO_Type                                    U32

/* Register gcregDcEcoId **
** ~~~~~~~~~~~~~~~~~~~~~ */

/* Shows the ID for the chip ECO. READ ONLY. */

#define gcregDcEcoIdRegAddrs                                              0x0808
#define GCREG_DC_ECO_ID_Address                                          0x00020
#define GCREG_DC_ECO_ID_MSB                                                   15
#define GCREG_DC_ECO_ID_LSB                                                    0
#define GCREG_DC_ECO_ID_BLK                                                    0
#define GCREG_DC_ECO_ID_Count                                                  1
#define GCREG_DC_ECO_ID_FieldMask                                     0xFFFFFFFF
#define GCREG_DC_ECO_ID_ReadMask                                      0xFFFFFFFF
#define GCREG_DC_ECO_ID_WriteMask                                     0x00000000
#define GCREG_DC_ECO_ID_ResetValue                                    0x00000000

/* ECO Id. */
#define GCREG_DC_ECO_ID_ID                                                  31:0
#define GCREG_DC_ECO_ID_ID_End                                                31
#define GCREG_DC_ECO_ID_ID_Start                                               0
#define GCREG_DC_ECO_ID_ID_Type                                              U32

/* Register gcregDcReservedId (6 in total) **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDcReservedIdRegAddrs                                         0x0810
#define GCREG_DC_RESERVED_ID_Address                                     0x00040
#define GCREG_DC_RESERVED_ID_MSB                                              15
#define GCREG_DC_RESERVED_ID_LSB                                               3
#define GCREG_DC_RESERVED_ID_BLK                                               3
#define GCREG_DC_RESERVED_ID_Count                                             6
#define GCREG_DC_RESERVED_ID_FieldMask                                0xFFFFFFFF
#define GCREG_DC_RESERVED_ID_ReadMask                                 0xFFFFFFFF
#define GCREG_DC_RESERVED_ID_WriteMask                                0x00000000
#define GCREG_DC_RESERVED_ID_ResetValue                               0x00000000

#define GCREG_DC_RESERVED_ID_ID                                             31:0
#define GCREG_DC_RESERVED_ID_ID_End                                           31
#define GCREG_DC_RESERVED_ID_ID_Start                                          0
#define GCREG_DC_RESERVED_ID_ID_Type                                         U32

/* Register gcregFrameBufferConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Configuration Register.  Frame Buffer and Timing control.     **
** NOTE: This register is double buffered.                                    */

#define gcregFrameBufferConfigRegAddrs                                    0x0809
#define GCREG_FRAME_BUFFER_CONFIG_Address                                0x00024
#define GCREG_FRAME_BUFFER_CONFIG_MSB                                         15
#define GCREG_FRAME_BUFFER_CONFIG_LSB                                          0
#define GCREG_FRAME_BUFFER_CONFIG_BLK                                          0
#define GCREG_FRAME_BUFFER_CONFIG_Count                                        1
#define GCREG_FRAME_BUFFER_CONFIG_FieldMask                           0x000E062F
#define GCREG_FRAME_BUFFER_CONFIG_ReadMask                            0x000E062F
#define GCREG_FRAME_BUFFER_CONFIG_WriteMask                           0x000E062F
#define GCREG_FRAME_BUFFER_CONFIG_ResetValue                          0x00000000

/* The format of the frame buffer.  None means there is no  frame buffer and  **
** the display controller will not produce  any output. NOTE: This field is   **
** double buffered.                                                           */
#define GCREG_FRAME_BUFFER_CONFIG_FORMAT                                     2:0
#define GCREG_FRAME_BUFFER_CONFIG_FORMAT_End                                   2
#define GCREG_FRAME_BUFFER_CONFIG_FORMAT_Start                                 0
#define GCREG_FRAME_BUFFER_CONFIG_FORMAT_Type                                U03
#define   GCREG_FRAME_BUFFER_CONFIG_FORMAT_NONE                              0x0
#define   GCREG_FRAME_BUFFER_CONFIG_FORMAT_A4R4G4B4                          0x1
#define   GCREG_FRAME_BUFFER_CONFIG_FORMAT_A1R5G5B5                          0x2
#define   GCREG_FRAME_BUFFER_CONFIG_FORMAT_R5G6B5                            0x3
#define   GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8                          0x4

/* Enable this layer or disable this layer. NOTE: This field is double        **
** buffered.                                                                  */
#define GCREG_FRAME_BUFFER_CONFIG_ENABLE                                     3:3
#define GCREG_FRAME_BUFFER_CONFIG_ENABLE_End                                   3
#define GCREG_FRAME_BUFFER_CONFIG_ENABLE_Start                                 3
#define GCREG_FRAME_BUFFER_CONFIG_ENABLE_Type                                U01
#define   GCREG_FRAME_BUFFER_CONFIG_ENABLE_DISABLED                          0x0
#define   GCREG_FRAME_BUFFER_CONFIG_ENABLE_ENABLED                           0x1

/* Enable or disable clear. NOTE: This field is double buffered. */
#define GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN                                   5:5
#define GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN_End                                 5
#define GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN_Start                               5
#define GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN_Type                              U01
#define   GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN_DISABLED                        0x0
#define   GCREG_FRAME_BUFFER_CONFIG_CLEAR_EN_ENABLED                         0x1

/* When SwitchPanel of panel 0 is enabled, output channel 0 will show the     **
** image of panel 1,not panel 0's.                                            **
** When SwitchPanel of panel 0 is disabeld,output channel 0 will show its     **
** original image which is from panel 0.                                      **
** When SwitchPanel of panel 1 is enabled, output channel 1 will show the     **
** image of panel 0,not panel 1's.                                            **
** When SwitchPanle of panel 1 is disabled,output channel 1 will show the     **
** original image which is from panel 1.                                      **
**                                                                            **
**                            disabled(normal)            enabled(switch)     **
** output channel 0            panel 0                            panel 1     **
** output channel 1            panel 1                            panel 0     **
** NOTE: This field is double buffered.                                       */
#define GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL                                9:9
#define GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL_End                              9
#define GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL_Start                            9
#define GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL_Type                           U01
#define   GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL_DISABLED                     0x0
#define   GCREG_FRAME_BUFFER_CONFIG_SWITCHPANEL_ENABLED                      0x1

/* Enable or disable color key. NOTE: This field is double buffered. */
#define GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN                             10:10
#define GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_End                            10
#define GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_Start                          10
#define GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_Type                          U01
#define   GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_DISABLED                    0x0
#define   GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_ENABLED                     0x1

/* NOTE: This field is double buffered. */
#define GCREG_FRAME_BUFFER_CONFIG_SWIZZLE                                  18:17
#define GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_End                                 18
#define GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_Start                               17
#define GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_Type                               U02
#define   GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ARGB                             0x0
#define   GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_RGBA                             0x1
#define   GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ABGR                             0x2
#define   GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_BGRA                             0x3

/* NOTE: This field is double buffered. */
#define GCREG_FRAME_BUFFER_CONFIG_UV_SWIZZLE                               19:19
#define GCREG_FRAME_BUFFER_CONFIG_UV_SWIZZLE_End                              19
#define GCREG_FRAME_BUFFER_CONFIG_UV_SWIZZLE_Start                            19
#define GCREG_FRAME_BUFFER_CONFIG_UV_SWIZZLE_Type                            U01

/* Register gcregFrameBufferAddress **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Base Address Register.  Starting address of the frame buffer. **
**  NOTE: This register is double buffered.                                   */

#define gcregFrameBufferAddressRegAddrs                                   0x080A
#define GCREG_FRAME_BUFFER_ADDRESS_Address                               0x00028
#define GCREG_FRAME_BUFFER_ADDRESS_MSB                                        15
#define GCREG_FRAME_BUFFER_ADDRESS_LSB                                         0
#define GCREG_FRAME_BUFFER_ADDRESS_BLK                                         0
#define GCREG_FRAME_BUFFER_ADDRESS_Count                                       1
#define GCREG_FRAME_BUFFER_ADDRESS_FieldMask                          0xFFFFFFFF
#define GCREG_FRAME_BUFFER_ADDRESS_ReadMask                           0xFFFFFFFF
#define GCREG_FRAME_BUFFER_ADDRESS_WriteMask                          0xFFFFFFFF
#define GCREG_FRAME_BUFFER_ADDRESS_ResetValue                         0x00000000

/* 32 bit address. */
#define GCREG_FRAME_BUFFER_ADDRESS_ADDRESS                                  31:0
#define GCREG_FRAME_BUFFER_ADDRESS_ADDRESS_End                                31
#define GCREG_FRAME_BUFFER_ADDRESS_ADDRESS_Start                               0
#define GCREG_FRAME_BUFFER_ADDRESS_ADDRESS_Type                              U32

/* Register gcregFrameBufferStride **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Stride Register.  Stride of the frame buffer in bytes.  NOTE: **
** This register is double buffered.                                          */

#define gcregFrameBufferStrideRegAddrs                                    0x080B
#define GCREG_FRAME_BUFFER_STRIDE_Address                                0x0002C
#define GCREG_FRAME_BUFFER_STRIDE_MSB                                         15
#define GCREG_FRAME_BUFFER_STRIDE_LSB                                          0
#define GCREG_FRAME_BUFFER_STRIDE_BLK                                          0
#define GCREG_FRAME_BUFFER_STRIDE_Count                                        1
#define GCREG_FRAME_BUFFER_STRIDE_FieldMask                           0x0001FFFF
#define GCREG_FRAME_BUFFER_STRIDE_ReadMask                            0x0001FFFF
#define GCREG_FRAME_BUFFER_STRIDE_WriteMask                           0x0001FFFF
#define GCREG_FRAME_BUFFER_STRIDE_ResetValue                          0x00000000

/* Number of bytes from start of one line to next line.  NOTE: This field is  **
** double buffered.                                                           */
#define GCREG_FRAME_BUFFER_STRIDE_STRIDE                                    16:0
#define GCREG_FRAME_BUFFER_STRIDE_STRIDE_End                                  16
#define GCREG_FRAME_BUFFER_STRIDE_STRIDE_Start                                 0
#define GCREG_FRAME_BUFFER_STRIDE_STRIDE_Type                                U17

/* Register gcregFrameBufferOrigin **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Pixel Origin Register.  Pixel origin inside the frame buffer  **
** for the top-left panel  pixel. This register should be set to 0.  NOTE:    **
** This register is double buffered.                                          */

#define gcregFrameBufferOriginRegAddrs                                    0x080C
#define GCREG_FRAME_BUFFER_ORIGIN_Address                                0x00030
#define GCREG_FRAME_BUFFER_ORIGIN_MSB                                         15
#define GCREG_FRAME_BUFFER_ORIGIN_LSB                                          0
#define GCREG_FRAME_BUFFER_ORIGIN_BLK                                          0
#define GCREG_FRAME_BUFFER_ORIGIN_Count                                        1
#define GCREG_FRAME_BUFFER_ORIGIN_FieldMask                           0x07FF07FF
#define GCREG_FRAME_BUFFER_ORIGIN_ReadMask                            0x07FF07FF
#define GCREG_FRAME_BUFFER_ORIGIN_WriteMask                           0x07FF07FF
#define GCREG_FRAME_BUFFER_ORIGIN_ResetValue                          0x00000000

/* X origin of frame buffer for panning.  NOTE: This field is double          **
** buffered.                                                                  */
#define GCREG_FRAME_BUFFER_ORIGIN_X                                         10:0
#define GCREG_FRAME_BUFFER_ORIGIN_X_End                                       10
#define GCREG_FRAME_BUFFER_ORIGIN_X_Start                                      0
#define GCREG_FRAME_BUFFER_ORIGIN_X_Type                                     U11

/* Y origin of frame buffer for panning.  NOTE: This field is double          **
** buffered.                                                                  */
#define GCREG_FRAME_BUFFER_ORIGIN_Y                                        26:16
#define GCREG_FRAME_BUFFER_ORIGIN_Y_End                                       26
#define GCREG_FRAME_BUFFER_ORIGIN_Y_Start                                     16
#define GCREG_FRAME_BUFFER_ORIGIN_Y_Type                                     U11

/* Register gcregDcTileInCfg **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Tile Input Configuration Register.  Tile input configuration.  NOTE: This  **
** register is double buffered.                                               */

#define gcregDcTileInCfgRegAddrs                                          0x080D
#define GCREG_DC_TILE_IN_CFG_Address                                     0x00034
#define GCREG_DC_TILE_IN_CFG_MSB                                              15
#define GCREG_DC_TILE_IN_CFG_LSB                                               0
#define GCREG_DC_TILE_IN_CFG_BLK                                               0
#define GCREG_DC_TILE_IN_CFG_Count                                             1
#define GCREG_DC_TILE_IN_CFG_FieldMask                                0x00000007
#define GCREG_DC_TILE_IN_CFG_ReadMask                                 0x00000007
#define GCREG_DC_TILE_IN_CFG_WriteMask                                0x00000007
#define GCREG_DC_TILE_IN_CFG_ResetValue                               0x00000000

/* Tile input data format 0 means non-tile input.  NOTE: This field is double **
** buffered.                                                                  */
#define GCREG_DC_TILE_IN_CFG_TILE_FORMAT                                     1:0
#define GCREG_DC_TILE_IN_CFG_TILE_FORMAT_End                                   1
#define GCREG_DC_TILE_IN_CFG_TILE_FORMAT_Start                                 0
#define GCREG_DC_TILE_IN_CFG_TILE_FORMAT_Type                                U02
#define   GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NONE                              0x0
#define   GCREG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888                          0x1
#define   GCREG_DC_TILE_IN_CFG_TILE_FORMAT_YUY2                              0x2
#define   GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NV12                              0x3

/* YUV standard select.  NOTE: This field is double buffered.  */
#define GCREG_DC_TILE_IN_CFG_YUV_STANDARD                                    2:2
#define GCREG_DC_TILE_IN_CFG_YUV_STANDARD_End                                  2
#define GCREG_DC_TILE_IN_CFG_YUV_STANDARD_Start                                2
#define GCREG_DC_TILE_IN_CFG_YUV_STANDARD_Type                               U01
#define   GCREG_DC_TILE_IN_CFG_YUV_STANDARD_BT601                            0x0
#define   GCREG_DC_TILE_IN_CFG_YUV_STANDARD_BT709                            0x1

/* Register gcregDcTileUvFrameBufferAdr **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Tiled UV Base Address Register.  UV frame buffer address when **
** tile input.  NOTE: This register is double buffered.                       */

#define gcregDcTileUvFrameBufferAdrRegAddrs                               0x080E
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_Address                        0x0038
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_MSB                                 15
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_LSB                                  0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_BLK                                  0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_Count                                1
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_FieldMask                   0xFFFFFFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ReadMask                    0xFFFFFFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_WriteMask                   0xFFFFFFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ResetValue                  0x00000000

/* UV frame buffer address when tile input NOTE: This field is double         **
** buffered.                                                                  */
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS                           31:0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_End                         31
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_Start                        0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_Type                       U32

/* Register gcregDcTileUvFrameBufferStr **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frame Buffer Tiled UV Stride Register.  UV frame buffer stride when tile   **
** input  NOTE: This register is double buffered.                             */

#define gcregDcTileUvFrameBufferStrRegAddrs                               0x080F
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_Address                        0x0003C
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_MSB                                 15
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_LSB                                  0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_BLK                                  0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_Count                                1
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_FieldMask                   0x0000FFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_ReadMask                    0x0000FFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_WriteMask                   0x0000FFFF
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_ResetValue                  0x00000000

/* UV frame buffer stride when tile input NOTE: This field is double          **
** buffered.                                                                  */
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE                            15:0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_End                          15
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_Start                         0
#define GCREG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_Type                        U16

/* Register gcregFrameBufferBackground **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Framebuffer background color.  NOTE: This register is double buffered.  */

#define gcregFrameBufferBackgroundRegAddrs                                0x0816
#define GCREG_FRAME_BUFFER_BACKGROUND_Address                            0x00058
#define GCREG_FRAME_BUFFER_BACKGROUND_MSB                                     15
#define GCREG_FRAME_BUFFER_BACKGROUND_LSB                                      0
#define GCREG_FRAME_BUFFER_BACKGROUND_BLK                                      0
#define GCREG_FRAME_BUFFER_BACKGROUND_Count                                    1
#define GCREG_FRAME_BUFFER_BACKGROUND_FieldMask                       0xFFFFFFFF
#define GCREG_FRAME_BUFFER_BACKGROUND_ReadMask                        0xFFFFFFFF
#define GCREG_FRAME_BUFFER_BACKGROUND_WriteMask                       0xFFFFFFFF
#define GCREG_FRAME_BUFFER_BACKGROUND_ResetValue                      0x00000000

/* NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_BACKGROUND_BLUE                                   7:0
#define GCREG_FRAME_BUFFER_BACKGROUND_BLUE_End                                 7
#define GCREG_FRAME_BUFFER_BACKGROUND_BLUE_Start                               0
#define GCREG_FRAME_BUFFER_BACKGROUND_BLUE_Type                              U08

/* NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_BACKGROUND_GREEN                                 15:8
#define GCREG_FRAME_BUFFER_BACKGROUND_GREEN_End                               15
#define GCREG_FRAME_BUFFER_BACKGROUND_GREEN_Start                              8
#define GCREG_FRAME_BUFFER_BACKGROUND_GREEN_Type                             U08

/* NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_BACKGROUND_RED                                  23:16
#define GCREG_FRAME_BUFFER_BACKGROUND_RED_End                                 23
#define GCREG_FRAME_BUFFER_BACKGROUND_RED_Start                               16
#define GCREG_FRAME_BUFFER_BACKGROUND_RED_Type                               U08

/* NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_BACKGROUND_ALPHA                                31:24
#define GCREG_FRAME_BUFFER_BACKGROUND_ALPHA_End                               31
#define GCREG_FRAME_BUFFER_BACKGROUND_ALPHA_Start                             24
#define GCREG_FRAME_BUFFER_BACKGROUND_ALPHA_Type                             U08

/* Register gcregFrameBufferColorKey **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Framebuffer Color Key Start Address Register.  Start of color key range of **
** framebuffer.  NOTE: This register is double buffered.                      */

#define gcregFrameBufferColorKeyRegAddrs                                  0x0817
#define GCREG_FRAME_BUFFER_COLOR_KEY_Address                             0x0005C
#define GCREG_FRAME_BUFFER_COLOR_KEY_MSB                                      15
#define GCREG_FRAME_BUFFER_COLOR_KEY_LSB                                       0
#define GCREG_FRAME_BUFFER_COLOR_KEY_BLK                                       0
#define GCREG_FRAME_BUFFER_COLOR_KEY_Count                                     1
#define GCREG_FRAME_BUFFER_COLOR_KEY_FieldMask                        0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_ReadMask                         0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_WriteMask                        0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_ResetValue                       0x00000000

/* 8 bit blue color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_BLUE                                    7:0
#define GCREG_FRAME_BUFFER_COLOR_KEY_BLUE_End                                  7
#define GCREG_FRAME_BUFFER_COLOR_KEY_BLUE_Start                                0
#define GCREG_FRAME_BUFFER_COLOR_KEY_BLUE_Type                               U08

/* 8 bit green color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_GREEN                                  15:8
#define GCREG_FRAME_BUFFER_COLOR_KEY_GREEN_End                                15
#define GCREG_FRAME_BUFFER_COLOR_KEY_GREEN_Start                               8
#define GCREG_FRAME_BUFFER_COLOR_KEY_GREEN_Type                              U08

/* 8 bit red color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_RED                                   23:16
#define GCREG_FRAME_BUFFER_COLOR_KEY_RED_End                                  23
#define GCREG_FRAME_BUFFER_COLOR_KEY_RED_Start                                16
#define GCREG_FRAME_BUFFER_COLOR_KEY_RED_Type                                U08

/* 8 bit alpha value. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_ALPHA                                 31:24
#define GCREG_FRAME_BUFFER_COLOR_KEY_ALPHA_End                                31
#define GCREG_FRAME_BUFFER_COLOR_KEY_ALPHA_Start                              24
#define GCREG_FRAME_BUFFER_COLOR_KEY_ALPHA_Type                              U08

/* Register gcregFrameBufferColorKeyHigh **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Framebuffer Color Key End Address Register.  End of color key range of     **
** framebuffer.  NOTE: This register is double buffered.                      */

#define gcregFrameBufferColorKeyHighRegAddrs                              0x0818
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_Address                        0x00060
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_MSB                                 15
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_LSB                                  0
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_BLK                                  0
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_Count                                1
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_FieldMask                   0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ReadMask                    0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_WriteMask                   0xFFFFFFFF
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ResetValue                  0x00000000

/* 8 bit blue color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_BLUE                               7:0
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_BLUE_End                             7
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_BLUE_Start                           0
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_BLUE_Type                          U08

/* 8 bit green color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_GREEN                             15:8
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_GREEN_End                           15
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_GREEN_Start                          8
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_GREEN_Type                         U08

/* 8 bit red color. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_RED                              23:16
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_RED_End                             23
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_RED_Start                           16
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_RED_Type                           U08

/* 8 bit alpha value. */
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ALPHA                            31:24
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ALPHA_End                           31
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ALPHA_Start                         24
#define GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_ALPHA_Type                         U08

/* Register gcregFrameBufferClearValue **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Framebuffer Clear Value Register.  Clear value used when                   **
** dcregFrameBufferConfig.Clear  is enabled, format is A8R8G8B8.  NOTE: This  **
** register is double buffered.                                               */

#define gcregFrameBufferClearValueRegAddrs                                0x0819
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_Address                           0x00064
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_MSB                                    15
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_LSB                                     0
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_BLK                                     0
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_Count                                   1
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_FieldMask                      0xFFFFFFFF
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ReadMask                       0xFFFFFFFF
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_WriteMask                      0xFFFFFFFF
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ResetValue                     0x00000000

/* 8 bit blue color. */
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_BLUE                                  7:0
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_BLUE_End                                7
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_BLUE_Start                              0
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_BLUE_Type                             U08

/* 8 bit green color. */
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_GREEN                                15:8
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_GREEN_End                              15
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_GREEN_Start                             8
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_GREEN_Type                            U08

/* 8 bit red color. */
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_RED                                 23:16
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_RED_End                                23
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_RED_Start                              16
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_RED_Type                              U08

/* 8 bit alpha value. */
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ALPHA                               31:24
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ALPHA_End                              31
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ALPHA_Start                            24
#define GCREG_FRAME_BUFFER_CLEAR_VALUE_ALPHA_Type                            U08

/* Register gcregVideoTL **
** ~~~~~~~~~~~~~~~~~~~~~ */

/* Top left coordinate of panel pixel where the video should start.  Be aware **
** there is no panning inside the video. NOTE: This register is double        **
** buffered.                                                                  */

#define gcregVideoTLRegAddrs                                              0x081A
#define GCREG_VIDEO_TL_Address                                           0x00068
#define GCREG_VIDEO_TL_MSB                                                    15
#define GCREG_VIDEO_TL_LSB                                                     0
#define GCREG_VIDEO_TL_BLK                                                     0
#define GCREG_VIDEO_TL_Count                                                   1
#define GCREG_VIDEO_TL_FieldMask                                      0x0FFF0FFF
#define GCREG_VIDEO_TL_ReadMask                                       0x0FFF0FFF
#define GCREG_VIDEO_TL_WriteMask                                      0x0FFF0FFF
#define GCREG_VIDEO_TL_ResetValue                                     0x00000000

/* Left boundary of video window. NOTE: This field is double buffered.  */
#define GCREG_VIDEO_TL_X                                                    11:0
#define GCREG_VIDEO_TL_X_End                                                  11
#define GCREG_VIDEO_TL_X_Start                                                 0
#define GCREG_VIDEO_TL_X_Type                                                U12

/* Top boundary of video window. NOTE: This field is double buffered.  */
#define GCREG_VIDEO_TL_Y                                                   27:16
#define GCREG_VIDEO_TL_Y_End                                                  27
#define GCREG_VIDEO_TL_Y_Start                                                16
#define GCREG_VIDEO_TL_Y_Type                                                U12

/* Register gcregFrameBufferSize **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* video size information. NOTE: This register is double buffered. */

#define gcregFrameBufferSizeRegAddrs                                      0x081B
#define GCREG_FRAME_BUFFER_SIZE_Address                                  0x0006C
#define GCREG_FRAME_BUFFER_SIZE_MSB                                           15
#define GCREG_FRAME_BUFFER_SIZE_LSB                                            0
#define GCREG_FRAME_BUFFER_SIZE_BLK                                            0
#define GCREG_FRAME_BUFFER_SIZE_Count                                          1
#define GCREG_FRAME_BUFFER_SIZE_FieldMask                             0x0FFF0FFF
#define GCREG_FRAME_BUFFER_SIZE_ReadMask                              0x0FFF0FFF
#define GCREG_FRAME_BUFFER_SIZE_WriteMask                             0x0FFF0FFF
#define GCREG_FRAME_BUFFER_SIZE_ResetValue                            0x00000000

/* video width. NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_SIZE_WIDTH                                       11:0
#define GCREG_FRAME_BUFFER_SIZE_WIDTH_End                                     11
#define GCREG_FRAME_BUFFER_SIZE_WIDTH_Start                                    0
#define GCREG_FRAME_BUFFER_SIZE_WIDTH_Type                                   U12

/* video height. NOTE: This field is double buffered.  */
#define GCREG_FRAME_BUFFER_SIZE_HEIGHT                                     27:16
#define GCREG_FRAME_BUFFER_SIZE_HEIGHT_End                                    27
#define GCREG_FRAME_BUFFER_SIZE_HEIGHT_Start                                  16
#define GCREG_FRAME_BUFFER_SIZE_HEIGHT_Type                                  U12

/* Register gcregVideoGlobalAlpha **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Global alpha for the video.  NOTE: This register is double buffered.  */

#define gcregVideoGlobalAlphaRegAddrs                                     0x081C
#define GCREG_VIDEO_GLOBAL_ALPHA_Address                                 0x00070
#define GCREG_VIDEO_GLOBAL_ALPHA_MSB                                          15
#define GCREG_VIDEO_GLOBAL_ALPHA_LSB                                           0
#define GCREG_VIDEO_GLOBAL_ALPHA_BLK                                           0
#define GCREG_VIDEO_GLOBAL_ALPHA_Count                                         1
#define GCREG_VIDEO_GLOBAL_ALPHA_FieldMask                            0x0000FFFF
#define GCREG_VIDEO_GLOBAL_ALPHA_ReadMask                             0x0000FFFF
#define GCREG_VIDEO_GLOBAL_ALPHA_WriteMask                            0x0000FFFF
#define GCREG_VIDEO_GLOBAL_ALPHA_ResetValue                           0x00000000

/* Source alpha for video. NOTE: This field is double buffered.  */
#define GCREG_VIDEO_GLOBAL_ALPHA_SRC_ALPHA                                   7:0
#define GCREG_VIDEO_GLOBAL_ALPHA_SRC_ALPHA_End                                 7
#define GCREG_VIDEO_GLOBAL_ALPHA_SRC_ALPHA_Start                               0
#define GCREG_VIDEO_GLOBAL_ALPHA_SRC_ALPHA_Type                              U08

/* Destination alpha for video.  NOTE: This field is double buffered.  */
#define GCREG_VIDEO_GLOBAL_ALPHA_DST_ALPHA                                  15:8
#define GCREG_VIDEO_GLOBAL_ALPHA_DST_ALPHA_End                                15
#define GCREG_VIDEO_GLOBAL_ALPHA_DST_ALPHA_Start                               8
#define GCREG_VIDEO_GLOBAL_ALPHA_DST_ALPHA_Type                              U08

/* Register gcregBlendStackOrder **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Set the video, overlay0, overlay1 order for blend. The 1st is the lowest   **
** layer, the 2nd is the middle layer, the 3rd is the highest layer. NOTE:    **
** This register is double buffered.                                          */

#define gcregBlendStackOrderRegAddrs                                      0x081D
#define GCREG_BLEND_STACK_ORDER_Address                                  0x00074
#define GCREG_BLEND_STACK_ORDER_MSB                                           15
#define GCREG_BLEND_STACK_ORDER_LSB                                            0
#define GCREG_BLEND_STACK_ORDER_BLK                                            0
#define GCREG_BLEND_STACK_ORDER_Count                                          1
#define GCREG_BLEND_STACK_ORDER_FieldMask                             0x00000007
#define GCREG_BLEND_STACK_ORDER_ReadMask                              0x00000007
#define GCREG_BLEND_STACK_ORDER_WriteMask                             0x00000007
#define GCREG_BLEND_STACK_ORDER_ResetValue                            0x00000000

/* NOTE: This field is double buffered.  */
#define GCREG_BLEND_STACK_ORDER_ORDER                                        2:0
#define GCREG_BLEND_STACK_ORDER_ORDER_End                                      2
#define GCREG_BLEND_STACK_ORDER_ORDER_Start                                    0
#define GCREG_BLEND_STACK_ORDER_ORDER_Type                                   U03
#define   GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1              0x0
#define   GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY1_OVERLAY0              0x1
#define   GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_VIDEO_OVERLAY1              0x2
#define   GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_OVERLAY1_VIDEO              0x3
#define   GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY1_VIDEO_OVERLAY0              0x4
#define   GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY1_OVERLAY0_VIDEO              0x5

/* Register gcregVideoAlphaBlendConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Alpha Blending Configuration Register.  NOTE: This register is double      **
** buffered.                                                                  */

#define gcregVideoAlphaBlendConfigRegAddrs                                0x081E
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_Address                           0x00078
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_MSB                                    15
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_LSB                                     0
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_BLK                                     0
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_Count                                   1
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_FieldMask                      0x0000EFDB
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ReadMask                       0x0000EFDB
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_WriteMask                      0x0000EFDB
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ResetValue                     0x00000000

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND                           0:0
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND_End                         0
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND_Start                       0
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND_Type                      U01
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND_DISABLED                0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_ALPHA_BLEND_ENABLED                 0x1

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE                        1:1
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_End                      1
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_Start                    1
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_Type                   U01
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_NORMAL               0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_INVERSED             0x1

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE                 4:3
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_End               4
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_Start             3
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_Type            U02
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_NORMAL        0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_GLOBAL        0x1
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_SCALED        0x2

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE                     7:6
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_End                   7
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_Start                 6
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_Type                U02
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_ZERO              0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_ONE               0x1
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_NORMAL            0x2
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_INVERSED          0x3

/* Src Blending factor is calculated from Src alpha.  */
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR                      8:8
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_End                    8
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_Start                  8
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_Type                 U01
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_DISABLED           0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_ENABLED            0x1

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE                        9:9
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_End                      9
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_Start                    9
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_Type                   U01
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_NORMAL               0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_INVERSED             0x1

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE               11:10
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_End              11
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_Start            10
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_Type            U02
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_NORMAL        0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_GLOBAL        0x1
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_SCALED        0x2

#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE                   14:13
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_End                  14
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_Start                13
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_Type                U02
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_ZERO              0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_ONE               0x1
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_NORMAL            0x2
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_INVERSED          0x3

/* Destination blending factor is calculated from Dst alpha.  */
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR                    15:15
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_End                   15
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_Start                 15
#define GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_Type                 U01
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_DISABLED           0x0
#define   GCREG_VIDEO_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_ENABLED            0x1

/* Register gcregOverlayConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Configuration Register.  Overlay control.  NOTE: This register is  **
** double buffered.                                                           */

#define gcregOverlayConfigRegAddrs                                        0x081F
#define GCREG_OVERLAY_CONFIG_Address                                     0x0007C
#define GCREG_OVERLAY_CONFIG_MSB                                              15
#define GCREG_OVERLAY_CONFIG_LSB                                               0
#define GCREG_OVERLAY_CONFIG_BLK                                               0
#define GCREG_OVERLAY_CONFIG_Count                                             1
#define GCREG_OVERLAY_CONFIG_FieldMask                                0x001E002F
#define GCREG_OVERLAY_CONFIG_ReadMask                                 0x001E002F
#define GCREG_OVERLAY_CONFIG_WriteMask                                0x001E002F
#define GCREG_OVERLAY_CONFIG_ResetValue                               0x00000000

/* The format of the overlay. None means there is no  overlay. NOTE: This     **
** field is double buffered.                                                  */
#define GCREG_OVERLAY_CONFIG_FORMAT                                          2:0
#define GCREG_OVERLAY_CONFIG_FORMAT_End                                        2
#define GCREG_OVERLAY_CONFIG_FORMAT_Start                                      0
#define GCREG_OVERLAY_CONFIG_FORMAT_Type                                     U03
#define   GCREG_OVERLAY_CONFIG_FORMAT_NONE                                   0x0
#define   GCREG_OVERLAY_CONFIG_FORMAT_A4R4G4B4                               0x1
#define   GCREG_OVERLAY_CONFIG_FORMAT_A1R5G5B5                               0x2
#define   GCREG_OVERLAY_CONFIG_FORMAT_R5G6B5                                 0x3
#define   GCREG_OVERLAY_CONFIG_FORMAT_A8R8G8B8                               0x4

/* Enable this overlay layer.  NOTE: This field is double buffered.  */
#define GCREG_OVERLAY_CONFIG_ENABLE                                          3:3
#define GCREG_OVERLAY_CONFIG_ENABLE_End                                        3
#define GCREG_OVERLAY_CONFIG_ENABLE_Start                                      3
#define GCREG_OVERLAY_CONFIG_ENABLE_Type                                     U01
#define   GCREG_OVERLAY_CONFIG_ENABLE_DISABLE                                0x0
#define   GCREG_OVERLAY_CONFIG_ENABLE_ENABLE                                 0x1

/* Enable or disable clear. NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG_CLEAR_EN                                        5:5
#define GCREG_OVERLAY_CONFIG_CLEAR_EN_End                                      5
#define GCREG_OVERLAY_CONFIG_CLEAR_EN_Start                                    5
#define GCREG_OVERLAY_CONFIG_CLEAR_EN_Type                                   U01
#define   GCREG_OVERLAY_CONFIG_CLEAR_EN_DISABLED                             0x0
#define   GCREG_OVERLAY_CONFIG_CLEAR_EN_ENABLED                              0x1

/* NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG_SWIZZLE                                       18:17
#define GCREG_OVERLAY_CONFIG_SWIZZLE_End                                      18
#define GCREG_OVERLAY_CONFIG_SWIZZLE_Start                                    17
#define GCREG_OVERLAY_CONFIG_SWIZZLE_Type                                    U02
#define   GCREG_OVERLAY_CONFIG_SWIZZLE_ARGB                                  0x0
#define   GCREG_OVERLAY_CONFIG_SWIZZLE_RGBA                                  0x1
#define   GCREG_OVERLAY_CONFIG_SWIZZLE_ABGR                                  0x2
#define   GCREG_OVERLAY_CONFIG_SWIZZLE_BGRA                                  0x3

/* NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG_UV_SWIZZLE                                    19:19
#define GCREG_OVERLAY_CONFIG_UV_SWIZZLE_End                                   19
#define GCREG_OVERLAY_CONFIG_UV_SWIZZLE_Start                                 19
#define GCREG_OVERLAY_CONFIG_UV_SWIZZLE_Type                                 U01

/* Enable or disable color key. NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG_COLOR_KEY_EN                                  20:20
#define GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_End                                 20
#define GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_Start                               20
#define GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_Type                               U01
#define   GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_DISABLED                         0x0
#define   GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_ENABLED                          0x1

/* Register gcregOverlayAddress **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Starting address of the overlay. NOTE: This register is double buffered. */

#define gcregOverlayAddressRegAddrs                                       0x0820
#define GCREG_OVERLAY_ADDRESS_Address                                    0x00080
#define GCREG_OVERLAY_ADDRESS_MSB                                             15
#define GCREG_OVERLAY_ADDRESS_LSB                                              0
#define GCREG_OVERLAY_ADDRESS_BLK                                              0
#define GCREG_OVERLAY_ADDRESS_Count                                            1
#define GCREG_OVERLAY_ADDRESS_FieldMask                               0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS_ReadMask                                0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS_WriteMask                               0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS_ResetValue                              0x00000000

/* 32 bit address. */
#define GCREG_OVERLAY_ADDRESS_ADDRESS                                       31:0
#define GCREG_OVERLAY_ADDRESS_ADDRESS_End                                     31
#define GCREG_OVERLAY_ADDRESS_ADDRESS_Start                                    0
#define GCREG_OVERLAY_ADDRESS_ADDRESS_Type                                   U32

/* Register gcregOverlayStride **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Stride of the overlay in bytes. NOTE: This register is double buffered. */

#define gcregOverlayStrideRegAddrs                                        0x0821
#define GCREG_OVERLAY_STRIDE_Address                                     0x00084
#define GCREG_OVERLAY_STRIDE_MSB                                              15
#define GCREG_OVERLAY_STRIDE_LSB                                               0
#define GCREG_OVERLAY_STRIDE_BLK                                               0
#define GCREG_OVERLAY_STRIDE_Count                                             1
#define GCREG_OVERLAY_STRIDE_FieldMask                                0x0001FFFF
#define GCREG_OVERLAY_STRIDE_ReadMask                                 0x0001FFFF
#define GCREG_OVERLAY_STRIDE_WriteMask                                0x0001FFFF
#define GCREG_OVERLAY_STRIDE_ResetValue                               0x00000000

/* Number of bytes from start of one line to next line. */
#define GCREG_OVERLAY_STRIDE_STRIDE                                         16:0
#define GCREG_OVERLAY_STRIDE_STRIDE_End                                       16
#define GCREG_OVERLAY_STRIDE_STRIDE_Start                                      0
#define GCREG_OVERLAY_STRIDE_STRIDE_Type                                     U17

/* Register gcregDcOverlayTileInCfg **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Tile Input Configuration Register.  Tile input configuration.  NOTE: This  **
** register is double buffered.                                               */

#define gcregDcOverlayTileInCfgRegAddrs                                   0x0822
#define GCREG_DC_OVERLAY_TILE_IN_CFG_Address                             0x00088
#define GCREG_DC_OVERLAY_TILE_IN_CFG_MSB                                      15
#define GCREG_DC_OVERLAY_TILE_IN_CFG_LSB                                       0
#define GCREG_DC_OVERLAY_TILE_IN_CFG_BLK                                       0
#define GCREG_DC_OVERLAY_TILE_IN_CFG_Count                                     1
#define GCREG_DC_OVERLAY_TILE_IN_CFG_FieldMask                        0x00000007
#define GCREG_DC_OVERLAY_TILE_IN_CFG_ReadMask                         0x00000007
#define GCREG_DC_OVERLAY_TILE_IN_CFG_WriteMask                        0x00000007
#define GCREG_DC_OVERLAY_TILE_IN_CFG_ResetValue                       0x00000000

/* Tile input data format 0 means non-tile input  NOTE: This field is double  **
** buffered.                                                                  */
#define GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT                             1:0
#define GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_End                           1
#define GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_Start                         0
#define GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_Type                        U02
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_NONE                      0x0
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_ARGB8888                  0x1
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_YUY2                      0x2
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_TILE_FORMAT_NV12                      0x3

/* YUV standard select. NOTE: This field is double buffered. */
#define GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD                            2:2
#define GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD_End                          2
#define GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD_Start                        2
#define GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD_Type                       U01
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD_BT601                    0x0
#define   GCREG_DC_OVERLAY_TILE_IN_CFG_YUV_STANDARD_BT709                    0x1

/* Register gcregDcTileUvOverlayAdr **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Starting address of the overlay UV. NOTE: This register is double          **
** buffered.                                                                  */

#define gcregDcTileUvOverlayAdrRegAddrs                                   0x0823
#define GCREG_DC_TILE_UV_OVERLAY_ADR_Address                             0x0008C
#define GCREG_DC_TILE_UV_OVERLAY_ADR_MSB                                      15
#define GCREG_DC_TILE_UV_OVERLAY_ADR_LSB                                       0
#define GCREG_DC_TILE_UV_OVERLAY_ADR_BLK                                       0
#define GCREG_DC_TILE_UV_OVERLAY_ADR_Count                                     1
#define GCREG_DC_TILE_UV_OVERLAY_ADR_FieldMask                        0xFFFFFFFF
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ReadMask                         0xFFFFFFFF
#define GCREG_DC_TILE_UV_OVERLAY_ADR_WriteMask                        0xFFFFFFFF
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ResetValue                       0x00000000

/* 32 bit address. */
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ADDRESS                                31:0
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ADDRESS_End                              31
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ADDRESS_Start                             0
#define GCREG_DC_TILE_UV_OVERLAY_ADR_ADDRESS_Type                            U32

/* Register gcregDcTileUvOverlayStr **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Stride of the overlay UV in bytes. NOTE: This register is double buffered. */

#define gcregDcTileUvOverlayStrRegAddrs                                   0x0824
#define GCREG_DC_TILE_UV_OVERLAY_STR_Address                             0x00090
#define GCREG_DC_TILE_UV_OVERLAY_STR_MSB                                      15
#define GCREG_DC_TILE_UV_OVERLAY_STR_LSB                                       0
#define GCREG_DC_TILE_UV_OVERLAY_STR_BLK                                       0
#define GCREG_DC_TILE_UV_OVERLAY_STR_Count                                     1
#define GCREG_DC_TILE_UV_OVERLAY_STR_FieldMask                        0x0000FFFF
#define GCREG_DC_TILE_UV_OVERLAY_STR_ReadMask                         0x0000FFFF
#define GCREG_DC_TILE_UV_OVERLAY_STR_WriteMask                        0x0000FFFF
#define GCREG_DC_TILE_UV_OVERLAY_STR_ResetValue                       0x00000000

/* Number of bytes from start of one line to next line. NOTE: This field is   **
** double buffered.                                                           */
#define GCREG_DC_TILE_UV_OVERLAY_STR_STRIDE                                 15:0
#define GCREG_DC_TILE_UV_OVERLAY_STR_STRIDE_End                               15
#define GCREG_DC_TILE_UV_OVERLAY_STR_STRIDE_Start                              0
#define GCREG_DC_TILE_UV_OVERLAY_STR_STRIDE_Type                             U16

/* Register gcregOverlayTL **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Top left coordinate of panel pixel where the overlay should start.  Be     **
** aware there is no panning inside the overlay. NOTE: This register is       **
** double buffered.                                                           */

#define gcregOverlayTLRegAddrs                                            0x0825
#define GCREG_OVERLAY_TL_Address                                         0x00094
#define GCREG_OVERLAY_TL_MSB                                                  15
#define GCREG_OVERLAY_TL_LSB                                                   0
#define GCREG_OVERLAY_TL_BLK                                                   0
#define GCREG_OVERLAY_TL_Count                                                 1
#define GCREG_OVERLAY_TL_FieldMask                                    0x0FFF0FFF
#define GCREG_OVERLAY_TL_ReadMask                                     0x0FFF0FFF
#define GCREG_OVERLAY_TL_WriteMask                                    0x0FFF0FFF
#define GCREG_OVERLAY_TL_ResetValue                                   0x00000000

/* Left boundary of overlay window. */
#define GCREG_OVERLAY_TL_X                                                  11:0
#define GCREG_OVERLAY_TL_X_End                                                11
#define GCREG_OVERLAY_TL_X_Start                                               0
#define GCREG_OVERLAY_TL_X_Type                                              U12

/* Top boundary of overlay window. */
#define GCREG_OVERLAY_TL_Y                                                 27:16
#define GCREG_OVERLAY_TL_Y_End                                                27
#define GCREG_OVERLAY_TL_Y_Start                                              16
#define GCREG_OVERLAY_TL_Y_Type                                              U12

/* Register gcregOverlaySize **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* overlay size information. NOTE: This register is double buffered. */

#define gcregOverlaySizeRegAddrs                                          0x0826
#define GCREG_OVERLAY_SIZE_Address                                       0x00098
#define GCREG_OVERLAY_SIZE_MSB                                                15
#define GCREG_OVERLAY_SIZE_LSB                                                 0
#define GCREG_OVERLAY_SIZE_BLK                                                 0
#define GCREG_OVERLAY_SIZE_Count                                               1
#define GCREG_OVERLAY_SIZE_FieldMask                                  0x0FFF0FFF
#define GCREG_OVERLAY_SIZE_ReadMask                                   0x0FFF0FFF
#define GCREG_OVERLAY_SIZE_WriteMask                                  0x0FFF0FFF
#define GCREG_OVERLAY_SIZE_ResetValue                                 0x00000000

/* overlay width. */
#define GCREG_OVERLAY_SIZE_WIDTH                                            11:0
#define GCREG_OVERLAY_SIZE_WIDTH_End                                          11
#define GCREG_OVERLAY_SIZE_WIDTH_Start                                         0
#define GCREG_OVERLAY_SIZE_WIDTH_Type                                        U12

/* overlay height. */
#define GCREG_OVERLAY_SIZE_HEIGHT                                          27:16
#define GCREG_OVERLAY_SIZE_HEIGHT_End                                         27
#define GCREG_OVERLAY_SIZE_HEIGHT_Start                                       16
#define GCREG_OVERLAY_SIZE_HEIGHT_Type                                       U12

/* Register gcregOverlayColorKey **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Color Key Start Address Register.  Start of color key range for    **
** overlay.  NOTE: This register is double buffered.                          */

#define gcregOverlayColorKeyRegAddrs                                      0x0827
#define GCREG_OVERLAY_COLOR_KEY_Address                                  0x0009C
#define GCREG_OVERLAY_COLOR_KEY_MSB                                           15
#define GCREG_OVERLAY_COLOR_KEY_LSB                                            0
#define GCREG_OVERLAY_COLOR_KEY_BLK                                            0
#define GCREG_OVERLAY_COLOR_KEY_Count                                          1
#define GCREG_OVERLAY_COLOR_KEY_FieldMask                             0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_ReadMask                              0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_WriteMask                             0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_ResetValue                            0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_COLOR_KEY_BLUE                                         7:0
#define GCREG_OVERLAY_COLOR_KEY_BLUE_End                                       7
#define GCREG_OVERLAY_COLOR_KEY_BLUE_Start                                     0
#define GCREG_OVERLAY_COLOR_KEY_BLUE_Type                                    U08

/* 8 bit green color. */
#define GCREG_OVERLAY_COLOR_KEY_GREEN                                       15:8
#define GCREG_OVERLAY_COLOR_KEY_GREEN_End                                     15
#define GCREG_OVERLAY_COLOR_KEY_GREEN_Start                                    8
#define GCREG_OVERLAY_COLOR_KEY_GREEN_Type                                   U08

/* 8 bit red color. */
#define GCREG_OVERLAY_COLOR_KEY_RED                                        23:16
#define GCREG_OVERLAY_COLOR_KEY_RED_End                                       23
#define GCREG_OVERLAY_COLOR_KEY_RED_Start                                     16
#define GCREG_OVERLAY_COLOR_KEY_RED_Type                                     U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_COLOR_KEY_ALPHA                                      31:24
#define GCREG_OVERLAY_COLOR_KEY_ALPHA_End                                     31
#define GCREG_OVERLAY_COLOR_KEY_ALPHA_Start                                   24
#define GCREG_OVERLAY_COLOR_KEY_ALPHA_Type                                   U08

/* Register gcregOverlayColorKeyHigh **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Color Key End Address Register.  End of color key range for        **
** overlay.  NOTE: This register is double buffered.                          */

#define gcregOverlayColorKeyHighRegAddrs                                  0x0828
#define GCREG_OVERLAY_COLOR_KEY_HIGH_Address                             0x000A0
#define GCREG_OVERLAY_COLOR_KEY_HIGH_MSB                                      15
#define GCREG_OVERLAY_COLOR_KEY_HIGH_LSB                                       0
#define GCREG_OVERLAY_COLOR_KEY_HIGH_BLK                                       0
#define GCREG_OVERLAY_COLOR_KEY_HIGH_Count                                     1
#define GCREG_OVERLAY_COLOR_KEY_HIGH_FieldMask                        0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ReadMask                         0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH_WriteMask                        0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ResetValue                       0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH_BLUE                                    7:0
#define GCREG_OVERLAY_COLOR_KEY_HIGH_BLUE_End                                  7
#define GCREG_OVERLAY_COLOR_KEY_HIGH_BLUE_Start                                0
#define GCREG_OVERLAY_COLOR_KEY_HIGH_BLUE_Type                               U08

/* 8 bit green color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH_GREEN                                  15:8
#define GCREG_OVERLAY_COLOR_KEY_HIGH_GREEN_End                                15
#define GCREG_OVERLAY_COLOR_KEY_HIGH_GREEN_Start                               8
#define GCREG_OVERLAY_COLOR_KEY_HIGH_GREEN_Type                              U08

/* 8 bit red color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH_RED                                   23:16
#define GCREG_OVERLAY_COLOR_KEY_HIGH_RED_End                                  23
#define GCREG_OVERLAY_COLOR_KEY_HIGH_RED_Start                                16
#define GCREG_OVERLAY_COLOR_KEY_HIGH_RED_Type                                U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ALPHA                                 31:24
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ALPHA_End                                31
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ALPHA_Start                              24
#define GCREG_OVERLAY_COLOR_KEY_HIGH_ALPHA_Type                              U08

/* Register gcregOverlayAlphaBlendConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Alpha Blending Configuration Register.  NOTE: This register is double      **
** buffered.                                                                  */

#define gcregOverlayAlphaBlendConfigRegAddrs                              0x0829
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_Address                         0x000A4
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_MSB                                  15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_LSB                                   0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_BLK                                   0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_Count                                 1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_FieldMask                    0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ReadMask                     0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_WriteMask                    0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ResetValue                   0x00000000

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND                         0:0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_End                       0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_Start                     0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_Type                    U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_DISABLED              0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_ENABLED               0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE                      1:1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_End                    1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_Start                  1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_Type                 U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_NORMAL             0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_MODE_INVERSED           0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE               4:3
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_End             4
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_Start           3
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_Type          U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_NORMAL      0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_GLOBAL      0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_GLOBAL_ALPHA_MODE_SCALED      0x2

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE                   7:6
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_End                 7
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_Start               6
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_Type              U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_ZERO            0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_ONE             0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_NORMAL          0x2
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_BLENDING_MODE_INVERSED        0x3

/* Src Blending factor is calculated from Src alpha.  */
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR                    8:8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_End                  8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_Start                8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_Type               U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_DISABLED         0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_ENABLED          0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE                      9:9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_End                    9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_Start                  9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_Type                 U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_NORMAL             0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_MODE_INVERSED           0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE             11:10
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_End            11
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_Start          10
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_Type          U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_NORMAL      0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_GLOBAL      0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_GLOBAL_ALPHA_MODE_SCALED      0x2

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE                 14:13
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_End                14
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_Start              13
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_Type              U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_ZERO            0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_ONE             0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_NORMAL          0x2
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_BLENDING_MODE_INVERSED        0x3

/* Destination blending factor is calculated from Dst alpha.  */
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR                  15:15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_End                 15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_Start               15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_Type               U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_DISABLED         0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_ENABLED          0x1

/* Register gcregOverlayGlobalAlpha **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay global alpha value.  NOTE: This register is double buffered.  */

#define gcregOverlayGlobalAlphaRegAddrs                                   0x082A
#define GCREG_OVERLAY_GLOBAL_ALPHA_Address                               0x000A8
#define GCREG_OVERLAY_GLOBAL_ALPHA_MSB                                        15
#define GCREG_OVERLAY_GLOBAL_ALPHA_LSB                                         0
#define GCREG_OVERLAY_GLOBAL_ALPHA_BLK                                         0
#define GCREG_OVERLAY_GLOBAL_ALPHA_Count                                       1
#define GCREG_OVERLAY_GLOBAL_ALPHA_FieldMask                          0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA_ReadMask                           0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA_WriteMask                          0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA_ResetValue                         0x00000000

#define GCREG_OVERLAY_GLOBAL_ALPHA_SRC_ALPHA                                 7:0
#define GCREG_OVERLAY_GLOBAL_ALPHA_SRC_ALPHA_End                               7
#define GCREG_OVERLAY_GLOBAL_ALPHA_SRC_ALPHA_Start                             0
#define GCREG_OVERLAY_GLOBAL_ALPHA_SRC_ALPHA_Type                            U08

#define GCREG_OVERLAY_GLOBAL_ALPHA_DST_ALPHA                                15:8
#define GCREG_OVERLAY_GLOBAL_ALPHA_DST_ALPHA_End                              15
#define GCREG_OVERLAY_GLOBAL_ALPHA_DST_ALPHA_Start                             8
#define GCREG_OVERLAY_GLOBAL_ALPHA_DST_ALPHA_Type                            U08

/* Register gcregOverlayClearValue **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Clear Value Register.  Clear value used when                       **
** dcregOverlayConfig.Clear  is enabled, Format is A8R8G8B8.  NOTE: This      **
** register is double buffered.                                               */

#define gcregOverlayClearValueRegAddrs                                    0x082B
#define GCREG_OVERLAY_CLEAR_VALUE_Address                                0x000AC
#define GCREG_OVERLAY_CLEAR_VALUE_MSB                                         15
#define GCREG_OVERLAY_CLEAR_VALUE_LSB                                          0
#define GCREG_OVERLAY_CLEAR_VALUE_BLK                                          0
#define GCREG_OVERLAY_CLEAR_VALUE_Count                                        1
#define GCREG_OVERLAY_CLEAR_VALUE_FieldMask                           0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE_ReadMask                            0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE_WriteMask                           0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE_ResetValue                          0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_CLEAR_VALUE_BLUE                                       7:0
#define GCREG_OVERLAY_CLEAR_VALUE_BLUE_End                                     7
#define GCREG_OVERLAY_CLEAR_VALUE_BLUE_Start                                   0
#define GCREG_OVERLAY_CLEAR_VALUE_BLUE_Type                                  U08

/* 8 bit green color. */
#define GCREG_OVERLAY_CLEAR_VALUE_GREEN                                     15:8
#define GCREG_OVERLAY_CLEAR_VALUE_GREEN_End                                   15
#define GCREG_OVERLAY_CLEAR_VALUE_GREEN_Start                                  8
#define GCREG_OVERLAY_CLEAR_VALUE_GREEN_Type                                 U08

/* 8 bit red color. */
#define GCREG_OVERLAY_CLEAR_VALUE_RED                                      23:16
#define GCREG_OVERLAY_CLEAR_VALUE_RED_End                                     23
#define GCREG_OVERLAY_CLEAR_VALUE_RED_Start                                   16
#define GCREG_OVERLAY_CLEAR_VALUE_RED_Type                                   U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_CLEAR_VALUE_ALPHA                                    31:24
#define GCREG_OVERLAY_CLEAR_VALUE_ALPHA_End                                   31
#define GCREG_OVERLAY_CLEAR_VALUE_ALPHA_Start                                 24
#define GCREG_OVERLAY_CLEAR_VALUE_ALPHA_Type                                 U08

/* Register gcregOverlayConfig1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Configuration Register.  Overlay control.  NOTE: This register is  **
** double buffered.                                                           */

#define gcregOverlayConfig1RegAddrs                                       0x082C
#define GCREG_OVERLAY_CONFIG1_Address                                    0x000B0
#define GCREG_OVERLAY_CONFIG1_MSB                                             15
#define GCREG_OVERLAY_CONFIG1_LSB                                              0
#define GCREG_OVERLAY_CONFIG1_BLK                                              0
#define GCREG_OVERLAY_CONFIG1_Count                                            1
#define GCREG_OVERLAY_CONFIG1_FieldMask                               0x0016002F
#define GCREG_OVERLAY_CONFIG1_ReadMask                                0x0016002F
#define GCREG_OVERLAY_CONFIG1_WriteMask                               0x0016002F
#define GCREG_OVERLAY_CONFIG1_ResetValue                              0x00000000

/* The format of the overlay.  None means there is no  overlay. NOTE: This    **
** field is double buffered.                                                  */
#define GCREG_OVERLAY_CONFIG1_FORMAT                                         2:0
#define GCREG_OVERLAY_CONFIG1_FORMAT_End                                       2
#define GCREG_OVERLAY_CONFIG1_FORMAT_Start                                     0
#define GCREG_OVERLAY_CONFIG1_FORMAT_Type                                    U03
#define   GCREG_OVERLAY_CONFIG1_FORMAT_NONE                                  0x0
#define   GCREG_OVERLAY_CONFIG1_FORMAT_A4R4G4B4                              0x1
#define   GCREG_OVERLAY_CONFIG1_FORMAT_A1R5G5B5                              0x2
#define   GCREG_OVERLAY_CONFIG1_FORMAT_R5G6B5                                0x3
#define   GCREG_OVERLAY_CONFIG1_FORMAT_A8R8G8B8                              0x4

/* Enable this overlay layer.  NOTE: This field is double buffered.  */
#define GCREG_OVERLAY_CONFIG1_ENABLE                                         3:3
#define GCREG_OVERLAY_CONFIG1_ENABLE_End                                       3
#define GCREG_OVERLAY_CONFIG1_ENABLE_Start                                     3
#define GCREG_OVERLAY_CONFIG1_ENABLE_Type                                    U01
#define   GCREG_OVERLAY_CONFIG1_ENABLE_DISABLE                               0x0
#define   GCREG_OVERLAY_CONFIG1_ENABLE_ENABLE                                0x1

/* Enable or disable clear. NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG1_CLEAR_EN                                       5:5
#define GCREG_OVERLAY_CONFIG1_CLEAR_EN_End                                     5
#define GCREG_OVERLAY_CONFIG1_CLEAR_EN_Start                                   5
#define GCREG_OVERLAY_CONFIG1_CLEAR_EN_Type                                  U01
#define   GCREG_OVERLAY_CONFIG1_CLEAR_EN_DISABLED                            0x0
#define   GCREG_OVERLAY_CONFIG1_CLEAR_EN_ENABLED                             0x1

/* NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG1_SWIZZLE                                      18:17
#define GCREG_OVERLAY_CONFIG1_SWIZZLE_End                                     18
#define GCREG_OVERLAY_CONFIG1_SWIZZLE_Start                                   17
#define GCREG_OVERLAY_CONFIG1_SWIZZLE_Type                                   U02
#define   GCREG_OVERLAY_CONFIG1_SWIZZLE_ARGB                                 0x0
#define   GCREG_OVERLAY_CONFIG1_SWIZZLE_RGBA                                 0x1
#define   GCREG_OVERLAY_CONFIG1_SWIZZLE_ABGR                                 0x2
#define   GCREG_OVERLAY_CONFIG1_SWIZZLE_BGRA                                 0x3

/* Enable or disable color key. NOTE: This field is double buffered. */
#define GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN                                 20:20
#define GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_End                                20
#define GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_Start                              20
#define GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_Type                              U01
#define   GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_DISABLED                        0x0
#define   GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_ENABLED                         0x1

/* Register gcregOverlayAddress1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Starting address of the overlay. NOTE: This register is double buffered. */

#define gcregOverlayAddress1RegAddrs                                      0x082D
#define GCREG_OVERLAY_ADDRESS1_Address                                   0x000B4
#define GCREG_OVERLAY_ADDRESS1_MSB                                            15
#define GCREG_OVERLAY_ADDRESS1_LSB                                             0
#define GCREG_OVERLAY_ADDRESS1_BLK                                             0
#define GCREG_OVERLAY_ADDRESS1_Count                                           1
#define GCREG_OVERLAY_ADDRESS1_FieldMask                              0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS1_ReadMask                               0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS1_WriteMask                              0xFFFFFFFF
#define GCREG_OVERLAY_ADDRESS1_ResetValue                             0x00000000

/* 32 bit address. */
#define GCREG_OVERLAY_ADDRESS1_ADDRESS                                      31:0
#define GCREG_OVERLAY_ADDRESS1_ADDRESS_End                                    31
#define GCREG_OVERLAY_ADDRESS1_ADDRESS_Start                                   0
#define GCREG_OVERLAY_ADDRESS1_ADDRESS_Type                                  U32

/* Register gcregOverlayStride1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Stride of the overlay in bytes. NOTE: This register is double buffered. */

#define gcregOverlayStride1RegAddrs                                       0x082E
#define GCREG_OVERLAY_STRIDE1_Address                                    0x000B8
#define GCREG_OVERLAY_STRIDE1_MSB                                             15
#define GCREG_OVERLAY_STRIDE1_LSB                                              0
#define GCREG_OVERLAY_STRIDE1_BLK                                              0
#define GCREG_OVERLAY_STRIDE1_Count                                            1
#define GCREG_OVERLAY_STRIDE1_FieldMask                               0x0001FFFF
#define GCREG_OVERLAY_STRIDE1_ReadMask                                0x0001FFFF
#define GCREG_OVERLAY_STRIDE1_WriteMask                               0x0001FFFF
#define GCREG_OVERLAY_STRIDE1_ResetValue                              0x00000000

/* Number of bytes from start of one line to next line. */
#define GCREG_OVERLAY_STRIDE1_STRIDE                                        16:0
#define GCREG_OVERLAY_STRIDE1_STRIDE_End                                      16
#define GCREG_OVERLAY_STRIDE1_STRIDE_Start                                     0
#define GCREG_OVERLAY_STRIDE1_STRIDE_Type                                    U17

/* Register gcregOverlayTL1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Top left coordinate of panel pixel where the overlay should start.  Be     **
** aware there is no panning inside the overlay. NOTE: This register is       **
** double buffered.                                                           */

#define gcregOverlayTL1RegAddrs                                           0x082F
#define GCREG_OVERLAY_TL1_Address                                        0x000BC
#define GCREG_OVERLAY_TL1_MSB                                                 15
#define GCREG_OVERLAY_TL1_LSB                                                  0
#define GCREG_OVERLAY_TL1_BLK                                                  0
#define GCREG_OVERLAY_TL1_Count                                                1
#define GCREG_OVERLAY_TL1_FieldMask                                   0x0FFF0FFF
#define GCREG_OVERLAY_TL1_ReadMask                                    0x0FFF0FFF
#define GCREG_OVERLAY_TL1_WriteMask                                   0x0FFF0FFF
#define GCREG_OVERLAY_TL1_ResetValue                                  0x00000000

/* Left boundary of overlay window. */
#define GCREG_OVERLAY_TL1_X                                                 11:0
#define GCREG_OVERLAY_TL1_X_End                                               11
#define GCREG_OVERLAY_TL1_X_Start                                              0
#define GCREG_OVERLAY_TL1_X_Type                                             U12

/* Top boundary of overlay window. */
#define GCREG_OVERLAY_TL1_Y                                                27:16
#define GCREG_OVERLAY_TL1_Y_End                                               27
#define GCREG_OVERLAY_TL1_Y_Start                                             16
#define GCREG_OVERLAY_TL1_Y_Type                                             U12

/* Register gcregOverlaySize1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* overlay1 size information. NOTE: This register is double buffered. */

#define gcregOverlaySize1RegAddrs                                         0x0830
#define GCREG_OVERLAY_SIZE1_Address                                      0x000C0
#define GCREG_OVERLAY_SIZE1_MSB                                               15
#define GCREG_OVERLAY_SIZE1_LSB                                                0
#define GCREG_OVERLAY_SIZE1_BLK                                                0
#define GCREG_OVERLAY_SIZE1_Count                                              1
#define GCREG_OVERLAY_SIZE1_FieldMask                                 0x0FFF0FFF
#define GCREG_OVERLAY_SIZE1_ReadMask                                  0x0FFF0FFF
#define GCREG_OVERLAY_SIZE1_WriteMask                                 0x0FFF0FFF
#define GCREG_OVERLAY_SIZE1_ResetValue                                0x00000000

/* overlay1 width. */
#define GCREG_OVERLAY_SIZE1_WIDTH                                           11:0
#define GCREG_OVERLAY_SIZE1_WIDTH_End                                         11
#define GCREG_OVERLAY_SIZE1_WIDTH_Start                                        0
#define GCREG_OVERLAY_SIZE1_WIDTH_Type                                       U12

/* overlay1 height. */
#define GCREG_OVERLAY_SIZE1_HEIGHT                                         27:16
#define GCREG_OVERLAY_SIZE1_HEIGHT_End                                        27
#define GCREG_OVERLAY_SIZE1_HEIGHT_Start                                      16
#define GCREG_OVERLAY_SIZE1_HEIGHT_Type                                      U12

/* Register gcregOverlayColorKey1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Color Key Start Address Register.  Start of color key range for    **
** overlay.  NOTE: This register is double buffered.                          */

#define gcregOverlayColorKey1RegAddrs                                     0x0831
#define GCREG_OVERLAY_COLOR_KEY1_Address                                 0x000C4
#define GCREG_OVERLAY_COLOR_KEY1_MSB                                          15
#define GCREG_OVERLAY_COLOR_KEY1_LSB                                           0
#define GCREG_OVERLAY_COLOR_KEY1_BLK                                           0
#define GCREG_OVERLAY_COLOR_KEY1_Count                                         1
#define GCREG_OVERLAY_COLOR_KEY1_FieldMask                            0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY1_ReadMask                             0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY1_WriteMask                            0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY1_ResetValue                           0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_COLOR_KEY1_BLUE                                        7:0
#define GCREG_OVERLAY_COLOR_KEY1_BLUE_End                                      7
#define GCREG_OVERLAY_COLOR_KEY1_BLUE_Start                                    0
#define GCREG_OVERLAY_COLOR_KEY1_BLUE_Type                                   U08

/* 8 bit green color. */
#define GCREG_OVERLAY_COLOR_KEY1_GREEN                                      15:8
#define GCREG_OVERLAY_COLOR_KEY1_GREEN_End                                    15
#define GCREG_OVERLAY_COLOR_KEY1_GREEN_Start                                   8
#define GCREG_OVERLAY_COLOR_KEY1_GREEN_Type                                  U08

/* 8 bit red color. */
#define GCREG_OVERLAY_COLOR_KEY1_RED                                       23:16
#define GCREG_OVERLAY_COLOR_KEY1_RED_End                                      23
#define GCREG_OVERLAY_COLOR_KEY1_RED_Start                                    16
#define GCREG_OVERLAY_COLOR_KEY1_RED_Type                                    U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_COLOR_KEY1_ALPHA                                     31:24
#define GCREG_OVERLAY_COLOR_KEY1_ALPHA_End                                    31
#define GCREG_OVERLAY_COLOR_KEY1_ALPHA_Start                                  24
#define GCREG_OVERLAY_COLOR_KEY1_ALPHA_Type                                  U08

/* Register gcregOverlayColorKeyHigh1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Color Key End Address Register.  End of color key range for        **
** overlay.  NOTE: This register is double buffered.                          */

#define gcregOverlayColorKeyHigh1RegAddrs                                 0x0832
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_Address                            0x000C8
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_MSB                                     15
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_LSB                                      0
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_BLK                                      0
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_Count                                    1
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_FieldMask                       0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ReadMask                        0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_WriteMask                       0xFFFFFFFF
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ResetValue                      0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_BLUE                                   7:0
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_BLUE_End                                 7
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_BLUE_Start                               0
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_BLUE_Type                              U08

/* 8 bit green color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_GREEN                                 15:8
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_GREEN_End                               15
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_GREEN_Start                              8
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_GREEN_Type                             U08

/* 8 bit red color. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_RED                                  23:16
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_RED_End                                 23
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_RED_Start                               16
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_RED_Type                               U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ALPHA                                31:24
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ALPHA_End                               31
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ALPHA_Start                             24
#define GCREG_OVERLAY_COLOR_KEY_HIGH1_ALPHA_Type                             U08

/* Register gcregOverlayAlphaBlendConfig1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Alpha Blending Configuration Register.  NOTE: This register is double      **
** buffered.                                                                  */

#define gcregOverlayAlphaBlendConfig1RegAddrs                             0x0833
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_Address                        0x000CC
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_MSB                                 15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_LSB                                  0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_BLK                                  0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_Count                                1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_FieldMask                   0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ReadMask                    0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_WriteMask                   0x0000EFDB
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ResetValue                  0x00000000

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND                        0:0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_End                      0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_Start                    0
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_Type                   U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_DISABLED             0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_ENABLED              0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE                     1:1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE_End                   1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE_Start                 1
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE_Type                U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE_NORMAL            0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_MODE_INVERSED          0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE              4:3
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_End            4
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_Start          3
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_Type         U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_NORMAL     0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_GLOBAL     0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_GLOBAL_ALPHA_MODE_SCALED     0x2

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE                  7:6
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_End                7
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_Start              6
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_Type             U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_ZERO           0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_ONE            0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_NORMAL         0x2
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_BLENDING_MODE_INVERSED       0x3

/* Src Blending factor is calculated from Src alpha.  */
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR                   8:8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_End                 8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_Start               8
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_Type              U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_DISABLED        0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_ENABLED         0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE                     9:9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE_End                   9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE_Start                 9
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE_Type                U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE_NORMAL            0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_MODE_INVERSED          0x1

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE            11:10
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_End           11
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_Start         10
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_Type         U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_NORMAL     0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_GLOBAL     0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_GLOBAL_ALPHA_MODE_SCALED     0x2

#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE                14:13
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_End               14
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_Start             13
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_Type             U02
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_ZERO           0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_ONE            0x1
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_NORMAL         0x2
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_BLENDING_MODE_INVERSED       0x3

/* Destination blending factor is calculated from Dst alpha.  */
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR                 15:15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_End                15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_Start              15
#define GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_Type              U01
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_DISABLED        0x0
#define   GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_ENABLED         0x1

/* Register gcregOverlayGlobalAlpha1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay global alpha value.  NOTE: This register is double buffered.  */

#define gcregOverlayGlobalAlpha1RegAddrs                                  0x0834
#define GCREG_OVERLAY_GLOBAL_ALPHA1_Address                              0x000D0
#define GCREG_OVERLAY_GLOBAL_ALPHA1_MSB                                       15
#define GCREG_OVERLAY_GLOBAL_ALPHA1_LSB                                        0
#define GCREG_OVERLAY_GLOBAL_ALPHA1_BLK                                        0
#define GCREG_OVERLAY_GLOBAL_ALPHA1_Count                                      1
#define GCREG_OVERLAY_GLOBAL_ALPHA1_FieldMask                         0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA1_ReadMask                          0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA1_WriteMask                         0x0000FFFF
#define GCREG_OVERLAY_GLOBAL_ALPHA1_ResetValue                        0x00000000

#define GCREG_OVERLAY_GLOBAL_ALPHA1_SRC_ALPHA                                7:0
#define GCREG_OVERLAY_GLOBAL_ALPHA1_SRC_ALPHA_End                              7
#define GCREG_OVERLAY_GLOBAL_ALPHA1_SRC_ALPHA_Start                            0
#define GCREG_OVERLAY_GLOBAL_ALPHA1_SRC_ALPHA_Type                           U08

#define GCREG_OVERLAY_GLOBAL_ALPHA1_DST_ALPHA                               15:8
#define GCREG_OVERLAY_GLOBAL_ALPHA1_DST_ALPHA_End                             15
#define GCREG_OVERLAY_GLOBAL_ALPHA1_DST_ALPHA_Start                            8
#define GCREG_OVERLAY_GLOBAL_ALPHA1_DST_ALPHA_Type                           U08

/* Register gcregOverlayClearValue1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Overlay Clear Value Register.  Clear value used when                       **
** dcregOverlayConfig.Clear  is enabled, Format is A8R8G8B8.  NOTE: This      **
** register is double buffered.                                               */

#define gcregOverlayClearValue1RegAddrs                                   0x0835
#define GCREG_OVERLAY_CLEAR_VALUE1_Address                               0x000D4
#define GCREG_OVERLAY_CLEAR_VALUE1_MSB                                        15
#define GCREG_OVERLAY_CLEAR_VALUE1_LSB                                         0
#define GCREG_OVERLAY_CLEAR_VALUE1_BLK                                         0
#define GCREG_OVERLAY_CLEAR_VALUE1_Count                                       1
#define GCREG_OVERLAY_CLEAR_VALUE1_FieldMask                          0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE1_ReadMask                           0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE1_WriteMask                          0xFFFFFFFF
#define GCREG_OVERLAY_CLEAR_VALUE1_ResetValue                         0x00000000

/* 8 bit blue color. */
#define GCREG_OVERLAY_CLEAR_VALUE1_BLUE                                      7:0
#define GCREG_OVERLAY_CLEAR_VALUE1_BLUE_End                                    7
#define GCREG_OVERLAY_CLEAR_VALUE1_BLUE_Start                                  0
#define GCREG_OVERLAY_CLEAR_VALUE1_BLUE_Type                                 U08

/* 8 bit green color. */
#define GCREG_OVERLAY_CLEAR_VALUE1_GREEN                                    15:8
#define GCREG_OVERLAY_CLEAR_VALUE1_GREEN_End                                  15
#define GCREG_OVERLAY_CLEAR_VALUE1_GREEN_Start                                 8
#define GCREG_OVERLAY_CLEAR_VALUE1_GREEN_Type                                U08

/* 8 bit red color. */
#define GCREG_OVERLAY_CLEAR_VALUE1_RED                                     23:16
#define GCREG_OVERLAY_CLEAR_VALUE1_RED_End                                    23
#define GCREG_OVERLAY_CLEAR_VALUE1_RED_Start                                  16
#define GCREG_OVERLAY_CLEAR_VALUE1_RED_Type                                  U08

/* 8 bit alpha value. */
#define GCREG_OVERLAY_CLEAR_VALUE1_ALPHA                                   31:24
#define GCREG_OVERLAY_CLEAR_VALUE1_ALPHA_End                                  31
#define GCREG_OVERLAY_CLEAR_VALUE1_ALPHA_Start                                24
#define GCREG_OVERLAY_CLEAR_VALUE1_ALPHA_Type                                U08

/* Register gcregPanelDestAddress **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Panel Out Destination Start Address Register.  Starting address of the     **
** panel out path destination buffer.  It is used for debugging.  NOTE: This  **
** register is double buffered.                                               */

#define gcregPanelDestAddressRegAddrs                                     0x0836
#define GCREG_PANEL_DEST_ADDRESS_Address                                 0x000D8
#define GCREG_PANEL_DEST_ADDRESS_MSB                                          15
#define GCREG_PANEL_DEST_ADDRESS_LSB                                           0
#define GCREG_PANEL_DEST_ADDRESS_BLK                                           0
#define GCREG_PANEL_DEST_ADDRESS_Count                                         1
#define GCREG_PANEL_DEST_ADDRESS_FieldMask                            0xFFFFFFFF
#define GCREG_PANEL_DEST_ADDRESS_ReadMask                             0xFFFFFFFF
#define GCREG_PANEL_DEST_ADDRESS_WriteMask                            0xFFFFFFFF
#define GCREG_PANEL_DEST_ADDRESS_ResetValue                           0x00000000

/* 32 bit address. */
#define GCREG_PANEL_DEST_ADDRESS_ADDRESS                                    31:0
#define GCREG_PANEL_DEST_ADDRESS_ADDRESS_End                                  31
#define GCREG_PANEL_DEST_ADDRESS_ADDRESS_Start                                 0
#define GCREG_PANEL_DEST_ADDRESS_ADDRESS_Type                                U32

/* Register gcregDestStride **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Destination Stride Register.  Stride of the destinatin buffer in bytes.    **
** NOTE: This register is double buffered.                                    */

#define gcregDestStrideRegAddrs                                           0x0837
#define GCREG_DEST_STRIDE_Address                                        0x000DC
#define GCREG_DEST_STRIDE_MSB                                                 15
#define GCREG_DEST_STRIDE_LSB                                                  0
#define GCREG_DEST_STRIDE_BLK                                                  0
#define GCREG_DEST_STRIDE_Count                                                1
#define GCREG_DEST_STRIDE_FieldMask                                   0x0003FFFF
#define GCREG_DEST_STRIDE_ReadMask                                    0x0003FFFF
#define GCREG_DEST_STRIDE_WriteMask                                   0x0003FFFF
#define GCREG_DEST_STRIDE_ResetValue                                  0x00000000

/* Number of bytes from the start of one line to the next line.  */
#define GCREG_DEST_STRIDE_STRIDE                                            17:0
#define GCREG_DEST_STRIDE_STRIDE_End                                          17
#define GCREG_DEST_STRIDE_STRIDE_Start                                         0
#define GCREG_DEST_STRIDE_STRIDE_Type                                        U18

/* Register gcregDisplayDitherTableLow **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Dither Threshold Table Register.  */

#define gcregDisplayDitherTableLowRegAddrs                                0x0838
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Address                           0x000E0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_MSB                                    15
#define GCREG_DISPLAY_DITHER_TABLE_LOW_LSB                                     0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_BLK                                     0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Count                                   1
#define GCREG_DISPLAY_DITHER_TABLE_LOW_FieldMask                      0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_LOW_ReadMask                       0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_LOW_WriteMask                      0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_LOW_ResetValue                     0x00000000

/* Dither threshold value for x,y=0,0. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X0                                 3:0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_End                               3
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_Start                             0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_Type                            U04

/* Dither threshold value for x,y=1,0. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X1                                 7:4
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_End                               7
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_Start                             4
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_Type                            U04

/* Dither threshold value for x,y=2,0. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X2                                11:8
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_End                              11
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_Start                             8
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_Type                            U04

/* Dither threshold value for x,y=3,0. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X3                               15:12
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_End                              15
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_Start                            12
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_Type                            U04

/* Dither threshold value for x,y=0,1. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X0                               19:16
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_End                              19
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_Start                            16
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_Type                            U04

/* Dither threshold value for x,y=1,1. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X1                               23:20
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_End                              23
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_Start                            20
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_Type                            U04

/* Dither threshold value for x,y=2,1. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X2                               27:24
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_End                              27
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_Start                            24
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_Type                            U04

/* Dither threshold value for x,y=3,1. */
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X3                               31:28
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_End                              31
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_Start                            28
#define GCREG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_Type                            U04

/* Register gcregDisplayDitherTableHigh **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDisplayDitherTableHighRegAddrs                               0x0839
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Address                          0x000E4
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_MSB                                   15
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_LSB                                    0
#define GCREG_DISPLAY_DITHER_TABLE_LOW_HIGH_BLK                                0
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Count                                  1
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_FieldMask                     0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_ReadMask                      0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_WriteMask                     0xFFFFFFFF
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_ResetValue                    0x00000000

/* Dither threshold value for x,y=0,2. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0                                3:0
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_End                              3
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_Start                            0
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_Type                           U04

/* Dither threshold value for x,y=1,2. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1                                7:4
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_End                              7
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_Start                            4
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_Type                           U04

/* Dither threshold value for x,y=2,2. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2                               11:8
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_End                             11
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_Start                            8
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_Type                           U04

/* Dither threshold value for x,y=3,2. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3                              15:12
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_End                             15
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_Start                           12
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_Type                           U04

/* Dither threshold value for x,y=0,3. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0                              19:16
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_End                             19
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_Start                           16
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_Type                           U04

/* Dither threshold value for x,y=1,3. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1                              23:20
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_End                             23
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_Start                           20
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_Type                           U04

/* Dither threshold value for x,y=2,3. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2                              27:24
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_End                             27
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_Start                           24
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_Type                           U04

/* Dither threshold value for x,y=3,3. */
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3                              31:28
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_End                             31
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_Start                           28
#define GCREG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_Type                           U04

/* Register gcregPanelConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Panel Configuration Register.  */

#define gcregPanelConfigRegAddrs                                          0x083A
#define GCREG_PANEL_CONFIG_Address                                       0x000E8
#define GCREG_PANEL_CONFIG_MSB                                                15
#define GCREG_PANEL_CONFIG_LSB                                                 0
#define GCREG_PANEL_CONFIG_BLK                                                 0
#define GCREG_PANEL_CONFIG_Count                                               1
#define GCREG_PANEL_CONFIG_FieldMask                                  0x00033333
#define GCREG_PANEL_CONFIG_ReadMask                                   0x00033333
#define GCREG_PANEL_CONFIG_WriteMask                                  0x00033333
#define GCREG_PANEL_CONFIG_ResetValue                                 0x00000000

/* Data Enable enabled/disabled.  */
#define GCREG_PANEL_CONFIG_DE                                                0:0
#define GCREG_PANEL_CONFIG_DE_End                                              0
#define GCREG_PANEL_CONFIG_DE_Start                                            0
#define GCREG_PANEL_CONFIG_DE_Type                                           U01
#define   GCREG_PANEL_CONFIG_DE_DISABLED                                     0x0
#define   GCREG_PANEL_CONFIG_DE_ENABLED                                      0x1

/* Data Enable polarity. */
#define GCREG_PANEL_CONFIG_DE_POLARITY                                       1:1
#define GCREG_PANEL_CONFIG_DE_POLARITY_End                                     1
#define GCREG_PANEL_CONFIG_DE_POLARITY_Start                                   1
#define GCREG_PANEL_CONFIG_DE_POLARITY_Type                                  U01
#define   GCREG_PANEL_CONFIG_DE_POLARITY_POSITIVE                            0x0
#define   GCREG_PANEL_CONFIG_DE_POLARITY_NEGATIVE                            0x1

/* Data enabled/disabled.  */
#define GCREG_PANEL_CONFIG_DATA_ENABLE                                       4:4
#define GCREG_PANEL_CONFIG_DATA_ENABLE_End                                     4
#define GCREG_PANEL_CONFIG_DATA_ENABLE_Start                                   4
#define GCREG_PANEL_CONFIG_DATA_ENABLE_Type                                  U01
#define   GCREG_PANEL_CONFIG_DATA_ENABLE_DISABLED                            0x0
#define   GCREG_PANEL_CONFIG_DATA_ENABLE_ENABLED                             0x1

/* Data polarity. */
#define GCREG_PANEL_CONFIG_DATA_POLARITY                                     5:5
#define GCREG_PANEL_CONFIG_DATA_POLARITY_End                                   5
#define GCREG_PANEL_CONFIG_DATA_POLARITY_Start                                 5
#define GCREG_PANEL_CONFIG_DATA_POLARITY_Type                                U01
#define   GCREG_PANEL_CONFIG_DATA_POLARITY_POSITIVE                          0x0
#define   GCREG_PANEL_CONFIG_DATA_POLARITY_NEGATIVE                          0x1

/* Clock enable/disable. */
#define GCREG_PANEL_CONFIG_CLOCK                                             8:8
#define GCREG_PANEL_CONFIG_CLOCK_End                                           8
#define GCREG_PANEL_CONFIG_CLOCK_Start                                         8
#define GCREG_PANEL_CONFIG_CLOCK_Type                                        U01
#define   GCREG_PANEL_CONFIG_CLOCK_DISABLED                                  0x0
#define   GCREG_PANEL_CONFIG_CLOCK_ENABLED                                   0x1

/* Clock polarity. */
#define GCREG_PANEL_CONFIG_CLOCK_POLARITY                                    9:9
#define GCREG_PANEL_CONFIG_CLOCK_POLARITY_End                                  9
#define GCREG_PANEL_CONFIG_CLOCK_POLARITY_Start                                9
#define GCREG_PANEL_CONFIG_CLOCK_POLARITY_Type                               U01
#define   GCREG_PANEL_CONFIG_CLOCK_POLARITY_POSITIVE                         0x0
#define   GCREG_PANEL_CONFIG_CLOCK_POLARITY_NEGATIVE                         0x1

/* Power enable/disable. */
#define GCREG_PANEL_CONFIG_POWER                                           12:12
#define GCREG_PANEL_CONFIG_POWER_End                                          12
#define GCREG_PANEL_CONFIG_POWER_Start                                        12
#define GCREG_PANEL_CONFIG_POWER_Type                                        U01
#define   GCREG_PANEL_CONFIG_POWER_DISABLED                                  0x0
#define   GCREG_PANEL_CONFIG_POWER_ENABLED                                   0x1

/* Power polarity. */
#define GCREG_PANEL_CONFIG_POWER_POLARITY                                  13:13
#define GCREG_PANEL_CONFIG_POWER_POLARITY_End                                 13
#define GCREG_PANEL_CONFIG_POWER_POLARITY_Start                               13
#define GCREG_PANEL_CONFIG_POWER_POLARITY_Type                               U01
#define   GCREG_PANEL_CONFIG_POWER_POLARITY_POSITIVE                         0x0
#define   GCREG_PANEL_CONFIG_POWER_POLARITY_NEGATIVE                         0x1

/* Backlight enabled/disabled. */
#define GCREG_PANEL_CONFIG_BACKLIGHT                                       16:16
#define GCREG_PANEL_CONFIG_BACKLIGHT_End                                      16
#define GCREG_PANEL_CONFIG_BACKLIGHT_Start                                    16
#define GCREG_PANEL_CONFIG_BACKLIGHT_Type                                    U01
#define   GCREG_PANEL_CONFIG_BACKLIGHT_DISABLED                              0x0
#define   GCREG_PANEL_CONFIG_BACKLIGHT_ENABLED                               0x1

/* Backlight polarity. */
#define GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY                              17:17
#define GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY_End                             17
#define GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY_Start                           17
#define GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY_Type                           U01
#define   GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY_POSITIVE                     0x0
#define   GCREG_PANEL_CONFIG_BACKLIGHT_POLARITY_NEGATIVE                     0x1

/* Register gcregPanelControl **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Panel control Register. */

#define gcregPanelControlRegAddrs                                         0x083B
#define GCREG_PANEL_CONTROL_Address                                      0x000EC
#define GCREG_PANEL_CONTROL_MSB                                               15
#define GCREG_PANEL_CONTROL_LSB                                                0
#define GCREG_PANEL_CONTROL_BLK                                                0
#define GCREG_PANEL_CONTROL_Count                                              1
#define GCREG_PANEL_CONTROL_FieldMask                                 0x00000003
#define GCREG_PANEL_CONTROL_ReadMask                                  0x00000003
#define GCREG_PANEL_CONTROL_WriteMask                                 0x00000003
#define GCREG_PANEL_CONTROL_ResetValue                                0x00000000

/* The valid field defines whether we can copy a new set of registers at the  **
** next VBLANK or not.  This ensures a frame will always start with a valid   **
** working set if this register is programmed last, which reduces the need    **
** for SW to wait for the start of a VBLANK signal in order to ensure all     **
** states are loaded before the next VBLANK.                                  */
#define GCREG_PANEL_CONTROL_VALID                                            0:0
#define GCREG_PANEL_CONTROL_VALID_End                                          0
#define GCREG_PANEL_CONTROL_VALID_Start                                        0
#define GCREG_PANEL_CONTROL_VALID_Type                                       U01
#define   GCREG_PANEL_CONTROL_VALID_PENDING                                  0x0
#define   GCREG_PANEL_CONTROL_VALID_WORKING                                  0x1

/* Interface of DPI */
#define GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE                            1:1
#define GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE_End                          1
#define GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE_Start                        1
#define GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE_Type                       U01
#define   GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE_NO                       0x0
#define   GCREG_PANEL_CONTROL_BACK_PRESSURE_DISABLE_YES                      0x1

/* Register gcregPanelFunction **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Panel function Register. NOTE: This register is double buffered. */

#define gcregPanelFunctionRegAddrs                                        0x083C
#define GCREG_PANEL_FUNCTION_Address                                     0x000F0
#define GCREG_PANEL_FUNCTION_MSB                                              15
#define GCREG_PANEL_FUNCTION_LSB                                               0
#define GCREG_PANEL_FUNCTION_BLK                                               0
#define GCREG_PANEL_FUNCTION_Count                                             1
#define GCREG_PANEL_FUNCTION_FieldMask                                0x00000007
#define GCREG_PANEL_FUNCTION_ReadMask                                 0x00000007
#define GCREG_PANEL_FUNCTION_WriteMask                                0x00000007
#define GCREG_PANEL_FUNCTION_ResetValue                               0x00000000

/* When Output is enabled, pixels will be displayed.  When Output is          **
** disabled, all pixels will be black.  This allows a panel to have correct   **
** timing but without any pixels. NOTE: This field is double buffered.        */
#define GCREG_PANEL_FUNCTION_OUTPUT                                          0:0
#define GCREG_PANEL_FUNCTION_OUTPUT_End                                        0
#define GCREG_PANEL_FUNCTION_OUTPUT_Start                                      0
#define GCREG_PANEL_FUNCTION_OUTPUT_Type                                     U01
#define   GCREG_PANEL_FUNCTION_OUTPUT_DISABLED                               0x0
#define   GCREG_PANEL_FUNCTION_OUTPUT_ENABLED                                0x1

/* When Gamma is enabled, the R, G, and B channels will be routed through the **
** Gamma LUT to perform gamma correction. NOTE: This field is double          **
** buffered.                                                                  */
#define GCREG_PANEL_FUNCTION_GAMMA                                           1:1
#define GCREG_PANEL_FUNCTION_GAMMA_End                                         1
#define GCREG_PANEL_FUNCTION_GAMMA_Start                                       1
#define GCREG_PANEL_FUNCTION_GAMMA_Type                                      U01
#define   GCREG_PANEL_FUNCTION_GAMMA_DISABLED                                0x0
#define   GCREG_PANEL_FUNCTION_GAMMA_ENABLED                                 0x1

/* Enabling dithering allows R8G8B8 modes to show better on  panels with less **
** bits-per-pixel. NOTE: This field is double buffered.                       */
#define GCREG_PANEL_FUNCTION_DITHER                                          2:2
#define GCREG_PANEL_FUNCTION_DITHER_End                                        2
#define GCREG_PANEL_FUNCTION_DITHER_Start                                      2
#define GCREG_PANEL_FUNCTION_DITHER_Type                                     U01
#define   GCREG_PANEL_FUNCTION_DITHER_DISABLED                               0x0
#define   GCREG_PANEL_FUNCTION_DITHER_ENABLED                                0x1

/* Register gcregPanelWorking **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Register to trigger Display Controller. */

#define gcregPanelWorkingRegAddrs                                         0x083D
#define GCREG_PANEL_WORKING_Address                                      0x000F4
#define GCREG_PANEL_WORKING_MSB                                               15
#define GCREG_PANEL_WORKING_LSB                                                0
#define GCREG_PANEL_WORKING_BLK                                                0
#define GCREG_PANEL_WORKING_Count                                              1
#define GCREG_PANEL_WORKING_FieldMask                                 0x00000001
#define GCREG_PANEL_WORKING_ReadMask                                  0x00000000
#define GCREG_PANEL_WORKING_WriteMask                                 0x00000001
#define GCREG_PANEL_WORKING_ResetValue                                0x00000000

/* Writing a one in this register will force a reset of the display           **
** controller.  All registers will be copied to the working set and counters  **
** will be reset to the end of HSYNC and VSYNC.                               */
#define GCREG_PANEL_WORKING_WORKING                                          0:0
#define GCREG_PANEL_WORKING_WORKING_End                                        0
#define GCREG_PANEL_WORKING_WORKING_Start                                      0
#define GCREG_PANEL_WORKING_WORKING_Type                                     U01
#define   GCREG_PANEL_WORKING_WORKING_WORKING                                0x1

/* Register gcregPanelState **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Register representing the Display Controller status. */

#define gcregPanelStateRegAddrs                                           0x083E
#define GCREG_PANEL_STATE_Address                                        0x000F8
#define GCREG_PANEL_STATE_MSB                                                 15
#define GCREG_PANEL_STATE_LSB                                                  0
#define GCREG_PANEL_STATE_BLK                                                  0
#define GCREG_PANEL_STATE_Count                                                1
#define GCREG_PANEL_STATE_FieldMask                                   0x0000000F
#define GCREG_PANEL_STATE_ReadMask                                    0x0000000F
#define GCREG_PANEL_STATE_WriteMask                                   0x00000000
#define GCREG_PANEL_STATE_ResetValue                                  0x00000000

/* When the frame buffer address gets written to, this bit gets set to one.   **
** It will be reset to zero at the start of the next VBLANK when the register **
** gets copied into the working set.                                          */
#define GCREG_PANEL_STATE_FLIP_IN_PROGRESS                                   0:0
#define GCREG_PANEL_STATE_FLIP_IN_PROGRESS_End                                 0
#define GCREG_PANEL_STATE_FLIP_IN_PROGRESS_Start                               0
#define GCREG_PANEL_STATE_FLIP_IN_PROGRESS_Type                              U01
#define   GCREG_PANEL_STATE_FLIP_IN_PROGRESS_NO                              0x0
#define   GCREG_PANEL_STATE_FLIP_IN_PROGRESS_YES                             0x1

/* When the display FIFO underflows, this bit gets set to one.  Reading this  **
** register will reset it back to zero.                                       */
#define GCREG_PANEL_STATE_VIDEO_UNDER_FLOW                                   1:1
#define GCREG_PANEL_STATE_VIDEO_UNDER_FLOW_End                                 1
#define GCREG_PANEL_STATE_VIDEO_UNDER_FLOW_Start                               1
#define GCREG_PANEL_STATE_VIDEO_UNDER_FLOW_Type                              U01
#define   GCREG_PANEL_STATE_VIDEO_UNDER_FLOW_NO                              0x0
#define   GCREG_PANEL_STATE_VIDEO_UNDER_FLOW_YES                             0x1

/* When the overlay FIFO underflows, this bit gets set to  one. Reading this  **
** register will reset it back to zero.                                       */
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW                                 2:2
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW_End                               2
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW_Start                             2
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW_Type                            U01
#define   GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW_NO                            0x0
#define   GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW_YES                           0x1

/* When the overlay FIFO underflows, this bit gets set to  one. Reading this  **
** register will reset it back to zero.                                       */
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1                                3:3
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1_End                              3
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1_Start                            3
#define GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1_Type                           U01
#define   GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1_NO                           0x0
#define   GCREG_PANEL_STATE_OVERLAY_UNDER_FLOW1_YES                          0x1

/* Register gcregPanelTiming **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Panel Timing Register.  Timing for hardware panel sequencing.  */

#define gcregPanelTimingRegAddrs                                          0x083F
#define GCREG_PANEL_TIMING_Address                                       0x000FC
#define GCREG_PANEL_TIMING_MSB                                                15
#define GCREG_PANEL_TIMING_LSB                                                 0
#define GCREG_PANEL_TIMING_BLK                                                 0
#define GCREG_PANEL_TIMING_Count                                               1
#define GCREG_PANEL_TIMING_FieldMask                                  0xFFFFFFFF
#define GCREG_PANEL_TIMING_ReadMask                                   0xFFFFFFFF
#define GCREG_PANEL_TIMING_WriteMask                                  0xFFFFFFFF
#define GCREG_PANEL_TIMING_ResetValue                                 0x00000000

/* Number of VSYNCsto wait after power has been enabled. */
#define GCREG_PANEL_TIMING_POWER_ENABLE                                      3:0
#define GCREG_PANEL_TIMING_POWER_ENABLE_End                                    3
#define GCREG_PANEL_TIMING_POWER_ENABLE_Start                                  0
#define GCREG_PANEL_TIMING_POWER_ENABLE_Type                                 U04

/* Number of VSYNCs to wait after backlight has been enabled. */
#define GCREG_PANEL_TIMING_BACKLIGHT_ENABLE                                  7:4
#define GCREG_PANEL_TIMING_BACKLIGHT_ENABLE_End                                7
#define GCREG_PANEL_TIMING_BACKLIGHT_ENABLE_Start                              4
#define GCREG_PANEL_TIMING_BACKLIGHT_ENABLE_Type                             U04

/* Number of VSYNCs to wait after clock has been enabled. */
#define GCREG_PANEL_TIMING_CLOCK_ENABLE                                     11:8
#define GCREG_PANEL_TIMING_CLOCK_ENABLE_End                                   11
#define GCREG_PANEL_TIMING_CLOCK_ENABLE_Start                                  8
#define GCREG_PANEL_TIMING_CLOCK_ENABLE_Type                                 U04

/* Number of VSYNCs to wait after data has been enabled. */
#define GCREG_PANEL_TIMING_DATA_ENABLE                                     15:12
#define GCREG_PANEL_TIMING_DATA_ENABLE_End                                    15
#define GCREG_PANEL_TIMING_DATA_ENABLE_Start                                  12
#define GCREG_PANEL_TIMING_DATA_ENABLE_Type                                  U04

/* Number of VSYNCs to wait after data has been disabled. */
#define GCREG_PANEL_TIMING_DATA_DISABLE                                    19:16
#define GCREG_PANEL_TIMING_DATA_DISABLE_End                                   19
#define GCREG_PANEL_TIMING_DATA_DISABLE_Start                                 16
#define GCREG_PANEL_TIMING_DATA_DISABLE_Type                                 U04

/* Number of VSYNCs to wait after clock has been disabled. */
#define GCREG_PANEL_TIMING_CLOCK_DISABLE                                   23:20
#define GCREG_PANEL_TIMING_CLOCK_DISABLE_End                                  23
#define GCREG_PANEL_TIMING_CLOCK_DISABLE_Start                                20
#define GCREG_PANEL_TIMING_CLOCK_DISABLE_Type                                U04

/* Number of VSYNCs to wait after backlight has been disabled. */
#define GCREG_PANEL_TIMING_BACKLIGHT_DISABLE                               27:24
#define GCREG_PANEL_TIMING_BACKLIGHT_DISABLE_End                              27
#define GCREG_PANEL_TIMING_BACKLIGHT_DISABLE_Start                            24
#define GCREG_PANEL_TIMING_BACKLIGHT_DISABLE_Type                            U04

/* Number of VSYNCs to wait after power has been disabled. */
#define GCREG_PANEL_TIMING_POWER_DISABLE                                   31:28
#define GCREG_PANEL_TIMING_POWER_DISABLE_End                                  31
#define GCREG_PANEL_TIMING_POWER_DISABLE_Start                                28
#define GCREG_PANEL_TIMING_POWER_DISABLE_Type                                U04

/* Register gcregHDisplay **
** ~~~~~~~~~~~~~~~~~~~~~~ */

/* Horizontal Display Total and Visible Pixel Count Register.  Horizontal     **
** Total and Display End counters.  NOTE: This register is double buffered.   */

#define gcregHDisplayRegAddrs                                             0x0840
#define GCREG_HDISPLAY_Address                                           0x00100
#define GCREG_HDISPLAY_MSB                                                    15
#define GCREG_HDISPLAY_LSB                                                     0
#define GCREG_HDISPLAY_BLK                                                     0
#define GCREG_HDISPLAY_Count                                                   1
#define GCREG_HDISPLAY_FieldMask                                      0x1FFF1FFF
#define GCREG_HDISPLAY_ReadMask                                       0x1FFF1FFF
#define GCREG_HDISPLAY_WriteMask                                      0x1FFF1FFF
#define GCREG_HDISPLAY_ResetValue                                     0x00000000

/* Number of visible horizontal pixels. NOTE: This field is double buffered. */
#define GCREG_HDISPLAY_DISPLAY_END                                          12:0
#define GCREG_HDISPLAY_DISPLAY_END_End                                        12
#define GCREG_HDISPLAY_DISPLAY_END_Start                                       0
#define GCREG_HDISPLAY_DISPLAY_END_Type                                      U13

/* Total number of horizontal pixels. NOTE: This field is double buffered. */
#define GCREG_HDISPLAY_TOTAL                                               28:16
#define GCREG_HDISPLAY_TOTAL_End                                              28
#define GCREG_HDISPLAY_TOTAL_Start                                            16
#define GCREG_HDISPLAY_TOTAL_Type                                            U13

/* Register gcregHSync **
** ~~~~~~~~~~~~~~~~~~~ */

/* Horizontal Sync Counter Register.  Horizontal Sync counters.  NOTE: This   **
** register is double buffered.                                               */

#define gcregHSyncRegAddrs                                                0x0841
#define GCREG_HSYNC_Address                                              0x00104
#define GCREG_HSYNC_MSB                                                       15
#define GCREG_HSYNC_LSB                                                        0
#define GCREG_HSYNC_BLK                                                        0
#define GCREG_HSYNC_Count                                                      1
#define GCREG_HSYNC_FieldMask                                         0xDFFF1FFF
#define GCREG_HSYNC_ReadMask                                          0xDFFF1FFF
#define GCREG_HSYNC_WriteMask                                         0xDFFF1FFF
#define GCREG_HSYNC_ResetValue                                        0x00000000

/* Start of horizontal sync pulse.  NOTE: This field is double buffered. */
#define GCREG_HSYNC_START                                                   12:0
#define GCREG_HSYNC_START_End                                                 12
#define GCREG_HSYNC_START_Start                                                0
#define GCREG_HSYNC_START_Type                                               U13

/* End of horizontal sync pulse.  NOTE: This field is double buffered. */
#define GCREG_HSYNC_END                                                    28:16
#define GCREG_HSYNC_END_End                                                   28
#define GCREG_HSYNC_END_Start                                                 16
#define GCREG_HSYNC_END_Type                                                 U13

/* Horizontal sync pulse control.  NOTE: This field is double buffered. */
#define GCREG_HSYNC_PULSE                                                  30:30
#define GCREG_HSYNC_PULSE_End                                                 30
#define GCREG_HSYNC_PULSE_Start                                               30
#define GCREG_HSYNC_PULSE_Type                                               U01
#define   GCREG_HSYNC_PULSE_DISABLED                                         0x0
#define   GCREG_HSYNC_PULSE_ENABLED                                          0x1

/* Polarity of the horizontal sync pulse.  NOTE: This field is double         **
** buffered.                                                                  */
#define GCREG_HSYNC_POLARITY                                               31:31
#define GCREG_HSYNC_POLARITY_End                                              31
#define GCREG_HSYNC_POLARITY_Start                                            31
#define GCREG_HSYNC_POLARITY_Type                                            U01
#define   GCREG_HSYNC_POLARITY_POSITIVE                                      0x0
#define   GCREG_HSYNC_POLARITY_NEGATIVE                                      0x1

/* Register gcregHCounter1 **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Horizontal Programmable Counter 1 Register.  */

#define gcregHCounter1RegAddrs                                            0x0842
#define GCREG_HCOUNTER1_Address                                          0x00108
#define GCREG_HCOUNTER1_MSB                                                   15
#define GCREG_HCOUNTER1_LSB                                                    0
#define GCREG_HCOUNTER1_BLK                                                    0
#define GCREG_HCOUNTER1_Count                                                  1
#define GCREG_HCOUNTER1_FieldMask                                     0xCFFF0FFF
#define GCREG_HCOUNTER1_ReadMask                                      0xCFFF0FFF
#define GCREG_HCOUNTER1_WriteMask                                     0xCFFF0FFF
#define GCREG_HCOUNTER1_ResetValue                                    0x00000000

/* Start of horizontal counter 1.  */
#define GCREG_HCOUNTER1_START                                               11:0
#define GCREG_HCOUNTER1_START_End                                             11
#define GCREG_HCOUNTER1_START_Start                                            0
#define GCREG_HCOUNTER1_START_Type                                           U12

/* End of horizontal counter 1.  */
#define GCREG_HCOUNTER1_END                                                27:16
#define GCREG_HCOUNTER1_END_End                                               27
#define GCREG_HCOUNTER1_END_Start                                             16
#define GCREG_HCOUNTER1_END_Type                                             U12

/* Horizontal counter 1 control.  */
#define GCREG_HCOUNTER1_PULSE                                              30:30
#define GCREG_HCOUNTER1_PULSE_End                                             30
#define GCREG_HCOUNTER1_PULSE_Start                                           30
#define GCREG_HCOUNTER1_PULSE_Type                                           U01
#define   GCREG_HCOUNTER1_PULSE_DISABLED                                     0x0
#define   GCREG_HCOUNTER1_PULSE_ENABLED                                      0x1

/* Polarity of the pulse.  */
#define GCREG_HCOUNTER1_POLARITY                                           31:31
#define GCREG_HCOUNTER1_POLARITY_End                                          31
#define GCREG_HCOUNTER1_POLARITY_Start                                        31
#define GCREG_HCOUNTER1_POLARITY_Type                                        U01
#define   GCREG_HCOUNTER1_POLARITY_POSITIVE                                  0x0
#define   GCREG_HCOUNTER1_POLARITY_NEGATIVE                                  0x1

/* Register gcregHCounter2 **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Horizontal Programmable Counter 2 Register.  */

#define gcregHCounter2RegAddrs                                            0x0843
#define GCREG_HCOUNTER2_Address                                          0x0010C
#define GCREG_HCOUNTER2_MSB                                                   15
#define GCREG_HCOUNTER2_LSB                                                    0
#define GCREG_HCOUNTER2_BLK                                                    0
#define GCREG_HCOUNTER2_Count                                                  1
#define GCREG_HCOUNTER2_FieldMask                                     0xCFFF0FFF
#define GCREG_HCOUNTER2_ReadMask                                      0xCFFF0FFF
#define GCREG_HCOUNTER2_WriteMask                                     0xCFFF0FFF
#define GCREG_HCOUNTER2_ResetValue                                    0x00000000

/* Start of horizontal counter 2. */
#define GCREG_HCOUNTER2_START                                               11:0
#define GCREG_HCOUNTER2_START_End                                             11
#define GCREG_HCOUNTER2_START_Start                                            0
#define GCREG_HCOUNTER2_START_Type                                           U12

/* End of horizontal counter 2. */
#define GCREG_HCOUNTER2_END                                                27:16
#define GCREG_HCOUNTER2_END_End                                               27
#define GCREG_HCOUNTER2_END_Start                                             16
#define GCREG_HCOUNTER2_END_Type                                             U12

/* Horizontal counter 2 control. */
#define GCREG_HCOUNTER2_PULSE                                              30:30
#define GCREG_HCOUNTER2_PULSE_End                                             30
#define GCREG_HCOUNTER2_PULSE_Start                                           30
#define GCREG_HCOUNTER2_PULSE_Type                                           U01
#define   GCREG_HCOUNTER2_PULSE_DISABLED                                     0x0
#define   GCREG_HCOUNTER2_PULSE_ENABLED                                      0x1

/* Polarity of the pulse. */
#define GCREG_HCOUNTER2_POLARITY                                           31:31
#define GCREG_HCOUNTER2_POLARITY_End                                          31
#define GCREG_HCOUNTER2_POLARITY_Start                                        31
#define GCREG_HCOUNTER2_POLARITY_Type                                        U01
#define   GCREG_HCOUNTER2_POLARITY_POSITIVE                                  0x0
#define   GCREG_HCOUNTER2_POLARITY_NEGATIVE                                  0x1

/* Register gcregVDisplay **
** ~~~~~~~~~~~~~~~~~~~~~~ */

/* Vertical Total and Visible Pixel Count Register.  Vertical Total and       **
** Display End counters.  NOTE: This register is double buffered.             */

#define gcregVDisplayRegAddrs                                             0x0844
#define GCREG_VDISPLAY_Address                                           0x00110
#define GCREG_VDISPLAY_MSB                                                    15
#define GCREG_VDISPLAY_LSB                                                     0
#define GCREG_VDISPLAY_BLK                                                     0
#define GCREG_VDISPLAY_Count                                                   1
#define GCREG_VDISPLAY_FieldMask                                      0x0FFF0FFF
#define GCREG_VDISPLAY_ReadMask                                       0x0FFF0FFF
#define GCREG_VDISPLAY_WriteMask                                      0x0FFF0FFF
#define GCREG_VDISPLAY_ResetValue                                     0x00000000

/* Number of visible vertical lines.  NOTE: This field is double buffered. */
#define GCREG_VDISPLAY_DISPLAY_END                                          11:0
#define GCREG_VDISPLAY_DISPLAY_END_End                                        11
#define GCREG_VDISPLAY_DISPLAY_END_Start                                       0
#define GCREG_VDISPLAY_DISPLAY_END_Type                                      U12

/* Total number of vertical lines.  NOTE: This field is double buffered. */
#define GCREG_VDISPLAY_TOTAL                                               27:16
#define GCREG_VDISPLAY_TOTAL_End                                              27
#define GCREG_VDISPLAY_TOTAL_Start                                            16
#define GCREG_VDISPLAY_TOTAL_Type                                            U12

/* Register gcregVSync **
** ~~~~~~~~~~~~~~~~~~~ */

/* Vertical Sync Counter Register.  Vertical Sync counters.  NOTE: This       **
** register is double buffered.                                               */

#define gcregVSyncRegAddrs                                                0x0845
#define GCREG_VSYNC_Address                                              0x00114
#define GCREG_VSYNC_MSB                                                       15
#define GCREG_VSYNC_LSB                                                        0
#define GCREG_VSYNC_BLK                                                        0
#define GCREG_VSYNC_Count                                                      1
#define GCREG_VSYNC_FieldMask                                         0xCFFF0FFF
#define GCREG_VSYNC_ReadMask                                          0xCFFF0FFF
#define GCREG_VSYNC_WriteMask                                         0xCFFF0FFF
#define GCREG_VSYNC_ResetValue                                        0x00000000

/* Start of the vertical sync pulse. NOTE: This field is double buffered. */
#define GCREG_VSYNC_START                                                   11:0
#define GCREG_VSYNC_START_End                                                 11
#define GCREG_VSYNC_START_Start                                                0
#define GCREG_VSYNC_START_Type                                               U12

/* End of the vertical sync pulse. NOTE: This field is double buffered. */
#define GCREG_VSYNC_END                                                    27:16
#define GCREG_VSYNC_END_End                                                   27
#define GCREG_VSYNC_END_Start                                                 16
#define GCREG_VSYNC_END_Type                                                 U12

/* Vertical sync pulse control. NOTE: This field is double buffered. */
#define GCREG_VSYNC_PULSE                                                  30:30
#define GCREG_VSYNC_PULSE_End                                                 30
#define GCREG_VSYNC_PULSE_Start                                               30
#define GCREG_VSYNC_PULSE_Type                                               U01
#define   GCREG_VSYNC_PULSE_DISABLED                                         0x0
#define   GCREG_VSYNC_PULSE_ENABLED                                          0x1

/* Polarity of the vertical sync pulse. NOTE: This field is double buffered. */
#define GCREG_VSYNC_POLARITY                                               31:31
#define GCREG_VSYNC_POLARITY_End                                              31
#define GCREG_VSYNC_POLARITY_Start                                            31
#define GCREG_VSYNC_POLARITY_Type                                            U01
#define   GCREG_VSYNC_POLARITY_POSITIVE                                      0x0
#define   GCREG_VSYNC_POLARITY_NEGATIVE                                      0x1

/* Register gcregDisplayCurrentLocation **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Display Current Location Register.  Current x,y location of display        **
** controller. READ ONLY.                                                     */

#define gcregDisplayCurrentLocationRegAddrs                               0x0846
#define GCREG_DISPLAY_CURRENT_LOCATION_Address                           0x00118
#define GCREG_DISPLAY_CURRENT_LOCATION_MSB                                    15
#define GCREG_DISPLAY_CURRENT_LOCATION_LSB                                     0
#define GCREG_DISPLAY_CURRENT_LOCATION_BLK                                     0
#define GCREG_DISPLAY_CURRENT_LOCATION_Count                                   1
#define GCREG_DISPLAY_CURRENT_LOCATION_FieldMask                      0xFFFFFFFF
#define GCREG_DISPLAY_CURRENT_LOCATION_ReadMask                       0xFFFFFFFF
#define GCREG_DISPLAY_CURRENT_LOCATION_WriteMask                      0x00000000
#define GCREG_DISPLAY_CURRENT_LOCATION_ResetValue                     0x00000000

/* Current X location. */
#define GCREG_DISPLAY_CURRENT_LOCATION_X                                    15:0
#define GCREG_DISPLAY_CURRENT_LOCATION_X_End                                  15
#define GCREG_DISPLAY_CURRENT_LOCATION_X_Start                                 0
#define GCREG_DISPLAY_CURRENT_LOCATION_X_Type                                U16

/* Current Y location. */
#define GCREG_DISPLAY_CURRENT_LOCATION_Y                                   31:16
#define GCREG_DISPLAY_CURRENT_LOCATION_Y_End                                  31
#define GCREG_DISPLAY_CURRENT_LOCATION_Y_Start                                16
#define GCREG_DISPLAY_CURRENT_LOCATION_Y_Type                                U16

/* Register gcregGammaIndex **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Gamma Index Register.  Index into gamma table.  See gcregGammaData for     **
** more  information.                                                         */

#define gcregGammaIndexRegAddrs                                           0x0847
#define GCREG_GAMMA_INDEX_Address                                        0x0011C
#define GCREG_GAMMA_INDEX_MSB                                                 15
#define GCREG_GAMMA_INDEX_LSB                                                  0
#define GCREG_GAMMA_INDEX_BLK                                                  0
#define GCREG_GAMMA_INDEX_Count                                                1
#define GCREG_GAMMA_INDEX_FieldMask                                   0x000000FF
#define GCREG_GAMMA_INDEX_ReadMask                                    0x00000000
#define GCREG_GAMMA_INDEX_WriteMask                                   0x000000FF
#define GCREG_GAMMA_INDEX_ResetValue                                  0x00000000

/* Index into gamma table. */
#define GCREG_GAMMA_INDEX_INDEX                                              7:0
#define GCREG_GAMMA_INDEX_INDEX_End                                            7
#define GCREG_GAMMA_INDEX_INDEX_Start                                          0
#define GCREG_GAMMA_INDEX_INDEX_Type                                         U08

/* Register gcregGammaData **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Gamma Data Register.  Translation values for the gamma table.  When this   **
** register  gets written, the data gets stored in the gamma table at the     **
** index specified by the gcregGammaIndex register.  After the  register is   **
** written, the index gets incremented.                                       */

#define gcregGammaDataRegAddrs                                            0x0848
#define GCREG_GAMMA_DATA_Address                                         0x00120
#define GCREG_GAMMA_DATA_MSB                                                  15
#define GCREG_GAMMA_DATA_LSB                                                   0
#define GCREG_GAMMA_DATA_BLK                                                   0
#define GCREG_GAMMA_DATA_Count                                                 1
#define GCREG_GAMMA_DATA_FieldMask                                    0x00FFFFFF
#define GCREG_GAMMA_DATA_ReadMask                                     0x00000000
#define GCREG_GAMMA_DATA_WriteMask                                    0x00FFFFFF
#define GCREG_GAMMA_DATA_ResetValue                                   0x00000000

/* Blue translation value. */
#define GCREG_GAMMA_DATA_BLUE                                                7:0
#define GCREG_GAMMA_DATA_BLUE_End                                              7
#define GCREG_GAMMA_DATA_BLUE_Start                                            0
#define GCREG_GAMMA_DATA_BLUE_Type                                           U08

/* Green translation value. */
#define GCREG_GAMMA_DATA_GREEN                                              15:8
#define GCREG_GAMMA_DATA_GREEN_End                                            15
#define GCREG_GAMMA_DATA_GREEN_Start                                           8
#define GCREG_GAMMA_DATA_GREEN_Type                                          U08

/* Red translation value. */
#define GCREG_GAMMA_DATA_RED                                               23:16
#define GCREG_GAMMA_DATA_RED_End                                              23
#define GCREG_GAMMA_DATA_RED_Start                                            16
#define GCREG_GAMMA_DATA_RED_Type                                            U08

/* Register gcregCursorConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Cursor Configuration Register.  Configuration register for the cursor.     **
** Double-buffered values in this register cannot be read  while a flip is in **
** progress.  NOTE: This register is double buffered.                         */

#define gcregCursorConfigRegAddrs                                         0x0849
#define GCREG_CURSOR_CONFIG_Address                                      0x00124
#define GCREG_CURSOR_CONFIG_MSB                                               15
#define GCREG_CURSOR_CONFIG_LSB                                                0
#define GCREG_CURSOR_CONFIG_BLK                                                0
#define GCREG_CURSOR_CONFIG_Count                                              1
#define GCREG_CURSOR_CONFIG_FieldMask                                 0x801F1F13
#define GCREG_CURSOR_CONFIG_ReadMask                                  0x801F1F13
#define GCREG_CURSOR_CONFIG_WriteMask                                 0x001F1F13
#define GCREG_CURSOR_CONFIG_ResetValue                                0x00000000

/* Format of the cursor.  NOTE: This field is double buffered. */
#define GCREG_CURSOR_CONFIG_FORMAT                                           1:0
#define GCREG_CURSOR_CONFIG_FORMAT_End                                         1
#define GCREG_CURSOR_CONFIG_FORMAT_Start                                       0
#define GCREG_CURSOR_CONFIG_FORMAT_Type                                      U02
#define   GCREG_CURSOR_CONFIG_FORMAT_DISABLED                                0x0
#define   GCREG_CURSOR_CONFIG_FORMAT_MASKED                                  0x1
#define   GCREG_CURSOR_CONFIG_FORMAT_A8R8G8B8                                0x2

/* Display Controller owning the cursor. Always 0 for this IP. NOTE: This     **
** field is double buffered.                                                  */
#define GCREG_CURSOR_CONFIG_DISPLAY                                          4:4
#define GCREG_CURSOR_CONFIG_DISPLAY_End                                        4
#define GCREG_CURSOR_CONFIG_DISPLAY_Start                                      4
#define GCREG_CURSOR_CONFIG_DISPLAY_Type                                     U01
#define   GCREG_CURSOR_CONFIG_DISPLAY_DISPLAY0                               0x0
#define   GCREG_CURSOR_CONFIG_DISPLAY_DISPLAY1                               0x1

/* Vertical offset to cursor hotspot.  NOTE: This field is double buffered. */
#define GCREG_CURSOR_CONFIG_HOT_SPOT_Y                                      12:8
#define GCREG_CURSOR_CONFIG_HOT_SPOT_Y_End                                    12
#define GCREG_CURSOR_CONFIG_HOT_SPOT_Y_Start                                   8
#define GCREG_CURSOR_CONFIG_HOT_SPOT_Y_Type                                  U05

/* Horizontal offset to cursor hotspot.  NOTE: This field is double buffered. */
#define GCREG_CURSOR_CONFIG_HOT_SPOT_X                                     20:16
#define GCREG_CURSOR_CONFIG_HOT_SPOT_X_End                                    20
#define GCREG_CURSOR_CONFIG_HOT_SPOT_X_Start                                  16
#define GCREG_CURSOR_CONFIG_HOT_SPOT_X_Type                                  U05

/* When the cursor address gets written to, this bit gets set  to one.  It    **
** will be reset to zero at the start of the next  VBLANK of the owning       **
** display when the register gets copied  into the working set. NOTE: This    **
** field is double buffered.                                                  */
#define GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS                               31:31
#define GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS_End                              31
#define GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS_Start                            31
#define GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS_Type                            U01
#define   GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS_NO                            0x0
#define   GCREG_CURSOR_CONFIG_FLIP_IN_PROGRESS_YES                           0x1

/* Register gcregCursorAddress **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Cursor Base Address Register.  Address of the cursor shape.  NOTE: This    **
** register is double buffered.                                               */

#define gcregCursorAddressRegAddrs                                        0x084A
#define GCREG_CURSOR_ADDRESS_Address                                     0x00128
#define GCREG_CURSOR_ADDRESS_MSB                                              15
#define GCREG_CURSOR_ADDRESS_LSB                                               0
#define GCREG_CURSOR_ADDRESS_BLK                                               0
#define GCREG_CURSOR_ADDRESS_Count                                             1
#define GCREG_CURSOR_ADDRESS_FieldMask                                0xFFFFFFFF
#define GCREG_CURSOR_ADDRESS_ReadMask                                 0xFFFFFFFF
#define GCREG_CURSOR_ADDRESS_WriteMask                                0xFFFFFFFF
#define GCREG_CURSOR_ADDRESS_ResetValue                               0x00000000

/* 32 bit address. */
#define GCREG_CURSOR_ADDRESS_ADDRESS                                        31:0
#define GCREG_CURSOR_ADDRESS_ADDRESS_End                                      31
#define GCREG_CURSOR_ADDRESS_ADDRESS_Start                                     0
#define GCREG_CURSOR_ADDRESS_ADDRESS_Type                                    U32

/* Register gcregCursorLocation **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Cursor Location Register.  Location of the cursor on the owning display.   **
** NOTE: This register is double buffered.                                    */

#define gcregCursorLocationRegAddrs                                       0x084B
#define GCREG_CURSOR_LOCATION_Address                                    0x0012C
#define GCREG_CURSOR_LOCATION_MSB                                             15
#define GCREG_CURSOR_LOCATION_LSB                                              0
#define GCREG_CURSOR_LOCATION_BLK                                              0
#define GCREG_CURSOR_LOCATION_Count                                            1
#define GCREG_CURSOR_LOCATION_FieldMask                               0x0FFF1FFF
#define GCREG_CURSOR_LOCATION_ReadMask                                0x0FFF1FFF
#define GCREG_CURSOR_LOCATION_WriteMask                               0x0FFF1FFF
#define GCREG_CURSOR_LOCATION_ResetValue                              0x00000000

/* X location of cursor's hotspot.  NOTE: This field is double buffered. */
#define GCREG_CURSOR_LOCATION_X                                             12:0
#define GCREG_CURSOR_LOCATION_X_End                                           12
#define GCREG_CURSOR_LOCATION_X_Start                                          0
#define GCREG_CURSOR_LOCATION_X_Type                                         U13

/* Y location of cursor's hotspot.  NOTE: This field is double buffered. */
#define GCREG_CURSOR_LOCATION_Y                                            27:16
#define GCREG_CURSOR_LOCATION_Y_End                                           27
#define GCREG_CURSOR_LOCATION_Y_Start                                         16
#define GCREG_CURSOR_LOCATION_Y_Type                                         U12

/* Register gcregCursorBackground **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Cursor Background Color Register.  The background color for Masked         **
** cursors.  NOTE: This register is double buffered.                          */

#define gcregCursorBackgroundRegAddrs                                     0x084C
#define GCREG_CURSOR_BACKGROUND_Address                                  0x00130
#define GCREG_CURSOR_BACKGROUND_MSB                                           15
#define GCREG_CURSOR_BACKGROUND_LSB                                            0
#define GCREG_CURSOR_BACKGROUND_BLK                                            0
#define GCREG_CURSOR_BACKGROUND_Count                                          1
#define GCREG_CURSOR_BACKGROUND_FieldMask                             0x00FFFFFF
#define GCREG_CURSOR_BACKGROUND_ReadMask                              0x00FFFFFF
#define GCREG_CURSOR_BACKGROUND_WriteMask                             0x00FFFFFF
#define GCREG_CURSOR_BACKGROUND_ResetValue                            0x00000000

/* Blue value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_BACKGROUND_BLUE                                         7:0
#define GCREG_CURSOR_BACKGROUND_BLUE_End                                       7
#define GCREG_CURSOR_BACKGROUND_BLUE_Start                                     0
#define GCREG_CURSOR_BACKGROUND_BLUE_Type                                    U08

/* Green value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_BACKGROUND_GREEN                                       15:8
#define GCREG_CURSOR_BACKGROUND_GREEN_End                                     15
#define GCREG_CURSOR_BACKGROUND_GREEN_Start                                    8
#define GCREG_CURSOR_BACKGROUND_GREEN_Type                                   U08

/* Red value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_BACKGROUND_RED                                        23:16
#define GCREG_CURSOR_BACKGROUND_RED_End                                       23
#define GCREG_CURSOR_BACKGROUND_RED_Start                                     16
#define GCREG_CURSOR_BACKGROUND_RED_Type                                     U08

/* Register gcregCursorForeground **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Cursor Foreground Color Register.  The foreground color for Masked         **
** cursors.  NOTE: This register is double buffered.                          */

#define gcregCursorForegroundRegAddrs                                     0x084D
#define GCREG_CURSOR_FOREGROUND_Address                                  0x00134
#define GCREG_CURSOR_FOREGROUND_MSB                                           15
#define GCREG_CURSOR_FOREGROUND_LSB                                            0
#define GCREG_CURSOR_FOREGROUND_BLK                                            0
#define GCREG_CURSOR_FOREGROUND_Count                                          1
#define GCREG_CURSOR_FOREGROUND_FieldMask                             0x00FFFFFF
#define GCREG_CURSOR_FOREGROUND_ReadMask                              0x00FFFFFF
#define GCREG_CURSOR_FOREGROUND_WriteMask                             0x00FFFFFF
#define GCREG_CURSOR_FOREGROUND_ResetValue                            0x00000000

/* Blue value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_FOREGROUND_BLUE                                         7:0
#define GCREG_CURSOR_FOREGROUND_BLUE_End                                       7
#define GCREG_CURSOR_FOREGROUND_BLUE_Start                                     0
#define GCREG_CURSOR_FOREGROUND_BLUE_Type                                    U08

/* Green value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_FOREGROUND_GREEN                                       15:8
#define GCREG_CURSOR_FOREGROUND_GREEN_End                                     15
#define GCREG_CURSOR_FOREGROUND_GREEN_Start                                    8
#define GCREG_CURSOR_FOREGROUND_GREEN_Type                                   U08

/* Red value. NOTE: This field is double buffered. */
#define GCREG_CURSOR_FOREGROUND_RED                                        23:16
#define GCREG_CURSOR_FOREGROUND_RED_End                                       23
#define GCREG_CURSOR_FOREGROUND_RED_Start                                     16
#define GCREG_CURSOR_FOREGROUND_RED_Type                                     U08

/* Register gcregDisplayIntr **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Display Interrupt Register.  This is the interrupt register for the        **
** Display.  This register will automatically clear after a read.  The        **
** interrupt bit is set when the current frame buffer  is used up. The        **
** interrupt signal will be pulled up only  when the interrupt enable bit in  **
** register  gcregDisplayIntrEnable is enabled.                               */

#define gcregDisplayIntrRegAddrs                                          0x084E
#define GCREG_DISPLAY_INTR_Address                                        0x0138//manually edited
#define GCREG_DISPLAY_INTR_MSB                                                15
#define GCREG_DISPLAY_INTR_LSB                                                 0
#define GCREG_DISPLAY_INTR_BLK                                                 0
#define GCREG_DISPLAY_INTR_Count                                               1
#define GCREG_DISPLAY_INTR_FieldMask                                  0xE0003111
#define GCREG_DISPLAY_INTR_ReadMask                                   0xE0003111
#define GCREG_DISPLAY_INTR_WriteMask                                  0x00000000
#define GCREG_DISPLAY_INTR_ResetValue                                 0x00000000

/* Display0 interrupt */
#define GCREG_DISPLAY_INTR_DISP0                                             0:0
#define GCREG_DISPLAY_INTR_DISP0_End                                           0
#define GCREG_DISPLAY_INTR_DISP0_Start                                         0
#define GCREG_DISPLAY_INTR_DISP0_Type                                        U01

/* Display1 interrupt */
#define GCREG_DISPLAY_INTR_DISP1                                             4:4
#define GCREG_DISPLAY_INTR_DISP1_End                                           4
#define GCREG_DISPLAY_INTR_DISP1_Start                                         4
#define GCREG_DISPLAY_INTR_DISP1_Type                                        U01

/* Cursor interrupt */
#define GCREG_DISPLAY_INTR_CURSOR                                            8:8
#define GCREG_DISPLAY_INTR_CURSOR_End                                          8
#define GCREG_DISPLAY_INTR_CURSOR_Start                                        8
#define GCREG_DISPLAY_INTR_CURSOR_Type                                       U01

/* Display0 DBI configure error */
#define GCREG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR                             12:12
#define GCREG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_End                            12
#define GCREG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_Start                          12
#define GCREG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_Type                          U01

/* Display1 DBI configure error */
#define GCREG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR                             13:13
#define GCREG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_End                            13
#define GCREG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_Start                          13
#define GCREG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_Type                          U01

/* Panel underflow intr. */
#define GCREG_DISPLAY_INTR_PANEL_UNDERFLOW                                 29:29
#define GCREG_DISPLAY_INTR_PANEL_UNDERFLOW_End                                29
#define GCREG_DISPLAY_INTR_PANEL_UNDERFLOW_Start                              29
#define GCREG_DISPLAY_INTR_PANEL_UNDERFLOW_Type                              U01

/* Soft reset done */
#define GCREG_DISPLAY_INTR_SOFT_RESET_DONE                                 30:30
#define GCREG_DISPLAY_INTR_SOFT_RESET_DONE_End                                30
#define GCREG_DISPLAY_INTR_SOFT_RESET_DONE_Start                              30
#define GCREG_DISPLAY_INTR_SOFT_RESET_DONE_Type                              U01

/* Bus error */
#define GCREG_DISPLAY_INTR_BUS_ERROR                                       31:31
#define GCREG_DISPLAY_INTR_BUS_ERROR_End                                      31
#define GCREG_DISPLAY_INTR_BUS_ERROR_Start                                    31
#define GCREG_DISPLAY_INTR_BUS_ERROR_Type                                    U01

/* Register gcregDisplayIntrEnable **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Display Interrupt Enable Register.  The interrupt enable register for      **
** display_0 (and display_1  if present).  NOTE: Interrupt enable for         **
** register gcregDisplayIntr.  NOTE: This register is double buffered.        */

#define gcregDisplayIntrEnableRegAddrs                                    0x084F
#define GCREG_DISPLAY_INTR_ENABLE_Address                                0x013C //manually edited
#define GCREG_DISPLAY_INTR_ENABLE_MSB                                         15
#define GCREG_DISPLAY_INTR_ENABLE_LSB                                          0
#define GCREG_DISPLAY_INTR_ENABLE_BLK                                          0
#define GCREG_DISPLAY_INTR_ENABLE_Count                                        1
#define GCREG_DISPLAY_INTR_ENABLE_FieldMask                           0xE0001011
#define GCREG_DISPLAY_INTR_ENABLE_ReadMask                            0xE0001011
#define GCREG_DISPLAY_INTR_ENABLE_WriteMask                           0xE0001011
#define GCREG_DISPLAY_INTR_ENABLE_ResetValue                          0x40000000

/* Display0 interrupt enable NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_DISP0                                      0:0
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_End                                    0
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_Start                                  0
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_Type                                 U01

/* Display1 interrupt enable NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_DISP1                                      4:4
#define GCREG_DISPLAY_INTR_ENABLE_DISP1_End                                    4
#define GCREG_DISPLAY_INTR_ENABLE_DISP1_Start                                  4
#define GCREG_DISPLAY_INTR_ENABLE_DISP1_Type                                 U01

/* Display0 DBI configure error enable NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_DBI_CFG_ERROR                      12:12
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_DBI_CFG_ERROR_End                     12
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_DBI_CFG_ERROR_Start                   12
#define GCREG_DISPLAY_INTR_ENABLE_DISP0_DBI_CFG_ERROR_Type                   U01

/* Panel underflow intr enable. NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_PANEL_UNDERFLOW                          29:29
#define GCREG_DISPLAY_INTR_ENABLE_PANEL_UNDERFLOW_End                         29
#define GCREG_DISPLAY_INTR_ENABLE_PANEL_UNDERFLOW_Start                       29
#define GCREG_DISPLAY_INTR_ENABLE_PANEL_UNDERFLOW_Type                       U01

/* Soft reset done enable NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_SOFT_RESET_DONE                          30:30
#define GCREG_DISPLAY_INTR_ENABLE_SOFT_RESET_DONE_End                         30
#define GCREG_DISPLAY_INTR_ENABLE_SOFT_RESET_DONE_Start                       30
#define GCREG_DISPLAY_INTR_ENABLE_SOFT_RESET_DONE_Type                       U01

/* Bus error enable NOTE: This field is double buffered. */
#define GCREG_DISPLAY_INTR_ENABLE_BUS_ERROR                                31:31
#define GCREG_DISPLAY_INTR_ENABLE_BUS_ERROR_End                               31
#define GCREG_DISPLAY_INTR_ENABLE_BUS_ERROR_Start                             31
#define GCREG_DISPLAY_INTR_ENABLE_BUS_ERROR_Type                             U01

/* Register gcregDbiConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* DBI Configuration Register.  Configuration register for DBI output.  */

#define gcregDbiConfigRegAddrs                                            0x0850
#define GCREG_DBI_CONFIG_Address                                         0x00140
#define GCREG_DBI_CONFIG_MSB                                                  15
#define GCREG_DBI_CONFIG_LSB                                                   0
#define GCREG_DBI_CONFIG_BLK                                                   0
#define GCREG_DBI_CONFIG_Count                                                 1
#define GCREG_DBI_CONFIG_FieldMask                                    0x00003FFF
#define GCREG_DBI_CONFIG_ReadMask                                     0x00003FFF
#define GCREG_DBI_CONFIG_WriteMask                                    0x00003FFF
#define GCREG_DBI_CONFIG_ResetValue                                   0x00000040

/* DBI Type select */
#define GCREG_DBI_CONFIG_DBI_TYPE                                            1:0
#define GCREG_DBI_CONFIG_DBI_TYPE_End                                          1
#define GCREG_DBI_CONFIG_DBI_TYPE_Start                                        0
#define GCREG_DBI_CONFIG_DBI_TYPE_Type                                       U02
#define   GCREG_DBI_CONFIG_DBI_TYPE_TYPE_AFIXED_E                            0x0
#define   GCREG_DBI_CONFIG_DBI_TYPE_TYPE_ACLOCK_E                            0x1
#define   GCREG_DBI_CONFIG_DBI_TYPE_TYPE_B                                   0x2
#define   GCREG_DBI_CONFIG_DBI_TYPE_TYPE_C                                   0x3

/* DBI interface data format. Refer to DBI specification section  on          **
** Interface Color Coding for detail.                                         */
#define GCREG_DBI_CONFIG_DBI_DATA_FORMAT                                     5:2
#define GCREG_DBI_CONFIG_DBI_DATA_FORMAT_End                                   5
#define GCREG_DBI_CONFIG_DBI_DATA_FORMAT_Start                                 2
#define GCREG_DBI_CONFIG_DBI_DATA_FORMAT_Type                                U04
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D8R3G3B2                          0x0
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D8R4G4B4                          0x1
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D8R5G6B5                          0x2
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D8R6G6B6                          0x3
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D8R8G8B8                          0x4
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D9R6G6B6                          0x5
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16R3G3B2                         0x6
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16R4G4B4                         0x7
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16R5G6B5                         0x8
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R6_G6_B6_OP1                  0x9
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R6_G6_B6_OP2                  0xA
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R8_G8_B8_OP1                  0xB
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R8_G8_B8_OP2                  0xC
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D1R5G6B5                          0xD
#define   GCREG_DBI_CONFIG_DBI_DATA_FORMAT_D1R8G8B8                          0xE

/* Output bus select */
#define GCREG_DBI_CONFIG_BUS_OUTPUT_SEL                                      6:6
#define GCREG_DBI_CONFIG_BUS_OUTPUT_SEL_End                                    6
#define GCREG_DBI_CONFIG_BUS_OUTPUT_SEL_Start                                  6
#define GCREG_DBI_CONFIG_BUS_OUTPUT_SEL_Type                                 U01
#define   GCREG_DBI_CONFIG_BUS_OUTPUT_SEL_DPI                                0x0
#define   GCREG_DBI_CONFIG_BUS_OUTPUT_SEL_DBI                                0x1

/* D/CX Pin polarity */
#define GCREG_DBI_CONFIG_DBIX_POLARITY                                       7:7
#define GCREG_DBI_CONFIG_DBIX_POLARITY_End                                     7
#define GCREG_DBI_CONFIG_DBIX_POLARITY_Start                                   7
#define GCREG_DBI_CONFIG_DBIX_POLARITY_Type                                  U01
#define   GCREG_DBI_CONFIG_DBIX_POLARITY_DEFAULT                             0x0
#define   GCREG_DBI_CONFIG_DBIX_POLARITY_REVERSE                             0x1

/* Time unit for AC characteristics  */
#define GCREG_DBI_CONFIG_DBI_AC_TIME_UNIT                                   11:8
#define GCREG_DBI_CONFIG_DBI_AC_TIME_UNIT_End                                 11
#define GCREG_DBI_CONFIG_DBI_AC_TIME_UNIT_Start                                8
#define GCREG_DBI_CONFIG_DBI_AC_TIME_UNIT_Type                               U04

/* Options for DBI Type C Interface Read/Write Sequence;  0: Option 1;  1:    **
** Option 2;  2: Option 3.                                                    */
#define GCREG_DBI_CONFIG_DBI_TYPEC_OPT                                     13:12
#define GCREG_DBI_CONFIG_DBI_TYPEC_OPT_End                                    13
#define GCREG_DBI_CONFIG_DBI_TYPEC_OPT_Start                                  12
#define GCREG_DBI_CONFIG_DBI_TYPEC_OPT_Type                                  U02

/* Register gcregDbiIfReset **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* DBI Reset Register.  Reset DBI interface to idle state. WRITE ONLY. */

#define gcregDbiIfResetRegAddrs                                           0x0851
#define GCREG_DBI_IF_RESET_Address                                       0x00144
#define GCREG_DBI_IF_RESET_MSB                                                15
#define GCREG_DBI_IF_RESET_LSB                                                 0
#define GCREG_DBI_IF_RESET_BLK                                                 0
#define GCREG_DBI_IF_RESET_Count                                               1
#define GCREG_DBI_IF_RESET_FieldMask                                  0x00000001
#define GCREG_DBI_IF_RESET_ReadMask                                   0x00000000
#define GCREG_DBI_IF_RESET_WriteMask                                  0x00000001
#define GCREG_DBI_IF_RESET_ResetValue                                 0x00000000

/* Reset DBI interface to idle state  */
#define GCREG_DBI_IF_RESET_DBI_IF_LEVEL_RESET                                0:0
#define GCREG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_End                              0
#define GCREG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_Start                            0
#define GCREG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_Type                           U01
#define   GCREG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_RESET                        0x1

/* Register gcregDbiWrChar1 **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* DBI Write AC Characteristics 1 Register.  DBI write AC characteristics     **
** definition register 1                                                      */

#define gcregDbiWrChar1RegAddrs                                           0x0852
#define GCREG_DBI_WR_CHAR1_Address                                       0x00148
#define GCREG_DBI_WR_CHAR1_MSB                                                15
#define GCREG_DBI_WR_CHAR1_LSB                                                 0
#define GCREG_DBI_WR_CHAR1_BLK                                                 0
#define GCREG_DBI_WR_CHAR1_Count                                               1
#define GCREG_DBI_WR_CHAR1_FieldMask                                  0x0000FFFF
#define GCREG_DBI_WR_CHAR1_ReadMask                                   0x0000FFFF
#define GCREG_DBI_WR_CHAR1_WriteMask                                  0x0000FFFF
#define GCREG_DBI_WR_CHAR1_ResetValue                                 0x00000000

/* Single write period duration. Cycle number=Setting*(DbiAcTimeUnit+1).      **
** This field must be no less than 3.                                         */
#define GCREG_DBI_WR_CHAR1_DBI_WR_PERIOD                                     7:0
#define GCREG_DBI_WR_CHAR1_DBI_WR_PERIOD_End                                   7
#define GCREG_DBI_WR_CHAR1_DBI_WR_PERIOD_Start                                 0
#define GCREG_DBI_WR_CHAR1_DBI_WR_PERIOD_Type                                U08

/* Cycle number=Setting*(DbiAcTimeUnit+1).  0: When Type A Fixed E mode: Not  **
** used.  1: When Type A Clock E mode: Time to assert E.  2: When Type B      **
** mode: Time to assert WRX.                                                  */
#define GCREG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT                             11:8
#define GCREG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_End                           11
#define GCREG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_Start                          8
#define GCREG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_Type                         U04

/* Cycle number=Setting*(DbiAcTimeUnit+1).  0: When Type A Fixed E mode: Time **
** to assert CSX.  1: When Type A Clock E mode: Not used.  2: When Type B     **
** mode: Time to assert CSX.                                                  */
#define GCREG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT                                15:12
#define GCREG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_End                               15
#define GCREG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_Start                             12
#define GCREG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_Type                             U04

/* Register gcregDbiWrChar2 **
** ~~~~~~~~~~~~~~~~~~~~~~~~ */

/* DBI Write AC Characteristics 2 Register.  DBI write AC characteristics     **
** definition register 2                                                      */

#define gcregDbiWrChar2RegAddrs                                           0x0853
#define GCREG_DBI_WR_CHAR2_Address                                       0x0014C
#define GCREG_DBI_WR_CHAR2_MSB                                                15
#define GCREG_DBI_WR_CHAR2_LSB                                                 0
#define GCREG_DBI_WR_CHAR2_BLK                                                 0
#define GCREG_DBI_WR_CHAR2_Count                                               1
#define GCREG_DBI_WR_CHAR2_FieldMask                                  0x0000FFFF
#define GCREG_DBI_WR_CHAR2_ReadMask                                   0x0000FFFF
#define GCREG_DBI_WR_CHAR2_WriteMask                                  0x0000FFFF
#define GCREG_DBI_WR_CHAR2_ResetValue                                 0x00000000

/* Cycle number=Setting*(DbiAcTimeUnit+1).  0: When Type A Fixed E mode: Not  **
** used.  1: When type A Clock E mode: Time to de-assert E.  2: When Type B   **
** mode: Time to de-assert WRX.                                               */
#define GCREG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT                             7:0
#define GCREG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_End                           7
#define GCREG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_Start                         0
#define GCREG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_Type                        U08

/* Cycle number=Setting*(DbiAcTimeUnit+1).  0: When type A fixed E mode: Time **
** to de-assert CSX.  1: When type A clock E mode: Not used.  2: When type B  **
** mode: Time to de-assert CSX.                                               */
#define GCREG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT                                15:8
#define GCREG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_End                              15
#define GCREG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_Start                             8
#define GCREG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_Type                            U08

/* Register gcregDbiCmd **
** ~~~~~~~~~~~~~~~~~~~~ */

/* DBI Command Control Register.  DBI Command in/out port. Writes to this     **
** register will send  command/data to the DBI port. WRITE ONLY.              */

#define gcregDbiCmdRegAddrs                                               0x0854
#define GCREG_DBI_CMD_Address                                            0x00150
#define GCREG_DBI_CMD_MSB                                                     15
#define GCREG_DBI_CMD_LSB                                                      0
#define GCREG_DBI_CMD_BLK                                                      0
#define GCREG_DBI_CMD_Count                                                    1
#define GCREG_DBI_CMD_FieldMask                                       0xC000FFFF
#define GCREG_DBI_CMD_ReadMask                                        0x00000000
#define GCREG_DBI_CMD_WriteMask                                       0xC000FFFF
#define GCREG_DBI_CMD_ResetValue                                      0x00000000

/* The type of data contained in this word is specified using                 **
** DBI_COMMANDFLAG[bits 31:30].  For Type C Options 1 and 2:                  **
** DBI_COMMAND_WORD[8] is used to indicate the polarity of D/CX.              **
** DBI_COMMAND_WORD[8] = 0 indicates DBI_COMMAND_WORD[7:0] is COMMAND WORD.   **
** DBI_COMMAND_WORD[8] = 1 indicates DBI_COMMAND_WORD[7:0] is DATA WORD.      */
#define GCREG_DBI_CMD_DBI_COMMAND_WORD                                      15:0
#define GCREG_DBI_CMD_DBI_COMMAND_WORD_End                                    15
#define GCREG_DBI_CMD_DBI_COMMAND_WORD_Start                                   0
#define GCREG_DBI_CMD_DBI_COMMAND_WORD_Type                                  U16

/* DBI command flag.  */
#define GCREG_DBI_CMD_DBI_COMMANDFLAG                                      31:30
#define GCREG_DBI_CMD_DBI_COMMANDFLAG_End                                     31
#define GCREG_DBI_CMD_DBI_COMMANDFLAG_Start                                   30
#define GCREG_DBI_CMD_DBI_COMMANDFLAG_Type                                   U02
/* //DBI_COMMAND_WORD will contain an address.  */
#define   GCREG_DBI_CMD_DBI_COMMANDFLAG_ADDRESS                              0x0
/* //Starts a write. Contents of DBI_COMMAND_WORD are ignored.  */
#define   GCREG_DBI_CMD_DBI_COMMANDFLAG_WRITE_MEM_START                      0x1
/* //DBI_COMMAND_WORD will contain a parameter or data.  */
#define   GCREG_DBI_CMD_DBI_COMMANDFLAG_PARAMETER_OR_DATA                    0x2

/* Register gcregDpiConfig **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* DPI Configuration Register.  The configuration register for DPI output.    **
** NOTE: This register is double buffered.                                    */

#define gcregDpiConfigRegAddrs                                            0x0855
#define GCREG_DPI_CONFIG_Address                                         0x00154
#define GCREG_DPI_CONFIG_MSB                                                  15
#define GCREG_DPI_CONFIG_LSB                                                   0
#define GCREG_DPI_CONFIG_BLK                                                   0
#define GCREG_DPI_CONFIG_Count                                                 1
#define GCREG_DPI_CONFIG_FieldMask                                    0x00000007
#define GCREG_DPI_CONFIG_ReadMask                                     0x00000007
#define GCREG_DPI_CONFIG_WriteMask                                    0x00000007
#define GCREG_DPI_CONFIG_ResetValue                                   0x00000005

/* DPI interface data format. Refer to DPI specification section for          **
** Interface Color Coding' for detail. NOTE: This field is double buffered.   */
#define GCREG_DPI_CONFIG_DPI_DATA_FORMAT                                     2:0
#define GCREG_DPI_CONFIG_DPI_DATA_FORMAT_End                                   2
#define GCREG_DPI_CONFIG_DPI_DATA_FORMAT_Start                                 0
#define GCREG_DPI_CONFIG_DPI_DATA_FORMAT_Type                                U03
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG1                           0x0
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG2                           0x1
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG3                           0x2
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D18CFG1                           0x3
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D18CFG2                           0x4
#define   GCREG_DPI_CONFIG_DPI_DATA_FORMAT_D24                               0x5

/* Register gcregDbiTypecCfg **
** ~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* DBI Type C Timing Control Register.  DBI Type C write timing definition. */

#define gcregDbiTypecCfgRegAddrs                                          0x0856
#define GCREG_DBI_TYPEC_CFG_Address                                      0x00158
#define GCREG_DBI_TYPEC_CFG_MSB                                               15
#define GCREG_DBI_TYPEC_CFG_LSB                                                0
#define GCREG_DBI_TYPEC_CFG_BLK                                                0
#define GCREG_DBI_TYPEC_CFG_Count                                              1
#define GCREG_DBI_TYPEC_CFG_FieldMask                                 0x001FFFFF
#define GCREG_DBI_TYPEC_CFG_ReadMask                                  0x001FFFFF
#define GCREG_DBI_TYPEC_CFG_WriteMask                                 0x001FFFFF
#define GCREG_DBI_TYPEC_CFG_ResetValue                                0x00000000

/* Divide counter for Tas (address setup time). Specifies how many sdaClk     **
** cycles in Tas phase.  DCX Tas means number of DBI_AC_TIME_UNIT of sdaClk   **
** to be ahead of scl.  Only works for DBI TYPE C Option3. Option1/2 will     **
** ignore this setting.  This field needs to be at least 1.                   */
#define GCREG_DBI_TYPEC_CFG_TAS                                              3:0
#define GCREG_DBI_TYPEC_CFG_TAS_End                                            3
#define GCREG_DBI_TYPEC_CFG_TAS_Start                                          0
#define GCREG_DBI_TYPEC_CFG_TAS_Type                                         U04

/* Divide counter for Twrl (SCL L duration (write)). Specifies how many       **
** sdaClk cycles in Twrl phase.  SCL Twrl means number of DBI_AC_TIME_UNIT of **
** sdaClk for scl staying low This field needs to be at least 1.              */
#define GCREG_DBI_TYPEC_CFG_SCL_TWRL                                        11:4
#define GCREG_DBI_TYPEC_CFG_SCL_TWRL_End                                      11
#define GCREG_DBI_TYPEC_CFG_SCL_TWRL_Start                                     4
#define GCREG_DBI_TYPEC_CFG_SCL_TWRL_Type                                    U08

/* Divide counter for Twrh (SCL H duration (write)). Specifies how many       **
** sdaClk cycles in Twrh phase.  SCL Twrh means number of DBI_AC_TIME_UNIT of **
** sdaClk for scl staying high.  This field need to be at least 1.            */
#define GCREG_DBI_TYPEC_CFG_SCL_TWRH                                       19:12
#define GCREG_DBI_TYPEC_CFG_SCL_TWRH_End                                      19
#define GCREG_DBI_TYPEC_CFG_SCL_TWRH_Start                                    12
#define GCREG_DBI_TYPEC_CFG_SCL_TWRH_Type                                    U08

/* Determine the source of output Scl.  */
#define GCREG_DBI_TYPEC_CFG_SCL_SEL                                        20:20
#define GCREG_DBI_TYPEC_CFG_SCL_SEL_End                                       20
#define GCREG_DBI_TYPEC_CFG_SCL_SEL_Start                                     20
#define GCREG_DBI_TYPEC_CFG_SCL_SEL_Type                                     U01
/* //follow the SCL_TWRL and SCL_TWRH setting.  */
#define   GCREG_DBI_TYPEC_CFG_SCL_SEL_DIVIDED_SDA_CLK                        0x0
/* //output 1 bit per SdaClk, ignore SCL_TWRL and SCL_TWRH. */
#define   GCREG_DBI_TYPEC_CFG_SCL_SEL_SDA_CLK                                0x1

/* Register gcregDCStatus **
** ~~~~~~~~~~~~~~~~~~~~~~ */

/* Display Controller Status Register.  */

#define gcregDCStatusRegAddrs                                             0x0857
#define GCREG_DC_STATUS_Address                                          0x0015C
#define GCREG_DC_STATUS_MSB                                                   15
#define GCREG_DC_STATUS_LSB                                                    0
#define GCREG_DC_STATUS_BLK                                                    0
#define GCREG_DC_STATUS_Count                                                  1
#define GCREG_DC_STATUS_FieldMask                                     0x00000001
#define GCREG_DC_STATUS_ReadMask                                      0x00000001
#define GCREG_DC_STATUS_WriteMask                                     0x00000000
#define GCREG_DC_STATUS_ResetValue                                    0x00000000

/* DBI Type C afifo full.  */
#define GCREG_DC_STATUS_DBI_TYPEC_FIFO_FULL                                  0:0
#define GCREG_DC_STATUS_DBI_TYPEC_FIFO_FULL_End                                0
#define GCREG_DC_STATUS_DBI_TYPEC_FIFO_FULL_Start                              0
#define GCREG_DC_STATUS_DBI_TYPEC_FIFO_FULL_Type                             U01

/* Register gcregSrcConfigEndian **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Endian control.  */

#define gcregSrcConfigEndianRegAddrs                                      0x0858
#define GCREG_SRC_CONFIG_ENDIAN_Address                                  0x00160
#define GCREG_SRC_CONFIG_ENDIAN_MSB                                           15
#define GCREG_SRC_CONFIG_ENDIAN_LSB                                            0
#define GCREG_SRC_CONFIG_ENDIAN_BLK                                            0
#define GCREG_SRC_CONFIG_ENDIAN_Count                                          1
#define GCREG_SRC_CONFIG_ENDIAN_FieldMask                             0x00000003
#define GCREG_SRC_CONFIG_ENDIAN_ReadMask                              0x00000003
#define GCREG_SRC_CONFIG_ENDIAN_WriteMask                             0x00000003
#define GCREG_SRC_CONFIG_ENDIAN_ResetValue                            0x00000000

/* Control source endian. */
#define GCREG_SRC_CONFIG_ENDIAN_CONTROL                                      1:0
#define GCREG_SRC_CONFIG_ENDIAN_CONTROL_End                                    1
#define GCREG_SRC_CONFIG_ENDIAN_CONTROL_Start                                  0
#define GCREG_SRC_CONFIG_ENDIAN_CONTROL_Type                                 U02
#define   GCREG_SRC_CONFIG_ENDIAN_CONTROL_NO_SWAP                            0x0
#define   GCREG_SRC_CONFIG_ENDIAN_CONTROL_SWAP_WORD                          0x1
#define   GCREG_SRC_CONFIG_ENDIAN_CONTROL_SWAP_DWORD                         0x2
#define   GCREG_SRC_CONFIG_ENDIAN_CONTROL_SWAP_DDWORD                        0x3

/* Register gcregSoftReset **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Soft reset.  */

#define gcregSoftResetRegAddrs                                            0x0859
#define GCREG_SOFT_RESET_Address                                         0x0164
#define GCREG_SOFT_RESET_MSB                                                  15
#define GCREG_SOFT_RESET_LSB                                                   0
#define GCREG_SOFT_RESET_BLK                                                   0
#define GCREG_SOFT_RESET_Count                                                 1
#define GCREG_SOFT_RESET_FieldMask                                    0x00000001
#define GCREG_SOFT_RESET_ReadMask                                     0x00000001
#define GCREG_SOFT_RESET_WriteMask                                    0x00000001
#define GCREG_SOFT_RESET_ResetValue                                   0x00000000

/* Writing a one in this register will force a soft reset of the display      **
** controller.                                                                */
#define GCREG_SOFT_RESET_RESET                                               0:0
#define GCREG_SOFT_RESET_RESET_End                                             0
#define GCREG_SOFT_RESET_RESET_Start                                           0
#define GCREG_SOFT_RESET_RESET_Type                                          U01
#define   GCREG_SOFT_RESET_RESET_RESET                                       0x1

/* Register gcregDcControl **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* Control register.  */

#define gcregDcControlRegAddrs                                            0x085A
#define GCREG_DC_CONTROL_Address                                         0x00168
#define GCREG_DC_CONTROL_MSB                                                  15
#define GCREG_DC_CONTROL_LSB                                                   0
#define GCREG_DC_CONTROL_BLK                                                   0
#define GCREG_DC_CONTROL_Count                                                 1
#define GCREG_DC_CONTROL_FieldMask                                    0x00000018
#define GCREG_DC_CONTROL_ReadMask                                     0x00000018
#define GCREG_DC_CONTROL_WriteMask                                    0x00000018
#define GCREG_DC_CONTROL_ResetValue                                   0x00000000

/* Enable or disable the debug register. */
#define GCREG_DC_CONTROL_DEBUG_REGISTER                                      3:3
#define GCREG_DC_CONTROL_DEBUG_REGISTER_End                                    3
#define GCREG_DC_CONTROL_DEBUG_REGISTER_Start                                  3
#define GCREG_DC_CONTROL_DEBUG_REGISTER_Type                                 U01
#define   GCREG_DC_CONTROL_DEBUG_REGISTER_DISABLED                           0x0
#define   GCREG_DC_CONTROL_DEBUG_REGISTER_ENABLED                            0x1

/* Enable or disable ram clock gating. */
#define GCREG_DC_CONTROL_RAM_CLOCK_GATING                                    4:4
#define GCREG_DC_CONTROL_RAM_CLOCK_GATING_End                                  4
#define GCREG_DC_CONTROL_RAM_CLOCK_GATING_Start                                4
#define GCREG_DC_CONTROL_RAM_CLOCK_GATING_Type                               U01
#define   GCREG_DC_CONTROL_RAM_CLOCK_GATING_DISABLED                         0x0
#define   GCREG_DC_CONTROL_RAM_CLOCK_GATING_ENABLED                          0x1

/* Register gcregRegisterTimingControl **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Timing control register.  */

#define gcregRegisterTimingControlRegAddrs                                0x085B
#define GCREG_REGISTER_TIMING_CONTROL_Address                            0x0016C
#define GCREG_REGISTER_TIMING_CONTROL_MSB                                     15
#define GCREG_REGISTER_TIMING_CONTROL_LSB                                      0
#define GCREG_REGISTER_TIMING_CONTROL_BLK                                      0
#define GCREG_REGISTER_TIMING_CONTROL_Count                                    1
#define GCREG_REGISTER_TIMING_CONTROL_FieldMask                       0xFFFFFFFF
#define GCREG_REGISTER_TIMING_CONTROL_ReadMask                        0xFFFFFFFF
#define GCREG_REGISTER_TIMING_CONTROL_WriteMask                       0xFFFFFFFF
#define GCREG_REGISTER_TIMING_CONTROL_ResetValue                      0x00000000

#define GCREG_REGISTER_TIMING_CONTROL_FOR_PF1P                               7:0
#define GCREG_REGISTER_TIMING_CONTROL_FOR_PF1P_End                             7
#define GCREG_REGISTER_TIMING_CONTROL_FOR_PF1P_Start                           0
#define GCREG_REGISTER_TIMING_CONTROL_FOR_PF1P_Type                          U08

#define GCREG_REGISTER_TIMING_CONTROL_FOR_RF2P                              15:8
#define GCREG_REGISTER_TIMING_CONTROL_FOR_RF2P_End                            15
#define GCREG_REGISTER_TIMING_CONTROL_FOR_RF2P_Start                           8
#define GCREG_REGISTER_TIMING_CONTROL_FOR_RF2P_Type                          U08

#define GCREG_REGISTER_TIMING_CONTROL_FAST_RTC                             17:16
#define GCREG_REGISTER_TIMING_CONTROL_FAST_RTC_End                            17
#define GCREG_REGISTER_TIMING_CONTROL_FAST_RTC_Start                          16
#define GCREG_REGISTER_TIMING_CONTROL_FAST_RTC_Type                          U02

#define GCREG_REGISTER_TIMING_CONTROL_FAST_WTC                             19:18
#define GCREG_REGISTER_TIMING_CONTROL_FAST_WTC_End                            19
#define GCREG_REGISTER_TIMING_CONTROL_FAST_WTC_Start                          18
#define GCREG_REGISTER_TIMING_CONTROL_FAST_WTC_Type                          U02

#define GCREG_REGISTER_TIMING_CONTROL_POWER_DOWN                           20:20
#define GCREG_REGISTER_TIMING_CONTROL_POWER_DOWN_End                          20
#define GCREG_REGISTER_TIMING_CONTROL_POWER_DOWN_Start                        20
#define GCREG_REGISTER_TIMING_CONTROL_POWER_DOWN_Type                        U01

#define GCREG_REGISTER_TIMING_CONTROL_DEEP_SLEEP                           21:21
#define GCREG_REGISTER_TIMING_CONTROL_DEEP_SLEEP_End                          21
#define GCREG_REGISTER_TIMING_CONTROL_DEEP_SLEEP_Start                        21
#define GCREG_REGISTER_TIMING_CONTROL_DEEP_SLEEP_Type                        U01

#define GCREG_REGISTER_TIMING_CONTROL_LIGHT_SLEEP                          22:22
#define GCREG_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_End                         22
#define GCREG_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_Start                       22
#define GCREG_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_Type                       U01

#define GCREG_REGISTER_TIMING_CONTROL_RESERVED                             31:23
#define GCREG_REGISTER_TIMING_CONTROL_RESERVED_End                            31
#define GCREG_REGISTER_TIMING_CONTROL_RESERVED_Start                          23
#define GCREG_REGISTER_TIMING_CONTROL_RESERVED_Type                          U09

/* Register gcregDebugCounterSelect **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Debug Counter Select Register.  */

#define gcregDebugCounterSelectRegAddrs                                   0x085C
#define GCREG_DEBUG_COUNTER_SELECT_Address                               0x00170
#define GCREG_DEBUG_COUNTER_SELECT_MSB                                        15
#define GCREG_DEBUG_COUNTER_SELECT_LSB                                         0
#define GCREG_DEBUG_COUNTER_SELECT_BLK                                         0
#define GCREG_DEBUG_COUNTER_SELECT_Count                                       1
#define GCREG_DEBUG_COUNTER_SELECT_FieldMask                          0x000000FF
#define GCREG_DEBUG_COUNTER_SELECT_ReadMask                           0x000000FF
#define GCREG_DEBUG_COUNTER_SELECT_WriteMask                          0x000000FF
#define GCREG_DEBUG_COUNTER_SELECT_ResetValue                         0x00000000

/* Write a value to this field to pick up from 0~255 counters.  Then the      **
** counter will be in gcregDebugCounterValue.                                 */
#define GCREG_DEBUG_COUNTER_SELECT_SELECT                                    7:0
#define GCREG_DEBUG_COUNTER_SELECT_SELECT_End                                  7
#define GCREG_DEBUG_COUNTER_SELECT_SELECT_Start                                0
#define GCREG_DEBUG_COUNTER_SELECT_SELECT_Type                               U08
/* //request number */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_REQ_CNT            0x00
/* //read return data last number  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_LAST_CNT           0x01
/* //number of 8bytes of request bytes  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_REQ_BURST_CNT         0x00
/* //number of 8bytes of read return data  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_BURST_CUNT         0x03
/* //total pixels sent  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_PIXEL_CNT                 0x04
/* //total frame sent  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_FRAME_CNT                 0x05
/* //total dbi input cmd  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_INPUT_DBI_CMD_CNT         0x06
/* //total dbi output cmd  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_OUTPUT_DBI_CMD_CNT        0x07
/* //debug signals  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_DEBUG_SIGNALS0                  0x08
/* //reset all debug counters  */
#define   GCREG_DEBUG_COUNTER_SELECT_SELECT_RESET_ALL_DEBUG_COUNTERS        0xFF

/* Register gcregDebugCounterValue **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Debug Counter Value Register.  Debug Counter Value as specified in         **
** gcregDebugCounterSelect.                                                   */

#define gcregDebugCounterValueRegAddrs                                    0x085D
#define GCREG_DEBUG_COUNTER_VALUE_Address                                0x00174
#define GCREG_DEBUG_COUNTER_VALUE_MSB                                         15
#define GCREG_DEBUG_COUNTER_VALUE_LSB                                          0
#define GCREG_DEBUG_COUNTER_VALUE_BLK                                          0
#define GCREG_DEBUG_COUNTER_VALUE_Count                                        1
#define GCREG_DEBUG_COUNTER_VALUE_FieldMask                           0xFFFFFFFF
#define GCREG_DEBUG_COUNTER_VALUE_ReadMask                            0xFFFFFFFF
#define GCREG_DEBUG_COUNTER_VALUE_WriteMask                           0x00000000
#define GCREG_DEBUG_COUNTER_VALUE_ResetValue                          0x00000000

/* Selected debug counter value  */
#define GCREG_DEBUG_COUNTER_VALUE_VALUE                                     31:0
#define GCREG_DEBUG_COUNTER_VALUE_VALUE_End                                   31
#define GCREG_DEBUG_COUNTER_VALUE_VALUE_Start                                  0
#define GCREG_DEBUG_COUNTER_VALUE_VALUE_Type                                 U32

/* Register gcregReserved **
** ~~~~~~~~~~~~~~~~~~~~~~ */

/* The register space is reserved for future use. */

#define gcregReservedRegAddrs                                             0x085E
#define GCREG_RESERVED_Address                                           0x00178
#define GCREG_RESERVED_MSB                                                    15
#define GCREG_RESERVED_LSB                                                     0
#define GCREG_RESERVED_BLK                                                     0
#define GCREG_RESERVED_Count                                                   1
#define GCREG_RESERVED_FieldMask                                      0xFFFFFFFF
#define GCREG_RESERVED_ReadMask                                       0xFFFFFFFF
#define GCREG_RESERVED_WriteMask                                      0xFFFFFFFF
#define GCREG_RESERVED_ResetValue                                     0x00000000

#define GCREG_RESERVED_RESERVED                                             31:0
#define GCREG_RESERVED_RESERVED_End                                           31
#define GCREG_RESERVED_RESERVED_Start                                          0
#define GCREG_RESERVED_RESERVED_Type                                         U32

/* Register gcregReserved1 **
** ~~~~~~~~~~~~~~~~~~~~~~~ */

/* The register space is reserved for future use. */

#define gcregReserved1RegAddrs                                            0x085F
#define GCREG_RESERVED1_Address                                          0x0017C
#define GCREG_RESERVED1_MSB                                                   15
#define GCREG_RESERVED1_LSB                                                    0
#define GCREG_RESERVED1_BLK                                                    0
#define GCREG_RESERVED1_Count                                                  1
#define GCREG_RESERVED1_FieldMask                                     0xFFFFFFFF
#define GCREG_RESERVED1_ReadMask                                      0xFFFFFFFF
#define GCREG_RESERVED1_WriteMask                                     0xFFFFFFFF
#define GCREG_RESERVED1_ResetValue                                    0x00000000

#define GCREG_RESERVED1_RESERVED                                            31:0
#define GCREG_RESERVED1_RESERVED_End                                          31
#define GCREG_RESERVED1_RESERVED_Start                                         0
#define GCREG_RESERVED1_RESERVED_Type                                        U32

/* Register gcregReservedGroup (8 in total) **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* The register space is reserved for future use. */

#define gcregReservedGroupRegAddrs                                        0x0860
#define GCREG_RESERVED_GROUP_Address                                     0x00180
#define GCREG_RESERVED_GROUP_MSB                                              15
#define GCREG_RESERVED_GROUP_LSB                                               3
#define GCREG_RESERVED_GROUP_BLK                                               3
#define GCREG_RESERVED_GROUP_Count                                             8
#define GCREG_RESERVED_GROUP_FieldMask                                0xFFFFFFFF
#define GCREG_RESERVED_GROUP_ReadMask                                 0xFFFFFFFF
#define GCREG_RESERVED_GROUP_WriteMask                                0xFFFFFFFF
#define GCREG_RESERVED_GROUP_ResetValue                               0x00000000

#define GCREG_RESERVED_GROUP_RESERVED                                       31:0
#define GCREG_RESERVED_GROUP_RESERVED_End                                     31
#define GCREG_RESERVED_GROUP_RESERVED_Start                                    0
#define GCREG_RESERVED_GROUP_RESERVED_Type                                   U32

/* Register gcregLayerClockGate **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Layer clock gater Register. */

#define gcregLayerClockGateRegAddrs                                       0x0868
#define GCREG_LAYER_CLOCK_GATE_Address                                   0x001A0
#define GCREG_LAYER_CLOCK_GATE_MSB                                            15
#define GCREG_LAYER_CLOCK_GATE_LSB                                             0
#define GCREG_LAYER_CLOCK_GATE_BLK                                             0
#define GCREG_LAYER_CLOCK_GATE_Count                                           1
#define GCREG_LAYER_CLOCK_GATE_FieldMask                              0x00000007
#define GCREG_LAYER_CLOCK_GATE_ReadMask                               0x00000007
#define GCREG_LAYER_CLOCK_GATE_WriteMask                              0x00000007
#define GCREG_LAYER_CLOCK_GATE_ResetValue                             0x00000000

#define GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK                             0:0
#define GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK_End                           0
#define GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK_Start                         0
#define GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK_Type                        U01
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK_DISABLED                  0x0
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_VIDEO_CLK_ENABLED                   0x1

#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK                          1:1
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK_End                        1
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK_Start                      1
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK_Type                     U01
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK_DISABLED               0x0
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY0_CLK_ENABLED                0x1

#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK                          2:2
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK_End                        2
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK_Start                      2
#define GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK_Type                     U01
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK_DISABLED               0x0
#define   GCREG_LAYER_CLOCK_GATE_DISABLE_OVERLAY1_CLK_ENABLED                0x1

/* Register gcregDebugTotVideoReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotVideoReqRegAddrs                                     0x0869
#define GCREG_DEBUG_TOT_VIDEO_REQ_Address                                0x001A4
#define GCREG_DEBUG_TOT_VIDEO_REQ_MSB                                         15
#define GCREG_DEBUG_TOT_VIDEO_REQ_LSB                                          0
#define GCREG_DEBUG_TOT_VIDEO_REQ_BLK                                          0
#define GCREG_DEBUG_TOT_VIDEO_REQ_Count                                        1
#define GCREG_DEBUG_TOT_VIDEO_REQ_FieldMask                           0xFFFFFFFF
#define GCREG_DEBUG_TOT_VIDEO_REQ_ReadMask                            0xFFFFFFFF
#define GCREG_DEBUG_TOT_VIDEO_REQ_WriteMask                           0x00000000
#define GCREG_DEBUG_TOT_VIDEO_REQ_ResetValue                          0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_VIDEO_REQ_NUM                                       31:0
#define GCREG_DEBUG_TOT_VIDEO_REQ_NUM_End                                     31
#define GCREG_DEBUG_TOT_VIDEO_REQ_NUM_Start                                    0
#define GCREG_DEBUG_TOT_VIDEO_REQ_NUM_Type                                   U32

/* Register gcregDebugLstVideoReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstVideoReqRegAddrs                                     0x086A
#define GCREG_DEBUG_LST_VIDEO_REQ_Address                                0x001A8
#define GCREG_DEBUG_LST_VIDEO_REQ_MSB                                         15
#define GCREG_DEBUG_LST_VIDEO_REQ_LSB                                          0
#define GCREG_DEBUG_LST_VIDEO_REQ_BLK                                          0
#define GCREG_DEBUG_LST_VIDEO_REQ_Count                                        1
#define GCREG_DEBUG_LST_VIDEO_REQ_FieldMask                           0xFFFFFFFF
#define GCREG_DEBUG_LST_VIDEO_REQ_ReadMask                            0xFFFFFFFF
#define GCREG_DEBUG_LST_VIDEO_REQ_WriteMask                           0x00000000
#define GCREG_DEBUG_LST_VIDEO_REQ_ResetValue                          0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_VIDEO_REQ_NUM                                       31:0
#define GCREG_DEBUG_LST_VIDEO_REQ_NUM_End                                     31
#define GCREG_DEBUG_LST_VIDEO_REQ_NUM_Start                                    0
#define GCREG_DEBUG_LST_VIDEO_REQ_NUM_Type                                   U32

/* Register gcregDebugTotVideoRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotVideoRrbRegAddrs                                     0x086B
#define GCREG_DEBUG_TOT_VIDEO_RRB_Address                                0x001AC
#define GCREG_DEBUG_TOT_VIDEO_RRB_MSB                                         15
#define GCREG_DEBUG_TOT_VIDEO_RRB_LSB                                          0
#define GCREG_DEBUG_TOT_VIDEO_RRB_BLK                                          0
#define GCREG_DEBUG_TOT_VIDEO_RRB_Count                                        1
#define GCREG_DEBUG_TOT_VIDEO_RRB_FieldMask                           0xFFFFFFFF
#define GCREG_DEBUG_TOT_VIDEO_RRB_ReadMask                            0xFFFFFFFF
#define GCREG_DEBUG_TOT_VIDEO_RRB_WriteMask                           0x00000000
#define GCREG_DEBUG_TOT_VIDEO_RRB_ResetValue                          0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_VIDEO_RRB_NUM                                       31:0
#define GCREG_DEBUG_TOT_VIDEO_RRB_NUM_End                                     31
#define GCREG_DEBUG_TOT_VIDEO_RRB_NUM_Start                                    0
#define GCREG_DEBUG_TOT_VIDEO_RRB_NUM_Type                                   U32

/* Register gcregDebugLstVideoRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstVideoRrbRegAddrs                                     0x086C
#define GCREG_DEBUG_LST_VIDEO_RRB_Address                                0x001B0
#define GCREG_DEBUG_LST_VIDEO_RRB_MSB                                         15
#define GCREG_DEBUG_LST_VIDEO_RRB_LSB                                          0
#define GCREG_DEBUG_LST_VIDEO_RRB_BLK                                          0
#define GCREG_DEBUG_LST_VIDEO_RRB_Count                                        1
#define GCREG_DEBUG_LST_VIDEO_RRB_FieldMask                           0xFFFFFFFF
#define GCREG_DEBUG_LST_VIDEO_RRB_ReadMask                            0xFFFFFFFF
#define GCREG_DEBUG_LST_VIDEO_RRB_WriteMask                           0x00000000
#define GCREG_DEBUG_LST_VIDEO_RRB_ResetValue                          0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_VIDEO_RRB_NUM                                       31:0
#define GCREG_DEBUG_LST_VIDEO_RRB_NUM_End                                     31
#define GCREG_DEBUG_LST_VIDEO_RRB_NUM_Start                                    0
#define GCREG_DEBUG_LST_VIDEO_RRB_NUM_Type                                   U32

/* Register gcregDebugTotOverlay0Req **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotOverlay0ReqRegAddrs                                  0x086D
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_Address                             0x001B4
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_MSB                                      15
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_LSB                                       0
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_BLK                                       0
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_Count                                     1
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_WriteMask                        0x00000000
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_NUM                                    31:0
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_NUM_End                                  31
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_NUM_Start                                 0
#define GCREG_DEBUG_TOT_OVERLAY0_REQ_NUM_Type                                U32

/* Register gcregDebugLstOverlay0Req **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstOverlay0ReqRegAddrs                                  0x086E
#define GCREG_DEBUG_LST_OVERLAY0_REQ_Address                             0x001B8
#define GCREG_DEBUG_LST_OVERLAY0_REQ_MSB                                      15
#define GCREG_DEBUG_LST_OVERLAY0_REQ_LSB                                       0
#define GCREG_DEBUG_LST_OVERLAY0_REQ_BLK                                       0
#define GCREG_DEBUG_LST_OVERLAY0_REQ_Count                                     1
#define GCREG_DEBUG_LST_OVERLAY0_REQ_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY0_REQ_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY0_REQ_WriteMask                        0x00000000
#define GCREG_DEBUG_LST_OVERLAY0_REQ_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_OVERLAY0_REQ_NUM                                    31:0
#define GCREG_DEBUG_LST_OVERLAY0_REQ_NUM_End                                  31
#define GCREG_DEBUG_LST_OVERLAY0_REQ_NUM_Start                                 0
#define GCREG_DEBUG_LST_OVERLAY0_REQ_NUM_Type                                U32

/* Register gcregDebugTotOverlay0Rrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotOverlay0RrbRegAddrs                                  0x086F
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_Address                             0x001BC
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_MSB                                      15
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_LSB                                       0
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_BLK                                       0
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_Count                                     1
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_WriteMask                        0x00000000
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_NUM                                    31:0
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_NUM_End                                  31
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_NUM_Start                                 0
#define GCREG_DEBUG_TOT_OVERLAY0_RRB_NUM_Type                                U32

/* Register gcregDebugLstOverlay0Rrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstOverlay0RrbRegAddrs                                  0x0870
#define GCREG_DEBUG_LST_OVERLAY0_RRB_Address                             0x001C0
#define GCREG_DEBUG_LST_OVERLAY0_RRB_MSB                                      15
#define GCREG_DEBUG_LST_OVERLAY0_RRB_LSB                                       0
#define GCREG_DEBUG_LST_OVERLAY0_RRB_BLK                                       0
#define GCREG_DEBUG_LST_OVERLAY0_RRB_Count                                     1
#define GCREG_DEBUG_LST_OVERLAY0_RRB_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY0_RRB_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY0_RRB_WriteMask                        0x00000000
#define GCREG_DEBUG_LST_OVERLAY0_RRB_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_OVERLAY0_RRB_NUM                                    31:0
#define GCREG_DEBUG_LST_OVERLAY0_RRB_NUM_End                                  31
#define GCREG_DEBUG_LST_OVERLAY0_RRB_NUM_Start                                 0
#define GCREG_DEBUG_LST_OVERLAY0_RRB_NUM_Type                                U32

/* Register gcregDebugTotOverlay1Req **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotOverlay1ReqRegAddrs                                  0x0871
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_Address                             0x001C4
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_MSB                                      15
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_LSB                                       0
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_BLK                                       0
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_Count                                     1
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_WriteMask                        0x00000000
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_NUM                                    31:0
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_NUM_End                                  31
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_NUM_Start                                 0
#define GCREG_DEBUG_TOT_OVERLAY1_REQ_NUM_Type                                U32

/* Register gcregDebugLstOverlay1Req **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstOverlay1ReqRegAddrs                                  0x0872
#define GCREG_DEBUG_LST_OVERLAY1_REQ_Address                             0x001C8
#define GCREG_DEBUG_LST_OVERLAY1_REQ_MSB                                      15
#define GCREG_DEBUG_LST_OVERLAY1_REQ_LSB                                       0
#define GCREG_DEBUG_LST_OVERLAY1_REQ_BLK                                       0
#define GCREG_DEBUG_LST_OVERLAY1_REQ_Count                                     1
#define GCREG_DEBUG_LST_OVERLAY1_REQ_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY1_REQ_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY1_REQ_WriteMask                        0x00000000
#define GCREG_DEBUG_LST_OVERLAY1_REQ_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_OVERLAY1_REQ_NUM                                    31:0
#define GCREG_DEBUG_LST_OVERLAY1_REQ_NUM_End                                  31
#define GCREG_DEBUG_LST_OVERLAY1_REQ_NUM_Start                                 0
#define GCREG_DEBUG_LST_OVERLAY1_REQ_NUM_Type                                U32

/* Register gcregDebugTotOverlay1Rrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotOverlay1RrbRegAddrs                                  0x0873
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_Address                             0x001CC
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_MSB                                      15
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_LSB                                       0
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_BLK                                       0
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_Count                                     1
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_WriteMask                        0x00000000
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_NUM                                    31:0
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_NUM_End                                  31
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_NUM_Start                                 0
#define GCREG_DEBUG_TOT_OVERLAY1_RRB_NUM_Type                                U32

/* Register gcregDebugLstOverlay1Rrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstOverlay1RrbRegAddrs                                  0x0874
#define GCREG_DEBUG_LST_OVERLAY1_RRB_Address                             0x001D0
#define GCREG_DEBUG_LST_OVERLAY1_RRB_MSB                                      15
#define GCREG_DEBUG_LST_OVERLAY1_RRB_LSB                                       0
#define GCREG_DEBUG_LST_OVERLAY1_RRB_BLK                                       0
#define GCREG_DEBUG_LST_OVERLAY1_RRB_Count                                     1
#define GCREG_DEBUG_LST_OVERLAY1_RRB_FieldMask                        0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY1_RRB_ReadMask                         0xFFFFFFFF
#define GCREG_DEBUG_LST_OVERLAY1_RRB_WriteMask                        0x00000000
#define GCREG_DEBUG_LST_OVERLAY1_RRB_ResetValue                       0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_OVERLAY1_RRB_NUM                                    31:0
#define GCREG_DEBUG_LST_OVERLAY1_RRB_NUM_End                                  31
#define GCREG_DEBUG_LST_OVERLAY1_RRB_NUM_Start                                 0
#define GCREG_DEBUG_LST_OVERLAY1_RRB_NUM_Type                                U32

/* Register gcregDebugTotCursorReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotCursorReqRegAddrs                                    0x0875
#define GCREG_DEBUG_TOT_CURSOR_REQ_Address                               0x001D4
#define GCREG_DEBUG_TOT_CURSOR_REQ_MSB                                        15
#define GCREG_DEBUG_TOT_CURSOR_REQ_LSB                                         0
#define GCREG_DEBUG_TOT_CURSOR_REQ_BLK                                         0
#define GCREG_DEBUG_TOT_CURSOR_REQ_Count                                       1
#define GCREG_DEBUG_TOT_CURSOR_REQ_FieldMask                          0xFFFFFFFF
#define GCREG_DEBUG_TOT_CURSOR_REQ_ReadMask                           0xFFFFFFFF
#define GCREG_DEBUG_TOT_CURSOR_REQ_WriteMask                          0x00000000
#define GCREG_DEBUG_TOT_CURSOR_REQ_ResetValue                         0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_CURSOR_REQ_NUM                                      31:0
#define GCREG_DEBUG_TOT_CURSOR_REQ_NUM_End                                    31
#define GCREG_DEBUG_TOT_CURSOR_REQ_NUM_Start                                   0
#define GCREG_DEBUG_TOT_CURSOR_REQ_NUM_Type                                  U32

/* Register gcregDebugLstCursorReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstCursorReqRegAddrs                                    0x0876
#define GCREG_DEBUG_LST_CURSOR_REQ_Address                               0x001D8
#define GCREG_DEBUG_LST_CURSOR_REQ_MSB                                        15
#define GCREG_DEBUG_LST_CURSOR_REQ_LSB                                         0
#define GCREG_DEBUG_LST_CURSOR_REQ_BLK                                         0
#define GCREG_DEBUG_LST_CURSOR_REQ_Count                                       1
#define GCREG_DEBUG_LST_CURSOR_REQ_FieldMask                          0xFFFFFFFF
#define GCREG_DEBUG_LST_CURSOR_REQ_ReadMask                           0xFFFFFFFF
#define GCREG_DEBUG_LST_CURSOR_REQ_WriteMask                          0x00000000
#define GCREG_DEBUG_LST_CURSOR_REQ_ResetValue                         0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_CURSOR_REQ_NUM                                      31:0
#define GCREG_DEBUG_LST_CURSOR_REQ_NUM_End                                    31
#define GCREG_DEBUG_LST_CURSOR_REQ_NUM_Start                                   0
#define GCREG_DEBUG_LST_CURSOR_REQ_NUM_Type                                  U32

/* Register gcregDebugTotCursorRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotCursorRrbRegAddrs                                    0x0877
#define GCREG_DEBUG_TOT_CURSOR_RRB_Address                               0x001DC
#define GCREG_DEBUG_TOT_CURSOR_RRB_MSB                                        15
#define GCREG_DEBUG_TOT_CURSOR_RRB_LSB                                         0
#define GCREG_DEBUG_TOT_CURSOR_RRB_BLK                                         0
#define GCREG_DEBUG_TOT_CURSOR_RRB_Count                                       1
#define GCREG_DEBUG_TOT_CURSOR_RRB_FieldMask                          0xFFFFFFFF
#define GCREG_DEBUG_TOT_CURSOR_RRB_ReadMask                           0xFFFFFFFF
#define GCREG_DEBUG_TOT_CURSOR_RRB_WriteMask                          0x00000000
#define GCREG_DEBUG_TOT_CURSOR_RRB_ResetValue                         0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_CURSOR_RRB_NUM                                      31:0
#define GCREG_DEBUG_TOT_CURSOR_RRB_NUM_End                                    31
#define GCREG_DEBUG_TOT_CURSOR_RRB_NUM_Start                                   0
#define GCREG_DEBUG_TOT_CURSOR_RRB_NUM_Type                                  U32

/* Register gcregDebugLstCursorRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstCursorRrbRegAddrs                                    0x0878
#define GCREG_DEBUG_LST_CURSOR_RRB_Address                               0x001E0
#define GCREG_DEBUG_LST_CURSOR_RRB_MSB                                        15
#define GCREG_DEBUG_LST_CURSOR_RRB_LSB                                         0
#define GCREG_DEBUG_LST_CURSOR_RRB_BLK                                         0
#define GCREG_DEBUG_LST_CURSOR_RRB_Count                                       1
#define GCREG_DEBUG_LST_CURSOR_RRB_FieldMask                          0xFFFFFFFF
#define GCREG_DEBUG_LST_CURSOR_RRB_ReadMask                           0xFFFFFFFF
#define GCREG_DEBUG_LST_CURSOR_RRB_WriteMask                          0x00000000
#define GCREG_DEBUG_LST_CURSOR_RRB_ResetValue                         0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_CURSOR_RRB_NUM                                      31:0
#define GCREG_DEBUG_LST_CURSOR_RRB_NUM_End                                    31
#define GCREG_DEBUG_LST_CURSOR_RRB_NUM_Start                                   0
#define GCREG_DEBUG_LST_CURSOR_RRB_NUM_Type                                  U32

/* Register gcregDebugTotDCReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotDCReqRegAddrs                                        0x0879
#define GCREG_DEBUG_TOT_DC_REQ_Address                                   0x001E4
#define GCREG_DEBUG_TOT_DC_REQ_MSB                                            15
#define GCREG_DEBUG_TOT_DC_REQ_LSB                                             0
#define GCREG_DEBUG_TOT_DC_REQ_BLK                                             0
#define GCREG_DEBUG_TOT_DC_REQ_Count                                           1
#define GCREG_DEBUG_TOT_DC_REQ_FieldMask                              0xFFFFFFFF
#define GCREG_DEBUG_TOT_DC_REQ_ReadMask                               0xFFFFFFFF
#define GCREG_DEBUG_TOT_DC_REQ_WriteMask                              0x00000000
#define GCREG_DEBUG_TOT_DC_REQ_ResetValue                             0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_DC_REQ_NUM                                          31:0
#define GCREG_DEBUG_TOT_DC_REQ_NUM_End                                        31
#define GCREG_DEBUG_TOT_DC_REQ_NUM_Start                                       0
#define GCREG_DEBUG_TOT_DC_REQ_NUM_Type                                      U32

/* Register gcregDebugLstDCReq **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstDCReqRegAddrs                                        0x087A
#define GCREG_DEBUG_LST_DC_REQ_Address                                   0x001E8
#define GCREG_DEBUG_LST_DC_REQ_MSB                                            15
#define GCREG_DEBUG_LST_DC_REQ_LSB                                             0
#define GCREG_DEBUG_LST_DC_REQ_BLK                                             0
#define GCREG_DEBUG_LST_DC_REQ_Count                                           1
#define GCREG_DEBUG_LST_DC_REQ_FieldMask                              0xFFFFFFFF
#define GCREG_DEBUG_LST_DC_REQ_ReadMask                               0xFFFFFFFF
#define GCREG_DEBUG_LST_DC_REQ_WriteMask                              0x00000000
#define GCREG_DEBUG_LST_DC_REQ_ResetValue                             0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_DC_REQ_NUM                                          31:0
#define GCREG_DEBUG_LST_DC_REQ_NUM_End                                        31
#define GCREG_DEBUG_LST_DC_REQ_NUM_Start                                       0
#define GCREG_DEBUG_LST_DC_REQ_NUM_Type                                      U32

/* Register gcregDebugTotDCRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugTotDCRrbRegAddrs                                        0x087B
#define GCREG_DEBUG_TOT_DC_RRB_Address                                   0x001EC
#define GCREG_DEBUG_TOT_DC_RRB_MSB                                            15
#define GCREG_DEBUG_TOT_DC_RRB_LSB                                             0
#define GCREG_DEBUG_TOT_DC_RRB_BLK                                             0
#define GCREG_DEBUG_TOT_DC_RRB_Count                                           1
#define GCREG_DEBUG_TOT_DC_RRB_FieldMask                              0xFFFFFFFF
#define GCREG_DEBUG_TOT_DC_RRB_ReadMask                               0xFFFFFFFF
#define GCREG_DEBUG_TOT_DC_RRB_WriteMask                              0x00000000
#define GCREG_DEBUG_TOT_DC_RRB_ResetValue                             0x00000000

/* Debug register */
#define GCREG_DEBUG_TOT_DC_RRB_NUM                                          31:0
#define GCREG_DEBUG_TOT_DC_RRB_NUM_End                                        31
#define GCREG_DEBUG_TOT_DC_RRB_NUM_Start                                       0
#define GCREG_DEBUG_TOT_DC_RRB_NUM_Type                                      U32

/* Register gcregDebugLstDCRrb **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugLstDCRrbRegAddrs                                        0x087C
#define GCREG_DEBUG_LST_DC_RRB_Address                                   0x001F0
#define GCREG_DEBUG_LST_DC_RRB_MSB                                            15
#define GCREG_DEBUG_LST_DC_RRB_LSB                                             0
#define GCREG_DEBUG_LST_DC_RRB_BLK                                             0
#define GCREG_DEBUG_LST_DC_RRB_Count                                           1
#define GCREG_DEBUG_LST_DC_RRB_FieldMask                              0xFFFFFFFF
#define GCREG_DEBUG_LST_DC_RRB_ReadMask                               0xFFFFFFFF
#define GCREG_DEBUG_LST_DC_RRB_WriteMask                              0x00000000
#define GCREG_DEBUG_LST_DC_RRB_ResetValue                             0x00000000

/* Debug register */
#define GCREG_DEBUG_LST_DC_RRB_NUM                                          31:0
#define GCREG_DEBUG_LST_DC_RRB_NUM_End                                        31
#define GCREG_DEBUG_LST_DC_RRB_NUM_Start                                       0
#define GCREG_DEBUG_LST_DC_RRB_NUM_Type                                      U32

/* Register gcregDebugFrameAndMisflag **
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define gcregDebugFrameAndMisflagRegAddrs                                 0x087D
#define GCREG_DEBUG_FRAME_AND_MISFLAG_Address                            0x001F4
#define GCREG_DEBUG_FRAME_AND_MISFLAG_MSB                                     15
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LSB                                      0
#define GCREG_DEBUG_FRAME_AND_MISFLAG_BLK                                      0
#define GCREG_DEBUG_FRAME_AND_MISFLAG_Count                                    1
#define GCREG_DEBUG_FRAME_AND_MISFLAG_FieldMask                       0xFFFFFFFF
#define GCREG_DEBUG_FRAME_AND_MISFLAG_ReadMask                        0xFFFFFFFF
#define GCREG_DEBUG_FRAME_AND_MISFLAG_WriteMask                       0x00000000
#define GCREG_DEBUG_FRAME_AND_MISFLAG_ResetValue                      0x00000000

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_TOTAL            0:0
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_TOTAL_End          0
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_TOTAL_Start        0
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_TOTAL_Type       U01

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG                  4:1
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_End                4
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_Start              1
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_MISMATCH_FLAG_Type             U04

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_FRAME_CNT                     15:5
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_FRAME_CNT_End                   15
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_FRAME_CNT_Start                  5
#define GCREG_DEBUG_FRAME_AND_MISFLAG_CURRENT_FRAME_CNT_Type                 U11

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_TOTAL             16:16
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_TOTAL_End            16
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_TOTAL_Start          16
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_TOTAL_Type          U01

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG                   20:17
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_End                  20
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_Start                17
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_MISMATCH_FLAG_Type                U04

/* Debug register */
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_FRAME_CNT                       31:21
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_FRAME_CNT_End                      31
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_FRAME_CNT_Start                    21
#define GCREG_DEBUG_FRAME_AND_MISFLAG_LAST_FRAME_CNT_Type                    U11


#endif /* __gcregDisplay_h__ */
