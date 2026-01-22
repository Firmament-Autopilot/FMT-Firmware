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
from ...mxs40sv2 import asset_enums as enums
from .....core.dependecy_validator import DependencyValidator


class AccessRestrictionsValidator(DependencyValidator):
    def validate(self, **_kwargs):

        def verify():
            if mpc_ppc_permission == enums.MpcPpcPermission['Disable']:
                if sram_region != enums.SRAMPart['Entire region'] or \
                        mmio_region != enums.MMIOPart['All']:
                    self.add_msg(
                        'Enable MPC and PPC protection to apply SRAM and/or '
                        'MMIO access restrictions')
            if mpc_ppc_permission == enums.MpcPpcPermission['Enable']:
                if sram_region == enums.SRAMPart['Entire region'] and \
                        mmio_region == enums.MMIOPart['All']:
                    self.add_msg(
                        'Enabling MPC and PPC protection requires configuring '
                        'SRAM and/or MMIO access restrictions')

        _pp = self.parser

        mpc_ppc_permission = _pp.get_mpc_ppc_permission()
        sram_region = _pp.get_sram_region()
        mmio_region = _pp.get_mmio_region()

        verify()

        mpc_ppc_permission = _pp.get_dead_mpc_ppc_permission()
        sram_region = _pp.get_dead_sram_region()
        mmio_region = _pp.get_dead_mmio_region()

        verify()
