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
import os


class PolicyParserPrimitives:
    """Provides functionality for parsing data in the policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir

    def field(self, *keys):
        """Gets a field from the policy as is"""
        value = self.json
        try:
            for key in keys:
                value = value[key]
        except KeyError:
            value = None
        return value

    def hex_field(self, *keys):
        """Gets a hex string field"""
        value = self.field(*keys)
        if value:
            value = int(value, 16)
        else:
            value = None
        return value

    def bytes_field(self, *keys):
        """Gets a byte string field"""
        value = self.field(*keys)
        if value:
            value = bytes.fromhex(value)
        else:
            value = None
        return value

    def bytes_list_field(self, *keys):
        """Gets a list of byte string field"""
        value = self.field(*keys)
        if value:
            byte_strings = []
            for item in value:
                byte_strings.append(bytes.fromhex(item))
        else:
            byte_strings = None
        return byte_strings

    def enum_field(self, enum_type, ret_value, *keys):
        """Gets enum field"""
        value = self.field(*keys)
        if value is not None:
            for item in enum_type:
                if item.name.lower() == value.lower():
                    value = item
                    break
            if not isinstance(value, enum_type):
                raise ValueError(f"Invalid enum value '{value}'")
            value = value.value if ret_value else value
        return value

    def bin_file_field(self, *keys):
        """Gets a field containing path to binary file"""
        value = self.field(*keys)
        if value:
            if not os.path.isabs(value):
                value = os.path.abspath(os.path.join(self.policy_dir, value))
            with open(value, 'rb') as fp:
                value = fp.read()
        else:
            value = None
        return value

    def bin_file_list_field(self, *keys):
        """Gets a field containing list of paths to binary files"""
        value = self.field(*keys)
        if value:
            contents = []
            for item in value:
                if not os.path.isabs(item):
                    item = os.path.abspath(os.path.join(self.policy_dir, item))
                with open(item, 'rb') as fp:
                    contents.append(fp.read())
        else:
            contents = None
        return contents

    def bin_file_or_hex_string_field(self, *keys):
        """Gets a field containing path to binary file or hex string"""
        try:
            data = self.bin_file_field(*keys)
        except (FileNotFoundError, OSError, ValueError):
            try:
                data = self.bytes_field(*keys)
            except ValueError as e:
                raise ValueError(
                    f"Error parsing data: '{'.'.join(keys)}'"
                ) from e
        return data

    def int_field(self, *keys):
        """Gets an integer field"""
        value = self.field(*keys)
        if value is not None:
            try:
                value = int(str(value), 0)
            except ValueError as e:
                raise ValueError(f"Invalid integer value '{value}'") from e
        return value if value else 0
