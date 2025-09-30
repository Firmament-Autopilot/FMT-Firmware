/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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
#include <stdlib.h>
#include <string.h>

#include "protocol/nmea/nmea.h"

#define NMEA_UNUSED(x) (void)x;

static uint8_t strtohex(const char* str)
{
    static int offset = 'A' - 'a';
    int high = (str[0] >= 'a' && str[0] <= 'z') ? str[0] + offset : str[0];
    int low = (str[1] >= 'a' && str[1] <= 'z') ? str[1] + offset : str[1];

    high = (high >= '0' && high <= '9') ? high - '0' : (high >= 'A' && high <= 'F') ? high - 'A' + 10
                                                                                    : 0;

    low = (low >= '0' && low <= '9') ? low - '0' : (low >= 'A' && low <= 'F') ? low - 'A' + 10
                                                                              : 0;

    return (high << 4) | low;
}

static void nmea_decoder_reset(nmea_decoder_t* decoder)
{
    decoder->decode_state = NMEA_DECODE_START;
    decoder->rx_buf_index = 0;
    // decoder->got_posllh = false;
    // decoder->got_velned = false;
    // decoder->got_svinfo = false;
    // decoder->got_dop = false;
}

int parse_nmea_sentence(nmea_decoder_t* decoder, const char* sentence)
{
    int len = strlen(sentence);
    char* endp;
    int comma_cnt = 0;
    int ret = -1;
    char* bufptr;

    if (decoder == NULL || len < 7) {
        return ret;
    }

    for (int i = 0; i < len; i++) {
        if (sentence[i] == ',') {
            comma_cnt++;
        }
    }

    if ((memcmp(sentence + 1, "KSXT,", 5) == 0) && (comma_cnt == 21)) {

        bufptr = (char*)(sentence + 5);

        /*
        An example of the KSXT message string is:

        $KSXT,20190909084745.00,116.23662400,40.07897925,68.3830,299.22,67.03,190.28,0.022,,1,3,46,28,,,,-0.004,-0.021,-0.020,,*27

        KSXT message fields
        Field	Meaning
        0	Message ID $KSXT
        1	UTC
        2	Lon
        3	Lat
        4	Height
        5	Heading
        6	Pitch
        7   Track true
        8   Vel
        9   Roll
       10   Pos qual
       11   Heading qual
       12   #hsolnSVs
       13   #msolnSVs
       14   East
       15   North
       16   Up
       17   EastVel
       18   NorthVel
       19   UpVel
       20   Reserved
       21   Reserved
       22	The checksum data, always begins with *
        */

        double utc_time = 0.0, lat = 0.0, lon = 0.0;
        float height = 0.0, heading = 0.0, pitch = 0.0, track = 0.0, vel = 0.0, roll = 0.0;
        int pos_qual = 0, heading_qual = 0, hsolnSVs = 0, msolnSVs = 0;
        float east = 0.0, north = 0.0, up = 0.0, vn = 0.0, ve = 0.0, vu = 0.0;

        NMEA_UNUSED(east);
        NMEA_UNUSED(north);
        NMEA_UNUSED(up);
        NMEA_UNUSED(roll);
        NMEA_UNUSED(pitch);
        NMEA_UNUSED(track);
        NMEA_UNUSED(utc_time);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lon = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lat = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            height = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            heading = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            pitch = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            track = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            vel = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            roll = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            pos_qual = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            heading_qual = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            hsolnSVs = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            msolnSVs = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            east = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            north = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            up = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ve = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            vn = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            vu = strtof(bufptr, &endp);
            bufptr = endp;
        }

        // TODO parse utc time
        decoder->buf.payload_rx_ksxt.year = 0;
        decoder->buf.payload_rx_ksxt.month = 0;
        decoder->buf.payload_rx_ksxt.day = 0;
        decoder->buf.payload_rx_ksxt.hour = 0;
        decoder->buf.payload_rx_ksxt.sec = 0;

        decoder->buf.payload_rx_ksxt.lon = lon * 1e7;
        decoder->buf.payload_rx_ksxt.lat = lat * 1e7;
        decoder->buf.payload_rx_ksxt.height = height * 1e3;
        decoder->buf.payload_rx_ksxt.velN = vn / 3.6f;
        decoder->buf.payload_rx_ksxt.velE = ve / 3.6f;
        decoder->buf.payload_rx_ksxt.velD = -vu / 3.6f;
        decoder->buf.payload_rx_ksxt.heading = heading / 180.0f * PI;
        decoder->buf.payload_rx_ksxt.track = track / 180.0f * PI;
        decoder->buf.payload_rx_ksxt.gSpeed = vel / 3.6f;
        decoder->buf.payload_rx_ksxt.pos_fixType = pos_qual;
        decoder->buf.payload_rx_ksxt.heading_fixType = heading_qual;
        decoder->buf.payload_rx_ksxt.MnumSV = msolnSVs;
        decoder->buf.payload_rx_ksxt.SnumSV = hsolnSVs;

        if (decoder->rx_handle)
            ret = decoder->rx_handle(NMEA_MSG_KSXT);
    } else if ((memcmp(sentence + 3, "GSA,", 4) == 0) && (comma_cnt >= 17)) {

        bufptr = (char*)(sentence + 6);

        /*
        GPS DOP and active satellites
        An example of the GSA message string is:
        $GPGSA,<1>,<2>,<3>,<3>,,,,,<3>,<3>,<3>,<4>,<5>,<6>*<7><CR><LF>
        $GNGSA,A,3,82,67,74,68,73,80,83,,,,,,0.99,0.53,0.84,2*09
        $GNGSA,A,3,12,19,06,17,02,09,28,05,,,,,2.38,1.10,2.11,1*05
        $GNGSA,A,3,27,04,16,08,09,26,31,11,,,,,1.96,1.05,1.65,1*08

        GSA message fields
        Field	Meaning
        0	Message ID $GPGSA
        1	Mode 1, M = manual, A = automatic
        2	Mode 2, Fix type, 1 = not available, 2 = 2D, 3 = 3D
        3	PRN number, 01 through 32 for GPS, 33 through 64 for SBAS, 64+ for GLONASS
        4 	PDOP: 0.5 through 99.9
        5	HDOP: 0.5 through 99.9
        6	VDOP: 0.5 through 99.9
        7	The checksum data, always begins with *
        */
        char M_pos = ' ';
        int fix_mode = 0;
        int sat_id[12] = { 0 };
        float pdop = 99.9f, hdop = 99.9f, vdop = 99.9f;

        NMEA_UNUSED(M_pos);
        NMEA_UNUSED(fix_mode);
        NMEA_UNUSED(sat_id);
        NMEA_UNUSED(pdop);

        if (bufptr && *(++bufptr) != ',') {
            M_pos = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            fix_mode = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        for (int y = 0; y < 12; y++) {
            if (bufptr && *(++bufptr) != ',') {
                sat_id[y] = strtol(bufptr, &endp, 10);
                bufptr = endp;
            }
        }

        if (bufptr && *(++bufptr) != ',') {
            pdop = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            hdop = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            vdop = strtof(bufptr, &endp);
            bufptr = endp;
        }

        decoder->buf.payload_rx_gpgsa.pdop = pdop;
        decoder->buf.payload_rx_gpgsa.hdop = hdop;
        decoder->buf.payload_rx_gpgsa.vdop = vdop;

        if (decoder->rx_handle)
            ret = decoder->rx_handle(NMEA_MSG_GPGSA);
    }

    return ret;
}

int parse_nmea_char(nmea_decoder_t* decoder, const uint8_t c)
{
    int ret = -1;

    switch (decoder->decode_state) {
    case NMEA_DECODE_START: {
        if (c == '$') {
            decoder->nmea_rx_buf[decoder->rx_buf_index++] = c;
            decoder->decode_state = NMEA_DECODE_PAYLOAD;
        }
    } break;
    case NMEA_DECODE_PAYLOAD: {
        if (c == '*') {
            decoder->decode_state = NMEA_DECODE_CS1;
        }
        decoder->nmea_rx_buf[decoder->rx_buf_index++] = c;
    } break;
    case NMEA_DECODE_CS1: {
        decoder->nmea_rx_buf[decoder->rx_buf_index++] = c;
        decoder->decode_state = NMEA_DECODE_CS2;
    } break;
    case NMEA_DECODE_CS2: {
        decoder->nmea_rx_buf[decoder->rx_buf_index++] = c;

        int i;
        uint8_t calc_cs = 0, recv_cs = 0;
        char recv_cs_str[3] = { 0 };
        /* verify checksum */
        for (i = 1; decoder->nmea_rx_buf[i] != '*'; i++) {
            calc_cs ^= decoder->nmea_rx_buf[i];
        }
        recv_cs_str[0] = decoder->nmea_rx_buf[i + 1];
        recv_cs_str[1] = decoder->nmea_rx_buf[i + 2];

        recv_cs = strtohex(recv_cs_str);
        if (recv_cs == calc_cs) {
            decoder->nmea_rx_buf[decoder->rx_buf_index++] = 0;
            ret = parse_nmea_sentence(decoder, decoder->nmea_rx_buf);
        }

        decoder->decode_state = NMEA_DECODE_START;
        nmea_decoder_reset(decoder);
    } break;
    default:
        decoder->decode_state = NMEA_DECODE_START;
        nmea_decoder_reset(decoder);
        break;
    }

    return ret;
}

fmt_err_t init_nmea_decoder(nmea_decoder_t* decoder, rt_device_t dev, nmea_rx_handle_ptr rx_handle)
{
    if (decoder == NULL || dev == NULL || rx_handle == NULL) {
        return FMT_EEMPTY;
    }

    decoder->nmea_dev = dev;
    decoder->rx_handle = rx_handle;
    decoder->got_posllh = false;
    decoder->got_velned = false;
    decoder->got_svinfo = false;
    decoder->got_dop = false;

    nmea_decoder_reset(decoder);

    return FMT_EOK;
}
