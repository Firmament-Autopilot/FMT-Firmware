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

#include "task/task_comm.h"
#include "module/mavproxy/mavlink_status.h"

static const mav_status_t mav_status[MAV_NOTICE_NUM] = {
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration started: 2 gyro"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration started: 2 accel"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration started: 2 mag"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration started: 2 level"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration done:"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] calibration failed:"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <0>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <10>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <20>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <30>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <40>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <50>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <60>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <70>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <80>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <90>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] progress <100>"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] up orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] down orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] left orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] right orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] front orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] back orientation detected"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] up side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] down side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] left side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] right side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] front side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "[cal] back side done, rotate to a different side"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Welcome to use the StarryPilot!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Initialization Start:"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Initialization finish! The Drone is ready to fly!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Sensor heating Start:"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Sensor heating Finish!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Sensor heating is Disable!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Sensor check start:"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Sensor check error!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Sensor check finish!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Gyro sensor undetected!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Gyro sensor uncalibrated!"
	},
	{
		.severity = MAV_SEVERITY_WARNING,
		.string  = "Gyro sensor is need to calibrate!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Gyro sensor is OK!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Accel sensor uncalibrated!"
	},
	{
		.severity = MAV_SEVERITY_WARNING,
		.string  = "Accel sensor is need to calibrate!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Accel sensor is OK!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Mag sensor undetected!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Mag sensor uncalibrated!"
	},
	{
		.severity = MAV_SEVERITY_WARNING,
		.string  = "Mag sensor is need to calibrate!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Mag sensor is OK!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "Baro sensor undetected!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "Baro sensor is OK!"
	},
	{
		.severity = MAV_SEVERITY_ERROR,
		.string  = "GPS undetected!"
	},
	{
		.severity = MAV_SEVERITY_INFO,
		.string  = "GPS is OK!"
	},
};

mav_status_t mavlink_get_status_content(uint8_t status)
{
	return mav_status[status];
}

