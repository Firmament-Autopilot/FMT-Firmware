# Table of Contents
- [Main features](#main-features)
- [Quick start](#quick-start)
- [Command-line interface](#command-line-interface)
    - [Tool help](#tool-help)
    - [Common options](#common-options)
    - [Create project](#create-project)
    - [Device Integrity Exam](#device-integrity-exam)
    - [Provision device](#provision-device)
    - [Reprovision device](#reprovision-device)
    - [Create provisioning packet](#create-provisioning-packet)
    - [Create DLM package](#create-dlm-package)
    - [Create debug token](#create-debug-token)
    - [Read die ID](#read-die-id)
    - [Get firmware version](#get-firmware-version)
    - [Get device info](#get-device-info)
- [Provisioning process](#provisioning-process)
- [Using package together with HSM](#using-package-together-with-hsm)
    - [Signing application with HSM](#signing-application-with-hsm)
    - [Signing reprovisioning packet with HSM](#signing-reprovisioning-packet-with-hsm)
    - [Reprovisioning with prebuilt data](#reprovisioning-with-prebuilt-data)
    - [Creation and signing a debug token with HSM](#creation-and-signing-a-debug-token-with-hsm)
    - [Creation and signing an RMA token with HSM](#creation-and-signing-an-rma-token-with-hsm)
- [Return Merchandise Authorization (RMA)](#return-merchandise-authorization-rma)
    - [RMA token](#rma-token)
    - [Transition to RMA](#transition-to-rma)
- [Protected Firmware Update](#protected-firmware-update)
    - [Protected FW Policy Provisioning](#protected-fw-policy-provisioning)
    - [Protected FW DFU](#protected-fw-dfu)


# Main features
* Keys creation - Creates a private-public key pair.
* Integrity exam - Passing an integrity exam before provisioning a device is an option to ensure that the device is a genuine Infineon device and it is in a known state.
* Provisioning - Provisioning is the act of configuring a device with an authorized set of keys, policies, and optionally certificates. Supports SWD and serial interface.
* Signing user applications - Signs a user application with a private key locally or using a Hardware Security Module.
* Debug token - The debug token is used to enable CM33 and/or the system access port when it is temporarily disabled.


# Quick start
## 1. Set a path to the On-Chip debugger
```bash
$ edgeprotecttools set-ocd --name openocd --path <PATH_TO_OPENOCD_ROOT_DIRECTORY>
```
Ensure that you provide the path to the root directory of OpenOCD (NOT _bin_ directory).
Specifying the path is not mandatory if you have ModusToolbox™ installed on your machine. OpenOCD from the ModusToolbox™ directory is used by default.

_Example:_
```bash
$ edgeprotecttools set-ocd --name openocd --path /Users/username/tools/openocd
```

## 2. Define a target
Run the following command and find the name of your target in the list of supported targets.
```bash
$ edgeprotecttools device-list
```
This target name will be used as a `-t` option value with each command.

_Example_:
```bash
$ edgeprotecttools -t psoc_c3 <COMMAND> [OPTIONS]
```

## 3. Create a new project
This copies the list of files required to start using the tool to the current working directory.
```bash
$ edgeprotecttools -t psoc_c3 init
```

## 5. Create keys
Create two private/public key pairs.
```bash
$ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/oem_rot_priv_key_0.pem keys/oem_rot_pub_key_0.pem
$ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/oem_rot_priv_key_1.pem keys/oem_rot_pub_key_1.pem
```

## 7. Provision the device
```bash
$ edgeprotecttools -t psoc_c3 provision-device -p policy/policy_oem_provisioning.json
```

## 8. Sign the image
```bash
$ edgeprotecttools sign-image --image image.bin --output image_signed.bin --key keys/oem_rot_priv_key_0.pem
```


# Command-line interface
This section contains the main CLI commands. More commands can be found in the tool help.

## Tool help
To see the list of commands supported for PSoC C3:
```bash
$ edgeprotecttools -t psoc_c3 --help
```
To see the list of options for a specific command:
```bash
$ edgeprotecttools -t psoc_c3 <COMMAND> --help
```

## Common options
The interface provides common options. These options are common for all commands and must precede them:

| Name          | Description                                  |
|---------------|----------------------------------------------|
| -t, --target  | Device name or family                        |
| -v, --verbose | Provides debug-level log                     |
| -q, --quiet   | Quiet display option                         |
| --logfile-off | Disabling logging to a file                  |
| --timestamps  | Enable displaying timestamps in log messages |


## Create project
Creates a new project for PSoC C3.
### Command: `init`
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 init
```


## Device Integrity Exam
The device integrity exam ensures that this is a genuine Infineon device and it is in a known state.
The integrity exam is implemented as a combination of a RAM application collecting device measurements and a host component validating device measurements.
The tool gets the RAM application output and compares it with the device integrity certificate data. This acceptance test is recommended before the device OEM provisioning and determines that there are no modifications of fuses or flash bits.
### Command: `integrity-exam`
### Parameters
| Name              | Optional/Required | Description                                                |
|-------------------|:-----------------:|------------------------------------------------------------|
| --probe-id        |     optional      | Probe serial number.                                       |
| --cert            |     required      | Path to the integrity certificate.                         |
| --custom-regions  |     optional      | Path to a custom regions template for integrity check.     |
| --key             |     optional      | Key to sign the DLM package.                               |
| --existing-packet |     optional      | Skip provisioning packet creation and use an existing one. |

### Usage example
```bash
$ edgeprotecttools -t psoc_c3 integrity-exam --probe-id 061003B803260400 --cert packets/device_integrity_cert.json
```

## Provision device
Configuring a device with a set of keys and policies.
### Command: `provision-device`
### Parameters
| Name              | Optional/Required | Description                                                                                                                                                       |
|-------------------|:-----------------:|-------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the provisioning policy.                                                                                                                              |
| --key, --key-path |     optional      | The path to the key used to sign the provisioning packet. If not specified, an unsigned packet will be created. Applicable only for policy type "prot_fw_policy". |
| --probe-id        |     optional      | Probe serial number.                                                                                                                                              |
| --existing-packet |     optional      | Skip provisioning packet creation and use the existing packet. This may be useful when a packet already exists and the tool does not have to generate it again.   |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 provision-device -p policy/policy_oem_provisioning.json --probe-id 061003B803260400
```

## Reprovision device
Reconfiguring a device with the updated policies.
### Command: `reprovision-device`
### Parameters
| Name              | Optional/Required | Description                                                                                                                                                     |
|-------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the reprovisioning policy.                                                                                                                          |
| --key, --key-path |     optional      | The path to the key used to sign the reprovisioning packet. If not specified, an unsigned packet will be created.                                               |
| --existing-packet |     optional      | Skip provisioning packet creation and use the existing packet. This may be useful when a packet already exists and the tool does not have to generate it again. |
| --probe-id        |     optional      | Probe serial number.                                                                                                                                            |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 reprovision-device -p policy/policy_oem_reprovisioning.json --key keys/oem_rot_priv_key_0.pem --probe-id 061003B803260400
```


## Create provisioning packet
Creates a provisioning/reprovisioning data packet without starting the device provisioning process.
### Command: `create-provisioning-packet`
### Parameters
| Name              | Optional/Required | Description                                                                                                       |
|-------------------|:-----------------:|-------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the provisioning policy.                                                                              |
| --key, --key-path |     optional      | The path to the key used to sign the reprovisioning packet. If not specified, an unsigned packet will be created. |
| -o, --output      |     optional      | The path where to save the packet.                                                                                |
### Usage example
#### Signed
```bash
# Provisioning
$ edgeprotecttools -t psoc_c3 create-provisioning-packet -p policy/policy_oem_provisioning.json
# Reprovisioning
$ edgeprotecttools -t psoc_c3 create-provisioning-packet -p policy/policy_oem_reprovisioning.json --key keys/oem_rot_priv_key_0.pem
```


## Create DLM package
Builds the RAM application and it's inputs into a single signed package.
### Command: `build-ramapp-package`
### Parameters
| Name              | Optional/Required | Description                                   |
|-------------------|:-----------------:|-----------------------------------------------|
| -a, --app         |     required      | The path to the RAM application binary.       |
| -o, --output      |     required      | The path to the DLM package output file.      |
| --inparams        |     optional      | The path to the application input parameters. |
| --key, --key-path |     optional      | Private key to sign the package.              |
| --hex-addr        |     optional      | Adjust address in hex output file.            |
| -S, --slot-size   |     optional      | Sets the maximum slot size.                   |
### Usage example
```bash
# Create signed DLM package (the --key option may be skipped for BOOT_SIMPLE_APP)
$ edgeprotecttools -t psoc_c3 build-ramapp-package --app packets/apps/prov_oem/cyapp_prov_oem_signed_ifx0.bin --inparams packets/apps/prov_oem/in_params.bin --key keys/oem_rot_priv_key_0.pem --output packets/apps/prov_oem/prov_oem_dlm.hex
```


## Create debug token
The debug token is used to enable CM33 or the system access port when it is temporarily disabled. Note that the token cannot enable an access port that is permanently disabled by the access restrictions. Also, the debug token can be used to enable/disable invasive or non-invasive debugging for CM33-AP.

The command creates a signed debug token binary based on the template. By default, the template is configured to be applicable for any die ID. See the [Read die id](#read-die-id) section to the find die ID of your device. See the [Get device info](#get-device-info) section to find the silicon ID, family ID, and revision ID needed to create a certificate.
### Command: `debug-token`
### Parameters
| Name              | Optional/Required | Description                                                                                                               |
|-------------------|:-----------------:|---------------------------------------------------------------------------------------------------------------------------|
| -T, --template    |     optional      | The path to the token template. The template can be found in the _packets_ directory of the project (_debug_token.json_). |
| --key, --key-path |     optional      | The path to the private key to sign the token. If the token to be signed by HSM, do not specify the option.               |
| -o, --output      |     required      | The file where to save the debug token.                                                                                   |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 debug-token --template packets/debug_token.json -o packets/debug_token.bin --key keys/oem_rot_priv_key_0.pem
```


## Read die ID
Reads the die ID from a device.
### Command: `read-die-id`
### Parameters
| Name           | Optional/Required | Description                                                                                                        |
|----------------|:-----------------:|--------------------------------------------------------------------------------------------------------------------|
| -o, --out-file |     optional      | The name of the file where to save the die ID. If not specified, the information will be displayed in the console. |
| --probe-id     |     optional      | Probe serial number.                                                                                               |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 read-die-id
```


## Get firmware version
Outputs version of ROM_BOOT, FLASH_BOOT
### Command: `version`
### Parameters
| Name       | Optional/Required | Description          |
|------------|:-----------------:|----------------------|
| --probe-id |     optional      | Probe serial number. |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 version
```


## Get device info
Gets device information - silicon ID, silicon revision, and family ID.
### Command: `device-info`
### Parameters
| Name       | Optional/Required | Description                                                                              |
|------------|:-----------------:|------------------------------------------------------------------------------------------|
| --probe-id |     optional      | Probe serial number.                                                                     |
| --ap       |     optional      | The access port used to read the data - "cm33" or "sysap". The default value is "sysap". |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 device-info
```

# Provisioning process
This section describes what happens when we run the `provision-device` command.
The provisioning process is done by the _prov_oem_ RAM application located in the _packets/apps_ directory of the project. However, before programming the RAM application into the device, we need to provide input parameters for the application. In the context of the RAM application, the input parameters are the data user provides in the policy file. Before starting the provisioning process, the tool generates input parameters binary based on the data in the policy file and optionally signs it with the key specified in the `--key` argument (signing applicable to reprovisioning only).
Then the RAM application and its input parameters are programmed into the device, and the provisioning process starts and configures the device according to the selected policy.

# Using package together with HSM
All the above examples describe the flow when the private keys are available locally on the computer. However, to protect your private keys, the cryptographic operations can be delegated to a Hardware Security Module (HSM). The flow of using the package with an HSM is different from the standard flow because the image must be signed using a different tool provided by the HSM vendor. Data are signed in a few steps: generate unsigned data, provide the data to HSM, grab the signature, and merge the unsigned data with the signature. However, the data has different formats and must be processed by different flows.

## Signing application with HSM
Refer to the [Signing application with HSM](https://github.com/Infineon/edgeprotecttools/blob/master/docs/README_GENERAL.md#signing-application-with-HSM) section.

## Signing reprovisioning packet with HSM
The provisioning packet does not require to be signed. However, the reprovisioning data must be signed with the OEM key.
The flow:
1. Generate a non-signed reprovisioning packet with data to be cryptographically protected.
2. Get the signature from HSM.
3. Generate a packet containing protected data and the signature.

### Step 1
The packet contains protected and non-protected data. Get the protected data only. Create a provisioning packet without using the`--key` option, which will create the packet containing only data to be signed.
```bash
$ edgeprotecttools -t psoc_c3 create-provisioning-packet -p policy/policy_oem_reprovisioning.json --key keys/oem_rot_priv_key_0.pem
```
### Step 2
Use the tools provided by your HSM provider to sign the data packet on the HSM machine. You can find the packet location in the previous step output. Save the signature returned by the HSM to a file.
### Step 3
Merge the file with the unsigned data with the signature file created by the HSM.
```bash
$ edgeprotecttools merge-bin --image packets/reprovisioning/in_params.bin --image hsm_signature.bin --output packets/reprovisioning/in_params.bin
```

## Reprovisioning with prebuilt data
When the keys are stored in HSM, the provisioning data is built and signed manually. Use the `provision-device` command with the `--existing-packet` option. The option indicates that the RAM application package will not be built and the tool will use the existing one.
```bash
$ edgeprotecttools -t psoc_c3 reprovision-device -p policy/policy_oem_reprovisioning.json --existing-packet
```


## Creation and signing a debug token with HSM
The flow:
1. Create a non-signed token.
2. Get the signature using HSM.
3. Add a signature returned by the HSM to the token.

### Step 1
Create a token but do not specify the `--key` option.
```bash
$ edgeprotecttools -t psoc_c3 debug-token --template packets/debug_token.json --output debug_token_unsigned.bin
```
### Step 2
Use the tools provided by your HSM provider to sign the extended image on the HSM machine. Save the signature returned by the HSM to a file.
### Step 3
Merge the unsigned token and the signature file created by the HSM.
```bash
$ edgeprotecttools merge-bin --image debug_token_unsigned.bin --image signature_hsm.bin --output debug_token_signed.bin
```


## Creation and signing an RMA token with HSM
The flow:
1. Create a non-signed token.
2. Get the signature using HSM.
3. Add a signature returned by the HSM to the token.

### Step 1
In the packets/debug_token.json change the "rma" property to `Enable`. Create a token but do not specify the `--key` option.
```bash
$ edgeprotecttools -t psoc_c3 debug-token --template packets/debug_token.json --output rma_token_unsigned.bin
```
### Step 2
Use the tools provided by your HSM provider to sign the extended image on the HSM machine. Save the signature returned by the HSM to a file.
### Step 3
Merge the unsigned token and the signature file created by the HSM.
```bash
$ edgeprotecttools merge-bin --image rma_token_unsigned.bin --image signature_hsm.bin --output rma_token_signed.bin
```


# Return Merchandise Authorization (RMA)
The flow for the transition device to the `RMA` lifecycle stage and open DAP.
## RMA token
For the transition of the device into the `RMA` lifecycle stage you need to create a token, which contains the device DIE_ID and is signed with the OEM RoT key.

There are two types of RMA tokens - "Transit to RMA" and "Open RMA". The tokens can be created with the `debug-token` command and the enabled `rma` property in the token template.

The token template is located in the _packets_ directory of the project. _debug_token.json_ defines the DIE_ID of the devices the token can be applied to. The default template min and max values are applicable for all devices. Modify it for specific devices only if needed. Set `rma` property to `Enable`.

"Transit to RMA" token is used to transit the device to the `RMA` LCS.
### Command: `debug-token`
### Parameters
| Name              | Optional/Required | Description                                                                                                               |
|-------------------|:-----------------:|---------------------------------------------------------------------------------------------------------------------------|
| -T, --template    |     required      | The path to the token template. The template can be found in the _packets_ directory of the project (_debug_token.json_). |
| --key, --key-path |     optional      | The path to the private key to sign the token. If the token to be signed by HSM, do not specify the option.               |
| -o, --output      |     required      | The file where to save the "Transit to RMA" token.                                                                        |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 debug-token --template packets/debug_token.json -o packets/rma_token.bin --key keys/oem_rot_priv_key_0.pem
```

## Transition to RMA
The command advances the device lifecycle stage to `RMA`. The token must be signed with the OEM key. 

For the device in `NORMAL_PROVISIONED` LCS, the DLM package does not need to be signed, and specifying the `--key` option is unnecessary. 

For the device in `SECURE` LCS, the DLM package must be signed with OEM RoT private key, and specifying the `--key` option is mandatory.

### Command: `transit-to-rma`
### Parameters
| Name              | Optional/Required | Description                                                  |
|-------------------|:-----------------:|--------------------------------------------------------------|
| --token           |     required      | Path to the "Transit to RMA" token.                          |
| --key, --key-path |     optional      | The path to the OEM RoT private key to sign the DLM package. |
| --probe-id        |     optional      | Probe serial number.                                         |

### Usage example
```bash
$ edgeprotecttools -t psoc_c3 transit-to-rma --token packets/rma_token.bin
$ edgeprotecttools -t psoc_c3 transit-to-rma --token packets/rma_token.bin --key keys/oem_rot_priv_key_0.pem
```

# Protected Firmware Update

## Protected FW Policy provisioning

This process is intended to provision Protected FW policy and assets to the device.
This process can be executed via SWD or DFU interface

1. Generate AES key `prot_fw_key.bin`
    ```bash
    $ edgeprotecttools create-key --key-type AES128 --output keys/prot_fw_key.bin
    ```
2. Generate Protected FW RoT 0 keypair
    ```bash
    $ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/prot_fw_rot_private_key_0.pem keys/prot_fw_rot_public_key_0.pem
    ```
3. Generate Protected FW RoT 1 keypair
    ```bash
    $ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/prot_fw_rot_private_key_1.pem keys/prot_fw_rot_public_key_1.pem
    ```
4. Update policy `policy_prot_fw.json`
5. From your project directory run the command
    ```bash
    $ edgeprotecttools -t psoc_c3 provision-device -p policy/policy_prot_fw.json
    ```

## Protected FW DFU

1. Make sure the Protected FW image is a binary (.bin, NOT .hex)
2. Sign and wrap the image into MCUBoot format:
    ```bash
    $ edgeprotecttools sign-image -i flash_app_simple.bin -o unencrypted.bin  --key keys/prot_fw_rot_private_key_0.pem --public-key-format full --pubkey-encoding raw --signature-encoding raw
    ```
3. Encrypt image 
    ```bash
    $ edgeprotecttools encrypt-aes -i unencrypted.bin -o encrypted.bin --iv 0xd3926e567875c434e9e05ae2d726104c --key keys/prot_fw_key.bin --cipher-mode CBC
    ```
4. Convert encrypted image into hex. Offset must correspond to field `prot_fw_addr` in `prot_fw_policy.json` that was previously programmed to the device
    ```bash
    $ edgeprotecttools bin2hex --image encrypted.bin -o encrypted.hex --offset 0x32000000 
    ```
5. Update policy `policy_prot_fw_dfu.json` with `interface` and `IV`
    ```json
    {
      "policy": {
        "platform": "psoc_c3",
        "version": 1.0,
        "type": "prot_fw_dfu"
      },
      "interface": {
        "description": "Indicates which interface to use: uart, i2c, or spi",
        "value": "uart"
      },
      "iv": {
       "description": "IV for encryption",
       "value": "d3926e567875c434e9e05ae2d726104c"
      }
    }
    ```
6. Select the tool used to communicate through the serial interface
    ```bash
    $ edgeprotecttools set-ocd -n serial -p dfuh-tool
    ```
7. Configure serial interface
    ```bash
    $ edgeprotecttools serial-config --protocol uart --hwid COM12
    ```
8. Run command
    ```bash
    $ edgeprotecttools -t psoc_c3 prot-fw-dfu -p policy/policy_prot_fw_dfu.json --image encrypted.hex
    ```

### Command `prot-fw-dfu`
### Parameters
| Name              | Optional/Required | Description                                                                                                                                                     |
|-------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the provisioning policy.                                                                                                                            |
| --image           |     required      | Protected firmware image.                                                                                                                                       |
| --key             |     optional      | OEM private key used to sign the DLM package.                                                                                                                   |
| --existing-packet |     optional      | Skip provisioning packet creation and use the existing packet. This may be useful when a packet already exists and the tool does not have to generate it again. |
### Usage example
```bash
$ edgeprotecttools -t psoc_c3 prot-fw-dfu -p policy/policy_prot_fw_dfu.json --image encrypted.hex
```
