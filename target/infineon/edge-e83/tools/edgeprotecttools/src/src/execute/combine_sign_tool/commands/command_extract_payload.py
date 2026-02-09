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

from ...image_signing.sign_tool import SignTool
from ..command_enum import Format
from .command import Command

logger = logging.getLogger(__name__)


class CommandExtractPayload(Command):
    """Extract-payload command implementation"""

    args_map = {
        'cmd_name': 'command',
        'image': 'file',
        'output': 'file',
        'description': 'description'
    }

    schema = 'extract_payload_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')[0]
        outputs = kwargs.get('outputs')[0]

        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._image = self.get_arg(inputs, 'image')
        self._output = self.get_arg(outputs, 'output')

    def validate_args(self) -> bool:
        """Validation of extract-payload command"""

        if not self._image:
            logger.error('Field "%s" is required', self.args_map.get('image'))
            return False

        abs_path = os.path.abspath(self._image)
        if not os.path.exists(abs_path):
            logger.error('File not found: "%s"', abs_path)
            return False

        if not self.format_validation(Format.BIN, self._output):
            return False

        return True

    def execute(self) -> bool:
        """Executes of the extract-payload command"""

        try:
            SignTool.extract_payload(self._image, self._output)
        except ValueError as e:
            logger.error(e)
            return False

        return True
