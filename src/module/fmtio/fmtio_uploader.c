/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include <firmament.h>

#include "hal/fmtio_dev/fmtio_dev.h"
#include "hal/serial/serial.h"
#include "module/file_manager/file_manager.h"
#include "module/fmtio/fmtio.h"

#define TAG "Uploader"

#define IO_FIRMWARE_NAME "./fmt_io.bin"
#define BL_BAUDRATE      115200

static const uint32_t crc32_tab[] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7, 0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59, 0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924, 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433, 0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65, 0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f, 0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1, 0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b, 0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236, 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d, 0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777, 0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9, 0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

enum {

    PROTO_NOP = 0x00,
    PROTO_OK = 0x10,
    PROTO_FAILED = 0x11,
    PROTO_INSYNC = 0x12,
    PROTO_INVALID = 0x13,
    PROTO_BAD_SILICON_REV = 0x14,
    PROTO_EOC = 0x20,
    PROTO_GET_SYNC = 0x21,
    PROTO_GET_DEVICE = 0x22,
    PROTO_CHIP_ERASE = 0x23,
    PROTO_CHIP_VERIFY = 0x24,
    PROTO_PROG_MULTI = 0x27,
    PROTO_READ_MULTI = 0x28,
    PROTO_GET_CRC = 0x29,
    PROTO_GET_OTP = 0x2a,
    PROTO_GET_SN = 0x2b,
    PROTO_GET_CHIP = 0x2c,
    PROTO_SET_DELAY = 0x2d,
    PROTO_GET_CHIP_DES = 0x2e,
    PROTO_REBOOT = 0x30,

    INFO_BL_REV = 1,     /**< bootloader protocol revision */
    BL_REV = 5,          /**< supported bootloader protocol  */
    INFO_BOARD_ID = 2,   /**< board type */
    INFO_BOARD_REV = 3,  /**< board revision */
    INFO_FLASH_SIZE = 4, /**< max firmware size in bytes */

    PROG_MULTI_MAX = 248, /**< protocol max is 255, must be multiple of 4 */

};

static rt_device_t fmtio_dev;

static uint32_t crc32part(const uint8_t* src, size_t len, uint32_t crc32val)
{
    size_t i;

    for (i = 0; i < len; i++) {
        crc32val = crc32_tab[(crc32val ^ src[i]) & 0xff] ^ (crc32val >> 8);
    }

    return crc32val;
}

static fmt_err_t send_char(uint8_t c)
{
    uint32_t bytes;

    bytes = rt_device_write(fmtio_dev, RT_WAITING_FOREVER, &c, 1);

    return (bytes == 1) ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t send(uint8_t* buff, uint32_t size)
{
    uint32_t bytes;

    bytes = rt_device_write(fmtio_dev, RT_WAITING_FOREVER, buff, size);

    return (bytes == size) ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t get_sync(int32_t timeout)
{
    uint8_t c[2];
    uint32_t bytes;

    bytes = rt_device_read(fmtio_dev, timeout, c, 2);
    if (bytes != 2) {
        PERIOD_EXECUTE(io_error_sync, 1000, ulog_e(TAG, "err get sync:%d\n", bytes););
        return FMT_ERROR;
    }

    if ((c[0] != PROTO_INSYNC) || (c[1] != PROTO_OK)) {
        PERIOD_EXECUTE(io_bad_sync, 1000, ulog_e(TAG, "bad sync 0x%02x,0x%02x\r\n", c[0], c[1]););
        return FMT_ERROR;
    }

    return FMT_EOK;
}

static fmt_err_t sync(void)
{
    uint8_t c;
    rt_size_t ret;

    /* flush read buffer */
    do {
        ret = rt_device_read(fmtio_dev, 40, &c, 1);
    } while (ret);

    /* complete any pending program operation */
    for (unsigned i = 0; i < (PROG_MULTI_MAX + 6); i++) {
        send_char(0);
    }

    send_char(PROTO_GET_SYNC);
    send_char(PROTO_EOC);

    return get_sync(50);
}

static fmt_err_t get_info(int param, uint8_t* val, uint32_t size)
{
    uint32_t bytes;

    send_char(PROTO_GET_DEVICE);
    send_char(param);
    send_char(PROTO_EOC);

    bytes = rt_device_read(fmtio_dev, 5000, val, size);

    if (bytes != size) {
        return FMT_ERROR;
    }

    return get_sync(100);
}

static rt_err_t erase(void)
{
    send_char(PROTO_CHIP_ERASE);
    send_char(PROTO_EOC);

    return get_sync(10000); /* allow 10s timeout */
}

static fmt_err_t program_fs(const char* file_name)
{
    size_t count = 0;
    uint8_t* file_buf;
    rt_err_t ret;
    uint32_t prog_cnt, prog_offset;
    uint32_t sum = 0;
    uint32_t fw_size_remote;
    uint8_t fill_blank = 0xff;
    uint32_t crc = 0;
    uint32_t bytes;
    int fd;
    struct stat fno;
    fmt_err_t error = FMT_EOK;

    ulog_i(TAG, "io firmaware:%s", file_name);

    if (stat(file_name, &fno) < 0) {
        ulog_e(TAG, "read %s status fail!", file_name);
        error = FMT_ERROR;
        goto Out;
    }

    fd = open(file_name, O_RDONLY);

    if (fd < 0) {
        ulog_e(TAG, "%s open fail!", file_name);
        error = FMT_ERROR;
        goto Out;
    }

    prog_cnt = fno.st_size / PROG_MULTI_MAX;
    prog_offset = fno.st_size % PROG_MULTI_MAX;

    file_buf = (uint8_t*)rt_malloc(PROG_MULTI_MAX);

    if (file_buf == NULL) {
        ulog_e(TAG, "malloc fail");
        error = FMT_ERROR;
        goto Out;
    }

    ulog_i(TAG, "erase...");
    ret = erase();
    ulog_i(TAG, "program...");

    int br;

    for (uint32_t i = 0; i < prog_cnt; i++) {

        br = read(fd, file_buf, PROG_MULTI_MAX);

        if (br != PROG_MULTI_MAX) {
            ulog_e(TAG, "read fail err. size:%d br:%d", PROG_MULTI_MAX, br);
            error = FMT_ERROR;
            goto Out;
        }

        /* calculate crc32 sum */
        sum = crc32part((uint8_t*)file_buf, PROG_MULTI_MAX, sum);

        send_char(PROTO_PROG_MULTI);
        send_char(PROG_MULTI_MAX);
        send(file_buf, PROG_MULTI_MAX);
        send_char(PROTO_EOC);

        ret = get_sync(1000);

        if (ret != RT_EOK) {
            ulog_e(TAG, "program fail %ld", ret);
            break;
        }
    }

    if (prog_offset) {
        br = read(fd, file_buf, prog_offset);

        if (br != prog_offset) {
            ulog_e(TAG, "read fail err. size:%d br:%d", prog_offset, br);
            error = FMT_ERROR;
            goto Out;
        }

        /* calculate crc32 sum */
        sum = crc32part((uint8_t*)file_buf, prog_offset, sum);

        send_char(PROTO_PROG_MULTI);
        send_char(prog_offset);
        send(file_buf, prog_offset);
        send_char(PROTO_EOC);

        ret = get_sync(1000);

        if (ret != RT_EOK) {
            ulog_e(TAG, "program fail %ld", ret);
        }
    }

    ret = get_info(INFO_FLASH_SIZE, (uint8_t*)&fw_size_remote, sizeof(fw_size_remote));
    send_char(PROTO_EOC);

    if (ret != RT_EOK) {
        ulog_e(TAG, "could not read firmware size\r\n");
        error = FMT_ERROR;
        goto Out;
    }

    /* fill the rest with 0xff */
    count = fno.st_size;

    while (count < fw_size_remote) {
        sum = crc32part(&fill_blank, sizeof(fill_blank), sum);
        count += sizeof(fill_blank);
    }

    /* request CRC from IO */
    send_char(PROTO_GET_CRC);
    send_char(PROTO_EOC);

    bytes = rt_device_read(fmtio_dev, 5000, &crc, sizeof(crc));

    if (bytes != sizeof(crc)) {
        ulog_e(TAG, "did not receive CRC checksum");
        error = FMT_ERROR;
        goto Out;
    }

    /* compare the CRC sum from the IO with the one calculated */
    if (sum != crc) {
        ulog_e(TAG, "CRC wrong: received: %x, expected: %x", crc, sum);
        error = FMT_ERROR;
        goto Out;
    } else {
        ulog_i(TAG, "CRC check ok, received: %x, expected: %x", crc, sum);
    }

Out:

    if (fd) {
        close(fd);
    }

    if (file_buf) {
        /* free file_buf */
        rt_free(file_buf);
    }

    return error;
}

static fmt_err_t reboot(void)
{
    send_char(PROTO_REBOOT);
    systime_udelay(100 * 1000);
    send_char(PROTO_EOC);
    systime_udelay(100 * 1000);

    return FMT_EOK;
}

/**
 * @brief Upload fmtio firmware
 * 
 * @param path Path of fmtio firmware
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t fmtio_upload(const char* path)
{
    uint32_t old_baudrate;

    fmtio_dev = fmtio_get_device();
    if (fmtio_dev == NULL) {
        return FMT_ERROR;
    }

    // FMT_TRY(fmtio_send_cmd(PROTO_CMD_REBOOT, NULL, 0));
    uint16_t reboot_magic = IO_REBOOT_MAGIC;
    send_io_cmd(IO_CODE_REBOOT, &reboot_magic, sizeof(reboot_magic));
    sys_msleep(10);

    /* suspend fmtio communication, since uploader need use that channel */
    fmtio_suspend_comm(1);
    /* bootloader baudrate is 115200 */
    FMT_TRY(rt_device_control(fmtio_dev, FMTIO_GET_BAUDRATE, &old_baudrate));
    if (old_baudrate != BL_BAUDRATE) {
        FMT_TRY(rt_device_control(fmtio_dev, FMTIO_SET_BAUDRATE, (void*)BL_BAUDRATE));
    }

    uint32_t time = systime_now_ms();
    while (systime_now_ms() - time < 10000) {
        if (sync() == FMT_EOK) {
            uint32_t bl_rev;

            ulog_i(TAG, "sync success");
            get_info(INFO_BL_REV, (uint8_t*)&bl_rev, sizeof(bl_rev));
            ulog_i(TAG, "found bootloader revision: %d", bl_rev);

            if (program_fs(path ? path : IO_FIRMWARE_NAME) == FMT_EOK) {
                reboot();
            } else {
                ulog_e(TAG, "program fail\n");
            }
            break;
        }
        sys_msleep(10);
    }

    /* change back baudrate */
    if (old_baudrate != BL_BAUDRATE) {
        FMT_TRY(rt_device_control(fmtio_dev, FMTIO_SET_BAUDRATE, (void*)old_baudrate));
    }
    /* resume fmtio communication */
    fmtio_suspend_comm(0);

    return FMT_EOK;
}