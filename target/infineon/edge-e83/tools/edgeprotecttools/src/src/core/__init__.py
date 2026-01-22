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
from .policy_filter_base import PolicyFilterBase
from .policy_validator_base import PolicyValidatorBase
from .policy_parser_base import PolicyParserBase
from .register_map_base import RegisterMapBaseP64, RegisterMapBaseMXS40Sv2
from .memory_map_base import MemoryMapBaseP64, MemoryMapBaseCYW20829
from .target_builder import TargetBuilder
from .memory_area import MemoryArea
from .key_data import KeyData
from .ocd_settings import OcdSettings


def package_name():
    return __name__.rpartition('.')[0] if '.' in __name__ else None
