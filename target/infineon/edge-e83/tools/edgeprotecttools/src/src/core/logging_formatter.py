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
import logging

from ..pkg_globals import PkgData


class CustomFormatter(logging.Formatter):
    error_fmt = ': ##_package_## : ERROR : %(message)s'
    debug_fmt = ': ##_package_## : DEBUG : %(name)s, line %(lineno)d: %(message)s'
    warning_fmt = ': ##_package_## : WARN  : %(message)s'
    info_fmt = ': ##_package_## : INFO  : %(message)s'

    def __init__(self):
        super().__init__(fmt="%(levelno)d: %(msg)s", datefmt=None, style='%')
        self.style = self._style = CustomPercentStyle()
        self.original_format = self.style.fmt
        self.package_name = PkgData.pkg_name().lower()
        self.package_short_name = PkgData.pkg_short_name()

    def enable_timestamps(self):
        """Enable displaying timestamps in log messages"""
        self.error_fmt = '%(asctime)s ' + self.error_fmt
        self.debug_fmt = '%(asctime)s ' + self.debug_fmt
        self.warning_fmt = '%(asctime)s ' + self.warning_fmt
        self.info_fmt = '%(asctime)s ' + self.info_fmt

    def disable_timestamps(self):
        """Disable displaying timestamps in log messages"""
        self.error_fmt = self.error_fmt.replace('%(asctime)s ', '')
        self.debug_fmt = self.debug_fmt.replace('%(asctime)s ', '')
        self.warning_fmt = self.warning_fmt.replace('%(asctime)s ', '')
        self.info_fmt = self.info_fmt.replace('%(asctime)s ', '')

    def format(self, record):
        if record.levelno == logging.DEBUG:
            self.style.fmt = self.debug_fmt

        elif record.levelno == logging.INFO:
            self.style.fmt = self.info_fmt

        elif record.levelno == logging.WARNING:
            self.style.fmt = self.warning_fmt

        elif record.levelno == logging.ERROR:
            self.style.fmt = self.error_fmt

        if 'openocd' in record.name:
            package = 'O'
        elif record.name.startswith(self.package_name):
            package = self.package_short_name
            if record.levelno == logging.ERROR:
                self.style.fmt += '. Check the log for details'
        else:
            package = ' '

        self.style.fmt = self.style.fmt.replace('##_package_##', package)

        result = logging.Formatter.format(self, record)

        self.style.fmt = self.original_format

        return result


class CustomPercentStyle(logging.PercentStyle):
    def __init__(self, fmt=None):
        super().__init__(fmt)

    @property
    def fmt(self):
        return self._fmt

    @fmt.setter
    def fmt(self, fmt):
        self._fmt = fmt
