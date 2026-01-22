"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import sys
from importlib import import_module

import click

from .core import package_name
from .targets import target_data
from . import cli as base_cli


class CliCreator:
    """Implements dynamic CLI layer creation and CLI validation"""

    @staticmethod
    def create():
        """Dynamic CLI creation"""
        is_help = '--help' in sys.argv[1:]

        target = CliCreator.option_from_args(['-t', '--target'])

        platform = CliCreator._get_platform(target)
        if platform == 'mxs40sv2':
            if target == 'psoc_c3':
                module_name = 'cli_psoc_c3'
            elif target in ('psoc_c3p8', 'psoc_c3x7', 'psoc_c3x8'):
                module_name = 'cli_psoc_c3p8'
            else:
                if not is_help:
                    CliCreator.validate_policy_presence(target)
                module_name = 'cli_mxs40sv2'
        elif platform == 'psoc64':
            module_name = 'cli_mxs40v1'
        elif platform == 'mxs22':
            if target in ('acw64xx', 'acw74xx'):
                module_name = 'cli_acwx4xx'
            elif target in ('pse84', 'pse8xs2', 'pse8xs4'):
                module_name = 'cli_pse8x'
            elif target == 'psb3xxx':
                module_name = 'cli_psb3xxx'
            else:
                module_name = 'cli_mxs22'
        elif platform == 'traveo_t2g':
            module_name = 'cli_traveo_t2g'
        elif platform == 'cyw559xx':
            module_name = 'cli_cyw559xx'
        else:
            module_name = None if target else 'cli'

        try:
            module = import_module(f'.{module_name}', package=package_name())
        except ModuleNotFoundError:
            CliCreator.unknown_target_error(target)
            sys.exit(2)
        else:
            module.main(standalone_mode=not is_help)
            common_commands = CliCreator._command_list(base_cli.main)
            if not any(a in common_commands for a in sys.argv[1:]) and is_help:
                CliCreator._print_help_instructions()

    @staticmethod
    def validate_policy_presence(target):
        """ Validates 'policy' option presence. Exits the process
        on error.

        For the mxs40sv2 platform, specifying policy is necessary for
        all commands except the common commands (those which do not
        require specifying target) and 'init' command
        """
        platform = CliCreator._get_platform(target)
        if platform == 'mxs40sv2':
            common_cmds = CliCreator._command_list(base_cli.main)
            from . import cli_mxs40sv2
            mxs40v2_cmds = CliCreator._command_list(cli_mxs40sv2.main)
            mxs40v2_cmds = [c for c in mxs40v2_cmds if c not in common_cmds]
            mxs40v2_cmds.remove('init')
            mxs40v2_cmds.remove('extend-image')
            mxs40v2_cmds.remove('device-info')
            mxs40v2_cmds.remove('read-die-id')
            mxs40v2_cmds.remove('load-and-run-app')
            mxs40v2_cmds.remove('convert-to-rma')
            mxs40v2_cmds.remove('encrypt')
            policy = CliCreator.option_from_args(['-p', '--policy'])
            if policy is None:
                if any(a in mxs40v2_cmds for a in sys.argv[1:]):
                    CliCreator.option_error(target, ['-p', '--policy'])

    @staticmethod
    def option_error(target, opt):
        """ Shows missing option error and exits the process """
        if len(opt) == 0:
            raise ValueError('No options specified')
        if len(opt) > 2:
            raise ValueError('More than two options specified')

        app_name = os.path.basename(sys.argv[0])
        if target is not None:
            sys.stderr.write(
                f"Try '{app_name} -t {target} --help' for help.\n\n")

        if len(opt) == 1:
            sys.stderr.write(f"Error: Missing option '{opt[0]}'.\n")
        if len(opt) == 2:
            sys.stderr.write(
                f"Error: Missing option '{opt[0]}' / '{opt[1]}'.\n")
        sys.exit(2)

    @staticmethod
    def unknown_target_error(target):
        """ Shows unknown target error and exits the process """
        app_name = os.path.basename(sys.argv[0])
        sys.stderr.write(f"Try '{app_name} device-list' for output of the "
                         f"supported devices list.\n\n")
        sys.stderr.write(f'Error: Unknown target \'{target}\'.\n')
        sys.exit(2)

    @staticmethod
    def option_from_args(opt):
        """ Gets specified option from command line arguments """
        args = sys.argv[1:]
        try:
            return [args[i + 1] for i in range(len(args)) if args[i] in opt][0]
        except IndexError:
            return None

    @staticmethod
    def _get_platform(target_name):
        platform = None
        if target_name is not None:
            try:
                target = target_data(target_name.lower())
                platform = target.get('platform')
            except KeyError:
                platform = None
        return platform

    @staticmethod
    def _command_list(obj):
        if isinstance(obj, click.Group):
            return [name for name, value in obj.commands.items()]
        return None

    @staticmethod
    def _print_help_instructions():
        app_name = os.path.basename(sys.argv[0])
        print()
        print('Command line interfaces are different for different targets.\n')
        print('To see a list of commands supported for a specific target:')
        print(f'{app_name} -t <TARGET> --help\n')
        print('To see a list of options for a specific command:')
        print(f'{app_name} -t <TARGET> <COMMAND> --help\n')
        print('To see a list of available targets:')
        print(f'{app_name} device-list\n')
        print('For detailed usage description refer to readme.md')
