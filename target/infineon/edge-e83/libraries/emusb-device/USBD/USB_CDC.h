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
File    : USB_CDC.h
Purpose : Public header of the communication device class
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_CDC_H          /* Avoid multiple inclusion */
#define USBD_CDC_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif


/*********************************************************************
*
*       Config defaults
*
**********************************************************************
*/
#define CDC_USB_CLASS     2         // 2: Communication Device Class
#define CDC_USB_SUBCLASS  0x00      //
#define CDC_USB_PROTOCOL  0x00      //

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

/*********************************************************************
*
*       USB_CDC_LINE_CODING
*
*  Function description
*    Structure that contains the new line-coding information sent by the host.
*/
typedef struct {
  U32 DTERate;         // The data transfer rate for the device in bits per second.
  U8  CharFormat;      // Number of stop bits:
                       // * 0 - 1 Stop bit
                       // * 1 - 1.5 Stop bits
                       // * 2 - 2 Stop bits
  U8  ParityType;      // Specifies the parity type:
                       // * 0 - None
                       // * 1 - Odd
                       // * 2 - Even
                       // * 3 - Mark
                       // * 4 - Space
  U8  DataBits;        // Specifies the bits per byte: (5, 6, 7, 8)
} USB_CDC_LINE_CODING;

/*********************************************************************
*
*       USB_CDC_SERIAL_STATE
*
*  Function description
*    Structure that contains the serial state that can be sent to the host.
*
*  Additional information
*    All members of the structure may have value 0 (false) or 1 (true).
*/
typedef struct {
  U8 DCD;           // Data Carrier Detect: Tells that the device is connected to the telephone line.
  U8 DSR;           // Data Set Read: Device is ready to receive data.
  U8 Break;         // 1 - Break condition signaled.
  U8 Ring;          // Device indicates that it has detected a ring signal on the telephone line.
  U8 FramingError;  // When set to 1, the device indicates a framing error.
  U8 ParityError;   // When set to 1, the device indicates a parity error.
  U8 OverRunError;  // When set to 1, the device indicates an over-run error.
  U8 CTS;           // Clear to Send: Deprecated, not used with USB.
} USB_CDC_SERIAL_STATE;

/*********************************************************************
*
*       USB_CDC_CONTROL_LINE_STATE
*
*  Function description
*    Structure that contains the new control line state sent by the host.
*
*  Additional information
*    All members of the structure may have value 0 (false) or 1 (true).
*/
typedef struct {
  U8 DTR;       // Data Terminal Ready.
  U8 RTS;       // Request To Send.
} USB_CDC_CONTROL_LINE_STATE;

typedef void USB_CDC_ON_SET_LINE_CODING(USB_CDC_LINE_CODING * pLineCoding);
typedef void USB_CDC_ON_SET_CONTROL_LINE_STATE(USB_CDC_CONTROL_LINE_STATE * pLineState);
typedef void USB_CDC_ON_SET_BREAK(unsigned BreakDuration);

typedef int USB_CDC_HANDLE;

/*********************************************************************
*
*       USB_CDC_INIT_DATA
*
*  Function description
*    Initialization structure that is needed when adding a CDC interface to emUSB-Device.
*/
typedef struct {
  U8 EPIn;        // Bulk IN endpoint for sending data to the host.
  U8 EPOut;       // Bulk OUT endpoint for receiving data from the host.
  U8 EPInt;       // Interrupt IN endpoint for sending status information.
} USB_CDC_INIT_DATA;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void           USBD_CDC_Init                       (void);
USB_CDC_HANDLE USBD_CDC_Add                        (const USB_CDC_INIT_DATA * pInitData);
void           USBD_CDC_CancelRead                 (USB_CDC_HANDLE hInst);
void           USBD_CDC_CancelWrite                (USB_CDC_HANDLE hInst);
int            USBD_CDC_Read                       (USB_CDC_HANDLE hInst, void * pData, unsigned NumBytes, unsigned Timeout);
int            USBD_CDC_ReadOverlapped             (USB_CDC_HANDLE hInst, void * pData, unsigned NumBytes);
int            USBD_CDC_Receive                    (USB_CDC_HANDLE hInst, void * pData, unsigned NumBytes, int Timeout);
int            USBD_CDC_ReceivePoll                (USB_CDC_HANDLE hInst, void * pData, unsigned NumBytes, unsigned Timeout);
void           USBD_CDC_ReadAsync                  (USB_CDC_HANDLE hInst, USB_ASYNC_IO_CONTEXT * pContext, int ShortRead);
void           USBD_CDC_SetOnBreak                 (USB_CDC_HANDLE hInst, USB_CDC_ON_SET_BREAK * pfOnBreak);
void           USBD_CDC_SetOnLineCoding            (USB_CDC_HANDLE hInst, USB_CDC_ON_SET_LINE_CODING * pf);
void           USBD_CDC_SetOnControlLineState      (USB_CDC_HANDLE hInst, USB_CDC_ON_SET_CONTROL_LINE_STATE * pf);
void           USBD_CDC_WriteSerialState           (USB_CDC_HANDLE hInst);
void           USBD_CDC_UpdateSerialState          (USB_CDC_HANDLE hInst, const USB_CDC_SERIAL_STATE * pSerialState);
int            USBD_CDC_WaitForRX                  (USB_CDC_HANDLE hInst, unsigned Timeout);
int            USBD_CDC_PollForRX                  (USB_CDC_HANDLE hInst, unsigned Timeout);
int            USBD_CDC_WaitForTX                  (USB_CDC_HANDLE hInst, unsigned Timeout);
int            USBD_CDC_PollForTX                  (USB_CDC_HANDLE hInst, unsigned Timeout);
int            USBD_CDC_WaitForTXReady             (USB_CDC_HANDLE hInst, int Timeout);
int            USBD_CDC_Write                      (USB_CDC_HANDLE hInst, const void * pData, unsigned NumBytes, int Timeout);
int            USBD_CDC_WriteEx                    (USB_CDC_HANDLE hInst, const void * pData, unsigned NumBytes, I8 Send0PacketIfRequired, int Timeout);
void           USBD_CDC_WriteAsync                 (USB_CDC_HANDLE hInst, USB_ASYNC_IO_CONTEXT * pContext, I8 Send0PacketIfRequired);
int            USBD_CDC_GetNumBytesInBuffer        (USB_CDC_HANDLE hInst);
int            USBD_CDC_GetNumBytesRemToRead       (USB_CDC_HANDLE hInst);
int            USBD_CDC_GetNumBytesRemToWrite      (USB_CDC_HANDLE hInst);
int            USBD_CDC_TxIsPending                (USB_CDC_HANDLE hInst);
void           USBD_CDC_SetOnTXEvent               (USB_CDC_HANDLE hInst, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
void           USBD_CDC_SetOnRXEvent               (USB_CDC_HANDLE hInst, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
void           USBD_CDC_Stall                      (USB_CDC_HANDLE hInst);

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_API > 0
#define  USB_CDC_Init                            USBD_CDC_Init
#define  USB_CDC_Add(x)                          USBD_CDC_Add(x)
#define  USB_CDC_CancelRead()                    USBD_CDC_CancelRead(0)
#define  USB_CDC_CancelWrite()                   USBD_CDC_CancelWrite(0)
#define  USB_CDC_Read(p, n)                      USBD_CDC_Read(0, p, n, 0)
#define  USB_CDC_ReadOverlapped(p, n)            USBD_CDC_ReadOverlapped(0, p, n)
#define  USB_CDC_ReadTimed(p, n, t)              USBD_CDC_Read(0, p, n, t)
#define  USB_CDC_Receive(p, n)                   USBD_CDC_Receive(0, p, n, 0)
#define  USB_CDC_ReceiveTimed(p, n, t)           USBD_CDC_Receive(0, p, n, t)
#define  USB_CDC_SetOnBreak(pf)                  USBD_CDC_SetOnBreak(0, pf)
#define  USB_CDC_SetOnLineCoding(pf)             USBD_CDC_SetOnLineCoding(0, pf)
#define  USB_CDC_SetOnControlLineState(pf)       USBD_CDC_SetOnControlLineState(0, pf)
#define  USB_CDC_UpdateSerialState(ps)           USBD_CDC_UpdateSerialState(0, ps)
#define  USB_CDC_WaitForTX()                     USBD_CDC_WaitForTX(0, 0)
#define  USB_CDC_WaitForRX()                     USBD_CDC_WaitForRX(0, 0)
#define  USB_CDC_WriteSerialState()              USBD_CDC_WriteSerialState(0)
#define  USB_CDC_Write(p, n)                     USBD_CDC_Write(0, p, n, 0)
#define  USB_CDC_WriteOverlapped(p, n)           USBD_CDC_Write(0, p, n, -1)
#define  USB_CDC_WriteTimed(p, n, t)             USBD_CDC_Write(0, p, n, t)
#define  USB_CDC_StartReadTransfer()             USBD_CDC_Receive(0, NULL, 0, -1)
#define  USB_CDC_IsStartReadTransferActive()     (1)
#define  USB_CDC_GetNumBytesInBuffer()           USBD_CDC_GetNumBytesInBuffer(0)
#define  USB_CDC_GetNumBytesRemToRead()          USBD_CDC_GetNumBytesRemToRead(0)
#define  USB_CDC_GetNumBytesToWrite()            USBD_CDC_GetNumBytesRemToWrite(0)
#define  USB_CDC_TxIsPending()                   USBD_CDC_TxIsPending(0)

#define  USB_CDC_CancelReadEx(h)                 USBD_CDC_CancelRead(h)
#define  USB_CDC_CancelWriteEx(h)                USBD_CDC_CancelWrite(h)
#define  USB_CDC_ReadEx(h, p, n)                 USBD_CDC_Read(h, p, n, 0)
#define  USB_CDC_ReadOverlappedEx(h, p, n)       USBD_CDC_ReadOverlapped(h, p, n)
#define  USB_CDC_ReadTimedEx(h,p, n, t)          USBD_CDC_Read(h, p, n, t)
#define  USB_CDC_ReceiveEx(h, p, n)              USBD_CDC_Receive(h, p, n, 0)
#define  USB_CDC_ReceiveTimedEx(h, p, n, t)      USBD_CDC_Receive(h, p, n, t)
#define  USB_CDC_SetOnBreakEx(h, pf)             USBD_CDC_SetOnBreak(h, pf)
#define  USB_CDC_SetOnLineCodingEx(h, pf)        USBD_CDC_SetOnLineCoding(h, pf)
#define  USB_CDC_SetOnControlLineStateEx(h, pf)  USBD_CDC_SetOnControlLineState(h, pf)
#define  USB_CDC_UpdateSerialStateEx(h, ps)      USBD_CDC_UpdateSerialState(h, ps)
#define  USB_CDC_WaitForTXEx(h)                  USBD_CDC_WaitForTX(h, 0)
#define  USB_CDC_WaitForRXEx(h)                  USBD_CDC_WaitForRX(h, 0)
#define  USB_CDC_WriteEx(h, p, n)                USBD_CDC_Write(h, p, n, 0)
#define  USB_CDC_WriteOverlappedEx(h, p, n)      USBD_CDC_Write(h, p, n, -1)
#define  USB_CDC_WriteTimedEx(h, p, n, t)        USBD_CDC_Write(h, p, n, t)
#define  USB_CDC_WriteSerialStateEx(h)           USBD_CDC_WriteSerialState(h)
#define  USB_CDC_StartReadTransferEx(h)          USBD_CDC_Receive(h, NULL, 0, -1)
//lint -esym(621, USB_CDC_IsStartReadTransferActiveEx) N:100
#define  USB_CDC_IsStartReadTransferActiveEx(h)  (1)
#define  USB_CDC_GetNumBytesInBufferEx(h)        USBD_CDC_GetNumBytesInBuffer(h)
#define  USB_CDC_GetNumBytesRemToReadEx(h)       USBD_CDC_GetNumBytesRemToRead(h)
#define  USB_CDC_GetNumBytesToWriteEx(h)         USBD_CDC_GetNumBytesRemToWrite(h)
#define  USB_CDC_TxIsPendingEx(h)                USBD_CDC_TxIsPending(h)
#endif

/*********************************************************************
*  End of Wrapper
**********************************************************************
*/

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/
