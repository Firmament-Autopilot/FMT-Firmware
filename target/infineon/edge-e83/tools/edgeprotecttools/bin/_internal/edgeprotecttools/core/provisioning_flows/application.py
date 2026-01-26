"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import os
import json


class Application:
    """
    Implements RAM application data for silicons
    """

    def __init__(self, app, app_dir=None):
        """
        Creates instance of the application
        @param app: Either application name or application
            configuration file. If the application name is specified,
            the application config will be found in the apps directory,
            otherwise the specified file will be used
        @param app_dir: Application directory. Not needed if a config
            file is specified
        """
        if os.path.isfile(app):
            self.config = app
        else:
            if app_dir is None:
                raise ValueError('Application directory not specified')
            self.config = os.path.join(app_dir, app, 'config.json')
        self.app_dir = os.path.abspath(os.path.dirname(self.config))
        self.config_data = self._get_json(self.config)

        self._name = app
        self._image_path = self._get_image_path()
        self._image_address = self._get_image_address()
        self._in_params_path = self._get_in_params_path()
        self._in_params_address = self._get_in_params_address()
        self._in_params_optional = self._get_in_params_optional()
        self._out_results_path = self._get_out_results_path()
        self._out_results_offset = self._get_out_results_offset()
        self._out_results_size = self._get_out_results_size()
        self._allowed_lcs = self._get_allowed_lcs()
        self._dfu_commands_path = self._get_dfu_commands_path()
        self._dlm_path = self._get_dlm_path()

    @property
    def name(self):
        """ Application name """
        return self._name

    @property
    def image_path(self):
        """ Application image path """
        return self._image_path

    @property
    def image_address(self):
        """ Address where to program the application """
        return self._image_address

    @property
    def in_params_path(self):
        """ Application input parameters path """
        return self._in_params_path

    @property
    def in_params_address(self):
        """ Address where to program the input parameters """
        return self._in_params_address

    @property
    def in_params_optional(self):
        """ Indicates whether the input parameters are optional """
        return self._in_params_optional

    @property
    def allowed_lcs(self):
        """
        A list of device lifecycles allowed to program the application
        """
        return self._allowed_lcs

    @property
    def dfu_commands_path(self):
        """ A path to the file containing DFU commands """
        return self._dfu_commands_path

    @property
    def out_results_path(self):
        """ A path to the file to save output results """
        return self._out_results_path

    @out_results_path.setter
    def out_results_path(self, value):
        self._out_results_path = value

    @property
    def out_results_offset(self):
        """ Address offset for app out results """
        return self._out_results_offset

    @property
    def out_results_size(self):
        """ Application response size """
        return self._out_results_size

    @property
    def dlm_path(self):
        """ A path to the DLM package """
        return self._dlm_path

    @dlm_path.setter
    def dlm_path(self, value):
        self._dlm_path = value

    def _get_image_data(self):
        image_data = self.config_data.get('image')
        if image_data is None:
            raise KeyError(f"'image' field not found in '{self.config}'")
        return image_data

    def _get_image_path(self):
        image_data = self._get_image_data()
        image_path = image_data.get('path')
        if image_path is None:
            raise KeyError(f"Image 'path' not found in '{self.config}'")

        try:
            if not os.path.isabs(image_path):
                image_path = os.path.abspath(
                    os.path.join(os.path.dirname(self.config), image_path))
        except ValueError as e:
            raise ValueError(f'{e} ({self.config})') from e
        return image_path

    def _get_image_address(self):
        image_data = self._get_image_data()
        image_address = image_data.get('address')
        return int(str(image_address), 0) if image_address else None

    def _get_in_params_path(self):
        in_params = self.config_data.get('in_params')
        if in_params is None:
            in_params_path = None
        else:
            in_params_path = in_params.get('path')
            if in_params_path is None:
                raise KeyError(
                    f"Input parameters 'path' not found in '{self.config}'")
            try:
                if isinstance(in_params_path, list):
                    for i, item in enumerate(in_params_path):
                        if not os.path.isabs(item):
                            in_params_path[i] = os.path.abspath(os.path.join(
                                os.path.dirname(self.config), item))
                else:
                    if not os.path.isabs(in_params_path):
                        in_params_path = os.path.abspath(os.path.join(
                            os.path.dirname(self.config), in_params_path))
            except ValueError as e:
                raise ValueError(f'{e} ({self.config})') from e
        return in_params_path

    def _get_in_params_address(self):
        in_params = self.config_data.get('in_params')
        if in_params:
            in_params_addr = in_params.get('address')
            if in_params_addr:
                return int(str(in_params_addr), 0)
        return None

    def _get_in_params_optional(self):
        in_params = self.config_data.get('in_params')
        return in_params.get('optional', False) if in_params else False

    def _get_out_results_path(self):
        out_results = self.config_data.get('out_results')
        out_results_path = out_results.get('path') if out_results else None
        if out_results_path:
            if not os.path.isabs(out_results_path):
                out_results_path = os.path.abspath(os.path.join(
                    os.path.dirname(self.config), out_results_path))
        return out_results_path

    def _get_out_results_offset(self):
        out_results = self.config_data.get('out_results')
        if out_results:
            out_offset = out_results.get('offset')
            return int(str(out_offset), 0) if out_offset else 0
        return None

    def _get_out_results_size(self):
        results = self.config_data.get('out_results')
        if results:
            size = results.get('size')
            return int(str(size), 0) if size else None
        return None

    def _get_dlm_path(self):
        out_results = self.config_data.get('dlm')
        out_results_path = out_results.get('path') if out_results else None
        if out_results_path:
            if not os.path.isabs(out_results_path):
                out_results_path = os.path.abspath(os.path.join(
                    os.path.dirname(self.config), out_results_path))
        return out_results_path

    def _get_allowed_lcs(self):
        return self.config_data.get('allowed_lcs')

    def _get_dfu_commands_path(self):

        dfu_cmd_path = self.config_data.get('dfu_commands')
        if dfu_cmd_path:
            dfu_cmd_path = dfu_cmd_path.get('path')
            if not os.path.isabs(dfu_cmd_path):
                dfu_cmd_path = os.path.abspath(
                    os.path.join(self.app_dir, dfu_cmd_path))
        return dfu_cmd_path

    @staticmethod
    def _get_json(filename):
        """
        Opens JSON file with the provisioning flows description as
        a dictionary
        """
        with open(filename, encoding='utf-8') as f:
            file_content = f.read()
            data = json.loads(file_content)
        return data
