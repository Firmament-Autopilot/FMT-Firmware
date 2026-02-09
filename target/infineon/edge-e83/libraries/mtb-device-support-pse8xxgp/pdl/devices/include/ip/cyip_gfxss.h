/***************************************************************************//**
* GFXSS IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _CYIP_GFXSS_H_
#define _CYIP_GFXSS_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    GFXSS
*******************************************************************************/

#define GFXSS_GPU_MXGPU_SECTION_SIZE            0x00000020UL
#define GFXSS_GPU_GCNANO_SECTION_SIZE           0x00000800UL
#define GFXSS_GPU_SECTION_SIZE                  0x00001000UL
#define GFXSS_DC_MXDC_SECTION_SIZE              0x00000080UL
#define GFXSS_DC_DCNANO_SECTION_SIZE            0x00000200UL
#define GFXSS_DC_SECTION_SIZE                   0x00001000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_SECTION_SIZE    0x00001000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SECTION_SIZE   0x00001000UL
#define GFXSS_MIPIDSI_SECTION_SIZE              0x00002000UL
#define GFXSS_SECTION_SIZE                      0x00004000UL

/**
  * \brief Platform IP standard configuration for GPU. (GFXSS_GPU_MXGPU)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 IP control. */
   __IM uint32_t RESERVED[2];
   __IM uint32_t STATUS;                        /*!< 0x0000000C IP status. */
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt status bits. */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt set bits. */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt mask bits. */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt masked bits. */
} GFXSS_GPU_MXGPU_Type;                         /*!< Size = 32 (0x20) */

/**
  * \brief Host Interface Registers (GFXSS_GPU_GCNANO)
  */
typedef struct {
  __IOM uint32_t AQHICLOCKCONTROL;              /*!< 0x00000000 Clock Control Register. */
   __IM uint32_t AQHIIDLE;                      /*!< 0x00000004 Idle Status Register. */
  __IOM uint32_t AQAXICONFIG;                   /*!< 0x00000008 AXI Configuration Register. */
   __IM uint32_t AQAXISTATUS;                   /*!< 0x0000000C AXI Status Register. READ ONLY. Back-to-back read is forbidden
                                                                to this register and can cause system hang. Please insert delay
                                                                (nop operation) between two consecutive reads while accessing
                                                                this register outside of VSI drivers. */
   __IM uint32_t AQINTRACKNOWLEDGE;             /*!< 0x00000010 Interrupt Acknowledge Register. Each bit represents a
                                                                corresponding event being triggered. Reading from this register
                                                                clears the outstanding interrupt. READ ONLY. When the access
                                                                comes from a debugger (HMASTER[0] == 1), the clear by read
                                                                function is disabled. Back-to-back read is forbidden to this
                                                                register and can cause system hang. Please insert delay (nop
                                                                operation) between two consecutive reads while accessing this
                                                                register outside of VSI drivers. */
  __IOM uint32_t AQINTRENBL;                    /*!< 0x00000014 Interrupt Enable Register. Each bit enables a corresponding
                                                                event. */
   __IM uint32_t RESERVED[3];
   __IM uint32_t GCCHIPREV;                     /*!< 0x00000024 Chip Revsion Register. Shows the revision for the chip in BCD.
                                                                This register has no set reset value. It varies with the
                                                                implementation. READ ONLY. */
   __IM uint32_t GCCHIPDATE;                    /*!< 0x00000028 Chip Date Register. Shows the release date for the IP in
                                                                YYYYMMDD (year/month/day) format. This register has no set reset
                                                                value. It varies with the implementation. READ ONLY. */
   __IM uint32_t RESERVED1[27];
   __IM uint32_t GCREGHICHIPPATCHREV;           /*!< 0x00000098 Chip Patch Revision Register. Patch revision level for the
                                                                chip. It varies per release. READ ONLY */
   __IM uint32_t RESERVED2[3];
   __IM uint32_t GCPRODUCTID;                   /*!< 0x000000A8 Product Identification Register. Shows Product ID. READ ONLY. */
   __IM uint32_t RESERVED3[21];
  __IOM uint32_t GCMODULEPOWERCONTROLS;         /*!< 0x00000100 Module Power Control Register. Control register for module
                                                                level power controls. */
  __IOM uint32_t GCMODULEPOWERMODULECONTROL;    /*!< 0x00000104 Module Power Module Control Register. Module level control
                                                                register. */
   __IM uint32_t GCMODULEPOWERMODULESTATUS;     /*!< 0x00000108 Module Power Module Status Register. Module level control
                                                                status. */
   __IM uint32_t RESERVED4[194];
  __IOM uint32_t AQMEMORYDEBUG;                 /*!< 0x00000414 Memory Debug Register. */
   __IM uint32_t RESERVED5[5];
  __IOM uint32_t AQREGISTERTIMINGCONTROL;       /*!< 0x0000042C Timing Control Register. */
   __IM uint32_t RESERVED6[52];
  __IOM uint32_t GCREGFETCHADDRESS;             /*!< 0x00000500 Fetch Command Buffer Base Address Register. Address of the
                                                                command buffer. The address must be 64-byte aligned. */
  __IOM uint32_t GCREGFETCHCONTROL;             /*!< 0x00000504 Fetch Control Register. Writing a non-zero value to this
                                                                register starts the fetch engine. The FE will start fetching
                                                                64-bit commands and data starting at the address specified by
                                                                the gcregFetchAddress register. Make sure this count is large
                                                                enough to fetch the END command, otherwise the FE will wait
                                                                until more data is coming. */
   __IM uint32_t GCREGCURRENTFETCHADDRESS;      /*!< 0x00000508 Current Fetch Command Address Register. Debugging register that
                                                                defines the current address the FE is fetching data from. READ
                                                                ONLY. */
   __IM uint32_t RESERVED7[189];
} GFXSS_GPU_GCNANO_Type;                        /*!< Size = 2048 (0x800) */

/**
  * \brief Graphics Processing Unit. (GFXSS_GPU)
  */
typedef struct {
        GFXSS_GPU_MXGPU_Type MXGPU;             /*!< 0x00000000 Platform IP standard configuration for GPU. */
   __IM uint32_t RESERVED[504];
        GFXSS_GPU_GCNANO_Type GCNANO;           /*!< 0x00000800 Host Interface Registers */
} GFXSS_GPU_Type;                               /*!< Size = 4096 (0x1000) */

/**
  * \brief Platform IP standard configuration for DC. (GFXSS_DC_MXDC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 IP control. */
  __IOM uint32_t CLK_CTL;                       /*!< 0x00000004 Clock control. */
  __IOM uint32_t IO_CTL;                        /*!< 0x00000008 IO enable control. */
   __IM uint32_t STATUS;                        /*!< 0x0000000C IP status. */
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt status. */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt set bits. */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt mask bits. */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt masked bits. */
  __IOM uint32_t ADDR0_INT;                     /*!< 0x00000020 Address 0 for interrupt generation. */
  __IOM uint32_t ADDR1_INT;                     /*!< 0x00000024 Address 1 for interrupt generation. */
  __IOM uint32_t ADDR2_INT;                     /*!< 0x00000028 Address 2 for interrupt generation. */
  __IOM uint32_t ADDR3_INT;                     /*!< 0x0000002C Address 3 for interrupt generation. */
   __IM uint32_t RESERVED[4];
  __IOM uint32_t RLAD_CTL;                      /*!< 0x00000040 Control options for the RLAD decoder. */
  __IOM uint32_t RLAD_IMG;                      /*!< 0x00000044 Properties of the uncompressed image. */
  __IOM uint32_t RLAD_ENC;                      /*!< 0x00000048 Configuration of the encoder that compressed the image. */
  __IOM uint32_t RLAD_BUF0;                     /*!< 0x0000004C Properties of the compressed image data buffer. */
  __IOM uint32_t RLAD_BUF1;                     /*!< 0x00000050 Properties of the compressed image data buffer. */
   __IM uint32_t RLAD_STATUS;                   /*!< 0x00000054 RLAD decoder status. */
   __IM uint32_t RESERVED1[6];
   __IM uint32_t IPIDENTIFIER;                  /*!< 0x00000070 GFXSS IP and desig release identification (with DC, GPU and
                                                                MIPIDSI). */
   __IM uint32_t RESERVED2[3];
} GFXSS_DC_MXDC_Type;                           /*!< Size = 128 (0x80) */

/**
  * \brief Host Interface Registers (GFXSS_DC_DCNANO)
  */
typedef struct {
   __IM uint32_t GCREGDCCHIPREV;                /*!< 0x00000000 Chip Revision Register. Shows the revision for the chip in BCD.
                                                                This register has no set reset value. It varies with the
                                                                implementation. READ ONLY. */
   __IM uint32_t GCREGDCCHIPDATE;               /*!< 0x00000004 Chip Date Register. Shows the release date for the IP in
                                                                YYYYMMDD (year, month. day) format. This register has no set
                                                                reset value. It varies with the implementation. READ ONLY. */
   __IM uint32_t GCREGDCCHIPPATCHREV;           /*!< 0x00000008 Patch Revision Register. Patch revision level for the chip.
                                                                READ ONLY. */
   __IM uint32_t GCREGDCPRODUCTID;              /*!< 0x0000000C Product Identification Register. READ ONLY. */
   __IM uint32_t RESERVED[5];
  __IOM uint32_t GCREGFRAMEBUFFERCONFIG;        /*!< 0x00000024 Frame Buffer Configuration Register. Frame Buffer and Timing
                                                                control. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERADDRESS;       /*!< 0x00000028 Frame Buffer Base Address Register. Starting address of the
                                                                frame buffer. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERSTRIDE;        /*!< 0x0000002C Frame Buffer Stride Register. Stride of the frame buffer in
                                                                bytes. NOTE.. This register is double buffered. */
   __IM uint32_t RESERVED1;
  __IOM uint32_t GCREGDCTILEINCFG;              /*!< 0x00000034 Tile Input Configuration Register. Tile input configuration.
                                                                NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGDCTILEUVFRAMEBUFFERADR;   /*!< 0x00000038 Frame Buffer Tiled UV Base Address Register. UV frame buffer
                                                                address when tile input. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGDCTILEUVFRAMEBUFFERSTR;   /*!< 0x0000003C Frame Buffer Tiled UV Stride Register. UV frame buffer stride
                                                                when tile input NOTE.. This register is double buffered. */
   __IM uint32_t RESERVED2[6];
  __IOM uint32_t GCREGFRAMEBUFFERBACKGROUND;    /*!< 0x00000058 Framebuffer background color. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERCOLORKEY;      /*!< 0x0000005C Framebuffer Color Key Start Address Register. Start of color
                                                                key range of framebuffer. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERCOLORKEYHIGH;  /*!< 0x00000060 Framebuffer Color Key End Address Register. End of color key
                                                                range of framebuffer. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERCLEARVALUE;    /*!< 0x00000064 Framebuffer Clear Value Register. Clear value used when
                                                                dcregFrameBufferConfig.Clear is enabled, format is A8R8G8B8.
                                                                NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGVIDEOTL;                  /*!< 0x00000068 Top left coordinate of panel pixel where the video should
                                                                start. Be aware there is no panning inside the video. NOTE..
                                                                This register is double buffered. */
  __IOM uint32_t GCREGFRAMEBUFFERSIZE;          /*!< 0x0000006C video size information. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGVIDEOGLOBALALPHA;         /*!< 0x00000070 Global alpha for the video. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGBLENDSTACKORDER;          /*!< 0x00000074 Set the video, overlay0, overlay1 order for blend. The 1st is
                                                                the lowest layer, the 2nd is the middle layer, the 3rd is the
                                                                highest layer. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGVIDEOALPHABLENDCONFIG;    /*!< 0x00000078 Alpha Blending Configuration Register. NOTE.. This register is
                                                                double buffered. */
  __IOM uint32_t GCREGOVERLAYCONFIG;            /*!< 0x0000007C Overlay Configuration Register. Overlay control. NOTE.. This
                                                                register is double buffered. */
  __IOM uint32_t GCREGOVERLAYADDRESS;           /*!< 0x00000080 Starting address of the overlay. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYSTRIDE;            /*!< 0x00000084 Stride of the overlay in bytes. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGDCOVERLAYTILEINCFG;       /*!< 0x00000088 Tile Input Configuration Register. Tile input configuration.
                                                                NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGDCTILEUVOVERLAYADR;       /*!< 0x0000008C Starting address of the overlay UV. NOTE.. This register is
                                                                double buffered. */
  __IOM uint32_t GCREGDCTILEUVOVERLAYSTR;       /*!< 0x00000090 Stride of the overlay UV in bytes. NOTE.. This register is
                                                                double buffered. */
  __IOM uint32_t GCREGOVERLAYTL;                /*!< 0x00000094 Top left coordinate of panel pixel where the overlay should
                                                                start. Be aware there is no panning inside the overlay. NOTE..
                                                                This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYSIZE;              /*!< 0x00000098 overlay size information. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYCOLORKEY;          /*!< 0x0000009C Overlay Color Key Start Address Register. Start of color key
                                                                range for overlay. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYCOLORKEYHIGH;      /*!< 0x000000A0 Overlay Color Key End Address Register. End of color key range
                                                                for overlay. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYALPHABLENDCONFIG;  /*!< 0x000000A4 Alpha Blending Configuration Register. NOTE.. This register is
                                                                double buffered. */
  __IOM uint32_t GCREGOVERLAYGLOBALALPHA;       /*!< 0x000000A8 Overlay global alpha value. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYCLEARVALUE;        /*!< 0x000000AC Overlay Clear Value Register. Clear value used when
                                                                dcregOverlayConfig.Clear is enabled, Format is A8R8G8B8. NOTE..
                                                                This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYCONFIG1;           /*!< 0x000000B0 Overlay Configuration Register. Overlay control. NOTE.. This
                                                                register is double buffered. */
  __IOM uint32_t GCREGOVERLAYADDRESS1;          /*!< 0x000000B4 Starting address of the overlay. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYSTRIDE1;           /*!< 0x000000B8 Stride of the overlay in bytes. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYTL1;               /*!< 0x000000BC Top left coordinate of panel pixel where the overlay should
                                                                start. Be aware there is no panning inside the overlay. NOTE..
                                                                This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYSIZE1;             /*!< 0x000000C0 overlay1 size information. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYCOLORKEY1;         /*!< 0x000000C4 Overlay Color Key Start Address Register. Start of color key
                                                                range for overlay. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYCOLORKEYHIGH1;     /*!< 0x000000C8 Overlay Color Key End Address Register. End of color key range
                                                                for overlay. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGOVERLAYALPHABLENDCONFIG1; /*!< 0x000000CC Alpha Blending Configuration Register. NOTE.. This register is
                                                                double buffered. */
  __IOM uint32_t GCREGOVERLAYGLOBALALPHA1;      /*!< 0x000000D0 Overlay global alpha value. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGOVERLAYCLEARVALUE1;       /*!< 0x000000D4 Overlay Clear Value Register. Clear value used when
                                                                dcregOverlayConfig.Clear is enabled, Format is A8R8G8B8. NOTE..
                                                                This register is double buffered. */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t GCREGDISPLAYDITHERTABLELOW;    /*!< 0x000000E0 Dither Threshold Table Register. */
  __IOM uint32_t GCREGDISPLAYDITHERTABLEHIGH;   /*!< 0x000000E4 Dither Threshold Table Register. */
  __IOM uint32_t GCREGPANELCONFIG;              /*!< 0x000000E8 Panel Configuration Register. */
  __IOM uint32_t GCREGPANELCONTROL;             /*!< 0x000000EC Panel control Register. */
  __IOM uint32_t GCREGPANELFUNCTION;            /*!< 0x000000F0 Panel function Register. NOTE.. This register is double
                                                                buffered. */
   __OM uint32_t GCREGPANELWORKING;             /*!< 0x000000F4 Register to trigger Display Controller. */
   __IM uint32_t GCREGPANELSTATE;               /*!< 0x000000F8 Register representing the Display Controller status. READ ONLY. */
   __IM uint32_t RESERVED4;
  __IOM uint32_t GCREGHDISPLAY;                 /*!< 0x00000100 Horizontal Display Total and Visible Pixel Count Register.
                                                                Horizontal Total and Display End counters. NOTE.. This register
                                                                is double buffered. */
  __IOM uint32_t GCREGHSYNC;                    /*!< 0x00000104 Horizontal Sync Counter Register. Horizontal Sync counters.
                                                                NOTE.. This register is double buffered. */
   __IM uint32_t RESERVED5[2];
  __IOM uint32_t GCREGVDISPLAY;                 /*!< 0x00000110 Vertical Total and Visible Pixel Count Register. Vertical Total
                                                                and Display End counters. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGVSYNC;                    /*!< 0x00000114 Vertical Sync Counter Register. Vertical Sync counters. NOTE..
                                                                This register is double buffered. */
   __IM uint32_t GCREGDISPLAYCURRENTLOCATION;   /*!< 0x00000118 Display Current Location Register. Current x,y location of
                                                                display controller. READ ONLY. */
   __OM uint32_t GCREGGAMMAINDEX;               /*!< 0x0000011C Gamma Index Register. Index into gamma table. See
                                                                gcregGammaData for more information. */
   __OM uint32_t GCREGGAMMADATA;                /*!< 0x00000120 Gamma Data Register. Translation values for the gamma table.
                                                                When this register gets written, the data gets stored in the
                                                                gamma table at the index specified by the gcregGammaIndex
                                                                register. After the register is written, the index gets
                                                                incremented. */
  __IOM uint32_t GCREGCURSORCONFIG;             /*!< 0x00000124 Cursor Configuration Register. Configuration register for the
                                                                cursor. Double-buffered values in this register cannot be read
                                                                while a flip is in progress. NOTE.. This register is double
                                                                buffered. */
  __IOM uint32_t GCREGCURSORADDRESS;            /*!< 0x00000128 Cursor Base Address Register. Address of the cursor shape.
                                                                NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGCURSORLOCATION;           /*!< 0x0000012C Cursor Location Register. Location of the cursor on the owning
                                                                display. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGCURSORBACKGROUND;         /*!< 0x00000130 Cursor Background Color Register. The background color for
                                                                Masked cursors. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGCURSORFOREGROUND;         /*!< 0x00000134 Cursor Foreground Color Register. The foreground color for
                                                                Masked cursors. NOTE.. This register is double buffered. */
   __IM uint32_t GCREGDISPLAYINTR;              /*!< 0x00000138 Display Interrupt Register. This is the interrupt register for
                                                                the Display. This register will automatically clear after a
                                                                read. The interrupt bit is set when the current frame buffer is
                                                                used up. The interrupt signal will be pulled up only when the
                                                                interrupt enable bit in register gcregDisplayIntrEnable is
                                                                enabled. READ ONLY. When the access comes from a debugger
                                                                (HMASTER[0] == 1), the clear by read function is disabled. */
  __IOM uint32_t GCREGDISPLAYINTRENABLE;        /*!< 0x0000013C Display Interrupt Enable Register. The interrupt enable
                                                                register for display_0 (and display_1 if present). NOTE..
                                                                Interrupt enable for register gcregDisplayIntr. NOTE.. This
                                                                register is double buffered. */
  __IOM uint32_t GCREGDBICONFIG;                /*!< 0x00000140 DBI Configuration Register. Configuration register for DBI
                                                                output. */
   __OM uint32_t GCREGDBIIFRESET;               /*!< 0x00000144 DBI Reset Register. Reset DBI interface to idle state. WRITE
                                                                ONLY. */
  __IOM uint32_t GCREGDBIWRCHAR1;               /*!< 0x00000148 DBI Write AC Characteristics 1 Register. DBI write AC
                                                                characteristics definition register 1 */
  __IOM uint32_t GCREGDBIWRCHAR2;               /*!< 0x0000014C DBI Write AC Characteristics 2 Register. DBI write AC
                                                                characteristics definition register 2 */
   __OM uint32_t GCREGDBICMD;                   /*!< 0x00000150 DBI Command Control Register. DBI Command in/out port. Writes
                                                                to this register will send command/data to the DBI port. WRITE
                                                                ONLY. */
  __IOM uint32_t GCREGDPICONFIG;                /*!< 0x00000154 DPI Configuration Register. The configuration register for DPI
                                                                output. NOTE.. This register is double buffered. */
  __IOM uint32_t GCREGDBITYPECCFG;              /*!< 0x00000158 DBI Type C Timing Control Register. DBI Type C write timing
                                                                definition. */
   __IM uint32_t GCREGDCSTATUS;                 /*!< 0x0000015C Display Controller Status Register. READ ONLY. */
  __IOM uint32_t GCREGSRCCONFIGENDIAN;          /*!< 0x00000160 Endian control. */
   __OM uint32_t GCREGSOFTRESET;                /*!< 0x00000164 Soft reset. WRITE ONLY. */
  __IOM uint32_t GCREGDCCONTROL;                /*!< 0x00000168 Control register. */
  __IOM uint32_t GCREGREGISTERTIMINGCONTROL;    /*!< 0x0000016C Timing control register. */
  __IOM uint32_t GCREGDEBUGCOUNTERSELECT;       /*!< 0x00000170 Debug Counter Select Register. */
   __IM uint32_t GCREGDEBUGCOUNTERVALUE;        /*!< 0x00000174 Debug Counter Value Register. Debug Counter Value as specified
                                                                in gcregDebugCounterSelect. READ ONLY */
   __IM uint32_t RESERVED6[10];
  __IOM uint32_t GCREGLAYERCLOCKGATE;           /*!< 0x000001A0 Layer clock gater Register. disable video/overlay0/overlay1
                                                                clock gater */
   __IM uint32_t GCREGDEBUGTOTVIDEOREQ;         /*!< 0x000001A4 debug registers.. count video current frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTVIDEOREQ;         /*!< 0x000001A8 debug registers.. count video last frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTVIDEORRB;         /*!< 0x000001AC debug registers.. count video current frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTVIDEORRB;         /*!< 0x000001B0 debug registers.. count video last frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTOVERLAY0REQ;      /*!< 0x000001B4 debug registers.. count overlay0 current frame number of
                                                                requested burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTOVERLAY0REQ;      /*!< 0x000001B8 debug registers.. count overlay0 last frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTOVERLAY0RRB;      /*!< 0x000001BC debug registers.. count overlay0 current frame number of
                                                                returned burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTOVERLAY0RRB;      /*!< 0x000001C0 debug registers.. count overlay0 last frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTOVERLAY1REQ;      /*!< 0x000001C4 debug registers.. count overlay1 current frame number of
                                                                requested burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTOVERLAY1REQ;      /*!< 0x000001C8 debug registers.. count overlay1 last frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTOVERLAY1RRB;      /*!< 0x000001CC debug registers.. count overlay1 current frame number of
                                                                returned burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTOVERLAY1RRB;      /*!< 0x000001D0 debug registers.. count overlay1 last frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTCURSORREQ;        /*!< 0x000001D4 debug registers.. count cursor current frame number of
                                                                requested burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTCURSORREQ;        /*!< 0x000001D8 debug registers.. count cursor last frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTCURSORRRB;        /*!< 0x000001DC debug registers.. count cursor current frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTCURSORRRB;        /*!< 0x000001E0 debug registers.. count cursor last frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTDCREQ;            /*!< 0x000001E4 debug registers.. count DC current frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTDCREQ;            /*!< 0x000001E8 debug registers.. count DC last frame number of requested
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGTOTDCRRB;            /*!< 0x000001EC debug registers.. count DC current frame number of returned
                                                                burst. READ ONLY */
   __IM uint32_t GCREGDEBUGLSTDCRRB;            /*!< 0x000001F0 debug registers.. count DC last frame number of returned burst.
                                                                READ ONLY */
   __IM uint32_t GCREGDEBUGFRAMEANDMISFLAG;     /*!< 0x000001F4 debug registers. READ ONLY */
   __IM uint32_t RESERVED7[2];
} GFXSS_DC_DCNANO_Type;                         /*!< Size = 512 (0x200) */

/**
  * \brief Display Controller. (GFXSS_DC)
  */
typedef struct {
        GFXSS_DC_MXDC_Type MXDC;                /*!< 0x00000000 Platform IP standard configuration for DC. */
   __IM uint32_t RESERVED[480];
        GFXSS_DC_DCNANO_Type DCNANO;            /*!< 0x00000800 Host Interface Registers */
   __IM uint32_t RESERVED1[384];
} GFXSS_DC_Type;                                /*!< Size = 4096 (0x1000) */

/**
  * \brief Platform IP standard configuration for MIPI-DSI. (GFXSS_MIPIDSI_MXMIPIDSI)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 IP control. */
  __IOM uint32_t CLK_CTL;                       /*!< 0x00000004 Clock control. */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt status bits. */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt set bits. */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt mask bits. */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt masked bits. */
  __IOM uint32_t DPI_CMD;                       /*!< 0x00000020 DPI command control. */
  __IOM uint32_t DBI_CMD;                       /*!< 0x00000024 DBI command control. */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t PHY_FREQ_RANGE;                /*!< 0x00000030 PHY frequency range selection. */
  __IOM uint32_t BIST;                          /*!< 0x00000034 BIST control. */
  __IOM uint32_t IO_CONTINUITY_TEST;            /*!< 0x00000038 IO continuity test control. */
  __IOM uint32_t PLL_TEST_CONFIG1;              /*!< 0x0000003C PLL-SoC interface configuration for Test. */
  __IOM uint32_t PLL_TEST_CONFIG2;              /*!< 0x00000040 PLL-SoC interface configuration for Test. */
   __IM uint32_t PLL_TEST_OBS1;                 /*!< 0x00000044 PLL Test Observation bits. */
   __IM uint32_t PLL_TEST_OBS2;                 /*!< 0x00000048 PLL Test Observation bits. */
   __IM uint32_t LP_INTERNAL_LOOPBACK_TEST;     /*!< 0x0000004C Low Power internal Loopback Test */
   __IM uint32_t RESERVED2[1004];
} GFXSS_MIPIDSI_MXMIPIDSI_Type;                 /*!< Size = 4096 (0x1000) */

/**
  * \brief DSI Registers (GFXSS_MIPIDSI_DWCMIPIDSI)
  */
typedef struct {
   __IM uint32_t VERSION;                       /*!< 0x00000000 Contains the version of the DSI host controller. */
  __IOM uint32_t PWR_UP;                        /*!< 0x00000004 Controls the power up of the controller. */
  __IOM uint32_t CLKMGR_CFG;                    /*!< 0x00000008 Configures the factor for internal dividers to divide
                                                                lanebyteclk for timeout purposes. */
  __IOM uint32_t DPI_VCID;                      /*!< 0x0000000C Configures the Virtual Channel ID for DPI traffic. */
  __IOM uint32_t DPI_COLOR_CODING;              /*!< 0x00000010 Configures DPI color coding. */
  __IOM uint32_t DPI_CFG_POL;                   /*!< 0x00000014 Configures the polarity of DPI signals. */
  __IOM uint32_t DPI_LP_CMD_TIM;                /*!< 0x00000018 Configures the timing for low-power commands sent while in
                                                                video mode. */
  __IOM uint32_t DBI_VCID;                      /*!< 0x0000001C Configures Virtual Channel ID for DBI traffic. */
  __IOM uint32_t DBI_CFG;                       /*!< 0x00000020 Configures the bit width of pixels for DBI. */
  __IOM uint32_t DBI_PARTITIONING_EN;           /*!< 0x00000024 Configures whether DWC_mipi_dsi_host is to partition DBI
                                                                traffic automatically. */
  __IOM uint32_t DBI_CMDSIZE;                   /*!< 0x00000028 Configures the command size and the size for automatic
                                                                partitioning of DBI packets. */
  __IOM uint32_t PCKHDL_CFG;                    /*!< 0x0000002C Configures how EoTp, BTA, CRC and ECC are to be used, to meet
                                                                peripherals characteristics */
  __IOM uint32_t GEN_VCID;                      /*!< 0x00000030 Configures the Virtual Channel ID of READ responses to store
                                                                and return to Generic interface. */
  __IOM uint32_t MODE_CFG;                      /*!< 0x00000034 Configures the mode of operation between Video or Command Mode.
                                                                (Commands can still be sent while in video mode.) */
  __IOM uint32_t VID_MODE_CFG;                  /*!< 0x00000038 Configures several aspects of Video mode operation, the
                                                                transmission mode, switching to low-power in the middle of a
                                                                frame, enabling acknowledge and whether to send commands in
                                                                low-power. */
  __IOM uint32_t VID_PKT_SIZE;                  /*!< 0x0000003C Configures the video packet size. */
  __IOM uint32_t VID_NUM_CHUNKS;                /*!< 0x00000040 Configures the number of chunks to use. The data in each chunk
                                                                has the size provided by VID_PKT_SIZE. */
  __IOM uint32_t VID_NULL_SIZE;                 /*!< 0x00000044 Configures the size of null packets. */
  __IOM uint32_t VID_HSA_TIME;                  /*!< 0x00000048 Configures the video HSA time. */
  __IOM uint32_t VID_HBP_TIME;                  /*!< 0x0000004C Configures the video HBP time. */
  __IOM uint32_t VID_HLINE_TIME;                /*!< 0x00000050 Configures the overall time for each video line. */
  __IOM uint32_t VID_VSA_LINES;                 /*!< 0x00000054 Configures the VSA period. */
  __IOM uint32_t VID_VBP_LINES;                 /*!< 0x00000058 Configures the VBP period. */
  __IOM uint32_t VID_VFP_LINES;                 /*!< 0x0000005C Configures the VFP period. */
  __IOM uint32_t VID_VACTIVE_LINES;             /*!< 0x00000060 Configures the vertical resolution of video. */
   __IM uint32_t RESERVED;
  __IOM uint32_t CMD_MODE_CFG;                  /*!< 0x00000068 Configures several aspect of command mode operation, tearing
                                                                effect, acknowledge for each packet and the speed mode to
                                                                transmit each Data Type related to commands. */
  __IOM uint32_t GEN_HDR;                       /*!< 0x0000006C Sets the header for new packets sent using the Generic
                                                                interface. */
  __IOM uint32_t GEN_PLD_DATA;                  /*!< 0x00000070 Sets the payload for packets sent using the Generic interface
                                                                and, when read returns the contents of READ responses from the
                                                                peripheral. */
   __IM uint32_t CMD_PKT_STATUS;                /*!< 0x00000074 Contains information about the status of FIFOs related to DBI
                                                                and Generic interface. */
  __IOM uint32_t TO_CNT_CFG;                    /*!< 0x00000078 Configures counters that trigger timeout errors. These are used
                                                                to warn the system of a failure, through an interrupt, and
                                                                restart the controller in case of unexpected situations that
                                                                cause deadlock conditions. */
  __IOM uint32_t HS_RD_TO_CNT;                  /*!< 0x0000007C Configures the Peripheral Response timeout after high-speed
                                                                Read operations. */
  __IOM uint32_t LP_RD_TO_CNT;                  /*!< 0x00000080 Configures the Peripheral Response timeout after low-power Read
                                                                operations. */
  __IOM uint32_t HS_WR_TO_CNT;                  /*!< 0x00000084 Configures the Peripheral Response timeout after high-speed
                                                                Write operations. */
  __IOM uint32_t LP_WR_TO_CNT;                  /*!< 0x00000088 Configures the Peripheral Response timeout after low-power
                                                                Write operations. */
  __IOM uint32_t BTA_TO_CNT;                    /*!< 0x0000008C Configures the Peripheral Response timeout after Bus Turnaround
                                                                completion. */
  __IOM uint32_t SDF_3D;                        /*!< 0x00000090 Stores 3D control information for VSS packets in video mode. */
  __IOM uint32_t LPCLK_CTRL;                    /*!< 0x00000094 Configures the possibility for using non continuous clock in
                                                                the clock lane. */
  __IOM uint32_t PHY_TMR_LPCLK_CFG;             /*!< 0x00000098 Sets the time that DWC_mipi_dsi_host assumes in calculations
                                                                for the clock lane to switch between high-speed and low-power. */
  __IOM uint32_t PHY_TMR_CFG;                   /*!< 0x0000009C Sets the time that DWC_mipi_dsi_host assumes in calculations
                                                                for the data lanes to switch between high-speed and low-power. */
  __IOM uint32_t PHY_RSTZ;                      /*!< 0x000000A0 Controls resets and the PLL of the D-PHY. */
  __IOM uint32_t PHY_IF_CFG;                    /*!< 0x000000A4 Configures the number of active lanes and the minimum time to
                                                                remain in stop state. */
  __IOM uint32_t PHY_ULPS_CTRL;                 /*!< 0x000000A8 Configures entering and leaving ULPS in the D-PHY. */
  __IOM uint32_t PHY_TX_TRIGGERS;               /*!< 0x000000AC Configures the pins that activate triggers in the D-PHY. */
   __IM uint32_t PHY_STATUS;                    /*!< 0x000000B0 Contains information about the status of the D-PHY. */
  __IOM uint32_t PHY_TST_CTRL0;                 /*!< 0x000000B4 Controls clock and clear pins of the D-PHY vendor specific
                                                                interface. */
  __IOM uint32_t PHY_TST_CTRL1;                 /*!< 0x000000B8 Controls data and enable pins of the D-PHY vendor specific
                                                                interface. */
   __IM uint32_t INT_ST0;                       /*!< 0x000000BC Contains the status of interrupt sources from acknowledge
                                                                reports and the D-PHY. */
   __IM uint32_t INT_ST1;                       /*!< 0x000000C0 Contains the status of interrupt sources related to timeouts,
                                                                ECC, CRC, packet size, EoTp, Generic and DBI interfaces. */
  __IOM uint32_t INT_MSK0;                      /*!< 0x000000C4 Configures masks for the sources of interrupts that affect the
                                                                INT_ST0 register. Write 1 to un-mask each error report. */
  __IOM uint32_t INT_MSK1;                      /*!< 0x000000C8 Configures masks for the sources of interrupts that affect the
                                                                INT_ST1 register. */
  __IOM uint32_t PHY_CAL;                       /*!< 0x000000CC Controls the skew calibration of D-PHY. */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t INT_FORCE0;                    /*!< 0x000000D8 Forces interrupt that affect the INT_ST0 register. */
  __IOM uint32_t INT_FORCE1;                    /*!< 0x000000DC Forces interrupts that affect the INT_ST1 register. */
   __IM uint32_t RESERVED2[4];
  __IOM uint32_t DSC_PARAMETER;                 /*!< 0x000000F0 Configures Display Stream Compression. */
  __IOM uint32_t PHY_TMR_RD_CFG;                /*!< 0x000000F4 Configures times related to PHY to perform some operations in
                                                                lane byte clock cycles. */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t VID_SHADOW_CTRL;               /*!< 0x00000100 Controls dpi shadow feature */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t DPI_VCID_ACT;                  /*!< 0x0000010C Holds the value that controller is using for DPI_VCID. */
   __IM uint32_t DPI_COLOR_CODING_ACT;          /*!< 0x00000110 Holds the value that controller is using for DPI_COLOR_CODING. */
   __IM uint32_t RESERVED5;
   __IM uint32_t DPI_LP_CMD_TIM_ACT;            /*!< 0x00000118 Holds the value that controller is using for DPI_LP_CMD_TIM. */
   __IM uint32_t RESERVED6[7];
   __IM uint32_t VID_MODE_CFG_ACT;              /*!< 0x00000138 Holds the value that controller is using for VID_MODE_CFG. */
   __IM uint32_t VID_PKT_SIZE_ACT;              /*!< 0x0000013C Holds the value that controller is using for VID_PKT_SIZE. */
   __IM uint32_t VID_NUM_CHUNKS_ACT;            /*!< 0x00000140 This register holds the value that controller is using for
                                                                VID_NUM_CHUNKS. */
   __IM uint32_t VID_NULL_SIZE_ACT;             /*!< 0x00000144 Holds the value that controller is using for VID_NULL_SIZE. */
   __IM uint32_t VID_HSA_TIME_ACT;              /*!< 0x00000148 Holds the value that controller is using for VID_HSA_TIME. */
   __IM uint32_t VID_HBP_TIME_ACT;              /*!< 0x0000014C Holds the value that controller is using for VID_HBP_TIME. */
   __IM uint32_t VID_HLINE_TIME_ACT;            /*!< 0x00000150 Holds the value that controller is using for VID_HLINE_TIME. */
   __IM uint32_t VID_VSA_LINES_ACT;             /*!< 0x00000154 Holds the value that controller is using for VID_VSA_LINES. */
   __IM uint32_t VID_VBP_LINES_ACT;             /*!< 0x00000158 Holds the value that controller is using for VID_VBP_LINES. */
   __IM uint32_t VID_VFP_LINES_ACT;             /*!< 0x0000015C Holds the value that controller is using for VID_VFP_LINES. */
   __IM uint32_t VID_VACTIVE_LINES_ACT;         /*!< 0x00000160 Holds the value that controller is using for VID_VACTIVE_LINES. */
   __IM uint32_t RESERVED7;
   __IM uint32_t VID_PKT_STATUS;                /*!< 0x00000168 Contains information about the status of FIFOs related to DPI
                                                                and eDPI interfaces. */
   __IM uint32_t RESERVED8[9];
   __IM uint32_t SDF_3D_ACT;                    /*!< 0x00000190 Holds the value that controller is using for SDF_3D. */
   __IM uint32_t RESERVED9[923];
} GFXSS_MIPIDSI_DWCMIPIDSI_Type;                /*!< Size = 4096 (0x1000) */

/**
  * \brief MIPI-DSI Host Controller. (GFXSS_MIPIDSI)
  */
typedef struct {
        GFXSS_MIPIDSI_MXMIPIDSI_Type MXMIPIDSI; /*!< 0x00000000 Platform IP standard configuration for MIPI-DSI. */
        GFXSS_MIPIDSI_DWCMIPIDSI_Type DWCMIPIDSI; /*!< 0x00001000 DSI Registers */
} GFXSS_MIPIDSI_Type;                           /*!< Size = 8192 (0x2000) */

/**
  * \brief GFXSS
  */
typedef struct {
        GFXSS_GPU_Type GFXSS_GPU;               /*!< 0x00000000 Graphics Processing Unit. */
        GFXSS_DC_Type GFXSS_DC;                 /*!< 0x00001000 Display Controller. */
        GFXSS_MIPIDSI_Type GFXSS_MIPIDSI;       /*!< 0x00002000 MIPI-DSI Host Controller. */
} GFXSS_Type;                                   /*!< Size = 16384 (0x4000) */


/* GFXSS_GPU_MXGPU.CTL */
#define GFXSS_GPU_MXGPU_CTL_ENABLED_Pos         31UL
#define GFXSS_GPU_MXGPU_CTL_ENABLED_Msk         0x80000000UL
/* GFXSS_GPU_MXGPU.STATUS */
#define GFXSS_GPU_MXGPU_STATUS_CORE_RST_Pos     0UL
#define GFXSS_GPU_MXGPU_STATUS_CORE_RST_Msk     0x1UL
/* GFXSS_GPU_MXGPU.INTR */
#define GFXSS_GPU_MXGPU_INTR_CORE_Pos           0UL
#define GFXSS_GPU_MXGPU_INTR_CORE_Msk           0x1UL
/* GFXSS_GPU_MXGPU.INTR_SET */
#define GFXSS_GPU_MXGPU_INTR_SET_CORE_SET_Pos   0UL
#define GFXSS_GPU_MXGPU_INTR_SET_CORE_SET_Msk   0x1UL
/* GFXSS_GPU_MXGPU.INTR_MASK */
#define GFXSS_GPU_MXGPU_INTR_MASK_CORE_MASK_Pos 0UL
#define GFXSS_GPU_MXGPU_INTR_MASK_CORE_MASK_Msk 0x1UL
/* GFXSS_GPU_MXGPU.INTR_MASKED */
#define GFXSS_GPU_MXGPU_INTR_MASKED_CORE_MASKED_Pos 0UL
#define GFXSS_GPU_MXGPU_INTR_MASKED_CORE_MASKED_Msk 0x1UL


/* GFXSS_GPU_GCNANO.AQHICLOCKCONTROL */
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_1_Pos 0UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_1_Msk 0x1UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_CLK2D_DIS_Pos 1UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_CLK2D_DIS_Msk 0x2UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_FSCALE_VAL_Pos 2UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_FSCALE_VAL_Msk 0x1FCUL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Pos 9UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Msk 0x200UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Pos 10UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Msk 0x400UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Pos 11UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Msk 0x800UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_SOFT_RESET_Pos 12UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_SOFT_RESET_Msk 0x1000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Pos 13UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Msk 0x2000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_2_Pos 14UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_2_Msk 0x4000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_3_Pos 15UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_3_Msk 0x8000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE3_D_Pos 16UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE3_D_Msk 0x10000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE2_D_Pos 17UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE2_D_Msk 0x20000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE_VG_Pos 18UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_IDLE_VG_Msk 0x40000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_ISOLATE_GPU_Pos 19UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_ISOLATE_GPU_Msk 0x80000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_4_Pos 20UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_4_Msk 0x1FF00000UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_5_Pos 29UL
#define GFXSS_GPU_GCNANO_AQHICLOCKCONTROL_AQHICLOCKCONTROL_RESERVED_5_Msk 0xE0000000UL
/* GFXSS_GPU_GCNANO.AQHIIDLE */
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_FE_Pos 0UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_FE_Msk 0x1UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_DE_Pos 1UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_DE_Msk 0x2UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_PE_Pos 2UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_PE_Msk 0x4UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_SH_Pos 3UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_SH_Msk 0x8UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_PA_Pos 4UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_PA_Msk 0x10UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_SE_Pos 5UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_SE_Msk 0x20UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_RA_Pos 6UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_RA_Msk 0x40UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_TX_Pos 7UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_TX_Msk 0x80UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_VG_Pos 8UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_VG_Msk 0x100UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_IM_Pos 9UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_IM_Msk 0x200UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_FP_Pos 10UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_FP_Msk 0x400UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_TS_Pos 11UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_TS_Msk 0x800UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_BLT_Pos 12UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_IDLE_BLT_Msk 0x1000UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_UNUSED_Pos 13UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_UNUSED_Msk 0x7FFFE000UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_AXI_LP_Pos 31UL
#define GFXSS_GPU_GCNANO_AQHIIDLE_AQHIIDLE_AXI_LP_Msk 0x80000000UL
/* GFXSS_GPU_GCNANO.AQAXICONFIG */
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_RESERVED_1_Pos 0UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_RESERVED_1_Msk 0xFFUL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AWCACHE_Pos 8UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AWCACHE_Msk 0xF00UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_ARCACHE_Pos 12UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_ARCACHE_Msk 0xF000UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXDOMAIN_SHARED_Pos 16UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXDOMAIN_SHARED_Msk 0x30000UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXDOMAIN_NON_SHARED_Pos 18UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXDOMAIN_NON_SHARED_Msk 0xC0000UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Pos 20UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Msk 0xF00000UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_RESERVED_2_Pos 24UL
#define GFXSS_GPU_GCNANO_AQAXICONFIG_AQAXICONFIG_RESERVED_2_Msk 0xFF000000UL
/* GFXSS_GPU_GCNANO.AQAXISTATUS */
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_WR_ERR_ID_Pos 0UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_WR_ERR_ID_Msk 0xFUL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_RD_ERR_ID_Pos 4UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_RD_ERR_ID_Msk 0xF0UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_DET_WR_ERR_Pos 8UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_DET_WR_ERR_Msk 0x100UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_DET_RD_ERR_Pos 9UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_DET_RD_ERR_Msk 0x200UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_RESERVED_Pos 10UL
#define GFXSS_GPU_GCNANO_AQAXISTATUS_AQAXISTATUS_RESERVED_Msk 0xFFFFFC00UL
/* GFXSS_GPU_GCNANO.AQINTRACKNOWLEDGE */
#define GFXSS_GPU_GCNANO_AQINTRACKNOWLEDGE_AQINTRACKNOWLEDGE_INTR_VEC_Pos 0UL
#define GFXSS_GPU_GCNANO_AQINTRACKNOWLEDGE_AQINTRACKNOWLEDGE_INTR_VEC_Msk 0xFFFFFFFFUL
/* GFXSS_GPU_GCNANO.AQINTRENBL */
#define GFXSS_GPU_GCNANO_AQINTRENBL_AQINTRENBL_INTR_ENBL_VEC_Pos 0UL
#define GFXSS_GPU_GCNANO_AQINTRENBL_AQINTRENBL_INTR_ENBL_VEC_Msk 0xFFFFFFFFUL
/* GFXSS_GPU_GCNANO.GCCHIPREV */
#define GFXSS_GPU_GCNANO_GCCHIPREV_GCCHIPREV_REV_Pos 0UL
#define GFXSS_GPU_GCNANO_GCCHIPREV_GCCHIPREV_REV_Msk 0xFFFFFFFFUL
/* GFXSS_GPU_GCNANO.GCCHIPDATE */
#define GFXSS_GPU_GCNANO_GCCHIPDATE_GCCHIPDATE_DATE_Pos 0UL
#define GFXSS_GPU_GCNANO_GCCHIPDATE_GCCHIPDATE_DATE_Msk 0xFFFFFFFFUL
/* GFXSS_GPU_GCNANO.GCREGHICHIPPATCHREV */
#define GFXSS_GPU_GCNANO_GCREGHICHIPPATCHREV_GCREGHICHIPPATCHREV_PATCH_REV_Pos 0UL
#define GFXSS_GPU_GCNANO_GCREGHICHIPPATCHREV_GCREGHICHIPPATCHREV_PATCH_REV_Msk 0xFFUL
#define GFXSS_GPU_GCNANO_GCREGHICHIPPATCHREV_GCREGHICHIPPATCHREV_RESERVED_Pos 8UL
#define GFXSS_GPU_GCNANO_GCREGHICHIPPATCHREV_GCREGHICHIPPATCHREV_RESERVED_Msk 0xFFFFFF00UL
/* GFXSS_GPU_GCNANO.GCPRODUCTID */
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_GRADE_LEVEL_Pos 0UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_GRADE_LEVEL_Msk 0xFUL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_NUM_Pos 4UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_NUM_Msk 0xFFFFF0UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_TYPE_Pos 24UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_TYPE_Msk 0xF000000UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_RESERVED_Pos 28UL
#define GFXSS_GPU_GCNANO_GCPRODUCTID_GCPRODUCTID_RESERVED_Msk 0xF0000000UL
/* GFXSS_GPU_GCNANO.GCMODULEPOWERCONTROLS */
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_Pos 0UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_Msk 0x1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_Pos 1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_Msk 0x2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_Pos 2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_Msk 0x4UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_RESERVED_1_Pos 3UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_RESERVED_1_Msk 0x8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Pos 4UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Msk 0xF0UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_RESERVED_2_Pos 8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_RESERVED_2_Msk 0xFF00UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Pos 16UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERCONTROLS_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Msk 0xFFFF0000UL
/* GFXSS_GPU_GCNANO.GCMODULEPOWERMODULECONTROL */
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_Pos 0UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_Msk 0x1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_1_Pos 1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_1_Msk 0x2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_Pos 2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_Msk 0x4UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_2_Pos 3UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_2_Msk 0xF8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG_Pos 8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG_Msk 0x100UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM_Pos 9UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM_Msk 0x200UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_3_Pos 10UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_3_Msk 0x400UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS_Pos 11UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS_Msk 0x800UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FLEXA_Pos 12UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FLEXA_Msk 0x1000UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_4_Pos 13UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULECONTROL_GCMODULEPOWERMODULECONTROL_RESERVED_4_Msk 0xFFFFE000UL
/* GFXSS_GPU_GCNANO.GCMODULEPOWERMODULESTATUS */
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_Pos 0UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_Msk 0x1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_1_Pos 1UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_1_Msk 0x2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_Pos 2UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_Msk 0x4UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_2_Pos 3UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_2_Msk 0xF8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG_Pos 8UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG_Msk 0x100UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM_Pos 9UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM_Msk 0x200UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS_Pos 11UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS_Msk 0x800UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FLEXA_Pos 12UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FLEXA_Msk 0x1000UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_3_Pos 13UL
#define GFXSS_GPU_GCNANO_GCMODULEPOWERMODULESTATUS_GCMODULEPOWERMODULESTATUS_RESERVED_3_Msk 0xFFFFE000UL
/* GFXSS_GPU_GCNANO.AQMEMORYDEBUG */
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Pos 0UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Msk 0xFFUL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_1_Pos 8UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_1_Msk 0xFF00UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_2_Pos 16UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_2_Msk 0x10000UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_3_Pos 17UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_3_Msk 0x60000UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_4_Pos 19UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_4_Msk 0xF80000UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_5_Pos 24UL
#define GFXSS_GPU_GCNANO_AQMEMORYDEBUG_AQMEMORYDEBUG_RESERVED_5_Msk 0xFF000000UL
/* GFXSS_GPU_GCNANO.AQREGISTERTIMINGCONTROL */
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FOR_RF1P_Pos 0UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FOR_RF1P_Msk 0xFFUL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FOR_RF2P_Pos 8UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FOR_RF2P_Msk 0xFF00UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FAST_RTC_Pos 16UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FAST_RTC_Msk 0x30000UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FAST_WTC_Pos 18UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_FAST_WTC_Msk 0xC0000UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_POWER_DOWN_Pos 20UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_POWER_DOWN_Msk 0x100000UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_RESERVED_Pos 21UL
#define GFXSS_GPU_GCNANO_AQREGISTERTIMINGCONTROL_AQREGISTERTIMINGCONTROL_RESERVED_Msk 0xFFE00000UL
/* GFXSS_GPU_GCNANO.GCREGFETCHADDRESS */
#define GFXSS_GPU_GCNANO_GCREGFETCHADDRESS_GCREGFETCHADDRESS_TYPE_Pos 0UL
#define GFXSS_GPU_GCNANO_GCREGFETCHADDRESS_GCREGFETCHADDRESS_TYPE_Msk 0x3UL
#define GFXSS_GPU_GCNANO_GCREGFETCHADDRESS_GCREGFETCHADDRESS_ADDRESS_Pos 2UL
#define GFXSS_GPU_GCNANO_GCREGFETCHADDRESS_GCREGFETCHADDRESS_ADDRESS_Msk 0xFFFFFFFCUL
/* GFXSS_GPU_GCNANO.GCREGFETCHCONTROL */
#define GFXSS_GPU_GCNANO_GCREGFETCHCONTROL_GCREGFETCHCONTROL_COUNT_Pos 0UL
#define GFXSS_GPU_GCNANO_GCREGFETCHCONTROL_GCREGFETCHCONTROL_COUNT_Msk 0x1FFFFFUL
#define GFXSS_GPU_GCNANO_GCREGFETCHCONTROL_GCREGFETCHCONTROL_RESERVED_Pos 21UL
#define GFXSS_GPU_GCNANO_GCREGFETCHCONTROL_GCREGFETCHCONTROL_RESERVED_Msk 0xFFE00000UL
/* GFXSS_GPU_GCNANO.GCREGCURRENTFETCHADDRESS */
#define GFXSS_GPU_GCNANO_GCREGCURRENTFETCHADDRESS_GCREGCURRENTFETCHADDRESS_ADDRESS_Pos 0UL
#define GFXSS_GPU_GCNANO_GCREGCURRENTFETCHADDRESS_GCREGCURRENTFETCHADDRESS_ADDRESS_Msk 0xFFFFFFFFUL


/* GFXSS_DC_MXDC.CTL */
#define GFXSS_DC_MXDC_CTL_ENABLED_Pos           31UL
#define GFXSS_DC_MXDC_CTL_ENABLED_Msk           0x80000000UL
/* GFXSS_DC_MXDC.CLK_CTL */
#define GFXSS_DC_MXDC_CLK_CTL_CLK_CORE_Pos      0UL
#define GFXSS_DC_MXDC_CLK_CTL_CLK_CORE_Msk      0x1UL
#define GFXSS_DC_MXDC_CLK_CTL_CLK_DIV_Pos       6UL
#define GFXSS_DC_MXDC_CLK_CTL_CLK_DIV_Msk       0xFFFFFFC0UL
/* GFXSS_DC_MXDC.IO_CTL */
#define GFXSS_DC_MXDC_IO_CTL_SPI_ENABLED_Pos    0UL
#define GFXSS_DC_MXDC_IO_CTL_SPI_ENABLED_Msk    0x1UL
#define GFXSS_DC_MXDC_IO_CTL_SPI_SDOEN_Pos      1UL
#define GFXSS_DC_MXDC_IO_CTL_SPI_SDOEN_Msk      0x2UL
#define GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Pos    8UL
#define GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Msk    0x100UL
#define GFXSS_DC_MXDC_IO_CTL_DBI_ENABLED_Pos    16UL
#define GFXSS_DC_MXDC_IO_CTL_DBI_ENABLED_Msk    0x10000UL
/* GFXSS_DC_MXDC.STATUS */
#define GFXSS_DC_MXDC_STATUS_CORE_RST_Pos       0UL
#define GFXSS_DC_MXDC_STATUS_CORE_RST_Msk       0x1UL
/* GFXSS_DC_MXDC.INTR */
#define GFXSS_DC_MXDC_INTR_CORE_Pos             0UL
#define GFXSS_DC_MXDC_INTR_CORE_Msk             0x1UL
#define GFXSS_DC_MXDC_INTR_ADDR0_Pos            8UL
#define GFXSS_DC_MXDC_INTR_ADDR0_Msk            0x100UL
#define GFXSS_DC_MXDC_INTR_ADDR1_Pos            9UL
#define GFXSS_DC_MXDC_INTR_ADDR1_Msk            0x200UL
#define GFXSS_DC_MXDC_INTR_ADDR2_Pos            10UL
#define GFXSS_DC_MXDC_INTR_ADDR2_Msk            0x400UL
#define GFXSS_DC_MXDC_INTR_ADDR3_Pos            11UL
#define GFXSS_DC_MXDC_INTR_ADDR3_Msk            0x800UL
#define GFXSS_DC_MXDC_INTR_RLAD_ERROR_Pos       16UL
#define GFXSS_DC_MXDC_INTR_RLAD_ERROR_Msk       0x10000UL
/* GFXSS_DC_MXDC.INTR_SET */
#define GFXSS_DC_MXDC_INTR_SET_CORE_SET_Pos     0UL
#define GFXSS_DC_MXDC_INTR_SET_CORE_SET_Msk     0x1UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR0_SET_Pos    8UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR0_SET_Msk    0x100UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR1_SET_Pos    9UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR1_SET_Msk    0x200UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR2_SET_Pos    10UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR2_SET_Msk    0x400UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR3_SET_Pos    11UL
#define GFXSS_DC_MXDC_INTR_SET_ADDR3_SET_Msk    0x800UL
#define GFXSS_DC_MXDC_INTR_SET_RLAD_ERROR_SET_Pos 16UL
#define GFXSS_DC_MXDC_INTR_SET_RLAD_ERROR_SET_Msk 0x10000UL
/* GFXSS_DC_MXDC.INTR_MASK */
#define GFXSS_DC_MXDC_INTR_MASK_CORE_MASK_Pos   0UL
#define GFXSS_DC_MXDC_INTR_MASK_CORE_MASK_Msk   0x1UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR0_MASK_Pos  8UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR0_MASK_Msk  0x100UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR1_MASK_Pos  9UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR1_MASK_Msk  0x200UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR2_MASK_Pos  10UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR2_MASK_Msk  0x400UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR3_MASK_Pos  11UL
#define GFXSS_DC_MXDC_INTR_MASK_ADDR3_MASK_Msk  0x800UL
#define GFXSS_DC_MXDC_INTR_MASK_RLAD_ERROR_MASK_Pos 16UL
#define GFXSS_DC_MXDC_INTR_MASK_RLAD_ERROR_MASK_Msk 0x10000UL
/* GFXSS_DC_MXDC.INTR_MASKED */
#define GFXSS_DC_MXDC_INTR_MASKED_CORE_MASKED_Pos 0UL
#define GFXSS_DC_MXDC_INTR_MASKED_CORE_MASKED_Msk 0x1UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR0_MASKED_Pos 8UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR0_MASKED_Msk 0x100UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR1_MASKED_Pos 9UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR1_MASKED_Msk 0x200UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR2_MASKED_Pos 10UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR2_MASKED_Msk 0x400UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR3_MASKED_Pos 11UL
#define GFXSS_DC_MXDC_INTR_MASKED_ADDR3_MASKED_Msk 0x800UL
#define GFXSS_DC_MXDC_INTR_MASKED_RLAD_ERROR_MASKED_Pos 16UL
#define GFXSS_DC_MXDC_INTR_MASKED_RLAD_ERROR_MASKED_Msk 0x10000UL
/* GFXSS_DC_MXDC.ADDR0_INT */
#define GFXSS_DC_MXDC_ADDR0_INT_ADDR0_INT_Pos   0UL
#define GFXSS_DC_MXDC_ADDR0_INT_ADDR0_INT_Msk   0xFFFFFFFFUL
/* GFXSS_DC_MXDC.ADDR1_INT */
#define GFXSS_DC_MXDC_ADDR1_INT_ADDR1_INT_Pos   0UL
#define GFXSS_DC_MXDC_ADDR1_INT_ADDR1_INT_Msk   0xFFFFFFFFUL
/* GFXSS_DC_MXDC.ADDR2_INT */
#define GFXSS_DC_MXDC_ADDR2_INT_ADDR2_INT_Pos   0UL
#define GFXSS_DC_MXDC_ADDR2_INT_ADDR2_INT_Msk   0xFFFFFFFFUL
/* GFXSS_DC_MXDC.ADDR3_INT */
#define GFXSS_DC_MXDC_ADDR3_INT_ADDR3_INT_Pos   0UL
#define GFXSS_DC_MXDC_ADDR3_INT_ADDR3_INT_Msk   0xFFFFFFFFUL
/* GFXSS_DC_MXDC.RLAD_CTL */
#define GFXSS_DC_MXDC_RLAD_CTL_RLAD_ENABLE_Pos  0UL
#define GFXSS_DC_MXDC_RLAD_CTL_RLAD_ENABLE_Msk  0x1UL
#define GFXSS_DC_MXDC_RLAD_CTL_RLAD_LAYER_Pos   8UL
#define GFXSS_DC_MXDC_RLAD_CTL_RLAD_LAYER_Msk   0x300UL
/* GFXSS_DC_MXDC.RLAD_IMG */
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_WIDTH_Pos   0UL
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_WIDTH_Msk   0xFFFUL
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_HEIGHT_Pos  14UL
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_HEIGHT_Msk  0x3FFC000UL
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_FORMAT_Pos  28UL
#define GFXSS_DC_MXDC_RLAD_IMG_RLAD_FORMAT_Msk  0xF0000000UL
/* GFXSS_DC_MXDC.RLAD_ENC */
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_MODE_Pos    0UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_MODE_Msk    0x3UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_R_Pos  16UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_R_Msk  0xF0000UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_G_Pos  20UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_G_Msk  0xF00000UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_B_Pos  24UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_B_Msk  0xF000000UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_A_Pos  28UL
#define GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_A_Msk  0xF0000000UL
/* GFXSS_DC_MXDC.RLAD_BUF0 */
#define GFXSS_DC_MXDC_RLAD_BUF0_RLAD_ADDRESS_Pos 7UL
#define GFXSS_DC_MXDC_RLAD_BUF0_RLAD_ADDRESS_Msk 0xFFFFFF80UL
/* GFXSS_DC_MXDC.RLAD_BUF1 */
#define GFXSS_DC_MXDC_RLAD_BUF1_RLAD_SIZE_Pos   0UL
#define GFXSS_DC_MXDC_RLAD_BUF1_RLAD_SIZE_Msk   0x1FFFFFFFUL
/* GFXSS_DC_MXDC.RLAD_STATUS */
#define GFXSS_DC_MXDC_RLAD_STATUS_RLAD_FAILED_Pos 0UL
#define GFXSS_DC_MXDC_RLAD_STATUS_RLAD_FAILED_Msk 0x7UL
/* GFXSS_DC_MXDC.IPIDENTIFIER */
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPPLATFORM_Pos 0UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPPLATFORM_Msk 0x1UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPNAME_Pos   4UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPNAME_Msk   0x30UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPVERMAJOR_Pos 8UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPVERMAJOR_Msk 0xF00UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPVERMINOR_Pos 12UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPVERMINOR_Msk 0xF000UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPMATURITY_Pos 16UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPMATURITY_Msk 0x30000UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPRELEASE_Pos 20UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPRELEASE_Msk 0xFF00000UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPIMPLEMENTATION_Pos 28UL
#define GFXSS_DC_MXDC_IPIDENTIFIER_IPIMPLEMENTATION_Msk 0x10000000UL


/* GFXSS_DC_DCNANO.GCREGDCCHIPREV */
#define GFXSS_DC_DCNANO_GCREGDCCHIPREV_GCREGDCCHIPREV_REV_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCCHIPREV_GCREGDCCHIPREV_REV_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDCCHIPDATE */
#define GFXSS_DC_DCNANO_GCREGDCCHIPDATE_GCREGDCCHIPDATE_DATE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCCHIPDATE_GCREGDCCHIPDATE_DATE_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDCCHIPPATCHREV */
#define GFXSS_DC_DCNANO_GCREGDCCHIPPATCHREV_GCREGDCCHIPPATCHREV_PATCH_REV_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCCHIPPATCHREV_GCREGDCCHIPPATCHREV_PATCH_REV_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDCPRODUCTID */
#define GFXSS_DC_DCNANO_GCREGDCPRODUCTID_GCREGDCPRODUCTID_PRODUCT_ID_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCPRODUCTID_GCREGDCPRODUCTID_PRODUCT_ID_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERCONFIG */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_FORMAT_Msk 0x7UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_ENABLE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_ENABLE_Msk 0x8UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_CLEAR_EN_Pos 5UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_CLEAR_EN_Msk 0x20UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_COLOR_KEY_EN_Pos 10UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_COLOR_KEY_EN_Msk 0x400UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_SWIZZLE_Pos 17UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_SWIZZLE_Msk 0x60000UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_UV_SWIZZLE_Pos 19UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_UV_SWIZZLE_Msk 0x80000UL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERADDRESS */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERADDRESS_GCREGFRAMEBUFFERADDRESS_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERADDRESS_GCREGFRAMEBUFFERADDRESS_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERSTRIDE */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSTRIDE_GCREGFRAMEBUFFERSTRIDE_STRIDE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSTRIDE_GCREGFRAMEBUFFERSTRIDE_STRIDE_Msk 0x1FFFFUL
/* GFXSS_DC_DCNANO.GCREGDCTILEINCFG */
#define GFXSS_DC_DCNANO_GCREGDCTILEINCFG_GCREGDCTILEINCFG_TILE_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCTILEINCFG_GCREGDCTILEINCFG_TILE_FORMAT_Msk 0x3UL
#define GFXSS_DC_DCNANO_GCREGDCTILEINCFG_GCREGDCTILEINCFG_YUV_STANDARD_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGDCTILEINCFG_GCREGDCTILEINCFG_YUV_STANDARD_Msk 0x4UL
/* GFXSS_DC_DCNANO.GCREGDCTILEUVFRAMEBUFFERADR */
#define GFXSS_DC_DCNANO_GCREGDCTILEUVFRAMEBUFFERADR_GCREGDCTILEUVFRAMEBUFFERADR_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCTILEUVFRAMEBUFFERADR_GCREGDCTILEUVFRAMEBUFFERADR_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDCTILEUVFRAMEBUFFERSTR */
#define GFXSS_DC_DCNANO_GCREGDCTILEUVFRAMEBUFFERSTR_GCREGDCTILEUVFRAMEBUFFERSTR_STRIDE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCTILEUVFRAMEBUFFERSTR_GCREGDCTILEUVFRAMEBUFFERSTR_STRIDE_Msk 0xFFFFUL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERBACKGROUND */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERBACKGROUND_GCREGFRAMEBUFFERBACKGROUND_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERCOLORKEY */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEY_GCREGFRAMEBUFFERCOLORKEY_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERCOLORKEYHIGH */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCOLORKEYHIGH_GCREGFRAMEBUFFERCOLORKEYHIGH_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERCLEARVALUE */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCLEARVALUE_GCREGFRAMEBUFFERCLEARVALUE_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGVIDEOTL */
#define GFXSS_DC_DCNANO_GCREGVIDEOTL_GCREGVIDEOTL_X_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGVIDEOTL_GCREGVIDEOTL_X_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGVIDEOTL_GCREGVIDEOTL_Y_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGVIDEOTL_GCREGVIDEOTL_Y_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGFRAMEBUFFERSIZE */
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGVIDEOGLOBALALPHA */
#define GFXSS_DC_DCNANO_GCREGVIDEOGLOBALALPHA_GCREGVIDEOGLOBALALPHA_SRC_ALPHA_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGVIDEOGLOBALALPHA_GCREGVIDEOGLOBALALPHA_SRC_ALPHA_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGVIDEOGLOBALALPHA_GCREGVIDEOGLOBALALPHA_DST_ALPHA_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGVIDEOGLOBALALPHA_GCREGVIDEOGLOBALALPHA_DST_ALPHA_Msk 0xFF00UL
/* GFXSS_DC_DCNANO.GCREGBLENDSTACKORDER */
#define GFXSS_DC_DCNANO_GCREGBLENDSTACKORDER_GCREGBLENDSTACKORDER_ORDER_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGBLENDSTACKORDER_GCREGBLENDSTACKORDER_ORDER_Msk 0x7UL
/* GFXSS_DC_DCNANO.GCREGVIDEOALPHABLENDCONFIG */
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_ALPHA_BLEND_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_ALPHA_BLEND_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_Msk 0x18UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_Pos 6UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_Msk 0xC0UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_Msk 0x100UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_Pos 9UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_Msk 0x200UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_Pos 10UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_Msk 0xC00UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_Pos 13UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_Msk 0x6000UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_Pos 15UL
#define GFXSS_DC_DCNANO_GCREGVIDEOALPHABLENDCONFIG_GCREGVIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_Msk 0x8000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCONFIG */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_FORMAT_Msk 0x7UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_ENABLE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_ENABLE_Msk 0x8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_CLEAR_EN_Pos 5UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_CLEAR_EN_Msk 0x20UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_SWIZZLE_Pos 17UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_SWIZZLE_Msk 0x60000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_UV_SWIZZLE_Pos 19UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_UV_SWIZZLE_Msk 0x80000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_COLOR_KEY_EN_Pos 20UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_COLOR_KEY_EN_Msk 0x100000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYADDRESS */
#define GFXSS_DC_DCNANO_GCREGOVERLAYADDRESS_GCREGOVERLAYADDRESS_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYADDRESS_GCREGOVERLAYADDRESS_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGOVERLAYSTRIDE */
#define GFXSS_DC_DCNANO_GCREGOVERLAYSTRIDE_GCREGOVERLAYSTRIDE_STRIDE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSTRIDE_GCREGOVERLAYSTRIDE_STRIDE_Msk 0x1FFFFUL
/* GFXSS_DC_DCNANO.GCREGDCOVERLAYTILEINCFG */
#define GFXSS_DC_DCNANO_GCREGDCOVERLAYTILEINCFG_GCREGDCOVERLAYTILEINCFG_TILE_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCOVERLAYTILEINCFG_GCREGDCOVERLAYTILEINCFG_TILE_FORMAT_Msk 0x3UL
#define GFXSS_DC_DCNANO_GCREGDCOVERLAYTILEINCFG_GCREGDCOVERLAYTILEINCFG_YUV_STANDARD_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGDCOVERLAYTILEINCFG_GCREGDCOVERLAYTILEINCFG_YUV_STANDARD_Msk 0x4UL
/* GFXSS_DC_DCNANO.GCREGDCTILEUVOVERLAYADR */
#define GFXSS_DC_DCNANO_GCREGDCTILEUVOVERLAYADR_GCREGDCTILEUVOVERLAYADR_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCTILEUVOVERLAYADR_GCREGDCTILEUVOVERLAYADR_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDCTILEUVOVERLAYSTR */
#define GFXSS_DC_DCNANO_GCREGDCTILEUVOVERLAYSTR_GCREGDCTILEUVOVERLAYSTR_STRIDE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCTILEUVOVERLAYSTR_GCREGDCTILEUVOVERLAYSTR_STRIDE_Msk 0xFFFFUL
/* GFXSS_DC_DCNANO.GCREGOVERLAYTL */
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL_GCREGOVERLAYTL_X_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL_GCREGOVERLAYTL_X_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL_GCREGOVERLAYTL_Y_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL_GCREGOVERLAYTL_Y_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYSIZE */
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCOLORKEY */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY_GCREGOVERLAYCOLORKEY_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCOLORKEYHIGH */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH_GCREGOVERLAYCOLORKEYHIGH_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYALPHABLENDCONFIG */
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_ALPHA_BLEND_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_ALPHA_BLEND_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_Msk 0x18UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_Pos 6UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_Msk 0xC0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_Msk 0x100UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_Pos 9UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_Msk 0x200UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_Pos 10UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_Msk 0xC00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_Pos 13UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_Msk 0x6000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_Pos 15UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG_GCREGOVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_Msk 0x8000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYGLOBALALPHA */
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA_GCREGOVERLAYGLOBALALPHA_SRC_ALPHA_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA_GCREGOVERLAYGLOBALALPHA_SRC_ALPHA_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA_GCREGOVERLAYGLOBALALPHA_DST_ALPHA_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA_GCREGOVERLAYGLOBALALPHA_DST_ALPHA_Msk 0xFF00UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCLEARVALUE */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE_GCREGOVERLAYCLEARVALUE_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCONFIG1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_FORMAT_Msk 0x7UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_ENABLE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_ENABLE_Msk 0x8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_CLEAR_EN_Pos 5UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_CLEAR_EN_Msk 0x20UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_SWIZZLE_Pos 17UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_SWIZZLE_Msk 0x60000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_COLOR_KEY_EN_Pos 20UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_COLOR_KEY_EN_Msk 0x100000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYADDRESS1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYADDRESS1_GCREGOVERLAYADDRESS1_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYADDRESS1_GCREGOVERLAYADDRESS1_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGOVERLAYSTRIDE1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYSTRIDE1_GCREGOVERLAYSTRIDE1_STRIDE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSTRIDE1_GCREGOVERLAYSTRIDE1_STRIDE_Msk 0x1FFFFUL
/* GFXSS_DC_DCNANO.GCREGOVERLAYTL1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL1_GCREGOVERLAYTL1_X_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL1_GCREGOVERLAYTL1_X_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL1_GCREGOVERLAYTL1_Y_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYTL1_GCREGOVERLAYTL1_Y_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYSIZE1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCOLORKEY1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEY1_GCREGOVERLAYCOLORKEY1_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCOLORKEYHIGH1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCOLORKEYHIGH1_GCREGOVERLAYCOLORKEYHIGH1_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYALPHABLENDCONFIG1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_Msk 0x18UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_Pos 6UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_Msk 0xC0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_Msk 0x100UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_Pos 9UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_Msk 0x200UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_Pos 10UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_Msk 0xC00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_Pos 13UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_Msk 0x6000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_Pos 15UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYALPHABLENDCONFIG1_GCREGOVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_Msk 0x8000UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYGLOBALALPHA1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA1_GCREGOVERLAYGLOBALALPHA1_SRC_ALPHA_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA1_GCREGOVERLAYGLOBALALPHA1_SRC_ALPHA_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA1_GCREGOVERLAYGLOBALALPHA1_DST_ALPHA_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYGLOBALALPHA1_GCREGOVERLAYGLOBALALPHA1_DST_ALPHA_Msk 0xFF00UL
/* GFXSS_DC_DCNANO.GCREGOVERLAYCLEARVALUE1 */
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_RED_Msk 0xFF0000UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_ALPHA_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGOVERLAYCLEARVALUE1_GCREGOVERLAYCLEARVALUE1_ALPHA_Msk 0xFF000000UL
/* GFXSS_DC_DCNANO.GCREGDISPLAYDITHERTABLELOW */
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X0_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X0_Msk 0xFUL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X1_Pos 4UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X1_Msk 0xF0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X2_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X2_Msk 0xF00UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X3_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y0_X3_Msk 0xF000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X0_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X0_Msk 0xF0000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X1_Pos 20UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X1_Msk 0xF00000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X2_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X2_Msk 0xF000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X3_Pos 28UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLELOW_GCREGDISPLAYDITHERTABLELOW_Y1_X3_Msk 0xF0000000UL
/* GFXSS_DC_DCNANO.GCREGDISPLAYDITHERTABLEHIGH */
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X0_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X0_Msk 0xFUL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X1_Pos 4UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X1_Msk 0xF0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X2_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X2_Msk 0xF00UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X3_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y2_X3_Msk 0xF000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X0_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X0_Msk 0xF0000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X1_Pos 20UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X1_Msk 0xF00000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X2_Pos 24UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X2_Msk 0xF000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X3_Pos 28UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYDITHERTABLEHIGH_GCREGDISPLAYDITHERTABLEHIGH_Y3_X3_Msk 0xF0000000UL
/* GFXSS_DC_DCNANO.GCREGPANELCONFIG */
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DE_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DE_POLARITY_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DE_POLARITY_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DATA_POLARITY_Pos 5UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_DATA_POLARITY_Msk 0x20UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_CLOCK_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_CLOCK_Msk 0x100UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_CLOCK_POLARITY_Pos 9UL
#define GFXSS_DC_DCNANO_GCREGPANELCONFIG_GCREGPANELCONFIG_CLOCK_POLARITY_Msk 0x200UL
/* GFXSS_DC_DCNANO.GCREGPANELCONTROL */
#define GFXSS_DC_DCNANO_GCREGPANELCONTROL_GCREGPANELCONTROL_VALID_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGPANELCONTROL_GCREGPANELCONTROL_VALID_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGPANELCONTROL_GCREGPANELCONTROL_BACK_PRESSURE_DISABLE_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGPANELCONTROL_GCREGPANELCONTROL_BACK_PRESSURE_DISABLE_Msk 0x2UL
/* GFXSS_DC_DCNANO.GCREGPANELFUNCTION */
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_OUTPUT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_OUTPUT_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_GAMMA_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_GAMMA_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_DITHER_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGPANELFUNCTION_GCREGPANELFUNCTION_DITHER_Msk 0x4UL
/* GFXSS_DC_DCNANO.GCREGPANELWORKING */
#define GFXSS_DC_DCNANO_GCREGPANELWORKING_GCREGPANELWORKING_WORKING_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGPANELWORKING_GCREGPANELWORKING_WORKING_Msk 0x1UL
/* GFXSS_DC_DCNANO.GCREGPANELSTATE */
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_VIDEO_UNDER_FLOW_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_VIDEO_UNDER_FLOW_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_OVERLAY_UNDER_FLOW_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_OVERLAY_UNDER_FLOW_Msk 0x4UL
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_OVERLAY_UNDER_FLOW1_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGPANELSTATE_GCREGPANELSTATE_OVERLAY_UNDER_FLOW1_Msk 0x8UL
/* GFXSS_DC_DCNANO.GCREGHDISPLAY */
#define GFXSS_DC_DCNANO_GCREGHDISPLAY_GCREGHDISPLAY_DISPLAY_END_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGHDISPLAY_GCREGHDISPLAY_DISPLAY_END_Msk 0x1FFFUL
#define GFXSS_DC_DCNANO_GCREGHDISPLAY_GCREGHDISPLAY_TOTAL_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGHDISPLAY_GCREGHDISPLAY_TOTAL_Msk 0x1FFF0000UL
/* GFXSS_DC_DCNANO.GCREGHSYNC */
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_START_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_START_Msk 0x1FFFUL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_END_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_END_Msk 0x1FFF0000UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_PULSE_Pos 30UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_PULSE_Msk 0x40000000UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_POLARITY_Pos 31UL
#define GFXSS_DC_DCNANO_GCREGHSYNC_GCREGHSYNC_POLARITY_Msk 0x80000000UL
/* GFXSS_DC_DCNANO.GCREGVDISPLAY */
#define GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGVSYNC */
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START_Msk 0xFFFUL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END_Msk 0xFFF0000UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_PULSE_Pos 30UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_PULSE_Msk 0x40000000UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_POLARITY_Pos 31UL
#define GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_POLARITY_Msk 0x80000000UL
/* GFXSS_DC_DCNANO.GCREGDISPLAYCURRENTLOCATION */
#define GFXSS_DC_DCNANO_GCREGDISPLAYCURRENTLOCATION_GCREGDISPLAYCURRENTLOCATION_X_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYCURRENTLOCATION_GCREGDISPLAYCURRENTLOCATION_X_Msk 0xFFFFUL
#define GFXSS_DC_DCNANO_GCREGDISPLAYCURRENTLOCATION_GCREGDISPLAYCURRENTLOCATION_Y_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYCURRENTLOCATION_GCREGDISPLAYCURRENTLOCATION_Y_Msk 0xFFFF0000UL
/* GFXSS_DC_DCNANO.GCREGGAMMAINDEX */
#define GFXSS_DC_DCNANO_GCREGGAMMAINDEX_GCREGGAMMAINDEX_INDEX_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGGAMMAINDEX_GCREGGAMMAINDEX_INDEX_Msk 0xFFUL
/* GFXSS_DC_DCNANO.GCREGGAMMADATA */
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGGAMMADATA_GCREGGAMMADATA_RED_Msk 0xFF0000UL
/* GFXSS_DC_DCNANO.GCREGCURSORCONFIG */
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_FORMAT_Msk 0x3UL
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_HOT_SPOT_Y_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_HOT_SPOT_Y_Msk 0x1F00UL
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_HOT_SPOT_X_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGCURSORCONFIG_GCREGCURSORCONFIG_HOT_SPOT_X_Msk 0x1F0000UL
/* GFXSS_DC_DCNANO.GCREGCURSORADDRESS */
#define GFXSS_DC_DCNANO_GCREGCURSORADDRESS_GCREGCURSORADDRESS_ADDRESS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGCURSORADDRESS_GCREGCURSORADDRESS_ADDRESS_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGCURSORLOCATION */
#define GFXSS_DC_DCNANO_GCREGCURSORLOCATION_GCREGCURSORLOCATION_X_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGCURSORLOCATION_GCREGCURSORLOCATION_X_Msk 0x1FFFUL
#define GFXSS_DC_DCNANO_GCREGCURSORLOCATION_GCREGCURSORLOCATION_Y_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGCURSORLOCATION_GCREGCURSORLOCATION_Y_Msk 0xFFF0000UL
/* GFXSS_DC_DCNANO.GCREGCURSORBACKGROUND */
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGCURSORBACKGROUND_GCREGCURSORBACKGROUND_RED_Msk 0xFF0000UL
/* GFXSS_DC_DCNANO.GCREGCURSORFOREGROUND */
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_BLUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_BLUE_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_GREEN_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_GREEN_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_RED_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGCURSORFOREGROUND_GCREGCURSORFOREGROUND_RED_Msk 0xFF0000UL
/* GFXSS_DC_DCNANO.GCREGDISPLAYINTR */
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_DISP0_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_DISP0_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_DISP0_DBI_CFG_ERROR_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_DISP0_DBI_CFG_ERROR_Msk 0x1000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_PANEL_UNDERFLOW_Pos 29UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_PANEL_UNDERFLOW_Msk 0x20000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_SOFT_RESET_DONE_Pos 30UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_SOFT_RESET_DONE_Msk 0x40000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_BUS_ERROR_Pos 31UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTR_GCREGDISPLAYINTR_BUS_ERROR_Msk 0x80000000UL
/* GFXSS_DC_DCNANO.GCREGDISPLAYINTRENABLE */
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_Msk 0x1000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_PANEL_UNDERFLOW_Pos 29UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_PANEL_UNDERFLOW_Msk 0x20000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_SOFT_RESET_DONE_Pos 30UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_SOFT_RESET_DONE_Msk 0x40000000UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_BUS_ERROR_Pos 31UL
#define GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_BUS_ERROR_Msk 0x80000000UL
/* GFXSS_DC_DCNANO.GCREGDBICONFIG */
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_TYPE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_TYPE_Msk 0x3UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_DATA_FORMAT_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_DATA_FORMAT_Msk 0x3CUL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_BUS_OUTPUT_SEL_Pos 6UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_BUS_OUTPUT_SEL_Msk 0x40UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_AC_TIME_UNIT_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_AC_TIME_UNIT_Msk 0xF00UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_TYPEC_OPT_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDBICONFIG_GCREGDBICONFIG_DBI_TYPEC_OPT_Msk 0x3000UL
/* GFXSS_DC_DCNANO.GCREGDBIIFRESET */
#define GFXSS_DC_DCNANO_GCREGDBIIFRESET_GCREGDBIIFRESET_DBI_IF_LEVEL_RESET_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBIIFRESET_GCREGDBIIFRESET_DBI_IF_LEVEL_RESET_Msk 0x1UL
/* GFXSS_DC_DCNANO.GCREGDBIWRCHAR1 */
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_EOR_WR_ASSERT_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_EOR_WR_ASSERT_Msk 0xF00UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_CS_ASSERT_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_CS_ASSERT_Msk 0xF000UL
/* GFXSS_DC_DCNANO.GCREGDBIWRCHAR2 */
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR2_GCREGDBIWRCHAR2_DBI_WR_EOR_WR_DE_ASRT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR2_GCREGDBIWRCHAR2_DBI_WR_EOR_WR_DE_ASRT_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR2_GCREGDBIWRCHAR2_DBI_WR_CS_DE_ASRT_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGDBIWRCHAR2_GCREGDBIWRCHAR2_DBI_WR_CS_DE_ASRT_Msk 0xFF00UL
/* GFXSS_DC_DCNANO.GCREGDBICMD */
#define GFXSS_DC_DCNANO_GCREGDBICMD_GCREGDBICMD_DBI_COMMAND_WORD_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBICMD_GCREGDBICMD_DBI_COMMAND_WORD_Msk 0xFFFFUL
#define GFXSS_DC_DCNANO_GCREGDBICMD_GCREGDBICMD_DBI_COMMANDFLAG_Pos 30UL
#define GFXSS_DC_DCNANO_GCREGDBICMD_GCREGDBICMD_DBI_COMMANDFLAG_Msk 0xC0000000UL
/* GFXSS_DC_DCNANO.GCREGDPICONFIG */
#define GFXSS_DC_DCNANO_GCREGDPICONFIG_GCREGDPICONFIG_DPI_DATA_FORMAT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDPICONFIG_GCREGDPICONFIG_DPI_DATA_FORMAT_Msk 0x7UL
/* GFXSS_DC_DCNANO.GCREGDBITYPECCFG */
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_TAS_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_TAS_Msk 0xFUL
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_SCL_TWRL_Pos 4UL
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_SCL_TWRL_Msk 0xFF0UL
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_SCL_TWRH_Pos 12UL
#define GFXSS_DC_DCNANO_GCREGDBITYPECCFG_GCREGDBITYPECCFG_SCL_TWRH_Msk 0xFF000UL
/* GFXSS_DC_DCNANO.GCREGDCSTATUS */
#define GFXSS_DC_DCNANO_GCREGDCSTATUS_GCREGDCSTATUS_DBI_TYPEC_FIFO_FULL_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDCSTATUS_GCREGDCSTATUS_DBI_TYPEC_FIFO_FULL_Msk 0x1UL
/* GFXSS_DC_DCNANO.GCREGSRCCONFIGENDIAN */
#define GFXSS_DC_DCNANO_GCREGSRCCONFIGENDIAN_GCREGSRCCONFIGENDIAN_CONTROL_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGSRCCONFIGENDIAN_GCREGSRCCONFIGENDIAN_CONTROL_Msk 0x3UL
/* GFXSS_DC_DCNANO.GCREGSOFTRESET */
#define GFXSS_DC_DCNANO_GCREGSOFTRESET_GCREGSOFTRESET_RESET_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGSOFTRESET_GCREGSOFTRESET_RESET_Msk 0x1UL
/* GFXSS_DC_DCNANO.GCREGDCCONTROL */
#define GFXSS_DC_DCNANO_GCREGDCCONTROL_GCREGDCCONTROL_DEBUG_REGISTER_Pos 3UL
#define GFXSS_DC_DCNANO_GCREGDCCONTROL_GCREGDCCONTROL_DEBUG_REGISTER_Msk 0x8UL
#define GFXSS_DC_DCNANO_GCREGDCCONTROL_GCREGDCCONTROL_RAM_CLOCK_GATING_Pos 4UL
#define GFXSS_DC_DCNANO_GCREGDCCONTROL_GCREGDCCONTROL_RAM_CLOCK_GATING_Msk 0x10UL
/* GFXSS_DC_DCNANO.GCREGREGISTERTIMINGCONTROL */
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FOR_PF1P_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FOR_PF1P_Msk 0xFFUL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FOR_RF2P_Pos 8UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FOR_RF2P_Msk 0xFF00UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FAST_RTC_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FAST_RTC_Msk 0x30000UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FAST_WTC_Pos 18UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_FAST_WTC_Msk 0xC0000UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_POWER_DOWN_Pos 20UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_POWER_DOWN_Msk 0x100000UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_DEEP_SLEEP_Pos 21UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_DEEP_SLEEP_Msk 0x200000UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_LIGHT_SLEEP_Pos 22UL
#define GFXSS_DC_DCNANO_GCREGREGISTERTIMINGCONTROL_GCREGREGISTERTIMINGCONTROL_LIGHT_SLEEP_Msk 0x400000UL
/* GFXSS_DC_DCNANO.GCREGDEBUGCOUNTERSELECT */
#define GFXSS_DC_DCNANO_GCREGDEBUGCOUNTERSELECT_GCREGDEBUGCOUNTERSELECT_SELECT_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGCOUNTERSELECT_GCREGDEBUGCOUNTERSELECT_SELECT_Msk 0xFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGCOUNTERVALUE */
#define GFXSS_DC_DCNANO_GCREGDEBUGCOUNTERVALUE_GCREGDEBUGCOUNTERVALUE_VALUE_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGCOUNTERVALUE_GCREGDEBUGCOUNTERVALUE_VALUE_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGLAYERCLOCKGATE */
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_VIDEO_CLK_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_VIDEO_CLK_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_Msk 0x2UL
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_Pos 2UL
#define GFXSS_DC_DCNANO_GCREGLAYERCLOCKGATE_GCREGLAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_Msk 0x4UL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTVIDEOREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTVIDEOREQ_GCREGDEBUGTOTVIDEOREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTVIDEOREQ_GCREGDEBUGTOTVIDEOREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTVIDEOREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTVIDEOREQ_GCREGDEBUGLSTVIDEOREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTVIDEOREQ_GCREGDEBUGLSTVIDEOREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTVIDEORRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTVIDEORRB_GCREGDEBUGTOTVIDEORRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTVIDEORRB_GCREGDEBUGTOTVIDEORRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTVIDEORRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTVIDEORRB_GCREGDEBUGLSTVIDEORRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTVIDEORRB_GCREGDEBUGLSTVIDEORRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTOVERLAY0REQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY0REQ_GCREGDEBUGTOTOVERLAY0REQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY0REQ_GCREGDEBUGTOTOVERLAY0REQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTOVERLAY0REQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY0REQ_GCREGDEBUGLSTOVERLAY0REQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY0REQ_GCREGDEBUGLSTOVERLAY0REQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTOVERLAY0RRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY0RRB_GCREGDEBUGTOTOVERLAY0RRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY0RRB_GCREGDEBUGTOTOVERLAY0RRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTOVERLAY0RRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY0RRB_GCREGDEBUGLSTOVERLAY0RRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY0RRB_GCREGDEBUGLSTOVERLAY0RRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTOVERLAY1REQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY1REQ_GCREGDEBUGTOTOVERLAY1REQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY1REQ_GCREGDEBUGTOTOVERLAY1REQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTOVERLAY1REQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY1REQ_GCREGDEBUGLSTOVERLAY1REQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY1REQ_GCREGDEBUGLSTOVERLAY1REQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTOVERLAY1RRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY1RRB_GCREGDEBUGTOTOVERLAY1RRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTOVERLAY1RRB_GCREGDEBUGTOTOVERLAY1RRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTOVERLAY1RRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY1RRB_GCREGDEBUGLSTOVERLAY1RRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTOVERLAY1RRB_GCREGDEBUGLSTOVERLAY1RRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTCURSORREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTCURSORREQ_GCREGDEBUGTOTCURSORREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTCURSORREQ_GCREGDEBUGTOTCURSORREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTCURSORREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTCURSORREQ_GCREGDEBUGLSTCURSORREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTCURSORREQ_GCREGDEBUGLSTCURSORREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTCURSORRRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTCURSORRRB_GCREGDEBUGTOTCURSORRRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTCURSORRRB_GCREGDEBUGTOTCURSORRRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTCURSORRRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTCURSORRRB_GCREGDEBUGLSTCURSORRRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTCURSORRRB_GCREGDEBUGLSTCURSORRRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTDCREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTDCREQ_GCREGDEBUGTOTDCREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTDCREQ_GCREGDEBUGTOTDCREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTDCREQ */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTDCREQ_GCREGDEBUGLSTDCREQ_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTDCREQ_GCREGDEBUGLSTDCREQ_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGTOTDCRRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTDCRRB_GCREGDEBUGTOTDCRRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGTOTDCRRB_GCREGDEBUGTOTDCRRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGLSTDCRRB */
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTDCRRB_GCREGDEBUGLSTDCRRB_NUM_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGLSTDCRRB_GCREGDEBUGLSTDCRRB_NUM_Msk 0xFFFFFFFFUL
/* GFXSS_DC_DCNANO.GCREGDEBUGFRAMEANDMISFLAG */
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_MISMATCH_FLAG_TOTAL_Pos 0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_MISMATCH_FLAG_TOTAL_Msk 0x1UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_MISMATCH_FLAG_Pos 1UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_MISMATCH_FLAG_Msk 0x1EUL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_FRAME_CNT_Pos 5UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_CURRENT_FRAME_CNT_Msk 0xFFE0UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_MISMATCH_FLAG_TOTAL_Pos 16UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_MISMATCH_FLAG_TOTAL_Msk 0x10000UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_MISMATCH_FLAG_Pos 17UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_MISMATCH_FLAG_Msk 0x1E0000UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_FRAME_CNT_Pos 21UL
#define GFXSS_DC_DCNANO_GCREGDEBUGFRAMEANDMISFLAG_GCREGDEBUGFRAMEANDMISFLAG_LAST_FRAME_CNT_Msk 0xFFE00000UL


/* GFXSS_MIPIDSI_MXMIPIDSI.CTL */
#define GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Pos 31UL
#define GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Msk 0x80000000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.CLK_CTL */
#define GFXSS_MIPIDSI_MXMIPIDSI_CLK_CTL_CLK_CFG_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_CLK_CTL_CLK_CFG_Msk 0x1UL
/* GFXSS_MIPIDSI_MXMIPIDSI.INTR */
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_CORE_Pos   0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_CORE_Msk   0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_DBI_TE_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_DBI_TE_Msk 0x100UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_DPI_HALT_Pos 16UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_DPI_HALT_Msk 0x10000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.INTR_SET */
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_CORE_SET_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_CORE_SET_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_DBI_TE_SET_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_DBI_TE_SET_Msk 0x100UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_DPI_HALT_SET_Pos 16UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_SET_DPI_HALT_SET_Msk 0x10000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.INTR_MASK */
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_CORE_MASK_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_CORE_MASK_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DBI_TE_MASK_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DBI_TE_MASK_Msk 0x100UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DPI_HALT_MASK_Pos 16UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DPI_HALT_MASK_Msk 0x10000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.INTR_MASKED */
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_CORE_MASKED_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_CORE_MASKED_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_DBI_TE_MASKED_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_DBI_TE_MASKED_Msk 0x100UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_DPI_HALT_MASKED_Pos 16UL
#define GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASKED_DPI_HALT_MASKED_Msk 0x10000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.DPI_CMD */
#define GFXSS_MIPIDSI_MXMIPIDSI_DPI_CMD_DPI_SHUTDOWN_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_DPI_CMD_DPI_SHUTDOWN_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_DPI_CMD_DPI_COLORMODE_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_DPI_CMD_DPI_COLORMODE_Msk 0x100UL
/* GFXSS_MIPIDSI_MXMIPIDSI.DBI_CMD */
#define GFXSS_MIPIDSI_MXMIPIDSI_DBI_CMD_DBI_RESET_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_DBI_CMD_DBI_RESET_Msk 0x1UL
/* GFXSS_MIPIDSI_MXMIPIDSI.PHY_FREQ_RANGE */
#define GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_CFG_CLK_FREQ_RANGE_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_CFG_CLK_FREQ_RANGE_Msk 0xFFUL
#define GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_HS_FREQ_RANGE_Pos 8UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_HS_FREQ_RANGE_Msk 0x7F00UL
/* GFXSS_MIPIDSI_MXMIPIDSI.BIST */
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_ON_Pos     0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_ON_Msk     0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_DONE_Pos   1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_DONE_Msk   0x2UL
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_OK_Pos     2UL
#define GFXSS_MIPIDSI_MXMIPIDSI_BIST_OK_Msk     0x4UL
/* GFXSS_MIPIDSI_MXMIPIDSI.IO_CONTINUITY_TEST */
#define GFXSS_MIPIDSI_MXMIPIDSI_IO_CONTINUITY_TEST_EN_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_IO_CONTINUITY_TEST_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_IO_CONTINUITY_TEST_DATA_Pos 1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_IO_CONTINUITY_TEST_DATA_Msk 0xFEUL
/* GFXSS_MIPIDSI_MXMIPIDSI.PLL_TEST_CONFIG1 */
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_VCO_CNTRL_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_VCO_CNTRL_Msk 0x3FUL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_PROP_CNTRL_Pos 6UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_PROP_CNTRL_Msk 0xFC0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_INT_CNTRL_Pos 12UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_INT_CNTRL_Msk 0x3F000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_GMP_CNTRL_Pos 18UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_GMP_CNTRL_Msk 0xC0000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_CPBIAS_CNTRL_Pos 20UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG1_CPBIAS_CNTRL_Msk 0x7F00000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.PLL_TEST_CONFIG2 */
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_GP_CLK_EN_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_GP_CLK_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_LOCK_PLL_Pos 1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_LOCK_PLL_Msk 0x2UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_N_Pos 2UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_N_Msk 0x3CUL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_M_Pos 6UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_M_Msk 0xFFC0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_CLKSEL_Pos 16UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_CLKSEL_Msk 0x30000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_UPDATEPLL_Pos 18UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_UPDATEPLL_Msk 0x40000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_FORCE_LOCK_Pos 19UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_FORCE_LOCK_Msk 0x80000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_SHADOW_CONTROL_Pos 20UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_PLL_SHADOW_CONTROL_Msk 0x100000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_SHADOW_CLEAR_Pos 21UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_SHADOW_CLEAR_Msk 0x200000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_TEST_STOP_CLK_EN_Pos 22UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_TEST_STOP_CLK_EN_Msk 0x400000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_WAKEUPPLL_Pos 23UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_CONFIG2_WAKEUPPLL_Msk 0x800000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.PLL_TEST_OBS1 */
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_VCO_CNTRL_OBS_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_VCO_CNTRL_OBS_Msk 0x3FUL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_PROP_CNTRL_OBS_Pos 6UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_PROP_CNTRL_OBS_Msk 0xFC0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_INT_CNTRL_OBS_Pos 12UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_INT_CNTRL_OBS_Msk 0x3F000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_GMP_CNTRL_OBS_Pos 18UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_GMP_CNTRL_OBS_Msk 0xC0000UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_CPBIAS_CNTRL_OBS_Pos 20UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS1_CPBIAS_CNTRL_OBS_Msk 0x7F00000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.PLL_TEST_OBS2 */
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_N_OBS_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_N_OBS_Msk 0xFUL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_M_OBS_Pos 4UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_M_OBS_Msk 0x3FF0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_SHADOW_CONTROL_OBS_Pos 14UL
#define GFXSS_MIPIDSI_MXMIPIDSI_PLL_TEST_OBS2_PLL_SHADOW_CONTROL_OBS_Msk 0x4000UL
/* GFXSS_MIPIDSI_MXMIPIDSI.LP_INTERNAL_LOOPBACK_TEST */
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXDATAESC_VALID_Pos 0UL
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXDATAESC_VALID_Msk 0x1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXDATAESC_Pos 1UL
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXDATAESC_Msk 0x1FEUL
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXTRIGGERESC_Pos 9UL
#define GFXSS_MIPIDSI_MXMIPIDSI_LP_INTERNAL_LOOPBACK_TEST_RXTRIGGERESC_Msk 0x1E00UL


/* GFXSS_MIPIDSI_DWCMIPIDSI.VERSION */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VERSION_VERSION_VERSION_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VERSION_VERSION_VERSION_Msk 0xFFFFFFFFUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PWR_UP */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_RESERVED_31_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_RESERVED_31_1_Msk 0xFFFFFFFEUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.CLKMGR_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_TX_ESC_CLK_DIVISION_Msk 0xFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_TO_CLK_DIVISION_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_TO_CLK_DIVISION_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CLKMGR_CFG_CLKMGR_CFG_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_VCID */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_DPI_VCID_DPI_VCID_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_DPI_VCID_DPI_VCID_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_DPI_VCID_RESERVED_31_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_DPI_VCID_RESERVED_31_2_Msk 0xFFFFFFFCUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_COLOR_CODING */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_DPI_COLOR_CODING_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_DPI_COLOR_CODING_Msk 0xFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_RESERVED_7_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_RESERVED_7_4_Msk 0xF0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_LOOSELY18_EN_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_LOOSELY18_EN_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_RESERVED_31_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_DPI_COLOR_CODING_RESERVED_31_9_Msk 0xFFFFFE00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_CFG_POL */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_DATAEN_ACTIVE_LOW_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_VSYNC_ACTIVE_LOW_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_HSYNC_ACTIVE_LOW_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_SHUTD_ACTIVE_LOW_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_COLORM_ACTIVE_LOW_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_COLORM_ACTIVE_LOW_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_RESERVED_31_5_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_CFG_POL_DPI_CFG_POL_RESERVED_31_5_Msk 0xFFFFFFE0UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_LP_CMD_TIM */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_INVACT_LPCMD_TIME_Msk 0xFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_RESERVED_15_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_RESERVED_15_8_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_OUTVACT_LPCMD_TIME_Msk 0xFF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_RESERVED_31_24_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_DPI_LP_CMD_TIM_RESERVED_31_24_Msk 0xFF000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DBI_VCID */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_VCID_DBI_VCID_DBI_VCID_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_VCID_DBI_VCID_DBI_VCID_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_VCID_DBI_VCID_RESERVED_31_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_VCID_DBI_VCID_RESERVED_31_2_Msk 0xFFFFFFFCUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DBI_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_IN_DBI_CONF_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_IN_DBI_CONF_Msk 0xFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_7_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_7_4_Msk 0xF0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_OUT_DBI_CONF_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_OUT_DBI_CONF_Msk 0xF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_15_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_15_12_Msk 0xF000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_LUT_SIZE_CONF_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_LUT_SIZE_CONF_Msk 0x30000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_31_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_RESERVED_31_18_Msk 0xFFFC0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DBI_PARTITIONING_EN */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_PARTITIONING_EN_DBI_PARTITIONING_EN_PARTITIONING_EN_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_PARTITIONING_EN_DBI_PARTITIONING_EN_PARTITIONING_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_PARTITIONING_EN_DBI_PARTITIONING_EN_RESERVED_31_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_PARTITIONING_EN_DBI_PARTITIONING_EN_RESERVED_31_1_Msk 0xFFFFFFFEUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DBI_CMDSIZE */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PCKHDL_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_TX_EN_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_TX_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_RX_EN_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_RX_EN_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_BTA_EN_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_BTA_EN_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_ECC_RX_EN_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_ECC_RX_EN_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_CRC_RX_EN_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_CRC_RX_EN_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_TX_LP_EN_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_EOTP_TX_LP_EN_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_RESERVED_31_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PCKHDL_CFG_PCKHDL_CFG_RESERVED_31_6_Msk 0xFFFFFFC0UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.GEN_VCID */
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_RX_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_RX_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_7_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_7_2_Msk 0xFCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_TEAR_AUTO_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_TEAR_AUTO_Msk 0x300UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_15_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_15_10_Msk 0xFC00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_TX_AUTO_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_GEN_VCID_TX_AUTO_Msk 0x30000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_31_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_VCID_GEN_VCID_RESERVED_31_18_Msk 0xFFFC0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.MODE_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_MODE_CFG_MODE_CFG_CMD_VIDEO_MODE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_MODE_CFG_MODE_CFG_CMD_VIDEO_MODE_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_MODE_CFG_MODE_CFG_RESERVED_31_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_MODE_CFG_MODE_CFG_RESERVED_31_1_Msk 0xFFFFFFFEUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_MODE_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VID_MODE_TYPE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VID_MODE_TYPE_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_7_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_7_2_Msk 0xFCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VSA_EN_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VSA_EN_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VBP_EN_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VBP_EN_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VFP_EN_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VFP_EN_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VACT_EN_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_VACT_EN_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_HBP_EN_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_HBP_EN_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_HFP_EN_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_HFP_EN_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_FRAME_BTA_ACK_EN_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_FRAME_BTA_ACK_EN_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_CMD_EN_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_LP_CMD_EN_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_EN_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_EN_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_19_17_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_19_17_Msk 0xE0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_MODE_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_MODE_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_23_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_23_21_Msk 0xE00000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_ORIENTATION_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_VPG_ORIENTATION_Msk 0x1000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_31_25_Pos 25UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_VID_MODE_CFG_RESERVED_31_25_Msk 0xFE000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_PKT_SIZE */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_VID_PKT_SIZE_VID_PKT_SIZE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_VID_PKT_SIZE_VID_PKT_SIZE_Msk 0x3FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_VID_PKT_SIZE_RESERVED_31_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_VID_PKT_SIZE_RESERVED_31_14_Msk 0xFFFFC000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_NUM_CHUNKS */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_VID_NUM_CHUNKS_Msk 0x1FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_RESERVED_31_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_VID_NUM_CHUNKS_RESERVED_31_13_Msk 0xFFFFE000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_NULL_SIZE */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_VID_NULL_SIZE_VID_NULL_SIZE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_VID_NULL_SIZE_VID_NULL_SIZE_Msk 0x1FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_VID_NULL_SIZE_RESERVED_31_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_VID_NULL_SIZE_RESERVED_31_13_Msk 0xFFFFE000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HSA_TIME */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_VID_HSA_TIME_VID_HSA_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_VID_HSA_TIME_VID_HSA_TIME_Msk 0xFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_VID_HSA_TIME_RESERVED_31_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_VID_HSA_TIME_RESERVED_31_12_Msk 0xFFFFF000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HBP_TIME */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_VID_HBP_TIME_VID_HBP_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_VID_HBP_TIME_VID_HBP_TIME_Msk 0xFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_VID_HBP_TIME_RESERVED_31_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_VID_HBP_TIME_RESERVED_31_12_Msk 0xFFFFF000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HLINE_TIME */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_VID_HLINE_TIME_VID_HLINE_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_VID_HLINE_TIME_VID_HLINE_TIME_Msk 0x7FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_VID_HLINE_TIME_RESERVED_31_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_VID_HLINE_TIME_RESERVED_31_15_Msk 0xFFFF8000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VSA_LINES */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_VID_VSA_LINES_VSA_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_VID_VSA_LINES_VSA_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_VID_VSA_LINES_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_VID_VSA_LINES_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VBP_LINES */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_VID_VBP_LINES_VBP_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_VID_VBP_LINES_VBP_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_VID_VBP_LINES_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_VID_VBP_LINES_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VFP_LINES */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_VID_VFP_LINES_VFP_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_VID_VFP_LINES_VFP_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_VID_VFP_LINES_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_VID_VFP_LINES_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VACTIVE_LINES */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_VID_VACTIVE_LINES_V_ACTIVE_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_VID_VACTIVE_LINES_V_ACTIVE_LINES_Msk 0x3FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_VID_VACTIVE_LINES_RESERVED_31_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_VID_VACTIVE_LINES_RESERVED_31_14_Msk 0xFFFFC000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.CMD_MODE_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_TEAR_FX_EN_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_TEAR_FX_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_ACK_RQST_EN_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_ACK_RQST_EN_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_7_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_7_2_Msk 0xFCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_0P_TX_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_0P_TX_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_1P_TX_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_1P_TX_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_2P_TX_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SW_2P_TX_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_0P_TX_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_0P_TX_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_1P_TX_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_1P_TX_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_2P_TX_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_SR_2P_TX_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_LW_TX_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_GEN_LW_TX_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_15_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_0P_TX_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_0P_TX_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_1P_TX_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_1P_TX_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SR_0P_TX_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SR_0P_TX_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_LW_TX_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_LW_TX_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_23_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_23_20_Msk 0xF00000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_MAX_RD_PKT_SIZE_Msk 0x1000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_31_25_Pos 25UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_RESERVED_31_25_Msk 0xFE000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.GEN_HDR */
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_DT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_DT_Msk 0x3FUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_VC_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_VC_Msk 0xC0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_WC_LSBYTE_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_WC_LSBYTE_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_WC_MSBYTE_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_GEN_WC_MSBYTE_Msk 0xFF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_RESERVED_31_24_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_HDR_GEN_HDR_RESERVED_31_24_Msk 0xFF000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.GEN_PLD_DATA */
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B1_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B1_Msk 0xFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B2_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B2_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B3_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B3_Msk 0xFF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B4_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_GEN_PLD_DATA_GEN_PLD_DATA_GEN_PLD_B4_Msk 0xFF000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.CMD_PKT_STATUS */
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_CMD_EMPTY_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_CMD_EMPTY_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_CMD_FULL_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_CMD_FULL_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_W_FULL_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_W_FULL_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_R_EMPTY_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_R_FULL_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_R_FULL_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_RD_CMD_BUSY_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_7_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_7_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_CMD_EMPY_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_CMD_EMPY_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_CMD_FULL_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_CMD_FULL_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_W_EMPTY_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_W_EMPTY_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_W_FULL_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_W_FULL_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_R_EMPTY_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_R_EMPTY_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_R_FULL_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_PLD_R_FULL_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_RD_CMD_BUSY_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_RD_CMD_BUSY_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_15_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_CMD_EMPTY_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_CMD_FULL_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_PLD_FULL_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_23_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_23_20_Msk 0xF00000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_CMD_EMPTY_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_CMD_EMPTY_Msk 0x1000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_CMD_FULL_Pos 25UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_CMD_FULL_Msk 0x2000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_PLD_EMPTY_Pos 26UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_PLD_EMPTY_Msk 0x4000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_PLD_FULL_Pos 27UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_DBI_BUFF_PLD_FULL_Msk 0x8000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_31_28_Pos 28UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_RESERVED_31_28_Msk 0xF0000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.TO_CNT_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_TO_CNT_CFG_TO_CNT_CFG_LPRX_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_TO_CNT_CFG_TO_CNT_CFG_LPRX_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_TO_CNT_CFG_TO_CNT_CFG_HSTX_TO_CNT_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_TO_CNT_CFG_TO_CNT_CFG_HSTX_TO_CNT_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.HS_RD_TO_CNT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_RD_TO_CNT_HS_RD_TO_CNT_HS_RD_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_RD_TO_CNT_HS_RD_TO_CNT_HS_RD_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_RD_TO_CNT_HS_RD_TO_CNT_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_RD_TO_CNT_HS_RD_TO_CNT_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.LP_RD_TO_CNT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_RD_TO_CNT_LP_RD_TO_CNT_LP_RD_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_RD_TO_CNT_LP_RD_TO_CNT_LP_RD_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_RD_TO_CNT_LP_RD_TO_CNT_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_RD_TO_CNT_LP_RD_TO_CNT_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.HS_WR_TO_CNT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_HS_WR_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_HS_WR_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_23_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_23_16_Msk 0xFF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_24_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_24_Msk 0x1000000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_31_25_Pos 25UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_HS_WR_TO_CNT_HS_WR_TO_CNT_RESERVED_31_25_Msk 0xFE000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.LP_WR_TO_CNT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_WR_TO_CNT_LP_WR_TO_CNT_LP_WR_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_WR_TO_CNT_LP_WR_TO_CNT_LP_WR_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_WR_TO_CNT_LP_WR_TO_CNT_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LP_WR_TO_CNT_LP_WR_TO_CNT_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.BTA_TO_CNT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_BTA_TO_CNT_BTA_TO_CNT_BTA_TO_CNT_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_BTA_TO_CNT_BTA_TO_CNT_BTA_TO_CNT_Msk 0xFFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_BTA_TO_CNT_BTA_TO_CNT_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_BTA_TO_CNT_BTA_TO_CNT_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.SDF_3D */
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_MODE_3D_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_MODE_3D_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_FORMAT_3D_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_FORMAT_3D_Msk 0xCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_SECOND_VSYNC_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_SECOND_VSYNC_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RIGHT_FIRST_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RIGHT_FIRST_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RESERVED_15_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RESERVED_15_6_Msk 0xFFC0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_SEND_3D_CFG_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_SEND_3D_CFG_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RESERVED_31_17_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_SDF_3D_RESERVED_31_17_Msk 0xFFFE0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.LPCLK_CTRL */
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_PHY_TXREQUESTCLKHS_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_AUTO_CLKLANE_CTRL_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_RESERVED_31_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_LPCLK_CTRL_LPCLK_CTRL_RESERVED_31_2_Msk 0xFFFFFFFCUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TMR_LPCLK_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_PHY_CLKLP2HS_TIME_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_RESERVED_15_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_RESERVED_15_10_Msk 0xFC00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_PHY_CLKHS2LP_TIME_Msk 0x3FF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_RESERVED_31_26_Pos 26UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_LPCLK_CFG_PHY_TMR_LPCLK_CFG_RESERVED_31_26_Msk 0xFC000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TMR_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_PHY_LP2HS_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_PHY_LP2HS_TIME_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_RESERVED_15_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_RESERVED_15_10_Msk 0xFC00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_PHY_HS2LP_TIME_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_PHY_HS2LP_TIME_Msk 0x3FF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_RESERVED_31_26_Pos 26UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_CFG_PHY_TMR_CFG_RESERVED_31_26_Msk 0xFC000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_RSTZ */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_SHUTDOWNZ_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_SHUTDOWNZ_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_RSTZ_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_RSTZ_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_ENABLECLK_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_ENABLECLK_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_FORCEPLL_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_PHY_FORCEPLL_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_RESERVED_31_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_RSTZ_PHY_RSTZ_RESERVED_31_4_Msk 0xFFFFFFF0UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_IF_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_RESERVED_7_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_RESERVED_7_2_Msk 0xFCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_PHY_STOP_WAIT_TIME_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_PHY_STOP_WAIT_TIME_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_RESERVED_31_16_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_RESERVED_31_16_Msk 0xFFFF0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_ULPS_CTRL */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSCLK_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSCLK_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSCLK_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSLAN_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSLAN_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSLAN_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_RESERVED_31_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_RESERVED_31_4_Msk 0xFFFFFFF0UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TX_TRIGGERS */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_Msk 0xFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_RESERVED_31_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TX_TRIGGERS_PHY_TX_TRIGGERS_RESERVED_31_4_Msk 0xFFFFFFF0UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_STATUS */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_LOCK_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_LOCK_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_DIRECTION_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_DIRECTION_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATECLKLANE_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATECLKLANE_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOTCLK_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOTCLK_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATE0LANE_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATE0LANE_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOT0LANE_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOT0LANE_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_RXULPSESC0LANE_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_RXULPSESC0LANE_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATE1LANE_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_STOPSTATE1LANE_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOT1LANE_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_PHY_ULPSACTIVENOT1LANE_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_9_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_10_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_11_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_11_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_12_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_31_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_STATUS_PHY_STATUS_RESERVED_31_13_Msk 0xFFFFE000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TST_CTRL0 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_PHY_TESTCLR_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_PHY_TESTCLR_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_PHY_TESTCLK_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_PHY_TESTCLK_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_RESERVED_31_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL0_PHY_TST_CTRL0_RESERVED_31_2_Msk 0xFFFFFFFCUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TST_CTRL1 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTDIN_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTDIN_Msk 0xFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHT_TESTDOUT_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHT_TESTDOUT_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTEN_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTEN_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTSEL_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_PHY_TESTSEL_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_RESERVED_31_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TST_CTRL1_PHY_TST_CTRL1_RESERVED_31_18_Msk 0xFFFC0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_ST0 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_0_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_0_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_1_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_2_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_3_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_3_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_4_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_5_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_5_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_6_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_7_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_7_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_8_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_9_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_10_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_11_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_11_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_12_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_13_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_14_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_ACK_WITH_ERR_15_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_0_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_0_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_1_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_1_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_2_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_2_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_3_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_3_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_4_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_DPHY_ERRORS_4_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST0_INT_ST0_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_ST1 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_TO_HS_TX_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_TO_HS_TX_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_TO_LP_RX_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_TO_LP_RX_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_ECC_SINGLE_ERR_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_ECC_SINGLE_ERR_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_ECC_MULTPL_ERR_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_ECC_MULTPL_ERR_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_CRC_ERR_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_CRC_ERR_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_PKT_SIZE_ERR_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_PKT_SIZE_ERR_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_EOPT_ERR_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_EOPT_ERR_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DPI_PLD_WR_ERR_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DPI_PLD_WR_ERR_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_CMD_WR_ERR_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_CMD_WR_ERR_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_WR_ERR_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_WR_ERR_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_SEND_ERR_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_SEND_ERR_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_RD_ERR_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_RD_ERR_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_RECEV_ERR_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_GEN_PLD_RECEV_ERR_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_CMD_WR_ERR_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_CMD_WR_ERR_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_WR_ERR_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_WR_ERR_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_RD_ERR_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_RD_ERR_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_RECV_ERR_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_PLD_RECV_ERR_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_ILEGAL_COMM_ERR_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DBI_ILEGAL_COMM_ERR_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_18_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DPI_BUFF_PLD_UNDER_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_DPI_BUFF_PLD_UNDER_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_20_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_ST1_INT_ST1_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_MSK0 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_0_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_0_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_1_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_2_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_3_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_3_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_4_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_5_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_5_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_6_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_7_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_7_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_8_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_9_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_10_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_11_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_11_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_12_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_13_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_14_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_ACK_WITH_ERR_15_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_0_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_0_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_1_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_1_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_2_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_2_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_3_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_3_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_4_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_MASK_DPHY_ERRORS_4_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK0_INT_MSK0_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_MSK1 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_TO_HS_TX_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_TO_HS_TX_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_TO_LP_RX_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_TO_LP_RX_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_ECC_SINGLE_ERR_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_ECC_SINGLE_ERR_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_ECC_MULTPL_ERR_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_ECC_MULTPL_ERR_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_CRC_ERR_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_CRC_ERR_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_PKT_SIZE_ERR_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_PKT_SIZE_ERR_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_EOPT_ERR_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_EOPT_ERR_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DPI_PLD_WR_ERR_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DPI_PLD_WR_ERR_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_CMD_WR_ERR_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_CMD_WR_ERR_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_WR_ERR_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_WR_ERR_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_SEND_ERR_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_SEND_ERR_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_RD_ERR_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_RD_ERR_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_RECEV_ERR_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_GEN_PLD_RECEV_ERR_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_CMD_WR_ERR_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_CMD_WR_ERR_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_WR_ERR_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_WR_ERR_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_RD_ERR_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_RD_ERR_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_RECV_ERR_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_PLD_RECV_ERR_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_ILEGAL_COMM_ERR_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DBI_ILEGAL_COMM_ERR_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_18_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DPI_BUFF_PLD_UNDER_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_MASK_DPI_BUFF_PLD_UNDER_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_20_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_MSK1_INT_MSK1_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_CAL */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_CAL_PHY_CAL_TXSKEWCALHS_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_CAL_PHY_CAL_TXSKEWCALHS_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_CAL_PHY_CAL_RESERVED_31_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_CAL_PHY_CAL_RESERVED_31_1_Msk 0xFFFFFFFEUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_FORCE0 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_0_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_0_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_1_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_2_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_3_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_3_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_4_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_5_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_5_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_6_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_7_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_7_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_8_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_9_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_10_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_11_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_11_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_12_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_13_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_14_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_ACK_WITH_ERR_15_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_0_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_0_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_1_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_1_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_2_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_2_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_3_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_3_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_4_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_FORCE_DPHY_ERRORS_4_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE0_INT_FORCE0_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.INT_FORCE1 */
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_TO_HS_TX_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_TO_HS_TX_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_TO_LP_RX_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_TO_LP_RX_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_ECC_SINGLE_ERR_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_ECC_SINGLE_ERR_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_ECC_MULTPL_ERR_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_ECC_MULTPL_ERR_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_CRC_ERR_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_CRC_ERR_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_PKT_SIZE_ERR_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_PKT_SIZE_ERR_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_EOPT_ERR_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_EOPT_ERR_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DPI_PLD_WR_ERR_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DPI_PLD_WR_ERR_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_CMD_WR_ERR_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_CMD_WR_ERR_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_WR_ERR_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_WR_ERR_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_SEND_ERR_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_SEND_ERR_Msk 0x400UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_RD_ERR_Pos 11UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_RD_ERR_Msk 0x800UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_RECEV_ERR_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_GEN_PLD_RECEV_ERR_Msk 0x1000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_CMD_WR_ERR_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_CMD_WR_ERR_Msk 0x2000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_WR_ERR_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_WR_ERR_Msk 0x4000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_RD_ERR_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_RD_ERR_Msk 0x8000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_RECV_ERR_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_PLD_RECV_ERR_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_ILEGAL_COMM_ERR_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DBI_ILEGAL_COMM_ERR_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_18_Msk 0x40000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DPI_BUFF_PLD_UNDER_Pos 19UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_FORCE_DPI_BUFF_PLD_UNDER_Msk 0x80000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_20_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_31_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_INT_FORCE1_INT_FORCE1_RESERVED_31_21_Msk 0xFFE00000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DSC_PARAMETER */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_COMPRESSION_MODE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_COMPRESSION_MODE_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_7_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_7_1_Msk 0xFEUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_COMPRESS_ALGO_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_COMPRESS_ALGO_Msk 0x300UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_15_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_15_10_Msk 0xFC00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_PPS_SEL_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_PPS_SEL_Msk 0x30000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_31_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DSC_PARAMETER_DSC_PARAMETER_RESERVED_31_18_Msk 0xFFFC0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.PHY_TMR_RD_CFG */
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_RD_CFG_PHY_TMR_RD_CFG_MAX_RD_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_RD_CFG_PHY_TMR_RD_CFG_MAX_RD_TIME_Msk 0x7FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_RD_CFG_PHY_TMR_RD_CFG_RESERVED_31_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_PHY_TMR_RD_CFG_PHY_TMR_RD_CFG_RESERVED_31_15_Msk 0xFFFF8000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_SHADOW_CTRL */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_EN_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_EN_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_7_1_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_7_1_Msk 0xFEUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_REQ_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_REQ_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_15_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_15_9_Msk 0xFE00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_PIN_REQ_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_VID_SHADOW_PIN_REQ_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_31_17_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_SHADOW_CTRL_VID_SHADOW_CTRL_RESERVED_31_17_Msk 0xFFFE0000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_VCID_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_ACT_DPI_VCID_ACT_DPI_VCID_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_ACT_DPI_VCID_ACT_DPI_VCID_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_ACT_DPI_VCID_ACT_RESERVED_31_2_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_VCID_ACT_DPI_VCID_ACT_RESERVED_31_2_Msk 0xFFFFFFFCUL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_COLOR_CODING_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_Msk 0xFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_RESERVED_7_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_RESERVED_7_4_Msk 0xF0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_LOOSELY18_EN_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_RESERVED_31_9_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_COLOR_CODING_ACT_DPI_COLOR_CODING_ACT_RESERVED_31_9_Msk 0xFFFFFE00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.DPI_LP_CMD_TIM_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_INVACT_LPCMD_TIME_Msk 0xFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_RESERVED_15_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_RESERVED_15_8_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_OUTVACT_LPCMD_TIME_Msk 0xFF0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_RESERVED_31_24_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_DPI_LP_CMD_TIM_ACT_DPI_LP_CMD_TIM_ACT_RESERVED_31_24_Msk 0xFF000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_MODE_CFG_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_VID_MODE_TYPE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_VID_MODE_TYPE_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VSA_EN_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VSA_EN_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VBP_EN_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VBP_EN_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VFP_EN_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VFP_EN_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VACT_EN_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_VACT_EN_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_HBP_EN_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_HBP_EN_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_HFP_EN_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_HFP_EN_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_FRAME_BTA_ACK_EN_Msk 0x100UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_CMD_EN_Pos 9UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_LP_CMD_EN_Msk 0x200UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_MODE_CFG_ACT_VID_MODE_CFG_ACT_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_PKT_SIZE_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_ACT_VID_PKT_SIZE_Msk 0x3FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_ACT_RESERVED_31_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_SIZE_ACT_VID_PKT_SIZE_ACT_RESERVED_31_14_Msk 0xFFFFC000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_NUM_CHUNKS_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_Msk 0x1FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_ACT_RESERVED_31_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NUM_CHUNKS_ACT_VID_NUM_CHUNKS_ACT_RESERVED_31_13_Msk 0xFFFFE000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_NULL_SIZE_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_ACT_VID_NULL_SIZE_Msk 0x1FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_ACT_RESERVED_31_13_Pos 13UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_NULL_SIZE_ACT_VID_NULL_SIZE_ACT_RESERVED_31_13_Msk 0xFFFFE000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HSA_TIME_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_ACT_VID_HSA_TIME_ACT_VID_HSA_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_ACT_VID_HSA_TIME_ACT_VID_HSA_TIME_Msk 0xFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_ACT_VID_HSA_TIME_ACT_RESERVED_31_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HSA_TIME_ACT_VID_HSA_TIME_ACT_RESERVED_31_12_Msk 0xFFFFF000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HBP_TIME_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_ACT_VID_HBP_TIME_ACT_VID_HBP_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_ACT_VID_HBP_TIME_ACT_VID_HBP_TIME_Msk 0xFFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_ACT_VID_HBP_TIME_ACT_RESERVED_31_12_Pos 12UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HBP_TIME_ACT_VID_HBP_TIME_ACT_RESERVED_31_12_Msk 0xFFFFF000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_HLINE_TIME_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_ACT_VID_HLINE_TIME_Msk 0x7FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_ACT_RESERVED_31_15_Pos 15UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_HLINE_TIME_ACT_VID_HLINE_TIME_ACT_RESERVED_31_15_Msk 0xFFFF8000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VSA_LINES_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_ACT_VID_VSA_LINES_ACT_VSA_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_ACT_VID_VSA_LINES_ACT_VSA_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_ACT_VID_VSA_LINES_ACT_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VSA_LINES_ACT_VID_VSA_LINES_ACT_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VBP_LINES_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_ACT_VID_VBP_LINES_ACT_VBP_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_ACT_VID_VBP_LINES_ACT_VBP_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_ACT_VID_VBP_LINES_ACT_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VBP_LINES_ACT_VID_VBP_LINES_ACT_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VFP_LINES_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_ACT_VID_VFP_LINES_ACT_VFP_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_ACT_VID_VFP_LINES_ACT_VFP_LINES_Msk 0x3FFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_ACT_VID_VFP_LINES_ACT_RESERVED_31_10_Pos 10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VFP_LINES_ACT_VID_VFP_LINES_ACT_RESERVED_31_10_Msk 0xFFFFFC00UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_VACTIVE_LINES_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_ACT_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_ACT_VID_VACTIVE_LINES_ACT_V_ACTIVE_LINES_Msk 0x3FFFUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_ACT_VID_VACTIVE_LINES_ACT_RESERVED_31_14_Pos 14UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_VACTIVE_LINES_ACT_VID_VACTIVE_LINES_ACT_RESERVED_31_14_Msk 0xFFFFC000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.VID_PKT_STATUS */
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_CMD_W_EMPTY_Msk 0x1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_CMD_W_FULL_Pos 1UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_CMD_W_FULL_Msk 0x2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_PLD_W_EMPTY_Msk 0x4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_PLD_W_FULL_Pos 3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_PLD_W_FULL_Msk 0x8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_4_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_4_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_5_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_5_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_6_Msk 0x40UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_7_Pos 7UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_7_Msk 0x80UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_15_8_Pos 8UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_15_8_Msk 0xFF00UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_BUFF_PLD_EMPTY_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_DPI_BUFF_PLD_FULL_Msk 0x20000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_19_18_Pos 18UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_19_18_Msk 0xC0000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_20_Pos 20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_20_Msk 0x100000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_21_Pos 21UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_21_Msk 0x200000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_22_Pos 22UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_22_Msk 0x400000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_23_Pos 23UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_23_Msk 0x800000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_31_24_Pos 24UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_VID_PKT_STATUS_VID_PKT_STATUS_RESERVED_31_24_Msk 0xFF000000UL
/* GFXSS_MIPIDSI_DWCMIPIDSI.SDF_3D_ACT */
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_MODE_3D_Pos 0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_MODE_3D_Msk 0x3UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_FORMAT_3D_Pos 2UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_FORMAT_3D_Msk 0xCUL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_SECOND_VSYNC_Pos 4UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_SECOND_VSYNC_Msk 0x10UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RIGHT_FIRST_Pos 5UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RIGHT_FIRST_Msk 0x20UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RESERVED_15_6_Pos 6UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RESERVED_15_6_Msk 0xFFC0UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_SEND_3D_CFG_Pos 16UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_SEND_3D_CFG_Msk 0x10000UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RESERVED_31_17_Pos 17UL
#define GFXSS_MIPIDSI_DWCMIPIDSI_SDF_3D_ACT_SDF_3D_ACT_RESERVED_31_17_Msk 0xFFFE0000UL


#endif /* _CYIP_GFXSS_H_ */


/* [] END OF FILE */
