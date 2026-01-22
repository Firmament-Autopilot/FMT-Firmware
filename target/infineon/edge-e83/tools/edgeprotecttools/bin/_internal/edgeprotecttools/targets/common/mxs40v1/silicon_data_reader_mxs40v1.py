"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
import logging
from collections import namedtuple

from .provisioning import provision_device_mxs40v1
from .silicon_data_parser import SiliconDataParser
from ....execute import jwt

logger = logging.getLogger(__name__)


class SiliconDataReaderMXS40v1:
    def __init__(self, target):
        self.target = target

    def read_die_id(self, tool):
        data = provision_device_mxs40v1.read_silicon_data(tool, self.target)
        if data is None:
            logger.error('Failed to read silicon data')
            return None
        parser = SiliconDataParser(data)
        try:
            die_id = parser.get_die_id()
        except KeyError:
            logger.error('Invalid response. \'die_id\' field not found')
        return die_id

    def read_complete_status(self, tool):
        data = provision_device_mxs40v1.read_silicon_data(tool, self.target)
        if data is None:
            logger.error('Failed to read silicon data')
            return None
        parser = SiliconDataParser(data)
        try:
            complete = parser.get_complete_status()
        except KeyError:
            logger.error('Invalid response. \'complete\' field not found')
        return complete

    def read_device_info(self, tool):
        jwt_text = jwt.read_jwt(self.target.entrance_exam.entrance_exam_jwt)
        json_data = jwt.readable_jwt(jwt_text)
        payload = json_data['payload']
        silicon_id = None
        silicon_rev = None
        family_id = None
        for item in payload['ahb_reads']:
            if item['description'].startswith('SI_ID'):
                address = int(item['address'], 0)
                silicon_id = tool.read32(address) >> 16 & 0xFFFF
                silicon_rev = tool.read32(address) >> 8 & 0xFF
            if item['description'].startswith('FAMILY_ID'):
                address = int(item['address'], 0)
                mask = int(item['mask'], 0)
                family_id = tool.read32(address) & mask
            if silicon_id and silicon_rev and family_id:
                break

        DeviceInfo = namedtuple('DeviceInfo',
                                'silicon_id silicon_rev family_id')
        dev_info = DeviceInfo(silicon_id, silicon_rev, family_id)
        return dev_info
