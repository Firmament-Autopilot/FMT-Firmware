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
from packaging import version


class TokenVersionVerifierMXS40Sv2:
    """Token template version verification"""

    def __init__(self, parser):
        self.parser = parser

    def verify(self):
        """Runs token template version verification"""

        ver_min = version.parse('1.0.0.0')
        ver_max = version.parse('2.0.0.0')
        section = "Token section 'version'"
        msg = None

        try:
            token_version = self.parser.get_version()
        except KeyError as e:
            msg = f"{section}: invalid structure, missing {e} field"
        else:
            try:
                if version.parse(token_version) < ver_min or version.parse(
                        token_version) >= ver_max:
                    msg = f"Incompatible token version. " \
                          f"Must be greater than {ver_min.__str__()} " \
                          f"and less then {ver_max.__str__()}"
            except TypeError:
                msg = f"{section}: invalid 'version' value"

        return msg is None, msg
