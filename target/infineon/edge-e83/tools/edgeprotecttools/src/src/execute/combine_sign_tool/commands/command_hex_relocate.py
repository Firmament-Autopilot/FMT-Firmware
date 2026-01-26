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
from ...hex_relocator import HexRelocator

logger = logging.getLogger(__name__)


class CommandHexRelocate(Command):
    """Hex-relocate command implementation"""

    args_map = {
        'cmd_name': 'command',
        'hex_file': 'file',
        'regions': 'regions',
        'output': 'file',
        'fill_value': 'fill-value',
        'description': 'description'
    }

    schema = 'hex_relocate_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._hex_file = self.get_arg(self._inputs, 'hex_file')
        self._regions = self.get_arg(self._inputs, 'regions')

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')

    @property
    def hex_file(self):
        return self._hex_file

    @property
    def regions(self):
        return self._regions

    @property
    def output(self):
        return self._output

    def validate_args(self) -> bool:
        """Validation of hex-relocate command"""

        if not os.path.exists(self.hex_file):
            logger.error("File not found: '%s'", os.path.abspath(self.hex_file))
            return False

        if not isinstance(self._regions, (list, tuple)):
            logger.error("Regions must be a list of dictionaries")
            return False

        for idx, region in enumerate(self._regions):
            if not isinstance(region, dict):
                logger.error("Region #%d is not a dictionary: %r", idx + 1, region)
                return False
            for key in ("start", "size", "dest"):
                if key not in region:
                    logger.error("Region #%d missing required key '%s'.", idx + 1, key)
                    return False
                try:
                    value = int(str(region[key]), 0)
                except ValueError:
                    logger.error(
                        "Region #%d: '%s' value is not a valid integer or hex string: %r",
                        idx + 1, key, region[key]
                    )
                    return False
                if key == "size" and value <= 0:
                    logger.error("Region #%d: 'size' must be > 0.", idx + 1)
                    return False
                if key in ("start", "dest") and value < 0:
                    logger.error("Region #%d: '%s' must be >= 0.", idx + 1, key)
                    return False

        return True

    def execute(self) -> bool:
        """Executes the hex-relocate command"""
        regions = [
            (
                int(str(region["start"]), 0),
                int(str(region["size"]), 0),
                int(str(region["dest"]), 0)
            )
            for region in self.regions
        ]
        if HexRelocator.relocate_file(self.hex_file, self.output, regions):
            logger.info("Saved file to '%s'", self.output)
            return True
        return False
