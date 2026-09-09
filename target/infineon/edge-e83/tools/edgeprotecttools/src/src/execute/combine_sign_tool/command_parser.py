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
import json
import logging
import re
from typing import List

from .command_group import CommandGroup

logger = logging.getLogger(__name__)


class CommandGroupParser:
    """Implements translation of JSON file properties into a
    groups of commands
    """
    def __init__(self, infile):
        self.infile = infile
        with open(infile, 'r', encoding='utf-8') as f:
            content = f.read()
        self.template = json.loads(self.remove_comments(content))

    def interpolate(self, interpolation_map: dict) -> None:
        """Interpolates template with specified key-value map"""
        self.template = self._interpolate(self.template, interpolation_map)

    def _interpolate(self, data, interpolation_map: dict):
        """Interpolates an object recursively"""
        if isinstance(data, dict):
            return {
                k: self._interpolate(v, interpolation_map)
                for k, v in data.items()
            }
        elif isinstance(data, list):
            return [self._interpolate(itm, interpolation_map) for itm in data]
        elif isinstance(data, str):
            m = re.fullmatch(r'\{\{ *(?P<cmd>\w+) *\}\}', data.strip())
            if m:
                if m['cmd'] in interpolation_map:
                    return interpolation_map[m['cmd']]
                else:
                    raise KeyError(f'Unknown variable: {m["cmd"]}')
            else:
                return data
        else:
            return data

    def parse(self) -> List[CommandGroup]:
        """Gets a list of command groups based on JSON file properties
        @return: List of command groups
        """
        groups = [CommandGroup(**group) for group in self.template['content']]

        return groups

    @staticmethod
    def remove_comments(content: str):
        """Remove single and multi-line comments"""
        single_line_comment_pattern = re.compile(r"//.*$", re.MULTILINE)
        multi_line_comment_pattern = re.compile(r"/\*.*?\*/", re.DOTALL)

        content = re.sub(multi_line_comment_pattern, "", content)
        content = re.sub(single_line_comment_pattern, "", content)

        return content
