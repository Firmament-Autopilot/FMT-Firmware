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
from .oem_reqs_validator_pse8x import OemReqsValidatorPse8x
from ...common.mxs22.dependency_validator_mxs22 import DependencyValidatorMXS22


class AdvancedValidatorPse8x(DependencyValidatorMXS22):
    """Validates policy dependencies for E8x device"""

    def __init__(self, parser):
        super().__init__(parser)
        self.validators['pre_build'].append(OemReqsValidatorPse8x)

    def validate(self, skip_list=None, **kwargs):
        if kwargs.get('ifx_oem_cert') is None:
            if OemReqsValidatorPse8x in self.validators['pre_build']:
                self.validators['pre_build'].remove(OemReqsValidatorPse8x)
        return super().validate(skip_list, **kwargs)
