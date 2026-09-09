"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from ...core.bitops import get_bits

logger = logging.getLogger(__name__)


class SiliconDataReaderPsocC3:
    """ Implements reading data from the devices on PSOC C3 platform """

    def __init__(self, target):
        self.target = target

    def read_die_id(self, tool):
        """ Reads device die ID """
        die_id = None
        die_id_0 = die_id_1 = die_id_2 = None
        mem_map = self.target.memory_map
        for offset in (mem_map.SFLASH_OFFSET_0, mem_map.SFLASH_OFFSET_1):
            try:
                die_id_0 = tool.read32(mem_map.SFLASH_DIE_ID_0 + offset)
                die_id_1 = tool.read32(mem_map.SFLASH_DIE_ID_1 + offset)
                die_id_2 = tool.read32(mem_map.SFLASH_DIE_ID_2 + offset)
                if any((die_id_0, die_id_1, die_id_2)):
                    break
            except RuntimeError:
                pass
        else:
            if all(x is None for x in (die_id_0, die_id_1, die_id_2)):
                logger.error('Failed to read die id')
                return die_id

        fld = {
            'lot': {'mask': 0x00ffffff, 'offset': 0, 'val': die_id_0},
            'wafer': {'mask': 0xff000000, 'offset': 24, 'val': die_id_0},

            'x': {'mask': 0x000000ff, 'offset': 0, 'val': die_id_1},
            'y': {'mask': 0x0000ff00, 'offset': 8, 'val': die_id_1},
            'sort': {'mask': 0x00070000, 'offset': 16, 'val': die_id_1},

            'day': {'mask': 0x000000ff, 'offset': 0, 'val': die_id_2},
            'month': {'mask': 0x0000ff00, 'offset': 8, 'val': die_id_2},
            'year': {'mask': 0x00ff0000, 'offset': 16, 'val': die_id_2},
        }
        die_id = {k: (v['val'] & v['mask']) >> v['offset']
                  for (k, v) in fld.items()}
        return die_id

    def read_lifecycle_stage(self, tool):
        """ Reads device lifecycle stage """
        return tool.read32(self.target.register_map.BOOTROW)

    def read_device_info(self, tool):
        """ Reads silicon ID, revision ID, family ID from the device """
        dev_info = None
        device_id_0 = device_id_1 = None
        mem_map = self.target.memory_map
        for offset in (mem_map.SFLASH_OFFSET_0, mem_map.SFLASH_OFFSET_1):
            try:
                device_id_0 = tool.read32(mem_map.SFLASH_DEVICE_ID_0 + offset)
                device_id_1 = tool.read32(mem_map.SFLASH_DEVICE_ID_1 + offset)
                if any((device_id_0, device_id_1)):
                    break
            except RuntimeError:
                pass
        else:
            if all(x is None for x in (device_id_0, device_id_1)):
                logger.error('Failed to read device info')
                return dev_info

        revision_id = get_bits(device_id_0, 8, 15)
        silicon_id = get_bits(device_id_0, 16, 31)
        family_id = get_bits(device_id_1, 0, 15)
        DeviceInfo = namedtuple(
            'DeviceInfo', 'silicon_id silicon_rev family_id')
        dev_info = DeviceInfo(silicon_id, revision_id, family_id)
        return dev_info
