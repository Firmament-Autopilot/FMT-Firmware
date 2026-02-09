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
import cbor


class CborParser:
    """Parses CBOR recursively"""

    @staticmethod
    def convert(data, offset=0):
        """Converts CBOR into dict"""
        if isinstance(data, str):
            with open(data, 'rb') as f:
                data = f.read()[offset:]

        return CborParser.parse(data)

    @staticmethod
    def parse(obj):
        """Parses CBOR item recursively"""
        if isinstance(obj, bytes):
            try:
                res = cbor.loads(obj)
            except Exception:  # pylint: disable=broad-exception-caught
                return f"h'{obj.hex().upper()}'"
            if cbor.dumps(res) != obj:
                return f"h'{obj.hex().upper()}'"
            return CborParser.parse(res)
        elif isinstance(obj, dict):
            return {(hex(k) if isinstance(k, int) else k):
                        CborParser.parse(v) for k, v in obj.items()}
        elif isinstance(obj, cbor.Tag):
            return {f'TAG({obj.tag})': CborParser.parse(obj.value)}
        elif isinstance(obj, (list, tuple)):
            return [CborParser.parse(v) for v in obj]
        else:
            return obj
