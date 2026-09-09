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

from ... import dump
from .command import Command

logger = logging.getLogger(__name__)


class CommandBinDump(Command):
    """Bin-dump command implementation"""

    args_map = {
        'cmd_name': 'command',
        'data': 'data',
        'random': 'random',
        'output': 'file',
        'description': 'description'
    }

    schema = 'bin_dump_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._data = self.get_arg(self._inputs, 'data')
        self._random = self.get_arg(self._inputs, 'random')

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')

    @property
    def data(self):
        return self._data

    @property
    def random(self):
        return self._random

    @property
    def output(self):
        return self._output

    def validate_args(self) -> bool:
        """Validation of bin-dump command"""

        if self._data and self._random is not None:
            logger.error(
                "Properties 'data' and 'random' are mutually exclusive")
            return False

        if not self._data and self._random is None:
            logger.error("Either 'data' or 'random' property must be specified")
            return False

        if self._data:
            if not all(c.lower() in '0123456789abcdef' for c in self._data):
                logger.error('The hex string must contain only hex characters')
                return False

            if len(self._data) % 2 != 0:
                logger.error(
                    'The hex string must contain an even number of characters')
                return False

        if self._random is not None:
            try:
                self._random = int(str(self._random), 0)
                if self._random < 0:
                    raise ValueError
            except ValueError:
                logger.error("Invalid random value: '%s'", self._random)
                return False

        return True

    def execute(self) -> bool:
        """Executes the bin-dump command"""
        if self._random is not None:
            self._data = os.urandom(int(str(self._random), 0))

        dump.bin_dump(self._data, self._output)
        logger.info("Data saved to '%s'", os.path.abspath(self._output))
        return True
