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
Purpose : Public header of USB MTP (Media Transfer Protocol)
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_MTP_H          /* Avoid multiple inclusion */
#define USBD_MTP_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       defines, configurable
*
**********************************************************************
*/
#ifndef   USB_MTP_POLL_TIMEOUT
  #define USB_MTP_POLL_TIMEOUT        100u  // Timeout used with USBD_MTP_Poll()
#endif

#ifndef   USB_MTP_READ_TIMEOUT
  #define USB_MTP_READ_TIMEOUT      10000u  // Timeout used for read operations. Should be at least 100 ms.
#endif

#ifndef   MTP_MAX_NUM_STORAGES
  #define MTP_MAX_NUM_STORAGES          4u  // Maximum number of storage units
#endif

#ifndef   MTP_SAVE_FILE_INFO
  #define MTP_SAVE_FILE_INFO            0   // Information related to file is stored in object instance. Requires more RAM.
#endif

#ifndef   MTP_MAX_FILE_PATH
  #define MTP_MAX_FILE_PATH           256   // Maximum number of characters in the path of a file or directory
#endif

#ifndef   MTP_SUPPORT_UTF8
  #define MTP_SUPPORT_UTF8              1   // File/directory names are encoded in UTF-8 format
#endif

#ifndef   MTP_SUPPORT_EVENTS
  #define MTP_SUPPORT_EVENTS            1   // Support Events such as object removed/added, new storage added/removed
#endif

#ifndef   MTP_SUPPORT_DEV_PROPERTIES
  #define MTP_SUPPORT_DEV_PROPERTIES    1   // Support Device properties
#endif

#ifndef   USB_MTP_NAME_CASE_SENSITIVE
  #define USB_MTP_NAME_CASE_SENSITIVE   0   // When checking file names and directory names the string compare will be case sensitive.
                                            //   0 - case sensitivity is not checked. (default)
                                            //   1 - case sensitivity is checked.
#endif

#ifndef USB_V2_V3_MIGRATION_MTP_INFO
  #define USB_V2_V3_MIGRATION_MTP_INFO  0
#endif

#ifndef   MTP_SEND_EVENT_TIMEOUT
  #define MTP_SEND_EVENT_TIMEOUT      256   // Max bInterval is 255 in FS, with 256 all intervals are possible,
                                            // if the host does not retrieve the event after the timeout the host has an issue.
#endif

#ifndef   USB_MTP_SUPPORT_SEGGER_CMD
  #define USB_MTP_SUPPORT_SEGGER_CMD    0   // Enables custom read and write commands to be used over the MTP protocol.
#endif

#ifndef   USB_MTP_OLD_MOUNTING_BEHAVIOR
  #define USB_MTP_OLD_MOUNTING_BEHAVIOR    0    // Defines whether to use the old mounting behavior
                                                // With version V3.54.0 and older the MTP Storage layer for emFile would automatically call FS_Mount.
                                                // 0 - Do not automatically call FS_Mount - volume must be mounted by the application.
                                                // 1 - Call FS_Mount automatically.
#endif

#ifndef   USB_MTP_SUPPORT_OPERATION_CB
  #define USB_MTP_SUPPORT_OPERATION_CB  0   // Enable support for MTP operation notifications.
#endif

/*********************************************************************
*
*       defines, non-configurable
*
**********************************************************************
*/
#define MTP_USB_CLASS             6       // Class of USB device
#define MTP_USB_SUBCLASS          1       // Subclass of USB device
#define MTP_USB_PROTOCOL          1       // Protocol of USB device

#define MTP_NUM_BYTES_FILE_ID     16u

#define MTP_FILE_ATTR_WP          0x01u
#define MTP_FILE_ATTR_SYSTEM      0x02u
#define MTP_FILE_ATTR_HIDDEN      0x04u

#define USB_MTP_OBJECT_PROP_ALL_PROPERTIES     0xFFFFFFFFUL

/*********************************************************************
*
*       Write protection attributes
*
*  Description
*    Flags to set write protection for a storage.
*    To be used in the USB_MTP_INST_DATA_DRIVER structure.
*/
#define MTP_STORAGE_PROTECT_WRITE   0x01u     // Prohibit file write
#define MTP_STORAGE_PROTECT_DELETE  0x02u     // Prohibit file delete
#define MTP_STORAGE_PROTECT_FORMAT  0x04u     // Prohibit storage formatting
#define MTP_STORAGE_PROTECT_ALL     0x07u     // Prohibit all write access

/*********************************************************************
*
*       Typedefs, enums and structs
*
**********************************************************************
*/
/*********************************************************************
*
*       USB_MTP_EVENT
*
*  Description
*    Enum containing the MTP event codes.
*/
typedef enum _USB_MTP_EVENT {
  USB_MTP_EVENT_UNDEFINED = 0x4000,         // This event code is undefined, and is not used
  USB_MTP_EVENT_CANCELTRANSACTION,          // This event is used to initiate the cancellation
                                            // of a transaction over transports which do not have
                                            // their own mechanism for canceling transactions.
                                            // Currently not used.
  USB_MTP_EVENT_OBJECTADDED,                // This event informs the host about a new object
                                            // that has been added to the storage.
  USB_MTP_EVENT_OBJECTREMOVED,              // Informs the host that an object has been removed.
  USB_MTP_EVENT_STOREADDED,                 // This event indicates that a storage has been added
                                            // to the device. It allows to dynamically show the available storages.
  USB_MTP_EVENT_STOREREMOVED,               // This event indicates that a storage has been removed to the device.
                                            // It allows to dynamically hide the available storages.
  USB_MTP_EVENT_DEVICEPROPCHANGED,          // A property changed on the device has occurred. Currently not used.
  USB_MTP_EVENT_OBJECTINFOCHANGED,          // This event indicates that the information for a particular object
                                            // has changed and that the host should acquire the information once again.
  USB_MTP_EVENT_DEVICEINFOCHANGED,          // This event indicates that the capabilities of the device have
                                            // changed and that the DeviceInfo should be requested again.
                                            // Currently not used.
  USB_MTP_EVENT_REQUESTOBJECTTRANSFER,      // This event can be used by the device to ask the host to initiate
                                            // an file object transfer to him. Currently not used.
  USB_MTP_EVENT_STOREFULL,                  // This event should be sent when a storage becomes full.
  USB_MTP_EVENT_DEVICERESET,                // Notifies the host about an internal reset. Currently not used
  USB_MTP_EVENT_STORAGEINFOCHANGED,         // This event is used when information of a storage changes.
  USB_MTP_EVENT_CAPTURECOMPLETE,            // Informs the host that the previously initiated capture acquire
                                            // is complete. Currently not used.
  USB_MTP_EVENT_UNREPORTEDSTATUS,           // This event may be implemented for certain transports in cases
                                            // where the responder unable to report events to the initiator
                                            // regarding changes in its internal status. Currently not used.
  USB_MTP_EVENT_OBJECTPROPCHANGED = 0xC801, // Informs about a change in the object property of an specific object.
                                            // Currently not used.
  USB_MTP_EVENT_OBJECTPROPDESCCHANGED,      // This event informs that the property description of an object
                                            // property has been changed and needs to be re-acquired.
                                            // Currently not used.
  USB_MTP_EVENT_OBJECTREFERENCESCHANGED     // This event is used to indicate that the references on an object
                                            // have been updated. Currently not used.
} USB_MTP_EVENT;

/*********************************************************************
*
*       USB_MTP_OPERATION_CB_TYPE
*
*  Description
*    Enum containing the callback operation types.
*/
#if USB_MTP_SUPPORT_OPERATION_CB
typedef enum _USB_MTP_OPERATION_CB_TYPE {
  USB_MTP_OPERATION_OBJECT_ADDED,             // A new object has been added.
  USB_MTP_OPERATION_OBJECT_REMOVED,           // An object is about to be removed.
  USB_MTP_OPERATION_OBJECT_RENAMED_OLD_NAME,  // An object is being renamed - old name of the object.
  USB_MTP_OPERATION_OBJECT_RENAMED_NEW_NAME   // An object is being renamed - new name of the object.
} USB_MTP_OPERATION_CB_TYPE; /*lint !e621 N:100 */
#endif


/*********************************************************************
*
*       USB_MTP_STORAGE_CB_TYPE
*
*  Description
*    Enum containing the callback operation types for the USB_MTP_WP_CB
*    callback registered via USBD_MTP_SetWriteProtectionCb()
*/
typedef enum _USB_MTP_STORAGE_CB_TYPE {
  USB_MTP_STORAGE_CB_FILE_CREATE, // File is being created.
  USB_MTP_STORAGE_CB_FILE_REMOVE, // File is being deleted.
  USB_MTP_STORAGE_CB_DIR_CREATE,  // Directory is being created.
  USB_MTP_STORAGE_CB_DIR_REMOVE,  // Directory is being removed.
  USB_MTP_STORAGE_CB_RENAME,      // File or dir is being renamed.
  USB_MTP_STORAGE_CB_MODIFY       // File or dir attributes are being modified.
} USB_MTP_STORAGE_CB_TYPE;

/*********************************************************************
*
*       USB_MTP_INST_DATA_DRIVER
*
*  Description
*    Structure which stores the parameters passed to the storage driver.
*
*  Additional information
*    pRootDir can specify the root of the file system or any other subdirectory.
*/
typedef struct USB_MTP_INST_DATA_DRIVER {
  const char * pRootDir;          // Path to directory to be used as the root of the storage.
  U8           IsRemovable;       // Set to 1 if the storage is removable.
  U8           Protect;           // Set write protection for this storage to prevent
                                  // writing / deleting of files or formating the storage,
                                  // see MTP_STORAGE_PROTECT_... macros.
} USB_MTP_INST_DATA_DRIVER;

/*********************************************************************
*
*       USB_MTP_STORAGE_INFO
*
*  Description
*    Structure which stores information about a storage.
*/
typedef struct USB_MTP_STORAGE_INFO {
  U32  NumKBytesTotal;            // Storage capacity in kBytes
  U32  NumKBytesFreeSpace;        // Available free space on storage in kBytes
  U16  FSType;                    // Type of file system as specified by MTP
  U8   IsWriteProtected;          // Set to 1 if the storage medium can not be modified
  U8   IsRemovable;               // Set to 1 if the storage medium can be removed from device
  char DirDelimiter;              // Character which separates the directory/file names in a path
  U8   BigFileSupport;            // Store layer should set this to 1 if it supports files > 4GB.
} USB_MTP_STORAGE_INFO;

/*********************************************************************
*
*       USB_MTP_FILE_INFO
*
*  Description
*    Structure which stores information about a file or directory.
*/
typedef struct USB_MTP_FILE_INFO {
  const char * pFilePath;         // Full path to file.
  const char * pFileName;         // Pointer to beginning of file/directory name in pFilePath.
  U64    FileSize;                // Size of the file in bytes.
  U32    CreationTime;            // The time and date when the file was created.
  U32    LastWriteTime;           // The time and date when the file was last modified.
  U8     IsDirectory;             // Set to 1 if the path points to a directory.
  U8     Attributes;              // Bitmask of file attributes (MTP_FILE_ATTR_...).
  U8     acId[MTP_NUM_BYTES_FILE_ID]; // Unique identifier which persists between MTP sessions.
} USB_MTP_FILE_INFO;

/*********************************************************************
*
*       USB_MTP_OPERATION_INFO
*
*  Description
*    Structure which provides information about a new MTP operation.
*/
#if USB_MTP_SUPPORT_OPERATION_CB
typedef struct USB_MTP_OPERATION_INFO {
  const char * pFilePath;         // Full path to file.
  U8           IsDirectory;       // Set to 1 if the path points to a directory.
} USB_MTP_OPERATION_INFO;
#endif

/*********************************************************************
*
*       Codes for object and device properties
*/
typedef enum _USB_MTP_OBJECT_PROPERTIES {
  /*lint --e{621} N:100 */
  USB_MTP_OBJECT_PROP_STORAGE_ID                            = 0xDC01u,
  USB_MTP_OBJECT_PROP_OBJECT_FORMAT                         = 0xDC02u,
  USB_MTP_OBJECT_PROP_PROTECTION_STATUS                     = 0xDC03u,
  USB_MTP_OBJECT_PROP_OBJECT_SIZE                           = 0xDC04u,
  USB_MTP_OBJECT_PROP_ASSOCIATION_TYPE                      = 0xDC05u,
  USB_MTP_OBJECT_PROP_ASSOCIATION_DESC                      = 0xDC06u,
  USB_MTP_OBJECT_PROP_OBJECT_FILE_NAME                      = 0xDC07u,
  USB_MTP_OBJECT_PROP_DATE_CREATED                          = 0xDC08u,
  USB_MTP_OBJECT_PROP_DATE_MODIFIED                         = 0xDC09u,
  USB_MTP_OBJECT_PROP_KEYWORDS                              = 0xDC0Au,
  USB_MTP_OBJECT_PROP_PARENT_OBJECT                         = 0xDC0Bu,
  USB_MTP_OBJECT_PROP_ALLOWED_FOLDER_CONTENTS               = 0xDC0Cu,
  USB_MTP_OBJECT_PROP_HIDDEN                                = 0xDC0Du,
  USB_MTP_OBJECT_PROP_SYSTEM_OBJECT                         = 0xDC0Eu,
  USB_MTP_OBJECT_PROP_PERSISTENT_UNIQUE_OBJECT_IDENTIFIER   = 0xDC41u,
  USB_MTP_OBJECT_PROP_SYNCID                                = 0xDC42u,
  USB_MTP_OBJECT_PROP_PROPERTY_BAG                          = 0xDC43u,
  USB_MTP_OBJECT_PROP_NAME                                  = 0xDC44u,
  USB_MTP_OBJECT_PROP_CREATED_BY                            = 0xDC45u,
  USB_MTP_OBJECT_PROP_ARTIST                                = 0xDC46u,
  USB_MTP_OBJECT_PROP_DATE_AUTHORED                         = 0xDC47u,
  USB_MTP_OBJECT_PROP_DESCRIPTION                           = 0xDC48u,
  USB_MTP_OBJECT_PROP_URL_REFERENCE                         = 0xDC49u,
  USB_MTP_OBJECT_PROP_LANGUAGELOCALE                        = 0xDC4Au,
  USB_MTP_OBJECT_PROP_COPYRIGHT_INFORMATION                 = 0xDC4Bu,
  USB_MTP_OBJECT_PROP_SOURCE                                = 0xDC4Cu,
  USB_MTP_OBJECT_PROP_ORIGIN_LOCATION                       = 0xDC4Du,
  USB_MTP_OBJECT_PROP_DATE_ADDED                            = 0xDC4Eu,
  USB_MTP_OBJECT_PROP_NON_CONSUMABLE                        = 0xDC4Fu,
  USB_MTP_OBJECT_PROP_CORRUPTUNPLAYABLE                     = 0xDC50u,
  USB_MTP_OBJECT_PROP_PRODUCERSERIALNUMBER                  = 0xDC51u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_FORMAT          = 0xDC81u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_SIZE            = 0xDC82u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_HEIGHT          = 0xDC83u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_WIDTH           = 0xDC84u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_DURATION        = 0xDC85u,
  USB_MTP_OBJECT_PROP_REPRESENTATIVE_SAMPLE_DATA            = 0xDC86u,
  USB_MTP_OBJECT_PROP_WIDTH                                 = 0xDC87u,
  USB_MTP_OBJECT_PROP_HEIGHT                                = 0xDC88u,
  USB_MTP_OBJECT_PROP_DURATION                              = 0xDC89u,
  USB_MTP_OBJECT_PROP_RATING                                = 0xDC8Au,
  USB_MTP_OBJECT_PROP_TRACK                                 = 0xDC8Bu,
  USB_MTP_OBJECT_PROP_GENRE                                 = 0xDC8Cu,
  USB_MTP_OBJECT_PROP_CREDITS                               = 0xDC8Du,
  USB_MTP_OBJECT_PROP_LYRICS                                = 0xDC8Eu,
  USB_MTP_OBJECT_PROP_SUBSCRIPTION_CONTENT_ID               = 0xDC8Fu,
  USB_MTP_OBJECT_PROP_PRODUCED_BY                           = 0xDC90u,
  USB_MTP_OBJECT_PROP_USE_COUNT                             = 0xDC91u,
  USB_MTP_OBJECT_PROP_SKIP_COUNT                            = 0xDC92u,
  USB_MTP_OBJECT_PROP_LAST_ACCESSED                         = 0xDC93u,
  USB_MTP_OBJECT_PROP_PARENTAL_RATING                       = 0xDC94u,
  USB_MTP_OBJECT_PROP_META_GENRE                            = 0xDC95u,
  USB_MTP_OBJECT_PROP_COMPOSER                              = 0xDC96u,
  USB_MTP_OBJECT_PROP_EFFECTIVE_RATING                      = 0xDC97u,
  USB_MTP_OBJECT_PROP_SUBTITLE                              = 0xDC98u,
  USB_MTP_OBJECT_PROP_ORIGINAL_RELEASE_DATE                 = 0xDC99u,
  USB_MTP_OBJECT_PROP_ALBUM_NAME                            = 0xDC9Au,
  USB_MTP_OBJECT_PROP_ALBUM_ARTIST                          = 0xDC9Bu,
  USB_MTP_OBJECT_PROP_MOOD                                  = 0xDC9Cu,
  USB_MTP_OBJECT_PROP_DRM_STATUS                            = 0xDC9Du,
  USB_MTP_OBJECT_PROP_SUB_DESCRIPTION                       = 0xDC9Eu,
  USB_MTP_OBJECT_PROP_IS_CROPPED                            = 0xDCD1u,
  USB_MTP_OBJECT_PROP_IS_COLOUR_CORRECTED                   = 0xDCD2u,
  USB_MTP_OBJECT_PROP_IMAGE_BIT_DEPTH                       = 0xDCD3u,
  USB_MTP_OBJECT_PROP_FNUMBER                               = 0xDCD4u,
  USB_MTP_OBJECT_PROP_EXPOSURE_TIME                         = 0xDCD5u,
  USB_MTP_OBJECT_PROP_EXPOSURE_INDEX                        = 0xDCD6u,
  USB_MTP_OBJECT_PROP_TOTAL_BITRATE                         = 0xDE91u,
  USB_MTP_OBJECT_PROP_BITRATE_TYPE                          = 0xDE92u,
  USB_MTP_OBJECT_PROP_SAMPLE_RATE                           = 0xDE93u,
  USB_MTP_OBJECT_PROP_NUMBER_OF_CHANNELS                    = 0xDE94u,
  USB_MTP_OBJECT_PROP_AUDIO_BITDEPTH                        = 0xDE95u,
  USB_MTP_OBJECT_PROP_SCAN_TYPE                             = 0xDE97u,
  USB_MTP_OBJECT_PROP_AUDIO_WAVE_CODEC                      = 0xDE99u,
  USB_MTP_OBJECT_PROP_AUDIO_BITRATE                         = 0xDE9Au,
  USB_MTP_OBJECT_PROP_VIDEO_FOURCC_CODEC                    = 0xDE9Bu,
  USB_MTP_OBJECT_PROP_VIDEO_BITRATE                         = 0xDE9Cu,
  USB_MTP_OBJECT_PROP_FRAMES_PER_THOUSAND_SECONDS           = 0xDE9Du,
  USB_MTP_OBJECT_PROP_KEYFRAME_DISTANCE                     = 0xDE9Eu,
  USB_MTP_OBJECT_PROP_BUFFER_SIZE                           = 0xDE9Fu,
  USB_MTP_OBJECT_PROP_ENCODING_QUALITY                      = 0xDEA0u,
  USB_MTP_OBJECT_PROP_ENCODING_PROFILE                      = 0xDEA1u,
  USB_MTP_OBJECT_PROP_DISPLAY_NAME                          = 0xDCE0u,
  USB_MTP_OBJECT_PROP_BODY_TEXT                             = 0xDCE1u,
  USB_MTP_OBJECT_PROP_SUBJECT                               = 0xDCE2u,
  USB_MTP_OBJECT_PROP_PRIORITY                              = 0xDCE3u,
  USB_MTP_OBJECT_PROP_GIVEN_NAME                            = 0xDD00u,
  USB_MTP_OBJECT_PROP_MIDDLE_NAMES                          = 0xDD01u,
  USB_MTP_OBJECT_PROP_FAMILY_NAME                           = 0xDD02u,
  USB_MTP_OBJECT_PROP_PREFIX                                = 0xDD03u,
  USB_MTP_OBJECT_PROP_SUFFIX                                = 0xDD04u,
  USB_MTP_OBJECT_PROP_PHONETIC_GIVEN_NAME                   = 0xDD05u,
  USB_MTP_OBJECT_PROP_PHONETIC_FAMILY_NAME                  = 0xDD06u,
  USB_MTP_OBJECT_PROP_EMAIL_PRIMARY                         = 0xDD07u,
  USB_MTP_OBJECT_PROP_EMAIL_PERSONAL_1                      = 0xDD08u,
  USB_MTP_OBJECT_PROP_EMAIL_PERSONAL_2                      = 0xDD09u,
  USB_MTP_OBJECT_PROP_EMAIL_BUSINESS_1                      = 0xDD0Au,
  USB_MTP_OBJECT_PROP_EMAIL_BUSINESS_2                      = 0xDD0Bu,
  USB_MTP_OBJECT_PROP_EMAIL_OTHERS                          = 0xDD0Cu,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_PRIMARY                  = 0xDD0Du,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_PERSONAL                 = 0xDD0Eu,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_PERSONAL_2               = 0xDD0Fu,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_BUSINESS                 = 0xDD10u,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_BUSINESS_2               = 0xDD11u,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_MOBILE                   = 0xDD12u,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_MOBILE_2                 = 0xDD13u,
  USB_MTP_OBJECT_PROP_FAX_NUMBER_PRIMARY                    = 0xDD14u,
  USB_MTP_OBJECT_PROP_FAX_NUMBER_PERSONAL                   = 0xDD15u,
  USB_MTP_OBJECT_PROP_FAX_NUMBER_BUSINESS                   = 0xDD16u,
  USB_MTP_OBJECT_PROP_PAGER_NUMBER                          = 0xDD17u,
  USB_MTP_OBJECT_PROP_PHONE_NUMBER_OTHERS                   = 0xDD18u,
  USB_MTP_OBJECT_PROP_PRIMARY_WEB_ADDRESS                   = 0xDD19u,
  USB_MTP_OBJECT_PROP_PERSONAL_WEB_ADDRESS                  = 0xDD1Au,
  USB_MTP_OBJECT_PROP_BUSINESS_WEB_ADDRESS                  = 0xDD1Bu,
  USB_MTP_OBJECT_PROP_INSTANT_MESSENGER_ADDRESS             = 0xDD1Cu,
  USB_MTP_OBJECT_PROP_INSTANT_MESSENGER_ADDRESS_2           = 0xDD1Du,
  USB_MTP_OBJECT_PROP_INSTANT_MESSENGER_ADDRESS_3           = 0xDD1Eu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_FULL          = 0xDD1Fu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_LINE_1        = 0xDD20u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_LINE_2        = 0xDD21u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_CITY          = 0xDD22u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_REGION        = 0xDD23u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_POSTAL_CODE   = 0xDD24u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_PERSONAL_COUNTRY       = 0xDD25u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_FULL          = 0xDD26u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_LINE_1        = 0xDD27u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_LINE_2        = 0xDD28u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_CITY          = 0xDD29u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_REGION        = 0xDD2Au,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_POSTAL_CODE   = 0xDD2Bu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_BUSINESS_COUNTRY       = 0xDD2Cu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_FULL             = 0xDD2Du,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_LINE_1           = 0xDD2Eu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_LINE_2           = 0xDD2Fu,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_CITY             = 0xDD30u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_REGION           = 0xDD31u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_POSTAL_CODE      = 0xDD32u,
  USB_MTP_OBJECT_PROP_POSTAL_ADDRESS_OTHER_COUNTRY          = 0xDD33u,
  USB_MTP_OBJECT_PROP_ORGANIZATION_NAME                     = 0xDD34u,
  USB_MTP_OBJECT_PROP_PHONETIC_ORGANIZATION_NAME            = 0xDD35u,
  USB_MTP_OBJECT_PROP_ROLE                                  = 0xDD36u,
  USB_MTP_OBJECT_PROP_BIRTHDATE                             = 0xDD37u,
  USB_MTP_OBJECT_PROP_MESSAGE_TO                            = 0xDD40u,
  USB_MTP_OBJECT_PROP_MESSAGE_CC                            = 0xDD41u,
  USB_MTP_OBJECT_PROP_MESSAGE_BCC                           = 0xDD42u,
  USB_MTP_OBJECT_PROP_MESSAGE_READ                          = 0xDD43u,
  USB_MTP_OBJECT_PROP_MESSAGE_RECEIVED_TIME                 = 0xDD44u,
  USB_MTP_OBJECT_PROP_MESSAGE_SENDER                        = 0xDD45u,
  USB_MTP_OBJECT_PROP_ACTIVITY_BEGIN_TIME                   = 0xDD50u,
  USB_MTP_OBJECT_PROP_ACTIVITY_END_TIME                     = 0xDD51u,
  USB_MTP_OBJECT_PROP_ACTIVITY_LOCATION                     = 0xDD52u,
  USB_MTP_OBJECT_PROP_ACTIVITY_REQUIRED_ATTENDEES           = 0xDD54u,
  USB_MTP_OBJECT_PROP_ACTIVITY_OPTIONAL_ATTENDEES           = 0xDD55u,
  USB_MTP_OBJECT_PROP_ACTIVITY_RESOURCES                    = 0xDD56u,
  USB_MTP_OBJECT_PROP_ACTIVITY_ACCEPTED                     = 0xDD57u,
  USB_MTP_OBJECT_PROP_OWNER                                 = 0xDD5Du,
  USB_MTP_OBJECT_PROP_EDITOR                                = 0xDD5Eu,
  USB_MTP_OBJECT_PROP_WEBMASTER                             = 0xDD5Fu,
  USB_MTP_OBJECT_PROP_URL_SOURCE                            = 0xDD60u,
  USB_MTP_OBJECT_PROP_URL_DESTINATION                       = 0xDD61u,
  USB_MTP_OBJECT_PROP_TIME_BOOKMARK                         = 0xDD62u,
  USB_MTP_OBJECT_PROP_OBJECT_BOOKMARK                       = 0xDD63u,
  USB_MTP_OBJECT_PROP_BYTE_BOOKMARK                         = 0xDD64u,
  USB_MTP_OBJECT_PROP_LAST_BUILD_DATE                       = 0xDD70u,
  USB_MTP_OBJECT_PROP_TIME_TO_LIVE                          = 0xDD71u,
  USB_MTP_OBJECT_PROP_MEDIA_GUID                            = 0xDD72u
} USB_MTP_OBJECT_PROPERTIES;                                /*lint !e621 N:100 */

typedef enum _USB_MTP_DEVICE_PROPERTIES {
  USB_MTP_DEVICE_PROP_UNDEFINED                      = 0x5000u,
  USB_MTP_DEVICE_PROP_BATTERY_LEVEL                  = 0x5001u,
  USB_MTP_DEVICE_PROP_FUNCTIONAL_MODE                = 0x5002u,
  USB_MTP_DEVICE_PROP_IMAGE_SIZE                     = 0x5003u,
  USB_MTP_DEVICE_PROP_COMPRESSION_SETTING            = 0x5004u,
  USB_MTP_DEVICE_PROP_WHITE_BALANCE                  = 0x5005u,
  USB_MTP_DEVICE_PROP_RGB_GAIN                       = 0x5006u,
  USB_MTP_DEVICE_PROP_F_NUMBER                       = 0x5007u,
  USB_MTP_DEVICE_PROP_FOCAL_LENGTH                   = 0x5008u,
  USB_MTP_DEVICE_PROP_FOCUS_DISTANCE                 = 0x5009u,
  USB_MTP_DEVICE_PROP_FOCUS_MODE                     = 0x500Au,
  USB_MTP_DEVICE_PROP_EXPOSURE_METERING_MODE         = 0x500Bu,
  USB_MTP_DEVICE_PROP_FLASH_MODE                     = 0x500Cu,
  USB_MTP_DEVICE_PROP_EXPOSURE_TIME                  = 0x500Du,
  USB_MTP_DEVICE_PROP_EXPOSURE_PROGRAM_MODE          = 0x500Eu,
  USB_MTP_DEVICE_PROP_EXPOSURE_INDEX                 = 0x500Fu,
  USB_MTP_DEVICE_PROP_EXPOSURE_BIAS_COMPENSATION     = 0x5010u,
  USB_MTP_DEVICE_PROP_DATETIME                       = 0x5011u,
  USB_MTP_DEVICE_PROP_CAPTURE_DELAY                  = 0x5012u,
  USB_MTP_DEVICE_PROP_STILL_CAPTURE_MODE             = 0x5013u,
  USB_MTP_DEVICE_PROP_CONTRAST                       = 0x5014u,
  USB_MTP_DEVICE_PROP_SHARPNESS                      = 0x5015u,
  USB_MTP_DEVICE_PROP_DIGITAL_ZOOM                   = 0x5016u,
  USB_MTP_DEVICE_PROP_EFFECT_MODE                    = 0x5017u,
  USB_MTP_DEVICE_PROP_BURST_NUMBER                   = 0x5018u,
  USB_MTP_DEVICE_PROP_BURST_INTERVAL                 = 0x5019u,
  USB_MTP_DEVICE_PROP_TIMELAPSE_NUMBER               = 0x501Au,
  USB_MTP_DEVICE_PROP_TIMELAPSE_INTERVAL             = 0x501Bu,
  USB_MTP_DEVICE_PROP_FOCUS_METERING_MODE            = 0x501Cu,
  USB_MTP_DEVICE_PROP_UPLOAD_URL                     = 0x501Du,
  USB_MTP_DEVICE_PROP_ARTIST                         = 0x501Eu,
  USB_MTP_DEVICE_PROP_COPYRIGHT_INFO                 = 0x501Fu,
  USB_MTP_DEVICE_PROP_SYNCHRONIZATION_PARTNER        = 0xD401u,
  USB_MTP_DEVICE_PROP_DEVICE_FRIENDLY_NAME           = 0xD402u,
  USB_MTP_DEVICE_PROP_VOLUME                         = 0xD403u,
  USB_MTP_DEVICE_PROP_SUPPORTEDFORMATSORDERED        = 0xD404u,
  USB_MTP_DEVICE_PROP_DEVICEICON                     = 0xD405u,
  USB_MTP_DEVICE_PROP_PLAYBACK_RATE                  = 0xD410u,
  USB_MTP_DEVICE_PROP_PLAYBACK_OBJECT                = 0xD411u,
  USB_MTP_DEVICE_PROP_PLAYBACK_CONTAINER             = 0xD412u,
  USB_MTP_DEVICE_PROP_SESSION_INITIATOR_VERSION_INFO = 0xD406u,
  USB_MTP_DEVICE_PROP_PERCEIVED_DEVICE_TYPE          = 0xD407u
} USB_MTP_DEVICE_PROPERTIES;

typedef enum _USB_MTP_OPERATION_CODES {
  /*lint --e{621} N:100 */
  USB_MTP_OPERATION_GET_DEVICE_INFO              = 0x1001u,
  USB_MTP_OPERATION_OPEN_SESSION                 = 0x1002u,
  USB_MTP_OPERATION_CLOSE_SESSION                = 0x1003u,
  USB_MTP_OPERATION_GET_STORAGE_IDS              = 0x1004u,
  USB_MTP_OPERATION_GET_STORAGE_INFO             = 0x1005u,
  USB_MTP_OPERATION_GET_NUM_OBJECTS              = 0x1006u,
  USB_MTP_OPERATION_GET_OBJECT_HANDLES           = 0x1007u,
  USB_MTP_OPERATION_GET_OBJECT_INFO              = 0x1008u,
  USB_MTP_OPERATION_GET_OBJECT                   = 0x1009u,
  USB_MTP_OPERATION_GET_THUMB                    = 0x100Au,
  USB_MTP_OPERATION_DELETE_OBJECT                = 0x100Bu,
  USB_MTP_OPERATION_SEND_OBJECT_INFO             = 0x100Cu,
  USB_MTP_OPERATION_SEND_OBJECT                  = 0x100Du,
  USB_MTP_OPERATION_FORMAT_STORE                 = 0x100Fu,
  USB_MTP_OPERATION_RESET_DEVICE                 = 0x1010u,
  USB_MTP_OPERATION_GET_DEVICE_PROP_DESC         = 0x1014u,
  USB_MTP_OPERATION_GET_DEVICE_PROP_VALUE        = 0x1015u,
  USB_MTP_OPERATION_SET_DEVICE_PROP_VALUE        = 0x1016u,
  USB_MTP_OPERATION_RESET_DEVICE_PROP_VALUE      = 0x1017u,
  USB_MTP_OPERATION_TERMINATE_OPEN_CAPTURE       = 0x1018u,
  USB_MTP_OPERATION_MOVE_OBJECT                  = 0x1019u,
  USB_MTP_OPERATION_COPY_OBJECT                  = 0x101Au,
  USB_MTP_OPERATION_GET_PARTIAL_OBJECT           = 0x101Bu,
  USB_MTP_OPERATION_INITIATE_OPEN_CAPTURE        = 0x101Cu,
  USB_MTP_OPERATION_GET_OBJECT_PROPS_SUPPORTED   = 0x9801u,
  USB_MTP_OPERATION_GET_OBJECT_PROP_DESC         = 0x9802u,
  USB_MTP_OPERATION_GET_OBJECT_PROP_VALUE        = 0x9803u,
  USB_MTP_OPERATION_SET_OBJECT_PROP_VALUE        = 0x9804u,
  USB_MTP_OPERATION_GET_OBJECT_PROPLIST          = 0x9805u,
  USB_MTP_OPERATION_GETSERVICEIDS                = 0x9301u,
  USB_MTP_OPERATION_GETSERVICEINFO               = 0x9302u,
  USB_MTP_OPERATION_GETSERVICECAPABILITIES       = 0x9303u,
  USB_MTP_OPERATION_GETSERVICEPROPDESC           = 0x9304u,
  USB_MTP_OPERATION_GETSERVICEPROPLIST           = 0x9305u,
  USB_MTP_OPERATION_SETSERVICEPROPLIST           = 0x9306u,
  USB_MTP_OPERATION_UPDATEOBJECTPROPLIST         = 0x9307u,
  USB_MTP_OPERATION_DELETEOBJECTPROPLIST         = 0x9308u,
  USB_MTP_OPERATION_DELETESERVICEPROPLIST        = 0x9309u,
  USB_MTP_OPERATION_GETFORMATCAPABILITIES        = 0x930Au,
  USB_MTP_OPERATION_ANDROID_BEGIN_EDIT_OBJECT    = 0x95C4u, // Must be called before using SendPartialObject and TruncateObject
  USB_MTP_OPERATION_ANDROID_END_EDIT_OBJECT      = 0x95C5u, // Called to commit changes made by SendPartialObject and TruncateObject
  USB_MTP_OPERATION_ANDROID_GET_PARTIAL_OBJECT64 = 0x95C1u, // Same as GetPartialObject, but with 64 bit offset
  USB_MTP_OPERATION_ANDROID_SEND_PARTIAL_OBJECT  = 0x95C2u, // Same as GetPartialObject64, but copying host to device
  USB_MTP_OPERATION_ANDROID_TRUNCATE_OBJECT      = 0x95C3u, // Truncates file to 64 bit length
  USB_MTP_OPERATION_SEGGER_WRITE                 = 0x9750u, // Custom vendor command, transfers arbitrary data, data size specified by first command parameter; Host writes, device reads.
  USB_MTP_OPERATION_SEGGER_READ                  = 0x9751u  // Custom vendor command, transfers arbitrary data, data size specified by first command parameter; Host reads, device writes.
} USB_MTP_OPERATION_CODES;                       /*lint !e621 N:100 */

/*********************************************************************
*
*       Response codes
*/
typedef enum _USB_MTP_RESPONSE_CODES {
  /*lint --e{621} N:100 */
  USB_MTP_RESPONSE_OK                                     = 0x2001u,
  USB_MTP_RESPONSE_GENERAL_ERROR                          = 0x2002u,
  USB_MTP_RESPONSE_PARAMETER_NOT_SUPPORTED                = 0x2006u,
  USB_MTP_RESPONSE_INCOMPLETE_TRANSFER                    = 0x2007u,
  USB_MTP_RESPONSE_INVALID_STORAGE_ID                     = 0x2008u,
  USB_MTP_RESPONSE_INVALID_OBJECT_HANDLE                  = 0x2009u,
  USB_MTP_RESPONSE_DEVICEPROP_NOT_SUPPORTED               = 0x200Au,
  USB_MTP_RESPONSE_STORE_FULL                             = 0x200Cu,
  USB_MTP_RESPONSE_ACCESS_DENIED                          = 0x200Fu,
  USB_MTP_RESPONSE_NO_THUMBNAIL_PRESENT                   = 0x2010u,
  USB_MTP_RESPONSE_STORE_NOT_AVAILABLE                    = 0x2013u,
  USB_MTP_RESPONSE_SPECIFICATION_BY_FORMAT_NOT_SUPPORTED  = 0x2014u,
  USB_MTP_RESPONSE_NO_VALID_OBJECT_INFO                   = 0x2015u,
  USB_MTP_RESPONSE_DEVICE_BUSY                            = 0x2019u,
  USB_MTP_RESPONSE_INVALID_PARENT_OBJECT                  = 0x201Au,
  USB_MTP_RESPONSE_INVALID_PARAMETER                      = 0x201Du,
  USB_MTP_RESPONSE_SESSION_ALREADY_OPEN                   = 0x201Eu,
  USB_MTP_RESPONSE_TRANSACTION_CANCELLED                  = 0x201Fu,
  USB_MTP_RESPONSE_INVALID_OBJECT_PROP_CODE               = 0xA801u,
  USB_MTP_RESPONSE_INVALID_OBJECTPROP_FORMAT              = 0xA802u,
  USB_MTP_RESPONSE_INVALID_OBJECTPROP_VALUE               = 0xA803u,
  USB_MTP_RESPONSE_INVALID_OBJECTREFERENCE                = 0xA804u,
  USB_MTP_RESPONSE_INVALID_DATASET                        = 0xA806u,
  USB_MTP_RESPONSE_SPECIFICATION_BY_GROUP_UNSUPPORTED     = 0xA807u,
  USB_MTP_RESPONSE_SPECIFICATION_BY_DEPTH_UNSUPPORTED     = 0xA808u,
  USB_MTP_RESPONSE_OBJECT_TOO_LARGE                       = 0xA809u,
  USB_MTP_RESPONSE_OBJECT_PROP_NOT_SUPPORTED              = 0xA80Au,
  USB_MTP_RESPONSE_GROUP_NOT_SUPPORTED                    = 0xA805u
} USB_MTP_RESPONSE_CODES;                                 /*lint !e621 N:100 */

/*********************************************************************
*
*       Object format codes
*/
typedef enum _USB_MTP_OBJECT_FORMAT {
  /*lint --e{621} N:100 */
  USB_MTP_OBJECT_FORMAT_UNDEFINED             = 0x3000u,  // Undefined object
  USB_MTP_OBJECT_FORMAT_ASSOCIATION           = 0x3001u,  // Association (for example, a folder)
  USB_MTP_OBJECT_FORMAT_SCRIPT                = 0x3002u,  // Device model-specific script
  USB_MTP_OBJECT_FORMAT_EXECUTABLE            = 0x3003u,  // Device model-specific binary executable
  USB_MTP_OBJECT_FORMAT_TEXT                  = 0x3004u,  // Text file
  USB_MTP_OBJECT_FORMAT_HTML                  = 0x3005u,  // Hypertext Markup Language file (text)
  USB_MTP_OBJECT_FORMAT_DPOF                  = 0x3006u,  // Digital Print Order Format file (text)
  USB_MTP_OBJECT_FORMAT_AIFF                  = 0x3007u,  // Audio clip
  USB_MTP_OBJECT_FORMAT_WAV                   = 0x3008u,  // Audio clip
  USB_MTP_OBJECT_FORMAT_MP3                   = 0x3009u,  // Audio clip
  USB_MTP_OBJECT_FORMAT_AVI                   = 0x300Au,  // Video clip
  USB_MTP_OBJECT_FORMAT_MPEG                  = 0x300Bu,  // Video clip
  USB_MTP_OBJECT_FORMAT_ASF                   = 0x300Cu,  // Microsoft Advanced Streaming Format (video)
  USB_MTP_OBJECT_FORMAT_DEFINED               = 0x3800u,  // Unknown image object
  USB_MTP_OBJECT_FORMAT_EXIF_JPEG             = 0x3801u,  // Exchangeable File Format, JEIDA standard
  USB_MTP_OBJECT_FORMAT_TIFF_EP               = 0x3802u,  // Tag Image File Format for Electronic Photography
  USB_MTP_OBJECT_FORMAT_FLASHPIX              = 0x3803u,  // Structured Storage Image Format
  USB_MTP_OBJECT_FORMAT_BMP                   = 0x3804u,  // Microsoft Windows Bitmap file
  USB_MTP_OBJECT_FORMAT_CIFF                  = 0x3805u,  // Canon Camera Image File Format
  USB_MTP_OBJECT_FORMAT_UNDEFINED_RESERVED0   = 0x3806u,  // Reserved
  USB_MTP_OBJECT_FORMAT_GIF                   = 0x3807u,  // Graphics Interchange Format
  USB_MTP_OBJECT_FORMAT_JFIF                  = 0x3808u,  // JPEG File Interchange Format
  USB_MTP_OBJECT_FORMAT_CD                    = 0x3809u,  // PhotoCD Image Pac
  USB_MTP_OBJECT_FORMAT_PICT                  = 0x380Au,  // Quickdraw Image Format
  USB_MTP_OBJECT_FORMAT_PNG                   = 0x380Bu,  // Portable Network Graphics
  USB_MTP_OBJECT_FORMAT_UNDEFINED_RESERVED1   = 0x380Cu,  // Reserved
  USB_MTP_OBJECT_FORMAT_TIFF                  = 0x380Du,  // Tag Image File Format
  USB_MTP_OBJECT_FORMAT_TIFF_IT               = 0x380Eu,  // Tag Image File Format for Information Technology (graphic arts)
  USB_MTP_OBJECT_FORMAT_JP2                   = 0x380Fu,  // JPEG2000 Baseline File Format
  USB_MTP_OBJECT_FORMAT_JPX                   = 0x3810u,  // JPEG2000 Extended File Format
  USB_MTP_OBJECT_FORMAT_UNDEFINED_FIRMWARE    = 0xB802u,  //
  USB_MTP_OBJECT_FORMAT_WINDOWS_IMAGE_FORMAT  = 0xB881u,  //
  USB_MTP_OBJECT_FORMAT_UNDEFINED_AUDIO       = 0xB900u,  //
  USB_MTP_OBJECT_FORMAT_WMA                   = 0xB901u,  //
  USB_MTP_OBJECT_FORMAT_OGG                   = 0xB902u,  //
  USB_MTP_OBJECT_FORMAT_AAC                   = 0xB903u,  //
  USB_MTP_OBJECT_FORMAT_AUDIBLE               = 0xB904u,  //
  USB_MTP_OBJECT_FORMAT_FLAC                  = 0xB906u,  //
  USB_MTP_OBJECT_FORMAT_UNDEFINED_VIDEO       = 0xB980u,  //
  USB_MTP_OBJECT_FORMAT_WMV                   = 0xB981u,  //
  USB_MTP_OBJECT_FORMAT_MP4_CONTAINER         = 0xB982u,  // ISO 14496-1
  USB_MTP_OBJECT_FORMAT_MP2                   = 0xB983u,  //
  USB_MTP_OBJECT_FORMAT_3GP_CONTAINER         = 0xB984u   // 3GPP file format. http://www.3gpp.org/ftp/Specs/html-info/26244.htm
} USB_MTP_OBJECT_FORMAT;                      /*lint !e621 N:100 */

/*********************************************************************
*
*       USB_MTP_STORAGE_INIT
*
*  Description
*    Initializes the storage medium.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath    : Pointer to a USB_MTP_INST_DATA_DRIVER structure that contains all information
*                   that is necessary for the driver initialization. For detailed information
*                   about the USB_MTP_INST_DATA_DRIVER structure, refer to USB_MTP_INST_DATA_DRIVER.
*
*  Additional information
*    This function is called when the storage driver is added to emUSB-Device-MTP.
*    It is the first function of the storage driver to be called.
*/
typedef void (USB_MTP_STORAGE_INIT) (U8 Unit, const USB_MTP_INST_DATA_DRIVER * pDriverData);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_INFO
*
*  Description
*    Returns information about storage medium such as capacity and available free space.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pStorageInfo : Pointer to a USB_MTP_STORAGE_INFO structure. For detailed information about
*                   the USB_MTP_STORAGE_INFO structure, refer to USB_MTP_STORAGE_INFO.
*
*  Additional information
*    Typically, this function is called immediately after the device is connected
*    to USB host when the USB host requests information about the available storage mediums.
*/
typedef void (USB_MTP_STORAGE_GET_INFO) (U8 Unit, USB_MTP_STORAGE_INFO * pStorageInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_FIND_FIRST_FILE
*
*  Description
*    Returns information about the first file in a specified directory.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pDirPath     : Full path to the directory to be searched.
*    pFileInfo    : [OUT] Information about the file/directory found.
*
*  Return value
*    == 0: File/directory found
*    == 1: No more files/directories found
*     < 0: An error occurred
*
*  Additional information
*    The "." and ".." directory entries which are relevant only for the file system should be skipped.
*/
typedef int (USB_MTP_STORAGE_FIND_FIRST_FILE) (U8 Unit, const char * pDirPath, USB_MTP_FILE_INFO * pFileInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_FIND_NEXT_FILE
*
*  Description
*    Moves to next file and returns information about it.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pFileInfo    : [OUT] Information about the file/directory found.
*
*  Return value
*    == 0: File/directory found
*    == 1: No more files/directories found
*     < 0: An error occurred
*
*  Additional information
*    The "." and ".." directory entries which are relevant only for the file system should be skipped.
*/
typedef int (USB_MTP_STORAGE_FIND_NEXT_FILE) (U8 Unit, USB_MTP_FILE_INFO * pFileInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_OPEN_FILE
*
*  Description
*    Opens a file for reading.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath    : [IN] Full path to file.
*
*  Return value
*    == 0: File opened
*    != 0: An error occurred
*
*  Additional information
*    This function is called at the beginning of a file read operation.
*    It is followed by one or more calls to USB_MTP_STORAGE_READ_FROM_FILE.
*    At the end of data transfer the MTP module closes the file by calling USB_MTP_STORAGE_CLOSE_FILE.
*    If the file does not exists an error should be returned.
*    The MTP module opens only one file at a time.
*/
typedef int (USB_MTP_STORAGE_OPEN_FILE) (U8 Unit, const char * pFilePath);

/*********************************************************************
*
*       USB_MTP_STORAGE_CREATE_FILE
*
*  Description
*    Opens a file for writing.
*
*  Parameters
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pDirPath     : [IN] Full path to directory where the file should be created.
*    pFileInfo    : [IN] Information about the file to be created. pFileName points to the name of the file.
*                   [OUT] pFilePath points to full path of created file, pFileName points to the beginning of file name in pFilePath.
*
*  Return value
*    == 0: File created and opened
*    != 0: An error occurred
*
*  Additional information
*    This function is called at the beginning of a file write operation.
*    The name of the file is specified in the pFileName filed of pFileInfo.
*    If the file exists it should be truncated to zero length.
*    When a file is created, the call to USB_MTP_STORAGE_CREATE_FILE is followed
*    by one or more calls to USB_MTP_STORAGE_WRITE_TO_FILE.
*    If CreationTime and LastWriteTime in pFileInfo are not zero,
*    these should be used instead of the time stamps generated by the file system.
*/
typedef int (USB_MTP_STORAGE_CREATE_FILE) (U8 Unit, const char * pDirPath, USB_MTP_FILE_INFO * pFileInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_READ_FROM_FILE
*
*  Description
*    Reads data from the current file.
*
*  Parameters
*    Unit     : Logical unit number. Specifies for which storage medium the function is called.
*    Off      : Byte offset where to read from.
*    pData    : [OUT] Data read from file.
*    NumBytes : Number of bytes to read from file.
*
*  Return value
*    == 0: Data read from file
*    != 0: An error occurred
*
*  Additional information
*    The function reads data from the file opened by USB_MTP_STORAGE_OPEN_FILE.
*/
typedef int (USB_MTP_STORAGE_READ_FROM_FILE) (U8 Unit, U64 Off, void * pData, U32 NumBytes);

/*********************************************************************
*
*       USB_MTP_STORAGE_WRITE_TO_FILE
*
*  Description
*    Writes data to current file.
*
*  Parameters
*    Unit     : Logical unit number. Specifies for which storage medium the function is called.
*    Off      : Byte offset where to read from.
*    pData    : [IN] Data to write to file.
*    NumBytes : Number of bytes to write to file.
*
*  Return value
*    == 0: Data written to file
*    != 0: An error occurred
*
*  Additional information
*    The function writes data to file opened by USB_MTP_STORAGE_CREATE_FILE.
*/
typedef int (USB_MTP_STORAGE_WRITE_TO_FILE) (U8 Unit, U64 Off, const void * pData, U32 NumBytes);

/*********************************************************************
*
*       USB_MTP_STORAGE_CLOSE_FILE
*
*  Description
*    Closes the current file.
*
*  Parameters
*    Unit     : Logical unit number. Specifies for which storage medium the function is called.
*
*  Return value
*    == 0: File closed.
*    != 0: An error occurred
*
*  Additional information
*    The function closes the file opened by USB_MTP_STORAGE_CREATE_FILE or USB_MTP_STORAGE_OPEN_FILE.
*/
typedef int (USB_MTP_STORAGE_CLOSE_FILE) (U8 Unit);

/*********************************************************************
*
*       USB_MTP_STORAGE_REMOVE_FILE
*
*  Description
*    Removes a file/directory from the storage medium.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file/directory to be removed
*
*  Return value
*    == 0: File removed.
*    != 0: An error occurred
*/
typedef int (USB_MTP_STORAGE_REMOVE_FILE) (U8 Unit, const char * pFilePath);

/*********************************************************************
*
*       USB_MTP_STORAGE_CREATE_DIR
*
*  Description
*    Creates a directory on the storage medium.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pDirPath   : [IN] Full path to directory where the directory should be created.
*    pFileInfo  : [IN] Information about the directory to be created. pFileName points to the directory name.
*                 [OUT] pFilePath points to full path of directory, pFileName points to the beginning of directory name in pFilePath
*
*  Return value
*    == 0: Directory created.
*    != 0: An error occurred
*
*  Additional information
*    If CreationTime and LastWriteTime in pFileInfo are not available,
*    zero should be used instead of the time stamps generated by the file system.
*/
typedef int (USB_MTP_STORAGE_CREATE_DIR) (U8 Unit, const char * pDirPath, USB_MTP_FILE_INFO * pFileInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_REMOVE_DIR
*
*  Description
*    Removes a directory and its contents from the storage medium.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pDirPath   : [IN] Full path to directory to be removed.
*
*  Return value
*    == 0: Directory removed.
*    != 0: An error occurred
*
*  Additional information
*    The function should remove the directory and the entire file tree under it.
*/
typedef int (USB_MTP_STORAGE_REMOVE_DIR) (U8 Unit, const char * pDirPath);

/*********************************************************************
*
*       USB_MTP_STORAGE_FORMAT
*
*  Description
*    Initializes the storage medium.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*
*  Return value
*    == 0: Storage medium initialized.
*    != 0: An error occurred
*
*  Additional information
*    The file system layer has to differentiate between two cases,
*    one where the MTP root directory is the same as the root directory
*    of the file system and one where it is only a subdirectory of
*    the file system. If pRootDir which was configured in the call
*    to USB_MTP_STORAGE_INIT, points to a subdirectory of the file system,
*    the storage medium should not be formatted.
*    Instead, all the files and directories underneath pRootDir should be removed.
*/
typedef int (USB_MTP_STORAGE_FORMAT) (U8 Unit);

/*********************************************************************
*
*       USB_MTP_STORAGE_RENAME_FILE
*
*  Description
*    Changes the name of a file or directory.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFileInfo  : Pointer to a USB_MTP_FILE_INFO structure.
*                 [IN] Information about the file/directory to be renamed.
*                 pFilePath member points to the full path and pFileName points to the new name.
*                 [OUT] pFilePath member points to full path of file/directory with the new name,
*                 pFileName points to the beginning of file/directory name in pFilePath.
*                 The other structure fields should also be filled.
*
*  Return value
*    == 0: File/directory renamed.
*    != 0: An error occurred
*
*  Additional information
*    Only the name of the file/directory should be changed.
*    The path to parent directory should remain the same.
*/
typedef int (USB_MTP_STORAGE_RENAME_FILE) (U8 Unit, USB_MTP_FILE_INFO * pFileInfo);

/*********************************************************************
*
*       USB_MTP_STORAGE_DEINIT
*
*  Description
*    De-initializes the storage medium.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*
*  Additional information
*    Typically called when the application calls USBD_Stop()
*    to de-initialize emUSB-Device.
*/
typedef void (USB_MTP_STORAGE_DEINIT) (U8 Unit);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILE_ATTRIBUTES
*
*  Description
*    Returns the attributes of a file or directory.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    pMask      : [OUT] The bitmask of the attributes.
*
*  Return value
*    == 0: Information returned.
*    != 0: An error occurred
*
*  Additional information
*    This function is called only when the compile time switch MTP_SAVE_FILE_INFO is set to 0.
*    For the list of supported attributes refer to USB_MTP_FILE_INFO.
*/
typedef int (USB_MTP_STORAGE_GET_FILE_ATTRIBUTES) (U8 Unit, const char * pFilePath, U8 * pMask);

/*********************************************************************
*
*       USB_MTP_STORAGE_MODIFY_FILE_ATTRIBUTES
*
*  Description
*    Sets and clears file attributes.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    SetMask    : The bitmask of the attributes which should be set.
*    ClrMask    : The bitmask of the attributes which should be cleared.
*
*  Return value
*    == 0: Attributes modified.
*    != 0: An error occurred
*
*  Additional information
*    For the list of supported attributes refer to USB_MTP_FILE_INFO.
*/
typedef int (USB_MTP_STORAGE_MODIFY_FILE_ATTRIBUTES) (U8 Unit, const char * pFilePath, U8 SetMask, U8 ClrMask);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILE_CREATION_TIME
*
*  Description
*    Returns the creation time of file or directory.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    pTime      : [OUT] The creation time.
*
*  Return value
*    == 0: Creation time returned.
*    != 0: An error occurred
*
*  Additional information
*    This function is called only when the compile time switch MTP_SAVE_FILE_INFO is set to 0.
*    For the list of supported attributes refer to USB_MTP_FILE_INFO.
*/
typedef int (USB_MTP_STORAGE_GET_FILE_CREATION_TIME) (U8 Unit, const char * pFilePath, U32 * pTime);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILELAST_WRITE_TIME
*
*  Description
*    Returns the time when the file or directory was last modified.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    pTime      : [OUT] The modification time.
*
*  Return value
*    == 0: Modification time returned.
*    != 0: An error occurred
*
*  Additional information
*    This function is called only when the compile time switch MTP_SAVE_FILE_INFO is set to 0.
*    For the list of supported attributes refer to USB_MTP_FILE_INFO.
*/
typedef int (USB_MTP_STORAGE_GET_FILELAST_WRITE_TIME) (U8 Unit, const char * pFilePath, U32 * pTime);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILE_ID
*
*  Description
*    Returns an ID which uniquely identifies the file or directory.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    pId        : [OUT] The unique ID of file or directory.
*                 Should point to a byte array MTP_NUM_BYTES_FILE_ID large.
*
*  Return value
*    == 0: ID returned.
*    != 0: An error occurred
*/
typedef int (USB_MTP_STORAGE_GET_FILE_ID) (U8 Unit, const char * pFilePath, U8  * pId);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILE_SIZE
*
*  Description
*    Returns the size of a file in bytes.
*
*  Parameters
*    Unit       : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath  : Full path to file or directory (0-terminated string).
*    pFileSize  : [OUT] The size of file in bytes.
*
*  Return value
*    == 0: Size of file returned.
*    != 0: An error occurred
*
*  Additional information
*    This function is called only when the compile time switch MTP_SAVE_FILE_INFO is set to 0.
*/
typedef int (USB_MTP_STORAGE_GET_FILE_SIZE) (U8 Unit, const char * pFilePath, U64 * pFileSize);

/*********************************************************************
*
*       USB_MTP_STORAGE_GET_FILE_INFO
*
*  Description
*    This function is optional. It is used to speed up retrieval of file information.
*    Returns the creation time, modification time and attributes in one call.
*
*  Parameters
*    Unit           : Logical unit number. Specifies for which storage medium the function is called.
*    pFilePath      : Path to file or directory.
*    pCreationTime  : [OUT] The creation time.
*    pLastWriteTime : [OUT] The modification time.
*    pAttributes    : [OUT] The size of file in bytes.
*
*  Return value
*    == 0: Operation retrieved information successfully.
*    != 0: An error occurred
*
*  Additional information
*    This function is called only when the compile time switch MTP_SAVE_FILE_INFO is set to 0.
*/
typedef int (USB_MTP_STORAGE_GET_FILE_INFO) (U8 Unit, const char * pFilePath, U32 * pCreationTime, U32 * pLastWriteTime, U64 * pFileSize, U8 * pAttributes);

/*********************************************************************
*
*       USB_MTP_OBJECT_ALLOC_FAIL
*
*  Description
*    Callback which can be set via USBD_MTP_SetObjectAllocFailCb().
*    This callback is called when the object list runs out of memory for new objects.
*    It can be used to notify the user of the issue (e.g. set an error LED).
*
*  Parameters
*    NumBytesRequested: Bytes need for a new object.
*    NumBytesAvail    : Bytes free in the object list.
*    pFilePath        : Pointer to a string containing the file path.
*    pFileName        : Pointer to a string containing the file name.
*
*  Additional information
*    This callback is informative only, the application must not try to free the object list.
*    This callback is called for every object where allocation failed.
*    The callback may not block.
*    When this callback is set the behavior of the MTP module is changed slightly -
*    new objects are normally allocated for each file/dir in a directory which is
*    opened by the user in the PC's explorer. When this callback is not set once
*    a single allocation fails the module will return an error to the PC even if
*    some objects inside a folder could be allocated.
*    When this callback is set the module will return as many objects as it could
*    fit into the object list before allocating started failing (e.g. if a folder
*    contains 50 files and allocation starts failing after 40 files the MTP module
*    will return the first 40 objects to the PC).
*/
typedef void (USB_MTP_OBJECT_ALLOC_FAIL) (U32 NumBytesRequested, U32 NumBytesAvail, const char * pFilePath, const char * pFileName);

/*********************************************************************
*
*       USB_MTP_WP_CB
*
*  Description
*    Callback which can be set via USBD_MTP_SetWriteProtectionCb().
*    This optional callback will be called on all write operations (write, rename, create, delete, modify)
*    and allows the application to prevent the operation for selected files.
*    E.g. prevent a certain file from being deleted or modified by the host.
*
*  Parameters
*    OperationType: One of the USB_MTP_STORAGE_CB_TYPE enum values.
*    Unit         : Logical unit number. Specifies for which storage medium the function is called.
*    pPath        : Pointer to a string containing the full file/directory path.
*
*  Return value
*    == 0: Proceed with operation.
*    != 0: Prevent operation, an error will be sent to the host.
*
*  Additional information
*    The callback may not block.
*    It is advised to use MTP_STORAGE_PROTECT_FORMAT for the volume
*    on which the file is located, otherwise it can be deleted
*    if the user formats the volume.
*/
typedef int (USB_MTP_WP_CB) (USB_MTP_STORAGE_CB_TYPE OperationType, U8 Unit, const char * pPath);

/*********************************************************************
*
*       USB_MTP_OPERATION_CB
*
*  Description
*    Callback which can be set via USBD_MTP_SetOperationCb().
*    This callback is called when operations are executed by the host
*    operating system via MTP.
*    This can be used to e.g. monitor new objects being created.
*
*  Parameters
*    OperationType: One of the USB_MTP_OPERATION_CB_TYPE enum values.
*    pFileInfo    : Pointer to a USB_MTP_OPERATION_INFO structure containing information about the affected file.
*/
#if USB_MTP_SUPPORT_OPERATION_CB
typedef void (USB_MTP_OPERATION_CB) (USB_MTP_OPERATION_CB_TYPE OperationType, const USB_MTP_OPERATION_INFO * pOpInfo);
#endif

/*********************************************************************
*
*       USB_MTP_STORAGE_API
*
*  Description
*    Structure that contains callbacks to the storage driver.
*/
typedef struct USB_MTP_STORAGE_API {
  USB_MTP_STORAGE_INIT                    * pfInit;                 // Initializes the storage medium.
  USB_MTP_STORAGE_GET_INFO                * pfGetInfo;              // Returns information about the storage medium such as storage capacity
                                                                    // and the available free space.
  USB_MTP_STORAGE_FIND_FIRST_FILE         * pfFindFirstFile;        // Returns information about the first file in a given directory.
  USB_MTP_STORAGE_FIND_NEXT_FILE          * pfFindNextFile;         // Moves to next file and returns information about it.
  USB_MTP_STORAGE_OPEN_FILE               * pfOpenFile;             // Opens an existing file.
  USB_MTP_STORAGE_CREATE_FILE             * pfCreateFile;           // Creates a new file.
  USB_MTP_STORAGE_READ_FROM_FILE          * pfReadFromFile;         // Reads data from the current file.
  USB_MTP_STORAGE_WRITE_TO_FILE           * pfWriteToFile;          // Writes data to current file.
  USB_MTP_STORAGE_CLOSE_FILE              * pfCloseFile;            // Closes the current file.
  USB_MTP_STORAGE_REMOVE_FILE             * pfRemoveFile;           // Removes a file from storage medium.
  USB_MTP_STORAGE_CREATE_DIR              * pfCreateDir;            // Creates a new directory.
  USB_MTP_STORAGE_REMOVE_DIR              * pfRemoveDir;            // Removes a directory from storage medium.
  USB_MTP_STORAGE_FORMAT                  * pfFormat;               // Formats the storage.
  USB_MTP_STORAGE_RENAME_FILE             * pfRenameFile;           // Changes the name of a file or directory.
  USB_MTP_STORAGE_DEINIT                  * pfDeInit;               // De-initializes the storage medium.
  USB_MTP_STORAGE_GET_FILE_ATTRIBUTES     * pfGetFileAttributes;    // Reads the attributes of a file or directory.
  USB_MTP_STORAGE_MODIFY_FILE_ATTRIBUTES  * pfModifyFileAttributes; // Changes the attributes of a file or directory.
  USB_MTP_STORAGE_GET_FILE_CREATION_TIME  * pfGetFileCreationTime;  // Returns the creation time of a file or directory.
  USB_MTP_STORAGE_GET_FILELAST_WRITE_TIME * pfGetFileLastWriteTime; // Returns the time of the last modification made to a file or directory.
  USB_MTP_STORAGE_GET_FILE_ID             * pfGetFileId;            // Returns the unique ID of a file or directory.
  USB_MTP_STORAGE_GET_FILE_SIZE           * pfGetFileSize;          // Returns the size of a file in bytes.
  USB_MTP_STORAGE_GET_FILE_INFO           * pfGetFileInfo;          // [Optional] Returns information about a file.
} USB_MTP_STORAGE_API;

/*********************************************************************
*
*       USB_MTP_INST_DATA
*
*  Description
*    Structure which stores the parameters of storage driver.
*
*  Additional information
*    The MTP device returns the sDescription string in the Storage
*    Description parameter and the sVolumeId in the Volume Identifier
*    of the StorageInfo dataset. For more information, refer to MTP specification.
*/
typedef struct USB_MTP_INST_DATA {
  const USB_MTP_STORAGE_API * pAPI;         // Pointer to a structure that holds the storage device driver API.
  const char                * sDescription; // Human-readable string which identifies the storage.
                                            // This string is displayed in Nautilus/Windows Explorer/etc.
  const char                * sVolumeId;    // Unique volume identifier
                                            // This field must be up to 256 characters long but only the
                                            // first 128 are significant and these must be unique for all
                                            // storages of an MTP device.
  USB_MTP_INST_DATA_DRIVER    DriverData;   // Driver data that are passed to the storage driver.
                                            // Refer to USB_MTP_INST_DATA_DRIVER for detailed information
                                            // about how to initialize this structure.
} USB_MTP_INST_DATA;

/*********************************************************************
*
*       USB_MTP_INFO
*
*  Description
*    Structure that is used when initialising the MTP module.
*/
typedef struct USB_MTP_INFO {
  const char * pManufacturer; // Name of the device manufacturer.
  const char * pModel;        // Model name of the MTP device.
  const char * pDeviceVersion;// Version of the MTP device.
  const char * pSerialNumber; // Serial number of the MTP device.
                              // The serial number should contain exactly
                              // 32 hexadecimal characters.
                              // It must be unique among devices sharing
                              // the same model name and device version
                              // strings. The MTP device returns this
                              // string in the Serial Number field of
                              // the DeviceInfo dataset. For more
                              // information, refer to MTP specification.
} USB_MTP_INFO;

/*********************************************************************
*
*       USB_MTP_INIT_DATA
*
*  Description
*    Structure which stores the parameters of the MTP interface.
*
*  Additional information
*    This structure holds the endpoints that should be used with the
*    MTP interface. Refer to USBD_AddEP() for more information about
*    how to add an endpoint.
*
*    The number of bytes in the pDataBuffer should be a multiple of USB
*    maximum packet size. The number of bytes in the object list depends
*    on the number of files/directories on the storage medium. An object
*    is assigned to each file/directory when the USB host requests
*    the object information for the first time.
*/
typedef struct {                  // NOLINT(clang-analyzer-optin.performance.Padding)
  U8     EPIn;                    // Endpoint for receiving data from host.
  U8     EPOut;                   // Endpoint for sending data to host.
  U8     EPInt;                   // Endpoint for sending events to host.
  void * pObjectList;             // Pointer to a memory region where the list of MTP objects is stored. Should be 4 byte aligned.
                                  // Each object requires a minimum of 12 bytes + the size of the file name inside the this list.
                                  // 33 more bytes are needed per object if MTP_SAVE_FILE_INFO is set to 1.
  U32    NumBytesObjectList;      // Number of bytes allocated for the object list.
  void * pDataBuffer;             // Pointer to a memory region to be used as communication buffer.
  U32    NumBytesDataBuffer;      // Number of bytes allocated for the data buffer.
  const USB_MTP_INFO * pMTPInfo;  // Pointer to a USB_MTP_INFO structure. Filling this structure is mandatory.
  //
  // The following fields are used internally by the MTP component.
  //
  U8     InterfaceNum;
  U32    NumBytesAllocated;
  U32    NumObjects;
} USB_MTP_INIT_DATA;

/*********************************************************************
*
*       USB_MTP_STORAGE_HANDLE
*/
typedef U32 USB_MTP_STORAGE_HANDLE;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
void                    USBD_MTP_Init                 (void);
int                     USBD_MTP_Add                  (const USB_MTP_INIT_DATA * pInitData);
USB_MTP_STORAGE_HANDLE  USBD_MTP_AddStorage           (const USB_MTP_INST_DATA * pInstData);
int                     USBD_MTP_RemoveStorage        (USB_MTP_STORAGE_HANDLE hStorage);
int                     USBD_MTP_Poll                 (void);
void                    USBD_MTP_Task                 (void);
int                     USBD_MTP_SendEvent            (USB_MTP_STORAGE_HANDLE hStorage, USB_MTP_EVENT Event, void * pPara);
void                    USBD_MTP_SetObjectAllocFailCb (USB_MTP_OBJECT_ALLOC_FAIL * pf);
void                    USBD_MTP_SetWriteProtectionCb (USB_MTP_WP_CB * pf);
#if USB_MTP_SUPPORT_OPERATION_CB
void                    USBD_MTP_SetOperationCb       (USB_MTP_OPERATION_CB * pf);
#endif

/*********************************************************************
*
*       Wrapper for emUSB V2 migration
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_API > 0
#define  USB_MTP_Init              USBD_MTP_Init
#define  USB_MTP_Add               USBD_MTP_Add
#define  USB_MTP_AddStorage        USBD_MTP_AddStorage
#define  USB_MTP_Task              USBD_MTP_Task
#define  USB_MTP_SendEvent         USBD_MTP_SendEvent
#endif

/*********************************************************************
*
*       Functions defined in the application
*
**********************************************************************
*/
#if USB_V2_V3_MIGRATION_MTP_INFO > 0
const char * USB_MTP_GetManufacturer (void);
const char * USB_MTP_GetModel        (void);
const char * USB_MTP_GetDeviceVersion(void);
const char * USB_MTP_GetSerialNumber (void);
#endif

/*********************************************************************
*
*       Storage drivers
*
**********************************************************************
*/
extern const USB_MTP_STORAGE_API USB_MTP_StorageFS;
extern const USB_MTP_STORAGE_API USB_MTP_StorageFS_BIGFAT;

/*********************************************************************
*
*       Custom commands
*
**********************************************************************
*/
#ifdef USB_MTP_SUPPORT_SEGGER_CMD
typedef void USB_MTP_SEGGER_WRITE(U32 TransactionId, U32 NumBytesRemaining, U32 * pNumBytesToSend, U8 ** pData);
typedef void USB_MTP_SEGGER_READ(U32 TransactionId, U32 NumBytesRemaining, U32 NumBytesInBuffer, U8 * pData);
void USBD_MTP_SetReadCallback  (USB_MTP_SEGGER_READ * pfRead);
void USBD_MTP_SetWriteCallback (USB_MTP_SEGGER_WRITE * pfWrite);
#endif
void USBD_MTP_PrintObjectList(void);

#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/
