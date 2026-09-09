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
import os
import time


def device_identity_asset_map(**kwargs):
    """Gets protected and unprotected parts of the entrance exam packet
    @param kwargs:
        :cert: path to the IFX Device Identity certificate
    @return: Unprotected data, protected data
    """
    unprotected = {
        'nonce': {
            'id': 0x13010002,
            'value': nonce()
        },
        'cert': {
            'id': 0x1F000000,
            'value': kwargs.get('ifx_integrity_cert')
        }
    }
    protected = {}

    return unprotected, protected, None


def nonce():
    """Gets a unique value in the following format:
      - bits 0...31 - incremental counter
      - bits 32...63 - initial value
      - bits 64...127 - Unix timestamp
    """
    incremental_counter = os.urandom(4)
    initial_value = os.urandom(4)
    unix_timestamp = int.to_bytes(int(time.time()), length=8, byteorder='big')
    return incremental_counter + initial_value + unix_timestamp
