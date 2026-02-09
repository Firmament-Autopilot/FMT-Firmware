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
from typing import List

from .cert_enums import LoadVerifyScheme


class TblImg:
    """A class that represents a line from an image table (.tbl file)"""

    def __init__(self, image_path, load_addr, flash_addr, image_max_size,
                 is_encrypted):
        self.image_path = image_path
        self.load_addr = int(load_addr, 16)
        self.flash_addr = int(flash_addr, 16)
        self.image_max_size = int(image_max_size, 16)
        self.is_encrypted = int(is_encrypted, 16)


class TblFile:
    """A class that represents an image table (.tbl file)"""

    def __init__(self, tbl_path):
        self.tbl_path = tbl_path
        self.tbl_dir = os.path.dirname(tbl_path)
        self._images = self._get_tbl_images()

    @property
    def images(self) -> List[TblImg]:
        """Gets the images in the image table"""
        return self._images

    @property
    def image_count(self) -> int:
        """Gets the number of images in the image table"""
        return len(self._images)

    def validate(self, load_verify_scheme: LoadVerifyScheme) -> List[str]:
        """Validates the image table (.tbl file)
        @param load_verify_scheme: Load-Verify scheme
        @return: List of error messages or an empty list if no errors
        """
        msgs = []
        mem_unload_flag = 0xFFFFFFFF

        for idx, img in enumerate(self._images):
            ln = f'Line {idx + 1}'
            if not os.path.exists(img.image_path):
                msgs.append(f"{ln}: Image file '{img.image_path}' not found")

            if img.load_addr == 0:
                msgs.append(f'{ln}: Illegal memory load address 0')

            if load_verify_scheme == LoadVerifyScheme.FLASH_VERIFY:
                if img.load_addr != mem_unload_flag:
                    msgs.append(
                        f'{ln}: Illegal load address {hex(img.load_addr)}')
            else:
                if img.load_addr == mem_unload_flag:
                    msgs.append(
                        f'{ln}: Illegal load address {hex(img.load_addr)}')

            if load_verify_scheme == LoadVerifyScheme.RAM_VERIFY:
                if img.flash_addr != mem_unload_flag:
                    msgs.append(
                        f'{ln}: Illegal flash address {hex(img.flash_addr)}')
            else:
                if img.flash_addr == mem_unload_flag:
                    msgs.append(
                        f'{ln}: Illegal flash address {hex(img.flash_addr)}')
        return msgs

    def _get_tbl_images(self):
        """Gets non-commented lines from the image table (.tbl file)"""
        with open(self.tbl_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        tbl_images = []
        for line in lines:
            if not line.startswith('#'):
                tbl_images.append(self._get_tbl_image(line))
        return tbl_images

    def _get_tbl_image(self, line: str):
        """Parses a line from the image table (.tbl file)
        @param line: Line from the image table
        """
        columns = line.split()
        img_path = columns[0]
        if not os.path.isabs(img_path):
            img_path = os.path.join(self.tbl_dir, img_path)
        return TblImg(img_path, columns[1], columns[2], columns[3], columns[4])
