/******************************************************************************
 * Copyright 2020-2024 The Firmament Authors. All Rights Reserved.
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

#include "param_fram.h"
#include "param.h"
#include <string.h>

#define TAG "ParamFRAM"

#pragma pack(1)
/* FRAM parameter header structure */
typedef struct {
    uint32_t magic;         /* Magic number: "FMTP" (0x464D5450) */
    uint16_t version;       /* Parameter format version */
    uint16_t param_count;   /* Total number of parameters */
    uint32_t data_size;     /* Size of parameter data in bytes */
    uint32_t data_crc;      /* CRC32 of parameter data */
    uint32_t header_crc;    /* CRC32 of header (excluding this field) */
} fram_param_header_t;
#pragma pack()

#define FRAM_HEADER_SIZE    sizeof(fram_param_header_t)
#define FRAM_DATA_OFFSET    512   /* Start data from sector 1 (sector 0 for header) */

/* CRC32 calculation (simple implementation) */
static uint32_t crc32_calculate(const uint8_t* data, uint32_t length)
{
    uint32_t crc = 0xFFFFFFFF;
    
    for (uint32_t i = 0; i < length; i++) {
        crc ^= data[i];
        for (uint32_t j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc = crc >> 1;
            }
        }
    }
    
    return ~crc;
}

/* Pack all parameters into binary buffer */
static uint32_t pack_parameters(uint8_t* buffer, uint32_t buffer_size)
{
    param_group_t* param_table = param_get_table();
    uint32_t offset = 0;
    uint16_t total_params = 0;
    
    if (param_table == NULL) {
        return 0;
    }
    
    /* Get total parameter count */
    for (int i = 0; i < param_get_group_count(); i++) {
        total_params += param_table[i].param_num;
    }
    
    /* Pack each parameter: [type(1)] [name_len(1)] [name] [data] */
    for (int i = 0; i < param_get_group_count(); i++) {
        param_t* p = param_table[i].param_list;
        
        for (int j = 0; j < param_table[i].param_num; j++) {
            uint8_t name_len = strlen(p->name);
            uint8_t data_size = 0;
            
            /* Calculate data size based on type */
            switch (p->type) {
                case PARAM_TYPE_INT8:
                case PARAM_TYPE_UINT8:
                    data_size = 1;
                    break;
                case PARAM_TYPE_INT16:
                case PARAM_TYPE_UINT16:
                    data_size = 2;
                    break;
                case PARAM_TYPE_INT32:
                case PARAM_TYPE_UINT32:
                case PARAM_TYPE_FLOAT:
                    data_size = 4;
                    break;
                case PARAM_TYPE_DOUBLE:
                    data_size = 8;
                    break;
                default:
                    continue;  /* Skip unknown types */
            }
            
            /* Check buffer space */
            if (offset + 2 + name_len + data_size > buffer_size) {
                console_printf("FRAM buffer overflow!\n");
                return 0;
            }
            
            /* Pack: type, name_len, name, data */
            buffer[offset++] = (uint8_t)p->type;
            buffer[offset++] = name_len;
            memcpy(&buffer[offset], p->name, name_len);
            offset += name_len;
            memcpy(&buffer[offset], &p->val, data_size);
            offset += data_size;
            
            p++;
        }
    }
    
    return offset;
}

/* Unpack parameters from binary buffer */
static fmt_err_t unpack_parameters(const uint8_t* buffer, uint32_t data_size)
{
    uint32_t offset = 0;
    
    while (offset < data_size) {
        /* Read type and name length */
        if (offset + 2 > data_size) break;
        
        uint8_t type = buffer[offset++];
        uint8_t name_len = buffer[offset++];
        
        if (name_len == 0 || offset + name_len > data_size) break;
        
        /* Read parameter name */
        char name[50];
        if (name_len >= sizeof(name)) {
            console_printf("Parameter name too long\n");
            return FMT_ERROR;
        }
        memcpy(name, &buffer[offset], name_len);
        name[name_len] = '\0';
        offset += name_len;
        
        /* Find parameter by name */
        param_t* param = param_get_by_name(name);
        if (param == NULL) {
            /* Skip unknown parameter */
            uint8_t data_size = 0;
            switch ((param_type_t)type) {
                case PARAM_TYPE_INT8:
                case PARAM_TYPE_UINT8:
                    data_size = 1; break;
                case PARAM_TYPE_INT16:
                case PARAM_TYPE_UINT16:
                    data_size = 2; break;
                case PARAM_TYPE_INT32:
                case PARAM_TYPE_UINT32:
                case PARAM_TYPE_FLOAT:
                    data_size = 4; break;
                case PARAM_TYPE_DOUBLE:
                    data_size = 8; break;
                default:
                    console_printf("Unknown param type: %d\n", type);
                    return FMT_ERROR;
            }
            offset += data_size;
            continue;
        }
        
        /* Verify type matches */
        if (param->type != (param_type_t)type) {
            console_printf("Parameter type mismatch: %s\n", name);
            return FMT_ERROR;
        }
        
        /* Load parameter value */
        uint8_t data_size = 0;
        switch (param->type) {
            case PARAM_TYPE_INT8:
            case PARAM_TYPE_UINT8:
                data_size = 1;
                break;
            case PARAM_TYPE_INT16:
            case PARAM_TYPE_UINT16:
                data_size = 2;
                break;
            case PARAM_TYPE_INT32:
            case PARAM_TYPE_UINT32:
            case PARAM_TYPE_FLOAT:
                data_size = 4;
                break;
            case PARAM_TYPE_DOUBLE:
                data_size = 8;
                break;
        }
        
        if (offset + data_size > data_size) {
            console_printf("Data overflow\n");
            return FMT_ERROR;
        }
        
        memcpy(&param->val, &buffer[offset], data_size);
        offset += data_size;
    }
    
    return FMT_EOK;
}

/**
 * @brief Save parameters to FRAM
 */
fmt_err_t param_fram_save(void)
{
    rt_device_t mtd_dev;
    fram_param_header_t header;
    uint8_t* data_buffer = NULL;
    uint32_t data_size;
    fmt_err_t res = FMT_ERROR;
    
    /* Open FRAM MTD device */
    mtd_dev = rt_device_find(FRAM_MTD_DEVICE_NAME);
    if (mtd_dev == RT_NULL) {
        console_printf("FRAM device %s not found\n", FRAM_MTD_DEVICE_NAME);
        return FMT_ERROR;
    }
    
    if (rt_device_open(mtd_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        console_printf("Failed to open FRAM device\n");
        return FMT_ERROR;
    }
    
    /* Allocate buffer for parameter data (max 30KB) */
    data_buffer = (uint8_t*)rt_malloc(30 * 1024);
    if (data_buffer == NULL) {
        console_printf("Failed to allocate FRAM buffer\n");
        goto cleanup;
    }
    
    /* Pack parameters into buffer */
    data_size = pack_parameters(data_buffer, 30 * 1024);
    if (data_size == 0) {
        console_printf("Failed to pack parameters\n");
        goto cleanup;
    }
    
    /* Prepare header */
    rt_memset(&header, 0, sizeof(header));
    header.magic = FRAM_PARAM_MAGIC;
    header.version = FRAM_PARAM_VERSION;
    header.param_count = 0;  /* Can be calculated if needed */
    header.data_size = data_size;
    header.data_crc = crc32_calculate(data_buffer, data_size);
    header.header_crc = crc32_calculate((uint8_t*)&header, 
                                        sizeof(header) - sizeof(header.header_crc));
    
    /* Write header to sector 0 */
    uint8_t sector_buffer[512];
    rt_memset(sector_buffer, 0xFF, sizeof(sector_buffer));
    rt_memcpy(sector_buffer, &header, sizeof(header));
    
    if (rt_device_write(mtd_dev, 0, sector_buffer, 1) != 1) {
        console_printf("Failed to write FRAM header\n");
        goto cleanup;
    }
    
    /* Write parameter data starting from sector 1 */
    uint32_t sectors_needed = (data_size + 511) / 512;
    for (uint32_t i = 0; i < sectors_needed; i++) {
        rt_memset(sector_buffer, 0xFF, sizeof(sector_buffer));
        uint32_t copy_size = (data_size > 512) ? 512 : data_size;
        rt_memcpy(sector_buffer, data_buffer + (i * 512), copy_size);
        
        if (rt_device_write(mtd_dev, 1 + i, sector_buffer, 1) != 1) {
            console_printf("Failed to write FRAM data sector %d\n", i);
            goto cleanup;
        }
        
        data_size -= copy_size;
    }
    
    res = FMT_EOK;
    
cleanup:
    if (data_buffer) {
        rt_free(data_buffer);
    }
    rt_device_close(mtd_dev);
    
    return res;
}

/**
 * @brief Load parameters from FRAM
 */
fmt_err_t param_fram_load(void)
{
    rt_device_t mtd_dev;
    fram_param_header_t header;
    uint8_t* data_buffer = NULL;
    uint8_t sector_buffer[512];
    fmt_err_t res = FMT_ERROR;
    
    /* Open FRAM MTD device */
    mtd_dev = rt_device_find(FRAM_MTD_DEVICE_NAME);
    if (mtd_dev == RT_NULL) {
        return FMT_ERROR;
    }
    
    if (rt_device_open(mtd_dev, RT_DEVICE_OFLAG_RDONLY) != RT_EOK) {
        return FMT_ERROR;
    }
    
    /* Read header from sector 0 */
    if (rt_device_read(mtd_dev, 0, sector_buffer, 1) != 1) {
        console_printf("Failed to read FRAM header\n");
        goto cleanup;
    }
    
    rt_memcpy(&header, sector_buffer, sizeof(header));
    
    /* Verify magic number */
    if (header.magic != FRAM_PARAM_MAGIC) {
        console_printf("Invalid FRAM magic: 0x%08X\n", header.magic);
        goto cleanup;
    }
    
    /* Verify header CRC */
    uint32_t calc_crc = crc32_calculate((uint8_t*)&header, 
                                        sizeof(header) - sizeof(header.header_crc));
    if (calc_crc != header.header_crc) {
        console_printf("FRAM header CRC mismatch\n");
        goto cleanup;
    }
    
    /* Verify data size */
    if (header.data_size == 0 || header.data_size > 30 * 1024) {
        console_printf("Invalid FRAM data size: %d\n", header.data_size);
        goto cleanup;
    }
    
    /* Allocate buffer for parameter data */
    data_buffer = (uint8_t*)rt_malloc(header.data_size);
    if (data_buffer == NULL) {
        console_printf("Failed to allocate buffer for FRAM data\n");
        goto cleanup;
    }
    
    /* Read parameter data */
    uint32_t sectors_needed = (header.data_size + 511) / 512;
    uint32_t offset = 0;
    
    for (uint32_t i = 0; i < sectors_needed; i++) {
        if (rt_device_read(mtd_dev, 1 + i, sector_buffer, 1) != 1) {
            console_printf("Failed to read FRAM data sector %d\n", i);
            goto cleanup;
        }
        
        uint32_t copy_size = (header.data_size - offset > 512) ? 512 : (header.data_size - offset);
        rt_memcpy(data_buffer + offset, sector_buffer, copy_size);
        offset += copy_size;
    }
    
    /* Verify data CRC */
    calc_crc = crc32_calculate(data_buffer, header.data_size);
    if (calc_crc != header.data_crc) {
        console_printf("FRAM data CRC mismatch\n");
        goto cleanup;
    }
    
    /* Unpack parameters */
    if (unpack_parameters(data_buffer, header.data_size) != FMT_EOK) {
        console_printf("Failed to unpack parameters from FRAM\n");
        goto cleanup;
    }
    
    res = FMT_EOK;
    
cleanup:
    if (data_buffer) {
        rt_free(data_buffer);
    }
    rt_device_close(mtd_dev);
    
    return res;
}

/**
 * @brief Check if valid parameters exist in FRAM
 */
rt_bool_t param_fram_valid(void)
{
    rt_device_t mtd_dev;
    fram_param_header_t header;
    uint8_t sector_buffer[512];
    rt_bool_t valid = RT_FALSE;
    
    /* Open FRAM MTD device */
    mtd_dev = rt_device_find(FRAM_MTD_DEVICE_NAME);
    if (mtd_dev == RT_NULL) {
        return RT_FALSE;
    }
    
    if (rt_device_open(mtd_dev, RT_DEVICE_OFLAG_RDONLY) != RT_EOK) {
        return RT_FALSE;
    }
    
    /* Read and verify header */
    if (rt_device_read(mtd_dev, 0, sector_buffer, 1) == 1) {
        rt_memcpy(&header, sector_buffer, sizeof(header));
        
        if (header.magic == FRAM_PARAM_MAGIC) {
            uint32_t calc_crc = crc32_calculate((uint8_t*)&header, 
                                                sizeof(header) - sizeof(header.header_crc));
            if (calc_crc == header.header_crc) {
                valid = RT_TRUE;
            }
        }
    }
    
    rt_device_close(mtd_dev);
    return valid;
}

/**
 * @brief Erase all parameters in FRAM
 */
fmt_err_t param_fram_erase(void)
{
    rt_device_t mtd_dev;
    uint8_t sector_buffer[512];
    fmt_err_t res = FMT_ERROR;
    
    /* Open FRAM MTD device */
    mtd_dev = rt_device_find(FRAM_MTD_DEVICE_NAME);
    if (mtd_dev == RT_NULL) {
        return FMT_ERROR;
    }
    
    if (rt_device_open(mtd_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }
    
    /* Erase header sector (write 0xFF) */
    rt_memset(sector_buffer, 0xFF, sizeof(sector_buffer));
    if (rt_device_write(mtd_dev, 0, sector_buffer, 1) == 1) {
        console_printf("FRAM parameters erased\n");
        res = FMT_EOK;
    }
    
    rt_device_close(mtd_dev);
    return res;
}
