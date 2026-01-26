# Table of Contents
- [Description](#description)
- [Usage examples](#usage-examples)
    - [Using PyInstaller on macOS](#using-pyinstaller-on-macos)
    - [Using PyInstaller on Ubuntu Linux](#using-pyinstaller-on-ubuntu-linux)
    - [Using PyInstaller on Windows](#using-pyinstaller-on-windows)


# Description

This README describes how to generate the Edge Protect Tools binary package using the PyInstaller utility. The resulting package includes all dependencies and the executable, which can run without Python installed.

The generated package is not cross-platform, so it must be executed on the platform with the same type.

Build the package on the same version or a newer version of the operating system the package is intended for.

For example, binaries generated on Ubuntu 22.04 can be executed on Ubuntu 22.04 or 24.04, but not on Ubuntu 20.04.

Use the current Edge Protect Security Suite version in the `ModusToolbox-Edge-Protect-Security-Suite-1.X` directory while following this README.

# Usage examples
## Using PyInstaller on macOS

This manual supports only macOS 12, 13, and 14. The other versions have not been tested.

1. Download and install Python version 3.9 - 3.13 from the official [Python download page](https://www.python.org/downloads)

Note: If Python version 3.9 - 3.13 is already installed on the system, you can skip this step.

2. Create a working directory wherever you prefer, for example, `workdir` in your home folder:

```bash
mkdir ~/workdir
```

3. Set `workdir` as the current working directory:

```bash
cd ~/workdir
```

4. Install the Python virtual environment package with the command:

```bash
pip3 install --upgrade --force-reinstall virtualenv
```

5. Create virtual environment space:

```bash
virtualenv venv
```

6. Activate the virtual environment:

```bash
source ./venv/bin/activate
```

7. Grant the write permission to all users if the Edge Protect Security Suite has been installed with root privileges:

```bash
sudo chmod o+w /Applications/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/src
```

8. Install Edge Protect Tools from the sources directory:

```bash
pip3 install --upgrade --force-reinstall /Applications/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/src
```

Note: If the Edge Protect Security Suite was installed for the current user only, use `~` before the `/Applications/...` path

```bash
pip3 install --upgrade --force-reinstall ~/Applications/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/src
```

9. Install PyInstaller package version 6.14.1:

```bash
pip3 install pyinstaller==6.14.1
```

10. Generate the Edge Protect Tools standalone application:

```bash
pyinstaller /Applications/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/build/pyinstaller.spec --distpath . --log-level DEBUG
```

Note: If the Edge Protect Security Suite was installed for the current user only, use `~` before the `/Applications/...` path

```bash
pyinstaller ~/Applications/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/build/pyinstaller.spec --distpath . --log-level DEBUG
```

11. Deactivate the virtual environment with the command:

```bash
deactivate
```

The generated Edge Protect Tools binary is located in the `~/workdir/edgeprotecttools` folder.

Note: The `~/workdir/edgeprotecttools/_internal` folder is also necessary for the normal Edge Protect Tools executable functionality.


## Using PyInstaller on Ubuntu Linux

This manual supports Ubuntu Linux 20.04, 22.04, and 24.04.

1. Install Python version 3.9 - 3.13 depending on Ubuntu version:

```bash
sudo apt install -y python3-dev
```

Note: If Python version 3.9 - 3.13 is already installed on the system, you can skip this step.

2. Create a working directory wherever you prefer, for example, `workdir` in your home folder:

```bash
mkdir ~/workdir
```

3. Set `workdir` as the current working directory:

```bash
cd ~/workdir
```

4. Install the Python virtual environment package with the command:

```bash
pip3 install --upgrade --force-reinstall virtualenv
```

5. Create virtual environment space:

```bash
virtualenv venv
```

6. Activate the virtual environment:

```bash
source ./venv/bin/activate
```

7. Grant the write permission to all users if the Edge Protect Security Suite has been installed with root privileges:

```bash
sudo chmod o+w /opt/Tools/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/src
```

8. Install Edge Protect Tools from the sources directory:

```bash
pip3 install --upgrade --force-reinstall /opt/Tools/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/src
```

9. Install PyInstaller package version 6.14.1:

```bash
pip3 install pyinstaller==6.14.1
```

10. Generate the Edge Protect Tools standalone application:

```bash
pyinstaller /opt/Tools/ModusToolbox-Edge-Protect-Security-Suite-1.X/tools/edgeprotecttools/build/pyinstaller.spec --distpath . --log-level DEBUG
```

11. Deactivate the virtual environment with the command:

```bash
deactivate
```

The generated Edge Protect Tools binary is located in the `~/workdir/edgeprotecttools` folder.

Note: The `~/workdir/edgeprotecttools/_internal` folder is also necessary for the normal Edge Protect Tools executable functionality.


## Using PyInstaller on Windows

This manual supports Windows 10 and Windows 11.

1. Download and install Python version 3.9 - 3.13 from the official [Python download page](https://www.python.org/downloads)

Note: If Python version 3.9 - 3.13 is already installed on the system, you can skip this step.

Set the "Add Python.exe to PATH" checkbox at the bottom in the first (initial) installation window.

2. Open the `Command Prompt` window and create a working directory wherever you prefer, for example, `workdir` in your home folder:

```commandline
md %HOMEPATH%\workdir
```

3. Set `workdir` as the current working directory:

```commandline
cd %HOMEPATH%\workdir
```

4. Install the Python virtual environment package with the command:

```commandline
pip install --upgrade --force-reinstall virtualenv
```

5. Create virtual environment space:

```commandline
virtualenv venv
```

6. Activate the virtual environment:

```commandline
venv\Scripts\activate
```

7. Install Edge Protect Tools from the sources directory:


For the current user installation of the Edge Protect Security Suite, use a command like:

```commandline
pip install --upgrade --force-reinstall C:\Users\%USERNAME%\Infineon\Tools\ModusToolbox-Edge-Protect-Security-Suite-1.X\tools\edgeprotecttools\src
```

For the installation with administrator privileges, use a command like:

```commandline
pip install --upgrade --force-reinstall C:\Infineon\Tools\ModusToolbox-Edge-Protect-Security-Suite-1.X\tools\edgeprotecttools\src
```

8. Install PyInstaller package version 6.14.1:

```commandline
pip install pyinstaller==6.14.1
```

9. Generate the Edge Protect Tools standalone application:

For the current user installation of the Edge Protect Security Suite, use a command like:

```commandline
pyinstaller C:\Users\%USERNAME%\Infineon\Tools\ModusToolbox-Edge-Protect-Security-Suite-1.X\tools\edgeprotecttools\build\pyinstaller.spec --distpath . --log-level DEBUG
```

For the installation with administrator privileges, use a command like:

```commandline
pyinstaller C:\Infineon\Tools\ModusToolbox-Edge-Protect-Security-Suite-1.X\tools\edgeprotecttools\build\pyinstaller.spec --distpath . --log-level DEBUG
```

10. Deactivate the virtual environment with the command:

```commandline
deactivate
```

The generated Edge Protect Tools binary is located in the `workdir/edgeprotecttools` folder.

Note: The `workdir/edgeprotecttools/_internal` folder is also necessary for the normal Edge Protect Tools executable functionality.
