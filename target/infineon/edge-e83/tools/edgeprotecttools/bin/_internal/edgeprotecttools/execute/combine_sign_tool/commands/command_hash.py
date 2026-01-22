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
import hashlib
import logging
import os

from .command import Command

logger = logging.getLogger(__name__)


class CommandHash(Command):
    """Hash command implementation"""

    args_map = {
        'cmd_name': 'command',
        'input_file': 'file',
        'output': 'file',
        'algorithm': 'algorithm',
        'format': 'format',
        'description': 'description'
    }

    schema = 'hash_schema.json'

    def __init__(self, **kwargs):
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._inputs = kwargs.get('inputs')[0]
        self._input_file = self.get_arg(self._inputs, 'input_file')
        self._algorithm_name = self.get_arg(self._inputs, 'algorithm')
        self._hash_algorithm = None

        outputs = kwargs.get('outputs')[0]
        self._output = self.get_arg(outputs, 'output')
        self._output_format = self.get_arg(outputs, 'format')

    @property
    def input_file(self):
        return self._input_file

    @property
    def algorithm(self):
        return self._algorithm_name

    @property
    def output(self):
        return self._output

    @property
    def output_format(self):
        return self._output_format

    def validate_args(self) -> bool:
        """Validation of hash command"""

        if not os.path.exists(self.input_file):
            logger.error("File not found: '%s'",
                         os.path.abspath(self.input_file))
            return False

        supported_algorithms = {
            'sha256': hashlib.sha256(),
            'sha384': hashlib.sha384(),
            'sha512': hashlib.sha512()
        }
        try:
            self._hash_algorithm = supported_algorithms[self.algorithm.lower()]
        except KeyError:
            logger.error("Unsupported hash algorithm: '%s'", self.algorithm)
            return False

        return True

    def execute(self) -> bool:
        """Executes the hash command"""
        with open(self.input_file, 'rb') as f:
            payload = f.read()

        self._hash_algorithm.update(payload)
        digest = self._hash_algorithm.digest()

        if self.output_format == 'txt':
            with open(self.output, 'w', encoding='utf-8') as f:
                f.write(digest.hex())
        else:
            with open(self.output, 'wb') as f:
                f.write(digest)
        logger.info("Hash = '%s'", digest.hex())
        logger.info("Hash saved to '%s'", os.path.abspath(self.output))

        return True
