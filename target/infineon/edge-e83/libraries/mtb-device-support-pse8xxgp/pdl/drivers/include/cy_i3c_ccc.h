/***************************************************************************//**
* \file cy_i3c_ccc.h
* \version 1.00
*
* \brief
* Provides API declarations for the I3C Controller.
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


#if !defined (CY_I3C_CCC_H)
#define CY_I3C_CCC_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined (CY_IP_MXI3C)

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*                               API Constants
*******************************************************************************/

/**
* \addtogroup group_i3c_macros_common_macros Common Macros
* \{
*/


/** Max number of target devices addressable in controller mode */
#define CY_I3C_MAX_DEVS (11U)

/** Bits per long */
#define CY_I3C_BITS_PER_LONG (32U)

/**
 * Create a contiguous bitmask starting at bit position l and ending at position h. For example
 * CY_I3C_GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000FFFFE00000.
 */
#define CY_I3C_GENMASK(h, l) (((~(0UL)) - ((1UL) << (l)) + 1UL) & (~(0UL) >> (CY_I3C_BITS_PER_LONG - 1UL - (h))))

/** Create a bitmask at bit position @n */
#define CY_I3C_BIT(n) ((1UL) << (n))

/** Divide and round up */
#define CY_I3C_DIV_ROUND_UP(n,d) (((n) + (d) - 1U) / (d))

/** Swap the bytes of a 16-bit word */
#define CY_I3C_SWAP16(x) ((uint16_t)((((uint16_t)(x) & (uint16_t)0x00FFU) << 8U) | (((uint16_t)(x) & (uint16_t)0xFF00U) >> 8U) ))

/** Direct CCC Mask */
#define CY_I3C_CCC_DIRECT                0x80U

/**Create Broadcast/Direct CCC Id */
#define CY_I3C_CCC_ID(id, broadcast)    ((id) | ((broadcast) ? 0U : CY_I3C_CCC_DIRECT))

/** Enable Target Events Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_ENEC(broadcast)            CY_I3C_CCC_ID(0x0U, broadcast)

/** Disable Target Events Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_DISEC(broadcast)            CY_I3C_CCC_ID(0x1U, broadcast)

/** Enter Activity State 0-3 Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_ENTAS(as, broadcast)        CY_I3C_CCC_ID(0x2U + (as), broadcast)

/** Reset Dynamic Address Assignment Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_RSTDAA(broadcast)        CY_I3C_CCC_ID(0x6U, broadcast)

/** Set Maximum Write Length Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_SETMWL(broadcast)        CY_I3C_CCC_ID(0x9U, broadcast)

/**Set Maximum Read Length Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_SETMRL(broadcast)        CY_I3C_CCC_ID(0xAU, broadcast)

/**Target Reset Action: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_RSTACT(broadcast)        (uint8_t)((broadcast) ? 0x2AU : 0x9AU)

/** Enter Dynamic Address Assignment Command: Broadcast-only command */
#define CY_I3C_CCC_ENTDAA            CY_I3C_CCC_ID(0x7U, true)

/** Define List of Targets Command: Broadcast-only command */
#define CY_I3C_CCC_DEFTGTS            CY_I3C_CCC_ID(0x8U, true)

/** Enter HDR Mode Command: Broadcast-only command */
#define CY_I3C_CCC_ENTHDR(x)        CY_I3C_CCC_ID(0x20U + (x), true)

/** Set all dynamic addresses as static addresses Command: Broadcast-only command*/
#define CY_I3C_CCC_SETAASA            CY_I3C_CCC_ID(0x29U, true)

/** Set Dynamic Address from Static Address Command: Unicast-only command */
#define CY_I3C_CCC_SETDASA            CY_I3C_CCC_ID(0x7U, false)

/** Set New Dynamic Address Command: Unicast-only command */
#define CY_I3C_CCC_SETNEWDA            CY_I3C_CCC_ID(0x8U, false)

/** Get Maximum Write Length Command: Unicast-only command */
#define CY_I3C_CCC_GETMWL            CY_I3C_CCC_ID(0xBU, false)

/** Get Maximum Read Length Command: Unicast-only command */
#define CY_I3C_CCC_GETMRL            CY_I3C_CCC_ID(0xCU, false)

/**Set Exchange Timing Information Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_SETXTIME(broadcast)        (uint8_t)((broadcast) ? 0x28U : 0x98U)

/**Get Exchange Timing Support Information Command: Unicast-only command */
#define CY_I3C_CCC_GETXTIME          CY_I3C_CCC_ID(0x99U, false)

/** Get Provisioned ID(PID) Command: Unicast-only command */
#define CY_I3C_CCC_GETPID            CY_I3C_CCC_ID(0xDU, false)

/** Get Bus Characteristic Register(BCR) Command: Unicast-only command */
#define CY_I3C_CCC_GETBCR            CY_I3C_CCC_ID(0xEU, false)

/** Get Device Characteristic Register(DCR) Command: Unicast-only command */
#define CY_I3C_CCC_GETDCR            CY_I3C_CCC_ID(0xFU, false)

/** Get Device Status Command: Unicast-only command */
#define CY_I3C_CCC_GETSTATUS        CY_I3C_CCC_ID(0x10U, false)

/** Get Accept Controllership Command: Unicast-only command */
#define CY_I3C_CCC_GETACCCR        CY_I3C_CCC_ID(0x11U, false)

/** Data Transfer Ending Procedure Control Command: valid in both broadcast and unicast modes */
#define CY_I3C_CCC_ENDXFER(broadcast)        CY_I3C_CCC_ID(0x12U, broadcast)

/** Get Maximum Data Speed Command: Unicast-only command */
#define CY_I3C_CCC_GETMXDS            CY_I3C_CCC_ID(0x14U, false)

/** Get HDR Capability Command: Unicast-only command */
#define CY_I3C_CCC_GETHDRCAP        CY_I3C_CCC_ID(0x15U, false)

/** Device control Command: Broadcast-only command */
#define CY_I3C_CCC_DEVCTRL           CY_I3C_CCC_ID(0x62U, true)

/** Target Interrupt Request Event \ref cy_stc_i3c_ccc_events_t */
#define CY_I3C_CCC_EVENT_SIR        CY_I3C_BIT(0U)

/** Controllership Request Event  \ref cy_stc_i3c_ccc_events_t */
#define CY_I3C_CCC_EVENT_MR            CY_I3C_BIT(1U)

/**Hot-join Event  \ref cy_stc_i3c_ccc_events_t */
#define CY_I3C_CCC_EVENT_HJ            CY_I3C_BIT(3U)

/** HDR Read Command Code */
#define CY_I3C_HDR_IS_READ_CMD        CY_I3C_BIT(7U)

/**
* \addtogroup group_i3c_macros_common_macros_getstatus_ccc_fields GetStatus CCC Fields
* \{
*/

/**
* Contains the interrupt number of any pending interrupt,
* or 0 if no interrupts are pending
*/
#define I3C_CCC_STATUS_PENDING_INT(status)    ((status) & CY_I3C_GENMASK(3U, 0U))

/** Indicates the Target has detected a protocol error */
#define I3C_CCC_STATUS_PROTOCOL_ERROR        CY_I3C_BIT(5U)

/** Indicates the Target Device's current activity mode */
#define I3C_CCC_STATUS_ACTIVITY_MODE(status) (((status) & CY_I3C_GENMASK(7U, 6U)) >> 6U)

/** \} group_i3c_macros_common_macros_getstatus_ccc_fields */

/** \} group_i3c_macros_common_macros */

/*******************************************************************************
*                              Type Definitions
*******************************************************************************/

/**
* \addtogroup group_i3c_data_structures
* \{
*/

/** ENEC/DISEC CCC payload structure */
typedef struct cy_stc_i3c_ccc_events
{
    uint8_t events;  /**< bitmask of CY_I3C_CCC_EVENT_xxx events */
}cy_stc_i3c_ccc_events_t;

/** SETMWL/GETMWL CCC payload structure */
typedef struct cy_stc_i3c_ccc_mrwl
{
    uint16_t len;             /**< maximum read/write length in bytes */
    uint8_t payloadSize;      /**< Optional IBI Payload size */
}cy_stc_i3c_ccc_mrwl_t;

/** SETMRL/GETMRL CCC payload structure */
typedef struct cy_stc_i3c_ccc_mrl
{
    uint16_t readLen;             /**< maximum read/write length in bytes */
    uint8_t payloadSize;     /**< Optional IBI Payload size */
}cy_stc_i3c_ccc_mrl_t;

/** GETXTIME CCC payload structure */
typedef struct cy_stc_i3c_ccc_getxtime
{
    uint8_t supportedModes;   /**< Bit mask indicating which Timing Control Mode(s) the Target supports */
    uint8_t state;            /**< Bit mask indicating which Timing Control Mode (if any) is currently enabled for the Target and overflow bit*/
    uint8_t frequency;        /**< Byte representing the Frequency of the Targets internal oscillator, in increments of 0.5 MHz*/
    uint8_t inaccuracy;       /**< Byte representing the maximum variation of the Targets internal oscillator in 1/10th percent (0.1%) increments */
}cy_stc_i3c_ccc_getxtime_t;

/** I3C/I2C device descriptor used for DEFTGTS */
typedef struct cy_stc_i3c_ccc_dev_desc
{
    uint8_t dynAddress; /**< dynamic address assigned to the I3C target or 0 if the entry is describing an I2C Target */
    union {
        uint8_t dcr; /**< DCR value (not applicable to entries describing I2C devices) */
        uint8_t lvr; /**< LVR value (not applicable to entries describing I3C devices) */
    };
    uint8_t bcr; /**< BCR value or 0 if this entry is describing an I2C target */
    uint8_t staticAddress; /**< static address or 0 if the device does not have a static address */
}cy_stc_i3c_ccc_dev_desc_t;

/** DEFTGTS CCC payload structure */
typedef struct cy_stc_i3c_ccc_deftgts
{
    uint8_t count; /**<  number of dev descriptors */
    cy_stc_i3c_ccc_dev_desc_t controller; /**< descriptor describing the current controller */
    cy_stc_i3c_ccc_dev_desc_t targets[CY_I3C_MAX_DEVS]; /**< array of descriptors describing targets controlled by the current controller */
}cy_stc_i3c_ccc_deftgts_t ;

/** SETNEWDA and SETDASA CCCs payload structure */
typedef struct cy_stc_i3c_ccc_setda
{
    uint8_t address; /**<  dynamic address to assign to an I3C device */
}cy_stc_i3c_ccc_setda_t;

/** GETPID CCC payload structure */
typedef struct cy_stc_i3c_ccc_getpid
{
    uint8_t pid[6U]; /**< 48 bits PID in big endian */
}cy_stc_i3c_ccc_getpid_t;

/** GETBCR CCC payload structure */
typedef struct cy_stc_i3c_ccc_getbcr
{
    uint8_t bcr; /**< BCR (Bus Characteristic Register) value */
}cy_stc_i3c_ccc_getbcr_t;

/** GETDCR CCC payload structure */
typedef struct cy_stc_i3c_ccc_getdcr
{
    uint8_t dcr; /**< DCR (Device Characteristic Register) value */
}cy_stc_i3c_ccc_getdcr_t;

/** GETSTATUS CCC payload structure */
typedef struct cy_stc_i3c_ccc_getstatus
{
    uint16_t status; /**< status of the I3C target (see I3C_CCC_STATUS_xxx macros for more information */
}cy_stc_i3c_ccc_getstatus_t;

/** GETACCCR CCC payload structure */
typedef struct cy_stc_i3c_ccc_getacccr
{
    uint8_t newcontroller; /**< address of the controller taking bus ownership */
}cy_stc_i3c_ccc_getacccr_t;

/** GETMXDS CCC payload structure */
typedef struct cy_stc_i3c_ccc_getmxds
{
    uint8_t maxwr; /**< write limitations */
    uint8_t maxrd; /**< read limitations */
    uint8_t maxrdturn[3U]; /**< maximum read turn-around expressed micro-seconds and little-endian formatted */
}cy_stc_i3c_ccc_getmxds_t;

/** GETHDRCAP CCC payload structure */
typedef struct cy_stc_i3c_ccc_gethdrcap
{
    uint8_t modes; /**< bitmap of supported HDR modes */
    uint8_t getcapByte2; /**< second byte for getcaps ccc */
    uint8_t getcapByte3; /**< third byte for getcaps ccc */
    uint8_t getcapByte4; /**< forth byte for getcaps ccc */
}cy_stc_i3c_ccc_gethdrcap_t;

/** RSTACT CCC payload structure */
typedef struct cy_stc_i3c_ccc_rstact
{
    uint8_t resetTime; /**< time required for reset */
}cy_stc_i3c_ccc_rstact_t;

/** DEVCTRL Address Mask */
typedef enum
{
    UNICAST_CMD    = 0x00U,   /**< UniCast Command, Target devices responds if address matches with devID */
    MULTICAST_CMD  = 0x03U,   /**< Multicast Command, Target devices respond if address matches with devID[6:3] */
    BROADCAST_CMD  = 0x07U,   /**< Broadcast Command, All Target devices responds */
} cy_en_i3c_devctrl_addrMsk_t;

/** DEVCTRL Start Offset */
typedef enum
{
    BYTE0,  /**< Start byte 0 */
    BYTE1,  /**< Start byte 1 */
    BYTE2,  /**< Start byte 2 */
    BYTE3,  /**< Start byte 3 */
} cy_en_i3c_devctrl_start_offset_t;

/** DEVCTRL PEC Burst Length */
typedef enum
{
    ONE_BYTE,     /**< Burst Length of 1 byte */
    TWO_BYTE,     /**< Burst Length of 2 byte */
    THREE_BYTE,   /**< Burst Length of 3 byte */
    FOUR_BYTE,    /**< Burst Length of 4 byte */
} cy_en_i3c_devctrl_pec_bl_t;
/** DEVCTRL CCC payload structure */
typedef struct cy_stc_i3c_ccc_devctrl
{
    cy_en_i3c_devctrl_addrMsk_t addrMask;          /**< Broadcast, Uni-cast or Multi-cast Command Selection */
    cy_en_i3c_devctrl_start_offset_t startOffset;  /**< Starting Byte of command */
    cy_en_i3c_devctrl_pec_bl_t PEC_BL;             /**< Burst length of DEVCTRL data packet */
    bool regMod;          /**< general or device specific register mode */
    uint8_t devID;        /**< 7-bit device address */
    uint8_t payloadByte0; /**< payload Byte 0 */
    uint8_t payloadByte1; /**< payload Byte 1  */
    uint8_t payloadByte2; /**< payload Byte 2 */
    uint8_t payloadByte3; /**< payload Byte 3  */
}cy_stc_i3c_ccc_devctrl_t;
/** \} group_i3c_data_structures */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXI3C */

#endif /* (CY_I3C_CCC_H) */

/* [] END OF FILE */
