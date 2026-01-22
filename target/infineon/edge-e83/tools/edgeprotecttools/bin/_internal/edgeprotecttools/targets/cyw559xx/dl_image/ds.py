"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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
from intelhex import IntelHex


class DS:
    """Data structure for Dynamic Section"""
    def __init__(self, data: IntelHex):
        self._data = data

    @property
    def header(self):
        """Gets the DS header"""
        return DsHeader(self._data, self.address)

    @property
    def address(self) -> int:
        """Gets the DS address"""
        ds_segment = self._data.segments()[2]
        return ds_segment[0]

    @property
    def size(self) -> int:
        """Gets the DS size"""
        ds_segment = self._data.segments()[2]
        return ds_segment[1] - ds_segment[0]

    @property
    def data(self) -> IntelHex:
        """Gets the Dynamic Section data"""
        return self._data[self.address:self.address + self.size]

    @property
    def ds_bytes(self) -> bytes:
        """Gets the Dynamic Section bytes"""
        return bytes(self.data.tobinarray())

    @property
    def padding(self):
        """Gets the Dynamic Section padding bytes"""
        return bytes(self.cert_address - (self.address + self.size))

    @property
    def cert_address(self) -> int:
        """Gets the certificates start address"""
        cert_data = self._data[self.address + self.size:]
        address = min(cert_data.addresses(), default=None)
        return address

class DsHeader:
    """Data structure for Dynamic Section Header"""
    def __repr__(self):
        return f"DsHeader(ds_size={hex(self.ds_size)})"

    def __init__(self, data, ds_address):
        self.data = data
        self.ds_address = ds_address

    @property
    def magic(self) -> int:
        """Gets the DS magic"""
        magic = self.data.gets(self.ds_address + 0, 8)
        return int.from_bytes(magic, 'little')

    @property
    def crc(self) -> int:
        """Gets the DS CRC"""
        crc = self.data.gets(self.ds_address + 8, 4)
        return int.from_bytes(crc, 'little')

    @property
    def ds_size(self) -> int:
        """Gets the DS length"""
        length = self.data.gets(self.ds_address + 12, 4)
        return int.from_bytes(length, 'little')

    @ds_size.setter
    def ds_size(self, value):
        """Sets the DS length"""
        self.data[self.ds_address + 12:self.ds_address + 16] = list(
            value.to_bytes(4, 'little'))
