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
from array import array
from typing import Union

from intelhex import IntelHex


class MDH:
    """Data structure for Meta Data Header"""
    def __init__(self, data: IntelHex):
        self.data = data
        self.sub_ds_sec_fw = SubDsInfo(data, 0)
        self.sub_ds_fw = SubDsInfo(data, 12)
        self.sub_ds_app = SubDsInfo(data, 24)

    @property
    def mdh_bytes(self) -> bytes:
        """Gets the MDH bytes"""
        if self.sub_ds_app.encrypted:
            return bytes(self.data[0:64].tobinarray())
        return bytes(self.data[0:48].tobinarray())

    @property
    def iv(self) -> Union[bytes, None]:
        """Gets the IV bytes"""
        iv_bytes = bytes(self.data[36:52].tobinarray())
        return bytes(iv_bytes) if self.sub_ds_app.encrypted else None

    @iv.setter
    def iv(self, value: bytes):
        """Add IV to MDH"""
        padding = b'\x00' * 12
        self.data.puts(36, value + padding)

    @property
    def padding(self) -> bytes:
        """Gets the padding bytes"""
        if self.sub_ds_app.encrypted:
            return bytes(self.data[52:64].tobinarray())
        return bytes(self.data[36:48].tobinarray())

class SubDsInfo:
    """Data structure for sub Dynamic Section"""
    def __repr__(self):
        return (f"SubDsInfo(address={hex(self.address)}, "
                f"size={hex(self.size)}, encrypted={self.encrypted})")

    def __init__(self, data, start):
        self.data = data
        self.start = start

    @property
    def address(self) -> int:
        """Gets the sub DS address"""
        address_bytes = self.data.gets(self.start, 4)
        return int.from_bytes(address_bytes, 'little')

    @address.setter
    def address(self, value):
        """Sets the sub DS address"""
        self.data[self.start:self.start + 4] = list(value.to_bytes(4, 'little'))

    @property
    def size(self) -> int:
        """Gets the sub DS length"""
        size_bytes = self.data.gets(self.start + 4, 4)
        return int.from_bytes(size_bytes, 'little')

    @size.setter
    def size(self, value):
        """Sets the sub DS length"""
        self.data[self.start + 4:self.start + 8] = list(
            value.to_bytes(4, 'little'))

    @property
    def encrypted(self) -> bool:
        """Gets the sub DS encryption flag"""
        flags_bytes = self.data[self.start + 8:self.start + 12].tobinarray()
        return flags_bytes == array('B', [1, 0, 1, 0])

    @encrypted.setter
    def encrypted(self, value):
        """Sets the sub DS encryption flag"""
        enc_bytes = b'\x01\x00\x01\x00' if value else b'\x00' * 4
        self.data[self.start + 8:self.start + 12] = list(enc_bytes)
