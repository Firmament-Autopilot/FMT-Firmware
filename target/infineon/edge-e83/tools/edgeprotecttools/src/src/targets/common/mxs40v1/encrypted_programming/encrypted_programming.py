"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from enum import IntEnum

from ..provisioning.sys_call import encrypted_programming
from .....core import progress_bar

ENCRYPTED_DATA_LEN = 0x210

logger = logging.getLogger(__name__)


class EPMode(IntEnum):
    init = 0x00
    data = 0x01
    finish = 0x02


def program(tool, target, encrypted_image):
    encrypted_image_path = os.path.abspath(encrypted_image)
    logger.info("Start encrypted programming of '%s':", encrypted_image_path)

    # Read keys ID and AES header
    with open(encrypted_image, 'r', encoding='utf-8') as f:
        file_lines = f.readlines()
        host_key_id = int(file_lines[0].strip()[:2])
        dev_key_id = int(file_lines[0].strip()[2:4])
        aes_header = file_lines[1].strip()

    # Validate AES header size
    header_size = len(aes_header)
    if header_size > target.register_map.ENTRANCE_EXAM_SRAM_SIZE:
        raise ValueError('JWT packet too long')

    # Init programming
    logger.debug('\nInit encrypted programming:')
    logger.debug('AES header (%d): %s', header_size, aes_header)
    syscall_status = encrypted_programming(tool, target.register_map,
                                           EPMode.init, aes_header,
                                           host_key_id, dev_key_id)
    if not syscall_status:
        return False

    # Start programming
    logger.debug('\nStart encrypted programming:')
    text = ''
    with open(encrypted_image, 'r', encoding='utf-8') as f:
        next(f)
        next(f)
        for line in f:
            text += line

    addr_bytes = 8
    data_bytes = ENCRYPTED_DATA_LEN * 2
    text = text.replace('\n', '')
    for i in range(0, len(text), data_bytes + addr_bytes):
        addr = int(text[i:i + addr_bytes], 16)
        data = text[i + addr_bytes: i + addr_bytes + data_bytes]

        logger.debug('\nRow address: 0x%x', addr)
        logger.debug('Row data: %s', data)

        syscall_status = encrypted_programming(tool, target.register_map,
                                               EPMode.data, data, 0, 0, addr)
        if syscall_status:
            progress = int(i / len(text) * 100)
            progress_bar.update_progress(progress)
        else:
            return False
    progress_bar.update_progress(100)

    # Finish programming
    logger.debug('\nFinish encrypted programming:')
    syscall_status = encrypted_programming(tool, target.register_map,
                                           EPMode.finish, None)
    if not syscall_status:
        return False

    return True
