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

import logging
import os

from .command import Command
from ... import dump

logger = logging.getLogger(__name__)


class CommandHexDump(Command):
    """Hex-dump command implementation"""

    args_map = {
        'cmd_name': 'command',
        'hex_file': 'file',
        'address': 'address',
        'size': 'size',
        'output': 'file',
        'fill_value': 'fill-value',
        'description': 'description'
    }

    schema = 'hex_dump_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._hex_file = self.get_arg(self._inputs, 'hex_file')
        self._address = self.get_arg(self._inputs, 'address')
        self._size = self.get_arg(self._inputs, 'size')

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')
        self._fill_value = self.get_arg(outputs, 'fill_value', default=0)

    @property
    def hex_file(self):
        return self._hex_file

    @property
    def address(self):
        return self._address

    @property
    def size(self):
        return self._size

    @property
    def output(self):
        return self._output

    @property
    def fill_value(self):
        return self._fill_value

    def validate_args(self) -> bool:
        """Validation of hex-dump command"""

        if not os.path.exists(self.hex_file):
            logger.error("File not found: '%s'", os.path.abspath(self.hex_file))
            return False

        try:
            self._address = int(str(self._address), 0)
        except ValueError:
            logger.error("Invalid address value: '%s'", self._address)
            return False

        try:
            self._size = int(str(self._size), 0)
            if self.size <= 0:
                raise ValueError
        except ValueError:
            logger.error("Invalid size value: '%s'", self._size)
            return False

        try:
            self._fill_value = int(str(self._fill_value), 0)
            if self.fill_value < 0 or self.fill_value > 0xFF:
                raise ValueError
        except ValueError:
            logger.error("Invalid fill value: '%s'", self._fill_value)
            return False

        return True

    def execute(self) -> bool:
        """Executes the hex-dump command"""
        dump.hex_dump(self.hex_file, self.address, self.size,
                      output=self.output, padding=self.fill_value)
        return True
