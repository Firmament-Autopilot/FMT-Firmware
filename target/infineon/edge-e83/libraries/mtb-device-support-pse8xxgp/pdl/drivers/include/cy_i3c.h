/***************************************************************************//**
* \file cy_i3c.h
* \version 1.00
*
* \brief
* Provides I3C API declarations for the I3C Controller.
*
********************************************************************************
* \copyright
* Copyright(c) 2020-2025 Infineon Technologies AG or an affiliate of
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
* \addtogroup group_cy_i3c
* \{
* Driver API for I3C Bus Peripheral
*
* I3C - The Improved Inter-Integrated Circuit (I3C) bus is a MIPI industry-standard.
*
* The functions and other declarations used in this part of the driver are in
* cy_i3c.h. You can also include cy_pdl.h to get access to all functions and declarations
* in the PDL.
*
* The I3C peripheral driver provides an API to implement I3C in Target, Main-Controller,
* or Secondary-Controller roles based on the DW I3C hardware block.
* This I3C bus is capable of supporting I3C as well as I2C target devices as defined
* in the specification.
* I2C targets are supported with Fast-mode, and Fast-mode Plus with external 50ns
* spike filter as per I3C specification.
*
* Features:
* * An industry-standard I3C bus interface
* * Supports target, main controller, and secondary controller operation
* * SCL frequency up to 12.5MHz (SDR data rate 12.5Mbps, HDR-DDR data rate at 25Mbps)
* * In controller mode, number of addressable target devices is 11
* * Works in active power mode only
* * Does not support I3C HDR-TSP/TSR modes
* * Does not support I3C CDR (clock data recovery)
* * Does not support I3C address arbitration optimizations
* * Does not support I3C IBI with data
* * Does not support I3C time stamping
* * Does not support vendor specific CCCs
* * Does not support I2C target role
*
********************************************************************************
* \section group_cy_i3c_configuration Configuration Considerations
********************************************************************************
* The I3C driver configuration can be divided to number of sequential
* steps listed below:
* * \ref group_i3c_config
* * \ref group_i3c_pins
* * \ref group_i3c_clock
* * \ref group_i3c_data_rate
* * \ref group_i3c_intr
* * \ref group_i3c_enable
*
********************************************************************************
* \subsection group_i3c_config Configure i3c
********************************************************************************
* To set up the I3C  driver, provide the configuration parameters in the
* \ref cy_stc_i3c_config_t structure. Provide i3cMode to the select
* operation mode target, controller or secondary controller-target.
* To initialize the driver, call \ref Cy_I3C_Init function providing a
* pointer to the populated \ref cy_stc_i3c_config_t
* structure and the allocated \ref cy_stc_i3c_context_t structure.
*
* For I3C target setup read and write buffer before enabling its
* operation using \ref Cy_I3C_TargetConfigReadBuf and \ref
* Cy_I3C_TargetConfigWriteBuf appropriately. Note that the controller reads
* data from the target read buffer and writes data into the target write buffer.
*
********************************************************************************
* \subsection group_i3c_pins Assign and Configure Pins
********************************************************************************
* Only dedicated  pins can be used for I3C operation. The HSIOM
* register must be configured to connect dedicated I3C pins to the
* block. Also the open-drain enable pin for I3C must be configured in open-drain
* with internal pull up enabled
* (this pin configuration implies usage of external pull-up resistors)
*
********************************************************************************
* \subsection group_i3c_clock Assign Clock Divider
********************************************************************************
* A clock source must be connected to the  block to oversample input and
* output signals, in this document this clock will be referred as clk_i3c.
* You must use one of the 8-bit or 16-bit dividers. Use the \ref group_sysclk
* driver API to do this.
*
********************************************************************************
* \subsection group_i3c_data_rate Configure Data Rate
********************************************************************************
* To get I3C target operation with the desired data rate, the clk_i3c must be
* fast enough to provide sufficient oversampling. Use the
* \ref group_sysclk driver API to do this.
*
* To get I3C controller operation with the desired data rate, the source clock
* frequency and SCL low and high phase duration must be configured. Use the
* \ref group_sysclk driver API to configure source clock frequency. Then call
* \ref Cy_I3C_SetDataRate to set the SCL low, high phase duration
* This function sets SCL low and high phase settings based on
* source clock frequency.
*
********************************************************************************
* \subsection group_i3c_intr Configure Interrupt
********************************************************************************
* The interrupt is mandatory for I3C operation.
* The driver provides three interrupt functions: \ref Cy_I3C_Interrupt,
* \ref Cy_I3C_TargetInterrupt, and \ref Cy_I3C_ControllerInterrupt. One of
* these functions must be called in the interrupt handler for the selected
* instance. Call \ref Cy_I3C_TargetInterrupt when I3C is configured to
* operate as a target, \ref Cy_I3C_ControllerInterrupt when I3C is configured
* to operate as a controller and \ref Cy_I3C_Interrupt when I3C is configured
* to operate as controller and target. Using the target- or controller-specific interrupt
* function allows reducing the flash consumed by the I3C driver. Also this
* interrupt must be enabled in the NVIC otherwise it will not work.
* \note
* The I3C driver documentation refers to the \ref Cy_I3C_Interrupt function
* when interrupt processing is mandatory for the operation. This is done to
* simplify the readability of the driver's documentation. The application should
*  call the target- or controller-specific interrupt functions \ref Cy_I3C_TargetInterrupt
* or \ref Cy_I3C_ControllerInterrupt, when appropriate.
*
********************************************************************************
* \subsection group_i3c_enable Enable I3C
********************************************************************************
* Finally, enable the I3C operation by calling \ref Cy_I3C_Enable. Then I3C
* target starts respond to the assigned address and I3C controller ready to execute
* transfers.
*
********************************************************************************
* \section group_i3c_use_cases Common Use Cases
********************************************************************************
* \subsection group_i3c_controller_mode Controller Operation
********************************************************************************
* Call \ref Cy_I3C_ControllerRead or \ref Cy_I3C_ControllerWrite to
* communicate with the target. These functions do not block and only start a
* transaction. After a transaction starts, the \ref Cy_I3C_Interrupt
* handles further data transaction until its completion (successfully or
* with error occurring). To monitor the transaction,
* use \ref Cy_I3C_GetBusStatus or register callback function using
* \ref Cy_I3C_RegisterEventCallback to be notified about
* \ref group_i3c_macros_callback_events.
*
********************************************************************************
* \subsection group_i3c_target Target Operation
********************************************************************************
* Target operation requires the \ref Cy_I3C_Interrupt be
* called inside the interrupt handler. The read and write buffers must
* be provided for the target to enable communication with the controller. Use
* \ref Cy_I3C_TargetConfigReadBuf and \ref Cy_I3C_TargetConfigWriteBuf
* for this purpose. Note that after transaction completion the buffer must be
* configured again. Otherwise, the same buffer is used starting from the point
* where the controller stopped a previous transaction.
* For example: The read buffer is configured to be 10 bytes and the controller reads
* 8 bytes. If the read buffer is not configured again, the next controller read
* will start from the 9th byte.
* To monitor the transaction status, use \ref Cy_I3C_GetBusStatus or
* use \ref Cy_I3C_RegisterEventCallback to register a callback function
* to be notified about \ref group_i3c_macros_callback_events.
*
* \note
* I3C supports only Primary Controller mode in PSE84A0. Secondary controller mode and Target mode are supported in PSE84B0.
*
********************************************************************************
* \section group_i3c_lp Low Power Support
********************************************************************************
* The I3C driver provides callback functions to handle power mode transition.
* The callback \ref Cy_I3C_DeepSleepCallback must be called
* during execution of \ref Cy_SysPm_CpuEnterDeepSleep \ref Cy_I3C_HibernateCallback
* must be called during execution of \ref Cy_SysPm_SystemEnterHibernate. To trigger the
* callback execution, the callback must be registered before calling the
* power mode transition function. Refer to \ref group_syspm driver for more
* information about power mode transitions and callback registration.
*
* \defgroup group_i3c_macros Macros
* \defgroup group_i3c_enums Enumerated Types
* \defgroup group_i3c_data_structures Data Structures
* \defgroup group_i3c_functions Functions
* \{
* \defgroup group_i3c_general_functions General
* \defgroup group_i3c_target_functions Target
* \defgroup group_i3c_controller_functions Controller
* \defgroup group_i3c_secondary_controller_functions Secondary Controller
* \defgroup group_i3c_interrupt_functions Interrupt
* \defgroup group_i3c_low_power_functions Low Power Callbacks
* \}
*/

#if !defined (CY_I3C_H)
#define CY_I3C_H

#include "cy_device_headers.h"
#include "cy_device.h"

#if defined (CY_IP_MXI3C)

#include "cy_syspm.h"
#include "cy_i3c_ccc.h"
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 *                              Constants                                     *
 ******************************************************************************/

/**
* \addtogroup group_i3c_macros
* \{
*/

/** Driver major version */
#define CY_I3C_DRV_VERSION_MAJOR    (1U)

/** Driver minor version */
#define CY_I3C_DRV_VERSION_MINOR    (0U)

/** I3C driver identifier */
#define CY_I3C_ID           CY_PDL_DRV_ID(0x75U)

/**
* \addtogroup group_i3c_macros_common_macros Common Macros
* \{
*/

/** Max device address value */
#define CY_I3C_MAX_ADDR CY_I3C_GENMASK(6U, 0U)

/** I3C Broadcast Address */
#define CY_I3C_BROADCAST_ADDR    (0x7EU)

/** payload size position in GETMRL response */
#define CY_I3C_GETMRL_PAYLOAD_SIZE   CY_I3C_BIT(4)

/** \} group_i3c_macros_common_macros */

/**
* \defgroup group_i3c_macros_intr_macros Interrupt Status
* \{
*/

/**
* The number of empty locations in the transmit buffer is greater than or
* equal to the specified threshold value.
*/
#define CY_I3C_INTR_TX_BUFFER_THLD_STS I3C_CORE_INTR_STATUS_TX_THLD_STS_Msk

/**
* The number of elements in the receive buffer is greater than or
* equal to the specified threshold value.
*/
#define CY_I3C_INTR_RX_BUFFER_THLD_STS I3C_CORE_INTR_STATUS_RX_THLD_STS_Msk

/**
* The number of elements in the IBI buffer is greater than or
* equal to the specified threshold value.
*/
#define CY_I3C_INTR_IBI_BUFFER_THLD_STS I3C_CORE_INTR_STATUS_IBI_THLD_STS_Msk

/**
* The number of empty locations in the command queue is greater than or
* equal to the specified threshold value.
*/
#define CY_I3C_INTR_CMD_QUEUE_READY_STS I3C_CORE_INTR_STATUS_CMD_QUEUE_READY_STS_Msk

/**
* The number of elements in the response queue is greater than or
* equal to the specified threshold value.
*/
#define CY_I3C_INTR_RESP_READY_STS I3C_CORE_INTR_STATUS_RESP_READY_STS_Msk

/**
* The transfer is aborted.
*/
#define CY_I3C_INTR_TRANSFER_ABORT_STS I3C_CORE_INTR_STATUS_TRANSFER_ABORT_STS_Msk

/**
* The CCC registers are updated by the I3C Controller through CCC commands.
*/
#define CY_I3C_INTR_CCC_UPDATED_STS I3C_CORE_INTR_STATUS_CCC_UPDATED_STS_Msk

/**
* The dynamic address of the device is assigned through SETDASA or ENTDAA CCC
*/
#define CY_I3C_INTR_DYN_ADDR_ASSGN_STS I3C_CORE_INTR_STATUS_DYN_ADDR_ASSGN_STS_Msk

/**
* Error occurred in the transfer.
*/
#define CY_I3C_INTR_TRANSFER_ERR_STS I3C_CORE_INTR_STATUS_TRANSFER_ERR_STS_Msk

/**
* DEFTGT CCC is received.
*/
#define CY_I3C_INTR_DEFTGT_STS I3C_CORE_INTR_STATUS_DEFTGT_STS_Msk

/**
* The read request is received from the current controller; command queue is empty.
*/
#define CY_I3C_INTR_READ_REQ_RECV_STS I3C_CORE_INTR_STATUS_READ_REQ_RECV_STS_Msk

/**
* The IBI request initiated via TIR request register is addressed and status is updated.
*/
#define CY_I3C_INTR_IBI_UPDATED_STS I3C_CORE_INTR_STATUS_IBI_UPDATED_STS_Msk

/**
* The role of the controller is changed.
*/
#define CY_I3C_INTR_BUSOWNER_UPDATED_STS I3C_CORE_INTR_STATUS_BUSOWNER_UPDATED_STS_Msk

#if CY_IP_MXI3C_VERSION_MINOR == 1u
/**
* Target reset pattern detected.
*/
#define CY_I3C_INTR_TGT_RST_PATTERN_DET_STS I3C_CORE_INTR_STATUS_TGT_RST_PATTERN_DET_STS_Msk
/**
* Provides the list of allowed sources for target mode.
*/
#define CY_I3C_TGT_INTR_Msk (CY_I3C_INTR_CCC_UPDATED_STS | CY_I3C_INTR_DYN_ADDR_ASSGN_STS | \
                             CY_I3C_INTR_RESP_READY_STS | CY_I3C_INTR_READ_REQ_RECV_STS | \
                             CY_I3C_INTR_IBI_UPDATED_STS | CY_I3C_INTR_TGT_RST_PATTERN_DET_STS | CY_I3C_INTR_BUSOWNER_UPDATED_STS)
#else
/**
* Provides the list of allowed sources for target mode.
*/
#define CY_I3C_TGT_INTR_Msk (CY_I3C_INTR_CCC_UPDATED_STS | CY_I3C_INTR_DYN_ADDR_ASSGN_STS | \
                             CY_I3C_INTR_RESP_READY_STS | CY_I3C_INTR_READ_REQ_RECV_STS )

#endif

/** \} group_i3c_macros_intr_macros */

/**
* \defgroup group_i3c_macros_controller_status I3C Controller Status
* Macros to check current I3C controller status returned by
* \ref Cy_I3C_GetBusStatus function. Each I3C controller status is encoded
* in a separate bit, therefore multiple bits may be set to indicate the
* current status.
* \{
*/

/**
* The controller is busy executing operation started by \ref Cy_I3C_SendCCCCmd or
* \ref Cy_I3C_ControllerRead or \ref Cy_I3C_ControllerWrite or \ref Cy_I3C_ControllerStartEntDaa
* \ref Cy_I3C_ControllerSendHdrCmds.
*/
#define CY_I3C_CONTROLLER_BUSY                          (0x00010000UL)

/**
* The controller has currently performed a broadcast CCC write transfer
*/
#define CY_I3C_CONTROLLER_BROADCAST_CCC_WR_XFER         (0x00000001UL)

/**
* The controller has currently performed a directed CCC write transfer
*/
#define CY_I3C_CONTROLLER_DIRECTED_CCC_WR_XFER          (0x00000002UL)

/**
* The controller has currently performed a broadcast CCC read transfer
*/
#define CY_I3C_CONTROLLER_DIRECTED_CCC_RD_XFER          (0x00000004UL)

/**
* The controller has currently performed DAA
*/
#define CY_I3C_CONTROLLER_ENTDAA_XFER                   (0x00000008UL)

/**
* The controller has currently performed a private SDR write to an I3C Target
*/
#define CY_I3C_CONTROLLER_I3C_SDR_WR_XFER               (0x00000010UL)

/**
* The controller has currently performed a private SDR read from an I3C Target
*/
#define CY_I3C_CONTROLLER_I3C_SDR_RD_XFER               (0x00000020UL)

/**
* The controller has currently performed a private SDR read to an I2C Target
*/
#define CY_I3C_CONTROLLER_I2C_SDR_WR_XFER               (0x00000040UL)

/**
* The controller has currently performed a private SDR read from an I2C Target
*/
#define CY_I3C_CONTROLLER_I2C_SDR_RD_XFER               (0x00000080UL)

/**
* The controller has currently performed a private HDR write in DDR mode
*/
#define CY_I3C_CONTROLLER_HDR_DDR_WR_XFER               (0x00000100UL)

/**
* The controller has currently performed a private HDR read in DDR mode
*/
#define CY_I3C_CONTROLLER_HDR_DDR_RD_XFER               (0x00000200UL)

/**
* The controller has currently responded to a IBI request
*/
#define CY_I3C_CONTROLLER_IBI_XFER                      (0x00000400UL)

/**
* The controller is in HALT state due to error in the transfer
*/
#define CY_I3C_CONTROLLER_HALT_STATE                    (0x00000800UL) //This is the BUS_ERR - Ask

/**
* The transaction was aborted
*/
#define CY_I3C_CONTROLLER_XFER_ABORTED                  (0X00001000UL)

/** \} group_i3c_macros_controller_status */

/**
* \defgroup group_i3c_macros_target_status I3C Target Status
* Macros to check current I3C target status returned by
* \ref Cy_I3C_GetBusStatus function. Each I3C target status is encoded
* in a separate bit, therefore multiple bits may be set to indicate the
* current status.
*
* \note
* I3C supports only Primary Controller mode in PSE84A0. Secondary controller mode and Target mode are supported in PSE84B0.
*
* \{
*/

/**
* The controller has finished reading data from the target
*/
#define CY_I3C_TARGET_RD_CMPLT      (0x00002000UL)

/**
* The controller has finished writing data into the target
*/
#define CY_I3C_TARGET_WR_CMPLT      (0x00004000UL)

/** There is a read transaction in progress */
#define CY_I3C_TARGET_RD_BUSY       (0x00008000UL)

/** There is a write transaction in progress */
#define CY_I3C_TARGET_WR_BUSY       (0x00010000UL)

/** \} group_i3c_macros_target_status */

/**
* \defgroup group_i3c_macros_callback_events I3C Callback Events
* \{
* Macros to check I3C events passed by \ref cy_cb_i3c_handle_events_t callback.
* Each event is encoded in a separate bit, and therefore it is possible to
* notify about multiple events.
*/

/** The controller write started by \ref Cy_I3C_ControllerWrite is complete */
#define CY_I3C_CONTROLLER_WR_CMPLT_EVENT       (0x00000001UL)

/** The controller read started by \ref Cy_I3C_ControllerRead is complete */
#define CY_I3C_CONTROLLER_RD_CMPLT_EVENT       (0x00000002UL)

/** CY_I3C_CONTROLLER_WR_EARLY_TERMINATION_EVENT */
#define CY_I3C_CONTROLLER_WR_EARLY_TERMINATION_EVENT   (0x00000004UL)

/**
* Indicates the I3C hardware has detected an error.
*/

/** CY_I3C_CRC_ERROR_EVENT */
#define CY_I3C_CRC_ERROR_EVENT                    (0x00000008UL)
/** CY_I3C_PARITY_ERROR_EVENT */
#define CY_I3C_PARITY_ERROR_EVENT                 (0x00000010UL)
/** CY_I3C_FRAME_ERROR_EVENT */
#define CY_I3C_FRAME_ERROR_EVENT                  (0x00000020UL)
/** CY_I3C_BROADCAST_ADDR_NACK_ERROR_EVENT */
#define CY_I3C_BROADCAST_ADDR_NACK_ERROR_EVENT    (0x00000040UL)
/** CY_I3C_ADDR_NACK_ERROR_EVENT */
#define CY_I3C_ADDR_NACK_ERROR_EVENT              (0x00000080UL)
/** CY_I3C_BUFFER_OVERFLOW_ERROR_EVENT */
#define CY_I3C_BUFFER_OVERFLOW_ERROR_EVENT        (0x00000100UL)
/** CY_I3C_XFER_ABORTED_ERROR_EVENT */
#define CY_I3C_XFER_ABORTED_ERROR_EVENT           (0x00000200UL)
/** CY_I3C_I2C_TGT_WDATA_NACK_ERROR_EVENT */
#define CY_I3C_I2C_TGT_WDATA_NACK_ERROR_EVENT     (0x00000400UL)
/** CY_I3C_CONTROLLER_EARLY_TERMINATION_EVENT */
#define CY_I3C_CONTROLLER_EARLY_TERMINATION_EVENT (0x00000800UL)
/** CY_I3C_CONTROLLER_ERROR_CE0_EVENT */
#define CY_I3C_CONTROLLER_ERROR_CE0_EVENT         (0X00001000UL)

/** CY_I3C_CONTROLLER_ERR_EVENT */
#define CY_I3C_CONTROLLER_ERR_EVENT               (CY_I3C_CRC_ERROR_EVENT| CY_I3C_PARITY_ERROR_EVENT| CY_I3C_FRAME_ERROR_EVENT| \
                                                   CY_I3C_BROADCAST_ADDR_NACK_ERROR_EVENT| CY_I3C_ADDR_NACK_ERROR_EVENT| CY_I3C_BUFFER_OVERFLOW_ERROR_EVENT| \
                                                   CY_I3C_XFER_ABORTED_ERROR_EVENT| CY_I3C_I2C_TGT_WDATA_NACK_ERROR_EVENT| CY_I3C_CONTROLLER_ERROR_CE0| CY_I3C_PEC_ERROR_EVENT)

/** CY_I3C_TARGET_ERR_EVENT */
#define CY_I3C_TARGET_ERR_EVENT                   (CY_I3C_CRC_ERROR_EVENT| CY_I3C_PARITY_ERROR_EVENT| CY_I3C_FRAME_ERROR_EVENT| \
                                                   CY_I3C_BUFFER_OVERFLOW_ERROR_EVENT | CY_I3C_CONTROLLER_EARLY_TERMINATION_EVENT | CY_I3C_PEC_ERROR_EVENT)

/** The target device is assigned a dynamic address through SETDASA or ENTDAA or SETAASA CCC from the controller */
#define CY_I3C_TARGET_ASSIGNED_DYN_ADDR_EVENT     (0X00002000UL)

/**
* The controller has read all data out of the configured Read buffer.
* This event can be used to configure the next Read buffer. If the buffer
* remains empty, the CY_I3C_DEFAULT_TX bytes are returned to the controller.
*/

/** CY_I3C_TARGET_WR_BUFFER_NOT_CONFIGURED */
#define CY_I3C_TARGET_WR_BUFFER_NOT_CONFIGURED    (0x00004000UL)
/** CY_I3C_TARGET_MAX_RD_LEN_UPDT_EVENT */
#define CY_I3C_TARGET_MAX_RD_LEN_UPDT_EVENT       (0X00008000UL)
/** CY_I3C_TARGET_MAX_WR_LEN_UPDT_EVENT */
#define CY_I3C_TARGET_MAX_WR_LEN_UPDT_EVENT       (0X00010000UL)
/**
* Indicates the controller completed reading from the target (set by the controller NAK
* or Stop)
*/
#define CY_I3C_TARGET_RD_CMPLT_EVENT              (0x00020000UL)
/**
* Indicates the controller completed writing to the target (set by the controller Stop
* or Restart)
*/
#define CY_I3C_TARGET_WR_CMPLT_EVENT              (0x00040000UL)
/** One of the CCC register is updated by I3C Controller through CCC commands */
#define CY_I3C_TARGET_CCC_REG_UPDATED_EVENT       (0x00080000UL)
/** There is no valid command in the command queue */
#define CY_I3C_TARGET_NO_VALID_CMD_IN_CMDQ_EVENT  (0x00100000UL)
/**
* The data in Tx FIFO is not equal to the data length size of the command
* or the TX_START_THLD value or the Response queue is full
*/
#define CY_I3C_TARGET_DATA_NOT_READY_EVENT        (0x00200000UL)
/** DEFTGTS CCC is received */
#define CY_I3C_DEFTGT_EVENT                       (0x00400000UL)
/** Role of the controller changed from Controller to Target or vice-versa */
#define CY_I3C_CONTROLLER_ROLE_UPDATED_EVENT      (0x00800000UL)
/** Target reset pattern detected */
#define CY_I3C_TARGET_RESET_EVENT                 (0x01000000UL)
/** IBI not attempted by target as bus might be busy.*/
#define CY_I3C_TARGET_IBI_NOT_ATTEMPTED_EVENT     (0x02000000UL)
/** IBI Acknowledged by controller*/
#define CY_I3C_TARGET_IBI_ACKNOWLEDGED_EVENT      (0x04000000UL)
/** Controllership request accepted */
#define CY_I3C_TARGET_CR_ACCEPTED_EVENT           (0x04000000UL)
/** FOR TIR with data controller terminated before reading all the data */
#define CY_I3C_TARGET_IBI_EARLY_STOP_EVENT        (0x08000000UL)

/** PEC Error event*/
#define CY_I3C_PEC_ERROR_EVENT                    (0x10000000UL)


/** \} group_i3c_macros_callback_events */

/** \cond INTERNAL */

/* I3C Address slot mask */
#define CY_I3C_ADDR_SLOT_STATUS_MASK       3UL

/* COMMAND_QUEUE_PORT Register */
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_Pos 0UL
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_Msk 0x7UL
/* Transfer Command Structure */
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_TRANSFER_CMD 0x0UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TID_Pos 3UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TID_Msk 0x78UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_CMD_Pos 7UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_CMD_Msk 0x7F80UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_CP_Pos 15UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_CP_Msk 0x8000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_DEV_INDX_Pos 16UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_DEV_INDX_Msk 0x1F0000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_SPEED_Pos 21UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_SPEED_Msk 0xE00000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_DBP_Pos 25UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_DBP_Msk 0x2000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_ROC_Pos 26UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_ROC_Msk 0x4000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_SDAP_Pos 27UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_SDAP_Msk 0x8000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_RnW_Pos 28UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_RnW_Msk 0x10000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TGT_RST_Pos 29UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TGT_RST_Msk 0x20000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TOC_Pos 30UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_TOC_Msk 0x40000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_PEC_Pos 31UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_CMD_PEC_Msk 0x80000000UL
/* Transfer Argument Command Structure */
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_TRANSFER_ARG 0x01UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DB_Pos 8UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DB_Msk 0xFF00UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DATA_LENGTH_Pos 16UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DATA_LENGTH_Msk 0xFFFF0000UL
/* Short Data Argument Structure */
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_SHORT_DATA_ARG 0x02UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_BYTE_STRB_Pos 3UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_BYTE_STRB_Msk 0x38UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_0_Pos 8UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_0_Msk 0xFF00UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_1_Pos 16UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_1_Msk 0xFF0000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_2_Pos 24UL
#define I3C_CORE_COMMAND_QUEUE_PORT_SHORT_DATA_ARG_DATA_BYTE_2_Msk 0xFF000000UL
/* To select the valid data bytes of the Short Data Argument */
#define CY_I3C_BYTE_STROBE1 1U
#define CY_I3C_BYTE_STROBE2 3U
#define CY_I3C_BYTE_STROBE3 7U
/* Address Assignment Command Structure */
#define I3C_CORE_COMMAND_QUEUE_PORT_CMD_ATTR_ADDR_ASSGN_CMD 0x03UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_TID_Pos 0x3UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_TID_Msk 0x78UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_CMD_Pos 7UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_CMD_Msk 0x7F80UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_DEV_INDX_Pos 16UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_DEV_INDX_Msk 0x1F0000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_DEV_COUNT_Pos 21UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_DEV_COUNT_Msk 0x3E00000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_ROC_Pos 26UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_ROC_Msk 0x4000000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_TOC_Pos 30UL
#define I3C_CORE_COMMAND_QUEUE_PORT_ADDR_ASSGN_CMD_TOC_Msk 0x40000000UL
/*Target Mode Transmit Command Structure*/
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_DATA_LENGTH_Pos 16UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_DATA_LENGTH_Msk 0xFFFF0000UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_TID_Pos 3UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_TID_Msk 0x0000038UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_ATTR_Pos 0UL
#define I3C_CORE_COMMAND_QUEUE_PORT_TARGET_TRANSMIT_ATTR_Msk 0x00000007UL


/*  RESPONSE_QUEUE_PORT Register  */
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_DATA_LENGTH_Pos 0UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_DATA_LENGTH_Msk 0xFFFFUL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_CCCT_Pos 16UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_CCCT_Msk 0xFF0000UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_TID_Pos 24UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_TID_Msk 0xF000000UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_ERR_STS_Pos 28UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_ERR_STS_Msk 0xF0000000UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_CRC_ERROR 0x1UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_PARITY_ERROR 0x2UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_FRAME_ERROR 0x3UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_BROADCAST_ADDR_NACK_ERROR 0x4UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_ADDR_NACK_ERROR 0x5UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_BUFFER_OVERFLOW_ERROR 0x6UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_XFER_ABORTED_ERROR 0x8UL
#define I3C_CORE_CONTROLLER_RESPONSE_QUEUE_PORT_I2C_TGT_WDATA_NACK_ERROR 0x9UL


#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DATA_LENGTH_LSB_Pos 0UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DATA_LENGTH_LSB_Msk 0xFFUL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DATA_LENGTH_Pos 0UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DATA_LENGTH_Msk 0xFFFFUL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DEFINING_BYTE_Pos 8UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_DEFINING_BYTE_Msk 0xFF00UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_CCC_HDR_HEADER_Pos 16UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_CCC_HDR_HEADER_Msk 0xFF0000UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_TID_Pos 24UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_TID_Msk 0x7000000UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_RX_RSP_Pos 27UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_RX_RSP_Msk 0x8000000UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_ERR_STS_Pos 28UL
#define I3C_CORE_TARGET_RESPONSE_QUEUE_PORT_ERR_STS_Msk 0xF0000000UL

/* BCR Register */
#define CY_I3C_CORE_BCR_DEVICE_ROLE_Msk            (0xC0U)
#define CY_I3C_CORE_BCR_I3C_TARGET                 (0U << 6U)
#define CY_I3C_CORE_BCR_I3C_CONTROLLER             (1U << 6U)
#define CY_I3C_CORE_BCR_HDR_CAP_Msk                (0x20U)
#define CY_I3C_CORE_BCR_BRIDGE_Msk                 (0x10U)
#define CY_I3C_CORE_BCR_OFFLINE_CAP_Msk            (0x08U)
#define CY_I3C_CORE_BCR_IBI_PAYLOAD_Msk            (0x04U)
#define CY_I3C_CORE_BCR_IBI_REQ_CAP_Msk            (0x02U)
#define CY_I3C_CORE_BCR_MAX_DATA_SPEED_LIM_Msk     (0x01U)

/* LVR register */
#define CY_I3C_LVR_LEGACY_I2C_INDEX_MASK        (0xE0U)
#define CY_I3C_LVR_I2C_MODE_INDICATOR            (0x10U)

/* Dev Operation Mode values */
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEV_OPERATION_MODE_CONTROLLER   (0x0U)
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEV_OPERATION_MODE_TARGET    (0x1U)

/*Asynchronous timing control commands*/
#define CY_I3C_ENTER_ASYNC_MODE0   (0xDF)
#define CY_I3C_EXIT_ASYNC_MODES   (0xFF)

/* IBI Identifiers */
#define CY_I3C_HOT_JOIN_ADDR                        (0x02U)
#define CY_I3C_IBI_QUEUE_IBI_ADDR(x)                ((x) >> 1U)
#define CY_I3C_IBI_TYPE_HOT_JOIN(x)                    (CY_I3C_IBI_QUEUE_IBI_ADDR((x)) == CY_I3C_HOT_JOIN_ADDR && !((bool)((x) & CY_I3C_BIT(0U))))
#define CY_I3C_IBI_TYPE_CONTROLLERSHIP_REQUEST(x)        (CY_I3C_IBI_QUEUE_IBI_ADDR((x)) != CY_I3C_HOT_JOIN_ADDR && !((bool)((x) & CY_I3C_BIT(0U))))
#define CY_I3C_IBI_TYPE_TIR_REQUEST(x)                (CY_I3C_IBI_QUEUE_IBI_ADDR((x)) != CY_I3C_HOT_JOIN_ADDR && ((bool)((x) & CY_I3C_BIT(0U))))
#define CY_I3C_IBI_TIR_REQ_ID(x)                    ((((x) & CY_I3C_GENMASK(6U, 5U)) >> 5U) + ((x) & CY_I3C_GENMASK(4U, 0U)))

/* IBI Completion Status */
#define I3C_CORE_TGT_INTR_REQ_IBI_STS_IBI_ACK_BY_CONTROLLER       (0x1U)
#define I3C_CORE_TGT_INTR_REQ_IBI_STS_IBI_EARLY_TERMINATE_BY_CONTROLLER  (0x2U)
#define I3C_CORE_TGT_INTR_REQ_IBI_STS_IBI_NOT_ATTEMPTED       (0x3U)

/* Interrupt Mask */
#if CY_IP_MXI3C_VERSION_MINOR == 0u
#define CY_I3C_INTR_MASK ( I3C_CORE_INTR_STATUS_EN_TX_THLD_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_RX_THLD_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_IBI_THLD_STS_EN_Msk    | \
                           I3C_CORE_INTR_STATUS_EN_CMD_QUEUE_READY_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_RESP_READY_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_TRANSFER_ABORT_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_CCC_UPDATED_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_DYN_ADDR_ASSGN_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_TRANSFER_ERR_STS_EN_Msk    | \
                           I3C_CORE_INTR_STATUS_EN_DEFTGT_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_READ_REQ_RECV_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_IBI_UPDATED_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_BUSOWNER_UPDATED_STS_EN_Msk )
#else
#define CY_I3C_INTR_MASK ( I3C_CORE_INTR_STATUS_EN_TX_THLD_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_RX_THLD_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_IBI_THLD_STS_EN_Msk    | \
                           I3C_CORE_INTR_STATUS_EN_CMD_QUEUE_READY_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_RESP_READY_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_TRANSFER_ABORT_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_CCC_UPDATED_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_DYN_ADDR_ASSGN_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_TRANSFER_ERR_STS_EN_Msk    | \
                           I3C_CORE_INTR_STATUS_EN_DEFTGT_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_READ_REQ_RECV_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_IBI_UPDATED_STS_EN_Msk  | \
                           I3C_CORE_INTR_STATUS_EN_BUSOWNER_UPDATED_STS_EN_Msk | \
                           I3C_CORE_INTR_STATUS_TGT_RST_PATTERN_DET_STS_Msk )
#endif

/* I3C states */
#define CY_I3C_IDLE              (0x10000000UL)
#define CY_I3C_IDLE_MASK         (0x10000000UL)

/* Controller states */
#define CY_I3C_CONTROLLER_ACTIVE     (0X00100000UL)
#define CY_I3C_CONTROLLER_RX         (0x00100001UL)
#define CY_I3C_CONTROLLER_TX         (0x00100002UL)

/* Target states */
#define CY_I3C_TARGET_ACTIVE      (0x00001000UL)
#define CY_I3C_TARGET_RX          (0x00001001UL)
#define CY_I3C_TARGET_TX          (0x00001002UL)

/* FIFO size */
#define CY_FIFO_SIZE              (256UL)

#define CY_I3C_FIFO_SIZE           CY_FIFO_SIZE
#define CY_I3C_HALF_FIFO_SIZE     (CY_FIFO_SIZE / 2UL)

#define CY_I3C_DEFAULT_RETURN    (0xFFUL)

/* Convert the timeout in milliseconds to microseconds */
#define CY_I3C_CONVERT_TIMEOUT_TO_US(timeoutMs)     ((timeoutMs) * 1000UL)

/* I3C data rates */
#define CY_I3C_SDR_DATA_RATE            (12500000U)
#define CY_I3C_SDR1_DATA_RATE            (8000000U)
#define CY_I3C_SDR2_DATA_RATE            (6000000U)
#define CY_I3C_SDR3_DATA_RATE            (4000000U)
#define CY_I3C_SDR4_DATA_RATE            (2000000U)
#define CY_I3C_HDRDDR_DATA_RATE            (25000000U)
#define CY_I3C_BUS_I2C_FM_TLOW_MIN_NS    (1300U)
#define CY_I3C_BUS_I2C_FMP_TLOW_MIN_NS    (500U)
#define CY_I3C_BUS_THIGH_MAX_NS            (41U)
#define CY_I3C_SCL_I3C_TIMING_CNT_MIN    (5U)
#define CY_I3C_BUS_TLOW_OD_MIN_NS        (200U) /* minimum low period is 200ns */


/* I2C data rates max (Hz): standard, fast and fast plus modes */
#define CY_I3C_I2C_FM_DATA_RATE    (400000U)
#define CY_I3C_I2C_FMP_DATA_RATE   (1000000U)

#define CY_I3C_IS_MODE_VALID(mode)      ((CY_I3C_TARGET  == (mode)) || \
                                          (CY_I3C_CONTROLLER == (mode)))
#define CY_I3C_IS_BUS_MODE_VALID(mode)                 ((CY_I3C_BUS_PURE  == (mode)) || \
                                                         (CY_I3C_BUS_MIXED_FAST == (mode)) || \
                                                         (CY_I3C_BUS_MIXED_SLOW == (mode)))
#define CY_I3C_IS_BUFFER_DEPTH_VALID(buffer_depth)      ((CY_I3C_1_WORD_DEPTH  == (buffer_depth)) || \
                                                          (CY_I3C_4_WORD_DEPTH == (buffer_depth)) || \
                                                          (CY_I3C_8_WORD_DEPTH == (buffer_depth)) || \
                                                          (CY_I3C_16_WORD_DEPTH == (buffer_depth)) || \
                                                          (CY_I3C_32_WORD_DEPTH == (buffer_depth)) || \
                                                          (CY_I3C_64_WORD_DEPTH == (buffer_depth)))
#define CY_IS_I3C_ADDR_NOT_RESERVED(addr)               (0U != (((8U <= (addr)) &&((addr) <= 61U)) || ((63U <= (addr)) &&((addr) <= 93U)) || \
                                                                 ((95U <= (addr)) && ((addr) <= 109U)) || ((111U <= (addr)) &&((addr) <= 117U))|| \
                                                                 (119U == (addr))))
/* IC_xxx_BUF_DEPTH - 1 = 0xF */
#define CY_IS_I3C_QUEUE_THLD_VALID(thld)              ((thld) <= 0xFUL)
#define CY_IS_I3C_IBI_DATA_THLD_VALID(thld)           ((thld) <= 0xFUL && (thld) >= 0x1UL)
#define CY_IS_I3C_SDA_HOLD_TIME_VALID(time)           ((time) <= 0x7U)
#define CY_IS_I3C_BUS_FREE_TIME_VALID(time)           ((time) <= 0xFFFFU)
#define CY_IS_I3C_OD_CLK_CNT_VALID(cnt)               ((cnt) <= 0xFFU)
#define CY_IS_I3C_PP_CLK_CNT_VALID(cnt)               ((cnt) <= 0xFFU)
#define CY_IS_I2C_CLK_CNT_VALID(cnt)                  ((cnt) <= 0xFFU)
#define CY_IS_I3C_EXT_LCNT_VALID(cnt)                 ((cnt) <= 0xFFU)
#define CY_IS_I3C_EXT_TERMINATION_LCNT_VALID(cnt)     ((cnt) <= 0xFU)

#define CY_IS_I3C_I2C_ADDRESS_VALID(addr)             ((0x7FU > (addr)) && (0x00U < (addr)))

#define CY_IS_I3C_STATIC_ADDRESS_VALID(addr)          ((addr) < 0x7FU)
#define CY_IS_I3C_PID_VALID(pid)                      ((pid) <= 0xFFFFFFFFFFFFU)
#define CY_IS_I3C_DCR_VALID(dcr)                      ((dcr) <= 0xFFU)

#define CY_IS_I3C_DEVICE_ROLE_CAP_VALID(devRole)      ((CY_I3C_TARGET == (devRole)) || (CY_I3C_SECONDARY_CONTROLLER == (devRole)))

#define CY_IS_I3C_BUS_AVAIL_TIME_VALID(time)          ((time) <= 0xFFFFU)
#define CY_IS_I3C_BUS_IDLE_TIME_VALID(time)           ((time) <= 0xFFFFFU)

#define CY_I3C_INTR_VALID(intr, mask)                 (0UL == ((intr) & ((uint32_t) ~(mask))))

#define CY_I3C_IS_SDR_DATA_RATE_VALID(dataRateHz)     (((dataRateHz) > 0UL) && \
                                                      ((dataRateHz) <= CY_I3C_SDR_DATA_RATE))

#define CY_I3C_IS_HDR_DATA_RATE_VALID(dataRateHz)     (((dataRateHz) > 0UL) && \
                                                        ((dataRateHz) <= CY_I3C_HDRDDR_DATA_RATE))

#define CY_I3C_IS_TIMEOUT_VALID(timeoutMs)              ((timeoutMs) <= (0xFFFFFFFFUL / 1000UL))

#define CY_IS_I3C_ADDR_VALID(addr)              ((0U == ((addr) & 0x80U)))

#define CY_IS_I3C_BUFFER_VALID(buffer, size)    ( (NULL != (buffer)) && ((size) > 0UL) )

#define CY_I3C_IS_BUFFER_SIZE_VALID(size)      (((size) > 0UL) && \
                                                 ((size) <= CY_I3C_FIFO_SIZE) )


/* Default Values */

#define I3C_CORE_QUEUE_THLD_CTRL_DEF_VAL  (_VAL2FLD(I3C_CORE_QUEUE_THLD_CTRL_CMD_EMPTY_BUF_THLD, 1UL) | \
                                           _VAL2FLD(I3C_CORE_QUEUE_THLD_CTRL_RESP_BUF_THLD, 1UL) | \
                                           _VAL2FLD(I3C_CORE_QUEUE_THLD_CTRL_IBI_STATUS_THLD, 1UL))

#define I3C_CORE_DATA_BUFFER_THLD_CTRL_DEF_VAL (_VAL2FLD(I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD, 1UL) | \
                                                _VAL2FLD(I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD, 1UL) | \
                                                _VAL2FLD(I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_START_THLD, 1UL) | \
                                                _VAL2FLD(I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_START_THLD, 1UL))

#define MAX_I3C_TRANSACTION_TIMEOUT (5000000U)

#define MAX_I3C_DATA_LENGTH (I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DATA_LENGTH_Msk >> I3C_CORE_COMMAND_QUEUE_PORT_TRANSFER_ARG_DATA_LENGTH_Pos)

/** \endcond */

/** \} group_i3c_macros */

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_i3c_enums
* \{
*/

/** I3C status codes */
typedef enum
{
    /** Operation completed successfully */
    CY_I3C_SUCCESS = 0U,

    /** One or more of input parameters are invalid */
    CY_I3C_BAD_PARAM = (CY_I3C_ID| CY_PDL_STATUS_ERROR | 1U),

    /**
    * The controller is not ready to start a new transaction.
    * Either the controller is still processing a previous transaction or in the
    * controller-target mode, the target operation is in progress.
    */
    CY_I3C_CONTROLLER_NOT_READY = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 2U),

    /**
    * The controller failed to attach the target device to the bus
    * as there already exists maximum number of devices on the bus.
    */
    CY_I3C_CONTROLLER_MAX_DEVS_PRESENT = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 3U),

    /**
    * The controller rejected to attach an I2C device without 50ns Spike filter.
    */
    CY_I3C_CONTROLLER_BAD_I2C_DEVICE = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 4U),

    /**
    * Unsupported CCC command
    */
    CY_I3C_CONTROLLER_CCC_NOT_SUPPORTED =(CY_I3C_ID | CY_PDL_STATUS_ERROR | 5U),

    /**
    * SDR Controller Error Code CE0 for Illegally formatted CCC Response
    */
    CY_I3C_CONTROLLER_ERROR_CE0 = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 6U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * CRC Error
    */
    CY_I3C_CONTROLLER_CRC_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 7U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * Parity Error
    */
    CY_I3C_CONTROLLER_PARITY_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 8U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * Frame Error
    */
    CY_I3C_CONTROLLER_FRAME_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 9U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * Broadcast Address NACK Error
    */
    CY_I3C_CONTROLLER_BROADCAST_ADDR_NACK_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 10U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * Address NACK Error - Target NACKs for the dynamic address assignment during
    * ENTDAA process.
    */
    CY_I3C_CONTROLLER_ADDR_NACK_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 11U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * TX/RX Buffer Overflow Error - Only for HDR Transfers
    */
    CY_I3C_CONTROLLER_BUFFER_OVERFLOW_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 12U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * Transfer Aborted Error
    */
    CY_I3C_CONTROLLER_XFER_ABORTED_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 13U ),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * I2C Target Write Data NACK Error
    */
    CY_I3C_CONTROLLER_I2C_TGT_WDATA_NACK_ERROR = ( CY_I3C_ID | CY_PDL_STATUS_ERROR | 14U ),

    /** The controller NACKed the IBI */
    CY_I3C_CONTROLLER_IBI_NACK = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 15U),

    /** The controller ACKed the Controllership Request IBI */
    CY_I3C_CONTROLLER_MR_IBI_ACK = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 16U),

    /** The controller ACKed the Target Interrupt Request IBI */
    CY_I3C_CONTROLLER_SIR_IBI_ACK = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 17U),

    /** The controller ACKed the Hot-join IBI */
    CY_I3C_CONTROLLER_HOTJOIN_IBI_ACK = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 18U),

    /** Free address unavailable */
    CY_I3C_CONTROLLER_FREE_ADDR_UNAVAIL = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 19U),

    /** The device is not HDR capable */
    CY_I3C_NOT_HDR_CAP = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 20U),

    /** The buffer size is greater than the FIFO size */
    CY_I3C_BAD_BUFFER_SIZE = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 21U),

    /** The secondary controller responded with incorrect address to GETACCCR CCC */
    CY_I3C_ADDR_MISMATCH = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 22U),

    /** The device is not yet assigned a dynamic address */
    CY_I3C_ADDR_INVALID = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 23U),

    /** In Target mode of operation, the Controller has disabled TIR through DISEC */
    CY_I3C_SIR_DISABLED = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 24U),

    /** In Target mode of operation, the Controller has disabled MR through DISEC */
    CY_I3C_CR_DISABLED = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 25U),

    /** The Target device failed to issue IBI */
    CY_I3C_IBI_NOT_ATTEMPTED = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 26U),

    /** There are no secondary controller devices on the bus */
    CY_I3C_NO_SECONDARY_CONTROLLER_DEVICES = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 27U),

    /** The target device requested generation of hot-join event generation */ //tbd - provide more clarity in the comment
    CY_I3C_BAD_EVENT_REQ = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 28U),

    /** The device is not a secondary controller */
    CY_I3C_NOT_SECONDARY_CONTROLLER = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 29U),

    /** No response was received, connection timeout */
    CY_I3C_TIMEOUT = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 30U),

    /**
    * Error Type of the processed command received in Response Data Structure:
    * PEC Error
    */
    CY_I3C_CONTROLLER_PEC_ERROR = (CY_I3C_ID | CY_PDL_STATUS_ERROR | 31U),

} cy_en_i3c_status_t;

/** I3C Operation Modes
*
* \note
*I3C supports only Primary Controller mode in PSE84A0. Secondary controller mode and Target mode are supported in PSE84B0.
*
*/
typedef enum
{
    CY_I3C_TARGET                   = 0U,    /**< Configures I3C for Target operation */
    CY_I3C_SECONDARY_CONTROLLER        = 1U,    /**< Configures I3C for Secondary Controller operation */
    CY_I3C_CONTROLLER                  = 2U,    /**< Configures I3C for Main Controller-operation */
} cy_en_i3c_mode_t;

/** I3C Bus Modes */
typedef enum
{
    CY_I3C_BUS_PURE,        /**< Only I3C devices are connected to the bus. No limitation expected */
    CY_I3C_BUS_MIXED_FAST,  /**< I2C devices with 50ns spike filter are present on the bus.
                                 High SCL pulse has to stay below 50ns when transmitting I3C frames */
    CY_I3C_BUS_MIXED_SLOW,  /**< I2C devices without 50ns spike filter are present on the bus */
    CY_I3C_BUS_MODE_NOT_APPLICABLE,  /**< Only for I3C Target configuration */
} cy_en_i3c_bus_mode_t;

/** I3C Address Slot Statuses */
typedef enum
{
    CY_I3C_ADDR_SLOT_FREE,              /**< Address is free */
    CY_I3C_ADDR_SLOT_RSVD,              /**< Address is reserved */
    CY_I3C_ADDR_SLOT_I2C_DEV,           /**< Address is assigned to an I2C device */
    CY_I3C_ADDR_SLOT_I3C_DEV,           /**< Address is assigned to an I3C device */
}cy_en_i3c_addr_slot_status_t;


/** I3C IBI Types */
typedef enum
{
    CY_I3C_IBI_HOTJOIN,                 /**< IBI Hot join Request */
    CY_I3C_IBI_SIR,                     /**< IBI Target Interrupt Request */
    CY_I3C_IBI_CONTROLLER_REQ,          /**< IBI Controller ownership Request */
} cy_en_i3c_ibi_type_t;

/** I3C Transaction IDs for HDR and SDR commands */
typedef enum
{
    CY_I3C_CONTROLLER_SDR_WRITE_TID  = 1U,     /**< TID for SDR Write Transfer */
    CY_I3C_CONTROLLER_SDR_READ_TID   = 2U,    /**< TID for SDR Read Transfer */
    CY_I3C_CONTROLLER_HDR_WRITE_TID  = 3U,    /**< TID for HDR Write Transfer */
    CY_I3C_CONTROLLER_HDR_READ_TID   = 4U,    /**< TID for HDR Read Transfer */
}cy_en_i3c_tid_t;

/** I3C Mode, SDR and HDR transfer speeds */
typedef enum
{
    CY_I3C_SDR0     = 0U,         /**< I3C mode transfer speed - SDR0*/
    CY_I3C_SDR1     = 1U,         /**< I3C mode transfer speed - SDR1*/
    CY_I3C_SDR2     = 2U,         /**< I3C mode transfer speed - SDR2*/
    CY_I3C_SDR3     = 3U,         /**< I3C mode transfer speed - SDR3*/
    CY_I3C_SDR4     = 4U,         /**< I3C mode transfer speed - SDR4*/
    CY_I3C_HDR_DDR  = 6U,         /**< I3C mode transfer speed - HDR-DDR */
}cy_en_i3c_data_speed_t;

/** I2C Mode, SDR transfer speeds */
typedef enum
{
    CY_I3C_FMP_I2C  = 0U,      /**< I2C mode transfer speed - Fast Mode Plus */
    CY_I3C_FM_I2C   = 1U,      /**< I2C mode transfer speed - Fast Mode */
}cy_en_i2c_data_speed_t;

/** I3C buffer depths */
typedef enum
{
    CY_I3C_1_WORD_DEPTH = 0U,    /**< Buffer depth of 1 word */
    CY_I3C_4_WORD_DEPTH = 1U,    /**< Buffer depth of 4 words */
    CY_I3C_8_WORD_DEPTH = 2U,    /**< Buffer depth of 8 words */
    CY_I3C_16_WORD_DEPTH = 3U,    /**< Buffer depth of 16 words */
    CY_I3C_32_WORD_DEPTH = 4U,    /**< Buffer depth of 32 words */
    CY_I3C_64_WORD_DEPTH = 5U,    /**< Buffer depth of 64 words */
}cy_en_i3c_buffer_depth_t;

/** I3C Target Reset */
typedef enum
{
    CY_I3C_NO_RESET = 0U,            /**< No Reset on Target Reset Pattern */
    CY_I3C_PERIPHERAL_RESET = 1U,    /**< Reset the I3C Peripheral Only */
    CY_I3C_CHIP_RESET = 2U,          /**< Reset the Whole Target */
}cy_en_i3c_target_reset_t;


/** I3C Activity states specified by ENTAS(x) CCC*/
typedef enum
{
    ActivityState0,  /**< Activity State 0 */
    ActivityState1,  /**< Activity State 1 */
    ActivityState2,  /**< Activity State 2 */
    ActivityState3,  /**< Activity State 3 */
} cy_en_i3c_activity_states_t;

/** \} group_i3c_enums */

/*******************************************************************************
*                              Type Definitions
*******************************************************************************/

/**
* \addtogroup group_i3c_data_structures
* \{
*/

/**
* I3C device IBI structure.
* Defines an IBI event.
*/
typedef struct cy_stc_i3c_ibi
{
    /** IBI event type */
    cy_en_i3c_ibi_type_t event;

    /** Address of the device requesting IBI */
    uint8_t targetAddress;

    /** IBI Status. Indicates the controller response for the received IBI */
    uint32_t status;

    /** IBI Payload size. Indicates the size of the received IBI Payload */
    uint8_t payloadSize;

    /** Below attributes are used only in target mode operations. */

    /** IBI Payload Data. Indicates the IBI Payload, For I3C Target mode max 4 bytes supported */
    uint8_t *payload;

    /** IBI Mandatory Data Byte(MDB). To be sent after IBI */
    uint8_t mdb;
}cy_stc_i3c_ibi_t;

/** I3C CCC response structure for Target mode*/
typedef struct cy_stc_i3c_target_ccc_resp
{
    /** CCC command id */
    uint8_t cmd;

    /** Defining Byte */
    uint8_t db;

    /** data length */
    uint8_t len;

    /** Transaction type receive response */
    bool rxRsp;
}cy_stc_i3c_target_ccc_resp_t;

/**
* Provides the typedef for the callback function called in the
* \ref Cy_I3C_Interrupt to notify the user about occurrences of
* \ref group_i3c_macros_callback_events.
*/
typedef void (* cy_cb_i3c_handle_events_t)(uint32_t event);

/**
* Provides the typedef for the callback function called in the
* \ref Cy_I3C_Interrupt to notify ccc response received by target.
*/
typedef void (* cy_cb_i3c_handle_ccc_response_t)(cy_stc_i3c_target_ccc_resp_t *cccData);

/**
* Provides the typedef for the callback function called in the
* \ref Cy_I3C_Interrupt to notify the user about occurrences of
* \ref group_i3c_macros_callback_events.
*/
typedef void (* cy_cb_i3c_handle_ibi_t)(cy_stc_i3c_ibi_t *event);

/**
* I2C device structure.
* Defines an I2C device.
* It is mandatory to provide I2C device static address and lvr information.
*/
typedef struct cy_stc_i2c_device
{
    /** Static address of the I2C device */
    uint8_t staticAddress;

    /** Legacy Virtual Register */
    uint8_t lvr;
} cy_stc_i2c_device_t;

/**
* I3C device structure.
* Defines an I3C device.
* StaticAddress of the I3C device if provided will be used by the controller
* to initiate the dynamic address assignment procedure through SETDASA.
* Desired I3C dynamic address to be used can be provided, but if set to zero,
* available free address will be assigned to the device by the controller.
*/
typedef struct cy_stc_i3c_device
{
    /** 48 bit provisional ID of I3C device */
    uint64_t provisionalID;

    /** Device Characteristic Register of I3C device */
    uint8_t dcr;

    /** Bus Characteristic Register of I3C device */
    uint8_t bcr;

    /** Static address of the I3C device if used */
    uint8_t staticAddress;

    /**
    * Desired dynamic address for I3C device.
    * If set to zero, available free address will be assigned by I3C controller.
    */
    uint8_t dynamicAddress;

    /** IBI payload length in bytes of target devices*/
    uint8_t ibipayloadSize;

    /** Max private SDR read length in bytes */
    uint16_t mrl;

    /** Max private SDR write length in bytes */
    uint16_t mwl;

    /** Max read speed information */
    uint8_t maxReadDs;

    /** Max write speed information */
    uint8_t maxWriteDs;

    /** Max read turn-around time in micro -seconds */
    uint8_t maxReadTurnaround[3U];

    /** Supported HDR modes */
    uint8_t HDRCap;

    /** Supports Asynchronous timing mode0 */
    bool ATM0Supported;

    /** Packet Error Check Enabled */
    bool PECEnabled;

    /**
    * Support for HDR Mode.
    * true: HDR modes supported. HDRCap member for the device is valid.
    * false: HDR modes are not supported.
    */
    bool hdrSupport;

    /**
    * Max data speed limitation.
    * true: Limitation on max data speed. maxReadDs, maxWriteDs, maxReadTurnaround members for the device are valid
    * false: No limitation on max data speed
    */
    bool speedLimit;
}cy_stc_i3c_device_t;

/** A local list of devices on the bus */
typedef struct cy_stc_i3c_controller_devlist
{
    /** Identifies the device type */
    bool i2c;

    /** I2C/I3C device descriptor */
    union
    {
        cy_stc_i3c_device_t i3cDevice;
        cy_stc_i2c_device_t i2cDevice;
    };
}cy_stc_i3c_controller_devlist_t;

/** Device Characteristic Table structure */
typedef struct cy_stc_i3c_dev_char
{
    uint32_t LSBProvisionalID; /**< The LSB 32-bit value of provisional ID */
    uint32_t MSBProvisionalID; /**< The MSB 16-bit value of provisional ID */
    uint32_t DCR_BCR;          /**< DCR [7:0] and BCR [15:8] of the I3C device */
    uint32_t dynamicAddress;   /**< Dynamic address [7:0] of the I3C device */
}cy_stc_i3c_dev_char_t;

/** 64-bit CCC structure */
typedef struct cy_stc_i3c_ccc
{
    uint32_t cmdHigh;     /**< cmdHigh */
    uint32_t cmdLow;      /**< cmdLow */
}cy_stc_i3c_ccc_t;

/** I3C bus configuration structure */
typedef struct cy_stc_i3c_config
{
    /** Specifies the mode of I3C controller operation */
    cy_en_i3c_mode_t i3cMode;

    /** Specifies the mode of I3C bus operation */
    cy_en_i3c_bus_mode_t i3cBusMode;

    /** Use the SDMA for Rx/Tx */
    bool useDma;

    /**
    * True - Enables the user to configure data rate related parameters for Controller Mode
    */
    bool manualDataRate;

    /** The frequency of the clock connected to the I3C block in Hz. */
    uint32_t i3cClockHz;

    /** The desired I3C data Rate in Hz. */
    uint32_t i3cSclRate;

    /** Opendrain data rate in Hz. */
    uint32_t openDrainSclRate;

    /** Specifies the number of empty locations(or above) in the Transmit FIFO that triggers the Transmit Buffer Threshold Status interrupt */
    cy_en_i3c_buffer_depth_t txEmptyBufThld;

    /** Specifies the number of entries (or above) in the Receive FIFO that triggers the Receive Buffer Threshold Status interrupt */
    cy_en_i3c_buffer_depth_t rxBufThld;

    /**
    * Controller Mode : Specifies the number of Transmit FIFO filled locations count that triggers the transmission.
    *  Target Mode : Specifies the number of Transmit FIFO filled locations count that triggers the transmission.
    */
    cy_en_i3c_buffer_depth_t txBufStartThld;

    /**
    * Controller Mode : Specifies the number of empty locations count in the Receive FIFO that triggers the reception.
    *  Target Mode : Specifies the number of empty locations count in the Receive FIFO that triggers the transmission.
    */
    cy_en_i3c_buffer_depth_t rxBufStartThld;

    /** Below members are only applicable for the Controller mode */

    /**
    * True - I3C broadcast address (0x7E) is used for private transfer
    */
    bool ibaInclude;

    /** Specifies whether the Controller ACK/NACK the Hot-Join request from Target */
    bool hotJoinCtrl;

    /** Specifies the device Dynamic Address */
    uint8_t dynamicAddr;

    /** Specifies the number of empty locations(or greater) in the Command Queue that triggers the Command Queue Ready Status interrupt */
    uint32_t cmdQueueEmptyThld;

    /** Specifies the number of entries(or greater) in the Response Queue that triggers the Response Queue Ready Status interrupt */
    uint32_t respQueueThld;

    /** Specifies the number of IBI status entries(or greater) in the IBI Queue that triggers the IBI Buffer Threshold Status interrupt */
    uint32_t ibiQueueThld;

    /** Specifies IBI data segment size in words (4 bytes) that enables the slicing of the incoming IBI data and generate individual status and thereby promotes the cut-through operation in reading out the IBI data. */
    uint32_t ibiDataThld;

    /** SDA hold time (in terms of number of I3C block clock cycles) of the transmit data with respect to the SCL edge in FM, FM+, SDR and DDR speed mode of operations */
    uint8_t sdaHoldTime;

    /**  Specifies    the I3C bus free count value */
    uint16_t busFreeTime;

    /* For Manual Data Rate Control */

    /** I3C Open Drain low count value */
    uint8_t openDrainLowCnt;

    /** I3C Open Drain high count value */
    uint8_t openDrainHighCnt;

    /** I3C Push Pull low count value */
    uint8_t pushPullLowCnt;

    /**  I3C Push Pull high count value */
    uint8_t pushPullHighCnt;

    /**  I2C FM Mode low count value */
    uint8_t i2cFMLowCnt;

    /** I2C FM Mode high count value */
    uint8_t i2cFMHighCnt;

    /** I2C FM Plus Mode low count value */
    uint8_t i2cFMPlusLowCnt;

    /** I2C FM Plus Mode high count value */
    uint8_t i2cFMPlusHighCnt;

    /** I3C Extended Low Count for SDR1 Mode */
    uint8_t extLowCnt1;

    /** I3C Extended Low Count for SDR2 Mode */
    uint8_t extLowCnt2;

    /** I3C Extended Low Count for SDR3 Mode */
    uint8_t extLowCnt3;

    /** I3C Extended Low Count for SDR4 Mode */
    uint8_t extLowCnt4;

    /** I3C Read Termination Bit Low count */
    uint8_t extTerminationLowCnt;

    /** Below members are only applicable for the Target mode */

    /**  Specifies whether the target uses adaptive I2C I3C mode.
    * It is required to be set only if the device is not aware of the type of the bus to which the target controller is connected
    */
    bool adaptiveI2CI3C;

    /** The static address of the I3C Target Device, if present */
    uint8_t staticAddress;

    /** The Provisional ID of the I3C Target Device */
    uint64_t pid;

    /** The device characteristic value of the I3C Target Device */
    uint8_t dcr;

    /**
    * Max data speed limitation.
    * True: Limitation on max data speed. maxReadDs, maxWriteDs, maxReadTurnaround members for the device are valid
    * False: No limitation on max data speed
    */
    bool speedLimit;

    /**
    * SDR only or SDR and HDR capable
      True: SDR and HDR
      False: SDR only
    */
    bool hdrCapable;

    /** Specifies the Device Role field in Bus Characteristic Register */
    cy_en_i3c_mode_t deviceRoleCap;

    /**
    * Specifies whether the Hot-Join Request Interrupts are allowed on the I3C bus or not
    * When disabled the Target will not initiate Hot-Join and will take part in Address Assignment without initiating Hot-Join
    */
    bool hotjoinEnable;

    /** Specifies the I3C bus available count value */
    uint16_t busAvailTime;

    /** Specifies the I3C bus idle count value */
    uint32_t busIdleTime;

} cy_stc_i3c_config_t;

/** I3C CCC command payload structure */
typedef struct cy_stc_i3c_ccc_payload
{
    /** Payload length */
    uint16_t len;

    /** Payload data */
    void *data;
} cy_stc_i3c_ccc_payload_t;

/** I3C CCC command structure */
typedef struct cy_stc_i3c_ccc_cmd
{
    /** CCC command id */
    uint8_t cmd;

    /** Defining Byte Present*/
    bool dbp;

    /** Defining Byte */
    uint8_t db;

    /** CCC command payload or NULL */
    cy_stc_i3c_ccc_payload_t *data;

    /** Destination address */
    uint8_t address;
}cy_stc_i3c_ccc_cmd_t;

/** I3C Controller information */
typedef struct cy_stc_i3c_controller
{
    /** Two bits per address to depict the status of the addresses - 8*4*8 */
    unsigned long addrslotsStatusArray[((CY_I3C_MAX_ADDR + 1U) * 2U) / CY_I3C_BITS_PER_LONG];

    /** immediate last address, from the address list, assigned as dynamic address to the target device  */
    uint8_t lastAddress;

    /** Index of the free position with respect to the Device Address Table */
    uint32_t freePos;

    /** The number of devices on the bus */
    uint32_t devCount;

    /** Count of I2C devices on the bus */
    uint32_t i2cDeviceCount;

    /** Number of dynamically addressed devices */
    uint32_t dynAddrDevCount;
}cy_stc_i3c_controller_t;

/** I3C HDR command Structure */
typedef struct cy_stc_i3c_hdr_cmd
{
    /**
    * Command opcode. Bit 7 encodes the direction of the data transfer, if
    * set this is a read, otherwise this is a write.
    */
    uint8_t code;

    /** Number of data words (a word is 16bits wide) to transfer */
    uint32_t ndatawords;

    /** Input/Output buffer */
    union
    {
        uint16_t *in;
        const uint16_t *out;
    }data;
}cy_stc_i3c_hdr_cmd_t;


/**
* I3C context structure.
* All fields for the context structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in function calls. Firmware must
* ensure that the defined instance of this structure remains in scope
* while the drive is in use.
*/
typedef struct cy_stc_i3c_context
{
    /** \cond INTERNAL */

    volatile uint32_t state;    /**< The driver state */
    cy_en_i3c_mode_t i3cMode;   /** Specifies the mode of i3c controller operation */
    cy_en_i3c_bus_mode_t i3cBusMode;     /** Specifies the mode of i3c bus operation */
    bool Enabled;     /** Specifies whether the I3C is enabled for operations. */

    uint32_t i3cSclRate;
    uint32_t i3cClockHz;

    uint32_t openDrainSclRate;    /**< Opendrain data rate in Hz */

    volatile uint32_t controllerStatus; /**< The controller status */

    uint8_t  *controllerBuffer;     /**< The pointer to the controller buffer (either for a transmit or a receive operation) */
    uint32_t  controllerBufferSize;         /**< The current controller buffer size */
    volatile uint32_t controllerBufferIdx;  /**< The current location in the controller buffer */
    volatile uint8_t destDeviceAddr; /**< The destination device address in the transfers */

    volatile uint32_t targetStatus;       /**< The target status */
    volatile bool     targetRdBufEmpty;   /**< Tracks target Read buffer empty event */

    uint8_t  *targetTxBuffer;             /**< The pointer to the target transmit buffer (a controller reads from it) */
    uint32_t  targetTxBufferSize;         /**< The current target transmit buffer size */
    volatile uint32_t targetTxBufferIdx;  /**< The current location in the target buffer */
    volatile uint32_t targetTxBufferCnt;  /**< The number of transferred bytes */

    uint8_t  *targetRxBuffer;             /**< The pointer to the target receive buffer (a controller writes into it) */
    uint32_t  targetRxBufferSize;         /**< The current target receive buffer size */
    volatile uint32_t targetRxBufferIdx;  /**< The current location in the target buffer */
    volatile uint32_t targetRxBufferCnt;

    cy_stc_i3c_controller_t i3cController;       /**< I3C Controller bus details */

    cy_stc_i3c_config_t dsConfig;         /**< I3C Config for DS wake up restore */
    uint32_t intr_mask;                   /**< Interrupt mask for DS wake up restore */
    cy_stc_i3c_controller_devlist_t devList[CY_I3C_MAX_DEVS]; /**< The list of devices on the bus */

    cy_stc_i3c_hdr_cmd_t *hdrCmd; /** <Maintains the HDR command sent */

    uint8_t deftgts_count; /** < Maintains count of targets received during DEFTGTS CCC */

    /**
    * The pointer to an event callback that is called when any of
    * \ref group_i3c_macros_callback_events occurs
    */
    cy_cb_i3c_handle_events_t cbEvents;

    /**
    * The pointer to a ccc response event callback that is called when target gets ccc response.
    */
    cy_cb_i3c_handle_ccc_response_t cccRespEvents;

    /**
    * The pointer to an event callback that is called when any of
    * \ref group_i3c_macros_ibi_events occurs
    */
    cy_cb_i3c_handle_ibi_t    cbIbi;

    /*Asynchronous Timing Mode0 Enabled*/
    bool ATM0Enabled;

    /*Packet Error Check Enabled*/
    bool PECEnabled;

    /** Specifies the reset mode to be performed on receiving target reset pattern. */
    cy_en_i3c_target_reset_t resetMode;

    /** \endcond */
} cy_stc_i3c_context_t;

/** The I3C Controller transfer structure */
typedef struct cy_stc_i3c_controller_xfer_config
{
    /** The 7-bit right justified target address to communicate with */
    uint8_t  targetAddress;

    /**
    * The pointer to the buffer for data to read from the target or
    * data to write into the target
    */
    uint8_t  *buffer;

    /** The size of the buffer */
    uint32_t bufferSize;

    /** toc */
    bool toc;
} cy_stc_i3c_controller_xfer_config_t;

/** \} group_i3c_data_structures */


/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_i3c_general_functions
* \{
*/
cy_en_i3c_status_t Cy_I3C_Init(I3C_CORE_Type *base, cy_stc_i3c_config_t const *config, cy_stc_i3c_context_t *context);
void Cy_I3C_DeInit(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
void Cy_I3C_Enable(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
void Cy_I3C_Disable(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
void Cy_I3C_Resume(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
bool Cy_I3C_IsBusBusy(I3C_CORE_Type const *base);
bool  Cy_I3C_IsController(I3C_CORE_Type const *base);
cy_en_i3c_status_t Cy_I3C_Reset(I3C_CORE_Type *base, cy_stc_i3c_config_t const *config, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_SoftReset(I3C_CORE_Type const *base);
cy_en_i3c_mode_t Cy_I3C_GetMode(I3C_CORE_Type const *base);
void Cy_I3C_Interrupt (I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
void Cy_I3C_RegisterEventCallback(I3C_CORE_Type const *base, cy_cb_i3c_handle_events_t callback, cy_stc_i3c_context_t *context);
void Cy_I3C_RegisterIbiCallback (I3C_CORE_Type const *base, cy_cb_i3c_handle_ibi_t callback, cy_stc_i3c_context_t *context);

/** \} group_i3c_general_functions */

/**
* \addtogroup group_i3c_controller_functions
* \{
*/
cy_en_i3c_status_t Cy_I3C_ControllerAttachI2CDevice(I3C_CORE_Type *base, cy_stc_i2c_device_t *i2cDevice, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerDetachI2CDevice(I3C_CORE_Type *base, cy_stc_i2c_device_t *i2cDevice, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerAttachI3CDevice(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDevice, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerDetachI3CDevice(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDevice, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_GetI2CDeviceCount(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_GetI3CDeviceCount(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_SetDataRate(I3C_CORE_Type *base, uint32_t dataRateHz, uint32_t i3cClockHz, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_GetDataRate(I3C_CORE_Type const *base, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerGetI2CDevices(I3C_CORE_Type *base, cy_stc_i2c_device_t *i2cDeviceList, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerGetI3CDevices(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDeviceList, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerGetFreeDeviceAddress(I3C_CORE_Type *base, uint8_t *address, cy_stc_i3c_context_t *context);
bool Cy_I3C_isCCCCmdSupported(I3C_CORE_Type *base, uint8_t cccCmd);
cy_en_i3c_status_t Cy_I3C_SendCCCCmd(I3C_CORE_Type *base, cy_stc_i3c_ccc_cmd_t *cccCmd, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_DisableDeviceIbi(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDevice, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_EnableDeviceIbi(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDevice, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerWrite(I3C_CORE_Type *base, cy_stc_i3c_controller_xfer_config_t *xferConfig, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerRead (I3C_CORE_Type *base, cy_stc_i3c_controller_xfer_config_t* xferConfig, cy_stc_i3c_context_t *context);
void Cy_I3C_ControllerAbortTransfer(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerWriteByte(I3C_CORE_Type *base, uint8_t targetAddress, int8_t data, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerReadByte(I3C_CORE_Type *base, uint8_t targetAddress, uint8_t *data, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_GetBusStatus(I3C_CORE_Type const *base, cy_stc_i3c_context_t const *context);
cy_en_i3c_status_t Cy_I3C_ControllerStartEntDaa(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_SetDASA(I3C_CORE_Type *base, cy_stc_i3c_ccc_cmd_t *cccCmd, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_SetAASA(I3C_CORE_Type *base, cy_stc_i3c_device_t *i3cDevice, uint8_t i3cDeviceCount, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerSendHdrCmds(I3C_CORE_Type *base, uint8_t targetAddress, cy_stc_i3c_hdr_cmd_t *hdrCmd, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerWriteDMA(I3C_CORE_Type *base, uint8_t targetAddress, uint32_t Datalength, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ControllerReadDMA(I3C_CORE_Type *base, uint8_t targetAddress, uint32_t Datalength, cy_stc_i3c_context_t *context);
#if CY_IP_MXI3C_VERSION_MINOR == 1u || defined(CY_DOXYGEN)
cy_en_i3c_status_t Cy_I3C_GetIbiPayload(I3C_CORE_Type *base, uint8_t *buffer, uint32_t size, cy_stc_i3c_context_t *context);
bool CY_I3C_isIbiPayloadEnabled(I3C_CORE_Type *base, uint8_t targetAddress, cy_stc_i3c_context_t *context);
#endif

/** \} group_i3c_controller_functions */


/**
* \addtogroup group_i3c_target_functions
* \{
*/
#if CY_IP_MXI3C_VERSION_MINOR == 1u || defined(CY_DOXYGEN)
cy_en_i3c_status_t Cy_I3C_TargetGetDynamicAddress(I3C_CORE_Type const *base, uint8_t *address, cy_stc_i3c_context_t const *context);
uint32_t Cy_I3C_TargetGetMaxReadLength(I3C_CORE_Type const *base, cy_stc_i3c_context_t const *context);
uint32_t Cy_I3C_TargetGetMaxWriteLength(I3C_CORE_Type const *base, cy_stc_i3c_context_t const *context);
cy_en_i3c_status_t Cy_I3C_TargetGenerateIbi(I3C_CORE_Type *base, cy_stc_i3c_ibi_t *ibitype, cy_stc_i3c_context_t *context);
void Cy_I3C_TargetConfigReadBuf (I3C_CORE_Type *base, uint8_t *buffer, uint32_t size, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_TargetGetReadTransferCount (I3C_CORE_Type const *base, cy_stc_i3c_context_t const *context);
void Cy_I3C_TargetConfigWriteBuf(I3C_CORE_Type const *base, uint8_t *buffer, uint32_t size, cy_stc_i3c_context_t *context);
uint32_t Cy_I3C_TargetGetWriteTransferCount (I3C_CORE_Type const *base, cy_stc_i3c_context_t const *context);
cy_en_i3c_status_t Cy_I3C_ConfigureVendorCCC0(I3C_CORE_Type *base, cy_stc_i3c_ccc_cmd_t* cccCmd, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_ConfigureVendorCCC1(I3C_CORE_Type *base, cy_stc_i3c_ccc_cmd_t* cccCmd, cy_stc_i3c_context_t *context);
void Cy_I3C_RegisterCCCRespCallback(I3C_CORE_Type const *base, cy_cb_i3c_handle_ccc_response_t callback, cy_stc_i3c_context_t *context);
cy_en_i3c_status_t Cy_I3C_TargetGetCCCData(I3C_CORE_Type *base, uint8_t *buffer, uint32_t size, cy_stc_i3c_context_t *context);
#endif

/** \} group_i3c_target_functions */

/**
* \addtogroup group_i3c_secondary_controller_functions
* \{
*/
#if CY_IP_MXI3C_VERSION_MINOR == 1u || defined(CY_DOXYGEN)
cy_en_i3c_status_t Cy_I3C_RequestControllership(I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
#endif
cy_en_i3c_status_t Cy_I3C_DeliverControllership(I3C_CORE_Type *base, uint8_t SecControllerAddress, cy_stc_i3c_context_t *context);

/** \} group_i3c_secondary_controller_functions */

/**
* \addtogroup group_i3c_interrupt_functions
* \{
*/
#if CY_IP_MXI3C_VERSION_MINOR == 1u || defined(CY_DOXYGEN)
void Cy_I3C_TargetInterrupt (I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
#endif
void Cy_I3C_ControllerInterrupt (I3C_CORE_Type *base, cy_stc_i3c_context_t *context);
/** \} group_i3c_interrupt_functions */

/**
* \addtogroup group_i3c_low_power_functions
* \{
*/
cy_en_syspm_status_t Cy_I3C_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
cy_en_syspm_status_t Cy_I3C_HibernateCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
/** \} group_i3c_low_power_functions */

/*******************************************************************************
*                     In-line Function Implementation
*******************************************************************************/

/**
* \addtogroup group_i3c_secondary_controller_functions
* \{
*/

#if CY_IP_MXI3C_VERSION_MINOR == 1u || defined(CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_I3C_Target_GetResetMode
****************************************************************************//**
*
* Returns the target reset mode set by RSTACT.
*
* \param context
* The pointer to the context structure \ref cy_stc_i3c_context_t allocated
* by the user. The structure is used during the I3C operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* Target Reset mode in \ref cy_en_i3c_target_reset_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_i3c_target_reset_t Cy_I3C_Target_GetResetMode(cy_stc_i3c_context_t *context)
{
    return context->resetMode;
}

/*******************************************************************************
* Function Name: Cy_I3C_Target_isTIREnabled
****************************************************************************//**
*
* Returns if Target interrupt request IBI is enabled/disabled by ENEC/DISEC CCC.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* boolean status of TIR enabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_I3C_Target_isTIREnabled(I3C_CORE_Type *base)
{
    return (bool)_FLD2VAL(I3C_CORE_TGT_EVENT_STATUS_TIR_EN, I3C_CORE_TGT_EVENT_STATUS(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_Target_isHJEnabled
****************************************************************************//**
*
* Returns if HotJoin IBI is enabled/disabled by ENEC/DISEC CCC.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* boolean status of HJ enabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_I3C_Target_isHJEnabled(I3C_CORE_Type *base)
{
    return (bool)_FLD2VAL(I3C_CORE_TGT_EVENT_STATUS_HJ_EN, I3C_CORE_TGT_EVENT_STATUS(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_Target_isCREnabled
****************************************************************************//**
*
* Returns if Controllership request IBI is enabled/disabled by ENEC/DISEC CCC.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* boolean status of CR enabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_I3C_Target_isCREnabled(I3C_CORE_Type *base)
{
    return (bool)_FLD2VAL(I3C_CORE_TGT_EVENT_STATUS_CR_EN, I3C_CORE_TGT_EVENT_STATUS(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_Target_getActivityState
****************************************************************************//**
*
* Returns Activity State set by ENTAS(x) CCC.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Activity state value.
*
*******************************************************************************/
__STATIC_INLINE cy_en_i3c_activity_states_t Cy_I3C_Target_getActivityState(I3C_CORE_Type *base)
{
    return (cy_en_i3c_activity_states_t)_FLD2VAL(I3C_CORE_TGT_EVENT_STATUS_ACTIVITY_STATE, I3C_CORE_TGT_EVENT_STATUS(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_Target_getTIRRemainingDataLength
****************************************************************************//**
*
* Returns the number of bytes remaining that was not transmitted in TIR,
* because of controller early terminating the TIR transfer.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Number of bytes remaining in terminated TIR transfer.
*
* \note
* This function can be called after CY_I3C_TARGET_IBI_EARLY_STOP_EVENT event.
* To get number of bytes that are not transmitted.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_I3C_Target_getTIRRemainingDataLength(I3C_CORE_Type *base)
{
    return (uint8_t)_FLD2VAL(I3C_CORE_TGT_IBI_RESP_TIR_RESP_DATA_LENGTH, base->TGT_IBI_RESP);
}
#endif
/** \} group_i3c_secondary_controller_functions */

/**
* \addtogroup group_i3c_general_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_I3C_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt request register. This register contains the current
* status of the interrupt sources.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* The current status of the interrupt sources.
* Each constant is a bit field value. The value returned may have multiple
* bits set to indicate the current status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetInterruptStatus(I3C_CORE_Type *base)
{
    return(I3C_CORE_INTR_STATUS(base) & CY_I3C_INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_I3C_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the I3C instance.
*
* \param interruptMask
* Interrupt sources to be cleared.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_ClearInterrupt(I3C_CORE_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_I3C_INTR_VALID(interruptMask, CY_I3C_INTR_MASK));
    I3C_CORE_INTR_STATUS(base) = interruptMask;
}

/*******************************************************************************
* Function Name: Cy_I3C_SetInterrupt
****************************************************************************//**
*
* Sets interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the I3C instance.
*
* \param interruptMask
* The interrupt sources to set in the interrupt request register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_SetInterrupt(I3C_CORE_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_I3C_INTR_VALID(interruptMask, CY_I3C_INTR_MASK));
    I3C_CORE_INTR_FORCE(base) = interruptMask;
}

/*******************************************************************************
* Function Name: Cy_I3C_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt signal enable register.
* This register specifies which bits from the interrupt request register
* can trigger an interrupt event.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetInterruptMask(I3C_CORE_Type *base)
{
    return(I3C_CORE_INTR_SIGNAL_EN(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_SetInterruptMask
****************************************************************************//**
*
* Writes the I3C interrupt signal enable register.
* This register specifies which bits
* from the I3C interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the I3C instance.
*
* \param interruptMask
* Enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_SetInterruptMask(I3C_CORE_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_I3C_INTR_VALID(interruptMask, CY_I3C_INTR_MASK));
    I3C_CORE_INTR_SIGNAL_EN(base) = interruptMask;

}

/*******************************************************************************
* Function Name: Cy_I3C_GetInterruptStatusMask
****************************************************************************//**
*
* Returns the interrupt status enable register.
* This register specifies which bits from the interrupt request register
* can generate interrupt.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetInterruptStatusMask(I3C_CORE_Type *base)
{
    return(I3C_CORE_INTR_STATUS_EN(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_SetInterruptStatusMask
****************************************************************************//**
*
* Writes the I3C interrupt status enable register. This register specifies which bits
* from the I3C interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the I3C instance.
*
* \param interruptMask
* Enabled I3C interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_SetInterruptStatusMask (I3C_CORE_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_I3C_INTR_VALID(interruptMask, CY_I3C_INTR_MASK));
    I3C_CORE_INTR_STATUS_EN(base) = interruptMask;
}

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.1', 3, 'Use of pointer as array.')

/*******************************************************************************
*  Function Name: Cy_I3C_WriteIntoDeviceAddressTable
****************************************************************************//**
*
* Writes the value into the specified location of the DAT.
*
* \param base
* The pointer to the I3C instance.
*
* \param index
* The offset from the base of the DAT.
*
* \param value
* The value to be written at the specified location in the DAT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_WriteIntoDeviceAddressTable(I3C_CORE_Type *base, uint8_t index, uint32_t value)
{
    volatile uint32_t *ptr;
    ptr = &(I3C_CORE_DEV_ADDR_TABLE_LOC1(base));
    ptr = ptr + index;
    *ptr = value;
}

/*******************************************************************************
* Function Name: Cy_I3C_ReadFromDeviceAddressTable
****************************************************************************//**
*
* Returns the complete DAT entry of given index.
*
* \param base
* The pointer to the I3C instance.
*
* \param index
* The offset from the base of the DAT.
*
* \return
* The dynamic address of the I3C device.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_ReadFromDeviceAddressTable(I3C_CORE_Type *base, uint8_t index)
{
    volatile uint32_t *ptr;

    ptr = &(I3C_CORE_DEV_ADDR_TABLE_LOC1(base));
    ptr = ptr + index;
    return (*ptr);
}

/*******************************************************************************
* Function Name: Cy_I3C_ReadDynAddrFromDAT
****************************************************************************//**
*
* Returns the dynamic address of the I3C device stored in the DAT.
*
* \param base
* The pointer to the I3C instance.
*
* \param index
* The offset from the base of the DAT.
*
* \return
* The dynamic address of the I3C device.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_ReadDynAddrFromDAT(I3C_CORE_Type *base, uint8_t index)
{
    volatile uint32_t *ptr;
    uint32_t addr;

    ptr = &(I3C_CORE_DEV_ADDR_TABLE_LOC1(base));
    ptr = ptr + index;
    addr = _FLD2VAL(I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_DYNAMIC_ADDR, *ptr);

    return (0x7FUL & addr);
}

/*******************************************************************************
* Function Name: Cy_I3C_ReadStaticAddrFromDAT
****************************************************************************//**
* Returns the static address of the I2C device stored in the DAT.
*
* \param base
* The pointer to the I3C instance.
*
* \param index
* The offset from the base of the DAT.
*
* \return
* The static address of the I2C device.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_ReadStaticAddrFromDAT(I3C_CORE_Type *base, uint8_t index)
{
    volatile uint32_t *ptr;

    ptr = &(I3C_CORE_DEV_ADDR_TABLE_LOC1(base));
    ptr = ptr + index;

    return ((*ptr) & I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_STATIC_ADDR_Msk);
}
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.1')

/*******************************************************************************
* Function Name: Cy_I3C_ReadFromDevCharTable
****************************************************************************//**
* Populates the i3c device defined by \ref cy_stc_i3c_device_t with the
* DCR, BCR, PID and dynamic address information from the DCT.
*
* \param base
* The pointer to the I3C instance.
*
* \param index
* The offset from the base of the DAT.
*
* \param i3cDevice
* The pointer to the i3c device description structure \ref cy_stc_i3c_device_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_ReadFromDevCharTable(I3C_CORE_Type *base, uint8_t index, cy_stc_i3c_device_t *i3cDevice)
{
    cy_stc_i3c_dev_char_t *ptr;
    volatile uint32_t dcr_bcr;

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_i3c_dev_char_t.');
    ptr = (cy_stc_i3c_dev_char_t *)&(I3C_CORE_DEV_CHAR_TABLE1_LOC1(base));
    ptr = ptr + index;
    i3cDevice->provisionalID = ((uint64_t)(ptr->LSBProvisionalID));
    i3cDevice->provisionalID |= ((uint64_t)(ptr->MSBProvisionalID) << 32UL);
    dcr_bcr = ptr->DCR_BCR;
    i3cDevice->dcr =(uint8_t)(I3C_CORE_DEV_CHAR_TABLE1_LOC3_DCR_Msk & (dcr_bcr));
    i3cDevice->bcr = ((uint8_t)_FLD2VAL(I3C_CORE_DEV_CHAR_TABLE1_LOC3_BCR, (dcr_bcr)));
    volatile uint32_t dynamic_address = (ptr->dynamicAddress);
    i3cDevice->dynamicAddress = (uint8_t) dynamic_address;
}

/*******************************************************************************
*  Function Name: Cy_I3C_UpdateI3CDevInList
****************************************************************************//**
*
* Adds the I3C device to the list of devices \ref cy_stc_i3c_controller_devlist_t
* present on the bus.
*
* \param i3cDevice
* The pointer to the I3C device description structure \ref cy_stc_i3c_device_t.
*
* \param pos
* The position of the device in the list \ref cy_stc_i3c_controller_devlist_t.
*
* \param context
* The pointer to the context structure \ref cy_stc_i3c_context_t allocated
* by the user. The structure is used during the I3C operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_UpdateI3CDevInList(cy_stc_i3c_device_t *i3cDevice, uint8_t pos, cy_stc_i3c_context_t *context)
{
    context->devList[pos].i2c = false;
    context->devList[pos].i3cDevice = *i3cDevice;
}

/*******************************************************************************
*  Function Name: Cy_I3C_UpdateI2CDevInList
****************************************************************************//**
*
* Adds the I2C device to the list of devices \ref cy_stc_i3c_controller_devlist_t
* present on the bus.
*
* \param i2cDevice
* The pointer to the I2C device description structure \ref cy_stc_i2c_device_t.
*
* \param pos
* The position of the device in the list \ref cy_stc_i3c_controller_devlist_t.
*
* \param context
* The pointer to the context structure \ref cy_stc_i3c_context_t allocated
* by the user. The structure is used during the I3C operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_UpdateI2CDevInList(cy_stc_i2c_device_t *i2cDevice, uint8_t pos, cy_stc_i3c_context_t *context)
{
    context->devList[pos].i2c = true;
    context->devList[pos].i2cDevice = *i2cDevice;
}

/*******************************************************************************
* Function Name: Cy_I3C_ReadRxFIFO
****************************************************************************//**
*
* Reads a data element directly out of the RX FIFO.
* This function does not check whether the RX FIFO has data before reading it.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Data from RX FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_ReadRxFIFO(I3C_CORE_Type *base)
{
    return (I3C_CORE_RX_DATA_PORT(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_WriteTxFIFO
****************************************************************************//**
*
* Writes data directly into the TX FIFO.
* This function does not check whether the TX FIFO is not full before writing
* into it.
*
* \param base
* The pointer to the I3C instance.
*
* \param data
* Data to write to the TX FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_WriteTxFIFO(I3C_CORE_Type *base, uint32_t data)
{
    I3C_CORE_RX_DATA_PORT(base) = data;
}

/*******************************************************************************
* Function Name: Cy_I3C_GetFreeEntriesInTxFifo
****************************************************************************//**
*
* Provides the number of empty locations in the TX FIFO.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Transmit buffer empty level value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetFreeEntriesInTxFifo(I3C_CORE_Type *base)
{
    return _FLD2VAL(I3C_CORE_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC, I3C_CORE_DATA_BUFFER_STATUS_LEVEL(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_GetFreeEntriesInRxFifo
****************************************************************************//**
*
* Provides the number of empty locations in the RX FIFO.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* Receive buffer empty level value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetFreeEntriesInRxFifo(I3C_CORE_Type *base)
{
    return ((CY_I3C_FIFO_SIZE/4UL) - _FLD2VAL(I3C_CORE_DATA_BUFFER_STATUS_LEVEL_RX_BUF_BLR, I3C_CORE_DATA_BUFFER_STATUS_LEVEL(base)));
}

/*******************************************************************************
* Function Name: Cy_I3C_SetRxFifoLevel
****************************************************************************//**
*
* Sets the RX FIFO level. When there are more data elements in the RX FIFO than
* this level, the RX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the I3C instance.
*
* \param level
* When there are more data elements in the FIFO than this level, the RX level
* interrupt is triggered.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_SetRxFifoLevel(I3C_CORE_Type *base, uint32_t level)
{
    CY_REG32_CLR_SET(I3C_CORE_DATA_BUFFER_THLD_CTRL(base), I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD, level);
}

/*******************************************************************************
* Function Name: Cy_I3C_GetRxFifoLevel
****************************************************************************//**
*
* Returns the RX FIFO level. When there are more words in the RX FIFO than the
* threshold level, the RX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the I3C instance.
*
* \return
* RX FIFO level.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_I3C_GetRxFifoLevel(I3C_CORE_Type const *base)
{
    return _FLD2VAL(I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD, I3C_CORE_DATA_BUFFER_THLD_CTRL(base));
}

/*******************************************************************************
* Function Name: Cy_I3C_SetTxEmptyThldLevel
****************************************************************************//**
*
* Sets the TX FIFO level. When the number of empty locations in the TX FIFO is
* greater than this level, the TX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the I3C instance.
*
* \param level
* When there are more empty locations in the TX FIFO than this level,
* the TX level interrupt is triggered.
*
*******************************************************************************/
__STATIC_INLINE void Cy_I3C_SetTxEmptyThldLevel(I3C_CORE_Type const *base, uint32_t level)
{
    CY_REG32_CLR_SET(I3C_CORE_DATA_BUFFER_THLD_CTRL(base), I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD, level);
}

/** \} group_i3c_general_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXI3C */

#endif /* (CY_I3C_H) */

/** \} group_i3c */

/* [] END OF FILE */
