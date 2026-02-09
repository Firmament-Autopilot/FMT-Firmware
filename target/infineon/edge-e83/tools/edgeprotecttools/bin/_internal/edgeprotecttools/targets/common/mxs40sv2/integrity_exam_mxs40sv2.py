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
import logging
import os
import json
from collections import namedtuple

import cbor

from .asset_enums import DeviceIntegrity, DeviceResponse
from .enums import CoseSign1Packet
from ..flow_parser import FlowParser
from ....core.entrance_exam_base import EntranceExam, EntranceExamRegion
from ....core.enums import EntranceExamStatus, ProvisioningStatus
from ....core.provisioning_flows.app_loading_flow import AppLoadingFlow
from ....core.target_director import Target

logger = logging.getLogger(__name__)

IntegrityAssets = namedtuple(
    'IntegrityAssets', 'silicon_id family_id si_rev_id die_id nonce regions')

MergedCert = namedtuple(
    'MergedCert', 'in_params out_results cert')


class IntegrityExamMXS40Sv2(EntranceExam):
    """Verifies that the device is in the expected state"""

    def __init__(self, target: Target, **kwargs):
        super().__init__(target, **kwargs)
        self.reg_map = target.register_map
        self.target = target

    def collect_integrity_assets(self, nonce, regions, tool=None):
        """Collects integrity assets"""
        si_id = None
        family_id = None
        si_rev = None
        die_id = None

        if not regions:
            raise ValueError('Corrupt integrity assets format')

        if tool:
            si_id, si_rev, family_id, die_id, _ = self.read_silicon_data(tool)

        assets = IntegrityAssets(
            si_id, family_id, si_rev, die_id, nonce, regions
        )

        return assets

    def collect_in_params(self, in_params, tool=None):
        """Collects in_params"""
        app_data = self._load_app_data(in_params)

        app_input = app_data.get(DeviceIntegrity.INTEGRITY_EXAM_CMD)
        in_cert = cbor.loads(app_input.get(CoseSign1Packet.COSE_PACKET_ID))
        regions_data = cbor.loads(in_cert.value[2])

        regions = self.collect_regions(
            regions_data.get(DeviceIntegrity.REGIONS)
        )

        nonce = app_input.get(DeviceIntegrity.NONCE)
        if not nonce:
            raise ValueError('Corrupt nonce format')

        return self.collect_integrity_assets(nonce, regions, tool=tool)

    def collect_out_results(self, out_results, tool=None):
        """Collects out_results"""
        app_data = self._load_app_data(out_results)

        app_input = app_data.get(DeviceResponse.DEV_RSP)
        in_cert = cbor.loads(app_input.get(CoseSign1Packet.COSE_PACKET_ID))
        regions_data = cbor.loads(in_cert.value[2])

        regions = self.collect_regions(
            regions_data.get(DeviceResponse.REGION_HASH)
        )

        nonce = regions_data.get(DeviceResponse.NONCE)
        if not nonce:
            raise ValueError('Corrupt nonce format')

        return self.collect_integrity_assets(nonce, regions, tool=tool)

    def collect_cert(self, cert_path):
        """Collects cert"""
        cert_data = self._load_template(cert_path)

        regions = self.collect_regions(cert_data.get('regions'))

        nonce = None

        return self.collect_integrity_assets(nonce, regions)

    def collect_custom_regions(self, custom_regions):
        """Collects custom regions"""
        if not custom_regions:
            return None

        custom_regions_data = self._load_template(custom_regions)
        regions = custom_regions_data.get('regions')

        if not regions:
            return None

        result = []

        for region in regions:
            if region.get('enabled'):
                region['operation'] = 'hash'
                result.append(region)

        return self.collect_regions(result)

    @staticmethod
    def collect_regions(regions):
        """Parses and collects regions """
        result = []

        if not isinstance(regions, list):
            raise ValueError('Corrupt regions format')

        for region in regions:
            if isinstance(region, list):
                address, size = list(map(list, zip(*region[:-1])))
                content = region[-1]
                result.append(EntranceExamRegion(address=address,
                                                 size=size,
                                                 content=content))
            elif isinstance(region, dict):
                if 'region' in region:
                    address, size = list(map(list, zip(*region.get('region'))))
                else:
                    address, size = None, None
                description = region.get('description')
                operation = region.get('operation')
                content = region.get('hash') if operation == 'hash' else None
                label = region.get('label')
                owner = region.get('owner')

                if operation == 'hash' and not content:
                    raise ValueError('Corrupt region format')

                entrance_exam_region = EntranceExamRegion(
                    address=address,
                    size=size,
                    description=description,
                    label=label,
                    operation=operation,
                    owner=owner,
                    content=content
                )
                logger.debug(repr(entrance_exam_region))
                result.append(entrance_exam_region)
            else:
                raise ValueError('Corrupt region type')

        return result

    @staticmethod
    def patch_custom_regions(cert_assets: IntegrityAssets,
                             in_assets: IntegrityAssets,
                             custom_regions: list):
        """Patches custom regions"""
        cert_regions = []
        in_regions = []

        if len(in_assets.regions) != len(cert_assets.regions):
            raise ValueError('Corrupt regions format')

        for i_region, c_region in zip(in_assets.regions, cert_assets.regions):
            for custom_region in custom_regions:
                if i_region == c_region == custom_region:
                    if i_region.owner != 'OEM' or c_region.owner != 'OEM':
                        logger.error('Only OEM region can be altered '
                                     'using custom region')
                        logger.error('certificate region: %s', c_region)
                        logger.error('in_params region: %s', i_region)
                        raise ValueError('Unable to alter region')
                    cert_regions.append(
                        EntranceExamRegion(
                            address=c_region.address,
                            size=c_region.size,
                            description=c_region.description,
                            label=c_region.label,
                            operation=c_region.operation,
                            owner=c_region.owner,
                            content=custom_region.content
                        )
                    )
                    in_regions.append(
                        EntranceExamRegion(
                            address=i_region.address,
                            size=i_region.size,
                            description=i_region.description,
                            label=i_region.label,
                            operation=i_region.operation,
                            owner=i_region.owner,
                            content=custom_region.content
                        )
                    )
                    break
            else:
                cert_regions.append(c_region)
                in_regions.append(i_region)

        cert_result = IntegrityAssets(
            cert_assets.silicon_id,
            cert_assets.family_id,
            cert_assets.si_rev_id,
            cert_assets.die_id,
            cert_assets.nonce,
            cert_regions
        )

        in_result = IntegrityAssets(
            in_assets.silicon_id,
            in_assets.family_id,
            in_assets.si_rev_id,
            in_assets.die_id,
            in_assets.nonce,
            in_regions
        )

        return cert_result, in_result

    def read_silicon_data(self, tool):
        """Reads silicon data"""
        info = self.target.silicon_data_reader.read_device_info(tool)
        die_id = self.target.silicon_data_reader.read_die_id(tool)
        lcs = self.target.version_provider.get_lifecycle_stage(tool)
        return info.silicon_id, info.silicon_rev, info.family_id, die_id, lcs

    def log_silicon_data(self, tool):
        """Prints silicon data"""
        prefix = '* '
        si_id, si_rev, family_id, die_id, lcs = self.read_silicon_data(tool)

        self.framed_text('SILICON INFO')

        logger.info('%sSilicon ID: 0x%02X', prefix, si_id)
        logger.info('%sFamily ID: 0x%02X', prefix, family_id)
        logger.info('%sRevision ID: 0x%01X', prefix, si_rev)

        logger.info('%sDie ID: ', prefix)
        for k, v in die_id.items():
            logger.info('%s- %s: %s', prefix, k, v)

        logger.info('%sLCS: %s', prefix, lcs)

        self.framed_line()

    def execute(self, tool, **kwargs):
        """
        Execute device integrity RAM app to collect and verify device regions
        data to ensure that this is a genuine Infineon device and it is in a
        known state
        """
        self.framed_text('DEVICE INTEGRITY CHECK')
        cert_assets = self.collect_cert(kwargs.get('integrity_cert'))
        custom_regions = self.collect_custom_regions(
            kwargs.get('custom_regions')
        )
        if tool:
            self.log_silicon_data(tool)
            flow, app = self.application_data(**kwargs)
            in_assets = self.collect_in_params(app.in_params_path, tool=tool)
            status = flow.run(tool)
            if status != ProvisioningStatus.OK:
                raise RuntimeError('Device integrity app execution failed')
            out_assets = self.collect_out_results(app.out_results_path,
                                                  tool=tool)
        else:
            in_assets = self.collect_in_params(kwargs.get('in_params'))
            out_assets = self.collect_out_results(kwargs.get('out_results'))

        if custom_regions:
            cert_assets, in_assets = self.patch_custom_regions(cert_assets,
                                                               in_assets,
                                                               custom_regions)

        status = self.verify(in_assets, out_assets, cert_assets)

        if status == EntranceExamStatus.OK:
            self.framed_text('DEVICE INTEGRITY PASSED')
        else:
            self.framed_text('DEVICE INTEGRITY FAILED')
        return status

    def verify(self, in_assets: IntegrityAssets, out_assets: IntegrityAssets,
               cert_assets: IntegrityAssets):
        """Verifies nonce and regions data"""
        status = self.verify_nonce(in_assets, out_assets)

        if status == EntranceExamStatus.OK:
            status = self.verify_regions(in_assets, out_assets, cert_assets)

        return status

    @staticmethod
    def verify_nonce(in_assets: IntegrityAssets, out_assets: IntegrityAssets):
        """Verifies nonce data"""
        if out_assets.nonce == in_assets.nonce:
            logger.info('NONCE: %s', out_assets.nonce.hex().upper())
            status = EntranceExamStatus.OK
        else:
            logger.info('Nonce mismatch')
            logger.info('IN_NONCE  : %s', in_assets.nonce.hex().upper())
            logger.info('OUT_NONCE : %s', out_assets.nonce.hex().upper())
            status = EntranceExamStatus.FAIL
        return status

    def verify_regions(self, in_assets: IntegrityAssets,
                       out_assets: IntegrityAssets,
                       cert_assets: IntegrityAssets):
        """Verifies regions data"""
        queue = []

        for m_c in zip(in_assets.regions,
                       out_assets.regions,
                       cert_assets.regions):
            merged_cert = MergedCert(*m_c)
            self._validate_merged_cert(merged_cert)
            queue.append(merged_cert)

        ifx_regions = filter(lambda x: (x.cert.owner == 'IFX'), queue)
        oem_regions = filter(lambda x: (x.cert.owner == 'OEM'), queue)
        return_regions = filter(lambda x: (x.cert.operation == 'return'), queue)

        ifx_success, ifx_count = 0, 0
        oem_success, oem_count = 0, 0
        regions_count = 0

        self.framed_text('IFX Regions data')
        for m_c in ifx_regions:
            status, info = self._process_region(m_c)
            self.log_region(m_c, info=info, status=status)
            if status == EntranceExamStatus.OK:
                ifx_success += 1
            ifx_count += 1

        self.framed_text('OEM Regions data')
        for m_c in oem_regions:
            status, info = self._process_region(m_c)
            self.log_region(m_c, info=info, status=status)
            if status == EntranceExamStatus.OK:
                oem_success += 1
            oem_count += 1

        self.framed_text('Regions data')
        for m_c in return_regions:
            self.log_region(m_c)
            regions_count += 1

        if ifx_count + oem_count + regions_count != len(queue):
            raise ValueError('Corrupt regions format')

        self.framed_line()
        logger.info('Total regions: %s', len(queue))
        logger.info('Return regions count: %d', regions_count)
        self.log_statistics('IFX', ifx_success, ifx_count)
        self.log_statistics('OEM', oem_success, oem_count)

        if ifx_success == ifx_count and oem_success == oem_count:
            return EntranceExamStatus.OK

        return EntranceExamStatus.FAIL

    @staticmethod
    def log_region(m_c: MergedCert, info=None, status=None):
        """Prints region info"""
        logger.info('Region')
        for address, size in zip(m_c.out_results.address, m_c.out_results.size):
            logger.info('- Address: 0x%08X, Size: %s', address, size)
        if m_c.cert.description:
            logger.info('- Description: %s', m_c.cert.description)
        if m_c.cert.label:
            logger.info('- Label: %s', m_c.cert.label)
        if m_c.cert.owner:
            logger.info('- Owner: %s', m_c.cert.owner)

        operation = m_c.in_params.operation
        if operation == 'return':
            if m_c.out_results.content:
                logger.info('- Value: %s', m_c.out_results.content)
            else:
                logger.info('- Corrupt value for return region')
        elif operation == 'hash':
            i_hash = m_c.in_params.content
            o_hash = m_c.out_results.content
            if status == EntranceExamStatus.OK:
                logger.info('- Hash match')
                logger.info('- Hash: %s', o_hash)
            else:
                logger.info('- Hash mismatch')
                if isinstance(i_hash, list):
                    for itm in i_hash:
                        logger.info('- IN_HASH  : %s',
                                    itm.get('hash').hex().upper())
                else:
                    logger.info('- IN_HASH  : %s', i_hash)
                logger.info('- OUT_HASH : %s', o_hash)
        else:
            raise ValueError('Unsupported operation type')

        if info:
            info_description = info.get('description')
            info_value = info.get('value')
            if info_description:
                logger.info('- Hash Description : %s', info_description)
            if info_value:
                logger.info('- Hash Version : %s', info_value)

    def application_data(self, **kwargs):
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

    @staticmethod
    def log_statistics(name, success: int, total: int):
        """Prints statistics"""
        if success == total:
            logger.info('%s hash regions passed (%d/%d)', name, success, total)
            logger.info('%s hash regions exam success', name)
        else:
            logger.error('%s hash regions passed (%d/%d)', name, success, total)
            logger.error('%s hash regions exam failed', name)

    @staticmethod
    def _process_region(m_c: MergedCert):
        """Process labeled region"""
        status = EntranceExamStatus.FAIL
        info = None

        cert_hash = m_c.cert.content
        out_hash = m_c.out_results.content

        if not (m_c.cert.label or m_c.in_params == m_c.out_results == m_c.cert):
            raise ValueError('Regions do not match')

        if cert_hash and out_hash:
            if isinstance(cert_hash, str):
                if cert_hash == out_hash:
                    status = EntranceExamStatus.OK
            elif isinstance(cert_hash, list):
                for row in cert_hash:
                    if isinstance(row, dict):
                        if row.get('hash') == out_hash:
                            status = EntranceExamStatus.OK
                            info = row
                            break
                    else:
                        raise ValueError('Corrupt certificate data')

            else:
                raise ValueError('Corrupt certificate data')

        return status, info

    @staticmethod
    def _validate_merged_cert(m_c: MergedCert):
        logger.debug('Certificate validation')
        logger.debug('- in_params: %s', repr(m_c.in_params))
        logger.debug('- out_results: %s', repr(m_c.out_results))
        logger.debug('- cert: %s', repr(m_c.cert))

        if not m_c.in_params == m_c.out_results == m_c.cert:
            if not (m_c.in_params.label and m_c.cert.label
                    and m_c.in_params.label == m_c.cert.label
                    and m_c.out_results.address and m_c.out_results.size):
                raise ValueError('Provided in_params, out_results and '
                                 'certificate do not match')

        for attr in ('address', 'size', 'label', 'operation', 'owner'):
            if getattr(m_c.in_params, attr) != getattr(m_c.cert, attr):
                raise ValueError('Certificate does not match in_params')

        in_content = m_c.in_params.content
        cert_content = m_c.cert.content

        if in_content != cert_content:
            if isinstance(in_content, list) and isinstance(cert_content, list):
                for i_row, c_row in zip(in_content, cert_content):
                    if not (i_row.get('hash') and c_row.get('hash')
                            and i_row.get('value') and c_row.get('value')):
                        raise ValueError('Certificate does not match in_params')
                    if i_row['value'] != c_row['value']:
                        raise ValueError('Certificate does not match in_params')
                    if i_row['hash'].hex().upper() != c_row['hash'].upper():
                        raise ValueError('Certificate does not match in_params')
            else:
                raise ValueError('Certificate does not match in_params')

    def framed_text(self, message, line_len=41):
        """Display info with separation"""
        self.framed_line(line_len=line_len)
        logger.info(' ' * ((line_len - len(message)) // 2) + message)
        self.framed_line(line_len=line_len)

    @staticmethod
    def framed_line(line_len=41):
        """Prints delimiter row"""
        logger.info('*' * line_len)

    @staticmethod
    def _load_app_data(path, validate_size=True):
        """Loads app data in CBOR format"""
        if validate_size:
            with open(path, 'rb') as f:
                data = f.read()
            if int.from_bytes(data[:4], byteorder='little') != len(data[4:]):
                raise ValueError('Packet size mismatch')
            return cbor.loads(data[4:])
        else:
            with open(path, 'rb') as f:
                return cbor.load(f.read())

    @staticmethod
    def _load_template(json_path):
        """Loads template data"""
        abs_path = os.path.abspath(json_path)
        with open(abs_path, 'r', encoding='utf-8') as f:
            cert_template = json.load(f)
        return cert_template

    def _get_flow(self, apps_type=None):
        flow_parser = FlowParser(self.target, test_pkg_type=apps_type)
        apps = flow_parser.apps_by_flow('integrity_exam')
        if not apps:
            raise ValueError('RAM applications list is empty')

        app_dir = self.target.project_initializer.apps_dir
        flow = AppLoadingFlow(self.target, 'integrity_exam', app_dir,
                              test_pkg_type=apps_type)
        return flow
