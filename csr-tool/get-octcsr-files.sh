#!/bin/bash

if [ "$1" != "skip" ]
then

echo "Getting octcsr_cn78xxp1"
rm -rf octcsr_cn78xxp1
svn co -q svn+ssh://kreese@masvn/svn/o78/trunk/hwcode/regs/gen octcsr_cn78xxp1

echo "Getting octcsr_cn70xxp1"
rm -rf octcsr_cn70xxp1
svn co -q svn+ssh://kreese@masvn/svn/o70/trunk/hwcode/regs/gen octcsr_cn70xxp1

echo "All chips retrieved, doing fixups"
fi

# Fixups for CN78XX
sed -i "s/SMI_\\([0-9(]\\)/SMI\\1/g" octcsr_cn78xxp1/smi.csr
sed -i "s/CIU3_/CIU_/g" octcsr_cn78xxp1/ciu3.csr

