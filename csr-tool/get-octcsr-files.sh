#!/bin/bash

if [ "$1" != "skip" ]
then
wget -O octcsr_cn63xxp1.txt http://iceman.caveonetworks.com/trac/browser/o63/trunk/packet/o63csr_pass1.txt?format=raw
wget -O octcsr_cn63xxp2.txt http://iceman.caveonetworks.com/trac/browser/o63/trunk/packet/o63csr.txt?format=raw
wget -O octcsr_cn68xxp1.txt http://iceman.caveonetworks.com/trac/browser/o68/trunk/packet/o68csr_pass1.txt?format=raw
wget -O octcsr_cn68xxp2.txt http://iceman.caveonetworks.com/trac/browser/o68/trunk/packet/o68csr.txt?format=raw
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

# Rename POW to SSO
sed -i "s/POW_/SSO_/g" octcsr_cn63*.txt octcsr_cn61*.txt

# Fixups for CN63XX
for f in octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
do
    sed -i "s/PCIEEP#_/PCIEEP(0..1)_/g" $f
    sed -i "s/PCIERC#_/PCIERC(0..1)_/g" $f
    sed -i "s/GMX#_/GMX(0)_/g" $f
    sed -i "s/LMC#_/LMC(0)_/g" $f
    sed -i "s/PCSX#_/PCSX(0)_/g" $f
    sed -i "s/PEM#_/PEM(0..1)_/g" $f
    sed -i "s/SRIO#_/SRIO(0..1)_/g" $f
    sed -i "s/SRIOMAINT#_/SRIOMAINT(0..1)_/g" $f
    sed -i "s/UAHC#_/UAHC(0)_/g" $f
    sed -i "s/UCTL#_/UCTL(0)_/g" $f
    sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" $f
    sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" $f
    sed -i "s/IOB_/IOB0_/g" $f
    sed -i "s/PIP_STAT\\([0-9]*\\)_PRT/PIP_STAT\\1_/g" $f
    sed -i "s/PIP_STAT_INB_\\([A-Z]*\\)\\([*@0-9(]\\)/PIP_STAT_INB_\1_PKND\2/g" $f
done

# Fixups for CN68XX
for f in octcsr_cn68xxp1.txt octcsr_cn68xxp2.txt
do
    sed -i "s/PCIEEP#_/PCIEEP(0..1)_/g" $f
    sed -i "s/PCIERC#_/PCIERC(0..1)_/g" $f
    sed -i "s/GMX#_/GMX(0..4)_/g" $f
    sed -i "s/LMC#_/LMC(0..3)_/g" $f
    sed -i "s/PCSX#_/PCSX(0..4)_/g" $f
    sed -i "s/PEM#_/PEM(0..1)_/g" $f
    sed -i "s/UAHC#_/UAHC(0)_/g" $f
    sed -i "s/UCTL#_/UCTL(0)_/g" $f
    sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" $f
    sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" $f
    sed -i "s/SMI_\\([0-9(]\\)/SMI\\1/g" $f
done

# Fixups for CN61XX
for f in octcsr_cn61xxp1.txt
do
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
    sed -i "s/IOB_/IOB0_/g" $f
    sed -i "s/PIP_STAT\\([0-9]*\\)_PRT/PIP_STAT\\1_/g" $f
    sed -i "s/PIP_STAT_INB_\\([A-Z]*\\)\\([*@0-9(]\\)/PIP_STAT_INB_\1_PKND\2/g" $f
done

#(DPI-15413) DPI_SLI_PRT*_ERR are at the wrong address
#
# The DPI_SLI_PRT*_ERR CSRs are implemented at the wrong
# address in the hardware.
#
# Here is the intended hardware addresses:
#
# DPI_SLI_PRT0_ERR               0x0001DF0000000920  NCB
# DPI_SLI_PRT1_ERR               0x0001DF0000000928  NCB
#
# Here are the actual hardware addresses:
#
# DPI_SLI_PRT0_ERR               0x0001DF0000000928  NCB
# DPI_SLI_PRT1_ERR               0x0001DF0000000930  NCB
#
# Applies to CN63XXp1, CN63XXp2, CN68XXp1
for f in octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt octcsr_cn68xxp1.txt
do
    sed -i "s/DPI_SLI_PRT0_ERR               0x0001DF0000000920  NCB/DPI_SLI_PRT0_ERR               0x0001DF0000000928  NCB/g" $f
    sed -i "s/DPI_SLI_PRT1_ERR               0x0001DF0000000928  NCB/DPI_SLI_PRT1_ERR               0x0001DF0000000930  NCB/g" $f
done

