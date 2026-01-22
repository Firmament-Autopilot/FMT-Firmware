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


class OPCode:
    """Operation codes"""
    RESET = '01030c00'
    ENTER_DOWNLOAD_MODE = '01EDFF14FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDFF0100'
    READ_LOCAL_NAME = '01140C00'
    READ_SUPPORTED_VCS = '013BFD00'
    READ_SOC_ID = '01E8FD00'
    GET_CSR = '01F4FD'


class OPResponse:
    """Operation code responses"""
    RESET = '040e0401030c00'
    ENTER_DOWNLOAD_MODE = '040e1a01edff00005cda00000000010147cfad0b00c05f41' \
                          '803d920900'
    DOWNLOAD_MINIDRIVER = '040e04012efc000410010004100100'
    READ_SUPPORTED_VCS = '040E54013BFD001E3C1807C0EB3814C77380080040002E2200' \
                         '07004988000C000000004022008008E0E039088120D82C00F8' \
                         '0E004008A244010002108882500028E0C64193390000000000' \
                         '000000000000000000000000'
