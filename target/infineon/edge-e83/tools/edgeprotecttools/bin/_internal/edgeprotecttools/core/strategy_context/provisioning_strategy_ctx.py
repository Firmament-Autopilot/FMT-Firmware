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


class ProvisioningStrategy(ABC):
    """
    The Strategy interface declares operations common to all supported
    versions of some algorithm.
    """
    @abstractmethod
    def provision(self, tool, target, bootloader, **kwargs):
        pass

    @abstractmethod
    def re_provision(self, tool, target, bootloader, **kwargs):
        pass

    @abstractmethod
    def erase_flash(self, tool, target):
        pass

    @abstractmethod
    def transit_to_rma(self, tool, target, cert, **kwargs):
        pass

    @abstractmethod
    def open_rma(self, tool, target, cert):
        pass


class ProvisioningContext:
    """
    The Context defines the interface of interest to clients.
    """
    def __init__(self, strategy: ProvisioningStrategy):
        self._strategy = strategy

    @property
    def strategy(self) -> ProvisioningStrategy:
        """
        The Context maintains a reference to one of the Strategy
        objects.
        """
        return self._strategy

    @strategy.setter
    def strategy(self, strategy: ProvisioningStrategy):
        """
        Allows replacing a Strategy object at runtime.
        """
        self._strategy = strategy

    def provision(self, tool, target, bootloader=None, **kwargs):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.provision(tool, target, bootloader=bootloader,
                                        **kwargs)

    def re_provision(self, tool, target, bootloader=None, **kwargs):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.re_provision(tool, target, bootloader=bootloader,
                                           **kwargs)

    def erase_flash(self, tool, target):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.erase_flash(tool, target)

    def transit_to_rma(self, tool, target, cert, **kwargs):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.transit_to_rma(tool, target, cert, **kwargs)

    def open_rma(self, tool, target, cert):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.open_rma(tool, target, cert)
