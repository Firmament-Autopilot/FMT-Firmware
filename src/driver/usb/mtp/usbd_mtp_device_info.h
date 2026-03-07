/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef USB_MTP_DEVICE_INFO_H
#define USB_MTP_DEVICE_INFO_H
#include <stdint.h>
#include "driver/usb/mtp/usb_mtp.h"

static const uint16_t VendExtDesc[] = { 'm', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', '.', 'c', 'o', 'm', ':', ' ', '1', '.', '0', ';', ' ', 0 }; /* last 2 bytes must be 0*/

// static const uint16_t SuppOP[] = { MTP_OP_GET_DEVICE_INFO, MTP_OP_OPEN_SESSION, MTP_OP_CLOSE_SESSION,
//                                    MTP_OP_GET_STORAGE_IDS, MTP_OP_GET_STORAGE_INFO, MTP_OP_GET_NUM_OBJECTS,
//                                    MTP_OP_GET_OBJECT_HANDLES, MTP_OP_GET_OBJECT_INFO, MTP_OP_GET_OBJECT,
//                                    MTP_OP_DELETE_OBJECT, MTP_OP_SEND_OBJECT_INFO, MTP_OP_SEND_OBJECT,
//                                    MTP_OP_GET_DEVICE_PROP_DESC, MTP_OP_GET_OBJECT_PROPS_SUPPORTED
//                                    };
//                                    /* MTP_OP_GET_OBJECT_PROPLIST，MTP_OP_GET_OBJECT_PROP_DESC,
//                                     MTP_OP_GET_DEVICE_PROP_VALUE，
//                                     MTP_OP_SET_OBJECT_PROP_VALUE，MTP_OP_GET_OBJECT_PROP_VALUE
//                                     MTP_OP_GET_OBJECT_PROP_REFERENCES，*/
// static const uint16_t SuppEvents[] = { MTP_EVENT_OBJECTADDED };

// static const uint16_t DevicePropSupp[] = { MTP_DEV_PROP_DEVICE_FRIENDLY_NAME, MTP_DEV_PROP_BATTERY_LEVEL };

// static const uint16_t SuppCaptFormat[] = { MTP_OBJ_FORMAT_UNDEFINED, MTP_OBJ_FORMAT_ASSOCIATION, MTP_OBJ_FORMAT_TEXT };

// static const uint16_t SuppImgFormat[] = { MTP_OBJ_FORMAT_UNDEFINED, MTP_OBJ_FORMAT_TEXT, MTP_OBJ_FORMAT_ASSOCIATION,
//                                           MTP_OBJ_FORMAT_EXECUTABLE, MTP_OBJ_FORMAT_WAV, MTP_OBJ_FORMAT_MP3,
//                                           MTP_OBJ_FORMAT_EXIF_JPEG, MTP_OBJ_FORMAT_MPEG, MTP_OBJ_FORMAT_MP4_CONTAINER,
//                                           MTP_OBJ_FORMAT_WINDOWS_IMAGE_FORMAT, MTP_OBJ_FORMAT_PNG, MTP_OBJ_FORMAT_WMA,
//                                           MTP_OBJ_FORMAT_WMV };

static const uint16_t Manuf[] = { 'F', 'i', 'r', 'm', 'a', 'm', 'e', 'n', 't', 0 }; /* last 2 bytes must be 0*/
static const uint16_t Model[] = { 'F', 'i', 'r', 'm', 'a', 'm', 'e', 'n', 't', 0 }; /* last 2 bytes must be 0*/
static const uint16_t DeviceVers[] = { 'V', '1', '.', '0', '0', 0 };                /* last 2 bytes must be 0*/
/*SerialNbr shall be 32 character hexadecimal string for legacy compatibility reasons */
static const uint16_t SerialNbr[] = { '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0',
                                      '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0',
                                      '0', '1', '0', '0', 0 }; /* last 2 bytes must be 0*/

static const uint16_t DefaultFileName[] = { 'N', 'e', 'w', ' ', 'F', 'o', 'l', 'd', 'e', 'r', 0 };

static const uint16_t DevicePropDefVal[] = { 'F', 'M', 'T', ' ', 'D', 'e', 'v', 'i', 'c', 'e', 0 };
static const uint16_t DevicePropCurDefVal[] = { 'F', 'M', 'T', ' ', 'D', 'e', 'v', 'i', 'c', 'e', 0 };

/* required for all object format : storageID, objectFormat, ObjectCompressedSize,
persistent unique object identifier, name*/
// static const uint16_t ObjectPropCode[] = { MTP_OB_PROP_STORAGE_ID, MTP_OB_PROP_OBJECT_FORMAT, MTP_OB_PROP_OBJECT_SIZE,
//                                            MTP_OB_PROP_OBJ_FILE_NAME, MTP_OB_PROP_PARENT_OBJECT, MTP_OB_PROP_NAME,
//                                            MTP_OB_PROP_PERS_UNIQ_OBJ_IDEN, MTP_OB_PROP_PROTECTION_STATUS,
//                                            MTP_OB_PROP_DISPLAY_NAME};

#define MTP_STORAGE_ID 0x00010001U /* SD card is inserted*/
#define MTP_STORAGE_IDS           1

/**
 * Write 8/16/32/64/128-bit little-endian values into buffer.
 * Macro-based for inline efficiency without large stack allocation.
 */
#define PUT_U8_AT(buf, x)  do { (buf)[0] = (uint8_t)(x); (buf) += 1; } while (0)
#define PUT_U16_AT(buf, x) do { uint16_t _v = (uint16_t)(x); memcpy(buf, &_v, 2); (buf) += 2; } while (0)
#define PUT_U32_AT(buf, x) do { uint32_t _v = (uint32_t)(x); memcpy(buf, &_v, 4); (buf) += 4; } while (0)
#define PUT_U64_AT(buf, x) do { uint64_t _v = (uint64_t)(x); memcpy(buf, &_v, 8); (buf) += 8; } while (0)
#define PUT_STRING_AT(buf, str, len) do { PUT_U8_AT(buf, len);\
                                        for (uint16_t i = 0; i < len; i++) { \
                                            PUT_U16_AT(buf, (uint16_t)str[i]); \
                                        } \
                                     } while (0)

#define GET_U8_AT(buf)  ({ uint8_t _v = *(uint8_t *)(buf); (buf) += 1; _v;})
#define GET_U16_AT(buf) ({ uint16_t _v; memcpy(&_v, buf, 2); (buf) += 2; _v;})
#define GET_U32_AT(buf) ({ uint32_t _v; memcpy(&_v, buf, 4); (buf) += 4; _v;})
#define GET_U64_AT(buf) ({ uint64_t _v; memcpy(&_v, buf, 8); (buf) += 8; _v;})
#define GET_STRING_AT(buf, str) \
    do { uint8_t *_str = (uint8_t *)str;\
        uint8_t _str_len = GET_U8_AT(buf); \
        for (uint16_t i = 0; i < _str_len; i++) { \
            uint16_t str_src = GET_U16_AT(buf); \
            if (_str != NULL) { _str[i] = (uint8_t)str_src; } \
        } \
    } while (0)

struct mtp_object_handle {
    uint32_t ObjectHandle_len;
    uint32_t ObjectHandle[CONFIG_USBDEV_MTP_MAX_OBJECTS];
} __PACKED;

#endif