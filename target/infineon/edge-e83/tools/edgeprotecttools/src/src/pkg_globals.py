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
import platform

from .__about__ import (__pkg_author__, __pkg_name__, __version__,
                        __pkg_short_name__, __github_url__)


class PkgData:
    """Brings together package data for global use across the modules"""

    alt_pkg_user_data_dir = None
    """Alternative directory where the package user data is stored"""

    @staticmethod
    def pkg_name():
        """Gets the package name"""
        return __pkg_name__

    @staticmethod
    def pkg_version():
        """Gets the package version"""
        return __version__

    @staticmethod
    def pkg_author():
        """Gets the package author"""
        return __pkg_author__

    @staticmethod
    def pkg_short_name():
        """Gets the package short name. Used for marking logger messages
        to distinguish them from messages of other applications
        """
        return __pkg_short_name__

    @staticmethod
    def pkg_dir():
        """Gets package installation directory"""
        return os.path.abspath(os.path.dirname(os.path.realpath(__file__)))

    @staticmethod
    def pkg_data_dir():
        """Gets package data directory"""
        return os.path.join(PkgData.pkg_dir(), 'data')

    @staticmethod
    def pkg_settings():
        """Gets the package global settings file location"""
        return os.path.join(PkgData.pkg_user_data_dir(), 'settings.json')

    @staticmethod
    def pkg_github_url():
        """Gets the package GitHub URL"""
        return __github_url__

    @staticmethod
    def pkg_user_data_dir():
        """Gets a directory where the package user data is stored"""
        if PkgData.alt_pkg_user_data_dir is not None:
            return PkgData.alt_pkg_user_data_dir

        system = platform.system()

        if system == 'Darwin':
            user_data_dir = os.path.expanduser('~/Library/Application Support')
        elif system == 'Linux':
            user_data_dir = os.path.expanduser('~/.local/share')
        elif system == 'Windows':
            user_data_dir = os.environ.get('LOCALAPPDATA')
            if user_data_dir is None:
                raise ValueError('Unset environment variable: LOCALAPPDATA')
        else:
            raise ValueError(f'Unsupported OS platform: {system}')

        author_dir_name = PkgData.pkg_author().replace(' ', '_')
        return os.path.join(user_data_dir, author_dir_name, PkgData.pkg_name())
