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


class EncryptedProgrammingStrategy(ABC):
    """
    The Strategy interface declares operations common to all
    supported versions of some algorithm.
    """
    @abstractmethod
    def create_header(self, host_key, dev_pub_key, key_to_encrypt, key_length):
        pass

    @abstractmethod
    def create_encrypted_image(self, hex_file, aes_key_file, aes_header,
                               host_key_id, dev_key_id, out_file_encrypt,
                               padding_value):
        pass

    @abstractmethod
    def program(self, tool, target, encrypted_image):
        pass


class EncryptedProgrammingContext:
    """
    The Context defines the interface of interest to clients.
    """
    def __init__(self, strategy: EncryptedProgrammingStrategy):
        self._strategy = strategy

    @property
    def strategy(self) -> EncryptedProgrammingStrategy:
        """
        The Context maintains a reference to one of the Strategy objects.
        """
        return self._strategy

    @strategy.setter
    def strategy(self, strategy: EncryptedProgrammingStrategy):
        """
        Allows replacing a Strategy object at runtime.
        """
        self._strategy = strategy

    def create_header(self, host_key, dev_pub_key, key_to_encrypt, key_length):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.create_header(
            self, host_key, dev_pub_key, key_to_encrypt, key_length)

    def create_encrypted_image(self, hex_file, aes_key_file, aes_header,
                               host_key_id, dev_key_id, out_file_encrypt,
                               padding_value):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.create_encrypted_image(
            self, hex_file, aes_key_file, aes_header, host_key_id, dev_key_id,
            out_file_encrypt, padding_value)

    def program(self, tool, target, encrypted_image):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.program(self, tool, target, encrypted_image)
