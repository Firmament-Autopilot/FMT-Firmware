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
from .base import ProgrammerBase
from .chipload_wrapper import ChipLoad
from .openocd_wrapper import Openocd
from .dfuht_wrapper import Dfuht
from ...core import OcdSettings

tools = {
    'openocd': Openocd,
    'serial': Dfuht,
    'chipload': ChipLoad
}


class ProgrammingTool:
    """Implements a factory method for creating OCD wrapper objects
    without specifying their concrete classes
    """

    @staticmethod
    def create(name, settings: OcdSettings = None) -> ProgrammerBase:
        """ Creates an instance of the on-chip debugger wrapper """
        tool_type = tools[name]
        tool = tool_type(name, settings)
        return tool
