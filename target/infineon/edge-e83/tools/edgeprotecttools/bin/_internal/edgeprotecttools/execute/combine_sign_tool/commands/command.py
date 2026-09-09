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
import pathlib
from abc import ABC, abstractmethod

from ..command_enum import Format

logger = logging.getLogger(__name__)


class Command(ABC):
    """
    The Command interface declares a method for executing a command.
    """
    args_map = {}

    schema = None

    @abstractmethod
    def __init__(self, **kwargs):
        """Instantiates the command class"""
        self._cmd_name = kwargs.get('command')

    @abstractmethod
    def validate_args(self) -> bool:
        """Validates a command parameters"""

    @abstractmethod
    def execute(self) -> bool:
        """Executes a command"""

    @property
    def name(self) -> str:
        """Get command name"""
        return self._cmd_name

    def get_arg(self, kwargs, name, default=None):
        """Get argument of args_map
        @param kwargs: dict where JSON value is taken from
        @param name: key of args_map to get according value
        @param default: default value if key is not found
        """
        arg = kwargs.get(self.args_map.get(name))
        return arg if arg is not None else default

    @staticmethod
    def format_validation(file_format: Format, out_file: str) -> bool:
        """Validation of a format and a file extension
        @param file_format: the format field from JSON
        @param out_file: path and name of file
        @return: True - if file_format is correct and no conflicts with
        out_file extension.
        """

        if file_format == Format.BIN:
            extension = '.bin'
        elif file_format == Format.IHEX:
            extension = '.hex'
        else:
            raise ValueError(f"Unsupported file format '{file_format}'")

        if pathlib.Path(out_file).suffix != extension:
            logger.error(
                'Output file extension "%s" conflicts with the format "%s"',
                os.path.abspath(out_file), file_format)
            return False

        return True
