"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import logging

from ...core.key_helper import AES_KEY_SIZE

logger = logging.getLogger(__name__)


def generate_key(key_size=AES_KEY_SIZE, add_iv=True, fmt='bin', output=None):
    """Creates an AES key
    @param key_size: Size of the AES key in bytes
    @param add_iv: Indicates whether to add IV to the generated key
    @param fmt: The key file output format
    @param output: The name of the file where to save the key.
           If None, do not save the key to a file
    @return: Key bytes
    """
    key = os.urandom(key_size)
    iv = os.urandom(AES_KEY_SIZE) if add_iv else None
    if fmt == 'hex':
        key = key.hex() + '\n' + iv.hex()
    elif fmt == 'bin':
        if iv:
            key = key + iv
    else:
        raise ValueError(f"Invalid format '{fmt}'")

    if output is not None:
        if os.path.dirname(output):
            os.makedirs(os.path.dirname(output), exist_ok=True)
        with open(output, 'wb') as fp:
            fp.write(key)
        logger.info("Created a key '%s'", os.path.abspath(output))
    return key
