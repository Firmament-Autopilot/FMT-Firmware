"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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
from typing import Tuple, List

from .symbol_file import SymbolFile


class SymbolAdapter:
    """
    Extracting variable interpolation data from symbol information file
    objects and adapting it for use in variable interpolation.
    """
    @staticmethod
    def adapt(sources: List[SymbolFile]) -> Tuple[Tuple[str, str], ...]:
        """
        Extracts a tuple of (name, value) pairs for variable
        interpolation from a list of SymbolFile objects.
        Raises KeyError if duplicate keys are found.
        """
        result = []
        seen = set()
        for sf in sources:
            if isinstance(sf, SymbolFile):
                for k, v in sf.get_symbols():
                    if k in seen:
                        raise KeyError(f"Duplicate symbol key found: '{k}'")
                    seen.add(k)
                    result.append((k, v))
        return tuple(result)

    @staticmethod
    def merge(a: Tuple[Tuple[str, str], ...],
              b: Tuple[Tuple[str, str], ...]) -> Tuple[Tuple[str, str], ...]:
        """
        Merges two tuples of (key, value) pairs, ensuring no duplicate keys.
        Raises KeyError if duplicate keys are found between the two tuples.
        """
        keys_a = set(k for k, _ in a)
        keys_b = set(k for k, _ in b)
        duplicates = keys_a & keys_b
        if duplicates:
            raise KeyError(
                f"Duplicate variable names found: {', '.join(duplicates)}")
        return a + b
