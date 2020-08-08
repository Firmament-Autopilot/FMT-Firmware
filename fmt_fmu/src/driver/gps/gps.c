/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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
#include <string.h>

#include "hal/serial.h"
#include "driver/gps.h"

#define FNV1_32_INIT	((uint32_t)0x811c9dc5)	// init value for FNV1 hash algorithm
#define FNV1_32_PRIME	((uint32_t)0x01000193)	// magic prime for FNV1 hash algorithm
#define M_DEG_TO_RAD_F 		0.01745329251994f
#define M_RAD_TO_DEG_F 		57.2957795130823f
#define MIN(x,y) (x < y ? x : y)

static rt_device_t serial_device;
static struct rt_device gps_device;

ubx_decode_state_t _decode_state;
uint16_t _rx_payload_length;
uint16_t _rx_payload_index;
uint8_t _rx_ck_a;
uint8_t _rx_ck_b;
uint16_t _rx_msg;
ubx_rxmsg_state_t _rx_state;
rt_bool_t _configured;
rt_bool_t _use_nav_pvt;
ubx_buf_t _buf;
ubx_ack_state_t _ack_state;
uint16_t _ack_waiting_msg;
uint32_t _ubx_version;
struct vehicle_gps_position_s _gps_position;
struct satellite_info_s _satellite_info;
uint8_t _rate_count_lat_lon;
uint8_t _rate_count_vel;
rt_bool_t _got_posllh;
rt_bool_t _got_velned;
rt_bool_t _got_svinfo;

void _decode_init(void)
{
	_decode_state = UBX_DECODE_SYNC1;
	_rx_ck_a = 0;
	_rx_ck_b = 0;
	_rx_payload_length = 0;
	_rx_payload_index = 0;

	//console_printf("_decode_state %d\n" , _decode_state);
}

void _add_byte_to_checksum(const uint8_t b)
{
	_rx_ck_a = _rx_ck_a + b;
	_rx_ck_b = _rx_ck_b + _rx_ck_a;
}

rt_err_t _set_baudrate(rt_device_t dev, uint32_t baudrate)
{
	rt_err_t err;

	//get current serial device config.
	struct serial_device* serial_dev = (struct serial_device*)dev;
	serial_dev->config.baud_rate = baudrate;

	err = rt_device_control(dev, RT_DEVICE_CTRL_CONFIG, &serial_dev->config);

	return err;
}

uint32_t fnv1_32_str(uint8_t* str, uint32_t hval)
{
	uint8_t* s = str;

	/*
	 * FNV-1 hash each octet in the buffer
	 */
	while(*s) {

		/* multiply by the 32 bit FNV magic prime mod 2^32 */
#if defined(NO_FNV_GCC_OPTIMIZATION)
		hval *= FNV1_32_PRIME;
#else
		hval += (hval << 1) + (hval << 4) + (hval << 7) + (hval << 8) + (hval << 24);
#endif

		/* xor the bottom with the current octet */
		hval ^= (uint32_t) * s++;
	}

	/* return our new hash value */
	return hval;
}

int	// -1 = error, 0 = ok, 1 = payload completed
payload_rx_add_nav_svinfo(const uint8_t b)
{
	int ret = 0;

	if(_rx_payload_index < sizeof(ubx_payload_rx_nav_svinfo_part1_t)) {
		// Fill Part 1 buffer
		_buf.raw[_rx_payload_index] = b;

	} else {
		if(_rx_payload_index == sizeof(ubx_payload_rx_nav_svinfo_part1_t)) {
			// Part 1 complete: decode Part 1 buffer
			_satellite_info.count = MIN(_buf.payload_rx_nav_svinfo_part1.numCh, SAT_INFO_MAX_SATELLITES);
//			console_printf("SVINFO len %u  numCh %u\r\n", (unsigned)_rx_payload_length,
//					 (unsigned)_buf.payload_rx_nav_svinfo_part1.numCh);
		}

		if(_rx_payload_index < sizeof(ubx_payload_rx_nav_svinfo_part1_t) + _satellite_info.count * sizeof(
		            ubx_payload_rx_nav_svinfo_part2_t)) {
			// Still room in _satellite_info: fill Part 2 buffer
			unsigned buf_index = (_rx_payload_index - sizeof(ubx_payload_rx_nav_svinfo_part1_t)) % sizeof(
			                         ubx_payload_rx_nav_svinfo_part2_t);
			_buf.raw[buf_index] = b;

			if(buf_index == sizeof(ubx_payload_rx_nav_svinfo_part2_t) - 1) {
				// Part 2 complete: decode Part 2 buffer
				unsigned sat_index = (_rx_payload_index - sizeof(ubx_payload_rx_nav_svinfo_part1_t)) / sizeof(
				                         ubx_payload_rx_nav_svinfo_part2_t);
				_satellite_info.used[sat_index]	= (uint8_t)(_buf.payload_rx_nav_svinfo_part2.flags & 0x01);
				_satellite_info.snr[sat_index]		= (uint8_t)(_buf.payload_rx_nav_svinfo_part2.cno);
				_satellite_info.elevation[sat_index]	= (uint8_t)(_buf.payload_rx_nav_svinfo_part2.elev);
				_satellite_info.azimuth[sat_index]	= (uint8_t)((float)_buf.payload_rx_nav_svinfo_part2.azim * 255.0f / 360.0f);
				_satellite_info.svid[sat_index]	= (uint8_t)(_buf.payload_rx_nav_svinfo_part2.svid);
//				console_printf("SVINFO #%02u  used %u  snr %3u  elevation %3u  azimuth %3u  svid %3u\r\n",
//						 (unsigned)sat_index + 1,
//						 (unsigned)_satellite_info.used[sat_index],
//						 (unsigned)_satellite_info.snr[sat_index],
//						 (unsigned)_satellite_info.elevation[sat_index],
//						 (unsigned)_satellite_info.azimuth[sat_index],
//						 (unsigned)_satellite_info.svid[sat_index]
//						);

			}
		}
	}

	if(++_rx_payload_index >= _rx_payload_length) {
		ret = 1;	// payload received completely
	}

	return ret;
}

int	// -1 = error, 0 = ok, 1 = payload completed
payload_rx_add_mon_ver(const uint8_t b)
{
	int ret = 0;

	if(_rx_payload_index < sizeof(ubx_payload_rx_mon_ver_part1_t)) {
		// Fill Part 1 buffer
		_buf.raw[_rx_payload_index] = b;

	} else {
		if(_rx_payload_index == sizeof(ubx_payload_rx_mon_ver_part1_t)) {
			// Part 1 complete: decode Part 1 buffer and calculate hash for SW&HW version strings
			_ubx_version = fnv1_32_str(_buf.payload_rx_mon_ver_part1.swVersion, FNV1_32_INIT);
			_ubx_version = fnv1_32_str(_buf.payload_rx_mon_ver_part1.hwVersion, _ubx_version);
//			console_printf("VER hash 0x%08x\r\n", _ubx_version);
//			console_printf("VER hw  \"%10s\"\r\n", _buf.payload_rx_mon_ver_part1.hwVersion);
//			console_printf("VER sw  \"%30s\"\r\n", _buf.payload_rx_mon_ver_part1.swVersion);
		}

		// fill Part 2 buffer
		unsigned buf_index = (_rx_payload_index - sizeof(ubx_payload_rx_mon_ver_part1_t)) % sizeof(
		                         ubx_payload_rx_mon_ver_part2_t);
		_buf.raw[buf_index] = b;

		if(buf_index == sizeof(ubx_payload_rx_mon_ver_part2_t) - 1) {
			// Part 2 complete: decode Part 2 buffer
			//console_printf("VER ext \" %30s\"\r\n", _buf.payload_rx_mon_ver_part2.extension);
		}
	}

	if(++_rx_payload_index >= _rx_payload_length) {
		ret = 1;	// payload received completely
	}

	return ret;
}

int	// 0 = no message handled, 1 = message handled, 2 = sat info message handled
payload_rx_done(void)
{
	int ret = 0;

	// return if no message handled
	if(_rx_state != UBX_RXMSG_HANDLE) {
		return ret;
	}

	// handle message
	switch(_rx_msg) {
		case UBX_MSG_NAV_PVT: {
			// struct gps_tm timeinfo;


			if((_buf.payload_rx_nav_pvt.flags & UBX_RX_NAV_PVT_FLAGS_GNSSFIXOK) == 1) {
				_gps_position.fix_type		 = _buf.payload_rx_nav_pvt.fixType;
				_gps_position.vel_ned_valid = 1;

			} else {
				_gps_position.fix_type		 = 0;
				_gps_position.vel_ned_valid = 0;
			}

			_gps_position.satellites_used	= _buf.payload_rx_nav_pvt.numSV;

			_gps_position.lat		= _buf.payload_rx_nav_pvt.lat;
			_gps_position.lon		= _buf.payload_rx_nav_pvt.lon;
			_gps_position.alt		= _buf.payload_rx_nav_pvt.hMSL;

			_gps_position.eph		= (float)_buf.payload_rx_nav_pvt.hAcc * 1e-3f;
			_gps_position.epv		= (float)_buf.payload_rx_nav_pvt.vAcc * 1e-3f;
			_gps_position.s_variance_m_s	= (float)_buf.payload_rx_nav_pvt.sAcc * 1e-3f;

			_gps_position.vel_m_s		= (float)_buf.payload_rx_nav_pvt.gSpeed * 1e-3f;

			_gps_position.vel_n_m_s	= (float)_buf.payload_rx_nav_pvt.velN * 1e-3f;
			_gps_position.vel_e_m_s	= (float)_buf.payload_rx_nav_pvt.velE * 1e-3f;
			_gps_position.vel_d_m_s	= (float)_buf.payload_rx_nav_pvt.velD * 1e-3f;

			_gps_position.cog_rad		= (float)_buf.payload_rx_nav_pvt.headMot * M_DEG_TO_RAD_F * 1e-5f;
			_gps_position.c_variance_rad	= (float)_buf.payload_rx_nav_pvt.headAcc * M_DEG_TO_RAD_F * 1e-5f;

			//Check if time and date fix flags are good
			if((_buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_VALIDDATE)
			        && (_buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_VALIDTIME)
			        && (_buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_FULLYRESOLVED)) {
				/* convert to unix timestamp */
				// timeinfo.tm_year	= _buf.payload_rx_nav_pvt.year - 1900;
				// timeinfo.tm_mon		= _buf.payload_rx_nav_pvt.month - 1;
				// timeinfo.tm_mday	= _buf.payload_rx_nav_pvt.day;
				// timeinfo.tm_hour	= _buf.payload_rx_nav_pvt.hour;
				// timeinfo.tm_min		= _buf.payload_rx_nav_pvt.min;
				// timeinfo.tm_sec		= _buf.payload_rx_nav_pvt.sec;

				//_gps_position.time_utc_usec = 0;
			}

			_gps_position.timestamp_time		= systime_now_ms();
			_gps_position.timestamp_velocity 	= systime_now_ms();
			_gps_position.timestamp_variance 	= systime_now_ms();
			_gps_position.timestamp_position	= systime_now_ms();

			_rate_count_vel++;
			_rate_count_lat_lon++;

			_got_posllh = RT_TRUE;
			_got_velned = RT_TRUE;

			ret = 1;
		}
		break;

		case UBX_MSG_NAV_POSLLH: {
			//console_printf("Rx NAV-POSLLH\r\n");

			_gps_position.lat	= _buf.payload_rx_nav_posllh.lat;
			_gps_position.lon	= _buf.payload_rx_nav_posllh.lon;
			_gps_position.alt	= _buf.payload_rx_nav_posllh.hMSL;
			_gps_position.eph	= (float)_buf.payload_rx_nav_posllh.hAcc * 1e-3f; // from mm to m
			_gps_position.epv	= (float)_buf.payload_rx_nav_posllh.vAcc * 1e-3f; // from mm to m
			_gps_position.alt_ellipsoid = _buf.payload_rx_nav_posllh.height;

			_gps_position.timestamp_position = systime_now_ms();

			_rate_count_lat_lon++;
			_got_posllh = RT_TRUE;

			//console_printf("alt:%d lat:%d lon:%d\r\n" , _gps_position.alt, _gps_position.lat,_gps_position.lon);

			ret = 1;
		}
		break;

		case UBX_MSG_NAV_SOL: {
			//console_printf("Rx NAV-SOL\r\n");

			_gps_position.fix_type		= _buf.payload_rx_nav_sol.gpsFix;
			_gps_position.s_variance_m_s	= (float)_buf.payload_rx_nav_sol.sAcc * 1e-2f;	// from cm to m
			_gps_position.satellites_used	= _buf.payload_rx_nav_sol.numSV;

			_gps_position.timestamp_variance = systime_now_ms();
		}
		break;

		case UBX_MSG_NAV_DOP: {
			//console_printf("Rx NAV-DOP\r\n");

			_gps_position.hdop		= _buf.payload_rx_nav_dop.hDOP * 0.01f;	// from cm to m
			_gps_position.vdop		= _buf.payload_rx_nav_dop.vDOP * 0.01f;	// from cm to m
			_gps_position.tdop		= _buf.payload_rx_nav_dop.tDOP * 0.01f;	// from cm to m
			_gps_position.ndop		= _buf.payload_rx_nav_dop.nDOP * 0.01f;	// from cm to m
			_gps_position.edop		= _buf.payload_rx_nav_dop.eDOP * 0.01f;	// from cm to m

			_gps_position.timestamp_variance = systime_now_ms();

			ret = 1;
		}
		break;

		case UBX_MSG_NAV_TIMEUTC: {
			//console_printf("Rx NAV-TIMEUTC\r\n");

			if(_buf.payload_rx_nav_timeutc.valid & UBX_RX_NAV_TIMEUTC_VALID_VALIDUTC) {
				// convert to unix timestamp
				// struct gps_tm timeinfo;
				// timeinfo.tm_year	= _buf.payload_rx_nav_timeutc.year - 1900;
				// timeinfo.tm_mon		= _buf.payload_rx_nav_timeutc.month - 1;
				// timeinfo.tm_mday	= _buf.payload_rx_nav_timeutc.day;
				// timeinfo.tm_hour	= _buf.payload_rx_nav_timeutc.hour;
				// timeinfo.tm_min		= _buf.payload_rx_nav_timeutc.min;
				// timeinfo.tm_sec		= _buf.payload_rx_nav_timeutc.sec;

				//_gps_position.time_utc_usec = 0;
				//console_printf("%d-%d-%d %d:%d:%d\r\n" , timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday,timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec);
			}

			_gps_position.timestamp_time = systime_now_ms();

			ret = 1;
		}
		break;

		case UBX_MSG_NAV_SVINFO: {
			//console_printf("Rx NAV-SVINFO\r\n");
			// _satellite_info already populated by payload_rx_add_svinfo(), just add a timestamp
			_satellite_info.timestamp = systime_now_us();

			_got_svinfo = RT_TRUE;

			ret = 2;
		}
		break;

		case UBX_MSG_NAV_VELNED: {
			//console_printf("Rx NAV-VELNED\r\n");

			_gps_position.vel_m_s		= (float)_buf.payload_rx_nav_velned.speed * 1e-2f;
			_gps_position.vel_n_m_s	= (float)_buf.payload_rx_nav_velned.velN * 1e-2f; /* NED NORTH velocity */
			_gps_position.vel_e_m_s	= (float)_buf.payload_rx_nav_velned.velE * 1e-2f; /* NED EAST velocity */
			_gps_position.vel_d_m_s	= (float)_buf.payload_rx_nav_velned.velD * 1e-2f; /* NED DOWN velocity */
			_gps_position.cog_rad		= (float)_buf.payload_rx_nav_velned.heading * M_DEG_TO_RAD_F * 1e-5f;
			_gps_position.c_variance_rad	= (float)_buf.payload_rx_nav_velned.cAcc * M_DEG_TO_RAD_F * 1e-5f;
			_gps_position.vel_ned_valid	= 1;

			_gps_position.timestamp_velocity = systime_now_ms();

			_rate_count_vel++;
			_got_velned = RT_TRUE;

			//console_printf("nV:%.2f eV:%.2f dV:%.2f" , _gps_position.vel_n_m_s,_gps_position.vel_e_m_s,_gps_position.vel_d_m_s);

			ret = 1;
		}
		break;

		case UBX_MSG_MON_VER: {
			//console_printf("Rx MON-VER\r\n");
		} break;

		case UBX_MSG_MON_HW: {
			//console_printf("Rx MON-HW\r\n");

			switch(_rx_payload_length) {
				case sizeof(ubx_payload_rx_mon_hw_ubx6_t):	/* u-blox 6 msg format */
					_gps_position.noise_per_ms		= _buf.payload_rx_mon_hw_ubx6.noisePerMS;
					_gps_position.jamming_indicator	= _buf.payload_rx_mon_hw_ubx6.jamInd;

					ret = 1;
					break;

				case sizeof(ubx_payload_rx_mon_hw_ubx7_t):	/* u-blox 7+ msg format */
					_gps_position.noise_per_ms		= _buf.payload_rx_mon_hw_ubx7.noisePerMS;
					_gps_position.jamming_indicator	= _buf.payload_rx_mon_hw_ubx7.jamInd;

					ret = 1;
					break;

				default:		// unexpected payload size:
					ret = 0;	// don't handle message
					break;
			}
		}
		break;

		case UBX_MSG_ACK_ACK: {
			//console_printf("Rx ACK-ACK\r\n");

			if((_ack_state == UBX_ACK_WAITING) && (_buf.payload_rx_ack_ack.msg == _ack_waiting_msg)) {
				_ack_state = UBX_ACK_GOT_ACK;
			}

			ret = 1;
		}
		break;

		case UBX_MSG_ACK_NAK: {
			//console_printf("Rx ACK-NAK\r\n");

			if((_ack_state == UBX_ACK_WAITING) && (_buf.payload_rx_ack_ack.msg == _ack_waiting_msg)) {
				_ack_state = UBX_ACK_GOT_NAK;
			}

			ret = 1;
		}
		break;

		default:
			break;
	}

	return ret;
}

int	// -1 = abort, 0 = continue
_payload_rx_init()
{
	int ret = 0;

	_rx_state = UBX_RXMSG_HANDLE;	// handle by default

	switch(_rx_msg) {
		case UBX_MSG_NAV_PVT:
			if((_rx_payload_length != UBX_PAYLOAD_RX_NAV_PVT_SIZE_UBX7)		/* u-blox 7 msg format */
			        && (_rx_payload_length != UBX_PAYLOAD_RX_NAV_PVT_SIZE_UBX8)) {	/* u-blox 8+ msg format */
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else if(!_use_nav_pvt) {
				_rx_state = UBX_RXMSG_DISABLE;        // disable if not using NAV-PVT
			}

			break;

		case UBX_MSG_NAV_POSLLH:
			if(_rx_payload_length != sizeof(ubx_payload_rx_nav_posllh_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else if(_use_nav_pvt) {
				_rx_state = UBX_RXMSG_DISABLE;        // disable if using NAV-PVT instead
			}

			break;

		case UBX_MSG_NAV_SOL:
			if(_rx_payload_length != sizeof(ubx_payload_rx_nav_sol_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else if(_use_nav_pvt) {
				_rx_state = UBX_RXMSG_DISABLE;        // disable if using NAV-PVT instead
			}

			break;

		case UBX_MSG_NAV_DOP:
			if(_rx_payload_length != sizeof(ubx_payload_rx_nav_dop_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			}

			break;

		case UBX_MSG_NAV_TIMEUTC:
			if(_rx_payload_length != sizeof(ubx_payload_rx_nav_timeutc_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else if(_use_nav_pvt) {
				_rx_state = UBX_RXMSG_DISABLE;        // disable if using NAV-PVT instead
			}

			break;

		case UBX_MSG_NAV_SVINFO:
			if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else {
				memset(&_satellite_info, 0, sizeof(_satellite_info));        // initialize sat info
			}

			break;

		case UBX_MSG_NAV_VELNED:
			if(_rx_payload_length != sizeof(ubx_payload_rx_nav_velned_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured

			} else if(_use_nav_pvt) {
				_rx_state = UBX_RXMSG_DISABLE;        // disable if using NAV-PVT instead
			}

			break;

		case UBX_MSG_MON_VER:
			break;		// unconditionally handle this message

		case UBX_MSG_MON_HW:
			if((_rx_payload_length != sizeof(ubx_payload_rx_mon_hw_ubx6_t))	/* u-blox 6 msg format */
			        && (_rx_payload_length != sizeof(ubx_payload_rx_mon_hw_ubx7_t))) {	/* u-blox 7+ msg format */
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(!_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if not _configured
			}

			break;

		case UBX_MSG_ACK_ACK:
			if(_rx_payload_length != sizeof(ubx_payload_rx_ack_ack_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if _configured
			}

			break;

		case UBX_MSG_ACK_NAK:
			if(_rx_payload_length != sizeof(ubx_payload_rx_ack_nak_t)) {
				_rx_state = UBX_RXMSG_ERROR_LENGTH;

			} else if(_configured) {
				_rx_state = UBX_RXMSG_IGNORE;        // ignore if _configured
			}

			break;

		default:
			_rx_state = UBX_RXMSG_DISABLE;	// disable all other messages
			break;
	}

	switch(_rx_state) {
		case UBX_RXMSG_HANDLE:	// handle message
		case UBX_RXMSG_IGNORE:	// ignore message but don't report error
			ret = 0;
			break;

//	case UBX_RXMSG_DISABLE:	// disable unexpected messages
//		{
//			hrt_abstime t = hrt_absolute_time();

//			if (t > _disable_cmd_last + DISABLE_MSG_INTERVAL) {
//				/* don't attempt for every message to disable, some might not be disabled */
//				_disable_cmd_last = t;
//				configure_message_rate(_rx_msg, 0);
//			}
//		}

//		ret = -1;	// return error, abort handling this message
//		break;

		case UBX_RXMSG_ERROR_LENGTH:	// error: invalid length
			ret = -1;	// return error, abort handling this message
			break;

		default:	// invalid message state
			ret = -1;	// return error, abort handling this message
			break;
	}

	return ret;
}

int	// -1 = error, 0 = ok, 1 = payload completed
_payload_rx_add(const uint8_t b)
{
	int ret = 0;

	_buf.raw[_rx_payload_index] = b;

	if(++_rx_payload_index >= _rx_payload_length) {
		ret = 1;	// payload received completely
	}

	return ret;
}

int	// -1 = NAK, error or timeout, 0 = ACK
_wait_for_ack(const uint16_t msg, const uint32_t timeout)
{
	int ret = -1;

	_ack_state = UBX_ACK_WAITING;
	_ack_waiting_msg = msg;	// memorize sent msg class&ID for ACK check

	uint32_t time_started = systime_now_ms();

	while((_ack_state == UBX_ACK_WAITING) && (systime_now_ms() < time_started + timeout)) {;}

	if(_ack_state == UBX_ACK_GOT_ACK) {
		ret = 0;	// ACK received ok
	}

	_ack_state = UBX_ACK_IDLE;
	return ret;
}

int	// 0 = decoding, 1 = message handled, 2 = sat info message handled
_parse_ubx_char(const uint8_t c)
{
	int ret = 0;

	//console_printf("%x," , c);

	switch(_decode_state) {
		case UBX_DECODE_SYNC1: {
			if(c == UBX_SYNC1) {
				_decode_state = UBX_DECODE_SYNC2;
			}
		}
		break;

		case UBX_DECODE_SYNC2: {
			if(c == UBX_SYNC2) {	// Sync2 found --> expecting Class
				_decode_state = UBX_DECODE_CLASS;
			} else {		// Sync1 not followed by Sync2: reset parser
				_decode_init();
			}
		}
		break;

		case UBX_DECODE_CLASS: {
			_add_byte_to_checksum(c);  // checksum is calculated for everything except Sync and Checksum bytes
			_rx_msg = c;
			_decode_state = UBX_DECODE_ID;
		}
		break;

		case UBX_DECODE_ID: {
			_add_byte_to_checksum(c);
			_rx_msg |= c << 8;
			_decode_state = UBX_DECODE_LENGTH1;

			//console_printf("msg:%x\r\n" , _rx_msg);
//			if(_rx_msg == UBX_MSG_NAV_SVINFO && _configured == RT_FALSE)
//				_decode_init();	//if configuration is not finish, ignore SVINFO
		}
		break;

		case UBX_DECODE_LENGTH1: {
			_add_byte_to_checksum(c);
			_rx_payload_length = c;
			_decode_state = UBX_DECODE_LENGTH2;
		}
		break;

		case UBX_DECODE_LENGTH2: {
			_add_byte_to_checksum(c);
			_rx_payload_length |= c << 8;	// calculate payload size

			//if(_rx_msg == UBX_MSG_NAV_SVINFO)

			if(_payload_rx_init() != 0) {	// start payload reception
				// payload will not be handled, discard message
				_decode_init();

			} else {
				_decode_state = (_rx_payload_length > 0) ? UBX_DECODE_PAYLOAD : UBX_DECODE_CHKSUM1;
			}

			//console_printf("len:%d\r\n" , _rx_payload_length);
		}
		break;

		case UBX_DECODE_PAYLOAD: {
			_add_byte_to_checksum(c);

			switch(_rx_msg) {
				case UBX_MSG_NAV_SVINFO: {
					ret = payload_rx_add_nav_svinfo(c);	// add a NAV-SVINFO payload byte
				}
				break;

				case UBX_MSG_MON_VER: {
					ret = payload_rx_add_mon_ver(c);	// add a MON-VER payload byte
				}
				break;

				default: {
					ret = _payload_rx_add(c);		// add a payload byte
				}
				break;
			}

			//console_printf("payload ret:%d\r\n" , ret);
			if(ret < 0) {
				// payload not handled, discard message
				_decode_init();
			} else if(ret > 0) {
				// payload complete, expecting checksum
				_decode_state = UBX_DECODE_CHKSUM1;
			} else {
				// expecting more payload, stay in state UBX_DECODE_PAYLOAD
			}

			ret = 0;
		}
		break;

		case UBX_DECODE_CHKSUM1: {
			if(_rx_ck_a != c) {
				//console_printf("ubx checksum err\r\n");
				_decode_init();
			} else {
				_decode_state = UBX_DECODE_CHKSUM2;
			}
		}
		break;

		case UBX_DECODE_CHKSUM2: {
			//console_printf("check sum 2\r\n");
			if(_rx_ck_b != c) {
				console_printf("ubx checksum err\r\n");
			} else {
				ret = payload_rx_done();	// finish payload processing
			}

			_decode_init();
		}
		break;
	}

	//console_printf("state:%d %x\r\n" , _decode_state , c);

	return ret;
}

void _calc_ubx_checksum(const uint8_t* buffer, const uint16_t length, ubx_checksum_t* checksum)
{
	for(uint16_t i = 0; i < length; i++) {
		checksum->ck_a = checksum->ck_a + buffer[i];
		checksum->ck_b = checksum->ck_b + checksum->ck_a;
	}
}

void _send_ubx_msg(const uint16_t msg, const uint8_t* payload, const uint16_t length)
{
	ubx_header_t   header = {UBX_SYNC1, UBX_SYNC2};
	ubx_checksum_t checksum = {0, 0};

	// Populate header
	header.msg	= msg;
	header.length	= length;

	// Calculate checksum
	_calc_ubx_checksum(((uint8_t*)&header) + 2, sizeof(header) - 2, &checksum);  // skip 2 sync bytes

	if(payload != NULL) {
		_calc_ubx_checksum(payload, length, &checksum);
	}

	rt_device_write(serial_device, 0, (const void*)&header, sizeof(header));

	if(payload != NULL) {
		rt_device_write(serial_device, 0, (const void*)payload, length);
	}

	rt_device_write(serial_device, 0, (const void*)&checksum, sizeof(checksum));
}

void _configure_message_rate(const uint16_t msg, const uint8_t rate)
{
	ubx_payload_tx_cfg_msg_t cfg_msg;	// don't use _buf (allow interleaved operation)

	cfg_msg.msg	= msg;
	cfg_msg.rate	= rate;

	_send_ubx_msg(UBX_MSG_CFG_MSG, (uint8_t*)&cfg_msg, sizeof(cfg_msg));
}

int _configure_by_ubx(void)
{
	uint32_t baudrates[] = {9600, 19200, 38400, 57600, 115200};
	uint32_t baudrate;
	uint8_t i;

	_configured = RT_FALSE;

	for(i = 0 ; i < sizeof(baudrates) / sizeof(baudrates[0]) ; i++) {
		baudrate = baudrates[i];
		_set_baudrate(serial_device, baudrate);
		/* flush input and wait for at least 20 ms silence */
		_decode_init();
		systime_delay_ms(20);
		_decode_init();

		/* Send a CFG-PRT message to set the UBX protocol for in and out
		 * and leave the baudrate as it is, we just want an ACK-ACK for this */
		memset(&_buf.payload_tx_cfg_prt, 0, sizeof(_buf.payload_tx_cfg_prt));
		_buf.payload_tx_cfg_prt.portID		= UBX_TX_CFG_PRT_PORTID;
		_buf.payload_tx_cfg_prt.mode		= UBX_TX_CFG_PRT_MODE;
		_buf.payload_tx_cfg_prt.baudRate	= baudrate;
		_buf.payload_tx_cfg_prt.inProtoMask	= UBX_TX_CFG_PRT_INPROTOMASK;
		_buf.payload_tx_cfg_prt.outProtoMask	= UBX_TX_CFG_PRT_OUTPROTOMASK;

		_send_ubx_msg(UBX_MSG_CFG_PRT, _buf.raw, sizeof(_buf.payload_tx_cfg_prt));

		if(_wait_for_ack(UBX_MSG_CFG_PRT, 2 * UBX_CONFIG_TIMEOUT) < 0) {
			/* try next baudrate */
			continue;
		}

		/* Send a CFG-PRT message again, this time change the baudrate */
		memset(&_buf.payload_tx_cfg_prt, 0, sizeof(_buf.payload_tx_cfg_prt));
		_buf.payload_tx_cfg_prt.portID		= UBX_TX_CFG_PRT_PORTID;
		_buf.payload_tx_cfg_prt.mode		= UBX_TX_CFG_PRT_MODE;
		_buf.payload_tx_cfg_prt.baudRate	= UBX_TX_CFG_PRT_BAUDRATE;
		_buf.payload_tx_cfg_prt.inProtoMask	= UBX_TX_CFG_PRT_INPROTOMASK;
		_buf.payload_tx_cfg_prt.outProtoMask	= UBX_TX_CFG_PRT_OUTPROTOMASK;

		_send_ubx_msg(UBX_MSG_CFG_PRT, _buf.raw, sizeof(_buf.payload_tx_cfg_prt));

		/* no ACK is expected here, but read the buffer anyway in case we actually get an ACK */
		_wait_for_ack(UBX_MSG_CFG_PRT, UBX_CONFIG_TIMEOUT);

		if(UBX_TX_CFG_PRT_BAUDRATE != baudrate) {
			//console_printf("change gps baudrate from %d to %d\r\n" , baudrate, UBX_TX_CFG_PRT_BAUDRATE);
			_set_baudrate(serial_device, UBX_TX_CFG_PRT_BAUDRATE);
			baudrate = UBX_TX_CFG_PRT_BAUDRATE;
		}

		/* at this point we have correct baudrate on both ends */
		break;
	}

	if(i >= sizeof(baudrates) / sizeof(baudrates[0])) {
		//console_printf("gps connection and/or baudrate detection failed\r\n");
		return 1;	// connection and/or baudrate detection failed
	}

	/* Send a CFG-RATE message to define update rate */
	memset(&_buf.payload_tx_cfg_rate, 0, sizeof(_buf.payload_tx_cfg_rate));
	_buf.payload_tx_cfg_rate.measRate	= UBX_TX_CFG_RATE_MEASINTERVAL;
	_buf.payload_tx_cfg_rate.navRate	= UBX_TX_CFG_RATE_NAVRATE;
	_buf.payload_tx_cfg_rate.timeRef	= UBX_TX_CFG_RATE_TIMEREF;

	_send_ubx_msg(UBX_MSG_CFG_RATE, _buf.raw, sizeof(_buf.payload_tx_cfg_rate));

	if(_wait_for_ack(UBX_MSG_CFG_RATE, UBX_CONFIG_TIMEOUT) < 0) {
		return 1;
	}

	/* send a NAV5 message to set the options for the internal filter */
	memset(&_buf.payload_tx_cfg_nav5, 0, sizeof(_buf.payload_tx_cfg_nav5));
	_buf.payload_tx_cfg_nav5.mask		= UBX_TX_CFG_NAV5_MASK;
	_buf.payload_tx_cfg_nav5.dynModel	= UBX_TX_CFG_NAV5_DYNMODEL;
	_buf.payload_tx_cfg_nav5.fixMode	= UBX_TX_CFG_NAV5_FIXMODE;

	_send_ubx_msg(UBX_MSG_CFG_NAV5, _buf.raw, sizeof(_buf.payload_tx_cfg_nav5));

	if(_wait_for_ack(UBX_MSG_CFG_NAV5, UBX_CONFIG_TIMEOUT) < 0) {
		return 1;
	}

	/* configure message rates */
	/* the last argument is divisor for measurement rate (set by CFG RATE), i.e. 1 means 10Hz */

	/* try to set rate for NAV-PVT */
	/* (implemented for ubx7+ modules only, use NAV-SOL, NAV-POSLLH, NAV-VELNED and NAV-TIMEUTC for ubx6) */
	_configure_message_rate(UBX_MSG_NAV_PVT, 1);

	if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
		_use_nav_pvt = RT_FALSE;

	} else {
		_use_nav_pvt = RT_TRUE;
	}

	if(!_use_nav_pvt) {
		_configure_message_rate(UBX_MSG_NAV_TIMEUTC, 5);

		if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
			console_printf("UBX_MSG_NAV_TIMEUTC configure fail!\n");
			return 1;
		}

		_configure_message_rate(UBX_MSG_NAV_POSLLH, 1);

		if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
			console_printf("UBX_MSG_CFG_MSG configure fail!\n");
			return 1;
		}

		_configure_message_rate(UBX_MSG_NAV_SOL, 1);

		if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
			console_printf("UBX_MSG_NAV_SOL configure fail!\n");
			return 1;
		}

		_configure_message_rate(UBX_MSG_NAV_VELNED, 1);

		if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
			console_printf("UBX_MSG_NAV_VELNED configure fail!\n");
			return 1;
		}
	}

	_configure_message_rate(UBX_MSG_NAV_DOP, 1);

	if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
		return 1;
	}

	_configure_message_rate(UBX_MSG_NAV_SVINFO, 5);

	if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
		return 1;
	}

	_configure_message_rate(UBX_MSG_MON_HW, 1);

	if(_wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
		return 1;
	}

	/* request module version information by sending an empty MON-VER message */
	_send_ubx_msg(UBX_MSG_MON_VER, NULL, 0);

	_configured = RT_TRUE;

	return 0;
}

static rt_err_t gps_serial_rx_ind(rt_device_t dev, rt_size_t size)
{
	rt_size_t bytes;
	uint8_t ch[SERIAL_RB_BUFSZ];

	bytes = rt_device_read(serial_device, 0, ch, size);

	if(bytes) {
		for(uint32_t j = 0 ; j < bytes ; j++) {
			//console_printf("%x," , ch[j]);
			_parse_ubx_char(ch[j]);
		}
	} else {
		console_printf("ubx listen err:%ld\r\n", bytes);
	}

	return RT_EOK;
}

rt_err_t gps_init(rt_device_t dev)
{
	_configured = RT_FALSE;
	_use_nav_pvt = RT_FALSE;
	_ack_state = UBX_ACK_IDLE;
	_ack_waiting_msg = 0;
	_got_posllh = RT_FALSE;
	_got_velned = RT_FALSE;
	_got_svinfo = RT_FALSE;

	rt_device_set_rx_indicate(serial_device, gps_serial_rx_ind);
	rt_device_open(serial_device, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);

	for(uint8_t i = 0 ; i < CONFIGURE_RETRY_MAX ; i++) {
		if(_configure_by_ubx() == 0) {
			// gps configuration success
			return RT_EOK;
		}
	}

	// gps configuration fail
	//return RT_ERROR;
//	//TODO:
	return RT_EOK;
}

rt_size_t gps_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
	if(pos == RD_ONLY_POSLLH) {
		if(_got_posllh == RT_FALSE)
			return 0;

		if(buffer != NULL)
			*(struct vehicle_gps_position_s*)buffer = _gps_position;

		_got_posllh = RT_FALSE;
	} else if(pos == RD_ONLY_VELNED) {
		if(_got_velned == RT_FALSE)
			return 0;

		if(buffer != NULL)
			*(struct vehicle_gps_position_s*)buffer = _gps_position;

		_got_velned = RT_FALSE;
	} else if(pos == RD_COMPLETED_REPORT) {
		if(_got_posllh == RT_FALSE || _got_velned == RT_FALSE)
			return 0;

		if(buffer != NULL)
			*(struct vehicle_gps_position_s*)buffer = _gps_position;

		_got_posllh = RT_FALSE;
		_got_velned = RT_FALSE;
	} else if(pos == RD_SVINFO) {
		if(_got_svinfo == RT_FALSE)
			return 0;

		if(buffer != NULL)
			*(struct satellite_info_s*)buffer = _satellite_info;

		_got_svinfo = RT_FALSE;
	} else if(pos == GPS_REPORT_READY) {
		*(uint8_t*)buffer = (_got_posllh && _got_posllh) ? 1 : 0;
	} else {
		return 0;
	}


	return size;
}

rt_err_t drv_gps_init(char* serial_device_name)
{
	rt_err_t res = RT_EOK;

	/* set device type */
	gps_device.type    = RT_Device_Class_Char;
	gps_device.init    = gps_init;
	gps_device.open    = RT_NULL;
	gps_device.close   = RT_NULL;
	gps_device.read    = gps_read;
	gps_device.write   = RT_NULL;
	gps_device.control = RT_NULL;

	/* register to device manager */
	res |= rt_device_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR);

	serial_device = rt_device_find(serial_device_name);

	if(serial_device == RT_NULL) {
		return RT_EEMPTY;
	}

	return res;
}
