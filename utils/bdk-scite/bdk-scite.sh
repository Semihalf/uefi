#!/bin/bash

export SciTE_HOME=${BDK_ROOT}/utils/bdk-scite/gscite
LOGFILE=${BDK_ROOT}/utils/bdk-scite/scite.log
nohup ${SciTE_HOME}/SciTE "$*" &> ${LOGFILE} &

