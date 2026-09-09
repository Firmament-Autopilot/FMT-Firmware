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

from .swd_loader import SwdLoaderPsocC3
from .serial_loader import SerialLoaderPsocC3
from ...common.mxs40sv2 import RamAppLoaderMXS40Sv2
from ...common.mxs40sv2.enums import LifecycleStage
from ....core.enums import ProvisioningStatus
from ....execute.programmer.dfuht_wrapper import Dfuht

logger = logging.getLogger(__name__)


class RamAppLoaderPsocC3(RamAppLoaderMXS40Sv2):
    """ A class that implements loading RAM application routine """

    def load(self, tool, target, app):
        """ Loads application and its input parameters into RAM """
        self.tool = tool
        self.target = target
        self.app = app

        if isinstance(self.tool, Dfuht):
            loader = SerialLoaderPsocC3(
                self.tool, self.target, self.app, self.app_status_codes
            )
        else:
            loader = SwdLoaderPsocC3(
                self.tool, self.target, self.app, self.app_status_codes
            )
        return loader.load()

    def load_application(self):
        """ Programs application into RAM """
        lcs = self.target.silicon_data_reader.read_lifecycle_stage(self.tool)
        lcs = LifecycleStage(lcs).name.upper()

        if lcs in self.app.allowed_lcs:
            logger.info("Programming '%s' application at address 0x%x (%s)",
                        self.app.name, self.app.image_address,
                        self.app.image_path)

            self.tool.program_ram(self.app.image_path,
                                  address=self.app.image_address)
            self.tool.write32(self.target.register_map.BOOT_DLM_CTL_2,
                              self.app.image_address)

            logger.info('Programming complete')
            return ProvisioningStatus.OK

        logger.warning("Skip programming '%s' application. The device "
                       "lifecycle stage is %s", self.app.name, lcs)
        return ProvisioningStatus.SKIPPED
