# Changelog
All notable changes to this project will be documented in this file.

## 1.6.1
### Changed
- Optimized encryption algorithm for faster processing of large images using ECB cipher mode

## 1.6.0
### Added
- Support for PSOC™ Edge E81, E82, E83, E84 series
- Support for AIROC™ CYW89829 B1 MCU
- Signer/Combiner symbol file feature for variable interpolation
- Intel HEX regions relocation feature

### Changed
- PSOC™ Control C3: "listen_window" value from "1 ms" to "2 ms" in "policy_oem_provisioning.json"
- CYW559xx: Align the certificate chain address in the OTA image to a 256-byte boundary

## 1.5.0
### Added
- CYW559xx device erase command
- CYW559xx custom encryption IV
- CYW20829 encryption in NORMAL_NO_SECURE LCS

### Changed
- Dropped support for Python 3.8

## 1.4.0
### Added
- Support for AIROC™ CYW20829 revision B1
- Application encryption for AIROC™ CYW559xx
- OTA image generation for AIROC™ CYW559xx

### Changed
- PSOC™ Control C3 integrity exam certificate
- Replaced lief package with pyelftools

## 1.3.0
### Added
- X.509 certificates generation and verification
- Device certificate generation for CYW559xx

## 1.2.0
### Added
- Support for PSOC C3 device
- Reading device CSR from CYW559xx

## 1.1.0
### Added
- Support for CYW559xx device

## 1.0.0
### Added
- Backward compatibility with the [CySecureTools 6.1.0](https://github.com/Infineon/cysecuretools) package
- Combiner/Signer tool
