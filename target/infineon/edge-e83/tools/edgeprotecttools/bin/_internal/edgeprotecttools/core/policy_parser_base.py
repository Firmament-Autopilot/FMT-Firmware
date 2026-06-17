"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from json import JSONDecodeError
from pathlib import Path

from .json_helper import read_json


class PolicyParserBase:
    """Base class for the classes that implement policy parser"""

    def __init__(self, policy_file):
        self.json = None
        self.policy_dir = None
        self.policy_file = None

        if policy_file is not None:
            self.initialize(policy_file)

    def initialize(self, policy_file):
        """Initializes parser"""
        self.policy_file = Path(policy_file).absolute()
        self.json = self.get_json(self.policy_file)
        self.policy_dir = os.path.dirname(self.policy_file)

    @staticmethod
    def get_json(filename):
        """Gets JSON file as a dictionary"""
        try:
            data = read_json(filename)
        except JSONDecodeError as e:
            raise JSONDecodeError(f"Failed to parse policy '{filename}': "
                                  f"{e.args[0]}", e.doc, e.pos) from e
        return data

    def policy_type(self):
        """Gets a value of policy type property"""
        try:
            return self.json['policy']['type']
        except KeyError as e:
            raise KeyError(
                f'Policy type not specified ({self.policy_file})') from e

    def policy_version(self):
        """Gets a value of policy version property"""
        try:
            return self.json['policy']['version']
        except KeyError as e:
            raise KeyError(
                f'Policy version not specified ({self.policy_file})') from e

    def custom_data_sections(self):
        """Gets list of custom data sections in a format suitable
        for CBOR packet
        """
        sections = []
        if not self.json or 'custom_data_sections' not in self.json:
            return sections

        for key, value in self.json['custom_data_sections'].items():
            if isinstance(value, dict):
                if 'id' not in value:
                    raise KeyError(
                        f"'id' is mandatory for custom data section '{key}'")
                if 'value' not in value:
                    raise KeyError(
                        f"'value' is mandatory for custom data section '{key}'")
            else:
                raise ValueError(
                    f"Custom data section '{key}' is not a dictionary")
            custom = self._custom_fields({key: value})
            sections.append(custom)
        return sections

    def _custom_fields(self, node):
        """Recursive method for conversion of 'id-value' pairs to
        a dictionary suitable for CBOR packet. Can be used for the nested
        'id-value' pairs
        Example 1:
         - Input: {
                    'param1': {'id': 1, 'value': 55},
                    'param2': {'id': 2, 'value': 77}
                  }
         - Output - {1: 55, 2: 77}
        Example 2:
         - Input: {'param1': {
                    'id': 11, 'value': {
                      'param2': {
                        'id': 22, 'value': 2
                      },
                      'param3': {
                        'id': 33, 'value': {
                          'param4': {
                            'id': 44, 'value': 4
                          },
                          'param5': {
                            'id': 55, 'value': 5
                          }
                        }
                      }
                    }
                 }}
         - Output - {11: {22: 2, 33: {44: 4, 55: 5}}}
        """
        custom = {}
        for item in node.values():
            if isinstance(item['value'], dict):
                custom[item['id']] = self._custom_fields(item['value'])
            else:
                if isinstance(item['value'], str):
                    try:
                        value = bytes.fromhex(item['value'])
                    except ValueError as e:
                        raise ValueError(
                            f"Non-hexadecimal number '{item['value']}'") from e
                else:
                    value = item['value']
                custom[item['id']] = value
        return custom
