#!/bin/bash

for s in "$*"
do
    echo "OCTEON_REMOTE_PROTOCOL=${OCTEON_REMOTE_PROTOCOL}"
    echo "OCTEON_REMOTE_CONSOLE=${OCTEON_REMOTE_CONSOLE}"
    if [ "${OCTEON_REMOTE_PROTOCOL}" != "" ]
    then
        echo "Booting bdk-minimal.bin"
        bdk-remote boot ${BDK_ROOT}/target-bin/bdk-minimal.bin || exit -1
        sleep 1
        echo "FIXME: Sending blank line to wake up nic10e"
        echo "" > ${OCTEON_REMOTE_CONSOLE}
    fi
    echo "Playing script $s"
    bdk-record play $1 ${BDK_ROOT}/lua-modules/main.lua || exit -1
    echo "Done with script $s"
done
