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
import os.path

from ....execute.image_signing.split_tool import SplitTool
from ..command_enum import Format
from .command import Command

logger = logging.getLogger(__name__)


class CommandHexSegment(Command):
    """
    Implements the HexSegment command. It gets a segment of file which
    starts from a specified address.
    """

    args_map = {
        'cmd_name': 'command',
        'image': 'file',
        'segment_addr': 'address',
        'output_format': 'format',
        'output': 'file'
    }

    schema = 'hex_segment_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')[0]
        outputs = kwargs.get('outputs')[0]

        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._image = self.get_arg(inputs, 'image')

        seg_addr = self.get_arg(inputs, 'segment_addr')
        self._segment_addr = int(str(seg_addr), 0) if seg_addr else None
        self._output = self.get_arg(outputs, 'output')
        self._output_format = self.get_arg(outputs, 'output_format')

    def validate_args(self) -> bool:
        """Validates the hex-segment command parameters"""

        required_args = ('image', 'segment_addr',
                         'output_format', 'output')

        for arg in required_args:
            arg_attr = f'_{arg}'
            if not getattr(self, arg_attr):
                logger.error('Field "%s" is required', self.args_map.get(arg))
                return False

        if not os.path.exists(self._image):
            logger.error('File not found: "%s"', os.path.abspath(self._image))
            return False

        if not self.format_validation(self._output_format, self._output):
            return False

        return True

    def execute(self) -> bool:
        """Executes the hex-segment command"""

        try:
            res = SplitTool.get_segment(self._image,
                                        self._segment_addr)

        except ValueError as e:
            logger.error(e)
            return False

        if not res:
            logger.error('Segment with address 0x%08x not found',
                         self._segment_addr)
            return False

        fmt = 'bin' if self._output_format == Format.BIN else 'hex'
        try:
            res.tofile(self._output, fmt)
        except (OSError, ValueError) as e:
            logger.error(e)
            return False

        return True
