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
from typing import List

from .command_group import CommandGroup

logger = logging.getLogger(__name__)


class CommandProcessor:
    """The command invoker, which sends a request to the commands"""

    def __init__(self, command_groups: List[CommandGroup]):
        self.command_groups = command_groups
        for group in self.command_groups:
            for data in group.command_data:
                group.commands.append(data.command(**data.kwargs))

    def execute_all(self) -> bool:
        """Starts all commands execution"""
        for group in self.command_groups:
            if not group.enabled:
                continue

            for cmd in group.commands:
                res = cmd.validate_args()

                if not res:
                    logger.error('%s: validation of "%s" command has failed',
                                 group.name, cmd.name)
                    return False

                logger.info('%s: command "%s" validation succeeded',
                            group.name, cmd.name)

                res = cmd.execute()

                if not res:
                    logger.error('%s: command "%s" failed',
                                 group.name, cmd.name)
                    return False

                logger.info('%s: command "%s" succeeded', group.name, cmd.name)

        return True
