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

from ....core.provisioning_flows.application import Application
from ....execute.image_signing.image import Image

logger = logging.getLogger(__name__)


class DLMPackage:
    """Extracts configuration data from the DLM packet"""

    def __init__(self, dlm, app: Application):
        self.dlm = dlm
        self.image = Image(self.dlm)
        self.image_app = Image(self.image.body)
        self.in_params = self.load_in_params(app)
        self.prov_packet = None

    def load_in_params(self, app):
        """Loads the input parameters from the DLM packet"""
        if app.in_params_address:
            return self.dlm[app.in_params_address - app.image_address:]
        return None
