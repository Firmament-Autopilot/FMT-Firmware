"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import sys
import shutil
import logging
import traceback

import json
import click

from .pkg_globals import PkgData
from . import ProvisioningPackage

from .api_common import CommonAPI
from .core.certificate_strategy import CertificateStrategyV1
from .core.version_provider import VersionProvider
from .core.target_director import TargetDirector
from .core.logging_configurator import LoggingConfigurator
from .core.project_base import ProjectInitializerBase
from .core.mtb_tools_discovery import mtb_tool_dir, ptp_tool_dir
from .execute.programmer.programmer import ProgrammingTool
from .execute.imgtool.main import get_dependencies, validate_security_counter
from .targets import get_target_builder
from .targets import print_targets, print_targets_extended

logger = logging.getLogger(__name__)


def require_target():
    """Indicates whether sys.argv contains a command that require target
    option"""
    commands = [
        'device-list', 'version', 'probe-list', 'set-ocd', 'bin2hex',
        'convert-key', 'sign-image', 'image-metadata', 'extract-payload',
        'add-signature', 'verify-image', 'serial-config'
    ]
    return not any(x in sys.argv for x in commands)


def get_output_nargs():
    """Based on key type defines number of output arguments"""
    if '--key-type' in sys.argv:
        if sys.argv[sys.argv.index('--key-type') + 1].upper() in \
                ['AES128', 'AES256'] \
                or '--template' in sys.argv:
            return 1
    return 2


@click.group(chain=True)
@click.pass_context
@click.option('-t', '--target', help='Device name or family')
@click.option('--rev', help='Device revision')
@click.option('-p', '--policy', type=click.File(), required=False,
              help='Provisioning policy file')
@click.option('-v', '--verbose', is_flag=True, help='Provides debug-level log')
@click.option('-q', '--quiet', is_flag=True, help='Quiet display option')
@click.option('--logfile-off', is_flag=True, help='Avoids logging into file')
@click.option('--timestamps', is_flag=True,
              help='Enable displaying timestamps in log messages')
@click.option('--alt-user-dir', help='Alternative package user data directory')
@click.option('--no-interactive-mode', is_flag=True, hidden=True,
              help='Skips user interactive prompts')
@click.option('--skip-validation', is_flag=True, hidden=True,
              help='Skips policy validation')
def main(ctx, target, rev, policy, verbose, quiet, logfile_off, timestamps,
         alt_user_dir, no_interactive_mode, skip_validation):
    """
    Common options (e.g. -t, --rev, -p, -v, -q, --timestamps) are common
    for all commands and must precede them:

    <PACKAGE_NAME> -t <TARGET> -p <POLICY> <COMMAND> --<COMMAND_OPTION>

    To see command options:

    <PACKAGE_NAME> <COMMAND> --help
    """
    if quiet:
        LoggingConfigurator.disable_logging()
    elif verbose:
        LoggingConfigurator.set_logger_level(logging.DEBUG)
    logger.debug(sys.argv)

    ctx.ensure_object(dict)
    log_file = not logfile_off

    if 'init' in sys.argv:
        validate_init_cmd_args()
        try:
            policy_path = default_policy(target, rev=rev)
        except ValueError as e:
            logger.error(e)
            sys.exit(2)
        log_file = False
    else:
        policy_path = policy.name if policy else None
    try:
        ctx.obj['TOOL'] = ProvisioningPackage(
            target=target,
            policy=policy_path,
            log_file=log_file,
            skip_prompts=no_interactive_mode,
            skip_validation=skip_validation,
            rev=rev,
            alt_user_dir=alt_user_dir,
            timestamps=timestamps,
        )
    except ValueError as e:
        logger.error(e)
        sys.exit(2)


@main.result_callback()
def process_pipeline(processors, **_):
    for func in processors:
        res = func()
        if not res:
            sys.stderr.write('Failed processing!\n')
            sys.exit(2)


@main.command('build-ramapp-package',
              help='Builds the RAM application and it\'s inputs into a single '
                   'signed package')
@click.option('-a', '--app', type=click.Path(), required=True,
              help='RAM application binary')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='RAM application package output file')
@click.option('--inparams', type=click.Path(),
              help='Application input parameters')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='Private key to sign the package')
@click.option('--hex-addr', help='Adjust address in hex output file')
@click.option('-S', '--slot-size', help='Sets the maximum slot size')
@click.pass_context
def cmd_build_ramapp_package(ctx, app, output, inparams, key, hex_addr,
                             slot_size):
    """Builds RAM Application package"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].build_ramapp_package(
            app, output, key, input_params=inparams, hex_addr=hex_addr,
            slot_size=slot_size)

    return process


@main.command('create-cert', hidden=True,
              help='Creates certificate from template')
@click.option('--template', type=click.Path(), required=True,
              help='CSR or Certificate template path')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path where to save the CSR or Certificate')
@click.option('--json-cert', type=click.Path(),
              help='The path where to save CSR or certificate JSON data')
@click.option('--csr', type=click.Path(), help='The CSR path')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign the certificate')
@click.option('--sign-key-0', type=click.Path(),
              help='Primary key used to sign the CSR')
@click.option('--sign-key-1', type=click.Path(),
              help='Secondary key used to sign the CSR')
@click.pass_context
def cmd_create_cert(
        ctx, template, output, json_cert, csr, key, sign_key_0, sign_key_1):
    """Creates certificate"""
    @process_handler()
    def process():
        validate_args()
        if 'TOOL' not in ctx.obj:
            return False
        key_path = key if key else (sign_key_0, sign_key_1)
        result = ctx.obj['TOOL'].create_cert(output, template=template,
                                             key_path=key_path, csr=csr,
                                             json_cert=json_cert)
        return result

    def validate_args():
        if key and (sign_key_0 or sign_key_1):
            sys.stderr.write("Error: The '--key' and '--sign-key-0/"
                             "--sign-key-1' options are mutually exclusive.\n")
            sys.exit(2)

        if sign_key_1 and not sign_key_0:
            sys.stderr.write("Error: Missing option '--sign-key-0'.\n")
            sys.exit(2)

        cert_data = CertificateStrategyV1.load_cert_template(template)
        if cert_data.get('TEMPLATE_TYPE') == 'OEM_CSR' and key:
            sys.stderr.write("Error: The '--key' option is not applicable for "
                             "OEM CSR. Use '--sign-key-0' and '--sign-key-1' "
                             "options.\n")
            sys.exit(2)

    return process


@main.command('oem-csr', help='Creates OEM CSR')
@click.option('--certificate-name', help='The certificate name')
@click.option('--oem', required=True, help='The OEM name')
@click.option('--project', required=True,
              help='The OEM project name')
@click.option('--project-number', required=True,
              help='The OEM project number')
@click.option('--issuer', help='The issuer name')
@click.option('--signer-id', help='The signer ID')
@click.option('--public-key-0', type=click.Path(), required=True,
              help='Primary public key path')
@click.option('--public-key-1', type=click.Path(),
              help='Secondary public key path')
@click.option('--cert-type', type=click.Choice(['development', 'production'],
              case_sensitive=False), required=True,
              help='Defines the "LCS" of the project')
@click.option('--date', help='The CSR creation date. The date-time string of '
                             'the following format: YYYY-MM-DD HH:MM:SS. '
                             'Example: 2025-03-12 15:59:23')
@click.option('--id', 'cert_id', help='The certificate ID')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='CSR path')
@click.option('--sign-key-0', type=click.Path(),
              help='Primary key used to sign the CSR')
@click.option('--sign-key-1', type=click.Path(),
              help='Secondary key used to sign the CSR')
@click.option('--algorithm-0',
              type=click.Choice(['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
                                case_sensitive=False),
              hidden=True, help='Primary signature algorithm')
@click.option('--algorithm-1',
              type=click.Choice(['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
                                case_sensitive=False),
              hidden=True, help='Secondary signature algorithm')
@click.pass_context
def cmd_create_oem_csr(
        ctx, certificate_name, oem, project, project_number, issuer, signer_id,
        public_key_0, public_key_1, cert_type, date, cert_id, output,
        sign_key_0, sign_key_1, algorithm_0, algorithm_1):
    """Creates OEM CSR"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        sign_keys = (sign_key_0, sign_key_1)
        algorithms = (algorithm_0, algorithm_1)
        validate()
        result = ctx.obj['TOOL'].oem_csr(certificate_name=certificate_name,
                                         oem=oem, project=project,
                                         project_number=project_number,
                                         issuer=issuer, signer_id=signer_id,
                                         public_key_0=public_key_0,
                                         public_key_1=public_key_1,
                                         cert_type=cert_type, date=date,
                                         cert_id=cert_id, output=output,
                                         key_path=sign_keys,
                                         algorithms=algorithms,
                                         use_adapter=True)
        return result

    def validate():
        if all((sign_key_0, sign_key_1)) and all((algorithm_0, algorithm_1)):
            sys.stderr.write("Error: The options '--sign-key-0' and "
                             "'--sign-key-1' are mutually exclusive "
                             "with the options '--algorithm-0' and "
                             "'--algorithm-1'.\n")
            sys.exit(2)

        if all((algorithm_0, algorithm_1)) and algorithm_0 != algorithm_1:
            sys.stderr.write("Error: The options '--algorithm-0' and "
                             "'--algorithm-1' must be the same.\n")
            sys.exit(2)

    return process


@main.command('ifx-oem-cert', help='Creates IFX OEM certificate')
@click.option('--certificate-name', help='The certificate name')
@click.option('--issuer', help='The issuer name')
@click.option('--signer-id', required=True,
              help='The unique ID of the certificate that corresponds to the '
                   'signing key')
@click.option('--date', help='The date of the OEM certificate creation '
                             '(YYYY-MM-DDTHH:MM:SS)')
@click.option('--id', 'cert_id', required=True,
              help='The unique serial number for the certificate')
@click.option('--csr', '--csr-path', 'csr', type=click.Path(), required=True,
              help='The path to the OEM CSR')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The certificate path')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign the certificate')
@click.option('--algorithm',
              type=click.Choice(['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
                                case_sensitive=False),
              help='The signature algorithm')
@click.pass_context
def cmd_ifx_oem_cert(
        ctx, certificate_name, issuer, signer_id, date, cert_id, csr, output,
        key, algorithm):
    """Creates IFX OEM certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate()
        result = ctx.obj['TOOL'].ifx_oem_cert(
            certificate_name=certificate_name, issuer=issuer, output=output,
            signer_id=signer_id, date=date, cert_id=cert_id, csr=csr,
            key_path=key, algorithm=algorithm, use_adapter=True)
        return result

    def validate():
        if not algorithm and not key:
            sys.stderr.write("Error: The '--algorithm' or '--key' option "
                             "must be specified.\n")
            sys.exit(2)

        if algorithm and key:
            sys.stderr.write("Error: The '--algorithm' and '--key' options "
                             "are mutually exclusive.\n")
            sys.exit(2)

    return process


@main.command('run-config', help='Executes commands specified in JSON file')
@click.option('-i', '--input', 'infile', type=click.Path(), required=True,
              help='Input file')
@click.option('-s', '--set', 'variable', required=False, nargs=2, default=[],
              multiple=True, metavar='[variable] [value]',
              help='Sets a value for variable interpolation')
@click.option('--symbol-search', type=click.Path(), required=False,
              help='Directory to search for symbol files')
@click.option('--symbol', type=click.Path(), required=False, multiple=True,
              help='Path to a symbol file (can be specified multiple times)')
@click.pass_context
def cmd_run_config(ctx, infile, variable, symbol, symbol_search):
    """Executes commands specified in JSON file"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].run_config(
            infile,
            variable=variable,
            symbol=symbol,
            symbol_search=symbol_search
        )

    return process


@main.command('power-on', hidden=True, help='Turns the power on')
@click.option('-v', '--voltage', type=click.INT,
              help='Sets target power voltage in mV')
@click.option('--probe-id', help='Probe serial number')
@click.pass_context
def cmd_power_on(ctx, voltage, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].power_on(voltage, probe_id=probe_id)

    return process


@main.command('power-off', hidden=True, help='Turns the power off')
@click.option('--probe-id', help='Probe serial number')
@click.pass_context
def cmd_target_power_off(ctx, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].power_off(probe_id=probe_id)

    return process


@main.command('device-list', help='List of supported devices')
@click.option('--extended', hidden=True, is_flag=True,
              help='Provides targets extended data')
@click.pass_context
def cmd_device_list(_ctx, extended):
    @process_handler()
    def process():
        if extended:
            print_targets_extended()
        else:
            print_targets()
        return True

    return process


@main.command('probe-list', hidden=True,
              help='Prints a list of connected probes')
@click.pass_context
def cmd_probe_list(_ctx):
    """Prints a list of connected probes"""
    @process_handler()
    def process():
        sys.stderr.write(
            "Error: The selected OCD does not support this feature.\n")
        return True

    return process


@main.command('set-ocd', help='Sets on-chip debugger')
@click.option('-n', '--name', required=True, help='Tool name',
              type=click.Choice(['openocd', 'serial', 'chipload']))
@click.option('-p', '--path', default='',
              help='Path to the tool root directory')
@click.option('-c', '--config', default='', help='Path to the target config')
@click.pass_context
def cmd_set_ocd(_ctx, name, path, config):
    @process_handler()
    def process():
        ocd_config = config
        ocd_path = path
        tool = ProgrammingTool.create(name)

        if not os.path.isfile(PkgData.pkg_settings()):
            os.makedirs(PkgData.pkg_user_data_dir(), exist_ok=True)
            shutil.copyfile(
                os.path.join(PkgData.pkg_data_dir(), 'global_settings.json'),
                PkgData.pkg_settings())

        if ProjectInitializerBase.is_project():
            if not ocd_path and tool.require_path:
                with open(PkgData.pkg_settings(), 'r', encoding='utf-8') as f:
                    data = json.load(f)
                if name == data['programming_tool']['name'] and \
                        data['programming_tool']['path']:
                    ocd_path = data['programming_tool']['path']
                    logger.info("The OCD path is not specified. "
                                "Global settings applied: '%s'", ocd_path)
                else:
                    ocd_path = ''

                if not validate_mtb(name, ocd_path):
                    return False

            ProjectInitializerBase.set_ocd_data(name, ocd_path, ocd_config)
            logger.info('Data in the project settings file changed')
        else:
            with open(PkgData.pkg_settings(), 'r', encoding='utf-8') as f:
                data = json.load(f)
            data['programming_tool']['name'] = name
            data['programming_tool']['path'] = ocd_path
            data['programming_tool']['config'] = ocd_config

            if not (validate_mtb(name, ocd_path)
                    or validate_ptp(name, ocd_path)):
                return False

            with open(PkgData.pkg_settings(), 'w', encoding='utf-8') as f:
                json.dump(data, f, indent=4)
            logger.info('Data in the package settings file changed')

        if tool.require_path and ocd_path and not os.path.exists(ocd_path):
            logger.warning("Path '%s' does not exist", ocd_path)

        return True

    def validate_mtb(tool_name, tool_path):
        """Validates the presence of MTB in the system"""

        tool_map = {
            'openocd': 'openocd',
            'serial': 'dfuh-tool'
        }

        if not tool_path:
            logger.info("The OCD path is not specified. "
                        "Tool autodiscovery applied")
            if not mtb_tool_dir(tool_map[tool_name]):
                logger.error('MTB not found.')
                return False
        return True

    def validate_ptp(tool_name, tool_path):
        """Validates the presence of PTP in the system"""

        tool_map = {
            'openocd': 'openocd'
        }

        if not tool_path:
            logger.info("The OCD path is not specified. "
                        "Tool autodiscovery applied")
            if tool_name not in tool_map:
                return False
            if not ptp_tool_dir(tool_map[tool_name]):
                logger.error('PTP not found.')
                return False
        return True

    return process


@main.command('serial-config', help='Configures serial interface')
@click.option('--protocol', help='Serial communication protocol',
              type=click.Choice(['uart', 'i2c', 'spi', 'can-fd'],
                                case_sensitive=False))
@click.option('--hwid', help='Specifies the ID of the hardware. If this option '
                             'is skipped, the first appropriate device found '
                             'will be used.')
@click.option('--uart-baudrate', type=click.INT,
              help='Sets the baud rate for the UART protocol')
@click.option('--uart-databits', type=click.INT,
              help='Sets the number of data bits for the UART protocol')
@click.option('--uart-paritytype',
              type=click.Choice(['None', 'Odd', 'Even'], case_sensitive=False),
              help='Sets the parity type for the UART protocol')
@click.option('--uart-stopbits', type=click.Choice(['1', '1.5', '2']),
              help='Sets the stop bits for the UART protocol')
@click.option('--i2c-address', type=click.IntRange(8, 120),
              help='Sets the address for the I2C protocol')
@click.option('--i2c-speed', type=click.Choice(['50', '100', '400', '1000']),
              help='Sets the speed for the I2C protocol in kHz')
@click.option('--spi-clockspeed', type=click.FLOAT,
              help='Sets the clock speed for the SPI protocol in MHz')
@click.option('--spi-mode', type=click.Choice(['00', '01', '10', '11']),
              help='Sets the mode for the SPI protocol in binary')
@click.option('--spi-lsb-first', is_flag=True,
              help='Specifies that the least-significant bit should be sent '
                   'first for the SPI protocol. Otherwise, the '
                   'most-significant bit will be sent first')
@click.option('--canfd-bitrate', type=click.INT,
              help='Sets the communication bitrate for CAN-FD protocol')
@click.option('--canfd-data-bitrate', type=click.INT,
              help='Sets the data communication bitrate for CAN-FD protocol')
@click.option('--canfd-output-frame-id', type=click.INT,
              help='Sets output frame ID for CAN-FD protocol')
@click.option('--canfd-input-frame-id', type=click.INT,
              help='Sets input frame ID for CAN-FD protocol (optional)')
@click.option('--canfd-enable-bitrate-switch', is_flag=True,
              help='Enables switching between default and data bitrates '
                   'for CAN-FD protocol')
@click.option('--canfd-ext-frame', is_flag=True,
              help='Enables extended frame support for CAN-FD protocol')
@click.pass_context
def cmd_serial_config(_ctx, protocol, hwid, uart_baudrate, uart_paritytype,
                      uart_databits, uart_stopbits, i2c_address, i2c_speed,
                      spi_clockspeed, spi_mode, spi_lsb_first,
                      canfd_bitrate, canfd_data_bitrate, canfd_output_frame_id,
                      canfd_input_frame_id, canfd_enable_bitrate_switch,
                      canfd_ext_frame):
    """Configures serial interface"""
    @process_handler()
    def process():
        def set_serial_data(filename=None):
            ProjectInitializerBase.set_serial_config(
                filename, protocol=protocol, hwid=hwid,
                uart_baudrate=uart_baudrate, uart_paritytype=uart_paritytype,
                uart_stopbits=uart_stopbits, uart_databits=uart_databits,
                i2c_address=i2c_address, i2c_speed=i2c_speed,
                spi_clockspeed=spi_clockspeed, spi_mode=spi_mode,
                spi_lsb_first=spi_lsb_first,
                canfd_bitrate=canfd_bitrate,
                canfd_data_bitrate=canfd_data_bitrate,
                canfd_output_frame_id=canfd_output_frame_id,
                canfd_input_frame_id=canfd_input_frame_id,
                canfd_enable_bitrate_switch=canfd_enable_bitrate_switch,
                canfd_ext_frame=canfd_ext_frame
            )

        if not os.path.isfile(PkgData.pkg_settings()):
            os.makedirs(PkgData.pkg_user_data_dir(), exist_ok=True)
            shutil.copyfile(
                os.path.join(PkgData.pkg_data_dir(), 'global_settings.json'),
                PkgData.pkg_settings())

        if ProjectInitializerBase.is_project():
            set_serial_data()
            logger.info('Data in the project settings file changed')
        else:
            set_serial_data(PkgData.pkg_settings())
            logger.info('Data in the package settings file changed')
        return True

    return process


@main.command('serial-ports',
              help='Outputs compatible hardware connected to the computer')
@click.pass_context
def cmd_serial_ports(ctx):
    """Checks compatible hardware connected to the computer"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        api = CommonAPI()

        if api.tool and api.tool.name == 'serial':
            ports = api.get_probe_list()
            if ports:
                for port in ports:
                    print(port.strip())
            else:
                print('No compatible hardware found', file=sys.stderr)
        else:
            sys.stderr.write(
                'Error: The selected OCD does not support this feature.\n')
        return True

    return process


@main.command('version', short_help='Shows package version info')
@click.pass_context
def cmd_version(_ctx):
    """Prints the package name, version, and source of installed
    distribution
    """
    @process_handler()
    def process():
        dist_info = VersionProvider.dist_info()
        print(f'Name: {dist_info["name"]}')
        print(f'Version: {dist_info["version"]}')

        if dist_info.get('url'):
            print(f'URL: {dist_info.get("url")}')

        vcs_info = dist_info.get('vcs_info')
        if vcs_info:
            if vcs_info.get('requested_revision'):
                print(
                    f'Requested revision: {vcs_info.get("requested_revision")}')
            if vcs_info.get('commit_id'):
                print(f'Commit: {vcs_info.get("commit_id")}')

        archive_info = dist_info.get('archive_info')
        if archive_info:
            print(f'Hash: {archive_info.get("hash")}')

        return True

    return process


@main.command('hash', help='Calculates hash of a file')
@click.option('-a', '--alg',  required=True, help='Hash algorithm',
              type=click.Choice(['SHA256', 'SHA384', "SHA512"],
                                case_sensitive=False))
@click.option('-i', '--input', 'binary', type=click.Path(), required=True,
              help='Input file')
@click.option('-o', '--output', type=click.Path(),
              help='Output binary (.bin) or text (.txt) file')
@click.pass_context
def cmd_hash(_ctx, alg, binary, output):
    @process_handler()
    def process():
        return CommonAPI.hash(binary, alg, output)

    return process


@main.command('bin2hex', help='Converts binary image to hex',
              short_help='Converts binary image to hex')
@click.option('-i', '--input', '--image', 'infile', type=click.Path(),
              required=True, help='Input bin file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output hex file')
@click.option('--offset', default='0',
              help='Starting address offset for loading bin')
@click.pass_context
def cmd_bin2hex(_ctx, infile, output, offset):
    @process_handler()
    def process():
        return CommonAPI.bin2hex(infile, output, int(offset, 0))

    return process


@main.command('hex2bin', help='Converts hex image to binary',
              short_help='Converts hex image to binary')
@click.option('-i', '--input', '--image', 'infile', type=click.Path(),
              required=True, help='Input hex file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output bin file')
@click.option('--start', help='Start of address range')
@click.option('--end', help='End of address range')
@click.option('--size', help='Size of resulting file (in bytes)')
@click.option('--pad', help='Padding byte')
@click.pass_context
def cmd_hex2bin(_ctx, infile, output, start, end, size, pad):
    @process_handler()
    def process():
        return CommonAPI.hex2bin(infile, output, start=start, end=end, size=size,
                                 pad=pad)

    return process


@main.command('hex2hcd', help='Converts Intel HEX to Infineon HCD format')
@click.option('-i', '--input', 'infile', type=click.Path(), required=True,
              help='Input Intel HEX file')
@click.option('-o', '--output', 'outfile', type=click.Path(), required=True,
              help='Output HCD file')
@click.pass_context
def cmd_hex2hcd(ctx, infile, outfile):
    """Converts Intel HEX to Infineon HCD format"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].hex2hcd(infile, outfile)

    return process


@main.command('cbor2json', help='Converts CBOR to JSON')
@click.option('-i', '--input', 'image', type=click.Path(), required=True,
              help='Input bin file')
@click.option('-o', '--output', type=click.Path(), help='Output file')
@click.option('--offset', type=click.INT, help='Offset')
@click.pass_context
def cmd_cbor2json(_ctx, image, output, offset):
    @process_handler()
    def process():
        CommonAPI.cbor2json(image, output=output, offset=offset)
        return True

    return process


@main.command('cose-sign', help='Creates a COSE_Sign message')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the data to be signed')
@click.option('--key-0', type=click.Path(),
              help='Primary private key path to sign message')
@click.option('--key-1', type=click.Path(),
              help='Secondary private key path to sign message')
@click.option('--kid-0', help='Key ID')
@click.option('--kid-1', help='Key ID')
@click.option('--signature-0', type=click.Path(),
              help='Primary signature path to add to the message')
@click.option('--signature-1', type=click.Path(),
              help='Secondary signature path to add to the message')
@click.option('--algorithm-0', type=click.Choice(
              ['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
              case_sensitive=False), default='ES256',
              help='Primary signature algorithm')
@click.option('--algorithm-1', type=click.Choice(
              ['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
              case_sensitive=False), default='ES256',
              help='Secondary signature algorithm')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output path')
@click.pass_context
def cose_sign(ctx, input_path, output, key_0, key_1, kid_0,
              kid_1, signature_0, signature_1, algorithm_0, algorithm_1):
    """Creates a COSE multiple signers message"""
    @process_handler()
    def process():
        validate()
        return ctx.obj['TOOL'].cose_sign(input_path, output, kid=(kid_0, kid_1),
                                         key=(key_0, key_1),
                                         signature=(signature_0, signature_1),
                                         algorithm=(algorithm_0, algorithm_1))

    def validate():
        if all((key_0, key_1)) and all((signature_0, signature_1)):
            sys.stderr.write("Error: The options '--key-0' and "
                             "'--key-1' are mutually exclusive "
                             "with the options '--signature-0' and "
                             "'--signature-1'.\n")
            sys.exit(2)

    return process


@main.command('cose-sign1', help='Creates a COSE_Sign1 message')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the data to be signed')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='Private key path to sign message')
@click.option('--kid', help='Key ID')
@click.option('--signature', type=click.Path(),
              help='Signature path to add to the message')
@click.option('--algorithm', type=click.Choice(
              ['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
              case_sensitive=False), default='ES256', help='Signature algorithm'
              )
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output path')
@click.pass_context
def cose_sign1(ctx, output, input_path, key, kid, signature, algorithm):
    """Creates a COSE_Sign1 message"""
    @process_handler()
    def process():
        validate()
        return ctx.obj['TOOL'].cose_sign(
            input_path, key=key, kid=kid, output=output, signature=signature,
            algorithm=algorithm)

    def validate():
        if key and signature:
            sys.stderr.write("Error: The '--key-path' and '--signature' "
                             "options are mutually exclusive.\n")
            sys.exit(2)

    return process


@main.command('cose-verify', help='Verifies the COSE_Sign message')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the data to be verified')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              required=True, help='Public key path to verify COSE signed')
@click.option('--kid', help='Key ID')
@click.pass_context
def cose_verify(ctx, input_path, key, kid):
    """Verifies a COSE signed packet"""
    @process_handler()
    def process():
        return ctx.obj['TOOL'].cose_verify(input_path, key, kid=kid)

    return process


@main.command('create-key', help='Creates private and public key pair')
@click.option('--key-type', type=click.Choice(
    ['ECDSA-P256', 'ECDSA-P384', 'ECDSA-P521', 'X25519',
     'RSA2048', 'RSA3072', 'RSA4096',
     'AES128', 'AES256'],
    case_sensitive=False), required=True, help='Key type')
@click.option('-o', '--output', type=click.Path(), nargs=get_output_nargs(),
              metavar='[private] [public] for pair, [key] for single key',
              required=True,
              help='Private and public key paths or single key path')
@click.option('--template', type=click.Path(),
              help='A JSON file or binary file containing key material')
@click.option('--format', 'fmt', type=click.Choice(
              ['PEM', 'DER', 'JWK'], case_sensitive=False),
              default='PEM', help='Key format')
@click.option('--kid', type=click.INT, help='Key ID. Applicable to JWK only')
@click.option('--byteorder', 'byteorder',
              type=click.Choice(['big', 'little'], case_sensitive=False),
              default='big', help='Byte order for private value')
@click.option('--password', help='Password for private key encryption')
@click.pass_context
def cmd_create_key(ctx, key_type, output, template, fmt, kid, byteorder,
                   password):
    """Creates key pair"""
    @process_handler()
    def process():
        validate_args()
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].create_keys(
            key_type, output, fmt, template=template, kid=kid,
            byteorder=byteorder, password=password
        )

    def validate_args():
        if key_type == 'X25519' and template:
            sys.stderr.write("Error: The '--template' option is not supported "
                             "for X25519 key type.\n")
            sys.exit(2)
    return process


@main.command('convert-key', help='Converts key to other formats')
@click.option('-f', '--fmt', '--format', 'fmt', required=True,
              help='Output key format')
@click.option('-k', '--key', '--key-path', 'key_path', type=click.Path(),
              required=True, help='Input key path')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output file')
@click.option('--endian', 'endian',
              type=click.Choice(['big', 'little'], case_sensitive=False),
              default='little', help='Byte order')
@click.option('--password', help='Private key password')
@click.option('--var-name', help='Variable name for the key in C array format')
@click.pass_context
def cmd_convert_key(_ctx, fmt, key_path, output, endian, password, var_name):
    """Converts key to other formats"""
    @process_handler()
    def process():
        CommonAPI.convert_key(
            key_path, fmt, endian=endian, output=output, password=password,
            var_name=var_name
        )
        return True

    return process


@main.command('export-public-key', help='Exports public key from private key')
@click.option('-k', '--key-path', type=click.Path(), required=True,
              help='Input key path')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output file')
@click.option('--format', 'fmt', type=click.Choice(
              ['PEM', 'DER', 'JWK'], case_sensitive=False),
              default='PEM', help='Key format')
@click.pass_context
def cmd_export_public_key(_ctx, key_path, output, fmt):
    """Exports public key from private key"""
    @process_handler()
    def process():
        return CommonAPI.export_public_key(key_path, fmt, output=output)

    return process


@main.command('create-key-lms', help='Creates LMS private and public key pair')
@click.option('--lms-type', type=click.Choice(
    ['LMS-SHA256-M24-H5', 'LMS-SHA256-M24-H10', 'LMS-SHA256-M24-H15',
     'LMS-SHA256-M32-H5', 'LMS-SHA256-M32-H10', 'LMS-SHA256-M32-H15'
     ],
    case_sensitive=False), required=True, help='LM-OTS key type')
@click.option('--lmots-type', type=click.Choice(
    ['LMOTS-SHA256-N24-W1', 'LMOTS-SHA256-N24-W2', 'LMOTS-SHA256-N24-W4',
     'LMOTS-SHA256-N24-W8', 'LMOTS-SHA256-N32-W1', 'LMOTS-SHA256-N32-W2',
     'LMOTS-SHA256-N32-W4', 'LMOTS-SHA256-N32-W8'
     ],
    case_sensitive=False), required=True, help='Key LMS type')
@click.option('-o', '--output', type=click.Path(), nargs=2,
              metavar='[private] [public]',
              required=True,
              help='Private and public key paths')
@click.pass_context
def cmd_create_lms_key(ctx, lms_type, lmots_type, output):
    """Creates LMS key pair"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].create_keys_lms(lms_type, lmots_type, output)
    return process


@main.command('merge-hex', help='Merges different hex files into one')
@click.option('--image', type=click.Path(), multiple=True, required=True,
              help='The hex file to merge. Specify the option multiple '
                   'times for each image')
@click.option('--output', type=click.Path(), required=True,
              help='The merged file')
@click.option('--overlap', default='error', type=click.Choice(
              ['error', 'ignore', 'replace'], case_sensitive=False),
              help='Action on overlap of data or starting address')
@click.pass_context
def cmd_merge_hex(_ctx, image, output, overlap):
    """Merges different hex files into one"""
    @process_handler()
    def process():
        if len(image) < 2:
            sys.stderr.write('Error: At least two images must be specified\n')
            sys.exit(2)
        CommonAPI.merge_hex(image, output, overlap=overlap)
        return True

    return process


@main.command('merge-bin', help='Merges different binary files into one')
@click.option('--image', type=click.Path(), multiple=True, required=True,
              help='The bin file to merge. Specify the option multiple '
                   'times for each image')
@click.option('--output', type=click.Path(), required=True,
              help='The merged file')
@click.pass_context
def cmd_merge_bin(_ctx, image, output):
    """Merges different bin files into one"""
    @process_handler()
    def process():
        if len(image) < 2:
            sys.stderr.write('Error: At least two images must be specified\n')
            sys.exit(2)
        CommonAPI.merge_bin(image, output)
        return True

    return process


@main.command('hex-dump', help='Extracts data from the hex file')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='Hex file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The bin file where to save the data')
@click.option('--address', required=True, help='Address of the data')
@click.option('--size', required=True, help='Size of the data')
@click.option('--erased-val', type=click.IntRange(0, 0xff), default=0,
              help='Value to fill the spaces between the segments')
@click.pass_context
def cmd_hex_dump(_ctx, image, output, address, size, erased_val):
    """Extracts data from the hex file"""
    @process_handler()
    def process():
        if CommonAPI.hex_dump(image, output, address, size,
                              erased_val=erased_val):
            logger.info('Saved data to "%s"', os.path.abspath(output))
            return True
        else:
            logger.error('Failed to save data')
            return False

    return process


@main.command('bin-dump', help='Creates binary file')
@click.option('--data', help='Hex string')
@click.option('--random', help='Generate random binary of specified length')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output file')
@click.pass_context
def cmd_bin_dump(_ctx, data, random, output):
    """Dumps hex string to a binary file"""
    @process_handler()
    def process():
        validate_args()
        bindata = data if data is not None else f'random{random}'
        return CommonAPI.bin_dump(bindata, output)

    def validate_args():
        if data is not None and random is not None:
            sys.stderr.write("Error: The '--data' and '--random' options "
                             "are mutually exclusive.\n")
            sys.exit(2)

        if data is None and random is None:
            sys.stderr.write("Error: Either '--data' or '--random' option "
                             "must be specified.\n")
            sys.exit(2)

    return process


@main.command('hex-segment', help='Extracts a segment from the hex file')
@click.option('--image', type=click.Path(), required=True, help='Hex file')
@click.option('--addr', required=True, help='Address of the segment')
@click.option('--output', type=click.Path(), required=True,
              help='The hex file where to save the segment')
@click.pass_context
def cmd_hex_segment(_ctx, image, addr, output):
    """Extracts a segment from the hex file"""
    @process_handler()
    def process():
        return CommonAPI.hex_segment(image, addr, output)

    return process


@main.command('multi-image-cbor',
              help='Creates multi-image COSE packet from provided hex image')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the hex image')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output path')
@click.option('--segment', required=False, multiple=True, nargs=2, default=[],
              metavar='[address] [size]',
              help='The custom segments to specify segmentation of the file')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='Private key path to sign message')
@click.option('--kid', help='Key ID')
@click.option('--algorithm',
              type=click.Choice(['ES256', 'ES384', 'ES512', 'RS256', 'RS384'],
                                case_sensitive=False),
              help='Signature algorithm')
@click.option('--signature', type=click.Path(),
              help='Signature path to add to the message')
@click.option('--erased-val', type=click.IntRange(0, 0xff), default=0,
              help='Value to fill the spaces between the segments')
@click.pass_context
def cmd_multi_image_cbor(ctx, input_path, output, segment, key, kid,
                         algorithm, signature, erased_val):
    """Creates a multiple images COSE packet"""
    @process_handler()
    def process():
        validate_args()
        return ctx.obj['TOOL'].multi_image_cbor(input_path, output, key,
                                                kid=kid,
                                                segments=segment,
                                                algorithm=algorithm,
                                                signature=signature,
                                                erased_val=erased_val)

    def validate_args():
        if key:
            if algorithm:
                sys.stderr.write(
                    "When key is being used, the '--algorithm' "
                    "must not be provided.\n")
                sys.exit(2)
            if signature:
                sys.stderr.write(
                    "When key is being used, the '--signature' "
                    "must not be provided.\n")
                sys.exit(2)
        else:
            if not algorithm:
                sys.stderr.write(
                    "When key is not used, the '--algorithm' "
                    "must be provided.\n")
                sys.exit(2)

    return process


@main.command('encrypt-aes', help='Encrypts binary file using AES encryption')
@click.option('-i', '--input', 'cbor_input', type=click.Path(), required=True,
              help='The bin file to encrypt')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The encrypted file')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='The path to the key used to encrypt the image')
@click.option('--iv', default='auto', show_default=True,
              help='Initialization vector as a binary file or a hex '
                   'string starting from "0x". Use "auto" for autogeneration')
@click.option('--nonce',
              help='A hex string or a file containing nonce used for '
                   'encryption')
@click.option('--add-iv', is_flag=True, help='Indicates whether to add IV at '
                                             'the beginning of the output file')
@click.option('--iv-output', help='The output file for the generated IV',
              type=click.Path())
@click.option('--cipher-mode', required=True,
              type=click.Choice(['CBC', 'CTR', 'ECB'], case_sensitive=False),
              help='Cipher mode for AES encryption')
@click.pass_context
def cmd_encrypt_aes(_ctx, cbor_input, output, key, iv, nonce, add_iv, iv_output,
                    cipher_mode):
    """Encrypts file with AES cipher"""
    @process_handler()
    def process():
        CommonAPI.encrypt_aes(cbor_input, output, key, iv, add_iv,
                              iv_output, cipher_mode, nonce=nonce)
        return True

    return process


@main.command('sign-image',
              short_help='Signs the user application with a key. Optionally '
                         'encrypts the signed application',
              help='Signs the user application with a key. Optionally '
                   'encrypts the signed application')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='The user application file (bin or hex)')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The signed image output file (bin or hex)')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='The path to the key used to sign the image')
@click.option('--image-config', type=click.Path(), hidden=True,
              help='The path to the image configuration file')
@click.option('-R', '--erased-val', default='0',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value, which is read back from erased flash. Default: 0')
@click.option('-H', '--header-size', default='0x400',
              help='Sets the image header size. Default: 0x400')
@click.option('-S', '--slot-size', default='0x20000',
              help='Sets the maximum slot size. Default: 0x20000')
@click.option('--min-erase-size', default='0x8000',
              help='Sets minimum erase size. Default 0x8000')
@click.option('--image-version', default='0.0.0',
              help='Sets the image version in the image header')
@click.option('-s', '--security-counter', callback=validate_security_counter,
              help='Specify the value of security counter. Use the `auto` '
                   'keyword to automatically generate it from the image version')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment. Default: 8')
@click.option('--public-key-format', type=click.Choice(['hash', 'full']),
              default='hash', help='The public key format in the image TLV - '
                                   'full key or hash of the key. Default: hash')
@click.option('--pubkey-encoding', type=click.Choice(['der', 'raw']),
              default='der', help='The public key encoding in the image TLV - '
                                  '"der" or "raw". Default: der')
@click.option('--signature-encoding', type=click.Choice(['asn1', 'raw']),
              default='asn1', help='The image signature encoding. Default: asn1')
@click.option('--pad', is_flag=True, help='Add padding to the image trailer')
@click.option('--confirm', is_flag=True, help='Add image OK status to trailer')
@click.option('--overwrite-only', is_flag=True,
              help='Use overwrite mode instead of swap')
@click.option('--boot-record', metavar='sw_type', help='Create CBOR encoded '
              'boot record TLV. The sw_type represents the role of the '
              'software component (e.g. CoFM for coprocessor firmware). '
              '[max. 12 characters]')
@click.option('--hex-addr', help='Adjust the address in the hex output file')
@click.option('-L', '--load-addr',
              help='Load address for image when it should run from RAM')
@click.option('-F', '--rom-fixed',
              help='Set flash address the image is built for')
@click.option('-M', '--max-sectors', type=click.INT,
              help='When padding allow for this amount of sectors '
                   '(defaults to 128)')
@click.option('--save-enctlv', is_flag=True,
              help='When upgrading, save encrypted key TLVs instead of plain '
                   'keys. Enable when BOOT_SWAP_SAVE_ENCTLV config option '
                   'was set')
@click.option('-d', '--dependencies', callback=get_dependencies,
              required=False, help='Add dependence on another image. Format: '
              '"(<image_ID>,<image_version>), ... "')
@click.option('--encrypt', type=click.Path(),
              help='Encrypt image using the provided public key')
@click.option('--protected-tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='The custom TLV to be placed into a protected area (the '
                   'signed part). Add the "0x" prefix for the value to be '
                   'interpreted as an integer, otherwise it will be '
                   'interpreted as a string. Specify the option multiple times '
                   'to add multiple TLVs')
@click.option('--tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='The custom TLV to be placed into a non-protected area. '
                   'Add the "0x" prefix for the value to be interpreted as an '
                   'integer, otherwise it will be interpreted as a string. '
                   'Specify the option multiple times to add multiple TLVs')
@click.option('--remove-tlv', required=False, multiple=True,
              help='Removes TLV with the specified ID')
@click.option('--enckey', type=click.Path(), help='Encryption key')
@click.option('--enckey-role', default="XIP",
              type=click.Choice(['XIP', 'AES-KW'], case_sensitive=False),
              help='Encryption key role')
@click.option('--encrypt-addr', help='Starting address for data encryption')
@click.option('--nonce-output', type=click.Path(),
              help='The path to a file where to save the nonce')
@click.option('--kdf', default='HKDF',
              type=click.Choice(['HKDF', 'KBKDFCMAC'], case_sensitive=False),
              help='Key derivation function name')
@click.pass_context
def cmd_sign_image(ctx, image, output, key, image_config, erased_val,
                   header_size, slot_size, min_erase_size, image_version,
                   security_counter, align, public_key_format, pubkey_encoding,
                   signature_encoding, pad, confirm, overwrite_only,
                   boot_record, hex_addr, load_addr, rom_fixed, max_sectors,
                   save_enctlv, dependencies, encrypt,
                   protected_tlv, tlv, remove_tlv, enckey, enckey_role,
                   encrypt_addr, nonce_output, kdf):
    """Signs application image"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        result = ctx.obj['TOOL'].sign_image(
            image,
            output=output,
            key_path=key,
            image_config=image_config,
            erased_val=erased_val,
            header_size=header_size,
            slot_size=slot_size,
            min_erase_size=min_erase_size,
            image_version=image_version,
            security_counter=security_counter,
            align=align,
            public_key_format=public_key_format,
            pubkey_encoding=pubkey_encoding,
            signature_encoding=signature_encoding,
            pad=pad,
            confirm=confirm,
            overwrite_only=overwrite_only,
            boot_record=boot_record,
            hex_addr=hex_addr,
            load_addr=load_addr,
            rom_fixed=rom_fixed,
            max_sectors=max_sectors,
            save_enctlv=save_enctlv,
            dependencies=dependencies,
            encrypt=encrypt,
            prot_tlv=protected_tlv,
            tlv=tlv,
            remove_tlv=remove_tlv,
            enckey=enckey,
            enckey_role=enckey_role,
            encrypt_addr=encrypt_addr,
            nonce_output=nonce_output,
            kdf=kdf
        )
        return result is not None

    return process


@main.command('image-metadata',
              short_help='Adds MCUboot metadata to a firmware image',
              help='Adds MCUboot metadata to a firmware image')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='The user application file (bin or hex)')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path to the binary file to save the image with metadata')
@click.option('--decrypted', type=click.Path(),
              help='The path where to save decrypted image payload')
@click.option('--image-config', type=click.Path(), hidden=True,
              help='The path to the image configuration file')
@click.option('-R', '--erased-val', default='0',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value, which is read back from erased flash. Default: 0')
@click.option('-H', '--header-size', default='0x400',
              help='Sets the image header size. Default: 0x400')
@click.option('-S', '--slot-size', default='0x20000',
              help='Sets the maximum slot size. Default: 0x20000')
@click.option('--min-erase-size', default='0x8000',
              help='Sets minimum erase size. Default 0x8000')
@click.option('--image-version', default='0.0.0',
              help='Sets the image version in the image header')
@click.option('-s', '--security-counter', callback=validate_security_counter,
              help='Specify the value of security counter. Use the `auto` '
                   'keyword to automatically generate it from the image version')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment. Default: 8')
@click.option('--pubkey', type=click.Path(),
              help='The public key to be added to the image')
@click.option('--public-key-format', type=click.Choice(['hash', 'full']),
              default='hash', help='In what format to add the public key to '
              'the image manifest: full key or hash of the key. Default: hash')
@click.option('--pubkey-encoding', type=click.Choice(['der', 'raw']),
              default='der', help='In what format to add the public key to '
              'the image manifest: full key or hash of the key. Default: der')
@click.option('--pad', is_flag=True, help='Add padding to the image trailer')
@click.option('--confirm', is_flag=True, help='Add image OK status to trailer')
@click.option('--overwrite-only', is_flag=True,
              help='Use overwrite mode instead of swap')
@click.option('--boot-record', metavar='sw_type', help='Create CBOR encoded '
              'boot record TLV. The sw_type represents the role of the '
              'software component (e.g. CoFM for coprocessor firmware). '
              '[max. 12 characters]')
@click.option('--hex-addr', help='Adjust the address in the hex output file')
@click.option('-L', '--load-addr',
              help='Load address for image when it should run from RAM')
@click.option('-F', '--rom-fixed',
              help='Set flash address the image is built for')
@click.option('-M', '--max-sectors', type=click.INT,
              help='When padding allow for this amount of sectors '
                   '(defaults to 128)')
@click.option('--save-enctlv', is_flag=True,
              help='When upgrading, save encrypted key TLVs instead of plain '
                   'keys. Enable when BOOT_SWAP_SAVE_ENCTLV config option '
                   'was set')
@click.option('-d', '--dependencies', callback=get_dependencies,
              required=False, help='Add dependence on another image. Format: '
              '"(<image_ID>,<image_version>), ... "')
@click.option('--encrypt', type=click.Path(),
              help='Encrypt image using the provided public key')
@click.option('--protected-tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='The custom TLV to be placed into a protected area (the '
                   'signed part). Add the "0x" prefix for the value to be '
                   'interpreted as an integer, otherwise it will be '
                   'interpreted as a string. Specify the option multiple times '
                   'to add multiple TLVs')
@click.option('--tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='The custom TLV to be placed into a non-protected area. '
                   'Add the "0x" prefix for the value to be interpreted as an '
                   'integer, otherwise it will be interpreted as a string. '
                   'Specify the option multiple times to add multiple TLVs')
@click.option('--remove-tlv', required=False, multiple=True,
              help='Removes TLV with the specified ID')
@click.option('--enckey', type=click.Path(), help='Encryption key')
@click.option('--enckey-role', default="XIP",
              type=click.Choice(['XIP', 'AES-KW'], case_sensitive=False),
              help='Encryption key role')
@click.option('--encrypt-addr', help='Starting address for data encryption')
@click.option('--nonce-output', type=click.Path(),
              help='The path to a file where to save the nonce')
@click.option('--kdf', default='HKDF',
              type=click.Choice(['HKDF', 'KBKDFCMAC'], case_sensitive=False),
              help='Key derivation function name')
@click.pass_context
def cmd_image_metadata(ctx, image, output, decrypted, pubkey, image_config,
                       erased_val, header_size, slot_size, min_erase_size,
                       image_version, security_counter, align,
                       public_key_format, pubkey_encoding,
                       pad, confirm, overwrite_only, boot_record, hex_addr,
                       load_addr, rom_fixed, max_sectors, save_enctlv,
                       dependencies, encrypt, protected_tlv, tlv, remove_tlv,
                       enckey, enckey_role, encrypt_addr, nonce_output, kdf):
    """Adds MCUboot metadata to a firmware image"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_args()
        result = ctx.obj['TOOL'].image_metadata(
            image,
            output=output,
            decrypted=decrypted,
            pubkey=pubkey,
            image_config=image_config,
            erased_val=erased_val,
            header_size=header_size,
            slot_size=slot_size,
            min_erase_size=min_erase_size,
            image_version=image_version,
            security_counter=security_counter,
            align=align,
            public_key_format=public_key_format,
            pubkey_encoding=pubkey_encoding,
            pad=pad,
            confirm=confirm,
            overwrite_only=overwrite_only,
            boot_record=boot_record,
            hex_addr=hex_addr,
            load_addr=load_addr,
            rom_fixed=rom_fixed,
            max_sectors=max_sectors,
            save_enctlv=save_enctlv,
            dependencies=dependencies,
            encrypt=encrypt,
            prot_tlv=protected_tlv,
            tlv=tlv,
            remove_tlv=remove_tlv,
            enckey=enckey,
            enckey_role=enckey_role,
            encrypt_addr=encrypt_addr,
            nonce_output=nonce_output,
            kdf=kdf
        )
        return result is not None

    def validate_args():
        if encrypt and not decrypted:
            sys.stderr.write("If encryption is being used, the '--decrypted' "
                             "argument is required.\n")
            sys.exit(2)

    return process


@main.command('extract-payload', help='Extracts a part of image to be signed',
              short_help='Extracts a part of image to be signed')
@click.option('--image', type=click.Path(), required=True,
              help='Image with MCUboot metadata (bin)')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path where to save the image to be signed (bin)')
@click.pass_context
def cmd_extract_payload(ctx, image, output):
    """Extracts a part of image to be signed"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].extract_payload(image, output)
        return True

    return process


@main.command('add-signature',
              help='Adds signature to the existing MCUboot format image',
              short_help='Adds signature to the existing MCUboot format image')
@click.option('--image', type=click.Path(), required=True,
              help='Image with MCUboot metadata (bin)')
@click.option('-s', '--signature', type=click.Path(), required=True,
              help='Binary file containing signature')
@click.option('--alg', type=click.Choice(
              ['ECDSA-P256', 'ECDSA-P384', 'ECDSA-P521',
               'RSA2048', 'RSA4096'], case_sensitive=False),
              required=True, help='Signature algorithm')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path where to save the image with the signature (bin)')
@click.pass_context
def cmd_add_signature(ctx, image, signature, alg, output):
    """Adds signature to the existing MCUboot format image"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].add_signature(image, signature, output, alg=alg)
        return True

    return process


@main.command('verify-image', help='Verifies image with a key')
@click.option('--image', type=click.Path(), required=True,
              help='The path to the image')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The path to the public key')
@click.pass_context
def cmd_verify_image(ctx, image, key):
    """Verifies image with a key"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].verify_image(image, key=key)

    return process


@main.command('x509-cert', help='Creates X.509 certificate')
@click.option('-c', '--config', type=click.Path(), required=True,
              help='The path to the certificate configuration file')
@click.option('--csr', type=click.Path(), help='The path to the CSR file')
@click.option('--ca-cert', type=click.Path(),
              help='The path to the CA certificate')
@click.option('--self-signed', is_flag=True, default=False,
              help='Indicates whether the certificate is self-signed')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='The path to the certificate signing key')
@click.option('--password', help='Signing key password')
@click.option('-e', '--encoding',
              type=click.Choice(['PEM', 'DER'], case_sensitive=False),
              default='PEM', help='The encoding of the certificate')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path to the output certificate file')
@click.pass_context
def cmd_x509_cert(ctx, config, csr, ca_cert, self_signed, key, password,
                  encoding, output):
    """Creates X.509 certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].x509_certificate(
            config=config, csr=csr, ca_cert=ca_cert, self_signed=self_signed,
            signing_key=key, password=password, encoding=encoding,
            output=output)

    return process


@main.command('verify-x509-cert', help='Verifies X.509 certificate')
@click.option('--cert', type=click.Path(), required=True,
              help='The path to the certificate file')
@click.option('--verifier', type=click.Path(), required=True,
              help='One of the following: key, CA certificate, or CSR')
@click.pass_context
def cmd_verify_x509_cert(ctx, cert, verifier):
    """Creates X.509 certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].verify_x509_certificate(cert, verifier)

    return process


@main.command('hex-relocate',
              help='Relocate regions in a hex file to new address spaces')
@click.option(
    '--region',
    type=(str, str, str),
    multiple=True,
    required=True,
    metavar='[START] [SIZE] [DEST]',
    help='Region to relocate: provide start, size, dest as hex values '
         '(e.g. --region 0x08000000 0x04000000 0x60000000). '
         'Can be specified multiple times'
)
@click.option('-i', '--input', 'input_file', type=click.Path(exists=True),
              required=True, help='Input HEX file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output HEX file')
@click.pass_context
def cmd_hex_relocate(_ctx, region, input_file, output):
    """Relocates regions in a hex file to new address spaces"""
    @process_handler()
    def process():
        regions = []
        for idx, (start, size, dest) in enumerate(region):
            try:
                start_int = int(start, 16)
                size_int = int(size, 16)
                dest_int = int(dest, 16)
            except ValueError:
                sys.stderr.write(
                    f"Region #{idx+1}: All values must be hexadecimal numbers. "
                    f"Got: start='{start}', size='{size}', dest='{dest}'\n"
                )
                sys.exit(2)
            regions.append((start_int, size_int, dest_int))
        return CommonAPI.hex_relocate(input_file, output, regions)
    return process


def print_assertion_error():
    _, _, tb = sys.exc_info()
    tb_info = traceback.extract_tb(tb)
    stack_trace = ''
    for item in traceback.StackSummary.from_list(tb_info).format():
        stack_trace += item
    stack_trace = stack_trace.rstrip('\n')
    logger.debug(stack_trace)
    filename, line, _, text = tb_info[-1]
    logger.error("An error occurred in file '%s' on line %d in statement %s",
                 filename, line, text)


def default_policy(target_name, rev=None):
    director = TargetDirector()
    target_name = target_name.lower()
    get_target_builder(director, target_name, rev=rev)
    target = director.get_target(None, None)
    return target.policy


def validate_init_cmd_args():
    if '--policy' in sys.argv:
        sys.stderr.write('Error: invalid argument used with "init" '
                         'command: --policy\n')
        sys.exit(1)
    if '-p' in sys.argv:
        sys.stderr.write('Error: invalid argument used with "init" '
                         'command: -p\n')
        sys.exit(1)


def process_handler(process_fail_value=False):
    def function_decorator(func):
        def inner_function(*args, **kwargs):
            try:
                return func(*args, **kwargs)
            except AssertionError:
                print_assertion_error()
            except Exception as e:  # pylint: disable=broad-except
                logger.error(e)
                logger.debug(e, exc_info=True)
            return process_fail_value
        return inner_function
    return function_decorator
