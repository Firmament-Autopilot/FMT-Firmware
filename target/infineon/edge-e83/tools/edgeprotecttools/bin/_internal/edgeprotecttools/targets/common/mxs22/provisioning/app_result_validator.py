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
import logging

from cbor import cbor
from cwt import COSE, COSEKey, VerifyError

from .....core.key_handlers.ec_handler import ECHandler
from .....targets.common.mxs22.enums import DeviceResponse, CoseSign1Packet

logger = logging.getLogger(__name__)


class AppResultsValidator:
    """Validates RAM app out results"""
    def __init__(self, results_path):
        self.results = results_path
        self.results_data = self.load_data(self.results)

    def validate(self):
        """Validates out results response packet signature if signed
         and returns RAM app status code
         """
        ctx = COSE.new()
        try:
            cbor_data = cbor.loads(self.results_data)
            assets = cbor.loads(cbor_data.value[2])
        except Exception as exc:
            raise ValueError('Unexpected format of response data') from exc
        raw_key = assets.get(DeviceResponse.ALIAS_PUB_KEY)
        if not raw_key:
            raw_key = assets.get(DeviceResponse.DICE_DEV_ID_PUB_KEY)
        status = int.from_bytes(assets.get(DeviceResponse.APP_STATUS), 'little')
        dice_key = ECHandler.populate_public_key(raw_key)
        json_key = ECHandler.public_jwk(dice_key, None)
        cose_key = COSEKey.from_jwk(json_key)
        try:
            signature = cbor_data.value[3]
        except Exception as exc:
            raise ValueError('Unexpected format of response data') from exc
        if signature:
            try:
                packet = ctx.decode(self.results_data, cose_key)
                logger.info('RAM app results verification success')
            except VerifyError:
                logger.error('RAM app results verification failed')
                return status
            try:
                out_res_data = cbor.loads(packet)
            except Exception as exc:
                raise ValueError(
                    'Unexpected format of response data') from exc
            return int.from_bytes(
                out_res_data.get(DeviceResponse.APP_STATUS), 'little')
        logger.info('RAM app results packet is unsigned')
        return status

    @staticmethod
    def load_data(results_path):
        """Loads devise response data"""
        with open(results_path, 'rb') as f:
            data = f.read()
        app_data = None
        try:
            app_data = cbor.loads(data)
        except Exception:  # pylint: disable=broad-except
            pass

        if int.from_bytes(data[:4], byteorder='little') == len(
                data[4:]):
            try:
                app_data = cbor.loads(data[4:])
            except Exception as exc:
                raise ValueError(
                    'Unexpected format of app out results data') from exc
            logger.debug(
                'Used out results with additional size info')
        device_response = app_data.get(DeviceResponse.DEV_RSP)
        results = device_response.get(CoseSign1Packet.COSE_PACKET_ID)
        return results

    @staticmethod
    def print_ram_app_status(code, status_codes):
        """
        Outputs RAM app status and description
        @param code: RAM app execution status code
        @param status_codes: RAM applications status codes
        return: ProvisioningStatus.OK if status CYAPP_SUCCESS
                else ProvisioningStatus.FAIL
        """
        status, desc = status_codes.status_by_code(code)
        msg = f'Application execution completed with status code: ' \
              f'({code:#010x}) - {status}: {desc}'
        if status == 'CYAPP_SUCCESS':
            logger.info(msg)
        else:
            logger.error(msg)
