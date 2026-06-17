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


class EntranceExamRegion:
    """Entity for handling Entrance Exam regions"""
    def __init__(self, **kwargs):
        self._description = kwargs.get('description')
        self._address = kwargs.get('address')
        self._size = kwargs.get('size')
        self._label = kwargs.get('label')
        self._operation = kwargs.get('operation')
        self._owner = kwargs.get('owner')
        self._content = kwargs.get('content')

        if bool(self._address) ^ bool(self._size):
            raise ValueError('Address and size are interdependent')

        if self._address and self._size:
            self._address = list(map(lambda x: int(str(x), 0), self._address))
            self._size = list(map(lambda x: int(str(x), 0), self._size))
            if len(self._address) != len(self._size):
                raise ValueError('Corrupt region data')

        if self._content and isinstance(self._content, bytes):
            self._content = self._content.hex().upper()

    @property
    def description(self):
        return self._description

    @property
    def address(self):
        return self._address

    @property
    def size(self):
        return self._size

    @property
    def label(self):
        return self._label

    @property
    def operation(self):
        return self._operation

    @property
    def owner(self):
        return self._owner

    @property
    def content(self):
        return self._content

    def __eq__(self, other):
        return self.address == other.address and self.size == other.size

    def __repr__(self):
        props = {p: getattr(self, p) for p in dir(type(self))
                 if isinstance(getattr(type(self), p), property)}
        return (f"{type(self).__name__}"
                f"({', '.join([f'{k}={repr(v)}' for k, v in props.items()])})")


class EntranceExam(ABC):
    @abstractmethod
    def __init__(self, target, **kwargs):
        pass

    @abstractmethod
    def execute(self, tool, **kwargs):
        pass
