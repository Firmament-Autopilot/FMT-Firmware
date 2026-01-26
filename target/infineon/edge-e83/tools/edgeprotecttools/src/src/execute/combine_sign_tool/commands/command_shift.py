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
from intelhex import IntelHex

from ..command_enum import Format
from .command import Command

logger = logging.getLogger(__name__)


class CommandShift(Command):
    """
    Implements a command for shifting found segment to a specific address
    """

    args_map = {
        'name': 'command',
        'image': 'file',
        'segment_addr': 'address',
        'second_addr': 'address',
        'output': 'file'
    }

    schema = 'shift_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')[0]
        outputs = kwargs.get('outputs')[0]

        self._cmd_name = self.get_arg(kwargs, 'name')
        self._image = self.get_arg(inputs, 'image')
        seg_addr = self.get_arg(inputs, 'segment_addr')
        self._segment_addr = int(str(seg_addr), 0) if seg_addr else None

        self._second_addr = int(str(self.get_arg(outputs, 'second_addr')), 0)
        self._output = self.get_arg(outputs, 'output')

    def validate_args(self) -> bool:
        """Validates the shift command parameters"""

        required_args = {'image', 'second_addr', 'output'}

        for arg in required_args:
            arg_attr = f'_{arg}'
            if not getattr(self, arg_attr):
                logger.error('Field "%s" is required', self.args_map.get(arg))
                return False

        if not os.path.exists(self._image):
            logger.error('File not found: "%s"',
                         os.path.abspath(self._image))
            return False

        received_ih = IntelHex(self._image)
        if not self._segment_addr and len(received_ih.segments()) > 1:
            logger.error('Segment address is mandatory if there is more than '
                         'one segment in the file')
            return False

        if not self.format_validation(Format.IHEX, self._output):
            return False

        return True

    def execute(self) -> bool:
        """Executes the shift command"""

        received_ih = IntelHex(self._image)
        shifted_ih = None

        if not self._segment_addr:
            # in this case it's allowed the only segment
            shifted_ih = IntelHex()
            shifted_ih.start_addr = received_ih.start_addr
            shifted_ih.frombytes(received_ih.tobinarray(),
                                 offset=self._second_addr)
        else:
            for start, end in received_ih.segments():
                if start == self._segment_addr:
                    segment_ih = IntelHex(received_ih[start:end])
                    shifted_ih = IntelHex()
                    shifted_ih.start_addr = received_ih.start_addr
                    shifted_ih.frombytes(segment_ih.tobinarray(),
                                         offset=self._second_addr)

            if shifted_ih:
                for start, end in received_ih.segments():
                    if start != self._segment_addr:
                        segment_ih = IntelHex(received_ih[start:end])
                        shifted_ih.merge(segment_ih, overlap='error')
            else:
                logger.error('Segment with address 0x%08x not found',
                             self._segment_addr)
                return False

        try:
            shifted_ih.tofile(self._output, 'hex')
        except (OSError, ValueError) as e:
            logger.error(e)
            return False

        return True
