#!/bin/bash
basepath=$(dirname $JLINK_SERVER)
$basepath/JLinkExe -device GD32F470VG -if swd -speed 4000 -commandfile ./download.jlink
