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

logger = logging.getLogger(__name__)


class HCIResponseParser:
    """HCI response parser"""

    status_map = {
        0x00: 'Success',
        0x01: 'Unknown HCI Command',
        0x12: 'Invalid HCI Command Parameters'
    }

    event_map = {
        0x040e: 'HCI Command Complete Event',
        0x04ff: 'HCI Event'
    }

    opcode_map = {
        0x0c03: 'HCI_Reset',
        0xffed: 'HCI_Enter_Download_Mode',
        0xfc2e: 'HCI_Create_Connection',
        0xfd3b: 'HCI_Read_Supported_VCS',
        0xfc0c: 'HCI_Super_Duper_Peek_Poke',
        0xfdf4: 'HCI_Get_CSR',
        0xfde8: 'HCI_Read_SOC_ID'
    }

    def parse(self, data):
        """Parse HCI response data"""
        if not data or len(data) < 3:
            raise ValueError('Invalid HCI response')
        hci_packets = self._hci_packets(data)
        return self._extract_data(hci_packets)

    def _extract_data(self, response):
        """Extracts data from response packets"""
        payload = b''
        opcode = None
        command_name = None
        for packet in response:
            event = packet.get('event')
            packet_data = packet.get('data')
            idx = 0
            if self.event_map.get(event) == 'HCI Event':
                logger.debug('Event_Sub_Code = %s', hex(packet_data[idx]))
                idx += 1
            elif self.event_map.get(event) == 'HCI Command Complete Event':
                opcode = int.from_bytes(packet_data[idx: idx + 2], 'little')
                command_name = self.opcode_map.get(opcode)
                logger.debug(
                    'Command_Opcode = %s ("%s")', hex(opcode),
                    self.opcode_map.get(opcode))
                idx += 2

            p_offset = 0
            if self.event_map.get(event) == 'HCI Event':
                p_offset = packet_data[idx]
                logger.debug('Payload Offset = %s', p_offset)
                idx += 1
            else:
                status = packet_data[idx]
                logger.debug('Status = %s', status)
                if status in self.status_map:
                    logger.info(
                        'Status = %s (%s)', status, self.status_map.get(status))
                idx += 2
            try:
                p_length = packet_data[idx]
            except IndexError:
                logger.debug('Corrupted packet data')
                return None
            logger.debug('Payload Length = %s', p_length)
            start_data = idx + p_offset + 1
            payload += packet_data[start_data: start_data + p_length]

        result = {
            'opcode': opcode,
            'command_name': command_name,
            'payload_length': len(payload),
            'payload': payload
        }
        return result

    def _hci_packets(self, data):
        """Parse HCI response data and create separate packets"""
        packets = []
        event = int.from_bytes(data[0:2], 'big')
        if event not in self.event_map:
            raise ValueError('Unknown HCI event')
        while event in self.event_map:
            idx = 2
            packet_len = data[idx]
            event_name = self.event_map.get(event)
            idx += 1
            if event_name == 'HCI Command Complete Event':
                logger.debug('Num_HCI_Command_Packets =  %s', data[idx])
                idx += 1
            event_data_len = data[idx]
            logger.debug('%s lenght %s', event_name, event_data_len)
            if event_data_len > 0:
                packet_data = data[idx: packet_len + idx]
                packets.append({'event': event, 'data': packet_data})
            data = data[idx + packet_len:]
            if data:
                event = int.from_bytes(data[0:2], 'big')
            else:
                event = None

        return packets
