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
import abc


class MemoryMapBaseP64(abc.ABC):
    """
    Base class for memory map representation. Each device memory map must
    implement its methods.
    """
    @property
    @abc.abstractmethod
    def FLASH_ADDRESS(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def FLASH_SIZE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def RAM_ADDR(self):
        """RAM address"""

    @property
    @abc.abstractmethod
    def SRAM_ADDR(self):
        """SRAM address"""

    @property
    @abc.abstractmethod
    def SRAM_SIZE(self):
        """SRAM size"""

    @property
    @abc.abstractmethod
    def PROVISION_JWT_PACKET_ADDRESS(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def PROVISION_JWT_PACKET_SIZE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def SPE_IMAGE_ID(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def NSPE_IMAGE_ID(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def EXTERNAL_MEM_START(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def VECTOR_TABLE_ADDR_ALIGNMENT(self):
        raise NotImplementedError


class MemoryMapBaseCYW20829(abc.ABC):
    """
    Base class for memory map representation. Each device memory map must
    implement its methods.
    """
    @property
    @abc.abstractmethod
    def VECTOR_TABLE_ADDR_ALIGNMENT(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def MAX_SLOT_SIZE(self):
        raise NotImplementedError
