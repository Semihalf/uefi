#!/bin/bash

if [ "${OCTEON_REMOTE_PROTOCOL}" != "" ]
then
    echo "Booting bdk-minimal.bin"
    bdk-remote boot ${BDK_ROOT}/target-bin/bdk-minimal.bin || exit -1
    sleep 1
    echo "FIXME: Sending blank line to wake up nic10e"
    echo "" > ${OCTEON_REMOTE_CONSOLE}
fi
echo "Recording script $1"
bdk-record record $1 ${BDK_ROOT}/lua-modules/main.lua
echo "Done with script $1"

