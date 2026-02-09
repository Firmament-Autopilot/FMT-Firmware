"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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


class DependencyValidator(ABC):
    """ Base class for the classes that do dependency validation """

    class Message:
        def __init__(self, msg, severity):
            self.severity = severity
            self.message = msg

    def __init__(self, parser):
        self.parser = parser
        self.messages = list()

    @property
    def is_valid(self):
        return not any(m.severity == 'error' for m in self.messages)

    @abstractmethod
    def validate(self, **kwargs): pass

    def add_msg(self, msg, severity='error'):
        message = self.Message(msg, severity)
        self.messages.append(message)
