#include "serial_protocol_internal.h"
#include <string.h>

/*******************************************************************************
 * Static members.
 *******************************************************************************/
// CRC-16 table for POLY 0x8005 (x^16 + x^15 + x^2 + 1).
static const uint16_t crc16_table[256] = {
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};

/*******************************************************************************
 * Public function definitions.
 *******************************************************************************/
void uxr_update_crc(uint16_t* crc, const uint8_t data)
{
    *crc = (*crc >> 8) ^ crc16_table[(*crc ^ data) & 0xFF];
}

bool uxr_get_next_octet(uxrSerialIO* serial_io, uint8_t* octet)
{
    bool rv = false;
    *octet = 0;
    if (serial_io->rb_head != serial_io->rb_tail)
    {
        if (UXR_FRAMING_ESC_FLAG != serial_io->rb[serial_io->rb_tail])
        {
            *octet = serial_io->rb[serial_io->rb_tail];
            serial_io->rb_tail = (uint8_t)((size_t)(serial_io->rb_tail + 1) % sizeof(serial_io->rb));
            rv = (UXR_FRAMING_BEGIN_FLAG != *octet);
        }
        else
        {
            uint8_t temp_tail = (uint8_t)((size_t)(serial_io->rb_tail + 1) % sizeof(serial_io->rb));
            if (temp_tail != serial_io->rb_head)
            {
                *octet = serial_io->rb[temp_tail];
                serial_io->rb_tail = (uint8_t)((size_t)(serial_io->rb_tail + 2) % sizeof(serial_io->rb));
                if (UXR_FRAMING_BEGIN_FLAG != *octet)
                {
                    *octet ^= UXR_FRAMING_XOR_FLAG;
                    rv = true;
                }
            }
        }
    }
    return rv;
}

bool uxr_add_next_octet(uxrSerialIO* serial_io, uint8_t octet)
{
    bool rv = false;

    if (UXR_FRAMING_BEGIN_FLAG == octet || UXR_FRAMING_ESC_FLAG == octet)
    {
        if ((uint8_t)(serial_io->wb_pos + 1) < sizeof(serial_io->wb))
        {
            serial_io->wb[serial_io->wb_pos] = UXR_FRAMING_ESC_FLAG;
            serial_io->wb[serial_io->wb_pos + 1] = octet ^ UXR_FRAMING_XOR_FLAG;
            serial_io->wb_pos = (uint8_t)(serial_io->wb_pos + 2);
            rv = true;
        }
    }
    else
    {
        if (serial_io->wb_pos < sizeof(serial_io->wb))
        {
            serial_io->wb[serial_io->wb_pos] = octet;
            serial_io->wb_pos = (uint8_t)(serial_io->wb_pos + 1);
            rv = true;
        }
    }

    return rv;
}

void uxr_init_serial_io(uxrSerialIO* serial_io, uint8_t local_addr)
{
    serial_io->local_addr = local_addr;
    serial_io->state = UXR_SERIAL_UNINITIALIZED;
    serial_io->rb_head = 0;
    serial_io->rb_tail = 0;
}

size_t uxr_write_serial_msg(uxrSerialIO* serial_io,
                            uxr_write_cb write_cb,
                            void* cb_arg,
                            const uint8_t* buf,
                            size_t len,
                            uint8_t remote_addr,
                            uint8_t* errcode)
{
    /* Buffer being flag. */
    serial_io->wb[0] = UXR_FRAMING_BEGIN_FLAG;
    serial_io->wb_pos = 1;

    /* Buffer header. */
    uxr_add_next_octet(serial_io, serial_io->local_addr);
    uxr_add_next_octet(serial_io, remote_addr);
    uxr_add_next_octet(serial_io, (uint8_t)(len & 0xFF));
    uxr_add_next_octet(serial_io, (uint8_t)(len >> 8));

    /* Write payload. */
    uint8_t octet = 0;
    uint16_t written_len = 0;
    uint16_t crc = 0;
    bool cond = true;
    while (written_len < len && cond)
    {
        octet = *(buf + written_len);
        if (uxr_add_next_octet(serial_io, octet))
        {
            uxr_update_crc(&crc, octet);
            ++written_len;
        }
        else
        {
            size_t bytes_written = write_cb(cb_arg, serial_io->wb, serial_io->wb_pos, errcode);
            if (0 < bytes_written)
            {
                cond = true;
                serial_io->wb_pos = (uint8_t)(serial_io->wb_pos - bytes_written);
            }
            else
            {
                cond = false;
            }
        }
    }

    /* Write CRC. */
    uint8_t tmp_crc[2];
    tmp_crc[0] = (uint8_t)(crc & 0xFF);
    tmp_crc[1] = (uint8_t)(crc >> 8);
    written_len = 0;
    while (written_len < sizeof(tmp_crc) && cond)
    {
        octet = *(tmp_crc + written_len);
        if (uxr_add_next_octet(serial_io, octet))
        {
            uxr_update_crc(&crc, octet);
            ++written_len;
        }
        else
        {
            size_t bytes_written = write_cb(cb_arg, serial_io->wb, serial_io->wb_pos, errcode);
            if (0 < bytes_written)
            {
                cond = true;
                serial_io->wb_pos = (uint8_t)(serial_io->wb_pos - bytes_written);
            }
            else
            {
                cond = false;
            }
        }
    }

    /* Flus write buffer. */
    if (cond && (0 < serial_io->wb_pos))
    {
            size_t bytes_written = write_cb(cb_arg, serial_io->wb, serial_io->wb_pos, errcode);
            if (0 < bytes_written)
            {
                cond = true;
                serial_io->wb_pos = (uint8_t)(serial_io->wb_pos - bytes_written);
            }
            else
            {
                cond = false;
            }
    }

    return cond ? (uint16_t)(len) : 0;
}

size_t uxr_read_serial_msg(uxrSerialIO* serial_io,
                           uxr_read_cb read_cb,
                           void* cb_arg,
                           uint8_t* buf,
                           size_t len,
                           uint8_t* remote_addr,
                           int timeout,
                           uint8_t* errcode)
{
    size_t rv = 0;

    /* Compute read-buffer available size. */
    uint8_t av_len[2] = {0, 0};
    if (serial_io->rb_head == serial_io->rb_tail)
    {
        serial_io->rb_head = 0;
        serial_io->rb_tail = 0;
        av_len[0] = sizeof(serial_io->rb) - 1;
    }
    else if (serial_io->rb_head > serial_io->rb_tail)
    {
        if (0 < serial_io->rb_tail)
        {
            av_len[0] = (uint8_t)(sizeof(serial_io->rb) - serial_io->rb_head);
            av_len[1] = (uint8_t)(serial_io->rb_tail - 1);
        }
        else
        {
            av_len[0] = (uint8_t)(sizeof(serial_io->rb) - serial_io->rb_head - 1);
        }
    }
    else
    {
        av_len[0] = (uint8_t)(serial_io->rb_tail - serial_io->rb_head - 1);
    }

    /* Read from serial. */
    size_t bytes_read[2] = {0};
    if (0 < av_len[0])
    {
        bytes_read[0] = read_cb(cb_arg, &serial_io->rb[serial_io->rb_head], av_len[0], timeout, errcode);
        serial_io->rb_head = (uint8_t)((size_t)(serial_io->rb_head + bytes_read[0]) % sizeof(serial_io->rb));
        if (0 < bytes_read[0])
        {
            if ((bytes_read[0] == av_len[0]) && (0 < av_len[1]))
            {
                bytes_read[1] = read_cb(cb_arg, &serial_io->rb[serial_io->rb_head], av_len[1], 0, errcode);
                serial_io->rb_head = (uint8_t)((size_t)(serial_io->rb_head + bytes_read[1]) % sizeof(serial_io->rb));
            }
        }
    }

    if (0 < (bytes_read[0] + bytes_read[1]) || (serial_io->rb_tail != serial_io->rb_head))
    {
        /* State Machine. */
        bool exit_cond = false;
        while (!exit_cond)
        {
            uint8_t octet = 0;
            switch (serial_io->state)
            {
                case UXR_SERIAL_UNINITIALIZED:
                {
                    octet = 0;
                    while ((UXR_FRAMING_BEGIN_FLAG != octet) && (serial_io->rb_head != serial_io->rb_tail))
                    {
                        octet = serial_io->rb[serial_io->rb_tail];
                        serial_io->rb_tail = (uint8_t)((size_t)(serial_io->rb_tail + 1) % sizeof(serial_io->rb));
                    }

                    if (UXR_FRAMING_BEGIN_FLAG == octet)
                    {
                        serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                    }
                    else
                    {
                        exit_cond = true;
                    }
                    break;
                }
                case UXR_SERIAL_READING_SRC_ADDR:
                {
                    if (uxr_get_next_octet(serial_io, &serial_io->src_addr))
                    {
                        serial_io->state = UXR_SERIAL_READING_DST_ADDR;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG != serial_io->src_addr)
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                }
                case UXR_SERIAL_READING_DST_ADDR:
                    if (uxr_get_next_octet(serial_io, &octet))
                    {
                        serial_io->state = (octet == serial_io->local_addr) ? UXR_SERIAL_READING_LEN_LSB :
                                                                              UXR_SERIAL_UNINITIALIZED;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                case UXR_SERIAL_READING_LEN_LSB:
                    if (uxr_get_next_octet(serial_io, &octet))
                    {
                        serial_io->msg_len = octet;
                        serial_io->state = UXR_SERIAL_READING_LEN_MSB;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                case UXR_SERIAL_READING_LEN_MSB:
                    if (uxr_get_next_octet(serial_io, &octet))
                    {
                        serial_io->msg_len = (uint16_t)(serial_io->msg_len + (octet << 8));
                        serial_io->msg_pos = 0;
                        serial_io->cmp_crc = 0;
                        if (len < serial_io->msg_len)
                        {
                            serial_io->state = UXR_SERIAL_UNINITIALIZED;
                            exit_cond = true;
                        }
                        else
                        {
                            serial_io->state = UXR_SERIAL_READING_PAYLOAD;
                        }
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                case UXR_SERIAL_READING_PAYLOAD:
                {
                    while ((serial_io->msg_pos < serial_io->msg_len) && uxr_get_next_octet(serial_io, &octet))
                    {
                        buf[(size_t)serial_io->msg_pos] = octet;
                        serial_io->msg_pos = (uint16_t)(serial_io->msg_pos + 1);
                        uxr_update_crc(&serial_io->cmp_crc, octet);
                    }

                    if (serial_io->msg_pos == serial_io->msg_len)
                    {
                        serial_io->state = UXR_SERIAL_READING_CRC_LSB;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                }
                case UXR_SERIAL_READING_CRC_LSB:
                    if (uxr_get_next_octet(serial_io, &octet))
                    {
                        serial_io->msg_crc = octet;
                        serial_io->state = UXR_SERIAL_READING_CRC_MSB;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                case UXR_SERIAL_READING_CRC_MSB:
                    if (uxr_get_next_octet(serial_io, &octet))
                    {
                        serial_io->msg_crc = (uint16_t)(serial_io->msg_crc + (octet << 8));
                        serial_io->state = UXR_SERIAL_UNINITIALIZED;
                        if (serial_io->cmp_crc == serial_io->msg_crc)
                        {
                            *remote_addr = serial_io->src_addr;
                            rv = serial_io->msg_len;
                        }
                        exit_cond = true;
                    }
                    else
                    {
                        if (UXR_FRAMING_BEGIN_FLAG == octet)
                        {
                            serial_io->state = UXR_SERIAL_READING_SRC_ADDR;
                        }
                        else
                        {
                            exit_cond = true;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return rv;
}
