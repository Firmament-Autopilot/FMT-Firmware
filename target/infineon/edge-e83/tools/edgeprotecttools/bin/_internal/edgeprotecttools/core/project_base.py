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
import json
import logging
from collections import namedtuple
from pathlib import Path
from shutil import copyfile
from abc import ABC, abstractmethod

from ..pkg_globals import PkgData
from .enums import Protocol

logger = logging.getLogger(__name__)

OcdData = namedtuple('OcdData', 'name path config')


class ProjectInitializerBase(ABC):
    """ A base class for targets projects initializers """

    metadata_file = f'.{PkgData.pkg_name().lower()}'
    supported_matadata_files = [metadata_file, '.cysecuretools']
    keys_dirname = 'keys'
    policy_dirname = 'policy'
    prebuilt_dirname = 'prebuilt'
    packets_dirname = 'packets'
    apps_dirname = 'apps'

    def __init__(self, target):
        self.target = target
        self.policy_parser = target.policy_parser
        self.target_dir = target.target_dir
        self.policy_src = os.path.join(self.target_dir, self.policy_dirname)
        self.cwd = os.getcwd()
        self.project_file = None

    @abstractmethod
    def init(self, cwd, overwrite):
        """Initializes new project"""

    @staticmethod
    def get_medatada_file(cwd=None):
        """Gets project metadata file path if exists in the cwd
        :param cwd: Current working directory
        :return: The project metadata file path or None
        """
        if not cwd:
            cwd = os.getcwd()
        for filename in ProjectInitializerBase.supported_matadata_files:
            metadata_file = os.path.abspath(os.path.join(cwd, filename))
            if os.path.isfile(metadata_file):
                return metadata_file
        return None

    @staticmethod
    def is_project(cwd=None):
        """Checks whether project metadata file exists in the cwd
        :param cwd: Current working directory
        :return: The value indicating whether project exists in cwd
        """
        return ProjectInitializerBase.get_medatada_file(cwd=cwd) is not None

    def create_config(self, policy):
        """Creates a project config file"""
        ocd_name = self.target.ocds[0]
        ocd_path = ''
        data = {}

        # Get OCD path from global settings if OCD name match
        from ..execute.programmer.programmer import ProgrammingTool
        tool = ProgrammingTool.create(ocd_name)
        if tool.require_path:
            try:
                with open(PkgData.pkg_settings(), encoding='utf-8') as f:
                    global_data = json.load(f)
            except FileNotFoundError as e:
                logger.debug(e)
                global_data = None
            else:
                if ocd_name == global_data['programming_tool']['name']:
                    ocd_path = global_data['programming_tool']['path']

            project_settings_path = os.path.join(PkgData.pkg_data_dir(),
                                                 'project_settings.json')
            with open(project_settings_path, encoding='utf-8') as f:
                data = json.load(f)

        data['user_settings']['target'] = self.target.name
        data['user_settings']['ocd_name'] = ocd_name
        data['user_settings']['ocd_path'] = ocd_path
        data['user_settings']['default_policy'] = policy

        if global_data and 'serial_interface' in global_data:
            data["serial_interface"] = global_data['serial_interface']

        with open(self.metadata_file, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4)
        self.remove_legacy_metadata_files()

    def remove_legacy_metadata_files(self):
        """Removes legacy metadata files"""
        for filename in self.supported_matadata_files:
            if filename != self.metadata_file:
                try:
                    os.remove(filename)
                except OSError:
                    pass

    @staticmethod
    def get_ocd_data(cwd=None):
        """Gets OCD name and path from the project metadata file
        :return: A named tuple OcdData(name, path, config)
        """
        metadata_file = ProjectInitializerBase.get_medatada_file(cwd=cwd)
        with open(metadata_file, encoding='utf-8') as f:
            data = json.load(f)
        try:
            ocd_name = data['user_settings']['ocd_name']
            ocd_path = data['user_settings']['ocd_path']
            ocd_config = data['user_settings'].get('ocd_config')
        except KeyError:
            ocd_name = None
            ocd_path = None
            ocd_config = None

        if ocd_path:
            ocd_path = os.path.abspath(ocd_path)
        return OcdData(ocd_name, ocd_path, ocd_config)

    @staticmethod
    def set_ocd_data(ocd_name, ocd_path, ocd_config=None, cwd=None):
        """Sets OCD name and path to the project metadata file"""
        metadata_file = ProjectInitializerBase.get_medatada_file(cwd=cwd)
        with open(metadata_file, 'r+', encoding='utf-8') as f:
            data = json.load(f)
            try:
                data['user_settings']['ocd_name'] = ocd_name
                data['user_settings']['ocd_path'] = ocd_path
                data['user_settings']['ocd_config'] = ocd_config
            except KeyError as e:
                raise KeyError(f'Invalid project configuration file structure '
                               f'({metadata_file})') from e
            f.seek(0)
            json.dump(data, f, indent=4)
            f.truncate()

    @staticmethod
    def get_serial_config(filename=None, cwd=None):
        """Gets serial interface configuration from the project
        metadata file
        @param filename: A file where to get the serial interface config
        @param cwd: A directory where to look for a project metadata file
        :return: A dictionary
        """
        if filename:
            metadata_file = filename
        else:
            metadata_file = ProjectInitializerBase.get_medatada_file(cwd=cwd)
        with open(metadata_file, encoding='utf-8') as f:
            data = json.load(f)
        return data.get('serial_interface')

    @staticmethod
    def set_serial_config(filename=None, cwd=None, **kwargs):
        """Sets serial interface configuration to the project metadata file
        @param filename: A file where to update serial interface settings
        @param cwd: A directory where to look for a project metadata file
        @param kwargs: Arbitrary keyword arguments.
            protocol - Serial communication protocol (uart, i2c, spi, usb)
            uart_baudrate - The baud rate for the UART protocol
            uart_databits - The number of data bits for the UART protocol
            uart_paritytype - The parity type for the UART protocol
            uart-stopbits - The stop bits for the UART protocol
            i2c_address - The address for the I2C protocol
            i2c_speed - The speed for the I2C protocol in kHz
            spi_clockspeed - The clock speed for the SPI protocol in MHz
            spi_mode - The mode for the SPI protocol in binary
            spi_lsb_first - Indicates whether the least-significant bit
                should be sent first for the SPI protocol
            canfd_bitrate - the communication bitrate for CAN-FD protocol
            canfd_data_bitrate - the data communication bitrate
                for CAN-FD protocol
            canfd_output_frame_id - the output frame ID for CAN-FD protocol
            canfd_input_frame_id - the input frame ID for CAN-FD protocol
            canfd_enable_bitrate_switch - the switching between default and
                data bitrates is enabled for CAN-FD protocol
            canfd_ext_frame - the extended frame support  for CAN-FD protocol
        """
        if filename:
            metadata_file = filename
        else:
            metadata_file = ProjectInitializerBase.get_medatada_file(cwd=cwd)
        with open(metadata_file, 'r+', encoding='utf-8') as f:
            data = json.load(f)
            serial = data.get('serial_interface', {})
            uart = serial.get(Protocol.UART, {})
            i2c = serial.get(Protocol.I2C, {})
            spi = serial.get(Protocol.SPI, {})
            can = serial.get(Protocol.CAN_FD, {})
            protocol = kwargs.get('protocol', '').replace('-', '_').lower()

            if protocol:
                serial['protocol'] = protocol
            if kwargs.get('hwid'):
                serial['hwid'] = kwargs.get('hwid')

            if protocol == Protocol.UART:
                if kwargs.get('uart_baudrate'):
                    uart['baudrate'] = int(kwargs.get('uart_baudrate'))
                if kwargs.get('uart_paritytype'):
                    uart['paritytype'] = kwargs.get(
                        'uart_paritytype'
                    ).capitalize()
                if kwargs.get('uart_stopbits'):
                    uart['stopbits'] = float(kwargs.get('uart_stopbits'))
                if kwargs.get('uart_databits'):
                    uart['databits'] = int(kwargs.get('uart_databits'))
            elif protocol == Protocol.I2C:
                if kwargs.get('i2c_address'):
                    i2c['address'] = int(kwargs.get('i2c_address'))
                if kwargs.get('i2c_speed'):
                    i2c['speed'] = int(kwargs.get('i2c_speed'))
            elif protocol == Protocol.SPI:
                if kwargs.get('spi_clockspeed'):
                    spi['clockspeed'] = float(kwargs.get('spi_clockspeed'))
                if kwargs.get('spi_mode'):
                    spi['mode'] = kwargs.get('spi_mode')
                if kwargs.get('spi_lsb_first'):
                    spi['lsb_first'] = kwargs.get('spi_lsb_first')
            elif protocol == Protocol.CAN_FD:
                if kwargs.get('canfd_bitrate'):
                    can['bitrate'] = int(kwargs.get('canfd_bitrate'))
                if kwargs.get('canfd_data_bitrate'):
                    can['data_bitrate'] = int(kwargs.get('canfd_data_bitrate'))
                if kwargs.get('canfd_output_frame_id'):
                    can['output_frame_id'] = int(kwargs.get(
                        'canfd_output_frame_id'
                    ))
                if kwargs.get('canfd_input_frame_id'):
                    can['input_frame_id'] = int(
                        kwargs.get('canfd_input_frame_id')
                    )
                else:
                    can['input_frame_id'] = None
                if kwargs.get('canfd_enable_bitrate_switch'):
                    can['enable_bitrate_switch'] = kwargs.get(
                        'canfd_enable_bitrate_switch'
                    )
                if kwargs.get('canfd_ext_frame'):
                    can['ext_frame'] = kwargs.get('canfd_ext_frame')

            serial[Protocol.UART] = uart
            serial[Protocol.I2C] = i2c
            serial[Protocol.SPI] = spi
            serial[Protocol.CAN_FD] = can

            data['serial_interface'] = serial
            f.seek(0)
            json.dump(data, f, indent=4)
            f.truncate()

    @staticmethod
    def get_default_policy(cwd=None):
        """Gets default policy path from the project metadata file"""
        metadata_file = ProjectInitializerBase.get_medatada_file(cwd=cwd)
        with open(metadata_file, encoding='utf-8') as f:
            data = json.load(f)
        policy = data['user_settings']['default_policy']
        return None if policy is None else os.path.abspath(policy)

    @staticmethod
    def get_policy_src_files(policy_src):
        """Gets names of the policy files in the source directory"""
        return ProjectInitializerBase._filenames_from_dir(policy_src, ext='json')

    @staticmethod
    def get_existent(dst, files):
        """Gets the list of the project files existent in the cwd
        :param dst: Directory where to search
        :param files: Name of files to search
        :return: List of the existent files
        """
        existent_files = []
        try:
            for entry in os.scandir(dst):
                if entry.name in files:
                    existent_files.append(entry.path)
        except FileNotFoundError:
            pass
        return existent_files

    @staticmethod
    def copy_files(src_dir, dst_dir, file_names, warn=True):
        """Copies files with the names specified in the list from
        source to destination directory
        :param src_dir: The source directory
        :param dst_dir: The destination directory
        :param file_names: List of the file names
        :param warn: Warn if file does not exist
        """
        Path(dst_dir).mkdir(parents=True, exist_ok=True)
        for name in file_names:
            src_file = os.path.join(src_dir, name)
            dst_file = os.path.join(dst_dir, name)
            try:
                Path(os.path.dirname(dst_file)).mkdir(parents=True,
                                                      exist_ok=True)
                copyfile(src_file, dst_file)
                logger.info("Copy '%s'", dst_file)
            except FileNotFoundError:
                if warn:
                    logger.warning("File '%s' does not exist", src_file)

    @staticmethod
    def _filenames_from_dir(dir_path, ext=None):
        """Gets a list of filenames from the specified directory"""
        if ext:
            files = [f for f in os.listdir(dir_path) if f.endswith(f'.{ext}')]
        else:
            files = os.listdir(dir_path)
        return files
