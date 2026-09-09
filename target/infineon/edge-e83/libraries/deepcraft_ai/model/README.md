# DeepCraft AI model

This directory contains the DEEPCRAFT Studio generated `model.c` and `model.h`
migrated from `PSOC_Edge_Machine_Learning_DEEPCRAFT_Deploy_Motion_1/proj_cm55`.

`model.c` is built by the parent `deepcraft_ai/SConscript` so the same TFLM,
U55, and SoCMEM placement options are applied to the generated model code.

The original BMI270 FIFO business logic is intentionally not migrated. The FMT
adapter feeds `IMAI_enqueue()` from FMT raw IMU data published on
`sensor_imu0_0`.

The model input order follows the original DEEPCRAFT example:

1. accelerometer X/Y/Z, converted from `m/s^2` to `g`
2. gyroscope X/Y/Z, converted from `rad/s` to `deg/s`

The adapter keeps the original example's input cadence and orientation:
`IMAI_enqueue()` is called at 50 Hz, and the X/Y axes are negated to match the
`USE_SENSOR_REMAPPING` path in the source project.
