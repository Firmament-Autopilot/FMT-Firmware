"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import importlib

from ...core.project_base import ProjectInitializerBase
from ...targets.common.flow_parser import FlowParser

logger = logging.getLogger(__name__)


class ProjectInitializer(ProjectInitializerBase):
    """
    A class that implements project creation logic
    """

    def __init__(self, target):
        super().__init__(target)
        self.test_pkg_type = None
        self.apps_paths = {}

        self.packets_src = os.path.join(self.target_dir, self.packets_dirname)
        self.packets_dst = os.path.join(self.cwd, os.path.basename(
            os.path.normpath(self.packets_src)))
        self.apps_src = os.path.join(self.target_dir, self.packets_dirname)
        self.keys_src = os.path.join(self.target_dir, self.keys_dirname)

        self.flow_parser = FlowParser(self.target)
        self.test_packages = target.test_packages

    @property
    def policy_dir(self):
        """
        Returns path to policy directory
        """
        if self.policy_parser.policy_dir is None:
            if self.is_project():
                policy_dir = os.path.join(self.cwd, self.policy_dirname)
            else:
                policy_dir = os.path.join(self.target.target_dir,
                                          self.policy_dirname)
        else:
            policy_dir = self.policy_parser.policy_dir
        return policy_dir

    @property
    def packets_dir(self):
        """ Gets a path to the packets directory in the project """
        return os.path.abspath(os.path.join(
            self.policy_dir, '..', self.packets_dirname))

    @property
    def apps_dir(self):
        """ Gets a path to the apps directory in the project """
        return os.path.join(self.packets_dir, self.apps_dirname)

    @property
    def pkg_apps_dir(self):
        """ Gets a path to the apps directory in the package """
        return os.path.join(
            self.target_dir, self.packets_dirname, self.apps_dirname)

    @property
    def test_policies_dir(self):
        """ A path to a directory containing test policies """
        if self.test_pkg_type is not None:
            package_data = self.test_packages.get(self.test_pkg_type)
            package_name = package_data['package']
            try:
                module = importlib.import_module(package_name)
                if module.__file__ is None:
                    raise ImportError(f"No module named '{package_name}'")
            except ImportError as e:
                raise ImportError(
                    f'Test applications not found. {e.msg}') from e
            if os.path.exists(module.TEST_POLICY_DIR):
                return module.TEST_POLICY_DIR
        return None

    def init(self, cwd, overwrite):
        """Initializes new project"""
        raise NotImplementedError

    def create_project(self, overwrite=None):
        """
        Creates new project
        :param overwrite: indicates whether the existing project files have
                to be overwritten. If the value is None, an interactive prompt
                will ask whether to overwrite existing files
        """
        if overwrite is None:
            if self.existing_files:
                print('%s' % '\n'.join(self.existing_files))
                answer = input(f'{len(self.existing_files)} files exist '
                               f'and will be overwritten. Continue? (y/n): ')
                if answer.strip() == 'y':
                    self.copy_project_files()
                else:
                    logger.info('Skip project creation')
            else:
                self.copy_project_files()
        elif overwrite is True:
            self.copy_project_files()
        else:
            logger.info('Skip project creation')

    @property
    def existing_files(self):
        """ Gets existing files in project directory """
        return self.existing_apps + self.existing_misc_files \
            + self.existing_policies + self.existing_keys

    @property
    def existing_apps(self):
        """ Gets existing RAM applications in project directory """
        apps = []
        app_paths = self.flow_parser.get_apps_paths()
        for d, f in app_paths.items():
            files = self._filenames_from_dir(os.path.dirname(f))
            app_dst = os.path.join(self.packets_dst, self.apps_dirname, d)
            apps.extend(self.get_existent(app_dst, files))
        return apps

    @property
    def existing_keys(self):
        """ Gets existing keys in project directory """
        keys_dst = os.path.join(self.cwd, self.keys_dirname)
        files = self._filenames_from_dir(self.keys_src, 'pem')
        return self.get_existent(keys_dst, files)

    @property
    def existing_policies(self):
        """ Gets existing policies in project directory """
        policy_dst = os.path.join(self.cwd, self.policy_dirname)
        files = self.get_policy_src_files(self.policy_src)
        return self.get_existent(policy_dst, files)

    @property
    def existing_misc_files(self):
        """ Gets existing miscellaneous files in project directory """
        existing = []
        for file_dir, files in self.misc_files.items():
            src = os.path.join(self.target_dir, file_dir)
            dst = os.path.join(self.cwd, os.path.basename(
                os.path.normpath(src)))
            existing.extend(self.get_existent(dst, files))
        return existing

    def copy_project_files(self):
        """
        Copies all files from the package directory to the project directory
        """
        self.copy_apps()
        self.copy_policies()
        self.copy_keys()
        self.copy_misc_files()
        self.create_config_file()

    def copy_policies(self):
        """
        Copies policy files from the package directory to the
        project directory
        """
        if self.test_pkg_type:
            src = (self.policy_src, self.test_policies_dir)
        else:
            src = (self.policy_src, )
        dst = os.path.join(self.cwd, self.policy_dirname)
        for policy_src in src:
            if not policy_src:
                continue
            files = self.get_policy_src_files(policy_src)
            self.copy_files(policy_src, dst, files)

    def copy_keys(self):
        """
        Copies key files from the package directory to the
        project directory
        """
        src = self.keys_src
        dst = os.path.join(self.cwd, self.keys_dirname)
        files = self._filenames_from_dir(self.keys_src, ext='pem')
        self.copy_files(src, dst, files)

    def copy_apps(self):
        """
        Copies ram applications data from the package directory to the
        project directory
        """
        apps_paths = self.flow_parser.get_apps_paths()
        apps_dir_dst = os.path.join(
            self.cwd, self.packets_dirname, self.apps_dirname)
        for app_name, file_name in apps_paths.items():
            dst = os.path.join(apps_dir_dst, app_name)
            src = os.path.dirname(file_name)
            files = self._filenames_from_dir(src)
            self.copy_files(src, dst, files)

    def copy_misc_files(self):
        """
        Copies miscellaneous files from the package directory to the
        project directory
        """
        for file_dir, files in self.misc_files.items():
            src = os.path.join(self.target_dir, file_dir)
            dst = os.path.join(self.cwd, os.path.basename(
                os.path.normpath(src)))
            self.copy_files(src, dst, files)

    def create_config_file(self):
        """ Creates project configuration file """
        self.create_config(self.target.default_policy)

    @property
    def misc_files(self):
        """
        Gets miscellaneous project files
        Must follow target project folder structure
        """
        return {}
