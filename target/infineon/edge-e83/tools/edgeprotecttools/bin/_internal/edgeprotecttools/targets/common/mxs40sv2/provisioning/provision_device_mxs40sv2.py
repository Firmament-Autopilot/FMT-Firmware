"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import logging
from shutil import copyfile

from ..enums import LifecycleStage
from ...flow_parser import FlowParser
from .....core.provisioning_flows.application import Application
from .....core.provisioning_flows.app_loading_flow import AppLoadingFlow
from .....core.target_director import Target
from .....core.enums import ProvisioningStatus
from .....core.strategy_context import ProvisioningStrategy


logger = logging.getLogger(__name__)


class ProvisioningMXS40Sv2(ProvisioningStrategy):
    """
    A high-level class for provisioning targets on MXS40Sv2 platform
    """
    def provision(self, tool, target: Target, bootloader=None,
                  **kwargs) -> ProvisioningStatus:
        """
        Starts provisioning process using the specified flow
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        :param bootloader: N/A for MXS40Sv2 platform
        :raises:
            ValueError - when invalid policy type is used
        :return:
            The provisioning status
        """
        mode = None
        config = kwargs.get('config')

        if config is None:
            mode = target.policy_parser.policy_type()

        if mode is not None and 'reprovisioning' in mode:
            raise ValueError('Reprovisioning policy type specified for the '
                             'provisioning operation')

        status = self._provision(
            tool, target, mode, config, kwargs.get('testapps'))

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       PROVISIONING PASSED               ')
            logger.info('*****************************************\n')
        elif status == ProvisioningStatus.SKIPPED:
            logger.error('The device cannot be provisioned due to invalid '
                         'lifecycle stage')

        return status

    def re_provision(self, tool, target: Target, bootloader=None,
                     **kwargs) -> ProvisioningStatus:
        """
        Starts reprovisioning process
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        :param bootloader: N/A for MXS40Sv2 platform
        :raises:
            ValueError - when invalid policy type is used
        :return:
            The reprovisioning status
        """
        mode = target.policy_parser.policy_type()
        if 'reprovisioning' not in mode:
            raise ValueError('Provisioning policy type specified for the '
                             'reprovisioning operation')

        status = self._provision(
            tool, target, mode, None, kwargs.get('testapps'))

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       REPROVISIONING PASSED               ')
            logger.info('*****************************************\n')
        elif status == ProvisioningStatus.SKIPPED:
            logger.error('The device cannot be reprovisioned due to invalid '
                         'lifecycle stage')

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
        if lcs_value == LifecycleStage.SECURE:
            if cert is None:
                logger.error('Certificate must be specified for transition '
                             'from SECURE to RMA LCS')
                return ProvisioningStatus.FAIL
            if not self._copy_rma_cert(cert, apps, flow_parser.apps_dir):
                return ProvisioningStatus.FAIL
        else:
            if cert is not None:
                logger.warning(
                    'The certificate will be ignored. Transition from the '
                    'current LCS to RMA LCS does not require a certificate')

        status = self._provision(
            tool, target, 'rma', apps_dir=flow_parser.apps_dir,
            test_pkg_type=test_pkg_type)

        self._remove_rma_inparams(apps, flow_parser.apps_dir)

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       TRANSITION TO RMA PASSED          ')
            logger.info('*****************************************\n')
        elif status == ProvisioningStatus.SKIPPED:
            logger.error('The device cannot be converted to RMA due to '
                         'invalid lifecycle stage')
        return status

    def open_rma(self, tool, target, cert):
        """Not implemented for MXS40Sv2 platform"""
        raise NotImplementedError

    @staticmethod
    def _copy_rma_cert(cert, apps, apps_dir):
        for app_name in apps:
            app = Application(app_name, app_dir=apps_dir)
            cert = os.path.abspath(cert)
            if os.path.isfile(cert):
                logger.debug("Copy '%s' into '%s'", cert, app.in_params_path)
                copyfile(cert, app.in_params_path)
            else:
                logger.error("File '%s' not found", cert)
                return False
        return True

    @staticmethod
    def _remove_rma_inparams(apps, apps_dir):
        for app_name in apps:
            app = Application(app_name, app_dir=apps_dir)
            if os.path.isfile(app.in_params_path):
                logger.debug("Remove file '%s'", app.in_params_path)
                os.remove(app.in_params_path)

    def _provision(self, tool, target, mode, config=None, test_pkg_type=None,
                   apps_dir=None):
        app_dir = apps_dir if apps_dir else target.project_initializer.apps_dir
        flow = AppLoadingFlow(
            target, mode, app_dir, config=config, test_pkg_type=test_pkg_type)
        return flow.run(tool)
