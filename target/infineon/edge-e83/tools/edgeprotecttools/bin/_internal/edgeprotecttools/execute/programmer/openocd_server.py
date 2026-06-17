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
import os
import logging
import enum
import platform
import time
import atexit
import subprocess
from pathlib import Path
from collections import namedtuple

from ...core.logging_configurator import LoggingConfigurator
from ...core.ocd_settings import OcdSettings

logger = logging.getLogger(__name__)


class OcdTransport(enum.Enum):
    """ Enum with supported transport protocols in OpenOCD """
    SWD = 'swd'
    JTAG = 'jtag'


class OcdProbeInterface(enum.Enum):
    """ Enum with supported debug probes in OpenOCD """
    KITPROG3 = 'kitprog3'
    CMSIS_DAP = 'cmsis-dap'


class OcdAcquire(enum.IntEnum):
    """ Enum with possible Acquire options in OpenOCD """
    ENABLE = 1
    DISABLE = 0


OcdCustomConfig = namedtuple(
    'OcdCustomConfig', 'variables interface before_init after_init')


class OcdConfig:
    """
        This is a class which contains configuration settings for OpenOCD.

        See OpenOCD documentation for details:
        http://openocd.org/doc/pdf/openocd.pdf
    """

    def __init__(self):
        """ Set initial basic configuration params for OpenOCD """
        # Root path to the OCD tool
        self.ocd_root_path = None

        # debug_level [n]
        # Display debug level.
        # If n (from 0..4) is provided, then set it to that level.
        # This affects the kind of messages sent to the server log.
        #   Level 0 is error messages only;
        #   level 1 adds warnings;
        #   level 2 adds informational messages;
        #   level 3 adds debugging messages;
        #   level 4 adds verbose low-level debug messages.
        # The default is level 2.
        # This is an OPTIONAL parameter
        self.debug_level = 2

        # Indicates whether enable the power supply on the debug probe to
        # power the target device.
        # The possible values:
        #    0 – Power supply disabled.
        #    Any other value defines target voltage in millivolts.
        # This is an OPTIONAL parameter
        self.enable_power_supply = 0

        # Enables or disables acquisition of the target device in Test mode.
        # This is OPTIONAL parameter
        self.enable_acquire = OcdAcquire.ENABLE.value

        # Set the serial number of the specific probe to which want to connect
        # This is OPTIONAL parameter
        self.probe_id = None

        # Set the specific debug adapter. Examples: kitprog3, jlink, cmsis-dap
        # This is MANDATORY parameter
        self.probe_interface = OcdProbeInterface.KITPROG3.value

        # Set the speed in kHz for the selected debug adapter.
        # This is OPTIONAL parameter
        self.adapter_speed_khz = 1000

        # Set the transport level. Examples: swd, jtag
        # This is MANDATORY parameter
        self.transport_select = OcdTransport.SWD.value

        # Set the name of the target device. Examples: psoc6, player
        # This is MANDATORY parameter
        self.target_device_name = None

        # Set the limit the size of accessible Flash
        # This is OPTIONAL parameter
        self.flash_restriction_size = None


class OpenocdServer(OcdConfig):
    """
        This is a class which implements OpenOCD server configuration.

        See OpenOCD documentation for details:
        http://openocd.org/doc/pdf/openocd.pdf
    """

    _supported_os_short_names = {
        'Windows': 'win',
        'Linux':   'linux',
        'Darwin':  'osx',
    }

    log_counter = 1

    def __init__(self, target, target_name=None, interface=None, probe_id=None,
                 tool_path=None, power=None, voltage=None, tcp_host_port=None):
        """ Set initial basic configuration params for OpenOCD """
        if interface:
            raise NotImplementedError

        super().__init__()
        self.inited = True
        self.server_proc = None  # TCL RPC server process
        self.openocd_cmd = ''    # command for OpenOCD configuration

        self.custom_config = self._ocd_custom_config(target)
        self.power = power
        self.voltage = voltage
        self.tcp_host_port = tcp_host_port
        if self.custom_config['interface']:
            self.probe_interface = self.custom_config['interface']

        os_name = platform.system()  # current OS type
        # Set OpenOCD execution filename
        if os_name in self._supported_os_short_names:
            self._os_short_name = self._supported_os_short_names[os_name]
        else:
            self.inited = False
            raise ValueError(f'Unsupported OS platform: {os_name}')

        # Set OpenOCD executable filename
        if self._os_short_name == 'win':
            self.openocd_exec_file = 'openocd.exe'
        else:
            self.openocd_exec_file = 'openocd'

        settings = OcdSettings()
        # Get OpenOCD directory path
        if tool_path is None:
            self.ocd_root_path = settings.ocd_path
        else:
            self.ocd_root_path = tool_path
        if not os.path.exists(self.ocd_root_path):
            raise FileNotFoundError(
                f"Unable to find OpenOCD in '{self.ocd_root_path}'")
        # Get OpenOCD target config
        self.target_config = settings.ocd_config

        self.target_device_name = target_name
        self.probe_id = probe_id

        # Update Flash restriction size to be able to program Secure Bootloader
        self.flash_restriction_size = target.memory_map.FLASH_SIZE

        # Only SWD interface supported by now
        self.transport_select = OcdTransport.SWD.value

    @staticmethod
    def _ocd_custom_config(target):
        try:
            variables = target.ocd_config['openocd']['variables']
        except KeyError:
            variables = ''
        try:
            interface = target.ocd_config['openocd']['interface']
        except KeyError:
            interface = ''
        try:
            before_init = target.ocd_config['openocd']['before_init']
        except KeyError:
            before_init = ''
        try:
            after_init = target.ocd_config['openocd']['after_init']
        except KeyError:
            after_init = ''
        return {'variables': variables, 'interface': interface,
                'before_init': before_init, 'after_init': after_init}

    def _prepare_command(self, ap='sysap', acquire=None):
        """
        This command configure the local OpenOCD server.
        :return: None
        """
        openocd_exec_file = os.path.abspath(os.path.join(
            self.ocd_root_path, 'bin', self.openocd_exec_file))
        openocd_scripts_dir = os.path.join(self.ocd_root_path, 'scripts')

        if self.probe_id is None:
            set_probe_id_command = ''
        else:
            set_probe_id_command = f'adapter serial {self.probe_id}'

        self.openocd_cmd = [
            openocd_exec_file,
            '--search',
            openocd_scripts_dir,
        ]

        ap_config = ''
        if ap == 'cm0':
            ap_config = 'set TARGET_AP cm0_ap'
        if ap == 'cm4':
            ap_config = 'set TARGET_AP cm4_ap'

        enable_acquire = 0 if self.power else self.enable_acquire \
            if acquire is None else int(acquire)

        openocd_config_cmd = []
        if self.flash_restriction_size is not None:
            openocd_config_cmd += [f'set FLASH_RESTRICTION_SIZE {self.flash_restriction_size}']

        if self.power:
            volt = '' if self.power == 'off' else self.voltage
            self.custom_config[
                'before_init'] += f'kitprog3 power_config {self.power} {volt}'

        if self.target_config:
            cfg_file, _ = os.path.splitext(self.target_config)
            target_config_name = f'target/{cfg_file}.cfg'
        else:
            target_config_name = f'target/{self.target_device_name}.cfg'

        openocd_config_cmd += [
            f'debug_level {self.debug_level}',
            f'set ENABLE_ACQUIRE {enable_acquire}',
            f'set ENABLE_POWER_SUPPLY {self.enable_power_supply}',
            'set ACQUIRE_TIMEOUT 5000',
            self.custom_config['variables'],
            ap_config,
            'gdb_port disabled',
            'telnet_port disabled',
            f'tcl_port {self.tcp_host_port}',
            f'source [find interface/{self.probe_interface}.cfg]',
            f'{set_probe_id_command}',
            f'transport select {self.transport_select}',
            f'source [find {target_config_name}]',
            f'adapter speed {self.adapter_speed_khz}',
            self.custom_config['before_init'],
            'init',
            self.custom_config['after_init']
        ]

        # Remove empty elements from list
        openocd_config_cmd = list(filter(None, openocd_config_cmd))
        # Insert a command '-c' before each element in list
        openocd_config_cmd = \
            [cmd for elem in openocd_config_cmd for cmd in ('-c', elem)]
        # Format command for Popen
        self.openocd_cmd.extend(openocd_config_cmd)

    def start(self, ap='sysap', acquire=None):
        """
        This command starts the local OpeOCD server.
        :return: True if server successfully started, otherwise False.
        """
        # Maximum time in seconds server should start after OpenOCD start
        server_startup_time = 15
        log_dir = LoggingConfigurator.get_log_dir()
        logfile = f'{log_dir}/openocd_{OpenocdServer.log_counter}.log'
        OpenocdServer.log_counter += 1
        server_started = False

        # Check if OpenOCD server is running now
        if (self.server_proc is not None and self.server_proc.poll() is not None) or self.server_proc is None:
            # Prepare command for Popen function
            self._prepare_command(ap, acquire)
            logger.debug('Execute command: %s', self.openocd_cmd)

            # Register function which will be executed at the end
            # of __main__ execution
            atexit.register(self.stop)

            # Start OpenOCD server and redirect stdout to the file
            Path(log_dir).mkdir(parents=True, exist_ok=True)
            with open(logfile, 'w', encoding='utf-8') as f:
                self.server_proc = subprocess.Popen(self.openocd_cmd, stdout=f,
                                                    stderr=subprocess.STDOUT)

            if self.power:
                time.sleep(1)
                return True

            # Check if server was started correctly
            start_time = time.time()
            previous_output = []
            while time.time() - start_time < server_startup_time:
                time.sleep(0.1)
                output = self._ocd_output(logfile)
                if not output:
                    server_started = False
                    break
                new_output = self._new_ocd_output(output, previous_output)
                previous_output = output

                server_started = self._ocd_start_result(new_output)

                if (self.server_proc.poll() is not None and
                        not server_started) or server_started:
                    break
        else:
            logger.error('OpenOCD server is running now')
        return server_started

    @staticmethod
    def _ocd_output(logfile):
        """Reads OpenOCD output from the logfile"""
        log_file_read_time = 5
        read_time = time.time()
        lines = []
        try:
            with open(logfile, 'r', encoding='utf-8') as log:
                while time.time() - read_time < log_file_read_time:
                    lines = log.readlines()
                    if lines:
                        break
                    time.sleep(0.2)
        except FileNotFoundError:
            logger.error('Server log file not found: %s', logfile)
        return lines

    @staticmethod
    def _new_ocd_output(current_lines, previous_lines):
        """From the OpenOCD output gets lines that are not in
        the previous result
        """
        previous_set = set(previous_lines)
        result = [x for x in current_lines if x not in previous_set]
        return result

    @staticmethod
    def _ocd_start_result(lines):
        """Analyzes OpenOCD output and returns the result of the start"""
        for line in lines:
            logger.info(line.rstrip())
            if 'Listening on port' in line:
                return True
        return False

    def stop(self):
        """This command stops the local OpenOCD server"""
        if self.server_proc is not None:
            timeout_sec = 1
            self.server_proc.kill()
            start_time = time.time()
            while self.server_proc.poll() is None:
                if time.time() - start_time > timeout_sec:
                    break
            self.server_proc = None

    def __del__(self):
        self.stop()
