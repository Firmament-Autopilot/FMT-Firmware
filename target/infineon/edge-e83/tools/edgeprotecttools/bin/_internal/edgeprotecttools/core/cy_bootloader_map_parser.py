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
import os
import json

CY_BOOTLOADER_MAP = os.path.abspath(os.path.join(
    os.path.dirname(__file__), '../data/cy_bootloader_map.json'))


class CyBootloaderMapParser:
    """
    Provides functionality for searching data in CyBootloader map.
    """
    @staticmethod
    def get_json(filename):
        """
        Gets JSON file as a dictionary.
        :param filename: The JSON file.
        :return: JSON file as a dictionary.
        """
        with open(filename, encoding='utf-8') as f:
            file_content = f.read()
            data = json.loads(file_content)
        return data

    @staticmethod
    def get_filename(target, upgrade_mode, build_mode, file_type):
        """
        Gets the name of CyBootloader hex, or jwt file based on
        target, mode and file type.
        :param target: Device name.
        :param upgrade_mode: CyBootloader upgrade mode (overwrite, swap).
        :param build_mode: CyBootloader build mode (debug or release).
        :param file_type: The type of the file (hex or jwt).
        :return: Filename.
        """
        data = CyBootloaderMapParser.get_json(CY_BOOTLOADER_MAP)
        path_schema = data['targets'][target.lower().strip()]
        for k, v in data['path_schemas'].items():
            if k == path_schema:
                if upgrade_mode is None:
                    upgrade_mode = v['default_mode']
                return v['modes'][upgrade_mode][build_mode][file_type]
        raise KeyError(
            f'Failed to find data in {CY_BOOTLOADER_MAP} (target "{target}", '
            f'upgrade mode "{upgrade_mode}", build mode "{build_mode}")'
        )
