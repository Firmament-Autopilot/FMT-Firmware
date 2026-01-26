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
import pyhsslms


def generate_key(lms_type_name, lmots_type_name):
    """Generates an LMS private and public key pair
    @return: A tuple containing the private key and public key
    """
    try:
        lms_type = getattr(pyhsslms, lms_type_name.replace('-', '_').lower())
    except AttributeError as e:
        raise ValueError(f'Invalid LMS type: {lms_type_name}') from e

    try:
        lmots_type = getattr(
            pyhsslms, lmots_type_name.replace('-', '_').lower())
    except AttributeError as e:
        raise ValueError(f'Invalid LMOTS type: {lmots_type_name}') from e

    try:
        private_key = pyhsslms.LmsPrivateKey(
            lms_type=lms_type, lmots_type=lmots_type)
    except ValueError as e:
        raise ValueError('LMS key not created: invalid input data') from e

    public_key = private_key.publicKey()
    private = private_key.serialize()
    public = public_key.serialize()

    return private, public


def save_key(data, output):
    """Saves the LMS key to the file
    @param data: Key data in bytes  
    @param output: Key output path
    """
    if not isinstance(data, bytes):
        raise ValueError('Key data must be of type bytes')
    if not isinstance(output, str):
        raise ValueError('Incorrect file name or no paths')
    if not data:
        raise ValueError('Missing data for key generation')
    if not output:
        raise ValueError('Missing paths for key generation')

    try:
        if os.path.dirname(output):
            os.makedirs(os.path.dirname(output), exist_ok=True)
        with open(output, 'wb') as w_data:
            w_data.write(data)
    except OSError as e:
        raise OSError(f"Unable to save key to '{output}': {e}") from e
