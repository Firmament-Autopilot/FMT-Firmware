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
import io
import logging
import os.path
from typing import List
from intelhex import IntelHex, HexRecordError

from ...image_signing.merge_tool import MergeTool
from ..command_enum import Format
from .command import Command
from ....core.signtool_base import bin2hex

logger = logging.getLogger(__name__)


class CommandMerge(Command):
    """
    Implements a command that merges two or more hex files.
    """
    args_map = {
        'cmd_name': 'command',
        'image': 'file',
        'output_format': 'format',
        'output': 'file',
        'offset': 'address',
        'description': 'description',
        'overlap': 'overlap'
    }

    schema = 'merge_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')
        outputs = kwargs.get('outputs')[0]

        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = [self.get_arg(dic, 'image') for dic in inputs]
        self._output_format = self.get_arg(outputs, 'output_format')
        self._output = self.get_arg(outputs, 'output')
        offset = self.get_arg(outputs, 'offset')
        self._offset = int(str(offset), 0) if offset else None
        self._overlap = self.get_arg(outputs, 'overlap')
        if not self._overlap:
            self._overlap = 'error'

    @property
    def inputs(self):
        return self._inputs

    @property
    def output(self):
        return self._output

    @property
    def offset(self):
        return self._offset

    @property
    def overlap(self):
        return self._overlap

    @staticmethod
    def _get_inputs_format(image_lst: List) -> list:
        """Return inputs format"""
        inputs_fmt = []
        for image in image_lst:
            try:
                IntelHex(image)
            except (UnicodeDecodeError, HexRecordError):
                inputs_fmt.append('bin')
            else:
                inputs_fmt.append('hex')
        return inputs_fmt

    def _validate_inputs_format(self, image_lst: List) -> bool:
        """Check if input files are all with the same type
        @param image_lst: list of input files to be verified
        @return: True - if input files are all with the same type
        """
        inputs_fmt = self._get_inputs_format(image_lst)
        return all(x == inputs_fmt[0] for x in inputs_fmt)

    def _validate_outputs_format(self) -> bool:
        """Check if input files are compatible with output format
        """
        if all(x == Format.BIN for x in self._get_inputs_format(self.inputs)) \
                and self._output_format == Format.IHEX and not self.offset:
            return False
        return True

    def validate_args(self) -> bool:
        """Validates the merge command parameters"""

        for itm in self.inputs:
            if not os.path.exists(itm):
                logger.error('File not found: "%s"', os.path.abspath(itm))
                return False

        min_input_images = 2
        if len(self.inputs) < min_input_images:
            logger.error('At least two input images are required')
            return False

        if not self._validate_inputs_format(self.inputs):
            logger.error('Ensure that all input files are of the same format')
            return False

        required_out_args = ('output_format', 'output')
        for arg in required_out_args:
            arg_attr = f'_{arg}'
            if not getattr(self, arg_attr):
                logger.error('Field "%s" is required', self.args_map.get(arg))
                return False

        if not self.format_validation(self._output_format, self.output):
            return False

        if not self._validate_outputs_format():
            logger.error('Address must be specified when merging binaries '
                         'and saving to HEX')
            return False

        if self.overlap not in ('error', 'ignore', 'replace'):
            logger.error('Overlap must be "replace", "ignore" or "error"')
            return False

        return True

    def execute(self) -> bool:
        """Executes the merge command"""
        formats = self._get_inputs_format(self.inputs)

        if all(fmt == 'bin' for fmt in formats):
            return self._execute_bin()
        else:
            return self._execute_hex()

    def _execute_bin(self) -> bool:
        """Executes the merge command for bin inputs"""
        try:
            data = MergeTool.merge_bin(self.inputs)
        except (OSError, ValueError) as e:
            logger.error('Failed to merge "%s" into "%s"',
                         ", ".join(self.inputs), self.output)
            logger.debug(e)
            return False

        try:
            if self._output_format == Format.BIN:
                with open(self.output, 'wb') as binary:
                    binary.write(data)
            else:
                bin2hex(io.BytesIO(data), self.output, offset=self.offset)
        except (OSError, ValueError) as e:
            logger.error('Unable to save file: "%s"', self.output)
            logger.debug(e)
            return False

        return True

    def _execute_hex(self) -> bool:
        """Executes the merge command for hex inputs"""
        fmt = 'bin' if self._output_format == Format.BIN else 'hex'

        try:
            ih_res = MergeTool.merge_hex(self.inputs, overlap=self.overlap)
        except ValueError as e:
            logger.error('Failed to merge "%s" into "%s"',
                         ", ".join(self.inputs), self.output)
            logger.debug(e)
            return False

        try:
            ih_res.tofile(self.output, fmt)
        except (OSError, ValueError) as e:
            logger.error('Failed to save file "%s"', self.output)
            logger.debug(e)
            return False
        return True
