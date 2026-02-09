"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from typing import Union

from ..asset_enums import (FlashWounding, SramWounding, TcpwmWounding,
                           ProvIcvControlWord)
from ...common.policy_parser_primitives import PolicyParserPrimitives


class PolicyParserProvIcv(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def prov_icv_control_word(self, ret_value=False) -> Union[ProvIcvControlWord,
                                                              int]:
        """Gets a value of the 'control_word.value' property"""
        return self.enum_field(ProvIcvControlWord, ret_value, 'control_word',
                               'value')

    def wound_can(self, ret_value=False) -> Union[int, bool]:
        """Gets a value of the 'wounding.can.value' property"""
        value = self.field('wounding', 'can', 'value')
        return 1 - int(value) if ret_value else value

    def wound_flash(self, ret_value=False) -> Union[FlashWounding, int]:
        """Gets a value of the 'wounding.flash.value' property"""
        return self.enum_field(FlashWounding, ret_value, 'wounding', 'flash',
                               'value')

    def wound_sram(self, ret_value=False) -> Union[SramWounding, int]:
        """Gets a value of the 'wounding.sram.value' property"""
        return self.enum_field(SramWounding, ret_value, 'wounding', 'sram',
                               'value')

    def wound_tcpwm(self, ret_value=False) -> Union[TcpwmWounding, int]:
        """Gets a value of the 'wounding.tcpwm.value' property"""
        return self.enum_field(TcpwmWounding, ret_value, 'wounding', 'tcpwm',
                               'value')

    def wound_pass(self, ret_value=False) -> Union[int, bool]:
        """Gets a value of the 'wounding.pass.value' property"""
        value = self.field('wounding', 'pass', 'value')
        return 1 - int(value) if ret_value else value

    def wound_cordic(self, ret_value=False) -> Union[int, bool]:
        """Gets a value of the 'wounding.cordic.value' property"""
        value = self.field('wounding', 'cordic', 'value')
        return 1 - int(value) if ret_value else value

    def wound_sram_repaired(self, ret_value=False) -> Union[int, bool]:
        """Gets a value of the 'wounding.sram_repaired.value' property"""
        value = self.field('wounding', 'sram_repaired', 'value')
        return int(value) if ret_value else value

    def wound_speed(self, ret_value=False) -> Union[int, bool]:
        """Gets a value of the 'wounding.speed.value' property"""
        value = self.field('wounding', 'speed', 'value')
        return int(value) if ret_value else value
