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
from .....core.status_codes_base import StatusCodesBase


class ExtendedBootMode(StatusCodesBase):
    """Extended boot mode codes for MXS22 platform"""

    def status_codes(self):
        """Gets a dictionary containing extended boot mode codes
        for the MXS22 platform
        """
        return {
            0xA0000002: {
                "status": "ALT_SERIAL_MODE",
                "desc": "Alternate serial mode is executed"
            },
            0xA0000003: {
                "status": "NEXT_APP_CONTROL_PASSED",
                "desc": "Control has been passed to the next application"
            },
            0xAA000000: {
                "status": "MAIN_FLOW_EXECUTED",
                "desc": "Main flow is executed"
            },
            0xAA000001: {
                "status": "RECOVERY_MODE",
                "desc": "Recovery mode is executed"
            },
            0xAA000002: {
                "status": "ALT_SERIAL_MODE",
                "desc": "Alternate serial mode is executed"
            },
            0xAA000003: {
                "status": "NEXT_APP_CONTROL_PASSED",
                "desc": "Control has been passed to the next application"
            },
            0xAA000004: {
                "status": "OPERATION_NOT_COMPLETED",
                "desc": "Operation started but not necessarily completed yet"
            },
            0xAA00B5F8: {
                "status": "TESTMODE",
                "desc": "Listen window."
            }
        }
