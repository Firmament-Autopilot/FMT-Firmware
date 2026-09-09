"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import random
import re
import sys
import json
import socket
import signal
import logging

from .openocd_server import OpenocdServer
from .base import ProgrammerBase, ResetType, AP
from ...core.target_director import TargetDirector

TARGET_MAP = os.path.join(os.path.dirname(__file__), 'openocd_target_map.json')
logger = logging.getLogger(__name__)


class Openocd(ProgrammerBase):
    """OpenOCD wrapper for client side"""

    _CMD_SUCCESS = 0
    _CMD_FAIL = -1

    def __init__(self, name, settings):
        path = settings.ocd_path if settings else None
        super().__init__(name, path=path)
        self.sock = None
        self.target = None
        self.ocd_server = None
        self.verbose = False
        self.tcp_host_address = '127.0.0.1'
        self.sock_buffer_size = 4096
        self._command_token = '\x1a'
        self.probe_id = None

        # Older versions of OpenOCD when connected to server via TCL port
        # require 'ocd_' prefix to get command output
        self.ocd_cmd_prefix = ''

        # Patterns to check an error message
        self._error_msg_patterns = [
            'Failed to',
            'Error',
            'error writing',
            'invalid command name',
        ]
        self.current_ap = AP.SYS  # currently selected by user access port
        self.connect_ap = AP.SYS  # access port selected before init
        self.mcu = None
        self.cm0_name = None
        self.cm4_name = None
        self.cm33_name = None
        self.cm55_name = None
        self.sysap_name = None

    def connect(self, target_name=None, interface=None, probe_id=None,
                ap='sysap', acquire=None, power=None, voltage=None, rev=None):
        """
        Connects to target using default debug interface.
        @param target_name: The target name.
        @param interface: Debug interface.
        @param probe_id: Probe serial number.
        @param ap: The access port to be used for flash operations
        @param acquire: Indicates whether to acquire device on connect
        @param power: Indicates whether to on/off the KitProg3 power
        @param voltage: The KitProg3 voltage level
        @param rev: The target revision
        @return: True if connected successfully, otherwise False
        """
        if interface:
            raise NotImplementedError

        if target_name:
            full_name = target_name + '_' + rev if rev else target_name
            ocd_target_name = ''
            # Search for device in target map
            with open(TARGET_MAP, encoding='utf-8') as f:
                file_content = f.read()
                json_data = json.loads(file_content)
            for json_target in json_data:
                if full_name.lower().strip() == json_target.lower().strip():
                    # Get target info
                    director = TargetDirector()
                    try:
                        from ...targets import get_target_builder
                        get_target_builder(director, target_name, rev=rev)
                    except KeyError as e:
                        raise ValueError(
                            f'Unknown target "{target_name}"') from e
                    self.target = director.get_target(None, None)
                    # Get target name which is relevant to OpenOCD
                    ocd_target_name = json_data[json_target]['target']
                    self.mcu = json_data[json_target].get('mcu')
                    self.cm0_name = json_data[json_target].get('cm0')
                    self.cm4_name = json_data[json_target].get('cm4')
                    self.cm33_name = json_data[json_target].get('cm33')
                    self.cm55_name = json_data[json_target].get('cm55')
                    self.sysap_name = json_data[json_target].get('sysap')
                    break
        else:
            raise ValueError("Parameter 'target_name' is None")

        if ap == 'cm4':
            self.connect_ap = AP.CM4
        elif ap == 'cm0':
            self.connect_ap = AP.CM0
        elif ap == 'sysap':
            self.connect_ap = AP.SYS
        elif ap == 'cm33':
            self.connect_ap = AP.CM33
        else:
            if not power:
                raise ValueError(f'Invalid access port value \'{ap}\'')

        # Register the signal handlers
        # When TERMINATE or INT signal from the system will be received,
        # the OCD server will be stopped
        signal.signal(signal.SIGTERM, self._terminate_signal_received)
        signal.signal(signal.SIGINT, self._terminate_signal_received)

        tcp_host_port = self.get_free_port()

        # Configure OpenOCD server
        self.ocd_server = OpenocdServer(
            self.target, ocd_target_name, interface, probe_id,
            tool_path=self.tool_path, power=power, voltage=voltage,
            tcp_host_port=tcp_host_port)
        self.probe_id = self.ocd_server.probe_id
        # Start GDB server and check if it is started
        server_started = self.ocd_server.start(ap, acquire)
        # No need of further connection if the power command is sent
        if power:
            return server_started
        if server_started:
            # Connect to OpenOCD server
            if self.sock is None:
                self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.sock.connect((self.tcp_host_address, tcp_host_port))
            else:
                raise ValueError('Debug session has already initialized')
        else:
            return False

        return True

    def get_free_port(self, min_port=6660, max_port=6678, attempts=1000):
        """Search for the free port
        @param min_port: Min port number
        @param max_port: Max port number
        @param attempts: Max number of connection attempts
        @return: Init port if free or alternative port number
        """
        attempt = 0
        port = min_port
        if min_port > max_port:
            raise ValueError(
                'The min_port number must be less than the max_port number')
        host_check = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        while attempt < attempts:
            port = random.randint(min_port, max_port)
            try:
                host_check.bind((self.tcp_host_address, port))
                break
            except OSError:
                attempt += 1
                logger.debug('Attempt to connect to port %s failed', port)
        host_check.close()
        if attempt >= attempts:
            raise ConnectionError(
                'The maximum number of connection attempts has been reached')
        return port

    def disconnect(self):
        """Closes active connection"""
        self.halt()  # halted core before disconnecting from it
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        self.sock.close()
        self.sock = None
        self.ocd_server.stop()

    def set_frequency(self, value_khz):
        """Sets probe frequency
        @param value_khz: Frequency in kHz
        """
        if self.sock is None:
            raise ValueError('Debug probe is not initialized')
        self._send('adapter speed {0}'.format(value_khz))

    def halt(self):
        """Halts the core"""
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        logger.debug('halt')
        self._send('halt')

    def resume(self):
        """Resumes the execution"""
        if self.sock is None:
            raise ValueError('Target is not initialized')
        logger.debug('resume')
        self._send('resume')

    def reset(self, reset_type=ResetType.SW):
        """Resets the target
        @param reset_type: The reset type
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        logger.debug('reset')
        if reset_type == ResetType.HW_SR:
            self._send('adapter assert srst')
            self._send('adapter deassert srst')
        else:
            if reset_type == ResetType.SW:
                self._send('reset_config srst_only')
            elif reset_type == ResetType.HW:
                self._send('reset_config trst_only')
            elif reset_type == ResetType.HW_SW:
                self._send('reset_config trst_and_srst')
            self._send('reset run')

    def reset_and_halt(self, reset_type=ResetType.SW):
        """Resets the target and halts the CPU immediately after reset
        @param reset_type: The reset type
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        logger.debug('reset_and_halt')
        self._send('reset init')

    def read8(self, address):
        """Reads 8-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        cmd_rsp = self._send('mdb 0x{0:x}'.format(address))
        value = self._parse_and_convert_read(cmd_rsp)
        logger.debug('read8 (0x%x): 0x%x', address, value)
        return value

    def read16(self, address):
        """Reads 16-bit value from specified memory location.
        @param address: The memory address to read
        @return: The read value
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        if (address & 0x01) == 0:
            cmd_rsp = self._send('mdh 0x{0:x}'.format(address))
            value = self._parse_and_convert_read(cmd_rsp)
            logger.debug('read16 (0x%x): 0x%x', address, value)
            return value
        raise ValueError('Address not aligned')

    def read32(self, address):
        """Reads 32-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        if (address & 0x03) == 0:
            cmd_rsp = self._send('mdw 0x{0:x}'.format(address))
            value = self._parse_and_convert_read(cmd_rsp)
            logger.debug('read32 (0x%x): 0x%x', address, value)
            return value
        raise ValueError('Address not aligned')

    def write8(self, address, value):
        """Writes 8-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 8-bit value to write
        """
        if self.sock is None:
            raise ValueError('Target is not initialized.')
        logger.debug('write8 (0x%x): 0x%x', address, value)
        data = self._send('mwb 0x{0:x} 0x{1:x}'.format(address, value))
        return data

    def write16(self, address, value):
        """Writes 16-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 16-bit value to write
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')
        logger.debug('write16 (0x%x): 0x%x', address, value)
        data = self._send('mwh 0x{0:x} 0x{1:x}'.format(address, value))
        return data

    def write32(self, address, value):
        """Writes 32-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 32-bit value to write
        """
        self._send('targets')
        if self.sock is None:
            raise ValueError('Target is not initialized')
        logger.debug('write32 (0x%x): 0x%x', address, value)
        data = self._send('mww 0x{0:x} 0x{1:x}'.format(address, value))
        return data

    def read_reg(self, reg_name):
        """Gets value of a core register
        @param reg_name: Core register name
        @return: The register value
        """
        reg = reg_name.lower()
        value = self._send('reg {0}'.format(reg))
        logger.debug('read_reg (%s): 0x%x', reg, value)
        return value

    def write_reg(self, reg_name, value):
        """Sets value of a core register
        @param reg_name: Core register name
        @param value: The value to set
        @return: The register value
        """
        reg = reg_name.lower()
        logger.debug('write_reg (%s): 0x%x', reg, value)
        self._send('reg {0} {1:#x}'.format(reg, value))

    def erase(self, address, size):
        """Erases entire device flash or specified sectors
        @param address: The memory location
        @param size: The memory size
        """
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        self.halt()
        logger.debug('erase 0x%x-0x%x', address, address + size)
        self._send('flash erase_address {0} {1}'.format(address, size))

    def program(self, filename, file_format=None, address=None, **kwargs):
        """Programs a file into flash
        @param filename: Path to a file
        @param file_format: N/A for OpenOCD
        @param address: Base address used for the address where to
               flash a binary
        @return: True if programmed successfully, otherwise False
        """
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        # Remove Windows-style path separator
        filename = filename.replace(os.sep, '/')
        self.halt()
        if address:
            logger.debug("Programming '%s' to %s", filename, address)
            self._send(f'flash write_image erase "{filename}" {address}')
        else:
            logger.debug("Programming '%s'", filename)
            self._send(f'flash write_image erase "{filename}"')

    def program_ram(self, filename, _file_format=None, address=None):
        """Programs a file into flash
        @param filename: Path to a file
        @param _file_format: N/A for OpenOCD
        @param address: Base address used for the address where to
               flash a binary
        @return: True if programmed successfully, otherwise False
        """
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        # Remove Windows-style path separator
        filename = filename.replace(os.sep, '/')
        self.halt()
        if address:
            logger.debug("Programming '%s' to %s", filename, address)
            self._send(f'load_image "{filename}" {address}')
        else:
            logger.debug("Programming '%s'", filename)
            self._send(f'load_image "{filename}"')

    def _parse_read(self, cmd_response):
        """Parse OpenOCD output from read memory commands
        @param cmd_response: String with response from server to the
               read command
        @return: The register as integer value
        """
        for err_msg in self._error_msg_patterns:
            if err_msg in cmd_response:
                logger.error("Unable to get data from the memory")
                return self._CMD_FAIL
        cmd_result = cmd_response.split(':')
        value = cmd_result[1].strip()
        return value

    def _parse_and_convert_read(self, cmd_response):
        """Parse OpenOCD output from read memory commands
        @param cmd_response: String with response from server to the
               read command
        @return: The register as integer value
        """
        value = self._parse_read(cmd_response)
        value = int(value, 16)
        return value

    def _send(self, cmd):
        """Send a command to TCL RPC
        Note: This command also check command status and if it is not
        SUCCESS raise ValueError exception
        @param cmd: String with command for OpenOCD server
        @return: String with response on sent command to the server
        """
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
            # Stop OpenOCD server if termination signal was received

        if self.verbose:
            logger.info('send -> %s', cmd)

        # Append ocd_ prefix to each command
        cmd = ''.join([self.ocd_cmd_prefix, cmd])
        logger.debug("Sending command '%s'", cmd)
        # 1. Send command and save status code and message
        send_cmd = 'set cmd_status [catch {{ {0} }} cmd_msg]'.format(cmd)
        cmd_status = self._send_cmd(send_cmd)
        # 2. Send set command to get message
        send_cmd = 'set cmd_response "$cmd_msg"'
        cmd_message = self._send_cmd(send_cmd)

        # Check if command status is OK (_CMD_SUCCESS)
        err_code = int(cmd_status, 16)
        if self._CMD_SUCCESS != err_code:
            raise RuntimeError("Command FAILED: {1}{0}{1}".format(cmd_message,
                                                                  os.linesep))
        cmd_message = cmd_message.rstrip()
        if cmd_message:
            logger.debug(cmd_message)
        return cmd_message

    def _send_cmd(self, cmd):
        """Send a command string to TCL RPC
        @param cmd: String with command for OpenOCD server
        @return: String with response on sent command
        """
        data = (cmd + self._command_token).encode("utf-8")
        self.sock.send(data)
        return self._receive()

    def _receive(self):
        """Read from the stream until the token (\x1a) was received
        @return: String with response on sent command to the server
        """
        data = bytes()
        while True:
            chunk = self.sock.recv(self.sock_buffer_size)
            data += chunk
            if bytes(self._command_token, encoding="utf-8") in chunk:
                break
        data = data.decode("utf-8").strip()
        data = data[:-1]  # strip trailing command token \x1a
        if self.verbose:
            logger.info('receive -> %s', data)
        return data

    def _terminate_signal_received(self, *_args):
        """
        The termination signal from the system was received
        """
        if logger is not None:
            logger.info('The termination signal from the system was received')
        if self.sock is not None:
            self.sock.close()
        self.ocd_server.stop()
        sys.exit(0)

    def get_ap(self):
        """Gets access port
        @return: Selected AP
        """
        logger.debug('AP: %s', self.current_ap)
        return self.current_ap

    def set_ap(self, ap: AP):
        """Sets access port
        @param ap: Access port
        """
        if ap == AP.CM0:
            self._send(f'targets {self.mcu}.{self.cm0_name}')
        elif ap == AP.CM4:
            self._send(f'targets {self.mcu}.{self.cm4_name}')
        elif ap == AP.CMx:
            if self.connect_ap == AP.CM0:
                self._send(f'targets {self.mcu}.{self.cm0_name}')
            elif self.connect_ap == AP.CM4:
                self._send(f'targets {self.mcu}.{self.cm4_name}')
            elif self.connect_ap == AP.CM33:
                self._send(f'targets {self.mcu}.{self.cm33_name}')
        elif ap == AP.CM33:
            self._send(f'targets {self.mcu}.{self.cm33_name}')
        elif ap == AP.SYS:
            self._send(f'targets {self.mcu}.{self.sysap_name}')
        self._send('targets')
        self.current_ap = ap

    def read(self, address, length):
        """Reads a block of unaligned bytes in memory
        @param address: The memory address where start reading
        @param length: Number of bytes to read
        @return: An array of byte values
        """
        def read_memory(addr, size):
            cmd = 'read_memory 0x{0:x} 8 {1}'.format(addr, size)
            logger.debug(cmd)
            response = self._send(cmd)
            value = [int(i, 16) for i in response.split()]
            return value

        # The maximum length limit of the 'read_memory' command is 64K
        # elements. For better performance, the maximum chunk size is 20K
        data = []
        max_size = 0x5000
        if length > max_size:
            read_address = address
            while len(data) < length:
                if len(data) + max_size > length:
                    read_size = length - len(data)
                else:
                    read_size = max_size
                data.extend(read_memory(read_address, read_size))
                read_address += read_size
        else:
            data = read_memory(address, length)

        return data

    def write(self, address, data):
        """Write a block of unaligned bytes in memory
        @param address: The memory address where start writing
        @param data: An array of byte values
        """
        if self.sock is None:
            raise ValueError('Target is not initialized.')

        if isinstance(data, list) and all(isinstance(i, int) for i in data):
            value = ' '.join([hex(i) for i in data])
        elif isinstance(data, (bytes, bytearray)):
            s = data.hex()
            value = '0x' + ' 0x'.join([s[i:i + 2] for i in range(0, len(s), 2)])
        else:
            raise ValueError('Either int array or bytes is supported')

        cmd = 'write_memory 0x{0:x} 8 {{{1}}}'.format(address, value)
        logger.debug(cmd)
        self._send(cmd)

    def get_probe_list(self):
        """Not implemented in OpenOCD"""
        raise NotImplementedError

    def examine_ap(self):
        """Examines CMx (depending on selected ap for connection) AP
        without reset
        """
        if self.connect_ap == AP.CM0:
            ap = self.cm0_name
        elif self.connect_ap == AP.CM4:
            ap = self.cm4_name
        elif self.connect_ap == AP.SYS:
            ap = self.sysap_name
        else:
            raise ValueError(f"Invalid DAP '{self.connect_ap}'")

        self._send(f'{self.mcu}.{ap} arp_examine')

    def get_voltage(self):
        """Reads target voltage
        @return Voltage value in Volts
        """
        if self.sock is None:
            raise ValueError('Target is not initialized')

        if self.ocd_server.probe_interface == 'kitprog3':
            logger.debug('kitprog3 get_power')
            response = self._send('kitprog3 get_power')
            match = re.search('VTarget = ([0-9.,]+) V', response)
            if match is not None:
                voltage = float(match.group(1))
                logger.debug('VTarget = %s', voltage)
            else:
                voltage = None
                logger.warning('VTarget is unknown')
        else:
            raise NotImplementedError
        return voltage

    def dump_image(self, filename, addr, size, **kwargs):
        """Dumps memory region to the file
        @param filename: Filename where to save the dump
        @param addr: Region address
        @param size: Region size
        @return: True if programmed successfully, otherwise False
        """
        if self.sock is None:
            raise ValueError('Debug session is not initialized')
        # Remove Windows-style path separator
        filename = filename.replace(os.sep, '/')
        logger.debug("Load data to file '%s'", filename)
        self._send(f'dump_image {filename} {addr} {size}')

    def verify(self, filename):
        """N/A to OpenOCD"""
