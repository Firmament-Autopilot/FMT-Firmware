/***************************************************************************//**
* \file cy_smif.h
* \version 2.130
*
* \brief
* Provides an API declaration of the Cypress SMIF driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2016-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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


/**
* \addtogroup group_smif
* \{
* The SPI-based communication interface to the external quad SPI (QSPI)
* high-speed memory devices.
*
* The functions and other declarations used in this driver are in cy_smif.h and
* cy_smif_memslot.h (if used). If you are using the ModusToolbox QSPI Configurator,
* also include cycfg_qspi_memslot.h.
*
* **SMIF: Serial Memory Interface**: This IP block implements an SPI-based
* communication interface for interfacing external memory devices to the MCU.
* The SMIF supports SPI, dual SPI (DSPI), quad SPI (QSPI), dual QSPI and octal SPI.
*
* Features
*   - Standard SPI Master interface
*   - Supports single/dual/quad/octal SPI memory devices
*   - Supports dual quad SPI mode
*   - Design-time configurable support for multiple (up to 4) external serial
*   memory devices
*   - eXecute-In-Place (XIP) operation mode for both read and write accesses
*   with 4KB XIP read cache and on-the-fly encryption and decryption
*   - Supports external serial memory initialization via
*   <a href="https://www.jedec.org/standards-documents/docs/jesd216b" target="_blank">
*   Serial Flash Discoverable Parameters (SFDP)</a> standard
*
* The primary usage model for the SMIF is that of an external memory interface.
* The SMIF is capable of interfacing with different types of memory, up to four
* types.
*
* \b SMIF driver is divided into three layers
*   - cy_smif.h API
*   - cy_smif_memslot.h API
*   - SMIF configuration structures
*
* The SMIF API is divided into the low-level functions and memory-slot functions. Use
* the low level API for the SMIF block initialization and for implementing a generic
* SPI communication interface using the SMIF block.
*
* The memory slot API has functions to implement the basic memory operations such as
* program, read, erase etc. These functions are implemented using the memory
* parameters in the memory device configuration data structure. The
* Cy_SMIF_MemInit() API initializes all the memory slots based on the settings
* in the array.
*
* \image html smif_3_0_p01_layers.png
*
* \note
* Above image is applicable only for SMIF v3 IP.
*
* \image html smif_1_0_p01_layers.png
*
* \note
* Above image is applicable only for SMIF v1 IP.
*
* The QSPI Configurator tool is a stand-alone application that is a part of ModusToolbox.
* It can be accessed within ModusToolbox via the Peripheral -> Serial Memory Interface ->
* External Tools -> Launch QSPI Configurator button, or from the
*  \<CY_TOOLS_PATHS\>/qspi-configurator directory.
*
* The tool generates *.c and *.h file with configuration structures. These configuration
* structures are input parameters for cy_smif_memslot API level.
*
* \warning The driver is not responsible for external memory persistence. You cannot edit
* a buffer during the Read/Write operations. If there is a memory error, the SMIF ip block
* can require a reset. To determine if this has happened, check the SMIF
* busy status using Cy_SMIF_BusyCheck() and implement a timeout. Reset the SMIF
* block by toggling CTL.ENABLED. Then reconfigure the SMIF block.
*
* For the Write operation, check that the SMIF driver has completed
* transferring by calling Cy_SMIF_BusyCheck(). Also, check that the memory is
* available with Cy_SMIF_MemIsBusy() before proceeding.
*
* Simple example of external flash memory programming using low level SMIF API.
* All steps mentioned in example below are incorporated in
* \ref Cy_SMIF_MemCmdWriteEnable(), \ref Cy_SMIF_MemCmdProgram(), and
* \ref Cy_SMIF_MemIsBusy() of the
* \ref group_smif_mem_slot_functions "memory slot level API".
* \warning Example is simplified, without checks of error conditions.
* \note Flash memories need erase operation before programming. Refer to
* external memory datasheet for specific memory commands.
*
* \snippet smif/snippet/main.c SMIF_API: Write example
*
* For the Read operation, before accessing the read buffer, check that it is ready
* by calling Cy_SMIF_GetTxFifoStatus().
*
* Simple example of external flash memory read using low level SMIF API. All
* steps mentioned in example below are incorporated in
* \ref Cy_SMIF_MemCmdRead() of the
* \ref group_smif_mem_slot_functions "memory slot level API".
* \warning Example is simplified, without checks of error conditions.
* \note Refer to external memory datasheet for specific memory commands.
*
* \snippet smif/snippet/main.c SMIF_API: Read example
*
* The user should invalidate the cache by calling Cy_SMIF_CacheInvalidate() when
* switching from the MMIO mode to XIP mode.
*
* \section group_smif_configuration Configuration Considerations
*
* PDL API has common parameters: base, context, config described in
* \ref page_getting_started_pdl_design "PDL Design" section.
*
* See the documentation for Cy_SMIF_Init() and Cy_SMIF_MemInit() for details
* on the required configuration structures and other initialization topics.
*
* The normal (MMIO) mode is used for implementing a generic SPI/DSPI/QSPI/dual
* QSPI/octal SPI communication interface using the SMIF block. This
* interface can be used to implement special commands like Program/Erase of
* flash, memory device configuration, sleep mode entry for memory devices or
* other special commands specific to the memory device. The transfer width
* (SPI/DSPI/QSPI/octal SPI) of a transmission is a parameter set for each
* transmit/receive operation. So these can be changed at run time.
*
* In a typical memory interface with flash memory, the SMIF is used in the
* memory mode when reading from the memory and it switches to the normal mode when
* writing to flash memory.
* A typical memory device has multiple types of commands.
*
* The SMIF interface can be used to transmit different types of commands. Each
* command has different phases: command, dummy cycles, and transmit and receive
* data which require separate APIs.
*
* \subsection group_smif_init SMIF Initialization
* Create interrupt function and allocate memory for SMIF context
* structure
* \snippet smif/snippet/main.c SMIF_INIT: context and interrupt
* SMIF driver initialization for low level API usage (cysmif.h)
* \snippet smif/snippet/main.c SMIF_INIT: low level
* Additional steps to initialize SMIF driver for memory slot level API usage
* (cy_smif_memslot.h).
* \snippet smif/snippet/main.c SMIF_INIT: memslot level
* \note Example does not include initialization of all needed configuration
* structures (\ref cy_stc_smif_mem_device_cfg_t, \ref cy_stc_smif_mem_cmd_t).
* SMIF/QSPI Configuration tool generates all configuration structures needed for
* memslot level API usage.
*
* \subsection group_smif_xip_init SMIF XIP Initialization
* The eXecute In Place (XIP) is a mode of operation where read or write commands
* to the memory device are directed through the SMIF without any use of API
* function calls. In this mode the SMIF block maps the AHB bus-accesses to
* external memory device addresses to make it behave similar to internal memory.
* This allows the CPU to execute code directly from external memory. This mode
* is not limited to code and is suitable also for data read and write accesses.
* The memory regions available for XIP addresses allocation are defined
* in a linker script file (.ld).
*
* With SMIF V3 IP (and above), MMIO mode transactions are also allowed when the device is set
* to XIP mode. However, only blocking SMIF API's are expected to be used for erase or
* program operations as external flash will be busy for such operation and may not be
* available for XIP at that moment. User can make use of \ref Cy_SMIF_MemRead,
* \ref Cy_SMIF_MemWrite, \ref Cy_SMIF_MemEraseSector API's which ensure that user gets
* control only after completing the requested operation.
* This will ensure the transaction is complete and then switch back to XIP.
* In case user wishes to make use of low level API's like \ref Cy_SMIF_TransmitCommand_Ext,
* \ref Cy_SMIF_TransmitData_Ext, \ref Cy_SMIF_SendDummyCycles_Ext user has to ensure the
* code is not running already from XIP location and complete the operation before switching
* back to XIP mode of execution. Also, user has to bound his complete SMIF operation using
* \ref Cy_SysLib_EnterCriticalSection and \ref Cy_SysLib_ExitCriticalSection so that there is
* no interruption for the operation due to any other interrupts.
*
* \snippet smif/snippet/main.c SMIF_INIT: XIP
* \note Example of input parameters initialization is in \ref group_smif_init
* section.
* \warning Functions that called from external memory should be declared with
* long call attribute.
*
* \subsection group_smif_xip_crypto SMIF XIP On-the-fly encryption
* In XIP mode, a cryptography component supports on-the-fly encryption for write data and
* on-the-fly decryption for read data. On-the-fly encryption/decryption in XIP mode can be
* enabled by setting the flags \ref CY_SMIF_FLAG_CRYPTO_ENABLE.
* Encryption  and  decryption  are  based  on  the  AES-128 forward block cipher: advanced
* encryption standard blockcipher with a 128-bit key. KEY[127:0] is a secret (private) key
* programmed into the CRYPTO_KEY3,...,CRYPTO_KEY0 registers using \ref Cy_SMIF_SetCryptoKey.
* These registers are software write-only. A software read returns 0. In the SMIF hardware,
* by applying AES-128 with KEY[127:0] on a plaintext PT[127:0], we get a ciphertext CT[127:0].
* In XIP mode, the XIP address is used as the plaintext PT[]. The resulting ciphertext CT[]
* is used on-the-fly and not software accessible. The XIP address is extended with the
* CRYPTO_INPUT3, ..., CRYPTO_INPUT0 registers. \ref Cy_SMIF_SetCryptoIV can be used to set
* initialization vector (96-bits).
* In XIP mode, the resulting ciphertext CT[] (of the encrypted address) is XORed with the memory
* transfers read data or write data. Note that the AES-128 block cipher is on the address of the
* data and not on the data itself.
*
* \image html smif_xip_mode_functionality.png
*
* \subsection group_smif_usage_rules Rules for SMIF Block Usage
* 1. All operations must use one or more dummy cycles between the Command
* and Address phase (when the MCU drives the data pins) and the device's
* Response phase (when the device drives the same data pins). Bus contention may
* occur if no (zero) dummy cycles are used.
* 2. Any transfer that does not allow dummy cycles (such as Register Status
* Reads) must use the single-bit transfer mode. In single-bit mode, the MCU
* drives the Command on the Data0 line and the device responds on the Data1
* line, so bus contention cannot occur.
*
* \section group_smif_more_information More Information
*
* More information regarding the Serial Memory Interface can be found in the component
* datasheet and the Technical Reference Manual (TRM).
*
* More information regarding the QSPI Configurator tool are in QSPI Configurator user guide.
*
* \defgroup group_smif_macros Macros
* \{
* \defgroup group_smif_macros_status Status Macros
* \defgroup group_smif_macros_cmd Command Macros
* \defgroup group_smif_macros_flags External Memory Flags
* \defgroup group_smif_macros_sfdp SFDP Macros
* \defgroup group_smif_macros_isr Interrupt Macros
* \}
* \defgroup group_smif_functions Functions
* \{
* \defgroup group_smif_low_level_functions Low Level Functions
* \{
* The SMIF interface can be used to transmit different types of commands.
* Each command has different phases: command, dummy cycles, and transmit and receive data which require separate APIs.
*
* During the time that Slave Select line is active (LOW) the clock signal (CLK) is toggled while command information is first
* transferred on the data (IO) signals from the master to the slave. The clock continues to toggle during any period required for
* information access in the slave. The clock continues to toggle during the transfer of read data from the slave to the master
* or write data from the master to the slave. When the master has transferred the desired amount of data, the master drives the
* Slave Select line inactive (HIGH).
* Basic flow for read/write commands using \ref Cy_SMIF_TransmitCommand, \ref Cy_SMIF_TransmitData, \ref Cy_SMIF_ReceiveData and
* \ref Cy_SMIF_SendDummyCycles with a Quad SPI interface.
*
*  \image html smif_1_0_p03_rw_cmd.png
*
* The sequence of the PDL functions required in a read or write transaction is:
* \ref Cy_SMIF_TransmitCommand() ->
* \ref Cy_SMIF_SendDummyCycles() ->
* \ref Cy_SMIF_ReceiveData() / \ref Cy_SMIF_TransmitData() ->
* \ref Cy_SMIF_BusyCheck().
* The address is sent as part of the Cy_SMIF_TransmitCommand() function.
* No separate function call is required.
*
* \}
* \defgroup group_smif_mem_slot_functions Memory Slot Functions
* \defgroup group_smif_functions_syspm_callback  Low Power Callback
* \}
* \defgroup group_smif_data_structures Data Structures
* \{
* \defgroup group_smif_data_structures_memslot SMIF Memory Description Structures
* General hierarchy of memory structures are:
*
* \image html smif_3_0_p02_memslot_stc.png
*
* \note
* Above image is applicable only for SMIF v3 IP.
*
* \image html smif_1_0_p02_memslot_stc.png
*
* \note
* Above image is applicable only for SMIF v1 IP.
*
* Top structure is \ref cy_stc_smif_block_config_t, which could have links up to
* 4 \ref cy_stc_smif_mem_config_t which describes each connected to the SMIF
* external memory.
* \}
* \defgroup group_smif_enums Enumerated Types
*/

#if !defined (CY_SMIF_H)
#define CY_SMIF_H

#include "cy_device.h"

#if defined (CY_IP_MXSMIF)

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_syspm.h"

#include "cy_pdl_srf.h"
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
#include "cy_pdl_srf_common.h"
#endif /* defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*            Constants
****************************************/

/**
* \addtogroup group_smif_macros
* \{
*/

/** The driver major version */
#define CY_SMIF_DRV_VERSION_MAJOR       2

/** The driver minor version */
#define CY_SMIF_DRV_VERSION_MINOR       130

/** One microsecond timeout for Cy_SMIF_TimeoutRun() */
#define CY_SMIF_WAIT_1_UNIT             (1U)

/** SMIF V6 internal CACHE line size */
#define CY_SMIF_CACHE_LINE_SIZE_IN_BYTES  (32U)

/** SMIF V6 internal CACHE SUB REGION size alignment */
#define CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES  (4096U)

/** The SMIF driver ID, reported as part of an unsuccessful API return status
 * \ref cy_en_smif_status_t */
#define CY_SMIF_ID                      CY_PDL_DRV_ID(0x2CUL)


/**
* \addtogroup group_smif_macros_isr
* \{
*/

/** Enable XIP_ALIGNMENT_ERROR interrupt see TRM for details */
#define CY_SMIF_ALIGNMENT_ERROR                 (SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk)
/** Enable RX_DATA_FIFO_UNDERFLOW interrupt see TRM for details */
#define CY_SMIF_RX_DATA_FIFO_UNDERFLOW          (SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Msk)
/** Enable TX_DATA_FIFO_OVERFLOW interrupt see TRM for details */
#define CY_SMIF_TX_DATA_FIFO_OVERFLOW           (SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk)
/** Enable TX_CMD_FIFO_OVERFLOW interrupt see TRM for details */
#define CY_SMIF_TX_COMMAND_FIFO_OVERFLOW        (SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk)
/** Enable TR_TX_REQ interrupt see TRM for details */
#define CY_SMIF_TX_DATA_FIFO_LEVEL_TRIGGER      (SMIF_INTR_TR_TX_REQ_Msk)
/** Enable TR_RX_REQ interrupt see TRM for details */
#define CY_SMIF_RX_DATA_FIFO_LEVEL_TRIGGER      (SMIF_INTR_TR_RX_REQ_Msk)

/** \} group_smif_macros_isr */

/** \cond INTERNAL */




#define CY_SMIF_CMD_FIFO_TX_MODE            (0UL)
#define CY_SMIF_CMD_FIFO_TX_COUNT_MODE      (1UL)
#define CY_SMIF_CMD_FIFO_RX_COUNT_MODE      (2UL)
#define CY_SMIF_CMD_FIFO_DUMMY_COUNT_MODE   (3UL)

#define CY_SMIF_TX_CMD_FIFO_STATUS_RANGE    (8U)

#define CY_SMIF_TX_DATA_FIFO_STATUS_RANGE   (8U)
#define CY_SMIF_RX_DATA_FIFO_STATUS_RANGE   (8U)

#define CY_SMIF_ONE_BYTE                    (1U)
#define CY_SMIF_TWO_BYTES                   (2U)
#define CY_SMIF_THREE_BYTES                 (3U)
#define CY_SMIF_FOUR_BYTES                  (4U)
#define CY_SMIF_FIVE_BYTES                  (5U)
#define CY_SMIF_SIX_BYTES                   (6U)
#define CY_SMIF_SEVEN_BYTES                 (7U)
#define CY_SMIF_EIGHT_BYTES                 (8U)

#define CY_SMIF_CRYPTO_FIRST_WORD           (0U)
#define CY_SMIF_CRYPTO_SECOND_WORD          (4U)
#define CY_SMIF_CRYPTO_THIRD_WORD           (8U)
#define CY_SMIF_CRYPTO_FOURTH_WORD          (12U)

#define CY_SMIF_CRYPTO_START                (1UL)
#define CY_SMIF_CRYPTO_COMPLETED            (0UL)
#define CY_SMIF_CRYPTO_ADDR_MASK            (0xFFFFFFF0UL)
#define CY_SMIF_AES128_BYTES                (16U)

#define CY_SMIF_CTL_REG_DEFAULT             (0x00000300U) /* 3 - [13:12] CLOCK_IF_RX_SEL  */
#define CY_SMIF_CTL2_REG_DEFAULT            (0x0080D000U)

#define CY_SMIF_SFDP_FAIL                   (0x08U)
#define CY_SMIF_SFDP_FAIL_SS0_POS           (0x00U)
#define CY_SMIF_SFDP_FAIL_SS1_POS           (0x01U)
#define CY_SMIF_SFDP_FAIL_SS2_POS           (0x02U)
#define CY_SMIF_SFDP_FAIL_SS3_POS           (0x03U)

#define CY_SMIF_MAX_DESELECT_DELAY          (7U)
#define CY_SMIF_MAX_TX_TR_LEVEL             (8U)
#define CY_SMIF_MAX_RX_TR_LEVEL             (8U)

#define CY_SMIF_MODE_VALID(mode)            ((CY_SMIF_NORMAL == (cy_en_smif_mode_t)(mode)) || \
                                             (CY_SMIF_MEMORY == (cy_en_smif_mode_t)(mode)))
#define CY_SMIF_BLOCK_EVENT_VALID(event)    ((CY_SMIF_BUS_ERROR == (cy_en_smif_error_event_t)(event)) || \
                                             (CY_SMIF_WAIT_STATES == (cy_en_smif_error_event_t)(event)))
#define CY_SMIF_CLOCK_SEL_VALID(clkSel)     ((CY_SMIF_SEL_OUTPUT_CLK == (cy_en_smif_clk_select_t)(clkSel)) || \
                                             (CY_SMIF_SEL_INVERTED_OUTPUT_CLK == (cy_en_smif_clk_select_t)(clkSel)) || \
                                             (CY_SMIF_SEL_INTERNAL_CLK == (cy_en_smif_clk_select_t)(clkSel)) || \
                                             (CY_SMIF_SEL_INVERTED_INTERNAL_CLK == (cy_en_smif_clk_select_t)(clkSel)) || \
                                             (CY_SMIF_SEL_FEEDBACK_CLK == (cy_en_smif_clk_select_t)(clkSel)) || \
                                             (CY_SMIF_SEL_INVERTED_FEEDBACK_CLK == (cy_en_smif_clk_select_t)(clkSel)) ||\
                                             (CY_SMIF_SEL_INVERTED_SPHB_RWDS_CLK == (cy_en_smif_clk_select_t)(clkSel))  || \
                                             (CY_SMIF_SEL_SPHB_RWDS_CLK == (cy_en_smif_clk_select_t)(clkSel)))

#define CY_SMIF_DESELECT_DELAY_VALID(delay) ((delay) <= CY_SMIF_MAX_DESELECT_DELAY)
/** Maximum number of devices that can be connected to a SMIF instance */
#define CY_SMIF_MAX_MEMNUM                  (4U)
/** Macro to check that a memory number is valid */
#define CY_SMIF_MEM_NUM_VALID(memNum)       (memNum < CY_SMIF_MAX_MEMNUM)
#define CY_SMIF_SLAVE_SEL_VALID(ss)         ((CY_SMIF_SLAVE_SELECT_0 == (ss)) || \
                                             (CY_SMIF_SLAVE_SELECT_1 == (ss)) || \
                                             (CY_SMIF_SLAVE_SELECT_2 == (ss)) || \
                                             (CY_SMIF_SLAVE_SELECT_3 == (ss)) || \
                                             ((CY_SMIF_SLAVE_SELECT_0 | CY_SMIF_SLAVE_SELECT_1) == (ss)))
#define CY_SMIF_DATA_SEL_VALID(ss)          ((CY_SMIF_DATA_SEL0 == (ss)) || \
                                             (CY_SMIF_DATA_SEL1 == (ss)) || \
                                             (CY_SMIF_DATA_SEL2 == (ss)) || \
                                             (CY_SMIF_DATA_SEL3 == (ss)))
#define CY_SMIF_TXFR_WIDTH_VALID(width)     ((CY_SMIF_WIDTH_SINGLE == (width)) || \
                                             (CY_SMIF_WIDTH_DUAL == (width))   || \
                                             (CY_SMIF_WIDTH_QUAD == (width))   || \
                                             (CY_SMIF_WIDTH_OCTAL == (width))  || \
                                             (CY_SMIF_WIDTH_NA == (width)))
#define CY_SMIF_CMD_PARAM_VALID(param, paramSize)  (((paramSize) > 0U)? (NULL != (param)) : (true))

#define CY_SMIF_WIDTH_NA_VALID(paramWidth, paramSize)   (((paramSize) > 0U)? \
                                                         (CY_SMIF_WIDTH_NA != (paramWidth)) : (true))
#define CY_SMIF_CMD_DATA_RATE_VALID(rate)   ((CY_SMIF_SDR == (rate)) || \
                                             (CY_SMIF_DDR == (rate)))
#define CY_SMIF_CMD_PARAM_DATA_RATE_VALID(rate)   ((CY_SMIF_SDR == (rate)) || \
                                                    (CY_SMIF_DDR == (rate)))
#define CY_SMIF_DATA_DATA_RATE_VALID(rate)   ((CY_SMIF_SDR == (rate)) || \
                                               (CY_SMIF_DDR == (rate)))

#define CY_SMIF_BUFFER_SIZE_MAX             (65536UL)
#define CY_SMIF_BUF_SIZE_VALID(size)        (((CY_SMIF_BUFFER_SIZE_MAX) >= (size)) && ((0UL) < (size)))

/***************************************
*        Command FIFO Register
***************************************/

/* SMIF->TX_CMD_FIFO_MMIO_WR Commands Fields */
#define CY_SMIF_CMD_MMIO_FIFO_WR_MODE_Pos            (24UL)           /* [26:24]         Command data mode */
#define CY_SMIF_CMD_MMIO_FIFO_WR_MODE_Msk            (0x07000000UL)   /* DATA[26:24]       Command data mode    */

#define CY_SMIF_CMD_MMIO_FIFO_WR_SS_Pos              (20UL)           /* [23:20]         Slave select         */
#define CY_SMIF_CMD_MMIO_FIFO_WR_SS_Msk              (0x00F00000UL)   /* DATA[23:20]     Slave select         */

#define CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE_Pos       (19UL)           /* [19]            Last byte            */
#define CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE_Msk       (0x00080000UL)   /* DATA[19]        Last byte               */

#define CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE_Pos       (18UL)           /* [18]         Data Rate         */
#define CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE_Msk       (0x00040000UL)   /* DATA[18]     Data Rate         */

#define CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH_Pos           (16UL)           /* [17:16]         Transfer width       */
#define CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH_Msk           (0x00030000UL)   /* DATA[17:16]     Transfer width  */

#define CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2_Pos   (8UL)            /* [15:8] */
#define CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2_Msk   (0x0000FF00UL)   /* DATA[15:8] second byte */

#define CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1_Pos   (0UL)            /* [7:0]         first byte         */
#define CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1_Msk   (0x000000FFUL)   /* DATA[7:0]     first byte         */

#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_Pos           (0UL)            /* [0]             Dummy count          */
#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_Msk           (0x0000FFFFUL)   /* DATA[15:0]      Dummy count          */

#define CY_SMIF_CMD_MMIO_FIFO_WR_TX_COUNT_Msk        (0x0000FFFFUL)   /* DATA[15:0]      TX count             */
#define CY_SMIF_CMD_MMIO_FIFO_WR_TX_COUNT_Pos        (0UL)            /* [0]             TX count             */

#define CY_SMIF_CMD_MMIO_FIFO_WR_RX_COUNT_Msk        (0x0000FFFFUL)   /* DATA[15:0]      RX count             */
#define CY_SMIF_CMD_MMIO_FIFO_WR_RX_COUNT_Pos        (0UL)            /* [0]             RX count             */

#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_READ_RWDS_Msk (0x00800000UL)   /* DATA[23]     Read with RWDS             */
#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_READ_RWDS_Pos (23UL)            /* [23]        Read with RWDS             */

#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_WRITE_RWDS_Msk (0x00200000UL)   /* DATA[21]     Write with RWDS             */
#define CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_WRITE_RWDS_Pos (21UL)            /* [21]            Dummy RWDS             */

#define CY_SMIF_CMD_MMIO_FIFO_WR_RWDS_REFRESH_Msk      (0x00100000UL)   /* DATA[20]     RWDS Refresh indicator   */
#define CY_SMIF_CMD_MMIO_FIFO_WR_RWDS_REFRESH_Pos      (20UL)            /* [20]        RWDS Refresh indicator   */


/** \endcond */
/** \} group_smif_macros */


/**
* \addtogroup group_smif_enums
* \{
*/

/** The Transfer width options for the command, data, the address and the mode. */
typedef enum
{
    CY_SMIF_WIDTH_SINGLE   = 0U,    /**< Single SPI mode. */
    CY_SMIF_WIDTH_DUAL     = 1U,    /**< Dual SPI mode. */
    CY_SMIF_WIDTH_QUAD     = 2U,    /**< Quad SPI mode. */
    CY_SMIF_WIDTH_OCTAL    = 3U,    /**< Octal SPI mode. */
    CY_SMIF_WIDTH_NA       = 0xFFU  /**< The specific width parameter is not applicable for this memory command. */
} cy_en_smif_txfr_width_t;

/** The SMIF error-event selection. */
typedef enum
{
    /**< Generates a bus error. */
    CY_SMIF_BUS_ERROR           = 0UL,
    /** Stalls the bus with the wait states. This option will increase the
     * interrupt latency.
     */
    CY_SMIF_WAIT_STATES         = 1UL
} cy_en_smif_error_event_t;

/** Specifies the delay line used for RX data capturing with  */
typedef enum
{
    CY_SMIF_1_NEW_SEL_PER_TAP  = 0, /**< 1 of these new delay cells per tap providing:
    granularity  of  max.  ~0.22ns */
    CY_SMIF_1_SEL_PER_TAP  = 1, /**< 1 cell per tap providing:
    granularity of max. ~0.4ns */
    CY_SMIF_2_SEL_PER_TAP  = 2, /**< 2 cells per tap providing:
    granularity of max. ~0.8ns */
    CY_SMIF_4_SEL_PER_TAP  = 3, /**< 4 cells per tap providing:
    granularity of max. ~1.6ns */
    CY_SMIF_NO_DELAY_SEL       = 0xFF,/**< No delay line (disabled) */
} cy_en_smif_delay_line_t;

/** The data line-selection options for a slave device. */
typedef enum
{
    /**
    * smif.spi_data[0] = DATA0, smif.spi_data[1] = DATA1, ..., smif.spi_data[7] = DATA7.
    * This value is allowed for the SPI, DSPI, QSPI, dual QSPI, and octal SPI modes.
    */
    CY_SMIF_DATA_SEL0      = 0,
    /**
    * smif.spi_data[2] = DATA0, smif.spi_data[3] = DATA1.
    * This value is only allowed for the SPI and DSPI modes.
    */
    CY_SMIF_DATA_SEL1      = 1,
    /**
    * smif.spi_data[4] = DATA0, smif.spi_data[5] = DATA1, ..., smif.spi_data[7] = DATA3.
    * This value is only allowed for the SPI, DSPI, QSPI and dual QSPI modes.
    */
    CY_SMIF_DATA_SEL2      = 2,
    /**
    * smif.spi_data[6] = DATA0, smif.spi_data[7] = DATA1.
    * This value is only allowed for the SPI and DSPI modes.
    */
    CY_SMIF_DATA_SEL3      = 3
} cy_en_smif_data_select_t;

/** The SMIF modes to work with an external memory. */
typedef enum
{
    CY_SMIF_NORMAL,         /**< Command mode (MMIO mode). */
    CY_SMIF_MEMORY          /**< XIP (eXecute In Place) mode. */
} cy_en_smif_mode_t;

typedef enum
{
    CY_SMIF_DLL_DIVIDE_BY_2  = 0,    /**< Divides DLL Clock by 2 */
    CY_SMIF_DLL_DIVIDE_BY_4  = 1,    /**< Divides DLL Clock by 4 */
    CY_SMIF_DLL_DIVIDE_BY_8  = 2,    /**< Divides DLL Clock by 8 */
    CY_SMIF_DLL_DIVIDE_BY_16 = 3,    /**< Divides DLL Clock by 16 */
} cy_en_smif_dll_divider_t;

/* This field is only applicable in SDR transmit mode. */
typedef enum
{
    CY_SMIF_TX_ONE_PERIOD_AHEAD = 0, /**< transmit data is launched nominally 1 PLL clock period ahead of the rising edge of the clock out to the memory */
    CY_SMIF_TX_TWO_PERIOD_AHEAD = 1, /**< transmit data is launched nominally 2 PLL clock periods ahead of the rising edge of the clock out to the memory */
} cy_en_smif_tx_sdr_extra_t;

/* Determines the relative amount of delay through the MDL in terms of the number of tap delays. */
typedef enum
{
    CY_SMIF_MDL_1_TAP_DELAY  = 0, /**< 1 tap delay */
    CY_SMIF_MDL_2_TAP_DELAY  = 1, /**< 2 tap delay */
    CY_SMIF_MDL_3_TAP_DELAY  = 2, /**< 3 tap delay */
    CY_SMIF_MDL_4_TAP_DELAY  = 3, /**< 4 tap delay */
    CY_SMIF_MDL_5_TAP_DELAY  = 4, /**< 5 tap delay */
    CY_SMIF_MDL_6_TAP_DELAY  = 5, /**< 6 tap delay */
    CY_SMIF_MDL_7_TAP_DELAY  = 6, /**< 7 tap delay */
    CY_SMIF_MDL_8_TAP_DELAY  = 7, /**< 8 tap delay */
    CY_SMIF_MDL_9_TAP_DELAY  = 8, /**< 9 tap delay */
    CY_SMIF_MDL_10_TAP_DELAY  = 9, /**< 10 tap delay */
    CY_SMIF_MDL_11_TAP_DELAY  = 10, /**< 11 tap delay */
    CY_SMIF_MDL_12_TAP_DELAY  = 11, /**< 12 tap delay */
    CY_SMIF_MDL_13_TAP_DELAY  = 12, /**< 13 tap delay */
    CY_SMIF_MDL_14_TAP_DELAY  = 13, /**< 14 tap delay */
    CY_SMIF_MDL_15_TAP_DELAY  = 14, /**< 15 tap delay */
    CY_SMIF_MDL_16_TAP_DELAY  = 15, /**< 16 tap delay */
    CY_SMIF_MDL_TAP_NUMBER  = 16, /**< Tap Count */
} cy_en_cy_smif_mdl_tap_sel_t;

/* Determines the relative amount of delay through the SDL (including neg and pos) in terms of the number of tap delays. */
typedef enum
{
    CY_SMIF_SDL_1_TAP_DELAY  = 0, /**< 1 tap delay */
    CY_SMIF_SDL_2_TAP_DELAY  = 1, /**< 2 tap delay */
    CY_SMIF_SDL_3_TAP_DELAY  = 2, /**< 3 tap delay */
    CY_SMIF_SDL_4_TAP_DELAY  = 3, /**< 4 tap delay */
    CY_SMIF_SDL_5_TAP_DELAY  = 4, /**< 5 tap delay */
    CY_SMIF_SDL_6_TAP_DELAY  = 5, /**< 6 tap delay */
    CY_SMIF_SDL_7_TAP_DELAY  = 6, /**< 7 tap delay */
    CY_SMIF_SDL_8_TAP_DELAY  = 7, /**< 8 tap delay */
    CY_SMIF_SDL_9_TAP_DELAY  = 8, /**< 9 tap delay */
    CY_SMIF_SDL_10_TAP_DELAY  = 9, /**< 10 tap delay */
    CY_SMIF_SDL_11_TAP_DELAY  = 10, /**< 11 tap delay */
    CY_SMIF_SDL_12_TAP_DELAY  = 11, /**< 12 tap delay */
    CY_SMIF_SDL_13_TAP_DELAY  = 12, /**< 13 tap delay */
    CY_SMIF_SDL_14_TAP_DELAY  = 13, /**< 14 tap delay */
    CY_SMIF_SDL_15_TAP_DELAY  = 14, /**< 15 tap delay */
    CY_SMIF_SDL_16_TAP_DELAY  = 15, /**< 16 tap delay */
    CY_SMIF_SDL_TAP_NUMBER  = 16, /**< Tap Count */
} cy_en_cy_smif_sdl_tap_sel_t;

/* Determines the relative amount of delay through the MDL/SDL(including neg and pos) for the reference clock in terms of the number of tap delays. */
typedef enum
{
    CY_SMIF_DDL_1_TAP_DELAY  = 0, /**< 1 tap delay */
    CY_SMIF_DDL_2_TAP_DELAY  = 1, /**< 2 tap delay */
    CY_SMIF_DDL_3_TAP_DELAY  = 2, /**< 3 tap delay */
    CY_SMIF_DDL_4_TAP_DELAY  = 3, /**< 4 tap delay */
    CY_SMIF_DDL_5_TAP_DELAY  = 4, /**< 5 tap delay */
    CY_SMIF_DDL_6_TAP_DELAY  = 5, /**< 6 tap delay */
    CY_SMIF_DDL_7_TAP_DELAY  = 6, /**< 7 tap delay */
    CY_SMIF_DDL_8_TAP_DELAY  = 7, /**< 8 tap delay */
    CY_SMIF_DDL_9_TAP_DELAY  = 8, /**< 9 tap delay */
    CY_SMIF_DDL_10_TAP_DELAY  = 9, /**< 10 tap delay */
    CY_SMIF_DDL_11_TAP_DELAY  = 10, /**< 11 tap delay */
    CY_SMIF_DDL_12_TAP_DELAY  = 11, /**< 12 tap delay */
    CY_SMIF_DDL_13_TAP_DELAY  = 12, /**< 13 tap delay */
    CY_SMIF_DDL_14_TAP_DELAY  = 13, /**< 14 tap delay */
    CY_SMIF_DDL_15_TAP_DELAY  = 14, /**< 15 tap delay */
    CY_SMIF_DDL_16_TAP_DELAY  = 15, /**< 16 tap delay */
    CY_SMIF_DDL_TAP_NUMBER  = 16, /**< Tap Count */
} cy_en_cy_smif_ddl_tap_sel_t;

#define CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MIN_SDR  (CY_SMIF_MDL_3_TAP_DELAY)   /* In SDR mode, when CLKOUT is not divide by two, this is the minimum acceptable MDL tap */
#define CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MAX_SDR  (CY_SMIF_MDL_13_TAP_DELAY)  /* In SDR mode, when CLKOUT is not divide by two, this is the maximum acceptable MDL tap */
#define CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MIN_DDR  (CY_SMIF_MDL_3_TAP_DELAY)   /* In DDR mode, when CLKOUT is not divide by two, this is the minimum acceptable MDL tap */
#define CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MAX_DDR  (CY_SMIF_MDL_14_TAP_DELAY)  /* In DDR mode, when CLKOUT is not divide by two, this is the maximum acceptable MDL tap */

typedef enum
{
    CY_SMIF_DELAY_TAP_DISABLE = 0,    /**< The SMIF Delay tap disable */
    CY_SMIF_DELAY_TAP_ENABLE = 1,    /**< The SMIF Delay tap enable */
} cy_en_smif_delay_tap_t;

/** The SMIF transfer status return values. */
typedef enum
{
    CY_SMIF_STARTED,       /**< The SMIF started. */
    CY_SMIF_SEND_COMPLETE, /**< The data transmission is complete. */
    CY_SMIF_SEND_BUSY,     /**< The data transmission is in progress. */
    CY_SMIF_RX_COMPLETE,   /**< The data reception is completed. */
    CY_SMIF_RX_BUSY,       /**< The data reception is in progress. */
    CY_SMIF_XIP_ERROR,     /**< An XIP alignment error. */
    CY_SMIF_CMD_ERROR,     /**< A TX CMD FIFO overflow. */
    CY_SMIF_TX_ERROR,      /**< A TX DATA FIFO overflow. */
    CY_SMIF_RX_ERROR       /**< An RX DATA FIFO underflow. */

} cy_en_smif_txfr_status_t;

/** The SMIF API return values. */
typedef enum
{
    CY_SMIF_SUCCESS = 0x00U,           /**< Successful SMIF operation. */
    CY_SMIF_CMD_FIFO_FULL   = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x01U,     /**< The command is cancelled. The command FIFO is full. */
    CY_SMIF_EXCEED_TIMEOUT  = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x02U,    /**< The SMIF operation timeout exceeded. */
    /**
    * The device does not have a QE bit. The device detects
    * 1-1-4 and 1-4-4 Reads based on the instruction.
    */
    CY_SMIF_NO_QE_BIT       = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x03U,
    CY_SMIF_BAD_PARAM       = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x04U,   /**< The SMIF API received the wrong parameter */
    CY_SMIF_NO_SFDP_SUPPORT = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x05U,   /**< The external memory does not support SFDP (JESD216B). */
    CY_SMIF_NOT_HYBRID_MEM  = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x06U,   /**< The external memory is not hybrid */
    CY_SMIF_SFDP_CORRUPTED_TABLE = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x07U, /**< The SFDP table is corrupted */
    /** Failed to initialize the slave select 0 external memory by auto detection (SFDP). */
    CY_SMIF_SFDP_SS0_FAILED = CY_SMIF_ID |CY_PDL_STATUS_ERROR |
                            ((uint32_t)CY_SMIF_SFDP_FAIL << CY_SMIF_SFDP_FAIL_SS0_POS),
    /** Failed to initialize the slave select 1 external memory by auto detection (SFDP). */
    CY_SMIF_SFDP_SS1_FAILED = CY_SMIF_ID | CY_PDL_STATUS_ERROR |
                            ((uint32_t)CY_SMIF_SFDP_FAIL << CY_SMIF_SFDP_FAIL_SS1_POS),
    /** Failed to initialize the slave select 2 external memory by auto detection (SFDP). */
    CY_SMIF_SFDP_SS2_FAILED = CY_SMIF_ID |CY_PDL_STATUS_ERROR |
                            ((uint32_t)CY_SMIF_SFDP_FAIL << CY_SMIF_SFDP_FAIL_SS2_POS),
    /** Failed to initialize the slave select 3 external memory by auto detection (SFDP). */
    CY_SMIF_SFDP_SS3_FAILED = CY_SMIF_ID |CY_PDL_STATUS_ERROR |
                            ((uint32_t)CY_SMIF_SFDP_FAIL << CY_SMIF_SFDP_FAIL_SS3_POS),
    /** The command API is not supported for this memory device. */
    CY_SMIF_CMD_NOT_FOUND = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x80U,
    /** SFDP Buffer Insufficient. */
    CY_SMIF_SFDP_BUFFER_INSUFFICIENT = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x81U,
    /**
    * The device does not have a OE bit. The device detects
    * 1-1-8 and 1-8-8 Reads based on the instruction.
    */
    CY_SMIF_NO_OE_BIT       = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x82U,
    /** SMIF is currently busy and cannot accept the request */
    CY_SMIF_BUSY            = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x83U,
    CY_SMIF_GENERAL_ERROR   = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x84U,  /**< Some general error */
    CY_SMIF_SECURITY_POLICY_VIOLATION = CY_SMIF_ID |CY_PDL_STATUS_ERROR | 0x90U,
} cy_en_smif_status_t;

/** The SMIF slave select definitions for the driver API. Each slave select is
 * represented by an enumeration that has the bit corresponding to the slave
 * select number set. */
typedef enum
{
   CY_SMIF_SLAVE_SELECT_0 = 1U,  /**< The SMIF slave select 0  */
   CY_SMIF_SLAVE_SELECT_1 = 2U,  /**< The SMIF slave select 1  */
   CY_SMIF_SLAVE_SELECT_2 = 4U,  /**< The SMIF slave select 2  */
   CY_SMIF_SLAVE_SELECT_3 = 8U   /**< The SMIF slave select 3  */
} cy_en_smif_slave_select_t;

/** Specifies receive capture mode. */
typedef enum
{
    CY_SMIF_SEL_NORMAL_SPI = 0U,                   /**< Normal SPI without DLP. */
    CY_SMIF_SEL_NORMAL_SPI_WITH_DLP = 1U,          /**< Normal SPI with DLP (Data Learning Pattern). */
    CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS = 2U,       /**< xSPI or HYPER BUS with Data strobe line. */
} cy_en_smif_capture_mode_t;

/** Specifies the clock source for the receiver clock. */
typedef enum
{
   CY_SMIF_SEL_OUTPUT_CLK   = 0U,  /**< The SMIF output clock */
   CY_SMIF_SEL_INVERTED_OUTPUT_CLK   = 1U,  /**< The SMIF inverted output clock */
   CY_SMIF_SEL_FEEDBACK_CLK     = 2U,  /**< The SMIF feedback clock */
   CY_SMIF_SEL_INVERTED_FEEDBACK_CLK = 3U,   /**< The SMIF feedback inverted clock */
   CY_SMIF_SEL_INTERNAL_CLK     = 4U,  /**< The SMIF internal clock */
   CY_SMIF_SEL_INVERTED_INTERNAL_CLK = 5U,  /**< The SMIF internal inverted clock */
   CY_SMIF_SEL_INVERTED_SPHB_RWDS_CLK = 6U,  /**< The SMIF internal inverted clock */
   CY_SMIF_SEL_SPHB_RWDS_CLK = 7U,  /**< The SMIF internal inverted clock */
} cy_en_smif_clk_select_t;


/** Specifies enabled type of SMIF cache. */
typedef enum
{
    CY_SMIF_CACHE_SLOW      = 1U,   /**< The SMIF slow cache (in the clk_slow domain) see TRM for details */
    CY_SMIF_CACHE_FAST      = 2U,   /**< The SMIF fast cache  (in the clk_fast domain) see TRM for details */
    CY_SMIF_CACHE_BOTH      = 3U    /**< The SMIF both caches */
} cy_en_smif_cache_t;

/** Specifies the quad enable requirement case.
 * JEDEC Basic Flash Parameter Table: 15th DWORD
**/
typedef enum
{
    CY_SMIF_SFDP_QER_0   = 0, /**< No QE Bit */
    CY_SMIF_SFDP_QER_1   = 1, /**< Bit 1 of Status Register 2 - Write uses 2 bytes using 01h */
    CY_SMIF_SFDP_QER_2   = 2, /**< Bit 6 of Status Register 1 - Write uses 1 byte */
    CY_SMIF_SFDP_QER_3   = 3, /**< Bit 7 of Status Register 2- Write uses 1 byte */
    CY_SMIF_SFDP_QER_4   = 4, /**< Bit 1 of Status Register 2 - Write uses 1 or 2 bytes */
    CY_SMIF_SFDP_QER_5   = 5, /**< Bit 1 of Status Register 2 - Write status uses 01h */
    CY_SMIF_SFDP_QER_6   = 6, /**< Bit 1 of Status Register 2 - Write uses 1 byte using 31h */
} cy_en_smif_qer_t;

/** Specifies the memory interface frequency range of operation.
**/
typedef enum
{
    CY_SMIF_100MHZ_OPERATION   = 0, /**< 100 MHz default operation */
    CY_SMIF_133MHZ_OPERATION   = 1, /**< 133 MHz operation */
    CY_SMIF_166MHZ_OPERATION   = 2, /**< 166 MHz operation */
    CY_SMIF_200MHZ_OPERATION   = 3, /**< 200 MHz operation */
} cy_en_smif_interface_freq_t;

/** Specifies the data rate. */
typedef enum
{
    CY_SMIF_SDR = 0,    /**< The SMIF Single Data Rate (SDR) */
    CY_SMIF_DDR = 1,    /**< The SMIF Double Data Rate (DDR) */
} cy_en_smif_data_rate_t;

/** Specifies the presence of the field. */
typedef enum
{
    CY_SMIF_NOT_PRESENT   = 0,
    CY_SMIF_PRESENT_1BYTE = 1,
    CY_SMIF_PRESENT_2BYTE = 2,
} cy_en_smif_field_presence_t;

/** Specifies the merge transaction timeout in terms of clock cycles. */
typedef enum
{
    CY_SMIF_MERGE_TIMEOUT_1_CYCLE      = 0,
    CY_SMIF_MERGE_TIMEOUT_16_CYCLES    = 1,
    CY_SMIF_MERGE_TIMEOUT_256_CYCLES   = 2,
    CY_SMIF_MERGE_TIMEOUT_4096_CYCLES  = 3,
    CY_SMIF_MERGE_TIMEOUT_65536_CYCLES = 4,
} cy_en_smif_merge_timeout_t;

/** Specifies the  PORT priority for XIP space. */
typedef enum
{
    CY_SMIF_EN_BRIDGE_PRIO_SMIF0_XIP_SPACE = 0, // The master accessing through the SMIF0 XIP space has high priority.
    CY_SMIF_EN_BRIDGE_PRIO_SMIF1_XIP_SPACE = 1, // The master accessing through the SMIF1 XIP space has high priority.
} cy_en_smif_bridge_xip_space_pri_t;

/** Specifies the XIP space. */
typedef enum
{
    CY_SMIF_EN_BRIDGE_SMIF0_XIP_SPACE = 0,
    CY_SMIF_EN_BRIDGE_SMIF1_XIP_SPACE = 1,
} cy_en_smif_bridge_xip_space_t;

/** Specifies the port priority on bridge interface. */
typedef struct
{
    cy_en_smif_bridge_xip_space_pri_t pri_ahb_smif0;  /**< This specifies the priority for AHB access over SMIF0 */
    cy_en_smif_bridge_xip_space_pri_t pri_ahb_smif1;  /**< This specifies the priority for AHB access over SMIF1 */
    cy_en_smif_bridge_xip_space_pri_t pri_axi_smif0;  /**< This specifies the priority for AXI access over SMIF0 */
    cy_en_smif_bridge_xip_space_pri_t pri_axi_smif1;  /**< This specifies the priority for AXI access over SMIF1 */
} cy_stc_smif_bridge_pri_t;

/** Specifies the remap type. */
typedef enum
{
    CY_SMIF_EN_BRIDGE_REMAP_TYPE_INACTIVE   = 0,
    CY_SMIF_EN_BRIDGE_REMAP_TYPE_TO_SMIF0   = 1,
    CY_SMIF_EN_BRIDGE_REMAP_TYPE_TO_SMIF1   = 2,
    CY_SMIF_EN_BRIDGE_REMAP_TYPE_INTERLEAVE = 3,
} cy_en_smif_bridge_remap_type_t;

/** Specifies the interleave size. */
typedef enum
{
    CY_SMIF_EN_BRIDGE_INTERLEAVE_8BYTE   = 0,
    CY_SMIF_EN_BRIDGE_INTERLEAVE_16BYTE  = 1,
    CY_SMIF_EN_BRIDGE_INTERLEAVE_32BYTE  = 2,
    CY_SMIF_EN_BRIDGE_INTERLEAVE_64BYTE  = 3,
    CY_SMIF_EN_BRIDGE_INTERLEAVE_128BYTE = 4,
} cy_en_smif_bridge_interleave_step_t;

/** Specifies the remap size. */
typedef enum
{
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_1MB   = 0x1FF00000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_2MB   = 0x1FE00000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_4MB   = 0x1FC00000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_8MB   = 0x1F800000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_16MB  = 0x1F000000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_32MB  = 0x1E000000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_64MB  = 0x1C000000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_128MB = 0x18000000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_256MB = 0x10000000U,
    CY_SMIF_EN_BRIDGE_REMAP_SIZE_512MB = 0x00000000U,
} cy_en_smif_bridge_remap_region_size_t;

/** Specifies the remap region information. */
typedef struct
{
    uint32_t                              regionIdx;   /**< This specifies the region index (0..8) */
    cy_en_smif_bridge_remap_region_size_t regionSize;  /**< This specifies the region size */
    uint32_t                              xipAddr;     /**< This specifies XIP address to be remapped */
    uint32_t                              phyAddr;     /**< This specifies target remapped address */
} cy_stc_smif_bridge_remap_t;

/** Specifies the interleaved memory region. */
typedef struct
{
    uint32_t                              regionIdx;       /**< This specifies the region index (0..8) */
    cy_en_smif_bridge_remap_region_size_t regionSize;      /**< This specifies the region size */
    uint32_t                              xipAddr;         /**< This specifies XIP address to be remapped */
    uint32_t                              phyAddr0;        /**< This specifies remapped address on PORT0 */
    uint32_t                              phyAddr1;        /**< This specifies remapped address on PORT1 */
} cy_stc_smif_bridge_interleave_remap_t;

/** Specifies the data line index. */
typedef enum
{
    CY_SMIF_DATA_BIT0_TAP_SEL = 0U, /**< Data line zero. */
    CY_SMIF_DATA_BIT1_TAP_SEL = 1U, /**< Data line one. */
    CY_SMIF_DATA_BIT2_TAP_SEL = 2U, /**< Data line two. */
    CY_SMIF_DATA_BIT3_TAP_SEL = 3U, /**< Data line three. */
    CY_SMIF_DATA_BIT4_TAP_SEL = 4U, /**< Data line four. */
    CY_SMIF_DATA_BIT5_TAP_SEL = 5U, /**< Data line five. */
    CY_SMIF_DATA_BIT6_TAP_SEL = 6U, /**< Data line six. */
    CY_SMIF_DATA_BIT7_TAP_SEL = 7U, /**< Data line seven. */
} cy_en_smif_mem_data_line_t;

/** Specifies the sdr cap style. */
typedef enum
{
    CY_SMIF_RX_CAP_STYLE_SDR_POS       = 0,
    CY_SMIF_RX_CAP_STYLE_SDR_NEG_NORM  = 1,
    CY_SMIF_RX_CAP_STYLE_SDR_NEG_PIPED = 2,
} cy_en_sdr_cap_style_t;

/** Specifies CACHE region attribute. */
typedef enum
{
      CY_SMIF_NON_CACHEABLE_NON_BUFFERABLE = 0x00, /**< Non-Cacheable, Non-Bufferable (reset value)*/
      CY_SMIF_NON_CACHEABLE_BUFFERABLE     = 0x01, /**< Non-Cacheable, Bufferable  */
      CY_SMIF_CACHEABLE_WT_WA              = 0x0E, /**< Cacheable, Write Through, Write Allocate */
      CY_SMIF_CACHEABLE_WT_RA              = 0x16, /**< Cacheable, Write Through, Read Allocate */
      CY_SMIF_CACHEABLE_WT_RWA             = 0x1E, /**< Cacheable, Write Through, Read & Write Allocate */
      CY_SMIF_CACHEABLE_WB_WA              = 0x0F, /**< Cacheable, Write Back, Write Allocate */
      CY_SMIF_CACHEABLE_WB_RA              = 0x17, /**< Cacheable, Write Back, Read Allocate */
      CY_SMIF_CACHEABLE_WB_RWA             = 0x1F, /**< Cacheable, Write Back, Read & Write Allocate */
} cy_en_smif_cache_attribute_t;

/** \cond INTERNAL */
/*******************************************************************************
* These are legacy macros. They are left here just for backward compatibility.
* Do not use them in new designs.
*******************************************************************************/

#define CY_SMIF_SEND_CMPLT                          CY_SMIF_SEND_COMPLETE
#define CY_SMIF_REC_CMPLT                           CY_SMIF_RX_COMPLETE
#define CY_SMIF_REC_BUSY                            CY_SMIF_RX_BUSY
#define CY_SMIF_SEL_INV_INTERNAL_CLK                CY_SMIF_SEL_INVERTED_INTERNAL_CLK
#define CY_SMIF_SEL_INV_FEEDBACK_CLK                CY_SMIF_SEL_INVERTED_FEEDBACK_CLK
#define cy_en_smif_cache_en_t                       cy_en_smif_cache_t
#define Cy_SMIF_GetTxfrStatus                       Cy_SMIF_GetTransferStatus

/** \endcond */

/** \} group_smif_enums */


/**
* \addtogroup group_smif_data_structures
* \{
*/

/***************************************************************************//**
*
* The SMIF user callback function type called at the end of a transfer.
*
* \param event
* The event which caused a callback call.
*
*******************************************************************************/
typedef void (*cy_smif_event_cb_t)(uint32_t event);


/** The SMIF configuration structure. */
typedef struct
{
    uint32_t mode;              /**<  Specifies the mode of operation \ref cy_en_smif_mode_t. */
    uint32_t deselectDelay;     /**<  Specifies the minimum duration of SPI de-selection between SPI transfers:
                                *   - "0": 1 clock cycle.
                                *   - "1": 2 clock cycles.
                                *   - "2": 3 clock cycles.
                                *   - "3": 4 clock cycles.
                                *   - "4": 5 clock cycles.
                                *   - "5": 6 clock cycles.
                                *   - "6": 7 clock cycles.
                                *   - "7": 8 clock cycles. */
//#if (CY_IP_MXSMIF_VERSION <= 3) DRIVERS-20475 temporary workaround
    uint32_t rxClockSel;        /**< Specifies the clock source for the receiver
                                *  clock \ref cy_en_smif_clk_select_t. */
//#endif
    uint32_t blockEvent;        /**< Specifies what happens when there is a Read
                                * from an empty RX FIFO or a Write to a full
                                * TX FIFO. \ref cy_en_smif_error_event_t. */
    cy_en_smif_delay_tap_t   delayTapEnable;      /**<  Delay tap can be enabled or disabled \ref cy_en_smif_delay_tap_t. */
    cy_en_smif_delay_line_t  delayLineSelect;     /**< set line selection which is input. \ref cy_en_smif_delay_line_t */
    uint32_t                    inputFrequencyMHz;    /**< Input frequency. Used when internal DLL is enabled for setting the speed mode */
    bool                        enable_internal_dll;  /**< Enables internal DLL. Default value by passes DLL */
    cy_en_smif_dll_divider_t    dll_divider_value;    /**< Divider value for DLL */
    cy_en_cy_smif_mdl_tap_sel_t mdl_tap;              /**< Delay tap for DLL MDL */
    cy_en_cy_smif_sdl_tap_sel_t device0_sdl_tap;      /**< Delay tap (pos and neg) for DLL SDL timings on Device[0]. Only relevant in XIP mode. */
    cy_en_cy_smif_sdl_tap_sel_t device1_sdl_tap;      /**< Delay tap (pos and neg) for DLL SDL timings on Device[1]. Only relevant in XIP mode. */
    cy_en_cy_smif_sdl_tap_sel_t device2_sdl_tap;      /**< Delay tap (pos and neg) for DLL SDL timings on Device[2]. Only relevant in XIP mode. */
    cy_en_cy_smif_sdl_tap_sel_t device3_sdl_tap;      /**< Delay tap (pos and neg) for DLL SDL timings on Device[3]. Only relevant in XIP mode. */
    cy_en_smif_capture_mode_t   rx_capture_mode;      /**< RX Capture mode */
    cy_en_smif_tx_sdr_extra_t   tx_sdr_extra;         /**< TX SDR Extra */
 } cy_stc_smif_config_t;

/** The SMIF internal context data. The user must not modify it. */
typedef struct
{
    uint8_t const volatile * volatile txBufferAddress;    /**<  The pointer to the data to transfer */
    uint32_t txBufferSize;                          /**<  The size of the data to transmit in bytes */
    /**
    * The transfer counter. The number of the transmitted bytes = txBufferSize - txBufferCounter
    */
    uint32_t volatile txBufferCounter;
    uint8_t volatile * volatile rxBufferAddress;    /**<  The pointer to the variable where the received data is stored */
    uint32_t rxBufferSize;                          /**<  The size of the data to be received in bytes */
    /**
    * The transfer counter. The number of the received bytes = rxBufferSize - rxBufferCounter
    */
    uint32_t volatile rxBufferCounter;
    /**
    * The status of the transfer. The transmitting / receiving is completed / in progress
    */
    cy_en_smif_txfr_status_t volatile transferStatus;
    cy_smif_event_cb_t       volatile txCompleteCb;          /**< The user-defined callback executed at the completion of a transmission */
    cy_smif_event_cb_t       volatile rxCompleteCb;          /**< The user-defined callback executed at the completion of a reception */
    /**
    * The timeout in microseconds for the blocking functions. This timeout value applies to all blocking APIs.
    */
    uint32_t timeout;
    /**
    * The timeout in microseconds for polling memory device on its readiness.
    */
    uint16_t memReadyPollDelay;
    cy_en_smif_data_rate_t  preCmdDataRate; /**< preferred command data rate */
    cy_en_smif_txfr_width_t preCmdWidth; /**< preferred command data rate */
    cy_en_smif_data_rate_t  preXIPDataRate; /**< preferred XIP data rate */
    uint32_t dummyCycles; /**< preferred dummy cycles per transaction */
    /** Determines if the device is memory-mapped, enables the Autodetect
     * using the SFDP, enables the write capability, or enables the crypto
     * support for this memory slave */
    uint32_t flags;
} cy_stc_smif_context_t;

 /** Specifies SMIF Crypto Region configuration. */
typedef struct{
    uint32_t key[4];                   /**< Specifies the AES key application for the region. */
    uint32_t iv[4];                    /**< Specifies the Crypto IV for the region */
    uint32_t *region_base_address;     /**< Specifies the base address for the region. */
    uint32_t region_size;              /**< Specifies the size of the memory region. */
}cy_stc_smif_crypto_region_config_t;

/** Specifies SMIF cache region configuration. */
typedef struct cy_stc_smif_cache_region
{
    bool                                  enabled;          /**< Enable/Disable CACHE Region.*/
    uint32_t                              start_address;    /**< Start address of CACHE region.*/
    uint32_t                              end_address;      /**< End address of CACHE region.*/
    cy_en_smif_cache_attribute_t          cache_attributes; /**< CACHE Transaction attributes set for this region.*/
} cy_stc_smif_cache_region_t;

/** Specifies SMIF cache configuration. */
typedef struct
{
    bool                        enabled;                 /**< Enable/Disable SMIF Internal CACHE.*/
    bool                        cache_retention_on;      /**< If set, retains CACHE in DeepSleep mode. Not applicable in Deep Sleep OFF or Deep Sleep RAM mode.*/
    cy_stc_smif_cache_region_t  cache_region_0;          /**< CACHE region 0 configuration. */
    cy_stc_smif_cache_region_t  cache_region_1;          /**< CACHE region 1 configuration. */
    cy_stc_smif_cache_region_t  cache_region_2;          /**< CACHE region 2 configuration. */
    cy_stc_smif_cache_region_t  cache_region_3;          /**< CACHE region 3 configuration. */
} cy_stc_smif_cache_config_t;
/** \} group_smif_data_structures */


/**
* \addtogroup group_smif_low_level_functions
* \{
*/

cy_en_smif_status_t Cy_SMIF_Init(SMIF_Type *base, cy_stc_smif_config_t const *config,
                                uint32_t timeout,
                                cy_stc_smif_context_t *context);
cy_en_smif_status_t Cy_SMIF_DllConfig(volatile SMIF_Type *base,
                                    cy_stc_smif_config_t const *config,
                                    cy_stc_smif_context_t *context);
void Cy_SMIF_DeInit(SMIF_Type *base);
void Cy_SMIF_SetDataSelect(SMIF_Type *base, cy_en_smif_slave_select_t slaveSelect,
                                cy_en_smif_data_select_t dataSelect);
void Cy_SMIF_SetMode(SMIF_Type *base, cy_en_smif_mode_t mode);
cy_en_smif_mode_t Cy_SMIF_GetMode(SMIF_Type const *base);
cy_en_smif_status_t Cy_SMIF_TransmitCommand(SMIF_Type *base,
                                uint8_t cmd,
                                cy_en_smif_txfr_width_t cmdTxfrWidth,
                                uint8_t const cmdParam[], uint32_t paramSize,
                                cy_en_smif_txfr_width_t paramTxfrWidth,
                                cy_en_smif_slave_select_t slaveSelect, uint32_t completeTxfr,
                                cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_TransmitData(SMIF_Type *base,
                                uint8_t const *txBuffer, uint32_t size,
                                cy_en_smif_txfr_width_t transferWidth,
                                cy_smif_event_cb_t TxCompleteCb,
                                cy_stc_smif_context_t *context);
cy_en_smif_status_t  Cy_SMIF_TransmitDataBlocking(SMIF_Type *base,
                                uint8_t const *txBuffer,
                                uint32_t size,
                                cy_en_smif_txfr_width_t transferWidth,
                                cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_ReceiveData(SMIF_Type *base,
                                uint8_t *rxBuffer, uint32_t size,
                                cy_en_smif_txfr_width_t transferWidth,
                                cy_smif_event_cb_t RxCompleteCb,
                                cy_stc_smif_context_t *context);
cy_en_smif_status_t  Cy_SMIF_ReceiveDataBlocking(SMIF_Type *base,
                                uint8_t *rxBuffer,
                                uint32_t size,
                                cy_en_smif_txfr_width_t transferWidth,
                                cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_SendDummyCycles(SMIF_Type *base, uint32_t cycles);
cy_en_smif_txfr_status_t Cy_SMIF_GetTransferStatus(SMIF_Type const *base, cy_stc_smif_context_t const *context);
void Cy_SMIF_Enable(SMIF_Type *base, cy_stc_smif_context_t *context);

cy_en_smif_status_t Cy_SMIF_TransmitCommand_Ext(SMIF_Type *base,
                                                 uint16_t cmd,
                                                 bool isCommand2byte,
                                                 cy_en_smif_txfr_width_t cmdTxfrWidth,
                                                 cy_en_smif_data_rate_t cmdDataRate,
                                                 uint8_t const cmdParam[],
                                                 uint32_t paramSize,
                                                 cy_en_smif_txfr_width_t paramTxfrWidth,
                                                 cy_en_smif_data_rate_t paramDataRate,
                                                 cy_en_smif_slave_select_t slaveSelect,
                                                 uint32_t completeTxfr,
                                                 cy_stc_smif_context_t const *context);

cy_en_smif_status_t Cy_SMIF_TransmitData_Ext(SMIF_Type *base,
                                                uint8_t const *txBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataDataRate,
                                                cy_smif_event_cb_t TxCmpltCb,
                                                cy_stc_smif_context_t *context);

cy_en_smif_status_t Cy_SMIF_TransmitDataBlocking_Ext(SMIF_Type *base,
                                                uint8_t const *txBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataDataRate,
                                                cy_stc_smif_context_t const *context);

cy_en_smif_status_t Cy_SMIF_ReceiveData_Ext(SMIF_Type *base,
                                                uint8_t *rxBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataRate,
                                                cy_smif_event_cb_t RxCmpltCb,
                                                cy_stc_smif_context_t *context);

cy_en_smif_status_t Cy_SMIF_ReceiveDataBlocking_Ext(SMIF_Type *base,
                                                uint8_t *rxBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataRate,
                                                cy_stc_smif_context_t const *context);

cy_en_smif_status_t Cy_SMIF_SendDummyCycles_Ext(SMIF_Type *base,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataRate,
                                                uint32_t cycles);
cy_en_smif_status_t Cy_SMIF_SendDummyCycles_With_RWDS(SMIF_Type *base,
                                                bool read_rwds,
                                                bool refresh_indicator,
                                                uint32_t cycles);
void Cy_SMIF_DeviceTransfer_SetMergeTimeout(SMIF_Type *base, cy_en_smif_slave_select_t slave, cy_en_smif_merge_timeout_t timeout);
void Cy_SMIF_DeviceTransfer_ClearMergeTimeout(SMIF_Type *base, cy_en_smif_slave_select_t slave);


/* MDL and SDL tap select functions. */
cy_en_smif_status_t Cy_SMIF_Set_DelayTapSel(SMIF_Type *base, uint8_t tapSel);
uint8_t Cy_SMIF_Get_DelayTapSel(SMIF_Type *base);
cy_en_smif_status_t Cy_SMIF_Set_Sdl_DelayTapSel(SMIF_CORE_DEVICE_Type *smif_device_base, uint8_t tapSel);

__STATIC_INLINE bool Cy_SMIF_IsEnabled(SMIF_Type *base);
__STATIC_INLINE void Cy_SMIF_Disable(SMIF_Type *base);
__STATIC_INLINE void  Cy_SMIF_SetInterruptMask(SMIF_Type *base, uint32_t interrupt);
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptMask(SMIF_Type const *base);
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptStatusMasked(SMIF_Type const *base);
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptStatus(SMIF_Type const *base);
__STATIC_INLINE void  Cy_SMIF_SetInterrupt(SMIF_Type *base, uint32_t interrupt);
__STATIC_INLINE void  Cy_SMIF_ClearInterrupt(SMIF_Type *base, uint32_t interrupt);
__STATIC_INLINE void  Cy_SMIF_SetTxFifoTriggerLevel(SMIF_Type *base, uint32_t level);
__STATIC_INLINE void  Cy_SMIF_SetRxFifoTriggerLevel(SMIF_Type *base, uint32_t level);
__STATIC_INLINE uint32_t  Cy_SMIF_GetCmdFifoStatus(SMIF_Type const *base);
__STATIC_INLINE uint32_t  Cy_SMIF_GetTxFifoStatus(SMIF_Type const *base);
__STATIC_INLINE uint32_t  Cy_SMIF_GetRxFifoStatus(SMIF_Type const *base);
cy_en_smif_status_t  Cy_SMIF_Encrypt(SMIF_Type *base,
                                uint32_t address,
                                uint8_t data[],
                                uint32_t size,
                                cy_stc_smif_context_t const *context);
__STATIC_INLINE bool Cy_SMIF_BusyCheck(SMIF_Type const *base);
__STATIC_INLINE void Cy_SMIF_Interrupt(SMIF_Type *base, cy_stc_smif_context_t *context);
cy_en_smif_status_t Cy_SMIF_CacheEnable(SMIF_Type *base, cy_en_smif_cache_t cacheType);
cy_en_smif_status_t Cy_SMIF_CacheDisable(SMIF_Type *base, cy_en_smif_cache_t cacheType);
cy_en_smif_status_t Cy_SMIF_CachePrefetchingEnable(SMIF_Type *base, cy_en_smif_cache_t cacheType);
cy_en_smif_status_t Cy_SMIF_CachePrefetchingDisable(SMIF_Type *base, cy_en_smif_cache_t cacheType);
cy_en_smif_status_t Cy_SMIF_CacheInvalidate(SMIF_Type *base, cy_en_smif_cache_t cacheType);
void Cy_SMIF_SetCryptoKey(SMIF_Type *base, uint32_t *key);
void Cy_SMIF_SetCryptoIV(SMIF_Type *base, uint32_t *nonce);
cy_en_smif_status_t Cy_SMIF_SetCryptoEnable(SMIF_Type *base, cy_en_smif_slave_select_t slaveId);
cy_en_smif_status_t Cy_SMIF_SetCryptoDisable(SMIF_Type *base, cy_en_smif_slave_select_t slaveId);
cy_en_smif_status_t Cy_SMIF_IsCryptoEnabled(SMIF_Type *base, cy_en_smif_slave_select_t slaveId, bool *crypto_status);

cy_en_smif_status_t Cy_SMIF_SetCryptoKeyRegion(SMIF_Type *base, uint8_t crypto_region_index, cy_stc_smif_crypto_region_config_t *region_config);
cy_en_smif_status_t Cy_SMIF_SetCryptoSubRegionDisable(SMIF_Type *base, uint8_t crypto_region_index, uint8_t mask);

cy_en_smif_status_t Cy_SMIF_ConvertSlaveSlotToIndex(cy_en_smif_slave_select_t ss, uint32_t *device_idx);

cy_en_smif_status_t Cy_SMIF_SetRxCaptureMode(SMIF_Type *base, cy_en_smif_capture_mode_t mode, cy_en_smif_slave_select_t slaveId);
#if (defined (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1u)) || defined (CY_DOXYGEN)
bool Cy_SMIF_IsBridgeOn(SMIF_Base_Type *base);
cy_en_smif_status_t Cy_SMIF_Bridge_Enable(SMIF_Base_Type *base, bool enable);
#endif /* (defined (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1u)) */

#if (defined (SMIF_DLP_PRESENT) && (SMIF_DLP_PRESENT > 0)) || \
      (defined (SMIF0_DLP_PRESENT) && (SMIF0_DLP_PRESENT > 0)) || \
      (defined (SMIF1_DLP_PRESENT) && (SMIF1_DLP_PRESENT > 0))
cy_en_smif_status_t Cy_SMIF_SetMasterDLP(SMIF_Type *base, uint16 dlp, uint8_t size);
uint16_t Cy_SMIF_GetMasterDLP(SMIF_Type *base);
uint8_t Cy_SMIF_GetMasterDLPSize(SMIF_Type *base);
uint8_t Cy_SMIF_GetTapNumCapturedCorrectDLP(SMIF_Type *base, uint8_t bit);
uint32_t CY_SMIF_GetDelayTapsNumber(volatile void *base);
#endif /* DLP_PRESENT */

cy_en_smif_status_t Cy_SMIF_InitCache(SMIF_CACHE_BLOCK_Type *base, const cy_stc_smif_cache_config_t *cache_config);

cy_en_smif_status_t Cy_SMIF_Clean_All_Cache(SMIF_CACHE_BLOCK_Type *base);
cy_en_smif_status_t Cy_SMIF_Invalidate_All_Cache(SMIF_CACHE_BLOCK_Type *base);
cy_en_smif_status_t Cy_SMIF_Clean_And_Invalidate_All_Cache(SMIF_CACHE_BLOCK_Type *base);

cy_en_smif_status_t Cy_SMIF_Clean_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size);
cy_en_smif_status_t Cy_SMIF_Invalidate_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size);
cy_en_smif_status_t Cy_SMIF_Clean_And_Invalidate_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size);
cy_en_smif_status_t Cy_SMIF_IsCacheEnabled(SMIF_CACHE_BLOCK_Type *base, bool *cache_status);

/** \addtogroup group_smif_functions_syspm_callback
* The driver supports SysPm callback for Deep Sleep and Hibernate transition.
* \{
*/
#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
cy_en_syspm_status_t Cy_SMIF_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
cy_en_syspm_status_t Cy_SMIF_HibernateCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
#endif
/** \} */


/***************************************
*  Internal SMIF function declarations
****************************************/
/** \cond INTERNAL */
__STATIC_INLINE void Cy_SMIF_PushTxFifo(SMIF_Type *baseaddr, cy_stc_smif_context_t *context);      /**< Writes transmitted data into the FIFO. */
__STATIC_INLINE void Cy_SMIF_PopRxFifo(SMIF_Type *baseaddr, cy_stc_smif_context_t *context);       /**< Reads received data from the FIFO. */
__STATIC_INLINE uint32_t Cy_SMIF_PackBytesArray(uint8_t const buff[], bool fourBytes);
__STATIC_INLINE void Cy_SMIF_UnPackByteArray(uint32_t inValue, uint8_t outBuff[], bool fourBytes);
__STATIC_INLINE cy_en_smif_status_t Cy_SMIF_TimeoutRun(uint32_t *timeoutUnits);
__STATIC_INLINE SMIF_DEVICE_Type volatile * Cy_SMIF_GetDeviceBySlot(SMIF_Type *base, cy_en_smif_slave_select_t slaveSelect);
/** \endcond */

/** \} group_smif_low_level_functions */


/**
* \addtogroup group_smif_low_level_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_SMIF_IsEnabled
****************************************************************************//**
*
* Checks whether the SMIF block is enabled
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return True if the block is enabled, false otherwise
*******************************************************************************/
__STATIC_INLINE bool Cy_SMIF_IsEnabled(SMIF_Type *base)
{
    return ((SMIF_CTL(base) & SMIF_CTL_ENABLED_Msk) != 0U);
}

/*******************************************************************************
* Function Name: Cy_SMIF_Disable
****************************************************************************//**
*
* Disables the operation of the SMIF block. The SMIF block can be disabled only
* when it is not in the active state. Use the Cy_SMIF_BusyCheck() API to check
* it before calling this API. Make sure the clock supplied to SMIF block is also
* disabled before calling this API using \ref Cy_SysClk_ClkHfDisable
*
* \param base
* Holds the base address of the SMIF block registers.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SMIF_Disable(SMIF_Type *base)
{
    SMIF_CTL(base) &= ~SMIF_CTL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetInterruptMask
****************************************************************************//**
*
* This function is used to set an interrupt mask for the SMIF Interrupt.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param interrupt
* This is the mask for different source options that can be masked. See
* \ref group_smif_macros_isr "Interrupt Macros" for possible values.
*
*******************************************************************************/
__STATIC_INLINE void  Cy_SMIF_SetInterruptMask(SMIF_Type *base, uint32_t interrupt)
{
    SMIF_INTR_MASK(base) = interrupt;
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetInterruptMask
****************************************************************************//**
*
* This function is used to read an interrupt mask for the SMIF Interrupt.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns the mask set for the SMIF interrupt.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptMask(SMIF_Type const *base)
{
  return (SMIF_INTR_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetInterruptStatusMasked
****************************************************************************//**
*
* This function is used to read an active masked interrupt. This function can
* be used in the interrupt service-routine to find which source triggered the
* interrupt.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns a word with bits set at positions corresponding to the
* interrupts triggered in the system.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptStatusMasked(SMIF_Type const *base)
{
  return (SMIF_INTR_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetInterruptStatus
****************************************************************************//**
*
* This function is used to read an active interrupt. This status is the unmasked
* result, so will also show interrupts that will not generate active interrupts.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns a word with bits set at positions corresponding to the
* interrupts triggered in the system.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetInterruptStatus(SMIF_Type const *base)
{
  return (SMIF_INTR(base));
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetInterrupt
****************************************************************************//**
*
* This function is used to set an interrupt source. This function can be used
* to activate interrupts through the software.
*
* \note Interrupt sources set using this interrupt will generate interrupts only
* if they are not masked.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param interrupt
* An encoded integer with a bit set corresponding to the interrupt to be
* triggered. See \ref group_smif_macros_isr "Interrupt Macros" for possible
* values.
*
*******************************************************************************/
__STATIC_INLINE void  Cy_SMIF_SetInterrupt(SMIF_Type *base, uint32_t interrupt)
{
    SMIF_INTR_SET(base) = interrupt;
}


/*******************************************************************************
* Function Name: Cy_SMIF_ClearInterrupt
****************************************************************************//**
*
* This function is used to clear an interrupt source. This function can be used
* in the user code to clear all pending interrupts.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param interrupt
* An encoded integer with a bit set corresponding to the interrupt that must
* be cleared. See \ref group_smif_macros_isr "Interrupt Macros" for possible
* values.
*
*******************************************************************************/
__STATIC_INLINE void  Cy_SMIF_ClearInterrupt(SMIF_Type *base, uint32_t interrupt)
{
    SMIF_INTR(base) = interrupt;

    /* Ensure that the initial Write has been flushed out to the hardware. */
    interrupt = SMIF_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetTxFifoTriggerLevel()
****************************************************************************//**
*
* This function is used to set a trigger level for the TX FIFO. This value must
* be an integer between 0 and 7. For the normal mode only.
* The triggering is active when TX_DATA_FIFO_STATUS <= level.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param level
* The trigger level to set (0-8).
*
*******************************************************************************/
__STATIC_INLINE void  Cy_SMIF_SetTxFifoTriggerLevel(SMIF_Type *base, uint32_t level)
{
    CY_ASSERT_L2(level <= CY_SMIF_MAX_TX_TR_LEVEL);
    SMIF_TX_DATA_FIFO_CTL(base) = level;
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetRxFifoTriggerLevel()
****************************************************************************//**
*
* This function is used to set a trigger level for the RX FIFO. This value must
* be an integer between 0 and 7. For the normal mode only.
* The triggering is active when RX_DATA_FIFOSTATUS > level.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param level
* The trigger level to set(0-8).
*
*******************************************************************************/
__STATIC_INLINE void  Cy_SMIF_SetRxFifoTriggerLevel(SMIF_Type *base, uint32_t level)
{
    CY_ASSERT_L2(level <= CY_SMIF_MAX_RX_TR_LEVEL);
    SMIF_RX_DATA_FIFO_CTL(base) = level;
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetCmdFifoStatus()
****************************************************************************//**
*
* This function is used to read the status of the CMD FIFO.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns the number of the entries in the CMD FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetCmdFifoStatus(SMIF_Type const *base)
{
    return (_FLD2VAL(SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4, SMIF_TX_CMD_MMIO_FIFO_STATUS(base)));
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetTxFifoStatus()
****************************************************************************//**
*
* This function is used to read the status of the TX FIFO.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns the number of the entries in the TX FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetTxFifoStatus(SMIF_Type const *base)
{
    return (_FLD2VAL(SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4, SMIF_TX_DATA_MMIO_FIFO_STATUS(base)));
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetRxFifoStatus()
****************************************************************************//**
*
* This function is used to read the status of the RX FIFO.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns the number of the entries in the RX FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t  Cy_SMIF_GetRxFifoStatus(SMIF_Type const *base)
{
    return (_FLD2VAL(SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4, SMIF_RX_DATA_MMIO_FIFO_STATUS(base)));
}


/*******************************************************************************
* Function Name: Cy_SMIF_BusyCheck
****************************************************************************//**
*
* This function provides the status of the IP block (False - not busy,
* True - busy).
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Returns an IP block status.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SMIF_BusyCheck(SMIF_Type const *base)
{
  return (1UL == _FLD2VAL(SMIF_STATUS_BUSY, SMIF_STATUS(base)));
}


/*******************************************************************************
* Function Name: Cy_SMIF_Interrupt
****************************************************************************//**
*
* The Interrupt Service Routine for the SMIF. The interrupt code will be
* responsible for the FIFO operations on FIFO interrupts during ongoing transfers.
* The user must place a call to this interrupt function in the interrupt
* routine corresponding to the interrupt attached to the SMIF. If the
* user does not do this, will break: the functionality of all the API functions in
* the SMIF driver that use SMIF interrupts to affect transfers.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \globalvars
*  - context->txBufferAddress - The pointer to the data to be transferred.
*
*  - context->txBufferSize - The size of txBuffer.
*
*  - context->txBufferCounter - The number of data entries left to be transferred.
*
* All the Global variables described above are used when the Software Buffer is
* used.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SMIF_Interrupt(SMIF_Type *base, cy_stc_smif_context_t *context)
{
    uint32_t interruptStatus = Cy_SMIF_GetInterruptStatusMasked(base);

    /* Check which interrupt occurred */
    if (0U != (interruptStatus & SMIF_INTR_TR_TX_REQ_Msk))
    {
        /* Send data */
        Cy_SMIF_PushTxFifo(base, context);

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_TR_TX_REQ_Msk);
    }
    else if (0U != (interruptStatus & SMIF_INTR_TR_RX_REQ_Msk))
    {
        /* Receive data */
        Cy_SMIF_PopRxFifo(base, context);

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_TR_RX_REQ_Msk);
    }
    else if (0U != (interruptStatus & SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk))
    {
        /* An XIP alignment error */
        context->transferStatus = CY_SMIF_XIP_ERROR;

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk);
    }

    else if (0U != (interruptStatus & SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk))
    {
        /* TX CMD FIFO overflow */
        context->transferStatus = CY_SMIF_CMD_ERROR;

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk);
    }

    else if (0U != (interruptStatus & SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk))
    {
        /* A TX DATA FIFO overflow */
        context->transferStatus = CY_SMIF_TX_ERROR;

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk);
    }

    else if (0U != (interruptStatus & SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Msk))
    {
        /* RX DATA FIFO underflow */
        context->transferStatus = CY_SMIF_RX_ERROR;

        Cy_SMIF_ClearInterrupt(base, SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Msk);
    }
    else
    {
        /* Processing of errors */
    }
}


/*******************************************************************************
*  Internal SMIF in-line functions
*******************************************************************************/

/** \cond INTERNAL */

/*******************************************************************************
* Function Name: Cy_SMIF_PushTxFifo
***************************************************************************//***
*
* \internal
*
* \param baseaddr
* Holds the base address of the SMIF block registers.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* This function writes data in the TX FIFO SMIF buffer by 4, 2, or 1 bytes based
* on the residual number of bytes and the available space in the TX FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SMIF_PushTxFifo(SMIF_Type *baseaddr, cy_stc_smif_context_t *context)
{
    /* The variable that shows which is smaller: the free FIFO size or amount of bytes to be sent */
    uint32_t writeBytes;
    uint32_t freeFifoBytes;
    uint32_t buffCounter = context->txBufferCounter;
    uint8_t *buff = (uint8_t*) context->txBufferAddress;

    freeFifoBytes = CY_SMIF_TX_DATA_FIFO_STATUS_RANGE - Cy_SMIF_GetTxFifoStatus(baseaddr);
    writeBytes = (freeFifoBytes > buffCounter)? buffCounter: freeFifoBytes;

    /* Check that after a FIFO Write, no data/FIFO space remains */
    while (0U != writeBytes)
    {
        /* The first main use case for long transfers */
        if (writeBytes == CY_SMIF_EIGHT_BYTES)
        {
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[0U], true);
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[4U], true);
        }
        /* The second main use case for short transfers */
        else if(writeBytes == CY_SMIF_ONE_BYTE)
        {
            if((context->preCmdDataRate == CY_SMIF_DDR) &&(context->preCmdWidth == CY_SMIF_WIDTH_OCTAL))
            {
                SMIF_TX_DATA_MMIO_FIFO_WR1ODD(baseaddr) = buff[0U];
            }
            else
            {
                SMIF_TX_DATA_MMIO_FIFO_WR1(baseaddr) = buff[0U];
            }
        }
        else if ((writeBytes == CY_SMIF_TWO_BYTES) || (writeBytes == CY_SMIF_THREE_BYTES))
        {
            SMIF_TX_DATA_FIFO_WR2(baseaddr) = Cy_SMIF_PackBytesArray(&buff[0U], false);
            writeBytes = CY_SMIF_TWO_BYTES;
        }
        else if ((writeBytes == CY_SMIF_FOUR_BYTES) || (writeBytes == CY_SMIF_FIVE_BYTES))
        {
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[0U], true);
            writeBytes = CY_SMIF_FOUR_BYTES;
        }
        else if ((writeBytes == CY_SMIF_SIX_BYTES) || (writeBytes == CY_SMIF_SEVEN_BYTES))
        {
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[0U], true);
            SMIF_TX_DATA_FIFO_WR2(baseaddr) = Cy_SMIF_PackBytesArray(&buff[4U], false);
            writeBytes = CY_SMIF_SIX_BYTES;
        }
        else /* The  future IP block with FIFO > 8*/
        {
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[0U], true);
            SMIF_TX_DATA_FIFO_WR4(baseaddr) = Cy_SMIF_PackBytesArray(&buff[4U], true);
            writeBytes = CY_SMIF_EIGHT_BYTES;
        }
        buff = &buff[writeBytes];
        buffCounter -= writeBytes;

        while (Cy_SMIF_GetTxFifoStatus(baseaddr) != 0);
        /* Send remaining data */
        freeFifoBytes = CY_SMIF_TX_DATA_FIFO_STATUS_RANGE;
        writeBytes = (freeFifoBytes > buffCounter)? buffCounter: freeFifoBytes;
    }

    /* Save changes in the context */
    context->txBufferAddress = buff;
    context->txBufferCounter = buffCounter;

    /* Check if all bytes are sent */
    if (0u == buffCounter)
    {
        Cy_SMIF_SetTxFifoTriggerLevel(baseaddr, 0U);

        /* Disable the TR_TX_REQ interrupt */
        Cy_SMIF_SetInterruptMask(baseaddr, Cy_SMIF_GetInterruptMask(baseaddr) & ~SMIF_INTR_TR_TX_REQ_Msk);

        context->transferStatus = CY_SMIF_SEND_COMPLETE;
        if (NULL != context->txCompleteCb)
        {
            context->txCompleteCb((uint32_t) CY_SMIF_SEND_COMPLETE);
        }
    }
}


/*******************************************************************************
* Function Name: Cy_SMIF_PopRxFifo
***************************************************************************//***
*
* \internal
*
* \param baseaddr
* Holds the base address of the SMIF block registers.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* This function reads data from the RX FIFO SMIF buffer by 4, 2, or 1 bytes
* based on the data availability in the RX FIFO and amount of bytes to be
* received.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SMIF_PopRxFifo(SMIF_Type *baseaddr, cy_stc_smif_context_t *context)
{
    /* The variable that shows which is smaller: the free FIFO size or amount of bytes to be received */
    uint32_t readBytes;
    uint32_t loadedFifoBytes;
    uint32_t buffCounter = context->rxBufferCounter;
    uint8_t *buff = (uint8_t*) context->rxBufferAddress;

    loadedFifoBytes = Cy_SMIF_GetRxFifoStatus(baseaddr);
    readBytes = (loadedFifoBytes > buffCounter)? buffCounter: loadedFifoBytes;

    /* Check that after a FIFO Read, no new data is available */
    while (0U != readBytes)
    {
        if (readBytes == CY_SMIF_EIGHT_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[4U], true);
        }
        else if(readBytes == CY_SMIF_ONE_BYTE)
        {
            buff[0U] = (uint8_t)SMIF_RX_DATA_FIFO_RD1(baseaddr);
        }
        else if(readBytes == CY_SMIF_TWO_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD2(baseaddr), &buff[0U], false);
        }
        else if(readBytes == CY_SMIF_THREE_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD2(baseaddr), &buff[0U], false);
            buff[2U] = (uint8_t)SMIF_RX_DATA_FIFO_RD1(baseaddr);
        }
        else if(readBytes == CY_SMIF_FOUR_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
        }
        else if(readBytes == CY_SMIF_FIVE_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
            buff[4U] = (uint8_t)SMIF_RX_DATA_FIFO_RD1(baseaddr);
        }
        else if(readBytes == CY_SMIF_SIX_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD2(baseaddr), &buff[4U], false);
        }
        else if(readBytes == CY_SMIF_SEVEN_BYTES)
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD2(baseaddr), &buff[4U], false);
            buff[6U] = (uint8_t)SMIF_RX_DATA_FIFO_RD1(baseaddr);
        }
        else /* The IP block FIFO > 8*/
        {
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[0U], true);
            Cy_SMIF_UnPackByteArray(SMIF_RX_DATA_FIFO_RD4(baseaddr), &buff[4U], true);
            readBytes = CY_SMIF_EIGHT_BYTES;
        }

        buff = &buff[readBytes];
        buffCounter -= readBytes;
        /* Check if we already got new data in RX_FIFO */
        loadedFifoBytes = Cy_SMIF_GetRxFifoStatus(baseaddr);
        readBytes = (loadedFifoBytes > buffCounter)? buffCounter: loadedFifoBytes;
    }

    /* Save changes in the context */
    context->rxBufferAddress = buff;
    context->rxBufferCounter = buffCounter;

    /* Check if all bytes are received */
    if (0UL == buffCounter)
    {
        /* In case we have additional byte left out because of WORD based protocol, do a dummy read.*/
        if(Cy_SMIF_GetRxFifoStatus(baseaddr) == 1U)
        {
            (void)(uint8_t)SMIF_RX_DATA_FIFO_RD1(baseaddr);
        }
        /* Disable the TR_RX_REQ interrupt */
        Cy_SMIF_SetInterruptMask(baseaddr, Cy_SMIF_GetInterruptMask(baseaddr) & ~SMIF_INTR_TR_RX_REQ_Msk);
        context->transferStatus = CY_SMIF_RX_COMPLETE;
        if (NULL != context->rxCompleteCb)
        {
            context->rxCompleteCb((uint32_t) CY_SMIF_RX_COMPLETE);
        }
    }

    context->rxBufferCounter = buffCounter;
}


/*******************************************************************************
* Function Name: Cy_SMIF_PackBytesArray
***************************************************************************//***
*
* \internal
*
* This function packs 0-numBytes of the buff byte array into a 4-byte value.
*
* \param buff
* The byte array to pack.
*
* \param fourBytes
*  - True: The pack is for a 32-bit value.
*  - False: The pack is for a 16-bit value.
*
* \return
*  The 4-byte value packed from the byte array.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SMIF_PackBytesArray(uint8_t const buff[], bool fourBytes)
{
    uint32_t result = 0UL;

    result = ((uint32_t)buff[1UL] << 8UL) | (uint32_t)buff[0UL];

    if(fourBytes)
    {
        result |= ((uint32_t)buff[3UL] << 24UL) | ((uint32_t)buff[2UL] << 16UL);
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_SMIF_UnPackByteArray
***************************************************************************//***
*
* \internal
*
* This function unpacks 0-numBytes from a 4-byte value into the byte array outBuff.
*
* \param smifReg
*  The 4-byte value to unpack.
*
* \param outBuff
* The byte array to fill.
*
* \param fourBytes
*  - The True unpack is for a 32-bit value.
*  - The False unpack is for a 16-bit value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SMIF_UnPackByteArray(uint32_t inValue, uint8_t outBuff[], bool fourBytes)
{
    outBuff[0UL] = (uint8_t)(inValue & 0xFFUL);
    outBuff[1UL] = (uint8_t)((inValue >> 8UL ) & 0xFFUL);

    if(fourBytes)
    {
        outBuff[2UL] = (uint8_t)((inValue >> 16UL) & 0xFFUL);
        outBuff[3UL] = (uint8_t)((inValue >> 24UL) & 0xFFUL);
    }
}


/*******************************************************************************
* Function Name: Cy_SMIF_TimeoutRun
****************************************************************************//**
*
* \internal
*
* This function checks if the timeout is expired. Use the Cy_SysLib_DelayUs() function for
* implementation.
*
* \param timeoutUnits
*  The pointer to the timeout. The timeout measured in microseconds is multiplied by
*  CY_SMIF_WAIT_1_UNIT.
*
* \return
* A timeout status:
*     - \ref CY_SMIF_SUCCESS - The timeout has not expired or input timeoutUnits is 0.
*     - \ref CY_SMIF_EXCEED_TIMEOUT - The timeout has expired.
*
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t Cy_SMIF_TimeoutRun(uint32_t *timeoutUnits)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    if (*timeoutUnits > 0u)
    {
        Cy_SysLib_DelayUs(CY_SMIF_WAIT_1_UNIT);
        --(*timeoutUnits);
        status = (0u == (*timeoutUnits))? CY_SMIF_EXCEED_TIMEOUT: CY_SMIF_SUCCESS;
    }
    return status;
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetDeviceBySlot
****************************************************************************//**
*
* \internal
* This function returns the address of the SMIF device registers structure by the slave
* slot number.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slaveSelect
* The slave device ID. This number is either CY_SMIF_SLAVE_SELECT_0 or
* CY_SMIF_SLAVE_SELECT_1 or CY_SMIF_SLAVE_SELECT_2 or CY_SMIF_SLAVE_SELECT_3
* (\ref cy_en_smif_slave_select_t). It defines the slave-select line to use
* during the transmission.
*
*******************************************************************************/
__STATIC_INLINE SMIF_DEVICE_Type volatile * Cy_SMIF_GetDeviceBySlot(SMIF_Type *base,
                                            cy_en_smif_slave_select_t slaveSelect)
{
    SMIF_DEVICE_Type volatile *device;
    /* Connect the slave to its data lines */
    switch (slaveSelect)
    {
        case CY_SMIF_SLAVE_SELECT_0:
            device = &(SMIF_DEVICE_IDX(base, 0));
            break;
        case CY_SMIF_SLAVE_SELECT_1:
            device = &(SMIF_DEVICE_IDX(base, 1));
            break;
        case CY_SMIF_SLAVE_SELECT_2:
            device = &(SMIF_DEVICE_IDX(base, 2));
            break;
        case CY_SMIF_SLAVE_SELECT_3:
            device = &(SMIF_DEVICE_IDX(base, 3));
            break;
        default:
            /* A user error */
            device = NULL;
            break;
    }

    return device;
}
/** \endcond */
/** \} group_smif_low_level_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSMIF */

#endif /* (CY_SMIF_H) */

/** \} group_smif */


/* [] END OF FILE */
