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
import re
import logging
from abc import ABC, abstractmethod
from xml.etree import ElementTree

import json

from .. import __path__ as site_packages
from ..pkg_globals import PkgData
from ..targets.common.flow_parser import FlowParser

logger = logging.getLogger(__name__)


class VersionProvider(ABC):
    """Base class for the classes that implement version provider"""

    def __init__(self, target):
        self.target = target
        self.project = target.project_initializer

    @abstractmethod
    def print_version(self, **kwargs):
        """Prints the package version and RAMApps versions bundled with
        the package
        """

    @abstractmethod
    def print_fw_version(self, tool):
        """Prints a BootROM version from the device"""

    @abstractmethod
    def log_version(self, tool):
        """Logs lifecycle stage of the device"""

    @abstractmethod
    def check_compatibility(self, tool, **_):
        """Verifies HW compatibility"""

    @staticmethod
    def print_package_version():
        """Prints the package version"""
        print(f'\n{PkgData.pkg_name()}: {PkgData.pkg_version()}')

    def print_ram_apps_version(self, **kwargs):
        """Prints versions of the RAM applications bundled with the package"""
        package_apps = self.package_ramapp_versions()
        print('\tPackage:')
        print('\t\tRAM Applications:')
        for app_name in package_apps:
            print(f'\t\t - {app_name}: {package_apps.get(app_name)}')
        if self.project.is_project():
            project_apps = self.project_ramapp_versions(kwargs.get('testapps'))
            print('\tProject:')
            print('\t\tRAM Applications:')
            for app_name in project_apps:
                print(f'\t\t - {app_name}: {project_apps.get(app_name)}')

    def project_ramapp_versions(self, test_pkg_type=False):
        """Gets a list of RAM Apps version(s) in the project"""
        versions = None
        if self.project.is_project():
            versions = self._ramapp_versions(
                self.project.apps_dir, test_pkg_type=test_pkg_type)
        return versions

    def package_ramapp_versions(self):
        """Gets a list of RAM Apps version(s) bundled with the package"""
        return self._ramapp_versions(self.project.pkg_apps_dir)

    def _ramapp_versions(self, apps_path, test_pkg_type=None):
        """Gets a dictionary with a RAM application name-version pairs"""
        apps = self._apps_path(test_pkg_type)
        versions = {}
        for app_name, config_path in apps.items():
            app_dir = os.path.basename(os.path.dirname(config_path))
            info_path = os.path.join(apps_path, app_dir, 'info.txt')
            try:
                with open(info_path, encoding='utf-8') as f:
                    info = f.read()
                    version = re.search(r'version:\s([0-9.]+)', info)[1]
            except (FileNotFoundError, TypeError):
                version = 'unknown'
            versions.update({app_name: version})
        return versions

    def _apps_path(self, test_pkg_type):
        """Gets a dictionary with the applications name-path"""
        flow_parser = FlowParser(self.target, test_pkg_type=test_pkg_type)
        apps = flow_parser.get_apps_paths()
        return apps

    @staticmethod
    def print_package_installation_source():
        """Prints the package installation source. Used for debugging"""
        dist_source = VersionProvider.dist_source()
        if dist_source:
            logger.debug('URL: %s', dist_source.get('url'))
            vcs_info = dist_source.get('vcs_info')
            if vcs_info is not None:
                revision = vcs_info.get('requested_revision')
                commit = vcs_info.get('commit_id')
                if revision is not None:
                    logger.debug('Branch/tag: %s', revision)
                if commit is not None:
                    logger.debug('Commit: %s', commit)
        else:
            logger.debug('Not able to find installation source details')

    @staticmethod
    def dist_info():
        """Gets information about installed distribution"""
        version_xml = VersionProvider.version_xml()
        info = {
            'name': PkgData.pkg_name(),
            'version': version_xml or PkgData.pkg_version()
        }
        dist_source = VersionProvider.dist_source()
        if dist_source:
            info.update(dist_source)
        return info

    @staticmethod
    def dist_source():
        """Gets the Direct URL Origin of installed distribution"""
        direct_url = os.path.join(
            f'{site_packages[0]}-{PkgData.pkg_version()}.dist-info',
            'direct_url.json')
        if os.path.isfile(direct_url):
            with open(direct_url, encoding='utf-8') as f:
                return json.load(f)
        return None

    @staticmethod
    def version_xml():
        """Gets the version of the package from the version.xml if exists"""
        version_xml = os.path.join(PkgData.pkg_dir(), '..', 'version.xml')
        if os.path.isfile(version_xml):
            tree = ElementTree.parse(version_xml)
            root = tree.getroot()
            return root.text
        return None
