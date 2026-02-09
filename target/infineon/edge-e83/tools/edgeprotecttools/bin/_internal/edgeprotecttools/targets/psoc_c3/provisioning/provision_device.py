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

from ...common.flow_parser import FlowParser
from ...common.mxs40sv2 import ProvisioningMXS40Sv2
from ....core.enums import ProvisioningStatus
from ....core.target_director import Target
from ....execute.programmer.dfuht_wrapper import Dfuht

logger = logging.getLogger(__name__)


class ProvisioningPsoc3(ProvisioningMXS40Sv2):
    """A high-level class for provisioning PSoC C3 targets"""

    def provision(self, tool, target: Target, bootloader=None,
                  **kwargs) -> ProvisioningStatus:
        """Starts provisioning process using the specified flow"""
        if not kwargs.get('config'):
            if 'prot_fw_dfu' in target.policy_parser.policy_type():
                prot_fw_image = kwargs.get('image')
                if prot_fw_image:
                    target.context['image'] = prot_fw_image
                else:
                    raise ValueError('Protected FW "image" must be specified')

                if not isinstance(tool, Dfuht):
                    raise ValueError('This flow can be executed '
                                     'only with "serial" tool')

        mode = None
        config = kwargs.get('config')

        if config is None:
            mode = target.policy_parser.policy_type()

        if mode is not None and 'reprovisioning' in mode:
            raise ValueError('Reprovisioning policy type specified for the '
                             'provisioning operation')

        status = self._provision(
            tool, target, mode, config, kwargs.get('testapps'))

        if status in (ProvisioningStatus.OK, ProvisioningStatus.STOP):
            logger.info('*****************************************')
            logger.info('       PROVISIONING PASSED               ')
            logger.info('*****************************************\n')
            status = ProvisioningStatus.OK
        elif status == ProvisioningStatus.SKIPPED:
            logger.error('The device cannot be provisioned due to invalid '
                         'lifecycle stage')

        return status

    def transit_to_rma(self, tool, target, cert=None, **kwargs):
        """Transits a part to the RMA LCS"""
        test_pkg_type = kwargs.get('testapps')

        flow_parser = FlowParser(target, test_pkg_type=test_pkg_type)
        apps = flow_parser.apps_by_flow('rma')

        if not apps:
            raise ValueError('RAM applications list is empty')

        status = self._provision(tool, target, 'rma',
                                 apps_dir=flow_parser.apps_dir,
                                 test_pkg_type=test_pkg_type)

        if status == ProvisioningStatus.OK:
            logger.info('******************************************')
            logger.info('       TRANSITION TO RMA LCS PASSED       ')
            logger.info('******************************************\n')
        elif status == ProvisioningStatus.SKIPPED:
            logger.error('The device cannot be converted into RMA LCS due to '
                         'an invalid current lifecycle stage')

        return status
