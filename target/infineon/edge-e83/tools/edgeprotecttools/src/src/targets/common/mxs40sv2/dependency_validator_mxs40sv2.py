"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from .dependencies_validator import (
    AccessRestrictionsValidator, EncryptionAndProgramOemKey1Validator,
    HciModeValidator, NvCounterValidator, PreBuildKeysExistValidator,
    RevocationAndEncryptionValidator
)
from ..dependencies_validation import DependenciesValidatorRunner


class DependencyValidatorMXS40Sv2(DependenciesValidatorRunner):
    """Validates policy dependencies for mxs40v2 platform"""

    validators = {
        'pre_build': [
            PreBuildKeysExistValidator,
            HciModeValidator,
            EncryptionAndProgramOemKey1Validator,
            RevocationAndEncryptionValidator,
            AccessRestrictionsValidator,
            NvCounterValidator
        ]
    }

    def __init__(self, parser):
        super().__init__(parser, self.validators)
