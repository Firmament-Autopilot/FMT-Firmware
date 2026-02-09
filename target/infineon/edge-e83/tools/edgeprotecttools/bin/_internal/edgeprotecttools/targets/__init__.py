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
import os
from importlib import import_module

from ..core import package_name


def __target_map() -> dict:
    """Creates a target map dynamically based on the presence of the
    target directory.
    Each target is associated with a target builder. If the
    'target_builder.py' file is found in the directory, the target module
    is imported, and its local target map is retrieved. The resulting map
    consolidates the parts from all available targets
    """
    full_target_map = {}
    pkg_name = package_name()
    for entry in os.scandir(os.path.dirname(__file__)):
        if entry.is_dir() and 'target_builder.py' in os.listdir(entry.path):
            module = import_module(f'.targets.{entry.name}', package=pkg_name)
            target_map = module.target_map
            for k, v in target_map.items():
                if k in full_target_map:
                    full_target_map[k].update(v)
                else:
                    full_target_map.update({k: v})
    return full_target_map


def target_data(target_name, rev=None):
    """Gets target data from the map"""
    target_name = target_name.lower()
    target_map = __target_map()
    if 'class' in target_map[target_name]:
        return target_map[target_name]
    if rev:
        rev = rev.lower()
        if rev in target_map[target_name]:
            return target_map[target_name][rev]
        raise ValueError(
            f"Target '{target_name}' does not have revision '{rev}'")
    if 'default' in target_map[target_name]:
        return target_map[target_name]['default']
    return next(iter(target_map[target_name].items()))[1]


def print_targets():
    """Prints target list"""
    output = {}
    for target_name in __target_map():
        target = target_data(target_name)
        tmp = output.get(target['family'], [])
        tmp.append(target_name)
        output[target['family']] = tmp
    print('Supported targets and families:')
    for family, targets in output.items():
        print(f'{family}:')
        for target_name in targets:
            print(f'\t{target_name}')


def get_target_builder(director, target_name, rev=None):
    """Gets target builder by target name"""
    try:
        target = target_data(target_name, rev=rev)
        director.builder = target['class'](target_name, rev=rev)
        return director.builder
    except KeyError as e:
        raise ValueError(f'Unknown target "{target_name}"') from e


def print_targets_extended():
    """Prints extended target list"""
    print('target|type|display_name|family')
    for k in __target_map():
        data = target_data(k)
        print(f'{k}|{data["type"]}|{data["display_name"]}|{data["family"]}')


def is_mxs40v1(target):
    """Gets a value indicating whether the target belongs
    to MXS40v1 platform"""
    return target_data(target)['platform'] == 'psoc64'


def is_mxs40sv2(target):
    """Gets a value indicating whether the target belongs
    to MXS40Sv2 platform"""
    return target_data(target)['platform'] == 'mxs40sv2'


def is_cywxx829(target):
    """Gets a value indicating whether the target belongs
    to the CYW20829 or CYW89829 family
    """
    return target.lower() in ('cyw20829', 'cyw89829')


def is_mxs22(target):
    """Gets a value indicating whether the target belongs
    to MXS22 platform"""
    return target_data(target)['platform'] == 'mxs22'


def is_traveo_t2g(target):
    """Gets a value indicating whether the target belongs
    to Traveo T2G platform"""
    return target_data(target)['platform'] == 'traveo_t2g'


def is_cyw559xx(target):
    """Gets a value indicating whether the target belongs
    to cyw559xx platform"""
    return target_data(target)['platform'] == 'cyw559xx'

def is_psb3xxx(target):
    """Gets a value indicating whether the target is PSB3xxx"""
    return target.lower() == 'psb3xxx'
