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
import json
import logging
import os
from builtins import staticmethod
from collections import namedtuple

from cbor import cbor
from cwt import COSE, COSEKey, VerifyError

from . import VersionProviderMXS22, CertificateStrategyMXS22
from .cert_validator_mxs22 import CertTemplateValidatorMXS22
from .chain_of_trust_verify import ChainOfTrust
from .enums import (DeviceResponse, DeviceIntegrity, CoseSign1Packet)
from ..flow_parser import FlowParser
from ....core.entrance_exam_base import EntranceExam, EntranceExamRegion
from ....core.enums import EntranceExamStatus
from ....core.key_handlers.ec_handler import ECHandler
from ....core.provisioning_flows.app_loading_flow import AppLoadingFlow
from ....core.target_director import Target

logger = logging.getLogger(__name__)

IntegrityAssets = namedtuple(
    'IntegrityAssets', 'silicon_id family_id si_rev_id die_id nonce regions')


class DeviceIntegrityMXS22(EntranceExam):
    """Verifies that the device is in the expected state"""

    def __init__(self, target: Target, **kwargs):
        super().__init__(target, **kwargs)
        self.reg_map = target.register_map
        self.target = target

    def execute(self, tool, **kwargs):
        """
        Execute device integrity RAM app to collect and verify device regions
        data to ensure that this is a genuine Infineon device and it is in a
        known state
        """
        self.framed_text('DEVICE INTEGRITY EXAM')
        if tool:
            flow, app = self.application_data(kwargs)
            in_params = app.in_params_path
            in_assets = self.collect_in_params(in_params, self.target, tool)
            if flow.run(tool) != EntranceExamStatus.OK:
                raise RuntimeError('Device integrity exam app execution failed')
            out_results = app.out_results_path
        else:
            in_assets = self.collect_in_params(kwargs.get('in_params'))
            out_results = kwargs.get('response')
        out_assets = self.collect_out_results(out_results, **kwargs)
        status = self.verify(in_assets, out_assets, **kwargs)

        if status == EntranceExamStatus.OK:
            self.framed_text('REGIONS VALIDATION PASSED')
        else:
            self.framed_text('REGIONS VALIDATION FAILED')

        self.framed_text('Chain of trust verification')
        cot = ChainOfTrust(out_assets.get('CHAIN_OF_TRUST'))
        if cot.verify():
            self.framed_text('Chain of trust verification passed')
        else:
            status = EntranceExamStatus.FAIL
            self.framed_text('Chain of trust verification failed')

        if status == EntranceExamStatus.OK:
            self.framed_text('DEVICE INTEGRITY PASSED')
        else:
            self.framed_text('DEVICE INTEGRITY FAILED')
        return status

    def fill_template(self, cert, response, output, **kwargs):
        """Fill integrity template with hashes"""

        cert_regions = self._load_template(cert).get('regions')
        out_regions = self.collect_out_results(response,
                                               **kwargs).get('REGIONS')

        pairs = self.pair_regions_smart(cert_regions, out_regions)
        regions = []

        for old, new in pairs:
            itm = {}

            if old.description:
                itm['description'] = old.description

            if old.operation:
                itm['operation'] = old.operation

            if old.label:
                itm['label'] = old.label
            else:
                itm['region'] = list(zip(old.address, old.size))

            if old.owner:
                itm['owner'] = old.owner

            if new.content:
                itm['hash'] = new.content
            regions.append(itm)

        new_template = {'regions': regions}

        with open(output, 'w', encoding='utf-8') as f:
            json.dump(new_template, f, indent=2)
        logger.info('Saved integrity hashes: "%s"', output)

        return EntranceExamStatus.OK

    def application_data(self, kwargs):
        """Provides app config data when an app flow is used"""
        apps_type = kwargs.get('testapps')
        flow_parser = FlowParser(self.target, test_pkg_type=apps_type)
        apps = flow_parser.apps_by_flow('device_integrity_exam')
        if not apps:
            raise ValueError('RAM applications list is empty')
        app_dir = self.target.project_initializer.apps_dir
        flow = AppLoadingFlow(
            self.target, 'device_integrity_exam', app_dir,
            test_pkg_type=apps_type)
        return flow, flow.app_list[-1]

    def verify(self, in_assets, out_assets, **kwargs):
        """Verify device regions data"""
        nonce = out_assets.get('NONCE')
        if nonce == in_assets.nonce:
            logger.info('- NONCE: %s', nonce.hex())
            out_regs = out_assets.get('REGIONS')
            status = self.process_regions(in_assets.regions, out_regs, **kwargs)
        else:
            logger.info('- IN_NONCE: %s', in_assets.nonce.hex())
            logger.info('- OUT_NONCE: %s', nonce.hex())
            status = EntranceExamStatus.FAIL
        return status

    def cert_filename(self, tool, cert, template, apps_type):
        """Generates certificate and template paths using
        device information or checks and returns the provided
        """
        if cert and not template:
            if self.is_json_cert(cert):
                return cert, cert

        if None in (cert, template) and (cert or template):
            raise ValueError('The integrity exam certificate '
                             'must be used with the template')
        if all((cert, template)):
            return cert, template

        dev_info = self.target.silicon_data_reader.read_device_info(tool)
        dev_id = dev_info.silicon_id.to_bytes(2, 'big').hex()
        dev_id += dev_info.family_id.to_bytes(2, 'big').hex()
        dev_id += dev_info.silicon_rev.to_bytes(1, 'big').hex()
        flow_parser = FlowParser(self.target, test_pkg_type=apps_type)
        apps = flow_parser.apps_by_flow('device_integrity_exam')
        cert_dir = os.path.dirname(next(iter(apps.values())))

        dev_cert = None
        dev_template = self.find_integrity_cert(cert_dir, dev_id)
        if not dev_template:
            dev_cert = os.path.join(cert_dir, f'pse84_{dev_id}.bin')
            dev_template = os.path.join(cert_dir, f'pse84_{dev_id}.json')
        if self.is_json_cert(dev_template):
            return dev_template, dev_template
        return dev_cert, dev_template

    @staticmethod
    def find_integrity_cert(cert_dir, dev_id):
        """Selects integrity exam certificate by the device info"""
        cert_names = [f for f in os.listdir(cert_dir) if os.path.isfile(
            os.path.join(cert_dir, f))]
        for name in cert_names:
            if name.endswith('.json'):
                with open(os.path.join(cert_dir, name), encoding='utf-8') as f:
                    cert_data = json.load(f)
            else:
                continue
            cert_fields = True
            for section in ('device', 'regions'):
                if section not in cert_data:
                    cert_fields = False
                    break
            if not cert_fields:
                continue
            device = cert_data.get('device')
            if device:
                si = device.get('si')
                family = device.get('family')
                rev = device.get('rev')
                if all((si, family, rev)):
                    si = int(si, 0).to_bytes(2, 'big').hex()
                    family = int(family, 0).to_bytes(2, 'big').hex()
                    rev = int(rev, 0).to_bytes(1, 'big').hex()
                    if si + family + rev == dev_id:
                        return os.path.join(cert_dir, name)
        return None

    @staticmethod
    def is_json_cert(cert):
        """Check for certificate in JSON"""
        try:
            with open(cert, encoding="utf-8") as f:
                cert_data = json.load(f)
        except UnicodeDecodeError:
            logger.debug("Unexpected behavior when read JSON '%s'", cert)
            return False
        return cert_data and cert_data.get('certificate')

    def process_regions(self, cert_regions, result_regions, **kwargs):
        """Regions data preparation and values comparison"""
        template_path = kwargs.get('template_path')
        cert_template = self._load_template(template_path)
        custom_regions = kwargs.get('custom_regions')
        if custom_regions:
            custom_regions = self._load_template(custom_regions)
        regions_info = cert_template.get('regions')
        ifx_input, oem_input, display_regions = self.sort_regions(
            cert_regions, regions_info, custom_regions)
        ifx_regions = self.pair_regions(ifx_input, result_regions)
        oem_regions = self.pair_regions(oem_input, result_regions)
        return_regions = self.pair_regions(display_regions, result_regions)
        self.framed_text('IFX Regions data')
        ifx_status, ifx_results = self.check_hash(ifx_regions)
        self.validation_status_log(ifx_status, 'IFX')
        self.framed_text('OEM Regions data')
        oem_status, oem_results = self.check_hash(oem_regions)
        self.validation_status_log(oem_status, 'OEM')

        self.framed_text('Regions data')
        self.display_return_regions(return_regions)
        self.framed_text('Integrity exam report')

        self.report_exam_results(ifx_results, 'IFX hash')
        self.report_exam_results(oem_results, 'OEM hash')
        returned_reg = len(return_regions)
        if returned_reg:
            logger.info('Regions data to display: %s', returned_reg)
        logger.info('Total: %s',
                    len(ifx_results) + len(oem_results) + len(return_regions))
        if EntranceExamStatus.FAIL in (ifx_status, oem_status):
            return EntranceExamStatus.FAIL
        return EntranceExamStatus.OK

    @staticmethod
    def report_exam_results(results, message):
        """Displays summary integrity exam results"""
        failed = []
        for result in results:
            if 'No hashes match' in result:
                failed.append(result)
        failed = len(failed)
        passed = len(results) - failed
        logger.info('%s regions passed: %s', message, passed)
        if failed:
            disabled = 0
            for status in results:
                if 'Disabled' in status:
                    disabled += 1
            if disabled:
                logger.info('%s regions disabled: %s', message, disabled)
            failed = failed - disabled
            if failed:
                logger.info('%s regions failed: %s', message, failed)

    @staticmethod
    def display_return_regions(return_regions):
        """Display return operation data"""
        for val in return_regions:
            try:
                logger.info('%s', val[1].get('description'))
                logger.info(
                    'Region address %s size %s', hex(val[0][0][0]),
                    val[0][0][1])
                logger.info(val[0][1].hex())
            except (TypeError, AttributeError, IndexError) as exc:
                raise ValueError('Corrupted region data') from exc
            print()

    @staticmethod
    def _load_template(json_path):
        """Loads template data"""
        abs_path = os.path.abspath(json_path)
        with open(abs_path, 'r', encoding='utf-8') as f:
            cert_template = json.load(f)
        return cert_template

    @staticmethod
    def validation_status_log(ifx_result, name):
        """Exam info status"""
        if ifx_result == EntranceExamStatus.OK:
            logger.info('%s regions exam success', name)
        else:
            logger.error('%s regions exam failed', name)

    @staticmethod
    def framed_text(message, line_len=41):
        """Display info with separation"""
        logger.info('*' * line_len)
        logger.info(' ' * ((line_len - len(message)) // 2) + message)
        logger.info('*' * line_len)

    @staticmethod
    def check_hash(region_pairs):
        """Compare regions pairs data and returns status
        @param region_pairs: The tuple list of regions data composed as app
                             result regions and reference regions
        @return: EntranceExamStatus.OK if regions data matched or
                 EntranceExamStatus.FAIL
        """
        display_data = []
        status = EntranceExamStatus.OK
        for itm in region_pairs:
            info = []
            try:
                exam_result = itm[0]
                exam_cert = itm[1]
            except (TypeError, AttributeError, IndexError) as exc:
                raise ValueError(
                    'Corrupted integrity_exam or certificate data') from exc
            label = exam_cert.get('label')
            description = exam_cert.get('description')
            if label:
                info.append(label)
            if description:
                info.append(description)
            if isinstance(exam_result, dict):
                res_region = exam_result.get(label)
                cert_hash = exam_cert.get('hash')
                status, data = DeviceIntegrityMXS22._process_label_regions(
                    res_region, cert_hash, label, status)
                info.extend(data)
            else:
                status, data = DeviceIntegrityMXS22._process_unlabeled_regions(
                    exam_result, exam_cert, status)
                info.extend(data)

            display_data.append(info)
        for hash_info in display_data:
            for info in hash_info:
                logger.info(info)
            print()

        return status, display_data

    @staticmethod
    def _process_unlabeled_regions(exam_data, cert_data, status):
        """Process unlabeled regions"""
        info = []
        for exam_region in exam_data:
            for cert_region in cert_data.get('region'):
                if exam_region == cert_region:
                    try:
                        info.append(
                            f'Region: {hex(exam_region[0])}, {exam_region[1]}')
                    except (TypeError, AttributeError, IndexError) as exc:
                        raise ValueError(
                            'Corrupted certificate region data') from exc

        cert_hash = cert_data.get('hash')
        exam_hash = exam_data[-1]
        if isinstance(cert_hash, list):
            for item in cert_hash:
                itm_hash = item.get('hash')
                if exam_hash == itm_hash:
                    info.append(f"Version: {item.get('value')}")
                    description = item.get('description')
                    if description:
                        info.append(f"Description: {description}")
                    info.append(f"HASH: {itm_hash.hex()}")
                    break
            else:
                status = DeviceIntegrityMXS22.hash_status(
                    cert_hash, exam_hash, info, status)
        else:
            if exam_hash == cert_hash:
                info.append(f'HASH: {exam_hash.hex()}')
            else:
                status = DeviceIntegrityMXS22.hash_status(
                    cert_hash, exam_hash, info, status)
        return status, info

    @staticmethod
    def hash_status(cert_hash, exam_hash, info, status):
        """Displays actual hash value and returns status fail
        if hash exam is not disabled
        """
        hash_info = DeviceIntegrityMXS22.act_hash_log(exam_hash)
        if cert_hash:
            status = EntranceExamStatus.FAIL
        else:
            hash_info.append('Disabled')
        info.extend(hash_info)
        return status

    @staticmethod
    def _process_label_regions(exam_data, cert_data, label, status):
        """Process labeled regions"""
        info = []
        for exam_item in exam_data:
            exam_hash = exam_item[-1]
            exam_item_addr = exam_item[0]
            exam_item_size = exam_item[1]
            if isinstance(cert_data, list):
                for cert_item in cert_data:
                    if cert_item.get('hash') == exam_hash:
                        info.append(f'Addr: {exam_item_addr}, '
                                    f'size {exam_item_size}')
                        info.append(f"{label} {cert_item.get('value')} "
                                    f"{cert_item.get('description')}")
                        info.append(f'HASH: {exam_hash.hex()}')
                        break
                else:
                    info.extend(
                        DeviceIntegrityMXS22.act_hash_log(exam_hash))
                    status = EntranceExamStatus.FAIL
            else:
                if cert_data == exam_hash:
                    info.append(f'Addr: {exam_item_addr}, '
                                f'size {exam_item_size}')
                    info.append(f'HASH: {exam_hash.hex()}')
                    break
                else:
                    status = DeviceIntegrityMXS22.hash_status(
                        cert_data, exam_hash, info, status)
        return status, info

    @staticmethod
    def act_hash_log(hash_data):
        """Display actual hash data"""
        return ['No hashes match', f'Act. HASH: {hash_data.hex()}']

    @staticmethod
    def pair_regions(cert, result):
        """Pair cert and result regions data"""
        regions = []
        for cert_reg in cert:
            for out_reg in result:
                if cert_reg.get('label'):
                    if isinstance(out_reg, dict) and cert_reg.get(
                            'label') in out_reg.keys():
                        regions.append((out_reg, cert_reg))
                        break
                elif isinstance(out_reg, list):
                    out_reg_itm = [i for i in out_reg[:-1]]
                    if out_reg_itm == cert_reg.get('region'):
                        regions.append((out_reg, cert_reg))
                        break
        return regions

    @staticmethod
    def create_region(region) -> EntranceExamRegion:
        """
        Create single region from certificate, in_params or app response region
        """
        if isinstance(region, dict):
            if 'region' in region or 'label' in region:
                address = region.get('region')
                if address:
                    addr, sz = list(map(list, zip(*address)))
                else:
                    addr, sz = None, None

                digest = region.get('hash')

                kv = {
                    'description': region.get('description'),
                    'address': addr,
                    'size': sz,
                    'label': region.get('label'),
                    'operation': region.get('operation'),
                    'owner': region.get('owner'),
                    'content': digest
                }
            else:
                label = list(region.keys())[-1]
                address, size, digest = list(region.values())[-1][-1]

                kv = {
                    'label': label,
                    'address': [address],
                    'size': [size],
                    'content': digest
                }
        else:
            addresses = region[:-1]
            digest = region[-1]
            (address, size) = list(map(list, zip(*addresses)))

            kv = {
                'address': address,
                'size': size,
                'content': digest
            }

        if isinstance(kv.get('content'), (bytes, bytearray)):
            kv['content'] = kv.get('content').hex()

        return EntranceExamRegion(**kv)

    def pair_regions_smart(self, cert, out):
        """Pair cert and response regions data"""
        regions = []
        cert_regions = [self.create_region(region) for region in cert]
        out_regions = [self.create_region(region) for region in out]
        for cert_reg in cert_regions:
            for out_reg in out_regions:
                if cert_reg == out_reg or \
                        (cert_reg.label and out_reg.label
                         and cert_reg.label == out_reg.label):
                    regions.append((cert_reg, out_reg))
                    break
            else:
                logger.warning('No match found for region: %s', repr(cert_reg))
        return regions

    @staticmethod
    def sort_regions(certificate, template, custom=None):
        """
        @param certificate: Regions certificate data
        @param template: Regions template data
        @param custom: OEM custom regions data
        @return: IFX regions data, OEM regions data, return operation data
        """
        if len(certificate) != len(template):
            raise ValueError('Incorrect number of regions in certificate and '
                             'certificate template')
        ifx = []
        oem = []
        ret = []
        for c_itm, t_itm in zip(certificate, template):
            if c_itm.get('region') and t_itm.get('region'):
                for c_reg, t_reg in zip(c_itm.get('region'),
                                        t_itm.get('region')):
                    if c_reg != [int(str(t_reg[0]), 0), int(str(t_reg[1]), 0)]:
                        raise ValueError('Regions data mismatch')

            c_hash = c_itm.get('hash')
            t_hash = t_itm.get('hash')
            if c_hash and t_hash:
                if isinstance(t_hash, list):
                    for c_hash_itm, t_hash_itm in zip(c_hash, t_hash):
                        if c_hash_itm.get('hash').hex() == t_hash_itm.get(
                                'hash'):
                            description = t_hash_itm.get('description')
                            if description:
                                c_hash_itm.update({'description': description})
                        else:
                            raise ValueError('Hash mismatch')
                else:
                    if c_hash.hex() != t_hash:
                        raise ValueError('Hash mismatch')

            c_itm.update({'description': t_itm.get('description')})
            if c_itm.get('operation') == 'hash':
                owner = c_itm.get('owner')
                if owner == 'IFX':
                    ifx.append(c_itm)
                elif owner == 'OEM':
                    if custom:
                        oem.append(DeviceIntegrityMXS22._replace_hash(
                            c_itm, custom))
                    else:
                        oem.append(c_itm)
            else:
                ret.append(c_itm)
        return ifx, oem, ret

    @staticmethod
    def _replace_hash(cert, custom):
        """Replace cert hash with the custom hash data"""
        for cust_reg in custom.get('regions'):
            replace = False

            if not cust_reg.get('label'):
                reg_data = [
                    [int(str(reg[0]), 0), int(str(reg[1]), 0)]
                    for reg in cust_reg.get('region')
                ]
                replace = reg_data == cert.get('region')
            elif cust_reg.get('label') == cert.get('label'):
                replace = True

            if replace:
                cert['hash'] = None
                if cust_reg.get('enabled', True):
                    cert['hash'] = bytes.fromhex(cust_reg.get('hash'))
        return cert

    def read_sfb_version(self, tool):
        """N/A for MXS22 platform"""

    def log_protection_state(self, tool):
        """N/A for MXS22 platform"""

    @staticmethod
    def collect_out_results(out_results, **kwargs):
        """Collects app out_results"""
        alias_out = kwargs.get('alias_cert')
        device_out = kwargs.get('device_cert')
        chain_of_trust_out = kwargs.get('chain_of_trust')
        with open(out_results, 'rb') as f:
            out_data = f.read()

        dev_rsp = DeviceIntegrityMXS22._parse_app_results(out_data)
        dev_cert = dev_rsp.get(DeviceResponse.IFX_DEVICE_CERT)[4:]
        alias_cert = dev_rsp.get(DeviceResponse.ALIAS_CERT)[4:]
        chain_of_trust = dev_rsp.get(DeviceResponse.IFX_CHAIN_OF_TRUST)[4:]
        if chain_of_trust_out:
            DeviceIntegrityMXS22._save_chain_of_trust(
                chain_of_trust, chain_of_trust_out)

        certs = cbor.loads(chain_of_trust)
        certs.append(dev_cert)
        certs.append(alias_cert)

        packet = cbor.loads(dev_rsp.get(CoseSign1Packet.COSE_PACKET_ID))
        resp_assets = cbor.loads(packet.value[2])
        dice_raw_key = resp_assets.get(DeviceResponse.DICE_DEV_ID_PUB_KEY)
        dice_key = ECHandler.populate_public_key(dice_raw_key)
        alias_raw_key = resp_assets.get(DeviceResponse.ALIAS_PUB_KEY)
        alias_key = ECHandler.populate_public_key(alias_raw_key)
        pkt = dev_rsp.get(CoseSign1Packet.COSE_PACKET_ID)
        resp_itms = DeviceIntegrityMXS22._verify(pkt, alias_key, 'Region data')

        dev_cert = DeviceIntegrityMXS22.process_dev_cert(dev_cert, device_out)
        alias_cert = DeviceIntegrityMXS22.process_alias_cert(
            alias_cert, dice_key, alias_out)
        nonce = resp_itms.get(DeviceResponse.NONCE)
        regions_data = resp_itms.get(DeviceResponse.REGION_HASH)
        assets = dev_cert
        assets.update(alias_cert)
        assets['NONCE'] = nonce
        assets['REGIONS'] = regions_data
        assets['CHAIN_OF_TRUST'] = certs

        return assets

    @staticmethod
    def _parse_app_results(app_results):
        app_data = None
        try:
            app_data = cbor.loads(app_results)
        except Exception:  # pylint: disable=broad-except
            pass

        if int.from_bytes(app_results[:4], byteorder='little') == len(
                app_results[4:]):
            try:
                app_data = cbor.loads(app_results[4:])
            except Exception as exc:
                raise ValueError(
                    'Unexpected format of app out results data') from exc
            logger.debug(
                'Used integrity_exam out results with additional size info')

        return app_data.get(DeviceResponse.DEV_RSP)

    @staticmethod
    def _save_chain_of_trust(chain_of_trust, output):
        out_path, ext = os.path.splitext(output)
        for i, cert in enumerate(cbor.loads(chain_of_trust)):
            cert_path = out_path + '_' + str(i) + ext
            abs_path = os.path.abspath(cert_path)
            with open(abs_path, 'wb') as f:
                f.write(cert)
            logger.info("Created certificate '%s'", abs_path)

    @staticmethod
    def process_cert(json_data, cert, output):
        """Process cert data against base template
        @param json_data: Cert JSON data
        @param cert: Cert payload
        @param output: Path to save cert
        @return: Dictionary cert data
        """
        version = json_data.get('VERSION')
        cert_validate = CertTemplateValidatorMXS22()
        base = cert_validate.find_base_template(version)
        if version:
            cert_type = json_data.get('TEMPLATE_TYPE')
        else:
            cert_type = 'version 0'
            for itm, val in json_data.items():
                if itm in base and base[itm].get('type') == 'VERSION':
                    json_data[itm] = VersionProviderMXS22.convert_fw_version(val)
        cert_ctx = CertificateStrategyMXS22()
        display_data = cert_ctx.display_cert(json_data, base)
        if output and output.endswith('.json'):
            cert_ctx.save_json_cert(display_data, cert, output)
        elif output:
            DeviceIntegrityMXS22.save_certificate(cert, output, cert_type)
        return display_data

    @staticmethod
    def process_alias_cert(cert, key, output):
        """Process Alias cert info
        @param cert: Alias cert payload
        @param key: Key to verify cert
        @param output: Path to save Alias cert
        @return: Tuple of Alias cert assets data
        """
        DeviceIntegrityMXS22.framed_text('ALIAS_CERTIFICATE')
        cert_data = DeviceIntegrityMXS22._verify(cert, key, 'Alias_certificate')
        alias_cert = DeviceIntegrityMXS22.process_cert(cert_data, cert, output)

        return alias_cert

    @staticmethod
    def process_dev_cert(cert, output):
        """Process Device cert info
        @param cert: Device cert payload
        @param output: Path to save Device cert
        @return: Tuple of Alias cert assets data
        """
        DeviceIntegrityMXS22.framed_text('DEVICE_CERTIFICATE')
        payload = cbor.loads(cert)
        data = cbor.loads(payload.value[2])
        return DeviceIntegrityMXS22.process_cert(data, cert, output)

    @staticmethod
    def save_certificate(cert, output, message):
        """Saves certificate"""
        cert_path = os.path.abspath(output)
        with open(cert_path, 'wb') as f:
            f.write(cert)
        logger.info("Created %s certificate '%s'", message, cert_path)

    @staticmethod
    def collect_in_params(in_params, target=None, tool=None):
        """Collects in_params and device info"""
        with open(in_params, 'rb') as f:
            app_input_data = cbor.loads(f.read()[4:])
        app_input = app_input_data.get(DeviceIntegrity.ENTR_EXAM_CMD)
        in_cert = cbor.loads(app_input.get(CoseSign1Packet.COSE_PACKET_ID))
        in_nonce = app_input.get(DeviceIntegrity.NONCE)
        regions_data = cbor.loads(in_cert.value[2])
        in_regions = regions_data.get(DeviceIntegrity.REGIONS)
        silicon_id = None
        family_id = None
        silicon_rev = None
        die_id = None
        if tool:
            dev_info = target.silicon_data_reader.read_device_info(tool)
            silicon_id = dev_info.silicon_id
            family_id = dev_info.family_id
            silicon_rev = dev_info.silicon_rev
            die_id = target.silicon_data_reader.read_die_id(tool)
        assets = IntegrityAssets(
            silicon_id, family_id, silicon_rev, die_id, in_nonce, in_regions)
        return assets

    @staticmethod
    def _verify(cbor_data, public_key, message):
        """Verifies and decodes cbor data"""
        ctx = COSE.new()
        json_key = ECHandler.public_jwk(public_key, None)
        cose_key = COSEKey.from_jwk(json_key)
        try:
            packet = ctx.decode(cbor_data, cose_key)
            logger.info('%s verification success', message)
        except VerifyError:
            logger.error('%s verification failed', message)
            return None
        return cbor.loads(packet)
