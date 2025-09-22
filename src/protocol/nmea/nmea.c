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
// #include <stdlib.h>
#include <string.h>

#include "protocol/nmea/nmea.h"

#define NMEA_UNUSED(x) (void)x;

int parse_nmea_sentence(const char* sentence)
{
    int len = strlen(sentence);
    char* endp;

    if (len < 7) {
        return 0;
    }

    int uiCalcComma = 0;

    for (int i = 0; i < len; i++) {
        if (sentence[i] == ',') {
            uiCalcComma++;
        }
    }

    char* bufptr = (char*)(sentence + 6);
    int ret = 0;

    if ((memcmp(sentence + 3, "ZDA,", 4) == 0) && (uiCalcComma == 6)) {

        /*
        UTC day, month, and year, and local time zone offset
        An example of the ZDA message string is:

        $GPZDA,172809.456,12,07,1996,00,00*45

        ZDA message fields
        Field	Meaning
        0	Message ID $GPZDA
        1	UTC
        2	Day, ranging between 01 and 31
        3	Month, ranging between 01 and 12
        4	Year
        5	Local time zone offset from GMT, ranging from 00 through 13 hours
        6	Local time zone offset from GMT, ranging from 00 through 59 minutes
        7	The checksum data, always begins with *
        Fields 5 and 6 together yield the total offset. For example, if field 5 is -5 and field 6 is +15, local time is 5 hours and 15 minutes earlier than GMT.
        */
        double utc_time = 0.0;
        int day = 0, month = 0, year = 0, local_time_off_hour = 0, local_time_off_min = 0;
        NMEA_UNUSED(local_time_off_hour);
        NMEA_UNUSED(local_time_off_min);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            day = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            month = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            year = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            local_time_off_hour = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            local_time_off_min = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }
    } else if ((memcmp(sentence + 3, "GGA,", 4) == 0) && (uiCalcComma >= 14)) {

        /*
          Time, position, and fix related data
          An example of the GBS message string is:
          $xxGGA,time,lat,NS,long,EW,quality,numSV,HDOP,alt,M,sep,M,diffAge,diffStation*cs
          $GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F
          $GNGGA,092721.00,2926.688113,N,11127.771644,E,2,08,1.11,106.3,M,-20,M,1.0,3721*53

          Note - The data string exceeds the nmea standard length.
          GGA message fields
          Field   Meaning
          0   Message ID $GPGGA
          1   UTC of position fix
          2   Latitude
          3   Direction of latitude:
          N: North
          S: South
          4   Longitude
          5   Direction of longitude:
          E: East
          W: West
          6   GPS Quality indicator:
          0: Fix not valid
          1: GPS fix
          2: Differential GPS fix, OmniSTAR VBS
          4: Real-Time Kinematic, fixed integers
          5: Real-Time Kinematic, float integers, OmniSTAR XP/HP or Location RTK
          7   Number of SVs in use, range from 00 through to 24+
          8   HDOP
          9   Orthometric height (MSL reference)
          10  M: unit of measure for orthometric height is meters
          11  Geoid separation
          12  M: geoid separation measured in meters
          13  Age of differential GPS data record, Type 1 or Type 9. Null field when DGPS is not used.
          14  Reference station ID, range 0000-4095. A null field when any reference station ID is selected and no corrections are received1.
          15
          The checksum data, always begins with *
        */
        double utc_time = 0.0, lat = 0.0, lon = 0.0;
        float alt = 0.f, geoid_h = 0.f;
        float hdop = 99.9f, dgps_age = NAN;
        int num_of_sv = 0, fix_quality = 0;
        char ns = '?', ew = '?';

        NMEA_UNUSED(dgps_age);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lat = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ns = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            lon = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ew = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            fix_quality = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            num_of_sv = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            hdop = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            alt = strtof(bufptr, &endp);
            bufptr = endp;
        }

        while (*(++bufptr) != ',') { } // skip M

        if (bufptr && *(++bufptr) != ',') {
            geoid_h = strtof(bufptr, &endp);
            bufptr = endp;
        }

        while (*(++bufptr) != ',') { } // skip M

        if (bufptr && *(++bufptr) != ',') {
            dgps_age = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (ns == 'S') {
            lat = -lat;
        }

        if (ew == 'W') {
            lon = -lon;
        }
    } else if (memcmp(sentence + 3, "HDT,", 4) == 0 && uiCalcComma == 2) {
        /*
        Heading message
        Example $GPHDT,121.2,T*35

        f1 Last computed heading value, in degrees (0-359.99)
        T "T" for "True"
         */

        float heading = 0.f;

        if (bufptr && *(++bufptr) != ',') {
            heading = strtof(bufptr, &endp);
            bufptr = endp;
        }
    } else if ((memcmp(sentence + 3, "GNS,", 4) == 0) && (uiCalcComma >= 12)) {

        /*
        Message GNS
        Type Output Message
        Time and position, together with GNSS fixing related data (number of satellites in use, and
        the resulting HDOP, age of differential data if in use, etc.).
        Message Structure:
        $xxGNS,time,lat,NS,long,EW,posMode,numSV,HDOP,alt,altRef,diffAge,diffStation,navStatus*cs<CR><LF>
        Example:
        $GPGNS,091547.00,5114.50897,N,00012.28663,W,AA,10,0.83,111.1,45.6,,,V*71
        $GNGNS,092721.00,2926.68811,N,11127.77164,E,DNNN,08,1.11,106.3,-20,1.0,3721,V*0D

        FieldNo.  Name    Unit     Format                  Example Description
        0        xxGNS    -       string            $GPGNS GNS Message ID (xx = current Talker ID)
        1        time     -       hhmmss.ss         091547.00 UTC time, see note on UTC representation
        2        lat      -       ddmm.mmmmm        5114.50897 Latitude (degrees & minutes), see format description
        3        NS       -       character         N North/South indicator
        4        long     -       dddmm.mmmmm       00012.28663 Longitude (degrees & minutes), see format description
        5        EW       -       character         E East/West indicator
        6      posMode    -       character         AA Positioning mode, see position fix flags description. First character for GPS, second character forGLONASS
        7       numSV     -       numeric         10 Number of satellites used (range: 0-99)
        8         HDOP    -       numeric         0.83 Horizontal Dilution of Precision
        9         alt     m       numeric         111.1 Altitude above mean sea level
        10        sep    m        numeric         45.6 Geoid separation: difference between ellipsoid and mean sea level UBX-18010854 - R05 Advance Information Page 18 of 262 u-blox ZED-F9P Interface Description - Manual GNS continued
        11    diffAge    s        numeric         - Age of differential corrections (blank when DGPS is not used)
        12 diffStation   -        numeric         - ID of station providing differential corrections (blank when DGPS is not used)
        13 navStatus    -         character         V Navigational status indicator (V = Equipment is not providing navigational status information) NMEA v4.10 and above only
        14 cs - hexadecimal *71   Checksum
        15 <CR><LF> - character - Carriage return and line feed
        */
        double utc_time = 0.0;
        double lat = 0.0, lon = 0.0;
        char pos_Mode[5] = { 'N', 'N', 'N', 'N', 'N' };
        int num_of_sv = 0;
        float alt = 0.f;
        float hdop = 0.f;
        char ns = '?', ew = '?';
        int i = 0;
        NMEA_UNUSED(pos_Mode);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lat = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ns = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            lon = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ew = *(bufptr++);
        }

        do {
            pos_Mode[i] = *(bufptr);
            i++;

        } while (*(++bufptr) != ',' && i < 5);

        if (bufptr && *(++bufptr) != ',') {
            num_of_sv = strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            hdop = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            alt = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (ns == 'S') {
            lat = -lat;
        }

        if (ew == 'W') {
            lon = -lon;
        }
    } else if ((memcmp(sentence + 3, "RMC,", 4) == 0) && (uiCalcComma >= 11)) {

        /*
        Position, velocity, and time
        The RMC string is:

        $xxRMC,time,status,lat,NS,long,EW,spd,cog,date,mv,mvEW,posMode,navStatus*cs<CR><LF>
        The Talker ID ($--) will vary depending on the satellite system used for the position solution:
        $GNRMC,092721.00,A,2926.688113,N,11127.771644,E,0.780,,200520,,,D,V*1D

        GPRMC message fields
        Field	Meaning
        0	Message ID $GPRMC
        1	UTC of position fix
        2	Status A=active or V=void
        3	Latitude
        4	Longitude
        5	Speed over the ground in knots
        6	Track angle in degrees (True)
        7	Date
        8	Magnetic variation in degrees
        9	The checksum data, always begins with *
        */
        double utc_time = 0.0;
        char Status = 'V';
        double lat = 0.0, lon = 0.0;
        float ground_speed_K = 0.f;
        float track_true = 0.f;
        int nmea_date = 0;
        float Mag_var = 0.f;
        char ns = '?', ew = '?';
        NMEA_UNUSED(Mag_var);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            Status = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            lat = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ns = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            lon = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            ew = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            ground_speed_K = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            track_true = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            nmea_date = (int)strtol(bufptr, &endp, 10);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            Mag_var = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (ns == 'S') {
            lat = -lat;
        }

        if (ew == 'W') {
            lon = -lon;
        }

        if (Status == 'V') {
            // _gps_position->fix_type = 0;
        }
    } else if ((memcmp(sentence + 3, "GST,", 4) == 0) && (uiCalcComma == 8)) {

        /*
        Position error statistics
        An example of the GST message string is:

        $GPGST,172814.0,0.006,0.023,0.020,273.6,0.023,0.020,0.031*6A
        $GNGST,091200.54,45,,,,1.2,0.77,2.2*70
        $GNGST,092720.50,43,,,,2.6,2.6,5.9*49

        The Talker ID ($--) will vary depending on the satellite system used for the position solution:

        $GP - GPS only
        $GL - GLONASS only
        $GN - Combined
        GST message fields
        Field   Meaning
        0   Message ID $GPGST
        1   UTC of position fix
        2   RMS value of the pseudorange residuals; includes carrier phase residuals during periods of RTK (float) and RTK (fixed) processing
        3   Error ellipse semi-major axis 1 sigma error, in meters
        4   Error ellipse semi-minor axis 1 sigma error, in meters
        5   Error ellipse orientation, degrees from true north
        6   Latitude 1 sigma error, in meters
        7   Longitude 1 sigma error, in meters
        8   Height 1 sigma error, in meters
        9   The checksum data, always begins with *
        */
        double utc_time = 0.0;
        float lat_err = 0.f, lon_err = 0.f, alt_err = 0.f;
        float min_err = 0.f, maj_err = 0.f, deg_from_north = 0.f, rms_err = 0.f;

        NMEA_UNUSED(min_err);
        NMEA_UNUSED(maj_err);
        NMEA_UNUSED(deg_from_north);
        NMEA_UNUSED(rms_err);

        if (bufptr && *(++bufptr) != ',') {
            utc_time = strtod(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            rms_err = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            maj_err = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            min_err = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            deg_from_north = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lat_err = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            lon_err = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            alt_err = strtof(bufptr, &endp);
            bufptr = endp;
        }
    } else if ((memcmp(sentence + 3, "GSA,", 4) == 0) && (uiCalcComma >= 17)) {

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
    } else if ((memcmp(sentence + 3, "VTG,", 4) == 0) && (uiCalcComma >= 8)) {

        /*$GNVTG,,T,,M,0.683,N,1.265,K*30
          $GNVTG,,T,,M,0.780,N,1.445,K*33

        Field	Meaning
        0	Message ID $GPVTG
        1	Track made good (degrees true)
        2	T: track made good is relative to true north
        3	Track made good (degrees magnetic)
        4	M: track made good is relative to magnetic north
        5	Speed, in knots
        6	N: speed is measured in knots
        7	Speed over ground in kilometers/hour (kph)
        8	K: speed over ground is measured in kph
        9	The checksum data, always begins with *
        */

        float track_true = 0.f;
        char T;
        float track_mag = 0.f;
        char M;
        float ground_speed = 0.f;
        char N;
        float ground_speed_K = 0.f;
        char K;
        NMEA_UNUSED(T);
        NMEA_UNUSED(track_mag);
        NMEA_UNUSED(M);
        NMEA_UNUSED(N);
        NMEA_UNUSED(ground_speed_K);
        NMEA_UNUSED(K);

        if (bufptr && *(++bufptr) != ',') {
            track_true = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            T = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            track_mag = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            M = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            ground_speed = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            N = *(bufptr++);
        }

        if (bufptr && *(++bufptr) != ',') {
            ground_speed_K = strtof(bufptr, &endp);
            bufptr = endp;
        }

        if (bufptr && *(++bufptr) != ',') {
            K = *(bufptr++);
        }
    }

    return ret;
}
