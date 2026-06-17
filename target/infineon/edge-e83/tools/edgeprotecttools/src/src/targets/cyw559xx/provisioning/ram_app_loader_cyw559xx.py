"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import logging

from .chip_loader import ChipLoad
from ....core.ram_app_loader_base import RamAppLoader

logger = logging.getLogger(__name__)


class RamAppLoaderCYW559xx(RamAppLoader):
    """ A class that implements loading RAM application routine """

    def __init__(self):
        self.tool = None
        self.target = None
        self.app = None

    def load(self, tool, target, app):
        """ Loads application into RAM """
        self.tool = tool
        self.target = target
        self.app = app
        loader = ChipLoad(self.tool, self.target, self.app)
        return loader.load()

    def reset(self):
        """ Not implemented """
