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
import sys
import datetime

from .project_base import ProjectInitializerBase
from .logging_formatter import CustomFormatter
from ..pkg_globals import PkgData


class LoggingConfigurator:
    """
    The class that allows configuring the way how the data is logged
    """
    console_handler = None
    file_handler = None

    @staticmethod
    def initialize_console_logger():
        """Initialize console logger"""
        logging.root.setLevel(logging.DEBUG)
        fmt = CustomFormatter()
        console_handler = logging.StreamHandler(sys.stdout)
        console_handler.setFormatter(fmt)
        console_handler.setLevel(logging.INFO)
        logger = logging.getLogger(__name__)
        logger.root.addHandler(console_handler)
        LoggingConfigurator.console_handler = console_handler

    @staticmethod
    def disable_logging():
        """Disable all logging calls of severity 'CRITICAL' and below"""
        logging.disable(logging.CRITICAL)

    @staticmethod
    def enable_logging():
        """Restore disabled logging"""
        logging.disable(logging.NOTSET)

    @staticmethod
    def set_logger_level(level):
        """Sets logging level (ERROR, WARNING, INFO, DEBUG)"""
        root_logger = logging.getLogger()
        root_logger.setLevel(level)
        for handler in root_logger.handlers:
            if isinstance(handler, type(logging.StreamHandler())):
                handler.setLevel(level)

    @staticmethod
    def initialize_file_logger():
        """Adds file logger"""
        logfile_fmt = CustomFormatter()
        prefix = logfile_fmt.package_name
        log_dir = LoggingConfigurator.get_log_dir()
        log_filename = datetime.datetime.now().strftime(
            os.path.join(log_dir, f'{prefix}_%Y-%m-%d_%H-%M-%S.log'))
        os.makedirs(log_dir, exist_ok=True)
        file_handler = logging.FileHandler(log_filename, mode='w+',
                                           encoding='utf-8')
        file_handler.setLevel(logging.DEBUG)
        file_handler.setFormatter(logfile_fmt)
        logfile_fmt.enable_timestamps()
        logger = logging.getLogger(__name__)
        logger.root.addHandler(file_handler)
        LoggingConfigurator.file_handler = file_handler

    @staticmethod
    def get_log_dir():
        """Gets a directory where user log files are stored"""
        if ProjectInitializerBase.is_project():
            data_dir = os.getcwd()
        else:
            data_dir = PkgData.pkg_user_data_dir()
        return os.path.join(data_dir, 'logs')
