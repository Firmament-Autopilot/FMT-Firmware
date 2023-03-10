#!/bin/bash
$JLINK_SERVER/../JLinkExe -device GD32F470VG -if swd -speed 4000 -commandfile ./download.jlink
