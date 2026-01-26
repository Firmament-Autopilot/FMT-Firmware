"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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


def si_rev_name(revision_id):
    """Gets silicon revision name based on revision ID (e.g. 0x12 = A1)"""
    letters = 'ABCDEF'
    numbers = '012345678'
    hexadecimal = f'{revision_id:02x}'
    first, second = int(hexadecimal[0]), int(hexadecimal[1])
    if 0 < first <= len(letters) and second > 0:
        return letters[first - 1] + numbers[second - 1]
    raise ValueError('Invalid revision ID')
