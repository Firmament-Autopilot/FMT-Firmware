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
Purpose : USB stack API
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USB_H     /* Avoid multiple inclusion */
#define USB_H

#include "SEGGER.h"
#include "USB_ConfDefaults.h"
#include <stddef.h>

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/

/* USB system version */
#define USB_VERSION  36605uL // Format: Mmmrr Example: 35601uL is 3.56.1


/*********************************************************************
*
*       Default values
*
*/
#ifndef   USB_MAX_PACKET_SIZE
  #if USB_SUPPORT_HIGH_SPEED
    #define USB_MAX_PACKET_SIZE   512u
  #else
    #define USB_MAX_PACKET_SIZE    64u
  #endif
#endif

//
// Maximum packet size defines for respective transfer types.
//
#define USB_SS_BULK_MAX_PACKET_SIZE     1024u
#define USB_HS_BULK_MAX_PACKET_SIZE      512u
#define USB_FS_BULK_MAX_PACKET_SIZE       64u
#define USB_HS_ISO_HB_MAX_PACKET_SIZE   3072u // ISO high-bandwidth
#define USB_SS_ISO_MAX_PACKET_SIZE     49152u
#define USB_HS_ISO_MAX_PACKET_SIZE      1024u
#define USB_FS_ISO_MAX_PACKET_SIZE      1023u
#define USB_SS_CONTROL_MAX_PACKET_SIZE   512u
#define USB_HS_CONTROL_MAX_PACKET_SIZE    64u
#define USB_FS_CONTROL_MAX_PACKET_SIZE    64u
//
// High-speed interrupt endpoints support 1024 bytes as per USB 2.0 spec.
// At the moment this is not supported by the stack, therefore this define is limited to 64.
//
#define USB_HS_INT_MAX_PACKET_SIZE        64u
#define USB_FS_INT_MAX_PACKET_SIZE        64u
#define USB_SS_INT_MAX_PACKET_SIZE        64u


#define USB_STATUS_ERROR           (-1)
#define USB_STATUS_BAD_READ_MODE   (-2)
#define USB_STATUS_EP_HALTED       (-3)
#define USB_STATUS_EP_BUSY         (-4)
#define USB_STATUS_INVALID_HANDLE  (-5)

#if USB_DEBUG_LEVEL > 0 || defined(__clang_analyzer__)
  #define USB_PANIC(ErrMsg)      USB_OS_Panic(ErrMsg)
#else
  #ifdef _lint
    //lint -emacro({9036}, USB_PANIC)  N:100
    #define USB_PANIC(ErrMsg)  do {} while(0)
  #else
    #define USB_PANIC(ErrMsg)
  #endif
#endif

#if USB_SUPPORT_LOG
  #define USB_LOG(p) USBD_Logf p
#else
  #ifdef _lint
    #define USB_LOG(p)  /*lint -save -e9036 N:102 */do {} while(0) /*lint -restore*/
  #else
    #define USB_LOG(p)
  #endif
#endif

#if USB_SUPPORT_WARN
  #define USB_WARN(p) USBD_Warnf p
#else
  #ifdef _lint
    #define USB_WARN(p)  /*lint -save -e9036 N:102 */do {} while(0) /*lint -restore*/
  #else
    #define USB_WARN(p)
  #endif
#endif

/*********************************************************************
*
*       Transfer types
*/
#define USB_TRANSFER_TYPE_CONTROL   0u
#define USB_TRANSFER_TYPE_ISO       1u
#define USB_TRANSFER_TYPE_BULK      2u
#define USB_TRANSFER_TYPE_INT       3u

/*********************************************************************
*
*       Endpoint direction
*/
#define USB_DIR_IN  1
#define USB_DIR_OUT 0

/*********************************************************************
*
*       Status flags
*/
#define USB_STAT_ATTACHED   (1u << 4)
#define USB_STAT_READY      (1u << 3)      // Set by any bus reset. Is required to go from "Powered" to "Addressed"
#define USB_STAT_ADDRESSED  (1u << 2)
#define USB_STAT_CONFIGURED (1u << 1)
#define USB_STAT_SUSPENDED  (1u << 0)

/*********************************************************************
*
*       Device state flags
*/
#define USB_DEVSTAT_SELF_POWERED             (1uL << 0)  // Device is self-powered.
#define USB_DEVSTAT_REMOTE_WAKEUP_ALLOWED    (1uL << 1)  // Remote Wakeup is allowed.
#define USB_DEVSTAT_U1_ENABLE                (1uL << 2)  // Link power state U1 is enabled (SuperSpeed only).
#define USB_DEVSTAT_U2_ENABLE                (1uL << 3)  // Link power state U2 is enabled (SuperSpeed only).
#define USB_DEVSTAT_LPM_ENABLE               (1uL << 4)  // Link power management is enabled (SuperSpeed only).

/*********************************************************************
*
*       USB speed
*/
#define USB_SPEED_NONE           0
#define USB_SPEED_FS             1
#define USB_SPEED_HS             2
#define USB_SPEED_SS             3

/*********************************************************************
*
*       Endpoint read mode
*/
#define USB_READ_MODE_CONTINUOUS    (1uL << 0)   // Always accept RX data independent of USB_Read...() calls,
                                                 // as long as there is enough free space in the buffer.

/*********************************************************************
*
*       Endpoint write mode
*/
#define USB_WRITE_MODE_EXTEND       (1uL << 0)   // Extend writes if possible

/*********************************************************************
*
*       Events for callback functions
*/
#define USB_EVENT_DATA_READ         (1uL << 0)
#define USB_EVENT_DATA_SEND         (1uL << 1)
#define USB_EVENT_DATA_ACKED        (1uL << 2)
#define USB_EVENT_READ_COMPLETE     (1uL << 3)
#define USB_EVENT_READ_ABORT        (1uL << 4)
#define USB_EVENT_WRITE_ABORT       (1uL << 5)
#define USB_EVENT_WRITE_COMPLETE    (1uL << 6)

/*********************************************************************
*
*       Message types
*
*  Description
*    The same message types are used for log and warning messages.
*    Separate filters can be used for both log and warnings.
*    For details, refer to USBD_SetLogFilter() and USBD_SetWarnFilter()
*    as wells as USBD_AddLogFilter() and USBD_AddWarnFilter() for more
*    information about using the message types.
*/
#define USB_MTYPE_INIT          (1UL <<  0)                 // Activates output of messages from the initialization of the stack that should be logged.
#define USB_MTYPE_CORE          (1UL <<  1)                 // Activates output of messages from the core of the stack that should be logged.
#define USB_MTYPE_CONFIG        (1UL <<  2)                 // Activates output of messages from the configuration of the stack.
#define USB_MTYPE_DRIVER        (1UL <<  3)                 // Activates output of messages from the driver that should be logged.
#define USB_MTYPE_ENUMERATION   (1UL <<  4)                 // Activates output of messages from enumeration that should be logged. Note: Since enumeration is handled in an ISR, use this with care as the timing will be changed greatly.
#define USB_MTYPE_CDC           (1UL <<  7)                 // Activates output of messages from CDC module that should be logged when a CDC connection is used.
#define USB_MTYPE_HID           (1UL <<  8)                 // Activates output of messages from HID module that should be logged when a HID connection is used.
#define USB_MTYPE_MSD           (1UL <<  9)                 // Activates output of messages from MSD module that should be logged when a MSD connection is used.
#define USB_MTYPE_MSD_CDROM     (1UL << 10)                 // Activates output of messages from MSD CDROM module that should be logged.
#define USB_MTYPE_MSD_PHY       (1UL << 11)                 // Activates output of messages from MSD Physical layer that should be logged.
#define USB_MTYPE_MTP           (1UL << 12)                 // Activates output of messages from MTP module that should be logged when a MTP connection is used.
#define USB_MTYPE_PRINTER       (1UL << 13)                 // Activates output of messages from Printer module that should be logged when Printer connection is used.
#define USB_MTYPE_RNDIS         (1UL << 14)                 // Activates output of messages from RNDIS module that should be logged when a RNIDS connection is used.
#define USB_MTYPE_VIRTUAL_MSD   (1UL << 16)                 // Activates output of messages from VirtualMSD module that should be logged when a VirtualMSD connection is used.
#define USB_MTYPE_UVC           (1UL << 17)                 // Activates output of messages from UVC module that should be logged when a UVC connection is used.
#define USB_MTYPE_ECM           (1UL << 18)                 // Activates output of messages from ECM module that should be logged when a ECM connection is used.
#define USB_MTYPE_AUDIO         (1UL << 19)                 // Activates output of messages from Audio module that should be logged when an audio connection is used.
#define USB_MTYPE_NCM           (1UL << 20)                 // Activates output of messages from NCM module that should be logged when a NCM connection is used.
#define USB_MTYPE_MIDI          (1UL << 21)                 // Activates output of messages from MIDI module that should be logged when a MIDI connection is used.
#define USB_MTYPE_INFO          (1UL << 31)                 // Non-maskable info messages

/*********************************************************************
*
*       MS OS relevant defines
*/
#define USB_MSOS_EXT_PROPTYPE_REG_NONE                        (0)   // No value type
#define USB_MSOS_EXT_PROPTYPE_REG_SZ                          (1)   // A NULL-terminated Unicode String (REG_SZ)
#define USB_MSOS_EXT_PROPTYPE_REG_EXPAND_SZ                   (2)   // A NULL-terminated Unicode String that includes environment variables (REG_EXPAND_SZ)

// (with environment variable references)
#define USB_MSOS_EXT_PROPTYPE_REG_BINARY                      (3)   // Free form binary
#define USB_MSOS_EXT_PROPTYPE_REG_DWORD                       (4)   // 32-bit number (LITTLE ENDIAN)
#define USB_MSOS_EXT_PROPTYPE_REG_DWORD_BIG_ENDIAN            (5)   // 32-bit number (BIG ENDIAN)
#define USB_MSOS_EXT_PROPTYPE_REG_LINK                        (6)   // Symbolic Link (unicode)
#define USB_MSOS_EXT_PROPTYPE_REG_MULTI_SZ                    (7)   // Multiple Unicode strings
#define USB_MSOS_EXT_PROPTYPE_REG_RESOURCE_LIST               (8)   // Resource list in the resource map
#define USB_MSOS_EXT_PROPTYPE_REG_FULL_RESOURCE_DESCRIPTOR    (9)   // Resource list in the hardware description
#define USB_MSOS_EXT_PROPTYPE_REG_RESOURCE_REQUIREMENTS_LIST (10)   // Microsoft resource requirement list.
#define USB_MSOS_EXT_PROPTYPE_REG_QWORD                      (11)   // 64-bit number

/*********************************************************************
*
*       Flags used in USB_ADD_EP_INFO
*/
#define USB_ADD_EP_FLAG_USE_ISO_SYNC_TYPES                  0x01u

/*********************************************************************
*
*       Isochronous endpoint relevant defines
*/
#define USB_ISO_SYNC_TYPE_NONE                              0x00u
#define USB_ISO_SYNC_TYPE_ASYNCHRONOUS                      0x01u
#define USB_ISO_SYNC_TYPE_ADAPTIVE                          0x02u
#define USB_ISO_SYNC_TYPE_SYNCHRONOUS                       0x03u

#define USB_ISO_SYNC_TYPE_EXP_FEEDBACK                      0x04u       // Is explicit feedback EP
#define USB_ISO_SYNC_TYPE_IMP_FEEDBACK                      0x08u       // Is data EP and implicit feedback EP for other EP

/*********************************************************************
*
*       Types / structures
*/

/*********************************************************************
*
*       USB_PORT_TYPE
*
*  Description
*    USB port types that can result from a Charging Port Detection.
*/
typedef enum {
  USB_PORT_TYPE_NOT_CONNECTED         = 0,  // Not connected.
  USB_PORT_TYPE_STANDARD_DOWNSTREAM   = 1,  // Connected to Standard Downstream Port.
  USB_PORT_TYPE_CHARGING_DOWNSTREAM   = 2,  // Connected to Charging Downstream Port.
  USB_PORT_TYPE_DEDICATED_CHARGING    = 3,  // Connected to Dedicated Charging Port.
  USB_PORT_TYPE_NON_STANDARD_CHARGING = 4,  // Connected to proprietary charger.
  USB_PORT_TYPE_ERROR                 = 99  // Charger detection failed.
} USB_PORT_TYPE;

/*********************************************************************
*
*       USB_DEVICE_INFO
*
*  Description
*    Device information that must be provided by the application via the function
*    USBD_SetDeviceInfo() before the USB stack is started using USBD_Start().
*    Is used during enumeration of the device by the host.
*/
typedef struct {
  U16  VendorId;                // Vendor ID. Uniquely identifies the vendor on a USB device.
  U16  ProductId;               // Product ID. Uniquely identifies all USB devices of a vendor.
  const char *sVendorName;      // Vendor name. ASCII string of up to 126 characters.
  const char *sProductName;     // Description of the USB device. ASCII string of up to 126 characters.
  const char *sSerialNumber;    // Serial number of the USB device (ASCII string).
                                // May be NULL if no serial number should be provided.
} USB_DEVICE_INFO;

/*********************************************************************
*
*       USB_SETUP_PACKET
*
*  Description
*    Structure containing a USB setup packet received from the host.
*/
typedef struct {
  U8 bmRequestType;     // Setup request type.
  U8 bRequest;          // Setup request number.
  U8 wValueLow;         // Low byte of the value field.
  U8 wValueHigh;        // High byte of the value field.
  U8 wIndexLow;         // Low byte of the index field.
  U8 wIndexHigh;        // High byte of the index field.
  U8 wLengthLow;        // Low byte of the length field.
  U8 wLengthHigh;       // High byte of the length field.
} USB_SETUP_PACKET;

/*********************************************************************
*
*       USB_WEBUSB_INFO
*
*  Description
*    Information that may be provided by the application for WebUSB capable USB devices.
*    Can be set via the function USBD_SetWebUSBInfo() before the USB stack is started using USBD_Start().
*    Is used during enumeration of the device by the host.
*/
typedef struct {
  U8  VendorCode;               // Vendor code used for the setup request.
  U8  DescIndex;                // Descriptor index of the descriptor containing the URL of the
                                // landing page.
  U8  URLPrefix;                // Prefix of the URL: 0 = "http://", 1 = "https://", 255 = none.
  const char *sURL;             // URL of the landing page. UTF-8 string.
} USB_WEBUSB_INFO;

typedef struct _EP_STAT EP_STAT;
typedef struct _USB_ASYNC_IO_CONTEXT *USB_ASYNC_IO_CONTEXT_POI;

typedef struct {
  const U8 * pData;
  U32        NumBytesRem;
} USB_DATA_PART;

typedef union USB_IOCTL_PARA_t USB_IOCTL_PARA;

typedef struct _USB_HW_DRIVER {
  void     (*pfStart)               (void);
  U8       (*pfAllocEP)             (U8 InDir, U8 TransferType);
  void     (*pfUpdateEP)            (EP_STAT * pEPStat);
  void     (*pfEnable)              (void);
  void     (*pfAttach)              (void);
  unsigned (*pfGetMaxPacketSize)    (unsigned EPIndex);
  int      (*pfGetSpeedInfo)        (void);
  void     (*pfSetAddress)          (U8  Addr);
  void     (*pfSetClrStallEP)       (unsigned EPIndex, int OnOnff);
  void     (*pfStallEP0)            (void);
  void     (*pfDisableRxInterruptEP)(unsigned EPIndex);
  void     (*pfEnableRxInterruptEP) (unsigned EPIndex, U8 *pData, U32 NumBytesRequested);
  void     (*pfStartTx)             (unsigned EPIndex);
  void     (*pfSendEP)              (unsigned EPIndex, const U8 * p, unsigned NumBytes);
  void     (*pfDisableTx)           (unsigned EPIndex);
  void     (*pfResetEP)             (unsigned EPIndex);
  int      (*pfControl)             (int Cmd, USB_IOCTL_PARA * p);
  int      (*pfDeInit)              (void);
  int      (*pfDetach)              (void);
  U8       (*pfAllocEPEx)           (U8 InDir, U8 TransferType, unsigned MaxPacketSize);
  int      (*pfSendEPEx)            (unsigned EPIndex, unsigned NumParts, const USB_DATA_PART *pParts, unsigned *pNumOfFullPackets);
  void     (*pfInit)                (void);
} USB_HW_DRIVER;

/*********************************************************************
*
*       USB_ON_CLASS_REQUEST
*
*  Description
*    Type of callback set in USBD_SetClassRequestHook() or USBD_SetVendorRequestHook().
*    This function is called when a setup class request
*    is sent from the host to the specified interface index.
*
*  Parameters
*    pSetupPacket : Pointer to the setup packet received from the host.
*
*  Return value
*    If the function has processed the setup packet, it must acknowledge the packet
*    by either sending a response packet using USBD_WriteEP0FromISR() or an empty packet with
*    USBD_WriteEP0FromISR(NULL, 0, 0) and must return 0.
*
*    If the function can't process the packet, it must return 1.
*    In this case the USB stacks tries to process the packet and will send a STALL
*    if that fails.
*/
typedef int          USB_ON_CLASS_REQUEST     (const USB_SETUP_PACKET * pSetupPacket);

/*********************************************************************
*
*       USB_ON_SETUP
*
*  Description
*    Type of callback set in USBD_SetOnSetup().
*    This function is called when a setup request was sent from the host.
*
*  Parameters
*    pSetupPacket : Pointer to the setup packet received from the host.
*
*  Return value
*    If the function has processed the setup packet, it must acknowledge the packet
*    by either sending a response packet using USBD_WriteEP0FromISR() or an empty packet with
*    USBD_WriteEP0FromISR(NULL, 0, 0) and must return 0.
*
*    If the function can't process the packet, it must return 1.
*    In this case the USB stacks tries to process the packet and will send a STALL
*    if that fails.
*/
typedef int          USB_ON_SETUP             (const USB_SETUP_PACKET * pSetupPacket);

/*********************************************************************
*
*       USB_ON_LPM_CHANGE
*
*  Description
*    Type of callback set in USBD_SetOnLPMChange().
*    This function is called when a LPM transition on the USB lines (L0 <-> L1) is detected.
*
*  Parameters
*    State:  * -1 - Transition to L0.
*            *  0 - Transition to L1. Remote wakeup not allowed.
*            *  1 - Transition to L1. Remote wakeup allowed.
*    BESL:   BESL value (Best Effort Service Latency) in range 0...15 reported by the host
*            when requesting a transition to L1 state. Values of 0,1,...,14,15 specify a BESL
*            of 125us,150us,...,9000us,10000us respectively,
*            see "Errata for USB 2.0 ECN: Link Power Management (LPM) - 7/2007" from usb.org for
*            an explanation of these values.
*/
typedef void         USB_ON_LPM_CHANGE        (int State, unsigned BESL);

/*********************************************************************
*
*       USB_GET_STRING_FUNC
*
*  Description
*    Type of callback set in USBD_SetGetStringHook().
*    This function is called when a string descriptor is requested from the host.
*
*  Parameters
*    Index : Index of the requested string.
*
*  Return value
*    If the function is able to provide a string for the given index, it should return a pointer to
*    an ASCII string. Otherwise it should return a NULL pointer.
*/
typedef const char * USB_GET_STRING_FUNC      (int Index);

typedef void         USB_ON_RX_FUNC           (const U8 * pData, unsigned NumBytes);
typedef void         USB_ISR_HANDLER          (void);
typedef void         USB_DETACH_FUNC          (void);
typedef U16          USB_ON_BCD_VERSION_FUNC  (void);
typedef const char * USB_ON_STRING_REQUEST    (void);
typedef void         USB_ON_SET_IF_FUNC       (U16 wIndex, U16 wValue, void * pContext);
typedef void         USB_ON_GET_IF_FUNC       (U16 wIndex, void * pContext);
typedef void         USB_EVENT_CALLBACK_FUNC  (unsigned Events, void * pContext);
typedef void         USB_ATTACH_FUNC          (void);
typedef void         USB_ENABLE_ISR_FUNC      (USB_ISR_HANDLER * pfISRHandler);
typedef void         USB_STATE_CALLBACK_FUNC  (void * pContext, U8 NewState);
typedef void         USB_ASYNC_CALLBACK_FUNC  (USB_ASYNC_IO_CONTEXT_POI pContext);

typedef struct _USB_EVENT_CALLBACK {
  struct _USB_EVENT_CALLBACK  *pNext;
  USB_EVENT_CALLBACK_FUNC     *pfEventCb;
  void                        *pContext;
} USB_EVENT_CALLBACK;

typedef struct _USB_HOOK {
  struct _USB_HOOK        * pNext;
  USB_STATE_CALLBACK_FUNC * cb;
  void                    * pContext;
} USB_HOOK;

typedef struct _USB_SETUP_HOOK {
  struct _USB_SETUP_HOOK * pNext;
  USB_ON_SETUP           * cb;
} USB_SETUP_HOOK;

typedef struct _USB_SOF_CALLBACK_HOOK {
  struct _USB_SOF_CALLBACK_HOOK *pNext;
  U16                            Interval;
  U16                            Count;
  void                         (*cb)(void *pContext);
  void                          *pContext;
} USB_SOF_CALLBACK_HOOK;

typedef struct _USB_MS_OS_EXT_PROP {
  U32          PropType;
  const char * sPropName;
  const void * pProp;
  U32          PropSize;
} USB_MS_OS_EXT_PROP;

typedef struct _USB_GET_STRING_DESC_HOOK {
  struct _USB_GET_STRING_DESC_HOOK * pNext;
  USB_GET_STRING_FUNC              * pfGetString;
} USB_GET_STRING_DESC_HOOK;

/*********************************************************************
*
*       USB_ADD_EP_INFO
*
*  Description
*    Structure used by USBD_AddEPEx() when adding an endpoint.
*
*  Additional information
*    The Interval parameter specifies the frequency in which the endpoint should be
*    polled for information by the host. It must be specified in units of 125 us.
*    Depending on the actual speed of the device during enumeration, the USB stack
*    converts the interval to the correct value required for the endpoint descriptor
*    according to the USB specification (into milliseconds for low/full-speed, into 125 us
*    for high-speed).
*    For endpoints of type USB_TRANSFER_TYPE_BULK the value is ignored and should be set to 0.
*
*    The actual maximum packet size for bulk endpoints may be smaller than given in the 'MaxPacketSize'
*    field to meet the requirements of the actual USB speed.
*
*    For SuperSpeed bulk endpoints, MaxPacketSize can be N * 1024, where N = 1...16.
*    Values of N > 1 enables the usage of burst transfers.
*/
typedef struct _USB_ADD_EP_INFO {
  unsigned  MaxPacketSize;    // Maximum packet size for the endpoint.
  U16       Interval;         // Specifies the interval measured in units of 125us (microframes).
                              // This value should be zero for a bulk endpoint.
  U8        Flags;            // Specifies whether optional parameters are used.
                              // * 0x00 - Ignore optional parameters.
                              // * USB_ADD_EP_FLAG_USE_ISO_SYNC_TYPES - Use ISO_Type. If not set the endpoint will have the sync type USB_ISO_SYNC_TYPE_NONE.
  U8        InDir;            // Specifies the direction of the desired endpoint.
                              // * USB_DIR_IN
                              // * USB_DIR_OUT
  U8        TransferType;     // Specifies the transfer type of the endpoint.
                              // The following values are allowed:
                              // * USB_TRANSFER_TYPE_BULK
                              // * USB_TRANSFER_TYPE_ISO
                              // * USB_TRANSFER_TYPE_INT
  U8        ISO_Type;         // Allows to set the synchronization type for isochronous endpoints.
                              // The following types are supported:
                              // * USB_ISO_SYNC_TYPE_NONE (default)
                              // * USB_ISO_SYNC_TYPE_ASYNCHRONOUS
                              // * USB_ISO_SYNC_TYPE_ADAPTIVE
                              // * USB_ISO_SYNC_TYPE_SYNCHRONOUS
} USB_ADD_EP_INFO;


/*********************************************************************
*
*       USB_ASYNC_IO_CONTEXT
*
*  Description
*    Contains information for asynchronous transfers.
*/
typedef struct _USB_ASYNC_IO_CONTEXT {
  unsigned                  NumBytesToTransfer;     // Number of bytes to transfer.
                                                    // Must be set by the application.
  void                    * pData;                  // Pointer to the buffer for read operations, pointer to the data for write operations.
                                                    // Must be set by the application.
  USB_ASYNC_CALLBACK_FUNC * pfOnComplete;           // Pointer to the function called on completion of the transfer.
                                                    // Must be set by the application.
  void                    * pContext;               // Pointer to a user context. Can be arbitrarily used by the application.
  int                       Status;                 // Result status of the asynchronous transfer. Set by the USB stack before calling pfOnComplete.
  unsigned                  NumBytesTransferred;    // Number of bytes transferred. Set by the USB stack before calling pfOnComplete.
} USB_ASYNC_IO_CONTEXT;

/*********************************************************************
*
*       Public API functions
*/
unsigned USBD_AddEP                     (U8 InDir, U8 TransferType, U16 Interval, U8 * pBuffer, unsigned BufferSize);
unsigned USBD_AddEPEx                   (const USB_ADD_EP_INFO * pInfo, U8 * pBuffer, unsigned BufferSize);
void     USBD_DeInit                    (void);
void     USBD_EnableIAD                 (void);
void     USBD_EnableSuperSpeed          (void);
unsigned USBD_GetState                  (void);
unsigned USBD_GetDeviceState            (void);
int      USBD_GetSpeed                  (void);
void     USBD_Init                      (void);
U32      USBD_GetVersion                (void);
char     USBD_IsConfigured              (void);
void     USBD_SetMaxPower               (unsigned MaxPower);
void     USBD_Start                     (void);
void     USBD_Stop                      (void);
int      USBD_RegisterSCHook            (USB_HOOK * pHook, USB_STATE_CALLBACK_FUNC *pfStateCb, void * pContext);
int      USBD_UnregisterSCHook          (USB_HOOK * pHook);

int      USBD_Read                      (unsigned EPOut, void* pData, unsigned NumBytesReq, unsigned Timeout);
int      USBD_Receive                   (unsigned EPOut, void* pData, unsigned NumBytesReq, int Timeout);
int      USBD_ReceivePoll               (unsigned EPOut, void* pData, unsigned NumBytesReq, unsigned Timeout);
int      USBD_ReadOverlapped            (unsigned EPOut, void* pData, unsigned NumBytesReq);
int      USBD_Write                     (unsigned EPIndex, const void* pData, unsigned NumBytes, I8 Send0PacketIfRequired, int ms);
int      USBD_WriteOverlapped           (unsigned EPIndex, const void* pData, unsigned NumBytes, I8 Send0PacketIfRequired);
void     USBD_CancelIO                  (unsigned EPIndex);
void     USBD_ReadAsync                 (unsigned EPIndex, USB_ASYNC_IO_CONTEXT * pContext, int ShortRead);
void     USBD_WriteAsync                (unsigned EPIndex, USB_ASYNC_IO_CONTEXT * pContext, I8 Send0PacketIfRequired);
unsigned USBD_GetNumBytesInBuffer       (unsigned EPIndex);
unsigned USBD_GetNumBytesRemToWrite     (unsigned EPIndex);
unsigned USBD_GetNumBytesRemToRead      (unsigned EPIndex);
void     USBD_SetOnRXHookEP             (unsigned EPIndex, USB_ON_RX_FUNC * pfOnRx);
void     USBD_SetClrStallEP             (unsigned EPIndex, int OnOff);
void     USBD_StallEP                   (unsigned EPIndex);
int      USBD_WaitForEndOfTransfer      (unsigned EPIndex, unsigned Timeout);
int      USBD_WaitForEndOfTransferEx    (unsigned EPIndex, unsigned Timeout, int AbortOnTimeout);
int      USBD_WaitForTXReady            (unsigned EPIndex, int Timeout);
unsigned USBD_GetReadMode               (unsigned EPIndex);
void     USBD_SetReadMode               (unsigned EPIndex, unsigned Mode);
unsigned USBD_GetWriteMode              (unsigned EPIndex);
void     USBD_SetWriteMode              (unsigned EPIndex, unsigned Mode);
void     USBD_SetOnEvent                (unsigned EPIndex, USB_EVENT_CALLBACK *pEventCb, USB_EVENT_CALLBACK_FUNC *pfEventCb, void *pContext);
void     USBD_RemoveOnEvent             (unsigned EPIndex, const USB_EVENT_CALLBACK *pEventCb);
int      USBD_IsNULLPacketRequired      (unsigned EPIndex);

void     USBD_SetClassRequestHook       (unsigned InterfaceNum, USB_ON_CLASS_REQUEST * pfOnClassRequest);
void     USBD_SetVendorRequestHook      (unsigned InterfaceNum, USB_ON_CLASS_REQUEST * pfOnVendorRequest);
void     USBD_SetOnSetupHook            (unsigned InterfaceNum, USB_ON_SETUP         * pfOnSetup);
void     USBD_SetOnSetInterfaceHook     (unsigned InterfaceNum, USB_ON_SET_IF_FUNC   * pfOnSetInterface, void * pContext);
void     USBD_SetOnGetInterfaceHook     (unsigned InterfaceNum, USB_ON_GET_IF_FUNC   * pfOnSetInterface, void * pContext);
void     USBD_SetOnSetup                (USB_SETUP_HOOK * pHook, USB_ON_SETUP        * pfOnSetup);

void     USBD_SetOnRxEP0                (USB_ON_RX_FUNC       * pfOnRx);
void     USBD_SetDetachFunc             (USB_DETACH_FUNC * pfDetach);
void     USBD_SetGetStringFunc          (USB_GET_STRING_FUNC * pfOnGetString);
void     USBD_SetGetStringHook          (USB_GET_STRING_DESC_HOOK * pHook, USB_GET_STRING_FUNC * pfOnGetString);
void     USBD_SetOnBCDVersionFunc       (USB_ON_BCD_VERSION_FUNC * pfOnBCDVersion);

void     USBD_DoRemoteWakeup            (void);
void     USBD_SetIsSelfPowered          (U8 IsSelfPowered);
void     USBD_SetAllowRemoteWakeUp      (U8 AllowRemoteWakeup);
void     USBD_UseV210                   (void);
void     USBD_SetBESLValues             (int BaselineBESL, int DeepBESL);
void     USBD_SetOnLPMChange            (USB_ON_LPM_CHANGE * pfOnLPMChange);
void     USBD_SetLPMResponse            (U8 Response);
int      USBD_TxIsPending               (unsigned EPIndex);

unsigned USBD_GetMaxPacketSize          (unsigned EPIndex);
unsigned USBD_GetInternalBufferSize     (unsigned EPIndex);

void     USBD_SetMSDescInfo             (U8 InterfaceNum, const char * sCompatibleID, const char * sSubCompatibleID, const USB_MS_OS_EXT_PROP * pProperties, U32 NumProperties);
void     USBD_SetMSVendorCode           (U8 VendorCode);
void     USBD_MSOSD_Init                (void);

unsigned USBD_GetUSBAddr                (void);
void     USBD_WriteEP0FromISR           (const void* pData, unsigned NumBytes, I8 Send0PacketIfRequired);
int      USBD_SetOnSOF                  (void (*pfSOFCallback)(void *pContext), U16 Interval, void *pContext, USB_SOF_CALLBACK_HOOK *pHook);
void     USBD_RemoveOnSOF               (const USB_SOF_CALLBACK_HOOK *pHook);

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*/
#if USB_V2_V3_MIGRATION_API > 0
#define USB_AddDriver                          USBD_AddDriver
#define USB_AddEP                              USBD_AddEP
#define USB_EnableIAD                          USBD_EnableIAD
#define USB_GetState                           USBD_GetState
#define USB_Init                               USBD_Init
#define USB_IsConfigured                       USBD_IsConfigured
#define USB_SetMaxPower                        USBD_SetMaxPower
#define USB_Start                              USBD_Start
#define USB_Stop                               USBD_Stop
#define USB_RegisterSCHook                     USBD_RegisterSCHook
#define USB_UnregisterSCHook                   USBD_UnregisterSCHook
#define USB_DeInit                             USBD_DeInit

#define USB_CancelIO                           USBD_CancelIO
#define USB_GetNumBytesInBuffer                USBD_GetNumBytesInBuffer

int     USB_ReadEP                             (unsigned EPIndex, void * pData, unsigned NumBytesReq);
int     USB_ReadEPOverlapped                   (unsigned EPIndex, void * pData, unsigned NumBytesReq);
int     USB_ReadEPTimed                        (unsigned EPIndex, void * pData, unsigned NumBytesReq, unsigned ms);
int     USB_ReceiveEP                          (unsigned EPIndex, void * pData, unsigned NumBytesReq);
int     USB_ReceiveEPTimed                     (unsigned EPIndex, void * pData, unsigned NumBytesReq, unsigned ms);
#define USB_WriteEP(h, p, n, s)                USBD_Write(h, p, n, s, 0)
#define USB_WriteEPOverlapped(h, p, n, s)      USBD_WriteOverlapped(h, p, n, s)
#define USB_WriteEPTimed(h, p, n, s, t)        USBD_Write(h, p, n, s, t)
void    USB_StartReadTransfer                  (unsigned EPIndex);
int     USB_IsStartReadTransferActive          (unsigned EPIndex);

#define USB_SetOnRXHookEP                      USBD_SetOnRXHookEP
#define USB_SetClrStallEP                      USBD_SetClrStallEP
#define USB_StallEP                            USBD_StallEP
#define USB_WaitForEndOfTransfer               USBD_WaitForEndOfTransfer

#define USB_SetClassRequestHook                USBD_SetClassRequestHook
#define USB_SetVendorRequestHook               USBD_SetVendorRequestHook
#define USB_SetOnSetupHook                     USBD_SetOnSetupHook
#define USB_SetOnRxEP0                         USBD_SetOnRxEP0
#define USB_SetDetachFunc                      USBD_SetDetachFunc
#define USB_SetGetStringFunc                   USBD_SetGetStringFunc
#define USB_SetOnBCDVersionFunc                USBD_SetOnBCDVersionFunc

#define USB_DoRemoteWakeup                     USBD_DoRemoteWakeup
#define USB_SetIsSelfPowered                   USBD_SetIsSelfPowered
#define USB_SetAllowRemoteWakeUp               USBD_SetAllowRemoteWakeUp
#define USB_TxIsPending                        USBD_TxIsPending
#define USB_GetMaxPacketSize                   USBD_GetMaxPacketSize
#define USB_GetInternalBufferSize              USBD_GetInternalBufferSize
#endif

/*********************************************************************
*
*       Kernel interface routines      (also for polled mode without kernel)
*/
void     USB_OS_Init                   (void);
void     USB_OS_Delay                  (int ms);
void     USB_OS_DecRI                  (void);
U32      USB_OS_GetTickCnt             (void);
void     USB_OS_IncDI                  (void);
#if USBD_OS_LAYER_EX > 0
void     USB_OS_Signal                 (unsigned EPIndex, unsigned TransactCnt);
void     USB_OS_Wait                   (unsigned EPIndex, unsigned TransactCnt);
int      USB_OS_WaitTimed              (unsigned EPIndex, unsigned ms, unsigned TransactCnt);
void     USB_OS_DeInit                 (void);
#else
  #error "Legacy OS layer API is no longer supported"
#endif
int      USB_OS_MutexAlloc             (void);
void     USB_OS_MutexFree              (void);
void     USB_OS_MutexLock              (int Idx);
void     USB_OS_MutexUnlock            (int Idx);
#ifdef __clang_analyzer__
  void   USB_OS_Panic                  (const char *pErrMsg) __attribute__((analyzer_noreturn));
#else
  void   USB_OS_Panic                  (const char *pErrMsg);
#endif
#if USBD_OS_USE_ISR_FLAG
  extern volatile I8                   USBD_IsInInterrupt;
#endif

/*********************************************************************
*
*       Log/Warn functions
*/
void USBD_SetLogFilter                  (U32 FilterMask);
void USBD_SetWarnFilter                 (U32 FilterMask);
void USBD_AddLogFilter                  (U32 FilterMask);
void USBD_AddWarnFilter                 (U32 FilterMask);
void USBD_Logf                          (U32 Type,       const char * sFormat, ...);
void USBD_Warnf                         (U32 Type,       const char * sFormat, ...);
void USBD_Logf_Application              (const char * sFormat, ...);
void USBD_LogHexDump                    (U32 Type, U32 Len, const void *pvData);
void USBD_Puts                          (const char * s);

#if USB_V2_V3_MIGRATION_API > 0
//
// obsolete function, do not use these functions.
// They are only for compatibility reasons here.
// Use instead USBD_* functions.
//
#define USB_SetLogFilter(FilterMask)    USBD_SetLogFilter(FilterMask)
#define USB_SetWarnFilter(FilterMask)   USBD_SetWarnFilter(FilterMask)
#define USB_AddLogFilter(FilterMask)    USBD_AddLogFilter(FilterMask)
#define USB_AddWarnFilter(FilterMask)   USBD_AddWarnFilter(FilterMask)
#endif

void USBD_SetWarnFunc                   (void (*pfWarn)(const char *s));
void USBD_SetLogFunc                    (void (*pfLog) (const char *s));

/*********************************************************************
*
*       USB configuration functions, to be called in USB_X_Config()
*/
void USBD_AddDriver                     (const USB_HW_DRIVER * pDriver);
void USBD_SetAttachFunc                 (USB_ATTACH_FUNC *pfAttach);
void USBD_SetISREnableFunc              (USB_ENABLE_ISR_FUNC *pfEnableISR);
void USBD_SetDeviceInfo                 (const USB_DEVICE_INFO *pDeviceInfo);
void USBD_SetCacheConfig                (const SEGGER_CACHE_CONFIG *pConfig, unsigned ConfSize);
void USBD_AssignMemory                  (void *pMem, U32 MemSize);
void USBD_SetWebUSBInfo                 (const USB_WEBUSB_INFO * pWebUSBInfo);

#define USBD_SetISRMgmFuncs(pf,a,b)     USBD_SetISREnableFunc(pf)

/*********************************************************************
*
*       Functions that have to be supplied by the customer
*/
void USBD_X_Config                      (void);
void USBD_X_EnableInterrupt             (void);   // optional function, activate with USBD_OS_USE_USBD_X_INTERRUPT
void USBD_X_DisableInterrupt            (void);   // optional function, activate with USBD_OS_USE_USBD_X_INTERRUPT

/*********************************************************************
*
*       Template Functions that can be used for outputting the warn
*       and log messages.
*       They are used in all samples provided with emUSB-Device.
*       These functions are used with the sample log and warning
*       implementation in USB_ConfigIO.c
*       Warn and log output can be individually set to other function
*       by using the functions:
*         USBD_SetWarnFunc              ()
*         USBD_SetLogFunc               ()
*/
void USB_X_Warn                        (const char * s);
void USB_X_Log                         (const char * s);

/*********************************************************************
*
*       Profiling instrumentation functions
*/
void USBD_SYSVIEW_Init(void);

/*********************************************************************
*
*       Utility functions
*/
U16      USBD_GetU16BE                  (const U8 * p);
U16      USBD_GetU16LE                  (const U8 * p);
U32      USBD_GetU24BE                  (const U8 * p);
U32      USBD_GetU24LE                  (const U8 * p);
U32      USBD_GetU32BE                  (const U8 * p);
U32      USBD_GetU32LE                  (const U8 * p);
void     USBD_StoreU16BE                (U8 * p, unsigned v);
void     USBD_StoreU16LE                (U8 * p, unsigned v);
void     USBD_StoreU24BE                (U8 * p, U32 v);
void     USBD_StoreU24LE                (U8 * p, U32 v);
void     USBD_StoreU32LE                (U8 * p, U32 v);
void     USBD_StoreU32BE                (U8 * p, U32 v);
U32      USBD_SwapU32                   (U32 v);
unsigned USBD_CalcBitsSet               (unsigned int x);

/*********************************************************************
*
*       Memory check functions for USB drivers
*/
/*********************************************************************
*
*       USB_CHECK_ADDRESS_FUNC
*
*  Description
*    Checks if an address can be used for DMA transfers.
*    The function must return 0, if DMA access is allowed for the given address,
*    1 otherwise.
*
*  Parameters
*    pMem : Pointer to the memory.
*
*  Return value
*    == 0: Memory can be used for DMA access.
*    != 0: DMA access not allowed for the given address.
*/
typedef int  USB_CHECK_ADDRESS_FUNC    (const void * pMem);
void USBD_SetCheckAddress(USB_CHECK_ADDRESS_FUNC * pfCheckValidDMAAddress);

/*********************************************************************
*
*       USBD_V2P_FUNC
*
*  Description
*    Converts a virtual address to a physical address to be used for DMA.
*
*  Parameters
*    pVirtAddr : Pointer to the virtual memory location.
*
*  Return value
*    Physical address.
*/
typedef PTR_ADDR (USBD_V2P_FUNC)(const void * pVirtAddr);

/*********************************************************************
*
*       Functions necessary for easy migration from emUSB V2 to V3
*
*/
#if USB_V2_V3_MIGRATION_DEVINFO > 0
const char * USB_GetVendorName         (void);
const char * USB_GetProductName        (void);
const char * USB_GetSerialNumber       (void);
U16          USB_GetVendorId           (void);
U16          USB_GetProductId          (void);
#endif
#if USB_V2_V3_MIGRATION_CONFIG > 0
void         USB_X_AddDriver           (void);
void         USB_X_HWAttach            (void);
void         USB_X_EnableISR           (USB_ISR_HANDLER * pfISRHandler);
#endif

/*********************************************************************
*
*       Individual driver configuration functions
*
*/
void USB_DRIVER_LPC17xx_ConfigAddr    (U32 BaseAddr);
void USB_DRIVER_LPC18xx_ConfigAddr    (U32 BaseAddr);
void USB_DRIVER_LPC43xx_ConfigAddr    (U32 BaseAddr);
void USB_DRIVER_P1020_ConfigAddr      (U32 BaseAddr);
void USB_DRIVER_RX_ConfigAddr         (U32 BaseAddr);
void USB_DRIVER_RZ_ConfigAddr         (U32 BaseAddr);
void USB_DRIVER_RZA2_ConfigAddr       (U32 BaseAddr);
void USB_DRIVER_R8A66597_ConfigAddr   (U32 BaseAddr);
void USB_DRIVER_SH726A_ConfigAddr     (U32 BaseAddr);
void USB_DRIVER_KinetisEHCI_ConfigAddr(U32 BaseAddr);
void USB_DRIVER_iMXRT10xx_ConfigAddr  (U32 BaseAddr);
void USB_DRIVER_Zynq7010_ConfigAddr   (U32 BaseAddr);

void USB_DRIVER_STM32F7xxHS_ConfigPHY(U8 UsePHY);
void USB_DRIVER_STM32F4xxHS_ConfigPHY(U8 UsePHY);
void USB_DRIVER_STM32U5xx_ConfigAddr(U32 RegBaseAddr, U32 RamBaseAddr);
void USB_DRIVER_STM32H5xx_ConfigAddr  (U32 RegBaseAddr, U32 RamBaseAddr);

void USB_DRIVER_LPC546xx_Workaround(void);
void USB_DRIVER_SYNERGYHS_ConfigPara(U16 PhySetVal, U16 BusWaitVal);
void USB_DRIVER_SYNERGYHS_ConfigAddr(U32 BaseAddr);
void USB_DRIVER_SYNERGYFS_ConfigAddr(U32 BaseAddr);

void USBD_DRIVER_ALIFE1_SetV2PHandler(USBD_V2P_FUNC * pfV2PHandler);

/*********************************************************************
*
*       Compatibility macros for configuring the base address
*
*/
#define USB_DRIVER_RX62N_ConfigAddr(x)               USB_DRIVER_RX_ConfigAddr(x)
#define USB_DRIVER_RX63N_ConfigAddr(x)               USB_DRIVER_RX_ConfigAddr(x)
#define USB_DRIVER_RX64M_ConfigAddr(x)               USB_DRIVER_RX_ConfigAddr(x)
#define USB_DRIVER_RX65N_ConfigAddr(x)               USB_DRIVER_RX_ConfigAddr(x)
#define USB_DRIVER_RX71M_ConfigAddr(x)               USB_DRIVER_RX_ConfigAddr(x)
#define USB_DRIVER_RA_HS_ConfigPara(x, y)            USB_DRIVER_SYNERGYHS_ConfigPara(x, y)
#define USB_DRIVER_RX71M_HS_ConfigPara(x, y)         USB_DRIVER_SYNERGYHS_ConfigPara(x, y)
#define USB_DRIVER_RA_HS_ConfigAddr(x)               USB_DRIVER_SYNERGYHS_ConfigAddr(x)
#define USB_DRIVER_RX71M_HS_ConfigAddr(x)            USB_DRIVER_SYNERGYHS_ConfigAddr(x)
#define USB_DRIVER_RA_FS_ConfigAddr(x)               USB_DRIVER_SYNERGYFS_ConfigAddr(x)

/*********************************************************************
*
*       Available target USB drivers
*
*/
#define USB_Driver_AtmelSAM3U              USB_Driver_Atmel_SAM3U
#define USB_Driver_AtmelRM9200             USB_Driver_Atmel_RM9200
#define USB_Driver_AtmelSAM7A3             USB_Driver_Atmel_SAM7A3
#define USB_Driver_AtmelSAM7S              USB_Driver_Atmel_SAM7S
#define USB_Driver_AtmelSAM7SE             USB_Driver_Atmel_SAM7SE
#define USB_Driver_AtmelSAM7X              USB_Driver_Atmel_SAM7X
#define USB_Driver_AtmelSAM9260            USB_Driver_Atmel_SAM9260
#define USB_Driver_AtmelSAM9261            USB_Driver_Atmel_SAM9261
#define USB_Driver_AtmelSAM9263            USB_Driver_Atmel_SAM9263
#define USB_Driver_AtmelSAM9G45            USB_Driver_Atmel_SAM9G45
#define USB_Driver_AtmelSAM9G20            USB_Driver_Atmel_SAM9G20
#define USB_Driver_AtmelSAM9Rx64           USB_Driver_Atmel_SAM9Rx64
#define USB_Driver_AtmelSAM9XE             USB_Driver_Atmel_SAM9XE
#define USB_Driver_NXPLPC17xx              USB_Driver_NXP_LPC17xx
#define USB_Driver_NXPLPC23xx              USB_Driver_NXP_LPC23xx
#define USB_Driver_NXPLPC24xx              USB_Driver_NXP_LPC24xx
#define USB_Driver_STSTM32                 USB_Driver_ST_STM32
#define USB_Driver_STSTM32F107             USB_Driver_ST_STM32F107
#define USB_Driver_STSTR91x                USB_Driver_ST_STR91x
#define USB_Driver_TMPA910                 USB_Driver_Toshiba_TMPA910
#define USB_Driver_TMPA900                 USB_Driver_Toshiba_TMPA900
#define USB_Driver_Renesas_RX62N           USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX63N           USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX64M           USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX65N           USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX71M           USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX71M_FS        USB_Driver_Renesas_RX
#define USB_Driver_Renesas_RX71M_HS        USB_Driver_Renesas_SynergyHS
#define USB_Driver_Renesas_RA_FS           USB_Driver_Renesas_SynergyFS
#define USB_Driver_Renesas_RA_HS           USB_Driver_Renesas_SynergyHS
#define USB_Driver_Atmel_SAM9X35           USB_Driver_Atmel_SAM9X25
#define USB_Driver_Atmel_SAMA5Dx           USB_Driver_Atmel_SAMA5D3x
#define USB_Driver_Freescale_K40           USB_Driver_Freescale_KHCI
#define USB_Driver_Freescale_K60           USB_Driver_Freescale_KHCI
#define USB_Driver_Freescale_K70           USB_Driver_Freescale_KHCI
#define USB_Driver_Renesas_SynergyS3_FS    USB_Driver_Renesas_SynergyFS
#define USB_Driver_Renesas_SynergyS5_FS    USB_Driver_Renesas_SynergyFS
#define USB_Driver_Renesas_SynergyS7_FS    USB_Driver_Renesas_SynergyFS
#define USB_Driver_Renesas_RX200           USB_Driver_Renesas_RX100
#define USB_Driver_SiLabs_EFM32GG11        USB_Driver_EM_EFM32GG990
#define USB_Driver_Infineon_XMC42xx        USB_Driver_Infineon_XMC45xx
#define USB_Driver_ST_STM32U5xx_FS_DynMem  USB_Driver_ST_STM32U5xx_FS
#define USB_Driver_ST_STM32WB55            USB_Driver_ST_STM32L4x2
#define USB_Driver_Renesas_RA4M2           USB_Driver_Renesas_SynergyFS


extern const USB_HW_DRIVER USB_Driver_AlifSemi_E1;
extern const USB_HW_DRIVER USB_Driver_Ambiq_Apollo4;
extern const USB_HW_DRIVER USB_Driver_Atmel_AT32UC3x;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM3U;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM3X;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM3S;
extern const USB_HW_DRIVER USB_Driver_Atmel_RM9200;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM7A3;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM7S;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM7SE;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM7X;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9260;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9261;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9263;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9G45;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9G20;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9Rx64;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9XE;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAM9X25;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMA5D2x;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMA5D2x_DMA;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMA5D3x;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMA5D3x_DMA;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMA5D4x;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMV7;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMD21;
extern const USB_HW_DRIVER USB_Driver_Atmel_SAMD51;
extern const USB_HW_DRIVER USB_Driver_Cypress_MB9BFxxx;
extern const USB_HW_DRIVER USB_Driver_EM_EFM32GG990;
extern const USB_HW_DRIVER USB_Driver_Freescale_KHCI;
extern const USB_HW_DRIVER USB_Driver_Freescale_KinetisEHCI;
extern const USB_HW_DRIVER USB_Driver_GD_GD32450xFS;
extern const USB_HW_DRIVER USB_Driver_GD_GD32450xHS;
extern const USB_HW_DRIVER USB_Driver_Infineon_XMC45xx;
extern const USB_HW_DRIVER USB_Driver_Infineon_XMC45xx_DynMem;
extern const USB_HW_DRIVER USB_Driver_Infineon_XMC45xx_DMA;
extern const USB_HW_DRIVER USB_Driver_MAX32570;
extern const USB_HW_DRIVER USB_Driver_Microsemi_SmartFusion2;
extern const USB_HW_DRIVER USB_Driver_Nordic_nRF52xxx;
extern const USB_HW_DRIVER USB_Driver_Nordic_nRF53xx;
extern const USB_HW_DRIVER USB_Driver_Nordic_nRF53xx_NS;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC17xx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC18xx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC23xx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC24xx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC43xx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC43xx_DynMem;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC51xxx;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC54xxx_HS;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC540xx_HS;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC54xxx_FS;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC55xxx_HS;
extern const USB_HW_DRIVER USB_Driver_NXP_LPC55xxx_FS;
extern const USB_HW_DRIVER USB_Driver_NXP_iMXRT10xx;
extern const USB_HW_DRIVER USB_Driver_NXP_iMXRT10xx_DynMem;
extern const USB_HW_DRIVER USB_Driver_NXP_iMXRT5xx;
extern const USB_HW_DRIVER USB_Driver_NXP_iMXRT6xx;
extern const USB_HW_DRIVER USB_Driver_RP_2040;
extern const USB_HW_DRIVER USB_Driver_Renesas_RZ;
extern const USB_HW_DRIVER USB_Driver_Renesas_RZA2;
extern const USB_HW_DRIVER USB_Driver_Renesas_RZG1;
extern const USB_HW_DRIVER USB_Driver_Renesas_RX;
extern const USB_HW_DRIVER USB_Driver_Renesas_RX64M_USBA;
extern const USB_HW_DRIVER USB_Driver_Renesas_RX100;
extern const USB_HW_DRIVER USB_Driver_Renesas_SH7268;
extern const USB_HW_DRIVER USB_Driver_Renesas_SH726A;
extern const USB_HW_DRIVER USB_Driver_Renesas_SynergyS1;
extern const USB_HW_DRIVER USB_Driver_Renesas_SynergyFS;
extern const USB_HW_DRIVER USB_Driver_Renesas_SynergyHS;
extern const USB_HW_DRIVER USB_Driver_Renesas_R8A66597;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F4xxFS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F4xxHS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F4xxHS_DMA;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F4xxHS_inFS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F7xxFS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F7xxFS_DynMem;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F7xxHS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F7xxHS_DynMem;
extern const USB_HW_DRIVER USB_Driver_ST_STM32F7xxHS_DMA;
extern const USB_HW_DRIVER USB_Driver_ST_STM32H7xxFS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32H7xxFS_DynMem;
extern const USB_HW_DRIVER USB_Driver_ST_STM32H7xxHS_inFS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32H7xxHS_inFS_DynMem;
extern const USB_HW_DRIVER USB_Driver_ST_STM32L4xx;
extern const USB_HW_DRIVER USB_Driver_ST_STM32L4x2;
extern const USB_HW_DRIVER USB_Driver_ST_STM32L5x2;
extern const USB_HW_DRIVER USB_Driver_ST_STM32H5xx;
extern const USB_HW_DRIVER USB_Driver_ST_STM32U5xx_FS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32U5xx_HS;
extern const USB_HW_DRIVER USB_Driver_ST_STM32U5xx_NG;
extern const USB_HW_DRIVER USB_Driver_ST_STR91x;
extern const USB_HW_DRIVER USB_Driver_TI_AM335x;
extern const USB_HW_DRIVER USB_Driver_TI_AM335xDMA;
extern const USB_HW_DRIVER USB_Driver_TI_LM3S9B9x;
extern const USB_HW_DRIVER USB_Driver_TI_OMAP_L138;
extern const USB_HW_DRIVER USB_Driver_TI_TM4Cxx;
extern const USB_HW_DRIVER USB_Driver_Toshiba_TMPA900;
extern const USB_HW_DRIVER USB_Driver_Toshiba_TZ1200;
extern const USB_HW_DRIVER USB_Driver_DialogSemi_DA1468x;
extern const USB_HW_DRIVER USB_Driver_DialogSemi_DA148xx;
extern const USB_HW_DRIVER USB_Driver_Xilinx_Ultrascale0;
extern const USB_HW_DRIVER USB_Driver_Xilinx_Ultrascale1;
extern const USB_HW_DRIVER USB_Driver_Xilinx_Ultrascale0_R5;
extern const USB_HW_DRIVER USB_Driver_Xilinx_Ultrascale1_R5;

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif
