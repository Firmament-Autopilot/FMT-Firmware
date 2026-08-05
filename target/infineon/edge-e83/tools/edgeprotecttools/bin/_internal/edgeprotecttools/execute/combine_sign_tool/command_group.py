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
from collections import namedtuple
from typing import List, Union

from .commands import (Command, CommandHexSegment, CommandSign, CommandShift,
                       CommandMerge, CommandExtractPayload, CommandEncryptAes,
                       CommandAddSignature, CommandSubprocessRunner,
                       CommandBinDump, CommandBin2Hex, CommandHash,
                       CommandHexDump, CommandHex2Bin, CommandHexRelocate)

logger = logging.getLogger(__name__)

CommandData = namedtuple('CommandData', 'command kwargs')


class CommandGroup:
    """Represents a group of commands and their options"""

    command_map = {
        'hex-segment': CommandHexSegment,
        'sign': CommandSign,
        'shift': CommandShift,
        'merge': CommandMerge,
        'extract-payload': CommandExtractPayload,
        'encrypt-aes': CommandEncryptAes,
        'add-signature': CommandAddSignature,
        'custom-script': CommandSubprocessRunner,
        'bin-dump': CommandBinDump,
        'bin2hex': CommandBin2Hex,
        'hash': CommandHash,
        'hex-dump': CommandHexDump,
        'hex2bin': CommandHex2Bin,
        'hex-relocate': CommandHexRelocate
    }

    def __init__(self, **kwargs):
        self._name = kwargs.get('name')
        self._enabled = kwargs.get('enabled', False)
        self._description = kwargs.get('description')
        self._command_data = self._parse(kwargs.get('commands', []))
        self._commands = []

    @property
    def enabled(self) -> bool:
        """Checks if a group should be executed or not """
        return self._enabled

    @property
    def description(self) -> Union[str, None]:
        """Get description for a group"""
        return self._description

    @property
    def command_data(self) -> List[CommandData]:
        """Get list of command in a group"""
        return self._command_data

    @property
    def commands(self) -> List[Command]:
        """Get list of command in a group"""
        return self._commands

    @property
    def name(self) -> str:
        """Get group name"""
        return self._name

    @staticmethod
    def _parse(commands: list) -> List[CommandData]:
        """Parse single command group to extract list of commands
        @param commands: top-level group of commands
        @return: list of classes which process a received command group
        """
        parsed_commands = []

        for command in commands:
            command_name = command.get('command')
            if command_name in CommandGroup.command_map:
                parsed_commands.append(
                    CommandData(CommandGroup.command_map[command_name], command)
                )
            else:
                raise KeyError(f"Unknown command '{command_name}'")

        return parsed_commands
