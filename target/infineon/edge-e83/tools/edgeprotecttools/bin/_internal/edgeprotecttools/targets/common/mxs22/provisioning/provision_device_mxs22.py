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

from ..enums import LifecycleStage
from ...flow_parser import FlowParser
from .....core.provisioning_flows.app_loading_flow import AppLoadingFlow
from .....core.target_director import Target
from .....core.enums import ProvisioningStatus
from .....core.strategy_context import (
    ProvisioningStrategy, ProvisioningPacketCtx)

logger = logging.getLogger(__name__)


class ProvisioningMXS22(ProvisioningStrategy):
    """
    A high-level class for provisioning targets on MXS22 platform
    """

    def provision(self, tool, target: Target, bootloader=None,
                  **kwargs) -> ProvisioningStatus:
        """
        Starts provisioning process using the specified flow
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        :param bootloader: N/A for MXS22 platform
        :raises:
            ValueError - when invalid policy type is used
        :return:
            The provisioning status
        """
        flow_name = kwargs.get('flow_name')
        config = kwargs.get('config')

        if not config and not flow_name:
            flow_name = target.policy_parser.policy_type()

        status = self._provision(tool, target, flow_name, config=config,
                                 test_pkg_type=kwargs.get('testapps'))

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('           PROVISIONING PASSED           ')
            logger.info('*****************************************\n')
        if status == ProvisioningStatus.SKIPPED:
            logger.info('RAM application execution completed')
            status = ProvisioningStatus.OK
        return status

    def re_provision(self, tool, target: Target, bootloader=None,
                     **kwargs) -> ProvisioningStatus:
        """Starts reprovisioning process
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        :param bootloader: N/A for MXS22 platform
        :return: The reprovisioning status
        """
        lcs = target.version_provider.get_lifecycle_stage(tool)
        if lcs != LifecycleStage.SECURE.name:
            logger.error('Reprovisioning is only available in the '
                         'PRODUCTION LCS')
            return ProvisioningStatus.FAIL

        flow_name = kwargs.get('flow_name')
        config = kwargs.get('config')

        if not config and not flow_name:
            flow_name = target.policy_parser.policy_type()

        status = self._provision(tool, target, flow_name, config=config,
                                 test_pkg_type=kwargs.get('testapps'))

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('           REPROVISIONING PASSED         ')
            logger.info('*****************************************\n')
        if status == ProvisioningStatus.SKIPPED:
            logger.info('RAM application execution completed')
            status = ProvisioningStatus.OK
        return status

    def erase_flash(self, tool, target):
        """ N/A. The target does not have flash """

    def transit_to_rma(self, tool, target, cert, **kwargs):
        """ Transits a part to the RMA LCS """
        test_pkg_type = kwargs.get('testapps')

        flow_parser = FlowParser(target, test_pkg_type=test_pkg_type)
        apps = flow_parser.apps_by_flow('rma')
        if not apps:
            raise ValueError('RAM applications list is empty')

        lcs_value = target.silicon_data_reader.read_lifecycle_stage(tool)
        if lcs_value not in (LifecycleStage.NORMAL_PROVISIONED,
                             LifecycleStage.SECURE):
            logger.error('Only devices in NORMAL_PROVISIONED or SECURE LCS '
                         'are eligible for transitioning to RMA LCS')
            return ProvisioningStatus.FAIL

        if not kwargs.get('existing-packet'):
            ctx = ProvisioningPacketCtx(target.provisioning_packet_strategy)
            ctx.create_package(
                target, flow_name='rma', input_params=cert, **kwargs)
        status = self._provision(
            tool, target, 'rma', apps_dir=flow_parser.apps_dir,
            test_pkg_type=test_pkg_type)

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       TRANSITION TO RMA PASSED          ')
            logger.info('*****************************************\n')

        return status

    def open_rma(self, tool, target, cert):
        """Enables full access to device in RMA lifecycle stage"""
        raise NotImplementedError

    @staticmethod
    def _provision(tool, target, flow_name, config=None, test_pkg_type=None,
                   apps_dir=None):
        app_dir = apps_dir if apps_dir else target.project_initializer.apps_dir
        flow = AppLoadingFlow(target, flow_name, app_dir, config=config,
                              test_pkg_type=test_pkg_type)
        return flow.run(tool)
