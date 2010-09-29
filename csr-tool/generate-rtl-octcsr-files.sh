#!/bin/bash

sim_base=~/work/simulator_source
export LANG=C # Needed os my sort order matches Rick's. Locales are evil
for model in n3_pass2 n3_pass3 o2p_pass1 o1p_pass1 o5020_pass1 o9n_pass1 o9n_pass2 o56_pass1 o56_pass2 o52_pass1 o52_pass2
do
    dir=${sim_base}/csrs/${model}/rtl
    files=`echo ${dir}/*/*.csr`
    ${dir}/utils/csr2spec_dir ${dir}/utils/ ${files} > ${model}-csr.txt
done

for model in o63_pass1 o63
do
    dir=${sim_base}/csrs/${model}
    pushd $dir
    python rtl/utils/csr.py --octane_spec
    popd
    mv $dir/rtl/octane_spec.txt ${model}-csr.txt
done

mv n3_pass2-csr.txt     octcsr_cn38xxp2.txt
mv n3_pass3-csr.txt     octcsr_cn38xxp3.txt
mv o2p_pass1-csr.txt    octcsr_cn31xxp1.txt
mv o1p_pass1-csr.txt    octcsr_cn30xxp1.txt
mv o5020_pass1-csr.txt  octcsr_cn50xxp1.txt
mv o9n_pass1-csr.txt    octcsr_cn58xxp1.txt
mv o9n_pass2-csr.txt    octcsr_cn58xxp2.txt
mv o56_pass1-csr.txt    octcsr_cn56xxp1.txt
mv o56_pass2-csr.txt    octcsr_cn56xxp2.txt
mv o52_pass1-csr.txt    octcsr_cn52xxp1.txt
mv o52_pass2-csr.txt    octcsr_cn52xxp2.txt
mv o63_pass1-csr.txt    octcsr_cn63xxp1.txt
mv o63-csr.txt          octcsr_cn63xxp2.txt

# For some reason Rick's version has CRLF in them for these
unix2dos octcsr_cn50xxp1.txt
unix2dos octcsr_cn63xxp1.txt
unix2dos octcsr_cn63xxp2.txt

