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
from ....core.dependecy_validator import DependencyValidator


class MpcValidator(DependencyValidator):
    """MPC policy validation"""

    sect = 'MPC policy configuration'

    def validate(self, **_kwargs):
        """Validates RAM and Flash MPC policy"""
        _pp = self.parser

        if _pp.n_ram_mpc() + _pp.n_flash_mpc() > 32:
            self.add_msg(f"{self.sect}: the maximum total number of "
                         "RAM and Flash MPC structures must be 32")

        mpc_ram = _pp.mpc_struct_ram()
        if mpc_ram:
            self.sect = 'RAM MPC policy configuration'
            for item in _pp.mpc_struct_ram():
                self.validate_region('offset', item.get('offset'))
                self.validate_region('size', item.get('size'))
                self.validate_attr(item.get('attr'))

        mpc_flash = _pp.mpc_struct_flash()
        if mpc_flash:
            self.sect = 'Flash MPC policy configuration'
            for item in _pp.mpc_struct_flash():
                self.validate_region('offset', item.get('offset'))
                self.validate_region('size', item.get('size'))
                self.validate_attr(item.get('attr'))

    def validate_region(self, name, value):
        """Validates MPC offset and size"""
        if 'KB' in value.upper():
            try:
                value_kb = int(value.upper().replace('KB', ''), 0)
            except ValueError:
                self.add_msg(f"{self.sect}: invalid '{name}' value '{value}'")
            else:
                if value_kb % 2 != 0:
                    self.add_msg(f"{self.sect}: '{name}' must be multiple of 2")
        else:
            self.add_msg(
                f"{self.sect}: '{name}' value must be in KB (e.g. 2 KB)")

    def validate_attr(self, attr):
        """Validates MPC attributes"""
        for idx in range(8):
            pc = attr.get('value').get(f'pc{idx}')
            if (pc[0] not in ('W', '-') or
                    pc[1] not in ('R', '-') or
                    pc[2] not in ('N', '-')):
                self.add_msg(f"{self.sect}: wrong 'pc{idx}' format: '{pc}'")
