/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2003 - 2025     SEGGER Microcontroller GmbH              *
*                                                                    *
*       www.segger.com     Support: www.segger.com/ticket            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device * USB Device stack for embedded applications    *
*                                                                    *
*       Please note: Knowledge of this file may under no             *
*       circumstances be used to write a similar product.            *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device version: V3.66.5                                *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
All Intellectual Property rights in the software belongs to SEGGER.
emUSB Device is protected by international copyright laws. This file
may only be used in accordance with the following terms:

The source code of the emUSB Device software has been licensed to Cypress
Semiconductor Corporation, whose registered office is 198 Champion
Court, San Jose, CA 95134, USA including the 
right to create and distribute the object code version of 
the emUSB Device software for its Cortex M0, M0+, M4, M33 and M55 based devices.
The object code version can be used by Cypress customers under the 
terms and conditions of the associated End User License Agreement.
Support for the object code version is provided by Cypress, 
full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              Cypress Semiconductor Corp, 198 Champion Ct., San Jose, CA 95134, USA
Licensed SEGGER software: emUSB-Device
License number:           USBD-00500
License model:            Cypress Services and License Agreement, signed November 17th/18th, 2010
                          and Amendment Number One, signed December 28th, 2020 and February 10th, 2021
                          and Amendment Number Three, signed May 2nd, 2022 and May 5th, 2022 and Amendment Number Four, signed August 28th, 2023
Licensed platform:        Cypress devices containing ARM Cortex M cores: M0, M0+, M4, M33 and M55
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2022-05-12 - 2026-05-19
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
Purpose : Public header of the CCID component
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_CCID_H          /* Avoid multiple inclusion */
#define USBD_CCID_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define USB_CCID_VOLTAGE_5               (1u << 0)     // 5.0 Volt
#define USB_CCID_VOLTAGE_3               (1u << 1)     // 3.0 Volt
#define USB_CCID_VOLTAGE_1_8             (1u << 2)     // 1.8 Volt

#define USB_CCID_PROTOCOL_0              (1u << 0)     // T=0 protocol
#define USB_CCID_PROTOCOL_1              (1u << 1)     // T=1 protocol

#define USB_CCID_PIN_VERFICATION         (1u << 0)     // PIN verification support.
#define USB_CCID_PIN_MODIFICATION        (1u << 1)     // PIN modification support.

#define USB_CCID_FEATURE_AUTO_PARAM_CFG   0x00000002u  // Automatic parameter configuration based on ATR data.
#define USB_CCID_FEATURE_AUTO_ACT_ICC     0x00000004u  // Automatic activation of ICC on inserting.
#define USB_CCID_FEATURE_AUTO_ICC_VOLTAGE 0x00000008u  // Automatic ICC voltage selection.
#define USB_CCID_FEATURE_AUTO_ICC_CLOCK   0x00000010u  // Automatic ICC clock frequency change according to active parameters
                                                       // provided by the Host or self determined.
#define USB_CCID_FEATURE_AUTO_BAUD_RATE   0x00000020u  // Automatic baud rate change according to active parameters
                                                       // provided by the Host or self determined.
#define USB_CCID_FEATURE_AUTO_PARAM_NEG   0x00000040u  // Automatic parameters negotiation made by the
                                                       // CCID (use of warm or cold resets or PPS according to a
                                                       // manufacturer proprietary algorithm to select the communication
                                                       // parameters with the ICC).
#define USB_CCID_FEATURE_AUTO_PPS         0x00000080u  // Automatic PPS made by the CCID according to the active parameters.
#define USB_CCID_FEATURE_CLOCK_STOP       0x00000100u  // CCID can set ICC in clock stop mode.
#define USB_CCID_FEATURE_NAD_VALUE        0x00000200u  // NAD value other than 00 accepted (T=1 protocol in use).
#define USB_CCID_FEATURE_AUTO_IFSD        0x00000400u  // Automatic IFSD exchange as first exchange (T=1 protocol in use).
#define USB_CCID_FEATURE_TPDU             0x00010000u  // TPDU level exchanges with CCID.
#define USB_CCID_FEATURE_APDU             0x00020000u  // Short APDU level exchange with CCID.
#define USB_CCID_FEATURE_APDU_EX          0x00040000u  // Short and Extended APDU level exchange with CCID.

//
// Message types for commands
//
#define USB_CCID_MSG_ICC_POWER_ON         0x62u
#define USB_CCID_MSG_ICC_POWER_OFF        0x63u
#define USB_CCID_MSG_GET_SLOT_STATUS      0x65u
#define USB_CCID_MSG_XFR_BLOCK            0x6Fu
#define USB_CCID_MSG_GET_PARAMETERS       0x6Cu
#define USB_CCID_MSG_RESET_PARAMETERS     0x6Du
#define USB_CCID_MSG_SET_PARAMETERS       0x61u
#define USB_CCID_MSG_ESCAPE_CMD           0x6Bu
#define USB_CCID_MSG_ICC_CLOCK            0x6Eu
#define USB_CCID_MSG_T0APDU               0x6Au
#define USB_CCID_MSG_SECURE               0x69u
#define USB_CCID_MSG_MECHANICAL           0x71u
#define USB_CCID_MSG_ABORT                0x72u
#define USB_CCID_MSG_SET_RATE_AND_CLOCK   0x73u

//
// Message types for responses
//
#define USB_CCID_MSG_DATABLOCK            0x80u
#define USB_CCID_MSG_SLOT_STATUS          0x81u
#define USB_CCID_MSG_PARAMETERS           0x82u
#define USB_CCID_MSG_ESCAPE_RSP           0x83u
#define USB_CCID_MSG_RATE_AND_CLOCK       0x84u

//
// Message types for notifications
//
#define USB_CCID_MSG_SLOT_CHANGE          0x50u
#define USB_CCID_MSG_HARDWARE_ERROR       0x51u

//
// Status values
//
#define USB_CCID_STATUS_CMD_SUCCESS       0x00u     // Command processed without error
#define USB_CCID_STATUS_CMD_FAIL          0x40u     // Command failed (error code provided by the error register)
#define USB_CCID_STATUS_CMD_TIME_EXT      0x80u     // Time Extension is requested
#define USB_CCID_STATUS_ICC_ACTIVE           0u     // An ICC is present and active
#define USB_CCID_STATUS_ICC_INACTIVE         1u     // An ICC is present and inactive
#define USB_CCID_STATUS_ICC_NOT_AVAIL        2u     // No ICC is present

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

/*********************************************************************
*
*       USBD_CCID_ABORT_CB
*
*  Description
*    Callback function to forward a CCID abort request from the host to the application.
*    The function is called in interrupt context and should return as fast as possible.
*
*  Parameters
*    Slot         : Card slot index (counting from 0).
*    SeqNum       : Sequence number of the command to abort.
*/
typedef void USBD_CCID_ABORT_CB(U8 Slot, U8 SeqNum);

/*********************************************************************
*
*       USB_CCID_INIT_DATA
*
*  Function description
*    Initialization structure that is needed when adding a CCID interface to emUSB-Device.
*/
typedef struct {
  U8 EPIn;                       // Endpoint for sending data to the host.
  U8 EPOut;                      // Endpoint for receiving data from the host.
  U8 EPInt;                      // Endpoint for sending notification to the host.
                                 // Optional, may be 0.
  U8 * pBuff;                    // Pointer to endpoint buffer for EPIn. Buffer should be able to hold one USB packet.
  USBD_CCID_ABORT_CB * pfAbort;  // Callback function to signal an abort by the host.
                                 // Optional, may be NULL.
} USB_CCID_INIT_DATA;

/*********************************************************************
*
*       USB_CCID_PROPERTIES
*
*  Function description
*    Declares all properties of a CCID device.
*/
typedef struct {                  // NOLINT(clang-analyzer-optin.performance.Padding)
  U16          Flags;             // Reserved for future use, must be 0.
  U8           NumSlots;          // Number of card slots supported by the device (max. 4).
  U8           VoltageSupport;    // Supported voltages, see USB_CCID_VOLTAGE... macros.
  U8           Protocols;         // Supported protocols (T=0, T=1), see USB_CCID_PROTOCOL... macros.
  U8           NumClocks;         // Number of supported clock rates (number of entries in the table pointed to by pClocks).
                                  // Must be >= 1.
  U8           DefaultClockIdx;   // Index of the default clock within the table pClocks.
  U8           NumDataRates;      // Number of supported data rates (number of entries in the table pointed to by pDataRates).
                                  // May be 0 to indicate a range. In this case pDataRates must contain 2 entries (min, max)
                                  // and DefaultDataRateIdx must be 0.
  U8           DefaultDataRateIdx;// Index of the default data rate within the table pDataRates.
  const U32  * pClocks;           // Table of all supported clock rates in KHz in increasing order.
  const U32  * pDataRates;        // Table of all supported data rates in bps in increasing order.
  U32          MaxIFSD;           // Indicates the maximum IFSD supported by CCID for protocol T=1.
  U32          Features;          // This value indicates what intelligent features the CCID has.
                                  // The value is a bitwise OR operation performed on the macros USB_CCID_FEATURE...
  U32          MaxMessageLength;  // Maximum CCID message length.
  U8           ClassGetResponse;  // Significant only for CCID that offers an APDU level for exchanges.
                                  // Indicates the default class value used by the CCID when it sends a Get Response command
                                  // to perform the transportation of an APDU by T=0 protocol.
                                  // Value 0xFF indicates that the CCID echoes the class of the APDU.
  U8           ClassEnvelope;     // Significant only for CCID that offers an extended APDU level for exchanges.
                                  // Indicates the default class value used by the CCID when it sends an Envelope command
                                  // to perform the transportation of an extended APDU by T=0 protocol.
                                  // Value 0xFF indicates that the CCID echoes the class of the APDU.
  U8           LCDLines;          // Number of lines of the LCD display. 0 if no display supported.
  U8           LCDColumns;        // Number of characters per line of the LCD display. 0 if no display supported.
  U8           PINSupport;        // This value indicates what PIN support features the CCID has.
  const char * pInterfaceName;    // Name of the interface.
} USB_CCID_PROPERTIES;

/*********************************************************************
*
*       USB_CCID_CMD
*
*  Function description
*    Contains information about a CCID command send from the host.
*/
typedef struct {
  U8  MessageType;      // Message type, see USB_CCID_MSG_... macros.
  U8  Slot;             // Card slot index (counting from 0).
  U8  SeqNum;           // Command sequence number.
  U8  PowerSelect;      // Only valid for message type USB_CCID_MSG_ICC_POWER_ON.
                        // Contains voltage that is applied to the ICC:
                        // * 0 - Automatic Voltage Selection
                        // * 1 - 5.0 volts
                        // * 2 - 3.0 volts
                        // * 3 - 1.8 volts.
  U8  BWI;              // Only valid for message types USB_CCID_MSG_XFR_BLOCK and USB_CCID_MSG_SECURE.
                        // Used to extend the CCIDs Block Waiting Timeout for this current transfer.
                        // The CCID shall timeout the block after "this number multiplied by the Block Waiting Time" has expired.
  U8  LevelParameter;   // Only valid for message types USB_CCID_MSG_XFR_BLOCK and USB_CCID_MSG_SECURE.
                        // Use changes depending on the exchange level reported by the class descriptor in dwFeatures field:
                        // * Character level: Size of expected data to be returned by the bulk-IN endpoint.
                        // * Extended APDU level: Indicates if APDU begins or ends in this command.
  U8  ProtocolNumber;   // Only valid for message types USB_CCID_MSG_SET_PARAMETERS.
                        // * 0: Structure for protocol T=0.
                        // * 1: Structure for protocol T=1.
  U8  ClockCommand;     // Only valid for message types USB_CCID_MSG_ICC_CLOCK.
                        // * 0: restarts Clock.
                        // * 1: Stops Clock.
  U8  ClassValid;       // Only valid for message types USB_CCID_MSG_T0APDU.
                        // Bit 0 == 1 indicates, that the field ClassGetResponse is valid.
                        // Bit 1 == 1 indicates, that the field ClassEnvelope is valid.
  U8  ClassGetResponse; // Only valid for message types USB_CCID_MSG_T0APDU.
                        // Value to force the class byte of the header in a Get Response command.
                        // Value = 0xFF indicates that the class byte of the Get Response command echoes the
                        // class byte of the APDU.
  U8  ClassEnvelope;    // Only valid for message types USB_CCID_MSG_T0APDU.
                        // Value to force the class byte of the header in a Envelope command.
                        // Value = 0xFF indicates that the class byte of the Envelope command echoes the class
                        // byte of the APDU.
  U8  Function;         // Only valid for message types USB_CCID_MSG_MECHANICAL.
                        // This value corresponds to the mechanical function being requested:
                        // * 1 - Accept Card.
                        // * 2 - Eject Card.
                        // * 3 - Capture Card.
                        // * 4 - Lock Card.
                        // * 5 - Unlock Card.
  unsigned DataLen;     // Size of data send with this command.
} USB_CCID_CMD;

/*********************************************************************
*
*       USB_CCID_PROTOCOL_DATA_T0
*
*  Function description
*    Protocol parameters for T=0 protocol.
*/
typedef struct {
  U8 FindexDindex;            // see USB CCID specification.
  U8 TCCKST0;                 // see USB CCID specification.
  U8 GuardTimeT0;             // see USB CCID specification.
  U8 WaitingIntegerT0;        // see USB CCID specification.
  U8 ClockStop;               // see USB CCID specification.
} USB_CCID_PROTOCOL_DATA_T0;

/*********************************************************************
*
*       USB_CCID_PROTOCOL_DATA_T1
*
*  Function description
*    Protocol parameters for T=1 protocol.
*/
typedef struct {
  U8 FindexDindex;            // see USB CCID specification.
  U8 TCCKST1;                 // see USB CCID specification.
  U8 GuardTimeT1;             // see USB CCID specification.
  U8 WaitingIntegerT1;        // see USB CCID specification.
  U8 ClockStop;               // see USB CCID specification.
  U8 IFSC;                    // see USB CCID specification.
  U8 NadValue;                // see USB CCID specification.
} USB_CCID_PROTOCOL_DATA_T1;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void USBD_CCID_Init             (void);
void USBD_CCID_Add              (const USB_CCID_INIT_DATA * pInitData, const USB_CCID_PROPERTIES *pProperties);
void USBD_CCID_NotifySlotState  (unsigned Slot, unsigned State);
void USBD_CCID_NotifyHwError    (unsigned Slot, U8 SeqNum, U8 ErrorCode);
int  USBD_CCID_ReceiveCmd       (USB_CCID_CMD *pCmd, unsigned BuffSize, U8 *pBuff, unsigned Timeout);
int  USBD_CCID_SendStatus       (const USB_CCID_CMD *pCmd, U8 Status, U8 Error, U8 ClockStatus);
int  USBD_CCID_SendDataBlock    (const USB_CCID_CMD *pCmd, U8 Status, U8 Error, U8 ChainParameter, unsigned DataLen, const U8 *pData);
int  USBD_CCID_SendEscape       (const USB_CCID_CMD *pCmd, U8 Status, U8 Error, unsigned DataLen, const U8 *pData);
int  USBD_CCID_SendParameters   (const USB_CCID_CMD *pCmd, U8 Status, U8 Error, U8 ProtocolNum, const void *pProtocolData);
int  USBD_CCID_SendDataRateAndClockFrequency(const USB_CCID_CMD *pCmd, U8 Status, U8 Error, U32 ClockFrequency, U32 DataRate);


#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/
