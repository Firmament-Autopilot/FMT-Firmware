This package contains security tools for creating keys, creating certificates, signing user applications, and provisioning Cypress/Infineon MCUs.

# Table of Contents
- [Prerequisites](#prerequisites)
- [Standalone Executable](#standalone-executable)
- [Installing From Sources](#installing-from-sources)
- [Supported Devices](#supported-devices)
- [Interface and Usage](#interface-and-usage)
- [Logging](#logging)
- [Known Issues](#known-issues)
- [Error Handling](#error-handling)
- [License and Contributions](#license-and-contributions)

# Prerequisites
* Python 3.9 - 3.13 if not using the executable.
* [Installed Infineon OpenOCD](https://github.com/Infineon/openocd/releases)
* Ensure the KitProg3 programming mode is **CMSIS-DAP Bulk**

# Standalone Executable
Edge Protect Tools can be used as a standalone application. The executable can be found in the `tools/edgeprotecttools/bin` directory of the Edge Protect Security Suite or Early Access Pack installation.

# Installing From Sources
Alternatively Edge Protect Tools can be installed from the sources as a Python package. The source code is located in the `tools/edgeprotecttools/src` directory of the Edge Protect Security Suite or Early Access Pack installation.

Install Python 3.13 on your computer. You can download it from https://www.python.org/downloads/. Set up the appropriate environment variable(s) for your operating system.

## Installing Package
Make sure that you have the latest version of pip installed, use
the following command.
```bash
$ python -m pip install --upgrade pip
```
Run the following command, from the Early Access Pack or Edge Protect Security Suite directory.
```bash
$ python -m pip install tools/edgeprotecttools/src
```

## Updating Package
To update the already installed package, run the following command from the Early Access Pack or Edge Protect Security Suite directory.
```bash
$ python -m pip install --upgrade --force-reinstall tools/edgeprotecttools/src
```

*Note*: There may be some pip dependency resolver errors. In most cases, these can be safely ignored.

*Note*: You can use the following command to show the path to the installed package
`$ python -m pip show edgeprotecttools`.


# Supported Devices
| Device                   | Documentation                                                   |
|--------------------------|-----------------------------------------------------------------|
| PSOC™ 64 Secure MCU      | [README_PSOC64.md](docs/README_PSOC64.md)                       |
| XMC7000 Industrial MCU   | [README_XMC7XXX.md](docs/README_XMC7XXX.md)                     |
| AIROC™ CYW20829/CYW89829 | [README_CYW20829_CYW89829.md](docs/README_CYW20829_CYW89829.md) |
| AIROC™ CYW559xx          | [README_CYW559XX.md](docs/README_CYW559XX.md)                   |
| PSOC™ Control C3         | [README_PSOCC3.md](docs/README_PSOCC3.md)                       |
| PSOC™ Edge 84 MCU        | [README_PSE8X.md](docs/README_PSE8X.md)                         |

Use `device-list` command for output of the supported devices list.
```bash
$ edgeprotecttools device-list
```


# Interface and Usage
For instructions how to use common commands, see [README_GENERAL.md](docs/README_GENERAL.md).

For instructions how to use target-specific commands, see the corresponding readme file in the [docs](docs) directory.


# Logging
Every time the tool is invoked, a new log file is created in the _logs_ directory of the project. By default, the console output has INFO logging severity. The log file contains the DEBUG logging severity.


# Known Issues
## Installation Failure on macOS Big Sur Using `pip`
### Details
During the installation of the package via _pip_ on macOS Big Sur, the following exception is raised:
```
  ...
  distutils.errors.DistutilsError: Setup script exited with error: SandboxViolation:
  mkdir('/private/var/root/Library/Caches/com.apple.python/private/tmp/easy_install-y8c1npmz', 511) {}

  The package setup script has attempted to modify files on your system
  that are not within the EasyInstall build area, and has been aborted.

  This package cannot be safely installed by EasyInstall, and may not
  support alternate installation locations even if you run its setup
  script by hand.  Please inform the package's author and the EasyInstall
  maintainers to find out if a fix or workaround is available.
```
### Resolution 
Upgrade the `pip` package running the following command from the terminal: `python3 -m pip install --upgrade pip`.
## LibraryNotFoundError During Runtime on Ubuntu 24.04
### Details
During the runtime of the package on Ubuntu 24.04, the following exception is raised:
```
  oscrypto.errors.LibraryNotFoundError: Error detecting the version of libcrypto
```
### Workaround
Consider using an executable file. See [Standalone Executable](#standalone-executable).
### Resolution 
Upgrade the `oscrypto` package running the following command from the terminal: `pip install --upgrade --force-reinstall git+https://github.com/wbond/oscrypto.git@d5f3437`.

# Error Handling
Refer to the guidelines on how to [resolve errors](docs/README_ERRORS.md).

# License and Contributions
The software is provided under the Apache-2.0 license. Contributions to this project are accepted under the same license.
This project contains code from other projects. The original license text is included in those source files.
