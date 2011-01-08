#!/bin/bash

host=mrdata
#host=cadata

if [ "$1" != "skip" ]
then
#wget -O octcsr_cn63xxp1.txt http://${host}/Docs/O63/Specs/o63csr_pass1.txt
#wget -O octcsr_cn63xxp2.txt http://${host}/Docs/O63/Specs/o63csr.txt
#wget -O octcsr_cn68xxp1.txt http://${host}/Docs/O68/Specs/o68csr.txt
wget -O octcsr_cn63xxp1.txt http://iceman/trac/browser/o63/trunk/packet/o63csr_pass1.txt?format=raw
wget -O octcsr_cn63xxp2.txt http://iceman/trac/browser/o63/trunk/packet/o63csr.txt?format=raw
wget -O octcsr_cn68xxp1.txt http://iceman/trac/browser/o68/trunk/packet/o68csr.txt?format=raw

fi

dos2unix -q octcsr_*.txt
sed -i "s/[ \\t][ \\t]*$//g" octcsr_*.txt

# Rename POW to SSO
sed -i "s/POW_/SSO_/g" octcsr_cn63*.txt

# Fixups for CN63XX
sed -i "s/PCIEEP#_/PCIEEP(0..1)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/PCIERC#_/PCIERC(0..1)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/GMX#_/GMX(0)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/LMC#_/LMC(0)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/PCSX#_/PCSX(0)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/PEM#_/PEM(0..1)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/SRIO#_/SRIO(0..1)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/SRIOMAINT#_/SRIOMAINT(0..1)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/UAHC#_/UAHC(0)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/UCTL#_/UCTL(0)_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/IOB_/IOB0_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/PIP_STAT\\([0-9]*\\)_PRT/PIP_STAT\\1_/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt
sed -i "s/PIP_STAT_INB_\\([A-Z]*\\)/PIP_STAT_INB_\1_PKND/g" octcsr_cn63xxp1.txt octcsr_cn63xxp2.txt

# Fixups for CN68XX
sed -i "s/PCIEEP#_/PCIEEP(0..1)_/g" octcsr_cn68xxp1.txt
sed -i "s/PCIERC#_/PCIERC(0..1)_/g" octcsr_cn68xxp1.txt
sed -i "s/GMX#_/GMX(0..4)_/g" octcsr_cn68xxp1.txt
sed -i "s/LMC#_/LMC(0..3)_/g" octcsr_cn68xxp1.txt
sed -i "s/PCSX#_/PCSX(0..4)_/g" octcsr_cn68xxp1.txt
sed -i "s/PEM#_/PEM(0..1)_/g" octcsr_cn68xxp1.txt
sed -i "s/UAHC#_/UAHC(0)_/g" octcsr_cn68xxp1.txt
sed -i "s/UCTL#_/UCTL(0)_/g" octcsr_cn68xxp1.txt
sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" octcsr_cn68xxp1.txt
sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" octcsr_cn68xxp1.txt
sed -i "s/SMI_\\([0-9(]\\)/SMI\\1/g" octcsr_cn68xxp1.txt

