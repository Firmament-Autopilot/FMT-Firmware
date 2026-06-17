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
import os

from intelhex import IntelHex

from ...common.mxs40sv2.asset_enums import ApPermission
from ...common.mxs40sv2.dlm_package import DLMPackage
from ...common.mxs40sv2.provisioning import SwdLoaderMXS40SV2
from ....core.enums import ProvisioningStatus

logger = logging.getLogger(__name__)


class SwdLoaderPsocC3(SwdLoaderMXS40SV2):
    """Loads applications through the SWD port"""

    def load_application(self):
        """ Programs application into RAM """
        lcs = self.target.version_provider.get_lifecycle_stage(self.tool)

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

    def load_dlm(self):
        lcs = self.target.version_provider.get_lifecycle_stage(self.tool)

        if lcs in self.app.allowed_lcs:
            logger.info("Programming '%s' DLM package (%s)",
                        self.app.name, self.app.dlm_path)

            self.tool.program_ram(self.app.dlm_path)
            self.tool.write32(self.target.register_map.BOOT_DLM_CTL_2,
                              self.app.image_address)

            logger.info('Programming complete')
            status = ProvisioningStatus.OK

            policy_parser = self.target.policy_parser

            if policy_parser.json and \
                policy_parser.policy_type() == 'oem_provisioning':
                status = self.check_ap_config(self.app.dlm_path, lcs)

            return status

        logger.warning("Skip programming '%s' application. The device "
                       "lifecycle stage is %s", self.app.name, lcs)
        return ProvisioningStatus.SKIPPED

    def read_app_output(self):
        """Reads application output and saves to a file"""
        logger.info('Read application output')
        addr = self.app.image_address + self.app.out_results_offset

        self.reset()

        size = self.app.out_results_size
        if not size:
            try:
                num_bytes = self.tool.read32(
                    self.app.image_address + self.app.out_results_offset
                )
            except RuntimeError as e:
                logger.error('Reading application output failed')
                raise e

            size = num_bytes + self.PACKET_SIZE

        self.tool.dump_image(self.app.out_results_path, addr, size)
        logger.info("Application output saved to '%s'",
                    os.path.abspath(self.app.out_results_path))

    def process_app_status(self, status):
        """ Handles app execution status """
        result = ProvisioningStatus.OK

        if status == self.app_status_codes.code_by_name('CYAPP_SUCCESS'):
            logger.info('Application execution successfully completed')
        else:
            self.print_ram_app_status(status)
            result = ProvisioningStatus.FAIL

        return result

    def check_ap_config(self, dlm_path, lcs):
        """Deserialize RAM app input parameters and check AP configuration"""
        status = ProvisioningStatus.OK
        ihex = IntelHex(dlm_path)
        dlm = ihex.tobinarray().tobytes()
        dlm_data = DLMPackage(dlm, self.app)
        in_params = dlm_data.in_params

        strategy = self.target.provisioning_packet_strategy
        policy_parser = self.target.policy_parser
        policy_parser.json = strategy.reverse_conversion(
            self.target, in_params, None
        )

        if lcs in ('NORMAL_PROVISIONED', 'SECURE'):
            ap_enable = ApPermission.Enable
            if policy_parser.debug_ap_system() != ap_enable or \
                    policy_parser.debug_sys_secure() != ap_enable:
                logger.info('System AP disabled')
                status = ProvisioningStatus.STOP
        return status

    def _load(self):
        if self.app.dlm_path:
            funcs = (
                self.check_romboot_readiness,
                self.load_dlm
            )
        else:
            funcs = (
                self.check_romboot_readiness,
                self.load_application,
                self.load_input_parameters
            )
        for func in funcs:
            status = func()
            if status != ProvisioningStatus.OK:
                return status
        return ProvisioningStatus.OK
