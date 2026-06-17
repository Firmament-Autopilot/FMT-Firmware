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
Purpose : USB_VirtualMSD API specification
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USB_VMSD_H            // Avoid multiple inclusion
#define USB_VMSD_H

#include "Global.h"
#include "USB_MSD.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define USB_VMSD_ATTR_READ_ONLY       (0x01u)
#define USB_VMSD_ATTR_HIDDEN          (0x02u)
#define USB_VMSD_ATTR_SYSTEM          (0x04u)
#define USB_VMSD_ATTR_VOLUME_ID       (0x08u)
#define USB_VMSD_ATTR_DIRECTORY       (0x10u)
#define USB_VMSD_ATTR_ARCHIVE         (0x20u)
#define USB_VMSD_ATTR_LONG_NAME       (USB_VMSD_ATTR_READ_ONLY | USB_VMSD_ATTR_HIDDEN | USB_VMSD_ATTR_SYSTEM | USB_VMSD_ATTR_VOLUME_ID)
#define USB_VMSD_ATTR_LONG_NAME_MASK  (USB_VMSD_ATTR_READ_ONLY | USB_VMSD_ATTR_HIDDEN | USB_VMSD_ATTR_SYSTEM | USB_VMSD_ATTR_VOLUME_ID | USB_VMSD_ATTR_DIRECTORY | USB_VMSD_ATTR_ARCHIVE)

//
// For use in USB_VMSD_CONST_FILE.Flags
//
#define USB_VMSD_FILE_WRITABLE        USB_VMSD_ATTR_READ_ONLY
#define USB_VMSD_FILE_AHEAD           (1uL << 8)

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

/*********************************************************************
*
*       USB_VMSD_CONST_FILE
*
*  Description
*    This structure contains information about a constant file which
*    cannot be changed at run time and should be shown inside the
*    VirtualMSD volume (e.g. Readme.txt).
*    This structure is a parameter for the USBD_VMSD_AddConstFiles()
*    function.
*
*  Additional information
*    If a file does not occupy complete sectors the remaining bytes of the last sector are
*    automatically filled with 0s on read.
*    If pData is NULL the file is not displayed in the volume. This is useful when the application
*    has certain files which should only be displayed after certain events (e.g. the
*    application displays a Fail.txt when the device is reconnected after an unsuccessful
*    firmware update).
*/
typedef struct {
  const char* sName;            // Pointer to a zero-terminated string containing the filename.
  const U8* pData;              // Pointer to the file data. Can be NULL.
  unsigned FileSize;            // Size of the file. Normally the size of the data pointed to by pData.
  U32 Flags;                    // Can be one of the following items:
                                // * USB_VMSD_FILE_WRITABLE: The file is writable
                                // * USB_VMSD_FILE_AHEAD: File is located at the start of the volume. Normally constant files are allocated at the end of the volume.
} USB_VMSD_CONST_FILE;

/*********************************************************************
*
*       USB_VMSD_DIR_ENTRY_SHORT
*
*  Description
*    Structure used to describe an entry with a short file name.
*    This structure is a member of USB_VMSD_DIR_ENTRY.
*/
typedef struct {
  U8  acFilename[8];        // File name, limited to 8 characters (short file name), padded with spaces (0x20).
  U8  acExt[3];             // File extension, limited to 3 characters (short file name), padded with spaces (0x20).
  U8  DirAttr;              // File attributes. Available attributes are listed below.
  U8  NTRes;                // Reserved for use by Windows NT.
  U8  CrtTimeTenth;         // Millisecond stamp at file creation time. This field actually contains a count of tenths of a second.
  U16 CrtTime;              // Creation time.
  U16 CrtDate;              // Date file was created.
  U16 LstAccDate;           // Last access date. Note that there is no last access time, only a date. This is the date of last read or write.
  U16 FstClusHI;            // High word of this entry's first cluster number.
  U16 WrtTime;              // Time of last write.
  U16 WrtDate;              // Date of last write.
  U16 FstClusLO;            // Low word of this entry's first cluster number.
  U32 FileSize;             // File size in bytes.
} USB_VMSD_DIR_ENTRY_SHORT;

/*********************************************************************
*
*       USB_VMSD_DIR_ENTRY_LONG
*
*  Description
*    Structure used to describe an entry with a long file name.
*    This structure is a member of USB_VMSD_DIR_ENTRY.
*    This is for information only, the read and write callbacks
*    only receive short file names.
*/
typedef struct {
  U8  Ord;             // The order of this entry in the sequence of long dir entries, associated with the short dir entry at the end of the long dir set.
  U8  acName1[10];     // Characters 1-5 of the long-name sub-component in this dir entry.
  U8  Attr;            // Attributes - must be USB_VMSD_ATTR_LONG_NAME.
  U8  Type;            // If zero, indicates a directory entry that is a sub-component of a long name. Other values reserved for future extensions. Non-zero implies other types.
  U8  Chksum;          // Checksum of name in the short dir entry at the end of the long dir set.
  U8  acName2[12];     // Characters 6-11 of the long-name sub-component in this dir entry.
  U16 FstClusLO;       // Must be zero.
  U8  acName3[4];      // Characters 12-13 of the long-name sub-component in this dir entry.
} USB_VMSD_DIR_ENTRY_LONG;

/*********************************************************************
*
*       USB_VMSD_DIR_ENTRY
*
*  Description
*    Union containing references to directory entries. This union
*    is a member of USB_VMSD_FILE_INFO.
*
*  Additional information
*    Check USB_VMSD_DIR_ENTRY_SHORT and USB_VMSD_DIR_ENTRY_LONG
*    for more information.
*/
typedef union {
  USB_VMSD_DIR_ENTRY_SHORT ShortEntry;   // Allows to access the entry as a "short directory entry".
  USB_VMSD_DIR_ENTRY_LONG  LongEntry;    // Allows to access the entry as a "long directory entry".
  U8                       ac[32];       // Allows to write directly to the structure without casting or using the members.
} USB_VMSD_DIR_ENTRY;

/*********************************************************************
*
*       USB_VMSD_FILE_INFO
*
*  Description
*    Structure used in the read and write callbacks.
*
*  Additional information
*   Check USB_VMSD_ON_READ_FUNC, USB_VMSD_ON_WRITE_FUNC and
*   USB_VMSD_DIR_ENTRY_SHORT for more information.
*/
typedef struct {
  const USB_VMSD_DIR_ENTRY_SHORT* pDirEntry;    // Pointer to a USB_VMSD_DIR_ENTRY_SHORT structure.
} USB_VMSD_FILE_INFO;

/*********************************************************************
*
*       USB_VMSD_ON_READ_FUNC
*
*  Description
*    Callback function prototype that is used when calling the
*    USBD_VMSD_SetUserAPI() function.
*
*  Parameters
*    Lun          : Zero-based index for the unit number.
                    Using only one virtual volume, this parameter is 0.
*    pData        : Pointer to a buffer in which the data is stored.
*    Off          : Offset in the file which is read by the host.
*    NumBytes     : Amount of bytes requested by the host.
*    pFile        : Pointer to a USB_VMSD_FILE_INFO structure describing the file.
*
*  Return value
*    == 0:   Success.
*    != 0:   An error occurred.
*/
typedef int    (USB_VMSD_ON_READ_FUNC)(unsigned Lun, U8 * pData, U32 Off, U32 NumBytes, const USB_VMSD_FILE_INFO * pFile);

/*********************************************************************
*
*       USB_VMSD_ON_WRITE_FUNC
*
*  Description
*    Callback function prototype that is used when calling the
*    USBD_VMSD_SetUserAPI() function.
*
*  Parameters
*    Lun          : Zero-based index for the unit number.
*                   Using only one virtual volume, this parameter is 0.
*    pData        : Pointer to the data to be written (received from the host).
*                   If pData == NULL, then there are no data written by the host,
*                   but instead a new or changed directory entry was written,
*                   which is provided via pFile.
*    Off          : Offset in the file which the host writes.
*    NumBytes     : Amount of bytes to write.
*    pFile        : Pointer to a USB_VMSD_FILE_INFO structure describing the file or NULL.
*
*  Return value
*    == 0:   Success.
*    == 1:   Enable continuous sector mode: From now on, only forward writes to continuous
*            sectors to the user callback. Ignore writes to all other sectors.
*    == -1:  Disable continuous sector mode.
*    == -2:  Report write error to USB host.
*
*  Additional information
*    Depending on the behavior of the host operating system it is possible that pFile is
*    NULL. In this case we recommend to perform data analysis to recognize the file.
*/
typedef int    (USB_VMSD_ON_WRITE_FUNC)(unsigned Lun, const U8   * pData, U32 Off, U32 NumBytes, const USB_VMSD_FILE_INFO * pFile);

/*********************************************************************
*
*       USB_VMSD_MEM_ALLOC
*
*  Description
*    Function prototype that is used when memory is being allocated
*    by the VirtualMSD module.
*
*  Parameters
*    Size       : Size of the required memory in bytes.
*
*  Return value
*    Pointer to the allocated memory or NULL.
*/
typedef void * (USB_VMSD_MEM_ALLOC)(U32 Size);

/*********************************************************************
*
*       USB_VMSD_MEM_FREE
*
*  Description
*    Function prototype that is used when memory is being freed
*    by the VirtualMSD module.
*
*  Parameters
*    p     : Pointer to a memory block which was previously
*            allocated by USB_VMSD_MEM_ALLOC.
*/
typedef void   (USB_VMSD_MEM_FREE)(void * p);

/*********************************************************************
*
*       USB_VMSD_CONST_FILE
*
*  Description
*    This structure contains the function pointers for user provided functions.
*    This structure is a parameter for the USBD_VMSD_SetUserAPI() function.
*/
typedef struct _USB_VMSD_USER_FUNC_API {
  USB_VMSD_ON_READ_FUNC  * pfOnReadSector;             // Pointer to a callback function of type USB_VMSD_ON_READ_FUNC which
                                                       // is called when a sector is read from the host.
                                                       // This function is mandatory and can not be NULL.
  USB_VMSD_ON_WRITE_FUNC * pfOnWriteSector;            // Pointer to a callback function of type USB_VMSD_ON_WRITE_FUNC which
                                                       // is called when a sector is written from the host.
                                                       // This function is mandatory and can not be NULL.
  USB_VMSD_MEM_ALLOC     * pfMemAlloc;                 // Pointer to a user provided alloc function of type USB_VMSD_MEM_ALLOC.
                                                       // If this pointer is NULL the internal alloc function is called.
                                                       // If no memory block is assigned USB_PANIC() is called.
  USB_VMSD_MEM_FREE      * pfMemFree;                  // Pointer to a user provided free function of type USB_VMSD_MEM_FREE.
                                                       // If this pointer is NULL the internal free function is called.
} USB_VMSD_USER_FUNC_API;

/*********************************************************************
*
*       Const data
*
**********************************************************************
*/
extern const USB_MSD_STORAGE_API USB_MSD_StorageVMSD;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
//
// Configuration functions that can be called within the USB_VMSD_X_Config function
//
void USBD_VMSD_AssignMemory          (U32 * p, U32 NumBytes);
void USBD_VMSD_SetUserAPI            (const USB_VMSD_USER_FUNC_API            * pUserFunc);
void USBD_VMSD_SetNumRootDirSectors  (unsigned Lun, unsigned                    NumRootDirSectors);
int  USBD_VMSD_SetVolumeInfo         (unsigned Lun, const char                * sVolumeName, const USB_MSD_LUN_INFO * pLunInfo);
int  USBD_VMSD_AddConstFiles         (unsigned Lun, const USB_VMSD_CONST_FILE * paConstFile, unsigned NumFiles);    // Add list of predefined files. such as Readme.txt, ...
void USBD_VMSD_SetNumSectors         (unsigned Lun, unsigned                    NumSectors);
void USBD_VMSD_SetSectorsPerCluster  (unsigned Lun, unsigned                    SectorsPerCluster);

void USBD_VMSD_Add                   (void);
void USBD_VMSD_Init                  (void);
void USBD_VMSD_ReInit                (void);
void USBD_VMSD_DeInit                (void);

void USB_VMSD_X_Config               (void);    // Has to be defined by user

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/

#if USB_V2_V3_MIGRATION_API > 0
#define USB_VMSD_AssignMemory           USBD_VMSD_AssignMemory
#define USB_VMSD_SetUserAPI             USBD_VMSD_SetUserAPI
#define USB_VMSD_SetNumRootDirSectors   USBD_VMSD_SetNumRootDirSectors
#define USB_VMSD_SetVolumeInfo          USBD_VMSD_SetVolumeInfo
#define USB_VMSD_AddConstFiles          USBD_VMSD_AddConstFiles
#define USB_VMSD_SetNumSectors          USBD_VMSD_SetNumSectors
#define USB_VMSD_SetSectorsPerCluster   USBD_VMSD_SetSectorsPerCluster

#define USB_VMSD_Init                   USBD_VMSD_Add
#define USB_VMSD_ReInit                 USBD_VMSD_ReInit
#define USB_VMSD_DeInit                 USBD_VMSD_DeInit
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
