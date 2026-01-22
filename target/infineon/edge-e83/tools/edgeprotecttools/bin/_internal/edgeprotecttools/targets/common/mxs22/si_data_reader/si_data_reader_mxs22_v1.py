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
import time
from collections import namedtuple

from ..enums import LifecycleStage
from .....core.crc import crc32d6a
from .....core.exceptions import ChecksumError

logger = logging.getLogger(__name__)

DeviceInfo = namedtuple('DeviceInfo', 'silicon_id silicon_rev family_id')
FwVersion = namedtuple(
    'FwVersion',
    'rom_boot rram_boot base_se_rt_services se_rt_services extended_boot')


class SiliconDataReaderMxs22V1:
    """ Implements reading data from the devices on MXS22 platform """

    bootrow_lcs_map = {
        '00000000000000000000000000000000': LifecycleStage.VIRGIN,
        '0000000000000000000000700000000b': LifecycleStage.SORT,
        '000000000000000000000b70000000db': LifecycleStage.PROVISIONED,
        '00000000000000d780000076bc00000b': LifecycleStage.NORMAL,
        '00000000000000d7800e0076bc00700b': LifecycleStage.NORMAL_NO_SECURE,
        '00000000000000d780000b76bc0000db': LifecycleStage.NORMAL_PROVISIONED,
        '00000000000000d78000db76bc000edb': LifecycleStage.SECURE,
        '00000000000000d79eb00076bef5000b': LifecycleStage.RMA_NORMAL,
        '00000000000000d79eb00b76bef500db': LifecycleStage.RMA_NORMAL_PROVISIONED,
        '00000000000000d79ebe0076bef5700b': LifecycleStage.RMA_NORMAL_NO_SECURE,
        '00000000000000d79eb0db76bef50edb': LifecycleStage.RMA_SECURE,
    }

    def __init__(self, target):
        self.target = target
        self.register_map = target.register_map
        self.fixed_read_addr = False

    def read_die_id(self, tool, timeout=10) -> dict:
        """ Reads device die ID """
        fields = None
        lcs = self.read_lifecycle_stage(tool)
        if lcs != LifecycleStage.VIRGIN:
            addr = self.register_map.die_id.addr
            size = self.register_map.die_id.size
            if self.fixed_read_addr:
                read_addr = self._non_sec_addr(addr)
            else:
                if lcs in [LifecycleStage.PROVISIONED, LifecycleStage.SORT]:
                    read_addr = addr
                else:
                    read_addr = self._non_sec_addr(addr)

            start_time = time.time()
            while True:
                try:
                    die_id = bytes(tool.read(read_addr, size))
                except RuntimeError:
                    logger.error('Unable to read die_id value')
                    break
                else:
                    if self.verify_checksum(die_id[10:size], die_id[:10], addr):
                        fields = {
                            'lot': int.from_bytes(die_id[:3],
                                                  byteorder='little'),
                            'wafer': int.from_bytes(die_id[3:4],
                                                    byteorder='little'),
                            'x': int.from_bytes(die_id[4:5],
                                                byteorder='little'),
                            'y': int.from_bytes(die_id[5:6],
                                                byteorder='little'),
                            'sort': int.from_bytes(die_id[6:7],
                                                   byteorder='little'),
                            'day': int.from_bytes(die_id[7:8],
                                                  byteorder='little'),
                            'month': int.from_bytes(die_id[8:9],
                                                    byteorder='little'),
                            'year': int.from_bytes(die_id[9:10],
                                                   byteorder='little'),
                        }
                        break
                    logger.debug('Incorrect DIE_ID checksum')
                    time.sleep(0.2)
                    if time.time() - start_time >= timeout:
                        logger.error('Incorrect DIE_ID checksum')
                        break
        else:
            logger.error('Unable to read die_id in the current LCS %s',
                         lcs.name)
        return fields

    def read_lifecycle_stage(self, tool, timeout=25) -> LifecycleStage:
        """ Reads device lifecycle stage """
        lcs = None
        start_time = time.time()
        while lcs is None:
            bootrow_0 = SiliconDataReaderMxs22V1.read32(
                tool, self.target.register_map.bootrow_0)
            bootrow_1 = SiliconDataReaderMxs22V1.read32(
                tool, self.target.register_map.bootrow_1)
            bootrow_2 = SiliconDataReaderMxs22V1.read32(
                tool, self.target.register_map.bootrow_2)
            bootrow_3 = SiliconDataReaderMxs22V1.read32(
                tool, self.target.register_map.bootrow_3)

            value = (bootrow_3.to_bytes(4, byteorder='big') +
                     bootrow_2.to_bytes(4, byteorder='big') +
                     bootrow_1.to_bytes(4, byteorder='big') +
                     bootrow_0.to_bytes(4, byteorder='big'))
            value = value.hex()
            try:
                lcs = self.bootrow_lcs_map[value]
                logger.debug('BOOTROW value = %s', value)
                break
            except KeyError as ex:
                lcs = None
                logger.debug('Unknown BOOTROW value %s', ex)
                time.sleep(0.2)
            logger.debug('LCS = %s', lcs)
            if time.time() - start_time >= timeout:
                logger.error("Unknown BOOTROW value '%s'", value)
                raise TimeoutError('Reading BOOTROW timeout')
        return lcs

    @staticmethod
    def read32(tool, addr):
        """Reading data with retry if failed"""
        attempt = 1
        timeout = 5
        start_time = time.time()
        while (time.time() - start_time) <= timeout:
            try:
                data = tool.read32(addr)
            except RuntimeError:
                logger.debug("Attempt to read failed %d", attempt)
            else:
                return data
            attempt += 1
        raise TimeoutError(f"Unable to read '{addr:#010x}'")

    def read_device_info(self, tool, timeout=10) -> DeviceInfo:
        """ Reads silicon ID, revision ID, family ID from the device """
        family_id = None
        si_revision_id = None
        silicon_id = None

        lcs = self.read_lifecycle_stage(tool)

        if lcs != LifecycleStage.VIRGIN:
            try:
                family_id, si_revision_id = self.device_id_to(
                    tool, lcs, timeout=timeout)
            except RuntimeError:
                logger.error('Unable to read DEVICE_ID_TO value')
            except ChecksumError as e:
                logger.error(e)
        else:
            logger.error('Unable to read revision ID and family ID '
                         'in the current LCS %s', lcs.name)

        if lcs not in (LifecycleStage.VIRGIN, LifecycleStage.SORT,
                       LifecycleStage.PROVISIONED):
            try:
                silicon_id = self.device_id_mpn(tool, timeout=timeout)
            except RuntimeError:
                logger.error('Unable to read DEVICE_ID_MNP value')
            except ChecksumError as e:
                logger.error(e)
        else:
            logger.error('Unable to read silicon ID in the current LCS %s',
                         lcs.name)

        return DeviceInfo(silicon_id, si_revision_id, family_id)

    def device_id_mpn(self, tool, timeout=10):
        """Read DEVICE_ID_MPN from device"""
        addr = self.register_map.device_id_mpn.addr
        size = self.register_map.device_id_mpn.size
        read_addr = self._non_sec_addr(addr)

        start_time = time.time()
        while True:
            device_id_mpn = bytes(tool.read(read_addr, size))
            if self.verify_checksum(device_id_mpn[2:size], device_id_mpn[:2],
                                    addr):
                break
            logger.debug('Incorrect DEVICE_ID_MNP checksum')
            time.sleep(0.2)
            if time.time() - start_time >= timeout:
                raise ChecksumError('Incorrect DEVICE_ID_MNP checksum')

        silicon_id = int.from_bytes(device_id_mpn[:2], byteorder='little')
        return silicon_id

    def device_id_to(self, tool, lcs, timeout=10):
        """Read DEVICE_ID_TO from device"""
        addr = self.register_map.device_id_to.addr
        size = self.register_map.device_id_to.size
        if self.fixed_read_addr:
            read_addr = self._non_sec_addr(addr)
        else:
            if lcs == LifecycleStage.PROVISIONED:
                read_addr = addr
            else:
                read_addr = self._non_sec_addr(addr)

        start_time = time.time()
        while True:
            device_id_to = bytes(tool.read(read_addr, size))
            if self.verify_checksum(device_id_to[3:size], device_id_to[:3],
                                    addr):
                break
            logger.debug('Incorrect DEVICE_ID_TO checksum')
            time.sleep(0.2)
            if time.time() - start_time >= timeout:
                raise ChecksumError('Incorrect DEVICE_ID_TO checksum')

        family_id = int.from_bytes(device_id_to[:2], byteorder='little')
        si_revision_id = int.from_bytes(device_id_to[2:3], byteorder='little')
        return family_id, si_revision_id

    def read_fw_version(self, tool, timeout=10) -> FwVersion:
        """Reads version of ROM_BOOT, RRAM_SE_BOOT, BASE_SE_RT_SERVICES,
        SE_RT_SERVICES and EXTENDED_BOOT
        """
        lcs = self.read_lifecycle_stage(tool)
        rom_boot, rram_boot = self.read_l0_version(tool, lcs, timeout=timeout)
        base_se_rt_services, se_rt_services, extended_boot = self.read_l1_version(
            tool, lcs, timeout=timeout)
        fw_version = FwVersion(rom_boot, rram_boot, base_se_rt_services,
                               se_rt_services, extended_boot)
        return fw_version

    def read_l0_version(self, tool, lcs, timeout=10):
        """Reads L0_VERSION
        @return: Version of ROM_BOOT, RRAM_BOOT
        """
        addr = self.register_map.l0_version.addr
        size = self.register_map.l0_version.size
        if self.fixed_read_addr:
            read_addr = self._non_sec_addr(addr)
        else:
            if lcs == LifecycleStage.PROVISIONED:
                read_addr = addr
            else:
                read_addr = self._non_sec_addr(addr)

        rom_boot = None
        rram_boot = None
        start_time = time.time()
        while True:
            try:
                se_version = bytes(tool.read(read_addr, size))
            except RuntimeError:
                logger.error('Unable to read L0_VERSION value')
                break
            else:
                if self.verify_checksum(se_version[16:size], se_version[:16],
                                        addr):
                    rom_boot = se_version[:8]
                    rram_boot = se_version[8:16]
                    break
                logger.debug('Incorrect L0_VERSION checksum')
                time.sleep(0.2)
                if time.time() - start_time >= timeout:
                    logger.error('Incorrect L0_VERSION checksum')
                    break
        return rom_boot, rram_boot

    def read_l1_version(self, tool, lcs, timeout=10):
        """Reads L1_VERSION
        @return: Version of BASE_SE_RT_SERVICES, SE_RT_SERVICES, EXTENDED_BOOT
        """
        addr = self.register_map.l1_version.addr
        size = self.register_map.l1_version.size
        if self.fixed_read_addr:
            read_addr = self._non_sec_addr(addr)
        else:
            if lcs == LifecycleStage.PROVISIONED:
                read_addr = addr
            else:
                read_addr = self._non_sec_addr(addr)

        base_se_rt_services = None
        se_rt_services = None
        extended_boot = None
        start_time = time.time()
        while True:
            try:
                se_version = bytes(tool.read(read_addr, size))
            except RuntimeError:
                logger.error('Unable to read L1_VERSION value')
                break
            else:
                if self.verify_checksum(se_version[24:size], se_version[:24],
                                        addr):
                    base_se_rt_services = se_version[:8]
                    se_rt_services = se_version[8:16]
                    extended_boot = se_version[16:24]
                    break
                logger.debug('Incorrect L1_VERSION checksum')
                time.sleep(0.2)
                if time.time() - start_time >= timeout:
                    logger.error('Incorrect L1_VERSION checksum')
                    break
        return base_se_rt_services, se_rt_services, extended_boot

    def read_extended_boot_info(self, tool):
        """Reads extended boot info and returns tuple of mode and status"""
        mode = None
        status = None
        info = None
        addr = self.register_map.extended_boot_info.addr
        size = self.register_map.extended_boot_info.size

        try:
            info = bytes(tool.read(addr, size))
        except RuntimeError:
            logger.error('Unable to read extended boot status value')
        if info:
            mode = int.from_bytes(info[:4], 'little')
            status = int.from_bytes(info[4:], 'little')
        return mode, status

    @staticmethod
    def verify_checksum(checksum_bytes, data, init_value):
        """Verifies checksum
        @param checksum_bytes: 4-Byte checksum read from device
        @param data: Data bytes for which the checksum has to be calculated
        @param init_value: Checksum initial value. For the crc32d6a algorithm
            it must be the data address in the memory
        """
        checksum = int.from_bytes(checksum_bytes, byteorder='big')
        expected_checksum = crc32d6a(data, init_value)
        return checksum == expected_checksum

    def _efuses_enabled(self, tool):
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        return efuse_ctl & 0x80000000 == 0x80000000

    def _enable_efuses(self, tool):
        """ Enables reading data from eFuses """
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        tool.write32(self.target.register_map.EFUSE_CTRL_ADDR,
                     efuse_ctl | 0x80000000)

    def _disable_efuses(self, tool):
        """ Disables reading data from eFuses """
        efuse_ctl = tool.read32(self.target.register_map.EFUSE_CTRL_ADDR)
        tool.write32(self.target.register_map.EFUSE_CTRL_ADDR,
                     efuse_ctl & 0x7FFFFFFF)

    def _non_sec_addr(self, addr):
        """Converts the address to non-secure"""
        return addr & self.target.register_map.non_secure_mask
