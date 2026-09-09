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
import time

from intelhex import IntelHex

from .app_result_validator import AppResultsValidator
from ..dlm_package import DLMPackage
from ..asset_enums import ApPermission
from .....core.enums import ProvisioningStatus

logger = logging.getLogger(__name__)


class SwdLoaderMXS22:
    """Loads applications through the serial port"""
    CYBOOT_DLM_LOAD = 0x0d500070
    CYBOOT_DLM_VERIFY = 0x0d500071
    CYBOOT_DLM_RUN = 0x0d500072
    CYBOOT_DLM_PKG_INVALID = 0xbaf00073
    CYAPP_SUCCESS = 0xf2a00001
    CYAPP_APP_RUNNING = 0xf2a00010
    BOOT_STATUS_SUCCESS = 0x0d50b002
    BOOT_DLM_CTL = 0x52400404
    REQUEST_SOFT_RESET = 0x00000001
    REQUEST_PKG_LOAD = 0x00000001
    PACKET_SIZE = 0x4
    CMD_EXIT_APP = 0x05
    INPUT_AVAIL_MSK = 0x20000000
    INPUT_PARAMS_ADDR = 0x3400D000
    OUT_FILE_SIZE_MAX = 16384
    DLM_VALIDATE_SLEEP_MS = 3000
    DLM_VALIDATE_TIMEOUT_S = 10
    DLM_EXECUTE_SLEEP_MS = 200
    DLM_EXECUTE_TIMEOUT_S = 60
    BOOTROM_READY_SLEEP_MS = 100
    BOOTROM_READY_TIMEOUT_S = 100
    REQUEST_PKG_LOAD_TIMEOUT_S = 10

    def __init__(self, tool, target, app, app_status_codes,
                 lcs=None, flow_name=None):
        self.tool = tool
        self.target = target
        self.app = app
        self.app_status_codes = app_status_codes
        self.lcs = lcs
        self.flow_name = flow_name

    def load(self):
        """Loads applications"""
        status = ProvisioningStatus.FAIL
        try:
            status = self._load_application()
        except RuntimeError:
            logging.error('DAP connection lost while loading application')
        else:
            if status == ProvisioningStatus.OK:
                status = self._validation_app()
            if status == ProvisioningStatus.OK:
                if isinstance(self.app.in_params_path, list):
                    for in_params in self.app.in_params_path:
                        self._trims_processing(in_params)
                        status = self._app_execution()
                        if status != ProvisioningStatus.OK:
                            break
                else:
                    status = self._app_execution()
            if status == ProvisioningStatus.OK:
                status = self._read_out_data()
            self.tool.reset()
            if self.target.policy_parser.json:
                policy_t = self.target.policy_parser.policy_type()
                if status == ProvisioningStatus.OK and policy_t == 'prov_oem':
                    status = self.check_ap_config(self.app.dlm_path, self.lcs)
        return status

    @staticmethod
    def check_ap_config(dlm_path, lcs):
        """Deserialize RAM app input parameters and check AP configuration"""
        status = ProvisioningStatus.OK
        ihex = IntelHex(dlm_path)
        dlm = ihex.tobinarray().tobytes()
        dlm_data = DLMPackage(dlm)
        if dlm_data.prov_packet.oem_packet:
            oem_cert = dlm_data.prov_packet.oem_cert
            if oem_cert:
                lcs = oem_cert.cert_type
            if lcs in ('PRODUCTION', 'SECURE'):
                ap_enable = ApPermission.Enabled.value
                if dlm_data.prov_packet.debug_system_ap != ap_enable:
                    logger.info('System AP disabled')
                    status = ProvisioningStatus.SKIPPED
                if dlm_data.prov_packet.debug_cm33_ap != ap_enable:
                    logger.info('CM33 AP disabled')
        return status

    def reset(self):
        """ Soft reset device """
        logger.debug('Reset device')
        try:
            self.tool.write32(self.target.register_map.res_soft_ctl,
                              self.REQUEST_SOFT_RESET)
        except RuntimeError:
            logger.debug('Failed to write REQUEST_SOFT_RESET')

    def _trims_processing(self, in_params):
        logger.info('Trims processing started...')
        in_params_path = os.path.join(self.app.app_dir, in_params)
        self.tool.program_ram(in_params_path, None, self.INPUT_PARAMS_ADDR)
        self.tool.write32(self.BOOT_DLM_CTL, self.INPUT_AVAIL_MSK)

    def _error_report(self):
        error_info = {
            'BOOT_DLM_CTL': self.target.register_map.boot_dlm_ctl,
            'BOOT_DLM_CTL2': self.target.register_map.boot_dlm_ctl2,
            'BOOT_DLM_STATUS': self.target.register_map.boot_dlm_status,
            'BOOT_STATUS': self.target.register_map.boot_status
        }
        for status_itm in error_info:
            status_itm_val = self.tool.read32(error_info.get(status_itm))
            logger.error('%s: 0x%08x', status_itm, status_itm_val)

    def _load_application(self):
        timeout = time.time() + self.REQUEST_PKG_LOAD_TIMEOUT_S
        while time.time() < timeout:
            try:
                self.tool.write32(self.target.register_map.boot_dlm_ctl,
                                  self.REQUEST_PKG_LOAD)
                break
            except RuntimeError:
                logger.debug('Failed to write REQUEST_PKG_LOAD')
        else:
            raise TimeoutError('REQUEST_PKG_LOAD writing timeout')

        self.reset()
        timeout = time.time() + self.BOOTROM_READY_TIMEOUT_S
        while time.time() < timeout:
            status = self.tool.read32(self.target.register_map.boot_dlm_status)
            if status == self.CYBOOT_DLM_LOAD:
                logger.info('ROM Boot is ready for DLM package upload')
                break
            time.sleep(0.001 * self.BOOTROM_READY_SLEEP_MS)
        else:
            self._error_report()
            raise TimeoutError('BOOT_ROM readiness timeout')

        path = self.app.dlm_path if self.app.dlm_path else self.app.image_path

        logger.info("Load application '%s'", path)
        if self._dlm_format(path) == '.hex':
            self.tool.program_ram(path)
        else:
            hex_addr = self._dlm_addr(path, self.app.image_address)
            self.tool.program_ram(path, None, hex_addr)
        return ProvisioningStatus.OK

    def _validation_app(self):
        hex_addr = self._dlm_addr(
            self.app.dlm_path if self.app.dlm_path else self.app.image_path,
            self.app.image_address
        )
        self.tool.write32(self.target.register_map.boot_dlm_ctl2, hex_addr)
        try:
            self.tool.write32(self.target.register_map.boot_dlm_ctl, 0)
        except RuntimeError:
            time.sleep(0.001 * self.DLM_VALIDATE_SLEEP_MS)
        timeout = time.time() + self.DLM_VALIDATE_TIMEOUT_S
        while time.time() < timeout:
            status = self.tool.read32(self.target.register_map.boot_dlm_status)
            if status != self.CYBOOT_DLM_VERIFY:
                break
            time.sleep(0.001 * self.DLM_VALIDATE_SLEEP_MS)
        else:
            self._error_report()
            raise TimeoutError('DLM validation timeout')

        if status == self.CYBOOT_DLM_PKG_INVALID:
            logger.error('Invalid DLM package')
            self._error_report()
            return ProvisioningStatus.FAIL
        logger.info('Validation of the DLM package success')
        return ProvisioningStatus.OK

    def _app_execution(self):
        timeout = time.time() + self.DLM_EXECUTE_TIMEOUT_S
        logger.info('Start DLM package execution')
        while time.time() < timeout:
            status = self.tool.read32(self.target.register_map.boot_dlm_status)
            if status not in (self.CYBOOT_DLM_RUN, self.CYAPP_APP_RUNNING):
                break
            time.sleep(0.001 * self.DLM_EXECUTE_SLEEP_MS)
        else:
            self._error_report()
            raise TimeoutError('DLM execution timeout')
        AppResultsValidator.print_ram_app_status(status, self.app_status_codes)
        if status == self.CYAPP_SUCCESS:
            return ProvisioningStatus.OK
        return ProvisioningStatus.FAIL

    def _read_out_data(self):
        if self.app.out_results_path:
            hex_addr = self._dlm_addr(self.app.dlm_path, self.app.image_address)
            address = hex_addr + self.app.out_results_offset
            num_bytes = self.tool.read32(address)
            if 0 < num_bytes <= self.OUT_FILE_SIZE_MAX:
                logger.info('Read out results of the application')
                self.tool.dump_image(self.app.out_results_path,
                                     address + self.PACKET_SIZE,
                                     num_bytes)
                logger.info('Out results data: %s', os.path.abspath(
                    self.app.out_results_path))
                results = AppResultsValidator(self.app.out_results_path)
                status = results.validate()
                results.print_ram_app_status(status, self.app_status_codes)
                if status == self.CYAPP_SUCCESS:
                    return ProvisioningStatus.OK
                return ProvisioningStatus.FAIL
        return ProvisioningStatus.OK

    def _dlm_addr(self, app_path, addr=None):
        if self._dlm_format(app_path) == '.hex':
            hex_obj = IntelHex(app_path)
            load_addr = hex_obj.minaddr()
        elif self._dlm_format(app_path) == '.bin' and addr is not None:
            load_addr = addr
        else:
            raise ValueError('No image address or incompatible format')
        return load_addr

    @staticmethod
    def _dlm_format(app_path):
        dlm_fmt = os.path.splitext(app_path)[1]
        return dlm_fmt
