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
import time
import logging

from ..enums import LifecycleStage
from .....execute.programmer.base import AP
from .....core.enums import ProvisioningStatus

logger = logging.getLogger(__name__)


class SwdLoaderMXS40SV2:
    """Loads applications through the SWD port"""
    WAIT_FOR_APP_TIMEOUT = 200
    WAIT_APP_END_TIMEOUT = 200
    CYAPP_STATE_FINISHED = 2
    INPUT_PARAM_MIN_SIZE = 8

    RES_SOFT_CTL_RESET_RQST = 0x00000001
    TST_DBG_CTL_WAIT_APP_RQST = 0x00000001
    TST_DBG_CTL_WFA_Msk = 0x80000000

    TST_DBG_STS_APP_WFA_SET = 0x0D500080
    TST_DBG_STS_APP_LAUNCHED = 0x0D500081
    TST_DBG_STS_APP_NOT_LAUNCHED = 0x0D500082
    TST_DBG_STS_APP_RUNNING = 0xF2A00010

    PACKET_SIZE = 0x4
    OUT_FILE_SIZE_MAX = 16384

    def __init__(self, tool, target, app, app_status_codes):
        self.tool = tool
        self.target = target
        self.app = app
        self.app_status_codes = app_status_codes

    def load(self):
        """Loads applications"""
        self.tool.set_ap(AP.SYS)
        time.sleep(0.2)
        self.tool.reset()

        ctrl_reg = self.tool.read32(self.target.register_map.TST_DEBUG_CTL)
        if (ctrl_reg & self.TST_DBG_CTL_WFA_Msk) == 0:
            self.tool.write32(self.target.register_map.TST_DEBUG_CTL,
                              self.TST_DBG_CTL_WAIT_APP_RQST)
            self.reset()
            logger.debug('Waiting until ROM_BOOT stopped '
                         'and read for application upload...')

        status = self._load()
        if status != ProvisioningStatus.OK:
            return status

        logger.debug('Clear DEBUG_IMAGE bit in SRSS_TST_DEBUG_CTL register '
                     'to start application')
        self.tool.write32(self.target.register_map.TST_DEBUG_CTL, 0)
        self.tool.resume()

        status = self.app_completion_status()

        if status == ProvisioningStatus.OK and self.app.out_results_path:
            self.read_app_output()

        self.reset()
        return status

    def check_romboot_readiness(self):
        """ Checks whether ROM_BOOT is ready for application programming """
        status = ProvisioningStatus.OK
        counter = 0
        while (self.tool.read32(self.target.register_map.TST_DEBUG_CTL) &
               self.TST_DBG_CTL_WFA_Msk) == 0:
            counter += 1
            if counter > self.WAIT_FOR_APP_TIMEOUT:
                raise TimeoutError('ROM_BOOT did not set flag '
                                   'waiting for application')
            time.sleep(0.1)
        debug_sts = self.tool.read32(self.target.register_map.TST_DEBUG_STATUS)
        if debug_sts != self.TST_DBG_STS_APP_WFA_SET:
            logger.error('TST_DEBUG_STATUS: 0x%x',
                         self.target.register_map.TST_DEBUG_STATUS)
            logger.error(
                'TST_DEBUG_CTL: 0x%x', self.target.register_map.TST_DEBUG_CTL)
            logger.error('ROM_BOOT did not set expected TST_DEBUG_STATUS')
            status = ProvisioningStatus.FAIL
        else:
            logger.debug('Ready for application programming')

        return status

    def load_application(self):
        """ Programs application into RAM """
        lcs = self.target.silicon_data_reader.read_lifecycle_stage(self.tool)
        lcs = LifecycleStage(lcs).name.upper()
        if lcs in self.app.allowed_lcs:
            logger.info(
                "Programming '%s' application at address 0x%x (%s)",
                self.app.name, self.app.image_address, self.app.image_path)
            self.tool.program_ram(
                self.app.image_path, address=self.app.image_address)
            logger.info('Programming complete')
            status = ProvisioningStatus.OK
        else:
            logger.warning("Skip programming '%s' application. The device "
                           "lifecycle stage is %s", self.app.name, lcs)
            status = ProvisioningStatus.SKIPPED
        return status

    def load_input_parameters(self):
        """ Programs application input parameters """
        status = ProvisioningStatus.OK
        if self.app.in_params_path and os.path.isfile(self.app.in_params_path):
            file_size = os.path.getsize(self.app.in_params_path)
            if file_size > self.INPUT_PARAM_MIN_SIZE:
                logger.info(
                    "Programming '%s' application input parameters at address "
                    "0x%x (%s)", self.app.name, self.app.in_params_address,
                    self.app.in_params_path)
                self.tool.program_ram(self.app.in_params_path,
                                      address=self.app.in_params_address)
                logger.info('Programming complete')
            else:
                raise ValueError(f'Input parameters size must be larger then '
                                 f'{self.INPUT_PARAM_MIN_SIZE} '
                                 f'bytes ({self.app.in_params_path}')
        else:
            logger.debug('No input parameters provided, skipped')

        return status

    def app_completion_status(self):
        """ Checks application programming status """
        # Wait until debugger is connected and TST_DEBUG_STATUS is changed
        timeout = 0
        status = self.TST_DBG_STS_APP_WFA_SET
        while status == self.TST_DBG_STS_APP_WFA_SET:
            timeout += 1
            if timeout > self.WAIT_APP_END_TIMEOUT:
                raise TimeoutError('Application did not return status')
            time.sleep(0.1)
            try:
                status = self.tool.read32(
                    self.target.register_map.TST_DEBUG_STATUS)
            except RuntimeError:
                status = self.TST_DBG_STS_APP_WFA_SET

        # Wait for application completion
        while status in [self.TST_DBG_STS_APP_LAUNCHED,
                         self.TST_DBG_STS_APP_RUNNING]:
            timeout += 1
            if timeout > self.WAIT_APP_END_TIMEOUT:
                if status == self.TST_DBG_STS_APP_WFA_SET:
                    logger.error('ROM_BOOT pass control to application timeout '
                                 '(status: 0x%x)', status)
                elif status == self.TST_DBG_STS_APP_RUNNING:
                    logger.error('Application return status timeout '
                                 '(status: 0x%x)', status)
                else:
                    logger.error('Unexpected error - status 0x%x', status)
                raise TimeoutError('Application did not return status')
            time.sleep(0.1)
            status = self.tool.read32(self.target.register_map.TST_DEBUG_STATUS)

        return self.process_app_status(status)

    def process_app_status(self, status):
        """ Handles app execution status """
        result = ProvisioningStatus.OK
        if status == self.TST_DBG_STS_APP_NOT_LAUNCHED:
            logger.error('ROM_BOOT did not launch application due to '
                         'verification failure (status: 0x%x)', status)
            result = ProvisioningStatus.FAIL
        else:
            if status == self.app_status_codes.code_by_name('CYAPP_SUCCESS'):
                logger.info('Application execution successfully completed')
            else:
                self.print_ram_app_status(status)
                result = ProvisioningStatus.FAIL
        return result

    def read_app_output(self):
        """Reads application output and saves to a file"""
        logger.info('Read application output')
        addr = self.app.image_address + self.app.out_results_offset
        self.tool.dump_image(self.app.out_results_path, addr,
                             self.app.out_results_size)
        logger.info("Application output saved to '%s'",
                    os.path.abspath(self.app.out_results_path))

    def reset(self):
        """ Reset device using RES_SOFT_CTL register """
        logger.debug('Reset device')
        try:
            self.tool.write32(self.target.register_map.RES_SOFT_CTL,
                              self.RES_SOFT_CTL_RESET_RQST)
        except RuntimeError:
            pass  # the mww command fails so catch this fail and continue
        time.sleep(0.1)

    def print_ram_app_status(self, code, severity='error'):
        """
        Outputs RAM app status description
        :param code: RAM app status code
        :param severity: The severity of the status message
        """
        try:
            status, desc = self.app_status_codes.status_by_code(code)
            msg = f'Application execution completed with status code: ' \
                  f'({hex(code)}) - {status}: {desc}'
            if severity == 'error':
                logger.error(msg)
            elif severity == 'warning':
                logger.warning(msg)
            elif severity == 'info':
                logger.info(msg)
            elif severity == 'debug':
                logger.debug(msg)
            else:
                raise ValueError('Invalid severity argument')
        except KeyError:
            logger.error('Unexpected RAM app completion status 0x%x', code)

    def _load(self):
        for func in [self.check_romboot_readiness,
                     self.load_application,
                     self.load_input_parameters]:
            status = func()
            if status != ProvisioningStatus.OK:
                return status
        return ProvisioningStatus.OK
