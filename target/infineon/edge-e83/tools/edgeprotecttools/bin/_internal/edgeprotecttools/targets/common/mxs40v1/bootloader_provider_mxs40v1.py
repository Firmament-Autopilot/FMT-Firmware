"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import logging

from ....core.project_base import ProjectInitializerBase
from ....core.cy_bootloader_map_parser import CyBootloaderMapParser

logger = logging.getLogger(__name__)


class BootloaderProviderMXS40v1:
    def __init__(self, target):
        self.target = target
        self.policy_parser = target.policy_parser
        self.cb_dir = ProjectInitializerBase.prebuilt_dirname

    def hex_path(self, from_project=None):
        """
        Gets CyBootloader hex-file path.
        :return: File path.
        """
        build_mode = self.policy_parser.get_cybootloader_mode()

        if from_project is None:
            from_project = self.target.project_initializer.is_project()

        if build_mode == 'custom':
            filename = self.policy_parser.get_cybootloader_hex()
        else:
            filename = self._get_filename_from_map('hex', from_project)

        return os.path.abspath(filename)

    def jwt_path(self, build_mode=None, from_project=None):
        """
        Gets CyBootloader jwt-file path.
        :param build_mode: CyBootloader mode (release or debug). If not
               specified, the mode specified in policy will be used
        :param from_project: If True this method will return jwt_path
               from the project, otherwise from the package
        :return: File path.
        """
        if not build_mode:
            build_mode = self.policy_parser.get_cybootloader_mode()

        if from_project is None:
            from_project = self.target.project_initializer.is_project()

        if build_mode == 'custom':
            filename = self.policy_parser.get_cybootloader_jwt()
        else:
            filename = self._get_filename_from_map('jwt', from_project)

        return os.path.abspath(filename)

    def _get_filename_from_map(self, file_type, from_project=False):
        build_mode = self.policy_parser.get_cybootloader_mode()
        upgrade_mode = self.policy_parser.get_upgrade_mode()
        try:
            filename = CyBootloaderMapParser.get_filename(
                self.target.name, upgrade_mode, build_mode, file_type)
            if from_project:
                filename = os.path.join(self.target.cwd, self.cb_dir, filename)
            else:
                filename = os.path.join(self.target.target_dir, self.cb_dir,
                                        filename)
        except KeyError as e:
            logger.error(e)
            filename = ''

        return filename
