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
Purpose : Public header of the human interface device class
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USB_HID_H          /* Avoid multiple inclusion */
#define USB_HID_H

#include "SEGGER.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Config defaults
*
**********************************************************************
*/
typedef int USB_HID_HANDLE;


/*********************************************************************
*
*       Const values
*
**********************************************************************
*/
#define USB_HID_USB_CLASS     3         // Human interface device class
#define USB_HID_USB_SUBCLASS  0x00      //
#define USB_HID_USB_PROTOCOL  0x00      //



// Section 4.2
#define USB_HID_NO_SUBCLASS                0
#define USB_HID_BOOT_INTERFACE_SUBCLASS    1

// Section 7.2.5
#define USB_HID_BOOT_PROTOCOL              0
#define USB_HID_REPORT_PROTOCOL            1

// HID report types
#define USB_HID_INPUT_REPORT                1
#define USB_HID_OUTPUT_REPORT               2
#define USB_HID_FEATURE_REPORT              3

// Report descriptor
// Section 6.2.2.4 - Main Items
#define USB_HID_MAIN_INPUT                   0x80
#define USB_HID_MAIN_OUTPUT                  0x90
#define USB_HID_MAIN_FEATURE                 0xB0
#define USB_HID_MAIN_COLLECTION              0xA0
#define USB_HID_MAIN_ENDCOLLECTION           0xC0

// Section 6.2.2.5 - Input, Output, and Features Items
#define USB_HID_DATA                     (0 << 0)
#define USB_HID_CONSTANT                 (1 << 0)
#define USB_HID_ARRAY                    (0 << 1)
#define USB_HID_VARIABLE                 (1 << 1)
#define USB_HID_ABSOLUTE                 (0 << 2)
#define USB_HID_RELATIVE                 (1 << 2)
#define USB_HID_NOWRAP                   (0 << 3)
#define USB_HID_WRAP                     (1 << 3)
#define USB_HID_LINEAR                   (0 << 4)
#define USB_HID_NONLINEAR                (1 << 4)
#define USB_HID_PREFERREDSTATE           (0 << 5)
#define USB_HID_NOPREFERRED              (1 << 5)
#define USB_HID_NONULLPOSITION           (0 << 6)
#define USB_HID_NULLSTATE                (1 << 6)
#define USB_HID_NONVOLATILE              (0 << 7)
#define USB_HID_VOLATILE                 (1 << 7)
#define USB_HID_BITFIELD                 (0 << 8)
#define USB_HID_BUFFEREDBYTES            (1 << 8)

// Section 6.2.2.6 - Collection, End Collection Items
#define USB_HID_COLLECTION_PHYSICAL          0x00
#define USB_HID_COLLECTION_APPLICATION       0x01
#define USB_HID_COLLECTION_LOGICAL           0x02
#define USB_HID_COLLECTION_REPORT            0x03
#define USB_HID_COLLECTION_NAMEDARRAY        0x04
//lint -esym(621, USB_HID_COLLECTION_USB_HID_USAGESWITCH, USB_HID_COLLECTION_USB_HID_USAGEMODIFIER)  N:100
#define USB_HID_COLLECTION_USB_HID_USAGESWITCH   0x05
#define USB_HID_COLLECTION_USB_HID_USAGEMODIFIER 0x06

//  Section 6.2.2.7
#define USB_HID_GLOBAL_USAGE_PAGE            0x04
#define USB_HID_GLOBAL_LOGICAL_MINIMUM       0x14
#define USB_HID_GLOBAL_LOGICAL_MAXIMUM       0x24
#define USB_HID_GLOBAL_PHYSICAL_MINIMUM      0x34
#define USB_HID_GLOBAL_PHYSICAL_MAXIMUM      0x44
#define USB_HID_GLOBAL_UNIT_EXPONENT         0x54
#define USB_HID_GLOBAL_UNIT                  0x64
#define USB_HID_GLOBAL_REPORT_SIZE           0x74
#define USB_HID_GLOBAL_REPORT_ID             0x84
#define USB_HID_GLOBAL_REPORT_COUNT          0x94
#define USB_HID_GLOBAL_PUSH                  0xA4
#define USB_HID_GLOBAL_POP                   0xB4

// Section 6.2.2.8
#define USB_HID_LOCAL_USAGE                  0x08
#define USB_HID_LOCAL_USAGE_MINIMUM          0x18
#define USB_HID_LOCAL_USAGE_MAXIMUM          0x28
#define USB_HID_LOCAL_DESIGNATOR_INDEX       0x38
#define USB_HID_LOCAL_DESIGNATOR_MINIMUM     0x48
#define USB_HID_LOCAL_DESIGNATOR_MAXIMUM     0x58
#define USB_HID_LOCAL_STRING_INDEX           0x78
#define USB_HID_LOCAL_STRING_MINIMUM         0x88
#define USB_HID_LOCAL_STRING_MAXIMUM         0x98
#define USB_HID_LOCAL_DELIMITER              0xA8

//   Usage pages
//   HuT1_12.pdf - Section 3 - Table 1

#define USB_HID_USAGE_PAGE_UNDEFINED            0x00
#define USB_HID_USAGE_PAGE_GENERIC_DESKTOP      0x01
#define USB_HID_USAGE_PAGE_SIMULATION           0x02
#define USB_HID_USAGE_PAGE_VR                   0x03
#define USB_HID_USAGE_PAGE_SPORT                0x04
#define USB_HID_USAGE_PAGE_GAME                 0x05
#define USB_HID_USAGE_PAGE_GENERIC_DEVICE       0x06
#define USB_HID_USAGE_PAGE_KEYBOARD_KEYPAD      0x07
#define USB_HID_USAGE_PAGE_LEDS                 0x08
#define USB_HID_USAGE_PAGE_BUTTON               0x09
#define USB_HID_USAGE_PAGE_ORDINAL              0x0A
#define USB_HID_USAGE_PAGE_TELEPHONY            0x0B
#define USB_HID_USAGE_PAGE_CONSUMER             0x0C
#define USB_HID_USAGE_PAGE_DIGITIZER            0x0D
#define USB_HID_USAGE_PAGE_PID                  0x0F
#define USB_HID_USAGE_PAGE_UNICODE              0x10

//  Scale
#define USB_HID_USAGE_PAGE_SCALE_PAGE           0x8D

//  Magnetic stripe reading devices
#define USB_HID_USAGE_PAGE_MSR                  0x8E

//  USB Device Class Definition for Image Class Devices
#define USB_HID_USAGE_PAGE_CAMERA_CONTROL       0x90

//  OAAF Definitions for arcade and coinop related devices
#define USB_HID_USAGE_PAGE_ARCADE               0x91

//   Generic Desktop Usages
//   see HuT1_12.pdf - Section 4 - Table 6

//  Pointer
#define USB_HID_USAGE_POINTER                   0x01

//  Mouse
#define USB_HID_USAGE_MOUSE                     0x02

//  Joystick
#define USB_HID_USAGE_JOYSTICK                  0x04

//  Game pad
#define USB_HID_USAGE_GAMEPAD                   0x05

//  Keyboard
#define USB_HID_USAGE_KEYBOARD                  0x06

//  Keypad
#define USB_HID_USAGE_KEYPAD                    0x07

//  Multi-axis controller
#define USB_HID_USAGE_MULTIAXIS                 0x08

//  X axis
#define USB_HID_USAGE_X                         0x30

//  Y axis
#define USB_HID_USAGE_Y                         0x31

//  Wheel
#define USB_HID_USAGE_WHEEL                     0x38

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

/*********************************************************************
*
*       USB_HID_INIT_DATA_EX
*
*   Description
*     Initialization structure that is needed when adding a HID
*     interface to emUSB-Device.
*
*   Additional information
*     To be able to receive input reports from the host either an endpoint must
*     be allocated (EPOut) or a buffer must be provided (BufferSize, pBuff).
*     If both EPOut == 0 and BufferSize == 0, then USBD_HID_Read() will not
*     work and all requests from the host will be stalled by the USB stack.
*     To receive Set Feature Report control commands the buffer is required.
*
*     pReport points to a report descriptor. A report descriptor is
*     a structure which is used to transmit HID control data to and
*     from a human interface device. A report descriptor defines
*     the format of a report and is composed of report items that define
*     one or more top-level collections. Each collection defines one or
*     more HID reports. Refer to Universal Serial Bus Specification,
*     1.0 Version and the latest version of the HID Usage Tables guide
*     for detailed information about HID input, output and feature reports.
*     The USB Implementers Forum provide an application that helps to
*     build and modify HID report descriptors. The HID Descriptor Tool
*     can be downloaded from:  www.usb.org/developers/hidpage/.
*     The report descriptor used in the supplied example application
*     HID_Echo1.c should match to the requirements of most
*     "vendor specific HID" applications. The report size is defined
*     to 64 bytes. As mentioned before, interrupt endpoints are limited
*     to at most one packet of at most 64 bytes per frame (on full
*     speed devices).
*/
typedef struct {
  U16           Flags;            // Reserved, must be set to 0.
  U8            EPIn;             // Endpoint for sending data to the host.
  U8            EPOut;            // Endpoint for receiving data from the host.
  const U8    * pReport;          // Pointer to a report descriptor.
  U16           NumBytesReport;   // Size of the HID report descriptor in bytes.
  U16           BuffSize;         // Size of the buffer pointed to by pBuff.
                                  // Must be at least the size of the output report.
  U8          * pBuff;            // Pointer to a buffer for receiving reports
                                  // from the host via endpoint 0 (Set_Report request).
  const char * pInterfaceName;    // Name of the interface. May be NULL.
} USB_HID_INIT_DATA_EX;

/*********************************************************************
*
*       USB_HID_INIT_DATA
*
*   Description
*     Initialization structure that is needed when adding a HID
*     interface to emUSB-Device.
*
*   Additional information
*     To be able to receive input reports from the host either an endpoint must
*     be allocated (EPOut) or a buffer must be provided (BufferSize, pBuff).
*     If both EPOut == 0 and BufferSize == 0, then USBD_HID_Read() will not
*     work and all requests from the host will be stalled by the USB stack.
*     To receive Set Feature Report control commands the buffer is required.
*
*     pReport points to a report descriptor. A report descriptor is
*     a structure which is used to transmit HID control data to and
*     from a human interface device. A report descriptor defines
*     the format of a report and is composed of report items that define
*     one or more top-level collections. Each collection defines one or
*     more HID reports. Refer to Universal Serial Bus Specification,
*     1.0 Version and the latest version of the HID Usage Tables guide
*     for detailed information about HID input, output and feature reports.
*     The USB Implementers Forum provide an application that helps to
*     build and modify HID report descriptors. The HID Descriptor Tool
*     can be downloaded from:  www.usb.org/developers/hidpage/.
*     The report descriptor used in the supplied example application
*     HID_Echo1.c should match to the requirements of most
*     "vendor specific HID" applications. The report size is defined
*     to 64 bytes. As mentioned before, interrupt endpoints are limited
*     to at most one packet of at most 64 bytes per frame (on full
*     speed devices).
*/
typedef struct {
  U8          EPIn;             // Endpoint for sending data to the host.
  U8          EPOut;            // Endpoint for receiving data from the host.
  const U8  * pReport;          // Pointer to a report descriptor.
  U16         NumBytesReport;   // Size of the HID report descriptor in bytes.
  U16         BuffSize;         // Size of the buffer pointed to by pBuff.
                                // Must be at least the size of the output report.
  U8        * pBuff;            // Pointer to a buffer for receiving reports
                                // from the host via endpoint 0 (Set_Report request).
} USB_HID_INIT_DATA;

typedef enum _USB_HID_REPORT_TYPE {
  USB_HID_REPORT_TYPE_NONE    = 0,
  USB_HID_REPORT_TYPE_INPUT   = USB_HID_INPUT_REPORT,
  USB_HID_REPORT_TYPE_OUTPUT  = USB_HID_OUTPUT_REPORT,
  USB_HID_REPORT_TYPE_FEATURE = USB_HID_FEATURE_REPORT
} USB_HID_REPORT_TYPE;

/*********************************************************************
*
*       USB_HID_ON_GETREPORT_REQUEST_FUNC
*
*   Description
*     Callback function which is set via
*     USBD_HID_SetOnGetReportRequest().
*
*   Parameters
*     ReportType  - HID report type, possible values are:
*                   * USB_HID_REPORT_TYPE_INPUT
*                   * USB_HID_REPORT_TYPE_OUTPUT
*                   * USB_HID_REPORT_TYPE_FEATURE
*     ReportId    - The ID of the report for which the GET_REPORT request has been sent.
*     pData       - [IN] Pointer to a pointer to the data to send via GET_REPORT request.
*     pNumBytes   - [IN] Number of bytes requested. Out: Number of bytes that shall be sent.
*
*   Return value
*     == 0: No data available. The stack will send a zero length packet as a response.
*     == 1: Data is available. The stack will send data to the host.
*      < 0: Data is handled by user application. USBD_WriteEP0FromISR() needs to be called from user context.
*/
typedef int  USB_HID_ON_GETREPORT_REQUEST_FUNC(USB_HID_REPORT_TYPE ReportType, unsigned ReportId, const U8 ** pData, U32 * pNumBytes);

/*********************************************************************
*
*       USB_HID_ON_SETREPORT_REQUEST_FUNC
*
*   Description
*     Callback function which is set via USBD_HID_SetOnSetReportRequest().
*     The function is called after a SET_REPORT command was sent from the host via
*     the control endpoint. The report should be read using USBD_HID_ReadReport().
*
*   Parameters
*     ReportType  - HID report type, possible values are:
*                   * USB_HID_REPORT_TYPE_INPUT
*                   * USB_HID_REPORT_TYPE_OUTPUT
*                   * USB_HID_REPORT_TYPE_FEATURE
*     ReportId    - The ID of the report for which the SET_REPORT request has been sent.
*
*   Additional information
*     In case no EP Out was used with the HID interface, and a USBD_HID_Read() or
*     USBD_HID_ReadOverlapped() is currently executed, then this function is not called and
*     the read function is serviced instead.
*/
typedef void USB_HID_ON_SETREPORT_REQUEST_FUNC(USB_HID_REPORT_TYPE ReportType, unsigned ReportId, U32 NumBytes);

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void           USBD_HID_Init                   (void);

USB_HID_HANDLE USBD_HID_Add                    (const USB_HID_INIT_DATA * pInitData);
USB_HID_HANDLE USBD_HID_AddEx                  (const USB_HID_INIT_DATA_EX * pInitData);

unsigned       USBD_HID_GetInterfaceNo         (USB_HID_HANDLE hInst);
unsigned       USBD_HID_GetNumBytesInBuffer    (USB_HID_HANDLE hInst);
unsigned       USBD_HID_GetNumBytesRemToWrite  (USB_HID_HANDLE hInst);
unsigned       USBD_HID_GetNumBytesRemToRead   (USB_HID_HANDLE hInst);

int            USBD_HID_ReadReport             (USB_HID_HANDLE hInst, void* pData, unsigned NumBytes);
int            USBD_HID_Receive                (USB_HID_HANDLE hInst, void* pData, unsigned NumBytes, int Timeout);
int            USBD_HID_ReceivePoll            (USB_HID_HANDLE hInst, void* pData, unsigned NumBytes, unsigned Timeout);
int            USBD_HID_Read                   (USB_HID_HANDLE hInst, void* pData, unsigned NumBytes, unsigned Timeout);
int            USBD_HID_ReadOverlapped         (USB_HID_HANDLE hInst, void* pData, unsigned NumBytes);
void           USBD_HID_StartReadTransfer      (USB_HID_HANDLE hInst);
int            USBD_HID_WaitForRX              (USB_HID_HANDLE hInst, unsigned Timeout);

int            USBD_HID_Write                  (USB_HID_HANDLE hInst, const void* pData, unsigned NumBytes, int Timeout);
int            USBD_HID_WaitForTX              (USB_HID_HANDLE hInst, unsigned Timeout);

void           USBD_HID_SetOnGetReportRequest  (USB_HID_HANDLE hInst, USB_HID_ON_GETREPORT_REQUEST_FUNC * pfOnGetReportRequest);
void           USBD_HID_SetOnSetReportRequest  (USB_HID_HANDLE hInst, USB_HID_ON_SETREPORT_REQUEST_FUNC * pfOnSetReportRequest);

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_API > 0
#define USB_HID_Init                             USBD_HID_Init
#define USB_HID_Add(x)                           USBD_HID_Add(x)
#define USB_HID_GetNumBytesInBuffer()            USBD_HID_GetNumBytesInBuffer(0)
#define USB_HID_Read(p, n)                       USBD_HID_Read(0, p, n, 0)
#define USB_HID_ReadTimed(p, n, t)               USBD_HID_Read(0, p, n, t)
#define USB_HID_ReadEPOverlapped(p, n)           USBD_HID_ReadOverlapped(0, p, n)
#define USB_HID_StartReadTransfer()              USBD_HID_StartReadTransfer(0)
#define USB_HID_Write(p, n)                      USBD_HID_Write(0, p, n, 0)
#define USB_HID_WriteTimed(p, n, t)              USBD_HID_Write(0, p, n, t)
#define USB_HID_WriteEPOverlapped(p, n)          USBD_HID_Write(0, p, n, -1)
#define USB_HID_GetNumBytesToWrite()             USBD_HID_GetNumBytesRemToWrite(0)
#define USB_HID_GetNumBytesRemToRead()           USBD_HID_GetNumBytesRemToRead(0)
#define USB_HID_WaitForTX()                      USBD_HID_WaitForTX(0, 0)
#define USB_HID_WaitForRX()                      USBD_HID_WaitForRX(0, 0)
#define USB_HID_IsStartReadTransferActive()      (1)

#define USB_HID_GetNumBytesInBufferEx(h)         USBD_HID_GetNumBytesInBuffer(h)
#define USB_HID_ReadEx(h, p, n)                  USBD_HID_Read(h, p, n, 0)
#define USB_HID_ReadExTimed(h, p, n, t)          USBD_HID_Read(h, p, n, t)
#define USB_HID_ReadEPOverlappedEx(h, p, n)      USBD_HID_ReadOverlapped(h, p, n)
#define USB_HID_StartReadTransferEx(h)           USBD_HID_StartReadTransfer(h)
#define USB_HID_WriteEx(h, p, n)                 USBD_HID_Write(h, p, n, 0)
#define USB_HID_WriteExTimed(h, p, n, t)         USBD_HID_Write(h, p, n, t)
#define USB_HID_WriteEPOverlappedEx(h, p, n)     USBD_HID_Write(h, p, n, -1)
#define USB_HID_GetNumBytesToWriteEx(h)          USBD_HID_GetNumBytesRemToWrite(h)
#define USB_HID_GetNumBytesRemToReadEx(h)        USBD_HID_GetNumBytesRemToRead(h)
#define USB_HID_WaitForTXEx(h)                   USBD_HID_WaitForTX(h, 0)
#define USB_HID_WaitForRXEx(h)                   USBD_HID_WaitForRX(h, 0)
//lint -esym(621, USB_HID_IsStartReadTransferActiveEx)  N:100
#define USB_HID_IsStartReadTransferActiveEx(h)   (1)
#endif

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/
