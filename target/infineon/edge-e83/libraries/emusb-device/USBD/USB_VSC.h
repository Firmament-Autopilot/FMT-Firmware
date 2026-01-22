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
Purpose : Public header of the Vendor Specific Class
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_VSC_H          /* Avoid multiple inclusion */
#define USBD_VSC_H

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

#ifndef USBD_VSC_MAX_EPS
  #define USBD_VSC_MAX_EPS     8u
#endif


/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/
#define USB_VSC_READ_FLAG_RECEIVE           (1uL << 0)
#define USB_VSC_READ_FLAG_POLL              (1uL << 1)

#define USB_VSC_WRITE_FLAG_NO_NULL_PACKET   (1uL << 0)

#define USB_VSC_USE_CUSTOM_MSOSDESC         (1uL << 0)


#if USBD_VSC_MAX_EPS > 32u
  #pragma message("USBD_VSC_MAX_EPS > 32 which is beyond the max allowed EPs setting to USB 2.0 standard default == 32")
  #undef USBD_VSC_MAX_EPS
  #define USBD_VSC_MAX_EPS   32u
#endif

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef unsigned int USB_VSC_HANDLE;

/*********************************************************************
*
*       USB_VSC_MSOSDESC_INFO
*
*  Function description
*    MS OS descriptor structure that contains for MS related
*    OSes information how to deal with device with out having
*    a driver store.
*
*/
typedef struct {
  const char               * sCompatibleID;                 // Strings that gives MS OS a hint to the driver that shall be loaded
  const char               * sSubCompatibleID;              // [Optional] Gives a sub id string, in most cases this can be NULL.
  U32                        NumProperties;                 // NumBer of properties that are stored in pProperties
  const USB_MS_OS_EXT_PROP * pProperties;                   // Variable array of MS OS extended OS descriptors.
                                                            // Depending on the sCompatibleID, this can be some sub structure
                                                            // which will be stored in the Windows registry. Eg. with WinUSB this contains
                                                            // the GUID which is needed to identify your device among other WinUSB devices.
} USB_VSC_MSOSDESC_INFO;


/*********************************************************************
*
*       USB_ON_ADD_FUNCTION_DESC
*
*  Function description
*    Call back that is used to add an additional descriptor between the interface or
*    one of its alternate setting descriptor and the endpoint descriptor(s).
*
*  Parameters
*    hInst:                 Handle to a valid VSC instance, returned by USBD_VSC_Add().
*    IFAlternateSetting:    Data that should be written.
*
*  Return value
*    == NULL: No additional descriptor shall be added to this interface or its alternate setting..
*    != NULL: Pointer to a USB descriptor.
*
*  Additional information
*    USB Descriptor follow a specific format. The first byte is always the length.
*    The second byte describes the descriptor type. Anything after these 2 bytes
*    is descriptor dependent.
*/
typedef const U8 * (USB_VSC_ON_ADD_FUNCTION_DESC)(USB_VSC_HANDLE hInst, U8 IFAlternateSetting);

/*********************************************************************
*
*       USB_VSC_INIT_DATA
*
*  Function description
*    Initialization structure that is needed when adding a VSC interface to emUSB-Device.
*/
typedef struct {
  U16                            Flags;                    // Various flags.
                                                           // Currently only one flag is available:
                                                           // - USB_VSC_USE_CUSTOM_MSOSDESC: Allows to use a cutom specified MS OS Descriptor.
                                                           // Otherwise this has to be be initialized to 0.
  U8                             aEP[USBD_VSC_MAX_EPS];    // Array of Endpoints Indices to be used. Each EPIndex needs to be allocated by USBD_AddEP
  U8                             NumEPs;                   // Number of EPIndex in array.
  const char                  *  pInterfaceName;           // Name of the interface.
  U8                             InterfaceClass;           // Sets the USB Class ID .
  U8                             InterfaceSubClass;        // Sets the USB SubClass ID.
  U8                             InterfaceProtocol;        // Sets the USB Protocol ID.
  const USB_VSC_MSOSDESC_INFO *  pMSDescInfo;              // [Optional] This pointer will only be used when the Flag USB_VSC_USE_CUSTOM_MSOSDESC is set.
} USB_VSC_INIT_DATA;


/*********************************************************************
*
*       USB_VSC_ON_SET_INTERFACE
*
*  Function description
*    Global callback function that is called whenever an alternate setting is set
*    for an interface that was added with USBD_VSC_Add().
*
*  Parameters
*    hInst:                 Handle to a valid VSC instance, returned by USBD_VSC_Add().
*    AlternateInterface:    Alternate interface that was set by the host.
*
*  Additional information
*    Each interface has one alternate setting which is the default setting.
*    This call back is called after the host has set the alternate setting.
*    By default all data transfers of the previous interface/alternate
*    setting are canceled.
*/
typedef void (USB_VSC_ON_SET_INTERFACE)(USB_VSC_HANDLE hInst, U8 AlternateInterface);

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/

USB_VSC_HANDLE  USBD_VSC_Add                  (const USB_VSC_INIT_DATA * pInitData);
void            USBD_VSC_CancelIO             (U8 EPIndex);
unsigned        USBD_VSC_GetNumBytesInBuffer  (U8 EPIndex);
unsigned        USBD_VSC_GetNumBytesRemToRead (U8 EPIndex);
unsigned        USBD_VSC_GetNumBytesRemToWrite(U8 EPIndex);
int             USBD_VSC_Read                 (U8 EPIndex, void * pData, unsigned NumBytes, int Timeout, unsigned Flags);
void            USBD_VSC_ReadAsync            (U8 EPIndex, USB_ASYNC_IO_CONTEXT * pContext, int ShortRead);
void            USBD_VSC_SetOnEPEvent         (U8 EPIndex, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
int             USBD_VSC_WaitEP               (U8 EPIndex, unsigned Timeout);
int             USBD_VSC_PollEP               (U8 EPIndex, unsigned Timeout);
int             USBD_VSC_WaitForTXReady       (U8 EPIndex, int Timeout);
int             USBD_VSC_Write                (U8 EPIndex, const void * pData, unsigned NumBytes, int Timeout, unsigned Flags);
void            USBD_VSC_WriteAsync           (U8 EPIndex, USB_ASYNC_IO_CONTEXT * pContext, I8 Send0PacketIfRequired);
void            USBD_VSC_SetContinuousReadMode(U8 EPIndex);
int             USBD_VSC_TxIsPending          (U8 EPIndex);
void            USBD_VSC_StallEP              (U8 EPIndex);
void            USBD_VSC_SetOnAddFuncDesc     (USB_VSC_ON_ADD_FUNCTION_DESC * pfOnAddFuncDesc);
void            USBD_VSC_SetOnVendorRequest   (USB_VSC_HANDLE hInst, USB_ON_CLASS_REQUEST * pfOnVendorRequest);
void            USBD_VSC_SetOnSetupRequest    (USB_VSC_HANDLE hInst, USB_ON_SETUP * pfOnSetupRequest);
void            USBD_VSC_SetOnClassRequest    (USB_VSC_HANDLE hInst, USB_ON_CLASS_REQUEST * pfOnClassRequest);
void            USBD_VSC_AddAlternateInterface(USB_VSC_HANDLE hInst, const USB_VSC_INIT_DATA * pInitData);
void            USBD_VSC_SetOnSetInterface    (USB_VSC_ON_SET_INTERFACE * pOnSetInterface);

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/
