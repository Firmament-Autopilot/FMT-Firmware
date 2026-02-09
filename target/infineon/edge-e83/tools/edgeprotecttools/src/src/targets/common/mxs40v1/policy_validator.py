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
import jsonschema
import logging
import json
import os.path
from math import ceil
from collections import namedtuple

from .policy_parser import ImageType
from ....core import PolicyValidatorBase
from ....core.enums import ValidationStatus
from ....execute.key_reader import load_key

MODULE_PATH = os.path.dirname(os.path.realpath(__file__))
POLICY_SCHEMA = os.path.join(MODULE_PATH, 'json', 'schema.json_schema')

logger = logging.getLogger(__name__)


class PolicyValidator(PolicyValidatorBase):
    """
    Validates policy file against JSON schema. Validates values in the file.
    """

    def __init__(self, policy_parser, memory_map):
        """
        Creates instance of policy validator.
        :param policy_parser: Specific parser for the policy.
        :param memory_map: Device memory map.
        """
        self.parser = policy_parser
        self.memory_map = memory_map
        self.policy_dir = self.parser.policy_dir
        self.stage = None
        self.is_smif = None
        self.is_multi_image = None

    def validate(self, skip=None, skip_prompts=False, **kwargs):
        """
        Validation of policy.json.
        :param skip: Validators to skip (e.g. pre_build, dap_disabling)
        :param skip_prompts: Indicates whether to skip interactive prompts
        :return Validation status
        """
        status = ValidationStatus.OK
        if self.skip_validation is True:
            return status

        skip_list = skip if skip else []

        # First stage validation
        with open(POLICY_SCHEMA, encoding='utf-8') as f:
            file_content = f.read()
            json_schema = json.loads(file_content)

        if self.parser.json is None:
            raise ValueError('No policy data')

        try:
            jsonschema.validate(self.parser.json, json_schema)
            logger.debug('First stage validation success')
        except (jsonschema.exceptions.ValidationError,
                jsonschema.exceptions.SchemaError) as e:
            logger.error('Validation against schema failed')
            logger.error(e)
            status = ValidationStatus.ERROR

        if self._continue_validation(status):
            self.stage = self.get_policy_stage()
            self.is_smif = self._is_smif()
            self.is_multi_image = self._is_multi_image()

        # Second stage validation
        if self._continue_validation(status):
            is_multi_image = self._is_multi_image()
            logger.debug('Validating firmware slots overlapping')
            result = self.validate_address_overlap(is_multi_image)
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            for slot in self.parser.json['boot_upgrade']['firmware'][1:]:
                logger.debug('Validating boot_auth id matches kid in JSON '
                             'key file')
                result = self.validate_boot_keys(slot)
                result &= self.validate_key_file_kid(slot)
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Validating there is no different JWKs with the '
                         'same key ID')
            result = self.key_name_validation()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if self.stage == 'multi':
                logger.debug('Validating multi-image IDs')
                result = self.validate_multi_image_id()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if self.stage == 'multi':
                logger.debug('Validating multi-image smif_id')
                result = self.validate_multi_image_smif_id()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if self.stage != 'multi':
                logger.debug('Validating whether image ID corresponds to '
                             'CyBootloader launch ID')
                result = self.image_launch_validation()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Validating policy for BOOT sections, '
                         'encryption and SMIF')
            result = self.check_slots()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Validating monotonic counter')
            result = self.validate_monotonic_counter()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Validating CyBootloader paths')
            result = self.validate_cybootloader_paths()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Validate whether slots address value is aligned '
                         'with the SMPU address limits')
            result = self.validate_slot_address_alignment()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Check aligning to Memory map')
            result = self.validate_regions_range()
            if not result:
                status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if 'pre_build' not in skip_list:
                logger.debug('Checking integrity of pre-build section')
                result = self.validate_prebuild_section()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if 'dap_disabling' not in skip_list:
                result = self.validate_dap_disabling(skip_prompts)
                if result != ValidationStatus.OK:
                    status = result

        if self._continue_validation(status):
            if self.parser.upgrade_mode() == 'swap':
                result = self.validate_status_partition_size()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if self.stage == 'multi':
                logger.debug('Validating multi-image smif_sector_size')
                result = self.validate_multi_image_smif_sector_size()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            if self.parser.upgrade_mode() == 'swap':
                result = self.validate_scratch_smif_alignment()
                if not result:
                    status = ValidationStatus.WARNING

        if self._continue_validation(status):
            if self.parser.upgrade_mode() == 'swap':
                result = self.validate_scratch_area()
                if not result:
                    status = ValidationStatus.ERROR

        if self._continue_validation(status):
            logger.debug('Checking flash regions integrity')
            result = self.validate_flash_gaps()
            if not result:
                status = ValidationStatus.WARNING

        if self._continue_validation(status):
            logger.debug('Checking partitions overlaps')
            result = self.check_partitions_overlap_in_sectors()
            if not result:
                status = ValidationStatus.ERROR

        if status == ValidationStatus.ERROR:
            logger.error('Policy validation finished with error')
        elif status == ValidationStatus.WARNING:
            logger.warning('Policy validation finished with warnings')
        elif status == ValidationStatus.TERMINATED:
            logger.info('Terminated by user')
        else:
            logger.debug('Second stage validation success')

        return status

    @staticmethod
    def _continue_validation(status):
        return status not in [ValidationStatus.ERROR,
                              ValidationStatus.TERMINATED]

    @staticmethod
    def validate_boot_keys(slot):
        """ Validates boot_keys section against boot_auth section """
        result = True
        for a in slot['boot_auth']:
            key_found = False
            for k in slot['boot_keys']:
                if k['kid'] == a:
                    key_found = True
                    break
            result &= key_found
            if not result:
                logger.error("Key with ID %s not found in the 'boot_keys' "
                             "section (image ID %s)", a, slot['id'])
                break

        return result

    def validate_key_file_kid(self, slot):
        """ Validates kid field of the key files against boot_auth section """
        result = True
        for a in slot['boot_auth']:
            key_found = False
            for k in slot['boot_keys']:
                if k['kid'] == a:
                    key_file = os.path.join(self.policy_dir, k['key'])
                    if os.path.exists(key_file):
                        private, public = load_key(key_file)
                        if private:
                            file_kid = int(private['kid'])
                        elif public:
                            file_kid = int(public['kid'])
                        else:
                            file_kid = None

                        if file_kid == a:
                            key_found = True
                            break
                    else:
                        key_found = True  # it is ok if file does not exist
                        logger.debug("Key file '%s' does not exist", key_file)
            result &= key_found
            if not result:
                logger.error("Key ID %s, specified in the 'boot_auth' "
                             "section does not match the ID in the 'kid' "
                             "field of JWK (image ID %s)", a, slot['id'])
                break

        return result

    def key_name_validation(self):
        """
        Validates whether there are no key entities with same ID,
        but different filename.
        :return: True if no entities with same ID, but different filename
        found, otherwise False.
        """
        # Create dictionary with key ID and paths
        keys = {}
        for slot in self.parser.json['boot_upgrade']['firmware']:
            for key_type in ['boot_keys', 'upgrade_keys']:
                if key_type in slot:
                    for item in slot[key_type]:
                        try:
                            keys[item['kid']].append(os.path.abspath(item['key']))
                        except KeyError:
                            keys[item['kid']] = [os.path.abspath(item['key'])]

        # Check whether there is a key with same ID, but different path
        for key_list in keys.values():
            if len(set(key_list)) > 1:
                logger.error('JWK entities with same key ID, but different '
                             'file names found')
                return False

        # Check whether same key ID is not used for the different file name
        for k1, v1 in keys.items():
            for k2, v2 in keys.items():
                if k1 != k2:
                    if any(elem in v1 for elem in v2):
                        logger.error('JWK entities with different key IDs, '
                                     'but same file name found')
                        return False

        return True

    def image_launch_validation(self):
        """
        Validates link from the first slot to the next to run image.
        :return True if validation succeeds, otherwise False.
        """
        launch = self.parser.json['boot_upgrade']['firmware'][0]['launch']
        image_id = self.parser.json['boot_upgrade']['firmware'][1]['id']

        if launch != image_id:
            if launch != self.memory_map.SPE_IMAGE_ID:
                logger.error('Image ID = %s does not correspond to '
                             'CyBootloader launch ID = %s', image_id, launch)
                return False
            else:
                logger.debug('NSPE image ID = %s. It will be launched by '
                             'the SPE part', image_id)
        return True

    def check_slots(self):
        """
        Validates types of images, availability of UPGRADE image,
        availability of SMIF
        :return: True if validation passed, otherwise False.
        """
        slot0 = None
        slot1 = None

        if self.stage == 'dual':

            bootloader_slot = self.parser.json['boot_upgrade']['firmware'][0]
            cm4_slot = self.parser.json['boot_upgrade']['firmware'][2]
            cm0_slot = self.parser.json['boot_upgrade']['firmware'][1]

            img_id = cm0_slot['id']

            # check dual stage scheme
            if img_id != self.memory_map.SPE_IMAGE_ID:
                logger.error('SPE Image ID = %s is not equal to 1!', img_id)
                return False

            if bootloader_slot['launch'] != img_id:
                logger.error(
                    'Image ID = %s does not correspond to CyBootloader '
                    'launch ID = %s', img_id, bootloader_slot['launch'])
                return False

            if cm0_slot['launch'] != cm4_slot['id']:
                logger.error(
                    'NSPE image ID = %s does not correspond the SPE '
                    'launch_ID = %s', cm4_slot['id'], cm0_slot['launch'])
                return False

            # check slots addresses and sizes if upgrade is set to True
            for slot in cm0_slot['resources']:
                if slot['type'] == ImageType.BOOT.name:
                    slot0 = slot
                if cm0_slot['upgrade']:
                    if slot['type'] == ImageType.UPGRADE.name:
                        slot1 = slot
                        smif_id = cm0_slot['smif_id']

                        if 'encrypt' in cm0_slot and cm0_slot['encrypt']:
                            # mark slot1 image as one, that should be encrypted
                            slot1.update({'encrypt': True})
                            logger.debug('Image for UPGRADE SPE will be encrypted per policy settings.')
                else:
                    logger.debug('Upgrade is disabled. Image for UPGRADE will not be generated per policy settings.')
                    break

            slots = [2]
        else:
            slots = [1]
        if self.stage == 'multi':
            slots.append(2)

        for slot_idx in slots:
            slot0 = None
            slot1 = None
            for slot in self.parser.json['boot_upgrade']['firmware'][slot_idx]['resources']:
                if slot['type'] == ImageType.BOOT.name:
                    slot0 = slot

                if self.parser.json['boot_upgrade']['firmware'][slot_idx]['upgrade']:
                    slot1 = slot
                    smif_id = self.parser.json['boot_upgrade']['firmware'][slot_idx]['smif_id']
                    if slot['type'] == ImageType.UPGRADE.name:
                        try:
                            if self.parser.json['boot_upgrade']['firmware'][slot_idx]['encrypt']:
                                # mark slot1 image as one, that should be encrypted
                                slot1.update({'encrypt': True})
                        except KeyError:
                            pass
                else:
                    logger.debug('UPGRADE image will not be generated per policy settings.')
                    break

            if slot0 is None:
                logger.error('BOOT section was not found in policy resources.')
                return False

            if slot1:
                if smif_id == 0:
                    if slot1['address'] >= self.memory_map.EXTERNAL_MEM_START:
                        logger.error(
                            'Slot 1 address = 0x%x, but SMIF is not '
                            'initialized (smif_id = 0). UPGRADE image will '
                            'not be generated', slot1['address'])
                        return False
                else:
                    if smif_id < 0 or smif_id > 4:
                        logger.error(
                            "Incorrect 'smif_id' value. The correct values "
                            "are: 0 - SMIF disabled (no external memory); "
                            "1, 2, 3 or 4 - slave select line, which controls "
                            "memory module")
                        return False

                    if slot1['address'] >= self.memory_map.EXTERNAL_MEM_START:
                        logger.debug('UPGRADE slot will reside in external '
                                     'flash at address 0x%x', slot1['address'])

                if slot0['size'] != slot1['size']:
                    logger.warning('BOOT and UPGRADE slots sizes are not equal')

        return True

    def validate_cybootloader_paths(self):
        """
        Validates path to CyBootloader hex and jwt file.
        :return: True if CyBootloader hex and jwt files specified in policy and exist, otherwise False.
        """
        node = self.parser.json['cy_bootloader']
        if node['mode'] == 'custom':
            if 'hex_path' not in node or 'jwt_path' not in node:
                logger.error('Paths to CyBootloader hex and jwt files are required when '
                             'CyBootloader mode is set to custom')
                return False
        return True

    def validate_multi_image_id(self):
        """
        Validates multi-image IDs.
        :return: True if multi-image ID matches requirements, otherwise false.
        """
        is_valid = True
        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] != 0:
                if 'multi_image' in slot:
                    is_valid &= 1 <= slot['multi_image'] <= 2
                else:
                    is_valid = False
        return is_valid

    def validate_address_overlap(self, slot_overlaps=True):
        """
        Validates whether used flash addresses do not overlap each other.
        :param slot_overlaps: Indicates whether to validate slot overlaps
        :return: True if there are no overlaps, otherwise False.
        """
        AddressSize = namedtuple("AddressSize", "address size")
        all_slots_addr = []
        res_area = []
        for slot in self.parser.json['boot_upgrade']['firmware']:
            app_area = []
            for item in slot['resources']:
                if item['type'] in ['BOOT', 'UPGRADE']:
                    app_area.append(AddressSize(item['address'], item['size']))
                if item['type'] in ['FLASH_PC1_SPM', 'STATUS_PARTITION', 'SCRATCH']:
                    res_area.append(AddressSize(item['address'], item['size']))

            # Validate overlaps in range of the slot
            if app_area:
                result = self.check_overlaps(app_area)
                if not result:
                    return result
                all_slots_addr.extend(app_area)

            # Validate overlaps in range of the resources
            if res_area:
                result = self.check_overlaps(res_area)
                if not result:
                    return result

        # Validate overlaps between app and resources
        result = self.check_overlaps(all_slots_addr, res_area)
        if not result:
            return result

        # Validate overlaps between the slots
        if slot_overlaps:
            return self.check_overlaps(all_slots_addr)

        return True

    @staticmethod
    def is_ram(item_type):
        """
        Checks whether the item is placed in ram
        @param item_type: Name of the item
        @return: True if the item is placed in ram, otherwise False
        """
        return item_type in ('SRAM_SPM_PRIV', 'SRAM_DAP')

    def is_common_cm0_cm4_slot(self, slot_id, item_type):
        """
        Checks whether the item is in a common cm0/cm4 slot
        @param slot_id: Id of the slot
        @param item_type: Name of the item
        @return: True if the item is placed in a common cm0/cm4 slot,
        otherwise False
        """
        return not self.is_multi_image and slot_id == 16 and item_type == 'BOOT'

    def check_partitions_overlap_in_sectors(self):
        """
        Checks whether partitions are placed in separate sector.
        @return: True if partitions are placed in separate sector,
        otherwise False
        """
        accessed_sectors = {'internal': [], 'external': []}
        for slot in self.parser.json['boot_upgrade']['firmware']:
            for item in slot['resources']:
                # Skip current item in case the item
                # is in ram or in common cm0/cm4 slot
                if self.is_ram(item['type']) or \
                        self.is_common_cm0_cm4_slot(slot['id'], item['type']):
                    continue

                # Getting sector size in case if the item 
                # is in external memory
                if item['address'] >= self.memory_map.EXTERNAL_MEM_START:
                    memory_type = 'external'
                    if 'smif_sector_size' in slot:
                        sector_size = slot['smif_sector_size']
                    else:
                        sector_size = self.memory_map.MIN_EXT_ERASE_SIZE
                else:
                    memory_type = 'internal'
                    sector_size = self.memory_map.MIN_INT_ERASE_SIZE

                # Calculate the number of first and last sectors
                # of the current partition and the total sectors number,
                # that is occupied by the current partition
                first_slot_sector = int(item['address'] / sector_size)
                last_slot_sector = int((item['address'] + item['size'] - 1)
                                       / sector_size)
                sectors_number = last_slot_sector - first_slot_sector + 1

                # Check whether there is a sector of current partition
                # which is already occupied by another partition
                for sector in range(sectors_number):
                    if first_slot_sector + sector in accessed_sectors[memory_type]:
                        logger.error('Partition with id %d overlaps another partition. '
                                     'Every partition in policy should have '
                                     'separate sectors', slot['id'])
                        return False
                    accessed_sectors[memory_type].append(first_slot_sector + sector)
        return True

    @staticmethod
    def check_overlaps(addr_list1, addr_list2=None):
        """
        Checks whether addresses in the specified list(s) overlap.
        If single list specified, check overlaps in the range of the list.
        If two lists specified, check overlaps between the lists.
        :return: True if address intersection detected, otherwise False
        """
        single_list = addr_list2 is None
        if single_list:
            addr_list2 = addr_list1

        for i in range(len(addr_list1)):
            for k in range(len(addr_list2)):
                if not single_list or (single_list and i != k):
                    x = range(addr_list1[i].address,
                              addr_list1[i].address + addr_list1[i].size)
                    y = range(addr_list2[k].address,
                              addr_list2[k].address + addr_list2[k].size)
                    xy = range(max(x.start, y.start), min(x.stop, y.stop))
                    if len(xy) > 0:
                        logger.error(
                            "Address range '0x%x-0x%x' overlaps address range "
                            "'0x%x-0x%x'", x.start, x.stop, y.start, y.stop)
                        return False
        return True

    def get_policy_stage(self):
        """
        Gets policy stage based on image count.
        :return: The stage.
        """
        # Dual-stage policy contains 3 firmware images (CyBootloader, M0p, M4)
        if len(self.parser.json['boot_upgrade']['firmware']) == 3:
            multi_image = False
            for slot in self.parser.json['boot_upgrade']['firmware']:
                multi_image |= 'multi_image' in slot
            return 'multi' if multi_image else 'dual'

        # Single-stage policy contains 2 firmware images (CyBootloader, M4)
        if len(self.parser.json['boot_upgrade']['firmware']) == 2:
            return "single"

    def validate_regions_range(self):
        """
        Validates whether memory regions are in range of the available
        internal and external memory
        """
        def is_flash_region_valid(reg):
            min_addr = self.memory_map.FLASH_ADDRESS
            max_addr = min_addr + self.memory_map.FLASH_SIZE
            is_start_valid = min_addr <= reg.start <= max_addr
            is_end_valid = min_addr <= reg.end <= max_addr
            if not is_start_valid or not is_end_valid:
                logger.error(
                    'Address range 0x%x-0x%x is out of available FLASH area '
                    '(0x%x-0x%x)', reg.start, reg.end, min_addr, max_addr)
                return False
            return True

        def is_smif_region_valid(reg):
            min_addr = self.memory_map.EXTERNAL_MEM_START
            if reg.start < min_addr:
                logger.error(
                    'Address range 0x%x-0x%x is not in external memory area '
                    '(0x%x)', reg.start, reg.end, min_addr)
                return False
            return True

        flash_regions = []
        smif_regions = []
        MemoryRegion = namedtuple('MemoryRegion', 'start end type')
        MemoryRegion.__new__.__defaults__ = (None, None, None)

        for item in self.parser.json['debug']['rma']['destroy_flash']:
            region = MemoryRegion(item['start'], item['start'] + item['size'])
            flash_regions.append(region)

        for item in self.parser.json['boot_upgrade']['firmware']:
            for res in item['resources']:
                region = MemoryRegion(res['address'],
                                      res['address'] + res['size'],
                                      res['type'])
                upgrade_enabled = item['upgrade']
                smif_enabled = item.get('smif_id', 0) > 0
                in_ext_mem = region.start >= self.memory_map.EXTERNAL_MEM_START

                if region.type in ['FLASH_PC1_SPM', 'STATUS_PARTITION']:
                    flash_regions.append(region)
                elif region.type == 'SCRATCH':
                    if in_ext_mem:
                        smif_regions.append(region)
                    else:
                        flash_regions.append(region)
                elif region.type == 'BOOT':
                    if in_ext_mem and smif_enabled:
                        smif_regions.append(region)
                    else:
                        flash_regions.append(region)
                elif region.type == 'UPGRADE' and upgrade_enabled:
                    if smif_enabled:
                        smif_regions.append(region)
                    else:
                        flash_regions.append(region)

        for region in flash_regions:
            if not is_flash_region_valid(region):
                return False

        for region in smif_regions:
            if not is_smif_region_valid(region):
                return False

        return True

    def validate_multi_image_smif_id(self):
        """
        Validates smif_id for multi-image case.
        :return: True if smif_id is the same for all images (with an
        exception for smif_id=0), otherwise false.
        """
        smif_id_list = []
        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] != 0:
                if 'smif_id' in slot:
                    smif_id_list.append(slot['smif_id'])

        smif_id_set = set(smif_id_list)
        is_valid = len(smif_id_set) == 1 or \
                   (len(smif_id_set) == 2 and 0 in smif_id_set)

        if not is_valid:
            logger.error('smif_id in multi-image case must be the same for all images (with an exception for '
                         'smif_id=0 which can be combined with other values)')

        return is_valid

    def validate_prebuild_section(self):
        """
        Validates pre_build section of given policy
        :return: true if all needed parameters in place and corresponding
        files exist
        """
        result = True
        if 'pre_build' in self.parser.json:
            # Checking oem_public_key
            try:
                key = self.parser.oem_public_key()
            except KeyError:
                logger.error('Parameter "oem_public_key" is missing')
                result = False
            else:
                if key.count(None) == 2:
                    logger.error('File from "oem_public_key" not found')
                    result = False

            # Checking oem_private_key
            try:
                key = self.parser.oem_private_key()
            except KeyError:
                logger.error('Parameter "oem_private_key" is missing')
                result = False
            else:
                if key.count(None) == 2:
                    logger.error('File from "oem_private_key" not found')
                    result = False

            # Checking hsm_public_key
            try:
                key = self.parser.hsm_public_key()
            except KeyError:
                logger.error('Parameter "hsm_public_key" is missing')
                result = False
            else:
                if key.count(None) == 2:
                    logger.error('File from "hsm_public_key" not found')
                    result = False

            # Checking hsm_private_key
            try:
                key = self.parser.hsm_private_key()
            except KeyError:
                logger.error('Parameter "hsm_private_key" is missing')
                result = False
            else:
                if key.count(None) == 2:
                    logger.error('File from "hsm_private_key" not found')
                    result = False

            # Checking cy_auth
            try:
                key_path = self.parser.get_cy_auth()
            except KeyError:
                logger.error('Parameter "cy_auth" is missing')
                result = False
            else:
                if not os.path.isfile(key_path):
                    logger.error('File from "cy_auth" not found')
                    result = False

            # Checking group_private_key
            if self.parser.provision_group_private_key_state():
                key = self.parser.group_private_key()
                if key.count(None) == 2:
                    logger.error('Group private key file not found')
                    result = False

            # Checking device_private_key
            if self.parser.provision_device_private_key_state():
                key = self.parser.device_private_key()
                if key.count(None) == 2:
                    logger.error('Device private key file not found')
                    result = False
        else:
            logger.error('Section "pre_build" is missing')
            result = False

        return result

    def _is_multi_image(self):
        for slot in self.parser.json['boot_upgrade']['firmware']:
            if 'multi_image' in slot:
                return True
        return False

    def validate_slot_address_alignment(self):
        """
        Validates whether slots address is aligned with the SMPU
        address limits
        """
        for slot in self.parser.json['boot_upgrade']['firmware']:
            for res in slot['resources']:
                if res['type'] in ['BOOT']:
                    address = int(res['address'])
                    if address % 1024 != 0:
                        logger.error(
                            '%s slot address (0x%x) is misaligned with the '
                            'SMPU address limits for the CYB06XXX part',
                            res['type'], address)
                        return False
        return True

    def validate_dap_disabling(self, skip_prompts=False):
        """
        Validates DAP closure and warns a user about the result
        """
        cm0_closed = self.parser.is_ap_disabled('m0p')
        cm4_closed = self.parser.is_ap_disabled('m4')
        sysap_closed = self.parser.is_ap_disabled('system')
        result = ValidationStatus.OK
        if cm0_closed and cm4_closed:
            if skip_prompts:
                logger.warning('The policy will close out SWD ports on the '
                               'chip, preventing any reprogramming of '
                               'application image via SWD')
                result = ValidationStatus.WARNING
            else:
                answer = input('The policy will close out SWD ports on the '
                               'chip, preventing any reprogramming of '
                               'application image via SWD. Please ensure you '
                               'have a valid image programmed on the chip '
                               'before provisioning the chip. '
                               'Continue? (y/n): ')
                if answer.lower() == 'y':
                    result = ValidationStatus.OK
                else:
                    return ValidationStatus.TERMINATED

        if sysap_closed:
            if skip_prompts:
                logger.warning('The policy will close out System DAP on the '
                               'chip, preventing further reprovisioning')
                result = ValidationStatus.WARNING
            else:
                answer = input('The policy will close out System DAP on the '
                               'chip, preventing further reprovisioning. '
                               'Continue? (y/n): ')
                if answer.lower() != 'y':
                    return ValidationStatus.TERMINATED
        return result

    def validate_monotonic_counter(self):
        """
        Validates 'monotonic' field in the policy
        """
        result = True
        cm0_monotonic = None
        cm4_monotonic = None
        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] != 0:
                if self._is_cm0_slot(slot['id']):
                    r = range(0, 16)
                    cm0_monotonic = slot['monotonic']
                    if cm0_monotonic not in r:
                        logger.error('CM0 application monotonic counter must '
                                     'be in range %d-%d', r.start, r.stop - 1)
                        result &= False
                if self._is_cm4_slot(slot['id']):
                    r = range(8, 16)
                    cm4_monotonic = slot['monotonic']
                    if cm4_monotonic not in r:
                        logger.error('CM4 application monotonic counter must '
                                     'be in range %d-%d', r.start, r.stop - 1)
                        result &= False
        if cm0_monotonic and cm4_monotonic and cm0_monotonic == cm4_monotonic:
            logger.error("'monotonic' field must be different for different "
                         "applications in multi-image case")
            result &= False
        return result

    def validate_status_partition_size(self):
        """
        Validate minimal allowable size and availability of status partition
        """
        result = True

        status_partition = self.parser.status_partition()
        if not status_partition:
            raise ValueError('Status partition not found in the specified '
                             'policy file')

        if self.is_multi_image:
            d_cm0 = self._calc_status_partition_size('cm0')
            d_cm4 = self._calc_status_partition_size('cm4')
            d = d_cm0 + d_cm4
        else:
            d = self._calc_status_partition_size()

        if status_partition.size < d:
            logger.error('SWAP status partition is too small. The minimum '
                         'sufficient size is %d bytes', d)
            result = False

        return result

    def validate_multi_image_smif_sector_size(self):
        """
         Validates smif_sector_size for multi-image case.
         :return: True if smif_sector_size are the same for all images
         """
        smif_sector_size_list = []

        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] == 0:
                continue
            if 'smif_id' in slot and slot['smif_id'] > 0:
                if 'smif_sector_size' in slot:
                    smif_sector_size_list.append(slot['smif_sector_size'])

        smif_sector_size_set = set(smif_sector_size_list)
        is_valid = len(smif_sector_size_set) < 2 or \
                  (len(smif_sector_size_set) == 2 and 0 in smif_sector_size_set)

        if not is_valid:
            logger.error('smif_sector_size in multi-image case must be the same'
                         ' for all images')

        return is_valid

    def validate_scratch_smif_alignment(self):
        """
        Validate slots alignment in external memory for swap:scratch mode
        """
        trailer_size = 512
        result = True

        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] == 0:
                continue
            if 'smif_id' in slot and slot['smif_id'] > 0:
                if 'smif_sector_size' in slot:
                    smif_sector_size = slot['smif_sector_size']
                else:
                    smif_sector_size = 256*1024
                    logger.warning(
                        "'smif_sector_size' field not found in policy. Assume "
                        "256K sector size for slot 'id': %s", slot['id'])
                    result = False

                for res in slot['resources']:
                    if res['type'] in ['UPGRADE']:
                        address = res['address']
                        size = res['size']

                        if size > 0x100000:
                            trailer_size = 1024

                        if (address+size-trailer_size) % smif_sector_size != 0:
                            tail_sector_size = (address+size) % smif_sector_size
                            logger.warning('slot id=%s', slot['id'])
                            logger.warning('slot address=0x%x', address)
                            logger.warning('slot size=0x%x', size)
                            logger.warning(
                                'SWAP-scratch mode requires the image and the '
                                'image trailer to be located in separate '
                                'sectors. Move the image trailer (last %d '
                                'bytes of the slot) to the new physical '
                                'sector in external memory. The current '
                                'configuration uses %d (0x%x) bytes of the '
                                'last slot physical sector',
                                trailer_size, tail_sector_size,
                                tail_sector_size)
                            result = False

        return result
 
    def validate_scratch_area(self):
        """
        Validate scratch_area to meet all necessary requirements
        """
        smif_found = False
        sector_size = 512
        smif_sector_size = 256*1024
        smif_start_addr = self.memory_map.EXTERNAL_MEM_START

        scratch_area = self.parser.scratch_area()
        if not scratch_area:
            logger.error('Scratch area must be specified inside policy file '
                         'in case of SWAP mode usage')
            return False

        for slot in self.parser.json['boot_upgrade']['firmware']:
            if slot['id'] == 0:
                continue
            if 'smif_id' in slot and slot['smif_id'] > 0:
                sector_size = slot.get('smif_sector_size', smif_sector_size)
                smif_found = True

        if scratch_area.address >= smif_start_addr and not smif_found:
            sector_size = smif_sector_size
            logger.warning('Scratch area in external memory, without any slots'
                           ' there')

        if scratch_area.address % sector_size != 0:
            logger.error(
                'Scratch area address is 0x%x, but it should be aligned to '
                'sector size of 0x%x', scratch_area.address, sector_size)
            return False

        if scratch_area.size < sector_size:
            logger.error('Scratch area size 0x%x is less than sector size '
                         '0x%x', scratch_area.size, sector_size)
            return False

        return True

    def validate_flash_gaps(self):
        """
        Finds unused sectors in the internal flash memory map
        :return: True if there are no unused sectors, otherwise False
        """

        single_image = not self._is_multi_image()

        flash_res = {}
        for item in self.parser.json["boot_upgrade"]["firmware"]:
            if single_image and item["id"] == 16:
                continue
            for res in item["resources"]:
                if res["type"].startswith(("FLASH", "BOOT", "STATUS_PARTITION")):
                    flash_res[res["address"]] = res["address"] + res["size"]
                if res["type"].startswith("SCRATCH"):
                    if res["address"] < self.memory_map.EXTERNAL_MEM_START:
                        flash_res[res["address"]] = res["address"] + res["size"]
                if item["upgrade"] and res["type"].startswith("UPGRADE"):
                    if item["smif_id"] == 0:
                        flash_res[res["address"]] = res["address"] + res["size"]
        flash_starts = sorted(flash_res.keys())
        prev_key = 0
        result = True
        for key in flash_starts:
            if prev_key > 0:
                if key != flash_res[prev_key]:
                    logger.warning(
                        'There is a gap between regions %d:%d and %d:%d '
                        '(%d bytes)', prev_key, flash_res[prev_key], key,
                        flash_res[key], key - flash_res[prev_key])
                    result = False
            prev_key = key
        return result

    def _calc_status_partition_size(self, slot_name=None):
        """
        Calculates minimum sufficient status partition size
        for the specified slot
        :param slot_name: cm0 or cm4. If None, the maximum image size
        between both slots will be used
        :return: Status partition size in bytes
        """
        int_mem_sector_size = 512  # internal memory sector size
        ext_mem_sector_size = 256 * 1024  # external memory sector size
        trailer = int_mem_sector_size  # trailer is 64B, one slice is enough
        duplicates = 2  # status partition duplicates
        boot_max_size = self._max_image_size('BOOT', slot_name)
        if self.is_smif:
            sector_size = ext_mem_sector_size
        else:
            sector_size = int_mem_sector_size
        boot_sectors = boot_max_size / sector_size
        sector_count = ceil(boot_sectors / sector_size)
        dx = int_mem_sector_size * sector_count + trailer
        d = dx * duplicates
        d = d * 2  # add UPGRADE slot
        return d

    @staticmethod
    def _is_bootloader_slot(image_id):
        return image_id == 0

    @staticmethod
    def _is_cm0_slot(image_id):
        return image_id in [1, 2, 3]

    @staticmethod
    def _is_cm4_slot(image_id):
        return image_id in [4, 16]

    @staticmethod
    def _is_app_slot(image_id):
        return PolicyValidator._is_cm0_slot(image_id) or \
               PolicyValidator._is_cm4_slot(image_id)

    def _is_smif(self):
        for slot in self.parser.json['boot_upgrade']['firmware']:
            if 'smif_id' in slot and slot['smif_id'] > 0:
                return True
        return False

    def _max_image_size(self, image_type, slot_name=None):
        """
        Gets the maximum size between the images of the
        specified type and slot
        """
        img_max_size = 0
        max_size_list = dict()
        for slot in self.parser.json['boot_upgrade']['firmware']:
            for item in slot['resources']:
                if item['type'] == image_type:
                    if item['size'] > img_max_size:
                        if self._is_cm0_slot(slot['id']):
                            max_size_list['cm0'] = item['size']
                        if self._is_cm4_slot(slot['id']):
                            max_size_list['cm4'] = item['size']
        if 'cm0' == slot_name:
            img_max_size = max_size_list['cm0']
        elif 'cm4' == slot_name:
            img_max_size = max_size_list['cm4']
        else:
            try:
                img_max_size = max(max_size_list['cm0'], max_size_list['cm4'])
            except KeyError:
                img_max_size = list(max_size_list.values())[0]
        return img_max_size
