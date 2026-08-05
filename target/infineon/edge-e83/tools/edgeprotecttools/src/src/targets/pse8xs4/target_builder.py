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
from .project_init_pse8xs4 import ProjectInitPse8xs4
from ..pse8xs2 import PSE8xS2Builder


class PSE8xS4Builder(PSE8xS2Builder):
    """ PSoC Edge E8x S4 target builder """

    def get_project_initializer(self):
        return ProjectInitPse8xs4
