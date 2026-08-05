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
import tempfile
import time

from ....core.enums import ProvisioningStatus
from ....core.logging_configurator import LoggingConfigurator
from ....execute.dfuht_commands import DfuhtCommandsCreator

logger = logging.getLogger(__name__)


class SerialLoaderPsocC3:
    """Loads applications through the serial port"""
    WAIT_FOR_APP_TIMEOUT = 200
    WAIT_APP_END_TIMEOUT = 8
    INPUT_PARAM_MIN_SIZE = 8

    RES_SOFT_CTL_RESET_RQST = 0x00000001
    TST_DBG_CTL_WAIT_APP_RQST = 0x00000001
    TST_DBG_CTL_WFA_Msk = 0x80000000

    TST_DBG_STS_APP_WFA_SET = 0x0D500080
    TST_DBG_STS_APP_LAUNCHED = 0x0D500081
    TST_DBG_STS_APP_NOT_LAUNCHED = 0x0D500082
    TST_DBG_STS_APP_RUNNING = 0xF2A00010

    PACKET_SIZE = 0x4
    OUT_FILE_SIZE_MAX = 4096

    def __init__(self, tool, target, app, app_status_codes):
        self.tool = tool
        self.target = target
        self.app = app
        self.app_status_codes = app_status_codes

    def load(self):
        """ Loads application and its input parameters into RAM """

        if not self._is_lcs_allowed(self.app):
            return ProvisioningStatus.SKIPPED

        if not self.app.dlm_path:
            raise ValueError('DLM path not specified')

        with tempfile.TemporaryDirectory() as dfu_command_dir:
            cmd_name = os.path.join(dfu_command_dir, 'cmd.mtbdfu')
            commands_cfg = DfuhtCommandsCreator(self.target, self.app,
                                                cmd_name)
            app_cmds = commands_cfg.create_packets()
            for app_pack in app_cmds:
                packet = app_pack[0]
                logger.info("DFU image programming '%s'", packet.image)
                status = ProvisioningStatus.FAIL
                if self.tool.program(packet.image, file_format='hex'):
                    status = ProvisioningStatus.OK
                else:
                    logging.error('Unexpected programming result')

                if self.app.name.startswith('to_rma'):
                    return status
                if self.app.name.startswith('prot_fw_dfu') \
                        and status == ProvisioningStatus.OK:
                    pth = self.target.context.get('image')
                    if not pth:
                        logger.error('Protected FW image not specified')
                        return ProvisioningStatus.FAIL
                    logger.info("Protected FW programming '%s'", pth)
                    status = ProvisioningStatus.OK \
                        if self.tool.program(pth, file_format='hex') \
                        else ProvisioningStatus.FAIL
                if status == ProvisioningStatus.OK:
                    status = self.post_processing(packet.min_addr)
        return status

    def post_processing(self, start_addr):
        """Handles reading app completion status and out results"""
        result = ProvisioningStatus.OK
        success_code = self.app_status_codes.code_by_name('CYAPP_SUCCESS')
        n_attempts = 4
        tmp_name = 'post_processing_data.bin'

        address = []
        size = []

        app_completion_status_addr = self.target.register_map.TST_DEBUG_STATUS
        app_completion_status_size = self.PACKET_SIZE
        address.append(app_completion_status_addr)
        size.append(app_completion_status_size)

        if self.app.out_results_path:
            out_results_addr = start_addr + self.app.out_results_offset
            out_results_size = self.OUT_FILE_SIZE_MAX
            address.append(out_results_addr)
            size.append(out_results_size)

        with tempfile.TemporaryDirectory() as tmp_dir:
            tmp_path = os.path.join(tmp_dir, tmp_name)

            for i in range(1, n_attempts + 1):
                logger.info(
                    'Reading results of the application: attempt %s / %s ',
                    i, n_attempts
                )

                LoggingConfigurator.disable_logging()
                try:
                    self.tool.dump_image(
                        tmp_path, address, size, chunk_size=128
                    )
                except RuntimeError as e:
                    if i == n_attempts:
                        raise e
                    continue
                except Exception as e:
                    raise e
                finally:
                    LoggingConfigurator.enable_logging()

                with open(tmp_path, 'rb') as f:
                    data = f.read()

                status = int.from_bytes(data[:4], byteorder="little")
                data = data[4:]
                if status == success_code:
                    logger.info('Application execution successfully completed')
                else:
                    self.print_ram_app_status(status)
                    result = ProvisioningStatus.FAIL
                break

        if self.app.out_results_path:
            sz = int.from_bytes(data[:4], byteorder="little")
            with open(self.app.out_results_path, 'wb') as f:
                f.write(data[:sz + self.PACKET_SIZE])
            logger.info("Saved application output to '%s'",
                        os.path.abspath(self.app.out_results_path))

        return result

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

    def _is_lcs_allowed(self, app):
        lcs = self.target.version_provider.get_lifecycle_stage(self.tool)
        if lcs in app.allowed_lcs:
            return True
        logger.warning("Skip programming '%s' application. The device "
                       "lifecycle stage is %s", self.app.name, lcs)
        return False
