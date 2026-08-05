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
from typing import Union, List

from intelhex import IntelHex


class SplitTool:
    """Extracting individual images from the multi-image file"""

    @staticmethod
    def get_segment(image, segment_addr, output=None) -> Union[IntelHex, None]:
        """Gets a segment which starts from the specified address
        from the hex file
        @param image: The hex file path
        @param segment_addr: Address of the segment
        @param output: A hex file where to save the segment
        @return: IntelHex object containing the segment
        """
        ih = IntelHex(image)
        for start, end in ih.segments():
            if start == int(str(segment_addr), 0):
                segment_ih = IntelHex(ih[start:end])
                segment_ih.start_addr = ih.start_addr
                if output:
                    if output.endswith('bin'):
                        segment_ih.tobinfile(output)
                    else:
                        segment_ih.write_hex_file(output)
                return segment_ih
        return None

    @staticmethod
    def split(image) -> List[IntelHex]:
        """Gets a list of the hex file segments
        @param image: The hex file path
        @return: A list of IntelHex objects containing all segments
        """
        ih = IntelHex(image)
        segments = []
        for start, end in ih.segments():
            segment_ih = IntelHex(ih[start:end])
            segment_ih.start_addr = ih.start_addr
            segments.append(segment_ih)
        return segments
