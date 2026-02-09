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
import os
from typing import List, Union
from .symbol_file import SymbolFile


class SymbolFileFinder:
    """
    Finds valid symbol information JSON files from a directory, a file,
    or a list of files.
    """
    @staticmethod
    def discover_symbol_files(sources: Union[str, List[str]]) -> List[SymbolFile]:
        """
        Given a directory, a file, or a list of files, returns a list
        of valid SymbolFile objects.
        Raises FileNotFoundError if the source is neither a file
        nor a directory.
        """
        if sources:
            if isinstance(sources, (list, tuple)):
                return SymbolFileFinder._find_from_list(sources)
            elif isinstance(sources, str):
                sources = os.path.normpath(sources)
                if os.path.isfile(sources):
                    return SymbolFileFinder._find_from_file(sources)
                elif os.path.isdir(sources):
                    return SymbolFileFinder._find_from_directory(sources)
                else:
                    raise FileNotFoundError(f"Symbol source '{sources}' not found")
        return []

    @staticmethod
    def _find_from_list(files: Union[list, List[str]]) -> List[SymbolFile]:
        symbol_files = []
        for file_path in files:
            sf = SymbolFile(file_path)
            if sf.is_valid():
                symbol_files.append(sf)
        return symbol_files

    @staticmethod
    def _find_from_file(file_path: str) -> List[SymbolFile]:
        symbol_files = []
        sf = SymbolFile(file_path)
        if sf.is_valid():
            symbol_files.append(sf)
        return symbol_files

    @staticmethod
    def _find_from_directory(directory: str) -> List[SymbolFile]:
        symbol_files = []
        for root, _, files in os.walk(directory):
            for file in files:
                file_path = os.path.join(root, file)
                sf = SymbolFile(file_path)
                if sf.is_valid():
                    symbol_files.append(sf)
        return symbol_files
