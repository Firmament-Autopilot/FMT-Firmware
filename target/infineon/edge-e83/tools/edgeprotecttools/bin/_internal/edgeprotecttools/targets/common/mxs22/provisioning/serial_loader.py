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

from .app_result_validator import AppResultsValidator
from .....core.enums import ProvisioningStatus
from .....core.logging_configurator import LoggingConfigurator
from .....execute.dfuht_commands import DfuhtCommandsCreator

logger = logging.getLogger(__name__)


class SerialLoader:
    """Loads applications through the serial port"""
    PACKET_SIZE = 0x4
    OUT_FILE_SIZE_MAX = 16384
    CYAPP_SUCCESS = 0xf2a00001

    def __init__(self, tool, target, app, app_status_codes):
        self.tool = tool
        self.target = target
        self.app = app
        self.app_status_codes = app_status_codes

    def load(self):
        """Loads applications"""
        with tempfile.TemporaryDirectory() as dfu_command_dir:
            cmd_name = os.path.join(dfu_command_dir, 'cmd.mtbdfu')
            commands_cfg = DfuhtCommandsCreator(self.target, self.app, cmd_name)
            app_cmds = commands_cfg.create_packets()
            for app_pack in app_cmds:
                packet = app_pack[0]
                logger.info("DFU image programming '%s'", packet.image)
                status = ProvisioningStatus.FAIL
                if self.tool.program(packet.image, file_format='hex'):
                    logger.info("DFU image verification '%s'", packet.image)
                    if self.tool.verify(packet.image):
                        for cmd_packet in app_pack:
                            logging.debug("DFU loading command '%s'",
                                          cmd_packet.filename)
                            if self.tool.program(
                                    cmd_packet.filename, file_format='mtbdfu'):
                                status = ProvisioningStatus.OK
                            else:
                                status = ProvisioningStatus.FAIL
                                logging.error(
                                    'Unexpected DFU command execution result')
                                break
                    else:
                        logging.error('Unexpected verification result')
                else:
                    logging.error('Unexpected programming result')
                if status == ProvisioningStatus.OK:
                    status = self._read_out_data(packet.min_addr)
        return status

    def reset(self):
        """ Not implemented for DFU """

    def _read_out_data(self, start_addr):
        n_attempts = 8
        if self.app.out_results_path:
            address = start_addr + self.app.out_results_offset
            for i in range(1, n_attempts + 1):
                time.sleep(1)
                logger.debug(
                    'Reading out results of the application: attempt %s / %s ',
                    i,
                    n_attempts
                )

                LoggingConfigurator.disable_logging()
                try:
                    num_bytes = self.tool.read32(address)
                except RuntimeError as e:
                    if i == n_attempts:
                        raise e
                    continue
                except Exception as e:
                    raise e
                finally:
                    LoggingConfigurator.enable_logging()

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
            status = self.tool.read32(self.target.register_map.boot_dlm_status)
            AppResultsValidator.print_ram_app_status(
                status, self.app_status_codes)
        return ProvisioningStatus.OK
