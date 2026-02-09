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

from ....core.signtool_base import SignToolBase
from .command import Command

logger = logging.getLogger(__name__)


class CommandBin2Hex(Command):
    """bin2hex command implementation"""

    args_map = {
        'cmd_name': 'command',
        'bin_file': 'file',
        'output': 'file',
        'offset': 'offset',
        'description': 'description'
    }

    schema = 'bin2hex_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._bin_file = self.get_arg(self._inputs, 'bin_file')
        self._offset = self.get_arg(self._inputs, 'offset', default=0)

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')

    @property
    def bin_file(self):
        return self._bin_file

    @property
    def offset(self):
        return self._offset

    @property
    def output(self):
        return self._output

    def validate_args(self) -> bool:
        """Validation of bin2hex command"""

        if not os.path.exists(self.bin_file):
            logger.error("File not found: '%s'", os.path.abspath(self.bin_file))
            return False

        try:
            self._offset = int(str(self.offset), 0)
        except ValueError:
            logger.error("Invalid offset value: '%s'", self.offset)
            return False

        return True

    def execute(self) -> bool:
        """Executes the bin2hex command"""
        result = SignToolBase.bin2hex(self.bin_file, self.output,
                                      offset=self.offset)
        if result:
            logger.info("Saved converted file to '%s'",
                        os.path.abspath(self.output))
        else:
            logger.error("Failed to convert file '%s'",
                         os.path.abspath(self.bin_file))
        return True
