# stdlib Stubs

## Overview

The stdlib stubs asset provides necessary WEAK stub implementations of all of the functions that nosys provides implementations for, but without the attached warnings that the GCC_ARM toolchain will throw when compiling the nosys versions of the stubs.

A user can opt to utilize their own implementations of any of the WEAK functions by redefining them in their application without the WEAK attribute.

If these stubs are not desired, they can be disabled by adding `MTB_STDLIB_STUBS_DISABLE` to DEFINES in the application makefile
