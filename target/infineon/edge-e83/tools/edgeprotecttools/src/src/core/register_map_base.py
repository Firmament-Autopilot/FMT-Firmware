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


class RegisterMapBaseP64(abc.ABC):
    """
    Base class for register map representation. Each P64 device register
    map must implement its methods.
    """

    #
    #  Entrance exam registers and constants
    #

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_FW_STATUS_REG(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_FW_STATUS_VAL(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_FW_STATUS_RE_VAL(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_FW_STATUS_MASK(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_SRAM_ADDR(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_SRAM_SIZE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_REGION_HASH_ADDR(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_REGION_HASH_SIZE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_REGION_HASH_MODE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def ENTRANCE_EXAM_REGION_HASH_EXPECTED_VAL(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def FB_FW_STATUS_FIRMWARE_RUNNING_CM4(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def FB_FW_STATUS_FIRMWARE_RUNNING_CM0(self):
        raise NotImplementedError

    #
    # LVD registers
    #

    @property
    @abc.abstractmethod
    def PWR_LVD_CTL(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def PWR_LVD_STATUS(self):
        raise NotImplementedError

    #
    # PSoC 6 BLE register addresses
    #

    @property
    @abc.abstractmethod
    def CYREG_IPC2_STRUCT_ACQUIRE(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def CYREG_IPC2_STRUCT_NOTIFY(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def CYREG_IPC2_STRUCT_DATA(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def CYREG_IPC2_STRUCT_LOCK_STATUS(self):
        raise NotImplementedError

    @property
    @abc.abstractmethod
    def CYREG_EFUSE_SECURE_HASH(self):
        raise NotImplementedError


class RegisterMapBaseMXS40Sv2(abc.ABC):
    """
    Base class for register map representation. Each MXS40Sv2 device
    register map must implement its methods.
    """
