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
import re
import tempfile
from collections import namedtuple

from .base import ProgrammerBase
from .dfuht_runner import DfuhtRunner
from ..dfuht_commands.dfuht_packet import (
    DfuhtReadSeriesCommand, DfuhtReadCommand, DfuhtMeta
)
from ..dfuht_commands.dfuht_packet_creator import DfuhtCommandsCreator

logger = logging.getLogger(__name__)


class Dfuht(ProgrammerBase):
    """Wrapper around the DFU Host Tool which implements a single
    interface for OCDs
    """

    def __init__(self, name, settings):
        path = settings.ocd_path if settings else None
        super().__init__(name, path=path)
        self.runner = DfuhtRunner(settings) if settings else None
        self.probe_id = self.runner.serial_port if self.runner else None

    def connect(self, target_name=None, interface=None, probe_id=None, ap=None,
                acquire=True, power=None, voltage=None, rev=None):
        """Checks whether the specified target is connected"""
        if self.require_path and self.tool_path:
            self.runner.dfuht_path = self.tool_path

        probe_id = self.runner.serial_port
        protocol = self.runner.protocol

        for probe in self.get_probe_list():
            if protocol.replace('_', '-').lower() in probe.lower() \
                    and probe_id in probe:
                logger.info("Target connected %s", probe)
                return True

        raise ValueError(f"Unknown probe ID '{probe_id}'")

    def disconnect(self):
        """N/A for DFU Host Tool"""

    def get_ap(self):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def set_ap(self, _):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def set_frequency(self, _):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def halt(self):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def resume(self):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def reset(self, *_):
        """N/A for DFU Host Tool"""

    def reset_and_halt(self, *_):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def read8(self, address):
        """Reads 8-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value or error message
        """
        return self._read_cmd(address, 1)

    def read16(self, address):
        """Reads 16-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value or error message
        """
        return self._read_cmd(address, 2)

    def read32(self, address):
        """Reads 32-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value or error message
        """
        return self._read_cmd(address, 4)

    def write8(self, *_):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def write16(self, *_):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def write32(self, *_):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def write(self, address, data):
        raise NotImplementedError

    def read_reg(self, _):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def write_reg(self, *_):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def erase(self, address, size):
        raise NotImplementedError

    def program(self, filename, file_format=None, address=None, **kwargs):
        """Programs a file into flash
        @param filename: Path to image 'hex' file or custom command 'mtbdfu'
        @param file_format: File format 'hex' or 'mtbdfu'.
        @param address: N/A
        @return: True if success, otherwise False
        """
        if file_format == 'hex':
            cmd = ['--program-device', filename]
        elif file_format == 'mtbdfu':
            cmd = ['--custom-command', filename]
        else:
            raise ValueError('File format is not specified or unsupported')
        stdout, _ = self.runner.run(cmd)
        return self._result_check(stdout)

    def read(self, address, length):
        """Reads a block of unaligned bytes in memory
        @param address: The memory address where start reading
        @param length: Number of bytes to read
        @return: An array of byte values
        """
        return self._read_cmd(address, length, array=True)

    def get_probe_list(self):
        """Gets compatible connected hardware"""
        stdout, stderr = self.runner.run(
            ['--display-hw'], add_protocol_args=False, print_output=False)
        if not stdout:
            for line in stderr:
                logger.error(line)
        return stdout

    def get_voltage(self):
        """N/A for DFU Host Tool"""
        raise NotImplementedError

    def dump_image(self, filename, addr, size, **kwargs):
        """Dumps memory region to the file
        @param filename: Filename where to save the dump
        @param addr: Region address
        @param size: Region size
        @return: True if programmed successfully, otherwise False
        """
        chunk_size = kwargs.get('chunk_size', 256)
        dump_value = self._read_cmd(addr, size, array=True, chunk_size=chunk_size)
        dir_name = os.path.dirname(filename)
        if dir_name:
            os.makedirs(dir_name, exist_ok=True)
        with open(filename, 'wb') as f:
            f.write(dump_value)
        logger.debug("Load data to file '%s'", os.path.abspath(filename))
        return dump_value

    def verify(self, filename):
        """Image verification in the device memory
        @param filename: Path to image 'hex'
        @return: True if success, otherwise False
        """
        cmd = ['--verify-device', filename]
        stdout, _ = self.runner.run(cmd)
        return self._result_check(stdout)

    def _read_cmd(self, addr, length, array=False, chunk_size=256):
        """Creates custom command and reads data via DFU Host Tool
        @addr: Start address to read data
        @length: Number of bytes to read
        @array: Method returns bytes array if True, otherwise integer value
        @return: Returns integer value or bytes based on array parameter value
        """
        value = b''
        if isinstance(addr, int) and isinstance(length, int):
            addr = [addr]
            length = [length]

        if len(addr) != len(length):
            raise ValueError('Address and length lists '
                             'must have the same length')

        cmd_info_list = [self._read_cmd_series(a, l, chunk_size=chunk_size)
                         for a, l in zip(addr, length)]
        chunks = [chunk for row in cmd_info_list for chunk in row]

        with tempfile.TemporaryDirectory() as dfu_command_dir:
            cmd_name = os.path.join(dfu_command_dir, 'read_series_cmd.mtbdfu')
            dfu_command = DfuhtCommandsCreator(None, None, cmd_name)
            read_cmd = DfuhtReadSeriesCommand(*[DfuhtReadCommand(address, size)
                                                for (address, size) in chunks])
            logger.debug('Command path: %s', cmd_name)
            logger.debug('Command value: %s', repr(read_cmd))
            cmd = dfu_command.create_packet(DfuhtMeta(), read_cmd, cmd_name)
            stdout, _ = self.runner.run(['--custom-command', cmd.filename])
            if self._result_check(stdout):
                value += bytes.fromhex(''.join(
                    ['' if re.match(r'\[\w+\].+', s) else s
                     for s in stdout[:-1]]
                ))
            else:
                raise RuntimeError('Failed to read data')
        if not array:
            int_value = int.from_bytes(value, byteorder="little")
            return int_value
        return value

    @staticmethod
    def _image_info(address, image_id):
        """Image info data to program-device command"""
        cmd = ['--application-start', hex(address[0]),
               '--application-length', hex(address[1])]
        if image_id:
            cmd.extend(['--application-id', hex(image_id)])
        return cmd

    @staticmethod
    def _result_check(stdout):
        """Check for operation success status message"""
        return bool('Operation succeeded.' in stdout)

    @staticmethod
    def _read_cmd_series(addr, length, chunk_size=256):
        """Creates a collection of DFU custom commands if
        the amount of data exceeds 256 bytes
        """
        CmdInfo = namedtuple('CmdInfo', 'addr size')
        commands = []
        read_address = addr
        while length > chunk_size:
            commands.append(CmdInfo(read_address, chunk_size))
            read_address += chunk_size
            length -= chunk_size
        commands.append(CmdInfo(read_address, length))
        return commands
