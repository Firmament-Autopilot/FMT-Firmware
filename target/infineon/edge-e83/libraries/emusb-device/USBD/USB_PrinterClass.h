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
Purpose : Sample implementation of USB printer device class
----------Literature--------------------------------------------------
Universal Serial Bus Device Class Definition for Printing Devices
Version 1.1 January 2000
-------------------------- END-OF-HEADER -----------------------------
*/
#ifndef USB_PRINTERCLASS_H__
#define USB_PRINTERCLASS_H__

#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       USB_PRINTER_GET_DEVICE_ID_STRING
*
*  Description
*    The library calls this function when the USB host requests
*    the printer's identification string. This string shall confirm to
*    the IEEE 1284 Device ID Syntax.
*
*  Return value
*    Pointer to the ID string.
*
*  Additional information
*   The return string shall confirm to the IEEE 1284 Device ID.
*/
typedef const char * USB_PRINTER_GET_DEVICE_ID_STRING (void);

/*********************************************************************
*
*       USB_PRINTER_ON_DATA_RECEIVED
*
*  Description
*    This function is called when data arrives from USB host.
*
*  Parameters
*    pData     : Pointer to the data.
*    NumBytes  : Data length.
*
*  Return value
*    == 0: More data can be accepted
*    != 0: No more data can be accepted, in this case a stall will be sent back to the host.
*/
typedef int          USB_PRINTER_ON_DATA_RECEIVED     (const U8 * pData, unsigned NumBytes);

/*********************************************************************
*
*       USB_PRINTER_GET_HAS_NO_ERROR
*
*  Description
*    This function should return a non-zero value if the printer has no error.
*
*  Return value
*    == 0: Error condition present.
*    != 0: No error.
*/
typedef U8           USB_PRINTER_GET_HAS_NO_ERROR     (void);

/*********************************************************************
*
*       USB_PRINTER_GET_IS_SELECTED
*
*  Description
*    This function should return a non-zero value if the printer is selected.
*
*  Return value
*    == 0: Not selected.
*    != 0: Selected.
*/
typedef U8           USB_PRINTER_GET_IS_SELECTED      (void);

/*********************************************************************
*
*       USB_PRINTER_GET_IS_PAPER_EMPTY
*
*  Description
*    This function should return a non-zero value if the printer is out of paper.
*
*  Return value
*    == 0: Has paper.
*    != 0: Out of paper.
*/
typedef U8           USB_PRINTER_GET_IS_PAPER_EMPTY   (void);

/*********************************************************************
*
*       USB_PRINTER_ON_RESET
*
*  Description
*    The library calls this function if the USB host sends a soft reset command.
*/
typedef void         USB_PRINTER_ON_RESET             (void);

/*********************************************************************
*
*       USB_PRINTER_API
*
*  Description
*    Initialization structure that is needed when adding a printer
*    interface to emUSB-Device. It holds pointers to callback functions
*    the interface invokes when it processes a request from the USB host.
*/
typedef struct USB_PRINTER_API {
  USB_PRINTER_GET_DEVICE_ID_STRING    *pfGetDeviceIdString; // The library calls this function when the USB host
                                                            // requests the printer's identification string.
  USB_PRINTER_ON_DATA_RECEIVED        *pfOnDataReceived;    // This function is called when data arrives from the USB host.
  USB_PRINTER_GET_HAS_NO_ERROR        *pfGetHasNoError;     // This function should return a non-zero value if the printer has no error.
  USB_PRINTER_GET_IS_SELECTED         *pfGetIsSelected;     // This function should return a non-zero value if the printer is selected
  USB_PRINTER_GET_IS_PAPER_EMPTY      *pfGetIsPaperEmpty;   // This function should return a non-zero value if the printer is out of paper.
  USB_PRINTER_ON_RESET                *pfOnReset;           // The library calls this function if the USB host sends a soft reset command.
} USB_PRINTER_API;

void  USB_PRINTER_Init                (USB_PRINTER_API * pAPI);
void  USB_PRINTER_Task                (void);
void  USB_PRINTER_TaskEx              (void);
int   USB_PRINTER_Read                (      void * pData, unsigned NumBytes);
int   USB_PRINTER_ReadTimed           (      void * pData, unsigned NumBytes, unsigned ms);
int   USB_PRINTER_Receive             (      void * pData, unsigned NumBytes);
int   USB_PRINTER_ReceiveTimed        (      void * pData, unsigned NumBytes, unsigned ms);
int   USB_PRINTER_Write               (const void * pData, unsigned NumBytes);
int   USB_PRINTER_WriteTimed          (const void * pData, unsigned NumBytes, int ms);
void  USB_PRINTER_SetOnVendorRequest  (USB_ON_CLASS_REQUEST * pfOnVendorRequest);
void  USB_PRINTER_ConfigIRQProcessing (void);
void  USB_PRINTER_SetClass            (U8 Class, U8 SubClass, U8 Protocol);

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif


#endif

/*************************** End of file ****************************/
