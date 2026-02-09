"""
Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import json
import logging
from time import sleep

from . import sys_call
from ..enums import ProtectionState, KeyId
from ..encrypted_programming import AesHeaderStrategy
from ..provisioning_packet import provisioning_packet_mxs40v1 as prov_packet
from .....execute import jwt
from .....core.key_handlers.pem_key import PemKey
from .....core.connect_helper import ConnectHelper
from .....core.target_director import Target
from .....core.enums import EntranceExamStatus, ProvisioningStatus
from .....core.strategy_context import ProvisioningStrategy
from .....core.strategy_context import EncryptedProgrammingContext
from .....execute.programmer.base import AP, ResetType
from ..data import SfbStatusMXS40v1


logger = logging.getLogger(__name__)


class ProvisioningMXS40v1(ProvisioningStrategy):

    def provision(self, tool, target: Target, bootloader,
                  **kwargs) -> ProvisioningStatus:
        """
        Programs Cypress Bootloader and calls system calls for device
        provisioning.
        :param tool: Programming/debugging tool used for communication
        :param target: The target object.
        :param bootloader: Path to Cypress Bootloader program file.
        :param kwargs: Dictionary with the following fields:
               - probe_id: Probe ID to use
        :return: Provisioning status.
        """
        skip_prompts = kwargs.get('skip_prompts')
        probe_id = kwargs.get('probe_id')

        prov_packets = self._get_provisioning_packet(target)
        status = _provision_identity(
            tool, target, prov_packets['prov_identity'], skip_prompts)

        if status == ProvisioningStatus.OK:
            status = _provision_complete(tool, target,
                                         prov_packets['prov_cmd'], bootloader,
                                         False, ap='cm4', probe_id=probe_id)

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       PROVISIONING PASSED               ')
            logger.info('*****************************************\n')

        return status

    def re_provision(self, tool, target: Target, bootloader,
                     **kwargs) -> ProvisioningStatus:
        """
        Programs Cypress Bootloader and calls system calls for device
        provisioning.
        :param tool: Programming/debugging tool used for communication
        :param target: The target object.
        :param bootloader: Path to Cypress Bootloader program file.
        :param kwargs: Dictionary with the following fields:
               - erase_boot: Indicates whether to erase BOOT slot
               - control_dap_cert: Certificate for AP control
        :return: Provisioning status.
        """
        erase_boot = kwargs.get('erase_boot', False)
        control_dap_cert = kwargs.get('control_dap_cert')
        probe_id = kwargs.get('probe_id')

        prov_packets = self._get_re_provisioning_packet(target)
        status = _provision_complete(
            tool, target, prov_packets['prov_cmd'], bootloader, True,
            erase_boot=erase_boot, control_dap_cert=control_dap_cert,
            probe_id=probe_id)

        if status == ProvisioningStatus.OK:
            logger.info('*****************************************')
            logger.info('       RE-PROVISIONING PASSED            ')
            logger.info('*****************************************\n')

        return status

    def erase_flash(self, tool, target):
        """
        Erases allowed (w/o bootloader, data only) flash area
        :param tool: Programming/debugging tool used for communication
        :param target: The target object
        """
        erase_flash(tool, target)

    def transit_to_rma(self, tool, target, cert, **_):
        """Transits a part to the RMA LCS
        @param tool: Programming/debugging tool used for communication
        @param target: The target object
        @param cert: JWT packet signed by the key mentioned in the debug/RMA
                     section of the policy, with authentication object
                     including valid DIE_ID range
        """
        if cert is None:
            raise ValueError('Certificate not specified')
        logger.info("Apply certificate '%s'", cert)
        with open(cert, encoding='utf-8') as f:
            cert_data = f.read()
        if sys_call.transition_to_rma(
                tool, target.memory_map, target.register_map, cert_data):
            tool.reset()
            logger.info('*****************************************')
            logger.info('      TRANSITION TO RMA LCS PASSED       ')
            logger.info('*****************************************\n')
            return ProvisioningStatus.OK
        return ProvisioningStatus.FAIL

    def open_rma(self, tool, target, cert):
        """Enables full access to device in RMA lifecycle stage
        @param tool: Programming/debugging tool used for communication
        @param target: The target object
        @param cert: JWT packet signed by the key mentioned in the debug/RMA
                     section of the policy, with authentication object
                     including valid DIE_ID range
        """
        logger.info("Apply certificate '%s'", cert)
        with open(cert, encoding='utf-8') as f:
            cert_data = f.read()
        if sys_call.open_rma(tool, target.memory_map, target.register_map,
                             cert_data):
            logger.info('*****************************************')
            logger.info('          FULL ACCESS ENABLED            ')
            logger.info('        DO NOT RESET THE DEVICE          ')
            logger.info('*****************************************\n')
            return ProvisioningStatus.OK
        return ProvisioningStatus.FAIL

    @staticmethod
    def _get_provisioning_packet(target):
        packet_dir = target.policy_parser.get_provisioning_packet_dir()
        prov_identity = os.path.join(packet_dir, prov_packet.PROV_IDENTITY_JWT)
        prov_cmd = os.path.join(packet_dir, prov_packet.PROV_CMD_JWT)

        if not os.path.isfile(prov_identity):
            logger.error('Cannot find provisioning packet %s', prov_identity)
            return False
        if not os.path.isfile(prov_cmd):
            logger.error('Cannot find provisioning packet %s', prov_cmd)
            return False

        return {'prov_identity': prov_identity, 'prov_cmd': prov_cmd}

    @staticmethod
    def _get_re_provisioning_packet(target):
        packet_dir = target.policy_parser.get_provisioning_packet_dir()
        prov_cmd = os.path.join(packet_dir, prov_packet.PROV_CMD_JWT)

        if not os.path.isfile(prov_cmd):
            logger.error('Cannot find provisioning packet %s', prov_cmd)
            return False

        return {'prov_cmd': prov_cmd}


def read_silicon_data(tool, target: Target):
    """
    Reads silicon data from device
    :param tool: Programming/debugging tool used for communication
    :param target: The target object.
    :return: Device response
    """
    logger.debug('Read silicon data')
    tool.reset(ResetType.SW)
    _, response = sys_call.provision_keys_and_policies(tool, None,
                                                       target.register_map)
    return response


def erase_flash(tool, target):
    logger.info('Erase main flash:')
    addr = target.memory_map.FLASH_ADDRESS
    size = target.memory_map.FLASH_SIZE
    logger.info('erasing address 0x%x, size 0x%x ...', addr, size)
    ap = tool.get_ap()
    if ap == AP.SYS:
        tool.set_ap(AP.CMx)
    tool.halt()
    tool.erase(addr, size)
    logger.info('Erasing complete')
    tool.set_ap(ap)
    erase_smif(tool, target)


def erase_smif(tool, target):
    smif_resources = target.policy_parser.get_smif_resources()
    if len(smif_resources) > 0:
        logger.info('Erase main smif slots:')
        ap = tool.get_ap()
        if ap == AP.SYS:
            tool.set_ap(AP.CMx)
        for (addr, size) in smif_resources:
            # Aligning start address to erase to minimal erase size of smif
            actual_addr = addr - addr % target.memory_map.MIN_EXT_ERASE_SIZE
            # Aligning size to erase to minimal erase size of smif
            if size % target.memory_map.MIN_EXT_ERASE_SIZE == 0:
                actual_size = size
            else:
                actual_size = size + target.memory_map.MIN_EXT_ERASE_SIZE - \
                              size % target.memory_map.MIN_EXT_ERASE_SIZE
            logger.info('erasing address 0x%x, size 0x%x ...', actual_addr,
                        actual_size)
            tool.erase(actual_addr, actual_size)
            logger.info('Erasing complete')
        tool.set_ap(ap)


def erase_status_partition(tool, target):
    memory_area = target.policy_parser.status_partition()
    if memory_area is not None:
        logger.info('Erase SWAP status partition memory region:')
        ap = tool.get_ap()
        if ap == AP.SYS:
            tool.set_ap(AP.CMx)
        logger.info('erasing address 0x%x, size 0x%x ...',
                    memory_area.address, memory_area.size)
        tool.erase(memory_area.address, memory_area.size)
        logger.info('Erasing complete')
        tool.set_ap(ap)


def erase_scratch_area(tool, target):
    memory_area = target.policy_parser.scratch_area()
    if memory_area is not None:
        logger.info('Erase SCRATCH memory region:')
        ap = tool.get_ap()
        if ap == AP.SYS:
            tool.set_ap(AP.CMx)
        logger.info('erasing address 0x%x, size 0x%x ...',
                    memory_area.address, memory_area.size)
        tool.erase(memory_area.address, memory_area.size)
        logger.info('Erasing complete')
        tool.set_ap(ap)


def erase_slots(tool, target, slot_type, first_only=False):
    """
    Erases slot(s) of specific type.
    :param tool: Programming/debugging tool
    :param target: The target object
    :param slot_type: Slot type - BOOT, UPGRADE
    :param first_only: For performance, erase first image only, it is
                       enough to prevent application from starting
    """
    data = target.policy_parser.get_image_data(slot_type)
    logger.info('Erase %s slot:', slot_type)
    for addr, size in data:
        logger.info('erasing address 0x%x, size 0x%x ...', addr, size)
        ap = tool.get_ap()
        if ap == AP.SYS:
            tool.set_ap(AP.CMx)
        tool.halt()
        tool.erase(addr, size)
        logger.info('Erasing complete')
        tool.set_ap(ap)
        if first_only:
            break


def _provision_identity(tool, target: Target,
                        prov_identity_jwt, skip_prompts) -> ProvisioningStatus:
    lifecycle = sys_call.read_lifecycle(tool, target.register_map)
    tool.examine_ap()

    if lifecycle == ProtectionState.secure:
        status = target.entrance_exam.execute(tool)
        if status == EntranceExamStatus.FLASH_NOT_EMPTY:
            if skip_prompts:
                logger.error('Cannot start provisioning. '
                             'User firmware running on chip detected')
                return ProvisioningStatus.FAIL
            else:
                answer = input('Erase user firmware running on chip? (y/n): ')
                if answer.lower() == 'y':
                    erase_flash(tool, target)
                else:
                    return ProvisioningStatus.TERMINATED
        elif status != EntranceExamStatus.OK:
            return ProvisioningStatus.FAIL
    else:
        erase_flash(tool, target)

    tool.reset_and_halt()
    sleep(0.2)

    is_exam_pass, response = sys_call.provision_keys_and_policies(
        tool, prov_identity_jwt, target.register_map)
    _save_device_response(target, response)

    if not is_exam_pass:
        logger.error('Unexpected ProvisionKeysAndPolicies syscall response')
        return ProvisioningStatus.FAIL
    else:
        return ProvisioningStatus.OK


def _provision_complete(tool, target: Target, prov_cmd_jwt, bootloader,
                        re_provision, erase_boot=False, control_dap_cert=None,
                        probe_id=None, ap='cm0') -> ProvisioningStatus:
    reg_map = target.register_map
    flash_ops_allowed = True

    if re_provision:
        is_cm0_open = read_cm0_permissions(tool, target)
        if is_cm0_open:
            ConnectHelper.disconnect(tool)
            ConnectHelper.connect(tool, target, probe_id=probe_id, ap=ap)
            tool.examine_ap()
        flash_ops_allowed = is_cm0_open

    if flash_ops_allowed:
        erase_status_partition(tool, target)
        erase_scratch_area(tool, target)

    # Read firmware status
    logger.info('Read FlashBoot firmware status:')
    sfb_fw_status = tool.read32(reg_map.ENTRANCE_EXAM_FW_STATUS_REG)
    if re_provision:
        expected = reg_map.ENTRANCE_EXAM_FW_STATUS_RE_VAL
    else:
        expected = reg_map.ENTRANCE_EXAM_FW_STATUS_VAL
    received = sfb_fw_status & reg_map.ENTRANCE_EXAM_FW_STATUS_MASK
    logger.info('FlashBoot firmware status = 0x%x', sfb_fw_status)
    logger.info('Received FB_FW_STATUS = 0x%x', received)
    logger.info('Expected FB_FW_STATUS = 0x%x', expected)

    if expected != received:
        try:
            status = SfbStatusMXS40v1().status_codes()[received]
            logger.info('SFB status: %s: %s', status['status'], status['desc'])
        except KeyError:
            logger.debug('Unexpected SFB status 0x%x', received)

    # Open cm0 AP with a certificate
    if control_dap_cert:
        logger.info('Opening cm0 AP')
        is_cm0_open = sys_call.dap_control(
            tool, reg_map, 0, 1, False, control_dap_cert)
        logger.info('cm0 AP %s', 'open' if is_cm0_open else 'closed')
        if is_cm0_open:
            ConnectHelper.disconnect(tool)
            ConnectHelper.connect(tool, target, probe_id=probe_id, ap='cm0',
                                  acquire=False)
            tool.examine_ap()
        flash_ops_allowed = is_cm0_open

    if erase_boot:
        if flash_ops_allowed:
            erase_slots(tool, target, 'BOOT')
        else:
            logger.warning('Skip erasing BOOT slot, AP cm0 is closed')
    else:
        logger.info('BOOT slot will remain the same and can affect '
                    'rollback counter')

    smif_enabled = len(target.policy_parser.get_smif_resources()) > 0
    if smif_enabled:
        if flash_ops_allowed:
            erase_smif(tool, target)
        else:
            logger.warning('Skip erasing external memory, AP cm0 is closed')

    context = EncryptedProgrammingContext(AesHeaderStrategy)

    # Program user application
    user_apps = target.policy_parser.get_user_apps()
    if user_apps:
        tool.reset()
    for encrypted, app in user_apps:
        if not os.path.isabs(app):
            app = os.path.join(target.policy_parser.policy_dir, app)
        if encrypted:
            logger.info("Programming encrypted user application '%s':", app)
            result = context.program(tool, target, app)
            if not result:
                logger.error('User application encrypted programming failed')
                return ProvisioningStatus.FAIL
        else:
            if flash_ops_allowed:
                current_ap = tool.get_ap()
                if current_ap == AP.SYS:
                    tool.set_ap(AP.CMx)
                logger.info("Programming user application '%s':", app)
                tool.halt()
                tool.program(app)
                logger.info('Programming user application complete')
                tool.resume()
                tool.set_ap(current_ap)
            else:
                logger.warning('Skip programming user application, '
                               'AP cm0 is closed')

    # Program bootloader
    is_custom_bootloader = target.policy_parser.is_custom_bootloader()
    is_encrypted_bootloader = target.policy_parser.is_encrypted_bootloader()
    if is_custom_bootloader and is_encrypted_bootloader:
        cy_bootloader_hex = target.policy_parser.get_cybootloader_hex()
        logger.info(
            "Programming encrypted bootloader '%s':", cy_bootloader_hex)
        result = context.program(tool, target, cy_bootloader_hex)
        if not result:
            logger.error('Bootloader encrypted programming failed')
            return ProvisioningStatus.FAIL
    else:
        if not flash_ops_allowed:
            logger.warning('Skip programming bootloader, AP cm0 is closed')
        elif bootloader is None:
            logger.warning('Skip programming bootloader')
        else:
            current_ap = tool.get_ap()
            if current_ap == AP.SYS:
                tool.set_ap(AP.CMx)
            logger.info("Programming bootloader '%s':", bootloader)
            tool.halt()
            tool.program(bootloader)
            logger.info('Programming bootloader complete')
            tool.resume()
            tool.set_ap(current_ap)

    tool.reset(ResetType.SW)
    sleep(3)

    _save_device_public_key(tool, target)

    # Run provisioning syscall
    logger.info('Run provisioning syscall:')
    is_exam_pass, response = sys_call.provision_keys_and_policies(
        tool, prov_cmd_jwt, target.register_map)
    tool.reset()

    if not is_exam_pass:
        return ProvisioningStatus.FAIL

    _save_device_response(target, response)

    if not target.policy_parser.is_sys_ap_enabled():
        logger.warning('System AP closed by policy. Final verification is '
                       'not available')
        return ProvisioningStatus.OK

    sfb_fw_status = tool.read32(reg_map.ENTRANCE_EXAM_FW_STATUS_REG)
    logger.info('FlashBoot firmware status = 0x%x', sfb_fw_status)
    is_exam_pass = sfb_fw_status == reg_map.FB_FW_STATUS_FIRMWARE_RUNNING_CM0

    if not is_exam_pass:
        logger.error('FlashBoot firmware status is not as expected')

    return ProvisioningStatus.OK if is_exam_pass else ProvisioningStatus.FAIL


def read_cm0_permissions(tool, target):
    logger.info('Checking cm0 AP permissions')
    passed, data = sys_call.get_prov_details(tool, target.register_map,
                                             sys_call.FB_POLICY_JWT)
    if passed and len(data) > 0:
        policy = jwt.readable_jwt(data)
        silicon_policy_parser = target.policy_parser.__class__(policy['payload'])
        is_cm0_open = silicon_policy_parser.is_cmx_ap_enabled(True)
        logger.info('cm0 AP %s', 'open' if is_cm0_open else 'closed')
    else:
        logger.error('Failed to read policy from device while getting AP '
                     'permission')
        logger.warning('Flash operations will be skipped')
        is_cm0_open = False
    return is_cm0_open


def _save_device_public_key(tool, target):
    try:
        jwk_path, pem_path = target.policy_parser.device_public_key_path()
        key = target.key_reader.read_public_key(tool, KeyId.DEVICE, 'jwk')
        if key:
            with open(jwk_path, 'w', encoding='utf-8') as f:
                f.write(json.dumps(key, indent=4))
            pem = PemKey(jwk_path)
            pem.save(pem_path, private_key=False)
    except TimeoutError:
        raise
    except (KeyError, OSError, ValueError, TypeError) as e:
        logger.error('Failed to save device public key')
        logger.error(e)


def _save_device_response(target, response):
    try:
        packet_dir = target.policy_parser.get_provisioning_packet_dir()
        filename = os.path.join(packet_dir, prov_packet.DEVICE_RESPONSE_JWT)
        if response:
            with open(filename, 'w', encoding='utf-8') as f:
                f.write(response)
        logger.info("Saved device response to '%s'", filename)
    except (KeyError, OSError, TypeError) as e:
        logger.error('Failed to save device response')
        logger.error(e)
