"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .app_loading_flow_cyw559xx import AppLoadingFlowCYW559xx
from .chip_loader import ChipLoad
from ....core.target_director import Target
from ....core.enums import ProvisioningStatus
from ....core.strategy_context import ProvisioningStrategy

logger = logging.getLogger(__name__)


class ProvisioningCYW559xx(ProvisioningStrategy):
    """
    A high-level class for provisioning targets on CYW559xx platform
    """

    def provision(self, tool, target: Target, bootloader=None,
                  **kwargs) -> ProvisioningStatus:
        """
        Starts provisioning process using the specified flow
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        :param bootloader: N/A for cyw559xx platform
        :raises:
            ValueError - when invalid policy type is used
        :return:
            The provisioning status
        """
        flow_name = kwargs.get('flow_name')
        config = kwargs.get('config')

        if not config and not flow_name:
            flow_name = target.policy_parser.policy_type()

        if tool.is_dm_mode():
            status = self._provision(tool, target, flow_name, config=config)
        else:
            logger.error('Failed to check device state')
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.OK:
            ProvisioningCYW559xx.framed_text('PROVISIONING PASSED')
        if status == ProvisioningStatus.SKIPPED:
            logger.info('RAM application execution completed')
            status = ProvisioningStatus.OK
        if status == ProvisioningStatus.FAIL:
            ProvisioningCYW559xx.framed_text('PROVISIONING FAILED')
        return status

    def re_provision(self, tool, target: Target, bootloader=None,
                     **kwargs) -> ProvisioningStatus:
        """ N/A for cyw559xx """

    def erase_flash(self, tool, target) -> bool:
        """Chip erase
        :param tool: Programming tool used for communication
        :param target: The target object
        :return: The status of the operation
        """
        loader = ChipLoad(tool, target, None)
        return loader.erase()

    def transit_to_rma(self, tool, target, cert, **kwargs):
        """ N/A for cyw559xx """

    def open_rma(self, tool, target, cert):
        """ N/A for cyw559xx """

    @staticmethod
    def _provision(tool, target, flow_name, config=None, apps_dir=None):
        app_dir = apps_dir if apps_dir else target.project_initializer.apps_dir
        flow = AppLoadingFlowCYW559xx(target, flow_name, app_dir, config=config)
        return flow.run(tool)

    @staticmethod
    def framed_text(message, line_len=41):
        """Display info with separation"""
        logger.info('*' * line_len)
        logger.info(' ' * ((line_len - len(message)) // 2) + message)
        logger.info('*' * line_len)
