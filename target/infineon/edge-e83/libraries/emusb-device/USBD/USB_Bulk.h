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
Purpose : Public header of the bulk component
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_BULK_H          /* Avoid multiple inclusion */
#define USBD_BULK_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Defines, set default values
*
**********************************************************************
*/

#ifndef USB_BULK_ALLOW_SETUP_REQUESTS
  #define USB_BULK_ALLOW_SETUP_REQUESTS  0
#endif

#define USB_BULK_FLAG_USE_CUSTOM_CLASS_IDS  (1uL << 0)

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef int USB_BULK_HANDLE;

/*********************************************************************
*
*       USB_BULK_INIT_DATA
*
*  Function description
*    Initialization structure that is needed when adding a BULK interface to emUSB-Device.
*/
typedef struct {
  U8 EPIn;                        // Endpoint for sending data to the host.
  U8 EPOut;                       // Endpoint for receiving data from the host.
} USB_BULK_INIT_DATA;

/*********************************************************************
*
*       USB_BULK_INIT_DATA_EX
*
*  Function description
*    Initialization structure that is needed when adding a BULK interface to emUSB-Device.
*/
typedef struct {
  U16         Flags;              // Various flags.
                                  // Valid bits:
                                  // * USB_BULK_FLAG_USE_CUSTOM_CLASS_IDS - Allows to set custom values for the
                                  //                                        bInterfaceClass, bInterfaceSubClass and
                                  //                                        bInterfaceProtocol.
  U8          EPIn;               // Endpoint for sending data to the host.
  U8          EPOut;              // Endpoint for receiving data from the host.
  const char *pInterfaceName;     // Name of the interface.
  U8          InterfaceClass;     // Only used when Flags has the USB_BULK_FLAG_USE_CUSTOM_CLASS_IDS bit set.
                                  // Allows to set the USB Class ID to a different value (default is 0xFF).
  U8          InterfaceSubClass;  // Only used when Flags has the USB_BULK_FLAG_USE_CUSTOM_CLASS_IDS bit set.
                                  // Allows to set the USB SubClass ID to a different value (default is 0xFF).
  U8          InterfaceProtocol;  // Only used when Flags has the USB_BULK_FLAG_USE_CUSTOM_CLASS_IDS bit set.
                                  // Allows to set the USB Protocol ID to a different value (default is 0xFF).
} USB_BULK_INIT_DATA_EX;

typedef void (USB_ON_USER_SET_INTERFACE)(U8 AlternateInterface);

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void            USBD_BULK_Init                 (void);
USB_BULK_HANDLE USBD_BULK_Add                  (const USB_BULK_INIT_DATA * pInitData);
USB_BULK_HANDLE USBD_BULK_Add_Ex               (const USB_BULK_INIT_DATA_EX * pInitData);
void            USBD_BULK_SetMSDescInfo        (USB_BULK_HANDLE hInst);
void            USBD_BULK_CancelRead           (USB_BULK_HANDLE hInst);
void            USBD_BULK_CancelWrite          (USB_BULK_HANDLE hInst);
unsigned        USBD_BULK_GetNumBytesInBuffer  (USB_BULK_HANDLE hInst);
unsigned        USBD_BULK_GetNumBytesRemToRead (USB_BULK_HANDLE hInst);
unsigned        USBD_BULK_GetNumBytesRemToWrite(USB_BULK_HANDLE hInst);
int             USBD_BULK_Read                 (USB_BULK_HANDLE hInst, void * pData, unsigned NumBytes, unsigned Timeout);
int             USBD_BULK_ReadOverlapped       (USB_BULK_HANDLE hInst, void * pData, unsigned NumBytes);
int             USBD_BULK_Receive              (USB_BULK_HANDLE hInst, void * pData, unsigned NumBytes, int Timeout);
int             USBD_BULK_ReceivePoll          (USB_BULK_HANDLE hInst, void * pData, unsigned NumBytes, unsigned Timeout);
void            USBD_BULK_ReadAsync            (USB_BULK_HANDLE hInst, USB_ASYNC_IO_CONTEXT * pContext, int ShortRead);
void            USBD_BULK_SetOnRXHook          (USB_BULK_HANDLE hInst, USB_ON_RX_FUNC * pfOnRx);
void            USBD_BULK_SetOnTXEvent         (USB_BULK_HANDLE hInst, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
void            USBD_BULK_SetOnRXEvent         (USB_BULK_HANDLE hInst, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
int             USBD_BULK_WaitForRX            (USB_BULK_HANDLE hInst, unsigned Timeout);
int             USBD_BULK_PollForRX            (USB_BULK_HANDLE hInst, unsigned Timeout);
int             USBD_BULK_WaitForTX            (USB_BULK_HANDLE hInst, unsigned Timeout);
int             USBD_BULK_PollForTX            (USB_BULK_HANDLE hInst, unsigned Timeout);
int             USBD_BULK_WaitForTXReady       (USB_BULK_HANDLE hInst, int Timeout);
int             USBD_BULK_Write                (USB_BULK_HANDLE hInst, const void * pData, unsigned NumBytes, int Timeout);
int             USBD_BULK_WriteEx              (USB_BULK_HANDLE hInst, const void * pData, unsigned NumBytes, I8 Send0PacketIfRequired, int Timeout);
void            USBD_BULK_WriteAsync           (USB_BULK_HANDLE hInst, USB_ASYNC_IO_CONTEXT * pContext, I8 Send0PacketIfRequired);
void            USBD_BULK_SetContinuousReadMode(USB_BULK_HANDLE hInst);
int             USBD_BULK_TxIsPending          (USB_BULK_HANDLE hInst);
void            USBD_BULK_SetNumBytesWithout0Packet(U32 Bytes);
void            USBD_BULK_Stall                (USB_BULK_HANDLE hInst, int Out);
#if (USB_BULK_ALLOW_SETUP_REQUESTS == 1)
void            USBD_BULK_SetOnVendorRequest   (USB_BULK_HANDLE hInst, USB_ON_CLASS_REQUEST * pfOnVendorRequest);
void            USBD_BULK_SetOnSetupRequest    (USB_BULK_HANDLE hInst, USB_ON_SETUP * pfOnSetupRequest);
#endif
void            USBD_BULK_SetOnClassRequest    (USB_BULK_HANDLE hInst, USB_ON_CLASS_REQUEST * pfOnClassRequest);
void            USBD_BULK_AddAlternateInterface(USB_BULK_HANDLE hInst, const USB_BULK_INIT_DATA_EX* pInitData, USB_ON_USER_SET_INTERFACE * pfOnUser);

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_API > 0
#define USB_BULK_Init                          USBD_BULK_Init
#define USB_BULK_Add(x)                        USBD_BULK_Add(x)
#define USB_BULK_CancelRead()                  USBD_BULK_CancelRead(0)
#define USB_BULK_CancelWrite()                 USBD_BULK_CancelWrite(0)
#define USB_BULK_GetNumBytesInBuffer()         USBD_BULK_GetNumBytesInBuffer(0)
#define USB_BULK_GetNumBytesRemToRead()        USBD_BULK_GetNumBytesRemToRead(0)
#define USB_BULK_GetNumBytesToWrite()          USBD_BULK_GetNumBytesToWrite(0)
#define USB_BULK_Read(p, n)                    USBD_BULK_Read(0, p, n, 0)
#define USB_BULK_ReadTimed(p, n, t)            USBD_BULK_Read(0, p, n, t)
#define USB_BULK_ReadOverlapped(p, n)          USBD_BULK_ReadOverlapped(0, p, n)
#define USB_BULK_Receive(p, n)                 USBD_BULK_Receive(0, p, n, 0)
#define USB_BULK_ReceiveTimed(p, n, t)         USBD_BULK_Receive(0, p, n, t)
#define USB_BULK_SetOnRXHook(x)                USBD_BULK_SetOnRXHook(0, x)
#define USB_BULK_WaitForRX()                   USBD_BULK_WaitForRX(0, 0)
#define USB_BULK_WaitForTX()                   USBD_BULK_WaitForTX(0, 0)
#define USB_BULK_Write(p, n)                   USBD_BULK_Write(0, p, n, 0)
#define USB_BULK_WriteEx(p, n, s)              USBD_BULK_WriteEx(0, p, n, s, 0)
#define USB_BULK_WriteExTimed(p, n, s, t)      USBD_BULK_WriteEx(0, p, n, s, t)
#define USB_BULK_WriteOverlapped(p, n)         USBD_BULK_Write(0, p, n, -1)
#define USB_BULK_WriteOverlappedEx(p, n, s)    USBD_BULK_WriteEx(0, p, n, s, -1)
#define USB_BULK_WriteTimed(p, n, t)           USBD_BULK_Write(0, p, n, t)
#define USB_BULK_WriteNULLPacket()             USBD_BULK_Write(0, NULL, 0, 0)
#define USB_BULK_StartReadTransfer()           USBD_BULK_Receive(0, NULL, 0, -1)
#define USB_BULK_TxIsPending()                 USBD_BULK_TxIsPending(0)
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
