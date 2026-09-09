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
from enum import Enum
from abc import ABCMeta, abstractmethod


class ResetType(Enum):
    """Enumeration for reset types"""
    SW = 1,    "Software reset"
    HW = 2,    "Hardware reset"
    HW_SW = 3, "Hardware and Software reset"
    HW_SR = 4, "Hardware switch reset pin"


class Interface(Enum):
    """Enumeration for communication interfaces"""
    SWD = 1
    JTAG = 2


class AP(Enum):
    """Enumeration for access ports"""
    SYS = 'sys'
    CM0 = 'cm0'
    CM4 = 'cm4'
    CMx = 'cmx'
    CM33 = 'cm33'


class ProgrammerBase(metaclass=ABCMeta):
    """Base class which is necessary to be implemented by the classes
    providing communication with OCD
    """

    def __init__(self, name, path=None, require_path=True):
        self.name = name
        self.tool_path = path
        self.require_path = require_path

    @abstractmethod
    def connect(self, target_name=None, interface=None, probe_id=None, ap=None,
                acquire=True, power=None, voltage=None, rev=None):
        """
        Connects to target.
        @param target_name: The target name.
        @param interface: Debug interface.
        @param probe_id: Probe serial number.
        @param ap: The access port used for communication.
        @param acquire: Indicates whether to acquire device on connect
        @param power: Target power
        @param voltage: Target power voltage
        @param rev: The target revision.
        @return: True if connected successfully, otherwise False
        """

    @abstractmethod
    def disconnect(self):
        """Disconnects from target"""

    @abstractmethod
    def get_ap(self):
        """Gets access port
        @return: Selected AP
        """

    @abstractmethod
    def set_ap(self, ap):
        """Sets access port"""

    @abstractmethod
    def set_frequency(self, value_khz):
        """Sets probe frequency
        @param value_khz: Frequency in kHz
        """

    @abstractmethod
    def halt(self):
        """Halts the core"""

    @abstractmethod
    def resume(self):
        """Resumes the execution"""

    @abstractmethod
    def reset(self, reset_type=ResetType.SW):
        """Resets the target
        @param reset_type: The reset type
        """

    @abstractmethod
    def reset_and_halt(self, reset_type=ResetType.SW):
        """Resets the target and halts the CPU immediately after reset
        @param reset_type: The reset type
        """

    @abstractmethod
    def read8(self, address):
        """Reads 8-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value
        """

    @abstractmethod
    def read16(self, address):
        """Reads 16-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value
        """

    @abstractmethod
    def read32(self, address):
        """Reads 32-bit value from specified memory location
        @param address: The memory address to read
        @return: The read value
        """

    @abstractmethod
    def write8(self, address, value):
        """Writes 8-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 8-bit value to write
        """

    @abstractmethod
    def write16(self, address, value):
        """Writes 16-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 16-bit value to write
        """

    @abstractmethod
    def write32(self, address, value):
        """Writes 32-bit value by specified memory location
        @param address: The memory address to write
        @param value: The 32-bit value to write
        """

    @abstractmethod
    def read_reg(self, reg_name):
        """Gets value of a core register
        @param reg_name: Core register name
        @return: The register value
        """

    @abstractmethod
    def write_reg(self, reg_name, value):
        """Sets value of a core register
        @param reg_name: Core register name
        @param value: The value to set
        """

    @abstractmethod
    def erase(self, address, size):
        """Erases entire device flash or specified sectors
        @param address: The memory location
        @param size: The memory size
        """

    @abstractmethod
    def program(self, filename, file_format=None, address=None, **kwargs):
        """Programs a file into flash.
        @param filename: Path to a file
        @param file_format: File format. Default is to use the file's extension
        @param address: Base address used for the address where to flash a binary
        @return: True if programmed successfully, otherwise False
        """

    @abstractmethod
    def read(self, address, length):
        """Reads a block of unaligned bytes in memory
        @param address: The memory address where start reading
        @param length: Number of bytes to read
        @return: Values array
        """

    @abstractmethod
    def write(self, address, data):
        """Writes a block of unaligned bytes in memory
        @param address: The memory address where start writing
        @param data: Data block
        """

    @abstractmethod
    def get_probe_list(self):
        """Gets list of connected probes"""

    def examine_ap(self):
        """Examines CMx (depending on selected ap for connection) AP
        without reset. This is applicable for OpenOCD and likely should
        not be implemented for other tools
        """

    @abstractmethod
    def get_voltage(self):
        """Reads target voltage
        @return Voltage value in Volts
        """

    @abstractmethod
    def dump_image(self, filename, addr, size, **kwargs):
        """Dumps memory region to the file
        @param filename: Filename where to save the dump
        @param addr: Region address
        @param size: Region size
        """

    def verify(self, filename):
        """Image verification in the device memory
        @param filename: Image file path
        @return: True if verification success, otherwise False
        """
