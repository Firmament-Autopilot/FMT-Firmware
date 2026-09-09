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
import os

from ..tbl_file import TblFile
from .....core.dependecy_validator import DependencyValidator


class LoadVerifySchemeValidator(DependencyValidator):
    """Validates the Load-Verify scheme against image address"""

    def validate(self, **_kwargs):
        """Validates Load-Verify scheme"""
        config_parser = self.parser

        img_table = config_parser.image_table()
        load_verify_scheme = config_parser.load_verify_scheme()

        if img_table is None:
            self.add_msg("'image_table' property must be specified")
            return

        if not os.path.isfile(img_table):
            self.add_msg(f"File not found: '{img_table}'")
            return

        tbl = TblFile(img_table)
        msgs = tbl.validate(load_verify_scheme)

        if msgs:
            self.add_msg(f"TBL file validation failed: {tbl.tbl_path}'")
        for msg in msgs:
            self.add_msg(msg)
