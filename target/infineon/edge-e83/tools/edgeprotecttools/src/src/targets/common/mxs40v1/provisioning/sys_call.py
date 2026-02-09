"""
Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from time import sleep

from .....core.enums import RegionHashStatus
from ..data import SfbStatusMXS40v1

# SysCall operation codes
READ_SILICON_ID_OPCODE = 0x00
READ_SILICON_ID_COMM = 0x01
REGION_HASH_OPCODE = 0x31
PROVISIONING_OPCODE = 0x33
ENCRYPTED_PROGRAMMING_OPCODE = 0x34
GET_PROV_DETAILS_OPCODE = 0x37
SET_DAP_CONTROL_OPCODE = 0x3A
TRANSITION_TO_RMA_OPCODE = 0x3B
OPEN_RMA_OPCODE = 0x29

# GetProvDetails SysCall codes
FB_POLICY_JWT = 0x100
FB_POLICY_IMG_CERTIFICATE = 0x300

logger = logging.getLogger(__name__)
sfb_status = SfbStatusMXS40v1()


def region_hash(tool, reg_map):
    """
    Procedure calls RegionHash syscall over IPC and read response.
    :param tool: Programming/debugging tool.
    :param reg_map: Device register map.
    :return: Region hash status
    """
    result = RegionHashStatus.OK
    logger.debug('Start RegionHash syscall')
    sram_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR
    address = reg_map.ENTRANCE_EXAM_REGION_HASH_ADDR
    length = reg_map.ENTRANCE_EXAM_REGION_HASH_SIZE
    mode = reg_map.ENTRANCE_EXAM_REGION_HASH_MODE
    exp_value = reg_map.ENTRANCE_EXAM_REGION_HASH_EXPECTED_VAL

    # Acquire IPC structure
    if not wait_acquire_ipc_struct(tool, reg_map):
        raise TimeoutError('Acquire IPC struct timeout.')

    # Set RAM address and Opcode
    op_code = (REGION_HASH_OPCODE << 24) + (exp_value << 16) + (mode << 8) + 0
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, sram_addr)
    tool.write32(sram_addr, op_code)

    scratch_addr = sram_addr + 0x08
    tool.write32(sram_addr + 0x04, scratch_addr)
    tool.write32(sram_addr + 0x08, length)
    tool.write32(sram_addr + 0x0C, address)

    # IPC_STRUCT[ipc_id].IPC_NOTIFY -
    tool.write32(reg_map.CYREG_IPC2_STRUCT_NOTIFY, 0x00000001)

    wait_release_ipc_struct(tool, reg_map)
    response = tool.read32(sram_addr)

    if (response & 0xFF000000) == 0xa0000000:
        logger.debug('RegionHash syscall passed')
    else:
        if response == sfb_status.code_by_name('CY_FB_INVALID_FLASH_OPERATION'):
            result = RegionHashStatus.FLASH_NOT_EMPTY
        else:
            logger.error('RegionHash syscall error: 0x%x', response)
            print_sfb_status(response)
            result = RegionHashStatus.FAIL

    return result


def transition_to_rma(tool, mem_map, reg_map, cert):
    """
    Converts parts from SECURE to RMA lifecycle stage
    @param tool: Programming/debugging tool.
    @param mem_map: Device memory map.
    @param reg_map: Device register map.
    @param cert: JWT packet signed by the key mentioned in the debug/RMA
           section of the policy, with authentication object including
           valid DIE_ID range.
    :return: True if the SysCall succeeds, otherwise False.
    """
    return _rma_syscall(tool, mem_map, reg_map, cert, 'TransitionToRMA')


def open_rma(tool, mem_map, reg_map, cert):
    """
    Enables full access to device in RMA lifecycle stage.
    @param tool: Programming/debugging tool.
    @param mem_map: Device memory map.
    @param reg_map: Device register map.
    @param cert: JWT packet signed by the key mentioned in the debug/RMA
           section of the policy, with authentication object including
           valid DIE_ID range.
    :return: True if the SysCall succeeds, otherwise False.
    """
    return _rma_syscall(tool, mem_map, reg_map, cert, 'OpenRMA')


def _rma_syscall(tool, mem_map, reg_map, cert, syscall_name):
    """
    Executes RMA system call.
    @param tool: Programming/debugging tool.
    @param reg_map: Device register map.
    @param cert: JWT packet signed by the key mentioned in the debug/RMA
           section of the policy, with authentication object including
           valid DIE_ID range.
    @param syscall_name: SysCall name - TransitionToRMA or OpenRMA.
    :return: True if the SysCall succeeds, otherwise False.
    """
    if len(cert) > mem_map.SRAM_SIZE:
        logger.error('JWT packet size (%s) exceeds SRAM_SCRATCH2 size (%s)',
                     len(cert), mem_map.SRAM_SIZE)
        return False

    if syscall_name == 'TransitionToRMA':
        op_code = TRANSITION_TO_RMA_OPCODE << 24
        sram_scratch_addr = mem_map.SRAM_ADDR
    elif syscall_name == 'OpenRMA':
        op_code = OPEN_RMA_OPCODE << 24
        sram_scratch_addr = mem_map.RAM_ADDR
    else:
        raise ValueError(f"Invalid SysCall name '{syscall_name}'")
    sram_scratch2_addr = sram_scratch_addr + 0x08

    if not wait_acquire_ipc_struct(tool, reg_map):
        raise TimeoutError('Acquire IPC struct timeout')

    logger.debug('Start %s syscall', syscall_name)
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, sram_scratch_addr)
    tool.write32(sram_scratch_addr, op_code)
    tool.write32(sram_scratch_addr + 0x04, sram_scratch2_addr)
    tool.write32(sram_scratch2_addr, len(cert))
    tool.write(sram_scratch2_addr + 0x04, [ord(char) for char in list(cert)])

    ipc_struct_notify(tool, reg_map)
    wait_release_ipc_struct(tool, reg_map)
    response = tool.read32(sram_scratch_addr)

    if (response & 0xFF000000) == 0xa0000000:
        logger.debug('%s syscall passed', syscall_name)
        return True
    logger.error('%s syscall error: 0x%x', syscall_name, response)
    print_sfb_status(response)
    return False


def get_prov_details(tool, reg_map, key_id):
    """
    Calls GetProvDetails syscall over IPC.
    :param tool: Programming/debugging tool.
    :param key_id: Public key ID.
    :param reg_map: Device register map.
    :return: True if syscall succeeds, otherwise False.
    """
    logger.debug('Start GetProvDetails syscall')
    sram_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR

    # Acquire IPC structure
    if not wait_acquire_ipc_struct(tool, reg_map):
        raise TimeoutError('Acquire IPC struct timeout.')

    # Set RAM address and Opcode
    op_code = GET_PROV_DETAILS_OPCODE << 24
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, sram_addr)  # IPC_STRUCT.DATA
    tool.write32(sram_addr, op_code)  # SRAM_SCRATCH

    scratch_addr = sram_addr + 0x08
    tool.write32(sram_addr + 0x04, scratch_addr)
    tool.write32(sram_addr + 0x08, key_id)
    tool.write32(sram_addr + 0x0C, 0x0)

    # IPC_STRUCT[ipc_id].IPC_NOTIFY -
    tool.write32(reg_map.CYREG_IPC2_STRUCT_NOTIFY, 0x00000001)

    # Wait for response
    wait_release_ipc_struct(tool, reg_map)
    response = tool.read32(sram_addr)

    log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    log_reg_value(tool, sram_addr)
    log_reg_value(tool, sram_addr + 0x04)
    log_reg_value(tool, sram_addr + 0x08)

    is_exam_pass = (response & 0xFF000000) == 0xa0000000
    if is_exam_pass:
        scratch_addr = tool.read32(sram_addr + 0x04)
        read_hash_size = tool.read32(scratch_addr + 0x00)
        read_hash_addr = tool.read32(scratch_addr + 0x04)

        # Avoid race condition when the bootloader does flash
        # erasing at the moment the tool reads JWT packet from
        # the same sector
        counter = 0
        timeout = 10
        while True:
            try:
                data = tool.read(read_hash_addr, read_hash_size)
                break
            except RuntimeError as e:
                if counter < timeout:
                    sleep(1)
                    counter += 1
                else:
                    raise e
        prov_details = bytes(data).decode()
        logger.debug("prov_details = '%s'", prov_details)
        logger.debug('GetProvDetails syscall passed')
    else:
        logger.debug('GetProvDetails syscall error: 0x%x', response)
        print_sfb_status(response, severity='debug')
        prov_details = None

    return is_exam_pass, prov_details


def provision_keys_and_policies(tool, filename, reg_map):
    """
    Calls ProvisionKeysAndPolicies syscall over IPC.
    :param tool: Programming/debugging tool.
    :param filename: Path to provisioning JWT file.
    :param reg_map: Device register map.
    :return: Tuple with the syscall result and device response
    """
    logger.debug('Start ProvisionKeysAndPolicies syscall')
    logger.debug("Apply JWT '%s'", filename)
    if filename:
        file_size = os.path.getsize(filename)
        if file_size > reg_map.ENTRANCE_EXAM_SRAM_SIZE:
            logger.error('JWT packet too long')
            return False

        logger.info('JWT packet size = %d', file_size)
        with open(filename, 'r+', encoding='utf-8') as jwt_file:
            jwt_file.seek(0)
            content = jwt_file.read()
        jwt_chars = list(content)
    else:
        file_size = 0
        jwt_chars = list()

    # Acquire IPC structure
    logger.debug('Acquire IPC structure')
    if not wait_acquire_ipc_struct(tool, reg_map):
        raise TimeoutError('Acquire IPC struct timeout.')
    else:
        log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_ACQUIRE)

    # Set RAM address and Opcode
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA,
                 reg_map.ENTRANCE_EXAM_SRAM_ADDR)
    log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR, (PROVISIONING_OPCODE << 24))
    log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR)

    scratch_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08
    tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x04, scratch_addr)
    log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x04)
    tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08, file_size + 0x04)
    log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08)
    scratch_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x0C

    tool.write(scratch_addr, [ord(char) for char in jwt_chars])

    if not jwt_chars:
        sleep(1)

    ipc_struct_notify(tool, reg_map)
    wait_release_ipc_struct(tool, reg_map)
    logger.debug('Reading response')

    # Read response for test
    log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR)

    status = tool.read32(reg_map.ENTRANCE_EXAM_SRAM_ADDR)
    result = (status & 0xFF000000) == 0xa0000000
    response = None

    if result:
        logger.debug('ProvisionKeysAndPolicies syscall passed')
        response = read_device_response(tool, reg_map)
    else:
        if filename:
            logger.error(
                'ProvisionKeysAndPolicies syscall error: 0x%x', status)
            print_sfb_status(status)
        else:
            syscall_invalid_arg = sfb_status.code_by_name(
                'CY_FB_SYSCALL_INVALID_ARGUMENT')
            if status == syscall_invalid_arg:
                response = read_device_response(tool, reg_map)
                result = True  # it is expected when no JWT packet specified
    return result, response


def encrypted_programming(tool, reg_map, mode, data, host_key_id=0,
                          dev_key_id=0, addr=None):
    """
    Calls EncryptedProgramming syscall over IPC.
    :param tool: Programming/debugging tool.
    :param reg_map: Device register map.
    :param mode: Syscall Mode: 0x00 - Init, 0x01 - Data, 0x02 - Finish.
    :param data: The data to program.
    :param host_key_id: Host private key ID (4 - HSM, 5 - OEM).
    :param dev_key_id: Device public key ID (1 - device, 12 - group).
    :param addr: Data address (used for Data mode only).
    :return: True if syscall succeeds, otherwise False.
    """
    logger.debug('Start EncryptedProgramming syscall')
    # Encrypted programming modes
    mode_init = 0x00
    mode_data = 0x01
    mode_finish = 0x02

    sram_addr_claimed = reg_map.ENTRANCE_EXAM_SRAM_ADDR + (
            reg_map.ENTRANCE_EXAM_SRAM_SIZE >> 1)

    data_size = 0 if mode == mode_finish else len(data)
    program_row_size = int(data_size / 2)

    # Acquire IPC structure
    wait_acquire_ipc_struct(tool, reg_map)

    # Set RAM address and Opcode
    op_code = (ENCRYPTED_PROGRAMMING_OPCODE << 24) + (host_key_id << 16) + \
              (dev_key_id << 8) + int(mode)

    logger.debug('Write registers:')
    logger.debug('0x%x <- 0x%x',
                 reg_map.CYREG_IPC2_STRUCT_DATA, sram_addr_claimed)
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, sram_addr_claimed)

    logger.debug('0x%x <- 0x%x', sram_addr_claimed, op_code)
    tool.write32(sram_addr_claimed, op_code)

    scratch_addr = sram_addr_claimed + 0x08
    logger.debug('0x%x <- 0x%x', sram_addr_claimed + 0x04, scratch_addr)
    tool.write32(sram_addr_claimed + 0x04, scratch_addr)

    logger.debug('0x%x <- 0x%x', sram_addr_claimed + 0x08, data_size >> 1)
    tool.write32(sram_addr_claimed + 0x08, data_size >> 1)
    scratch_addr = sram_addr_claimed + 0x0C

    logger.debug('Clear RAM')
    tool.write(scratch_addr, bytes(512))

    scratch_addr = sram_addr_claimed + 0x0C

    if mode_init == mode:
        logger.debug('Write AES header to RAM')
        data_bytes = [int(data[i:i + 2], 16) for i in range(0, len(data), 2)]
        tool.write(scratch_addr, data_bytes)
    elif mode_data == mode:
        tool.write32(sram_addr_claimed + 0x08, program_row_size)
        tool.write32(scratch_addr, addr)
        scratch_addr += 4
        logger.debug('Write data to RAM')
        data_bytes = [int(data[i:i + 2], 16) for i in range(0, len(data), 2)]
        tool.write(scratch_addr, data_bytes)

    # Read written data
    logger.debug('Read registers:')
    log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    log_reg_value(tool, sram_addr_claimed)
    log_reg_value(tool, sram_addr_claimed + 0x04)
    log_reg_value(tool, sram_addr_claimed + 0x08)
    log_reg_value(tool, sram_addr_claimed + 0x0C)

    ipc_struct_notify(tool, reg_map)

    wait_release_ipc_struct(tool, reg_map)

    response = tool.read32(sram_addr_claimed)

    # Read response for test
    log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    log_reg_value(tool, sram_addr_claimed)
    log_reg_value(tool, sram_addr_claimed + 0x04)
    log_reg_value(tool, sram_addr_claimed + 0x08)
    log_reg_value(tool, sram_addr_claimed + 0x0C)

    if response & 0xFF000000 == 0xa0000000:
        logger.debug('EncryptedProgramming syscall passed')
        return True
    else:
        logger.error('EncryptedProgramming syscall error: 0x%x', response)
        print_sfb_status(response)
        return False


def dap_control(tool, reg_map, cpu_id, desired_state, jwt_not_required,
                filename):
    """
    Calls DAPControl SysCall over IPC
    :param tool: Programming/debugging tool
    :param reg_map: Device register map
    :param cpu_id: CPU ID (0-CM0, 1-CM4, 2-SYS)
    :param desired_state: The state to be set for the AP
    :param jwt_not_required: Indicates whether SysCall can control the
           DAP with (control is set to 'certificate') or without
           (control is set to 'open') a signed certificate (JWT)
    :param filename: Path to the certificate (JWT)
    :return: True if SysCall succeeds, otherwise False
    """
    if cpu_id == 0:
        logger.debug('Config cm0 AP, desired state = %d', desired_state)
    elif cpu_id == 1:
        logger.debug('Config cm4 AP, desired state = %d', desired_state)
    elif cpu_id == 2:
        logger.debug('Config system AP, desired state = %d', desired_state)
    else:
        raise ValueError(f'Invalid CPU ID {cpu_id}')

    wait_acquire_ipc_struct(tool, reg_map)

    disable_jwt_use = 1 if jwt_not_required else 0
    op_code = (SET_DAP_CONTROL_OPCODE << 24) + (desired_state << 16) + (cpu_id << 8) + disable_jwt_use

    if jwt_not_required:
        logger.debug('JWT is NOT required')
        tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, op_code)
        log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
    else:
        logger.debug('JWT is required')
        if not filename:
            raise ValueError('JWT certificate is required but not specified')
        logger.info("Apply certificate '%s'", filename)

        file_size = os.path.getsize(filename)
        if file_size > reg_map.ENTRANCE_EXAM_SRAM_SIZE:
            logger.error('JWT packet too long')
            return False

        logger.debug('JWT packet size: %d', file_size)
        with open(filename, 'r+', encoding='utf-8') as jwt_file:
            jwt_file.seek(0)
            content = jwt_file.read()
        jwt_chars = list(content)

        # Set RAM address and Opcode
        tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA,
                     reg_map.ENTRANCE_EXAM_SRAM_ADDR)
        tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR, op_code)
        scratch_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08
        tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x04, scratch_addr)
        tool.write32(reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08, file_size)
        scratch_addr = reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x0C

        tool.write(scratch_addr, [ord(char) for char in jwt_chars])

        log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR)
        log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x04)
        log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x08)
        log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x0C)

    ipc_struct_notify(tool, reg_map)
    wait_release_ipc_struct(tool, reg_map)

    if jwt_not_required:
        response = tool.read32(reg_map.CYREG_IPC2_STRUCT_DATA)
    else:
        response = tool.read32(reg_map.ENTRANCE_EXAM_SRAM_ADDR)

    if response & 0xFF000000 == 0xa0000000:
        logger.debug('DAP_Control SysCall passed')
        return True
    else:
        logger.error('DAP_Control SysCall error: 0x%x', response)
        print_sfb_status(response)
        log_reg_value(tool, reg_map.CYREG_IPC2_STRUCT_DATA)
        log_reg_value(tool, reg_map.ENTRANCE_EXAM_SRAM_ADDR)
        return False


def read_lifecycle(tool, reg_map):
    """
    Reads device lifecycle
    :param tool: Programming/debugging tool.
    :param reg_map: Device register map.
    :return: The value that indicates device current lifecycle
    """
    tool.write32(reg_map.CYREG_IPC2_STRUCT_ACQUIRE, 0x80000000)
    ipc_acquire = 0
    while (ipc_acquire & 0x80000000) == 0:
        ipc_acquire = tool.read32(reg_map.CYREG_IPC2_STRUCT_ACQUIRE)
    # Set RAM address and Opcode
    tool.write32(reg_map.CYREG_IPC2_STRUCT_DATA, (READ_SILICON_ID_OPCODE << 24)
                 + (READ_SILICON_ID_COMM << 8) + 1)
    tool.write32(reg_map.CYREG_IPC2_STRUCT_NOTIFY, 0x00000001)
    # Wait for response
    wait_release_ipc_struct(tool, reg_map)
    response = tool.read32(reg_map.CYREG_IPC2_STRUCT_DATA)
    if response & 0xFF000000 == 0xa0000000:
        return (response >> 16) & 0x0f


def read_device_response(tool, reg_map):
    """
    Reads device JWT response after provisioning syscall execution
    """
    scratch_addr = tool.read32(reg_map.ENTRANCE_EXAM_SRAM_ADDR + 0x04)
    resp_size = tool.read32(scratch_addr)
    resp_addr = tool.read32(scratch_addr + 0x04)
    logger.debug('Device response address = 0x%x', resp_addr)
    logger.debug('Device response size = %d', resp_size)
    data = tool.read(resp_addr, resp_size)
    response = bytes(data).decode()
    logger.info("Device response = '%s'", response)
    return response


def wait_acquire_ipc_struct(tool, reg_map, timeout=5000):
    """
    Wait for acquires IPC structure.
    :param tool: Programming/debugging tool.
    :param reg_map: Device register map.
    :param timeout: Timeout to acquire structure.
    :return: IPC acquire status (True or False)
    """
    logger.debug('Start wait_acquire_ipc_struct')
    tool.write32(reg_map.CYREG_IPC2_STRUCT_ACQUIRE, 0x80000000)

    count = 0
    ipc_acquire = 0
    while (ipc_acquire & 0x80000000) == 0 and count < timeout:
        ipc_acquire = tool.read32(reg_map.CYREG_IPC2_STRUCT_ACQUIRE)
        count += 1
        sleep(0.2)
    if count >= timeout:
        raise TimeoutError('IPC structure release timeout')

    result = (ipc_acquire & (1 << 31)) != 0
    logger.debug("wait_acquire_ipc_struct result '0x%x'", result)
    return result


def wait_release_ipc_struct(tool, reg_map, timeout=300):
    """
    Wait for release IPC structure.
    @param tool: Programming/debugging tool.
    @param reg_map: Device register map.
    @param timeout: Timeout to release structure.
    @return: IPC acquire status (True or False)
    """
    logger.debug('Start wait_release_ipc_struct')
    response = 0x80000000
    count = 0
    while (response & 0x80000000) != 0 and count < timeout:
        response = tool.read32(reg_map.CYREG_IPC2_STRUCT_LOCK_STATUS)
        count += 1
        sleep(0.2)
    if count >= timeout:
        raise TimeoutError('IPC structure release timeout')
    result = response & (1 << 31)
    logger.debug("wait_release_ipc_struct result '0x%x'", result)
    return result != 0


def ipc_struct_notify(tool, reg_map):
    """
    IPC_STRUCT[ipc_id].IPC_NOTIFY
    @param tool: Programming/debugging tool.
    @param reg_map: Device register map.
    """
    logger.debug('ipc_struct_notify')
    tool.write32(reg_map.CYREG_IPC2_STRUCT_NOTIFY, 0x00000001)


def print_sfb_status(status_code, severity='error'):
    """
    Outputs SFB status description
    :param status_code: SFB status code
    :param severity: The severity of the status message
    """
    try:
        status = sfb_status.status_codes()[status_code]
        msg = f'SFB status: {status["status"]}: {status["desc"]}'
        if severity == 'error':
            logger.error(msg)
        elif severity == 'warning':
            logger.warning(msg)
        elif severity == 'info':
            logger.info(msg)
        elif severity == 'debug':
            logger.debug(msg)
        else:
            raise ValueError('Invalid severity argument')
    except KeyError:
        logger.debug('Unexpected SFB status 0x%x', status_code)


def log_reg_value(tool, register):
    """ Outputs register value for debugging """
    logger.debug('0x%x 0x%x', register, tool.read32(register))
