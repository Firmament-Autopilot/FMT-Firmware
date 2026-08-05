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

from ...execute.project_init import ProjectInitializer

logger = logging.getLogger(__name__)


class ProjectInitializerCYW559xx(ProjectInitializer):
    """
    A class that implements project creation logic for CYW559xx target
    """

    def init(self, cwd=None, overwrite=None, **kwargs):
        """
        Initializes new project
        :param cwd: Current working directory
        :param overwrite: indicates whether the existing project files have
                to be overwritten. If the value is None, an interactive prompt
                will ask whether to overwrite existing files
        """
        if cwd:
            self.cwd = cwd

        self.test_pkg_type = kwargs.get('testapps')
        self.flow_parser.test_pkg_type = self.test_pkg_type
        self.apps_paths = self.flow_parser.get_apps_paths()

        self.create_project(overwrite=overwrite)

    @property
    def misc_files(self):
        """
        Gets miscellaneous project files
        Must follow the project folder structure for cyw559xx target
        """
        return {
            self.keys_dirname: [
                'rsa_key_tmpl.json'
            ],
            self.packets_dirname: [
            ],
            'certs': [
                'key_cert_config.json',
                'content_cert_config.json',
                'x509cert.json'
            ]
        }
