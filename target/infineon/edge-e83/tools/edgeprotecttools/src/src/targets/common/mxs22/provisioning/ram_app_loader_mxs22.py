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

from .serial_loader import SerialLoader
from .swd_loader_mxs22 import SwdLoaderMXS22
from .....core.enums import ProvisioningStatus
from .....core.ram_app_loader_base import RamAppLoader
from .....execute.programmer.dfuht_wrapper import Dfuht

logger = logging.getLogger(__name__)


class RamAppLoaderMXS22(RamAppLoader):
    """ A class that implements loading RAM application routine """

    def __init__(self, app_status_codes):
        self.tool = None
        self.target = None
        self.app = None
        self.app_status_codes = app_status_codes

    def load(self, tool, target, app, flow_name=None):
        """ Loads application and its input parameters into RAM """
        self.tool = tool
        self.target = target
        self.app = app
        lcs = self.target.version_provider.get_lifecycle_stage(self.tool)
        if isinstance(self.tool, Dfuht):
            loader = SerialLoader(
                self.tool, self.target, self.app, self.app_status_codes)
        else:
            loader = SwdLoaderMXS22(
                self.tool, self.target, self.app, self.app_status_codes,
                lcs=lcs, flow_name=flow_name)

        if self._lcs_compatibility_check(self.app, lcs):
            logger.error('The RAM application cannot be executed due to '
                         'invalid lifecycle stage')
            return ProvisioningStatus.SKIPPED
        return loader.load()

    def reset(self):
        """ Reset device via a reset pin """
        self.tool.reset()

    def _lcs_compatibility_check(self, app, lcs):
        if lcs not in app.allowed_lcs:
            logger.warning("Skip programming '%s' application. The device "
                           "lifecycle stage is %s", self.app.name, lcs)
            return True
        return False
