# Pre-defined Syspm Callback Implementations

There are a number of peripherals which require special handling when the MCU enters or exits DeepSleep.
These actions can take place at one or more stages of the transition process:

* CHECK_READY: Some peripherals contain local state (e.g. FIFO contents) that is not retained in DeepSleep, so the peripheral status needs to be checked prior to the transition to determine whether the transition is safe to perform or if it should be blocked.
* BEFORE_TRANSITION: Once it has been determined that the system should enter Deepsleep, some peripherals require some action to be taken in order to be ready for the transition. In some cases, it may be necessary to save (in RAM) the state of registers that are not retained. In others, some configuration of the peripheral (or other related peripherals, e.g. pins) need to be changed in order to avoid unnecessary power consumption.
* AFTER_TRANSITION: After the device has woken from DeepSleep, some peripherals require additional steps to be performed before they return to active operating mode. This generally involves restoration of registers that were saved in BEFORE_TRANSITION, or reversal of configuration changes that were performed in that step.
Some low-level SysPm related callbacks are provided in the PDL, but much of the high level functionality related to safely entering and exiting DeepSleep needs to be implemented at a higher level and this is wehre this library comes into play.

For drivers that already have deep sleep callbacks available in PDL and contain all logic needed to safely handle deepsleep entry this library only provides aliases in order to maintain uniformity on the naming level.
For drivers for which instead more steps or checks are needed, the implementaiton is handled in this asset.
Each callback is only available for devices that include the needed IP and the packaging system makes sure to include only relevant files for each family of devices.

## Overview
All prebuilt callback implementations will provide a function signature which conforms to the Cy_SysPmCallback function pointer signature. This enables them to be directly registered without the application needing to write a wrapper function to adapt the signature.

This means that any information which a prebuilt callback needs in order to operation must be consolidated in a single high-level struct that can be passed via the "context" argument of cy_stc_syspm_callback_params_t  (a generic void pointer whose interpretation is defined by each callback). The one exception is the base pointer, which is already passed via a separate member on cy_stc_syspm_callback_params_t . If a callback does not require any information beyond the base pointer, the context member can be left unused.