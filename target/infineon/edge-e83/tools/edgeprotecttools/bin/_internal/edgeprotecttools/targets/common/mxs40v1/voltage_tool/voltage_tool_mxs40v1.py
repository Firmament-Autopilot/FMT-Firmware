"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .lvd_voltage_picker import LvdVoltagePicker
from .....core.target_director import Target
from .....core.voltage_tool import VoltageTool

logger = logging.getLogger(__name__)


class VoltageToolMXS40v1(VoltageTool, LvdVoltagePicker):
    """ Implementation of reading voltage for MXS40v1 platform """

    def __init__(self, target: Target, **kwargs):
        VoltageTool.__init__(self, target, **kwargs)
        LvdVoltagePicker.__init__(self, target, **kwargs)

    @property
    def voltage_level(self):
        return self.get_voltage_level()

    def get_voltage(self, tool):
        return self.get_lvd_voltage(tool)
