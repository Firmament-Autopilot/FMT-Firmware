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
import json

from ..pkg_globals import PkgData
from ..core.project_base import ProjectInitializerBase


class OcdSettings:
    """A class for accessing On-Chip debugger configuration"""

    def __init__(self):
        with open(PkgData.pkg_settings(), encoding='utf-8') as f:
            file_content = f.read()
        try:
            self.json_data = json.loads(file_content)
        except json.decoder.JSONDecodeError as e:
            raise json.decoder.JSONDecodeError(
                f"Failed to parse settings file '{PkgData.pkg_settings()}': "
                f"{e.args[0]}'", e.doc, e.pos) from e

    @property
    def ocd_name(self):
        """Gets a name of the On-Chip debugger"""
        ocd_name = None
        if ProjectInitializerBase.is_project():
            ocd_name = ProjectInitializerBase.get_ocd_data().name
        if ocd_name is None:
            try:
                ocd_name = self.json_data['programming_tool']['name']
            except KeyError as e:
                raise KeyError(f'Invalid settings file structure '
                               f'({PkgData.pkg_settings()})') from e
        return ocd_name

    @property
    def ocd_path(self):
        """Gets a path to the On-Chip debugger"""
        ocd_path = None
        if ProjectInitializerBase.is_project():
            ocd_path = ProjectInitializerBase.get_ocd_data().path
        if ocd_path is None:
            try:
                ocd_path = self.json_data['programming_tool']['path']
            except KeyError as e:
                raise KeyError(f'Invalid settings file structure '
                               f'({PkgData.pkg_settings()})') from e
        return ocd_path

    @property
    def ocd_config(self):
        """Gets openocd target config"""
        ocd_config = None
        if ProjectInitializerBase.is_project():
            ocd_config = ProjectInitializerBase.get_ocd_data().config
        if ocd_config is None:
            ocd_prog_tool = self.json_data.get('programming_tool')
            ocd_config = ocd_prog_tool.get('config') if ocd_prog_tool else None
        return ocd_config

    @staticmethod
    def serial_config():
        """Gets serial interface configuration"""
        if ProjectInitializerBase.is_project():
            config = ProjectInitializerBase.get_serial_config()
        else:
            config = ProjectInitializerBase.get_serial_config(
                PkgData.pkg_settings())
        return config
