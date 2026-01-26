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

from cbor import cbor

from .dlm_policy import DLMPolicy
from ....execute.image_signing.image import Image

logger = logging.getLogger(__name__)


class DLMPackage:
    """Extracts configuration data from the DLM packet"""

    def __init__(self, dlm):
        self.dlm = dlm
        self.image = Image(self.dlm)
        self.image_app = Image(self.image.body)
        self.in_params = self.load_in_params(self.image_app.trailer)
        self.prov_packet = DLMPolicy(self.in_params) if self.in_params else None

    @staticmethod
    def load_in_params(in_params):
        """Creates dictionary from the CBOR in_params"""
        data_len = int.from_bytes(in_params[:4], 'little')
        if data_len == len(in_params[4:]):
            return cbor.loads(in_params[4:])
        return None
