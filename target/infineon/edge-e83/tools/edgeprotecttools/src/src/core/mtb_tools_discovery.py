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
import os
import platform
import subprocess

from packaging import version

MTB_FULL_NAME = 'ModusToolbox'
MTB_TOOLS_DIR_PREFIX = 'tools_'
PTP_TOOLS_DIR_PREFIX = 'ModusToolboxProgtools-'


def mtb_tools_dir():
    """Gets a path to the 'tools_X.Y' directory of the latest MTB
    version (where X and Y are the version number of the 'tools' directory)
    """
    cy_tools_paths = os.environ.get('CY_TOOLS_PATHS')

    if cy_tools_paths:
        return cy_tools_paths

    mtb_directory = mtb_dir()
    if mtb_directory is None:
        return None

    tools = [d for d in os.listdir(mtb_directory) if d.startswith(
        MTB_TOOLS_DIR_PREFIX)]
    if len(tools) > 0:
        tools.sort()
        return os.path.join(mtb_directory, tools[-1])

    raise FileNotFoundError(
        f"'tools_X.Y' directory not found in '{mtb_directory}'")


def ptp_tools_dir():
    """Gets a path to the ProgToolsPack directory"""
    system = platform.system()
    if system == 'Windows':
        install_dir = os.path.join('C:', os.sep, 'Infineon', 'Tools')
    elif system == 'Linux':
        install_dir = os.path.join('/', 'opt', 'Tools')
    elif system == 'Darwin':
        install_dir = os.path.join('/', 'Applications')
    else:
        raise RuntimeError('Unsupported operating system')

    if not os.path.exists(install_dir):
        return None

    tools = [
        d for d in os.listdir(install_dir) if d.startswith(PTP_TOOLS_DIR_PREFIX)
    ]
    if len(tools) > 0:
        tools.sort()
        return os.path.join(install_dir, tools[-1])

    return None


def mtb_dir():
    """Gets a path to the MTB directory"""
    system = platform.system()
    if system in ('Windows', 'Linux'):
        path = os.path.join(os.path.expanduser('~'), MTB_FULL_NAME)
    elif system == 'Darwin':
        path = os.path.join('/Applications', MTB_FULL_NAME)
    else:
        raise RuntimeError('Unsupported operating system')

    return path if os.path.isdir(path) else None


def mtb_version():
    """Gets version of the latest MTB installation"""
    mtb_tools_path = mtb_tools_dir()
    if mtb_tools_path:
        last_dir = os.path.basename(os.path.normpath(mtb_tools_path))
        return last_dir.replace(MTB_TOOLS_DIR_PREFIX, '')
    return None


def ptp_version():
    """Gets version of the latest PTP installation"""
    ptp_tools_path = mtb_tools_dir()
    if ptp_tools_path:
        last_dir = os.path.basename(os.path.normpath(ptp_tools_path))
        return last_dir.replace(PTP_TOOLS_DIR_PREFIX, '')
    return None


def mtb_tools():
    """Gets paths to all MTB tools"""
    mtb_tools_path = mtb_tools_dir()

    system = platform.system()
    if system in ('Linux', 'Darwin'):
        exec_file = 'mtbquery'
    elif system == 'Windows':
        exec_file = 'mtbquery.exe'
    else:
        raise RuntimeError('Unsupported operating system')

    if mtb_tools_path:
        mtbquery = os.path.join(mtb_tools_path, 'mtbquery', exec_file)
        try:
            out = subprocess.check_output([mtbquery, '--alltools']).decode('utf-8')
        except FileNotFoundError:
            tools = None
        else:
            tools = {}
            for key, value in (ln.split('=') for ln in out.split('\n') if ln):
                tools[key] = value
        return tools
    return None


def mtb_tool_dir(tool_name):
    """Gets the path to the tool bundled with MTB"""
    tools = mtb_tools()
    if tools:
        mtb_latest_ver = mtb_version()
        if version.parse(mtb_latest_ver) >= version.parse('3.0'):
            tool_dir = tools.get(f'CY_TOOL_{tool_name}_BASE_ABS')
        else:
            tool_dir = tools.get(f'CY_TOOL_{tool_name}_BASE')
        if tool_dir:
            tool_dir = tool_dir.strip()
        return tool_dir
    return None


def ptp_tool_dir(tool_name):
    """Gets the path to the tool bundled with PTP"""

    ptp_dir = ptp_tools_dir()

    if ptp_dir:
        tools = os.listdir(ptp_dir)
    else:
        return None

    if tools and tool_name in tools:
        path = os.path.join(ptp_dir, tool_name)
        if os.path.exists(path):
            return path

    return None


def mtb_tool_exe(tool_name):
    """Gets the path to the tool bundled with MTB"""
    tools = mtb_tools()
    if tools:
        mtb_latest_ver = mtb_version()
        if version.parse(mtb_latest_ver) >= version.parse('3.0'):
            tool_exe = tools.get(f'CY_TOOL_{tool_name}_EXE_ABS')
        else:
            tool_exe = tools.get(f'CY_TOOL_{tool_name}_EXE')
        if tool_exe:
            tool_exe = tool_exe.strip()
        return tool_exe
    return None
