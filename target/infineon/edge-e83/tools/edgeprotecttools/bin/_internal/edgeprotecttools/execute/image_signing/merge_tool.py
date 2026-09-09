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
from intelhex import IntelHex


class MergeTool:
    """Merging images"""

    @staticmethod
    def merge_hex(images, output=None, overlap='error') -> IntelHex:
        """Merges two or more different hex files into one
        @param images: A tuple containing file paths. The files are
        merged in the specified order
        @param output: The path where to save the merged file
        @param overlap: Action on overlap of data or starting addr:
            - error: raising OverlapError;
            - ignore: ignore other data and keep current data in
                      overlapping region;
            - replace: replace data with other data in overlapping region;
        @return IntelHex object containing merged image
        """
        if not isinstance(images, (tuple, list)):
            raise TypeError(
                f'Expected tuple or list, got {type(images).__name__}')

        if len(images) < 2:
            raise ValueError('At least two images must be specified')

        ih_orig = IntelHex(images[0])
        for image in images[1:]:
            ih_new = IntelHex(image)
            ih_orig.merge(ih_new, overlap=overlap)

        if output:
            if output.endswith('bin'):
                ih_orig.tobinfile(output)
            else:
                ih_orig.write_hex_file(output)
        return ih_orig

    @staticmethod
    def append_hex(first, second, first_end_addr=None, output=None):
        """Appends the second hex file to the first one starting from the
        end address of the first file
        @param first: The hex file to which to append the data
        @param second: The hex file to append
        @param first_end_addr: The end address of the first file
        @param output: The path where to save the appended file
        @return IntelHex object containing appended image
        """
        ih_first = IntelHex(first)
        ih_second = IntelHex(second)

        if not first_end_addr:
            first_end_addr = ih_first.maxaddr() + 1

        j = 0
        for i in range(first_end_addr,
                       first_end_addr + ih_second.maxaddr() + 1):
            ih_first[i] = ih_second[j]
            j += 1

        if output:
            ih_first.write_hex_file(output)
        return ih_first

    @staticmethod
    def merge_bin(images, output=None) -> bytes:
        """Merges two or more different bin files into one
        @param images: A tuple containing file paths. The files are
        merged in the specified order
        @param output: The path where to save the merged file
        @return Merged bytes
        """
        if not isinstance(images, (tuple, list)):
            raise TypeError(
                f'Expected tuple or list, got {type(images).__name__}')

        if len(images) < 2:
            raise ValueError('At least two images must be specified')

        merged = b''
        for image in images:
            with open(image, 'rb') as binary:
                merged += binary.read()
        if output:
            with open(output, 'wb') as binary:
                binary.write(merged)
        return merged
