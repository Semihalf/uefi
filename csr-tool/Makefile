SVNROOT=svn+ssh://kreesema@masvn/svn

.PHONY: all
all: fetch generate copy-headers

.PHONY: fetch
fetch: clean
	svn export -q ${SVNROOT}/t88/trunk/hwcode/regs/gen cn88xx

.PHONY: generate
generate:
	rm -rf html output
	mkdir html output
	./csr-tool.py --html \
	    --csr cn88xxp1,cn88xx,t88=1.0 \
	    --csr cn88xx,cn88xx,t88=1.1

.PHONY: copy-headers
copy-headers:
	mv output/bdk-csrs*.h ../libbdk-arch/
	mv output/bdk-csrs.c ../libbdk-arch/
	mv output/bdk-csrs.lua ../lua-modules/csr_db.lua
	mv output/tns-map-cn88xx.lua ../lua-modules/tns.lua
	svn export --force -q ${SVNROOT}/asim/branches/development/processor/sysreg/system_registers.h ../libbdk-arch/bdk-sysreg.h

.PHONY: copy-html
copy-html:
	rm -rf /var/www/thunder/csr-html
	mv html /var/www/thunder/csr-html

.PHONY: copy
copy: copy-headers copy-html

.PHONY: clean
clean:
	rm -rf output html cn8??? *.pickle *.pyc

