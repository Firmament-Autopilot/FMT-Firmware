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
import logging

from .swd_loader_mxs40sv2 import SwdLoaderMXS40SV2
from .....core.ram_app_loader_base import RamAppLoader
from .....execute.programmer.dfuht_wrapper import Dfuht

logger = logging.getLogger(__name__)


class RamAppLoaderMXS40Sv2(RamAppLoader):
    """ A class that implements loading RAM application routine """

    def __init__(self, app_status_codes):
        self.tool = None
        self.target = None
        self.app = None
        self.app_status_codes = app_status_codes

    def load(self, tool, target, app):
        """ Loads application and its input parameters into RAM """
        self.tool = tool
        self.target = target
        self.app = app

        if isinstance(self.tool, Dfuht):
            raise NotImplementedError('Serial interface not supported')

        loader = SwdLoaderMXS40SV2(
            self.tool, self.target, self.app, self.app_status_codes
        )
        return loader.load()

    def load_application(self):
        """ Programs application into RAM """

    def reset(self):
        """ Reset device using RES_SOFT_CTL register """
