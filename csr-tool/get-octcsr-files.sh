#!/bin/bash

if [ "$1" != "skip" ]
then
wget -O octcsr_cn61xxp1.txt http://iceman.caveonetworks.com/trac/browser/o61/trunk/packet/o61csr.txt?format=raw

echo "Getting octcsr_cn78xxp1"
rm -rf octcsr_cn78xxp1
svn co -q svn+ssh://kreese@masvn/svn/o78/trunk/hwcode/regs/gen octcsr_cn78xxp1

echo "Getting octcsr_cn70xxp1"
rm -rf octcsr_cn70xxp1
svn co -q svn+ssh://kreese@masvn/svn/o70/trunk/hwcode/regs/gen octcsr_cn70xxp1

echo "All chips retrieved, doing fixups"
fi

dos2unix -q octcsr_*.txt
sed -i "s/[ \\t][ \\t]*$//g" octcsr_*.txt

# Fixups for CN61XX
for f in octcsr_cn61xxp1.txt
do
    sed -i "s/POW_/SSO_/g" $f # Rename POW to SSO
    sed -i "s/PCIEEP#_/PCIEEP(0..1)_/g" $f
    sed -i "s/PCIERC#_/PCIERC(0..1)_/g" $f
    sed -i "s/GMX#_/GMX(0..1)_/g" $f
    sed -i "s/LMC#_/LMC(0)_/g" $f
    sed -i "s/PCSX#_/PCSX(0..1)_/g" $f
    sed -i "s/PEM#_/PEM(0..1)_/g" $f
    sed -i "s/UAHC#_/UAHC(0)_/g" $f
    sed -i "s/UCTL#_/UCTL(0)_/g" $f
    sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" $f
    sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" $f
done

# Fixups for CN78XX
sed -i "s/SMI_\\([0-9(]\\)/SMI\\1/g" octcsr_cn78xxp1/smi.csr
sed -i "s/CIU3_/CIU_/g" octcsr_cn78xxp1/ciu3.csr

