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
from abc import ABC, abstractmethod


class ProvisioningPacketStrategy(ABC):
    """The Strategy interface declares operations common to all
    supported versions of some algorithm
    """

    @abstractmethod
    def create(self, target, **kwargs):
        """Creates provisioning packet"""

    @abstractmethod
    def verify(self, target, **kwargs):
        """Verifies packet signature"""

    @abstractmethod
    def create_package(self, target, **kwargs):
        """Creates provisioning package"""

    @abstractmethod
    def reverse_conversion(self, target, packets, output):
        """Converts provisioning packet back to policy"""


class ProvisioningPacketCtx:
    """The Context defines the interface of interest to clients"""
    def __init__(self, strategy: ProvisioningPacketStrategy):
        self._strategy = strategy

    @property
    def strategy(self) -> ProvisioningPacketStrategy:
        """The Context maintains a reference to one of the Strategy
        objects
        """
        return self._strategy

    @strategy.setter
    def strategy(self, strategy: ProvisioningPacketStrategy):
        """Allows replacing a Strategy object at runtime"""
        self._strategy = strategy

    def create(self, target, **kwargs):
        """Delegates work to the Strategy object"""
        return self._strategy.create(target, **kwargs)

    def verify(self, target, **kwargs):
        """Delegates work to the Strategy object"""
        return self._strategy.verify(target, **kwargs)

    def create_package(self, target, **kwargs):
        """Delegates work to the Strategy object"""
        return self._strategy.create_package(target, **kwargs)

    def reverse_conversion(self, target, packets, output):
        """Delegates work to the Strategy object"""
        return self._strategy.reverse_conversion(target, packets, output)
