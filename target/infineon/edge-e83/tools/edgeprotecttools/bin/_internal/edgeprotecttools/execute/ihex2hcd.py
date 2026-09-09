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
import subprocess

from ..core.mtb_tools_discovery import mtb_tool_exe


def hex2hcd(infile, outfile):
    """Converts Intel HEX to Infineon HCD format
    @param infile: Input Intel HEX file
    @param outfile: Output HCD file
    @return: True if success, otherwise False
    """
    tool_path = mtb_tool_exe('intel_hex_to_hcd')

    if not tool_path:
        raise FileNotFoundError('Intel HEX to HCD conversion tool not found')

    out = subprocess.check_output(
        [
            tool_path,
            os.path.abspath(infile),
            os.path.abspath(outfile)
        ],
        stderr=subprocess.STDOUT
    )

    if out:
        raise RuntimeError(out.decode('utf-8'))
