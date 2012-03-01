#!/bin/bash

if [ "${OCTEON_REMOTE_PROTOCOL}" != "" ]
then
    echo "Booting bdk-full.bin"
    bdk-remote boot ${BDK_ROOT}/target-bin/bdk-full.bin || exit -1
    sleep 1
fi
echo "Recording script $1"
bdk-record record $1 ${BDK_ROOT}/lua-modules/main.lua
echo "Done with script $1"

