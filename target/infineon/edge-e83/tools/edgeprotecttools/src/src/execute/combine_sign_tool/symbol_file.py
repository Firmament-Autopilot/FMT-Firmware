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
import json
import os
from typing import List, Tuple


class SymbolFile:
    """
    Represents a single symbol information JSON file.
    Handles loading, validation, and access to symbol data.
    """
    def __init__(self, json_path: str):
        self.json_path = os.path.normpath(json_path)
        self.version = None
        self.symbols = []
        self._load_and_validate()

    def __repr__(self) -> str:
        return f"<SymbolFile path='{self.json_path}'>"

    def _load_and_validate(self) -> None:
        try:
            with open(self.json_path, 'r', encoding='utf-8') as f:
                data = json.load(f)
        except (UnicodeDecodeError, json.decoder.JSONDecodeError):
            return
        if 'version' in data:
            self.version = data['version']
        symbol_info = data.get('symbolInformation', [])
        if not isinstance(symbol_info, list):
            return
        self.symbols = [
            (item['name'], item['value'])
            for item in symbol_info
            if isinstance(item, dict) and 'name' in item and 'value' in item
        ]

    def is_valid(self) -> bool:
        """
        Checks if the symbol file contains at least one valid symbol entry.
        :return: True if there is at least one valid symbol, False otherwise.
        """
        return bool(self.symbols)

    def get_symbols(self) -> List[Tuple[str, str]]:
        """
        Returns the list of (name, value) symbol pairs loaded from the file.
        :return: List of (name, value) tuples.
        """
        return self.symbols
