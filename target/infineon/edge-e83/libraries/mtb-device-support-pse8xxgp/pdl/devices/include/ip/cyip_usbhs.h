/***************************************************************************//**
* USBHS IP definitions
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

#ifndef _CYIP_USBHS_H_
#define _CYIP_USBHS_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    USBHS
*******************************************************************************/

#define USBHS_DWC_OTG_INTREG_SECTION_SIZE       0x00000F00UL
#define USBHS_SS_SECTION_SIZE                   0x00000100UL
#define USBHS_SECTION_SIZE                      0x00080000UL

/**
  * \brief Internal register map (USBHS_DWC_OTG_INTREG)
  */
typedef struct {
  __IOM uint32_t GOTGCTL;                       /*!< 0x00000000 The OTG Control and Status register controls the behavior and
                                                                reflects the status of the OTG function of the controller. */
  __IOM uint32_t GOTGINT;                       /*!< 0x00000004 The application reads this register whenever there is an OTG
                                                                interrupt and clears the bits in this register to clear the OTG
                                                                interrupt. */
  __IOM uint32_t GAHBCFG;                       /*!< 0x00000008 This register can be used to configure the core after power-on
                                                                or a change in mode. This register mainly contains AHB
                                                                system-related configuration parameters. Do not change this
                                                                register after the initial programming. The application must
                                                                program this register before starting any transactions on either
                                                                the AHB or the USB. */
  __IOM uint32_t GUSBCFG;                       /*!< 0x0000000C This register can be used to configure the core after power-on
                                                                or when changing to Host mode or Device mode. It contains USB
                                                                and USB-PHY related configuration parameters. The application
                                                                must program this register before starting any transactions on
                                                                either the AHB or the USB. If you are using the HSIC interface,
                                                                HSIC PHY must be in reset while programming this register. Do
                                                                not make changes to this register after the initial programming. */
  __IOM uint32_t GRSTCTL;                       /*!< 0x00000010 The application uses this register to reset various hardware
                                                                features inside the controller. */
  __IOM uint32_t GINTSTS;                       /*!< 0x00000014 This register interrupts the application for system-level
                                                                events in the current mode (Device mode or Host mode). Some of
                                                                the bits in this register are valid only in Host mode, while
                                                                others are valid in Device mode only. This register also
                                                                indicates the current mode. To clear the interrupt status bits
                                                                of type R_SS_WC, the application must write 1'b1 to the bit. The
                                                                FIFO status interrupts are read only; once software reads from
                                                                or writes to the FIFO while servicing these interrupts, FIFO
                                                                interrupt conditions are cleared automatically. The application
                                                                must clear the GINTSTS register at initialization before
                                                                unmasking the interrupt bit to avoid any interrupts generated
                                                                prior to initialization. Note: Read the reset value of
                                                                GINTSTS.CurMod only after the following conditions: - If
                                                                IDDIG_FILTER is disabled, read only after PHY clock is stable. -
                                                                If IDDIG_FILTER is enabled, read only after the filter timer
                                                                expires. */
  __IOM uint32_t GINTMSK;                       /*!< 0x00000018 This register works with the Interrupt Register (GINTSTS) to
                                                                interrupt the application. When an interrupt bit is masked, the
                                                                interrupt associated with that bit is not generated. However,
                                                                the GINTSTS register bit corresponding to that interrupt is
                                                                still set. Note: The fields of this register change depending on
                                                                host or device mode. */
   __IM uint32_t GRXSTSR;                       /*!< 0x0000001C A read to the Receive Status Debug Read register returns the
                                                                contents of the top of the Receive FIFO. The receive status
                                                                contents must be interpreted differently in Host and Device
                                                                modes. The core ignores the receive status read when the receive
                                                                FIFO is empty and returns a value of 32'h0000_0000. Note: - Use
                                                                of these fields vary based on whether the core is functioning as
                                                                a host or a device. - Do not read this register's reset value
                                                                before configuring the core because the read value is 'X' in the
                                                                simulation. */
   __IM uint32_t GRXSTSP;                       /*!< 0x00000020 A read to the Receive Status Read and Pop register returns the
                                                                contents of the top of the Receive FIFO and additionally pops
                                                                the top data entry out of the RxFIFO. The receive status
                                                                contents must be interpreted differently in Host and Device
                                                                modes. The core ignores the receive status pop/read when the
                                                                receive FIFO is empty and returns a value of 32'h0000_0000. The
                                                                application must only pop the Receive Status FIFO when the
                                                                Receive FIFO Non-Empty bit of the Core Interrupt register
                                                                (GINTSTS.RxFLvl) is asserted. Note: - Use of these fields vary
                                                                based on whether the core is functioning as a host or a device.
                                                                - Do not read this register's reset value before configuring the
                                                                core because the read value is 'X' in the simulation. */
  __IOM uint32_t GRXFSIZ;                       /*!< 0x00000024 The application can program the RAM size that must be allocated
                                                                to the RxFIFO. */
  __IOM uint32_t GNPTXFSIZ;                     /*!< 0x00000028 The application can program the RAM size and the memory start
                                                                address for the Non-periodic TxFIFO Note: The fields of this
                                                                register change depending on host or device mode. */
   __IM uint32_t GNPTXSTS;                      /*!< 0x0000002C In Device mode, this register is valid only in Shared FIFO
                                                                operation. This read-only register contains the free space
                                                                information for the Non-periodic TxFIFO and the Non-periodic
                                                                Transmit Request Queue. */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t GGPIO;                         /*!< 0x00000038 The application can use this register for general purpose
                                                                input/output ports or for debugging. */
  __IOM uint32_t GUID;                          /*!< 0x0000003C This is a read/write register containing the User ID. It is
                                                                implemented only if Remove Optional Features? was deselected
                                                                during coreConsultant configuration (parameter
                                                                OTG_RM_OPT_FEATURES = 0). The power-on value for this register
                                                                is specified as the Power-on Value of User ID Register User
                                                                Identification Register during coreConsultant configuration
                                                                (parameter OTG_USERID). This register can be used in the
                                                                following ways: - To store the version or revision of your
                                                                system - To store hardware configurations that are outside the
                                                                DWC_otg core - As a scratch register */
   __IM uint32_t GSNPSID;                       /*!< 0x00000040 This read-only register contains the release number of the core
                                                                being used. */
   __IM uint32_t GHWCFG1;                       /*!< 0x00000044 This register contains the logical endpoint direction(s)
                                                                selected using coreConsultant. */
   __IM uint32_t GHWCFG2;                       /*!< 0x00000048 This register contains configuration options selected using
                                                                coreConsultant. */
   __IM uint32_t GHWCFG3;                       /*!< 0x0000004C This register contains configuration options selected using
                                                                coreConsultant. */
   __IM uint32_t GHWCFG4;                       /*!< 0x00000050 This register contains configuration options selected using
                                                                coreConsultant. Note: Bit [31] is available only when
                                                                Scatter/Gather DMA mode is enabled. When Scatter/Gather DMA mode
                                                                is disabled, this field is reserved. */
  __IOM uint32_t GLPMCFG;                       /*!< 0x00000054 Register to control the LPM functionality of the controller. */
   __IM uint32_t RESERVED1;
  __IOM uint32_t GDFIFOCFG;                     /*!< 0x0000005C Register to configure the DFIFOs for the controller. */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t GINTMSK2;                      /*!< 0x00000068 This register works with the Interrupt Register (GINTSTS2) to
                                                                interrupt the application. When an interrupt bit is masked, the
                                                                interrupt associated with that bit is not generated. However,
                                                                the GINTSTS2 register bit corresponding to that interrupt is
                                                                still set. Note: The fields of this register change depending on
                                                                host or device mode. */
  __IOM uint32_t GINTSTS2;                      /*!< 0x0000006C This register interrupts the application for system-level
                                                                events in the current mode (Device mode or Host mode). Some of
                                                                the bits in this register are valid only in Host mode, while
                                                                others are valid in Device mode only. This register also
                                                                indicates the current mode. To clear the interrupt status bits
                                                                of type R_SS_WC, the application must write 1'b1 to the bit. The
                                                                application must clear the GINTSTS2 register at initialization
                                                                before unmasking the interrupt bit to avoid any interrupts
                                                                generated prior to initialization. */
   __IM uint32_t RESERVED3[36];
  __IOM uint32_t HPTXFSIZ;                      /*!< 0x00000100 This register holds the size and the memory start address of
                                                                the Periodic TxFIFO. Note: Read the reset value of this register
                                                                only after the following conditions: - If IDDIG_FILTER is
                                                                disabled, read only after PHY clock is stable. - If IDDIG_FILTER
                                                                is enabled, read only after the filter timer expires. */
  __IOM uint32_t DIEPTXF1;                      /*!< 0x00000104 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF2;                      /*!< 0x00000108 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF3;                      /*!< 0x0000010C This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF4;                      /*!< 0x00000110 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF5;                      /*!< 0x00000114 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF6;                      /*!< 0x00000118 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF7;                      /*!< 0x0000011C This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
  __IOM uint32_t DIEPTXF8;                      /*!< 0x00000120 This register is valid only in dedicated FIFO mode
                                                                (OTG_EN_DED_TX_FIFO=1). It holds the size and memory start
                                                                address of IN endpoint TxFIFOs implemented in Device mode. Each
                                                                FIFO holds the data for one IN endpoint. This register is
                                                                repeated for instantiated IN endpoint FIFOs 1 to 15. For IN
                                                                endpoint FIFO 0, use GNPTXFSIZ register for programming the size
                                                                and memory start address. */
   __IM uint32_t RESERVED4[183];
  __IOM uint32_t HCFG;                          /*!< 0x00000400 This register is used to configure the controller in Host mode. */
  __IOM uint32_t HFIR;                          /*!< 0x00000404 This register is used to control the interval between two
                                                                consecutive SOFs. */
   __IM uint32_t HFNUM;                         /*!< 0x00000408 This register indicates the current frame number. It also
                                                                indicates the time remaining (in terms of the number of PHY
                                                                clocks) in the current (micro)frame. Note: Read the reset value
                                                                of this register only after the following conditions: - If
                                                                IDDIG_FILTER is disabled, read only when the PHY clock is
                                                                stable. - If IDDIG_FILTER is enabled, read only after the filter
                                                                timer expires. */
   __IM uint32_t RESERVED5;
   __IM uint32_t HPTXSTS;                       /*!< 0x00000410 This register contains information about the Periodic Transmit
                                                                Queue in the Host controller. */
   __IM uint32_t HAINT;                         /*!< 0x00000414 When a significant event occurs on a channel, the Host All
                                                                Channels Interrupt register interrupts the application using the
                                                                Host Channels Interrupt bit of the Core Interrupt register
                                                                (GINTSTS.HChInt). This is shown in the 'Interrupt Hierarchy'
                                                                figure in the databook. There is one interrupt bit per channel,
                                                                up to a maximum of 16 bits. Bits in this register are set and
                                                                cleared when the application sets and clears bits in the
                                                                corresponding Host Channel-n Interrupt register. */
  __IOM uint32_t HAINTMSK;                      /*!< 0x00000418 The Host All Channel Interrupt Mask register works with the
                                                                Host All Channel Interrupt register to interrupt the application
                                                                when an event occurs on a channel. There is one interrupt mask
                                                                bit per channel, up to a maximum of 16 bits. */
  __IOM uint32_t HFLBADDR;                      /*!< 0x0000041C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented as flops. This register holds the starting
                                                                address of the Frame list information. */
   __IM uint32_t RESERVED6[8];
  __IOM uint32_t HPRT;                          /*!< 0x00000440 This register is available only in Host mode. Currently, the
                                                                OTG Host supports only one port. A single register holds USB
                                                                port-related information such as USB reset, enable, suspend,
                                                                resume, connect status, and test mode for each port. It is shown
                                                                in the 'Interrupt Hierarchy' figure in the databook. The R_SS_WC
                                                                bits in this register can trigger an interrupt to the
                                                                application through the Host Port Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.PrtInt). On a Port Interrupt, the
                                                                application must read this register and clear the bit that
                                                                caused the interrupt. For the R_SS_WC bits, the application must
                                                                write a 1 to the bit to clear the interrupt. */
   __IM uint32_t RESERVED7[47];
  __IOM uint32_t HCCHAR0;                       /*!< 0x00000500 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT0;                       /*!< 0x00000504 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT0;                        /*!< 0x00000508 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK0;                     /*!< 0x0000050C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ0;                       /*!< 0x00000510 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA0;                        /*!< 0x00000514 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED8;
   __IM uint32_t HCDMAB0;                       /*!< 0x0000051C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR1;                       /*!< 0x00000520 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT1;                       /*!< 0x00000524 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT1;                        /*!< 0x00000528 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK1;                     /*!< 0x0000052C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ1;                       /*!< 0x00000530 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA1;                        /*!< 0x00000534 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED9;
   __IM uint32_t HCDMAB1;                       /*!< 0x0000053C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR2;                       /*!< 0x00000540 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT2;                       /*!< 0x00000544 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT2;                        /*!< 0x00000548 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK2;                     /*!< 0x0000054C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ2;                       /*!< 0x00000550 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA2;                        /*!< 0x00000554 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED10;
   __IM uint32_t HCDMAB2;                       /*!< 0x0000055C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR3;                       /*!< 0x00000560 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT3;                       /*!< 0x00000564 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT3;                        /*!< 0x00000568 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK3;                     /*!< 0x0000056C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ3;                       /*!< 0x00000570 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA3;                        /*!< 0x00000574 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED11;
   __IM uint32_t HCDMAB3;                       /*!< 0x0000057C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR4;                       /*!< 0x00000580 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT4;                       /*!< 0x00000584 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT4;                        /*!< 0x00000588 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK4;                     /*!< 0x0000058C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ4;                       /*!< 0x00000590 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA4;                        /*!< 0x00000594 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED12;
   __IM uint32_t HCDMAB4;                       /*!< 0x0000059C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR5;                       /*!< 0x000005A0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT5;                       /*!< 0x000005A4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT5;                        /*!< 0x000005A8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK5;                     /*!< 0x000005AC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ5;                       /*!< 0x000005B0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA5;                        /*!< 0x000005B4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED13;
   __IM uint32_t HCDMAB5;                       /*!< 0x000005BC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR6;                       /*!< 0x000005C0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT6;                       /*!< 0x000005C4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT6;                        /*!< 0x000005C8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK6;                     /*!< 0x000005CC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ6;                       /*!< 0x000005D0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA6;                        /*!< 0x000005D4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED14;
   __IM uint32_t HCDMAB6;                       /*!< 0x000005DC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR7;                       /*!< 0x000005E0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT7;                       /*!< 0x000005E4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT7;                        /*!< 0x000005E8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK7;                     /*!< 0x000005EC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ7;                       /*!< 0x000005F0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA7;                        /*!< 0x000005F4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED15;
   __IM uint32_t HCDMAB7;                       /*!< 0x000005FC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR8;                       /*!< 0x00000600 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT8;                       /*!< 0x00000604 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT8;                        /*!< 0x00000608 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK8;                     /*!< 0x0000060C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ8;                       /*!< 0x00000610 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA8;                        /*!< 0x00000614 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED16;
   __IM uint32_t HCDMAB8;                       /*!< 0x0000061C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR9;                       /*!< 0x00000620 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT9;                       /*!< 0x00000624 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT9;                        /*!< 0x00000628 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK9;                     /*!< 0x0000062C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ9;                       /*!< 0x00000630 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA9;                        /*!< 0x00000634 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED17;
   __IM uint32_t HCDMAB9;                       /*!< 0x0000063C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR10;                      /*!< 0x00000640 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT10;                      /*!< 0x00000644 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT10;                       /*!< 0x00000648 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK10;                    /*!< 0x0000064C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ10;                      /*!< 0x00000650 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA10;                       /*!< 0x00000654 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED18;
   __IM uint32_t HCDMAB10;                      /*!< 0x0000065C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR11;                      /*!< 0x00000660 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT11;                      /*!< 0x00000664 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT11;                       /*!< 0x00000668 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK11;                    /*!< 0x0000066C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ11;                      /*!< 0x00000670 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA11;                       /*!< 0x00000674 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED19;
   __IM uint32_t HCDMAB11;                      /*!< 0x0000067C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR12;                      /*!< 0x00000680 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT12;                      /*!< 0x00000684 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT12;                       /*!< 0x00000688 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK12;                    /*!< 0x0000068C This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ12;                      /*!< 0x00000690 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA12;                       /*!< 0x00000694 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED20;
   __IM uint32_t HCDMAB12;                      /*!< 0x0000069C This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR13;                      /*!< 0x000006A0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT13;                      /*!< 0x000006A4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT13;                       /*!< 0x000006A8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK13;                    /*!< 0x000006AC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ13;                      /*!< 0x000006B0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA13;                       /*!< 0x000006B4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED21;
   __IM uint32_t HCDMAB13;                      /*!< 0x000006BC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR14;                      /*!< 0x000006C0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT14;                      /*!< 0x000006C4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT14;                       /*!< 0x000006C8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK14;                    /*!< 0x000006CC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ14;                      /*!< 0x000006D0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA14;                       /*!< 0x000006D4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED22;
   __IM uint32_t HCDMAB14;                      /*!< 0x000006DC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
  __IOM uint32_t HCCHAR15;                      /*!< 0x000006E0 This register contains the characteristics of the Host Channel. */
  __IOM uint32_t HCSPLT15;                      /*!< 0x000006E4 This register contains the Split characteristics of the Host
                                                                Channel. */
  __IOM uint32_t HCINT15;                       /*!< 0x000006E8 This register indicates the status of a channel with respect to
                                                                USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the Host Channels Interrupt bit of the Core
                                                                Interrupt register (GINTSTS.HChInt) is set. Before the
                                                                application can read this register, it must first read the Host
                                                                All Channels Interrupt (HAINT) register to get the exact channel
                                                                number for the Host Channel-n Interrupt register. The
                                                                application must clear the appropriate bit in this register to
                                                                clear the corresponding bits in the HAINT and GINTSTS registers. */
  __IOM uint32_t HCINTMSK15;                    /*!< 0x000006EC This register reflects the mask for each channel status
                                                                described in the previous section. */
  __IOM uint32_t HCTSIZ15;                      /*!< 0x000006F0 This register reflects the transfer size for the Host Channel. */
  __IOM uint32_t HCDMA15;                       /*!< 0x000006F4 This register is used by the OTG host in the internal DMA mode
                                                                to maintain the current buffer pointer for IN/OUT transactions.
                                                                The starting DMA address must be DWORD-aligned. */
   __IM uint32_t RESERVED23;
   __IM uint32_t HCDMAB15;                      /*!< 0x000006FC This register is present only in case of Scatter/Gather DMA. It
                                                                is implemented in RAM instead of flop-based implementation. This
                                                                register holds the current buffer address. */
   __IM uint32_t RESERVED24[64];
  __IOM uint32_t DCFG;                          /*!< 0x00000800 This register configures the core in Device mode after power-on
                                                                or after certain control commands or enumeration. Do not make
                                                                changes to this register after initial programming. */
  __IOM uint32_t DCTL;                          /*!< 0x00000804 This register is used to control the characteristics of the
                                                                Device controller. */
   __IM uint32_t DSTS;                          /*!< 0x00000808 This register indicates the status of the core with respect to
                                                                USB-related events. It must be read on interrupts from Device
                                                                All Interrupts (DAINT) register. */
   __IM uint32_t RESERVED25;
  __IOM uint32_t DIEPMSK;                       /*!< 0x00000810 This register works with each of the Device IN Endpoint
                                                                Interrupt (DIEPINTn) registers for all endpoints to generate an
                                                                interrupt per IN endpoint. The IN endpoint interrupt for a
                                                                specific status in the DIEPINTn register can be masked by
                                                                writing to the corresponding bit in this register. Status bits
                                                                are masked by default. */
  __IOM uint32_t DOEPMSK;                       /*!< 0x00000814 This register works with each of the Device OUT Endpoint
                                                                Interrupt (DOEPINTn) registers for all endpoints to generate an
                                                                interrupt per OUT endpoint. The OUT endpoint interrupt for a
                                                                specific status in the DOEPINTn register can be masked by
                                                                writing into the corresponding bit in this register. Status bits
                                                                are masked by default. */
   __IM uint32_t DAINT;                         /*!< 0x00000818 When a significant event occurs on an endpoint, a Device All
                                                                Endpoints Interrupt register interrupts the application using
                                                                the Device OUT Endpoints Interrupt bit or Device IN Endpoints
                                                                Interrupt bit of the Core Interrupt register (GINTSTS.OEPInt or
                                                                GINTSTS.IEPInt, respectively). This is shown in Figure 5-2.
                                                                There is one interrupt bit per endpoint, up to a maximum of 16
                                                                bits for OUT endpoints and 16 bits for IN endpoints. For a
                                                                bidirectional endpoint, the corresponding IN and OUT interrupt
                                                                bits are used. Bits in this register are set and cleared when
                                                                the application sets and clears bits in the corresponding Device
                                                                Endpoint-n Interrupt register (DIEPINTn/DOEPINTn). */
  __IOM uint32_t DAINTMSK;                      /*!< 0x0000081C The Device Endpoint Interrupt Mask register works with the
                                                                Device Endpoint Interrupt register to interrupt the application
                                                                when an event occurs on a device endpoint. However, the Device
                                                                All Endpoints Interrupt (DAINT) register bit corresponding to
                                                                that interrupt is still set. */
   __IM uint32_t RESERVED26[2];
  __IOM uint32_t DVBUSDIS;                      /*!< 0x00000828 This register specifies the VBUS discharge time after VBUS
                                                                pulsing during SRP. */
  __IOM uint32_t DVBUSPULSE;                    /*!< 0x0000082C This register contains the VBUS pulsing time during SRP. */
  __IOM uint32_t DTHRCTL;                       /*!< 0x00000830 This register contains the Receive and Transmit Threshold
                                                                characteristics of the Device controller. */
  __IOM uint32_t DIEPEMPMSK;                    /*!< 0x00000834 This register is valid only in Dedicated FIFO operation
                                                                (OTG_EN_DED_TX_FIFO = 1). This register is used to control the
                                                                IN endpoint FIFO empty interrupt generation (DIEPINTn.TxfEmp). */
   __IM uint32_t RESERVED27[50];
  __IOM uint32_t DIEPCTL0;                      /*!< 0x00000900 This register is used to control the characteristics of the IN
                                                                Endpoint 0 of the Device controller. */
   __IM uint32_t RESERVED28;
  __IOM uint32_t DIEPINT0;                      /*!< 0x00000908 This register indicates the status of an endpoint with respect
                                                                to USB- and AHB-related events. It is shown in the 'Interrupt
                                                                Hierarchy' figure in the databook. The application must read
                                                                this register when the OUT Endpoints Interrupt bit or IN
                                                                Endpoints Interrupt bit of the Core Interrupt register
                                                                (GINTSTS.OEPInt or GINTSTS.IEPInt, respectively) is set. Before
                                                                the application can read this register, it must first read the
                                                                Device All Endpoints Interrupt (DAINT) register to get the exact
                                                                endpoint number for the Device Endpoint-n Interrupt register.
                                                                The application must clear the appropriate bit in this register
                                                                to clear the corresponding bits in the DAINT and GINTSTS
                                                                registers */
   __IM uint32_t RESERVED29;
  __IOM uint32_t DIEPTSIZ0;                     /*!< 0x00000910 The application must modify this register before enabling
                                                                endpoint 0. Once endpoint 0 is enabled using Endpoint Enable bit
                                                                of the Device Control Endpoint 0 Control registers
                                                                (DIEPCTL0.EPEna/DOEPCTL0.EPEna), the core modifies this
                                                                register. The application can only read this register once the
                                                                core has cleared the Endpoint Enable bit. Nonzero endpoints use
                                                                the registers for endpoints 115. When Scatter/Gather DMA mode is
                                                                enabled, this register must not be programmed by the
                                                                application. If the application reads this register when
                                                                Scatter/Gather DMA mode is enabled, the core returns all zeros. */
  __IOM uint32_t DIEPDMA0;                      /*!< 0x00000914 This register contains the DMA Address for the IN Endpoint 0 of
                                                                the Device controller. */
   __IM uint32_t DTXFSTS0;                      /*!< 0x00000918 This register contains information about the IN Endpoint
                                                                Transmit FIFO of the Device controller. */
   __IM uint32_t DIEPDMAB0;                     /*!< 0x0000091C This register contains the DMA Buffer Address for the IN
                                                                Endpoint 0 of the Device controller. */
  __IOM uint32_t DIEPCTL1;                      /*!< 0x00000920 This register is used to control the characteristics of
                                                                Endpoint 1. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED30;
  __IOM uint32_t DIEPINT1;                      /*!< 0x00000928 This register contains the interrupts for the IN Endpoint 1 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED31;
  __IOM uint32_t DIEPTSIZ1;                     /*!< 0x00000930 This register reflects the Transfer Size of the IN Endpoint 1
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA1;                      /*!< 0x00000934 This register contains the DMA Address for the IN Endpoint 1 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS1;                      /*!< 0x00000938 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 1 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB1;                     /*!< 0x0000093C This register contains the DMA Buffer Address of the IN
                                                                Endpoint 1 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL2;                      /*!< 0x00000940 This register is used to control the characteristics of
                                                                Endpoint 2. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED32;
  __IOM uint32_t DIEPINT2;                      /*!< 0x00000948 This register contains the interrupts for the IN Endpoint 2 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED33;
  __IOM uint32_t DIEPTSIZ2;                     /*!< 0x00000950 This register reflects the Transfer Size of the IN Endpoint 2
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA2;                      /*!< 0x00000954 This register contains the DMA Address for the IN Endpoint 2 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS2;                      /*!< 0x00000958 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 2 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB2;                     /*!< 0x0000095C This register contains the DMA Buffer Address of the IN
                                                                Endpoint 2 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL3;                      /*!< 0x00000960 This register is used to control the characteristics of
                                                                Endpoint 3. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED34;
  __IOM uint32_t DIEPINT3;                      /*!< 0x00000968 This register contains the interrupts for the IN Endpoint 3 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED35;
  __IOM uint32_t DIEPTSIZ3;                     /*!< 0x00000970 This register reflects the Transfer Size of the IN Endpoint 3
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA3;                      /*!< 0x00000974 This register contains the DMA Address for the IN Endpoint 3 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS3;                      /*!< 0x00000978 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 3 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB3;                     /*!< 0x0000097C This register contains the DMA Buffer Address of the IN
                                                                Endpoint 3 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL4;                      /*!< 0x00000980 This register is used to control the characteristics of
                                                                Endpoint 4. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED36;
  __IOM uint32_t DIEPINT4;                      /*!< 0x00000988 This register contains the interrupts for the IN Endpoint 4 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED37;
  __IOM uint32_t DIEPTSIZ4;                     /*!< 0x00000990 This register reflects the Transfer Size of the IN Endpoint 4
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA4;                      /*!< 0x00000994 This register contains the DMA Address for the IN Endpoint 4 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS4;                      /*!< 0x00000998 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 4 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB4;                     /*!< 0x0000099C This register contains the DMA Buffer Address of the IN
                                                                Endpoint 4 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL5;                      /*!< 0x000009A0 This register is used to control the characteristics of
                                                                Endpoint 5. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED38;
  __IOM uint32_t DIEPINT5;                      /*!< 0x000009A8 This register contains the interrupts for the IN Endpoint 5 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED39;
  __IOM uint32_t DIEPTSIZ5;                     /*!< 0x000009B0 This register reflects the Transfer Size of the IN Endpoint 5
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA5;                      /*!< 0x000009B4 This register contains the DMA Address for the IN Endpoint 5 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS5;                      /*!< 0x000009B8 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 5 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB5;                     /*!< 0x000009BC This register contains the DMA Buffer Address of the IN
                                                                Endpoint 5 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL6;                      /*!< 0x000009C0 This register is used to control the characteristics of
                                                                Endpoint 6. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED40;
  __IOM uint32_t DIEPINT6;                      /*!< 0x000009C8 This register contains the interrupts for the IN Endpoint 6 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED41;
  __IOM uint32_t DIEPTSIZ6;                     /*!< 0x000009D0 This register reflects the Transfer Size of the IN Endpoint 6
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA6;                      /*!< 0x000009D4 This register contains the DMA Address for the IN Endpoint 6 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS6;                      /*!< 0x000009D8 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 6 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB6;                     /*!< 0x000009DC This register contains the DMA Buffer Address of the IN
                                                                Endpoint 6 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL7;                      /*!< 0x000009E0 This register is used to control the characteristics of
                                                                Endpoint 7. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED42;
  __IOM uint32_t DIEPINT7;                      /*!< 0x000009E8 This register contains the interrupts for the IN Endpoint 7 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED43;
  __IOM uint32_t DIEPTSIZ7;                     /*!< 0x000009F0 This register reflects the Transfer Size of the IN Endpoint 7
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA7;                      /*!< 0x000009F4 This register contains the DMA Address for the IN Endpoint 7 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS7;                      /*!< 0x000009F8 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 7 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB7;                     /*!< 0x000009FC This register contains the DMA Buffer Address of the IN
                                                                Endpoint 7 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
  __IOM uint32_t DIEPCTL8;                      /*!< 0x00000A00 This register is used to control the characteristics of
                                                                Endpoint 8. Note: This register exists for an endpoint i if the
                                                                OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
   __IM uint32_t RESERVED44;
  __IOM uint32_t DIEPINT8;                      /*!< 0x00000A08 This register contains the interrupts for the IN Endpoint 8 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t RESERVED45;
  __IOM uint32_t DIEPTSIZ8;                     /*!< 0x00000A10 This register reflects the Transfer Size of the IN Endpoint 8
                                                                of the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
  __IOM uint32_t DIEPDMA8;                      /*!< 0x00000A14 This register contains the DMA Address for the IN Endpoint 8 of
                                                                the Device controller. Note: This register exists for an
                                                                endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that
                                                                endpoint. */
   __IM uint32_t DTXFSTS8;                      /*!< 0x00000A18 This register reflects the status of the IN Endpoint Transmit
                                                                FIFO Status Register 8 of the Device controller. Note: This
                                                                register exists for an endpoint i if the OTG_EP_DIR_i parameter
                                                                is 0 or 1 for that endpoint. */
   __IM uint32_t DIEPDMAB8;                     /*!< 0x00000A1C This register contains the DMA Buffer Address of the IN
                                                                Endpoint 8 of the Device controller. Note: This register exists
                                                                for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for
                                                                that endpoint. */
   __IM uint32_t RESERVED46[56];
  __IOM uint32_t DOEPCTL0;                      /*!< 0x00000B00 This register is used to control the characteristics of the OUT
                                                                Endpoint 0 of the Device controller. */
   __IM uint32_t RESERVED47;
  __IOM uint32_t DOEPINT0;                      /*!< 0x00000B08 This register contains the interrupts for the OUT Endpoint 0 of
                                                                the Device controller. */
   __IM uint32_t RESERVED48;
  __IOM uint32_t DOEPTSIZ0;                     /*!< 0x00000B10 This register contains the Transfer Size for the OUT Endpoint 0
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA0;                      /*!< 0x00000B14 This register contains the DMA Address for the OUT Endpoint 0
                                                                of the Device controller. */
   __IM uint32_t RESERVED49;
   __IM uint32_t DOEPDMAB0;                     /*!< 0x00000B1C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 0 of the Device controller. */
  __IOM uint32_t DOEPCTL1;                      /*!< 0x00000B20 This register is used to control the characteristics of OUT
                                                                Endpoint 1 of the Device controller. */
   __IM uint32_t RESERVED50;
  __IOM uint32_t DOEPINT1;                      /*!< 0x00000B28 This register contains the interrupts for the OUT Endpoint 1 of
                                                                the Device controller. */
   __IM uint32_t RESERVED51;
  __IOM uint32_t DOEPTSIZ1;                     /*!< 0x00000B30 This register contains the Transfer Size for the OUT Endpoint 1
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA1;                      /*!< 0x00000B34 This register contains the DMA Address for the OUT Endpoint 1
                                                                of the Device controller. */
   __IM uint32_t RESERVED52;
   __IM uint32_t DOEPDMAB1;                     /*!< 0x00000B3C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 1 of the Device controller. */
  __IOM uint32_t DOEPCTL2;                      /*!< 0x00000B40 This register is used to control the characteristics of OUT
                                                                Endpoint 2 of the Device controller. */
   __IM uint32_t RESERVED53;
  __IOM uint32_t DOEPINT2;                      /*!< 0x00000B48 This register contains the interrupts for the OUT Endpoint 2 of
                                                                the Device controller. */
   __IM uint32_t RESERVED54;
  __IOM uint32_t DOEPTSIZ2;                     /*!< 0x00000B50 This register contains the Transfer Size for the OUT Endpoint 2
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA2;                      /*!< 0x00000B54 This register contains the DMA Address for the OUT Endpoint 2
                                                                of the Device controller. */
   __IM uint32_t RESERVED55;
   __IM uint32_t DOEPDMAB2;                     /*!< 0x00000B5C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 2 of the Device controller. */
  __IOM uint32_t DOEPCTL3;                      /*!< 0x00000B60 This register is used to control the characteristics of OUT
                                                                Endpoint 3 of the Device controller. */
   __IM uint32_t RESERVED56;
  __IOM uint32_t DOEPINT3;                      /*!< 0x00000B68 This register contains the interrupts for the OUT Endpoint 3 of
                                                                the Device controller. */
   __IM uint32_t RESERVED57;
  __IOM uint32_t DOEPTSIZ3;                     /*!< 0x00000B70 This register contains the Transfer Size for the OUT Endpoint 3
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA3;                      /*!< 0x00000B74 This register contains the DMA Address for the OUT Endpoint 3
                                                                of the Device controller. */
   __IM uint32_t RESERVED58;
   __IM uint32_t DOEPDMAB3;                     /*!< 0x00000B7C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 3 of the Device controller. */
  __IOM uint32_t DOEPCTL4;                      /*!< 0x00000B80 This register is used to control the characteristics of OUT
                                                                Endpoint 4 of the Device controller. */
   __IM uint32_t RESERVED59;
  __IOM uint32_t DOEPINT4;                      /*!< 0x00000B88 This register contains the interrupts for the OUT Endpoint 4 of
                                                                the Device controller. */
   __IM uint32_t RESERVED60;
  __IOM uint32_t DOEPTSIZ4;                     /*!< 0x00000B90 This register contains the Transfer Size for the OUT Endpoint 4
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA4;                      /*!< 0x00000B94 This register contains the DMA Address for the OUT Endpoint 4
                                                                of the Device controller. */
   __IM uint32_t RESERVED61;
   __IM uint32_t DOEPDMAB4;                     /*!< 0x00000B9C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 4 of the Device controller. */
  __IOM uint32_t DOEPCTL5;                      /*!< 0x00000BA0 This register is used to control the characteristics of OUT
                                                                Endpoint 5 of the Device controller. */
   __IM uint32_t RESERVED62;
  __IOM uint32_t DOEPINT5;                      /*!< 0x00000BA8 This register contains the interrupts for the OUT Endpoint 5 of
                                                                the Device controller. */
   __IM uint32_t RESERVED63;
  __IOM uint32_t DOEPTSIZ5;                     /*!< 0x00000BB0 This register contains the Transfer Size for the OUT Endpoint 5
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA5;                      /*!< 0x00000BB4 This register contains the DMA Address for the OUT Endpoint 5
                                                                of the Device controller. */
   __IM uint32_t RESERVED64;
   __IM uint32_t DOEPDMAB5;                     /*!< 0x00000BBC This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 5 of the Device controller. */
  __IOM uint32_t DOEPCTL6;                      /*!< 0x00000BC0 This register is used to control the characteristics of OUT
                                                                Endpoint 6 of the Device controller. */
   __IM uint32_t RESERVED65;
  __IOM uint32_t DOEPINT6;                      /*!< 0x00000BC8 This register contains the interrupts for the OUT Endpoint 6 of
                                                                the Device controller. */
   __IM uint32_t RESERVED66;
  __IOM uint32_t DOEPTSIZ6;                     /*!< 0x00000BD0 This register contains the Transfer Size for the OUT Endpoint 6
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA6;                      /*!< 0x00000BD4 This register contains the DMA Address for the OUT Endpoint 6
                                                                of the Device controller. */
   __IM uint32_t RESERVED67;
   __IM uint32_t DOEPDMAB6;                     /*!< 0x00000BDC This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 6 of the Device controller. */
  __IOM uint32_t DOEPCTL7;                      /*!< 0x00000BE0 This register is used to control the characteristics of OUT
                                                                Endpoint 7 of the Device controller. */
   __IM uint32_t RESERVED68;
  __IOM uint32_t DOEPINT7;                      /*!< 0x00000BE8 This register contains the interrupts for the OUT Endpoint 7 of
                                                                the Device controller. */
   __IM uint32_t RESERVED69;
  __IOM uint32_t DOEPTSIZ7;                     /*!< 0x00000BF0 This register contains the Transfer Size for the OUT Endpoint 7
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA7;                      /*!< 0x00000BF4 This register contains the DMA Address for the OUT Endpoint 7
                                                                of the Device controller. */
   __IM uint32_t RESERVED70;
   __IM uint32_t DOEPDMAB7;                     /*!< 0x00000BFC This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 7 of the Device controller. */
  __IOM uint32_t DOEPCTL8;                      /*!< 0x00000C00 This register is used to control the characteristics of OUT
                                                                Endpoint 8 of the Device controller. */
   __IM uint32_t RESERVED71;
  __IOM uint32_t DOEPINT8;                      /*!< 0x00000C08 This register contains the interrupts for the OUT Endpoint 8 of
                                                                the Device controller. */
   __IM uint32_t RESERVED72;
  __IOM uint32_t DOEPTSIZ8;                     /*!< 0x00000C10 This register contains the Transfer Size for the OUT Endpoint 8
                                                                of the Device controller. */
  __IOM uint32_t DOEPDMA8;                      /*!< 0x00000C14 This register contains the DMA Address for the OUT Endpoint 8
                                                                of the Device controller. */
   __IM uint32_t RESERVED73;
   __IM uint32_t DOEPDMAB8;                     /*!< 0x00000C1C This register contains the DMA Buffer Address for the OUT
                                                                Endpoint 8 of the Device controller. */
   __IM uint32_t RESERVED74[120];
  __IOM uint32_t PCGCCTL;                       /*!< 0x00000E00 This register is used to control the Power and Clock Gating
                                                                characteristics of the controller. */
  __IOM uint32_t PCGCCTL1;                      /*!< 0x00000E04 This register is used to control the Power and Clock Gating
                                                                characteristics of the controller. */
   __IM uint32_t RESERVED75[62];
} USBHS_DWC_OTG_INTREG_Type;                    /*!< Size = 3840 (0xF00) */

/**
  * \brief USBHS Subsystem, Controller, PHY control,configuration and status registers (USBHS_SS)
  */
typedef struct {
  __IOM uint32_t SUBSYSTEM_CTL;                 /*!< 0x00000000 Subsystem level control register */
  __IOM uint32_t PHY_FUNC_CTL_1;                /*!< 0x00000004 Subsystem level- PHY functional mode control register 1 */
  __IOM uint32_t PHY_FUNC_CTL_2;                /*!< 0x00000008 Subsystem level- PHY functional mode control register 2 */
  __IOM uint32_t PHY_TEST_CTL;                  /*!< 0x0000000C Subsystem level- PHY test mode control register */
  __IOM uint32_t CONTROLLER_DDFT_CTL;           /*!< 0x00000010 Subsystem level- Controller DDFT control register */
  __IOM uint32_t INTR_SS;                       /*!< 0x00000014 Subsystem level- Interrupt register */
  __IOM uint32_t INTR_SS_SET;                   /*!< 0x00000018 Subsystem level- Interrupt set register */
  __IOM uint32_t INTR_SS_MASK;                  /*!< 0x0000001C Subsystem level- Interrupt mask register */
   __IM uint32_t INTR_SS_MASKED;                /*!< 0x00000020 Subsystem level- Interrupt masked register */
   __IM uint32_t RESERVED[55];
} USBHS_SS_Type;                                /*!< Size = 256 (0x100) */

/**
  * \brief Regmap for both Subsystem and Controller IP (USBHS)
  */
typedef struct {
        USBHS_DWC_OTG_INTREG_Type DWC_OTG_INTREG; /*!< 0x00000000 Internal register map */
   __IM uint32_t RESERVED[64576];
        USBHS_SS_Type SS;                       /*!< 0x00040000 USBHS Subsystem, Controller, PHY control,configuration and
                                                                status registers */
} USBHS_Type;                                   /*!< Size = 262400 (0x40100) */


/* USBHS_DWC_OTG_INTREG.GOTGCTL */
#define USBHS_DWC_OTG_INTREG_GOTGCTL_VBVALIDOVEN_Pos 2UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_VBVALIDOVEN_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_VBVALIDOVVAL_Pos 3UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_VBVALIDOVVAL_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_AVALIDOVEN_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_AVALIDOVEN_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_AVALIDOVVAL_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_AVALIDOVVAL_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BVALIDOVEN_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BVALIDOVEN_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BVALIDOVVAL_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BVALIDOVVAL_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_DBNCEFLTRBYPASS_Pos 15UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_DBNCEFLTRBYPASS_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_CONIDSTS_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_CONIDSTS_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_DBNCTIME_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_DBNCTIME_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_ASESVLD_Pos 18UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_ASESVLD_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BSESVLD_Pos 19UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_BSESVLD_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_OTGVER_Pos 20UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_OTGVER_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_CURMOD_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_CURMOD_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_TESTMODE_CORR_EUSB2_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GOTGCTL_TESTMODE_CORR_EUSB2_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GOTGINT */
#define USBHS_DWC_OTG_INTREG_GOTGINT_SESENDDET_Pos 2UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_SESENDDET_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_SESREQSUCSTSCHNG_Pos 8UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_SESREQSUCSTSCHNG_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_HSTNEGSUCSTSCHNG_Pos 9UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_HSTNEGSUCSTSCHNG_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_HSTNEGDET_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_HSTNEGDET_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_ADEVTOUTCHG_Pos 18UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_ADEVTOUTCHG_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_DBNCEDONE_Pos 19UL
#define USBHS_DWC_OTG_INTREG_GOTGINT_DBNCEDONE_Msk 0x80000UL
/* USBHS_DWC_OTG_INTREG.GAHBCFG */
#define USBHS_DWC_OTG_INTREG_GAHBCFG_GLBLINTRMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_GLBLINTRMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_HBSTLEN_Pos 1UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_HBSTLEN_Msk 0x1EUL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_DMAEN_Pos  5UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_DMAEN_Msk  0x20UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_NPTXFEMPLVL_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_NPTXFEMPLVL_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_PTXFEMPLVL_Pos 8UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_PTXFEMPLVL_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_REMMEMSUPP_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_REMMEMSUPP_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_NOTIALLDMAWRIT_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_NOTIALLDMAWRIT_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_AHBSINGLE_Pos 23UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_AHBSINGLE_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_INVDESCENDIANESS_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GAHBCFG_INVDESCENDIANESS_Msk 0x1000000UL
/* USBHS_DWC_OTG_INTREG.GUSBCFG */
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TOUTCAL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TOUTCAL_Msk 0x7UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYIF_Pos  3UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYIF_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_ULPI_UTMI_SEL_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_ULPI_UTMI_SEL_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FSINTF_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FSINTF_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYSEL_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYSEL_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_USBTRDTIM_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_USBTRDTIM_Msk 0x3C00UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYLPWRCLKSEL_Pos 15UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_PHYLPWRCLKSEL_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TERMSELDLPULSE_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TERMSELDLPULSE_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_IC_USBCAP_Pos 26UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_IC_USBCAP_Msk 0x4000000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TXENDDELAY_Pos 28UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_TXENDDELAY_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FORCEHSTMODE_Pos 29UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FORCEHSTMODE_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FORCEDEVMODE_Pos 30UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_FORCEDEVMODE_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_CORRUPTTXPKT_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GUSBCFG_CORRUPTTXPKT_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GRSTCTL */
#define USBHS_DWC_OTG_INTREG_GRSTCTL_CSFTRST_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_CSFTRST_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_PIUFSSFTRST_Pos 1UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_PIUFSSFTRST_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_FRMCNTRRST_Pos 2UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_FRMCNTRRST_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_RXFFLSH_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_RXFFLSH_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_TXFFLSH_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_TXFFLSH_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_TXFNUM_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_TXFNUM_Msk 0x7C0UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_CSFTRSTDONE_Pos 29UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_CSFTRSTDONE_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_DMAREQ_Pos 30UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_DMAREQ_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_AHBIDLE_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GRSTCTL_AHBIDLE_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GINTSTS */
#define USBHS_DWC_OTG_INTREG_GINTSTS_CURMOD_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_CURMOD_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_MODEMIS_Pos 1UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_MODEMIS_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_OTGINT_Pos 2UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_OTGINT_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_SOF_Pos    3UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_SOF_Msk    0x8UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_RXFLVL_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_RXFLVL_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_NPTXFEMP_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_NPTXFEMP_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_GINNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_GINNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_GOUTNAKEFF_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_GOUTNAKEFF_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ERLYSUSP_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ERLYSUSP_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_USBSUSP_Pos 11UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_USBSUSP_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_USBRST_Pos 12UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_USBRST_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ENUMDONE_Pos 13UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ENUMDONE_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ISOOUTDROP_Pos 14UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_ISOOUTDROP_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_EOPF_Pos   15UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_EOPF_Msk   0x8000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_EPMIS_Pos  17UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_EPMIS_Msk  0x20000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_IEPINT_Pos 18UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_IEPINT_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_OEPINT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_OEPINT_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_INCOMPISOIN_Pos 20UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_INCOMPISOIN_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_INCOMPLP_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_INCOMPLP_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_FETSUSP_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_FETSUSP_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_RESETDET_Pos 23UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_RESETDET_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_PRTINT_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_PRTINT_Msk 0x1000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_HCHINT_Pos 25UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_HCHINT_Msk 0x2000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_PTXFEMP_Pos 26UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_PTXFEMP_Msk 0x4000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_LPM_INT_Pos 27UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_LPM_INT_Msk 0x8000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_CONIDSTSCHNG_Pos 28UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_CONIDSTSCHNG_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_DISCONNINT_Pos 29UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_DISCONNINT_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_SESSREQINT_Pos 30UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_SESSREQINT_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_WKUPINT_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GINTSTS_WKUPINT_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GINTMSK */
#define USBHS_DWC_OTG_INTREG_GINTMSK_MODEMISMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_MODEMISMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_OTGINTMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_OTGINTMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_SOFMSK_Pos 3UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_SOFMSK_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_RXFLVLMSK_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_RXFLVLMSK_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_NPTXFEMPMSK_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_NPTXFEMPMSK_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_GINNAKEFFMSK_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_GINNAKEFFMSK_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_GOUTNAKEFFMSK_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_GOUTNAKEFFMSK_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ERLYSUSPMSK_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ERLYSUSPMSK_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_USBSUSPMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_USBSUSPMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_USBRSTMSK_Pos 12UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_USBRSTMSK_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ENUMDONEMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ENUMDONEMSK_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ISOOUTDROPMSK_Pos 14UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_ISOOUTDROPMSK_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_EOPFMSK_Pos 15UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_EOPFMSK_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_EPMISMSK_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_EPMISMSK_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_IEPINTMSK_Pos 18UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_IEPINTMSK_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_OEPINTMSK_Pos 19UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_OEPINTMSK_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_INCOMPLPMSK_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_INCOMPLPMSK_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_FETSUSPMSK_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_FETSUSPMSK_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_RESETDETMSK_Pos 23UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_RESETDETMSK_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_PRTINTMSK_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_PRTINTMSK_Msk 0x1000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_HCHINTMSK_Pos 25UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_HCHINTMSK_Msk 0x2000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_PTXFEMPMSK_Pos 26UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_PTXFEMPMSK_Msk 0x4000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_LPM_INTMSK_Pos 27UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_LPM_INTMSK_Msk 0x8000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_CONIDSTSCHNGMSK_Pos 28UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_CONIDSTSCHNGMSK_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_DISCONNINTMSK_Pos 29UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_DISCONNINTMSK_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_SESSREQINTMSK_Pos 30UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_SESSREQINTMSK_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_WKUPINTMSK_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GINTMSK_WKUPINTMSK_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GRXSTSR */
#define USBHS_DWC_OTG_INTREG_GRXSTSR_CHNUM_Pos  0UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_CHNUM_Msk  0xFUL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_BCNT_Pos   4UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_BCNT_Msk   0x7FF0UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_DPID_Pos   15UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_DPID_Msk   0x18000UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_PKTSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_PKTSTS_Msk 0x1E0000UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_FN_Pos     21UL
#define USBHS_DWC_OTG_INTREG_GRXSTSR_FN_Msk     0x1E00000UL
/* USBHS_DWC_OTG_INTREG.GRXSTSP */
#define USBHS_DWC_OTG_INTREG_GRXSTSP_CHNUM_Pos  0UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_CHNUM_Msk  0xFUL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_BCNT_Pos   4UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_BCNT_Msk   0x7FF0UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_DPID_Pos   15UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_DPID_Msk   0x18000UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_PKTSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_PKTSTS_Msk 0x1E0000UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_FN_Pos     21UL
#define USBHS_DWC_OTG_INTREG_GRXSTSP_FN_Msk     0x1E00000UL
/* USBHS_DWC_OTG_INTREG.GRXFSIZ */
#define USBHS_DWC_OTG_INTREG_GRXFSIZ_RXFDEP_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GRXFSIZ_RXFDEP_Msk 0x3FFUL
/* USBHS_DWC_OTG_INTREG.GNPTXFSIZ */
#define USBHS_DWC_OTG_INTREG_GNPTXFSIZ_NPTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GNPTXFSIZ_NPTXFSTADDR_Msk 0x3FFUL
#define USBHS_DWC_OTG_INTREG_GNPTXFSIZ_NPTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GNPTXFSIZ_NPTXFDEP_Msk 0x1FF0000UL
/* USBHS_DWC_OTG_INTREG.GNPTXSTS */
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXFSPCAVAIL_Msk 0xFFFFUL
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXQSPCAVAIL_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXQSPCAVAIL_Msk 0xFF0000UL
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXQTOP_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GNPTXSTS_NPTXQTOP_Msk 0x7F000000UL
/* USBHS_DWC_OTG_INTREG.GGPIO */
#define USBHS_DWC_OTG_INTREG_GGPIO_GPI_Pos      0UL
#define USBHS_DWC_OTG_INTREG_GGPIO_GPI_Msk      0xFFFFUL
#define USBHS_DWC_OTG_INTREG_GGPIO_GPO_Pos      16UL
#define USBHS_DWC_OTG_INTREG_GGPIO_GPO_Msk      0xFFFF0000UL
/* USBHS_DWC_OTG_INTREG.GUID */
#define USBHS_DWC_OTG_INTREG_GUID_GUID_Pos      0UL
#define USBHS_DWC_OTG_INTREG_GUID_GUID_Msk      0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.GSNPSID */
#define USBHS_DWC_OTG_INTREG_GSNPSID_SYNOPSYSID_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GSNPSID_SYNOPSYSID_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.GHWCFG1 */
#define USBHS_DWC_OTG_INTREG_GHWCFG1_EPDIR_Pos  0UL
#define USBHS_DWC_OTG_INTREG_GHWCFG1_EPDIR_Msk  0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.GHWCFG2 */
#define USBHS_DWC_OTG_INTREG_GHWCFG2_OTGMODE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_OTGMODE_Msk 0x7UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_OTGARCH_Pos 3UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_OTGARCH_Msk 0x18UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_SINGPNT_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_SINGPNT_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_HSPHYTYPE_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_HSPHYTYPE_Msk 0xC0UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_FSPHYTYPE_Pos 8UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_FSPHYTYPE_Msk 0x300UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NUMDEVEPS_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NUMDEVEPS_Msk 0x3C00UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NUMHSTCHNL_Pos 14UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NUMHSTCHNL_Msk 0x3C000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_PERIOSUPPORT_Pos 18UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_PERIOSUPPORT_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_DYNFIFOSIZING_Pos 19UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_DYNFIFOSIZING_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_MULTIPROCINTRPT_Pos 20UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_MULTIPROCINTRPT_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NPTXQDEPTH_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_NPTXQDEPTH_Msk 0xC00000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_PTXQDEPTH_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_PTXQDEPTH_Msk 0x3000000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_TKNQDEPTH_Pos 26UL
#define USBHS_DWC_OTG_INTREG_GHWCFG2_TKNQDEPTH_Msk 0x7C000000UL
/* USBHS_DWC_OTG_INTREG.GHWCFG3 */
#define USBHS_DWC_OTG_INTREG_GHWCFG3_XFERSIZEWIDTH_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_XFERSIZEWIDTH_Msk 0xFUL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_PKTSIZEWIDTH_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_PKTSIZEWIDTH_Msk 0x70UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_OTGEN_Pos  7UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_OTGEN_Msk  0x80UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_I2CINTSEL_Pos 8UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_I2CINTSEL_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_VNDCTLSUPT_Pos 9UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_VNDCTLSUPT_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_OPTFEATURE_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_OPTFEATURE_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_RSTTYPE_Pos 11UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_RSTTYPE_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_ADPSUPPORT_Pos 12UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_ADPSUPPORT_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_HSICMODE_Pos 13UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_HSICMODE_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_BCSUPPORT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_BCSUPPORT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_LPMMODE_Pos 15UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_LPMMODE_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_DFIFODEPTH_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GHWCFG3_DFIFODEPTH_Msk 0xFFFF0000UL
/* USBHS_DWC_OTG_INTREG.GHWCFG4 */
#define USBHS_DWC_OTG_INTREG_GHWCFG4_NUMDEVPERIOEPS_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_NUMDEVPERIOEPS_Msk 0xFUL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_PARTIALPWRDN_Pos 4UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_PARTIALPWRDN_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_AHBFREQ_Pos 5UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_AHBFREQ_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_HIBERNATION_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_HIBERNATION_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_EXTENDEDHIBERNATION_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_EXTENDEDHIBERNATION_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ENHANCEDLPMSUPT1_Pos 9UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ENHANCEDLPMSUPT1_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_SERVINTFLOW_Pos 10UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_SERVINTFLOW_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_IPGISOCSUPT_Pos 11UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_IPGISOCSUPT_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ACGSUPT_Pos 12UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ACGSUPT_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ENHANCEDLPMSUPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_ENHANCEDLPMSUPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_PHYDATAWIDTH_Pos 14UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_PHYDATAWIDTH_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_NUMCTLEPS_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_NUMCTLEPS_Msk 0xF0000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_IDDGFLTR_Pos 20UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_IDDGFLTR_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_VBUSVALIDFLTR_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_VBUSVALIDFLTR_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_AVALIDFLTR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_AVALIDFLTR_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_BVALIDFLTR_Pos 23UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_BVALIDFLTR_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_SESSENDFLTR_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_SESSENDFLTR_Msk 0x1000000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DEDFIFOMODE_Pos 25UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DEDFIFOMODE_Msk 0x2000000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_INEPS_Pos  26UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_INEPS_Msk  0x3C000000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DESCDMAENABLED_Pos 30UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DESCDMAENABLED_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DESCDMA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_GHWCFG4_DESCDMA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.GLPMCFG */
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPMCAP_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPMCAP_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_APPL1RES_Pos 1UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_APPL1RES_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_HIRD_Pos   2UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_HIRD_Msk   0x3CUL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_BREMOTEWAKE_Pos 6UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_BREMOTEWAKE_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_ENBLSLPM_Pos 7UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_ENBLSLPM_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_HIRD_THRES_Pos 8UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_HIRD_THRES_Msk 0x1F00UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_COREL1RES_Pos 13UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_COREL1RES_Msk 0x6000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_SLPSTS_Pos 15UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_SLPSTS_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_L1RESUMEOK_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_L1RESUMEOK_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_CHNL_INDX_Pos 17UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_CHNL_INDX_Msk 0x1E0000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RETRY_CNT_Pos 21UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RETRY_CNT_Msk 0xE00000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_SNDLPM_Pos 24UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_SNDLPM_Msk 0x1000000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RETRYCNT_STS_Pos 25UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RETRYCNT_STS_Msk 0xE000000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_ENBESL_Pos 28UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_ENBESL_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RESTORESLPSTS_Pos 29UL
#define USBHS_DWC_OTG_INTREG_GLPMCFG_LPM_RESTORESLPSTS_Msk 0x20000000UL
/* USBHS_DWC_OTG_INTREG.GDFIFOCFG */
#define USBHS_DWC_OTG_INTREG_GDFIFOCFG_GDFIFOCFG_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GDFIFOCFG_GDFIFOCFG_Msk 0xFFFFUL
#define USBHS_DWC_OTG_INTREG_GDFIFOCFG_EPINFOBASEADDR_Pos 16UL
#define USBHS_DWC_OTG_INTREG_GDFIFOCFG_EPINFOBASEADDR_Msk 0xFFFF0000UL
/* USBHS_DWC_OTG_INTREG.GINTMSK2 */
#define USBHS_DWC_OTG_INTREG_GINTMSK2_GINTMSK2_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GINTMSK2_GINTMSK2_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.GINTSTS2 */
#define USBHS_DWC_OTG_INTREG_GINTSTS2_GINTSTS2_Pos 0UL
#define USBHS_DWC_OTG_INTREG_GINTSTS2_GINTSTS2_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HPTXFSIZ */
#define USBHS_DWC_OTG_INTREG_HPTXFSIZ_PTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HPTXFSIZ_PTXFSTADDR_Msk 0x3FFUL
#define USBHS_DWC_OTG_INTREG_HPTXFSIZ_PTXFSIZE_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HPTXFSIZ_PTXFSIZE_Msk 0x7FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF1 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF1_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF1_INEPNTXFSTADDR_Msk 0x3FFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF1_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF1_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF2 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF2_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF2_INEPNTXFSTADDR_Msk 0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF2_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF2_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF3 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF3_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF3_INEPNTXFSTADDR_Msk 0xFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF3_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF3_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF4 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF4_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF4_INEPNTXFSTADDR_Msk 0xFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF4_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF4_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF5 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF5_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF5_INEPNTXFSTADDR_Msk 0xFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF5_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF5_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF6 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF6_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF6_INEPNTXFSTADDR_Msk 0x1FFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF6_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF6_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF7 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF7_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF7_INEPNTXFSTADDR_Msk 0x1FFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF7_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF7_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.DIEPTXF8 */
#define USBHS_DWC_OTG_INTREG_DIEPTXF8_INEPNTXFSTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF8_INEPNTXFSTADDR_Msk 0x1FFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTXF8_INEPNTXFDEP_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DIEPTXF8_INEPNTXFDEP_Msk 0x3FF0000UL
/* USBHS_DWC_OTG_INTREG.HCFG */
#define USBHS_DWC_OTG_INTREG_HCFG_FSLSPCLKSEL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCFG_FSLSPCLKSEL_Msk 0x3UL
#define USBHS_DWC_OTG_INTREG_HCFG_FSLSSUPP_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCFG_FSLSSUPP_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCFG_ENA32KHZS_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCFG_ENA32KHZS_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCFG_RESVALID_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCFG_RESVALID_Msk  0xFF00UL
#define USBHS_DWC_OTG_INTREG_HCFG_DIS_TX_IPGAP_DLY_CHECK_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCFG_DIS_TX_IPGAP_DLY_CHECK_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCFG_DESCDMA_Pos   23UL
#define USBHS_DWC_OTG_INTREG_HCFG_DESCDMA_Msk   0x800000UL
#define USBHS_DWC_OTG_INTREG_HCFG_FRLISTEN_Pos  24UL
#define USBHS_DWC_OTG_INTREG_HCFG_FRLISTEN_Msk  0x3000000UL
#define USBHS_DWC_OTG_INTREG_HCFG_PERSCHEDENA_Pos 26UL
#define USBHS_DWC_OTG_INTREG_HCFG_PERSCHEDENA_Msk 0x4000000UL
#define USBHS_DWC_OTG_INTREG_HCFG_MODECHTIMEN_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCFG_MODECHTIMEN_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HFIR */
#define USBHS_DWC_OTG_INTREG_HFIR_FRINT_Pos     0UL
#define USBHS_DWC_OTG_INTREG_HFIR_FRINT_Msk     0xFFFFUL
#define USBHS_DWC_OTG_INTREG_HFIR_HFIRRLDCTRL_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HFIR_HFIRRLDCTRL_Msk 0x10000UL
/* USBHS_DWC_OTG_INTREG.HFNUM */
#define USBHS_DWC_OTG_INTREG_HFNUM_FRNUM_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HFNUM_FRNUM_Msk    0xFFFFUL
#define USBHS_DWC_OTG_INTREG_HFNUM_FRREM_Pos    16UL
#define USBHS_DWC_OTG_INTREG_HFNUM_FRREM_Msk    0xFFFF0000UL
/* USBHS_DWC_OTG_INTREG.HPTXSTS */
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXFSPCAVAIL_Msk 0xFFFFUL
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXQSPCAVAIL_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXQSPCAVAIL_Msk 0x7F0000UL
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXQTOP_Pos 23UL
#define USBHS_DWC_OTG_INTREG_HPTXSTS_PTXQTOP_Msk 0xFF800000UL
/* USBHS_DWC_OTG_INTREG.HAINT */
#define USBHS_DWC_OTG_INTREG_HAINT_HAINT_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HAINT_HAINT_Msk    0xFFFFUL
/* USBHS_DWC_OTG_INTREG.HAINTMSK */
#define USBHS_DWC_OTG_INTREG_HAINTMSK_HAINTMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HAINTMSK_HAINTMSK_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.HFLBADDR */
#define USBHS_DWC_OTG_INTREG_HFLBADDR_HFLBADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HFLBADDR_HFLBADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HPRT */
#define USBHS_DWC_OTG_INTREG_HPRT_PRTCONNSTS_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTCONNSTS_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTCONNDET_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTCONNDET_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTENA_Pos    2UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTENA_Msk    0x4UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTENCHNG_Pos 3UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTENCHNG_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTOVRCURRACT_Pos 4UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTOVRCURRACT_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTOVRCURRCHNG_Pos 5UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTOVRCURRCHNG_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTRES_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTRES_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTSUSP_Pos   7UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTSUSP_Msk   0x80UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTRST_Pos    8UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTRST_Msk    0x100UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTLNSTS_Pos  10UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTLNSTS_Msk  0xC00UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTPWR_Pos    12UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTPWR_Msk    0x1000UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTTSTCTL_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTTSTCTL_Msk 0x1E000UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTSPD_Pos    17UL
#define USBHS_DWC_OTG_INTREG_HPRT_PRTSPD_Msk    0x60000UL
/* USBHS_DWC_OTG_INTREG.HCCHAR0 */
#define USBHS_DWC_OTG_INTREG_HCCHAR0_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR0_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT0 */
#define USBHS_DWC_OTG_INTREG_HCSPLT0_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT0_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT0 */
#define USBHS_DWC_OTG_INTREG_HCINT0_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT0_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT0_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT0_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT0_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT0_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT0_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT0_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT0_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT0_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT0_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT0_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT0_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT0_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT0_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT0_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT0_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT0_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT0_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT0_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT0_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT0_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT0_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT0_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT0_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT0_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT0_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT0_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK0 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK0_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ0 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ0_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA0 */
#define USBHS_DWC_OTG_INTREG_HCDMA0_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA0_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB0 */
#define USBHS_DWC_OTG_INTREG_HCDMAB0_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB0_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR1 */
#define USBHS_DWC_OTG_INTREG_HCCHAR1_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR1_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT1 */
#define USBHS_DWC_OTG_INTREG_HCSPLT1_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT1_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT1 */
#define USBHS_DWC_OTG_INTREG_HCINT1_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT1_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT1_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT1_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT1_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT1_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT1_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT1_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT1_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT1_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT1_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT1_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT1_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT1_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT1_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT1_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT1_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT1_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT1_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT1_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT1_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT1_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT1_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT1_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT1_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT1_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT1_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT1_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK1 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK1_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ1 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ1_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA1 */
#define USBHS_DWC_OTG_INTREG_HCDMA1_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA1_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB1 */
#define USBHS_DWC_OTG_INTREG_HCDMAB1_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB1_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR2 */
#define USBHS_DWC_OTG_INTREG_HCCHAR2_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR2_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT2 */
#define USBHS_DWC_OTG_INTREG_HCSPLT2_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT2_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT2 */
#define USBHS_DWC_OTG_INTREG_HCINT2_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT2_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT2_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT2_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT2_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT2_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT2_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT2_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT2_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT2_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT2_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT2_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT2_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT2_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT2_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT2_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT2_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT2_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT2_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT2_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT2_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT2_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT2_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT2_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT2_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT2_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT2_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT2_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK2 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK2_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ2 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ2_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA2 */
#define USBHS_DWC_OTG_INTREG_HCDMA2_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA2_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB2 */
#define USBHS_DWC_OTG_INTREG_HCDMAB2_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB2_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR3 */
#define USBHS_DWC_OTG_INTREG_HCCHAR3_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR3_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT3 */
#define USBHS_DWC_OTG_INTREG_HCSPLT3_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT3_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT3 */
#define USBHS_DWC_OTG_INTREG_HCINT3_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT3_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT3_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT3_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT3_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT3_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT3_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT3_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT3_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT3_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT3_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT3_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT3_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT3_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT3_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT3_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT3_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT3_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT3_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT3_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT3_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT3_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT3_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT3_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT3_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT3_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT3_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT3_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK3 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK3_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ3 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ3_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA3 */
#define USBHS_DWC_OTG_INTREG_HCDMA3_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA3_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB3 */
#define USBHS_DWC_OTG_INTREG_HCDMAB3_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB3_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR4 */
#define USBHS_DWC_OTG_INTREG_HCCHAR4_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR4_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT4 */
#define USBHS_DWC_OTG_INTREG_HCSPLT4_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT4_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT4 */
#define USBHS_DWC_OTG_INTREG_HCINT4_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT4_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT4_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT4_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT4_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT4_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT4_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT4_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT4_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT4_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT4_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT4_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT4_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT4_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT4_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT4_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT4_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT4_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT4_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT4_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT4_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT4_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT4_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT4_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT4_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT4_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT4_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT4_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK4 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK4_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ4 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ4_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA4 */
#define USBHS_DWC_OTG_INTREG_HCDMA4_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA4_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB4 */
#define USBHS_DWC_OTG_INTREG_HCDMAB4_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB4_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR5 */
#define USBHS_DWC_OTG_INTREG_HCCHAR5_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR5_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT5 */
#define USBHS_DWC_OTG_INTREG_HCSPLT5_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT5_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT5 */
#define USBHS_DWC_OTG_INTREG_HCINT5_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT5_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT5_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT5_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT5_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT5_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT5_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT5_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT5_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT5_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT5_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT5_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT5_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT5_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT5_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT5_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT5_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT5_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT5_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT5_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT5_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT5_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT5_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT5_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT5_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT5_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT5_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT5_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK5 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK5_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ5 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ5_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA5 */
#define USBHS_DWC_OTG_INTREG_HCDMA5_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA5_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB5 */
#define USBHS_DWC_OTG_INTREG_HCDMAB5_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB5_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR6 */
#define USBHS_DWC_OTG_INTREG_HCCHAR6_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR6_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT6 */
#define USBHS_DWC_OTG_INTREG_HCSPLT6_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT6_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT6 */
#define USBHS_DWC_OTG_INTREG_HCINT6_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT6_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT6_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT6_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT6_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT6_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT6_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT6_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT6_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT6_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT6_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT6_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT6_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT6_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT6_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT6_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT6_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT6_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT6_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT6_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT6_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT6_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT6_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT6_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT6_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT6_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT6_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT6_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK6 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK6_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ6 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ6_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA6 */
#define USBHS_DWC_OTG_INTREG_HCDMA6_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA6_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB6 */
#define USBHS_DWC_OTG_INTREG_HCDMAB6_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB6_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR7 */
#define USBHS_DWC_OTG_INTREG_HCCHAR7_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR7_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT7 */
#define USBHS_DWC_OTG_INTREG_HCSPLT7_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT7_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT7 */
#define USBHS_DWC_OTG_INTREG_HCINT7_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT7_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT7_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT7_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT7_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT7_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT7_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT7_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT7_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT7_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT7_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT7_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT7_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT7_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT7_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT7_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT7_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT7_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT7_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT7_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT7_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT7_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT7_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT7_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT7_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT7_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT7_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT7_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK7 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK7_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ7 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ7_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA7 */
#define USBHS_DWC_OTG_INTREG_HCDMA7_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA7_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB7 */
#define USBHS_DWC_OTG_INTREG_HCDMAB7_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB7_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR8 */
#define USBHS_DWC_OTG_INTREG_HCCHAR8_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR8_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT8 */
#define USBHS_DWC_OTG_INTREG_HCSPLT8_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT8_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT8 */
#define USBHS_DWC_OTG_INTREG_HCINT8_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT8_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT8_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT8_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT8_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT8_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT8_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT8_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT8_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT8_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT8_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT8_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT8_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT8_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT8_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT8_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT8_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT8_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT8_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT8_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT8_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT8_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT8_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT8_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT8_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT8_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT8_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT8_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK8 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK8_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ8 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ8_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA8 */
#define USBHS_DWC_OTG_INTREG_HCDMA8_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA8_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB8 */
#define USBHS_DWC_OTG_INTREG_HCDMAB8_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB8_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR9 */
#define USBHS_DWC_OTG_INTREG_HCCHAR9_MPS_Pos    0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_MPS_Msk    0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPNUM_Pos  11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPNUM_Msk  0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPDIR_Pos  15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPDIR_Msk  0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EC_Pos     20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_EC_Msk     0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_CHDIS_Pos  30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_CHDIS_Msk  0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_CHENA_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR9_CHENA_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT9 */
#define USBHS_DWC_OTG_INTREG_HCSPLT9_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT9_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT9 */
#define USBHS_DWC_OTG_INTREG_HCINT9_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT9_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT9_CHHLTD_Pos  1UL
#define USBHS_DWC_OTG_INTREG_HCINT9_CHHLTD_Msk  0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT9_AHBERR_Pos  2UL
#define USBHS_DWC_OTG_INTREG_HCINT9_AHBERR_Msk  0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT9_STALL_Pos   3UL
#define USBHS_DWC_OTG_INTREG_HCINT9_STALL_Msk   0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT9_NAK_Pos     4UL
#define USBHS_DWC_OTG_INTREG_HCINT9_NAK_Msk     0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT9_ACK_Pos     5UL
#define USBHS_DWC_OTG_INTREG_HCINT9_ACK_Msk     0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT9_NYET_Pos    6UL
#define USBHS_DWC_OTG_INTREG_HCINT9_NYET_Msk    0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT9_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT9_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT9_BBLERR_Pos  8UL
#define USBHS_DWC_OTG_INTREG_HCINT9_BBLERR_Msk  0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT9_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT9_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT9_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT9_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT9_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT9_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT9_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT9_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT9_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT9_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK9 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK9_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ9 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_PID_Pos    29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_PID_Msk    0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_DOPNG_Pos  31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ9_DOPNG_Msk  0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA9 */
#define USBHS_DWC_OTG_INTREG_HCDMA9_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA9_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB9 */
#define USBHS_DWC_OTG_INTREG_HCDMAB9_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB9_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR10 */
#define USBHS_DWC_OTG_INTREG_HCCHAR10_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR10_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT10 */
#define USBHS_DWC_OTG_INTREG_HCSPLT10_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT10_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT10 */
#define USBHS_DWC_OTG_INTREG_HCINT10_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT10_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT10_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT10_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT10_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT10_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT10_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT10_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT10_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT10_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT10_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT10_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT10_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT10_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT10_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT10_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT10_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT10_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT10_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT10_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT10_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT10_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT10_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT10_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT10_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT10_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT10_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT10_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK10 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK10_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ10 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ10_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA10 */
#define USBHS_DWC_OTG_INTREG_HCDMA10_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA10_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB10 */
#define USBHS_DWC_OTG_INTREG_HCDMAB10_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB10_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR11 */
#define USBHS_DWC_OTG_INTREG_HCCHAR11_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR11_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT11 */
#define USBHS_DWC_OTG_INTREG_HCSPLT11_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT11_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT11 */
#define USBHS_DWC_OTG_INTREG_HCINT11_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT11_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT11_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT11_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT11_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT11_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT11_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT11_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT11_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT11_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT11_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT11_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT11_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT11_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT11_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT11_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT11_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT11_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT11_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT11_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT11_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT11_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT11_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT11_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT11_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT11_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT11_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT11_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK11 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK11_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ11 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ11_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA11 */
#define USBHS_DWC_OTG_INTREG_HCDMA11_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA11_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB11 */
#define USBHS_DWC_OTG_INTREG_HCDMAB11_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB11_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR12 */
#define USBHS_DWC_OTG_INTREG_HCCHAR12_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR12_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT12 */
#define USBHS_DWC_OTG_INTREG_HCSPLT12_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT12_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT12 */
#define USBHS_DWC_OTG_INTREG_HCINT12_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT12_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT12_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT12_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT12_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT12_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT12_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT12_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT12_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT12_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT12_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT12_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT12_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT12_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT12_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT12_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT12_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT12_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT12_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT12_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT12_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT12_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT12_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT12_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT12_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT12_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT12_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT12_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK12 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK12_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ12 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ12_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA12 */
#define USBHS_DWC_OTG_INTREG_HCDMA12_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA12_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB12 */
#define USBHS_DWC_OTG_INTREG_HCDMAB12_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB12_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR13 */
#define USBHS_DWC_OTG_INTREG_HCCHAR13_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR13_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT13 */
#define USBHS_DWC_OTG_INTREG_HCSPLT13_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT13_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT13 */
#define USBHS_DWC_OTG_INTREG_HCINT13_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT13_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT13_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT13_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT13_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT13_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT13_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT13_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT13_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT13_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT13_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT13_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT13_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT13_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT13_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT13_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT13_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT13_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT13_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT13_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT13_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT13_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT13_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT13_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT13_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT13_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT13_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT13_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK13 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK13_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ13 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ13_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA13 */
#define USBHS_DWC_OTG_INTREG_HCDMA13_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA13_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB13 */
#define USBHS_DWC_OTG_INTREG_HCDMAB13_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB13_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR14 */
#define USBHS_DWC_OTG_INTREG_HCCHAR14_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR14_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT14 */
#define USBHS_DWC_OTG_INTREG_HCSPLT14_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT14_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT14 */
#define USBHS_DWC_OTG_INTREG_HCINT14_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT14_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT14_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT14_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT14_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT14_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT14_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT14_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT14_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT14_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT14_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT14_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT14_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT14_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT14_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT14_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT14_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT14_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT14_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT14_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT14_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT14_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT14_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT14_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT14_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT14_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT14_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT14_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK14 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK14_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ14 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ14_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA14 */
#define USBHS_DWC_OTG_INTREG_HCDMA14_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA14_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB14 */
#define USBHS_DWC_OTG_INTREG_HCDMAB14_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB14_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCCHAR15 */
#define USBHS_DWC_OTG_INTREG_HCCHAR15_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPNUM_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPNUM_Msk 0x7800UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPDIR_Pos 15UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPDIR_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_LSPDDEV_Pos 17UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_LSPDDEV_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EC_Pos    20UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_EC_Msk    0x300000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_DEVADDR_Pos 22UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_DEVADDR_Msk 0x1FC00000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_ODDFRM_Pos 29UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_ODDFRM_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_CHDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_CHDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_CHENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCCHAR15_CHENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCSPLT15 */
#define USBHS_DWC_OTG_INTREG_HCSPLT15_PRTADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_PRTADDR_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_HUBADDR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_HUBADDR_Msk 0x3F80UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_XACTPOS_Pos 14UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_XACTPOS_Msk 0xC000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_COMPSPLT_Pos 16UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_COMPSPLT_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_SPLTENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCSPLT15_SPLTENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCINT15 */
#define USBHS_DWC_OTG_INTREG_HCINT15_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINT15_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINT15_CHHLTD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINT15_CHHLTD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINT15_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINT15_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINT15_STALL_Pos  3UL
#define USBHS_DWC_OTG_INTREG_HCINT15_STALL_Msk  0x8UL
#define USBHS_DWC_OTG_INTREG_HCINT15_NAK_Pos    4UL
#define USBHS_DWC_OTG_INTREG_HCINT15_NAK_Msk    0x10UL
#define USBHS_DWC_OTG_INTREG_HCINT15_ACK_Pos    5UL
#define USBHS_DWC_OTG_INTREG_HCINT15_ACK_Msk    0x20UL
#define USBHS_DWC_OTG_INTREG_HCINT15_NYET_Pos   6UL
#define USBHS_DWC_OTG_INTREG_HCINT15_NYET_Msk   0x40UL
#define USBHS_DWC_OTG_INTREG_HCINT15_XACTERR_Pos 7UL
#define USBHS_DWC_OTG_INTREG_HCINT15_XACTERR_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_HCINT15_BBLERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_HCINT15_BBLERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_HCINT15_FRMOVRUN_Pos 9UL
#define USBHS_DWC_OTG_INTREG_HCINT15_FRMOVRUN_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_HCINT15_DATATGLERR_Pos 10UL
#define USBHS_DWC_OTG_INTREG_HCINT15_DATATGLERR_Msk 0x400UL
#define USBHS_DWC_OTG_INTREG_HCINT15_BNAINTR_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINT15_BNAINTR_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINT15_XCS_XACT_ERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_HCINT15_XCS_XACT_ERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_HCINT15_DESC_LST_ROLLINTR_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINT15_DESC_LST_ROLLINTR_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCINTMSK15 */
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_CHHLTDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_CHHLTDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_BNAINTRMSK_Pos 11UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_BNAINTRMSK_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_DESC_LST_ROLLINTRMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_HCINTMSK15_DESC_LST_ROLLINTRMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.HCTSIZ15 */
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_PID_Pos   29UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_PID_Msk   0x60000000UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_DOPNG_Pos 31UL
#define USBHS_DWC_OTG_INTREG_HCTSIZ15_DOPNG_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.HCDMA15 */
#define USBHS_DWC_OTG_INTREG_HCDMA15_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMA15_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.HCDMAB15 */
#define USBHS_DWC_OTG_INTREG_HCDMAB15_HCDMAB_Pos 0UL
#define USBHS_DWC_OTG_INTREG_HCDMAB15_HCDMAB_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DCFG */
#define USBHS_DWC_OTG_INTREG_DCFG_DEVSPD_Pos    0UL
#define USBHS_DWC_OTG_INTREG_DCFG_DEVSPD_Msk    0x3UL
#define USBHS_DWC_OTG_INTREG_DCFG_NZSTSOUTHSHK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DCFG_NZSTSOUTHSHK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DCFG_ENA32KHZSUSP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DCFG_ENA32KHZSUSP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DCFG_DEVADDR_Pos   4UL
#define USBHS_DWC_OTG_INTREG_DCFG_DEVADDR_Msk   0x7F0UL
#define USBHS_DWC_OTG_INTREG_DCFG_PERFRINT_Pos  11UL
#define USBHS_DWC_OTG_INTREG_DCFG_PERFRINT_Msk  0x1800UL
#define USBHS_DWC_OTG_INTREG_DCFG_ENDEVOUTNAK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DCFG_ENDEVOUTNAK_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DCFG_XCVRDLY_Pos   14UL
#define USBHS_DWC_OTG_INTREG_DCFG_XCVRDLY_Msk   0x4000UL
#define USBHS_DWC_OTG_INTREG_DCFG_ERRATICINTMSK_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DCFG_ERRATICINTMSK_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DCFG_IPGISOCSUPT_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DCFG_IPGISOCSUPT_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DCFG_DESCDMA_Pos   23UL
#define USBHS_DWC_OTG_INTREG_DCFG_DESCDMA_Msk   0x800000UL
#define USBHS_DWC_OTG_INTREG_DCFG_PERSCHINTVL_Pos 24UL
#define USBHS_DWC_OTG_INTREG_DCFG_PERSCHINTVL_Msk 0x3000000UL
#define USBHS_DWC_OTG_INTREG_DCFG_RESVALID_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DCFG_RESVALID_Msk  0xFC000000UL
/* USBHS_DWC_OTG_INTREG.DCTL */
#define USBHS_DWC_OTG_INTREG_DCTL_RMTWKUPSIG_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DCTL_RMTWKUPSIG_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DCTL_SFTDISCON_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DCTL_SFTDISCON_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DCTL_GNPINNAKSTS_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DCTL_GNPINNAKSTS_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DCTL_GOUTNAKSTS_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DCTL_GOUTNAKSTS_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DCTL_TSTCTL_Pos    4UL
#define USBHS_DWC_OTG_INTREG_DCTL_TSTCTL_Msk    0x70UL
#define USBHS_DWC_OTG_INTREG_DCTL_SGNPINNAK_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DCTL_SGNPINNAK_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DCTL_CGNPINNAK_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DCTL_CGNPINNAK_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DCTL_SGOUTNAK_Pos  9UL
#define USBHS_DWC_OTG_INTREG_DCTL_SGOUTNAK_Msk  0x200UL
#define USBHS_DWC_OTG_INTREG_DCTL_CGOUTNAK_Pos  10UL
#define USBHS_DWC_OTG_INTREG_DCTL_CGOUTNAK_Msk  0x400UL
#define USBHS_DWC_OTG_INTREG_DCTL_PWRONPRGDONE_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DCTL_PWRONPRGDONE_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DCTL_GMC_Pos       13UL
#define USBHS_DWC_OTG_INTREG_DCTL_GMC_Msk       0x6000UL
#define USBHS_DWC_OTG_INTREG_DCTL_IGNRFRMNUM_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DCTL_IGNRFRMNUM_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DCTL_NAKONBBLE_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DCTL_NAKONBBLE_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_DCTL_ENCONTONBNA_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DCTL_ENCONTONBNA_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DCTL_DEEPSLEEPBESLREJECT_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DCTL_DEEPSLEEPBESLREJECT_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_DCTL_SERVINT_Pos   19UL
#define USBHS_DWC_OTG_INTREG_DCTL_SERVINT_Msk   0x80000UL
/* USBHS_DWC_OTG_INTREG.DSTS */
#define USBHS_DWC_OTG_INTREG_DSTS_SUSPSTS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DSTS_SUSPSTS_Msk   0x1UL
#define USBHS_DWC_OTG_INTREG_DSTS_ENUMSPD_Pos   1UL
#define USBHS_DWC_OTG_INTREG_DSTS_ENUMSPD_Msk   0x6UL
#define USBHS_DWC_OTG_INTREG_DSTS_ERRTICERR_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DSTS_ERRTICERR_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DSTS_SOFFN_Pos     8UL
#define USBHS_DWC_OTG_INTREG_DSTS_SOFFN_Msk     0x3FFF00UL
#define USBHS_DWC_OTG_INTREG_DSTS_DEVLNSTS_Pos  22UL
#define USBHS_DWC_OTG_INTREG_DSTS_DEVLNSTS_Msk  0xC00000UL
/* USBHS_DWC_OTG_INTREG.DIEPMSK */
#define USBHS_DWC_OTG_INTREG_DIEPMSK_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_EPDISBLDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_EPDISBLDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_TIMEOUTMSK_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_TIMEOUTMSK_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INTKNTXFEMPMSK_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INTKNTXFEMPMSK_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INTKNEPMISMSK_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INTKNEPMISMSK_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INEPNAKEFFMSK_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_INEPNAKEFFMSK_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_TXFIFOUNDRNMSK_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_TXFIFOUNDRNMSK_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_BNAININTRMSK_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_BNAININTRMSK_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_NAKMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPMSK_NAKMSK_Msk 0x2000UL
/* USBHS_DWC_OTG_INTREG.DOEPMSK */
#define USBHS_DWC_OTG_INTREG_DOEPMSK_XFERCOMPLMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_XFERCOMPLMSK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_EPDISBLDMSK_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_EPDISBLDMSK_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_AHBERRMSK_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_AHBERRMSK_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_SETUPMSK_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_SETUPMSK_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_OUTTKNEPDISMSK_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_OUTTKNEPDISMSK_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_STSPHSERCVDMSK_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_STSPHSERCVDMSK_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_OUTPKTERRMSK_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_OUTPKTERRMSK_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BNAOUTINTRMSK_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BNAOUTINTRMSK_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BBLEERRMSK_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_BBLEERRMSK_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_NAKMSK_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_NAKMSK_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_NYETMSK_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPMSK_NYETMSK_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DAINT */
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT0_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT0_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT1_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT1_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT2_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT2_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT3_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT3_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT4_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT4_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT5_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT5_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT6_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT6_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT7_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT7_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT8_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DAINT_INEPINT8_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT0_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT0_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT1_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT1_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT2_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT2_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT3_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT3_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT4_Pos 20UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT4_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT5_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT5_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT6_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT6_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT7_Pos 23UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT7_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT8_Pos 24UL
#define USBHS_DWC_OTG_INTREG_DAINT_OUTEPINT8_Msk 0x1000000UL
/* USBHS_DWC_OTG_INTREG.DAINTMSK */
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK0_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK0_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK1_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK1_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK2_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK2_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK3_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK3_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK4_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK4_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK5_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK5_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK6_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK6_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK7_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK7_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK8_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_INEPMSK8_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK0_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK0_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK1_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK1_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK2_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK2_Msk 0x40000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK3_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK3_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK4_Pos 20UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK4_Msk 0x100000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK5_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK5_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK6_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK6_Msk 0x400000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK7_Pos 23UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK7_Msk 0x800000UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK8_Pos 24UL
#define USBHS_DWC_OTG_INTREG_DAINTMSK_OUTEPMSK8_Msk 0x1000000UL
/* USBHS_DWC_OTG_INTREG.DVBUSDIS */
#define USBHS_DWC_OTG_INTREG_DVBUSDIS_DVBUSDIS_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DVBUSDIS_DVBUSDIS_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DVBUSPULSE */
#define USBHS_DWC_OTG_INTREG_DVBUSPULSE_DVBUSPULSE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DVBUSPULSE_DVBUSPULSE_Msk 0xFFFUL
/* USBHS_DWC_OTG_INTREG.DTHRCTL */
#define USBHS_DWC_OTG_INTREG_DTHRCTL_NONISOTHREN_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_NONISOTHREN_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_ISOTHREN_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_ISOTHREN_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_TXTHRLEN_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_TXTHRLEN_Msk 0x7FCUL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_AHBTHRRATIO_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_AHBTHRRATIO_Msk 0x1800UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_RXTHREN_Pos 16UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_RXTHREN_Msk 0x10000UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_RXTHRLEN_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_RXTHRLEN_Msk 0x3FE0000UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_ARBPRKEN_Pos 27UL
#define USBHS_DWC_OTG_INTREG_DTHRCTL_ARBPRKEN_Msk 0x8000000UL
/* USBHS_DWC_OTG_INTREG.DIEPEMPMSK */
#define USBHS_DWC_OTG_INTREG_DIEPEMPMSK_INEPTXFEMPMSK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPEMPMSK_INEPTXFEMPMSK_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL0 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_MPS_Msk   0x3UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL0_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT0 */
#define USBHS_DWC_OTG_INTREG_DIEPINT0_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT0_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ0 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ0_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ0_XFERSIZE_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ0_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ0_PKTCNT_Msk 0x180000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA0 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA0_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA0_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS0 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS0_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS0_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB0 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB0_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB0_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL1 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL1_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT1 */
#define USBHS_DWC_OTG_INTREG_DIEPINT1_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT1_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ1 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ1_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA1 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA1_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA1_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS1 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS1_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS1_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB1 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB1_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB1_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL2 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL2_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT2 */
#define USBHS_DWC_OTG_INTREG_DIEPINT2_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT2_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ2 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ2_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA2 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA2_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA2_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS2 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS2_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS2_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB2 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB2_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB2_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL3 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL3_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT3 */
#define USBHS_DWC_OTG_INTREG_DIEPINT3_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT3_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ3 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ3_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA3 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA3_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA3_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS3 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS3_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS3_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB3 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB3_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB3_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL4 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL4_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT4 */
#define USBHS_DWC_OTG_INTREG_DIEPINT4_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT4_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ4 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ4_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA4 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA4_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA4_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS4 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS4_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS4_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB4 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB4_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB4_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL5 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL5_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT5 */
#define USBHS_DWC_OTG_INTREG_DIEPINT5_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT5_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ5 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ5_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA5 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA5_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA5_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS5 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS5_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS5_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB5 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB5_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB5_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL6 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL6_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT6 */
#define USBHS_DWC_OTG_INTREG_DIEPINT6_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT6_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ6 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ6_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA6 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA6_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA6_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS6 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS6_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS6_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB6 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB6_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB6_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL7 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL7_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT7 */
#define USBHS_DWC_OTG_INTREG_DIEPINT7_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT7_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ7 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ7_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA7 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA7_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA7_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS7 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS7_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS7_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB7 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB7_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB7_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPCTL8 */
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_TXFNUM_Pos 22UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_TXFNUM_Msk 0x3C00000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DIEPCTL8_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DIEPINT8 */
#define USBHS_DWC_OTG_INTREG_DIEPINT8_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TIMEOUT_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TIMEOUT_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INTKNTXFEMP_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INTKNTXFEMP_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INTKNEPMIS_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INTKNEPMIS_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INEPNAKEFF_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_INEPNAKEFF_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TXFEMP_Pos 7UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TXFEMP_Msk 0x80UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TXFIFOUNDRN_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_TXFIFOUNDRN_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DIEPINT8_NYETINTRPT_Msk 0x4000UL
/* USBHS_DWC_OTG_INTREG.DIEPTSIZ8 */
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_MC_Pos   29UL
#define USBHS_DWC_OTG_INTREG_DIEPTSIZ8_MC_Msk   0x60000000UL
/* USBHS_DWC_OTG_INTREG.DIEPDMA8 */
#define USBHS_DWC_OTG_INTREG_DIEPDMA8_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMA8_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DTXFSTS8 */
#define USBHS_DWC_OTG_INTREG_DTXFSTS8_INEPTXFSPCAVAIL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DTXFSTS8_INEPTXFSPCAVAIL_Msk 0xFFFFUL
/* USBHS_DWC_OTG_INTREG.DIEPDMAB8 */
#define USBHS_DWC_OTG_INTREG_DIEPDMAB8_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DIEPDMAB8_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL0 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_MPS_Msk   0x3UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL0_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT0 */
#define USBHS_DWC_OTG_INTREG_DOEPINT0_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT0_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ0 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_XFERSIZE_Msk 0x7FUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_PKTCNT_Msk 0x80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_SUPCNT_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ0_SUPCNT_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA0 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA0_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA0_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB0 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB0_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB0_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL1 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL1_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT1 */
#define USBHS_DWC_OTG_INTREG_DOEPINT1_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT1_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ1 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ1_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA1 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA1_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA1_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB1 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB1_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB1_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL2 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL2_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT2 */
#define USBHS_DWC_OTG_INTREG_DOEPINT2_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT2_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ2 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ2_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA2 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA2_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA2_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB2 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB2_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB2_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL3 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL3_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT3 */
#define USBHS_DWC_OTG_INTREG_DOEPINT3_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT3_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ3 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ3_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA3 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA3_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA3_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB3 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB3_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB3_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL4 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL4_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT4 */
#define USBHS_DWC_OTG_INTREG_DOEPINT4_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT4_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ4 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ4_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA4 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA4_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA4_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB4 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB4_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB4_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL5 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL5_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT5 */
#define USBHS_DWC_OTG_INTREG_DOEPINT5_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT5_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ5 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ5_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA5 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA5_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA5_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB5 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB5_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB5_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL6 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL6_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT6 */
#define USBHS_DWC_OTG_INTREG_DOEPINT6_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT6_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ6 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ6_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA6 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA6_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA6_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB6 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB6_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB6_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL7 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL7_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT7 */
#define USBHS_DWC_OTG_INTREG_DOEPINT7_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT7_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ7 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ7_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA7 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA7_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA7_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB7 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB7_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB7_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPCTL8 */
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_MPS_Pos   0UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_MPS_Msk   0x7FFUL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_USBACTEP_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_USBACTEP_Msk 0x8000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_DPID_Pos  16UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_DPID_Msk  0x10000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_NAKSTS_Pos 17UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_NAKSTS_Msk 0x20000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPTYPE_Pos 18UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPTYPE_Msk 0xC0000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SNP_Pos   20UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SNP_Msk   0x100000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_STALL_Pos 21UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_STALL_Msk 0x200000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_CNAK_Pos  26UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_CNAK_Msk  0x4000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SNAK_Pos  27UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SNAK_Msk  0x8000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SETD0PID_Pos 28UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SETD0PID_Msk 0x10000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SETD1PID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_SETD1PID_Msk 0x20000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPDIS_Pos 30UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPDIS_Msk 0x40000000UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPENA_Pos 31UL
#define USBHS_DWC_OTG_INTREG_DOEPCTL8_EPENA_Msk 0x80000000UL
/* USBHS_DWC_OTG_INTREG.DOEPINT8 */
#define USBHS_DWC_OTG_INTREG_DOEPINT8_XFERCOMPL_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_XFERCOMPL_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_EPDISBLD_Pos 1UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_EPDISBLD_Msk 0x2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_AHBERR_Pos 2UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_AHBERR_Msk 0x4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_SETUP_Pos 3UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_SETUP_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_OUTTKNEPDIS_Pos 4UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_OUTTKNEPDIS_Msk 0x10UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_STSPHSERCVD_Pos 5UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_STSPHSERCVD_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BACK2BACKSETUP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BACK2BACKSETUP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_OUTPKTERR_Pos 8UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_OUTPKTERR_Msk 0x100UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BNAINTR_Pos 9UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BNAINTR_Msk 0x200UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_PKTDRPSTS_Pos 11UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_PKTDRPSTS_Msk 0x800UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BBLEERR_Pos 12UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_BBLEERR_Msk 0x1000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_NAKINTRPT_Pos 13UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_NAKINTRPT_Msk 0x2000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_NYETINTRPT_Pos 14UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_NYETINTRPT_Msk 0x4000UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_STUPPKTRCVD_Pos 15UL
#define USBHS_DWC_OTG_INTREG_DOEPINT8_STUPPKTRCVD_Msk 0x8000UL
/* USBHS_DWC_OTG_INTREG.DOEPTSIZ8 */
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_XFERSIZE_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_XFERSIZE_Msk 0x7FFFFUL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_PKTCNT_Pos 19UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_PKTCNT_Msk 0x1FF80000UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_RXDPID_Pos 29UL
#define USBHS_DWC_OTG_INTREG_DOEPTSIZ8_RXDPID_Msk 0x60000000UL
/* USBHS_DWC_OTG_INTREG.DOEPDMA8 */
#define USBHS_DWC_OTG_INTREG_DOEPDMA8_DMAADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMA8_DMAADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.DOEPDMAB8 */
#define USBHS_DWC_OTG_INTREG_DOEPDMAB8_DMABUFFERADDR_Pos 0UL
#define USBHS_DWC_OTG_INTREG_DOEPDMAB8_DMABUFFERADDR_Msk 0xFFFFFFFFUL
/* USBHS_DWC_OTG_INTREG.PCGCCTL */
#define USBHS_DWC_OTG_INTREG_PCGCCTL_STOPPCLK_Pos 0UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_STOPPCLK_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_RSTPDWNMODULE_Pos 3UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_RSTPDWNMODULE_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_ENBL_L1GATING_Pos 5UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_ENBL_L1GATING_Msk 0x20UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_PHYSLEEP_Pos 6UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_PHYSLEEP_Msk 0x40UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_L1SUSPENDED_Pos 7UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL_L1SUSPENDED_Msk 0x80UL
/* USBHS_DWC_OTG_INTREG.PCGCCTL1 */
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_GATEEN_Pos 0UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_GATEEN_Msk 0x1UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_COUNTER_Pos 1UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_COUNTER_Msk 0x6UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_RAMGATEEN_Pos 3UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_RAMGATEEN_Msk 0x8UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_RESERVED_Pos 4UL
#define USBHS_DWC_OTG_INTREG_PCGCCTL1_RESERVED_Msk 0xFFFFFFF0UL


/* USBHS_SS.SUBSYSTEM_CTL */
#define USBHS_SS_SUBSYSTEM_CTL_SS_ENABLE_Pos    0UL
#define USBHS_SS_SUBSYSTEM_CTL_SS_ENABLE_Msk    0x1UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_MODE_Pos     1UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_MODE_Msk     0x2UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_PHY_POWER_DOWN_Pos 2UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_PHY_POWER_DOWN_Msk 0x4UL
#define USBHS_SS_SUBSYSTEM_CTL_AHB_MASTER_SYNC_Pos 3UL
#define USBHS_SS_SUBSYSTEM_CTL_AHB_MASTER_SYNC_Msk 0x8UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_CTRL_SCALEDOWN_MODE_Pos 4UL
#define USBHS_SS_SUBSYSTEM_CTL_USB_CTRL_SCALEDOWN_MODE_Msk 0x30UL
#define USBHS_SS_SUBSYSTEM_CTL_SS_FORCED_SHUTDOWN_Pos 6UL
#define USBHS_SS_SUBSYSTEM_CTL_SS_FORCED_SHUTDOWN_Msk 0x40UL
#define USBHS_SS_SUBSYSTEM_CTL_RSVD_1_Pos       7UL
#define USBHS_SS_SUBSYSTEM_CTL_RSVD_1_Msk       0xFFFFFF80UL
/* USBHS_SS.PHY_FUNC_CTL_1 */
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_B_TUNE_Pos  0UL
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_B_TUNE_Msk  0x1UL
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_FSEL_Pos    1UL
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_FSEL_Msk    0xEUL
#define USBHS_SS_PHY_FUNC_CTL_1_DISCONNECT_THRESHOLD_Pos 4UL
#define USBHS_SS_PHY_FUNC_CTL_1_DISCONNECT_THRESHOLD_Msk 0x70UL
#define USBHS_SS_PHY_FUNC_CTL_1_SQUELCH_THRESHOLD_Pos 7UL
#define USBHS_SS_PHY_FUNC_CTL_1_SQUELCH_THRESHOLD_Msk 0x380UL
#define USBHS_SS_PHY_FUNC_CTL_1_CHARGER_TYPE_DETECTION_Pos 10UL
#define USBHS_SS_PHY_FUNC_CTL_1_CHARGER_TYPE_DETECTION_Msk 0xC00UL
#define USBHS_SS_PHY_FUNC_CTL_1_TX_HS_CROSSOVER_Pos 12UL
#define USBHS_SS_PHY_FUNC_CTL_1_TX_HS_CROSSOVER_Msk 0x3000UL
#define USBHS_SS_PHY_FUNC_CTL_1_FS_LS_SOURCE_IMPEDANCE_Pos 14UL
#define USBHS_SS_PHY_FUNC_CTL_1_FS_LS_SOURCE_IMPEDANCE_Msk 0x3C000UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_DC_VOLTAGE_Pos 18UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_DC_VOLTAGE_Msk 0x3C0000UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_RISETUNE_Pos 22UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_RISETUNE_Msk 0xC00000UL
#define USBHS_SS_PHY_FUNC_CTL_1_USB_SOURCE_IMPEDANCE_Pos 24UL
#define USBHS_SS_PHY_FUNC_CTL_1_USB_SOURCE_IMPEDANCE_Msk 0x3000000UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_PRE_EMPHASIS_CURRENT_Pos 26UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_PRE_EMPHASIS_CURRENT_Msk 0xC000000UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_PRE_EMPHASIS_DURATION_Pos 28UL
#define USBHS_SS_PHY_FUNC_CTL_1_HS_TX_PRE_EMPHASIS_DURATION_Msk 0x10000000UL
#define USBHS_SS_PHY_FUNC_CTL_1_PORT_RESET_Pos  29UL
#define USBHS_SS_PHY_FUNC_CTL_1_PORT_RESET_Msk  0x20000000UL
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_I_TUNE_Pos  30UL
#define USBHS_SS_PHY_FUNC_CTL_1_PLL_I_TUNE_Msk  0xC0000000UL
/* USBHS_SS.PHY_FUNC_CTL_2 */
#define USBHS_SS_PHY_FUNC_CTL_2_PLL_P_TUNE_Pos  0UL
#define USBHS_SS_PHY_FUNC_CTL_2_PLL_P_TUNE_Msk  0xFUL
#define USBHS_SS_PHY_FUNC_CTL_2_OTG_TUNE_Pos    4UL
#define USBHS_SS_PHY_FUNC_CTL_2_OTG_TUNE_Msk    0x70UL
#define USBHS_SS_PHY_FUNC_CTL_2_RES_TUNING_CODE_Pos 7UL
#define USBHS_SS_PHY_FUNC_CTL_2_RES_TUNING_CODE_Msk 0x780UL
#define USBHS_SS_PHY_FUNC_CTL_2_RES_TUNING_SEL_Pos 11UL
#define USBHS_SS_PHY_FUNC_CTL_2_RES_TUNING_SEL_Msk 0x800UL
#define USBHS_SS_PHY_FUNC_CTL_2_EFUSE_SEL_Pos   12UL
#define USBHS_SS_PHY_FUNC_CTL_2_EFUSE_SEL_Msk   0x1000UL
#define USBHS_SS_PHY_FUNC_CTL_2_RSVD_2_Pos      13UL
#define USBHS_SS_PHY_FUNC_CTL_2_RSVD_2_Msk      0xFFFFE000UL
/* USBHS_SS.PHY_TEST_CTL */
#define USBHS_SS_PHY_TEST_CTL_TEST_PULSE_Pos    0UL
#define USBHS_SS_PHY_TEST_CTL_TEST_PULSE_Msk    0x1UL
#define USBHS_SS_PHY_TEST_CTL_TEST_DATAOUT_SEL0_Pos 1UL
#define USBHS_SS_PHY_TEST_CTL_TEST_DATAOUT_SEL0_Msk 0x2UL
#define USBHS_SS_PHY_TEST_CTL_TEST_DATAIN0_Pos  2UL
#define USBHS_SS_PHY_TEST_CTL_TEST_DATAIN0_Msk  0x3FCUL
#define USBHS_SS_PHY_TEST_CTL_TEST_ADDR0_Pos    10UL
#define USBHS_SS_PHY_TEST_CTL_TEST_ADDR0_Msk    0x3C00UL
#define USBHS_SS_PHY_TEST_CTL_TEST_BURNIN_Pos   14UL
#define USBHS_SS_PHY_TEST_CTL_TEST_BURNIN_Msk   0x4000UL
#define USBHS_SS_PHY_TEST_CTL_TEST_SCAN_EN_Pos  15UL
#define USBHS_SS_PHY_TEST_CTL_TEST_SCAN_EN_Msk  0x8000UL
#define USBHS_SS_PHY_TEST_CTL_TEST_IDDQ_EN_Pos  16UL
#define USBHS_SS_PHY_TEST_CTL_TEST_IDDQ_EN_Msk  0x10000UL
#define USBHS_SS_PHY_TEST_CTL_TEST_LOOPBACK_EN_Pos 17UL
#define USBHS_SS_PHY_TEST_CTL_TEST_LOOPBACK_EN_Msk 0x20000UL
#define USBHS_SS_PHY_TEST_CTL_TEST_ANALOGPIN_SEL_Pos 18UL
#define USBHS_SS_PHY_TEST_CTL_TEST_ANALOGPIN_SEL_Msk 0xC0000UL
#define USBHS_SS_PHY_TEST_CTL_TEST_ATERESET_Pos 20UL
#define USBHS_SS_PHY_TEST_CTL_TEST_ATERESET_Msk 0x100000UL
#define USBHS_SS_PHY_TEST_CTL_RSVD_3_Pos        21UL
#define USBHS_SS_PHY_TEST_CTL_RSVD_3_Msk        0xFFE00000UL
/* USBHS_SS.CONTROLLER_DDFT_CTL */
#define USBHS_SS_CONTROLLER_DDFT_CTL_DEBUG_HCLK_PROBES_COUNT_Pos 0UL
#define USBHS_SS_CONTROLLER_DDFT_CTL_DEBUG_HCLK_PROBES_COUNT_Msk 0x3FUL
#define USBHS_SS_CONTROLLER_DDFT_CTL_DEBUG_PCLK_PROBES_COUNT_Pos 6UL
#define USBHS_SS_CONTROLLER_DDFT_CTL_DEBUG_PCLK_PROBES_COUNT_Msk 0x3FC0UL
#define USBHS_SS_CONTROLLER_DDFT_CTL_RSVD_4_Pos 14UL
#define USBHS_SS_CONTROLLER_DDFT_CTL_RSVD_4_Msk 0xFFFFC000UL
/* USBHS_SS.INTR_SS */
#define USBHS_SS_INTR_SS_QCH_HCLK_GATED_Pos     0UL
#define USBHS_SS_INTR_SS_QCH_HCLK_GATED_Msk     0x1UL
#define USBHS_SS_INTR_SS_QCH_REQ_ERR_Pos        1UL
#define USBHS_SS_INTR_SS_QCH_REQ_ERR_Msk        0x2UL
/* USBHS_SS.INTR_SS_SET */
#define USBHS_SS_INTR_SS_SET_QCH_HCLK_GATED_Pos 0UL
#define USBHS_SS_INTR_SS_SET_QCH_HCLK_GATED_Msk 0x1UL
#define USBHS_SS_INTR_SS_SET_QCH_REQ_ERR_Pos    1UL
#define USBHS_SS_INTR_SS_SET_QCH_REQ_ERR_Msk    0x2UL
/* USBHS_SS.INTR_SS_MASK */
#define USBHS_SS_INTR_SS_MASK_QCH_HCLK_GATED_Pos 0UL
#define USBHS_SS_INTR_SS_MASK_QCH_HCLK_GATED_Msk 0x1UL
#define USBHS_SS_INTR_SS_MASK_QCH_REQ_ERR_Pos   1UL
#define USBHS_SS_INTR_SS_MASK_QCH_REQ_ERR_Msk   0x2UL
/* USBHS_SS.INTR_SS_MASKED */
#define USBHS_SS_INTR_SS_MASKED_QCH_HCLK_GATED_Pos 0UL
#define USBHS_SS_INTR_SS_MASKED_QCH_HCLK_GATED_Msk 0x1UL
#define USBHS_SS_INTR_SS_MASKED_QCH_REQ_ERR_Pos 1UL
#define USBHS_SS_INTR_SS_MASKED_QCH_REQ_ERR_Msk 0x2UL


#endif /* _CYIP_USBHS_H_ */


/* [] END OF FILE */
