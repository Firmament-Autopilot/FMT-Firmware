/*
 * Copyright (c) 2020-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ETHOSU65_INTERFACE_H
#define ETHOSU65_INTERFACE_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#if !defined(__cplusplus) || __cplusplus < 201402L
#define CONSTEXPR
#else
#define CONSTEXPR constexpr
#endif

#ifndef __cplusplus
#define STRUCT struct
#else
#define STRUCT
#endif

#if defined(__cplusplus) && defined(NPU_DISASSEMBLE)
#include <iomanip>
#include <sstream>
#include <vector>
#endif

#if defined(__cplusplus) && !defined(NPU_NAMESPACE)
#define NPU_NAMESPACE npu
#endif

#ifdef __cplusplus
#include <cstring>
#include <limits>
#endif

#ifdef __cplusplus
namespace NPU_NAMESPACE
{
#endif
#define NNX_ARCH_VERSION_MAJOR 1
#define NNX_ARCH_VERSION_MINOR 0
#define NNX_ARCH_VERSION_PATCH 6

// Register offsets
//
// Register subpage BASE
//
#define NPU_REG_ID 0x0000
#define NPU_REG_STATUS 0x0004
#define NPU_REG_CMD 0x0008
#define NPU_REG_RESET 0x000C
#define NPU_REG_QBASE 0x0010
#define NPU_REG_QBASE_HI 0x0014
#define NPU_REG_QREAD 0x0018
#define NPU_REG_QCONFIG 0x001C
#define NPU_REG_QSIZE 0x0020
#define NPU_REG_PROT 0x0024
#define NPU_REG_CONFIG 0x0028
#define NPU_REG_LOCK 0x002C
#define NPU_REG_REGIONCFG 0x003C
#define NPU_REG_AXI_LIMIT0 0x0040
#define NPU_REG_AXI_LIMIT1 0x0044
#define NPU_REG_AXI_LIMIT2 0x0048
#define NPU_REG_AXI_LIMIT3 0x004C
#define BASE_REGISTERS_SIZE 0x0080

//
// Register subpage BASE_POINTERS
//
#define NPU_REG_BASEP_BASE 0x0080
#define NPU_REG_BASEP_ARRLEN 0x0008
#define BASE_POINTERS_REGISTERS_SIZE 0x0100

//
// Register subpage DEBUG
//
#define NPU_REG_WD_STATUS 0x0100
#define NPU_REG_MAC_STATUS 0x0104
#define NPU_REG_AO_STATUS 0x0108
#define NPU_REG_DMA_STATUS0 0x0110
#define NPU_REG_DMA_STATUS1 0x0114
#define NPU_REG_CLKFORCE 0x0140
#define NPU_REG_DEBUG_ADDRESS 0x0144
#define NPU_REG_DEBUG_MISC 0x0148
#define NPU_REG_DEBUGCORE 0x014C
#define NPU_REG_DEBUG_BLOCK 0x0150
#define DEBUG_REGISTERS_SIZE 0x0180

//
// Register subpage PMU
//
#define NPU_REG_PMCR 0x0180
#define NPU_REG_PMCNTENSET 0x0184
#define NPU_REG_PMCNTENCLR 0x0188
#define NPU_REG_PMOVSSET 0x018C
#define NPU_REG_PMOVSCLR 0x0190
#define NPU_REG_PMINTSET 0x0194
#define NPU_REG_PMINTCLR 0x0198
#define NPU_REG_PMCCNTR 0x01A0
#define NPU_REG_PMCCNTR_HI 0x01A4
#define NPU_REG_PMCCNTR_CFG 0x01A8
#define NPU_REG_PMCAXI_CHAN 0x01AC
#define PMU_REGISTERS_SIZE 0x0200

//
// Register subpage TSU_DEBUG
//
#define NPU_REG_KERNEL_X 0x0200
#define NPU_REG_KERNEL_Y 0x0204
#define NPU_REG_KERNEL_W_M1 0x0208
#define NPU_REG_KERNEL_H_M1 0x020C
#define NPU_REG_OFM_CBLK_WIDTH_M1 0x0210
#define NPU_REG_OFM_CBLK_HEIGHT_M1 0x0214
#define NPU_REG_OFM_CBLK_DEPTH_M1 0x0218
#define NPU_REG_IFM_CBLK_DEPTH_M1 0x021C
#define NPU_REG_OFM_X 0x0220
#define NPU_REG_OFM_Y 0x0224
#define NPU_REG_OFM_Z 0x0228
#define NPU_REG_IFM_Z 0x022C
#define NPU_REG_PAD_TOP 0x0230
#define NPU_REG_PAD_LEFT 0x0234
#define NPU_REG_IFM_CBLK_WIDTH 0x0238
#define NPU_REG_IFM_CBLK_HEIGHT 0x023C
#define NPU_REG_DMA_IFM_SRC 0x0240
#define NPU_REG_DMA_IFM_SRC_HI 0x0244
#define NPU_REG_DMA_IFM_DST 0x0248
#define NPU_REG_DMA_OFM_SRC 0x024C
#define NPU_REG_DMA_OFM_DST 0x0250
#define NPU_REG_DMA_OFM_DST_HI 0x0254
#define NPU_REG_DMA_WEIGHT_SRC 0x0258
#define NPU_REG_DMA_WEIGHT_SRC_HI 0x025C
#define NPU_REG_DMA_CMD_SRC 0x0260
#define NPU_REG_DMA_CMD_SRC_HI 0x0264
#define NPU_REG_DMA_CMD_SIZE 0x0268
#define NPU_REG_DMA_M2M_SRC 0x026C
#define NPU_REG_DMA_M2M_SRC_HI 0x0270
#define NPU_REG_DMA_M2M_DST 0x0274
#define NPU_REG_DMA_M2M_DST_HI 0x0278
#define NPU_REG_CURRENT_QREAD 0x027C
#define NPU_REG_DMA_SCALE_SRC 0x0280
#define NPU_REG_DMA_SCALE_SRC_HI 0x0284
#define NPU_REG_CURRENT_BLOCK 0x02B4
#define NPU_REG_CURRENT_OP 0x02B8
#define NPU_REG_CURRENT_CMD 0x02BC
#define TSU_DEBUG_REGISTERS_SIZE 0x02C0

//
// Register subpage PMU_COUNTERS
//
#define NPU_REG_PMEVCNTR_BASE 0x0300
#define NPU_REG_PMEVCNTR_ARRLEN 0x0004
#define NPU_REG_PMEVTYPER_BASE 0x0380
#define NPU_REG_PMEVTYPER_ARRLEN 0x0004
#define PMU_COUNTERS_REGISTERS_SIZE 0x0400

//
// Register subpage SHARED_BUFFER
//
#define NPU_REG_SHARED_BUFFER_BASE 0x0400
#define NPU_REG_SHARED_BUFFER_ARRLEN 0x0100
#define SHARED_BUFFER_REGISTERS_SIZE 0x0800

//
// Register subpage TSU_IFM
//
#define NPU_REG_IFM_PAD_TOP 0x0800
#define NPU_REG_IFM_PAD_LEFT 0x0804
#define NPU_REG_IFM_PAD_RIGHT 0x0808
#define NPU_REG_IFM_PAD_BOTTOM 0x080C
#define NPU_REG_IFM_DEPTH_M1 0x0810
#define NPU_REG_IFM_PRECISION 0x0814
#define NPU_REG_IFM_UPSCALE 0x081C
#define NPU_REG_IFM_ZERO_POINT 0x0824
#define NPU_REG_IFM_WIDTH0_M1 0x0828
#define NPU_REG_IFM_HEIGHT0_M1 0x082C
#define NPU_REG_IFM_HEIGHT1_M1 0x0830
#define NPU_REG_IFM_IB_END 0x0834
#define NPU_REG_IFM_REGION 0x083C
#define TSU_IFM_REGISTERS_SIZE 0x0840

//
// Register subpage TSU_OFM
//
#define NPU_REG_OFM_WIDTH_M1 0x0844
#define NPU_REG_OFM_HEIGHT_M1 0x0848
#define NPU_REG_OFM_DEPTH_M1 0x084C
#define NPU_REG_OFM_PRECISION 0x0850
#define NPU_REG_OFM_BLK_WIDTH_M1 0x0854
#define NPU_REG_OFM_BLK_HEIGHT_M1 0x0858
#define NPU_REG_OFM_BLK_DEPTH_M1 0x085C
#define NPU_REG_OFM_ZERO_POINT 0x0860
#define NPU_REG_OFM_WIDTH0_M1 0x0868
#define NPU_REG_OFM_HEIGHT0_M1 0x086C
#define NPU_REG_OFM_HEIGHT1_M1 0x0870
#define NPU_REG_OFM_REGION 0x087C
#define TSU_OFM_REGISTERS_SIZE 0x0880

//
// Register subpage TSU_KERNEL
//
#define NPU_REG_KERNEL_WIDTH_M1 0x0880
#define NPU_REG_KERNEL_HEIGHT_M1 0x0884
#define NPU_REG_KERNEL_STRIDE 0x0888
#define NPU_REG_PARALLEL_MODE 0x088C
#define NPU_REG_ACC_FORMAT 0x0890
#define NPU_REG_ACTIVATION 0x0894
#define NPU_REG_ACTIVATION_MIN 0x0898
#define NPU_REG_ACTIVATION_MAX 0x089C
#define NPU_REG_WEIGHT_REGION 0x08A0
#define NPU_REG_SCALE_REGION 0x08A4
#define NPU_REG_AB_START 0x08B4
#define NPU_REG_BLOCKDEP 0x08BC
#define TSU_KERNEL_REGISTERS_SIZE 0x08C0

//
// Register subpage TSU_DMA
//
#define NPU_REG_DMA0_SRC_REGION 0x08C0
#define NPU_REG_DMA0_DST_REGION 0x08C4
#define NPU_REG_DMA0_SIZE0 0x08C8
#define NPU_REG_DMA0_SIZE1 0x08CC
#define TSU_DMA_REGISTERS_SIZE 0x0900

//
// Register subpage TSU_IFM2
//
#define NPU_REG_IFM2_BROADCAST 0x0900
#define NPU_REG_IFM2_SCALAR 0x0904
#define NPU_REG_IFM2_PRECISION 0x0914
#define NPU_REG_IFM2_ZERO_POINT 0x0924
#define NPU_REG_IFM2_WIDTH0_M1 0x0928
#define NPU_REG_IFM2_HEIGHT0_M1 0x092C
#define NPU_REG_IFM2_HEIGHT1_M1 0x0930
#define NPU_REG_IFM2_IB_START 0x0934
#define NPU_REG_IFM2_REGION 0x093C
#define TSU_IFM2_REGISTERS_SIZE 0x0940

//
// Register subpage TSU_IFM_BASE
//
#define NPU_REG_IFM_BASE0 0x0A00
#define NPU_REG_IFM_BASE0_HI 0x0A04
#define NPU_REG_IFM_BASE1 0x0A08
#define NPU_REG_IFM_BASE1_HI 0x0A0C
#define NPU_REG_IFM_BASE2 0x0A10
#define NPU_REG_IFM_BASE2_HI 0x0A14
#define NPU_REG_IFM_BASE3 0x0A18
#define NPU_REG_IFM_BASE3_HI 0x0A1C
#define NPU_REG_IFM_STRIDE_X 0x0A20
#define NPU_REG_IFM_STRIDE_X_HI 0x0A24
#define NPU_REG_IFM_STRIDE_Y 0x0A28
#define NPU_REG_IFM_STRIDE_Y_HI 0x0A2C
#define NPU_REG_IFM_STRIDE_C 0x0A30
#define NPU_REG_IFM_STRIDE_C_HI 0x0A34
#define TSU_IFM_BASE_REGISTERS_SIZE 0x0A40

//
// Register subpage TSU_OFM_BASE
//
#define NPU_REG_OFM_BASE0 0x0A40
#define NPU_REG_OFM_BASE0_HI 0x0A44
#define NPU_REG_OFM_BASE1 0x0A48
#define NPU_REG_OFM_BASE1_HI 0x0A4C
#define NPU_REG_OFM_BASE2 0x0A50
#define NPU_REG_OFM_BASE2_HI 0x0A54
#define NPU_REG_OFM_BASE3 0x0A58
#define NPU_REG_OFM_BASE3_HI 0x0A5C
#define NPU_REG_OFM_STRIDE_X 0x0A60
#define NPU_REG_OFM_STRIDE_X_HI 0x0A64
#define NPU_REG_OFM_STRIDE_Y 0x0A68
#define NPU_REG_OFM_STRIDE_Y_HI 0x0A6C
#define NPU_REG_OFM_STRIDE_C 0x0A70
#define NPU_REG_OFM_STRIDE_C_HI 0x0A74
#define TSU_OFM_BASE_REGISTERS_SIZE 0x0A80

//
// Register subpage TSU_WS_BASE
//
#define NPU_REG_WEIGHT_BASE 0x0A80
#define NPU_REG_WEIGHT_BASE_HI 0x0A84
#define NPU_REG_WEIGHT_LENGTH 0x0A88
#define NPU_REG_WEIGHT_LENGTH_HI 0x0A8C
#define NPU_REG_SCALE_BASE 0x0A90
#define NPU_REG_SCALE_BASE_HI 0x0A94
#define NPU_REG_SCALE_LENGTH 0x0A98
#define NPU_REG_SCALE_LENGTH_HI 0x0A9C
#define NPU_REG_OFM_SCALE 0x0AA0
#define NPU_REG_OFM_SCALE_SHIFT 0x0AA4
#define NPU_REG_OPA_SCALE 0x0AA8
#define NPU_REG_OPA_SCALE_SHIFT 0x0AAC
#define NPU_REG_OPB_SCALE 0x0AB0
#define TSU_WS_BASE_REGISTERS_SIZE 0x0AC0

//
// Register subpage TSU_DMA_BASE
//
#define NPU_REG_DMA0_SRC 0x0AC0
#define NPU_REG_DMA0_SRC_HI 0x0AC4
#define NPU_REG_DMA0_DST 0x0AC8
#define NPU_REG_DMA0_DST_HI 0x0ACC
#define NPU_REG_DMA0_LEN 0x0AD0
#define NPU_REG_DMA0_LEN_HI 0x0AD4
#define NPU_REG_DMA0_SKIP0 0x0AD8
#define NPU_REG_DMA0_SKIP0_HI 0x0ADC
#define NPU_REG_DMA0_SKIP1 0x0AE0
#define NPU_REG_DMA0_SKIP1_HI 0x0AE4
#define TSU_DMA_BASE_REGISTERS_SIZE 0x0B00

//
// Register subpage TSU_IFM2_BASE
//
#define NPU_REG_IFM2_BASE0 0x0B00
#define NPU_REG_IFM2_BASE0_HI 0x0B04
#define NPU_REG_IFM2_BASE1 0x0B08
#define NPU_REG_IFM2_BASE1_HI 0x0B0C
#define NPU_REG_IFM2_BASE2 0x0B10
#define NPU_REG_IFM2_BASE2_HI 0x0B14
#define NPU_REG_IFM2_BASE3 0x0B18
#define NPU_REG_IFM2_BASE3_HI 0x0B1C
#define NPU_REG_IFM2_STRIDE_X 0x0B20
#define NPU_REG_IFM2_STRIDE_X_HI 0x0B24
#define NPU_REG_IFM2_STRIDE_Y 0x0B28
#define NPU_REG_IFM2_STRIDE_Y_HI 0x0B2C
#define NPU_REG_IFM2_STRIDE_C 0x0B30
#define NPU_REG_IFM2_STRIDE_C_HI 0x0B34
#define TSU_IFM2_BASE_REGISTERS_SIZE 0x0B40

//
// Register subpage TSU_WS1_BASE
//
#define NPU_REG_WEIGHT1_BASE 0x0B40
#define NPU_REG_WEIGHT1_BASE_HI 0x0B44
#define NPU_REG_WEIGHT1_LENGTH 0x0B48
#define NPU_REG_WEIGHT1_LENGTH_HI 0x0B4C
#define NPU_REG_SCALE1_BASE 0x0B50
#define NPU_REG_SCALE1_BASE_HI 0x0B54
#define NPU_REG_SCALE1_LENGTH 0x0B58
#define NPU_REG_SCALE1_LENGTH_HI 0x0B5C
#define TSU_WS1_BASE_REGISTERS_SIZE 0x0B80

//
// Register subpage TSU_USER_BASE
//
#define TSU_USER_BASE_REGISTERS_SIZE 0x0BC0

//
// Register subpage TSU_DMA_EBASE
//
#define TSU_DMA_EBASE_REGISTERS_SIZE 0x0C00

//
// Register subpage ID
//
#define NPU_REG_REVISION 0x0FC0
#define NPU_REG_PID4 0x0FD0
#define NPU_REG_PID5 0x0FD4
#define NPU_REG_PID6 0x0FD8
#define NPU_REG_PID7 0x0FDC
#define NPU_REG_PID0 0x0FE0
#define NPU_REG_PID1 0x0FE4
#define NPU_REG_PID2 0x0FE8
#define NPU_REG_PID3 0x0FEC
#define NPU_REG_CID0 0x0FF0
#define NPU_REG_CID1 0x0FF4
#define NPU_REG_CID2 0x0FF8
#define NPU_REG_CID3 0x0FFC
#define ID_REGISTERS_SIZE 0x1000

#ifdef __cplusplus
// Enum types
enum class acc_format : uint8_t
{
    I32 = 0,
    I40 = 1,
    F16 = 2,
};

enum class activation_clip_range : uint8_t
{
    OFM_PRECISION = 0,
    FORCE_UINT8   = 2,
    FORCE_INT8    = 3,
    FORCE_INT16   = 5,
};

enum class activation_format : uint8_t
{
    NHWC    = 0,
    NHCWB16 = 1,
};

enum class activation_function : uint8_t
{
    RELU    = 0,
    TANH    = 3,
    SIGMOID = 4,
    TABLE_0 = 16,
    TABLE_1 = 17,
    TABLE_2 = 18,
    TABLE_3 = 19,
    TABLE_4 = 20,
    TABLE_5 = 21,
    TABLE_6 = 22,
    TABLE_7 = 23,
};

enum class activation_precision : uint8_t
{
    B8  = 0,
    B16 = 1,
    B32 = 2,
    B64 = 3,
};

enum class activation_type : uint8_t
{
    UNSIGNED = 0,
    SIGNED   = 1,
};

enum class axi_mem_encoding : uint8_t
{
    DEVICE_NON_BUFFERABLE                 = 0,
    DEVICE_BUFFERABLE                     = 1,
    NORMAL_NON_CACHEABLE_NON_BUFFERABLE   = 2,
    NORMAL_NON_CACHEABLE_BUFFERABLE       = 3,
    WRITE_THROUGH_NO_ALLOCATE             = 4,
    WRITE_THROUGH_READ_ALLOCATE           = 5,
    WRITE_THROUGH_WRITE_ALLOCATE          = 6,
    WRITE_THROUGH_READ_AND_WRITE_ALLOCATE = 7,
    WRITE_BACK_NO_ALLOCATE                = 8,
    WRITE_BACK_READ_ALLOCATE              = 9,
    WRITE_BACK_WRITE_ALLOCATE             = 10,
    WRITE_BACK_READ_AND_WRITE_ALLOCATE    = 11,
};

enum class broadcast_mode : uint8_t
{
    DISABLE = 0,
    ENABLE  = 1,
};

enum class cmd0_opcode : uint16_t
{
    NPU_OP_STOP               = 0,
    NPU_OP_IRQ                = 1,
    NPU_OP_CONV               = 2,
    NPU_OP_DEPTHWISE          = 3,
    NPU_OP_POOL               = 5,
    NPU_OP_ELEMENTWISE        = 6,
    NPU_OP_DMA_START          = 16,
    NPU_OP_DMA_WAIT           = 17,
    NPU_OP_KERNEL_WAIT        = 18,
    NPU_OP_PMU_MASK           = 19,
    NPU_SET_IFM_PAD_TOP       = 256,
    NPU_SET_IFM_PAD_LEFT      = 257,
    NPU_SET_IFM_PAD_RIGHT     = 258,
    NPU_SET_IFM_PAD_BOTTOM    = 259,
    NPU_SET_IFM_DEPTH_M1      = 260,
    NPU_SET_IFM_PRECISION     = 261,
    NPU_SET_IFM_UPSCALE       = 263,
    NPU_SET_IFM_ZERO_POINT    = 265,
    NPU_SET_IFM_WIDTH0_M1     = 266,
    NPU_SET_IFM_HEIGHT0_M1    = 267,
    NPU_SET_IFM_HEIGHT1_M1    = 268,
    NPU_SET_IFM_IB_END        = 269,
    NPU_SET_IFM_REGION        = 271,
    NPU_SET_OFM_WIDTH_M1      = 273,
    NPU_SET_OFM_HEIGHT_M1     = 274,
    NPU_SET_OFM_DEPTH_M1      = 275,
    NPU_SET_OFM_PRECISION     = 276,
    NPU_SET_OFM_BLK_WIDTH_M1  = 277,
    NPU_SET_OFM_BLK_HEIGHT_M1 = 278,
    NPU_SET_OFM_BLK_DEPTH_M1  = 279,
    NPU_SET_OFM_ZERO_POINT    = 280,
    NPU_SET_OFM_WIDTH0_M1     = 282,
    NPU_SET_OFM_HEIGHT0_M1    = 283,
    NPU_SET_OFM_HEIGHT1_M1    = 284,
    NPU_SET_OFM_REGION        = 287,
    NPU_SET_KERNEL_WIDTH_M1   = 288,
    NPU_SET_KERNEL_HEIGHT_M1  = 289,
    NPU_SET_KERNEL_STRIDE     = 290,
    NPU_SET_PARALLEL_MODE     = 291,
    NPU_SET_ACC_FORMAT        = 292,
    NPU_SET_ACTIVATION        = 293,
    NPU_SET_ACTIVATION_MIN    = 294,
    NPU_SET_ACTIVATION_MAX    = 295,
    NPU_SET_WEIGHT_REGION     = 296,
    NPU_SET_SCALE_REGION      = 297,
    NPU_SET_AB_START          = 301,
    NPU_SET_BLOCKDEP          = 303,
    NPU_SET_DMA0_SRC_REGION   = 304,
    NPU_SET_DMA0_DST_REGION   = 305,
    NPU_SET_DMA0_SIZE0        = 306,
    NPU_SET_DMA0_SIZE1        = 307,
    NPU_SET_IFM2_BROADCAST    = 384,
    NPU_SET_IFM2_SCALAR       = 385,
    NPU_SET_IFM2_PRECISION    = 389,
    NPU_SET_IFM2_ZERO_POINT   = 393,
    NPU_SET_IFM2_WIDTH0_M1    = 394,
    NPU_SET_IFM2_HEIGHT0_M1   = 395,
    NPU_SET_IFM2_HEIGHT1_M1   = 396,
    NPU_SET_IFM2_IB_START     = 397,
    NPU_SET_IFM2_REGION       = 399,
};

enum class cmd1_opcode : uint16_t
{
    NPU_SET_IFM_BASE0      = 0,
    NPU_SET_IFM_BASE1      = 1,
    NPU_SET_IFM_BASE2      = 2,
    NPU_SET_IFM_BASE3      = 3,
    NPU_SET_IFM_STRIDE_X   = 4,
    NPU_SET_IFM_STRIDE_Y   = 5,
    NPU_SET_IFM_STRIDE_C   = 6,
    NPU_SET_OFM_BASE0      = 16,
    NPU_SET_OFM_BASE1      = 17,
    NPU_SET_OFM_BASE2      = 18,
    NPU_SET_OFM_BASE3      = 19,
    NPU_SET_OFM_STRIDE_X   = 20,
    NPU_SET_OFM_STRIDE_Y   = 21,
    NPU_SET_OFM_STRIDE_C   = 22,
    NPU_SET_WEIGHT_BASE    = 32,
    NPU_SET_WEIGHT_LENGTH  = 33,
    NPU_SET_SCALE_BASE     = 34,
    NPU_SET_SCALE_LENGTH   = 35,
    NPU_SET_OFM_SCALE      = 36,
    NPU_SET_OPA_SCALE      = 37,
    NPU_SET_OPB_SCALE      = 38,
    NPU_SET_DMA0_SRC       = 48,
    NPU_SET_DMA0_DST       = 49,
    NPU_SET_DMA0_LEN       = 50,
    NPU_SET_DMA0_SKIP0     = 51,
    NPU_SET_DMA0_SKIP1     = 52,
    NPU_SET_IFM2_BASE0     = 128,
    NPU_SET_IFM2_BASE1     = 129,
    NPU_SET_IFM2_BASE2     = 130,
    NPU_SET_IFM2_BASE3     = 131,
    NPU_SET_IFM2_STRIDE_X  = 132,
    NPU_SET_IFM2_STRIDE_Y  = 133,
    NPU_SET_IFM2_STRIDE_C  = 134,
    NPU_SET_WEIGHT1_BASE   = 144,
    NPU_SET_WEIGHT1_LENGTH = 145,
    NPU_SET_SCALE1_BASE    = 146,
    NPU_SET_SCALE1_LENGTH  = 147,
};

enum class cmd_ctrl : uint8_t
{
    CMD0_CTRL = 0,
    CMD1_CTRL = 1,
};

enum class custom_dma : uint8_t
{
    NOT_IMPLEMENTED = 0,
    IMPLEMENTED     = 1,
};

enum class dma_fault_src : uint8_t
{
    AXI_M0 = 0,
    AXI_M1 = 1,
};

enum class dma_region_mode : uint8_t
{
    EXTERNAL = 0,
    INTERNAL = 1,
};

enum class dma_stride_mode : uint8_t
{
    D1 = 0,
    D2 = 1,
    D3 = 2,
};

enum class elementwise_mode : uint8_t
{
    MUL   = 0,
    ADD   = 1,
    SUB   = 2,
    MIN   = 3,
    MAX   = 4,
    LRELU = 5,
    ABS   = 6,
    CLZ   = 7,
    SHR   = 8,
    SHL   = 9,
};

enum class functional_safety : uint8_t
{
    NOT_IMPLEMENTED = 0,
    IMPLEMENTED     = 1,
};

enum class ifm2_operand_order : uint8_t
{
    ORDER_B = 0,
    ORDER_A = 1,
};

enum class ifm_scale_mode : uint8_t
{
    OPA_OPB_16 = 0,
    OPA_32     = 1,
    OPB_32     = 2,
};

enum class ifm_upscale_mode : uint8_t
{
    NONE    = 0,
    NEAREST = 1,
    ZEROS   = 2,
};

enum class kernel_decomposition : uint8_t
{
    D8X8 = 0,
    D4X4 = 1,
};

enum class kernel_dilation : uint8_t
{
    NONE = 0,
    X2   = 1,
};

enum class max_beats : uint8_t
{
    B64  = 0,
    B128 = 1,
    B256 = 2,
};

enum class mem_attr : uint8_t
{
    AXI0_OUTSTANDING_COUNTER0 = 0,
    AXI0_OUTSTANDING_COUNTER1 = 1,
    AXI1_OUTSTANDING_COUNTER2 = 2,
    AXI1_OUTSTANDING_COUNTER3 = 3,
};

enum class ofm_scale_mode : uint8_t
{
    PER_CHANNEL = 0,
    GLOBAL      = 1,
};

enum class parallel_mode : uint8_t
{
    SINGLE_CORE     = 0,
    DUAL_CORE_DEPTH = 1,
};

enum class pmu_axi_channel : uint8_t
{
    RD_CMD        = 0,
    RD_IFM        = 1,
    RD_WEIGHTS    = 2,
    RD_SCALE_BIAS = 3,
    RD_MEM2MEM    = 4,
    WR_OFM        = 8,
    WR_MEM2MEM    = 9,
};

enum class pmu_event : uint16_t
{
    NO_EVENT                     = 0,
    CYCLE                        = 17,
    NPU_IDLE                     = 32,
    CC_STALLED_ON_BLOCKDEP       = 33,
    CC_STALLED_ON_SHRAM_RECONFIG = 34,
    NPU_ACTIVE                   = 35,
    MAC_ACTIVE                   = 48,
    MAC_ACTIVE_8BIT              = 49,
    MAC_ACTIVE_16BIT             = 50,
    MAC_DPU_ACTIVE               = 51,
    MAC_STALLED_BY_WD_ACC        = 52,
    MAC_STALLED_BY_WD            = 53,
    MAC_STALLED_BY_ACC           = 54,
    MAC_STALLED_BY_IB            = 55,
    MAC_ACTIVE_32BIT             = 56,
    MAC_STALLED_BY_INT_W         = 57,
    MAC_STALLED_BY_INT_ACC       = 58,
    AO_ACTIVE                    = 64,
    AO_ACTIVE_8BIT               = 65,
    AO_ACTIVE_16BIT              = 66,
    AO_STALLED_BY_OFMP_OB        = 67,
    AO_STALLED_BY_OFMP           = 68,
    AO_STALLED_BY_OB             = 69,
    AO_STALLED_BY_ACC_IB         = 70,
    AO_STALLED_BY_ACC            = 71,
    AO_STALLED_BY_IB             = 72,
    WD_ACTIVE                    = 80,
    WD_STALLED                   = 81,
    WD_STALLED_BY_WS             = 82,
    WD_STALLED_BY_WD_BUF         = 83,
    WD_PARSE_ACTIVE              = 84,
    WD_PARSE_STALLED             = 85,
    WD_PARSE_STALLED_IN          = 86,
    WD_PARSE_STALLED_OUT         = 87,
    WD_TRANS_WS                  = 88,
    WD_TRANS_WB                  = 89,
    WD_TRANS_DW0                 = 90,
    WD_TRANS_DW1                 = 91,
    AXI0_RD_TRANS_ACCEPTED       = 128,
    AXI0_RD_TRANS_COMPLETED      = 129,
    AXI0_RD_DATA_BEAT_RECEIVED   = 130,
    AXI0_RD_TRAN_REQ_STALLED     = 131,
    AXI0_WR_TRANS_ACCEPTED       = 132,
    AXI0_WR_TRANS_COMPLETED_M    = 133,
    AXI0_WR_TRANS_COMPLETED_S    = 134,
    AXI0_WR_DATA_BEAT_WRITTEN    = 135,
    AXI0_WR_TRAN_REQ_STALLED     = 136,
    AXI0_WR_DATA_BEAT_STALLED    = 137,
    AXI0_ENABLED_CYCLES          = 140,
    AXI0_RD_STALL_LIMIT          = 142,
    AXI0_WR_STALL_LIMIT          = 143,
    AXI_LATENCY_ANY              = 160,
    AXI_LATENCY_32               = 161,
    AXI_LATENCY_64               = 162,
    AXI_LATENCY_128              = 163,
    AXI_LATENCY_256              = 164,
    AXI_LATENCY_512              = 165,
    AXI_LATENCY_1024             = 166,
    ECC_DMA                      = 176,
    ECC_SB0                      = 177,
    AXI1_RD_TRANS_ACCEPTED       = 384,
    AXI1_RD_TRANS_COMPLETED      = 385,
    AXI1_RD_DATA_BEAT_RECEIVED   = 386,
    AXI1_RD_TRAN_REQ_STALLED     = 387,
    AXI1_WR_TRANS_ACCEPTED       = 388,
    AXI1_WR_TRANS_COMPLETED_M    = 389,
    AXI1_WR_TRANS_COMPLETED_S    = 390,
    AXI1_WR_DATA_BEAT_WRITTEN    = 391,
    AXI1_WR_TRAN_REQ_STALLED     = 392,
    AXI1_WR_DATA_BEAT_STALLED    = 393,
    AXI1_ENABLED_CYCLES          = 396,
    AXI1_RD_STALL_LIMIT          = 398,
    AXI1_WR_STALL_LIMIT          = 399,
    ECC_SB1                      = 433,
};

enum class pooling_mode : uint8_t
{
    MAX        = 0,
    AVERAGE    = 1,
    REDUCE_SUM = 2,
};

enum class privilege_level : uint8_t
{
    USER       = 0,
    PRIVILEGED = 1,
};

enum class round_mode : uint8_t
{
    DBL      = 0,
    TRUNCATE = 1,
    NATURAL  = 2,
};

enum class security_level : uint8_t
{
    SECURE     = 0,
    NON_SECURE = 1,
};

enum class state : uint8_t
{
    STOPPED = 0,
    RUNNING = 1,
};

enum class wd_core_slice_state : uint8_t
{
    HEADER  = 0,
    PALETTE = 1,
    WEIGHTS = 2,
};

enum class wd_ctrl_state : uint8_t
{
    IDLE     = 0,
    DRAIN    = 1,
    OFD_INIT = 2,
    OFD_RUN  = 3,
};

enum class weight_order : uint8_t
{
    DEPTH_FIRST       = 0,
    PART_KERNEL_FIRST = 1,
};

#else

enum acc_format
{
    ACC_FORMAT_I32 = 0,
    ACC_FORMAT_I40 = 1,
    ACC_FORMAT_F16 = 2,
};

enum activation_clip_range
{
    ACTIVATION_CLIP_RANGE_OFM_PRECISION = 0,
    ACTIVATION_CLIP_RANGE_FORCE_UINT8   = 2,
    ACTIVATION_CLIP_RANGE_FORCE_INT8    = 3,
    ACTIVATION_CLIP_RANGE_FORCE_INT16   = 5,
};

enum activation_format
{
    ACTIVATION_FORMAT_NHWC    = 0,
    ACTIVATION_FORMAT_NHCWB16 = 1,
};

enum activation_function
{
    ACTIVATION_FUNCTION_RELU    = 0,
    ACTIVATION_FUNCTION_TANH    = 3,
    ACTIVATION_FUNCTION_SIGMOID = 4,
    ACTIVATION_FUNCTION_TABLE_0 = 16,
    ACTIVATION_FUNCTION_TABLE_1 = 17,
    ACTIVATION_FUNCTION_TABLE_2 = 18,
    ACTIVATION_FUNCTION_TABLE_3 = 19,
    ACTIVATION_FUNCTION_TABLE_4 = 20,
    ACTIVATION_FUNCTION_TABLE_5 = 21,
    ACTIVATION_FUNCTION_TABLE_6 = 22,
    ACTIVATION_FUNCTION_TABLE_7 = 23,
};

enum activation_precision
{
    ACTIVATION_PRECISION_B8  = 0,
    ACTIVATION_PRECISION_B16 = 1,
    ACTIVATION_PRECISION_B32 = 2,
    ACTIVATION_PRECISION_B64 = 3,
};

enum activation_type
{
    ACTIVATION_TYPE_UNSIGNED = 0,
    ACTIVATION_TYPE_SIGNED   = 1,
};

enum axi_mem_encoding
{
    AXI_MEM_ENCODING_DEVICE_NON_BUFFERABLE                 = 0,
    AXI_MEM_ENCODING_DEVICE_BUFFERABLE                     = 1,
    AXI_MEM_ENCODING_NORMAL_NON_CACHEABLE_NON_BUFFERABLE   = 2,
    AXI_MEM_ENCODING_NORMAL_NON_CACHEABLE_BUFFERABLE       = 3,
    AXI_MEM_ENCODING_WRITE_THROUGH_NO_ALLOCATE             = 4,
    AXI_MEM_ENCODING_WRITE_THROUGH_READ_ALLOCATE           = 5,
    AXI_MEM_ENCODING_WRITE_THROUGH_WRITE_ALLOCATE          = 6,
    AXI_MEM_ENCODING_WRITE_THROUGH_READ_AND_WRITE_ALLOCATE = 7,
    AXI_MEM_ENCODING_WRITE_BACK_NO_ALLOCATE                = 8,
    AXI_MEM_ENCODING_WRITE_BACK_READ_ALLOCATE              = 9,
    AXI_MEM_ENCODING_WRITE_BACK_WRITE_ALLOCATE             = 10,
    AXI_MEM_ENCODING_WRITE_BACK_READ_AND_WRITE_ALLOCATE    = 11,
};

enum broadcast_mode
{
    BROADCAST_MODE_DISABLE = 0,
    BROADCAST_MODE_ENABLE  = 1,
};

enum cmd0_opcode
{
    CMD0_OPCODE_NPU_OP_STOP               = 0,
    CMD0_OPCODE_NPU_OP_IRQ                = 1,
    CMD0_OPCODE_NPU_OP_CONV               = 2,
    CMD0_OPCODE_NPU_OP_DEPTHWISE          = 3,
    CMD0_OPCODE_NPU_OP_POOL               = 5,
    CMD0_OPCODE_NPU_OP_ELEMENTWISE        = 6,
    CMD0_OPCODE_NPU_OP_DMA_START          = 16,
    CMD0_OPCODE_NPU_OP_DMA_WAIT           = 17,
    CMD0_OPCODE_NPU_OP_KERNEL_WAIT        = 18,
    CMD0_OPCODE_NPU_OP_PMU_MASK           = 19,
    CMD0_OPCODE_NPU_SET_IFM_PAD_TOP       = 256,
    CMD0_OPCODE_NPU_SET_IFM_PAD_LEFT      = 257,
    CMD0_OPCODE_NPU_SET_IFM_PAD_RIGHT     = 258,
    CMD0_OPCODE_NPU_SET_IFM_PAD_BOTTOM    = 259,
    CMD0_OPCODE_NPU_SET_IFM_DEPTH_M1      = 260,
    CMD0_OPCODE_NPU_SET_IFM_PRECISION     = 261,
    CMD0_OPCODE_NPU_SET_IFM_UPSCALE       = 263,
    CMD0_OPCODE_NPU_SET_IFM_ZERO_POINT    = 265,
    CMD0_OPCODE_NPU_SET_IFM_WIDTH0_M1     = 266,
    CMD0_OPCODE_NPU_SET_IFM_HEIGHT0_M1    = 267,
    CMD0_OPCODE_NPU_SET_IFM_HEIGHT1_M1    = 268,
    CMD0_OPCODE_NPU_SET_IFM_IB_END        = 269,
    CMD0_OPCODE_NPU_SET_IFM_REGION        = 271,
    CMD0_OPCODE_NPU_SET_OFM_WIDTH_M1      = 273,
    CMD0_OPCODE_NPU_SET_OFM_HEIGHT_M1     = 274,
    CMD0_OPCODE_NPU_SET_OFM_DEPTH_M1      = 275,
    CMD0_OPCODE_NPU_SET_OFM_PRECISION     = 276,
    CMD0_OPCODE_NPU_SET_OFM_BLK_WIDTH_M1  = 277,
    CMD0_OPCODE_NPU_SET_OFM_BLK_HEIGHT_M1 = 278,
    CMD0_OPCODE_NPU_SET_OFM_BLK_DEPTH_M1  = 279,
    CMD0_OPCODE_NPU_SET_OFM_ZERO_POINT    = 280,
    CMD0_OPCODE_NPU_SET_OFM_WIDTH0_M1     = 282,
    CMD0_OPCODE_NPU_SET_OFM_HEIGHT0_M1    = 283,
    CMD0_OPCODE_NPU_SET_OFM_HEIGHT1_M1    = 284,
    CMD0_OPCODE_NPU_SET_OFM_REGION        = 287,
    CMD0_OPCODE_NPU_SET_KERNEL_WIDTH_M1   = 288,
    CMD0_OPCODE_NPU_SET_KERNEL_HEIGHT_M1  = 289,
    CMD0_OPCODE_NPU_SET_KERNEL_STRIDE     = 290,
    CMD0_OPCODE_NPU_SET_PARALLEL_MODE     = 291,
    CMD0_OPCODE_NPU_SET_ACC_FORMAT        = 292,
    CMD0_OPCODE_NPU_SET_ACTIVATION        = 293,
    CMD0_OPCODE_NPU_SET_ACTIVATION_MIN    = 294,
    CMD0_OPCODE_NPU_SET_ACTIVATION_MAX    = 295,
    CMD0_OPCODE_NPU_SET_WEIGHT_REGION     = 296,
    CMD0_OPCODE_NPU_SET_SCALE_REGION      = 297,
    CMD0_OPCODE_NPU_SET_AB_START          = 301,
    CMD0_OPCODE_NPU_SET_BLOCKDEP          = 303,
    CMD0_OPCODE_NPU_SET_DMA0_SRC_REGION   = 304,
    CMD0_OPCODE_NPU_SET_DMA0_DST_REGION   = 305,
    CMD0_OPCODE_NPU_SET_DMA0_SIZE0        = 306,
    CMD0_OPCODE_NPU_SET_DMA0_SIZE1        = 307,
    CMD0_OPCODE_NPU_SET_IFM2_BROADCAST    = 384,
    CMD0_OPCODE_NPU_SET_IFM2_SCALAR       = 385,
    CMD0_OPCODE_NPU_SET_IFM2_PRECISION    = 389,
    CMD0_OPCODE_NPU_SET_IFM2_ZERO_POINT   = 393,
    CMD0_OPCODE_NPU_SET_IFM2_WIDTH0_M1    = 394,
    CMD0_OPCODE_NPU_SET_IFM2_HEIGHT0_M1   = 395,
    CMD0_OPCODE_NPU_SET_IFM2_HEIGHT1_M1   = 396,
    CMD0_OPCODE_NPU_SET_IFM2_IB_START     = 397,
    CMD0_OPCODE_NPU_SET_IFM2_REGION       = 399,
};

enum cmd1_opcode
{
    CMD1_OPCODE_NPU_SET_IFM_BASE0      = 0,
    CMD1_OPCODE_NPU_SET_IFM_BASE1      = 1,
    CMD1_OPCODE_NPU_SET_IFM_BASE2      = 2,
    CMD1_OPCODE_NPU_SET_IFM_BASE3      = 3,
    CMD1_OPCODE_NPU_SET_IFM_STRIDE_X   = 4,
    CMD1_OPCODE_NPU_SET_IFM_STRIDE_Y   = 5,
    CMD1_OPCODE_NPU_SET_IFM_STRIDE_C   = 6,
    CMD1_OPCODE_NPU_SET_OFM_BASE0      = 16,
    CMD1_OPCODE_NPU_SET_OFM_BASE1      = 17,
    CMD1_OPCODE_NPU_SET_OFM_BASE2      = 18,
    CMD1_OPCODE_NPU_SET_OFM_BASE3      = 19,
    CMD1_OPCODE_NPU_SET_OFM_STRIDE_X   = 20,
    CMD1_OPCODE_NPU_SET_OFM_STRIDE_Y   = 21,
    CMD1_OPCODE_NPU_SET_OFM_STRIDE_C   = 22,
    CMD1_OPCODE_NPU_SET_WEIGHT_BASE    = 32,
    CMD1_OPCODE_NPU_SET_WEIGHT_LENGTH  = 33,
    CMD1_OPCODE_NPU_SET_SCALE_BASE     = 34,
    CMD1_OPCODE_NPU_SET_SCALE_LENGTH   = 35,
    CMD1_OPCODE_NPU_SET_OFM_SCALE      = 36,
    CMD1_OPCODE_NPU_SET_OPA_SCALE      = 37,
    CMD1_OPCODE_NPU_SET_OPB_SCALE      = 38,
    CMD1_OPCODE_NPU_SET_DMA0_SRC       = 48,
    CMD1_OPCODE_NPU_SET_DMA0_DST       = 49,
    CMD1_OPCODE_NPU_SET_DMA0_LEN       = 50,
    CMD1_OPCODE_NPU_SET_DMA0_SKIP0     = 51,
    CMD1_OPCODE_NPU_SET_DMA0_SKIP1     = 52,
    CMD1_OPCODE_NPU_SET_IFM2_BASE0     = 128,
    CMD1_OPCODE_NPU_SET_IFM2_BASE1     = 129,
    CMD1_OPCODE_NPU_SET_IFM2_BASE2     = 130,
    CMD1_OPCODE_NPU_SET_IFM2_BASE3     = 131,
    CMD1_OPCODE_NPU_SET_IFM2_STRIDE_X  = 132,
    CMD1_OPCODE_NPU_SET_IFM2_STRIDE_Y  = 133,
    CMD1_OPCODE_NPU_SET_IFM2_STRIDE_C  = 134,
    CMD1_OPCODE_NPU_SET_WEIGHT1_BASE   = 144,
    CMD1_OPCODE_NPU_SET_WEIGHT1_LENGTH = 145,
    CMD1_OPCODE_NPU_SET_SCALE1_BASE    = 146,
    CMD1_OPCODE_NPU_SET_SCALE1_LENGTH  = 147,
};

enum cmd_ctrl
{
    CMD_CTRL_CMD0_CTRL = 0,
    CMD_CTRL_CMD1_CTRL = 1,
};

enum custom_dma
{
    CUSTOM_DMA_NOT_IMPLEMENTED = 0,
    CUSTOM_DMA_IMPLEMENTED     = 1,
};

enum dma_fault_src
{
    DMA_FAULT_SRC_AXI_M0 = 0,
    DMA_FAULT_SRC_AXI_M1 = 1,
};

enum dma_region_mode
{
    DMA_REGION_MODE_EXTERNAL = 0,
    DMA_REGION_MODE_INTERNAL = 1,
};

enum dma_stride_mode
{
    DMA_STRIDE_MODE_D1 = 0,
    DMA_STRIDE_MODE_D2 = 1,
    DMA_STRIDE_MODE_D3 = 2,
};

enum elementwise_mode
{
    ELEMENTWISE_MODE_MUL   = 0,
    ELEMENTWISE_MODE_ADD   = 1,
    ELEMENTWISE_MODE_SUB   = 2,
    ELEMENTWISE_MODE_MIN   = 3,
    ELEMENTWISE_MODE_MAX   = 4,
    ELEMENTWISE_MODE_LRELU = 5,
    ELEMENTWISE_MODE_ABS   = 6,
    ELEMENTWISE_MODE_CLZ   = 7,
    ELEMENTWISE_MODE_SHR   = 8,
    ELEMENTWISE_MODE_SHL   = 9,
};

enum functional_safety
{
    FUNCTIONAL_SAFETY_NOT_IMPLEMENTED = 0,
    FUNCTIONAL_SAFETY_IMPLEMENTED     = 1,
};

enum ifm2_operand_order
{
    IFM2_OPERAND_ORDER_ORDER_B = 0,
    IFM2_OPERAND_ORDER_ORDER_A = 1,
};

enum ifm_scale_mode
{
    IFM_SCALE_MODE_OPA_OPB_16 = 0,
    IFM_SCALE_MODE_OPA_32     = 1,
    IFM_SCALE_MODE_OPB_32     = 2,
};

enum ifm_upscale_mode
{
    IFM_UPSCALE_MODE_NONE    = 0,
    IFM_UPSCALE_MODE_NEAREST = 1,
    IFM_UPSCALE_MODE_ZEROS   = 2,
};

enum kernel_decomposition
{
    KERNEL_DECOMPOSITION_D8X8 = 0,
    KERNEL_DECOMPOSITION_D4X4 = 1,
};

enum kernel_dilation
{
    KERNEL_DILATION_NONE = 0,
    KERNEL_DILATION_X2   = 1,
};

enum max_beats
{
    MAX_BEATS_B64  = 0,
    MAX_BEATS_B128 = 1,
    MAX_BEATS_B256 = 2,
};

enum mem_attr
{
    MEM_ATTR_AXI0_OUTSTANDING_COUNTER0 = 0,
    MEM_ATTR_AXI0_OUTSTANDING_COUNTER1 = 1,
    MEM_ATTR_AXI1_OUTSTANDING_COUNTER2 = 2,
    MEM_ATTR_AXI1_OUTSTANDING_COUNTER3 = 3,
};

enum ofm_scale_mode
{
    OFM_SCALE_MODE_PER_CHANNEL = 0,
    OFM_SCALE_MODE_GLOBAL      = 1,
};

enum parallel_mode
{
    PARALLEL_MODE_SINGLE_CORE     = 0,
    PARALLEL_MODE_DUAL_CORE_DEPTH = 1,
};

enum pmu_axi_channel
{
    PMU_AXI_CHANNEL_RD_CMD        = 0,
    PMU_AXI_CHANNEL_RD_IFM        = 1,
    PMU_AXI_CHANNEL_RD_WEIGHTS    = 2,
    PMU_AXI_CHANNEL_RD_SCALE_BIAS = 3,
    PMU_AXI_CHANNEL_RD_MEM2MEM    = 4,
    PMU_AXI_CHANNEL_WR_OFM        = 8,
    PMU_AXI_CHANNEL_WR_MEM2MEM    = 9,
};

enum pmu_event
{
    PMU_EVENT_NO_EVENT                     = 0,
    PMU_EVENT_CYCLE                        = 17,
    PMU_EVENT_NPU_IDLE                     = 32,
    PMU_EVENT_CC_STALLED_ON_BLOCKDEP       = 33,
    PMU_EVENT_CC_STALLED_ON_SHRAM_RECONFIG = 34,
    PMU_EVENT_NPU_ACTIVE                   = 35,
    PMU_EVENT_MAC_ACTIVE                   = 48,
    PMU_EVENT_MAC_ACTIVE_8BIT              = 49,
    PMU_EVENT_MAC_ACTIVE_16BIT             = 50,
    PMU_EVENT_MAC_DPU_ACTIVE               = 51,
    PMU_EVENT_MAC_STALLED_BY_WD_ACC        = 52,
    PMU_EVENT_MAC_STALLED_BY_WD            = 53,
    PMU_EVENT_MAC_STALLED_BY_ACC           = 54,
    PMU_EVENT_MAC_STALLED_BY_IB            = 55,
    PMU_EVENT_MAC_ACTIVE_32BIT             = 56,
    PMU_EVENT_MAC_STALLED_BY_INT_W         = 57,
    PMU_EVENT_MAC_STALLED_BY_INT_ACC       = 58,
    PMU_EVENT_AO_ACTIVE                    = 64,
    PMU_EVENT_AO_ACTIVE_8BIT               = 65,
    PMU_EVENT_AO_ACTIVE_16BIT              = 66,
    PMU_EVENT_AO_STALLED_BY_OFMP_OB        = 67,
    PMU_EVENT_AO_STALLED_BY_OFMP           = 68,
    PMU_EVENT_AO_STALLED_BY_OB             = 69,
    PMU_EVENT_AO_STALLED_BY_ACC_IB         = 70,
    PMU_EVENT_AO_STALLED_BY_ACC            = 71,
    PMU_EVENT_AO_STALLED_BY_IB             = 72,
    PMU_EVENT_WD_ACTIVE                    = 80,
    PMU_EVENT_WD_STALLED                   = 81,
    PMU_EVENT_WD_STALLED_BY_WS             = 82,
    PMU_EVENT_WD_STALLED_BY_WD_BUF         = 83,
    PMU_EVENT_WD_PARSE_ACTIVE              = 84,
    PMU_EVENT_WD_PARSE_STALLED             = 85,
    PMU_EVENT_WD_PARSE_STALLED_IN          = 86,
    PMU_EVENT_WD_PARSE_STALLED_OUT         = 87,
    PMU_EVENT_WD_TRANS_WS                  = 88,
    PMU_EVENT_WD_TRANS_WB                  = 89,
    PMU_EVENT_WD_TRANS_DW0                 = 90,
    PMU_EVENT_WD_TRANS_DW1                 = 91,
    PMU_EVENT_AXI0_RD_TRANS_ACCEPTED       = 128,
    PMU_EVENT_AXI0_RD_TRANS_COMPLETED      = 129,
    PMU_EVENT_AXI0_RD_DATA_BEAT_RECEIVED   = 130,
    PMU_EVENT_AXI0_RD_TRAN_REQ_STALLED     = 131,
    PMU_EVENT_AXI0_WR_TRANS_ACCEPTED       = 132,
    PMU_EVENT_AXI0_WR_TRANS_COMPLETED_M    = 133,
    PMU_EVENT_AXI0_WR_TRANS_COMPLETED_S    = 134,
    PMU_EVENT_AXI0_WR_DATA_BEAT_WRITTEN    = 135,
    PMU_EVENT_AXI0_WR_TRAN_REQ_STALLED     = 136,
    PMU_EVENT_AXI0_WR_DATA_BEAT_STALLED    = 137,
    PMU_EVENT_AXI0_ENABLED_CYCLES          = 140,
    PMU_EVENT_AXI0_RD_STALL_LIMIT          = 142,
    PMU_EVENT_AXI0_WR_STALL_LIMIT          = 143,
    PMU_EVENT_AXI_LATENCY_ANY              = 160,
    PMU_EVENT_AXI_LATENCY_32               = 161,
    PMU_EVENT_AXI_LATENCY_64               = 162,
    PMU_EVENT_AXI_LATENCY_128              = 163,
    PMU_EVENT_AXI_LATENCY_256              = 164,
    PMU_EVENT_AXI_LATENCY_512              = 165,
    PMU_EVENT_AXI_LATENCY_1024             = 166,
    PMU_EVENT_ECC_DMA                      = 176,
    PMU_EVENT_ECC_SB0                      = 177,
    PMU_EVENT_AXI1_RD_TRANS_ACCEPTED       = 384,
    PMU_EVENT_AXI1_RD_TRANS_COMPLETED      = 385,
    PMU_EVENT_AXI1_RD_DATA_BEAT_RECEIVED   = 386,
    PMU_EVENT_AXI1_RD_TRAN_REQ_STALLED     = 387,
    PMU_EVENT_AXI1_WR_TRANS_ACCEPTED       = 388,
    PMU_EVENT_AXI1_WR_TRANS_COMPLETED_M    = 389,
    PMU_EVENT_AXI1_WR_TRANS_COMPLETED_S    = 390,
    PMU_EVENT_AXI1_WR_DATA_BEAT_WRITTEN    = 391,
    PMU_EVENT_AXI1_WR_TRAN_REQ_STALLED     = 392,
    PMU_EVENT_AXI1_WR_DATA_BEAT_STALLED    = 393,
    PMU_EVENT_AXI1_ENABLED_CYCLES          = 396,
    PMU_EVENT_AXI1_RD_STALL_LIMIT          = 398,
    PMU_EVENT_AXI1_WR_STALL_LIMIT          = 399,
    PMU_EVENT_ECC_SB1                      = 433,
};

enum pooling_mode
{
    POOLING_MODE_MAX        = 0,
    POOLING_MODE_AVERAGE    = 1,
    POOLING_MODE_REDUCE_SUM = 2,
};

enum privilege_level
{
    PRIVILEGE_LEVEL_USER       = 0,
    PRIVILEGE_LEVEL_PRIVILEGED = 1,
};

enum round_mode
{
    ROUND_MODE_DBL      = 0,
    ROUND_MODE_TRUNCATE = 1,
    ROUND_MODE_NATURAL  = 2,
};

enum security_level
{
    SECURITY_LEVEL_SECURE     = 0,
    SECURITY_LEVEL_NON_SECURE = 1,
};

enum state
{
    STATE_STOPPED = 0,
    STATE_RUNNING = 1,
};

enum wd_core_slice_state
{
    WD_CORE_SLICE_STATE_HEADER  = 0,
    WD_CORE_SLICE_STATE_PALETTE = 1,
    WD_CORE_SLICE_STATE_WEIGHTS = 2,
};

enum wd_ctrl_state
{
    WD_CTRL_STATE_IDLE     = 0,
    WD_CTRL_STATE_DRAIN    = 1,
    WD_CTRL_STATE_OFD_INIT = 2,
    WD_CTRL_STATE_OFD_RUN  = 3,
};

enum weight_order
{
    WEIGHT_ORDER_DEPTH_FIRST       = 0,
    WEIGHT_ORDER_PART_KERNEL_FIRST = 1,
};

#endif

#ifdef NPU_DISASSEMBLE

static const char *acc_format_str[] = {
    "ACC_FORMAT_I32",
    "ACC_FORMAT_I40",
    "ACC_FORMAT_F16",
};

static const char *activation_clip_range_str[] = {
    "ACTIVATION_CLIP_RANGE_OFM_PRECISION",
    "****",
    "ACTIVATION_CLIP_RANGE_FORCE_UINT8",
    "ACTIVATION_CLIP_RANGE_FORCE_INT8",
    "****",
    "ACTIVATION_CLIP_RANGE_FORCE_INT16",
};

static const char *activation_format_str[] = {
    "ACTIVATION_FORMAT_NHWC",
    "ACTIVATION_FORMAT_NHCWB16",
};

static const char *activation_function_str[] = {
    "ACTIVATION_FUNCTION_RELU",
    "****",
    "****",
    "ACTIVATION_FUNCTION_TANH",
    "ACTIVATION_FUNCTION_SIGMOID",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "ACTIVATION_FUNCTION_TABLE_0",
    "ACTIVATION_FUNCTION_TABLE_1",
    "ACTIVATION_FUNCTION_TABLE_2",
    "ACTIVATION_FUNCTION_TABLE_3",
    "ACTIVATION_FUNCTION_TABLE_4",
    "ACTIVATION_FUNCTION_TABLE_5",
    "ACTIVATION_FUNCTION_TABLE_6",
    "ACTIVATION_FUNCTION_TABLE_7",
};

static const char *activation_precision_str[] = {
    "ACTIVATION_PRECISION_B8",
    "ACTIVATION_PRECISION_B16",
    "ACTIVATION_PRECISION_B32",
    "ACTIVATION_PRECISION_B64",
};

static const char *activation_type_str[] = {
    "ACTIVATION_TYPE_UNSIGNED",
    "ACTIVATION_TYPE_SIGNED",
};

static const char *axi_mem_encoding_str[] = {
    "AXI_MEM_ENCODING_DEVICE_NON_BUFFERABLE",
    "AXI_MEM_ENCODING_DEVICE_BUFFERABLE",
    "AXI_MEM_ENCODING_NORMAL_NON_CACHEABLE_NON_BUFFERABLE",
    "AXI_MEM_ENCODING_NORMAL_NON_CACHEABLE_BUFFERABLE",
    "AXI_MEM_ENCODING_WRITE_THROUGH_NO_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_THROUGH_READ_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_THROUGH_WRITE_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_THROUGH_READ_AND_WRITE_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_BACK_NO_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_BACK_READ_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_BACK_WRITE_ALLOCATE",
    "AXI_MEM_ENCODING_WRITE_BACK_READ_AND_WRITE_ALLOCATE",
};

static const char *broadcast_mode_str[] = {
    "BROADCAST_MODE_DISABLE",
    "BROADCAST_MODE_ENABLE",
};

static const char *cmd0_opcode_str[] = {
    "CMD0_OPCODE_NPU_OP_STOP",
    "CMD0_OPCODE_NPU_OP_IRQ",
    "CMD0_OPCODE_NPU_OP_CONV",
    "CMD0_OPCODE_NPU_OP_DEPTHWISE",
    "****",
    "CMD0_OPCODE_NPU_OP_POOL",
    "CMD0_OPCODE_NPU_OP_ELEMENTWISE",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_OP_DMA_START",
    "CMD0_OPCODE_NPU_OP_DMA_WAIT",
    "CMD0_OPCODE_NPU_OP_KERNEL_WAIT",
    "CMD0_OPCODE_NPU_OP_PMU_MASK",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM_PAD_TOP",
    "CMD0_OPCODE_NPU_SET_IFM_PAD_LEFT",
    "CMD0_OPCODE_NPU_SET_IFM_PAD_RIGHT",
    "CMD0_OPCODE_NPU_SET_IFM_PAD_BOTTOM",
    "CMD0_OPCODE_NPU_SET_IFM_DEPTH_M1",
    "CMD0_OPCODE_NPU_SET_IFM_PRECISION",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM_UPSCALE",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM_ZERO_POINT",
    "CMD0_OPCODE_NPU_SET_IFM_WIDTH0_M1",
    "CMD0_OPCODE_NPU_SET_IFM_HEIGHT0_M1",
    "CMD0_OPCODE_NPU_SET_IFM_HEIGHT1_M1",
    "CMD0_OPCODE_NPU_SET_IFM_IB_END",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM_REGION",
    "****",
    "CMD0_OPCODE_NPU_SET_OFM_WIDTH_M1",
    "CMD0_OPCODE_NPU_SET_OFM_HEIGHT_M1",
    "CMD0_OPCODE_NPU_SET_OFM_DEPTH_M1",
    "CMD0_OPCODE_NPU_SET_OFM_PRECISION",
    "CMD0_OPCODE_NPU_SET_OFM_BLK_WIDTH_M1",
    "CMD0_OPCODE_NPU_SET_OFM_BLK_HEIGHT_M1",
    "CMD0_OPCODE_NPU_SET_OFM_BLK_DEPTH_M1",
    "CMD0_OPCODE_NPU_SET_OFM_ZERO_POINT",
    "****",
    "CMD0_OPCODE_NPU_SET_OFM_WIDTH0_M1",
    "CMD0_OPCODE_NPU_SET_OFM_HEIGHT0_M1",
    "CMD0_OPCODE_NPU_SET_OFM_HEIGHT1_M1",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_OFM_REGION",
    "CMD0_OPCODE_NPU_SET_KERNEL_WIDTH_M1",
    "CMD0_OPCODE_NPU_SET_KERNEL_HEIGHT_M1",
    "CMD0_OPCODE_NPU_SET_KERNEL_STRIDE",
    "CMD0_OPCODE_NPU_SET_PARALLEL_MODE",
    "CMD0_OPCODE_NPU_SET_ACC_FORMAT",
    "CMD0_OPCODE_NPU_SET_ACTIVATION",
    "CMD0_OPCODE_NPU_SET_ACTIVATION_MIN",
    "CMD0_OPCODE_NPU_SET_ACTIVATION_MAX",
    "CMD0_OPCODE_NPU_SET_WEIGHT_REGION",
    "CMD0_OPCODE_NPU_SET_SCALE_REGION",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_AB_START",
    "****",
    "CMD0_OPCODE_NPU_SET_BLOCKDEP",
    "CMD0_OPCODE_NPU_SET_DMA0_SRC_REGION",
    "CMD0_OPCODE_NPU_SET_DMA0_DST_REGION",
    "CMD0_OPCODE_NPU_SET_DMA0_SIZE0",
    "CMD0_OPCODE_NPU_SET_DMA0_SIZE1",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM2_BROADCAST",
    "CMD0_OPCODE_NPU_SET_IFM2_SCALAR",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM2_PRECISION",
    "****",
    "****",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM2_ZERO_POINT",
    "CMD0_OPCODE_NPU_SET_IFM2_WIDTH0_M1",
    "CMD0_OPCODE_NPU_SET_IFM2_HEIGHT0_M1",
    "CMD0_OPCODE_NPU_SET_IFM2_HEIGHT1_M1",
    "CMD0_OPCODE_NPU_SET_IFM2_IB_START",
    "****",
    "CMD0_OPCODE_NPU_SET_IFM2_REGION",
};

static const char *cmd1_opcode_str[] = {
    "CMD1_OPCODE_NPU_SET_IFM_BASE0",
    "CMD1_OPCODE_NPU_SET_IFM_BASE1",
    "CMD1_OPCODE_NPU_SET_IFM_BASE2",
    "CMD1_OPCODE_NPU_SET_IFM_BASE3",
    "CMD1_OPCODE_NPU_SET_IFM_STRIDE_X",
    "CMD1_OPCODE_NPU_SET_IFM_STRIDE_Y",
    "CMD1_OPCODE_NPU_SET_IFM_STRIDE_C",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD1_OPCODE_NPU_SET_OFM_BASE0",
    "CMD1_OPCODE_NPU_SET_OFM_BASE1",
    "CMD1_OPCODE_NPU_SET_OFM_BASE2",
    "CMD1_OPCODE_NPU_SET_OFM_BASE3",
    "CMD1_OPCODE_NPU_SET_OFM_STRIDE_X",
    "CMD1_OPCODE_NPU_SET_OFM_STRIDE_Y",
    "CMD1_OPCODE_NPU_SET_OFM_STRIDE_C",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD1_OPCODE_NPU_SET_WEIGHT_BASE",
    "CMD1_OPCODE_NPU_SET_WEIGHT_LENGTH",
    "CMD1_OPCODE_NPU_SET_SCALE_BASE",
    "CMD1_OPCODE_NPU_SET_SCALE_LENGTH",
    "CMD1_OPCODE_NPU_SET_OFM_SCALE",
    "CMD1_OPCODE_NPU_SET_OPA_SCALE",
    "CMD1_OPCODE_NPU_SET_OPB_SCALE",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD1_OPCODE_NPU_SET_DMA0_SRC",
    "CMD1_OPCODE_NPU_SET_DMA0_DST",
    "CMD1_OPCODE_NPU_SET_DMA0_LEN",
    "CMD1_OPCODE_NPU_SET_DMA0_SKIP0",
    "CMD1_OPCODE_NPU_SET_DMA0_SKIP1",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD1_OPCODE_NPU_SET_IFM2_BASE0",
    "CMD1_OPCODE_NPU_SET_IFM2_BASE1",
    "CMD1_OPCODE_NPU_SET_IFM2_BASE2",
    "CMD1_OPCODE_NPU_SET_IFM2_BASE3",
    "CMD1_OPCODE_NPU_SET_IFM2_STRIDE_X",
    "CMD1_OPCODE_NPU_SET_IFM2_STRIDE_Y",
    "CMD1_OPCODE_NPU_SET_IFM2_STRIDE_C",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "CMD1_OPCODE_NPU_SET_WEIGHT1_BASE",
    "CMD1_OPCODE_NPU_SET_WEIGHT1_LENGTH",
    "CMD1_OPCODE_NPU_SET_SCALE1_BASE",
    "CMD1_OPCODE_NPU_SET_SCALE1_LENGTH",
};

static const char *cmd_ctrl_str[] = {
    "CMD_CTRL_CMD0_CTRL",
    "CMD_CTRL_CMD1_CTRL",
};

static const char *custom_dma_str[] = {
    "CUSTOM_DMA_NOT_IMPLEMENTED",
    "CUSTOM_DMA_IMPLEMENTED",
};

static const char *dma_fault_src_str[] = {
    "DMA_FAULT_SRC_AXI_M0",
    "DMA_FAULT_SRC_AXI_M1",
};

static const char *dma_region_mode_str[] = {
    "DMA_REGION_MODE_EXTERNAL",
    "DMA_REGION_MODE_INTERNAL",
};

static const char *dma_stride_mode_str[] = {
    "DMA_STRIDE_MODE_D1",
    "DMA_STRIDE_MODE_D2",
    "DMA_STRIDE_MODE_D3",
};

static const char *elementwise_mode_str[] = {
    "ELEMENTWISE_MODE_MUL",
    "ELEMENTWISE_MODE_ADD",
    "ELEMENTWISE_MODE_SUB",
    "ELEMENTWISE_MODE_MIN",
    "ELEMENTWISE_MODE_MAX",
    "ELEMENTWISE_MODE_LRELU",
    "ELEMENTWISE_MODE_ABS",
    "ELEMENTWISE_MODE_CLZ",
    "ELEMENTWISE_MODE_SHR",
    "ELEMENTWISE_MODE_SHL",
};

static const char *functional_safety_str[] = {
    "FUNCTIONAL_SAFETY_NOT_IMPLEMENTED",
    "FUNCTIONAL_SAFETY_IMPLEMENTED",
};

static const char *ifm2_operand_order_str[] = {
    "IFM2_OPERAND_ORDER_ORDER_B",
    "IFM2_OPERAND_ORDER_ORDER_A",
};

static const char *ifm_scale_mode_str[] = {
    "IFM_SCALE_MODE_OPA_OPB_16",
    "IFM_SCALE_MODE_OPA_32",
    "IFM_SCALE_MODE_OPB_32",
};

static const char *ifm_upscale_mode_str[] = {
    "IFM_UPSCALE_MODE_NONE",
    "IFM_UPSCALE_MODE_NEAREST",
    "IFM_UPSCALE_MODE_ZEROS",
};

static const char *kernel_decomposition_str[] = {
    "KERNEL_DECOMPOSITION_D8X8",
    "KERNEL_DECOMPOSITION_D4X4",
};

static const char *kernel_dilation_str[] = {
    "KERNEL_DILATION_NONE",
    "KERNEL_DILATION_X2",
};

static const char *max_beats_str[] = {
    "MAX_BEATS_B64",
    "MAX_BEATS_B128",
    "MAX_BEATS_B256",
};

static const char *mem_attr_str[] = {
    "MEM_ATTR_AXI0_OUTSTANDING_COUNTER0",
    "MEM_ATTR_AXI0_OUTSTANDING_COUNTER1",
    "MEM_ATTR_AXI1_OUTSTANDING_COUNTER2",
    "MEM_ATTR_AXI1_OUTSTANDING_COUNTER3",
};

static const char *ofm_scale_mode_str[] = {
    "OFM_SCALE_MODE_PER_CHANNEL",
    "OFM_SCALE_MODE_GLOBAL",
};

static const char *parallel_mode_str[] = {
    "PARALLEL_MODE_SINGLE_CORE",
    "PARALLEL_MODE_DUAL_CORE_DEPTH",
};

static const char *pmu_axi_channel_str[] = {
    "PMU_AXI_CHANNEL_RD_CMD",
    "PMU_AXI_CHANNEL_RD_IFM",
    "PMU_AXI_CHANNEL_RD_WEIGHTS",
    "PMU_AXI_CHANNEL_RD_SCALE_BIAS",
    "PMU_AXI_CHANNEL_RD_MEM2MEM",
    "****",
    "****",
    "****",
    "PMU_AXI_CHANNEL_WR_OFM",
    "PMU_AXI_CHANNEL_WR_MEM2MEM",
};

static const char *pmu_event_str[] = {
    "PMU_EVENT_NO_EVENT",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_CYCLE",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_NPU_IDLE",
    "PMU_EVENT_CC_STALLED_ON_BLOCKDEP",
    "PMU_EVENT_CC_STALLED_ON_SHRAM_RECONFIG",
    "PMU_EVENT_NPU_ACTIVE",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_MAC_ACTIVE",
    "PMU_EVENT_MAC_ACTIVE_8BIT",
    "PMU_EVENT_MAC_ACTIVE_16BIT",
    "PMU_EVENT_MAC_DPU_ACTIVE",
    "PMU_EVENT_MAC_STALLED_BY_WD_ACC",
    "PMU_EVENT_MAC_STALLED_BY_WD",
    "PMU_EVENT_MAC_STALLED_BY_ACC",
    "PMU_EVENT_MAC_STALLED_BY_IB",
    "PMU_EVENT_MAC_ACTIVE_32BIT",
    "PMU_EVENT_MAC_STALLED_BY_INT_W",
    "PMU_EVENT_MAC_STALLED_BY_INT_ACC",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_AO_ACTIVE",
    "PMU_EVENT_AO_ACTIVE_8BIT",
    "PMU_EVENT_AO_ACTIVE_16BIT",
    "PMU_EVENT_AO_STALLED_BY_OFMP_OB",
    "PMU_EVENT_AO_STALLED_BY_OFMP",
    "PMU_EVENT_AO_STALLED_BY_OB",
    "PMU_EVENT_AO_STALLED_BY_ACC_IB",
    "PMU_EVENT_AO_STALLED_BY_ACC",
    "PMU_EVENT_AO_STALLED_BY_IB",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_WD_ACTIVE",
    "PMU_EVENT_WD_STALLED",
    "PMU_EVENT_WD_STALLED_BY_WS",
    "PMU_EVENT_WD_STALLED_BY_WD_BUF",
    "PMU_EVENT_WD_PARSE_ACTIVE",
    "PMU_EVENT_WD_PARSE_STALLED",
    "PMU_EVENT_WD_PARSE_STALLED_IN",
    "PMU_EVENT_WD_PARSE_STALLED_OUT",
    "PMU_EVENT_WD_TRANS_WS",
    "PMU_EVENT_WD_TRANS_WB",
    "PMU_EVENT_WD_TRANS_DW0",
    "PMU_EVENT_WD_TRANS_DW1",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_AXI0_RD_TRANS_ACCEPTED",
    "PMU_EVENT_AXI0_RD_TRANS_COMPLETED",
    "PMU_EVENT_AXI0_RD_DATA_BEAT_RECEIVED",
    "PMU_EVENT_AXI0_RD_TRAN_REQ_STALLED",
    "PMU_EVENT_AXI0_WR_TRANS_ACCEPTED",
    "PMU_EVENT_AXI0_WR_TRANS_COMPLETED_M",
    "PMU_EVENT_AXI0_WR_TRANS_COMPLETED_S",
    "PMU_EVENT_AXI0_WR_DATA_BEAT_WRITTEN",
    "PMU_EVENT_AXI0_WR_TRAN_REQ_STALLED",
    "PMU_EVENT_AXI0_WR_DATA_BEAT_STALLED",
    "****",
    "****",
    "PMU_EVENT_AXI0_ENABLED_CYCLES",
    "****",
    "PMU_EVENT_AXI0_RD_STALL_LIMIT",
    "PMU_EVENT_AXI0_WR_STALL_LIMIT",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_AXI_LATENCY_ANY",
    "PMU_EVENT_AXI_LATENCY_32",
    "PMU_EVENT_AXI_LATENCY_64",
    "PMU_EVENT_AXI_LATENCY_128",
    "PMU_EVENT_AXI_LATENCY_256",
    "PMU_EVENT_AXI_LATENCY_512",
    "PMU_EVENT_AXI_LATENCY_1024",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_ECC_DMA",
    "PMU_EVENT_ECC_SB0",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_AXI1_RD_TRANS_ACCEPTED",
    "PMU_EVENT_AXI1_RD_TRANS_COMPLETED",
    "PMU_EVENT_AXI1_RD_DATA_BEAT_RECEIVED",
    "PMU_EVENT_AXI1_RD_TRAN_REQ_STALLED",
    "PMU_EVENT_AXI1_WR_TRANS_ACCEPTED",
    "PMU_EVENT_AXI1_WR_TRANS_COMPLETED_M",
    "PMU_EVENT_AXI1_WR_TRANS_COMPLETED_S",
    "PMU_EVENT_AXI1_WR_DATA_BEAT_WRITTEN",
    "PMU_EVENT_AXI1_WR_TRAN_REQ_STALLED",
    "PMU_EVENT_AXI1_WR_DATA_BEAT_STALLED",
    "****",
    "****",
    "PMU_EVENT_AXI1_ENABLED_CYCLES",
    "****",
    "PMU_EVENT_AXI1_RD_STALL_LIMIT",
    "PMU_EVENT_AXI1_WR_STALL_LIMIT",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "****",
    "PMU_EVENT_ECC_SB1",
};

static const char *pooling_mode_str[] = {
    "POOLING_MODE_MAX",
    "POOLING_MODE_AVERAGE",
    "POOLING_MODE_REDUCE_SUM",
};

static const char *privilege_level_str[] = {
    "PRIVILEGE_LEVEL_USER",
    "PRIVILEGE_LEVEL_PRIVILEGED",
};

static const char *round_mode_str[] = {
    "ROUND_MODE_DBL",
    "ROUND_MODE_TRUNCATE",
    "ROUND_MODE_NATURAL",
};

static const char *security_level_str[] = {
    "SECURITY_LEVEL_SECURE",
    "SECURITY_LEVEL_NON_SECURE",
};

static const char *state_str[] = {
    "STATE_STOPPED",
    "STATE_RUNNING",
};

static const char *wd_core_slice_state_str[] = {
    "WD_CORE_SLICE_STATE_HEADER",
    "WD_CORE_SLICE_STATE_PALETTE",
    "WD_CORE_SLICE_STATE_WEIGHTS",
};

static const char *wd_ctrl_state_str[] = {
    "WD_CTRL_STATE_IDLE",
    "WD_CTRL_STATE_DRAIN",
    "WD_CTRL_STATE_OFD_INIT",
    "WD_CTRL_STATE_OFD_RUN",
};

static const char *weight_order_str[] = {
    "WEIGHT_ORDER_DEPTH_FIRST",
    "WEIGHT_ORDER_PART_KERNEL_FIRST",
};

#endif

// Register type structs
// id_r - ID register
struct id_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t version_status : 4; // This is the version of the product
            uint32_t version_minor : 4;  // This is the n for the P part of an RnPn release number
            uint32_t version_major : 4;  // This is the n for the R part of an RnPn release number
            uint32_t product_major : 4;  // Product major ID number (unique per base product)
            uint32_t arch_patch_rev : 4; // This is the patch number of the architecture version a.b
            uint32_t
                arch_minor_rev : 8; // This is the minor architecture version number, b in the architecture version a.b
            uint32_t
                arch_major_rev : 4; // This is the major architecture version number, a in the architecture version a.b
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR id_r() : word0(268853249) {}
    CONSTEXPR id_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    id_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_version_status() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_version_status() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR id_r &set_version_status(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & value) << 0);
        return *this;
    }
    volatile id_r &set_version_status(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_version_minor() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_version_minor() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR id_r &set_version_minor(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & value) << 4);
        return *this;
    }
    volatile id_r &set_version_minor(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_version_major() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_version_major() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR id_r &set_version_major(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 8) & word0) | ((((1U << 4) - 1) & value) << 8);
        return *this;
    }
    volatile id_r &set_version_major(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 8) & word0) | ((((1U << 4) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR uint32_t get_product_major() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 12);
        return value;
    }
    uint32_t get_product_major() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 12);
        return value;
    }
    CONSTEXPR id_r &set_product_major(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 12) & word0) | ((((1U << 4) - 1) & value) << 12);
        return *this;
    }
    volatile id_r &set_product_major(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 12) & word0) | ((((1U << 4) - 1) & value) << 12);
        return *this;
    }
    CONSTEXPR uint32_t get_arch_patch_rev() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_arch_patch_rev() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR id_r &set_arch_patch_rev(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 16) & word0) | ((((1U << 4) - 1) & value) << 16);
        return *this;
    }
    volatile id_r &set_arch_patch_rev(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 16) & word0) | ((((1U << 4) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_arch_minor_rev() const
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 20);
        return value;
    }
    uint32_t get_arch_minor_rev() const volatile
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 20);
        return value;
    }
    CONSTEXPR id_r &set_arch_minor_rev(uint32_t value)
    {
        word0 = (((~((1U << 8) - 1)) << 20) & word0) | ((((1U << 8) - 1) & value) << 20);
        return *this;
    }
    volatile id_r &set_arch_minor_rev(uint32_t value) volatile
    {
        word0 = (((~((1U << 8) - 1)) << 20) & word0) | ((((1U << 8) - 1) & value) << 20);
        return *this;
    }
    CONSTEXPR uint32_t get_arch_major_rev() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 28);
        return value;
    }
    uint32_t get_arch_major_rev() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 28);
        return value;
    }
    CONSTEXPR id_r &set_arch_major_rev(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 28) & word0) | ((((1U << 4) - 1) & value) << 28);
        return *this;
    }
    volatile id_r &set_arch_major_rev(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 28) & word0) | ((((1U << 4) - 1) & value) << 28);
        return *this;
    }
#endif
};

// status_r - Register describes the current operating status of the NPU
struct status_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t state : 1;      // NPU state, 0 = Stopped, 1 = Running
            uint32_t irq_raised : 1; // Raw IRQ status, 0 = IRQ not raised, 1 = IRQ raised. IRQ is cleared using command
                                     // register bit 1
            uint32_t
                bus_status : 1; // 0=OK, 1=Bus abort detected and processing halted (NPU will reach IDLE state and not
                                // to start process any more commands/AXI transactions). Can only be cleared by a reset
            uint32_t reset_status : 1; // Reset is ongoing and only this register can be read (other registers read as 0
                                       // and writes are ignored.) A value of 0 means NPU is not being reset and can be
                                       // accessed as normal
            uint32_t
                cmd_parse_error : 1; // 0=No error 1=Command stream parsing error detected. Can only be cleared by reset
            uint32_t cmd_end_reached : 1; // 0=Not reached, 1=Reached. Cleared by writing QBASE or QSIZE when NPU is in
                                          // stopped state
            uint32_t pmu_irq_raised : 1;  // 0=No PMU IRQ, 1=PMU IRQ raised. Cleared by using command register bit 1
            uint32_t wd_fault : 1; // Weight decoder state: 0=no fault 1=weight decoder decompression fault. Can only be
                                   // cleared by reset
            uint32_t ecc_fault : 1; // ECC state for internal RAMs: 0=no fault 1=ECC fault signalled. Can only be
                                    // cleared by reset
            uint32_t reserved0 : 2;
            uint32_t faulting_interface : 1; // Faulting interface on bus abort
            uint32_t faulting_channel : 4;  // Faulting channel on a bus abort. Read: 0=Cmd 1=IFM 2=Weights 3=Scale+Bias
                                            // 4=Mem2Mem; Write: 8=OFM 9=Mem2Mem
            uint32_t irq_history_mask : 16; // IRQ History mask
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR status_r() : word0(8) {}
    CONSTEXPR status_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    status_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::state get_state() const
    {
        NPU_NAMESPACE::state value = static_cast<NPU_NAMESPACE::state>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::state get_state() const volatile
    {
        NPU_NAMESPACE::state value = static_cast<NPU_NAMESPACE::state>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR status_r &set_state(NPU_NAMESPACE::state value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile status_r &set_state(NPU_NAMESPACE::state value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_irq_raised() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_irq_raised() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR status_r &set_irq_raised(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile status_r &set_irq_raised(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_bus_status() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_bus_status() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR status_r &set_bus_status(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile status_r &set_bus_status(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_reset_status() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_reset_status() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR status_r &set_reset_status(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile status_r &set_reset_status(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_parse_error() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_cmd_parse_error() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR status_r &set_cmd_parse_error(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile status_r &set_cmd_parse_error(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_end_reached() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_cmd_end_reached() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR status_r &set_cmd_end_reached(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile status_r &set_cmd_end_reached(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_pmu_irq_raised() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_pmu_irq_raised() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR status_r &set_pmu_irq_raised(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    volatile status_r &set_pmu_irq_raised(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_fault() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    uint32_t get_wd_fault() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    CONSTEXPR status_r &set_wd_fault(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    volatile status_r &set_wd_fault(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    CONSTEXPR uint32_t get_ecc_fault() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_ecc_fault() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR status_r &set_ecc_fault(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    volatile status_r &set_ecc_fault(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::dma_fault_src get_faulting_interface() const
    {
        NPU_NAMESPACE::dma_fault_src value = static_cast<NPU_NAMESPACE::dma_fault_src>(((1U << 1) - 1) & (word0 >> 11));
        return value;
    }
    NPU_NAMESPACE::dma_fault_src get_faulting_interface() const volatile
    {
        NPU_NAMESPACE::dma_fault_src value = static_cast<NPU_NAMESPACE::dma_fault_src>(((1U << 1) - 1) & (word0 >> 11));
        return value;
    }
    CONSTEXPR status_r &set_faulting_interface(NPU_NAMESPACE::dma_fault_src value)
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 11);
        return *this;
    }
    volatile status_r &set_faulting_interface(NPU_NAMESPACE::dma_fault_src value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 11);
        return *this;
    }
    CONSTEXPR uint32_t get_faulting_channel() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 12);
        return value;
    }
    uint32_t get_faulting_channel() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 12);
        return value;
    }
    CONSTEXPR status_r &set_faulting_channel(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 12) & word0) | ((((1U << 4) - 1) & value) << 12);
        return *this;
    }
    volatile status_r &set_faulting_channel(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 12) & word0) | ((((1U << 4) - 1) & value) << 12);
        return *this;
    }
    CONSTEXPR uint32_t get_irq_history_mask() const
    {
        uint32_t value = ((1U << 16) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_irq_history_mask() const volatile
    {
        uint32_t value = ((1U << 16) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR status_r &set_irq_history_mask(uint32_t value)
    {
        word0 = (((~((1U << 16) - 1)) << 16) & word0) | ((((1U << 16) - 1) & value) << 16);
        return *this;
    }
    volatile status_r &set_irq_history_mask(uint32_t value) volatile
    {
        word0 = (((~((1U << 16) - 1)) << 16) & word0) | ((((1U << 16) - 1) & value) << 16);
        return *this;
    }
#endif
};

// cmd_r - Command register, reads as last written command
struct cmd_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t transition_to_running_state : 1; // Write 1 to transition the NPU to running state. Writing 0 has
                                                      // no effect
            uint32_t clear_irq : 1; // Write 1 to clear the IRQ status in the STATUS register. Writing 0 has no effect
            uint32_t clock_q_enable : 1; // Write 1 to this bit to enable clock off using clock q-interface and enable
                                         // the requester clock gate
            uint32_t power_q_enable : 1; // Write 1 to this bit to enable power off using power q-interface
            uint32_t
                stop_request : 1; // Write 1 to this bit to request STOP after completing any already-started commands
            uint32_t reserved0 : 11;
            uint32_t clear_irq_history : 16; // Clears the IRQ history mask
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR cmd_r() : word0(12) {}
    CONSTEXPR cmd_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    cmd_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_transition_to_running_state() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_transition_to_running_state() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR cmd_r &set_transition_to_running_state(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile cmd_r &set_transition_to_running_state(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_clear_irq() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_clear_irq() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR cmd_r &set_clear_irq(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile cmd_r &set_clear_irq(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_clock_q_enable() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_clock_q_enable() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR cmd_r &set_clock_q_enable(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile cmd_r &set_clock_q_enable(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_power_q_enable() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_power_q_enable() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR cmd_r &set_power_q_enable(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile cmd_r &set_power_q_enable(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_stop_request() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_stop_request() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR cmd_r &set_stop_request(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile cmd_r &set_stop_request(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_clear_irq_history() const
    {
        uint32_t value = ((1U << 16) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_clear_irq_history() const volatile
    {
        uint32_t value = ((1U << 16) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR cmd_r &set_clear_irq_history(uint32_t value)
    {
        word0 = (((~((1U << 16) - 1)) << 16) & word0) | ((((1U << 16) - 1) & value) << 16);
        return *this;
    }
    volatile cmd_r &set_clear_irq_history(uint32_t value) volatile
    {
        word0 = (((~((1U << 16) - 1)) << 16) & word0) | ((((1U << 16) - 1) & value) << 16);
        return *this;
    }
#endif
};

// reset_r - Request Reset and new security mode
struct reset_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t pending_CPL : 1; // Current privilege level 0=User 1=Privileged
            uint32_t pending_CSL : 1; // Current security level 0=Secure 1=Non secure
            uint32_t reserved0 : 30;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR reset_r() : word0(0) {}
    CONSTEXPR reset_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    reset_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::privilege_level get_pending_CPL() const
    {
        NPU_NAMESPACE::privilege_level value =
            static_cast<NPU_NAMESPACE::privilege_level>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::privilege_level get_pending_CPL() const volatile
    {
        NPU_NAMESPACE::privilege_level value =
            static_cast<NPU_NAMESPACE::privilege_level>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR reset_r &set_pending_CPL(NPU_NAMESPACE::privilege_level value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile reset_r &set_pending_CPL(NPU_NAMESPACE::privilege_level value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::security_level get_pending_CSL() const
    {
        NPU_NAMESPACE::security_level value =
            static_cast<NPU_NAMESPACE::security_level>(((1U << 1) - 1) & (word0 >> 1));
        return value;
    }
    NPU_NAMESPACE::security_level get_pending_CSL() const volatile
    {
        NPU_NAMESPACE::security_level value =
            static_cast<NPU_NAMESPACE::security_level>(((1U << 1) - 1) & (word0 >> 1));
        return value;
    }
    CONSTEXPR reset_r &set_pending_CSL(NPU_NAMESPACE::security_level value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 1);
        return *this;
    }
    volatile reset_r &set_pending_CSL(NPU_NAMESPACE::security_level value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 1);
        return *this;
    }
#endif
};

// qbase_r - Base address of the command stream in bytes
struct qbase_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR qbase_r() : word0(0), word1(0) {}
    CONSTEXPR qbase_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    qbase_r copy() volatile
    {
        return *this;
    }
#endif
};

// qread_r - Read offset in the command stream in bytes. Multiple of 4 in the range 0 to 16 MB
struct qread_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t QREAD : 32; // The read offset of the current command under execution
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR qread_r() : word0(0) {}
    CONSTEXPR qread_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    qread_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_QREAD() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_QREAD() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR qread_r &set_QREAD(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile qread_r &set_QREAD(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// qconfig_r - AXI configuration for the command stream in the range 0-3. Same encoding as for REGIONCFG
struct qconfig_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t cmd_region0 : 2; // Command region configuration
            uint32_t reserved0 : 30;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR qconfig_r() : word0(0) {}
    CONSTEXPR qconfig_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    qconfig_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_cmd_region0() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_cmd_region0() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR qconfig_r &set_cmd_region0(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile qconfig_r &set_cmd_region0(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
#endif
};

// qsize_r - Size of the command stream in bytes. Multiple of 4 in the range 0 to 16 MB
struct qsize_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t QSIZE : 32; // Size of the next command stream to be executed by the NPU
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR qsize_r() : word0(0) {}
    CONSTEXPR qsize_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    qsize_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_QSIZE() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_QSIZE() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR qsize_r &set_QSIZE(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile qsize_r &set_QSIZE(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// prot_r - Protection level configured for the NPU when acting as an AXI requester
struct prot_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t active_CPL : 1; // Current privilege level 0=User 1=Privileged
            uint32_t active_CSL : 1; // Current security level 0=Secure 1=Non secure
            uint32_t reserved0 : 30;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR prot_r() : word0(0) {}
    CONSTEXPR prot_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    prot_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::privilege_level get_active_CPL() const
    {
        NPU_NAMESPACE::privilege_level value =
            static_cast<NPU_NAMESPACE::privilege_level>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::privilege_level get_active_CPL() const volatile
    {
        NPU_NAMESPACE::privilege_level value =
            static_cast<NPU_NAMESPACE::privilege_level>(((1U << 1) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR prot_r &set_active_CPL(NPU_NAMESPACE::privilege_level value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile prot_r &set_active_CPL(NPU_NAMESPACE::privilege_level value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::security_level get_active_CSL() const
    {
        NPU_NAMESPACE::security_level value =
            static_cast<NPU_NAMESPACE::security_level>(((1U << 1) - 1) & (word0 >> 1));
        return value;
    }
    NPU_NAMESPACE::security_level get_active_CSL() const volatile
    {
        NPU_NAMESPACE::security_level value =
            static_cast<NPU_NAMESPACE::security_level>(((1U << 1) - 1) & (word0 >> 1));
        return value;
    }
    CONSTEXPR prot_r &set_active_CSL(NPU_NAMESPACE::security_level value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 1);
        return *this;
    }
    volatile prot_r &set_active_CSL(NPU_NAMESPACE::security_level value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 1);
        return *this;
    }
#endif
};

// config_r - RTL configuration
struct config_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t macs_per_cc : 4;        // The log2(macs/clock cycle)
            uint32_t cmd_stream_version : 4; // command stream version accepted by this NPU
            uint32_t shram_size : 8;         // Total size in KB of internal SHRAM
            uint32_t reserved0 : 10;
            uint32_t functional_safety : 1; // Functional safety configuration
            uint32_t custom_dma : 1;        // Custom DMA configuration
            uint32_t product : 4;           // Product configuration
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR config_r() : word0(268435456) {}
    CONSTEXPR config_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    config_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_macs_per_cc() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_macs_per_cc() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR config_r &set_macs_per_cc(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & value) << 0);
        return *this;
    }
    volatile config_r &set_macs_per_cc(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_stream_version() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_cmd_stream_version() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR config_r &set_cmd_stream_version(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & value) << 4);
        return *this;
    }
    volatile config_r &set_cmd_stream_version(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_shram_size() const
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_shram_size() const volatile
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR config_r &set_shram_size(uint32_t value)
    {
        word0 = (((~((1U << 8) - 1)) << 8) & word0) | ((((1U << 8) - 1) & value) << 8);
        return *this;
    }
    volatile config_r &set_shram_size(uint32_t value) volatile
    {
        word0 = (((~((1U << 8) - 1)) << 8) & word0) | ((((1U << 8) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::functional_safety get_functional_safety() const
    {
        NPU_NAMESPACE::functional_safety value =
            static_cast<NPU_NAMESPACE::functional_safety>(((1U << 1) - 1) & (word0 >> 26));
        return value;
    }
    NPU_NAMESPACE::functional_safety get_functional_safety() const volatile
    {
        NPU_NAMESPACE::functional_safety value =
            static_cast<NPU_NAMESPACE::functional_safety>(((1U << 1) - 1) & (word0 >> 26));
        return value;
    }
    CONSTEXPR config_r &set_functional_safety(NPU_NAMESPACE::functional_safety value)
    {
        word0 = (((~((1U << 1) - 1)) << 26) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 26);
        return *this;
    }
    volatile config_r &set_functional_safety(NPU_NAMESPACE::functional_safety value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 26) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 26);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::custom_dma get_custom_dma() const
    {
        NPU_NAMESPACE::custom_dma value = static_cast<NPU_NAMESPACE::custom_dma>(((1U << 1) - 1) & (word0 >> 27));
        return value;
    }
    NPU_NAMESPACE::custom_dma get_custom_dma() const volatile
    {
        NPU_NAMESPACE::custom_dma value = static_cast<NPU_NAMESPACE::custom_dma>(((1U << 1) - 1) & (word0 >> 27));
        return value;
    }
    CONSTEXPR config_r &set_custom_dma(NPU_NAMESPACE::custom_dma value)
    {
        word0 = (((~((1U << 1) - 1)) << 27) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 27);
        return *this;
    }
    volatile config_r &set_custom_dma(NPU_NAMESPACE::custom_dma value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 27) & word0) | ((((1U << 1) - 1) & static_cast<uint32_t>(value)) << 27);
        return *this;
    }
    CONSTEXPR uint32_t get_product() const
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 28);
        return value;
    }
    uint32_t get_product() const volatile
    {
        uint32_t value = ((1U << 4) - 1) & (word0 >> 28);
        return value;
    }
    CONSTEXPR config_r &set_product(uint32_t value)
    {
        word0 = (((~((1U << 4) - 1)) << 28) & word0) | ((((1U << 4) - 1) & value) << 28);
        return *this;
    }
    volatile config_r &set_product(uint32_t value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 28) & word0) | ((((1U << 4) - 1) & value) << 28);
        return *this;
    }
#endif
};

// lock_r - Lock register. This register is designed for driver use and does not affect NPU functionality
struct lock_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t LOCK : 32; // 32 bit value for LOCK configuration
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR lock_r() : word0(0) {}
    CONSTEXPR lock_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    lock_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_LOCK() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_LOCK() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR lock_r &set_LOCK(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile lock_r &set_LOCK(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// regioncfg_r - Region memory type configuration. Bits[2*k+1:2*k] give the memory type for REGION[k]
struct regioncfg_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t region0 : 2; // Bits for Region0 Configuration
            uint32_t region1 : 2; // Bits for Region1 Configuration
            uint32_t region2 : 2; // Bits for Region2 Configuration
            uint32_t region3 : 2; // Bits for Region3 Configuration
            uint32_t region4 : 2; // Bits for Region4 Configuration
            uint32_t region5 : 2; // Bits for Region5 Configuration
            uint32_t region6 : 2; // Bits for Region6 Configuration
            uint32_t region7 : 2; // Bits for Region7 Configuration
            uint32_t reserved0 : 16;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR regioncfg_r() : word0(0) {}
    CONSTEXPR regioncfg_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    regioncfg_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region0() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region0() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region0(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile regioncfg_r &set_region0(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region1() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 2));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region1() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 2));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region1(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 2) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 2);
        return *this;
    }
    volatile regioncfg_r &set_region1(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 2) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 2);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region2() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 4));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region2() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 4));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region2(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 4) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    volatile regioncfg_r &set_region2(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 4) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region3() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 6));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region3() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 6));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region3(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 6) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 6);
        return *this;
    }
    volatile regioncfg_r &set_region3(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 6) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 6);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region4() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 8));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region4() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 8));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region4(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 8) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 8);
        return *this;
    }
    volatile regioncfg_r &set_region4(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 8) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 8);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region5() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 10));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region5() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 10));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region5(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 10) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 10);
        return *this;
    }
    volatile regioncfg_r &set_region5(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 10) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 10);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region6() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 12));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region6() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 12));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region6(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 12) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 12);
        return *this;
    }
    volatile regioncfg_r &set_region6(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 12) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 12);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::mem_attr get_region7() const
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 14));
        return value;
    }
    NPU_NAMESPACE::mem_attr get_region7() const volatile
    {
        NPU_NAMESPACE::mem_attr value = static_cast<NPU_NAMESPACE::mem_attr>(((1U << 2) - 1) & (word0 >> 14));
        return value;
    }
    CONSTEXPR regioncfg_r &set_region7(NPU_NAMESPACE::mem_attr value)
    {
        word0 = (((~((1U << 2) - 1)) << 14) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 14);
        return *this;
    }
    volatile regioncfg_r &set_region7(NPU_NAMESPACE::mem_attr value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 14) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 14);
        return *this;
    }
#endif
};

// axi_limit0_r - AXI limits for port 0 counter 0
struct axi_limit0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t max_beats : 2; // Burst split alignment
            uint32_t reserved0 : 2;
            uint32_t memtype : 4; // Memtype to be used to encode AxCACHE signals
            uint32_t reserved1 : 8;
            uint32_t
                max_outstanding_read_m1 : 6; // Maximum number of outstanding AXI read transactions - 1 in range 0 to 63
            uint32_t reserved2 : 2;
            uint32_t max_outstanding_write_m1 : 5; // Maximum number of outstanding AXI write transactions - 1 in range
                                                   // 0 to 31
            uint32_t reserved3 : 3;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR axi_limit0_r() : word0(0) {}
    CONSTEXPR axi_limit0_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    axi_limit0_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::max_beats get_max_beats() const
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::max_beats get_max_beats() const volatile
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR axi_limit0_r &set_max_beats(NPU_NAMESPACE::max_beats value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile axi_limit0_r &set_max_beats(NPU_NAMESPACE::max_beats value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::axi_mem_encoding get_memtype() const
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    NPU_NAMESPACE::axi_mem_encoding get_memtype() const volatile
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    CONSTEXPR axi_limit0_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    volatile axi_limit0_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_read_m1() const
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_max_outstanding_read_m1() const volatile
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR axi_limit0_r &set_max_outstanding_read_m1(uint32_t value)
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    volatile axi_limit0_r &set_max_outstanding_read_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_write_m1() const
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    uint32_t get_max_outstanding_write_m1() const volatile
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    CONSTEXPR axi_limit0_r &set_max_outstanding_write_m1(uint32_t value)
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
    volatile axi_limit0_r &set_max_outstanding_write_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
#endif
};

// axi_limit1_r - AXI limits for port 0 counter 1
struct axi_limit1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t max_beats : 2; // Burst split alignment
            uint32_t reserved0 : 2;
            uint32_t memtype : 4; // Memtype to be used to encode AxCACHE signals
            uint32_t reserved1 : 8;
            uint32_t
                max_outstanding_read_m1 : 6; // Maximum number of outstanding AXI read transactions - 1 in range 0 to 63
            uint32_t reserved2 : 2;
            uint32_t max_outstanding_write_m1 : 5; // Maximum number of outstanding AXI write transactions - 1 in range
                                                   // 0 to 31
            uint32_t reserved3 : 3;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR axi_limit1_r() : word0(0) {}
    CONSTEXPR axi_limit1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    axi_limit1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::max_beats get_max_beats() const
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::max_beats get_max_beats() const volatile
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR axi_limit1_r &set_max_beats(NPU_NAMESPACE::max_beats value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile axi_limit1_r &set_max_beats(NPU_NAMESPACE::max_beats value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::axi_mem_encoding get_memtype() const
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    NPU_NAMESPACE::axi_mem_encoding get_memtype() const volatile
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    CONSTEXPR axi_limit1_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    volatile axi_limit1_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_read_m1() const
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_max_outstanding_read_m1() const volatile
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR axi_limit1_r &set_max_outstanding_read_m1(uint32_t value)
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    volatile axi_limit1_r &set_max_outstanding_read_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_write_m1() const
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    uint32_t get_max_outstanding_write_m1() const volatile
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    CONSTEXPR axi_limit1_r &set_max_outstanding_write_m1(uint32_t value)
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
    volatile axi_limit1_r &set_max_outstanding_write_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
#endif
};

// axi_limit2_r - AXI limits for port 1 counter 2
struct axi_limit2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t max_beats : 2; // Burst split alignment
            uint32_t reserved0 : 2;
            uint32_t memtype : 4; // Memtype to be used to encode AxCACHE signals
            uint32_t reserved1 : 8;
            uint32_t
                max_outstanding_read_m1 : 6; // Maximum number of outstanding AXI read transactions - 1 in range 0 to 63
            uint32_t reserved2 : 2;
            uint32_t max_outstanding_write_m1 : 5; // Maximum number of outstanding AXI write transactions - 1 in range
                                                   // 0 to 31
            uint32_t reserved3 : 3;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR axi_limit2_r() : word0(0) {}
    CONSTEXPR axi_limit2_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    axi_limit2_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::max_beats get_max_beats() const
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::max_beats get_max_beats() const volatile
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR axi_limit2_r &set_max_beats(NPU_NAMESPACE::max_beats value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile axi_limit2_r &set_max_beats(NPU_NAMESPACE::max_beats value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::axi_mem_encoding get_memtype() const
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    NPU_NAMESPACE::axi_mem_encoding get_memtype() const volatile
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    CONSTEXPR axi_limit2_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    volatile axi_limit2_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_read_m1() const
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_max_outstanding_read_m1() const volatile
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR axi_limit2_r &set_max_outstanding_read_m1(uint32_t value)
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    volatile axi_limit2_r &set_max_outstanding_read_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_write_m1() const
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    uint32_t get_max_outstanding_write_m1() const volatile
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    CONSTEXPR axi_limit2_r &set_max_outstanding_write_m1(uint32_t value)
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
    volatile axi_limit2_r &set_max_outstanding_write_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
#endif
};

// axi_limit3_r - AXI limits for port 1 counter 3
struct axi_limit3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t max_beats : 2; // Burst split alignment
            uint32_t reserved0 : 2;
            uint32_t memtype : 4; // Memtype to be used to encode AxCACHE signals
            uint32_t reserved1 : 8;
            uint32_t
                max_outstanding_read_m1 : 6; // Maximum number of outstanding AXI read transactions - 1 in range 0 to 63
            uint32_t reserved2 : 2;
            uint32_t max_outstanding_write_m1 : 5; // Maximum number of outstanding AXI write transactions - 1 in range
                                                   // 0 to 31
            uint32_t reserved3 : 3;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR axi_limit3_r() : word0(0) {}
    CONSTEXPR axi_limit3_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    axi_limit3_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::max_beats get_max_beats() const
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::max_beats get_max_beats() const volatile
    {
        NPU_NAMESPACE::max_beats value = static_cast<NPU_NAMESPACE::max_beats>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR axi_limit3_r &set_max_beats(NPU_NAMESPACE::max_beats value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile axi_limit3_r &set_max_beats(NPU_NAMESPACE::max_beats value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::axi_mem_encoding get_memtype() const
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    NPU_NAMESPACE::axi_mem_encoding get_memtype() const volatile
    {
        NPU_NAMESPACE::axi_mem_encoding value =
            static_cast<NPU_NAMESPACE::axi_mem_encoding>(((1U << 4) - 1) & (word0 >> 4));
        return value;
    }
    CONSTEXPR axi_limit3_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value)
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    volatile axi_limit3_r &set_memtype(NPU_NAMESPACE::axi_mem_encoding value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 4) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_read_m1() const
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_max_outstanding_read_m1() const volatile
    {
        uint32_t value = ((1U << 6) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR axi_limit3_r &set_max_outstanding_read_m1(uint32_t value)
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    volatile axi_limit3_r &set_max_outstanding_read_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 6) - 1)) << 16) & word0) | ((((1U << 6) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_max_outstanding_write_m1() const
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    uint32_t get_max_outstanding_write_m1() const volatile
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 24);
        return value;
    }
    CONSTEXPR axi_limit3_r &set_max_outstanding_write_m1(uint32_t value)
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
    volatile axi_limit3_r &set_max_outstanding_write_m1(uint32_t value) volatile
    {
        word0 = (((~((1U << 5) - 1)) << 24) & word0) | ((((1U << 5) - 1) & value) << 24);
        return *this;
    }
#endif
};

// basep_r - The driver can use this address to relocate the command stream on region 0. If the region contains data
// requiring A-byte alignment then the base must be a multiple of A
struct basep_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR basep_r() : word0(0), word1(0) {}
    CONSTEXPR basep_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    basep_r copy() volatile
    {
        return *this;
    }
#endif
};

// wd_status_r - WD_STATUS
struct wd_status_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t core_slice_state : 2; // WD core slice parser state
            uint32_t core_idle : 1;        // Core idle
            uint32_t ctrl_state : 2;       // WD control state
            uint32_t ctrl_idle : 1;        // All stripe jobs idle (all weights consumed)
            uint32_t write_buf_index0 : 3; // current write index for next data from core
            uint32_t write_buf_valid0 : 1; // write buf valid (full)
            uint32_t write_buf_idle0 : 1;  // write buf idle (empty)
            uint32_t write_buf_index1 : 3; // current write index for next data from core
            uint32_t write_buf_valid1 : 1; // write buf valid (full)
            uint32_t write_buf_idle1 : 1;  // write buf idle (empty)
            uint32_t events : 12;          // WD events mapped as appendix A
            uint32_t reserved0 : 4;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR wd_status_r() : word0(0) {}
    CONSTEXPR wd_status_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    wd_status_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::wd_core_slice_state get_core_slice_state() const
    {
        NPU_NAMESPACE::wd_core_slice_state value =
            static_cast<NPU_NAMESPACE::wd_core_slice_state>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::wd_core_slice_state get_core_slice_state() const volatile
    {
        NPU_NAMESPACE::wd_core_slice_state value =
            static_cast<NPU_NAMESPACE::wd_core_slice_state>(((1U << 2) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR wd_status_r &set_core_slice_state(NPU_NAMESPACE::wd_core_slice_state value)
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile wd_status_r &set_core_slice_state(NPU_NAMESPACE::wd_core_slice_state value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 0) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_core_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_core_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR wd_status_r &set_core_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile wd_status_r &set_core_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::wd_ctrl_state get_ctrl_state() const
    {
        NPU_NAMESPACE::wd_ctrl_state value = static_cast<NPU_NAMESPACE::wd_ctrl_state>(((1U << 2) - 1) & (word0 >> 3));
        return value;
    }
    NPU_NAMESPACE::wd_ctrl_state get_ctrl_state() const volatile
    {
        NPU_NAMESPACE::wd_ctrl_state value = static_cast<NPU_NAMESPACE::wd_ctrl_state>(((1U << 2) - 1) & (word0 >> 3));
        return value;
    }
    CONSTEXPR wd_status_r &set_ctrl_state(NPU_NAMESPACE::wd_ctrl_state value)
    {
        word0 = (((~((1U << 2) - 1)) << 3) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 3);
        return *this;
    }
    volatile wd_status_r &set_ctrl_state(NPU_NAMESPACE::wd_ctrl_state value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 3) & word0) | ((((1U << 2) - 1) & static_cast<uint32_t>(value)) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_ctrl_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_ctrl_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR wd_status_r &set_ctrl_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile wd_status_r &set_ctrl_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_index0() const
    {
        uint32_t value = ((1U << 3) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_write_buf_index0() const volatile
    {
        uint32_t value = ((1U << 3) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_index0(uint32_t value)
    {
        word0 = (((~((1U << 3) - 1)) << 6) & word0) | ((((1U << 3) - 1) & value) << 6);
        return *this;
    }
    volatile wd_status_r &set_write_buf_index0(uint32_t value) volatile
    {
        word0 = (((~((1U << 3) - 1)) << 6) & word0) | ((((1U << 3) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_valid0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    uint32_t get_write_buf_valid0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_valid0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    volatile wd_status_r &set_write_buf_valid0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_idle0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    uint32_t get_write_buf_idle0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_idle0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    volatile wd_status_r &set_write_buf_idle0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_index1() const
    {
        uint32_t value = ((1U << 3) - 1) & (word0 >> 11);
        return value;
    }
    uint32_t get_write_buf_index1() const volatile
    {
        uint32_t value = ((1U << 3) - 1) & (word0 >> 11);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_index1(uint32_t value)
    {
        word0 = (((~((1U << 3) - 1)) << 11) & word0) | ((((1U << 3) - 1) & value) << 11);
        return *this;
    }
    volatile wd_status_r &set_write_buf_index1(uint32_t value) volatile
    {
        word0 = (((~((1U << 3) - 1)) << 11) & word0) | ((((1U << 3) - 1) & value) << 11);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_valid1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    uint32_t get_write_buf_valid1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_valid1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    volatile wd_status_r &set_write_buf_valid1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    CONSTEXPR uint32_t get_write_buf_idle1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    uint32_t get_write_buf_idle1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    CONSTEXPR wd_status_r &set_write_buf_idle1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    volatile wd_status_r &set_write_buf_idle1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    CONSTEXPR uint32_t get_events() const
    {
        uint32_t value = ((1U << 12) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_events() const volatile
    {
        uint32_t value = ((1U << 12) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR wd_status_r &set_events(uint32_t value)
    {
        word0 = (((~((1U << 12) - 1)) << 16) & word0) | ((((1U << 12) - 1) & value) << 16);
        return *this;
    }
    volatile wd_status_r &set_events(uint32_t value) volatile
    {
        word0 = (((~((1U << 12) - 1)) << 16) & word0) | ((((1U << 12) - 1) & value) << 16);
        return *this;
    }
#endif
};

// mac_status_r - MAC_STATUS
struct mac_status_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t block_cfg_valid : 1;     // MAC has a valid block configuration
            uint32_t trav_en : 1;             // MAC is doing block traversal
            uint32_t wait_for_ib : 1;         // MAC is waiting for an Input Buffer to become available
            uint32_t wait_for_acc_buf : 1;    // MAC is waiting for an Accumulator Buffer to become available
            uint32_t wait_for_weights : 1;    // MAC is waiting for a Weight Block to become available
            uint32_t stall_stripe : 1;        // MAC is stalling between two stripes
            uint32_t dw_sel : 1;              // Currently used weight interface in MAC AI
            uint32_t wait_for_dw0_ready : 1;  // MAC AI is waiting for MAC DPU to send dw0_ready to WD
            uint32_t wait_for_dw1_ready : 1;  // MAC AI is waiting for MAC DPU to send dw1_ready to WD
            uint32_t acc_buf_sel_ai : 1;      // Currently used AccBuf interface in MAC AI
            uint32_t wait_for_acc0_ready : 1; // MAC AI is waiting for acc0_ready from AO
            uint32_t wait_for_acc1_ready : 1; // MAC AI is waiting for acc1_ready from AO
            uint32_t acc_buf_sel_aa : 1;      // Currently used AccBuf interface in MAC ADDER_ARRAY
            uint32_t acc0_valid : 1;          // MAC outgoing value of acc0_valid
            uint32_t acc1_valid : 1;          // MAC outgoing value of acc1_valid
            uint32_t reserved0 : 1;
            uint32_t events : 11; // Mapped to MAC events described in Appendix A
            uint32_t reserved1 : 5;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR mac_status_r() : word0(0) {}
    CONSTEXPR mac_status_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    mac_status_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_block_cfg_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_block_cfg_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR mac_status_r &set_block_cfg_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile mac_status_r &set_block_cfg_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_trav_en() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_trav_en() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR mac_status_r &set_trav_en(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile mac_status_r &set_trav_en(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_ib() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_wait_for_ib() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_ib(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile mac_status_r &set_wait_for_ib(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_acc_buf() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_wait_for_acc_buf() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_acc_buf(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile mac_status_r &set_wait_for_acc_buf(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_weights() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_wait_for_weights() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_weights(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile mac_status_r &set_wait_for_weights(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_stall_stripe() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_stall_stripe() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR mac_status_r &set_stall_stripe(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile mac_status_r &set_stall_stripe(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_dw_sel() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_dw_sel() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR mac_status_r &set_dw_sel(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    volatile mac_status_r &set_dw_sel(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_dw0_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    uint32_t get_wait_for_dw0_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_dw0_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    volatile mac_status_r &set_wait_for_dw0_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_dw1_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_wait_for_dw1_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_dw1_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    volatile mac_status_r &set_wait_for_dw1_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR uint32_t get_acc_buf_sel_ai() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    uint32_t get_acc_buf_sel_ai() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    CONSTEXPR mac_status_r &set_acc_buf_sel_ai(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    volatile mac_status_r &set_acc_buf_sel_ai(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_acc0_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    uint32_t get_wait_for_acc0_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_acc0_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    volatile mac_status_r &set_wait_for_acc0_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    CONSTEXPR uint32_t get_wait_for_acc1_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    uint32_t get_wait_for_acc1_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    CONSTEXPR mac_status_r &set_wait_for_acc1_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    volatile mac_status_r &set_wait_for_acc1_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    CONSTEXPR uint32_t get_acc_buf_sel_aa() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    uint32_t get_acc_buf_sel_aa() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    CONSTEXPR mac_status_r &set_acc_buf_sel_aa(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    volatile mac_status_r &set_acc_buf_sel_aa(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    CONSTEXPR uint32_t get_acc0_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    uint32_t get_acc0_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    CONSTEXPR mac_status_r &set_acc0_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    volatile mac_status_r &set_acc0_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    CONSTEXPR uint32_t get_acc1_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    uint32_t get_acc1_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    CONSTEXPR mac_status_r &set_acc1_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    volatile mac_status_r &set_acc1_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    CONSTEXPR uint32_t get_events() const
    {
        uint32_t value = ((1U << 11) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_events() const volatile
    {
        uint32_t value = ((1U << 11) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR mac_status_r &set_events(uint32_t value)
    {
        word0 = (((~((1U << 11) - 1)) << 16) & word0) | ((((1U << 11) - 1) & value) << 16);
        return *this;
    }
    volatile mac_status_r &set_events(uint32_t value) volatile
    {
        word0 = (((~((1U << 11) - 1)) << 16) & word0) | ((((1U << 11) - 1) & value) << 16);
        return *this;
    }
#endif
};

// ao_status_r - AO_STATUS
struct ao_status_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t cmd_sbw_valid : 1; // Block command to shared buffer write module is valid
            uint32_t cmd_act_valid : 1; // Block command to activation function module is valid
            uint32_t cmd_ctl_valid : 1; // Block command to control module is valid
            uint32_t cmd_scl_valid : 1; // Block command to scale module is valid
            uint32_t cmd_sbr_valid : 1; // Block command to shared buffer read module is valid
            uint32_t cmd_ofm_valid : 1; // Block command to ofm parameter module is valid
            uint32_t blk_cmd_ready : 1; // Ready to accept block command
            uint32_t blk_cmd_valid : 1; // Block command from CC is valid
            uint32_t reserved0 : 8;
            uint32_t events : 8; // Mapped to AO events described in Appendix A
            uint32_t reserved1 : 8;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ao_status_r() : word0(0) {}
    CONSTEXPR ao_status_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ao_status_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_sbw_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_cmd_sbw_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_sbw_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile ao_status_r &set_cmd_sbw_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_act_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_cmd_act_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_act_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile ao_status_r &set_cmd_act_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_ctl_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_cmd_ctl_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_ctl_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile ao_status_r &set_cmd_ctl_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_scl_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_cmd_scl_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_scl_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile ao_status_r &set_cmd_scl_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_sbr_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_cmd_sbr_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_sbr_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile ao_status_r &set_cmd_sbr_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_ofm_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_cmd_ofm_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR ao_status_r &set_cmd_ofm_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile ao_status_r &set_cmd_ofm_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_blk_cmd_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_blk_cmd_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR ao_status_r &set_blk_cmd_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    volatile ao_status_r &set_blk_cmd_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_blk_cmd_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    uint32_t get_blk_cmd_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    CONSTEXPR ao_status_r &set_blk_cmd_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    volatile ao_status_r &set_blk_cmd_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    CONSTEXPR uint32_t get_events() const
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_events() const volatile
    {
        uint32_t value = ((1U << 8) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR ao_status_r &set_events(uint32_t value)
    {
        word0 = (((~((1U << 8) - 1)) << 16) & word0) | ((((1U << 8) - 1) & value) << 16);
        return *this;
    }
    volatile ao_status_r &set_events(uint32_t value) volatile
    {
        word0 = (((~((1U << 8) - 1)) << 16) & word0) | ((((1U << 8) - 1) & value) << 16);
        return *this;
    }
#endif
};

// dma_status0_r - DMA_STATUS0
struct dma_status0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t cmd_idle : 1; // When this bit is high means that the CMD block is not busy in generating addresses
                                   // for a CMD job
            uint32_t ifm_idle : 1; // When this bit is high means that there are no ongoing IFM jobs
            uint32_t wgt_idle_c0 : 1; // When this bit is high means that the WGT block is not busy in generating
                                      // addresses for a WGT job
            uint32_t bas_idle_c0 : 1; // When this bit is high means that the BAS block is not busy in generating
                                      // addresses for a BAS job
            uint32_t m2m_idle : 1;    // When this bit is high means that there are no ongoing M2M jobs
            uint32_t ofm_idle : 1;    // When this bit is high means that there are no ongoing OFM jobs
            uint32_t halt_req : 1;    // CPM has requested to HALT AXI bus before soft reset
            uint32_t halt_ack : 1;    // DMA is in condition to halt the AXI bus since there are no pending transactions
            uint32_t pause_req : 1;   // CC has requested to pause the AXI
            uint32_t pause_ack : 1; // DMA is in condition to pause the AXI bus since there are no pending transactions
            uint32_t ib0_ai_valid_c0 : 1;       // Data for AI to be read in IFM input buffer 0 - Core 0
            uint32_t ib0_ai_ready_c0 : 1;       // Data consumed from AI in IFM input buffer 0 - Core 0
            uint32_t ib1_ai_valid_c0 : 1;       // Data for AI to be read in IFM input buffer 1 - Core 0
            uint32_t ib1_ai_ready_c0 : 1;       // Data consumed from AI in IFM input buffer 1 - Core 0
            uint32_t ib0_ao_valid_c0 : 1;       // Data for AO to be read in IFM input buffer 0 - Core 0
            uint32_t ib0_ao_ready_c0 : 1;       // Data consumed from AO in IFM input buffer 0 - Core 0
            uint32_t ib1_ao_valid_c0 : 1;       // Data for AO to be read in IFM input buffer 0 - Core 0
            uint32_t ib1_ao_ready_c0 : 1;       // Data consumed from AO in IFM input buffer 1 - Core 0
            uint32_t ob0_valid_c0 : 1;          // Data for DMA ready to be consumed in OFM output buffer 0 -  Core 0
            uint32_t ob0_ready_c0 : 1;          // Data consumed from DMA in OFM output buffer 0 - Core 0
            uint32_t ob1_valid_c0 : 1;          // Data for DMA ready to be consumed in OFM output buffer 1 -  Core 0
            uint32_t ob1_ready_c0 : 1;          // Data consumed from DMA in OFM output buffer 1 - Core 0
            uint32_t cmd_valid : 1;             // New command word for CC to be consumed
            uint32_t cmd_ready : 1;             // command word consumed by CC
            uint32_t wd_bitstream_valid_c0 : 1; // New weight word for WD to be consumed - Core 0
            uint32_t wd_bitstream_ready_c0 : 1; // Weight word consumed by WD - Core 0
            uint32_t bs_bitstream_valid_c0 : 1; // New BaS word for AO to be consumed - Core 0
            uint32_t bs_bitstream_ready_c0 : 1; // BaS word consumed by AO - Core 0
            uint32_t axi0_ar_stalled : 1; // Read transfer request stalled on arready low AXI0 (due to memory system)
            uint32_t axi0_rd_limit_stall : 1; // Read stalled due to one AXI0 limit counter being reached
            uint32_t axi0_aw_stalled : 1; // Write transfer request stalled on awready low AXI0 (due to memory system)
            uint32_t axi0_w_stalled : 1;  // Write transfer stalled on awready low AXI0 (due to memory system)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma_status0_r() : word0(0) {}
    CONSTEXPR dma_status0_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma_status0_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_cmd_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR dma_status0_r &set_cmd_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile dma_status0_r &set_cmd_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_ifm_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_ifm_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ifm_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile dma_status0_r &set_ifm_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_wgt_idle_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_wgt_idle_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR dma_status0_r &set_wgt_idle_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile dma_status0_r &set_wgt_idle_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_bas_idle_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_bas_idle_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR dma_status0_r &set_bas_idle_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile dma_status0_r &set_bas_idle_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_m2m_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_m2m_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR dma_status0_r &set_m2m_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile dma_status0_r &set_m2m_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_ofm_idle() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_ofm_idle() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ofm_idle(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile dma_status0_r &set_ofm_idle(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_halt_req() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_halt_req() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR dma_status0_r &set_halt_req(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    volatile dma_status0_r &set_halt_req(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_halt_ack() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    uint32_t get_halt_ack() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    CONSTEXPR dma_status0_r &set_halt_ack(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    volatile dma_status0_r &set_halt_ack(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    CONSTEXPR uint32_t get_pause_req() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_pause_req() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR dma_status0_r &set_pause_req(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    volatile dma_status0_r &set_pause_req(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR uint32_t get_pause_ack() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    uint32_t get_pause_ack() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    CONSTEXPR dma_status0_r &set_pause_ack(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    volatile dma_status0_r &set_pause_ack(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ai_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    uint32_t get_ib0_ai_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib0_ai_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    volatile dma_status0_r &set_ib0_ai_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ai_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    uint32_t get_ib0_ai_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib0_ai_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    volatile dma_status0_r &set_ib0_ai_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ai_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    uint32_t get_ib1_ai_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib1_ai_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    volatile dma_status0_r &set_ib1_ai_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ai_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    uint32_t get_ib1_ai_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib1_ai_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    volatile dma_status0_r &set_ib1_ai_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ao_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    uint32_t get_ib0_ao_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib0_ao_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    volatile dma_status0_r &set_ib0_ao_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ao_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    uint32_t get_ib0_ao_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib0_ao_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    volatile dma_status0_r &set_ib0_ao_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ao_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_ib1_ao_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib1_ao_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 16) & word0) | ((((1U << 1) - 1) & value) << 16);
        return *this;
    }
    volatile dma_status0_r &set_ib1_ao_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 16) & word0) | ((((1U << 1) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ao_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 17);
        return value;
    }
    uint32_t get_ib1_ao_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 17);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ib1_ao_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 17) & word0) | ((((1U << 1) - 1) & value) << 17);
        return *this;
    }
    volatile dma_status0_r &set_ib1_ao_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 17) & word0) | ((((1U << 1) - 1) & value) << 17);
        return *this;
    }
    CONSTEXPR uint32_t get_ob0_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 18);
        return value;
    }
    uint32_t get_ob0_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 18);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ob0_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 18) & word0) | ((((1U << 1) - 1) & value) << 18);
        return *this;
    }
    volatile dma_status0_r &set_ob0_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 18) & word0) | ((((1U << 1) - 1) & value) << 18);
        return *this;
    }
    CONSTEXPR uint32_t get_ob0_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 19);
        return value;
    }
    uint32_t get_ob0_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 19);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ob0_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 19) & word0) | ((((1U << 1) - 1) & value) << 19);
        return *this;
    }
    volatile dma_status0_r &set_ob0_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 19) & word0) | ((((1U << 1) - 1) & value) << 19);
        return *this;
    }
    CONSTEXPR uint32_t get_ob1_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 20);
        return value;
    }
    uint32_t get_ob1_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 20);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ob1_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 20) & word0) | ((((1U << 1) - 1) & value) << 20);
        return *this;
    }
    volatile dma_status0_r &set_ob1_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 20) & word0) | ((((1U << 1) - 1) & value) << 20);
        return *this;
    }
    CONSTEXPR uint32_t get_ob1_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 21);
        return value;
    }
    uint32_t get_ob1_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 21);
        return value;
    }
    CONSTEXPR dma_status0_r &set_ob1_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 21) & word0) | ((((1U << 1) - 1) & value) << 21);
        return *this;
    }
    volatile dma_status0_r &set_ob1_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 21) & word0) | ((((1U << 1) - 1) & value) << 21);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_valid() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 22);
        return value;
    }
    uint32_t get_cmd_valid() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 22);
        return value;
    }
    CONSTEXPR dma_status0_r &set_cmd_valid(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 22) & word0) | ((((1U << 1) - 1) & value) << 22);
        return *this;
    }
    volatile dma_status0_r &set_cmd_valid(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 22) & word0) | ((((1U << 1) - 1) & value) << 22);
        return *this;
    }
    CONSTEXPR uint32_t get_cmd_ready() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 23);
        return value;
    }
    uint32_t get_cmd_ready() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 23);
        return value;
    }
    CONSTEXPR dma_status0_r &set_cmd_ready(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 23) & word0) | ((((1U << 1) - 1) & value) << 23);
        return *this;
    }
    volatile dma_status0_r &set_cmd_ready(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 23) & word0) | ((((1U << 1) - 1) & value) << 23);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_bitstream_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 24);
        return value;
    }
    uint32_t get_wd_bitstream_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 24);
        return value;
    }
    CONSTEXPR dma_status0_r &set_wd_bitstream_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 24) & word0) | ((((1U << 1) - 1) & value) << 24);
        return *this;
    }
    volatile dma_status0_r &set_wd_bitstream_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 24) & word0) | ((((1U << 1) - 1) & value) << 24);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_bitstream_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 25);
        return value;
    }
    uint32_t get_wd_bitstream_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 25);
        return value;
    }
    CONSTEXPR dma_status0_r &set_wd_bitstream_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 25) & word0) | ((((1U << 1) - 1) & value) << 25);
        return *this;
    }
    volatile dma_status0_r &set_wd_bitstream_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 25) & word0) | ((((1U << 1) - 1) & value) << 25);
        return *this;
    }
    CONSTEXPR uint32_t get_bs_bitstream_valid_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 26);
        return value;
    }
    uint32_t get_bs_bitstream_valid_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 26);
        return value;
    }
    CONSTEXPR dma_status0_r &set_bs_bitstream_valid_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 26) & word0) | ((((1U << 1) - 1) & value) << 26);
        return *this;
    }
    volatile dma_status0_r &set_bs_bitstream_valid_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 26) & word0) | ((((1U << 1) - 1) & value) << 26);
        return *this;
    }
    CONSTEXPR uint32_t get_bs_bitstream_ready_c0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 27);
        return value;
    }
    uint32_t get_bs_bitstream_ready_c0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 27);
        return value;
    }
    CONSTEXPR dma_status0_r &set_bs_bitstream_ready_c0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 27) & word0) | ((((1U << 1) - 1) & value) << 27);
        return *this;
    }
    volatile dma_status0_r &set_bs_bitstream_ready_c0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 27) & word0) | ((((1U << 1) - 1) & value) << 27);
        return *this;
    }
    CONSTEXPR uint32_t get_axi0_ar_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 28);
        return value;
    }
    uint32_t get_axi0_ar_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 28);
        return value;
    }
    CONSTEXPR dma_status0_r &set_axi0_ar_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 28) & word0) | ((((1U << 1) - 1) & value) << 28);
        return *this;
    }
    volatile dma_status0_r &set_axi0_ar_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 28) & word0) | ((((1U << 1) - 1) & value) << 28);
        return *this;
    }
    CONSTEXPR uint32_t get_axi0_rd_limit_stall() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 29);
        return value;
    }
    uint32_t get_axi0_rd_limit_stall() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 29);
        return value;
    }
    CONSTEXPR dma_status0_r &set_axi0_rd_limit_stall(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 29) & word0) | ((((1U << 1) - 1) & value) << 29);
        return *this;
    }
    volatile dma_status0_r &set_axi0_rd_limit_stall(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 29) & word0) | ((((1U << 1) - 1) & value) << 29);
        return *this;
    }
    CONSTEXPR uint32_t get_axi0_aw_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 30);
        return value;
    }
    uint32_t get_axi0_aw_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 30);
        return value;
    }
    CONSTEXPR dma_status0_r &set_axi0_aw_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 30) & word0) | ((((1U << 1) - 1) & value) << 30);
        return *this;
    }
    volatile dma_status0_r &set_axi0_aw_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 30) & word0) | ((((1U << 1) - 1) & value) << 30);
        return *this;
    }
    CONSTEXPR uint32_t get_axi0_w_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_axi0_w_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR dma_status0_r &set_axi0_w_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile dma_status0_r &set_axi0_w_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// dma_status1_r - DMA_STATUS1
struct dma_status1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t axi0_wr_limit_stall : 1; // Write stalled due to one AXI0 limit counter being reached
            uint32_t axi1_ar_stalled : 1; // Read transfer request stalled on arready low AXI1 (due to memory system)
            uint32_t axi1_rd_limit_stall : 1; // Read stalled due to one AXI1 limit counter being reached
            uint32_t axi1_wr_stalled : 1; // Write transfer request stalled on awready low AXI1 (due to memory system)
            uint32_t axi1_w_stalled : 1;  // Write transfer stalled on wready low AXI1 (due to memory system)
            uint32_t axi1_wr_limit_stall : 1; // Write stalled due to one AXI1 limit counter being reached
            uint32_t wgt_idle_c1 : 1;     // When this bit is high means that the WGT block is not busy in generating
                                          // addresses for a WGT job
            uint32_t bas_idle_c1 : 1;     // When this bit is high means that the BAS block is not busy in generating
                                          // addresses for a BAS job
            uint32_t ib0_ai_valid_c1 : 1; // Data for AI to be read in IFM input buffer 0 - Core 1
            uint32_t ib0_ai_ready_c1 : 1; // Data consumed from AI in IFM input buffer 0 - Core 1
            uint32_t ib1_ai_valid_c1 : 1; // Data for AI to be read in IFM input buffer 1 - Core 1
            uint32_t ib1_ai_ready_c1 : 1; // Data consumed from AI in IFM input buffer 1 - Core 1
            uint32_t ib0_ao_valid_c1 : 1; // Data for AO to be read in IFM input buffer 0 - Core 1
            uint32_t ib0_ao_ready_c1 : 1; // Data consumed from AO in IFM input buffer 0 - Core 1
            uint32_t ib1_ao_valid_c1 : 1; // Data for AO to be read in IFM input buffer 0 - Core 1
            uint32_t ib1_ao_ready_c1 : 1; // Data consumed from AO in IFM input buffer 1 - Core 1
            uint32_t ob0_valid_c1 : 1;    // Data for DMA ready to be consumed in OFM output buffer 0 - Core 1
            uint32_t ob0_ready_c1 : 1;    // Data consumed from DMA in OFM output buffer 0 - Core 1
            uint32_t ob1_valid_c1 : 1;    // Data for DMA ready to be consumed in OFM output buffer 1 - Core 1
            uint32_t ob1_ready_c1 : 1;    // Data consumed from DMA in OFM output buffer 1 - Core 1
            uint32_t wd_bitstream_valid_c1 : 1; // New weight word for WD to be consumed - Core 1
            uint32_t wd_bitstream_ready_c1 : 1; // Weight word consumed by WD - Core 1
            uint32_t bs_bitstream_valid_c1 : 1; // New BaS word for AO to be consumed - Core 1
            uint32_t bs_bitstream_ready_c1 : 1; // BaS word consumed by AO - Core 1
            uint32_t reserved0 : 8;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma_status1_r() : word0(0) {}
    CONSTEXPR dma_status1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma_status1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_axi0_wr_limit_stall() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_axi0_wr_limit_stall() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi0_wr_limit_stall(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile dma_status1_r &set_axi0_wr_limit_stall(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_axi1_ar_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_axi1_ar_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi1_ar_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile dma_status1_r &set_axi1_ar_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_axi1_rd_limit_stall() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_axi1_rd_limit_stall() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi1_rd_limit_stall(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile dma_status1_r &set_axi1_rd_limit_stall(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_axi1_wr_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_axi1_wr_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi1_wr_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile dma_status1_r &set_axi1_wr_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_axi1_w_stalled() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_axi1_w_stalled() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi1_w_stalled(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile dma_status1_r &set_axi1_w_stalled(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_axi1_wr_limit_stall() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_axi1_wr_limit_stall() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR dma_status1_r &set_axi1_wr_limit_stall(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile dma_status1_r &set_axi1_wr_limit_stall(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    CONSTEXPR uint32_t get_wgt_idle_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    uint32_t get_wgt_idle_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 6);
        return value;
    }
    CONSTEXPR dma_status1_r &set_wgt_idle_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    volatile dma_status1_r &set_wgt_idle_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 6) & word0) | ((((1U << 1) - 1) & value) << 6);
        return *this;
    }
    CONSTEXPR uint32_t get_bas_idle_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    uint32_t get_bas_idle_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 7);
        return value;
    }
    CONSTEXPR dma_status1_r &set_bas_idle_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    volatile dma_status1_r &set_bas_idle_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 7) & word0) | ((((1U << 1) - 1) & value) << 7);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ai_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_ib0_ai_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib0_ai_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    volatile dma_status1_r &set_ib0_ai_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 8) & word0) | ((((1U << 1) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ai_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    uint32_t get_ib0_ai_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 9);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib0_ai_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    volatile dma_status1_r &set_ib0_ai_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 9) & word0) | ((((1U << 1) - 1) & value) << 9);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ai_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    uint32_t get_ib1_ai_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib1_ai_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    volatile dma_status1_r &set_ib1_ai_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ai_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    uint32_t get_ib1_ai_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 11);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib1_ai_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    volatile dma_status1_r &set_ib1_ai_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 11) & word0) | ((((1U << 1) - 1) & value) << 11);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ao_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    uint32_t get_ib0_ao_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 12);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib0_ao_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    volatile dma_status1_r &set_ib0_ao_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 12) & word0) | ((((1U << 1) - 1) & value) << 12);
        return *this;
    }
    CONSTEXPR uint32_t get_ib0_ao_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    uint32_t get_ib0_ao_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 13);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib0_ao_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    volatile dma_status1_r &set_ib0_ao_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 13) & word0) | ((((1U << 1) - 1) & value) << 13);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ao_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    uint32_t get_ib1_ao_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 14);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib1_ao_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    volatile dma_status1_r &set_ib1_ao_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 14) & word0) | ((((1U << 1) - 1) & value) << 14);
        return *this;
    }
    CONSTEXPR uint32_t get_ib1_ao_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    uint32_t get_ib1_ao_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 15);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ib1_ao_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    volatile dma_status1_r &set_ib1_ao_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 15) & word0) | ((((1U << 1) - 1) & value) << 15);
        return *this;
    }
    CONSTEXPR uint32_t get_ob0_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 16);
        return value;
    }
    uint32_t get_ob0_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 16);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ob0_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 16) & word0) | ((((1U << 1) - 1) & value) << 16);
        return *this;
    }
    volatile dma_status1_r &set_ob0_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 16) & word0) | ((((1U << 1) - 1) & value) << 16);
        return *this;
    }
    CONSTEXPR uint32_t get_ob0_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 17);
        return value;
    }
    uint32_t get_ob0_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 17);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ob0_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 17) & word0) | ((((1U << 1) - 1) & value) << 17);
        return *this;
    }
    volatile dma_status1_r &set_ob0_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 17) & word0) | ((((1U << 1) - 1) & value) << 17);
        return *this;
    }
    CONSTEXPR uint32_t get_ob1_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 18);
        return value;
    }
    uint32_t get_ob1_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 18);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ob1_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 18) & word0) | ((((1U << 1) - 1) & value) << 18);
        return *this;
    }
    volatile dma_status1_r &set_ob1_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 18) & word0) | ((((1U << 1) - 1) & value) << 18);
        return *this;
    }
    CONSTEXPR uint32_t get_ob1_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 19);
        return value;
    }
    uint32_t get_ob1_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 19);
        return value;
    }
    CONSTEXPR dma_status1_r &set_ob1_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 19) & word0) | ((((1U << 1) - 1) & value) << 19);
        return *this;
    }
    volatile dma_status1_r &set_ob1_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 19) & word0) | ((((1U << 1) - 1) & value) << 19);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_bitstream_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 20);
        return value;
    }
    uint32_t get_wd_bitstream_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 20);
        return value;
    }
    CONSTEXPR dma_status1_r &set_wd_bitstream_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 20) & word0) | ((((1U << 1) - 1) & value) << 20);
        return *this;
    }
    volatile dma_status1_r &set_wd_bitstream_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 20) & word0) | ((((1U << 1) - 1) & value) << 20);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_bitstream_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 21);
        return value;
    }
    uint32_t get_wd_bitstream_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 21);
        return value;
    }
    CONSTEXPR dma_status1_r &set_wd_bitstream_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 21) & word0) | ((((1U << 1) - 1) & value) << 21);
        return *this;
    }
    volatile dma_status1_r &set_wd_bitstream_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 21) & word0) | ((((1U << 1) - 1) & value) << 21);
        return *this;
    }
    CONSTEXPR uint32_t get_bs_bitstream_valid_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 22);
        return value;
    }
    uint32_t get_bs_bitstream_valid_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 22);
        return value;
    }
    CONSTEXPR dma_status1_r &set_bs_bitstream_valid_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 22) & word0) | ((((1U << 1) - 1) & value) << 22);
        return *this;
    }
    volatile dma_status1_r &set_bs_bitstream_valid_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 22) & word0) | ((((1U << 1) - 1) & value) << 22);
        return *this;
    }
    CONSTEXPR uint32_t get_bs_bitstream_ready_c1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 23);
        return value;
    }
    uint32_t get_bs_bitstream_ready_c1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 23);
        return value;
    }
    CONSTEXPR dma_status1_r &set_bs_bitstream_ready_c1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 23) & word0) | ((((1U << 1) - 1) & value) << 23);
        return *this;
    }
    volatile dma_status1_r &set_bs_bitstream_ready_c1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 23) & word0) | ((((1U << 1) - 1) & value) << 23);
        return *this;
    }
#endif
};

// clkforce_r - Force clocks on for clock gating
struct clkforce_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t top_level_clk : 1; // set to 1 to force on TOP level clock
            uint32_t cc_clk : 1;        // set to 1 to force on CC clock
            uint32_t dma_clk : 1;       // set to 1 to force on DMA clock
            uint32_t mac_clk : 1;       // set to 1 to force on MAC clock
            uint32_t ao_clk : 1;        // set to 1 to force on AO clock
            uint32_t wd_clk : 1;        // set to 1 to force on WD clock
            uint32_t reserved0 : 26;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR clkforce_r() : word0(0) {}
    CONSTEXPR clkforce_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    clkforce_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_top_level_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_top_level_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR clkforce_r &set_top_level_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile clkforce_r &set_top_level_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_cc_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_cc_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR clkforce_r &set_cc_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile clkforce_r &set_cc_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_dma_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_dma_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR clkforce_r &set_dma_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile clkforce_r &set_dma_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_mac_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_mac_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR clkforce_r &set_mac_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile clkforce_r &set_mac_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_ao_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    uint32_t get_ao_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 4);
        return value;
    }
    CONSTEXPR clkforce_r &set_ao_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    volatile clkforce_r &set_ao_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 4) & word0) | ((((1U << 1) - 1) & value) << 4);
        return *this;
    }
    CONSTEXPR uint32_t get_wd_clk() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    uint32_t get_wd_clk() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 5);
        return value;
    }
    CONSTEXPR clkforce_r &set_wd_clk(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
    volatile clkforce_r &set_wd_clk(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 5) & word0) | ((((1U << 1) - 1) & value) << 5);
        return *this;
    }
#endif
};

// debug_address_r - Set debug address for register reads 0x400-0x7FF. The address must be 1KB aligned
struct debug_address_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t addr : 32; // Register address
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR debug_address_r() : word0(0) {}
    CONSTEXPR debug_address_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    debug_address_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_addr() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_addr() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR debug_address_r &set_addr(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile debug_address_r &set_addr(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// debug_misc_r - 32-bit read/write register for driver debug use. This does not affect NPU function
struct debug_misc_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t misc : 32; // Debug misc
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR debug_misc_r() : word0(0) {}
    CONSTEXPR debug_misc_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    debug_misc_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_misc() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_misc() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR debug_misc_r &set_misc(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile debug_misc_r &set_misc(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// debugcore_r - Select core number for debug registers (0x200-0x2FF) and RAM reads (0x400-0x7FF). Value is 0 or 1
struct debugcore_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t core : 32; // Debug core
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR debugcore_r() : word0(0) {}
    CONSTEXPR debugcore_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    debugcore_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_core() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_core() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR debugcore_r &set_core(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile debugcore_r &set_core(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// debug_block_r - Set from which of four block banks the TSU registers are read. 0 = read from the current bank 256+n =
// force to read from bank n where n is in the range 0 to 3
struct debug_block_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t block : 32; // Debug block
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR debug_block_r() : word0(0) {}
    CONSTEXPR debug_block_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    debug_block_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_block() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_block() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR debug_block_r &set_block(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile debug_block_r &set_block(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pmcr_r - PMU Register control
struct pmcr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t cnt_en : 1;        // Enable counter
            uint32_t event_cnt_rst : 1; // Reset event counter
            uint32_t cycle_cnt_rst : 1; // Reset cycle counter
            uint32_t mask_en : 1;       // PMU can be enabled/disabled by command stream operation NPU_OP_PMU_MASK
            uint32_t reserved0 : 7;
            uint32_t num_event_cnt : 5; // Number of event counters
            uint32_t reserved1 : 16;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmcr_r() : word0(8192) {}
    CONSTEXPR pmcr_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmcr_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_cnt_en() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_cnt_en() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmcr_r &set_cnt_en(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmcr_r &set_cnt_en(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_event_cnt_rst() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_event_cnt_rst() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmcr_r &set_event_cnt_rst(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmcr_r &set_event_cnt_rst(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_cycle_cnt_rst() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_cycle_cnt_rst() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmcr_r &set_cycle_cnt_rst(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmcr_r &set_cycle_cnt_rst(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_mask_en() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_mask_en() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmcr_r &set_mask_en(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmcr_r &set_mask_en(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_num_event_cnt() const
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 11);
        return value;
    }
    uint32_t get_num_event_cnt() const volatile
    {
        uint32_t value = ((1U << 5) - 1) & (word0 >> 11);
        return value;
    }
    CONSTEXPR pmcr_r &set_num_event_cnt(uint32_t value)
    {
        word0 = (((~((1U << 5) - 1)) << 11) & word0) | ((((1U << 5) - 1) & value) << 11);
        return *this;
    }
    volatile pmcr_r &set_num_event_cnt(uint32_t value) volatile
    {
        word0 = (((~((1U << 5) - 1)) << 11) & word0) | ((((1U << 5) - 1) & value) << 11);
        return *this;
    }
#endif
};

// pmcntenset_r - Count enable set register
struct pmcntenset_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0 : 1; // Event counter enable bit for PMEVCNTR0
            uint32_t EVENT_CNT_1 : 1; // Event counter enable bit for PMEVCNTR1
            uint32_t EVENT_CNT_2 : 1; // Event counter enable bit for PMEVCNTR2
            uint32_t EVENT_CNT_3 : 1; // Event counter enable bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT : 1; // PMCCNTR enable bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmcntenset_r() : word0(0) {}
    CONSTEXPR pmcntenset_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmcntenset_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmcntenset_r &set_EVENT_CNT_0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmcntenset_r &set_EVENT_CNT_0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmcntenset_r &set_EVENT_CNT_1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmcntenset_r &set_EVENT_CNT_1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmcntenset_r &set_EVENT_CNT_2(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmcntenset_r &set_EVENT_CNT_2(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmcntenset_r &set_EVENT_CNT_3(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmcntenset_r &set_EVENT_CNT_3(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmcntenset_r &set_CYCLE_CNT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmcntenset_r &set_CYCLE_CNT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmcntenclr_r - Count enable clear register
struct pmcntenclr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0 : 1; // Event counter disable bit for PMEVCNTR0
            uint32_t EVENT_CNT_1 : 1; // Event counter disable bit for PMEVCNTR1
            uint32_t EVENT_CNT_2 : 1; // Event counter disable bit for PMEVCNTR2
            uint32_t EVENT_CNT_3 : 1; // Event counter disable bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT : 1; // PMCCNTR disable bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmcntenclr_r() : word0(0) {}
    CONSTEXPR pmcntenclr_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmcntenclr_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmcntenclr_r &set_EVENT_CNT_0(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmcntenclr_r &set_EVENT_CNT_0(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmcntenclr_r &set_EVENT_CNT_1(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmcntenclr_r &set_EVENT_CNT_1(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmcntenclr_r &set_EVENT_CNT_2(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmcntenclr_r &set_EVENT_CNT_2(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmcntenclr_r &set_EVENT_CNT_3(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmcntenclr_r &set_EVENT_CNT_3(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmcntenclr_r &set_CYCLE_CNT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmcntenclr_r &set_CYCLE_CNT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmovsset_r - Overflow flag status set register
struct pmovsset_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0_OVF : 1; // Event counter overflow set bit for PMEVCNTR0
            uint32_t EVENT_CNT_1_OVF : 1; // Event counter overflow set bit for PMEVCNTR1
            uint32_t EVENT_CNT_2_OVF : 1; // Event counter overflow set bit for PMEVCNTR2
            uint32_t EVENT_CNT_3_OVF : 1; // Event counter overflow set bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT_OVF : 1; // PMCCNTR overflow set bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmovsset_r() : word0(0) {}
    CONSTEXPR pmovsset_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmovsset_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmovsset_r &set_EVENT_CNT_0_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmovsset_r &set_EVENT_CNT_0_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmovsset_r &set_EVENT_CNT_1_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmovsset_r &set_EVENT_CNT_1_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmovsset_r &set_EVENT_CNT_2_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmovsset_r &set_EVENT_CNT_2_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmovsset_r &set_EVENT_CNT_3_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmovsset_r &set_EVENT_CNT_3_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmovsset_r &set_CYCLE_CNT_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmovsset_r &set_CYCLE_CNT_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmovsclr_r - Overflow flag status clear register
struct pmovsclr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0_OVF : 1; // Event counter overflow clear bit for PMEVCNTR0
            uint32_t EVENT_CNT_1_OVF : 1; // Event counter overflow clear bit for PMEVCNTR1
            uint32_t EVENT_CNT_2_OVF : 1; // Event counter overflow clear bit for PMEVCNTR2
            uint32_t EVENT_CNT_3_OVF : 1; // Event counter overflow clear bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT_OVF : 1; // PMCCNTR overflow clear bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmovsclr_r() : word0(0) {}
    CONSTEXPR pmovsclr_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmovsclr_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmovsclr_r &set_EVENT_CNT_0_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmovsclr_r &set_EVENT_CNT_0_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmovsclr_r &set_EVENT_CNT_1_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmovsclr_r &set_EVENT_CNT_1_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmovsclr_r &set_EVENT_CNT_2_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmovsclr_r &set_EVENT_CNT_2_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmovsclr_r &set_EVENT_CNT_3_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmovsclr_r &set_EVENT_CNT_3_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT_OVF() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT_OVF() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmovsclr_r &set_CYCLE_CNT_OVF(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmovsclr_r &set_CYCLE_CNT_OVF(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmintset_r - Interrupt enable set register
struct pmintset_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0_INT : 1; // Event counter overflow interrupt request enable bit for PMEVCNTR0
            uint32_t EVENT_CNT_1_INT : 1; // Event counter overflow interrupt request enable bit for PMEVCNTR1
            uint32_t EVENT_CNT_2_INT : 1; // Event counter overflow interrupt request enable bit for PMEVCNTR2
            uint32_t EVENT_CNT_3_INT : 1; // Event counter overflow interrupt request enable bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT_INT : 1; // PMCCNTR overflow interrupt request enable bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmintset_r() : word0(0) {}
    CONSTEXPR pmintset_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmintset_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmintset_r &set_EVENT_CNT_0_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmintset_r &set_EVENT_CNT_0_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmintset_r &set_EVENT_CNT_1_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmintset_r &set_EVENT_CNT_1_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmintset_r &set_EVENT_CNT_2_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmintset_r &set_EVENT_CNT_2_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmintset_r &set_EVENT_CNT_3_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmintset_r &set_EVENT_CNT_3_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmintset_r &set_CYCLE_CNT_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmintset_r &set_CYCLE_CNT_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmintclr_r - Interrupt enable clear register
struct pmintclr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EVENT_CNT_0_INT : 1; // Event counter overflow interrupt request disable bit for PMEVCNTR0
            uint32_t EVENT_CNT_1_INT : 1; // Event counter overflow interrupt request disable bit for PMEVCNTR1
            uint32_t EVENT_CNT_2_INT : 1; // Event counter overflow interrupt request disable bit for PMEVCNTR2
            uint32_t EVENT_CNT_3_INT : 1; // Event counter overflow interrupt request disable bit for PMEVCNTR3
            uint32_t reserved0 : 27;
            uint32_t CYCLE_CNT_INT : 1; // PMCCNTR overflow interrupt request disable bit
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmintclr_r() : word0(0) {}
    CONSTEXPR pmintclr_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmintclr_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_0_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    uint32_t get_EVENT_CNT_0_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 0);
        return value;
    }
    CONSTEXPR pmintclr_r &set_EVENT_CNT_0_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    volatile pmintclr_r &set_EVENT_CNT_0_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 0) & word0) | ((((1U << 1) - 1) & value) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_1_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    uint32_t get_EVENT_CNT_1_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 1);
        return value;
    }
    CONSTEXPR pmintclr_r &set_EVENT_CNT_1_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    volatile pmintclr_r &set_EVENT_CNT_1_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 1) & word0) | ((((1U << 1) - 1) & value) << 1);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_2_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    uint32_t get_EVENT_CNT_2_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 2);
        return value;
    }
    CONSTEXPR pmintclr_r &set_EVENT_CNT_2_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    volatile pmintclr_r &set_EVENT_CNT_2_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 2) & word0) | ((((1U << 1) - 1) & value) << 2);
        return *this;
    }
    CONSTEXPR uint32_t get_EVENT_CNT_3_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    uint32_t get_EVENT_CNT_3_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 3);
        return value;
    }
    CONSTEXPR pmintclr_r &set_EVENT_CNT_3_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    volatile pmintclr_r &set_EVENT_CNT_3_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 3) & word0) | ((((1U << 1) - 1) & value) << 3);
        return *this;
    }
    CONSTEXPR uint32_t get_CYCLE_CNT_INT() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    uint32_t get_CYCLE_CNT_INT() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 31);
        return value;
    }
    CONSTEXPR pmintclr_r &set_CYCLE_CNT_INT(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
    volatile pmintclr_r &set_CYCLE_CNT_INT(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 31) & word0) | ((((1U << 1) - 1) & value) << 31);
        return *this;
    }
#endif
};

// pmccntr_r - Performance monitor cycle count register
struct pmccntr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CYCLE_CNT_LO : 32; // Cycle count - LSB
            uint32_t CYCLE_CNT_HI : 16; // Cycle count - MSB
            uint32_t reserved0 : 16;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR pmccntr_r() : word0(0), word1(0) {}
    CONSTEXPR pmccntr_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    pmccntr_r copy() volatile
    {
        return *this;
    }
#endif
};

// pmccntr_cfg_r - Set start/stop event on the cycle counter
struct pmccntr_cfg_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CYCLE_CNT_CFG_START : 10; // Cycle counter start event
            uint32_t reserved0 : 6;
            uint32_t CYCLE_CNT_CFG_STOP : 10; // Cycle counter stop event
            uint32_t reserved1 : 6;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmccntr_cfg_r() : word0(0) {}
    CONSTEXPR pmccntr_cfg_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmccntr_cfg_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::pmu_event get_CYCLE_CNT_CFG_START() const
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::pmu_event get_CYCLE_CNT_CFG_START() const volatile
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR pmccntr_cfg_r &set_CYCLE_CNT_CFG_START(NPU_NAMESPACE::pmu_event value)
    {
        word0 = (((~((1U << 10) - 1)) << 0) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile pmccntr_cfg_r &set_CYCLE_CNT_CFG_START(NPU_NAMESPACE::pmu_event value) volatile
    {
        word0 = (((~((1U << 10) - 1)) << 0) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::pmu_event get_CYCLE_CNT_CFG_STOP() const
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 16));
        return value;
    }
    NPU_NAMESPACE::pmu_event get_CYCLE_CNT_CFG_STOP() const volatile
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 16));
        return value;
    }
    CONSTEXPR pmccntr_cfg_r &set_CYCLE_CNT_CFG_STOP(NPU_NAMESPACE::pmu_event value)
    {
        word0 = (((~((1U << 10) - 1)) << 16) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 16);
        return *this;
    }
    volatile pmccntr_cfg_r &set_CYCLE_CNT_CFG_STOP(NPU_NAMESPACE::pmu_event value) volatile
    {
        word0 = (((~((1U << 10) - 1)) << 16) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 16);
        return *this;
    }
#endif
};

// pmcaxi_chan_r - Set which AXI channel to monitor for latency measurements in PMU
struct pmcaxi_chan_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CH_SEL : 4; // Channel select for latency measurements
            uint32_t reserved0 : 4;
            uint32_t AXI_CNT_SEL : 2;  // AXI counter to monitor for latency measurements
            uint32_t BW_CH_SEL_EN : 1; // Bandwidth channel selector
            uint32_t reserved1 : 21;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmcaxi_chan_r() : word0(0) {}
    CONSTEXPR pmcaxi_chan_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmcaxi_chan_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::pmu_axi_channel get_CH_SEL() const
    {
        NPU_NAMESPACE::pmu_axi_channel value =
            static_cast<NPU_NAMESPACE::pmu_axi_channel>(((1U << 4) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::pmu_axi_channel get_CH_SEL() const volatile
    {
        NPU_NAMESPACE::pmu_axi_channel value =
            static_cast<NPU_NAMESPACE::pmu_axi_channel>(((1U << 4) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR pmcaxi_chan_r &set_CH_SEL(NPU_NAMESPACE::pmu_axi_channel value)
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile pmcaxi_chan_r &set_CH_SEL(NPU_NAMESPACE::pmu_axi_channel value) volatile
    {
        word0 = (((~((1U << 4) - 1)) << 0) & word0) | ((((1U << 4) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    CONSTEXPR uint32_t get_AXI_CNT_SEL() const
    {
        uint32_t value = ((1U << 2) - 1) & (word0 >> 8);
        return value;
    }
    uint32_t get_AXI_CNT_SEL() const volatile
    {
        uint32_t value = ((1U << 2) - 1) & (word0 >> 8);
        return value;
    }
    CONSTEXPR pmcaxi_chan_r &set_AXI_CNT_SEL(uint32_t value)
    {
        word0 = (((~((1U << 2) - 1)) << 8) & word0) | ((((1U << 2) - 1) & value) << 8);
        return *this;
    }
    volatile pmcaxi_chan_r &set_AXI_CNT_SEL(uint32_t value) volatile
    {
        word0 = (((~((1U << 2) - 1)) << 8) & word0) | ((((1U << 2) - 1) & value) << 8);
        return *this;
    }
    CONSTEXPR uint32_t get_BW_CH_SEL_EN() const
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    uint32_t get_BW_CH_SEL_EN() const volatile
    {
        uint32_t value = ((1U << 1) - 1) & (word0 >> 10);
        return value;
    }
    CONSTEXPR pmcaxi_chan_r &set_BW_CH_SEL_EN(uint32_t value)
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
    volatile pmcaxi_chan_r &set_BW_CH_SEL_EN(uint32_t value) volatile
    {
        word0 = (((~((1U << 1) - 1)) << 10) & word0) | ((((1U << 1) - 1) & value) << 10);
        return *this;
    }
#endif
};

// kernel_x_r - Kernel X offset of in kernel decomposition
struct kernel_x_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_x_r() : word0(0) {}
    CONSTEXPR kernel_x_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_x_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_x_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_x_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_y_r - Kernel Y offset of in kernel decomposition
struct kernel_y_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_y_r() : word0(0) {}
    CONSTEXPR kernel_y_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_y_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_y_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_y_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_w_m1_r - Kernel (width-1) of current block
struct kernel_w_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_w_m1_r() : word0(0) {}
    CONSTEXPR kernel_w_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_w_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_w_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_w_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_h_m1_r - Kernel (height-1) of current block
struct kernel_h_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_h_m1_r() : word0(0) {}
    CONSTEXPR kernel_h_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_h_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_h_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_h_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_cblk_width_m1_r - OFM current block (width-1)
struct ofm_cblk_width_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_cblk_width_m1_r() : word0(0) {}
    CONSTEXPR ofm_cblk_width_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_cblk_width_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_cblk_width_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_cblk_width_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_cblk_height_m1_r - OFM current block (height-1)
struct ofm_cblk_height_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_cblk_height_m1_r() : word0(0) {}
    CONSTEXPR ofm_cblk_height_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_cblk_height_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_cblk_height_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_cblk_height_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_cblk_depth_m1_r - OFM current block (depth-1)
struct ofm_cblk_depth_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_cblk_depth_m1_r() : word0(0) {}
    CONSTEXPR ofm_cblk_depth_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_cblk_depth_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_cblk_depth_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_cblk_depth_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_cblk_depth_m1_r - IFM current block (depth-1)
struct ifm_cblk_depth_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_cblk_depth_m1_r() : word0(0) {}
    CONSTEXPR ifm_cblk_depth_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_cblk_depth_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_cblk_depth_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_cblk_depth_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_x_r - Block X coordinate in OFM
struct ofm_x_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_x_r() : word0(0) {}
    CONSTEXPR ofm_x_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_x_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_x_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_x_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_y_r - Block Y coordinate in OFM
struct ofm_y_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_y_r() : word0(0) {}
    CONSTEXPR ofm_y_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_y_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_y_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_y_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_z_r - Block Z (channel) coordinate in OFM
struct ofm_z_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_z_r() : word0(0) {}
    CONSTEXPR ofm_z_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_z_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_z_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_z_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_z_r - Block Z (channel) coordinate in IFM
struct ifm_z_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_z_r() : word0(0) {}
    CONSTEXPR ifm_z_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_z_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_z_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_z_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pad_top_r - Block top pad
struct pad_top_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pad_top_r() : word0(0) {}
    CONSTEXPR pad_top_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pad_top_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pad_top_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pad_top_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pad_left_r - Block left pad
struct pad_left_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pad_left_r() : word0(0) {}
    CONSTEXPR pad_left_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pad_left_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pad_left_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pad_left_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_cblk_width_r - IFM current block derived width
struct ifm_cblk_width_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_cblk_width_r() : word0(0) {}
    CONSTEXPR ifm_cblk_width_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_cblk_width_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_cblk_width_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_cblk_width_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_cblk_height_r - IFM current block derived height
struct ifm_cblk_height_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_cblk_height_r() : word0(0) {}
    CONSTEXPR ifm_cblk_height_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_cblk_height_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_cblk_height_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_cblk_height_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma_ifm_src_r - DMA IFM channel source position on AXI
struct dma_ifm_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_ifm_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma_ifm_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_ifm_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma_ifm_dst_r - DMA IFM channel destination position in SHRAM
struct dma_ifm_dst_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma_ifm_dst_r() : word0(0) {}
    CONSTEXPR dma_ifm_dst_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma_ifm_dst_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma_ifm_dst_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma_ifm_dst_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma_ofm_src_r - DMA OFM channel source position in SHRAM
struct dma_ofm_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma_ofm_src_r() : word0(0) {}
    CONSTEXPR dma_ofm_src_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma_ofm_src_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma_ofm_src_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma_ofm_src_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma_ofm_dst_r - DMA OFM channel destination position on AXI
struct dma_ofm_dst_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_ofm_dst_r() : word0(0), word1(0) {}
    CONSTEXPR dma_ofm_dst_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_ofm_dst_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma_weight_src_r - DMA weight channel source position on AXI
struct dma_weight_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_weight_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma_weight_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_weight_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma_cmd_src_r - DMA command channel source position on AXI
struct dma_cmd_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_cmd_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma_cmd_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_cmd_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma_cmd_size_r - DMA command channel number of bytes buffered
struct dma_cmd_size_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma_cmd_size_r() : word0(0) {}
    CONSTEXPR dma_cmd_size_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma_cmd_size_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma_cmd_size_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma_cmd_size_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma_m2m_src_r - DMA memory to memory source position on AXI
struct dma_m2m_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_m2m_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma_m2m_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_m2m_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma_m2m_dst_r - DMA memory to memory destination position on AXI
struct dma_m2m_dst_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_m2m_dst_r() : word0(0), word1(0) {}
    CONSTEXPR dma_m2m_dst_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_m2m_dst_r copy() volatile
    {
        return *this;
    }
#endif
};

// current_qread_r - QREAD position being issued (rather than completed)
struct current_qread_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR current_qread_r() : word0(0) {}
    CONSTEXPR current_qread_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    current_qread_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR current_qread_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile current_qread_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma_scale_src_r - DMA scale and bias channel source position on AXI
struct dma_scale_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t offset_LO : 32; // Offset - LSB
            uint32_t offset_HI : 8;  // Offset - MSB
            uint32_t reserved0 : 24;
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma_scale_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma_scale_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma_scale_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// current_block_r - 0-3. Current block bank being executed by the TSU or last one executed if TSU is stopped
struct current_block_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR current_block_r() : word0(0) {}
    CONSTEXPR current_block_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    current_block_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR current_block_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile current_block_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// current_op_r - Current NPU OP command being executed by the TSU
struct current_op_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR current_op_r() : word0(0) {}
    CONSTEXPR current_op_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    current_op_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR current_op_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile current_op_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// current_cmd_r - Current 32-bit command being parsed by the command stream parser
struct current_cmd_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR current_cmd_r() : word0(0) {}
    CONSTEXPR current_cmd_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    current_cmd_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR current_cmd_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile current_cmd_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pmevcntr_r - Performance monitor event 0 count register
struct pmevcntr_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t count : 32; // Count word
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmevcntr_r() : word0(0) {}
    CONSTEXPR pmevcntr_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmevcntr_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_count() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_count() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pmevcntr_r &set_count(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pmevcntr_r &set_count(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pmevtyper_r - Performance monitor event type register 0
struct pmevtyper_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t EV_TYPE : 10; // Event Type
            uint32_t reserved0 : 22;
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pmevtyper_r() : word0(0) {}
    CONSTEXPR pmevtyper_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pmevtyper_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR NPU_NAMESPACE::pmu_event get_EV_TYPE() const
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 0));
        return value;
    }
    NPU_NAMESPACE::pmu_event get_EV_TYPE() const volatile
    {
        NPU_NAMESPACE::pmu_event value = static_cast<NPU_NAMESPACE::pmu_event>(((1U << 10) - 1) & (word0 >> 0));
        return value;
    }
    CONSTEXPR pmevtyper_r &set_EV_TYPE(NPU_NAMESPACE::pmu_event value)
    {
        word0 = (((~((1U << 10) - 1)) << 0) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
    volatile pmevtyper_r &set_EV_TYPE(NPU_NAMESPACE::pmu_event value) volatile
    {
        word0 = (((~((1U << 10) - 1)) << 0) & word0) | ((((1U << 10) - 1) & static_cast<uint32_t>(value)) << 0);
        return *this;
    }
#endif
};

// shared_buffer_r - Shared buffer debug access. Only valid in STOPPED state
struct shared_buffer_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t mem_word : 32; // Memory word
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR shared_buffer_r() : word0(0) {}
    CONSTEXPR shared_buffer_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    shared_buffer_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_mem_word() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_mem_word() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR shared_buffer_r &set_mem_word(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile shared_buffer_r &set_mem_word(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_pad_top_r - None
struct ifm_pad_top_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_pad_top_r() : word0(0) {}
    CONSTEXPR ifm_pad_top_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_pad_top_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_pad_top_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_pad_top_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_pad_left_r - None
struct ifm_pad_left_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_pad_left_r() : word0(0) {}
    CONSTEXPR ifm_pad_left_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_pad_left_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_pad_left_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_pad_left_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_pad_right_r - None
struct ifm_pad_right_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_pad_right_r() : word0(0) {}
    CONSTEXPR ifm_pad_right_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_pad_right_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_pad_right_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_pad_right_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_pad_bottom_r - None
struct ifm_pad_bottom_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_pad_bottom_r() : word0(0) {}
    CONSTEXPR ifm_pad_bottom_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_pad_bottom_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_pad_bottom_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_pad_bottom_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_depth_m1_r - None
struct ifm_depth_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_depth_m1_r() : word0(0) {}
    CONSTEXPR ifm_depth_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_depth_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_depth_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_depth_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_precision_r - None
struct ifm_precision_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_precision_r() : word0(0) {}
    CONSTEXPR ifm_precision_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_precision_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_precision_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_precision_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_upscale_r - None
struct ifm_upscale_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_upscale_r() : word0(0) {}
    CONSTEXPR ifm_upscale_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_upscale_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_upscale_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_upscale_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_zero_point_r - None
struct ifm_zero_point_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_zero_point_r() : word0(0) {}
    CONSTEXPR ifm_zero_point_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_zero_point_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_zero_point_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_zero_point_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_width0_m1_r - None
struct ifm_width0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_width0_m1_r() : word0(0) {}
    CONSTEXPR ifm_width0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_width0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_width0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_width0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_height0_m1_r - None
struct ifm_height0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_height0_m1_r() : word0(0) {}
    CONSTEXPR ifm_height0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_height0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_height0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_height0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_height1_m1_r - None
struct ifm_height1_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_height1_m1_r() : word0(0) {}
    CONSTEXPR ifm_height1_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_height1_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_height1_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_height1_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_ib_end_r - None
struct ifm_ib_end_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_ib_end_r() : word0(0) {}
    CONSTEXPR ifm_ib_end_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_ib_end_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_ib_end_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_ib_end_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_region_r - None
struct ifm_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm_region_r() : word0(0) {}
    CONSTEXPR ifm_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_width_m1_r - None
struct ofm_width_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_width_m1_r() : word0(0) {}
    CONSTEXPR ofm_width_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_width_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_width_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_width_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_height_m1_r - None
struct ofm_height_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_height_m1_r() : word0(0) {}
    CONSTEXPR ofm_height_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_height_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_height_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_height_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_depth_m1_r - None
struct ofm_depth_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_depth_m1_r() : word0(0) {}
    CONSTEXPR ofm_depth_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_depth_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_depth_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_depth_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_precision_r - None
struct ofm_precision_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_precision_r() : word0(0) {}
    CONSTEXPR ofm_precision_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_precision_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_precision_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_precision_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_blk_width_m1_r - None
struct ofm_blk_width_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_blk_width_m1_r() : word0(0) {}
    CONSTEXPR ofm_blk_width_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_blk_width_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_blk_width_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_blk_width_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_blk_height_m1_r - None
struct ofm_blk_height_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_blk_height_m1_r() : word0(0) {}
    CONSTEXPR ofm_blk_height_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_blk_height_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_blk_height_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_blk_height_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_blk_depth_m1_r - None
struct ofm_blk_depth_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_blk_depth_m1_r() : word0(0) {}
    CONSTEXPR ofm_blk_depth_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_blk_depth_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_blk_depth_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_blk_depth_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_zero_point_r - None
struct ofm_zero_point_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_zero_point_r() : word0(0) {}
    CONSTEXPR ofm_zero_point_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_zero_point_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_zero_point_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_zero_point_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_width0_m1_r - None
struct ofm_width0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_width0_m1_r() : word0(0) {}
    CONSTEXPR ofm_width0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_width0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_width0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_width0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_height0_m1_r - None
struct ofm_height0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_height0_m1_r() : word0(0) {}
    CONSTEXPR ofm_height0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_height0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_height0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_height0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_height1_m1_r - None
struct ofm_height1_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_height1_m1_r() : word0(0) {}
    CONSTEXPR ofm_height1_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_height1_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_height1_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_height1_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_region_r - None
struct ofm_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_region_r() : word0(0) {}
    CONSTEXPR ofm_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_width_m1_r - None
struct kernel_width_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_width_m1_r() : word0(0) {}
    CONSTEXPR kernel_width_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_width_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_width_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_width_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_height_m1_r - None
struct kernel_height_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_height_m1_r() : word0(0) {}
    CONSTEXPR kernel_height_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_height_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_height_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_height_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// kernel_stride_r - None
struct kernel_stride_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR kernel_stride_r() : word0(0) {}
    CONSTEXPR kernel_stride_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    kernel_stride_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR kernel_stride_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile kernel_stride_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// parallel_mode_r - None
struct parallel_mode_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR parallel_mode_r() : word0(0) {}
    CONSTEXPR parallel_mode_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    parallel_mode_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR parallel_mode_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile parallel_mode_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// acc_format_r - None
struct acc_format_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR acc_format_r() : word0(0) {}
    CONSTEXPR acc_format_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    acc_format_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR acc_format_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile acc_format_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// activation_r - None
struct activation_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR activation_r() : word0(0) {}
    CONSTEXPR activation_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    activation_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR activation_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile activation_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// activation_min_r - None
struct activation_min_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR activation_min_r() : word0(0) {}
    CONSTEXPR activation_min_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    activation_min_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR activation_min_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile activation_min_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// activation_max_r - None
struct activation_max_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR activation_max_r() : word0(0) {}
    CONSTEXPR activation_max_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    activation_max_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR activation_max_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile activation_max_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// weight_region_r - None
struct weight_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR weight_region_r() : word0(0) {}
    CONSTEXPR weight_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    weight_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR weight_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile weight_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// scale_region_r - None
struct scale_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR scale_region_r() : word0(0) {}
    CONSTEXPR scale_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    scale_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR scale_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile scale_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ab_start_r - None
struct ab_start_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ab_start_r() : word0(0) {}
    CONSTEXPR ab_start_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ab_start_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ab_start_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ab_start_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// blockdep_r - None
struct blockdep_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR blockdep_r() : word0(0) {}
    CONSTEXPR blockdep_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    blockdep_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR blockdep_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile blockdep_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma0_src_region_r - None
struct dma0_src_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma0_src_region_r() : word0(0) {}
    CONSTEXPR dma0_src_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma0_src_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma0_src_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma0_src_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma0_dst_region_r - None
struct dma0_dst_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma0_dst_region_r() : word0(0) {}
    CONSTEXPR dma0_dst_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma0_dst_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma0_dst_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma0_dst_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma0_size0_r - None
struct dma0_size0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma0_size0_r() : word0(0) {}
    CONSTEXPR dma0_size0_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma0_size0_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma0_size0_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma0_size0_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma0_size1_r - None
struct dma0_size1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR dma0_size1_r() : word0(0) {}
    CONSTEXPR dma0_size1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    dma0_size1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR dma0_size1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile dma0_size1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_broadcast_r - None
struct ifm2_broadcast_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_broadcast_r() : word0(0) {}
    CONSTEXPR ifm2_broadcast_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_broadcast_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_broadcast_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_broadcast_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_scalar_r - None
struct ifm2_scalar_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_scalar_r() : word0(0) {}
    CONSTEXPR ifm2_scalar_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_scalar_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_scalar_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_scalar_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_precision_r - None
struct ifm2_precision_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_precision_r() : word0(0) {}
    CONSTEXPR ifm2_precision_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_precision_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_precision_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_precision_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_zero_point_r - None
struct ifm2_zero_point_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_zero_point_r() : word0(0) {}
    CONSTEXPR ifm2_zero_point_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_zero_point_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_zero_point_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_zero_point_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_width0_m1_r - None
struct ifm2_width0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_width0_m1_r() : word0(0) {}
    CONSTEXPR ifm2_width0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_width0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_width0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_width0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_height0_m1_r - None
struct ifm2_height0_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_height0_m1_r() : word0(0) {}
    CONSTEXPR ifm2_height0_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_height0_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_height0_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_height0_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_height1_m1_r - None
struct ifm2_height1_m1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_height1_m1_r() : word0(0) {}
    CONSTEXPR ifm2_height1_m1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_height1_m1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_height1_m1_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_height1_m1_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_ib_start_r - None
struct ifm2_ib_start_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_ib_start_r() : word0(0) {}
    CONSTEXPR ifm2_ib_start_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_ib_start_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_ib_start_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_ib_start_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm2_region_r - None
struct ifm2_region_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ifm2_region_r() : word0(0) {}
    CONSTEXPR ifm2_region_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ifm2_region_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ifm2_region_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ifm2_region_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ifm_base0_r - None
struct ifm_base0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_base0_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_base0_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_base0_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_base1_r - None
struct ifm_base1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_base1_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_base1_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_base1_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_base2_r - None
struct ifm_base2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_base2_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_base2_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_base2_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_base3_r - None
struct ifm_base3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_base3_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_base3_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_base3_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_stride_x_r - None
struct ifm_stride_x_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_stride_x_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_stride_x_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_stride_x_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_stride_y_r - None
struct ifm_stride_y_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_stride_y_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_stride_y_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_stride_y_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm_stride_c_r - None
struct ifm_stride_c_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm_stride_c_r() : word0(0), word1(0) {}
    CONSTEXPR ifm_stride_c_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm_stride_c_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_base0_r - None
struct ofm_base0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_base0_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_base0_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_base0_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_base1_r - None
struct ofm_base1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_base1_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_base1_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_base1_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_base2_r - None
struct ofm_base2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_base2_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_base2_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_base2_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_base3_r - None
struct ofm_base3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_base3_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_base3_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_base3_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_stride_x_r - None
struct ofm_stride_x_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_stride_x_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_stride_x_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_stride_x_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_stride_y_r - None
struct ofm_stride_y_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_stride_y_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_stride_y_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_stride_y_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_stride_c_r - None
struct ofm_stride_c_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ofm_stride_c_r() : word0(0), word1(0) {}
    CONSTEXPR ofm_stride_c_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ofm_stride_c_r copy() volatile
    {
        return *this;
    }
#endif
};

// weight_base_r - None
struct weight_base_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR weight_base_r() : word0(0), word1(0) {}
    CONSTEXPR weight_base_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    weight_base_r copy() volatile
    {
        return *this;
    }
#endif
};

// weight_length_r - None
struct weight_length_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR weight_length_r() : word0(0), word1(0) {}
    CONSTEXPR weight_length_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    weight_length_r copy() volatile
    {
        return *this;
    }
#endif
};

// scale_base_r - None
struct scale_base_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR scale_base_r() : word0(0), word1(0) {}
    CONSTEXPR scale_base_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    scale_base_r copy() volatile
    {
        return *this;
    }
#endif
};

// scale_length_r - None
struct scale_length_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR scale_length_r() : word0(0), word1(0) {}
    CONSTEXPR scale_length_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    scale_length_r copy() volatile
    {
        return *this;
    }
#endif
};

// ofm_scale_r - None
struct ofm_scale_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_scale_r() : word0(0) {}
    CONSTEXPR ofm_scale_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_scale_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_scale_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_scale_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// ofm_scale_shift_r - None
struct ofm_scale_shift_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR ofm_scale_shift_r() : word0(0) {}
    CONSTEXPR ofm_scale_shift_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    ofm_scale_shift_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR ofm_scale_shift_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile ofm_scale_shift_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// opa_scale_r - None
struct opa_scale_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR opa_scale_r() : word0(0) {}
    CONSTEXPR opa_scale_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    opa_scale_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR opa_scale_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile opa_scale_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// opa_scale_shift_r - None
struct opa_scale_shift_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR opa_scale_shift_r() : word0(0) {}
    CONSTEXPR opa_scale_shift_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    opa_scale_shift_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR opa_scale_shift_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile opa_scale_shift_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// opb_scale_r - None
struct opb_scale_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR opb_scale_r() : word0(0) {}
    CONSTEXPR opb_scale_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    opb_scale_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR opb_scale_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile opb_scale_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// dma0_src_r - None
struct dma0_src_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma0_src_r() : word0(0), word1(0) {}
    CONSTEXPR dma0_src_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma0_src_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma0_dst_r - None
struct dma0_dst_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma0_dst_r() : word0(0), word1(0) {}
    CONSTEXPR dma0_dst_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma0_dst_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma0_len_r - None
struct dma0_len_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma0_len_r() : word0(0), word1(0) {}
    CONSTEXPR dma0_len_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma0_len_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma0_skip0_r - None
struct dma0_skip0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma0_skip0_r() : word0(0), word1(0) {}
    CONSTEXPR dma0_skip0_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma0_skip0_r copy() volatile
    {
        return *this;
    }
#endif
};

// dma0_skip1_r - None
struct dma0_skip1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR dma0_skip1_r() : word0(0), word1(0) {}
    CONSTEXPR dma0_skip1_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    dma0_skip1_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_base0_r - None
struct ifm2_base0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_base0_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_base0_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_base0_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_base1_r - None
struct ifm2_base1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_base1_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_base1_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_base1_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_base2_r - None
struct ifm2_base2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_base2_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_base2_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_base2_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_base3_r - None
struct ifm2_base3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_base3_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_base3_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_base3_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_stride_x_r - None
struct ifm2_stride_x_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_stride_x_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_stride_x_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_stride_x_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_stride_y_r - None
struct ifm2_stride_y_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_stride_y_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_stride_y_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_stride_y_r copy() volatile
    {
        return *this;
    }
#endif
};

// ifm2_stride_c_r - None
struct ifm2_stride_c_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR ifm2_stride_c_r() : word0(0), word1(0) {}
    CONSTEXPR ifm2_stride_c_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    ifm2_stride_c_r copy() volatile
    {
        return *this;
    }
#endif
};

// weight1_base_r - None
struct weight1_base_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR weight1_base_r() : word0(0), word1(0) {}
    CONSTEXPR weight1_base_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    weight1_base_r copy() volatile
    {
        return *this;
    }
#endif
};

// weight1_length_r - None
struct weight1_length_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR weight1_length_r() : word0(0), word1(0) {}
    CONSTEXPR weight1_length_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    weight1_length_r copy() volatile
    {
        return *this;
    }
#endif
};

// scale1_base_r - None
struct scale1_base_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR scale1_base_r() : word0(0), word1(0) {}
    CONSTEXPR scale1_base_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    scale1_base_r copy() volatile
    {
        return *this;
    }
#endif
};

// scale1_length_r - None
struct scale1_length_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value_LO : 32; // 64-bit register value - LSB
            uint32_t value_HI : 32; // 64-bit register value - MSB
        };
        uint32_t word[2];
    };
#else
  private:
    uint32_t word0;
    uint32_t word1;

  public:
    CONSTEXPR scale1_length_r() : word0(0), word1(0) {}
    CONSTEXPR scale1_length_r(uint64_t init) :
        word0(static_cast<uint32_t>((init)&std::numeric_limits<uint64_t>::max())),
        word1(static_cast<uint32_t>((init >> 32) & std::numeric_limits<uint64_t>::max()))
    {
    }
    CONSTEXPR void operator=(uint64_t value)
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    void operator=(uint64_t value) volatile
    {
        word0 = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
        word1 = static_cast<uint32_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
    }
    CONSTEXPR operator uint64_t()
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    operator uint64_t() volatile
    {
        return (static_cast<uint64_t>(word1) << 32) | word0;
    }
    scale1_length_r copy() volatile
    {
        return *this;
    }
#endif
};

// revision_r - Internal FPGA build revision: first 32-bits of the Ultan Git hash used for the build
struct revision_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t value : 32; // 32-bit register value
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR revision_r() : word0(0) {}
    CONSTEXPR revision_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    revision_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_value() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_value() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR revision_r &set_value(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile revision_r &set_value(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid4_r - Peripheral ID byte 4 (Arm=code 4)
struct pid4_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID4 : 32; // Byte 4 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid4_r() : word0(4) {}
    CONSTEXPR pid4_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid4_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID4() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID4() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid4_r &set_PID4(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid4_r &set_PID4(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid5_r - Peripheral ID byte 5 (reserved)
struct pid5_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID5 : 32; // Byte 5 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid5_r() : word0(0) {}
    CONSTEXPR pid5_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid5_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID5() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID5() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid5_r &set_PID5(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid5_r &set_PID5(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid6_r - Peripheral ID byte 6 (reserved)
struct pid6_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID6 : 32; // Byte 6 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid6_r() : word0(0) {}
    CONSTEXPR pid6_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid6_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID6() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID6() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid6_r &set_PID6(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid6_r &set_PID6(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid7_r - Peripheral ID byte 7 (reserved)
struct pid7_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID7 : 32; // Byte 7 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid7_r() : word0(0) {}
    CONSTEXPR pid7_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid7_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID7() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID7() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid7_r &set_PID7(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid7_r &set_PID7(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid0_r - Peripheral ID byte 0. This is bits[7:0] of the part number
struct pid0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID0 : 32; // Byte 0 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid0_r() : word0(129) {}
    CONSTEXPR pid0_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid0_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID0() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID0() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid0_r &set_PID0(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid0_r &set_PID0(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid1_r - Peripheral ID byte 1. This is bits[11:8] of the part number in bits[3:0], and bits[3:0] of the Arm ID in
// bits[7:4]
struct pid1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID1 : 32; // Byte 1 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid1_r() : word0(181) {}
    CONSTEXPR pid1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID1() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID1() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid1_r &set_PID1(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid1_r &set_PID1(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid2_r - Peripheral ID byte 2. This is bits[6:4] of the Arm ID in bits[2:0], and bit 3 indicates format B
struct pid2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID2 : 32; // Byte 2 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid2_r() : word0(11) {}
    CONSTEXPR pid2_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid2_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID2() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID2() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid2_r &set_PID2(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid2_r &set_PID2(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// pid3_r - Peripheral ID byte 3
struct pid3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t PID3 : 32; // Byte 1 of Peripheral ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR pid3_r() : word0(0) {}
    CONSTEXPR pid3_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    pid3_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_PID3() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_PID3() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR pid3_r &set_PID3(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile pid3_r &set_PID3(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// cid0_r - Component ID byte 0
struct cid0_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CID0 : 32; // Byte 0 of Component ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR cid0_r() : word0(13) {}
    CONSTEXPR cid0_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    cid0_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_CID0() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_CID0() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR cid0_r &set_CID0(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile cid0_r &set_CID0(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// cid1_r - Component ID byte 1
struct cid1_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CID1 : 32; // Byte 1 of Component ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR cid1_r() : word0(240) {}
    CONSTEXPR cid1_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    cid1_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_CID1() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_CID1() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR cid1_r &set_CID1(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile cid1_r &set_CID1(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// cid2_r - Component ID byte 2
struct cid2_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CID2 : 32; // Byte 2 of Component ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR cid2_r() : word0(5) {}
    CONSTEXPR cid2_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    cid2_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_CID2() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_CID2() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR cid2_r &set_CID2(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile cid2_r &set_CID2(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

// cid3_r - Component ID byte 3
struct cid3_r
{
#ifndef __cplusplus
    union
    {
        struct
        {
            uint32_t CID3 : 32; // Byte 3 of Component ID (Lower 8 bits valid)
        };
        uint32_t word;
    };
#else
  private:
    uint32_t word0;

  public:
    CONSTEXPR cid3_r() : word0(177) {}
    CONSTEXPR cid3_r(uint32_t init) : word0(init) {}
    CONSTEXPR void operator=(uint32_t value)
    {
        word0 = value;
    }
    void operator=(uint32_t value) volatile
    {
        word0 = value;
    }
    CONSTEXPR operator uint32_t()
    {
        return word0;
    }
    operator uint32_t() volatile
    {
        return word0;
    }
    cid3_r copy() volatile
    {
        return *this;
    }
    CONSTEXPR uint32_t get_CID3() const
    {
        uint32_t value = word0;
        return value;
    }
    uint32_t get_CID3() const volatile
    {
        uint32_t value = word0;
        return value;
    }
    CONSTEXPR cid3_r &set_CID3(uint32_t value)
    {
        word0 = value;
        return *this;
    }
    volatile cid3_r &set_CID3(uint32_t value) volatile
    {
        word0 = value;
        return *this;
    }
#endif
};

struct NPU_REG
{
    STRUCT id_r ID;           // 0x0000
    STRUCT status_r STATUS;   // 0x0004
    STRUCT cmd_r CMD;         // 0x0008
    STRUCT reset_r RESET;     // 0x000C
    STRUCT qbase_r QBASE;     // 0x0010
    STRUCT qread_r QREAD;     // 0x0018
    STRUCT qconfig_r QCONFIG; // 0x001C
    STRUCT qsize_r QSIZE;     // 0x0020
    STRUCT prot_r PROT;       // 0x0024
    STRUCT config_r CONFIG;   // 0x0028
    STRUCT lock_r LOCK;       // 0x002C
    uint32_t unused0[3];
    STRUCT regioncfg_r REGIONCFG;   // 0x003C
    STRUCT axi_limit0_r AXI_LIMIT0; // 0x0040
    STRUCT axi_limit1_r AXI_LIMIT1; // 0x0044
    STRUCT axi_limit2_r AXI_LIMIT2; // 0x0048
    STRUCT axi_limit3_r AXI_LIMIT3; // 0x004C
    uint32_t unused1[12];
    STRUCT basep_r BASEP[8]; // 0x0080
    uint32_t unused2[16];
    STRUCT wd_status_r WD_STATUS;   // 0x0100
    STRUCT mac_status_r MAC_STATUS; // 0x0104
    STRUCT ao_status_r AO_STATUS;   // 0x0108
    uint32_t unused3[1];
    STRUCT dma_status0_r DMA_STATUS0; // 0x0110
    STRUCT dma_status1_r DMA_STATUS1; // 0x0114
    uint32_t unused4[10];
    STRUCT clkforce_r CLKFORCE;           // 0x0140
    STRUCT debug_address_r DEBUG_ADDRESS; // 0x0144
    STRUCT debug_misc_r DEBUG_MISC;       // 0x0148
    STRUCT debugcore_r DEBUGCORE;         // 0x014C
    STRUCT debug_block_r DEBUG_BLOCK;     // 0x0150
    uint32_t unused5[11];
    STRUCT pmcr_r PMCR;             // 0x0180
    STRUCT pmcntenset_r PMCNTENSET; // 0x0184
    STRUCT pmcntenclr_r PMCNTENCLR; // 0x0188
    STRUCT pmovsset_r PMOVSSET;     // 0x018C
    STRUCT pmovsclr_r PMOVSCLR;     // 0x0190
    STRUCT pmintset_r PMINTSET;     // 0x0194
    STRUCT pmintclr_r PMINTCLR;     // 0x0198
    uint32_t unused6[1];
    STRUCT pmccntr_r PMCCNTR;         // 0x01A0
    STRUCT pmccntr_cfg_r PMCCNTR_CFG; // 0x01A8
    STRUCT pmcaxi_chan_r PMCAXI_CHAN; // 0x01AC
    uint32_t unused7[20];
    STRUCT kernel_x_r KERNEL_X;                     // 0x0200
    STRUCT kernel_y_r KERNEL_Y;                     // 0x0204
    STRUCT kernel_w_m1_r KERNEL_W_M1;               // 0x0208
    STRUCT kernel_h_m1_r KERNEL_H_M1;               // 0x020C
    STRUCT ofm_cblk_width_m1_r OFM_CBLK_WIDTH_M1;   // 0x0210
    STRUCT ofm_cblk_height_m1_r OFM_CBLK_HEIGHT_M1; // 0x0214
    STRUCT ofm_cblk_depth_m1_r OFM_CBLK_DEPTH_M1;   // 0x0218
    STRUCT ifm_cblk_depth_m1_r IFM_CBLK_DEPTH_M1;   // 0x021C
    STRUCT ofm_x_r OFM_X;                           // 0x0220
    STRUCT ofm_y_r OFM_Y;                           // 0x0224
    STRUCT ofm_z_r OFM_Z;                           // 0x0228
    STRUCT ifm_z_r IFM_Z;                           // 0x022C
    STRUCT pad_top_r PAD_TOP;                       // 0x0230
    STRUCT pad_left_r PAD_LEFT;                     // 0x0234
    STRUCT ifm_cblk_width_r IFM_CBLK_WIDTH;         // 0x0238
    STRUCT ifm_cblk_height_r IFM_CBLK_HEIGHT;       // 0x023C
    STRUCT dma_ifm_src_r DMA_IFM_SRC;               // 0x0240
    STRUCT dma_ifm_dst_r DMA_IFM_DST;               // 0x0248
    STRUCT dma_ofm_src_r DMA_OFM_SRC;               // 0x024C
    STRUCT dma_ofm_dst_r DMA_OFM_DST;               // 0x0250
    STRUCT dma_weight_src_r DMA_WEIGHT_SRC;         // 0x0258
    STRUCT dma_cmd_src_r DMA_CMD_SRC;               // 0x0260
    STRUCT dma_cmd_size_r DMA_CMD_SIZE;             // 0x0268
    STRUCT dma_m2m_src_r DMA_M2M_SRC;               // 0x026C
    STRUCT dma_m2m_dst_r DMA_M2M_DST;               // 0x0274
    STRUCT current_qread_r CURRENT_QREAD;           // 0x027C
    STRUCT dma_scale_src_r DMA_SCALE_SRC;           // 0x0280
    uint32_t unused8[11];
    STRUCT current_block_r CURRENT_BLOCK; // 0x02B4
    STRUCT current_op_r CURRENT_OP;       // 0x02B8
    STRUCT current_cmd_r CURRENT_CMD;     // 0x02BC
    uint32_t unused9[16];
    STRUCT pmevcntr_r PMEVCNTR[4]; // 0x0300
    uint32_t unused10[28];
    STRUCT pmevtyper_r PMEVTYPER[4]; // 0x0380
    uint32_t unused11[28];
    STRUCT shared_buffer_r SHARED_BUFFER[256]; // 0x0400
    STRUCT ifm_pad_top_r IFM_PAD_TOP;          // 0x0800
    STRUCT ifm_pad_left_r IFM_PAD_LEFT;        // 0x0804
    STRUCT ifm_pad_right_r IFM_PAD_RIGHT;      // 0x0808
    STRUCT ifm_pad_bottom_r IFM_PAD_BOTTOM;    // 0x080C
    STRUCT ifm_depth_m1_r IFM_DEPTH_M1;        // 0x0810
    STRUCT ifm_precision_r IFM_PRECISION;      // 0x0814
    uint32_t unused12[1];
    STRUCT ifm_upscale_r IFM_UPSCALE; // 0x081C
    uint32_t unused13[1];
    STRUCT ifm_zero_point_r IFM_ZERO_POINT; // 0x0824
    STRUCT ifm_width0_m1_r IFM_WIDTH0_M1;   // 0x0828
    STRUCT ifm_height0_m1_r IFM_HEIGHT0_M1; // 0x082C
    STRUCT ifm_height1_m1_r IFM_HEIGHT1_M1; // 0x0830
    STRUCT ifm_ib_end_r IFM_IB_END;         // 0x0834
    uint32_t unused14[1];
    STRUCT ifm_region_r IFM_REGION; // 0x083C
    uint32_t unused15[1];
    STRUCT ofm_width_m1_r OFM_WIDTH_M1;           // 0x0844
    STRUCT ofm_height_m1_r OFM_HEIGHT_M1;         // 0x0848
    STRUCT ofm_depth_m1_r OFM_DEPTH_M1;           // 0x084C
    STRUCT ofm_precision_r OFM_PRECISION;         // 0x0850
    STRUCT ofm_blk_width_m1_r OFM_BLK_WIDTH_M1;   // 0x0854
    STRUCT ofm_blk_height_m1_r OFM_BLK_HEIGHT_M1; // 0x0858
    STRUCT ofm_blk_depth_m1_r OFM_BLK_DEPTH_M1;   // 0x085C
    STRUCT ofm_zero_point_r OFM_ZERO_POINT;       // 0x0860
    uint32_t unused16[1];
    STRUCT ofm_width0_m1_r OFM_WIDTH0_M1;   // 0x0868
    STRUCT ofm_height0_m1_r OFM_HEIGHT0_M1; // 0x086C
    STRUCT ofm_height1_m1_r OFM_HEIGHT1_M1; // 0x0870
    uint32_t unused17[2];
    STRUCT ofm_region_r OFM_REGION;             // 0x087C
    STRUCT kernel_width_m1_r KERNEL_WIDTH_M1;   // 0x0880
    STRUCT kernel_height_m1_r KERNEL_HEIGHT_M1; // 0x0884
    STRUCT kernel_stride_r KERNEL_STRIDE;       // 0x0888
    STRUCT parallel_mode_r PARALLEL_MODE;       // 0x088C
    STRUCT acc_format_r ACC_FORMAT;             // 0x0890
    STRUCT activation_r ACTIVATION;             // 0x0894
    STRUCT activation_min_r ACTIVATION_MIN;     // 0x0898
    STRUCT activation_max_r ACTIVATION_MAX;     // 0x089C
    STRUCT weight_region_r WEIGHT_REGION;       // 0x08A0
    STRUCT scale_region_r SCALE_REGION;         // 0x08A4
    uint32_t unused18[3];
    STRUCT ab_start_r AB_START; // 0x08B4
    uint32_t unused19[1];
    STRUCT blockdep_r BLOCKDEP;               // 0x08BC
    STRUCT dma0_src_region_r DMA0_SRC_REGION; // 0x08C0
    STRUCT dma0_dst_region_r DMA0_DST_REGION; // 0x08C4
    STRUCT dma0_size0_r DMA0_SIZE0;           // 0x08C8
    STRUCT dma0_size1_r DMA0_SIZE1;           // 0x08CC
    uint32_t unused20[12];
    STRUCT ifm2_broadcast_r IFM2_BROADCAST; // 0x0900
    STRUCT ifm2_scalar_r IFM2_SCALAR;       // 0x0904
    uint32_t unused21[3];
    STRUCT ifm2_precision_r IFM2_PRECISION; // 0x0914
    uint32_t unused22[3];
    STRUCT ifm2_zero_point_r IFM2_ZERO_POINT; // 0x0924
    STRUCT ifm2_width0_m1_r IFM2_WIDTH0_M1;   // 0x0928
    STRUCT ifm2_height0_m1_r IFM2_HEIGHT0_M1; // 0x092C
    STRUCT ifm2_height1_m1_r IFM2_HEIGHT1_M1; // 0x0930
    STRUCT ifm2_ib_start_r IFM2_IB_START;     // 0x0934
    uint32_t unused23[1];
    STRUCT ifm2_region_r IFM2_REGION; // 0x093C
    uint32_t unused24[48];
    STRUCT ifm_base0_r IFM_BASE0;       // 0x0A00
    STRUCT ifm_base1_r IFM_BASE1;       // 0x0A08
    STRUCT ifm_base2_r IFM_BASE2;       // 0x0A10
    STRUCT ifm_base3_r IFM_BASE3;       // 0x0A18
    STRUCT ifm_stride_x_r IFM_STRIDE_X; // 0x0A20
    STRUCT ifm_stride_y_r IFM_STRIDE_Y; // 0x0A28
    STRUCT ifm_stride_c_r IFM_STRIDE_C; // 0x0A30
    uint32_t unused25[2];
    STRUCT ofm_base0_r OFM_BASE0;       // 0x0A40
    STRUCT ofm_base1_r OFM_BASE1;       // 0x0A48
    STRUCT ofm_base2_r OFM_BASE2;       // 0x0A50
    STRUCT ofm_base3_r OFM_BASE3;       // 0x0A58
    STRUCT ofm_stride_x_r OFM_STRIDE_X; // 0x0A60
    STRUCT ofm_stride_y_r OFM_STRIDE_Y; // 0x0A68
    STRUCT ofm_stride_c_r OFM_STRIDE_C; // 0x0A70
    uint32_t unused26[2];
    STRUCT weight_base_r WEIGHT_BASE;         // 0x0A80
    STRUCT weight_length_r WEIGHT_LENGTH;     // 0x0A88
    STRUCT scale_base_r SCALE_BASE;           // 0x0A90
    STRUCT scale_length_r SCALE_LENGTH;       // 0x0A98
    STRUCT ofm_scale_r OFM_SCALE;             // 0x0AA0
    STRUCT ofm_scale_shift_r OFM_SCALE_SHIFT; // 0x0AA4
    STRUCT opa_scale_r OPA_SCALE;             // 0x0AA8
    STRUCT opa_scale_shift_r OPA_SCALE_SHIFT; // 0x0AAC
    STRUCT opb_scale_r OPB_SCALE;             // 0x0AB0
    uint32_t unused27[3];
    STRUCT dma0_src_r DMA0_SRC;     // 0x0AC0
    STRUCT dma0_dst_r DMA0_DST;     // 0x0AC8
    STRUCT dma0_len_r DMA0_LEN;     // 0x0AD0
    STRUCT dma0_skip0_r DMA0_SKIP0; // 0x0AD8
    STRUCT dma0_skip1_r DMA0_SKIP1; // 0x0AE0
    uint32_t unused28[6];
    STRUCT ifm2_base0_r IFM2_BASE0;       // 0x0B00
    STRUCT ifm2_base1_r IFM2_BASE1;       // 0x0B08
    STRUCT ifm2_base2_r IFM2_BASE2;       // 0x0B10
    STRUCT ifm2_base3_r IFM2_BASE3;       // 0x0B18
    STRUCT ifm2_stride_x_r IFM2_STRIDE_X; // 0x0B20
    STRUCT ifm2_stride_y_r IFM2_STRIDE_Y; // 0x0B28
    STRUCT ifm2_stride_c_r IFM2_STRIDE_C; // 0x0B30
    uint32_t unused29[2];
    STRUCT weight1_base_r WEIGHT1_BASE;     // 0x0B40
    STRUCT weight1_length_r WEIGHT1_LENGTH; // 0x0B48
    STRUCT scale1_base_r SCALE1_BASE;       // 0x0B50
    STRUCT scale1_length_r SCALE1_LENGTH;   // 0x0B58
    uint32_t unused30[280];
    STRUCT revision_r REVISION; // 0x0FC0
    uint32_t unused31[3];
    STRUCT pid4_r PID4; // 0x0FD0
    STRUCT pid5_r PID5; // 0x0FD4
    STRUCT pid6_r PID6; // 0x0FD8
    STRUCT pid7_r PID7; // 0x0FDC
    STRUCT pid0_r PID0; // 0x0FE0
    STRUCT pid1_r PID1; // 0x0FE4
    STRUCT pid2_r PID2; // 0x0FE8
    STRUCT pid3_r PID3; // 0x0FEC
    STRUCT cid0_r CID0; // 0x0FF0
    STRUCT cid1_r CID1; // 0x0FF4
    STRUCT cid2_r CID2; // 0x0FF8
    STRUCT cid3_r CID3; // 0x0FFC

#ifdef __cplusplus
    enum class access_type_t : uint8_t
    {
        RW,
        RO,
        WO
    };
    NPU_REG()
    {
        reset();
    }
    void reset()
    {
        ID         = 268853249;
        STATUS     = 8;
        CMD        = 12;
        RESET      = 0;
        QBASE      = 0;
        QREAD      = 0;
        QCONFIG    = 0;
        QSIZE      = 0;
        PROT       = 0;
        CONFIG     = 268435456;
        LOCK       = 0;
        REGIONCFG  = 0;
        AXI_LIMIT0 = 0;
        AXI_LIMIT1 = 0;
        AXI_LIMIT2 = 0;
        AXI_LIMIT3 = 0;
        for (size_t i = 0; i < (sizeof(BASEP) / sizeof(BASEP[0])); ++i)
            BASEP[i] = 0;
        WD_STATUS          = 0;
        MAC_STATUS         = 0;
        AO_STATUS          = 0;
        DMA_STATUS0        = 0;
        DMA_STATUS1        = 0;
        CLKFORCE           = 0;
        DEBUG_ADDRESS      = 0;
        DEBUG_MISC         = 0;
        DEBUGCORE          = 0;
        DEBUG_BLOCK        = 0;
        PMCR               = 8192;
        PMCNTENSET         = 0;
        PMCNTENCLR         = 0;
        PMOVSSET           = 0;
        PMOVSCLR           = 0;
        PMINTSET           = 0;
        PMINTCLR           = 0;
        PMCCNTR            = 0;
        PMCCNTR_CFG        = 0;
        PMCAXI_CHAN        = 0;
        KERNEL_X           = 0;
        KERNEL_Y           = 0;
        KERNEL_W_M1        = 0;
        KERNEL_H_M1        = 0;
        OFM_CBLK_WIDTH_M1  = 0;
        OFM_CBLK_HEIGHT_M1 = 0;
        OFM_CBLK_DEPTH_M1  = 0;
        IFM_CBLK_DEPTH_M1  = 0;
        OFM_X              = 0;
        OFM_Y              = 0;
        OFM_Z              = 0;
        IFM_Z              = 0;
        PAD_TOP            = 0;
        PAD_LEFT           = 0;
        IFM_CBLK_WIDTH     = 0;
        IFM_CBLK_HEIGHT    = 0;
        DMA_IFM_SRC        = 0;
        DMA_IFM_DST        = 0;
        DMA_OFM_SRC        = 0;
        DMA_OFM_DST        = 0;
        DMA_WEIGHT_SRC     = 0;
        DMA_CMD_SRC        = 0;
        DMA_CMD_SIZE       = 0;
        DMA_M2M_SRC        = 0;
        DMA_M2M_DST        = 0;
        CURRENT_QREAD      = 0;
        DMA_SCALE_SRC      = 0;
        CURRENT_BLOCK      = 0;
        CURRENT_OP         = 0;
        CURRENT_CMD        = 0;
        for (size_t i = 0; i < (sizeof(PMEVCNTR) / sizeof(PMEVCNTR[0])); ++i)
            PMEVCNTR[i] = 0;
        for (size_t i = 0; i < (sizeof(PMEVTYPER) / sizeof(PMEVTYPER[0])); ++i)
            PMEVTYPER[i] = 0;
        for (size_t i = 0; i < (sizeof(SHARED_BUFFER) / sizeof(SHARED_BUFFER[0])); ++i)
            SHARED_BUFFER[i] = 0;
        IFM_PAD_TOP       = 0;
        IFM_PAD_LEFT      = 0;
        IFM_PAD_RIGHT     = 0;
        IFM_PAD_BOTTOM    = 0;
        IFM_DEPTH_M1      = 0;
        IFM_PRECISION     = 0;
        IFM_UPSCALE       = 0;
        IFM_ZERO_POINT    = 0;
        IFM_WIDTH0_M1     = 0;
        IFM_HEIGHT0_M1    = 0;
        IFM_HEIGHT1_M1    = 0;
        IFM_IB_END        = 0;
        IFM_REGION        = 0;
        OFM_WIDTH_M1      = 0;
        OFM_HEIGHT_M1     = 0;
        OFM_DEPTH_M1      = 0;
        OFM_PRECISION     = 0;
        OFM_BLK_WIDTH_M1  = 0;
        OFM_BLK_HEIGHT_M1 = 0;
        OFM_BLK_DEPTH_M1  = 0;
        OFM_ZERO_POINT    = 0;
        OFM_WIDTH0_M1     = 0;
        OFM_HEIGHT0_M1    = 0;
        OFM_HEIGHT1_M1    = 0;
        OFM_REGION        = 0;
        KERNEL_WIDTH_M1   = 0;
        KERNEL_HEIGHT_M1  = 0;
        KERNEL_STRIDE     = 0;
        PARALLEL_MODE     = 0;
        ACC_FORMAT        = 0;
        ACTIVATION        = 0;
        ACTIVATION_MIN    = 0;
        ACTIVATION_MAX    = 0;
        WEIGHT_REGION     = 0;
        SCALE_REGION      = 0;
        AB_START          = 0;
        BLOCKDEP          = 0;
        DMA0_SRC_REGION   = 0;
        DMA0_DST_REGION   = 0;
        DMA0_SIZE0        = 0;
        DMA0_SIZE1        = 0;
        IFM2_BROADCAST    = 0;
        IFM2_SCALAR       = 0;
        IFM2_PRECISION    = 0;
        IFM2_ZERO_POINT   = 0;
        IFM2_WIDTH0_M1    = 0;
        IFM2_HEIGHT0_M1   = 0;
        IFM2_HEIGHT1_M1   = 0;
        IFM2_IB_START     = 0;
        IFM2_REGION       = 0;
        IFM_BASE0         = 0;
        IFM_BASE1         = 0;
        IFM_BASE2         = 0;
        IFM_BASE3         = 0;
        IFM_STRIDE_X      = 0;
        IFM_STRIDE_Y      = 0;
        IFM_STRIDE_C      = 0;
        OFM_BASE0         = 0;
        OFM_BASE1         = 0;
        OFM_BASE2         = 0;
        OFM_BASE3         = 0;
        OFM_STRIDE_X      = 0;
        OFM_STRIDE_Y      = 0;
        OFM_STRIDE_C      = 0;
        WEIGHT_BASE       = 0;
        WEIGHT_LENGTH     = 0;
        SCALE_BASE        = 0;
        SCALE_LENGTH      = 0;
        OFM_SCALE         = 0;
        OFM_SCALE_SHIFT   = 0;
        OPA_SCALE         = 0;
        OPA_SCALE_SHIFT   = 0;
        OPB_SCALE         = 0;
        DMA0_SRC          = 0;
        DMA0_DST          = 0;
        DMA0_LEN          = 0;
        DMA0_SKIP0        = 0;
        DMA0_SKIP1        = 0;
        IFM2_BASE0        = 0;
        IFM2_BASE1        = 0;
        IFM2_BASE2        = 0;
        IFM2_BASE3        = 0;
        IFM2_STRIDE_X     = 0;
        IFM2_STRIDE_Y     = 0;
        IFM2_STRIDE_C     = 0;
        WEIGHT1_BASE      = 0;
        WEIGHT1_LENGTH    = 0;
        SCALE1_BASE       = 0;
        SCALE1_LENGTH     = 0;
        REVISION          = 0;
        PID4              = 4;
        PID5              = 0;
        PID6              = 0;
        PID7              = 0;
        PID0              = 129;
        PID1              = 181;
        PID2              = 11;
        PID3              = 0;
        CID0              = 13;
        CID1              = 240;
        CID2              = 5;
        CID3              = 177;
    }
    uint32_t &operator[](const int addr_offset)
    {
        return reinterpret_cast<uint32_t *>(this)[addr_offset / 4];
    }
    access_type_t get_access_type(uint32_t offset)
    {
        switch (offset)
        {
        case 0:
            return access_type_t::RO;
        case 4:
            return access_type_t::RO;
        case 8:
            return access_type_t::RW;
        case 12:
            return access_type_t::RW;
        case 16:
            return access_type_t::RW;
        case 24:
            return access_type_t::RO;
        case 28:
            return access_type_t::RW;
        case 32:
            return access_type_t::RW;
        case 36:
            return access_type_t::RO;
        case 40:
            return access_type_t::RO;
        case 44:
            return access_type_t::RW;
        case 60:
            return access_type_t::RW;
        case 64:
            return access_type_t::RW;
        case 68:
            return access_type_t::RW;
        case 72:
            return access_type_t::RW;
        case 76:
            return access_type_t::RW;
        case 128:
            return access_type_t::RW;
        case 136:
            return access_type_t::RW;
        case 144:
            return access_type_t::RW;
        case 152:
            return access_type_t::RW;
        case 160:
            return access_type_t::RW;
        case 168:
            return access_type_t::RW;
        case 176:
            return access_type_t::RW;
        case 184:
            return access_type_t::RW;
        case 256:
            return access_type_t::RO;
        case 260:
            return access_type_t::RO;
        case 264:
            return access_type_t::RO;
        case 272:
            return access_type_t::RO;
        case 276:
            return access_type_t::RO;
        case 320:
            return access_type_t::RW;
        case 324:
            return access_type_t::RW;
        case 328:
            return access_type_t::RW;
        case 332:
            return access_type_t::RW;
        case 336:
            return access_type_t::RW;
        case 384:
            return access_type_t::RW;
        case 388:
            return access_type_t::RW;
        case 392:
            return access_type_t::RW;
        case 396:
            return access_type_t::RW;
        case 400:
            return access_type_t::RW;
        case 404:
            return access_type_t::RW;
        case 408:
            return access_type_t::RW;
        case 416:
            return access_type_t::RW;
        case 424:
            return access_type_t::RW;
        case 428:
            return access_type_t::RW;
        case 512:
            return access_type_t::RO;
        case 516:
            return access_type_t::RO;
        case 520:
            return access_type_t::RO;
        case 524:
            return access_type_t::RO;
        case 528:
            return access_type_t::RO;
        case 532:
            return access_type_t::RO;
        case 536:
            return access_type_t::RO;
        case 540:
            return access_type_t::RO;
        case 544:
            return access_type_t::RO;
        case 548:
            return access_type_t::RO;
        case 552:
            return access_type_t::RO;
        case 556:
            return access_type_t::RO;
        case 560:
            return access_type_t::RO;
        case 564:
            return access_type_t::RO;
        case 568:
            return access_type_t::RO;
        case 572:
            return access_type_t::RO;
        case 576:
            return access_type_t::RO;
        case 584:
            return access_type_t::RO;
        case 588:
            return access_type_t::RO;
        case 592:
            return access_type_t::RO;
        case 600:
            return access_type_t::RO;
        case 608:
            return access_type_t::RO;
        case 616:
            return access_type_t::RO;
        case 620:
            return access_type_t::RO;
        case 628:
            return access_type_t::RO;
        case 636:
            return access_type_t::RO;
        case 640:
            return access_type_t::RO;
        case 692:
            return access_type_t::RO;
        case 696:
            return access_type_t::RO;
        case 700:
            return access_type_t::RO;
        case 768:
            return access_type_t::RW;
        case 772:
            return access_type_t::RW;
        case 776:
            return access_type_t::RW;
        case 780:
            return access_type_t::RW;
        case 896:
            return access_type_t::RW;
        case 900:
            return access_type_t::RW;
        case 904:
            return access_type_t::RW;
        case 908:
            return access_type_t::RW;
        case 1024:
            return access_type_t::RW;
        case 1028:
            return access_type_t::RW;
        case 1032:
            return access_type_t::RW;
        case 1036:
            return access_type_t::RW;
        case 1040:
            return access_type_t::RW;
        case 1044:
            return access_type_t::RW;
        case 1048:
            return access_type_t::RW;
        case 1052:
            return access_type_t::RW;
        case 1056:
            return access_type_t::RW;
        case 1060:
            return access_type_t::RW;
        case 1064:
            return access_type_t::RW;
        case 1068:
            return access_type_t::RW;
        case 1072:
            return access_type_t::RW;
        case 1076:
            return access_type_t::RW;
        case 1080:
            return access_type_t::RW;
        case 1084:
            return access_type_t::RW;
        case 1088:
            return access_type_t::RW;
        case 1092:
            return access_type_t::RW;
        case 1096:
            return access_type_t::RW;
        case 1100:
            return access_type_t::RW;
        case 1104:
            return access_type_t::RW;
        case 1108:
            return access_type_t::RW;
        case 1112:
            return access_type_t::RW;
        case 1116:
            return access_type_t::RW;
        case 1120:
            return access_type_t::RW;
        case 1124:
            return access_type_t::RW;
        case 1128:
            return access_type_t::RW;
        case 1132:
            return access_type_t::RW;
        case 1136:
            return access_type_t::RW;
        case 1140:
            return access_type_t::RW;
        case 1144:
            return access_type_t::RW;
        case 1148:
            return access_type_t::RW;
        case 1152:
            return access_type_t::RW;
        case 1156:
            return access_type_t::RW;
        case 1160:
            return access_type_t::RW;
        case 1164:
            return access_type_t::RW;
        case 1168:
            return access_type_t::RW;
        case 1172:
            return access_type_t::RW;
        case 1176:
            return access_type_t::RW;
        case 1180:
            return access_type_t::RW;
        case 1184:
            return access_type_t::RW;
        case 1188:
            return access_type_t::RW;
        case 1192:
            return access_type_t::RW;
        case 1196:
            return access_type_t::RW;
        case 1200:
            return access_type_t::RW;
        case 1204:
            return access_type_t::RW;
        case 1208:
            return access_type_t::RW;
        case 1212:
            return access_type_t::RW;
        case 1216:
            return access_type_t::RW;
        case 1220:
            return access_type_t::RW;
        case 1224:
            return access_type_t::RW;
        case 1228:
            return access_type_t::RW;
        case 1232:
            return access_type_t::RW;
        case 1236:
            return access_type_t::RW;
        case 1240:
            return access_type_t::RW;
        case 1244:
            return access_type_t::RW;
        case 1248:
            return access_type_t::RW;
        case 1252:
            return access_type_t::RW;
        case 1256:
            return access_type_t::RW;
        case 1260:
            return access_type_t::RW;
        case 1264:
            return access_type_t::RW;
        case 1268:
            return access_type_t::RW;
        case 1272:
            return access_type_t::RW;
        case 1276:
            return access_type_t::RW;
        case 1280:
            return access_type_t::RW;
        case 1284:
            return access_type_t::RW;
        case 1288:
            return access_type_t::RW;
        case 1292:
            return access_type_t::RW;
        case 1296:
            return access_type_t::RW;
        case 1300:
            return access_type_t::RW;
        case 1304:
            return access_type_t::RW;
        case 1308:
            return access_type_t::RW;
        case 1312:
            return access_type_t::RW;
        case 1316:
            return access_type_t::RW;
        case 1320:
            return access_type_t::RW;
        case 1324:
            return access_type_t::RW;
        case 1328:
            return access_type_t::RW;
        case 1332:
            return access_type_t::RW;
        case 1336:
            return access_type_t::RW;
        case 1340:
            return access_type_t::RW;
        case 1344:
            return access_type_t::RW;
        case 1348:
            return access_type_t::RW;
        case 1352:
            return access_type_t::RW;
        case 1356:
            return access_type_t::RW;
        case 1360:
            return access_type_t::RW;
        case 1364:
            return access_type_t::RW;
        case 1368:
            return access_type_t::RW;
        case 1372:
            return access_type_t::RW;
        case 1376:
            return access_type_t::RW;
        case 1380:
            return access_type_t::RW;
        case 1384:
            return access_type_t::RW;
        case 1388:
            return access_type_t::RW;
        case 1392:
            return access_type_t::RW;
        case 1396:
            return access_type_t::RW;
        case 1400:
            return access_type_t::RW;
        case 1404:
            return access_type_t::RW;
        case 1408:
            return access_type_t::RW;
        case 1412:
            return access_type_t::RW;
        case 1416:
            return access_type_t::RW;
        case 1420:
            return access_type_t::RW;
        case 1424:
            return access_type_t::RW;
        case 1428:
            return access_type_t::RW;
        case 1432:
            return access_type_t::RW;
        case 1436:
            return access_type_t::RW;
        case 1440:
            return access_type_t::RW;
        case 1444:
            return access_type_t::RW;
        case 1448:
            return access_type_t::RW;
        case 1452:
            return access_type_t::RW;
        case 1456:
            return access_type_t::RW;
        case 1460:
            return access_type_t::RW;
        case 1464:
            return access_type_t::RW;
        case 1468:
            return access_type_t::RW;
        case 1472:
            return access_type_t::RW;
        case 1476:
            return access_type_t::RW;
        case 1480:
            return access_type_t::RW;
        case 1484:
            return access_type_t::RW;
        case 1488:
            return access_type_t::RW;
        case 1492:
            return access_type_t::RW;
        case 1496:
            return access_type_t::RW;
        case 1500:
            return access_type_t::RW;
        case 1504:
            return access_type_t::RW;
        case 1508:
            return access_type_t::RW;
        case 1512:
            return access_type_t::RW;
        case 1516:
            return access_type_t::RW;
        case 1520:
            return access_type_t::RW;
        case 1524:
            return access_type_t::RW;
        case 1528:
            return access_type_t::RW;
        case 1532:
            return access_type_t::RW;
        case 1536:
            return access_type_t::RW;
        case 1540:
            return access_type_t::RW;
        case 1544:
            return access_type_t::RW;
        case 1548:
            return access_type_t::RW;
        case 1552:
            return access_type_t::RW;
        case 1556:
            return access_type_t::RW;
        case 1560:
            return access_type_t::RW;
        case 1564:
            return access_type_t::RW;
        case 1568:
            return access_type_t::RW;
        case 1572:
            return access_type_t::RW;
        case 1576:
            return access_type_t::RW;
        case 1580:
            return access_type_t::RW;
        case 1584:
            return access_type_t::RW;
        case 1588:
            return access_type_t::RW;
        case 1592:
            return access_type_t::RW;
        case 1596:
            return access_type_t::RW;
        case 1600:
            return access_type_t::RW;
        case 1604:
            return access_type_t::RW;
        case 1608:
            return access_type_t::RW;
        case 1612:
            return access_type_t::RW;
        case 1616:
            return access_type_t::RW;
        case 1620:
            return access_type_t::RW;
        case 1624:
            return access_type_t::RW;
        case 1628:
            return access_type_t::RW;
        case 1632:
            return access_type_t::RW;
        case 1636:
            return access_type_t::RW;
        case 1640:
            return access_type_t::RW;
        case 1644:
            return access_type_t::RW;
        case 1648:
            return access_type_t::RW;
        case 1652:
            return access_type_t::RW;
        case 1656:
            return access_type_t::RW;
        case 1660:
            return access_type_t::RW;
        case 1664:
            return access_type_t::RW;
        case 1668:
            return access_type_t::RW;
        case 1672:
            return access_type_t::RW;
        case 1676:
            return access_type_t::RW;
        case 1680:
            return access_type_t::RW;
        case 1684:
            return access_type_t::RW;
        case 1688:
            return access_type_t::RW;
        case 1692:
            return access_type_t::RW;
        case 1696:
            return access_type_t::RW;
        case 1700:
            return access_type_t::RW;
        case 1704:
            return access_type_t::RW;
        case 1708:
            return access_type_t::RW;
        case 1712:
            return access_type_t::RW;
        case 1716:
            return access_type_t::RW;
        case 1720:
            return access_type_t::RW;
        case 1724:
            return access_type_t::RW;
        case 1728:
            return access_type_t::RW;
        case 1732:
            return access_type_t::RW;
        case 1736:
            return access_type_t::RW;
        case 1740:
            return access_type_t::RW;
        case 1744:
            return access_type_t::RW;
        case 1748:
            return access_type_t::RW;
        case 1752:
            return access_type_t::RW;
        case 1756:
            return access_type_t::RW;
        case 1760:
            return access_type_t::RW;
        case 1764:
            return access_type_t::RW;
        case 1768:
            return access_type_t::RW;
        case 1772:
            return access_type_t::RW;
        case 1776:
            return access_type_t::RW;
        case 1780:
            return access_type_t::RW;
        case 1784:
            return access_type_t::RW;
        case 1788:
            return access_type_t::RW;
        case 1792:
            return access_type_t::RW;
        case 1796:
            return access_type_t::RW;
        case 1800:
            return access_type_t::RW;
        case 1804:
            return access_type_t::RW;
        case 1808:
            return access_type_t::RW;
        case 1812:
            return access_type_t::RW;
        case 1816:
            return access_type_t::RW;
        case 1820:
            return access_type_t::RW;
        case 1824:
            return access_type_t::RW;
        case 1828:
            return access_type_t::RW;
        case 1832:
            return access_type_t::RW;
        case 1836:
            return access_type_t::RW;
        case 1840:
            return access_type_t::RW;
        case 1844:
            return access_type_t::RW;
        case 1848:
            return access_type_t::RW;
        case 1852:
            return access_type_t::RW;
        case 1856:
            return access_type_t::RW;
        case 1860:
            return access_type_t::RW;
        case 1864:
            return access_type_t::RW;
        case 1868:
            return access_type_t::RW;
        case 1872:
            return access_type_t::RW;
        case 1876:
            return access_type_t::RW;
        case 1880:
            return access_type_t::RW;
        case 1884:
            return access_type_t::RW;
        case 1888:
            return access_type_t::RW;
        case 1892:
            return access_type_t::RW;
        case 1896:
            return access_type_t::RW;
        case 1900:
            return access_type_t::RW;
        case 1904:
            return access_type_t::RW;
        case 1908:
            return access_type_t::RW;
        case 1912:
            return access_type_t::RW;
        case 1916:
            return access_type_t::RW;
        case 1920:
            return access_type_t::RW;
        case 1924:
            return access_type_t::RW;
        case 1928:
            return access_type_t::RW;
        case 1932:
            return access_type_t::RW;
        case 1936:
            return access_type_t::RW;
        case 1940:
            return access_type_t::RW;
        case 1944:
            return access_type_t::RW;
        case 1948:
            return access_type_t::RW;
        case 1952:
            return access_type_t::RW;
        case 1956:
            return access_type_t::RW;
        case 1960:
            return access_type_t::RW;
        case 1964:
            return access_type_t::RW;
        case 1968:
            return access_type_t::RW;
        case 1972:
            return access_type_t::RW;
        case 1976:
            return access_type_t::RW;
        case 1980:
            return access_type_t::RW;
        case 1984:
            return access_type_t::RW;
        case 1988:
            return access_type_t::RW;
        case 1992:
            return access_type_t::RW;
        case 1996:
            return access_type_t::RW;
        case 2000:
            return access_type_t::RW;
        case 2004:
            return access_type_t::RW;
        case 2008:
            return access_type_t::RW;
        case 2012:
            return access_type_t::RW;
        case 2016:
            return access_type_t::RW;
        case 2020:
            return access_type_t::RW;
        case 2024:
            return access_type_t::RW;
        case 2028:
            return access_type_t::RW;
        case 2032:
            return access_type_t::RW;
        case 2036:
            return access_type_t::RW;
        case 2040:
            return access_type_t::RW;
        case 2044:
            return access_type_t::RW;
        case 2048:
            return access_type_t::RW;
        case 2052:
            return access_type_t::RW;
        case 2056:
            return access_type_t::RW;
        case 2060:
            return access_type_t::RW;
        case 2064:
            return access_type_t::RW;
        case 2068:
            return access_type_t::RW;
        case 2076:
            return access_type_t::RW;
        case 2084:
            return access_type_t::RW;
        case 2088:
            return access_type_t::RW;
        case 2092:
            return access_type_t::RW;
        case 2096:
            return access_type_t::RW;
        case 2100:
            return access_type_t::RW;
        case 2108:
            return access_type_t::RW;
        case 2116:
            return access_type_t::RW;
        case 2120:
            return access_type_t::RW;
        case 2124:
            return access_type_t::RW;
        case 2128:
            return access_type_t::RW;
        case 2132:
            return access_type_t::RW;
        case 2136:
            return access_type_t::RW;
        case 2140:
            return access_type_t::RW;
        case 2144:
            return access_type_t::RW;
        case 2152:
            return access_type_t::RW;
        case 2156:
            return access_type_t::RW;
        case 2160:
            return access_type_t::RW;
        case 2172:
            return access_type_t::RW;
        case 2176:
            return access_type_t::RW;
        case 2180:
            return access_type_t::RW;
        case 2184:
            return access_type_t::RW;
        case 2188:
            return access_type_t::RW;
        case 2192:
            return access_type_t::RW;
        case 2196:
            return access_type_t::RW;
        case 2200:
            return access_type_t::RW;
        case 2204:
            return access_type_t::RW;
        case 2208:
            return access_type_t::RW;
        case 2212:
            return access_type_t::RW;
        case 2228:
            return access_type_t::RW;
        case 2236:
            return access_type_t::RW;
        case 2240:
            return access_type_t::RW;
        case 2244:
            return access_type_t::RW;
        case 2248:
            return access_type_t::RW;
        case 2252:
            return access_type_t::RW;
        case 2304:
            return access_type_t::RW;
        case 2308:
            return access_type_t::RW;
        case 2324:
            return access_type_t::RW;
        case 2340:
            return access_type_t::RW;
        case 2344:
            return access_type_t::RW;
        case 2348:
            return access_type_t::RW;
        case 2352:
            return access_type_t::RW;
        case 2356:
            return access_type_t::RW;
        case 2364:
            return access_type_t::RW;
        case 2560:
            return access_type_t::RW;
        case 2568:
            return access_type_t::RW;
        case 2576:
            return access_type_t::RW;
        case 2584:
            return access_type_t::RW;
        case 2592:
            return access_type_t::RW;
        case 2600:
            return access_type_t::RW;
        case 2608:
            return access_type_t::RW;
        case 2624:
            return access_type_t::RW;
        case 2632:
            return access_type_t::RW;
        case 2640:
            return access_type_t::RW;
        case 2648:
            return access_type_t::RW;
        case 2656:
            return access_type_t::RW;
        case 2664:
            return access_type_t::RW;
        case 2672:
            return access_type_t::RW;
        case 2688:
            return access_type_t::RW;
        case 2696:
            return access_type_t::RW;
        case 2704:
            return access_type_t::RW;
        case 2712:
            return access_type_t::RW;
        case 2720:
            return access_type_t::RW;
        case 2724:
            return access_type_t::RW;
        case 2728:
            return access_type_t::RW;
        case 2732:
            return access_type_t::RW;
        case 2736:
            return access_type_t::RW;
        case 2752:
            return access_type_t::RW;
        case 2760:
            return access_type_t::RW;
        case 2768:
            return access_type_t::RW;
        case 2776:
            return access_type_t::RW;
        case 2784:
            return access_type_t::RW;
        case 2816:
            return access_type_t::RW;
        case 2824:
            return access_type_t::RW;
        case 2832:
            return access_type_t::RW;
        case 2840:
            return access_type_t::RW;
        case 2848:
            return access_type_t::RW;
        case 2856:
            return access_type_t::RW;
        case 2864:
            return access_type_t::RW;
        case 2880:
            return access_type_t::RW;
        case 2888:
            return access_type_t::RW;
        case 2896:
            return access_type_t::RW;
        case 2904:
            return access_type_t::RW;
        case 4032:
            return access_type_t::RO;
        case 4048:
            return access_type_t::RO;
        case 4052:
            return access_type_t::RO;
        case 4056:
            return access_type_t::RO;
        case 4060:
            return access_type_t::RO;
        case 4064:
            return access_type_t::RO;
        case 4068:
            return access_type_t::RO;
        case 4072:
            return access_type_t::RO;
        case 4076:
            return access_type_t::RO;
        case 4080:
            return access_type_t::RO;
        case 4084:
            return access_type_t::RO;
        case 4088:
            return access_type_t::RO;
        case 4092:
            return access_type_t::RO;
        default:
            return access_type_t::RO;
        }
    }
#endif
};

#ifdef __cplusplus
struct isa
{
#ifdef NPU_DISASSEMBLE
    static int disassemble(const uint32_t *in,
                           std::string &op,
                           std::vector<std::pair<std::string, std::string>> &fields)
    {
        switch (*in & 0xffff)
        {
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_STOP):
        {
            const npu_op_stop_t &v = *reinterpret_cast<const npu_op_stop_t *>(in);
            op                     = "NPU_OP_STOP";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_IRQ):
        {
            const npu_op_irq_t &v = *reinterpret_cast<const npu_op_irq_t *>(in);
            op                    = "NPU_OP_IRQ";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_CONV):
        {
            const npu_op_conv_t &v = *reinterpret_cast<const npu_op_conv_t *>(in);
            op                     = "NPU_OP_CONV";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DEPTHWISE):
        {
            const npu_op_depthwise_t &v = *reinterpret_cast<const npu_op_depthwise_t *>(in);
            op                          = "NPU_OP_DEPTHWISE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_POOL):
        {
            const npu_op_pool_t &v = *reinterpret_cast<const npu_op_pool_t *>(in);
            op                     = "NPU_OP_POOL";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_ELEMENTWISE):
        {
            const npu_op_elementwise_t &v = *reinterpret_cast<const npu_op_elementwise_t *>(in);
            op                            = "NPU_OP_ELEMENTWISE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_START):
        {
            const npu_op_dma_start_t &v = *reinterpret_cast<const npu_op_dma_start_t *>(in);
            op                          = "NPU_OP_DMA_START";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_WAIT):
        {
            const npu_op_dma_wait_t &v = *reinterpret_cast<const npu_op_dma_wait_t *>(in);
            op                         = "NPU_OP_DMA_WAIT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_KERNEL_WAIT):
        {
            const npu_op_kernel_wait_t &v = *reinterpret_cast<const npu_op_kernel_wait_t *>(in);
            op                            = "NPU_OP_KERNEL_WAIT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_PMU_MASK):
        {
            const npu_op_pmu_mask_t &v = *reinterpret_cast<const npu_op_pmu_mask_t *>(in);
            op                         = "NPU_OP_PMU_MASK";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_TOP):
        {
            const npu_set_ifm_pad_top_t &v = *reinterpret_cast<const npu_set_ifm_pad_top_t *>(in);
            op                             = "NPU_SET_IFM_PAD_TOP";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_LEFT):
        {
            const npu_set_ifm_pad_left_t &v = *reinterpret_cast<const npu_set_ifm_pad_left_t *>(in);
            op                              = "NPU_SET_IFM_PAD_LEFT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_RIGHT):
        {
            const npu_set_ifm_pad_right_t &v = *reinterpret_cast<const npu_set_ifm_pad_right_t *>(in);
            op                               = "NPU_SET_IFM_PAD_RIGHT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_BOTTOM):
        {
            const npu_set_ifm_pad_bottom_t &v = *reinterpret_cast<const npu_set_ifm_pad_bottom_t *>(in);
            op                                = "NPU_SET_IFM_PAD_BOTTOM";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_DEPTH_M1):
        {
            const npu_set_ifm_depth_m1_t &v = *reinterpret_cast<const npu_set_ifm_depth_m1_t *>(in);
            op                              = "NPU_SET_IFM_DEPTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PRECISION):
        {
            const npu_set_ifm_precision_t &v = *reinterpret_cast<const npu_set_ifm_precision_t *>(in);
            op                               = "NPU_SET_IFM_PRECISION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_UPSCALE):
        {
            const npu_set_ifm_upscale_t &v = *reinterpret_cast<const npu_set_ifm_upscale_t *>(in);
            op                             = "NPU_SET_IFM_UPSCALE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_ZERO_POINT):
        {
            const npu_set_ifm_zero_point_t &v = *reinterpret_cast<const npu_set_ifm_zero_point_t *>(in);
            op                                = "NPU_SET_IFM_ZERO_POINT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_WIDTH0_M1):
        {
            const npu_set_ifm_width0_m1_t &v = *reinterpret_cast<const npu_set_ifm_width0_m1_t *>(in);
            op                               = "NPU_SET_IFM_WIDTH0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT0_M1):
        {
            const npu_set_ifm_height0_m1_t &v = *reinterpret_cast<const npu_set_ifm_height0_m1_t *>(in);
            op                                = "NPU_SET_IFM_HEIGHT0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT1_M1):
        {
            const npu_set_ifm_height1_m1_t &v = *reinterpret_cast<const npu_set_ifm_height1_m1_t *>(in);
            op                                = "NPU_SET_IFM_HEIGHT1_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_IB_END):
        {
            const npu_set_ifm_ib_end_t &v = *reinterpret_cast<const npu_set_ifm_ib_end_t *>(in);
            op                            = "NPU_SET_IFM_IB_END";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_REGION):
        {
            const npu_set_ifm_region_t &v = *reinterpret_cast<const npu_set_ifm_region_t *>(in);
            op                            = "NPU_SET_IFM_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH_M1):
        {
            const npu_set_ofm_width_m1_t &v = *reinterpret_cast<const npu_set_ofm_width_m1_t *>(in);
            op                              = "NPU_SET_OFM_WIDTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT_M1):
        {
            const npu_set_ofm_height_m1_t &v = *reinterpret_cast<const npu_set_ofm_height_m1_t *>(in);
            op                               = "NPU_SET_OFM_HEIGHT_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_DEPTH_M1):
        {
            const npu_set_ofm_depth_m1_t &v = *reinterpret_cast<const npu_set_ofm_depth_m1_t *>(in);
            op                              = "NPU_SET_OFM_DEPTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_PRECISION):
        {
            const npu_set_ofm_precision_t &v = *reinterpret_cast<const npu_set_ofm_precision_t *>(in);
            op                               = "NPU_SET_OFM_PRECISION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_WIDTH_M1):
        {
            const npu_set_ofm_blk_width_m1_t &v = *reinterpret_cast<const npu_set_ofm_blk_width_m1_t *>(in);
            op                                  = "NPU_SET_OFM_BLK_WIDTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_HEIGHT_M1):
        {
            const npu_set_ofm_blk_height_m1_t &v = *reinterpret_cast<const npu_set_ofm_blk_height_m1_t *>(in);
            op                                   = "NPU_SET_OFM_BLK_HEIGHT_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_DEPTH_M1):
        {
            const npu_set_ofm_blk_depth_m1_t &v = *reinterpret_cast<const npu_set_ofm_blk_depth_m1_t *>(in);
            op                                  = "NPU_SET_OFM_BLK_DEPTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_ZERO_POINT):
        {
            const npu_set_ofm_zero_point_t &v = *reinterpret_cast<const npu_set_ofm_zero_point_t *>(in);
            op                                = "NPU_SET_OFM_ZERO_POINT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH0_M1):
        {
            const npu_set_ofm_width0_m1_t &v = *reinterpret_cast<const npu_set_ofm_width0_m1_t *>(in);
            op                               = "NPU_SET_OFM_WIDTH0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT0_M1):
        {
            const npu_set_ofm_height0_m1_t &v = *reinterpret_cast<const npu_set_ofm_height0_m1_t *>(in);
            op                                = "NPU_SET_OFM_HEIGHT0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT1_M1):
        {
            const npu_set_ofm_height1_m1_t &v = *reinterpret_cast<const npu_set_ofm_height1_m1_t *>(in);
            op                                = "NPU_SET_OFM_HEIGHT1_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_REGION):
        {
            const npu_set_ofm_region_t &v = *reinterpret_cast<const npu_set_ofm_region_t *>(in);
            op                            = "NPU_SET_OFM_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_WIDTH_M1):
        {
            const npu_set_kernel_width_m1_t &v = *reinterpret_cast<const npu_set_kernel_width_m1_t *>(in);
            op                                 = "NPU_SET_KERNEL_WIDTH_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_HEIGHT_M1):
        {
            const npu_set_kernel_height_m1_t &v = *reinterpret_cast<const npu_set_kernel_height_m1_t *>(in);
            op                                  = "NPU_SET_KERNEL_HEIGHT_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_STRIDE):
        {
            const npu_set_kernel_stride_t &v = *reinterpret_cast<const npu_set_kernel_stride_t *>(in);
            op                               = "NPU_SET_KERNEL_STRIDE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_PARALLEL_MODE):
        {
            const npu_set_parallel_mode_t &v = *reinterpret_cast<const npu_set_parallel_mode_t *>(in);
            op                               = "NPU_SET_PARALLEL_MODE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACC_FORMAT):
        {
            const npu_set_acc_format_t &v = *reinterpret_cast<const npu_set_acc_format_t *>(in);
            op                            = "NPU_SET_ACC_FORMAT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION):
        {
            const npu_set_activation_t &v = *reinterpret_cast<const npu_set_activation_t *>(in);
            op                            = "NPU_SET_ACTIVATION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MIN):
        {
            const npu_set_activation_min_t &v = *reinterpret_cast<const npu_set_activation_min_t *>(in);
            op                                = "NPU_SET_ACTIVATION_MIN";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MAX):
        {
            const npu_set_activation_max_t &v = *reinterpret_cast<const npu_set_activation_max_t *>(in);
            op                                = "NPU_SET_ACTIVATION_MAX";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_WEIGHT_REGION):
        {
            const npu_set_weight_region_t &v = *reinterpret_cast<const npu_set_weight_region_t *>(in);
            op                               = "NPU_SET_WEIGHT_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_SCALE_REGION):
        {
            const npu_set_scale_region_t &v = *reinterpret_cast<const npu_set_scale_region_t *>(in);
            op                              = "NPU_SET_SCALE_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_AB_START):
        {
            const npu_set_ab_start_t &v = *reinterpret_cast<const npu_set_ab_start_t *>(in);
            op                          = "NPU_SET_AB_START";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_BLOCKDEP):
        {
            const npu_set_blockdep_t &v = *reinterpret_cast<const npu_set_blockdep_t *>(in);
            op                          = "NPU_SET_BLOCKDEP";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SRC_REGION):
        {
            const npu_set_dma0_src_region_t &v = *reinterpret_cast<const npu_set_dma0_src_region_t *>(in);
            op                                 = "NPU_SET_DMA0_SRC_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_DST_REGION):
        {
            const npu_set_dma0_dst_region_t &v = *reinterpret_cast<const npu_set_dma0_dst_region_t *>(in);
            op                                 = "NPU_SET_DMA0_DST_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE0):
        {
            const npu_set_dma0_size0_t &v = *reinterpret_cast<const npu_set_dma0_size0_t *>(in);
            op                            = "NPU_SET_DMA0_SIZE0";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE1):
        {
            const npu_set_dma0_size1_t &v = *reinterpret_cast<const npu_set_dma0_size1_t *>(in);
            op                            = "NPU_SET_DMA0_SIZE1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_BROADCAST):
        {
            const npu_set_ifm2_broadcast_t &v = *reinterpret_cast<const npu_set_ifm2_broadcast_t *>(in);
            op                                = "NPU_SET_IFM2_BROADCAST";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_SCALAR):
        {
            const npu_set_ifm2_scalar_t &v = *reinterpret_cast<const npu_set_ifm2_scalar_t *>(in);
            op                             = "NPU_SET_IFM2_SCALAR";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_PRECISION):
        {
            const npu_set_ifm2_precision_t &v = *reinterpret_cast<const npu_set_ifm2_precision_t *>(in);
            op                                = "NPU_SET_IFM2_PRECISION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_ZERO_POINT):
        {
            const npu_set_ifm2_zero_point_t &v = *reinterpret_cast<const npu_set_ifm2_zero_point_t *>(in);
            op                                 = "NPU_SET_IFM2_ZERO_POINT";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_WIDTH0_M1):
        {
            const npu_set_ifm2_width0_m1_t &v = *reinterpret_cast<const npu_set_ifm2_width0_m1_t *>(in);
            op                                = "NPU_SET_IFM2_WIDTH0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT0_M1):
        {
            const npu_set_ifm2_height0_m1_t &v = *reinterpret_cast<const npu_set_ifm2_height0_m1_t *>(in);
            op                                 = "NPU_SET_IFM2_HEIGHT0_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT1_M1):
        {
            const npu_set_ifm2_height1_m1_t &v = *reinterpret_cast<const npu_set_ifm2_height1_m1_t *>(in);
            op                                 = "NPU_SET_IFM2_HEIGHT1_M1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_IB_START):
        {
            const npu_set_ifm2_ib_start_t &v = *reinterpret_cast<const npu_set_ifm2_ib_start_t *>(in);
            op                               = "NPU_SET_IFM2_IB_START";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_REGION):
        {
            const npu_set_ifm2_region_t &v = *reinterpret_cast<const npu_set_ifm2_region_t *>(in);
            op                             = "NPU_SET_IFM2_REGION";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE0):
        {
            const npu_set_ifm_base0_t &v = *reinterpret_cast<const npu_set_ifm_base0_t *>(in);
            op                           = "NPU_SET_IFM_BASE0";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE1):
        {
            const npu_set_ifm_base1_t &v = *reinterpret_cast<const npu_set_ifm_base1_t *>(in);
            op                           = "NPU_SET_IFM_BASE1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE2):
        {
            const npu_set_ifm_base2_t &v = *reinterpret_cast<const npu_set_ifm_base2_t *>(in);
            op                           = "NPU_SET_IFM_BASE2";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE3):
        {
            const npu_set_ifm_base3_t &v = *reinterpret_cast<const npu_set_ifm_base3_t *>(in);
            op                           = "NPU_SET_IFM_BASE3";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_X):
        {
            const npu_set_ifm_stride_x_t &v = *reinterpret_cast<const npu_set_ifm_stride_x_t *>(in);
            op                              = "NPU_SET_IFM_STRIDE_X";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_Y):
        {
            const npu_set_ifm_stride_y_t &v = *reinterpret_cast<const npu_set_ifm_stride_y_t *>(in);
            op                              = "NPU_SET_IFM_STRIDE_Y";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_C):
        {
            const npu_set_ifm_stride_c_t &v = *reinterpret_cast<const npu_set_ifm_stride_c_t *>(in);
            op                              = "NPU_SET_IFM_STRIDE_C";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE0):
        {
            const npu_set_ofm_base0_t &v = *reinterpret_cast<const npu_set_ofm_base0_t *>(in);
            op                           = "NPU_SET_OFM_BASE0";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE1):
        {
            const npu_set_ofm_base1_t &v = *reinterpret_cast<const npu_set_ofm_base1_t *>(in);
            op                           = "NPU_SET_OFM_BASE1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE2):
        {
            const npu_set_ofm_base2_t &v = *reinterpret_cast<const npu_set_ofm_base2_t *>(in);
            op                           = "NPU_SET_OFM_BASE2";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE3):
        {
            const npu_set_ofm_base3_t &v = *reinterpret_cast<const npu_set_ofm_base3_t *>(in);
            op                           = "NPU_SET_OFM_BASE3";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_X):
        {
            const npu_set_ofm_stride_x_t &v = *reinterpret_cast<const npu_set_ofm_stride_x_t *>(in);
            op                              = "NPU_SET_OFM_STRIDE_X";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_Y):
        {
            const npu_set_ofm_stride_y_t &v = *reinterpret_cast<const npu_set_ofm_stride_y_t *>(in);
            op                              = "NPU_SET_OFM_STRIDE_Y";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_C):
        {
            const npu_set_ofm_stride_c_t &v = *reinterpret_cast<const npu_set_ofm_stride_c_t *>(in);
            op                              = "NPU_SET_OFM_STRIDE_C";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_BASE):
        {
            const npu_set_weight_base_t &v = *reinterpret_cast<const npu_set_weight_base_t *>(in);
            op                             = "NPU_SET_WEIGHT_BASE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_LENGTH):
        {
            const npu_set_weight_length_t &v = *reinterpret_cast<const npu_set_weight_length_t *>(in);
            op                               = "NPU_SET_WEIGHT_LENGTH";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_BASE):
        {
            const npu_set_scale_base_t &v = *reinterpret_cast<const npu_set_scale_base_t *>(in);
            op                            = "NPU_SET_SCALE_BASE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_LENGTH):
        {
            const npu_set_scale_length_t &v = *reinterpret_cast<const npu_set_scale_length_t *>(in);
            op                              = "NPU_SET_SCALE_LENGTH";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_SCALE):
        {
            const npu_set_ofm_scale_t &v = *reinterpret_cast<const npu_set_ofm_scale_t *>(in);
            op                           = "NPU_SET_OFM_SCALE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPA_SCALE):
        {
            const npu_set_opa_scale_t &v = *reinterpret_cast<const npu_set_opa_scale_t *>(in);
            op                           = "NPU_SET_OPA_SCALE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPB_SCALE):
        {
            const npu_set_opb_scale_t &v = *reinterpret_cast<const npu_set_opb_scale_t *>(in);
            op                           = "NPU_SET_OPB_SCALE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SRC):
        {
            const npu_set_dma0_src_t &v = *reinterpret_cast<const npu_set_dma0_src_t *>(in);
            op                          = "NPU_SET_DMA0_SRC";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_DST):
        {
            const npu_set_dma0_dst_t &v = *reinterpret_cast<const npu_set_dma0_dst_t *>(in);
            op                          = "NPU_SET_DMA0_DST";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_LEN):
        {
            const npu_set_dma0_len_t &v = *reinterpret_cast<const npu_set_dma0_len_t *>(in);
            op                          = "NPU_SET_DMA0_LEN";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP0):
        {
            const npu_set_dma0_skip0_t &v = *reinterpret_cast<const npu_set_dma0_skip0_t *>(in);
            op                            = "NPU_SET_DMA0_SKIP0";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP1):
        {
            const npu_set_dma0_skip1_t &v = *reinterpret_cast<const npu_set_dma0_skip1_t *>(in);
            op                            = "NPU_SET_DMA0_SKIP1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE0):
        {
            const npu_set_ifm2_base0_t &v = *reinterpret_cast<const npu_set_ifm2_base0_t *>(in);
            op                            = "NPU_SET_IFM2_BASE0";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE1):
        {
            const npu_set_ifm2_base1_t &v = *reinterpret_cast<const npu_set_ifm2_base1_t *>(in);
            op                            = "NPU_SET_IFM2_BASE1";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE2):
        {
            const npu_set_ifm2_base2_t &v = *reinterpret_cast<const npu_set_ifm2_base2_t *>(in);
            op                            = "NPU_SET_IFM2_BASE2";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE3):
        {
            const npu_set_ifm2_base3_t &v = *reinterpret_cast<const npu_set_ifm2_base3_t *>(in);
            op                            = "NPU_SET_IFM2_BASE3";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_X):
        {
            const npu_set_ifm2_stride_x_t &v = *reinterpret_cast<const npu_set_ifm2_stride_x_t *>(in);
            op                               = "NPU_SET_IFM2_STRIDE_X";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_Y):
        {
            const npu_set_ifm2_stride_y_t &v = *reinterpret_cast<const npu_set_ifm2_stride_y_t *>(in);
            op                               = "NPU_SET_IFM2_STRIDE_Y";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_C):
        {
            const npu_set_ifm2_stride_c_t &v = *reinterpret_cast<const npu_set_ifm2_stride_c_t *>(in);
            op                               = "NPU_SET_IFM2_STRIDE_C";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_BASE):
        {
            const npu_set_weight1_base_t &v = *reinterpret_cast<const npu_set_weight1_base_t *>(in);
            op                              = "NPU_SET_WEIGHT1_BASE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_LENGTH):
        {
            const npu_set_weight1_length_t &v = *reinterpret_cast<const npu_set_weight1_length_t *>(in);
            op                                = "NPU_SET_WEIGHT1_LENGTH";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_BASE):
        {
            const npu_set_scale1_base_t &v = *reinterpret_cast<const npu_set_scale1_base_t *>(in);
            op                             = "NPU_SET_SCALE1_BASE";
            v.disassemble(fields);
            break;
        }
        case (static_cast<uint32_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL) << 14) |
            static_cast<uint32_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_LENGTH):
        {
            const npu_set_scale1_length_t &v = *reinterpret_cast<const npu_set_scale1_length_t *>(in);
            op                               = "NPU_SET_SCALE1_LENGTH";
            v.disassemble(fields);
            break;
        }
        }
        return (*in & (3 << 14)) != 0 ? 2 : 1;
    }
#endif
#endif
    // Signal the end of command stream
    struct npu_op_stop_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t mask : 16;   //  Encoding for 16-bit mask value
#ifdef __cplusplus
      public:
        npu_op_stop_t(uint32_t _mask) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_STOP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), mask(_mask & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_op_stop_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_STOP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), mask(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_STOP) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_STOP);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_stop_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_stop_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_mask() const
        {
            return static_cast<uint32_t>(mask);
        }
        CONSTEXPR npu_op_stop_t &set_mask(uint32_t value)
        {
            mask = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("mask", std::to_string(mask)));
        }
#endif
#endif
    };
    // Raises an IRQ to the host
    struct npu_op_irq_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t mask : 16;   //  Encoding for 16-bit mask value
#ifdef __cplusplus
      public:
        npu_op_irq_t(uint32_t _mask) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_IRQ)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), mask(_mask & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_op_irq_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_IRQ)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), mask(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_IRQ) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_IRQ);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_irq_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_irq_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_mask() const
        {
            return static_cast<uint32_t>(mask);
        }
        CONSTEXPR npu_op_irq_t &set_mask(uint32_t value)
        {
            mask = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("mask", std::to_string(mask)));
        }
#endif
#endif
    };
    // 2D convolution
    struct npu_op_conv_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
#ifdef __cplusplus
      public:
        CONSTEXPR npu_op_conv_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_CONV)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_CONV) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_CONV);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_conv_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_conv_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const {}
#endif
#endif
    };
    // Depth-wise 2D convolution
    struct npu_op_depthwise_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
#ifdef __cplusplus
      public:
        CONSTEXPR npu_op_depthwise_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DEPTHWISE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DEPTHWISE) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DEPTHWISE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_depthwise_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_depthwise_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const {}
#endif
#endif
    };
    // Pooling
    struct npu_op_pool_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;      //  control
        uint32_t pooling_mode : 3; //  Pooling mode
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_op_pool_t(NPU_NAMESPACE::pooling_mode _pooling_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_POOL)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            pooling_mode(static_cast<uint8_t>(_pooling_mode) & ((1U << 3) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_op_pool_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_POOL)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pooling_mode(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_POOL) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_POOL);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_pool_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_pool_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::pooling_mode get_pooling_mode() const
        {
            return static_cast<NPU_NAMESPACE::pooling_mode>(pooling_mode);
        }
        CONSTEXPR npu_op_pool_t &set_pooling_mode(NPU_NAMESPACE::pooling_mode value)
        {
            pooling_mode = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "pooling_mode",
                (pooling_mode < (sizeof(pooling_mode_str) / sizeof(pooling_mode_str[0])) ?
                     pooling_mode_str[pooling_mode] :
                     "****")));
        }
#endif
#endif
    };
    // Elementwise operation
    struct npu_op_elementwise_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;          //  control
        uint32_t elementwise_mode : 6; //  Elementwise mode
        uint32_t reserved1 : 10;
#ifdef __cplusplus
      public:
        npu_op_elementwise_t(NPU_NAMESPACE::elementwise_mode _elementwise_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_ELEMENTWISE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            elementwise_mode(static_cast<uint8_t>(_elementwise_mode) & ((1U << 6) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_op_elementwise_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_ELEMENTWISE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), elementwise_mode(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_ELEMENTWISE) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_ELEMENTWISE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_elementwise_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_elementwise_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::elementwise_mode get_elementwise_mode() const
        {
            return static_cast<NPU_NAMESPACE::elementwise_mode>(elementwise_mode);
        }
        CONSTEXPR npu_op_elementwise_t &set_elementwise_mode(NPU_NAMESPACE::elementwise_mode value)
        {
            elementwise_mode = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "elementwise_mode",
                (elementwise_mode < (sizeof(elementwise_mode_str) / sizeof(elementwise_mode_str[0])) ?
                     elementwise_mode_str[elementwise_mode] :
                     "****")));
        }
#endif
#endif
    };
    // Queue new DMA for the given channel
    struct npu_op_dma_start_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
#ifdef __cplusplus
      public:
        CONSTEXPR npu_op_dma_start_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_START)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_START) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_START);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_dma_start_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_dma_start_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const {}
#endif
#endif
    };
    // Wait for the DMA channel to have k or fewer active descriptors outstanding
    struct npu_op_dma_wait_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t k : 4;       //  Number of outstanding descriptors
        uint32_t reserved1 : 12;
#ifdef __cplusplus
      public:
        npu_op_dma_wait_t(uint32_t _k) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_WAIT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), k(_k & ((1U << 4) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_op_dma_wait_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_WAIT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), k(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_WAIT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_DMA_WAIT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_dma_wait_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_dma_wait_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_k() const
        {
            return static_cast<uint32_t>(k);
        }
        CONSTEXPR npu_op_dma_wait_t &set_k(uint32_t value)
        {
            k = static_cast<uint8_t>(value) & ((1U << 4) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("k", std::to_string(k)));
        }
#endif
#endif
    };
    // Wait for n or fewer kernel operations to be remaining
    struct npu_op_kernel_wait_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t n : 2;       //  Number of kernel operations in range 0-3
        uint32_t reserved1 : 14;
#ifdef __cplusplus
      public:
        npu_op_kernel_wait_t(uint32_t _n) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_KERNEL_WAIT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), n(_n & ((1U << 2) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_op_kernel_wait_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_KERNEL_WAIT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), n(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_KERNEL_WAIT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_KERNEL_WAIT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_kernel_wait_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_kernel_wait_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_n() const
        {
            return static_cast<uint32_t>(n);
        }
        CONSTEXPR npu_op_kernel_wait_t &set_n(uint32_t value)
        {
            n = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("n", std::to_string(n)));
        }
#endif
#endif
    };
    // Enable or disable PMU counting (debug feature only)
    struct npu_op_pmu_mask_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t enable : 1;  //  Enable or disable PMU mask
        uint32_t reserved1 : 15;
#ifdef __cplusplus
      public:
        npu_op_pmu_mask_t(uint32_t _enable) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_PMU_MASK)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), enable(_enable & ((1U << 1) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_op_pmu_mask_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_PMU_MASK)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), enable(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_PMU_MASK) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_OP_PMU_MASK);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_op_pmu_mask_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_op_pmu_mask_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_enable() const
        {
            return static_cast<uint32_t>(enable);
        }
        CONSTEXPR npu_op_pmu_mask_t &set_enable(uint32_t value)
        {
            enable = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("enable", std::to_string(enable)));
        }
#endif
#endif
    };
    // IFM top pad
    struct npu_set_ifm_pad_top_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t pad : 7;     //  IFM top pad
        uint32_t reserved1 : 9;
#ifdef __cplusplus
      public:
        npu_set_ifm_pad_top_t(uint32_t _pad) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_TOP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(_pad & ((1U << 7) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_pad_top_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_TOP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_TOP) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_TOP);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_pad_top_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_pad_top_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_pad() const
        {
            return static_cast<uint32_t>(pad);
        }
        CONSTEXPR npu_set_ifm_pad_top_t &set_pad(uint32_t value)
        {
            pad = static_cast<uint8_t>(value) & ((1U << 7) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("pad", std::to_string(pad)));
        }
#endif
#endif
    };
    // IFM left pad
    struct npu_set_ifm_pad_left_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t pad : 7;     //  IFM left pad
        uint32_t reserved1 : 9;
#ifdef __cplusplus
      public:
        npu_set_ifm_pad_left_t(uint32_t _pad) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_LEFT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(_pad & ((1U << 7) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_pad_left_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_LEFT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_LEFT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_LEFT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_pad_left_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_pad_left_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_pad() const
        {
            return static_cast<uint32_t>(pad);
        }
        CONSTEXPR npu_set_ifm_pad_left_t &set_pad(uint32_t value)
        {
            pad = static_cast<uint8_t>(value) & ((1U << 7) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("pad", std::to_string(pad)));
        }
#endif
#endif
    };
    // IFM right pad
    struct npu_set_ifm_pad_right_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t pad : 8;     //  IFM right pad. Max value is 128
        uint32_t reserved1 : 8;
#ifdef __cplusplus
      public:
        npu_set_ifm_pad_right_t(uint32_t _pad) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_RIGHT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(_pad & ((1U << 8) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_pad_right_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_RIGHT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_RIGHT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_RIGHT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_pad_right_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_pad_right_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_pad() const
        {
            return static_cast<uint32_t>(pad);
        }
        CONSTEXPR npu_set_ifm_pad_right_t &set_pad(uint32_t value)
        {
            pad = static_cast<uint8_t>(value) & ((1U << 8) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("pad", std::to_string(pad)));
        }
#endif
#endif
    };
    // IFM bottom pad
    struct npu_set_ifm_pad_bottom_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t pad : 8;     //  IFM bottom pad. Max value is 128
        uint32_t reserved1 : 8;
#ifdef __cplusplus
      public:
        npu_set_ifm_pad_bottom_t(uint32_t _pad) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_BOTTOM)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(_pad & ((1U << 8) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_pad_bottom_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_BOTTOM)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), pad(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_BOTTOM) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PAD_BOTTOM);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_pad_bottom_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_pad_bottom_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_pad() const
        {
            return static_cast<uint32_t>(pad);
        }
        CONSTEXPR npu_set_ifm_pad_bottom_t &set_pad(uint32_t value)
        {
            pad = static_cast<uint8_t>(value) & ((1U << 8) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("pad", std::to_string(pad)));
        }
#endif
#endif
    };
    // Number of input channels for convolution
    struct npu_set_ifm_depth_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t depth_m1 : 16; //  Number of input channels for convolution
#ifdef __cplusplus
      public:
        npu_set_ifm_depth_m1_t(uint32_t _depth_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(_depth_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_depth_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_DEPTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_DEPTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_depth_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_depth_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_depth_m1() const
        {
            return static_cast<uint32_t>(depth_m1);
        }
        CONSTEXPR npu_set_ifm_depth_m1_t &set_depth_m1(uint32_t value)
        {
            depth_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("depth_m1", std::to_string(depth_m1)));
        }
#endif
#endif
    };
    // IFM Precision
    struct npu_set_ifm_precision_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;         //  control
        uint32_t activation_type : 1; //  IFM type
        uint32_t reserved1 : 1;
        uint32_t activation_precision : 2; //  IFM precision
        uint32_t reserved2 : 2;
        uint32_t activation_format : 2; //  IFM format
        uint32_t scale_mode : 2;        //  IFM scale mode
        uint32_t reserved3 : 4;
        uint32_t round_mode : 2; //  IFM round mode
#ifdef __cplusplus
      public:
        npu_set_ifm_precision_t(NPU_NAMESPACE::activation_type _activation_type,
                                NPU_NAMESPACE::activation_precision _activation_precision,
                                NPU_NAMESPACE::activation_format _activation_format,
                                NPU_NAMESPACE::ifm_scale_mode _scale_mode,
                                NPU_NAMESPACE::round_mode _round_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PRECISION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            activation_type(static_cast<uint8_t>(_activation_type) & ((1U << 1) - 1)), reserved1(0),
            activation_precision(static_cast<uint8_t>(_activation_precision) & ((1U << 2) - 1)), reserved2(0),
            activation_format(static_cast<uint8_t>(_activation_format) & ((1U << 2) - 1)),
            scale_mode(static_cast<uint8_t>(_scale_mode) & ((1U << 2) - 1)), reserved3(0),
            round_mode(static_cast<uint8_t>(_round_mode) & ((1U << 2) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_precision_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PRECISION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), activation_type(0), reserved1(0),
            activation_precision(0), reserved2(0), activation_format(0), scale_mode(0), reserved3(0), round_mode(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PRECISION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_PRECISION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_type get_activation_type() const
        {
            return static_cast<NPU_NAMESPACE::activation_type>(activation_type);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_activation_type(NPU_NAMESPACE::activation_type value)
        {
            activation_type = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_precision get_activation_precision() const
        {
            return static_cast<NPU_NAMESPACE::activation_precision>(activation_precision);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_activation_precision(NPU_NAMESPACE::activation_precision value)
        {
            activation_precision = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_format get_activation_format() const
        {
            return static_cast<NPU_NAMESPACE::activation_format>(activation_format);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_activation_format(NPU_NAMESPACE::activation_format value)
        {
            activation_format = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::ifm_scale_mode get_scale_mode() const
        {
            return static_cast<NPU_NAMESPACE::ifm_scale_mode>(scale_mode);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_scale_mode(NPU_NAMESPACE::ifm_scale_mode value)
        {
            scale_mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::round_mode get_round_mode() const
        {
            return static_cast<NPU_NAMESPACE::round_mode>(round_mode);
        }
        CONSTEXPR npu_set_ifm_precision_t &set_round_mode(NPU_NAMESPACE::round_mode value)
        {
            round_mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_type",
                (activation_type < (sizeof(activation_type_str) / sizeof(activation_type_str[0])) ?
                     activation_type_str[activation_type] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_precision",
                (activation_precision < (sizeof(activation_precision_str) / sizeof(activation_precision_str[0])) ?
                     activation_precision_str[activation_precision] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_format",
                (activation_format < (sizeof(activation_format_str) / sizeof(activation_format_str[0])) ?
                     activation_format_str[activation_format] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "scale_mode",
                (scale_mode < (sizeof(ifm_scale_mode_str) / sizeof(ifm_scale_mode_str[0])) ?
                     ifm_scale_mode_str[scale_mode] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "round_mode",
                (round_mode < (sizeof(round_mode_str) / sizeof(round_mode_str[0])) ? round_mode_str[round_mode] :
                                                                                     "****")));
        }
#endif
#endif
    };
    // IFM upscale mode
    struct npu_set_ifm_upscale_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t mode : 2;    //  IFM upscale mode
        uint32_t reserved1 : 14;
#ifdef __cplusplus
      public:
        npu_set_ifm_upscale_t(NPU_NAMESPACE::ifm_upscale_mode _mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_UPSCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            mode(static_cast<uint8_t>(_mode) & ((1U << 2) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_upscale_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_UPSCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), mode(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_UPSCALE) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_UPSCALE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_upscale_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_upscale_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::ifm_upscale_mode get_mode() const
        {
            return static_cast<NPU_NAMESPACE::ifm_upscale_mode>(mode);
        }
        CONSTEXPR npu_set_ifm_upscale_t &set_mode(NPU_NAMESPACE::ifm_upscale_mode value)
        {
            mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "mode",
                (mode < (sizeof(ifm_upscale_mode_str) / sizeof(ifm_upscale_mode_str[0])) ? ifm_upscale_mode_str[mode] :
                                                                                           "****")));
        }
#endif
#endif
    };
    // IFM zero point
    struct npu_set_ifm_zero_point_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;     //  control
        uint32_t zero_point : 16; //  Zero point offset
#ifdef __cplusplus
      public:
        npu_set_ifm_zero_point_t(uint32_t _zero_point) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            zero_point(_zero_point & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_zero_point_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), zero_point(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_ZERO_POINT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_ZERO_POINT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_zero_point_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_zero_point_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_zero_point() const
        {
            return static_cast<uint32_t>(zero_point);
        }
        CONSTEXPR npu_set_ifm_zero_point_t &set_zero_point(uint32_t value)
        {
            zero_point = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("zero_point", std::to_string(zero_point)));
        }
#endif
#endif
    };
    // IFM Tile 0 and tile 2 width
    struct npu_set_ifm_width0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t width_m1 : 16; //  IFM Tile 0 and tile 2 width
#ifdef __cplusplus
      public:
        npu_set_ifm_width0_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_width0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_WIDTH0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_WIDTH0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_width0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_width0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_ifm_width0_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // IFM Tile 0 height
    struct npu_set_ifm_height0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  IFM Tile 0 height
#ifdef __cplusplus
      public:
        npu_set_ifm_height0_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_height0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_height0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_height0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ifm_height0_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // IFM Tile 1 height
    struct npu_set_ifm_height1_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  IFM Tile 1 height
#ifdef __cplusplus
      public:
        npu_set_ifm_height1_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm_height1_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT1_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_HEIGHT1_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_height1_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_height1_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ifm_height1_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // End of IB0,IB1 buffers
    struct npu_set_ifm_ib_end_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t ib_end : 6;  //  End of IB0,IB1 buffers in the SHRAM in KB units. Multiple of 2
        uint32_t reserved1 : 10;
#ifdef __cplusplus
      public:
        npu_set_ifm_ib_end_t(uint32_t _ib_end) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_IB_END)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ib_end(_ib_end & ((1U << 6) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_ib_end_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_IB_END)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ib_end(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_IB_END) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_IB_END);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_ib_end_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_ib_end_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_ib_end() const
        {
            return static_cast<uint32_t>(ib_end);
        }
        CONSTEXPR npu_set_ifm_ib_end_t &set_ib_end(uint32_t value)
        {
            ib_end = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("ib_end", std::to_string(ib_end)));
        }
#endif
#endif
    };
    // Index n for IFM access
    struct npu_set_ifm_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Region number n
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_set_ifm_region_t(uint32_t _region) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(_region & ((1U << 3) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_ifm_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
        }
#endif
#endif
    };
    // Output feature map width
    struct npu_set_ofm_width_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t width_m1 : 16; //  Output feature map width
#ifdef __cplusplus
      public:
        npu_set_ofm_width_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_width_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_width_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_width_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_ofm_width_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // Output feature map height
    struct npu_set_ofm_height_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  Output feature map height
#ifdef __cplusplus
      public:
        npu_set_ofm_height_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_height_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_height_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_height_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ofm_height_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // Output feature map depth
    struct npu_set_ofm_depth_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t depth_m1 : 16; //  Output feature map depth
#ifdef __cplusplus
      public:
        npu_set_ofm_depth_m1_t(uint32_t _depth_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(_depth_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_depth_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_DEPTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_DEPTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_depth_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_depth_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_depth_m1() const
        {
            return static_cast<uint32_t>(depth_m1);
        }
        CONSTEXPR npu_set_ofm_depth_m1_t &set_depth_m1(uint32_t value)
        {
            depth_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("depth_m1", std::to_string(depth_m1)));
        }
#endif
#endif
    };
    // OFM Precision
    struct npu_set_ofm_precision_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;              //  control
        uint32_t activation_type : 1;      //  OFM type
        uint32_t activation_precision : 2; //  OFM precision
        uint32_t reserved1 : 3;
        uint32_t activation_format : 2; //  OFM format
        uint32_t scale_mode : 1;        //  OFM scale mode
        uint32_t reserved2 : 5;
        uint32_t round_mode : 2; //  OFM round mode
#ifdef __cplusplus
      public:
        npu_set_ofm_precision_t(NPU_NAMESPACE::activation_type _activation_type,
                                NPU_NAMESPACE::activation_precision _activation_precision,
                                NPU_NAMESPACE::activation_format _activation_format,
                                NPU_NAMESPACE::ofm_scale_mode _scale_mode,
                                NPU_NAMESPACE::round_mode _round_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_PRECISION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            activation_type(static_cast<uint8_t>(_activation_type) & ((1U << 1) - 1)),
            activation_precision(static_cast<uint8_t>(_activation_precision) & ((1U << 2) - 1)), reserved1(0),
            activation_format(static_cast<uint8_t>(_activation_format) & ((1U << 2) - 1)),
            scale_mode(static_cast<uint8_t>(_scale_mode) & ((1U << 1) - 1)), reserved2(0),
            round_mode(static_cast<uint8_t>(_round_mode) & ((1U << 2) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_precision_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_PRECISION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), activation_type(0),
            activation_precision(0), reserved1(0), activation_format(0), scale_mode(0), reserved2(0), round_mode(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_PRECISION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_PRECISION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_type get_activation_type() const
        {
            return static_cast<NPU_NAMESPACE::activation_type>(activation_type);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_activation_type(NPU_NAMESPACE::activation_type value)
        {
            activation_type = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_precision get_activation_precision() const
        {
            return static_cast<NPU_NAMESPACE::activation_precision>(activation_precision);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_activation_precision(NPU_NAMESPACE::activation_precision value)
        {
            activation_precision = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_format get_activation_format() const
        {
            return static_cast<NPU_NAMESPACE::activation_format>(activation_format);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_activation_format(NPU_NAMESPACE::activation_format value)
        {
            activation_format = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::ofm_scale_mode get_scale_mode() const
        {
            return static_cast<NPU_NAMESPACE::ofm_scale_mode>(scale_mode);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_scale_mode(NPU_NAMESPACE::ofm_scale_mode value)
        {
            scale_mode = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::round_mode get_round_mode() const
        {
            return static_cast<NPU_NAMESPACE::round_mode>(round_mode);
        }
        CONSTEXPR npu_set_ofm_precision_t &set_round_mode(NPU_NAMESPACE::round_mode value)
        {
            round_mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_type",
                (activation_type < (sizeof(activation_type_str) / sizeof(activation_type_str[0])) ?
                     activation_type_str[activation_type] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_precision",
                (activation_precision < (sizeof(activation_precision_str) / sizeof(activation_precision_str[0])) ?
                     activation_precision_str[activation_precision] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_format",
                (activation_format < (sizeof(activation_format_str) / sizeof(activation_format_str[0])) ?
                     activation_format_str[activation_format] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "scale_mode",
                (scale_mode < (sizeof(ofm_scale_mode_str) / sizeof(ofm_scale_mode_str[0])) ?
                     ofm_scale_mode_str[scale_mode] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "round_mode",
                (round_mode < (sizeof(round_mode_str) / sizeof(round_mode_str[0])) ? round_mode_str[round_mode] :
                                                                                     "****")));
        }
#endif
#endif
    };
    // OFM block width
    struct npu_set_ofm_blk_width_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;  //  control
        uint32_t width_m1 : 6; //  OFM block width
        uint32_t reserved1 : 10;
#ifdef __cplusplus
      public:
        npu_set_ofm_blk_width_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 6) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ofm_blk_width_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_WIDTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_WIDTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_blk_width_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_blk_width_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_ofm_blk_width_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // OFM block height
    struct npu_set_ofm_blk_height_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t height_m1 : 5; //  OFM block height
        uint32_t reserved1 : 11;
#ifdef __cplusplus
      public:
        npu_set_ofm_blk_height_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 5) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ofm_blk_height_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_HEIGHT_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_HEIGHT_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_blk_height_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_blk_height_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ofm_blk_height_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint8_t>(value) & ((1U << 5) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // OFM block depth
    struct npu_set_ofm_blk_depth_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;  //  control
        uint32_t depth_m1 : 7; //  OFM block depth
        uint32_t reserved1 : 9;
#ifdef __cplusplus
      public:
        npu_set_ofm_blk_depth_m1_t(uint32_t _depth_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(_depth_m1 & ((1U << 7) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ofm_blk_depth_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_DEPTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), depth_m1(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_DEPTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_BLK_DEPTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_blk_depth_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_blk_depth_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_depth_m1() const
        {
            return static_cast<uint32_t>(depth_m1);
        }
        CONSTEXPR npu_set_ofm_blk_depth_m1_t &set_depth_m1(uint32_t value)
        {
            depth_m1 = static_cast<uint8_t>(value) & ((1U << 7) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("depth_m1", std::to_string(depth_m1)));
        }
#endif
#endif
    };
    // OFM zero point
    struct npu_set_ofm_zero_point_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;     //  control
        uint32_t zero_point : 16; //  Zero point offset
#ifdef __cplusplus
      public:
        npu_set_ofm_zero_point_t(uint32_t _zero_point) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            zero_point(_zero_point & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_zero_point_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), zero_point(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_ZERO_POINT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_ZERO_POINT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_zero_point_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_zero_point_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_zero_point() const
        {
            return static_cast<uint32_t>(zero_point);
        }
        CONSTEXPR npu_set_ofm_zero_point_t &set_zero_point(uint32_t value)
        {
            zero_point = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("zero_point", std::to_string(zero_point)));
        }
#endif
#endif
    };
    // OFM Tile 0 and tile 2 width
    struct npu_set_ofm_width0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t width_m1 : 16; //  OFM Tile 0 and tile 2 width
#ifdef __cplusplus
      public:
        npu_set_ofm_width0_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_width0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_WIDTH0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_width0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_width0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_ofm_width0_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // OFM Tile 0 height
    struct npu_set_ofm_height0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  OFM Tile 0 height
#ifdef __cplusplus
      public:
        npu_set_ofm_height0_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_height0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_height0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_height0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ofm_height0_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // OFM Tile 1 height
    struct npu_set_ofm_height1_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  OFM Tile 1 height
#ifdef __cplusplus
      public:
        npu_set_ofm_height1_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ofm_height1_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT1_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_HEIGHT1_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_height1_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_height1_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ofm_height1_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // Index n for OFM access
    struct npu_set_ofm_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Index n for OFM access
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_set_ofm_region_t(uint32_t _region) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(_region & ((1U << 3) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ofm_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_OFM_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_ofm_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
        }
#endif
#endif
    };
    // Kernel width
    struct npu_set_kernel_width_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t width_m1 : 16; //  Kernel width
#ifdef __cplusplus
      public:
        npu_set_kernel_width_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_kernel_width_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_WIDTH_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_WIDTH_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_WIDTH_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_kernel_width_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_kernel_width_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_kernel_width_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // Kernel height
    struct npu_set_kernel_height_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  Kernel height
#ifdef __cplusplus
      public:
        npu_set_kernel_height_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_kernel_height_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_HEIGHT_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_HEIGHT_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_HEIGHT_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_kernel_height_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_kernel_height_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_kernel_height_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // Kernel stride
    struct npu_set_kernel_stride_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;       //  control
        uint32_t stride_x_lsb : 1;  //  Stride x LSB. (kernel_x_stride - 1)[0]
        uint32_t stride_y_lsb : 1;  //  Stride y LSB. (kernel_y_stride - 1)[0]
        uint32_t weight_order : 1;  //  Weight ordering mode
        uint32_t dilation_x : 1;    //  Kernel x dilation
        uint32_t dilation_y : 1;    //  Kernel y dilation
        uint32_t decomposition : 1; //  Kernel decomposition
        uint32_t stride_x_msb : 1;  //  Stride x MSB. (kernel_x_stride - 1) >> 1
        uint32_t reserved1 : 2;
        uint32_t stride_y_msb : 1; //  Stride y MSB. (kernel_y_stride - 1) >> 1
        uint32_t reserved2 : 6;
#ifdef __cplusplus
      public:
        npu_set_kernel_stride_t(uint32_t _stride_x_lsb,
                                uint32_t _stride_y_lsb,
                                NPU_NAMESPACE::weight_order _weight_order,
                                NPU_NAMESPACE::kernel_dilation _dilation_x,
                                NPU_NAMESPACE::kernel_dilation _dilation_y,
                                NPU_NAMESPACE::kernel_decomposition _decomposition,
                                uint32_t _stride_x_msb,
                                uint32_t _stride_y_msb) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_STRIDE)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            stride_x_lsb(_stride_x_lsb & ((1U << 1) - 1)), stride_y_lsb(_stride_y_lsb & ((1U << 1) - 1)),
            weight_order(static_cast<uint8_t>(_weight_order) & ((1U << 1) - 1)),
            dilation_x(static_cast<uint8_t>(_dilation_x) & ((1U << 1) - 1)),
            dilation_y(static_cast<uint8_t>(_dilation_y) & ((1U << 1) - 1)),
            decomposition(static_cast<uint8_t>(_decomposition) & ((1U << 1) - 1)),
            stride_x_msb(_stride_x_msb & ((1U << 1) - 1)), reserved1(0), stride_y_msb(_stride_y_msb & ((1U << 1) - 1)),
            reserved2(0)
        {
        }
        CONSTEXPR npu_set_kernel_stride_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_STRIDE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), stride_x_lsb(0), stride_y_lsb(0),
            weight_order(0), dilation_x(0), dilation_y(0), decomposition(0), stride_x_msb(0), reserved1(0),
            stride_y_msb(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_STRIDE) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_KERNEL_STRIDE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_stride_x_lsb() const
        {
            return static_cast<uint32_t>(stride_x_lsb);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_stride_x_lsb(uint32_t value)
        {
            stride_x_lsb = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_stride_y_lsb() const
        {
            return static_cast<uint32_t>(stride_y_lsb);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_stride_y_lsb(uint32_t value)
        {
            stride_y_lsb = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::weight_order get_weight_order() const
        {
            return static_cast<NPU_NAMESPACE::weight_order>(weight_order);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_weight_order(NPU_NAMESPACE::weight_order value)
        {
            weight_order = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::kernel_dilation get_dilation_x() const
        {
            return static_cast<NPU_NAMESPACE::kernel_dilation>(dilation_x);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_dilation_x(NPU_NAMESPACE::kernel_dilation value)
        {
            dilation_x = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::kernel_dilation get_dilation_y() const
        {
            return static_cast<NPU_NAMESPACE::kernel_dilation>(dilation_y);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_dilation_y(NPU_NAMESPACE::kernel_dilation value)
        {
            dilation_y = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::kernel_decomposition get_decomposition() const
        {
            return static_cast<NPU_NAMESPACE::kernel_decomposition>(decomposition);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_decomposition(NPU_NAMESPACE::kernel_decomposition value)
        {
            decomposition = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_stride_x_msb() const
        {
            return static_cast<uint32_t>(stride_x_msb);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_stride_x_msb(uint32_t value)
        {
            stride_x_msb = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_stride_y_msb() const
        {
            return static_cast<uint32_t>(stride_y_msb);
        }
        CONSTEXPR npu_set_kernel_stride_t &set_stride_y_msb(uint32_t value)
        {
            stride_y_msb = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("stride_x_lsb", std::to_string(stride_x_lsb)));
            fields.push_back(std::make_pair<std::string, std::string>("stride_y_lsb", std::to_string(stride_y_lsb)));
            fields.push_back(std::make_pair<std::string, std::string>(
                "weight_order",
                (weight_order < (sizeof(weight_order_str) / sizeof(weight_order_str[0])) ?
                     weight_order_str[weight_order] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "dilation_x",
                (dilation_x < (sizeof(kernel_dilation_str) / sizeof(kernel_dilation_str[0])) ?
                     kernel_dilation_str[dilation_x] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "dilation_y",
                (dilation_y < (sizeof(kernel_dilation_str) / sizeof(kernel_dilation_str[0])) ?
                     kernel_dilation_str[dilation_y] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "decomposition",
                (decomposition < (sizeof(kernel_decomposition_str) / sizeof(kernel_decomposition_str[0])) ?
                     kernel_decomposition_str[decomposition] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>("stride_x_msb", std::to_string(stride_x_msb)));
            fields.push_back(std::make_pair<std::string, std::string>("stride_y_msb", std::to_string(stride_y_msb)));
        }
#endif
#endif
    };
    // Multi-core parallel mode
    struct npu_set_parallel_mode_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;       //  control
        uint32_t parallel_mode : 1; //  Multi-core parallel mode
        uint32_t reserved1 : 15;
#ifdef __cplusplus
      public:
        npu_set_parallel_mode_t(NPU_NAMESPACE::parallel_mode _parallel_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_PARALLEL_MODE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            parallel_mode(static_cast<uint8_t>(_parallel_mode) & ((1U << 1) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_parallel_mode_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_PARALLEL_MODE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), parallel_mode(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_PARALLEL_MODE) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_PARALLEL_MODE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_parallel_mode_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_parallel_mode_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::parallel_mode get_parallel_mode() const
        {
            return static_cast<NPU_NAMESPACE::parallel_mode>(parallel_mode);
        }
        CONSTEXPR npu_set_parallel_mode_t &set_parallel_mode(NPU_NAMESPACE::parallel_mode value)
        {
            parallel_mode = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "parallel_mode",
                (parallel_mode < (sizeof(parallel_mode_str) / sizeof(parallel_mode_str[0])) ?
                     parallel_mode_str[parallel_mode] :
                     "****")));
        }
#endif
#endif
    };
    // Accumulator format
    struct npu_set_acc_format_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t acc_format : 2; //  Accumulator format
        uint32_t reserved1 : 14;
#ifdef __cplusplus
      public:
        npu_set_acc_format_t(NPU_NAMESPACE::acc_format _acc_format) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACC_FORMAT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            acc_format(static_cast<uint8_t>(_acc_format) & ((1U << 2) - 1)), reserved1(0)
        {
        }
        CONSTEXPR npu_set_acc_format_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACC_FORMAT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), acc_format(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACC_FORMAT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACC_FORMAT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_acc_format_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_acc_format_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::acc_format get_acc_format() const
        {
            return static_cast<NPU_NAMESPACE::acc_format>(acc_format);
        }
        CONSTEXPR npu_set_acc_format_t &set_acc_format(NPU_NAMESPACE::acc_format value)
        {
            acc_format = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "acc_format",
                (acc_format < (sizeof(acc_format_str) / sizeof(acc_format_str[0])) ? acc_format_str[acc_format] :
                                                                                     "****")));
        }
#endif
#endif
    };
    // Activation function and clip range
    struct npu_set_activation_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;             //  control
        uint32_t activation_function : 5; //  Activation function (before table lookup)
        uint32_t reserved1 : 7;
        uint32_t activation_clip_range : 3; //  Activation clip range. This must be set to 0 if table lookup is not used
        uint32_t reserved2 : 1;
#ifdef __cplusplus
      public:
        npu_set_activation_t(NPU_NAMESPACE::activation_function _activation_function,
                             NPU_NAMESPACE::activation_clip_range _activation_clip_range) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            activation_function(static_cast<uint8_t>(_activation_function) & ((1U << 5) - 1)), reserved1(0),
            activation_clip_range(static_cast<uint8_t>(_activation_clip_range) & ((1U << 3) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_activation_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), activation_function(0), reserved1(0),
            activation_clip_range(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_activation_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_activation_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_function get_activation_function() const
        {
            return static_cast<NPU_NAMESPACE::activation_function>(activation_function);
        }
        CONSTEXPR npu_set_activation_t &set_activation_function(NPU_NAMESPACE::activation_function value)
        {
            activation_function = static_cast<uint8_t>(value) & ((1U << 5) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_clip_range get_activation_clip_range() const
        {
            return static_cast<NPU_NAMESPACE::activation_clip_range>(activation_clip_range);
        }
        CONSTEXPR npu_set_activation_t &set_activation_clip_range(NPU_NAMESPACE::activation_clip_range value)
        {
            activation_clip_range = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_function",
                (activation_function < (sizeof(activation_function_str) / sizeof(activation_function_str[0])) ?
                     activation_function_str[activation_function] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_clip_range",
                (activation_clip_range < (sizeof(activation_clip_range_str) / sizeof(activation_clip_range_str[0])) ?
                     activation_clip_range_str[activation_clip_range] :
                     "****")));
        }
#endif
#endif
    };
    // Lower bound clip
    struct npu_set_activation_min_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;        //  control
        uint32_t clip_boundary : 16; //  Clip boundary for OFM activations
#ifdef __cplusplus
      public:
        npu_set_activation_min_t(uint32_t _clip_boundary) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MIN)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            clip_boundary(_clip_boundary & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_activation_min_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MIN)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), clip_boundary(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MIN) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MIN);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_activation_min_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_activation_min_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_clip_boundary() const
        {
            return static_cast<uint32_t>(clip_boundary);
        }
        CONSTEXPR npu_set_activation_min_t &set_clip_boundary(uint32_t value)
        {
            clip_boundary = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("clip_boundary", std::to_string(clip_boundary)));
        }
#endif
#endif
    };
    // Upper bound clip
    struct npu_set_activation_max_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;        //  control
        uint32_t clip_boundary : 16; //  Clip boundary for OFM activations
#ifdef __cplusplus
      public:
        npu_set_activation_max_t(uint32_t _clip_boundary) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MAX)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            clip_boundary(_clip_boundary & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_activation_max_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MAX)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), clip_boundary(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MAX) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_ACTIVATION_MAX);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_activation_max_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_activation_max_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_clip_boundary() const
        {
            return static_cast<uint32_t>(clip_boundary);
        }
        CONSTEXPR npu_set_activation_max_t &set_clip_boundary(uint32_t value)
        {
            clip_boundary = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("clip_boundary", std::to_string(clip_boundary)));
        }
#endif
#endif
    };
    // Index n for weight stream access
    struct npu_set_weight_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Index n for weight stream access
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_set_weight_region_t(uint32_t _region) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_WEIGHT_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(_region & ((1U << 3) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_weight_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_WEIGHT_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_WEIGHT_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_WEIGHT_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_weight_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_weight_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_weight_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
        }
#endif
#endif
    };
    // Index n for scale stream access
    struct npu_set_scale_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Index n for scale stream access
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_set_scale_region_t(uint32_t _region) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_SCALE_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(_region & ((1U << 3) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_scale_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_SCALE_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_SCALE_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_SCALE_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_scale_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_scale_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_scale_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
        }
#endif
#endif
    };
    // Start of ACC0,ACC1 buffers
    struct npu_set_ab_start_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;  //  control
        uint32_t ab_start : 6; //  Start of ACC0,ACC1 buffers in the SHRAM in KB units. Multiple of 2
        uint32_t reserved1 : 10;
#ifdef __cplusplus
      public:
        npu_set_ab_start_t(uint32_t _ab_start) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_AB_START)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ab_start(_ab_start & ((1U << 6) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ab_start_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_AB_START)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ab_start(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_AB_START) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_AB_START);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ab_start_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ab_start_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_ab_start() const
        {
            return static_cast<uint32_t>(ab_start);
        }
        CONSTEXPR npu_set_ab_start_t &set_ab_start(uint32_t value)
        {
            ab_start = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("ab_start", std::to_string(ab_start)));
        }
#endif
#endif
    };
    // Block number of blocks dependency
    struct npu_set_blockdep_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;  //  control
        uint32_t blockdep : 2; //  Block number of blocks dependency between kernel operations
        uint32_t reserved1 : 14;
#ifdef __cplusplus
      public:
        npu_set_blockdep_t(uint32_t _blockdep) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_BLOCKDEP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), blockdep(_blockdep & ((1U << 2) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_blockdep_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_BLOCKDEP)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), blockdep(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_BLOCKDEP) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_BLOCKDEP);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_blockdep_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_blockdep_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_blockdep() const
        {
            return static_cast<uint32_t>(blockdep);
        }
        CONSTEXPR npu_set_blockdep_t &set_blockdep(uint32_t value)
        {
            blockdep = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("blockdep", std::to_string(blockdep)));
        }
#endif
#endif
    };
    // DMA0 source region
    struct npu_set_dma0_src_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Region number
        uint32_t reserved1 : 5;
        uint32_t region_mode : 1; //  Region mode
        uint32_t stride_mode : 2; //  Stride mode
        uint32_t reserved2 : 5;
#ifdef __cplusplus
      public:
        npu_set_dma0_src_region_t(uint32_t _region,
                                  NPU_NAMESPACE::dma_region_mode _region_mode,
                                  NPU_NAMESPACE::dma_stride_mode _stride_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SRC_REGION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            region(_region & ((1U << 3) - 1)), reserved1(0),
            region_mode(static_cast<uint8_t>(_region_mode) & ((1U << 1) - 1)),
            stride_mode(static_cast<uint8_t>(_stride_mode) & ((1U << 2) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_dma0_src_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SRC_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0), region_mode(0),
            stride_mode(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SRC_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SRC_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_dma0_src_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_dma0_src_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_dma0_src_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::dma_region_mode get_region_mode() const
        {
            return static_cast<NPU_NAMESPACE::dma_region_mode>(region_mode);
        }
        CONSTEXPR npu_set_dma0_src_region_t &set_region_mode(NPU_NAMESPACE::dma_region_mode value)
        {
            region_mode = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::dma_stride_mode get_stride_mode() const
        {
            return static_cast<NPU_NAMESPACE::dma_stride_mode>(stride_mode);
        }
        CONSTEXPR npu_set_dma0_src_region_t &set_stride_mode(NPU_NAMESPACE::dma_stride_mode value)
        {
            stride_mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
            fields.push_back(std::make_pair<std::string, std::string>(
                "region_mode",
                (region_mode < (sizeof(dma_region_mode_str) / sizeof(dma_region_mode_str[0])) ?
                     dma_region_mode_str[region_mode] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "stride_mode",
                (stride_mode < (sizeof(dma_stride_mode_str) / sizeof(dma_stride_mode_str[0])) ?
                     dma_stride_mode_str[stride_mode] :
                     "****")));
        }
#endif
#endif
    };
    // DMA0 destination region
    struct npu_set_dma0_dst_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3; //  Region number if region_mode is region_mode_external. Else core mask to write to (bit k
                             //  set for core k=0,1)
        uint32_t reserved1 : 5;
        uint32_t region_mode : 1; //  Region mode
        uint32_t stride_mode : 2; //  Stride mode
        uint32_t reserved2 : 5;
#ifdef __cplusplus
      public:
        npu_set_dma0_dst_region_t(uint32_t _region,
                                  NPU_NAMESPACE::dma_region_mode _region_mode,
                                  NPU_NAMESPACE::dma_stride_mode _stride_mode) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_DST_REGION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            region(_region & ((1U << 3) - 1)), reserved1(0),
            region_mode(static_cast<uint8_t>(_region_mode) & ((1U << 1) - 1)),
            stride_mode(static_cast<uint8_t>(_stride_mode) & ((1U << 2) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_dma0_dst_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_DST_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0), region_mode(0),
            stride_mode(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_DST_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_DST_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_dma0_dst_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_dma0_dst_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_dma0_dst_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::dma_region_mode get_region_mode() const
        {
            return static_cast<NPU_NAMESPACE::dma_region_mode>(region_mode);
        }
        CONSTEXPR npu_set_dma0_dst_region_t &set_region_mode(NPU_NAMESPACE::dma_region_mode value)
        {
            region_mode = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::dma_stride_mode get_stride_mode() const
        {
            return static_cast<NPU_NAMESPACE::dma_stride_mode>(stride_mode);
        }
        CONSTEXPR npu_set_dma0_dst_region_t &set_stride_mode(NPU_NAMESPACE::dma_stride_mode value)
        {
            stride_mode = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
            fields.push_back(std::make_pair<std::string, std::string>(
                "region_mode",
                (region_mode < (sizeof(dma_region_mode_str) / sizeof(dma_region_mode_str[0])) ?
                     dma_region_mode_str[region_mode] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "stride_mode",
                (stride_mode < (sizeof(dma_stride_mode_str) / sizeof(dma_stride_mode_str[0])) ?
                     dma_stride_mode_str[stride_mode] :
                     "****")));
        }
#endif
#endif
    };
    // Size of second dimension for 2D/3D transfers
    struct npu_set_dma0_size0_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t size : 16;   //  Size of second dimension for 2D/3D transfers
#ifdef __cplusplus
      public:
        npu_set_dma0_size0_t(uint32_t _size) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), size(_size & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_dma0_size0_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), size(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE0) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE0);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_dma0_size0_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_dma0_size0_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_size() const
        {
            return static_cast<uint32_t>(size);
        }
        CONSTEXPR npu_set_dma0_size0_t &set_size(uint32_t value)
        {
            size = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("size", std::to_string(size)));
        }
#endif
#endif
    };
    // Size of third dimension for 3D transfers
    struct npu_set_dma0_size1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t size : 16;   //  Size of third dimension for 3D transfers
#ifdef __cplusplus
      public:
        npu_set_dma0_size1_t(uint32_t _size) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), size(_size & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_dma0_size1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), size(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_DMA0_SIZE1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_dma0_size1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_dma0_size1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_size() const
        {
            return static_cast<uint32_t>(size);
        }
        CONSTEXPR npu_set_dma0_size1_t &set_size(uint32_t value)
        {
            size = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("size", std::to_string(size)));
        }
#endif
#endif
    };
    // IFM2 broadcast configuration
    struct npu_set_ifm2_broadcast_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t
            broadcast_h : 1; //  Broadcast H dimension (if set then any accesses to IFM2 sets y=0 and IFM2 height=1)
        uint32_t broadcast_w : 1; //  Broadcast W dimension (if set then any accesses to IFM2 sets x=0 and IFM2 width=1)
        uint32_t broadcast_c : 1; //  Broadcast C dimension (if set then any accesses to IFM2 sets c=0 and IFM2 depth=1)
        uint32_t reserved1 : 3;
        uint32_t operand_order : 1;      //  Operand order
        uint32_t broadcast_constant : 1; //  Broadcast constant given by NPU_SET_IFM2_SCALAR and so ignore BH, BW and BC
        uint32_t reserved2 : 8;
#ifdef __cplusplus
      public:
        npu_set_ifm2_broadcast_t(NPU_NAMESPACE::broadcast_mode _broadcast_h,
                                 NPU_NAMESPACE::broadcast_mode _broadcast_w,
                                 NPU_NAMESPACE::broadcast_mode _broadcast_c,
                                 NPU_NAMESPACE::ifm2_operand_order _operand_order,
                                 NPU_NAMESPACE::broadcast_mode _broadcast_constant) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_BROADCAST)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            broadcast_h(static_cast<uint8_t>(_broadcast_h) & ((1U << 1) - 1)),
            broadcast_w(static_cast<uint8_t>(_broadcast_w) & ((1U << 1) - 1)),
            broadcast_c(static_cast<uint8_t>(_broadcast_c) & ((1U << 1) - 1)), reserved1(0),
            operand_order(static_cast<uint8_t>(_operand_order) & ((1U << 1) - 1)),
            broadcast_constant(static_cast<uint8_t>(_broadcast_constant) & ((1U << 1) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_ifm2_broadcast_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_BROADCAST)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), broadcast_h(0), broadcast_w(0),
            broadcast_c(0), reserved1(0), operand_order(0), broadcast_constant(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_BROADCAST) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_BROADCAST);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::broadcast_mode get_broadcast_h() const
        {
            return static_cast<NPU_NAMESPACE::broadcast_mode>(broadcast_h);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_broadcast_h(NPU_NAMESPACE::broadcast_mode value)
        {
            broadcast_h = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::broadcast_mode get_broadcast_w() const
        {
            return static_cast<NPU_NAMESPACE::broadcast_mode>(broadcast_w);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_broadcast_w(NPU_NAMESPACE::broadcast_mode value)
        {
            broadcast_w = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::broadcast_mode get_broadcast_c() const
        {
            return static_cast<NPU_NAMESPACE::broadcast_mode>(broadcast_c);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_broadcast_c(NPU_NAMESPACE::broadcast_mode value)
        {
            broadcast_c = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::ifm2_operand_order get_operand_order() const
        {
            return static_cast<NPU_NAMESPACE::ifm2_operand_order>(operand_order);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_operand_order(NPU_NAMESPACE::ifm2_operand_order value)
        {
            operand_order = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::broadcast_mode get_broadcast_constant() const
        {
            return static_cast<NPU_NAMESPACE::broadcast_mode>(broadcast_constant);
        }
        CONSTEXPR npu_set_ifm2_broadcast_t &set_broadcast_constant(NPU_NAMESPACE::broadcast_mode value)
        {
            broadcast_constant = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "broadcast_h",
                (broadcast_h < (sizeof(broadcast_mode_str) / sizeof(broadcast_mode_str[0])) ?
                     broadcast_mode_str[broadcast_h] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "broadcast_w",
                (broadcast_w < (sizeof(broadcast_mode_str) / sizeof(broadcast_mode_str[0])) ?
                     broadcast_mode_str[broadcast_w] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "broadcast_c",
                (broadcast_c < (sizeof(broadcast_mode_str) / sizeof(broadcast_mode_str[0])) ?
                     broadcast_mode_str[broadcast_c] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "operand_order",
                (operand_order < (sizeof(ifm2_operand_order_str) / sizeof(ifm2_operand_order_str[0])) ?
                     ifm2_operand_order_str[operand_order] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "broadcast_constant",
                (broadcast_constant < (sizeof(broadcast_mode_str) / sizeof(broadcast_mode_str[0])) ?
                     broadcast_mode_str[broadcast_constant] :
                     "****")));
        }
#endif
#endif
    };
    // IFM2 scalar value
    struct npu_set_ifm2_scalar_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t scalar : 16; //  int16 or uint16 depending on ifm2_precision.type
#ifdef __cplusplus
      public:
        npu_set_ifm2_scalar_t(uint32_t _scalar) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_SCALAR)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), scalar(_scalar & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm2_scalar_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_SCALAR)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), scalar(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_SCALAR) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_SCALAR);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_scalar_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_scalar_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_scalar() const
        {
            return static_cast<uint32_t>(scalar);
        }
        CONSTEXPR npu_set_ifm2_scalar_t &set_scalar(uint32_t value)
        {
            scalar = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("scalar", std::to_string(scalar)));
        }
#endif
#endif
    };
    // IFM2 Precision
    struct npu_set_ifm2_precision_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;         //  control
        uint32_t activation_type : 1; //  IFM type - MUST MATCH IFM
        uint32_t reserved1 : 1;
        uint32_t activation_precision : 2; //  IFM precision - MUST MATCH IFM
        uint32_t reserved2 : 2;
        uint32_t activation_format : 2; //  IFM format
        uint32_t reserved3 : 8;
#ifdef __cplusplus
      public:
        npu_set_ifm2_precision_t(NPU_NAMESPACE::activation_type _activation_type,
                                 NPU_NAMESPACE::activation_precision _activation_precision,
                                 NPU_NAMESPACE::activation_format _activation_format) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_PRECISION)),
            reserved0(0), control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            activation_type(static_cast<uint8_t>(_activation_type) & ((1U << 1) - 1)), reserved1(0),
            activation_precision(static_cast<uint8_t>(_activation_precision) & ((1U << 2) - 1)), reserved2(0),
            activation_format(static_cast<uint8_t>(_activation_format) & ((1U << 2) - 1)), reserved3(0)
        {
        }
        CONSTEXPR npu_set_ifm2_precision_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_PRECISION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), activation_type(0), reserved1(0),
            activation_precision(0), reserved2(0), activation_format(0), reserved3(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_PRECISION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_PRECISION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_precision_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_precision_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_type get_activation_type() const
        {
            return static_cast<NPU_NAMESPACE::activation_type>(activation_type);
        }
        CONSTEXPR npu_set_ifm2_precision_t &set_activation_type(NPU_NAMESPACE::activation_type value)
        {
            activation_type = static_cast<uint8_t>(value) & ((1U << 1) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_precision get_activation_precision() const
        {
            return static_cast<NPU_NAMESPACE::activation_precision>(activation_precision);
        }
        CONSTEXPR npu_set_ifm2_precision_t &set_activation_precision(NPU_NAMESPACE::activation_precision value)
        {
            activation_precision = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::activation_format get_activation_format() const
        {
            return static_cast<NPU_NAMESPACE::activation_format>(activation_format);
        }
        CONSTEXPR npu_set_ifm2_precision_t &set_activation_format(NPU_NAMESPACE::activation_format value)
        {
            activation_format = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_type",
                (activation_type < (sizeof(activation_type_str) / sizeof(activation_type_str[0])) ?
                     activation_type_str[activation_type] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_precision",
                (activation_precision < (sizeof(activation_precision_str) / sizeof(activation_precision_str[0])) ?
                     activation_precision_str[activation_precision] :
                     "****")));
            fields.push_back(std::make_pair<std::string, std::string>(
                "activation_format",
                (activation_format < (sizeof(activation_format_str) / sizeof(activation_format_str[0])) ?
                     activation_format_str[activation_format] :
                     "****")));
        }
#endif
#endif
    };
    // IFM2 zero point
    struct npu_set_ifm2_zero_point_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;     //  control
        uint32_t zero_point : 16; //  Zero point offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_zero_point_t(uint32_t _zero_point) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)),
            zero_point(_zero_point & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm2_zero_point_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_ZERO_POINT)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), zero_point(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_ZERO_POINT) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_ZERO_POINT);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_zero_point_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_zero_point_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_zero_point() const
        {
            return static_cast<uint32_t>(zero_point);
        }
        CONSTEXPR npu_set_ifm2_zero_point_t &set_zero_point(uint32_t value)
        {
            zero_point = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("zero_point", std::to_string(zero_point)));
        }
#endif
#endif
    };
    // IFM2 Tile 0 and tile 2 width
    struct npu_set_ifm2_width0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;   //  control
        uint32_t width_m1 : 16; //  IFM2 Tile 0 and tile 2 width
#ifdef __cplusplus
      public:
        npu_set_ifm2_width0_m1_t(uint32_t _width_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(_width_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm2_width0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_WIDTH0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), width_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_WIDTH0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_WIDTH0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_width0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_width0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_width_m1() const
        {
            return static_cast<uint32_t>(width_m1);
        }
        CONSTEXPR npu_set_ifm2_width0_m1_t &set_width_m1(uint32_t value)
        {
            width_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("width_m1", std::to_string(width_m1)));
        }
#endif
#endif
    };
    // IFM2 Tile 0 height
    struct npu_set_ifm2_height0_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  IFM2 Tile 0 height
#ifdef __cplusplus
      public:
        npu_set_ifm2_height0_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm2_height0_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT0_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT0_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT0_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_height0_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_height0_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ifm2_height0_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // IFM2 Tile 1 height
    struct npu_set_ifm2_height1_m1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;    //  control
        uint32_t height_m1 : 16; //  IFM2 Tile 1 height
#ifdef __cplusplus
      public:
        npu_set_ifm2_height1_m1_t(uint32_t _height_m1) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(_height_m1 & ((1U << 16) - 1))
        {
        }
        CONSTEXPR npu_set_ifm2_height1_m1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT1_M1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), height_m1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT1_M1) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_HEIGHT1_M1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_height1_m1_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_height1_m1_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_height_m1() const
        {
            return static_cast<uint32_t>(height_m1);
        }
        CONSTEXPR npu_set_ifm2_height1_m1_t &set_height_m1(uint32_t value)
        {
            height_m1 = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("height_m1", std::to_string(height_m1)));
        }
#endif
#endif
    };
    // Start of IB0,IB1 buffers for IFM2
    struct npu_set_ifm2_ib_start_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2;  //  control
        uint32_t ib_start : 6; //  Start of IB0,IB1 buffers for IFM2 in the SHRAM in KB units. Multiple of 2
        uint32_t reserved1 : 10;
#ifdef __cplusplus
      public:
        npu_set_ifm2_ib_start_t(uint32_t _ib_start) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_IB_START)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ib_start(_ib_start & ((1U << 6) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm2_ib_start_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_IB_START)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), ib_start(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_IB_START) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_IB_START);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_ib_start_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_ib_start_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_ib_start() const
        {
            return static_cast<uint32_t>(ib_start);
        }
        CONSTEXPR npu_set_ifm2_ib_start_t &set_ib_start(uint32_t value)
        {
            ib_start = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("ib_start", std::to_string(ib_start)));
        }
#endif
#endif
    };
    // Index n for IFM2 access
    struct npu_set_ifm2_region_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t region : 3;  //  Index n for IFM2 access
        uint32_t reserved1 : 13;
#ifdef __cplusplus
      public:
        npu_set_ifm2_region_t(uint32_t _region) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(_region & ((1U << 3) - 1)),
            reserved1(0)
        {
        }
        CONSTEXPR npu_set_ifm2_region_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_REGION)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL)), region(0), reserved1(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_REGION) &&
                   control == static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd0_opcode::NPU_SET_IFM2_REGION);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD0_CTRL);
        }
        operator uint32_t()
        {
            uint32_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd0_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd0_opcode>(opcode);
        }
        CONSTEXPR npu_set_ifm2_region_t &set_opcode(NPU_NAMESPACE::cmd0_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ifm2_region_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_region() const
        {
            return static_cast<uint32_t>(region);
        }
        CONSTEXPR npu_set_ifm2_region_t &set_region(uint32_t value)
        {
            region = static_cast<uint8_t>(value) & ((1U << 3) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("region", std::to_string(region)));
        }
#endif
#endif
    };
    // IFM Tile 0 address
    struct npu_set_ifm_base0_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_base0_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_base0_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE0) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE0);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_base0_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM Tile 1 address
    struct npu_set_ifm_base1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_base1_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_base1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE1) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_base1_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM Tile 2 address
    struct npu_set_ifm_base2_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_base2_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_base2_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE2) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE2);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_base2_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM Tile 3 address
    struct npu_set_ifm_base3_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_base3_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_base3_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE3) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_BASE3);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_base3_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM byte stride between horizontal values
    struct npu_set_ifm_stride_x_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_stride_x_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_stride_x_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_X) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_X);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_stride_x_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM byte stride between vertical values
    struct npu_set_ifm_stride_y_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_stride_y_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_stride_y_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_Y) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_Y);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_stride_y_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM byte stride between channel blocks (of 16 bytes each block)
    struct npu_set_ifm_stride_c_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm_stride_c_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm_stride_c_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_C) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM_STRIDE_C);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm_stride_c_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM Tile 0 address
    struct npu_set_ofm_base0_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_base0_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_base0_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE0) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE0);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_base0_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM Tile 1 address
    struct npu_set_ofm_base1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_base1_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_base1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE1) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_base1_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM Tile 2 address
    struct npu_set_ofm_base2_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_base2_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_base2_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE2) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE2);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_base2_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM Tile 3 address
    struct npu_set_ofm_base3_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_base3_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_base3_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE3) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_BASE3);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_base3_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM byte stride between horizontal values
    struct npu_set_ofm_stride_x_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_stride_x_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_stride_x_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_X) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_X);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_stride_x_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM byte stride between vertical values
    struct npu_set_ofm_stride_y_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_stride_y_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_stride_y_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_Y) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_Y);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_stride_y_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // OFM byte stride between channel blocks (of 16 bytes each block)
    struct npu_set_ofm_stride_c_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ofm_stride_c_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ofm_stride_c_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_C) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_STRIDE_C);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ofm_stride_c_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Weight stream byte offset in WEIGHT_REGION
    struct npu_set_weight_base_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_weight_base_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_weight_base_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_BASE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_BASE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_weight_base_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Weight stream byte length
    struct npu_set_weight_length_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
        uint32_t length : 32; //  Weight stream byte length
#ifdef __cplusplus
      public:
        npu_set_weight_length_t(uint32_t _length) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(_length)
        {
        }
        CONSTEXPR npu_set_weight_length_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_LENGTH) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT_LENGTH);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_weight_length_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_weight_length_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_length() const
        {
            return static_cast<uint32_t>(length);
        }
        CONSTEXPR npu_set_weight_length_t &set_length(uint32_t value)
        {
            length = value;
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("length", std::to_string(length)));
        }
#endif
#endif
    };
    // Scale and bias stream input byte offset from SCALE_REGION
    struct npu_set_scale_base_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_scale_base_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_scale_base_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_BASE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_BASE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_scale_base_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Scale and bias stream input byte length
    struct npu_set_scale_length_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
        uint32_t length : 20; //  Scale and bias stream byte length
        uint32_t reserved2 : 12;
#ifdef __cplusplus
      public:
        npu_set_scale_length_t(uint32_t _length) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0),
            length(_length & ((1U << 20) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_scale_length_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_LENGTH) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE_LENGTH);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_scale_length_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_scale_length_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_length() const
        {
            return static_cast<uint32_t>(length);
        }
        CONSTEXPR npu_set_scale_length_t &set_length(uint32_t value)
        {
            length = value & ((1U << 20) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("length", std::to_string(length)));
        }
#endif
#endif
    };
    // OFM scale
    struct npu_set_ofm_scale_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t shift : 6;   //  Shift
        uint32_t reserved1 : 10;
        uint32_t scale : 32; //  Scale. Not applied for 32-bit operations
#ifdef __cplusplus
      public:
        npu_set_ofm_scale_t(uint32_t _shift, uint32_t _scale) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), shift(_shift & ((1U << 6) - 1)),
            reserved1(0), scale(_scale)
        {
        }
        CONSTEXPR npu_set_ofm_scale_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), shift(0), reserved1(0), scale(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_SCALE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OFM_SCALE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_ofm_scale_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_ofm_scale_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_shift() const
        {
            return static_cast<uint32_t>(shift);
        }
        CONSTEXPR npu_set_ofm_scale_t &set_shift(uint32_t value)
        {
            shift = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_scale() const
        {
            return static_cast<uint32_t>(scale);
        }
        CONSTEXPR npu_set_ofm_scale_t &set_scale(uint32_t value)
        {
            scale = value;
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("shift", std::to_string(shift)));
            fields.push_back(std::make_pair<std::string, std::string>("scale", std::to_string(scale)));
        }
#endif
#endif
    };
    // Input operand A scale
    struct npu_set_opa_scale_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t shift : 6;   //  Shift. Ignored if IFM scale mode is 0
        uint32_t reserved1 : 10;
        uint32_t scale : 32; //  Scale. 16-bit if IFM scale mode is 0
#ifdef __cplusplus
      public:
        npu_set_opa_scale_t(uint32_t _shift, uint32_t _scale) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPA_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), shift(_shift & ((1U << 6) - 1)),
            reserved1(0), scale(_scale)
        {
        }
        CONSTEXPR npu_set_opa_scale_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPA_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), shift(0), reserved1(0), scale(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPA_SCALE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPA_SCALE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_opa_scale_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_opa_scale_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_shift() const
        {
            return static_cast<uint32_t>(shift);
        }
        CONSTEXPR npu_set_opa_scale_t &set_shift(uint32_t value)
        {
            shift = static_cast<uint8_t>(value) & ((1U << 6) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_scale() const
        {
            return static_cast<uint32_t>(scale);
        }
        CONSTEXPR npu_set_opa_scale_t &set_scale(uint32_t value)
        {
            scale = value;
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("shift", std::to_string(shift)));
            fields.push_back(std::make_pair<std::string, std::string>("scale", std::to_string(scale)));
        }
#endif
#endif
    };
    // Input operand B scale
    struct npu_set_opb_scale_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
        uint32_t scale : 16; //  Scale. Not used if IFM scale mode is 1 or 2
        uint32_t reserved2 : 16;
#ifdef __cplusplus
      public:
        npu_set_opb_scale_t(uint32_t _scale) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPB_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0),
            scale(_scale & ((1U << 16) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_opb_scale_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPB_SCALE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), scale(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPB_SCALE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_OPB_SCALE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_opb_scale_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_opb_scale_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_scale() const
        {
            return static_cast<uint32_t>(scale);
        }
        CONSTEXPR npu_set_opb_scale_t &set_scale(uint32_t value)
        {
            scale = static_cast<uint16_t>(value) & ((1U << 16) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("scale", std::to_string(scale)));
        }
#endif
#endif
    };
    // DMA user channel 0 source byte offset from DMA0_SRC_REGION
    struct npu_set_dma0_src_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_dma0_src_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SRC)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_dma0_src_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SRC)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SRC) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SRC);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_dma0_src_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // DMA user channel 0 destination byte offset from DMA0_DST_REGION
    struct npu_set_dma0_dst_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_dma0_dst_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_DST)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_dma0_dst_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_DST)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_DST) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_DST);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_dma0_dst_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // DMA user channel 0 transfer length in bytes for each 1D transfer
    struct npu_set_dma0_len_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_dma0_len_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_LEN)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_dma0_len_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_LEN)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_LEN) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_LEN);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_dma0_len_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // byte distance to skip after each inner (1D) transfer (2D/3D mode) (any alignment)
    struct npu_set_dma0_skip0_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_dma0_skip0_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_dma0_skip0_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP0) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP0);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_dma0_skip0_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // byte distance to skip after each 2D transfer (3D mode) (any alignment)
    struct npu_set_dma0_skip1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_dma0_skip1_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_dma0_skip1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP1) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_DMA0_SKIP1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_dma0_skip1_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 Tile 0 address
    struct npu_set_ifm2_base0_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_base0_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_base0_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE0)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE0) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE0);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_base0_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 Tile 1 address
    struct npu_set_ifm2_base1_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_base1_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_base1_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE1)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE1) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE1);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_base1_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 Tile 2 address
    struct npu_set_ifm2_base2_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_base2_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_base2_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE2)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE2) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE2);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_base2_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 Tile 3 address
    struct npu_set_ifm2_base3_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_base3_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_base3_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE3)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE3) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_BASE3);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_base3_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 byte stride between horizontal values
    struct npu_set_ifm2_stride_x_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_stride_x_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_stride_x_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_X)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_X) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_X);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_stride_x_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 byte stride between vertical values
    struct npu_set_ifm2_stride_y_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_stride_y_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_stride_y_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_Y)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_Y) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_Y);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_stride_y_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // IFM2 byte stride between channel blocks (of 16 bytes each block)
    struct npu_set_ifm2_stride_c_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_ifm2_stride_c_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_ifm2_stride_c_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_C)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_C) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_IFM2_STRIDE_C);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_ifm2_stride_c_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Weight stream byte offset in WEIGHT_REGION for core 1
    struct npu_set_weight1_base_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_weight1_base_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_weight1_base_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_BASE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_BASE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_weight1_base_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Weight stream byte length for core 1
    struct npu_set_weight1_length_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
        uint32_t length : 32; //  Weight stream byte length
#ifdef __cplusplus
      public:
        npu_set_weight1_length_t(uint32_t _length) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(_length)
        {
        }
        CONSTEXPR npu_set_weight1_length_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_LENGTH) &&
                   control >= 1 && control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_WEIGHT1_LENGTH);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_weight1_length_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_weight1_length_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_length() const
        {
            return static_cast<uint32_t>(length);
        }
        CONSTEXPR npu_set_weight1_length_t &set_length(uint32_t value)
        {
            length = value;
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("length", std::to_string(length)));
        }
#endif
#endif
    };
    // Scale and bias stream input byte offset from SCALE_REGION for core 1
    struct npu_set_scale1_base_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t addr_hi : 8; //  address extension
        uint32_t reserved1 : 8;
        uint32_t addr_lo : 32; //  address offset
#ifdef __cplusplus
      public:
        npu_set_scale1_base_t(uint64_t _addr) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)),
            addr_hi(static_cast<uint8_t>((_addr >> 32) & std::numeric_limits<uint64_t>::max())), reserved1(0),
            addr_lo(static_cast<uint32_t>((_addr)&std::numeric_limits<uint64_t>::max()))
        {
        }
        CONSTEXPR npu_set_scale1_base_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_BASE)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), addr_hi(0), reserved1(0), addr_lo(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_BASE) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_BASE);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR uint64_t get_addr() const
        {
            return (static_cast<uint64_t>(addr_hi) << 32) | addr_lo;
        }
        CONSTEXPR npu_set_scale1_base_t &set_addr(uint64_t value)
        {
            addr_lo = static_cast<uint32_t>((value)&std::numeric_limits<uint64_t>::max());
            addr_hi = static_cast<uint8_t>((value >> 32) & std::numeric_limits<uint64_t>::max());
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            std::stringstream saddr;
            saddr << std::hex << "0x" << get_addr();
            fields.push_back(std::make_pair<std::string, std::string>("addr", saddr.str()));
        }
#endif
#endif
    };
    // Scale and bias stream input byte length for core 1
    struct npu_set_scale1_length_t
    {
#ifdef __cplusplus
      private:
#endif
        uint32_t opcode : 10; //  opcode
        uint32_t reserved0 : 4;
        uint32_t control : 2; //  control
        uint32_t reserved1 : 16;
        uint32_t length : 20; //  Scale and bias stream byte length
        uint32_t reserved2 : 12;
#ifdef __cplusplus
      public:
        npu_set_scale1_length_t(uint32_t _length) :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0),
            length(_length & ((1U << 20) - 1)), reserved2(0)
        {
        }
        CONSTEXPR npu_set_scale1_length_t() :
            opcode(static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_LENGTH)), reserved0(0),
            control(static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL)), reserved1(0), length(0), reserved2(0)
        {
        }
        CONSTEXPR bool valid() const
        {
            return opcode == static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_LENGTH) && control >= 1 &&
                   control <= 2;
        }
        CONSTEXPR void init()
        {
            opcode  = static_cast<uint16_t>(NPU_NAMESPACE::cmd1_opcode::NPU_SET_SCALE1_LENGTH);
            control = static_cast<uint8_t>(NPU_NAMESPACE::cmd_ctrl::CMD1_CTRL);
        }
        operator uint64_t()
        {
            uint64_t word;
            std::memcpy(&word, this, sizeof(word));
            return word;
        }
        CONSTEXPR NPU_NAMESPACE::cmd1_opcode get_opcode() const
        {
            return static_cast<NPU_NAMESPACE::cmd1_opcode>(opcode);
        }
        CONSTEXPR npu_set_scale1_length_t &set_opcode(NPU_NAMESPACE::cmd1_opcode value)
        {
            opcode = static_cast<uint16_t>(value) & ((1U << 10) - 1);
            return *this;
        }
        CONSTEXPR NPU_NAMESPACE::cmd_ctrl get_control() const
        {
            return static_cast<NPU_NAMESPACE::cmd_ctrl>(control);
        }
        CONSTEXPR npu_set_scale1_length_t &set_control(NPU_NAMESPACE::cmd_ctrl value)
        {
            control = static_cast<uint8_t>(value) & ((1U << 2) - 1);
            return *this;
        }
        CONSTEXPR uint32_t get_length() const
        {
            return static_cast<uint32_t>(length);
        }
        CONSTEXPR npu_set_scale1_length_t &set_length(uint32_t value)
        {
            length = value & ((1U << 20) - 1);
            return *this;
        }
#ifdef NPU_DISASSEMBLE
        void disassemble(std::vector<std::pair<std::string, std::string>> &fields) const
        {
            fields.push_back(std::make_pair<std::string, std::string>("length", std::to_string(length)));
        }
#endif
#endif
    };
#ifdef __cplusplus
};
#endif
#define NPU_OP_STRUCTS                                                                                                 \
    NPU_OP_(stop)                                                                                                      \
    NPU_OP_(irq)                                                                                                       \
    NPU_OP_(conv)                                                                                                      \
    NPU_OP_(depthwise)                                                                                                 \
    NPU_OP_(pool)                                                                                                      \
    NPU_OP_(elementwise)                                                                                               \
    NPU_OP_(dma_start)                                                                                                 \
    NPU_OP_(dma_wait)                                                                                                  \
    NPU_OP_(kernel_wait)                                                                                               \
    NPU_OP_(pmu_mask)

#define NPU_SET_STRUCTS                                                                                                \
    NPU_SET_(ifm_pad_top)                                                                                              \
    NPU_SET_(ifm_pad_left)                                                                                             \
    NPU_SET_(ifm_pad_right)                                                                                            \
    NPU_SET_(ifm_pad_bottom)                                                                                           \
    NPU_SET_(ifm_depth_m1)                                                                                             \
    NPU_SET_(ifm_precision)                                                                                            \
    NPU_SET_(ifm_upscale)                                                                                              \
    NPU_SET_(ifm_zero_point)                                                                                           \
    NPU_SET_(ifm_width0_m1)                                                                                            \
    NPU_SET_(ifm_height0_m1)                                                                                           \
    NPU_SET_(ifm_height1_m1)                                                                                           \
    NPU_SET_(ifm_ib_end)                                                                                               \
    NPU_SET_(ifm_region)                                                                                               \
    NPU_SET_(ofm_width_m1)                                                                                             \
    NPU_SET_(ofm_height_m1)                                                                                            \
    NPU_SET_(ofm_depth_m1)                                                                                             \
    NPU_SET_(ofm_precision)                                                                                            \
    NPU_SET_(ofm_blk_width_m1)                                                                                         \
    NPU_SET_(ofm_blk_height_m1)                                                                                        \
    NPU_SET_(ofm_blk_depth_m1)                                                                                         \
    NPU_SET_(ofm_zero_point)                                                                                           \
    NPU_SET_(ofm_width0_m1)                                                                                            \
    NPU_SET_(ofm_height0_m1)                                                                                           \
    NPU_SET_(ofm_height1_m1)                                                                                           \
    NPU_SET_(ofm_region)                                                                                               \
    NPU_SET_(kernel_width_m1)                                                                                          \
    NPU_SET_(kernel_height_m1)                                                                                         \
    NPU_SET_(kernel_stride)                                                                                            \
    NPU_SET_(parallel_mode)                                                                                            \
    NPU_SET_(acc_format)                                                                                               \
    NPU_SET_(activation)                                                                                               \
    NPU_SET_(activation_min)                                                                                           \
    NPU_SET_(activation_max)                                                                                           \
    NPU_SET_(weight_region)                                                                                            \
    NPU_SET_(scale_region)                                                                                             \
    NPU_SET_(ab_start)                                                                                                 \
    NPU_SET_(blockdep)                                                                                                 \
    NPU_SET_(dma0_src_region)                                                                                          \
    NPU_SET_(dma0_dst_region)                                                                                          \
    NPU_SET_(dma0_size0)                                                                                               \
    NPU_SET_(dma0_size1)                                                                                               \
    NPU_SET_(ifm2_broadcast)                                                                                           \
    NPU_SET_(ifm2_scalar)                                                                                              \
    NPU_SET_(ifm2_precision)                                                                                           \
    NPU_SET_(ifm2_zero_point)                                                                                          \
    NPU_SET_(ifm2_width0_m1)                                                                                           \
    NPU_SET_(ifm2_height0_m1)                                                                                          \
    NPU_SET_(ifm2_height1_m1)                                                                                          \
    NPU_SET_(ifm2_ib_start)                                                                                            \
    NPU_SET_(ifm2_region)                                                                                              \
    NPU_SET_(ifm_base0)                                                                                                \
    NPU_SET_(ifm_base1)                                                                                                \
    NPU_SET_(ifm_base2)                                                                                                \
    NPU_SET_(ifm_base3)                                                                                                \
    NPU_SET_(ifm_stride_x)                                                                                             \
    NPU_SET_(ifm_stride_y)                                                                                             \
    NPU_SET_(ifm_stride_c)                                                                                             \
    NPU_SET_(ofm_base0)                                                                                                \
    NPU_SET_(ofm_base1)                                                                                                \
    NPU_SET_(ofm_base2)                                                                                                \
    NPU_SET_(ofm_base3)                                                                                                \
    NPU_SET_(ofm_stride_x)                                                                                             \
    NPU_SET_(ofm_stride_y)                                                                                             \
    NPU_SET_(ofm_stride_c)                                                                                             \
    NPU_SET_(weight_base)                                                                                              \
    NPU_SET_(weight_length)                                                                                            \
    NPU_SET_(scale_base)                                                                                               \
    NPU_SET_(scale_length)                                                                                             \
    NPU_SET_(ofm_scale)                                                                                                \
    NPU_SET_(opa_scale)                                                                                                \
    NPU_SET_(opb_scale)                                                                                                \
    NPU_SET_(dma0_src)                                                                                                 \
    NPU_SET_(dma0_dst)                                                                                                 \
    NPU_SET_(dma0_len)                                                                                                 \
    NPU_SET_(dma0_skip0)                                                                                               \
    NPU_SET_(dma0_skip1)                                                                                               \
    NPU_SET_(ifm2_base0)                                                                                               \
    NPU_SET_(ifm2_base1)                                                                                               \
    NPU_SET_(ifm2_base2)                                                                                               \
    NPU_SET_(ifm2_base3)                                                                                               \
    NPU_SET_(ifm2_stride_x)                                                                                            \
    NPU_SET_(ifm2_stride_y)                                                                                            \
    NPU_SET_(ifm2_stride_c)                                                                                            \
    NPU_SET_(weight1_base)                                                                                             \
    NPU_SET_(weight1_length)                                                                                           \
    NPU_SET_(scale1_base)                                                                                              \
    NPU_SET_(scale1_length)

#define EXPAND_ACC_FORMAT(FUNC, SEP) FUNC(acc_format, I32) SEP FUNC(acc_format, I40) SEP FUNC(acc_format, F16)

#define EXPAND_ACTIVATION_CLIP_RANGE(FUNC, SEP)                                                                        \
    FUNC(activation_clip_range, OFM_PRECISION)                                                                         \
    SEP FUNC(activation_clip_range, FORCE_UINT8) SEP FUNC(activation_clip_range, FORCE_INT8)                           \
        SEP FUNC(activation_clip_range, FORCE_INT16)

#define EXPAND_ACTIVATION_FORMAT(FUNC, SEP) FUNC(activation_format, NHWC) SEP FUNC(activation_format, NHCWB16)

#define EXPAND_ACTIVATION_FUNCTION(FUNC, SEP)                                                                          \
    FUNC(activation_function, RELU)                                                                                    \
    SEP FUNC(activation_function, TANH) SEP FUNC(activation_function, SIGMOID) SEP FUNC(activation_function, TABLE_0)  \
        SEP FUNC(activation_function, TABLE_1) SEP FUNC(activation_function, TABLE_2)                                  \
            SEP FUNC(activation_function, TABLE_3) SEP FUNC(activation_function, TABLE_4)                              \
                SEP FUNC(activation_function, TABLE_5) SEP FUNC(activation_function, TABLE_6)                          \
                    SEP FUNC(activation_function, TABLE_7)

#define EXPAND_ACTIVATION_PRECISION(FUNC, SEP)                                                                         \
    FUNC(activation_precision, B8)                                                                                     \
    SEP FUNC(activation_precision, B16) SEP FUNC(activation_precision, B32) SEP FUNC(activation_precision, B64)

#define EXPAND_ACTIVATION_TYPE(FUNC, SEP) FUNC(activation_type, UNSIGNED) SEP FUNC(activation_type, SIGNED)

#define EXPAND_AXI_MEM_ENCODING(FUNC, SEP)                                                                             \
    FUNC(axi_mem_encoding, DEVICE_NON_BUFFERABLE)                                                                      \
    SEP FUNC(axi_mem_encoding, DEVICE_BUFFERABLE) SEP FUNC(axi_mem_encoding, NORMAL_NON_CACHEABLE_NON_BUFFERABLE)      \
        SEP FUNC(axi_mem_encoding, NORMAL_NON_CACHEABLE_BUFFERABLE)                                                    \
            SEP FUNC(axi_mem_encoding, WRITE_THROUGH_NO_ALLOCATE)                                                      \
                SEP FUNC(axi_mem_encoding, WRITE_THROUGH_READ_ALLOCATE)                                                \
                    SEP FUNC(axi_mem_encoding, WRITE_THROUGH_WRITE_ALLOCATE)                                           \
                        SEP FUNC(axi_mem_encoding, WRITE_THROUGH_READ_AND_WRITE_ALLOCATE)                              \
                            SEP FUNC(axi_mem_encoding, WRITE_BACK_NO_ALLOCATE)                                         \
                                SEP FUNC(axi_mem_encoding, WRITE_BACK_READ_ALLOCATE)                                   \
                                    SEP FUNC(axi_mem_encoding, WRITE_BACK_WRITE_ALLOCATE)                              \
                                        SEP FUNC(axi_mem_encoding, WRITE_BACK_READ_AND_WRITE_ALLOCATE)

#define EXPAND_BROADCAST_MODE(FUNC, SEP) FUNC(broadcast_mode, DISABLE) SEP FUNC(broadcast_mode, ENABLE)

#define EXPAND_CMD0_OPCODE(FUNC, SEP)                                                                                  \
    FUNC(cmd0_opcode, NPU_OP_STOP)                                                                                     \
    SEP FUNC(cmd0_opcode, NPU_OP_IRQ) SEP FUNC(cmd0_opcode, NPU_OP_CONV) SEP FUNC(                                     \
        cmd0_opcode, NPU_OP_DEPTHWISE) SEP FUNC(cmd0_opcode, NPU_OP_POOL) SEP FUNC(cmd0_opcode, NPU_OP_ELEMENTWISE)    \
        SEP FUNC(cmd0_opcode, NPU_OP_DMA_START) SEP FUNC(cmd0_opcode, NPU_OP_DMA_WAIT) SEP FUNC(                       \
            cmd0_opcode, NPU_OP_KERNEL_WAIT) SEP FUNC(cmd0_opcode, NPU_OP_PMU_MASK) SEP FUNC(cmd0_opcode,              \
                                                                                             NPU_SET_IFM_PAD_TOP)      \
            SEP FUNC(cmd0_opcode, NPU_SET_IFM_PAD_LEFT) SEP FUNC(cmd0_opcode, NPU_SET_IFM_PAD_RIGHT) SEP FUNC(         \
                cmd0_opcode, NPU_SET_IFM_PAD_BOTTOM) SEP FUNC(cmd0_opcode,                                             \
                                                              NPU_SET_IFM_DEPTH_M1) SEP FUNC(cmd0_opcode,              \
                                                                                             NPU_SET_IFM_PRECISION)    \
                SEP FUNC(cmd0_opcode, NPU_SET_IFM_UPSCALE) SEP FUNC(cmd0_opcode, NPU_SET_IFM_ZERO_POINT) SEP FUNC(     \
                    cmd0_opcode, NPU_SET_IFM_WIDTH0_M1) SEP FUNC(cmd0_opcode, NPU_SET_IFM_HEIGHT0_M1)                  \
                    SEP FUNC(cmd0_opcode, NPU_SET_IFM_HEIGHT1_M1) SEP FUNC(cmd0_opcode, NPU_SET_IFM_IB_END) SEP FUNC(  \
                        cmd0_opcode, NPU_SET_IFM_REGION) SEP FUNC(cmd0_opcode, NPU_SET_OFM_WIDTH_M1)                   \
                        SEP FUNC(cmd0_opcode, NPU_SET_OFM_HEIGHT_M1) SEP FUNC(cmd0_opcode, NPU_SET_OFM_DEPTH_M1)       \
                            SEP FUNC(cmd0_opcode, NPU_SET_OFM_PRECISION) SEP FUNC(                                     \
                                cmd0_opcode, NPU_SET_OFM_BLK_WIDTH_M1) SEP FUNC(cmd0_opcode,                           \
                                                                                NPU_SET_OFM_BLK_HEIGHT_M1)             \
                                SEP FUNC(cmd0_opcode, NPU_SET_OFM_BLK_DEPTH_M1) SEP FUNC(                              \
                                    cmd0_opcode, NPU_SET_OFM_ZERO_POINT) SEP FUNC(cmd0_opcode, NPU_SET_OFM_WIDTH0_M1)  \
                                    SEP FUNC(cmd0_opcode, NPU_SET_OFM_HEIGHT0_M1) SEP FUNC(                            \
                                        cmd0_opcode,                                                                   \
                                        NPU_SET_OFM_HEIGHT1_M1) SEP FUNC(cmd0_opcode, NPU_SET_OFM_REGION)              \
                                        SEP FUNC(cmd0_opcode, NPU_SET_KERNEL_WIDTH_M1) SEP FUNC(                       \
                                            cmd0_opcode,                                                               \
                                            NPU_SET_KERNEL_HEIGHT_M1) SEP FUNC(cmd0_opcode, NPU_SET_KERNEL_STRIDE)     \
                                            SEP FUNC(cmd0_opcode, NPU_SET_PARALLEL_MODE) SEP FUNC(                     \
                                                cmd0_opcode,                                                           \
                                                NPU_SET_ACC_FORMAT) SEP FUNC(cmd0_opcode, NPU_SET_ACTIVATION)          \
                                                SEP FUNC(cmd0_opcode,                                                  \
                                                         NPU_SET_ACTIVATION_MIN) SEP FUNC(cmd0_opcode,                 \
                                                                                          NPU_SET_ACTIVATION_MAX)      \
                                                    SEP FUNC(cmd0_opcode, NPU_SET_WEIGHT_REGION) SEP FUNC(             \
                                                        cmd0_opcode,                                                   \
                                                        NPU_SET_SCALE_REGION) SEP FUNC(cmd0_opcode, NPU_SET_AB_START)  \
                                                        SEP FUNC(cmd0_opcode, NPU_SET_BLOCKDEP)                        \
                                                            SEP FUNC(cmd0_opcode, NPU_SET_DMA0_SRC_REGION) SEP FUNC(   \
                                                                cmd0_opcode,                                           \
                                                                NPU_SET_DMA0_DST_REGION) SEP FUNC(cmd0_opcode,         \
                                                                                                  NPU_SET_DMA0_SIZE0)  \
                                                                SEP FUNC(cmd0_opcode, NPU_SET_DMA0_SIZE1) SEP FUNC(    \
                                                                    cmd0_opcode,                                       \
                                                                    NPU_SET_IFM2_BROADCAST) SEP                        \
                                                                    FUNC(cmd0_opcode, NPU_SET_IFM2_SCALAR) SEP FUNC(   \
                                                                        cmd0_opcode,                                   \
                                                                        NPU_SET_IFM2_PRECISION) SEP                    \
                                                                        FUNC(cmd0_opcode, NPU_SET_IFM2_ZERO_POINT) SEP \
                                                                            FUNC(cmd0_opcode,                          \
                                                                                 NPU_SET_IFM2_WIDTH0_M1) SEP           \
                                                                                FUNC(cmd0_opcode,                      \
                                                                                     NPU_SET_IFM2_HEIGHT0_M1) SEP      \
                                                                                    FUNC(cmd0_opcode,                  \
                                                                                         NPU_SET_IFM2_HEIGHT1_M1)      \
                                                                                        SEP FUNC(                      \
                                                                                            cmd0_opcode,               \
                                                                                            NPU_SET_IFM2_IB_START)     \
                                                                                            SEP FUNC(                  \
                                                                                                cmd0_opcode,           \
                                                                                                NPU_SET_IFM2_REGION)

#define EXPAND_CMD1_OPCODE(FUNC, SEP)                                                                                  \
    FUNC(cmd1_opcode, NPU_SET_IFM_BASE0)                                                                               \
    SEP FUNC(cmd1_opcode, NPU_SET_IFM_BASE1) SEP FUNC(cmd1_opcode, NPU_SET_IFM_BASE2)                                  \
        SEP FUNC(cmd1_opcode, NPU_SET_IFM_BASE3) SEP FUNC(cmd1_opcode, NPU_SET_IFM_STRIDE_X)                           \
            SEP FUNC(cmd1_opcode, NPU_SET_IFM_STRIDE_Y) SEP FUNC(cmd1_opcode, NPU_SET_IFM_STRIDE_C) SEP FUNC(          \
                cmd1_opcode, NPU_SET_OFM_BASE0) SEP FUNC(cmd1_opcode, NPU_SET_OFM_BASE1)                               \
                SEP FUNC(cmd1_opcode, NPU_SET_OFM_BASE2) SEP FUNC(cmd1_opcode, NPU_SET_OFM_BASE3) SEP FUNC(            \
                    cmd1_opcode, NPU_SET_OFM_STRIDE_X) SEP FUNC(cmd1_opcode, NPU_SET_OFM_STRIDE_Y)                     \
                    SEP FUNC(cmd1_opcode, NPU_SET_OFM_STRIDE_C) SEP FUNC(cmd1_opcode, NPU_SET_WEIGHT_BASE) SEP FUNC(   \
                        cmd1_opcode, NPU_SET_WEIGHT_LENGTH) SEP FUNC(cmd1_opcode, NPU_SET_SCALE_BASE)                  \
                        SEP FUNC(cmd1_opcode, NPU_SET_SCALE_LENGTH) SEP FUNC(cmd1_opcode, NPU_SET_OFM_SCALE)           \
                            SEP FUNC(cmd1_opcode, NPU_SET_OPA_SCALE) SEP FUNC(cmd1_opcode, NPU_SET_OPB_SCALE)          \
                                SEP FUNC(cmd1_opcode, NPU_SET_DMA0_SRC) SEP FUNC(cmd1_opcode, NPU_SET_DMA0_DST)        \
                                    SEP FUNC(cmd1_opcode, NPU_SET_DMA0_LEN) SEP FUNC(cmd1_opcode, NPU_SET_DMA0_SKIP0)  \
                                        SEP FUNC(cmd1_opcode, NPU_SET_DMA0_SKIP1) SEP FUNC(                            \
                                            cmd1_opcode, NPU_SET_IFM2_BASE0) SEP FUNC(cmd1_opcode, NPU_SET_IFM2_BASE1) \
                                            SEP FUNC(cmd1_opcode, NPU_SET_IFM2_BASE2) SEP FUNC(cmd1_opcode,            \
                                                                                               NPU_SET_IFM2_BASE3)     \
                                                SEP FUNC(cmd1_opcode, NPU_SET_IFM2_STRIDE_X)                           \
                                                    SEP FUNC(cmd1_opcode, NPU_SET_IFM2_STRIDE_Y)                       \
                                                        SEP FUNC(cmd1_opcode, NPU_SET_IFM2_STRIDE_C)                   \
                                                            SEP FUNC(cmd1_opcode, NPU_SET_WEIGHT1_BASE)                \
                                                                SEP FUNC(cmd1_opcode, NPU_SET_WEIGHT1_LENGTH)          \
                                                                    SEP FUNC(cmd1_opcode, NPU_SET_SCALE1_BASE)         \
                                                                        SEP FUNC(cmd1_opcode, NPU_SET_SCALE1_LENGTH)

#define EXPAND_CMD_CTRL(FUNC, SEP) FUNC(cmd_ctrl, CMD0_CTRL) SEP FUNC(cmd_ctrl, CMD1_CTRL)

#define EXPAND_CUSTOM_DMA(FUNC, SEP) FUNC(custom_dma, NOT_IMPLEMENTED) SEP FUNC(custom_dma, IMPLEMENTED)

#define EXPAND_DMA_FAULT_SRC(FUNC, SEP) FUNC(dma_fault_src, AXI_M0) SEP FUNC(dma_fault_src, AXI_M1)

#define EXPAND_DMA_REGION_MODE(FUNC, SEP) FUNC(dma_region_mode, EXTERNAL) SEP FUNC(dma_region_mode, INTERNAL)

#define EXPAND_DMA_STRIDE_MODE(FUNC, SEP)                                                                              \
    FUNC(dma_stride_mode, D1) SEP FUNC(dma_stride_mode, D2) SEP FUNC(dma_stride_mode, D3)

#define EXPAND_ELEMENTWISE_MODE(FUNC, SEP)                                                                             \
    FUNC(elementwise_mode, MUL)                                                                                        \
    SEP FUNC(elementwise_mode, ADD) SEP FUNC(elementwise_mode, SUB) SEP FUNC(elementwise_mode, MIN)                    \
        SEP FUNC(elementwise_mode, MAX) SEP FUNC(elementwise_mode, LRELU) SEP FUNC(elementwise_mode, ABS)              \
            SEP FUNC(elementwise_mode, CLZ) SEP FUNC(elementwise_mode, SHR) SEP FUNC(elementwise_mode, SHL)

#define EXPAND_FUNCTIONAL_SAFETY(FUNC, SEP)                                                                            \
    FUNC(functional_safety, NOT_IMPLEMENTED) SEP FUNC(functional_safety, IMPLEMENTED)

#define EXPAND_IFM2_OPERAND_ORDER(FUNC, SEP) FUNC(ifm2_operand_order, ORDER_B) SEP FUNC(ifm2_operand_order, ORDER_A)

#define EXPAND_IFM_SCALE_MODE(FUNC, SEP)                                                                               \
    FUNC(ifm_scale_mode, OPA_OPB_16) SEP FUNC(ifm_scale_mode, OPA_32) SEP FUNC(ifm_scale_mode, OPB_32)

#define EXPAND_IFM_UPSCALE_MODE(FUNC, SEP)                                                                             \
    FUNC(ifm_upscale_mode, NONE) SEP FUNC(ifm_upscale_mode, NEAREST) SEP FUNC(ifm_upscale_mode, ZEROS)

#define EXPAND_KERNEL_DECOMPOSITION(FUNC, SEP) FUNC(kernel_decomposition, D8X8) SEP FUNC(kernel_decomposition, D4X4)

#define EXPAND_KERNEL_DILATION(FUNC, SEP) FUNC(kernel_dilation, NONE) SEP FUNC(kernel_dilation, X2)

#define EXPAND_MAX_BEATS(FUNC, SEP) FUNC(max_beats, B64) SEP FUNC(max_beats, B128) SEP FUNC(max_beats, B256)

#define EXPAND_MEM_ATTR(FUNC, SEP)                                                                                     \
    FUNC(mem_attr, AXI0_OUTSTANDING_COUNTER0)                                                                          \
    SEP FUNC(mem_attr, AXI0_OUTSTANDING_COUNTER1) SEP FUNC(mem_attr, AXI1_OUTSTANDING_COUNTER2)                        \
        SEP FUNC(mem_attr, AXI1_OUTSTANDING_COUNTER3)

#define EXPAND_OFM_SCALE_MODE(FUNC, SEP) FUNC(ofm_scale_mode, PER_CHANNEL) SEP FUNC(ofm_scale_mode, GLOBAL)

#define EXPAND_PARALLEL_MODE(FUNC, SEP) FUNC(parallel_mode, SINGLE_CORE) SEP FUNC(parallel_mode, DUAL_CORE_DEPTH)

#define EXPAND_PMU_AXI_CHANNEL(FUNC, SEP)                                                                              \
    FUNC(pmu_axi_channel, RD_CMD)                                                                                      \
    SEP FUNC(pmu_axi_channel, RD_IFM) SEP FUNC(pmu_axi_channel, RD_WEIGHTS) SEP FUNC(pmu_axi_channel, RD_SCALE_BIAS)   \
        SEP FUNC(pmu_axi_channel, RD_MEM2MEM) SEP FUNC(pmu_axi_channel, WR_OFM) SEP FUNC(pmu_axi_channel, WR_MEM2MEM)

#define EXPAND_PMU_EVENT(FUNC, SEP)                                                                                                    \
    FUNC(pmu_event, NO_EVENT)                                                                                                          \
    SEP FUNC(pmu_event, CYCLE) SEP FUNC(pmu_event, NPU_IDLE) SEP FUNC(pmu_event, CC_STALLED_ON_BLOCKDEP) SEP FUNC(                     \
        pmu_event, CC_STALLED_ON_SHRAM_RECONFIG) SEP FUNC(pmu_event, NPU_ACTIVE) SEP FUNC(pmu_event, MAC_ACTIVE)                       \
        SEP FUNC(pmu_event, MAC_ACTIVE_8BIT) SEP FUNC(pmu_event, MAC_ACTIVE_16BIT) SEP FUNC(                                           \
            pmu_event, MAC_DPU_ACTIVE) SEP FUNC(pmu_event, MAC_STALLED_BY_WD_ACC) SEP FUNC(pmu_event,                                  \
                                                                                           MAC_STALLED_BY_WD)                          \
            SEP FUNC(pmu_event, MAC_STALLED_BY_ACC) SEP FUNC(pmu_event, MAC_STALLED_BY_IB) SEP FUNC(                                   \
                pmu_event,                                                                                                             \
                MAC_ACTIVE_32BIT) SEP FUNC(pmu_event,                                                                                  \
                                           MAC_STALLED_BY_INT_W) SEP FUNC(pmu_event,                                                   \
                                                                          MAC_STALLED_BY_INT_ACC) SEP FUNC(pmu_event,                  \
                                                                                                           AO_ACTIVE)                  \
                SEP FUNC(pmu_event, AO_ACTIVE_8BIT) SEP FUNC(pmu_event, AO_ACTIVE_16BIT) SEP FUNC(                                     \
                    pmu_event, AO_STALLED_BY_OFMP_OB) SEP FUNC(pmu_event, AO_STALLED_BY_OFMP) SEP                                      \
                    FUNC(pmu_event, AO_STALLED_BY_OB) SEP FUNC(pmu_event, AO_STALLED_BY_ACC_IB) SEP FUNC(                              \
                        pmu_event, AO_STALLED_BY_ACC) SEP FUNC(pmu_event, AO_STALLED_BY_IB) SEP                                        \
                        FUNC(pmu_event, WD_ACTIVE) SEP FUNC(pmu_event, WD_STALLED) SEP FUNC(pmu_event, WD_STALLED_BY_WS) SEP FUNC(     \
                            pmu_event, WD_STALLED_BY_WD_BUF) SEP FUNC(pmu_event,                                                       \
                                                                      WD_PARSE_ACTIVE) SEP                                             \
                            FUNC(pmu_event, WD_PARSE_STALLED) SEP FUNC(pmu_event, WD_PARSE_STALLED_IN) SEP FUNC(                       \
                                pmu_event, WD_PARSE_STALLED_OUT) SEP FUNC(pmu_event,                                                   \
                                                                          WD_TRANS_WS) SEP                                             \
                                FUNC(pmu_event, WD_TRANS_WB) SEP FUNC(pmu_event, WD_TRANS_DW0) SEP FUNC(                               \
                                    pmu_event, WD_TRANS_DW1) SEP FUNC(pmu_event,                                                       \
                                                                      AXI0_RD_TRANS_ACCEPTED) SEP                                      \
                                    FUNC(pmu_event, AXI0_RD_TRANS_COMPLETED) SEP FUNC(pmu_event, AXI0_RD_DATA_BEAT_RECEIVED) SEP FUNC( \
                                        pmu_event, AXI0_RD_TRAN_REQ_STALLED) SEP FUNC(pmu_event,                                       \
                                                                                      AXI0_WR_TRANS_ACCEPTED) SEP                      \
                                        FUNC(pmu_event, AXI0_WR_TRANS_COMPLETED_M) SEP FUNC(                                           \
                                            pmu_event, AXI0_WR_TRANS_COMPLETED_S) SEP                                                  \
                                            FUNC(pmu_event, AXI0_WR_DATA_BEAT_WRITTEN) SEP FUNC(                                       \
                                                pmu_event, AXI0_WR_TRAN_REQ_STALLED) SEP                                               \
                                                FUNC(pmu_event, AXI0_WR_DATA_BEAT_STALLED) SEP FUNC(                                   \
                                                    pmu_event,                                                                         \
                                                    AXI0_ENABLED_CYCLES) SEP FUNC(pmu_event,                                           \
                                                                                  AXI0_RD_STALL_LIMIT) SEP                             \
                                                    FUNC(pmu_event, AXI0_WR_STALL_LIMIT) SEP FUNC(                                     \
                                                        pmu_event,                                                                     \
                                                        AXI_LATENCY_ANY) SEP FUNC(pmu_event,                                           \
                                                                                  AXI_LATENCY_32) SEP                                  \
                                                        FUNC(pmu_event,                                                                \
                                                             AXI_LATENCY_64) SEP FUNC(pmu_event,                                       \
                                                                                      AXI_LATENCY_128) SEP                             \
                                                            FUNC(pmu_event, AXI_LATENCY_256) SEP FUNC(                                 \
                                                                pmu_event,                                                             \
                                                                AXI_LATENCY_512) SEP FUNC(pmu_event,                                   \
                                                                                          AXI_LATENCY_1024) SEP                        \
                                                                FUNC(pmu_event, ECC_DMA) SEP FUNC(                                     \
                                                                    pmu_event,                                                         \
                                                                    ECC_SB0) SEP FUNC(pmu_event,                                       \
                                                                                      AXI1_RD_TRANS_ACCEPTED) SEP                      \
                                                                    FUNC(pmu_event, AXI1_RD_TRANS_COMPLETED) SEP FUNC(                 \
                                                                        pmu_event, AXI1_RD_DATA_BEAT_RECEIVED) SEP                     \
                                                                        FUNC(pmu_event, AXI1_RD_TRAN_REQ_STALLED) SEP FUNC(            \
                                                                            pmu_event, AXI1_WR_TRANS_ACCEPTED) SEP                     \
                                                                            FUNC(pmu_event, AXI1_WR_TRANS_COMPLETED_M) SEP FUNC(       \
                                                                                pmu_event,                                             \
                                                                                AXI1_WR_TRANS_COMPLETED_S) SEP                         \
                                                                                FUNC(pmu_event,                                        \
                                                                                     AXI1_WR_DATA_BEAT_WRITTEN) SEP                    \
                                                                                    FUNC(pmu_event,                                    \
                                                                                         AXI1_WR_TRAN_REQ_STALLED) SEP                 \
                                                                                        FUNC(                                          \
                                                                                            pmu_event,                                 \
                                                                                            AXI1_WR_DATA_BEAT_STALLED) SEP             \
                                                                                            FUNC(                                      \
                                                                                                pmu_event,                             \
                                                                                                AXI1_ENABLED_CYCLES) SEP               \
                                                                                                FUNC(                                  \
                                                                                                    pmu_event,                         \
                                                                                                    AXI1_RD_STALL_LIMIT) SEP           \
                                                                                                    FUNC(                              \
                                                                                                        pmu_event,                     \
                                                                                                        AXI1_WR_STALL_LIMIT)           \
                                                                                                        SEP FUNC(                      \
                                                                                                            pmu_event,                 \
                                                                                                            ECC_SB1)

#define EXPAND_POOLING_MODE(FUNC, SEP)                                                                                 \
    FUNC(pooling_mode, MAX) SEP FUNC(pooling_mode, AVERAGE) SEP FUNC(pooling_mode, REDUCE_SUM)

#define EXPAND_PRIVILEGE_LEVEL(FUNC, SEP) FUNC(privilege_level, USER) SEP FUNC(privilege_level, PRIVILEGED)

#define EXPAND_ROUND_MODE(FUNC, SEP) FUNC(round_mode, DBL) SEP FUNC(round_mode, TRUNCATE) SEP FUNC(round_mode, NATURAL)

#define EXPAND_SECURITY_LEVEL(FUNC, SEP) FUNC(security_level, SECURE) SEP FUNC(security_level, NON_SECURE)

#define EXPAND_STATE(FUNC, SEP) FUNC(state, STOPPED) SEP FUNC(state, RUNNING)

#define EXPAND_WD_CORE_SLICE_STATE(FUNC, SEP)                                                                          \
    FUNC(wd_core_slice_state, HEADER) SEP FUNC(wd_core_slice_state, PALETTE) SEP FUNC(wd_core_slice_state, WEIGHTS)

#define EXPAND_WD_CTRL_STATE(FUNC, SEP)                                                                                \
    FUNC(wd_ctrl_state, IDLE)                                                                                          \
    SEP FUNC(wd_ctrl_state, DRAIN) SEP FUNC(wd_ctrl_state, OFD_INIT) SEP FUNC(wd_ctrl_state, OFD_RUN)

#define EXPAND_WEIGHT_ORDER(FUNC, SEP) FUNC(weight_order, DEPTH_FIRST) SEP FUNC(weight_order, PART_KERNEL_FIRST)

#ifdef __cplusplus
}
#endif
#endif
