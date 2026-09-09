# Secure Request Framework Library

## Overview

With ARM TruseZone core, the Secure Request Framework (SRF) exists to provide a reusable infastructure for implementing multiple secure operations via a single non-secure-callable entry point.

Through the SRF, the secure world exposes one or more operations, which are roughly equivalent
to a function. These operations can be combined into a module - a unit of integration between
different entities which wish to expose their operations. For example, the Peripheral Driver
Library (PDL) would be one module.

For Dual-Core case, SRF integrate Infineon's interprocessor communication library (MTB-IPC).
Secure Request IPC integration provides an implementation of contexts and structures used to store states and signal information over MTB-IPC. And it excutes exposed operation defined in
the secure world.

This framework requires the user manage a mtb_srf_config.h file that contains macros for
the various modules that use the SRF.  The file comes with the default macros for user and
PDL module IDs. Should a library be added to the project that uses SRF, that library should
generate a relevant error message requesting that its module ID is added to the mtb_srf_config.h file.

These are fully documented in the [SRF API Reference Manual](https://infineon.github.io/mtb-srf/html/index.html).

## Features

* Provides registeration framework mtb_srf_module_register() for a module in the secure world
* Provides an implementation of secure request pool (e.g. `mtb_srf_pool_s`, `mtb_srf_ipc_pool_s`), which is composed of multiple secure request objects `mtb_srf_request_ns_t`, which is called SRF request.
* Provides SRF comminucation via non-secure-callable (NSC) within TrustZone core. Calling mtb_srf_request_submit() from the non-secure world, secure world provides memory access checking, permission validation, operation dispatch and execution of exposed operation.
* Provides SRF IPC communication between one core (sender) and one TrustZone core (receiver)
  - Sender: Transmit an SRF request over IPC mtb_srf_ipc_request_submit()
  - Receiver: Receives an SRF request over IPC mtb_srf_ipc_receive_request() and process the SRF request from IPC mtb_srf_ipc_process_request().

## More information

For more information, refer to the following documents:

* [ModusToolbox Middleware Template API Reference Guide](https://infineon.github.io/mtb-srf/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software)
* [Infineon Technologies AG](https://www.infineon.com)

© 2025, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.
