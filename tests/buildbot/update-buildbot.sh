#!/bin/bash

scp master.cfg buildbot@chad-pci:master/master.cfg
ssh buildbot@chad-pci buildbot reconfig master
