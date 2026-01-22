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
import subprocess

from .command import Command

logger = logging.getLogger(__name__)


class CommandSubprocessRunner(Command):
    """
    Implements a command for running custom script.
    """

    args_map = {
        'cmd_name': 'command',
        'cmd_line': 'command-line',
        'shell': 'shell'
    }

    schema = 'custom_script_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')[0]
        self._cmd_name = self.get_arg(kwargs, 'cmd_name')

        self._cli = self.get_arg(inputs, 'cmd_line')
        self._shell = self.get_arg(inputs, 'shell')

    def validate_args(self) -> bool:
        """Validates the custom command parameters"""

        if not self._cli:
            logger.error("Field '%s' is required", self.args_map.get('cmd_line'))
            return False

        if not isinstance(self._cli, str):
            logger.error("The command must be a string")
            return False

        logger.debug('CLI: %s', self._cli)

        return True

    def execute(self) -> bool:
        """Executes the subprocess command"""
        logger.info('cmd: %s', self._cli)

        try:
            if self._shell:
                res = subprocess.run(self._cli, check=True, shell=True)
            else:
                cmd = list(self._cli.split())
                res = subprocess.run(cmd, check=True)
        except (ChildProcessError, FileNotFoundError, AttributeError,
                ValueError, OSError) as e:
            logger.error(e)
            return False

        if res.returncode != 0:
            logger.error('Error %s', res.returncode)
            return False

        return True
