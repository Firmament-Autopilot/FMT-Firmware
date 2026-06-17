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
import json
import struct
from enum import IntEnum
from abc import ABC, abstractmethod

from ...core.bitops import number_size


class DfuCommands(IntEnum):
    """DFU commands IDs"""
    READ = 0x51
    RUN_OEM_APP = 0x50
    PROVISION_OEM_APP = 0x52


class DfuMetaData:
    """DFU meta data"""
    FILE_VERSION = 1
    PRODUCT_ID = '01020304'
    APPLICATION_ID = 1
    PACKET_CHECKSUM_TYPE = 0


class DfuhtCommandBase(ABC):
    """An abstract class necessary for implementation by the
    classes that implement parts of DFU Host Tool JSON packet
    """

    @abstractmethod
    def dict(self):
        """Dictionary representation of the command"""


class DfuhtMeta(DfuhtCommandBase):
    """Representation for DFU Host Tool packet metadata, required
    to start DFU communication
    """

    def __init__(self):
        self.file_version = DfuMetaData.FILE_VERSION
        self.product_id = DfuMetaData.PRODUCT_ID
        self.application_id = DfuMetaData.APPLICATION_ID
        self.packet_checksum_type = DfuMetaData.PACKET_CHECKSUM_TYPE

    def dict(self):
        """Representation of meta section for DFU Host Tool commands"""
        return {
            'File Version': hex(self.file_version),
            'Product Id': self.product_id,
            'Application Id': hex(self.application_id),
            'Packet Checksum Type': hex(self.packet_checksum_type)
        }


class DfuhtRunCommand(DfuhtCommandBase):
    """Representation of the DFU Host Tool command for running OEM app"""
    def __init__(self):
        self.cmd_id = DfuCommands.RUN_OEM_APP

    def dict(self):
        """Dictionary representation of the command"""
        return {
            'cmdId': hex(self.cmd_id)
        }


class DfuhtProvisionCommand(DfuhtCommandBase):
    """Representation of the DFU Host Tool command for provisioning OEM app"""
    def __init__(self, hex_addr):
        self.cmd_id = DfuCommands.PROVISION_OEM_APP
        self.hex_addr = hex_addr

    def dict(self):
        """Dictionary representation of the command"""
        return {
            'cmdId': hex(self.cmd_id),
            'dataLength': hex(number_size(self.hex_addr)),
            'dataBytes': f"0x{struct.pack('<L', self.hex_addr).hex()}"
        }


class DfuhtReadCommand(DfuhtCommandBase):
    """Representation of the DFU Host Tool command for read command"""
    def __init__(self, addr, size):
        self.cmd_id = DfuCommands.READ
        self.hex_addr = addr
        self.size = size

    def dict(self):
        """Dictionary representation of the command"""
        return {
            'cmdId': hex(self.cmd_id),
            'dataLength': hex(number_size(self.hex_addr) + 2),
            'dataBytes': f"0x{struct.pack('<LH', self.hex_addr, self.size).hex()}",
            'outCli': 'True'
        }

    def __repr__(self):
        return f'{type(self).__name__}(addr={hex(self.hex_addr)}, size={self.size})'


class DfuhtReadSeriesCommand(DfuhtCommandBase):
    """Representation of the DFU Host Tool command for read command"""
    def __init__(self, *read_commands):
        self.cmd_id = None
        self.commands = [read_command for read_command in read_commands]

    def dict(self):
        """Dictionary representation of the command"""
        return {"commandSet": [cmd.dict() for cmd in self.commands]}

    def __add__(self, other):
        return DfuhtReadSeriesCommand(*(self.commands + other.commands))

    def __repr__(self):
        return (
            f'{type(self).__name__}'
            f'(commands=[{", ".join(list(map(repr, self.commands)))}])'
        )


class DfuhtCustomCommand(DfuhtCommandBase):
    """Representation of DFU Host Tool custom command"""

    def __init__(self, cmd: DfuCommands, data=b''):
        self.cmd_id = cmd.value if isinstance(cmd, DfuCommands) else cmd
        self.data = data
        self.length = self._data_length()
        self.repeat = 1
        self.rsp = b'\x00'

    def __repr__(self):
        return f'{type(self).__name__}(cmd_id={self.cmd_id})'

    def dict(self):
        """Dictionary representation of the command"""
        return {
            'cmdId': hex(self.cmd_id),
            'dataLength': hex(self._data_length()),
            'dataBytes': self._data_bytes(),
            'rsp': self._rsp()
        }

    def _data_length(self):
        if isinstance(self.data, bytes):
            return len(self.data)
        if isinstance(self.data, int):
            return number_size(self.data)
        raise TypeError(f'must be int or bytes, not {type(self.data).__name__}')

    def _data_bytes(self):
        if isinstance(self.data, bytes):
            return [hex(x) for x in self.data]
        if isinstance(self.data, int):
            return hex(self.data)
        raise TypeError(f'must be int or bytes, not {type(self.data).__name__}')

    def _rsp(self):
        if isinstance(self.rsp, DfuhtCustomCommandRsp):
            return self.rsp.dict()
        if isinstance(self.rsp, bytes):
            return hex(int.from_bytes(self.rsp, byteorder="big"))
        raise TypeError(f'must be bytes or {DfuhtCustomCommandRsp.__name__}, '
                        f'not {type(self.data).__name__}')


class DfuhtCustomCommandRsp(DfuhtCommandBase):
    """Representation of DFU Host Tool custom command extended response"""

    def __init__(self, status_code, response=b'', checksum=0):
        self.status_code = status_code
        self.response = response
        self.length = self._rsp_length()
        self.checksum = checksum

    def dict(self):
        """Dictionary representation of the custom command response"""
        return {
            'statusCode': hex(self.status_code),
            'responseLength': hex(self._rsp_length()),
            'response': self._response(),
            'checksum': hex(self.checksum)
        }

    def _rsp_length(self):
        if isinstance(self.response, bytes):
            return len(self.response)
        if isinstance(self.response, int):
            return number_size(self.response)
        raise TypeError(
            f'must be int or bytes, not {type(self.response).__name__}')

    def _response(self):
        if isinstance(self.response, bytes):
            return [hex(x) for x in self.response]
        if isinstance(self.response, int):
            return hex(self.response)
        raise TypeError(
            f'must be int or bytes, not {type(self.response).__name__}')


class DfuhtPacket:
    """Representation of DFU Host Tool JSON packet"""

    def __init__(self, meta, command, filename, **kwargs):
        self.image = kwargs.get('image')
        self.min_addr = kwargs.get('min_addr')
        self.meta = meta
        self.command = command
        self.filename = filename
        self.dict = {
            'APPInfo': self.meta.dict(),
            'commands': [cmd.dict() for cmd in self.command]
        }

    def dump(self):
        """Serializes a packet as a JSON formatted file"""
        with open(self.filename, 'w', encoding='utf-8') as f:
            json.dump(self.dict, f, indent=2)
