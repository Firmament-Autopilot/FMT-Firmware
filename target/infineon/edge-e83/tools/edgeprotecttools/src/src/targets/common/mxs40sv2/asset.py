"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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


class Asset:
    def __init__(self, name, asset_data):
        self.name = name
        self.size = asset_data['size']
        self.value = self._set_value(asset_data['data'], self.size)

    def __repr__(self):
        return f'Asset("{self.name}", {self.size})'

    @staticmethod
    def _set_value(data, size):
        """
        Sets a value of single asset
        :param data: dict of sub-asset values
        :param size: Size of single asset in bytes
        :return: Return an array of bytes representing a value of single Asset
        """
        value = 0
        for item in data:
            if isinstance(item['value'], int):
                value |= item['value'] << item['shift']
            elif isinstance(item['value'], (bytes, bytearray)):
                return item['value']
        return value.to_bytes(size, byteorder='little')
