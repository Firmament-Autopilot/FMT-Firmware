"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from ..enums import ProtectionState
from ..provisioning.sys_call import region_hash, read_lifecycle
from .....core.enums import EntranceExamStatus, RegionHashStatus
from .....core.target_director import Target
from .....core.connect_helper import ConnectHelper
from .....core.entrance_exam_base import EntranceExam
from .....core.strategy_context import ProvisioningContext
from .....execute import jwt
from .....execute.programmer.base import AP
from .....pkg_globals import PkgData

logger = logging.getLogger(__name__)

ENTRANCE_EXAM_JWT = 'entrance_exam.jwt'
SFB_VER_ERROR = 'Engineering Sample version of PSoC64 detected, the ' \
                f'current version of {PkgData.pkg_name()} is incompatible. ' \
                'Please contact Cypress to receive production versions of ' \
                'PSoC64 Silicon\n'


class EntranceExamMXS40v1(EntranceExam):
    def __init__(self, target: Target, **kwargs):
        super().__init__(target, **kwargs)
        self.reg_map = target.register_map
        self.target = target

    @property
    def entrance_exam_jwt(self):
        packet_dir = self.target.policy_parser.get_provisioning_packet_dir()
        return os.path.abspath(os.path.join(packet_dir, ENTRANCE_EXAM_JWT))

    def execute(self, tool, **kwargs):
        """
        Checks device life-cycle, FlashBoot firmware, Flash state and
        a bunch of registers.
        """
        jwt_text = jwt.read_jwt(self.entrance_exam_jwt)

        logger.info('*****************************************')
        logger.info('             ENTRANCE EXAM               ')
        logger.info('*****************************************')

        complete = self.target.silicon_data_reader.read_complete_status(tool)
        exam_pass = not complete
        if not exam_pass:
            logger.error('Device has been previously provisioned')

        if exam_pass:
            ConnectHelper.disconnect(tool)
            ConnectHelper.connect(tool, self.target,
                                  probe_id=tool.probe_id, ap='cm4')
            tool.examine_ap()

            # Erase flash
            context = ProvisioningContext(self.target.provisioning_strategy)
            if kwargs.get('erase_flash'):
                context.erase_flash(tool, self.target)

            # Verify voltage
            voltage = self.target.voltage_tool.get_voltage(tool)
            v_min = self.target.voltage_tool.voltage_level * 0.9
            v_max = self.target.voltage_tool.voltage_level * 1.1
            if voltage < v_min or voltage > v_max:
                exam_pass = False
                logger.error(
                    'Silicon voltage is out of range. Expected voltage level '
                    'is in range %s V - %s V\n', v_min, v_max)
            else:
                exam_pass = True
            tool.set_ap(AP.SYS)

        # Verify entrance exam JWT signature
        if exam_pass:
            logger.info('Verify entrance exam JWT signature:')
            cy_pub_key = self.target.key_reader.get_cypress_public_key()
            exam_pass = jwt.validate_jwt(jwt_text, cy_pub_key)
            if exam_pass:
                logger.info('Signature verified')
            else:
                logger.error('Invalid signature')

        # Verify ahb_reads32
        if exam_pass:
            json_data = jwt.readable_jwt(jwt_text)
            payload = json_data['payload']
            tool.reset()
            exam_pass = self.verify_ahb_reads(tool, payload['ahb_reads'], 32)

        # Verify ahb_reads8
        if exam_pass:
            exam_pass &= self.verify_ahb_reads(tool, payload['ahb_reads8'], 8)

        # Verify region_hashes
        if exam_pass:
            for item in payload['region_hashes']:
                logger.info('.' * 70)
                logger.info('Verify %s', item['description'])
                logger.info('.' * 70)
                logger.info('Address: %s', item['address'])
                logger.info('Size:    %s', item['size'])
                logger.info('Mode:    %s', item['hash_id'])
                logger.info('Value:   %s', item['value'])
                syscall_status = region_hash(tool, self.reg_map)
                if syscall_status == RegionHashStatus.OK:
                    logger.info('PASS\n')
                else:
                    logger.info('FAIL\n')

        result = EntranceExamStatus.OK
        if exam_pass:
            if syscall_status == RegionHashStatus.FLASH_NOT_EMPTY:
                result = EntranceExamStatus.FLASH_NOT_EMPTY
            elif syscall_status == RegionHashStatus.FAIL:
                result = EntranceExamStatus.FAIL
        else:
            result = EntranceExamStatus.FAIL

        logger.info('*****************************************')
        if result == EntranceExamStatus.OK:
            logger.info('       ENTRANCE EXAM PASSED')
        else:
            logger.info('       ENTRANCE EXAM FAILED')
        logger.info('*****************************************')

        return result

    def log_protection_state(self, tool):
        lifecycle = read_lifecycle(tool, self.reg_map)
        try:
            protection_state = ProtectionState(lifecycle).name
        except ValueError:
            protection_state = f'{ProtectionState.unknown.name} ({lifecycle})'
        logger.info('Chip protection state: %s', protection_state.capitalize())

    def read_sfb_version(self, tool):
        jwt_text = jwt.read_jwt(self.entrance_exam_jwt)
        json_data = jwt.readable_jwt(jwt_text)
        payload = json_data['payload']
        major_version = None
        minor_version = None
        for item in payload['ahb_reads']:
            if item['description'].startswith('SFB_VER_HI'):
                address = int(item['address'], 0)
                mask = int(item['mask'], 0)
                sfb_ver_hi = tool.read32(address)
                major_version = sfb_ver_hi & mask
            if item['description'].startswith('SFB_VER_LO'):
                address = int(item['address'], 0)
                mask = int(item['mask'], 0)
                sfb_ver_lo = tool.read32(address)
                minor_version = sfb_ver_lo & mask
            if major_version and minor_version:
                break

        # Parse SFB version values
        maj_version = (sfb_ver_hi >> 24) & 0x0F
        min_version = (sfb_ver_hi >> 16) & 0xFF
        patch = sfb_ver_lo >> 24
        build = sfb_ver_lo & 0x0000FFFF

        return f'{maj_version}.{min_version}.{patch}.{build}'

    @staticmethod
    def verify_ahb_reads(tool, items, bits):
        """
        Verifies ahb_reads sections from entrance exam JWT packet.
        :param tool: Programming/debugging tool used for communication
               with device.
        :param items: ahb_reads items.
        :param bits: Indicates whether it is 8-bit or 32.-bit value.
        :return: True if values of all registers are as expected,
                 otherwise, False.
        """
        exam_pass = True
        for item in items:
            logger.info('.' * 70)
            logger.info('Verify %s', item['description'])
            logger.info('.' * 70)

            address = int(item['address'], 0)
            mask = int(item['mask'], 0)
            value = int(item['value'], 0)

            if bits == 8:
                read_value = tool.read8(address) & mask
            elif bits == 32:
                read_value = tool.read32(address) & mask
            else:
                raise ValueError('Invalid number of bits.')

            expected_value = value & mask
            logger.info('Address: %s', item["address"])
            logger.info('Expected value:     0x%x', expected_value)
            logger.info('Received value:     0x%x', read_value)
            if read_value == expected_value:
                logger.info('PASS\n')
            else:
                logger.info('FAIL\n')
                exam_pass = False
                if item['description'].startswith('SFB_VER_HI') \
                        or item['description'].startswith('SFB_VER_LO'):
                    logger.error(SFB_VER_ERROR)
        return exam_pass
