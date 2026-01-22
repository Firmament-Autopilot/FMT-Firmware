"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import hashlib
import logging

from . import EntranceExamMXS40v1
from .....core.target_director import Target
from .....core.enums import EntranceExamStatus
from .....execute import jwt

logger = logging.getLogger(__name__)


class EntranceExamCyb06xx7(EntranceExamMXS40v1):
    def __init__(self, target: Target, **kwargs):
        super(EntranceExamCyb06xx7, self).__init__(target, **kwargs)
        self.word_size = 4
        self.asset_hash_len = 16
        self.mem_map = target.memory_map

    def execute(self, tool, **kwargs):
        """
        Checks device life-cycle, Flashboot firmware, Flash state and
        bunch of registers.
        """
        exam_status = super(EntranceExamCyb06xx7, self).execute(tool, **kwargs)
        if exam_status == EntranceExamStatus.OK:
            if self.verify_asset_hash(tool):
                return EntranceExamStatus.OK
            else:
                return EntranceExamStatus.FAIL

    def verify_asset_hash(self, tool):
        """
        Verifies SecureFlashBoot asset hash
        """
        logger.info('Verify SecureFlashBoot asset hash:')
        jwt_text = jwt.read_jwt(self.entrance_exam_jwt)
        json_data = jwt.readable_jwt(jwt_text)
        payload = json_data['payload']['ahb_reads8']

        segments = self._get_sfb_toc1_segments(tool)
        sfb_hash = self._calculate_sfb_asset_hash(tool, segments)

        exam_pass = self._compare_asset_hash(sfb_hash, payload)
        return exam_pass

    def _get_sfb_toc1_segments(self, tool):
        """
        Gets SecureFlashBoot TOC1 segments address and size
        """
        segments = list()
        #
        # Calculate constant objects for hash calculation:
        #
        # Flash boot in SFlash
        fb_address = self._read_word(tool, self.mem_map.TOC1_ADDRESS
                                     + self.mem_map.TOC1_SFB_ADDRESS_OFFSET)
        fb_size = self._read_word(tool, fb_address)

        # Syscall table address value
        syscall_table_val = 0  # means that key is a value for hash calculation

        # Append to hash object list constant objects
        segments.append(self._pair(fb_address, fb_size))
        segments.append(self._pair(self.mem_map.SYSCALL_TABLE_ADDR,
                                   syscall_table_val))

        # Append the rest of hash object in TOC1
        # Calculate number of rest hash objects in TOC1
        hash_obj_addr = self.mem_map.TOC1_ADDRESS \
            + self.mem_map.TOC1_HASH_OBJ_OFFSET
        toc1_hash_objects = self._read_word(tool, hash_obj_addr)
        num_rest_hash_objects = int(toc1_hash_objects - (
                ((self.mem_map.TOC1_SFB_ADDRESS_OFFSET
                  - self.mem_map.TOC1_HASH_OBJ_OFFSET) / self.word_size) - 1))

        # Reduce by 2 a number of hash objects because Flash_Boot
        # and Syscall_Table already included
        precalculated_object_count = 2
        num_rest_hash_objects -= precalculated_object_count
        toc1_rest_objects_address = self.mem_map.TOC1_ADDRESS \
            + self.mem_map.TOC1_SFB_ADDRESS_OFFSET \
            + int(self.word_size * precalculated_object_count)

        # Get the rest of hash objects in TOC1
        rest_hash_objects = self._get_toc1_objects(tool,
                                                   toc1_rest_objects_address,
                                                   num_rest_hash_objects)

        # Extend existing list of hash objects with additional hash objects
        segments.extend(rest_hash_objects)
        return segments

    def _calculate_sfb_asset_hash(self, tool, segments, truncate_to_bytes=0):
        """
        Calculates SecureFlashBoot asset hash
        """
        sha256 = hashlib.sha256()
        if len(segments) > 0:
            logger.debug('Read SFB TOC1 objects')
            for addr_value_pair in segments:
                for address, read_size in addr_value_pair.items():
                    logger.debug(
                        'Address: 0x%x, Size: 0x%x', address, read_size)
                    if read_size != 0:
                        # Read bytes from specific address and calculate hash
                        # from it
                        data = tool.read(address, read_size)
                        binary = bytes(data)
                        logger.debug('Data: %s', data)
                        logger.debug('Binary data: %s', binary)
                        sha256.update(binary)
                    else:
                        # Hash should be calculated from 'address' value
                        byte_list = address.to_bytes(self.word_size,
                                                     byteorder='little',
                                                     signed=False)
                        logger.debug('Data: %s', address)
                        logger.debug('Binary data: %s', byte_list)
                        sha256.update(byte_list)
            sfb_hash = list(sha256.digest())
            sfb_hash = self._truncate_list(sfb_hash, truncate_to_bytes)
            logger.debug('SFB hash: %s', sfb_hash)
        else:
            logger.error('No SecureFlashBoot TOC1 segments')
            sfb_hash = None
        return sfb_hash

    def _compare_asset_hash(self, sfb_hash, items):
        """
        Compares calculated ASSET_HASH values with the values from JWT
        """
        exam_pass = True

        if len(sfb_hash) < self.asset_hash_len:
            logger.error(
                'Invalid length of SFB asset hash array %d', len(sfb_hash))
            return False

        for i in range(self.asset_hash_len):
            item = self._get_jwt_item_by_name(items, f'ASSET_HASH byte {i}')

            logger.info('.' * 70)
            logger.info('Verify %s', item['description'])
            logger.info('.' * 70)

            expected_value = int(item['value'], 0)
            received_value = sfb_hash[i]

            logger.info('Expected value:     0x%x', expected_value)
            logger.info('Received value:     0x%x', received_value)
            if received_value == expected_value:
                logger.info('PASS\n')
            else:
                logger.info('FAIL\n')
                exam_pass = False
        return exam_pass

    def _get_toc1_objects(self, tool, start_address, object_count):
        """
        Get required objects for HASH from TOC1
        """
        toc1_objects = list()
        for i in range(object_count):
            address = self._read_word(tool, start_address + int(
                i * self.word_size))
            size = self._read_word(tool, address)
            toc1_objects.append(self._pair(address, size))
        return toc1_objects

    def _read_word(self, tool, address):
        byte_list = tool.read(address, self.word_size)
        reg_value = int.from_bytes(byte_list, byteorder='little', signed=False)
        return reg_value

    @staticmethod
    def _truncate_list(hash_list, truncate_to_bytes):
        if 0 <= truncate_to_bytes < len(hash_list):
            if 0 != truncate_to_bytes:
                hash_list = hash_list[:-truncate_to_bytes]
        else:
            raise ValueError('Invalid truncate value.')
        return hash_list

    @staticmethod
    def _pair(key, val):
        return {key: val}

    @staticmethod
    def _get_jwt_item_by_name(items, name):
        for item in items:
            if item['description'].startswith(name):
                return item
