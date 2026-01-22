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
Purpose : Public header of the mass storage device client
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_MSD_H          /* Avoid multiple inclusion */
#define USBD_MSD_H

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

#ifndef   MSD_DEBUG_LEVEL
  #define MSD_DEBUG_LEVEL 0
#endif

#ifndef   USB_MSD_MAX_UNIT
  #define USB_MSD_MAX_UNIT 4u        // Maximum number of logical units (LUN)
#endif

#ifndef   USB_MSD_POLL_TIMEOUT
  #define USB_MSD_POLL_TIMEOUT 100u  // Timeout used with USBD_MSD_Poll()
#endif

#ifndef   MSD_USB_CLASS
  #define MSD_USB_CLASS     8u       // 8: Mass storage
#endif

#ifndef   MSD_USB_SUBCLASS
  #define MSD_USB_SUBCLASS  6u       // 1: RBC (reduced SCSI) 2: ATAPI, 3: QIC 157, 4: UFI, 6: SCSI
#endif

#ifndef   MSD_USB_PROTOCOL
  #define MSD_USB_PROTOCOL  0x50u    // 0x50: BOT (Bulk-only-transport)
#endif

#ifndef USB_V2_V3_MIGRATION_MSD_LUN_INFO
  #define USB_V2_V3_MIGRATION_MSD_LUN_INFO   0
#endif

/*********************************************************************
*
*       Define non-configurable
*
**********************************************************************
*/
#define USB_MSD_MT_WRITE_INFO_SIZE         sizeof(USB_MSD_MT_WRITE_INFO)

//
// Flags for function USBD_MSD_RequestRefresh()
//
#define USB_MSD_TRY_DISCONNECT  (1u << 0)      // Try a medium disconnect before doing a USB detach.
#define USB_MSD_RE_ATTACH       (1u << 1)      // Automatically re-attach after detach has been done.

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef struct _LUN_INFO LUN_INFO;

/*********************************************************************
*
*       PREVENT_ALLOW_REMOVAL_HOOK
*
*  Description
*    Callback function to prevent/allow removal of storage medium.
*    See USBD_MSD_SetPreventAllowRemovalHook().
*
*  Parameters
*    PreventRemoval: Show whether the device shall be locked or not.
*                      * 0 - The device shall be removable.
*                      * 1 - The device shall be locked.
*/
typedef void (PREVENT_ALLOW_REMOVAL_HOOK)(U8 PreventRemoval);

/*********************************************************************
*
*       START_STOP_UNIT_HOOK
*
*  Description
*    Callback function which is called when a START STOP UNIT SCSI command is received.
*
*  Parameters
*    Lun: Specifies the logical unit number.
*    StartLoadEject: Specifies which operation is executed by the host:
*                      * 0 : Stop disk
*                      * 1 : Start disk and make ready for access
*                      * 2 : Eject disk if permitted
*                      * 3 : Load, start and make disk ready.
*/
typedef void (START_STOP_UNIT_HOOK)(U8 Lun, U8 StartLoadEject);
/*********************************************************************
*
*       StartStopUnitHook
*
*  Description
*    Output compressed data.
*
*  Parameters
*    Lun: Specifies the logical unit number.
*    StartLoadEject: Specifies which operation is executed by the host:
*                      * 0 : Stop disk
*                      * 1 : Start disk and make ready for access
*                      * 2 : Eject disk if permitted
*                      * 3 : Load, start and make disk ready.
*/
void StartStopUnitHook(U8 Lun, U8 StartLoadEject);

/*********************************************************************
*
*       READ_WRITE_HOOK
*
*  Description
*    Callback function which is called with every read/write access to the storage medium.
*
*  Parameters
*    Lun       : Specifies the logical unit number which was accessed through read or write.
*    IsRead    : Specifies whether a read or a write access was used:
*                  * 1 : read
*                  * 0 : write
*    OnOff     : States whether the read or write request has been initialized (1) or whether it is complete (0).
*    StartLBA  : The first Logical Block Address accessed by the transfer.
*    NumBlocks : The number of blocks accessed by the transfer, starting from the StartLBA.
*/
typedef void (READ_WRITE_HOOK)(U8 Lun, U8 IsRead, U8 OnOff, U32 StartLBA, U32 NumBlocks);

/*********************************************************************
*
*       USB_MSD_HANDLE_CMD
*
*  Description
*    [Internal]
*    Handles other SCSI commands and help the MSD layer to  executes other command.
*    This callback is eg used to handle CD-ROM commands.
*
*
*  Parameters
*    pLUNInfo   : Pointer to the internal LUNInfo
*    pCmdBlock  : Pointer to the Cmd Block the host has sent to us.
*    pNumBytes  : [IN] Number of Byte to be transferred
*                 [OUT] Number of Bytes actually sent.
*
*  Return value
*    <  0 - Command failed
*    == 0 - Command was successful.
*/
typedef U8   (USB_MSD_HANDLE_CMD)(LUN_INFO * pLUNInfo, U8 * pCmdBlock, U32 * pNumBytes);

/*********************************************************************
*
*       USB_MSD_INFO
*
*  Description
*    emUSB-Device-MSD storage interface.
*/
typedef struct {
  U32 NumSectors;             // Number of available sectors.
  U16 SectorSize;             // Size of one sector in bytes.
} USB_MSD_INFO;

/*********************************************************************
*
*       USB_MSD_LUN_INFO
*
*  Description
*    Structure that is used when adding a logical volume to emUSB-Device-MSD.
*/
typedef struct {
  const char * pVendorName;     // Vendor name of the mass storage device. The string should be no longer than 8 bytes.
  const char * pProductName;    // Product name of the mass storage device. The product name string should be no longer than 16 bytes.
  const char * pProductVer;     // Product version number of the mass storage device. The product version string should be no longer than 4 bytes.
  const char * pSerialNo;       // Product serial number of the mass storage device. The serial number string must be exactly 12 bytes, in order to satisfy the
                                // USB bootability specification requirements.
} USB_MSD_LUN_INFO;

/*********************************************************************
*
*       USB_MSD_INIT_DATA
*
*  Description
*    emUSB-Device-MSD initialization structure that is required
*    when adding an MSD interface.
*/
typedef struct {
  U8 EPIn;                // Bulk IN endpoint for sending data to the host.
  U8 EPOut;               // Bulk OUT endpoint for receiving data from the host.
  U8 InterfaceNum;        // Interface number. This member is used internally, set to 0.
} USB_MSD_INIT_DATA;

/*********************************************************************
*
*       USB_MSD_INST_DATA_DRIVER
*
*  Description
*    USB-MSD initialization structure that is required
*    when adding an MSD interface.
*/
typedef struct {                // NOLINT(clang-analyzer-optin.performance.Padding)
  void     * pStart;            // A pointer defining the start address
  U32        StartSector;       // The start sector that is used for the driver.
  U32        NumSectors;        // The available number of sectors available for the driver.
  U16        SectorSize;        // The sector size that should be used by the driver.
  void     * pSectorBuffer;     // Pointer to an application provided buffer to be used as temporary buffer for storing the sector data.
  unsigned   NumBytes4Buffer;   // Size of the application provided buffer.
  U8         NumBuffers;        // Number of buffer that are available. This is only used when using the MT storage layer.
} USB_MSD_INST_DATA_DRIVER;

/*********************************************************************
*
*       USB_MSD_STORAGE_INIT
*
*  Description
*   Initializes the storage medium.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    pDriverData  : Pointer to a USB_MSD_INST_DATA_DRIVER structure that contains all
*                   information that is necessary for the driver initialization.
*                   Refer to USB_MSD_INST_DATA_DRIVER structure for detailed information.
*
*/
typedef void       (USB_MSD_STORAGE_INIT)           (U8 Lun, const USB_MSD_INST_DATA_DRIVER * pDriverData);

/*********************************************************************
*
*       USB_MSD_STORAGE_GETINFO
*
*  Description
*    Retrieves storage medium information such as sector size and number of sectors available.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    pInfo        : Pointer to a USB_MSD_INFO structure. For detailed information about the USB_MSD_INFO structure, refer to USB_MSD_INFO.
*
*/
typedef void       (USB_MSD_STORAGE_GETINFO)        (U8 Lun, USB_MSD_INFO * pInfo);
/*********************************************************************
*
*       USB_MSD_STORAGE_GETREADBUFFER
*
*  Description
*    Prepares the read function and returns a pointer to a buffer that is used by the storage driver.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    SectorIndex  : Specifies the start sector for the read operation.
*    ppData       : Pointer to a pointer to store the read buffer address of the driver.
*    NumSectors   : Number of sectors to read.
*
*  Return value
*    Maximum number of consecutive sectors that can be read at once by the driver.
*/
typedef U32        (USB_MSD_STORAGE_GETREADBUFFER)  (U8 Lun, U32 SectorIndex, void ** ppData, U32 NumSectors);
/*********************************************************************
*
*       USB_MSD_STORAGE_READ
*
*  Description
*    Reads one or multiple consecutive sectors from the storage medium.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    SectorIndex  : Specifies the start sector from where the read operation is started.
*    pData        : Pointer to buffer to store the read data.
*    NumSectors   : Number of sectors to read.
*
*  Return value
*    == 0 - Success.
*    != 0 - Failed.
*/
typedef I8       (USB_MSD_STORAGE_READ)           (U8 Lun, U32 SectorIndex, void *   pData, U32 NumSectors);
/*********************************************************************
*
*       USB_MSD_STORAGE_GETWRITEBUFFER
*
*  Description
*    Prepares the write function and returns a pointer to a buffer that is used by the storage driver.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    SectorIndex  : Specifies the start sector for the write operation.
*    ppData       : Pointer to a pointer to store the write buffer address of the driver.
*    NumSectors   : Number of sectors to write.
*
*  Return value
*    Maximum number of consecutive sectors that can be written into the buffer.
*/
typedef U32        (USB_MSD_STORAGE_GETWRITEBUFFER) (U8 Lun, U32 SectorIndex,       void ** ppData, U32 NumSectors);
/*********************************************************************
*
*       USB_MSD_STORAGE_WRITE
*
*  Description
*    Writes one or more consecutive sectors to the storage medium.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*    SectorIndex  : Specifies the start sector for the write operation.
*    pData        : Pointer to data to be written to the storage medium.
*    NumSectors   : Number of sectors to write.
*
*  Return value
*    == 0 - Success.
*    != 0 - Failed.
*/
typedef I8       (USB_MSD_STORAGE_WRITE)          (U8 Lun, U32 SectorIndex, const void *   pData, U32 NumSectors);
/*********************************************************************
*
*       USB_MSD_STORAGE_MEDIUMISPRESENT
*
*  Description
*    Checks if medium is present.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*
*  Return value
*    == 1: Medium is present.
*    == 0: Medium is not present.
*/
typedef I8       (USB_MSD_STORAGE_MEDIUMISPRESENT)(U8 Lun);
/*********************************************************************
*
*       USB_MSD_STORAGE_DEINIT
*
*  Description
*    De-initializes the storage medium.
*
*  Parameters
*    Lun          : Logical unit number. Specifies for which drive the function is called.
*
*/
typedef void       (USB_MSD_STORAGE_DEINIT)         (U8 Lun);

/*********************************************************************
*
*       USB_MSD_STORAGE_API
*
*  Description
*    USB-MSD initialization structure that is required
*    when adding an MSD interface.
*/
typedef struct {
  USB_MSD_STORAGE_INIT            * pfInit;                  // Initializes the storage medium.
  USB_MSD_STORAGE_GETINFO         * pfGetInfo;               // Retrieves storage medium information such as sector size and number of sectors available.
  USB_MSD_STORAGE_GETREADBUFFER   * pfGetReadBuffer;         // Prepares read function and returns a pointer to a buffer that is used by the storage driver.
  USB_MSD_STORAGE_READ            * pfRead;                  // Reads one or multiple sectors from the storage medium.
  USB_MSD_STORAGE_GETWRITEBUFFER  * pfGetWriteBuffer;        // Prepares write function and returns a pointer to a buffer that is used by the storage driver.
  USB_MSD_STORAGE_WRITE           * pfWrite;                 // Writes one or more sectors to the storage medium.
  USB_MSD_STORAGE_MEDIUMISPRESENT * pfMediumIsPresent;       // Checks if medium is present.
  USB_MSD_STORAGE_DEINIT          * pfDeInit;                // De-initializes the storage medium.
} USB_MSD_STORAGE_API;

/*********************************************************************
*
*       USB_MSD_INST_DATA
*
*  Description
*    USB-MSD initialization structure that is required when adding an MSD interface.
*
*  Additional information
*    All non-optional members of this structure need to be initialized correctly,
*    except DeviceType and pfHandleCmd because it is done by the functions
*    USBD_MSD_AddUnit() or USBD_MSD_AddCDROM().
*/
typedef struct {                                // NOLINT(clang-analyzer-optin.performance.Padding)
  const USB_MSD_STORAGE_API * pAPI;             // Pointer to a structure that holds the storage device driver API.
  USB_MSD_INST_DATA_DRIVER    DriverData;       // Driver data that are passed to the storage driver.
                                                // Refer to USB_MSD_INST_DATA_DRIVER for detailed information about how to initialize this structure.
  U8                          DeviceType;       // Determines the type of the device:
                                                //   + 0: Direct access block device
                                                //   + 5: CD/DVD
  U8                          IsPresent;        // Determines if the medium is storage is present. For non-removable devices always 1.
  USB_MSD_HANDLE_CMD        * pfHandleCmd;      // Optional pointer to a callback function which handles SCSI commands.
  U8                          IsWriteProtected; // Specifies whether the storage medium shall be write-protected.
  const USB_MSD_LUN_INFO    * pLunInfo;         // Pointer to a USB_MSD_LUN_INFO structure. Filling this structure is mandatory for each LUN.
} USB_MSD_INST_DATA;

typedef struct {
  U32         SectorIndex;
  U32         NumSectors;
} USB_MSD_MT_WRITE_INFO;


/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void USBD_MSD_Init    (void);
void USBD_MSD_Add     (const USB_MSD_INIT_DATA * pInitData);
void USBD_MSD_AddUnit (const USB_MSD_INST_DATA * pInstData);
void USBD_MSD_AddCDRom(const USB_MSD_INST_DATA * pInstData);

void USBD_MSD_SetPreventAllowRemovalHook  (U8 Lun, PREVENT_ALLOW_REMOVAL_HOOK    * pfOnPreventAllowRemoval);
void USBD_MSD_SetStartStopUnitHook        (U8 Lun, START_STOP_UNIT_HOOK          * pfOnStartStopUnit);
void USBD_MSD_SetReadWriteHook            (U8 Lun, READ_WRITE_HOOK               * pfOnReadWrite);

int  USBD_MSD_Poll   (void);
int  USBD_MSD_PollEx (unsigned Timeout);
void USBD_MSD_Task   (void);

#if USB_V2_V3_MIGRATION_MSD_LUN_INFO > 0
const char * USB_MSD_GetProductVer (U8 Lun);
const char * USB_MSD_GetProductName(U8 Lun);
const char * USB_MSD_GetVendorName (U8 Lun);
const char * USB_MSD_GetSerialNo   (U8 Lun);
#endif

void USBD_MSD_RequestDisconnect   (U8 Lun);
void USBD_MSD_Disconnect          (U8 Lun);
int  USBD_MSD_WaitForDisconnection(U8 Lun, U32 TimeOut);
void USBD_MSD_Connect             (U8 Lun);
void USBD_MSD_UpdateWriteProtect  (U8 Lun, U8 IsWriteProtected);
void USBD_MSD_RequestRefresh      (U8 Lun, U32 Flags);

/*********************************************************************
*
*       API functions for the multi-task storage
*
**********************************************************************
*/
void USBD_MSD_StorageTask(void);
void USBD_MSD_Storage_MTInit(void);

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_API > 0
#define  USB_MSD_Init                                   USBD_MSD_Init
#define  USB_MSD_Add                                    USBD_MSD_Add
#define  USB_MSD_AddUnit                                USBD_MSD_AddUnit
#define  USB_MSD_AddCDRom                               USBD_MSD_AddCDRom
#define  USB_MSD_SetPreventAllowRemovalHook             USBD_MSD_SetPreventAllowRemovalHook
//lint -esym(621, USB_MSD_SetPreventAllowRemovalHookEx) N:100
#define  USB_MSD_SetPreventAllowRemovalHookEx           USBD_MSD_SetPreventAllowRemovalHookEx
#define  USB_MSD_SetStartStopUnitHook                   USBD_MSD_SetStartStopUnitHook
#define  USB_MSD_SetReadWriteHook                       USBD_MSD_SetReadWriteHook
#define  USB_MSD_Task                                   USBD_MSD_Task
#define  USB_MSD_RequestDisconnect                      USBD_MSD_RequestDisconnect
#define  USB_MSD_Disconnect                             USBD_MSD_Disconnect
#define  USB_MSD_WaitForDisconnection                   USBD_MSD_WaitForDisconnection
#define  USB_MSD_Connect                                USBD_MSD_Connect
#define  USB_MSD_UpdateWriteProtect                     USBD_MSD_UpdateWriteProtect
#define  USB_MSD_UpdateSenseInfo                        USBD_MSD_UpdateSenseInfo
#define  USB_MSD_StorageTask                            USBD_MSD_StorageTask
#define  USB_MSD_Storage_MTInit(x)                      USBD_MSD_Storage_MTInit()
#endif

/*********************************************************************
*
*       Storage interface
*
**********************************************************************
*/

extern const USB_MSD_STORAGE_API USB_MSD_StorageRAM;
extern const USB_MSD_STORAGE_API USB_MSD_StorageByIndex;
extern const USB_MSD_STORAGE_API USB_MSD_StorageByName;
extern const USB_MSD_STORAGE_API USB_MSD_StorageTrim;
extern const USB_MSD_STORAGE_API USB_MSD_StorageMT;


#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/

