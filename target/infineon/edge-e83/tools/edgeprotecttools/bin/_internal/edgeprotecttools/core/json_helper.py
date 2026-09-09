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
import json
from copy import deepcopy


def read_json(filename):
    """ Reads dictionary object from a JSON file """
    with open(filename, encoding='utf-8') as f:
        json_str = f.read()
        d = json.loads(json_str)
    return d


def dump_json(data, filename):
    """ Saves dictionary object to a JSON file """
    with open(filename, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=4)


def replace(datadict, lookup_key, value):
    """ Sets value to all fields with the specified name """
    replaced_dict = deepcopy(datadict)
    for k, v in datadict.items():
        if isinstance(v, dict):
            replaced_dict[k] = replace(datadict[k], lookup_key, value)
        if k == lookup_key:
            replaced_dict[k] = value
    return replaced_dict
