"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from ....core.bitops import get_bits

logger = logging.getLogger(__name__)


class SiliconDataReaderMXS40Sv2:
    """ Implements reading data from the devices on MXS40Sv2 platform """

    def __init__(self, target):
        self.target = target

    def read_die_id(self, tool):
        """ Reads device die ID """
        efuses_enabled = self._efuses_enabled(tool)
        if not efuses_enabled:
            self._enable_efuses(tool)

        die_id_0 = tool.read32(self.target.register_map.EFUSE_DIE_ID_0)
        die_id_1 = tool.read32(self.target.register_map.EFUSE_DIE_ID_1)
        die_id_2 = tool.read32(self.target.register_map.EFUSE_DIE_ID_2)

        if not efuses_enabled:
            self._disable_efuses(tool)

        fld = {
            'lot': {'mask': 0x00ffffff, 'offset': 0, 'val': die_id_0},
            'wafer': {'mask': 0xff000000, 'offset': 24, 'val': die_id_0},

            'x': {'mask': 0x000000ff, 'offset': 0, 'val': die_id_1},
            'y': {'mask': 0x0000ff00, 'offset': 8, 'val': die_id_1},
            'sort': {'mask': 0x00ff0000, 'offset': 16, 'val': die_id_1},
            'day': {'mask': 0xff000000, 'offset': 24, 'val': die_id_1},

            'month': {'mask': 0x000000ff, 'offset': 0, 'val': die_id_2},
            'year': {'mask': 0x0000ff00, 'offset': 8, 'val': die_id_2},
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
        try:
            efuses_enabled = self._efuses_enabled(tool)
            if not efuses_enabled:
                self._enable_efuses(tool)

            device_id = tool.read32(self.target.register_map.EFUSE_DEVICE_ID)
            die_2 = tool.read32(self.target.register_map.EFUSE_DIE_ID_2)

            if not efuses_enabled:
                self._disable_efuses(tool)
        except RuntimeError as e:
            logger.error(e)
        else:
            silicon_id = get_bits(device_id, 0, 15)
            family_id = get_bits(device_id, 16, 27)
            revision_id = get_bits(die_2, 16, 23)
            DeviceInfo = namedtuple(
                'DeviceInfo', 'silicon_id silicon_rev family_id')
            dev_info = DeviceInfo(silicon_id, revision_id, family_id)
        return dev_info

    def _efuses_enabled(self, tool):
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        return efuse_ctl & 0x80000000 == 0x80000000

    def _enable_efuses(self, tool):
        """ Enables reading data from eFuses """
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        tool.write32(self.target.register_map.EFUSE_CTRL_ADDR,
                     efuse_ctl | 0x80000000)

    def _disable_efuses(self, tool):
        """ Disables reading data from eFuses """
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        tool.write32(self.target.register_map.EFUSE_CTRL_ADDR,
                     efuse_ctl & 0x7FFFFFFF)
