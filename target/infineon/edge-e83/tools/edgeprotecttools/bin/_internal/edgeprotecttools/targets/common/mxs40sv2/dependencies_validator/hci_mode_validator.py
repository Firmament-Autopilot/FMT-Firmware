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
from ..enums import PolicyType
from ...mxs40sv2 import asset_enums as enums
from .....core.dependecy_validator import DependencyValidator


class HciModeValidator(DependencyValidator):
    """Dependencies validator for HCI mode settings"""

    def validate(self, **_kwargs):
        """Validates dependencies between policy properties"""
        _pp = self.parser

        policy_type = _pp.policy_type()

        if policy_type == PolicyType.HCI_SECURE:
            dead_cm33 = _pp.get_dead_cm33_permission()
            cm33 = _pp.get_cm33_permission()
            smif = _pp.get_smif_configuration()
            lifecycle = _pp.get_target_lcs()

            if dead_cm33 != enums.ApPermission['Permanently Disable']:
                self.add_msg('For the HCI mode CM33 AP must be '
                             '"Permanently Disable" for DEAD branch')

            if cm33 == enums.ApPermission['Enable']:
                self.add_msg('For the HCI mode CM33 AP must be "Disabled"')

            if smif != enums.SMIFConfiguation['HCI mode']:
                self.add_msg('For the HCI mode smif configuration '
                             'must be "HCI mode"')

            if lifecycle not in (enums.LifecycleStage['SECURE'],
                                 enums.LifecycleStage['NORMAL']):
                self.add_msg('For the HCI mode target_lcs must be "SECURE"'
                             ' or "NORMAL"')
