#!/bin/bash

host=mrdata
#host=cadata

if [ "$1" != "skip" ]
then
wget -O octcsr_cn56xxp1.txt http://${host}/Docs/O56/Specs/o56csr_pass1.txt
wget -O octcsr_cn56xxp2.txt http://${host}/Docs/O56/Specs/o56csr.txt
wget -O octcsr_cn52xxp1.txt http://${host}/Docs/O52/Specs/o52csr_pass1.txt
wget -O octcsr_cn52xxp2.txt http://${host}/Docs/O52/Specs/o52csr.txt
wget -O octcsr_cn63xxp1.txt http://${host}/Docs/O63/Specs/o63csr_pass1.txt
wget -O octcsr_cn63xxp2.txt http://${host}/Docs/O63/Specs/o63csr.txt
wget -O octcsr_cn68xxp1.txt http://${host}/Docs/O68/Specs/o68csr.txt
fi

sed -i "s/MIO_BOOT_REG_CFG(1..7)/MIO_BOOT_REG_CFG(0..7)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/MIO_BOOT_REG_TIM(1..7)/MIO_BOOT_REG_TIM(0..7)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt

sed -i "s/GMX#_/GMX(0..1)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt

sed -i "s/USBC#_/USBC(0)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/USBN#_/USBN(0)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt

sed -i "s/PESC#_/PESC(0..1)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/PCIERC#_/PCIERC(0..1)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/PCIEEP#_/PCIEEP(0)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/LMC#_/LMC(0..1)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/PCSX#_/PCSX(0..1)_/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt

sed -i "s/USBC#_/USBC(0..1)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/USBN#_/USBN(0..1)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/LMC#_/LMC(0)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/PESC#_/PESC(0..1)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/PCIERC#_/PCIERC(0..1)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/PCIEEP#_/PCIEEP(0)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/PCSX#_/PCSX(0)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/GMX#_/GMX(0)_/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt

# Convert the USB device registers to range of 0..4 instead of having 0 different
sed -i "s/USBC(0)_DIEPCTL(1..4)/USBC(0)_DIEPCTL(0..4)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/USBC(0)_DIEPTSIZ(1..4)/USBC(0)_DIEPTSIZ(0..4)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/USBC(0)_DOEPCTL(1..4)/USBC(0)_DOEPCTL(0..4)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt
sed -i "s/USBC(0)_DOEPTSIZ(1..4)/USBC(0)_DOEPTSIZ(0..4)/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt

# Convert the USB device registers to range of 0..4 instead of having 0 different
sed -i "s/USBC(0..1)_DIEPCTL(1..4)/USBC(0..1)_DIEPCTL(0..4)/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/USBC(0..1)_DIEPTSIZ(1..4)/USBC(0..1)_DIEPTSIZ(0..4)/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/USBC(0..1)_DOEPCTL(1..4)/USBC(0..1)_DOEPCTL(0..4)/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/USBC(0..1)_DOEPTSIZ(1..4)/USBC(0..1)_DOEPTSIZ(0..4)/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt

# Fix the format of 0's address
sed -i "s/^USBC0_DIEPCTL0  /USBC0_DIEPCTL000/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC0_DIEPTSIZ0  /USBC0_DIEPTSIZ000/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC0_DOEPCTL0  /USBC0_DOEPCTL000/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC0_DOEPTSIZ0  /USBC0_DOEPTSIZ000/g" octcsr_cn56xxp1.txt octcsr_cn56xxp2.txt octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt

# Fix the format of 0's address
sed -i "s/^USBC1_DIEPCTL0  /USBC1_DIEPCTL000/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC1_DIEPTSIZ0  /USBC1_DIEPTSIZ000/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC1_DOEPCTL0  /USBC1_DOEPCTL000/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt
sed -i "s/^USBC1_DOEPTSIZ0  /USBC1_DOEPTSIZ000/g" octcsr_cn52xxp1.txt octcsr_cn52xxp2.txt

# Change TRA_ to TRA(0)_ for all the older chips
sed -i "s/^TRA_/TRA0_/g" octcsr_cn5*.txt
sed -i "s/TRA_/TRA(0)_/g" octcsr_cn5*.txt

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
