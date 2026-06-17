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
import abc


class StatusCodesBase(abc.ABC):
    """Base class for the classes storing status codes"""

    @abc.abstractmethod
    def status_codes(self):
        """Dictionary in the following format:
            {
                0x00000000: {
                    "status": "SUCCESS",
                    "desc": "The operation completed successfully"
                },
                0x00000001: {
                    "status": "FAILURE",
                    "desc": "The operation failed"
                }
            }
        """

    def status_by_code(self, code):
        """Gets status name and description by status code"""
        codes = self.status_codes()
        return codes[code]['status'], codes[code]['desc']

    def code_by_name(self, name):
        """Gets status code by status name"""
        codes = self.status_codes()
        return next(k for k, v in codes.items() if v['status'] == name)
