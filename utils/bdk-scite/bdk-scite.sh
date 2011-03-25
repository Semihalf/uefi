#!/bin/bash

export SciTE_HOME=${BDK_ROOT}/utils/bdk-scite/gscite
LOGFILE=${BDK_ROOT}/utils/bdk-scite/scite.log
${SciTE_HOME}/SciTE -sidebar.show=1 "$*" &> ${LOGFILE} &

