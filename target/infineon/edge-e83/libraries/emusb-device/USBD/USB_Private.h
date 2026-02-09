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
Purpose : Private USB include file.
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USB_PRIVATE_H
#define USB_PRIVATE_H

#include "USB.h"

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/

#define USB_MAX_ALLOWED_EPADDR      0x20u

#ifndef USB_NUM_TX_DATA_PARTS
  #define USB_NUM_TX_DATA_PARTS       3u
#endif

// Parameters of functions can't be made 'const', if pointer to function is used as callback or in API structure.
#define USBD_API_USE        /*lint -e{818}  N:100 */

/*********************************************************************
*
*       Driver commands
*/
#define USB_DRIVER_CMD_SET_CONFIGURATION        0
#define USB_DRIVER_CMD_SET_SOF_CALLBACK         1
#define USB_DRIVER_CMD_GET_FLAGS                2
#define USB_DRIVER_CMD_REMOTE_WAKEUP            3
#define USB_DRIVER_CMD_TESTMODE                 4
#define USB_DRIVER_CMD_GET_LPM_CONFIG           5
#define USB_DRIVER_CMD_ASSIGN_MEMORY            7
#define USB_DRIVER_CMD_GET_MEM_ALIGNMENT        8
#define USB_DRIVER_CMD_ENABLE_SUPER_SPEED       9
#define USB_DRIVER_CMD_U1_CONTROL              10
#define USB_DRIVER_CMD_U2_CONTROL              11
#define USB_DRIVER_CMD_GET_EXIT_LATENCY        12
#define USB_DRIVER_CMD_CHECK_MAX_PACKET_SIZE   13
#define USB_DRIVER_CMD_SET_ALT_PACKET_SIZE     14
#define USB_DRIVER_CMD_SET_LPM_RESPONSE        15
#define USB_DRIVER_CMD_LOW_POWER_RESUME        16

//
// Test Mode Selectors (USB 2.0 spec Table 9-7)
//
#define USB_CMD_TESTMODE_TEST_J                 1u
#define USB_CMD_TESTMODE_TEST_K                 2u
#define USB_CMD_TESTMODE_TEST_SE0_NAK           3u
#define USB_CMD_TESTMODE_TEST_PACKET            4u
#define USB_CMD_TESTMODE_TEST_FORCE_ENABLE      5u

//
// Defines and masks used with the EP_STAT Flags variable.
//
#define USB_EP_STAT_ASYNC_CALLBACK_USED         (1u    << 0)
#define USB_EP_STAT_ISO_TYPES_MASK              (0x0Fu << 2)

//
// Read mode for USB__Read()
//
#define USB_RD_MODE_BLOCK            (1uL << 0)                    // block until all bytes are read
#define USB_RD_MODE_BLOCK_SHORT      (1uL << 1)                    // block until at least 1 byte was read
#define USB_RD_MODE_NO_BLOCK         (1uL << 2)                    // never block, get only bytes from buffer
#define USB_RD_MODE_NO_WAIT          (1uL << 4)                    // don't wait for event
#define USB_RD_MODE_NO_ABORT         (1uL << 5)                    // don't abort transfer after timeout

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

//
// Driver capabilities
//
typedef struct {
  U8       SetAddressBehavior;      // 0: Set USB address via pfSetAddress() after the "SetAddress" setup request was completed.
                                    // 1: Set USB address immediately when the "SetAddress" setup packet was received.
                                    // 2: Same as 1, but don't send an acknowledge (is done by the driver/controller automatically).
  I8       MultiPacketRxBehavior;   // True if driver can receive multiple packets via DMA but does not report each packet
                                    // received to the stack. Used for correct timeout behavior.
  I8       AlwaysDisableRX;         // True if pfDisableRxInterruptEP() should be called even if no pfEnableRxInterruptEP() was executed before.
} USB_DRIVER_FLAGS;

//
// Driver ioctl parameter
//
union USB_IOCTL_PARA_t {
  USB_DRIVER_FLAGS Flags;
  U8               Configuration;
  U8               TestMode;
  U32              MemAlignment;
  I8               LPM_Enable;
  U32              LPM_Config;
  U8               LPM_Response;
  struct {
    void         * pMem;
    U32            MemSize;
  } MemAssign;
  struct {
    U8             U1;
    U16            U2;
  } ExitLatency;
  void          (* pfSOFCallback)(void);
  struct {
    U8             EPIndex;
    U16            MaxPacketSize;
  } PacketSize;
};


typedef struct {
  unsigned Cnt;
  unsigned Sizeof;
  U8 * pBuffer;
} USB_INFO_BUFFER;

typedef struct {
  U8       * pData;
  unsigned   Size;
  unsigned   NumBytesIn;
  unsigned   RdPos;
} USB_BUFFER;

struct _EP_STAT {
  U16                       MaxPacketSize;
  U16                       MaxPacketSizeUser;
  U16                       Interval;                   // In frames. Valid only for ISO and interrupt endpoints. Not used by stack except for creating descriptors.
  U8                        EPType;                     // 0: Control, 1: Isochronous, 2: Bulk, 3: Interrupt See [1], chapter "9.6.6  Endpoint", table 9-13.
  U8                        EPAddr;                     // b[4:0]: EPAddr => This is the physical endpoint number.
                                                        // b[6:5]: Unused, SBZ.
                                                        // b[7]:   Direction, 1: Device to Host (IN), 0: Host to device (OUT).
  volatile I8               IsHalted;                   // 1: Endpoint is stalled. Typically set by application via call to USBD_StallEP() in case of fatal error.
  U8                        Flags;                      // b[0]   AsyncCallbackUsed
                                                        // b[5:2] ISO Endpoint Sync
  U16                       TransactionCnt;             // Counter to synchronize OS_Wait() + OS_Signal functions.
  union {
    struct {
      int                   TxNumBytesPending;          // It indicates whether a IN transfer is already queued for the endpoint.
                                                        // 0: No TX transfer is in progress.
                                                        // 1: Transfer of a NULL packet is in progress.
                                                        // >0: Transfer of (TxNumBytesPending - 1) bytes of data is in progress.
                                                        // -1: Intermediate state: TX transfer is just finished, but a new transfer cannot be started yet.
      unsigned              NumBytesWithout0Packet;     // No 0-packet is sent after a transfer of a multiple of this number of bytes.
                                                        // Must be a multiple of MaxPacketSize and a power of 2.
      U16                   NumFullPacketsSend;         // Number of full packets (MaxPacketSize) send within a transfer.
      U8                    Send0PacketIfRequired;      // This flag is used with IN endpoints. When set the stack will check at the end of a transaction whether
                                                        // the last transfer was a multiple of MaxPacketSize, if yes it will send a zero packet to complete the transaction.
                                                        // This flag is normally depending on which API function is used. Some API functions even allow the user to set it.
      U8                    SendEventOccurred;          // Set if the driver has triggered USB_EVENT_DATA_SEND.
                                                        // If not, the event is later triggered together with USB_EVENT_DATA_ACKED.
      U8                    SignalOnTXReady;            // Send event if TX queue gets a free entry
      U8                    WriteMode;                  // See USB_READ_WRITE... defines.
      U8                    NumDataParts;
      USB_DATA_PART         DataParts[USB_NUM_TX_DATA_PARTS];
    } TxInfo;
    struct {
      USB_ON_RX_FUNC *      pfOnRx;                     // Pointer to a callback function set either by USBD_SetOnRxEP0() or by USBD_SetOnRXHookEP() functions.
      U8             *      pData;
      volatile unsigned     NumBytesRem;                // Volatile since modified by ISR and checked by task/application.
      I8                    RxInterruptEnabled;         // Keep track of driver RX interrupt enable / disable
      U8                    ReadMode;                   // See USB_READ_MODE... defines.
      U8                    AllowShortPacket;           // Controls the behavior of the internal _OnRxCheckDone() function.
      U8                    RxPacketByPacket;           // Perform read operation packet by packet (only request a single packet from the driver)
      USB_BUFFER            Buffer;
    } RxInfo;
  } Dir;
  USB_EVENT_CALLBACK        *pEventCallbacks;           // List of callback functions for this endpoint.
};

typedef struct {
  void (*pfAdd)(U8 FirstInterFaceNo, U8 NumInterfaces, U8 ClassNo, U8 SubClassNo, U8 ProtocolNo);
  void (*pfAddIadDesc)(unsigned InterFaceNo, USB_INFO_BUFFER * pInfoBuffer);
} USB_IAD_API;

typedef struct {
  union {
    USB_ON_SET_IF_FUNC   * Set;
    USB_ON_GET_IF_FUNC   * Get;
  } cb;
  void                   * pContext;
} USB_SET_INTERFACE_HOOK;

typedef void         USB_ADD_FUNC_DESC        (int InterfaceNo, U8 IFAlternateSetting, USB_INFO_BUFFER * pInfoBuffer);
typedef void         USB_ADD_EP_FUNC_DESC     (int InterfaceNo, U8 IFAlternateSetting, U8 EPAddr, USB_INFO_BUFFER * pInfoBuffer);
typedef unsigned     USB_GET_EP_CUSTOM_SIZE   (int InterfaceNo, U8 IFAlternateSetting, U8 EPAddr, unsigned MaxPacketSize);
typedef void         USB_DEINIT_FUNC          (void);

typedef struct _USB_DEINIT_HOOK {
  struct _USB_DEINIT_HOOK * pNext;
  USB_DEINIT_FUNC         * pfCallback;
  U8                      * pFlag;
} USB_DEINIT_HOOK;

typedef struct _INTERFACE {
#if USB_NUM_EPS > 16u
  U32                       EPs;
#else
  U16                       EPs;
#endif
  U8                        IFAlternateSetting;  // Applicable for ALT_INTERFACE, value is used in descriptor creation.
  U8                        IFClass;             // Interface Class
  U8                        IFSubClass;          // Interface Subclass
  U8                        IFProtocol;          // Interface Protocol
  U8                        CurrentAltSetting;   // Applicable for INTERFACE, value is used for CmdSetInterface/CmdGetInterface
  U8                        iName;               // Index of String descriptor
  USB_ADD_FUNC_DESC       * pfAddFuncDesc;
  USB_ADD_EP_FUNC_DESC    * pfAddEndpointFuncDesc;
  USB_ON_CLASS_REQUEST    * pfOnClassRequest;
  USB_ON_CLASS_REQUEST    * pfOnVendorRequest;
  USB_SET_INTERFACE_HOOK    OnSetInterfaceHook;  // Contains a pointer to a callback which is called when a Set Interface command is received. Set from a class module or the application (USBD_SetOnSetInterfaceHook()).
#if USB_SUPPORT_GET_INTERFACE_CB
  USB_SET_INTERFACE_HOOK    OnGetInterfaceHook;  // Contains a pointer to a callback which is called when a Get Interface command is received. Set from a class module or the application (USBD_SetOnGetInterfaceHook()).
#endif
#if USB_SUPPORT_TRANSFER_ISO
  USB_GET_EP_CUSTOM_SIZE  * pfGetCustomMaxPacketSize;
#endif
} INTERFACE;

typedef struct _ALT_INTERFACE {
  U8        IFNo;      // Index of the real interface
  I8        MinSpeed;  // Minimum required enumerated USB speed for this alternate setting (0=full-speed, 1=high-speed, ...)
  INTERFACE AltIF;     // Interface structure
} ALT_INTERFACE;


/*********************************************************************
*
*       USBD_PROFILE_API
*/
typedef struct {
  void(*pfRecordEndCall)       (unsigned int EventId);
  void(*pfRecordEndCallU32)    (unsigned int EventId, U32 Para0);
  void(*pfRecordVoid)          (unsigned int EventId);
  void(*pfRecordU32)           (unsigned int EventId, U32 Para0);
  void(*pfRecordU32x2)         (unsigned int EventId, U32 Para0, U32 Para1);
  void(*pfRecordU32x3)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2);
  void(*pfRecordU32x4)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3);
  void(*pfRecordU32x5)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4);
  void(*pfRecordU32x6)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4, U32 Para5);
  void(*pfRecordU32x7)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4, U32 Para5, U32 Para6);
  void(*pfRecordU32x8)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4, U32 Para5, U32 Para6, U32 Para7);
  void(*pfRecordU32x9)         (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4, U32 Para5, U32 Para6, U32 Para7, U32 Para8);
  void(*pfRecordU32x10)        (unsigned int EventId, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4, U32 Para5, U32 Para6, U32 Para7, U32 Para8, U32 Para9);
  void(*pfRecordString)        (unsigned int EventId, const char* pPara0);
  U32(*pfPtr2Id)              (U32 Ptr);
} USBD_PROFILE_API;

typedef struct {
  U32                   IdOffset;
  const USBD_PROFILE_API* pAPI;
} USBD_PROFILE;

U32  USBD_PROFILE_GetAPIDesc(const char** psDesc);
void USBD_PROFILE_SetAPI(const USBD_PROFILE_API* pAPI, U32 IdOffset);

typedef struct {                                  // NOLINT(clang-analyzer-optin.performance.Padding)
  U8                        NumEPs;               // Count of currently used endpoints.
  U8                        NumIFs;               // Count of currently used interfaces.
  U8                        NumAltIFs;            // Count of currently used alternative interfaces.
  U8                        EventsIdx;            // Index for allocating events.
  U8                        Class;                // Device Class    (when IAD is not used the class is defined in the device descriptor)
  U8                        SubClass;             // Device Subclass (when IAD is not used the subclass is defined in the device descriptor)
  U8                        Protocol;             // Device Protocol (when IAD is not used the Protocol is defined in the device descriptor)
  U8                        IsInited;             // Flag indicating whether emUSB-Device was initialized.
  volatile U8               State;                // Global USB state, similar to [1]: chapter 9.1.1.
                                                  // Bitwise combination of USB_STAT_ATTACHED, USB_STAT_READY, USB_STAT_ADDRESSED, USB_STAT_CONFIGURED, USB_STAT_SUSPENDED
  U8                        Addr;                 // The USB device address, assigned by the host. Zero when the device is not enumerated.
  U8                        ConfigAttr;           // For use in configuration descriptor.
  U8                        DeviceState;          // Device state returned by 'Get Status' request from the host.
                                                  // See USB_DEVSTAT_... macros.
  U8                        NumStringDesc;        // Number of String descriptors
  U8                        NumOnRxEP0Callbacks;  // Count of receive callbacks for endpoint zero.
  U16                       RecommendedBESLValue;
  USB_DRIVER_FLAGS          Flags;                // Driver dependent flags
  const char *              aStringDesc[USB_MAX_STRING_DESC];
  INTERFACE                 aIF[USB_MAX_NUM_IF];  // Array of available interfaces.
#if USB_MAX_NUM_ALT_IF > 0u
  ALT_INTERFACE             aAltIF[USB_MAX_NUM_ALT_IF];  // Array of available alternative interfaces.
#endif
  USB_SETUP_HOOK          * pFirstSetupHook;      // List of callback functions to handle setup requests.
  U16                       TransactionCnt;       // Counter to synchronize OS_Wait() + OS_Signal functions.
  U8                        MaxPower;             // Used in configuration descriptor.
  U8                        MaxPowerSS;           // For SuperSpeed enumeration.
  USB_ON_RX_FUNC          * apfOnRxEP0[USB_MAX_NUM_COMPONENTS]; // Array of function pointers to receive callbacks for endpoint zero.
  const USB_HW_DRIVER     * pDriver;              // Pointer to the hardware driver structure.
  USB_ENABLE_ISR_FUNC     * pfEnableISR;          // Pointer to function to enable the USB interrupt and set the interrupt handler.
  const USB_IAD_API       * pIadAPI;              // Pointer to the USB Interface Association Descriptor API.
  USB_DEINIT_HOOK         * pDeInitHandler;       // Pointer to a linked list of functions which should be called when USBD_DeInit() is called. These callbacks are normally set by class modules.
  USB_DETACH_FUNC         * pfDetach;             // Pointer to a callback which is called on a detach event. Set from the application (USBD_SetDetachFunc()).
  USB_GET_STRING_DESC_HOOK* pfGetString;          // Pointer to a callback which is called when the host requests a string descriptor from the device. Set from the application (USBD_SetGetStringFunc()).
  USB_ON_BCD_VERSION_FUNC * pfOnBCDVersion;       // Pointer to a callback which is called when the host requests a device descriptor from the device. Set from the application (USBD_SetOnBCDVersionFunc()).
  USB_ATTACH_FUNC         * pfAttach;             // Pointer to the attach function (optional).
  const USB_DEVICE_INFO   * pDeviceInfo;          // Pointer to device information used during enumeration.
  U8                        aPhyAddr2EPIndex[USB_MAX_ALLOWED_EPADDR];  // Mapping table, physical to logical endpoint address.
  USB_HOOK                * pFirstSCHook;         // List of hook function called on status change.
  USB_ON_LPM_CHANGE       * pfOnLPMChange;        // LPM callback
  SEGGER_CACHE_CONFIG       CacheConfig;
  const U8 *             (* pfBuildBOSDesc)(void);
  void                   (* pfAddSSEndpointCompanion)(const EP_STAT *pEPStat, USB_INFO_BUFFER *pInfoBuffer);
  unsigned               (* pfAddSSDeviceCap)(USB_INFO_BUFFER *pInfoBuffer);
  int                    (* pfSetClrFeature)(U8 Recipient, U16 wValue, int SetClr);
  unsigned               (* pfAddWebUSBDesc)(USB_INFO_BUFFER *pInfoBuffer);
  USB_SOF_CALLBACK_HOOK   * pSOFCbHook;           // Linked list of USB_SOF_CALLBACK_HOOK structures.
  U16                       USBSpecRev;           // USB specification release number (bcdUSB)
  U8                        MinimumSpeed;         // Minimum speed the device can operate at. 1=full, 2=high, 3=SuperSpeed
#if USB_SUPPORT_TEST_MODE
  U8                        TestMode;
#endif
#if USBD_SUPPORT_PROFILE
  USBD_PROFILE              Profile;
#endif
  const char              * sCopyright;
} USBD_GLOBAL;

enum _STRING_INDEX {
  STRING_INDEX_LANGUAGE = 0,  // Language index. MUST BE 0 acc. to spec.
  STRING_INDEX_MANUFACTURER,  // iManufacturer:      Index of String Desc (Manuf)    (variable, but needs to be unique)
  STRING_INDEX_PRODUCT,       // iProduct:           Index of String Desc (Product)  (variable, but needs to be unique)
  STRING_INDEX_SN,            // iSerialNumber:      Index of String Desc (Serial #) (variable, but needs to be unique)
  STRING_INDEX_CONFIG,        // iConfiguration:     Index of String Desc (Configuration name) (variable, but needs to be unique)
  STRING_INDEX_MAX
};

#define STRING_INDEX_MS_OS  0xEEu   // Special String index that is used by Microsoft to detect "special" interfaces/devices
#define STRING_INDEX_OTHER  ((unsigned)STRING_INDEX_MAX)   // Start index of other string descriptors store in aStringDesc[]

/*********************************************************************
*
*       Global data
*
**********************************************************************
*/
extern EP_STAT USB_aEPStat[USB_NUM_EPS];
extern USBD_GLOBAL  USB_Global;
extern USB_CHECK_ADDRESS_FUNC * USBD__pfCheckValidDMAAddress;

/*********************************************************************
*
*       emUSB-Device profiling instrumentation
*
**********************************************************************
*/

/*********************************************************************
*
*       Profile event identifiers
*/
enum {
  //
  // Events for IP API functions (IDs 0-249).
  //
  USBD_EVTID_INIT = 0,
  USBD_EVTID_DEINIT,
  USBD_EVTID_START,
  USBD_EVTID_STOP,
  //
  // Events for Read/Write (IDs 250-299).
  //
  USBD_EVTID_READ = 250,
  USBD_EVTID_RECEIVE,
  USBD_EVTID_READOVERLAPPED,
  USBD_EVTID_WRITE,
  USBD_EVTID_WRITEOVERLAPPED,
  USBD_EVTID_CANCELIO,
  //
  // Events for other internal events (IDs 560-...).
  //
  USBD_EVTID_INTERNAL1 = 560,  // Placeholder.
  //
  // Make sure this is the last entry.
  //
  USBD_EVTID_LAST
};

#define USBD_PROFILE_API_DESC  "M=emUSBD,V=30214"

#define USBD_PROFILE_GET_EVENT_ID(EvtId)  ((EvtId) + USB_Global.Profile.IdOffset)

/*********************************************************************
*
*       USBD_PROFILE_CALL_VOID()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_VOID(EventId)                                        \
    if (USB_Global.Profile.pAPI) {                                              \
      USB_Global.Profile.pAPI->pfRecordVoid(USBD_PROFILE_GET_EVENT_ID(EventId));  \
    }
#else
#define USBD_PROFILE_CALL_VOID(EventId)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32(EventId, Para0)                                               \
    if (USB_Global.Profile.pAPI) {                                                           \
      USB_Global.Profile.pAPI->pfRecordU32(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0));  \
    }
#else
#define USBD_PROFILE_CALL_U32(EventId, Para0)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32x2()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32x2(EventId, Para0, Para1)                                                      \
    if (USB_Global.Profile.pAPI) {                                                                           \
      USB_Global.Profile.pAPI->pfRecordU32x2(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0), (U32)(Para1));  \
    }
#else
#define USBD_PROFILE_CALL_U32x2(Id, Para0, Para1)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32x3()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32x3(EventId, Para0, Para1, Para2)                                                             \
    if (USB_Global.Profile.pAPI) {                                                                                         \
      USB_Global.Profile.pAPI->pfRecordU32x3(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0), (U32)(Para1), (U32)(Para2));  \
    }
#else
#define USBD_PROFILE_CALL_U32x3(Id, Para0, Para1, Para2)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32x4()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32x4(EventId, Para0, Para1, Para2, Para3)                                                                    \
    if (USB_Global.Profile.pAPI) {                                                                                                       \
      USB_Global.Profile.pAPI->pfRecordU32x4(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0), (U32)(Para1), (U32)(Para2), (U32)(Para3));  \
    }
#else
#define USBD_PROFILE_CALL_U32x4(Id, Para0, Para1, Para2, Para3)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32x5()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32x5(EventId, Para0, Para1, Para2, Para3, Para4)                                                                           \
    if (USB_Global.Profile.pAPI) {                                                                                                                     \
      USB_Global.Profile.pAPI->pfRecordU32x5(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0), (U32)(Para1), (U32)(Para2), (U32)(Para3), (U32)(Para4));  \
    }
#else
#define USBD_PROFILE_CALL_U32x5(Id, Para0, Para1, Para2, Para3, Para4)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_U32x6()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_U32x6(EventId, Para0, Para1, Para2, Para3, Para4, Para5)                                                                                  \
    if (USB_Global.Profile.pAPI) {                                                                                                                                   \
      USB_Global.Profile.pAPI->pfRecordU32x6(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(Para0), (U32)(Para1), (U32)(Para2), (U32)(Para3), (U32)(Para4), (U32)(Para5));  \
    }
#else
#define USBD_PROFILE_CALL_U32x6(Id, Para0, Para1, Para2, Para3, Para4, Para5)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_STRING()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_STRING(EventId, pPara0)                                                       \
    if (USB_Global.Profile.pAPI) {                                                                       \
      USB_Global.Profile.pAPI->pfRecordString(USBD_PROFILE_GET_EVENT_ID(EventId), (const char*)(pPara0));  \
    }
#else
#define USBD_PROFILE_CALL_STRING(EventId, pPara0)
#endif

/*********************************************************************
*
*       USBD_PROFILE_CALL_STRING_U32()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_CALL_STRING_U32(EventId, pPara0, Para1)                                                             \
    if (USB_Global.Profile.pAPI) {                                                                                        \
      USB_Global.Profile.pAPI->pfRecordStringU32(USBD_PROFILE_GET_EVENT_ID(EventId), (const char*)(pPara0), (U32)(Para1));  \
    }
#else
#define USBD_PROFILE_CALL_STRING_U32(EventId, pPara0, Para1)
#endif

/*********************************************************************
*
*       USBD_PROFILE_END_CALL()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_END_CALL(EventId)                                            \
    if (USB_Global.Profile.pAPI) {                                                 \
      USB_Global.Profile.pAPI->pfRecordEndCall(USBD_PROFILE_GET_EVENT_ID(EventId));  \
    }
#else
#define USBD_PROFILE_END_CALL(EventId)
#endif

/*********************************************************************
*
*       USBD_PROFILE_END_CALL_U32()
*/
#if USBD_SUPPORT_PROFILE
#define USBD_PROFILE_END_CALL_U32(EventId, ReturnValue)                                                \
    if (USB_Global.Profile.pAPI) {                                                                      \
      USB_Global.Profile.pAPI->pfRecordEndCallU32(USBD_PROFILE_GET_EVENT_ID(EventId), (U32)(ReturnValue));  \
    }
#else
#define USBD_PROFILE_END_CALL_U32(EventId, ReturnValue)
#endif


/*********************************************************************
*
*       USB descriptor defines.
*       Refer to [1]: chapter 9.6 "Standard USB Descriptor Definitions" for details.
*
*/
#define USB_DESC_TYPE_DEVICE           0x01u
#define USB_DESC_TYPE_CONFIG           0x02u
#define USB_DESC_TYPE_STRING           0x03u
#define USB_DESC_TYPE_INTERFACE        0x04u
#define USB_DESC_TYPE_ENDPOINT         0x05u
#define USB_DESC_TYPE_QUALIFIER        0x06u
#define USB_DESC_TYPE_SPEED_CONFIG     0x07u
#define USB_DESC_TYPE_INTERFACE_POWER  0x08u
#define USB_DESC_TYPE_IAD              0x0Bu
#define USB_DESC_TYPE_BOS              0x0Fu
#define USB_DESC_TYPE_CAPABILITY       0x10u
#define USB_DESC_TYPE_SS_EP_COMPN      0x30u

#define USB_BOS_CAP_TYPE_WIRELESS_USB           0x01
#define USB_BOS_CAP_TYPE_USB20_EXTENSION        0x02
#define USB_BOS_CAP_TYPE_SUPER_SPEED            0x03
#define USB_BOS_CAP_TYPE_CONTAINER_ID           0x04
#define USB_BOS_CAP_TYPE_PLATFORM               0x05

#define USB_STORE_U16(u16) ((u16) & 255), ((u16) / 256)

/*********************************************************************
*
*       OS layer auxiliary functions
*/
#if USBD_OS_USE_ISR_FLAG
  #define USBD_ENTER_ISR()       {USBD_IsInInterrupt = 1;}
  #define USBD_LEAVE_ISR()       {USBD_IsInInterrupt = 0;}
#else
  #define USBD_ENTER_ISR()
  #define USBD_LEAVE_ISR()
#endif

/*********************************************************************
*
*       Internal functions.
*
**********************************************************************
*/
unsigned USB__CalcMaxPacketSize     (unsigned MaxPacketSize, U8 TransferType, int SpeedMode);
int      USB__Read                  (unsigned EPIndex, void* pData, unsigned NumBytesReq, unsigned ms, unsigned Mode);
U8       USB__EPAddr2Index          (unsigned EPAddr);
U8       USB__EPIndex2Addr          (unsigned EPIndex);
void*    USB__GetpDest              (unsigned EPIndex,    unsigned NumBytes);
U32      USB__GetNextRX             (unsigned EPIndex, U8 **p);
void     USB__HandleSetup           (const USB_SETUP_PACKET * pSetupPacket);
void     USB__OnBusReset            (void);
void     USB__OnResume              (void);
void     USB__OnRx                  (unsigned EPIndex, const U8 * pData, unsigned NumBytes);
void     USB__OnRxZeroCopy          (unsigned EPIndex, unsigned NumBytes);
void     USB__OnRxZeroCopyEx        (unsigned EPIndex, unsigned NumBytes, int Done);
void     USB__OnStatusChange        (U8 NewState);
void     USB__OnSuspend             (void);
void     USB__OnTx                  (unsigned EPIndex);
void     USB__OnTx0Done             (void);
void     USB__Send                  (unsigned EPIndex);
void     USB__UpdateEPHW            (void);
int      USB__GetSpeedCapability    (void);
int      USB__GetSpeedMode          (void);
U8       USB__AllocIF               (void);
U8       USB__AllocAltIF            (U8 InterFaceNo);
U8       USB__AllocEvent            (void);
void     USB__StallEP0              (void);
void     USB__ResetDataToggleEP     (unsigned EPIndex);
void     USB__RemovePendingOperation(unsigned EPIndex, int Flag);
void     USB__EventDataSend         (unsigned EPIndex);
U8       USB__AllocStringDesc       (const char *sString);
void     USB__EmptyBuffer           (unsigned EPIndex);
U8   *   USB__GetDescBuffer         (unsigned * pDescBufferSize);
unsigned USB__AddPlatformDesc       (USB_INFO_BUFFER *pInfoBuffer);
void     USB__RegisterDeInitHandler (USB_DEINIT_HOOK *pHook, USB_DEINIT_FUNC * pfHandler);
void     USB__RegisterDeInitFlag    (USB_DEINIT_HOOK *pHook, U8 *pFlag);
void     USB__OnLPMChange           (int State, unsigned BESL);

//lint -sem(USB__EPIndex2Addr, pure)          N:100
//lint -sem(USB__GetSpeedCapability, pure)    N:100
//lint -sem(USB__GetSpeedMode, pure)          N:100

void     USB_XXLog(unsigned Tag, unsigned Data);

/*********************************************************************
*
*       InfoBuffer routines
*
**********************************************************************
*/
void USB_IB_Init                (USB_INFO_BUFFER * pInfoBuffer, U8 * pBuffer, unsigned SizeofBuffer);
void USB_IB_AddU8               (USB_INFO_BUFFER * pInfoBuffer, U8  Data);
void USB_IB_AddU16              (USB_INFO_BUFFER * pInfoBuffer, U16 Data);
void USB_IB_AddU32              (USB_INFO_BUFFER * pInfoBuffer, U32 Data);
void USB_IB_AddBytes            (USB_INFO_BUFFER * pInfoBuffer, const U8 * pData, U32 NumBytes);
U8 * USB_IB_GetP                (const USB_INFO_BUFFER * pInfoBuffer);

/*********************************************************************
*
*       Buffer routines
*
**********************************************************************
*/
unsigned USBD_BUFFER_Read       (USB_BUFFER * pBuffer,       U8 * pData, unsigned NumBytesReq);
unsigned USBD_BUFFER_Write      (USB_BUFFER * pBuffer, const U8 * pData, unsigned NumBytes);

/*********************************************************************
*
*       Legacy
*
**********************************************************************
*/
#define  USB__DecRI()         USB_OS_DecRI()
#define  USB__IncDI()         USB_OS_IncDI()

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif // USB_PRIVATE_H

/*************************** End of file ****************************/
