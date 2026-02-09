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

from intelhex import IntelHex, HexRecordError

from ...image_signing.sign_tool import SignTool, Image
from ..command_enum import Format
from .command import Command

logger = logging.getLogger(__name__)


class CommandAddSignature(Command):
    """Add-signature command implementation"""

    args_map = {
        'cmd_name': 'command',
        'image': 'file',
        'signature': 'file',
        'algorithm': 'algorithm',
        'output': 'file',
        'output_format': 'format',
        'description': 'description'
    }

    schema = 'add_signature_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')
        self._image = None
        self._in_format = None
        self._signature = None
        self._algorithm = None
        self._parse_inputs()

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')
        self._output_format = self.get_arg(outputs, 'output_format')

    @property
    def image(self):
        return self._image

    @property
    def in_format(self):
        return self._in_format

    @property
    def signature(self):
        return self._signature

    @property
    def algorithm(self):
        return self._algorithm

    @property
    def output(self):
        return self._output

    @property
    def output_format(self):
        return self._output_format

    def _parse_inputs(self):

        dic_a = self._inputs[0]
        dic_b = self._inputs[1]

        if self.get_arg(dic_a, 'algorithm'):
            self._signature = self.get_arg(dic_a, 'signature')
            self._algorithm = self.get_arg(dic_a, 'algorithm')
            self._image = self.get_arg(dic_b, 'image')
        elif self.get_arg(dic_b, 'algorithm'):
            self._signature = self.get_arg(dic_b, 'signature')
            self._algorithm = self.get_arg(dic_b, 'algorithm')
            self._image = self.get_arg(dic_a, 'image')

    def get_input_format(self):
        """Get input image format"""

        try:
            IntelHex(self.image)
        except (UnicodeDecodeError, HexRecordError):
            fmt = Format.BIN
        else:
            fmt = Format.IHEX

        return fmt

    def validate_args(self) -> bool:
        """Validation of add-signature command"""

        required_args = ('image', 'signature', 'algorithm',
                         'output_format', 'output')

        for arg in required_args:
            arg_attr = f'_{arg}'
            if not getattr(self, arg_attr):
                logger.error('Field "%s" is required', self.args_map.get(arg))
                return False

            if not os.path.exists(self.image):
                logger.error('File not found: "%s"', os.path.abspath(self.image))
                return False

        image = Image(self.image)
        if not image.has_metadata:
            logger.error('The image does not have metadata: "%s"',
                         os.path.abspath(self.image))
            return False

        if not os.path.exists(self.signature):
            logger.error('File not found: "%s"',
                         os.path.abspath(self.signature))
            return False

        if not self.format_validation(Format.BIN, self.signature):
            return False

        if not self.format_validation(self.output_format, self.output):
            return False

        return True

    def execute(self) -> bool:
        """Executes of the add-signature command"""
        self._in_format = self.get_input_format()

        try:
            res_bytes = SignTool.add_signature(self.image, self.signature,
                                               self.algorithm)
        except (OSError, ValueError) as e:
            logger.error(e)
            return False

        ih = IntelHex()
        offset = 0
        if self.output_format == Format.IHEX:
            output_file_format = 'hex'
            if self.in_format == Format.IHEX:
                received_ih = IntelHex(self.image)
                offset = received_ih.minaddr()
                logger.debug('offset: %s', hex(offset))
        else:
            output_file_format = 'bin'

        ih.frombytes(res_bytes, offset)
        ih.tofile(self.output, output_file_format)

        return True
