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
import os
from os.path import join

from .command_group import CommandData
from .commands import (CommandAddSignature, CommandExtractPayload,
                       CommandEncryptAes, CommandHexSegment, CommandMerge,
                       CommandShift, CommandSign, CommandSubprocessRunner,
                       CommandBinDump, CommandBin2Hex, CommandHash,
                       CommandHexDump, CommandHex2Bin, CommandHexRelocate)
from ...core.enums import ValidationStatus
from ...core.json_validator import JsonValidator


class CommandJsonValidator(JsonValidator):
    """Json validator for sign&combine tools"""
    schema_dir = join(os.path.dirname(__file__), 'schemas')
    schemas = {'root': join(schema_dir, 'root_schema.json')}

    def __init__(self, parser):
        super().__init__(parser=parser)
        for command in (
                CommandAddSignature,
                CommandExtractPayload,
                CommandEncryptAes,
                CommandHexSegment,
                CommandMerge,
                CommandShift,
                CommandSign,
                CommandSubprocessRunner,
                CommandBinDump,
                CommandBin2Hex,
                CommandHash,
                CommandHexDump,
                CommandHex2Bin,
                CommandHexRelocate
        ):
            self.schemas[command] = join(self.schema_dir, command.schema)

    def validate_command(self, command_data: CommandData) -> ValidationStatus:
        """Validates command data against json schema"""
        return self.validate_by_schema(command_data.command,
                                       data=command_data.kwargs)
